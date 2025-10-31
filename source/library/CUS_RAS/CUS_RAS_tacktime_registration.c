/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_tacktime_registration.c
Description : 표준 TACKTIME 등록

MES Version : 5.0

Function List
- 

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/04  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Tacktime_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_TACKTIME_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Tacktime_Registration()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tacktime_Registration(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_TACKTIME_REGISTRATION(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Tacktime_Registration", out_node);
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
CUS_RAS_TACKTIME_REGISTRATION()
- Main sub function of "CUS_RAS_Tacktime_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_TACKTIME_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CBASTAKTIM_TAG CBASTAKTIM;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MRASRESDEF_TAG MRASRESDEF;

    TRSNode **data_list;
    int data_list_count = 0;

    LOG_head("CUS_RAS_Tacktime_Registration");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    /* Validation Check */
    if (CUS_RAS_Tacktime_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
 
    // step 1 : 등록
    if (TRS.get_procstep(in_node) == '1')
    {
        data_list = TRS.get_list(in_node, "DATA_LIST");
        data_list_count = TRS.get_item_count(in_node, "DATA_LIST");

        for (int i = 0; i < data_list_count; i++)
        {
            //공정 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), data_list[i], "OPER");

            DBU_select_mwipoprdef(1, &MWIPOPRDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0010 : 이 공정은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //설비조회
            DBU_init_mrasresdef(&MRASRESDEF);
            TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), data_list[i], "RES_ID");

            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code != DB_SUCCESS)
            {
            strcpy(s_msg_code, "RAS-0004");
            TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
            }

            //제품조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), data_list[i], "MAT_ID");

            if (TRS.get_int(in_node, "MAT_VER") == 0)
            {
                MWIPMATDEF.MAT_VER = 1;
            }
            else
            {
                MWIPMATDEF.MAT_VER = TRS.get_int(data_list[i], "MAT_VER");
            }

            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, MWIPMATDEF.MAT_VER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            DBU_init_cbastaktim(&CBASTAKTIM);
            TRS.copy(CBASTAKTIM.FACTORY, sizeof(CBASTAKTIM.FACTORY), in_node, IN_FACTORY);
            memcpy(CBASTAKTIM.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CBASTAKTIM.AREA_ID));
            memcpy(CBASTAKTIM.OPER, MWIPOPRDEF.OPER, sizeof(CBASTAKTIM.OPER));
            TRS.copy(CBASTAKTIM.RES_ID, sizeof(CBASTAKTIM.RES_ID), data_list[i], "RES_ID");
            memcpy(CBASTAKTIM.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(CBASTAKTIM.MAT_ID));

            DBU_select_cbastaktim(1, &CBASTAKTIM);
            if (DB_error_code != DB_SUCCESS)
            {
                //조회되지 않으면 INSERT
                if (DB_error_code == DB_NOT_FOUND)
                {
                    CBASTAKTIM.MAT_VER = MWIPMATDEF.MAT_VER;
                    CBASTAKTIM.QTY = TRS.get_double(data_list[i], "QTY");
                    TRS.copy(CBASTAKTIM.UNIT, sizeof(CBASTAKTIM.UNIT), data_list[i], "UNIT");
                    TRS.copy(CBASTAKTIM.CREATE_USER_ID, sizeof(CBASTAKTIM.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CBASTAKTIM.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));

                    DBU_insert_cbastaktim(&CBASTAKTIM);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "BAS-0004");
                        TRS.add_fieldmsg(out_node, "CBASTAKTIM INSERT ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CBASTAKTIM.AREA_ID), CBASTAKTIM.AREA_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CBASTAKTIM.OPER), CBASTAKTIM.OPER);
                        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CBASTAKTIM.RES_ID), CBASTAKTIM.RES_ID);
                        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CBASTAKTIM.MAT_ID), CBASTAKTIM.MAT_ID);
                        TRS.add_fieldmsg(out_node, "UNIT", DT_STRING, sizeof(CBASTAKTIM.UNIT), CBASTAKTIM.UNIT);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }
                else
                {
                    strcpy(s_msg_code, "BAS-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    TRS.add_fieldmsg(out_node, "CBASTAKTIM SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CBASTAKTIM.AREA_ID), CBASTAKTIM.AREA_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CBASTAKTIM.OPER), CBASTAKTIM.OPER);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CBASTAKTIM.RES_ID), CBASTAKTIM.RES_ID);
                    TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CBASTAKTIM.MAT_ID), CBASTAKTIM.MAT_ID);


                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            //조회되면 UPDATE
            else if (DB_error_code == DB_SUCCESS)
            {
                CBASTAKTIM.MAT_VER = MWIPMATDEF.MAT_VER;
                CBASTAKTIM.QTY = TRS.get_double(data_list[i], "QTY");
                TRS.copy(CBASTAKTIM.UNIT, sizeof(CBASTAKTIM.UNIT), data_list[i], "UNIT");
                TRS.copy(CBASTAKTIM.UPDATE_USER_ID, sizeof(CBASTAKTIM.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CBASTAKTIM.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

                DBU_update_cbastaktim(1, &CBASTAKTIM);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "BAS-0004");
                    TRS.add_fieldmsg(out_node, "CBASTAKTIM UPDATE ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CBASTAKTIM.AREA_ID), CBASTAKTIM.AREA_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CBASTAKTIM.OPER), CBASTAKTIM.OPER);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CBASTAKTIM.RES_ID), CBASTAKTIM.RES_ID);
                    TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CBASTAKTIM.MAT_ID), CBASTAKTIM.MAT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }
    }
    // step 2 : 삭제
    else if (TRS.get_procstep(in_node) == '2')
    {
        data_list = TRS.get_list(in_node, "DATA_LIST");
        data_list_count = TRS.get_item_count(in_node, "DATA_LIST");

        for (int i = 0; i < data_list_count; i++)
        {
            //공정 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), data_list[i], "OPER");

            DBU_select_mwipoprdef(1, &MWIPOPRDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0010 : 이 공정은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            DBU_init_cbastaktim(&CBASTAKTIM);
            TRS.copy(CBASTAKTIM.FACTORY, sizeof(CBASTAKTIM.FACTORY), in_node, IN_FACTORY);
            memcpy(CBASTAKTIM.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CBASTAKTIM.AREA_ID));
            memcpy(CBASTAKTIM.OPER, MWIPOPRDEF.OPER, sizeof(CBASTAKTIM.OPER));
            TRS.copy(CBASTAKTIM.RES_ID, sizeof(CBASTAKTIM.RES_ID), data_list[i], "RES_ID");
            TRS.copy(CBASTAKTIM.MAT_ID, sizeof(CBASTAKTIM.MAT_ID), data_list[i], "MAT_ID");

            DBU_delete_cbastaktim(1, &CBASTAKTIM);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "BAS-0004");
                TRS.add_fieldmsg(out_node, "CBASTAKTIM DELETE ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CBASTAKTIM.AREA_ID), CBASTAKTIM.AREA_ID);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CBASTAKTIM.OPER), CBASTAKTIM.OPER);
                TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CBASTAKTIM.RES_ID), CBASTAKTIM.RES_ID);
                TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CBASTAKTIM.MAT_ID), CBASTAKTIM.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
    }
   
    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_Tacktime_Registration_Validation()
- Validation Check sub function of "CUS_RAS_TACKTIME_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Tacktime_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
