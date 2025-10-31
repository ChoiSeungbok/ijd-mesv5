/*******************************************************************************

    System      : MESplus
    Module      : User Routine for Common
    File Name   : UCMN_prologue.c
    Description : User Routine for UCMN_prologue

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

#include "UCMN_common.h"
#include "CUS_defines.h"

char gs_sys_time[14];

int UCMN_prologue_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */

    memset(gs_sys_time, ' ', sizeof(gs_sys_time));

    DB_get_systime(gs_sys_time);

    if (DB_error_code != DB_SUCCESS)
    {
        TRS.add_fieldmsg(out_node, "s_sys_time", MP_NVST);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;

        COM_set_result(out_node, MP_FAIL_C, "CMN-0004", MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    return MP_TRUE;
}

