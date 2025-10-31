/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_update_tool.c
Description : Tool update function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/27  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Update_Tool_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Update_Tool_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Update_Tool_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Update_Tool()
- Tool Event function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Update_Tool(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_UPDATE_TOOL(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }
    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Update_Tool", out_node);

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
CUS_RAS_UPDATE_TOOL()
- Main sub function of "CUS_RAS_Update_Tool" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_UPDATE_TOOL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *tool_in_node;
    TRSNode **sts_list;
    TRSNode *tool_sts_list;
    TRSNode *cmn_out;

    int i_sts_count = 0;

    LOG_head("CUS_RAS_Update_Tool");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_Update_Tool_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    tool_in_node = TRS.add_node(in_node, "tool_in_node");
    TRS.add_char(tool_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));
    CopyDefaultMembers(tool_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_TRUE)
        TRS.add_string(tool_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));
    else
        TRS.add_nstring(tool_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));

    TRS.add_nstring(tool_in_node, "TOOL_ID", TRS.get_string(in_node, "TOOL_ID"));
    TRS.add_nstring(tool_in_node, "TOOL_DESC", TRS.get_string(in_node, "TOOL_DESC"));
    TRS.add_nstring(tool_in_node, "TOOL_TYPE", TRS.get_string(in_node, "TOOL_TYPE"));
    TRS.add_nstring(tool_in_node, "TOOL_GRP", TRS.get_string(in_node, "TOOL_GRP"));
    TRS.add_nstring(tool_in_node, "TOOL_SET_ID", TRS.get_string(in_node, "TOOL_SET_ID"));
    TRS.add_nstring(tool_in_node, "TOOL_SET_LOCATION", TRS.get_string(in_node, "TOOL_SET_LOCATION"));
    TRS.add_nstring(tool_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
    TRS.add_nstring(tool_in_node, "SUB_AREA_ID", TRS.get_string(in_node, "SUB_AREA_ID"));
    TRS.add_nstring(tool_in_node, "TOOL_LOCATION", TRS.get_string(in_node, "TOOL_LOCATION"));
    TRS.add_nstring(tool_in_node, "VENDOR_ID", TRS.get_string(in_node, "VENDOR_ID"));
    TRS.add_nstring(tool_in_node, "VENDOR_TOOL_ID", TRS.get_string(in_node, "VENDOR_TOOL_ID"));
    TRS.add_int(tool_in_node, "CELL_COUNT_X", TRS.get_int(in_node, "CELL_COUNT_X"));
    TRS.add_int(tool_in_node, "CELL_COUNT_Y", TRS.get_int(in_node, "CELL_COUNT_Y"));
    TRS.add_int(tool_in_node, "CELL_COUNT_Z", TRS.get_int(in_node, "CELL_COUNT_Z"));
    TRS.add_int(tool_in_node, "CELL_SIZE_X", TRS.get_int(in_node, "CELL_SIZE_X"));
    TRS.add_int(tool_in_node, "CELL_SIZE_Y", TRS.get_int(in_node, "CELL_SIZE_Y"));
    TRS.add_int(tool_in_node, "CELL_SIZE_Z", TRS.get_int(in_node, "CELL_SIZE_Z"));
    TRS.add_nstring(tool_in_node, "TOOL_COMMENT", TRS.get_string(in_node, "TOOL_COMMENT"));

    sts_list = TRS.get_list(in_node, "STS_LIST");
    i_sts_count = TRS.get_item_count(in_node, "STS_LIST");

    for (int i = 0; i < 30; i++)
    {
        if (i < i_sts_count)
        {
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_nstring(tool_sts_list, "TOOL_STS", TRS.get_string(sts_list[i], "TOOL_STS"));
        }
        else
        {
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_nstring(tool_sts_list, "TOOL_STS", "");
        }
    }

    if (CUS_RAS_Update_Tool_Before_Transaction(s_msg_code, 0, tool_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    cmn_out = TRS.create_node("Cmn_Out");
    if (RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }
    TRS.free_node(cmn_out);

    if (CUS_RAS_Update_Tool_After_Transaction(s_msg_code, 0, tool_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_Tool_Event_Validation()
- Validation Check sub function of "CUS_RAS_UPDATE_TOOL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Update_Tool_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "IUNSG") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "TOOL_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "TOOL_ID", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Update_Tool_Before_Transaction()
- Main sub function of "CUS_RAS_UPDATE_TOOL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Update_Tool_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Update_Tool_After_Transaction()
- Main sub function of "CUS_RAS_UPDATE_TOOL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Update_Tool_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}
