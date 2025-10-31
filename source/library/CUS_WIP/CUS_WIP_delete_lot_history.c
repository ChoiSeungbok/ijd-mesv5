/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_delete_lot_history.c
Description : Tran Delete Lot History function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/20  WG.LEE        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Delete_Lot_History_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Delete_Lot_History_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Delete_Lot_History_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_DELETE_LOT_HISTORY(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Delete_Lot_History()
- Tran adapt Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_Lot_History(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_DELETE_LOT_HISTORY(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Delete_Lot_History", out_node);
	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}
	if (i_ret == MP_TRUE)
	{
		if (gb_multi_transaction == MP_FALSE)
		{
			DB_commit();
		}
	}
	else
	{
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_DELETE_LOT_HISTORY()
- Main sub function of "CUS_WIP_Delete_Lot_History" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_DELETE_LOT_HISTORY(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPLOTHISX_TAG MWIPLOTHISX;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_RET;
	struct MSECUSRDEF_TAG MSECUSRDEF;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;


	struct work_date_tag work_date;

	TRSNode* del_in_node;
	char s_factory[10];
	char s_yyyymm[6];
	int i_stopseq;
	double d_pack_qty = 0;
	double d_pack_qty_2 = 0;




	LOG_head("CUS_WIP_Delete_Lot_History");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_Delete_Lot_History_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	memset(s_yyyymm, ' ', sizeof(s_yyyymm));
	Get_shift(s_factory, &work_date);
	i_stopseq = TRS.get_int(in_node, "STOP_SEQ");

	//TRS.copy(i_stopseq, sizeof(i_stopseq), in_node, "STOP_SEQ");


	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_dberrmsg(out_node, DB_error_msg);

		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		return MP_FALSE;
	}










	//Step = 2 인경우 : 검사 공정만 이력삭제 할 수 있는 화면에서 사용. 
	// tran_time이 전달인 경우, 검사 공정이 아닌경우 작업을 진행 할 수 없도록 한다. 
	if (TRS.get_procstep(in_node) == '2')
	{
		//lot 이력 조회
		DBU_init_mwiplothisx(&MWIPLOTHISX);
		TRS.copy(MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
		MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_mwiplothisx(1, &MWIPLOTHISX);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			return MP_FALSE;
		}

		if ((int)DBU_select_mwiplothisx_scalar(7, &MWIPLOTHISX) > 0) {
			//20221201 처리후 20분뒤에나 리턴가능하도록 수정
			//WIP-0693 : 리턴은 처리진행후 20분뒤에 가능합니다.
			strcpy(s_msg_code, "WIP-0693");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
			TRS.add_fieldmsg(out_node, "TRAN_TIME", DT_STRING, sizeof(MWIPLOTHISX.TRAN_TIME), MWIPLOTHISX.TRAN_TIME);
			return MP_FALSE;
		}

		memcpy(s_yyyymm, MWIPLOTHISX.TRAN_TIME, sizeof(s_yyyymm));

		//해당 월에 실적 처리가 되었는지 체크한다.
		if (memcmp(s_yyyymm, work_date.s_work_month, sizeof(s_yyyymm)) != MP_FALSE)
		{
			//WIP-0124 : 이 달은 유효하지 않습니다. 달을 확인 하세요.
			strcpy(s_msg_code, "WIP-0124");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
			TRS.add_fieldmsg(out_node, "TRAN_TIME", DT_STRING, sizeof(MWIPLOTHISX.TRAN_TIME), MWIPLOTHISX.TRAN_TIME);
			return MP_FALSE;
		}

		//공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);

		if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END)) == MP_FALSE
			|| memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_MOVE, strlen(MP_TRAN_CODE_MOVE)) == MP_FALSE)
		{
			memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OLD_OPER, sizeof(MWIPOPRDEF.OPER));
		}
		else
		{
			memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
		}

		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		/*
		//ctm 사업부에서만 이력 삭제를 할 수 있도록 한다.
		if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, strlen(gs_area_ctm)) != MP_FALSE)
		{
			//MIG-0014 : 검사공정이 아닙니다.
			strcpy(s_msg_code, "MIG-0014");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
			return MP_FALSE;
		}
		*/

		//검사 공정인 경우
		if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE ||
			memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE)
		{
		}
		else
		{
			//MIG-0014 : 검사공정이 아닙니다.
			strcpy(s_msg_code, "MIG-0014");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			return MP_FALSE;
		}
	}

	/*
	if (TRS.get_procstep(in_node) == '3') {


		//공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_RET);
		TRS.copy(MWIPOPRDEF_RET.FACTORY, sizeof(MWIPOPRDEF_RET.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_RET.OPER, sizeof(MWIPOPRDEF_RET.OPER), in_node, "RETURN_OPER");



		DBU_select_mwipoprdef(1, &MWIPOPRDEF_RET);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_RET.FACTORY), MWIPOPRDEF_RET.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_RET.OPER), MWIPOPRDEF_RET.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		}

	}
	*/

	del_in_node = TRS.add_node(in_node, "del_in_node");
	TRS.add_char(del_in_node, IN_PROCSTEP, '1');
	CopyDefaultMembers(del_in_node, in_node);

	if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
		TRS.add_nstring(del_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
	else
		TRS.add_string(del_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

	TRS.add_nstring(del_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
	TRS.add_int(del_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);



	/*
	if (CUS_WIP_Delete_Lot_History_Before_Transaction(s_msg_code, 0, del_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}
	*/



	if (TRS.get_procstep(in_node) == '2') {

		if (WIP_DELETE_LOT_HISTORY(s_msg_code, del_in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;

		}

		//다음히스토리에 Loss 있으면 Loss까지 제거
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			return MP_FALSE;
		}

		//lot 이력 조회
		DBU_init_mwiplothisx(&MWIPLOTHISX);
		TRS.copy(MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
		MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_mwiplothisx(1, &MWIPLOTHISX);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			return MP_FALSE;
		}

		if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_LOSS, strlen(MP_TRAN_CODE_LOSS)) == MP_FALSE)
		{

			del_in_node = TRS.add_node(in_node, "del_in_node");
			TRS.add_char(del_in_node, IN_PROCSTEP, '1');
			CopyDefaultMembers(del_in_node, in_node);

			if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
				TRS.add_nstring(del_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
			else
				TRS.add_string(del_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

			TRS.add_nstring(del_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
			TRS.add_int(del_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);


			if (WIP_DELETE_LOT_HISTORY(s_msg_code, del_in_node, out_node) == MP_FALSE)
			{
				return MP_FALSE;

			}

		}



	}

	else if (TRS.get_procstep(in_node) == '3') {


		DBC_init_msecusrdef(&MSECUSRDEF);
		TRS.copy(MSECUSRDEF.FACTORY, sizeof(MSECUSRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MSECUSRDEF.USER_ID, sizeof(MSECUSRDEF.USER_ID), in_node, IN_USERID);
		DBC_select_msecusrdef(1, &MSECUSRDEF);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "SEC-0004");
			TRS.add_fieldmsg(out_node, "MSECUSRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MSECUSRDEF.FACTORY), MSECUSRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MSECUSRDEF.USER_ID), IN_USERID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}



		//리턴권한추가(20240810)
		if (MSECUSRDEF.USER_CMF_10[0] != 'Y')
		{
			strcpy(s_msg_code, "WIP-0697");
			TRS.add_fieldmsg(out_node, "MSECUSRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MSECUSRDEF.FACTORY), MSECUSRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MSECUSRDEF.USER_ID), IN_USERID);
			TRS.add_fieldmsg(out_node, "RETURN ACCOUNT", MP_STR, sizeof(MSECUSRDEF.USER_CMF_9), MSECUSRDEF.USER_CMF_9);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;

		}



		do {



			DBU_init_cpaklotsts(&CPAKLOTSTS);
			memcpy(CPAKLOTSTS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CPAKLOTSTS.FACTORY));
			memcpy(CPAKLOTSTS.ORG_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));


			d_pack_qty = DBU_select_cpaklotsts_scalar(29, &CPAKLOTSTS);
			d_pack_qty_2 = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS);

			if (d_pack_qty != 0)
			{
				if (d_pack_qty == d_pack_qty_2)
				{
					DBU_delete_cpaklotsts(3, &CPAKLOTSTS);
					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "CMN-0004");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS DELETE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}

			}



			//lot 이력 조회
			DBU_init_mwiplothisx(&MWIPLOTHISX);
			TRS.copy(MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
			MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_mwiplothisx(1, &MWIPLOTHISX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				return MP_FALSE;
			}


			//공정 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
			memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));




			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);

				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//기본적으로 창고에서 CV되는 트랜잭션은 리턴안되게 막음..다른이력들과 꼬일수 있어서, 일단 요청받아서 조정,
			if (memcmp(MWIPOPRDEF.OPER_CMF_12, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) != MP_FALSE && memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CV, strlen(MP_TRAN_CODE_CV)) == MP_FALSE) {
				//MIG-0019 : 창고공정에서의 수량변경이력은 리턴할수없습니다.(기타입출고,자재투입..등)
				strcpy(s_msg_code, "MIG-0019");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				return MP_FALSE;
			}


			del_in_node = TRS.add_node(in_node, "del_in_node");
			TRS.add_char(del_in_node, IN_PROCSTEP, '1');
			CopyDefaultMembers(del_in_node, in_node);

			if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
				TRS.add_nstring(del_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
			else
				TRS.add_string(del_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

			TRS.add_nstring(del_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
			TRS.add_int(del_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);

			if (TRS.get_int(in_node, "HIST_SEQ") > 1 &&
				memcmp(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_CV, strlen(MP_TRAN_CODE_CV)) != 0)


				DBU_init_mwiplothisx(&MWIPLOTHISX);
			memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_mwiplothisx(1, &MWIPLOTHISX);


			//if (MWIPLOTHISX.TRAN_CODE)


			//CTM기준 가공은 같이 실적처리했어도 LOT별 리턴하고  전처리쪽은 처리한 실적들 같이 리턴. 다른사업부들은 뭐 어떻게 하든 크게 상관은 없음..
			if (MWIPOPRDEF.OPER_CMF_17[0] != 'Y')
			{
				memset(MWIPLOTHISX.MULTI_TR_KEY, ' ', sizeof(MWIPLOTHISX.MULTI_TR_KEY));
				MWIPLOTHISX.MULTI_TR_SEQ = 0;


				DBU_update_mwiplothisx(1, &MWIPLOTHISX);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}



			if (WIP_DELETE_LOT_HISTORY(s_msg_code, del_in_node, out_node) == MP_FALSE) {

				return MP_FALSE; 

			}
			//선택한 HIST까지의 상태이면 중지
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				return MP_FALSE;
			}


		} while (i_stopseq <= MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);


		//_stopseq

		//TRS.get_int(in_node, "STOP_SEQ")

		return MP_TRUE;

		/*
		//선택한 공정까지의 상태이면 중지
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			return MP_FALSE;
		}




		if (memcmp(MWIPLOTSTSX.OPER, MWIPOPRDEF_RET.OPER, strlen(MWIPOPRDEF_RET.OPER)) == MP_FALSE) {
			return MP_TRUE;
		}
		else {
			if (WIP_DELETE_LOT_HISTORY(s_msg_code, del_in_node, out_node) == MP_FALSE) {

				return MP_FALSE;

			}
		}


		*/


	}


	else {

		if (WIP_DELETE_LOT_HISTORY(s_msg_code, del_in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;

		}
	}



	if (CUS_WIP_Delete_Lot_History_After_Transaction(s_msg_code, 0, del_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}


	return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Delete_Lot_History_Validation()
- Validation Check sub function of "CUS_WIP_DELETE_LOT_HISTORY" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_Lot_History_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"123") == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Delete_Lot_History_Before_Transaction()
- Main sub function of "CUS_WIP_DELETE_LOT_HISTORY" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_Lot_History_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Delete_Lot_History_After_Transaction()
- Main sub function of "CUS_WIP_DELETE_LOT_HISTORY" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_Lot_History_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{

	return MP_TRUE;
}