/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_lot_info.c
Description : View Inv Lot Info

MES Version : 4.0.0

Function List
- CUS_INV_View_Lot_Info()
+ View Inv Lot Info
- CUS_INV_VIEW_LOT_INFO()
+ Main sub function of "CUS_INV_View_Lot_Info" function
+ Inv Lot Info definition
- CUS_INV_View_Lot_Info_Validation()
+ Validation Check sub function of "CUS_INV_VIEW_LOT_INFO" function

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

int CUS_INV_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Lot_Info()
- View Inv Lot Info
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VIEW_LOT_INFO(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VIEW_LOT_INFO", out_node);

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
CUS_INV_VIEW_LOT_INFO()
- Main sub function of "CUS_INV_View_Lot_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

    LOG_head("CUS_INV_View_Lot_Info");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Lot_Info_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DBU_init_minvlotsts(&MINVLOTSTS);
	TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "INV_LOT_ID");

    DBU_select_minvlotsts(1, &MINVLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

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

	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

    TRS.add_string(out_node, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
	TRS.add_string(out_node, "INV_LOT_TYPE", MINVLOTSTS.INV_LOT_TYPE, sizeof(MINVLOTSTS.INV_LOT_TYPE));
	TRS.add_string(out_node, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
	TRS.add_int(out_node, "MAT_VER", MWIPMATDEF.MAT_VER);
	TRS.add_string(out_node, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
	TRS.add_double(out_node, "QTY", MINVLOTSTS.QTY);
	TRS.add_string(out_node, "UNIT", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));
	TRS.add_string(out_node, "ORDER_ID", MINVLOTSTS.ORDER_ID, sizeof(MINVLOTSTS.ORDER_ID));
	TRS.add_string(out_node, "VENDOR_ID", MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
	TRS.add_int(out_node, "VENDOR_SITE_ID", MINVLOTSTS.VENDOR_SITE_ID);
	TRS.add_string(out_node, "VENDOR_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
	TRS.add_string(out_node, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
	TRS.add_string(out_node, "SUB_AREA_ID", MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
	TRS.add_string(out_node, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
	TRS.add_string(out_node, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
	TRS.add_char(out_node, "HOLD_FLAG", MINVLOTSTS.HOLD_FLAG);
	TRS.add_string(out_node, "INV_CMF_1", MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1));
	TRS.add_string(out_node, "INV_CMF_2", MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2));
	TRS.add_string(out_node, "INV_CMF_4", MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4));

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_View_Lot_Info_Validation()
- Validation Check sub function of "CUS_INV_VIEW_LOT_INFO" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
