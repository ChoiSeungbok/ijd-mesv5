/******************************************************************************'
    System      : MESplus
    Module      : CUS_WIP
    File Name   : CUS_WIP_common.c
    Description : Customer Common Function 

    MES Version : 5.3.4 ~

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/08/18                  WG.LEE

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.
******************************************************************************/
#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "CUS_INV_common.h" 

/*******************************************************************************
INPUT_INV_LOT_BY_LEVEL()
- Insert Inv Lot Input and cv Inv Lot Qty
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- string sLot
- TRSNode *in_node : In Node from each transaction function
- TRSNode *out_node : Common out node for result message
*******************************************************************************/
int INPUT_INV_LOT_BY_LEVEL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node){
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;             //LOT 상태 테이블
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_LOAD;        //load될 LOT 상태 테이블
    struct MWIPLOTHISX_TAG MWIPLOTHIS_LOAD;         //load될 LOT 상태 테이블    
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_ISS;         //LOT 상태 테이블    
    struct MWIPLOTHISX_TAG MWIPLOTHISX;             //LOT 이력 테이블
    struct MWIPLOTHISX_TAG MWIPLOTHISX_ISS;         //LOT 이력 테이블
    struct MWIPORDSTS_TAG MWIPORDSTS;               //작업지시 마스터 테이블
    struct MWIPMATDEF_TAG MWIPMATDEF;               //자재 마스터 테이블
    struct CWIPORDBOM_TAG CWIPORDBOM;               //작업지시 BOM정보
    struct MINVLOTSTS_TAG MINVLOTSTS;               //자재 상태 테이블
    struct MINVLOTSTS_TAG MINVLOTSTS_ISS;           //자재 상태 테이블
    struct MWIPOPRDEF_TAG MWIPOPRDEF;               //공정 마스터 상태 테이블
    struct MWIPOPRDEF_TAG MWIPOPRDEF_AF;            //공정 마스터 상태 테이블
    struct MWIPOPRDEF_TAG MWIPOPRDEF_ISS;           //공정 마스터 상태 테이블
    struct MINVLOTISS_TAG MINVLOTISS;               //자재 투입 테이블
    struct CWIPINVLDM_TAG CWIPINVLDM;               //자재 LOAD 테이블
    struct CWIPINVLDM_TAG CWIPINVLDM_UN;            //자재 LOAD 테이블
    struct CWIPLOTTRC_TAG CWIPLOTTRC;               //lot 추적 테이블
    struct CWIPERPOPR_TAG CWIPERPOPR;               //
    struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;          //
    struct MGCMTBLDAT_TAG MGCMTBLDAT_SUB_AREA;      //    
    struct MGCMTBLDAT_TAG MGCMTBLDAT_TYPE;          //
    struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;           //
    struct CBASTXNDEF_TAG CBASTXNDEF;               //
    struct CBASTXNDEF_TAG CBASTXNDEF_ETC;           //
    struct MINVETCLOT_TAG MINVETCLOT;               //
    struct IF_INV_TXNS_TAG IF_INV_TXNS;               //

    TRSNode *cv_in;
    TRSNode *inv_list;
    TRSNode *inv_if;
    TRSNode *load_in;    
    TRSNode *cmn_out;

    double d_Qty = 0;
    double d_UseQty = 0;
    double d_RemainQty = 0;
    double d_LdmQty = 0;
    double d_OrderBomQty = 0;
    double d_orderQty = 0;
    double d_LoadRemainQty =0;
    char s_lot_id[26];
    char s_before_mat_id[31];
    int i_seq = 0;
    int i_Change_mat = MP_FALSE;
    int iStep = 0;
    int i = 0;
    int iLevel = 0;
    char c_Level[10];
    double d_UnitQty = 0;
    char c_CheckErpInput;           //ERP 완료이력 여부
    char c_CheckErpResult;          //ERP에 생산이력 여부
    char c_FirstInputYn;          //오더기준 처음 투입되는  경우
    double d_ifseq = 0;
    char c_if_seq[30];
    char c_Iss_cmf4[30];
    int i_LotType = 0;

    LOG_head("INPUT_INV_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    c_CheckErpResult = ' ';
    c_CheckErpInput = ' ';

    //ERP에 생산 이력 및 완료 이력 여부를 리턴 받아오는 함수
    if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    //lot정보 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    ////해당 lot이 테스트 품인 경우 ERP I/F를 타지 못하게 한다.
    //if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
    //    return MP_TRUE;

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
    d_orderQty = MWIPORDSTS.ORD_QTY;

    //LOT의 공정을 조회한다.
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0010 : 이 공정은 존재 하지 않습니다.
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //AREA 정보 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
    TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
    memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
    if (DB_error_code != DB_SUCCESS)
    {
        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
        strcpy(s_msg_code, "GCM-0008");
        gs_log_type.e_type = MP_LOG_E_EXISTENCE;
        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //SUB AREA 정보 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT_SUB_AREA);
    TRS.copy(MGCMTBLDAT_SUB_AREA.FACTORY, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT_SUB_AREA.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
    memcpy(MGCMTBLDAT_SUB_AREA.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SUB_AREA);
    if (DB_error_code != DB_SUCCESS)
    {
        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
        strcpy(s_msg_code, "GCM-0008");
        gs_log_type.e_type = MP_LOG_E_EXISTENCE;
        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), MGCMTBLDAT_SUB_AREA.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.KEY_1), MGCMTBLDAT_SUB_AREA.KEY_1);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //작업지시 공정 조회
    DBU_init_cwiperpopr(&CWIPERPOPR);
    memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
    memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
    memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
    DBU_select_cwiperpopr(2, &CWIPERPOPR);

    //자재 소진 순서 : lot -> 설비 -> 작지 -> 공정 순으로 투입된 자재를 소진한다. 
    //1.LOT 단위 자재 차감. 
    iStep = 4;
    DBU_init_cwipinvldm(&CWIPINVLDM);
    memcpy(CWIPINVLDM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
    CWIPINVLDM.REL_LEVEL = '1';
    TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.LOT_ID), in_node, "LOT_ID");
    DBU_open_cwipinvldm(iStep, &CWIPINVLDM);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
        strcpy(s_msg_code, "WIP-0585");
        TRS.add_fieldmsg(out_node, "CWIPINVLDM OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    while (1)
    {
        DBU_fetch_cwipinvldm(iStep, &CWIPINVLDM);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_cwipinvldm(iStep);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
            strcpy(s_msg_code, "WIP-0585");
            TRS.add_fieldmsg(out_node, "CWIPINVLDM FETCH", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            DBU_close_cwipinvldm(iStep);
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        memset(s_lot_id, ' ', sizeof(s_lot_id));

        //로드된 lot이 공정 lot인 경우
        if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
        {
            //로드된 lot정보 조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
            memcpy(MWIPLOTSTSX_LOAD.LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX_LOAD.LOT_ID), MWIPLOTSTSX_LOAD.LOT_ID);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            memcpy(s_lot_id, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTSTSX_LOAD.LOT_ID));
            i_seq = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;

            if (memcmp(CWIPINVLDM.OUT_OPER, MWIPLOTSTSX_LOAD.OPER, sizeof(MWIPLOTSTSX_LOAD.OPER)) != MP_FALSE)
            {
                //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                strcpy(s_msg_code, "WIP-0648");
                TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //투입되는 LOT의 중간검사 값이 있으면 UPDATE 해준다.
            if (MWIPLOTSTSX_LOAD.LOT_CMF_12[0] != ' ')
            {
                memcpy(MWIPLOTSTSX.LOT_CMF_12, MWIPLOTSTSX_LOAD.LOT_CMF_12, sizeof(MWIPLOTSTSX_LOAD.LOT_CMF_12));
                memcpy(MWIPLOTSTSX.LOT_CMF_13, MWIPLOTSTSX_LOAD.LOT_CMF_13, sizeof(MWIPLOTSTSX_LOAD.LOT_CMF_13));
                DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    return MP_FALSE;
                }

                DBU_init_mwiplothisx(&MWIPLOTHISX);
                memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
                DBU_select_mwiplothisx(1, &MWIPLOTHISX);

                memcpy(MWIPLOTHISX.LOT_CMF_12, MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_12));
                memcpy(MWIPLOTHISX.LOT_CMF_13, MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_13));
                DBU_update_mwiplothisx(1, &MWIPLOTHISX);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    return MP_FALSE;
                }
            }
        }
        //로드된 lot이 자재 lot인 경우
        else
        {
            //로드된 lot정보 조회
            DBU_init_minvlotsts(&MINVLOTSTS);
            memcpy(MINVLOTSTS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(MINVLOTSTS.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
            DBU_select_minvlotsts(1, &MINVLOTSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            if (memcmp(CWIPINVLDM.OUT_OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
            {
                //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                strcpy(s_msg_code, "WIP-0648");
                TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            memcpy(s_lot_id, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
            i_seq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
        }

        //자재 정보 조회
        DBU_init_mwipmatdef(&MWIPMATDEF);
        memcpy(MWIPMATDEF.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
        memcpy(MWIPMATDEF.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
        MWIPMATDEF.MAT_VER = 1;
        DBU_select_mwipmatdef(1, &MWIPMATDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0006 : 이 제품은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0006");
            TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //자재사용 저장
        DBU_init_minvlotiss(&MINVLOTISS);
        memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
        memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
        MINVLOTISS.HIST_SEQ = i_seq;
        DBU_select_minvlotiss(1, &MINVLOTISS);
        if (DB_error_code == DB_SUCCESS)
        {



                 DBU_init_minvlotiss(&MINVLOTISS);
                memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
                //20230516 INV에서 WIP으로 변경된 원자재경우 HIST_SEQ 중복떔시...오류 그냥 플로스 10000 시켜서 HIST_SEQ 만듬
                MINVLOTISS.HIST_SEQ = i_seq + 10000;
                DBU_select_minvlotiss(1, &MINVLOTISS);
                if (DB_error_code == DB_SUCCESS)
                {




                    //INV-0028 : 해당 자재에 투입 이력이 존재합니다. 자재LOT 투입 이력을 확인하세요.
                    strcpy(s_msg_code, "INV-0028");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MINVLOTISS SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }

        }
        else if (DB_error_code == DB_NOT_FOUND)
        {
            memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
            TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
            memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX.LAST_TRAN_TIME));
            memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
            memcpy(MINVLOTISS.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
            MINVLOTISS.MAT_VER = CWIPINVLDM.MAT_VER;
            memcpy(MINVLOTISS.AREA_ID, CWIPINVLDM.AREA_ID, sizeof(MINVLOTISS.AREA_ID));
            memcpy(MINVLOTISS.SUB_AREA_ID, CWIPINVLDM.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID));
            memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
            memcpy(MINVLOTISS.ERP_OPER, CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
            memcpy(MINVLOTISS.OUT_OPER, CWIPINVLDM.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER));
            memcpy(MINVLOTISS.REASON_CODE, CWIPINVLDM.INPUT_TYPE, sizeof(CWIPINVLDM.INPUT_TYPE));
            MINVLOTISS.TRAN_QTY = CWIPINVLDM.QTY;
            memcpy(MINVLOTISS.TRAN_UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
            memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            //개발품인지, 양산품인지 여부를 저장한다.
            memcpy(MINVLOTISS.CMF_4, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
            DBU_insert_minvlotiss(&MINVLOTISS);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MINVLOTISS INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            //사용한 자재는 사용량 만큼 CV처리를 해준다.
            if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
            {
                cv_in = TRS.add_node(in_node, "cv_in");
                TRS.add_char(cv_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(cv_in, in_node);

                TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTSTSX_LOAD.LOT_ID));
                TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_LOAD.MAT_ID, sizeof(MWIPLOTSTSX_LOAD.MAT_ID));
                TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_LOAD.OPER, sizeof(MWIPLOTSTSX_LOAD.OPER));
                TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_LOAD.FLOW, sizeof(MWIPLOTSTSX_LOAD.FLOW));
                TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
                TRS.add_double(cv_in, "QTY_1", COM_dbl_round(MWIPLOTSTSX_LOAD.QTY_1,5,'U') - COM_dbl_round(MINVLOTISS.TRAN_QTY, 5, 'U'));

         //       TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_LOAD.QTY_1 - MINVLOTISS.TRAN_QTY);

                TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }

                TRS.free_node(cmn_out);

                if (memcmp(MWIPLOTSTSX_LOAD.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)) != MP_FALSE)
                {
                    //LOT 추적 테이블에 저장
                    DBU_init_cwiplottrc(&CWIPLOTTRC);
                    TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
                    memcpy(CWIPLOTTRC.AREA_ID, CWIPINVLDM.AREA_ID, sizeof(CWIPLOTTRC.AREA_ID));
                    memcpy(CWIPLOTTRC.SUB_AREA_ID, CWIPINVLDM.SUB_AREA_ID, sizeof(CWIPLOTTRC.SUB_AREA_ID));
                    memcpy(CWIPLOTTRC.OPER, CWIPINVLDM.OPER, sizeof(CWIPLOTTRC.OPER));
                    memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
                    CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;
					memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
                    DBU_insert_cwiplottrc(&CWIPLOTTRC);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
                        TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }
                }

                //gb_multi_transaction KEY는 공백으로 해준다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);               
                memcpy(MWIPLOTSTSX_LOAD.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);

                DBU_init_mwiplothisx(&MWIPLOTHIS_LOAD);
                memcpy(MWIPLOTHIS_LOAD.LOT_ID, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTHIS_LOAD.LOT_ID));
                MWIPLOTHIS_LOAD.HIST_SEQ = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;
                DBU_select_mwiplothisx(1, &MWIPLOTHIS_LOAD);

                memset(MWIPLOTHIS_LOAD.MULTI_TR_KEY, ' ', sizeof(MWIPLOTHIS_LOAD.MULTI_TR_KEY));
                MWIPLOTHIS_LOAD.MULTI_TR_SEQ = 0;

                DBU_update_mwiplothisx(1, &MWIPLOTHIS_LOAD);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_fieldmsg(out_node, "MWIPLOTHIS_LOAD UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS_LOAD.LOT_ID), MWIPLOTHIS_LOAD.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
            else
            {
                cv_in = TRS.add_node(in_node, "cv_in");
                TRS.add_char(cv_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(cv_in, in_node);

                inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
                TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                TRS.add_double(inv_list, "ISSUE_QTY", MINVLOTISS.TRAN_QTY);
                TRS.add_string(cv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                //TRS.add_nstring(cv_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_INV_ISSUE_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }

                TRS.free_node(cmn_out);
            }
        }

        d_Qty = 0;

        //로드된 lot을 다시 조회한다. 
        if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
        {
            //로드된 lot정보 조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
            memcpy(MWIPLOTSTSX_LOAD.LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX_LOAD.LOT_ID), MWIPLOTSTSX_LOAD.LOT_ID);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            d_Qty = MWIPLOTSTSX_LOAD.QTY_1;
        }
        else
        {
            //로드된 lot정보 조회
            DBU_init_minvlotsts(&MINVLOTSTS);
            memcpy(MINVLOTSTS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(MINVLOTSTS.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
            DBU_select_minvlotsts(1, &MINVLOTSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                return MP_FALSE;
            }

            d_Qty = MINVLOTSTS.QTY;
        }

        if (d_Qty == 0)
        {
            DBU_delete_cwipinvldm(5, &CWIPINVLDM);

            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else
        {     
            //자재 수량이 남았지만 공정별 또는 작업지시별 load되어있지 않으면 자동으로 unload처리를 해준다.
            //자재lot 복사
            DBU_init_cwipinvldm(&CWIPINVLDM_UN);
            memcpy(CWIPINVLDM_UN.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(CWIPINVLDM_UN.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));

            //lot에 투입된 자재 투입정보는 먼저 삭제해 준다.
            DBU_delete_cwipinvldm(1, &CWIPINVLDM);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            //자재 수량이 남았지만 공정별 또는 작업지시별 load되어있지 않으면 자동으로 unload처리를 해준다
            if ((int)DBU_select_cwipinvldm_scalar(4, &CWIPINVLDM_UN) == 0)
            {
                if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) != MP_FALSE)
                {
                    load_in = TRS.add_node(in_node, "load_in");
                    TRS.add_char(load_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(load_in, in_node);

                    TRS.add_char(load_in, "REL_LEVEL", '1');

                    inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
                    TRS.add_string(inv_list, "INV_LOT_ID", CWIPINVLDM_UN.INV_LOT_ID, sizeof(CWIPINVLDM_UN.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_UNLOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                }
            }
        }
    }

    // i = 0 => 작업지시별, i=1 => 공정별
    for (i = 0; i < 2; i++)
    {
        //자재 소진이 순서대로 mat 또는 lot이 있는경우는 어떻게????
        memset(s_before_mat_id, ' ', sizeof(s_before_mat_id));

        // i = 0 => 작업지시별(iStep = 3), i=1 => 공정별(iStep = 2) 자재 차감
        iStep = (3 - i);
        iLevel = (2 + i);
        memset(c_Level, ' ', sizeof(c_Level));
        
        DBU_init_cwipinvldm(&CWIPINVLDM);
        memcpy(CWIPINVLDM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        COM_itoa_left(c_Level, iLevel, 1);
        CWIPINVLDM.REL_LEVEL = c_Level[0];
        TRS.copy(CWIPINVLDM.ORDER_ID, sizeof(CWIPINVLDM.ORDER_ID), in_node, "ORDER_ID");
        TRS.copy(CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER), in_node, "OPER");
        DBU_open_cwipinvldm(iStep, &CWIPINVLDM);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
            strcpy(s_msg_code, "WIP-0585");
            TRS.add_fieldmsg(out_node, "CWIPINVLDM OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
            TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        while (1)
        {
            DBU_fetch_cwipinvldm(iStep, &CWIPINVLDM);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_cwipinvldm(iStep);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "CWIPINVLDM FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_cwipinvldm(iStep);
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //이미 투입처리 된 자재lot은 건너뛴다.
            DBU_init_minvlotiss(&MINVLOTISS);
            memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            memcpy(MINVLOTISS.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
            memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
            TRS.copy(MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID), in_node, "ORDER_ID");
            DBU_select_minvlotiss(2, &MINVLOTISS);
            if (DB_error_code == DB_SUCCESS) {
                continue;
            }
            else {

                
                //오더기준 처음 투입되는 건지 확인 체크
             //   DBU_init_minvlotiss(&MINVLOTISS);
                memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                memcpy(MINVLOTISS.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
                memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
                TRS.copy(MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID), in_node, "ORDER_ID");
                if ((int)DBU_select_minvlotiss_scalar(5, &MINVLOTISS) > 0)
                {
                    c_FirstInputYn = 'N';
                }
                else {
                    c_FirstInputYn = 'Y';
                }
                
               // c_FirstInputYn = 'N';

            }




            i_Change_mat = MP_FALSE;

            //MAT ID 체크
            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            if (memcmp(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID)) != MP_FALSE)
            {
                //mat 정보가 변경되는 시점에 이전에 투입(level별 자재 소모) 해당 mat id가 소모처리 되었는지 체크
                DBU_init_minvlotiss(&MINVLOTISS);
                memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                memcpy(MINVLOTISS.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
                memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
                TRS.copy(MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID), in_node, "ORDER_ID");
                if ((int)DBU_select_minvlotiss_scalar(3, &MINVLOTISS) > 0)
                {
                    continue;
                }

                //소모 될 수량이 정해질 경우 d_RemainQty(남은 수량)을 MANUAL_QTY로 세팅한다. 
                // ex) 외주 입고시 loss qty 와 lot qty 수량의 합만큼 자재를 소모해야 하므로.
                if (TRS.get_double(in_node, "MANUAL_QTY") != 0)
                    d_RemainQty = TRS.get_double(in_node, "MANUAL_QTY");
                else
                    d_RemainQty = MWIPLOTSTSX.QTY_1;

                i_Change_mat = MP_TRUE;
            }

            if (i_Change_mat == MP_FALSE && d_RemainQty == 0)
                continue;

            //작업지시 bom상에 있는 mat_id인치 체크한다.
            DBU_init_cwipordbom(&CWIPORDBOM);
            TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
            memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), in_node, "OPER");
            memcpy(CWIPORDBOM.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));
            CWIPORDBOM.MAT_VER = CWIPINVLDM.MAT_VER;

            DBU_select_cwipordbom(1, &CWIPORDBOM);
            if (DB_error_code == DB_SUCCESS)
            {    
                d_UnitQty = CWIPORDBOM.UNIT_QTY;      


                //ERP 소요량이 6자리부터 시작하는거 발생(GRT)
                // 20240206
                //일단 분할되는 공정아니어서, 소요량 1로 해놓기는 했는데..문제안될거 같기는 한데.봐야됨.문제되는 케이스 있을수있음.
                if (d_UnitQty == 0)
                {
                    d_UnitQty = 1;
                }
            }
            else
            {                    
                //d_UnitQty = 1;
                d_UnitQty = 0;
            }

            memset(s_lot_id, ' ', sizeof(s_lot_id));

            //로드된 lot이 공정 lot인 경우
            if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
            {
                //로드된 lot정보 조회
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
                memcpy(MWIPLOTSTSX_LOAD.LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX_LOAD.LOT_ID), MWIPLOTSTSX_LOAD.LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }

                if (memcmp(CWIPINVLDM.OUT_OPER, MWIPLOTSTSX_LOAD.OPER, sizeof(MWIPLOTSTSX_LOAD.OPER)) != MP_FALSE)
                {
                    //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0648");
                    TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_LOAD.OPER), MWIPLOTSTSX_LOAD.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                d_Qty = MWIPLOTSTSX_LOAD.QTY_1;
                d_LdmQty = CWIPINVLDM.QTY;
                d_OrderBomQty = CWIPORDBOM.QTY;
                memcpy(s_lot_id, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTSTSX_LOAD.LOT_ID));
                i_seq = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;

                //투입되는 LOT의 중간검사 값이 있으면 UPDATE 해준다.
                if (MWIPLOTSTSX_LOAD.LOT_CMF_12[0] != ' ')
                {
                    memcpy(MWIPLOTSTSX.LOT_CMF_12, MWIPLOTSTSX_LOAD.LOT_CMF_12, sizeof(MWIPLOTSTSX_LOAD.LOT_CMF_12));
                    memcpy(MWIPLOTSTSX.LOT_CMF_13, MWIPLOTSTSX_LOAD.LOT_CMF_13, sizeof(MWIPLOTSTSX_LOAD.LOT_CMF_13));
                    DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }

                    DBU_init_mwiplothisx(&MWIPLOTHISX);
                    memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
                    DBU_select_mwiplothisx(1, &MWIPLOTHISX);

                    memcpy(MWIPLOTHISX.LOT_CMF_12, MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_12));
                    memcpy(MWIPLOTHISX.LOT_CMF_13, MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_13));
                    DBU_update_mwiplothisx(1, &MWIPLOTHISX);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
            }
            //로드된 lot이 자재 lot인 경우
            else
            {
                //로드된 lot정보 조회
                DBU_init_minvlotsts(&MINVLOTSTS);
                memcpy(MINVLOTSTS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                memcpy(MINVLOTSTS.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));
                DBU_select_minvlotsts(1, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }

                if (memcmp(CWIPINVLDM.OUT_OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
                {
                    //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0648");
                    TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                d_Qty = MINVLOTSTS.QTY;
                d_LdmQty = CWIPINVLDM.QTY;
                d_OrderBomQty = CWIPORDBOM.QTY;
                memcpy(s_lot_id, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                i_seq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
            }

            //자재 투입 방식에 따라 차감 수량이 바뀐다. 
            if (memcmp(CWIPINVLDM.INPUT_TYPE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL)) == MP_FALSE)
            {
                //자재 투입 방식이 all인 경우 
                d_RemainQty = 0;
                d_UseQty = d_Qty;
            }
            else
            {
                //자재 투입 방식이 bom인 경우 

                //생성된 lotdml 차감 수량 계산. 
                //d_RemainQty : 생성된 lot의 완료 수량 계산 변수
                //d_Qty : load 된 자재의 잔량
                //d_UseQty : 투입에 사용되는 수량
                //d_UnitQty : 투입 단위. (BOM상에 없으면 1)




                if (COM_dbl_round(d_RemainQty * d_UnitQty, 5, 'U') <= d_Qty)
                {
                    d_UseQty = COM_dbl_round(d_RemainQty * d_UnitQty, 5, 'U');

                    d_RemainQty = 0;
                }
                else if (COM_dbl_round(d_RemainQty * d_UnitQty, 5, 'U') > d_Qty)
                {
                    d_UseQty = d_Qty;

                    d_RemainQty = ((COM_dbl_round(d_RemainQty * d_UnitQty, 5, 'U')) - d_UseQty) / d_UnitQty;

  

                }

                //소요량 수량이 소수점이 맞아 떨어지지 않는경우 처음 처리시 잔량 소수점 넣어준다
                //20230421 송용원
                if (c_FirstInputYn == 'Y') {
                    if (COM_dbl_round(d_orderQty * d_UnitQty, 5, 'U') < d_OrderBomQty)
                    {
                        d_UseQty = d_UseQty + (d_OrderBomQty - (COM_dbl_round(d_orderQty * d_UnitQty, 5, 'U')));
                    }

                    if (COM_dbl_round(d_orderQty * d_UnitQty, 5, 'U') > d_OrderBomQty)
                    {
                        d_UseQty = d_UseQty - ( (COM_dbl_round(d_orderQty * d_UnitQty, 5, 'U'))- d_OrderBomQty);
                    }
                 //   d_RemainQty =  ((COM_dbl_round(d_RemainQty * d_UnitQty, 5, 'U')) - d_UseQty) / d_UnitQty;


                    if (d_UseQty < 0)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "UseQty Calculation", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "D_USE_QTY", MP_INT, d_UseQty);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                        TRS.add_dberrmsg(out_node, DB_error_msg);


                        return MP_FALSE;
                    }


                    d_RemainQty = 0;
                }


            }

            //사용자재가 0인경우 자재 소요를 하지 않는다.
            if (d_UseQty == 0)
            {
                memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                continue;
            }

            //자재사용 저장
            DBU_init_minvlotiss(&MINVLOTISS);
            memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
            memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
            MINVLOTISS.HIST_SEQ = i_seq;
            DBU_select_minvlotiss(1, &MINVLOTISS);
            if (DB_error_code == DB_SUCCESS)
            {

                

                DBU_init_minvlotiss(&MINVLOTISS);
                memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
                //20230516 INV에서 WIP으로 변경된 원자재경우 HIST_SEQ 중복떔시...오류 그냥 플로스 10000 시켜서 HIST_SEQ 만듬
                MINVLOTISS.HIST_SEQ = i_seq + 10000;
                DBU_select_minvlotiss(1, &MINVLOTISS);
                if (DB_error_code == DB_SUCCESS)
                {




                    //INV-0028 : 해당 자재에 투입 이력이 존재합니다. 자재LOT 투입 이력을 확인하세요.
                    strcpy(s_msg_code, "INV-0028");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MINVLOTISS SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }
            }


            if (DB_error_code == DB_NOT_FOUND)
            {
                memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
                TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
                memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX.LAST_TRAN_TIME));
                memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
                memcpy(MINVLOTISS.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
                MINVLOTISS.MAT_VER = CWIPINVLDM.MAT_VER;
                memcpy(MINVLOTISS.AREA_ID, CWIPINVLDM.AREA_ID, sizeof(MINVLOTISS.AREA_ID));
                memcpy(MINVLOTISS.SUB_AREA_ID, CWIPINVLDM.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID));
                memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
                memcpy(MINVLOTISS.ERP_OPER, CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
                memcpy(MINVLOTISS.OUT_OPER, CWIPINVLDM.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER));
                memcpy(MINVLOTISS.REASON_CODE, CWIPINVLDM.INPUT_TYPE, sizeof(CWIPINVLDM.INPUT_TYPE));
                MINVLOTISS.TRAN_QTY = d_UseQty;
                memcpy(MINVLOTISS.TRAN_UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                //COM_dtoa(MINVLOTISS.TRAN_UNIT, d_UnitQty, sizeof(MINVLOTISS.TRAN_UNIT));
                memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                //개발품인지, 양산품인지 여부를 저장한다.
                memcpy(MINVLOTISS.CMF_4, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

                DBU_insert_minvlotiss(&MINVLOTISS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MINVLOTISS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }

                //사용한 자재는 사용량 만큼 CV처리를 해준다.
                if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
                {
                    cv_in = TRS.add_node(in_node, "cv_in");
                    TRS.add_char(cv_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(cv_in, in_node);

                    TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTSTSX_LOAD.LOT_ID));
                    TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_LOAD.MAT_ID, sizeof(MWIPLOTSTSX_LOAD.MAT_ID));
                    TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_LOAD.OPER, sizeof(MWIPLOTSTSX_LOAD.OPER));
                    TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_LOAD.FLOW, sizeof(MWIPLOTSTSX_LOAD.FLOW));
                    TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    //TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
                    TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_LOAD.QTY_1 - MINVLOTISS.TRAN_QTY);
                    TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);

                    //gb_multi_transaction KEY는 공백으로 해준다.
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
                    memcpy(MWIPLOTSTSX_LOAD.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);

                    DBU_init_mwiplothisx(&MWIPLOTHIS_LOAD);
                    memcpy(MWIPLOTHIS_LOAD.LOT_ID, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(MWIPLOTHIS_LOAD.LOT_ID));
                    MWIPLOTHIS_LOAD.HIST_SEQ = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;
                    DBU_select_mwiplothisx(1, &MWIPLOTHIS_LOAD);

                    memset(MWIPLOTHIS_LOAD.MULTI_TR_KEY, ' ', sizeof(MWIPLOTHIS_LOAD.MULTI_TR_KEY));
                    MWIPLOTHIS_LOAD.MULTI_TR_SEQ = 0;

                    DBU_update_mwiplothisx(1, &MWIPLOTHIS_LOAD);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "MWIPLOTHIS_LOAD UPDATE", MP_NVST);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS_LOAD.LOT_ID), MWIPLOTHIS_LOAD.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }

                    if (memcmp(MWIPLOTSTSX_LOAD.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)) != MP_FALSE)
                    {
                        //LOT 추적 테이블에 저장
                        DBU_init_cwiplottrc(&CWIPLOTTRC);
                        TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
                        memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPLOTTRC.AREA_ID));
                        memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPLOTTRC.SUB_AREA_ID));
                        memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
                        memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                        CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                        memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX_LOAD.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
                        CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX_LOAD.LAST_ACTIVE_HIST_SEQ;
						memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
                        DBU_insert_cwiplottrc(&CWIPLOTTRC);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                            strcpy(s_msg_code, "ADM-0004");
                            TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
                            TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            return MP_FALSE;
                        }
                    }
                }
                else
                {
                    cv_in = TRS.add_node(in_node, "cv_in");
                    TRS.add_char(cv_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(cv_in, in_node);

                    inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
                    TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                    TRS.add_double(inv_list, "ISSUE_QTY", MINVLOTISS.TRAN_QTY);
                    TRS.add_string(cv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_nstring(cv_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_ISSUE_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                }


                /*
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
                memcpy(MWIPLOTSTSX_LOAD.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);
                */

                //A모두 사용된 자재는 LOAD 테이블에서 뺀다.
                //if (d_Qty - d_UseQty <= 0)






                 //로드된 lot을 다시 조회한다. 
                if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
                {
                    //로드된 lot정보 조회
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX_LOAD);
                    memcpy(MWIPLOTSTSX_LOAD.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LOAD);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX_LOAD.LOT_ID), MWIPLOTSTSX_LOAD.LOT_ID);

                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.category = MP_LOG_CATE_TRANS;

                        return MP_FALSE;
                    }

                    d_LoadRemainQty = MWIPLOTSTSX_LOAD.QTY_1;
                }
                else
                {
                    //로드된 lot정보 조회
                    DBU_init_minvlotsts(&MINVLOTSTS);
                    memcpy(MINVLOTSTS.FACTORY, MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY));
                    memcpy(MINVLOTSTS.INV_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    DBU_select_minvlotsts(1, &MINVLOTSTS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);

                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.category = MP_LOG_CATE_TRANS;

                        return MP_FALSE;
                    }

                    d_LoadRemainQty = MINVLOTSTS.QTY;
                }



               // if(d_LoadRemainQty == 0)
               // if (d_Qty - d_UseQty <= 0)
                if (d_LoadRemainQty == 0)
                {
                    
                    DBU_delete_cwipinvldm(1, &CWIPINVLDM);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
                        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }

                    if (memcmp(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID)) != MP_FALSE)
                    {
                        memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    }

                    

                }
                else {

                    memcpy(MINVLOTISS.FACTORY, CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY));
                    memcpy(MINVLOTISS.MAT_ID, CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID));
                    memcpy(MINVLOTISS.OPER, CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER));
                    TRS.copy(MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID), in_node, "ORDER_ID");
                    memcpy(MINVLOTISS.INV_LOT_ID, CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));


                    //20230608 일단 주석처리
                    //double i_issQty = (double)DBU_select_minvlotiss_scalar(6, &MINVLOTISS);

                    if ((double)DBU_select_minvlotiss_scalar(6, &MINVLOTISS) >= d_LdmQty)
                    {
                        //이부분에서 오류있는거 같아서 일단 주석처리
                        /*
                        
                        DBU_delete_cwipinvldm(1, &CWIPINVLDM);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                            strcpy(s_msg_code, "ADM-0004");
                            TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
                            TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            return MP_FALSE;
                        }
                        */
                        
                        if (memcmp(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID)) != MP_FALSE)
                        {
                            memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                        };
                        
                    }


                }

                if (d_RemainQty == 0)
                {
                    memcpy(s_before_mat_id, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                }
            }
        }
    }

    //to 공정이 정해지는경우 (skip 또는 재작업) to 공정이 ERP의 다음공정인 경우 
    //ERP 실적 공정이 아니더라고 자재 투입 실적을 올리도록 한다.
    if (COM_isnullspace(TRS.get_string(in_node, "TO_OPER")) == MP_FALSE)
    {
        //완료 이후 공정 정보 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
        TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF_AF.OPER, sizeof(MWIPOPRDEF_AF.OPER), in_node,"TO_OPER");
        DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);

        if (c_CheckErpResult != 'Y')
        {
            if (memcmp(MWIPOPRDEF.OPER_CMF_1, MWIPOPRDEF_AF.OPER_CMF_1, sizeof(MWIPOPRDEF_AF.OPER_CMF_1)) != MP_FALSE)
            {
                c_CheckErpResult = 'Y';
            }
        }
    }

    //컵계량 공정인 경우 첫공정이어도 무조건 자재 사용을 올려준다. 
    //컵계량 공정에서 end 이후 바로 split되어 다음 lot으로 자재 소모를 올려줄 수 없기 때문
    if (TRS.get_char(in_node, "MUST_ISSUE_YN") == 'Y')
        c_CheckErpResult = 'Y';

    //일반 생산품인 경우 erp 인터페이스 
    if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
    {
        //ERP실적공정에만 자재 소모량을 ERP에 올려준다.
        if (c_CheckErpResult == 'Y')
        {
            DBU_init_minvlotiss(&MINVLOTISS);
            memcpy(MINVLOTISS.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
            memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            memcpy(MINVLOTISS.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MINVLOTISS.ERP_OPER));
            memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            DBU_open_minvlotiss(4, &MINVLOTISS);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            while (1)
            {
                DBU_fetch_minvlotiss(4, &MINVLOTISS);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_minvlotiss(4);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                    strcpy(s_msg_code, "WIP-0585");
                    TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_minvlotiss(4);
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //임시 코드. erp에 수동으로 전송한 경우 'n'이 들어가 있어 해당 자재 소비 정보는 erp에 올려주지 않는다. 
                if (MINVLOTISS.TRAN_UNIT_3[0] == 'N')
                    continue;

                //이미 ERP전송된것은 중복으로 올라가지 않도록 CMF_1을 체크한다.
                if (MINVLOTISS.CMF_1[0] == 'Y')
                    continue;

                //자재 정보 조회
                DBU_init_mwipmatdef(&MWIPMATDEF);
                TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPMATDEF.MAT_ID, MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
                MWIPMATDEF.MAT_VER = 1;
                DBU_select_mwipmatdef(1, &MWIPMATDEF);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0006 : 이 제품은 존재 하지 않습니다.
                    strcpy(s_msg_code, "WIP-0006");
                    TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }

                //생성된 LOT ID 또는 Client에서 받은 LOT ID에 대한 정보를 조회한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_ISS);
                memcpy(MWIPLOTSTSX_ISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_ISS);
                if (DB_error_code == DB_SUCCESS)
                {
                    //투입 자재가 테스트품인 경우 자재소모 인터페이스를 태우지 않는다.
                    if (MWIPLOTSTSX_ISS.LOT_TYPE == MP_LOT_TYPE_T)
                        continue;

                    if (memcmp(MINVLOTISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)) != MP_FALSE)
                    {
                        DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                        memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
                        memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
                        DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

                        if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
                        {
                            //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                            strcpy(s_msg_code, "WIP-0646");
                            TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                            TRS.add_dberrmsg(out_node, DB_error_msg);
                            return MP_FALSE;
                        }

                        if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
                        {
                            //20250526 출하전 제품창고에서 투입처리되는거 막음
                           //INV - 0079 : 제품창고에서는  투입처리 할 수 없습니다.창고 이동 후 투입처리를 진행해 주세요.
                            strcpy(s_msg_code, "INV-0079");
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);

                            gs_log_type.type = MP_LOG_ERROR;
                            gs_log_type.e_type = MP_LOG_E_SYSTEM;
                            gs_log_type.category = MP_LOG_CATE_VIEW;

                            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                            return MP_FALSE;
                        }

                    }
                    else
                    {
                        DBU_init_mwiplothisx(&MWIPLOTHISX_ISS);
                        memcpy(MWIPLOTHISX_ISS.LOT_ID, MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
                        memcpy(MWIPLOTHISX_ISS.TRAN_CODE, MP_TRAN_CODE_ADAPT, strlen(MP_TRAN_CODE_ADAPT));
                        DBU_select_mwiplothisx(5, &MWIPLOTHISX_ISS);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                            strcpy(s_msg_code, "WIP-0646");
                            TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                            TRS.add_dberrmsg(out_node, DB_error_msg);
                            return MP_FALSE;
                        }

                        DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                        memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
                        memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTHISX_ISS.OLD_OPER, sizeof(MWIPLOTHISX_ISS.OLD_OPER));
                        DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);
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
                    }
                }
                else if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_init_minvlotsts(&MINVLOTSTS_ISS);
                    memcpy(MINVLOTSTS_ISS.FACTORY, MINVLOTISS.FACTORY, sizeof(MINVLOTSTS_ISS.FACTORY));
                    memcpy(MINVLOTSTS_ISS.INV_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTSTS_ISS.LOT_ID));
                    DBU_select_minvlotsts(1, &MINVLOTSTS_ISS);

                    DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                    memcpy(MWIPOPRDEF_ISS.FACTORY, MINVLOTSTS_ISS.FACTORY, sizeof(MINVLOTSTS_ISS.FACTORY));
                    memcpy(MWIPOPRDEF_ISS.OPER, MINVLOTSTS_ISS.OPER, sizeof(MINVLOTSTS_ISS.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

                    if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
                    {
                        //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                        strcpy(s_msg_code, "WIP-0646");
                        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }



                ///베트남은 저장품은 자재투입을  기타출고로 처리한다.
               // if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_STORED_GOODS, strlen(MP_MAT_TYPE_STORED_GOODS)) == 0 && memcmp(MWIPMATDEF.FACTORY, "IJDV1", strlen("IJDV1")) == 0) {

                 ///20230313 베트남은 저장품은 자재투입을  기타출고로 처리한다.(문제는 없을것으로 보여서 일단 한국도 가능하게는 해놓음)
                if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_STORED_GOODS, strlen(MP_MAT_TYPE_STORED_GOODS)) == 0) {
                    //기타출고 계정 가져온다.
                    DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
                    TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
                    memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE", strlen("TEST_ITEM_ISSUE"));
                    memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                    memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);


                    if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0){
                        //기타출고 계정 가져온다.
                        DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
                        TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
                        memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE2", strlen("TEST_ITEM_ISSUE2"));
                        memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                        memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);

                    if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
                    {

                        //기타출고 계정 가져온다.
                        DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
                        TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
                        memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
                        memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                      //  memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                        memcpy(MGCMTBLDAT_TYPE.KEY_2, " ", sizeof(" "));
                        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            strcpy(s_msg_code, "WIP-0004");
                            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(3)", MP_NVST);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
                            TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
                            TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            gs_log_type.type = MP_LOG_ERROR;
                            gs_log_type.e_type = MP_LOG_E_SYSTEM;
                            gs_log_type.category = MP_LOG_CATE_VIEW;

                            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                            return MP_FALSE;
                        }

                    }

                    }


                    //기타 출고 코드 확인
                    DBU_init_cbastxndef(&CBASTXNDEF_ETC);
                    TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
                    CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_3, sizeof(MGCMTBLDAT_TYPE.DATA_3));
                    CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));
                    DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF_ETC.FACTORY), CBASTXNDEF_ETC.FACTORY);
                        TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF_ETC.TRAN_TYPE_ID);
                        TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF_ETC.ERP_AREA_ID);
                        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //ETC OUT 한글명 가져옴
                    DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
                    TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
                    memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
                    memcpy(MGCMTBLDAT_SRC.KEY_1, "ETC_OUT", strlen("ETC_OUT"));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        if (DB_error_code == DB_NOT_FOUND)
                        {
                            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                            strcpy(s_msg_code, "GCM-0008");
                            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
                        }
                        else
                        {
                            strcpy(s_msg_code, "INV-0004");
                            gs_log_type.e_type = MP_LOG_E_SYSTEM;
                            TRS.add_dberrmsg(out_node, DB_error_msg);
                        }

                        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
                        TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
                        TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }


                    //기타 입출고 이력 테이블 저장
                    DBU_init_minvetclot(&MINVETCLOT);
                    TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
                    memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    DBU_select_minvetclot(2, &MINVETCLOT);

                    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
                    {
                        strcpy(s_msg_code, "INV-0004");
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.category = MP_LOG_CATE_TRANS;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //기타입고 정보 저장
                    TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
                    memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        MINVETCLOT.SEQ = 1;
                    }
                    else
                    {
                        MINVETCLOT.SEQ += 1;
                    }

                    if (i_LotType == 1)
                        memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
                    else if (i_LotType == 2)
                        memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));

                    MINVETCLOT.QTY = MINVLOTISS.TRAN_QTY;
                    memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
                    memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
                    memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF_ISS.SUB_AREA_ID, sizeof(MWIPOPRDEF_ISS.SUB_AREA_ID));
                    memcpy(MINVETCLOT.OPER, MWIPOPRDEF_ISS.OPER, sizeof(MWIPOPRDEF_ISS.OPER));
                    memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
                    MINVETCLOT.VENDOR_SITE_ID = 0;
                    memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
                    memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_OUT, sizeof(MINVETCLOT.ETC_TYPE));
                    memcpy(MINVETCLOT.ETC_DATE, MWIPLOTSTSX.LAST_TRAN_TIME, 8);
                    MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
                    memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
                    memcpy(MINVETCLOT.ETC_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

                    //211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
                    //211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
                    memcpy(MINVETCLOT.CMF_1, "C", strlen("C"));
                    memcpy(MINVETCLOT.CMF_2, MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));
                    memcpy(MINVETCLOT.CMF_3, MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
                    //20240215 자재리턴시 필요해서 HIST_SEQ추가
                    memset(c_Iss_cmf4, ' ', sizeof(c_Iss_cmf4));
                    sprintf(c_Iss_cmf4, "%d", MINVLOTISS.HIST_SEQ);
                    memcpy(MINVETCLOT.CMF_4, c_Iss_cmf4, sizeof(MINVETCLOT.CMF_4));


                    TRS.copy(MINVETCLOT.CREATE_USER_ID, sizeof(MINVETCLOT.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(MINVETCLOT.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                    TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

                    // 기타 입고 정보 생성
                    DBU_insert_minvetclot(&MINVETCLOT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "INV-0004");
                        TRS.add_fieldmsg(out_node, "MINVETCLOT INSERT/UPDATE", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVETCLOT.FACTORY), MINVETCLOT.FACTORY);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_COMMON;
                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //ERP 실적 - IF_INV_TXNS
                    inv_if = TRS.add_node(in_node, "inv_if");
                    TRS.add_char(inv_if, IN_PROCSTEP, '1');
                    CopyDefaultMembers(inv_if, in_node);

                    TRS.add_char(inv_if, "TRAN_FLAG", 'I');
                    //TRS.add_int(inv_if, "TRAN_TYPE_ID", CBASTXNDEF_ETC.TRAN_TYPE_ID);
                    //TRS.add_string(inv_if, "TRAN_TYPE", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));

                    TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_1));
                    TRS.add_string(inv_if, "TRAN_TYPE", "Account issue", sizeof("Account issue"));

                    TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
                    TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
                    TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
                    TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
                    TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(inv_if, "FROM_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
                    TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_double(inv_if, "QTY", -1 * MINVLOTISS.TRAN_QTY);
                    TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
                    TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    DBU_init_if_inv_txns(&IF_INV_TXNS);
                    TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
                    memcpy(IF_INV_TXNS.MES_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

                    d_ifseq = (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

                    //ERP 실적 - IF_INV_TXN_LOTS
                    inv_if = TRS.add_node(in_node, "inv_if");
                    TRS.add_char(inv_if, IN_PROCSTEP, '1');
                    CopyDefaultMembers(inv_if, in_node);

                    TRS.add_char(inv_if, "TRAN_FLAG", 'I');
                    TRS.add_double(inv_if, "INV_TXNS_ID", d_ifseq);
                    TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(inv_if, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)); //추후 맞는 데이터가 들어옴
                    TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_INV_TXN_LOTS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    memset(c_if_seq, ' ', sizeof(c_if_seq));
                    sprintf(c_if_seq, "%.0f", d_ifseq);

                    //인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
                    MINVLOTISS.CMF_1[0] = 'Y';
                    memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
                    DBU_update_minvlotiss(1, &MINVLOTISS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "CMN-0004");
                        TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                        return MP_FALSE;
                    }






                }
                else {


                    inv_if = TRS.add_node(in_node, "inv_if");
                    TRS.add_char(inv_if, IN_PROCSTEP, '1');
                    CopyDefaultMembers(inv_if, in_node);

                    TRS.add_char(inv_if, "TRAN_FLAG", 'I');
                    TRS.add_string(inv_if, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.add_int(inv_if, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
                    TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
                    TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
                    TRS.add_string(inv_if, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                    TRS.add_int(inv_if, "ERP_SUB_AREA_ID", COM_atoi(MGCMTBLDAT_SUB_AREA.DATA_8, sizeof(MGCMTBLDAT_SUB_AREA.DATA_8)));
                    TRS.add_int(inv_if, "OPER_SEQ", CWIPERPOPR.OPER_SEQ);
                    TRS.add_string(inv_if, "OPER", CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
                    //TRS.add_string(inv_if, "INV_OPER", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
                    TRS.add_string(inv_if, "INV_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
                    TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);
                    TRS.add_string(inv_if, "CMF_1", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");

                    if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, inv_if, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    d_ifseq = TRS.get_double(cmn_out, "IF_SEQ");

                    TRS.free_node(cmn_out);

                    memset(c_if_seq, ' ', sizeof(c_if_seq));
                    sprintf(c_if_seq, "%.0f", d_ifseq);

                    //인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
                    MINVLOTISS.CMF_1[0] = 'Y';
                    memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
                    DBU_update_minvlotiss(1, &MINVLOTISS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "CMN-0004");
                        TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                        return MP_FALSE;
                    }
                }









            }
        }
    }
    //테스트 품인 경우 투입처리한 해당 공정에서 기타 출고로 erp에 올린다.
    else if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
    {
        //기타 출고 명칭 가져온다.
        DBU_init_cbastxndef(&CBASTXNDEF);
        TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
        CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_1);
        CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));
        DBU_select_cbastxndef(2, &CBASTXNDEF);

        if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
            TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (DB_error_code == DB_NOT_FOUND)
        {
            //해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
            //MST(ERP AREA ID : 103)
            //임시로 하드코딩
            DBU_init_cbastxndef(&CBASTXNDEF);
            TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
            CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_1);
            CBASTXNDEF.ERP_AREA_ID = 103;
            DBU_select_cbastxndef(2, &CBASTXNDEF);

            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
                TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }



        DBU_init_minvlotiss(&MINVLOTISS);
        memcpy(MINVLOTISS.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        memcpy(MINVLOTISS.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
        memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));        
        DBU_open_minvlotiss(5, &MINVLOTISS);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
            strcpy(s_msg_code, "WIP-0585");
            TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
            TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        while (1)
        {
            DBU_fetch_minvlotiss(5, &MINVLOTISS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_minvlotiss(5);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
                TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_minvlotiss(5);
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }


            //20230109 품목별 개발품에 대한 자재소진시  기타입출고 정보를 관리하기로 변경
// 품목별로 먼저 조회하고 없으면,공통으로 변경
//기타출고 계정 가져온다.
            DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
            TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
            memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE", strlen("TEST_ITEM_ISSUE"));
            memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
            memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);


            if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
            {
                //20230109 품목별 개발품에 대한 자재소진시  기타입출고 정보를 관리하기로 변경
                // 품목별로 먼저 조회하고 없으면,공통으로 변경
                //기타출고 계정 가져온다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
                TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE2", strlen("TEST_ITEM_ISSUE2"));
                memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                memcpy(MGCMTBLDAT_TYPE.KEY_2, MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);





                if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
                {

                    //기타출고 계정 가져온다.
                    DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
                    TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
                    memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
                    memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                    memcpy(MGCMTBLDAT_TYPE.KEY_2, " ", sizeof(" "));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
                        TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
                        TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                }
            }






            //기타 출고 코드 확인
            DBU_init_cbastxndef(&CBASTXNDEF_ETC);
            TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
            CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_3, sizeof(MGCMTBLDAT_TYPE.DATA_3));
            CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));
            DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF_ETC.FACTORY), CBASTXNDEF_ETC.FACTORY);
                TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF_ETC.TRAN_TYPE_ID);
                TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF_ETC.ERP_AREA_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //ETC OUT 한글명 가져옴
            DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
            TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
            memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
            memcpy(MGCMTBLDAT_SRC.KEY_1, "ETC_OUT", strlen("ETC_OUT"));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    gs_log_type.e_type = MP_LOG_E_EXISTENCE;
                }
                else
                {
                    strcpy(s_msg_code, "INV-0004");
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                }

                TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
                TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }




            //이미 ERP전송된것은 중복으로 올라가지 않도록 CMF_1을 체크한다.
            if (MINVLOTISS.CMF_1[0] == 'Y')
                continue;

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
            memcpy(MWIPMATDEF.MAT_ID, MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            i_LotType = 0;

            //생성된 LOT ID 또는 Client에서 받은 LOT ID에 대한 정보를 조회한다.
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_ISS);
            memcpy(MWIPLOTSTSX_ISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_ISS);
            if (DB_error_code == DB_SUCCESS)
            {
                i_LotType = 1;

                //투입 자재가 테스트품인 경우 기타 출고 인터페이스를 태우지 않는다.
                if (MWIPLOTSTSX_ISS.LOT_TYPE == MP_LOT_TYPE_T)
                    continue;

                if (memcmp(MINVLOTISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)) != MP_FALSE)
                {
                    DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                    memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
                    memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

                    if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
                    {
                        //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                        strcpy(s_msg_code, "WIP-0646");
                        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
                else
                {
                    DBU_init_mwiplothisx(&MWIPLOTHISX_ISS);
                    memcpy(MWIPLOTHISX_ISS.LOT_ID, MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
                    memcpy(MWIPLOTHISX_ISS.TRAN_CODE, MP_TRAN_CODE_ADAPT, strlen(MP_TRAN_CODE_ADAPT));
                    DBU_select_mwiplothisx(5, &MWIPLOTHISX_ISS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                        strcpy(s_msg_code, "WIP-0646");
                        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }

                    DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                    memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
                    memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTHISX_ISS.OLD_OPER, sizeof(MWIPLOTHISX_ISS.OLD_OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);
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
                }
            }
            else if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_init_minvlotsts(&MINVLOTSTS_ISS);
                memcpy(MINVLOTSTS_ISS.FACTORY, MINVLOTISS.FACTORY, sizeof(MINVLOTSTS_ISS.FACTORY));
                memcpy(MINVLOTSTS_ISS.INV_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTSTS_ISS.LOT_ID));
                DBU_select_minvlotsts(1, &MINVLOTSTS_ISS);

                DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
                memcpy(MWIPOPRDEF_ISS.FACTORY, MINVLOTSTS_ISS.FACTORY, sizeof(MINVLOTSTS_ISS.FACTORY));
                memcpy(MWIPOPRDEF_ISS.OPER, MINVLOTSTS_ISS.OPER, sizeof(MINVLOTSTS_ISS.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

                if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
                {
                    //WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0646");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    return MP_FALSE;
                }

                i_LotType = 2;
            }

            //기타 출고의 창고는 ISS테이블의 OUT OPER (창고)로 처리 되도록 한다.
            DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
            memcpy(MWIPOPRDEF_ISS.FACTORY, MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY));
            memcpy(MWIPOPRDEF_ISS.OPER, MINVLOTISS.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0010 : 이 공정은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF_ISS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }


            //기타 입출고 이력 테이블 저장
            DBU_init_minvetclot(&MINVETCLOT);
            TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
            memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
            DBU_select_minvetclot(2, &MINVETCLOT);

            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "INV-0004");
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                TRS.add_dberrmsg(out_node, DB_error_msg);
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //기타입고 정보 저장
            TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
            memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

            if (DB_error_code == DB_NOT_FOUND)
            {
                MINVETCLOT.SEQ = 1;
            }
            else
            {
                MINVETCLOT.SEQ += 1;
            }

            if(i_LotType == 1)
                memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
            else if (i_LotType == 2)
                memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));

            MINVETCLOT.QTY = MINVLOTISS.TRAN_QTY;
            memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
            memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
            memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF_ISS.SUB_AREA_ID, sizeof(MWIPOPRDEF_ISS.SUB_AREA_ID));            
            memcpy(MINVETCLOT.OPER, MWIPOPRDEF_ISS.OPER, sizeof(MWIPOPRDEF_ISS.OPER));
            memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
            MINVETCLOT.VENDOR_SITE_ID = 0;
            memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
            memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_OUT, sizeof(MINVETCLOT.ETC_TYPE));
            memcpy(MINVETCLOT.ETC_DATE, MWIPLOTSTSX.LAST_TRAN_TIME, 8);
            MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
            memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
            memcpy(MINVETCLOT.ETC_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

			//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
			//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS),E(기타출고로 설정한 자재투입)
			memcpy(MINVETCLOT.CMF_1, "C", strlen("C"));
			memcpy(MINVETCLOT.CMF_2, MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));
			memcpy(MINVETCLOT.CMF_3, MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
            //20240215 자재리턴시 필요해서 HIST_SEQ추가
            memset(c_Iss_cmf4, ' ', sizeof(c_Iss_cmf4));
            sprintf(c_Iss_cmf4, "%d", MINVLOTISS.HIST_SEQ);
            memcpy(MINVETCLOT.CMF_4, c_Iss_cmf4, sizeof(MINVETCLOT.CMF_4));


            TRS.copy(MINVETCLOT.CREATE_USER_ID, sizeof(MINVETCLOT.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVETCLOT.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
            TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

            // 기타 입고 정보 생성
            DBU_insert_minvetclot(&MINVETCLOT);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "INV-0004");
                TRS.add_fieldmsg(out_node, "MINVETCLOT INSERT/UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVETCLOT.FACTORY), MINVETCLOT.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_COMMON;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //ERP 실적 - IF_INV_TXNS
            inv_if = TRS.add_node(in_node, "inv_if");
            TRS.add_char(inv_if, IN_PROCSTEP, '1');
            CopyDefaultMembers(inv_if, in_node);

            TRS.add_char(inv_if, "TRAN_FLAG", 'I');
            TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_1));
            TRS.add_string(inv_if, "TRAN_TYPE", "Account issue", sizeof("Account issue"));


            TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
            TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
            TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
            TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
            TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
            TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_string(inv_if, "FROM_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));          
            TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_double(inv_if, "QTY", -1 * MINVLOTISS.TRAN_QTY);
            TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
            TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            DBU_init_if_inv_txns(&IF_INV_TXNS);
            TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
            memcpy(IF_INV_TXNS.MES_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

            d_ifseq = (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

            //ERP 실적 - IF_INV_TXN_LOTS
            inv_if = TRS.add_node(in_node, "inv_if");
            TRS.add_char(inv_if, IN_PROCSTEP, '1');
            CopyDefaultMembers(inv_if, in_node);

            TRS.add_char(inv_if, "TRAN_FLAG", 'I');
            TRS.add_double(inv_if, "INV_TXNS_ID", d_ifseq);
            TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
            TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_string(inv_if, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
            TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)); //추후 맞는 데이터가 들어옴
            TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_INV_TXN_LOTS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            memset(c_if_seq, ' ', sizeof(c_if_seq));
            sprintf(c_if_seq, "%.0f", d_ifseq);

            //인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
            MINVLOTISS.CMF_1[0] = 'Y';
            memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
            DBU_update_minvlotiss(1, &MINVLOTISS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}



/*******************************************************************************
TRANS_ERP_INFO()
- ERP로 실적 데이터를 보낼지 체크한다.
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- string sLot
- TRSNode *in_node : In Node from each transaction function
- TRSNode *out_node : Common out node for result message
*******************************************************************************/
int TRANS_ERP_INFO(char *c_CheckErpResult, char *c_CheckErpInput, char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;       //작업지시 마스터 테이블
    struct MWIPFLWOPR_TAG MWIPFLWOPR;       //flow-oper 맵핑 테이블
    struct MWIPOPRDEF_TAG MWIPOPRDEF;       //공정 마스터 테이블
    struct CWIPERPOPR_TAG CWIPERPOPR;       //작업지시 ERP공정 테이블

    int i_step = 0;
    char c_ErpOper[30];

    LOG_head("TRANS_ERP_INFO");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    //작업지시 조회
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

    //공정 조회
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

    memcpy(c_ErpOper, MWIPOPRDEF.OPER_CMF_1, sizeof(c_ErpOper));

    i_step = 2;

    DBU_init_mwipflwopr(&MWIPFLWOPR);
    TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPFLWOPR.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
    DBU_open_mwipflwopr(i_step, &MWIPFLWOPR);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0014 : 이 공정은 FLOW에 속해 있지 않습니다.
        strcpy(s_msg_code, "WIP-0014");
        TRS.add_fieldmsg(out_node, "MWIPORDSTS OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
        TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_mwipflwopr(i_step, &MWIPFLWOPR);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_mwipflwopr(i_step);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0014 : 이 공정은 FLOW에 속해 있지 않습니다.
            strcpy(s_msg_code, "WIP-0014");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS FETCH", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            DBU_close_mwipflwopr(i_step);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        memcpy(MWIPOPRDEF.FACTORY, MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
        memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
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
        
        //MWIPFLWOPR 에서 seq_num를 역순으로 조회하여 첫번째로 erp 공정이 같은 것이 erp 실적 업로드 공정이다. 
        if (memcmp(MWIPOPRDEF.OPER_CMF_1, c_ErpOper, sizeof(c_ErpOper)) == MP_FALSE)
        {
            //역순의 첫 번째 공정과 현재 실적 공정을 비교하여 같으면 erp 실적 전송하고, 다르면 erp실적을 전송하지 않는다. 
            if (memcmp(MWIPFLWOPR.OPER, TRS.get_string(in_node, "OPER"), strlen(TRS.get_string(in_node, "OPER"))) == MP_FALSE)
            {
                //ERP공정이 존재하는지 체크한다.
                DBU_init_cwiperpopr(&CWIPERPOPR);
                memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
                memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
                memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
                DBU_select_cwiperpopr(2, &CWIPERPOPR);
                if (DB_error_code == DB_SUCCESS)
                {
                    *c_CheckErpResult = 'Y';

                    //erp작업지시의 마지막 공정에서는 투입정보를 I/F 한다.
                    if (CWIPERPOPR.LAST_FLAG == 'Y')                       
                        *c_CheckErpInput = 'Y';
                    else 
                        *c_CheckErpInput = 'N';
                }
                else
                {
                    *c_CheckErpResult = 'N';
                    *c_CheckErpInput = 'N';
                }

                DBU_close_mwipflwopr(i_step);
                break;
            }
            else
            {
                *c_CheckErpResult = 'N';
                *c_CheckErpInput = 'N';
                DBU_close_mwipflwopr(i_step);
                break;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
    Update_Resource_Status()
        - 설비 상태를 변경한다.
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - string sLot
        - TRSNode *in_node : In Node from each transaction function
        - TRSNode *out_node : Common out node for result message
*******************************************************************************/
int Update_Resource_Status(char *s_msg_code, char *s_factory, char *s_res_id, char c_res_sts, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct CWIPDWNSTS_TAG CWIPDWNSTS;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MRASTOLDEF_TAG  MRASTOLDEF;
    struct MRASTOLEVN_TAG  MRASTOLEVN;

    struct work_date_tag work_date;
    //char s_factory[10];
    TRSNode  *tool_in;
    TRSNode  *cmn_out;
    int iStep = 0;

    DBU_init_mrasresdef(&MRASRESDEF);
    memcpy(MRASRESDEF.FACTORY, s_factory, sizeof(MRASRESDEF.FACTORY));
    memcpy(MRASRESDEF.RES_ID, s_res_id, sizeof(MRASRESDEF.RES_ID));
    DBU_select_mrasresdef(1, &MRASRESDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        if(DB_error_code == DB_NOT_FOUND)
        {
            // RAS-0003 : 존재하지 않는 장비입니다.
            strcpy(s_msg_code, "RAS-0003");
        }
        else
        {
            strcpy(s_msg_code, "RAS-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MRASRESDEF Select 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        return MP_FALSE;
    }

    if (MRASRESDEF.DELETE_FLAG == 'Y')
    {
        //RAS-0119 : 이 장비는 삭제되었습니다.
        strcpy(s_msg_code, "RAS-0119");

        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        TRS.add_fieldmsg(out_node, "DELETE_FLAG", DT_CHAR, MRASRESDEF.DELETE_FLAG);
        TRS.add_fieldmsg(out_node, "DELETE_USER_ID", DT_STRING, sizeof(MRASRESDEF.DELETE_USER_ID), MRASRESDEF.DELETE_USER_ID);
        TRS.add_fieldmsg(out_node, "DELETE_TIME", DT_STRING, sizeof(MRASRESDEF.DELETE_TIME), MRASRESDEF.DELETE_TIME);

        return MP_FALSE;
    }

    // 1. Start Lot 시 설비 상태를 U 변경
    // 2. End Lot 시 설비 상태를 I 변경
    //  R : Up, D : Down, I : Idle
    if (c_res_sts == 'R')
    {
        //비가동 등록된 설비인 경우 비가동 정보를 완료 시켜준다.
        DBU_init_cwipdwnsts(&CWIPDWNSTS);
        memcpy(CWIPDWNSTS.FACTORY, MRASRESDEF.FACTORY, sizeof(CWIPDWNSTS.FACTORY));
        memcpy(CWIPDWNSTS.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        CWIPDWNSTS.DOWN_STATUS = 'S';
        DBU_select_cwipdwnsts(2, &CWIPDWNSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            //TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
            //memcpy(s_factory, MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY));
            memset(&work_date, ' ', sizeof(work_date));
            Get_shift(s_factory, &work_date);

            memcpy(CWIPDWNSTS.DOWN_END_TIME, gs_sys_time, sizeof(CWIPDWNSTS.DOWN_END_TIME));
            memcpy(CWIPDWNSTS.DOWN_END_DATE, work_date.s_work_date, sizeof(CWIPDWNSTS.DOWN_END_DATE));
            memcpy(CWIPDWNSTS.DOWN_END_DAY_NIGHT, work_date.s_day_night, sizeof(CWIPDWNSTS.DOWN_END_DAY_NIGHT));
            CWIPDWNSTS.DOWN_STATUS = 'E'; //END상태

            memcpy(CWIPDWNSTS.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
            memcpy(CWIPDWNSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPDWNSTS.UPDATE_TIME));

            DBU_update_cwipdwnsts(1, &CWIPDWNSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CWIPDWNSTS UPDATE(1)", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
                TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
                TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

                return MP_FALSE;
            }
        }

        // 설비 상태 변경 여부 확인
        //   - 현재는 래핑기를 제외하고 설비 상태 변경
        //   - 래핑기는 EIS(Equipment Interface Server)를 통해서 설비 상태를 변경하고 있음
        if (MRASRESDEF.RES_CMF_2[0] != 'Y')
        {
            memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));
            MRASRESDEF.RES_PRI_STS[0] = c_res_sts;
            MRASRESDEF.RES_UP_DOWN_FLAG = 'U';

            memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time)); // 설비 상태 변경 일시
            DBU_update_mrasresdef(2, &MRASRESDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

                return MP_FALSE;
            }
        }
    }        
    else if (c_res_sts == 'I')
    {
        //- 현재는 래핑기를 제외하고 설비 상태 변경
        //래핑기의 설비 인터페이스가 원활하지 않아 end시 lot이 걸려있는지 체크 하고 설비 상태값 변경
			
        if (MRASRESDEF.RES_CMF_2[0] == 'Y' || MRASRESDEF.RES_CMF_9[0] == 'Y')
        {
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            memcpy(MWIPLOTSTSX.START_RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));

            if (DBU_select_mwiplotstsx_scalar(3, &MWIPLOTSTSX) > 0 || MRASRESDEF.RES_CMF_9[0] == 'Y')
            {
                //return MP_TRUE;
				memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));

				MRASRESDEF.RES_PRI_STS[0] = 'R';
				MRASRESDEF.RES_UP_DOWN_FLAG = 'U';
				memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time)); // 설비 상태 변경 일시

				DBU_update_mrasresdef(2, &MRASRESDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

					return MP_FALSE;
				}
            }
			else
			{
				memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));

				MRASRESDEF.RES_PRI_STS[0] = c_res_sts;
				MRASRESDEF.RES_UP_DOWN_FLAG = 'U';
				memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time)); // 설비 상태 변경 일시

				DBU_update_mrasresdef(2, &MRASRESDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

					return MP_FALSE;
				}
			}
        }
		else
		{
			memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));

			MRASRESDEF.RES_PRI_STS[0] = c_res_sts;
			MRASRESDEF.RES_UP_DOWN_FLAG = 'U';
			memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time)); // 설비 상태 변경 일시

			DBU_update_mrasresdef(2, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

				return MP_FALSE;
			}
		}

        iStep = 2;

        //툴 사용횟수 증가
        DBU_init_mrastoldef(&MRASTOLDEF);
        memcpy(MRASTOLDEF.FACTORY, MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY));
        memcpy(MRASTOLDEF.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        DBU_open_mrastoldef(iStep, &MRASTOLDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //RAS-0168 : TOOL 이 존재하지 않습니다.
            strcpy(s_msg_code, "RAS-0168");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "TOOL_ID", DT_STRING, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
            TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASTOLDEF.RES_ID), MRASTOLDEF.RES_ID);

            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_TRANS;

            return MP_FALSE;
        }
        while (1)
        {
            DBU_fetch_mrastoldef(iStep, &MRASTOLDEF);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBC_close_mrastoldef(iStep);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                // Unexpected Fetch error
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "MRASTOLDEF FETCH", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "TOOL_ID", DT_STRING, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
                TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASTOLDEF.RES_ID), MRASTOLDEF.RES_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_TRANS;

                DBC_close_mrastoldef(iStep);

                return MP_FALSE;
            }

            if (MRASTOLDEF.TOOL_STS_1[0] != ' ')
            {
                if (COM_isnullspace(TRS.get_string(in_node, "CAR")) == MP_FALSE)
                {
                    if (TRS.mem_cmp(in_node, "CAR", MRASTOLDEF.TOOL_STS_1, sizeof(MRASTOLDEF.TOOL_STS_1)) != MP_FALSE)
                    {
                        continue;
                    }
                }
            }

            DBC_init_mrastolevn(&MRASTOLEVN);
            memcpy(MRASTOLEVN.FACTORY, MRASRESDEF.FACTORY, sizeof(MRASTOLEVN.FACTORY));
            memcpy(MRASTOLEVN.TOOL_EVENT_ID, MP_TOOL_EVENT_COUNT, strlen(MP_TOOL_EVENT_COUNT));
            memcpy(MRASTOLEVN.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
            memcpy(MRASTOLEVN.TOOL_TYPE, MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
            DBC_select_mrastolevn(1, &MRASTOLEVN);
            if (DB_error_code == DB_SUCCESS)
            {
                //툴 사용횟수 증가.
                tool_in = TRS.create_node("tool_in");
                TRS.add_char(tool_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(tool_in, in_node);

                TRS.add_string(tool_in, "TOOL_EVENT_ID", MRASTOLEVN.TOOL_EVENT_ID, sizeof(MRASTOLEVN.TOOL_EVENT_ID));
                TRS.add_string(tool_in, "TOOL_ID", MRASTOLEVN.TOOL_ID, sizeof(MRASTOLEVN.TOOL_ID));
                TRS.add_string(tool_in, "TOOL_TYPE", MRASTOLEVN.TOOL_TYPE, sizeof(MRASTOLEVN.TOOL_TYPE));

                TRS.add_nstring(tool_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_nstring(tool_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_RAS_TOOL_EVENT(s_msg_code, tool_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(tool_in);
                    TRS.free_node(cmn_out);

                    DBC_close_mrastoldef(iStep);

                    return MP_FALSE;
                }
                TRS.free_node(tool_in);
                TRS.free_node(cmn_out);
            }
        }
    }
    
    return MP_TRUE;
}

/*******************************************************************************
    Update_Lot_Summary()
        - Lot 별 실적 집계
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Common out node for result message
*******************************************************************************/
int Update_Lot_Summary(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    char isDelete;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CSUMLOTDAT_TAG CSUMLOTDAT;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS_T;
    struct MWIPLOTLOS_TAG MWIPLOTLOS;

    struct work_date_tag work_date;

    int i_db_error_code = 0;
    int i_hist_seq = 0;

    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    // Lot 이력 삭제 여부
    isDelete = TRS.get_char(in_node, "IS_DELETE");

    if(isDelete == ' ')
    {
        DBU_init_mwiplothisx(&MWIPLOTHIS);
        memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID));
        MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;

        DBU_select_mwiplothisx(1, &MWIPLOTHIS);

        DBU_init_csumlotdat(&CSUMLOTDAT);
        memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));

        if (TRS.mem_cmp(in_node, "TRAN_CODE", "START", strlen("START")) == 0)
        {
            CSUMLOTDAT.START_HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;
            memcpy(CSUMLOTDAT.OPER, MWIPLOTSTS.OPER, sizeof(CSUMLOTDAT.OPER));
            DBU_select_csumlotdat(1, &CSUMLOTDAT);
            i_db_error_code = DB_error_code;

            CSUMLOTDAT.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
            memcpy(CSUMLOTDAT.RES_ID, MWIPLOTSTS.START_RES_ID, sizeof(CSUMLOTDAT.RES_ID));

            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));

            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            memcpy(CSUMLOTDAT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMLOTDAT.AREA_ID));
            memcpy(CSUMLOTDAT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMLOTDAT.SUB_AREA_ID));
            memcpy(CSUMLOTDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMLOTDAT.FACTORY));
            memcpy(CSUMLOTDAT.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMLOTDAT.MAT_ID));
            memcpy(CSUMLOTDAT.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMLOTDAT.FLOW));
            CSUMLOTDAT.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
            memcpy(CSUMLOTDAT.OPER, MWIPLOTSTS.OPER, sizeof(CSUMLOTDAT.OPER));
            CSUMLOTDAT.IN_QTY = MWIPLOTSTS.QTY_1;
            memcpy(CSUMLOTDAT.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMLOTDAT.UNIT));
            memcpy(CSUMLOTDAT.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMLOTDAT.ORDER_ID));
            memcpy(CSUMLOTDAT.START_DATE, work_date.s_work_date, sizeof(CSUMLOTDAT.START_DATE));
            memcpy(CSUMLOTDAT.START_TIME, gs_sys_time, sizeof(CSUMLOTDAT.START_TIME));
            memcpy(CSUMLOTDAT.START_DAY_NIGHT, work_date.s_day_night, sizeof(CSUMLOTDAT.START_DAY_NIGHT));

            if(i_db_error_code == DB_SUCCESS)
            {
                TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                DBU_update_csumlotdat(1, &CSUMLOTDAT);
                if(DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_fieldmsg(out_node, "CSUMLOTDAT Update 1", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                    TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
            else if(i_db_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CSUMLOTDAT.CREATE_USER_ID, sizeof(CSUMLOTDAT.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CSUMLOTDAT.CREATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.CREATE_TIME));                
                memcpy(CSUMLOTDAT.CMF_2, MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));
                
                DBU_insert_csumlotdat(&CSUMLOTDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_fieldmsg(out_node, "CSUMLOTDAT Insert", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                    TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;                    
                }
            }
        }
        else if (TRS.mem_cmp(in_node, "TRAN_CODE", "CV", strlen("CV")) == 0)
        {
            // Start Lot 정보 조회
            DBU_init_mwiplothisx(&MWIPLOTHIS_T);
            memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            MWIPLOTHIS_T.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
            memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
            MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
            DBU_select_mwiplothisx(3, &MWIPLOTHIS_T);
            if (DB_error_code == DB_SUCCESS)
            {
                DBU_init_csumlotdat(&CSUMLOTDAT);
                memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
                memcpy(CSUMLOTDAT.OPER, MWIPLOTSTS.OPER, sizeof(CSUMLOTDAT.OPER));
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHIS_T.HIST_SEQ;
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                if (DB_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.IN_QTY = MWIPLOTSTS.QTY_1;

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT CV Update 1", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
            }
        }
        else if (TRS.mem_cmp(in_node, "TRAN_CODE", "END", strlen("END")) == 0)
        {
            // Start Lot 정보 조회
            DBU_init_mwiplothisx(&MWIPLOTHIS_T);
            memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            MWIPLOTHIS_T.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
            memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
            MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
            DBU_select_mwiplothisx(3, &MWIPLOTHIS_T);
            if(DB_error_code == DB_NOT_FOUND)
            {
                memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
                TRS.copy(CSUMLOTDAT.OPER, sizeof(CSUMLOTDAT.OPER), in_node, "OPER");                
                //END시 START SEQ 및 시간을 END 기준으로 넣어주도록 수정                
                //CSUMLOTDAT.START_HIST_SEQ = 0;
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;

                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                i_db_error_code = DB_error_code;

                CSUMLOTDAT.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
                memcpy(CSUMLOTDAT.RES_ID, MWIPLOTSTS.END_RES_ID, sizeof(CSUMLOTDAT.RES_ID));
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                memcpy(MWIPOPRDEF.OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPOPRDEF.OPER));

                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                //memset(CSUMLOTDAT.START_DATE, ' ', sizeof(CSUMLOTDAT.START_DATE));
                //memset(CSUMLOTDAT.START_TIME, ' ', sizeof(CSUMLOTDAT.START_TIME));
                //memset(CSUMLOTDAT.START_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.START_DAY_NIGHT));
                memcpy(CSUMLOTDAT.START_DATE, MWIPLOTHIS.TRAN_CMF_1, sizeof(CSUMLOTDAT.START_DATE));
                memcpy(CSUMLOTDAT.START_TIME, MWIPLOTHIS.TRAN_TIME, sizeof(CSUMLOTDAT.START_TIME));
                memcpy(CSUMLOTDAT.START_DAY_NIGHT, MWIPLOTHIS.TRAN_CMF_2, sizeof(CSUMLOTDAT.START_DAY_NIGHT));

                // Start Lot이 필수인 공정의 경우는 Mother Lot의 시작 시간을 구한다.
                if(MWIPOPRDEF.START_REQUIRE_FLAG == 'Y')
                {
                    // 모 Lot의 시작 시간을 구한다.
                    DBU_init_mwiplothisx(&MWIPLOTHIS_T);
                    memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS_T.LOT_ID));
                    memcpy(MWIPLOTHIS_T.FROM_TO_LOT_ID, MWIPLOTSTS.FROM_TO_LOT_ID, sizeof(MWIPLOTHIS_T.FROM_TO_LOT_ID));
                    memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
                    memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
                    MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
                    DBU_select_mwiplothisx(4, &MWIPLOTHIS_T);
                    if(DB_error_code == DB_SUCCESS)
                    {
                        memcpy(CSUMLOTDAT.START_DATE, MWIPLOTHIS_T.TRAN_TIME, sizeof(CSUMLOTDAT.START_DATE));
                        memcpy(CSUMLOTDAT.START_TIME, MWIPLOTHIS_T.TRAN_TIME, sizeof(CSUMLOTDAT.START_TIME));
                        memcpy(CSUMLOTDAT.START_DAY_NIGHT, MWIPLOTHIS_T.TRAN_CMF_2, sizeof(CSUMLOTDAT.START_DAY_NIGHT));
                    }
                }

                memcpy(CSUMLOTDAT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMLOTDAT.AREA_ID));
                memcpy(CSUMLOTDAT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMLOTDAT.SUB_AREA_ID));
                memcpy(CSUMLOTDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMLOTDAT.FACTORY));
                memcpy(CSUMLOTDAT.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMLOTDAT.MAT_ID));
                memcpy(CSUMLOTDAT.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMLOTDAT.FLOW));
                CSUMLOTDAT.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
                CSUMLOTDAT.OUT_QTY = MWIPLOTSTS.QTY_1;
                memcpy(CSUMLOTDAT.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMLOTDAT.UNIT));
                memcpy(CSUMLOTDAT.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMLOTDAT.ORDER_ID));
                CSUMLOTDAT.END_HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                memcpy(CSUMLOTDAT.END_DATE, MWIPLOTHIS.TRAN_CMF_1, sizeof(CSUMLOTDAT.END_DATE));
                memcpy(CSUMLOTDAT.END_TIME, MWIPLOTHIS.TRAN_TIME, sizeof(CSUMLOTDAT.END_TIME));
                memcpy(CSUMLOTDAT.END_DAY_NIGHT, MWIPLOTHIS.TRAN_CMF_2, sizeof(CSUMLOTDAT.END_DAY_NIGHT));

                //검사인 경우 판정값을 같이 저장한다. 
                if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
                {
                    memcpy(CSUMLOTDAT.CMF_1, MWIPLOTHIS.LOT_CMF_11, sizeof(MWIPLOTHIS.LOT_CMF_11));
                }

                if (i_db_error_code == DB_NOT_FOUND)
                {
                    CSUMLOTDAT.IN_QTY = MWIPLOTSTS.QTY_1;
                    TRS.copy(CSUMLOTDAT.CREATE_USER_ID, sizeof(CSUMLOTDAT.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.CREATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.CREATE_TIME));
                    //END 만 있는 공정인 경우
                    CSUMLOTDAT.ONLY_END_FLAG = 'Y';
                    memcpy(CSUMLOTDAT.CMF_2, MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));

                    DBU_insert_csumlotdat(&CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Insert", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
                else if(i_db_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.OUT_QTY = MWIPLOTSTS.QTY_1;

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Update 1", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHIS_T.HIST_SEQ;
                memcpy(CSUMLOTDAT.OPER, MWIPLOTHIS_T.OLD_OPER, sizeof(CSUMLOTDAT.OPER));
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                if (DB_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.END_HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;

                    memcpy(CSUMLOTDAT.END_DATE, work_date.s_work_date, sizeof(CSUMLOTDAT.END_DATE));
                    memcpy(CSUMLOTDAT.END_TIME, gs_sys_time, sizeof(CSUMLOTDAT.END_TIME));
                    memcpy(CSUMLOTDAT.END_DAY_NIGHT, work_date.s_day_night, sizeof(CSUMLOTDAT.END_DAY_NIGHT));

                    CSUMLOTDAT.OUT_QTY = MWIPLOTSTS.QTY_1;

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {

                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Update 2", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;

                    }
                }
            }
        }
        else if (TRS.mem_cmp(in_node, "TRAN_CODE", "LOSS", strlen("LOSS")) == 0)
        {
            DBU_init_mwiplotlos(&MWIPLOTLOS);
            memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTLOS.LOT_ID));
            MWIPLOTLOS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            MWIPLOTLOS.QTY_FLAG = '1';
            DBU_select_mwiplotlos(1, &MWIPLOTLOS);

            DBU_init_mwiplothisx(&MWIPLOTHIS_T);
            memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            MWIPLOTHIS_T.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
            memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
            MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
            DBU_select_mwiplothisx(3, &MWIPLOTHIS_T);
            if (DB_error_code == DB_NOT_FOUND)
            {
                // Lot의 Start Transaction을 못 찾았은 경우                
                memcpy(CSUMLOTDAT.OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(CSUMLOTDAT.OPER));
                CSUMLOTDAT.START_HIST_SEQ = 0;
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                i_db_error_code = DB_error_code;
                
                CSUMLOTDAT.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
                memset(CSUMLOTDAT.RES_ID, ' ', sizeof(CSUMLOTDAT.RES_ID));
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                memcpy(MWIPOPRDEF.OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(MWIPOPRDEF.OPER));

                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                memcpy(CSUMLOTDAT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMLOTDAT.AREA_ID));
                memcpy(CSUMLOTDAT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMLOTDAT.SUB_AREA_ID));
                memcpy(CSUMLOTDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMLOTDAT.FACTORY));
                memcpy(CSUMLOTDAT.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMLOTDAT.MAT_ID));
                memcpy(CSUMLOTDAT.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMLOTDAT.FLOW));
                CSUMLOTDAT.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
                CSUMLOTDAT.LOSS_QTY = MWIPLOTLOS.TOTAL_LOSS_QTY;
                memcpy(CSUMLOTDAT.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMLOTDAT.UNIT));
                memcpy(CSUMLOTDAT.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMLOTDAT.ORDER_ID));
                memset(CSUMLOTDAT.START_DATE, ' ', sizeof(CSUMLOTDAT.START_DATE));
                memset(CSUMLOTDAT.START_TIME, ' ', sizeof(CSUMLOTDAT.START_TIME));
                memset(CSUMLOTDAT.START_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.START_DAY_NIGHT));

                // 원인공정의 최근 End Lot 정보 조회
                DBU_init_mwiplothisx(&MWIPLOTHIS_T);
                memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
                MWIPLOTHIS_T.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
                memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END));
                MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
                DBU_select_mwiplothisx(3, &MWIPLOTHIS_T);
                if (DB_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.END_HIST_SEQ = MWIPLOTHIS_T.HIST_SEQ;
                    memcpy(CSUMLOTDAT.END_DATE, MWIPLOTHIS_T.TRAN_CMF_1, sizeof(CSUMLOTDAT.END_DATE));
                    memcpy(CSUMLOTDAT.END_TIME, MWIPLOTHIS_T.TRAN_TIME, sizeof(CSUMLOTDAT.END_TIME));
                    memcpy(CSUMLOTDAT.END_DAY_NIGHT, MWIPLOTHIS_T.TRAN_CMF_2, sizeof(CSUMLOTDAT.END_DAY_NIGHT));
                }
                else if(DB_error_code == DB_NOT_FOUND)
                {
                    CSUMLOTDAT.END_HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                    memcpy(CSUMLOTDAT.END_DATE, MWIPLOTHIS.TRAN_CMF_1, sizeof(CSUMLOTDAT.END_DATE));
                    memcpy(CSUMLOTDAT.END_TIME, MWIPLOTHIS.TRAN_TIME, sizeof(CSUMLOTDAT.END_TIME));
                    memcpy(CSUMLOTDAT.END_DAY_NIGHT, MWIPLOTHIS.TRAN_CMF_2, sizeof(CSUMLOTDAT.END_DAY_NIGHT));
                }

                if (i_db_error_code == DB_NOT_FOUND)
                {
                    CSUMLOTDAT.IN_QTY = MWIPLOTLOS.TOTAL_LOSS_QTY;
                    CSUMLOTDAT.END_HIST_SEQ = MWIPLOTLOS.HIST_SEQ;

                    TRS.copy(CSUMLOTDAT.CREATE_USER_ID, sizeof(CSUMLOTDAT.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.CREATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.CREATE_TIME));
                    memcpy(CSUMLOTDAT.CMF_2, MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));

                    DBU_insert_csumlotdat(&CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT Loss Insert", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_fieldmsg(out_node, "LOSS_QTY", DT_INT, CSUMLOTDAT.LOSS_QTY);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
                else if(i_db_error_code == DB_SUCCESS)
                {
                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT Loss Update 1", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_fieldmsg(out_node, "LOSS_QTY", DT_INT, CSUMLOTDAT.LOSS_QTY);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHIS_T.HIST_SEQ;
                memcpy(CSUMLOTDAT.OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(CSUMLOTDAT.OPER));
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                if (DB_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.LOSS_QTY += MWIPLOTLOS.TOTAL_LOSS_QTY;
                    CSUMLOTDAT.OUT_QTY = MWIPLOTLOS.NEW_QTY;

                    CSUMLOTDAT.IN_QTY = CSUMLOTDAT.OUT_QTY + CSUMLOTDAT.LOSS_QTY;

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT Loss Update 2", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }
                }
            }
        }
        else if (TRS.mem_cmp(in_node, "TRAN_CODE", "STORE", strlen("STORE")) == 0)
        {
            DBU_init_mwiplothisx(&MWIPLOTHIS_T);
            memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            MWIPLOTHIS_T.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            TRS.copy(MWIPLOTHIS_T.OLD_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER), in_node, "OPER");
            memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
            MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
            DBU_select_mwiplothisx(3, &MWIPLOTHIS_T);
            if (DB_error_code == DB_NOT_FOUND)
            {
                memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
                TRS.copy(CSUMLOTDAT.OPER, sizeof(CSUMLOTDAT.OPER), in_node, "OPER");
                CSUMLOTDAT.START_HIST_SEQ = 0;
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                i_db_error_code = DB_error_code;

                CSUMLOTDAT.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
                memcpy(CSUMLOTDAT.RES_ID, MWIPLOTSTS.END_RES_ID, sizeof(CSUMLOTDAT.RES_ID));
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                memcpy(MWIPOPRDEF.OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPOPRDEF.OPER));

                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                memset(CSUMLOTDAT.START_DATE, ' ', sizeof(CSUMLOTDAT.START_DATE));
                memset(CSUMLOTDAT.START_TIME, ' ', sizeof(CSUMLOTDAT.START_TIME));
                memset(CSUMLOTDAT.START_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.START_DAY_NIGHT));

                // Start Lot이 필수인 공정의 경우는 Mother Lot의 시작 시간을 구한다.
                if (MWIPOPRDEF.START_REQUIRE_FLAG == 'Y')
                {
                    // 모 Lot의 시작 시간을 구한다.
                    DBU_init_mwiplothisx(&MWIPLOTHIS_T);
                    memcpy(MWIPLOTHIS_T.LOT_ID, MWIPLOTSTS.FROM_TO_LOT_ID, sizeof(MWIPLOTHIS_T.LOT_ID));
                    memcpy(MWIPLOTHIS_T.FROM_TO_LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS_T.FROM_TO_LOT_ID));
                    memcpy(MWIPLOTHIS_T.OLD_OPER, MWIPLOTHIS.OLD_OPER, sizeof(MWIPLOTHIS_T.OLD_OPER));
                    memcpy(MWIPLOTHIS_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
                    MWIPLOTHIS_T.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
                    DBU_select_mwiplothisx(4, &MWIPLOTHIS_T);
                    if (DB_error_code == DB_SUCCESS)
                    {
                        memcpy(CSUMLOTDAT.START_DATE, MWIPLOTHIS_T.TRAN_CMF_1, sizeof(CSUMLOTDAT.START_DATE));
                        memcpy(CSUMLOTDAT.START_TIME, MWIPLOTHIS_T.TRAN_TIME, sizeof(CSUMLOTDAT.START_TIME));
                        memcpy(CSUMLOTDAT.START_DAY_NIGHT, MWIPLOTHIS_T.TRAN_CMF_2, sizeof(CSUMLOTDAT.START_DAY_NIGHT));
                    }
                }

                memcpy(CSUMLOTDAT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMLOTDAT.AREA_ID));
                memcpy(CSUMLOTDAT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMLOTDAT.SUB_AREA_ID));
                memcpy(CSUMLOTDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMLOTDAT.FACTORY));
                memcpy(CSUMLOTDAT.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMLOTDAT.MAT_ID));
                memcpy(CSUMLOTDAT.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMLOTDAT.FLOW));
                CSUMLOTDAT.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
                CSUMLOTDAT.LOSS_QTY = MWIPLOTSTS.QTY_1;
                CSUMLOTDAT.OUT_QTY = 0;

                memcpy(CSUMLOTDAT.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMLOTDAT.UNIT));
                memcpy(CSUMLOTDAT.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMLOTDAT.ORDER_ID));
                memcpy(CSUMLOTDAT.END_DATE, work_date.s_work_date, sizeof(CSUMLOTDAT.END_DATE));
                memcpy(CSUMLOTDAT.END_TIME, gs_sys_time, sizeof(CSUMLOTDAT.END_TIME));
                memcpy(CSUMLOTDAT.END_DAY_NIGHT, work_date.s_day_night, sizeof(CSUMLOTDAT.END_DAY_NIGHT));

                if (i_db_error_code == DB_NOT_FOUND)
                {
                    CSUMLOTDAT.IN_QTY = MWIPLOTSTS.QTY_1;
                    CSUMLOTDAT.END_HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                    TRS.copy(CSUMLOTDAT.CREATE_USER_ID, sizeof(CSUMLOTDAT.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.CREATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.CREATE_TIME));
                    memcpy(CSUMLOTDAT.CMF_2, MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));

                    DBU_insert_csumlotdat(&CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Insert", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
                else if (i_db_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.IN_QTY = MWIPLOTHIS_T.QTY_1;

                    TRS.copy(CSUMLOTDAT.CREATE_USER_ID, sizeof(CSUMLOTDAT.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.CREATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.CREATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Update 1", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        return MP_FALSE;
                    }
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHIS_T.HIST_SEQ;
                memcpy(CSUMLOTDAT.OPER, MWIPLOTHIS_T.OLD_OPER, sizeof(CSUMLOTDAT.OPER));
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                if (DB_error_code == DB_SUCCESS)
                {
                    memcpy(CSUMLOTDAT.END_DATE, work_date.s_work_date, sizeof(CSUMLOTDAT.END_DATE));
                    memcpy(CSUMLOTDAT.END_TIME, gs_sys_time, sizeof(CSUMLOTDAT.END_TIME));
                    memcpy(CSUMLOTDAT.END_DAY_NIGHT, work_date.s_day_night, sizeof(CSUMLOTDAT.END_DAY_NIGHT));

                    CSUMLOTDAT.LOSS_QTY += MWIPLOTSTS.QTY_1;
                    if(CSUMLOTDAT.OUT_QTY == 0)
                        CSUMLOTDAT.IN_QTY = CSUMLOTDAT.LOSS_QTY;
                    else
                    {
                        CSUMLOTDAT.OUT_QTY -= MWIPLOTSTS.QTY_1;
                        CSUMLOTDAT.IN_QTY = CSUMLOTDAT.OUT_QTY + CSUMLOTDAT.LOSS_QTY;
                    }

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT End Update 2", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }
                }
            }
        }
    }
    // Delete Lot History 시
    else
    {
        i_hist_seq = TRS.get_int(in_node, "HIST_SEQ");
        if(TRS.mem_cmp(in_node, "TRAN_CODE", "START", strlen("START")) == 0)
        {
            DBU_init_csumlotdat(&CSUMLOTDAT);
            memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
            CSUMLOTDAT.START_HIST_SEQ = i_hist_seq;

            DBU_delete_csumlotdat(1, &CSUMLOTDAT);
            if(DB_error_code != DB_NOT_FOUND && DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMLOTDAT Delete", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else if(TRS.mem_cmp(in_node, "TRAN_CODE", "END", strlen("END")) == 0)
        {
            DBU_init_csumlotdat(&CSUMLOTDAT);
            memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
            CSUMLOTDAT.END_HIST_SEQ = i_hist_seq;
            DBU_select_csumlotdat(2, &CSUMLOTDAT);
            if(DB_error_code == DB_SUCCESS)
            {
                CSUMLOTDAT.IN_QTY = 0;
                CSUMLOTDAT.OUT_QTY = 0;
                CSUMLOTDAT.LOSS_QTY = 0;

                CSUMLOTDAT.END_HIST_SEQ = 0;
                memset(CSUMLOTDAT.END_DATE, ' ', sizeof(CSUMLOTDAT.END_DATE));
                memset(CSUMLOTDAT.END_TIME, ' ', sizeof(CSUMLOTDAT.END_TIME));
                memset(CSUMLOTDAT.END_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.END_DAY_NIGHT));

                TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                DBU_update_csumlotdat(1, &CSUMLOTDAT);
                if(DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_fieldmsg(out_node, "CSUMLOTDAT Delete", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                    TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
        }
        else if (TRS.mem_cmp(in_node, "TRAN_CODE", "LOSS", strlen("LOSS")) == 0)
        {
            DBU_init_mwiplotlos(&MWIPLOTLOS);
            memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTLOS.LOT_ID));
            MWIPLOTLOS.HIST_SEQ = i_hist_seq;
            DBU_select_mwiplotlos(1, &MWIPLOTLOS);

            // Loss Transaction 이전의 이력중 가장 최근 의 Start 이력의 HIST_SEQ를 찾는다.
            DBU_init_mwiplothisx(&MWIPLOTHIS);
            memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID));
            MWIPLOTHIS.HIST_SEQ = i_hist_seq;
            DBU_select_mwiplothisx(3, &MWIPLOTHIS);
            if(DB_error_code == DB_SUCCESS)
            {
                DBU_init_csumlotdat(&CSUMLOTDAT);
                memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID));
                CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHIS.HIST_SEQ;
                DBU_select_csumlotdat(1, &CSUMLOTDAT);
                if(DB_error_code == DB_SUCCESS)
                {
                    CSUMLOTDAT.LOSS_QTY -= MWIPLOTLOS.TOTAL_LOSS_QTY;
                    if(CSUMLOTDAT.LOSS_QTY < 0)
                        CSUMLOTDAT.LOSS_QTY = 0;

                    CSUMLOTDAT.IN_QTY = CSUMLOTDAT.OUT_QTY + CSUMLOTDAT.LOSS_QTY;

                    TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

                    DBU_update_csumlotdat(1, &CSUMLOTDAT);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CSUMLOTDAT Delete", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
                        TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }
                }
            }
        }
    }
    return MP_TRUE;
}

/*******************************************************************************
    Update_Res_Wip_Summary()
        - 설비 효율에서 사용 데이터 생성
        - 설비를 사용하는 생산하는 공정이 대상됨.
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Common out node for result message
*******************************************************************************/
int Update_Res_Wip_Summary(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CSUMRESWIP_TAG CSUMRESWIP;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;

    struct work_date_tag work_date;

    int i_db_error_code = 0;

    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    DBU_init_mwiplothisx(&MWIPLOTHIS);
    memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID));
    MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;

    DBU_select_mwiplothisx(1, &MWIPLOTHIS);
    DBU_init_csumreswip(&CSUMRESWIP);
    memcpy(CSUMRESWIP.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CSUMRESWIP.LOT_ID));

    if (TRS.mem_cmp(in_node, "TRAN_CODE", "START", strlen("START")) == 0)
    {
        CSUMRESWIP.START_HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;
        DBU_select_csumreswip(1, &CSUMRESWIP);
        i_db_error_code = DB_error_code;

        memcpy(CSUMRESWIP.OPER, MWIPLOTSTS.OPER, sizeof(CSUMRESWIP.OPER));
        CSUMRESWIP.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
        memcpy(CSUMRESWIP.RES_ID, MWIPLOTSTS.START_RES_ID, sizeof(CSUMRESWIP.RES_ID));

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
        memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));

        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        memcpy(CSUMRESWIP.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMRESWIP.AREA_ID));
        memcpy(CSUMRESWIP.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMRESWIP.SUB_AREA_ID));
        memcpy(CSUMRESWIP.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMRESWIP.FACTORY));
        memcpy(CSUMRESWIP.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMRESWIP.MAT_ID));
        memcpy(CSUMRESWIP.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMRESWIP.FLOW));
        CSUMRESWIP.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
        memcpy(CSUMRESWIP.OPER, MWIPLOTSTS.OPER, sizeof(CSUMRESWIP.OPER));
        CSUMRESWIP.IN_QTY = MWIPLOTSTS.QTY_1;
        memcpy(CSUMRESWIP.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMRESWIP.UNIT));
        memcpy(CSUMRESWIP.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMRESWIP.ORDER_ID));
        memcpy(CSUMRESWIP.START_DATE, work_date.s_work_date, sizeof(CSUMRESWIP.START_DATE));
        memcpy(CSUMRESWIP.START_TIME, gs_sys_time, sizeof(CSUMRESWIP.START_TIME));
        memcpy(CSUMRESWIP.START_DAY_NIGHT, work_date.s_day_night, sizeof(CSUMRESWIP.START_DAY_NIGHT));

        if (i_db_error_code == DB_SUCCESS)
        {
            TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));

            DBU_update_csumreswip(1, &CSUMRESWIP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMRESWIP Update 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else if (i_db_error_code == DB_NOT_FOUND)
        {
            TRS.copy(CSUMRESWIP.CREATE_USER_ID, sizeof(CSUMRESWIP.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CSUMRESWIP.CREATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.CREATE_TIME));

            DBU_insert_csumreswip(&CSUMRESWIP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMRESWIP Insert", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }
    else if (TRS.mem_cmp(in_node, "TRAN_CODE", "CV", strlen("CV")) == 0)
    {
        // Start Lot 정보 조회
        DBU_init_mwiplothisx(&MWIPLOTHIS);
        memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
        MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
        memcpy(MWIPLOTHIS.OLD_OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTHIS.OLD_OPER));
        memcpy(MWIPLOTHIS.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
        MWIPLOTHIS.RESV_FLAG_1 = MWIPLOTSTS.RESV_FLAG_1;  // 재작업 여부
        DBU_select_mwiplothisx(3, &MWIPLOTHIS);
        if (DB_error_code == DB_SUCCESS)
        {
            DBU_init_csumreswip(&CSUMRESWIP);
            memcpy(CSUMRESWIP.LOT_ID, MWIPLOTHIS.LOT_ID, sizeof(CSUMRESWIP.LOT_ID));
            CSUMRESWIP.START_HIST_SEQ = MWIPLOTHIS.HIST_SEQ;
            DBU_select_csumreswip(1, &CSUMRESWIP);
            if (DB_error_code == DB_SUCCESS)
            {
                CSUMRESWIP.IN_QTY = MWIPLOTSTS.QTY_1;

                TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));

                DBU_update_csumreswip(1, &CSUMRESWIP);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_fieldmsg(out_node, "CSUMRESWIP CV Update 1", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);
                    TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);

                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    return MP_FALSE;
                }
            }
        }
    }
    else if (TRS.mem_cmp(in_node, "TRAN_CODE", "END", strlen("END")) == 0)
    {
        DBU_init_csumreswip(&CSUMRESWIP);
        TRS.copy(CSUMRESWIP.LOT_ID, sizeof(CSUMRESWIP.LOT_ID), in_node, "LOT_ID");
        CSUMRESWIP.START_HIST_SEQ = TRS.get_int(in_node, "START_HIST_SEQ");
        DBU_select_csumreswip(1, &CSUMRESWIP);
        if (DB_error_code == DB_SUCCESS)
        {
            CSUMRESWIP.IN_QTY = TRS.get_double(in_node, "IN_QTY");
            CSUMRESWIP.OUT_QTY = TRS.get_double(in_node, "OUT_QTY");
            CSUMRESWIP.LOSS_QTY = TRS.get_double(in_node, "LOSS_QTY");

            CSUMRESWIP.END_HIST_SEQ = TRS.get_int(in_node, "END_HIST_SEQ");
            TRS.copy(CSUMRESWIP.END_DATE, sizeof(CSUMRESWIP.END_DATE), in_node, "END_DATE");
            TRS.copy(CSUMRESWIP.END_TIME, sizeof(CSUMRESWIP.END_TIME), in_node, "END_TIME");
            TRS.copy(CSUMRESWIP.END_DAY_NIGHT, sizeof(CSUMRESWIP.END_DAY_NIGHT), in_node, "END_DAY_NIGHT");

            TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));
            DBU_update_csumreswip(1, &CSUMRESWIP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMRESWIP Update 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }
    else if(TRS.mem_cmp(in_node, "TRAN_CODE", "LOSS", strlen("LOSS")) == 0)
    {
        DBU_init_csumreswip(&CSUMRESWIP);
        TRS.copy(CSUMRESWIP.LOT_ID, sizeof(CSUMRESWIP.LOT_ID), in_node, "LOT_ID");
        CSUMRESWIP.START_HIST_SEQ = TRS.get_int(in_node, "START_HIST_SEQ");
        DBU_select_csumreswip(1, &CSUMRESWIP);
        if (DB_error_code == DB_SUCCESS)
        {
            CSUMRESWIP.LOSS_QTY += TRS.get_double(in_node, "LOSS_QTY");
            CSUMRESWIP.OUT_QTY = TRS.get_double(in_node, "OUT_QTY");
            CSUMRESWIP.IN_QTY = CSUMRESWIP.LOSS_QTY + CSUMRESWIP.OUT_QTY;

            if (TRS.get_char(in_node, "IS_OUT_OF_OPER") != 'Y')
            {
                CSUMRESWIP.END_HIST_SEQ = TRS.get_int(in_node, "END_HIST_SEQ");
                TRS.copy(CSUMRESWIP.END_DATE, sizeof(CSUMRESWIP.END_DATE), in_node, "END_DATE");
                TRS.copy(CSUMRESWIP.END_TIME, sizeof(CSUMRESWIP.END_TIME), in_node, "END_TIME");
                TRS.copy(CSUMRESWIP.END_DAY_NIGHT, sizeof(CSUMRESWIP.END_DAY_NIGHT), in_node, "END_DAY_NIGHT");
            }

            TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));
            DBU_update_csumreswip(1, &CSUMRESWIP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMRESWIP Update 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else if(DB_error_code == DB_NOT_FOUND)
        {
            memcpy(CSUMRESWIP.OPER, MWIPLOTSTS.OPER, sizeof(CSUMRESWIP.OPER));
            CSUMRESWIP.RWK_FLAG = MWIPLOTSTS.RESV_FLAG_1;
            memcpy(CSUMRESWIP.RES_ID, MWIPLOTSTS.START_RES_ID, sizeof(CSUMRESWIP.RES_ID));

            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));

            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            memcpy(CSUMRESWIP.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CSUMRESWIP.AREA_ID));
            memcpy(CSUMRESWIP.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CSUMRESWIP.SUB_AREA_ID));
            memcpy(CSUMRESWIP.FACTORY, MWIPLOTSTS.FACTORY, sizeof(CSUMRESWIP.FACTORY));
            memcpy(CSUMRESWIP.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CSUMRESWIP.MAT_ID));
            memcpy(CSUMRESWIP.FLOW, MWIPLOTSTS.FLOW, sizeof(CSUMRESWIP.FLOW));
            CSUMRESWIP.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
            memcpy(CSUMRESWIP.OPER, MWIPLOTSTS.OPER, sizeof(CSUMRESWIP.OPER));
            CSUMRESWIP.IN_QTY = MWIPLOTSTS.QTY_1;
            memcpy(CSUMRESWIP.UNIT, MWIPOPRDEF.UNIT_1, sizeof(CSUMRESWIP.UNIT));
            memcpy(CSUMRESWIP.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CSUMRESWIP.ORDER_ID));
            memset(CSUMRESWIP.START_DATE, ' ', sizeof(CSUMRESWIP.START_DATE));
            memset(CSUMRESWIP.START_TIME, ' ', sizeof(CSUMRESWIP.START_TIME));
            memset(CSUMRESWIP.START_DAY_NIGHT, ' ', sizeof(CSUMRESWIP.START_DAY_NIGHT));

            CSUMRESWIP.IN_QTY = TRS.get_double(in_node, "IN_QTY");
            CSUMRESWIP.OUT_QTY = TRS.get_double(in_node, "OUT_QTY");
            CSUMRESWIP.LOSS_QTY = TRS.get_double(in_node, "LOSS_QTY");

            CSUMRESWIP.END_HIST_SEQ = TRS.get_int(in_node, "END_HIST_SEQ");
            TRS.copy(CSUMRESWIP.END_DATE, sizeof(CSUMRESWIP.END_DATE), in_node, "END_DATE");
            TRS.copy(CSUMRESWIP.END_TIME, sizeof(CSUMRESWIP.END_TIME), in_node, "END_TIME");
            TRS.copy(CSUMRESWIP.END_DAY_NIGHT, sizeof(CSUMRESWIP.END_DAY_NIGHT), in_node, "END_DAY_NIGHT");

            TRS.copy(CSUMRESWIP.CREATE_USER_ID, sizeof(CSUMRESWIP.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CSUMRESWIP.CREATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.CREATE_TIME));

            DBU_insert_csumreswip(&CSUMRESWIP);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_fieldmsg(out_node, "CSUMRESWIP Insert", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
                TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMRESWIP.START_HIST_SEQ);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
    Call_Resource_Efficiency()
        - 설비 효율용 Function 호출
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - int i_seq :
        - struct MWIPLOTSTSX_TAG *MWIPLOTSTS :
        - struct MWIPLOTSTSX_TAG *MWIPLOTSTS_AF :
        - struct work_date_tag *work_date :
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Call_Resource_Efficiency(char *s_msg_code, int i_seq, 
                             struct MWIPLOTSTSX_TAG *MWIPLOTSTS, struct MWIPLOTSTSX_TAG *MWIPLOTSTS_AF, struct work_date_tag *work_date,
                             TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTHISX_TAG MWIPLOTHISX;

    TRSNode *res_wip;
    TRSNode **Lot_tbl;

    Lot_tbl = TRS.get_list(in_node, "LOT_TBL");

    res_wip = TRS.add_node(in_node, "Res_Wip");
    CopyDefaultMembers(res_wip, in_node);

    TRS.add_nstring(res_wip, "LOT_ID", TRS.get_string(Lot_tbl[i_seq], "LOT_ID"));
    TRS.add_nstring(res_wip, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if (memcmp(MWIPLOTSTS->LAST_TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START)) != 0)
    {
        DBU_init_mwiplothisx(&MWIPLOTHISX);
        memcpy(MWIPLOTHISX.FACTORY, MWIPLOTSTS->FACTORY, sizeof(MWIPLOTHISX.FACTORY));
        memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTS->LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
        memcpy(MWIPLOTHISX.OPER, MWIPLOTSTS->OPER, sizeof(MWIPLOTHISX.OPER));
        memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
        DBU_select_mwiplothisx(6, &MWIPLOTHISX);
        if (DB_error_code == DB_SUCCESS)
        {
            TRS.add_int(res_wip, "START_HIST_SEQ", MWIPLOTHISX.HIST_SEQ);
        }
        else
        {
            TRS.add_int(res_wip, "START_HIST_SEQ", MWIPLOTSTS->LAST_ACTIVE_HIST_SEQ);
        }
    }
    else
    {
        TRS.add_int(res_wip, "START_HIST_SEQ", MWIPLOTSTS->LAST_ACTIVE_HIST_SEQ);
    }

    TRS.add_double(res_wip, "IN_QTY", TRS.get_double(Lot_tbl[i_seq], "LOSS_QTY_1") + TRS.get_double(Lot_tbl[i_seq], "GOOD_QTY_1"));
    TRS.add_double(res_wip, "LOSS_QTY", TRS.get_double(Lot_tbl[i_seq], "LOSS_QTY_1"));
    TRS.add_double(res_wip, "OUT_QTY", TRS.get_double(Lot_tbl[i_seq], "GOOD_QTY_1"));
    
    if(memcmp(MWIPLOTSTS_AF->LAST_TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END)) == 0)
        TRS.add_int(res_wip, "END_HIST_SEQ", MWIPLOTSTS_AF->LAST_ACTIVE_HIST_SEQ);

    TRS.add_string(res_wip, "END_DATE", work_date->s_work_date, sizeof(work_date->s_work_date));
    TRS.add_string(res_wip, "END_TIME", MWIPLOTSTS_AF->LAST_TRAN_TIME, sizeof(MWIPLOTSTS_AF->LAST_TRAN_TIME));
    TRS.add_string(res_wip, "END_DAY_NIGHT", work_date->s_day_night, sizeof(work_date->s_day_night));
    TRS.add_nstring(res_wip, "TRAN_CODE", TRS.get_string(in_node, "TRAN_CODE"));
    TRS.add_char(res_wip, "IS_OUT_OF_OPER", TRS.get_char(in_node, "IS_OUT_OF_OPER"));

    if (Update_Res_Wip_Summary(s_msg_code, res_wip, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}

/*******************************************************************************
    Adjust_Lot_Summary()
        - Lot Summary의 END_DATE, END_TIME, END_DAY_NIGTH 보정
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - int i_start_hist_seq :
        - double d_split_qty :
        - double d_loss_qty :
        - struct work_date_tag *work_date :
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Adjust_Lot_Summary(char *s_msg_code, int i_start_hist_seq, double d_split_qty, double d_loss_qty, struct work_date_tag *work_date, 
                       TRSNode *in_node, TRSNode *out_node)
{
    struct CSUMLOTDAT_TAG CSUMLOTDAT;
    TRSNode **Lot_tbl;

    Lot_tbl = TRS.get_list(in_node, "LOT_TBL");

    DBU_init_csumlotdat(&CSUMLOTDAT);
    TRS.copy(CSUMLOTDAT.LOT_ID, sizeof(CSUMLOTDAT.LOT_ID), Lot_tbl[0], "LOT_ID");
    TRS.copy(CSUMLOTDAT.OPER, sizeof(CSUMLOTDAT.OPER), in_node, "OPER");
    CSUMLOTDAT.START_HIST_SEQ = i_start_hist_seq;
    DBU_select_csumlotdat(1, &CSUMLOTDAT);
    if (DB_error_code == DB_SUCCESS)
    {
        memcpy(CSUMLOTDAT.END_TIME, gs_sys_time, sizeof(CSUMLOTDAT.END_TIME));

        CSUMLOTDAT.IN_QTY = d_split_qty + d_loss_qty;
        CSUMLOTDAT.LOSS_QTY = d_loss_qty;
        CSUMLOTDAT.OUT_QTY = d_split_qty;

        memcpy(CSUMLOTDAT.END_DATE, work_date->s_work_date, sizeof(CSUMLOTDAT.END_DATE));
        memcpy(CSUMLOTDAT.END_DAY_NIGHT, work_date->s_day_night, sizeof(CSUMLOTDAT.END_DAY_NIGHT));

        TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));

        DBU_update_csumlotdat(1, &CSUMLOTDAT);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_fieldmsg(out_node, "CSUMLOTDAT Update 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
            TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
            TRS.add_fieldmsg(out_node, "START_HIST_SEQ", DT_INT, CSUMLOTDAT.START_HIST_SEQ);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
