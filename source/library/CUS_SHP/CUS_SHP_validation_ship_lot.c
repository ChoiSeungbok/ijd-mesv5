/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_SHP_validation_ship_lot.c
Description : Validation Ship Lot

MES Version : 4.0.0

Function List
- CUS_SHP_Validation_Ship_Lot()
+ Validation Ship Lot
- CUS_SHP_VALIDATION_SHIP_LOT()
+ Main sub function of "CUS_SHP_Validation_Ship_Lot" function
+ Ship Lot definition
- CUS_SHP_Validation_Ship_Lot_Validation()
+ Validation Check sub function of "CUS_SHP_VALIDATION_SHIP_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/16  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_Validation_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_VALIDATION_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_Validation_Ship_Lot()
- Validation Ship Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Validation_Ship_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_SHP_VALIDATION_SHIP_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_SHP_VALIDATION_SHIP_LOT", out_node);

	if (i_ret == MP_TRUE)
	{
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
		DB_commit();
	}
	else
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_VALIDATION_SHIP_LOT()
- Main sub function of "CUS_SHP_Validation_Ship_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_VALIDATION_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct CSHPORDMST_TAG CSHPORDMST;
	struct CSHPORDDTL_TAG CSHPORDDTL;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;

	TRSNode *list_item;
	int i_step = 0;
	double d_pack_lot_qty = 0;

	LOG_head("CUS_SHP_Validation_Ship_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_SHP_Validation_Ship_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 출하 지시 마스터 정보 조회
	DBU_init_cshpordmst(&CSHPORDMST);
	TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
	DBU_select_cshpordmst(1, &CSHPORDMST);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CSHPORDMST SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSHPORDMST.FACTORY), CSHPORDMST.FACTORY);
		TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// 출하 지시 마스터 상태 체크
	// 출하 -> WAIT 상태에서 가능
	if (memcmp(CSHPORDMST.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
	{
		strcpy(s_msg_code, "WIP-0575");
		TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// PROCSTEP : 1 -> LOT ID 스캔
	// PROCSTEP : 2 -> BOX ID 스캔
	// PROCSTEP : 3 -> FINAL BOX ID 스캔
	if (TRS.get_procstep(in_node) == '1')
	{
		// MWIPLOTSTSX - 포장 LOT 정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "PACK_LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 포장 LOT 잠금 여부 체크
		if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
		{
			// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 삭제 여부 체크
		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKLOTSTS - 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), in_node, "PACK_LOT_ID");
		DBU_select_cpaklotsts(3, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 포장 LOT 포장 상태 체크
		// 출하 -> PACK_FLAG(Y) 상태에서 가능
		if (CPAKLOTSTS.PACK_FLAG != 'Y')
		{
			// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0576");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 출하 상태 체크
		// 출하 -> SHIP_FLAG(N) 상태에서 가능
		if (CPAKLOTSTS.SHIP_FLAG != 'N')
		{
			// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0569");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKORDSTS - 포장 지시 정보 조회
		DBU_init_cpakordsts(&CPAKORDSTS);
		TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
		CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
		DBU_select_cpakordsts(1, &CPAKORDSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 출하 지시 상세 정보 조회
		DBU_init_cshporddtl(&CSHPORDDTL);
		TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
		memcpy(CSHPORDDTL.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
		CSHPORDDTL.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
		DBU_select_cshporddtl(3, &CSHPORDDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CSHPORDDTL SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSHPORDDTL.FACTORY), CSHPORDDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
			TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 출하 지시 상세 상태 체크
		// 출하 -> WAIT 상태에서 가능
		if (memcmp(CSHPORDDTL.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
		{
			strcpy(s_msg_code, "WIP-0575");
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
			TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//제품 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
		MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;
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

		list_item = TRS.add_node(out_node, "SHIP_LOT_LIST");

		TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
		TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
		TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(list_item, "DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
		TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
		TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
		TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), in_node, "BOX_ID");
		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(10, &CPAKLOTSTS);

		// BOX에 매핑된 LOT ID 잠금 여부 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(11, &CPAKLOTSTS);
		// BOX에 매핑된 LOT ID 삭제 여부 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(2) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(12, &CPAKLOTSTS);
		// BOX에 매핑된 LOT 포장 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0576");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(3) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(13, &CPAKLOTSTS);
		// BOX에 매핑된 LOT 출하 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0569");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(4) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(15, &CPAKLOTSTS);
		// BOX에 매핑된 출하 지시 상세 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0575");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		i_step = 6;
		// CPAKLOTSTS - BOX 매핑 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), in_node, "BOX_ID");
		DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0567 : 해당 포장지시는 포장정보가 없습니다.
			strcpy(s_msg_code, "WIP-0586");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cpaklotsts(i_step, &CPAKLOTSTS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cpaklotsts(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0567 : 해당 포장지시는 포장정보가 없습니다.
				strcpy(s_msg_code, "WIP-0586");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				// 20.12.22 minjae.go
				DBU_close_cpaklotsts(i_step);
				//

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;
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

				// 20.12.22 minjae.go
				DBU_close_cpaklotsts(i_step);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "SHIP_LOT_LIST");

			TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
			TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_string(list_item, "DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
			TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
			TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), in_node, "FINAL_BOX_ID");
		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(16, &CPAKLOTSTS);

		// BOX에 매핑된 LOT ID 잠금 여부 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(17, &CPAKLOTSTS);
		// BOX에 매핑된 LOT ID 삭제 여부 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(2) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(18, &CPAKLOTSTS);
		// BOX에 매핑된 LOT 포장 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0576");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(3) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(19, &CPAKLOTSTS);
		// BOX에 매핑된 LOT 출하 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0569");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(4) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		d_pack_lot_qty = DBU_select_cpaklotsts_scalar(21, &CPAKLOTSTS);
		// BOX에 매핑된 출하 지시 상세 상태 체크
		if (d_pack_lot_qty > 0)
		{
			strcpy(s_msg_code, "WIP-0575");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		i_step = 7;
		// CPAKLOTSTS - BOX 매핑 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), in_node, "FINAL_BOX_ID");
		DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0567 : 해당 포장지시는 포장정보가 없습니다.
			strcpy(s_msg_code, "WIP-0586");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cpaklotsts(i_step, &CPAKLOTSTS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cpaklotsts(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0567 : 해당 포장지시는 포장정보가 없습니다.
				strcpy(s_msg_code, "WIP-0586");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.22 minjae.go
				DBU_close_cpaklotsts(i_step);
				//

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;
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

				// 20.12.22 minjae.go
				DBU_close_cpaklotsts(i_step);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "SHIP_LOT_LIST");

			TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
			TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_string(list_item, "DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
			TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
			TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
		}
	}


	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Validation_Ship_Lot_Validation()
- Validation Check sub function of "CUS_SHP_VALIDATION_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Validation_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	/* ProcStep Validation */
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
