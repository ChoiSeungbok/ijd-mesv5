/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_impact_end_lot.c
    Description : Impact 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/09  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_IMPACT_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Impact_End_Lot()
        - Impact 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Impact_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_IMPACT_END_LOT(s_msg_code, in_node, out_node);

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
    CUS_EIS_IMPACT_END_LOT()
        - Main sub function of "CUS_EIS_Impact_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_IMPACT_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTIMP_TAG CWIPLOTIMP;

    struct work_date_tag work_date;

    TRSNode *start_lot_in;
    char s_last_tran_time[14];

    LOG_head("CUS_EIS_IMPACT_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Check_LotStatus(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if(Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if (memcmp(MWIPLOTSTS.LOT_STATUS, MP_LOT_STATUS_PROC, strlen(MP_LOT_STATUS_PROC)) != 0)
    {
        start_lot_in = TRS.add_node(in_node, "Start_Lot_In");

        CopyDefaultMembers(start_lot_in, in_node);
        TRS.add_char(start_lot_in, IN_PROCSTEP, '1');

        TRS.add_nstring(start_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_string(start_lot_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
        TRS.add_int(start_lot_in, "MAT_VER", MWIPLOTSTS.MAT_VER);
        TRS.add_string(start_lot_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
        TRS.add_string(start_lot_in, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
        TRS.add_nstring(start_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

        if(memcmp(MWIPLOTSTS.LAST_TRAN_TIME, MRASRESDEF.LAST_EVENT_TIME, sizeof(MWIPLOTSTS.LAST_TRAN_TIME)) > 0)
            memcpy(s_last_tran_time, MWIPLOTSTS.LAST_TRAN_TIME, sizeof(s_last_tran_time));
        else
            memcpy(s_last_tran_time, MRASRESDEF.LAST_EVENT_TIME, sizeof(s_last_tran_time));

        if (TRS.mem_cmp(in_node, "START_TIME", s_last_tran_time, sizeof(s_last_tran_time)) > 0 &&
            TRS.mem_cmp(in_node, "START_TIME", gs_sys_time, sizeof(gs_sys_time)) < 0)
        {
            TRS.add_nstring(start_lot_in, "BACK_TIME", TRS.get_string(in_node, "START_TIME"));
        }

        if (CUS_WIP_START_LOT(s_msg_code, start_lot_in, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    }

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    DBU_init_cwiplotimp(&CWIPLOTIMP);

    TRS.copy(CWIPLOTIMP.LOT_ID, sizeof(CWIPLOTIMP.LOT_ID), in_node, "LOT_ID");
    CWIPLOTIMP.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
    memcpy(CWIPLOTIMP.OPER,   MWIPLOTSTS.OPER, sizeof(CWIPLOTIMP.OPER));
    memcpy(CWIPLOTIMP.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTIMP.MAT_ID));
    memcpy(CWIPLOTIMP.FLOW,   MWIPLOTSTS.FLOW, sizeof(CWIPLOTIMP.FLOW));
    CWIPLOTIMP.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
    TRS.copy(CWIPLOTIMP.GRADE, sizeof(CWIPLOTIMP.GRADE), in_node, "GRADE");
    TRS.copy(CWIPLOTIMP.RES_ID, sizeof(CWIPLOTIMP.RES_ID), in_node, "RES_ID");
    TRS.copy(CWIPLOTIMP.FACTORY, sizeof(CWIPLOTIMP.FACTORY), in_node, IN_FACTORY);
    memcpy(CWIPLOTIMP.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTIMP.WORK_DATE));
    memcpy(CWIPLOTIMP.WORK_TIME, gs_sys_time, sizeof(CWIPLOTIMP.WORK_TIME));
    memcpy(CWIPLOTIMP.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTIMP.DAY_NIGHT));

    CWIPLOTIMP.EDC_HIST_SEQ = TRS.get_int(in_node, "EDC_HIST_SEQ");

    TRS.copy(CWIPLOTIMP.RECIPE_ID, sizeof(CWIPLOTIMP.RECIPE_ID), in_node, "RECIPE_ID");
    TRS.copy(CWIPLOTIMP.START_TIME, sizeof(CWIPLOTIMP.START_TIME), in_node, "START_TIME");
    TRS.copy(CWIPLOTIMP.END_TIME, sizeof(CWIPLOTIMP.END_TIME), in_node, "END_TIME");
    TRS.copy(CWIPLOTIMP.JUDGMENT, sizeof(CWIPLOTIMP.JUDGMENT), in_node, "JUDGMENT");
    CWIPLOTIMP.FLATNESS_1 = atof(TRS.get_string(in_node, "FLATNESS_1"));
    CWIPLOTIMP.FLATNESS_2 = atof(TRS.get_string(in_node, "FLATNESS_2"));
    CWIPLOTIMP.FLATNESS_3 = atof(TRS.get_string(in_node, "FLATNESS_3"));
    CWIPLOTIMP.FLATNESS_4 = atof(TRS.get_string(in_node, "FLATNESS_4"));
    CWIPLOTIMP.FLATNESS_5 = atof(TRS.get_string(in_node, "FLATNESS_5"));
    CWIPLOTIMP.WEIGHT = atof(TRS.get_string(in_node, "WEIGHT"));
    CWIPLOTIMP.AIR_POCKET = atof(TRS.get_string(in_node, "AIR_POCKET"));
    TRS.copy(CWIPLOTIMP.IMPACT_NO, sizeof(CWIPLOTIMP.IMPACT_NO), in_node, "IMPACT_NO");
    CWIPLOTIMP.IMPACT_TIME = atoi(TRS.get_string(in_node, "IMPACT_TIME"));

    TRS.copy(CWIPLOTIMP.CREATE_USER_ID, sizeof(CWIPLOTIMP.CREATE_USER_ID), in_node, IN_USERID);
    memcpy(CWIPLOTIMP.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTIMP.CREATE_TIME));

    DBU_insert_cwiplotimp(&CWIPLOTIMP);
    if(DB_error_code != DB_SUCCESS)
    {
        TRS.add_fieldmsg(out_node, "CWIPLOTIMP Insert", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTIMP.LOT_ID), CWIPLOTIMP.LOT_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    TRS.add_string(in_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
    // End Lot 처리
    if (Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
