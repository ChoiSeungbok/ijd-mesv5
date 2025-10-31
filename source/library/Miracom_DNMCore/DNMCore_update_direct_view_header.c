/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_update_direct_view_header.c
	Description : Direct_View_Header Setup function module

	MES Version : 5.2.0

	Function List
		- DNM_Update_Direct_View_Header()
			+ Create/Update/Delete Direct_View_Header definition
		- DNM_UPDATE_DIRECT_VIEW_HEADER()
			+ Main sub function of DNM_Update_Direct_View_Header function
			+ Create/Update/Delete Direct_View_Header definition
		- DNM_Update_Direct_View_Header_Validation()
			+ Main sub function of DNM_UPDATE_DIRECT_VIEW_HEADER function
			+ Check the condition for create/update/delete Direct_View_Header
	Detail Description
		- DNM_UPDATE_DIRECT_VIEW_HEADER()
			+ h_proc_step
				+ MP_STEP_CREATE : Create Direct_View_Header definition
				+ MP_STEP_UPDATE : Update Direct_View_Header definition
				+ MP_STEP_DELETE : Delete Direct_View_Header definition

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2012/08/01  Kelly Jung     Create by Generator

	Copyright(C) 1998-2012 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "DNMCore_common.h"

int DNM_Update_Direct_View_Header_Validation(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node);

/*******************************************************************************
	DNM_Update_Direct_View_Header()
		- Create/Update/Delete Direct_View_Header definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_Update_Direct_View_Header(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_UPDATE_DIRECT_VIEW_HEADER(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_UPDATE_DIRECT_VIEW_HEADER", out_node);

	if(i_ret == MP_TRUE)
	{
		DB_commit();
	}
	else
	{
		DB_rollback();
	}

	return MP_TRUE;
}
/*******************************************************************************
	DNM_UPDATE_DIRECT_VIEW_HEADER()
		- Main sub function of "DNM_Update_Direct_View_Header" function
		- Create/Update/Delete Direct_View_Header definition
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_UPDATE_DIRECT_VIEW_HEADER(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMDVWHDR_TAG MDNMDVWHDR;
	struct MDNMDVWHDR_TAG MDNMDVWHDR_o;

	LOG_head("DNM_Update_Direct_View_Header");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_Update_Direct_View_Header",
							 MP_UPOINT_BEFORE,
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;
	if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE; 

	if(DNM_Update_Direct_View_Header_Validation(s_msg_code, in_node, out_node) == MP_FALSE) 
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBC_init_mdnmdvwhdr(&MDNMDVWHDR);
	TRS.copy(MDNMDVWHDR.VIEW_ID, sizeof(MDNMDVWHDR.VIEW_ID), in_node, "VIEW_ID");
	TRS.copy(MDNMDVWHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME), in_node, "COL_NAME");
    TRS.copy(MDNMDVWHDR.DISPLAY_NAME, sizeof(MDNMDVWHDR.DISPLAY_NAME), in_node, "DISPLAY_NAME");
    TRS.copy(MDNMDVWHDR.COL_DESC, sizeof(MDNMDVWHDR.COL_DESC), in_node, "COL_DESC");
	TRS.copy(MDNMDVWHDR.CREATE_TIME, sizeof(MDNMDVWHDR.CREATE_TIME), in_node, "CREATE_TIME");
	TRS.copy(MDNMDVWHDR.CREATE_USER_ID, sizeof(MDNMDVWHDR.CREATE_USER_ID), in_node, "CREATE_USER_ID");
	TRS.copy(MDNMDVWHDR.UPDATE_TIME, sizeof(MDNMDVWHDR.UPDATE_TIME), in_node, "UPDATE_TIME");
	TRS.copy(MDNMDVWHDR.UPDATE_USER_ID, sizeof(MDNMDVWHDR.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");

	if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{

		//----[Addtional Logic for Create Case]----
		/*TRS.copy(MDNMDVWHDR.CREATE_USER_ID, sizeof(MDNMDVWHDR.CREATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(MDNMDVWHDR.CREATE_TIME); 
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "DB_get_systime", MP_NVST);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		}*/

		DBC_insert_mdnmdvwhdr(&MDNMDVWHDR); 
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVWHDR INSERT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 
	}
	else if(TRS.get_procstep(in_node) == MP_STEP_UPDATE)
	{
		DBC_init_mdnmdvwhdr(&MDNMDVWHDR_o); 
		TRS.copy(MDNMDVWHDR_o.VIEW_ID, sizeof(MDNMDVWHDR_o.VIEW_ID), in_node, "VIEW_ID");
		TRS.copy(MDNMDVWHDR_o.COL_NAME, sizeof(MDNMDVWHDR_o.COL_NAME), in_node, "COL_NAME");
		DBC_select_mdnmdvwhdr_for_update(1, &MDNMDVWHDR_o);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVWHDR SELECT FOR UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 

		//----[Addtional Logic for Create Case]----
		/*memcpy(MDNMDVWHDR.CREATE_USER_ID, MDNMDVWHDR_o.CREATE_USER_ID, sizeof(MDNMDVWHDR.CREATE_USER_ID)); 
		memcpy(MDNMDVWHDR.CREATE_TIME, MDNMDVWHDR_o.CREATE_TIME, sizeof(MDNMDVWHDR.CREATE_TIME));
		TRS.copy(MDNMDVWHDR.UPDATE_USER_ID, sizeof(MDNMDVWHDR.UPDATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(MDNMDVWHDR.UPDATE_TIME); 
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "DB_get_systime", MP_NVST);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} */

		DBC_update_mdnmdvwhdr(1, &MDNMDVWHDR);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVWHDR UPDATE", MP_NVST); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 
	}
	else if(TRS.get_procstep(in_node) == MP_STEP_DELETE)
	{
		DBC_delete_mdnmdvwhdr(1, &MDNMDVWHDR);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVWHDR DELETE", MP_NVST); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 
	}

	if(COM_proc_user_routine("DNM", "DNM_Update_Direct_View_Header",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 

/*******************************************************************************
	DNM_Update_Direct_View_Header_Validation()
		- Main sub function of "DNM_UPDATE_DIRECT_VIEW_HEADER" function
		- Check the condition for create/update/delete Direct_View_Header & vbCrLf	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_Update_Direct_View_Header_Validation(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node)
{
	struct MDNMDVWHDR_TAG MDNMDVWHDR;
	struct MWIPFACDEF_TAG MWIPFACDEF;
    struct MDNMSQLDEF_TAG MDNMSQLDEF;

//	int i_count = 0;

	/* ProcStep Validation */
	if(COM_service_validation(s_msg_code,
							in_node,
							out_node,
							TRS.get_procstep(in_node),
							"IUD") == MP_FALSE)
	{
		return MP_FALSE;
	}

	/* Factory Validation */
	if(COM_isnullspace(TRS.get_string(in_node, IN_FACTORY)) == MP_TRUE)
	{
		strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_SETUP;
		return MP_FALSE;
	}
	else
	{
		DBC_init_mwipfacdef(&MWIPFACDEF);
		TRS.copy(MWIPFACDEF.FACTORY, sizeof(MWIPFACDEF.FACTORY), in_node, IN_FACTORY);
		DBC_select_mwipfacdef(1, &MWIPFACDEF);
		if(DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0005");
			TRS.add_fieldmsg(out_node, "MWIPFACDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFACDEF.FACTORY), MWIPFACDEF.FACTORY);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_SETUP;
			return MP_FALSE;
		}
	}

	/* View_id Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "VIEW_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	/* Col_name Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "COL_NAME")) == MP_TRUE)
	{
		strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "COL_NAME", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

    DBC_init_mdnmsqldef(&MDNMSQLDEF);
	TRS.copy(MDNMSQLDEF.VIEW_ID, sizeof(MDNMSQLDEF.VIEW_ID), in_node, "VIEW_ID");
	DBC_select_mdnmsqldef(1, &MDNMSQLDEF); 
	if(DB_error_code != DB_SUCCESS)
	{ 
		strcpy(s_msg_code, "TAP-XXXX"); 
		TRS.add_fieldmsg(out_node, "MDNMSQLDEF SELECT", MP_NVST); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMSQLDEF.VIEW_ID), MDNMSQLDEF.VIEW_ID); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
	}

	DBC_init_mdnmdvwhdr(&MDNMDVWHDR);
	TRS.copy(MDNMDVWHDR.VIEW_ID, sizeof(MDNMDVWHDR.VIEW_ID), in_node, "VIEW_ID");
	TRS.copy(MDNMDVWHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME), in_node, "COL_NAME");
	DBC_select_mdnmdvwhdr(1, &MDNMDVWHDR); 
	if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{
		if(DB_error_code == DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-XXXX"); 
			TRS.add_fieldmsg(out_node, "MDNMDVWHDR SELECT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		}
	}
	else if(TRS.get_procstep(in_node) == MP_STEP_UPDATE ||
			TRS.get_procstep(in_node) == MP_STEP_DELETE) 
	{
		if(DB_error_code != DB_SUCCESS)
		{
			if(DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "TAP-XXXX"); 
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
			}
			else
			{
				strcpy(s_msg_code, "TAP-0004"); 
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}

			TRS.add_fieldmsg(out_node, "MDNMDVWHDR SELECT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_SETUP;
			return MP_FALSE;
		}
	}
	return MP_TRUE;
}