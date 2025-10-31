/******************************************************************************'

	System      : MESplus
	Module      : CUS_BAS
	File Name   : CUS_BAS_view_caption_list.c
	Description : View Caption List function module

	MES Version : 5.3.4

	Function List
		- CUS_BAS_View_Caption_List()
			+ View Caption definition List
		- CUS_BAS_VIEW_CAPTION_LIST()
			+ Main sub function of CUS_BAS_View_Caption_List function
			+ View Caption definition List
	Detail Description
		- CUS_BAS_VIEW_CAPTION()
			+ h_proc_step
				+ 1 : View Caption definition List by Primary Key
	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2019/03/17                Create by Generator

	Copyright(C) 1998-2019 Miracom,Inc.
	All rights reserved.

******************************************************************************/

#include "CUS_common.h"

int CUS_BAS_VIEW_CAPTION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
	COMCus_View_Caption_List()
		- View Caption definition List
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_View_Caption_List(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAS_VIEW_CAPTION_LIST(s_msg_code, in_node, out_node);		

    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 

	COM_out_msg_log_write(s_msg_code,"CUS_BAS_View_Caption_List", out_node);

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
	CUS_BAS_VIEW_CAPTION_LIST()
		- Main sub function of "CUS_BAS_View_Caption_List" function
		- View Caption definition List
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE) 
	Arguments
		- char *s_msg_code : Error Message Code 
		- TRSNode *in_node : Input Message structure 
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_VIEW_CAPTION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
	struct CBASCPTDEF_TAG CBASCPTDEF;
	TRSNode *list_item;

	int i_step = 1;

	LOG_head("CUS_BAS_VIEW_CAPTION_LIST");
	TRS.log_add_all_members(in_node);

	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* ProcStep Validation */
	if(COM_service_validation(s_msg_code, 
                            in_node, 
                            out_node, 
                            TRS.get_procstep(in_node), 
                            "1234") == MP_FALSE) 
		return MP_FALSE;

	/* Caption_type Validation */
	if (TRS.get_procstep(in_node) == '1')
	{
		if(COM_isnullspace(TRS.get_string(in_node, "CAPTION_TYPE")) == MP_TRUE)
		{
			strcpy(s_msg_code, "CMN-0001");
			TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			return MP_FALSE;
		}

        
	    DBU_init_cbascptdef(&CBASCPTDEF);
        TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), in_node, "CAPTION_TYPE");

        if(memcmp(CBASCPTDEF.CAPTION_TYPE, MP_CAPTION_TYPE_MESSAGE, strlen(MP_CAPTION_TYPE_MESSAGE)) == 0)
        {
            CBASCPTDEF.CAPTION_CMF_10[0] = 'M';
            i_step = 4;
        }
        else 
        {
            i_step = 1;
        }

	    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "NEXT_CAPTION_KEY");
	    DBU_open_cbascptdef(i_step, &CBASCPTDEF); 
	    if(DB_error_code != DB_SUCCESS)
	    { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF OPEN", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE; 
	    }
    }
    else if (TRS.get_procstep(in_node) == '2')
	{
        i_step = 2;

	    DBU_init_cbascptdef(&CBASCPTDEF);
        TRS.copy(CBASCPTDEF.CAPTION_CMF_10, sizeof(CBASCPTDEF.CAPTION_CMF_10), in_node, "CAPTION_CMF_10");
	    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "NEXT_CAPTION_KEY");
	    DBU_open_cbascptdef(i_step, &CBASCPTDEF); 
	    if(DB_error_code != DB_SUCCESS)
	    { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF OPEN", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_CMF_10", MP_STR, sizeof(CBASCPTDEF.CAPTION_CMF_10), CBASCPTDEF.CAPTION_CMF_10); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE; 
	    }
    }
    else if (TRS.get_procstep(in_node) == '3')
	{
        i_step = 3;

	    DBU_init_cbascptdef(&CBASCPTDEF);
        TRS.copy(CBASCPTDEF.CAPTION_CMF_10, sizeof(CBASCPTDEF.CAPTION_CMF_10), in_node, "CAPTION_CMF_10");
	    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "NEXT_CAPTION_KEY");
	    DBU_open_cbascptdef(i_step, &CBASCPTDEF); 
	    if(DB_error_code != DB_SUCCESS)
	    { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF OPEN", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_CMF_10", MP_STR, sizeof(CBASCPTDEF.CAPTION_CMF_10), CBASCPTDEF.CAPTION_CMF_10); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE; 
	    }
    }
    else if (TRS.get_procstep(in_node) == '4')
    {
        i_step = 5;
        DBU_init_cbascptdef(&CBASCPTDEF);

        if(memcmp(CBASCPTDEF.CAPTION_TYPE, MP_CAPTION_TYPE_MESSAGE, strlen(MP_CAPTION_TYPE_MESSAGE)) == 0)
        {
            CBASCPTDEF.CAPTION_CMF_10[0] = 'M';   
        }

        TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), in_node, "CAPTION_TYPE");
	    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "SEARCH_KEY");
	    DBU_open_cbascptdef(i_step, &CBASCPTDEF); 
	    if(DB_error_code != DB_SUCCESS)
	    { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF OPEN", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE; 
	    }
        
    }
	while(1)
	{
		DBU_fetch_cbascptdef(i_step, &CBASCPTDEF); 
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_cbascptdef(i_step); 
			break;
        }
		else if(DB_error_code != DB_SUCCESS)
		{
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF FETCH", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            DBU_close_cbascptdef(i_step); 

            return MP_FALSE; 
		}

        if(COM_check_node_length(out_node) == MP_FALSE)
        {
            TRS.add_string(out_node, "NEXT_CAPTION_KEY", CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY));
            DBU_close_cbascptdef(i_step); 
			break;
        }

		list_item = TRS.add_node(out_node, "LIST");

		TRS.add_string(list_item, "CAPTION_TYPE", CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE));
		TRS.add_string(list_item, "CAPTION_KEY", CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY));
		TRS.add_string(list_item, "CAPTION_MSG_1", CBASCPTDEF.CAPTION_MSG_1, sizeof(CBASCPTDEF.CAPTION_MSG_1));
		TRS.add_string(list_item, "CAPTION_MSG_2", CBASCPTDEF.CAPTION_MSG_2, sizeof(CBASCPTDEF.CAPTION_MSG_2));
		TRS.add_string(list_item, "CAPTION_MSG_3", CBASCPTDEF.CAPTION_MSG_3, sizeof(CBASCPTDEF.CAPTION_MSG_3));
	}

	return MP_TRUE; 
}
