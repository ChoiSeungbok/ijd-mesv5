/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_WIP_update_lot_comment.c
    Description : Lot Comment 수정.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/25  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"

int CUS_WIP_UPDATE_LOT_COMMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_WIP_Update_Lot_Comment()
        - Lot Comment 수정.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Lot_Comment(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_LOT_COMMENT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Update_Lot_Comment", out_node);

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
    CUS_WIP_UPDATE_LOT_COMMENT()
        - Main sub function of "CUS_WIP_Update_Lot_Comment" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_LOT_COMMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTHIS_TAG MINVLOTHIS;

    struct CWIPLOTRMK_TAG CWIPLOTRMK;

    LOG_head("CUS_WIP_UPDATE_LOT_COMMENT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);
    char s_sys_time[14];


    memset(s_sys_time, ' ', sizeof(s_sys_time));
    DB_get_systime(s_sys_time);

    if (TRS.get_procstep(in_node) == '1')
    {

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            TRS.copy(MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LAST_COMMENT), in_node, "LOT_DESC");

            DBU_update_mwiplotstsx(1, &MWIPLOTSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

                return MP_FALSE;
            }


            DBU_init_mwiplothisx(&MWIPLOTHIS);
            memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            DBU_select_mwiplothisx(1, &MWIPLOTHIS);

            memcpy(MWIPLOTHIS.TRAN_COMMENT, MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LOT_DESC));

            DBU_update_mwiplothisx(1, &MWIPLOTHIS);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MWIPLOTHIS UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTHIS.HIST_SEQ);

                return MP_FALSE;
            }

        }
        else if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_init_minvlotsts(&MINVLOTSTS);
            TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
            DBU_select_minvlotsts(1, &MINVLOTSTS);

            TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "LOT_DESC");

            DBU_update_minvlotsts(1, &MINVLOTSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);
                TRS.add_fieldmsg(out_node, "minvlotsts UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

                return MP_FALSE;
            }


            DBU_init_minvlothis(&MINVLOTHIS);
            TRS.copy(MINVLOTHIS.FACTORY, sizeof(MINVLOTHIS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MINVLOTHIS.INV_LOT_ID, sizeof(MINVLOTHIS.INV_LOT_ID), in_node, "LOT_ID");
            MINVLOTHIS.HIST_SEQ = MINVLOTSTS.LAST_HIST_SEQ;

            DBU_select_minvlothis(1, &MINVLOTHIS);

            TRS.copy(MINVLOTHIS.TRAN_COMMENT, sizeof(MINVLOTHIS.TRAN_COMMENT), in_node, "LOT_DESC");
            DBU_update_minvlothis(1, &MINVLOTHIS);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MINVLOTHIS UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHIS.INV_LOT_ID), MINVLOTHIS.INV_LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTHIS.HIST_SEQ);

                return MP_FALSE;
            }
        }
    }
    else if (TRS.get_procstep(in_node) == '2') {
        DBU_init_cwiplotrmk(&CWIPLOTRMK);
        TRS.copy(CWIPLOTRMK.LOT_ID, sizeof(CWIPLOTRMK.LOT_ID), in_node, "LOT_ID");
        DBU_select_cwiplotrmk(1, &CWIPLOTRMK);
        if (DB_error_code == DB_SUCCESS)
        {
            TRS.copy(CWIPLOTRMK.FACTORY, sizeof(CWIPLOTRMK.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPLOTRMK.LOT_ID, sizeof(CWIPLOTRMK.LOT_ID), in_node, "LOT_ID");
            TRS.copy(CWIPLOTRMK.COMMENT_1, sizeof(CWIPLOTRMK.COMMENT_1), in_node, "COMMENT_1");
            TRS.copy(CWIPLOTRMK.COMMENT_1, sizeof(CWIPLOTRMK.COMMENT_1), in_node, "COMMENT_1");
            TRS.copy(CWIPLOTRMK.COMMENT_2, sizeof(CWIPLOTRMK.COMMENT_2), in_node, "COMMENT_2");
            TRS.copy(CWIPLOTRMK.COMMENT_3, sizeof(CWIPLOTRMK.COMMENT_3), in_node, "COMMENT_3");
            TRS.copy(CWIPLOTRMK.COMMENT_4, sizeof(CWIPLOTRMK.COMMENT_4), in_node, "COMMENT_4");
            TRS.copy(CWIPLOTRMK.COMMENT_5, sizeof(CWIPLOTRMK.COMMENT_5), in_node, "COMMENT_5");
            TRS.copy(CWIPLOTRMK.COMMENT_6, sizeof(CWIPLOTRMK.COMMENT_6), in_node, "COMMENT_6");
            TRS.copy(CWIPLOTRMK.COMMENT_7, sizeof(CWIPLOTRMK.COMMENT_7), in_node, "COMMENT_7");
            TRS.copy(CWIPLOTRMK.COMMENT_8, sizeof(CWIPLOTRMK.COMMENT_8), in_node, "COMMENT_8");
            TRS.copy(CWIPLOTRMK.COMMENT_9, sizeof(CWIPLOTRMK.COMMENT_9), in_node, "COMMENT_9");
            TRS.copy(CWIPLOTRMK.COMMENT_10, sizeof(CWIPLOTRMK.COMMENT_10), in_node, "COMMENT_10");

            TRS.copy(CWIPLOTRMK.UPDATE_USER_ID, sizeof(CWIPLOTRMK.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTRMK.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
            DBU_update_cwiplotrmk(1, &CWIPLOTRMK);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "CWIPLOTRMK UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTRMK.LOT_ID), CWIPLOTRMK.LOT_ID);

                return MP_FALSE;
            }

        }
        else {
            TRS.copy(CWIPLOTRMK.FACTORY, sizeof(CWIPLOTRMK.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPLOTRMK.LOT_ID, sizeof(CWIPLOTRMK.LOT_ID), in_node, "LOT_ID");
            TRS.copy(CWIPLOTRMK.COMMENT_1, sizeof(CWIPLOTRMK.COMMENT_1), in_node, "COMMENT_1");
            TRS.copy(CWIPLOTRMK.COMMENT_2, sizeof(CWIPLOTRMK.COMMENT_2), in_node, "COMMENT_2");
            TRS.copy(CWIPLOTRMK.COMMENT_3, sizeof(CWIPLOTRMK.COMMENT_3), in_node, "COMMENT_3");
            TRS.copy(CWIPLOTRMK.COMMENT_4, sizeof(CWIPLOTRMK.COMMENT_4), in_node, "COMMENT_4");
            TRS.copy(CWIPLOTRMK.COMMENT_5, sizeof(CWIPLOTRMK.COMMENT_5), in_node, "COMMENT_5");
            TRS.copy(CWIPLOTRMK.COMMENT_6, sizeof(CWIPLOTRMK.COMMENT_6), in_node, "COMMENT_6");
            TRS.copy(CWIPLOTRMK.COMMENT_7, sizeof(CWIPLOTRMK.COMMENT_7), in_node, "COMMENT_7");
            TRS.copy(CWIPLOTRMK.COMMENT_8, sizeof(CWIPLOTRMK.COMMENT_8), in_node, "COMMENT_8");
            TRS.copy(CWIPLOTRMK.COMMENT_9, sizeof(CWIPLOTRMK.COMMENT_9), in_node, "COMMENT_9");
            TRS.copy(CWIPLOTRMK.COMMENT_10, sizeof(CWIPLOTRMK.COMMENT_10), in_node, "COMMENT_10");

            TRS.copy(CWIPLOTRMK.CREATE_USER_ID, sizeof(CWIPLOTRMK.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTRMK.CREATE_TIME, s_sys_time, sizeof(s_sys_time));


            DBU_insert_cwiplotrmk( &CWIPLOTRMK);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0003");;
                TRS.add_fieldmsg(out_node, "CWIPLOTRMK INSERT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTRMK.FACTORY), CWIPLOTRMK.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTRMK.LOT_ID), CWIPLOTRMK.LOT_ID);
                TRS.add_fieldmsg(out_node, "COMMENT_1", MP_STR, sizeof(CWIPLOTRMK.COMMENT_1), CWIPLOTRMK.COMMENT_1);
                TRS.add_fieldmsg(out_node, "COMMENT_2", MP_STR, sizeof(CWIPLOTRMK.COMMENT_2), CWIPLOTRMK.COMMENT_2);
                TRS.add_fieldmsg(out_node, "COMMENT_3", MP_STR, sizeof(CWIPLOTRMK.COMMENT_3), CWIPLOTRMK.COMMENT_3);
                TRS.add_fieldmsg(out_node, "COMMENT_4", MP_STR, sizeof(CWIPLOTRMK.COMMENT_4), CWIPLOTRMK.COMMENT_4);
                TRS.add_fieldmsg(out_node, "COMMENT_5", MP_STR, sizeof(CWIPLOTRMK.COMMENT_5), CWIPLOTRMK.COMMENT_5);
                TRS.add_fieldmsg(out_node, "COMMENT_6", MP_STR, sizeof(CWIPLOTRMK.COMMENT_6), CWIPLOTRMK.COMMENT_6);
                TRS.add_fieldmsg(out_node, "COMMENT_7", MP_STR, sizeof(CWIPLOTRMK.COMMENT_7), CWIPLOTRMK.COMMENT_7);
                TRS.add_fieldmsg(out_node, "COMMENT_8", MP_STR, sizeof(CWIPLOTRMK.COMMENT_8), CWIPLOTRMK.COMMENT_8);
                TRS.add_fieldmsg(out_node, "COMMENT_9", MP_STR, sizeof(CWIPLOTRMK.COMMENT_9), CWIPLOTRMK.COMMENT_9);
                TRS.add_fieldmsg(out_node, "COMMENT_10", MP_STR, sizeof(CWIPLOTRMK.COMMENT_10), CWIPLOTRMK.COMMENT_10);

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
