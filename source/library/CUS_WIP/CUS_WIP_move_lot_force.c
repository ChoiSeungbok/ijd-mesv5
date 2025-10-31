/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_move_lot_force.c
Description : Move Lot Force function

MES Version : 5.0

Function List


Detail Description
- MOVE 기능이 필요하여 SKIP기능으로 커스터마이징
- SKIP으로 처리 후, MWIPLOTSTS, MWIPLOTHIS, MWIPLOTMVH의 TRAN CODE 값을 MOVE로 변경

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/19  KY.JUNG        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Move_Lot_Force_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Move_Lot_Force_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Move_Lot_Force_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Move_Lot_Force()
- Tran Skip Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Force(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_MOVE_LOT_FORCE(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Move_Lot_Force", out_node);
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
CUS_WIP_MOVE_LOT_FORCE()
- Main sub function of "CUS_WIP_Move_Lot_Force" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_MOVE_LOT_FORCE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
    struct work_date_tag work_date;
    
    TRSNode *move_in_node;

	char unit[10];
	int unit_Change_Flag = 0;

    LOG_head("CUS_WIP_Move_Lot_Force");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(unit, ' ', sizeof(unit));

    /* Validation Check */
    if (CUS_WIP_Move_Lot_Force_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //lot정보 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
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

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    //skip 시작(skip기능을 이용하여 move 처리)
	move_in_node = TRS.add_node(in_node, "move_in_node");

    TRS.add_char(move_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(move_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(move_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(move_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_string(move_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    TRS.add_int(move_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);
    TRS.add_string(move_in_node, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(move_in_node, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(move_in_node, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_string(move_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));

    TRS.add_nstring(move_in_node, "TO_FLOW", TRS.get_string(in_node, "TO_FLOW"));
    TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

    //추가 정보성 데이터
    TRS.add_nstring(move_in_node, "LOCATION_1", TRS.get_string(in_node, "LOCATION_1"));
    TRS.add_nstring(move_in_node, "LOCATION_2", TRS.get_string(in_node, "LOCATION_2"));
    TRS.add_nstring(move_in_node, "LOCATION_3", TRS.get_string(in_node, "LOCATION_3"));
    
    TRS.add_string(move_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(move_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(move_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(move_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(move_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
	TRS.add_nstring(move_in_node, "PREV_MAT_FLOW", TRS.get_string(in_node, "PREV_MAT_FLOW"));
	TRS.add_nstring(move_in_node, "PREV_MAT_OPER", TRS.get_string(in_node, "PREV_MAT_OPER"));
	TRS.add_nstring(move_in_node, "PREV_PROD_OPER", TRS.get_string(in_node, "PREV_PROD_OPER"));


	TRS.add_nstring(move_in_node, "LOT_CMF_16", TRS.get_string(in_node, "LOT_CMF_16"));


	//FROM 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
	TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
	DBU_select_mwipoprdef_for_update(1, &MWIPOPRDEF_FROM);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	//TO 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
	TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
	DBU_select_mwipoprdef_for_update(1, &MWIPOPRDEF_TO);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	if (memcmp(MWIPOPRDEF_FROM.UNIT_1, MWIPOPRDEF_TO.UNIT_1, sizeof(MWIPOPRDEF_TO.UNIT_1)) != 0)
	{
		if (TRS.get_char(in_node, "FROM_TO_FLAG") == 'F')
		{
			memcpy(unit, MWIPOPRDEF_FROM.UNIT_1, sizeof(MWIPOPRDEF_FROM.UNIT_1));
			memcpy(MWIPOPRDEF_FROM.UNIT_1, MWIPOPRDEF_TO.UNIT_1, sizeof(MWIPOPRDEF_TO.UNIT_1));
			DBU_update_mwipoprdef(1, &MWIPOPRDEF_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			unit_Change_Flag = 1;
		}
		else if (TRS.get_char(in_node, "FROM_TO_FLAG") == 'T')
		{
			memcpy(unit, MWIPOPRDEF_TO.UNIT_1, sizeof(MWIPOPRDEF_TO.UNIT_1));
			memcpy(MWIPOPRDEF_TO.UNIT_1, MWIPOPRDEF_FROM.UNIT_1, sizeof(MWIPOPRDEF_FROM.UNIT_1));
			DBU_update_mwipoprdef(1, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			unit_Change_Flag = 1;
		}
	}

    if (CUS_WIP_Move_Lot_Force_Before_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_SKIP_LOT(s_msg_code, move_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

	if (unit_Change_Flag == 1)
	{
		if (TRS.get_char(in_node, "FROM_TO_FLAG") == 'F')
		{
			memcpy(MWIPOPRDEF_FROM.UNIT_1, unit, sizeof(unit));
			DBU_update_mwipoprdef(1, &MWIPOPRDEF_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		else if (TRS.get_char(in_node, "FROM_TO_FLAG") == 'T')
		{
			memcpy(MWIPOPRDEF_TO.UNIT_1, unit, sizeof(unit));
			DBU_update_mwipoprdef(1, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}

	TRS.set_char(move_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));

    if (CUS_WIP_Move_Lot_Force_After_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Move_Lot_Force_Validation()
- Validation Check sub function of "CUS_WIP_MOVE_LOT_FORCE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Force_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    /*if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

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
CUS_WIP_Move_Lot_Force_Before_Transaction()
- Main sub function of "CUS_WIP_MOVE_LOT_FORCE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Force_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Move_Lot_Force_After_Transaction()
- Main sub function of "CUS_WIP_MOVE_LOT_FORCE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Force_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPLOTHISX_TAG MWIPLOTHIS;
	struct MWIPLOTMVH_TAG MWIPLOTMVH;

	// LOT 정보 조회
	DBU_init_mwiplotstsx(&MWIPLOTSTS);
	TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
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

	// 제품 -> 완제품으로 이동됐다면, 이전 제품 FLOW & OPER 값 저장
	// 해당 LOT 완제품창고 -> 제품 창고로 이동 시, 사용할 예정.
	if (TRS.get_procstep(in_node) == '1')
	{
		if (COM_isspace(TRS.get_string(in_node, "PREV_MAT_FLOW"), sizeof(TRS.get_string(in_node, "PREV_MAT_FLOW"))) == MP_TRUE)
		{
			memset(MWIPLOTSTS.LOT_CMF_7, ' ', sizeof(MWIPLOTSTS.LOT_CMF_7));
			memset(MWIPLOTSTS.LOT_CMF_8, ' ', sizeof(MWIPLOTSTS.LOT_CMF_8));

		}
		else
		{
			TRS.copy(MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7), in_node, "PREV_MAT_FLOW");	// 이전 제품 FLOW
			TRS.copy(MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8), in_node, "PREV_MAT_OPER");	// 이전 제품 OPER
		}

		if (COM_isspace(TRS.get_string(in_node, "LOT_CMF_16"), sizeof(TRS.get_string(in_node, "LOT_CMF_16"))) == MP_TRUE)
		{
			memset(MWIPLOTSTS.LOT_CMF_16, ' ', sizeof(MWIPLOTSTS.LOT_CMF_16));

		}
		else
		{
			TRS.copy(MWIPLOTSTS.LOT_CMF_16, sizeof(MWIPLOTSTS.LOT_CMF_16), in_node, "LOT_CMF_16");
		}



		
	}
	// 완제품 창고 -> 제품 창고로 이동
	else if (TRS.get_procstep(in_node) == '2')
	{
		memset(MWIPLOTSTS.LOT_CMF_7, ' ', sizeof(MWIPLOTSTS.LOT_CMF_7));
		memset(MWIPLOTSTS.LOT_CMF_8, ' ', sizeof(MWIPLOTSTS.LOT_CMF_8));
		memset(MWIPLOTSTS.LOT_CMF_9, ' ', sizeof(MWIPLOTSTS.LOT_CMF_9));
	}
	// 완제품 창고 <-> 출하대기 창고
	else if (TRS.get_procstep(in_node) == '3')
	{
		if (COM_isspace(TRS.get_string(in_node, "PREV_PROD_OPER"), sizeof(TRS.get_string(in_node, "PREV_PROD_OPER"))) == MP_TRUE)
		{
			memset(MWIPLOTSTS.LOT_CMF_9, ' ', sizeof(MWIPLOTSTS.LOT_CMF_9));
		}
		else
		{
			TRS.copy(MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9), in_node, "PREV_PROD_OPER");	// 이전 완제품 창고
		}
	}
	// P급 창고 -> 생산 창고 //제품 창고 -> 제품 창고
	else if (TRS.get_procstep(in_node) == '4')
	{
		MWIPLOTSTS.NSTD_FLAG = ' ';
		memset(MWIPLOTSTS.NSTD_RET_FLOW, ' ', sizeof(MWIPLOTSTS.NSTD_RET_FLOW));
		memset(MWIPLOTSTS.NSTD_RET_OPER, ' ', sizeof(MWIPLOTSTS.NSTD_RET_OPER));
		memset(MWIPLOTSTS.NSTD_TIME, ' ', sizeof(MWIPLOTSTS.NSTD_TIME));
	}

	// TRAN CODE (SKIP -> MOVE)로 변경
	memcpy(MWIPLOTSTS.LAST_TRAN_CODE, MP_TRAN_CODE_MOVE, sizeof(MWIPLOTSTS.LAST_TRAN_CODE));
	DBU_update_mwiplotstsx(1, &MWIPLOTSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
		strcpy(s_msg_code, "ADM-0004");
		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}

	// LOT 정보 조회
	DBU_init_mwiplotstsx(&MWIPLOTSTS);
	TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
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

	// 해당 LOT 마지막 이력 조회
	DBU_init_mwiplothisx(&MWIPLOTHIS);
	TRS.copy(MWIPLOTHIS.FACTORY, sizeof(MWIPLOTHIS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
	MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
	DBU_select_mwiplothisx(1, &MWIPLOTHIS);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "MWIPLOTHIS SELECT", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}
	
	//이전 제품창고 FLOW, OPER 저장 및 TRAN CODE 변경(SKIP -> MOVE) //완제품, 반품 창고 -> 제품 창고
	memcpy(MWIPLOTHIS.LOT_CMF_7, MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7));
	memcpy(MWIPLOTHIS.LOT_CMF_8, MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8));
	memcpy(MWIPLOTHIS.LOT_CMF_9, MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9));

	MWIPLOTHIS.NSTD_FLAG = MWIPLOTSTS.NSTD_FLAG;
	memcpy(MWIPLOTHIS.NSTD_RET_FLOW, MWIPLOTSTS.NSTD_RET_FLOW, sizeof(MWIPLOTSTS.NSTD_RET_FLOW));
	memcpy(MWIPLOTHIS.NSTD_RET_OPER, MWIPLOTSTS.NSTD_RET_OPER, sizeof(MWIPLOTSTS.NSTD_RET_OPER));
	memcpy(MWIPLOTHIS.NSTD_TIME, MWIPLOTSTS.NSTD_TIME, sizeof(MWIPLOTSTS.NSTD_TIME));

	memcpy(MWIPLOTHIS.TRAN_CODE, MP_TRAN_CODE_MOVE, sizeof(MWIPLOTHIS.TRAN_CODE));
	DBU_update_mwiplothisx(1, &MWIPLOTHIS);
	if (DB_error_code != DB_SUCCESS)
	{
		//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
		strcpy(s_msg_code, "ADM-0004");
		TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHIS.FACTORY), MWIPLOTHIS.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}


	//이거 STORE때문에 필요하너여서 일단 삭제 필요없을것 같음 20220429
	/*
	// SKIP으로 생성된 이동 이력 조회
	DBC_init_mwiplotmvh(&MWIPLOTMVH);
	TRS.copy(MWIPLOTMVH.FACTORY, sizeof(MWIPLOTMVH.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTMVH.LOT_ID, sizeof(MWIPLOTMVH.LOT_ID), in_node, "LOT_ID");
	MWIPLOTMVH.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
	DBC_select_mwiplotmvh(1, &MWIPLOTMVH);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "MWIPLOTMVH SELECT", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTMVH.LOT_ID), MWIPLOTMVH.LOT_ID);
		TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTMVH.HIST_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}
	

	//TRAN CODE 변경(SKIP -> MOVE)
	memcpy(MWIPLOTMVH.TRAN_CODE, MP_TRAN_CODE_MOVE, sizeof(MWIPLOTMVH.TRAN_CODE));
	DBC_update_mwiplotmvh(1, &MWIPLOTMVH);
	if (DB_error_code != DB_SUCCESS)
	{
		//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
		strcpy(s_msg_code, "ADM-0004");
		TRS.add_fieldmsg(out_node, "MWIPLOTMVH UPDATE", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTMVH.FACTORY), MWIPLOTMVH.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTMVH.LOT_ID), MWIPLOTMVH.LOT_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}
	*/

    return MP_TRUE;
}