/******************************************************************************'

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_update_inv_data_update.c
    Description : inv_data_update Setup function module

    MES Version : 5.3.4 ~

    Function List
        - CUS_INV_Update_inv_data_update()
            + Create/Update/Delete inv_data_update definition
        - CUS_INV_UPDATE_INV_DATA_UPDATE()
            + Main sub function of CUS_INV_Update_inv_data_update function
            + Create/Update/Delete inv_data_update definition
        - CUS_INV_Update_inv_data_update_Validation()
            + Main sub function of CUS_INV_UPDATE_INV_DATA_UPDATE function
            + Check the condition for create/update/delete inv_data_update
    Detail Description
        - CUS_INV_UPDATE_INV_DATA_UPDATE()
            + h_proc_step
                + MP_STEP_CREATE : Create inv_data_update definition
                + MP_STEP_UPDATE : Update inv_data_update definition
                + MP_STEP_DELETE : Delete inv_data_update definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2022-12-21             Create by Generator

    Copyright(C) 1998-2022 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_INV_common.h"

int CUS_INV_Update_inv_data_update_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Update_inv_data_update()
        - Create/Update/Delete inv_data_update definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Update_inv_data_update(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_UPDATE_INV_DATA_UPDATE(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_UPDATE_INV_DATA_UPDATE", out_node);

    if(i_ret == MP_TRUE)
    {
        DB_commit();
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_UPDATE_INV_DATA_UPDATE()
        - Main sub function of "CUS_INV_Update_inv_data_update" function
        - Create/Update/Delete inv_data_update definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_UPDATE_INV_DATA_UPDATE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MINVLOTSTS_TAG MINVLOTSTS;
   // struct MINVLOTSTS_TAG MINVLOTSTS_o;
    char   s_sys_time[14];


    LOG_head("CUS_INV_UPDATE_INV_DATA_UPDATE");
    COM_log_add_field_msg(in_node);
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_INV", "CUS_INV_Update_inv_data_update",
                             MP_UPOINT_BEFORE,
                             in_node,
                             out_node) == MP_FALSE)     return MP_FALSE;
    if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE;
    */

    memset(s_sys_time, ' ', sizeof(s_sys_time));
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0003");
        TRS.add_fieldmsg(out_node, "DB_get_systime", MP_NVST);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if(CUS_INV_Update_inv_data_update_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }


    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_minvlotsts(&MINVLOTSTS);
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "INV_LOT_ID");
        DBU_select_minvlotsts(1, &MINVLOTSTS);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_INV-0004");
            TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT FOR UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //----[Addtional Logic for Update Case]----

        TRS.copy(MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_ID), in_node, "VENDOR_LOT_ID");
        TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(MINVLOTSTS.UPDATE_TIME));

        DBU_update_minvlotsts(1, &MINVLOTSTS);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_INV-0004");
            TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
            TRS.add_fieldmsg(out_node, "VENDOR_LOT_ID", MP_STR, sizeof(MINVLOTSTS.VENDOR_LOT_ID), MINVLOTSTS.VENDOR_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_INV", "CUS_INV_Update_inv_data_update",
                             MP_UPOINT_AFTER,
                             in_node,
                             out_node) == MP_FALSE) return MP_FALSE;
    */

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
} 

/*******************************************************************************
    CUS_INV_Update_inv_data_update_Validation()
        - Main sub function of "CUS_INV_UPDATE_INV_DATA_UPDATE" function
        - Check the condition for create/update/delete inv_data_update
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Update_inv_data_update_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    //struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MWIPFACDEF_TAG MWIPFACDEF;

    /* ProcStep Validation */
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }

    /* Factory Validation */
    if(COM_isnullspace(TRS.get_factory(in_node)) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_INV-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        return MP_FALSE;
    }

    DBC_init_mwipfacdef(&MWIPFACDEF);
    TRS.copy(MWIPFACDEF.FACTORY, sizeof(MWIPFACDEF.FACTORY), in_node, IN_FACTORY);
    DBC_select_mwipfacdef(1, &MWIPFACDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0005");
        TRS.add_fieldmsg(out_node, "MWIPFACDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFACDEF.FACTORY), MWIPFACDEF.FACTORY);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        return MP_FALSE;
    }

    /* INV_LOT_ID Validation */
    if(COM_isnullspace(TRS.get_string(in_node, "INV_LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_INV-0001");
        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }



    return MP_TRUE;
}

