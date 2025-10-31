/******************************************************************************'

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_update_spec.c
Description : CUS_QCM_update_spec service

MES Version : 5.3.4 ~

Function List
- CUS_QCM_update_spec()
+ Setup service interface function
- CUS_QCM_UPDATE_SPEC()
+ Main sub function of CUS_QCM_update_spec function
+ Setup service main business function
- CUS_QCM_update_spec_Validation()
+ Main sub function of CUS_QCM_UPDATE_SPEC function
+ Check the condition for create/update/delete
Detail Description
- CUS_QCM_UPDATE_SPEC()
+ h_proc_step
+ MP_STEP_CREATE : Create case
+ MP_STEP_UPDATE : Update case
+ MP_STEP_DELETE : Delete case

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2022-04-19             Create by Generator

Copyright(C) 1998-2022 Miracom,Inc.
All rights reserved.

******************************************************************************/
#include "CUS_QCM_common.h"


int CUS_QCM_update_spec_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_update_spec_Before(TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_update_spec_After(TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_QCM_update_spec()
- Setup service interface function
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_update_spec(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_UPDATE_SPEC(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_UPDATE_SPEC", out_node);

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
CUS_QCM_UPDATE_SPEC()
- Main sub function of "CUS_QCM_update_spec" function
- Setup service main business function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_SPEC(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MSPMRELVER_TAG MSPMRELVER;
	struct MSPMRELVER_TAG MSPMRELVER_o;
	char   s_sys_time[14];





	LOG_head("CUS_QCM_UPDATE_SPEC");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	/* Not use in customizing
	if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_update_spec",
	MP_UPOINT_BEFORE,
	in_node,
	out_node) == MP_FALSE)     return MP_FALSE;
	if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE;
	*/

	memset(s_sys_time, ' ', sizeof(s_sys_time));
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "CMN-0003");
		TRS.add_fieldmsg(out_node, "DB_get_systime", MP_NVST);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	if (CUS_QCM_update_spec_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	

	if (SPM_Update_Spec(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}




	//COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_QCM_update_spec_Validation()
- Main sub function of "CUS_QCM_UPDATE_SPEC" function
- Check the condition for create/update/delete
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_update_spec_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MSPMRELVER_TAG MSPMRELVER;
	struct MWIPFACDEF_TAG MWIPFACDEF;

	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"1") == MP_FALSE)
	{
		return MP_FALSE;
	}

	/* Factory Validation */
	if (COM_isnullspace(TRS.get_factory(in_node)) == MP_TRUE)
	{
		strcpy(s_msg_code, "CUS_QCM-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_SETUP;
		return MP_FALSE;
	}


	return MP_TRUE;
}



int CUS_QCM_update_spec_Before(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */

	//승인되어있으면 스펙업데이트가 안되서 스펙업데이트할때 풀었다가 끝나면 다시 승인되도록 수정(20220418)
	char s_msg_code[MP_SIZE_MSG];

	struct MSPMRELVER_TAG MSPMRELVER;


	DBC_init_mspmrelver(&MSPMRELVER);
	TRS.copy(MSPMRELVER.SPEC_REL_ID, sizeof(MSPMRELVER.SPEC_REL_ID), in_node, "SPEC_REL_ID");

	MSPMRELVER.SPEC_REL_VER = TRS.get_int(in_node, "SPEC_REL_VER");

	//TRS.copy(MSPMRELVER.SPEC_REL_VER, sizeof(MSPMRELVER.SPEC_REL_VER), in_node, "SPEC_REL_VER");
	DBC_select_mspmrelver(1, &MSPMRELVER);
	if (DB_error_code != DB_SUCCESS)
	{
		//SPM-0005 : 제조명세가 존재하지 않습니다.
		strcpy(s_msg_code, "SPM-0005");
		TRS.add_fieldmsg(out_node, "MSPMRELVER SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "SPEC_REL_ID", MP_STR, sizeof(MSPMRELVER.SPEC_REL_ID), MSPMRELVER.SPEC_REL_ID);
		TRS.add_fieldmsg(out_node, "SPEC_REL_VER", MP_STR, sizeof(MSPMRELVER.SPEC_REL_VER), MSPMRELVER.SPEC_REL_VER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	MSPMRELVER.APPROVAL_FLAG = ' ';
	MSPMRELVER.RELEASE_FLAG = ' ';

	DBC_update_mspmrelver(1, &MSPMRELVER);
	if (DB_error_code != DB_SUCCESS)
	{
		//SPM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
		strcpy(s_msg_code, "SPM-0004");
		TRS.add_fieldmsg(out_node, "MSPMRELVER UPDATE", MP_NVST);
		TRS.add_fieldmsg(out_node, "SPEC_REL_ID", MP_STR, sizeof(MSPMRELVER.SPEC_REL_ID), MSPMRELVER.SPEC_REL_ID);
		TRS.add_fieldmsg(out_node, "SPEC_REL_VER", MP_STR, sizeof(MSPMRELVER.SPEC_REL_VER), MSPMRELVER.SPEC_REL_VER);
		TRS.add_fieldmsg(out_node, "APPROVAL_FLAG", MP_STR, sizeof(MSPMRELVER.APPROVAL_FLAG), MSPMRELVER.APPROVAL_FLAG);
		TRS.add_fieldmsg(out_node, "RELEASE_FLAG", MP_STR, sizeof(MSPMRELVER.RELEASE_FLAG), MSPMRELVER.RELEASE_FLAG);

		return MP_FALSE;
	}


    return MP_TRUE;
}




int CUS_QCM_update_spec_After(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
	//승인되어있으면 스펙업데이트가 안되서 스펙업데이트할때 풀었다가 끝나면 다시 승인되도록 수정(20220418)

	char s_msg_code[MP_SIZE_MSG];

	struct MSPMRELVER_TAG MSPMRELVER;


	DBC_init_mspmrelver(&MSPMRELVER);
	TRS.copy(MSPMRELVER.SPEC_REL_ID, sizeof(MSPMRELVER.SPEC_REL_ID), in_node, "SPEC_REL_ID");
	MSPMRELVER.SPEC_REL_VER = TRS.get_int(in_node, "SPEC_REL_VER");
	DBC_select_mspmrelver(1, &MSPMRELVER);
	if (DB_error_code != DB_SUCCESS)
	{
		//SPM-0005 : 제조명세가 존재하지 않습니다.
		strcpy(s_msg_code, "SPM-0005");
		TRS.add_fieldmsg(out_node, "MSPMRELVER SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "SPEC_REL_ID", MP_STR, sizeof(MSPMRELVER.SPEC_REL_ID), MSPMRELVER.SPEC_REL_ID);
		TRS.add_fieldmsg(out_node, "SPEC_REL_VER", MP_STR, sizeof(MSPMRELVER.SPEC_REL_VER), MSPMRELVER.SPEC_REL_VER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	MSPMRELVER.APPROVAL_FLAG = 'Y';
	MSPMRELVER.RELEASE_FLAG = 'Y';


	DBC_update_mspmrelver(1, &MSPMRELVER);
	if (DB_error_code != DB_SUCCESS)
	{
		//SPM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
		strcpy(s_msg_code, "SPM-0004");
		TRS.add_fieldmsg(out_node, "MSPMRELVER UPDATE", MP_NVST);
		TRS.add_fieldmsg(out_node, "SPEC_REL_ID", MP_STR, sizeof(MSPMRELVER.SPEC_REL_ID), MSPMRELVER.SPEC_REL_ID);
		TRS.add_fieldmsg(out_node, "SPEC_REL_VER", MP_STR, sizeof(MSPMRELVER.SPEC_REL_VER), MSPMRELVER.SPEC_REL_VER);
		TRS.add_fieldmsg(out_node, "APPROVAL_FLAG", MP_STR, sizeof(MSPMRELVER.APPROVAL_FLAG), MSPMRELVER.APPROVAL_FLAG);
		TRS.add_fieldmsg(out_node, "RELEASE_FLAG", MP_STR, sizeof(MSPMRELVER.RELEASE_FLAG), MSPMRELVER.RELEASE_FLAG);

		return MP_FALSE;
	}


    return MP_TRUE;
}

