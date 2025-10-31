/*******************************************************************************

System      : MESplus
Module      : CUS_BAS
File Name   : CUS_BAS_register_checksheet.c
Description : 체크시트 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/31  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAS_common.h"

int CUS_BAS_Register_Checksheet_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_REGISTER_CHECKSHEET(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAS_Register_Checksheet()
- CUS_BAS_Register_Checksheet function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Register_Checksheet(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_REGISTER_CHECKSHEET(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_Register_Checksheet", out_node);
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
CUS_BAS_REGISTER_CHECKSHEET()
- Main sub function of "CUS_BAS_Register_Checksheet" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_REGISTER_CHECKSHEET(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CBASCHKDEF_TAG CBASCHKDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPMATDEF_TAG MWIPMATDEF;

    TRSNode **check_list;

    char s_sys_time[14];
    int check_list_count = 0;
    int i = 0;

    LOG_head("CUS_BAS_Register_Checksheet");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_BAS_Register_Checksheet_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

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

    //공정 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");

    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);

        TRS.add_dberrmsg(out_node, DB_error_msg);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
    
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    // 제품 체크
    DBU_init_mwipmatdef(&MWIPMATDEF);
    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
    memcpy(MWIPMATDEF.MAT_GRP_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
   
    DBU_select_mwipmatdef(2, &MWIPMATDEF);
    if (DB_error_code == DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", MP_NVST);

        TRS.add_dberrmsg(out_node, DB_error_msg);
        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPMATDEF.MAT_GRP_1), MWIPMATDEF.MAT_GRP_1);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    // 체크리스트 정보 삭제하고 모든 리스트를 INSERT 한다.
    DBU_init_cbaschkdef(&CBASCHKDEF);

    TRS.copy(CBASCHKDEF.FACTORY, sizeof(CBASCHKDEF.FACTORY), in_node, IN_FACTORY);
    memcpy(CBASCHKDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CBASCHKDEF.AREA_ID));
    memcpy(CBASCHKDEF.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CBASCHKDEF.SUB_AREA_ID));
    memcpy(CBASCHKDEF.OPER, MWIPOPRDEF.OPER, sizeof(CBASCHKDEF.OPER));
    TRS.copy(CBASCHKDEF.MAT_ID, sizeof(CBASCHKDEF.MAT_ID), in_node, "MAT_ID");

    DBU_delete_cbaschkdef(2, &CBASCHKDEF);
    if (DB_error_code != DB_SUCCESS && DB_error_code !=DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CBASCHKDEF DELETE", MP_NVST);

        TRS.add_dberrmsg(out_node, DB_error_msg);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASCHKDEF.AREA_ID), CBASCHKDEF.AREA_ID);
        TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CBASCHKDEF.SUB_AREA_ID), CBASCHKDEF.SUB_AREA_ID);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CBASCHKDEF.OPER), CBASCHKDEF.OPER);
        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CBASCHKDEF.MAT_ID), CBASCHKDEF.MAT_ID);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    // 체크리스트 정보 Insert
    check_list = TRS.get_list(in_node, "CHECK_LIST");
    check_list_count = TRS.get_item_count(in_node, "CHECK_LIST");

    for (i = 0; i < check_list_count; i++)
    {
        DBU_init_cbaschkdef(&CBASCHKDEF);
        TRS.copy(CBASCHKDEF.FACTORY, sizeof(CBASCHKDEF.FACTORY), in_node, IN_FACTORY);
        memcpy(CBASCHKDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CBASCHKDEF.AREA_ID));
        memcpy(CBASCHKDEF.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CBASCHKDEF.SUB_AREA_ID));
        TRS.copy(CBASCHKDEF.OPER, sizeof(CBASCHKDEF.OPER), in_node, "OPER");
        TRS.copy(CBASCHKDEF.MAT_ID, sizeof(CBASCHKDEF.MAT_ID), in_node, "MAT_ID");
        CBASCHKDEF.SEQ = i+1;
        TRS.copy(CBASCHKDEF.CHK_COMMENT, sizeof(CBASCHKDEF.CHK_COMMENT), check_list[i], "CHK_COMMENT");
        TRS.copy(CBASCHKDEF.CHK_UNIT, sizeof(CBASCHKDEF.CHK_UNIT), check_list[i], "CHK_UNIT");
        TRS.copy(CBASCHKDEF.CREATE_USER_ID, sizeof(CBASCHKDEF.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CBASCHKDEF.CREATE_TIME, s_sys_time, sizeof(CBASCHKDEF.CREATE_TIME));

        DBU_insert_cbaschkdef(&CBASCHKDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CBASCHKDEF INSERT", MP_NVST);

            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASCHKDEF.AREA_ID), CBASCHKDEF.AREA_ID);
            TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CBASCHKDEF.SUB_AREA_ID), CBASCHKDEF.SUB_AREA_ID);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CBASCHKDEF.OPER), CBASCHKDEF.OPER);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CBASCHKDEF.MAT_ID), CBASCHKDEF.MAT_ID);
            TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASCHKDEF.SEQ);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_BAS_Register_Checksheet_Validation()
- Validation Check sub function of "CUS_BAS_REGISTER_CHECKSHEET" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Register_Checksheet_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "MAT_ID", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}