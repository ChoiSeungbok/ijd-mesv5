/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_lot_issue_list.c
Description : View Inv Lot Issue List

MES Version : 4.0.0

Function List
- CUS_INV_View_Lot_Issue_List()
+ View Inv Lot Issue List
- CUS_INV_VIEW_LOT_ISSUE_LIST()
+ Main sub function of "CUS_INV_View_Lot_Issue_List" function
+ Unload Lot definition
- CUS_INV_View_Lot_Issue_List_Validation()
+ Validation Check sub function of "CUS_INV_VIEW_LOT_ISSUE_LIST" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/10  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_View_Lot_Issue_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_LOT_ISSUE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Lot_Issue_List()
- View Inv Lot Issue List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_Issue_List(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VIEW_LOT_ISSUE_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VIEW_LOT_ISSUE_LIST", out_node);

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
CUS_INV_VIEW_LOT_ISSUE_LIST()
- Main sub function of "CUS_INV_View_Lot_Issue_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_LOT_ISSUE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MINVMATISS_TAG MINVMATISS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_INV_View_Lot_Issue_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Lot_Issue_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");

	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

    i_step = 2;

	DBU_init_minvmatiss(&MINVMATISS);
	TRS.copy(MINVMATISS.FACTORY, sizeof(MINVMATISS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVMATISS.INV_LOT_ID, sizeof(MINVMATISS.INV_LOT_ID), in_node, "INV_LOT_ID");
	TRS.copy(MINVMATISS.REQ_MAT_ID, sizeof(MINVMATISS.REQ_MAT_ID), in_node, "REQ_MAT_ID");
	TRS.copy(MINVMATISS.AREA_ID, sizeof(MINVMATISS.AREA_ID), in_node, "AREA_ID");
	TRS.copy(MINVMATISS.TO_OPER, sizeof(MINVMATISS.TO_OPER), in_node, "TO_OPER");

    DBU_open_minvmatiss(i_step, &MINVMATISS);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "MINVMATISS OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMATISS.FACTORY), MINVMATISS.FACTORY);
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVMATISS.INV_LOT_ID), MINVMATISS.INV_LOT_ID);
        TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVMATISS.REQ_MAT_ID), MINVMATISS.REQ_MAT_ID);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVMATISS.AREA_ID), MINVMATISS.AREA_ID);
		TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MINVMATISS.TO_OPER), MINVMATISS.TO_OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_minvmatiss(i_step, &MINVMATISS);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_minvmatiss(i_step);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVMATISS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMATISS.FACTORY), MINVMATISS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVMATISS.INV_LOT_ID), MINVMATISS.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVMATISS.REQ_MAT_ID), MINVMATISS.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVMATISS.AREA_ID), MINVMATISS.AREA_ID);
			TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MINVMATISS.TO_OPER), MINVMATISS.TO_OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.21 minjae.go
			DBU_close_minvmatiss(i_step);
			//

			return MP_FALSE;
        }

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MINVMATISS.OPER, sizeof(MINVMATISS.OPER));
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

			// 20.12.21 minjae.go
			DBU_close_minvmatiss(i_step);
			//

			return MP_FALSE;
		}

		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_TO.OPER, MINVMATISS.TO_OPER, sizeof(MINVMATISS.TO_OPER));
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

			// 20.12.21 minjae.go
			DBU_close_minvmatiss(i_step);
			//

			return MP_FALSE;
		}

        list_item = TRS.add_node(out_node, "ISSUE_LIST");

        TRS.add_string(list_item, "INV_LOT_ID", MINVMATISS.INV_LOT_ID, sizeof(MINVMATISS.INV_LOT_ID));
		TRS.add_string(list_item, "REQ_NO", MINVMATISS.REQ_NO, sizeof(MINVMATISS.REQ_NO));
		TRS.add_string(list_item, "REQ_MAT_ID", MINVMATISS.REQ_MAT_ID, sizeof(MINVMATISS.REQ_MAT_ID));
		TRS.add_int(list_item, "REQ_MAT_VER", MINVMATISS.REQ_MAT_VER);
		TRS.add_string(list_item, "REQ_MAT_DESC", MINVMATISS.TRAN_COMMENT, sizeof(MINVMATISS.TRAN_COMMENT));
		TRS.add_string(list_item, "ISSUE_TIME", MINVMATISS.ISSUE_TIME, sizeof(MINVMATISS.ISSUE_TIME));
		TRS.add_double(list_item, "ISSUE_QTY", MINVMATISS.ISSUE_QTY);
		TRS.add_string(list_item, "UNIT", MINVMATISS.UNIT, sizeof(MINVMATISS.UNIT));
		TRS.add_string(list_item, "AREA_ID", MINVMATISS.AREA_ID, sizeof(MINVMATISS.AREA_ID));
		TRS.add_string(list_item, "SUB_AREA_ID", MINVMATISS.SUB_AREA_ID, sizeof(MINVMATISS.SUB_AREA_ID));
		TRS.add_string(list_item, "OPER", MINVMATISS.OPER, sizeof(MINVMATISS.OPER));
		TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		TRS.add_string(list_item, "TO_AREA_ID", MINVMATISS.TO_AREA_ID, sizeof(MINVMATISS.TO_AREA_ID));
		TRS.add_string(list_item, "TO_SUB_AREA_ID", MINVMATISS.TO_SUB_AREA_ID, sizeof(MINVMATISS.TO_SUB_AREA_ID));
		TRS.add_string(list_item, "TO_OPER", MINVMATISS.TO_OPER, sizeof(MINVMATISS.TO_OPER));
		TRS.add_string(list_item, "TO_OPER_DESC", MWIPOPRDEF_TO.OPER_DESC, sizeof(MWIPOPRDEF_TO.OPER_DESC));
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_View_Lot_Issue_List_Validation()
- Validation Check sub function of "CUS_INV_VIEW_LOT_ISSUE_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_Issue_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
