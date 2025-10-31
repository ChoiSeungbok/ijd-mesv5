/*******************************************************************************

System      : MESplus
Module      : CUS_SHP
File Name   : CUS_SHP_view_return_lot_list.c
Description : View Return Lot List

MES Version : 4.0.0

Function List
- CUS_SHP_View_Return_Lot_List()
+ View Return Lot List
- CUS_SHP_VIEW_RETURN_LOT_LIST()
+ Main sub function of "CUS_SHP_View_Return_Lot_List" function
+ Return Lot definition
- CUS_SHP_View_Return_Lot_List_Validation()
+ Validation Check sub function of "CUS_SHP_VIEW_RETURN_LOT_LIST" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/14  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_View_Return_Lot_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_VIEW_RETURN_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_View_Return_Lot_List()
- View Return Lot List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Return_Lot_List(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_SHP_VIEW_RETURN_LOT_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_SHP_VIEW_RETURN_LOT_LIST", out_node);

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
CUS_SHP_VIEW_RETURN_LOT_LIST()
- Main sub function of "CUS_SHP_View_Return_Lot_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_VIEW_RETURN_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRETORDSTS_TAG CRETORDSTS;
	struct CRETLOTSTS_TAG CRETLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CPAKORDSTS_TAG CPAKORDSTS;

    TRSNode *list_item;
	int i_step = 0;
	char erp_order_no[25];

    LOG_head("CUS_SHP_View_Return_Lot_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_SHP_View_Return_Lot_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");

	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

	DBU_init_cretordsts(&CRETORDSTS);
	TRS.copy(CRETORDSTS.FACTORY, sizeof(CRETORDSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CRETORDSTS.CMF_1, sizeof(CRETORDSTS.RET_ORDER_ID), in_node, "RET_ORDER_ID");
	TRS.copy(CRETORDSTS.MAT_ID, sizeof(CRETORDSTS.MAT_ID), in_node, "MAT_ID");
	TRS.copy(CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID), in_node, "AREA_ID");
	TRS.copy(CRETORDSTS.CUSTOMER_ID, sizeof(CRETORDSTS.CUSTOMER_ID), in_node, "CUSTOMER_ID");

    DBU_open_cretordsts(2, &CRETORDSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "CRETORDSTS OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETORDSTS.FACTORY), CRETORDSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.CMF_1), CRETORDSTS.CMF_1);
        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CRETORDSTS.MAT_ID), CRETORDSTS.MAT_ID);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CRETORDSTS.AREA_ID), CRETORDSTS.AREA_ID);
		TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(CRETORDSTS.CUSTOMER_ID), CRETORDSTS.CUSTOMER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_cretordsts(2, &CRETORDSTS);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_cretordsts(2);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CRETORDSTS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETORDSTS.FACTORY), CRETORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.CMF_1), CRETORDSTS.CMF_1);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CRETORDSTS.MAT_ID), CRETORDSTS.MAT_ID);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CRETORDSTS.AREA_ID), CRETORDSTS.AREA_ID);
			TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(CRETORDSTS.CUSTOMER_ID), CRETORDSTS.CUSTOMER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.22 minjae.go
			DBU_close_cretordsts(2);
			//

			return MP_FALSE;
        }

		//제품 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, CRETORDSTS.MAT_ID, sizeof(CRETORDSTS.MAT_ID));
		MWIPMATDEF.MAT_VER = CRETORDSTS.MAT_VER;
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
			DBU_close_cretordsts(2);
			//

			return MP_FALSE;
		}

		i_step = 2;

		DBU_init_cretlotsts(&CRETLOTSTS);
		TRS.copy(CRETLOTSTS.FACTORY, sizeof(CRETLOTSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CRETLOTSTS.RET_ORDER_ID, CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));
		DBU_open_cretlotsts(i_step, &CRETLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CRETLOTSTS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETLOTSTS.FACTORY), CRETLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETLOTSTS.RET_ORDER_ID), CRETLOTSTS.RET_ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.22 minjae.go
			DBU_close_cretordsts(2);
			//

			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cretlotsts(2, &CRETLOTSTS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cretlotsts(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CRETLOTSTS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETLOTSTS.FACTORY), CRETLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETLOTSTS.RET_ORDER_ID), CRETLOTSTS.RET_ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.22 minjae.go
				DBU_close_cretlotsts(i_step);
				DBU_close_cretordsts(2);
				//

				return MP_FALSE;
			}

			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CRETLOTSTS.PACK_ORDER_ID, sizeof(CRETLOTSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CRETLOTSTS.PACK_LINE_NO;
			DBU_select_cpakordsts(1, &CPAKORDSTS);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

				// 20.12.22 minjae.go
				DBU_close_cretlotsts(i_step);
				DBU_close_cretordsts(2);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "RETURN_LOT_LIST");

			TRS.add_string(list_item, "RET_ORDER_ID", CRETLOTSTS.CMF_1, sizeof(CRETLOTSTS.CMF_1));	//ERP 반품지시
			TRS.add_string(list_item, "LOT_ID", CRETLOTSTS.LOT_ID, sizeof(CRETLOTSTS.LOT_ID));
			TRS.add_string(list_item, "RET_LOT_ID", CRETLOTSTS.RET_LOT_ID, sizeof(CRETLOTSTS.RET_LOT_ID));
			TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_double(list_item, "QTY", CRETLOTSTS.QTY);
			TRS.add_string(list_item, "UNIT", CRETLOTSTS.UNIT, sizeof(CRETLOTSTS.UNIT));
			TRS.add_string(list_item, "RET_DATE", CRETLOTSTS.RET_DATE, sizeof(CRETLOTSTS.RET_DATE));
			TRS.add_int(list_item, "RET_LINE_NO", CRETLOTSTS.RET_LINE_NO);
			TRS.add_string(list_item, "AREA_ID", CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID));
			TRS.add_string(list_item, "CUSTOMER_ID", CRETORDSTS.CUSTOMER_ID, sizeof(CRETORDSTS.CUSTOMER_ID));
			TRS.add_string(list_item, "CUSTOMER_NAME", CRETORDSTS.CUSTOMER_NAME, sizeof(CRETORDSTS.CUSTOMER_NAME));
			TRS.add_string(list_item, "PACK_DATE", CRETLOTSTS.PACK_DATE, sizeof(CRETLOTSTS.PACK_DATE));
			TRS.add_string(list_item, "PACK_ORDER_ID", CRETLOTSTS.PACK_ORDER_ID, sizeof(CRETLOTSTS.PACK_ORDER_ID));
			TRS.add_int(list_item, "PACK_LINE_NO", CRETLOTSTS.PACK_LINE_NO);

			if (DB_error_code == DB_NOT_FOUND)
			{
				memset(erp_order_no, ' ', sizeof(erp_order_no));
				TRS.add_string(list_item, "CMF_1", erp_order_no, sizeof(erp_order_no));
			}
			else
			{
				TRS.add_string(list_item, "CMF_1", CPAKORDSTS.CMF_1, sizeof(CPAKORDSTS.CMF_1));
			}

			TRS.add_string(list_item, "SHIP_DATE", CRETLOTSTS.SHIP_DATE, sizeof(CRETLOTSTS.SHIP_DATE));
			TRS.add_string(list_item, "SHIP_ORDER_ID", CRETLOTSTS.SHIP_ORDER_ID, sizeof(CRETLOTSTS.SHIP_ORDER_ID));
			TRS.add_double(list_item, "SHIP_ORDER_SEQ", CRETLOTSTS.SHIP_ORDER_SEQ);
			TRS.add_string(list_item, "CMF_1", CRETLOTSTS.RET_ORDER_ID, sizeof(CRETLOTSTS.RET_ORDER_ID));	
		}
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_View_Return_Lot_List_Validation()
- Validation Check sub function of "CUS_SHP_VIEW_RETURN_LOT_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Return_Lot_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
