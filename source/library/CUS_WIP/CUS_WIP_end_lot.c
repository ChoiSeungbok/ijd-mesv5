/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_end_lot.c
Description : Tran end Lot function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/03  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_End_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_End_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_End_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_End_Lot()
- Tran adapt Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_End_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_END_LOT(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_End_Lot", out_node);

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
CUS_WIP_END_LOT()
- Main sub function of "CUS_WIP_End_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_END_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	TRSNode* end_in_node;
	struct work_date_tag work_date;

	char s_factory[10];
	int i = 0;
	int j = 0;
	char s_member[5][101] = { "LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
	char s_member_name[101];

	LOG_head("CUS_WIP_End_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_End_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));

	Get_shift(s_factory, &work_date);

	//END 시작
	end_in_node = TRS.add_node(in_node, "end_in_node");

	TRS.add_char(end_in_node, IN_PROCSTEP, '1');
	CopyDefaultMembers(end_in_node, in_node);

	//create 시간은 클라이언트에서 서버 호출 시간으로 한다. 
	//gs_sys_time를 사용하는 이유는 create -> start가 같은 시간에 들어가도록 하기 위해.
	if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
		TRS.add_nstring(end_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
	else
		TRS.add_string(end_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

	//필수값
	TRS.add_nstring(end_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
	TRS.add_nstring(end_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
	TRS.add_int(end_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
	TRS.add_nstring(end_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
	TRS.add_nstring(end_in_node, "OPER", TRS.get_string(in_node, "OPER"));
	TRS.add_nstring(end_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
	TRS.add_nstring(end_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

	TRS.add_string(end_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
	TRS.add_string(end_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
	TRS.add_nstring(end_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
	TRS.add_nstring(end_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
	TRS.add_nstring(end_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
	TRS.add_char(end_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
	TRS.add_char(end_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
	TRS.add_char(end_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
	TRS.add_char(end_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
	TRS.add_char(end_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
	TRS.add_nstring(end_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
	TRS.add_nstring(end_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
	TRS.add_nstring(end_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
	TRS.add_nstring(end_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
	TRS.add_nstring(end_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));
	TRS.add_char(end_in_node, "RWK_FLAG", TRS.get_char(in_node, "RWK_FLAG"));
	TRS.add_nstring(end_in_node, "RWK_CODE", TRS.get_string(in_node, "RWK_CODE"));
	TRS.add_char(end_in_node, "SKIP_IF_YN", TRS.get_char(in_node, "SKIP_IF_YN"));
	TRS.add_char(end_in_node, "SCRAP_IF_YN", TRS.get_char(in_node, "SCRAP_IF_YN"));
	TRS.add_char(end_in_node, "CLASS_OPER_SKIP", TRS.get_char(in_node, "CLASS_OPER_SKIP"));  //분류정보시 작지 실적UPDATE SKIP여부
	TRS.add_char(end_in_node, "INV_FLAG", TRS.get_char(in_node, "INV_FLAG"));

	//완료시 TO_FLOW/TO_OPERD을 지정해 주면 지정된 공정으로 간다.
	if (COM_isnullspace(TRS.get_string(in_node, "TO_FLOW")) == MP_FALSE)
		TRS.add_nstring(end_in_node, "TO_FLOW", TRS.get_string(in_node, "TO_FLOW"));

	if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
		TRS.add_nstring(end_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 20; i++)
		{
			sprintf(s_member_name, "%s%d", s_member[j], i + 1);
			TRS.add_nstring(end_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
		}
	}

	if (CUS_WIP_End_Lot_Before_Transaction(s_msg_code, 0, end_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (WIP_END_LOT(s_msg_code, end_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_End_Lot_After_Transaction(s_msg_code, 0, end_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_End_Lot_Validation()
- Validation Check sub function of "CUS_WIP_END_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_End_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"1") == MP_FALSE)
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

/*******************************************************************************
CUS_WIP_End_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_END_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_End_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
	struct MWIPLOTHISX_TAG  MWIPLOTHISX;
	struct MGCMTBLDAT_TAG  MGCMTBLDAT;
	struct CWIPERPOPR_TAG  CWIPERPOPR;
	struct MWIPOPRDEF_TAG  MWIPOPRDEF;
	struct MWIPORDSTS_TAG  MWIPORDSTS;
	struct CWIPLOTREC_TAG  CWIPLOTREC;
	struct MRASRESDEF_TAG  MRASRESDEF;

	struct CWIPDWNSTS_TAG CWIPDWNSTS;

	int iCount = 0;

	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

	if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_FALSE)
	{
		if (TRS.mem_cmp(in_node, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
		{
			//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
			strcpy(s_msg_code, "WIP-0647");
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

	//P급인지 체크
	DBU_init_cwiplotrec(&CWIPLOTREC);
	memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
	memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
	DBU_select_cwiplotrec(2, &CWIPLOTREC);
	if (DB_error_code == DB_SUCCESS)
	{

		DBU_update_cwiplotrec(5, &CWIPLOTREC);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		/*
		//WIP-0668 : P급은 작업을 진행 할 수 없습니다. LOT을 확인하세요.
		strcpy(s_msg_code, "WIP-0668");
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
		*/
	}

	/*gcm의 SYSTEM_OPTION 에 셋업된 정보를 가져온다.
		KEY_1  : CUSTOM SYSTEM OPTION 코드
		DATA_1 : CUSTOM SYSTEM OPTION 명칭
		DATA_2 : OPTION 값
		DATA_3 : OPTION 사용여부
	*/
	//CUSTOM SYSTEM 옵션 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_SYSTEM, strlen(MP_GCM_SYSTEM));
	memcpy(MGCMTBLDAT.KEY_1, MP_SYS_CHECK_ERP_OPER_END, strlen(MP_SYS_CHECK_ERP_OPER_END));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
	if (DB_error_code != DB_SUCCESS)
	{
		//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
		strcpy(s_msg_code, "GCM-0008");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//MES 공정별 작업지시에 ERP 공정이 있는지 확인한다.
	if (MGCMTBLDAT.DATA_3[0] == 'Y')
	{
		//ERP 공정이 셋업되어 있는 공정인 경우 ERP공정과 비교 벨리데이션에
		//그릿의 분류가 아닐때. 
		if (MWIPOPRDEF.OPER_CMF_1[0] != ' ')
		{
			if (TRS.get_char(in_node, "CLASS_OPER_SKIP") == 'Y')
				return MP_TRUE;
			if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_FALSE)
			{
				//작업지시 조회
				DBU_init_mwipordsts(&MWIPORDSTS);
				TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
				DBU_select_mwipordsts(1, &MWIPORDSTS);

				if (memcmp(MWIPORDSTS.ORDER_DESC, "CLASS", strlen("CLASS")) == MP_FALSE)
					return MP_TRUE;

				//주말 선방전 pass 임시 코딩
				if (memcmp(MWIPOPRDEF.OPER, "OC04050", strlen("OC04050")) == MP_FALSE)
					return MP_TRUE;

				//lot이 생산품인 경우
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_P)
				{
					DBU_init_cwiperpopr(&CWIPERPOPR);
					memcpy(CWIPERPOPR.FACTORY, MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
					TRS.copy(CWIPERPOPR.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID), in_node, "ORDER_ID");
					memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
					DBU_select_cwiperpopr(2, &CWIPERPOPR);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							//WIP-0650 : MES공정과 ERP의 공정이 같지 않습니다. 작업지시의 FLOW를 조정하세요.
							strcpy(s_msg_code, "WIP-0650");
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}
				}
			}
		}
	}



	if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
	{

		if (memcmp(TRS.get_string(in_node, "COMMENT"), MP_PDA_TRAN_COMMENT, strlen(MP_PDA_TRAN_COMMENT)) == MP_FALSE)
		{


			//WIP-0695 : PDA로는 검사공정을 진행할수 없습니다.
			strcpy(s_msg_code, "WIP-0695");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER_DESC", MP_STR, sizeof(MWIPOPRDEF.OPER_DESC), MWIPOPRDEF.OPER_DESC);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;


		}


		//기존 LOT이 END 했던 공정인 경우 재작업 여부(RESV_FLAG_1)를 업데이트 한다. 
		DBU_init_mwiplothisx(&MWIPLOTHISX);
		memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(MWIPLOTHISX.OLD_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(MWIPLOTHISX.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END));
		iCount = (int)DBU_select_mwiplothisx_scalar(5, &MWIPLOTHISX);
		if (iCount > 0)
		{
			MWIPLOTSTSX.RESV_FLAG_1 = 'Y';
			MWIPLOTSTSX.RWK_COUNT = MWIPLOTSTSX.RWK_COUNT + 1;

			DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}



	if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
	{
		DBU_init_cwipdwnsts(&CWIPDWNSTS);
		TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), in_node, "RES_ID");
		CWIPDWNSTS.DOWN_STATUS = 'S';
		if ((int)DBU_select_cwipdwnsts_scalar(7, &CWIPDWNSTS) > 0)
		{
			//WIP-0682 : 현재 설비는 비가동상태입니다.  비가동종료 후 진행하시기 바랍니다.
			strcpy(s_msg_code, "WIP-0682");
			TRS.add_fieldmsg(out_node, "CWIPDWNSTS SELECT(7)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;


		}


	}

	//설비 이벤트에서 설비 상태값이 변경되기 때문에 조회해서 다시 넘겨준다.
	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);
	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_char(in_node, "RES_UP_DOWN_FLAG_VALUE", MRASRESDEF.RES_UP_DOWN_FLAG);
		TRS.add_string(in_node, "RES_PRI_STS_VALUE", MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS));
	}


	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_End_Lot_After_Transaction()
- Main sub function of "CUS_WIP_END_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_End_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPORDSTS_TAG   MWIPORDSTS;         //작업지시 마스터
	struct CWIPERPOPR_TAG   CWIPERPOPR;         //
	struct CWIPORDOPR_TAG   CWIPORDOPR;
	struct CWIPERPOPR_TAG   CWIPERPOPR_AF;      //
	struct CWIPERPOPR_TAG   CWIPERPOPR_NO;      //
	struct MWIPOPRDEF_TAG   MWIPOPRDEF;
	struct MWIPOPRDEF_TAG   MWIPOPRDEF_AF;
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_AREA;
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
	struct MWIPMATDEF_TAG   MWIPMATDEF;
	struct CWIPRCPDEF_TAG   CWIPRCPDEF;         //설비 레시비 정보
	struct MRASRESDEF_TAG   MRASRESDEF;         //설비 레시비 정보

	TRSNode* if_in;
	TRSNode* if_end_in;
	TRSNode* send_in;
	TRSNode* insp_in;

	TRSNode* Prod_ch_in;
	TRSNode* Prod_ch_list;


	TRSNode* cmn_out;
	char c_CheckErpInput;           //ERP 완료이력 여부
	char c_CheckErpResult;          //ERP에 생산이력 여부
	int iCheckToERP = MP_FALSE;

	if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	TRS.set_nstring(in_node, "TRAN_CODE", "END");

	// Lot 별 Summary
	if (Update_Lot_Summary(s_msg_code, in_node, out_node) == MP_FALSE)
		return MP_FALSE;

	//lot정보 조회
	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
	if (DB_error_code != DB_SUCCESS)
	{
		//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
		strcpy(s_msg_code, "WIP-0044");
		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//공정 정보 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
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

	//완료 이후 공정 정보 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
	TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
	if (DB_error_code != DB_SUCCESS)
	{
		//WIP-0010 : 이 공정은 존재 하지 않습니다.
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);
	if (DB_error_code == DB_SUCCESS)
	{
		MRASRESDEF.RES_UP_DOWN_FLAG = TRS.get_char(in_node, "RES_UP_DOWN_FLAG_VALUE");
		TRS.copy(MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS), in_node, "RES_PRI_STS_VALUE");
		DBU_update_mrasresdef(2, &MRASRESDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	//검사 공정인 경우
	if (memcmp(MWIPOPRDEF_AF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
	{
		insp_in = TRS.add_node(in_node, "insp_in");
		TRS.add_char(insp_in, IN_PROCSTEP, '2');
		CopyDefaultMembers(insp_in, in_node);

		TRS.add_string(insp_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, insp_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

		TRS.free_node(cmn_out);

		//CTM의 최종검사 또는 W/D 검사인 경우 라운드 검사 장비에 LOT정보를 보내준다.
		if (memcmp(MWIPOPRDEF_AF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
		{
			//최종검사이며, 라운드 검사인 경우 조건
			if (memcmp(MWIPOPRDEF_AF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE &&
				memcmp(MWIPOPRDEF_AF.OPER_CMF_5, MP_CQMS_INSP_JUDGE_GROUP_ROUND, strlen(MP_CQMS_INSP_JUDGE_GROUP_ROUND)) == MP_FALSE)
			{
				DBU_init_cwiprcpdef(&CWIPRCPDEF);
				memcpy(CWIPRCPDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
				memcpy(CWIPRCPDEF.AREA_ID, MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
				memcpy(CWIPRCPDEF.OPER, MWIPOPRDEF_AF.OPER, sizeof(MWIPOPRDEF_AF.OPER));
				memcpy(CWIPRCPDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				DBU_select_cwiprcpdef(1, &CWIPRCPDEF);
				//if (DB_error_code != DB_SUCCESS)
				//{
				//    //WIP-0625 : Round 검사의 Recipe 정보가 존재하지 않습니다.  Recipe 정보를 확인하세요.
				//    strcpy(s_msg_code, "WIP-0625");
				//    TRS.add_fieldmsg(out_node, "CWIPRCPDEF SELECT", MP_NVST);
				//    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPRCPDEF.FACTORY), CWIPRCPDEF.FACTORY);
				//    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPRCPDEF.AREA_ID), CWIPRCPDEF.AREA_ID);
				//    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPRCPDEF.OPER), CWIPRCPDEF.OPER);
				//    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);
				//    TRS.add_dberrmsg(out_node, DB_error_msg);

				//    gs_log_type.type = MP_LOG_ERROR;
				//    gs_log_type.e_type = MP_LOG_E_SYSTEM;
				//    gs_log_type.category = MP_LOG_CATE_VIEW;

				//    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				//    return MP_FALSE;
				//}

				DBU_init_mrasresdef(&MRASRESDEF);
				memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
				memcpy(MRASRESDEF.AREA_ID, MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
				MRASRESDEF.RES_CMF_1[0] = 'Y';
				memcpy(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_ROUND, strlen(MP_RESS_GRP_ROUND));
				DBU_select_mrasresdef(2, &MRASRESDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0626 : Round 검사 장비가 존재하지 않습니다. Round 검사 장비를 확인하세요.
					strcpy(s_msg_code, "WIP-0626");
					TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MRASRESDEF.AREA_ID), MRASRESDEF.AREA_ID);
					TRS.add_fieldmsg(out_node, "RES_GRP_1", MP_STR, sizeof(MRASRESDEF.RES_GRP_1), MRASRESDEF.RES_GRP_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//라운드 검사 설비에 lot정보를 쏴주는 것은 실적화면에서 설비를 선택하지 않고, 검사 공정에 검사 의뢰시 
				//설비에 데이터가 넘어가야 하기 때문에 end lot after쪽에 넣는다. 
				send_in = TRS.add_node(in_node, "send_in");
				TRS.add_char(send_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(send_in, in_node);
				TRS.add_string(send_in, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
				TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
				TRS.add_string(send_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
				TRS.add_string(send_in, "RECIPE_ID", CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_EIS_START_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
	}

	//CLASS_OPER_SKIP가 Y시(그릿 분류) SKIP 처리 한다. 
	//CLASS_OPER_SKIP가 있는 분류 서비스에서는 erp실적 처리를 별도로 하기 때문에 아래 로직은 전부 skip해야 한다.
	//그릿의 분류는 작업지시가 없지 진행되기 때문에. 
	if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
	{
		//작업지시 조회
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//공정별 작업지시에 end 수량을 업데이트 한다. 
		DBU_init_cwipordopr(&CWIPORDOPR);
		memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		memcpy(CWIPORDOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_cwipordopr(1, &CWIPORDOPR);
		if (DB_error_code == DB_SUCCESS)
		{
			if (MWIPLOTSTSX.RESV_FLAG_1 == 'Y')
			{
				CWIPORDOPR.OPER_RWK_OUT_QTY = CWIPORDOPR.OPER_RWK_OUT_QTY + MWIPLOTSTSX.QTY_1;
			}
			else
			{
				CWIPORDOPR.OPER_OUT_QTY = CWIPORDOPR.OPER_OUT_QTY + MWIPLOTSTSX.QTY_1;
			}

			//작업지시 수량보다 많은 수량이 완료시 공정 작업지시는 자동 마감처리를 한다.
			if (MWIPORDSTS.ORD_QTY <= CWIPORDOPR.OPER_OUT_QTY + CWIPORDOPR.OPER_LOSS_QTY)
			{
				CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_CLOSE;
				memcpy(CWIPORDOPR.OPER_END_TIME, gs_sys_time, sizeof(CWIPORDOPR.OPER_END_TIME));
				TRS.copy(CWIPORDOPR.OPER_END_DATE, sizeof(CWIPORDOPR.OPER_END_DATE), in_node, "TRAN_CMF_1");
			}

			memcpy(CWIPORDOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDOPR.UPDATE_TIME));
			TRS.copy(CWIPORDOPR.UPDATE_USER_ID, sizeof(CWIPORDOPR.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_cwipordopr(1, &CWIPORDOPR);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPORDOPR UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//다음공정이 창고로 가는 경우를 마지막공정이라고 판단하여 작업지시의 out 수량 실적을 올려준다.
		if (MWIPOPRDEF_AF.INV_FLAG == 'Y')
		{
			if (MWIPLOTSTSX.RESV_FLAG_1 == 'Y')
			{
				MWIPORDSTS.ORD_RWK_QTY = MWIPORDSTS.ORD_RWK_QTY + MWIPLOTSTSX.QTY_1;
			}
			else
			{
				MWIPORDSTS.ORD_OUT_QTY = MWIPORDSTS.ORD_OUT_QTY + MWIPLOTSTSX.QTY_1;
			}

			//작업지시 수량보다 많은 수량이 완료시 작업지시는 자동 마감처리를 한다.
			//불량 수량 + 양품 수량이 작업지시 수량보다 커질때 작지 완료 -> 불량 수량이 빠져있었어서 추가. _ 210322_LWG
			if (MWIPORDSTS.ORD_OUT_QTY >= MWIPORDSTS.ORD_QTY + MWIPORDSTS.ORD_LOSS_QTY)
			{
				MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_CLOSE;
			}

			memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
			TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//인터페이스 스킵 여부가 Y인 경우 ERP에 인터페이스를 보내지 않는다. 
		// ex) 외주입고에서 end 인 경우
		if (TRS.get_char(in_node, "SKIP_IF_YN") != 'Y')
		{
			//해당 lot이 테스트 품인 경우 ERP I/F를 타지 못하게 한다.
			if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
			{
				//ERP에 생산 이력 및 완료 이력 여부를 리턴 받아오는 함수
				if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, in_node, out_node) == MP_FALSE)
					return MP_FALSE;

				//LOT ID에 대한 품목 정보를 조회한다.
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = 1;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				//ERP AREA 정보 조회
				DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
				TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
				memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//완료 이후 작업지시 ERP 공정 조회
				DBU_init_cwiperpopr(&CWIPERPOPR_AF);
				memcpy(CWIPERPOPR_AF.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR_AF.FACTORY));
				memcpy(CWIPERPOPR_AF.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR_AF.ORDER_ID));
				memcpy(CWIPERPOPR_AF.OPER, MWIPOPRDEF_AF.OPER_CMF_1, sizeof(CWIPERPOPR_AF.OPER));
				DBU_select_cwiperpopr(2, &CWIPERPOPR_AF);
				if (DB_error_code == DB_SUCCESS)
					iCheckToERP = MP_TRUE;
				else
					iCheckToERP = MP_FALSE;

				//작업지시 ERP 공정 조회
				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
				DBU_select_cwiperpopr(2, &CWIPERPOPR);

				//To Oper를 지정해 주는 경우 erp 실적 전송 공정이 아닌 경우 다음 공정의 erp 공정과 비교하여 다르면 실적을 전송한다.
				if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
				{
					if (c_CheckErpResult != 'Y')
					{
						if (memcmp(CWIPERPOPR.OPER, CWIPERPOPR_AF.OPER, sizeof(CWIPERPOPR_AF.OPER)) != MP_FALSE)
							c_CheckErpResult = 'Y';
					}
					else if (c_CheckErpResult == 'Y')
					{
						if (memcmp(CWIPERPOPR.OPER, CWIPERPOPR_AF.OPER, sizeof(CWIPERPOPR_AF.OPER)) == MP_FALSE)
							c_CheckErpResult = 'N';
					}

					if (c_CheckErpInput != 'Y')
					{
						if (MWIPOPRDEF_AF.INV_FLAG == 'Y')
							c_CheckErpInput = 'Y';
					}
				}

				//ERP 공정 실적 정보 I/F 전송 여부 
				if (c_CheckErpResult == 'Y')
				{
					//DBU_init_if_move_trx(&IF_MOVE_TRX);
					if_in = TRS.add_node(in_node, "if_in");
					TRS.add_char(if_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(if_in, in_node);

					TRS.add_char(if_in, "TRAN_FLAG", 'I');
					TRS.add_string(if_in, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					TRS.add_int(if_in, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
					TRS.add_string(if_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					TRS.add_int(if_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
					TRS.add_string(if_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
					TRS.add_int(if_in, "FROM_OPER_SEQ", CWIPERPOPR.OPER_SEQ);

					//From인 경우 무조건 Q로 보낸다.  => 재작업인 경우는 추후 다시 확인.
					TRS.add_string(if_in, "FROM_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
					TRS.add_int(if_in, "FROM_STEP_TYPE", 1);

					if (c_CheckErpInput == 'Y')
					{
						if (MWIPOPRDEF_AF.INV_FLAG == 'Y')
						{
							TRS.add_string(if_in, "TO_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
							TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_T, strlen(MP_ERP_TRAN_STEP_T));
							TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR.OPER_SEQ);
							TRS.add_int(if_in, "TO_STEP_TYPE", 3);
						}
						else
						{
							TRS.add_string(if_in, "TO_OPER", MWIPOPRDEF_AF.OPER_CMF_1, sizeof(MWIPOPRDEF_AF.OPER_CMF_1));
							TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
							TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR_AF.OPER_SEQ);
							TRS.add_int(if_in, "TO_STEP_TYPE", 1);
						}
					}
					else
					{
						//TO 공정이 erp 공정에 없는 경우 다음 ERP공정을 찾아 해당 공정을 TO공정으로 지정해 준다.
						if (iCheckToERP == MP_FALSE)
						{
							DBU_init_cwiperpopr(&CWIPERPOPR_NO);
							memcpy(CWIPERPOPR_NO.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR_NO.FACTORY));
							memcpy(CWIPERPOPR_NO.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR_NO.ORDER_ID));
							memcpy(CWIPERPOPR_NO.AREA_ID, CWIPERPOPR.AREA_ID, sizeof(CWIPERPOPR_NO.AREA_ID));
							CWIPERPOPR_NO.OPER_SEQ = CWIPERPOPR.NEXT_OPER_SEQ;
							DBU_select_cwiperpopr(101, &CWIPERPOPR_NO);

							TRS.add_string(if_in, "TO_OPER", CWIPERPOPR_NO.OPER, sizeof(CWIPERPOPR_NO.OPER));
							TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR_NO.OPER_SEQ);
						}
						else
						{
							TRS.add_string(if_in, "TO_OPER", MWIPOPRDEF_AF.OPER_CMF_1, sizeof(MWIPOPRDEF_AF.OPER_CMF_1));
							TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR_AF.OPER_SEQ);
						}

						TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
						TRS.add_int(if_in, "TO_STEP_TYPE", 1);
					}

					//to 공정에 대한 erp작업지시가 존재하지 않음. => to  oper seq가 있을 때만 진행. 
					//MOVE TRX에 지속적으로 에러가 발생하여 수정._20210329_LWG
					if (TRS.get_int(if_in, "TO_OPER_SEQ") == 0)
					{
						//WIP-0689 : To 공정에 대한 ERP 작업지시가 없습니다. 작업지시를 확인하세요.
						strcpy(s_msg_code, "WIP-0689");
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR_AF.OPER), CWIPERPOPR_AF.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					TRS.add_string(if_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(if_in, "QTY", MWIPLOTSTSX.QTY_1);
					TRS.add_nstring(if_in, "OPER", TRS.get_string(in_node, "OPER"));
					TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

					//작업지시의 수량보다 많은 수량이 실적이 잡히면 OVER_FLAG를 y한다.
					if (MWIPORDSTS.ORD_QTY < CWIPORDOPR.OPER_OUT_QTY + CWIPORDOPR.OPER_LOSS_QTY)
						TRS.add_char(if_in, "OVER_FLAG", 'Y');
					else
						TRS.add_char(if_in, "OVER_FLAG", 'N');

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_MOVE_TRX(s_msg_code, if_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}

				//ERP 공정 마지막 완료 정보 I/F 전송 여부 
				if (c_CheckErpInput == 'Y')
				{
					if (MWIPOPRDEF_AF.INV_FLAG == 'Y')
					{
						if_end_in = TRS.add_node(in_node, "if_end_in");
						TRS.add_char(if_end_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_end_in, in_node);

						TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
						TRS.add_string(if_end_in, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_int(if_end_in, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
						TRS.add_string(if_end_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						TRS.add_int(if_end_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
						TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_44));
						TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
						TRS.add_string(if_end_in, "INV_OPER", MWIPOPRDEF_AF.OPER_CMF_1, sizeof(MWIPOPRDEF_AF.OPER_CMF_1));
						TRS.add_int(if_end_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
						TRS.add_string(if_end_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						TRS.add_string(if_end_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						TRS.add_double(if_end_in, "QTY", MWIPLOTSTSX.QTY_1);
						TRS.add_nstring(if_end_in, "MES_OPER", TRS.get_string(in_node, "OPER"));
						TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);
					}
				}
			}

			else {


				if (MWIPOPRDEF_AF.INV_FLAG == 'Y' && memcmp(MWIPOPRDEF_AF.OPER_GRP_1, "LOSS", strlen("LOSS")) != MP_FALSE)
				{
					//20240809 테스트 작지이지만 바로 양산품 전환을 선택한 경우 바로 전환시킨다
					if (MWIPORDSTS.ORD_CMF_9[0] == 'Y')
					{
						Prod_ch_in = TRS.add_node(in_node, "Prod_ch_in");
						TRS.add_char(Prod_ch_in, "PROCSTEP", '1');
						CopyDefaultMembers(Prod_ch_in, in_node);

						Prod_ch_list = TRS.add_node(Prod_ch_in, "LOT_LIST");
						TRS.add_string(Prod_ch_list, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(Prod_ch_list, "TO_CREATE_CODE", "PROD", sizeof("PROD"));



						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_CHANGE_TEST_PROD_LOT(s_msg_code, Prod_ch_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}






					}
				}

			}
		}
		//인터페이스 P급 창고인 경우 불량으로 올린다.
		if (TRS.get_char(in_node, "SCRAP_IF_YN") == 'Y')
		{
			if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
			{
				//LOT ID에 대한 품목 정보를 조회한다.
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = 1;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				//ERP AREA 정보 조회
				DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
				TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
				memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
				DBU_select_cwiperpopr(2, &CWIPERPOPR);

				if_in = TRS.add_node(in_node, "if_in");
				TRS.add_char(if_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_in, in_node);

				TRS.add_char(if_in, "TRAN_FLAG", 'I');
				TRS.add_string(if_in, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				TRS.add_int(if_in, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
				TRS.add_string(if_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_int(if_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
				TRS.add_string(if_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_int(if_in, "FROM_OPER_SEQ", CWIPERPOPR.OPER_SEQ);
				TRS.add_string(if_in, "FROM_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
				TRS.add_int(if_in, "FROM_STEP_TYPE", 1);
				TRS.add_string(if_in, "TO_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S));
				TRS.add_int(if_in, "TO_STEP_TYPE", 5);
				TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR.OPER_SEQ);
				TRS.add_string(if_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(if_in, "QTY", MWIPLOTSTSX.QTY_1);
				TRS.add_nstring(if_in, "OPER", TRS.get_string(in_node, "OPER"));
				TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_char(if_in, "OVER_FLAG", 'N');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_MOVE_TRX(s_msg_code, if_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);
			}
		}
	}

	//재작업 여부가 Y인 경우 다시 공백 처리를 해준다.
	if (MWIPLOTSTSX.RESV_FLAG_1 != ' ')
	{
		MWIPLOTSTSX.RESV_FLAG_1 = ' ';

		DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
	}

	return MP_TRUE;
}