/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_validation_dlv_lot.c
Description : Validation Dlv Lot

MES Version : 4.0.0

Function List
- CUS_INV_Validation_Dlv_Lot()
+ Validation Dlv Lot
- CUS_INV_VALIDATION_DLV_LOT()
+ Main sub function of "CUS_INV_Validation_Dlv_Lot" function
+ Dlv Lot definition
- CUS_INV_Validation_Dlv_Lot_Validation()
+ Validation Check sub function of "CUS_INV_VALIDATION_DLV_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/17  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_Validation_Dlv_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VALIDATION_DLV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_Validation_Dlv_Lot()
- Validation Dlv Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Validation_Dlv_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VALIDATION_DLV_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VALIDATION_DLV_LOT", out_node);

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
CUS_INV_VALIDATION_DLV_LOT()
- Main sub function of "CUS_INV_Validation_Dlv_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VALIDATION_DLV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVLBL_TAG MINVDLVLBL;
	struct MWIPMATDEF_TAG MWIPMATDEF;

    TRSNode *list_item;
	int i_step = 0;

    LOG_head("CUS_INV_Validation_Dlv_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_Validation_Dlv_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
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

	// 입하 LOT 수입검사 상태 체크
	//if (memcmp(MINVDLVLOT.INSP_STATUS, MP_CQMS_STATUS_COMPLETE, strlen(MP_CQMS_STATUS_COMPLETE)) != 0)
	if(MINVDLVLOT.INSP_STATUS[0] != MP_CQMS_STATUS_COMPLETE)
	{
		//INV-0047 : 이 입하 자재 LOT은 수입 검사가 진행중입니다.
		strcpy(s_msg_code, "INV-0047");
		TRS.add_fieldmsg(out_node, "CUS_INV_VALIDATION_DLV_LOT", MP_NVST);
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
		strcpy(s_msg_code, "INV-0037");
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
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
	memcpy(MWIPMATDEF.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
	MWIPMATDEF.MAT_VER = MINVDLVLOT.MAT_VER;
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
	memcpy(MINVDLVMST.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
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

	// 수입 검사 결과 정보
	TRS.add_string(out_node, "INSP_ID", MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID));
	TRS.add_char(out_node, "INSP_RESULT_FLAG", MINVDLVLOT.INSP_RESULT_FLAG);
	TRS.add_string(out_node, "INSP_REQ_TIME", MINVDLVLOT.INSP_REQ_TIME, sizeof(MINVDLVLOT.INSP_REQ_TIME));
	TRS.add_string(out_node, "INSP_USER_ID", MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID));

	i_step = 2;

	DBU_init_minvdlvlbl(&MINVDLVLBL);
	TRS.copy(MINVDLVLBL.FACTORY, sizeof(MINVDLVLBL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLBL.DLV_LOT_ID, sizeof(MINVDLVLBL.DLV_LOT_ID), in_node, "DLV_LOT_ID");
	DBU_open_minvdlvlbl(i_step, &MINVDLVLBL);

	if (DB_error_code != DB_SUCCESS)
	{
		//INV-0043 : 검색하신 정보는 존재하지 않습니다.
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "MINVDLVLBL OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLBL.FACTORY), MINVDLVLBL.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	while (1)
	{
		DBU_fetch_minvdlvlbl(i_step, &MINVDLVLBL);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_minvdlvlbl(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVDLVLBL OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLBL.FACTORY), MINVDLVLBL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.21 minjae.go
			DBU_close_minvdlvlbl(i_step);
			//

			return MP_FALSE;
		}

		list_item = TRS.add_node(out_node, "DLV_LBL_LIST");

		// 입고 자재 라벨(LOT) 정보
		TRS.add_string(list_item, "LABEL_ID", MINVDLVLBL.LABEL_ID, sizeof(MINVDLVLBL.LABEL_ID));
		TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "QTY", MINVDLVLBL.QTY);
		TRS.add_string(list_item, "UNIT", MINVDLVLOT.UNIT, sizeof(MINVDLVLOT.UNIT));
	}
	
    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Validation_Dlv_Lot_Validation()
- Validation Check sub function of "CUS_INV_VALIDATION_DLV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Validation_Dlv_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
