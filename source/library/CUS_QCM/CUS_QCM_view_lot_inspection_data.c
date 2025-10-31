/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_view_lot_info.c
Description : View Lot Infomation function

MES Version : 5.0

Function List
- step 1: Lot id를 조회하여 lot 리스트 정보를 리턴한다. 


Detail Description
- 검사 Lot에 대한 기본 데이터를 조회

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/02   KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_QCM_common.h"

int CUS_QCM_View_Lot_Inspection_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_VIEW_LOT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_QCM_View_Lot_Info()
- View Lot Info
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_View_Lot_Inspection_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_VIEW_LOT_INSPECTION_DATA(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_View_Lot_Inspection_Data", out_node);
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
CUS_QCM_VIEW_LOT_INSPECTION_DATA()
- Main sub function of "CUS_QCM_View_Lot_Inspection_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_VIEW_LOT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPDAT_TAG CQCMISPDAT;
	struct MEDCCOLDEF_TAG MEDCCOLDEF;
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPSTS_TAG CQCMISPSTS_LP;

	//struct MEDCLOTDAT_TAG MEDCLOTDAT;

	struct MWIPMATDEF_TAG MWIPMATDEF_D;
	struct CWIPLOTRND_TAG CWIPLOTRND;
	

	char c_insp_kind[31];
	char s_real_d_value1[25];
	char s_real_d_value2[25];
	double d_real_d_ref;

	double d_max_d_value1;
	double d_max_d_value2;

	int i_rnd_seq;

	TRSNode *data_list;

    LOG_head("CUS_QCM_View_Lot_Inspection_Data");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_QCM_View_Lot_Inspection_Data_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	memset(c_insp_kind, ' ', sizeof(c_insp_kind));
	memset(s_real_d_value1, ' ', sizeof(s_real_d_value1));
	memset(s_real_d_value2, ' ', sizeof(s_real_d_value2));

    //Lot 조회
	if (TRS.get_procstep(in_node) == '1')
	{
		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		DBU_init_medccoldef(&MEDCCOLDEF);
		TRS.copy(MEDCCOLDEF.FACTORY, sizeof(MEDCCOLDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MEDCCOLDEF.COL_SET_ID, sizeof(MEDCCOLDEF.COL_SET_ID), in_node, "COL_SET_ID");
		DBU_select_medccoldef(1, &MEDCCOLDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "MEDCCOLDEF SELECT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLDEF.FACTORY), MEDCCOLDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(MEDCCOLDEF.COL_SET_ID), MEDCCOLDEF.COL_SET_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		memcpy(c_insp_kind, MEDCCOLDEF.COL_CMF_2, sizeof(MEDCCOLDEF.COL_CMF_2)); //검사종류

		//Round검사인경우
		//L/P인경우도 추가 (C-SCAN 검사쪽 끌고와야햠.20250328 syw)
		if (memcmp(c_insp_kind, "A", strlen("A")) == 0  || memcmp(c_insp_kind, "L", strlen("L")) == 0)
		{
			//데이터 존재 유무
			DBU_init_cqcmispdat(&CQCMISPDAT);
			TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
			if ((int)DBU_select_cqcmispdat_scalar(8, &CQCMISPDAT) > 0)
			{
				//있는 데이터 그대로
				DBU_open_cqcmispdat(5, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cqcmispdat(5);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cqcmispdat(5);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					data_list = TRS.add_node(out_node, "DATA_LIST");

					TRS.add_string(data_list, "FACTORY", CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY));
					TRS.add_string(data_list, "INSP_ID", CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID));
					TRS.add_string(data_list, "COL_SET_ID", CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID));
					TRS.add_int(data_list, "COL_SET_VER", CQCMISPDAT.COL_SET_VER);
					TRS.add_int(data_list, "INSP_SEQ", CQCMISPDAT.INSP_SEQ);
					TRS.add_string(data_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
					TRS.add_int(data_list, "CHAR_SEQ", CQCMISPDAT.CHAR_SEQ);
					TRS.add_int(data_list, "UNIT_SEQ", CQCMISPDAT.UNIT_SEQ);
					TRS.add_int(data_list, "VALUE_SEQ", CQCMISPDAT.VALUE_SEQ);
					TRS.add_string(data_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
					TRS.add_char(data_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
					TRS.add_int(data_list, "VALUE_COUNT", CQCMISPDAT.VALUE_COUNT);
					TRS.add_string(data_list, "VALUE_1", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
					TRS.add_string(data_list, "VALUE_2", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
					TRS.add_string(data_list, "VALUE_3", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
					TRS.add_string(data_list, "VALUE_4", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
					TRS.add_string(data_list, "VALUE_5", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
					TRS.add_string(data_list, "VALUE_6", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
					TRS.add_string(data_list, "VALUE_7", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
					TRS.add_string(data_list, "VALUE_8", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
					TRS.add_string(data_list, "VALUE_9", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
					TRS.add_string(data_list, "VALUE_10", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
					TRS.add_string(data_list, "VALUE_11", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
					TRS.add_string(data_list, "VALUE_12", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
					TRS.add_string(data_list, "VALUE_13", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
					TRS.add_string(data_list, "VALUE_14", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
					TRS.add_string(data_list, "VALUE_15", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
					TRS.add_string(data_list, "VALUE_16", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
					TRS.add_string(data_list, "VALUE_17", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
					TRS.add_string(data_list, "VALUE_18", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
					TRS.add_string(data_list, "VALUE_19", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
					TRS.add_string(data_list, "VALUE_20", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
					TRS.add_string(data_list, "VALUE_21", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
					TRS.add_string(data_list, "VALUE_22", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
					TRS.add_string(data_list, "VALUE_23", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
					TRS.add_string(data_list, "VALUE_24", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
					TRS.add_string(data_list, "VALUE_25", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));

				}
			}
			else
			{
				// L/P검사 데이터 가져옴
				DBU_init_cqcmispsts(&CQCMISPSTS_LP);
				TRS.copy(CQCMISPSTS_LP.FACTORY, sizeof(CQCMISPSTS_LP.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPSTS_LP.LOT_ID, sizeof(CQCMISPSTS_LP.LOT_ID), in_node, "LOT_ID");
				CQCMISPSTS_LP.INSP_STATUS = MP_CQMS_STATUS_COMPLETE;
				DBU_select_cqcmispsts(4,&CQCMISPSTS_LP);
				if (DB_error_code == DB_SUCCESS)
				{
					
					DBU_init_cqcmispdat(&CQCMISPDAT);
					TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS_LP.INSP_ID, sizeof(CQCMISPSTS_LP.INSP_ID));
					memcpy(CQCMISPDAT.COL_SET_ID, CQCMISPSTS_LP.COL_SET_ID, sizeof(CQCMISPSTS_LP.COL_SET_ID));
					DBU_open_cqcmispdat(5, &CQCMISPDAT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmispdat(5);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmispdat(5);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						data_list = TRS.add_node(out_node, "DATA_LIST");

						TRS.add_string(data_list, "FACTORY", CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY));
						TRS.add_string(data_list, "INSP_ID", CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID));
						TRS.add_string(data_list, "COL_SET_ID", CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID));
						TRS.add_int(data_list, "COL_SET_VER", CQCMISPDAT.COL_SET_VER);
						TRS.add_int(data_list, "INSP_SEQ", CQCMISPDAT.INSP_SEQ);
						TRS.add_string(data_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
						TRS.add_int(data_list, "CHAR_SEQ", CQCMISPDAT.CHAR_SEQ);
						TRS.add_int(data_list, "UNIT_SEQ", CQCMISPDAT.UNIT_SEQ);
						TRS.add_int(data_list, "VALUE_SEQ", CQCMISPDAT.VALUE_SEQ);
						TRS.add_string(data_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
						TRS.add_char(data_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
						TRS.add_int(data_list, "VALUE_COUNT", CQCMISPDAT.VALUE_COUNT);
						TRS.add_string(data_list, "VALUE_1", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						TRS.add_string(data_list, "VALUE_2", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
						TRS.add_string(data_list, "VALUE_3", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
						TRS.add_string(data_list, "VALUE_4", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
						TRS.add_string(data_list, "VALUE_5", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
						TRS.add_string(data_list, "VALUE_6", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
						TRS.add_string(data_list, "VALUE_7", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
						TRS.add_string(data_list, "VALUE_8", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
						TRS.add_string(data_list, "VALUE_9", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
						TRS.add_string(data_list, "VALUE_10", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
						TRS.add_string(data_list, "VALUE_11", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
						TRS.add_string(data_list, "VALUE_12", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
						TRS.add_string(data_list, "VALUE_13", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
						TRS.add_string(data_list, "VALUE_14", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
						TRS.add_string(data_list, "VALUE_15", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
						TRS.add_string(data_list, "VALUE_16", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
						TRS.add_string(data_list, "VALUE_17", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
						TRS.add_string(data_list, "VALUE_18", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
						TRS.add_string(data_list, "VALUE_19", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
						TRS.add_string(data_list, "VALUE_20", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
						TRS.add_string(data_list, "VALUE_21", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
						TRS.add_string(data_list, "VALUE_22", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
						TRS.add_string(data_list, "VALUE_23", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
						TRS.add_string(data_list, "VALUE_24", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
						TRS.add_string(data_list, "VALUE_25", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));

					}
				}
				else
				{
					if (DB_error_code == DB_NOT_FOUND)
					{

					}
					else
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT(4)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CQCMISPSTS.LOT_ID), CQCMISPSTS.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}



				// 실제직경 구하는 값 
				DBU_init_mwipmatdef(&MWIPMATDEF_D);
				TRS.copy(MWIPMATDEF_D.FACTORY, sizeof(MWIPMATDEF_D.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF_D.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
				MWIPMATDEF_D.MAT_VER = CQCMISPSTS.MAT_VER;
				//(최대직경에서 해당값을 빼줘야 실제직경)
				d_real_d_ref = DBU_select_mwipmatdef_scalar(2, &MWIPMATDEF_D);


				//라운드 설비 데이터의 최근 Seq
				DBU_init_cwiplotrnd(&CWIPLOTRND);
				TRS.copy(CWIPLOTRND.LOT_ID, sizeof(CWIPLOTRND.LOT_ID), in_node, "LOT_ID");
				i_rnd_seq = (int)DBU_select_cwiplotrnd_scalar(2, &CWIPLOTRND);


				//라운드 설비데이터에서 직접 가져오는것으로 변경
				//설비 신호시 기존 edc테이블에 넣어줬던로직은 spc데이터를 판정시 넣어줄 예정이므로 기능을 뺄 예정
				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.CMF_1, sizeof(CQCMISPDAT.CMF_1), in_node, "LOT_ID");
				CQCMISPDAT.INSP_SEQ = i_rnd_seq;
				DBU_open_cqcmispdat(8, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CQCMISPDAT.CMF_1), CQCMISPDAT.CMF_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				while (1)
				{
					DBU_fetch_cqcmispdat(8, &CQCMISPDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cqcmispdat(8);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cqcmispdat(8);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}


					if (memcmp(CQCMISPDAT.CHAR_ID, "MAX-D", strlen("MAX-D")) == 0)
					{
						d_max_d_value1 = COM_atof(CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						d_max_d_value2 = COM_atof(CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
					}
					else {
						d_max_d_value1 = 0;
						d_max_d_value2 = 0;
					}

					data_list = TRS.add_node(out_node, "DATA_LIST");

					TRS.add_string(data_list, "FACTORY", CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY));
					TRS.add_string(data_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
					TRS.add_int(data_list, "CHAR_SEQ", CQCMISPDAT.CHAR_SEQ);
					TRS.add_int(data_list, "UNIT_SEQ", 1);
					TRS.add_int(data_list, "VALUE_SEQ", 1);
					TRS.add_char(data_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
					TRS.add_int(data_list, "VALUE_COUNT", CQCMISPDAT.VALUE_COUNT);

                    //로직이 안탐 => 캐릭터 비교문 수정 _20210318_01
					if (memcmp(CQCMISPDAT.CHAR_ID, "REAL-D", strlen("REAL-D")) == 0)
					{
						COM_dtoa(s_real_d_value1, d_max_d_value1 - d_real_d_ref, sizeof(s_real_d_value1));
						TRS.add_string(data_list, "VALUE_1", s_real_d_value1, sizeof(s_real_d_value1));

						COM_dtoa(s_real_d_value2, d_max_d_value2 - d_real_d_ref, sizeof(s_real_d_value2));
						TRS.add_string(data_list, "VALUE_2", s_real_d_value2, sizeof(s_real_d_value2));
					}
					else
					{
						TRS.add_string(data_list, "VALUE_1", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						TRS.add_string(data_list, "VALUE_2", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
					}

					TRS.add_string(data_list, "VALUE_3", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
					TRS.add_string(data_list, "VALUE_4", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
					TRS.add_string(data_list, "VALUE_5", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
					TRS.add_string(data_list, "VALUE_6", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
					TRS.add_string(data_list, "VALUE_7", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
					TRS.add_string(data_list, "VALUE_8", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
					TRS.add_string(data_list, "VALUE_9", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
					TRS.add_string(data_list, "VALUE_10", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
					TRS.add_string(data_list, "VALUE_11", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
					TRS.add_string(data_list, "VALUE_12", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
					TRS.add_string(data_list, "VALUE_13", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));

					/*
					DBU_init_medclotdat(&MEDCLOTDAT);
					TRS.copy(MEDCLOTDAT.LOT_ID, sizeof(MEDCLOTDAT.LOT_ID), in_node, "LOT_ID");
					DBU_open_medclotdat(2, &MEDCLOTDAT);
					if (DB_error_code != DB_SUCCESS)
					{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MEDCLOTDAT OPEN", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MEDCLOTDAT.LOT_ID), MEDCLOTDAT.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
					}

					while (1)
					{
					DBU_fetch_medclotdat(2, &MEDCLOTDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
					DBU_close_medclotdat(2);
					break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MEDCLOTDAT FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_medclotdat(2);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
					}

					if (memcmp(MEDCLOTDAT.CHAR_ID, "MAX-D", strlen("MAX-D")) == 0)
					{
					d_max_d_value1 = COM_atof(MEDCLOTDAT.VALUE_1, sizeof(MEDCLOTDAT.VALUE_1));
					d_max_d_value2 = COM_atof(MEDCLOTDAT.VALUE_2, sizeof(MEDCLOTDAT.VALUE_2));
					}

					data_list = TRS.add_node(out_node, "DATA_LIST");


					TRS.add_string(data_list, "FACTORY", MEDCLOTDAT.FACTORY, sizeof(MEDCLOTDAT.FACTORY));
					TRS.add_string(data_list, "CHAR_ID", MEDCLOTDAT.CHAR_ID, sizeof(MEDCLOTDAT.CHAR_ID));
					TRS.add_int(data_list, "CHAR_SEQ", MEDCLOTDAT.CHAR_SEQ_NUM);
					TRS.add_int(data_list, "UNIT_SEQ", MEDCLOTDAT.UNIT_SEQ_NUM);
					TRS.add_int(data_list, "VALUE_SEQ", MEDCLOTDAT.VALUE_SEQ_NUM);
					TRS.add_char(data_list, "VALUE_TYPE", MEDCLOTDAT.VALUE_TYPE);
					TRS.add_int(data_list, "VALUE_COUNT", MEDCLOTDAT.VALUE_COUNT);

					if (memcmp(MEDCLOTDAT.CHAR_ID, "REAL-D", strlen("REAL-D")) == 0)
					{
					COM_dtoa(s_real_d_value1, d_max_d_value1 - d_real_d_ref, sizeof(s_real_d_value1));
					TRS.add_string(data_list, "VALUE_1", s_real_d_value1, sizeof(s_real_d_value1));

					COM_dtoa(s_real_d_value2, d_max_d_value2 - d_real_d_ref, sizeof(s_real_d_value2));
					TRS.add_string(data_list, "VALUE_2", s_real_d_value2, sizeof(s_real_d_value2));
					}
					else
					{
					TRS.add_string(data_list, "VALUE_1", MEDCLOTDAT.VALUE_1, sizeof(MEDCLOTDAT.VALUE_1));
					TRS.add_string(data_list, "VALUE_2", MEDCLOTDAT.VALUE_2, sizeof(MEDCLOTDAT.VALUE_2));
					}

					TRS.add_string(data_list, "VALUE_3", MEDCLOTDAT.VALUE_3, sizeof(MEDCLOTDAT.VALUE_3));
					TRS.add_string(data_list, "VALUE_4", MEDCLOTDAT.VALUE_4, sizeof(MEDCLOTDAT.VALUE_4));
					TRS.add_string(data_list, "VALUE_5", MEDCLOTDAT.VALUE_5, sizeof(MEDCLOTDAT.VALUE_5));
					TRS.add_string(data_list, "VALUE_6", MEDCLOTDAT.VALUE_6, sizeof(MEDCLOTDAT.VALUE_6));
					TRS.add_string(data_list, "VALUE_7", MEDCLOTDAT.VALUE_7, sizeof(MEDCLOTDAT.VALUE_7));
					TRS.add_string(data_list, "VALUE_8", MEDCLOTDAT.VALUE_8, sizeof(MEDCLOTDAT.VALUE_8));
					TRS.add_string(data_list, "VALUE_9", MEDCLOTDAT.VALUE_9, sizeof(MEDCLOTDAT.VALUE_9));
					TRS.add_string(data_list, "VALUE_10", MEDCLOTDAT.VALUE_10, sizeof(MEDCLOTDAT.VALUE_10));
					TRS.add_string(data_list, "VALUE_11", MEDCLOTDAT.VALUE_11, sizeof(MEDCLOTDAT.VALUE_11));
					TRS.add_string(data_list, "VALUE_12", MEDCLOTDAT.VALUE_12, sizeof(MEDCLOTDAT.VALUE_12));
					TRS.add_string(data_list, "VALUE_13", MEDCLOTDAT.VALUE_13, sizeof(MEDCLOTDAT.VALUE_13));
					TRS.add_string(data_list, "VALUE_14", MEDCLOTDAT.VALUE_14, sizeof(MEDCLOTDAT.VALUE_14));
					TRS.add_string(data_list, "VALUE_15", MEDCLOTDAT.VALUE_15, sizeof(MEDCLOTDAT.VALUE_15));
					TRS.add_string(data_list, "VALUE_16", MEDCLOTDAT.VALUE_16, sizeof(MEDCLOTDAT.VALUE_16));
					TRS.add_string(data_list, "VALUE_17", MEDCLOTDAT.VALUE_17, sizeof(MEDCLOTDAT.VALUE_17));
					TRS.add_string(data_list, "VALUE_18", MEDCLOTDAT.VALUE_18, sizeof(MEDCLOTDAT.VALUE_18));
					TRS.add_string(data_list, "VALUE_19", MEDCLOTDAT.VALUE_19, sizeof(MEDCLOTDAT.VALUE_19));
					TRS.add_string(data_list, "VALUE_20", MEDCLOTDAT.VALUE_20, sizeof(MEDCLOTDAT.VALUE_20));
					TRS.add_string(data_list, "VALUE_21", MEDCLOTDAT.VALUE_21, sizeof(MEDCLOTDAT.VALUE_21));
					TRS.add_string(data_list, "VALUE_22", MEDCLOTDAT.VALUE_22, sizeof(MEDCLOTDAT.VALUE_22));
					TRS.add_string(data_list, "VALUE_23", MEDCLOTDAT.VALUE_23, sizeof(MEDCLOTDAT.VALUE_23));
					TRS.add_string(data_list, "VALUE_24", MEDCLOTDAT.VALUE_24, sizeof(MEDCLOTDAT.VALUE_24));
					TRS.add_string(data_list, "VALUE_25", MEDCLOTDAT.VALUE_25, sizeof(MEDCLOTDAT.VALUE_25));

					}
					*/

				}
			}
		}
		else
		{
			DBU_init_cqcmispdat(&CQCMISPDAT);
			TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
			//있는 데이터 그대로
			DBU_open_cqcmispdat(5, &CQCMISPDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_cqcmispdat(5);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cqcmispdat(5);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				data_list = TRS.add_node(out_node, "DATA_LIST");

				TRS.add_string(data_list, "FACTORY", CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY));
				TRS.add_string(data_list, "INSP_ID", CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID));
				TRS.add_string(data_list, "COL_SET_ID", CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID));
				TRS.add_int(data_list, "COL_SET_VER", CQCMISPDAT.COL_SET_VER);
				TRS.add_int(data_list, "INSP_SEQ", CQCMISPDAT.INSP_SEQ);
				TRS.add_string(data_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
				TRS.add_int(data_list, "CHAR_SEQ", CQCMISPDAT.CHAR_SEQ);
				TRS.add_int(data_list, "UNIT_SEQ", CQCMISPDAT.UNIT_SEQ);
				TRS.add_int(data_list, "VALUE_SEQ", CQCMISPDAT.VALUE_SEQ);
				TRS.add_string(data_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
				TRS.add_char(data_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
				TRS.add_int(data_list, "VALUE_COUNT", CQCMISPDAT.VALUE_COUNT);
				TRS.add_string(data_list, "VALUE_1", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
				TRS.add_string(data_list, "VALUE_2", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
				TRS.add_string(data_list, "VALUE_3", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
				TRS.add_string(data_list, "VALUE_4", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
				TRS.add_string(data_list, "VALUE_5", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
				TRS.add_string(data_list, "VALUE_6", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
				TRS.add_string(data_list, "VALUE_7", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
				TRS.add_string(data_list, "VALUE_8", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
				TRS.add_string(data_list, "VALUE_9", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
				TRS.add_string(data_list, "VALUE_10", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
				TRS.add_string(data_list, "VALUE_11", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
				TRS.add_string(data_list, "VALUE_12", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
				TRS.add_string(data_list, "VALUE_13", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
				TRS.add_string(data_list, "VALUE_14", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
				TRS.add_string(data_list, "VALUE_15", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
				TRS.add_string(data_list, "VALUE_16", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
				TRS.add_string(data_list, "VALUE_17", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
				TRS.add_string(data_list, "VALUE_18", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
				TRS.add_string(data_list, "VALUE_19", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
				TRS.add_string(data_list, "VALUE_20", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
				TRS.add_string(data_list, "VALUE_21", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
				TRS.add_string(data_list, "VALUE_22", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
				TRS.add_string(data_list, "VALUE_23", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
				TRS.add_string(data_list, "VALUE_24", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
				TRS.add_string(data_list, "VALUE_25", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));
			}
		}
	}
	// 검사 조회 화면 용
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		
		DBU_open_cqcmispdat(6, &CQCMISPDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN(6)", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cqcmispdat(6, &CQCMISPDAT);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cqcmispdat(6);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH(6)", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cqcmispdat(6);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			data_list = TRS.add_node(out_node, "DATA_LIST");

			TRS.add_string(data_list, "FACTORY", CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY));
			TRS.add_string(data_list, "INSP_ID", CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID));
			TRS.add_string(data_list, "COL_SET_ID", CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID));
			TRS.add_int(data_list, "COL_SET_VER", CQCMISPDAT.COL_SET_VER);
			TRS.add_int(data_list, "INSP_SEQ", CQCMISPDAT.INSP_SEQ);
			TRS.add_string(data_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
			TRS.add_int(data_list, "CHAR_SEQ", CQCMISPDAT.CHAR_SEQ);
			TRS.add_int(data_list, "UNIT_SEQ", CQCMISPDAT.UNIT_SEQ);
			TRS.add_int(data_list, "VALUE_SEQ", CQCMISPDAT.VALUE_SEQ);
			TRS.add_string(data_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
			TRS.add_char(data_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
			TRS.add_int(data_list, "VALUE_COUNT", CQCMISPDAT.VALUE_COUNT);
			TRS.add_string(data_list, "VALUE_1", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
			TRS.add_string(data_list, "VALUE_2", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
			TRS.add_string(data_list, "VALUE_3", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
			TRS.add_string(data_list, "VALUE_4", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
			TRS.add_string(data_list, "VALUE_5", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
			TRS.add_string(data_list, "VALUE_6", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
			TRS.add_string(data_list, "VALUE_7", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
			TRS.add_string(data_list, "VALUE_8", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
			TRS.add_string(data_list, "VALUE_9", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
			TRS.add_string(data_list, "VALUE_10", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
			TRS.add_string(data_list, "VALUE_11", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
			TRS.add_string(data_list, "VALUE_12", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
			TRS.add_string(data_list, "VALUE_13", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
			TRS.add_string(data_list, "VALUE_14", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
			TRS.add_string(data_list, "VALUE_15", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
			TRS.add_string(data_list, "VALUE_16", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
			TRS.add_string(data_list, "VALUE_17", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
			TRS.add_string(data_list, "VALUE_18", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
			TRS.add_string(data_list, "VALUE_19", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
			TRS.add_string(data_list, "VALUE_20", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
			TRS.add_string(data_list, "VALUE_21", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
			TRS.add_string(data_list, "VALUE_22", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
			TRS.add_string(data_list, "VALUE_23", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
			TRS.add_string(data_list, "VALUE_24", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
			TRS.add_string(data_list, "VALUE_25", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));
		}
	}
	// 검사 마스터 정보 조회
	else if (TRS.get_procstep(in_node) == '3')
	{
		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");

		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT(1)", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_string(out_node, "FACTORY", CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY));
		TRS.add_string(out_node, "INSP_ID", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
		TRS.add_string(out_node, "INSP_TYPE", CQCMISPSTS.INSP_TYPE, sizeof(CQCMISPSTS.INSP_TYPE));
		TRS.add_string(out_node, "COL_SET_ID", CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID));
		TRS.add_int(out_node, "COL_SET_VERSION", CQCMISPSTS.COL_SET_VERSION);
		TRS.add_string(out_node, "LOT_ID", CQCMISPSTS.LOT_ID, sizeof(CQCMISPSTS.LOT_ID));
		TRS.add_string(out_node, "MAT_ID", CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
		TRS.add_int(out_node, "MAT_VER", CQCMISPSTS.MAT_VER);
		TRS.add_string(out_node, "AREA_ID", CQCMISPSTS.AREA_ID, sizeof(CQCMISPSTS.AREA_ID));		
		TRS.add_string(out_node, "INSP_OPER", CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
	}

    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_View_Lot_Inspection_Data_Validation()
- Validation Check sub function of "CUS_QCM_VIEW_LOT_INSPECTION_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_View_Lot_Inspection_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    return MP_TRUE;
}
