/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_ship_lot.c
Description : Tran ship Lot function

MES Version : 5.0

Function List


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/01  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Ship_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Ship_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Ship_Lot()
- Tran Ship Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Ship_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_SHIP_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Ship_Lot", out_node);
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
CUS_WIP_SHIP_LOT()
- Main sub function of "CUS_WIP_Ship_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTS_TAG MWIPLOTSTS;
    TRSNode *ship_in_node;
    struct work_date_tag work_date;
    char s_factory[10];

    int i = 0;
    int j = 0;
    char s_member[5][101] = { "LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
    char s_member_name[101];

    LOG_head("CUS_WIP_Ship_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Ship_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    
    //lot정보 조회
    DBC_init_mwiplotsts(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
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

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    //ship 시작
    ship_in_node = TRS.add_node(in_node, "ship_in_node");

    TRS.add_char(ship_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(ship_in_node, in_node);


    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(ship_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(ship_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_string(ship_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
	TRS.add_nstring(ship_in_node, "TO_FACTORY", TRS.get_string(in_node, "TO_FACTORY"));
	TRS.add_nstring(ship_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

    //추가 정보성 데이터
    TRS.add_nstring(ship_in_node, "LOCATION_1", TRS.get_string(in_node, "LOCATION_1"));
    TRS.add_nstring(ship_in_node, "LOCATION_2", TRS.get_string(in_node, "LOCATION_2"));
    TRS.add_nstring(ship_in_node, "LOCATION_3", TRS.get_string(in_node, "LOCATION_3"));
    
    TRS.add_string(ship_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(ship_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(ship_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(ship_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 20; i++)
        {
            sprintf(s_member_name, "%s%d", s_member[j], i + 1);
            TRS.add_nstring(ship_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
        }
    }

    if (CUS_WIP_Ship_Lot_Before_Transaction(s_msg_code, 0, ship_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_SHIP_LOT(s_msg_code, ship_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Ship_Lot_After_Transaction(s_msg_code, 0, ship_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Ship_Lot_Validation()
- Validation Check sub function of "CUS_WIP_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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



    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Ship_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Ship_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Ship_Lot_After_Transaction()
- Main sub function of "CUS_WIP_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Ship_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}