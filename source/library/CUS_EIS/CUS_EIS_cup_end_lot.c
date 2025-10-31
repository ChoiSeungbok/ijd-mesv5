/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_cup_end_lot.c
    Description : Cup 조립 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

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

int CUS_EIS_CUP_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Cup_End_Lot()
        - Cup 조립 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Cup_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_CUP_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Cup_End_Lot", out_node);

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
    CUS_EIS_CUP_END_LOT()
        - Main sub function of "CUS_EIS_Cup_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_CUP_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTCUP_TAG CWIPLOTCUP;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;
    struct MWIPMATFLW_TAG MWIPMATFLW;
    struct CWIPLOTBAS_TAG CWIPLOTBAS;

    struct work_date_tag work_date;
    char cExist;

    TRSNode *create_lot_in;
    TRSNode *start_lot_in;
    TRSNode *end_lot_in;
    char sResult[20];
    char s_last_tran_time[14];

    LOG_head("CUS_EIS_CUP_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        TRS.add_fieldmsg(out_node, "Lot is empty", MP_NVST);
        TRS.add_fieldmsg(out_node, "RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));

        return MP_FALSE;
    }

    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    if(DB_error_code == DB_SUCCESS)
    {
        cExist = 'Y';
    }
    else if(DB_error_code == DB_NOT_FOUND)
    {
        cExist = 'N';
    }
    else
    {
        strcpy(s_msg_code, "WIP-0004");		// WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MWIPLOTSTS Select 1", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

        return MP_FALSE;
    }

    DBU_init_cwiplotbas(&CWIPLOTBAS);
    TRS.copy(CWIPLOTBAS.MASTER_LOT_ID, sizeof(CWIPLOTBAS.MASTER_LOT_ID), in_node, "MASTER_LOT_ID");
    TRS.copy(CWIPLOTBAS.RES_ID, sizeof(CWIPLOTBAS.RES_ID), in_node, "RES_ID");
    DBU_select_cwiplotbas(1, &CWIPLOTBAS);
    if(DB_error_code != DB_SUCCESS)
    {
        if(DB_error_code == DB_NOT_FOUND)
            // WIP-0602 : 기준 Lot 정보를 찾을 수 없습니다.
            strcpy(s_msg_code, "WIP-0602");
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "CWIPLOTBAS Select 1", MP_NVST);
        TRS.add_fieldmsg(out_node, "MASTER_LOT_ID", MP_STR, sizeof(CWIPLOTBAS.MASTER_LOT_ID), CWIPLOTBAS.MASTER_LOT_ID);
        TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPLOTBAS.RES_ID), CWIPLOTBAS.RES_ID);

        return MP_FALSE;
    }

    DBU_init_mwipmatflw(&MWIPMATFLW);
    TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPMATFLW.MAT_ID, CWIPLOTBAS.MAT_ID, sizeof(MWIPMATFLW.MAT_ID));
    MWIPMATFLW.MAT_VER = 1;
    MWIPMATFLW.FLOW_SEQ_NUM = 1;
    DBU_select_mwipmatflw(3, &MWIPMATFLW);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0593 : 해당 제품은 Flow가 설정되지 않았습니다. 제품 셋업의 플로우 부여에서 설정하세요.
            strcpy(s_msg_code, "WIP-0593");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT 3", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_NSTRING, TRS.get_string(in_node, "FACTORY"));
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));

        return MP_FALSE;
    }

    DBU_init_mwipflwopr(&MWIPFLWOPR);
    TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPFLWOPR.FLOW));
    DBU_select_mwipflwopr(2, &MWIPFLWOPR);
    if(DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0601 : 이 Flow에 공정이 설정되어 있지 않습니다.
            strcpy(s_msg_code, "WIP-0601");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT 2", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
        TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

        return MP_FALSE;
    }

    if(cExist == 'N')
    {
        create_lot_in = TRS.add_node(in_node, "Create_Lot_In");
        CopyDefaultMembers(create_lot_in, in_node);
        TRS.add_char(create_lot_in, IN_PROCSTEP, '1');

        TRS.add_nstring(create_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_string(create_lot_in, "MAT_ID", CWIPLOTBAS.MAT_ID, sizeof(CWIPLOTBAS.MAT_ID));
        TRS.add_int(create_lot_in, "MAT_VER", 1);
        TRS.add_char(create_lot_in, "LOT_TYPE", 'P');
        TRS.add_string(create_lot_in, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
        TRS.add_int(create_lot_in, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
        TRS.add_string(create_lot_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
        TRS.add_double(create_lot_in, "QTY_1", 1);
        TRS.add_char(create_lot_in, "LOT_PRIORITY", '1');
        TRS.add_nstring(create_lot_in, "CREATE_CODE", "PROD");
        TRS.add_nstring(create_lot_in, "OWNER_CODE", "PROD");
        TRS.add_string(create_lot_in, "ORDER_ID", CWIPLOTBAS.ORDER_ID, sizeof(CWIPLOTBAS.ORDER_ID));

        if (CUS_WIP_CREATE_LOT(s_msg_code, create_lot_in, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    }   
        
    start_lot_in = TRS.create_node("Start_Lot_In");

    CopyDefaultMembers(start_lot_in, in_node);
    TRS.add_char(start_lot_in, IN_PROCSTEP, '1');

    TRS.add_nstring(start_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(start_lot_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(start_lot_in, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(start_lot_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_string(start_lot_in, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    TRS.add_nstring(start_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if (memcmp(MWIPLOTSTS.LAST_TRAN_TIME, MRASRESDEF.LAST_EVENT_TIME, sizeof(MWIPLOTSTS.LAST_TRAN_TIME)) > 0)
        memcpy(s_last_tran_time, MWIPLOTSTS.LAST_TRAN_TIME, sizeof(s_last_tran_time));
    else
        memcpy(s_last_tran_time, MRASRESDEF.LAST_EVENT_TIME, sizeof(s_last_tran_time));

    if (TRS.mem_cmp(in_node, "START_TIME", s_last_tran_time, sizeof(s_last_tran_time)) > 0 &&
        TRS.mem_cmp(in_node, "START_TIME", gs_sys_time, sizeof(gs_sys_time)) < 0)
    {
        TRS.add_nstring(start_lot_in, "BACK_TIME", TRS.get_string(in_node, "START_TIME"));
    }

    if (CUS_WIP_START_LOT(s_msg_code, start_lot_in, out_node) == MP_FALSE)
    {
        TRS.free_node(start_lot_in);
        return MP_FALSE;
    }

    TRS.free_node(start_lot_in);

    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    DBU_init_cwiplotcup(&CWIPLOTCUP);

    TRS.copy(CWIPLOTCUP.LOT_ID, sizeof(CWIPLOTCUP.LOT_ID), in_node, "LOT_ID");
    CWIPLOTCUP.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
    memcpy(CWIPLOTCUP.OPER,   MWIPLOTSTS.OPER, sizeof(CWIPLOTCUP.OPER));
    memcpy(CWIPLOTCUP.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTCUP.MAT_ID));
    memcpy(CWIPLOTCUP.FLOW,   MWIPLOTSTS.FLOW, sizeof(CWIPLOTCUP.FLOW));
    CWIPLOTCUP.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
    TRS.copy(CWIPLOTCUP.GRADE, sizeof(CWIPLOTCUP.GRADE), in_node, "GRADE");
    TRS.copy(CWIPLOTCUP.RES_ID, sizeof(CWIPLOTCUP.RES_ID), in_node, "RES_ID");
    TRS.copy(CWIPLOTCUP.FACTORY, sizeof(CWIPLOTCUP.FACTORY), in_node, IN_FACTORY);
    memcpy(CWIPLOTCUP.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTCUP.WORK_DATE));
    memcpy(CWIPLOTCUP.WORK_TIME, gs_sys_time, sizeof(CWIPLOTCUP.WORK_TIME));
    memcpy(CWIPLOTCUP.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTCUP.DAY_NIGHT));

    CWIPLOTCUP.EDC_HIST_SEQ = TRS.get_int(in_node, "EDC_HIST_SEQ");

    TRS.copy(CWIPLOTCUP.MASTER_LOT_ID, sizeof(CWIPLOTCUP.MASTER_LOT_ID), in_node, "MASTER_LOT_ID");

    TRS.copy(CWIPLOTCUP.RECIPE_ID, sizeof(CWIPLOTCUP.RECIPE_ID), in_node, "RECIPE_ID");
    TRS.copy(CWIPLOTCUP.START_TIME, sizeof(CWIPLOTCUP.START_TIME), in_node, "START_TIME");
    TRS.copy(CWIPLOTCUP.END_TIME, sizeof(CWIPLOTCUP.END_TIME), in_node, "END_TIME");
    TRS.copy(CWIPLOTCUP.JUDGMENT, sizeof(CWIPLOTCUP.JUDGMENT), in_node, "JUDGMENT");

    TRS.copy(CWIPLOTCUP.INPUT_TIME, sizeof(CWIPLOTCUP.INPUT_TIME), in_node, "INPUT_TIME");
    CWIPLOTCUP.CUP_INPUT_COUNTER = atoi(TRS.get_string(in_node, "CUP_INPUT_COUNTER"));
    TRS.copy(CWIPLOTCUP.CUP_TYPE, sizeof(CWIPLOTCUP.CUP_TYPE), in_node, "CUP_TYPE");
    CWIPLOTCUP.CUP_WEIGHT_STANDARD = atof(TRS.get_string(in_node, "CUP_WEIGHT_STANDARD"));
    CWIPLOTCUP.CUP_WEIGHT_VALUE = atof(TRS.get_string(in_node, "CUP_WEIGHT_VALUE"));
    TRS.copy(CWIPLOTCUP.POWDER_INJECTION_LOCATION, sizeof(CWIPLOTCUP.POWDER_INJECTION_LOCATION), in_node, "POWDER_INJECTION_LOCATION");
    CWIPLOTCUP.ROBOT_MEASURABLE_STANDARD = atof(TRS.get_string(in_node, "ROBOT_MEASURABLE_STANDARD"));
    CWIPLOTCUP.ROBOT_MEASURABLE_VALUE = atof(TRS.get_string(in_node, "ROBOT_MEASURABLE_VALUE"));
    CWIPLOTCUP.PRECISION_WEIGH_STANDARD = atof(TRS.get_string(in_node, "PRECISION_WEIGH_STANDARD"));
    CWIPLOTCUP.PRECISION_WEIGH_VALUE = atof(TRS.get_string(in_node, "PRECISION_WEIGH_VALUE"));
    TRS.copy(CWIPLOTCUP.PRESS_TIME, sizeof(CWIPLOTCUP.PRESS_TIME), in_node, "PRESS_TIME");
    CWIPLOTCUP.NUMBER_OF_PRESSES = atoi(TRS.get_string(in_node, "NUMBER_OF_PRESSES"));
    TRS.copy(CWIPLOTCUP.KNIFE_FLATTENING_USE, sizeof(CWIPLOTCUP.KNIFE_FLATTENING_USE), in_node, "KNIFE_FLATTENING_USE");
    TRS.copy(CWIPLOTCUP.CARBIDE_TYPE, sizeof(CWIPLOTCUP.CARBIDE_TYPE), in_node, "CARBIDE_TYPE");
    CWIPLOTCUP.CARBIDE_SAMPLE_PASSED_NO = atoi(TRS.get_string(in_node, "CARBIDE_SAMPLE_PASSED_NO"));
    TRS.copy(sResult, sizeof(sResult), in_node, "CARBIDE_SAMPLE_RESULT");
    CWIPLOTCUP.CARBIDE_SAMPLE_RESULT = sResult[0];
    CWIPLOTCUP.CARBIDE_WEIGHT_STANDARD = atof(TRS.get_string(in_node, "CARBIDE_WEIGHT_STANDARD"));
    CWIPLOTCUP.CARBIDE_WEIGHT_VALUE = atof(TRS.get_string(in_node, "CARBIDE_WEIGHT_VALUE"));
    CWIPLOTCUP.CARBIDE_HEIGHT_STANDARD = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_STANDARD"));
    CWIPLOTCUP.CARBIDE_HEIGHT_P1 = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_P1"));
    CWIPLOTCUP.CARBIDE_HEIGHT_P2 = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_P2"));
    CWIPLOTCUP.CARBIDE_HEIGHT_P3 = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_P3"));
    CWIPLOTCUP.CARBIDE_HEIGHT_P4 = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_P4"));
    CWIPLOTCUP.CARBIDE_HEIGHT_P5 = atof(TRS.get_string(in_node, "CARBIDE_HEIGHT_P5"));
    CWIPLOTCUP.CARBIDE_OUTER_DIAMETER_STANDARD  = atof(TRS.get_string(in_node, "CARBIDE_OUTER_DIAMETER_STANDARD"));
    CWIPLOTCUP.CARBIDE_OUTER_DIAMETER_VALUE = atof(TRS.get_string(in_node, "CARBIDE_OUTER_DIAMETER_VALUE"));
    CWIPLOTCUP.COMPLETE_FLATNESS_STANDARD = atof(TRS.get_string(in_node, "COMPLETE_FLATNESS_STANDARD"));
    CWIPLOTCUP.COMPLETE_FLATNESS_VALUE = atof(TRS.get_string(in_node, "COMPLETE_FLATNESS_VALUE"));
    CWIPLOTCUP.COMPLETE_WEIGHT_STANDARD = atof(TRS.get_string(in_node, "COMPLETE_WEIGHT_STANDARD"));
    CWIPLOTCUP.COMPLETE_WEIGHT_VALUE = atof(TRS.get_string(in_node, "COMPLETE_WEIGHT_VALUE"));
    CWIPLOTCUP.CARBIDE_INPUT_COUNT = atoi(TRS.get_string(in_node, "CARBIDE_INPUT_COUNT"));
    CWIPLOTCUP.IMPACT_PROCESS_INPUT_COUNT = atoi(TRS.get_string(in_node, "IMPACT_PROCESS_INPUT_COUNT"));
    CWIPLOTCUP.NG_COUND = atoi(TRS.get_string(in_node, "NG_COUND"));

    TRS.copy(CWIPLOTCUP.CREATE_USER_ID, sizeof(CWIPLOTCUP.CREATE_USER_ID), in_node, IN_USERID);
    memcpy(CWIPLOTCUP.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCUP.CREATE_TIME));

    DBU_insert_cwiplotcup(&CWIPLOTCUP);
    if(DB_error_code != DB_SUCCESS)
    {
        TRS.add_fieldmsg(out_node, "CWIPLOTCUP Insert", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTCUP.LOT_ID), CWIPLOTCUP.LOT_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    // 사용한 자재 반영
    //TRSNode *use_material_in;
    //use_material_in = TRS.create_node("Use_Material_In");
    //CopyDefaultMembers(use_material_in, in_node);

    //TRS.add_char(use_material_in, IN_PROCSTEP, '1');
    //TRS.add_string(use_material_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    //TRS.add_nstring(use_material_in, "OPER", TRS.get_string(in_node, "OPER"));
    //TRS.add_nstring(use_material_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
    //TRS.add_nstring(use_material_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    //TRS.add_nstring(use_material_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

    //if (INPUT_INV_LOT(s_msg_code, use_material_in, out_node) == MP_FALSE)
    //{
    //    TRS.free_node(use_material_in);
    //    return MP_FALSE;
    //}

    //TRS.free_node(use_material_in);

    end_lot_in = TRS.create_node("End_Lot_In");
    CopyDefaultMembers(end_lot_in, in_node);
    TRS.add_nstring(end_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(end_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_string(end_lot_in, "ORDER_ID", CWIPLOTBAS.ORDER_ID, sizeof(CWIPLOTBAS.ORDER_ID));
    TRS.add_nstring(end_lot_in, "END_TIME", TRS.get_string(in_node, "END_TIME"));

    // End Lot 처리
    if (Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, end_lot_in, out_node) == MP_FALSE)
    {
        TRS.free_node(end_lot_in);
        return MP_FALSE;
    }

    TRS.free_node(end_lot_in);

    // 평탄 공정 시작
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    start_lot_in = TRS.create_node("Start_Lot_In");

    CopyDefaultMembers(start_lot_in, in_node);
    TRS.add_char(start_lot_in, IN_PROCSTEP, '1');

    TRS.add_nstring(start_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(start_lot_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(start_lot_in, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(start_lot_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_string(start_lot_in, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    TRS.add_nstring(start_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if (CUS_WIP_START_LOT(s_msg_code, start_lot_in, out_node) == MP_FALSE)
    {
        TRS.free_node(start_lot_in);
        return MP_FALSE;
    }

    TRS.free_node(start_lot_in);

    end_lot_in = TRS.create_node("End_Lot_In");
    CopyDefaultMembers(end_lot_in, in_node);
    TRS.add_nstring(end_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(end_lot_in, "ORDER_ID", CWIPLOTBAS.ORDER_ID, sizeof(CWIPLOTBAS.ORDER_ID));
    TRS.add_nstring(end_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    // End Lot 처리
    if (Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, end_lot_in, out_node) == MP_FALSE)
    {
        TRS.free_node(end_lot_in);
        return MP_FALSE;
    }

    TRS.free_node(end_lot_in);

    return MP_TRUE;
}
