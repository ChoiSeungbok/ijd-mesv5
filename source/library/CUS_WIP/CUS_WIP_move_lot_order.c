/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_move_lot_order.c
Description : 이동 지시 등록/확인

MES Version : 5.0

Function List
- step 1: 이동지시 등록
- step 2: 이동지시 확정

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/12  Miracom        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "../CUS_COM/CUS_defines.h"

int CUS_WIP_Move_Lot_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_MOVE_LOT_ORDER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Move_Lot_Order()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Order(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_MOVE_LOT_ORDER(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Move_Lot_Order", out_node);
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
CUS_WIP_MOVE_LOT_ORDER()
- Main sub function of "CUS_WIP_Move_Lot_Order" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_MOVE_LOT_ORDER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	/* TABLE */
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	// LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_EA;	// LOT 마스터
	struct MWIPLOTHISX_TAG MWIPLOTHISX;	// LOT 마스터    
	struct CWIPLOTMVM_TAG CWIPLOTMVM;	// 이동지시 마스터
	struct CWIPLOTMVR_TAG CWIPLOTMVR;	// 이동지시 LOT LIST
	struct CWIPLOTMVC_TAG CWIPLOTMVC;	// 이동지시 LOT 변경 LIST
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;	// TO 창고 정보
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;	// FROM 창고 정보
	struct MWIPFLWOPR_TAG MWIPFLWOPR;		// 완제품 창고일 경우, 출하 FLOW 정보
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_INSP;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	struct CWIPLOTREC_TAG CWIPLOTREC;

	struct work_date_tag work_date;

	TRSNode* gen_in_node;
	TRSNode* merge_in;
	//TRSNode *store_in;
	TRSNode* move_in;
	TRSNode* unstore_in;
	TRSNode* erpif_in;
	TRSNode* cmn_out;
	TRSNode** Lot_tbl;
	TRSNode* list_item;

	char s_before_mat_id[31];
	char s_Order_id[21];
	int i_lot_count = 0;
	int i_step = 0;
	double dSumQty = 0;
	double dLotSumQty = 0;
	int iCount = 0;
	double d_pack_sum_qty = 0;
	double d_inv_txns_id = 0;
	char s_factory[10];
	char s_Mat_id[31];
	char s_Press_id[21];
	char c_Change_yn;
	int i_insp_move_flag = 0;

	// LOG
	LOG_head("CUS_WIP_Move_Lot_Order");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	// VALIDATION CHECK
	if (CUS_WIP_Move_Lot_Order_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	//step 1: 이동지시 등록
	/* => 이동지시 등록할 때는 이동할 LOT 리스트(CWIPLOTMVR)와 이동하면서 변경될 LOT LIST(CWIPLOTMVC)를 저장한다.
		  저장 후 실제 LOT이 MERGE되는 시점은 다음 공정에서 이동표를 인수 하는 시점이고
		  인수 전에는 LOT LIST를 변경 및 삭제 할 수 있다.
	 */
	if (TRS.get_procstep(in_node) == '1')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "MOVE_ID")) == MP_TRUE)
		{
			memset(s_Order_id, ' ', sizeof(s_Order_id));

			//이동지시 ID 발번 규칙을 셋업하여 찾아오도록 한다.
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			TRS.add_char(gen_in_node, "PROCSTEP", '2');
			CopyDefaultMembers(gen_in_node, in_node);
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_MOVE_ORDER, strlen(MP_ID_ROLE_WIP_MOVE_ORDER));
			TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "AREA_ID"));
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
			memcpy(s_Order_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
			TRS.free_node(cmn_out);
		}
		else
		{
			TRS.copy(s_Order_id, sizeof(s_Order_id), in_node, "MOVE_ID");
		}

		//FROM 창고 조회하여 FROM_SUB_AREA_ID, FROM_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER), in_node, "OPER");
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

		//TO 창고 조회하여 TO_SUB_AREA_ID, TO_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
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

		//이동지시 마스터 생성 및 업데이트
		DBU_init_cwiplotmvm(&CWIPLOTMVM);
		TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPLOTMVM.MOVE_ID, s_Order_id, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code == DB_SUCCESS)
		{
			if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
			{
				//WIP-0560 : 완료된 이동지시는 수정할 수 없습니다.
				strcpy(s_msg_code, "WIP-0560");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(CWIPLOTMVM.MOVE_STATUS), CWIPLOTMVM.MOVE_STATUS);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//이동지시를 수정할 수 없는 공정인 경우 수정할 수 없다. 
			//GCM 셋업 C_MOVE_OPTION
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, "C_MOVE_OPTION", strlen("C_MOVE_OPTION"));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code == DB_SUCCESS)
			{
				if (MGCMTBLDAT.DATA_3[0] == 'Y')
				{
					//WIP-0688 : 선택된 공정에서는 이동지시를 수정 할 수 없습니다.
					strcpy(s_msg_code, "WIP-0688");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}

			TRS.copy(CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID), in_node, "AREA_ID");
			memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			//TRS.copy(CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID), in_node, "TO_SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER), in_node, "TO_OPER");
			TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));
			CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");

			DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		else if (DB_error_code == DB_NOT_FOUND)
		{
			memcpy(CWIPLOTMVM.FROM_AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			memcpy(CWIPLOTMVM.FROM_SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.FROM_OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
			//TRS.copy(CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID), in_node, "AREA_ID");
			//TRS.copy(CWIPLOTMVM.FROM_SUB_AREA_ID, sizeof(CWIPLOTMVM.FROM_SUB_AREA_ID), in_node, "SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.FROM_OPER, sizeof(CWIPLOTMVM.FROM_OPER), in_node, "OPER");
			//TO_AREA_ID는 같은 사업부 내에서만 이동할 수 있도록 함
			memcpy(CWIPLOTMVM.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			//TRS.copy(CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID), in_node, "AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID), in_node, "TO_SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER), in_node, "TO_OPER");

			
			CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");
			//memcpy(CWIPLOTMVM.MOVE_STATUS, MP_CWIP_ORDER_START, strlen(MP_CWIP_ORDER_START));
			CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_START;
			TRS.copy(CWIPLOTMVM.CREATE_USER_ID, sizeof(CWIPLOTMVM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.CREATE_TIME));
			TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

			DBU_insert_cwiplotmvm(&CWIPLOTMVM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		/* 이동지시 LOT LIST를 삭제 한다.
			=> 이동지시 리스트의 변동이 있을겨우 전부 삭제 후 다시 저장한다. */
			//CWIPLOTMVR에 저장되었던 lot list를 지운다.
		DBU_init_cwiplotmvr(&CWIPLOTMVR);
		memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
		memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_delete_cwiplotmvr(2, &CWIPLOTMVR);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//이동지시 변경이동 lot list 를 삭제한다. 
		//CWIPLOTMVC에 저장되었던 lot list를 지운다.
		DBU_init_cwiplotmvc(&CWIPLOTMVC);
		memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
		memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_delete_cwiplotmvc(2, &CWIPLOTMVC);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//이동지시 LOT LIST 저장
		Lot_tbl = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (int i = 0; i < i_lot_count; i++)
		{
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				// 이동 시, FROM 창고가 완제품 창고라면, 포장 정보 확인.
				// 만약 포장 진행 중인 정보가 존재한다면, 해당 출하 LOT 분할 예정이기때문에, 
				// 이동을 하려면, 해당 LOT의 수량을 분할하여 분할된 LOT으로 이동해야됨. 
				DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
				TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CPAKLOTSTS_COUNT.ORG_LOT_ID, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), Lot_tbl[i], "LOT_ID");
				d_pack_sum_qty = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS_COUNT);

				if (d_pack_sum_qty > 0)
				{
					//WIP-0623 : 해당 Lot은 포장 진행중입니다. 이동을 원하신다면, Lot을 분할해주세요.
					strcpy(s_msg_code, "WIP-0623");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS_COUNT.FACTORY), CPAKLOTSTS_COUNT.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), CPAKLOTSTS_COUNT.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "QTY", MP_DBL, TRS.get_double(Lot_tbl[i], "QTY"));
					TRS.add_fieldmsg(out_node, "PACKING_QTY", MP_DBL, d_pack_sum_qty);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			// 이동될 lot 이 선택공정 (from)과 같은지 여부 체크
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_EA);
			TRS.copy(MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID), Lot_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_EA);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_EA.FACTORY), MWIPLOTSTSX_EA.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//완제품 창고로 이동할 경우 lot이 테스트 품이면 이동 할 수 없다.
			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
			{
				if (MWIPLOTSTSX_EA.LOT_TYPE == MP_LOT_TYPE_T)
				{
					//WIP-0686 : 테스트품은 제품창고로 이동할 수 없습니다. 양산품 전환 후 이동처리 하세요.
					strcpy(s_msg_code, "WIP-0686");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//LOSS -> LOSS 창고 이동의 경우 P급 체크 VALIDATION을 하지 않음.
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0)
			{
			}
			else
			{
				//P급인지 체크
				DBU_init_cwiplotrec(&CWIPLOTREC);
				memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(MWIPLOTSTSX_EA.FACTORY));
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);
				if (DB_error_code == DB_SUCCESS)
				{

					/*
					//WIP-0667 : P급은 외주 출고를 할 수 없습니다. LOT상태를 확인하세요.
					strcpy(s_msg_code, "WIP-0667");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
					*/
					//29221228 리턴하다가 누락되거나 어쩌다 보니 계속 P급 리스트에 남아있는경우 있어서 그냥 있으면 Del 시켜버리도록 수정(어차피 창고이동 하는 상태이면 P급 아닌상태임)

					CWIPLOTREC.DELETE_FLAG = 'Y';
					TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));

					DBU_update_cwiplotrec(4, &CWIPLOTREC);
					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
					{
						TRS.add_fieldmsg(out_node, "CWIPLOTREC Delete 1", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

						return MP_FALSE;
					}

				}
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
			{
				//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0648");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == MP_FALSE)
			{
				//WIP-0679 : 입고 공정과 LOT의 공정이 같습니다. LOT의 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0679");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//이동지시 확정이 안된 LOT은 작업을 진행 할 수 없다.            
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
			memcpy(CWIPLOTMVR.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
			iCount = (int)DBU_select_cwiplotmvr_scalar(4, &CWIPLOTMVR);
			if (iCount > 0)
			{
				//WIP-0673 :이 LOT은 이미 "OPEN" 상태의 다른 이동지시번호가 존재합니다.
				strcpy(s_msg_code, "WIP-0673");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}


			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(MWIPLOTSTSX_EA.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX_EA.MAT_ID, sizeof(MWIPLOTSTSX_EA.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(10) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 창고 -> 완제품 창고 이동 시, LOT_CMF_11 - GCM(C_INSP_JUDGE_LIST).DATA_7 = Y(C, P, S)인것만 가능(+ 공백도 가능),
			//20231018 제품반 검사판정 체크
			/*if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				&& memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0)
				*/
			//20250502 일단 판정없으면 무조건 막히도록 수정.(품질팀요청)
			
			/*
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0 || memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_PROTO_TYPE, strlen(MP_MAT_TYPE_PROTO_TYPE)) == 0)
				{
					DBU_init_mgcmtbldat(&MGCMTBLDAT_INSP);
					TRS.copy(MGCMTBLDAT_INSP.FACTORY, sizeof(MGCMTBLDAT_INSP.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_INSP.TABLE_NAME, MP_GCM_INSP_JUDGE_LIST, strlen(MP_GCM_INSP_JUDGE_LIST));
					memcpy(MGCMTBLDAT_INSP.KEY_1, MWIPLOTSTSX_EA.LOT_CMF_11, sizeof(MWIPLOTSTSX_EA.LOT_CMF_11));

					if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
					{
						i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
					}
					else
					{
						//20250502 일단 다른 사업부도 합격아니면 무조건 막음 제품이랑 개발품
						i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(3, &MGCMTBLDAT_INSP);
					}


					if (i_insp_move_flag == 0)
					{
						//WIP-0654 : 해당 Lot의 판정 값은 완제품 창고로 이동이 불가합니다.
						strcpy(s_msg_code, "WIP-0654");
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
						TRS.add_fieldmsg(out_node, "JUDGE", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_CMF_11), MWIPLOTSTSX_EA.LOT_CMF_11);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}


			}
			
			*/

			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			TRS.copy(CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID), Lot_tbl[i], "LOT_ID");
			CWIPLOTMVR.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVR.QTY = TRS.get_double(Lot_tbl[i], "QTY");
			CWIPLOTMVR.MERGE_FLAG = CWIPLOTMVM.MERGE_FLAG;
			CWIPLOTMVR.MERGE_LOT_FLAG = TRS.get_char(Lot_tbl[i], "MERGE_LOT_FLAG");
			TRS.copy(CWIPLOTMVR.CREATE_USER_ID, sizeof(CWIPLOTMVR.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.CREATE_TIME));
			TRS.copy(CWIPLOTMVR.UPDATE_USER_ID, sizeof(CWIPLOTMVR.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.UPDATE_TIME));

			DBU_insert_cwiplotmvr(&CWIPLOTMVR);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MERGE_FLAG 가 'Y'가 아닌경우 이동지시 LOT LIST 는 이동지시 확정 LOT LIST와 동일하다.
			if (CWIPLOTMVM.MERGE_FLAG != 'Y')
			{
				DBU_init_cwiplotmvc(&CWIPLOTMVC);
				memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVR.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
				memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				memcpy(CWIPLOTMVC.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
				CWIPLOTMVC.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
				CWIPLOTMVC.QTY = CWIPLOTMVR.QTY;
				TRS.copy(CWIPLOTMVC.CREATE_USER_ID, sizeof(CWIPLOTMVC.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTMVC.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.CREATE_TIME));
				TRS.copy(CWIPLOTMVC.UPDATE_USER_ID, sizeof(CWIPLOTMVC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTMVC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.UPDATE_TIME));

				DBU_insert_cwiplotmvc(&CWIPLOTMVC);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTMVC INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
					TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVC.LOT_ID), CWIPLOTMVC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		if (CWIPLOTMVM.MERGE_FLAG == 'Y')
		{
			//merge 대표 lot에 다른 lot을 모두 merge처리 할 수량이 들어간다. 
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			CWIPLOTMVR.MERGE_LOT_FLAG = 'Y';
			DBU_select_cwiplotmvr(2, &CWIPLOTMVR);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MERGE 대상 LOT의 QTY값 SUM
			dSumQty = DBU_select_cwiplotmvr_scalar(2, &CWIPLOTMVR);

			//mergr lot을 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
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

			DBU_init_cwiplotmvc(&CWIPLOTMVC);
			memcpy(CWIPLOTMVC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			memcpy(CWIPLOTMVC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			CWIPLOTMVC.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVC.QTY = dSumQty;
			TRS.copy(CWIPLOTMVC.CREATE_USER_ID, sizeof(CWIPLOTMVC.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.CREATE_TIME));
			TRS.copy(CWIPLOTMVC.UPDATE_USER_ID, sizeof(CWIPLOTMVC.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.UPDATE_TIME));

			DBU_insert_cwiplotmvc(&CWIPLOTMVC);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVC.LOT_ID), CWIPLOTMVC.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//move id를 out node에 넣어준다.
		TRS.add_string(out_node, "MOVE_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));

	}
	//step 2: 이동지시 취소
	// => 이동지시의 상태를 삭제로 변경한다.
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_cwiplotmvm(&CWIPLOTMVM);
		TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), in_node, "MOVE_ID");

		DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0561 : 이동지시번호가 존재하지 않습니다. 이동지시 번호를 확인하세요.
			strcpy(s_msg_code, "WIP-0561");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM SELECT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
		{
			//WIP-0562 : 완료된 이동지시는 취소할 수 없습니다.
			strcpy(s_msg_code, "WIP-0562");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(CWIPLOTMVM.MOVE_STATUS), CWIPLOTMVM.MOVE_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_DELETE;
		TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

		DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	//step 3: 이동지시 확인
	else if (TRS.get_procstep(in_node) == '3')
	{
		//이동지시 조회
		DBU_init_cwiplotmvm(&CWIPLOTMVM);
		TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), in_node, "MOVE_ID");

		DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0561 : 이동지시번호가 존재하지 않습니다. 이동지시 번호를 확인하세요.
			strcpy(s_msg_code, "WIP-0561");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM SELECT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
		{
			//WIP-0560 : 완료된 이동지시는 수정할 수 없습니다.
			strcpy(s_msg_code, "WIP-0560");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(CWIPLOTMVM.MOVE_STATUS), CWIPLOTMVM.MOVE_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		//FROM 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_FROM.OPER, CWIPLOTMVM.FROM_OPER, sizeof(CWIPLOTMVM.FROM_OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
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
		memcpy(MWIPOPRDEF_TO.OPER, CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(3) ", DT_NOVALUESTRING);
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

		//이동지시를 완료처리 해준다.
		CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_FINISH;
		TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

		DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 1.merge 여부가 Y인 경우 이동지시에 있는 lot list를 merge 한다.         
		if (CWIPLOTMVM.MERGE_FLAG == 'Y')
		{
			i_step = 2;

			//merge 대표 lot에 다른 lot을 모두 merge처리 한다. 
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			CWIPLOTMVR.MERGE_LOT_FLAG = 'Y';
			DBU_select_cwiplotmvr(2, &CWIPLOTMVR);
			if (DB_error_code == DB_SUCCESS)
			{
				//mergr lot을 조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
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

				DBU_init_cwiplotmvr(&CWIPLOTMVR);
				memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
				memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				DBU_open_cwiplotmvr(i_step, &CWIPLOTMVR);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "CWIPLOTMVR OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVR.FACTORY), &CWIPLOTMVR.FACTORY);
					TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVR.MOVE_ID), &CWIPLOTMVR.MOVE_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cwiplotmvr(i_step, &CWIPLOTMVR);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cwiplotmvr(i_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
						strcpy(s_msg_code, "WIP-0044");
						TRS.add_fieldmsg(out_node, "CWIPLOTMVR FETCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVR.FACTORY), &CWIPLOTMVR.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVR.MOVE_ID), &CWIPLOTMVR.MOVE_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cwiplotmvr(i_step);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//MERGE_FLAG가 'Y'인 경우 merge 대표 LOT에 merge 처리 한다.
					if (CWIPLOTMVR.MERGE_FLAG == 'Y')
					{
						//이동지시 LOT LIST를 각각 merge lot에 merge 시켜준다.
						merge_in = TRS.add_node(in_node, "merge_in");
						TRS.add_char(merge_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(merge_in, in_node);

						TRS.add_string(merge_in, "LOT_ID", CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
						TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_double(merge_in, "MOVE_QTY_1", CWIPLOTMVR.QTY);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
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

		i_step = 3;
		iCount = 0;
		memset(s_before_mat_id, ' ', sizeof(s_before_mat_id));

		//2. 변경 lot 정보를 move처리 한다. 
		DBU_init_cwiplotmvc(&CWIPLOTMVC);
		memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVC.FACTORY));
		memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVC.MOVE_ID));
		DBU_open_cwiplotmvc(i_step, &CWIPLOTMVC);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVC OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVC.FACTORY), &CWIPLOTMVC.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVC.MOVE_ID), &CWIPLOTMVC.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		while (1)
		{
			DBU_fetch_cwiplotmvc(i_step, &CWIPLOTMVC);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwiplotmvc(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVC.FACTORY), &CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVC.MOVE_ID), &CWIPLOTMVC.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cwiplotmvc(i_step);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			iCount++;

			//move처리할 lot 조회 
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

			//완제품 창고로 이동할 경우 lot이 테스트 품이면 이동 할 수 없다.
			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
			{
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_T)
				{
					//WIP-0686 : 테스트품은 제품창고로 이동할 수 없습니다. 양산품 전환 후 이동처리 하세요.
					strcpy(s_msg_code, "WIP-0686");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			if (memcmp(MWIPLOTSTSX.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
			{
				//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0648");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
				TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			/* STORE 모두 없엘예정....이것떄문에 창고이동 계속 꼬임.20220429*/
			//이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
			/*
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
			}
			*/

			/* STORE 모두 없엘예정....이것떄문에 창고이동 계속 꼬임.20220429*/
			//STORE 되어있는거는 현창고에서 Unstore되도록 수정 20220429./
			if (MWIPLOTSTSX.INV_FLAG == 'Y')
			{
				unstore_in = TRS.add_node(in_node, "unstore_in");
				TRS.add_char(unstore_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(unstore_in, in_node);

				TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.OPER));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}



			//move처리할 lot 조회 
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

			//품목정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}





			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				// 이동 시, FROM 창고가 완제품 창고라면, 포장 정보 확인.
				// 만약 포장 진행 중인 정보가 존재한다면, 해당 출하 LOT 분할 예정이기때문에, 
				// 이동을 하려면, 해당 LOT의 수량을 분할하여 분할된 LOT으로 이동해야됨. 
				DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
				TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
				memcpy(CPAKLOTSTS_COUNT.ORG_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				d_pack_sum_qty = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS_COUNT);

				if (d_pack_sum_qty > 0)
				{
					//WIP-0623 : 해당 Lot은 포장 진행중입니다. 이동을 원하신다면, Lot을 분할해주세요.
					strcpy(s_msg_code, "WIP-0623");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS_COUNT.FACTORY), CPAKLOTSTS_COUNT.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), CPAKLOTSTS_COUNT.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "QTY", MP_DBL, MWIPLOTSTSX.QTY_1);
					TRS.add_fieldmsg(out_node, "PACKING_QTY", MP_DBL, d_pack_sum_qty);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//제품 창고 -> 완제품 창고 이동 시, LOT_CMF_11 - GCM(C_INSP_JUDGE_LIST).DATA_7 = Y(C, P, S)인것만 가능(+ 공백도 가능)
			/*if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				&& memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0
				)
				*/
				
				/*
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0 && memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{

				if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0 || memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_PROTO_TYPE, strlen(MP_MAT_TYPE_PROTO_TYPE)) == 0)
				{

					DBU_init_mgcmtbldat(&MGCMTBLDAT_INSP);
					TRS.copy(MGCMTBLDAT_INSP.FACTORY, sizeof(MGCMTBLDAT_INSP.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_INSP.TABLE_NAME, MP_GCM_INSP_JUDGE_LIST, strlen(MP_GCM_INSP_JUDGE_LIST));
					memcpy(MGCMTBLDAT_INSP.KEY_1, MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));


					if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
					{
						i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
					}
					else
					{
						//일단 다른 사업부도 판정없으면 못나가게 막음..문제될지 안될지는.....
						i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
						//i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(3, &MGCMTBLDAT_INSP);
					}

					if (i_insp_move_flag == 0)
					{
						//WIP-0654 : 해당 Lot의 판정 값은 완제품 창고로 이동이 불가합니다.
						strcpy(s_msg_code, "WIP-0654");
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
						TRS.add_fieldmsg(out_node, "JUDGE", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_11), MWIPLOTSTSX.LOT_CMF_11);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}


			}
*/
			//제품 창고 -> 완제품 창고
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 완제품 창고로 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
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
			//제품 창고 -> 제품 창고
			//Store 모두 없엘거임.20220429

			/*
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				// TO 창고로 STORE
				store_in = TRS.add_node(in_node, "store_in");
				TRS.add_char(store_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(store_in, in_node);

				TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(store_in, "TO_OPER", CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
				TRS.add_string(store_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			*/
			//제품 창고 -> 제품 창고
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}



			//완제품, 반품 창고 -> 완제품 창고
			else if ((memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, strlen(MP_OPER_GRP_TYPE_RET)) == 0)
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 완제품 창고끼리 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}


			//완제품, 반품 창고 -> 제품 창고

			//Store 모두 없엘거임.20220429
			/*
			else if ((memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, strlen(MP_OPER_GRP_TYPE_RET)) == 0)
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				if (memcmp(MWIPLOTSTSX.OPER, MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.OPER)) != 0)
				{
					// 제품 창고로 이동
					move_in = TRS.add_node(in_node, "move_in");
					CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(move_in, "PROCSTEP", '2');
					TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(move_in, "TO_FLOW", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));
					TRS.add_string(move_in, "TO_OPER", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));
					TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
					TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}

				// TO 창고로 STORE
				store_in = TRS.add_node(in_node, "store_in");
				TRS.add_char(store_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(store_in, in_node);

				TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(store_in, "TO_OPER", CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
				TRS.add_string(store_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

			*/
			//완제품, 반품 창고 -> 제품 창고
			else if ((memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, strlen(MP_OPER_GRP_TYPE_RET)) == 0)
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}




			//P급 창고 -> P급 창고
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(7, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 또다른 P급 창고로 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
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

				if (CWIPLOTREC.DELETE_FLAG == 'Y')
				{
					//WIP-0642 : 해당 P급 Lot 정보는 이미 삭제되어 있습니다. 상태를 확인해주세요.
					strcpy(s_msg_code, "WIP-0642");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

					return MP_FALSE;
				}

				memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				DBU_update_cwiplotrec(4, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//그외
			else
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}






			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != 0)
			{
				//LOT이 생산품인 경우만 이동처리 인터페이스를 처리한다.   
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_P)
				{
					if (memcmp(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID)) != MP_FALSE)
					{
						DB_init_condition(&DBC_Q_COND);
						memcpy(DBC_Q_COND.KEY_1, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

						dSumQty = DBU_select_cwiplotmvc_scalar(3, &CWIPLOTMVC);
						dLotSumQty = DBU_select_cwiplotmvc_scalar(4, &CWIPLOTMVC);

						if (COM_dbl_round(dSumQty, 5, 'U') != COM_dbl_round(dLotSumQty, 5, 'U'))
						{
							//WIP-0676 : 이동지시 수량과 LOT의 수량이 다릅니다. 이동지시 수량을 확인하세요.
							strcpy(s_msg_code, "WIP-0676");
							TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

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
						TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
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
						TRS.add_double(erpif_in, "QTY", dSumQty);
						TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
						TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
						TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
						TRS.add_string(erpif_in, "MES_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));     //이동지시 번호

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
						memcpy(IF_INV_TXNS.MES_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
						d_inv_txns_id = DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

						memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					}

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
					TRS.add_string(erpif_in, "MES_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));     //이동지시 번호

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
		}
	}
	//step 4: 이동지시 등록 - CTM PRESS 
	/*
		=> CTM의 PRESS에서는 이동지시를 보낼 때 호기별, 제품별 이동지시를 따로 보낸다.
		   Client 에서 이동 리스트를 press 설비별, mat id 별로 order by를 한 뒤에 서버에 보내어
		   호기 또는 제품이 변경되는 시점에 이동지시번호를 각각 생성 해 준다.
	*/
	else if (TRS.get_procstep(in_node) == '4')
	{
		//FROM 창고 조회하여 FROM_SUB_AREA_ID, FROM_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER), in_node, "OPER");
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

		//TO 창고 조회하여 TO_SUB_AREA_ID, TO_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
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

		memset(s_Mat_id, ' ', sizeof(s_Mat_id));
		memset(s_Press_id, ' ', sizeof(s_Press_id));
		memset(s_Order_id, ' ', sizeof(s_Order_id));
		c_Change_yn = 'N';

		//이동지시 LOT LIST 저장
		Lot_tbl = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (int i = 0; i < i_lot_count; i++)
		{
			if (i == 0)
			{
				c_Change_yn = 'Y';
				TRS.copy(s_Mat_id, sizeof(s_Mat_id), Lot_tbl[i], "MAT_ID");
				TRS.copy(s_Press_id, sizeof(s_Press_id), Lot_tbl[i], "PRESS_RES_ID");
			}
			else
			{
				c_Change_yn = 'N';

				if (TRS.mem_cmp(Lot_tbl[i], "PRESS_RES_ID", s_Press_id, sizeof(s_Press_id)) != MP_FALSE)
				{
					c_Change_yn = 'Y';
					TRS.copy(s_Press_id, sizeof(s_Press_id), Lot_tbl[i], "PRESS_RES_ID");
				}
				if (TRS.mem_cmp(Lot_tbl[i], "MAT_ID", s_Mat_id, sizeof(s_Mat_id)) != MP_FALSE)
				{
					c_Change_yn = 'Y';
					TRS.copy(s_Mat_id, sizeof(s_Mat_id), Lot_tbl[i], "MAT_ID");
				}
			}

			if (c_Change_yn == 'Y')
			{
				memset(s_Order_id, ' ', sizeof(s_Order_id));

				if (COM_isnullspace(TRS.get_string(in_node, "MOVE_ID")) == MP_TRUE)
				{
					//이동지시 ID 발번 규칙을 셋업하여 찾아오도록 한다.
					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);
					TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_MOVE_ORDER, strlen(MP_ID_ROLE_WIP_MOVE_ORDER));
					TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "AREA_ID"));
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
					memcpy(s_Order_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
					TRS.free_node(cmn_out);
				}
				else
				{
					TRS.copy(s_Order_id, sizeof(s_Order_id), in_node, "MOVE_ID");
				}

				//이동지시 마스터 생성 및 업데이트
				DBU_init_cwiplotmvm(&CWIPLOTMVM);
				TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTMVM.MOVE_ID, s_Order_id, sizeof(CWIPLOTMVM.MOVE_ID));
				DBU_select_cwiplotmvm(1, &CWIPLOTMVM);

				if (DB_error_code == DB_SUCCESS)
				{
					DBU_init_mwiplotstsx(&MWIPLOTSTSX);
					TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

					DBU_init_mwiplothisx(&MWIPLOTHISX);
					memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					MWIPLOTHISX.HIST_SEQ = 1;
					DBU_select_mwiplothisx(1, &MWIPLOTHISX);

					memcpy(CWIPLOTMVM.CMF_1, s_Press_id, sizeof(s_Press_id));
					memcpy(CWIPLOTMVM.CMF_2, s_Mat_id, sizeof(s_Mat_id));
					memcpy(CWIPLOTMVM.CMF_3, MWIPLOTHISX.TRAN_CMF_1, sizeof(MWIPLOTHISX.TRAN_CMF_1));

					if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
					{
						//WIP-0560 : 완료된 이동지시는 수정할 수 없습니다.
						strcpy(s_msg_code, "WIP-0560");
						TRS.add_fieldmsg(out_node, "CWIPLOTMVM", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
						TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(CWIPLOTMVM.MOVE_STATUS), CWIPLOTMVM.MOVE_STATUS);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					memcpy(CWIPLOTMVM.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
					memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
					memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
					TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));
					CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");

					DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					/* 이동지시 LOT LIST를 삭제 한다.
					=> 이동지시 리스트의 변동이 있을겨우 전부 삭제 후 다시 저장한다. */
					//CWIPLOTMVR에 저장되었던 lot list를 지운다.
					DBU_init_cwiplotmvr(&CWIPLOTMVR);
					memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
					memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
					DBU_delete_cwiplotmvr(2, &CWIPLOTMVR);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPLOTMVR DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
							TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					//이동지시 변경이동 lot list 를 삭제한다. 
					//CWIPLOTMVC에 저장되었던 lot list를 지운다.
					DBU_init_cwiplotmvc(&CWIPLOTMVC);
					memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
					memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
					DBU_delete_cwiplotmvc(2, &CWIPLOTMVC);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPLOTMVC DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
							TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}
				}
				else if (DB_error_code == DB_NOT_FOUND)
				{

					DBU_init_mwiplotstsx(&MWIPLOTSTSX);
					TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

					DBU_init_mwiplothisx(&MWIPLOTHISX);
					memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					MWIPLOTHISX.HIST_SEQ = 1;
					DBU_select_mwiplothisx(1, &MWIPLOTHISX);

					memcpy(CWIPLOTMVM.CMF_1, s_Press_id, sizeof(s_Press_id));
					memcpy(CWIPLOTMVM.CMF_2, s_Mat_id, sizeof(s_Mat_id));
					memcpy(CWIPLOTMVM.CMF_3, MWIPLOTHISX.TRAN_CMF_1, sizeof(MWIPLOTHISX.TRAN_CMF_1));

					memcpy(CWIPLOTMVM.FROM_AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
					memcpy(CWIPLOTMVM.FROM_SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
					memcpy(CWIPLOTMVM.FROM_OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
					memcpy(CWIPLOTMVM.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
					memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
					memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
					CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");
					CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_START;
					TRS.copy(CWIPLOTMVM.CREATE_USER_ID, sizeof(CWIPLOTMVM.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTMVM.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.CREATE_TIME));
					TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

					DBU_insert_cwiplotmvm(&CWIPLOTMVM);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTMVM INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}

				//move id를 out node에 넣어준다.
				list_item = TRS.add_node(out_node, "MOVE_LIST");
				TRS.add_string(list_item, "MOVE_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			}

			// 이동될 lot 이 선택공정 (from)과 같은지 여부 체크
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_EA);
			TRS.copy(MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID), Lot_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_EA);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_EA.FACTORY), MWIPLOTSTSX_EA.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;




			}

			//P급인지 체크
			DBU_init_cwiplotrec(&CWIPLOTREC);
			memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(MWIPLOTSTSX_EA.FACTORY));
			memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID));
			DBU_select_cwiplotrec(2, &CWIPLOTREC);
			if (DB_error_code == DB_SUCCESS)
			{

				/*
				//WIP-0667 : P급은 외주 출고를 할 수 없습니다. LOT상태를 확인하세요.
				strcpy(s_msg_code, "WIP-0667");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
				*/


				//29221228 리턴하다가 누락되거나 어쩌다 보니 계속 P급 리스트에 남아있는경우 있어서 그냥 있으면 Del 시켜버리도록 수정(어차피 창고이동 하는 상태이면 P급 아닌상태임)

				CWIPLOTREC.DELETE_FLAG = 'Y';
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));

				DBU_update_cwiplotrec(4, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					TRS.add_fieldmsg(out_node, "CWIPLOTREC Delete 1", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

					return MP_FALSE;
				}
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
			{
				//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0648");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == MP_FALSE)
			{
				//WIP-0679 : 입고 공정과 LOT의 공정이 같습니다. LOT의 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0679");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//완제품 창고로 이동할 경우 lot이 테스트 품이면 이동 할 수 없다.
			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
			{
				if (MWIPLOTSTSX_EA.LOT_TYPE == MP_LOT_TYPE_T)
				{
					//WIP-0686 : 테스트품은 제품창고로 이동할 수 없습니다. 양산품 전환 후 이동처리 하세요.
					strcpy(s_msg_code, "WIP-0686");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//이동지시 확정이 안된 LOT은 작업을 진행 할 수 없다.            
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
			memcpy(CWIPLOTMVR.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
			iCount = (int)DBU_select_cwiplotmvr_scalar(4, &CWIPLOTMVR);
			if (iCount > 0)
			{
				//WIP-0673 :이 LOT은 이미 "OPEN" 상태의 다른 이동지시번호가 존재합니다.
				strcpy(s_msg_code, "WIP-0673");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			TRS.copy(CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID), Lot_tbl[i], "LOT_ID");
			CWIPLOTMVR.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVR.QTY = TRS.get_double(Lot_tbl[i], "QTY");
			CWIPLOTMVR.MERGE_FLAG = CWIPLOTMVM.MERGE_FLAG;
			CWIPLOTMVR.MERGE_LOT_FLAG = TRS.get_char(Lot_tbl[i], "MERGE_LOT_FLAG");
			TRS.copy(CWIPLOTMVR.CREATE_USER_ID, sizeof(CWIPLOTMVR.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.CREATE_TIME));
			TRS.copy(CWIPLOTMVR.UPDATE_USER_ID, sizeof(CWIPLOTMVR.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.UPDATE_TIME));

			DBU_insert_cwiplotmvr(&CWIPLOTMVR);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cwiplotmvc(&CWIPLOTMVC);
			memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVR.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
			memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			memcpy(CWIPLOTMVC.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
			CWIPLOTMVC.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVC.QTY = CWIPLOTMVR.QTY;
			TRS.copy(CWIPLOTMVC.CREATE_USER_ID, sizeof(CWIPLOTMVC.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.CREATE_TIME));
			TRS.copy(CWIPLOTMVC.UPDATE_USER_ID, sizeof(CWIPLOTMVC.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.UPDATE_TIME));

			DBU_insert_cwiplotmvc(&CWIPLOTMVC);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVC.LOT_ID), CWIPLOTMVC.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}

	/* 이동지시 등록과 확정이 동시에 */
	else if (TRS.get_procstep(in_node) == '5')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "MOVE_ID")) == MP_TRUE)
		{
			memset(s_Order_id, ' ', sizeof(s_Order_id));

			//이동지시 ID 발번 규칙을 셋업하여 찾아오도록 한다.
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			TRS.add_char(gen_in_node, "PROCSTEP", '2');
			CopyDefaultMembers(gen_in_node, in_node);
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_MOVE_ORDER, strlen(MP_ID_ROLE_WIP_MOVE_ORDER));
			TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "AREA_ID"));
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
			memcpy(s_Order_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
			TRS.free_node(cmn_out);
		}
		else
		{
			TRS.copy(s_Order_id, sizeof(s_Order_id), in_node, "MOVE_ID");
		}

		//FROM 창고 조회하여 FROM_SUB_AREA_ID, FROM_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER), in_node, "OPER");
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

		//TO 창고 조회하여 TO_SUB_AREA_ID, TO_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
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

		//이동지시 마스터 생성 및 업데이트
		DBU_init_cwiplotmvm(&CWIPLOTMVM);
		TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPLOTMVM.MOVE_ID, s_Order_id, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code == DB_SUCCESS)
		{
			if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
			{
				//WIP-0560 : 완료된 이동지시는 수정할 수 없습니다.
				strcpy(s_msg_code, "WIP-0560");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(CWIPLOTMVM.MOVE_STATUS), CWIPLOTMVM.MOVE_STATUS);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//이동지시를 수정할 수 없는 공정인 경우 수정할 수 없다. 
			//GCM 셋업 C_MOVE_OPTION
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, "C_MOVE_OPTION", strlen("C_MOVE_OPTION"));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code == DB_SUCCESS)
			{
				if (MGCMTBLDAT.DATA_3[0] == 'Y')
				{
					//WIP-0688 : 선택된 공정에서는 이동지시를 수정 할 수 없습니다.
					strcpy(s_msg_code, "WIP-0688");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}

			TRS.copy(CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID), in_node, "AREA_ID");
			memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			//TRS.copy(CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID), in_node, "TO_SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER), in_node, "TO_OPER");
			TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));
			CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");

			DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		else if (DB_error_code == DB_NOT_FOUND)
		{
			memcpy(CWIPLOTMVM.FROM_AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			memcpy(CWIPLOTMVM.FROM_SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.FROM_OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
			//TRS.copy(CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID), in_node, "AREA_ID");
			//TRS.copy(CWIPLOTMVM.FROM_SUB_AREA_ID, sizeof(CWIPLOTMVM.FROM_SUB_AREA_ID), in_node, "SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.FROM_OPER, sizeof(CWIPLOTMVM.FROM_OPER), in_node, "OPER");
			//TO_AREA_ID는 같은 사업부 내에서만 이동할 수 있도록 함
			memcpy(CWIPLOTMVM.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			memcpy(CWIPLOTMVM.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(CWIPLOTMVM.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			//TRS.copy(CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID), in_node, "AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID), in_node, "TO_SUB_AREA_ID");
			//TRS.copy(CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER), in_node, "TO_OPER");

			CWIPLOTMVM.MERGE_FLAG = TRS.get_char(in_node, "MERGE_YN");
			//memcpy(CWIPLOTMVM.MOVE_STATUS, MP_CWIP_ORDER_START, strlen(MP_CWIP_ORDER_START));
			CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_START;
			TRS.copy(CWIPLOTMVM.CREATE_USER_ID, sizeof(CWIPLOTMVM.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.CREATE_TIME));
			TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

			DBU_insert_cwiplotmvm(&CWIPLOTMVM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		/* 이동지시 LOT LIST를 삭제 한다.
			=> 이동지시 리스트의 변동이 있을겨우 전부 삭제 후 다시 저장한다. */
			//CWIPLOTMVR에 저장되었던 lot list를 지운다.
		DBU_init_cwiplotmvr(&CWIPLOTMVR);
		memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
		memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_delete_cwiplotmvr(2, &CWIPLOTMVR);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//이동지시 변경이동 lot list 를 삭제한다. 
		//CWIPLOTMVC에 저장되었던 lot list를 지운다.
		DBU_init_cwiplotmvc(&CWIPLOTMVC);
		memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
		memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		DBU_delete_cwiplotmvc(2, &CWIPLOTMVC);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//이동지시 LOT LIST 저장
		Lot_tbl = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (int i = 0; i < i_lot_count; i++)
		{
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				// 이동 시, FROM 창고가 완제품 창고라면, 포장 정보 확인.
				// 만약 포장 진행 중인 정보가 존재한다면, 해당 출하 LOT 분할 예정이기때문에, 
				// 이동을 하려면, 해당 LOT의 수량을 분할하여 분할된 LOT으로 이동해야됨. 
				DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
				TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CPAKLOTSTS_COUNT.ORG_LOT_ID, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), Lot_tbl[i], "LOT_ID");
				d_pack_sum_qty = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS_COUNT);

				if (d_pack_sum_qty > 0)
				{
					//WIP-0623 : 해당 Lot은 포장 진행중입니다. 이동을 원하신다면, Lot을 분할해주세요.
					strcpy(s_msg_code, "WIP-0623");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS_COUNT.FACTORY), CPAKLOTSTS_COUNT.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), CPAKLOTSTS_COUNT.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "QTY", MP_DBL, TRS.get_double(Lot_tbl[i], "QTY"));
					TRS.add_fieldmsg(out_node, "PACKING_QTY", MP_DBL, d_pack_sum_qty);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			// 이동될 lot 이 선택공정 (from)과 같은지 여부 체크
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_EA);
			TRS.copy(MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID), Lot_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_EA);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_EA.FACTORY), MWIPLOTSTSX_EA.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//완제품 창고로 이동할 경우 lot이 테스트 품이면 이동 할 수 없다.
			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
			{
				if (MWIPLOTSTSX_EA.LOT_TYPE == MP_LOT_TYPE_T)
				{
					//WIP-0686 : 테스트품은 제품창고로 이동할 수 없습니다. 양산품 전환 후 이동처리 하세요.
					strcpy(s_msg_code, "WIP-0686");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//LOSS -> LOSS 창고 이동의 경우 P급 체크 VALIDATION을 하지 않음.
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0)
			{
			}
			else
			{
				//P급인지 체크
				DBU_init_cwiplotrec(&CWIPLOTREC);
				memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(MWIPLOTSTSX_EA.FACTORY));
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(MWIPLOTSTSX_EA.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);
				if (DB_error_code == DB_SUCCESS)
				{

					/*
					//WIP-0667 : P급은 외주 출고를 할 수 없습니다. LOT상태를 확인하세요.
					strcpy(s_msg_code, "WIP-0667");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
					*/
					//29221228 리턴하다가 누락되거나 어쩌다 보니 계속 P급 리스트에 남아있는경우 있어서 그냥 있으면 Del 시켜버리도록 수정(어차피 창고이동 하는 상태이면 P급 아닌상태임)

					CWIPLOTREC.DELETE_FLAG = 'Y';
					TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));

					DBU_update_cwiplotrec(4, &CWIPLOTREC);
					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
					{
						TRS.add_fieldmsg(out_node, "CWIPLOTREC Delete 1", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

						return MP_FALSE;
					}

				}
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
			{
				//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0648");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPLOTSTSX_EA.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == MP_FALSE)
			{
				//WIP-0679 : 입고 공정과 LOT의 공정이 같습니다. LOT의 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0679");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_EA.OPER), MWIPLOTSTSX_EA.OPER);
				TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//이동지시 확정이 안된 LOT은 작업을 진행 할 수 없다.            
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
			memcpy(CWIPLOTMVR.LOT_ID, MWIPLOTSTSX_EA.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
			iCount = (int)DBU_select_cwiplotmvr_scalar(4, &CWIPLOTMVR);
			if (iCount > 0)
			{
				//WIP-0673 :이 LOT은 이미 "OPEN" 상태의 다른 이동지시번호가 존재합니다.
				strcpy(s_msg_code, "WIP-0673");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}


			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX_EA.FACTORY, sizeof(MWIPLOTSTSX_EA.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX_EA.MAT_ID, sizeof(MWIPLOTSTSX_EA.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(10) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 창고 -> 완제품 창고 이동 시, LOT_CMF_11 - GCM(C_INSP_JUDGE_LIST).DATA_7 = Y(C, P, S)인것만 가능(+ 공백도 가능),
			//20231018 제품반 검사판정 체크
			
			/*
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				&& memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0)
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT_INSP);
				TRS.copy(MGCMTBLDAT_INSP.FACTORY, sizeof(MGCMTBLDAT_INSP.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_INSP.TABLE_NAME, MP_GCM_INSP_JUDGE_LIST, strlen(MP_GCM_INSP_JUDGE_LIST));
				memcpy(MGCMTBLDAT_INSP.KEY_1, MWIPLOTSTSX_EA.LOT_CMF_11, sizeof(MWIPLOTSTSX_EA.LOT_CMF_11));

				if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
				{
					i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
				}
				else
				{
					i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(3, &MGCMTBLDAT_INSP);
				}


				if (i_insp_move_flag == 0)
				{
					//WIP-0654 : 해당 Lot의 판정 값은 완제품 창고로 이동이 불가합니다.
					strcpy(s_msg_code, "WIP-0654");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_ID), MWIPLOTSTSX_EA.LOT_ID);
					TRS.add_fieldmsg(out_node, "JUDGE", MP_STR, sizeof(MWIPLOTSTSX_EA.LOT_CMF_11), MWIPLOTSTSX_EA.LOT_CMF_11);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			*/

			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			TRS.copy(CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID), Lot_tbl[i], "LOT_ID");
			CWIPLOTMVR.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVR.QTY = TRS.get_double(Lot_tbl[i], "QTY");
			CWIPLOTMVR.MERGE_FLAG = CWIPLOTMVM.MERGE_FLAG;
			CWIPLOTMVR.MERGE_LOT_FLAG = TRS.get_char(Lot_tbl[i], "MERGE_LOT_FLAG");
			TRS.copy(CWIPLOTMVR.CREATE_USER_ID, sizeof(CWIPLOTMVR.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.CREATE_TIME));
			TRS.copy(CWIPLOTMVR.UPDATE_USER_ID, sizeof(CWIPLOTMVR.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVR.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVR.UPDATE_TIME));

			DBU_insert_cwiplotmvr(&CWIPLOTMVR);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MERGE_FLAG 가 'Y'가 아닌경우 이동지시 LOT LIST 는 이동지시 확정 LOT LIST와 동일하다.
			if (CWIPLOTMVM.MERGE_FLAG != 'Y')
			{
				DBU_init_cwiplotmvc(&CWIPLOTMVC);
				memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVR.FACTORY, sizeof(CWIPLOTMVR.FACTORY));
				memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				memcpy(CWIPLOTMVC.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
				CWIPLOTMVC.HIST_SEQ = MWIPLOTSTSX_EA.LAST_ACTIVE_HIST_SEQ;
				CWIPLOTMVC.QTY = CWIPLOTMVR.QTY;
				TRS.copy(CWIPLOTMVC.CREATE_USER_ID, sizeof(CWIPLOTMVC.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTMVC.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.CREATE_TIME));
				TRS.copy(CWIPLOTMVC.UPDATE_USER_ID, sizeof(CWIPLOTMVC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTMVC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.UPDATE_TIME));

				DBU_insert_cwiplotmvc(&CWIPLOTMVC);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTMVC INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
					TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVC.LOT_ID), CWIPLOTMVC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		if (CWIPLOTMVM.MERGE_FLAG == 'Y')
		{
			//merge 대표 lot에 다른 lot을 모두 merge처리 할 수량이 들어간다. 
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			CWIPLOTMVR.MERGE_LOT_FLAG = 'Y';
			DBU_select_cwiplotmvr(2, &CWIPLOTMVR);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVR INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVR.FACTORY), CWIPLOTMVR.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVR.MOVE_ID), CWIPLOTMVR.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVR.LOT_ID), CWIPLOTMVR.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MERGE 대상 LOT의 QTY값 SUM
			dSumQty = DBU_select_cwiplotmvr_scalar(2, &CWIPLOTMVR);

			//mergr lot을 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
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

			DBU_init_cwiplotmvc(&CWIPLOTMVC);
			memcpy(CWIPLOTMVC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			memcpy(CWIPLOTMVC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			CWIPLOTMVC.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			CWIPLOTMVC.QTY = dSumQty;
			TRS.copy(CWIPLOTMVC.CREATE_USER_ID, sizeof(CWIPLOTMVC.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.CREATE_TIME));
			TRS.copy(CWIPLOTMVC.UPDATE_USER_ID, sizeof(CWIPLOTMVC.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTMVC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVC.UPDATE_TIME));

			DBU_insert_cwiplotmvc(&CWIPLOTMVC);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTMVC.LOT_ID), CWIPLOTMVC.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//move id를 out node에 넣어준다.
		TRS.add_string(out_node, "MOVE_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));


		////////////여기가지가 등록//////////////////////////////////////////////////////////		











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

		//이동지시를 완료처리 해준다.
		CWIPLOTMVM.MOVE_STATUS[0] = MP_CWIP_ORDER_FINISH;
		TRS.copy(CWIPLOTMVM.UPDATE_USER_ID, sizeof(CWIPLOTMVM.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CWIPLOTMVM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTMVM.UPDATE_TIME));

		DBU_update_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM UPDATE", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 1.merge 여부가 Y인 경우 이동지시에 있는 lot list를 merge 한다.         
		if (CWIPLOTMVM.MERGE_FLAG == 'Y')
		{
			i_step = 2;

			//merge 대표 lot에 다른 lot을 모두 merge처리 한다. 
			DBU_init_cwiplotmvr(&CWIPLOTMVR);
			memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
			memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			CWIPLOTMVR.MERGE_LOT_FLAG = 'Y';
			DBU_select_cwiplotmvr(2, &CWIPLOTMVR);
			if (DB_error_code == DB_SUCCESS)
			{
				//mergr lot을 조회한다.
				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
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

				DBU_init_cwiplotmvr(&CWIPLOTMVR);
				memcpy(CWIPLOTMVR.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY));
				memcpy(CWIPLOTMVR.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				DBU_open_cwiplotmvr(i_step, &CWIPLOTMVR);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "CWIPLOTMVR OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVR.FACTORY), &CWIPLOTMVR.FACTORY);
					TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVR.MOVE_ID), &CWIPLOTMVR.MOVE_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cwiplotmvr(i_step, &CWIPLOTMVR);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cwiplotmvr(i_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
						strcpy(s_msg_code, "WIP-0044");
						TRS.add_fieldmsg(out_node, "CWIPLOTMVR FETCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVR.FACTORY), &CWIPLOTMVR.FACTORY);
						TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVR.MOVE_ID), &CWIPLOTMVR.MOVE_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cwiplotmvr(i_step);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//MERGE_FLAG가 'Y'인 경우 merge 대표 LOT에 merge 처리 한다.
					if (CWIPLOTMVR.MERGE_FLAG == 'Y')
					{
						//이동지시 LOT LIST를 각각 merge lot에 merge 시켜준다.
						merge_in = TRS.add_node(in_node, "merge_in");
						TRS.add_char(merge_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(merge_in, in_node);

						TRS.add_string(merge_in, "LOT_ID", CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID));
						TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_double(merge_in, "MOVE_QTY_1", CWIPLOTMVR.QTY);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
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

		i_step = 3;
		iCount = 0;
		memset(s_before_mat_id, ' ', sizeof(s_before_mat_id));

		//2. 변경 lot 정보를 move처리 한다. 
		DBU_init_cwiplotmvc(&CWIPLOTMVC);
		memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVC.FACTORY));
		memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVC.MOVE_ID));
		DBU_open_cwiplotmvc(i_step, &CWIPLOTMVC);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVC OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVC.FACTORY), &CWIPLOTMVC.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVC.MOVE_ID), &CWIPLOTMVC.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		while (1)
		{
			DBU_fetch_cwiplotmvc(i_step, &CWIPLOTMVC);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwiplotmvc(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(&CWIPLOTMVC.FACTORY), &CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(&CWIPLOTMVC.MOVE_ID), &CWIPLOTMVC.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cwiplotmvc(i_step);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			iCount++;

			//move처리할 lot 조회 
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

			//완제품 창고로 이동할 경우 lot이 테스트 품이면 이동 할 수 없다.
			if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
			{
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_T)
				{
					//WIP-0686 : 테스트품은 제품창고로 이동할 수 없습니다. 양산품 전환 후 이동처리 하세요.
					strcpy(s_msg_code, "WIP-0686");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			if (memcmp(MWIPLOTSTSX.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
			{
				//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0648");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
				TRS.add_fieldmsg(out_node, "FROM_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			/* STORE 모두 없엘예정....이것떄문에 창고이동 계속 꼬임.20220429*/
			//이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
			/*
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
			}
			*/

			/* STORE 모두 없엘예정....이것떄문에 창고이동 계속 꼬임.20220429*/
			//STORE 되어있는거는 현창고에서 Unstore되도록 수정 20220429./
			if (MWIPLOTSTSX.INV_FLAG == 'Y')
			{
				unstore_in = TRS.add_node(in_node, "unstore_in");
				TRS.add_char(unstore_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(unstore_in, in_node);

				TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.OPER));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}



			//move처리할 lot 조회 
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

			//품목정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0006 : 이 제품은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}





			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				// 이동 시, FROM 창고가 완제품 창고라면, 포장 정보 확인.
				// 만약 포장 진행 중인 정보가 존재한다면, 해당 출하 LOT 분할 예정이기때문에, 
				// 이동을 하려면, 해당 LOT의 수량을 분할하여 분할된 LOT으로 이동해야됨. 
				DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
				TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
				memcpy(CPAKLOTSTS_COUNT.ORG_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				d_pack_sum_qty = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS_COUNT);

				if (d_pack_sum_qty > 0)
				{
					//WIP-0623 : 해당 Lot은 포장 진행중입니다. 이동을 원하신다면, Lot을 분할해주세요.
					strcpy(s_msg_code, "WIP-0623");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS_COUNT.FACTORY), CPAKLOTSTS_COUNT.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), CPAKLOTSTS_COUNT.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "QTY", MP_DBL, MWIPLOTSTSX.QTY_1);
					TRS.add_fieldmsg(out_node, "PACKING_QTY", MP_DBL, d_pack_sum_qty);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//제품 창고 -> 완제품 창고 이동 시, LOT_CMF_11 - GCM(C_INSP_JUDGE_LIST).DATA_7 = Y(C, P, S)인것만 가능(+ 공백도 가능)
			/*
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				&& memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0
				)
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT_INSP);
				TRS.copy(MGCMTBLDAT_INSP.FACTORY, sizeof(MGCMTBLDAT_INSP.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_INSP.TABLE_NAME, MP_GCM_INSP_JUDGE_LIST, strlen(MP_GCM_INSP_JUDGE_LIST));
				memcpy(MGCMTBLDAT_INSP.KEY_1, MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));

				//20250424 CTM은 공백막음.
				if (memcmp(MWIPOPRDEF_FROM.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
				{
					i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
				}
				else
				{
					i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(3, &MGCMTBLDAT_INSP);
				}

				if (i_insp_move_flag == 0)
				{
					//WIP-0654 : 해당 Lot의 판정 값은 완제품 창고로 이동이 불가합니다.
					strcpy(s_msg_code, "WIP-0654");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_fieldmsg(out_node, "JUDGE", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_11), MWIPLOTSTSX.LOT_CMF_11);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			*/

			//제품 창고 -> 완제품 창고
			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 완제품 창고로 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
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
			//제품 창고 -> 제품 창고
			//Store 모두 없엘거임.20220429

			/*
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				// TO 창고로 STORE
				store_in = TRS.add_node(in_node, "store_in");
				TRS.add_char(store_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(store_in, in_node);

				TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(store_in, "TO_OPER", CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
				TRS.add_string(store_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			*/
			//제품 창고 -> 제품 창고
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}



			//완제품, 반품 창고 -> 완제품 창고
			else if ((memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, strlen(MP_OPER_GRP_TYPE_RET)) == 0)
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 완제품 창고끼리 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}


			//완제품, 반품 창고 -> 제품 창고
			else if ((memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == 0
				|| memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, strlen(MP_OPER_GRP_TYPE_RET)) == 0)
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_OPER, strlen(MP_OPER_GRP_TYPE_OPER)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}




			//P급 창고 -> P급 창고
			else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0)
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(7, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// 또다른 P급 창고로 MOVE
				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '1');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
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

				if (CWIPLOTREC.DELETE_FLAG == 'Y')
				{
					//WIP-0642 : 해당 P급 Lot 정보는 이미 삭제되어 있습니다. 상태를 확인해주세요.
					strcpy(s_msg_code, "WIP-0642");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

					return MP_FALSE;
				}

				memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				DBU_update_cwiplotrec(4, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//그외
			else
			{
				DBU_init_mwipflwopr(&MWIPFLWOPR);
				TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}


				move_in = TRS.add_node(in_node, "move_in");
				CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(move_in, "PROCSTEP", '4');
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
				TRS.add_string(move_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}






			if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != 0
				&& memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != 0)
			{
				//LOT이 생산품인 경우만 이동처리 인터페이스를 처리한다.   
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_P)
				{
					if (memcmp(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID)) != MP_FALSE)
					{
						DB_init_condition(&DBC_Q_COND);
						memcpy(DBC_Q_COND.KEY_1, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

						dSumQty = DBU_select_cwiplotmvc_scalar(3, &CWIPLOTMVC);
						dLotSumQty = DBU_select_cwiplotmvc_scalar(4, &CWIPLOTMVC);

						if (COM_dbl_round(dSumQty, 5, 'U') != COM_dbl_round(dLotSumQty, 5, 'U'))
						{
							//WIP-0676 : 이동지시 수량과 LOT의 수량이 다릅니다. 이동지시 수량을 확인하세요.
							strcpy(s_msg_code, "WIP-0676");
							TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

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
						TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
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
						TRS.add_double(erpif_in, "QTY", dSumQty);
						TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
						TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
						TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
						TRS.add_string(erpif_in, "MES_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));     //이동지시 번호

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
						memcpy(IF_INV_TXNS.MES_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
						d_inv_txns_id = DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

						memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					}

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
					TRS.add_string(erpif_in, "MES_ID", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));     //이동지시 번호

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
		}




	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Move_Lot_Order_Validation()
- Validation Check sub function of "CUS_WIP_MOVE_LOT_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Move_Lot_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP VALIDATION
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"1234") == MP_FALSE)
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
