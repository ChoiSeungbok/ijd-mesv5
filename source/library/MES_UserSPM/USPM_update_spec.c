/*******************************************************************************

    System      : MESplus
    Module      : User Routine for SPM
    File Name   : USPM_Update_Spec.c
    Description : User Routine for SPM_Update_Spec

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2012/11/13  Miracom        Create

    Copyright(C) 1998-2012 Miracom,Inc.
    All rights reserved.EDC_View_Attach_Character_List

*******************************************************************************/

#include "USPM_common.h"

int SPM_Update_Spec_Before_1(TRSNode *in_node, TRSNode *out_node)
{
	/* TODO : Insert your code */

	if (TRS.get_procstep(in_node) != MP_STEP_CREATE) {


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
	}


	return MP_TRUE;



}

int SPM_Update_Spec_After_1(TRSNode *in_node, TRSNode *out_node)
{



	/* TODO : Insert your code */
	//승인되어있으면 스펙업데이트가 안되서 스펙업데이트할때 풀었다가 끝나면 다시 승인되도록 수정(20220418)

	if (TRS.get_procstep(in_node) != MP_STEP_DELETE) {

		char s_msg_code[MP_SIZE_MSG];

		struct MSPMRELVER_TAG MSPMRELVER;


		DBC_init_mspmrelver(&MSPMRELVER);
		TRS.copy(MSPMRELVER.SPEC_REL_ID, sizeof(MSPMRELVER.SPEC_REL_ID), in_node, "SPEC_REL_ID");
		MSPMRELVER.SPEC_REL_VER = TRS.get_int(in_node, "SPEC_REL_VER");
		DBC_select_mspmrelver(1, &MSPMRELVER);
		if (DB_error_code != DB_SUCCESS)
		{
			/*
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
			*/

			return MP_TRUE;
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

	}
	return MP_TRUE;
}

