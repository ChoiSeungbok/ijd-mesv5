/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_move_shipment.c
    Description : Move Shipment

    MES Version : 4.0.0

    Function List
        - CUS_INV_Move_Shipment()
            + Move Shipment
        - CUS_INV_MOVE_SHIPMENT()
            + Main sub function of "CUS_INV_Move_Shipment" function
            + Move Shipment definition
        - CUS_INV_Move_Lot_Validation()
            + Validation Check sub function of "CUS_INV_MOVE_SHIPMENT" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/11/26  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_MOVE_SHIPMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Move_Shipment_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Move_Shipment_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Move_Shipment_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_MOVE_SHIPMENT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Move_Shipment()
        - Move Shipment
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Move_Shipment(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_MOVE_SHIPMENT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_MOVE_SHIPMENT", out_node);

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
CUS_INV_MOVE_SHIPMENT()
- Main sub function of "CUS_INV_Move_Shipment" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_MOVE_SHIPMENT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *move_in_node;
	TRSNode **move_lot_list;
	TRSNode *lot_list;
	int i;

	LOG_head("CUS_INV_MOVE_SHIPMENT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Move_Shipment_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	move_in_node = TRS.add_node(in_node, "move_in_node");
	CopyDefaultMembers(move_in_node, in_node);

	TRS.add_char(move_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	move_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(move_in_node, "LOT_LIST");
		TRS.add_nstring(lot_list, "LOT_ID", TRS.get_string(move_lot_list[i], "LOT_ID"));
	}

	TRS.add_nstring(move_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

	if (CUS_INV_Move_Shipment_Before_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_MOVE_SHIPMENT(s_msg_code, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Move_Shipment_After_Transaction(s_msg_code, 0, move_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_MOVE_SHIPMENT()
        - Main sub function of "CUS_INV_Move_Shipment" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_MOVE_SHIPMENT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
    struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;

    char s_sys_time[14];

	int i = 0;

	TRSNode **move_lot_list;
	TRSNode *regenerate_in;
	TRSNode *terminate_in;
	TRSNode *create_in;
	TRSNode *move_in;
	TRSNode *erpif_in;
    TRSNode *cmn_out;
	TRSNode *inv_list;
	 
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

	move_lot_list = TRS.get_list(in_node, "LOT_LIST");

	// 자재창고 또는 생산 창고 -> 완제품 창고 이동
	// 이동 후 INV LOT -> WIP LOT으로 변경
	if (TRS.get_char(in_node, IN_PROCSTEP) == '1')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
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

			if (COM_isnullspace(MINVLOTSTS_OLD.INV_CMF_4) == MP_FALSE)
			{
				//INV-0041 : 해당 자재는 Kitting된 자재입니다.
				strcpy(s_msg_code, "INV-0041");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPOPRDEF - FROM 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
			TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTSTS_OLD.OPER, sizeof(MINVLOTSTS_OLD.OPER));
			MWIPOPRDEF_FROM.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_FROM);
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

			// MWIPOPRDEF - TO 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
			TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
			MWIPOPRDEF_TO.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//20220421 공정같아도됨.해당 체크 삭제
			/*
			// 공정 체크
			if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == 0)
			{
				//INV-0045 : 현재 공정과 이동 공정이 같습니다.
				strcpy(s_msg_code, "INV-0045");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			// 사업부 생산 창고 -> 사업부 생산 창고 이동 불가
			if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID)) != 0)
			{
				//INV-0025 : 자재 LOT 사업부가 같지 않습니다.
				strcpy(s_msg_code, "INV-0025");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "FROM_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_FROM.AREA_ID), MWIPOPRDEF_FROM.AREA_ID);
				TRS.add_fieldmsg(out_node, "TO_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_TO.AREA_ID), MWIPOPRDEF_TO.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));
			memcpy(MINVLOTSTS.SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(MINVLOTSTS.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_MOVE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));

			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
			MINVLOTSTS.LAST_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
			MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;

			TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			//자재 LOT 이력 생성
			DBU_init_minvlothis(&MINVLOTHIS);

			//자재 LOT UPSERT & 자재 이력 INSERT
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

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//자재 LOT 이동 이력 생성
			if (CUS_INV_INSERT_LOT_MVH_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVLOTSTS) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//FROM AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
			TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
			TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
			TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
			memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}



			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
				CBASTXNDEF.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}




			//20220421 동일창고는 ERP 인터페이스 안되도록
			if (MWIPOPRDEF_FROM.OPER_CMF_1 != MWIPOPRDEF_TO.OPER_CMF_1)
			{

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

			}









			// MWIPLOTSTS - LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS.LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//INV LOT -> WIP LOT 변경
				//완제품 창고의 FLOW, OPER를 조회
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));


				//320220323 변경
				//DBU_select_mwipflwopr(5, &MWIPFLWOPR);


				//20220331 변경
				DBU_select_mwipflwopr(9, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//// INV LOT -> WIP LOT
				create_in = TRS.add_node(in_node, "create_in");
				CopyDefaultMembers(create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(create_in, "PROCSTEP", '1');
				TRS.add_string(create_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(create_in, "LOT_DESC", MP_CINV_TRAN_CODE_PROD_IN, strlen(MP_CINV_TRAN_CODE_PROD_IN));
				TRS.add_string(create_in, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
				TRS.add_int(create_in, "MAT_VER", MINVLOTSTS.MAT_VER);
				TRS.add_char(create_in, "LOT_TYPE", MP_LOT_TYPE_PROD);
				TRS.add_string(create_in, "FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
				TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_double(create_in, "QTY_1", MINVLOTSTS.QTY);
				TRS.add_char(create_in, "LOT_PRIORITY", '5');
				TRS.add_string(create_in, "OWNER_CODE", "PROD", strlen("PROD"));
				TRS.add_string(create_in, "CREATE_CODE", "PROD", strlen("PROD"));

				TRS.add_string(create_in, "LOT_CMF_11", "P", strlen("P"));
				//TRS.add_string(create_in, "LOT_CMF_11", MINVLOTSTS.INSP_RESULT_FLAG, sizeof(MINVLOTSTS.INSP_RESULT_FLAG));
				TRS.add_string(create_in, "LOT_CMF_14", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				//20211118 이전 플로우 공정 현재공정 같이 넣음 창고이동이나 품변에서 걸려서.
				TRS.add_string(create_in, "LOT_CMF_7", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(create_in, "LOT_CMF_8", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				//20211118 COMMENT 추가 //LAST_TRAN_COMMENT
				TRS.add_string(create_in, "COMMENT", MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT));
		
				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			else
			{
				if (MWIPLOTSTS.LOT_DEL_FLAG != 'Y')
				{
					// WIP-0630 : 해당 Lot은 삭제되어 있지 않습니다. Lot을 확인하세요.
					strcpy(s_msg_code, "WIP-0630");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//이미 생성된 LOT이라면 REGENERATE 처리
				regenerate_in = TRS.add_node(in_node, "regenerate_in");
				CopyDefaultMembers(regenerate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(regenerate_in, IN_PROCSTEP, '1');
				TRS.add_string(regenerate_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_string(regenerate_in, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
				TRS.add_string(regenerate_in, "LOT_CMF_7", MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7));
				TRS.add_string(regenerate_in, "LOT_CMF_8", MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8));
				TRS.add_string(regenerate_in, "LOT_CMF_9", MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9));
				TRS.add_string(regenerate_in, "LOT_CMF_10", MWIPLOTSTS.LOT_CMF_10, sizeof(MWIPLOTSTS.LOT_CMF_10));
				TRS.add_string(regenerate_in, "LOT_CMF_11", MWIPLOTSTS.LOT_CMF_11, sizeof(MWIPLOTSTS.LOT_CMF_11));
				TRS.add_string(regenerate_in, "LOT_CMF_12", MWIPLOTSTS.LOT_CMF_12, sizeof(MWIPLOTSTS.LOT_CMF_12));
				TRS.add_string(regenerate_in, "LOT_CMF_13", MWIPLOTSTS.LOT_CMF_13, sizeof(MWIPLOTSTS.LOT_CMF_13));
				TRS.add_string(regenerate_in, "LOT_CMF_14", MWIPLOTSTS.LOT_CMF_14, sizeof(MWIPLOTSTS.LOT_CMF_14));
				TRS.add_double(regenerate_in, "QTY_1", MINVLOTSTS.QTY);
				TRS.add_double(regenerate_in, "QTY_2", 0);
				TRS.add_double(regenerate_in, "QTY_3", 0);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_REGENERATE_LOT(s_msg_code, regenerate_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

			// 자재 LOT TERMINATE
			terminate_in = TRS.add_node(in_node, "terminate_in");
			CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT
			TRS.add_char(terminate_in, "PROCSTEP", '3');

			inv_list = TRS.add_node(terminate_in, "INV_LOT_LIST");
			TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_INV_TERMINATE_LOT_MAIN(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}
	// WIP LOT -> INV LOT 변경
	// 변경 후 완제품 창고, 반품 창고 -> 자재 창고 또는 생산 창고 이동
	else if (TRS.get_char(in_node, IN_PROCSTEP) == '2')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// MWIPLOTSTS - LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 자재 LOT 조회
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				// 자재 LOT 조회
				DBU_init_minvlotsts(&MINVLOTSTS_OLD);
				TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVLOTSTS_OLD.INV_LOT_ID, MWIPLOTSTS.LOT_CMF_14, sizeof(MWIPLOTSTS.LOT_CMF_14));
				DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//분할 자재 LOT ID 생성
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVLOTSTS.INV_LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				memcpy(MINVLOTSTS.INV_LOT_DESC, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				memcpy(MINVLOTSTS.INV_LOT_TYPE, MINVLOTSTS_OLD.INV_LOT_TYPE, sizeof(MINVLOTSTS_OLD.INV_LOT_TYPE));
				memcpy(MINVLOTSTS.INV_LOT_STATUS, MINVLOTSTS_OLD.INV_LOT_STATUS, sizeof(MINVLOTSTS_OLD.INV_LOT_STATUS));
				MINVLOTSTS.INV_LOT_PRIORITY = MINVLOTSTS_OLD.INV_LOT_PRIORITY;
				memcpy(MINVLOTSTS.MAT_ID, MINVLOTSTS_OLD.MAT_ID, sizeof(MINVLOTSTS_OLD.MAT_ID));
				MINVLOTSTS.MAT_VER = MINVLOTSTS_OLD.MAT_VER;
				MINVLOTSTS.QTY = MWIPLOTSTS.QTY_1;
				MINVLOTSTS.QTY_2 = 0;
				MINVLOTSTS.QTY_3 = 0;
				memcpy(MINVLOTSTS.UNIT, MINVLOTSTS_OLD.UNIT, sizeof(MINVLOTSTS_OLD.UNIT));
				memcpy(MINVLOTSTS.UNIT_2, MINVLOTSTS_OLD.UNIT_2, sizeof(MINVLOTSTS_OLD.UNIT_2));
				memcpy(MINVLOTSTS.UNIT_3, MINVLOTSTS_OLD.UNIT_3, sizeof(MINVLOTSTS_OLD.UNIT_3));
				memcpy(MINVLOTSTS.ORDER_ID, MINVLOTSTS_OLD.ORDER_ID, sizeof(MINVLOTSTS_OLD.ORDER_ID));
				memcpy(MINVLOTSTS.ADD_ORDER_ID_1, MINVLOTSTS_OLD.ADD_ORDER_ID_1, sizeof(MINVLOTSTS_OLD.ADD_ORDER_ID_1));
				memcpy(MINVLOTSTS.ADD_ORDER_ID_2, MINVLOTSTS_OLD.ADD_ORDER_ID_2, sizeof(MINVLOTSTS_OLD.ADD_ORDER_ID_2));
				memcpy(MINVLOTSTS.ADD_ORDER_ID_3, MINVLOTSTS_OLD.ADD_ORDER_ID_3, sizeof(MINVLOTSTS_OLD.ADD_ORDER_ID_3));
				memcpy(MINVLOTSTS.VENDOR_ID, MINVLOTSTS_OLD.VENDOR_ID, sizeof(MINVLOTSTS_OLD.VENDOR_ID));
				MINVLOTSTS.VENDOR_SITE_ID = MINVLOTSTS_OLD.VENDOR_SITE_ID;
				memcpy(MINVLOTSTS.VENDOR_LOT_ID, MINVLOTSTS_OLD.VENDOR_LOT_ID, sizeof(MINVLOTSTS_OLD.VENDOR_LOT_ID));
				memcpy(MINVLOTSTS.AREA_ID, MINVLOTSTS_OLD.AREA_ID, sizeof(MINVLOTSTS_OLD.AREA_ID));
				memset(MINVLOTSTS.SUB_AREA_ID, ' ', sizeof(MINVLOTSTS.SUB_AREA_ID));
				memset(MINVLOTSTS.LOCATION_1, ' ', sizeof(MINVLOTSTS.LOCATION_1));
				memset(MINVLOTSTS.LOCATION_2, ' ', sizeof(MINVLOTSTS.LOCATION_2));
				memset(MINVLOTSTS.LOCATION_3, ' ', sizeof(MINVLOTSTS.LOCATION_3));
				memcpy(MINVLOTSTS.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
				memset(MINVLOTSTS.LOC_NO, ' ', sizeof(MINVLOTSTS.LOC_NO));
				memset(MINVLOTSTS.RES_ID, ' ', sizeof(MINVLOTSTS.RES_ID));
				memset(MINVLOTSTS.PORT_ID, ' ', sizeof(MINVLOTSTS.PORT_ID));
				memset(MINVLOTSTS.SLOT_NO, ' ', sizeof(MINVLOTSTS.SLOT_NO));
				memset(MINVLOTSTS.CRR_ID, ' ', sizeof(MINVLOTSTS.CRR_ID));
				memset(MINVLOTSTS.LOT_ID, ' ', sizeof(MINVLOTSTS.LOT_ID));
				memcpy(MINVLOTSTS.RECV_DATE, MINVLOTSTS_OLD.RECV_DATE, sizeof(MINVLOTSTS_OLD.RECV_DATE));
				MINVLOTSTS.RECV_QTY = MWIPLOTSTS.QTY_1;
				memset(MINVLOTSTS.REASON_CODE, ' ', sizeof(MINVLOTSTS.REASON_CODE));
				MINVLOTSTS.LOAD_FLAG = 'N';
				MINVLOTSTS.TRANSIT_FLAG = 'N';
				MINVLOTSTS.DELETE_FLAG = 'N';
				memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
				memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
				memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
				MINVLOTSTS.HOLD_FLAG = 'N';
				memset(MINVLOTSTS.HOLD_CODE, ' ', sizeof(MINVLOTSTS.HOLD_CODE));
				MINVLOTSTS.INSP_FLAG = MINVLOTSTS_OLD.INSP_FLAG;
				memcpy(MINVLOTSTS.INSP_ID, MINVLOTSTS_OLD.INSP_ID, sizeof(MINVLOTSTS_OLD.INSP_ID));
				MINVLOTSTS.INSP_RESULT_FLAG = MINVLOTSTS_OLD.INSP_RESULT_FLAG;
				memset(MINVLOTSTS.INV_LOT_GRADE, ' ', sizeof(MINVLOTSTS.INV_LOT_GRADE));
				memcpy(MINVLOTSTS.DLV_NO, MINVLOTSTS_OLD.DLV_NO, sizeof(MINVLOTSTS_OLD.DLV_NO));
				MINVLOTSTS.DLV_SEQ = MINVLOTSTS_OLD.DLV_SEQ;
				memcpy(MINVLOTSTS.PO_NO, MINVLOTSTS_OLD.PO_NO, sizeof(MINVLOTSTS_OLD.PO_NO));
				MINVLOTSTS.PO_SEQ = MINVLOTSTS_OLD.PO_SEQ;
				memcpy(MINVLOTSTS.BL_NO, MINVLOTSTS_OLD.BL_NO, sizeof(MINVLOTSTS_OLD.BL_NO));
				MINVLOTSTS.BL_SEQ = MINVLOTSTS_OLD.BL_SEQ;
				MINVLOTSTS.PO_DISTRIBUTION_ID = MINVLOTSTS_OLD.PO_DISTRIBUTION_ID;
				memcpy(MINVLOTSTS.INV_CMF_1, MINVLOTSTS_OLD.INV_CMF_1, sizeof(MINVLOTSTS_OLD.INV_CMF_1));
				memcpy(MINVLOTSTS.INV_CMF_2, MINVLOTSTS_OLD.INV_CMF_2, sizeof(MINVLOTSTS_OLD.INV_CMF_2));
				memset(MINVLOTSTS.INV_CMF_3, ' ', sizeof(MINVLOTSTS.INV_CMF_3));	// 이전 공정
				memset(MINVLOTSTS.INV_CMF_4, ' ', sizeof(MINVLOTSTS.INV_CMF_4));
				memcpy(MINVLOTSTS.INV_CMF_5, MINVLOTSTS_OLD.INV_CMF_5, sizeof(MINVLOTSTS_OLD.INV_CMF_5)); // 기타 입고 유형
				memset(MINVLOTSTS.INV_CMF_6, ' ', sizeof(MINVLOTSTS.INV_CMF_6));
				memset(MINVLOTSTS.INV_CMF_7, ' ', sizeof(MINVLOTSTS.INV_CMF_7));
				memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8));
				memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9));
				memset(MINVLOTSTS.INV_CMF_10, ' ', sizeof(MINVLOTSTS.INV_CMF_10));
				memset(MINVLOTSTS.INV_CMF_11, ' ', sizeof(MINVLOTSTS.INV_CMF_11));
				memset(MINVLOTSTS.INV_CMF_12, ' ', sizeof(MINVLOTSTS.INV_CMF_12));
				memset(MINVLOTSTS.INV_CMF_13, ' ', sizeof(MINVLOTSTS.INV_CMF_13));
				memset(MINVLOTSTS.INV_CMF_14, ' ', sizeof(MINVLOTSTS.INV_CMF_14));
				memset(MINVLOTSTS.INV_CMF_15, ' ', sizeof(MINVLOTSTS.INV_CMF_15));
				memset(MINVLOTSTS.INV_CMF_16, ' ', sizeof(MINVLOTSTS.INV_CMF_16));
				memset(MINVLOTSTS.INV_CMF_17, ' ', sizeof(MINVLOTSTS.INV_CMF_17));
				memset(MINVLOTSTS.INV_CMF_18, ' ', sizeof(MINVLOTSTS.INV_CMF_18));
				memset(MINVLOTSTS.INV_CMF_19, ' ', sizeof(MINVLOTSTS.INV_CMF_19));
				memset(MINVLOTSTS.INV_CMF_20, ' ', sizeof(MINVLOTSTS.INV_CMF_20));
				memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_PROD_OUT, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
				memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
				MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = 1;
				MINVLOTSTS.LAST_HIST_SEQ = 1;
				memcpy(MINVLOTSTS.ORG_INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				MINVLOTSTS.FROM_TO_DIV = ' ';
				memset(MINVLOTSTS.FROM_TO_INV_LOT_ID, ' ', sizeof(MINVLOTSTS.FROM_TO_INV_LOT_ID));
				MINVLOTSTS.FROM_TO_HIST_SEQ = 0;
				MINVLOTSTS.CREATE_QTY = MWIPLOTSTS.QTY_1;
				MINVLOTSTS.CREATE_QTY_2 = 0;
				MINVLOTSTS.CREATE_QTY_3 = 0;
				TRS.copy(MINVLOTSTS.CREATE_USER_ID, sizeof(MINVLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

				//자재 LOT OLD 데이터
				//자재 생성 -> OLD, NEW 데이터 같음
				DBU_init_minvlotsts(&MINVLOTSTS_OLD);
				memcpy(&MINVLOTSTS_OLD, &MINVLOTSTS, sizeof(MINVLOTSTS));

				//자재 LOT 이력 생성
				DBU_init_minvlothis(&MINVLOTHIS);

				//자재 LOT UPSERT & 자재 이력 INSERT
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
			}
			else
			{
				// 자재 LOT이 죽어있는경우, 그대로 자재 LOT 완제품 창고로 부활(수량은 LOT의 수량으로)
				// 완제품 창고에서 DELETE된 LOT이기때문에, 무조건 완제품 창고
				if (MINVLOTSTS_OLD.DELETE_FLAG == 'Y')
				{
					// 자재 LOT REGENERATE
					regenerate_in = TRS.add_node(in_node, "regenerate_in");
					CopyDefaultMembers(regenerate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(regenerate_in, "PROCSTEP", '2');
					TRS.add_string(regenerate_in, "INV_LOT_ID", MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID));
					TRS.add_double(regenerate_in, "QTY", MWIPLOTSTS.QTY_1);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_REGENERATE_LOT_MAIN(s_msg_code, regenerate_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
				// 자재 LOT이 죽어 있지 않은 경우, 에러
				else
				{
					// WIP-0630 : 해당 Lot은 삭제되어 있지 않습니다. Lot을 확인하세요.
					strcpy(s_msg_code, "WIP-0630");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			// INV LOT으로 변경 후, WIP LOT TERMINATE
			terminate_in = TRS.add_node(in_node, "terminate_in");
			CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(terminate_in, "PROCSTEP", '1');
			TRS.add_string(terminate_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPOPRDEF - FROM 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
			TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTSTS_OLD.OPER, sizeof(MINVLOTSTS_OLD.OPER));
			MWIPOPRDEF_FROM.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_FROM);
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

			// MWIPOPRDEF - TO 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
			TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
			MWIPOPRDEF_TO.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			//20220421 공정같아도됨.해당 체크 삭제
			/*
			// 공정 체크
			if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == 0)
			{
				//INV-0045 : 현재 공정과 이동 공정이 같습니다.
				strcpy(s_msg_code, "INV-0045");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			// 사업부 생산 창고 -> 사업부 생산 창고 이동 불가
			if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID)) != 0)
			{
				//INV-0025 : 자재 LOT 사업부가 같지 않습니다.
				strcpy(s_msg_code, "INV-0025");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "FROM_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_FROM.AREA_ID), MWIPOPRDEF_FROM.AREA_ID);
				TRS.add_fieldmsg(out_node, "TO_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_TO.AREA_ID), MWIPOPRDEF_TO.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));
			memcpy(MINVLOTSTS.SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(MINVLOTSTS.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_MOVE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));

			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
			MINVLOTSTS.LAST_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
			MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;

			TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			//자재 LOT 이력 생성
			DBU_init_minvlothis(&MINVLOTHIS);

			//자재 LOT UPSERT & 자재 이력 INSERT
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

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//자재 LOT 이동 이력 생성
			if (CUS_INV_INSERT_LOT_MVH_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVLOTSTS) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//FROM AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
			TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
			TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
			TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
			memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
				CBASTXNDEF.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}





			//20220421 동일창고는 ERP 인터페이스 안되도록
			if (MWIPOPRDEF_FROM.OPER_CMF_1 != MWIPOPRDEF_TO.OPER_CMF_1)
			{
				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
	}
	// 반품 창고 -> 완제품 창고
	else if (TRS.get_char(in_node, IN_PROCSTEP) == '3')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// MWIPLOTSTS - LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), move_lot_list[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MWIPOPRDEF - FROM 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
			TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
			MWIPOPRDEF_FROM.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_FROM);
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

			// MWIPOPRDEF - TO 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
			TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
			MWIPOPRDEF_TO.INV_FLAG = 'Y';
			DBU_select_mwipoprdef(4, &MWIPOPRDEF_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//20220421 공정같아도됨.해당 체크 삭제
			/*
			// 공정 체크
			if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == 0)
			{
				//INV-0045 : 현재 공정과 이동 공정이 같습니다.
				strcpy(s_msg_code, "INV-0045");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			// 사업부 생산 창고 -> 사업부 생산 창고 이동 불가
			if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID)) != 0)
			{
				//INV-0025 : 자재 LOT 사업부가 같지 않습니다.
				strcpy(s_msg_code, "INV-0025");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "FROM_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_FROM.AREA_ID), MWIPOPRDEF_FROM.AREA_ID);
				TRS.add_fieldmsg(out_node, "TO_AREA_ID", MP_STR, sizeof(MWIPOPRDEF_TO.AREA_ID), MWIPOPRDEF_TO.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mwipflwopr(&MWIPFLWOPR);
			TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			DBU_select_mwipflwopr(5, &MWIPFLWOPR);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 완제품 창고끼리 MOVE
			move_in = TRS.add_node(in_node, "move_in");
			CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(move_in, "PROCSTEP", '4');
			TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
			TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
			TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//FROM AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
			TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
			TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
			TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
			memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
				CBASTXNDEF.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}



			//20220421 동일창고는 ERP 인터페이스 안되도록
			if (MWIPOPRDEF_FROM.OPER_CMF_1 != MWIPOPRDEF_TO.OPER_CMF_1)
			{
				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MWIPLOTSTS.QTY_1);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID)); //추후 이동지시번호가 들어올예정

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_double(erpif_in, "QTY", MWIPLOTSTS.QTY_1);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

			}


		}
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_Move_Shipment_Validation()
        - Validation Check sub function of "CUS_INV_MOVE_SHIPMENT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Shipment_Validation(char *s_msg_code,
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
CUS_INV_Move_Shipment_Before_Transaction()
- Main sub function of "CUS_INV_MOVE_SHIPMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Shipment_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Move_Shipment_After_Transaction()
- Main sub function of "CUS_INV_MOVE_SHIPMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Shipment_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}