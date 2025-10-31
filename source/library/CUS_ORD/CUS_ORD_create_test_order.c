/*******************************************************************************

System      : MESplus
Module      : CUS_ORD
File Name   : CUS_ORD_create_test_order.c
Description : Create Test Order function

MES Version : 5.0

Function List
- step 1: 테스트 작업지시 생성


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/01/12  WG.LEE        Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_ORD_Create_Test_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_ORD_CREATE_TEST_ORDER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_ORD_Create_Test_Order()
- Update Order Bom
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Create_Test_Order(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_ORD_CREATE_TEST_ORDER(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_ORD_Create_Test_Order", out_node);
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
CUS_ORD_CREATE_TEST_ORDER()
- Main sub function of "CUS_ORD_Create_Test_Order" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_CREATE_TEST_ORDER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF_BOM;
	struct MWIPMATFLW_TAG MWIPMATFLW;
	struct MWIPFLWDEF_TAG MWIPFLWDEF;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct CWIPORDBOM_TAG CWIPORDBOM;
	struct work_date_tag work_date;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_AF;
	struct CWIPRCPDEF_TAG   CWIPRCPDEF;         //설비 레시비 정보
	struct MRASRESDEF_TAG   MRASRESDEF;         //설비 레시비 정보
	struct CQCMISPSTS_TAG CQCMISPSTS;


	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	TRSNode** list_item;

	TRSNode* create_in;
	TRSNode* send_in;
	TRSNode* insp_in;

	int iItemCount = 0;
	int i = 0;
	char s_factory[10];
	char sOrder_id[26];

	char s_lot_id[26];

	LOG_head("CUS_ORD_Create_Test_Order");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(sOrder_id, ' ', sizeof(sOrder_id));
	memset(s_factory, ' ', sizeof(s_factory));
	memset(&work_date, ' ', sizeof(work_date));

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	Get_shift(s_factory, &work_date);

	/* Validation Check */
	if (CUS_ORD_Create_Test_Order_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//작업지시 생성
	if (TRS.get_procstep(in_node) == '1')
	{
		//MAT_ID 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0006 : 이 제품은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
		{
			//품목 - FLOW 정보 조회
			DBU_init_mwipmatflw(&MWIPMATFLW);
			TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;
			TRS.copy(MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW), in_node, "FLOW");
			DBU_select_mwipmatflw(4, &MWIPMATFLW);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0019 : 이 FLOW는 제품에 속해 있지 않습니다.
				strcpy(s_msg_code, "WIP-0019");
				TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			//flow의 첫번쨰 공정을 조회한다.            
			DBU_init_mwipoprdef(&MWIPOPRDEF);

			DBU_init_mwipflwopr(&MWIPFLWOPR);
			TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
			DBU_select_mwipflwopr(2, &MWIPFLWOPR);
			if (DB_error_code == DB_SUCCESS)
			{
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);

				DBU_init_mwipflwdef(&MWIPFLWDEF);
				TRS.copy(MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWDEF.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				DBU_select_mwipflwdef(1, &MWIPFLWDEF);
			}


			memset(sOrder_id, ' ', sizeof(sOrder_id));

			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			TRS.add_char(gen_in_node, "PROCSTEP", '2');
			CopyDefaultMembers(gen_in_node, in_node);
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_TEST_ORDER, strlen(MP_ID_ROLE_TEST_ORDER));
			TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			/*
			memcpy(sOrder_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));


			TRS.free_node(cmn_out);
			*/



			if (COM_isnullspace(MWIPFLWDEF.FLOW_CMF_2) == MP_FALSE)
			{
				//2025-05-23 스카이 개발품작지로 의뢰되는경우있어서 스카이작지는 -SK붙임.

				//sprintf(sOrder_id, "%s%s", TRS.get_string(cmn_out, "GEN_ID"), MWIPFLWDEF.FLOW_CMF_2);
				snprintf(sOrder_id, sizeof(sOrder_id), "%s%s", TRS.get_string(cmn_out, "GEN_ID"), MWIPFLWDEF.FLOW_CMF_2);
			}
			else
			{
				memcpy(sOrder_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
			}
			TRS.free_node(cmn_out);

			//만들어진 작업지시를 INSERT 한다.
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, sOrder_id, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(MWIPORDSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPORDSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			memcpy(MWIPORDSTS.WORK_DATE, gs_sys_time, sizeof(MWIPORDSTS.WORK_DATE));
			TRS.copy(MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1), in_node, "AREA_ID");
			memcpy(MWIPORDSTS.ORD_CMF_2, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			memcpy(MWIPORDSTS.ORD_CMF_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			MWIPORDSTS.LOT_TYPE = MP_LOT_TYPE_T;
			MWIPORDSTS.LOT_PRIORITY = '1';
			memcpy(MWIPORDSTS.OWNER_CODE, MP_OWNER_CODE_DEVE, strlen(MP_OWNER_CODE_DEVE));
			//memcpy(MWIPORDSTS.CREATE_CODE, MP_CREATE_CODE_TEST, strlen(MP_CREATE_CODE_TEST));
			TRS.copy(MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE), in_node, "CREATE_CODE");
			memcpy(MWIPORDSTS.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
			MWIPORDSTS.FLOW_SEQ_NUM = MWIPMATFLW.FLOW_SEQ_NUM;
			memcpy(MWIPORDSTS.ORG_DUE_TIME, gs_sys_time, sizeof(MWIPORDSTS.ORG_DUE_TIME));
			MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
			TRS.copy(MWIPORDSTS.CREATE_USER_ID, sizeof(MWIPORDSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MWIPORDSTS.CREATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.CREATE_TIME));
			MWIPORDSTS.ORD_QTY = TRS.get_double(in_node, "ORD_QTY");
			TRS.copy(MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC), in_node, "COMMENT");

			TRS.copy(MWIPORDSTS.ORD_CMF_9, sizeof(MWIPORDSTS.ORD_CMF_9), in_node, "ORD_CMF_9");


			TRS.copy(MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME), in_node, "FROM_DATE");
			TRS.copy(MWIPORDSTS.PLAN_END_TIME, sizeof(MWIPORDSTS.PLAN_END_TIME), in_node, "TO_DATE");

			DBU_insert_mwipordsts(&MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPORDSTS.MAT_ID), MWIPORDSTS.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
		else
		{
			TRS.copy(sOrder_id, sizeof(sOrder_id), in_node, "ORDER_ID");
		}

		//작업지시 조회
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPORDSTS.ORDER_ID, sOrder_id, sizeof(MWIPORDSTS.ORDER_ID));
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		if (MWIPORDSTS.ORD_STATUS_FLAG != MP_CWIP_ORDER_WAIT)
		{
			//ORD-0027 : 대기 상태인 작업지시만 수정이 가능합니다.
			strcpy(s_msg_code, "ORD-0027");
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		if (memcmp(MWIPORDSTS.FLOW, TRS.get_string(in_node, "FLOW"), strlen(TRS.get_string(in_node, "FLOW"))) != MP_FALSE)
		{
			TRS.copy(MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW), in_node, "FLOW");
		}

		if (COM_dbl_round(MWIPORDSTS.ORD_QTY, 5, 'U') != COM_dbl_round(TRS.get_double(in_node, "ORD_QTY"), 5, 'U'))
		{
			MWIPORDSTS.ORD_QTY = TRS.get_double(in_node, "ORD_QTY");
		}

		TRS.copy(MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC), in_node, "COMMENT");

		//작업지시 설명 업데이트
		DBU_update_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
		TRS.add_string(out_node, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));


		if (TRS.get_char(in_node, "LOT_CREATE_FLAG") == 'Y') {

			memset(s_lot_id, ' ', sizeof(s_lot_id));

			if (TRS.get_char(in_node, "LOT_INPUT_FLAG") == 'Y') {
				memcpy(s_lot_id, TRS.get_string(in_node, "LOT_ID"), strlen(TRS.get_string(in_node, "LOT_ID")));
			}
			else {

				gen_in_node = TRS.add_node(in_node, "gen_in_node");
				TRS.add_char(gen_in_node, "PROCSTEP", '2');
				CopyDefaultMembers(gen_in_node, in_node);
				TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
				TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
				TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
				TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
				TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
				TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
				TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);






				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				if (COM_isnullspace(TRS.get_string(in_node, "CREATE_LOT_KEY")) == MP_FALSE)
				{
					sprintf(s_lot_id, "%s%s", TRS.get_string(cmn_out, "GEN_ID"), TRS.get_string(in_node, "CREATE_LOT_KEY"));
				}
				else
				{
					memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
				}

				TRS.free_node(cmn_out);
			}





			//LOT ID 생성 
			//채번된 LOT ID로 작업 공정의 작업지시 정보를 사용하여 LOT을 생성 한다.
			create_in = TRS.add_node(in_node, "create_in");
			TRS.add_char(create_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(create_in, in_node);

			TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
			TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
			TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
			TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
			TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
			TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
			TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
			TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
			TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
			TRS.add_double(create_in, "QTY_1", MWIPORDSTS.ORD_QTY);
			TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
			TRS.add_string(create_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			TRS.add_string(create_in, "COMMENT", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));


			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//작업지시 업데이트.
			//create 시 작업지시가 자동 생성될때 상태값이 start로 변경되기 때문에 다시 wait상태로 바꿔준다
			MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
			MWIPORDSTS.ORD_IN_QTY = MWIPORDSTS.ORD_QTY;
			TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));

			//작업지시 설명 업데이트
			DBU_update_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}


			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
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


			//완료 이후 공정 정보 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
			TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0010 : 이 공정은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			if (memcmp(MWIPOPRDEF_AF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
			{
				insp_in = TRS.add_node(in_node, "insp_in");
				TRS.add_char(insp_in, IN_PROCSTEP, '2');
				CopyDefaultMembers(insp_in, in_node);

				TRS.add_string(insp_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, insp_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);


				DBU_init_cqcmispsts(&CQCMISPSTS);
				TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPSTS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				memcpy(CQCMISPSTS.INSP_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				DBU_select_cqcmispsts(3, &CQCMISPSTS);
				if (DB_error_code == DB_NOT_FOUND)
				{
					return MP_FALSE;
				}

				//SAMPLE 검사인경우  GRADE /SIZE 입력
				TRS.copy(CQCMISPSTS.CMF_7, sizeof(CQCMISPSTS.CMF_7), in_node, "INSP_SAMPLE_GRADE");
				TRS.copy(CQCMISPSTS.CMF_8, sizeof(CQCMISPSTS.CMF_8), in_node, "INSP_SAMPLE_SIZE");


				DBU_update_cqcmispsts(2, &CQCMISPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}








				//CTM의 최종검사 또는 W/D 검사인 경우 라운드 검사 장비에 LOT정보를 보내준다.
				if (memcmp(MWIPOPRDEF_AF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
				{
					//최종검사이며, 라운드 검사인 경우 조건
					if (memcmp(MWIPOPRDEF_AF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE &&
						memcmp(MWIPOPRDEF_AF.OPER_CMF_5, MP_CQMS_INSP_JUDGE_GROUP_ROUND, strlen(MP_CQMS_INSP_JUDGE_GROUP_ROUND)) == MP_FALSE)
					{
						DBU_init_cwiprcpdef(&CWIPRCPDEF);
						memcpy(CWIPRCPDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
						memcpy(CWIPRCPDEF.AREA_ID, MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
						memcpy(CWIPRCPDEF.OPER, MWIPOPRDEF_AF.OPER, sizeof(MWIPOPRDEF_AF.OPER));
						memcpy(CWIPRCPDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
						DBU_select_cwiprcpdef(1, &CWIPRCPDEF);
						//if (DB_error_code != DB_SUCCESS)
						//{
						//    //WIP-0625 : Round 검사의 Recipe 정보가 존재하지 않습니다.  Recipe 정보를 확인하세요.
						//    strcpy(s_msg_code, "WIP-0625");
						//    TRS.add_fieldmsg(out_node, "CWIPRCPDEF SELECT", MP_NVST);
						//    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPRCPDEF.FACTORY), CWIPRCPDEF.FACTORY);
						//    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPRCPDEF.AREA_ID), CWIPRCPDEF.AREA_ID);
						//    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPRCPDEF.OPER), CWIPRCPDEF.OPER);
						//    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);
						//    TRS.add_dberrmsg(out_node, DB_error_msg);

						//    gs_log_type.type = MP_LOG_ERROR;
						//    gs_log_type.e_type = MP_LOG_E_SYSTEM;
						//    gs_log_type.category = MP_LOG_CATE_VIEW;

						//    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						//    return MP_FALSE;
						//}

						DBU_init_mrasresdef(&MRASRESDEF);
						memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
						memcpy(MRASRESDEF.AREA_ID, MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
						MRASRESDEF.RES_CMF_1[0] = 'Y';
						memcpy(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_ROUND, strlen(MP_RESS_GRP_ROUND));
						DBU_select_mrasresdef(2, &MRASRESDEF);
						if (DB_error_code != DB_SUCCESS)
						{
							//WIP-0626 : Round 검사 장비가 존재하지 않습니다. Round 검사 장비를 확인하세요.
							strcpy(s_msg_code, "WIP-0626");
							TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
							TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MRASRESDEF.AREA_ID), MRASRESDEF.AREA_ID);
							TRS.add_fieldmsg(out_node, "RES_GRP_1", MP_STR, sizeof(MRASRESDEF.RES_GRP_1), MRASRESDEF.RES_GRP_1);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						//라운드 검사 설비에 lot정보를 쏴주는 것은 실적화면에서 설비를 선택하지 않고, 검사 공정에 검사 의뢰시 
						//설비에 데이터가 넘어가야 하기 때문에 end lot after쪽에 넣는다. 
						send_in = TRS.add_node(in_node, "send_in");
						TRS.add_char(send_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(send_in, in_node);
						TRS.add_string(send_in, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
						TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
						TRS.add_string(send_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
						TRS.add_string(send_in, "RECIPE_ID", CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_EIS_START_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}
				}
			}

			TRS.add_string(out_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		}





		//BOM정보를 삭제하고 모든 리스트를 INSERT 한다.
		DBU_init_cwipordbom(&CWIPORDBOM);
		memcpy(CWIPORDBOM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		DBU_delete_cwipordbom(2, &CWIPORDBOM);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPORDBOM DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		list_item = TRS.get_list(in_node, "BOM_LIST");
		iItemCount = TRS.get_item_count(in_node, "BOM_LIST");

		for (i = 0; i < iItemCount; i++)
		{
			DBU_init_cwipordbom(&CWIPORDBOM);
			memcpy(CWIPORDBOM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
			memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), list_item[i], "OPER");
			TRS.copy(CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID), list_item[i], "MAT_ID");
			CWIPORDBOM.MAT_VER = 1;
			CWIPORDBOM.UNIT_QTY = TRS.get_double(list_item[i], "UNIT_QTY");
			CWIPORDBOM.QTY = TRS.get_double(list_item[i], "QTY");

			//MAT_ID 조회
			DBU_init_mwipmatdef(&MWIPMATDEF_BOM);
			memcpy(MWIPMATDEF_BOM.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
			memcpy(MWIPMATDEF_BOM.MAT_ID, CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));
			MWIPMATDEF_BOM.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF_BOM);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BOM.FACTORY), MWIPMATDEF_BOM.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BOM.MAT_ID), MWIPMATDEF_BOM.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			memcpy(CWIPORDBOM.UNIT, MWIPMATDEF_BOM.UNIT_1, sizeof(CWIPORDBOM.UNIT));

			//OUT_OPER 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			memcpy(MWIPOPRDEF.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
			memcpy(MWIPOPRDEF.OPER_CMF_1, CWIPORDBOM.FLOW, sizeof(CWIPORDBOM.FLOW));
			DBU_select_mwipoprdef(2, &MWIPOPRDEF);
			if (DB_error_code == DB_SUCCESS)
			{
				memcpy(CWIPORDBOM.OUT_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			}

			TRS.copy(CWIPORDBOM.CREATE_USER_ID, sizeof(CWIPORDBOM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPORDBOM.CREATE_TIME, gs_sys_time, sizeof(CWIPORDBOM.CREATE_TIME));

			DBU_insert_cwipordbom(&CWIPORDBOM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPORDBOM INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDBOM.OPER), CWIPORDBOM.OPER);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}

	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		if (MWIPORDSTS.ORD_STATUS_FLAG != MP_CWIP_ORDER_WAIT)
		{
			//ORD-0027 : 대기 상태인 작업지시만 수정이 가능합니다.
			strcpy(s_msg_code, "ORD-0027");
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_DELETE;

		//작업지시 설명 업데이트
		DBU_update_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
	}

	return MP_TRUE;
}



/*******************************************************************************
CUS_ORD_Create_Test_Order_Validation()
- Validation Check sub function of "CUS_ORD_CREATE_TEST_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Create_Test_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (TRS.get_procstep(in_node) == '1')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}

		if (COM_isnullspace(TRS.get_string(in_node, "FLOW")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "FLOW", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}

		if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}
	}

	return MP_TRUE;
}
