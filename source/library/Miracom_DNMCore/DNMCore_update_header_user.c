/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_update_header_user.c
	Description : Header_User Setup function module

	MES Version : 5.2.0

	Function List
		- DNM_Update_Header_User()
			+ Create/Update/Delete Header_User definition
		- DNM_UPDATE_HEADER_USER()
			+ Main sub function of DNM_Update_Header_User function
			+ Create/Update/Delete Header_User definition
		- DNM_Update_Header_User_Validation()
			+ Main sub function of DNM_UPDATE_HEADER_USER function
			+ Check the condition for create/update/delete Header_User
	Detail Description
		- DNM_UPDATE_HEADER_USER()
			+ h_proc_step
				+ MP_STEP_CREATE : Create Header_User definition
				+ MP_STEP_UPDATE : Update Header_User definition
				+ MP_STEP_DELETE : Delete Header_User definition

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2012/08/01  Kelly Jung     Create by Generator

	Copyright(C) 1998-2012 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "DNMCore_common.h"

int DNM_Update_Header_User_Validation(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node);

/*******************************************************************************
	DNM_Update_Header_User()
		- Create/Update/Delete Header_User definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_Update_Header_User(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_UPDATE_HEADER_USER(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_UPDATE_HEADER_USER", out_node);

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
	DNM_UPDATE_HEADER_USER()
		- Main sub function of "DNM_Update_Header_User" function
		- Create/Update/Delete Header_User definition
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_UPDATE_HEADER_USER(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMDVUHDR_TAG MDNMDVUHDR;
	struct MDNMDVUHDR_TAG MDNMDVUHDR_o;
	struct MBASGLBDEF_TAG MBASGLBDEF;

	LOG_head("DNM_Update_Header_User");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_Update_Header_User",
							 MP_UPOINT_BEFORE,
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;
	if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE; 

	if(DNM_Update_Header_User_Validation(s_msg_code, in_node, out_node) == MP_FALSE) 
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBC_init_mbasglbdef(&MBASGLBDEF);
	TRS.copy(MBASGLBDEF.FACTORY, sizeof(MBASGLBDEF.FACTORY), in_node, "FACTORY");
	memcpy(MBASGLBDEF.OPTION_NAME, "UseUserHeaderForDirectView", strlen("UseUserHeaderForDirectView"));
	DBC_select_mbasglbdef(1, &MBASGLBDEF);

	if(MBASGLBDEF.VALUE_1[0]!='Y')
		TRS.set_nstring(in_node, "USER_ID", "ADMIN");


	DBC_init_mdnmdvuhdr(&MDNMDVUHDR);
	TRS.copy(MDNMDVUHDR.FACTORY, sizeof(MDNMDVUHDR.FACTORY), in_node, "FACTORY");
	TRS.copy(MDNMDVUHDR.VIEW_ID, sizeof(MDNMDVUHDR.VIEW_ID), in_node, "VIEW_ID");
	TRS.copy(MDNMDVUHDR.USER_ID, sizeof(MDNMDVUHDR.USER_ID), in_node, "USER_ID");
	TRS.copy(MDNMDVUHDR.COL_NAME, sizeof(MDNMDVUHDR.COL_NAME), in_node, "COL_NAME");
    MDNMDVUHDR.COL_SEQ = TRS.get_int(in_node, "COL_SEQ");
	TRS.copy(MDNMDVUHDR.CREATE_TIME, sizeof(MDNMDVUHDR.CREATE_TIME), in_node, "CREATE_TIME");
	TRS.copy(MDNMDVUHDR.CREATE_USER_ID, sizeof(MDNMDVUHDR.CREATE_USER_ID), in_node, "CREATE_USER_ID");
	TRS.copy(MDNMDVUHDR.UPDATE_TIME, sizeof(MDNMDVUHDR.UPDATE_TIME), in_node, "UPDATE_TIME");
	TRS.copy(MDNMDVUHDR.UPDATE_USER_ID, sizeof(MDNMDVUHDR.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");

	if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{

		//----[Addtional Logic for Create Case]----
		/*TRS.copy(MDNMDVUHDR.CREATE_USER_ID, sizeof(MDNMDVUHDR.CREATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(MDNMDVUHDR.CREATE_TIME); 
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

		DBC_insert_mdnmdvuhdr(&MDNMDVUHDR); 
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVUHDR INSERT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 
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
		DBC_init_mdnmdvuhdr(&MDNMDVUHDR_o); 
		TRS.copy(MDNMDVUHDR_o.FACTORY, sizeof(MDNMDVUHDR_o.FACTORY), in_node, "FACTORY");
		TRS.copy(MDNMDVUHDR_o.VIEW_ID, sizeof(MDNMDVUHDR_o.VIEW_ID), in_node, "VIEW_ID");
		TRS.copy(MDNMDVUHDR_o.USER_ID, sizeof(MDNMDVUHDR_o.USER_ID), in_node, "USER_ID");
		TRS.copy(MDNMDVUHDR_o.COL_NAME, sizeof(MDNMDVUHDR_o.COL_NAME), in_node, "COL_NAME");
        MDNMDVUHDR_o.COL_SEQ = TRS.get_int(in_node, "COL_SEQ");
		DBC_select_mdnmdvuhdr_for_update(1, &MDNMDVUHDR_o);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVUHDR SELECT FOR UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 

		//----[Addtional Logic for Create Case]----
		/*memcpy(MDNMDVUHDR.CREATE_USER_ID, MDNMDVUHDR_o.CREATE_USER_ID, sizeof(MDNMDVUHDR.CREATE_USER_ID)); 
		memcpy(MDNMDVUHDR.CREATE_TIME, MDNMDVUHDR_o.CREATE_TIME, sizeof(MDNMDVUHDR.CREATE_TIME));
		TRS.copy(MDNMDVUHDR.UPDATE_USER_ID, sizeof(MDNMDVUHDR.UPDATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(MDNMDVUHDR.UPDATE_TIME); 
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

		DBC_update_mdnmdvuhdr(1, &MDNMDVUHDR);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVUHDR UPDATE", MP_NVST); 
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 
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
		DBC_delete_mdnmdvuhdr(1, &MDNMDVUHDR);
		if(DB_error_code != DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-0004"); 
			TRS.add_fieldmsg(out_node, "MDNMDVUHDR DELETE", MP_NVST); 
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
			return MP_FALSE; 
		} 
	}

	if(COM_proc_user_routine("DNM", "DNM_Update_Header_User",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 

/*******************************************************************************
	DNM_Update_Header_User_Validation()
		- Main sub function of "DNM_UPDATE_HEADER_USER" function
		- Check the condition for create/update/delete Header_User & vbCrLf	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_Update_Header_User_Validation(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node)
{
	struct MDNMDVUHDR_TAG MDNMDVUHDR;
	struct MWIPFACDEF_TAG MWIPFACDEF;

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

	/* Factory Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
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
	/* User_id Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "USER_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "USER_ID", MP_NVST);

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
    if(TRS.get_int(in_node, "COL_SEQ")==0)
    {
        strcpy(s_msg_code, "TAP-0001");
		TRS.add_fieldmsg(out_node, "COL_SEQ", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
    }
	DBC_init_mdnmdvuhdr(&MDNMDVUHDR);
	TRS.copy(MDNMDVUHDR.FACTORY, sizeof(MDNMDVUHDR.FACTORY), in_node, "FACTORY");
	TRS.copy(MDNMDVUHDR.VIEW_ID, sizeof(MDNMDVUHDR.VIEW_ID), in_node, "VIEW_ID");
	TRS.copy(MDNMDVUHDR.USER_ID, sizeof(MDNMDVUHDR.USER_ID), in_node, "USER_ID");
	TRS.copy(MDNMDVUHDR.COL_NAME, sizeof(MDNMDVUHDR.COL_NAME), in_node, "COL_NAME");
    MDNMDVUHDR.COL_SEQ = TRS.get_int(in_node, "COL_SEQ");
	DBC_select_mdnmdvuhdr(1, &MDNMDVUHDR); 
	if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{
		if(DB_error_code == DB_SUCCESS)
		{ 
			strcpy(s_msg_code, "TAP-XXXX"); 
			TRS.add_fieldmsg(out_node, "MDNMDVUHDR SELECT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 
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

			TRS.add_fieldmsg(out_node, "MDNMDVUHDR SELECT", MP_NVST); 
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
			TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
			TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
            TRS.add_fieldmsg(out_node, "COL_SEQ", MP_INT, MDNMDVUHDR.COL_SEQ); 

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_SETUP;
			return MP_FALSE;
		}
	}
	return MP_TRUE;
}