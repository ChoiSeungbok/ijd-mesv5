/*******************************************************************************

System      : MESplus
Module      : CUS_IFS
File Name   : CUS_IFS_om_promise_date.c
Description : I/F Om Promise Date function(출하예정일변경)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/17  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_IFS_common.h"

int CUS_IFS_Om_Promise_Date_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_IFS_Om_Promise_Date()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Om_Promise_Date(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_IFS_OM_PROMISE_DATE(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_IFS_Om_Promise_Date", out_node);
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
CUS_IFS_OM_PROMISE_DATE()
- Main sub function of "CUS_IFS_Om_Promise_Date" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_OM_PROMISE_DATE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct IF_OM_PROMISE_DATE_TAG IF_OM_PROMISE_DATE;

    LOG_head("CUS_IFS_Om_Promise_Date");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_IFS_Om_Promise_Date_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_if_om_promise_date(&IF_OM_PROMISE_DATE);

    if (TRS.get_char(in_node, "TRAN_FLAG") == 'I')
    {
        IF_OM_PROMISE_DATE.IF_CODE = 'N';
        memcpy(IF_OM_PROMISE_DATE.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_OM_PROMISE_DATE.FACTORY, sizeof(IF_OM_PROMISE_DATE.FACTORY), in_node, IN_FACTORY);
		IF_OM_PROMISE_DATE.TRAN_FLAG = TRS.get_char(in_node, "TRAN_FLAG");
        IF_OM_PROMISE_DATE.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
        TRS.copy(IF_OM_PROMISE_DATE.TRAN_TYPE, sizeof(IF_OM_PROMISE_DATE.TRAN_TYPE), in_node, "TRAN_TYPE");
        memcpy(IF_OM_PROMISE_DATE.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
        IF_OM_PROMISE_DATE.HEADER_ID = TRS.get_int(in_node, "HEADER_ID");
        IF_OM_PROMISE_DATE.LINE_NUMBER = TRS.get_int(in_node, "LINE_NUMBER");      
        TRS.copy(IF_OM_PROMISE_DATE.PROMISE_DATE, sizeof(IF_OM_PROMISE_DATE.PROMISE_DATE), in_node, "PROMISE_DATE");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_1, sizeof(IF_OM_PROMISE_DATE.CMF_1), in_node, "CMF_1");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_2, sizeof(IF_OM_PROMISE_DATE.CMF_2), in_node, "CMF_2");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_3, sizeof(IF_OM_PROMISE_DATE.CMF_3), in_node, "CMF_3");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_4, sizeof(IF_OM_PROMISE_DATE.CMF_4), in_node, "CMF_4");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_5, sizeof(IF_OM_PROMISE_DATE.CMF_5), in_node, "CMF_5");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_6, sizeof(IF_OM_PROMISE_DATE.CMF_6), in_node, "CMF_6");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_7, sizeof(IF_OM_PROMISE_DATE.CMF_7), in_node, "CMF_7");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_8, sizeof(IF_OM_PROMISE_DATE.CMF_8), in_node, "CMF_8");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_9, sizeof(IF_OM_PROMISE_DATE.CMF_9), in_node, "CMF_9");
        TRS.copy(IF_OM_PROMISE_DATE.CMF_10, sizeof(IF_OM_PROMISE_DATE.CMF_10), in_node, "CMF_10");
        TRS.copy(IF_OM_PROMISE_DATE.CREATE_USER_ID, sizeof(IF_OM_PROMISE_DATE.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_OM_PROMISE_DATE.CREATE_TIME, gs_sys_time, sizeof(IF_OM_PROMISE_DATE.CREATE_TIME));
        TRS.copy(IF_OM_PROMISE_DATE.UPDATE_USER_ID, sizeof(IF_OM_PROMISE_DATE.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_OM_PROMISE_DATE.UPDATE_TIME, gs_sys_time, sizeof(IF_OM_PROMISE_DATE.UPDATE_TIME));

        DBU_insert_if_om_promise_date(&IF_OM_PROMISE_DATE);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "IF_OM_PROMISE_DATE INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_OM_PROMISE_DATE.FACTORY), IF_OM_PROMISE_DATE.FACTORY);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    else if (TRS.get_char(in_node, "TRAN_FLAG") == 'D')
    {

    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_IFS_Om_Promise_Date_Validation()
- Validation Check sub function of "CUS_IFS_OM_PROMISE_DATE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Om_Promise_Date_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
