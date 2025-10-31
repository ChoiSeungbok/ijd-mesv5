/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_uom_conv_def.c
Description : ERP -> MES ERP 단위 환산 정보

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

int CUS_BAT_ERP_MES_UOM_CONV_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Uom_Conv_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Uom_Conv_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_UOM_CONV_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Uom_Conv_Def", out_node);


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
CUS_BAT_ERP_MES_UOM_CONV_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Uom_Conv_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_UOM_CONV_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_UOM_CONV_DEF_TAG IF_UOM_CONV_DEF;
	struct IF_UOM_CONV_DEF_HIS_TAG IF_UOM_CONV_DEF_HIS;
	struct MWIPMATDEF_TAG MWIPMATDEF;

	int i_step = 0;
	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_Uom_Conv_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_uom_conv_def(&IF_UOM_CONV_DEF);
	DBU_open_if_uom_conv_def(i_step, &IF_UOM_CONV_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_UOM_CONV_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_UOM_CONV_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_UOM_CONV_DEF.FACTORY), IF_UOM_CONV_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_UOM_CONV_DEF.ITEM_CODE), IF_UOM_CONV_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "FROM_UNIT", MP_STR, sizeof(IF_UOM_CONV_DEF.FROM_UNIT), IF_UOM_CONV_DEF.FROM_UNIT);
			TRS.add_fieldmsg(out_node, "TO_UNIT", MP_STR, sizeof(IF_UOM_CONV_DEF.FROM_UNIT), IF_UOM_CONV_DEF.TO_UNIT);
						

			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_uom_conv_def(i_step, &IF_UOM_CONV_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_uom_conv_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_UOM_CONV_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_UOM_CONV_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_UOM_CONV_DEF.FACTORY), IF_UOM_CONV_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ITEM_CODE", MP_STR, sizeof(IF_UOM_CONV_DEF.ITEM_CODE), IF_UOM_CONV_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "FROM_UNIT", MP_STR, sizeof(IF_UOM_CONV_DEF.FROM_UNIT), IF_UOM_CONV_DEF.FROM_UNIT);
			TRS.add_fieldmsg(out_node, "TO_UNIT", MP_STR, sizeof(IF_UOM_CONV_DEF.FROM_UNIT), IF_UOM_CONV_DEF.TO_UNIT);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		// 환산 단위는 단순 업데이트로만 처리
		// CMF 5, 6 만 업데이트 하면 되서 단순 처리함.
		// MAT_CMF_5 : 환산단위
		// MAT_CMF_6 : 환산비율

		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, IF_UOM_CONV_DEF.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, IF_UOM_CONV_DEF.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0006");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_UOM_CONV_DEF.IF_CODE = 'E';
			memcpy(IF_UOM_CONV_DEF.IF_MSG, Error_Msg, strlen(Error_Msg));
			DBU_update_if_uom_conv_def(101, &IF_UOM_CONV_DEF);
			DB_commit();
			continue;
		}

		memcpy(MWIPMATDEF.MAT_CMF_5, IF_UOM_CONV_DEF.TO_UNIT, sizeof(IF_UOM_CONV_DEF.TO_UNIT));
		
		COM_dtoa(MWIPMATDEF.MAT_CMF_6, IF_UOM_CONV_DEF.CONVERSION_RATE, sizeof(MWIPMATDEF.MAT_ID));

		memcpy(MWIPMATDEF.UPDATE_TIME, gs_sys_time, sizeof(MWIPMATDEF.UPDATE_TIME));
		memcpy(MWIPMATDEF.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		DBU_update_mwipmatdef(2, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0004");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_UOM_CONV_DEF.IF_CODE = 'E';
			memcpy(IF_UOM_CONV_DEF.IF_MSG, Error_Msg, strlen(Error_Msg));
			DBU_update_if_uom_conv_def(101, &IF_UOM_CONV_DEF);
			DB_commit();
			continue;
		}

		// BACKUP
		DBU_init_if_uom_conv_def_his(&IF_UOM_CONV_DEF_HIS);

		IF_UOM_CONV_DEF_HIS.IF_SEQ = IF_UOM_CONV_DEF.IF_SEQ;

		DBU_delete_if_uom_conv_def_his(1, &IF_UOM_CONV_DEF_HIS);
		DBU_insert_if_uom_conv_def_his((struct IF_UOM_CONV_DEF_HIS_TAG *)&IF_UOM_CONV_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_UOM_CONV_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_uom_conv_def(1, &IF_UOM_CONV_DEF);

		DB_commit();
	}

	return MP_TRUE;
}

