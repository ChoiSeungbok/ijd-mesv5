/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_ship_report_spec_registration_by_mat.c
Description : 출하검사 성적서 스펙 등록(품목)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/12  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_QCM_common.h"

int CUS_QCM_Ship_Report_Spec_Registration_By_Mat_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_MAT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_QCM_Ship_Report_Spec_Registration_By_Mat()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Ship_Report_Spec_Registration_By_Mat(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_MAT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Ship_Report_Spec_Registration_By_Mat", out_node);
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
CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_MAT()
- Main sub function of "CUS_QCM_Ship_Report_Spec_Registration_By_Mat" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_MAT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCSTSPM_TAG CQCMCSTSPM;
    struct MGCMLAGDAT_TAG MGCMLAGDAT;

    TRSNode **data_list;

    int i_data_count = 0;
    int i = 0;
    char c_flag = ' ';
    

    LOG_head("CUS_QCM_Ship_Report_Spec_Registration_By_Mat");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    /* Validation Check */
    if (CUS_QCM_Ship_Report_Spec_Registration_By_Mat_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    data_list = TRS.get_list(in_node, "DATA_LIST");
    i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

    //step 1 : 저장
    //step 2 : 삭제
    for (i = 0; i < i_data_count; i++)
    {
        DBU_init_cqcmcstspm(&CQCMCSTSPM);
        TRS.copy(CQCMCSTSPM.FACTORY, sizeof(CQCMCSTSPM.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CQCMCSTSPM.MAT_ID, sizeof(CQCMCSTSPM.MAT_ID), in_node, "MAT_ID");       
        TRS.copy(CQCMCSTSPM.INSP_TYPE, sizeof(CQCMCSTSPM.INSP_TYPE), data_list[i], "INSP_TYPE");
        TRS.copy(CQCMCSTSPM.DELIVERY_ID, sizeof(CQCMCSTSPM.DELIVERY_ID), data_list[i], "DELIVERY_ID");
        TRS.copy(CQCMCSTSPM.CHAR_ID, sizeof(CQCMCSTSPM.CHAR_ID), data_list[i], "CHAR_ID");

        if (CQCMCSTSPM.LOW_SPEC_LIMIT[0] != ' '&& CQCMCSTSPM.UPPER_SPEC_LIMIT[0] != ' ')
        {
            CQCMCSTSPM.SPEC_TYPE = MP_SPEC_TYPE_B;
        }
        else if (CQCMCSTSPM.LOW_SPEC_LIMIT[0] != ' ')
        {
            CQCMCSTSPM.SPEC_TYPE = MP_SPEC_TYPE_L;
        }
        else if (CQCMCSTSPM.UPPER_SPEC_LIMIT[0] != ' ')
        {
            CQCMCSTSPM.SPEC_TYPE = MP_SPEC_TYPE_U;
        }

        if (TRS.get_procstep(in_node) == '1')
        {
            DBU_select_cqcmcstspm(1, &CQCMCSTSPM);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    c_flag = 'I';
                }
                else
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPM SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPM.FACTORY), CQCMCSTSPM.FACTORY);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPM.INSP_TYPE), CQCMCSTSPM.INSP_TYPE);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CQCMCSTSPM.MAT_ID), CQCMCSTSPM.MAT_ID);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPM.DELIVERY_ID), CQCMCSTSPM.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPM.CHAR_ID), CQCMCSTSPM.CHAR_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
                    
            TRS.copy(CQCMCSTSPM.TARGET_VALUE, sizeof(CQCMCSTSPM.TARGET_VALUE), data_list[i], "TARGET_VALUE");
            TRS.copy(CQCMCSTSPM.LOW_SPEC_LIMIT, sizeof(CQCMCSTSPM.LOW_SPEC_LIMIT), data_list[i], "LOW_SPEC_LIMIT");
            TRS.copy(CQCMCSTSPM.UPPER_SPEC_LIMIT, sizeof(CQCMCSTSPM.UPPER_SPEC_LIMIT), data_list[i], "UPPER_SPEC_LIMIT");
            TRS.copy(CQCMCSTSPM.CMF_1, sizeof(CQCMCSTSPM.CMF_1), data_list[i], "CMF_1");

            if (c_flag == 'I')
            {
                //납품처 조회
                DBC_init_mgcmlagdat(&MGCMLAGDAT);
                TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_DELIVERY, strlen(MP_GCM_DELIVERY));
                memcpy(MGCMLAGDAT.KEY_1, CQCMCSTSPM.DELIVERY_ID,sizeof(CQCMCSTSPM.DELIVERY_ID));
                DBC_select_mgcmlagdat(1, &MGCMLAGDAT);

                CQCMCSTSPM.MAT_VER = TRS.get_int(in_node, "MAT_VER");
                memcpy(CQCMCSTSPM.DELIVERY_NAME, MGCMLAGDAT.DATA_1, sizeof(CQCMCSTSPM.DELIVERY_NAME));
                memcpy(CQCMCSTSPM.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CQCMCSTSPM.CREATE_USER_ID, sizeof(CQCMCSTSPM.CREATE_USER_ID), in_node, IN_USERID);

                DBU_insert_cqcmcstspm(&CQCMCSTSPM);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPM INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPM.FACTORY), CQCMCSTSPM.FACTORY);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPM.INSP_TYPE), CQCMCSTSPM.INSP_TYPE);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CQCMCSTSPM.MAT_ID), CQCMCSTSPM.MAT_ID);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPM.DELIVERY_ID), CQCMCSTSPM.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPM.CHAR_ID), CQCMCSTSPM.CHAR_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            //조회되면 update
            else
            {
                memcpy(CQCMCSTSPM.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CQCMCSTSPM.UPDATE_USER_ID, sizeof(CQCMCSTSPM.UPDATE_USER_ID), in_node, IN_USERID);

                DBU_update_cqcmcstspm(1, &CQCMCSTSPM);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPM UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPM.FACTORY), CQCMCSTSPM.FACTORY);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPM.INSP_TYPE), CQCMCSTSPM.INSP_TYPE);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CQCMCSTSPM.MAT_ID), CQCMCSTSPM.MAT_ID);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPM.DELIVERY_ID), CQCMCSTSPM.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPM.CHAR_ID), CQCMCSTSPM.CHAR_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }            
        }
        else if (TRS.get_procstep(in_node) == '2')
        {
            DBU_delete_cqcmcstspm(1, &CQCMCSTSPM);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "QCM-0004");
                TRS.add_fieldmsg(out_node, "CQCMCSTSPM DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPM.FACTORY), CQCMCSTSPM.FACTORY);
                TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPM.INSP_TYPE), CQCMCSTSPM.INSP_TYPE);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CQCMCSTSPM.MAT_ID), CQCMCSTSPM.MAT_ID);
                TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPM.DELIVERY_ID), CQCMCSTSPM.DELIVERY_ID);
                TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPM.CHAR_ID), CQCMCSTSPM.CHAR_ID);
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
CUS_QCM_Ship_Report_Spec_Registration_By_Mat_Validation()
- Validation Check sub function of "CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_MAT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Ship_Report_Spec_Registration_By_Mat_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
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
