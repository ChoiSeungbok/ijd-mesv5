/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_ball_mill_end_lot.c
    Description : Ball Mill 공정 완료 후 EAP 완료 정보 전송(EAP -> MES)

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/21  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_BALL_MILL_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Collect_Inspection_Data()
        - Ball Mill 공정 완료 후 EAP 완료 정보 전송(EAP -> MES)
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Ball_Mill_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_BALL_MILL_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Ball_Mill_End_Lot", out_node);

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
    CUS_EIS_BALL_MILL_END_LOT()
        - Main sub function of "CUS_EIS_Ball_Mill_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_BALL_MILL_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    char s_channel[100];
    TRSNode *send_node;

    LOG_head("CUS_EIS_START_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    // Channel 설정
    sprintf(s_channel, "/%.*s/EAP/%s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, TRS.get_string(in_node, "RES_ID"));

    send_node = TRS.add_node(in_node, "End_Lot");
    TRS.add_char(send_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(send_node, in_node);

    TRS.add_string(send_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
    TRS.add_nstring(send_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    TRS.add_nstring(send_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

    LOG_head("Send Equipment To End Lot Information");
    TRS.log_add_all_members(send_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    MOA.call_service("EAP", "EIS_EAP_Ball_Mill_End_Lot", send_node, NULL, s_channel, 18000000, DM_UNICAST);

    return MP_TRUE;
}
