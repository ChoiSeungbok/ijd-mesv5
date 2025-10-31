/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_worker_list.c
Description : View Worker List function

MES Version : 5.0

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/21  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Worker_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_VIEW_WORKER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_View_Worker_List()
- View Worker List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Worker_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_VIEW_WORKER_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_VIEW_WORKER_LIST", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

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
CUS_WIP_VIEW_WORKER_LIST()
- Main sub function of "CUS_WIP_View_Worker_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_WORKER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CWIPWRKGRP_TAG CWIPWRKGRP;
	struct CWIPWRKDEF_TAG CWIPWRKDEF;

	TRSNode *list_item;
	int i_step;

	LOG_head("CUS_WIP_View_Worker_List");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_View_Worker_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	if (TRS.get_procstep(in_node) == '1')
	{
		i_step = 2;

		DBU_init_cwipwrkgrp(&CWIPWRKGRP);
		TRS.copy(CWIPWRKGRP.FACTORY, sizeof(CWIPWRKGRP.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPWRKGRP.AREA_ID, sizeof(CWIPWRKGRP.AREA_ID), in_node, "AREA_ID");
		TRS.copy(CWIPWRKGRP.SUB_AREA_ID, sizeof(CWIPWRKGRP.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		TRS.copy(CWIPWRKGRP.OPER, sizeof(CWIPWRKGRP.OPER), in_node, "OPER");
		TRS.copy(CWIPWRKGRP.GROUP_ID, sizeof(CWIPWRKGRP.GROUP_ID), in_node, "GROUP_ID");

		DBU_open_cwipwrkgrp(i_step, &CWIPWRKGRP);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CWIPWRKGRP OPEN(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPWRKGRP.FACTORY), CWIPWRKGRP.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPWRKGRP.AREA_ID), CWIPWRKGRP.AREA_ID);
			TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CWIPWRKGRP.SUB_AREA_ID), CWIPWRKGRP.SUB_AREA_ID);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPWRKGRP.OPER), CWIPWRKGRP.OPER);
			TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPWRKGRP.GROUP_ID), CWIPWRKGRP.GROUP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cwipwrkgrp(i_step, &CWIPWRKGRP);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwipwrkgrp(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPWRKGRP OPEN(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPWRKGRP.FACTORY), CWIPWRKGRP.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPWRKGRP.AREA_ID), CWIPWRKGRP.AREA_ID);
				TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CWIPWRKGRP.SUB_AREA_ID), CWIPWRKGRP.SUB_AREA_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPWRKGRP.OPER), CWIPWRKGRP.OPER);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPWRKGRP.GROUP_ID), CWIPWRKGRP.GROUP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cwipwrkgrp(i_step);
				//

				return MP_FALSE;
			}

			DBU_init_cwipwrkdef(&CWIPWRKDEF);
			TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPWRKDEF.WORKER_ID, CWIPWRKGRP.WORKER_ID, sizeof(CWIPWRKGRP.WORKER_ID));
			DBU_select_cwipwrkdef(1, &CWIPWRKDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPWRKDEF.FACTORY), CWIPWRKDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cwipwrkgrp(i_step);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "WORKER_LIST");

			TRS.add_string(list_item, "WORKER_ID", CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID));
			TRS.add_string(list_item, "WORKER_DESC", CWIPWRKDEF.WORKER_DESC, sizeof(CWIPWRKDEF.WORKER_DESC));
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		i_step = 3;

		DBU_init_cwipwrkgrp(&CWIPWRKGRP);
		TRS.copy(CWIPWRKGRP.FACTORY, sizeof(CWIPWRKGRP.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPWRKGRP.AREA_ID, sizeof(CWIPWRKGRP.AREA_ID), in_node, "AREA_ID");
		TRS.copy(CWIPWRKGRP.SUB_AREA_ID, sizeof(CWIPWRKGRP.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		TRS.copy(CWIPWRKGRP.OPER, sizeof(CWIPWRKGRP.OPER), in_node, "OPER");
		TRS.copy(CWIPWRKGRP.GROUP_ID, sizeof(CWIPWRKGRP.GROUP_ID), in_node, "GROUP_ID");

		DBU_open_cwipwrkgrp(i_step, &CWIPWRKGRP);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CWIPWRKGRP OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPWRKGRP.FACTORY), CWIPWRKGRP.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPWRKGRP.AREA_ID), CWIPWRKGRP.AREA_ID);
			TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CWIPWRKGRP.SUB_AREA_ID), CWIPWRKGRP.SUB_AREA_ID);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPWRKGRP.OPER), CWIPWRKGRP.OPER);
			TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPWRKGRP.GROUP_ID), CWIPWRKGRP.GROUP_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cwipwrkgrp(i_step, &CWIPWRKGRP);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwipwrkgrp(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPWRKGRP OPEN ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPWRKGRP.FACTORY), CWIPWRKGRP.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPWRKGRP.AREA_ID), CWIPWRKGRP.AREA_ID);
				TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CWIPWRKGRP.SUB_AREA_ID), CWIPWRKGRP.SUB_AREA_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPWRKGRP.OPER), CWIPWRKGRP.OPER);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPWRKGRP.GROUP_ID), CWIPWRKGRP.GROUP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cwipwrkgrp(i_step);
				//
				
				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "WORKER_LIST");

			TRS.add_string(list_item, "WORKER_ID", CWIPWRKGRP.WORKER_ID, sizeof(CWIPWRKGRP.WORKER_ID));
			TRS.add_string(list_item, "WORKER_DESC", CWIPWRKGRP.WORK_TYPE, sizeof(CWIPWRKGRP.WORK_TYPE)); //여기서는 작업자명
		}
	}
	
    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Worker_List_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_WORKER_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Worker_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    return MP_TRUE;
}
