/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_Batch_Oee.c
Description : Batch OEE(설비종합효율 Procedure 실행)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/01/18                 Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"


int CUS_RAS_BATCH_OEE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Batch_Oee_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_RAS_Batch_Oee()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Batch_Oee(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_BATCH_OEE(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Batch_Oee", out_node);
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
CUS_RAS_BATCH_OEE()
- Main sub function of "CUS_RAS_Batch_Oee" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_BATCH_OEE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    char s_flag[2];
    char s_factory[10];    
    char s_area_id[20];
    char s_sub_area_id[20];
    char s_line_id[20];
    char s_oper[10];
    char s_res_id[20];
    char s_start_date[10];
    char s_end_date[10];    
    char s_cmf_1[30];
    char s_cmf_2[30];
    char s_cmf_3[30];
    char s_cmf_4[30];
    char s_cmf_5[30];
    
    char s_err_code[10];
    char s_msg_rst_code[30];
    char s_msg_rep_word[200];

    memset(s_flag, 0x00, sizeof(s_flag)); 
    memset(s_factory, 0x00, sizeof(s_factory));
    memset(s_area_id, 0x00, sizeof(s_area_id));    
    memset(s_sub_area_id, 0x00, sizeof(s_sub_area_id));
    memset(s_line_id, 0x00, sizeof(s_line_id));
    memset(s_oper, 0x00, sizeof(s_oper));    
    memset(s_res_id, 0x00, sizeof(s_res_id));
    memset(s_start_date, 0x00, sizeof(s_start_date));
    memset(s_end_date, 0x00, sizeof(s_end_date));
    memset(s_cmf_1, 0x00, sizeof(s_cmf_1));
    memset(s_cmf_2, 0x00, sizeof(s_cmf_2));
    memset(s_cmf_3, 0x00, sizeof(s_cmf_3));
    memset(s_cmf_4, 0x00, sizeof(s_cmf_4));
    memset(s_cmf_5, 0x00, sizeof(s_cmf_5));
    memset(s_err_code, 0x00, sizeof(s_err_code));
    memset(s_msg_rst_code, 0x00, sizeof(s_msg_rst_code));
    memset(s_msg_rep_word, 0x00, sizeof(s_msg_rep_word));

    LOG_head("CUS_RAS_Batch_Oee");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (CUS_RAS_Batch_Oee_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    
    memcpy(s_factory, TRS.get_string(in_node, IN_FACTORY), strlen(TRS.get_string(in_node, IN_FACTORY)));
    memcpy(s_area_id, TRS.get_string(in_node, "AREA_ID"), strlen(TRS.get_string(in_node, "AREA_ID")));
    memcpy(s_sub_area_id, TRS.get_string(in_node, "SUB_AREA_ID"), strlen(TRS.get_string(in_node, "SUB_AREA_ID")));
    memcpy(s_line_id, TRS.get_string(in_node, "LINE_ID"), strlen(TRS.get_string(in_node, "LINE_ID")));
    memcpy(s_oper, TRS.get_string(in_node, "OPER"), strlen(TRS.get_string(in_node, "OPER")));
    memcpy(s_flag, TRS.get_string(in_node, "FLAG"), strlen(TRS.get_string(in_node, "FLAG")));
    memcpy(s_res_id, TRS.get_string(in_node, "RES_ID"), strlen(TRS.get_string(in_node, "RES_ID")));
    memcpy(s_start_date, TRS.get_string(in_node, "START_DATE"), strlen(TRS.get_string(in_node, "START_DATE")));
    memcpy(s_end_date, TRS.get_string(in_node, "END_DATE"), strlen(TRS.get_string(in_node, "END_DATE")));
    memcpy(s_cmf_1, TRS.get_string(in_node, "CMF_1"), strlen(TRS.get_string(in_node, "CMF_1")));
    memcpy(s_cmf_2, TRS.get_string(in_node, "CMF_2"), strlen(TRS.get_string(in_node, "CMF_2")));
    memcpy(s_cmf_3, TRS.get_string(in_node, "CMF_3"), strlen(TRS.get_string(in_node, "CMF_3")));
    memcpy(s_cmf_4, TRS.get_string(in_node, "CMF_4"), strlen(TRS.get_string(in_node, "CMF_4")));
    memcpy(s_cmf_5, TRS.get_string(in_node, "CMF_5"), strlen(TRS.get_string(in_node, "CMF_5")));

    DBU_batch_job_exec_oee(s_flag, s_factory, s_start_date, s_end_date,  s_area_id, s_sub_area_id, s_line_id, s_oper, s_res_id, s_cmf_1, s_cmf_2, s_cmf_3, s_cmf_4, s_cmf_5, s_err_code, s_msg_rst_code, s_msg_rep_word);
    
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "QCM-0004");
        TRS.add_fieldmsg(out_node, "Pkg_RAS_Summary EXEC", DT_NOVALUESTRING);
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
CUS_RAS_Batch_Oee_Validation()
- Validation Check sub function of "CUS_RAS_BATCH_OEE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Batch_Oee_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }
    if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

        return MP_FALSE;
    }
    if (COM_isnullspace(TRS.get_string(in_node, "START_DATE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "START_DATE", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "END_DATE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "END_DATE", MP_NVST);

        return MP_FALSE;
    }


    return MP_TRUE;
}
