/******************************************************************************'

System      : MESplus
Module      : CUS_WIP
File Name   : COMCus_update_caption.c
Description : Caption Setup function module

MES Version : 5.3.4

Function List
- CUS_WIP_non_operation()
+ Create/Update/Delete Caption definition
- CUS_WIP_NON_OPERATION()
+ Main sub function of CUS_WIP_non_operation function
+ Create/Update/Delete Caption definition
- CUS_WIP_non_operation_Validation()
+ Main sub function of CUS_WIP_NON_OPERATION function
+ Check the condition for create/update/delete Caption
Detail Description
- CUS_WIP_NON_OPERATION()
+ h_proc_step
+ MP_STEP_CREATE : Create Caption definition
+ MP_STEP_UPDATE : Update Caption definition
+ MP_STEP_DELETE : Delete Caption definition

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2016/01/01                 Create by Generator

Copyright(C) 1998-2016 Miracom,Inc.
All rights reserved.

******************************************************************************/

#if defined(_HPUX_SOURCE)

#include <dirent.h>

#elif defined(__digital__) || defined(_AIX)

#include <dirent.h>

#elif defined(WIN32) || defined(WIN64)

#include <direct.h>

#endif

#include "CUS_common.h"
#include "CUS_defines.h"

int CUS_WIP_NON_OPERATION(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

int CUS_WIP_non_operation_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);


char gs_cus_cpt_dir[256];

/*******************************************************************************
COMCus_Update_Caption()
- Create/Update/Delete Caption definition
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_non_operation(TRSNode *in_node,
	TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_NON_OPERATION(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_NON_OPERATION", out_node);

	if (i_ret == MP_TRUE)
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
CUS_WIP_NON_OPERATION()
- Main sub function of "CUS_WIP_non_operation" function
- Create/Update/Delete Caption definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_NON_OPERATION(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{

	struct CWIPDWNSTS_TAG CWIPDWNSTS;


	LOG_head("CUS_WIP_non_operation");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	
	if (CUS_WIP_non_operation_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
	COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	return MP_FALSE;
	}
	
	
	DBU_init_cwipdwnsts(&CWIPDWNSTS);


	if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{

		TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
		TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), in_node, "RES_ID");
		CWIPDWNSTS.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		CWIPDWNSTS.SEQ = TRS.get_int(in_node, "SEQ");

		DBU_select_cwipdwnsts(1, &CWIPDWNSTS);


		TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
		TRS.copy(CWIPDWNSTS.FLOW, sizeof(CWIPDWNSTS.FLOW), in_node, "FLOW");
		TRS.copy(CWIPDWNSTS.OPER, sizeof(CWIPDWNSTS.OPER), in_node, "OPER");
		TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), in_node, "RES_ID");
		CWIPDWNSTS.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		CWIPDWNSTS.SEQ = TRS.get_int(in_node, "SEQ") + 1;
		TRS.copy(CWIPDWNSTS.AREA_ID, sizeof(CWIPDWNSTS.AREA_ID), in_node, "AREA_ID");
		TRS.copy(CWIPDWNSTS.SUB_AREA_ID, sizeof(CWIPDWNSTS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		TRS.copy(CWIPDWNSTS.ORDER_ID, sizeof(CWIPDWNSTS.ORDER_ID), in_node, "ORDER_ID");
		TRS.copy(CWIPDWNSTS.DOWN_CODE, sizeof(CWIPDWNSTS.DOWN_CODE), in_node, "DOWN_CODE");
		TRS.copy(CWIPDWNSTS.DOWN_TYPE_1, sizeof(CWIPDWNSTS.DOWN_TYPE_1), in_node, "DOWN_TYPE_1");
		TRS.copy(CWIPDWNSTS.DOWN_TYPE_2, sizeof(CWIPDWNSTS.DOWN_TYPE_2), in_node, "DOWN_TYPE_2");
		TRS.copy(CWIPDWNSTS.DOWN_TYPE_3, sizeof(CWIPDWNSTS.DOWN_TYPE_3), in_node, "DOWN_TYPE_3");
		TRS.copy(CWIPDWNSTS.DOWN_START_TIME, sizeof(CWIPDWNSTS.DOWN_START_TIME), in_node, "DOWN_START_TIME");
		//TRS.copy(CWIPDWNSTS.DOWN_END_TIME, sizeof(CWIPDWNSTS.DOWN_END_TIME), in_node, "DOWN_END_TIME");
		CWIPDWNSTS.DOWN_STATUS = TRS.get_char(in_node, "DOWN_STATUS");
		TRS.copy(CWIPDWNSTS.CREATE_USER_ID, sizeof(CWIPDWNSTS.CREATE_USER_ID), in_node, "CREATE_USER_ID");
		TRS.copy(CWIPDWNSTS.CREATE_TIME, sizeof(CWIPDWNSTS.CREATE_TIME), in_node, "CREATE_TIME");

		TRS.copy(CWIPDWNSTS.CREATE_USER_ID, sizeof(CWIPDWNSTS.CREATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(CWIPDWNSTS.CREATE_TIME);


		DBU_insert_cwipdwnsts(&CWIPDWNSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CWIPDWNSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(CWIPDWNSTS.FLOW), CWIPDWNSTS.FLOW);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);


			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;


			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_UPDATE)
	{

		TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
		TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), in_node, "RES_ID");
		CWIPDWNSTS.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		CWIPDWNSTS.SEQ = TRS.get_int(in_node, "SEQ");

		DBU_select_cwipdwnsts(1, &CWIPDWNSTS);

		TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
		TRS.copy(CWIPDWNSTS.FLOW, sizeof(CWIPDWNSTS.FLOW), in_node, "FLOW");
		TRS.copy(CWIPDWNSTS.OPER, sizeof(CWIPDWNSTS.OPER), in_node, "OPER");
		TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), in_node, "RES_ID");
		CWIPDWNSTS.HIST_SEQ = TRS.get_int(in_node, "HIST_SEQ");
		CWIPDWNSTS.SEQ = TRS.get_int(in_node, "SEQ");
		TRS.copy(CWIPDWNSTS.DOWN_END_TIME, sizeof(CWIPDWNSTS.DOWN_END_TIME), in_node, "DOWN_END_TIME");
		CWIPDWNSTS.DOWN_STATUS = TRS.get_char(in_node, "DOWN_STATUS");
		TRS.copy(CWIPDWNSTS.UPDATE_USER_ID, sizeof(CWIPDWNSTS.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
		TRS.copy(CWIPDWNSTS.UPDATE_TIME, sizeof(CWIPDWNSTS.UPDATE_TIME), in_node, "UPDATE_TIME");

		TRS.copy(CWIPDWNSTS.CREATE_USER_ID, sizeof(CWIPDWNSTS.CREATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(CWIPDWNSTS.CREATE_TIME);


		DBU_update_cwipdwnsts(1, &CWIPDWNSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CWIPDWNSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(CWIPDWNSTS.FLOW), CWIPDWNSTS.FLOW);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);

			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;


			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}



	//COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_non_operation_Validation()
- Main sub function of "CUS_WIP_NON_OPERATION" function
- Check the condition for create/update/delete Caption & vbCrLf    Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_non_operation_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{


	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"IUDFL") == MP_FALSE)
	{
		return MP_FALSE;
	}


	/* Caption_type Validation */
	if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "CMN-0001");
		TRS.add_fieldmsg(out_node, "RES_ID", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_SETUP;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	return MP_TRUE;
}


