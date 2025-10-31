/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_update_lot_loss.c
Description : LOT LOSS 등록

MES Version : 5.0

Function List
- step 1: 불량등록 화면 lot loss처리
- step 2: 공정실적 loss정보 임시 테이블 저장
- step 3: 다중 불량등록 화면 다중 lot loss처리

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/28  Miracom        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Update_Lot_Loss_Validation(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTSX, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_UPDATE_LOT_LOSS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Update_Lot_Loss()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Lot_Loss(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_UPDATE_LOT_LOSS(s_msg_code, in_node, out_node);
    
    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Update_Lot_Loss", out_node);
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
CUS_WIP_UPDATE_LOT_LOSS()
- Main sub function of "CUS_WIP_Update_Lot_Loss" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_LOT_LOSS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* TABLE */
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	// LOT 마스터
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;	// LOT 마스터
    struct CWIPLOTLST_TAG CWIPLOTLST;	// LOT LOSS CODE 임시저장 테이블
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_AF;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    struct work_date_tag work_date;
    
    TRSNode *split_in;
    TRSNode *loss_in;
    TRSNode *loss_in_p;
    TRSNode *unit_in;
    TRSNode **in_code_tbl;
    TRSNode **Lot_tbl;
    TRSNode *cmn_out;
    TRSNode *res_wip;

    int i_lot_count = 0;
    int i = 0;
    double dSumqty = 0;
    char c_skip;

    // LOG
    LOG_head("CUS_WIP_Update_Lot_Loss");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    // VALIDATION CHECK
    if (CUS_WIP_Update_Lot_Loss_Validation(s_msg_code, &MWIPLOTSTSX, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MWIPLOTSTSX.FACTORY, &work_date);

    //step 1: 불량등록 화면 lot loss처리
    if (TRS.get_procstep(in_node) == '1')
    {       
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
        memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0010");
            TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        //창고에 있는 LOT은 LOSS처리 못하게 한다. _ ERP 실적 올릴때 문제 발생. 
        if (MWIPOPRDEF.INV_FLAG == 'Y')
        {
            //WIP-0675 : 창고 공정에서는 불량처리를 할 수 없습니다. 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0675");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
        CopyDefaultMembers(loss_in, in_node);
        TRS.add_char(loss_in, IN_PROCSTEP, '1');

        TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
        TRS.add_nstring(loss_in, "CAUSE_OPER", TRS.get_string(in_node, "CUASE_OPER"));

        if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
            TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
        else 
            TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

        TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_double(loss_in, "OUT_QTY_1", MWIPLOTSTSX.QTY_1 - TRS.get_double(in_node, "OUT_QTY_1"));
        TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

        in_code_tbl = TRS.get_list(in_node, "LOSS_TBL");

        for (i = 0; i < TRS.get_item_count(in_node, "LOSS_TBL"); i++)
        {
            if (TRS.mem_cmp(in_code_tbl[i], "CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)) == MP_FALSE)
            {
                //쿼리에서 split될 lot id 를 가져온다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

                split_in = TRS.add_node(in_node, "split_in");
                CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(split_in, "PROCSTEP", '1');
                TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(in_code_tbl[i], "VALUE"));
                TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "LOSS_COMMENT"));
                TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                //split된 lot을 조회한다. 
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

                //split 된 lot으로 불량 처리 한다. 
                loss_in_p = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in_p, in_node);
                TRS.add_char(loss_in_p, IN_PROCSTEP, '1');

                TRS.add_string(loss_in_p, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                TRS.add_string(loss_in_p, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_nstring(loss_in_p, "CAUSE_OPER", TRS.get_string(in_node, "CUASE_OPER"));

                if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
                    TRS.add_string(loss_in_p, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                else
                    TRS.add_nstring(loss_in_p, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

                TRS.add_nstring(loss_in_p, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_double(loss_in_p, "OUT_QTY_1", 0);
                TRS.add_string(loss_in_p, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                unit_in = TRS.add_node(loss_in_p, "UNIT1");
                TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(in_code_tbl[i], "CODE"));
                TRS.add_double(unit_in, "LOSS_QTY", TRS.get_double(in_code_tbl[i], "VALUE"));
                TRS.add_nstring(loss_in_p, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
                TRS.add_nstring(loss_in_p, "COMMENT", TRS.get_string(in_node, "COMMENT"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_p, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                if (TRS.get_item_count(in_node, "LOSS_TBL") == 1)
                    return MP_TRUE;
                else 
                    continue;
            }

            unit_in = TRS.add_node(loss_in, "UNIT1");
            TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(in_code_tbl[i], "CODE"));
            TRS.add_double(unit_in, "LOSS_QTY", TRS.get_double(in_code_tbl[i], "VALUE"));
        }

        TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
        TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

        if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
            return MP_FALSE;

        // 설비 효율용 집계
        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        {
            //LOT정보 재조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
            memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

            DBU_init_mwiplothisx(&MWIPLOTHIS);
            memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            MWIPLOTHIS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
            TRS.copy(MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS.OLD_OPER), in_node, "CUASE_OPER");
            memcpy(MWIPLOTHIS.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
            DBU_select_mwiplothisx(3, &MWIPLOTHIS);
            if(DB_error_code == DB_SUCCESS)
                MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ = MWIPLOTHIS.HIST_SEQ;
            else
                MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ = 0;

            res_wip = TRS.add_node(in_node, "LOT_TBL");
            TRS.add_nstring(res_wip, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
            TRS.add_double(res_wip, "LOSS_QTY_1", TRS.get_double(in_node, "OUT_QTY_1"));
            TRS.add_double(res_wip, "GOOD_QTY_1", MWIPLOTSTSX_AF.QTY_1);

            TRS.set_nstring(in_node, "TRAN_CODE", "LOSS");
            TRS.set_char(in_node, "IS_OUT_OF_OPER", 'Y');
            if (Call_Resource_Efficiency(s_msg_code, 0, &MWIPLOTSTSX, &MWIPLOTSTSX_AF, &work_date, in_node, out_node) == MP_FALSE)
                return MP_FALSE;
        }
    }
    //step 2: 공정실적 loss정보 임시 테이블 저장
    else if (TRS.get_procstep(in_node) == '2')
    {
        //불량정보 삭제.
        DBU_init_cwiplotlst(&CWIPLOTLST);
        memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
        memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
        memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
        //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;

        DBU_delete_cwiplotlst(2,&CWIPLOTLST);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPLOTLST DELETE(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }

        in_code_tbl = TRS.get_list(in_node, "LOSS_TBL");

        for (i = 0; i < TRS.get_item_count(in_node, "LOSS_TBL"); i++)
        {
            dSumqty = dSumqty + TRS.get_double(in_code_tbl[i], "VALUE");
            
            if (dSumqty > MWIPLOTSTSX.QTY_1)
            {
                //WIP-0605 : 불량수량이 lot의 수량을 넘을 수 없습니다. 불량 수량을 확인 하세요.
                strcpy(s_msg_code, "WIP-0605");
                return MP_FALSE;
            }

            DBU_init_cwiplotlst(&CWIPLOTLST);
            TRS.copy(CWIPLOTLST.FACTORY, sizeof(CWIPLOTLST.FACTORY), in_node, IN_FACTORY);
            memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));            
            CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
            CWIPLOTLST.QTY_FLAG = TRS.get_char(in_code_tbl[i], "QTY_FLAG");
            CWIPLOTLST.SEQ_NUM = (int)DBU_select_cwiplotlst_scalar(2, &CWIPLOTLST);
            memcpy(CWIPLOTLST.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPLOTLST.MAT_ID));
            CWIPLOTLST.MAT_VER = MWIPLOTSTSX.MAT_VER;            
            memcpy(CWIPLOTLST.FLOW, MWIPLOTSTSX.FLOW, sizeof(CWIPLOTLST.FLOW));
            memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
            TRS.copy(CWIPLOTLST.RES_ID, sizeof(CWIPLOTLST.RES_ID), in_node, "RES_ID");
            TRS.copy(CWIPLOTLST.LOSS_CODE, sizeof(CWIPLOTLST.LOSS_CODE), in_code_tbl[i], "CODE");
            CWIPLOTLST.LOSS_QTY = TRS.get_double(in_code_tbl[i], "VALUE");
            memcpy(CWIPLOTLST.TRAN_TIME, gs_sys_time, sizeof(CWIPLOTLST.TRAN_TIME));
            TRS.copy(CWIPLOTLST.CUASE_OPER, sizeof(CWIPLOTLST.CUASE_OPER), in_node, "CUASE_OPER");

            DBU_insert_cwiplotlst(&CWIPLOTLST);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPLOTLST INSERT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }
    //step 3: 다중 불량등록 화면 다중 lot loss처리
    else if (TRS.get_procstep(in_node) == '3')
    {
        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int j = 0; j < i_lot_count; j++)
        {
            c_skip = 'N';

            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[j], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
            {
                // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
                strcpy(s_msg_code, "WIP-0059");
                return MP_FALSE;
            }

            if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
            {
                // WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0076");
                return MP_FALSE;
            }

            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            //창고에 있는 LOT은 LOSS처리 못하게 한다. _ ERP 실적 올릴때 문제 발생. 
            if (MWIPOPRDEF.INV_FLAG == 'Y')
            {
                //WIP-0675 : 창고 공정에서는 불량처리를 할 수 없습니다. 공정을 확인하세요.
                strcpy(s_msg_code, "WIP-0675");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
            CopyDefaultMembers(loss_in, in_node);
            TRS.add_char(loss_in, IN_PROCSTEP, '1');

            TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_nstring(loss_in, "CAUSE_OPER", TRS.get_string(in_node, "CUASE_OPER"));

            if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
                TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
            else
                TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

            TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_double(loss_in, "OUT_QTY_1", MWIPLOTSTSX.QTY_1 - TRS.get_double(in_node, "OUT_QTY_1"));
            TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

            in_code_tbl = TRS.get_list(in_node, "LOSS_TBL");

            for (i = 0; i < TRS.get_item_count(in_node, "LOSS_TBL"); i++)
            {
                if (TRS.mem_cmp(in_code_tbl[i], "CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)) == MP_FALSE)
                {
                    //쿼리에서 split될 lot id 를 가져온다.
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                    memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);

                    split_in = TRS.add_node(in_node, "split_in");
                    CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                    TRS.add_char(split_in, "PROCSTEP", '1');
                    TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(in_code_tbl[i], "VALUE"));
                    TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "LOSS_COMMENT"));
                    TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    //split된 lot을 조회한다. 
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

                    //split 된 lot으로 불량 처리 한다. 
                    loss_in_p = TRS.add_node(in_node, "Wip_Lot_Loss");
                    CopyDefaultMembers(loss_in_p, in_node);
                    TRS.add_char(loss_in_p, IN_PROCSTEP, '1');

                    TRS.add_string(loss_in_p, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(loss_in_p, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                    TRS.add_nstring(loss_in_p, "CAUSE_OPER", TRS.get_string(in_node, "CUASE_OPER"));

                    if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
                        TRS.add_string(loss_in_p, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                    else
                        TRS.add_nstring(loss_in_p, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

                    TRS.add_nstring(loss_in_p, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_double(loss_in_p, "OUT_QTY_1", 0);
                    TRS.add_string(loss_in_p, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                    unit_in = TRS.add_node(loss_in_p, "UNIT1");
                    TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(in_code_tbl[i], "CODE"));
                    TRS.add_double(unit_in, "LOSS_QTY", TRS.get_double(in_code_tbl[i], "VALUE"));
                    TRS.add_nstring(loss_in_p, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
                    TRS.add_nstring(loss_in_p, "COMMENT", TRS.get_string(in_node, "COMMENT"));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in_p, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    if (TRS.get_item_count(in_node, "LOSS_TBL") == 1)
                    {
                        c_skip = 'Y';
                        break;
                    }
                    else
                        continue;
                }

                unit_in = TRS.add_node(loss_in, "UNIT1");
                TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(in_code_tbl[i], "CODE"));
                TRS.add_double(unit_in, "LOSS_QTY", TRS.get_double(in_code_tbl[i], "VALUE"));
            }

            if(c_skip == 'Y')
                continue;

            TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
            TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            // 설비 효율용 집계
            if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
            {
                //LOT정보 재조회
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
                memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

                DBU_init_mwiplothisx(&MWIPLOTHIS);
                memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                MWIPLOTHIS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                TRS.copy(MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS.OLD_OPER), in_node, "CUASE_OPER");
                memcpy(MWIPLOTHIS.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
                DBU_select_mwiplothisx(3, &MWIPLOTHIS);
                if (DB_error_code == DB_SUCCESS)
                    MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ = MWIPLOTHIS.HIST_SEQ;
                else
                    MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ = 0;

                TRS.add_double(Lot_tbl[j], "LOSS_QTY_1", TRS.get_double(in_node, "OUT_QTY_1"));
                TRS.add_double(Lot_tbl[j], "GOOD_QTY_1", MWIPLOTSTSX_AF.QTY_1);

                TRS.set_nstring(in_node, "TRAN_CODE", "LOSS");
                TRS.set_char(in_node, "IS_OUT_OF_OPER", 'Y');
                if (Call_Resource_Efficiency(s_msg_code, i, &MWIPLOTSTSX, &MWIPLOTSTSX_AF, &work_date, in_node, out_node) == MP_FALSE)
                    return MP_FALSE;
            }
        }
    }
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Update_Lot_Loss_Validation()
- Validation Check sub function of "CUS_WIP_UPDATE_LOT_LOSS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Lot_Loss_Validation(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTSX, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "123") == MP_FALSE)
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

    if (TRS.get_procstep(in_node) != '3')
    {

        // 1. LOT 조회
        DBU_init_mwiplotstsx(MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX->LOT_ID, sizeof(MWIPLOTSTSX->LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, MWIPLOTSTSX);

        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004");		// CMN-0004 : Database에는 조건의 데이터가 존재하지 않습니다.
            }
            else
            {
                strcpy(s_msg_code, "WIP-0004");		// WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            }

            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "[UPDATE_LOSS_LOT] MWIPLOTSTSX_SELECT(1)", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX->LOT_ID), MWIPLOTSTSX->LOT_ID);

            return MP_FALSE;
        }

        if (MWIPLOTSTSX->HOLD_FLAG == 'Y')
        {
            // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
            strcpy(s_msg_code, "WIP-0059");
            return MP_FALSE;
        }

        if (MWIPLOTSTSX->LOT_DEL_FLAG == 'Y')
        {
            // WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0076");
            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
