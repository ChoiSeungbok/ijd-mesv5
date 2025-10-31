/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_sub_area_def.c
Description : ERP -> MES 작업장 정보

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

int CUS_BAT_ERP_MES_SUB_AREA_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Sub_Area_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Sub_Area_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_SUB_AREA_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Sub_Area_Def", out_node);


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
CUS_BAT_ERP_MES_SUB_AREA_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Sub_Area_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_SUB_AREA_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_SUB_AREA_DEF_TAG IF_SUB_AREA_DEF;
	struct IF_SUB_AREA_DEF_HIS_TAG IF_SUB_AREA_DEF_HIS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	int i_step = 0;

	TRSNode *list_item;
	TRSNode *tran_in_node;
	TRSNode *tran_out_node;

	char s_dept_id[10];
	char s_dept_code[30];
	char Error_Msg[201];


	LOG_head("CUS_BAT_Erp_Mes_Sub_Area_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_sub_area_def(&IF_SUB_AREA_DEF);
	DBU_open_if_sub_area_def(i_step, &IF_SUB_AREA_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_SUB_AREA_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_SUB_AREA_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_SUB_AREA_DEF.FACTORY), IF_SUB_AREA_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_SUB_AREA_DEF.ORG_CODE), IF_SUB_AREA_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "DEPT_ID", MP_INT, IF_SUB_AREA_DEF.DEPT_ID);
			TRS.add_fieldmsg(out_node, "DEPT_CODE", MP_STR, sizeof(IF_SUB_AREA_DEF.DEPT_CODE), IF_SUB_AREA_DEF.DEPT_CODE);
			TRS.add_fieldmsg(out_node, "DEPT_DESC", MP_STR, sizeof(IF_SUB_AREA_DEF.DEPT_DESC), IF_SUB_AREA_DEF.DEPT_DESC);			
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_sub_area_def(i_step, &IF_SUB_AREA_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_sub_area_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_SUB_AREA_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_SUB_AREA_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_SUB_AREA_DEF.FACTORY), IF_SUB_AREA_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_SUB_AREA_DEF.ORG_CODE), IF_SUB_AREA_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "DEPT_ID", MP_INT, IF_SUB_AREA_DEF.DEPT_ID);
			TRS.add_fieldmsg(out_node, "DEPT_CODE", MP_STR, sizeof(IF_SUB_AREA_DEF.DEPT_CODE), IF_SUB_AREA_DEF.DEPT_CODE);
			TRS.add_fieldmsg(out_node, "DEPT_DESC", MP_STR, sizeof(IF_SUB_AREA_DEF.DEPT_DESC), IF_SUB_AREA_DEF.DEPT_DESC);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		tran_in_node = TRS.create_node("IN_VALUE");
		tran_out_node = TRS.create_node("OUT_VALUE");

		TRS.set_string(tran_in_node, "FACTORY", IF_SUB_AREA_DEF.FACTORY, sizeof(IF_SUB_AREA_DEF.FACTORY));
		TRS.set_string(tran_in_node, "TABLE_NAME", MP_GCM_SUB_AREA, strlen(MP_GCM_SUB_AREA));
		TRS.set_string(tran_in_node, "USERID", MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
		TRS.set_char(tran_in_node, "PROCSTEP", 'U');
		list_item = TRS.add_node(tran_in_node, "DATA_LIST");


		memset(s_dept_id, ' ', sizeof(s_dept_id));
		memset(s_dept_code, ' ', sizeof(s_dept_code));

		COM_itoa_left(s_dept_id, IF_SUB_AREA_DEF.DEPT_ID, sizeof(s_dept_id));

		// AREA 조회해서 PREFIX 가져오기
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_SUB_AREA_DEF.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
		memcpy(MGCMTBLDAT.KEY_1, IF_SUB_AREA_DEF.ORG_CODE, sizeof(IF_SUB_AREA_DEF.ORG_CODE));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();
			//RAS-0011 : 존재하지 않는 AREA입니다.
			strcpy(s_msg_code, "RAS-0011");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_SUB_AREA_DEF.IF_CODE = 'E';
			memcpy(IF_SUB_AREA_DEF.IF_MSG, Error_Msg, sizeof(IF_SUB_AREA_DEF.IF_MSG));
			DBU_update_if_sub_area_def(101, &IF_SUB_AREA_DEF);
			DB_commit();
			continue;
		}

		// MES SUB_AREA CODE = AREA PREFIX + '_' + ERP_DEPT_CODE
		s_dept_code[0] = MGCMTBLDAT.DATA_3[0];
		s_dept_code[1] = '_';

		memcpy(s_dept_code + 2, IF_SUB_AREA_DEF.DEPT_CODE, sizeof(IF_SUB_AREA_DEF.DEPT_CODE));
		

		// KEY_1 SUB_AREA, MES ONLY
		TRS.add_string(list_item, "KEY_1", s_dept_code, sizeof(s_dept_code));
		// DATA_1 DESCRIPTION
		TRS.add_string(list_item, "DATA_1", IF_SUB_AREA_DEF.DEPT_DESC, sizeof(IF_SUB_AREA_DEF.DEPT_DESC));
		// DATA_2 AREA
		TRS.add_string(list_item, "DATA_2", IF_SUB_AREA_DEF.ORG_CODE, sizeof(IF_SUB_AREA_DEF.ORG_CODE));
		// DATA_3 FMB BOARD ID, MES ONLY
		TRS.add_string(list_item, "DATA_4", IF_SUB_AREA_DEF.DEPT_CODE, sizeof(IF_SUB_AREA_DEF.DEPT_CODE));
		// DATA_5 BLENDING_YN, MES ONLY
		// DATA_6 OUTSOURCING_YN, MES ONLY
		// DATA_7 GRIT_CLASS_YN, MES ONLY
		// DATA_8 ERP_SUB_AREA_ID, ERP ONLY
		TRS.add_string(list_item, "DATA_8", s_dept_id, sizeof(s_dept_id));

		// INSERT GT(General Table)
		if (BAS_UPDATE_DATA_LIST(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE)
		{
			DB_rollback();
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_SUB_AREA_DEF.IF_CODE = 'E';
			memcpy(IF_SUB_AREA_DEF.IF_MSG, Error_Msg, sizeof(IF_SUB_AREA_DEF.IF_MSG));
			DBU_update_if_sub_area_def(101, &IF_SUB_AREA_DEF);
			DB_commit();
			continue;
		}

		// BACKUP
		DBU_init_if_sub_area_def_his(&IF_SUB_AREA_DEF_HIS);

		IF_SUB_AREA_DEF_HIS.IF_SEQ = IF_SUB_AREA_DEF.IF_SEQ;

		DBU_delete_if_sub_area_def_his(1, &IF_SUB_AREA_DEF_HIS);
		DBU_insert_if_sub_area_def_his((struct IF_SUB_AREA_DEF_HIS_TAG *)&IF_SUB_AREA_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_SUB_AREA_DEF_HIS INSERT", MP_NVST);
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
		DBU_delete_if_sub_area_def(1, &IF_SUB_AREA_DEF);

		TRS.free_node(tran_in_node);
		TRS.free_node(tran_out_node);
		DB_commit();
	}

	return MP_TRUE;
}

