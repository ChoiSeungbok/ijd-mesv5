/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_create_issue_request.c
    Description : Create Issue Request

    MES Version : 5.2.0

    Function List
        - CUS_INV_Create_Issue_Request()
            + Create Issue Request
        - CUS_INV_CREATE_ISSUE_REQUEST()
            + Main Sub function of "CUS_INV_Create_Issue_Request"
            + (called by "CUS_INV_Create_Issue_Request")
        - CUS_INV_Create_Issue_Request_Validation()
            + Validation Check sub function of "CUS_INV_CREATE_ISSUE_REQUEST" function
            + (called by "CUS_INV_CREATE_ISSUE_REQUEST")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/13  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_CREATE_ISSUE_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CREATE_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Create_Issue_Request()
        - Create Issue Request
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Create_Issue_Request_In_Tag *CUS_INV_Create_Issue_Request_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_CREATE_ISSUE_REQUEST_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CREATE_ISSUE_REQUEST", out_node);

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
CUS_INV_CREATE_ISSUE_REQUEST_MAIN()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CREATE_ISSUE_REQUEST_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_ISSUE_REQUEST_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *create_in_node;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	TRSNode **req_mat_list;
	TRSNode *mat_list;
	int i;
	char issue_request_id[31];

	LOG_head("CUS_INV_CREATE_ISSUE_REQUEST");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Create_Issue_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(issue_request_id, ' ', sizeof(issue_request_id));

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "FROM_OPER", TRS.get_string(in_node, "FROM_OPER"));
	TRS.add_nstring(create_in_node, "REQ_OPER", TRS.get_string(in_node, "REQ_OPER"));
	TRS.add_nstring(create_in_node, "REQ_WORKER_ID", TRS.get_string(in_node, "REQ_WORKER_ID"));
	TRS.add_nstring(create_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

	req_mat_list = TRS.get_list(in_node, "REQ_MAT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "REQ_MAT_LIST"); i++)
	{
		mat_list = TRS.add_node(create_in_node, "REQ_MAT_LIST");
		TRS.add_nstring(mat_list, "REQ_MAT_ID", TRS.get_string(req_mat_list[i], "REQ_MAT_ID"));
		TRS.add_int(mat_list, "REQ_MAT_VER", TRS.get_int(req_mat_list[i], "REQ_MAT_VER"));
		TRS.add_double(mat_list, "REQ_QTY", TRS.get_double(req_mat_list[i], "REQ_QTY"));
	}

	// PROCSTEP = 1 -> 생성
	// PROCSTEP = 2 -> 수정
	if (TRS.get_procstep(in_node) == '1')
	{
		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_ISSUE_REQUEST_NO, strlen(MP_ID_ROLE_ISSUE_REQUEST_NO));
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
		memcpy(issue_request_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);

		TRS.add_string(create_in_node, "REQ_NO", issue_request_id, sizeof(issue_request_id));
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		TRS.add_nstring(create_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
	}

	if (CUS_INV_Create_Issue_Request_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CREATE_ISSUE_REQUEST(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Create_Issue_Request_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_CREATE_ISSUE_REQUEST()
        - Main sub function of "CUS_INV_Create_Issue_Request" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_ISSUE_REQUEST(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct CWIPWRKDEF_TAG CWIPWRKDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVLOTSTS_TAG MINVLOTSTS_COUNT;

    char s_sys_time[14];

	int i;
	double qty = 0;

	TRSNode **req_mat_list;
		  
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

	// MWIPOPRDEF - 요청 창고 정보 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
	TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "REQ_OPER");
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

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

	// MWIPOPRDEF - 자재 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
	TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER), in_node, "FROM_OPER");
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);

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

	// FROM 창고는 자재 또는 위탁창고여야만 함.
	if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) != 0
		&& memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) != 0)
	{
		strcpy(s_msg_code, "INV-0039");
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// CWIPWRKDEF - 작업자 정보 조회
	DBU_init_cwipwrkdef(&CWIPWRKDEF);
	TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID), in_node, "REQ_WORKER_ID");
	DBU_select_cwipwrkdef(1, &CWIPWRKDEF);
	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "CMN-0004");
		TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
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
		TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	req_mat_list = TRS.get_list(in_node, "REQ_MAT_LIST");

	if (TRS.get_item_count(in_node, "REQ_MAT_LIST") > 0)
	{
		// MINVREQMST - 불출 요청 지시 생성
		DBU_init_minvreqmst(&MINVREQMST);
		TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");
		memcpy(MINVREQMST.REQ_TIME, s_sys_time, sizeof(s_sys_time));
		memcpy(MINVREQMST.AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
		memcpy(MINVREQMST.SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
		memcpy(MINVREQMST.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
		memcpy(MINVREQMST.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
		memcpy(MINVREQMST.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
		memcpy(MINVREQMST.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
		memcpy(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_CREATE, sizeof(MINVREQMST.REQ_STATUS));
		memcpy(MINVREQMST.CMF_1, CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID));	//CMF_1 : 요청자
		memset(MINVREQMST.CMF_2, ' ', sizeof(MINVREQMST.CMF_2));
		memset(MINVREQMST.CMF_3, ' ', sizeof(MINVREQMST.CMF_3));
		memset(MINVREQMST.CMF_4, ' ', sizeof(MINVREQMST.CMF_4));
		memset(MINVREQMST.CMF_5, ' ', sizeof(MINVREQMST.CMF_5));
		memset(MINVREQMST.CMF_6, ' ', sizeof(MINVREQMST.CMF_6));
		memset(MINVREQMST.CMF_7, ' ', sizeof(MINVREQMST.CMF_7));
		memset(MINVREQMST.CMF_8, ' ', sizeof(MINVREQMST.CMF_8));
		memset(MINVREQMST.CMF_9, ' ', sizeof(MINVREQMST.CMF_9));
		memset(MINVREQMST.CMF_10, ' ', sizeof(MINVREQMST.CMF_10));
		TRS.copy(MINVREQMST.CREATE_USER_ID, sizeof(MINVREQMST.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQMST.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVREQMST.UPDATE_USER_ID, sizeof(MINVREQMST.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		// MINVREQMST - 불출 요청 지시 생성
		DBU_insert_minvreqmst(&MINVREQMST);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQMST INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	for (i = 0; i < TRS.get_item_count(in_node, "REQ_MAT_LIST"); i++)
	{
		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), req_mat_list[i], "REQ_MAT_ID");
		MWIPMATDEF.MAT_VER = TRS.get_int(req_mat_list[i], "REQ_MAT_VER");
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

		// 해당 제품, 공정에 존재하는 자재 LOT 수량 조회
		DBU_init_minvlotsts(&MINVLOTSTS_COUNT);
		TRS.copy(MINVLOTSTS_COUNT.FACTORY, sizeof(MINVLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS_COUNT.MAT_ID, sizeof(MINVLOTSTS_COUNT.MAT_ID), req_mat_list[i], "REQ_MAT_ID");
		MINVLOTSTS_COUNT.MAT_VER = TRS.get_int(req_mat_list[i], "REQ_MAT_VER");
		memcpy(MINVLOTSTS_COUNT.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
		qty = DBU_select_minvlotsts_scalar(2, &MINVLOTSTS_COUNT);

		if (qty < TRS.get_double(req_mat_list[i], "REQ_QTY"))
		{
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS_COUNT.MAT_ID), MINVLOTSTS_COUNT.MAT_ID);
			TRS.add_fieldmsg(out_node, "QTY", MP_DBL, qty);
			TRS.add_fieldmsg(out_node, "REQ_QTY", MP_DBL, TRS.get_double(req_mat_list[i], "REQ_QTY"));

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MINVREQDTL - 불출 요청 지시 상세 정보 생성
		DBU_init_minvreqdtl(&MINVREQDTL);
		TRS.copy(MINVREQDTL.FACTORY, sizeof(MINVREQDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQDTL.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		memcpy(MINVREQDTL.REQ_MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MINVREQDTL.REQ_MAT_VER = MWIPMATDEF.MAT_VER;
		MINVREQDTL.REQ_QTY = TRS.get_double(req_mat_list[i], "REQ_QTY");
		memcpy(MINVREQDTL.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
		memcpy(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_CREATE, sizeof(MINVREQDTL.REQ_STATUS));
		TRS.copy(MINVREQDTL.CREATE_USER_ID, sizeof(MINVREQDTL.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQDTL.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVREQDTL.UPDATE_USER_ID, sizeof(MINVREQDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		// MINVREQDTL - 불출 요청 지시 상세 정보 생성
		DBU_insert_minvreqdtl(&MINVREQDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQDTL INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQDTL.REQ_MAT_ID), MINVREQDTL.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, sizeof(MINVREQDTL.REQ_MAT_VER), MINVREQDTL.REQ_MAT_VER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Create_Issue_Request_Validation()
        - Validation Check sub function of "CUS_INV_CREATE_ISSUE_REQUEST" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_ISSUE_REQUEST_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Create_Issue_Request_Before_Transaction()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	// 수정 프로세스 : 삭제 -> 재생성
	if (TRS.get_procstep(in_node) == '2')
	{
		if (CUS_INV_DELETE_ISSUE_REQUEST_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}
	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Issue_Request_After_Transaction()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}