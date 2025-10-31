/*******************************************************************************

	System      : MESplus
	Module      : CUS_INV
	File Name   : CUS_INV_in_lot.c
	Description : In Inv Lot

	MES Version : 4.0.0

	Function List
		- CUS_INV_In_Lot()
			+ In Lot
		- CUS_INV_IN_LOT()
			+ Main sub function of "CUS_INV_In_Lot" function
			+ In Lot definition
		- CUS_INV_In_Lot_Validation()
			+ Validation Check sub function of "CUS_INV_IN_LOT" function

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

int CUS_INV_IN_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_In_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_In_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_In_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_INV_IN_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);


/*******************************************************************************
	CUS_INV_In_Lot()
		- In Lot
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_In_Lot(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_IN_LOT_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_IN_LOT", out_node);

	if (i_ret == MP_TRUE)
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
CUS_INV_IN_LOT()
- Main sub function of "CUS_INV_In_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_IN_LOT_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{
	TRSNode* in_in_node;
	TRSNode** inv_lot_list;
	TRSNode* inv_list;
	int i;

	LOG_head("CUS_INV_IN_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_In_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	in_in_node = TRS.add_node(in_node, "in_in_node");
	CopyDefaultMembers(in_in_node, in_node);

	TRS.add_char(in_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(in_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
	}

	TRS.add_nstring(in_in_node, "MAT_TYPE", TRS.get_string(in_node, "MAT_TYPE"));
	TRS.add_nstring(in_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
	TRS.add_nstring(in_in_node, "OPER", TRS.get_string(in_node, "OPER"));

	if (CUS_INV_In_Lot_Before_Transaction(s_msg_code, 0, in_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_IN_LOT(s_msg_code, in_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_In_Lot_After_Transaction(s_msg_code, 0, in_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_INV_IN_LOT()
		- Main sub function of "CUS_INV_In_Lot" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_IN_LOT(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{

	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
	struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_WH;
	struct MWIPMATDEF_TAG MWIPMATDEF;

	char s_sys_time[14];

	int i;
	// int c_step=0;

	TRSNode** inv_lot_list;

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

		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVLOTSTS_OLD.DLV_NO, sizeof(MINVLOTSTS_OLD.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVLOTSTS_OLD.DLV_SEQ;
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

		// 자재 LOT 수입 검사 공정 체크
		if (MINVLOTSTS_OLD.INSP_RESULT_FLAG == ' ')
		{
			strcpy(s_msg_code, "INV-0016");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS_OLD.MAT_ID, sizeof(MINVLOTSTS_OLD.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVLOTSTS_OLD.MAT_VER;
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

		//MAT_CMF_9 : 금형 여부
		if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
		{
			if (MINVDLVDTL.CONSIGNMENT_FLAG == 'Y') {

				// MWIPOPRDEF - 자재 창고 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_in_lot_02) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) != 0)
				{
					//INV-0076 : 해당 창고는 위탁 창고가 아닙니다.
					strcpy(s_msg_code, "INV-0076");
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else {
				DBU_init_mgcmtbldat(&MGCMTBLDAT_WH);
				TRS.copy(MGCMTBLDAT_WH.FACTORY, sizeof(MGCMTBLDAT_WH.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_WH.TABLE_NAME, MP_GCM_MOLD_OPER, strlen(MP_GCM_MOLD_OPER));

				//2022/03/02 한국은 바로 금형창고로 베트남은 원자재 창고에서 금형창고로 분출하는것으로 프로세스 바꿈.

				memcpy(MGCMTBLDAT_WH.KEY_1, MINVLOTSTS_OLD.AREA_ID, sizeof(MGCMTBLDAT_WH.KEY_1));

				//memcpy(MGCMTBLDAT_WH.KEY_3, MINVLOTSTS_OLD.AREA_ID, sizeof(MGCMTBLDAT_WH.KEY_3));


				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_WH);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_WH.FACTORY), MGCMTBLDAT_WH.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_WH.TABLE_NAME), MGCMTBLDAT_WH.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_WH.KEY_1), MGCMTBLDAT_WH.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// MWIPOPRDEF - 자재 창고 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				//memcpy(MWIPOPRDEF.OPER, MGCMTBLDAT_WH.DATA_1, sizeof(MWIPOPRDEF.OPER));   
				memcpy(MWIPOPRDEF.OPER, MGCMTBLDAT_WH.DATA_3, sizeof(MWIPOPRDEF.OPER));

				//2022/03/02 한국은 바로 금형창고로 베트남은 원자재 창고에서 금형창고로 분출하는것으로 프로세스 바꿈.

				DBU_select_mwipoprdef(1, &MWIPOPRDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_in_lot_01) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_WH.DATA_1), MGCMTBLDAT_WH.DATA_1);
					TRS.add_fieldmsg(out_node, "OPER2", MP_STR, sizeof(MGCMTBLDAT_WH.DATA_3), MGCMTBLDAT_WH.DATA_3);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}


		}
		else
		{
			// MWIPOPRDEF - 자재 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_in_lot_02) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (MINVDLVDTL.CONSIGNMENT_FLAG == 'Y')
			{
				if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) != 0)
				{
					//INV-0076 : 해당 창고는 위탁 창고가 아닙니다.
					strcpy(s_msg_code, "INV-0076");
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) != 0)
				{
					//INV-0077 : 해당 창고는 자재 창고가 아닙니다.
					strcpy(s_msg_code, "INV-0077");
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

		// TRAN CODE : IN
		// IQC 합격 -> 자재 입고
		memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));

		// 자재 창고로 이동
		memcpy(MINVLOTSTS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
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
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;

}

/*******************************************************************************
	CUS_INV_In_Lot_Validation()
		- Validation Check sub function of "CUS_INV_IN_LOT" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_In_Lot_Validation(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
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
CUS_INV_In_Lot_Before_Transaction()
- Main sub function of "CUS_INV_IN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_In_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_In_Lot_After_Transaction()
- Main sub function of "CUS_INV_IN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_In_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}