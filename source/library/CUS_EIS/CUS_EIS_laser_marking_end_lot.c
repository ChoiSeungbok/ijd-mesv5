/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_laser_marking_end_lot.c
    Description : Laser Marking 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

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

int CUS_EIS_LASER_MARKING_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Laser_Marking_End_Lot()
        - Laser Marking 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Laser_Marking_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_LASER_MARKING_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Laser_Marking_End_Lot", out_node);

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
    CUS_EIS_LASER_MARKING_END_LOT()
        - Main sub function of "CUS_EIS_Laser_Marking_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_LASER_MARKING_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTLMK_TAG CWIPLOTLMK;

    struct work_date_tag work_date;
   // TRSNode *send_in;
    //TRSNode *cmn_out;

    LOG_head("CUS_EIS_LASER_MARKING_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Check_LotStatus(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if(Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if(memcmp(MWIPLOTSTS.LOT_STATUS, MP_LOT_STATUS_PROC, strlen(MP_LOT_STATUS_PROC)) != 0)
    {
        // WIP-0595 : 해당 Lot은 작업시작이 되지 않았습니다.
        strcpy(s_msg_code, "WIP-0595");
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
        TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTS.LOT_STATUS), MWIPLOTSTS.LOT_STATUS);

        return MP_FALSE;
    }

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    DBU_init_cwiplotlmk(&CWIPLOTLMK);
    TRS.copy(CWIPLOTLMK.LOT_ID, sizeof(CWIPLOTLMK.LOT_ID), in_node, "LOT_ID");
    CWIPLOTLMK.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
    DBU_select_cwiplotlmk(1, &CWIPLOTLMK);

    memcpy(CWIPLOTLMK.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTLMK.OPER));
    memcpy(CWIPLOTLMK.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTLMK.MAT_ID));
    memcpy(CWIPLOTLMK.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTLMK.FLOW));
    CWIPLOTLMK.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
    TRS.copy(CWIPLOTLMK.GRADE, sizeof(CWIPLOTLMK.GRADE), in_node, "GRADE");
    TRS.copy(CWIPLOTLMK.RES_ID, sizeof(CWIPLOTLMK.RES_ID), in_node, "RES_ID");
    TRS.copy(CWIPLOTLMK.FACTORY, sizeof(CWIPLOTLMK.FACTORY), in_node, IN_FACTORY);
    memcpy(CWIPLOTLMK.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTLMK.WORK_DATE));
    memcpy(CWIPLOTLMK.WORK_TIME, gs_sys_time, sizeof(CWIPLOTLMK.WORK_TIME));
    memcpy(CWIPLOTLMK.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTLMK.DAY_NIGHT));
    TRS.copy(CWIPLOTLMK.LASER_MARKING, sizeof(CWIPLOTLMK.LASER_MARKING), in_node, "LASER_MARKING_FLAG");
    TRS.copy(CWIPLOTLMK.INK_PRINT, sizeof(CWIPLOTLMK.INK_PRINT), in_node, "INK_PRINT_FLAG");
    TRS.copy(CWIPLOTLMK.INPUT_NO, sizeof(CWIPLOTLMK.INPUT_NO), in_node, "INPUT_NO");
    TRS.copy(CWIPLOTLMK.ORDER_ID, sizeof(CWIPLOTLMK.ORDER_ID), in_node, "ORDER_ID");

    if (DB_error_code == DB_SUCCESS)
    {
        TRS.copy(CWIPLOTLMK.UPDATE_USER_ID, sizeof(CWIPLOTLMK.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTLMK.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTLMK.UPDATE_TIME));

        DBU_update_cwiplotlmk(1, &CWIPLOTLMK);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CWIPLOTLMK Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTLMK.LOT_ID), CWIPLOTLMK.LOT_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }
    else if (DB_error_code == DB_NOT_FOUND)
    {
        TRS.copy(CWIPLOTLMK.CREATE_USER_ID, sizeof(CWIPLOTLMK.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTLMK.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTLMK.CREATE_TIME));

        DBU_insert_cwiplotlmk(&CWIPLOTLMK);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CWIPLOTLMK Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTLMK.LOT_ID), CWIPLOTLMK.LOT_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }
	if (Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
		return MP_FALSE;
	/*
    if (memcmp(CWIPLOTLMK.INK_PRINT, "NG", strlen("NG")) == MP_FALSE)
    {
        send_in = TRS.add_node(in_node, "send_in");
        TRS.add_char(send_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(send_in, in_node);

        TRS.add_nstring(send_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_string(send_in, "LOT_ID", CWIPLOTLMK.LOT_ID, sizeof(CWIPLOTLMK.LOT_ID));
        TRS.add_string(send_in, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_EIS_START_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);
    }
    else
    {
        // End Lot 처리
        if (Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
            return MP_FALSE;
    }
	*/

    return MP_TRUE;
}
