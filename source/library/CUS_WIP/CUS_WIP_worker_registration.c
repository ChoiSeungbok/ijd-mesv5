/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_worker_registration.c
Description : 작업자 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/06  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_WORKER_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Worker_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Worker_Registration()
- Tool Event function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Worker_Registration(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_WORKER_REGISTRATION(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }
    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Worker_Registration", out_node);

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
CUS_WIP_WORKER_REGISTRATION()
- Main sub function of "CUS_WIP_Worker_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_WORKER_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CWIPWRKGRP_TAG CWIPWRKGRP;

    TRSNode     **worker_list;

    int worker_count = 0;

    LOG_head("CUS_WIP_Worker_Registration");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Worker_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    DBU_init_cwipwrkgrp(&CWIPWRKGRP);

    //작업자 등록
    if (TRS.get_procstep(in_node) == '1')
    {
        TRS.copy(CWIPWRKGRP.FACTORY, sizeof(CWIPWRKGRP.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPWRKGRP.AREA_ID, sizeof(CWIPWRKGRP.AREA_ID), in_node, "AREA_ID");
        TRS.copy(CWIPWRKGRP.SUB_AREA_ID, sizeof(CWIPWRKGRP.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        TRS.copy(CWIPWRKGRP.OPER, sizeof(CWIPWRKGRP.OPER), in_node, "OPER");
        TRS.copy(CWIPWRKGRP.GROUP_ID, sizeof(CWIPWRKGRP.GROUP_ID), in_node, "GROUP_ID");

        //WRKGRP정보를 삭제하고 모든 리스트를 INSERT 한다
        DBU_delete_cwipwrkgrp(2,&CWIPWRKGRP);
        if (DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code!=DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CWIPWRKDEF DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPWRKGRP.AREA_ID), CWIPWRKGRP.AREA_ID);
                TRS.add_fieldmsg(out_node, "SUB_AREA_ID", DT_STRING, sizeof(CWIPWRKGRP.SUB_AREA_ID), CWIPWRKGRP.SUB_AREA_ID);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPWRKGRP.OPER), CWIPWRKGRP.OPER);
                TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPWRKGRP.GROUP_ID), CWIPWRKGRP.GROUP_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        worker_list = TRS.get_list(in_node, "WORKER_LIST");
        worker_count = TRS.get_item_count(in_node, "WORKER_LIST");

        for (int i = 0; i < worker_count; i++)
        {
            DBU_init_cwipwrkgrp(&CWIPWRKGRP);
            TRS.copy(CWIPWRKGRP.WORKER_ID, sizeof(CWIPWRKGRP.WORKER_ID), worker_list[i], "WORKER_ID");
            TRS.copy(CWIPWRKGRP.FACTORY, sizeof(CWIPWRKGRP.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPWRKGRP.AREA_ID, sizeof(CWIPWRKGRP.AREA_ID), in_node, "AREA_ID");
            TRS.copy(CWIPWRKGRP.SUB_AREA_ID, sizeof(CWIPWRKGRP.SUB_AREA_ID), in_node, "SUB_AREA_ID");
            TRS.copy(CWIPWRKGRP.OPER, sizeof(CWIPWRKGRP.OPER), in_node, "OPER");
            TRS.copy(CWIPWRKGRP.GROUP_ID, sizeof(CWIPWRKGRP.GROUP_ID), in_node, "GROUP_ID");
			TRS.copy(CWIPWRKGRP.WORK_TYPE, sizeof(CWIPWRKGRP.WORK_TYPE), worker_list[i], "WORK_TYPE");

            TRS.copy(CWIPWRKGRP.CREATE_USER_ID, sizeof(CWIPWRKGRP.CREATE_USER_ID), in_node, IN_USERID);
            DB_get_systime(CWIPWRKGRP.CREATE_TIME);

            DBU_insert_cwipwrkgrp(&CWIPWRKGRP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CWIPWRKGRP INSERT", MP_NVST);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_SETUP;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Worker_Registration_Validation()
- Validation Check sub function of "CUS_WIP_WORKER_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Worker_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    // AREA_ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    //SUB_AREA_ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "SUB_AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    //OPER VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    //GROUP_ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "GROUP_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "GROUP_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }
    return MP_TRUE;
}
