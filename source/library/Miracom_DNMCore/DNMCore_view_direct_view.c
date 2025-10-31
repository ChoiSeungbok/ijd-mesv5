/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_view_direct_view.c
	Description : View Direct_view function module

	MES Version : 5.2.0

	Function List
		- DNM_View_Direct_View()
			+ View Direct_view definition
		- DNM_VIEW_DIRECT_VIEW()
			+ Main sub function of DNM_View_Direct_View function
			+ View Direct_view definition
	Detail Description
		- DNM_VIEW_DIRECT_VIEW()
			+ h_proc_step
				+ 1 : View Direct_view definition  by Primary Key
	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2012/08/01  Kelly Jung     Create by Generator

	Copyright(C) 1998-2012 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "DNMCore_common.h"

/*******************************************************************************
	DNM_View_Direct_View()
		- View Direct_view definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_View_Direct_View(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_VIEW_DIRECT_VIEW(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_VIEW_DIRECT_VIEW", out_node);

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
	DNM_VIEW_DIRECT_VIEW()
		- Main sub function of "DNM_View_Direct_View" function
		- View Direct_view definition
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_VIEW_DIRECT_VIEW(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMSQLDEF_TAG MDNMSQLDEF;
//    struct MDNMDVUHDR_TAG MDNMDVUHDR;
    struct MDNMDVWHDR_TAG MDNMDVWHDR;
	int i_step;

    TRSNode *list_item;


	i_step=1;

	LOG_head("DNM_View_Direct_View");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_View_Direct_View",
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
	DBC_init_mdnmsqldef(&MDNMSQLDEF);
	TRS.copy(MDNMSQLDEF.VIEW_ID, sizeof(MDNMSQLDEF.VIEW_ID), in_node, "VIEW_ID");
	DBC_select_mdnmsqldef(i_step, &MDNMSQLDEF); 
	if(DB_error_code != DB_SUCCESS)
	{ 
		strcpy(s_msg_code, "TAP-0004"); 
		TRS.add_fieldmsg(out_node, "MDNMSQLDEF SELECT", MP_NVST); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMSQLDEF.VIEW_ID), MDNMSQLDEF.VIEW_ID); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
	}
	TRS.add_string(out_node, "VIEW_ID", MDNMSQLDEF.VIEW_ID, sizeof(MDNMSQLDEF.VIEW_ID));
	TRS.add_string(out_node, "VIEW_DESC", MDNMSQLDEF.VIEW_DESC, sizeof(MDNMSQLDEF.VIEW_DESC));
    COM_add_null(MDNMSQLDEF.SQL_TEXT,sizeof(MDNMSQLDEF.SQL_TEXT));
    TRS.set_blob(out_node, MP_BIN_DATA_1,(unsigned char*)MDNMSQLDEF.SQL_TEXT, strlen(MDNMSQLDEF.SQL_TEXT));
    
    //icon, bgcolor flag Ãß°¡
    TRS.add_char(out_node, "USE_ICON_FLAG", MDNMSQLDEF.USE_ICON_FLAG);
    TRS.add_char(out_node, "USE_BGCOLOR_FLAG", MDNMSQLDEF.USE_BGCOLOR_FLAG);
	TRS.add_string(out_node, "CREATE_TIME", MDNMSQLDEF.CREATE_TIME, sizeof(MDNMSQLDEF.CREATE_TIME));
	TRS.add_string(out_node, "CREATE_USER_ID", MDNMSQLDEF.CREATE_USER_ID, sizeof(MDNMSQLDEF.CREATE_USER_ID));
	TRS.add_string(out_node, "UPDATE_TIME", MDNMSQLDEF.UPDATE_TIME, sizeof(MDNMSQLDEF.UPDATE_TIME));
	TRS.add_string(out_node, "UPDATE_USER_ID", MDNMSQLDEF.UPDATE_USER_ID, sizeof(MDNMSQLDEF.UPDATE_USER_ID));

   
    i_step=2;

    DBC_init_mdnmdvwhdr(&MDNMDVWHDR);
	TRS.copy(MDNMDVWHDR.VIEW_ID, sizeof(MDNMDVWHDR.VIEW_ID), in_node, "VIEW_ID");
    TRS.copy(MDNMDVWHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME), in_node, IN_FACTORY);
    TRS.copy(MDNMDVWHDR.DISPLAY_NAME, sizeof(MDNMDVWHDR.DISPLAY_NAME), in_node, "USER_ID");
	DBC_open_mdnmdvwhdr(i_step, &MDNMDVWHDR); 
	if(DB_error_code != DB_SUCCESS)
	{ 
		strcpy(s_msg_code, "TAP-0004"); 
		TRS.add_fieldmsg(out_node, "MDNMDVWHDR OPEN", MP_NVST); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWHDR.VIEW_ID), MDNMDVWHDR.VIEW_ID); 
		TRS.add_fieldmsg(out_node, "COL_NAME", MP_STR, sizeof(MDNMDVWHDR.COL_NAME), MDNMDVWHDR.COL_NAME); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
	}
	while(1)
	{
		DBC_fetch_mdnmdvwhdr(i_step, &MDNMDVWHDR); 
		if(DB_error_code != DB_SUCCESS)
		{
			DBC_close_mdnmdvwhdr(i_step); 
			break;
		}
		list_item = TRS.add_node(out_node, "HEADER_LIST");
		TRS.add_string(list_item, "VIEW_ID", MDNMDVWHDR.VIEW_ID, sizeof(MDNMDVWHDR.VIEW_ID));
		TRS.add_string(list_item, "COL_NAME", MDNMDVWHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME));
        TRS.add_string(list_item, "DISPLAY_NAME", MDNMDVWHDR.DISPLAY_NAME, sizeof(MDNMDVWHDR.DISPLAY_NAME));

        if(COM_isspace(MDNMDVWHDR.DISPLAY_NAME, sizeof(MDNMDVWHDR.DISPLAY_NAME))==MP_TRUE)
            TRS.set_string(list_item, "DISPLAY_NAME", MDNMDVWHDR.COL_NAME, sizeof(MDNMDVWHDR.COL_NAME));

        TRS.add_string(list_item, "COL_DESC", MDNMDVWHDR.COL_DESC, sizeof(MDNMDVWHDR.COL_DESC));
		TRS.add_string(list_item, "CREATE_TIME", MDNMDVWHDR.CREATE_TIME, sizeof(MDNMDVWHDR.CREATE_TIME));
		TRS.add_string(list_item, "CREATE_USER_ID", MDNMDVWHDR.CREATE_USER_ID, sizeof(MDNMDVWHDR.CREATE_USER_ID));
		TRS.add_string(list_item, "UPDATE_TIME", MDNMDVWHDR.UPDATE_TIME, sizeof(MDNMDVWHDR.UPDATE_TIME));
		TRS.add_string(list_item, "UPDATE_USER_ID", MDNMDVWHDR.UPDATE_USER_ID, sizeof(MDNMDVWHDR.UPDATE_USER_ID));
	}
    

	if(COM_proc_user_routine("DNM", "DNM_View_Direct_View",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 