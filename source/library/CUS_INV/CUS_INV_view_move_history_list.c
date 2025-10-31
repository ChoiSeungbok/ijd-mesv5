/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_move_history_list.c
Description : 자재 이동 현황 조회

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/10  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_INV_common.h"

int CUS_INV_View_Move_History_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_MOVE_HISTORY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Move_History_List()
- View Move History
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Move_History_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_VIEW_MOVE_HISTORY_LIST(s_msg_code, in_node, out_node);

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
CUS_INV_VIEW_MOVE_HISTORY_LIST()
- Main sub function of "CUS_INV_View_Move_History_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_MOVE_HISTORY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MINVLOTMVH_TAG MINVLOTMVH;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보

    TRSNode *list_item;

    int i_step;

    LOG_head("CUS_INV_View_Move_History_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Move_History_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }  


	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");

	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

    i_step = 2;

    DBU_init_minvlotmvh(&MINVLOTMVH);
    TRS.copy(MINVLOTMVH.FACTORY, sizeof(MINVLOTMVH.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MINVLOTMVH.AREA_ID, sizeof(MINVLOTMVH.AREA_ID), in_node, "AREA_ID");
    TRS.copy(MINVLOTMVH.OPER, sizeof(MINVLOTMVH.OPER), in_node, "OPER");
    TRS.copy(MINVLOTMVH.TO_OPER, sizeof(MINVLOTMVH.TO_OPER), in_node, "TO_OPER");
    TRS.copy(MINVLOTMVH.MAT_ID, sizeof(MINVLOTMVH.MAT_ID), in_node, "MAT_ID");
    TRS.copy(MINVLOTMVH.INV_LOT_ID, sizeof(MINVLOTMVH.INV_LOT_ID), in_node, "INV_LOT_ID");

    DBU_open_minvlotmvh(i_step, &MINVLOTMVH);
    if (DB_error_code != DB_SUCCESS)
    {
        //INV-0043 : 검색하신 정보는 존재하지 않습니다.
        strcpy(s_msg_code, "INV-0043");
        TRS.add_fieldmsg(out_node, "MINVLOTMVH OPEN", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVLOTMVH.AREA_ID), MINVLOTMVH.AREA_ID);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTMVH.OPER), MINVLOTMVH.OPER);
        TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MINVLOTMVH.TO_OPER), MINVLOTMVH.TO_OPER);
        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTMVH.MAT_ID), MINVLOTMVH.MAT_ID);
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTMVH.INV_LOT_ID), MINVLOTMVH.INV_LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_minvlotmvh(i_step, &MINVLOTMVH);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_minvlotmvh(i_step);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "MINVLOTMVH FETCH", DT_NOVALUESTRING);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            DBU_close_minvlotmvh(i_step);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (COM_check_node_length(out_node) == MP_FALSE)
        {
            TRS.add_string(out_node, "NEXT_INV_LOT_ID", MINVLOTMVH.INV_LOT_ID, sizeof(MINVLOTMVH.INV_LOT_ID));

            DBU_close_minvlotmvh(i_step);
            break;
        }

        list_item = TRS.add_node(out_node, "MVH_TBL");
        TRS.add_string(list_item, "INV_LOT_ID", MINVLOTMVH.INV_LOT_ID, sizeof(MINVLOTMVH.INV_LOT_ID));
        TRS.add_int(list_item, "HIST_SEQ", MINVLOTMVH.HIST_SEQ);
        TRS.add_string(list_item, "TRAN_CODE", MINVLOTMVH.TRAN_CODE, sizeof(MINVLOTMVH.TRAN_CODE));
        TRS.add_string(list_item, "TRAN_USER_ID", MINVLOTMVH.TRAN_USER_ID, sizeof(MINVLOTMVH.TRAN_USER_ID));
        TRS.add_string(list_item, "TRAN_TIME", MINVLOTMVH.TRAN_TIME, sizeof(MINVLOTMVH.TRAN_TIME));
        TRS.add_string(list_item, "MAT_ID", MINVLOTMVH.MAT_ID, sizeof(MINVLOTMVH.MAT_ID));
        TRS.add_int(list_item, "MAT_VER", MINVLOTMVH.MAT_VER);
        TRS.add_string(list_item, "AREA_ID", MINVLOTMVH.AREA_ID, sizeof(MINVLOTMVH.AREA_ID));
        TRS.add_string(list_item, "SUB_AREA_ID", MINVLOTMVH.SUB_AREA_ID, sizeof(MINVLOTMVH.SUB_AREA_ID));
        TRS.add_string(list_item, "OPER", MINVLOTMVH.OPER, sizeof(MINVLOTMVH.OPER));
        TRS.add_string(list_item, "TO_AREA_ID", MINVLOTMVH.TO_AREA_ID, sizeof(MINVLOTMVH.TO_AREA_ID));
        TRS.add_string(list_item, "TO_SUB_AREA_ID", MINVLOTMVH.TO_SUB_AREA_ID, sizeof(MINVLOTMVH.TO_SUB_AREA_ID));
        TRS.add_string(list_item, "TO_OPER", MINVLOTMVH.TO_OPER, sizeof(MINVLOTMVH.TO_OPER));
        TRS.add_double(list_item, "TRAN_QTY", MINVLOTMVH.TRAN_QTY);

        //제품 조회
        DBU_init_mwipmatdef(&MWIPMATDEF);
        TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPMATDEF.MAT_ID, MINVLOTMVH.MAT_ID,sizeof(MWIPMATDEF.MAT_ID));
        MWIPMATDEF.MAT_VER = MINVLOTMVH.MAT_VER;
        DBU_select_mwipmatdef(1, &MWIPMATDEF);

        TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
        TRS.add_string(list_item, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));

        //From 사업부 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, MINVLOTMVH.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MINVLOTMVH.AREA_ID, sizeof(MINVLOTMVH.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

        //From 작업장 조회(null이 아닌경우)
        if (COM_isnullspace(MINVLOTMVH.SUB_AREA_ID) == MP_FALSE)
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MINVLOTMVH.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MINVLOTMVH.SUB_AREA_ID, sizeof(MINVLOTMVH.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
        }

        //From 공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPOPRDEF.OPER, MINVLOTMVH.OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));

        //To 사업부 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, MINVLOTMVH.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MINVLOTMVH.TO_AREA_ID, sizeof(MINVLOTMVH.TO_AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_string(list_item, "TO_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

        //To 작업장 조회(null이 아닌경우)
        if (COM_isnullspace(MINVLOTMVH.TO_SUB_AREA_ID) == MP_FALSE)
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MINVLOTMVH.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MINVLOTMVH.TO_SUB_AREA_ID, sizeof(MINVLOTMVH.TO_SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "TO_SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
        }

        //To 공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPOPRDEF.OPER, MINVLOTMVH.TO_OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        TRS.add_string(list_item, "TO_OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_INV_View_Move_History_List_Validation()
- Validation Check sub function of "CUS_INV_VIEW_MOVE_HISTORY_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Move_History_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
