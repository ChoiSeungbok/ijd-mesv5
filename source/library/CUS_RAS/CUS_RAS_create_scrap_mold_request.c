/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_create_scrap_mold_request.c
Description : 금형 폐기 요청 생성

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/02  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_CREATE_SCRAP_MOLD_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Create_Scrap_Mold_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Create_Scrap_Mold_Request()
- CUS_RAS_Create_Scrap_Mold_Request function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Create_Scrap_Mold_Request(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Create_Scrap_Mold_Request", out_node);

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
CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN()
- Main sub function of "CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *create_in_node;
    TRSNode	*gen_in_node;
    TRSNode	*cmn_out;
    TRSNode **request_tool_list;
    TRSNode *tool_list;

    char req_no[21];
    int request_mold_count = 0;
    int i = 0;

    LOG_head("CUS_RAS_Scrap_Mold_Request");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    /*' Validation Check */
    if (CUS_RAS_Create_Scrap_Mold_Request_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memset(req_no, ' ', sizeof(req_no));

    create_in_node = TRS.add_node(in_node, "create_in_node");
    CopyDefaultMembers(create_in_node, in_node);

    TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

    // PROCSTEP = 1 -> 신규 생성
    // PROCSTEP = 2 -> 저장
    if (TRS.get_procstep(in_node) == '1')
    {
        gen_in_node = TRS.add_node(in_node, "gen_in_node");

        CopyDefaultMembers(gen_in_node, in_node);
        TRS.add_string(gen_in_node, "RULE_ID", "MOLD_REQ_NO", strlen("MOLD_REQ_NO"));
        TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

        cmn_out = TRS.create_node("cmn_out");
        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        memcpy(req_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

        TRS.free_node(cmn_out);

        TRS.add_string(create_in_node, "REQ_NO", req_no, sizeof(req_no));       
    }
    else if(TRS.get_procstep(in_node) == '2')
    {
        TRS.add_nstring(create_in_node, "REQ_NO", TRS.get_string(in_node, "REQ_NO"));
    }

    TRS.add_nstring(create_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
    TRS.add_nstring(create_in_node, "SUB_AREA_ID", TRS.get_string(in_node, "SUB_AREA_ID"));
    TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(create_in_node, "REQ_USER_ID", TRS.get_string(in_node, "REQ_USER_ID"));
    TRS.add_nstring(create_in_node, "REQ_COMMENT", TRS.get_string(in_node, "REQ_COMMENT"));

    request_tool_list = TRS.get_list(in_node, "REQUEST_TOOL_LIST");
    request_mold_count = TRS.get_item_count(in_node, "REQUEST_TOOL_LIST");

    for (i = 0; i < request_mold_count; i++)
    {
        tool_list = TRS.add_node(create_in_node, "REQUEST_TOOL_LIST");
        TRS.add_nstring(tool_list, "TOOL_ID", TRS.get_string(request_tool_list[i], "TOOL_ID"));
    }

    if (CUS_RAS_CREATE_SCRAP_MOLD_REQUEST(s_msg_code, create_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    TRS.add_string(out_node, "REQ_NO", TRS.get_string(create_in_node, "REQ_NO"), sizeof(req_no));

    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_CREATE_SCRAP_MOLD_REQUEST()
- Main sub function of "CUS_RAS_Scrap_Mold_Request" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_CREATE_SCRAP_MOLD_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRASDSPREQ_TAG CRASDSPREQ;
    struct CRASDSPTOL_TAG CRASDSPTOL;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct CWIPWRKDEF_TAG CWIPWRKDEF;
    struct MRASTOLDEF_TAG MRASTOLDEF;

    TRSNode **request_tool_list;

    char s_sys_time[15];
    int request_tool_list_count = 0;
    int i = 0;
 
    memset(s_sys_time, ' ', sizeof(s_sys_time));

    //DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    // MWIPOPRDEF - 요청 창고 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");

    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    // CWIPWRKDEF - 작업자 조회
    DBU_init_cwipwrkdef(&CWIPWRKDEF);
    TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID), in_node, "REQ_USER_ID");
    TRS.copy(CWIPWRKDEF.AREA_ID, sizeof(CWIPWRKDEF.AREA_ID), in_node, "AREA_ID");
    TRS.copy(CWIPWRKDEF.SUB_AREA_ID, sizeof(CWIPWRKDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");

	// 벨리데이션은 사업부만 체크로 수정 (step 2 => 4 )
    DBU_select_cwipwrkdef(4, &CWIPWRKDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPWRKDEF.AREA_ID), CWIPWRKDEF.AREA_ID);
        TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(CWIPWRKDEF.SUB_AREA_ID), CWIPWRKDEF.SUB_AREA_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    DBU_init_crasdspreq(&CRASDSPREQ);
    TRS.copy(CRASDSPREQ.FACTORY, sizeof(CRASDSPREQ.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CRASDSPREQ.REQ_NO, sizeof(CRASDSPREQ.REQ_NO), in_node, "REQ_NO");

    // PROCSTEP = 1 -> 금형 폐기 요청 INSERT
    // PROCSTEP = 2 -> 금형 폐기 요청 UPDATAE
    if (TRS.get_procstep(in_node) == '2')
    {
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

        if (memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_REQUEST, strlen(MP_CRAS_DSP_REQ_STATUS_REQUEST)) !=0)
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
    }

    TRS.copy(CRASDSPREQ.AREA_ID, sizeof(CRASDSPREQ.AREA_ID), in_node, "AREA_ID");
    TRS.copy(CRASDSPREQ.SUB_AREA_ID, sizeof(CRASDSPREQ.SUB_AREA_ID), in_node, "SUB_AREA_ID");
    TRS.copy(CRASDSPREQ.OPER, sizeof(CRASDSPREQ.OPER), in_node, "OPER");
    TRS.copy(CRASDSPREQ.REQ_USER_ID, sizeof(CRASDSPREQ.REQ_USER_ID), in_node, "REQ_USER_ID");
    TRS.copy(CRASDSPREQ.REQ_COMMENT, sizeof(CRASDSPREQ.REQ_COMMENT), in_node, "REQ_COMMENT");
    memcpy(CRASDSPREQ.REQ_TIME, s_sys_time, sizeof(CRASDSPREQ.REQ_TIME));

    if (TRS.get_procstep(in_node) == '1')
    {
        memcpy(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_REQUEST, sizeof(CRASDSPREQ.REQ_STATUS));
        memcpy(CRASDSPREQ.CREATE_TIME, s_sys_time, sizeof(CRASDSPREQ.CREATE_TIME));
        TRS.copy(CRASDSPREQ.CREATE_USER_ID, sizeof(CRASDSPREQ.CREATE_USER_ID), in_node, IN_USERID);

        DBU_insert_crasdspreq(&CRASDSPREQ);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CRASDSPREQ INSERT", MP_NVST);
            TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }
    }
    else if (TRS.get_procstep(in_node) == '2')
    {
        memcpy(CRASDSPREQ.UPDATE_TIME, s_sys_time, sizeof(CRASDSPREQ.UPDATE_TIME));
        TRS.copy(CRASDSPREQ.UPDATE_USER_ID, sizeof(CRASDSPREQ.UPDATE_USER_ID), in_node, IN_USERID);

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

    //금평 폐기 리스트를 삭제하고 모든 리스트를 INSERT 한다.
    DBU_init_crasdsptol(&CRASDSPTOL);
    TRS.copy(CRASDSPTOL.FACTORY, sizeof(CRASDSPTOL.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CRASDSPTOL.REQ_NO, sizeof(CRASDSPTOL.REQ_NO), in_node, "REQ_NO");

    DBU_delete_crasdsptol(2, &CRASDSPTOL);
    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CRASDSPTOL DELETE", MP_NVST);
        TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    request_tool_list = TRS.get_list(in_node, "REQUEST_TOOL_LIST");
    request_tool_list_count = TRS.get_item_count(in_node, "REQUEST_TOOL_LIST");

    for (i = 0; i < request_tool_list_count; i++)
    {
        //MRASTOLDEF - 도구 정보 조회
        DBU_init_mrastoldef(&MRASTOLDEF);
        TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), request_tool_list[i], "TOOL_ID");
        DBU_select_mrastoldef(1, &MRASTOLDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        //폐기된 도구인지 체크
        if (MRASTOLDEF.DELETE_FLAG == 'Y')
        {
            strcpy(s_msg_code, "RAS-0171");
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_COMMON;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }


       
        //금형 폐기 리스트 조회
        DBU_init_crasdsptol(&CRASDSPTOL);
        TRS.copy(CRASDSPTOL.FACTORY, sizeof(CRASDSPTOL.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CRASDSPTOL.TOOL_ID, sizeof(CRASDSPTOL.TOOL_ID), request_tool_list[i], "TOOL_ID");

        DBU_select_crasdsptol(2, &CRASDSPTOL);
        if (DB_error_code != DB_SUCCESS)
        {
            //금형 폐기 리스트에 존재하지 않는 경우 INSERT
            if (DB_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CRASDSPTOL.REQ_NO, sizeof(CRASDSPTOL.REQ_NO), in_node, "REQ_NO");
                TRS.copy(CRASDSPTOL.CREATE_USER_ID, sizeof(CRASDSPTOL.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CRASDSPTOL.CREATE_TIME, s_sys_time, sizeof(CRASDSPTOL.CREATE_TIME));

                DBU_insert_crasdsptol(&CRASDSPTOL);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CRASDSPTOL INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
                    TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                    return MP_FALSE;
                }
            }
            else
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASDSPTOL SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
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
CUS_RAS_Create_Scrap_Mold_Request_Validation()
- Validation Check sub function of "CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Create_Scrap_Mold_Request_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
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

        return MP_FALSE;
    }

    return MP_TRUE;
}