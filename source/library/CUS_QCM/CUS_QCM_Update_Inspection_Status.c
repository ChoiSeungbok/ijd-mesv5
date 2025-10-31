/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Update_Inspection_Status.c
Description : Tran Inspection Status Update function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/28  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Update_Inspection_Status_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Update_Inspection_Status()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_Inspection_Status(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_UPDATE_INSPECTION_STATUS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Update_Inspection_Status", out_node);
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
CUS_QCM_UPDATE_INSPECTION_STATUS()
- Main sub function of "CUS_QCM_Update_Inspection_Status" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_INSPECTION_STATUS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct MINVDLVLOT_TAG MINVDLVLOT;

	char s_sys_time[14];


	//TRSNode *collect_in_node;
	//TRSNode **data_list;

	//int i_data_count;

	//int i_select_count;

    LOG_head("CUS_QCM_Update_Inspection_Status");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


    /* Validation Check */
    if (CUS_QCM_Update_Inspection_Status_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   



	//접수
	if (TRS.get_procstep(in_node) == '1')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVLOT.DLV_LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
		DBU_select_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");

			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		
		//memcpy(CSHPORDDTL.UPDATE_TIME, gs_sys_time, sizeof(CSHPORDDTL.UPDATE_TIME));
		
		
		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_RECEIVE;  // RECEIVE ('R')
		memcpy(CQCMISPSTS.CMF_1, gs_sys_time, sizeof(gs_sys_time));
		memcpy(CQCMISPSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");

			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		/*
		if (TRS.get_char(in_node, "INSP_STATUS") == MP_CQMS_STATUS_CANCEL)
		{
			MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_CANCEL;
			memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_minvdlvlot(2, &MINVDLVLOT);
			// close
		}
		else if (TRS.get_char(in_node, "INSP_STATUS") == MP_CQMS_STATUS_REQUEST)
		{
			MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_REQUEST;
			memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_minvdlvlot(2, &MINVDLVLOT);
			//Requesst
		}
		else if (TRS.get_char(in_node, "INSP_STATUS") == MP_CQMS_STATUS_RECEIVE)
		{
			//Receipt
			MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_RECEIVE;
			memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_minvdlvlot(2, &MINVDLVLOT);
		}
		else if (TRS.get_char(in_node, "INSP_STATUS") == MP_CQMS_STATUS_COMPLETE)
		{
			//Complete
			MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_COMPLETE;
			memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_minvdlvlot(2, &MINVDLVLOT);
		}
		*/

		MINVDLVLOT.INSP_STATUS[0] = MP_CQMS_STATUS_RECEIVE;
		memcpy(MINVDLVLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_minvdlvlot(2, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");

			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (CQCMISPSTS.INSP_STATUS == MP_CQMS_STATUS_COMPLETE)
		{
			//QCM-0069 : 이미 완료처리된 검사입니다.
			strcpy(s_msg_code, "QCM-0069");

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (CQCMISPSTS.INSP_STATUS == MP_CQMS_STATUS_CANCEL)
		{
			//QCM-0070 : 이미 취소처리된 검사입니다.
			strcpy(s_msg_code, "QCM-0070");

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		

		CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_HOLD;  // HOLD ('H')
		memcpy(CQCMISPSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");

			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



	}
	else if (TRS.get_procstep(in_node) == '3')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		//CQCMISPSTS.INSP_STATUS = MP_CQMS_STATUS_HOLD;  // HOLD ('H')
		memcpy(CQCMISPSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
		TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");

		DBU_update_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");

			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Update_Inspection_Status_Validation()
- Validation Check sub function of "CUS_QCM_UPDATE_INSPECTION_STATUS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_Inspection_Status_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
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
