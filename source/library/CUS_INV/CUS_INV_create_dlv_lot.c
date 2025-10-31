/*******************************************************************************

	System      : MESplus
	Module      : CUS_INV
	File Name   : CUS_INV_create_dlv_lot.c
	Description : Create Inv Dlv_Lot Data

	MES Version : 5.2.0

	Function List
		- CUS_INV_Create_Dlv_Lot()
			+ Create Inv Dlv Lot Data
		- CUS_INV_CREATE_DLV_LOT()
			+ Main Sub function of "CUS_INV_Create_Dlv_Lot"
			+ (called by "CUS_INV_Create_Dlv__Lot")
		- CUS_INV_Create_Dlv_Lot_Validation()
			+ Validation Check sub function of "CUS_INV_CREATE_DLV_LOT" function
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
#include "CUS_WIP_common.h"

int CUS_INV_CREATE_DLV_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Create_Dlv_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_CREATE_DLV_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Create_Dlv_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_Create_Dlv_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
	CUS_INV_Create_Dlv_Lot()
		- Create Inv Dlv Lot Data
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- CUS_INV_Create_Dlv_Lot_In_Tag *CUS_INV_Create_Dlv_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Lot(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_CREATE_DLV_LOT_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_CREATE_DLV_LOT", out_node);

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
CUS_INV_CREATE_DLV_LOT_MAIN()
- Main sub function of "CUS_INV_CREATE_DLV_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CREATE_DLV_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_DLV_LOT_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct MGCMLAGDAT_TAG MGCMLAGDAT;
	TRSNode* create_in_node;
	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	char inv_dlv_lot_id[26];

	LOG_head("CUS_INV_CREATE_DLV_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Create_Dlv_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(inv_dlv_lot_id, ' ', sizeof(inv_dlv_lot_id));

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
	TRS.add_int(create_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
	TRS.add_double(create_in_node, "QTY", TRS.get_double(in_node, "QTY"));
	TRS.add_double(create_in_node, "QTY_2", TRS.get_double(in_node, "QTY_2"));
	TRS.add_double(create_in_node, "QTY_3", TRS.get_double(in_node, "QTY_3"));
	TRS.add_nstring(create_in_node, "DLV_NO", TRS.get_string(in_node, "DLV_NO"));
	TRS.add_int(create_in_node, "DLV_SEQ", TRS.get_int(in_node, "DLV_SEQ"));
	TRS.add_nstring(create_in_node, "DLV_TIME", TRS.get_string(in_node, "DLV_TIME"));
	TRS.add_nstring(create_in_node, "VENDOR_LOT_ID", TRS.get_string(in_node, "VENDOR_LOT_ID"));
	TRS.add_nstring(create_in_node, "COMMENT_1", TRS.get_string(in_node, "COMMENT_1"));

	if (COM_isnullspace(TRS.get_string(in_node, "DLV_LOT_ID")) == MP_FALSE)
	{
		memcpy(inv_dlv_lot_id, TRS.get_string(in_node, "DLV_LOT_ID"), strlen(TRS.get_string(in_node, "DLV_LOT_ID")));
	}
	else
	{
		//입하 LOT ID를 자재 LOT ID 룰로 변경
		DBU_init_mgcmlagdat(&MGCMLAGDAT);
		TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
		TRS.copy(MGCMLAGDAT.KEY_1, sizeof(MGCMLAGDAT.KEY_1), in_node, "VENDOR_ID");
		TRS.copy(MGCMLAGDAT.KEY_2, sizeof(MGCMLAGDAT.KEY_2), in_node, "VENDOR_SITE_ID");
		DBU_select_mgcmlagdat(3, &MGCMLAGDAT);

		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			TRS.add_fieldmsg(out_node, "MGCMLAGDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
			TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		gen_in_node = TRS.add_node(in_node, "gen_in_node");
		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_INV_LOT_ID, strlen(MP_ID_ROLE_INV_LOT_ID));
		TRS.add_string(gen_in_node, "LOT_ID", MGCMLAGDAT.DATA_1, 12);
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(inv_dlv_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);
	}

	TRS.add_string(create_in_node, "DLV_LOT_ID", inv_dlv_lot_id, sizeof(inv_dlv_lot_id));

	if (CUS_INV_Create_Dlv_Lot_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CREATE_DLV_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Create_Dlv_Lot_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	TRS.add_string(out_node, "DLV_LOT_ID", inv_dlv_lot_id, sizeof(inv_dlv_lot_id));

	return MP_TRUE;
}

/*******************************************************************************
	CUS_INV_CREATE_DLV_LOT()
		- Main sub function of "CUS_INV_Create_Dlv_Lot" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_INV_CREATE_DLV_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_DLV_LOT(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVLOT_TAG MINVDLVLOT_QTY;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MINVDLVLBL_TAG MINVDLVLBL;

	TRSNode* confirm_in_node;
	TRSNode* comment_in_node;

	TRSNode* cmn_out;

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

	// MWIPMATDEF - 제품 정보 조회
	DBU_init_mwipmatdef(&MWIPMATDEF);
	TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
	MWIPMATDEF.MAT_VER = TRS.get_int(in_node, "MAT_VER");
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

	// MINVDLVMST - 구매 입고 마스터 정보 조회
	DBU_init_minvdlvmst(&MINVDLVMST);
	TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO), in_node, "DLV_NO");
	DBU_select_minvdlvmst(1, &MINVDLVMST);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	//금형 자재의 경우, 수량은 1만 가능
	//MAT_CMF_9 : 금형 여부
	if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
	{
		// PDC 사업부는 수량 무조건 1이 아님.
		if (memcmp(MINVDLVMST.AREA_ID, gs_area_pdc, strlen(gs_area_pdc)) != 0)
		{
			if (TRS.get_double(in_node, "QTY") != 1)
			{
				strcpy(s_msg_code, "INV-0021");
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, TRS.get_double(in_node, "QTY"));

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
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

	// 수량 체크
	DBU_init_minvdlvlot(&MINVDLVLOT_QTY);
	TRS.copy(MINVDLVLOT_QTY.FACTORY, sizeof(MINVDLVLOT_QTY.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLOT_QTY.DLV_NO, sizeof(MINVDLVLOT_QTY.DLV_NO), in_node, "DLV_NO");
	MINVDLVLOT_QTY.DLV_SEQ = TRS.get_int(in_node, "DLV_SEQ");
	d_total_qty = DBU_select_minvdlvlot_scalar(2, &MINVDLVLOT_QTY);

	//if (MINVDLVDTL.DLV_QTY < d_total_qty + TRS.get_double(in_node, "QTY"))
	if (MINVDLVDTL.DLV_QTY < d_total_qty)
	{
		strcpy(s_msg_code, "INV-0021");
		TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVLOT_QTY.DLV_NO), MINVDLVLOT_QTY.DLV_NO);
		TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVLOT_QTY.DLV_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// MWIPOPRDEF - 수입 검사 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF.AREA_ID, MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
	memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_INSP, sizeof(MP_OPER_INSP));
	memcpy(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_IQC, sizeof(MP_INSP_TYPE_IQC));
	MWIPOPRDEF.INV_FLAG = 'Y';
	DBU_select_mwipoprdef(6, &MWIPOPRDEF);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// MINVDLVLOT - 입하 자재 LOT 생성
	DBU_init_minvdlvlot(&MINVDLVLOT);
	TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
	memcpy(MINVDLVLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
	MINVDLVLOT.MAT_VER = MWIPMATDEF.MAT_VER;
	MINVDLVLOT.QTY = TRS.get_double(in_node, "QTY");
	MINVDLVLOT.QTY_2 = TRS.get_double(in_node, "QTY_2");
	MINVDLVLOT.QTY_3 = TRS.get_double(in_node, "QTY_3");
	memcpy(MINVDLVLOT.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
	memcpy(MINVDLVLOT.UNIT_2, MWIPMATDEF.UNIT_2, sizeof(MWIPMATDEF.UNIT_2));
	memcpy(MINVDLVLOT.UNIT_3, MWIPMATDEF.UNIT_3, sizeof(MWIPMATDEF.UNIT_3));
	memcpy(MINVDLVLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
	memcpy(MINVDLVLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
	memcpy(MINVDLVLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
	TRS.copy(MINVDLVLOT.VENDOR_LOT_ID, sizeof(MINVDLVLOT.VENDOR_LOT_ID), in_node, "VENDOR_LOT_ID");
	memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVDLVLOT.DLV_LOT_STATUS));
	TRS.copy(MINVDLVLOT.DLV_TIME, sizeof(MINVDLVLOT.DLV_TIME), in_node, "DLV_TIME");
	memcpy(MINVDLVLOT.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO));
	MINVDLVLOT.DLV_SEQ = MINVDLVDTL.DLV_SEQ;
	memcpy(MINVDLVLOT.PO_NO, MINVDLVDTL.PO_NO, sizeof(MINVDLVDTL.PO_NO));
	MINVDLVLOT.PO_SEQ = MINVDLVDTL.PO_SEQ;
	memcpy(MINVDLVLOT.BL_NO, MINVDLVDTL.BL_NO, sizeof(MINVDLVDTL.BL_NO));
	MINVDLVLOT.BL_SEQ = MINVDLVDTL.BL_SEQ;
	MINVDLVLOT.PO_DISTRIBUTION_ID = MINVDLVDTL.PO_DISTRIBUTION_ID;
	memset(MINVDLVLOT.INSP_ID, ' ', sizeof(MINVDLVLOT.INSP_ID));
	memset(MINVDLVLOT.INSP_REQ_TIME, ' ', sizeof(MINVDLVLOT.INSP_REQ_TIME));
	memset(MINVDLVLOT.INSP_USER_ID, ' ', sizeof(MINVDLVLOT.INSP_USER_ID));
	memset(MINVDLVLOT.INSP_STATUS, ' ', sizeof(MINVDLVLOT.INSP_STATUS));
	MINVDLVLOT.INSP_RESULT_FLAG = ' ';
	TRS.copy(MINVDLVLOT.CREATE_USER_ID, sizeof(MINVDLVLOT.CREATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVDLVLOT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	// MINVDLVLOT - 입하 자재 LOT 생성
	DBU_insert_minvdlvlot(&MINVDLVLOT);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVDLVLOT INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	if (TRS.get_procstep(in_node) == '1')
	{
		//금형 자재 CONFIRM
//MAT_CMF_9 : 금형 여부
		if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
		{
			memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, sizeof(MINVDLVLOT.DLV_LOT_STATUS));

			DBU_update_minvdlvlot(1, &MINVDLVLOT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVLOT INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
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

			confirm_in_node = TRS.add_node(in_node, "confirm_in_node");
			TRS.add_char(confirm_in_node, IN_PROCSTEP, '1');
			CopyDefaultMembers(confirm_in_node, in_node);

			TRS.add_nstring(confirm_in_node, "LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
			//입하 LOT 확정 -> 수입 검사 요청
			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, confirm_in_node, cmn_out) == MP_FALSE)
			{
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{

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


		DBU_init_minvdlvlbl(&MINVDLVLBL);
		TRS.copy(MINVDLVLBL.FACTORY, sizeof(MINVDLVLBL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLBL.DLV_LOT_ID, sizeof(MINVDLVLBL.DLV_LOT_ID), in_node, "DLV_LOT_ID");
		TRS.copy(MINVDLVLBL.LABEL_ID, sizeof(MINVDLVLBL.LABEL_ID), in_node, "DLV_LOT_ID");
		DBU_select_minvdlvlbl(1, &MINVDLVLBL);
		if (DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "INV-0020");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		MINVDLVLBL.QTY = TRS.get_double(in_node, "QTY");
		MINVDLVLBL.QTY_2 = TRS.get_double(in_node, "QTY_2");
		MINVDLVLBL.QTY_3 = TRS.get_double(in_node, "QTY_3");

		TRS.copy(MINVDLVLBL.CREATE_USER_ID, sizeof(MINVDLVLBL.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLBL.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVDLVLBL.UPDATE_USER_ID, sizeof(MINVDLVLBL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLBL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		// MINVDLVLBL - 입고 자재 LABEL 생성
		DBU_insert_minvdlvlbl(&MINVDLVLBL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLBL INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


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



		comment_in_node = TRS.add_node(in_node, "confirm_in_node");
		TRS.add_char(comment_in_node, IN_PROCSTEP, '2');
		CopyDefaultMembers(comment_in_node, in_node);

		TRS.add_nstring(comment_in_node, "LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));

		TRS.add_nstring(comment_in_node, "COMMENT_1", TRS.get_string(in_node, "COMMENT_1"));
		//입하 LOT 확정 -> 비고란 추가
		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_UPDATE_LOT_COMMENT(s_msg_code, comment_in_node, cmn_out) == MP_FALSE)
		{
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);




		confirm_in_node = TRS.add_node(in_node, "confirm_in_node");
		TRS.add_char(confirm_in_node, IN_PROCSTEP, '1');
		CopyDefaultMembers(confirm_in_node, in_node);

		TRS.add_nstring(confirm_in_node, "LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
		//입하 LOT 확정 -> 수입 검사 요청
		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, confirm_in_node, cmn_out) == MP_FALSE)
		{
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);



	}



	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
	CUS_INV_Create_Dlv_Lot_Validation()
		- Validation Check sub function of "CUS_INV_CREATE_DLV_LOT" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_INV_CREATE_DLV_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	
	if(COM_service_validation(s_msg_code,
							  in_node,
							  out_node,
							  TRS.get_procstep(in_node),
							  "12") == MP_FALSE)
	{
		return MP_FALSE;
	}
	

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Dlv_Lot_Before_Transaction()
- Main sub function of "CUS_INV_CREATE_DLV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Dlv_Lot_After_Transaction()
- Main sub function of "CUS_INV_CREATE_DLV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}