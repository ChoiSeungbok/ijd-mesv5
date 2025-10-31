/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_WIP_update_productivity_goal.c
    Description : 생산성, 수율 목표 등록.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/11/20  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_WIP_UPDATE_PRODUCTIVITY_GOAL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_UPDATE_PRODUCTIVITY_GOAL_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
/*******************************************************************************
    CUS_WIP_Update_Productivity_Goal()
        - 생산성, 수율 목표 등록
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Productivity_Goal(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_PRODUCTIVITY_GOAL(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Update_Productivity_Goal", out_node);

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
    CUS_WIP_UPDATE_PRODUCTIVITY_GOAL()
        - Main sub function of "CUS_WIP_Update_Productivity_Goal" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_PRODUCTIVITY_GOAL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CWIPPRDGOL_TAG CWIPPRDGOL;

    int i = 0;

    LOG_head("CUS_WIP_UPDATE_PRODUCTIVITY_GOAL");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (TRS.get_procstep(in_node) == '1')
    {
        if(CUS_WIP_UPDATE_PRODUCTIVITY_GOAL_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwipprdgol(&CWIPPRDGOL);
            TRS.copy(CWIPPRDGOL.FACTORY, sizeof(CWIPPRDGOL.FACTORY), in_node, IN_FACTORY);
            CWIPPRDGOL.KIND = TRS.get_char(in_node->SItems[i], "KIND");
            TRS.copy(CWIPPRDGOL.AREA_ID, sizeof(CWIPPRDGOL.AREA_ID), in_node->SItems[i], "AREA_ID");
            TRS.copy(CWIPPRDGOL.SHOP, sizeof(CWIPPRDGOL.SHOP), in_node->SItems[i], "SHOP");
            TRS.copy(CWIPPRDGOL.OPER_GRP, sizeof(CWIPPRDGOL.OPER_GRP), in_node->SItems[i], "OPER_GRP");
            TRS.copy(CWIPPRDGOL.CLASS, sizeof(CWIPPRDGOL.CLASS), in_node->SItems[i], "CLASS");
            TRS.copy(CWIPPRDGOL.WORK_MONTH, sizeof(CWIPPRDGOL.WORK_MONTH), in_node->SItems[i], "WORK_MONTH");
            TRS.copy(CWIPPRDGOL.WEEK_OF_MONTH, sizeof(CWIPPRDGOL.WEEK_OF_MONTH), in_node->SItems[i], "WEEK_OF_MONTH");           
            DBU_select_cwipprdgol(1, &CWIPPRDGOL);
            CWIPPRDGOL.GOAL_YIELD = TRS.get_double(in_node->SItems[i], "GOAL_YIELD");
            CWIPPRDGOL.GOAL_PRODUCTVITY = TRS.get_double(in_node->SItems[i], "GOAL_PRODUCTVITY");

            if (DB_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CWIPPRDGOL.CREATE_USER_ID, sizeof(CWIPPRDGOL.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPPRDGOL.CREATE_TIME, gs_sys_time, sizeof(CWIPPRDGOL.CREATE_TIME));

                DBU_insert_cwipprdgol(&CWIPPRDGOL);
                if(DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CWIPPRDGOL Insert", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "SEQ", DT_INT, i);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPPRDGOL.FACTORY), CWIPPRDGOL.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPPRDGOL.AREA_ID), CWIPPRDGOL.AREA_ID);
                    TRS.add_fieldmsg(out_node, "SHOP", DT_STRING, sizeof(CWIPPRDGOL.SHOP), CWIPPRDGOL.SHOP);
                    TRS.add_fieldmsg(out_node, "OPER_GRP", DT_STRING, sizeof(CWIPPRDGOL.OPER_GRP), CWIPPRDGOL.OPER_GRP);
                    TRS.add_fieldmsg(out_node, "CLASS", DT_STRING, sizeof(CWIPPRDGOL.CLASS), CWIPPRDGOL.CLASS);
                    TRS.add_fieldmsg(out_node, "WORK_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WORK_MONTH), CWIPPRDGOL.WORK_MONTH);
                    TRS.add_fieldmsg(out_node, "WEEK_OF_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WEEK_OF_MONTH), CWIPPRDGOL.WEEK_OF_MONTH);
                
                    return MP_FALSE;
                }
            }
            else if(DB_error_code == DB_SUCCESS)
            {
                TRS.copy(CWIPPRDGOL.UPDATE_USER_ID, sizeof(CWIPPRDGOL.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPPRDGOL.UPDATE_TIME, gs_sys_time, sizeof(CWIPPRDGOL.UPDATE_TIME));
            
                DBU_update_cwipprdgol(1, &CWIPPRDGOL);
                if (DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CWIPPRDGOL Update 1", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "SEQ", DT_INT, i);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPPRDGOL.FACTORY), CWIPPRDGOL.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPPRDGOL.AREA_ID), CWIPPRDGOL.AREA_ID);
                    TRS.add_fieldmsg(out_node, "SHOP", DT_STRING, sizeof(CWIPPRDGOL.SHOP), CWIPPRDGOL.SHOP);
                    TRS.add_fieldmsg(out_node, "OPER_GRP", DT_STRING, sizeof(CWIPPRDGOL.OPER_GRP), CWIPPRDGOL.OPER_GRP);
                    TRS.add_fieldmsg(out_node, "CLASS", DT_STRING, sizeof(CWIPPRDGOL.CLASS), CWIPPRDGOL.CLASS);
                    TRS.add_fieldmsg(out_node, "WORK_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WORK_MONTH), CWIPPRDGOL.WORK_MONTH);
                    TRS.add_fieldmsg(out_node, "WEEK_OF_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WEEK_OF_MONTH), CWIPPRDGOL.WEEK_OF_MONTH);

                    return MP_FALSE;
                }
            }
        }
    }
    else if(TRS.get_procstep(in_node) == '2')
    {
        for(i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwipprdgol(&CWIPPRDGOL);
            TRS.copy(CWIPPRDGOL.FACTORY, sizeof(CWIPPRDGOL.FACTORY), in_node, IN_FACTORY);
            CWIPPRDGOL.KIND = TRS.get_char(in_node->SItems[i], "KIND");
            TRS.copy(CWIPPRDGOL.AREA_ID, sizeof(CWIPPRDGOL.AREA_ID), in_node->SItems[i], "AREA_ID");
            TRS.copy(CWIPPRDGOL.SHOP, sizeof(CWIPPRDGOL.SHOP), in_node->SItems[i], "SHOP");
            TRS.copy(CWIPPRDGOL.OPER_GRP, sizeof(CWIPPRDGOL.OPER_GRP), in_node->SItems[i], "OPER_GRP");
            TRS.copy(CWIPPRDGOL.CLASS, sizeof(CWIPPRDGOL.CLASS), in_node->SItems[i], "CLASS");
            TRS.copy(CWIPPRDGOL.WORK_MONTH, sizeof(CWIPPRDGOL.WORK_MONTH), in_node->SItems[i], "WORK_MONTH");
            TRS.copy(CWIPPRDGOL.WEEK_OF_MONTH, sizeof(CWIPPRDGOL.WEEK_OF_MONTH), in_node->SItems[i], "WEEK_OF_MONTH");
            DBU_delete_cwipprdgol(1, &CWIPPRDGOL);
            if(DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CWIPPRDGOL Delete 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "SEQ", DT_INT, i);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPPRDGOL.FACTORY), CWIPPRDGOL.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPPRDGOL.AREA_ID), CWIPPRDGOL.AREA_ID);
                TRS.add_fieldmsg(out_node, "SHOP", DT_STRING, sizeof(CWIPPRDGOL.SHOP), CWIPPRDGOL.SHOP);
                TRS.add_fieldmsg(out_node, "OPER_GRP", DT_STRING, sizeof(CWIPPRDGOL.OPER_GRP), CWIPPRDGOL.OPER_GRP);
                TRS.add_fieldmsg(out_node, "CLASS", DT_STRING, sizeof(CWIPPRDGOL.CLASS), CWIPPRDGOL.CLASS);
                TRS.add_fieldmsg(out_node, "WORK_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WORK_MONTH), CWIPPRDGOL.WORK_MONTH);
                TRS.add_fieldmsg(out_node, "WEEK_OF_MONTH", DT_STRING, sizeof(CWIPPRDGOL.WEEK_OF_MONTH), CWIPPRDGOL.WEEK_OF_MONTH);
            
                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
    CUS_WIP_UPDATE_PRODUCTIVITY_GOAL_Validation()
        - Main sub function of "CUS_WIP_UPDATE_PRODUCTIVITY_GOAL" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_PRODUCTIVITY_GOAL_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MGCMTBLDAT_TAG MGCMTBLDAT;

    int i = 0;


    for(i = 0; i < in_node->SCount; i++)
    {
        if (TRS.get_char(in_node->SItems[0], "KIND") == 'P')
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
            memcpy(MGCMTBLDAT.TABLE_NAME, "C_PROD_PROD", strlen("C_PROD_PROD"));
            TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node->SItems[i], "AREA_ID");
            TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), in_node->SItems[i], "SHOP");
            TRS.copy(MGCMTBLDAT.KEY_3, sizeof(MGCMTBLDAT.KEY_3), in_node->SItems[i], "OPER_GRP");

            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                    // GCM-1001 : 생산성 기준정보를 잘못 입력했습니다. 생산성 기준정보를 확인하세요.(C_PROD_PROD)
                    strcpy(s_msg_code, "GCM-1001");
                else
                {
                    strcpy(s_msg_code, "GCM-0002");
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                }

                TRS.add_fieldmsg(out_node, "MGCMTBLDAT 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                TRS.add_fieldmsg(out_node, "KEY_1", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
                TRS.add_fieldmsg(out_node, "KEY_2", DT_STRING, sizeof(MGCMTBLDAT.KEY_2), MGCMTBLDAT.KEY_2);
                TRS.add_fieldmsg(out_node, "KEY_3", DT_STRING, sizeof(MGCMTBLDAT.KEY_3), MGCMTBLDAT.KEY_3);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}
