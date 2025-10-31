/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_view_direct_view_list.c
	Description : View Direct_view List function module

	MES Version : 5.2.0

	Function List
		- DNM_View_Direct_View_List()
			+ View Direct_view definition List
		- DNM_VIEW_DIRECT_VIEW_LIST()
			+ Main sub function of DNM_View_Direct_View_List function
			+ View Direct_view definition List
	Detail Description
		- DNM_VIEW_DIRECT_VIEW()
			+ h_proc_step
				+ 1 : View Direct_view definition List by Primary Key
	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2012/08/01  Kelly Jung     Create by Generator

	Copyright(C) 1998-2012 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "DNMCore_common.h"

/*******************************************************************************
	DNM_View_Direct_View_List()
		- View Direct_view definition List
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_View_Direct_View_List(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_VIEW_DIRECT_VIEW_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_VIEW_DIRECT_VIEW_LIST", out_node);

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
	DNM_VIEW_DIRECT_VIEW_LIST()
		- Main sub function of "DNM_View_Direct_View_List" function
		- View Direct_view definition List
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_VIEW_DIRECT_VIEW_LIST(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMSQLDEF_TAG MDNMSQLDEF;
	TRSNode *list_item;

	int i_step;

	LOG_head("DNM_View_Direct_View_List");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_View_Direct_View_List",
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

	/* View_id Validation */
	
	DBC_init_mdnmsqldef(&MDNMSQLDEF);
	TRS.copy(MDNMSQLDEF.VIEW_ID, sizeof(MDNMSQLDEF.VIEW_ID), in_node, "VIEW_ID");
	DBC_open_mdnmsqldef(i_step, &MDNMSQLDEF); 
	if(DB_error_code != DB_SUCCESS)
	{ 
		strcpy(s_msg_code, "TAP-0004"); 
		TRS.add_fieldmsg(out_node, "MDNMSQLDEF OPEN", MP_NVST); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMSQLDEF.VIEW_ID), MDNMSQLDEF.VIEW_ID); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
	}
	while(1)
	{
		DBC_fetch_mdnmsqldef(i_step, &MDNMSQLDEF); 
		if(DB_error_code != DB_SUCCESS)
		{
			DBC_close_mdnmsqldef(i_step); 
			break;
		}
		list_item = TRS.add_node(out_node, "LIST");
		TRS.add_string(list_item, "VIEW_ID", MDNMSQLDEF.VIEW_ID, sizeof(MDNMSQLDEF.VIEW_ID));
		TRS.add_string(list_item, "VIEW_DESC", MDNMSQLDEF.VIEW_DESC, sizeof(MDNMSQLDEF.VIEW_DESC));
        //icon, bgcolor flag Ãß°¡
        TRS.add_char(list_item, "USE_ICON_FLAG", MDNMSQLDEF.USE_ICON_FLAG);
        TRS.add_char(list_item, "USE_BGCOLOR_FLAG", MDNMSQLDEF.USE_BGCOLOR_FLAG);
		TRS.add_string(list_item, "CREATE_TIME", MDNMSQLDEF.CREATE_TIME, sizeof(MDNMSQLDEF.CREATE_TIME));
		TRS.add_string(list_item, "CREATE_USER_ID", MDNMSQLDEF.CREATE_USER_ID, sizeof(MDNMSQLDEF.CREATE_USER_ID));
		TRS.add_string(list_item, "UPDATE_TIME", MDNMSQLDEF.UPDATE_TIME, sizeof(MDNMSQLDEF.UPDATE_TIME));
		TRS.add_string(list_item, "UPDATE_USER_ID", MDNMSQLDEF.UPDATE_USER_ID, sizeof(MDNMSQLDEF.UPDATE_USER_ID));
	}

	if(COM_proc_user_routine("DNM", "DNM_View_Direct_View_List",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 