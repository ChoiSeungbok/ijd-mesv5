/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_std_bom_def.c
Description : ERP -> MES 포장지시 정보

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

int CUS_BAT_ERP_MES_STD_BOM_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Std_Bom_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Std_Bom_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_STD_BOM_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Std_Bom_Def", out_node);


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
CUS_BAT_ERP_MES_STD_BOM_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Std_Bom_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_STD_BOM_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_STD_BOM_DEF_TAG IF_STD_BOM_DEF;
	struct IF_STD_BOM_DEF_HIS_TAG IF_STD_BOM_DEF_HIS;

	struct CBOMSTDDEF_TAG CBOMSTDDEF;

	int i_step = 0;
	char procStep;
	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_Std_Bom_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_std_bom_def(&IF_STD_BOM_DEF);
	DBU_open_if_std_bom_def(i_step, &IF_STD_BOM_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_STD_BOM_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_STD_BOM_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_STD_BOM_DEF.FACTORY), IF_STD_BOM_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.ORG_CODE), IF_STD_BOM_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "BOM_COMP_ID", MP_INT, IF_STD_BOM_DEF.BOM_COMP_ID);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.ITEM_CODE), IF_STD_BOM_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "COMP_ITEM_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.COMP_ITEM_CODE), IF_STD_BOM_DEF.COMP_ITEM_CODE);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_std_bom_def(i_step, &IF_STD_BOM_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_std_bom_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_STD_BOM_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_STD_BOM_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_STD_BOM_DEF.FACTORY), IF_STD_BOM_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.ORG_CODE), IF_STD_BOM_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "BOM_COMP_ID", MP_INT, IF_STD_BOM_DEF.BOM_COMP_ID);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.ITEM_CODE), IF_STD_BOM_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "COMP_ITEM_CODE", MP_STR, sizeof(IF_STD_BOM_DEF.COMP_ITEM_CODE), IF_STD_BOM_DEF.COMP_ITEM_CODE);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
		

		DBU_init_cbomstddef(&CBOMSTDDEF);

		memcpy(CBOMSTDDEF.FACTORY, IF_STD_BOM_DEF.FACTORY, sizeof(CBOMSTDDEF.FACTORY));		
		memcpy(CBOMSTDDEF.AREA_ID, IF_STD_BOM_DEF.ORG_CODE, sizeof(IF_STD_BOM_DEF.ORG_CODE));
		memcpy(CBOMSTDDEF.MAT_ID, IF_STD_BOM_DEF.ITEM_CODE, sizeof(CBOMSTDDEF.MAT_ID));
		CBOMSTDDEF.MAT_VER = 1;

		memcpy(CBOMSTDDEF.ALTERNATE_CODE, IF_STD_BOM_DEF.ALTERNATE_CODE, sizeof(CBOMSTDDEF.ALTERNATE_CODE));
		memcpy(CBOMSTDDEF.OPER, IF_STD_BOM_DEF.OPER, sizeof(CBOMSTDDEF.OPER));
		memcpy(CBOMSTDDEF.COMP_MAT_ID, IF_STD_BOM_DEF.COMP_ITEM_CODE, sizeof(CBOMSTDDEF.COMP_MAT_ID));

		DBU_select_cbomstddef(1, &CBOMSTDDEF);
		if (DB_error_code == DB_NOT_FOUND) {
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {

			if (IF_STD_BOM_DEF.TRAN_FLAG == 'D')
			{
				procStep = MP_STEP_DELETE;
			}
			else {
				procStep = MP_STEP_UPDATE;
			}			
		}
		else
		{
			DB_rollback();

			//WIP-0665 : 이 표준 BOM 정보는 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0665");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_STD_BOM_DEF.IF_CODE = 'E';
			memcpy(IF_STD_BOM_DEF.IF_MSG, Error_Msg, sizeof(IF_STD_BOM_DEF.IF_MSG));
			DBU_update_if_std_bom_def(101, &IF_STD_BOM_DEF);
			DB_commit();
			continue;
		}

		CBOMSTDDEF.ERP_AREA_ID = IF_STD_BOM_DEF.ORG_ID;
		CBOMSTDDEF.ERP_MAT_ID = IF_STD_BOM_DEF.ITEM_ID;
		memcpy(CBOMSTDDEF.MAT_ID, IF_STD_BOM_DEF.ITEM_CODE, sizeof(CBOMSTDDEF.MAT_ID));
		memcpy(CBOMSTDDEF.MAT_DESC, IF_STD_BOM_DEF.ITEM_DESC, sizeof(CBOMSTDDEF.MAT_DESC));
		CBOMSTDDEF.MAT_VER = 1;
		memcpy(CBOMSTDDEF.UNIT, IF_STD_BOM_DEF.ITEM_UNIT, sizeof(CBOMSTDDEF.UNIT));

		memcpy(CBOMSTDDEF.ALTERNATE_CODE, IF_STD_BOM_DEF.ALTERNATE_CODE, sizeof(CBOMSTDDEF.ALTERNATE_CODE));
		CBOMSTDDEF.OPER_SEQ = IF_STD_BOM_DEF.OPER_SEQ;
		CBOMSTDDEF.STD_OPER_ID = IF_STD_BOM_DEF.STD_OPER_ID;
		memcpy(CBOMSTDDEF.OPER, IF_STD_BOM_DEF.OPER, sizeof(CBOMSTDDEF.OPER));
		memcpy(CBOMSTDDEF.OPER_DESC, IF_STD_BOM_DEF.OPER_DESC, sizeof(CBOMSTDDEF.OPER_DESC));


		memcpy(CBOMSTDDEF.COMP_MAT_ID, IF_STD_BOM_DEF.COMP_ITEM_CODE, sizeof(CBOMSTDDEF.COMP_MAT_ID));
		memcpy(CBOMSTDDEF.COMP_MAT_DESC, IF_STD_BOM_DEF.COMP_ITEM_DESC, sizeof(CBOMSTDDEF.COMP_MAT_DESC));
		CBOMSTDDEF.MAT_VER = 1;
		memcpy(CBOMSTDDEF.COMP_MAT_UNIT, IF_STD_BOM_DEF.COMP_ITEM_UNIT, sizeof(CBOMSTDDEF.COMP_MAT_UNIT));

		
		
		CBOMSTDDEF.COMP_SEQ = IF_STD_BOM_DEF.COMP_SEQ;
		CBOMSTDDEF.COMP_QTY = IF_STD_BOM_DEF.COMP_QTY;
		CBOMSTDDEF.COMP_YIELD_FACTOR = IF_STD_BOM_DEF.COMP_YIELD_FACTOR;

		memcpy(CBOMSTDDEF.EFFECTIVITY_DATE, IF_STD_BOM_DEF.EFFECTIVITY_DATE, sizeof(CBOMSTDDEF.EFFECTIVITY_DATE));
		CBOMSTDDEF.WIP_SUPPLY_TYPE = IF_STD_BOM_DEF.WIP_SUPPLY_TYPE;
		
		if (COM_isnullspace(IF_STD_BOM_DEF.WIP_SUPPLY_TYPE_NAME) == MP_FALSE)
		{
			memcpy(CBOMSTDDEF.WIP_SUPPLY_TYPE_NAME, IF_STD_BOM_DEF.WIP_SUPPLY_TYPE_NAME, sizeof(CBOMSTDDEF.WIP_SUPPLY_TYPE_NAME));
		}
		else {
			CBOMSTDDEF.WIP_SUPPLY_TYPE_NAME[0] = ' ';
		}		

		memcpy(CBOMSTDDEF.SUPPLY_INV_OPER, IF_STD_BOM_DEF.SUPPLY_INV_OPER, sizeof(CBOMSTDDEF.SUPPLY_INV_OPER));


		
		memcpy(CBOMSTDDEF.UPDATE_TIME, gs_sys_time, sizeof(CBOMSTDDEF.UPDATE_TIME));
		memcpy(CBOMSTDDEF.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		if (procStep == MP_STEP_CREATE)
		{
			memcpy(CBOMSTDDEF.CREATE_TIME, gs_sys_time, sizeof(CBOMSTDDEF.CREATE_TIME));
			memcpy(CBOMSTDDEF.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_cbomstddef(&CBOMSTDDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_STD_BOM_DEF.IF_CODE = 'E';
				memcpy(IF_STD_BOM_DEF.IF_MSG, Error_Msg, sizeof(IF_STD_BOM_DEF.IF_MSG));
				DBU_update_if_std_bom_def(101, &IF_STD_BOM_DEF);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			DBU_update_cbomstddef(1, &CBOMSTDDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_STD_BOM_DEF.IF_CODE = 'E';
				memcpy(IF_STD_BOM_DEF.IF_MSG, Error_Msg, sizeof(IF_STD_BOM_DEF.IF_MSG));
				DBU_update_if_std_bom_def(101, &IF_STD_BOM_DEF);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_DELETE)
		{
			DBU_delete_cbomstddef(1, &CBOMSTDDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_STD_BOM_DEF.IF_CODE = 'E';
				memcpy(IF_STD_BOM_DEF.IF_MSG, Error_Msg, sizeof(IF_STD_BOM_DEF.IF_MSG));
				DBU_update_if_std_bom_def(101, &IF_STD_BOM_DEF);
				DB_commit();
				continue;
			}
		}


		// BACKUP
		DBU_init_if_std_bom_def_his(&IF_STD_BOM_DEF_HIS);

		IF_STD_BOM_DEF_HIS.IF_SEQ = IF_STD_BOM_DEF.IF_SEQ;

		DBU_delete_if_std_bom_def_his(1, &IF_STD_BOM_DEF_HIS);
		DBU_insert_if_std_bom_def_his((struct IF_STD_BOM_DEF_HIS_TAG *)&IF_STD_BOM_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_STD_BOM_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_std_bom_def(1, &IF_STD_BOM_DEF);

		DB_commit();
	}

	return MP_TRUE;
}

