/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_delete_issue_request.c
    Description : Delete Issue Request

    MES Version : 5.2.0

    Function List
        - CUS_INV_Delete_Issue_Request()
            + Delete Issue Request
        - CUS_INV_DELETE_ISSUE_REQUEST()
            + Main Sub function of "CUS_INV_Delete_Issue_Request"
            + (called by "CUS_INV_Delete_Issue_Request")
        - CUS_INV_Delete_Issue_Request_Validation()
            + Validation Check sub function of "CUS_INV_DELETE_ISSUE_REQUEST" function
            + (called by "CUS_INV_DELETE_ISSUE_REQUEST")
       
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

int CUS_INV_DELETE_ISSUE_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_DELETE_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Delete_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Delete_Issue_Request()
        - Delete Issue Request
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Delete_Issue_Request_In_Tag *CUS_INV_Delete_Issue_Request_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Issue_Request(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_DELETE_ISSUE_REQUEST_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_DELETE_ISSUE_REQUEST", out_node);

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
CUS_INV_DELETE_ISSUE_REQUEST_MAIN()
- Main sub function of "CUS_INV_DELETE_ISSUE_REQUEST_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_DELETE_ISSUE_REQUEST_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_DELETE_ISSUE_REQUEST_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *delete_in_node;

	LOG_head("CUS_INV_DELETE_ISSUE_REQUEST");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Delete_Issue_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	delete_in_node = TRS.add_node(in_node, "delete_in_node");
	CopyDefaultMembers(delete_in_node, in_node);

	TRS.add_char(delete_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));
	TRS.add_nstring(delete_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));

	if (CUS_INV_Delete_Issue_Request_Before_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_DELETE_ISSUE_REQUEST(s_msg_code, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Delete_Issue_Request_After_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_DELETE_ISSUE_REQUEST()
        - Main sub function of "CUS_INV_Delete_Issue_Request" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_DELETE_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_DELETE_ISSUE_REQUEST(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;

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
	// 상태가 CREATE -> 삭제 가능
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

	// MINVREQMST - 불출 요청 마스터 정보 삭제
	DBU_delete_minvreqmst(1, &MINVREQMST);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVREQMST DELETE", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQMST.FACTORY), MINVREQMST.FACTORY);
		TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// MINVREQDTL - 불출 요청 상세 정보 삭제
	DBU_init_minvreqdtl(&MINVREQDTL);
	TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO), in_node, "REQ_NO");
	DBU_delete_minvreqdtl(2, &MINVREQDTL);
	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "MINVREQDTL DELETE", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
		TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Delete_Issue_Request_Validation()
        - Validation Check sub function of "CUS_INV_DELETE_ISSUE_REQUEST" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_DELETE_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Delete_Issue_Request_Before_Transaction()
- Main sub function of "CUS_INV_DELETE_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Delete_Issue_Request_After_Transaction()
- Main sub function of "CUS_INV_DELETE_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Delete_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}