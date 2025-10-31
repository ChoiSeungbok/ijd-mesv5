/*******************************************************************************

    System      : MESplus
    Module      : CUS_WIP
    File Name   : CUS_WIP_inventory_survey.c
    Description : 재고 조사한 Lot을 생성한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/07  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_INVENTORY_SURVEY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_WIP_Inventory_Survey()
        - 설비에 시작 정보를 전송한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Inventory_Survey(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_INVENTORY_SURVEY(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Inventory_Survey", out_node);

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
    CUS_WIP_INVENTORY_SURVEY()
        - Main sub function of "CUS_WIP_Inventory_Survey" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_INVENTORY_SURVEY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPMATFLW_TAG MWIPMATFLW;
    struct MWIPMATFLW_TAG MWIPMATFLW_M;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;
    struct MWIPFLWOPR_TAG MWIPFLWOPR_M;
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct CPAKLOTSTS_TAG CPAKLOTSTS;
    struct CPAKORDSTS_TAG CPAKORDSTS;

    // Legacy System Table
    struct CT_PACKING_V_TAG CT_PACKING_V;
    struct CT_SAL110T_TAG CT_SAL110T_SUM;

    TRSNode *create_in_node;
    TRSNode *inv_lot;
    TRSNode *terminate_lot;
    TRSNode *cv_in;

    int iCnt = 0;
    char s_seq[3];
    char s_lot_id[25];
    char s_first_flow[20];
    char s_last_oper[10];

    LOG_head("CUS_WIP_INVENTORY_SURVEY");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);
    
    DBU_init_mwipmatdef(&MWIPMATDEF);
    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
    MWIPMATDEF.MAT_VER = 1;

    DBU_select_mwipmatdef(1, &MWIPMATDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0006 : 이 제품은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0006");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATDEF.MAT_VER);

        return MP_FALSE;
    }

    if (MWIPMATDEF.DELETE_FLAG == 'Y')
    {
        // WIP-0276 : 이 제품은 이미 삭제되었습니다. 제품을 확인하세요.
        strcpy(s_msg_code, "WIP-0276");
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATDEF.MAT_VER);

        return MP_FALSE;
    }

    DBU_init_mwipoprdef(&MWIPOPRDEF);
    memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");

    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_minvlotsts(&MINVLOTSTS);
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
        DBU_select_minvlotsts(1, &MINVLOTSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            // INV-0048 : 이 자재 Lot은 이미 존재합니다.
            strcpy(s_msg_code, "INV-0048");
            TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

            return MP_FALSE;
        }
        else if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

            return MP_FALSE;
        }

    }
    else
    {
        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            // WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0045");

            TRS.add_fieldmsg(out_node, "Already Exits Lot ID", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));
            TRS.add_fieldmsg(out_node, "QTY", DT_DOUBLE, TRS.get_double(in_node, "QTY"));
            TRS.add_fieldmsg(out_node, "OPER", DT_NSTRING, TRS.get_string(in_node, "OPER"));

            return MP_FALSE;
        }
        else if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "Lot ID", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));
            TRS.add_fieldmsg(out_node, "QTY", DT_DOUBLE, TRS.get_double(in_node, "QTY"));
            TRS.add_fieldmsg(out_node, "OPER", DT_NSTRING, TRS.get_string(in_node, "OPER"));

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        // Material의 첫번째 Flow 구하기
        DBU_init_mwipmatflw(&MWIPMATFLW);
        memcpy(MWIPMATFLW.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
        memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATFLW.MAT_ID));
        MWIPMATFLW.MAT_VER = 1;
        MWIPMATFLW.FLOW_SEQ_NUM = 1;
        DBU_select_mwipmatflw(3, &MWIPMATFLW);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
            {
                // WIP-0593 : 해당 제품은 Flow가 설정되지 않았습니다. 제품 셋업의 플로우 부여에서 설정하세요.
                strcpy(s_msg_code, "WIP-0593");
            }
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT 2", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_NSTRING, TRS.get_string(in_node, "FACTORY"));
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));

            return MP_FALSE;
        }

        memcpy(s_first_flow, MWIPMATFLW.FLOW, sizeof(s_first_flow));
    }

    // 자재
    if(TRS.get_procstep(in_node) == '1')
    {
        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '3');

        inv_lot = TRS.add_node(create_in_node, "INV_LOT_LIST");
        TRS.add_nstring(inv_lot, "INV_LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(inv_lot, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_nstring(inv_lot, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_double(inv_lot, "QTY", TRS.get_double(in_node, "QTY"));
        TRS.add_nstring(inv_lot, "VENDOR_ID", TRS.get_string(in_node, "VENDOR_ID"));
		TRS.add_nstring(inv_lot, "VENDOR_SITE_ID", TRS.get_string(in_node, "VENDOR_SITE_ID"));
        TRS.add_nstring(inv_lot, "VENDOR_LOT_ID", TRS.get_string(in_node, "VENDOR_LOT_ID"));
        TRS.add_nstring(inv_lot, "IN_TYPE", "MIG");

        if(CUS_INV_CREATE_LOT_MAIN(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;
    }
    // 재공
    else if (TRS.get_procstep(in_node) == '2')
    {
        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '1');

        TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_int(create_in_node, "MAT_VER", 1);
        TRS.add_char(create_in_node, "LOT_TYPE", 'P');
        TRS.add_string(create_in_node, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
        TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
        TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
        TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
        TRS.add_nstring(create_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
        TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
        TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");

        if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

        memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

        DBU_init_mwiplothisx(&MWIPLOTHIS);
        TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
        MWIPLOTHIS.HIST_SEQ = 1;
        DBU_select_mwiplothisx(1, &MWIPLOTHIS);

        memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplothisx(1, &MWIPLOTHIS);
    }
    //  제품(완제품 창고)
    else if(TRS.get_procstep(in_node) == '3')
    {
        /* 처리 순서
         1. Flow에서 마지막 공정 찾기
         2. 찾은 마지막 공정에 Lot을 생성
         3. 완제품 창고로 이동
        */
        DBU_init_mwipflwopr(&MWIPFLWOPR);

        memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
        memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPFLWOPR.FLOW));

        DBU_select_mwipflwopr(4, &MWIPFLWOPR);
        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if(DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, "WIP-0004");
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

            return MP_FALSE;
        }

        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '1');

        TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_int(create_in_node, "MAT_VER", 1);
        TRS.add_char(create_in_node, "LOT_TYPE", 'P');
        TRS.add_string(create_in_node, "FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
        TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
        TRS.add_string(create_in_node, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
        TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
        TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
        TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
        TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");

        if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

        memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

        DBU_init_mwiplothisx(&MWIPLOTHIS);
        TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
        MWIPLOTHIS.HIST_SEQ = 1;
        DBU_select_mwiplothisx(1, &MWIPLOTHIS);

        memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplothisx(1, &MWIPLOTHIS);

        terminate_lot = TRS.add_node(in_node, "Create_Lot_In");
        CopyDefaultMembers(terminate_lot, in_node);
        TRS.add_char(terminate_lot, IN_PROCSTEP, '1');
        TRS.add_nstring(terminate_lot, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

        if(CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_lot, out_node) == MP_FALSE)
            return MP_FALSE;

        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '3');

        inv_lot = TRS.add_node(create_in_node, "INV_LOT_LIST");
        TRS.add_nstring(inv_lot, "INV_LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(inv_lot, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_nstring(inv_lot, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_double(inv_lot, "QTY", TRS.get_double(in_node, "QTY"));
        TRS.add_nstring(inv_lot, "IN_TYPE", "MIG");

        if (CUS_INV_CREATE_LOT_MAIN(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;
    }
    // 출하대기 인 경우
    else if (TRS.get_procstep(in_node) == '4')
    {
        /* 처리 순서
          1. Mat ID의 사업부로 공정(출하대기 창고)을 찾음
          2. 찾은 공정으로 FLOW-OPER에서 FLOW 찾음.
          3. Mat ID의 첫번째 Flow, flow의 마지막 Oper 찾음
          4. 출하 Lot을 생성한다.(Create)(LOT_CMF_7 : 첫번째 FLOW, LOT_CMF_8 : 첫번재 FLOW의 마지막 공정, LOT_CMF_9 : 완제품 창고)
          5. CPAKORDSTS 데이터를 생성한다.
          6. CPAKLOTSTS 데이터를 생성한다.
        */

        // 사업부로 공정(출하대기 창고) 찾기
        memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
        memcpy(MWIPOPRDEF.AREA_ID, MWIPMATDEF.MAT_GRP_1, sizeof(MWIPOPRDEF.AREA_ID));
        MWIPOPRDEF.INV_FLAG = 'Y';
        memcpy(MWIPOPRDEF.OPER_GRP_1, "SHIP", strlen("SHIP"));

        DBU_select_mwipoprdef(7, &MWIPOPRDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0600 : 출하 대기 창고를 찾을 수 없습니다.
                strcpy(s_msg_code, "WIP-0600");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPOPRDEF Select 7", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
            TRS.add_fieldmsg(out_node, "INV_FLAG", DT_CHAR, MWIPOPRDEF.INV_FLAG);
            TRS.add_fieldmsg(out_node, "OPER_GRP_1", DT_STRING, sizeof(MWIPOPRDEF.OPER_GRP_1), MWIPOPRDEF.OPER_GRP_1);

            return MP_FALSE;
        }

        // 찾은 공정(출하대기 창고)으로 FLOW-OPER에서 FLOW 찾음
        DBU_init_mwipflwopr(&MWIPFLWOPR_M);

        memcpy(MWIPFLWOPR_M.FACTORY, MWIPOPRDEF.FACTORY, sizeof(MWIPFLWOPR_M.FACTORY));
        memcpy(MWIPFLWOPR_M.OPER, MWIPOPRDEF.OPER, sizeof(MWIPFLWOPR_M.OPER));

        DBU_select_mwipflwopr(5, &MWIPFLWOPR_M);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, "WIP-0004");
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 5", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR_M.FACTORY), MWIPFLWOPR_M.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPFLWOPR_M.OPER), MWIPFLWOPR_M.OPER);

            return MP_FALSE;
        }

        // 첫번째 Flow의 마지막 공정 찾기
        DBU_init_mwipflwopr(&MWIPFLWOPR);

        memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
        memcpy(MWIPFLWOPR.FLOW, s_first_flow, sizeof(MWIPFLWOPR.FLOW));
        DBU_select_mwipflwopr(4, &MWIPFLWOPR);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

            return MP_FALSE;
        }

        memcpy(s_last_oper, MWIPFLWOPR.OPER, sizeof(s_last_oper));

        // Flow의 Flow_SEQ_NUM 구하기
        DBU_init_mwipmatflw(&MWIPMATFLW_M);
        memcpy(MWIPMATFLW_M.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW_M.FACTORY));
        TRS.copy(MWIPMATFLW_M.MAT_ID, sizeof(MWIPMATFLW_M.MAT_ID), in_node, "MAT_ID");
        MWIPMATFLW_M.MAT_VER = 1;
        memcpy(MWIPMATFLW_M.FLOW, MWIPFLWOPR_M.FLOW, sizeof(MWIPMATFLW_M.FLOW));
        DBU_select_mwipmatflw(4, &MWIPMATFLW_M);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0593 : 해당 제품은 Flow가 설정되지 않았습니다. 제품 셋업의 플로우 부여에서 설정하세요.
                strcpy(s_msg_code, "WIP-0593");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPMATFLW Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATFLW_M.FACTORY), MWIPMATFLW_M.FACTORY);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATFLW_M.MAT_ID), MWIPMATFLW_M.MAT_ID);
            TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATFLW_M.MAT_VER);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPMATFLW_M.FLOW), MWIPMATFLW_M.FLOW);

            return MP_FALSE;
        }

        //
        DBU_init_ct_packing_v(&CT_PACKING_V);
        TRS.copy(CT_PACKING_V.LOT_ID, sizeof(CT_PACKING_V.LOT_ID), in_node, "LOT_ID");
        iCnt = (int)DBU_select_ct_packing_v_scalar(2, &CT_PACKING_V);

        if(iCnt == 0)
        {
            // 해당 출하 Lot은 출하대기 창고 존재하지 않습니다.
            strcpy(s_msg_code, "WIP-0606");
            return MP_FALSE;
        }

        // Legacy System에서 Packing Lot 구하기
        DBU_open_ct_packing_v(1, &CT_PACKING_V);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "CT_PACKING_V Open 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PACKING_V.LOT_ID), CT_PACKING_V.LOT_ID);

            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_ct_packing_v(1, &CT_PACKING_V);
            if(DB_error_code == DB_NOT_FOUND)
            {
				// 20.12.21 minjae.go
                //DBU_close_ct_sal110t(1);
				DBU_close_ct_packing_v(1);
				//
                break;
            }
            else if(DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");

                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "CT_PACKING_V Fetch 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PACKING_V.LOT_ID), CT_PACKING_V.LOT_ID);

                DBU_close_ct_packing_v(1);

                return MP_FALSE;
            }

            COM_itoa_zero(s_seq, CT_PACKING_V.LOT_SEQ, sizeof(s_seq));
            sprintf(s_lot_id, "%s-%.*s", TRS.get_string(in_node, "LOT_ID"), (int)sizeof(s_seq), s_seq);

            DBU_init_mwiplotstsx(&MWIPLOTSTS);
            memcpy(MWIPLOTSTS.LOT_ID, s_lot_id, strlen(s_lot_id));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                // 생산 Lot 생성
                create_in_node = TRS.add_node(in_node, "Create_Lot_In");

                CopyDefaultMembers(create_in_node, in_node);
                TRS.add_char(create_in_node, IN_PROCSTEP, '1');

                TRS.add_string(create_in_node, "LOT_ID", s_lot_id, sizeof(s_lot_id));
                TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
                TRS.add_int(create_in_node, "MAT_VER", 1);
                TRS.add_char(create_in_node, "LOT_TYPE", 'P');
                TRS.add_string(create_in_node, "FLOW", MWIPFLWOPR_M.FLOW, sizeof(MWIPFLWOPR_M.FLOW));
                TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW_M.FLOW_SEQ_NUM);
                TRS.add_string(create_in_node, "OPER", MWIPFLWOPR_M.OPER, sizeof(MWIPFLWOPR_M.OPER));
                TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
                TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
                TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
                TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");
                TRS.add_string(create_in_node, "LOT_CMF_7", s_first_flow, sizeof(s_first_flow)); // 제품의 첫번째 Flow
                TRS.add_string(create_in_node, "LOT_CMF_8", s_last_oper, sizeof(s_last_oper)); // 제품의 첫번째 Flow의 마지막 공정

                // 사업부로 공정(완제품 창고) 찾기
                memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                memcpy(MWIPOPRDEF.AREA_ID, MWIPMATDEF.MAT_GRP_1, sizeof(MWIPOPRDEF.AREA_ID));
                MWIPOPRDEF.INV_FLAG = 'Y';
                memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD));

                DBU_select_mwipoprdef(7, &MWIPOPRDEF);
                if (DB_error_code != DB_SUCCESS)
                {
                    if (DB_error_code == DB_NOT_FOUND)
                        // WIP-0604 : 완제품 창고를 찾을 수 없습니다.
                        strcpy(s_msg_code, "WIP-0604");
                    else
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                    }

                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF Select 7", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
                    TRS.add_fieldmsg(out_node, "INV_FLAG", DT_CHAR, MWIPOPRDEF.INV_FLAG);
                    TRS.add_fieldmsg(out_node, "OPER_GRP_1", DT_STRING, sizeof(MWIPOPRDEF.OPER_GRP_1), MWIPOPRDEF.OPER_GRP_1);

                    DBU_close_ct_packing_v(1);

                    return MP_FALSE;
                }

                TRS.add_string(create_in_node, "LOT_CMF_9", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

				if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
				{
					// 20.12.21 minjae.go
					DBU_close_ct_packing_v(1);
					//
					return MP_FALSE;
				}
                DBU_init_mwiplotstsx(&MWIPLOTSTS);
                TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

                memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
                DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

                DBU_init_mwiplothisx(&MWIPLOTHIS);
                TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
                MWIPLOTHIS.HIST_SEQ = 1;
                DBU_select_mwiplothisx(1, &MWIPLOTHIS);

                memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
                DBU_update_mwiplothisx(1, &MWIPLOTHIS);

                DBU_init_cpaklotsts(&CPAKLOTSTS);
                memcpy(CPAKLOTSTS.FACTORY, MWIPOPRDEF.FACTORY, sizeof(CPAKLOTSTS.FACTORY));
                memcpy(CPAKLOTSTS.ORG_LOT_ID, CT_PACKING_V.LOT_ADD, sizeof(CPAKLOTSTS.ORG_LOT_ID));
                memcpy(CPAKLOTSTS.PACK_LOT_ID, s_lot_id, strlen(s_lot_id));
                TRS.copy(CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID), in_node, "MAT_ID");
                CPAKLOTSTS.MAT_VER = 1;
                CPAKLOTSTS.QTY = CT_PACKING_V.LABEL_QTY;
                memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(CPAKLOTSTS.UNIT));
                COM_itoa_left(CPAKLOTSTS.PACK_ORDER_ID, CT_PACKING_V.ORDER_NUMBER, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
                CPAKLOTSTS.PACK_LINE_NO = CT_PACKING_V.LINE_NUMBER;

                TRS.copy(CPAKLOTSTS.CREATE_USER_ID, sizeof(MWIPMATDEF.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CPAKLOTSTS.CREATE_TIME, gs_sys_time, sizeof(CPAKLOTSTS.CREATE_TIME));

                DBU_insert_cpaklotsts(&CPAKLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "CPAKLOTSTS Insert", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORG_LOT_ID", DT_STRING, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
                    TRS.add_fieldmsg(out_node, "PACK_LOT_ID", DT_STRING, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
                    TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CPAKLOTSTS.MAT_ID), CPAKLOTSTS.MAT_ID);
                    TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", DT_STRING, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);

                    DBU_close_ct_packing_v(1);

                    return MP_FALSE;
                }

                DBU_init_cpakordsts(&CPAKORDSTS);
                memcpy(CPAKORDSTS.FACTORY, CPAKLOTSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY));
                memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
                CPAKORDSTS.LINE_NO = CT_PACKING_V.LINE_NUMBER;
                DBU_select_cpakordsts(1, &CPAKORDSTS);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    memcpy(CPAKORDSTS.PACK_ORD_DATE, CT_PACKING_V.ORDERED_DATE, sizeof(CT_PACKING_V.ORDERED_DATE));
                    memcpy(CPAKORDSTS.MAT_ID, CT_PACKING_V.ITEM_CODE, sizeof(CPAKORDSTS.MAT_ID));
                    CPAKORDSTS.MAT_VER = 1;
                    memcpy(CPAKORDSTS.CUSTOMER_ID, CT_PACKING_V.CUSTOMER_NUMBER, sizeof(CPAKORDSTS.CUSTOMER_ID));
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    memcpy(MWIPMATDEF.FACTORY, CPAKORDSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
                    memcpy(MWIPMATDEF.MAT_ID, CPAKORDSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    MWIPMATDEF.MAT_VER = 1;
                    DBU_select_mwipmatdef(1, &MWIPMATDEF);

                    memcpy(CPAKORDSTS.AREA_ID, MWIPMATDEF.MAT_GRP_1, sizeof(CPAKORDSTS.AREA_ID));
                    TRS.copy(CPAKORDSTS.OPER, sizeof(CPAKORDSTS.OPER), in_node, "OPER");
                    CPAKORDSTS.QTY = CT_PACKING_V.ORDER_QTY;

                    DBU_init_ct_sal110t(&CT_SAL110T_SUM);
                    CT_SAL110T_SUM.HEADER_ID = CT_PACKING_V.HEADER_ID;
                    CT_SAL110T_SUM.LINE_NUMBER = CT_PACKING_V.LINE_NUMBER;

                    CPAKORDSTS.PACKED_QTY = DBU_select_ct_sal110t_scalar(3, &CT_SAL110T_SUM);
                    memcpy(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(CPAKORDSTS.UNIT));
                    if (CPAKORDSTS.QTY > CPAKORDSTS.PACKED_QTY)
                        memcpy(CPAKORDSTS.PACK_ORD_STATUS, "WAIT", strlen("WAIT"));
                    else if (CPAKORDSTS.QTY <= CPAKORDSTS.PACKED_QTY)
                        memcpy(CPAKORDSTS.PACK_ORD_STATUS, "PACKED", strlen("PACKED"));

                    memcpy(CPAKORDSTS.LABEL_NAME, CT_PACKING_V.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
                    memcpy(CPAKORDSTS.LABEL_TYPE, CT_PACKING_V.LABEL_TYPE, sizeof(CPAKORDSTS.LABEL_TYPE));
                    memcpy(CPAKORDSTS.LABEL_MESH, CT_PACKING_V.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));

                    DBU_insert_cpakordsts(&CPAKORDSTS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");

                        TRS.add_fieldmsg(out_node, "CPAKORDSTS Insert", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
                        TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", DT_STRING, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
                        TRS.add_fieldmsg(out_node, "LINE_NO", DT_INT, CPAKORDSTS.LINE_NO);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        DBU_close_ct_packing_v(1);

                        return MP_FALSE;
                    }
                }
            }
            else if(DB_error_code == DB_SUCCESS && CT_PACKING_V.LABEL_QTY != MWIPLOTSTS.QTY_1)
            {
                // 출하 Lot 이 존재하고 수량이 존재하는 Lot의 수량과 비교하여 다른 CV Transaction을 발생시킨다.
                cv_in = TRS.add_node(in_node, "Create_Lot_In");

                CopyDefaultMembers(cv_in, in_node);
                TRS.add_char(cv_in, IN_PROCSTEP, '1');

                TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
                TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
                TRS.add_string(cv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                TRS.add_string(cv_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
				//TRS.add_nstring(cv_in, "COMMENT", MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LAST_COMMENT));
                TRS.add_nstring(cv_in, "COMMENT", MWIPLOTSTS.LAST_COMMENT);

                if(MWIPLOTSTS.QTY_1 - CT_PACKING_V.LABEL_QTY >= 0)
                    TRS.add_double(cv_in, "QTY_1", MWIPLOTSTS.QTY_1 - CT_PACKING_V.LABEL_QTY);
                else
                    TRS.add_double(cv_in, "QTY_1", CT_PACKING_V.LABEL_QTY - MWIPLOTSTS.QTY_1);

				if (CUS_WIP_CV_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
				{
					// 20.12.21 minjae.go
					DBU_close_ct_packing_v(1);
					//
					return MP_FALSE;
				}
            }
        }
    }

    return MP_TRUE;
}
