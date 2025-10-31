/*******************************************************************************

    System      : MESplus
    Module      : User Routine for ORD
    File Name   : UORD_Update_Order.c
    Description : User Routine for ORD_Update_Order

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/10  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "UORD_common.h"

int ORD_UPDATE_ORDER_AFTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

int ORD_Update_Order_Before_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
    return MP_TRUE;
}

int ORD_Update_Order_After_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
    char s_msg_code[MP_SIZE_MSG];
    int i_ret = MP_TRUE;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = ORD_UPDATE_ORDER_AFTER(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    COM_out_msg_log_write(s_msg_code, "ORD_UPDATE_ORDER_AFTER", out_node);

    return i_ret;
}


int ORD_UPDATE_ORDER_AFTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct MWIPFLWDEF_TAG MWIPFLWDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        //작업지시 조회
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0002 : 이 ORDER는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0002");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //flow 조회
        DBU_init_mwipflwdef(&MWIPFLWDEF);
        memcpy(MWIPFLWDEF.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        memcpy(MWIPFLWDEF.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
        DBU_select_mwipflwdef(1, &MWIPFLWDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0012 : 이 FLOW는 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0012");
            TRS.add_fieldmsg(out_node, "MWIPFLWDEF SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWDEF.FACTORY), MWIPFLWDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWDEF.FLOW), MWIPFLWDEF.FLOW);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //flow의 창고공정을 찾아 온다.
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        memcpy(MWIPOPRDEF.FACTORY, MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
        memcpy(MWIPOPRDEF.OPER_CMF_1, MWIPFLWDEF.FLOW, sizeof(MWIPFLWDEF.FLOW));
        DBU_select_mwipoprdef(2, &MWIPOPRDEF);
        if (DB_error_code == DB_SUCCESS)
        {
            memcpy(MWIPORDSTS.ORD_CMF_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
        }

        MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;

        //작업지시 상태 및 창고 저장.
        DBU_update_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}