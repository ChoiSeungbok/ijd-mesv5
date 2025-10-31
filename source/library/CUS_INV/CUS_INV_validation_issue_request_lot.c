/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_validation_issue_request_lot.c
Description : Validation Issue Request Lot

MES Version : 4.0.0

Function List
- CUS_INV_Validation_Issue_Request_Lot()
+ Validation Issue Request Lot
- CUS_INV_VALIDATION_ISSUE_REQUEST_LOT()
+ Main sub function of "CUS_INV_Validation_Issue_Request_Lot" function
+ Issue Request definition
- CUS_INV_Validation_Issue_Request_Lot_Validation()
+ Validation Check sub function of "CUS_INV_VALIDATION_ISSUE_REQUEST_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/16  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_Validation_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VALIDATION_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_Validation_Issue_Request_Lot()
- Validation Issue Request Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Validation_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VALIDATION_ISSUE_REQUEST_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VALIDATION_ISSUE_REQUEST_LOT", out_node);

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
CUS_INV_VALIDATION_ISSUE_REQUEST_LOT()
- Main sub function of "CUS_INV_Validation_Issue_Request_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VALIDATION_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVLOTSTS_TAG MINVLOTSTS;

    TRSNode *list_item;

    LOG_head("CUS_INV_Validation_Issue_Request_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_Validation_Issue_Request_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// MINVREQMST - 불출 요청 마스터 정보 조회
	DBU_init_minvreqmst(&MINVREQMST);
	TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
	DBU_select_minvreqmst(1, &MINVREQMST);
	if (DB_error_code != DB_SUCCESS)
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

	// PROCSTEP : 1 -> 자재 불출 등록 자재 LOT 스캔 체크
	// PROCSTEP : 2 -> 자재 인수 자재 LOT 스캔 체크
	if (TRS.get_procstep(in_node) == '1')
	{
		// 불출 요청 마스터 상태 체크
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) != 0
			&& memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
		{
			strcpy(s_msg_code, "INV-0027");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQLOT - 불출 등록 LOT 조회
		DBU_init_minvreqlot(&MINVREQLOT);
		TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
		TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), in_node, "REQ_LOT_ID");
		DBU_select_minvreqlot(2, &MINVREQLOT);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (DB_error_code != DB_NOT_FOUND)
		{
			//INV-0044 : 해당 자재는 이미 등록되었습니다.
			strcpy(s_msg_code, "INV-0044");
			TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 정보 조회
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "REQ_LOT_ID");
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
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT LOAD 체크
		if (MINVLOTSTS.LOAD_FLAG == 'Y')
		{
			//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
			strcpy(s_msg_code, "INV-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
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

		// MINVREQDTL - 불출 요청 상세 정보 조회
		DBU_init_minvreqdtl(&MINVREQDTL);
		TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO), in_node, "REQ_NO");
		memcpy(MINVREQDTL.REQ_MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
		MINVREQDTL.REQ_MAT_VER = MINVLOTSTS.MAT_VER;
		DBU_select_minvreqdtl(1, &MINVREQDTL);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
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
			TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 불출 요청 상세 정보 상태 체크
		if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) != 0
			&& memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
		{
			strcpy(s_msg_code, "INV-0027");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQDTL.REQ_STATUS), MINVREQDTL.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		list_item = TRS.add_node(out_node, "REQ_LOT_LIST");

		TRS.add_string(list_item, "REQ_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		TRS.add_string(list_item, "REQ_MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(list_item, "REQ_MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "REQ_QTY", MINVLOTSTS.QTY);
		TRS.add_string(list_item, "UNIT", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));
		TRS.add_string(list_item, "REQ_STATUS", " ", strlen(" "));
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		// 불출 요청 마스터 상태 체크
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, strlen(MP_CINV_ISSUE_COMPLETED)) == 0)
		{
			//INV-0058 : 해당 자재 불출 요청은 이미 완료되었습니다.
			strcpy(s_msg_code, "INV-0058");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQLOT - 불출 등록 LOT 조회
		DBU_init_minvreqlot(&MINVREQLOT);
		TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
		TRS.copy(MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID), in_node, "REQ_MAT_ID");
		MINVREQLOT.REQ_MAT_VER = TRS.get_int(in_node, "REQ_MAT_VER");
		TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), in_node, "REQ_LOT_ID");
		DBU_select_minvreqlot(3, &MINVREQLOT);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 불출 요청 LOT 상태 체크
		if (memcmp(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, strlen(MP_CINV_ISSUE_ISSUE)) != 0)
		{
			strcpy(s_msg_code, "INV-0035");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQLOT.REQ_STATUS), MINVREQLOT.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQDTL - 불출 요청 상세 정보 조회
		DBU_init_minvreqdtl(&MINVREQDTL);
		TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO), in_node, "REQ_NO");
		memcpy(MINVREQDTL.REQ_MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
		MINVREQDTL.REQ_MAT_VER = MINVREQLOT.REQ_MAT_VER;
		DBU_select_minvreqdtl(1, &MINVREQDTL);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 불출 요청 마스터 상태 체크
		if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, strlen(MP_CINV_ISSUE_COMPLETED)) == 0)
		{
			//INV-0058 : 해당 자재 불출 요청은 이미 완료되었습니다.
			strcpy(s_msg_code, "INV-0058");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQDTL.REQ_STATUS), MINVREQDTL.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		// 자재 LOT 정보 조회
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "REQ_LOT_ID");
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
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//제품 조회
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

		list_item = TRS.add_node(out_node, "REQ_LOT_LIST");

		TRS.add_string(list_item, "REQ_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		TRS.add_string(list_item, "REQ_MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(list_item, "REQ_MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "REQ_QTY", MINVLOTSTS.QTY);
		TRS.add_string(list_item, "UNIT", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));
		TRS.add_string(list_item, "REQ_STATUS", MINVREQLOT.REQ_STATUS, sizeof(MINVREQLOT.REQ_STATUS));
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Validation_Issue_Request_Lot_Validation()
- Validation Check sub function of "CUS_INV_VALIDATION_ISSUE_REQUEST_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Validation_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
