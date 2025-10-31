/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_lot_history_list.c
Description : 자재 LOT 이력 조회

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/11  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_INV_common.h"

int CUS_INV_View_Lot_History_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_LOT_HISTORY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Lot_History_List()
- View Inv Lot History
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_History_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_VIEW_LOT_HISTORY_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_View_Oper_List", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    if (i_ret == MP_TRUE)
    {
        if (gb_multi_transaction == MP_FALSE)
        {
            DB_commit();
        }
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_VIEW_LOT_HISTORY_LIST()
- Main sub function of "CUS_INV_View_Lot_History_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_LOT_HISTORY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{  
    struct MINVLOTHIS_TAG MINVLOTHIS;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보

    TRSNode *list_item;

    int i_step;

    LOG_head("CUS_INV_View_Lot_History_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Lot_History_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    i_step = 2;

    DBU_init_minvlothis(&MINVLOTHIS);
    TRS.copy(MINVLOTHIS.FACTORY, sizeof(MINVLOTHIS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MINVLOTHIS.INV_LOT_ID, sizeof(MINVLOTHIS.INV_LOT_ID), in_node, "INV_LOT_ID");

    DBU_open_minvlothis(i_step, &MINVLOTHIS);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "MINVLOTHIS OPEN", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHIS.INV_LOT_ID), MINVLOTHIS.INV_LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_minvlothis(i_step, &MINVLOTHIS);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_minvlothis(i_step);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "MINVLOTHIS FETCH", DT_NOVALUESTRING);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            DBU_close_minvlothis(i_step);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (COM_check_node_length(out_node) == MP_FALSE)
        {
            TRS.add_int(out_node, "NEXT_HIST_SEQ", MINVLOTHIS.HIST_SEQ);

            DBU_close_minvlothis(i_step);
            break;
        }

        list_item = TRS.add_node(out_node, "LOT_TBL");
        TRS.add_string(list_item, "INV_LOT_ID", MINVLOTHIS.INV_LOT_ID, sizeof(MINVLOTHIS.INV_LOT_ID));
        TRS.add_int(list_item, "HIST_SEQ", MINVLOTHIS.HIST_SEQ);
        TRS.add_string(list_item, "TRAN_CODE", MINVLOTHIS.TRAN_CODE, sizeof(MINVLOTHIS.TRAN_CODE));
        TRS.add_string(list_item, "TRAN_USER_ID", MINVLOTHIS.TRAN_USER_ID, sizeof(MINVLOTHIS.TRAN_USER_ID));
        TRS.add_string(list_item, "TRAN_TIME", MINVLOTHIS.TRAN_TIME, sizeof(MINVLOTHIS.TRAN_TIME));
        TRS.add_string(list_item, "INV_LOT_STATUS", MINVLOTHIS.INV_LOT_STATUS, sizeof(MINVLOTHIS.INV_LOT_STATUS));
        TRS.add_char(list_item, "INV_LOT_PRIORITY", MINVLOTHIS.INV_LOT_PRIORITY);
        TRS.add_string(list_item, "MAT_ID", MINVLOTHIS.MAT_ID, sizeof(MINVLOTHIS.MAT_ID));
        TRS.add_int(list_item, "MAT_VER", MINVLOTHIS.MAT_VER);
        TRS.add_double(list_item, "QTY", MINVLOTHIS.QTY);
        TRS.add_string(list_item, "UNIT", MINVLOTHIS.UNIT, sizeof(MINVLOTHIS.UNIT));
        TRS.add_string(list_item, "VENDOR_ID", MINVLOTHIS.VENDOR_ID, sizeof(MINVLOTHIS.VENDOR_ID));
		TRS.add_int(list_item, "VENDOR_SITE_ID", MINVLOTHIS.VENDOR_SITE_ID);
        TRS.add_string(list_item, "VENDOR_LOT_ID", MINVLOTHIS.VENDOR_LOT_ID, sizeof(MINVLOTHIS.VENDOR_LOT_ID));
        TRS.add_string(list_item, "AREA_ID", MINVLOTHIS.AREA_ID, sizeof(MINVLOTHIS.AREA_ID));
        TRS.add_string(list_item, "SUB_AREA_ID", MINVLOTHIS.SUB_AREA_ID, sizeof(MINVLOTHIS.SUB_AREA_ID));
        TRS.add_string(list_item, "OPER", MINVLOTHIS.OPER, sizeof(MINVLOTHIS.OPER));
        TRS.add_string(list_item, "LOT_ID", MINVLOTHIS.LOT_ID, sizeof(MINVLOTHIS.LOT_ID));
        TRS.add_string(list_item, "RECV_DATE", MINVLOTHIS.RECV_DATE, sizeof(MINVLOTHIS.RECV_DATE));
        TRS.add_double(list_item, "RECV_QTY", MINVLOTHIS.RECV_QTY);
        TRS.add_char(list_item, "DELETE_FLAG", MINVLOTHIS.DELETE_FLAG);
        TRS.add_string(list_item, "DELETE_CODE", MINVLOTHIS.DELETE_CODE, sizeof(MINVLOTHIS.DELETE_CODE));
        TRS.add_string(list_item, "DELETE_TIME", MINVLOTHIS.DELETE_TIME, sizeof(MINVLOTHIS.DELETE_TIME));
        TRS.add_char(list_item, "HOLD_FLAG", MINVLOTHIS.HOLD_FLAG);
        TRS.add_string(list_item, "HOLD_CODE", MINVLOTHIS.HOLD_CODE, sizeof(MINVLOTHIS.HOLD_CODE));
        TRS.add_char(list_item, "INSP_FLAG", MINVLOTHIS.INSP_FLAG);
        TRS.add_string(list_item, "INSP_ID", MINVLOTHIS.INSP_ID, sizeof(MINVLOTHIS.INSP_ID));
        TRS.add_char(list_item, "INSP_RESULT_FLAG", MINVLOTHIS.INSP_RESULT_FLAG);
        TRS.add_string(list_item, "DLV_NO", MINVLOTHIS.DLV_NO, sizeof(MINVLOTHIS.DLV_NO));
        TRS.add_int(list_item, "DLV_SEQ", MINVLOTHIS.DLV_SEQ);
        TRS.add_string(list_item, "PO_NO", MINVLOTHIS.PO_NO, sizeof(MINVLOTHIS.PO_NO));
        TRS.add_int(list_item, "PO_SEQ", MINVLOTHIS.PO_SEQ);
        TRS.add_string(list_item, "INV_CMF_1", MINVLOTHIS.INV_CMF_1, sizeof(MINVLOTHIS.INV_CMF_1));
        TRS.add_string(list_item, "INV_CMF_2", MINVLOTHIS.INV_CMF_2, sizeof(MINVLOTHIS.INV_CMF_2));
        TRS.add_string(list_item, "INV_CMF_3", MINVLOTHIS.INV_CMF_3, sizeof(MINVLOTHIS.INV_CMF_3));
        TRS.add_string(list_item, "INV_CMF_4", MINVLOTHIS.INV_CMF_4, sizeof(MINVLOTHIS.INV_CMF_4));
        TRS.add_string(list_item, "INV_CMF_5", MINVLOTHIS.INV_CMF_5, sizeof(MINVLOTHIS.INV_CMF_5));
        TRS.add_string(list_item, "INV_CMF_6", MINVLOTHIS.INV_CMF_6, sizeof(MINVLOTHIS.INV_CMF_6));
        TRS.add_string(list_item, "INV_CMF_7", MINVLOTHIS.INV_CMF_7, sizeof(MINVLOTHIS.INV_CMF_7));
		TRS.add_char(list_item, "LOAD_FLAG", MINVLOTHIS.LOAD_FLAG);
		TRS.add_string(list_item, "LOT_ID", MINVLOTHIS.LOT_ID, sizeof(MINVLOTHIS.LOT_ID));
		TRS.add_string(list_item, "RES_ID", MINVLOTHIS.RES_ID, sizeof(MINVLOTHIS.RES_ID));
		TRS.add_string(list_item, "ORDER_ID", MINVLOTHIS.ORDER_ID, sizeof(MINVLOTHIS.ORDER_ID));
        TRS.add_string(list_item, "INV_CMF_8", MINVLOTHIS.INV_CMF_8, sizeof(MINVLOTHIS.INV_CMF_8));
        TRS.add_string(list_item, "INV_CMF_9", MINVLOTHIS.INV_CMF_9, sizeof(MINVLOTHIS.INV_CMF_9));
        TRS.add_string(list_item, "INV_CMF_10", MINVLOTHIS.INV_CMF_10, sizeof(MINVLOTHIS.INV_CMF_10));
        TRS.add_string(list_item, "INV_CMF_11", MINVLOTHIS.INV_CMF_11, sizeof(MINVLOTHIS.INV_CMF_11));
        TRS.add_string(list_item, "INV_CMF_12", MINVLOTHIS.INV_CMF_12, sizeof(MINVLOTHIS.INV_CMF_12));
        TRS.add_string(list_item, "INV_CMF_13", MINVLOTHIS.INV_CMF_13, sizeof(MINVLOTHIS.INV_CMF_13));
        TRS.add_string(list_item, "INV_CMF_14", MINVLOTHIS.INV_CMF_14, sizeof(MINVLOTHIS.INV_CMF_14));
        TRS.add_string(list_item, "INV_CMF_15", MINVLOTHIS.INV_CMF_15, sizeof(MINVLOTHIS.INV_CMF_15));
        TRS.add_string(list_item, "INV_CMF_16", MINVLOTHIS.INV_CMF_16, sizeof(MINVLOTHIS.INV_CMF_16));
        TRS.add_string(list_item, "INV_CMF_17", MINVLOTHIS.INV_CMF_17, sizeof(MINVLOTHIS.INV_CMF_17));
        TRS.add_string(list_item, "INV_CMF_18", MINVLOTHIS.INV_CMF_18, sizeof(MINVLOTHIS.INV_CMF_18));
        TRS.add_string(list_item, "INV_CMF_19", MINVLOTHIS.INV_CMF_19, sizeof(MINVLOTHIS.INV_CMF_19));
        TRS.add_string(list_item, "INV_CMF_20", MINVLOTHIS.INV_CMF_20, sizeof(MINVLOTHIS.INV_CMF_20));
        TRS.add_string(list_item, "ORG_INV_LOT_ID", MINVLOTHIS.ORG_INV_LOT_ID, sizeof(MINVLOTHIS.ORG_INV_LOT_ID));
        TRS.add_string(list_item, "OLD_MAT_ID", MINVLOTHIS.OLD_MAT_ID, sizeof(MINVLOTHIS.OLD_MAT_ID));
        TRS.add_string(list_item, "OLD_AREA_ID", MINVLOTHIS.OLD_AREA_ID, sizeof(MINVLOTHIS.OLD_AREA_ID));
        TRS.add_string(list_item, "OLD_SUB_AREA_ID", MINVLOTHIS.OLD_SUB_AREA_ID, sizeof(MINVLOTHIS.OLD_SUB_AREA_ID));
        TRS.add_string(list_item, "OLD_OPER", MINVLOTHIS.OLD_OPER, sizeof(MINVLOTHIS.OLD_OPER));
        TRS.add_double(list_item, "OLD_QTY", MINVLOTHIS.OLD_QTY);
        TRS.add_string(list_item, "OLD_UNIT", MINVLOTHIS.OLD_UNIT, sizeof(MINVLOTHIS.OLD_UNIT));
        TRS.add_string(list_item, "CREATE_TIME", MINVLOTHIS.CREATE_TIME, sizeof(MINVLOTHIS.CREATE_TIME));
        TRS.add_string(list_item, "UPDATE_TIME", MINVLOTHIS.UPDATE_TIME, sizeof(MINVLOTHIS.UPDATE_TIME));
        TRS.add_char(list_item, "HIST_DEL_FLAG", MINVLOTHIS.HIST_DEL_FLAG);

        //제품 조회
        DBU_init_mwipmatdef(&MWIPMATDEF);
        TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPMATDEF.MAT_ID, MINVLOTHIS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
        MWIPMATDEF.MAT_VER = MINVLOTHIS.MAT_VER;
        DBU_select_mwipmatdef(1, &MWIPMATDEF);

        TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));

        //사업부 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, MINVLOTHIS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MINVLOTHIS.AREA_ID, sizeof(MINVLOTHIS.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

        //사업장 조회(null이 아닌경우)
        if (COM_isnullspace(MINVLOTHIS.SUB_AREA_ID) == MP_FALSE)
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MINVLOTHIS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MINVLOTHIS.SUB_AREA_ID, sizeof(MINVLOTHIS.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
        }

        //공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPOPRDEF.OPER, MINVLOTHIS.OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));

        //이전 제품 조회
        DBU_init_mwipmatdef(&MWIPMATDEF);
        TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPMATDEF.MAT_ID, MINVLOTHIS.OLD_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
        MWIPMATDEF.MAT_VER = MINVLOTHIS.MAT_VER;
        DBU_select_mwipmatdef(1, &MWIPMATDEF);

        TRS.add_string(list_item, "OLD_MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));

        //이전 사업부 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, MINVLOTHIS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MINVLOTHIS.OLD_AREA_ID, sizeof(MINVLOTHIS.OLD_AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_string(list_item, "OLD_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

        //이전 작업장 조회(null이 아닌경우)
        if (COM_isnullspace(MINVLOTHIS.OLD_SUB_AREA_ID) == MP_FALSE)
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MINVLOTHIS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MINVLOTHIS.OLD_SUB_AREA_ID, sizeof(MINVLOTHIS.OLD_SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "OLD_SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
        }

        //이전 공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPOPRDEF.OPER, MINVLOTHIS.OLD_OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        TRS.add_string(list_item, "OLD_OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
    }
    
    return MP_TRUE;
}



/*******************************************************************************
CUS_INV_View_Lot_History_List_Validation()
- Validation Check sub function of "CUS_INV_VIEW_Lot_HISTORY_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_History_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
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

    if (COM_isnullspace(TRS.get_string(in_node, "INV_LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    return MP_TRUE;
}
