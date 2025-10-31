/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_etc_in_lot.c
Description : 공정 LOT 기타 입고

MES Version : 5.0

Function List


Detail Description

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/20  KY.JUNG        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Etc_In_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Etc_In_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Etc_In_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_ETC_IN_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_ETC_IN_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Etc_In_Lot()
- Tran Etc In Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Etc_In_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_ETC_IN_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Etc_In_Lot", out_node);
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
CUS_WIP_ETC_IN_LOT()
- Main sub function of "CUS_WIP_Etc_In_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_ETC_IN_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	TRSNode* etc_in_node;
	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	TRSNode* lot_list;
	TRSNode** wip_lot_list;

	struct work_date_tag work_date;

	int i;
	char lot_id[26];
	char s_factory[10];

	LOG_head("CUS_WIP_Etc_In_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_Etc_In_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	memset(s_factory, ' ', sizeof(s_factory));

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	etc_in_node = TRS.add_node(in_node, "etc_in_node");
	CopyDefaultMembers(etc_in_node, in_node);

	TRS.add_char(etc_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(etc_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
	TRS.add_char(etc_in_node, "ERP_FLAG", TRS.get_char(in_node, "ERP_FLAG"));

	wip_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{

		lot_list = TRS.add_node(etc_in_node, "LOT_LIST");

		memset(lot_id, ' ', sizeof(lot_id));

		if (TRS.get_char(in_node, "LOT_INPUT_FLAG") != 'Y') {
			// LOT 발번 필요함.



			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

			if (TRS.mem_cmp(in_node, "AREA_ID", gs_area_grt, sizeof(gs_area_grt)) == MP_FALSE && TRS.get_char(wip_lot_list[i], "PROD_CHK") == 'Y')
			{
				TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_SHIPPING_LOT_ID));
				TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
			}
			else
			{
				TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
			}

			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
			TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(wip_lot_list[i], "OPER"));
			TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

			TRS.free_node(cmn_out);

		}
		else {
			memcpy(lot_id, TRS.get_string(wip_lot_list[i], "LOT_ID"), strlen(TRS.get_string(wip_lot_list[i], "LOT_ID")));


			//TRS.add_nstring(lot_list, "LOT_ID", TRS.get_string(wip_lot_list[i], "LOT_ID"));
		}

		TRS.add_string(lot_list, "LOT_ID", lot_id, sizeof(lot_id));

		TRS.add_double(lot_list, "QTY_1", TRS.get_double(wip_lot_list[i], "QTY_1"));
		TRS.add_nstring(lot_list, "SUB_AREA_ID", TRS.get_string(wip_lot_list[i], "SUB_AREA_ID"));
		TRS.add_nstring(lot_list, "OPER", TRS.get_string(wip_lot_list[i], "OPER"));
		TRS.add_nstring(lot_list, "MAT_ID", TRS.get_string(wip_lot_list[i], "MAT_ID"));
		TRS.add_int(lot_list, "MAT_VER", TRS.get_int(wip_lot_list[i], "MAT_VER"));
		TRS.add_nstring(lot_list, "IN_TYPE", TRS.get_string(wip_lot_list[i], "IN_TYPE"));
		TRS.add_nstring(lot_list, "COMMENT", TRS.get_string(wip_lot_list[i], "COMMENT"));
		TRS.add_char(lot_list, "LOT_TYPE", TRS.get_char(wip_lot_list[i], "LOT_TYPE"));
		TRS.add_nstring(lot_list, "OWNER_CODE", TRS.get_string(wip_lot_list[i], "OWNER_CODE"));
		TRS.add_nstring(lot_list, "CREATE_CODE", TRS.get_string(wip_lot_list[i], "CREATE_CODE"));
	}

	if (CUS_WIP_Etc_In_Lot_Before_Transaction(s_msg_code, 0, etc_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_ETC_IN_LOT_MAIN(s_msg_code, etc_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_Etc_In_Lot_After_Transaction(s_msg_code, 0, etc_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_ETC_IN_LOT()
- Main sub function of "CUS_WIP_Etc_In_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_ETC_IN_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPMATFLW_TAG MWIPMATFLW;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_IN;
	struct MINVLOTSTS_TAG MINVLOTSTS;

	TRSNode* create_in;
	TRSNode* cmn_out;
	//TRSNode* lot_list;
	TRSNode** wip_lot_list;
	TRSNode* cv_in;
	TRSNode* inv_list;
//	TRSNode* adapt_in;

	char s_lot_id[26];
	char c_comment[400];
	char c_oper[10];
	char c_mat_id[30];
	char s_sys_time[14];
	char c_lot_type;
	char c_owner_code[10];
	char c_create_code[10];
	int i = 0;
	double iqty = 0;


	memset(s_lot_id, ' ', sizeof(s_lot_id));
	memset(c_comment, ' ', sizeof(c_comment));
	memset(c_oper, ' ', sizeof(c_oper));
	memset(c_mat_id, ' ', sizeof(c_mat_id));
	c_lot_type = 'P';
//	memset(c_lot_type, ' ', sizeof(c_lot_type));
	memset(c_owner_code, ' ', sizeof(c_owner_code));
	memset(c_create_code, ' ', sizeof(c_create_code));

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

	wip_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{


		memcpy(s_lot_id, TRS.get_string(wip_lot_list[i], "LOT_ID"), strlen(TRS.get_string(wip_lot_list[i], "LOT_ID")));
		iqty = TRS.get_double(wip_lot_list[i], "QTY_1");
		memcpy(c_comment, TRS.get_string(wip_lot_list[i], "COMMENT"), strlen(TRS.get_string(wip_lot_list[i], "COMMENT")));
		memcpy(c_oper, TRS.get_string(wip_lot_list[i], "OPER"), strlen(TRS.get_string(wip_lot_list[i], "OPER")));
		memcpy(c_mat_id, TRS.get_string(wip_lot_list[i], "MAT_ID"), strlen(TRS.get_string(wip_lot_list[i], "MAT_ID")));

		memcpy(c_owner_code, TRS.get_string(wip_lot_list[i], "OWNER_CODE"), strlen(TRS.get_string(wip_lot_list[i], "OWNER_CODE")));
		memcpy(c_create_code, TRS.get_string(wip_lot_list[i], "CREATE_CODE"), strlen(TRS.get_string(wip_lot_list[i], "CREATE_CODE")));
		c_lot_type = TRS.get_char(wip_lot_list[i], "LOT_TYPE");

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), wip_lot_list[i], "MAT_ID");
		MWIPMATDEF.MAT_VER = TRS.get_int(wip_lot_list[i], "MAT_VER");
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// TO 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), wip_lot_list[i], "OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1X2) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
		{
			// 제품에 해당하는 FLOW 조회
			DBU_init_mwipmatflw(&MWIPMATFLW);
			TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;
			DBU_select_mwipmatflw(3, &MWIPMATFLW);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//플로우가 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0655");
				TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//완제품의 FLOW, OPER를 조회
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0655");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 제품에 해당하는 FLOW 조회
				DBU_init_mwipmatflw(&MWIPMATFLW);
				TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;
				memcpy(MWIPMATFLW.FLOW, MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				DBU_select_mwipmatflw(4, &MWIPMATFLW);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0655");
					TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
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
				// 제품에 해당하는 제품 창고 조회(마지막 공정)
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				DBU_select_mwipflwopr(3, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0655");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
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
			// 제품에 해당하는 FLOW 조회
			DBU_init_mwipmatflw(&MWIPMATFLW);
			TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;
			DBU_select_mwipmatflw(3, &MWIPMATFLW);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0655");
				TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 제품에 해당하는 제품 창고 조회(마지막 공정)
			DBU_init_mwipflwopr(&MWIPFLWOPR);
			TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
			DBU_select_mwipflwopr(3, &MWIPFLWOPR);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0655");
				TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}
		}




		//실제  lot을 찾아서 수량을 보정해주는 로직 추가.               
		DBU_init_mwiplotstsx(&MWIPLOTSTSX_IN);
		TRS.copy(MWIPLOTSTSX_IN.FACTORY, sizeof(MWIPLOTSTSX_IN.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPLOTSTSX_IN.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_IN.LOT_ID));

		//memcpy(s_lot_id, TRS.get_string(wip_lot_list[i], "LOT_ID"), strlen(TRS.get_string(wip_lot_list[i], "LOT_ID")));


		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_IN);
		// wip lot인 경우
		if (DB_error_code == DB_SUCCESS)
		{


			if (MWIPLOTSTSX_IN.LOT_DEL_FLAG == 'Y')
			{
				MWIPLOTSTSX_IN.LOT_DEL_FLAG = ' ';
				memset(MWIPLOTSTSX_IN.LOT_DEL_CODE, ' ', sizeof(MWIPLOTSTSX_IN.LOT_DEL_CODE));
				memset(MWIPLOTSTSX_IN.LOT_DEL_TIME, ' ', sizeof(MWIPLOTSTSX_IN.LOT_DEL_TIME));
				//품목변경은 ADAPT 해야하는게 맞는데..수량없는상태에서 살려지지가 않아서 그냥 품목바꿈.20230303
				TRS.copy(MWIPLOTSTSX_IN.MAT_ID, sizeof(MWIPLOTSTSX_IN.MAT_ID), wip_lot_list[i], "MAT_ID");
				memcpy(MWIPLOTSTSX_IN.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				MWIPLOTSTSX_IN.LOT_TYPE = c_lot_type;
				memcpy(MWIPLOTSTSX_IN.OWNER_CODE, c_owner_code,sizeof(c_owner_code));
				memcpy(MWIPLOTSTSX_IN.CREATE_CODE, c_create_code, sizeof(c_create_code));




				MWIPLOTSTSX_IN.QTY_1 = 0;

				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_IN);
				if (DB_error_code != DB_SUCCESS)
				{
					memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);

					return MP_FALSE;
				}


			}
			else {

				if (memcmp(MWIPLOTSTSX_IN.OPER, c_oper, sizeof(MWIPLOTSTSX_IN.OPER)) < 0) {

					memcpy(s_msg_code, "WIP-0638", MP_SIZE_MSG);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER_1", MP_STR, sizeof(MWIPLOTSTSX_IN.OPER), MWIPLOTSTSX_IN.OPER);
					TRS.add_fieldmsg(out_node, "OPER_2", MP_STR, sizeof(c_oper), c_oper);

					return MP_FALSE;

				}

				if (memcmp(MWIPLOTSTSX_IN.MAT_ID, c_mat_id, sizeof(MWIPLOTSTSX_IN.MAT_ID)) < 0) {
				
					memcpy(s_msg_code, "WIP-0637", MP_SIZE_MSG);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER_1", MP_STR, sizeof(MWIPLOTSTSX_IN.MAT_ID), MWIPLOTSTSX_IN.MAT_ID);
					TRS.add_fieldmsg(out_node, "OPER_2", MP_STR, sizeof(c_mat_id), c_mat_id);

					return MP_FALSE;
				
				}


				if (memcmp(MWIPLOTSTSX_IN.CREATE_CODE, c_create_code, sizeof(MWIPLOTSTSX_IN.CREATE_CODE)) < 0) {

					memcpy(s_msg_code, "WIP-0694", MP_SIZE_MSG);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.CREATE_CODE), MWIPLOTSTSX_IN.CREATE_CODE);
					TRS.add_fieldmsg(out_node, "TO_CREATE_CODE", MP_STR, sizeof(c_create_code), c_create_code);

					return MP_FALSE;

				}

			}

			/*
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_IN);
					TRS.copy(MWIPLOTSTSX_IN.FACTORY, sizeof(MWIPLOTSTSX_IN.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPLOTSTSX_IN.LOT_ID, s_lot_id, strlen(MWIPLOTSTSX_IN.LOT_ID));

					//memcpy(s_lot_id, TRS.get_string(wip_lot_list[i], "LOT_ID"), strlen(TRS.get_string(wip_lot_list[i], "LOT_ID")));


					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_IN);
*/
				/*
				if (memcmp(MWIPLOTSTSX_IN.MAT_ID, c_mat_id, sizeof(MWIPLOTSTSX_IN.MAT_ID)) < 0) {



					//lot adapt 처리
					adapt_in = TRS.add_node(in_node, "apt_in");
					TRS.add_char(adapt_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(adapt_in, in_node);

					TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX_IN.LOT_ID, sizeof(MWIPLOTSTSX_IN.LOT_ID));
					TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX_IN.MAT_ID, sizeof(MWIPLOTSTSX_IN.MAT_ID));
					TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX_IN.OPER, sizeof(MWIPLOTSTSX_IN.OPER));
					TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX_IN.FLOW, sizeof(MWIPLOTSTSX_IN.FLOW));
					TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX_IN.ORDER_ID, sizeof(MWIPLOTSTSX_IN.ORDER_ID));
					TRS.add_string(adapt_in, "TO_MAT_ID", c_mat_id, sizeof(c_mat_id));
					TRS.add_int(adapt_in, "TO_MAT_VER", 1);
					TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX_IN.OPER, sizeof(MWIPLOTSTSX_IN.OPER));
					TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX_IN.FLOW, sizeof(MWIPLOTSTSX_IN.FLOW));
					TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX_IN.LOT_TYPE);
					TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX_IN.LOT_PRIORITY);
					TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX_IN.CREATE_CODE, sizeof(MWIPLOTSTSX_IN.CREATE_CODE));
					TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX_IN.OWNER_CODE, sizeof(MWIPLOTSTSX_IN.OWNER_CODE));
					TRS.add_string(adapt_in, "COMMENT", c_comment,(c_comment));



					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);


					DBU_init_mwiplotstsx(&MWIPLOTSTSX_IN);
					TRS.copy(MWIPLOTSTSX_IN.FACTORY, sizeof(MWIPLOTSTSX_IN.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPLOTSTSX_IN.LOT_ID, s_lot_id, strlen(MWIPLOTSTSX_IN.LOT_ID));

					//memcpy(s_lot_id, TRS.get_string(wip_lot_list[i], "LOT_ID"), strlen(TRS.get_string(wip_lot_list[i], "LOT_ID")));


					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_IN);



					if (MWIPLOTSTSX_IN.LOT_DEL_FLAG == 'Y')
					{
						MWIPLOTSTSX_IN.LOT_DEL_FLAG = ' ';
						memset(MWIPLOTSTSX_IN.LOT_DEL_CODE, ' ', sizeof(MWIPLOTSTSX_IN.LOT_DEL_CODE));
						memset(MWIPLOTSTSX_IN.LOT_DEL_TIME, ' ', sizeof(MWIPLOTSTSX_IN.LOT_DEL_TIME));
						MWIPLOTSTSX_IN.QTY_1 = 0;

						DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_IN);
						if (DB_error_code != DB_SUCCESS)
						{
							memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);

							return MP_FALSE;
						}



					}

				}

				*/


			




			cv_in = TRS.add_node(in_node, "cv_in");
			TRS.add_char(cv_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(cv_in, in_node);

		

			TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_IN.LOT_ID, sizeof(MWIPLOTSTSX_IN.LOT_ID));
			TRS.add_string(cv_in, "MAT_ID", c_mat_id, sizeof(c_mat_id));
			TRS.add_int(cv_in, "MAT_VER", 1);
			TRS.add_string(cv_in, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
			TRS.add_int(cv_in, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
			TRS.add_string(cv_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
			TRS.add_string(cv_in, "COMMENT", c_comment, sizeof(c_comment));;
			TRS.add_double(cv_in, "QTY_1", COM_dbl_round(MWIPLOTSTSX_IN.QTY_1, 5, 'U') + COM_dbl_round(iqty, 5, 'U'));

		//	TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(lot_list[i], "COMMENT"));
		//	TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_IN.QTY_1 + TRS.get_double(lot_list[i], "QTY_1"));


			TRS.add_nstring(cv_in, "CODE", "CV001");


			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			//TRS.free_node(cmn_out);
		}
		else
		{

			//자재lot인 경우 다시 수량을 살려준다.
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTSTS.INV_LOT_ID, s_lot_id, strlen(s_lot_id));
			//TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MWIPLOTSTSX_IN.LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code == DB_SUCCESS  && MINVLOTSTS.DELETE_FLAG != 'Y')
			{
				/*
				if (MINVLOTSTS.DELETE_FLAG == 'Y')
				{
					MINVLOTSTS.DELETE_FLAG = ' ';
					memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
					memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
					memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
					MINVLOTSTS.QTY = 0;
					DBU_update_minvlotsts(1, &MINVLOTSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);
						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
				*/


					if (memcmp(MINVLOTSTS.OPER, c_oper, sizeof(c_oper))  < 0) {

						memcpy(s_msg_code, "WIP-0638", MP_SIZE_MSG);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						TRS.add_fieldmsg(out_node, "MINVLOTSTSX_IN UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);
						TRS.add_fieldmsg(out_node, "OPER_1", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
						TRS.add_fieldmsg(out_node, "OPER_2", MP_STR, sizeof(c_oper), c_oper);

						return MP_FALSE;


					}

					if (memcmp(MINVLOTSTS.MAT_ID, c_mat_id, sizeof(c_mat_id)) < 0) {

						memcpy(s_msg_code, "WIP-0637", MP_SIZE_MSG);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						TRS.add_fieldmsg(out_node, "MINVLOTSTSX_IN UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);
						TRS.add_fieldmsg(out_node, "OPER_1", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
						TRS.add_fieldmsg(out_node, "OPER_2", MP_STR, sizeof(c_mat_id), c_mat_id);

						return MP_FALSE;

					}

					//양산 원자재가 있으면 기타입고 다른유형으로 안됨.
					if(memcmp(c_create_code, MP_CREATE_CODE_PROD, sizeof(MP_CREATE_CODE_PROD)) < 0){

						memcpy(s_msg_code, "WIP-0694", MP_SIZE_MSG);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_IN UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.LOT_ID), MWIPLOTSTSX_IN.LOT_ID);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_IN.CREATE_CODE), MWIPLOTSTSX_IN.CREATE_CODE);
						TRS.add_fieldmsg(out_node, "TO_CREATE_CODE", MP_STR, sizeof(c_create_code), c_create_code);

						return MP_FALSE;

					}
				


				cv_in = TRS.add_node(in_node, "cv_in");
				TRS.add_char(cv_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(cv_in, in_node);



				inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
			//	TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(lot_list[i], "LOT_ID"));
			//	TRS.add_double(inv_list, "CHANGE_QTY", MINVLOTSTS.QTY + TRS.get_double(lot_list[i], "QTY_1"));
			//	TRS.add_nstring(inv_list, "TRAN_COMMENT", TRS.get_string(lot_list[i], "COMMENT"));

				TRS.add_string(inv_list, "MAT_ID", c_mat_id, sizeof(c_mat_id));
				TRS.add_int(inv_list, "MAT_VER", 1);
				TRS.add_string(inv_list, "INV_LOT_ID", c_comment, sizeof(c_comment));
				TRS.add_double(inv_list, "CHANGE_QTY", COM_dbl_round(MINVLOTSTS.QTY,5,'U') + COM_dbl_round(iqty, 5, 'U'));
				TRS.add_string(inv_list, "TRAN_COMMENT", c_comment, sizeof(c_comment));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

			}
			else {

				create_in = TRS.add_node(in_node, "create_in");

				CopyDefaultMembers(create_in, in_node);
				TRS.add_char(create_in, IN_PROCSTEP, '1');
				TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));


				TRS.add_string(create_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_int(create_in, "MAT_VER", MWIPMATDEF.MAT_VER);
				TRS.add_string(create_in, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				TRS.add_int(create_in, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
				TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				//TRS.add_double(create_in, "QTY_1", TRS.get_double(lot_list[i], "QTY_1"));
				TRS.add_double(create_in, "QTY_1", COM_dbl_round(iqty, 5, 'U'));




				TRS.add_char(create_in, "LOT_PRIORITY", '1');
		
				//TRS.add_char(create_in, "LOT_TYPE", 'P');
				//TRS.add_nstring(create_in, "CREATE_CODE", "PROD");
				//TRS.add_nstring(create_in, "OWNER_CODE", "PROD");
				
				//TRS.add_char(create_in, "LOT_TYPE", c_lot_type, sizeof(c_lot_type));
				TRS.add_char(create_in, "LOT_TYPE", c_lot_type);
				TRS.add_string(create_in, "OWNER_CODE", c_owner_code, sizeof(c_owner_code));
				TRS.add_string(create_in, "CREATE_CODE", c_create_code, sizeof(c_create_code));
				

				//TRS.add_nstring(create_in, "COMMENT", TRS.get_string(lot_list[i], "COMMENT"));
				TRS.add_string(create_in, "COMMENT", c_comment, sizeof(c_comment));


				if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
				{
					TRS.add_string(create_in, "LOT_CMF_7", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
					TRS.add_string(create_in, "LOT_CMF_8", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				}

				cmn_out = TRS.create_node("Cmn_Out");



				if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}


			}

		}

		TRS.free_node(cmn_out);
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Etc_In_Lot_Validation()
- Validation Check sub function of "CUS_WIP_ETC_IN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Etc_In_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	/*if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"1") == MP_FALSE)
	{
		return MP_FALSE;
	}*/

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

/*******************************************************************************
CUS_WIP_Etc_In_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_ETC_IN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Etc_In_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Etc_In_Lot_After_Transaction()
- Main sub function of "CUS_WIP_ETC_IN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Etc_In_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct CBASTXNDEF_TAG CBASTXNDEF_ETC;
	struct MWIPFLWOPR_TAG MWIPFLWOPR_PROD;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct MINVETCLOT_TAG MINVETCLOT;
//	TRSNode* store_in;
	TRSNode* erpif_in;
	TRSNode* move_in;
	TRSNode* cmn_out;
	TRSNode** wip_lot_list;
	TRSNode* lot_list;
	int i = 0;
	double iqty = 0;

	wip_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{

		iqty = TRS.get_double(wip_lot_list[i], "QTY_1");

		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), wip_lot_list[i], "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
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

		// TO 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), wip_lot_list[i], "OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1x) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//완제품 창고로 기타 입고 - 제품에 해당하는 마지막 공정으로 LOT 생성 -> 완제품 창고로 MOVE
		//생산 창고로 기타 입고 - 제품에 해당하는 마지막 공정으로 LOT 생성 -> 선택된 창고로 STOREXXX
		//STORE 제거 전부 MOVE
		if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
		{
			if (memcmp(MWIPLOTSTS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER)) != 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR_PROD);
				TRS.copy(MWIPFLWOPR_PROD.FACTORY, sizeof(MWIPFLWOPR_PROD.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR_PROD.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR_PROD);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR_PROD.FACTORY), MWIPFLWOPR_PROD.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR_PROD.FLOW), MWIPFLWOPR_PROD.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 완제품 창고로 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR_PROD.FLOW, sizeof(MWIPFLWOPR_PROD.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR_PROD.OPER, sizeof(MWIPFLWOPR_PROD.OPER));
				TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
		else
		{
			if (memcmp(MWIPLOTSTS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER)) != 0)
			{

				// MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				//TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR_PROD.FLOW, sizeof(MWIPFLWOPR_PROD.FLOW));
				TRS.add_nstring(move_in, "TO_OPER", TRS.get_string(wip_lot_list[i], "OPER"));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
		/*	else
			{
				// TO 창고로 STORE
				store_in = TRS.add_node(in_node, "store_in");
				TRS.add_char(store_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(store_in, in_node);

				TRS.add_string(store_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_nstring(store_in, "TO_OPER", TRS.get_string(wip_lot_list[i], "OPER"));
				TRS.add_nstring(store_in, "COMMENT", TRS.get_string(wip_lot_list[i], "COMMENT"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
	*/
	//ETC IN 한글명 가져옴
		DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
		TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
		memcpy(MGCMTBLDAT_SRC.KEY_1, "ETC_IN", strlen("ETC_IN"));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//TO AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
		TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
		MWIPMATDEF.MAT_VER = MWIPLOTSTS.MAT_VER;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//기타입고 정보 저장
		DBU_init_minvetclot(&MINVETCLOT);
		TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVETCLOT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		DBU_select_minvetclot(2, &MINVETCLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			MINVETCLOT.SEQ = 1;
		}
		else {
			MINVETCLOT.SEQ = MINVETCLOT.SEQ + 1;
		}


		TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVETCLOT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		//MINVETCLOT.SEQ = MINVETCLOT.SEQ + 1;
		memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
		//MINVETCLOT.QTY = MWIPLOTSTS.QTY_1;

		MINVETCLOT.QTY = COM_dbl_round(iqty, 5, 'U');
		memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
		memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		memcpy(MINVETCLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
		MINVETCLOT.VENDOR_SITE_ID = 0;
		memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
		memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_IN, sizeof(MINVETCLOT.ETC_TYPE));
		memcpy(MINVETCLOT.ETC_DATE, gs_sys_time, 8);
		MINVETCLOT.TRAN_SRC_ID = 0;
		memset(MINVETCLOT.TRAN_SRC_NAME, ' ', sizeof(MINVETCLOT.TRAN_SRC_NAME));
		memcpy(MINVETCLOT.ETC_COMMENT, MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LAST_COMMENT));


		//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
		//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
		if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
		{
			memcpy(MINVETCLOT.CMF_1, "A", strlen("A"));
			memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
			memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));
		}
		else
		{
			memcpy(MINVETCLOT.CMF_1, "B", strlen("B"));
			memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
			memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));
		}





		TRS.copy(MINVETCLOT.CREATE_USER_ID, sizeof(MINVETCLOT.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVETCLOT.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

		if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
		{
			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
				CBASTXNDEF.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			DBU_init_cbastxndef(&CBASTXNDEF_ETC);
			TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(TRS.get_string(wip_lot_list[i], "IN_TYPE"), sizeof(TRS.get_string(wip_lot_list[i], "IN_TYPE")));
			CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF_ETC.FACTORY), CBASTXNDEF_ETC.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF_ETC.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF_ETC.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF_ETC);
				TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(TRS.get_string(wip_lot_list[i], "IN_TYPE"), sizeof(TRS.get_string(wip_lot_list[i], "IN_TYPE")));
				CBASTXNDEF_ETC.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF_ETC.FACTORY), CBASTXNDEF_ETC.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF_ETC.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF_ETC.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
			memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));

			//ERP 실적 - IF_INV_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
			TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
			TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
			TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			//TRS.add_double(erpif_in, "QTY", MWIPLOTSTS.QTY_1);
			TRS.add_double(erpif_in, "QTY", COM_dbl_round(iqty, 5, 'U'));


			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
			TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID)); //추후 이동지시번호가 들어올예정

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_inv_txns(&IF_INV_TXNS);
			TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

			//ERP 실적 - IF_INV_TXN_LOTS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID)); //추후 이동지시번호가 들어올예정
			TRS.add_double(erpif_in, "QTY", COM_dbl_round(iqty, 5, 'U'));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}

		// 기타 입고 정보 생성
		DBU_insert_minvetclot(&MINVETCLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVETCLOT INSERT/UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVETCLOT.FACTORY), MINVETCLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//기타입고 화면으로 리스트 전송
		lot_list = TRS.add_node(out_node, "LOT_LIST");
		TRS.add_string(lot_list, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		TRS.add_double(lot_list, "QTY", MWIPLOTSTS.QTY_1);
		TRS.add_string(lot_list, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
		TRS.add_string(lot_list, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		TRS.add_string(lot_list, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		TRS.add_string(lot_list, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		TRS.add_string(lot_list, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(lot_list, "MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(lot_list, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_nstring(lot_list, "ARRIVAL_DATE", "");
		TRS.add_nstring(lot_list, "IN_TYPE", TRS.get_string(wip_lot_list[i], "IN_TYPE"));
		TRS.add_nstring(lot_list, "VENDOR_ID", "");
		TRS.add_nstring(lot_list, "VENDOR_LOT_ID", "");
		TRS.add_nstring(lot_list, "COMMENT", TRS.get_string(wip_lot_list[i], "COMMENT"));
	}

	return MP_TRUE;
}