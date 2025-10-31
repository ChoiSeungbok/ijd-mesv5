/*******************************************************************************

System      : MESplus
Module      : CUS_SHP
File Name   : CUS_SHP_view_order_list.c
Description : 출하 지시 조회

MES Version : 4.0.0

Function List
-

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

int CUS_SHP_View_Order_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_VIEW_ORDER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_View_Order_List()
- View Ship Order List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Order_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_VIEW_ORDER_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_View_Order_List", out_node);

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
CUS_SHP_VIEW_ORDER_LIST()
- Main sub function of "CUS_SHP_View_Order_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_VIEW_ORDER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{  
    struct CSHPORDMST_TAG CSHPORDMST;
    struct CSHPORDDTL_TAG CSHPORDDTL;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct CPAKORDSTS_TAG CPAKORDSTS;

    TRSNode *list_item;

    int i_step;
    double d_reg_qty =0;

    LOG_head("CUS_SHP_View_Order_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_SHP_View_Order_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");

	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

    i_step = 2;

    //출하지시 마스터 정보 조회
    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_cshpordmst(&CSHPORDMST);
        TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID), in_node, "AREA_ID");
        TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");

        DBU_open_cshpordmst(i_step, &CSHPORDMST);
        if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "CSHPORDMST OPEN", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CSHPORDMST.AREA_ID), CSHPORDMST.AREA_ID);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSHPORDMST.OPER), CSHPORDMST.OPER);
            TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_cshpordmst(i_step, &CSHPORDMST);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_cshpordmst(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //INV-0043 : 검색하신 정보는 존재하지 않습니다.
                strcpy(s_msg_code, "INV-0043");
                TRS.add_fieldmsg(out_node, "CSHPORDMST FETCH", DT_NOVALUESTRING);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_cshpordmst(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_SHIP_ORDER_ID", CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));

                DBU_close_cshpordmst(i_step);
                break;
            }

            list_item = TRS.add_node(out_node, "ORDER_TBL");
            TRS.add_string(list_item, "SHIP_ORDER_ID", CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
            TRS.add_string(list_item, "SHIP_ORD_DATE", CSHPORDMST.SHIP_ORD_DATE, sizeof(CSHPORDMST.SHIP_ORD_DATE));
            TRS.add_string(list_item, "CUSTOMER_ID", CSHPORDMST.CUSTOMER_ID, sizeof(CSHPORDMST.CUSTOMER_ID));
			TRS.add_string(list_item, "CUSTOMER_NUMBER", CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
			TRS.add_string(list_item, "CUSTOMER_NAME", CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
            TRS.add_string(list_item, "AREA_ID", CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
            TRS.add_string(list_item, "OPER", CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
            TRS.add_string(list_item, "DELIVERY", CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
			TRS.add_int(list_item, "DELIVERY_ID", CSHPORDMST.DELIVERY_ID);
			TRS.add_string(list_item, "DELIVERY_NAME", CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
            TRS.add_string(list_item, "DELIVERY_LOCATION", CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
            TRS.add_string(list_item, "DELIVERY_PHONE_NO", CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
            TRS.add_string(list_item, "DELIVERY_USER_ID", CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
            TRS.add_string(list_item, "SHIP_ORD_STATUS", CSHPORDMST.SHIP_ORD_STATUS, sizeof(CSHPORDMST.SHIP_ORD_STATUS));
			TRS.add_char(list_item, "DELETE_FLAG", CSHPORDMST.DELETE_FLAG);
          
            //사업부 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, CSHPORDMST.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

            //공정 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
            memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
        }

    }
    // 출하지시 상세 정보 조회
    else if (TRS.get_procstep(in_node) == '2')
    {
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

        DBU_init_cshporddtl(&CSHPORDDTL);
        TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");

        DBU_open_cshporddtl(i_step, &CSHPORDDTL);
        if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "CSHPORDDTL OPEN", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_cshporddtl(i_step, &CSHPORDDTL);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_cshporddtl(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //INV-0043 : 검색하신 정보는 존재하지 않습니다.
                strcpy(s_msg_code, "INV-0043");
                TRS.add_fieldmsg(out_node, "CSHPORDDTL FETCH", DT_NOVALUESTRING);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_cshporddtl(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_int(out_node, "NEXT_SEQ", CSHPORDDTL.SEQ);

                DBU_close_cshporddtl(i_step);
                break;
            }

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CSHPORDDTL.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CSHPORDDTL.MAT_VER;
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

			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CSHPORDDTL.PACK_ORDER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CSHPORDDTL.PACK_LINE_NO;
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

            list_item = TRS.add_node(out_node, "ORDER_TBL");
            TRS.add_string(list_item, "SHIP_ORDER_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
            TRS.add_int(list_item, "SEQ", CSHPORDDTL.SEQ);
            TRS.add_string(list_item, "MAT_ID", CSHPORDDTL.MAT_ID, sizeof(CSHPORDDTL.MAT_ID));
            TRS.add_int(list_item, "MAT_VER", CSHPORDDTL.MAT_VER);
			TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "SHIP_ORD_STATUS", CSHPORDDTL.SHIP_ORD_STATUS, sizeof(CSHPORDDTL.SHIP_ORD_STATUS));
            TRS.add_string(list_item, "PACK_ORDER_ID", CSHPORDDTL.PACK_ORDER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
            TRS.add_int(list_item, "PACK_LINE_NO", CSHPORDDTL.PACK_LINE_NO);
			TRS.add_string(list_item, "CMF_1", CPAKORDSTS.CMF_1, sizeof(CPAKORDSTS.CMF_1));
            TRS.add_double(list_item, "QTY", CSHPORDDTL.QTY);
			TRS.add_double(list_item, "SHIPPED_QTY", CSHPORDDTL.SHIPPED_QTY);
            TRS.add_string(list_item, "UNIT", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
			TRS.add_char(list_item, "DELETE_FLAG", CSHPORDDTL.DELETE_FLAG);
        }
    }
	// 출하지시 상세 정보 조회 (PDA) 
	// HM 사업부 - 포장 LOT까지 같이 조회
	// 이외 사업부 - DTL 정보만 조회
	else if (TRS.get_procstep(in_node) == '3')
	{
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

		DBU_init_cshporddtl(&CSHPORDDTL);
		TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");

		DBU_open_cshporddtl(3, &CSHPORDDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CSHPORDDTL OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cshporddtl(3, &CSHPORDDTL);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cshporddtl(3);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CSHPORDDTL FETCH", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cshporddtl(3);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CSHPORDDTL.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CSHPORDDTL.MAT_VER;
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
			memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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

			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CSHPORDDTL.PACK_ORDER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CSHPORDDTL.PACK_LINE_NO;
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

            //출하등록된 수량
            DBU_init_cpaklotsts(&CPAKLOTSTS);
            TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
            memcpy(CPAKLOTSTS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
            CPAKLOTSTS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
            d_reg_qty = DBU_select_cpaklotsts_scalar(27, &CPAKLOTSTS);

			list_item = TRS.add_node(out_node, "ORDER_TBL_PDA");
			TRS.add_string(list_item, "SHIP_ORDER_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
			TRS.add_int(list_item, "SEQ", CSHPORDDTL.SEQ);
			TRS.add_string(list_item, "MAT_ID", CSHPORDDTL.MAT_ID, sizeof(CSHPORDDTL.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", CSHPORDDTL.MAT_VER);
			TRS.add_string(list_item, "MAT_DESC", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
			TRS.add_string(list_item, "SHIP_ORD_STATUS", CSHPORDDTL.SHIP_ORD_STATUS, sizeof(CSHPORDDTL.SHIP_ORD_STATUS));
			TRS.add_string(list_item, "PACK_ORDER_ID", CSHPORDDTL.PACK_ORDER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
			TRS.add_int(list_item, "PACK_LINE_NO", CSHPORDDTL.PACK_LINE_NO);
			TRS.add_double(list_item, "QTY", CSHPORDDTL.QTY);
			TRS.add_double(list_item, "SHIPPED_QTY", CSHPORDDTL.SHIPPED_QTY);
			TRS.add_string(list_item, "UNIT", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
			TRS.add_string(list_item, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_double(list_item, "REG_QTY", d_reg_qty);
		}

		TRS.add_string(out_node, "AREA_ID", CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));

		if (memcmp(CSHPORDMST.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
		{
			i_step = 8;

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
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
					//INV-0043 : 검색하신 정보는 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0043");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cpaklotsts(i_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//제품 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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

				list_item = TRS.add_node(out_node, "SHIP_LOT_TBL_PDA");

				TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
				TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
				TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
				TRS.add_string(list_item, "DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
				TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
				TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
				TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
				TRS.add_string(list_item, "SHIP_ORDER_ID", CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			}
		}
	}
	// 출하지시 상세 정보에 해당하는 출하 LOT 조회 (PDA) 
	// HM 이외의 사업부에서만 리턴값 존재
	else if (TRS.get_procstep(in_node) == '4')
	{
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

		if (memcmp(CSHPORDMST.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) != 0)
		{
			// 출하 지시 마스터 정보 조회
			DBU_init_cshporddtl(&CSHPORDDTL);
			TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			CSHPORDDTL.SEQ = TRS.get_int(in_node, "SEQ");
			DBU_select_cshporddtl(1, &CSHPORDDTL);

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

			i_step = 9;

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			CPAKLOTSTS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
			DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
				TRS.add_fieldmsg(out_node, "SEQ", MP_DBL, CPAKLOTSTS.SHIP_ORDER_SEQ);
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
					//INV-0043 : 검색하신 정보는 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0043");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cpaklotsts(i_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//제품 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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

				//주문지시 조회 ( 라벨명 가져오기 위함)
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






				list_item = TRS.add_node(out_node, "SHIP_LOT_LIST");

				TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
				TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
				TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
				TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(list_item, "DESC", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
				TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
				TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
				TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
				TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
				TRS.add_string(list_item, "SHIP_ORDER_ID", CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			}
		}
	}
	// 출하지시 확정 정보 조회 (PDA) 
	// HM 사업부 - 포장 LOT까지 같이 조회
	// 이외 사업부 - DTL 정보만 조회
	else if (TRS.get_procstep(in_node) == '5')
	{
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

		DBU_init_cshporddtl(&CSHPORDDTL);
		TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");

		DBU_open_cshporddtl(i_step, &CSHPORDDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CSHPORDDTL OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cshporddtl(i_step, &CSHPORDDTL);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cshporddtl(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CSHPORDDTL FETCH", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cshporddtl(i_step);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CSHPORDDTL.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CSHPORDDTL.MAT_VER;
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
			memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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

			list_item = TRS.add_node(out_node, "ORDER_TBL_PDA");
			TRS.add_string(list_item, "SHIP_ORDER_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
			TRS.add_int(list_item, "SEQ", CSHPORDDTL.SEQ);
			TRS.add_string(list_item, "MAT_ID", CSHPORDDTL.MAT_ID, sizeof(CSHPORDDTL.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", CSHPORDDTL.MAT_VER);
			TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "SHIP_ORD_STATUS", CSHPORDDTL.SHIP_ORD_STATUS, sizeof(CSHPORDDTL.SHIP_ORD_STATUS));
			TRS.add_string(list_item, "PACK_ORDER_ID", CSHPORDDTL.PACK_ORDER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
			TRS.add_int(list_item, "PACK_LINE_NO", CSHPORDDTL.PACK_LINE_NO);
			TRS.add_double(list_item, "QTY", CSHPORDDTL.QTY);
			TRS.add_double(list_item, "SHIPPED_QTY", CSHPORDDTL.SHIPPED_QTY);
			TRS.add_string(list_item, "UNIT", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
			TRS.add_string(list_item, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		}

		if (memcmp(CSHPORDMST.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
		{
			i_step = 10;

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
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
					//INV-0043 : 검색하신 정보는 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0043");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cpaklotsts(i_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//제품 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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

				list_item = TRS.add_node(out_node, "SHIP_LOT_TBL_PDA");

				TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
				TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
				TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
				TRS.add_string(list_item, "DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
				TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
				TRS.add_string(list_item, "BOX_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
				TRS.add_string(list_item, "FINAL_BOX_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
				TRS.add_string(list_item, "SHIP_ORDER_ID", CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			}
		}
	}
	// 출하지시 확정 - 상세 정보에 해당하는 출하 LOT 조회 (PDA) 
	// HM 이외의 사업부에서만 리턴값 존재
	else if (TRS.get_procstep(in_node) == '6')
	{
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

		if (memcmp(CSHPORDMST.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) != 0)
		{
			// 출하 지시 마스터 정보 조회
			DBU_init_cshporddtl(&CSHPORDDTL);
			TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			CSHPORDDTL.SEQ = TRS.get_int(in_node, "SEQ");
			DBU_select_cshporddtl(1, &CSHPORDDTL);

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

			i_step = 11;

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
			CPAKLOTSTS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
			DBU_open_cpaklotsts(i_step, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
				TRS.add_fieldmsg(out_node, "SEQ", MP_DBL, CPAKLOTSTS.SHIP_ORDER_SEQ);
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
					//INV-0043 : 검색하신 정보는 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0043");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cpaklotsts(i_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//제품 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, CSHPORDMST.OPER, sizeof(CSHPORDMST.OPER));
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
				TRS.add_string(list_item, "SHIP_ORDER_ID", CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			}
		}
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_View_Order_List_Validation()
- Validation Check sub function of "CUS_SHP_VIEW_ORDER_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Order_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
    in_node,
    out_node,
    TRS.get_procstep(in_node),
    "123456") == MP_FALSE)
    {
    return MP_FALSE;
    }

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
