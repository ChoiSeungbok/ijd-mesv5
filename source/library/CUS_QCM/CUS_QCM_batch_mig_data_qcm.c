/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Batch_Mig_Data_Qcm.c
Description : 

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/20                 Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"


int CUS_QCM_Batch_Mig_Data_Qcm_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Batch_Mig_Data_Qcm()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Batch_Mig_Data_Qcm(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_BATCH_MIG_DATA_QCM(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_Batch_Mig_Data_Qcm", out_node);
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
CUS_QCM_BATCH_MIG_DATA_QCM()
- Main sub function of "CUS_QCM_Batch_Mig_Data_Qcm" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_BATCH_MIG_DATA_QCM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{		
	char s_factory[10];
	char s_area[10];
	char s_qcm_insp_type[10];
	char s_qcm_oper[10];
	char s_insp_reproc_flag[10];
	char s_mat_code[30];
	char s_qc_no[30];
	char s_lot_no[25];
	char s_err_code[10];
	char s_msg_rst_code[30];
	char s_msg_rep_word[200];
	char s_insp_from_date[10];
	char s_insp_to_date[10];

	memset(s_factory, 0x00, sizeof(s_factory));
	memset(s_area, 0x00, sizeof(s_area));
	memset(s_qcm_insp_type, 0x00, sizeof(s_qcm_insp_type));
	memset(s_qcm_oper, 0x00, sizeof(s_qcm_oper));
	memset(s_insp_reproc_flag, 0x00, sizeof(s_insp_reproc_flag));
	memset(s_mat_code, 0x00, sizeof(s_mat_code));
	memset(s_qc_no, 0x00, sizeof(s_qc_no));
	memset(s_lot_no, 0x00, sizeof(s_lot_no));
	memset(s_err_code, 0x00, sizeof(s_err_code));
	memset(s_msg_rst_code, 0x00, sizeof(s_msg_rst_code));
	memset(s_msg_rep_word, 0x00, sizeof(s_msg_rep_word));
	memset(s_insp_from_date, 0x00, sizeof(s_insp_from_date));
	memset(s_insp_to_date, 0x00, sizeof(s_insp_to_date));
	
	LOG_head("CUS_QCM_Batch_Mig_Data_Qcm");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);
		
	if (CUS_QCM_Batch_Mig_Data_Qcm_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memcpy(s_factory, TRS.get_string(in_node, IN_FACTORY), strlen(TRS.get_string(in_node, IN_FACTORY)));
	memcpy(s_area, TRS.get_string(in_node, "AREA"), strlen(TRS.get_string(in_node, "AREA")));
	memcpy(s_qcm_insp_type, TRS.get_string(in_node, "QCM_INSP_TYPE"), strlen(TRS.get_string(in_node, "QCM_INSP_TYPE")));
	memcpy(s_qcm_oper, TRS.get_string(in_node, "QCM_OPER"), strlen(TRS.get_string(in_node, "QCM_OPER")));	
	memcpy(s_insp_reproc_flag, TRS.get_string(in_node, "INSP_REPROC_FLAG"), strlen(TRS.get_string(in_node, "INSP_REPROC_FLAG")));
	memcpy(s_mat_code, TRS.get_string(in_node, "MAT_CODE"), strlen(TRS.get_string(in_node, "MAT_CODE")));
	memcpy(s_qc_no, TRS.get_string(in_node, "QC_NO"), strlen(TRS.get_string(in_node, "QC_NO")));
	memcpy(s_lot_no, TRS.get_string(in_node, "LOT_NO"), strlen(TRS.get_string(in_node, "LOT_NO")));
    memcpy(s_insp_from_date, TRS.get_string(in_node, "INSP_FROM_DATE"), strlen(TRS.get_string(in_node, "INSP_FROM_DATE")));
	memcpy(s_insp_to_date, TRS.get_string(in_node, "INSP_TO_DATE"), strlen(TRS.get_string(in_node, "INSP_TO_DATE")));

	DBU_batch_job_exec_qcm_migration(s_factory, s_area, s_qcm_insp_type, s_qcm_oper, s_insp_from_date, s_insp_to_date, s_insp_reproc_flag, s_mat_code, s_qc_no, s_lot_no, s_err_code, s_msg_rst_code, s_msg_rep_word);
    
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "QCM-0004");
        TRS.add_fieldmsg(out_node, "PR_MIG_QCM_DATA_QCM EXEC", DT_NOVALUESTRING);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.set_char(out_node, "OUT_ERR_CODE", 'E');
        TRS.set_string(out_node, "OUT_MSG_CODE", "QCM-0004", sizeof("QCM-0004"));
        TRS.set_string(out_node, "OUT_MSG_REP_WORD", DB_error_msg, sizeof(s_msg_rep_word));

        return MP_FALSE;
    }

    TRS.set_char(out_node, "OUT_ERR_CODE", s_err_code[0]);

    if (s_err_code[0] == 'E')//실패시
    {     
        strcpy(s_msg_code, "QCM-0077");//QCM-0077 : 마이그레이션이  정상적으로 처리되지 않았습니다. 상세를 확인해주세요.
        TRS.add_dberrmsg(out_node, s_msg_rep_word);

        TRS.set_string(out_node, "OUT_MSG_CODE", s_msg_rst_code, sizeof(s_msg_rst_code));
        TRS.set_string(out_node, "OUT_MSG_REP_WORD", s_msg_rep_word, sizeof(s_msg_rep_word));

        return MP_FALSE;
    }
    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Batch_Mig_Data_Qcm_Validation()
- Validation Check sub function of "CUS_QCM_BATCH_MIG_DATA_QCM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Batch_Mig_Data_Qcm_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{	
	if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		return MP_FALSE;
	}
    if (COM_isnullspace(TRS.get_string(in_node, "INSP_FROM_DATE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "INSP_FROM_DATE", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }
    if (COM_isnullspace(TRS.get_string(in_node, "INSP_TO_DATE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "INSP_TO_DATE", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }
   

	return MP_TRUE;
}
