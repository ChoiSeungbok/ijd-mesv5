/******************************************************************************'

	System      : MESplus
	Module      : DNMCore
	File Name   : DNMCore_multi_update_direct_view_condition.c
	Description : Direct_View_Header Setup function module

	MES Version : 5.2.0

	Function List
		- DNM_Multi_Update_Direct_View_Condition()
			+ Create/Update/Delete Direct_View_Header definition
		- DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION()
			+ Main sub function of DNM_Multi_Update_Direct_View_Condition function
			+ Create/Update/Delete Direct_View_Header definition
		- DNM_Multi_Update_Direct_View_Condition_Validation()
			+ Main sub function of DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION function
			+ Check the condition for create/update/delete Direct_View_Header
	Detail Description
		- DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION()
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

//int DNM_Multi_Update_Direct_View_Condition_Validation(char *s_msg_code,
//									TRSNode *in_node,
//									TRSNode *out_node);

/*******************************************************************************
	DNM_Multi_Update_Direct_View_Condition()
		- Create/Update/Delete Direct_View_Header definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_Multi_Update_Direct_View_Condition(TRSNode *in_node,
						TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code,"DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION", out_node);

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
	DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION()
		- Main sub function of "DNM_Multi_Update_Direct_View_Condition" function
		- Create/Update/Delete Direct_View_Header definition
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION(char *s_msg_code,
							  TRSNode *in_node, 
							  TRSNode *out_node)
{ 
	struct MDNMDVWCND_TAG MDNMDVWCND;

    TRSNode **List;
//    TRSNode *update_in_node;

    int i=0;

	LOG_head("DNM_Multi_Update_Direct_View_Condition");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if(COM_proc_user_routine("DNM", "DNM_Multi_Update_Direct_View_Condition",
							 MP_UPOINT_BEFORE,
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;
	if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE; 


    DBC_init_mdnmdvwcnd(&MDNMDVWCND);
    TRS.copy(MDNMDVWCND.VIEW_ID, sizeof(MDNMDVWCND.VIEW_ID), in_node, "VIEW_ID");
    DBC_delete_mdnmdvwcnd(2, &MDNMDVWCND);
    if(DB_error_code!=DB_NOT_FOUND && DB_error_code!=DB_SUCCESS)
    {
        strcpy(s_msg_code, "TAP-0004"); 
		TRS.add_fieldmsg(out_node, "MDNMDVWCND DELETE", MP_NVST); 
		TRS.add_fieldmsg(out_node, "VIEW_ID", MP_STR, sizeof(MDNMDVWCND.VIEW_ID), MDNMDVWCND.VIEW_ID); 
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
		return MP_FALSE; 
    }


    List =  TRS.get_list(in_node, "LIST");

    for(i=0;i<TRS.get_item_count(in_node, "LIST");i++)
    {
        TRS.set_char(List[i], "PROCSTEP", MP_STEP_CREATE);
        TRS.set_char(List[i], "LANGUAGE", TRS.get_language(in_node));
        TRS.set_nstring(List[i], "FACTORY", TRS.get_factory(in_node));
        TRS.set_nstring(List[i], "USERID", TRS.get_userid(in_node));
        TRS.set_nstring(List[i], "VIEW_ID", TRS.get_string(in_node, "VIEW_ID"));
        if(DNM_UPDATE_DIRECT_VIEW_CONDITION(s_msg_code, List[i], out_node)==MP_FALSE)
        {
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		    return MP_FALSE;
        }
    }
	


	if(COM_proc_user_routine("DNM", "DNM_Multi_Update_Direct_View_Condition",
							 MP_UPOINT_AFTER, 
							 in_node,
							 out_node) == MP_FALSE)     return MP_FALSE;

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE; 
} 
