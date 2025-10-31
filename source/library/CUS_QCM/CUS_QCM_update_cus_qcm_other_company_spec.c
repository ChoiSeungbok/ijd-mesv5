/******************************************************************************'

    System      : MESplus
    Module      : CUS_QCM
    File Name   : CUS_QCM_Update_CUS_QCM_Other_Company_Spec.c
    Description : CUS_QCM_Update_CUS_QCM_Other_Company_Spec Setup function module

    MES Version : 5.3.4 ~

    Function List
        - CUS_QCM_Update_CUS_QCM_Other_Company_Spec()
            + Create/Update/Delete CUS_QCM_Customer_Claim definition
        - CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC()
            + Main sub function of CUS_QCM_Update_CUS_QCM_Other_Company_Spec function
            + Create/Update/Delete CUS_QCM_Customer_Voc definition
        - CUS_QCM_Update_CUS_QCM_Other_Company_Spec_Validation()
            + Main sub function of CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC function
            + Check the condition for create/update/delete CUS_QCM_Customer_Voc
    Detail Description
        - CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC()
            + h_proc_step
                + MP_STEP_CREATE : Create CUS_QCM_Customer_Voc definitionCUS_QCM_Update_CUS_QCM
                + MP_STEP_UPDATE : Update CUS_QCM_Customer_Voc definition
                + MP_STEP_DELETE : Delete CUS_QCM_Customer_Voc definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2024-12-11             Create by Generator

    Copyright(C) 1998-2024 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_QCM_common.h"

int CUS_QCM_Update_CUS_QCM_Other_Company_Spec_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Other_Company_Spec()
        - Create/Update/Delete CUS_QCM_Customer_Voc definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Other_Company_Spec(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC", out_node);

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
    CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC()
        - Main sub function of "CUS_QCM_Update_CUS_QCM_Other_Company_Spec" function
        - Create/Update/Delete CUS_QCM_Customer_Claim definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCUSSPE_TAG CQCMCUSSPE;
    struct CQCMCUSSPE_TAG CQCMCUSSPE_o;
    struct CQCMISPLOS_TAG CQCMISPLOS;

    char   s_sys_time[14];
    char s_file_no[10];
    TRSNode* gen_in_node;
    TRSNode* cmn_out;

    TRSNode** loss_list;
    int i_loss_count;

    LOG_head("CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Other_Company_Spec",
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

    if(CUS_QCM_Update_CUS_QCM_Other_Company_Spec_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cqcmcusspe(&CQCMCUSSPE);
    TRS.copy(CQCMCUSSPE.FACTORY, sizeof(CQCMCUSSPE.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMCUSSPE.REPORT_NO, sizeof(CQCMCUSSPE.REPORT_NO), in_node, "REPORT_NO");
    TRS.copy(CQCMCUSSPE.REPORT_TYPE, sizeof(CQCMCUSSPE.REPORT_TYPE), in_node, "REPORT_TYPE");
    TRS.copy(CQCMCUSSPE.CUST_NO, sizeof(CQCMCUSSPE.CUST_NO), in_node, "CUST_NO");
    TRS.copy(CQCMCUSSPE.CUST_NAME, sizeof(CQCMCUSSPE.CUST_NAME), in_node, "CUST_NAME");
    TRS.copy(CQCMCUSSPE.SAL_GROUP, sizeof(CQCMCUSSPE.SAL_GROUP), in_node, "SAL_GROUP");
    TRS.copy(CQCMCUSSPE.CREATE_DATE, sizeof(CQCMCUSSPE.CREATE_DATE), in_node, "CREATE_DATE");
    TRS.copy(CQCMCUSSPE.GRADE, sizeof(CQCMCUSSPE.GRADE), in_node, "GRADE");

    TRS.copy(CQCMCUSSPE.DATA_01, sizeof(CQCMCUSSPE.DATA_01), in_node, "DATA_01");
    TRS.copy(CQCMCUSSPE.DATA_02, sizeof(CQCMCUSSPE.DATA_02), in_node, "DATA_02");
    TRS.copy(CQCMCUSSPE.DATA_03, sizeof(CQCMCUSSPE.DATA_03), in_node, "DATA_03");
    TRS.copy(CQCMCUSSPE.DATA_04, sizeof(CQCMCUSSPE.DATA_04), in_node, "DATA_04");
    TRS.copy(CQCMCUSSPE.DATA_05, sizeof(CQCMCUSSPE.DATA_05), in_node, "DATA_05");
    TRS.copy(CQCMCUSSPE.DATA_06, sizeof(CQCMCUSSPE.DATA_06), in_node, "DATA_06");
    TRS.copy(CQCMCUSSPE.DATA_07, sizeof(CQCMCUSSPE.DATA_07), in_node, "DATA_07");
    TRS.copy(CQCMCUSSPE.DATA_08, sizeof(CQCMCUSSPE.DATA_08), in_node, "DATA_08");
    TRS.copy(CQCMCUSSPE.DATA_09, sizeof(CQCMCUSSPE.DATA_09), in_node, "DATA_09");
    TRS.copy(CQCMCUSSPE.DATA_10, sizeof(CQCMCUSSPE.DATA_10), in_node, "DATA_10");

    TRS.copy(CQCMCUSSPE.DATA_11, sizeof(CQCMCUSSPE.DATA_11), in_node, "DATA_11");
    TRS.copy(CQCMCUSSPE.DATA_12, sizeof(CQCMCUSSPE.DATA_12), in_node, "DATA_12");
    TRS.copy(CQCMCUSSPE.DATA_13, sizeof(CQCMCUSSPE.DATA_13), in_node, "DATA_13");
    TRS.copy(CQCMCUSSPE.DATA_14, sizeof(CQCMCUSSPE.DATA_14), in_node, "DATA_14");
    TRS.copy(CQCMCUSSPE.DATA_15, sizeof(CQCMCUSSPE.DATA_15), in_node, "DATA_15");
    TRS.copy(CQCMCUSSPE.DATA_16, sizeof(CQCMCUSSPE.DATA_16), in_node, "DATA_16");
    TRS.copy(CQCMCUSSPE.DATA_17, sizeof(CQCMCUSSPE.DATA_17), in_node, "DATA_17");
    TRS.copy(CQCMCUSSPE.DATA_18, sizeof(CQCMCUSSPE.DATA_18), in_node, "DATA_18");
    TRS.copy(CQCMCUSSPE.DATA_19, sizeof(CQCMCUSSPE.DATA_19), in_node, "DATA_19");
    TRS.copy(CQCMCUSSPE.DATA_20, sizeof(CQCMCUSSPE.DATA_20), in_node, "DATA_20");

    TRS.copy(CQCMCUSSPE.DATA_21, sizeof(CQCMCUSSPE.DATA_21), in_node, "DATA_21");
    TRS.copy(CQCMCUSSPE.DATA_22, sizeof(CQCMCUSSPE.DATA_22), in_node, "DATA_22");
    TRS.copy(CQCMCUSSPE.DATA_23, sizeof(CQCMCUSSPE.DATA_23), in_node, "DATA_23");
    TRS.copy(CQCMCUSSPE.DATA_24, sizeof(CQCMCUSSPE.DATA_24), in_node, "DATA_24");
    TRS.copy(CQCMCUSSPE.DATA_25, sizeof(CQCMCUSSPE.DATA_25), in_node, "DATA_25");
    TRS.copy(CQCMCUSSPE.DATA_26, sizeof(CQCMCUSSPE.DATA_26), in_node, "DATA_26");
    TRS.copy(CQCMCUSSPE.DATA_27, sizeof(CQCMCUSSPE.DATA_27), in_node, "DATA_27");
    TRS.copy(CQCMCUSSPE.DATA_28, sizeof(CQCMCUSSPE.DATA_28), in_node, "DATA_28");
    TRS.copy(CQCMCUSSPE.DATA_29, sizeof(CQCMCUSSPE.DATA_29), in_node, "DATA_29");
    TRS.copy(CQCMCUSSPE.DATA_30, sizeof(CQCMCUSSPE.DATA_30), in_node, "DATA_30");
    TRS.copy(CQCMCUSSPE.FILE_NO_01, sizeof(CQCMCUSSPE.FILE_NO_01), in_node, "FILE_NO_01");
    TRS.copy(CQCMCUSSPE.FILE_PATH_01, sizeof(CQCMCUSSPE.FILE_PATH_01), in_node, "FILE_PATH_01");
    TRS.copy(CQCMCUSSPE.FILE_NO_02, sizeof(CQCMCUSSPE.FILE_NO_02), in_node, "FILE_NO_02");
    TRS.copy(CQCMCUSSPE.FILE_PATH_02, sizeof(CQCMCUSSPE.FILE_PATH_02), in_node, "FILE_PATH_02");
    TRS.copy(CQCMCUSSPE.FILE_NO_03, sizeof(CQCMCUSSPE.FILE_NO_03), in_node, "FILE_NO_03");
    TRS.copy(CQCMCUSSPE.FILE_PATH_03, sizeof(CQCMCUSSPE.FILE_PATH_03), in_node, "FILE_PATH_03");
    TRS.copy(CQCMCUSSPE.FILE_NO_04, sizeof(CQCMCUSSPE.FILE_NO_04), in_node, "FILE_NO_04");
    TRS.copy(CQCMCUSSPE.FILE_PATH_04, sizeof(CQCMCUSSPE.FILE_PATH_04), in_node, "FILE_PATH_04");
    TRS.copy(CQCMCUSSPE.FILE_NO_05, sizeof(CQCMCUSSPE.FILE_NO_05), in_node, "FILE_NO_05");
    TRS.copy(CQCMCUSSPE.FILE_PATH_05, sizeof(CQCMCUSSPE.FILE_PATH_05), in_node, "FILE_PATH_05");
    TRS.copy(CQCMCUSSPE.COMMENT_01, sizeof(CQCMCUSSPE.COMMENT_01), in_node, "COMMENT_01");
    TRS.copy(CQCMCUSSPE.COMMENT_02, sizeof(CQCMCUSSPE.COMMENT_02), in_node, "COMMENT_02");
    TRS.copy(CQCMCUSSPE.COMMENT_03, sizeof(CQCMCUSSPE.COMMENT_03), in_node, "COMMENT_03");
    TRS.copy(CQCMCUSSPE.COMMENT_04, sizeof(CQCMCUSSPE.COMMENT_04), in_node, "COMMENT_04");
    TRS.copy(CQCMCUSSPE.COMMENT_05, sizeof(CQCMCUSSPE.COMMENT_05), in_node, "COMMENT_05");
    TRS.copy(CQCMCUSSPE.COMMENT_06, sizeof(CQCMCUSSPE.COMMENT_06), in_node, "COMMENT_06");
    TRS.copy(CQCMCUSSPE.COMMENT_07, sizeof(CQCMCUSSPE.COMMENT_07), in_node, "COMMENT_07");
    TRS.copy(CQCMCUSSPE.COMMENT_08, sizeof(CQCMCUSSPE.COMMENT_08), in_node, "COMMENT_08");
    TRS.copy(CQCMCUSSPE.COMMENT_09, sizeof(CQCMCUSSPE.COMMENT_09), in_node, "COMMENT_09");
    TRS.copy(CQCMCUSSPE.COMMENT_10, sizeof(CQCMCUSSPE.COMMENT_10), in_node, "COMMENT_10");
    TRS.copy(CQCMCUSSPE.CMF_01, sizeof(CQCMCUSSPE.CMF_01), in_node, "CMF_01");
    TRS.copy(CQCMCUSSPE.CMF_02, sizeof(CQCMCUSSPE.CMF_02), in_node, "CMF_02");
    TRS.copy(CQCMCUSSPE.CMF_03, sizeof(CQCMCUSSPE.CMF_03), in_node, "CMF_03");
    TRS.copy(CQCMCUSSPE.CMF_04, sizeof(CQCMCUSSPE.CMF_04), in_node, "CMF_04");
    TRS.copy(CQCMCUSSPE.CMF_05, sizeof(CQCMCUSSPE.CMF_05), in_node, "CMF_05");
    TRS.copy(CQCMCUSSPE.CMF_06, sizeof(CQCMCUSSPE.CMF_06), in_node, "CMF_06");
    TRS.copy(CQCMCUSSPE.CMF_07, sizeof(CQCMCUSSPE.CMF_07), in_node, "CMF_07");
    TRS.copy(CQCMCUSSPE.CMF_08, sizeof(CQCMCUSSPE.CMF_08), in_node, "CMF_08");
    TRS.copy(CQCMCUSSPE.CMF_09, sizeof(CQCMCUSSPE.CMF_09), in_node, "CMF_09");
    TRS.copy(CQCMCUSSPE.CMF_10, sizeof(CQCMCUSSPE.CMF_10), in_node, "CMF_10");
    CQCMCUSSPE.USE_YN = TRS.get_char(in_node, "USE_YN");
    TRS.copy(CQCMCUSSPE.CREATE_USER_ID, sizeof(CQCMCUSSPE.CREATE_USER_ID), in_node, "CREATE_USER_ID");
    TRS.copy(CQCMCUSSPE.CREATE_TIME, sizeof(CQCMCUSSPE.CREATE_TIME), in_node, "CREATE_TIME");
    TRS.copy(CQCMCUSSPE.UPDATE_USER_ID, sizeof(CQCMCUSSPE.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
    TRS.copy(CQCMCUSSPE.UPDATE_TIME, sizeof(CQCMCUSSPE.UPDATE_TIME), in_node, "UPDATE_TIME");

//step 1 : 저장
//step 2 : 수정
//step 3 : 삭제

    if (TRS.get_procstep(in_node) == '1')
    {

        //----[Addtional Logic for Create Case]----



        memset(s_file_no, ' ', sizeof(s_file_no));


        gen_in_node = TRS.add_node(in_node, "gen_in_node");

        //ID 발번            
        CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
        TRS.add_string(gen_in_node, "RULE_ID", "CUSTOMER_VOC", strlen("CUSTOMER_VOC"));
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


        memcpy(CQCMCUSSPE.REPORT_NO, s_file_no, sizeof(s_file_no));
        TRS.copy(CQCMCUSSPE.CREATE_USER_ID, sizeof(CQCMCUSSPE.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMCUSSPE.CREATE_TIME, s_sys_time, sizeof(CQCMCUSSPE.CREATE_TIME));
        DBU_insert_cqcmcusspe(&CQCMCUSSPE);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCUSSPE INSERT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE.FACTORY), CQCMCUSSPE.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE.REPORT_NO), CQCMCUSSPE.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }





        TRS.add_string(out_node, "REPORT_NO", s_file_no, sizeof(s_file_no));








    }
    else if (TRS.get_procstep(in_node) == '2')
    {
        DBU_init_cqcmcusspe(&CQCMCUSSPE_o);
        TRS.copy(CQCMCUSSPE_o.FACTORY, sizeof(CQCMCUSSPE_o.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CQCMCUSSPE_o.REPORT_NO, sizeof(CQCMCUSSPE_o.REPORT_NO), in_node, "REPORT_NO");
        DBU_select_cqcmcusspe_for_update(1, &CQCMCUSSPE_o);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCUSSPE SELECT FOR UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE_o.FACTORY), CQCMCUSSPE_o.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE_o.REPORT_NO), CQCMCUSSPE_o.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //----[Addtional Logic for Update Case]----

        memcpy(CQCMCUSSPE.CREATE_USER_ID, CQCMCUSSPE_o.CREATE_USER_ID, sizeof(CQCMCUSSPE.CREATE_USER_ID));
        memcpy(CQCMCUSSPE.CREATE_TIME, CQCMCUSSPE_o.CREATE_TIME, sizeof(CQCMCUSSPE.CREATE_TIME));
        TRS.copy(CQCMCUSSPE.UPDATE_USER_ID, sizeof(CQCMCUSSPE.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMCUSSPE.UPDATE_TIME, s_sys_time, sizeof(CQCMCUSSPE.UPDATE_TIME));

        DBU_update_cqcmcusspe(1, &CQCMCUSSPE);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCUSSPE UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE.FACTORY), CQCMCUSSPE.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE.REPORT_NO), CQCMCUSSPE.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }





    }
    else if (TRS.get_procstep(in_node) == '3')
    {
        DBU_delete_cqcmcusspe(1, &CQCMCUSSPE);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCUSSPE DELETE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE.FACTORY), CQCMCUSSPE.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE.REPORT_NO), CQCMCUSSPE.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Other_Company_Spec",
                             MP_UPOINT_AFTER,
                             in_node,
                             out_node) == MP_FALSE) return MP_FALSE;
    */

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
} 

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Other_Company_Spec_Validation()
        - Main sub function of "CUS_QCM_UPDATE_CUS_QCM_OTHER_COMPANY_SPEC" function
        - Check the condition for create/update/delete CUS_QCM_Customer_Claim
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Other_Company_Spec_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCUSSPE_TAG CQCMCUSSPE;
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



    DBU_init_cqcmcusspe(&CQCMCUSSPE);
    TRS.copy(CQCMCUSSPE.FACTORY, sizeof(CQCMCUSSPE.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMCUSSPE.REPORT_NO, sizeof(CQCMCUSSPE.REPORT_NO), in_node, "REPORT_NO");
    DBU_select_cqcmcusspe(1, &CQCMCUSSPE);
    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        if(DB_error_code == DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-XXXX");
            TRS.add_fieldmsg(out_node, "CQCMCUSSPE SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE.FACTORY), CQCMCUSSPE.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE.REPORT_NO), CQCMCUSSPE.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    else if (TRS.get_procstep(in_node) == '2' || TRS.get_procstep(in_node) == '3')
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

            TRS.add_fieldmsg(out_node, "CQCMCUSSPE SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCUSSPE.FACTORY), CQCMCUSSPE.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCUSSPE.REPORT_NO), CQCMCUSSPE.REPORT_NO);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_SETUP;
            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

