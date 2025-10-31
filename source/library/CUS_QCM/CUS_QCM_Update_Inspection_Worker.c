/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Update_Inspection_Worker.c
Description : Tran Inspection Worker Update function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/22  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Update_Inspection_Worker_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Update_Inspection_Worker()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_Inspection_Worker(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_UPDATE_INSPECTION_WORKER(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Update_Inspection_Worker", out_node);
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
CUS_QCM_UPDATE_INSPECTION_WORKER()
- Main sub function of "CUS_QCM_Update_Inspection_Worker" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_INSPECTION_WORKER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPWRK_TAG CQCMISPWRK;

	char s_sys_time[14];

	TRSNode **data_list;
	int i_data_count;
	int i_select_count;


	//TRSNode *collect_in_node;
	//TRSNode **data_list;

	//int i_data_count;

	//int i_select_count;

    LOG_head("CUS_QCM_Update_Inspection_Worker");
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
    if (CUS_QCM_Update_Inspection_Worker_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   

	    //검사자 등록
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

		data_list = TRS.get_list(in_node, "WORKER_LIST");
		i_data_count = TRS.get_item_count(in_node, "WORKER_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_cqcmispwrk(&CQCMISPWRK);
			TRS.copy(CQCMISPWRK.FACTORY, sizeof(CQCMISPWRK.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPWRK.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			TRS.copy(CQCMISPWRK.WORKER_ID, sizeof(CQCMISPWRK.WORKER_ID), data_list[i], "WORKER_ID");

			TRS.copy(CQCMISPWRK.WORKER_DESC, sizeof(CQCMISPWRK.WORKER_DESC), data_list[i], "WORKER_DESC");
			TRS.copy(CQCMISPWRK.WORK_TYPE, sizeof(CQCMISPWRK.WORK_TYPE), data_list[i], "WORK_TYPE");

			i_select_count = (int)DBU_select_cqcmispwrk_scalar(1, &CQCMISPWRK);
			if (i_select_count > 0)
			{
				DBU_update_cqcmispwrk(1, &CQCMISPWRK);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPWRK UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPWRK.INSP_ID), CQCMISPWRK.INSP_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				DBU_insert_cqcmispwrk(&CQCMISPWRK);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPWRK INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPWRK.INSP_ID), CQCMISPWRK.INSP_ID);
					
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

		}



    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Update_Inspection_Worker_Validation()
- Validation Check sub function of "CUS_QCM_UPDATE_INSPECTION_WORKER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_Inspection_Worker_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12345678") == MP_FALSE)
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
