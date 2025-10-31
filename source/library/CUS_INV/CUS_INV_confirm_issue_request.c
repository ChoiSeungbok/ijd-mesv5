/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_confirm_issue_request.c
    Description : Confirm Issue Request

    MES Version : 5.2.0

    Function List
        - CUS_INV_Confirm_Issue_Request()
            + Confirm Issue Request
        - CUS_INV_CONFIRM_ISSUE_REQUEST()
            + Main Sub function of "CUS_INV_Confirm_Issue_Request"
            + (called by "CUS_INV_Confirm_Issue_Request")
        - CUS_INV_Confirm_Issue_Request_Validation()
            + Validation Check sub function of "CUS_INV_CONFIRM_ISSUE_REQUEST" function
            + (called by "CUS_INV_CONFIRM_ISSUE_REQUEST")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/19  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_CONFIRM_ISSUE_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Confirm_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Confirm_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Confirm_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Confirm_Issue_Request()
        - Confirm Issue Request
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Confirm_Issue_Request_In_Tag *CUS_INV_Confirm_Issue_Request_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Issue_Request(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CONFIRM_ISSUE_REQUEST", out_node);

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
CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN()
- Main sub function of "CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *confirm_in_node;
	TRSNode **req_lot_list;
	TRSNode *lot_list;
	int i;

	LOG_head("CUS_INV_CONFIRM_ISSUE_REQUEST");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Confirm_Issue_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	confirm_in_node = TRS.add_node(in_node, "confirm_in_node");
	CopyDefaultMembers(confirm_in_node, in_node);

	TRS.add_char(confirm_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));
	TRS.add_nstring(confirm_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));

	req_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(confirm_in_node, "REQ_LOT_LIST");
		TRS.add_nstring(lot_list, "REQ_LOT_ID", TRS.get_string(req_lot_list[i], "REQ_LOT_ID"));
	}

	if (CUS_INV_Confirm_Issue_Request_Before_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CONFIRM_ISSUE_REQUEST(s_msg_code, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Confirm_Issue_Request_After_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_CONFIRM_ISSUE_REQUEST()
        - Main sub function of "CUS_INV_Confirm_Issue_Request" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CONFIRM_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CONFIRM_ISSUE_REQUEST(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MINVREQDTL_TAG MINVREQDTL_COUNT;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct MINVREQLOT_TAG MINVREQLOT_COUNT;

	TRSNode **req_lot_list;
	char s_sys_time[14];
	int i_req_status_count = 0;
	int i = 0;

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

	// MINVREQMST - 불출 요청 마스터 정보 조회
	DBU_init_minvreqmst(&MINVREQMST);
	TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
	DBU_select_minvreqmst(1, &MINVREQMST);
	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	if (DB_error_code == DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// PROCSTEP = 1 -> 불출 요청 확정
	// PROCSTEP = 2 -> 불출 요청 확정 취소
	// PROCSTEP = 3 -> 불출 요청 등록 확정
	// PROCSTEP = 4 -> 불출 요청 등록 확정 취소
	if (TRS.get_procstep(in_node) == '1')
	{
		// 불출 요청 마스터 상태 체크
		// 상태가 CREATE -> 확정 가능
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_CREATE, strlen(MP_CINV_ISSUE_CREATE)) != 0)
		{
			strcpy(s_msg_code, "INV-0031");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQMST - 불출 요청 마스터 정보 상태 업데이트(CREATE -> REQUEST)
		memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REQUEST, sizeof(MINVREQMST.REQ_STATUS));
		TRS.copy(MINVREQMST.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvreqmst(1, &MINVREQMST);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQMST UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQMST.FACTORY), MINVREQMST.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQDTL - 불출 요청 상세 정보 상태 업데이트(CREATE -> REQUEST)
		DBU_init_minvreqdtl(&MINVREQDTL);
		TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQDTL.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REQUEST, sizeof(MINVREQDTL.REQ_STATUS));
		TRS.copy(MINVREQDTL.UPDATE_USER_ID, sizeof(MINVREQDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvreqdtl(2, &MINVREQDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		// 불출 요청 마스터 상태 체크
		// 상태가 REQUEST -> 확정 취소 가능
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) != 0)
		{
			strcpy(s_msg_code, "INV-0031");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQMST - 불출 요청 마스터 정보 상태 업데이트(REQUEST -> CREATE)
		memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_CREATE, sizeof(MINVREQMST.REQ_STATUS));
		TRS.copy(MINVREQMST.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvreqmst(1, &MINVREQMST);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQMST UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQMST.FACTORY), MINVREQMST.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQDTL - 불출 요청 상세 정보 상태 업데이트(REQUEST -> CREATE)
		DBU_init_minvreqdtl(&MINVREQDTL);
		TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQDTL.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_CREATE, sizeof(MINVREQDTL.REQ_STATUS));
		TRS.copy(MINVREQDTL.UPDATE_USER_ID, sizeof(MINVREQDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvreqdtl(2, &MINVREQDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		// 불출 요청 마스터 상태 체크
		// 상태가 REGIST -> 확정 가능
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
		{
			strcpy(s_msg_code, "INV-0031");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		req_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
		{
			// MINVREQLOT - 불출 요청 LOT 정보 조회
			DBU_init_minvreqlot(&MINVREQLOT);
			TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
			TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), req_lot_list[i], "REQ_LOT_ID");
			DBU_select_minvreqlot(2, &MINVREQLOT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (memcmp(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
			{
				//INV-0031 : 해당 불출 요청은 수정이 불가능합니다. 상태를 확인해주세요. 
				strcpy(s_msg_code, "INV-0031");
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 자재 불출 요청 LOT 정보 상태 변경 (REGIST -> ISSUE)
			memcpy(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQLOT.REQ_STATUS));
			TRS.copy(MINVREQLOT.UPDATE_USER_ID, sizeof(MINVREQLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVREQLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_minvreqlot(1, &MINVREQLOT);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvreqdtl(&MINVREQDTL);
			TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVREQDTL.REQ_NO, MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO));
			memcpy(MINVREQDTL.REQ_MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
			MINVREQDTL.REQ_MAT_VER = MINVREQLOT.REQ_MAT_VER;
			DBU_select_minvreqdtl(1, &MINVREQDTL);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
			{
				//INV-0031 : 해당 불출 요청은 수정이 불가능합니다. 상태를 확인해주세요. 
				strcpy(s_msg_code, "INV-0031");
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvreqlot(&MINVREQLOT_COUNT);
			TRS.copy(MINVREQLOT_COUNT.FACTORY, sizeof(MINVREQLOT_COUNT.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVREQLOT_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
			memcpy(MINVREQLOT_COUNT.REQ_MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
			MINVREQLOT_COUNT.REQ_MAT_VER = MINVREQLOT.REQ_MAT_VER;
			memcpy(MINVREQLOT_COUNT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQLOT_COUNT.REQ_STATUS));
			// MINVREQLOT - 불출 상태가 ISSUE + COMPLETED인 수량
			i_req_status_count = (int)DBU_select_minvreqlot_scalar(7, &MINVREQLOT_COUNT);

			if (i_req_status_count >= MINVREQDTL.REQ_QTY)
			{
				// 자재 불출 요청 상세 정보 상태 변경 (REGIST -> ISSUE)
				memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQDTL.REQ_STATUS));
				TRS.copy(MINVREQDTL.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVREQDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_minvreqdtl(1, &MINVREQDTL);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "INV-0004");
					TRS.add_fieldmsg(out_node, "MINVREQDTL UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
					TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
					TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
					TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// 자재 불출 상세 요청의 상태를 체크하여 자재 불출 마스터 정보의 상태를 변경
				DBU_init_minvreqdtl(&MINVREQDTL_COUNT);
				TRS.copy(MINVREQDTL_COUNT.FACTORY, sizeof(MINVREQDTL_COUNT.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVREQDTL_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
				memcpy(MINVREQDTL_COUNT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQDTL_COUNT.REQ_STATUS));

				// MINVREQDTL - 불출 상태가 ISSUE, COMPLETED가 아닌 것의 수량
				i_req_status_count = (int)DBU_select_minvreqdtl_scalar(4, &MINVREQDTL_COUNT);

				if (i_req_status_count == 0)
				{
					// 자재 불출 요청 마스터 정보 상태 변경 (REGIST -> ISSUE)
					memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQMST.REQ_STATUS));
					TRS.copy(MINVREQMST.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(MINVREQMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_minvreqmst(1, &MINVREQMST);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "INV-0004");
						TRS.add_fieldmsg(out_node, "MINVREQMST UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQMST.FACTORY), MINVREQMST.FACTORY);
						TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '4')
	{
		// 불출 요청 마스터 상태 체크
		// 상태가 ISSUE -> 확정 취소 가능
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, strlen(MP_CINV_ISSUE_COMPLETED)) == 0)
		{
			//INV-0058 : 해당 자재 불출 요청은 이미 완료되었습니다.
			strcpy(s_msg_code, "INV-0058");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQMST.REQ_STATUS), MINVREQMST.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		req_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
		{
			// MINVREQLOT - 불출 요청 LOT 정보 조회
			DBU_init_minvreqlot(&MINVREQLOT);
			TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
			TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), req_lot_list[i], "REQ_LOT_ID");
			DBU_select_minvreqlot(2, &MINVREQLOT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (memcmp(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, strlen(MP_CINV_ISSUE_ISSUE)) != 0)
			{
				//INV-0031 : 해당 불출 요청은 수정이 불가능합니다. 상태를 확인해주세요. 
				strcpy(s_msg_code, "INV-0031");
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 자재 불출 요청 LOT 정보 상태 변경 (ISSUE -> REGIST)
			memcpy(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_REGIST, sizeof(MINVREQLOT.REQ_STATUS));
			TRS.copy(MINVREQLOT.UPDATE_USER_ID, sizeof(MINVREQLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVREQLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_minvreqlot(1, &MINVREQLOT);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvreqdtl(&MINVREQDTL);
			TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVREQDTL.REQ_NO, MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO));
			memcpy(MINVREQDTL.REQ_MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
			MINVREQDTL.REQ_MAT_VER = MINVREQLOT.REQ_MAT_VER;
			DBU_select_minvreqdtl(1, &MINVREQDTL);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
				TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
				TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_ISSUE, strlen(MP_CINV_ISSUE_ISSUE)) == 0)
			{
				DBU_init_minvreqlot(&MINVREQLOT_COUNT);
				TRS.copy(MINVREQLOT_COUNT.FACTORY, sizeof(MINVREQLOT_COUNT.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVREQLOT_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
				memcpy(MINVREQLOT_COUNT.REQ_MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
				MINVREQLOT_COUNT.REQ_MAT_VER = MINVREQLOT.REQ_MAT_VER;
				memcpy(MINVREQLOT_COUNT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, sizeof(MINVREQLOT_COUNT.REQ_STATUS));
				// MINVREQLOT - 불출 상태가 ISSUE + COMPLETED 수량
				i_req_status_count = (int)DBU_select_minvreqlot_scalar(7, &MINVREQLOT_COUNT);

				if (i_req_status_count < MINVREQDTL.REQ_QTY)
				{
					// 자재 불출 상세 정보 상태 변경 (ISSUE -> REGIST)
					memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REGIST, sizeof(MINVREQDTL.REQ_STATUS));
					TRS.copy(MINVREQDTL.UPDATE_USER_ID, sizeof(MINVREQDTL.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(MINVREQDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_minvreqdtl(1, &MINVREQDTL);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "INV-0004");
						TRS.add_fieldmsg(out_node, "MINVREQDTL UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
						TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
						TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
						TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_ISSUE, strlen(MP_CINV_ISSUE_ISSUE)) == 0)
					{
						// 자재 불출 요청 마스터 정보 상태 변경 (ISSUE -> REGIST)
						memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REGIST, sizeof(MINVREQMST.REQ_STATUS));
						TRS.copy(MINVREQMST.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
						memcpy(MINVREQMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
						DBU_update_minvreqmst(1, &MINVREQMST);

						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "INV-0004");
							TRS.add_fieldmsg(out_node, "MINVREQMST UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQMST.FACTORY), MINVREQMST.FACTORY);
							TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}
		}
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Confirm_Issue_Request_Validation()
        - Validation Check sub function of "CUS_INV_CONFIRM_ISSUE_REQUEST" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CONFIRM_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Confirm_Issue_Request_Before_Transaction()
- Main sub function of "CUS_INV_CONFIRM_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Confirm_Issue_Request_After_Transaction()
- Main sub function of "CUS_INV_CONFIRM_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Confirm_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}