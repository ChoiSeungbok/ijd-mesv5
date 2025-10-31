/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_wo_bom_info.c
Description : ERP -> MES ERP Work Order BOM 정보

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

int CUS_BAT_ERP_MES_WO_BOM_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Wo_Bom_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Wo_Bom_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_WO_BOM_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Wo_Bom_Info", out_node);


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
CUS_BAT_ERP_MES_WO_BOM_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Wo_Bom_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_WO_BOM_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_WO_BOM_INFO_TAG IF_WO_BOM_INFO;
	struct IF_WO_BOM_INFO_HIS_TAG IF_WO_BOM_INFO_HIS;
	struct CWIPORDBOM_TAG CWIPORDBOM;
	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF_COMP;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	
	int i_step = 0;
	int i_step2 = 0;
	int i_row_count = 0;
	int i_loop_error_flag = 1;

	char procStep;
	char Error_Msg[201];
	
	

	LOG_head("CUS_BAT_Erp_Mes_Wo_Bom_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_wo_bom_info(&IF_WO_BOM_INFO);
	DBU_open_if_wo_bom_info(i_step, &IF_WO_BOM_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WO_BOM_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WO_BOM_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WO_BOM_INFO.FACTORY), IF_WO_BOM_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ORG_CODE), IF_WO_BOM_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_WO_BOM_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_WO_BOM_INFO.WIP_ENTITY_NAME), IF_WO_BOM_INFO.WIP_ENTITY_NAME);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ITEM_CODE), IF_WO_BOM_INFO.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "COMP_ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.COMP_ITEM_CODE), IF_WO_BOM_INFO.COMP_ITEM_CODE);


			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_wo_bom_info(i_step, &IF_WO_BOM_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_wo_bom_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WO_BOM_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WO_BOM_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WO_BOM_INFO.FACTORY), IF_WO_BOM_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ORG_CODE), IF_WO_BOM_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_WO_BOM_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_WO_BOM_INFO.WIP_ENTITY_NAME), IF_WO_BOM_INFO.WIP_ENTITY_NAME);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ITEM_CODE), IF_WO_BOM_INFO.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "COMP_ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.COMP_ITEM_CODE), IF_WO_BOM_INFO.COMP_ITEM_CODE);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		i_loop_error_flag = 1;

		DBU_init_mwipordsts(&MWIPORDSTS);
		memcpy(MWIPORDSTS.FACTORY, IF_WO_BOM_INFO.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(MWIPORDSTS.ORDER_ID, IF_WO_BOM_INFO.WIP_ENTITY_NAME, sizeof(MWIPORDSTS.ORDER_ID));

		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "ORD-0002");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'R';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}


		//2023-03-02 Wait 아니어도 상관없음 밭는걸로
		// 
		// 
		/*
		// 작업지시 상태가 Wait 이 아니면 패스
		if (!(MWIPORDSTS.ORD_STATUS_FLAG == MP_ORD_STATUS_WAIT || MWIPORDSTS.ORD_STATUS_FLAG == MP_ORD_STATUS_OPEN))
		{
			DB_rollback();

			strcpy(s_msg_code, "ORD-0027");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'E';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}
		*/

		// 모품목 Check
		DBU_init_mwipmatdef(&MWIPMATDEF);

		memcpy(MWIPMATDEF.FACTORY, IF_WO_BOM_INFO.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, IF_WO_BOM_INFO.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;

		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();
			strcpy(s_msg_code, "WIP-0006");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'R';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}

		// 자품목 Check
		DBU_init_mwipmatdef(&MWIPMATDEF_COMP);

		memcpy(MWIPMATDEF_COMP.FACTORY, IF_WO_BOM_INFO.FACTORY, sizeof(MWIPMATDEF_COMP.FACTORY));
		memcpy(MWIPMATDEF_COMP.MAT_ID, IF_WO_BOM_INFO.COMP_ITEM_CODE, sizeof(MWIPMATDEF_COMP.MAT_ID));
		MWIPMATDEF_COMP.MAT_VER = 1;

		DBU_select_mwipmatdef(1, &MWIPMATDEF_COMP);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0006");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'R';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}

		// FLOW-OPER SELECT 
		DBU_init_mwipflwopr(&MWIPFLWOPR);

		memcpy(MWIPFLWOPR.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
		memcpy(MWIPFLWOPR.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPFLWOPR.FLOW));

		// ERP OPER CODE 기준으로 조회해야 해서 NEXT_OPER 에 임시로 넣음
		memcpy(MWIPFLWOPR.NEXT_OPER, IF_WO_BOM_INFO.OPER, sizeof(MWIPFLWOPR.NEXT_OPER));

        //(int) 추가. _lwg
		i_row_count = (int)DBU_select_mwipflwopr_scalar(2, &MWIPFLWOPR);

		if (i_row_count == 0)
		{
			strcpy(s_msg_code, "WIP-0014");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'R';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}
		
		i_step2 = 3;
		DBU_open_mwipflwopr(i_step2, &MWIPFLWOPR);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0014");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WO_BOM_INFO.IF_CODE = 'E';
			memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
			DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
			DB_commit();
			continue;
		}

		// FETCH
		while (1)
		{
			DBU_fetch_mwipflwopr(i_step2, &MWIPFLWOPR);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_mwipflwopr(i_step2);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "IF_WO_BOM_INFO OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WO_BOM_INFO.IF_SEQ);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WO_BOM_INFO.FACTORY), IF_WO_BOM_INFO.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ORG_CODE), IF_WO_BOM_INFO.ORG_CODE);
				TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_WO_BOM_INFO.WIP_ENTITY_ID);
				TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_WO_BOM_INFO.WIP_ENTITY_NAME), IF_WO_BOM_INFO.WIP_ENTITY_NAME);
				TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.ITEM_CODE), IF_WO_BOM_INFO.ITEM_CODE);
				TRS.add_fieldmsg(out_node, "COMP_ITEM_CODE", MP_STR, sizeof(IF_WO_BOM_INFO.COMP_ITEM_CODE), IF_WO_BOM_INFO.COMP_ITEM_CODE);
				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			// 환산 단위는 단순 업데이트로만 처리
			// CMF 5, 6 만 업데이트 하면 되서 단순 처리함.
			// MAT_CMF_5 : 환산단위
			// MAT_CMF_6 : 환산비율

			DBU_init_cwipordbom(&CWIPORDBOM);
			memcpy(CWIPORDBOM.FACTORY, IF_WO_BOM_INFO.FACTORY, sizeof(CWIPORDBOM.FACTORY));
			memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID));
			memcpy(CWIPORDBOM.FLOW, MWIPFLWOPR.FLOW, sizeof(CWIPORDBOM.FLOW));
			memcpy(CWIPORDBOM.OPER, MWIPFLWOPR.OPER, sizeof(CWIPORDBOM.OPER));
			memcpy(CWIPORDBOM.MAT_ID, MWIPMATDEF_COMP.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));
			CWIPORDBOM.MAT_VER = MWIPMATDEF_COMP.MAT_VER;
			DBU_select_cwipordbom(1, &CWIPORDBOM);
			if (DB_error_code == DB_NOT_FOUND)
			{
				procStep = MP_STEP_CREATE;
			}
			else if (DB_error_code == DB_SUCCESS)
			{
				procStep = MP_STEP_UPDATE;
			}
			else
			{
				DB_rollback();

				strcpy(s_msg_code, "ORD-0028");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WO_BOM_INFO.IF_CODE = 'E';
				memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
				DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
				DB_commit();
				i_loop_error_flag = 0;
				continue;
			}

			memcpy(CWIPORDBOM.UNIT, MWIPMATDEF_COMP.UNIT_1, sizeof(CWIPORDBOM.UNIT));
			CWIPORDBOM.QTY = IF_WO_BOM_INFO.TOTAL_QTY;
			CWIPORDBOM.UNIT_QTY = IF_WO_BOM_INFO.UNIT_QTY;
			
			// 출고 창고 없이 내려오는 경우가 있어서 수정 (비표준 작지의 경우 해당)
			if (COM_isnullspace(IF_WO_BOM_INFO.SUPPLY_INV_OPER) == MP_FALSE)
			{
				// AREA 조회해서 PREFIX 가져오기
				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				memcpy(MGCMTBLDAT.FACTORY, IF_WO_BOM_INFO.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
				memcpy(MGCMTBLDAT.KEY_1, IF_WO_BOM_INFO.ORG_CODE, sizeof(IF_WO_BOM_INFO.ORG_CODE));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "BAS-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_BOM_INFO.IF_CODE = 'E';
					memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
					DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
					DB_commit();
					i_loop_error_flag = 0;
					continue;
				}

				CWIPORDBOM.OUT_OPER[0] = MGCMTBLDAT.DATA_3[0];
				memcpy(CWIPORDBOM.OUT_OPER + 1, IF_WO_BOM_INFO.SUPPLY_INV_OPER, sizeof(CWIPORDBOM.OUT_OPER));
			}
			

			if (procStep == MP_STEP_CREATE)
			{
				memcpy(CWIPORDBOM.CREATE_TIME, gs_sys_time, sizeof(CWIPORDBOM.CREATE_TIME));
				memcpy(CWIPORDBOM.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

				DBU_insert_cwipordbom(&CWIPORDBOM);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "WIP-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_BOM_INFO.IF_CODE = 'E';
					memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
					DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
					DB_commit();
					i_loop_error_flag = 0;
					continue;
				}
			}
			else if (procStep == MP_STEP_UPDATE) {

				memcpy(CWIPORDBOM.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDBOM.UPDATE_TIME));
				memcpy(CWIPORDBOM.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

				DBU_update_cwipordbom(1, &CWIPORDBOM);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "WIP-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WO_BOM_INFO.IF_CODE = 'E';
					memcpy(IF_WO_BOM_INFO.IF_MSG, Error_Msg, sizeof(IF_WO_BOM_INFO.IF_MSG));
					DBU_update_if_wo_bom_info(101, &IF_WO_BOM_INFO);
					DB_commit();
					i_loop_error_flag = 0;
					continue;
				}
			}
		}	

		// Loop 내부 Error 발생해도 BOM 정보 지우지 않도록 수정
		if (i_loop_error_flag == 1)
		{
			// BACKUP
			DBU_init_if_wo_bom_info_his(&IF_WO_BOM_INFO_HIS);

			IF_WO_BOM_INFO_HIS.IF_SEQ = IF_WO_BOM_INFO.IF_SEQ;
			DBU_delete_if_wo_bom_info_his(1, &IF_WO_BOM_INFO_HIS);

			memcpy(IF_WO_BOM_INFO.UPDATE_TIME, gs_sys_time, sizeof(IF_WO_BOM_INFO.UPDATE_TIME));

			DBU_insert_if_wo_bom_info_his((struct IF_WO_BOM_INFO_HIS_TAG *)&IF_WO_BOM_INFO);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "BAS-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_fieldmsg(out_node, "IF_WO_BOM_INFO_HIS INSERT", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			// DELETE
			DBU_delete_if_wo_bom_info(1, &IF_WO_BOM_INFO);

			DB_commit();
		}		
	}

	return MP_TRUE;
}

