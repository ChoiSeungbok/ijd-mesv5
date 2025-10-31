/******************************************************************************'

    System      : MESplus
    Module      : CUS_QCM
    File Name   : CUS_QCM_update_cus_qcm_customer_claim.c
    Description : CUS_QCM_Customer_Claim Setup function module

    MES Version : 5.3.4 ~

    Function List
        - CUS_QCM_Update_CUS_QCM_Customer_Claim()
            + Create/Update/Delete CUS_QCM_Customer_Claim definition
        - CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM()
            + Main sub function of CUS_QCM_Update_CUS_QCM_Customer_Claim function
            + Create/Update/Delete CUS_QCM_Customer_Claim definition
        - CUS_QCM_Update_CUS_QCM_Customer_Claim_Validation()
            + Main sub function of CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM function
            + Check the condition for create/update/delete CUS_QCM_Customer_Claim
    Detail Description
        - CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM()
            + h_proc_step
                + MP_STEP_CREATE : Create CUS_QCM_Customer_Claim definition
                + MP_STEP_UPDATE : Update CUS_QCM_Customer_Claim definition
                + MP_STEP_DELETE : Delete CUS_QCM_Customer_Claim definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2024-12-11             Create by Generator

    Copyright(C) 1998-2024 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_QCM_common.h"

int CUS_QCM_Update_CUS_QCM_Customer_Claim_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Customer_Claim()
        - Create/Update/Delete CUS_QCM_Customer_Claim definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Customer_Claim(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM", out_node);

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
    CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM()
        - Main sub function of "CUS_QCM_Update_CUS_QCM_Customer_Claim" function
        - Create/Update/Delete CUS_QCM_Customer_Claim definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCPLMST_TAG CQCMCPLMST;
    struct CQCMCPLMST_TAG CQCMCPLMST_o;
    struct CQCMISPLOS_TAG CQCMISPLOS;

    char   s_sys_time[14];
    char s_file_no[10];
    TRSNode* gen_in_node;
    TRSNode* cmn_out;

    TRSNode** loss_list;
    int i_loss_count;

    LOG_head("CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Claim",
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

    if(CUS_QCM_Update_CUS_QCM_Customer_Claim_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cqcmcplmst(&CQCMCPLMST);
    TRS.copy(CQCMCPLMST.FACTORY, sizeof(CQCMCPLMST.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO), in_node, "REPORT_NO");
    TRS.copy(CQCMCPLMST.CUST_NO, sizeof(CQCMCPLMST.CUST_NO), in_node, "CUST_NO");
    TRS.copy(CQCMCPLMST.CUST_NAME, sizeof(CQCMCPLMST.CUST_NAME), in_node, "CUST_NAME");
    TRS.copy(CQCMCPLMST.EVENT_DATE, sizeof(CQCMCPLMST.EVENT_DATE), in_node, "EVENT_DATE");
    TRS.copy(CQCMCPLMST.RECEIVED_DATE_1, sizeof(CQCMCPLMST.RECEIVED_DATE_1), in_node, "RECEIVED_DATE_1");
    TRS.copy(CQCMCPLMST.RECEIVED_DATE_2, sizeof(CQCMCPLMST.RECEIVED_DATE_2), in_node, "RECEIVED_DATE_2");
    TRS.copy(CQCMCPLMST.RECEIVED_DATE_3, sizeof(CQCMCPLMST.RECEIVED_DATE_3), in_node, "RECEIVED_DATE_3");
    TRS.copy(CQCMCPLMST.GRADE, sizeof(CQCMCPLMST.GRADE), in_node, "GRADE");
    TRS.copy(CQCMCPLMST.MAT_ID, sizeof(CQCMCPLMST.MAT_ID), in_node, "MAT_ID");
    TRS.copy(CQCMCPLMST.MAT_DESC, sizeof(CQCMCPLMST.MAT_DESC), in_node, "MAT_DESC");
    TRS.copy(CQCMCPLMST.CLOSURE_DATE, sizeof(CQCMCPLMST.CLOSURE_DATE), in_node, "CLOSURE_DATE");
    TRS.copy(CQCMCPLMST.SHARE_DATE, sizeof(CQCMCPLMST.SHARE_DATE), in_node, "SHARE_DATE");
    TRS.copy(CQCMCPLMST.SAL_GROUP, sizeof(CQCMCPLMST.SAL_GROUP), in_node, "SAL_GROUP");
    TRS.copy(CQCMCPLMST.SAL_USER, sizeof(CQCMCPLMST.SAL_USER), in_node, "SAL_USER");
    CQCMCPLMST.CLAIM_STATUS = TRS.get_char(in_node, "CLAIM_STATUS");
    TRS.copy(CQCMCPLMST.CLAIM_LEVEL, sizeof(CQCMCPLMST.CLAIM_LEVEL), in_node, "CLAIM_LEVEL");
    CQCMCPLMST.CLAIM_COUNT_FLAG = TRS.get_char(in_node, "CLAIM_COUNT_FLAG");
    CQCMCPLMST.CLAIM_ADJUSTED_FLAG = TRS.get_char(in_node, "CLAIM_ADJUSTED_FLAG");
    CQCMCPLMST.COST_QTY_01 = TRS.get_int(in_node, "COST_QTY_01");
    CQCMCPLMST.COST_QTY_02 = TRS.get_int(in_node, "COST_QTY_02");
    CQCMCPLMST.COST_QTY_03 = TRS.get_int(in_node, "COST_QTY_03");
    CQCMCPLMST.COST_MONTH = TRS.get_int(in_node, "COST_MONTH");
    TRS.copy(CQCMCPLMST.FILE_NO_01, sizeof(CQCMCPLMST.FILE_NO_01), in_node, "FILE_NO_01");
    TRS.copy(CQCMCPLMST.FILE_PATH_01, sizeof(CQCMCPLMST.FILE_PATH_01), in_node, "FILE_PATH_01");
    TRS.copy(CQCMCPLMST.FILE_NO_02, sizeof(CQCMCPLMST.FILE_NO_02), in_node, "FILE_NO_02");
    TRS.copy(CQCMCPLMST.FILE_PATH_02, sizeof(CQCMCPLMST.FILE_PATH_02), in_node, "FILE_PATH_02");
    TRS.copy(CQCMCPLMST.FILE_NO_03, sizeof(CQCMCPLMST.FILE_NO_03), in_node, "FILE_NO_03");
    TRS.copy(CQCMCPLMST.FILE_PATH_03, sizeof(CQCMCPLMST.FILE_PATH_03), in_node, "FILE_PATH_03");
    TRS.copy(CQCMCPLMST.FILE_NO_04, sizeof(CQCMCPLMST.FILE_NO_04), in_node, "FILE_NO_04");
    TRS.copy(CQCMCPLMST.FILE_PATH_04, sizeof(CQCMCPLMST.FILE_PATH_04), in_node, "FILE_PATH_04");
    TRS.copy(CQCMCPLMST.FILE_NO_05, sizeof(CQCMCPLMST.FILE_NO_05), in_node, "FILE_NO_05");
    TRS.copy(CQCMCPLMST.FILE_PATH_05, sizeof(CQCMCPLMST.FILE_PATH_05), in_node, "FILE_PATH_05");
    TRS.copy(CQCMCPLMST.COMMENT_01, sizeof(CQCMCPLMST.COMMENT_01), in_node, "COMMENT_01");
    TRS.copy(CQCMCPLMST.COMMENT_02, sizeof(CQCMCPLMST.COMMENT_02), in_node, "COMMENT_02");
    TRS.copy(CQCMCPLMST.COMMENT_03, sizeof(CQCMCPLMST.COMMENT_03), in_node, "COMMENT_03");
    TRS.copy(CQCMCPLMST.COMMENT_04, sizeof(CQCMCPLMST.COMMENT_04), in_node, "COMMENT_04");
    TRS.copy(CQCMCPLMST.COMMENT_05, sizeof(CQCMCPLMST.COMMENT_05), in_node, "COMMENT_05");
    TRS.copy(CQCMCPLMST.COMMENT_06, sizeof(CQCMCPLMST.COMMENT_06), in_node, "COMMENT_06");
    TRS.copy(CQCMCPLMST.COMMENT_07, sizeof(CQCMCPLMST.COMMENT_07), in_node, "COMMENT_07");
    TRS.copy(CQCMCPLMST.COMMENT_08, sizeof(CQCMCPLMST.COMMENT_08), in_node, "COMMENT_08");
    TRS.copy(CQCMCPLMST.COMMENT_09, sizeof(CQCMCPLMST.COMMENT_09), in_node, "COMMENT_09");
    TRS.copy(CQCMCPLMST.COMMENT_10, sizeof(CQCMCPLMST.COMMENT_10), in_node, "COMMENT_10");
    TRS.copy(CQCMCPLMST.CMF_01, sizeof(CQCMCPLMST.CMF_01), in_node, "CMF_01");
    TRS.copy(CQCMCPLMST.CMF_02, sizeof(CQCMCPLMST.CMF_02), in_node, "CMF_02");
    TRS.copy(CQCMCPLMST.CMF_03, sizeof(CQCMCPLMST.CMF_03), in_node, "CMF_03");
    TRS.copy(CQCMCPLMST.CMF_04, sizeof(CQCMCPLMST.CMF_04), in_node, "CMF_04");
    TRS.copy(CQCMCPLMST.CMF_05, sizeof(CQCMCPLMST.CMF_05), in_node, "CMF_05");
    TRS.copy(CQCMCPLMST.CMF_06, sizeof(CQCMCPLMST.CMF_06), in_node, "CMF_06");
    TRS.copy(CQCMCPLMST.CMF_07, sizeof(CQCMCPLMST.CMF_07), in_node, "CMF_07");
    TRS.copy(CQCMCPLMST.CMF_08, sizeof(CQCMCPLMST.CMF_08), in_node, "CMF_08");
    TRS.copy(CQCMCPLMST.CMF_09, sizeof(CQCMCPLMST.CMF_09), in_node, "CMF_09");
    TRS.copy(CQCMCPLMST.CMF_10, sizeof(CQCMCPLMST.CMF_10), in_node, "CMF_10");
    CQCMCPLMST.USE_YN = TRS.get_char(in_node, "USE_YN");
    TRS.copy(CQCMCPLMST.CREATE_USER_ID, sizeof(CQCMCPLMST.CREATE_USER_ID), in_node, "CREATE_USER_ID");
    TRS.copy(CQCMCPLMST.CREATE_TIME, sizeof(CQCMCPLMST.CREATE_TIME), in_node, "CREATE_TIME");
    TRS.copy(CQCMCPLMST.UPDATE_USER_ID, sizeof(CQCMCPLMST.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
    TRS.copy(CQCMCPLMST.UPDATE_TIME, sizeof(CQCMCPLMST.UPDATE_TIME), in_node, "UPDATE_TIME");

//step 1 : 저장
//step 2 : 수정
//step 3 : 삭제

    if(TRS.get_procstep(in_node) == '1')
    {

        //----[Addtional Logic for Create Case]----



        memset(s_file_no, ' ', sizeof(s_file_no));


        gen_in_node = TRS.add_node(in_node, "gen_in_node");

        //LOT ID 발번            
        CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
        TRS.add_string(gen_in_node, "RULE_ID", "CUSTOMER_CLAIM", strlen("CUSTOMER_CLAIM"));
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


        memcpy(CQCMCPLMST.REPORT_NO, s_file_no, sizeof(s_file_no));
        TRS.copy(CQCMCPLMST.CREATE_USER_ID, sizeof(CQCMCPLMST.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMCPLMST.CREATE_TIME, s_sys_time, sizeof(CQCMCPLMST.CREATE_TIME));
        DBU_insert_cqcmcplmst(&CQCMCPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCPLMST INSERT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST.FACTORY), CQCMCPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST.REPORT_NO), CQCMCPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        /*
        //Loss정보 삭제처리 
        DBU_init_cqcmisplos(&CQCMISPLOS);
        TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
        memcpy(CQCMISPLOS.INSP_ID, CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO));
        if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
        {
            DBU_delete_cqcmisplos(2, &CQCMISPLOS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "QCM-0004");
                TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
                TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
        */

        loss_list = TRS.get_list(in_node, "LOSS_LIST");
        i_loss_count = TRS.get_item_count(in_node, "LOSS_LIST");
        if (i_loss_count > 0)
        {
            for (int i = 0; i < i_loss_count; i++)
            {
                    // QCM Loss 정보성 테이블 저장
                    DBU_init_cqcmisplos(&CQCMISPLOS);
                    TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
                    memcpy(CQCMISPLOS.INSP_ID, CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO));         //검사 ID
                    CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
                    CQCMISPLOS.QTY_FLAG = '1';
                    TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
                    CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
                    memset(CQCMISPLOS.LOT_ID, ' ', sizeof(CQCMISPLOS.LOT_ID));
                    CQCMISPLOS.HIST_SEQ = 1;
                    memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
                 //   memcpy(CQCMISPLOS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
                  //  CQCMISPLOS.MAT_VER = MWIPLOTSTS.MAT_VER;
                    memset(CQCMISPLOS.FLOW, ' ', sizeof(CQCMISPLOS.FLOW));
                    CQCMISPLOS.FLOW_SEQ = 0;
                    TRS.copy(CQCMISPLOS.OPER, sizeof(CQCMISPLOS.OPER), loss_list[i], "LOSS_OPER");
                    memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
                    CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
                    DBU_insert_cqcmisplos(&CQCMISPLOS);
     
            }
        }



        TRS.add_string(out_node, "REPORT_NO", s_file_no, sizeof(s_file_no));








    }
    else if(TRS.get_procstep(in_node) == '2')
    {
        DBU_init_cqcmcplmst(&CQCMCPLMST_o);
        TRS.copy(CQCMCPLMST_o.FACTORY, sizeof(CQCMCPLMST_o.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CQCMCPLMST_o.REPORT_NO, sizeof(CQCMCPLMST_o.REPORT_NO), in_node, "REPORT_NO");
        DBU_select_cqcmcplmst_for_update(1, &CQCMCPLMST_o);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCPLMST SELECT FOR UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST_o.FACTORY), CQCMCPLMST_o.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST_o.REPORT_NO), CQCMCPLMST_o.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //----[Addtional Logic for Update Case]----

        memcpy(CQCMCPLMST.CREATE_USER_ID, CQCMCPLMST_o.CREATE_USER_ID, sizeof(CQCMCPLMST.CREATE_USER_ID));
        memcpy(CQCMCPLMST.CREATE_TIME, CQCMCPLMST_o.CREATE_TIME, sizeof(CQCMCPLMST.CREATE_TIME));
        TRS.copy(CQCMCPLMST.UPDATE_USER_ID, sizeof(CQCMCPLMST.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CQCMCPLMST.UPDATE_TIME, s_sys_time, sizeof(CQCMCPLMST.UPDATE_TIME));

        DBU_update_cqcmcplmst(1, &CQCMCPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCPLMST UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST.FACTORY), CQCMCPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST.REPORT_NO), CQCMCPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        

        //Loss정보 삭제처리 
        DBU_init_cqcmisplos(&CQCMISPLOS);
        TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
        memcpy(CQCMISPLOS.INSP_ID, CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO));
        if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
        {
            DBU_delete_cqcmisplos(2, &CQCMISPLOS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "QCM-0004");
                TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
                TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }


        loss_list = TRS.get_list(in_node, "LOSS_LIST");
        i_loss_count = TRS.get_item_count(in_node, "LOSS_LIST");
        if (i_loss_count > 0)
        {
            for (int i = 0; i < i_loss_count; i++)
            {
                // QCM Loss 정보성 테이블 저장
                DBU_init_cqcmisplos(&CQCMISPLOS);
                TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
                memcpy(CQCMISPLOS.INSP_ID, CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO));         //검사 ID
                CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
                CQCMISPLOS.QTY_FLAG = '1';
                TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
                CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
                memset(CQCMISPLOS.LOT_ID, ' ', sizeof(CQCMISPLOS.LOT_ID));
                CQCMISPLOS.HIST_SEQ = 1;
                memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
                //   memcpy(CQCMISPLOS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
                 //  CQCMISPLOS.MAT_VER = MWIPLOTSTS.MAT_VER;
                memset(CQCMISPLOS.FLOW, ' ', sizeof(CQCMISPLOS.FLOW));
                CQCMISPLOS.FLOW_SEQ = 0;
                TRS.copy(CQCMISPLOS.OPER, sizeof(CQCMISPLOS.OPER), loss_list[i], "LOSS_OPER");
                memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
                CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
                DBU_insert_cqcmisplos(&CQCMISPLOS);

            }
        }


    }
    else if(TRS.get_procstep(in_node) == '3')
    {
        DBU_delete_cqcmcplmst(1, &CQCMCPLMST);
        if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-0004");
            TRS.add_fieldmsg(out_node, "CQCMCPLMST DELETE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST.FACTORY), CQCMCPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST.REPORT_NO), CQCMCPLMST.REPORT_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Claim",
                             MP_UPOINT_AFTER,
                             in_node,
                             out_node) == MP_FALSE) return MP_FALSE;
    */

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
} 

/*******************************************************************************
    CUS_QCM_Update_CUS_QCM_Customer_Claim_Validation()
        - Main sub function of "CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM" function
        - Check the condition for create/update/delete CUS_QCM_Customer_Claim
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Update_CUS_QCM_Customer_Claim_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCPLMST_TAG CQCMCPLMST;
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



    DBU_init_cqcmcplmst(&CQCMCPLMST);
    TRS.copy(CQCMCPLMST.FACTORY, sizeof(CQCMCPLMST.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CQCMCPLMST.REPORT_NO, sizeof(CQCMCPLMST.REPORT_NO), in_node, "REPORT_NO");
    DBU_select_cqcmcplmst(1, &CQCMCPLMST);
    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        if(DB_error_code == DB_SUCCESS)
        {
            strcpy(s_msg_code, "CUS_QCM-XXXX");
            TRS.add_fieldmsg(out_node, "CQCMCPLMST SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST.FACTORY), CQCMCPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST.REPORT_NO), CQCMCPLMST.REPORT_NO);
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

            TRS.add_fieldmsg(out_node, "CQCMCPLMST SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCPLMST.FACTORY), CQCMCPLMST.FACTORY);
            TRS.add_fieldmsg(out_node, "REPORT_NO", MP_STR, sizeof(CQCMCPLMST.REPORT_NO), CQCMCPLMST.REPORT_NO);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_SETUP;
            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

