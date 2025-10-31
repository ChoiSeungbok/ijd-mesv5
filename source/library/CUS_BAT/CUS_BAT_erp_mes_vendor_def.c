/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_vendor_def.c
Description : ERP -> MES Vendor Á¤º¸

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

int CUS_BAT_ERP_MES_VENDOR_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Vendor_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Vendor_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_VENDOR_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Vendor_Def", out_node);


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
CUS_BAT_ERP_MES_VENDOR_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Vendor_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_VENDOR_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_VENDOR_DEF_TAG IF_VENDOR_DEF;
	struct IF_VENDOR_DEF_HIS_TAG IF_VENDOR_DEF_HIS;
	int i_step = 0;

	TRSNode *list_item;
	TRSNode *tran_in_node;
	TRSNode *tran_out_node;

	char s_vendor_id[10];
	char s_site_user_id[10];

	char Error_Msg[201];	

	LOG_head("CUS_BAT_Erp_Mes_Vendor_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));
	
	// OPEN
	i_step = 101;

	DBU_init_if_vendor_def(&IF_VENDOR_DEF);
	DBU_open_if_vendor_def(i_step, &IF_VENDOR_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_VENDOR_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_VENDOR_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_VENDOR_DEF.FACTORY), IF_VENDOR_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_INT, IF_VENDOR_DEF.VENDOR_ID);
			TRS.add_fieldmsg(out_node, "VENDOR_CODE", MP_INT, IF_VENDOR_DEF.VENDOE_CODE);
			TRS.add_fieldmsg(out_node, "VENDOR_NAME", MP_STR, sizeof(IF_VENDOR_DEF.VENDOR_NAME), IF_VENDOR_DEF.VENDOR_NAME);
			TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_INT, IF_VENDOR_DEF.VENDOR_SITE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_vendor_def(i_step, &IF_VENDOR_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_vendor_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_VENDOR_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_VENDOR_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_VENDOR_DEF.FACTORY), IF_VENDOR_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_INT, IF_VENDOR_DEF.VENDOR_ID);
			TRS.add_fieldmsg(out_node, "VENDOR_CODE", MP_INT, IF_VENDOR_DEF.VENDOE_CODE);
			TRS.add_fieldmsg(out_node, "VENDOR_NAME", MP_STR, sizeof(IF_VENDOR_DEF.VENDOR_NAME), IF_VENDOR_DEF.VENDOR_NAME);
			TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_INT, IF_VENDOR_DEF.VENDOR_SITE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		tran_in_node = TRS.create_node("IN_VALUE");
		tran_out_node = TRS.create_node("OUT_VALUE");

		TRS.set_string(tran_in_node, "FACTORY", IF_VENDOR_DEF.FACTORY, sizeof(IF_VENDOR_DEF.FACTORY));
		TRS.set_string(tran_in_node, "TABLE_NAME", MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
		TRS.set_string(tran_in_node, "USERID", MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
		TRS.set_char(tran_in_node, "PROCSTEP", 'U');
		list_item = TRS.add_node(tran_in_node, "DATA_LIST");


		memset(s_vendor_id, ' ', sizeof(s_vendor_id));
		memset(s_site_user_id, ' ', sizeof(s_site_user_id));

		COM_itoa_left(s_vendor_id, IF_VENDOR_DEF.VENDOR_ID, sizeof(s_vendor_id));
		COM_itoa_left(s_site_user_id, IF_VENDOR_DEF.VENDOR_SITE_ID, sizeof(s_site_user_id));

		TRS.add_string(list_item, "KEY_1", s_vendor_id, sizeof(s_vendor_id));
		TRS.add_string(list_item, "KEY_2", s_site_user_id, sizeof(s_site_user_id));
		TRS.add_string(list_item, "DATA_1", IF_VENDOR_DEF.VENDOR_NAME, sizeof(IF_VENDOR_DEF.VENDOR_NAME));
		TRS.add_string(list_item, "DATA_2", IF_VENDOR_DEF.VENDOR_TYPE, sizeof(IF_VENDOR_DEF.VENDOR_TYPE));

		// INSERT GT(General Table)
		if (BAS_UPDATE_DATA_LIST(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE)
		{
			DB_rollback();
			
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_VENDOR_DEF.IF_CODE = 'E';
			memcpy(IF_VENDOR_DEF.IF_MSG, Error_Msg, sizeof(IF_VENDOR_DEF.IF_MSG));
			DBU_update_if_vendor_def(101, &IF_VENDOR_DEF);
			DB_commit();
			continue;
		}

		// BACKUP
		DBU_init_if_vendor_def_his(&IF_VENDOR_DEF_HIS);

		IF_VENDOR_DEF_HIS.IF_SEQ = IF_VENDOR_DEF.IF_SEQ;

		DBU_delete_if_vendor_def_his(1, &IF_VENDOR_DEF_HIS);
		DBU_insert_if_vendor_def_his((struct IF_VENDOR_DEF_HIS_TAG *)&IF_VENDOR_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_VENDOR_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, tran_out_node);

			TRS.free_node(tran_in_node);
			TRS.free_node(tran_out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_vendor_def(1, &IF_VENDOR_DEF);

		TRS.free_node(tran_in_node);
		TRS.free_node(tran_out_node);
		DB_commit();
	}

	return MP_TRUE;
}

