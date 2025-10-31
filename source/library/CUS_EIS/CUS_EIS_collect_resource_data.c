/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_collect_resource_data.c
    Description : 설비에서 받은 Count 누적(EDR & MD 설비)

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/26  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_COLLECT_RESOURCE_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_RESOURCE_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node);

/*******************************************************************************
    CEIS_Collect_Resource_Data()
        - 설비에서 받은 Count 누적(EDR & MD 설비)
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Resource_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_RESOURCE_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Resource_Data", out_node);

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
    CUS_EIS_COLLECT_RESOURCE_DATA()
        - Main sub function of "CUS_EIS_Collect_Resource_Data" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_RESOURCE_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTCUM_TAG CWIPLOTCUM;
    struct CWIPLOTDRY_TAG CWIPLOTDRY;

    struct work_date_tag work_date;

    LOG_head("CUS_EIS_COLLECT_RESOURCE_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Validation_CUS_EIS_COLLECT_RESOURCE_DATA(s_msg_code, in_node, &MRASRESDEF, out_node) == MP_FALSE)
        return MP_FALSE;

    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPLOTSTS.START_RES_ID, sizeof(MWIPLOTSTS.START_RES_ID), in_node, "RES_ID");
    DBU_select_mwiplotstsx(2, &MWIPLOTSTS);
    if(DB_error_code == DB_NOT_FOUND)
    {
        // WIP-0587 : 해당 설비에서 작업 시작된 Lot이 없습니다.
        strcpy(s_msg_code, "WIP-0587");

        TRS.add_fieldmsg(out_node, "Select MWIPLOTSTS 3", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "START_RES_ID", DT_STRING, sizeof(MWIPLOTSTS.START_RES_ID), MWIPLOTSTS.START_RES_ID);
        TRS.add_fieldmsg(out_node, "LOT_DEL_FLAG", DT_CHAR, MWIPLOTSTS.LOT_DEL_FLAG);
        TRS.add_fieldmsg(out_node, "LOT_DEL_CODE", DT_STRING, sizeof(MWIPLOTSTS.LOT_DEL_CODE), MWIPLOTSTS.LOT_DEL_CODE);

        return MP_FALSE;
    }

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    // EDR&MD,DRY-CIP 설비의 Count 누적
    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_cwiplotcum(&CWIPLOTCUM);
        memcpy(CWIPLOTCUM.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CWIPLOTCUM.LOT_ID));
        CWIPLOTCUM.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;

        DBU_select_cwiplotcum(1, &CWIPLOTCUM);
        if (DB_error_code == DB_SUCCESS)
        {
            CWIPLOTCUM.CUM++;

            memcpy(CWIPLOTCUM.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTCUM.WORK_DATE));
            memcpy(CWIPLOTCUM.WORK_TIME, gs_sys_time, sizeof(CWIPLOTCUM.WORK_TIME));
            memcpy(CWIPLOTCUM.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTCUM.DAY_NIGHT));

            memcpy(CWIPLOTCUM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCUM.UPDATE_TIME));
            TRS.copy(CWIPLOTCUM.UPDATE_USER_ID, sizeof(CWIPLOTCUM.UPDATE_USER_ID), in_node, IN_USERID);

            DBU_update_cwiplotcum(1, &CWIPLOTCUM);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");

                TRS.add_fieldmsg(out_node, "Update CWIPLOTCUM 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTCUM.FACTORY), CWIPLOTCUM.FACTORY);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTCUM.HIST_SEQ);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else if (DB_error_code == DB_NOT_FOUND)
        {

            memcpy(CWIPLOTCUM.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTCUM.OPER));
            memcpy(CWIPLOTCUM.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTCUM.MAT_ID));
            memcpy(CWIPLOTCUM.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTCUM.FLOW));
            CWIPLOTCUM.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;

            memcpy(CWIPLOTCUM.RES_ID, MWIPLOTSTS.START_RES_ID, sizeof(CWIPLOTCUM.RES_ID));

            CWIPLOTCUM.CUM = 1;

            memcpy(CWIPLOTCUM.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CWIPLOTCUM.FACTORY));
            memcpy(CWIPLOTCUM.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTCUM.WORK_DATE));
            memcpy(CWIPLOTCUM.WORK_TIME, gs_sys_time, sizeof(CWIPLOTCUM.WORK_TIME));
            memcpy(CWIPLOTCUM.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTCUM.DAY_NIGHT));

            memcpy(CWIPLOTCUM.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCUM.CREATE_TIME));
            TRS.copy(CWIPLOTCUM.CREATE_USER_ID, sizeof(CWIPLOTCUM.CREATE_USER_ID), in_node, IN_USERID);

            DBU_insert_cwiplotcum(&CWIPLOTCUM);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");

                TRS.add_fieldmsg(out_node, "Insert CWIPLOTCUM", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTCUM.LOT_ID), CWIPLOTCUM.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTCUM.HIST_SEQ);

                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPLOTCUM.OPER), CWIPLOTCUM.OPER);
                TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CWIPLOTCUM.MAT_ID), CWIPLOTCUM.MAT_ID);
                TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(CWIPLOTCUM.FLOW), CWIPLOTCUM.FLOW);
                TRS.add_fieldmsg(out_node, "FLOW_SEQ_NUM", DT_INT, CWIPLOTCUM.FLOW_SEQ_NUM);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }
    // DRY 설비
    else if(TRS.get_procstep(in_node) == '2')
    {
        DBU_init_cwiplotdry(&CWIPLOTDRY);
        memcpy(CWIPLOTDRY.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CWIPLOTDRY.LOT_ID));
        CWIPLOTDRY.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
        
        memcpy(CWIPLOTDRY.WORK_TIME, gs_sys_time, sizeof(CWIPLOTDRY.WORK_TIME));
        memcpy(CWIPLOTDRY.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTDRY.OPER));
        memcpy(CWIPLOTDRY.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTDRY.MAT_ID));
        memcpy(CWIPLOTDRY.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTDRY.FLOW));
        CWIPLOTDRY.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;

        memcpy(CWIPLOTDRY.RES_ID, MWIPLOTSTS.START_RES_ID, sizeof(CWIPLOTDRY.RES_ID));

        memcpy(CWIPLOTDRY.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CWIPLOTDRY.FACTORY));
        memcpy(CWIPLOTDRY.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTDRY.WORK_DATE));
        memcpy(CWIPLOTDRY.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTDRY.DAY_NIGHT));

        CWIPLOTDRY.OPERATION_PRESS = TRS.get_int(in_node, "OPERATION_PRESS");
        CWIPLOTDRY.PRESS_HOLD_TIME_1 = TRS.get_int(in_node, "PRESS_HOLD_TIME_1");
        CWIPLOTDRY.PRESS_HOLD_TIME_2 = TRS.get_int(in_node, "PRESS_HOLD_TIME_2");
        CWIPLOTDRY.PRESS_OPERATION_FLAG = TRS.get_string(in_node, "PRESS_OPERATION_FLAG")[0];
        CWIPLOTDRY.DISCHARGE_OPERATION_FLAG = TRS.get_string(in_node, "DISCHARGE_OPERATION_FLAG")[0];

        memcpy(CWIPLOTDRY.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTDRY.CREATE_TIME));
        TRS.copy(CWIPLOTDRY.CREATE_USER_ID, sizeof(CWIPLOTDRY.CREATE_USER_ID), in_node, IN_USERID);

        DBU_insert_cwiplotdry(&CWIPLOTDRY);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_fieldmsg(out_node, "Insert CWIPLOTDRY", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTDRY.LOT_ID), CWIPLOTDRY.LOT_ID);
            TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTDRY.HIST_SEQ);
            TRS.add_fieldmsg(out_node, "WORK_TIME", DT_STRING, sizeof(CWIPLOTDRY.WORK_TIME), CWIPLOTDRY.WORK_TIME);

            TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPLOTDRY.OPER), CWIPLOTDRY.OPER);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CWIPLOTDRY.MAT_ID), CWIPLOTDRY.MAT_ID);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(CWIPLOTDRY.FLOW), CWIPLOTDRY.FLOW);
            TRS.add_fieldmsg(out_node, "FLOW_SEQ_NUM", DT_INT, CWIPLOTDRY.FLOW_SEQ_NUM);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
    Validation_CUS_EIS_COLLECT_RESOURCE_DATA()
        - Main sub function of "CUS_EIS_COLLECT_RESOURCE_DATA" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - struct MRASRESDEF_TAG *MRASRESDEF : 설비
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_RESOURCE_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node)
{
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "12") == MP_FALSE)
        return MP_FALSE;

    if(Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
