/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_delete_dlv_lot.c
Description : Delete Inv Dlv_Lot Data

MES Version : 5.2.0

Function List
- CUS_INV_Delete_Dlv_order()
+ Delete Inv Dlv Lot Data
- CUS_INV_DELETE_DLV_ORDER()
+ Main Sub function of "CUS_INV_Delete_Dlv_order"
+ (called by "CUS_INV_Delete_Dlv_order")
- CUS_INV_Delete_Dlv_order_Validation()
+ Validation Check sub function of "CUS_INV_DELETE_DLV_ORDER" function
+ (called by "CUS_INV_CREATE_DLV_LOT")

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/10  Miracom         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_DELETE_DLV_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Dlv_order_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_DELETE_DLV_ORDER_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Dlv_order_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Dlv_order_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_Delete_Dlv_order()
- Delete Inv Dlv Lot Data
Return Value
- int : 0 (MP_TRUE)
Arguments
- CUS_INV_Delete_Dlv_order_In_Tag *CUS_INV_Delete_Dlv_order_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Dlv_order(TRSNode *in_node,
	TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_DELETE_DLV_ORDER_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_DELETE_DLV_ORDER", out_node);

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
CUS_INV_DELETE_DLV_ORDER_MAIN()
- Main sub function of "CUS_INV_DELETE_DLV_ORDER_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_DELETE_DLV_ORDER_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_DELETE_DLV_ORDER_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *delete_in_node;

	LOG_head("CUS_INV_DELETE_DLV_ORDER");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Delete_Dlv_order_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	delete_in_node = TRS.add_node(in_node, "delete_in_node");
	CopyDefaultMembers(delete_in_node, in_node);

	TRS.add_char(delete_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(delete_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));

	if (CUS_INV_Delete_Dlv_order_Before_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_DELETE_DLV_ORDER(s_msg_code, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Delete_Dlv_order_After_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_DELETE_DLV_ORDER()
- Main sub function of "CUS_INV_Delete_Dlv_order" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_DELETE_DLV_ORDER_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_DELETE_DLV_ORDER(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVDTL_TAG MINVDLVDTL;


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



	// MINVDLVDTL - 구매 입고 상세 정보 조회
	DBU_init_minvdlvdtl(&MINVDLVDTL);
	TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO), in_node, "DLV_NO");
	MINVDLVDTL.DLV_SEQ = TRS.get_int(in_node, "DLV_SEQ");

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

	/*
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
	*/

	// ERP 에서 삭제된 오더에 대해 인터페이스 안들어 오는경우때문에 mES에서 별도 삭제 가능하도록.
	// PROCSTEP : 1 -> PO 활성화
	// PROCSTEP : 2 -> PO 삭제
	if (TRS.get_procstep(in_node) == '1')
	{

		MINVDLVDTL.ERP_OPEN_YN = ' ';
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


		// MINVDLVLOT - 입하 자재 LOT 정보 조회
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO), in_node, "DLV_NO");
		MINVDLVLOT.DLV_SEQ = TRS.get_int(in_node, "DLV_SEQ");


	//	DBU_select_minvdlvlot(3, &MINVDLVLOT);

		d_total_qty = DBU_select_minvdlvlot_scalar(3, &MINVDLVLOT);

		//if (MINVDLVDTL.DLV_QTY < d_total_qty + TRS.get_double(in_node, "QTY"))
		if (0 == d_total_qty)
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


		MINVDLVDTL.ERP_OPEN_YN = 'Y';
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

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
CUS_INV_Delete_Dlv_order_Validation()
- Validation Check sub function of "CUS_INV_DELETE_DLV_ORDER" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_DELETE_DLV_ORDER_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Dlv_order_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	/*
	if(COM_service_validation(s_msg_code,
	in_node,
	out_node,
	TRS.get_procstep(in_node),
	"1") == MP_FALSE)
	{
	return MP_FALSE;
	}
	*/

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Delete_Dlv_order_Before_Transaction()
- Main sub function of "CUS_INV_DELETE_DLV_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Dlv_order_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Delete_Dlv_order_After_Transaction()
- Main sub function of "CUS_INV_DELETE_DLV_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Dlv_order_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}