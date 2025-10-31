/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_WIP_update_loss_by_oper.c
    Description : 공정별 불량 정보를 저장한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/17  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_UPDATE_LOSS_BY_OPER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_WIP_Update_Loss_By_Oper()
        - 공정별 불량 정보를 저장한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Loss_By_Oper(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_LOSS_BY_OPER(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Impact_End_Lot", out_node);

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
    CUS_WIP_UPDATE_LOSS_BY_OPER()
        - Main sub function of "CUS_WIP_Update_Loss_By_Oper" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_LOSS_BY_OPER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MGCMTBLDAT_TAG MGCMTBLDAT;

    int i = 0;

    LOG_head("CUS_WIP_UPDATE_LOSS_BY_OPER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    DBC_init_mgcmtbldat(&MGCMTBLDAT);
    TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT.TABLE_NAME, "C_OPER_LOSS", strlen("C_OPER_LOSS"));
    TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "OPER");
    DBC_delete_mgcmtbldat(4, &MGCMTBLDAT);
    if(DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "GCM-0006");

        TRS.add_fieldmsg(out_node, "MGCMTBLDAT Select 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "TABLE_NAME", sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
        TRS.add_fieldmsg(out_node, "KEY_1", sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    for(i = 0; i < in_node->SCount; i++)
    {
        DBC_init_mgcmtbldat(&MGCMTBLDAT);
        TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT.TABLE_NAME, "C_OPER_LOSS", strlen("C_OPER_LOSS"));
        TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "OPER");
        TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), in_node->SItems[i], "LOSS_CODE");
        TRS.copy(MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1), in_node->SItems[i], "SEQ");
        TRS.copy(MGCMTBLDAT.CREATE_USER_ID, sizeof(MGCMTBLDAT.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(MGCMTBLDAT.CREATE_TIME, gs_sys_time, sizeof(MGCMTBLDAT.CREATE_TIME));

        DBC_insert_mgcmtbldat(&MGCMTBLDAT);
        if(DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
            TRS.add_fieldmsg(out_node, "TABLE_NAME", sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
            TRS.add_fieldmsg(out_node, "KEY_1", sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
            TRS.add_fieldmsg(out_node, "KEY_2", sizeof(MGCMTBLDAT.KEY_2), MGCMTBLDAT.KEY_2);
            TRS.add_fieldmsg(out_node, "DATA_1", sizeof(MGCMTBLDAT.DATA_1), MGCMTBLDAT.DATA_1);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
