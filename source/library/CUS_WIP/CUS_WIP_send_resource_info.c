/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_send_resource_info.c
Description : 설비에 레시피 정보를 전송한다.

MES Version : 5.0

Function List
-
 
Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/22  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_SEND_RESOURCE_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Send_Resource_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Send_Resource_Info()
- 설비에 레시피 정보를 전송한다.
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Send_Resource_Info(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_SEND_RESOURCE_INFO(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Send_Resource_Info", out_node);

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
CUS_WIP_SEND_RESOURCE_INFO()
- Main sub function of "CUS_WIP_Send_Resource_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_SEND_RESOURCE_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    //struct MWIPMATDEF_TAG MWIPMATDEF;     //제품 마스터
    struct MRASRESDEF_TAG MRASRESDEF;     //설비 마스터
    struct MWIPOPRDEF_TAG MWIPOPRDEF;     //공정 마스터
    struct MWIPORDSTS_TAG MWIPORDSTS;     //작업지시 마스터
    struct MWIPIDGHIS_TAG MWIPIDGHIS;     //
    struct MWIPIDGHIS_TAG MWIPIDGHIS_TO;     //
    
    struct work_date_tag work_date;
    TRSNode *send_in;
    TRSNode *gen_in_node;
    int iCount = 0;
    int i = 0;
    int iCheckSeq = 0;
    char c_skip_yn;
    char s_factory[10];

    memset(s_factory, ' ', sizeof(s_factory));

    // LOG
    LOG_head("CUS_WIP_Send_Resource_Info");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(s_factory, &work_date);

    // VALIDATION CHECK
    if (CUS_WIP_Send_Resource_Info_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //작업지시 조회
    DBU_init_mwipordsts(&MWIPORDSTS);
    TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
    DBU_select_mwipordsts(1, &MWIPORDSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //ORD-0002 : 이 ORDER는 존재하지 않습니다.
        strcpy(s_msg_code, "ORD-0002");
        TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
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

    if (TRS.get_procstep(in_node) == '1')
    {
        //공정OPTION의 ID 발번 규칙(DATA_3)에 등록된 ID 발번 규칙으로 해당 공정의 LOT ID를 채번한다.
        gen_in_node = TRS.add_node(in_node, "gen_in_node");
        TRS.add_char(gen_in_node, "PROCSTEP", '2');
        CopyDefaultMembers(gen_in_node, in_node);
        TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_CTM_ACUP_LOT, strlen(MP_ID_ROLE_CTM_ACUP_LOT));
        TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
        TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
        TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
        TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, out_node) == MP_FALSE)
        {
            return MP_FALSE;
        }

        TRS.add_nstring(out_node, "LOT_ID", TRS.get_string(out_node, "GEN_ID"));
    }
    else if (TRS.get_procstep(in_node) == '2')
    {
        if (TRS.get_char(in_node, "CUP_YN") == 'Y')
        {
            // LOT_ID VALIDATION
            if (COM_isnullspace(TRS.get_string(in_node, "CUP_LOT_ID")) == MP_TRUE)
            {
                strcpy(s_msg_code, "WIP-0001");
                TRS.add_fieldmsg(out_node, "CUP_LOT_ID", MP_NVST);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            DBU_init_mrasresdef(&MRASRESDEF);
            TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "CUP_RES_ID");
            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //EDC-0021 : 이 장비는 존재 하지 않습니다. 장비를 확인 하세요.
                strcpy(s_msg_code, "EDC-0021");
                TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //설비에 보내는 lot의 수만큼 lot id를 발번해 놓는다. 다음 발번할 lot seq를 맞추기 위해. 
            iCount = TRS.get_int(in_node, "LOT_QTY");
            for (i = 0; i < iCount-1; i++)
            {
                c_skip_yn = 'N';

                DBU_init_mwipidghis(&MWIPIDGHIS);
                TRS.copy(MWIPIDGHIS.FACTORY, sizeof(MWIPIDGHIS.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPIDGHIS.RULE_ID, MP_ID_ROLE_CTM_ACUP_LOT, strlen(MP_ID_ROLE_CTM_ACUP_LOT));
                TRS.copy(MWIPIDGHIS.GEN_ID, sizeof(MWIPIDGHIS.GEN_ID), in_node, "CUP_LOT_ID");                
                DBU_select_mwipidghis(2, &MWIPIDGHIS);
                if (DB_error_code == DB_SUCCESS)
                {
                    iCheckSeq = MWIPIDGHIS.SEQ_NUM;

                    DBU_init_mwipidghis(&MWIPIDGHIS_TO);
                    memcpy(MWIPIDGHIS_TO.FACTORY, MWIPIDGHIS.FACTORY, sizeof(MWIPIDGHIS.FACTORY));
                    memcpy(MWIPIDGHIS_TO.RULE_ID, MWIPIDGHIS.RULE_ID, sizeof(MWIPIDGHIS.RULE_ID));
                    TRS.copy(MWIPIDGHIS_TO.OPER, sizeof(MWIPIDGHIS_TO.OPER), in_node, "OPER");
                    memcpy(MWIPIDGHIS_TO.MAT_ID, MWIPORDSTS.MAT_ID, sizeof(MWIPIDGHIS_TO.MAT_ID));
                    memcpy(MWIPIDGHIS_TO.RES_ID, MRASRESDEF.RES_ID, sizeof(MWIPIDGHIS_TO.RES_ID));
                    memcpy(MWIPIDGHIS_TO.DATETIME, MWIPIDGHIS.DATETIME, sizeof(MWIPIDGHIS.DATETIME));
                    MWIPIDGHIS_TO.SEQ_NUM = iCheckSeq + (i + 1);

                    if ((int)DBU_select_mwipidghis_scalar(2, &MWIPIDGHIS_TO) > 0)
                    {
                        c_skip_yn = 'Y';
                    }
                }
    
                if (c_skip_yn == 'N')
                {
                    gen_in_node = TRS.add_node(in_node, "gen_in_node");
                    TRS.add_char(gen_in_node, "PROCSTEP", '2');
                    CopyDefaultMembers(gen_in_node, in_node);
                    TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_CTM_ACUP_LOT, strlen(MP_ID_ROLE_CTM_ACUP_LOT));
                    TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
                    TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
                    TRS.add_string(gen_in_node, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
                    TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
                    TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

                    if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, out_node) == MP_FALSE)
                    {
                        return MP_FALSE;
                    }
                }
                
            }

            send_in = TRS.add_node(in_node, "send_in");
            CopyDefaultMembers(send_in, in_node);

            TRS.add_char(send_in, IN_PROCSTEP, '1');
            TRS.add_nstring(send_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
            TRS.add_nstring(send_in, "OPER", TRS.get_string(in_node, "OPER"));

            TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(in_node, "CUP_LOT_ID"));
            TRS.add_int(send_in, "LOT_QTY", TRS.get_int(in_node, "LOT_QTY"));
            TRS.add_string(send_in, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
            TRS.add_nstring(send_in, "RECIPE_ID", TRS.get_string(in_node, "CUP_RECIPE_ID"));
            TRS.add_nstring(send_in, "AUTO_FLAG", TRS.get_string(in_node, "AUTO_FLAG"));
            TRS.add_string(send_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));

            if (CUS_EIS_BASIS_LOT(s_msg_code, send_in, out_node) == MP_FALSE)
                return MP_FALSE;
        }

        if (TRS.get_char(in_node, "IMP_YN") == 'Y')
        {
            // LOT_ID VALIDATION
            if (COM_isnullspace(TRS.get_string(in_node, "IMP_LOT_ID")) == MP_TRUE)
            {
                strcpy(s_msg_code, "WIP-0001");
                TRS.add_fieldmsg(out_node, "IMP_LOT_ID", MP_NVST);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            DBU_init_mrasresdef(&MRASRESDEF);
            TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "IMP_RES_ID");
            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //EDC-0021 : 이 장비는 존재 하지 않습니다. 장비를 확인 하세요.
                strcpy(s_msg_code, "EDC-0021");
                TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            send_in = TRS.add_node(in_node, "send_in");
            CopyDefaultMembers(send_in, in_node);

            TRS.add_char(send_in, IN_PROCSTEP, '1');
            TRS.add_nstring(send_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
            TRS.add_nstring(send_in, "OPER", TRS.get_string(in_node, "OPER"));

            TRS.add_nstring(send_in, "LOT_ID", TRS.get_string(in_node, "IMP_LOT_ID"));
            TRS.add_int(send_in, "LOT_QTY", TRS.get_int(in_node, "LOT_QTY"));
            TRS.add_string(send_in, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
            TRS.add_nstring(send_in, "RECIPE_ID", TRS.get_string(in_node, "IMP_RECIPE_ID"));
            TRS.add_nstring(send_in, "AUTO_FLAG", TRS.get_string(in_node, "AUTO_FLAG"));
            TRS.add_string(send_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));

            if (CUS_EIS_BASIS_LOT(s_msg_code, send_in, out_node) == MP_FALSE)
                return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_SEND_RESOURCE_INFO()
- Main sub function of "CUS_WIP_SEND_RESOURCE_INFO" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- struct MRASRESDEF_TAG *MRASRESDEF : 설비
- struct MWIPLOTSTSX_TAG *MWIPLOTSTS : Lot 정보
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Send_Resource_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
    {
        return MP_FALSE;
    }

    // FACTORY VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }
    // ORDER ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    // OPER VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    // RES_ID VALIDATION
    if (TRS.get_procstep(in_node) == '1')
    {
        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "RES_ID", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_TRANS;

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
