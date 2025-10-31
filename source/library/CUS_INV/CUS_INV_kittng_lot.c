/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_kitting_lot.c
    Description : Kitting Inv Lot

    MES Version : 5.2.0

    Function List
        - CUS_INV_Kitting_Lot()
            + Kitting Inv Lot
        - CUS_INV_KITTING_LOT()
            + Main Sub function of "CUS_INV_Kitting_Lot"
            + (called by "CUS_INV_Kitting_Lot")
        - CUS_INV_Kitting_Lot_Validation()
            + Validation Check sub function of "CUS_INV_KITTING_LOT" function
            + (called by "CUS_INV_KITTING_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/09/07  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_KITTING_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Kitting_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_KITTING_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Kitting_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Kitting_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Kitting_Lot()
        - Kitting Inv Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Kitting_Lot_In_Tag *CUS_INV_Kitting_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Kitting_Lot(TRSNode *in_node,
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_KITTING_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_KITTING_LOT", out_node);

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
CUS_INV_KITTING_LOT_MAIN()
- Main sub function of "CUS_INV_KITTING_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_KITTING_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_KITTING_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *kitting_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	char kitting_id[26];

	LOG_head("CUS_INV_KITTING_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Kitting_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	kitting_in_node = TRS.add_node(in_node, "kitting_in_node");
	CopyDefaultMembers(kitting_in_node, in_node);

	TRS.add_char(kitting_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	memset(kitting_id, ' ', sizeof(kitting_id));

	if (COM_isnullspace(TRS.get_string(in_node, "KITTING_ID")) == MP_FALSE)
	{
		memcpy(kitting_id, TRS.get_string(in_node, "KITTING_ID"), strlen(TRS.get_string(in_node, "KITTING_ID")));
	}
	else
	{
		gen_in_node = TRS.add_node(in_node, "gen_in_node");
		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_KITTING_ID, strlen(MP_ID_ROLE_KITTING_ID));
		TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
		TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(kitting_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);
	}

	TRS.add_string(kitting_in_node, "KITTING_ID", kitting_id, sizeof(kitting_id));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(kitting_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
		TRS.add_double(inv_list, "KITTING_QTY", TRS.get_double(inv_lot_list[i], "KITTING_QTY"));
	}
	
	if (CUS_INV_Kitting_Lot_Before_Transaction(s_msg_code, 0, kitting_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_KITTING_LOT(s_msg_code, kitting_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Kitting_Lot_After_Transaction(s_msg_code, 0, kitting_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_KITTING_LOT()
        - Main sub function of "CUS_INV_Kitting_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_KITTING_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_KITTING_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
	struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MINVLOTSTS_TAG MINVLOTSTS_COUNT;

	TRSNode *split_in;
	TRSNode *cmn_out;
	TRSNode **inv_lot_list;

	char split_lot_id[25];
    char s_sys_time[14];

	int i;
	double d_lot_count = 0;
	
		  
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	//PROCSTEP = 1 -> KITTING
	if (TRS.get_procstep(in_node) == '1')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
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
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 자재 LOT 잠금 여부 체크
			if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
			{
				strcpy(s_msg_code, "WIP-0059");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
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

			// KITTING 자재 체크
			if (COM_isnullspace(MINVLOTSTS_OLD.INV_CMF_4) == MP_FALSE)
			{
				strcpy(s_msg_code, "INV-0041");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// KITTING 수량이 LOT 수량과 다르면 SPLIT
			if (MINVLOTSTS_OLD.QTY != TRS.get_double(inv_lot_list[i], "KITTING_QTY"))
			{
				memset(split_lot_id, ' ', sizeof(split_lot_id));

				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(split_in, "PROCSTEP", '1');
				TRS.add_string(split_in, "INV_LOT_ID", MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID));
				TRS.add_int(split_in, "LAST_ACTIVE_HIST_SEQ", MINVLOTSTS_OLD.LAST_ACTIVE_HIST_SEQ);
				TRS.add_double(split_in, "SPLIT_QTY", TRS.get_double(inv_lot_list[i], "KITTING_QTY"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_INV_SPLIT_LOT_MAIN(s_msg_code, split_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				memcpy(split_lot_id, TRS.get_string(cmn_out, "SPLIT_LOT_ID"), strlen(TRS.get_string(cmn_out, "SPLIT_LOT_ID")));

				TRS.free_node(cmn_out);
			}
			else
			{
				memcpy(split_lot_id, MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID));
			}

			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTSTS_OLD.INV_LOT_ID, split_lot_id, sizeof(split_lot_id));
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

			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

			// 자재 LOT & KITTING ID 매핑
			TRS.copy(MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4), in_node, "KITTING_ID");	// INV_CMF_4(KITTING_ID)
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_KITTING, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
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

			TRS.add_nstring(out_node, "KITTING_ID", TRS.get_string(in_node, "KITTING_ID"));
		}
	}
	//PROCSTEP = 2 -> UNKITTING
	else if (TRS.get_procstep(in_node) == '2')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
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
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 자재 LOT 잠금 여부 체크
			if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
			{
				strcpy(s_msg_code, "WIP-0059");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
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

			// KITTING 자재 체크
			if (COM_isnullspace(MINVLOTSTS_OLD.INV_CMF_4) == MP_TRUE)
			{
				//INV-0061 : 해당 자재 Lot은 Kitting ID가 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0061");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

			// 자재 LOT & KITTING ID 매핑
			memset(MINVLOTSTS.INV_CMF_4, ' ', sizeof(MINVLOTSTS.INV_CMF_4)); // INV_CMF_4(KITTING_ID)
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNKITTING, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
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

			DBU_init_minvlotsts(&MINVLOTSTS_COUNT);
			TRS.copy(MINVLOTSTS_COUNT.FACTORY, sizeof(MINVLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_COUNT.INV_CMF_4, sizeof(MINVLOTSTS_COUNT.INV_CMF_4), in_node, "KITTING_ID");
			d_lot_count = DBU_select_minvlotsts_scalar(5, &MINVLOTSTS_COUNT);

			TRS.add_double(out_node, "LOT_COUNT", d_lot_count);
		}
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Kitting_Lot_Validation()
        - Validation Check sub function of "CUS_INV_KITTING_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_KITTING_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Kitting_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{   
	/*
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }
	*/
    
    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Kitting_Lot_Before_Transaction()
- Main sub function of "CUS_INV_KITTING_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Kitting_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Kitting_Lot_After_Transaction()
- Main sub function of "CUS_INV_KITTING_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Kitting_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}