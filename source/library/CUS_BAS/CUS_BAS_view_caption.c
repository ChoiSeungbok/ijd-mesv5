/******************************************************************************'

	System      : MESplus
	Module      : CUS_BAS
	File Name   : CUS_BAS_view_caption.c
	Description : View Caption function module

	MES Version : 5.3.4

	Function List
		- CUS_BAS_View_Caption()
			+ View Caption definition
		- CUS_BAS_VIEW_CAPTION()
			+ Main sub function of CUS_BAS_View_Caption function
			+ View Caption definition
	Detail Description
		- CUS_BAS_VIEW_CAPTION()
			+ h_proc_step
				+ 1 : View Caption definition  by Primary Key
	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2019/03/17                 Create by Generator

	Copyright(C) 1998-2019 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "CUS_common.h"

int CUS_BAS_VIEW_CAPTION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
	CUS_BAS_View_Caption()
		- View Caption definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_View_Caption(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAS_VIEW_CAPTION(s_msg_code, in_node, out_node);

    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 

    COM_out_msg_log_write(s_msg_code,"CUS_BAS_View_Caption", out_node);

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
	CUS_BAS_VIEW_CAPTION()
		- Main sub function of "CUS_BAS_View_Caption" function
		- View Caption definition
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_VIEW_CAPTION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
	struct CBASCPTDEF_TAG CBASCPTDEF;

	int i_step;

	i_step=1;

	LOG_head("CUS_BAS_VIEW_CAPTION");
	LOG_add("h_language", MP_CHR, TRS.get_language(in_node));
	LOG_add("h_factory", MP_NSTR, TRS.get_factory(in_node)); 
	LOG_add("h_user_id", MP_NSTR, TRS.get_userid(in_node));
	LOG_add("h_proc_step", MP_CHR, TRS.get_procstep(in_node));
	LOG_add("caption_type", MP_NSTR, TRS.get_string(in_node, "CAPTION_TYPE"));
	LOG_add("caption_key", MP_NSTR, TRS.get_string(in_node, "CAPTION_KEY"));
    //TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW); 

	/* ProcStep Validation */
	if(COM_service_validation(s_msg_code, 
                                in_node, 
                                out_node, 
                                TRS.get_procstep(in_node), "1") == MP_FALSE) 
		return MP_FALSE;

	/* Caption_type Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "CAPTION_TYPE")) == MP_TRUE)
	{
		strcpy(s_msg_code, "CMN-0001");
		TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		return MP_FALSE;
	}

	/* Caption_key Validation */
	if(COM_isnullspace(TRS.get_string(in_node, "CAPTION_KEY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "CMN-0001");
		TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		return MP_FALSE;
	}

	DBU_init_cbascptdef(&CBASCPTDEF);
	TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), in_node, "CAPTION_TYPE");
	TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "CAPTION_KEY");
	DBU_select_cbascptdef(i_step, &CBASCPTDEF); 
	if(DB_error_code != DB_SUCCESS)
	{ 
        if (DB_error_code == DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "CMN-0005"); //Caption 정의가 존재하지 않습니다.
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
        }
        else
        {
            strcpy(s_msg_code, "CMN-0004"); //관리자에게 문의하십시오.
            gs_log_type.e_type = MP_LOG_E_SYSTEM;

            TRS.add_dberrmsg(out_node, DB_error_msg);
        }
		
		TRS.add_fieldmsg(out_node, "CBASCPTDEF SELECT", MP_NVST); 
        TRS.add_fieldmsg(out_node, "Case", MP_INT, i_step); 
		TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
		TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 		

		gs_log_type.type = MP_LOG_ERROR;		
		gs_log_type.category = MP_LOG_CATE_VIEW;

		return MP_FALSE; 
	}
	TRS.add_string(out_node, "CAPTION_TYPE", CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE));
	TRS.add_string(out_node, "CAPTION_KEY", CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY));
	TRS.add_string(out_node, "CAPTION_MSG_1", CBASCPTDEF.CAPTION_MSG_1, sizeof(CBASCPTDEF.CAPTION_MSG_1));
	TRS.add_string(out_node, "CAPTION_MSG_2", CBASCPTDEF.CAPTION_MSG_2, sizeof(CBASCPTDEF.CAPTION_MSG_2));
	TRS.add_string(out_node, "CAPTION_MSG_3", CBASCPTDEF.CAPTION_MSG_3, sizeof(CBASCPTDEF.CAPTION_MSG_3));
	TRS.add_string(out_node, "CAPTION_MSG_4", CBASCPTDEF.CAPTION_MSG_4, sizeof(CBASCPTDEF.CAPTION_MSG_4));
	TRS.add_string(out_node, "CAPTION_MSG_5", CBASCPTDEF.CAPTION_MSG_5, sizeof(CBASCPTDEF.CAPTION_MSG_5));
	TRS.add_string(out_node, "CAPTION_CMF_1", CBASCPTDEF.CAPTION_CMF_1, sizeof(CBASCPTDEF.CAPTION_CMF_1));
	TRS.add_string(out_node, "CAPTION_CMF_2", CBASCPTDEF.CAPTION_CMF_2, sizeof(CBASCPTDEF.CAPTION_CMF_2));
	TRS.add_string(out_node, "CAPTION_CMF_3", CBASCPTDEF.CAPTION_CMF_3, sizeof(CBASCPTDEF.CAPTION_CMF_3));
	TRS.add_string(out_node, "CAPTION_CMF_4", CBASCPTDEF.CAPTION_CMF_4, sizeof(CBASCPTDEF.CAPTION_CMF_4));
	TRS.add_string(out_node, "CAPTION_CMF_5", CBASCPTDEF.CAPTION_CMF_5, sizeof(CBASCPTDEF.CAPTION_CMF_5));
	TRS.add_string(out_node, "CAPTION_CMF_6", CBASCPTDEF.CAPTION_CMF_6, sizeof(CBASCPTDEF.CAPTION_CMF_6));
	TRS.add_string(out_node, "CAPTION_CMF_7", CBASCPTDEF.CAPTION_CMF_7, sizeof(CBASCPTDEF.CAPTION_CMF_7));
	TRS.add_string(out_node, "CAPTION_CMF_8", CBASCPTDEF.CAPTION_CMF_8, sizeof(CBASCPTDEF.CAPTION_CMF_8));
	TRS.add_string(out_node, "CAPTION_CMF_9", CBASCPTDEF.CAPTION_CMF_9, sizeof(CBASCPTDEF.CAPTION_CMF_9));
	TRS.add_string(out_node, "CAPTION_CMF_10", CBASCPTDEF.CAPTION_CMF_10, sizeof(CBASCPTDEF.CAPTION_CMF_10));
	TRS.add_string(out_node, "CREATE_USER_ID", CBASCPTDEF.CREATE_USER_ID, sizeof(CBASCPTDEF.CREATE_USER_ID));
	TRS.add_string(out_node, "CREATE_TIME", CBASCPTDEF.CREATE_TIME, sizeof(CBASCPTDEF.CREATE_TIME));
	TRS.add_string(out_node, "UPDATE_USER_ID", CBASCPTDEF.UPDATE_USER_ID, sizeof(CBASCPTDEF.UPDATE_USER_ID));
	TRS.add_string(out_node, "UPDATE_TIME", CBASCPTDEF.UPDATE_TIME, sizeof(CBASCPTDEF.UPDATE_TIME));

	return MP_TRUE; 
}
