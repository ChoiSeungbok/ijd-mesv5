/*******************************************************************************

System      : MESplus
Module      : CUS_SHP
File Name   : CUS_SHP_view_ship_lot_list.c
Description : 제품 출하 LOT 현황 조회

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

int CUS_SHP_View_Ship_Lot_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_VIEW_SHIP_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_View_Ship_Lot_List()
- View Ship Lot List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Ship_Lot_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_VIEW_SHIP_LOT_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_View_Ship_Lot_List", out_node);

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
CUS_SHP_VIEW_SHIP_LOT_LIST()
- Main sub function of "CUS_SHP_View_Ship_Lot_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_VIEW_SHIP_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CSHPORDMST_TAG CSHPORDMST;
    struct CPAKLOTSTS_TAG CPAKLOTSTS;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보
	struct CPAKORDSTS_TAG CPAKORDSTS;

    TRSNode *list_item;

    int i_step, l_step;

    LOG_head("CUS_SHP_View_Shipping_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_SHP_View_Ship_Lot_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");
	
	if (COM_isnullspace(TRS.get_string(in_node, "MAT_DESC")) == MP_TRUE)
	{
		DBC_Q_COND.KEY_1[0] = '%';
	}
	else
	{
		TRS.copy(DBC_Q_COND.KEY_1, sizeof(DBC_Q_COND.KEY_1), in_node, "MAT_DESC");
	}


	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

    i_step = 2;

    //출하지시 마스터 정보 조회
    DBU_init_cshpordmst(&CSHPORDMST);
    TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID), in_node, "AREA_ID");
    TRS.copy(CSHPORDMST.CUSTOMER_ID, sizeof(CSHPORDMST.CUSTOMER_ID), in_node, "CUSTOMER_ID");
    TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");    
    CSHPORDMST.DELIVERY_ID = TRS.get_int(in_node, "DELIVERY_ID");
           
    DBU_open_cshpordmst(i_step, &CSHPORDMST);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "CSHPORDMST OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CSHPORDMST.AREA_ID), CSHPORDMST.AREA_ID);
        TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(CSHPORDMST.CUSTOMER_ID), CSHPORDMST.CUSTOMER_ID);
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
            TRS.add_fieldmsg(out_node, "CSHPORDMST FETCH", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CSHPORDMST.AREA_ID), CSHPORDMST.AREA_ID);
            TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(CSHPORDMST.CUSTOMER_ID), CSHPORDMST.CUSTOMER_ID);
            TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;


			DBU_close_cshpordmst(i_step);
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //사업부 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, CSHPORDMST.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT.KEY_1, CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
                 
        l_step = 5;

        DBU_init_cpaklotsts(&CPAKLOTSTS);
        TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
        memcpy(CPAKLOTSTS.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
        TRS.copy(CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID), in_node, "MAT_ID");
        TRS.copy(CPAKLOTSTS.CMF_5, sizeof(CPAKLOTSTS.CMF_5), in_node, "ERP_PACK_ORDER_ID");
        CPAKLOTSTS.SHIP_FLAG = 'Y';

        DBU_open_cpaklotsts(l_step, &CPAKLOTSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
            TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CPAKLOTSTS.MAT_ID), CPAKLOTSTS.MAT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;
			DBU_close_cshpordmst(i_step);
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_cpaklotsts(l_step, &CPAKLOTSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_cpaklotsts(l_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //INV-0043 : 검색하신 정보는 존재하지 않습니다.
                strcpy(s_msg_code, "INV-0043");
                TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
                TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CPAKLOTSTS.MAT_ID), CPAKLOTSTS.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;


				DBU_close_cpaklotsts(l_step);
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));

                DBU_close_cpaklotsts(l_step);
                break;
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
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				DBU_close_cshpordmst(i_step);
				DBU_close_cpaklotsts(l_step);
                return MP_FALSE;
            }

			// 주문 지시 조회
			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
			DBU_select_cpakordsts(1, &CPAKORDSTS);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				DBU_close_cshpordmst(i_step);
				DBU_close_cpaklotsts(l_step);
				return MP_FALSE;
			}

            list_item = TRS.add_node(out_node, "LOT_TBL");

            TRS.add_string(list_item, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
            TRS.add_string(list_item, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			TRS.add_string(list_item, "CMF_2", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
            TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_double(list_item, "QTY", CPAKLOTSTS.QTY);
            TRS.add_string(list_item, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
            TRS.add_string(list_item, "AREA_ID", CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_string(list_item, "CUSTOMER_ID", CSHPORDMST.CUSTOMER_ID, sizeof(CSHPORDMST.CUSTOMER_ID));
			TRS.add_string(list_item, "CUSTOMER_NAME", CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
            TRS.add_int(list_item, "DELIVERY_ID", CPAKORDSTS.DELIVERY_ID);
            TRS.add_string(list_item, "DELIVERY_NAME", CPAKORDSTS.DELIVERY_NAME, sizeof(CPAKORDSTS.DELIVERY_NAME));
            TRS.add_char(list_item, "PACK_FLAG", CPAKLOTSTS.PACK_FLAG);
            TRS.add_string(list_item, "PACK_DATE", CPAKLOTSTS.PACK_DATE, sizeof(CPAKLOTSTS.PACK_DATE));
            TRS.add_string(list_item, "PACK_ORDER_ID", CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
            TRS.add_int(list_item, "PACK_LINE_NO", CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_string(list_item, "PACK_ORD_DATE", CPAKORDSTS.PACK_ORD_DATE, sizeof(CPAKORDSTS.PACK_ORD_DATE));
			TRS.add_string(list_item, "CMF_5", CPAKLOTSTS.CMF_5, sizeof(CPAKLOTSTS.CMF_5));
            TRS.add_char(list_item, "SHIP_FLAG", CPAKLOTSTS.SHIP_FLAG);
            TRS.add_string(list_item, "SHIP_DATE", CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
            TRS.add_string(list_item, "SHIP_ORDER_ID", CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
            TRS.add_double(list_item, "SHIP_ORDER_SEQ", CPAKLOTSTS.SHIP_ORDER_SEQ);
            TRS.add_string(list_item, "BOX_ID_1", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
            TRS.add_string(list_item, "BOX_ID_2", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
        }
    }
    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_View_Ship_Lot_List_Validation()
- Validation Check sub function of "CUS_SHP_VIEW_SHIP_LOT_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_View_Ship_Lot_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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

    if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }
    return MP_TRUE;
}
