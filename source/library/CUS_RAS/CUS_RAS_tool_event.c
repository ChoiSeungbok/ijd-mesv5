/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_tool_event.c
Description : Tool event function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/06  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Tool_Event_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Tool_Event_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Tool_Event_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Tool_Event()
- Tool Event function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tool_Event(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_TOOL_EVENT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }
    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Tool_Event", out_node);

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
CUS_RAS_TOOL_EVENT()
- Main sub function of "CUS_RAS_Tool_Event" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_TOOL_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASTOLDEF_TAG MRASTOLDEF;
    struct MRASTOLEVN_TAG MRASTOLEVN;

    struct work_date_tag work_date;

    TRSNode *tool_in_node;
    TRSNode **sts_list;
    TRSNode *tool_sts_list;
    TRSNode *cmn_out;

    int i_sts_count = 0;
    char s_factory[10];

    LOG_head("CUS_RAS_Tool_Event");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_Tool_Event_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    memset(s_factory, ' ', sizeof(s_factory));
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    DBC_init_mrastoldef(&MRASTOLDEF);
    TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), in_node, "TOOL_ID");
    DBC_select_mrastoldef(1, &MRASTOLDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //RAS-0168 : TOOL 이 존재하지 않습니다.
        strcpy(s_msg_code, "RAS-0168");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "TOOL_ID", DT_STRING, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);

        return MP_FALSE;
    }

    DBC_init_mrastolevn(&MRASTOLEVN);
    TRS.copy(MRASTOLEVN.FACTORY, sizeof(MRASTOLEVN.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MRASTOLEVN.TOOL_EVENT_ID, sizeof(MRASTOLEVN.TOOL_EVENT_ID), in_node, "TOOL_EVENT_ID");
    memcpy(MRASTOLEVN.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
    memcpy(MRASTOLEVN.TOOL_TYPE, MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
    DBC_select_mrastolevn(1, &MRASTOLEVN);
    if (DB_error_code != DB_SUCCESS)
    {
        //RAS-0146 : TOOL EVENT가 존재하지 않습니다.
        strcpy(s_msg_code, "RAS-0146");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "TOOL_ID", DT_STRING, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);

        return MP_FALSE;
    }

    tool_in_node = TRS.add_node(in_node, "tool_in_node");
    TRS.add_char(tool_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(tool_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_TRUE)
        TRS.add_string(tool_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));
    else
        TRS.add_nstring(tool_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));

    TRS.add_string(tool_in_node, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
    TRS.add_string(tool_in_node, "TOOL_TYPE", MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
    TRS.add_string(tool_in_node, "TOOL_EVENT_ID", MRASTOLEVN.TOOL_EVENT_ID, sizeof(MRASTOLEVN.TOOL_EVENT_ID));

    TRS.add_nstring(tool_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(tool_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(tool_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));

    TRS.add_nstring(tool_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
    TRS.add_nstring(tool_in_node, "OPER", TRS.get_string(in_node, "OPER"));

    TRS.add_nstring(tool_in_node, "TOOL_GRP", TRS.get_string(in_node, "TOOL_GRP"));
    TRS.add_nstring(tool_in_node, "TOOL_SET_ID", TRS.get_string(in_node, "TOOL_SET_ID"));
    TRS.add_nstring(tool_in_node, "TOOL_SET_LOCATION", TRS.get_string(in_node, "TOOL_SET_LOCATION"));
    TRS.add_nstring(tool_in_node, "TOOL_STATUS", TRS.get_string(in_node, "TOOL_STATUS"));
    TRS.add_nstring(tool_in_node, "TOOL_LOCATION", TRS.get_string(in_node, "TOOL_LOCATION"));

    sts_list = TRS.get_list(in_node, "STS_LIST");
    i_sts_count = TRS.get_item_count(in_node, "STS_LIST");

    for (int i = 0; i < 30; i++)
    {
        if (i == 27)
        {   
            //작업일자
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", work_date.s_work_date, sizeof(work_date.s_work_date));
        }
        else if (i == 28)
        {
            //작업조
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", work_date.s_day_night, sizeof(work_date.s_day_night));
        }
        else if (i == 29)
        {
            //작업시간
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", work_date.s_sys_time, sizeof(work_date.s_sys_time));
        }
        else
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
    }

    TRS.add_nstring(tool_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

    if (CUS_RAS_Tool_Event_Before_Transaction(s_msg_code, 0, tool_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    cmn_out = TRS.create_node("Cmn_Out");
    if (RAS_TOOL_EVENT(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }
    TRS.free_node(cmn_out);

    if (CUS_RAS_Tool_Event_After_Transaction(s_msg_code, 0, tool_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_Tool_Event_Validation()
- Validation Check sub function of "CUS_RAS_TOOL_EVENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tool_Event_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "TOOL_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "TOOL_ID", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "TOOL_EVENT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "TOOL_EVENT_ID", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Tool_Event_Before_Transaction()
- Main sub function of "CUS_RAS_TOOL_EVENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tool_Event_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Tool_Event_After_Transaction()
- Main sub function of "CUS_RAS_TOOL_EVENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tool_Event_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}
