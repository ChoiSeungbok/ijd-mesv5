/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_scrap_mold_request.c
Description : 금형 폐기 요청

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/25  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_SCRAP_MOLD_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Scrap_Mold_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Scrap_Mold_Request()
- CUS_RAS_Scrap_Mold_Request function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Scrap_Mold_Request(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_SCRAP_MOLD_REQUEST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Scrap_Mold_Request", out_node);
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
CUS_RAS_SCRAP_MOLD_REQUEST()
- Main sub function of "CUS_RAS_Scrap_Mold_Request" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_SCRAP_MOLD_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRASDSPREQ_TAG CRASDSPREQ;
    struct CRASDSPTOL_TAG CRASDSPTOL;

    TRSNode *create_in_node;
    TRSNode *cmn_out;
    TRSNode **request_mold_list;
    TRSNode *mold_list;

    char s_sys_time[14];

    int request_mold_count = 0;
    int i = 0;

    LOG_head("CUS_RAS_Scrap_Mold_Request");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    /*' Validation Check */
    if (CUS_RAS_Scrap_Mold_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
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

    // step 1. 금형 폐기 요청 Create
    // step 2. 금평 폐기 요청 Update
    if (TRS.get_procstep(in_node) == '1'|| TRS.get_procstep(in_node) == '2')
    {
        create_in_node = TRS.add_node(in_node, "create_in_node");
        TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));
        CopyDefaultMembers(create_in_node, in_node);

        TRS.add_nstring(create_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
        TRS.add_nstring(create_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
        TRS.add_nstring(create_in_node, "SUB_AREA_ID", TRS.get_string(in_node, "SUB_AREA_ID"));
        TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_nstring(create_in_node, "REQ_USER_ID", TRS.get_string(in_node, "REQ_USER_ID"));
        TRS.add_nstring(create_in_node, "REQ_COMMENT", TRS.get_string(in_node, "REQ_COMMENT"));

        request_mold_list = TRS.get_list(in_node, "REQUEST_TOOL_LIST");
        request_mold_count = TRS.get_item_count(in_node, "REQUEST_TOOL_LIST");

        // 요청된 금형 폐기 리스트 개수 체크(한 개 이상 선택)
        if (request_mold_count <= 0)
        {
            strcpy(s_msg_code, "RAS-0322");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_COMMON;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        for (i = 0; i<request_mold_count; i++)
        {
            mold_list = TRS.add_node(create_in_node, "REQUEST_TOOL_LIST");
            TRS.add_nstring(mold_list, "TOOL_ID", TRS.get_string(request_mold_list[i], "TOOL_ID"));
        }

        cmn_out = TRS.create_node("cmn_out");
        if (CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN(s_msg_code, create_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }

        TRS.add_string(out_node, "REQ_NO", TRS.get_string(cmn_out, "REQ_NO"), strlen(TRS.get_string(cmn_out, "REQ_NO")));
        TRS.free_node(cmn_out);        
    }     
    else
    {
        DBU_init_crasdspreq(&CRASDSPREQ);
        TRS.copy(CRASDSPREQ.FACTORY, sizeof(CRASDSPREQ.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CRASDSPREQ.REQ_NO, sizeof(CRASDSPREQ.REQ_NO), in_node, "REQ_NO");

        //요청 정보 조회
        DBU_select_crasdspreq(1, &CRASDSPREQ);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CRASDSPREQ SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }
        // step 3. 금형 폐기 요청 Confrim
        if (TRS.get_procstep(in_node) == '3')
        {
            if (memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_REQUEST, strlen(MP_CRAS_DSP_REQ_STATUS_REQUEST)) != 0)
            {
                strcpy(s_msg_code, "RAS-0321");
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
                TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(CRASDSPREQ.REQ_STATUS), CRASDSPREQ.REQ_STATUS);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_COMMON;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            memcpy(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_CONFIRM, sizeof(CRASDSPREQ.REQ_STATUS));        
            TRS.copy(CRASDSPREQ.UPDATE_USER_ID, sizeof(CRASDSPREQ.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CRASDSPREQ.UPDATE_TIME, s_sys_time, sizeof(CRASDSPREQ.UPDATE_TIME));

            DBU_update_crasdspreq(1, &CRASDSPREQ);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASDSPREQ UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

        }
        // step 4. 금형 폐기 요청 Confrim 취소
        else if (TRS.get_procstep(in_node) == '4')
        {
            if (memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_COMPLETED, strlen(MP_CRAS_DSP_REQ_STATUS_COMPLETED)) == 0)
            {
                strcpy(s_msg_code, "RAS-0321");
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
                TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(CRASDSPREQ.REQ_STATUS), CRASDSPREQ.REQ_STATUS);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_COMMON;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            memcpy(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_REQUEST, sizeof(CRASDSPREQ.REQ_STATUS));
            TRS.copy(CRASDSPREQ.UPDATE_USER_ID, sizeof(CRASDSPREQ.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CRASDSPREQ.UPDATE_TIME, s_sys_time, sizeof(CRASDSPREQ.UPDATE_TIME));

            DBU_update_crasdspreq(1, &CRASDSPREQ);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASDSPREQ UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }
        }
        //step 5. 금형 폐기 요청 삭제
        else if (TRS.get_procstep(in_node) == '5')
        {
            if (memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_CONFIRM, strlen(MP_CRAS_DSP_REQ_STATUS_CONFIRM)) == 0
                ||memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_COMPLETED, sizeof(CRASDSPREQ.REQ_STATUS)) == 0)
            {
                strcpy(s_msg_code, "RAS-0321");
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
                TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(CRASDSPREQ.REQ_STATUS), CRASDSPREQ.REQ_STATUS);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_COMMON;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //폐기 리스트 삭제
            DBU_init_crasdsptol(&CRASDSPTOL);
            TRS.copy(CRASDSPTOL.FACTORY, sizeof(CRASDSPTOL.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CRASDSPTOL.REQ_NO, sizeof(CRASDSPTOL.REQ_NO), in_node, "REQ_NO");

            DBU_delete_crasdsptol(2, &CRASDSPTOL);
            if (DB_error_code != DB_SUCCESS && DB_error_code!=DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASDSPTOL DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            //폐기 요청 정보 삭제
            DBU_delete_crasdspreq(1, &CRASDSPREQ);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASDSPREQ DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
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
CUS_RAS_Scrap_Mold_Request_Validation()
- Validation Check sub function of "CUS_RAS_SCRAP_MOLD_REQUEST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Scrap_Mold_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12345") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}