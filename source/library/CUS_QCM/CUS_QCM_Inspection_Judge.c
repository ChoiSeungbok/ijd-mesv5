/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Inspection_Judge.c
Description : Tran Inspection Judge function

MES Version : 5.0

Function List
-

Detail Description
- 판정시 호출하는 서비스
- 판정에 대한 주요 기준정보는 GCM Table : C_INSP_JUDGE  에 있다.
- C_INSP_JUDGE 에는 공정별로  판정코드와 추가정보가 셋업되어있음

- DATA_3(이동 Flag) 이 Y인 경우  DATA_4(Flow) , DATA_5(Oper) 에 설정된  곳으로  END 트랜잭션 발생
- DATA_6(선 Loss처리) 는 판정시에 Loss가 있을 때 Loss 트랜잭션을 일으킬지 여부.
- DATA_7(Main 실 Loss적용) 은 판정시 Main Flag가 'Y'인 Loss만 실제 Loss 트랜잭셕을 일으킬지 여부 ( 품질은 Loss코드별로 Main 여부 플래그가 존재)
- DATA_8(Loss시 기타출고) 은 Loss처리시 Loss서비스에 ETC_OUT_YN 값을 넣어준다. ( 내부에서는 기타출고로 처리)
- DATA_9(불량필수입력)은 판정시 판정코드에 대하여 Loss코드가 최소 1개이상 입력되어야하는 Validation 체크를 위한 Flag값

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/07  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "CUS_INV_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Inspection_Judge_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);


/*******************************************************************************
CUS_QCM_Inspection_Judge()
- Tran start Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Inspection_Judge(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_INSPECTION_JUDGE(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_Inspection_Judge", out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

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
CUS_QCM_INSPECTION_JUDGE()
- Main sub function of "CUS_WIP_Inspection_Judge" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_INSPECTION_JUDGE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS_SPL;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS_ORG;

	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPLOS_TAG CQCMISPLOS;

	struct CQCMISPDAT_TAG CQCMISPDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct CWIPLOTREC_TAG CWIPLOTREC;

	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_ORG;
	struct MWIPMATDEF_TAG MWIPMATDEF;

	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;

	struct work_date_tag work_date;

	char s_judge_flag;
	char c_lot_type;
	char s_split_lot_id[26];
	char s_factory[10];

	char s_auto_move_yn; //설정된 Flow, Oper로 이동
	char s_loss_tran_yn; // Loss처리 여부 ( 실제 Loss 트랜잭션 발생 여부)
	char s_only_main_loss_tran_yn;  // Loss처리시에 Main Flag = 'Y' 인것만 Loss트랜잭션 발생할지 여부 ( Y가 아니면 Flag 상관없이 모두 불량)
	char s_etc_out_by_loss; // Loss를 기타출고로 처리할지 여부
	char s_loss_check_yn;  // Loss 필수 체크 여부 ( 판정시 Loss 코드가 반드시 존재해야되는지 여부) 

	//int i_loss_max_seq = 0;
	//int i_loss_cnt = 0;
	int i_pdc_loss_sum_cnt = 0;
	int i_pdc_rework_cnt = 0;
	int i_worker_count = 0;
	int i_splite_count = 0;
	double d_loss_qty = 0;



	TRSNode* loss_in_node;
	TRSNode* unit_in;
	TRSNode* gen_in_node;
	TRSNode* argu_list_node;
	TRSNode* split_in;
	TRSNode* skip_in;
	TRSNode* cmn_out;
	TRSNode* end_in;
	TRSNode* inv_in;
	TRSNode* cv_in;
	TRSNode* loss_in;
	TRSNode** splite_tbl;
	//TRSNode *change_cmf_in;




	LOG_head("CUS_QCM_Inspection_Judge");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_factory, ' ', sizeof(s_factory));
	memset(s_split_lot_id, ' ', sizeof(s_split_lot_id));

	memset(&work_date, ' ', sizeof(work_date));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	Get_shift(s_factory, &work_date);

	/* Validation Check */
	if (CUS_QCM_Inspection_Judge_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//검사ID Vaildation
	DBU_init_cqcmispsts(&CQCMISPSTS);
	TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
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
		return MP_FALSE;
	}

	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
	DBU_select_mwipoprdef(1, &MWIPOPRDEF);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	if (COM_isspace(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID)) == MP_TRUE)
	{
		strcpy(s_msg_code, "QCM-0064");
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
		return MP_FALSE;
	}

	// IQC 검사는 모두 자재테이블, 그 외에는 생산에서 조회해야 한다.
	if (memcmp(CQCMISPSTS.INSP_TYPE, MP_INSP_TYPE_IQC, strlen(MP_INSP_TYPE_IQC)) == 0)
	{
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
		DBU_select_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		c_lot_type = 'P';
	}
	else
	{
		//생산Lot, Dlv Lot  구분
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		//TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
		memcpy(MWIPLOTSTS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		//현재 Lot의 공정과  검사공정(INSP_OPER)가 다를 경우 에러
		if (memcmp(MWIPLOTSTS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER)) != 0)
		{
			strcpy(s_msg_code, "QCM-0066");
			TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTS.OPER), MWIPLOTSTS.OPER);
			TRS.add_fieldmsg(out_node, "REQUESTED_INSP_OPER", MP_STR, sizeof(CQCMISPSTS.INSP_OPER), CQCMISPSTS.INSP_OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		//Lot Type
		c_lot_type = MWIPLOTSTS.LOT_TYPE;
	}

	s_judge_flag = TRS.get_char(in_node, "INSP_JUDGE_FLAG");

	//WORKER 등록
	i_worker_count = TRS.get_item_count(in_node, "WORKER_LIST");

	if (i_worker_count > 0)
	{
		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_UPDATE_INSPECTION_WORKER(s_msg_code, in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

	}



	//TO DO. 여기 판정값에 따른 공정 가져오는 테이블 변경해야함.
	//MP_GCM_INSP_JUDGE
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_INSP_JUDGE, strlen(MP_GCM_INSP_JUDGE));


	//20220310 스카이아다이아 절단품거사는 공정_2붙임..완료창고가 달라져야 되서.....음성에서 하는거랑.(OC06020_2)
	if (TRS.get_procstep(in_node) == '3')
	{
		TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "JUDGE_OPER");

	}
	else {
		memcpy(MGCMTBLDAT.KEY_1, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
	}

	MGCMTBLDAT.KEY_2[0] = s_judge_flag;
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "QCM-0004");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", DT_NOVALUESTRING);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	s_auto_move_yn = MGCMTBLDAT.DATA_3[0]; // 설정된 To Flow, To Oper 로 이동 여부
	s_loss_tran_yn = MGCMTBLDAT.DATA_6[0];  // Loss처리 여부 ( 실제 Loss 트랜잭션 발생 여부)
	s_only_main_loss_tran_yn = MGCMTBLDAT.DATA_7[0];  // Loss처리시에 Main Flag = 'Y' 인것만 Loss트랜잭션 발생할지 여부 ( Y가 아니면 Flag 상관없이 모두 불량)
	s_etc_out_by_loss = MGCMTBLDAT.DATA_8[0];
	s_loss_check_yn = MGCMTBLDAT.DATA_9[0];

	/*
		C - IQC	CTM 수입검사 창고
		G - IQC	GRIT 수입검사 창고
		H - IQC	HM 수입검사 창고
		P - IQC	PDC 수입검사 창고

		OC04120	L / P검사
		OC05060	ROUND 검사
		OC05070	W / D급검사
		OC06020	절단품 검사
		OC07020	인서트 검사
		OC55010	검사(대원)

		OG05240	약식 검사
		OG06450	MP - 제품검사
		OG09010	제품검사
		OG09020	CP - 제품검사
		OG09030	제품검사 - Coat
		OG09040	제품검사 - cBN
		OG55010	검사(대원)

		OH23060	2차 중간검사(QC)
		OH24110	제품검사

		OP08120	완제품 검사
		OP90040	리칭검사
		OP55010(대)검사

		*/

		//Procstep 1:  판정       
		//Procstep 2:  판정(PDC 전용화면)  => PDC제품검사 혹은 PDC 수입검사(상품수입) 에서 동일한 화면 사용
		//Procstep 3:  20220310 추가 판정(스카이 다이아 절단품 검사 전용)  => 스카이다이아 전용화면 별도 사용
	if (TRS.get_procstep(in_node) == '1')
	{
		// IQC 판정과 그 외 판정을 구분해서 처리한다. (판정 안에서 분기 처리해도 되나 명확하게 구분해서 처리하는게 나을것으로 판단.
		if (memcmp(CQCMISPSTS.INSP_TYPE, MP_INSP_TYPE_IQC, strlen(MP_INSP_TYPE_IQC)) == 0)
		{
			if (s_judge_flag == MP_CQMS_INSP_JUDGE_PASS)
			{
				//(1) 자재 Dlv Lot 판정 Update
				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_PASS; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_FAIL)
			{
				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_FAIL; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_SPECIAL)
			{
				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_SPECIAL; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_C)
			{
				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_C; // SAMPLE 2026/04/27 추가(최성수요청)

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
		}
		else
		{
			if (s_judge_flag == MP_CQMS_INSP_JUDGE_PASS) //합격
			{

				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;




				//HM 전용 수량 OVER COPLETE 발생시  20220614 송용원
				if (TRS.get_char(in_node, "OVER_QTY_FLAG") == 'Y') {

					DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
					memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

					//자재 차감
					cv_in = TRS.add_node(in_node, "Cv_in");
					CopyDefaultMembers(cv_in, in_node);

					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_double(cv_in, "QTY_1", TRS.get_double(in_node, "OVER_QTY"));

					if (CUS_WIP_CV_LOT(s_msg_code, cv_in, out_node) == MP_FALSE) {
						return MP_FALSE;
					}



					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);


				}



				//선 Loss 처리 여부
				if (s_loss_tran_yn == 'Y')
				{
					// 부외재고 이동 전용 LOSS코드 있을 때, 해당 LOT은 SPLIT하여  LOSS처리 해준다.
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(9, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(10, &CQCMISPLOS);
					}

					// 부외재고 전용 불량이 존재할 때
					if (d_loss_qty > 0)
					{
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '1');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_double(split_in, "MOVE_QTY_1", d_loss_qty);
						TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);

						TRS.add_char(split_in, "SKIP_BY_LOSS", 'Y');



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
						TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));

						TRS.add_double(loss_in, "OUT_QTY_1", 0);
						TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));

						unit_in = TRS.add_node(loss_in, "UNIT1");
						TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));
						TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
						TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

						if (s_etc_out_by_loss == 'Y')
						{
							TRS.add_char(loss_in, "ETC_OUT_YN", 'Y');
						}

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);



					}














					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(4, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(7, &CQCMISPLOS);
					}

					//판정 LOT을 재조회한다.
					DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
					memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

					if (d_loss_qty > 0)
					{
						loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
						CopyDefaultMembers(loss_in_node, in_node);
						TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
						TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
						TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
						TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS_ORG.QTY_1 - d_loss_qty);
						if (s_etc_out_by_loss == 'Y')
						{
							TRS.add_char(loss_in_node, "ETC_OUT_YN", 'Y');
						}

						if (s_only_main_loss_tran_yn == 'Y')
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
							DBU_open_cqcmisplos(2, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(2, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(2);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.22 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(2);
									//

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}
						else
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
							DBU_open_cqcmisplos(3, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(3, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(3);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.21 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(3);
									//
									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}


						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

					}
				}


				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_FAIL)
			{

				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;



				if (s_only_main_loss_tran_yn == 'Y')
				{
					// LOSS 처리
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
					d_loss_qty = DBU_select_cqcmisplos_scalar(4, &CQCMISPLOS);

					if (d_loss_qty == 0)
					{
						strcpy(s_msg_code, "QCM-0073");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
					else
					{

						if (MWIPLOTSTS.QTY_1 - d_loss_qty != 0)
						{
							strcpy(s_msg_code, "QCM-0074");
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
						CopyDefaultMembers(loss_in_node, in_node);
						TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
						TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
						TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
						TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS.QTY_1 - d_loss_qty);
						TRS.add_nstring(loss_in_node, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_nstring(loss_in_node, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
						TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
						DBU_open_cqcmisplos(2, &CQCMISPLOS);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}
						while (1)
						{
							DBU_fetch_cqcmisplos(2, &CQCMISPLOS);
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_close_cqcmisplos(2);
								break;
							}
							else if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
								TRS.add_dberrmsg(out_node, DB_error_msg);
								DBU_close_cqcmispdat(2);
								return MP_FALSE;
							}

							//Main => 'Y'인 값
							unit_in = TRS.add_node(loss_in_node, "UNIT1");
							TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
							TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

						}

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
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
					// LOSS 처리
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
					d_loss_qty = DBU_select_cqcmisplos_scalar(7, &CQCMISPLOS);

					if (d_loss_qty == 0)
					{
						strcpy(s_msg_code, "QCM-0073");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
					else
					{

						if (MWIPLOTSTS.QTY_1 - d_loss_qty != 0)
						{
							strcpy(s_msg_code, "QCM-0074");
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
						CopyDefaultMembers(loss_in_node, in_node);
						TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
						TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
						TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
						TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS.QTY_1 - d_loss_qty);
						TRS.add_nstring(loss_in_node, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_nstring(loss_in_node, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
						TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
						DBU_open_cqcmisplos(3, &CQCMISPLOS);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}
						while (1)
						{
							DBU_fetch_cqcmisplos(3, &CQCMISPLOS);
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_close_cqcmisplos(3);
								break;
							}
							else if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
								TRS.add_dberrmsg(out_node, DB_error_msg);
								DBU_close_cqcmispdat(3);
								return MP_FALSE;
							}

							unit_in = TRS.add_node(loss_in_node, "UNIT1");
							TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
							TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

						}

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}
				}




			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_SPECIAL || s_judge_flag == MP_CQMS_INSP_JUDGE_W)
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//선 Loss 처리 여부
				if (s_loss_tran_yn == 'Y')
				{
					// 부외재고 이동 전용 LOSS코드 있을 때, 해당 LOT은 SPLIT하여  LOSS처리 해준다.
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(9, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(10, &CQCMISPLOS);
					}

					// 부외재고 전용 불량이 존재할 때
					if (d_loss_qty > 0)
					{
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '1');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_double(split_in, "MOVE_QTY_1", d_loss_qty);
						TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);

						TRS.add_char(split_in, "SKIP_BY_LOSS", 'Y');

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
						TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));

						TRS.add_double(loss_in, "OUT_QTY_1", 0);
						TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));

						unit_in = TRS.add_node(loss_in, "UNIT1");
						TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));
						TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
						TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

					}


					//판정 LOT을 재조회한다.
					DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
					memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);


					// 부외재고 전용 Loss가 아닌것만 처리
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(4, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(7, &CQCMISPLOS);
					}



					if (d_loss_qty > 0)
					{
						loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
						CopyDefaultMembers(loss_in_node, in_node);
						TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
						TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
						TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
						TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS_ORG.QTY_1 - d_loss_qty);

						if (s_only_main_loss_tran_yn == 'Y')
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							DBU_open_cqcmisplos(2, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(2, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(2);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.21 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(2);
									//

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}
						else
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
							DBU_open_cqcmisplos(3, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(3, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(3);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.21 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(3);
									//

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}


						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

					}
				}


				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));


					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_REWORK )
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				if (COM_isnullspace(TRS.get_string(in_node, "TO_FLOW")) == MP_TRUE ||
					COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_TRUE)
				{
					strcpy(s_msg_code, "QCM-0060");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

				if (memcmp(CQCMISPSTS.INSP_OPER, TRS.get_string(in_node, "TO_OPER"), strlen(TRS.get_string(in_node, "TO_OPER"))) == 0)
				{
					strcpy(s_msg_code, "QCM-0062");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;



				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 재가공 (END처리)

					skip_in = TRS.add_node(in_node, "skip_in");
					CopyDefaultMembers(skip_in, in_node);

					TRS.add_char(skip_in, "PROCSTEP", '1');
					TRS.add_string(skip_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(skip_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(skip_in, "TO_FLOW", TRS.get_string(in_node, "TO_FLOW"), sizeof(TRS.get_string(in_node, "TO_FLOW")));
					TRS.add_string(skip_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"), sizeof(TRS.get_string(in_node, "TO_OPER")));
					TRS.add_string(skip_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					//TRS.add_string(skip_in, "RESV_FLAG_1", "Y", strlen("Y"));
					TRS.add_string(skip_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(skip_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(skip_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(skip_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}
					TRS.add_nstring(skip_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, skip_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_CHANGE_MATERIAL) //품목변경용
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;




				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));


					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}






			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_A)  // 절단가능품
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
					TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
					TRS.add_char(end_in, "SCRAP_IF_YN", 'Y');

					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}


				//***************절단가능품시  CWIPLOTREC 테이블에 INSERT ***********************

				//LOT 재조회
				//lot정보 조회
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_ORG.FACTORY), MWIPLOTSTS_ORG.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_ORG.LOT_ID), MWIPLOTSTS_ORG.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//LOT ID에 대한 품목 정보를 조회한다.
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = 1;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				//작업지시 조회
				DBU_init_mwipordsts(&MWIPORDSTS);
				TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
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

				//공정 정보 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF_ORG);
				TRS.copy(MWIPOPRDEF_ORG.FACTORY, sizeof(MWIPOPRDEF_ORG.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_ORG.OPER, MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				//TRS.copy(MWIPOPRDEF_ORG.OPER, sizeof(MWIPOPRDEF_ORG.OPER), in_node, "OPER");
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ORG);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0010 : 이 공정은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ORG.FACTORY), MWIPOPRDEF_ORG.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ORG.OPER), MWIPOPRDEF_ORG.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				if (DB_error_code == DB_SUCCESS)
				{
					//WIP-0680 : 해당 Lot은 이미 P급 판정 진행중입니다.
					strcpy(s_msg_code, "WIP-0680");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//부외재고 리스트 테이블에 insert해준다. 
				DBU_init_cwiplotrec(&CWIPLOTREC);
				memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPLOTSTS_ORG.FACTORY));
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				CWIPLOTREC.HIST_SEQ = MWIPLOTSTS_ORG.LAST_ACTIVE_HIST_SEQ;
				memcpy(CWIPLOTREC.AREA_ID, MWIPOPRDEF_ORG.AREA_ID, sizeof(MWIPOPRDEF_ORG.AREA_ID));
				memcpy(CWIPLOTREC.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(CWIPLOTREC.INV_OPER, MWIPORDSTS.ORD_CMF_3, sizeof(CWIPLOTREC.INV_OPER));

				memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
				memcpy(CWIPLOTREC.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
				memcpy(CWIPLOTREC.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTREC.WORK_DATE));
				memcpy(CWIPLOTREC.MAT_ID, MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPLOTSTS_ORG.MAT_ID));
				CWIPLOTREC.MAT_VER = MWIPLOTSTS_ORG.MAT_VER;
				memcpy(CWIPLOTREC.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				CWIPLOTREC.QTY = MWIPLOTSTS_ORG.QTY_1;
				memcpy(CWIPLOTREC.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(CWIPLOTREC.CREATE_USER_ID, sizeof(CWIPLOTREC.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				DBU_insert_cwiplotrec(&CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTREC.TRAN_OPER), CWIPLOTREC.TRAN_OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}





			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_B) //절단소재용 (Grit의 경우 블렌딩용 포함)
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_C) // SAMPLE 판정
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;



				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_D) // GRIT 부외재고
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);


				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//MP_LOSS_CODE_NON_STOCK
				//GRIT 부외재고 판정은 특정 정의된 LOSS코드로 일괄 LOSS처리한다. ( 나중에 되살릴 수 있음) 

				/*
				change_cmf_in = TRS.add_node(in_node, "Change_cmf");
				CopyDefaultMembers(change_cmf_in, in_node);
				TRS.add_char(change_cmf_in, IN_PROCSTEP, '1');
				TRS.add_string(change_cmf_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(change_cmf_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
				TRS.add_string(change_cmf_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
				cmn_out = TRS.create_node("Cmn_Out");
				if (WIP_CHANGE_CMF(s_msg_code, change_cmf_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out); */






				loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
				CopyDefaultMembers(loss_in_node, in_node);
				TRS.add_char(loss_in_node, IN_PROCSTEP, '1');

				TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
				TRS.add_double(loss_in_node, "OUT_QTY_1", 0);
				TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				TRS.add_string(loss_in_node, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
				TRS.add_string(loss_in_node, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));


				unit_in = TRS.add_node(loss_in_node, "UNIT1");
				TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));
				TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTS_ORG.QTY_1);
				//	TRS.add_string(loss_in_node, "LOSS_COMMENT", CQCMISPSTS.INSP_COMMENT,sizeof(CQCMISPSTS.INSP_COMMENT));
					//TRS.add_string(loss_in_node, "COMMENT", CQCMISPSTS.INSP_COMMENT,sizeof(CQCMISPSTS.INSP_COMMENT));

				TRS.add_nstring(loss_in_node, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
				TRS.add_nstring(loss_in_node, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_E || s_judge_flag == MP_CQMS_INSP_JUDGE_V) //품목전환(저함량 Solid)
			{

				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					//	TRS.add_char(end_in, "INV_FLAG", 'Y'); //품변으로 다시 투입될것이기에 플래그 Y (20210817)
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}


					//INV FLAG 없어서 다시 재투입이 안되서 업데이트 시킴 일단
					DBU_init_mwiplotstsx(&MWIPLOTSTS);

					memcpy(MWIPLOTSTS.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

					MWIPLOTSTS.INV_FLAG = 'Y';  //품변으로 다시 투입될것이기에 플래그 Y (20211122)
					DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					//INV FLAG 없어서 다시 재투입이 안되서 업데이트 시킴 일단
					DBU_init_mwiplotstsx(&MWIPLOTSTS);

					memcpy(MWIPLOTSTS.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

					MWIPLOTSTS.INV_FLAG = 'Y';  //품변으로 다시 투입될것이기에 플래그 Y (20211122)
					DBU_update_mwiplotstsx(1, &MWIPLOTSTS);


					TRS.free_node(cmn_out);
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_RND_PASS || s_judge_flag ==  MP_CQMS_INSP_JUDGE_I) //합격
			{

				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;




				//HM 전용 수량 OVER COPLETE 발생시  20220614 송용원
				if (TRS.get_char(in_node, "OVER_QTY_FLAG") == 'Y') {

					DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
					memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

					//자재 차감
					cv_in = TRS.add_node(in_node, "Cv_in");
					CopyDefaultMembers(cv_in, in_node);

					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_double(cv_in, "QTY_1", TRS.get_double(in_node, "OVER_QTY"));

					if (CUS_WIP_CV_LOT(s_msg_code, cv_in, out_node) == MP_FALSE) {
						return MP_FALSE;
					}



					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);


				}



				//선 Loss 처리 여부
				if (s_loss_tran_yn == 'Y')
				{
					// 부외재고 이동 전용 LOSS코드 있을 때, 해당 LOT은 SPLIT하여  LOSS처리 해준다.
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(9, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(10, &CQCMISPLOS);
					}

					// 부외재고 전용 불량이 존재할 때
					if (d_loss_qty > 0)
					{
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '1');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_double(split_in, "MOVE_QTY_1", d_loss_qty);
						TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);

						TRS.add_char(split_in, "SKIP_BY_LOSS", 'Y');



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
						TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));

						TRS.add_double(loss_in, "OUT_QTY_1", 0);
						TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));

						unit_in = TRS.add_node(loss_in, "UNIT1");
						TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));
						TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
						TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
						TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

						if (s_etc_out_by_loss == 'Y')
						{
							TRS.add_char(loss_in, "ETC_OUT_YN", 'Y');
						}

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);



					}














					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

					if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(4, &CQCMISPLOS);
					}
					else // Main 상관없이 모두 불량처리
					{
						d_loss_qty = DBU_select_cqcmisplos_scalar(7, &CQCMISPLOS);
					}

					//판정 LOT을 재조회한다.
					DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
					memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

					if (d_loss_qty > 0)
					{
						loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
						CopyDefaultMembers(loss_in_node, in_node);
						TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
						TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
						TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
						TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
						TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS_ORG.QTY_1 - d_loss_qty);
						if (s_etc_out_by_loss == 'Y')
						{
							TRS.add_char(loss_in_node, "ETC_OUT_YN", 'Y');
						}

						if (s_only_main_loss_tran_yn == 'Y')
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
							DBU_open_cqcmisplos(2, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(2, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(2);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.22 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(2);
									//

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}
						else
						{
							DBU_init_cqcmisplos(&CQCMISPLOS);
							TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
							TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
							memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
							DBU_open_cqcmisplos(3, &CQCMISPLOS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
								TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
							while (1)
							{
								DBU_fetch_cqcmisplos(3, &CQCMISPLOS);
								if (DB_error_code == DB_NOT_FOUND)
								{
									DBU_close_cqcmisplos(3);
									break;
								}
								else if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "QCM-0004");
									TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									// 20.12.21 minjae.go
									//DBU_close_cqcmispdat(2);
									DBU_close_cqcmisplos(3);
									//
									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}

								unit_in = TRS.add_node(loss_in_node, "UNIT1");
								TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
								TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

							}
						}


						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

					}
				}


				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));

					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_Z)  // 절단가능품
			{
				//불량 필수 입력 체크
				if (s_loss_check_yn == 'Y')
				{
					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
					if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
					{
						strcpy(s_msg_code, "QCM-0081");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
					TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
					TRS.add_char(end_in, "SCRAP_IF_YN", 'Y');

					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}


				//***************절단가능품시  CWIPLOTREC 테이블에 INSERT ***********************

				//LOT 재조회
				//lot정보 조회
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_ORG.FACTORY), MWIPLOTSTS_ORG.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_ORG.LOT_ID), MWIPLOTSTS_ORG.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//LOT ID에 대한 품목 정보를 조회한다.
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = 1;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				//작업지시 조회
				DBU_init_mwipordsts(&MWIPORDSTS);
				TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
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

				
				//공정 정보 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF_ORG);
				TRS.copy(MWIPOPRDEF_ORG.FACTORY, sizeof(MWIPOPRDEF_ORG.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_ORG.OPER, MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				//TRS.copy(MWIPOPRDEF_ORG.OPER, sizeof(MWIPOPRDEF_ORG.OPER), in_node, "OPER");
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ORG);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0010 : 이 공정은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ORG.FACTORY), MWIPOPRDEF_ORG.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ORG.OPER), MWIPOPRDEF_ORG.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				if (DB_error_code == DB_SUCCESS)
				{
					//WIP-0680 : 해당 Lot은 이미 P급 판정 진행중입니다.
					strcpy(s_msg_code, "WIP-0680");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//부외재고 리스트 테이블에 insert해준다. 
				DBU_init_cwiplotrec(&CWIPLOTREC);
				memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPLOTSTS_ORG.FACTORY));
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				CWIPLOTREC.HIST_SEQ = MWIPLOTSTS_ORG.LAST_ACTIVE_HIST_SEQ;
				memcpy(CWIPLOTREC.AREA_ID, MWIPOPRDEF_ORG.AREA_ID, sizeof(MWIPOPRDEF_ORG.AREA_ID));
				memcpy(CWIPLOTREC.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(CWIPLOTREC.INV_OPER, MWIPORDSTS.ORD_CMF_3, sizeof(CWIPLOTREC.INV_OPER));

				memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
				memcpy(CWIPLOTREC.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
				memcpy(CWIPLOTREC.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTREC.WORK_DATE));
				memcpy(CWIPLOTREC.MAT_ID, MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPLOTSTS_ORG.MAT_ID));
				CWIPLOTREC.MAT_VER = MWIPLOTSTS_ORG.MAT_VER;
				memcpy(CWIPLOTREC.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				CWIPLOTREC.QTY = MWIPLOTSTS_ORG.QTY_1;
				memcpy(CWIPLOTREC.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(CWIPLOTREC.CREATE_USER_ID, sizeof(CWIPLOTREC.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				DBU_insert_cwiplotrec(&CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTREC.TRAN_OPER), CWIPLOTREC.TRAN_OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}





			}
		}

		// 검사요청정보 Update
		//todo( ReworkFlow, Reworkoper 추가 필요 )
		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_COMPLETE;  //완료
		CQCMISPSTS.INSP_JUDGE_FLAG = s_judge_flag;
		TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
		CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VERSION");
		//20220614 송용원 추가 HM사업부 단차등으로 수량증가훌수있음
		if (TRS.get_char(in_node, "OVER_QTY_FLAG") == 'Y') {
			CQCMISPSTS.QTY = MWIPLOTSTS_ORG.QTY_1;
		}
		TRS.copy(CQCMISPSTS.RWK_FLOW, sizeof(CQCMISPSTS.RWK_FLOW), in_node, "TO_FLOW");
		TRS.copy(CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER), in_node, "TO_OPER");
		TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");
		memcpy(CQCMISPSTS.INSP_JUDGE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CQCMISPSTS.CMF_4, sizeof(CQCMISPSTS.CMF_4), in_node, IN_USERID); //판정자
		CQCMISPSTS.CMF_5[0] = c_lot_type;
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CQCMISPSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		// IQC 판정과 그 외 판정을 구분해서 처리한다. (판정 안에서 분기 처리해도 되나 명확하게 구분해서 처리하는게 나을것으로 판단.
		if (memcmp(CQCMISPSTS.INSP_TYPE, MP_INSP_TYPE_IQC, strlen(MP_INSP_TYPE_IQC)) == 0)
		{
			//PDC전용화면을 사용하는 수입검사(수입상품품목) 는 일부 LOSS를 제외하고 입고시키기 위해 표준판정로직과 분기시킴.
			if (s_judge_flag == MP_CQMS_INSP_JUDGE_PASS)
			{
				//PDC검사 전용 화면을 사용하는 수입검사(수입상품)는  불량 발생시 전량반품이 아닌 차감 후 입고
				//LOSS존재시 전량 반품이 아닌 DLV 라벨에서 LOSS수량만큼 차감시켜준다.
				//CUS_INV_Loss_Dlv_Label 호출( in_node : DLV_LOT_ID , LOSS_QTY(double) )

				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				d_loss_qty = DBU_select_cqcmisplos_scalar(6, &CQCMISPLOS);

				if (d_loss_qty > 0)
				{
					loss_in_node = TRS.add_node(in_node, "loss_in");
					CopyDefaultMembers(loss_in_node, in_node);

					TRS.add_char(loss_in_node, "PROCSTEP", '1');
					TRS.add_string(loss_in_node, "DLV_LOT_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
					TRS.add_double(loss_in_node, "LOSS_QTY", d_loss_qty);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_LOSS_DLV_LABEL_MAIN(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}









				//(1) 자재 Dlv Lot 판정 Update
				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_PASS; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_FAIL)
			{
				//PDC검사 전용 화면을 사용하는 수입검사(수입상품)는  불량 발생시 전량반품이 아닌 차감 후 입고
				//LOSS존재시 전량 반품이 아닌 DLV 라벨에서 LOSS수량만큼 차감시켜준다.
				//CUS_INV_Loss_Dlv_Label 호출( in_node : DLV_LOT_ID , LOSS_QTY(double) )

				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				d_loss_qty = DBU_select_cqcmisplos_scalar(6, &CQCMISPLOS);

				if (d_loss_qty > 0)
				{
					loss_in_node = TRS.add_node(in_node, "loss_in");
					CopyDefaultMembers(loss_in_node, in_node);

					TRS.add_char(loss_in_node, "PROCSTEP", '1');
					TRS.add_string(loss_in_node, "DLV_LOT_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
					TRS.add_double(loss_in_node, "LOSS_QTY", d_loss_qty);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_LOSS_DLV_LABEL_MAIN(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}


				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_FAIL; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else if (s_judge_flag == MP_CQMS_INSP_JUDGE_SPECIAL)
			{
				//PDC검사 전용 화면을 사용하는 수입검사(수입상품)는  불량 발생시 전량반품이 아닌 차감 후 입고
				//LOSS존재시 전량 반품이 아닌 DLV 라벨에서 LOSS수량만큼 차감시켜준다.
				//CUS_INV_Loss_Dlv_Label 호출( in_node : DLV_LOT_ID , LOSS_QTY(double) )

				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				d_loss_qty = DBU_select_cqcmisplos_scalar(6, &CQCMISPLOS);

				if (d_loss_qty > 0)
				{
					loss_in_node = TRS.add_node(in_node, "loss_in");
					CopyDefaultMembers(loss_in_node, in_node);

					TRS.add_char(loss_in_node, "PROCSTEP", '1');
					TRS.add_string(loss_in_node, "DLV_LOT_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
					TRS.add_double(loss_in_node, "LOSS_QTY", d_loss_qty);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_LOSS_DLV_LABEL_MAIN(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}


				TRS.copy(MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID), in_node, "INSP_ID");
				memcpy(MINVDLVLOT.INSP_REQ_TIME, gs_sys_time, sizeof(gs_sys_time));
				TRS.copy(MINVDLVLOT.INSP_USER_ID, sizeof(MINVDLVLOT.INSP_USER_ID), in_node, IN_USERID);
				MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
				MINVDLVLOT.INSP_RESULT_FLAG = MP_CQMS_INSP_JUDGE_SPECIAL; // 자릿수 늘려야함.
				//TRS.copy(MINVDLVLOT.INSP_RESULT_FLAG, sizeof(MINVDLVLOT.INSP_RESULT_FLAG), in_node, "INSP_JUDGE_FLAG");

				TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_minvdlvlot(2, &MINVDLVLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
		}
		else
		{
			if (s_judge_flag == MP_CQMS_INSP_JUDGE_PASS) //합격
			{

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);


				//자재 차감
				inv_in = TRS.add_node(in_node, "inv_in");
				CopyDefaultMembers(inv_in, in_node);

				TRS.add_char(inv_in, IN_PROCSTEP, '1');
				TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
				TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
				//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
				//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
				TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

				if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
					return MP_FALSE;


				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
				TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
				if ((int)DBU_select_cqcmispdat_scalar(2, &CQCMISPDAT) == 0)
				{
					//QCM-0059
					strcpy(s_msg_code, "QCM-0059");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT SELECT(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//PDC의 경우 합격, 불합격, 재가공 로직이 데이터안에 같이 들어있기 때문에 벨리데이션 추가 
				//(일반적인 화면에서 저장시에는 문제발생하지 않으나, 마이그레이션 등 데이터 이관 후 문제가 발생할 수 있어서 추가) 
				if ((int)DBU_select_cqcmispdat_scalar(9, &CQCMISPDAT) == 0)
				{
					//QCM-0059
					strcpy(s_msg_code, "QCM-0078");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT SELECT SCALAR(9)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				//PDC Loss 총 수량
				i_pdc_loss_sum_cnt = (int)DBU_select_cqcmispdat_scalar(3, &CQCMISPDAT);

				//Loss처리
				if (i_pdc_loss_sum_cnt > 0)
				{
					loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
					CopyDefaultMembers(loss_in_node, in_node);
					TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
					TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
					TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
					TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
					TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
					TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS.QTY_1 - i_pdc_loss_sum_cnt);

					// LOSS 처리 ( REWORK 제외한  실제 Loss처리 대상)
					DBU_init_cqcmispdat(&CQCMISPDAT);
					TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
					TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
					DBU_open_cqcmispdat(2, &CQCMISPDAT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
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
						DBU_fetch_cqcmispdat(2, &CQCMISPDAT);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cqcmispdat(2);
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

							DBU_close_cqcmispdat(2);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						unit_in = TRS.add_node(loss_in_node, "UNIT1");
						TRS.add_string(unit_in, "LOSS_CODE", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						TRS.add_double(unit_in, "LOSS_QTY", CQCMISPDAT.SAMPLE_COUNT);

					}

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

				//Rework Qty(재가공 총 수량)
				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
				TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");

				i_pdc_rework_cnt = (int)DBU_select_cqcmispdat_scalar(4, &CQCMISPDAT);

				//Split처리 후, 재가공공정 이동(Skip 처리)
				if (i_pdc_rework_cnt > 0)
				{
					//REWORK_OPER Vaildation 추가 todo
					if (COM_isnullspace(TRS.get_string(in_node, "TO_FLOW")) == MP_TRUE ||
						COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_TRUE)
					{
						strcpy(s_msg_code, "QCM-0060");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						return MP_FALSE;
					}

					if (memcmp(CQCMISPSTS.INSP_OPER, TRS.get_string(in_node, "TO_OPER"), strlen(TRS.get_string(in_node, "TO_OPER"))) == 0)
					{
						strcpy(s_msg_code, "QCM-0062");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						return MP_FALSE;
					}


					DBU_init_mwipoprdef(&MWIPOPRDEF);
					TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPOPRDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
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

					DBU_init_mgcmtbldat(&MGCMTBLDAT);
					TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_OPER_OPTION, strlen(MP_GCM_OPER_OPTION));
					memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					memcpy(MGCMTBLDAT.KEY_2, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
					memcpy(MGCMTBLDAT.KEY_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

					if (COM_isspace(MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3)) == MP_TRUE)
					{
						strcpy(s_msg_code, "QCM-0061");
						TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
						TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						return MP_FALSE;
					}


					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);

					TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));
					TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

					argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
					TRS.add_string(argu_list_node, "ARGUMENT", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					memcpy(s_split_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
					TRS.free_node(cmn_out);


					// MWIPLOTSTS - 공정 LOT ID 정보 조회
					DBU_init_mwiplotstsx(&MWIPLOTSTS);
					TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPLOTSTS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
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


					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node);

					TRS.add_char(split_in, "PROCSTEP", '1');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", s_split_lot_id, sizeof(s_split_lot_id));
					TRS.add_string(split_in, "CHILD_LOT_DESC", s_split_lot_id, sizeof(s_split_lot_id));
					TRS.add_double(split_in, "MOVE_QTY_1", i_pdc_rework_cnt);
					TRS.add_char(split_in, "SKIP_BY_LOSS", 'Y');

					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS.QTY_1);   //split 전 모랏의 총 수량

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					//Split Lot 정보
					DBU_init_mwiplotstsx(&MWIPLOTSTS_SPL);
					memcpy(MWIPLOTSTS_SPL.LOT_ID, s_split_lot_id, sizeof(MWIPLOTSTS_SPL.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_SPL);
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


					skip_in = TRS.add_node(in_node, "skip_in");
					CopyDefaultMembers(skip_in, in_node);

					TRS.add_char(skip_in, "PROCSTEP", '1');
					TRS.add_string(skip_in, "LOT_ID", MWIPLOTSTS_SPL.LOT_ID, sizeof(MWIPLOTSTS_SPL.LOT_ID));  //Splited Lot ID
					TRS.add_string(skip_in, "OPER", MWIPLOTSTS_SPL.OPER, sizeof(MWIPLOTSTS_SPL.OPER));
					TRS.add_string(skip_in, "TO_FLOW", TRS.get_string(in_node, "TO_FLOW"), sizeof(TRS.get_string(in_node, "TO_FLOW")));
					TRS.add_string(skip_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"), sizeof(TRS.get_string(in_node, "TO_OPER")));
					TRS.add_string(skip_in, "ORDER_ID", MWIPLOTSTS_SPL.ORDER_ID, sizeof(MWIPLOTSTS_SPL.ORDER_ID));
					//TRS.add_string(skip_in, "RESV_FLAG_1", "Y", strlen("Y"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, skip_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

				/* 데이터 저장시로 이동
				//Loss 정보 저장
				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
				TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
				CQCMISPDAT.INSP_SEQ = 1;
				memcpy(CQCMISPDAT.CHAR_ID, "JUDGE_LOSS", strlen("JUDGE_LOSS"));
				DBU_open_cqcmispdat(3, &CQCMISPDAT);

				while (1)
				{
					DBU_fetch_cqcmispdat(3, &CQCMISPDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cqcmispdat(3);
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

						DBU_close_cqcmispdat(3);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					DBU_init_cqcmisplos(&CQCMISPLOS);
					TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
					memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);
					CQCMISPLOS.QTY_FLAG = '1';
					memcpy(CQCMISPLOS.LOSS_CODE, CQCMISPDAT.VALUE_1, sizeof(CQCMISPLOS.LOSS_CODE));
					CQCMISPLOS.LOSS_QTY = CQCMISPDAT.SAMPLE_COUNT;
					memcpy(CQCMISPLOS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
					CQCMISPLOS.HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;
					memcpy(CQCMISPLOS.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
					memcpy(CQCMISPLOS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
					CQCMISPLOS.MAT_VER = MWIPLOTSTS.MAT_VER;
					memcpy(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
					CQCMISPLOS.FLOW_SEQ = MWIPLOTSTS.FLOW_SEQ_NUM;
					memcpy(CQCMISPLOS.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
					memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
					DBU_insert_cqcmisplos(&CQCMISPLOS);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS INSERT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

				}
				*/

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}

			}
		}

		// 검사요청정보 Update
		//todo( ReworkFlow, Reworkoper 추가 필요 )
		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_COMPLETE;  //완료
		CQCMISPSTS.INSP_JUDGE_FLAG = s_judge_flag;
		TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
		CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VERSION");
		if (TRS.get_char(in_node, "OVER_QTY_FLAG") == 'Y') {
			CQCMISPSTS.QTY = MWIPLOTSTS_ORG.QTY_1;
		}
		TRS.copy(CQCMISPSTS.RWK_FLOW, sizeof(CQCMISPSTS.RWK_FLOW), in_node, "TO_FLOW");
		TRS.copy(CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER), in_node, "TO_OPER");
		TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");
		memcpy(CQCMISPSTS.INSP_JUDGE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CQCMISPSTS.CMF_4, sizeof(CQCMISPSTS.CMF_4), in_node, IN_USERID); //판정자
		CQCMISPSTS.CMF_5[0] = c_lot_type;
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CQCMISPSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		//PDC 리칭의 경우 검사 완료후 분할 진행

		if (TRS.get_char(in_node, "SPLITE_FLAG") == 'Y')
		{
			splite_tbl = TRS.get_list(in_node, "SPLITE_LIST");
			i_splite_count = TRS.get_item_count(in_node, "SPLITE_LIST");

			for (int i = 0; i < i_splite_count; i++)
			{


				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(split_in, "PROCSTEP", '1');
				TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_nstring(split_in, "CHILD_LOT_ID", TRS.get_string(splite_tbl[i], "SPLITE_LOT"));
				TRS.add_nstring(split_in, "CHILD_LOT_DESC", TRS.get_string(splite_tbl[i], "SPLITE_LOT"));
				TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(splite_tbl[i], "SPLITE_LOT_QTY"));
				//TRS.add_string(split_in, "COMMENT", MWIPLOTSTS_ORG.LAST_COMMENT, sizeof(MWIPLOTSTS_ORG.LAST_COMMENT));
				TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);

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


	}
	else if (TRS.get_procstep(in_node) == '3')
	{

		if (s_judge_flag == MP_CQMS_INSP_JUDGE_PASS) //합격
		{

			//불량 필수 입력 체크
			if (s_loss_check_yn == 'Y')
			{
				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				if ((int)DBU_select_cqcmisplos_scalar(3, &CQCMISPLOS) == 0)
				{
					strcpy(s_msg_code, "QCM-0081");
					TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, strlen("C_INSP_JUDGE"), "C_INSP_JUDGE");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}

			//판정 LOT을 재조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
			memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

			//자재 차감
			inv_in = TRS.add_node(in_node, "inv_in");
			CopyDefaultMembers(inv_in, in_node);

			TRS.add_char(inv_in, IN_PROCSTEP, '1');
			TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
			TRS.add_string(inv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
			TRS.add_string(inv_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
			//TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			//TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
			//to 공정이 정해지는경우 (skip 또는 재작업) to 공정을 end로 넘겨준다.
			TRS.add_nstring(inv_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));

			if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
				return MP_FALSE;






			//선 Loss 처리 여부
			if (s_loss_tran_yn == 'Y')
			{
				// 부외재고 이동 전용 LOSS코드 있을 때, 해당 LOT은 SPLIT하여  LOSS처리 해준다.
				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

				if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
				{
					d_loss_qty = DBU_select_cqcmisplos_scalar(9, &CQCMISPLOS);
				}
				else // Main 상관없이 모두 불량처리
				{
					d_loss_qty = DBU_select_cqcmisplos_scalar(10, &CQCMISPLOS);
				}

				// 부외재고 전용 불량이 존재할 때
				if (d_loss_qty > 0)
				{
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
					memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(split_in, "PROCSTEP", '1');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_double(split_in, "MOVE_QTY_1", d_loss_qty);
					TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);

					TRS.add_char(split_in, "SKIP_BY_LOSS", 'Y');



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
					TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));

					TRS.add_double(loss_in, "OUT_QTY_1", 0);
					TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));

					unit_in = TRS.add_node(loss_in, "UNIT1");
					TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));
					TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
					TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));
					TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					if (s_etc_out_by_loss == 'Y')
					{
						TRS.add_char(loss_in, "ETC_OUT_YN", 'Y');
					}

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);



				}














				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
				memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외

				if (s_only_main_loss_tran_yn == 'Y') //Main Flag 'Y'  만 불량처리 할지 여부
				{
					d_loss_qty = DBU_select_cqcmisplos_scalar(4, &CQCMISPLOS);
				}
				else // Main 상관없이 모두 불량처리
				{
					d_loss_qty = DBU_select_cqcmisplos_scalar(7, &CQCMISPLOS);
				}

				//판정 LOT을 재조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
				memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

				if (d_loss_qty > 0)
				{
					loss_in_node = TRS.add_node(in_node, "Wip_Lot_Loss");
					CopyDefaultMembers(loss_in_node, in_node);
					TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
					TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(loss_in_node, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(loss_in_node, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(loss_in_node, "CAUSE_FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));
					TRS.add_string(loss_in_node, "CAUSE_OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_double(loss_in_node, "OUT_QTY_1", MWIPLOTSTS_ORG.QTY_1 - d_loss_qty);
					if (s_etc_out_by_loss == 'Y')
					{
						TRS.add_char(loss_in_node, "ETC_OUT_YN", 'Y');
					}

					if (s_only_main_loss_tran_yn == 'Y')
					{
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
						TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
						memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
						DBU_open_cqcmisplos(2, &CQCMISPLOS);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
						while (1)
						{
							DBU_fetch_cqcmisplos(2, &CQCMISPLOS);
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_close_cqcmisplos(2);
								break;
							}
							else if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								// 20.12.22 minjae.go
								//DBU_close_cqcmispdat(2);
								DBU_close_cqcmisplos(2);
								//

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							unit_in = TRS.add_node(loss_in_node, "UNIT1");
							TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
							TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

						}
					}
					else
					{
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
						TRS.copy(CQCMISPLOS.INSP_ID, sizeof(CQCMISPLOS.INSP_ID), in_node, "INSP_ID");
						memcpy(CQCMISPLOS.LOSS_CODE, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)); //부외재고 이동 loss코드 제외
						DBU_open_cqcmisplos(3, &CQCMISPLOS);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "QCM-0004");
							TRS.add_fieldmsg(out_node, "CQCMISPLOS OPEN", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
							TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
						while (1)
						{
							DBU_fetch_cqcmisplos(3, &CQCMISPLOS);
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_close_cqcmisplos(3);
								break;
							}
							else if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "QCM-0004");
								TRS.add_fieldmsg(out_node, "CQCMISPLOS FETCH", DT_NOVALUESTRING);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								// 20.12.21 minjae.go
								//DBU_close_cqcmispdat(2);
								DBU_close_cqcmisplos(3);
								//
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							unit_in = TRS.add_node(loss_in_node, "UNIT1");
							TRS.add_string(unit_in, "LOSS_CODE", CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE));
							TRS.add_double(unit_in, "LOSS_QTY", CQCMISPLOS.LOSS_QTY);

						}
					}


					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
			}

			//판정 LOT을 재조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
			memcpy(MWIPLOTSTS_ORG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

			if (MWIPLOTSTS_ORG.LOT_DEL_FLAG != 'Y')
			{




				//자동이동처리
				if (s_auto_move_yn == 'Y')
				{
					if (COM_isnullspace(MGCMTBLDAT.DATA_4) == MP_TRUE ||
						COM_isnullspace(MGCMTBLDAT.DATA_5) == MP_TRUE)
					{
						// To Flow, To Oper  설정이 되어있지 않습니다. (GCM : C_INSP_JUDGE )
						strcpy(s_msg_code, "QCM-0075");
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "TO_FLOW", MGCMTBLDAT.DATA_4, sizeof(MGCMTBLDAT.DATA_4));
					TRS.add_string(end_in, "TO_OPER", MGCMTBLDAT.DATA_5, sizeof(MGCMTBLDAT.DATA_5));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));


					//memset()
					//TRS.add_string(end_in,"LOT_CMF_11",s_judge_flag)

					//MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
				else
				{
					//LOT 완료
					end_in = TRS.add_node(in_node, "end_in");
					TRS.add_char(end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(end_in, in_node);

					TRS.add_string(end_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(end_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(end_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(end_in, "LOT_CMF_10", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
					MWIPLOTSTS_ORG.LOT_CMF_11[0] = s_judge_flag;
					TRS.add_string(end_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_TYPE_PQC, strlen(MP_INSP_TYPE_PQC)) == 0)
					{
						TRS.add_string(end_in, "LOT_CMF_12", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
						MWIPLOTSTS_ORG.LOT_CMF_13[0] = s_judge_flag;
						TRS.add_string(end_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					}

					TRS.add_nstring(end_in, "COMMENT", TRS.get_string(in_node, "INSP_COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

				}
			}


		}



		// 검사요청정보 Update
		//todo( ReworkFlow, Reworkoper 추가 필요 )
		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_COMPLETE;  //완료
		CQCMISPSTS.INSP_JUDGE_FLAG = s_judge_flag;
		TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
		CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VERSION");
		if (TRS.get_char(in_node, "OVER_QTY_FLAG") == 'Y') {
			CQCMISPSTS.QTY = MWIPLOTSTS_ORG.QTY_1;
		}
		TRS.copy(CQCMISPSTS.RWK_FLOW, sizeof(CQCMISPSTS.RWK_FLOW), in_node, "TO_FLOW");
		TRS.copy(CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER), in_node, "TO_OPER");
		TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");
		memcpy(CQCMISPSTS.INSP_JUDGE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CQCMISPSTS.CMF_4, sizeof(CQCMISPSTS.CMF_4), in_node, IN_USERID); //판정자
		CQCMISPSTS.CMF_5[0] = c_lot_type;
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CQCMISPSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}
	return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Inspection_Judge_Validation()
- Validation Check sub function of "CUS_QCM_INSPECTION_JUDGE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Inspection_Judge_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
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
