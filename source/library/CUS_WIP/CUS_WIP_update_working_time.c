/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_WIP_update_working_time.c
Description : 작업자 투입시간 등록.

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/12/          Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_WIP_UPDATE_WORKING_TIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_UPDATE_WORKING_TIME_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
/*******************************************************************************
CUS_WIP_Update_Working_Time()
- 생산성, 수율 목표 등록
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Working_Time(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_WORKING_TIME(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Update_Working_Time", out_node);

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
CUS_WIP_UPDATE_WORKING_TIME()
- Main sub function of "CUS_WIP_Update_Working_Time" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_WORKING_TIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CWIPWRKINP_TAG CWIPWRKINP;

    int i = 0;

    LOG_head("CUS_WIP_UPDATE_WORKING_TIME");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    //신규/갱신
    if (TRS.get_procstep(in_node) == '1')
    {
        if (CUS_WIP_UPDATE_WORKING_TIME_VALIDATION(s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwipwrkinp(&CWIPWRKINP);
            CWIPWRKINP.WORK_SEQ = TRS.get_int(in_node->SItems[i], "WORK_SEQ");
            DBU_select_cwipwrkinp(1, &CWIPWRKINP);

            TRS.copy(CWIPWRKINP.FACTORY, sizeof(CWIPWRKINP.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPWRKINP.WORK_DATE, sizeof(CWIPWRKINP.WORK_DATE), in_node->SItems[i], "WORK_DATE");
            TRS.copy(CWIPWRKINP.USER_ID, sizeof(CWIPWRKINP.USER_ID), in_node->SItems[i], "USER_ID");
            TRS.copy(CWIPWRKINP.USER_DESC, sizeof(CWIPWRKINP.USER_DESC), in_node->SItems[i], "USER_DESC");
            TRS.copy(CWIPWRKINP.AREA_ID, sizeof(CWIPWRKINP.AREA_ID), in_node->SItems[i], "AREA_ID");
            TRS.copy(CWIPWRKINP.OPER, sizeof(CWIPWRKINP.OPER), in_node->SItems[i], "OPER");
            TRS.copy(CWIPWRKINP.OPER_DESC, sizeof(CWIPWRKINP.OPER_DESC), in_node->SItems[i], "OPER_DESC");
            TRS.copy(CWIPWRKINP.START_DT, sizeof(CWIPWRKINP.START_DT), in_node->SItems[i], "START_DT");
            TRS.copy(CWIPWRKINP.START_TIME, sizeof(CWIPWRKINP.START_TIME), in_node->SItems[i], "START_TIME");
            TRS.copy(CWIPWRKINP.END_DT, sizeof(CWIPWRKINP.END_DT), in_node->SItems[i], "END_DT");
            TRS.copy(CWIPWRKINP.END_TIME, sizeof(CWIPWRKINP.END_TIME), in_node->SItems[i], "END_TIME");

            CWIPWRKINP.TOTAL_WORK_TIME = TRS.get_double(in_node->SItems[i], "TOTAL_WORK_TIME");
            CWIPWRKINP.TOTAL_CONV_TIME = TRS.get_double(in_node->SItems[i], "TOTAL_CONV_TIME");
            CWIPWRKINP.BREAK_TIME = TRS.get_double(in_node->SItems[i], "BREAK_TIME");
                        
            CWIPWRKINP.WEK_01_ST_TIME = TRS.get_double(in_node->SItems[i], "WEK_01_ST_TIME");
            CWIPWRKINP.WEK_01_OV_TIME = TRS.get_double(in_node->SItems[i], "WEK_01_OV_TIME");
            CWIPWRKINP.WEK_02_ST_TIME = TRS.get_double(in_node->SItems[i], "WEK_02_ST_TIME");
            CWIPWRKINP.WEK_02_OV_TIME = TRS.get_double(in_node->SItems[i], "WEK_02_OV_TIME");
            CWIPWRKINP.HOL_01_ST_TIME = TRS.get_double(in_node->SItems[i], "HOL_01_ST_TIME");
            CWIPWRKINP.HOL_01_OV_TIME = TRS.get_double(in_node->SItems[i], "HOL_01_OV_TIME");
            CWIPWRKINP.HOL_02_ST_TIME = TRS.get_double(in_node->SItems[i], "HOL_02_ST_TIME");
            CWIPWRKINP.HOL_02_OV_TIME = TRS.get_double(in_node->SItems[i], "HOL_02_OV_TIME");
                       
            TRS.copy(CWIPWRKINP.CMF_1, sizeof(CWIPWRKINP.CMF_1), in_node->SItems[i], "CMF_1");
            TRS.copy(CWIPWRKINP.CMF_2, sizeof(CWIPWRKINP.CMF_2), in_node->SItems[i], "CMF_2");
            TRS.copy(CWIPWRKINP.CMF_3, sizeof(CWIPWRKINP.CMF_3), in_node->SItems[i], "CMF_3");
            TRS.copy(CWIPWRKINP.CMF_4, sizeof(CWIPWRKINP.CMF_4), in_node->SItems[i], "CMF_4");
            TRS.copy(CWIPWRKINP.CMF_5, sizeof(CWIPWRKINP.CMF_5), in_node->SItems[i], "CMF_5");
            TRS.copy(CWIPWRKINP.CMF_6, sizeof(CWIPWRKINP.CMF_6), in_node->SItems[i], "CMF_6");
            TRS.copy(CWIPWRKINP.CMF_7, sizeof(CWIPWRKINP.CMF_7), in_node->SItems[i], "CMF_7");
            TRS.copy(CWIPWRKINP.CMF_8, sizeof(CWIPWRKINP.CMF_8), in_node->SItems[i], "CMF_8");
            TRS.copy(CWIPWRKINP.CMF_9, sizeof(CWIPWRKINP.CMF_9), in_node->SItems[i], "CMF_9");
            TRS.copy(CWIPWRKINP.CMF_10, sizeof(CWIPWRKINP.CMF_10), in_node->SItems[i], "CMF_10");
            TRS.copy(CWIPWRKINP.REMARKS, sizeof(CWIPWRKINP.REMARKS), in_node->SItems[i], "REMARKS");
                       
            if (DB_error_code == DB_NOT_FOUND)
            {
                CWIPWRKINP.WORK_SEQ =(int)DBU_select_cwipwrkinp_scalar(2, &CWIPWRKINP);

                TRS.copy(CWIPWRKINP.CREATE_USER_ID, sizeof(CWIPWRKINP.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPWRKINP.CREATE_TIME, gs_sys_time, sizeof(CWIPWRKINP.CREATE_TIME));

                DBU_insert_cwipwrkinp(&CWIPWRKINP);
                if (DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CWIPWRKINP Insert", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "WORK_SEQ", DT_INT, CWIPWRKINP.WORK_SEQ);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPWRKINP.FACTORY), CWIPWRKINP.FACTORY);
                    TRS.add_fieldmsg(out_node, "USER_ID", DT_STRING, sizeof(CWIPWRKINP.USER_ID), CWIPWRKINP.USER_ID);

                    return MP_FALSE;
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                TRS.copy(CWIPWRKINP.UPDATE_USER_ID, sizeof(CWIPWRKINP.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPWRKINP.UPDATE_TIME, gs_sys_time, sizeof(CWIPWRKINP.UPDATE_TIME));

                DBU_update_cwipwrkinp(1, &CWIPWRKINP);
                if (DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CWIPWRKINP Update 1", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "WORK_SEQ", DT_INT, CWIPWRKINP.WORK_SEQ);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPWRKINP.FACTORY), CWIPWRKINP.FACTORY);
                    TRS.add_fieldmsg(out_node, "USER_ID", DT_STRING, sizeof(CWIPWRKINP.USER_ID), CWIPWRKINP.USER_ID);

                    return MP_FALSE;
                }
            }
        }
    }
    //삭제
    else if (TRS.get_procstep(in_node) == '2')
    {
        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwipwrkinp(&CWIPWRKINP);
            CWIPWRKINP.WORK_SEQ = TRS.get_int(in_node->SItems[i], "WORK_SEQ");            
            DBU_delete_cwipwrkinp(1, &CWIPWRKINP);

            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CWIPWRKINP Delete 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "WORK_SEQ", DT_INT, CWIPWRKINP.WORK_SEQ);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPWRKINP.FACTORY), CWIPWRKINP.FACTORY);
                TRS.add_fieldmsg(out_node, "USER_ID", DT_STRING, sizeof(CWIPWRKINP.USER_ID), CWIPWRKINP.USER_ID);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_UPDATE_WORKING_TIME_VALIDATION()
- Main sub function of "CUS_WIP_UPDATE_WORKING_TIME" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_WORKING_TIME_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{  
        
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1|2") == MP_FALSE)
    {
        return MP_FALSE;
    }
   
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);
        return MP_FALSE;
    }

    int i = 0;
    for (i = 0; i < in_node->SCount; i++)
    {
       
        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "WORK_DATE")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "WORK_DATE", MP_NVST);

            return MP_FALSE;
        }
        
        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "USER_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "USER_ID", MP_NVST);

            return MP_FALSE;
        }

        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "USER_DESC")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "USER_DESC", MP_NVST);

            return MP_FALSE;
        }
        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "AREA_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

            return MP_FALSE;
        }
        /*
       if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "OPER")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

            return MP_FALSE;
        }*/
    }

    return MP_TRUE;
}
