/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Create_Inspection_Request.c
Description : Tran Create Inspection Request function

MES Version : 5.0

Function List
-

Detail Description
- 자재 입하 (IQC)  혹은  공정 Lot 검사공정의 이전 공정 End처리시(PQC or OQC) 호출하는 서비스
- 검사 요청 마스터가 생성된다

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/15  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"
#include "CUS_common.h"

int CUS_QCM_Create_Inspection_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Create_Inspection_Request()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Create_Inspection_Request(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_Create_Inspection_Request", out_node);
	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

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
CUS_QCM_CREATE_INSPECTION_REQUEST()
- Main sub function of "CUS_QCM_Create_Inspection_Request" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_CREATE_INSPECTION_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	//struct CQCMISPDAT_TAG CQCMISPDAT;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MINVDLVDTL_TAG MINVDLVDTL;

	struct CQCMISPSTS_TAG CQCMISPSTS_OLD;
	struct CQCMISPDAT_TAG CQCMISPDAT;

	struct CQCMGRTSIV_TAG CQCMGRTSIV;
	struct CQCMGRTHLT_TAG CQCMGRTHLT;
	struct CQCMGRTCOT_TAG CQCMGRTCOT;
	struct CQCMGRTASP_TAG CQCMGRTASP;

	char s_sys_time[14];
	char s_insp_id[26];

	//TRSNode *collect_in_node;
	//TRSNode **data_list;

	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;

	int i_insp_oper_check;


	LOG_head("CUS_QCM_Create_Inspection_Request");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_insp_id, ' ', sizeof(s_insp_id));

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


	/* Validation Check */
	if (CUS_QCM_Create_Inspection_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	//ProcStep 1  자재(DLV_LOT_ID) 검사 요청
	//ProcStep 2  제품(반제품) ( WIP LOT) 검사요청
	//ProcStep 3  자재 검사요청 취소

	if (TRS.get_procstep(in_node) == '1')
	{

		// DLV_LOT_ID 존재체크
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
		DBU_select_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//공정 정보
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MINVDLVLOT.OPER, sizeof(MINVDLVLOT.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//검사공정 체크
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, "C_INSP_TYPE", strlen("C_INSP_TYPE"));
		memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.OPER_GRP_2, sizeof(MWIPOPRDEF.OPER_GRP_2));
		i_insp_oper_check = (int)DBU_select_mgcmtbldat_scalar(1, &MGCMTBLDAT);

		if (i_insp_oper_check == 0)
		{
			strcpy(s_msg_code, "QCM-0054");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "NEXT_OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}


		memcpy(CQCMISPSTS.INSP_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));


		//이미 검사정보 있으면 패스 20230921 
		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CQCMISPSTS.LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
		memcpy(CQCMISPSTS.INSP_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_cqcmispsts(3, &CQCMISPSTS);
		if (DB_error_code != DB_NOT_FOUND)
		{
			return MP_TRUE;
		}

		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		//INSP_ID 발번
		CopyDefaultMembers(gen_in_node, in_node);
		TRS.add_string(gen_in_node, "RULE_ID", "INSP_ID", strlen("INSP_ID"));
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");

		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

		memcpy(s_insp_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);


		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CQCMISPSTS.INSP_ID, s_insp_id, sizeof(s_insp_id));
		memcpy(CQCMISPSTS.INSP_TYPE, MWIPOPRDEF.OPER_GRP_2, sizeof(MWIPOPRDEF.OPER_GRP_2));  //IQC
		memcpy(CQCMISPSTS.INSP_REQ_TIME, s_sys_time, sizeof(s_sys_time));
		CQCMISPSTS.INSP_STATUS = 'Q';
		//memset(CQCMISPSTS.INSP_JUDGE_FLAG, ' ', sizeof(CQCMISPSTS.INSP_JUDGE_FLAG));
		CQCMISPSTS.INSP_JUDGE_FLAG = ' ';
		//CQCMISPSTS.INSP_JUDGE_TYPE[0] = 'A';  //확인필요
		memset(CQCMISPSTS.INSP_JUDGE_TIME, ' ', sizeof(CQCMISPSTS.INSP_JUDGE_TIME));
		memcpy(CQCMISPSTS.INSP_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(CQCMISPSTS.LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
		memcpy(CQCMISPSTS.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
		CQCMISPSTS.MAT_VER = MINVDLVLOT.MAT_VER;
		CQCMISPSTS.QTY = MINVDLVLOT.QTY;
		memcpy(CQCMISPSTS.AREA_ID, MINVDLVLOT.AREA_ID, sizeof(CQCMISPSTS.AREA_ID));
		memset(CQCMISPSTS.RWK_FLOW, ' ', sizeof(CQCMISPSTS.RWK_FLOW));
		memset(CQCMISPSTS.RWK_OPER, ' ', sizeof(CQCMISPSTS.RWK_OPER));
		memset(CQCMISPSTS.CMF_1, ' ', sizeof(CQCMISPSTS.CMF_1));
		memset(CQCMISPSTS.CMF_2, ' ', sizeof(CQCMISPSTS.CMF_2));
		memset(CQCMISPSTS.CMF_3, ' ', sizeof(CQCMISPSTS.CMF_3));
		memset(CQCMISPSTS.CMF_4, ' ', sizeof(CQCMISPSTS.CMF_4));
		memset(CQCMISPSTS.CMF_5, ' ', sizeof(CQCMISPSTS.CMF_5));
		//memset(CQCMISPSTS.CMF_6, ' ', sizeof(CQCMISPSTS.CMF_6));
		CQCMISPSTS.CMF_6[0] = '1';
		memset(CQCMISPSTS.CMF_7, ' ', sizeof(CQCMISPSTS.CMF_7));
		memset(CQCMISPSTS.CMF_8, ' ', sizeof(CQCMISPSTS.CMF_8));
		memset(CQCMISPSTS.CMF_9, ' ', sizeof(CQCMISPSTS.CMF_9));
		memset(CQCMISPSTS.CMF_10, ' ', sizeof(CQCMISPSTS.CMF_10));
		TRS.copy(CQCMISPSTS.CREATE_USER_ID, sizeof(CQCMISPSTS.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CQCMISPSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		memset(CQCMISPSTS.UPDATE_USER_ID, ' ', sizeof(CQCMISPSTS.UPDATE_USER_ID));
		memset(CQCMISPSTS.UPDATE_TIME, ' ', sizeof(CQCMISPSTS.UPDATE_TIME));

		DBU_insert_cqcmispsts(&CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		memcpy(MINVDLVLOT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
		memcpy(MINVDLVLOT.INSP_REQ_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
		MINVDLVLOT.INSP_STATUS[0] = 'Q';
		MINVDLVLOT.INSP_RESULT_FLAG = ' ';
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_update_minvdlvlot(2, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
		DBU_select_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVLOT.DLV_NO), MINVDLVLOT.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//수입검사 대상 X
		if (MINVDLVDTL.INSPECTION_FLAG == 'N')
		{

			//UPDATE DLV LOT
			memcpy(MINVDLVLOT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(MINVDLVLOT.INSP_REQ_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
			MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
			MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_PASS;
			TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_update_minvdlvlot(2, &MINVDLVLOT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			// 검사요청정보 Update
			//todo( ReworkFlow, Reworkoper 추가 필요 )
			CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_COMPLETE;  //완료
			CQCMISPSTS.INSP_JUDGE_FLAG = MP_CQMS_INSP_JUDGE_PASS;
			memcpy(CQCMISPSTS.INSP_JUDGE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CQCMISPSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			DBU_update_cqcmispsts(2, &CQCMISPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{

		// LOT_ID 존재체크
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//공정 정보
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//검사공정 체크
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, "C_INSP_TYPE", strlen("C_INSP_TYPE"));
		memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.OPER_GRP_2, sizeof(MWIPOPRDEF.OPER_GRP_2));
		i_insp_oper_check = (int)DBU_select_mgcmtbldat_scalar(1, &MGCMTBLDAT);

		if (i_insp_oper_check == 0)
		{
			strcpy(s_msg_code, "QCM-0054");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "NEXT_OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//해당 Lot에 대해 이미 살아있는 검사요청이 존재하면 취소처리한다.
		DBU_init_cqcmispsts(&CQCMISPSTS);
		memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
		memcpy(CQCMISPSTS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		if ((int)DBU_select_cqcmispsts_scalar(3, &CQCMISPSTS) > 0)
		{
			CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_CANCEL;
			DBU_update_cqcmispsts(3, &CQCMISPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CQCMISPSTS.LOT_ID), CQCMISPSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

		}






		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		//INSP_ID 발번
		CopyDefaultMembers(gen_in_node, in_node);
		TRS.add_string(gen_in_node, "RULE_ID", "INSP_ID", strlen("INSP_ID"));
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

		memcpy(s_insp_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);


		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CQCMISPSTS.INSP_ID, s_insp_id, sizeof(s_insp_id));
		memcpy(CQCMISPSTS.INSP_TYPE, MWIPOPRDEF.OPER_GRP_2, sizeof(MWIPOPRDEF.OPER_GRP_2));
		memcpy(CQCMISPSTS.INSP_REQ_TIME, s_sys_time, sizeof(s_sys_time));
		CQCMISPSTS.INSP_STATUS = 'R';
		//memset(CQCMISPSTS.INSP_JUDGE_FLAG, ' ', sizeof(CQCMISPSTS.INSP_JUDGE_FLAG));
		CQCMISPSTS.INSP_JUDGE_FLAG = ' ';
		//CQCMISPSTS.INSP_JUDGE_TYPE[0] = 'A';  //확인필요
		memset(CQCMISPSTS.INSP_JUDGE_TIME, ' ', sizeof(CQCMISPSTS.INSP_JUDGE_TIME));
		memcpy(CQCMISPSTS.INSP_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(CQCMISPSTS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		memcpy(CQCMISPSTS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
		CQCMISPSTS.MAT_VER = MWIPLOTSTS.MAT_VER;
		CQCMISPSTS.QTY = MWIPLOTSTS.QTY_1;
		memset(CQCMISPSTS.RWK_FLOW, ' ', sizeof(CQCMISPSTS.RWK_FLOW));
		memset(CQCMISPSTS.RWK_OPER, ' ', sizeof(CQCMISPSTS.RWK_OPER));
		memcpy(CQCMISPSTS.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CQCMISPSTS.AREA_ID));
		memset(CQCMISPSTS.CMF_1, ' ', sizeof(CQCMISPSTS.CMF_1));  //접수시 시간
		memcpy(CQCMISPSTS.CMF_2, MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));  //ORDER_ID
		memcpy(CQCMISPSTS.CMF_3, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));               //요청시의 FLOW
		memset(CQCMISPSTS.CMF_4, ' ', sizeof(CQCMISPSTS.CMF_4));
		memset(CQCMISPSTS.CMF_5, ' ', sizeof(CQCMISPSTS.CMF_5));
		//memset(CQCMISPSTS.CMF_6, ' ', sizeof(CQCMISPSTS.CMF_6));
		CQCMISPSTS.CMF_6[0] = '1';
		memset(CQCMISPSTS.CMF_7, ' ', sizeof(CQCMISPSTS.CMF_7));
		memset(CQCMISPSTS.CMF_8, ' ', sizeof(CQCMISPSTS.CMF_8));
		memset(CQCMISPSTS.CMF_9, ' ', sizeof(CQCMISPSTS.CMF_9));
		memset(CQCMISPSTS.CMF_10, ' ', sizeof(CQCMISPSTS.CMF_10));
		TRS.copy(CQCMISPSTS.CREATE_USER_ID, sizeof(CQCMISPSTS.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CQCMISPSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		memset(CQCMISPSTS.UPDATE_USER_ID, ' ', sizeof(CQCMISPSTS.UPDATE_USER_ID));
		memset(CQCMISPSTS.UPDATE_TIME, ' ', sizeof(CQCMISPSTS.UPDATE_TIME));

		DBU_insert_cqcmispsts(&CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		memcpy(MWIPLOTSTS.LOT_CMF_10, s_insp_id, sizeof(s_insp_id));
		memset(MWIPLOTSTS.LOT_CMF_11, ' ', sizeof(MWIPLOTSTS.LOT_CMF_11));
		DBU_update_mwiplotstsx(2, &MWIPLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_CMF_10), MWIPLOTSTS.LOT_CMF_10);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		//기존 같은 LOT_ID,  OPER  인 검사요청번호를 찾아서  존재하면,  각각의 검사데이터를 모두 복사해온다.
		//검사공정의 복사대상여부는 CMF에서 'Y'인것만 복사한다.
		//재가공시  새로운 의뢰가 내려오더라도  기존 LOT_ID, OPER 에서 검사했던 데이터를 그대로 가져오기 위함.

		if (MWIPOPRDEF.OPER_CMF_9[0] == 'Y')
		{
			// 같은 LOT_ID , 검사공정에 이미 과거에 판정이력이 있는 경우
			DBU_init_cqcmispsts(&CQCMISPSTS_OLD);
			TRS.copy(CQCMISPSTS_OLD.FACTORY, sizeof(CQCMISPSTS_OLD.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPSTS_OLD.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			memcpy(CQCMISPSTS_OLD.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
			memcpy(CQCMISPSTS_OLD.INSP_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CQCMISPSTS_OLD.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			DBU_select_cqcmispsts(5, &CQCMISPSTS_OLD);
			if (DB_error_code == DB_SUCCESS)
			{

				// ***********[1] CQCMISPDAT  검사 기본 공통 데이터 테이블 확인 *************

				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID)); //과거 검사요청 번호

				if ((int)DBU_select_cqcmispdat_scalar(5, &CQCMISPDAT) > 0) //과거 요청번호에 데이터가 있는 경우
				{
					//과거 검사데이터를 신규 검사요청번호에 복사해준다.

					DBU_init_cqcmispdat(&CQCMISPDAT);
					TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));
					DBU_open_cqcmispdat(7, &CQCMISPDAT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN(7)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmispdat(7, &CQCMISPDAT);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmispdat(7);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmispdat(7);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));

						DBU_insert_cqcmispdat(&CQCMISPDAT);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPDAT INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

					}
				}

				// ***********[2] CQCMGRTSIV  검사 GRIT SIV 데이터 테이블 확인 *************

				DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
				TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));

				if ((int)DBU_select_cqcmgrtsiv_scalar(3, &CQCMGRTSIV) > 0)
				{
					//과거 검사데이터를 신규 검사요청번호에 복사해준다. ( GRIT의 PSD, BI, BTI 데이터 )
					DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
					TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));
					DBU_open_cqcmgrtsiv(2, &CQCMGRTSIV);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTSIV OPEN(2)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTSIV.FACTORY), CQCMGRTSIV.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmgrtsiv(2, &CQCMGRTSIV);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmgrtsiv(2);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTSIV FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmgrtsiv(2);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));

						DBU_insert_cqcmgrtsiv(&CQCMGRTSIV);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTSIV INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTSIV.FACTORY), CQCMGRTSIV.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTSIV.INSP_ID), CQCMGRTSIV.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}


				// ***********[3] CQCMGRTHLT  검사 GRIT HLT 데이터 테이블 확인 *************

				DBU_init_cqcmgrthlt(&CQCMGRTHLT);
				TRS.copy(CQCMGRTHLT.FACTORY, sizeof(CQCMGRTHLT.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTHLT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMGRTHLT.INSP_ID));

				if ((int)DBU_select_cqcmgrthlt_scalar(3, &CQCMGRTHLT) > 0)
				{
					//과거 검사데이터를 신규 검사요청번호에 복사해준다. ( GRIT의 HLT(Half life time) 데이터 )
					DBU_init_cqcmgrthlt(&CQCMGRTHLT);
					TRS.copy(CQCMGRTHLT.FACTORY, sizeof(CQCMGRTHLT.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMGRTHLT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));
					DBU_open_cqcmgrthlt(2, &CQCMGRTHLT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTHLT OPEN(2)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTHLT.FACTORY), CQCMGRTHLT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTHLT.INSP_ID), CQCMGRTHLT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmgrthlt(2, &CQCMGRTHLT);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmgrthlt(2);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTHLT FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmgrthlt(2);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						memcpy(CQCMGRTHLT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));

						DBU_insert_cqcmgrthlt(&CQCMGRTHLT);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTHLT INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTHLT.FACTORY), CQCMGRTHLT.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTHLT.INSP_ID), CQCMGRTHLT.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}

				// ***********[4] CQCMGRTCOT  검사 GRIT Coating 데이터 테이블 확인 *************

				DBU_init_cqcmgrtcot(&CQCMGRTCOT);
				TRS.copy(CQCMGRTCOT.FACTORY, sizeof(CQCMGRTCOT.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTCOT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMGRTCOT.INSP_ID));

				if ((int)DBU_select_cqcmgrtcot_scalar(2, &CQCMGRTCOT) > 0)
				{
					//과거 검사데이터를 신규 검사요청번호에 복사해준다. ( GRIT의 Coating 데이터 )
					DBU_init_cqcmgrtcot(&CQCMGRTCOT);
					TRS.copy(CQCMGRTCOT.FACTORY, sizeof(CQCMGRTCOT.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMGRTCOT.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));
					DBU_open_cqcmgrtcot(2, &CQCMGRTCOT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTCOT OPEN(2)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTCOT.FACTORY), CQCMGRTCOT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTCOT.INSP_ID), CQCMGRTCOT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmgrtcot(2, &CQCMGRTCOT);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmgrtcot(2);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTCOT FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmgrtcot(2);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						memcpy(CQCMGRTCOT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));

						DBU_insert_cqcmgrtcot(&CQCMGRTCOT);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTCOT INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTCOT.FACTORY), CQCMGRTCOT.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTCOT.INSP_ID), CQCMGRTCOT.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}


				// ***********[5] CQCMGRTASP  검사 GRIT Aspect 데이터 테이블 확인 *************

				DBU_init_cqcmgrtasp(&CQCMGRTASP);
				TRS.copy(CQCMGRTASP.FACTORY, sizeof(CQCMGRTASP.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTASP.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMGRTASP.INSP_ID));

				if ((int)DBU_select_cqcmgrtasp_scalar(2, &CQCMGRTASP) > 0)
				{
					//과거 검사데이터를 신규 검사요청번호에 복사해준다. ( GRIT의 Coating 데이터 )
					DBU_init_cqcmgrtasp(&CQCMGRTASP);
					TRS.copy(CQCMGRTASP.FACTORY, sizeof(CQCMGRTASP.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMGRTASP.INSP_ID, CQCMISPSTS_OLD.INSP_ID, sizeof(CQCMISPSTS_OLD.INSP_ID));
					DBU_open_cqcmgrtasp(2, &CQCMGRTASP);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMGRTASP OPEN(2)", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTASP.FACTORY), CQCMGRTASP.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cqcmgrtasp(2, &CQCMGRTASP);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmgrtasp(2);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTASP FETCH", DT_NOVALUESTRING);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							DBU_close_cqcmgrtasp(2);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						memcpy(CQCMGRTASP.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));

						DBU_insert_cqcmgrtasp(&CQCMGRTASP);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMGRTASP INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMGRTASP.FACTORY), CQCMGRTASP.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMGRTASP.INSP_ID), CQCMGRTASP.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}
		}

	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
		DBU_select_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}



		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		//TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		memcpy(CQCMISPSTS.INSP_ID, MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID));
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_CANCEL;
		memcpy(CQCMISPSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//DLV LOT => 검사정보 초기화
		memset(MINVDLVLOT.INSP_ID, ' ', sizeof(MINVDLVLOT.INSP_ID));
		memset(MINVDLVLOT.INSP_REQ_TIME, ' ', sizeof(MINVDLVLOT.INSP_REQ_TIME));
		memset(MINVDLVLOT.INSP_USER_ID, ' ', sizeof(MINVDLVLOT.INSP_USER_ID));
		memset(MINVDLVLOT.INSP_STATUS, ' ', sizeof(MINVDLVLOT.INSP_STATUS));
		MINVDLVLOT.INSP_RESULT_FLAG = ' ';
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}


	return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Create_Inspection_Request_Validation()
- Validation Check sub function of "CUS_QCM_CREATE_INSPECTION_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Create_Inspection_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		return MP_FALSE;
	}

	return MP_TRUE;
}
