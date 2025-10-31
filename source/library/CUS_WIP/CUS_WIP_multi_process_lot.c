/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_multi_process_lot.c
Description : lot 메인 프로세스

MES Version : 5.0

Function List
- step 1 : 작업시작
- step 2 : 작업완료

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/03  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Multi_Process_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_MULTI_PROCESS_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Multi_Process_Lot()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Multi_Process_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_MULTI_PROCESS_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Multi_Process_Lot", out_node);
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
CUS_WIP_MULTI_PROCESS_LOT()
- Main sub function of "CUS_WIP_Multi_Process_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_MULTI_PROCESS_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	    //LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_AF;	//LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;	//LOT 마스터
	struct MWIPLOTHISX_TAG MWIPLOTHISX;	    //LOT 히스토리 마스터
	struct MWIPORDSTS_TAG MWIPORDSTS;       //작업지시 마스터
	struct MWIPOPRDEF_TAG MWIPOPRDEF;       //공정 마스터
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;                   //공정 마스터  
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;                   //공정 마스터  
	struct MWIPMATDEF_TAG MWIPMATDEF;       //
	struct MRASRESDEF_TAG MRASRESDEF;       //
	struct MRASRESMFO_TAG MRASRESMFO;       //
	struct CWIPOPRWRK_TAG CWIPOPRWRK;       //공정 작업자
	struct CWIPLOTLST_TAG CWIPLOTLST;       //불량 임시등록    
	struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM DATA TABLE
	struct MGCMTBLDAT_TAG MGCMTBLDAT_D;     //GCM DATA TABLE (공정별 저장 데이터)
	struct MGCMTBLDAT_TAG MGCMTBLDAT_RES;               //GCM DATA TABLE (레시피 설비 전송 정보)
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;                 //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;                 //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_DEL;
	struct CWIPGRPSTS_TAG CWIPGRPSTS;       //그룹 마스터 테이블
	struct CWIPGRPLOT_TAG CWIPGRPLOT;       //그룹 LOT 테이블
	struct CWIPPRSRUN_TAG CWIPPRSRUN;
	struct CWIPLOTPRS_TAG CWIPLOTPRS;       //PRESS 설비 정보테이블
	struct MINVLOTISS_TAG MINVLOTISS;                   //자재 사용
	struct CWIPERPOPR_TAG CWIPERPOPR;                   //
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct CWIPORDBOM_TAG CWIPORDBOM;
	struct CWIPLOTMVR_TAG CWIPLOTMVR;                   //
	struct CWIPLOTTRC_TAG CWIPLOTTRC;                   //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SUB_AREA;

	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	TRSNode* create_in;
	TRSNode* start_in;
	TRSNode* end_in;
	TRSNode* adapt_in;
	TRSNode* loss_in;
	TRSNode* unit_in;
	TRSNode* inv_in;
	TRSNode* split_in;
	TRSNode* cv_in;
	TRSNode* store_in;
	TRSNode* unstore_in;
	//TRSNode *insp_in;
	TRSNode* send_in;
	TRSNode* terminate_in;
	TRSNode* res_in;
	//TRSNode *erpchk_in;
	TRSNode* argu_list_node;
	TRSNode** Lot_tbl;
	TRSNode** Worker_tbl;
	TRSNode* list_item;
	TRSNode* erpif_in;
	TRSNode* move_in;

	TRSNode* inv_if;

	struct work_date_tag work_date;
	int iCheckOperOption = 0;
	int iCheckOperData = 0;         //공정 데이터 여부
	//char c_CheckErpInput;           //ERP 생산완료 여부
	//char c_CheckErpResult;          //ERP에 생산이력 여부
	int i_lot_count = 0;
	int i_worker_count = 0;
	int i_step = 0;
	char s_lot_id[26];
	char s_group_id[26];
	char s_cell_id[26];
	int i_Qty = 0;
	double d_splitQty = 0;
	char s_factory[10];
	int iRunCount = 0;
	char* ptr1;
	char c_skip_yn;
	double d_inv_txns_id = 0;
	int iCount = 0;
	int iChage_Seq = 0;
	double d_beofore_qty = 0;
	double d_ifseq = 0;
	char c_if_seq[30];

	// LOG
	LOG_head("CUS_WIP_Multi_Process_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	// VALIDATION CHECK
	if (CUS_WIP_Multi_Process_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(s_group_id, ' ', sizeof(s_group_id));
	memset(s_lot_id, ' ', sizeof(s_lot_id));
	memset(s_factory, ' ', sizeof(s_factory));
	memset(s_cell_id, ' ', sizeof(s_cell_id));

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	//설비 파라미터가 나오면 설비를 조회한다
	if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
	{
		/*
		설비 옵션
		- RES_CMF_1 : LOT 전송 여부
		=> LOT 전송 여부가 'Y'인 경우 해당 LOT 정보를 설비에 보낸다.
		- RES_CMF_2 : 설비 상태 수신 여부
		*/

		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
		DBU_select_mrasresdef(1, &MRASRESDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//EDC-0021 : 이 장비는 존재 하지 않습니다. 장비를 확인 하세요.
			strcpy(s_msg_code, "EDC-0021");
			TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_mrasresmfo(&MRASRESMFO);
		TRS.copy(MRASRESMFO.FACTORY, sizeof(MRASRESMFO.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASRESMFO.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
		TRS.copy(MRASRESMFO.OPER, sizeof(MRASRESMFO.OPER), in_node, "OPER");
		DBU_select_mrasresmfo(3, &MRASRESMFO);
		if (DB_error_code != DB_SUCCESS)
		{
			//RAS-0246 : 선택한 장비가 MFO에 정의되어 있지 않습니다.
			strcpy(s_msg_code, "RAS-0246");
			TRS.add_fieldmsg(out_node, "MRASRESMFO SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESMFO.FACTORY), MRASRESMFO.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESMFO.RES_ID), MRASRESMFO.RES_ID);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASRESMFO.OPER), MRASRESMFO.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

	}

	//공정 조회
	/*
		공정옵션
		- OPER_CMF_1 : MES 공정 코드에 맵핑된 ERP 공정 코드
		- OPER_CMF_2 : 공정LOT 투입 여부
						=> 해당 FLOW에서 끝나는 LOT은 FLOW별 창고에 들어가서 다음 작업지시의 자재로 들어간다.
						허나 자재로 투입 되지 않고 같은 LOT ID로 쭉 진행되어야 하는 공정인 경우
						OPER_CMF_2를 'Y'로 하여 진행하면 현재 작업지시에 있는 창고로 이동된 LOT ID가 자재 투입이 아닌
						그래로 작업 시작을 한다.
		- OPER_CMF_3 : 외주 창고 공정
		- OPER_CMF_4 : 자동 창고 이동 여부
						OPER_CMF_2를 'Y'로 하면 다른 FLOW의 창고에 있는 LOT을 현재 작업지시의 창고로 자동 이동 처리 후
						START를 할 수 있도록 하는 옵션이다.
						EX) CTM의 황삭준비공정(작업지시 공정)인 경우 이전 flow의 창고에서 별도의 이동처리가 없이 황삭 START
		- OPER_CMF_5 : 판정그룹
		- OPER_CMF_6 : 검사IMG종류
		- OPER_CMF_7 : CUP-CELL MAPPING 공정 여부
		- OPER_CMF_8 : TO_OPER 제외 공정
						=> 실적 처리시 TO OPER를 선택 할 때, OPER_CMF_8에 Y인 공정은 TO OPER로 지정 할 수 없다.
						EX) CTM 작업지시공정, 외경가공, 레이저마킹 공정 같은 경우.
	*/
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

	//창고 고정은 lot작업을 시작 및 완료 할 수 없다. 
	if (MWIPOPRDEF.INV_FLAG == 'Y')
	{
		//WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
		strcpy(s_msg_code, "WIP-0628");
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//CUP - CELL 맵핑 공정인 경우 lot작업을 시작 및 완료 할 수 없다. 
	if (MWIPOPRDEF.OPER_CMF_7[0] == 'Y')
	{
		//WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
		strcpy(s_msg_code, "WIP-0628");
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
		memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
	{
		//WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
		strcpy(s_msg_code, "WIP-0628");
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//to 공정이 정해지는경우 현재 공정에 ERP공정이 묶여있지 않은 경우 에러 
	// => ERP I/F문제로 인해.
	if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
	{
		if (MWIPOPRDEF.OPER_CMF_1[0] == ' ')
		{
			//WIP-0666 : 이공정은 다음공정을 지정할 수 있는 공정이 아닙니다.  ERP공정 맵필 여부를 확인하세요.
			strcpy(s_msg_code, "WIP-0666");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//OPER_CMF_8가 'Y'인 경우 TO OPER를 할 수 없다. (특이공정: 작업지시공정, 외경가공공정)
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
		if (DB_error_code == DB_SUCCESS)
		{
			if (MWIPOPRDEF_TO.OPER_CMF_8[0] == 'Y')
			{
				//WIP-0678 : 이 공정은 TO 공정으로 지정할 수 없는 공정입니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0678");
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}

	//공정 데이터 저장 여부 
	//GCM의 C_OPER_DATA 에 각 공정별 저장 데이터를 셋업하여 해당 리스트를 저장 한다.
	DBU_init_mgcmtbldat(&MGCMTBLDAT_D);
	TRS.copy(MGCMTBLDAT_D.FACTORY, sizeof(MGCMTBLDAT_D.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT_D.TABLE_NAME, MP_GCM_OPER_DATA, strlen(MP_GCM_OPER_DATA));
	memcpy(MGCMTBLDAT_D.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
	iCheckOperData = (int)DBU_select_mgcmtbldat_scalar(2, &MGCMTBLDAT_D);

	/*gcm의 OPER_OPTION 에 셋업된 정보를 가져온다.
		DATA_1 : 시작 트랜젝션옵션 - 시작공정의 START 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
		DATA_2 : 완료 트랜젝션옵션 - 시작공정의 END 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
		DATA_3 : 공정별 id 발번 규칙 - 공정별 ID 발번 규칙을 셋업한다.
		DATA_4 : 그룹ID 생성룰 - 그룹 ID를 발번 하고, 그룹 테이블에 INSERT 한다.
		DATA_5 : CV 허용 공정 - 수량변경 처리를 할 수 있는 공정(dat_1 이 create인 공정 포함)
		DATA_6 : 공정별 id 발번 규칙2 - 공정별 ID 발번 규칙을 셋업한다. ID rule이 두개인 경우.
		DATA_7 : split공정시 split될 자lot이 qty값.
		DATA_8 : 특정 설비 저장 공정 여부. press인 경우 lot의 save res id에 저장되도록 한다.
		DATA_9 : LOT 채번시 특정 문자 추가 가능 공정 - 그릿인 경우 2자리를 더 선택하여 추가한다.
	*/
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_OPER_OPTION, strlen(MP_GCM_OPER_OPTION));
	memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
	memcpy(MGCMTBLDAT.KEY_2, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
	memcpy(MGCMTBLDAT.KEY_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
	if (DB_error_code == DB_SUCCESS)
	{
		iCheckOperOption = MP_TRUE;
	}
	else
	{
		iCheckOperOption = MP_FALSE;
	}

	//step 1 : 작업시작
	if (TRS.get_procstep(in_node) == '1')
	{
		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
		i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

		for (int i = 0; i < i_lot_count; i++)
		{
			//개별 lot별로 작업지시를 조회한다.
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), Lot_tbl[i], "ORDER_ID");
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

			//완료 또는 삭제된 작업지시는 진행 할 수 없음
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_FINISH
				|| MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_DELETE)
			{
				//ORD-0024 : 선택한 Order는 이미 삭제되었습니다.
				strcpy(s_msg_code, "ORD-0024");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//작업지시가 대기 상태면 작업지시 시작처리 해준다.
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
			{
				MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
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

			memset(s_lot_id, ' ', sizeof(s_lot_id));

			//LOT ID가 없는경우 LOT ID를 생성한 후 START처리를 한다.  
			if (COM_isnullspace(TRS.get_string(Lot_tbl[i], "LOT_ID")) == MP_TRUE)
			{
				//공정OPTION의 시작 트랜젝션옵션(DATA_1) 이 CREATE 인 경우 해당 공정에서는 LOT을 생성 할 수 있다.
				if (memcmp(MGCMTBLDAT.DATA_1, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) == MP_FALSE)
				{
					//공정OPTION의 ID 발번 규칙(DATA_3)이 등록 되어있는지 체크 한다.
					if (MGCMTBLDAT.DATA_3[0] == ' ')
					{
						//WIP-0597 : ID 발번 규칙이 정의되어있지 않습니다.  ID 발번 규칙을 설정하세요.
						strcpy(s_msg_code, "WIP-0597");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//공정별 LOT ID 발번 규칙을 셋업하여 찾아오도록 한ㄷ. -> 공정셋업이 안되어 있으므로 임시 테스트 발번   
					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);
					TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));

					if (memcmp(MGCMTBLDAT.DATA_3, MP_ID_ROLE_GRT_PRESS_LOT_ID, strlen(MP_ID_ROLE_GRT_PRESS_LOT_ID)) == MP_FALSE)
					{
						TRS.add_string(gen_in_node, "RESG_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					}

					TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
					//사업부별 채번룰의 SEQ가 1번이 되는 경우 FLOW로 사업부를 파라미터로 넘겨 SEQ를 채번한다.
					TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
					TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
					TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
					TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
					TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					//LOT 채번시 특정 문자 추가 가능 공정(MGCMTBLDAT.DATA_9) 인경우 채번된 lot id에 추가 문자를 붙인다.
					if (MGCMTBLDAT.DATA_9[0] == 'Y')
					{
						if (COM_isnullspace(TRS.get_string(in_node, "CREATE_LOT_KEY")) == MP_FALSE)
						{
							sprintf(s_lot_id, "%s%s", TRS.get_string(cmn_out, "GEN_ID"), TRS.get_string(in_node, "CREATE_LOT_KEY"));
						}
						else
						{
							memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
						}
					}
					else
					{
						memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
					}

					TRS.free_node(cmn_out);

					// 테스트 작업지시인 경우 lot채번 후 첫글자를 변경한다. 
					// GCM AREA에 DATA_6에 변경할 첫 글자를 세팅함. 
					// GCM AREA에 DATA_7에 변경될 글자의 index번호를 세팅항.
					// CTM, HM에 한해서만 세팅함. 
					if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_T)
					{
						//FROM AREA 정보 조회
						DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
						TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
						memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
						memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
						if (DB_error_code != DB_SUCCESS)
						{
							if (DB_error_code == DB_NOT_FOUND)
							{
								//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
								strcpy(s_msg_code, "GCM-0008");
								gs_log_type.e_type = MP_LOG_E_EXISTENCE;
							}
							else
							{
								strcpy(s_msg_code, "INV-0004");
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								TRS.add_dberrmsg(out_node, DB_error_msg);
							}

							TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
							TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						// GCM AREA에 DATA_6에 변경할 첫 글자가 있는지 여부를 확인한다. 
						if (MGCMTBLDAT_FROM.DATA_6[0] != ' ')
						{
							//변경될 글자의 index번호를 찾아 변경한다. 
							if (MGCMTBLDAT_FROM.DATA_7[0] != ' ')
							{
								/*
								//lot의 첫글자가 'R'인경우 연구소 lot이기 때문에 연구소 lot은 첫 글자가 R로 유지 한다.
								if (s_lot_id[0] != 'R')
								{
									iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

									s_lot_id[iChage_Seq - 1] = MGCMTBLDAT_FROM.DATA_6[0];
								}
								*/


								if (MWIPLOTSTSX.LOT_ID[0] == 'R')
								{
									iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

									s_lot_id[iChage_Seq - 1] = 'R';
								}
								else
								{
									iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

									s_lot_id[iChage_Seq - 1] = MGCMTBLDAT_FROM.DATA_6[0];
								}

							}
						}
					}

					//lot id 생성
					create_in = TRS.add_node(in_node, "create_in");
					TRS.add_char(create_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(create_in, in_node);

					TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
					TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
					TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
					TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
					TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
					TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
					TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
					TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
					TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
					TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
					TRS.add_double(create_in, "QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
					TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
					TRS.add_nstring(create_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
				else
				{
					//WIP-0596 : 해당 공정은 Lot 생성 공정이 아닙니다. Lot 생성 여부를 확인하세요.
					strcpy(s_msg_code, "WIP-0596");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				TRS.copy(s_lot_id, sizeof(s_lot_id), Lot_tbl[i], "LOT_ID");
			}

			//생성된 LOT ID 또는 Client에서 받은 LOT ID에 대한 정보를 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
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

			//이동지시 확정이 안된 LOT은 작업을 진행 할 수 없다.            
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
			memcpy(CWIPLOTMVR.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
			iCount = (int)DBU_select_cwiplotmvr_scalar(4, &CWIPLOTMVR);
			if (iCount > 0)
			{
				//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
				strcpy(s_msg_code, "WIP-0564");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			if (memcmp(MGCMTBLDAT.DATA_1, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) != MP_FALSE)
			{
				if (MWIPOPRDEF.OPER_CMF_2[0] != 'Y')
				{

					if (TRS.mem_cmp(Lot_tbl[i], "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
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
			}

			//LOT ID에 대한 품목 정보를 조회한다.
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			//lot 삭제여부 체크
			if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
			{
				//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//생산 작업지시에 테스트 품을 시작할 수 없다.
			if (MWIPORDSTS.LOT_TYPE != MWIPLOTSTSX.LOT_TYPE)
			{
				//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
				strcpy(s_msg_code, "WIP-0681");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_fieldmsg(out_node, "LOT_TYPE", MP_CHR, MWIPLOTSTSX.LOT_TYPE);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//공정 LOT 시작여부(공정 OPER_CMF_2 옵션)가 Y인 경우 ADAPT로 LOT의 제품 코드 및 공정,FLOW를 변경 후 LOT START를 한다.
			if (MWIPOPRDEF.OPER_CMF_2[0] == 'Y')
			{
				//LOT의 FROM 공정 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
				TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

				/*
					자동 창고 이동 공정인 경우
					CTM의 황삭준비공정(작업지시 공정)인 경우 이전 flow의 창고에서 별도의 이동처리가 없이
					lot 이동처리 후 lot을 이동처리 한다.
				*/


				if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
				{
					//WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0657");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				if (MWIPOPRDEF.OPER_CMF_4[0] == 'Y')
				{
					//창고 이동이 안되어 있는경우 작업지시의 FLOW창고로 STORE처리를 해준다.
					// => 현재 lot이 작업지시의 창고가 아닐경우 이동처리를 해준다.
					if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
					{
						/*
						//창고 이동하여 자재 FLAG로 되어있는지 체크한다.
						if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
						{
							//WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
							strcpy(s_msg_code, "WIP-0657");
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
						*/
						//이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
						if (MWIPLOTSTSX.INV_FLAG == 'Y')
						{
							unstore_in = TRS.add_node(in_node, "unstore_in");
							TRS.add_char(unstore_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(unstore_in, in_node);

							TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
							TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);



							store_in = TRS.add_node(in_node, "store_in");
							TRS.add_char(store_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(store_in, in_node);

							TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_string(store_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
							TRS.add_string(store_in, "TO_OPER", MWIPORDSTS.ORD_CMF_3, sizeof(MWIPORDSTS.ORD_CMF_3));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);
						}
						else {

							//20220502 수정 Store 안쓸거임
							move_in = TRS.add_node(in_node, "move_in");
							CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

							TRS.add_char(move_in, "PROCSTEP", '1');
							TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_string(move_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));

							TRS.add_string(move_in, "TO_OPER", MWIPORDSTS.ORD_CMF_3, sizeof(MWIPORDSTS.ORD_CMF_3));

							TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
							TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
							TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);


						}




						//lot이 정상lot인 경우에만 이동 erp 인터페이스를 해준다.
						if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_P)
						{
							//FROM AREA 정보 조회
							DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
							TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
							memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
							DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
							if (DB_error_code != DB_SUCCESS)
							{
								if (DB_error_code == DB_NOT_FOUND)
								{
									//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
									strcpy(s_msg_code, "GCM-0008");
									gs_log_type.e_type = MP_LOG_E_EXISTENCE;
								}
								else
								{
									strcpy(s_msg_code, "INV-0004");
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									TRS.add_dberrmsg(out_node, DB_error_msg);
								}

								TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
								TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							//TO 창고 조회
							DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
							TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
							memcpy(MWIPOPRDEF_TO.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_TO.OPER));
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

							//TO AREA 정보 조회
							DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
							TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
							memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
							DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
							if (DB_error_code != DB_SUCCESS)
							{
								if (DB_error_code == DB_NOT_FOUND)
								{
									//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
									strcpy(s_msg_code, "GCM-0008");
									gs_log_type.e_type = MP_LOG_E_EXISTENCE;
								}
								else
								{
									strcpy(s_msg_code, "INV-0004");
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									TRS.add_dberrmsg(out_node, DB_error_msg);
								}

								TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
								TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
							TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
							memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
							DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
							if (DB_error_code != DB_SUCCESS)
							{
								if (DB_error_code == DB_NOT_FOUND)
								{
									//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
									strcpy(s_msg_code, "GCM-0008");
									gs_log_type.e_type = MP_LOG_E_EXISTENCE;
								}
								else
								{
									strcpy(s_msg_code, "INV-0004");
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									TRS.add_dberrmsg(out_node, DB_error_msg);
								}

								TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
								TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
								TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							//창고 이동 인터페이스 
							DBU_init_cbastxndef(&CBASTXNDEF);
							TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
							CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
							CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
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
								CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
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

							//ERP 실적 - IF_INV_TXNS
							erpif_in = TRS.add_node(in_node, "erpif_in");
							TRS.add_char(erpif_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(erpif_in, in_node);

							TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
							TRS.add_int(erpif_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_2));
							TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
							TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
							TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
							TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
							TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
							TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
							TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
							TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
							TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
							TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
							TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
							TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
							TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
							TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
							TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

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
							memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							d_inv_txns_id = DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

							//ERP 실적 - IF_INV_TXN_LOTS
							erpif_in = TRS.add_node(in_node, "erpif_in");
							TRS.add_char(erpif_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(erpif_in, in_node);

							TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
							TRS.add_double(erpif_in, "INV_TXNS_ID", d_inv_txns_id);
							TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
							TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
							TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
							TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));     //이동지시 번호

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);
						}

						//lot 정보 조회
						DBU_init_mwiplotstsx(&MWIPLOTSTSX);
						memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
						DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

						//LOT의 FROM 공정 조회
						DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
						TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
						memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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
					}
				}

				//창고이동여부 체크
				if (MWIPLOTSTSX.INV_FLAG != 'Y')
				{
					if (MWIPLOTSTSX.NSTD_FLAG == 'Y' && memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END)) == MP_FALSE)
					{

					}
					else
					{
						/*
						//WIP-0564 : 창고이동되지 않은 lot은 진행 할 수 없습니다.
						strcpy(s_msg_code, "WIP-0564");
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
						*/
					}
				}

				//현재 lot의 mat id가 변경되는 to mat id의 bom상에 없으면 에러 메시지.
				DBU_init_cwipordbom(&CWIPORDBOM);
				TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID));
				memcpy(CWIPORDBOM.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));

				if ((int)DBU_select_cwipordbom_scalar(4, &CWIPORDBOM) == 0)
				{
					//ORD-0028 : 이 자재는 작업지시 BOM에 속해 있지 않습니다. 작업지시를 확인하세요.
					strcpy(s_msg_code, "ORD-0028");
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				//작업지시의 제품코드와 LOT ID의 제품코드가 다른 경우
				//LOT의 INV_FLAG(자재 여부)가 'Y'일 경우
				// => LOT 의 제품코드, FLOW, 공정을 변경해 준다.
				//if (MWIPOPRDEF_FROM.INV_FLAG == 'Y' && MWIPLOTSTSX.INV_FLAG == 'Y')


					//memcmp(MWIPLOTSTSX.MAT_ID, MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID)) != MP_FALSE &&
					//&& memcmp(MWIPOPRDEF_FROM.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_FROM.OPER)) == MP_FALSE)
				if (MWIPOPRDEF_FROM.INV_FLAG == 'Y')
				{
					//표준 작업지시인 경우 모품목, 자품목이 같은경우 에러
					if (MWIPORDSTS.ORD_CMF_7[0] == 'Y')
					{
						if (memcmp(MWIPLOTSTSX.MAT_ID, MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID)) == MP_FALSE)
						{
							//WIP-0671 : 표준 작업지시는 모품목과 자품목이 같을 수 없습니다. 작업지시를 확인하세요.
							strcpy(s_msg_code, "WIP-0671");
							TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					//lot adapt 처리
					adapt_in = TRS.add_node(in_node, "apt_in");
					TRS.add_char(adapt_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(adapt_in, in_node);

					TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
					TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
					TRS.add_string(adapt_in, "TO_MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
					TRS.add_int(adapt_in, "TO_MAT_VER", MWIPORDSTS.MAT_VER);
					TRS.add_string(adapt_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.add_string(adapt_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
					TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
					TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
					TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
					TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
					//TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
					TRS.add_nstring(adapt_in, "TRAN_CMF_3", "ORDER_CHANGE");  // 자품목이 모품목으로 LOT이 동일하게 들어가는경우

					if (MWIPOPRDEF.OPER_CMF_14[0] != ' ')
					{
						d_beofore_qty = MWIPLOTSTSX.QTY_1;

						TRS.add_double(adapt_in, "QTY_1", COM_atof(MWIPOPRDEF.OPER_CMF_14[0], sizeof(MWIPOPRDEF.OPER_CMF_14[0])));

					}
					else
					{
						TRS.add_double(adapt_in, "QTY_1", MWIPLOTSTSX.QTY_1);
					}


					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					//작업지시의 첫 공정을 조회한다
					//ADAPT 되는 공정은 작업지시의 첫공정이기 때문에 첫 공정을 조회한다.
					DBU_init_cwiperpopr(&CWIPERPOPR);
					memcpy(CWIPERPOPR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
					memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					DBU_select_cwiperpopr(3, &CWIPERPOPR);

					//자재사용 저장
					//ADAPT 처리가 되더라고 이전 작업지시의 LOT이 현재 작업지시에 투입되는 것이므로 자재 사용 테이블에 INSERT시켜준다. 
					//ERP I/F는 해당 ERP별 공정 END시 ERP에 올라간다.
					DBU_init_minvlotiss(&MINVLOTISS);
					memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
					memcpy(MINVLOTISS.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
					MINVLOTISS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
					memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
					TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
					memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX.LAST_TRAN_TIME));
					memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
					memcpy(MINVLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					MINVLOTISS.MAT_VER = MWIPLOTSTSX.MAT_VER;
					memcpy(MINVLOTISS.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MINVLOTISS.AREA_ID));
					memcpy(MINVLOTISS.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID));
					memcpy(MINVLOTISS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					memcpy(MINVLOTISS.ERP_OPER, CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
					memcpy(MINVLOTISS.OUT_OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
					memcpy(MINVLOTISS.REASON_CODE, MP_INPUT_TYPE_LOT, strlen(MP_INPUT_TYPE_LOT));
					MINVLOTISS.TRAN_QTY = d_beofore_qty; // MWIPLOTSTSX.QTY_1;
					memcpy(MINVLOTISS.TRAN_UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
					memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

					//if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
					//{
					memcpy(MINVLOTISS.CMF_4, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
					//}

					DBU_insert_minvlotiss(&MINVLOTISS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "MINVLOTISS INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
						TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}


					//AREA 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
					TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
					memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
					if (DB_error_code != DB_SUCCESS)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
						TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_VIEW;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}


					//SUB AREA 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT_SUB_AREA);
					TRS.copy(MGCMTBLDAT_SUB_AREA.FACTORY, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_SUB_AREA.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
					memcpy(MGCMTBLDAT_SUB_AREA.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SUB_AREA);
					if (DB_error_code != DB_SUCCESS)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
						TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), MGCMTBLDAT_SUB_AREA.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.KEY_1), MGCMTBLDAT_SUB_AREA.KEY_1);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_VIEW;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_P) {




						inv_if = TRS.add_node(in_node, "inv_if");
						TRS.add_char(inv_if, IN_PROCSTEP, '1');
						CopyDefaultMembers(inv_if, in_node);

						TRS.add_char(inv_if, "TRAN_FLAG", 'I');
						TRS.add_string(inv_if, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_int(inv_if, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
						TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
						TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
						TRS.add_string(inv_if, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
						TRS.add_int(inv_if, "ERP_SUB_AREA_ID", COM_atoi(MGCMTBLDAT_SUB_AREA.DATA_8, sizeof(MGCMTBLDAT_SUB_AREA.DATA_8)));
						TRS.add_int(inv_if, "OPER_SEQ", CWIPERPOPR.OPER_SEQ);
						TRS.add_string(inv_if, "OPER", CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
						//TRS.add_string(inv_if, "INV_OPER", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
						TRS.add_string(inv_if, "INV_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
						TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
						TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						TRS.add_double(inv_if, "QTY", d_beofore_qty);
						TRS.add_string(inv_if, "CMF_1", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");

						if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, inv_if, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}


						d_ifseq = TRS.get_double(cmn_out, "IF_SEQ");

						TRS.free_node(cmn_out);

						memset(c_if_seq, ' ', sizeof(c_if_seq));
						sprintf(c_if_seq, "%.0f", d_ifseq);

						//인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
						MINVLOTISS.CMF_1[0] = 'Y';
						memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
						DBU_update_minvlotiss(1, &MINVLOTISS);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "CMN-0004");
							TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
							TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

							return MP_FALSE;
						}

					}


				}
				else
				{
					/*
					//창고 이동하여 자재 FLAG로 되어있는지 체크한다.
					if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
					{
						//WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
						strcpy(s_msg_code, "WIP-0657");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}


					if (MWIPLOTSTSX.INV_FLAG != 'Y')
					{
						//WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
						strcpy(s_msg_code, "WIP-0657");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
					*/
					//if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
					//{
					//    //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
					//    strcpy(s_msg_code, "WIP-0648");
					//    TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
					//    TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
					//    TRS.add_dberrmsg(out_node, DB_error_msg);

					//    gs_log_type.type = MP_LOG_ERROR;
					//    gs_log_type.e_type = MP_LOG_E_SYSTEM;
					//    gs_log_type.category = MP_LOG_CATE_VIEW;

					//    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					//    return MP_FALSE;
					//}

					if (memcmp(MWIPLOTSTSX.ADD_ORDER_ID_1, "MIG", strlen("MIG")) == MP_FALSE)
					{
						if (MWIPLOTSTSX.FLOW[0] == ' ')
						{
							//LOT ADAPT 처리
							adapt_in = TRS.add_node(in_node, "apt_in");
							TRS.add_char(adapt_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(adapt_in, in_node);

							TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
							TRS.add_string(adapt_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
							TRS.add_string(adapt_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
							TRS.add_string(adapt_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
							TRS.add_string(adapt_in, "TO_MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
							TRS.add_int(adapt_in, "TO_MAT_VER", MWIPORDSTS.MAT_VER);
							TRS.add_string(adapt_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
							TRS.add_string(adapt_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
							TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
							TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
							TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
							TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
							//TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
							TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
							TRS.add_nstring(adapt_in, "TRAN_CMF_3", "ORDER_CHANGE");  // 자품목이 모품목으로 LOT이 동일하게 들어가는경우

							if (MWIPOPRDEF.OPER_CMF_14[0] != ' ')
							{
								TRS.add_double(adapt_in, "QTY_1", COM_atof(MWIPOPRDEF.OPER_CMF_14[0], sizeof(MWIPOPRDEF.OPER_CMF_14[0])));
							}
							else
							{
								TRS.add_double(adapt_in, "QTY_1", MWIPLOTSTSX.QTY_1);
							}

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);
						}
						else {
							//LOT ADAPT 처리
							adapt_in = TRS.add_node(in_node, "apt_in");
							TRS.add_char(adapt_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(adapt_in, in_node);

							TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
							TRS.add_string(adapt_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
							TRS.add_string(adapt_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
							TRS.add_string(adapt_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
							TRS.add_string(adapt_in, "TO_MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
							TRS.add_int(adapt_in, "TO_MAT_VER", MWIPORDSTS.MAT_VER);
							TRS.add_string(adapt_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
							TRS.add_string(adapt_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
							TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
							TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
							TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
							TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
							//TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
							TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
							TRS.add_nstring(adapt_in, "TRAN_CMF_3", "ORDER_CHANGE");  // 자품목이 모품목으로 LOT이 동일하게 들어가는경우


							if (MWIPOPRDEF.OPER_CMF_14[0] != ' ')
							{
								TRS.add_double(adapt_in, "QTY_1", COM_atof(MWIPOPRDEF.OPER_CMF_14[0], sizeof(MWIPOPRDEF.OPER_CMF_14[0])));
							}
							else
							{
								TRS.add_double(adapt_in, "QTY_1", MWIPLOTSTSX.QTY_1);
							}

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);
						}
					}
					else {
						//LOT ADAPT 처리
						adapt_in = TRS.add_node(in_node, "apt_in");
						TRS.add_char(adapt_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(adapt_in, in_node);

						TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
						TRS.add_string(adapt_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_string(adapt_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
						TRS.add_string(adapt_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
						TRS.add_string(adapt_in, "TO_MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
						TRS.add_int(adapt_in, "TO_MAT_VER", MWIPORDSTS.MAT_VER);
						TRS.add_string(adapt_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
						TRS.add_string(adapt_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
						TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
						TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
						TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
						TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
						//TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
						TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
						TRS.add_nstring(adapt_in, "TRAN_CMF_3", "ORDER_CHANGE");  // 자품목이 모품목으로 LOT이 동일하게 들어가는경우

						if (MWIPOPRDEF.OPER_CMF_14[0] != ' ')
						{
							TRS.add_double(adapt_in, "QTY_1", COM_atof(MWIPOPRDEF.OPER_CMF_14[0], sizeof(MWIPOPRDEF.OPER_CMF_14[0])));
						}
						else
						{
							TRS.add_double(adapt_in, "QTY_1", MWIPLOTSTSX.QTY_1);
						}


						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}

				}
			}

			//작업지시 공정, 외경가공 공정이 아닌경우
			else
			{
				//in_node 로 받은 공정과 lot의 공정을 비교한다. OPER_CMF_2가 'Y'인 공정을 제외하고는 
				//in_node 의 공정과 LOT의 공정이 같아야 한다.
				if (TRS.mem_cmp(in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
				{
					//WIP-0066 : LOT의 공정이 현재 공정과 일치 하지 않습니다. LOT을 확인 하세요.
					strcpy(s_msg_code, "WIP-0066");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//lot 작업시작
			start_in = TRS.add_node(in_node, "start_in");
			TRS.add_char(start_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(start_in, in_node);

			TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_nstring(start_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

			//GCM에 등록된 공정별 저장 데이터를 start node에 담아준다.
			//공정별 저장 데이터는 Client 실적 화면에서 저장하는 공정 정보 데이터.
			if (iCheckOperData > 0)
			{
				i_step = 2;

				/*gcm의 OPER_DATA 에 셋업된 정보를 가져온다.
				KEY_1 : 공정 코드
				KEY_2 : 공정에서 저장될 데이터의 번호
				DATA_1 : (LABEL_NAME) 클라이언트에서 label에 보일 명칭.
				DATA_2 : (COLUMN_NAME) 테이블에 저장될 컬럼 명.
				DATA_3 : (VISIBLE_BUTTON) 클라이언트에서 컨트롤에 콤보박스 버튼이 보이는지 여부.
				DATA_4 : (USE_GCM_TABLE) 사용되는 GCM table 명.
				DATA_5 : (READ_ONLY_YN) 컨트롤의 read only 여부.
				DATA_6 : (SAVE_YN) 저장여부.
				DATA_7 : (NECESSARY YN) 필수여부.
				DATA_8 : (POPUP YN) 팝업여부.
				*/
				DBU_init_mgcmtbldat(&MGCMTBLDAT_D);
				TRS.copy(MGCMTBLDAT_D.FACTORY, sizeof(MGCMTBLDAT_D.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_D.TABLE_NAME, MP_GCM_OPER_DATA, strlen(MP_GCM_OPER_DATA));
				memcpy(MGCMTBLDAT_D.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_open_mgcmtbldat(i_step, &MGCMTBLDAT_D);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_D.FACTORY), MGCMTBLDAT_D.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_D.TABLE_NAME), MGCMTBLDAT_D.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_D.KEY_1), MGCMTBLDAT_D.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				while (1)
				{
					DBU_fetch_mgcmtbldat(i_step, &MGCMTBLDAT_D);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_mgcmtbldat(i_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
						TRS.add_fieldmsg(out_node, "MGCMTBLDAT FETCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_D.FACTORY), MGCMTBLDAT_D.FACTORY);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_D.TABLE_NAME), MGCMTBLDAT_D.TABLE_NAME);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_D.KEY_1), MGCMTBLDAT_D.KEY_1);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_mgcmtbldat(i_step);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//client 에서 넘겨준 in_node의 member 중에 저장 컬럼에 해당되는 것이 있으면 start node에 담아준다. 
					for (int k = 0; k < in_node->MemberCount; k++)
					{
						if (memcmp(MGCMTBLDAT_D.DATA_2, in_node->Members[k]->Name, strlen(in_node->Members[k]->Name)) == MP_FALSE)
						{
							//DATA_6 (저장여부) 가 'Y'인 경우만 저장되도록 한다.
							if (MGCMTBLDAT_D.DATA_6[0] == 'Y')
							{
								//DATA_7 (필수여부) 가 'Y'인 경우 입력되어있는지 체크 
								if (MGCMTBLDAT_D.DATA_7[0] == 'Y')
								{
									if (COM_isnullspace(TRS.get_string(in_node, in_node->Members[k]->Name)) == MP_TRUE)
									{
										strcpy(s_msg_code, "WIP-0001");
										TRS.add_fieldmsg(out_node, "DATA_1", MP_STR, sizeof(MGCMTBLDAT_D.DATA_1), MGCMTBLDAT_D.DATA_1);
										TRS.add_fieldmsg(out_node, in_node->Members[k]->Name, MP_NVST);

										gs_log_type.type = MP_LOG_ERROR;
										gs_log_type.e_type = MP_LOG_E_VALIDATION;
										gs_log_type.category = MP_LOG_CATE_TRANS;

										return MP_FALSE;
									}
								}

								TRS.add_nstring(start_in, in_node->Members[k]->Name, in_node->Members[k]->Value.s);
							}
						}
					}
				}
			}

			//특정 설비 저장 공정 여부 공정옵션(DATA_8) 'Y' 공정인 경우작업 설비를 save 설비 필드에 저장 한다.
			if (MGCMTBLDAT.DATA_8[0] == 'Y')
			{
				TRS.add_nstring(start_in, "SAVE_RES_ID_1", TRS.get_string(in_node, "RES_ID"));
			}

			TRS.add_nstring(start_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
			{
				cmn_out = TRS.create_node("Cmn_Out");
				TRS.add_nstring(start_in, "TRAN_CODE", "START");
				if (Update_Res_Wip_Summary(s_msg_code, start_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);
			}

			//설비에 시작 정보를 보내는 경우(RES_CMF_1 = 'Y') 설비에 시작 정보를 보낸다.
			if (MRASRESDEF.RES_CMF_1[0] == 'Y')
			{
				if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
				{
					if (i == 0)
					{
						send_in = TRS.add_node(in_node, "send_in");
						CopyDefaultMembers(send_in, in_node);

						if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
						{
							//연구소의 테스트품인 경우 LOT_ID[0] == 'R' 인 경우 설비 start lot을 cell id 가 아닌 lot id 로 보낸다. _20210413_lwg
							if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_T && MWIPLOTSTSX.LOT_ID[0] == 'R')
							{
								TRS.add_char(send_in, IN_PROCSTEP, '1');
								TRS.add_string(send_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							}
							else
							{
								TRS.add_char(send_in, IN_PROCSTEP, '2');
								TRS.add_string(send_in, "LOT_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
							}
						}
						else
						{
							TRS.add_char(send_in, IN_PROCSTEP, '1');
							TRS.add_string(send_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						}

						TRS.add_nstring(send_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

						TRS.add_nstring(send_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
						TRS.add_nstring(send_in, "PROFILE", TRS.get_string(in_node, "LOT_CMF_4"));

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
				else
				{
					DBU_init_mgcmtbldat(&MGCMTBLDAT_RES);
					TRS.copy(MGCMTBLDAT_RES.FACTORY, sizeof(MGCMTBLDAT_RES.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_RES.TABLE_NAME, MP_GCM_TRANS_RES_INFO, strlen(MP_GCM_TRANS_RES_INFO));
					memcpy(MGCMTBLDAT_RES.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_RES);
					if (DB_error_code == DB_SUCCESS)
					{

					}
					else
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							send_in = TRS.add_node(in_node, "send_in");
							TRS.add_char(send_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(send_in, in_node);

							TRS.add_nstring(send_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
							TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));
							TRS.add_nstring(send_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

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
			}

			//LOT ID 정보를 재 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);


			//CTM 슬라이싱공정, A가 1로 들어가서  A.1, A.2  각각 1개씩 나와야됨.  ADAPT하면서 수량늘리고 분활도 시킴.
			if (MWIPOPRDEF.OPER_CMF_14[0] != ' ')
			{

				for (int i = 1; i <= MWIPLOTSTSX.QTY_1; i++)
				{

					char s_lot_seq[1] = "";

					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node);

					COM_itoa_left(s_lot_seq, i, sizeof(s_lot_seq));

					sprintf(s_lot_id, "%.*s%.*s%.*s", COM_len_space(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)), MWIPLOTSTSX.LOT_ID, COM_len_space(".", sizeof(".")), ".", COM_len_space(s_lot_seq, sizeof(s_lot_seq)), s_lot_seq);




					TRS.add_char(split_in, "PROCSTEP", '1');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
					TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
					TRS.add_double(split_in, "MOVE_QTY_1", 1);

					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량
					TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));


					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
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

			}

			//시작시 생성된 lot list를 out node에 보낸다.
			//Client 실적 화면에서 작업시작 후 시작처리한 LOT LIST를 다시 조회하여 보여주기 위해. 
			list_item = TRS.add_node(out_node, "LOT_TBL");
			TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
			TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));

			if (MWIPLOTSTSX.START_RES_ID[0] != ' ' && MRASRESDEF.RES_ID[0] != ' ')
			{
				TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
			}
		}
	}

	//step 1 : 작업완료
	else if (TRS.get_procstep(in_node) == '2')
	{
		//FROM AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
		TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
		i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

		for (int i = 0; i < i_lot_count; i++)
		{
			//개별 lot별로 작업지시를 조회한다.
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), Lot_tbl[i], "ORDER_ID");
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

			//완료 또는 삭제된 작업지시는 진행 할 수 없음
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_FINISH
				|| MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_DELETE)
			{
				//ORD-0024 : 선택한 Order는 이미 삭제되었습니다.
				strcpy(s_msg_code, "ORD-0024");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//c_CheckErpResult = ' ';
			//c_CheckErpInput = ' ';

			////ERP에 생산 이력 및 투입 이력 여부를 리턴 받아오는 함수
			//erpchk_in = TRS.add_node(in_node, "erpchk_in");
			//CopyDefaultMembers(erpchk_in, in_node);
			//TRS.add_nstring(erpchk_in, "OPER", TRS.get_string(in_node, "OPER"));
			//TRS.add_string(erpchk_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

			//if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, erpchk_in, out_node) == MP_FALSE)
			//    return MP_FALSE;

			//lot 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
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

			//lot 삭제여부 체크
			if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
			{
				//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (TRS.mem_cmp(Lot_tbl[i], "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
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

			//자재 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			//불량 수량이 존재 하지 않고, 실적 수량이 LOT 수량과 다른경우 CV처리를 해서 수량을 조정해 준다.
			if (COM_dbl_round(TRS.get_double(Lot_tbl[i], "GOOD_QTY_1") + TRS.get_double(Lot_tbl[i], "LOSS_QTY_1"), 5, 'U') != COM_dbl_round(MWIPLOTSTSX.QTY_1, 5, 'U'))
			{
				//OPER OPTION : DATA_5 CV허용 공정
				//CV허용 공정 및 첫공정 (CREATE 허용) 인경우 CV처리를 하여 수량을 조정 할 수 있다.
				if (memcmp(MGCMTBLDAT.DATA_1, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) == MP_FALSE || MGCMTBLDAT.DATA_5[0] == 'Y')
				{
					//불량코드가 없지만 완료 수량이 다르면 다른 수량 만큼 cv 처리를 한다.
					cv_in = TRS.add_node(in_node, "cv_in");
					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(cv_in, in_node);

					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(cv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
					TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

					if (COM_isnullspace(TRS.get_string(in_node, "COMMENT")) == MP_FALSE)
					{
						//TRS.add_nstring(cv_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
						TRS.add_nstring(cv_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT);
					}
					else
					{
						TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
					}
					// TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_double(cv_in, "QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
					TRS.add_char(cv_in, "IS_IN_OPER", 'Y');

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}
				else
				{
					//WIP-0634 : 이공정은 수량조정 가능 공정이 아닙니다.
					strcpy(s_msg_code, "WIP-0634");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//자재 차감
			inv_in = TRS.add_node(in_node, "inv_in");
			CopyDefaultMembers(inv_in, in_node);

			TRS.add_char(inv_in, IN_PROCSTEP, '1');
			TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_nstring(inv_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(inv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

			//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
			if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
			{
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
			}

			if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
				return MP_FALSE;

			//if (INPUT_INV_LOT(s_msg_code, inv_in, out_node) == MP_FALSE)
			//    return MP_FALSE;

			//LOT정보 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
			memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

			//press설비인 경우 cell_id 가 바뀌는 시점에 run수를 초기화해서 조회한다.
			if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
			{
				if (memcmp(s_cell_id, MWIPLOTSTSX.LOT_CMF_1, sizeof(s_cell_id)) != MP_FALSE)
				{
					memcpy(s_cell_id, MWIPLOTSTSX.LOT_CMF_1, sizeof(s_cell_id));
					iRunCount = 0;
				}
			}

			//그릿인 경우 불량 정보 등록된 것이 있으면 loss 처리를 해준다. 
			//로직 점검 필요.
			if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_grt, strlen(gs_area_grt)) == MP_FALSE)
			{
				DBU_init_cwiplotlst(&CWIPLOTLST);
				memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
				memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
				memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
				memcpy(CWIPLOTLST.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));

				//부외재고 코드 불량이 등록되어있을경우 lot을 split하여 split된 lot을 부외재고로 보내고 loss처리 한다. 
				DBU_select_cwiplotlst(2, &CWIPLOTLST);
				if (DB_error_code == DB_SUCCESS)
				{
					//쿼리에서 split될 lot id 를 가져온다.
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
					memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(split_in, "PROCSTEP", '1');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_double(split_in, "MOVE_QTY_1", CWIPLOTLST.LOSS_QTY);
					TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "LOSS_COMMENT"));
					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX_AF.QTY_1);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					//split된 lot을 조회한다. 
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

					//split 된 lot으로 불량 처리 한다. 
					loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
					CopyDefaultMembers(loss_in, in_node);
					TRS.add_char(loss_in, IN_PROCSTEP, '1');

					TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_string(loss_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.add_string(loss_in, "CAUSE_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

					if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
						TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
					else
						TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

					TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
					TRS.add_double(loss_in, "OUT_QTY_1", 0);
					TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
					unit_in = TRS.add_node(loss_in, "UNIT1");
					TRS.add_string(unit_in, "LOSS_CODE", CWIPLOTLST.LOSS_CODE, sizeof(CWIPLOTLST.LOSS_CODE));
					TRS.add_double(unit_in, "LOSS_QTY", CWIPLOTLST.LOSS_QTY);
					TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					//임시 loss 저장 테이블에서 지워준다.
					DBU_delete_cwiplotlst(1, &CWIPLOTLST);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPLOTLST DELETE(1) ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					//LOT정보 재조회
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
					memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);
				}
			}

			//불량 정보 등록된 것이 있으면 loss 처리를 해준다. 
			i_step = 2;

			DBU_init_cwiplotlst(&CWIPLOTLST);
			memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
			memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
			//start시의 hist_seq를 가져온다
			//CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
			memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));

			//불량정보 등록 여부 체크
			if ((int)DBU_select_cwiplotlst_scalar(4, &CWIPLOTLST) > 0)
			{
				loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
				CopyDefaultMembers(loss_in, in_node);
				TRS.add_char(loss_in, IN_PROCSTEP, '1');

				TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
				TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

				if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
					TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				else
					TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

				TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//cv이후 lot의 수량이 변결될 수 있어 MWIPLOTSTSX_AF의 수량으로 가져온다.
				TRS.add_double(loss_in, "OUT_QTY_1", MWIPLOTSTSX_AF.QTY_1 - DBU_select_cwiplotlst_scalar(3, &CWIPLOTLST));

				DBU_open_cwiplotlst(i_step, &CWIPLOTLST);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
					strcpy(s_msg_code, "WIP-0232");
					TRS.add_fieldmsg(out_node, "CWIPLOTLST OPEN(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cwiplotlst(i_step, &CWIPLOTLST);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cwiplotlst(i_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
						strcpy(s_msg_code, "WIP-0232");
						TRS.add_fieldmsg(out_node, "CWIPLOTLST FETCH(2)", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cwiplotlst(i_step);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					unit_in = TRS.add_node(loss_in, "UNIT1");
					TRS.add_string(unit_in, "LOSS_CODE", CWIPLOTLST.LOSS_CODE, sizeof(CWIPLOTLST.LOSS_CODE));
					TRS.add_double(unit_in, "LOSS_QTY", CWIPLOTLST.LOSS_QTY);
				}

				//open마지막의 CAUSE_OPER를 넣어준다.
				TRS.add_string(loss_in, "CAUSE_OPER", CWIPLOTLST.CUASE_OPER, sizeof(CWIPLOTLST.CUASE_OPER));
				TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
				TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				//불량등록 후 불량 임시 테이블은 비워준다.
				DBU_init_cwiplotlst(&CWIPLOTLST);
				memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
				memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
				//CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
				memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));

				DBU_delete_cwiplotlst(2, &CWIPLOTLST);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTLST DELETE(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}

				//LOT정보 재조회
				DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
				memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

				//PRESS 공정인 경우 CWIPPRSRUN테이블에 일별 PRESS 집계 테이블에 저장한다. 
				if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
				{
					if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
					{
						//if (MWIPLOTSTSX_AF.LOT_ID[0] != 'R')
						//{
							memset(s_lot_id, ' ', sizeof(s_lot_id));
							c_skip_yn = 'N';

							if (memcmp(MGCMTBLDAT.DATA_3, MP_ID_ROLE_WIP_PRESS_LOT_ID, strlen(MP_ID_ROLE_WIP_PRESS_LOT_ID)) == MP_FALSE)
							{
								DBU_init_cwipprsrun(&CWIPPRSRUN);
								TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
								memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
								DBU_select_cwipprsrun(2, &CWIPPRSRUN);
								if (DB_error_code == DB_SUCCESS)
								{
									c_skip_yn = 'Y';

									memcpy(s_lot_id, CWIPPRSRUN.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
									ptr1 = strchr(s_lot_id, '_');
									ptr1[1] = MWIPLOTSTSX.LOT_CMF_2[0];
								}
							}

							if (c_skip_yn == 'N')
							{

								gen_in_node = TRS.add_node(in_node, "gen_in_node");
								TRS.add_char(gen_in_node, "PROCSTEP", '2');
								CopyDefaultMembers(gen_in_node, in_node);

								//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
								//해당 공정의 start시 사용되는 id rule이 있는경우 여부 rule 필드에 있는 id룰을 사용한다.
								if (MGCMTBLDAT.DATA_6[0] != ' ')
									TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_6, sizeof(MGCMTBLDAT.DATA_6));
								else
									TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));

								TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
								TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
								TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
								TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
								TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
								TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
								TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
								TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

								argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
								TRS.add_string(argu_list_node, "ARGUMENT", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

								cmn_out = TRS.create_node("Cmn_Out");
								if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
								{
									TRS.clone(out_node, cmn_out);
									TRS.free_node(cmn_out);
									return MP_FALSE;
								}
								memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
								TRS.free_node(cmn_out);
								 
								// 테스트 작업지시인 경우 lot채번 후 첫글자를 변경한다. 
								// GCM AREA에 DATA_6에 변경할 첫 글자를 세팅함. 
								// GCM AREA에 DATA_7에 변경될 글자의 index번호를 세팅항.
								// CTM, HM에 한해서만 세팅함. 
								if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_T)
								{
									// GCM AREA에 DATA_6에 변경할 첫 글자가 있는지 여부를 확인한다. 
									if (MGCMTBLDAT_FROM.DATA_6[0] != ' ')
									{
										//변경될 글자의 index번호를 찾아 변경한다. 
										if (MGCMTBLDAT_FROM.DATA_7[0] != ' ')
										{
											//lot의 첫글자가 'R'인경우 연구소 lot이기 때문에 연구소 lot은 첫 글자가 R로 유지 한다.
											if (s_lot_id[0] != 'R')
											{

												if (MWIPLOTSTSX.LOT_ID[0] == 'R')
												{
													iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

													s_lot_id[iChage_Seq - 1] = 'R';
												}
												else 
												{
													iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

													s_lot_id[iChage_Seq - 1] = MGCMTBLDAT_FROM.DATA_6[0];
												} 

											}
										}
									}
								}
							}
						//}
						 
						DBU_init_cwipprsrun(&CWIPPRSRUN); 
						TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
						memcpy(CWIPPRSRUN.WORK_DATE, work_date.s_work_date, sizeof(CWIPPRSRUN.WORK_DATE));
						memcpy(CWIPPRSRUN.RES_ID, MRASRESDEF.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
						if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
						{
							//if (MWIPLOTSTSX.LOT_ID[0] == 'R')
							if (MWIPLOTSTSX.LOT_CMF_2[0] == ' ')
							{
								memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPPRSRUN.CELL_ID));
								CWIPPRSRUN.MAPPING_SEQ = 1;
							}
							else
							{
								if (MWIPLOTSTSX.LOT_CMF_1[0] == ' ')
								{
									memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPPRSRUN.CELL_ID));
								}
								else
								{
									memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
								}
								//memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
								CWIPPRSRUN.MAPPING_SEQ = atoi(MWIPLOTSTSX.LOT_CMF_2);
							}
						}
						else
						{
							memcpy(CWIPPRSRUN.CELL_ID, s_lot_id, sizeof(CWIPPRSRUN.CELL_ID));
							CWIPPRSRUN.MAPPING_SEQ = 1;
						}

						if (iRunCount == 0)
						{
							iRunCount = (int)DBU_select_cwipprsrun_scalar(2, &CWIPPRSRUN);
							memcpy(s_cell_id, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
						}

						CWIPPRSRUN.RUN_COUNT = iRunCount;

						if (MWIPLOTSTSX.LOT_ID[0] == 'R' && memcmp(MGCMTBLDAT.DATA_3, MP_ID_ROLE_WIP_PRESS_LOT_ID, strlen(MP_ID_ROLE_WIP_PRESS_LOT_ID)) != MP_FALSE)
						{
							memcpy(CWIPPRSRUN.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
						}
						else
						{
							memcpy(CWIPPRSRUN.LOT_ID, s_lot_id, sizeof(CWIPPRSRUN.LOT_ID));
						}

						CWIPPRSRUN.DAY_NIGHT = work_date.s_day_night[0];
						TRS.copy(CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR), in_node, "LOT_CMF_3");
						memcpy(CWIPPRSRUN.MAT_ID, MWIPLOTSTSX_AF.MAT_ID, sizeof(MWIPLOTSTSX_AF.MAT_ID));
						TRS.copy(CWIPPRSRUN.AREA_ID, sizeof(CWIPPRSRUN.AREA_ID), in_node, "AREA_ID");
						TRS.copy(CWIPPRSRUN.SUB_AREA_ID, sizeof(CWIPPRSRUN.SUB_AREA_ID), in_node, "SUB_AREA_ID");
						TRS.copy(CWIPPRSRUN.OPER, sizeof(CWIPPRSRUN.OPER), in_node, "OPER");
						CWIPPRSRUN.LOSS_YN = 'Y';
						memcpy(CWIPPRSRUN.TRAN_TIME, gs_sys_time, sizeof(CWIPPRSRUN.TRAN_TIME));

						memcpy(CWIPPRSRUN.ORG_LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
						CWIPPRSRUN.ORG_LOT_HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ;

						TRS.copy(CWIPPRSRUN.PROFILE_ID, sizeof(CWIPPRSRUN.PROFILE_ID), in_node, "LOT_CMF_4");

						//셀 중량
						if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_5")) == MP_FALSE)
							CWIPPRSRUN.CELL_WEIGHT = COM_atof(TRS.get_string(in_node, "LOT_CMF_5"), sizeof(TRS.get_string(in_node, "LOT_CMF_5")));
						else
							CWIPPRSRUN.CELL_WEIGHT = 0;

						//셀 높이
						if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_6")) == MP_FALSE)
							CWIPPRSRUN.CELL_HEIGHT = COM_atof(TRS.get_string(in_node, "LOT_CMF_6"), sizeof(TRS.get_string(in_node, "LOT_CMF_6")));
						else
							CWIPPRSRUN.CELL_HEIGHT = 0;

						//설정압력
						if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_1")) == MP_FALSE)
							CWIPPRSRUN.SET_VOLTAGE = COM_atof(TRS.get_string(in_node, "CTM_CMF_1"), sizeof(TRS.get_string(in_node, "CTM_CMF_1")));
						else
							CWIPPRSRUN.SET_VOLTAGE = 0;

						//설정Power1
						if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_2")) == MP_FALSE)
							CWIPPRSRUN.SET_POWER_1 = COM_atof(TRS.get_string(in_node, "CTM_CMF_2"), sizeof(TRS.get_string(in_node, "CTM_CMF_2")));
						else
							CWIPPRSRUN.SET_POWER_1 = 0;

						//설정Power2
						if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_3")) == MP_FALSE)
							CWIPPRSRUN.SET_POWER_2 = COM_atof(TRS.get_string(in_node, "CTM_CMF_3"), sizeof(TRS.get_string(in_node, "CTM_CMF_3")));
						else
							CWIPPRSRUN.SET_POWER_2 = 0;

						//설정Power3
						if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_4")) == MP_FALSE)
							CWIPPRSRUN.SET_POWER_3 = COM_atof(TRS.get_string(in_node, "CTM_CMF_4"), sizeof(TRS.get_string(in_node, "CTM_CMF_4")));
						else
							CWIPPRSRUN.SET_POWER_3 = 0;

						memcpy(CWIPPRSRUN.CREATE_TIME, gs_sys_time, sizeof(CWIPPRSRUN.CREATE_TIME));
						TRS.copy(CWIPPRSRUN.CREATE_USER_ID, sizeof(CWIPPRSRUN.CREATE_USER_ID), in_node, IN_USERID);

						DBU_insert_cwipprsrun(&CWIPPRSRUN);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPPRSRUN INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
							TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPPRSRUN.RES_ID), CWIPPRSRUN.RES_ID);
							TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPPRSRUN.LOT_ID), CWIPPRSRUN.LOT_ID);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPPRSRUN.OPER), CWIPPRSRUN.OPER);
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

			//설비 완공 정보는 END 이전에 보내줘야 한다. 
			if (MRASRESDEF.RES_CMF_1[0] == 'Y')
			{
				//볼밀 설비인 경우 lot완료시 설비 완료 처리를 보내준다.
				if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_BOLMIL, strlen(MP_RESS_GRP_BOLMIL)) == MP_FALSE)
				{
					send_in = TRS.add_node(in_node, "send_in");
					TRS.add_char(send_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(send_in, in_node);

					TRS.add_nstring(send_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
					TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_EIS_BALL_MILL_END_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
				else if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
				{
					if (MRASRESDEF.RES_CMF_6[0] == 'Y')
					{
						if (i == 0)
						{
							send_in = TRS.add_node(in_node, "send_in");
							TRS.add_char(send_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(send_in, in_node);

							TRS.add_nstring(send_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

							if (MWIPLOTSTSX.LOT_CMF_1[0] != ' ')
								TRS.add_string(send_in, "LOT_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
							else
								TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_EIS_SEND_PRESS_END_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);
						}
					}
				}
			}

			//Loss 이후 QTY가 작업자만 저장한다.
			if (MWIPLOTSTSX_AF.QTY_1 <= 0)
			{
				//작업자 저장
				Worker_tbl = TRS.get_list(in_node, "WORKER_TBL");
				i_worker_count = TRS.get_item_count(in_node, "WORKER_TBL");

				for (int k = 0; k < i_worker_count; k++)
				{
					DBU_init_cwipoprwrk(&CWIPOPRWRK);
					TRS.copy(CWIPOPRWRK.FACTORY, sizeof(CWIPOPRWRK.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CWIPOPRWRK.OPER, sizeof(CWIPOPRWRK.OPER), in_node, "OPER");
					memcpy(CWIPOPRWRK.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					CWIPOPRWRK.HIST_SEQ = MWIPLOTSTSX_AF.LAST_HIST_SEQ;
					TRS.copy(CWIPOPRWRK.WORKER_ID, sizeof(CWIPOPRWRK.OPER), Worker_tbl[k], "WORKER_ID");

					memcpy(CWIPOPRWRK.START_TIME, MWIPLOTSTSX.START_TIME, sizeof(CWIPOPRWRK.START_TIME));
					memcpy(CWIPOPRWRK.END_TIME, MWIPLOTSTSX_AF.END_TIME, sizeof(CWIPOPRWRK.END_TIME));
					memcpy(CWIPOPRWRK.CREATE_TIME, gs_sys_time, sizeof(CWIPOPRWRK.CREATE_TIME));
					TRS.copy(CWIPOPRWRK.CREATE_USER_ID, sizeof(CWIPOPRWRK.CREATE_USER_ID), in_node, IN_USERID);

					DBU_insert_cwipoprwrk(&CWIPOPRWRK);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPOPRWRK INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPOPRWRK.FACTORY), CWIPOPRWRK.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPOPRWRK.OPER), CWIPOPRWRK.OPER);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPOPRWRK.LOT_ID), CWIPOPRWRK.LOT_ID);
						TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPOPRWRK.WORKER_ID), CWIPOPRWRK.WORKER_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}

				// 설비 효율용 집계 호출
				if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
				{
					TRS.set_nstring(in_node, "TRAN_CODE", "LOSS");
					if (Call_Resource_Efficiency(s_msg_code, i, &MWIPLOTSTSX, &MWIPLOTSTSX_AF, &work_date, in_node, out_node) == MP_FALSE)
						return MP_FALSE;
				}

				// Lot Summary의 END_DATE, END_TIME, END_DAY_NIGTH 보정
				//if (Adjust_Lot_Summary(s_msg_code, MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ, TRS.get_double(Lot_tbl[i], "GOOD_QTY_1"), TRS.get_double(Lot_tbl[i], "LOSS_QTY_1"), &work_date, in_node, out_node) == MP_FALSE)
				//    return MP_FALSE;

				continue;
			}

			//QTY가 0보다 큰 경우만 END가 되도록 한다.
			//LOT 완료
			end_in = TRS.add_node(in_node, "end_in");
			TRS.add_char(end_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(end_in, in_node);

			TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_string(end_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

			if (iCheckOperData > 0)
			{
				i_step = 2;

				DBU_init_mgcmtbldat(&MGCMTBLDAT_D);
				TRS.copy(MGCMTBLDAT_D.FACTORY, sizeof(MGCMTBLDAT_D.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_D.TABLE_NAME, MP_GCM_OPER_DATA, strlen(MP_GCM_OPER_DATA));
				memcpy(MGCMTBLDAT_D.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_open_mgcmtbldat(i_step, &MGCMTBLDAT_D);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_D.FACTORY), MGCMTBLDAT_D.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_D.TABLE_NAME), MGCMTBLDAT_D.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_D.KEY_1), MGCMTBLDAT_D.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				while (1)
				{
					DBU_fetch_mgcmtbldat(i_step, &MGCMTBLDAT_D);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_mgcmtbldat(i_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
						TRS.add_fieldmsg(out_node, "MGCMTBLDAT FETCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_D.FACTORY), MGCMTBLDAT_D.FACTORY);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_D.TABLE_NAME), MGCMTBLDAT_D.TABLE_NAME);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_D.KEY_1), MGCMTBLDAT_D.KEY_1);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_mgcmtbldat(i_step);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					for (int k = 0; k < in_node->MemberCount; k++)
					{
						if (memcmp(MGCMTBLDAT_D.DATA_2, in_node->Members[k]->Name, strlen(in_node->Members[k]->Name)) == MP_FALSE)
						{
							//DATA_6 (저장여부) 가 'Y'인 경우만 저장되도록 한다.
							if (MGCMTBLDAT_D.DATA_6[0] == 'Y')
							{
								//DATA_7 (필수여부) 가 'Y'인 경우 입력되어있는지 체크 
								if (MGCMTBLDAT_D.DATA_7[0] == 'Y')
								{
									if (COM_isnullspace(TRS.get_string(in_node, in_node->Members[k]->Name)) == MP_TRUE)
									{
										strcpy(s_msg_code, "WIP-0001");
										TRS.add_fieldmsg(out_node, "DATA_1", MP_STR, sizeof(MGCMTBLDAT_D.DATA_1), MGCMTBLDAT_D.DATA_1);
										TRS.add_fieldmsg(out_node, in_node->Members[k]->Name, MP_NVST);

										gs_log_type.type = MP_LOG_ERROR;
										gs_log_type.e_type = MP_LOG_E_VALIDATION;
										gs_log_type.category = MP_LOG_CATE_TRANS;

										return MP_FALSE;
									}
								}

								TRS.add_nstring(end_in, in_node->Members[k]->Name, in_node->Members[k]->Value.s);
							}
						}
					}
				}
			}

			TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

			//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
			if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
			{
				TRS.add_string(end_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_nstring(end_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
			}

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//LOT정보 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
			memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

			//공정옵션이 있는 공인인 경우.
			if (iCheckOperOption == MP_TRUE)
			{
				//공정 옵션이 split인 경우 lot을 split 하여 각각 나눈다. 
				if (memcmp(MGCMTBLDAT.DATA_2, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
				{
					//SPLIT공정이면서 맵핑그룹 설정되어 있는 공정인 경우 LOT을 SPLIT 하면서 SPLIT된 LOT들을 그룹ID에 묶어준다.
					//수동 컵계량 공정인 경우 해당 옵션을 사용한다.
					if (MGCMTBLDAT.DATA_4[0] != ' ')
					{
						memset(s_group_id, ' ', sizeof(s_group_id));

						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);

						//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
						TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

						argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
						TRS.add_string(argu_list_node, "ARGUMENT", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						memcpy(s_group_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
						TRS.free_node(cmn_out);

						DBU_init_cwipgrpsts(&CWIPGRPSTS);
						TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
						memcpy(CWIPGRPSTS.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS.GROUP_ID));
						memcpy(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_CUP, strlen(MP_MAPPING_GROUP_CUP));
						TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "RES_ID");
						TRS.copy(CWIPGRPSTS.CREATE_USER_ID, sizeof(CWIPGRPSTS.CREATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPSTS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.CREATE_TIME));
						TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
						memcpy(CWIPGRPSTS.CMF_1, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						DBU_insert_cwipgrpsts(&CWIPGRPSTS);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
							TRS.add_fieldmsg(out_node, "GROUP_TYPE", MP_STR, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);

							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}

						TRS.add_string(out_node, "GROUP_ID", CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID));
					}

					i_Qty = (int)MWIPLOTSTSX.QTY_1;
					d_splitQty = atoi(MGCMTBLDAT.DATA_7);

					for (int k = 0; k < i_Qty; k++)
					{
						memset(s_lot_id, ' ', sizeof(s_lot_id));
						c_skip_yn = 'N';

						if (memcmp(MGCMTBLDAT.DATA_3, MP_ID_ROLE_WIP_PRESS_LOT_ID, strlen(MP_ID_ROLE_WIP_PRESS_LOT_ID)) == MP_FALSE)
						{
							DBU_init_cwipprsrun(&CWIPPRSRUN);
							TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
							memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
							DBU_select_cwipprsrun(2, &CWIPPRSRUN);
							if (DB_error_code == DB_SUCCESS)
							{
								c_skip_yn = 'Y';

								memcpy(s_lot_id, CWIPPRSRUN.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
								ptr1 = strchr(s_lot_id, '_');
								ptr1[1] = MWIPLOTSTSX.LOT_CMF_2[0];
							}
						}

						if (c_skip_yn == 'N')
						{
							gen_in_node = TRS.add_node(in_node, "gen_in_node");
							TRS.add_char(gen_in_node, "PROCSTEP", '2');
							CopyDefaultMembers(gen_in_node, in_node);

							//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
							//해당 공정의 start시 사용되는 id rule이 있는경우 여부 rule 필드에 있는 id룰을 사용한다.
							if (MGCMTBLDAT.DATA_6[0] != ' ')
								TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_6, sizeof(MGCMTBLDAT.DATA_6));
							else
								TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));

							TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
							TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
							TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
							TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
							TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
							TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
							TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

							argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
							TRS.add_string(argu_list_node, "ARGUMENT", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
							TRS.free_node(cmn_out);

							// 테스트 작업지시인 경우 lot채번 후 첫글자를 변경한다. 
							// GCM AREA에 DATA_6에 변경할 첫 글자를 세팅함. 
							// GCM AREA에 DATA_7에 변경될 글자의 index번호를 세팅항.
							// CTM, HM에 한해서만 세팅함. 
							if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_T)
							{
								// GCM AREA에 DATA_6에 변경할 첫 글자가 있는지 여부를 확인한다. 
								if (MGCMTBLDAT_FROM.DATA_6[0] != ' ')
								{
									//변경될 글자의 index번호를 찾아 변경한다. 
									if (MGCMTBLDAT_FROM.DATA_7[0] != ' ')
									{
										//lot의 첫글자가 'R'인경우 연구소 lot이기 때문에 연구소 lot은 첫 글자가 R로 유지 한다.
										if (s_lot_id[0] != 'R')
										{
											iChage_Seq = COM_atoi(MGCMTBLDAT_FROM.DATA_7, sizeof(MGCMTBLDAT_FROM.DATA_7));

											s_lot_id[iChage_Seq - 1] = MGCMTBLDAT_FROM.DATA_6[0];
										}

	


									}



								}
							}
						}

						// 2) 자LOT SPLIT
						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '1');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
						TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
						TRS.add_double(split_in, "MOVE_QTY_1", d_splitQty); // QTY_1 유효중량
						TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1 - (k * d_splitQty));   //split 전 모랏의 총 수량

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);


						//split lot 조회
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

						if (s_group_id[0] != ' ')
						{
							//lot 별 그룹번호 저장
							DBU_init_cwipgrplot(&CWIPGRPLOT);
							memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
							memcpy(CWIPGRPLOT.GROUP_ID, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID));
							memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
							CWIPGRPLOT.MAPPING_SEQ = k + 1;
							memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
							memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
							memcpy(CWIPGRPLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
							TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
							memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));
							TRS.copy(CWIPGRPLOT.UPDATE_USER_ID, sizeof(CWIPGRPLOT.UPDATE_USER_ID), in_node, IN_USERID);
							memcpy(CWIPGRPLOT.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.UPDATE_TIME));
							DBU_insert_cwipgrplot(&CWIPGRPLOT);
							if (DB_error_code != DB_SUCCESS)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "CWIPGRPLOT INSERT", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
								TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

								TRS.add_dberrmsg(out_node, DB_error_msg);

								return MP_FALSE;
							}

							//LOT ID에 그룹 번호 저장
							memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_1, s_group_id, sizeof(s_group_id));
							COM_itoa_left(MWIPLOTSTSX_SPLIT.LOT_CMF_2, k + 1, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_2));
							DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
							if (DB_error_code != DB_SUCCESS)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.FACTORY), MWIPLOTSTSX_SPLIT.FACTORY);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);

								TRS.add_dberrmsg(out_node, DB_error_msg);

								return MP_FALSE;
							}
						}
					}
				}
				//공정 옵션이 맵핑그룹 설정 이 Y인 경우 그룹번호를 만들어 준다.
				else if (MGCMTBLDAT.DATA_4[0] != ' ')
				{
					//첫번째 lot일 경우 mapping 마스터 번호를 생성한다. 
					if (i == 0)
					{
						memset(s_group_id, ' ', sizeof(s_group_id));

						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);

						//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
						TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
						//TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "GROUP_TYPE"));
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

						argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
						TRS.add_string(argu_list_node, "ARGUMENT", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						memcpy(s_group_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
						TRS.free_node(cmn_out);

						DBU_init_cwipgrpsts(&CWIPGRPSTS);
						TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
						memcpy(CWIPGRPSTS.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS.GROUP_ID));
						memcpy(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_ISP, strlen(MP_MAPPING_GROUP_ISP));
						TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "RES_ID");
						TRS.copy(CWIPGRPSTS.CREATE_USER_ID, sizeof(CWIPGRPSTS.CREATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPSTS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.CREATE_TIME));
						TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
						memcpy(CWIPGRPSTS.CMF_1, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						DBU_insert_cwipgrpsts(&CWIPGRPSTS);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
							TRS.add_fieldmsg(out_node, "GROUP_TYPE", MP_STR, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);

							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					//lot 별 그룹번호 저장
					DBU_init_cwipgrplot(&CWIPGRPLOT);
					memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
					memcpy(CWIPGRPLOT.GROUP_ID, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID));
					memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
					CWIPGRPLOT.MAPPING_SEQ = i + 1;
					memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
					memcpy(CWIPGRPLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));
					TRS.copy(CWIPGRPLOT.UPDATE_USER_ID, sizeof(CWIPGRPLOT.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPGRPLOT.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.UPDATE_TIME));
					DBU_insert_cwipgrplot(&CWIPGRPLOT);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPLOT INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					//MWIPLOTSTSX에 맵핑 순서 저장.
					memcpy(MWIPLOTSTSX_AF.LOT_CMF_1, CWIPGRPLOT.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID));
					COM_itoa_left(MWIPLOTSTSX_AF.LOT_CMF_2, CWIPGRPLOT.MAPPING_SEQ, sizeof(MWIPLOTSTSX_AF.LOT_CMF_2));
					DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_AF);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_AF.FACTORY), MWIPLOTSTSX_AF.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_AF.LOT_ID), MWIPLOTSTSX_AF.LOT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					//lot history 테이블에도 그룹id를 맵핑시켜 준다. 
					// => history 업데이트 이유는 end 이후에 업데이트 이므로 history 까지 맞춰준다.
					DBU_init_mwiplothisx(&MWIPLOTHISX);
					memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
					MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ;
					DBU_select_mwiplothisx(1, &MWIPLOTHISX);

					memcpy(MWIPLOTHISX.LOT_CMF_1, CWIPGRPLOT.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID));
					COM_itoa_left(MWIPLOTHISX.LOT_CMF_2, CWIPGRPLOT.MAPPING_SEQ, sizeof(MWIPLOTHISX.LOT_CMF_2));
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
			}

			//PRESS 공정인 경우 CWIPPRSRUN테이블에 일별 PRESS 집계 테이블에 저장한다. 
			if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
			{
				DBU_init_cwipprsrun(&CWIPPRSRUN);
				TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPPRSRUN.WORK_DATE, work_date.s_work_date, sizeof(CWIPPRSRUN.WORK_DATE));
				memcpy(CWIPPRSRUN.RES_ID, MRASRESDEF.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
				if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
				{
					if (MWIPLOTSTSX.LOT_ID[0] == 'R')
					{
						memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPPRSRUN.CELL_ID));
						memcpy(CWIPPRSRUN.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
						CWIPPRSRUN.MAPPING_SEQ = 1;
					}
					else
					{
						memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX_SPLIT.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
						memcpy(CWIPPRSRUN.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
						CWIPPRSRUN.MAPPING_SEQ = atoi(MWIPLOTSTSX_SPLIT.LOT_CMF_2);
					}
				}
				else
				{
					memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(CWIPPRSRUN.CELL_ID));
					memcpy(CWIPPRSRUN.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
					CWIPPRSRUN.MAPPING_SEQ = 1;
				}

				if (iRunCount == 0)
				{
					iRunCount = (int)DBU_select_cwipprsrun_scalar(2, &CWIPPRSRUN);
				}

				CWIPPRSRUN.RUN_COUNT = iRunCount;
				CWIPPRSRUN.DAY_NIGHT = work_date.s_day_night[0];
				TRS.copy(CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR), in_node, "LOT_CMF_3");
				memcpy(CWIPPRSRUN.MAT_ID, MWIPLOTSTSX_AF.MAT_ID, sizeof(MWIPLOTSTSX_AF.MAT_ID));
				TRS.copy(CWIPPRSRUN.AREA_ID, sizeof(CWIPPRSRUN.AREA_ID), in_node, "AREA_ID");
				TRS.copy(CWIPPRSRUN.SUB_AREA_ID, sizeof(CWIPPRSRUN.SUB_AREA_ID), in_node, "SUB_AREA_ID");
				TRS.copy(CWIPPRSRUN.OPER, sizeof(CWIPPRSRUN.OPER), in_node, "OPER");
				CWIPPRSRUN.LOSS_YN = 'N';
				memcpy(CWIPPRSRUN.TRAN_TIME, gs_sys_time, sizeof(CWIPPRSRUN.TRAN_TIME));

				memcpy(CWIPPRSRUN.ORG_LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
				CWIPPRSRUN.ORG_LOT_HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ;

				TRS.copy(CWIPPRSRUN.PROFILE_ID, sizeof(CWIPPRSRUN.PROFILE_ID), in_node, "LOT_CMF_4");

				//셀 중량
				if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_5")) == MP_FALSE)
					CWIPPRSRUN.CELL_WEIGHT = COM_atof(TRS.get_string(in_node, "LOT_CMF_5"), sizeof(TRS.get_string(in_node, "LOT_CMF_5")));
				else
					CWIPPRSRUN.CELL_WEIGHT = 0;

				//셀 높이
				if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_6")) == MP_FALSE)
					CWIPPRSRUN.CELL_HEIGHT = COM_atof(TRS.get_string(in_node, "LOT_CMF_6"), sizeof(TRS.get_string(in_node, "LOT_CMF_6")));
				else
					CWIPPRSRUN.CELL_HEIGHT = 0;

				//설정압력
				if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_1")) == MP_FALSE)
					CWIPPRSRUN.SET_VOLTAGE = COM_atof(TRS.get_string(in_node, "CTM_CMF_1"), sizeof(TRS.get_string(in_node, "CTM_CMF_1")));
				else
					CWIPPRSRUN.SET_VOLTAGE = 0;

				//설정Power1
				if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_2")) == MP_FALSE)
					CWIPPRSRUN.SET_POWER_1 = COM_atof(TRS.get_string(in_node, "CTM_CMF_2"), sizeof(TRS.get_string(in_node, "CTM_CMF_2")));
				else
					CWIPPRSRUN.SET_POWER_1 = 0;

				//설정Power2
				if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_3")) == MP_FALSE)
					CWIPPRSRUN.SET_POWER_2 = COM_atof(TRS.get_string(in_node, "CTM_CMF_3"), sizeof(TRS.get_string(in_node, "CTM_CMF_3")));
				else
					CWIPPRSRUN.SET_POWER_2 = 0;

				//설정Power3
				if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_4")) == MP_FALSE)
					CWIPPRSRUN.SET_POWER_3 = COM_atof(TRS.get_string(in_node, "CTM_CMF_4"), sizeof(TRS.get_string(in_node, "CTM_CMF_4")));
				else
					CWIPPRSRUN.SET_POWER_3 = 0;

				memcpy(CWIPPRSRUN.CREATE_TIME, gs_sys_time, sizeof(CWIPPRSRUN.CREATE_TIME));
				TRS.copy(CWIPPRSRUN.CREATE_USER_ID, sizeof(CWIPPRSRUN.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cwipprsrun(&CWIPPRSRUN);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRSRUN INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPPRSRUN.RES_ID), CWIPPRSRUN.RES_ID);
					TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPPRSRUN.LOT_ID), CWIPPRSRUN.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPPRSRUN.OPER), CWIPPRSRUN.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//PRESS 설비에서 받은 정보는 시작 LOT으로 설비 인터페이스 데이터를 받아 LOT이 완료시 PRESS로 채번된 LOT ID를 저장해준다.
				DBU_init_cwiplotprs(&CWIPLOTPRS);
				memcpy(CWIPLOTPRS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTPRS.FACTORY));
				memcpy(CWIPLOTPRS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTPRS.LOT_ID));
				if (DBU_select_cwiplotprs_scalar(2, &CWIPLOTPRS) > 0)
				{
					//CWIPLOTPRS.CMF_1
					if (memcmp(MGCMTBLDAT.DATA_2, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
					{
						memcpy(CWIPLOTPRS.CMF_1, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					}
					else
					{
						memcpy(CWIPLOTPRS.CMF_1, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					}

					TRS.copy(CWIPLOTPRS.UPDATE_USER_ID, sizeof(CWIPLOTPRS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTPRS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTPRS.UPDATE_TIME));
					DBU_update_cwiplotprs(3, &CWIPLOTPRS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTPRS UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTPRS.FACTORY), CWIPLOTPRS.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}

			}

			//작업자 저장
			Worker_tbl = TRS.get_list(in_node, "WORKER_TBL");
			i_worker_count = TRS.get_item_count(in_node, "WORKER_TBL");

			for (int k = 0; k < i_worker_count; k++)
			{
				DBU_init_cwipoprwrk(&CWIPOPRWRK);
				TRS.copy(CWIPOPRWRK.FACTORY, sizeof(CWIPOPRWRK.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPOPRWRK.OPER, sizeof(CWIPOPRWRK.OPER), in_node, "OPER");
				memcpy(CWIPOPRWRK.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				CWIPOPRWRK.HIST_SEQ = MWIPLOTSTSX_AF.LAST_HIST_SEQ;
				TRS.copy(CWIPOPRWRK.WORKER_ID, sizeof(CWIPOPRWRK.OPER), Worker_tbl[k], "WORKER_ID");
				memcpy(CWIPOPRWRK.START_TIME, MWIPLOTSTSX.START_TIME, sizeof(CWIPOPRWRK.START_TIME));
				memcpy(CWIPOPRWRK.END_TIME, MWIPLOTSTSX_AF.END_TIME, sizeof(CWIPOPRWRK.END_TIME));
				memcpy(CWIPOPRWRK.CREATE_TIME, gs_sys_time, sizeof(CWIPOPRWRK.CREATE_TIME));
				TRS.copy(CWIPOPRWRK.CREATE_USER_ID, sizeof(CWIPOPRWRK.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cwipoprwrk(&CWIPOPRWRK);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPOPRWRK INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPOPRWRK.FACTORY), CWIPOPRWRK.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPOPRWRK.OPER), CWIPOPRWRK.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPOPRWRK.LOT_ID), CWIPOPRWRK.LOT_ID);
					TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPOPRWRK.WORKER_ID), CWIPOPRWRK.WORKER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}

			// 설비 효율용 집계
			if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
			{
				TRS.set_nstring(in_node, "TRAN_CODE", "END");
				if (Call_Resource_Efficiency(s_msg_code, i, &MWIPLOTSTSX, &MWIPLOTSTSX_AF, &work_date, in_node, out_node) == MP_FALSE)
					return MP_FALSE;
			}

			//테스트 작업지시에서 특정 공정의 특정 MAT ID 인 경우 작업이 끝나고 저정로 LOT을 TERMINATE 한다. (안상현 K 요청. )
			//GCM - C_OPER_AUTO_DEL_MAT에 셋업 
			if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_T)
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT_DEL);
				TRS.copy(MGCMTBLDAT_DEL.FACTORY, sizeof(MGCMTBLDAT_DEL.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_DEL.TABLE_NAME, "C_OPER_AUTO_DEL_MAT", strlen("C_OPER_AUTO_DEL_MAT"));
				memcpy(MGCMTBLDAT_DEL.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				memcpy(MGCMTBLDAT_DEL.KEY_2, MWIPLOTSTSX_AF.MAT_ID, sizeof(MWIPLOTSTSX_AF.MAT_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_DEL);
				if (DB_error_code == DB_SUCCESS)
				{
					//CWIPLOTPRS.CMF_1
					if (memcmp(MGCMTBLDAT.DATA_2, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
					{
						DBU_init_cwiplottrc(&CWIPLOTTRC);
						memcpy(CWIPLOTTRC.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
						memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX_AF.OPER, sizeof(CWIPLOTTRC.OPER));
						memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
						DBU_open_cwiplottrc(3, &CWIPLOTTRC);
						if (DB_error_code != DB_SUCCESS)
						{
							//WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
							strcpy(s_msg_code, "WIP-0583");
							TRS.add_fieldmsg(out_node, "CWIPLOTTRC OPEN", MP_NVST);
							TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTTRC.OPER), CWIPLOTTRC.OPER);
							TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
						while (1)
						{
							DBU_fetch_cwiplottrc(3, &CWIPLOTTRC);
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_close_cwiplottrc(3);
								break;
							}
							else if (DB_error_code != DB_SUCCESS)
							{
								//WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
								strcpy(s_msg_code, "WIP-0583");
								TRS.add_fieldmsg(out_node, "CWIPLOTTRC OPEN", MP_NVST);
								TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
								TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTTRC.OPER), CWIPLOTTRC.OPER);
								TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								DBU_close_cwiplottrc(3);
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							terminate_in = TRS.add_node(in_node, "teminate_in");
							TRS.add_char(terminate_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(terminate_in, in_node);

							TRS.add_string(terminate_in, "LOT_ID", CWIPLOTTRC.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
							TRS.add_string(terminate_in, "COMMENT", MP_CINV_TRAN_CODE_TERMINATE, strlen(MP_CINV_TRAN_CODE_TERMINATE));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
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
						terminate_in = TRS.add_node(in_node, "teminate_in");
						TRS.add_char(terminate_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(terminate_in, in_node);

						TRS.add_string(terminate_in, "LOT_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
						TRS.add_string(terminate_in, "COMMENT", MP_CINV_TRAN_CODE_TERMINATE, strlen(MP_CINV_TRAN_CODE_TERMINATE));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}
				}
			}
		}
	}

	if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
	{
		res_in = TRS.add_node(in_node, "res_in_node");
		TRS.add_char(res_in, "PROCSTEP", '1');
		CopyDefaultMembers(res_in, in_node);

		TRS.add_nstring(res_in, "CAR", TRS.get_string(in_node, "LOT_CMF_3"));

		// 설비 상태를 자동으로 변경 해준다.
		if (TRS.get_procstep(in_node) == '1')
		{
			//start시 비가동이 완료가 되어있지 않은 경우 start시 비가동을 완료 시켜준다.
			if (Update_Resource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'R', res_in, out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}
		}
		else if (TRS.get_procstep(in_node) == '2')
		{
			//end시에는 설비에 tool이 작착된 경우 사용횟수를 올려준다. => 로직 추가 예정
			if (Update_Resource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'I', res_in, out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}
		}
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_WIP_Multi_Process_Lot_Validation()
		- Validation Check sub function of "CUS_WIP_MULTI_PROCESS_LOT" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Multi_Process_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP VALIDATION
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
	{
		return MP_FALSE;
	}

	// FACTORY VALIDATION
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
