/*******************************************************************************

	System      : MESplus
	Module      : CUS_INV
	File Name   : CUS_INV_confirm_dlv_lot.c
	Description : Confirm Inv Dlv Lot

	MES Version : 5.2.0

	Function List
		- CUS_INV_Confirm_Dlv_Lot()
			+ Confirm Dlv Lot
		- CUS_INV_CONFIRM_DLV_LOT()
			+ Main Sub function of "CUS_INV_Confirm_Dlv_Lot"
			+ (called by "CUS_INV_Confirm_Dlv_Lot")
		- CUS_INV_Confirm_Dlv_Lot_Validation()
			+ Validation Check sub function of "CUS_INV_CONFIRM_DLV_LOT" function
			+ (called by "CUS_INV_CONFIRM_DLV_LOT")

	Detail Description
		-

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2020/08/19  Miracom         Create

	Copyright(C) 1998-2020 Miracom,Inc.
	All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_CONFIRM_DLV_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Confirm_Dlv_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_CONFIRM_DLV_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Confirm_Dlv_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Confirm_Dlv_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
	CUS_INV_Confirm_Dlv_Lot()
		- Confirm Dlv Lot
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- CUS_INV_Confirm_Dlv_Lot_In_Tag *CUS_INV_Confirm_Dlv_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Dlv_Lot(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_CONFIRM_DLV_LOT_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_CONFIRM_DLV_LOT", out_node);

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
CUS_INV_CONFIRM_DLV_LOT_MAIN()
- Main sub function of "CUS_INV_CONFIRM_DLV_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CONFIRM_DLV_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CONFIRM_DLV_LOT_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	TRSNode* confirm_in_node;

	LOG_head("CUS_INV_CONFIRM_DLV_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Confirm_Dlv_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	confirm_in_node = TRS.add_node(in_node, "confirm_in_node");
	CopyDefaultMembers(confirm_in_node, in_node);

	TRS.add_char(confirm_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));
	TRS.add_nstring(confirm_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
	TRS.add_nstring(confirm_in_node, "LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));

	if (CUS_INV_Confirm_Dlv_Lot_Before_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CONFIRM_DLV_LOT(s_msg_code, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Confirm_Dlv_Lot_After_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_INV_CONFIRM_DLV_LOT()
		- Main sub function of "CUS_INV_Confirm_Dlv_Lot" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_INV_CONFIRM_DLV_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CONFIRM_DLV_LOT(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVLBL_TAG MINVDLVLBL_COUNT;
	struct MINVDLVDTL_TAG MINVDLVDTL;

	TRSNode* delete_in_node;

	char s_sys_time[14];
	double d_total_qty = 0;

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

	// MINVDLVLOT - 입하 자재 LOT 정보 조회
	DBU_init_minvdlvlot(&MINVDLVLOT);
	TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
	DBU_select_minvdlvlot(1, &MINVDLVLOT);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// PROCSTEP = 1 -> 입하 자재 확정
	// PROCSTEP = 2 -> 입하 자재 확정 취소
	// PROCSTEP = 3 -> 입하 자재 확정 취소및 완전 취소
	if (TRS.get_procstep(in_node) == '1')
	{

		/*
		// 입하 LOT 상태 체크
		if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, strlen(MP_CINV_LOT_STATUS_WAIT)) != 0)
		{
			//INV-0069 : 해당 작업은 오직 대기 상태에서만 가능합니다.
			strcpy(s_msg_code, "INV-0069");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/


		// 해당 제품, 공정에 존재하는 자재 LOT 수량 조회
		DBU_init_minvdlvlbl(&MINVDLVLBL_COUNT);
		TRS.copy(MINVDLVLBL_COUNT.FACTORY, sizeof(MINVDLVLBL_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLBL_COUNT.DLV_LOT_ID, sizeof(MINVDLVLBL_COUNT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
		d_total_qty = DBU_select_minvdlvlbl_scalar(2, &MINVDLVLBL_COUNT);

		if (d_total_qty == 0)
		{
			//INV-0038 : 해당 입하 Lot의 라벨 수량이 0입니다.
			strcpy(s_msg_code, "INV-0038");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		MINVDLVLOT.QTY = d_total_qty;
		memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, sizeof(MP_CINV_LOT_STATUS_CONFIRM));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvlot(1, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVDLVDTL - 구매 입고 상세 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
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

		if (MINVDLVDTL.ERP_OPEN_YN == 'Y')
		{
			//INV-0066 : 해당 PO 정보는 ERP에서 마감되었습니다.
			strcpy(s_msg_code, "INV-0066");
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

		MINVDLVDTL.DLV_IN_QTY += MINVDLVLOT.QTY;

		TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		// 입하 LOT 수입검사 상태 체크
		//if (memcmp(MINVDLVLOT.INSP_STATUS, MP_CQMS_STATUS_REQUEST, strlen(MP_CQMS_STATUS_REQUEST)) != 0)
		if (MINVDLVLOT.INSP_STATUS[0] == MP_CQMS_STATUS_RECEIVE)
		{
			//INV-0047 : 이 입하 자재 LOT은 수입 검사가 진행중입니다.
			strcpy(s_msg_code, "INV-0047");
			TRS.add_fieldmsg(out_node, "CUS_INV_CONFIRM_DLV_LOT", MP_NVST);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 입하 LOT 상태 체크
		if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, strlen(MP_CINV_LOT_STATUS_CONFIRM)) != 0)
		{
			//INV-0070 : 해당 작업은 오직 확정 상태에서만 가능합니다.
			strcpy(s_msg_code, "INV-0070");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVDLVLOT.DLV_LOT_STATUS));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvlot(1, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVDLVDTL - 구매 입고 상세 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
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

		if (MINVDLVDTL.ERP_OPEN_YN == 'Y')
		{
			//INV-0066 : 해당 PO 정보는 ERP에서 마감되었습니다.
			strcpy(s_msg_code, "INV-0066");
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

		MINVDLVDTL.DLV_IN_QTY -= MINVDLVLOT.QTY;

		TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	else if (TRS.get_procstep(in_node) == '3')
	{
		// 입하 LOT 수입검사 상태 체크
		//if (memcmp(MINVDLVLOT.INSP_STATUS, MP_CQMS_STATUS_REQUEST, strlen(MP_CQMS_STATUS_REQUEST)) != 0)
		if (MINVDLVLOT.INSP_STATUS[0] == MP_CQMS_STATUS_RECEIVE)
		{
			//INV-0047 : 이 입하 자재 LOT은 수입 검사가 진행중입니다.
			strcpy(s_msg_code, "INV-0047");
			TRS.add_fieldmsg(out_node, "CUS_INV_CONFIRM_DLV_LOT", MP_NVST);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		/*
		// 입하 LOT 상태 체크
		if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, strlen(MP_CINV_LOT_STATUS_CONFIRM)) != 0)
		{

			//INV-0070 : 해당 작업은 오직 확정 상태에서만 가능합니다.
			strcpy(s_msg_code, "INV-0070");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/



		if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_COMPLETED, strlen(MP_CINV_LOT_STATUS_COMPLETED)) == 0)
		{

			//INV-0070 : 해당 작업은 오직 확정 상태에서만 가능합니다.
			strcpy(s_msg_code, "INV-0070");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVDLVLOT.DLV_LOT_STATUS));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvlot(1, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVDLVDTL - 구매 입고 상세 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
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

		if (MINVDLVDTL.ERP_OPEN_YN == 'Y')
		{
			//INV-0066 : 해당 PO 정보는 ERP에서 마감되었습니다.
			strcpy(s_msg_code, "INV-0066");
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

		MINVDLVDTL.DLV_IN_QTY -= MINVDLVLOT.QTY;

		TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		delete_in_node = TRS.add_node(in_node, "delete_in_node");
		CopyDefaultMembers(delete_in_node, in_node);

		TRS.add_char(delete_in_node, IN_PROCSTEP, '1');
		TRS.add_nstring(delete_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));

		if (CUS_INV_DELETE_DLV_LOT(s_msg_code, delete_in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}
	}





	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
	CUS_INV_Confirm_Dlv_Lot_Validation()
		- Validation Check sub function of "CUS_INV_CONFIRM_DLV_LOT" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_INV_CONFIRM_DLV_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Dlv_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	/*
	if(COM_service_validation(s_msg_code,
							  in_node,
							  out_node,
							  TRS.get_procstep(in_node),
							  "123") == MP_FALSE)
	{
		return MP_FALSE;
	}
	*/

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Confirm_Dlv_Lot_Before_Transaction()
- Main sub function of "CUS_INV_CONFIRM_DLV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Dlv_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Confirm_Issue_Request_After_Transaction()
- Main sub function of "CUS_INV_CONFIRM_DLV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Dlv_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP = 1 -> 입하 자재 확정
	// PROCSTEP = 2 -> 입하 자재 확정 취소
	if (TRS.get_procstep(in_node) == '1')
	{
		//입하 LOT 확정 -> 수입 검사 요청
		if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		TRS.set_char(in_node, IN_PROCSTEP, '3');
		//입하 LOT 확정 취소 -> 수입 검사 요청 취소
		if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}
	}

	return MP_TRUE;
}