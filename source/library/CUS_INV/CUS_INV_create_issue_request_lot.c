/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_create_issue_request_lot.c
    Description : Create Issue Request Lot

    MES Version : 5.2.0

    Function List
        - CUS_INV_Create_Issue_Request_Lot()
            + Create Issue Request Lot
        - CUS_INV_CREATE_ISSUE_REQUEST_LOT()
            + Main Sub function of "CUS_INV_Create_Issue_Request_Lot"
            + (called by "CUS_INV_Create_Issue_Request_Lot")
        - CUS_INV_Create_Issue_Request_Lot_Validation()
            + Validation Check sub function of "CUS_INV_CREATE_ISSUE_REQUEST_LOT" function
            + (called by "CUS_INV_CREATE_ISSUE_REQUEST_LOT")
       
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

int CUS_INV_CREATE_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Issue_Request_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Create_Issue_Request_Lot()
        - Create Issue Request Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Create_Issue_Request_Lot_In_Tag *CUS_INV_Create_Issue_Request_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CREATE_ISSUE_REQUEST_LOT", out_node);

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
CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *create_in_node;
	TRSNode **req_lot_list;
	TRSNode *lot_list;
	int i;

	LOG_head("CUS_INV_CREATE_ISSUE_REQUEST_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Create_Issue_Request_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
	//TRS.add_nstring(create_in_node, "REQ_MAT_ID", TRS.get_string(in_node, "REQ_MAT_ID"));
	//TRS.add_int(create_in_node, "REQ_MAT_VER", TRS.get_int(in_node, "REQ_MAT_VER"));

	req_lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(create_in_node, "REQ_LOT_LIST");
		TRS.add_nstring(lot_list, "REQ_LOT_ID", TRS.get_string(req_lot_list[i], "REQ_LOT_ID"));
	}

	if (CUS_INV_Create_Issue_Request_Lot_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CREATE_ISSUE_REQUEST_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Create_Issue_Request_Lot_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_CREATE_ISSUE_REQUEST_LOT()
        - Main sub function of "CUS_INV_Create_Issue_Request_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_ISSUE_REQUEST_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_ISSUE_REQUEST_LOT(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVREQLOT_TAG MINVREQLOT_COUNT;

	char s_sys_time[14];
	int i;
	double d_total_qty = 0;

	TRSNode **req_lot_list;
	//double d_total_qty = 0;

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

	if(DB_error_code == DB_NOT_FOUND)
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
	if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) != 0
		&& memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
	{
		strcpy(s_msg_code, "INV-0027");
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
		// 자재 LOT 정보 조회
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), req_lot_list[i], "REQ_LOT_ID");
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
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT LOAD 체크
		if (MINVLOTSTS.LOAD_FLAG == 'Y')
		{
			//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
			strcpy(s_msg_code, "INV-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
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
		memcpy(MINVREQDTL.REQ_MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
		MINVREQDTL.REQ_MAT_VER = MINVLOTSTS.MAT_VER;
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

		if (DB_error_code == DB_NOT_FOUND)
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

		DBU_init_minvreqlot(&MINVREQLOT_COUNT);
		TRS.copy(MINVREQLOT_COUNT.FACTORY, sizeof(MINVREQLOT_COUNT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQLOT_COUNT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		memcpy(MINVREQLOT_COUNT.REQ_MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
		MINVREQLOT_COUNT.REQ_MAT_VER = MINVREQDTL.REQ_MAT_VER;
		// 등록되어 있는 수량 체크
		d_total_qty = (int)DBU_select_minvreqlot_scalar(5, &MINVREQLOT_COUNT);

		if (d_total_qty > MINVREQDTL.REQ_QTY)
		{
			//INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "REQ_QTY", MP_DBL, MINVREQDTL.REQ_QTY);
			TRS.add_fieldmsg(out_node, "REG_QTY", MP_DBL, d_total_qty);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
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

		// 불출 요청 상세 정보 상태 체크
		if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) != 0
			&& memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
		{
			strcpy(s_msg_code, "INV-0027");
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

		// MINVREQLOT - 불출 요청 LOT 생성
		DBU_init_minvreqlot(&MINVREQLOT);
		TRS.copy(MINVREQLOT.FACTORY, sizeof(MINVREQLOT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVREQLOT.REQ_NO, MINVREQDTL.REQ_NO, sizeof(MINVREQDTL.REQ_NO));
		memcpy(MINVREQLOT.REQ_MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
		MINVREQLOT.REQ_MAT_VER = MINVREQDTL.REQ_MAT_VER;
		memcpy(MINVREQLOT.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		MINVREQLOT.REQ_QTY = MINVLOTSTS.QTY;
		memcpy(MINVREQLOT.UNIT, MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));
		memcpy(MINVREQLOT.REQ_STATUS, MP_CINV_ISSUE_REGIST, sizeof(MINVREQLOT.REQ_STATUS));
		TRS.copy(MINVREQLOT.CREATE_USER_ID, sizeof(MINVREQLOT.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQLOT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVREQLOT.UPDATE_USER_ID, sizeof(MINVREQLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVREQLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		// MINVREQLOT - 불출 요청 LOT 생성
		DBU_insert_minvreqlot(&MINVREQLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVREQLOT INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
			TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
			TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, sizeof(MINVREQLOT.REQ_MAT_VER), MINVREQLOT.REQ_MAT_VER);
			TRS.add_fieldmsg(out_node, "REQ_LOT_ID", MP_INT, sizeof(MINVREQLOT.INV_LOT_ID), MINVREQLOT.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (memcmp(MINVREQDTL.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) == 0)
		{
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


			// 불출 요청 마스터 상태 체크
			if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REGIST, strlen(MP_CINV_ISSUE_REGIST)) != 0)
			{
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
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Create_Issue_Request_Lot_Validation()
        - Validation Check sub function of "CUS_INV_CREATE_ISSUE_REQUEST_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_ISSUE_REQUEST_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Create_Issue_Request_Lot_Before_Transaction()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	/*if (CUS_INV_DELETE_ISSUE_REQUEST_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}*/
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Issue_Request_Lot_After_Transaction()
- Main sub function of "CUS_INV_CREATE_ISSUE_REQUEST_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Issue_Request_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}