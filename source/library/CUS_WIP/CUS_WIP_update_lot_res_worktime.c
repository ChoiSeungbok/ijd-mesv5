/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_WIP_update_lot_res_worktime.c
Description : Lot Resource Work Time 수정.

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/08/12  WG.LEE        Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"

int CUS_WIP_Update_Lot_Res_Worktime_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_UPDATE_LOT_RES_WORKTIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Update_Lot_Res_Worktime()
- Lot Comment 수정.
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Lot_Res_Worktime(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_LOT_RES_WORKTIME(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Update_Lot_Res_Worktime", out_node);

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
CUS_WIP_UPDATE_LOT_RES_WORKTIME()
- Main sub function of "CUS_WIP_Update_Lot_Res_Worktime" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_LOT_RES_WORKTIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;

    TRSNode **Lot_tbl;
    int i_lot_count = 0;

    LOG_head("CUS_WIP_UPDATE_LOT_RES_WORKTIME");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    // VALIDATION CHECK
    if (CUS_WIP_Update_Lot_Res_Worktime_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int i = 0; i < i_lot_count; i++)
        {
            DBU_init_mwiplotstsx(&MWIPLOTSTS);
            TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), Lot_tbl[i], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
            if (DB_error_code == DB_SUCCESS)
            {
                TRS.copy(MWIPLOTSTS.LOT_CMF_17, sizeof(MWIPLOTSTS.LOT_CMF_17), in_node, "START_TIME");
                TRS.copy(MWIPLOTSTS.LOT_CMF_18, sizeof(MWIPLOTSTS.LOT_CMF_18), in_node, "END_TIME");

                DBU_update_mwiplotstsx(1, &MWIPLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTS UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTS.OPER), MWIPLOTSTS.OPER);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "START_TIME", MP_STR, sizeof(MWIPLOTSTS.LOT_CMF_17), MWIPLOTSTS.LOT_CMF_17);
                    TRS.add_fieldmsg(out_node, "END_TIME", MP_STR, sizeof(MWIPLOTSTS.LOT_CMF_18), MWIPLOTSTS.LOT_CMF_18);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }

                DBU_init_mwiplothisx(&MWIPLOTHIS);
                memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
                //MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                //DBU_select_mwiplothisx(1, &MWIPLOTHIS);
                TRS.copy(MWIPLOTHIS.START_RES_ID, sizeof(MWIPLOTHIS.START_RES_ID), in_node, "RES_ID");                                
                memcpy(MWIPLOTHIS.LOT_CMF_17, MWIPLOTSTS.LOT_CMF_17, sizeof(MWIPLOTSTS.LOT_CMF_17));
                memcpy(MWIPLOTHIS.LOT_CMF_18, MWIPLOTSTS.LOT_CMF_18, sizeof(MWIPLOTSTS.LOT_CMF_18));

                DBU_update_mwiplothisx(3, &MWIPLOTHIS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MWIPLOTHIS UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHIS.FACTORY), MWIPLOTHIS.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTHIS.OPER), MWIPLOTHIS.OPER);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "START_TIME", MP_STR, sizeof(MWIPLOTHIS.LOT_CMF_17), MWIPLOTHIS.LOT_CMF_17);
                    TRS.add_fieldmsg(out_node, "END_TIME", MP_STR, sizeof(MWIPLOTHIS.LOT_CMF_18), MWIPLOTHIS.LOT_CMF_18);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
        }
    }

    return MP_TRUE;
}


/*******************************************************************************
CUS_WIP_Update_Lot_Res_Worktime_Validation()
- Validation Check sub function of "CUS_WIP_UPDATE_LOT_RES_WORKTIME" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Lot_Res_Worktime_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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

    return MP_TRUE;
}

