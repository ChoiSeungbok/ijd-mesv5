/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_input_lot_data.c
Description : lot data(edc) 데이터를 등록한다.

MES Version : 5.0

Function List
- step 1 : 공정 lot data 입력

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/08  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Input_Lot_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_INPUT_LOT_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Input_Lot_Data()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Input_Lot_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_INPUT_LOT_DATA(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Input_Lot_Data", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    if (i_ret == MP_TRUE)
    {
        if (gb_multi_transaction == MP_FALSE)
        {
            DB_commit();
        }
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_INPUT_LOT_DATA()
- Main sub function of "CUS_WIP_Input_Lot_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_INPUT_LOT_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MEDCLOTDAT_TAG MEDCLOTDAT;
    struct MEDCCOLVER_TAG MEDCCOLVER;
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX_DEL;
    //struct MWIPLOTHIS_TAG  MWIPLOTHIS;

    TRSNode  *tran_in_node;    
    TRSNode  **data_list;
    TRSNode  **data_list1;
    TRSNode  **data_list2;
    TRSNode  *char_list;
    TRSNode  *unit_list;
    TRSNode  *value_seq_list;
    TRSNode  *value_list;

    int iCnt = 0;
	int iCnt2 = 0;
    int i_list_count;
    int i_list_count1;
    int i_list_count2;

    // LOG
    LOG_head("CUS_WIP_Input_Lot_Data");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    // VALIDATION CHECK
    if (CUS_WIP_Input_Lot_Data_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }


	//1 일반착완공시 등록, 2 이후 완료된이후 등록(20220415 추가)
	if (TRS.get_procstep(in_node) == '1') 
	{

		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBC_init_medccolver(&MEDCCOLVER);
		TRS.copy(MEDCCOLVER.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID), in_node, "COL_SET_ID");
		DBC_select_medccolver(2, &MEDCCOLVER);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				// EDC-0038 : 이 COLLECTION SET VERSION은 존재하지 않습니다.
				strcpy(s_msg_code, "EDC-0038");
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "EDC-00004");
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MEDCCOLVER Select 2", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
			TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			return MP_FALSE;
		}

		DBU_init_medclotdat(&MEDCLOTDAT);
		TRS.copy(MEDCLOTDAT.LOT_ID, sizeof(MEDCLOTDAT.LOT_ID), in_node, "LOT_ID");
		MEDCLOTDAT.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		TRS.copy(MEDCLOTDAT.OPER, sizeof(MEDCLOTDAT.OPER), in_node, "OPER");
		TRS.copy(MEDCLOTDAT.COL_SET_ID, sizeof(MEDCLOTDAT.OPER), in_node, "COL_SET_ID");
		MEDCLOTDAT.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;




		iCnt2 = (int)DBU_select_medclotdat_scalar(4, &MEDCLOTDAT);

		if (iCnt2 > 0)
		{

			//기존 입력되어있는 이전버전의 데이터들은 삭제_PDC 베트남 PRESS만 삭제(검사 COUNT가 계속달라질것이어서 업데이트안됨.(2022 /01 /20 Syw)
			DBU_delete_medclotdat(1, &MEDCLOTDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "EDC-0004");
				TRS.add_fieldmsg(out_node, "MEDCLOTDAT DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MEDCLOTDAT.LOT_ID), MEDCLOTDAT.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}






		iCnt = (int)DBU_select_medclotdat_scalar(2, &MEDCLOTDAT);






		if (iCnt == 0)
		{
			tran_in_node = TRS.add_node(in_node, "Collect_Lot_Data");
			TRS.add_char(tran_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));
			CopyDefaultMembers(tran_in_node, in_node);
			TRS.add_string(tran_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(tran_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_int(tran_in_node, "MAT_VER", MWIPLOTSTSX.MAT_VER);
			TRS.add_string(tran_in_node, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_int(tran_in_node, "FLOW_SEQ_NUM", MWIPLOTSTSX.FLOW_SEQ_NUM);
			TRS.add_nstring(tran_in_node, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_nstring(tran_in_node, "COL_SET_ID", TRS.get_string(in_node, "COL_SET_ID"));
			TRS.add_int(tran_in_node, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
			TRS.add_nstring(tran_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_char(tran_in_node, "SELECT_MFO_FLAG", 'Y');

			i_list_count = TRS.get_item_count(in_node, "CHAR_LIST");
			data_list = TRS.get_list(in_node, "CHAR_LIST");
			for (int i = 0; i < i_list_count; i++)
			{
				char_list = TRS.add_node(tran_in_node, "CHAR_LIST");
				TRS.add_nstring(char_list, "CHAR_ID", TRS.get_string(data_list[i], "CHAR_ID"));

				i_list_count1 = TRS.get_item_count(data_list[i], "UNIT_LIST");
				data_list1 = TRS.get_list(data_list[i], "UNIT_LIST");
				for (int j = 0; j < i_list_count1; j++)
				{
					unit_list = TRS.add_node(char_list, "UNIT_LIST");
					TRS.add_nstring(unit_list, "UNIT_ID", TRS.get_string(data_list1[j], "UNIT_ID"));
					TRS.add_char(unit_list, "VALUE_TYPE", TRS.get_char(data_list1[j], "VALUE_TYPE"));
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", TRS.get_int(data_list1[j], "UNIT_SEQ_NUM"));

					i_list_count2 = TRS.get_item_count(data_list1[j], "VALUE_LIST");
					data_list2 = TRS.get_list(data_list1[j], "VALUE_LIST");
					for (int k = 0; k < i_list_count2; k++)
					{
						value_list = TRS.add_node(unit_list, "VALUE_LIST");
						TRS.add_nstring(value_list, "VALUE", TRS.get_string(data_list2[k], "VALUE"));
					}
				}
			}

			if (EDC_COLLECT_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE)
				return MP_FALSE;
		}
		else
		{



			tran_in_node = TRS.add_node(in_node, "Collect_Lot_Data");
			CopyDefaultMembers(tran_in_node, in_node);
			TRS.add_char(tran_in_node, IN_PROCSTEP, '1');
			TRS.add_string(tran_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_int(tran_in_node, "HIST_SEQ", TRS.get_int(in_node, "HIST_SEQ"));
			TRS.add_string(tran_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_int(tran_in_node, "MAT_VER", MWIPLOTSTSX.MAT_VER);
			TRS.add_string(tran_in_node, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_int(tran_in_node, "FLOW_SEQ_NUM", MWIPLOTSTSX.FLOW_SEQ_NUM);
			TRS.add_nstring(tran_in_node, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(tran_in_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
			TRS.add_char(tran_in_node, "LOT_EDC_TRAN_FLAG", 'Y');
			TRS.add_char(tran_in_node, "SELECT_MFO_FLAG", ' ');
			TRS.add_char(tran_in_node, "COL_SET_OVR_FLAG", 'Y');
			TRS.add_string(tran_in_node, "PROC_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_nstring(tran_in_node, "PROC_OPER", TRS.get_string(in_node, "OPER"));

			i_list_count = TRS.get_item_count(in_node, "CHAR_LIST");
			data_list = TRS.get_list(in_node, "CHAR_LIST");

			for (int i = 0; i < i_list_count; i++)
			{
				char_list = TRS.add_node(tran_in_node, "CHAR_LIST");
				TRS.add_nstring(char_list, "COL_SET_ID", TRS.get_string(data_list[i], "COL_SET_ID"));
				TRS.add_int(char_list, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
				TRS.add_int(char_list, "COL_SEQ", TRS.get_int(data_list[i], "COL_SEQ"));
				TRS.add_nstring(char_list, "CHAR_ID", TRS.get_string(data_list[i], "CHAR_ID"));
				TRS.add_int(char_list, "CHAR_SEQ_NUM", TRS.get_int(data_list[i], "CHAR_SEQ_NUM"));

				i_list_count1 = TRS.get_item_count(data_list[i], "UNIT_LIST");
				data_list1 = TRS.get_list(data_list[i], "UNIT_LIST");
				for (int j = 0; j < i_list_count1; j++)
				{
					unit_list = TRS.add_node(char_list, "UNIT_LIST");
					TRS.add_nstring(unit_list, "UNIT_ID", TRS.get_string(data_list1[j], "UNIT_ID"));
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", TRS.get_int(data_list1[j], "UNIT_SEQ_NUM"));

					value_seq_list = TRS.add_node(unit_list, "VALUE_SEQ_LIST");
					TRS.add_int(value_seq_list, "VALUE_SEQ_NUM", 1);

					i_list_count2 = TRS.get_item_count(data_list1[j], "VALUE_LIST");
					data_list2 = TRS.get_list(data_list1[j], "VALUE_LIST");
					for (int k = 0; k < i_list_count2; k++)
					{
						value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
						TRS.add_nstring(value_list, "VALUE", TRS.get_string(data_list2[k], "VALUE"));
					}
				}
			}

			if (EDC_CHANGE_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE)  //QA 데이터 입력 화면 지연 발생
				return MP_FALSE;
		}

   }
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		DBU_init_mwiplotstsx(&MWIPLOTSTSX_DEL);
		TRS.copy(MWIPLOTSTSX_DEL.LOT_ID, sizeof(MWIPLOTSTSX_DEL.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_DEL);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_DEL SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_DEL.FACTORY), MWIPLOTSTSX_DEL.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_ID), MWIPLOTSTSX_DEL.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		DBC_init_medccolver(&MEDCCOLVER);
		TRS.copy(MEDCCOLVER.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID), in_node, "COL_SET_ID");
		DBC_select_medccolver(2, &MEDCCOLVER);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				// EDC-0038 : 이 COLLECTION SET VERSION은 존재하지 않습니다.
				strcpy(s_msg_code, "EDC-0038");
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "EDC-00004");
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MEDCCOLVER Select 2", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
			TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			return MP_FALSE;
		}

		DBU_init_medclotdat(&MEDCLOTDAT);
		TRS.copy(MEDCLOTDAT.LOT_ID, sizeof(MEDCLOTDAT.LOT_ID), in_node, "LOT_ID");
		MEDCLOTDAT.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		TRS.copy(MEDCLOTDAT.OPER, sizeof(MEDCLOTDAT.OPER), in_node, "OPER");
		TRS.copy(MEDCLOTDAT.COL_SET_ID, sizeof(MEDCLOTDAT.OPER), in_node, "COL_SET_ID");
		MEDCLOTDAT.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;




		iCnt2 = (int)DBU_select_medclotdat_scalar(4, &MEDCLOTDAT);

		if (iCnt2 > 0)
		{

			//기존 입력되어있는 이전버전의 데이터들은 삭제_PDC 베트남 PRESS만 삭제(검사 COUNT가 계속달라질것이어서 업데이트안됨.(2022 /01 /20 Syw)
			DBU_delete_medclotdat(1, &MEDCLOTDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "EDC-0004");
				TRS.add_fieldmsg(out_node, "MEDCLOTDAT DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MEDCLOTDAT.LOT_ID), MEDCLOTDAT.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}






		iCnt = (int)DBU_select_medclotdat_scalar(2, &MEDCLOTDAT);






		if (iCnt == 0)
		{
			tran_in_node = TRS.add_node(in_node, "Collect_Lot_Data");



			CopyDefaultMembers(tran_in_node, in_node);
			TRS.add_char(tran_in_node, IN_PROCSTEP, '4');
			TRS.add_nstring(tran_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
			TRS.add_nstring(tran_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
			TRS.add_int(tran_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
			TRS.add_nstring(tran_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
			TRS.add_int(tran_in_node, "FLOW_SEQ_NUM", TRS.get_int(in_node, "FLOW_SEQ_NUM"));
			TRS.add_nstring(tran_in_node, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_nstring(tran_in_node, "COL_SET_ID", TRS.get_string(in_node, "COL_SET_ID"));
			TRS.add_int(tran_in_node, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
			TRS.add_nstring(tran_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_char(tran_in_node, "SELECT_MFO_FLAG", 'Y');

			i_list_count = TRS.get_item_count(in_node, "CHAR_LIST");
			data_list = TRS.get_list(in_node, "CHAR_LIST");
			for (int i = 0; i < i_list_count; i++)
			{
				char_list = TRS.add_node(tran_in_node, "CHAR_LIST");
				TRS.add_nstring(char_list, "CHAR_ID", TRS.get_string(data_list[i], "CHAR_ID"));

				i_list_count1 = TRS.get_item_count(data_list[i], "UNIT_LIST");
				data_list1 = TRS.get_list(data_list[i], "UNIT_LIST");
				for (int j = 0; j < i_list_count1; j++)
				{
					unit_list = TRS.add_node(char_list, "UNIT_LIST");
					TRS.add_nstring(unit_list, "UNIT_ID", TRS.get_string(data_list1[j], "UNIT_ID"));
					TRS.add_char(unit_list, "VALUE_TYPE", TRS.get_char(data_list1[j], "VALUE_TYPE"));
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", TRS.get_int(data_list1[j], "UNIT_SEQ_NUM"));

					i_list_count2 = TRS.get_item_count(data_list1[j], "VALUE_LIST");
					data_list2 = TRS.get_list(data_list1[j], "VALUE_LIST");
					for (int k = 0; k < i_list_count2; k++)
					{
						value_list = TRS.add_node(unit_list, "VALUE_LIST");
						TRS.add_nstring(value_list, "VALUE", TRS.get_string(data_list2[k], "VALUE"));
					}
				}
			}





			if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
			{
				MWIPLOTSTSX_DEL.LOT_DEL_FLAG = ' ';
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_DEL);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_DEL UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_DEL.FACTORY), MWIPLOTSTSX_DEL.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_ID), MWIPLOTSTSX_DEL.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_DEL_FLAG", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_DEL_FLAG), MWIPLOTSTSX_DEL.LOT_DEL_FLAG);


					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}



				if (EDC_COLLECT_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE) 
				{
					return MP_FALSE;
				}


				MWIPLOTSTSX_DEL.LOT_DEL_FLAG = 'Y';
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_DEL);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_DEL_FLAG", MP_STR, sizeof(MWIPLOTSTSX.LOT_DEL_FLAG), MWIPLOTSTSX.LOT_DEL_FLAG);


					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

			}
			else
			{
				if (EDC_COLLECT_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE)
					return MP_FALSE;
			}


		}
		else
		{



			tran_in_node = TRS.add_node(in_node, "Collect_Lot_Data");
			CopyDefaultMembers(tran_in_node, in_node);
			TRS.add_char(tran_in_node, IN_PROCSTEP, '1');
			TRS.add_nstring(tran_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
			TRS.add_int(tran_in_node, "HIST_SEQ", TRS.get_int(in_node, "HIST_SEQ"));
			TRS.add_nstring(tran_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
			TRS.add_int(tran_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
			TRS.add_nstring(tran_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
			TRS.add_int(tran_in_node, "FLOW_SEQ_NUM", TRS.get_int(in_node, "FLOW_SEQ_NUM"));
			TRS.add_nstring(tran_in_node, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(tran_in_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
			TRS.add_char(tran_in_node, "LOT_EDC_TRAN_FLAG", 'Y');
			TRS.add_char(tran_in_node, "SELECT_MFO_FLAG", ' ');
			TRS.add_char(tran_in_node, "COL_SET_OVR_FLAG", 'Y');
			TRS.add_nstring(tran_in_node, "PROC_FLOW", TRS.get_int(in_node, "FLOW_SEQ_NUM"));
			TRS.add_nstring(tran_in_node, "PROC_OPER", TRS.get_string(in_node, "OPER"));

			i_list_count = TRS.get_item_count(in_node, "CHAR_LIST");
			data_list = TRS.get_list(in_node, "CHAR_LIST");

			for (int i = 0; i < i_list_count; i++)
			{
				char_list = TRS.add_node(tran_in_node, "CHAR_LIST");
				TRS.add_nstring(char_list, "COL_SET_ID", TRS.get_string(data_list[i], "COL_SET_ID"));
				TRS.add_int(char_list, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
				TRS.add_int(char_list, "COL_SEQ", TRS.get_int(data_list[i], "COL_SEQ"));
				TRS.add_nstring(char_list, "CHAR_ID", TRS.get_string(data_list[i], "CHAR_ID"));
				TRS.add_int(char_list, "CHAR_SEQ_NUM", TRS.get_int(data_list[i], "CHAR_SEQ_NUM"));

				i_list_count1 = TRS.get_item_count(data_list[i], "UNIT_LIST");
				data_list1 = TRS.get_list(data_list[i], "UNIT_LIST");
				for (int j = 0; j < i_list_count1; j++)
				{
					unit_list = TRS.add_node(char_list, "UNIT_LIST");
					TRS.add_nstring(unit_list, "UNIT_ID", TRS.get_string(data_list1[j], "UNIT_ID"));
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", TRS.get_int(data_list1[j], "UNIT_SEQ_NUM"));

					value_seq_list = TRS.add_node(unit_list, "VALUE_SEQ_LIST");
					TRS.add_int(value_seq_list, "VALUE_SEQ_NUM", 1);

					i_list_count2 = TRS.get_item_count(data_list1[j], "VALUE_LIST");
					data_list2 = TRS.get_list(data_list1[j], "VALUE_LIST");
					for (int k = 0; k < i_list_count2; k++)
					{
						value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
						TRS.add_nstring(value_list, "VALUE", TRS.get_string(data_list2[k], "VALUE"));
					}
				}
			}







			if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
			{
				MWIPLOTSTSX_DEL.LOT_DEL_FLAG = ' ';
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_DEL);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_DEL UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_DEL.FACTORY), MWIPLOTSTSX_DEL.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX_DEL.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_DEL_FLAG", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_DEL_FLAG), MWIPLOTSTSX_DEL.LOT_DEL_FLAG);


					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}



				if (EDC_CHANGE_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE)  
				{
					return MP_FALSE;
				}


				MWIPLOTSTSX_DEL.LOT_DEL_FLAG = 'Y';
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_DEL);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_DEL.FACTORY), MWIPLOTSTSX_DEL.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_ID), MWIPLOTSTSX_DEL.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_DEL_FLAG", MP_STR, sizeof(MWIPLOTSTSX_DEL.LOT_DEL_FLAG), MWIPLOTSTSX_DEL.LOT_DEL_FLAG);


					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

			}
			else
			{

				if (EDC_CHANGE_LOT_DATA(s_msg_code, tran_in_node, out_node) == MP_FALSE)  
					return MP_FALSE;
			}



		}



	}


    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Input_Lot_Data_Validation()
- Validation Check sub function of "CUS_WIP_INPUT_LOT_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Input_Lot_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
    {
        return MP_FALSE;
    }

    // FACTORY VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }


    return MP_TRUE;
}
