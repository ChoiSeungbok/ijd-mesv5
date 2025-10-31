/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Save_Report.c
Description : Tran Create Inspection Request function

MES Version : 5.0

Function List
-

Detail Description
- 성적서 레포트의 데이터를 저장하는 서비스

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/01  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"
#include "CUS_common.h"

int CUS_QCM_Save_Report_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);


/*******************************************************************************
CUS_QCM_Save_Report()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Save_Report(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_SAVE_REPORT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_Save_Report", out_node);
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
CUS_QCM_SAVE_REPORT()
- Main sub function of "CUS_QCM_Save_Report" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_SAVE_REPORT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	struct CQCMRPTCTM_TAG CQCMRPTCTM;
	struct CQCMRPTHMM_TAG CQCMRPTHMM;

	struct CQCMRPTGRN_TAG CQCMRPTGRN;
	struct CQCMRPTGNY_TAG CQCMRPTGNY;
	struct CQCMRPTGNP_TAG CQCMRPTGNP;

	struct CQCMRPTGRM_TAG CQCMRPTGRM;
	struct CQCMRPTGMP_TAG CQCMRPTGMP;

	//CQCMRPTGRN
	//CQCMRPTGNY
	//CQCMRPTGNP

	char s_sys_time[14];
	char s_area_id[21];
	char s_report_no[21];

	//TRSNode *collect_in_node;
	//TRSNode **data_list;

	TRSNode** data_list;
	TRSNode** pivot_list;
	TRSNode** aspect_list;

	int i_data_count;

	//unsigned char *s_query = 0x00;
	//long l_size;


	LOG_head("CUS_QCM_Save_Report");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_area_id, ' ', sizeof(s_area_id));
	memset(s_report_no, ' ', sizeof(s_report_no));

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
	if (CUS_QCM_Save_Report_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	//ProcStep 1  CTM 성적서 데이터 저장

	if (TRS.get_procstep(in_node) == '1')
	{

		DBU_init_cqcmrptctm(&CQCMRPTCTM);
		TRS.copy(CQCMRPTCTM.FACTORY, sizeof(CQCMRPTCTM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMRPTCTM.REPORT_NO, sizeof(CQCMRPTCTM.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptctm_scalar(2, &CQCMRPTCTM) > 0)
		{
			DBU_delete_cqcmrptctm(2, &CQCMRPTCTM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTCTM DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmrptctm(&CQCMRPTCTM);
			TRS.copy(CQCMRPTCTM.FACTORY, sizeof(CQCMRPTCTM.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMRPTCTM.REPORT_NO, sizeof(CQCMRPTCTM.REPORT_NO), in_node, "REPORT_NO");
			TRS.copy(CQCMRPTCTM.PACK_LOT_ID, sizeof(CQCMRPTCTM.PACK_LOT_ID), data_list[i], "PACK_LOT_ID");
			TRS.copy(CQCMRPTCTM.ORG_LOT_ID, sizeof(CQCMRPTCTM.ORG_LOT_ID), data_list[i], "ORG_LOT_ID");
			TRS.copy(CQCMRPTCTM.GRADE, sizeof(CQCMRPTCTM.GRADE), data_list[i], "GRADE");
			TRS.copy(CQCMRPTCTM.TYPES, sizeof(CQCMRPTCTM.TYPES), data_list[i], "TYPES");
			TRS.copy(CQCMRPTCTM.PACK_ORDER_ID, sizeof(CQCMRPTCTM.PACK_ORDER_ID), data_list[i], "PACK_ORDER_ID");
			TRS.copy(CQCMRPTCTM.CUSTOMER_ID, sizeof(CQCMRPTCTM.CUSTOMER_ID), data_list[i], "CUSTOMER_ID");

			TRS.copy(CQCMRPTCTM.OD_STANDARD, sizeof(CQCMRPTCTM.OD_STANDARD), data_list[i], "OD_STANDARD");
			TRS.copy(CQCMRPTCTM.OD_SPEC, sizeof(CQCMRPTCTM.OD_SPEC), data_list[i], "OD_SPEC");
			TRS.copy(CQCMRPTCTM.OD_MIN_VAL, sizeof(CQCMRPTCTM.OD_MIN_VAL), data_list[i], "OD_MIN_VAL");
			TRS.copy(CQCMRPTCTM.OD_MAX_VAL, sizeof(CQCMRPTCTM.OD_MAX_VAL), data_list[i], "OD_MAX_VAL");

			TRS.copy(CQCMRPTCTM.AT_STANDARD, sizeof(CQCMRPTCTM.AT_STANDARD), data_list[i], "AT_STANDARD");
			TRS.copy(CQCMRPTCTM.AT_SPEC, sizeof(CQCMRPTCTM.AT_SPEC), data_list[i], "AT_SPEC");
			TRS.copy(CQCMRPTCTM.AT_MIN_VAL, sizeof(CQCMRPTCTM.AT_MIN_VAL), data_list[i], "AT_MIN_VAL");
			TRS.copy(CQCMRPTCTM.AT_MAX_VAL, sizeof(CQCMRPTCTM.AT_MAX_VAL), data_list[i], "AT_MAX_VAL");


			TRS.copy(CQCMRPTCTM.GT_STANDARD, sizeof(CQCMRPTCTM.GT_STANDARD), data_list[i], "GT_STANDARD");
			TRS.copy(CQCMRPTCTM.GT_SPEC, sizeof(CQCMRPTCTM.GT_SPEC), data_list[i], "GT_SPEC");
			TRS.copy(CQCMRPTCTM.GT_MIN_VAL, sizeof(CQCMRPTCTM.GT_MIN_VAL), data_list[i], "GT_MIN_VAL");
			TRS.copy(CQCMRPTCTM.GT_MAX_VAL, sizeof(CQCMRPTCTM.GT_MAX_VAL), data_list[i], "GT_MAX_VAL");

			TRS.copy(CQCMRPTCTM.LEN01_STANDARD, sizeof(CQCMRPTCTM.LEN01_STANDARD), data_list[i], "LEN01_STANDARD");
			TRS.copy(CQCMRPTCTM.LEN01_SPEC, sizeof(CQCMRPTCTM.LEN01_SPEC), data_list[i], "LEN01_SPEC");
			TRS.copy(CQCMRPTCTM.LEN_MIN_VAL01, sizeof(CQCMRPTCTM.LEN_MIN_VAL01), data_list[i], "LEN_MIN_VAL01");
			TRS.copy(CQCMRPTCTM.LEN_MAX_VAL01, sizeof(CQCMRPTCTM.LEN_MAX_VAL01), data_list[i], "LEN_MAX_VAL01");

			TRS.copy(CQCMRPTCTM.LEN02_STANDARD, sizeof(CQCMRPTCTM.LEN02_STANDARD), data_list[i], "LEN02_STANDARD");
			TRS.copy(CQCMRPTCTM.LEN02_SPEC, sizeof(CQCMRPTCTM.LEN02_SPEC), data_list[i], "LEN02_SPEC");
			TRS.copy(CQCMRPTCTM.LEN_MIN_VAL02, sizeof(CQCMRPTCTM.LEN_MIN_VAL02), data_list[i], "LEN_MIN_VAL02");
			TRS.copy(CQCMRPTCTM.LEN_MAX_VAL02, sizeof(CQCMRPTCTM.LEN_MAX_VAL02), data_list[i], "LEN_MAX_VAL02");

			TRS.copy(CQCMRPTCTM.DMG_STANDARD, sizeof(CQCMRPTCTM.DMG_STANDARD), data_list[i], "DMG_STANDARD");
			TRS.copy(CQCMRPTCTM.DMG_SPEC, sizeof(CQCMRPTCTM.DMG_SPEC), data_list[i], "DMG_SPEC");
			TRS.copy(CQCMRPTCTM.DMG_MIN_VAL, sizeof(CQCMRPTCTM.DMG_MIN_VAL), data_list[i], "DMG_MIN_VAL");
			TRS.copy(CQCMRPTCTM.DMG_MAX_VAL, sizeof(CQCMRPTCTM.DMG_MAX_VAL), data_list[i], "DMG_MAX_VAL");





			TRS.copy(CQCMRPTCTM.COMMENTS, sizeof(CQCMRPTCTM.COMMENTS), data_list[i], "COMMENTS");

			TRS.copy(CQCMRPTCTM.CREATE_USER_ID, sizeof(CQCMRPTCTM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTCTM.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_insert_cqcmrptctm(&CQCMRPTCTM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTCTM INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_cqcmrpthmm(&CQCMRPTHMM);
		TRS.copy(CQCMRPTHMM.FACTORY, sizeof(CQCMRPTHMM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMRPTHMM.REPORT_NO, sizeof(CQCMRPTHMM.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrpthmm_scalar(2, &CQCMRPTHMM) > 0)
		{
			DBU_delete_cqcmrpthmm(2, &CQCMRPTHMM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTHMM DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmrpthmm(&CQCMRPTHMM);
			TRS.copy(CQCMRPTHMM.FACTORY, sizeof(CQCMRPTHMM.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMRPTHMM.REPORT_NO, sizeof(CQCMRPTHMM.REPORT_NO), in_node, "REPORT_NO");
			TRS.copy(CQCMRPTHMM.PACK_LOT_ID, sizeof(CQCMRPTHMM.PACK_LOT_ID), data_list[i], "PACK_LOT_ID");
			TRS.copy(CQCMRPTHMM.ORG_LOT_ID, sizeof(CQCMRPTHMM.ORG_LOT_ID), data_list[i], "ORG_LOT_ID");
			TRS.copy(CQCMRPTHMM.GRADE, sizeof(CQCMRPTHMM.GRADE), data_list[i], "GRADE");
			TRS.copy(CQCMRPTHMM.TYPES, sizeof(CQCMRPTHMM.TYPES), data_list[i], "TYPES");
			TRS.copy(CQCMRPTHMM.PACK_ORDER_ID, sizeof(CQCMRPTHMM.PACK_ORDER_ID), data_list[i], "PACK_ORDER_ID");
			TRS.copy(CQCMRPTHMM.CUSTOMER_ID, sizeof(CQCMRPTHMM.CUSTOMER_ID), data_list[i], "CUSTOMER_ID");

			CQCMRPTHMM.LOT_QTY = TRS.get_double(data_list[i], "LOT_QTY");

			TRS.copy(CQCMRPTHMM.OD_METER, sizeof(CQCMRPTHMM.OD_METER), data_list[i], "OD_METER");
			TRS.copy(CQCMRPTHMM.ID_METER, sizeof(CQCMRPTHMM.ID_METER), data_list[i], "ID_METER");
			TRS.copy(CQCMRPTHMM.HEIGHT, sizeof(CQCMRPTHMM.HEIGHT), data_list[i], "HEIGHT");
			TRS.copy(CQCMRPTHMM.LENGTH, sizeof(CQCMRPTHMM.LENGTH), data_list[i], "LENGTH");

			TRS.copy(CQCMRPTHMM.DENSITY, sizeof(CQCMRPTHMM.DENSITY), data_list[i], "DENSITY");
			TRS.copy(CQCMRPTHMM.MAG_SAT, sizeof(CQCMRPTHMM.MAG_SAT), data_list[i], "MAG_SAT");
			TRS.copy(CQCMRPTHMM.COER_FORCE, sizeof(CQCMRPTHMM.COER_FORCE), data_list[i], "COER_FORCE");
			TRS.copy(CQCMRPTHMM.HARDNESS_HV20, sizeof(CQCMRPTHMM.HARDNESS_HV20), data_list[i], "HARDNESS_HV20");
			TRS.copy(CQCMRPTHMM.TRS, sizeof(CQCMRPTHMM.TRS), data_list[i], "TRS");

			TRS.copy(CQCMRPTHMM.COMMENTS, sizeof(CQCMRPTHMM.COMMENTS), data_list[i], "COMMENTS");
			TRS.copy(CQCMRPTHMM.ATTRIBUTE01, sizeof(CQCMRPTHMM.ATTRIBUTE01), data_list[i], "REMARK");

			TRS.copy(CQCMRPTHMM.ATTRIBUTE02, sizeof(CQCMRPTHMM.ATTRIBUTE02), in_node, "ATTRIBUTE02");  // 2025-10-23(BOK) ATTRIBUTE02 추가

			TRS.copy(CQCMRPTHMM.IMAGE_NUM1, sizeof(CQCMRPTHMM.IMAGE_NUM1), data_list[i], "IMAGE_NUM1");
			TRS.copy(CQCMRPTHMM.IMAGE_NUM2, sizeof(CQCMRPTHMM.IMAGE_NUM2), data_list[i], "IMAGE_NUM2");

			TRS.copy(CQCMRPTHMM.CREATE_USER_ID, sizeof(CQCMRPTHMM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTHMM.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			
			TRS.copy(CQCMRPTHMM.GRAIN_SIZE, sizeof(CQCMRPTHMM.COMMENTS), data_list[i], "GRAIN_SIZE");
			TRS.copy(CQCMRPTHMM.DENSITY_SPEC, sizeof(CQCMRPTHMM.DENSITY_SPEC), data_list[i], "DENSITY_SPEC");
			TRS.copy(CQCMRPTHMM.MAG_SAT_SPEC, sizeof(CQCMRPTHMM.MAG_SAT_SPEC), data_list[i], "MAG_SAT_SPEC");
			TRS.copy(CQCMRPTHMM.COER_FORCE_SPEC, sizeof(CQCMRPTHMM.COER_FORCE_SPEC), data_list[i], "COER_FORCE_SPEC");
			TRS.copy(CQCMRPTHMM.HARDNESS_HV20_SPEC, sizeof(CQCMRPTHMM.HARDNESS_HV20_SPEC), data_list[i], "HARDNESS_HV20_SPEC");
			TRS.copy(CQCMRPTHMM.TRS_SPEC, sizeof(CQCMRPTHMM.TRS_SPEC), data_list[i], "TRS_SPEC");
			TRS.copy(CQCMRPTHMM.GRAIN_SIZE_SPEC, sizeof(CQCMRPTHMM.GRAIN_SIZE_SPEC), data_list[i], "GRAIN_SIZE_SPEC");
			


			DBU_insert_cqcmrpthmm(&CQCMRPTHMM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTHMM INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		//CQCMRPTGRN
		//CQCMRPTGNY
		//CQCMRPTGNP

		DBU_init_cqcmrptgrn(&CQCMRPTGRN);
		TRS.copy(CQCMRPTGRN.REPORT_NO, sizeof(CQCMRPTGRN.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptgrn_scalar(2, &CQCMRPTGRN) > 0)
		{
			DBU_delete_cqcmrptgrn(2, &CQCMRPTGRN);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGRN DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}

		DBU_init_cqcmrptgny(&CQCMRPTGNY);
		TRS.copy(CQCMRPTGNY.REPORT_NO, sizeof(CQCMRPTGNY.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptgny_scalar(2, &CQCMRPTGNY) > 0)
		{
			DBU_delete_cqcmrptgny(2, &CQCMRPTGNY);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGNY DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}

		DBU_init_cqcmrptgnp(&CQCMRPTGNP);
		TRS.copy(CQCMRPTGNP.REPORT_NO, sizeof(CQCMRPTGNP.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptgnp_scalar(2, &CQCMRPTGNP) > 0)
		{
			DBU_delete_cqcmrptgnp(2, &CQCMRPTGNP);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGNP DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}




		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmrptgrn(&CQCMRPTGRN);
			TRS.copy(CQCMRPTGRN.FACTORY, sizeof(CQCMRPTGRN.FACTORY), in_node, "FACTORY");
			TRS.copy(CQCMRPTGRN.REPORT_NO, sizeof(CQCMRPTGRN.REPORT_NO), in_node, "REPORT_NO");
			TRS.copy(CQCMRPTGRN.HEADER_ID, sizeof(CQCMRPTGRN.HEADER_ID), data_list[i], "HEADER_ID");
			TRS.copy(CQCMRPTGRN.LINE_NUMBER, sizeof(CQCMRPTGRN.LINE_NUMBER), data_list[i], "LINE_NUMBER");
			TRS.copy(CQCMRPTGRN.LOT_ID, sizeof(CQCMRPTGRN.LOT_ID), data_list[i], "PACK_LOT_ID");

			TRS.copy(CQCMRPTGRN.GRADE, sizeof(CQCMRPTGRN.GRADE), data_list[i], "GRADE");
			TRS.copy(CQCMRPTGRN.SIZES, sizeof(CQCMRPTGRN.SIZES), data_list[i], "SIZES");

			TRS.copy(CQCMRPTGRN.CUST_NO, sizeof(CQCMRPTGRN.CUST_NO), data_list[i], "CUST_NO");
			TRS.copy(CQCMRPTGRN.REMARKS, sizeof(CQCMRPTGRN.REMARKS), data_list[i], "REMARKS");

			TRS.copy(CQCMRPTGRN.TI_SPEC, sizeof(CQCMRPTGRN.TI_SPEC), data_list[i], "TI_SPEC");
			TRS.copy(CQCMRPTGRN.TTI_SPEC, sizeof(CQCMRPTGRN.TTI_SPEC), data_list[i], "TTI_SPEC");
			TRS.copy(CQCMRPTGRN.WT_SPEC, sizeof(CQCMRPTGRN.WT_SPEC), data_list[i], "WT_SPEC");
			TRS.copy(CQCMRPTGRN.BD_SPEC, sizeof(CQCMRPTGRN.BD_SPEC), data_list[i], "BD_SPEC");
			TRS.copy(CQCMRPTGRN.PSD_TS_SPEC, sizeof(CQCMRPTGRN.PSD_TS_SPEC), data_list[i], "PSD_TS_SPEC");
			TRS.copy(CQCMRPTGRN.PSD_US_SPEC, sizeof(CQCMRPTGRN.PSD_US_SPEC), data_list[i], "PSD_US_SPEC");
			TRS.copy(CQCMRPTGRN.PSD_OS_SPEC, sizeof(CQCMRPTGRN.PSD_OS_SPEC), data_list[i], "PSD_OS_SPEC");
			TRS.copy(CQCMRPTGRN.ATTRIBUTE02, sizeof(CQCMRPTGRN.ATTRIBUTE01), data_list[i], "PSD_SS_SPEC");
			TRS.copy(CQCMRPTGRN.PSD_LS_SPEC, sizeof(CQCMRPTGRN.PSD_LS_SPEC), data_list[i], "PSD_LS_SPEC");
			TRS.copy(CQCMRPTGRN.PSD_FS_SPEC, sizeof(CQCMRPTGRN.PSD_FS_SPEC), data_list[i], "PSD_FS_SPEC");
			TRS.copy(CQCMRPTGRN.HLT_TI_SPEC, sizeof(CQCMRPTGRN.HLT_TI_SPEC), data_list[i], "HLT_TI_SPEC");

			TRS.copy(CQCMRPTGRN.TI_VAL, sizeof(CQCMRPTGRN.TI_VAL), data_list[i], "TI_VAL");
			TRS.copy(CQCMRPTGRN.TTI_VAL, sizeof(CQCMRPTGRN.TTI_VAL), data_list[i], "TTI_VAL");
			TRS.copy(CQCMRPTGRN.WT_VAL, sizeof(CQCMRPTGRN.WT_VAL), data_list[i], "WT_VAL");
			TRS.copy(CQCMRPTGRN.BD_VAL, sizeof(CQCMRPTGRN.BD_VAL), data_list[i], "BD_VAL");
			TRS.copy(CQCMRPTGRN.PSD_TS_VAL, sizeof(CQCMRPTGRN.PSD_TS_VAL), data_list[i], "PSD_TS_VAL");
			TRS.copy(CQCMRPTGRN.PSD_US_VAL, sizeof(CQCMRPTGRN.PSD_US_VAL), data_list[i], "PSD_US_VAL");
			TRS.copy(CQCMRPTGRN.PSD_OS_VAL, sizeof(CQCMRPTGRN.PSD_OS_VAL), data_list[i], "PSD_OS_VAL");
			TRS.copy(CQCMRPTGRN.ATTRIBUTE02, sizeof(CQCMRPTGRN.ATTRIBUTE02), data_list[i], "PSD_OS_VAL");
			TRS.copy(CQCMRPTGRN.PSD_LS_VAL, sizeof(CQCMRPTGRN.PSD_LS_VAL), data_list[i], "PSD_LS_VAL");
			TRS.copy(CQCMRPTGRN.PSD_FS_VAL, sizeof(CQCMRPTGRN.PSD_FS_VAL), data_list[i], "PSD_FS_VAL");
			TRS.copy(CQCMRPTGRN.HLT_TI_VAL, sizeof(CQCMRPTGRN.HLT_TI_VAL), data_list[i], "HLT_TI_VAL");
			TRS.copy(CQCMRPTGRN.CM_L_VAL, sizeof(CQCMRPTGRN.CM_L_VAL), data_list[i], "CM_L_VAL");
			TRS.copy(CQCMRPTGRN.CM_A_VAL, sizeof(CQCMRPTGRN.CM_A_VAL), data_list[i], "CM_A_VAL");
			TRS.copy(CQCMRPTGRN.CM_B_VAL, sizeof(CQCMRPTGRN.CM_B_VAL), data_list[i], "CM_B_VAL");
			TRS.copy(CQCMRPTGRN.SURFACE_B_VAL, sizeof(CQCMRPTGRN.SURFACE_B_VAL), data_list[i], "SURFACE_B_VAL");

			TRS.copy(CQCMRPTGRN.IMAGE_NUM, sizeof(CQCMRPTGRN.IMAGE_NUM), data_list[i], "IMAGE_NUM");
			TRS.copy(CQCMRPTGRN.IMAGE_NUM2, sizeof(CQCMRPTGRN.IMAGE_NUM2), data_list[i], "IMAGE_NUM2");
			TRS.copy(CQCMRPTGRN.IMAGE_NUM3, sizeof(CQCMRPTGRN.IMAGE_NUM3), data_list[i], "IMAGE_NUM3");

			TRS.copy(CQCMRPTGRN.CREATE_USER_ID, sizeof(CQCMRPTGRN.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTGRN.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_insert_cqcmrptgrn(&CQCMRPTGRN);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTHMM INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		pivot_list = TRS.get_list(in_node, "PIVOT_LIST");
		i_data_count = TRS.get_item_count(in_node, "PIVOT_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmrptgnp(&CQCMRPTGNP);
			TRS.copy(CQCMRPTGNP.FACTORY, sizeof(CQCMRPTGNP.FACTORY), in_node, "FACTORY");
			TRS.copy(CQCMRPTGNP.REPORT_NO, sizeof(CQCMRPTGNP.REPORT_NO), in_node, "REPORT_NO");

			CQCMRPTGNP.SORT_NO = TRS.get_int(pivot_list[i], "SORT_NO");
			TRS.copy(CQCMRPTGNP.QC_NAME, sizeof(CQCMRPTGNP.QC_NAME), pivot_list[i], "QC_NAME");
			TRS.copy(CQCMRPTGNP.SPEC_VAL, sizeof(CQCMRPTGNP.SPEC_VAL), pivot_list[i], "SPEC_VAL");

			TRS.copy(CQCMRPTGNP.REMARKS, sizeof(CQCMRPTGNP.REMARKS), pivot_list[i], "REMARKS");
			TRS.copy(CQCMRPTGNP.CUST_NO, sizeof(CQCMRPTGNP.CUST_NO), pivot_list[i], "CUST_NO");

			TRS.copy(CQCMRPTGNP.LOT_01, sizeof(CQCMRPTGNP.LOT_01), pivot_list[i], "LOT_01");
			TRS.copy(CQCMRPTGNP.LOT_02, sizeof(CQCMRPTGNP.LOT_02), pivot_list[i], "LOT_02");
			TRS.copy(CQCMRPTGNP.LOT_03, sizeof(CQCMRPTGNP.LOT_03), pivot_list[i], "LOT_03");
			TRS.copy(CQCMRPTGNP.LOT_04, sizeof(CQCMRPTGNP.LOT_04), pivot_list[i], "LOT_04");
			TRS.copy(CQCMRPTGNP.LOT_05, sizeof(CQCMRPTGNP.LOT_05), pivot_list[i], "LOT_05");
			TRS.copy(CQCMRPTGNP.LOT_06, sizeof(CQCMRPTGNP.LOT_06), pivot_list[i], "LOT_06");
			TRS.copy(CQCMRPTGNP.LOT_07, sizeof(CQCMRPTGNP.LOT_07), pivot_list[i], "LOT_07");

			TRS.copy(CQCMRPTGNP.IMAGE_NUM, sizeof(CQCMRPTGNP.IMAGE_NUM), pivot_list[i], "IMAGE_NUM");
			TRS.copy(CQCMRPTGNP.IMAGE_NUM2, sizeof(CQCMRPTGNP.IMAGE_NUM2), pivot_list[i], "IMAGE_NUM2");
			TRS.copy(CQCMRPTGNP.IMAGE_NUM3, sizeof(CQCMRPTGNP.IMAGE_NUM3), pivot_list[i], "IMAGE_NUM3");

			//TRS.copy(CQCMRPTGNP.USE_YN, sizeof(CQCMRPTGNP.USE_YN), pivot_list[i], "USE_YN");
			CQCMRPTGNP.USE_YN = TRS.get_char(pivot_list[i], "USE_YN");

			TRS.copy(CQCMRPTGNP.CREATE_USER_ID, sizeof(CQCMRPTGNP.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTGNP.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_insert_cqcmrptgnp(&CQCMRPTGNP);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGNP INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}




		aspect_list = TRS.get_list(in_node, "ASPECT_LIST");
		i_data_count = TRS.get_item_count(in_node, "ASPECT_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmrptgny(&CQCMRPTGNY);
			TRS.copy(CQCMRPTGNY.FACTORY, sizeof(CQCMRPTGNY.FACTORY), in_node, "FACTORY");
			TRS.copy(CQCMRPTGNY.REPORT_NO, sizeof(CQCMRPTGNY.REPORT_NO), in_node, "REPORT_NO");

			CQCMRPTGNY.SORT_NO = TRS.get_int(aspect_list[i], "SORT_NO");
			TRS.copy(CQCMRPTGNY.QC_NAME, sizeof(CQCMRPTGNY.QC_NAME), aspect_list[i], "QC_NAME");
			TRS.copy(CQCMRPTGNY.SPEC_VAL, sizeof(CQCMRPTGNY.SPEC_VAL), aspect_list[i], "SPEC_VAL");

			TRS.copy(CQCMRPTGNY.VAL_01, sizeof(CQCMRPTGNY.VAL_01), aspect_list[i], "VAL_01");
			TRS.copy(CQCMRPTGNY.VAL_02, sizeof(CQCMRPTGNY.VAL_02), aspect_list[i], "VAL_02");
			TRS.copy(CQCMRPTGNY.VAL_03, sizeof(CQCMRPTGNY.VAL_03), aspect_list[i], "VAL_03");
			TRS.copy(CQCMRPTGNY.VAL_04, sizeof(CQCMRPTGNY.VAL_04), aspect_list[i], "VAL_04");
			TRS.copy(CQCMRPTGNY.VAL_05, sizeof(CQCMRPTGNY.VAL_05), aspect_list[i], "VAL_05");
			TRS.copy(CQCMRPTGNY.VAL_06, sizeof(CQCMRPTGNY.VAL_06), aspect_list[i], "VAL_06");

			TRS.copy(CQCMRPTGNY.CREATE_USER_ID, sizeof(CQCMRPTGNY.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTGNY.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_insert_cqcmrptgny(&CQCMRPTGNY);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGNY INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}



	}
	else if (TRS.get_procstep(in_node) == '4')
	{
		//CQCMRPTGRM
		//CQCMRPTGMP


		DBU_init_cqcmrptgrm(&CQCMRPTGRM);
		TRS.copy(CQCMRPTGRM.FACTORY, sizeof(CQCMRPTGRM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMRPTGRM.REPORT_NO, sizeof(CQCMRPTGRM.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptgrm_scalar(2, &CQCMRPTGRM) > 0)
		{
			DBU_delete_cqcmrptgrm(2, &CQCMRPTGRM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGRM DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}

		DBU_init_cqcmrptgmp(&CQCMRPTGMP);
		TRS.copy(CQCMRPTGMP.FACTORY, sizeof(CQCMRPTGMP.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMRPTGMP.REPORT_NO, sizeof(CQCMRPTGMP.REPORT_NO), in_node, "REPORT_NO");
		if ((int)DBU_select_cqcmrptgmp_scalar(3, &CQCMRPTGMP) > 0)
		{
			DBU_delete_cqcmrptgmp(2, &CQCMRPTGMP);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGMP DELETE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}




		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmrptgrm(&CQCMRPTGRM);
			TRS.copy(CQCMRPTGRM.FACTORY, sizeof(CQCMRPTGRM.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMRPTGRM.REPORT_NO, sizeof(CQCMRPTGRM.REPORT_NO), in_node, "REPORT_NO");
			TRS.copy(CQCMRPTGRM.HEADER_ID, sizeof(CQCMRPTGRM.HEADER_ID), data_list[i], "HEADER_ID");
			CQCMRPTGRM.LINE_NUMBER = TRS.get_int(data_list[i], "LINE_NUMBER");
			TRS.copy(CQCMRPTGRM.LOT_ID, sizeof(CQCMRPTGRM.LOT_ID), data_list[i], "PACK_LOT_ID");
			TRS.copy(CQCMRPTGRM.ITEM_CODE, sizeof(CQCMRPTGRM.ITEM_CODE), data_list[i], "ITEM_CODE");
			TRS.copy(CQCMRPTGRM.GRADE, sizeof(CQCMRPTGRM.GRADE), data_list[i], "GRADE");
			TRS.copy(CQCMRPTGRM.SIZES, sizeof(CQCMRPTGRM.SIZES), data_list[i], "SIZES");

			memcpy(CQCMRPTGRM.REPORT_DATE, s_sys_time, 8);
			TRS.copy(CQCMRPTGRM.INSP_VALUE, sizeof(CQCMRPTGRM.INSP_VALUE), data_list[i], "INSP_VALUE");
			TRS.copy(CQCMRPTGRM.SHIP_NAME, sizeof(CQCMRPTGRM.SHIP_NAME), data_list[i], "SHIP_NAME");

			TRS.copy(CQCMRPTGRM.WT, sizeof(CQCMRPTGRM.WT), data_list[i], "WT");
			TRS.copy(CQCMRPTGRM.MEAN, sizeof(CQCMRPTGRM.MEAN), data_list[i], "MEAN");
			TRS.copy(CQCMRPTGRM.SD, sizeof(CQCMRPTGRM.SD), data_list[i], "SD");
			TRS.copy(CQCMRPTGRM.LP, sizeof(CQCMRPTGRM.LP), data_list[i], "LP");
			TRS.copy(CQCMRPTGRM.ELEC_CONDUCTIVITY, sizeof(CQCMRPTGRM.ELEC_CONDUCTIVITY), data_list[i], "ELEC_CONDUCTIVITY");
			TRS.copy(CQCMRPTGRM.VOL_STATIC01, sizeof(CQCMRPTGRM.VOL_STATIC01), data_list[i], "VOL_STATIC01");
			TRS.copy(CQCMRPTGRM.VOL_STATIC02, sizeof(CQCMRPTGRM.VOL_STATIC02), data_list[i], "VOL_STATIC02");
			TRS.copy(CQCMRPTGRM.VOL_STATIC03, sizeof(CQCMRPTGRM.VOL_STATIC03), data_list[i], "VOL_STATIC03");
			TRS.copy(CQCMRPTGRM.VOL_STATIC04, sizeof(CQCMRPTGRM.VOL_STATIC04), data_list[i], "VOL_STATIC04");
			TRS.copy(CQCMRPTGRM.VOL_STATIC05, sizeof(CQCMRPTGRM.VOL_STATIC05), data_list[i], "VOL_STATIC05");
			TRS.copy(CQCMRPTGRM.VOL_STATIC06, sizeof(CQCMRPTGRM.VOL_STATIC06), data_list[i], "VOL_STATIC06");
			TRS.copy(CQCMRPTGRM.VOL_STATIC07, sizeof(CQCMRPTGRM.VOL_STATIC07), data_list[i], "VOL_STATIC07");
			TRS.copy(CQCMRPTGRM.VOL_STATIC08, sizeof(CQCMRPTGRM.VOL_STATIC08), data_list[i], "VOL_STATIC08");
			TRS.copy(CQCMRPTGRM.VOL_STATIC09, sizeof(CQCMRPTGRM.VOL_STATIC09), data_list[i], "VOL_STATIC09");

			TRS.copy(CQCMRPTGRM.IMAGE01, sizeof(CQCMRPTGRM.IMAGE01), data_list[i], "IMAGE01");
			TRS.copy(CQCMRPTGRM.IMAGE02, sizeof(CQCMRPTGRM.IMAGE02), data_list[i], "IMAGE02");
			TRS.copy(CQCMRPTGRM.IMAGE03, sizeof(CQCMRPTGRM.IMAGE03), data_list[i], "IMAGE03");
			TRS.copy(CQCMRPTGRM.IMAGE04, sizeof(CQCMRPTGRM.IMAGE04), data_list[i], "IMAGE04");
			TRS.copy(CQCMRPTGRM.IMAGE05, sizeof(CQCMRPTGRM.IMAGE05), data_list[i], "IMAGE05");

			TRS.copy(CQCMRPTGRM.ANALYZER, sizeof(CQCMRPTGRM.ANALYZER), data_list[i], "ANALYZER");

			TRS.copy(CQCMRPTGRM.WT_CHK, sizeof(CQCMRPTGRM.WT_CHK), data_list[i], "WT_CHK");
			TRS.copy(CQCMRPTGRM.MEAN_CHK, sizeof(CQCMRPTGRM.MEAN_CHK), data_list[i], "MEAN_CHK");
			TRS.copy(CQCMRPTGRM.SD_CHK, sizeof(CQCMRPTGRM.SD_CHK), data_list[i], "SD_CHK");
			TRS.copy(CQCMRPTGRM.LP_CHK, sizeof(CQCMRPTGRM.LP_CHK), data_list[i], "LP_CHK");
			TRS.copy(CQCMRPTGRM.ELEC_CONDUCTIVITY_CHK, sizeof(CQCMRPTGRM.ELEC_CONDUCTIVITY_CHK), data_list[i], "ELEC_CONDUCTIVITY_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC01_CHK, sizeof(CQCMRPTGRM.VOL_STATIC01_CHK), data_list[i], "VOL_STATIC01_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC02_CHK, sizeof(CQCMRPTGRM.VOL_STATIC02_CHK), data_list[i], "VOL_STATIC02_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC03_CHK, sizeof(CQCMRPTGRM.VOL_STATIC03_CHK), data_list[i], "VOL_STATIC03_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC04_CHK, sizeof(CQCMRPTGRM.VOL_STATIC04_CHK), data_list[i], "VOL_STATIC04_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC05_CHK, sizeof(CQCMRPTGRM.VOL_STATIC05_CHK), data_list[i], "VOL_STATIC05_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC06_CHK, sizeof(CQCMRPTGRM.VOL_STATIC06_CHK), data_list[i], "VOL_STATIC06_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC07_CHK, sizeof(CQCMRPTGRM.VOL_STATIC07_CHK), data_list[i], "VOL_STATIC07_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC08_CHK, sizeof(CQCMRPTGRM.VOL_STATIC08_CHK), data_list[i], "VOL_STATIC08_CHK");
			TRS.copy(CQCMRPTGRM.VOL_STATIC09_CHK, sizeof(CQCMRPTGRM.VOL_STATIC09_CHK), data_list[i], "VOL_STATIC09_CHK");

			TRS.copy(CQCMRPTGRM.IMAGE01_CHK, sizeof(CQCMRPTGRM.IMAGE01_CHK), data_list[i], "IMAGE01_CHK");
			TRS.copy(CQCMRPTGRM.IMAGE02_CHK, sizeof(CQCMRPTGRM.IMAGE02_CHK), data_list[i], "IMAGE02_CHK");
			TRS.copy(CQCMRPTGRM.IMAGE03_CHK, sizeof(CQCMRPTGRM.IMAGE03_CHK), data_list[i], "IMAGE03_CHK");
			TRS.copy(CQCMRPTGRM.IMAGE04_CHK, sizeof(CQCMRPTGRM.IMAGE04_CHK), data_list[i], "IMAGE04_CHK");
			TRS.copy(CQCMRPTGRM.IMAGE05_CHK, sizeof(CQCMRPTGRM.IMAGE05_CHK), data_list[i], "IMAGE05_CHK");

			TRS.copy(CQCMRPTGRM.REMARKS, sizeof(CQCMRPTGRM.REMARKS), data_list[i], "REMARKS");

			TRS.copy(CQCMRPTGRM.SUB_IMAGE01, sizeof(CQCMRPTGRM.SUB_IMAGE01), data_list[i], "SUB_IMAGE01");
			TRS.copy(CQCMRPTGRM.SUB_IMAGE02, sizeof(CQCMRPTGRM.SUB_IMAGE02), data_list[i], "SUB_IMAGE02");
			TRS.copy(CQCMRPTGRM.SUB_IMAGE03, sizeof(CQCMRPTGRM.SUB_IMAGE03), data_list[i], "SUB_IMAGE03");
			TRS.copy(CQCMRPTGRM.SUB_IMAGE04, sizeof(CQCMRPTGRM.SUB_IMAGE04), data_list[i], "SUB_IMAGE04");
			TRS.copy(CQCMRPTGRM.SUB_IMAGE05, sizeof(CQCMRPTGRM.SUB_IMAGE05), data_list[i], "SUB_IMAGE05");
			TRS.copy(CQCMRPTGRM.SUB_IMAGE06, sizeof(CQCMRPTGRM.SUB_IMAGE06), data_list[i], "SUB_IMAGE06");

			CQCMRPTGRM.USE_YN = 'Y';

			TRS.copy(CQCMRPTGRM.CREATE_USER_ID, sizeof(CQCMRPTGRM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTGRM.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_insert_cqcmrptgrm(&CQCMRPTGRM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGRM INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		DBU_init_cqcmrptgmp(&CQCMRPTGMP);
		TRS.copy(CQCMRPTGMP.FACTORY, sizeof(CQCMRPTGMP.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMRPTGMP.REPORT_NO, sizeof(CQCMRPTGMP.REPORT_NO), in_node, "REPORT_NO");
		DBU_open_cqcmrptgmp(2, &CQCMRPTGMP);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMRPTGMP OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMRPTGMP.FACTORY), CQCMRPTGMP.FACTORY);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cqcmrptgmp(2, &CQCMRPTGMP);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cqcmrptgmp(2);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGMP FETCH", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cqcmrptgmp(2);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			CQCMRPTGMP.LOT_SEQ = (int)DBU_select_cqcmrptgmp_scalar(2, &CQCMRPTGMP) + 1;  // LOT_SEQ
			memcpy(CQCMRPTGMP.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMRPTGMP.CREATE_USER_ID, sizeof(CQCMRPTGMP.CREATE_USER_ID), in_node, IN_USERID);
			DBU_insert_cqcmrptgmp(&CQCMRPTGMP);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMRPTGMP INSERT", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


		}


		aspect_list = TRS.get_list(in_node, "ASPECT_LIST");
		i_data_count = TRS.get_item_count(in_node, "ASPECT_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmrptgny(&CQCMRPTGNY);
			TRS.copy(CQCMRPTGNY.FACTORY, sizeof(CQCMRPTGNY.FACTORY), in_node, "FACTORY");
			TRS.copy(CQCMRPTGNY.REPORT_NO, sizeof(CQCMRPTGNY.REPORT_NO), in_node, "REPORT_NO");

			CQCMRPTGNY.SORT_NO = TRS.get_int(aspect_list[i], "SORT_NO");
			TRS.copy(CQCMRPTGNY.QC_NAME, sizeof(CQCMRPTGNY.QC_NAME), aspect_list[i], "QC_NAME");
			TRS.copy(CQCMRPTGNY.SPEC_VAL, sizeof(CQCMRPTGNY.SPEC_VAL), aspect_list[i], "SPEC_VAL");

			TRS.copy(CQCMRPTGNY.VAL_01, sizeof(CQCMRPTGNY.VAL_01), aspect_list[i], "VAL_01");
			TRS.copy(CQCMRPTGNY.VAL_02, sizeof(CQCMRPTGNY.VAL_02), aspect_list[i], "VAL_02");
			TRS.copy(CQCMRPTGNY.VAL_03, sizeof(CQCMRPTGNY.VAL_03), aspect_list[i], "VAL_03");
			TRS.copy(CQCMRPTGNY.VAL_04, sizeof(CQCMRPTGNY.VAL_04), aspect_list[i], "VAL_04");
			TRS.copy(CQCMRPTGNY.VAL_05, sizeof(CQCMRPTGNY.VAL_05), aspect_list[i], "VAL_05");
			TRS.copy(CQCMRPTGNY.VAL_06, sizeof(CQCMRPTGNY.VAL_06), aspect_list[i], "VAL_06");

			TRS.copy(CQCMRPTGNY.CREATE_USER_ID, sizeof(CQCMRPTGNY.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMRPTGNY.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_update_cqcmrptgny(1, &CQCMRPTGNY);
			if (DB_error_code != DB_SUCCESS)
			{
				DBU_insert_cqcmrptgny(&CQCMRPTGNY);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMRPTGNY INSERT", MP_NVST);
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

	return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Generate_Report_Validation()
- Validation Check sub function of "CUS_QCM_Generate_Report" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Save_Report_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12345") == MP_FALSE)
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
