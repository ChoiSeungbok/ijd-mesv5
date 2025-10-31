/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_p_wo_info.c
Description : ERP -> MES CTM P급 작업지시 정보

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

int CUS_BAT_ERP_MES_P_WO_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_P_Wo_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_P_Wo_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_P_WO_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_P_Wo_Info", out_node);


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
CUS_BAT_ERP_MES_P_WO_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_P_Wo_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_P_WO_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_P_WO_INFO_TAG IF_P_WO_INFO;
	struct IF_P_WO_INFO_HIS_TAG IF_P_WO_INFO_HIS;	
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CWIPORDRWK_TAG CWIPORDRWK;
	
	char procStep;
	int i_step = 0;

	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_P_Wo_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_p_wo_info(&IF_P_WO_INFO);
	DBU_open_if_p_wo_info(i_step, &IF_P_WO_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_P_WO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_P_WO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_P_WO_INFO.FACTORY), IF_P_WO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_P_WO_INFO.ORG_CODE), IF_P_WO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_P_WO_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_P_WO_INFO.WIP_ENTITY_NAME), IF_P_WO_INFO.WIP_ENTITY_NAME);

			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_p_wo_info(i_step, &IF_P_WO_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_p_wo_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_P_WO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_P_WO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_P_WO_INFO.FACTORY), IF_P_WO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_P_WO_INFO.ORG_CODE), IF_P_WO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_ID", MP_INT, IF_P_WO_INFO.WIP_ENTITY_ID);
			TRS.add_fieldmsg(out_node, "WIP_ENTITY_NAME", MP_STR, sizeof(IF_P_WO_INFO.WIP_ENTITY_NAME), IF_P_WO_INFO.WIP_ENTITY_NAME);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		// Material Check
		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, IF_P_WO_INFO.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, IF_P_WO_INFO.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;

		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0006");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_P_WO_INFO.IF_CODE = 'E';
			memcpy(IF_P_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_P_WO_INFO.IF_MSG));
			DBU_update_if_p_wo_info(101, &IF_P_WO_INFO);
			DB_commit();
			continue;
		}

		DBU_init_cwipordrwk(&CWIPORDRWK);
		memcpy(CWIPORDRWK.FACTORY, IF_P_WO_INFO.FACTORY, sizeof(CWIPORDRWK.FACTORY));
		memcpy(CWIPORDRWK.AREA_ID, IF_P_WO_INFO.ORG_CODE, sizeof(IF_P_WO_INFO.ORG_CODE));
		memcpy(CWIPORDRWK.ORDER_ID, IF_P_WO_INFO.WIP_ENTITY_NAME, sizeof(CWIPORDRWK.ORDER_ID));

		DBU_select_cwipordrwk(1, &CWIPORDRWK);
		if (DB_error_code == DB_NOT_FOUND)
		{
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {

			procStep = MP_STEP_UPDATE;
		}
		else {
			DB_rollback();

			strcpy(s_msg_code, "WIP-0004");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_P_WO_INFO.IF_CODE = 'E';
			memcpy(IF_P_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_P_WO_INFO.IF_MSG));
			DBU_update_if_p_wo_info(101, &IF_P_WO_INFO);
			DB_commit();
			continue;
		}

		memcpy(CWIPORDRWK.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(CWIPORDRWK.MAT_ID));
		CWIPORDRWK.MAT_VER = MWIPMATDEF.MAT_VER;
		CWIPORDRWK.QTY = IF_P_WO_INFO.REMAIN_QTY;
	
		CWIPORDRWK.ERP_ORDER_ID = IF_P_WO_INFO.WIP_ENTITY_ID;		
		CWIPORDRWK.DELETE_FLAG = IF_P_WO_INFO.ENABLED_FLAG;
	
		if (procStep == MP_STEP_CREATE)
		{
			memcpy(CWIPORDRWK.CREATE_TIME, gs_sys_time, sizeof(CWIPORDRWK.CREATE_TIME));
			memcpy(CWIPORDRWK.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_cwipordrwk(&CWIPORDRWK);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "WIP-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_P_WO_INFO.IF_CODE = 'E';
				memcpy(IF_P_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_P_WO_INFO.IF_MSG));
				DBU_update_if_p_wo_info(101, &IF_P_WO_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE) {

			memcpy(CWIPORDRWK.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDRWK.UPDATE_TIME));
			memcpy(CWIPORDRWK.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			if (IF_P_WO_INFO.ENABLED_FLAG == 'Y')
			{
				memcpy(CWIPORDRWK.DELETE_TIME, gs_sys_time, sizeof(CWIPORDRWK.DELETE_TIME));
				memcpy(CWIPORDRWK.DELETE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
			}

			DBU_update_cwipordrwk(1, &CWIPORDRWK);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "WIP-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_P_WO_INFO.IF_CODE = 'E';
				memcpy(IF_P_WO_INFO.IF_MSG, Error_Msg, sizeof(IF_P_WO_INFO.IF_MSG));
				DBU_update_if_p_wo_info(101, &IF_P_WO_INFO);
				DB_commit();
				continue;
			}
		}

		// BACKUP
		DBU_init_if_p_wo_info_his(&IF_P_WO_INFO_HIS);

		IF_P_WO_INFO_HIS.IF_SEQ = IF_P_WO_INFO.IF_SEQ;

		DBU_delete_if_p_wo_info_his(1, &IF_P_WO_INFO_HIS);
		DBU_insert_if_p_wo_info_his((struct IF_P_WO_INFO_HIS_TAG *)&IF_P_WO_INFO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_P_WO_INFO_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_p_wo_info(1, &IF_P_WO_INFO);

		DB_commit();
	}

	return MP_TRUE;
}

