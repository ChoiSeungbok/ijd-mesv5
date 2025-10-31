/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_merge_lot.c
Description : Tran Merge Lot function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/13  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Merge_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Merge_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Merge_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Merge_Lot()
- Tran Merge Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_MERGE_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Merge_Lot", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

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
CUS_WIP_MERGE_LOT()
- Main sub function of "CUS_WIP_Merge_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_MERGE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTS_TAG MWIPLOTSTS;
    struct MWIPLOTSTS_TAG MWIPLOTSTS_INTO;

    struct work_date_tag work_date;
    TRSNode *merge_in_node;    
    int i = 0;
    int j = 0;
    char s_member[5][101] = { "LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
    char s_member_name[101];
    char s_factory[10];

    LOG_head("CUS_WIP_Merge_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Merge_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBC_init_mwiplotsts(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBC_select_mwiplotsts(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    DBC_init_mwiplotsts(&MWIPLOTSTS_INTO);
    TRS.copy(MWIPLOTSTS_INTO.LOT_ID, sizeof(MWIPLOTSTS_INTO.LOT_ID), in_node, "INTO_LOT_ID");
    DBC_select_mwiplotsts(1, &MWIPLOTSTS_INTO);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS_INTO.LOT_ID), MWIPLOTSTS_INTO.LOT_ID);

        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    merge_in_node = TRS.add_node(in_node, "merge_in_node");
    TRS.add_char(merge_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(merge_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(merge_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(merge_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    TRS.add_string(merge_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    TRS.add_int(merge_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);
    TRS.add_string(merge_in_node, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));    
    TRS.add_int(merge_in_node, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(merge_in_node, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_string(merge_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));   
    TRS.add_string(merge_in_node, "CRR_ID", MWIPLOTSTS.CRR_ID, sizeof(MWIPLOTSTS.CRR_ID));
    TRS.add_double(merge_in_node, "MOVE_QTY_1", TRS.get_double(in_node, "MOVE_QTY_1"));
    TRS.add_double(merge_in_node, "MOVE_QTY_2", TRS.get_double(in_node, "MOVE_QTY_2"));
    TRS.add_double(merge_in_node, "MOVE_QTY_3", TRS.get_double(in_node, "MOVE_QTY_3"));    
    TRS.add_string(merge_in_node, "INTO_LOT_ID", MWIPLOTSTS_INTO.LOT_ID, sizeof(MWIPLOTSTS_INTO.LOT_ID));
    TRS.add_nstring(merge_in_node, "INTO_CRR_ID", TRS.get_string(in_node, "INTO_CRR_ID"));
    TRS.add_nstring(merge_in_node, "INTO_RES_ID", TRS.get_string(in_node, "INTO_RES_ID"));
    TRS.add_nstring(merge_in_node, "INTO_PORT_ID", TRS.get_string(in_node, "INTO_PORT_ID"));
    TRS.add_string(merge_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(merge_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(merge_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(merge_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_char(merge_in_node, "NO_AUTOMATIC_TERMINATE_LOT", ' ');
    //분류에서는 2차형상, 3차형상에서는 공정중 MERGE가 된다.
    TRS.add_char(merge_in_node, "SKIP_OPER_CHECK", TRS.get_char(in_node, "SKIP_OPER_CHECK"));  

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 20; i++)
        {
            sprintf(s_member_name, "%s%d", s_member[j], i + 1);
            TRS.add_nstring(merge_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
        }
    }

    if (CUS_WIP_Merge_Lot_Before_Transaction(s_msg_code, 0, merge_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_MERGE_LOT(s_msg_code, merge_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Merge_Lot_After_Transaction(s_msg_code, 0, merge_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Merge_Lot_Validation()
- Validation Check sub function of "CUS_WIP_MERGE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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


    if (COM_isnullspace(TRS.get_string(in_node, "INTO_LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "INTO_LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Merge_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_MERGE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    /*
    struct MWIPOPRDEF_TAG   MWIPOPRDEF;

    // 공정 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0010 : 이 공정은 존재 하지 않습니다.
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_char(in_node, "SKIP_OPER_CHECK") != 'Y')
    {
        if (MWIPOPRDEF.INV_FLAG != 'Y')
        {
            //WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0657");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    */

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Merge_Lot_After_Transaction()
- Main sub function of "CUS_WIP_MERGE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX_INTO;
    struct MWIPOPRDEF_TAG   MWIPOPRDEF;
    struct CWIPLOTTRC_TAG   CWIPLOTTRC;

    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    //MERGE될 lot 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTSX_INTO);
    TRS.copy(MWIPLOTSTSX_INTO.LOT_ID, sizeof(MWIPLOTSTSX_INTO.LOT_ID), in_node, "INTO_LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_INTO);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_INTO.FACTORY), MWIPLOTSTSX_INTO.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_INTO.LOT_ID), MWIPLOTSTSX_INTO.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    
    //MERGE되어 사라질 LOT
    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    // 공정 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0010 : 이 공정은 존재 하지 않습니다.
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //20250526 GRT 물류에서 요청함, 생산에서 물류제품창고의 재고를 분할하고 가지고 가는 경우가 있어서. 막음.
    if (memcmp(MWIPOPRDEF.OPER_CMF_2, "N", strlen("N")) == 0)
    {
        // WIP-0699 :분할병합을 진행할수 없는 공정입니다.확인바랍니다.
        strcpy(s_msg_code, "WIP-0699");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //LOT 추적 테이블에 저장
    DBU_init_cwiplottrc(&CWIPLOTTRC);
    TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
    memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
    memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
    memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX_INTO.LOT_ID, sizeof(MWIPLOTSTSX_INTO.LOT_ID));
    CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX_INTO.LAST_ACTIVE_HIST_SEQ;
    memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));   
    CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
	memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
    DBU_insert_cwiplottrc(&CWIPLOTTRC);
    if (DB_error_code != DB_SUCCESS)
    {
        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        strcpy(s_msg_code, "ADM-0004");
        TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
        TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    return MP_TRUE;
}