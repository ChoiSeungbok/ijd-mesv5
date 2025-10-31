/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Collect_Cut_Inspection_Upload.c
Description : Tran Inspection Save function

MES Version : 5.0

Function List
-

Detail Description
- Client에서 절단품검사 데이터 엑셀(데이터만 붙여넣기 가능) 업로드시 사용하는 서비스
- 업로드시에는 Lot번호만 알고있으므로,  Lot으로 검사요청번호를 찾아서 데이터를 저장.

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/12/14  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Collect_Cut_Inspection_Upload_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Collect_Inspection_Data()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Cut_Inspection_Upload(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

	//CUS_QCM_Collect_Cut_Inspection_Upload
    i_ret = CUS_QCM_COLLECT_CUT_INSPECTION_UPLOAD(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Collect_Cut_Inspection_Upload", out_node);
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
CUS_QCM_COLLECT_CUT_INSPECTION_UPLOAD()
- Main sub function of "CUS_QCM_Collect_Cut_Inspection_Upload" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_COLLECT_CUT_INSPECTION_UPLOAD(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPDAT_TAG CQCMISPDAT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;

	struct MWIPCOLDEF_TAG MWIPCOLDEF;
	struct MEDCCOLDEF_TAG MEDCCOLDEF;
	struct MEDCCOLVER_TAG MEDCCOLVER;
	struct MEDCCOLCHR_TAG MEDCCOLCHR;
	struct MEDCCHRDEF_TAG MEDCCHRDEF;

	char s_sys_time[14];

	TRSNode **data_list;

//	TRSNode *insp_in;
//	TRSNode *cmn_out;

	int i_data_count;
	int i_select_count;
	int i_col_set_count;
	int i_col_set_version;


    LOG_head("CUS_QCM_Collect_Cut_Inspection_Upload");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "QCM-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


    /* Validation Check */
    if (CUS_QCM_Collect_Cut_Inspection_Upload_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   
	// 엑셀 업로드 저장
	if (TRS.get_procstep(in_node) == '1')
	{

		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			if (TRS.get_char(data_list[i], "SKIP_YN") == 'Y')
			{
				continue;
			}
			//업로드의 경우,  LOT_ID만 가지고 검사ID(INSP_ID)를 찾아야 함.
			//Validation ( 검사ID 활성화상태로 존재여부,  해당Lot 존재 여부, 품목에 cut검사셋 존재 여부 )

			//(1) Lot가 존재하는지 확인
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), data_list[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0044");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			//(2) 검사ID 찾기
		    
			DBU_init_cqcmispsts(&CQCMISPSTS);
			TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPSTS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			memcpy(CQCMISPSTS.INSP_OPER, "OC06020", strlen("OC06020")); //임시 하드코딩
			DBU_select_cqcmispsts(3, &CQCMISPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "QCM-0050");
				}
				else
				{
					strcpy(s_msg_code, "QCM-0004");
				}

				TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT(3) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CQCMISPSTS.LOT_ID), CQCMISPSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			//(3) 해당 랏의 품목을 기준으로  검사셋이 존재확인 Validation  ( 검사셋이 존재하면 해당 검사셋으로 저장)
			
			DBU_init_mwipcoldef(&MWIPCOLDEF);
			TRS.copy(MWIPCOLDEF.FACTORY, sizeof(MWIPCOLDEF.FACTORY), in_node, IN_FACTORY);
			MWIPCOLDEF.MAT_VER = 1;
			MWIPCOLDEF.OPT_LEVEL = '4';
			memcpy(MWIPCOLDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			memcpy(MWIPCOLDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			
			i_col_set_count = (int)DBU_select_mwipcoldef_scalar(2, &MWIPCOLDEF);

			if (i_col_set_count > 1)
			{
				//QCM-0079 : 해당품목에 검사셋이 2개 이상 설정되어있습니다. 검사셋은 1개만 설정 가능합니다.
				strcpy(s_msg_code, "QCM-0079");

				TRS.add_fieldmsg(out_node, "MWIPCOLDEF Scalar(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (i_col_set_count == 0)
			{
				//QCM-0063 : 현재의 품목, 공정별 검사 Set이 설정되어있지 않습니다. MFO 설정을 하시기 바랍니다.
				strcpy(s_msg_code, "QCM-0063");

				TRS.add_fieldmsg(out_node, "MWIPCOLDEF Scalar(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			
			DBU_init_mwipcoldef(&MWIPCOLDEF);
			TRS.copy(MWIPCOLDEF.FACTORY, sizeof(MWIPCOLDEF.FACTORY), in_node, IN_FACTORY);
			MWIPCOLDEF.MAT_VER = 1;
			MWIPCOLDEF.OPT_LEVEL = '4';
			memcpy(MWIPCOLDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			memcpy(MWIPCOLDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			MWIPCOLDEF.DISABLE_FLAG = 'N';
			DBU_select_mwipcoldef(4, &MWIPCOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//QCM-0063 : 현재의 품목, 공정별 검사 Set이 설정되어있지 않습니다. MFO 설정을 하시기 바랍니다.
				strcpy(s_msg_code, "QCM-0063");

				TRS.add_fieldmsg(out_node, "MWIPCOLDEF Select(3) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_medccoldef(&MEDCCOLDEF);
			TRS.copy(MEDCCOLDEF.FACTORY, sizeof(MEDCCOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MEDCCOLDEF.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			DBU_select_medccoldef(1, &MEDCCOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//QCM-0004 
				strcpy(s_msg_code, "QCM-0004");

				TRS.add_fieldmsg(out_node, "MEDCCOLDEF Select(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLDEF.FACTORY), MEDCCOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLDEF.COL_SET_ID), MEDCCOLDEF.COL_SET_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_medccolver(&MEDCCOLVER);
			TRS.copy(MEDCCOLVER.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
			memcpy(MEDCCOLVER.COL_SET_ID, MEDCCOLDEF.COL_SET_ID, sizeof(MEDCCOLDEF.COL_SET_ID));

			i_col_set_version = (int)DBU_select_medccolver_scalar(2, &MEDCCOLVER);

			if (i_col_set_version == 0)
			{
				//QCM-0004 
				strcpy(s_msg_code, "QCM-0004");

				TRS.add_fieldmsg(out_node, "MEDCCOLVER Scalar(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);
				TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, MEDCCOLVER.COL_SET_VERSION);
				
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			DBU_init_medcchrdef(&MEDCCHRDEF);
			TRS.copy(MEDCCHRDEF.FACTORY, sizeof(MEDCCHRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MEDCCHRDEF.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID), data_list[i], "CHAR_ID");
			DBU_select_medcchrdef(1, &MEDCCHRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//QCM-0004 
				strcpy(s_msg_code, "QCM-0004");

				TRS.add_fieldmsg(out_node, "MEDCCHRDEF Select(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCHRDEF.FACTORY), MEDCCHRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(MEDCCHRDEF.CHAR_ID), MEDCCHRDEF.CHAR_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_medccolchr(&MEDCCOLCHR);
			TRS.copy(MEDCCOLCHR.FACTORY, sizeof(MEDCCOLCHR.FACTORY), in_node, IN_FACTORY);
			memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLDEF.COL_SET_ID, sizeof(MEDCCOLDEF.COL_SET_ID));
			MEDCCOLCHR.COL_SET_VERSION = i_col_set_version;
			memcpy(MEDCCOLCHR.CHAR_ID, MEDCCHRDEF.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID));
			DBU_select_medccolchr(1, &MEDCCOLCHR);
			if (DB_error_code != DB_SUCCESS)
			{
				// QCM-0080 : 품몸의 검사셋이 검사항목코드와 매칭되지 않습니다. 검사셋을 확인해주세요.
				strcpy(s_msg_code, "QCM-0080");

				TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
				TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(MEDCCOLCHR.CHAR_ID), MEDCCOLCHR.CHAR_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}




			//CQCMISPSTS.INSP_ID => 검사의뢰 ID
			//MWIPCOLDEF.COL_SET_ID  => 검사셋

			DBU_init_cqcmispdat(&CQCMISPDAT);
			TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(CQCMISPDAT.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			CQCMISPDAT.COL_SET_VER = (int)DBU_select_medccolver_scalar(2, &MEDCCOLVER);
			CQCMISPDAT.INSP_SEQ = 1;

			//검사 Data List
			TRS.copy(CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID), data_list[i], "CHAR_ID");
			CQCMISPDAT.CHAR_SEQ = MEDCCOLCHR.SEQ_NUM;
			CQCMISPDAT.UNIT_SEQ = 1;
			CQCMISPDAT.VALUE_SEQ = 1;
			memset(CQCMISPDAT.UNIT_ID, ' ', sizeof(CQCMISPDAT.UNIT_ID));

			CQCMISPDAT.VALUE_TYPE = MEDCCHRDEF.VALUE_TYPE;
			CQCMISPDAT.VALUE_COUNT = MEDCCOLCHR.VALUE_COUNT;

			TRS.copy(CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1), data_list[i], "VALUE_1");
			TRS.copy(CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2), data_list[i], "VALUE_2");
			TRS.copy(CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3), data_list[i], "VALUE_3");
			TRS.copy(CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4), data_list[i], "VALUE_4");
			TRS.copy(CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5), data_list[i], "VALUE_5");
			TRS.copy(CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6), data_list[i], "VALUE_6");
			TRS.copy(CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7), data_list[i], "VALUE_7");
			TRS.copy(CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8), data_list[i], "VALUE_8");
			TRS.copy(CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9), data_list[i], "VALUE_9");
			TRS.copy(CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10), data_list[i], "VALUE_10");
			TRS.copy(CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11), data_list[i], "VALUE_11");
			TRS.copy(CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12), data_list[i], "VALUE_12");
			TRS.copy(CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13), data_list[i], "VALUE_13");
			TRS.copy(CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14), data_list[i], "VALUE_14");
			TRS.copy(CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15), data_list[i], "VALUE_15");
			TRS.copy(CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16), data_list[i], "VALUE_16");
			TRS.copy(CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17), data_list[i], "VALUE_17");
			TRS.copy(CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18), data_list[i], "VALUE_18");
			TRS.copy(CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19), data_list[i], "VALUE_19");
			TRS.copy(CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20), data_list[i], "VALUE_20");
			TRS.copy(CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21), data_list[i], "VALUE_21");
			TRS.copy(CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22), data_list[i], "VALUE_22");
			TRS.copy(CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23), data_list[i], "VALUE_23");
			TRS.copy(CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24), data_list[i], "VALUE_24");
			TRS.copy(CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25), data_list[i], "VALUE_25");




			i_select_count = (int)DBU_select_cqcmispdat_scalar(1, &CQCMISPDAT);

			if (i_select_count > 0)
			{
				//update
				memcpy(CQCMISPDAT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMISPDAT.UPDATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmispdat(2, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMISPDAT.INSP_SEQ);
					TRS.add_fieldmsg(out_node, "CHAR_SEQ", MP_INT, CQCMISPDAT.CHAR_SEQ);
					TRS.add_fieldmsg(out_node, "UNIT_SEQ", MP_INT, CQCMISPDAT.UNIT_SEQ);
					TRS.add_fieldmsg(out_node, "VALUE_SEQ", MP_INT, CQCMISPDAT.VALUE_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				//insert
				memcpy(CQCMISPDAT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMISPDAT.CREATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cqcmispdat(&CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMISPDAT.INSP_SEQ);
					TRS.add_fieldmsg(out_node, "CHAR_SEQ", MP_INT, CQCMISPDAT.CHAR_SEQ);
					TRS.add_fieldmsg(out_node, "UNIT_SEQ", MP_INT, CQCMISPDAT.UNIT_SEQ);
					TRS.add_fieldmsg(out_node, "VALUE_SEQ", MP_INT, CQCMISPDAT.VALUE_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}


		// EDC 데이터 저장 ( SPC )
		/* 검사등록(표준) 화면으로 판정시 판정로직전에 한번더 데이터 저장( EDC 저장 로직 )을 하기 때문에 여기서 넣지않고 주석처리함. 
		insp_in = TRS.add_node(in_node, "insp_in");
		TRS.add_char(insp_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(insp_in, in_node);

		TRS.add_nstring(insp_in, "INSP_ID", TRS.get_string(in_node, "INSP_ID"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_COLLECT_SPC_DATA(s_msg_code, insp_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		*/


	}
    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Collect_Cut_Inspection_Upload_Validation()
- Validation Check sub function of "CUS_QCM_COLLECT_INSPECTION_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Cut_Inspection_Upload_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12345678") == MP_FALSE)
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
