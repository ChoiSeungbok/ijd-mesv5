/******************************************************************************'

    System      : MESplus
    Module      : CUS_QCM
    File Name   : CUS_QCM_update_cus_qcm_cample_analysis.c
    Description : CUS_QCM_Sample_Analysis Setup function module

    MES Version : 5.3.4 ~

    Function List
        - CUS_QCM_Update_CUS_QCM_Sample_Analysis()
            + Create/Update/Delete CUS_QCM_Customer_Claim definition
        - CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS()
            + Main sub function of CUS_QCM_Update_CUS_QCM_Sample_Analysis function
            + Create/Update/Delete CUS_QCM_Sample_Analysis definition
        - CUS_QCM_Update_CUS_QCM_Sample_Analysis_Validation()
            + Main sub function of CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS function
            + Check the condition for create/update/delete CUS_QCM_Sample_Analysis
    Detail Description
        - CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS()
            + h_proc_step
                + MP_STEP_CREATE : Create CUS_QCM_Sample_Analysis definition
                + MP_STEP_UPDATE : Update CUS_QCM_Sample_Analysis definition
                + MP_STEP_DELETE : Delete CUS_QCM_Sample_Analysis definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2024-12-11             Create by Generator

    Copyright(C) 1998-2024 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_QCM_common.h"


int CUS_QCM_Update_CUS_QCM_Sample_Analysis_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Sample_Analysis()
        - Create/Update/Delete CUS_QCM_Sample_Analysis definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Sample_Analysis(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS", out_node);

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
    CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS()
        - Main sub function of "CUS_QCM_Update_CUS_QCM_Sample_Analysis" function
        - Create/Update/Delete CUS_QCM_Customer_Claim definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMSPLMST_TAG CQCMSPLMST;
    struct CQCMSPLMST_TAG CQCMSPLMST_o;
    struct CQCMISPLOS_TAG CQCMISPLOS;

    char   s_sys_time[14];
    char s_file_no[10];
    TRSNode* gen_in_node;
    TRSNode* cmn_out;

    TRSNode** loss_list;
    int i_loss_count;

    LOG_head("CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Sample_Analysis",
                             MP_UPOINT_BEFORE,
                             in_node,
                             out_node) == MP_FALSE)     return MP_FALSE;
    if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE;
    */

    memset(s_sys_time, ' ', sizeof(s_sys_time));
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
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

    if(CUS_QCM_Update_CUS_QCM_Sample_Analysis_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cqcmsplmst(&CQCMSPLMST);
    TRS.copy(CQCMSPLMST.FACTORY, sizeof(CQCMSPLMST.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMSPLMST.REPORT_NO, sizeof(CQCMSPLMST.REPORT_NO), in_node, "REPORT_NO");
    TRS.copy(CQCMSPLMST.CUST_NO, sizeof(CQCMSPLMST.CUST_NO), in_node, "CUST_NO");
    TRS.copy(CQCMSPLMST.CUST_NAME, sizeof(CQCMSPLMST.CUST_NAME), in_node, "CUST_NAME");
    TRS.copy(CQCMSPLMST.EVENT_DATE, sizeof(CQCMSPLMST.EVENT_DATE), in_node, "EVENT_DATE");
    TRS.copy(CQCMSPLMST.RECEIVED_DATE_1, sizeof(CQCMSPLMST.RECEIVED_DATE_1), in_node, "RECEIVED_DATE_1");
    TRS.copy(CQCMSPLMST.RECEIVED_DATE_2, sizeof(CQCMSPLMST.RECEIVED_DATE_2), in_node, "RECEIVED_DATE_2");
    TRS.copy(CQCMSPLMST.RECEIVED_DATE_3, sizeof(CQCMSPLMST.RECEIVED_DATE_3), in_node, "RECEIVED_DATE_3");
    TRS.copy(CQCMSPLMST.GRADE, sizeof(CQCMSPLMST.GRADE), in_node, "GRADE");
    TRS.copy(CQCMSPLMST.MAT_ID, sizeof(CQCMSPLMST.MAT_ID), in_node, "MAT_ID");
    TRS.copy(CQCMSPLMST.MAT_DESC, sizeof(CQCMSPLMST.MAT_DESC), in_node, "MAT_DESC");
    TRS.copy(CQCMSPLMST.CLOSURE_DATE, sizeof(CQCMSPLMST.CLOSURE_DATE), in_node, "CLOSURE_DATE");
    TRS.copy(CQCMSPLMST.SHARE_DATE, sizeof(CQCMSPLMST.SHARE_DATE), in_node, "SHARE_DATE");
    TRS.copy(CQCMSPLMST.SAL_GROUP, sizeof(CQCMSPLMST.SAL_GROUP), in_node, "SAL_GROUP");
    TRS.copy(CQCMSPLMST.SAL_USER, sizeof(CQCMSPLMST.SAL_USER), in_node, "SAL_USER");
    CQCMSPLMST.ANALYZE_STATUS = TRS.get_char(in_node, "ANALYZE_STATUS");

    CQCMSPLMST.COST_QTY_01 = TRS.get_int(in_node, "COST_QTY_01");
    CQCMSPLMST.COST_QTY_02 = TRS.get_int(in_node, "COST_QTY_02");
    CQCMSPLMST.COST_QTY_03 = TRS.get_int(in_node, "COST_QTY_03");
    CQCMSPLMST.COST_MONTH = TRS.get_int(in_node, "COST_MONTH");
    TRS.copy(CQCMSPLMST.FILE_NO_01, sizeof(CQCMSPLMST.FILE_NO_01), in_node, "FILE_NO_01");
    TRS.copy(CQCMSPLMST.FILE_PATH_01, sizeof(CQCMSPLMST.FILE_PATH_01), in_node, "FILE_PATH_01");
    TRS.copy(CQCMSPLMST.FILE_NO_02, sizeof(CQCMSPLMST.FILE_NO_02), in_node, "FILE_NO_02");
    TRS.copy(CQCMSPLMST.FILE_PATH_02, sizeof(CQCMSPLMST.FILE_PATH_02), in_node, "FILE_PATH_02");
    TRS.copy(CQCMSPLMST.FILE_NO_03, sizeof(CQCMSPLMST.FILE_NO_03), in_node, "FILE_NO_03");
    TRS.copy(CQCMSPLMST.FILE_PATH_03, sizeof(CQCMSPLMST.FILE_PATH_03), in_node, "FILE_PATH_03");
    TRS.copy(CQCMSPLMST.FILE_NO_04, sizeof(CQCMSPLMST.FILE_NO_04), in_node, "FILE_NO_04");
    TRS.copy(CQCMSPLMST.FILE_PATH_04, sizeof(CQCMSPLMST.FILE_PATH_04), in_node, "FILE_PATH_04");
    TRS.copy(CQCMSPLMST.FILE_NO_05, sizeof(CQCMSPLMST.FILE_NO_05), in_node, "FILE_NO_05");
    TRS.copy(CQCMSPLMST.FILE_PATH_05, sizeof(CQCMSPLMST.FILE_PATH_05), in_node, "FILE_PATH_05");
    TRS.copy(CQCMSPLMST.COMMENT_01, sizeof(CQCMSPLMST.COMMENT_01), in_node, "COMMENT_01");
    TRS.copy(CQCMSPLMST.COMMENT_02, sizeof(CQCMSPLMST.COMMENT_02), in_node, "COMMENT_02");
    TRS.copy(CQCMSPLMST.COMMENT_03, sizeof(CQCMSPLMST.COMMENT_03), in_node, "COMMENT_03");
    TRS.copy(CQCMSPLMST.COMMENT_04, sizeof(CQCMSPLMST.COMMENT_04), in_node, "COMMENT_04");
    TRS.copy(CQCMSPLMST.COMMENT_05, sizeof(CQCMSPLMST.COMMENT_05), in_node, "COMMENT_05");
    TRS.copy(CQCMSPLMST.COMMENT_06, sizeof(CQCMSPLMST.COMMENT_06), in_node, "COMMENT_06");
    TRS.copy(CQCMSPLMST.COMMENT_07, sizeof(CQCMSPLMST.COMMENT_07), in_node, "COMMENT_07");
    TRS.copy(CQCMSPLMST.COMMENT_08, sizeof(CQCMSPLMST.COMMENT_08), in_node, "COMMENT_08");
    TRS.copy(CQCMSPLMST.COMMENT_09, sizeof(CQCMSPLMST.COMMENT_09), in_node, "COMMENT_09");
    TRS.copy(CQCMSPLMST.COMMENT_10, sizeof(CQCMSPLMST.COMMENT_10), in_node, "COMMENT_10");
    TRS.copy(CQCMSPLMST.CMF_01, sizeof(CQCMSPLMST.CMF_01), in_node, "CMF_01");
    TRS.copy(CQCMSPLMST.CMF_02, sizeof(CQCMSPLMST.CMF_02), in_node, "CMF_02");
    TRS.copy(CQCMSPLMST.CMF_03, sizeof(CQCMSPLMST.CMF_03), in_node, "CMF_03");
    TRS.copy(CQCMSPLMST.CMF_04, sizeof(CQCMSPLMST.CMF_04), in_node, "CMF_04");
    TRS.copy(CQCMSPLMST.CMF_05, sizeof(CQCMSPLMST.CMF_05), in_node, "CMF_05");
    TRS.copy(CQCMSPLMST.CMF_06, sizeof(CQCMSPLMST.CMF_06), in_node, "CMF_06");
    TRS.copy(CQCMSPLMST.CMF_07, sizeof(CQCMSPLMST.CMF_07), in_node, "CMF_07");
    TRS.copy(CQCMSPLMST.CMF_08, sizeof(CQCMSPLMST.CMF_08), in_node, "CMF_08");
    TRS.copy(CQCMSPLMST.CMF_09, sizeof(CQCMSPLMST.CMF_09), in_node, "CMF_09");
    TRS.copy(CQCMSPLMST.CMF_10, sizeof(CQCMSPLMST.CMF_10), in_node, "CMF_10");
    CQCMSPLMST.USE_YN = TRS.get_char(in_node, "USE_YN");
    TRS.copy(CQCMSPLMST.CREATE_USER_ID, sizeof(CQCMSPLMST.CREATE_USER_ID), in_node, "CREATE_USER_ID");
    TRS.copy(CQCMSPLMST.CREATE_TIME, sizeof(CQCMSPLMST.CREATE_TIME), in_node, "CREATE_TIME");
    TRS.copy(CQCMSPLMST.UPDATE_USER_ID, sizeof(CQCMSPLMST.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
    TRS.copy(CQCMSPLMST.UPDATE_TIME, sizeof(CQCMSPLMST.UPDATE_TIME), in_node, "UPDATE_TIME");

//step 1 : 저장
//step 2 : 수정
//step 3 : 삭제

    if(TRS.get_procstep(in_node) == '1')
    {

        //----[Addtional Logic for Create Case]----



        memset(s_file_no, ' ', sizeof(s_file_no));


        gen_in_node = TRS.add_node(in_node, "gen_in_node");

        //ID 발번            
        CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
        TRS.add_string(gen_in_node, "RULE_ID", "SAMPLE_ANALYSIS", strlen("SAMPLE_ANALYSIS"));
        TRS.add_char(gen_in_node, "PROCSTEP", '2');

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        memcpy(s_file_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

        TRS.free_node(cmn_out);


        memcpy(CQCMSPLMST.REPORT_NO, s_file_no, sizeof(s_file_no));
        TRS.copy(CQCMSPLMST.CREATE_USER_ID, sizeof(CQCMSPLMST.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMSPLMST.CREATE_TIME, s_sys_time, sizeof(CQCMSPLMST.CREATE_TIME));
        DBU_insert_cqcmsplmst(&CQCMSPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMSPLMST INSERT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST.FACTORY), CQCMSPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST.REPORT_NO), CQCMSPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

  



        TRS.add_string(out_node, "REPORT_NO", s_file_no, sizeof(s_file_no));








    }
    else if(TRS.get_procstep(in_node) == '2')
    {
        DBU_init_cqcmsplmst(&CQCMSPLMST_o);
        TRS.copy(CQCMSPLMST_o.FACTORY, sizeof(CQCMSPLMST_o.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CQCMSPLMST_o.REPORT_NO, sizeof(CQCMSPLMST_o.REPORT_NO), in_node, "REPORT_NO");
        DBU_select_cqcmsplmst_for_update(1, &CQCMSPLMST_o);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMSPLMST SELECT FOR UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST_o.FACTORY), CQCMSPLMST_o.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST_o.REPORT_NO), CQCMSPLMST_o.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //----[Addtional Logic for Update Case]----

        memcpy(CQCMSPLMST.CREATE_USER_ID, CQCMSPLMST_o.CREATE_USER_ID, sizeof(CQCMSPLMST.CREATE_USER_ID));
        memcpy(CQCMSPLMST.CREATE_TIME, CQCMSPLMST_o.CREATE_TIME, sizeof(CQCMSPLMST.CREATE_TIME));
        TRS.copy(CQCMSPLMST.UPDATE_USER_ID, sizeof(CQCMSPLMST.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMSPLMST.UPDATE_TIME, s_sys_time, sizeof(CQCMSPLMST.UPDATE_TIME));

        DBU_update_cqcmsplmst(1, &CQCMSPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMSPLMST UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST.FACTORY), CQCMSPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST.REPORT_NO), CQCMSPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        




    }
    else if(TRS.get_procstep(in_node) == '3')
    {
        DBU_delete_cqcmsplmst(1, &CQCMSPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMSPLMST DELETE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST.FACTORY), CQCMSPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST.REPORT_NO), CQCMSPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Sample_Analysis",
                             MP_UPOINT_AFTER,
                             in_node,
                             out_node) == MP_FALSE) return MP_FALSE;
    */

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
} 

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Sample_Analysis_Validation()
        - Main sub function of "CUS_QCM_UPDATE_CUS_QCM_SAMPLE_ANALYSIS" function
        - Check the condition for create/update/delete CUS_QCM_Customer_Claim
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Sample_Analysis_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMSPLMST_TAG CQCMSPLMST;
    struct MWIPFACDEF_TAG MWIPFACDEF;

    /* ProcStep Validation */
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "123") == MP_FALSE)
    {
        return MP_FALSE;
    }

    /* Factory Validation */
    if(COM_isnullspace(TRS.get_factory(in_node)) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_QCM-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        return MP_FALSE;
    }

    DBC_init_mwipfacdef(&MWIPFACDEF);
    TRS.copy(MWIPFACDEF.FACTORY, sizeof(MWIPFACDEF.FACTORY), in_node, IN_FACTORY);
    DBC_select_mwipfacdef(1, &MWIPFACDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0005");
        TRS.add_fieldmsg(out_node, "MWIPFACDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFACDEF.FACTORY), MWIPFACDEF.FACTORY);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        return MP_FALSE;
    }



    DBU_init_cqcmsplmst(&CQCMSPLMST);
    TRS.copy(CQCMSPLMST.FACTORY, sizeof(CQCMSPLMST.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMSPLMST.REPORT_NO, sizeof(CQCMSPLMST.REPORT_NO), in_node, "REPORT_NO");
    DBU_select_cqcmsplmst(1, &CQCMSPLMST);
    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        if(DB_error_code == DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-XXXX");
            TRS.add_fieldmsg(out_node, "CQCMSPLMST SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST.FACTORY), CQCMSPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST.REPORT_NO), CQCMSPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    else if(TRS.get_procstep(in_node) == MP_STEP_UPDATE || TRS.get_procstep(in_node) == MP_STEP_DELETE)
    {

        /* REPORT_NO Validation */
        if (COM_isnullspace(TRS.get_string(in_node, "REPORT_NO")) == MP_TRUE)
        {
            strcpy(s_msg_code, "CUS_QCM-0001");
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CUS_QCM-XXXX");
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
            }
            else
            {
                strcpy(s_msg_code, "CUS_QCM-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
            }

            TRS.add_fieldmsg(out_node, "CQCMSPLMST SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMSPLMST.FACTORY), CQCMSPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMSPLMST.REPORT_NO), CQCMSPLMST.REPORT_NO);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_SETUP;
            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

