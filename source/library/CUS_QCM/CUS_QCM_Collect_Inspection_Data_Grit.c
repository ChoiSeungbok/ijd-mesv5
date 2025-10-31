/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Collect_Inspection_Data_Grit.c
Description : Tran Inspection Save function

MES Version : 5.0

Function List
-

Detail Description
- Grit의 검사 (Saw / Wheel ) 의 데이터를 저장하는 서비스 
- Client에서 Grit 전용 검사화면에서 사용되며, 각 항목별로 Step을 나누었음
- 각 검사데이터 저장 후 마지막에 공통 검사데이터 테이블 CQCMISPDAT(EDC와 비슷한 구조의 품질데이터 테이블) 에 별도로 Summary해서 저장함.

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/14  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Collect_Inspection_Data_Grit_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Collect_Inspection_Data_Grit()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Inspection_Data_Grit(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_COLLECT_INSPECTION_DATA_GRIT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Collect_Inspection_Data_Grit", out_node);
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
CUS_QCM_COLLECT_INSPECTION_DATA_GRIT()
- Main sub function of "CUS_QCM_Collect_Inspection_Data_Grit" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_COLLECT_INSPECTION_DATA_GRIT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPDAT_TAG CQCMISPDAT;

	struct CQCMGRTSIV_TAG CQCMGRTSIV;
	struct CQCMGRTCOT_TAG CQCMGRTCOT;
	struct CQCMGRTHLT_TAG CQCMGRTHLT;
	struct CQCMGRTASP_TAG CQCMGRTASP;


	char s_sys_time[14];


	//TRSNode *collect_in_node;
	TRSNode **data_list;

	TRSNode *insp_in;
	TRSNode *cmn_out;

	int i_data_count;
	int i_max_insp_count;

	//int i_exists_count;

    LOG_head("CUS_QCM_Collect_Inspection_Data_Grit");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


    /* Validation Check */
    if (CUS_QCM_Collect_Inspection_Data_Grit_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   

	//Step : 1  PSD
	//Step : 2  BI
	//Step : 3  BTI
	//Step : 4  HLT
	//Step : 5  Coating
	//Step : 6 Aspect


	if (TRS.get_procstep(in_node) == '1')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for(int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMGRTSIV.INSP_ID, sizeof(CQCMGRTSIV.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMGRTSIV.INSP_DTL_TYPE, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //PSD
			CQCMGRTSIV.INSP_COUNT = TRS.get_int(in_node, "INSP_COUNT");
			CQCMGRTSIV.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");
			
			DBU_select_cqcmgrtsiv(1, &CQCMGRTSIV);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//INSERT
					TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드
																												//TRS.copy(CQCMGRTSIV.SIZES,)  //size 저장필요
					CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

					CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     //빈체 
					CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); //찬체
					CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    //차이
					CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         // (%)

					CQCMGRTSIV.SUM_DIFF_SIEVE = TRS.get_double(data_list[i], "SUM_DIFF_SIEVE"); // ( SUM DIFF)
					CQCMGRTSIV.RATIO_SIEVE = TRS.get_double(data_list[i], "RATIO_SIEVE");  // RATIO SIEVE

					memcpy(CQCMGRTSIV.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CQCMGRTSIV.CREATE_USER_ID, sizeof(CQCMGRTSIV.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cqcmgrtsiv(&CQCMGRTSIV);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
						TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
						TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
						TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);
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
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

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
				//UPDATE
				TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드
																											//TRS.copy(CQCMGRTSIV.SIZES,)  //size 저장필요
				CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

				CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     //빈체 
				CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); //찬체
				CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    //차이
				CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         // (%)

				CQCMGRTSIV.SUM_DIFF_SIEVE = TRS.get_double(data_list[i], "SUM_DIFF_SIEVE"); // ( SUM DIFF)
				CQCMGRTSIV.RATIO_SIEVE = TRS.get_double(data_list[i], "RATIO_SIEVE");  // RATIO SIEVE

				memcpy(CQCMGRTSIV.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTSIV.UPDATE_USER_ID, sizeof(CQCMGRTSIV.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmgrtsiv(1, &CQCMGRTSIV);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}

		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMGRTSIV.INSP_ID, sizeof(CQCMGRTSIV.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMGRTSIV.INSP_DTL_TYPE, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //BI
			CQCMGRTSIV.INSP_COUNT = TRS.get_int(in_node, "INSP_COUNT");
			CQCMGRTSIV.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");

			DBU_select_cqcmgrtsiv(1, &CQCMGRTSIV);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//INSERT
					TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드
																												//TRS.copy(CQCMGRTSIV.SIZES,)  //size 저장필요
					CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

					CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     // 1차 빈체 
					CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); // 1차 찬체
					CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    // 1차 차이
					CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         //  1차 (%)

					CQCMGRTSIV.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");     // 2차 빈체 
					CQCMGRTSIV.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2"); // 2차 찬체
					CQCMGRTSIV.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");    // 2차 차이
					CQCMGRTSIV.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");         //  2차 (%)

					CQCMGRTSIV.AVG_SIEVE = TRS.get_double(data_list[i], "AVG_SIEVE");  //평균
					CQCMGRTSIV.TI_CHANGE = TRS.get_double(data_list[i], "TI_CHANGE");  // RATIO SIEVE

					CQCMGRTSIV.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
					CQCMGRTSIV.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");

					memcpy(CQCMGRTSIV.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CQCMGRTSIV.CREATE_USER_ID, sizeof(CQCMGRTSIV.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cqcmgrtsiv(&CQCMGRTSIV);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
						TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
						TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
						TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);
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
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

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
				//UPDATE
				TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드

				CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

				CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     //빈체 
				CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); //찬체
				CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    //차이
				CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         // (%)

				CQCMGRTSIV.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");     // 2차 빈체 
				CQCMGRTSIV.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2"); // 2차 찬체
				CQCMGRTSIV.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");    // 2차 차이
				CQCMGRTSIV.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");         //  2차 (%)

				CQCMGRTSIV.AVG_SIEVE = TRS.get_double(data_list[i], "AVG_SIEVE");  //평균
				CQCMGRTSIV.TI_CHANGE = TRS.get_double(data_list[i], "TI_CHANGE");  // RATIO SIEVE

				CQCMGRTSIV.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
				CQCMGRTSIV.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");

				memcpy(CQCMGRTSIV.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTSIV.UPDATE_USER_ID, sizeof(CQCMGRTSIV.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmgrtsiv(1, &CQCMGRTSIV);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}

		}

	}
	else if (TRS.get_procstep(in_node) == '3')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMGRTSIV.INSP_ID, sizeof(CQCMGRTSIV.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMGRTSIV.INSP_DTL_TYPE, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //BTI
			CQCMGRTSIV.INSP_COUNT = TRS.get_int(in_node, "INSP_COUNT");
			CQCMGRTSIV.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");

			DBU_select_cqcmgrtsiv(1, &CQCMGRTSIV);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//INSERT
					TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드
																												//TRS.copy(CQCMGRTSIV.SIZES,)  //size 저장필요
					CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

					CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     // 1차 빈체 
					CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); // 1차 찬체
					CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    // 1차 차이
					CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         //  1차 (%)

					CQCMGRTSIV.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");     // 2차 빈체 
					CQCMGRTSIV.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2"); // 2차 찬체
					CQCMGRTSIV.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");    // 2차 차이
					CQCMGRTSIV.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");         //  2차 (%)

					CQCMGRTSIV.AVG_SIEVE = TRS.get_double(data_list[i], "AVG_SIEVE");  //평균
					CQCMGRTSIV.TI_CHANGE = TRS.get_double(data_list[i], "TI_CHANGE");  // RATIO SIEVE

					CQCMGRTSIV.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
					CQCMGRTSIV.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");

					memcpy(CQCMGRTSIV.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CQCMGRTSIV.CREATE_USER_ID, sizeof(CQCMGRTSIV.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cqcmgrtsiv(&CQCMGRTSIV);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
						TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
						TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
						TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);
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
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

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
				//UPDATE
				TRS.copy(CQCMGRTSIV.SIEVE_CODE, sizeof(CQCMGRTSIV.SIEVE_CODE), data_list[i], "SIEVE_CODE"); //체 코드

				CQCMGRTSIV.SIEVE_VALUE = TRS.get_double(data_list[i], "SIEVE_VALUE"); //체 값

				CQCMGRTSIV.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");     //빈체 
				CQCMGRTSIV.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1"); //찬체
				CQCMGRTSIV.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");    //차이
				CQCMGRTSIV.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");         // (%)

				CQCMGRTSIV.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");     // 2차 빈체 
				CQCMGRTSIV.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2"); // 2차 찬체
				CQCMGRTSIV.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");    // 2차 차이
				CQCMGRTSIV.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");         //  2차 (%)

				CQCMGRTSIV.AVG_SIEVE = TRS.get_double(data_list[i], "AVG_SIEVE");  //평균
				CQCMGRTSIV.TI_CHANGE = TRS.get_double(data_list[i], "TI_CHANGE");  // RATIO SIEVE

				CQCMGRTSIV.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
				CQCMGRTSIV.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");

				memcpy(CQCMGRTSIV.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTSIV.UPDATE_USER_ID, sizeof(CQCMGRTSIV.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmgrtsiv(1, &CQCMGRTSIV);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTSIV UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTSIV.INSP_DTL_TYPE), CQCMGRTSIV.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTSIV.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTSIV.INSP_SEQ);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}

		}

	}
	else if (TRS.get_procstep(in_node) == '4')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmgrthlt(&CQCMGRTHLT);
			TRS.copy(CQCMGRTHLT.FACTORY, sizeof(CQCMGRTHLT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMGRTHLT.INSP_ID, sizeof(CQCMGRTHLT.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMGRTHLT.INSP_DTL_TYPE, sizeof(CQCMGRTHLT.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //HLT
			CQCMGRTHLT.INSP_COUNT = TRS.get_int(in_node, "INSP_COUNT");
			CQCMGRTHLT.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");

			DBU_select_cqcmgrthlt(1, &CQCMGRTHLT);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//INSERT

					TRS.copy(CQCMGRTHLT.SIZES_1, sizeof(CQCMGRTHLT.SIZES_1), data_list[i], "SIZES_1");  //Size1
					CQCMGRTHLT.SIEVE_VALUE_1 = TRS.get_double(data_list[i], "SIEVE_VALUE_1");
					CQCMGRTHLT.SMASH_TIME_1 = TRS.get_double(data_list[i], "SMASH_TIME_1");
					CQCMGRTHLT.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
					CQCMGRTHLT.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");
					CQCMGRTHLT.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1");
					CQCMGRTHLT.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");
					CQCMGRTHLT.TOTAL_SIEVE_1 = TRS.get_double(data_list[i], "TOTAL_SIEVE_1");
					CQCMGRTHLT.AVG_SIEVE_1 = TRS.get_double(data_list[i], "AVG_SIEVE_1");
					CQCMGRTHLT.F_VALUE_1 = TRS.get_double(data_list[i], "F_VALUE_1");
					CQCMGRTHLT.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");

					CQCMGRTHLT.TI_RESULT = TRS.get_double(data_list[i], "TI_RESULT");

					if (TRS.get_char(in_node, "DOUBLE_SIZE_YN") == 'Y')
					{
						TRS.copy(CQCMGRTHLT.SIZES_2, sizeof(CQCMGRTHLT.SIZES_2), data_list[i], "SIZES_2");  //Size1
						CQCMGRTHLT.SIEVE_VALUE_2 = TRS.get_double(data_list[i], "SIEVE_VALUE_2");
						CQCMGRTHLT.SMASH_TIME_2 = TRS.get_double(data_list[i], "SMASH_TIME_2");
						CQCMGRTHLT.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");
						CQCMGRTHLT.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");
						CQCMGRTHLT.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2");
						CQCMGRTHLT.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");
						CQCMGRTHLT.TOTAL_SIEVE_2 = TRS.get_double(data_list[i], "TOTAL_SIEVE_2");
						CQCMGRTHLT.AVG_SIEVE_2 = TRS.get_double(data_list[i], "AVG_SIEVE_2");
						CQCMGRTHLT.F_VALUE_2 = TRS.get_double(data_list[i], "F_VALUE_2");
						CQCMGRTHLT.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");
					}

					memcpy(CQCMGRTHLT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CQCMGRTHLT.CREATE_USER_ID, sizeof(CQCMGRTHLT.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cqcmgrthlt(&CQCMGRTHLT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTHLT UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTHLT.INSP_ID), CQCMGRTHLT.INSP_ID);
						TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTHLT.INSP_DTL_TYPE), CQCMGRTHLT.INSP_DTL_TYPE);
						TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTHLT.INSP_COUNT);
						TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTHLT.INSP_SEQ);
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
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTHLT UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTHLT.INSP_ID), CQCMGRTHLT.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTHLT.INSP_DTL_TYPE), CQCMGRTHLT.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTHLT.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTHLT.INSP_SEQ);

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
				//UPDATE
				TRS.copy(CQCMGRTHLT.SIZES_1, sizeof(CQCMGRTHLT.SIZES_1), data_list[i], "SIZES_1");  //Size1
				CQCMGRTHLT.SIEVE_VALUE_1 = TRS.get_double(data_list[i], "SIEVE_VALUE_1");
				CQCMGRTHLT.SMASH_TIME_1 = TRS.get_double(data_list[i], "SMASH_TIME_1");
				CQCMGRTHLT.COUNT_1 = TRS.get_double(data_list[i], "COUNT_1");
				CQCMGRTHLT.NOT_SIEVE_1 = TRS.get_double(data_list[i], "NOT_SIEVE_1");
				CQCMGRTHLT.EXIST_SIEVE_1 = TRS.get_double(data_list[i], "EXIST_SIEVE_1");
				CQCMGRTHLT.DIFF_SIEVE_1 = TRS.get_double(data_list[i], "DIFF_SIEVE_1");
				CQCMGRTHLT.TOTAL_SIEVE_1 = TRS.get_double(data_list[i], "TOTAL_SIEVE_1");
				CQCMGRTHLT.AVG_SIEVE_1 = TRS.get_double(data_list[i], "AVG_SIEVE_1");
				CQCMGRTHLT.F_VALUE_1 = TRS.get_double(data_list[i], "F_VALUE_1");
				CQCMGRTHLT.TI_VALUE_1 = TRS.get_double(data_list[i], "TI_VALUE_1");

				CQCMGRTHLT.TI_RESULT = TRS.get_double(data_list[i], "TI_RESULT");

				if (TRS.get_char(in_node, "DOUBLE_SIZE_YN") == 'Y')
				{
					TRS.copy(CQCMGRTHLT.SIZES_2, sizeof(CQCMGRTHLT.SIZES_2), data_list[i], "SIZES_2");  //Size1
					CQCMGRTHLT.SIEVE_VALUE_2 = TRS.get_double(data_list[i], "SIEVE_VALUE_2");
					CQCMGRTHLT.SMASH_TIME_2 = TRS.get_double(data_list[i], "SMASH_TIME_2");
					CQCMGRTHLT.COUNT_2 = TRS.get_double(data_list[i], "COUNT_2");
					CQCMGRTHLT.NOT_SIEVE_2 = TRS.get_double(data_list[i], "NOT_SIEVE_2");
					CQCMGRTHLT.EXIST_SIEVE_2 = TRS.get_double(data_list[i], "EXIST_SIEVE_2");
					CQCMGRTHLT.DIFF_SIEVE_2 = TRS.get_double(data_list[i], "DIFF_SIEVE_2");
					CQCMGRTHLT.TOTAL_SIEVE_2 = TRS.get_double(data_list[i], "TOTAL_SIEVE_2");
					CQCMGRTHLT.AVG_SIEVE_2 = TRS.get_double(data_list[i], "AVG_SIEVE_2");
					CQCMGRTHLT.F_VALUE_2 = TRS.get_double(data_list[i], "F_VALUE_2");
					CQCMGRTHLT.TI_VALUE_2 = TRS.get_double(data_list[i], "TI_VALUE_2");
				}

				memcpy(CQCMGRTHLT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTHLT.UPDATE_USER_ID, sizeof(CQCMGRTHLT.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmgrthlt(1, &CQCMGRTHLT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTHLT UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTHLT.INSP_ID), CQCMGRTHLT.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTHLT.INSP_DTL_TYPE), CQCMGRTHLT.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTHLT.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTHLT.INSP_SEQ);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}

		}

	}
	else if (TRS.get_procstep(in_node) == '5')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_cqcmgrtcot(&CQCMGRTCOT);
		TRS.copy(CQCMGRTCOT.FACTORY, sizeof(CQCMGRTCOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMGRTCOT.INSP_ID, sizeof(CQCMGRTCOT.INSP_ID), in_node, "INSP_ID");
		memcpy(CQCMGRTCOT.INSP_DTL_TYPE, "COATING", strlen("COATING"));
		CQCMGRTCOT.INSP_COUNT = 1;
		DBU_select_cqcmgrtcot(1, &CQCMGRTCOT);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//INSERT
				
				CQCMGRTCOT.MA_VALUE_1 = TRS.get_double(in_node, "MA_VALUE_1");
				CQCMGRTCOT.MA_RESULT = TRS.get_double(in_node, "MA_RESULT");

				CQCMGRTCOT.WT_VALUE_1 = TRS.get_double(in_node, "WT_VALUE_1");
				CQCMGRTCOT.WT_VALUE_2 = TRS.get_double(in_node, "WT_VALUE_2");
				CQCMGRTCOT.WT_VALUE_3 = TRS.get_double(in_node, "WT_VALUE_3");
				CQCMGRTCOT.WT_RESULT = TRS.get_double(in_node, "WT_RESULT");

				CQCMGRTCOT.BD_VALUE_1 = TRS.get_double(in_node, "BD_VALUE_1");
				CQCMGRTCOT.BD_RESULT = TRS.get_double(in_node, "BD_RESULT");

				CQCMGRTCOT.TD_VALUE_1 = TRS.get_double(in_node, "TD_VALUE_1");
				CQCMGRTCOT.TD_RESULT = TRS.get_double(in_node, "TD_RESULT");

				CQCMGRTCOT.PCS_VALUE_1 = TRS.get_double(in_node, "PCS_VALUE_1");
				CQCMGRTCOT.PCS_RESULT = TRS.get_double(in_node, "PCS_RESULT");

				CQCMGRTCOT.PS_VALUE_1 = TRS.get_double(in_node, "PS_VALUE_1");
				CQCMGRTCOT.PS_VALUE_2 = TRS.get_double(in_node, "PS_VALUE_2");
				CQCMGRTCOT.PS_RESULT = TRS.get_double(in_node, "PS_RESULT");

				CQCMGRTCOT.CM_L = TRS.get_double(in_node, "CM_L");
				CQCMGRTCOT.CM_A = TRS.get_double(in_node, "CM_A");
				CQCMGRTCOT.CM_B = TRS.get_double(in_node, "CM_B");

				TRS.copy(CQCMGRTCOT.REMARKS, sizeof(CQCMGRTCOT.REMARKS), in_node, "REMARKS");

				CQCMGRTCOT.GRAIN_SIZE = TRS.get_double(in_node, "GRAIN_SIZE");
				CQCMGRTCOT.ELIP_VALUE = TRS.get_double(in_node, "ELIP_VALUE2");
				CQCMGRTCOT.ELIP_VALUE2 = TRS.get_double(in_node, "ELIP_VALUE2");
				CQCMGRTCOT.ROUG_VALUE = TRS.get_double(in_node, "ROUG_VALUE");
				CQCMGRTCOT.CIRCULRARITY = TRS.get_double(in_node, "CIRCULRARITY");
				CQCMGRTCOT.CONVEXITY = TRS.get_double(in_node, "CONVEXITY");
				CQCMGRTCOT.SHAPE_FACTOR = TRS.get_double(in_node, "SHAPE_FACTOR");
				CQCMGRTCOT.SURFACE_B = TRS.get_double(in_node, "SURFACE_B");
				CQCMGRTCOT.CON_O_VALUE = TRS.get_double(in_node, "CON_O_VALUE");

				memcpy(CQCMGRTCOT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTCOT.CREATE_USER_ID, sizeof(CQCMGRTCOT.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cqcmgrtcot(&CQCMGRTCOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTCOT UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTCOT.INSP_ID), CQCMGRTCOT.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTCOT.INSP_DTL_TYPE), CQCMGRTCOT.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTCOT.INSP_COUNT);
             

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}
		}
		else
		{
			//UPDATE
			CQCMGRTCOT.MA_VALUE_1 = TRS.get_double(in_node, "MA_VALUE_1");
			CQCMGRTCOT.MA_RESULT = TRS.get_double(in_node, "MA_RESULT");

			CQCMGRTCOT.WT_VALUE_1 = TRS.get_double(in_node, "WT_VALUE_1");
			CQCMGRTCOT.WT_VALUE_2 = TRS.get_double(in_node, "WT_VALUE_2");
			CQCMGRTCOT.WT_VALUE_3 = TRS.get_double(in_node, "WT_VALUE_3");
			CQCMGRTCOT.WT_RESULT = TRS.get_double(in_node, "WT_RESULT");

			CQCMGRTCOT.BD_VALUE_1 = TRS.get_double(in_node, "BD_VALUE_1");
			CQCMGRTCOT.BD_RESULT = TRS.get_double(in_node, "BD_RESULT");

			CQCMGRTCOT.TD_VALUE_1 = TRS.get_double(in_node, "TD_VALUE_1");
			CQCMGRTCOT.TD_RESULT = TRS.get_double(in_node, "TD_RESULT");

			CQCMGRTCOT.PCS_VALUE_1 = TRS.get_double(in_node, "PCS_VALUE_1");
			CQCMGRTCOT.PCS_RESULT = TRS.get_double(in_node, "PCS_RESULT");

			CQCMGRTCOT.PS_VALUE_1 = TRS.get_double(in_node, "PS_VALUE_1");
			CQCMGRTCOT.PS_VALUE_2 = TRS.get_double(in_node, "PS_VALUE_2");
			CQCMGRTCOT.PS_RESULT = TRS.get_double(in_node, "PS_RESULT");

			CQCMGRTCOT.CM_L = TRS.get_double(in_node, "CM_L");
			CQCMGRTCOT.CM_A = TRS.get_double(in_node, "CM_A");
			CQCMGRTCOT.CM_B = TRS.get_double(in_node, "CM_B");

			TRS.copy(CQCMGRTCOT.REMARKS, sizeof(CQCMGRTCOT.REMARKS), in_node, "REMARKS");

			CQCMGRTCOT.GRAIN_SIZE = TRS.get_double(in_node, "GRAIN_SIZE");
			CQCMGRTCOT.ELIP_VALUE = TRS.get_double(in_node, "ELIP_VALUE2");
			CQCMGRTCOT.ELIP_VALUE2 = TRS.get_double(in_node, "ELIP_VALUE2");
			CQCMGRTCOT.ROUG_VALUE = TRS.get_double(in_node, "ROUG_VALUE");
			CQCMGRTCOT.CIRCULRARITY = TRS.get_double(in_node, "CIRCULRARITY");
			CQCMGRTCOT.CONVEXITY = TRS.get_double(in_node, "CONVEXITY");
			CQCMGRTCOT.SHAPE_FACTOR = TRS.get_double(in_node, "SHAPE_FACTOR");
			CQCMGRTCOT.SURFACE_B = TRS.get_double(in_node, "SURFACE_B");
			CQCMGRTCOT.CON_O_VALUE = TRS.get_double(in_node, "CON_O_VALUE");

			memcpy(CQCMGRTCOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMGRTCOT.UPDATE_USER_ID, sizeof(CQCMGRTCOT.UPDATE_USER_ID), in_node, IN_USERID);

			DBU_update_cqcmgrtcot(1, &CQCMGRTCOT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMGRTCOT UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTCOT.INSP_ID), CQCMGRTCOT.INSP_ID);
				TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTCOT.INSP_DTL_TYPE), CQCMGRTCOT.INSP_DTL_TYPE);
				TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTCOT.INSP_COUNT);


				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

	}
	else if (TRS.get_procstep(in_node) == '6')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmgrtasp(&CQCMGRTASP);
			TRS.copy(CQCMGRTASP.FACTORY, sizeof(CQCMGRTASP.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMGRTASP.INSP_ID, sizeof(CQCMGRTASP.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMGRTASP.INSP_DTL_TYPE, sizeof(CQCMGRTASP.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //ASPECT
			CQCMGRTASP.INSP_COUNT = 1;
			CQCMGRTASP.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");

			DBU_select_cqcmgrtasp(1, &CQCMGRTASP);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//INSERT
					TRS.copy(CQCMGRTASP.QC_NAME, sizeof(CQCMGRTASP.QC_NAME), data_list[i], "QC_NAME"); //명칭
					TRS.copy(CQCMGRTASP.SPEC_VAL, sizeof(CQCMGRTASP.SPEC_VAL), data_list[i], "SPEC_VAL"); // spec 값

					CQCMGRTASP.VAL_1 = TRS.get_double(data_list[i], "VAL_1"); //MEAN
					CQCMGRTASP.VAL_2 = TRS.get_double(data_list[i], "VAL_2"); //D10
					CQCMGRTASP.VAL_3 = TRS.get_double(data_list[i], "VAL_3"); //D25
					CQCMGRTASP.VAL_4 = TRS.get_double(data_list[i], "VAL_4"); //D50
					CQCMGRTASP.VAL_5 = TRS.get_double(data_list[i], "VAL_5"); //D75
					CQCMGRTASP.VAL_6 = TRS.get_double(data_list[i], "VAL_6"); //D90
		            //CQCMGRTASP.VAL_7 (사용안함)

					memcpy(CQCMGRTASP.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CQCMGRTASP.CREATE_USER_ID, sizeof(CQCMGRTASP.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cqcmgrtasp(&CQCMGRTASP);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
						TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
						TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
						TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);
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
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);

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
				//UPDATE
				TRS.copy(CQCMGRTASP.QC_NAME, sizeof(CQCMGRTASP.QC_NAME), data_list[i], "QC_NAME"); //명칭
				TRS.copy(CQCMGRTASP.SPEC_VAL, sizeof(CQCMGRTASP.SPEC_VAL), data_list[i], "SPEC_VAL"); // spec 값

				CQCMGRTASP.VAL_1 = TRS.get_double(data_list[i], "VAL_1"); //MEAN
				CQCMGRTASP.VAL_2 = TRS.get_double(data_list[i], "VAL_2"); //D10
				CQCMGRTASP.VAL_3 = TRS.get_double(data_list[i], "VAL_3"); //D25
				CQCMGRTASP.VAL_4 = TRS.get_double(data_list[i], "VAL_4"); //D50
				CQCMGRTASP.VAL_5 = TRS.get_double(data_list[i], "VAL_5"); //D75
				CQCMGRTASP.VAL_6 = TRS.get_double(data_list[i], "VAL_6"); //D90
																		  //CQCMGRTASP.VAL_7 (사용안함)

				memcpy(CQCMGRTASP.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTASP.UPDATE_USER_ID, sizeof(CQCMGRTASP.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmgrtasp(1, &CQCMGRTASP);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}

		}

	}
	else if (TRS.get_procstep(in_node) == '7')
	{

	DBU_init_cqcmispsts(&CQCMISPSTS);
	TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
	DBU_select_cqcmispsts(1, &CQCMISPSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "QCM-0050");
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
		}
		TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	data_list = TRS.get_list(in_node, "DATA_LIST");
	i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

	for (int i = 0; i < i_data_count; i++)
	{

		DBU_init_cqcmgrtasp(&CQCMGRTASP);
		TRS.copy(CQCMGRTASP.FACTORY, sizeof(CQCMGRTASP.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMGRTASP.INSP_ID, sizeof(CQCMGRTASP.INSP_ID), in_node, "INSP_ID");
		TRS.copy(CQCMGRTASP.INSP_DTL_TYPE, sizeof(CQCMGRTASP.INSP_DTL_TYPE), in_node, "INSP_DTL_TYPE");  //ASPECT
		CQCMGRTASP.INSP_COUNT = 1;
		CQCMGRTASP.INSP_SEQ = TRS.get_int(data_list[i], "INSP_SEQ");

		DBU_select_cqcmgrtasp(1, &CQCMGRTASP);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//INSERT
				TRS.copy(CQCMGRTASP.QC_NAME, sizeof(CQCMGRTASP.QC_NAME), data_list[i], "QC_NAME"); //명칭
				TRS.copy(CQCMGRTASP.SPEC_VAL, sizeof(CQCMGRTASP.SPEC_VAL), data_list[i], "SPEC_VAL"); // spec 값

				CQCMGRTASP.VAL_1 = TRS.get_double(data_list[i], "VAL_1"); //MEAN
				CQCMGRTASP.VAL_2 = TRS.get_double(data_list[i], "VAL_2"); //D10
				CQCMGRTASP.VAL_3 = TRS.get_double(data_list[i], "VAL_3"); //D25
				CQCMGRTASP.VAL_4 = TRS.get_double(data_list[i], "VAL_4"); //D50
				CQCMGRTASP.VAL_5 = TRS.get_double(data_list[i], "VAL_5"); //D75
				CQCMGRTASP.VAL_6 = TRS.get_double(data_list[i], "VAL_6"); //D90
				//CQCMGRTASP.VAL_7 (사용안함)

				memcpy(CQCMGRTASP.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMGRTASP.CREATE_USER_ID, sizeof(CQCMGRTASP.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cqcmgrtasp(&CQCMGRTASP);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
					TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
					TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);
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
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
				TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
				TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
				TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);

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
			//UPDATE
			TRS.copy(CQCMGRTASP.QC_NAME, sizeof(CQCMGRTASP.QC_NAME), data_list[i], "QC_NAME"); //명칭
			TRS.copy(CQCMGRTASP.SPEC_VAL, sizeof(CQCMGRTASP.SPEC_VAL), data_list[i], "SPEC_VAL"); // spec 값

			CQCMGRTASP.VAL_1 = TRS.get_double(data_list[i], "VAL_1"); //MEAN
			CQCMGRTASP.VAL_2 = TRS.get_double(data_list[i], "VAL_2"); //D10
			CQCMGRTASP.VAL_3 = TRS.get_double(data_list[i], "VAL_3"); //D25
			CQCMGRTASP.VAL_4 = TRS.get_double(data_list[i], "VAL_4"); //D50
			CQCMGRTASP.VAL_5 = TRS.get_double(data_list[i], "VAL_5"); //D75
			CQCMGRTASP.VAL_6 = TRS.get_double(data_list[i], "VAL_6"); //D90
			//CQCMGRTASP.VAL_7 (사용안함)

			memcpy(CQCMGRTASP.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMGRTASP.UPDATE_USER_ID, sizeof(CQCMGRTASP.UPDATE_USER_ID), in_node, IN_USERID);

			DBU_update_cqcmgrtasp(1, &CQCMGRTASP);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMGRTASP UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
				TRS.add_fieldmsg(out_node, "INSP_DTL_TYPE", MP_STR, sizeof(CQCMGRTASP.INSP_DTL_TYPE), CQCMGRTASP.INSP_DTL_TYPE);
				TRS.add_fieldmsg(out_node, "INSP_COUNT", MP_INT, CQCMGRTASP.INSP_COUNT);
				TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMGRTASP.INSP_SEQ);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}

	}

	}



	if (TRS.get_procstep(in_node) != '7') //7번은 뺴고(7번은 일반 표준검사화면에서 넘어오는 ICP데이터임
	{
	// CQCMISPDAT 테이블로  일괄 업데이트.
	//GRIT 전용화면에서 저장되었던 GRIT제품검사 데이터들을(CQCMGRTSIV, CQCMGRTCOT, CQCMGRTHLT, CQCMGRTASP)   공통 검사데이터 테이블(CQCMISPDAT)로 옮겨주는 작업.

	//1. 기존 CQCMISPDAT존재시 삭제처리
	DBU_init_cqcmispdat(&CQCMISPDAT);
	TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
	if ((int)DBU_select_cqcmispdat_scalar(5, &CQCMISPDAT) > 0)
	{
		//삭제
		DBU_delete_cqcmispdat(2, &CQCMISPDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPDAT DELETE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	//(2) 최종 검사코드와 매칭되는 결과값만 CQCMISPDAT 테이블로 복사

	DBU_init_cqcmispdat(&CQCMISPDAT);
	TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
	TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
	DBU_open_cqcmispdat(4, &CQCMISPDAT);
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
		DBU_fetch_cqcmispdat(4, &CQCMISPDAT);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_cqcmispdat(4);
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

			DBU_close_cqcmispdat(4);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		memcpy(CQCMISPDAT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CQCMISPDAT.CREATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

		DBU_insert_cqcmispdat(&CQCMISPDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPDAT INSERT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

	}


	//GRIT의 경우 내부 검사차수를 저장시킴. ( 재가공 후 재검하는 것이 아닌, 내부적으로  재검 횟수 증가)
	//해당 검사차수는 BI, BTI, PSD,  HLT 에서  검사 차수를 늘린 숫자중 가장 높은 값으로 저장.
	DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
	TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMGRTSIV.INSP_ID, sizeof(CQCMGRTSIV.INSP_ID), in_node, "INSP_ID");
	i_max_insp_count = (int)DBU_select_cqcmgrtsiv_scalar(4, &CQCMGRTSIV);

	if (i_max_insp_count == 0)
	{
		i_max_insp_count = 1;
	}

	

	//i_max_insp_count

	// 검사요청정보 Update
	DBU_init_cqcmispsts(&CQCMISPSTS);
	TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
	DBU_select_cqcmispsts(1, &CQCMISPSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "QCM-0004");
		TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	COM_itoa_left(CQCMISPSTS.CMF_6, i_max_insp_count, sizeof(CQCMISPSTS.CMF_6));
	TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
	CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VER");
	TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(CQCMISPSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
	DBU_update_cqcmispsts(1, &CQCMISPSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "QCM-0004");
		TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	// EDC 데이터 저장 ( SPC )
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

	}


    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Collect_Inspection_Data_Grit_Validation()
- Validation Check sub function of "CUS_QCM_COLLECT_INSPECTION_DATA_GRIT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Inspection_Data_Grit_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1234567") == MP_FALSE)
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
