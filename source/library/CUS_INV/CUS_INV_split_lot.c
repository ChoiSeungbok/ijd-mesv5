/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_split_lot.c
    Description : Split Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Split_Lot()
            + Split Lot
        - CUS_INV_SPLIT_LOT()
            + Main sub function of "CUS_INV_Split_Lot" function
            + Split Lot definition
        - CUS_INV_Split_Lot_Validation()
            + Validation Check sub function of "CUS_INV_SPLIT_LOT" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/03  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_SPLIT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Split_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Split_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Split_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_SPLIT_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Split_Lot()
        - Split Lot
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Split_Lot(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_SPLIT_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_SPLIT_LOT", out_node);

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
CUS_INV_SPLIT_LOT()
- Main sub function of "CUS_INV_Split_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_SPLIT_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	struct MINVLOTSTS_TAG MINVLOTSTS;
	TRSNode *split_in_node;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	char split_lot_id[25];
	char s_org_inv_lot_id[26];

	LOG_head("CUS_INV_SPLIT_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Split_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(split_lot_id, ' ', sizeof(split_lot_id));
	memset(s_org_inv_lot_id, 0x00, sizeof(s_org_inv_lot_id));

	split_in_node = TRS.add_node(in_node, "split_in_node");
	CopyDefaultMembers(split_in_node, in_node);

	TRS.add_nstring(split_in_node, "INV_LOT_ID", TRS.get_string(in_node, "INV_LOT_ID"));
	TRS.add_double(split_in_node, "SPLIT_QTY", TRS.get_double(in_node, "SPLIT_QTY"));
	TRS.add_double(split_in_node, "SPLIT_QTY_2", TRS.get_double(in_node, "SPLIT_QTY_2"));
	TRS.add_double(split_in_node, "SPLIT_QTY_3", TRS.get_double(in_node, "SPLIT_QTY_3"));
	TRS.add_nstring(split_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

	if (COM_isnullspace(TRS.get_string(in_node, "SPLIT_LOT_ID")) == MP_FALSE)
	{
		memcpy(split_lot_id, TRS.get_string(in_node, "SPLIT_LOT_ID"), strlen(TRS.get_string(in_node, "SPLIT_LOT_ID")));
	}
	else
	{
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "INV_LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		memcpy(s_org_inv_lot_id, MINVLOTSTS.ORG_INV_LOT_ID, sizeof(MINVLOTSTS.ORG_INV_LOT_ID));




		gen_in_node = TRS.add_node(in_node, "gen_in_node");
		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW, strlen(MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW));
		TRS.add_string(gen_in_node, "LOT_ID", s_org_inv_lot_id, strlen(s_org_inv_lot_id)); // Original Lot으로 발번
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

		memcpy(split_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
		TRS.free_node(cmn_out);
	}
	
	TRS.add_string(split_in_node, "SPLIT_LOT_ID", split_lot_id, sizeof(split_lot_id));





	if (CUS_INV_Split_Lot_Before_Transaction(s_msg_code, 0, split_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_SPLIT_LOT(s_msg_code, split_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Split_Lot_After_Transaction(s_msg_code, 0, split_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_SPLIT_LOT()
        - Main sub function of "CUS_INV_Split_Lot" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_SPLIT_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
	struct MINVLOTSTS_TAG MINVLOTSTS_CHILD;
	struct MINVLOTSTS_TAG MINVLOTSTS_CHILD_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MINVLOTHIS_TAG MINVLOTHIS_CHILD;

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

	DBU_init_minvlotsts(&MINVLOTSTS_OLD);
	TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), in_node, "INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
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
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 자재 LOT 삭제 여부 체크
	if (MINVLOTSTS_OLD.DELETE_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0013");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 자재 LOT 잠금 여부 체크
	if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
	{
		strcpy(s_msg_code, "INV-0014");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 자재 LOT LOAD 체크
	if (MINVLOTSTS_OLD.LOAD_FLAG == 'Y')
	{
		//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
		strcpy(s_msg_code, "INV-0059");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 사용할 MINVLOTSTS 데이터 초기화
	DBU_init_minvlotsts(&MINVLOTSTS);
	DBU_init_minvlotsts(&MINVLOTSTS_CHILD);
	DBU_init_minvlotsts(&MINVLOTSTS_CHILD_OLD);

	// Mother Inv Lot 복사
	memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

	// Child Inv Lot 복사 
	// Child Inv Lot ID 적용
	memcpy(&MINVLOTSTS_CHILD, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));
	TRS.copy(MINVLOTSTS_CHILD.INV_LOT_ID, sizeof(MINVLOTSTS_CHILD.INV_LOT_ID), in_node, "SPLIT_LOT_ID");
	// Update Inv Lot Status (Mother)
	MINVLOTSTS.FROM_TO_DIV = 'F';
	TRS.copy(MINVLOTSTS.FROM_TO_INV_LOT_ID, sizeof(MINVLOTSTS.FROM_TO_INV_LOT_ID), in_node, "SPLIT_LOT_ID");

	// LAST 데이터 관리
	memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_SPLIT, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
	memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
	MINVLOTSTS.LAST_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
	MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
	MINVLOTSTS.FROM_TO_HIST_SEQ = 1;

	TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	// SPLIT 수량 변경
	MINVLOTSTS.QTY = MINVLOTSTS.QTY - TRS.get_double(in_node, "SPLIT_QTY");

	if (MINVLOTSTS.QTY < 0)
	{
		//INV-0021 : 입력한 수량은 한계치를 초과하였습니다.수량을 체크해주세요.
		strcpy(s_msg_code, "INV-0021");
		TRS.add_fieldmsg(out_node, "QTY", MP_DBL, TRS.get_double(in_node, "SPLIT_QTY"));
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	MINVLOTSTS.QTY_2 = MINVLOTSTS.QTY_2 - TRS.get_double(in_node, "SPLIT_QTY_2");
	MINVLOTSTS.QTY_3 = MINVLOTSTS.QTY_3 - TRS.get_double(in_node, "SPLIT_QTY_3");

	// 전량 SPLIT -> 자재 LOT 삭제
	if (MINVLOTSTS.QTY <= 0)
	{
		MINVLOTSTS.DELETE_FLAG = 'Y';
		memcpy(MINVLOTSTS.DELETE_CODE, MP_CINV_TRAN_CODE_RET_OUT, sizeof(MINVLOTSTS.DELETE_CODE));
		memcpy(MINVLOTSTS.DELETE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVLOTSTS.DELETE_USER_ID, sizeof(MINVLOTSTS.DELETE_USER_ID), in_node, IN_USERID);
	}

	// Update Inv Lot Status (Child)

	//Child Inv Lot 수량 
	MINVLOTSTS_CHILD.QTY = TRS.get_double(in_node, "SPLIT_QTY");
	MINVLOTSTS_CHILD.QTY_2 = TRS.get_double(in_node, "SPLIT_QTY_2");
	MINVLOTSTS_CHILD.QTY_3 = TRS.get_double(in_node, "SPLIT_QTY_3");

	MINVLOTSTS_CHILD.CREATE_QTY = TRS.get_double(in_node, "SPLIT_QTY");
	MINVLOTSTS_CHILD.CREATE_QTY_2 = TRS.get_double(in_node, "SPLIT_QTY_2");
	MINVLOTSTS_CHILD.CREATE_QTY_3 = TRS.get_double(in_node, "SPLIT_QTY_3");

	MINVLOTSTS_CHILD.FROM_TO_DIV = 'T';
	memcpy(MINVLOTSTS_CHILD.FROM_TO_INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

	TRS.copy(MINVLOTSTS_CHILD.CREATE_USER_ID, sizeof(MINVLOTSTS_CHILD.CREATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTSTS_CHILD.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS_CHILD.UPDATE_USER_ID, sizeof(MINVLOTSTS_CHILD.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTSTS_CHILD.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	// LAST 데이터 관리
	memcpy(MINVLOTSTS_CHILD.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_SPLIT, sizeof(MINVLOTSTS_CHILD.LAST_TRAN_CODE));
	memcpy(MINVLOTSTS_CHILD.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
	TRS.copy(MINVLOTSTS_CHILD.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS_CHILD.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
	MINVLOTSTS_CHILD.LAST_HIST_SEQ = 1;
	MINVLOTSTS_CHILD.LAST_ACTIVE_HIST_SEQ = 1;
	MINVLOTSTS_CHILD.FROM_TO_HIST_SEQ = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;

	//Mother 자재 LOT 이력 생성
	DBU_init_minvlothis(&MINVLOTHIS);

	//Mother LOT UPSERT & 자재 이력 INSERT
	if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_OLD,
		&MINVLOTSTS,
		&MINVLOTHIS) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBU_init_minvlotsts(&MINVLOTSTS_OLD);
	TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), in_node, "INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
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
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//Mother 자재 LOT 분할/병합 이력 생성
	if (CUS_INV_INSERT_LOT_SWH_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_OLD,
		&MINVLOTSTS,
		&MINVLOTSTS_CHILD) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBU_init_minvlotsts(&MINVLOTSTS_OLD);
	TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), in_node, "INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
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
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//Child 자재 LOT 이력 생성
	DBU_init_minvlothis(&MINVLOTHIS_CHILD);

	//Child 자재 LOT UPSERT & 자재 이력 INSERT
	if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_CHILD_OLD,
		&MINVLOTSTS_CHILD,
		&MINVLOTHIS_CHILD) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//Child 자재 LOT 분할/병합 이력 생성
	if (CUS_INV_INSERT_LOT_SWH_HISTORY(s_msg_code,
		in_node,
		out_node,
		s_sys_time,
		&MINVLOTSTS_CHILD_OLD,
		&MINVLOTSTS_CHILD,
		&MINVLOTSTS) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	TRS.add_nstring(out_node, "SPLIT_LOT_ID", TRS.get_string(in_node, "SPLIT_LOT_ID"));

	DBU_init_minvlotsts(&MINVLOTSTS_OLD);
	TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), in_node, "INV_LOT_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
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
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;

}

/*******************************************************************************
    CUS_INV_Split_Lot_Validation()
        - Validation Check sub function of "CUS_INV_SPLIT_LOT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Split_Lot_Validation(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node)
{
	struct MINVLOTSTS_TAG MINVLOTSTS;

	if (TRS.get_int(in_node, "LAST_ACTIVE_HIST_SEQ") > 0)
	{
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "INV_LOT_ID");

		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0044");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}

			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			COM_out_msg_log_write(s_msg_code, "CUS_INV_Split_Lot", out_node);
			//return MP_TRUE;
			return MP_FALSE;
		}

		if (TRS.get_int(in_node, "LAST_ACTIVE_HIST_SEQ") != MINVLOTSTS.LAST_ACTIVE_HIST_SEQ)
		{
			strcpy(s_msg_code, "WIP-0113");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "LAST_ACTIVE_HIST_SEQ", MP_INT, MINVLOTSTS.LAST_ACTIVE_HIST_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			COM_out_msg_log_write(s_msg_code, "CUS_INV_Split_Lot", out_node);
			//return MP_TRUE;
			return MP_FALSE;
		}
	}

	//
	if (COM_dbl_round(TRS.get_double(in_node, "SPLIT_QTY"), 5, 'U') == 0) {
		
		strcpy(s_msg_code, "INV-0074");
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		COM_out_msg_log_write(s_msg_code, "CUS_INV_Split_Lot", out_node);
		return MP_FALSE;
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Split_Lot_Before_Transaction()
- Main sub function of "CUS_INV_SPLIT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Split_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Split_Lot_After_Transaction()
- Main sub function of "CUS_INV_SPLIT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Split_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}