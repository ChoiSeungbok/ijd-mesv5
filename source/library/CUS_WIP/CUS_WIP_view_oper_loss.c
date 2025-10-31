/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_oper_loss.c
Description : View Oper loss list function

MES Version : 5.0

Function List
- step 1: 공정별 불량항목 찾기

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/21  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Oper_Loss_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_VIEW_OPER_LOSS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_View_Oper_Loss()
- View Oper List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Oper_Loss(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_VIEW_OPER_LOSS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_View_Oper_Loss", out_node);
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
CUS_WIP_VIEW_OPER_LOSS()
- Main sub function of "CUS_WIP_View_Oper_Loss" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_OPER_LOSS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MGCMTBLDAT_TAG MGCMTBLDAT_O;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_D;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    TRSNode *list_item;
    int i_step = 0;

    LOG_head("CUS_WIP_View_Oper_Loss");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_View_Oper_Loss_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        //공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
            TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        i_step = 3;

        DBU_init_mgcmtbldat(&MGCMTBLDAT_O);
        memcpy(MGCMTBLDAT_O.FACTORY, MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
        memcpy(MGCMTBLDAT_O.TABLE_NAME, MP_GCM_OPER_LOSS, strlen(MP_GCM_OPER_LOSS));
        memcpy(MGCMTBLDAT_O.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

        DBU_open_mgcmtbldat(i_step, &MGCMTBLDAT_O);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_O.FACTORY), MGCMTBLDAT_O.FACTORY);
            TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_O.TABLE_NAME), MGCMTBLDAT_O.TABLE_NAME);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_O.KEY_1), MGCMTBLDAT_O.KEY_1);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mgcmtbldat(i_step, &MGCMTBLDAT_O);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mgcmtbldat(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                strcpy(s_msg_code, "GCM-0008");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_O.FACTORY), MGCMTBLDAT_O.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_O.TABLE_NAME), MGCMTBLDAT_O.TABLE_NAME);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_O.KEY_1), MGCMTBLDAT_O.KEY_1);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mgcmtbldat(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            list_item = TRS.add_node(out_node, "LOT_TBL");
            TRS.add_string(list_item, "LOSS_CODE", MGCMTBLDAT_O.KEY_2, sizeof(MGCMTBLDAT_O.KEY_2));

            DBU_init_mgcmtbldat(&MGCMTBLDAT_D);
            memcpy(MGCMTBLDAT_D.FACTORY, MGCMTBLDAT_O.FACTORY, sizeof(MGCMTBLDAT_O.FACTORY));
            memcpy(MGCMTBLDAT_D.TABLE_NAME, MP_GCM_LOSS_CODE, strlen(MP_GCM_LOSS_CODE));
            memcpy(MGCMTBLDAT_D.KEY_1, MGCMTBLDAT_O.KEY_2, sizeof(MGCMTBLDAT_O.KEY_2));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT_D);

            TRS.add_string(list_item, "LOSS_DESC", MGCMTBLDAT_D.DATA_1, sizeof(MGCMTBLDAT_D.DATA_1));
        }
    }
  
    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Oper_Loss_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_OPER_LOSS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Oper_Loss_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    return MP_TRUE;
}
