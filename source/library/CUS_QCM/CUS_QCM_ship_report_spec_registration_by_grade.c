/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_ship_report_spec_registration_by_grade.c
Description : 출하검사 성적서 스펙 등록(GRADE)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/16  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_QCM_common.h"

int CUS_QCM_Ship_Report_Spec_Registration_By_Grade_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_QCM_Ship_Report_Spec_Registration_By_Grade()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Ship_Report_Spec_Registration_By_Grade(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_GRADE(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Ship_Report_Spec_Registration_By_Grade", out_node);
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
CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_GRADE()
- Main sub function of "CUS_QCM_Ship_Report_Spec_Registration_By_Grade" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CQCMCSTSPG_TAG CQCMCSTSPG;
    struct MGCMLAGDAT_TAG MGCMLAGDAT;

    TRSNode **data_list;

    int i_data_count = 0;
    int i = 0;
    char c_flag = ' ';

    LOG_head("CUS_QCM_Ship_Report_Spec_Registration_By_Grade");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    /* Validation Check */
    if (CUS_QCM_Ship_Report_Spec_Registration_By_Grade_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
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
        DBU_init_cqcmcstspg(&CQCMCSTSPG);
        TRS.copy(CQCMCSTSPG.FACTORY, sizeof(CQCMCSTSPG.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CQCMCSTSPG.DELIVERY_ID, sizeof(CQCMCSTSPG.DELIVERY_ID), data_list[i], "DELIVERY_ID");
        TRS.copy(CQCMCSTSPG.GRADE, sizeof(CQCMCSTSPG.GRADE), data_list[i], "GRADE");
        TRS.copy(CQCMCSTSPG.INSP_TYPE, sizeof(CQCMCSTSPG.INSP_TYPE), data_list[i], "INSP_TYPE");       
        TRS.copy(CQCMCSTSPG.CHAR_ID, sizeof(CQCMCSTSPG.CHAR_ID), data_list[i], "CHAR_ID");

        if (TRS.get_procstep(in_node) == '1')
        {
            DBU_select_cqcmcstspg(1, &CQCMCSTSPG);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    c_flag = 'I';
                }
                else
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPG SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPG.FACTORY), CQCMCSTSPG.FACTORY);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPG.DELIVERY_ID), CQCMCSTSPG.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "GRADE", MP_STR, sizeof(CQCMCSTSPG.GRADE), CQCMCSTSPG.GRADE);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPG.INSP_TYPE), CQCMCSTSPG.INSP_TYPE);                  
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPG.CHAR_ID), CQCMCSTSPG.CHAR_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            TRS.copy(CQCMCSTSPG.TARGET_VALUE, sizeof(CQCMCSTSPG.TARGET_VALUE), data_list[i], "TARGET_VALUE");
            TRS.copy(CQCMCSTSPG.LOW_SPEC_LIMIT, sizeof(CQCMCSTSPG.LOW_SPEC_LIMIT), data_list[i], "LOW_SPEC_LIMIT");
            TRS.copy(CQCMCSTSPG.UPPER_SPEC_LIMIT, sizeof(CQCMCSTSPG.UPPER_SPEC_LIMIT), data_list[i], "UPPER_SPEC_LIMIT");
            TRS.copy(CQCMCSTSPG.CMF_1, sizeof(CQCMCSTSPG.CMF_1), data_list[i], "CMF_1");

            if (CQCMCSTSPG.LOW_SPEC_LIMIT[0] != ' '&& CQCMCSTSPG.UPPER_SPEC_LIMIT[0] != ' ')
            {
                CQCMCSTSPG.SPEC_TYPE = MP_SPEC_TYPE_B;
            }
            else if (CQCMCSTSPG.LOW_SPEC_LIMIT[0] != ' ')
            {
                CQCMCSTSPG.SPEC_TYPE = MP_SPEC_TYPE_L;
            }
            else if (CQCMCSTSPG.UPPER_SPEC_LIMIT[0] != ' ')
            {
                CQCMCSTSPG.SPEC_TYPE = MP_SPEC_TYPE_U;
            }

            if (c_flag == 'I')
            {
                //납품처 조회
                DBC_init_mgcmlagdat(&MGCMLAGDAT);
                TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_DELIVERY, strlen(MP_GCM_DELIVERY));
                memcpy(MGCMLAGDAT.KEY_1, CQCMCSTSPG.DELIVERY_ID, sizeof(CQCMCSTSPG.DELIVERY_ID));
                DBC_select_mgcmlagdat(1, &MGCMLAGDAT);

                memcpy(CQCMCSTSPG.DELIVERY_NAME, MGCMLAGDAT.DATA_1, sizeof(CQCMCSTSPG.DELIVERY_NAME));
                memcpy(CQCMCSTSPG.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CQCMCSTSPG.CREATE_USER_ID, sizeof(CQCMCSTSPG.CREATE_USER_ID), in_node, IN_USERID);

                DBU_insert_cqcmcstspg(&CQCMCSTSPG);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPG INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPG.FACTORY), CQCMCSTSPG.FACTORY);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPG.DELIVERY_ID), CQCMCSTSPG.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "GRADE", MP_STR, sizeof(CQCMCSTSPG.GRADE), CQCMCSTSPG.GRADE);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPG.INSP_TYPE), CQCMCSTSPG.INSP_TYPE);
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPG.CHAR_ID), CQCMCSTSPG.CHAR_ID);
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
                memcpy(CQCMCSTSPG.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CQCMCSTSPG.UPDATE_USER_ID, sizeof(CQCMCSTSPG.UPDATE_USER_ID), in_node, IN_USERID);

                DBU_update_cqcmcstspg(1, &CQCMCSTSPG);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "QCM-0004");
                    TRS.add_fieldmsg(out_node, "CQCMCSTSPG UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPG.FACTORY), CQCMCSTSPG.FACTORY);
                    TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPG.DELIVERY_ID), CQCMCSTSPG.DELIVERY_ID);
                    TRS.add_fieldmsg(out_node, "GRADE", MP_STR, sizeof(CQCMCSTSPG.GRADE), CQCMCSTSPG.GRADE);
                    TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPG.INSP_TYPE), CQCMCSTSPG.INSP_TYPE);
                    TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPG.CHAR_ID), CQCMCSTSPG.CHAR_ID);
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
            DBU_delete_cqcmcstspg(1, &CQCMCSTSPG);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "QCM-0004");
                TRS.add_fieldmsg(out_node, "CQCMCSTSPM DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMCSTSPG.FACTORY), CQCMCSTSPG.FACTORY);
                TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(CQCMCSTSPG.DELIVERY_ID), CQCMCSTSPG.DELIVERY_ID);
                TRS.add_fieldmsg(out_node, "GRADE", MP_STR, sizeof(CQCMCSTSPG.GRADE), CQCMCSTSPG.GRADE);
                TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMCSTSPG.INSP_TYPE), CQCMCSTSPG.INSP_TYPE);
                TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(CQCMCSTSPG.CHAR_ID), CQCMCSTSPG.CHAR_ID);
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
CUS_QCM_Ship_Report_Spec_Registration_By_Grade_Validation()
- Validation Check sub function of "CUS_QCM_SHIP_REPORT_SPEC_REGISTRATION_BY_GRADE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Ship_Report_Spec_Registration_By_Grade_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
