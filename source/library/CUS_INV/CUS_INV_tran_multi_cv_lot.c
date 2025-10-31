/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_INV_tran_multi_cv_lot.c
Description : 자재 cv처리

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/12/31  이우길        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_INV_TRAN_MULTI_CV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_Tran_Multi_Cv_Lot()
- Lagacy System의 재고, 재공을 MES으로 재고, 재공을 생성한다.
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Tran_Multi_Cv_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_TRAN_MULTI_CV_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_INV_Tran_Multi_Cv_Lot", out_node);

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
CUS_INV_TRAN_MULTI_CV_LOT()
- Main sub function of "CUS_INV_Tran_Multi_Cv_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_TRAN_MULTI_CV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MINVLOTSTS_TAG MINVLOTSTS;
    //struct MINVLOTHIS_TAG MINVLOTHIS;
  
    TRSNode *inv_list;
    TRSNode *cv_in;
    TRSNode *cmn_out;

    LOG_head("CUS_INV_TRAN_MULTI_CV_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);


    if (TRS.get_procstep(in_node) == '1')
    {
        //자재lot인 경우 다시 수량을 살려준다.
        DBU_init_minvlotsts(&MINVLOTSTS);
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "INV_LOT_ID");
        DBU_select_minvlotsts(1, &MINVLOTSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            if (MINVLOTSTS.DELETE_FLAG == 'Y')
            {
                MINVLOTSTS.DELETE_FLAG = ' ';
                memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
                memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
                memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
                DBU_update_minvlotsts(1, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            //DBU_init_minvlothis(&MINVLOTHIS);
            //memcpy(MINVLOTHIS.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
            //memcpy(MINVLOTHIS.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
            //MINVLOTHIS.HIST_SEQ = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
            //DBU_select_minvlothis(1, &MINVLOTHIS);

            cv_in = TRS.add_node(in_node, "cv_in");
            TRS.add_char(cv_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(cv_in, in_node);

            inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
            TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
            TRS.add_double(inv_list, "CHANGE_QTY", TRS.get_double(in_node, "QTY_1"));
            TRS.add_string(inv_list, "TRAN_COMMENT", "CHANGE_QTY", strlen("CHANGE_QTY"));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
        else
        {
            return MP_FALSE;
        }
    }
   
    return MP_TRUE;
}
