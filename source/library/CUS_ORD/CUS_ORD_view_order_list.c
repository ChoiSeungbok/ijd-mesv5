/*******************************************************************************

System      : MESplus
Module      : CUS_ORD
File Name   : CUS_ORD_view_order_list.c
Description : View Order List function

MES Version : 5.0

Function List
- step 1: 작업지시 조회

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/30  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_ORD_common.h"

int CUS_ORD_View_Order_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_ORD_VIEW_ORDER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_ORD_View_Order_List()
- View Oper List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_View_Order_List(TRSNode *in_node, TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_ORD_VIEW_ORDER_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_ORD_View_Order_List", out_node);
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
CUS_ORD_VIEW_ORDER_LIST()
- Main sub function of "CUS_ORD_View_Order_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_VIEW_ORDER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;  //작업지시 마스트

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_ORD_View_Order_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_ORD_View_Order_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    i_step = 0;

    //작업지시 찾기 : 사업부,작업장,공정에 대한 작업지시 찾기
    if (TRS.get_procstep(in_node) == '1')
    {
        i_step = 2;

        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1), in_node, "AREA_ID");
        //TRS.copy(MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2), in_node, "SUB_AREA_ID");
        TRS.copy(MWIPORDSTS.ORD_CMF_3, sizeof(MWIPORDSTS.ORD_CMF_3), in_node, "OPER");
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORD_CMF_3), in_node, "NEXT_ORDER");

        DBU_open_mwipordsts(i_step, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0002 : 이 ORDER는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0002");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_1), MWIPORDSTS.ORD_CMF_1);
            TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_2), MWIPORDSTS.ORD_CMF_2);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_3), MWIPORDSTS.ORD_CMF_3);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mwipordsts(i_step, &MWIPORDSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mwipordsts(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //ORD-0002 : 이 ORDER는 존재하지 않습니다.
                strcpy(s_msg_code, "ORD-0002");
                TRS.add_fieldmsg(out_node, "MWIPORDSTS FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_1), MWIPORDSTS.ORD_CMF_1);
                TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_2), MWIPORDSTS.ORD_CMF_2);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_3), MWIPORDSTS.ORD_CMF_3);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mwipordsts(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_ORDER", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                DBU_close_mwipordsts(i_step);
                break;
            }

            //진행중 또는 대기인 작업지시 리스트만 보이게 한다.
            if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_FINISH
                || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_DELETE)
            {
                continue;
            }

            list_item = TRS.add_node(out_node, "ORDER_LIST");

            TRS.add_string(list_item, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_string(list_item, "PLAN_START_TIME", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
            TRS.add_string(list_item, "PLAN_END_TIME", MWIPORDSTS.PLAN_END_TIME, sizeof(MWIPORDSTS.PLAN_END_TIME));
        }
    }

    //작업지시 등록 화면. => 사업부, 작업장, 작업일시로 작업지시 찾기
    else if (TRS.get_procstep(in_node) == '2')
    {
        DB_init_condition(&DBC_Q_COND);
        TRS.copy(DBC_Q_COND.FROM_DATE, sizeof(DBC_Q_COND.FROM_DATE), in_node, "FROM_DATE");
        TRS.copy(DBC_Q_COND.TO_DATE, sizeof(DBC_Q_COND.TO_DATE), in_node, "TO_DATE");

        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

        i_step = 3;

        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1), in_node, "AREA_ID");
        TRS.copy(MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2), in_node, "SUB_AREA_ID");        
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "NEXT_ORDER");

        DBU_open_mwipordsts(i_step, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0002 : 이 ORDER는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0002");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_1), MWIPORDSTS.ORD_CMF_1);
            TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_2), MWIPORDSTS.ORD_CMF_2);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_3), MWIPORDSTS.ORD_CMF_3);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mwipordsts(i_step, &MWIPORDSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mwipordsts(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //ORD-0002 : 이 ORDER는 존재하지 않습니다.
                strcpy(s_msg_code, "ORD-0002");
                TRS.add_fieldmsg(out_node, "MWIPORDSTS FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_1), MWIPORDSTS.ORD_CMF_1);
                TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_2), MWIPORDSTS.ORD_CMF_2);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPORDSTS.ORD_CMF_3), MWIPORDSTS.ORD_CMF_3);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mwipordsts(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_ORDER", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                DBU_close_mwipordsts(i_step);
                break;
            }

            list_item = TRS.add_node(out_node, "ORDER_LIST");

            TRS.add_string(list_item, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_string(list_item, "ORDER_DESC", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
            TRS.add_string(list_item, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
            TRS.add_int(list_item, "MAT_VER", MWIPORDSTS.MAT_VER);
            TRS.add_double(list_item, "ORD_QTY", MWIPORDSTS.ORD_QTY);
            TRS.add_string(list_item, "PLAN_START_TIME", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
            TRS.add_string(list_item, "PLAN_END_TIME", MWIPORDSTS.PLAN_END_TIME, sizeof(MWIPORDSTS.PLAN_END_TIME));
            TRS.add_char(list_item, "ORDER_STATUS_FLAG", MWIPORDSTS.ORD_STATUS_FLAG);
        }
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_ORD_View_Order_List_Validation()
- Validation Check sub function of "CUS_ORD_VIEW_ORDER_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_View_Order_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
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
