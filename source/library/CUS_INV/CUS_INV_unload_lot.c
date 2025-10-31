/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_unload_lot.c
    Description : Unload Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Unload_Lot()
            + Unload Lot
        - CUS_INV_UNLOAD_LOT()
            + Main sub function of "CUS_INV_Unload_Lot" function
            + Unload Lot definition
        - CUS_INV_Unload_Lot_Validation()
            + Validation Check sub function of "CUS_INV_UNLOAD_LOT" function

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

int CUS_INV_UNLOAD_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Unload_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Unload_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Unload_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_UNLOAD_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Unload_Lot()
        - Unload Lot
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Unload_Lot(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_UNLOAD_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_UNLOAD_LOT", out_node);

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
CUS_INV_UNLOAD_LOT()
- Main sub function of "CUS_INV_Unload_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_UNLOAD_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *unload_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;

	LOG_head("CUS_INV_UNLOAD_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Unload_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	unload_in_node = TRS.add_node(in_node, "unload_in_node");
	CopyDefaultMembers(unload_in_node, in_node);

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(unload_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
	}

	TRS.add_char(unload_in_node, "REL_LEVEL", TRS.get_char(in_node, "REL_LEVEL"));
	//unload 할때는 commnet 안건들도록 수정 20230710
	//TRS.add_nstring(unload_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

	if (CUS_INV_Unload_Lot_Before_Transaction(s_msg_code, 0, unload_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_UNLOAD_LOT(s_msg_code, unload_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Unload_Lot_After_Transaction(s_msg_code, 0, unload_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_UNLOAD_LOT()
        - Main sub function of "CUS_INV_Unload_Lot" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_UNLOAD_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

    char s_sys_time[14];

	int i;

	TRSNode **inv_lot_list;
     
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

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for(i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST") ; i++)
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

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS_OLD.DELETE_FLAG == 'Y')
		{
			// 전부사용했는데도 LDM테이블에 남아있는경우가 있어서.. 오류처리는 안하는 걸로 변경.
			/*
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
			*/
			
			return MP_TRUE;;

		}



		// LOAD LEVEL VALIDATION
		// LOAD LEVEL이 존재하지 않을 경우 기존 로직 (임시 사용)
		if (TRS.get_char(in_node, "REL_LEVEL") == ' ')
		{

			//20220418 이거때문에 계속 문제됨  . 필요없어서 날림..
			/*
			// 자재 LOT 투입 여부 체크
			if (COM_isnullspace(MINVLOTSTS_OLD.ORDER_ID) == MP_TRUE)
			{
				strcpy(s_msg_code, "INV-0017");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

			// TRAN CODE : UNLOAD
			// 작업지시 매핑 해제, 투입여부 체크 해제, 투입 작업장 및 공정 UPDATE
			MINVLOTSTS.LOAD_FLAG = 'N';
			memset(MINVLOTSTS.ORDER_ID, ' ', sizeof(MINVLOTSTS.ORDER_ID));
			memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8)); // INV_CMF_8(투입 작업장)
			memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9)); // INV_CMF_9(투입 공정)


			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNLOAD, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			//unload 할때는 commnet 안건들도록 수정 20230710
			//TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
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
		}
		else
		{
			memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

			// LOAD LEVEL 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_LOAD_LEVEL, strlen(MP_GCM_LOAD_LEVEL));
			MGCMTBLDAT.KEY_1[0] = TRS.get_char(in_node, "REL_LEVEL");
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "REL_LEVEL", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// LOAD LEVEL의 DATA_1 값으로 TRAN_CODE 변경
			if (memcmp(MGCMTBLDAT.DATA_1, MP_LOAD_LEVEL_LOT, strlen(MP_LOAD_LEVEL_LOT)) == 0)
			{
				if (COM_isnullspace(MINVLOTSTS.LOT_ID) == MP_TRUE)
				{
					//INV-0072 : 해당 Lot은 해당 Level로 투입되어 있지 않습니다.
					strcpy(s_msg_code, "INV-0072");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "REL_LEVEL", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNLOAD_LOT, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
				memset(MINVLOTSTS.LOT_ID, ' ', sizeof(MINVLOTSTS.LOT_ID));
			}
			else if (memcmp(MGCMTBLDAT.DATA_1, MP_LOAD_LEVEL_RES, strlen(MP_LOAD_LEVEL_RES)) == 0)
			{
				if (COM_isnullspace(MINVLOTSTS.RES_ID) == MP_TRUE)
				{
					//INV-0072 : 해당 Lot은 해당 Level로 투입되어 있지 않습니다.
					strcpy(s_msg_code, "INV-0072");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "REL_LEVEL", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNLOAD_RES, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
				memset(MINVLOTSTS.RES_ID, ' ', sizeof(MINVLOTSTS.RES_ID));
			}
			else if (memcmp(MGCMTBLDAT.DATA_1, MP_LOAD_LEVEL_WO, strlen(MP_LOAD_LEVEL_WO)) == 0)
			{
				if (COM_isnullspace(MINVLOTSTS.ORDER_ID) == MP_TRUE)
				{
					//INV-0072 : 해당 Lot은 해당 Level로 투입되어 있지 않습니다.
					strcpy(s_msg_code, "INV-0072");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "REL_LEVEL", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNLOAD_WO, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
				memset(MINVLOTSTS.ORDER_ID, ' ', sizeof(MINVLOTSTS.ORDER_ID));
			}
			else if (memcmp(MGCMTBLDAT.DATA_1, MP_LOAD_LEVEL_OPER, strlen(MP_LOAD_LEVEL_OPER)) == 0)
			{
				if (COM_isnullspace(MINVLOTSTS.INV_CMF_9) == MP_TRUE)
				{
					//INV-0072 : 해당 Lot은 해당 Level로 투입되어 있지 않습니다.
					strcpy(s_msg_code, "INV-0072");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "REL_LEVEL", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_UNLOAD_OPER, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
				memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8)); // INV_CMF_8(투입 작업장)
				memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9));
			}

			// TRAN CODE : UNLOAD_LOT, UNLOAD_RES, UNLOAD_WO, UNLOAD_OPER
			// LOT, 설비, 작업지시, 공정 모두 LOAD 정보가 존재하지 않을 경우, LOAD_FLAG(N) 변경
			if (COM_isnullspace(MINVLOTSTS.LOT_ID) == MP_TRUE
				&& COM_isnullspace(MINVLOTSTS.RES_ID) == MP_TRUE
				&& COM_isnullspace(MINVLOTSTS.ORDER_ID) == MP_TRUE
				&& COM_isnullspace(MINVLOTSTS.INV_CMF_9) == MP_TRUE)
			{
				MINVLOTSTS.LOAD_FLAG = 'N';
			}

			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			//unload 할때는 commnet 안건들도록 수정 20230710
		//	TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
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
		}
    }

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;

}

/*******************************************************************************
    CUS_INV_Unload_Lot_Validation()
        - Validation Check sub function of "CUS_INV_UNLOAD_LOT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Unload_Lot_Validation(char *s_msg_code,
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
CUS_INV_Unload_Lot_Before_Transaction()
- Main sub function of "CUS_INV_UNLOAD_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Unload_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Unload_Lot_After_Transaction()
- Main sub function of "CUS_INV_UNLOAD_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Unload_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}