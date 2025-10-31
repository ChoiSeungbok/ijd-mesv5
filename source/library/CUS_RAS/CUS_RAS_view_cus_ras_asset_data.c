/******************************************************************************'

    System      : MESplus
    Module      : CUS_RAS
    File Name   : CUS_RAS_view_cus_ras_asset_data.c
    Description : CUS_RAS_View_Cus_ras_asset_data service

    MES Version : 5.3.4 ~

    Function List
        - CUS_RAS_View_Cus_ras_asset_data()
            + View service interface function
        - CUS_RAS_VIEW_CUS_RAS_ASSET_DATA()
            + Main sub function of CUS_RAS_View_Cus_ras_asset_data function
            + View service main business function
    Detail Description
        - CUS_RAS_VIEW_CUS_RAS_ASSET_DATA()
            + h_proc_step
                + 1 : View data by Primary Key
    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2021-09-16             Create by Generator

    Copyright(C) 1998-2021 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_RAS_common.h"

/*******************************************************************************
    CUS_RAS_View_Cus_ras_asset_data()
        - View service interface function
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_View_Cus_ras_asset_data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_VIEW_CUS_RAS_ASSET_DATA(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_VIEW_CUS_RAS_ASSET_DATA", out_node);

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
    CUS_RAS_VIEW_CUS_RAS_ASSET_DATA()
        - Main sub function of "CUS_RAS_View_Cus_ras_asset_data" function
        - View service main business function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_VIEW_CUS_RAS_ASSET_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CERPASTSTS_TAG CERPASTSTS;

    LOG_head("CUS_RAS_VIEW_CUS_RAS_ASSET_DATA");
    LOG_add("h_language", MP_CHR, TRS.get_language(in_node));
    LOG_add("h_factory", MP_NSTR, TRS.get_factory(in_node));
    LOG_add("h_user_id", MP_NSTR, TRS.get_userid(in_node));
    LOG_add("h_proc_step", MP_CHR, TRS.get_procstep(in_node));
    LOG_add("book_type_code", MP_NSTR, TRS.get_string(in_node, "BOOK_TYPE_CODE"));
    LOG_add("asset_number", MP_NSTR, TRS.get_string(in_node, "ASSET_NUMBER"));
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Not use in customizing
    if(COM_proc_user_routine("CUS_RAS", "CUS_RAS_View_Cus_ras_asset_data",
                             MP_UPOINT_BEFORE,
                             in_node,
                             out_node) == MP_FALSE)     return MP_FALSE;
    if(TRS.get_boolean(in_node, "__BYPASS") == MP_TRUE) return MP_TRUE;
    */

    /* ProcStep Validation */
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }

    /* FACTORY Validation */
    if(COM_isnullspace(TRS.get_factory(in_node)) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_RAS-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    /* BOOK_TYPE_CODE Validation */
    if(COM_isnullspace(TRS.get_string(in_node, "BOOK_TYPE_CODE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_RAS-0001");
        TRS.add_fieldmsg(out_node, "BOOK_TYPE_CODE", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    /* ASSET_NUMBER Validation */
    if(COM_isnullspace(TRS.get_string(in_node, "ASSET_NUMBER")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CUS_RAS-0001");
        TRS.add_fieldmsg(out_node, "ASSET_NUMBER", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cerpaststs(&CERPASTSTS);
    TRS.copy(CERPASTSTS.FACTORY, sizeof(CERPASTSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CERPASTSTS.BOOK_TYPE_CODE, sizeof(CERPASTSTS.BOOK_TYPE_CODE), in_node, "BOOK_TYPE_CODE");
    TRS.copy(CERPASTSTS.ASSET_NUMBER, sizeof(CERPASTSTS.ASSET_NUMBER), in_node, "ASSET_NUMBER");
    DBU_select_cerpaststs(1, &CERPASTSTS);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CUS_RAS-9999");
        TRS.add_fieldmsg(out_node, "CERPASTSTS SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CERPASTSTS.FACTORY), CERPASTSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "BOOK_TYPE_CODE", MP_STR, sizeof(CERPASTSTS.BOOK_TYPE_CODE), CERPASTSTS.BOOK_TYPE_CODE);
        TRS.add_fieldmsg(out_node, "ASSET_NUMBER", MP_STR, sizeof(CERPASTSTS.ASSET_NUMBER), CERPASTSTS.ASSET_NUMBER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    TRS.add_string(out_node, "FACTORY", CERPASTSTS.FACTORY, sizeof(CERPASTSTS.FACTORY));
    TRS.add_string(out_node, "BOOK_TYPE_CODE", CERPASTSTS.BOOK_TYPE_CODE, sizeof(CERPASTSTS.BOOK_TYPE_CODE));
    TRS.add_string(out_node, "ASSET_NUMBER", CERPASTSTS.ASSET_NUMBER, sizeof(CERPASTSTS.ASSET_NUMBER));
    TRS.add_string(out_node, "ASSET_NAME", CERPASTSTS.ASSET_NAME, sizeof(CERPASTSTS.ASSET_NAME));
    TRS.add_string(out_node, "ATTRIBUTE_CATEGORY_CODE", CERPASTSTS.ATTRIBUTE_CATEGORY_CODE, sizeof(CERPASTSTS.ATTRIBUTE_CATEGORY_CODE));
    TRS.add_string(out_node, "CATEGORY_CODE", CERPASTSTS.CATEGORY_CODE, sizeof(CERPASTSTS.CATEGORY_CODE));
    TRS.add_string(out_node, "CURRENT_UNITS", CERPASTSTS.CURRENT_UNITS, sizeof(CERPASTSTS.CURRENT_UNITS));
    TRS.add_string(out_node, "ORIGINAL_COST", CERPASTSTS.ORIGINAL_COST, sizeof(CERPASTSTS.ORIGINAL_COST));
    TRS.add_string(out_node, "DATE_PLACED_IN_SERVICE", CERPASTSTS.DATE_PLACED_IN_SERVICE, sizeof(CERPASTSTS.DATE_PLACED_IN_SERVICE));
    TRS.add_string(out_node, "OPERATING_UNIT_SEG", CERPASTSTS.OPERATING_UNIT_SEG, sizeof(CERPASTSTS.OPERATING_UNIT_SEG));
    TRS.add_string(out_node, "OPERATING_UNIT", CERPASTSTS.OPERATING_UNIT, sizeof(CERPASTSTS.OPERATING_UNIT));
    TRS.add_string(out_node, "DEPARTMENT_SEG", CERPASTSTS.DEPARTMENT_SEG, sizeof(CERPASTSTS.DEPARTMENT_SEG));
    TRS.add_string(out_node, "DEPARTMENTS", CERPASTSTS.DEPARTMENTS, sizeof(CERPASTSTS.DEPARTMENTS));
    TRS.add_string(out_node, "PRODUCT_FAMILY_SEG", CERPASTSTS.PRODUCT_FAMILY_SEG, sizeof(CERPASTSTS.PRODUCT_FAMILY_SEG));
    TRS.add_string(out_node, "PRODUCT_FAMILY", CERPASTSTS.PRODUCT_FAMILY, sizeof(CERPASTSTS.PRODUCT_FAMILY));
    TRS.add_string(out_node, "BUSINESS_UNIT", CERPASTSTS.BUSINESS_UNIT, sizeof(CERPASTSTS.BUSINESS_UNIT));
    TRS.add_string(out_node, "TAG_NUMBER", CERPASTSTS.TAG_NUMBER, sizeof(CERPASTSTS.TAG_NUMBER));
    TRS.add_string(out_node, "SERIAL_NUMBER", CERPASTSTS.SERIAL_NUMBER, sizeof(CERPASTSTS.SERIAL_NUMBER));
    TRS.add_string(out_node, "MANUFACTURER_NAME", CERPASTSTS.MANUFACTURER_NAME, sizeof(CERPASTSTS.MANUFACTURER_NAME));
    TRS.add_string(out_node, "MODEL_NUMBER", CERPASTSTS.MODEL_NUMBER, sizeof(CERPASTSTS.MODEL_NUMBER));
    TRS.add_string(out_node, "EMPLOYEE_NUMBER", CERPASTSTS.EMPLOYEE_NUMBER, sizeof(CERPASTSTS.EMPLOYEE_NUMBER));
    TRS.add_string(out_node, "EMPLOYEE_NAME", CERPASTSTS.EMPLOYEE_NAME, sizeof(CERPASTSTS.EMPLOYEE_NAME));
    TRS.add_string(out_node, "IN_USE_FLAG", CERPASTSTS.IN_USE_FLAG, sizeof(CERPASTSTS.IN_USE_FLAG));
    TRS.add_string(out_node, "PRORATE_DATE", CERPASTSTS.PRORATE_DATE, sizeof(CERPASTSTS.PRORATE_DATE));
    TRS.add_string(out_node, "LOCATION_ID", CERPASTSTS.LOCATION_ID, sizeof(CERPASTSTS.LOCATION_ID));
    TRS.add_string(out_node, "LOCATION_DESCRIPTION", CERPASTSTS.LOCATION_DESCRIPTION, sizeof(CERPASTSTS.LOCATION_DESCRIPTION));
    TRS.add_string(out_node, "DEPRN_METHOD_CODE", CERPASTSTS.DEPRN_METHOD_CODE, sizeof(CERPASTSTS.DEPRN_METHOD_CODE));
    TRS.add_string(out_node, "PLC", CERPASTSTS.PLC, sizeof(CERPASTSTS.PLC));
    TRS.add_string(out_node, "PURCHASING_DATE", CERPASTSTS.PURCHASING_DATE, sizeof(CERPASTSTS.PURCHASING_DATE));
    TRS.add_string(out_node, "CONFIRMATION_DATE", CERPASTSTS.CONFIRMATION_DATE, sizeof(CERPASTSTS.CONFIRMATION_DATE));
    TRS.add_string(out_node, "CONFIRMED_PLC", CERPASTSTS.CONFIRMED_PLC, sizeof(CERPASTSTS.CONFIRMED_PLC));
    TRS.add_string(out_node, "RES_ID", CERPASTSTS.RES_ID, sizeof(CERPASTSTS.RES_ID));
    TRS.add_string(out_node, "CMF_1", CERPASTSTS.CMF_1, sizeof(CERPASTSTS.CMF_1));
    TRS.add_string(out_node, "CMF_2", CERPASTSTS.CMF_2, sizeof(CERPASTSTS.CMF_2));
    TRS.add_string(out_node, "CMF_3", CERPASTSTS.CMF_3, sizeof(CERPASTSTS.CMF_3));
    TRS.add_string(out_node, "CMF_4", CERPASTSTS.CMF_4, sizeof(CERPASTSTS.CMF_4));
    TRS.add_string(out_node, "CMF_5", CERPASTSTS.CMF_5, sizeof(CERPASTSTS.CMF_5));
    TRS.add_string(out_node, "CMF_6", CERPASTSTS.CMF_6, sizeof(CERPASTSTS.CMF_6));
    TRS.add_string(out_node, "CMF_7", CERPASTSTS.CMF_7, sizeof(CERPASTSTS.CMF_7));
    TRS.add_string(out_node, "CMF_8", CERPASTSTS.CMF_8, sizeof(CERPASTSTS.CMF_8));
    TRS.add_string(out_node, "CMF_9", CERPASTSTS.CMF_9, sizeof(CERPASTSTS.CMF_9));
    TRS.add_string(out_node, "CMF_10", CERPASTSTS.CMF_10, sizeof(CERPASTSTS.CMF_10));
    TRS.add_string(out_node, "CMF_11", CERPASTSTS.CMF_11, sizeof(CERPASTSTS.CMF_11));
    TRS.add_string(out_node, "CMF_12", CERPASTSTS.CMF_12, sizeof(CERPASTSTS.CMF_12));
    TRS.add_string(out_node, "CMF_13", CERPASTSTS.CMF_13, sizeof(CERPASTSTS.CMF_13));
    TRS.add_string(out_node, "CMF_14", CERPASTSTS.CMF_14, sizeof(CERPASTSTS.CMF_14));
    TRS.add_string(out_node, "CMF_15", CERPASTSTS.CMF_15, sizeof(CERPASTSTS.CMF_15));
    TRS.add_string(out_node, "CREATE_USER_ID", CERPASTSTS.CREATE_USER_ID, sizeof(CERPASTSTS.CREATE_USER_ID));
    TRS.add_string(out_node, "CREATE_TIME", CERPASTSTS.CREATE_TIME, sizeof(CERPASTSTS.CREATE_TIME));
    TRS.add_string(out_node, "UPDATE_USER_ID", CERPASTSTS.UPDATE_USER_ID, sizeof(CERPASTSTS.UPDATE_USER_ID));
    TRS.add_string(out_node, "UPDATE_TIME", CERPASTSTS.UPDATE_TIME, sizeof(CERPASTSTS.UPDATE_TIME));


    /* Not use in customizing
    if(COM_proc_user_routine("CUS_RAS", "CUS_RAS_View_Cus_ras_asset_data",
                             MP_UPOINT_AFTER,
                             in_node,
                             out_node) == MP_FALSE) return MP_FALSE;
    */

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}

