/*******************************************************************************

	System      : MESplus
	Module      : CUS_INV
	File Name   : CUS_INV_move_lot.c
	Description : Move Inv Lot

	MES Version : 4.0.0

	Function List
		- CUS_INV_Move_Lot()
			+ Move Lot
		- CUS_INV_MOVE_LOT()
			+ Main sub function of "CUS_INV_Move_Lot" function
			+ Move Lot definition
		- CUS_INV_Move_Lot_Validation()
			+ Validation Check sub function of "CUS_INV_MOVE_LOT" function

	Detail Description
		-

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2020/08/03  Miracom       Create

	Copyright(C) 1998-2020 Miracom,Inc.
	All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_MOVE_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Move_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Move_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Move_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_MOVE_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_RAS_UPDATE_TOOL(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);


/*******************************************************************************
	CUS_INV_Move_Lot()
		- Move Lot
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_MOVE_LOT_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_MOVE_LOT", out_node);

	if (i_ret == MP_TRUE)
	{
		DB_commit();
	}
	else
	{
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_MOVE_LOT()
- Main sub function of "CUS_INV_Move_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_MOVE_LOT_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{
	struct MINVREQMST_TAG MINVREQMST;

	TRSNode* move_in_node;
	TRSNode** inv_lot_list;
	TRSNode* inv_list;
	int i;

	LOG_head("CUS_INV_MOVE_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Move_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	move_in_node = TRS.add_node(in_node, "move_in_node");
	CopyDefaultMembers(move_in_node, in_node);

	TRS.add_char(move_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(move_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
	}

	// 창고 간 자재 이동
	if (TRS.get_procstep(in_node) == '1')
	{
		TRS.add_nstring(move_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
	}
	// 불출 요청 인수
	else if (TRS.get_procstep(in_node) == '2')
	{
		TRS.add_nstring(move_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
		TRS.add_nstring(move_in_node, "REQ_MAT_ID", TRS.get_string(in_node, "REQ_MAT_ID"));
		TRS.add_int(move_in_node, "REQ_MAT_VER", TRS.get_int(in_node, "REQ_MAT_VER"));

		// MINVREQMST - 불출 요청 마스터 정보 조회
		DBU_init_minvreqmst(&MINVREQMST);
		TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
		DBU_select_minvreqmst(1, &MINVREQMST);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (DB_error_code == DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		TRS.add_nstring(move_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_string(move_in_node, "TO_OPER", MINVREQMST.TO_OPER, sizeof(MINVREQMST.TO_OPER));
	}
	// 자재 KITTING
	else if (TRS.get_procstep(in_node) == '3')
	{
		TRS.add_nstring(move_in_node, "KITTING_ID", TRS.get_string(in_node, "KITTING_ID"));
		TRS.add_nstring(move_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
	}
	// 외주 출고
	else if (TRS.get_procstep(in_node) == '4')
	{
		TRS.add_nstring(move_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
	}
	// 위탁, 자재 창고에서의 이동 (불출 I/F를 보낼 것이기때문에, 이동 I/F 보내지 않음)
	else if (TRS.get_procstep(in_node) == '5')
	{
		TRS.add_nstring(move_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
		TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
	}

	if (CUS_INV_Move_Lot_Before_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_MOVE_LOT(s_msg_code, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Move_Lot_After_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_INV_MOVE_LOT()
		- Main sub function of "CUS_INV_Move_Lot" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_MOVE_LOT(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{

	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
	struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct MRASTOLDEF_TAG MRASTOLDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;

	char s_sys_time[14];

	int i = 0;
	int i_move_step = 0;

	TRSNode** inv_lot_list;
	TRSNode* tool_in_node;
	TRSNode* tool_sts_list;
	TRSNode* cmn_out;

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

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		DBU_init_minvlotsts(&MINVLOTSTS_OLD);
		TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0044");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS_OLD.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "INV-0013");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "INV-0014");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 외주 출고일때 자재 LOAD 여부 체크
		if (TRS.get_procstep(in_node) == '4')
		{
			//창고 이동 개념으로 봐야해서 ( 외주 창고로 이동 후 load 됨) 주석처리 _ 20210107_lwg 
			// 자재 LOT LOAD 체크
			//if (MINVLOTSTS_OLD.LOAD_FLAG != 'Y')
			//{
			//	strcpy(s_msg_code, "INV-0017");
			//	TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			//	TRS.add_dberrmsg(out_node, DB_error_msg);

			//	gs_log_type.type = MP_LOG_ERROR;
			//	gs_log_type.e_type = MP_LOG_E_VALIDATION;
			//	gs_log_type.category = MP_LOG_CATE_COMMON;
			//	COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			//	return MP_FALSE;
			//}
		}
		else
		{
			// 자재 LOT LOAD 체크
			if (MINVLOTSTS_OLD.LOAD_FLAG == 'Y')
			{
				//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
				strcpy(s_msg_code, "INV-0059");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		if (TRS.get_procstep(in_node) == '3')
		{
			if (memcmp(MINVLOTSTS_OLD.INV_CMF_4, TRS.get_string(in_node, "KITTING_ID"), strlen(TRS.get_string(in_node, "KITTING_ID"))) != 0)
			{
				//INV-0040 : 자재 LOT의 Kitting ID가 다릅니다.
				strcpy(s_msg_code, "INV-0040");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "INV_KITTING_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_CMF_4), MINVLOTSTS_OLD.INV_CMF_4);
				TRS.add_fieldmsg(out_node, "KITTING_ID", MP_STR, strlen(TRS.get_string(in_node, "KITTING_ID")), TRS.get_string(in_node, "KITTING_ID"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		else if (TRS.get_procstep(in_node) != '4')
		{
			if (COM_isnullspace(MINVLOTSTS_OLD.INV_CMF_4) == MP_FALSE)
			{
				//INV-0041 : 해당 자재는 Kitting된 자재입니다.
				strcpy(s_msg_code, "INV-0041");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		// MWIPOPRDEF - FROM 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTSTS_OLD.OPER, sizeof(MINVLOTSTS_OLD.OPER));
		MWIPOPRDEF_FROM.INV_FLAG = 'Y';
		DBU_select_mwipoprdef(4, &MWIPOPRDEF_FROM);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// MWIPOPRDEF - TO 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
		MWIPOPRDEF_TO.INV_FLAG = 'Y';
		DBU_select_mwipoprdef(4, &MWIPOPRDEF_TO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 공정 체크 (출고 창고와 자재 LOT의 공정이 같은지 체크)
		if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == 0)
		{
			//INV-0045 : 현재 공정과 이동 공정이 같습니다.
			strcpy(s_msg_code, "INV-0045");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
			TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 사업부 체크 (자재 창고 -> 사업부 별 생산 창고 이동 가능, 사업부별 생산 창고 -> 자재 창고 이동 가능)
		// 사업부 생산 창고 -> 사업부 생산 창고 이동 불가
		if (COM_isnullspace(MWIPOPRDEF_FROM.AREA_ID) == MP_FALSE
			&& COM_isnullspace(MWIPOPRDEF_TO.AREA_ID) == MP_FALSE)
		{
			if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID)) != 0)
			{
				//INV-0025 : 자재 LOT 사업부가 같지 않습니다.
				strcpy(s_msg_code, "INV-0025");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "FROM_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_FROM.AREA_ID), MWIPOPRDEF_FROM.AREA_ID);
				TRS.add_fieldmsg(out_node, "TO_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_TO.AREA_ID), MWIPOPRDEF_TO.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));
		memcpy(MINVLOTSTS.SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
		memcpy(MINVLOTSTS.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));

		// 창고 간 자재 이동
		// 같은 창고 TYPE 이동 : MOVE
		// 자재 창고 -> 생산 창고 : OPER_IN
		// 생산 창고 -> 자재 창고 : INV_IN
		// 생산 창고 -> 외주창고 : OUTSRC_IN
		// 모든 창고 -> 자재 반납 창고 : RET_IN
		//i_move_step(1) : 같은 창고
		//i_move_step(2) : 자재 창고 -> 생산 창고
		//i_move_step(3) : 생산 창고 -> 자재 창고
		//i_move_step(4) : 생산 창고 -> 외주 창고
		//i_move_step(5) : 모든 창고 -> 자재 반납 창고
		if (TRS.get_procstep(in_node) == '4')
		{
			i_move_step = 4;
		}
		else
		{
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) == 0)
			{
				if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
				{
					i_move_step = 2;
				}
				else
				{
					i_move_step = 1;
				}
			}
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0 ||
				memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_MOLD, strlen(MP_OPER_GRP_TYPE_MOLD)) == 0)
			{
				if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) == 0
					|| memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) == 0)
				{
					i_move_step = 3;
				}
				else
				{
					i_move_step = 1;
				}
			}

			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_RET_R, strlen(MP_OPER_GRP_TYPE_RET_R)) == 0)
			{
				i_move_step = 5;
			}
		}

		// FROM & TO 창고에 대해 트랜 코드 다르게 발생
		if (i_move_step == 1)
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_MOVE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
		}
		else if (i_move_step == 2)
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_OPER_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
		}
		else if (i_move_step == 3)
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_INV_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
		}
		else if (i_move_step == 4)
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_OUTSRC_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
		}
		else if (i_move_step == 5)
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_RET_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
		}

		memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
		MINVLOTSTS.LAST_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
		MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;

		TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		//자재 LOT 이력 생성
		DBU_init_minvlothis(&MINVLOTHIS);

		//자재 LOT UPSERT & 자재 이력 INSERT
		if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
			in_node,
			out_node,
			s_sys_time,
			&MINVLOTSTS_OLD,
			&MINVLOTSTS,
			&MINVLOTHIS) == MP_FALSE)
		{
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//MAT_CMF_9 : 금형 여부
		if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
		{
			//TOOL 조회
			DBU_init_mrastoldef(&MRASTOLDEF);
			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASTOLDEF.TOOL_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

			DBU_select_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{

				//20230828 금형도 원자재 창고에서 금형창고로 이동하는식으로 변경되어서 해당 부분 삭제
				/*
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
				*/

			}
			else {
				//TO0L UPDATE
				memcpy(MRASTOLDEF.OPER, MINVLOTSTS.OPER, sizeof(MRASTOLDEF.OPER));

				DBU_update_mrastoldef(1, &MRASTOLDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "RAS-0004");
					TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				tool_in_node = TRS.add_node(in_node, "tool_in_node");
				TRS.add_char(tool_in_node, IN_PROCSTEP, 'U');
				CopyDefaultMembers(tool_in_node, in_node);

				TRS.add_string(tool_in_node, "SUB_AREA_ID", MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
				TRS.add_string(tool_in_node, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
				TRS.add_string(tool_in_node, "TOOL_DESC", MRASTOLDEF.TOOL_DESC, sizeof(MRASTOLDEF.TOOL_DESC));
				TRS.add_string(tool_in_node, "TOOL_TYPE", MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
				TRS.add_string(tool_in_node, "TOOL_GRP", MRASTOLDEF.TOOL_GRP, sizeof(MRASTOLDEF.TOOL_GRP));
				TRS.add_string(tool_in_node, "AREA_ID", MRASTOLDEF.AREA_ID, sizeof(MRASTOLDEF.AREA_ID));
				TRS.add_string(tool_in_node, "VENDOR_ID", MRASTOLDEF.VENDOR_ID, sizeof(MRASTOLDEF.VENDOR_ID));
				TRS.add_string(tool_in_node, "TOOL_COMMENT", MRASTOLDEF.TOOL_COMMENT, sizeof(MRASTOLDEF.TOOL_COMMENT));

				//TOOL 업데이트시 현재 TOOL_STS의 값을 동일하게 넣어준다.
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_1, sizeof(MRASTOLDEF.TOOL_STS_1));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_2, sizeof(MRASTOLDEF.TOOL_STS_2));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_3, sizeof(MRASTOLDEF.TOOL_STS_3));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_4, sizeof(MRASTOLDEF.TOOL_STS_4));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_5, sizeof(MRASTOLDEF.TOOL_STS_5));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_6, sizeof(MRASTOLDEF.TOOL_STS_6));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_7, sizeof(MRASTOLDEF.TOOL_STS_7));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_8, sizeof(MRASTOLDEF.TOOL_STS_8));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_9, sizeof(MRASTOLDEF.TOOL_STS_9));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_10, sizeof(MRASTOLDEF.TOOL_STS_10));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_11, sizeof(MRASTOLDEF.TOOL_STS_11));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_12, sizeof(MRASTOLDEF.TOOL_STS_12));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_13, sizeof(MRASTOLDEF.TOOL_STS_13));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_14, sizeof(MRASTOLDEF.TOOL_STS_14));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_15, sizeof(MRASTOLDEF.TOOL_STS_15));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_16, sizeof(MRASTOLDEF.TOOL_STS_16));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_17, sizeof(MRASTOLDEF.TOOL_STS_17));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_18, sizeof(MRASTOLDEF.TOOL_STS_18));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_19, sizeof(MRASTOLDEF.TOOL_STS_19));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_20, sizeof(MRASTOLDEF.TOOL_STS_20));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_21, sizeof(MRASTOLDEF.TOOL_STS_21));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_22, sizeof(MRASTOLDEF.TOOL_STS_22));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_23, sizeof(MRASTOLDEF.TOOL_STS_23));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_24, sizeof(MRASTOLDEF.TOOL_STS_24));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_25, sizeof(MRASTOLDEF.TOOL_STS_25));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_26, sizeof(MRASTOLDEF.TOOL_STS_26));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_27, sizeof(MRASTOLDEF.TOOL_STS_27));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_28, sizeof(MRASTOLDEF.TOOL_STS_28));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_29, sizeof(MRASTOLDEF.TOOL_STS_29));
				tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
				TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_30, sizeof(MRASTOLDEF.TOOL_STS_30));

				cmn_out = TRS.create_node("cmn_out");
				if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}

		//자재 LOT 이동 이력 생성
		if (CUS_INV_INSERT_LOT_MVH_HISTORY(s_msg_code,
			in_node,
			out_node,
			s_sys_time,
			&MINVLOTSTS_OLD,
			&MINVLOTSTS) == MP_FALSE)
		{
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//자재 불출 -> 자재 불출 내역 생성
		if (TRS.get_procstep(in_node) == '2')
		{
			// MINVREQMST - 불출 요청 마스터 정보 조회
			DBU_init_minvreqmst(&MINVREQMST);
			TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
			DBU_select_minvreqmst(1, &MINVREQMST);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MINVREQLOT - 불출 요청 LOT 정보 조회
			DBU_init_minvreqlot(&MINVREQLOT);
			TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
			TRS.copy(MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID), in_node, "REQ_MAT_ID");
			MINVREQLOT.REQ_MAT_VER = TRS.get_int(in_node, "REQ_MAT_VER");
			memcpy(MINVREQLOT.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			DBU_select_minvreqlot(1, &MINVREQLOT);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 자재 불출 내역 생성
			if (CUS_INV_INSERT_LOT_MAT_ISSUE_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVREQMST,
				&MINVREQLOT) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;

}

/*******************************************************************************
	CUS_INV_Move_Lot_Validation()
		- Validation Check sub function of "CUS_INV_MOVE_LOT" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot_Validation(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{
	/*
	if(COM_service_validation(s_msg_code,
							  in_node,
							  out_node,
							  TRS.get_procstep(in_node),
							  "1") == MP_FALSE)
	{
		return MP_FALSE;
	}*/

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Move_Lot_Before_Transaction()
- Main sub function of "CUS_INV_MOVE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Move_Lot_After_Transaction()
- Main sub function of "CUS_INV_MOVE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;


	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVLOTMVH_TAG MINVLOTMVH;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;

	TRSNode** inv_lot_list;
	TRSNode* erpif_in;
	TRSNode* cmn_out;
	int i;

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	// STEP 1 : 이동 인터페이스
	// STEP 4 : 외주 출고 이동 인터페이스
	if (TRS.get_procstep(in_node) == '1' || TRS.get_procstep(in_node) == '4')
	{
		//각 LOT마다 데이터 전송
		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			//LOT 데이터 조회
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0044");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
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

			DBU_init_minvlotmvh(&MINVLOTMVH);
			TRS.copy(MINVLOTMVH.FACTORY, sizeof(MINVLOTMVH.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTMVH.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			MINVLOTMVH.HIST_SEQ = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
			DBU_select_minvlotmvh(1, &MINVLOTMVH);
			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0054 : 자재 이동 이력이 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0054");
				TRS.add_fieldmsg(out_node, "MINVLOTMVH SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTMVH.FACTORY), MINVLOTMVH.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTMVH.INV_LOT_ID), MINVLOTMVH.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPOPRDEF - FROM 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
			TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTMVH.OPER, sizeof(MINVLOTMVH.OPER));
			MWIPOPRDEF_FROM.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0590 : 이 창고는 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0590");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}


				TRS.add_fieldmsg(out_node, "MWIPOPRDEF_FROM SELECT(4) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//FROM AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
			TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
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

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPOPRDEF - TO 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
			TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_TO.OPER, MINVLOTMVH.TO_OPER, sizeof(MINVLOTMVH.TO_OPER));
			MWIPOPRDEF_TO.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0590 : 이 창고는 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0590");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF_TO SELECT(4) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
			TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
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

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//위탁 창고에서 이동
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) == 0)
			{
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
				CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2));
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
					CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
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

				// MINVDLVDTL - 구매 입고 상세 정보 조회
				DBU_init_minvdlvdtl(&MINVDLVDTL);
				TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVDLVDTL.DLV_NO, MINVLOTSTS.DLV_NO, sizeof(MINVLOTSTS.DLV_NO));
				MINVDLVDTL.DLV_SEQ = MINVLOTSTS.DLV_SEQ;
				DBU_select_minvdlvdtl(1, &MINVDLVDTL);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "INV-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
					TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//ERP 실적 - IF_PO_CONSIGN_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE_NAME", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
				TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
				TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
				TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
				TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_double(erpif_in, "QTY", -MINVLOTSTS.QTY);
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_PO_CONSIGN_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			//자재 창고에서 이동
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) == 0)
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
				TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
				memcpy(MGCMTBLDAT_SRC.KEY_1, "ISSUE", strlen("ISSUE"));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);

				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", 2);	//2번으로 고정
				TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));	//2번으로 고정
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

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
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				DBU_select_if_inv_txns(2, &IF_INV_TXNS);

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", IF_INV_TXNS.IF_SEQ);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			else
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
				TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
				memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
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

				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
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
					CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
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

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정

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
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
	}

	return MP_TRUE;
}