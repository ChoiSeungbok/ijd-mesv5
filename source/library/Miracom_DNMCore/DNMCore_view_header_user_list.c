/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_view_header_user_list.c
	Description : View Header_User List function module

	MES Version : 5.2.0

	Function List
		- DNM_View_Header_User_List()
			+ View Header_User definition List
		- DNM_VIEW_HEADER_USER_LIST()
			+ Main sub function of DNM_View_Header_User_List function
			+ View Header_User definition List
	Detail Description
		- DNM_VIEW_HEADER_USER()
			+ h_proc_step
				+ 1 : View Header_User definition List by Primary Key
	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2012/08/01  Kelly Jung     Create by Generator

	Copyright(C) 1998-2012 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "DNMCore_common.h"

/*******************************************************************************
	DNM_View_Header_User_List()
		- View Header_User definition List
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_View_Header_User_List(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_VIEW_HEADER_USER_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_VIEW_HEADER_USER_LIST", out_node);

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
	DNM_VIEW_HEADER_USER_LIST()
		- Main sub function of "DNM_View_Header_User_List" function
		- View Header_User definition List
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_VIEW_HEADER_USER_LIST(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMDVUHDR_TAG MDNMDVUHDR;
    struct MDNMDVWHDR_TAG MDNMDVWHDR;
	struct MBASGLBDEF_TAG MBASGLBDEF;

	TRSNode *list_item;

	int i_step;

	LOG_head("DNM_View_Header_User_List");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_View_Header_User_List",
							 MP_UPOINT_BEFORE,
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;
	if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE; 

	/* ProcStep Validation */
	if(COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "1") == MP_FALSE) 
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	i_step = 1;

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
	DBC_open_mdnmdvuhdr(i_step, &MDNMDVUHDR); 
	if(DB_error_code != DB_SUCCESS)
	{ 
		strcpy(s_msg_code, "TAP-0004"); 
		TRS.add_fieldmsg(out_node, "MDNMDVUHDR OPEN", MP_NVST); 
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MDNMDVUHDR.FACTORY), MDNMDVUHDR.FACTORY); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVUHDR.VIEW_ID), MDNMDVUHDR.VIEW_ID); 
		TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MDNMDVUHDR.USER_ID), MDNMDVUHDR.USER_ID); 
		TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVUHDR.COL_NAME), MDNMDVUHDR.COL_NAME); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
	}
	while(1)
	{
		DBC_fetch_mdnmdvuhdr(i_step, &MDNMDVUHDR); 
		if(DB_error_code != DB_SUCCESS)
		{
			DBC_close_mdnmdvuhdr(i_step); 
			break;
		}
		list_item = TRS.add_node(out_node, "LIST");
		TRS.add_string(list_item, "FACTORY", MDNMDVUHDR.FACTORY, sizeof(MDNMDVUHDR.FACTORY));
		TRS.add_string(list_item, "VIEW_ID", MDNMDVUHDR.VIEW_ID, sizeof(MDNMDVUHDR.VIEW_ID));
		TRS.add_string(list_item, "USER_ID", MDNMDVUHDR.USER_ID, sizeof(MDNMDVUHDR.USER_ID));
		TRS.add_string(list_item, "COL_NAME", MDNMDVUHDR.COL_NAME, sizeof(MDNMDVUHDR.COL_NAME));
        TRS.add_int(list_item, "COL_SEQ", MDNMDVUHDR.COL_SEQ);
		TRS.add_string(list_item, "CREATE_TIME", MDNMDVUHDR.CREATE_TIME, sizeof(MDNMDVUHDR.CREATE_TIME));
		TRS.add_string(list_item, "CREATE_USER_ID", MDNMDVUHDR.CREATE_USER_ID, sizeof(MDNMDVUHDR.CREATE_USER_ID));
		TRS.add_string(list_item, "UPDATE_TIME", MDNMDVUHDR.UPDATE_TIME, sizeof(MDNMDVUHDR.UPDATE_TIME));
		TRS.add_string(list_item, "UPDATE_USER_ID", MDNMDVUHDR.UPDATE_USER_ID, sizeof(MDNMDVUHDR.UPDATE_USER_ID));

        DBC_init_mdnmdvwhdr(&MDNMDVWHDR);
	    TRS.copy(MDNMDVWHDR.VIEW_ID, sizeof(MDNMDVWHDR.VIEW_ID), in_node, "VIEW_ID");
        memcpy(MDNMDVWHDR.COL_NAME, MDNMDVUHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME));
	    DBC_select_mdnmdvwhdr(i_step, &MDNMDVWHDR); 
	    if(DB_error_code == DB_SUCCESS)
	    {
            TRS.add_string(list_item, "DISPLAY_NAME", MDNMDVWHDR.DISPLAY_NAME, sizeof(MDNMDVWHDR.DISPLAY_NAME));
            TRS.add_string(list_item, "COL_DESC", MDNMDVWHDR.COL_DESC, sizeof(MDNMDVWHDR.COL_DESC));
        }
	}

	if(COM_proc_user_routine("DNM", "DNM_View_Header_User_List",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 