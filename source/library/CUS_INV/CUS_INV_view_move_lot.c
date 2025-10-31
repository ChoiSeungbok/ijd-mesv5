/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_move_lot.c
Description : View Move Lot

MES Version : 4.0.0

Function List
- CUS_INV_View_Move_Lot()
+ View Move Lot
- CUS_INV_VIEW_MOVE_LOT()
+ Main sub function of "CUS_INV_View_Move_Lot" function
+ Move Lot definition
- CUS_INV_View_Move_Lot_Validation()
+ Validation Check sub function of "CUS_INV_VIEW_MOVE_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/16  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_View_Move_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_MOVE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Move_Lot()
- View Move Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Move_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VIEW_MOVE_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VIEW_MOVE_LOT", out_node);

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
CUS_INV_VIEW_MOVE_LOT()
- Main sub function of "CUS_INV_View_Move_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_MOVE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVMOVSTS_TAG MINVMOVSTS;
	struct MINVMOVLOT_TAG MINVMOVLOT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_INV_View_Move_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Move_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// MINVMOVSTS - 이동 지시 정보 조회
	DBU_init_minvmovsts(&MINVMOVSTS);
	TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "MOVE_ID");
	
	DBU_select_minvmovsts(1, &MINVMOVSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVMOVSTS SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// 불출 요청 마스터 상태 체크
	if (MINVMOVSTS.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
	{
		//INV-0063 : 이동 상태를 확인해주세요.
		strcpy(s_msg_code, "INV-0063");
		TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
		TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(MINVMOVSTS.MOVE_STATUS), MINVMOVSTS.MOVE_STATUS);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//FROM 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
	TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_FROM.OPER, MINVMOVSTS.OPER, sizeof(MINVMOVSTS.OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);

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

	// TO 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
	TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_TO.OPER, MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	//이동지시 상태
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_ORDER_STATUS, strlen(MP_WIP_ORDER_STATUS));
	memcpy(MGCMTBLDAT.KEY_1, MINVMOVSTS.MOVE_STATUS, sizeof(MINVMOVSTS.MOVE_STATUS));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

	TRS.add_string(out_node, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
	TRS.add_string(out_node, "FROM_OPER_DESC", MWIPOPRDEF_FROM.OPER_DESC, sizeof(MWIPOPRDEF_FROM.OPER_DESC));
	TRS.add_string(out_node, "TO_OPER_DESC", MWIPOPRDEF_TO.OPER_DESC, sizeof(MWIPOPRDEF_TO.OPER_DESC));
	TRS.add_string(out_node, "MOVE_STATUS", MINVMOVSTS.MOVE_STATUS, sizeof(MINVMOVSTS.MOVE_STATUS));
	TRS.add_string(out_node, "MOVE_STATUSDESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

	i_step = 2;

	// MINVMOVLOT - 이동 등록 LOT 조회
	DBU_init_minvmovlot(&MINVMOVLOT);
	TRS.copy(MINVMOVLOT.FACTORY, sizeof(MINVMOVLOT.FACTORY), in_node, IN_FACTORY);
	memcpy(MINVMOVLOT.MOVE_ID, MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
	DBU_open_minvmovlot(i_step, &MINVMOVLOT);

	if (DB_error_code != DB_SUCCESS)
	{
		//INV-0043 : 검색하신 정보는 존재하지 않습니다.
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "MINVMOVLOT OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
		TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	while (1)
	{
		DBU_fetch_minvmovlot(i_step, &MINVMOVLOT);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_minvmovlot(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVMOVLOT OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.21 minjae.go
			DBU_close_minvmovlot(i_step);
			//

			return MP_FALSE;
		}

		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVLOTSTS.INV_LOT_ID, MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
		DBU_select_minvlotsts(1, &MINVLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_dberrmsg(out_node, DB_error_msg);
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.21 minjae.go
			DBU_close_minvmovlot(i_step);
			//

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

			// 20.12.21 minjae.go
			DBU_close_minvmovlot(i_step);
			//
			

			return MP_FALSE;
		}

		list_item = TRS.add_node(out_node, "INV_LOT_LIST");

		TRS.add_string(list_item, "INV_LOT_ID", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
		TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
		TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "QTY", MINVMOVLOT.QTY);
		TRS.add_string(list_item, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_View_Move_Lot_Validation()
- Validation Check sub function of "CUS_INV_VIEW_MOVE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Move_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
