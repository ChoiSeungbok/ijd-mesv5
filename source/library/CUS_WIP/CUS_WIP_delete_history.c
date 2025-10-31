/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_delete_history.c
Description : lot 이력삭제

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/20  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_DELETE_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Delete_History_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Delete_History()
- LOT 이력삭제
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_History(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_DELETE_HISTORY(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Delete_History", out_node);

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
CUS_WIP_DELETE_HISTORY()
- Main sub function of "CUS_WIP_Delete_History" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_DELETE_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;   //이력삭제 이전 lot sts

    TRSNode     *delete_in;
    TRSNode     *cmn_out;

    LOG_head("CUS_WIP_Delete_History");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Delete_History_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "CMN-0004");		// CMN-0004 : Database에는 조건의 데이터가 존재하지 않습니다.
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");		// WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        }

        TRS.add_dberrmsg(out_node, DB_error_msg);
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        return MP_FALSE;
    }

    delete_in = TRS.add_node(in_node, "delete_in");
    TRS.add_char(delete_in, IN_PROCSTEP, '1');
    CopyDefaultMembers(delete_in, in_node);

    TRS.add_string(delete_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    TRS.add_int(delete_in, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);

    cmn_out = TRS.create_node("Cmn_Out");
    if (WIP_DELETE_LOT_HISTORY(s_msg_code, delete_in, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }


    return MP_TRUE;
}


/*******************************************************************************
CUS_WIP_Delete_History_Validation()
- Validation Check sub function of "CUS_WIP_LATHE_PROCESS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_History_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}