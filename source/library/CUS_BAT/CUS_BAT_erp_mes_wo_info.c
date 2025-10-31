/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_wo_info.c
Description : ERP -> MES Work Order 정보

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/22  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAT_common.h"

int CUS_BAT_ERP_MES_WO_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Wo_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Wo_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_WO_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Wo_Info", out_node);


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
CUS_BAT_ERP_MES_WO_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Wo_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_WO_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_WO_INFO_TAG IF_WO_INFO;
	struct IF_WO_INFO_HIS_TAG IF_WO_INFO_HIS;
	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MWIPFLWDEF_TAG MWIPFLWDEF;
	struct CWIPERPOPR_TAG CWIPERPOPR;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPMATFLW_TAG MWIPMATFLW;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MINVDLVDTL_TAG MINVDLVDTL;

	TRSNode	*tran_in_node;


	TRSNode	*tran_out_node;

	TRSNode *Flow_in_node;
	TRSNode *Flow_out_node;

	int i_step = 0;
	int i_force_send_history = 0;
	char procStep;
	char erp_order_id[30];
	char inv_oper[11];
	char sub_area_id[21];
	char Error_Msg[201];
	char po_dis_id[30];

	LOG_head("CUS_BAT_Erp_Mes_Wo_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_wo_info(&IF_WO_INFO);
	DBU_open_if_wo_info(i_step, &IF_WO_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WO_INFO.FACTORY), IF_WO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WO_INFO.ORG_CODE), IF_WO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_WO_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_WO_INFO.WIP_ENTITY_NAME), IF_WO_INFO.WIP_ENTITY_NAME);
			
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_wo_info(i_step, &IF_WO_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_wo_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WO_INFO.FACTORY), IF_WO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WO_INFO.ORG_CODE), IF_WO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_WO_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_WO_INFO.WIP_ENTITY_NAME), IF_WO_INFO.WIP_ENTITY_NAME);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		i_force_send_history = 0;

		// ERP 에서 UNRELEASE 상태로 오는 것은 무조건 무시한다.
		if (IF_WO_INFO.STATUS_TYPE == 1)
		{
			DB_rollback();

			strcpy(s_msg_code, "IFS-0005");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_INFO.IF_CODE = 'E';
			memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
			DBU_update_if_wo_info(101, &IF_WO_INFO);
			DB_commit();
			continue;
		}

		DBU_init_mwipordsts(&MWIPORDSTS);
		memcpy(MWIPORDSTS.FACTORY, IF_WO_INFO.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(MWIPORDSTS.ORDER_ID, IF_WO_INFO.WIP_ENTITY_NAME, sizeof(MWIPORDSTS.ORDER_ID));
		
		DBU_select_mwipordsts(1, &MWIPORDSTS);

		if (DB_error_code == DB_NOT_FOUND)
		{
			//CREATE
			procStep = MP_STEP_CREATE;
		}
		else
		{
			// 작업지시 상태가 W:Wait 상태 인 경우에만 처리한다.
			// 다 처리하는 것으로 변경
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_ORD_STATUS_WAIT)
			{
				procStep = MP_STEP_UPDATE;
			}

			// 작업지시 상태가 O:Open 상태인 경우 상태값 업데이트만 한다. (추가 실적 처리 방지)
		
			else if (MWIPORDSTS.ORD_STATUS_FLAG == MP_ORD_STATUS_OPEN) {

				procStep = MP_STEP_UPDATE;
				// ERP ORDER STATUS
				//4	Complete
				//3	Released
				//12	Closed
				//7	Cancelled
				//1	Unreleased

				// MES ORDER STATUS
				//C	Close
				//D	Delete or Cancel
				//F	Finish
				//O	Open
				//W	Wait

				// W = 3, 4 = F, 12 = C, 7 = D

				if (IF_WO_INFO.STATUS_TYPE == 3)
				{
					MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_OPEN;
				}

				if (IF_WO_INFO.STATUS_TYPE == 4)
				{
					MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_FINISH;
				}
				else if (IF_WO_INFO.STATUS_TYPE == 12)
				{
					MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_CLOSE;
				}
				else if (IF_WO_INFO.STATUS_TYPE == 7)
				{
					MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_DELETE_OR_CANCEL;
				}


				//20240610 erp 상태 릴리즈인경우는 변경가능하도록 업데이트 가능하도록 ,..(베트남 외주떔시<오더수량이랑,PO수량들이 바뀜수정해야됨>)
				MWIPORDSTS.QTY = IF_WO_INFO.PLAN_QTY;
				memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
				memcpy(MWIPORDSTS.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
				DBU_update_mwipordsts(3, &MWIPORDSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "ORD-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_INFO.IF_CODE = 'E';
					memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
					DBU_update_if_wo_info(101, &IF_WO_INFO);
					DB_commit();
					continue;
				}

				// 상태 업데이트 하고 이력으로 처리
				i_force_send_history = 1;
			}
			else {
				// 상태 맞지 않는 걸로 너무 많이 에러가 남아서 에러 표기하고 HIS 로 빼버림
				strcpy(s_msg_code, "ORD-0027");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WO_INFO.IF_CODE = 'E';
				memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
				i_force_send_history = 1;
			}
		}

		tran_in_node = TRS.create_node("UPDATE_ORDERL_IN");
		tran_out_node = TRS.create_node("CMN_OUT");

		if (i_force_send_history == 0)
		{
			// 필수
			// FACTORY, ORDER_ID, MAT_ID, MAT_VER, FLOW, FLOW_SEQ_NUM, ORD_QTY, QTY, LOT_TYPE, QTY, OWNER_CODE, CREATE_CODE

			TRS.set_string(tran_in_node, "FACTORY", IF_WO_INFO.FACTORY, sizeof(IF_WO_INFO.FACTORY));
			TRS.set_char(tran_in_node, "PROCSTEP", procStep);
			TRS.set_string(tran_in_node, "ORDER_ID", IF_WO_INFO.WIP_ENTITY_NAME, sizeof(MWIPORDSTS.ORDER_ID));

			TRS.set_char(tran_in_node, "LOT_TYPE", MP_LOT_TYPE_PROD);
			TRS.set_double(tran_in_node, "QTY", 0);

			TRS.set_string(tran_in_node, "OWNER_CODE", MP_OWNER_CODE_PROD, strlen(MP_OWNER_CODE_PROD));
			TRS.set_string(tran_in_node, "CREATE_CODE", MP_CREATE_CODE_PROD, strlen(MP_CREATE_CODE_PROD));

			TRS.set_char(tran_in_node, "LOT_PRIORITY", '1');

			TRS.set_string(tran_in_node, "PLAN_START_TIME", IF_WO_INFO.PLAN_START_DATE, sizeof(IF_WO_INFO.PLAN_START_DATE));
			TRS.set_string(tran_in_node, "PLAN_END_TIME", IF_WO_INFO.PLAN_END_DATE, sizeof(IF_WO_INFO.PLAN_END_DATE));

			// RELEASE DATE 로 일단 WORK DATE 설정
			TRS.set_string(tran_in_node, "WORK_DATE", IF_WO_INFO.RELEASED_DATE, 8);

			// 표준 작업지시 여부 체크해서 표준이면 ORD_CMF_7 = 'Y'
			if (IF_WO_INFO.JOB_TYPE == MP_ORD_JOB_TYPE_STANDARD)
			{
				TRS.set_nstring(tran_in_node, "ORD_CMF_7", "Y");
			}
			else {
				TRS.set_nstring(tran_in_node, "ORD_CMF_7", "N");
			}

			// Material Check
			DBU_init_mwipmatdef(&MWIPMATDEF);

			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), tran_in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, IF_WO_INFO.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "WIP-0006");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WO_INFO.IF_CODE = 'R';
				memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
				DBU_update_if_wo_info(101, &IF_WO_INFO);
				DB_commit();
				continue;
			}

			TRS.set_string(tran_in_node, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
			TRS.set_int(tran_in_node, "MAT_VER", MWIPMATDEF.MAT_VER);

			// Flow Check
			DBU_init_mwipmatflw(&MWIPMATFLW);

			memcpy(MWIPMATFLW.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
			memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATFLW.MAT_ID));
			MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;

			//DBU_select_mwipmatflw(5, &MWIPMATFLW);

			//211116 출하플로우 뺴고 조회되도록 수정.(cas 6추가)
			DBU_select_mwipmatflw(6, &MWIPMATFLW);
			if (DB_error_code != DB_SUCCESS)
			{

				/*
				DB_rollback();

				strcpy(s_msg_code, "WIP-0019");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WO_INFO.IF_CODE = 'R';
				memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
				DBU_update_if_wo_info(101, &IF_WO_INFO);
				DB_commit();
				continue;
				*/

				//20221207 플로우 없으면 가능한 플로우 찾아서 등록되도록 수정
				// 품목에 플로우 없으면 매칭되는 플로우 있는지 조회
				DBU_init_mwipflwdef(&MWIPFLWDEF);
				TRS.copy(MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWDEF.FLOW_CMF_20, IF_WO_INFO.WIP_ENTITY_NAME, sizeof(MWIPFLWDEF.FLOW_CMF_20));

				DBU_select_mwipflwdef(2, &MWIPFLWDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "WIP-0019");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					//IF_WO_INFO.IF_CODE = 'R';

					memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
					DBU_update_if_wo_info(101, &IF_WO_INFO);
					DB_commit();
					continue;
				}


				DBU_init_mwipmatflw(&MWIPMATFLW);
				memcpy(MWIPMATFLW.FACTORY, MWIPFLWDEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
				memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATFLW.MAT_ID));
				MWIPMATFLW.MAT_VER = 1;
				memcpy(MWIPMATFLW.FLOW, MWIPFLWDEF.FLOW, sizeof(MWIPMATFLW.FLOW));

				DBC_select_mwipmatflw(4, &MWIPMATFLW);

				if (DB_error_code == DB_NOT_FOUND)
				{
					//플로우넣기
					Flow_in_node = TRS.create_node("ATTACH_FLOW_IN");
					Flow_out_node = TRS.create_node("CMN_OUT");

					TRS.set_string(Flow_in_node, "FACTORY", MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
					TRS.set_char(Flow_in_node, "PROCSTEP", '1');

					TRS.set_string(Flow_in_node, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.set_int(Flow_in_node, "MAT_VER", 1);
					TRS.set_string(Flow_in_node, "FLOW", MWIPFLWDEF.FLOW, sizeof(MWIPFLWDEF.FLOW));


					if (WIP_ATTACH_FLOW_TOMATERIAL(s_msg_code, Flow_in_node, Flow_out_node) == MP_FALSE)
					{
						DB_rollback();

						//strcpy(s_msg_code, "WIP-0019");

						strcpy(s_msg_code, "WIP-0004");
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						//IF_WO_INFO.IF_CODE = 'R';
						memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
						DBU_update_if_wo_info(101, &IF_WO_INFO);
						DB_commit();

						TRS_free_node(Flow_in_node);
						TRS_free_node(Flow_out_node);
						continue;
					}
				}


			}

			// 신규인 경우에만 FLOW Setting 한다. Update 시에는 MES 에서 바꾼 경우가 존재.
			if (procStep == MP_STEP_CREATE)
			{
				TRS.set_string(tran_in_node, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				TRS.set_int(tran_in_node, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
			}
			else {
				TRS.set_string(tran_in_node, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
				TRS.set_int(tran_in_node, "FLOW_SEQ_NUM", MWIPORDSTS.FLOW_SEQ_NUM);
			}

			TRS.set_double(tran_in_node, "ORD_QTY", IF_WO_INFO.PLAN_QTY);


			memset(erp_order_id, 0x00, sizeof(erp_order_id));
			COM_itoa_left(erp_order_id, IF_WO_INFO.WIP_ENTITY_ID, sizeof(erp_order_id));

			// ORD_CMF_1 사업부
			// ORD_CMF_2 작업장
			// ORD_CMF_3 창고
			// ORD_CMF_4 PO번호 (현재 I/F 에는 없음) // 20211214 PO번호가 먼저내려올수 있음 있으면 들어오도록
			// ORD_CMF_5 ERP ORDER ID

			TRS.set_string(tran_in_node, "ORD_CMF_1", IF_WO_INFO.ORG_CODE, sizeof(IF_WO_INFO.ORG_CODE));


			// 20211214 PO번호가 먼저내려올수 있음 있으면 들어오도록  변경

			DBU_init_minvdlvdtl(&MINVDLVDTL);

			memcpy(MINVDLVDTL.FACTORY, IF_WO_INFO.FACTORY, sizeof(MINVDLVDTL.FACTORY));
			memcpy(MINVDLVDTL.CMF_1, IF_WO_INFO.WIP_ENTITY_NAME, sizeof(MINVDLVDTL.CMF_1));




			DBU_select_minvdlvdtl(103, &MINVDLVDTL);
			if (DB_error_code == DB_SUCCESS) {


				memset(po_dis_id, 0x00, sizeof(po_dis_id));
				COM_itoa_left(po_dis_id, MINVDLVDTL.PO_DISTRIBUTION_ID, sizeof(po_dis_id));

				TRS.set_string(tran_in_node, "ORD_CMF_4", po_dis_id, sizeof(MWIPORDSTS.ORD_CMF_4));
			}



			memset(sub_area_id, 0x00, sizeof(sub_area_id));



			// AREA 조회해서 PREFIX 가져오기
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			memcpy(MGCMTBLDAT.FACTORY, IF_WO_INFO.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
			memcpy(MGCMTBLDAT.KEY_1, IF_WO_INFO.ORG_CODE, sizeof(IF_WO_INFO.ORG_CODE));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "WIP-0008");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WO_INFO.IF_CODE = 'E';
				memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
				DBU_update_if_wo_info(101, &IF_WO_INFO);
				DB_commit();
				continue;
			}

			// 작업장 두번째자리 : _
			// 그 뒤에 ERP 작업장코드
			sub_area_id[0] = MGCMTBLDAT.DATA_3[0];
			sub_area_id[1] = '_';

			memcpy(sub_area_id + 2, IF_WO_INFO.DEPT_CODE, sizeof(IF_WO_INFO.DEPT_CODE));

			TRS.set_string(tran_in_node, "ORD_CMF_2", sub_area_id, sizeof(sub_area_id));

			memset(inv_oper, 0x00, sizeof(inv_oper));
			inv_oper[0] = MGCMTBLDAT.DATA_3[0];
			memcpy(inv_oper + 1, IF_WO_INFO.COMPLETION_INV_OPER, sizeof(IF_WO_INFO.COMPLETION_INV_OPER));
			TRS.set_string(tran_in_node, "ORD_CMF_3", inv_oper, sizeof(inv_oper));
			TRS.set_string(tran_in_node, "ORD_CMF_5", erp_order_id, sizeof(MWIPORDSTS.ORD_CMF_5));
			TRS.set_string(tran_in_node, "ORD_CMF_8", IF_WO_INFO.ITEM_UNIT, sizeof(IF_WO_INFO.ITEM_UNIT));

			// ERP ORDER STATUS
			//4	Complete
			//3	Released
			//12	Closed
			//7	Cancelled
			//1	Unreleased

			// MES ORDER STATUS
			//C	Close
			//D	Delete or Cancel
			//F	Finish
			//O	Open
			//W	Wait

			// W = 3, 4 = F, 12 = C, 7 = D
			if (IF_WO_INFO.STATUS_TYPE == 3)
			{
				TRS.set_char(tran_in_node, "ORDER_STATUS_FLAG", MP_ORD_STATUS_WAIT);
			}			
			if (IF_WO_INFO.STATUS_TYPE == 4)
			{
				TRS.set_char(tran_in_node, "ORDER_STATUS_FLAG", MP_ORD_STATUS_FINISH);
				MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_FINISH;
			}
			else if (IF_WO_INFO.STATUS_TYPE == 12)
			{
				TRS.set_char(tran_in_node, "ORDER_STATUS_FLAG", MP_ORD_STATUS_CLOSE);
				MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_CLOSE;
			}
			else if (IF_WO_INFO.STATUS_TYPE == 7)
			{
				TRS.set_char(tran_in_node, "ORDER_STATUS_FLAG", MP_ORD_STATUS_DELETE_OR_CANCEL);
				MWIPORDSTS.ORD_STATUS_FLAG = MP_ORD_STATUS_DELETE_OR_CANCEL;
			}

			if (IF_WO_INFO.STATUS_TYPE == 3)
			{
				if (ORD_UPDATE_ORDER(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE)
				{
					DB_rollback();
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_INFO.IF_CODE = 'E';
					memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
					DBU_update_if_wo_info(101, &IF_WO_INFO);

					DB_commit();
					continue;
				}
			}
			else {
				if (procStep == MP_STEP_CREATE)
				{
					strcpy(s_msg_code, "ORD-0030");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_INFO.IF_CODE = 'E';
					memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
					DBU_update_if_wo_info(101, &IF_WO_INFO);
					DB_commit();
					i_force_send_history = 1;
				}
				else {
					// WAIT 상태에서 상태 변경 와도 처리할수 있어야 함.
					memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
					memcpy(MWIPORDSTS.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
					DBU_update_mwipordsts(3, &MWIPORDSTS);

					if (DB_error_code != DB_SUCCESS)
					{
						DB_rollback();

						strcpy(s_msg_code, "ORD-0004");
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						IF_WO_INFO.IF_CODE = 'E';
						memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
						DBU_update_if_wo_info(101, &IF_WO_INFO);
						DB_commit();
						continue;
					}
				}
			}


			/*INV_OPER	8			N	VARCHAR2(30 Byte)	(' ')	False	완료창고	Frequency	20	0	0.00017				False
			NEXT_OPER_SEQ	9			N	NUMBER(6)	(0)	False	다음 공정번호	None	10	0	0.1				False
			NEXT_OPER	10			N	VARCHAR2(30 Byte)	(' ')	False	다음 공정	None	35	0	0.02857				False
			FIRST_FLAG	11			N	VARCHAR2(1 Byte)	(' ')	False	첫공정 여부	None	3	0	0.33333				False
			LAST_FLAG	12			N	VARCHAR2(1 Byte)	(' ')	False	마지막공정 여부	None	3	0	0.33333				False*/

			if (i_force_send_history == 0)
			{
				// Erp 공정 정보 입력 or 수정
				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.AREA_ID, IF_WO_INFO.ORG_CODE, sizeof(IF_WO_INFO.ORG_CODE));
				memcpy(CWIPERPOPR.SUB_AREA_ID, sub_area_id, sizeof(CWIPERPOPR.SUB_AREA_ID));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				CWIPERPOPR.OPER_SEQ = IF_WO_INFO.OPER_SEQ_NUM;

				DBU_select_cwiperpopr(101, &CWIPERPOPR);
				if (DB_error_code == DB_NOT_FOUND)
				{
					memcpy(CWIPERPOPR.OPER, IF_WO_INFO.OPER, sizeof(IF_WO_INFO.OPER));
					memcpy(CWIPERPOPR.OPER_DESC, IF_WO_INFO.OPER_DESC, sizeof(CWIPERPOPR.OPER_DESC));
					memcpy(CWIPERPOPR.INV_OPER, IF_WO_INFO.COMPLETION_INV_OPER, sizeof(IF_WO_INFO.COMPLETION_INV_OPER));
					CWIPERPOPR.NEXT_OPER_SEQ = IF_WO_INFO.NEXT_OPER_SEQ;
					memcpy(CWIPERPOPR.NEXT_OPER, IF_WO_INFO.NEXT_OPER, sizeof(IF_WO_INFO.OPER));

					CWIPERPOPR.PREV_OPER_SEQ = IF_WO_INFO.PRE_OPER_SEQ;
					memcpy(CWIPERPOPR.PREV_OPER, IF_WO_INFO.PRE_OPER, sizeof(IF_WO_INFO.PRE_OPER));

					CWIPERPOPR.FIRST_FLAG = IF_WO_INFO.FIRST_OPER_YN;
					CWIPERPOPR.LAST_FLAG = IF_WO_INFO.LAST_OPER_YN;

					memcpy(CWIPERPOPR.CREATE_TIME, gs_sys_time, sizeof(CWIPERPOPR.CREATE_TIME));
					memcpy(CWIPERPOPR.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

					DBU_insert_cwiperpopr(&CWIPERPOPR);
					if (DB_error_code != DB_SUCCESS)
					{
						DB_rollback();

						strcpy(s_msg_code, "WIP-0004");
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						IF_WO_INFO.IF_CODE = 'E';
						memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
						DBU_update_if_wo_info(101, &IF_WO_INFO);
						DB_commit();
						continue;
					}
				}
				else if (DB_error_code == DB_SUCCESS)
				{
					if (IF_WO_INFO.TRAN_FLAG == 'D')
					{
						DBU_delete_cwiperpopr(1, &CWIPERPOPR);
						if (DB_error_code != DB_SUCCESS)
						{
							DB_rollback();

							strcpy(s_msg_code, "WIP-0004");
							COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

							IF_WO_INFO.IF_CODE = 'E';
							memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
							DBU_update_if_wo_info(101, &IF_WO_INFO);
							DB_commit();
							continue;
						}
					}
					else {
						memcpy(CWIPERPOPR.OPER, IF_WO_INFO.OPER, sizeof(IF_WO_INFO.OPER));
						memcpy(CWIPERPOPR.OPER_DESC, IF_WO_INFO.OPER_DESC, sizeof(CWIPERPOPR.OPER_DESC));
						memcpy(CWIPERPOPR.INV_OPER, IF_WO_INFO.COMPLETION_INV_OPER, sizeof(IF_WO_INFO.COMPLETION_INV_OPER));
						CWIPERPOPR.NEXT_OPER_SEQ = IF_WO_INFO.NEXT_OPER_SEQ;
						memcpy(CWIPERPOPR.NEXT_OPER, IF_WO_INFO.NEXT_OPER, sizeof(IF_WO_INFO.NEXT_OPER));

						CWIPERPOPR.PREV_OPER_SEQ = IF_WO_INFO.PRE_OPER_SEQ;
						memcpy(CWIPERPOPR.PREV_OPER, IF_WO_INFO.PRE_OPER, sizeof(IF_WO_INFO.PRE_OPER));

						CWIPERPOPR.FIRST_FLAG = IF_WO_INFO.FIRST_OPER_YN;
						CWIPERPOPR.LAST_FLAG = IF_WO_INFO.LAST_OPER_YN;

						memcpy(CWIPERPOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPERPOPR.UPDATE_TIME));
						memcpy(CWIPERPOPR.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

						DBU_update_cwiperpopr(1, &CWIPERPOPR);
						if (DB_error_code != DB_SUCCESS)
						{
							DB_rollback();

							strcpy(s_msg_code, "WIP-0004");
							COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

							IF_WO_INFO.IF_CODE = 'E';
							memcpy(IF_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_INFO.IF_MSG));
							DBU_update_if_wo_info(101, &IF_WO_INFO);
							DB_commit();
							continue;
						}
					}
				}
			}			
		}			

		// BACKUP
		DBU_init_if_wo_info_his(&IF_WO_INFO_HIS);

		IF_WO_INFO_HIS.IF_SEQ = IF_WO_INFO.IF_SEQ;

		DBU_delete_if_wo_info_his(1, &IF_WO_INFO_HIS);
		DBU_insert_if_wo_info_his((struct IF_WO_INFO_HIS_TAG *)&IF_WO_INFO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_WO_INFO_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);

			TRS.free_node(tran_in_node);
			TRS.free_node(tran_out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_wo_info(1, &IF_WO_INFO);

		TRS.free_node(tran_in_node);
		TRS.free_node(tran_out_node);

		DB_commit();

		
	}

	return MP_TRUE;
}

