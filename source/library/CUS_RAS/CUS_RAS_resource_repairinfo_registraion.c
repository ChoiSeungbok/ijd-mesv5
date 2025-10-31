/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_resouce_repairinfo_registration.c
Description : 설비 수리 정보 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/28  SR.SON        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_Resouce_Repairinfo_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Resouce_Repairinfo_Registration()
- 프로그램 테스트
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Resouce_Repairinfo_Registration(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Resouce_Repairinfo_Registration", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

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
CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION()
- Main sub function of "CUS_RAS_Resouce_Repairinfo_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRASRPRSTS_TAG CRASRPRSTS;
    struct CRASRPRSPR_TAG CRASRPRSPR;
    struct CRASRPRWRK_TAG CRASRPRWRK;

    TRSNode     *gen_in_node;
    TRSNode     *cmn_out;

    TRSNode     **spare_list;
    TRSNode     **worker_list;

    char c_flag = ' ';
    char repair_id[21];

    double action_use_time = 0;
    double worst_bm_time = 0;

    int spare_count = 0;
    int worker_count = 0;

    LOG_head("CUS_RAS_Resouce_Repairinfo_Registration");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_Resouce_Repairinfo_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    DBU_init_crasrprsts(&CRASRPRSTS);

    // 수리번호 신규 채번
    if (TRS.get_procstep(in_node) == '1')
    {
        memset(repair_id, ' ', sizeof(repair_id));

        gen_in_node = TRS.add_node(in_node, "gen_in_node");

        CopyDefaultMembers(gen_in_node, in_node);
        TRS.add_string(gen_in_node, "RULE_ID", "REPAIR_ID", strlen("REPAIR_ID"));
        TRS.add_char(gen_in_node, "PROCSTEP", '2');

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        memcpy(repair_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
        TRS.free_node(cmn_out);

        TRS.add_string(out_node, "REPAIR_ID", repair_id, sizeof(repair_id));
    }
    //설비 정보 저장
    else if (TRS.get_procstep(in_node) == '2')
    {
        TRS.copy(CRASRPRSTS.FACTORY, sizeof(CRASRPRSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRSTS.REPAIR_ID), in_node, "REPAIR_ID");

        if (COM_isnullspace(TRS.get_string(in_node, "REPAIR_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "REPAIR_ID IS NULL", MP_NVST);
            TRS.add_fieldmsg(out_node, "REPAIR_ID", MP_STR, sizeof(CRASRPRSTS.REPAIR_ID), CRASRPRSTS.REPAIR_ID);

            return MP_FALSE;
        }
            
        DBU_select_crasrprsts(1, &CRASRPRSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
            {
                c_flag = 'I';
            }
            else
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRSTS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "REPAIR_ID", MP_STR, sizeof(CRASRPRSTS.REPAIR_ID), CRASRPRSTS.REPAIR_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_SETUP;

                return MP_FALSE;
            }
        }
        else
        {
            c_flag = 'U';
        }

        worker_count = TRS.get_item_count(in_node, "WORKER_LIST");

        TRS.copy(CRASRPRSTS.WORK_DATE, sizeof(CRASRPRSTS.WORK_DATE), in_node, "WORK_DATE");
        CRASRPRSTS.MONTH = TRS.get_int(in_node, "MONTH");
        CRASRPRSTS.WEEK = TRS.get_int(in_node, "WEEK");
        CRASRPRSTS.WEEKEND_FLAG = TRS.get_char(in_node, "WEEKEND_FLAG");
        TRS.copy(CRASRPRSTS.REPAIR_STATUS, sizeof(CRASRPRSTS.REPAIR_STATUS), in_node, "REPAIR_STATUS");
        TRS.copy(CRASRPRSTS.AREA_ID, sizeof(CRASRPRSTS.AREA_ID), in_node, "AREA_ID");
        TRS.copy(CRASRPRSTS.SUB_AREA_ID, sizeof(CRASRPRSTS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        TRS.copy(CRASRPRSTS.OPER, sizeof(CRASRPRSTS.OPER), in_node, "OPER");
        TRS.copy(CRASRPRSTS.RES_ID, sizeof(CRASRPRSTS.RES_ID), in_node, "RES_ID");
        TRS.copy(CRASRPRSTS.GRADE, sizeof(CRASRPRSTS.GRADE), in_node, "GRADE");
        TRS.copy(CRASRPRSTS.REPAIR_TYPE, sizeof(CRASRPRSTS.REPAIR_TYPE), in_node, "REPAIR_TYPE");
        TRS.copy(CRASRPRSTS.ALRAM_TIME, sizeof(CRASRPRSTS.ALRAM_TIME), in_node, "ALRAM_TIME");
        TRS.copy(CRASRPRSTS.ACTION_START_TIME, sizeof(CRASRPRSTS.ACTION_START_TIME), in_node, "ACTION_START_TIME");
        TRS.copy(CRASRPRSTS.ACTION_END_TIME, sizeof(CRASRPRSTS.ACTION_END_TIME), in_node, "ACTION_END_TIME");
        action_use_time = TRS.get_double(in_node, "ACTION_USE_TIME");
        CRASRPRSTS.ACTION_USE_TIME = action_use_time;
        CRASRPRSTS.TOTAL_USE_TIME = TRS.get_double(in_node, "TOTAL_USE_TIME");
        //WORST_BM_TIME
        //ACTION_USE_TIME이 100시간 이상일 때 실 조치시간(시간)
        worst_bm_time = round(action_use_time / 60);
        CRASRPRSTS.WORST_BM_TIME = (worst_bm_time >=100? worst_bm_time :0);

        TRS.copy(CRASRPRSTS.RECEPTION_DATA, sizeof(CRASRPRSTS.RECEPTION_DATA), in_node, "RECEPTION_DATA");
        TRS.copy(CRASRPRSTS.BREAK_CLASS, sizeof(CRASRPRSTS.BREAK_CLASS), in_node, "BREAK_CLASS");
        TRS.copy(CRASRPRSTS.BREAK_PART, sizeof(CRASRPRSTS.BREAK_PART), in_node, "BREAK_PART");
        TRS.copy(CRASRPRSTS.BREAK_TYPE, sizeof(CRASRPRSTS.BREAK_TYPE), in_node, "BREAK_TYPE");
        TRS.copy(CRASRPRSTS.CAUSE_DATA, sizeof(CRASRPRSTS.CAUSE_DATA), in_node, "CAUSE_DATA");
        TRS.copy(CRASRPRSTS.ACTION_DATA, sizeof(CRASRPRSTS.ACTION_DATA), in_node, "ACTION_DATA");
        TRS.copy(CRASRPRSTS.REMARK, sizeof(CRASRPRSTS.REMARK), in_node, "REMARK");
        CRASRPRSTS.MAN_HOUR = worker_count*action_use_time / 8 * 60;
        CRASRPRSTS.WORKER_COUNT = worker_count;
        
        if (c_flag == 'I')
        {
            TRS.copy(CRASRPRSTS.WORK_USER_ID, sizeof(CRASRPRSTS.WORK_USER_ID), in_node, IN_USERID); 
            TRS.copy(CRASRPRSTS.CREATE_USER_ID, sizeof(CRASRPRSTS.CREATE_USER_ID), in_node, IN_USERID);
            DB_get_systime(CRASRPRSTS.CREATE_TIME);

            DBU_insert_crasrprsts(&CRASRPRSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                //RAS-0150 : 설비 수리 정보 생성할 수 없습니다
                strcpy(s_msg_code, "RAS-0150");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "CRASRPRSTS INSERT ", DT_NOVALUESTRING);

                return MP_FALSE;
            }
        }
        else if (c_flag == 'U')
        {
            TRS.copy(CRASRPRSTS.UPDATE_USER_ID, sizeof(CRASRPRSTS.UPDATE_USER_ID), in_node, IN_USERID);
            DB_get_systime(CRASRPRSTS.UPDATE_TIME);

            DBU_update_crasrprsts(1, &CRASRPRSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRSTS UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REPAIR_ID", MP_STR, sizeof(CRASRPRSTS.REPAIR_ID), CRASRPRSTS.REPAIR_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_SETUP;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }   

        //설비 수리 스페어 리스트 저장
        DBU_init_crasrprspr(&CRASRPRSPR);
        TRS.copy(CRASRPRSPR.FACTORY, sizeof(CRASRPRSPR.FACTORY), in_node, IN_FACTORY);
        memcpy(CRASRPRSPR.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRSPR.REPAIR_ID));

        DBU_delete_crasrprspr(2, &CRASRPRSPR);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRSPR DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASRPRSPR.SPARE_ID), CRASRPRSPR.SPARE_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_SETUP;

                return MP_FALSE;
            }
        }

        spare_list = TRS.get_list(in_node, "SPARE_LIST");
        spare_count = TRS.get_item_count(in_node, "SPARE_LIST");

        for (int i = 0; i < spare_count; i++)
        {
            DBU_init_crasrprspr(&CRASRPRSPR);
            TRS.copy(CRASRPRSPR.FACTORY, sizeof(CRASRPRSPR.FACTORY), in_node, IN_FACTORY);
            memcpy(CRASRPRSPR.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRSPR.REPAIR_ID));
            TRS.copy(CRASRPRSPR.SPARE_ID, sizeof(CRASRPRSPR.SPARE_ID), spare_list[i], "SPARE_ID");
            TRS.copy(CRASRPRSPR.SPARE_MAT_ID, sizeof(CRASRPRSPR.SPARE_MAT_ID), spare_list[i], "SPARE_MAT_ID");
            TRS.copy(CRASRPRSPR.SPARE_SPEC_ID, sizeof(CRASRPRSPR.SPARE_SPEC_ID), spare_list[i], "SPARE_SPEC_ID");
            CRASRPRSPR.USE_COUNT = TRS.get_double(spare_list[i], "USE_COUNT");
            TRS.copy(CRASRPRSPR.CREATE_USER_ID, sizeof(CRASRPRSPR.CREATE_USER_ID), in_node, IN_USERID);
            DB_get_systime(CRASRPRSPR.CREATE_TIME);

            DBU_insert_crasrprspr(&CRASRPRSPR);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code != DB_NOT_FOUND)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CRASRPRSPR INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "SPARE_ID", DT_STRING, sizeof(CRASRPRSPR.SPARE_ID), CRASRPRSPR.SPARE_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }

        //설비 수리 투입인원 리스트 저장
        DBU_init_crasrprwrk(&CRASRPRWRK);
        TRS.copy(CRASRPRWRK.FACTORY, sizeof(CRASRPRWRK.FACTORY), in_node, IN_FACTORY);
        memcpy(CRASRPRWRK.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRWRK.REPAIR_ID));

        DBU_delete_crasrprwrk(2, &CRASRPRWRK);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRWRK DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REPAIR_ID", DT_STRING, sizeof(CRASRPRWRK.REPAIR_ID), CRASRPRWRK.REPAIR_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }     
        }

        worker_list = TRS.get_list(in_node, "WORKER_LIST");

        for (int i = 0; i < worker_count; i++)
        {
            DBU_init_crasrprwrk(&CRASRPRWRK);
            TRS.copy(CRASRPRWRK.FACTORY, sizeof(CRASRPRWRK.FACTORY), in_node, IN_FACTORY);
            memcpy(CRASRPRWRK.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRWRK.REPAIR_ID));
            TRS.copy(CRASRPRWRK.WORKER_ID, sizeof(CRASRPRWRK.WORKER_ID), worker_list[i], "WORKER_ID");
            TRS.copy(CRASRPRWRK.WORKER_DESC, sizeof(CRASRPRWRK.WORKER_DESC), worker_list[i], "WORKER_DESC");
            TRS.copy(CRASRPRWRK.CREATE_USER_ID, sizeof(CRASRPRWRK.CREATE_USER_ID), in_node, IN_USERID);
            DB_get_systime(CRASRPRWRK.CREATE_TIME);

            DBU_insert_crasrprwrk(&CRASRPRWRK);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRWRK INSERT", MP_NVST);
                TRS.add_fieldmsg(out_node, "WORKER_ID", DT_STRING, sizeof(CRASRPRWRK.WORKER_ID), CRASRPRWRK.WORKER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
    }
    //설비 정보 삭제
    else if (TRS.get_procstep(in_node) == '3')
    {
        TRS.copy(CRASRPRSTS.FACTORY, sizeof(CRASRPRSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRSTS.REPAIR_ID), in_node, "REPAIR_ID");

        //설비 수리 스페어 리스트 삭제
        DBU_init_crasrprspr(&CRASRPRSPR);
        TRS.copy(CRASRPRSPR.FACTORY,sizeof(CRASRPRSPR.FACTORY), in_node, IN_FACTORY);
        memcpy(CRASRPRSPR.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRSPR.REPAIR_ID));

        DBU_delete_crasrprspr(2,&CRASRPRSPR);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRSPR DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "RPARE_ID", DT_STRING, sizeof(CRASRPRSPR.REPAIR_ID), CRASRPRSPR.REPAIR_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        //설비 수리 투입인원 리스트 삭제
        DBU_init_crasrprwrk(&CRASRPRWRK);
        TRS.copy(CRASRPRWRK.FACTORY, sizeof(CRASRPRWRK.FACTORY), in_node, IN_FACTORY);
        memcpy(CRASRPRWRK.REPAIR_ID, CRASRPRSTS.REPAIR_ID, sizeof(CRASRPRWRK.REPAIR_ID));
            
        DBU_delete_crasrprwrk(2, &CRASRPRWRK);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CRASRPRWRK DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "REPAIR_ID", DT_STRING, sizeof(CRASRPRWRK.REPAIR_ID), CRASRPRWRK.WORKER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
 
        //설비 수리 정보 삭제
        DBU_delete_crasrprsts(1, &CRASRPRSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CRASRPRSTS DELETE", MP_NVST);
            TRS.add_fieldmsg(out_node, "REPAIR_ID", DT_STRING, sizeof(CRASRPRSTS.REPAIR_ID), CRASRPRSTS.REPAIR_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Resouce_Repairinfo_Registration_Validation()
- Validation Check sub function of "CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Resouce_Repairinfo_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
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
