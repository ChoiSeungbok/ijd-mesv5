/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_transaction_type_def.c
Description : ERP -> MES ERP Transaction Type Á¤º¸

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

int CUS_BAT_ERP_MES_TRANSACTION_TYPE_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Transaction_Type_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Transaction_Type_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_TRANSACTION_TYPE_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Transaction_Type_Def", out_node);


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
CUS_BAT_ERP_MES_TRANSACTION_TYPE_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Transaction_Type_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_TRANSACTION_TYPE_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_TXN_TYPE_DEF_TAG IF_TXN_TYPE_DEF;
	struct IF_TXN_TYPE_DEF_HIS_TAG IF_TXN_TYPE_DEF_HIS;
	struct CBASTXNDEF_TAG CBASTXNDEF;

	int i_step = 0;
	char procStep;
	char Error_Msg[201];	

	LOG_head("CUS_BAT_Erp_Mes_Transaction_Type_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;	

	DBU_init_if_txn_type_def(&IF_TXN_TYPE_DEF);
	DBU_open_if_txn_type_def(i_step, &IF_TXN_TYPE_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_TXN_TYPE_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_TXN_TYPE_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_TXN_TYPE_DEF.FACTORY), IF_TXN_TYPE_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_ID", MP_INT, IF_TXN_TYPE_DEF.ORG_ID);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_INT, IF_TXN_TYPE_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "TRANSACTION_TYPE_ID", MP_INT, IF_TXN_TYPE_DEF.TRANSACTION_TYPE_ID);
			TRS.add_fieldmsg(out_node, "TRANSACTION_TYPE_NAME", MP_STR, sizeof(IF_TXN_TYPE_DEF.TRANSACTION_TYPE_NAME), IF_TXN_TYPE_DEF.TRANSACTION_TYPE_NAME);
			TRS.add_fieldmsg(out_node, "TRANSACTION_SOURCE_ID", MP_INT, IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_ID);
			TRS.add_fieldmsg(out_node, "TRANSACTION_SOURCE_DESC", MP_STR, sizeof(IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_DESC), IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_DESC);


			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_txn_type_def(i_step, &IF_TXN_TYPE_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_txn_type_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_TXN_TYPE_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_TXN_TYPE_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_TXN_TYPE_DEF.FACTORY), IF_TXN_TYPE_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_ID", MP_INT, IF_TXN_TYPE_DEF.ORG_ID);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_INT, IF_TXN_TYPE_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "TRANSACTION_TYPE_ID", MP_INT, IF_TXN_TYPE_DEF.TRANSACTION_TYPE_ID);
			TRS.add_fieldmsg(out_node, "TRANSACTION_TYPE_NAME", MP_STR, sizeof(IF_TXN_TYPE_DEF.TRANSACTION_TYPE_NAME), IF_TXN_TYPE_DEF.TRANSACTION_TYPE_NAME);
			TRS.add_fieldmsg(out_node, "TRANSACTION_SOURCE_ID", MP_INT, IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_ID);
			TRS.add_fieldmsg(out_node, "TRANSACTION_SOURCE_DESC", MP_STR, sizeof(IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_DESC), IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_DESC);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}


		DBU_init_cbastxndef(&CBASTXNDEF);
		memcpy(CBASTXNDEF.FACTORY, IF_TXN_TYPE_DEF.FACTORY, sizeof(CBASTXNDEF.FACTORY));
		CBASTXNDEF.ERP_AREA_ID = IF_TXN_TYPE_DEF.ORG_ID;
		CBASTXNDEF.TRAN_TYPE_ID = IF_TXN_TYPE_DEF.TRANSACTION_TYPE_ID;
		CBASTXNDEF.TRAN_SRC_ID = IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_ID;

		DBU_select_cbastxndef(1, &CBASTXNDEF);
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

			strcpy(s_msg_code, "BAS-0004");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_TXN_TYPE_DEF.IF_CODE = 'E';
			memcpy(IF_TXN_TYPE_DEF.IF_MSG, Error_Msg, sizeof(IF_TXN_TYPE_DEF.IF_MSG));

			DBU_update_if_txn_type_def(101, &IF_TXN_TYPE_DEF);
			DB_commit();
			continue;
		}

		CBASTXNDEF.ERP_AREA_ID = IF_TXN_TYPE_DEF.ORG_ID;
		memcpy(CBASTXNDEF.AREA_ID, IF_TXN_TYPE_DEF.ORG_CODE, sizeof(IF_TXN_TYPE_DEF.ORG_CODE));

		CBASTXNDEF.TRAN_TYPE_ID = IF_TXN_TYPE_DEF.TRANSACTION_TYPE_ID;
		memcpy(CBASTXNDEF.TRAN_TYPE_NAME, IF_TXN_TYPE_DEF.TRANSACTION_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));

		CBASTXNDEF.TRAN_SRC_ID = IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_ID;
		memcpy(CBASTXNDEF.TRAN_SRC_DESC, IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));

		CBASTXNDEF.USER_DEFINED_FLAG = IF_TXN_TYPE_DEF.USER_DEFINED_FLAG;

		memcpy(CBASTXNDEF.ISSUE_RECEIPT_FLAG, IF_TXN_TYPE_DEF.ISSUE_RECEIPT_FLAG, sizeof(CBASTXNDEF.ISSUE_RECEIPT_FLAG));

		CBASTXNDEF.TRAN_ACTION_ID = IF_TXN_TYPE_DEF.TRANSACTION_ACTION_ID;
		CBASTXNDEF.TRAN_SRC_TYPE_ID = IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_TYPE_ID;

		memcpy(CBASTXNDEF.TRAN_SRC_TYPE_NAME, IF_TXN_TYPE_DEF.TRANSACTION_SOURCE_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_SRC_TYPE_NAME));

		CBASTXNDEF.MRO_FLAG = IF_TXN_TYPE_DEF.MRO_FLAG[0];

		CBASTXNDEF.ENABLED_FLAG = IF_TXN_TYPE_DEF.ENABLED_FLAG;

		memcpy(CBASTXNDEF.DISABLE_DATE, IF_TXN_TYPE_DEF.DISABLE_DATE, sizeof(CBASTXNDEF.DISABLE_DATE));

		memcpy(CBASTXNDEF.UPDATE_TIME, gs_sys_time, sizeof(CBASTXNDEF.UPDATE_TIME));
		memcpy(CBASTXNDEF.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		if (procStep == MP_STEP_CREATE)
		{
			memcpy(CBASTXNDEF.CREATE_TIME, gs_sys_time, sizeof(CBASTXNDEF.CREATE_TIME));
			memcpy(CBASTXNDEF.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_cbastxndef(&CBASTXNDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "BAS-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_TXN_TYPE_DEF.IF_CODE = 'E';
				memcpy(IF_TXN_TYPE_DEF.IF_MSG, Error_Msg, sizeof(IF_TXN_TYPE_DEF.IF_MSG));
				DBU_update_if_txn_type_def(101, &IF_TXN_TYPE_DEF);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			DBU_update_cbastxndef(1, &CBASTXNDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "BAS-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_TXN_TYPE_DEF.IF_CODE = 'E';
				memcpy(IF_TXN_TYPE_DEF.IF_MSG, Error_Msg, sizeof(IF_TXN_TYPE_DEF.IF_MSG));
				DBU_update_if_txn_type_def(101, &IF_TXN_TYPE_DEF);
				DB_commit();
				continue;
			}
		}		

		// BACKUP
		DBU_init_if_txn_type_def_his(&IF_TXN_TYPE_DEF_HIS);

		IF_TXN_TYPE_DEF_HIS.IF_SEQ = IF_TXN_TYPE_DEF.IF_SEQ;

		DBU_delete_if_txn_type_def_his(1, &IF_TXN_TYPE_DEF_HIS);
		DBU_insert_if_txn_type_def_his((struct IF_TXN_TYPE_DEF_HIS_TAG *)&IF_TXN_TYPE_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_TXN_TYPE_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_txn_type_def(1, &IF_TXN_TYPE_DEF);

		DB_commit();
	}

	return MP_TRUE;
}

