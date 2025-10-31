/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_merge_lot.c
    Description : Merge Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Merge_Lot()
            + Merge Lot
        - CUS_INV_MERGE_LOT()
            + Main sub function of "CUS_INV_Merge_Lot" function
            + Merge Lot definition
        - CUS_INV_Merge_Lot_Validation()
            + Validation Check sub function of "CUS_INV_MERGE_LOT" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/04  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_MERGE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Merge_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Merge_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Merge_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_MERGE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Merge_Lot()
        - Merge Lot
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Merge_Lot(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_MERGE_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_MERGE_LOT", out_node);

    if(i_ret == MP_TRUE)
    {
        DB_commit();
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_MERGE_LOT()
- Main sub function of "CUS_INV_Merge_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_MERGE_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *merge_in_node;

	LOG_head("CUS_INV_MERGE_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Merge_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	merge_in_node = TRS.add_node(in_node, "merge_in_node");
	CopyDefaultMembers(merge_in_node, in_node);

	TRS.add_nstring(merge_in_node, "TO_INV_LOT_ID", TRS.get_string(in_node, "TO_INV_LOT_ID"));
	TRS.add_nstring(merge_in_node, "FROM_INV_LOT_ID", TRS.get_string(in_node, "FROM_INV_LOT_ID"));
	TRS.add_nstring(merge_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

	if (CUS_INV_Merge_Lot_Before_Transaction(s_msg_code, 0, merge_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_MERGE_LOT(s_msg_code, merge_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Merge_Lot_After_Transaction(s_msg_code, 0, merge_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_MERGE_LOT()
        - Main sub function of "CUS_INV_Merge_Lot" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_MERGE_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS_TO;
    struct MINVLOTSTS_TAG MINVLOTSTS_TO_OLD;
	struct MINVLOTSTS_TAG MINVLOTSTS_FROM;
	struct MINVLOTSTS_TAG MINVLOTSTS_FROM_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS_TO;
	struct MINVLOTHIS_TAG MINVLOTHIS_FROM;

    char s_sys_time[14];

    memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// TO 자재 LOT 조회
	DBU_init_minvlotsts(&MINVLOTSTS_TO_OLD);
	TRS.copy(MINVLOTSTS_TO_OLD.FACTORY, sizeof(MINVLOTSTS_TO_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_TO_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), in_node, "TO_INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_TO_OLD);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0044");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
		}
		TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_TO_OLD.FACTORY), MINVLOTSTS_TO_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// TO 자재 LOT 삭제 여부 체크
	if (MINVLOTSTS_TO_OLD.DELETE_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0013");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// TO 자재 LOT 잠금 여부 체크
	if (MINVLOTSTS_TO_OLD.HOLD_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0014");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 자재 LOT LOAD 체크
	if (MINVLOTSTS_TO_OLD.LOAD_FLAG == 'Y')
	{
		//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
		strcpy(s_msg_code, "INV-0059");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM 자재 LOT 조회
	DBU_init_minvlotsts(&MINVLOTSTS_FROM_OLD);
	TRS.copy(MINVLOTSTS_FROM_OLD.FACTORY, sizeof(MINVLOTSTS_FROM_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_FROM_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), in_node, "FROM_INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_FROM_OLD);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0044");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
		}
		TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.FACTORY), MINVLOTSTS_FROM_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM 자재 LOT 삭제 여부 체크
	if (MINVLOTSTS_FROM_OLD.DELETE_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0013");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM 자재 LOT 잠금 여부 체크
	if (MINVLOTSTS_FROM_OLD.HOLD_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0014");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 자재 LOT LOAD 체크
	if (MINVLOTSTS_FROM_OLD.LOAD_FLAG == 'Y')
	{
		//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
		strcpy(s_msg_code, "INV-0059");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 공정 체크
	if (memcmp(MINVLOTSTS_TO_OLD.OPER, MINVLOTSTS_FROM_OLD.OPER, sizeof(MINVLOTSTS_TO.OPER)) != 0)
	{
		strcpy(s_msg_code, "INV-0023");
		TRS.add_fieldmsg(out_node, "TO_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MINVLOTSTS_TO_OLD.OPER), MINVLOTSTS_TO_OLD.OPER);
		TRS.add_fieldmsg(out_node, "FROM_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.OPER), MINVLOTSTS_FROM_OLD.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 품목 체크
	if (memcmp(MINVLOTSTS_TO_OLD.MAT_ID, MINVLOTSTS_FROM_OLD.MAT_ID, sizeof(MINVLOTSTS_TO_OLD.MAT_ID)) != 0)
	{
		strcpy(s_msg_code, "INV-0024");
		TRS.add_fieldmsg(out_node, "TO_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "TO_MAT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.MAT_ID), MINVLOTSTS_TO_OLD.MAT_ID);
		TRS.add_fieldmsg(out_node, "FROM_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "FROM_MAT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.MAT_ID), MINVLOTSTS_FROM_OLD.MAT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM/TO 동일 자재 LOT ID 체크
	if (memcmp(MINVLOTSTS_TO_OLD.INV_LOT_ID, MINVLOTSTS_FROM_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID)) == 0)
	{
		strcpy(s_msg_code, "INV-0026");
		TRS.add_fieldmsg(out_node, "TO_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "FROM_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM/TO 동일 자재 LOT ID 체크
	if (memcmp(MINVLOTSTS_TO_OLD.INV_CMF_4, MINVLOTSTS_FROM_OLD.INV_CMF_4, sizeof(MINVLOTSTS_TO_OLD.INV_CMF_4)) != 0)
	{
		strcpy(s_msg_code, "INV-0040");
		TRS.add_fieldmsg(out_node, "TO_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_LOT_ID), MINVLOTSTS_TO_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "TO_KITTING_ID", MP_STR, sizeof(MINVLOTSTS_TO_OLD.INV_CMF_4), MINVLOTSTS_TO_OLD.INV_CMF_4);
		TRS.add_fieldmsg(out_node, "FROM_INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_LOT_ID), MINVLOTSTS_FROM_OLD.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "FROM_KITTING_ID", MP_STR, sizeof(MINVLOTSTS_FROM_OLD.INV_CMF_4), MINVLOTSTS_FROM_OLD.INV_CMF_4);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 사용할 MINVLOTSTS 데이터 초기화
	DBU_init_minvlotsts(&MINVLOTSTS_TO);
	DBU_init_minvlotsts(&MINVLOTSTS_FROM);

	// 자재 Lot 복사
	memcpy(&MINVLOTSTS_TO, &MINVLOTSTS_TO_OLD, sizeof(MINVLOTSTS_TO));
	memcpy(&MINVLOTSTS_FROM, &MINVLOTSTS_FROM_OLD, sizeof(MINVLOTSTS_FROM));


	// Update Inv Lot Status (TO 자재)
	MINVLOTSTS_TO.FROM_TO_DIV = 'T';
	memcpy(MINVLOTSTS_TO.FROM_TO_INV_LOT_ID, MINVLOTSTS_FROM.INV_LOT_ID, sizeof(MINVLOTSTS_TO.FROM_TO_INV_LOT_ID));

	// LAST 데이터 관리
	memcpy(MINVLOTSTS_TO.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_MERGE, sizeof(MINVLOTSTS_TO.LAST_TRAN_CODE));
	memcpy(MINVLOTSTS_TO.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS_TO.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS_TO.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
	MINVLOTSTS_TO.LAST_HIST_SEQ = MINVLOTSTS_TO_OLD.LAST_HIST_SEQ + 1;
	MINVLOTSTS_TO.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_TO_OLD.LAST_HIST_SEQ + 1;
	MINVLOTSTS_TO.FROM_TO_HIST_SEQ = MINVLOTSTS_FROM_OLD.LAST_ACTIVE_HIST_SEQ + 1;

	TRS.copy(MINVLOTSTS_TO.UPDATE_USER_ID, sizeof(MINVLOTSTS_TO.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTSTS_TO.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	// MERGE 수량 변경
	MINVLOTSTS_TO.QTY = MINVLOTSTS_TO.QTY + MINVLOTSTS_FROM_OLD.QTY;
	MINVLOTSTS_TO.QTY_2 = MINVLOTSTS_TO.QTY_2 + MINVLOTSTS_FROM_OLD.QTY_2;
	MINVLOTSTS_TO.QTY_3 = MINVLOTSTS_TO.QTY_3 + MINVLOTSTS_FROM_OLD.QTY_3;

	// Update Inv Lot Status (FROM 자재)
	//INTO Inv Lot 수량 
	MINVLOTSTS_FROM.QTY = 0;
	MINVLOTSTS_FROM.QTY_2 = 0;
	MINVLOTSTS_FROM.QTY_3 = 0;

	MINVLOTSTS_FROM.DELETE_FLAG = 'Y';
	memcpy(MINVLOTSTS_FROM.DELETE_CODE, MP_CINV_TRAN_CODE_RET_OUT, sizeof(MINVLOTSTS_FROM.DELETE_CODE));
	memcpy(MINVLOTSTS_FROM.DELETE_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS_FROM.DELETE_USER_ID, sizeof(MINVLOTSTS_FROM.DELETE_USER_ID), in_node, IN_USERID);

	MINVLOTSTS_FROM.FROM_TO_DIV = 'F';
	memcpy(MINVLOTSTS_FROM.FROM_TO_INV_LOT_ID, MINVLOTSTS_TO.INV_LOT_ID, sizeof(MINVLOTSTS_TO.INV_LOT_ID));

	TRS.copy(MINVLOTSTS_FROM.UPDATE_USER_ID, sizeof(MINVLOTSTS_FROM.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTSTS_FROM.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	// LAST 데이터 관리
	memcpy(MINVLOTSTS_FROM.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_MERGE, sizeof(MINVLOTSTS_FROM.LAST_TRAN_CODE));
	memcpy(MINVLOTSTS_FROM.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS_FROM.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS_FROM.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
	MINVLOTSTS_FROM.LAST_HIST_SEQ = MINVLOTSTS_FROM.LAST_HIST_SEQ + 1;
	MINVLOTSTS_FROM.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_FROM.LAST_HIST_SEQ + 1;
	MINVLOTSTS_FROM.FROM_TO_HIST_SEQ = MINVLOTSTS_TO.LAST_ACTIVE_HIST_SEQ;

	//TO 자재 LOT 이력 생성
	DBU_init_minvlothis(&MINVLOTHIS_TO);

	//TO 자재 LOT UPSERT & 자재 이력 INSERT
	if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_TO_OLD,
		&MINVLOTSTS_TO,
		&MINVLOTHIS_TO) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//TO 자재 LOT 분할/병합 이력 생성
	if (CUS_INV_INSERT_LOT_SWH_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_TO_OLD,
		&MINVLOTSTS_TO,
		&MINVLOTSTS_FROM) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//FROM 자재 LOT 이력 생성
	DBU_init_minvlothis(&MINVLOTHIS_FROM);

	//FROM 자재 LOT UPSERT & 자재 이력 INSERT
	if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_FROM_OLD,
		&MINVLOTSTS_FROM,
		&MINVLOTHIS_FROM) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//FROM 자재 LOT 분할/병합 이력 생성
	if (CUS_INV_INSERT_LOT_SWH_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_FROM_OLD,
		&MINVLOTSTS_FROM,
		&MINVLOTSTS_TO) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;

}

/*******************************************************************************
    CUS_INV_Merge_Lot_Validation()
        - Validation Check sub function of "CUS_INV_MERGE_LOT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Merge_Lot_Validation(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node)
{
    /*
	if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Merge_Lot_Before_Transaction()
- Main sub function of "CUS_INV_MERGE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Merge_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Merge_Lot_After_Transaction()
- Main sub function of "CUS_INV_MERGE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Merge_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}