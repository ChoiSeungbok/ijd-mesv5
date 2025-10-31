/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_blending_order.c
Description : Blending order - lot id mapping function

MES Version : 5.0

Function List
- step 1: 블랜딩 작업지시에 lot id 투입


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/17  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Blending_Order_Bom_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_BLENDING_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Blending_Order()
- Update Order Bom
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Blending_Order(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_BLENDING_ORDER(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Blending_Order", out_node);
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
CUS_WIP_BLENDING_ORDER()
- Main sub function of "CUS_WIP_Blending_Order" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_BLENDING_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MWIPFLWDEF_TAG MWIPFLWDEF;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;
    struct CWIPGRTBLD_TAG CWIPGRTBLD;
    struct CWIPBLDAVG_TAG CWIPBLDAVG;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    struct work_date_tag work_date;

    TRSNode *gen_in_node;
    TRSNode *create_in;
    TRSNode **Lot_tbl;
    TRSNode **Avg_tbl;
    TRSNode *mat_in;
    TRSNode *list_in;
    TRSNode *cmn_out;

    int i_lot_count = 0;
    int i_avg_count = 0;
    int i = 0;
    int icount = 0;
    char s_lot_id[26];
    char s_factory[10];

    LOG_head("CUS_WIP_Blending_Order");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Blending_Order_Bom_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memset(s_lot_id, ' ', sizeof(s_lot_id));
    memset(s_factory, ' ', sizeof(s_factory));

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(s_factory, &work_date);

    //작업지시 체크
    DBU_init_mwipordsts(&MWIPORDSTS);
    TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
    DBU_select_mwipordsts(1, &MWIPORDSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //ORD-0002 : 이 ORDER는 존재하지 않습니다.
        strcpy(s_msg_code, "ORD-0002");
        TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {   
        //작업지시 수량관 블랜딩 작업의 sum 수량이 다르면 벨리데이션
        if (MWIPORDSTS.ORD_QTY != TRS.get_double(in_node, "SUM_QTY"))
        {
            //WIP-0645 : 작업지시 수량과 lot 선택 수량이 다릅니다. 수량을 확인 하세요.
            strcpy(s_msg_code, "WIP-0645");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //작업지시에 이미 생성된 lot이 있는지 벨리데이션.
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        memcpy(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));       
        icount = (int)DBU_select_mwiplotstsx_scalar(4, &MWIPLOTSTSX);
        if (icount > 0)
        {
            //WIP-0619 : 작업지시에 대한 Lot 생성 수량이 초과 되었습니다. Lot 생성수량과 작업지시 수량을 확인하세요.
            strcpy(s_msg_code, "WIP-0619");
            TRS.add_dberrmsg(out_node, DB_error_msg);
            return MP_FALSE;
        }

        //작업지시 FLOW조회
        DBU_init_mwipflwdef(&MWIPFLWDEF);
        memcpy(MWIPFLWDEF.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        memcpy(MWIPFLWDEF.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
        DBU_select_mwipflwdef(1, &MWIPFLWDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0008 : 이 FLOW는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0008");
            TRS.add_fieldmsg(out_node, "MWIPFLWDEF SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWDEF.FACTORY), MWIPFLWDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWDEF.FLOW), MWIPFLWDEF.FLOW);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
        //작업지시의 첫 공정을 조회한다. 
        DBU_init_mwipflwopr(&MWIPFLWOPR);
        memcpy(MWIPFLWOPR.FACTORY, MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
        memcpy(MWIPFLWOPR.FLOW, MWIPFLWDEF.FLOW, sizeof(MWIPFLWDEF.FLOW));
        DBU_select_mwipflwopr(2, &MWIPFLWOPR);
        if (DB_error_code != DB_SUCCESS)
        {
            //EDC-0044 : OPERATION은 FLOW에 속해 있지 않습니다.
            strcpy(s_msg_code, "EDC-0044");
            TRS.add_fieldmsg(out_node, "MWIPFLWDEF SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //작업지시에 등록된 lot을 지운다.
        DBU_init_cwipgrtbld(&CWIPGRTBLD);
        TRS.copy(CWIPGRTBLD.FACTORY, sizeof(CWIPGRTBLD.FACTORY), in_node, IN_FACTORY);
        memcpy(CWIPGRTBLD.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPGRTBLD.ORDER_ID));
        DBU_delete_cwipgrtbld(2, &CWIPGRTBLD);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPGRTBLD DELETE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTBLD.FACTORY), CWIPGRTBLD.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPGRTBLD.ORDER_ID), CWIPGRTBLD.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (i = 0; i < i_lot_count; i++)
        {
            //자재lot 또는 공정lot인지 판단하여 조회한다
            if (memcmp(TRS.get_string(Lot_tbl[i], "LOT_TYPE"), MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
            {
                DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
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

                //lot 삭제여부 체크
                if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
                {
                    //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0076");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

                    return MP_FALSE;
                }

                //lot별 고정을 조회한다.
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

                /* 
                    제품창고에 있는 lot인 경우 블랜딩 작업지시에 투입 처리 안되게 한다.
                    -> 블랜딩 작업지시에서 보기이만 하고, 투입처리는 되지 않도록 한다.
                       LOT 일부 실적 투입시에는 Split하여 블랜딩 원료로 선택 후 해당 아이템을 공정창고로 이동, 
                       실물 반출하여 투입하는 방식으로 Process 진행
                       (블랜딩 투입으로 설정된 LOT은 포장 불가가 되도록 설정)                    
                 */
                if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
                {
                    //WIP-0690 : 제품창고에서는 블랜딩 작업지시에 투입처리 할 수 없습니다. 창고 이동 후 투입처리를 진행해 주세요.
                    strcpy(s_msg_code, "WIP-0690");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            else
            {
                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_minvlotsts(1, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
                //lot 삭제여부 체크
                if (MINVLOTSTS.DELETE_FLAG == 'Y')
                {
                    //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0076");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

                    return MP_FALSE;
                }
            }

            DBU_init_cwipgrtbld(&CWIPGRTBLD);
            TRS.copy(CWIPGRTBLD.FACTORY, sizeof(CWIPGRTBLD.FACTORY), in_node, IN_FACTORY);
            memcpy(CWIPGRTBLD.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPGRTBLD.ORDER_ID));
            TRS.copy(CWIPGRTBLD.LOT_ID, sizeof(CWIPGRTBLD.LOT_ID), Lot_tbl[i], "LOT_ID");            
            TRS.copy(CWIPGRTBLD.MAT_ID, sizeof(CWIPGRTBLD.MAT_ID), Lot_tbl[i], "MAT_ID");
            TRS.copy(CWIPGRTBLD.OPER, sizeof(CWIPGRTBLD.OPER), Lot_tbl[i], "OUT_OPER");
            CWIPGRTBLD.QTY_1 = TRS.get_double(Lot_tbl[i], "QTY_1");
            CWIPGRTBLD.SHEET_NO = TRS.get_int(Lot_tbl[i], "SHEET_NO");
            CWIPGRTBLD.PSD_UP = TRS.get_double(Lot_tbl[i], "PSD_UP_VALUE");
            CWIPGRTBLD.SS = TRS.get_double(Lot_tbl[i], "SS_VALUE");
            CWIPGRTBLD.OS = TRS.get_double(Lot_tbl[i], "OS_VALUE");
            CWIPGRTBLD.PSD_LO = TRS.get_double(Lot_tbl[i], "PSD_LO_VALUE");
            CWIPGRTBLD.TI = TRS.get_double(Lot_tbl[i], "TI_VALUE");
            CWIPGRTBLD.BI = TRS.get_double(Lot_tbl[i], "BI_VALUE");
            CWIPGRTBLD.TTI = TRS.get_double(Lot_tbl[i], "TTI_VALUE");
            CWIPGRTBLD.MA = TRS.get_double(Lot_tbl[i], "MA_VALUE");
            CWIPGRTBLD.HLT = TRS.get_double(Lot_tbl[i], "HLT_VALUE");
            CWIPGRTBLD.EILLPT = TRS.get_double(Lot_tbl[i], "EILLPT_VALUE");            
            TRS.copy(CWIPGRTBLD.CREATE_USER_ID, sizeof(CWIPGRTBLD.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPGRTBLD.CREATE_TIME, gs_sys_time, sizeof(CWIPGRTBLD.CREATE_TIME));
            TRS.copy(CWIPGRTBLD.UPDATE_USER_ID, sizeof(CWIPGRTBLD.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPGRTBLD.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRTBLD.UPDATE_TIME));
            DBU_insert_cwipgrtbld(&CWIPGRTBLD);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPGRTBLD INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTBLD.FACTORY), CWIPGRTBLD.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPGRTBLD.ORDER_ID), CWIPGRTBLD.ORDER_ID);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRTBLD.LOT_ID), CWIPGRTBLD.LOT_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPGRTBLD.OPER), CWIPGRTBLD.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        Avg_tbl = TRS.get_list(in_node, "AVG_TBL");
        i_avg_count = TRS.get_item_count(in_node, "AVG_TBL");

        for (i = 0; i < i_avg_count; i++)
        {
            DBU_init_cwipbldavg(&CWIPBLDAVG);
            TRS.copy(CWIPBLDAVG.FACTORY, sizeof(CWIPBLDAVG.FACTORY), in_node, IN_FACTORY);
            memcpy(CWIPBLDAVG.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            CWIPBLDAVG.SHEET_NO = TRS.get_int(Avg_tbl[i], "SHEET_NO");
            DBU_select_cwipbldavg(1, &CWIPBLDAVG);
            
            CWIPBLDAVG.QTY_1 = TRS.get_double(Avg_tbl[i], "QTY_1");
            CWIPBLDAVG.QTY_RATE = TRS.get_double(Avg_tbl[i], "RATE");
            CWIPBLDAVG.SHEET_NO = TRS.get_int(Avg_tbl[i], "SHEET_NO");
            CWIPBLDAVG.PSD_UP = TRS.get_double(Avg_tbl[i], "PSD_UP_VALUE");
            CWIPBLDAVG.SS = TRS.get_double(Avg_tbl[i], "SS_VALUE");
            CWIPBLDAVG.OS = TRS.get_double(Avg_tbl[i], "OS_VALUE");
            CWIPBLDAVG.PSD_LO = TRS.get_double(Avg_tbl[i], "PSD_LO_VALUE");
            CWIPBLDAVG.TI = TRS.get_double(Avg_tbl[i], "TI_VALUE");
            CWIPBLDAVG.BI = TRS.get_double(Avg_tbl[i], "BI_VALUE");
            CWIPBLDAVG.TTI = TRS.get_double(Avg_tbl[i], "TTI_VALUE");
            CWIPBLDAVG.MA = TRS.get_double(Avg_tbl[i], "MA_VALUE");
            CWIPBLDAVG.HLT = TRS.get_double(Avg_tbl[i], "HLT_VALUE");
            CWIPBLDAVG.EILLPT = TRS.get_double(Avg_tbl[i], "EILLPT_VALUE");

            if (DB_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CWIPBLDAVG.UPDATE_USER_ID, sizeof(CWIPBLDAVG.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPBLDAVG.UPDATE_TIME, gs_sys_time, sizeof(CWIPBLDAVG.UPDATE_TIME));
                TRS.copy(CWIPBLDAVG.CREATE_USER_ID, sizeof(CWIPBLDAVG.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPBLDAVG.CREATE_TIME, gs_sys_time, sizeof(CWIPBLDAVG.CREATE_TIME));

                DBU_insert_cwipbldavg(&CWIPBLDAVG);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPBLDAVG INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPBLDAVG.FACTORY), CWIPBLDAVG.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPBLDAVG.ORDER_ID), CWIPBLDAVG.ORDER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                TRS.copy(CWIPBLDAVG.UPDATE_USER_ID, sizeof(CWIPBLDAVG.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPBLDAVG.UPDATE_TIME, gs_sys_time, sizeof(CWIPBLDAVG.UPDATE_TIME));

                DBU_update_cwipbldavg(1, &CWIPBLDAVG);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPBLDAVG UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPBLDAVG.FACTORY), CWIPBLDAVG.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPBLDAVG.ORDER_ID), CWIPBLDAVG.ORDER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }

        memset(s_lot_id, ' ', sizeof(s_lot_id));

        gen_in_node = TRS.add_node(in_node, "gen_in_node");
        TRS.add_char(gen_in_node, "PROCSTEP", '2');
        CopyDefaultMembers(gen_in_node, in_node);
        TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_SHIPPING_LOT_ID));
        TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        //사업부별 채번룰의 SEQ가 1번이 되는 경우 FLOW로 사업부를 파라미터로 넘겨 SEQ를 채번한다.
        TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
        TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
        TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
        TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
        TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }

        if (COM_isnullspace(TRS.get_string(in_node, "CREATE_LOT_KEY")) == MP_FALSE)
        {
            sprintf(s_lot_id, "%s%s", TRS.get_string(cmn_out, "GEN_ID"), TRS.get_string(in_node, "CREATE_LOT_KEY"));
        }
        else
        {
            memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
        }

        TRS.free_node(cmn_out);

        //LOT ID 생성 
        //채번된 LOT ID로 작업 공정의 작업지시 정보를 사용하여 LOT을 생성 한다.
        create_in = TRS.add_node(in_node, "create_in");
        TRS.add_char(create_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(create_in, in_node);

        TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
        TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
        TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
        TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
        TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
        TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
        TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
        TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
        TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
        TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
        TRS.add_double(create_in, "QTY_1", MWIPORDSTS.ORD_QTY);
        TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
        TRS.add_nstring(create_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);

        //작업지시 업데이트.
        //create 시 작업지시가 자동 생성될때 상태값이 start로 변경되기 때문에 다시 wait상태로 바꿔준다
        MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
        TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
        TRS.copy(MWIPORDSTS.ORD_CMF_6, sizeof(MWIPORDSTS.ORD_CMF_6), in_node, "CREATE_LOT_KEY");

        //작업지시 설명 업데이트
        DBU_update_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //자동으로 자재 투입 처리를 해준다. 
        //자재 투입 서비스 호출. 
        mat_in = TRS.add_node(in_node, "mat_in");
        TRS.add_char(mat_in, IN_PROCSTEP, '4');
        CopyDefaultMembers(mat_in, in_node);

        TRS.add_nstring(mat_in, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
        TRS.add_string(mat_in, "SUB_AREA_ID", MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
        TRS.add_string(mat_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        TRS.add_string(mat_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
        TRS.add_string(mat_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
        TRS.add_char(mat_in, "REL_LEVEL", '1');
        
        for (i = 0; i < i_lot_count; i++)
        {
            list_in = TRS.add_node(mat_in, "LIST_TBL");
            TRS.add_nstring(list_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));
            TRS.add_nstring(list_in, "MAT_ID", TRS.get_string(Lot_tbl[i], "MAT_ID"));
            TRS.add_nstring(list_in, "LOT_TYPE", TRS.get_string(Lot_tbl[i], "LOT_TYPE"));
            TRS.add_nstring(list_in, "INPUT_TYPE", TRS.get_string(Lot_tbl[i], "INPUT_TYPE"));            
            TRS.add_nstring(list_in, "OUT_OPER", TRS.get_string(Lot_tbl[i], "OUT_OPER"));
            TRS.add_double(list_in, "QTY", TRS.get_double(Lot_tbl[i], "QTY_1"));
            TRS.add_double(list_in, "BOM_QTY", TRS.get_double(Lot_tbl[i], "BOM_QTY"));
        }

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, mat_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);


        TRS.add_string(out_node, "LOT_ID", s_lot_id, sizeof(s_lot_id));
    }
    
    else if (TRS.get_procstep(in_node) == '2')
    {
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
        DBU_select_mwiplotstsx(4, &MWIPLOTSTSX);
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

        if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) != MP_FALSE)
        {
            //WIP-0653 : 이 LOT은 작업중입니다. LOT정보를 확인하세요.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "TRAN_CODE", MP_STR, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE), MWIPLOTSTSX.LAST_TRAN_CODE);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //LOT ID 이력삭제
        create_in = TRS.add_node(in_node, "create_in");
        TRS.add_char(create_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(create_in, in_node);

        TRS.add_string(create_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        
        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_DELETE_HISTORY(s_msg_code, create_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Blending_Order_Bom_Validation()
- Validation Check sub function of "CUS_WIP_BLENDING_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Blending_Order_Bom_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
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

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
    {
        //ORD-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.
        strcpy(s_msg_code, "ORD-0001");
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}
