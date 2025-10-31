/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_release_lot.c
    Description : Release Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Release_Lot()
            + Release Lot
        - CUS_INV_RELEASE_LOT()
            + Main sub function of "CUS_INV_Release_Lot" function
            + Release Lot definition
        - CUS_INV_Release_Lot_Validation()
            + Validation Check sub function of "CUS_INV_RELEASE_LOT" function

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

int CUS_INV_RELEASE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Release_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Release_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Release_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_RELEASE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Release_Lot()
        - Release Lot
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Release_Lot(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_RELEASE_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_RELEASE_LOT", out_node);

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
CUS_INV_RELEASE_LOT()
- Main sub function of "CUS_INV_Release_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_RELEASE_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *release_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;

	LOG_head("CUS_INV_RELEASE_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Release_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	release_in_node = TRS.add_node(in_node, "release_in_node");
	CopyDefaultMembers(release_in_node, in_node);

	TRS.add_char(release_in_node, IN_PROCSTEP, '2');

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(release_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
	}

	TRS.add_nstring(release_in_node, "RELEASE_CODE", TRS.get_string(in_node, "RELEASE_CODE"));
	TRS.add_nstring(release_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
	

	if (CUS_INV_Release_Lot_Before_Transaction(s_msg_code, 0, release_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_RELEASE_LOT(s_msg_code, release_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Release_Lot_After_Transaction(s_msg_code, 0, release_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_RELEASE_LOT()
        - Main sub function of "CUS_INV_Release_Lot" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_RELEASE_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;

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
				strcpy(s_msg_code, "INV-0044");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
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
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS_OLD.HOLD_FLAG != 'Y')
		{
			strcpy(s_msg_code, "WIP-0083");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// Release Code 체크
		if (COM_isnullspace(TRS.get_string(in_node, "RELEASE_CODE")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "RELEASE_CODE", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// Release Code 체크 (GCM 체크)
		if (COM_check_gcm_data(s_msg_code,
			out_node,
			"C_INV_RELEASE_CODE",
			TRS.get_factory(in_node),
			TRS.get_string(in_node, "RELEASE_CODE"),
			(int)strlen(TRS.get_string(in_node, "RELEASE_CODE"))) == MP_FALSE)
		{
			return MP_FALSE;
		}

		memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));


		//20231207  ' ' 에서 'N'으로 변경
		//MINVLOTSTS.HOLD_FLAG = ' ';
		MINVLOTSTS.HOLD_FLAG = 'N';
		memset(MINVLOTSTS.HOLD_CODE, ' ', sizeof(MINVLOTSTS.HOLD_CODE));

		memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_RELEASE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
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

		//자재 LOT 잠금 이력 생성
		if (CUS_INV_INSERT_LOT_HLD_HISTORY(s_msg_code,
			in_node,
			out_node,
			&MINVLOTSTS) == MP_FALSE)
		{
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
    }

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;

}

/*******************************************************************************
    CUS_INV_Release_Lot_Validation()
        - Validation Check sub function of "CUS_INV_RELEASE_LOT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Release_Lot_Validation(char *s_msg_code,
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
CUS_INV_Release_Lot_Before_Transaction()
- Main sub function of "CUS_INV_RELEASE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Release_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Release_Lot_After_Transaction()
- Main sub function of "CUS_INV_RELEASE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Release_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}