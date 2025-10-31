/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_mold_store_registration.c
Description : 금형 입고 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/11  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Mold_Store_Registration_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_RAS_MOLD_STORE_REGISTRATION(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_CREATE_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_RAS_Mold_Store_Registration()
- Mold Store Registration function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Store_Registration(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_RAS_MOLD_STORE_REGISTRATION(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_RAS_Mold_Store_Registration", out_node);
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
CUS_RAS_MOLD_STORE_REGISTRATION()
- Main sub function of "CUS_RAS_Mold_Store_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_MOLD_STORE_REGISTRATION(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MRASTOLDEF_TAG MRASTOLDEF;
	struct MRASTEVDEF_TAG MRASTEVDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
	struct MINVMOVSTS_TAG MINVMOVSTS;

	//TRSNode	    *gen_in_node;
	TRSNode* create_in_node;
	TRSNode* split_in;
	TRSNode* move_in;
	TRSNode* tool_in_node;
	TRSNode* tool_event_in_node;
	TRSNode* cmn_out;
	TRSNode** inv_lot_list;
	TRSNode** move_lot_list;
	TRSNode* inv_list;
	TRSNode* move_list;

	char mold_lot_id[30];
	char split_lot_id[30];

	char inv_step;
	char tool_step;

	int inv_lot_count = 0;
	int i_step = 0;
	int i;
	int i_tol;

	LOG_head("CUS_RAS_Mold_Store_Registration");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_RAS_Mold_Store_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 저장
	if (TRS.get_procstep(in_node) == '1')
	{
		inv_step = '1';
		tool_step = 'I';

		// MOLD TYPE 체크 (GCM 체크)
		if (COM_check_gcm_data(s_msg_code,
			out_node,
			"C_MOLD_TYPE",
			TRS.get_factory(in_node),
			TRS.get_string(in_node, "MOLD_TYPE"),
			(int)strlen(TRS.get_string(in_node, "MOLD_TYPE"))) == MP_FALSE)
		{
			return MP_FALSE;
		}

		//금형 LOT ID채번
		memset(mold_lot_id, ' ', sizeof(mold_lot_id));


		/*gen_in_node = TRS.add_node(in_node, "gen_in_node");

		CopyDefaultMembers(gen_in_node, in_node);
		TRS.add_string(gen_in_node, "RULE_ID", "MOLD_LOT_ID", strlen("MOLD_LOT_ID"));
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

		memcpy(mold_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID"))); */

		//TRS.add_string(out_node, "MOLD_LOT_ID", mold_lot_id, sizeof(mold_lot_id));


		//TRS.free_node(cmn_out);

		//자재 LOT 생성
		create_in_node = TRS.add_node(in_node, "create_in_node");
		TRS.add_char(create_in_node, IN_PROCSTEP, inv_step);
		CopyDefaultMembers(create_in_node, in_node);

		TRS.add_nstring(create_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
		TRS.add_nstring(create_in_node, "MOLD_MODEL", TRS.get_string(in_node, "MOLD_MODEL"));
		TRS.add_nstring(create_in_node, "MOLD_TYPE", TRS.get_string(in_node, "MOLD_TYPE"));
		TRS.add_nstring(create_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_nstring(create_in_node, "MAT_TYPE", MP_MAT_TYPE_STORED_GOODS);

		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");
		inv_lot_count = TRS.get_item_count(in_node, "INV_LOT_LIST");

		for (i = 0; i < inv_lot_count; i++)
		{
			inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
			TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
			TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		}

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_INV_CREATE_LOT_MAIN(s_msg_code, create_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);



		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");
		inv_lot_count = TRS.get_item_count(in_node, "INV_LOT_LIST");

		for (i_tol = 0; i_tol < inv_lot_count; i_tol++)
		{
			TRS.copy(mold_lot_id, sizeof(mold_lot_id), inv_lot_list[i_tol], "INV_LOT_ID");

			// MINVDLVLOT - 입하 자재 LOT 정보 조회
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTSTS.INV_LOT_ID, mold_lot_id, sizeof(MINVLOTSTS.INV_LOT_ID));

			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

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

			//TOOL 생성
			tool_in_node = TRS.add_node(in_node, "tool_in_node");
			TRS.add_char(tool_in_node, IN_PROCSTEP, tool_step);
			CopyDefaultMembers(tool_in_node, in_node);

			TRS.add_nstring(tool_in_node, "TOOL_ID", mold_lot_id);
			TRS.add_nstring(tool_in_node, "TOOL_DESC", MWIPMATDEF.MAT_DESC);
			TRS.add_nstring(tool_in_node, "TOOL_GRP", TRS.get_string(in_node, "MOLD_MODEL"));
			TRS.add_nstring(tool_in_node, "TOOL_TYPE", TRS.get_string(in_node, "MOLD_TYPE"));
			TRS.add_string(tool_in_node, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
			TRS.add_string(tool_in_node, "SUB_AREA_ID", MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
			TRS.add_string(tool_in_node, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
			TRS.add_string(tool_in_node, "VENDOR_ID", MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			TRS.add_nstring(tool_in_node, "TOOL_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//TOOL 정보 UPDATE
			DBU_init_mrastoldef(&MRASTOLDEF);
			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASTOLDEF.TOOL_ID, mold_lot_id, sizeof(MRASTOLDEF.TOOL_ID));

			DBU_select_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			memcpy(MRASTOLDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MRASTOLDEF.MAT_ID));
			MRASTOLDEF.MAT_VER = MINVLOTSTS.MAT_VER;
			memcpy(MRASTOLDEF.OPER, MINVLOTSTS.OPER, sizeof(MRASTOLDEF.OPER));

			DBU_update_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MRASTOLDEF.MAT_ID), MRASTOLDEF.MAT_ID);
				TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, sizeof(MRASTOLDEF.MAT_VER), MRASTOLDEF.MAT_VER);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_mrastevdef(&MRASTEVDEF);
			TRS.copy(MRASTEVDEF.FACTORY, sizeof(MRASTEVDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASTEVDEF.TOOL_TYPE, MRASTOLDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));

			i_step = 2;
			DBU_open_mrastevdef(i_step, &MRASTEVDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTEVDEF OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_mrastevdef(i_step, &MRASTEVDEF);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_mrastevdef(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "RAS-0004");
					TRS.add_fieldmsg(out_node, "MRASTEVDEF FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_mrastevdef(i_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//TOOL EVENT 셋업
				tool_event_in_node = TRS.add_node(in_node, "tool_event_in_node");
				TRS.add_char(tool_event_in_node, IN_PROCSTEP, 'I');
				CopyDefaultMembers(tool_event_in_node, in_node);

				TRS.add_string(tool_event_in_node, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
				TRS.add_string(tool_event_in_node, "TOOL_TYPE", MRASTEVDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));
				TRS.add_string(tool_event_in_node, "TOOL_EVENT_ID", MRASTEVDEF.TOOL_EVENT_ID, sizeof(MRASTEVDEF.TOOL_EVENT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (RAS_UPDATE_TOOL_EVENT_RELATION(s_msg_code, tool_event_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		inv_step = '1';
		tool_step = 'I';

		// MOLD TYPE 체크 (GCM 체크)
		if (COM_check_gcm_data(s_msg_code,
			out_node,
			"C_MOLD_TYPE",
			TRS.get_factory(in_node),
			TRS.get_string(in_node, "MOLD_TYPE"),
			(int)strlen(TRS.get_string(in_node, "MOLD_TYPE"))) == MP_FALSE)
		{
			return MP_FALSE;
		}

		//금형 LOT ID채번
		memset(mold_lot_id, ' ', sizeof(mold_lot_id));



		//구매에서 이동지시등록한 창고와 생산에서 입고잡는 창고가 다르다면 창고변경. UPDATE
		//이동지시 마스터 생성 및 업데이트
		DBU_init_minvmovsts(&MINVMOVSTS);
		TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "MOVE_ID");

		DBU_select_minvmovsts(1, &MINVMOVSTS);
		if (DB_error_code == DB_SUCCESS)
		{

			if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) != MP_TRUE)
			{
				if (memcmp(MINVMOVSTS.TO_OPER, TRS.get_string(in_node, "TO_OPER"), strlen(TRS.get_string(in_node, "TO_OPER"))) != MP_FALSE)
				{
					TRS.copy(MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER), in_node, "TO_OPER");
					TRS.copy(MINVMOVSTS.UPDATE_USER_ID, sizeof(MINVMOVSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(MINVMOVSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.UPDATE_TIME));

					DBU_update_minvmovsts(1, &MINVMOVSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "MINVMOVSTS UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		//창고이동 start
		move_in = TRS.add_node(in_node, "move_in");
		CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(move_in, "PROCSTEP", '3');


		TRS.add_nstring(move_in, "MOVE_ID", TRS.get_string(in_node, "MOVE_ID"));


		//move_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		move_list = TRS.add_node(move_in, "INV_LOT_LIST");
		TRS.add_nstring(move_list, "INV_LOT_ID", TRS.get_string(in_node, "INV_LOT_ID"));

		TRS.add_double(move_in, "QTY", TRS.get_double(in_node, "QTY"));



		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_MOVE_LOT_ORDER(s_msg_code, move_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		//창고이동 END



				// MINVDLVLOT - 입하 자재 LOT 정보 조회
		DBU_init_minvlotsts(&MINVLOTSTS_OLD);
		TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), in_node, "INV_LOT_ID");
		//memcpy(MINVLOTSTS.INV_LOT_ID, mold_lot_id, sizeof(MINVLOTSTS.INV_LOT_ID));

		DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}



		split_in = TRS.add_node(in_node, "split_in");
		CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(split_in, "PROCSTEP", '1');


		TRS.add_nstring(split_in, "INV_LOT_ID", TRS.get_string(in_node, "INV_LOT_ID"));
		TRS.add_nstring(split_in, "SPLIT_LOT_ID", TRS.get_string(in_node, "SPLIT_LOT_ID"));
		TRS.add_int(split_in, "LAST_ACTIVE_HIST_SEQ", MINVLOTSTS_OLD.LAST_ACTIVE_HIST_SEQ);
		TRS.add_double(split_in, "SPLIT_QTY", TRS.get_double(in_node, "QTY"));


		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_SPLIT_LOT_MAIN(s_msg_code, split_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}




		TRS.copy(mold_lot_id, sizeof(mold_lot_id), in_node, "SPLIT_LOT_ID");

		// MINVDLVLOT - 입하 자재 LOT 정보 조회
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "SPLIT_LOT_ID");
		//memcpy(MINVLOTSTS.INV_LOT_ID, mold_lot_id, sizeof(MINVLOTSTS.INV_LOT_ID));

		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}



		TRS.copy(MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1), in_node, "MOLD_MODEL"); // 금형 모델
		TRS.copy(MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2), in_node, "MOLD_TYPE"); // 금형 구분
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






		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

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

		//TOOL 생성
		tool_in_node = TRS.add_node(in_node, "tool_in_node");
		TRS.add_char(tool_in_node, IN_PROCSTEP, tool_step);
		CopyDefaultMembers(tool_in_node, in_node);

		TRS.add_nstring(tool_in_node, "TOOL_ID", mold_lot_id);
		TRS.add_nstring(tool_in_node, "TOOL_DESC", MWIPMATDEF.MAT_DESC);
		TRS.add_nstring(tool_in_node, "TOOL_GRP", TRS.get_string(in_node, "MOLD_MODEL"));
		TRS.add_nstring(tool_in_node, "TOOL_TYPE", TRS.get_string(in_node, "MOLD_TYPE"));
		TRS.add_string(tool_in_node, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
		TRS.add_string(tool_in_node, "SUB_AREA_ID", MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
		TRS.add_string(tool_in_node, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
		TRS.add_string(tool_in_node, "VENDOR_ID", MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
		TRS.add_nstring(tool_in_node, "TOOL_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		//TOOL 정보 UPDATE
		DBU_init_mrastoldef(&MRASTOLDEF);
		TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), in_node, "SPLIT_LOT_ID");
		//memcpy(MRASTOLDEF.TOOL_ID, mold_lot_id, sizeof(MRASTOLDEF.TOOL_ID));


		DBU_select_mrastoldef(1, &MRASTOLDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		memcpy(MRASTOLDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MRASTOLDEF.MAT_ID));
		MRASTOLDEF.MAT_VER = MINVLOTSTS.MAT_VER;
		memcpy(MRASTOLDEF.OPER, MINVLOTSTS.OPER, sizeof(MRASTOLDEF.OPER));

		DBU_update_mrastoldef(1, &MRASTOLDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MRASTOLDEF.MAT_ID), MRASTOLDEF.MAT_ID);
			TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, sizeof(MRASTOLDEF.MAT_VER), MRASTOLDEF.MAT_VER);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		DBU_init_mrastevdef(&MRASTEVDEF);
		TRS.copy(MRASTEVDEF.FACTORY, sizeof(MRASTEVDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASTEVDEF.TOOL_TYPE, MRASTOLDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));

		i_step = 2;
		DBU_open_mrastevdef(i_step, &MRASTEVDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASTEVDEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_mrastevdef(i_step, &MRASTEVDEF);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_mrastevdef(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTEVDEF FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_mrastevdef(i_step);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TOOL EVENT 셋업
			tool_event_in_node = TRS.add_node(in_node, "tool_event_in_node");
			TRS.add_char(tool_event_in_node, IN_PROCSTEP, 'I');
			CopyDefaultMembers(tool_event_in_node, in_node);

			TRS.add_string(tool_event_in_node, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			TRS.add_string(tool_event_in_node, "TOOL_TYPE", MRASTEVDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));
			TRS.add_string(tool_event_in_node, "TOOL_EVENT_ID", MRASTEVDEF.TOOL_EVENT_ID, sizeof(MRASTEVDEF.TOOL_EVENT_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (RAS_UPDATE_TOOL_EVENT_RELATION(s_msg_code, tool_event_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Mold_Store_Registration_Validation()
- Validation Check sub function of "CUS_RAS_MOLD_STORE_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Store_Registration_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		return MP_FALSE;
	}

	return MP_TRUE;
}
