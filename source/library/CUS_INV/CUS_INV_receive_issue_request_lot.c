/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_receive_issue_request_lot.c
    Description : Confirm Receive Request Lot

    MES Version : 5.2.0

    Function List
        - CUS_INV_Receive_Issue_Request_Lot()
            + Receive Issue Request Lot
        - CUS_INV_RECEIVE_ISSUE_REQUEST_LOT()
            + Main Sub function of "CUS_INV_Receive_Issue_Request_Lot"
            + (called by "CUS_INV_Receive_Issue_Request_Lot")
        - CUS_INV_Receive_Issue_Request_Lot_Validation()
            + Validation Check sub function of "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT" function
            + (called by "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/18  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_RECEIVE_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Receive_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Receive_Issue_Request_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Receive_Issue_Request_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Receive_Issue_Request_Lot()
        - Receive Issue Request Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Receive_Issue_Request_Lot_In_Tag *CUS_INV_Receive_Issue_Request_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Receive_Issue_Request_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT", out_node);

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
CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN()
- Main sub function of "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *receive_in_node;
	TRSNode **recv_lot_list;
	TRSNode *lot_list;
	TRSNode *inv_lot_list;
	int i;

	LOG_head("CUS_INV_RECEIVE_ISSUE_REQUEST_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Receive_Issue_Request_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	receive_in_node = TRS.add_node(in_node, "receive_in_node");
	CopyDefaultMembers(receive_in_node, in_node);

	TRS.add_char(receive_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(receive_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
	TRS.add_nstring(receive_in_node, "REQ_MAT_ID", TRS.get_string(in_node, "REQ_MAT_ID"));
	TRS.add_int(receive_in_node, "REQ_MAT_VER", TRS.get_int(in_node, "REQ_MAT_VER"));
	TRS.add_double(receive_in_node, "QTY", TRS.get_double(in_node, "QTY"));

	recv_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(receive_in_node, "REQ_LOT_LIST");
		TRS.add_nstring(lot_list, "REQ_LOT_ID", TRS.get_string(recv_lot_list[i], "REQ_LOT_ID"));

		inv_lot_list = TRS.add_node(receive_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_lot_list, "INV_LOT_ID", TRS.get_string(recv_lot_list[i], "REQ_LOT_ID"));
	}

	if (CUS_INV_Receive_Issue_Request_Lot_Before_Transaction(s_msg_code, 0, receive_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_RECEIVE_ISSUE_REQUEST_LOT(s_msg_code, receive_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Receive_Issue_Request_Lot_After_Transaction(s_msg_code, 0, receive_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_RECEIVE_ISSUE_REQUEST_LOT()
        - Main sub function of "CUS_INV_Receive_Issue_Request_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_RECEIVE_ISSUE_REQUEST_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MINVREQDTL_TAG MINVREQDTL_COUNT;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct MINVREQLOT_TAG MINVREQLOT_COUNT;

	TRSNode **recv_lot_list;
	int i_status_count = 0;
	int i_total_count = 0;
	int i = 0;
    char s_sys_time[14];

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

	// 불출 요청 마스터 상태 체크
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

	// MINVREQDTL - 불출 요청 상세 정보 조회
	DBU_init_minvreqdtl(&MINVREQDTL);
	TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO), in_node, "REQ_NO");
	TRS.copy(MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID), in_node, "REQ_MAT_ID");
	MINVREQDTL.REQ_MAT_VER = TRS.get_int(in_node, "REQ_MAT_VER");
	DBU_select_minvreqdtl(1, &MINVREQDTL);
	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
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

	if(DB_error_code == DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
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

	// 불출 요청 상세 정보 상태 체크
	if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, strlen(MP_CINV_ISSUE_COMPLETED)) == 0)
	{
		//INV-0058 : 해당 자재 불출 요청은 이미 완료되었습니다.
		strcpy(s_msg_code, "INV-0058");
		TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
		TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
		TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQDTL.REQ_MAT_VER);
		TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQDTL.REQ_STATUS), MINVREQDTL.REQ_STATUS);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	recv_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

	// 불출 요청 LOT 상태 변경
	for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
	{
		// MINVREQLOT - 불출 요청 LOT 정보 조회
		DBU_init_minvreqlot(&MINVREQLOT);
		TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQLOT.REQ_NO, sizeof(MINVREQLOT.REQ_NO), in_node, "REQ_NO");
		TRS.copy(MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID), in_node, "REQ_MAT_ID");
		MINVREQLOT.REQ_MAT_VER = TRS.get_int(in_node, "REQ_MAT_VER");
		TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), recv_lot_list[i], "REQ_LOT_ID");
		DBU_select_minvreqlot(1, &MINVREQLOT);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
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
			TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 불출 요청 LOT 상태 체크
		if (memcmp(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_ISSUE, strlen(MP_CINV_ISSUE_ISSUE)) != 0)
		{
			strcpy(s_msg_code, "INV-0035");
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(MINVREQLOT.REQ_STATUS), MINVREQLOT.REQ_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 불출 요청 LOT 상태 변경(CONFIRM -> COMPLETED)
		memcpy(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, sizeof(MINVREQLOT.REQ_STATUS));
		TRS.copy(MINVREQLOT.UPDATE_USER_ID, sizeof(MINVREQLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvreqlot(1, &MINVREQLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQLOT.FACTORY), MINVREQLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_minvreqlot(&MINVREQLOT_COUNT);
		TRS.copy(MINVREQLOT_COUNT.FACTORY, sizeof(MINVREQLOT_COUNT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQLOT_COUNT.REQ_NO, MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO));
		memcpy(MINVREQLOT_COUNT.REQ_MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
		MINVREQLOT_COUNT.REQ_MAT_VER = MINVREQDTL.REQ_MAT_VER;
		memcpy(MINVREQLOT_COUNT.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, sizeof(MINVREQLOT_COUNT.REQ_STATUS));
		// MINVREQLOT - 불출 인수된 LOT의 수량
		i_status_count = (int)DBU_select_minvreqlot_scalar(8, &MINVREQLOT_COUNT);

		DBU_init_minvreqlot(&MINVREQLOT_COUNT);
		TRS.copy(MINVREQLOT_COUNT.FACTORY, sizeof(MINVREQLOT_COUNT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQLOT_COUNT.REQ_NO, MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO));
		memcpy(MINVREQLOT_COUNT.REQ_MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
		MINVREQLOT_COUNT.REQ_MAT_VER = MINVREQDTL.REQ_MAT_VER;
		// MINVREQLOT - 해당 불출 상세 요청에 매핑된 LOT의 수량
		i_total_count = (int)DBU_select_minvreqlot_scalar(6, &MINVREQLOT_COUNT);

		if (i_total_count == i_status_count)
		{
			// 불출 요청 LOT의 상태를 체크하여 불출 요청 상세 정보 상태 변경
			// 불출 요청 상세 정보 상태 변경(ISSUE -> COMPLETED)
			memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, sizeof(MINVREQDTL.REQ_STATUS));
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

			// 완료된 불출 상세 정보의 수량 
			DBU_init_minvreqdtl(&MINVREQDTL_COUNT);
			TRS.copy(MINVREQDTL_COUNT.FACTORY, sizeof(MINVREQDTL_COUNT.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVREQDTL_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
			memcpy(MINVREQDTL_COUNT.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, sizeof(MINVREQDTL_COUNT.REQ_STATUS));
			i_status_count = (int)DBU_select_minvreqdtl_scalar(2, &MINVREQDTL_COUNT);

			// 불출 요청에 매핑되어 있는 불출 상세 정보의 수량 
			DBU_init_minvreqdtl(&MINVREQDTL_COUNT);
			TRS.copy(MINVREQDTL_COUNT.FACTORY, sizeof(MINVREQDTL_COUNT.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVREQDTL_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
			i_total_count = (int)DBU_select_minvreqdtl_scalar(5, &MINVREQDTL_COUNT);

			if (i_status_count == i_total_count)
			{
				// 불출 요청 상세 정보의 상태를 체크하여 불출 요청 마스터 정보 상태 변경
				// 불출 요청 마스터 정보 상태 변경(ISSUE -> COMPLETED)
				memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_COMPLETED, sizeof(MINVREQMST.REQ_STATUS));
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
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Receive_Issue_Request_Lot_Validation()
        - Validation Check sub function of "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Receive_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Receive_Issue_Request_Lot_Before_Transaction()
- Main sub function of "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Receive_Issue_Request_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Receive_Issue_Request_Lot_After_Transaction()
- Main sub function of "CUS_INV_RECEIVE_ISSUE_REQUEST_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Receive_Issue_Request_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;

	TRSNode **inv_lot_list;
	TRSNode *erpif_in;
	TRSNode *cmn_out;
	int i;

	// 불출 상태 변경 -> (자재 이동 -> 자재 불출 내역 생성)
	if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	// MINVREQMST - 불출 요청 마스터 정보 조회
	DBU_init_minvreqmst(&MINVREQMST);
	TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
	DBU_select_minvreqmst(1, &MINVREQMST);
	if (DB_error_code != DB_SUCCESS)
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

	//FROM AREA 정보 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
	TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
	memcpy(MGCMTBLDAT_FROM.KEY_1, MINVREQMST.AREA_ID, sizeof(MINVREQMST.AREA_ID));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);

	if (DB_error_code != DB_SUCCESS)
	{
		//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
		strcpy(s_msg_code, "GCM-0008");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// FROM 창고
	DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
	TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_FROM.OPER, MINVREQMST.OPER, sizeof(MINVREQMST.OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_dberrmsg(out_node, DB_error_msg);
		}

		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//TO AREA 정보 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
	TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
	memcpy(MGCMTBLDAT_TO.KEY_1, MINVREQMST.TO_AREA_ID, sizeof(MINVREQMST.TO_AREA_ID));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);

	if (DB_error_code != DB_SUCCESS)
	{
		//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
		strcpy(s_msg_code, "GCM-0008");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//TO 창고
	DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
	TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_TO.OPER, MINVREQMST.TO_OPER, sizeof(MINVREQMST.TO_OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_dberrmsg(out_node, DB_error_msg);
		}

		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// MINVREQDTL - 불출 요청 상세 정보 조회
	DBU_init_minvreqdtl(&MINVREQDTL);
	TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO), in_node, "REQ_NO");
	TRS.copy(MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID), in_node, "REQ_MAT_ID");
	MINVREQDTL.REQ_MAT_VER = TRS.get_int(in_node, "REQ_MAT_VER");
	DBU_select_minvreqdtl(1, &MINVREQDTL);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVREQDTL SELECT", MP_NVST);
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

	// MWIPMATDEF - 제품 정보 조회
	DBU_init_mwipmatdef(&MWIPMATDEF);
	TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPMATDEF.MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
	MWIPMATDEF.MAT_VER = MINVREQDTL.REQ_MAT_VER;
	DBU_select_mwipmatdef(1, &MWIPMATDEF);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0006");
		TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) == 0)
	{
		DBU_init_cbastxndef(&CBASTXNDEF);
		TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
		CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
		CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2));
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
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
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

		inv_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "REQ_LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS);

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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MINVDLVDTL - 구매 입고 상세 정보 조회
			DBU_init_minvdlvdtl(&MINVDLVDTL);
			TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVDLVDTL.DLV_NO, MINVLOTSTS.DLV_NO, sizeof(MINVLOTSTS.DLV_NO));
			MINVDLVDTL.DLV_SEQ = MINVLOTSTS.DLV_SEQ;
			DBU_select_minvdlvdtl(1, &MINVDLVDTL);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
				TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//ERP 실적 - IF_PO_CONSIGN_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
			TRS.add_string(erpif_in, "TRAN_TYPE_NAME", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
			TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
			TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
			TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
			TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
			TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
			TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
			TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
			TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
			TRS.add_double(erpif_in, "QTY", -MINVLOTSTS.QTY);
			TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
			TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_CONSIGN_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}
	else
	{
		DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
		TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
		memcpy(MGCMTBLDAT_SRC.KEY_1, "ISSUE", strlen("ISSUE"));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);

		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ERP 실적 - IF_INV_TXNS
		erpif_in = TRS.add_node(in_node, "erpif_in");
		TRS.add_char(erpif_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(erpif_in, in_node);

		TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
		TRS.add_int(erpif_in, "TRAN_TYPE_ID", 2);	//2번으로 고정
		TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));	//2번으로 고정
		TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
		TRS.add_string(erpif_in, "AREA_ID", MINVREQMST.AREA_ID, sizeof(MINVREQMST.AREA_ID));
		TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
		TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
		TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
		TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
		TRS.add_double(erpif_in, "QTY", TRS.get_double(in_node, "QTY"));
		TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
		TRS.add_string(erpif_in, "TO_AREA_ID", MINVREQMST.TO_AREA_ID, sizeof(MINVREQMST.TO_AREA_ID));
		TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
		TRS.add_string(erpif_in, "MES_ID", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));

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
		memcpy(IF_INV_TXNS.MES_ID, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		DBU_select_if_inv_txns(2, &IF_INV_TXNS);

		inv_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "REQ_LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS);

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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//ERP 실적 - IF_INV_TXN_LOTS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "INV_TXNS_ID", IF_INV_TXNS.IF_SEQ);
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
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

	return MP_TRUE;
}