/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_outsourcing_process.c
Description : 외주 프로세스

MES Version : 5.0

Function List
- step 1 : 외주 출고
- step 2 : 외주 입고

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/14  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"


int CUS_WIP_Outsourcing_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_OUTSOURCING_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Outsourcing_Process()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Outsourcing_Process(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_OUTSOURCING_PROCESS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Outsourcing_Process", out_node);
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
CUS_WIP_OUTSOURCING_PROCESS()
- Main sub function of "CUS_WIP_Outsourcing_Process" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_OUTSOURCING_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	    //LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_BF; //LOT 마스터
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_AF;	//LOT 마스터
    struct MWIPLOTHISX_TAG MWIPLOTHISX;	    //LOT 히스토리
    struct MWIPOPRDEF_TAG MWIPOPRDEF;       //공정 마스터 
    struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;  //공정 마스터 
    struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;    //공정 마스터 
    struct MWIPORDSTS_TAG MWIPORDSTS;       //작업지시 마스터
    struct CWIPINVLDM_TAG CWIPINVLDM;       //투입자재 
    struct MINVLOTSTS_TAG MINVLOTSTS;       //자재상태 테이블
    struct MINVLOTHIS_TAG MINVLOTHIS;       //자재이력 테이블
    struct MINVDLVMST_TAG MINVDLVMST;       //PO 마스터
    struct MINVDLVDTL_TAG MINVDLVDTL;     //PO 디테일
    struct CWIPLOTLST_TAG CWIPLOTLST;       //불량 임시저장 테이블
    struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;    //
    struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;  //
    struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;   //
    struct CWIPERPOPR_TAG CWIPERPOPR;       //
    struct CWIPLOTTRC_TAG  CWIPLOTTRC;
    //struct CWIPORDBOM_TAG CWIPORDBOM;       //
    struct MWIPMATDEF_TAG MWIPMATDEF;       //자재 마스터
    struct MWIPMATDEF_TAG MWIPMATDEF_PO;       //
    struct CWIPLOTREC_TAG CWIPLOTREC;       //
    struct IF_INV_TXNS_TAG IF_INV_TXNS;       //
    struct IF_PO_RCV_HEADER_TAG IF_PO_RCV_HEADER;
    struct IF_PO_RCV_TXNS_TAG IF_PO_RCV_TXNS;
    struct work_date_tag work_date;

    TRSNode *cmn_out;
    TRSNode *move_in;
    TRSNode *start_in;
    TRSNode *end_in;
    //TRSNode *store_in;
    TRSNode *unstore_in;
    TRSNode *inv_list;
    //TRSNode *insp_in;       
    TRSNode *loss_in;
    TRSNode *unit_in;
    //TRSNode *cv_in;
    TRSNode *erpif_in;
    TRSNode *poif_in;
    TRSNode *inv_in;    
    TRSNode *gen_in_node;
    TRSNode *create_in;
    //TRSNode *mat_in;
    TRSNode **Lot_tbl;
    //TRSNode *list_in;
    TRSNode *list_item;
	TRSNode *adapt_in;
	TRSNode *cv_in;
  

	TRSNode *mat_in;
	TRSNode *list_in;


    char s_lot_id[26];
    int i_lot_count = 0;
    int i_step = 0;
    double dHeaderSeq = 0;
    double dDtlSeq = 0;
    char s_factory[10];
    //int iSkip = MP_FALSE;
	double dOrderQty = 0;
    double dActiveSeq = 0;
    double dcheckFirstOpeSeq = 2;
    // LOG
    LOG_head("CUS_WIP_Outsourcing_Process");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    memset(s_factory, ' ', sizeof(s_factory));

    // VALIDATION CHECK
    if (CUS_WIP_Outsourcing_Process_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(s_factory, &work_date);

    if (TRS.get_procstep(in_node) != '7')
    {
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

        //완료 또는 삭제된 작업지시는 진행 할 수 없음
        if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_FINISH
            || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_DELETE)
        {
            //ORD-0024 : 선택한 Order는 이미 삭제되었습니다.
            strcpy(s_msg_code, "ORD-0024");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //PO가 연결되어 있지 않는 작업지시는 작업을 진행 할 수 없다.
        if (MWIPORDSTS.ORD_CMF_4[0] == ' ')
        {
            //WIP-0584 : 해당 작업지시에는 PO가 연결되어있지 않습니다. 작업지시를 확인하세요.
            strcpy(s_msg_code, "WIP-0584");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    //외주 출고 수정 화면
    if (TRS.get_procstep(in_node) == '3')
    {
        //작업공정 조회
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

        if (MWIPOPRDEF.INV_FLAG == 'Y')
        {
            //WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
            memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
        {
            //WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP)) != MP_FALSE)
        {
            //WIP-0659 : 이 공정은 외주 공정이 아닙니다. 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0659");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //TO_공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
        TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
        DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
            TRS.add_fieldmsg(out_node, "MWIPOPRDEF_TO SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (MWIPOPRDEF_TO.INV_FLAG != 'Y')
        {
            //WIP-0658 : 이 창고는 외주창고가 아닙니다. 창고 옵션을 확인하세요.
            strcpy(s_msg_code, "WIP-0658");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP)) != MP_FALSE)
        {
            //WIP-0658 : 이 창고는 외주창고가 아닙니다. 창고 옵션을 확인하세요.
            strcpy(s_msg_code, "WIP-0658");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF_TO.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
            memcmp(MWIPOPRDEF_TO.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
        {
            //WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //TO AREA 정보 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
        TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //SRC_CODE 조회 => I/F  사용
        DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
        TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
        memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
            TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
            TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int i = 0; i < i_lot_count; i++)
        {
            //품목정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), Lot_tbl[i], "MAT_ID");
            //memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (TRS.mem_cmp(Lot_tbl[i], "LOT_TYPE", MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
            {
                //lot정보 조회
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

                //해당 lot이 테스트 품인 경우 외주 출고를 할 수 없다
                if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
                {
                    //WIP-0683 : 테스트품은 외주 출고를 할 수 없습니다. lot의 상태를 확인하세요.
                    strcpy(s_msg_code, "WIP-0683");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //P급인지 체크
                DBU_init_cwiplotrec(&CWIPLOTREC);
                memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                DBU_select_cwiplotrec(2, &CWIPLOTREC);
                if (DB_error_code == DB_SUCCESS)
                {
                    //WIP-0667 : P급은 외주 출고를 할 수 없습니다. LOT상태를 확인하세요.
                    strcpy(s_msg_code, "WIP-0667");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //각각의 lot의 공정이 다르기 때문에 FROM 공정을 각 lot마다 조회한다.
                DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
                TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0010 : 이 공정은 존재 하지 않습니다.
                    strcpy(s_msg_code, "WIP-0010");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (TRS.mem_cmp(Lot_tbl[i], "OUT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
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

                //FROM AREA 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
                TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    gs_log_type.e_type = MP_LOG_E_EXISTENCE;
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_VIEW;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                // END 이력이 있는지 여부로 ERP 자재 이동 여부 확인
                // flow상 외주가 첫공정일 때만 외주 보내지는lot을 자재 이동 IF 보내준다. 
                // flow상 외주가 중간에 있는 경우는 MOVE IF로 외주로 보내졌기 때문. 
                DBU_init_mwiplothisx(&MWIPLOTHISX);
                memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                memcpy(MWIPLOTHISX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END));

                if (DBU_select_mwiplothisx_scalar(3, &MWIPLOTHISX) == 0)
                {
                    //해당 lot이 창고공정에 있지 않으면 에러.
                    if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
                    {
                        //WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
                        strcpy(s_msg_code, "WIP-0657");
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                    {
                        //ERP 실적 - 반재품의 if 실적은 lot의 트랜젝션이 일어나기 전에 erp에 실적을 올려준다
                        erpif_in = TRS.add_node(in_node, "erpif_in");
                        TRS.add_char(erpif_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(erpif_in, in_node);

                        TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
                        TRS.add_int(erpif_in, "TRAN_TYPE_ID", 2);
                        TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));
                        TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
                        TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
                        TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                        TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                        TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
                        TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
                        TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                        TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
                        TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
                        TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
                        TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
                        TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                        TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }
                        TRS.free_node(cmn_out);

                        DBU_init_if_inv_txns(&IF_INV_TXNS);
                        TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
                        memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

                        //ERP 실적 - IF_INV_TXN_LOTS
                        erpif_in = TRS.add_node(in_node, "erpif_in");
                        TRS.add_char(erpif_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(erpif_in, in_node);
                        TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
                        TRS.add_double(erpif_in, "INV_TXNS_ID", DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
                        TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                        TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                        TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                        TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                        TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);

                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }
                        TRS.free_node(cmn_out);
                    }
                }

                if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                {
                    //이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
                    if (MWIPLOTSTSX.INV_FLAG == 'Y')
                    {
                        unstore_in = TRS.add_node(in_node, "unstore_in");
                        TRS.add_char(unstore_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(unstore_in, in_node);

                        TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                     //   TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
                     //   TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));

						TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
						TRS.add_string(unstore_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));


                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }
                        TRS.free_node(cmn_out);
                    }
					else {
						//20220502 수정 Store 안쓸거임
						move_in = TRS.add_node(in_node, "move_in");
						CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(move_in, "PROCSTEP", '1');
						TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
						TRS.add_string(move_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
						TRS.add_string(move_in, "LOT_CMF_16", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));


						TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

					}
					/*
                    store_in = TRS.add_node(in_node, "store_in");
                    TRS.add_char(store_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(store_in, in_node);

                    TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(store_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
                    TRS.add_string(store_in, "LOT_CMF_16", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

					*/






                }
            }
            else if (TRS.mem_cmp(Lot_tbl[i], "LOT_TYPE", MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == MP_FALSE)
            {
                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_minvlotsts(1, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }

                //각각의 lot의 공정이 다르기 때문에 FROM 공정을 각 lot마다 조회한다.
                DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
                TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTSTS.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0010 : 이 공정은 존재 하지 않습니다.
                    strcpy(s_msg_code, "WIP-0010");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (TRS.mem_cmp(Lot_tbl[i], "OUT_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
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

                //해당 lot이 창고공정에 있지 않으면 에러.
                if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
                {
                    //WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0657");
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (memcmp(MINVLOTSTS.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                {
                    move_in = TRS.add_node(in_node, "load_in");
                    TRS.add_char(move_in, IN_PROCSTEP, '4');
                    CopyDefaultMembers(move_in, in_node);

                    TRS.add_string(move_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
                    TRS.add_nstring(move_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    inv_list = TRS.add_node(move_in, "INV_LOT_LIST");
                    TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, move_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                }

                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_minvlotsts(1, &MINVLOTSTS);

                memcpy(MINVLOTSTS.INV_CMF_10, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                memcpy(MINVLOTSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVLOTSTS.UPDATE_TIME));
                TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);

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

                DBU_init_minvlothis(&MINVLOTHIS);
                TRS.copy(MINVLOTHIS.FACTORY, sizeof(MINVLOTHIS.FACTORY), in_node, IN_FACTORY);
                memcpy(MINVLOTHIS.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                MINVLOTHIS.HIST_SEQ = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
                DBU_select_minvlothis(1, &MINVLOTHIS);

                memcpy(MINVLOTHIS.INV_CMF_10, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                memcpy(MINVLOTHIS.UPDATE_TIME, gs_sys_time, sizeof(MINVLOTHIS.UPDATE_TIME));
                TRS.copy(MINVLOTHIS.UPDATE_USER_ID, sizeof(MINVLOTHIS.UPDATE_USER_ID), in_node, IN_USERID);

                DBU_update_minvlothis(1, &MINVLOTHIS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MINVLOTHIS UPDATE", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTHIS.FACTORY), MINVLOTHIS.FACTORY);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHIS.INV_LOT_ID), MINVLOTHIS.INV_LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }

        //작업지시 상태값 변경
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);

        //작업지시가 대기 상태면 작업지시 시작처리 해준다.
        if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
        {
            MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
        }

        memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);

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
    }
    
    //외주 입고 수정 화면
    else if (TRS.get_procstep(in_node) == '4')
    {
        //작업공정 조회
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

        if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP)) != MP_FALSE)
        {
            //WIP-0659 : 이 공정은 외주 공정이 아닙니다. 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0659");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        // 구매 입고 디테일 정보 조회
        DBU_init_minvdlvdtl(&MINVDLVDTL);
        TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
        MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
        DBU_select_minvdlvdtl(102, &MINVDLVDTL);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
            TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        if (MINVDLVDTL.DELETE_FLAG == 'Y')
        {
            //WIP-0662 : 이미 완료된 PO 번호 입니다. PO정보를 확인하세요.
            strcpy(s_msg_code, "WIP-0662");
            TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        // 구매 입고 마스터 정보 조회
        DBU_init_minvdlvmst(&MINVDLVMST);
        TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
        memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.PO_NO));
        DBU_select_minvdlvmst(1, &MINVDLVMST);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
            TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        //FROM AREA 정보 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
        TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //sub AREA 정보 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
        TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
        memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //ERP 공정 조회
        DBU_init_cwiperpopr(&CWIPERPOPR);
        memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
        memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
        memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
        DBU_select_cwiperpopr(2, &CWIPERPOPR);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_init_cwiperpopr(&CWIPERPOPR);
                memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
                memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
                memcpy(CWIPERPOPR.OPER, MP_ORD_OPER_OSP, strlen(MP_ORD_OPER_OSP));
                DBU_select_cwiperpopr(2, &CWIPERPOPR);
            }
        }

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");



        for (int i = 0; i < i_lot_count; i++)
        {

            double dLossQty = 0;
            //lot정보 조회
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

            //작업지시 벨리데이션
            if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
            {
                //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
                strcpy(s_msg_code, "WIP-0647");
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                TRS.add_fieldmsg(out_node, "LOT_ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //공정 체크
            if (memcmp(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
            {
                //WIP-0656 : 작업 공정과 Lot의 공정이 다릅니다. 공정을 확인하세요.
                strcpy(s_msg_code, "WIP-0656");
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
            {
                //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0076");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //LOT 작업시작
            start_in = TRS.add_node(in_node, "start_in");
            TRS.add_char(start_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(start_in, in_node);

            TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_string(start_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_nstring(start_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            //자재 차감
            inv_in = TRS.add_node(in_node, "inv_in");
            CopyDefaultMembers(inv_in, in_node);

            TRS.add_char(inv_in, IN_PROCSTEP, '1');
            TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(inv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            TRS.add_string(inv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

            if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
                return MP_FALSE;


            //불량정보 등록 여부 체크 후 불량 등록.
            DBU_init_cwiplotlst(&CWIPLOTLST);
            memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
            memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
            memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
            i_step = 2;
            
            if ((int)DBU_select_cwiplotlst_scalar(4, &CWIPLOTLST) > 0)
            {
                loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in, in_node);
                TRS.add_char(loss_in, IN_PROCSTEP, '1');

                TRS.add_nstring(loss_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
                TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

                if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
                    TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                else
                    TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

                TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                //cv이후 lot의 수량이 변결될 수 있어 MWIPLOTSTSX_AF의 수량으로 가져온다.
                TRS.add_double(loss_in, "OUT_QTY_1", TRS.get_double(Lot_tbl[i],"QTY_1"));

                DBU_open_cwiplotlst(i_step, &CWIPLOTLST);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
                    strcpy(s_msg_code, "WIP-0232");
                    TRS.add_fieldmsg(out_node, "CWIPLOTLST OPEN(2)", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
                while (1)
                {
                    DBU_fetch_cwiplotlst(i_step, &CWIPLOTLST);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        DBU_close_cwiplotlst(i_step);
                        break;
                    }
                    else if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
                        strcpy(s_msg_code, "WIP-0232");
                        TRS.add_fieldmsg(out_node, "CWIPLOTLST FETCH(2)", MP_NVST);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        DBU_close_cwiplotlst(i_step);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    unit_in = TRS.add_node(loss_in, "UNIT1");
                    TRS.add_string(unit_in, "LOSS_CODE", CWIPLOTLST.LOSS_CODE, sizeof(CWIPLOTLST.LOSS_CODE));
                    TRS.add_double(unit_in, "LOSS_QTY", CWIPLOTLST.LOSS_QTY);
                }

                //open마지막의 CAUSE_OPER를 넣어준다.
                TRS.add_string(loss_in, "CAUSE_OPER", CWIPLOTLST.CUASE_OPER, sizeof(CWIPLOTLST.CUASE_OPER));
                TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
                TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);


                dLossQty = CWIPLOTLST.LOSS_QTY;

                //불량등록 후 불량 임시 테이블은 비워준다.
                DBU_init_cwiplotlst(&CWIPLOTLST);
                memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
                memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
                memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
                //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;

                DBU_delete_cwiplotlst(2, &CWIPLOTLST);
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
            }


            //외주 입고 시에는 불량이 없어서 불량 로직을 뺌.
            //2023022 외주시 LOT전량수량 폐기경우 있어서 로직 수정
             if (dLossQty != TRS.get_double(Lot_tbl[i], "SUM_QTY")) {

                //LOT 완료
                end_in = TRS.add_node(in_node, "end_in");
                TRS.add_char(end_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(end_in, in_node);

                TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                TRS.add_string(end_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_string(end_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

                cmn_out = TRS.create_node("Cmn_Out");
                TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
                if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }

            //LOT정보 재조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
            memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

            //외주 입고된 LOT은 PO 정보를 지워준다. 
            memset(MWIPLOTSTSX_AF.LOT_CMF_15, ' ', sizeof(MWIPLOTSTSX_AF.LOT_CMF_15));
            memset(MWIPLOTSTSX_AF.LOT_CMF_16, ' ', sizeof(MWIPLOTSTSX_AF.LOT_CMF_16));

            DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_AF);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_AF.LOT_ID), MWIPLOTSTSX_AF.LOT_ID);
                TRS.add_fieldmsg(out_node, "LOT_CMF_15", MP_STR, sizeof(MWIPLOTSTSX_AF.LOT_CMF_15), MWIPLOTSTSX_AF.LOT_CMF_15);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            //입고된 수량만큼 PO 정보에 입고 수량을 업데이트 해준다.
            MINVDLVDTL.DLV_IN_QTY = MINVDLVDTL.DLV_IN_QTY + TRS.get_double(Lot_tbl[i], "SUM_QTY");
            MINVDLVDTL.CONFIRM_QTY = MINVDLVDTL.CONFIRM_QTY + TRS.get_double(Lot_tbl[i], "QTY_1");
            MINVDLVDTL.LOSS_QTY = MINVDLVDTL.LOSS_QTY + TRS.get_double(Lot_tbl[i], "LOSS_QTY");
            
            if (MINVDLVDTL.DLV_IN_QTY >= MINVDLVDTL.DLV_QTY)
            {
                MINVDLVDTL.DELETE_FLAG = 'Y';
            }
            memcpy(MINVDLVDTL.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.UPDATE_TIME));
            TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
            DBU_update_minvdlvdtl(1, &MINVDLVDTL);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
                TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX_AF.MAT_ID, sizeof(MWIPLOTSTSX_AF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //to 창고 공정 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
            TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
            memcpy(MWIPOPRDEF_TO.OPER, MWIPLOTSTSX_AF.OPER, sizeof(MWIPOPRDEF_TO.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0010 : 이 공정은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //품목정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF_PO);
            memcpy(MWIPMATDEF_PO.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF_PO.FACTORY));
            memcpy(MWIPMATDEF_PO.MAT_ID, MINVDLVDTL.MAT_ID, sizeof(MWIPMATDEF_PO.MAT_ID));
            MWIPMATDEF_PO.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF_PO);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_PO.FACTORY), MWIPMATDEF_PO.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_PO.MAT_ID), MWIPMATDEF_PO.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //외주입고 정보 인터페이스
            //ERP 실적 - IF_PO_RCV_HEADER
            poif_in = TRS.add_node(in_node, "poif_in");
            TRS.add_char(poif_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(poif_in, in_node);

            TRS.add_char(poif_in, "TRAN_FLAG", 'I');
            TRS.add_int(poif_in, "VENDOR_ID", COM_atoi(MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID)));
            TRS.add_int(poif_in, "VENDOR_SITE_ID", MINVDLVMST.VENDOR_SITE_ID);
            TRS.add_int(poif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
            TRS.add_string(poif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
            TRS.add_string(poif_in, "MES_ID", MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_PO_RCV_HEADER(s_msg_code, poif_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            DBU_init_if_po_rcv_header(&IF_PO_RCV_HEADER);
            TRS.copy(IF_PO_RCV_HEADER.FACTORY, sizeof(IF_PO_RCV_HEADER.FACTORY), in_node, IN_FACTORY);
            memcpy(IF_PO_RCV_HEADER.MES_ID, MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
            dHeaderSeq = DBU_select_if_po_rcv_header_scalar(2, &IF_PO_RCV_HEADER);

            //ERP 실적 - IF_PO_RCV_TXNS
            erpif_in = TRS.add_node(in_node, "erpif_in");
            TRS.add_char(erpif_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(erpif_in, in_node);

            TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
            TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
            TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
            TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
            TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
            TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
            TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
            TRS.add_string(erpif_in, "PO_TYPE", MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP));
            TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_PO.MAT_CMF_1, sizeof(MWIPMATDEF_PO.MAT_CMF_1)));
            TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF_PO.MAT_ID, sizeof(MWIPMATDEF_PO.MAT_ID));
            TRS.add_string(erpif_in, "OPER_CODE", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
            TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX_AF.QTY_1);
            TRS.add_string(erpif_in, "UNIT", MWIPMATDEF_PO.UNIT_1, sizeof(MWIPMATDEF_PO.UNIT_1));
            TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            TRS.add_string(erpif_in, "INV_OPER", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
            TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
            TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_PO_RCV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            DBU_init_if_po_rcv_txns(&IF_PO_RCV_TXNS);
            TRS.copy(IF_PO_RCV_TXNS.FACTORY, sizeof(IF_PO_RCV_TXNS.FACTORY), in_node, IN_FACTORY);
            IF_PO_RCV_TXNS.RCV_HEADER_ID = dHeaderSeq;
            memcpy(IF_PO_RCV_TXNS.MES_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            dDtlSeq = DBU_select_if_po_rcv_txns_scalar(2, &IF_PO_RCV_TXNS);

            //ERP 실적 - IF_PO_RCV_TXN_LOTS
            erpif_in = TRS.add_node(in_node, "erpif_in");
            TRS.add_char(erpif_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(erpif_in, in_node);

            TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
            TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
            TRS.add_double(erpif_in, "RCV_TXN_ID", dDtlSeq);
            TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
            TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX_AF.QTY_1);

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_PO_RCV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            //시작시 생성된 lot list를 out node에 보낸다.
            //Client 실적 화면에서 작업시작 후 시작처리한 LOT LIST를 다시 조회하여 보여주기 위해. 
            list_item = TRS.add_node(out_node, "LOT_LIST");
            TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        }
    }
   
    //외주 lot 생성
    else if (TRS.get_procstep(in_node) == '5')
    {
        //작업공정 조회
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

        // 구매 입고 디테일 정보 조회
        DBU_init_minvdlvdtl(&MINVDLVDTL);
        TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
        MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
        DBU_select_minvdlvdtl(102, &MINVDLVDTL);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
            TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        // 구매 입고 마스터 정보 조회
        DBU_init_minvdlvmst(&MINVDLVMST);
        TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
        memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.PO_NO));
        DBU_select_minvdlvmst(1, &MINVDLVMST);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
            TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }

        //DLV_QTY 보다 입고 수량이 큰경우 에러 
        if (COM_dbl_round(MINVDLVDTL.DLV_QTY, 5, 'U') < COM_dbl_round(MINVDLVDTL.DLV_IN_QTY + TRS.get_double(in_node, "QTY_1"), 5, 'U'))
        {
            //WIP-0660 : PO수량보다 LOT 수량을 더 크게 생성 할 수 없습니다. LOT 수량을 확인 하세요.
            strcpy(s_msg_code, "WIP-0660");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        memset(s_lot_id, ' ', sizeof(s_lot_id));

        gen_in_node = TRS.add_node(in_node, "gen_in_node");
        TRS.add_char(gen_in_node, "PROCSTEP", '2');
        CopyDefaultMembers(gen_in_node, in_node);

        //pdc인 경우 공정lot 채번에 맞게 lot이 생성되어야 한다.
        if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_pdc, sizeof(gs_area_pdc)) == MP_FALSE)
        {
            TRS.add_string(gen_in_node, "RULE_ID", "WIP_PDC_OPER_LOT_ID", strlen("WIP_PDC_OPER_LOT_ID"));
        }
        else
        {
            TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
        }

        TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
        TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
        TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
        //TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
        TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
        TRS.free_node(cmn_out);

        //LOT ID 생성 
        //채번된 LOT ID로 작업 공정의 작업지시 정보를 사용하여 LOT을 생성 한다.
        create_in = TRS.add_node(in_node, "create_in");
        TRS.add_char(create_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(create_in, in_node);

        TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
        TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
        TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
        TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
        TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
        TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
        TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
        TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
        TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
        TRS.add_double(create_in, "QTY_1", TRS.get_double(in_node, "QTY_1"));
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

        TRS.add_string(out_node, "LOT_ID", s_lot_id, sizeof(s_lot_id));
    }

    //외주 lot 삭제
    else if (TRS.get_procstep(in_node) == '6')
    {
        //lot정보 조회
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
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

        //작업공정 조회
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

        //작업지시 벨리데이션
        if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
        {
            //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
            strcpy(s_msg_code, "WIP-0647");
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_fieldmsg(out_node, "LOT_ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //공정 체크
        if (memcmp(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
        {
            //WIP-0656 : 작업 공정과 Lot의 공정이 다릅니다. 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0656");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

		/*
        if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) != MP_FALSE)
        {
            //WIP-0661 : 외주공정에서 생성한 lot이 아닙니다. lot정보를 확인하세요.
            strcpy(s_msg_code, "WIP-0661");
            TRS.add_fieldmsg(out_node, "TRAN_CODE", MP_STR, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE), MWIPLOTSTSX.LAST_TRAN_CODE);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
		*/
          
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

    //외주 반납
    else if (TRS.get_procstep(in_node) == '7')
    {
        //작업공정 조회
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

        if (MWIPOPRDEF.INV_FLAG != 'Y')
        {
            //WIP-0582 : 해당 공정은 창고가 아닙니다.
            strcpy(s_msg_code, "WIP-0582");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_OSP, strlen(MP_OPER_GRP_TYPE_OSP)) != MP_FALSE)
        {
            //WIP-0658 : 이 창고는 외주창고가 아닙니다. 창고 옵션을 확인하세요.
            strcpy(s_msg_code, "WIP-0658");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //TO_공정 조회
        DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
        TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
        DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
            TRS.add_fieldmsg(out_node, "MWIPOPRDEF_TO SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (MWIPOPRDEF_TO.INV_FLAG != 'Y')
        {
            //WIP-0582 : 해당 공정은 창고가 아닙니다.
            strcpy(s_msg_code, "WIP-0582");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF_TO.OPER_GRP_1, MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP)) == MP_FALSE)
        {
            //WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (memcmp(MWIPOPRDEF_TO.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
            memcmp(MWIPOPRDEF_TO.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
        {
            //WIP-0628 : 이공정은 시작 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0628");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //TO AREA 정보 조회
        DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
        TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
        memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //SRC_CODE 조회 => I/F  사용
        DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
        TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
        memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
        if (DB_error_code != DB_SUCCESS)
        {
            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
            strcpy(s_msg_code, "GCM-0008");
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
            TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
            TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_VIEW;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int i = 0; i < i_lot_count; i++)
        {
            //품목정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), Lot_tbl[i], "MAT_ID");
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

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //자재 투입에 걸려있는지 확인한다. 
            DBU_init_cwipinvldm(&CWIPINVLDM);
            TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
            if ((int)DBU_select_cwipinvldm_scalar(4, &CWIPINVLDM) > 0)
            {
                //INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
                strcpy(s_msg_code, "INV-0059");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (TRS.mem_cmp(Lot_tbl[i], "LOT_TYPE", MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == MP_FALSE)
            {
                //lot정보 조회
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

                //각각의 lot의 공정이 다르기 때문에 FROM 공정을 각 lot마다 조회한다.
                DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
                TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_FROM.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0010 : 이 공정은 존재 하지 않습니다.
                    strcpy(s_msg_code, "WIP-0010");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (memcmp(MWIPOPRDEF.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
                {
                    //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0648");
                    TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (TRS.mem_cmp(Lot_tbl[i], "OUT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
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

                //FROM AREA 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
                TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    gs_log_type.e_type = MP_LOG_E_EXISTENCE;
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_VIEW;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //해당 lot이 창고공정에 있지 않으면 에러.
                if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
                {
                    //WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0657");
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                {
                    //ERP 실적 - 반재품의 if 실적은 lot의 트랜젝션이 일어나기 전에 erp에 실적을 올려준다
                    erpif_in = TRS.add_node(in_node, "erpif_in");
                    TRS.add_char(erpif_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(erpif_in, in_node);

                    TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
                    TRS.add_int(erpif_in, "TRAN_TYPE_ID", 2);
                    TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));
                    TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
                    TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
                    TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
                    TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
                    TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
                    TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
                    TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
                    TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
                    TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    DBU_init_if_inv_txns(&IF_INV_TXNS);
                    TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
                    memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

                    //ERP 실적 - IF_INV_TXN_LOTS
                    erpif_in = TRS.add_node(in_node, "erpif_in");
                    TRS.add_char(erpif_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(erpif_in, in_node);
                    TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
                    TRS.add_double(erpif_in, "INV_TXNS_ID", DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
                    TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);
                }

                if (memcmp(MWIPOPRDEF_FROM.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                {
                    //이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
                    if (MWIPLOTSTSX.INV_FLAG == 'Y')
                    {
                        unstore_in = TRS.add_node(in_node, "unstore_in");
                        TRS.add_char(unstore_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(unstore_in, in_node);

                        TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                       // TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
                       // TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));

						TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
						TRS.add_string(unstore_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));

                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }
                        TRS.free_node(cmn_out);
                    }
					/*
                    store_in = TRS.add_node(in_node, "store_in");
                    TRS.add_char(store_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(store_in, in_node);

                    TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(store_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
                    TRS.add_nstring(store_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);
					*/

                    //lot정보 재조회
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

                    if (MWIPLOTSTSX.LOT_CMF_16[0] != ' ')
                    {
                        memset(MWIPLOTSTSX.LOT_CMF_16, ' ', sizeof(MWIPLOTSTSX.LOT_CMF_16));
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
                    }

                    DBU_init_mwiplothisx(&MWIPLOTHISX);
                    memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    DBU_select_mwiplothisx(1, &MWIPLOTHISX);

                    if (MWIPLOTHISX.LOT_CMF_16[0] != ' ')
                    {
                        memset(MWIPLOTHISX.LOT_CMF_16, ' ', sizeof(MWIPLOTHISX.LOT_CMF_16));
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
            }
            else if (TRS.mem_cmp(Lot_tbl[i], "LOT_TYPE", MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == MP_FALSE)
            {
                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_minvlotsts(1, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.category = MP_LOG_CATE_TRANS;

                    return MP_FALSE;
                }

                //각각의 lot의 공정이 다르기 때문에 FROM 공정을 각 lot마다 조회한다.
                DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
                TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_FROM.OPER, MINVLOTSTS.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0010 : 이 공정은 존재 하지 않습니다.
                    strcpy(s_msg_code, "WIP-0010");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (memcmp(MWIPOPRDEF.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER)) != MP_FALSE)
                {
                    //WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0648");
                    TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (TRS.mem_cmp(Lot_tbl[i], "OUT_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
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

                //해당 lot이 창고공정에 있지 않으면 에러.
                if (MWIPOPRDEF_FROM.INV_FLAG != 'Y')
                {
                    //WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
                    strcpy(s_msg_code, "WIP-0657");
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                if (memcmp(MINVLOTSTS.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) != MP_FALSE)
                {
                    move_in = TRS.add_node(in_node, "load_in");
                    TRS.add_char(move_in, IN_PROCSTEP, '4');
                    CopyDefaultMembers(move_in, in_node);

                    TRS.add_string(move_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
                    TRS.add_nstring(move_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    inv_list = TRS.add_node(move_in, "INV_LOT_LIST");
                    TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, move_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                }

                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_minvlotsts(1, &MINVLOTSTS);

                if (MINVLOTSTS.INV_CMF_10[0] != ' ')
                {
                    memset(MINVLOTSTS.INV_CMF_10, ' ', sizeof(MINVLOTSTS.INV_CMF_10));
                    memcpy(MINVLOTSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVLOTSTS.UPDATE_TIME));
                    TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);

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

                DBU_init_minvlothis(&MINVLOTHIS);
                TRS.copy(MINVLOTHIS.FACTORY, sizeof(MINVLOTHIS.FACTORY), in_node, IN_FACTORY);
                memcpy(MINVLOTHIS.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                MINVLOTHIS.HIST_SEQ = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
                DBU_select_minvlothis(1, &MINVLOTHIS);

                if (MINVLOTHIS.INV_CMF_10[0] != ' ')
                {
                    memset(MINVLOTHIS.INV_CMF_10, ' ', sizeof(MINVLOTHIS.INV_CMF_10));
                    memcpy(MINVLOTHIS.UPDATE_TIME, gs_sys_time, sizeof(MINVLOTHIS.UPDATE_TIME));
                    TRS.copy(MINVLOTHIS.UPDATE_USER_ID, sizeof(MINVLOTHIS.UPDATE_USER_ID), in_node, IN_USERID);

                    DBU_update_minvlothis(1, &MINVLOTHIS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "MINVLOTHIS UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTHIS.FACTORY), MINVLOTHIS.FACTORY);
                        TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHIS.INV_LOT_ID), MINVLOTHIS.INV_LOT_ID);

                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }

            }
        }
    }
	else if (TRS.get_procstep(in_node) == '8')
	{
		//lot정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
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

		//작업공정 조회
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

		//작업지시 벨리데이션
		if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
		{
			//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
			strcpy(s_msg_code, "WIP-0647");
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_fieldmsg(out_node, "LOT_ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//공정 체크
		if (memcmp(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
		{
			//WIP-0656 : 작업 공정과 Lot의 공정이 다릅니다. 공정을 확인하세요.
			strcpy(s_msg_code, "WIP-0656");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		/*
		if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) != MP_FALSE)
		{
			//WIP-0661 : 외주공정에서 생성한 lot이 아닙니다. lot정보를 확인하세요.
			strcpy(s_msg_code, "WIP-0661");
			TRS.add_fieldmsg(out_node, "TRAN_CODE", MP_STR, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE), MWIPLOTSTSX.LAST_TRAN_CODE);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/

		/*
		//LOT ADAPT 처리
		adapt_in = TRS.add_node(in_node, "apt_in");
		TRS.add_char(adapt_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(adapt_in, in_node);

		TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
		TRS.add_string(adapt_in, "TO_MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
		TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
		TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
		TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
		TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
		TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
		TRS.add_double(adapt_in, "QTY", TRS.get_double(in_node, "QTY_1"));
		TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));



		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		*/


			/*
			//작업지시 상태값 변경
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			*/
			
			dOrderQty = MWIPORDSTS.ORD_IN_QTY + TRS.get_double(in_node, "QTY_1") - MWIPLOTSTSX.QTY_1;
            dActiveSeq = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;


            //외주 가공에서 생성된 LOT인지 체크
            if (dActiveSeq <= dcheckFirstOpeSeq) {
			    if (MWIPORDSTS.ORD_QTY < dOrderQty) 
			    {
				    //WIP-0619 : 작업지시에 대한 Lot 생성 수량이 초과 되었습니다. Lot 생성수량과 작업지시 수량을 확인하세요.
				    strcpy(s_msg_code, "WIP-0619");
				    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "ACTIVE_SEQ", MP_INT, dActiveSeq);
                    TRS.add_fieldmsg(out_node, "VALIDATATION_SEQ", MP_INT, dcheckFirstOpeSeq);
				    TRS.add_dberrmsg(out_node, DB_error_msg);

				    gs_log_type.type = MP_LOG_ERROR;
				    gs_log_type.e_type = MP_LOG_E_SYSTEM;
				    gs_log_type.category = MP_LOG_CATE_VIEW;

				    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				    return MP_FALSE;
			    }
            }

			MWIPORDSTS.ORD_IN_QTY = dOrderQty;
			memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
			TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);

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




		cv_in = TRS.add_node(in_node, "cv_in");
		TRS.add_char(cv_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(cv_in, in_node);

		TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		TRS.add_string(cv_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
		//TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
		//TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
		TRS.add_double(cv_in, "QTY_1", TRS.get_double(in_node, "QTY_1"));
		TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);



	}
	// 외주입고 및 LOT생성같이(스카이 다이아) & 20220616 투입기준 외주입고기능에서도 사용
	else if (TRS.get_procstep(in_node) == '9')
	{

		//작업공정 조회
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

		if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP)) != MP_FALSE)
		{
			//WIP-0659 : 이 공정은 외주 공정이 아닙니다. 공정을 확인하세요.
			strcpy(s_msg_code, "WIP-0659");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 구매 입고 디테일 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
		DBU_select_minvdlvdtl(102, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (MINVDLVDTL.DELETE_FLAG == 'Y')
		{
			//WIP-0662 : 이미 완료된 PO 번호 입니다. PO정보를 확인하세요.
			strcpy(s_msg_code, "WIP-0662");
			TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 구매 입고 마스터 정보 조회
		DBU_init_minvdlvmst(&MINVDLVMST);
		TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.PO_NO));
		DBU_select_minvdlvmst(1, &MINVDLVMST);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//FROM AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
		TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_dberrmsg(out_node, DB_error_msg);
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//sub AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
		TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
		memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_dberrmsg(out_node, DB_error_msg);
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ERP 공정 조회
		DBU_init_cwiperpopr(&CWIPERPOPR);
		memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
		memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
		memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
		DBU_select_cwiperpopr(2, &CWIPERPOPR);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				memcpy(CWIPERPOPR.OPER, MP_ORD_OPER_OSP, strlen(MP_ORD_OPER_OSP));
				DBU_select_cwiperpopr(2, &CWIPERPOPR);
			}
		}

		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
		i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");



		memset(s_lot_id, ' ', sizeof(s_lot_id));

		gen_in_node = TRS.add_node(in_node, "gen_in_node");
		TRS.add_char(gen_in_node, "PROCSTEP", '2');
		CopyDefaultMembers(gen_in_node, in_node);



		//LOT을 클라이언트에서 받은경우
		if (TRS.get_char(Lot_tbl[0], "CUSTOM_LOT_FLAG") == 'Y')
		{

			memcpy(s_lot_id, TRS.get_string(Lot_tbl[0], "LOT_ID"), strlen(TRS.get_string(Lot_tbl[0], "LOT_ID")));

			DBU_init_mwiplotstsx(&MWIPLOTSTSX_BF);
			//  TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
			memcpy(MWIPLOTSTSX_BF.LOT_ID, s_lot_id, strlen(s_lot_id));


			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_BF);
			if (DB_error_code == DB_SUCCESS)
			{
				//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0045");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_BF.FACTORY), MWIPLOTSTSX_BF.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, strlen(s_lot_id), s_lot_id);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


		}
		else{


			//pdc인 경우 공정lot 채번에 맞게 lot이 생성되어야 한다. 
			if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_pdc, sizeof(gs_area_pdc)) == MP_FALSE)
			{
				TRS.add_string(gen_in_node, "RULE_ID", "WIP_PDC_OPER_LOT_ID", strlen("WIP_PDC_OPER_LOT_ID"));
			}
			else
			{
				TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
			}


			TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
			TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
			//TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
			TRS.free_node(cmn_out);
		}
	

		//LOT ID 생성 
		//채번된 LOT ID로 작업 공정의 작업지시 정보를 사용하여 LOT을 생성 한다.
		create_in = TRS.add_node(in_node, "create_in");
		TRS.add_char(create_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(create_in, in_node);

		TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
		TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
		TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
		TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
		TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
		TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
		TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
		TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
		TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
		TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
		TRS.add_double(create_in, "QTY_1", TRS.get_double(Lot_tbl[0], "QTY_1"));
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



		//lot정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		//  TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
		memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, strlen(s_lot_id));





		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, strlen(s_lot_id), s_lot_id);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//작업지시 벨리데이션
		if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
		{
			//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
			strcpy(s_msg_code, "WIP-0647");
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_fieldmsg(out_node, "LOT_ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//공정 체크
		if (memcmp(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
		{
			//WIP-0656 : 작업 공정과 Lot의 공정이 다릅니다. 공정을 확인하세요.
			strcpy(s_msg_code, "WIP-0656");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//LOT 작업시작
		start_in = TRS.add_node(in_node, "start_in");
		TRS.add_char(start_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(start_in, in_node);

		TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		TRS.add_string(start_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
		TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
		TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		TRS.add_nstring(start_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		//자재 차감
		inv_in = TRS.add_node(in_node, "inv_in");
		CopyDefaultMembers(inv_in, in_node);

		TRS.add_char(inv_in, IN_PROCSTEP, '1');
		TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.add_string(inv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		TRS.add_string(inv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
		TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

		if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
			return MP_FALSE;


		//불량정보 등록 여부 체크 후 불량 등록.
		DBU_init_cwiplotlst(&CWIPLOTLST);
		memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
		memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
		memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
		i_step = 2;

		if ((int)DBU_select_cwiplotlst_scalar(4, &CWIPLOTLST) > 0)
		{
			loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
			CopyDefaultMembers(loss_in, in_node);
			TRS.add_char(loss_in, IN_PROCSTEP, '1');

			TRS.add_nstring(loss_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
			TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

			if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
				TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			else
				TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

			TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			//cv이후 lot의 수량이 변결될 수 있어 MWIPLOTSTSX_AF의 수량으로 가져온다.
			TRS.add_double(loss_in, "OUT_QTY_1", TRS.get_double(Lot_tbl[0], "QTY_1"));

			DBU_open_cwiplotlst(i_step, &CWIPLOTLST);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
				strcpy(s_msg_code, "WIP-0232");
				TRS.add_fieldmsg(out_node, "CWIPLOTLST OPEN(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			while (1)
			{
				DBU_fetch_cwiplotlst(i_step, &CWIPLOTLST);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_cwiplotlst(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0232 : 이 LOT의 마지막 이력이 LOSS가 아닙니다.
					strcpy(s_msg_code, "WIP-0232");
					TRS.add_fieldmsg(out_node, "CWIPLOTLST FETCH(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTLST.FACTORY), CWIPLOTLST.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cwiplotlst(i_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				unit_in = TRS.add_node(loss_in, "UNIT1");
				TRS.add_string(unit_in, "LOSS_CODE", CWIPLOTLST.LOSS_CODE, sizeof(CWIPLOTLST.LOSS_CODE));
				TRS.add_double(unit_in, "LOSS_QTY", CWIPLOTLST.LOSS_QTY);
			}

			//open마지막의 CAUSE_OPER를 넣어준다.
			TRS.add_string(loss_in, "CAUSE_OPER", CWIPLOTLST.CUASE_OPER, sizeof(CWIPLOTLST.CUASE_OPER));
			TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(in_node, "COMMENT"));
			TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//불량등록 후 불량 임시 테이블은 비워준다.
			DBU_init_cwiplotlst(&CWIPLOTLST);
			memcpy(CWIPLOTLST.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTLST.FACTORY));
			memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
			memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
			//CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;

			DBU_delete_cwiplotlst(2, &CWIPLOTLST);
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
		}

		//외주 입고 시에는 불량이 없어서 불량 로직을 뺌.
		//LOT 완료
		end_in = TRS.add_node(in_node, "end_in");
		TRS.add_char(end_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(end_in, in_node);

		TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		TRS.add_string(end_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
		TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
		TRS.add_string(end_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

		cmn_out = TRS.create_node("Cmn_Out");
		TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
		if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		//LOT정보 재조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
		memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

		//외주 입고된 LOT은 PO 정보를 지워준다. 
		memset(MWIPLOTSTSX_AF.LOT_CMF_15, ' ', sizeof(MWIPLOTSTSX_AF.LOT_CMF_15));
		memset(MWIPLOTSTSX_AF.LOT_CMF_16, ' ', sizeof(MWIPLOTSTSX_AF.LOT_CMF_16));

		DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_AF);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_AF.LOT_ID), MWIPLOTSTSX_AF.LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_CMF_15", MP_STR, sizeof(MWIPLOTSTSX_AF.LOT_CMF_15), MWIPLOTSTSX_AF.LOT_CMF_15);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		//입고된 수량만큼 PO 정보에 입고 수량을 업데이트 해준다.
		MINVDLVDTL.DLV_IN_QTY = MINVDLVDTL.DLV_IN_QTY + TRS.get_double(Lot_tbl[0], "SUM_QTY");
		MINVDLVDTL.CONFIRM_QTY = MINVDLVDTL.CONFIRM_QTY + TRS.get_double(Lot_tbl[0], "QTY_1");
		MINVDLVDTL.LOSS_QTY = MINVDLVDTL.LOSS_QTY + TRS.get_double(Lot_tbl[0], "LOSS_QTY");

		if (MINVDLVDTL.DLV_IN_QTY >= MINVDLVDTL.DLV_QTY)
		{
			MINVDLVDTL.DELETE_FLAG = 'Y';
		}
		memcpy(MINVDLVDTL.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.UPDATE_TIME));
		TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_update_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX_AF.MAT_ID, sizeof(MWIPLOTSTSX_AF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		//to 창고 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_TO.OPER, MWIPLOTSTSX_AF.OPER, sizeof(MWIPOPRDEF_TO.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//품목정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF_PO);
		memcpy(MWIPMATDEF_PO.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF_PO.FACTORY));
		memcpy(MWIPMATDEF_PO.MAT_ID, MINVDLVDTL.MAT_ID, sizeof(MWIPMATDEF_PO.MAT_ID));
		MWIPMATDEF_PO.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF_PO);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0006 : 이 제품은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_PO.FACTORY), MWIPMATDEF_PO.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_PO.MAT_ID), MWIPMATDEF_PO.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//외주입고 정보 인터페이스
		//ERP 실적 - IF_PO_RCV_HEADER
		poif_in = TRS.add_node(in_node, "poif_in");
		TRS.add_char(poif_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(poif_in, in_node);

		TRS.add_char(poif_in, "TRAN_FLAG", 'I');
		TRS.add_int(poif_in, "VENDOR_ID", COM_atoi(MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID)));
		TRS.add_int(poif_in, "VENDOR_SITE_ID", MINVDLVMST.VENDOR_SITE_ID);
		TRS.add_int(poif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
		TRS.add_string(poif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
		TRS.add_string(poif_in, "MES_ID", MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_IFS_PO_RCV_HEADER(s_msg_code, poif_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		DBU_init_if_po_rcv_header(&IF_PO_RCV_HEADER);
		TRS.copy(IF_PO_RCV_HEADER.FACTORY, sizeof(IF_PO_RCV_HEADER.FACTORY), in_node, IN_FACTORY);
		memcpy(IF_PO_RCV_HEADER.MES_ID, MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
		dHeaderSeq = DBU_select_if_po_rcv_header_scalar(2, &IF_PO_RCV_HEADER);

		//ERP 실적 - IF_PO_RCV_TXNS
		erpif_in = TRS.add_node(in_node, "erpif_in");
		TRS.add_char(erpif_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(erpif_in, in_node);

		TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
		TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
		TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
		TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
		TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
		TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
		TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
		TRS.add_string(erpif_in, "PO_TYPE", MP_ERP_PO_TYPE_OSP, strlen(MP_ERP_PO_TYPE_OSP));
		TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_PO.MAT_CMF_1, sizeof(MWIPMATDEF_PO.MAT_CMF_1)));
		TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF_PO.MAT_ID, sizeof(MWIPMATDEF_PO.MAT_ID));
		TRS.add_string(erpif_in, "OPER_CODE", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
		TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX_AF.QTY_1);
		TRS.add_string(erpif_in, "UNIT", MWIPMATDEF_PO.UNIT_1, sizeof(MWIPMATDEF_PO.UNIT_1));
		TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		TRS.add_string(erpif_in, "INV_OPER", CWIPERPOPR.INV_OPER, sizeof(CWIPERPOPR.INV_OPER));
		TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
		TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_IFS_PO_RCV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		DBU_init_if_po_rcv_txns(&IF_PO_RCV_TXNS);
		TRS.copy(IF_PO_RCV_TXNS.FACTORY, sizeof(IF_PO_RCV_TXNS.FACTORY), in_node, IN_FACTORY);
		IF_PO_RCV_TXNS.RCV_HEADER_ID = dHeaderSeq;
		memcpy(IF_PO_RCV_TXNS.MES_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		dDtlSeq = DBU_select_if_po_rcv_txns_scalar(2, &IF_PO_RCV_TXNS);

		//ERP 실적 - IF_PO_RCV_TXN_LOTS
		erpif_in = TRS.add_node(in_node, "erpif_in");
		TRS.add_char(erpif_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(erpif_in, in_node);

		TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
		TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
		TRS.add_double(erpif_in, "RCV_TXN_ID", dDtlSeq);
		TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
		TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX_AF.QTY_1);

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_IFS_PO_RCV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);







		//자동으로 자재 투입 처리를 해준다. 
		//자재 투입 서비스 호출. 
		mat_in = TRS.add_node(in_node, "mat_in");
		TRS.add_char(mat_in, IN_PROCSTEP, '5');
		CopyDefaultMembers(mat_in, in_node);


		TRS.add_nstring(mat_in, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
		TRS.add_string(mat_in, "SUB_AREA_ID", MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
		TRS.add_string(mat_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		TRS.add_nstring(mat_in, "OPER", TRS.get_string(in_node, "OPER"));
		TRS.add_string(mat_in, "LOT_ID", MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
		TRS.add_char(mat_in, "REL_LEVEL", '1');



		list_in = TRS.add_node(mat_in, "LIST_TBL");
		TRS.add_nstring(list_in, "LOT_ID", TRS.get_string(Lot_tbl[0], "BOM_LOT_ID"));
		TRS.add_nstring(list_in, "MAT_ID", TRS.get_string(Lot_tbl[0], "BOM_MAT_ID"));
		TRS.add_nstring(list_in, "LOT_TYPE", TRS.get_string(Lot_tbl[0], "BOM_LOT_TYPE"));

		TRS.add_nstring(list_in, "INPUT_TYPE", TRS.get_string(Lot_tbl[0], "BOM_INPUT_TYPE"));
		TRS.add_nstring(list_in, "OUT_OPER", TRS.get_string(Lot_tbl[0], "BOM_OUT_OPER"));
		TRS.add_double(list_in, "QTY", TRS.get_double(Lot_tbl[0], "BOM_QTY_1"));
		TRS.add_double(list_in, "BOM_QTY", TRS.get_double(Lot_tbl[0], "BOM_BOM_QTY"));


		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, mat_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);




		//시작시 생성된 lot list를 out node에 보낸다.
		//Client 실적 화면에서 작업시작 후 시작처리한 LOT LIST를 다시 조회하여 보여주기 위해. 
		list_item = TRS.add_node(out_node, "LOT_LIST");
		TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

	}
    // 베트남 저함량및 슬라이드 제품 외주입고 화면
    //베트남 외주가공 LOT생성(저함량 외경절단및,분할)
    //베트남 외주가공 LOT생성(저함량 외경절단및,분할)
    else if (TRS.get_procstep(in_node) == '0')
    {
    //작업공정 조회
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

    // 구매 입고 디테일 정보 조회
    DBU_init_minvdlvdtl(&MINVDLVDTL);
    TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
    MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
    DBU_select_minvdlvdtl(102, &MINVDLVDTL);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
        TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    // 구매 입고 마스터 정보 조회
    DBU_init_minvdlvmst(&MINVDLVMST);
    TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
    memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.PO_NO));
    DBU_select_minvdlvmst(1, &MINVDLVMST);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
        TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    //DLV_QTY 보다 입고 수량이 큰경우 에러 
    if (COM_dbl_round(MINVDLVDTL.DLV_QTY, 5, 'U') < COM_dbl_round(MINVDLVDTL.DLV_IN_QTY + TRS.get_double(in_node, "QTY_1"), 5, 'U'))
    {
        //WIP-0660 : PO수량보다 LOT 수량을 더 크게 생성 할 수 없습니다. LOT 수량을 확인 하세요.
        strcpy(s_msg_code, "WIP-0660");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }


    //투입전LOT조회


    DBU_init_mwiplotstsx(&MWIPLOTSTSX_BF);
    TRS.copy(MWIPLOTSTSX_BF.FACTORY, sizeof(MWIPLOTSTSX_BF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPLOTSTSX_BF.LOT_ID, sizeof(MWIPLOTSTSX_BF.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_BF);




    //자동으로 자재 투입 처리를 해준다. 
    //자재 투입 서비스 호출. 
    mat_in = TRS.add_node(in_node, "mat_in");
    TRS.add_char(mat_in, IN_PROCSTEP, '5');
    CopyDefaultMembers(mat_in, in_node);


    TRS.add_nstring(mat_in, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
    TRS.add_string(mat_in, "AREA_ID", MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1));
    TRS.add_string(mat_in, "SUB_AREA_ID", MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
    TRS.add_string(mat_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
    TRS.add_nstring(mat_in, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_string(mat_in, "LOT_ID", MWIPLOTSTSX_BF.LOT_ID, sizeof(MWIPLOTSTSX_BF.LOT_ID));
    TRS.add_char(mat_in, "REL_LEVEL", '1');



    list_in = TRS.add_node(mat_in, "LIST_TBL");
    TRS.add_string(list_in, "LOT_ID", MWIPLOTSTSX_BF.LOT_ID, sizeof(MWIPLOTSTSX_BF.LOT_ID));
    TRS.add_nstring(list_in, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_char(list_in, "LOT_TYPE", MWIPLOTSTSX_BF.LOT_TYPE);

    TRS.add_nstring(list_in, "INPUT_TYPE", TRS.get_string(in_node, "BOM_INPUT_TYPE"));
    TRS.add_string(list_in, "OUT_OPER", MWIPLOTSTSX_BF.OPER, sizeof(MWIPLOTSTSX_BF.OPER));
    TRS.add_double(list_in, "QTY", TRS.get_double(in_node, "QTY_1"));
    TRS.add_double(list_in, "BOM_QTY", TRS.get_double(in_node, "QTY_1"));


    cmn_out = TRS.create_node("Cmn_Out");
    if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, mat_in, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }
    TRS.free_node(cmn_out);



    //일단 외주가공으로 LOT 이동진행

    move_in = TRS.add_node(in_node, "move_in");
    CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

    TRS.add_char(move_in, "PROCSTEP", '1');
    TRS.add_nstring(move_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(move_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
    TRS.add_nstring(move_in, "TO_OPER", TRS.get_string(in_node, "OPER"));

    //TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
    //TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
    TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

    cmn_out = TRS.create_node("Cmn_Out");
    if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }
    TRS.free_node(cmn_out);







    //lot adapt 처리
    adapt_in = TRS.add_node(in_node, "apt_in");
    TRS.add_char(adapt_in, IN_PROCSTEP, '1');
    CopyDefaultMembers(adapt_in, in_node);

    TRS.add_nstring(adapt_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(adapt_in, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_nstring(adapt_in, "OPER", TRS.get_string(in_node, "BOM_OUT_OPER"));
    TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX_BF.FLOW, sizeof(MWIPLOTSTSX_BF.FLOW));
    TRS.add_string(adapt_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
    TRS.add_string(adapt_in, "TO_MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
    TRS.add_int(adapt_in, "TO_MAT_VER", MWIPORDSTS.MAT_VER);
    TRS.add_string(adapt_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    TRS.add_string(adapt_in, "TO_FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
    TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX_BF.LOT_TYPE);
    TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX_BF.LOT_PRIORITY);
    TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX_BF.CREATE_CODE, sizeof(MWIPLOTSTSX_BF.CREATE_CODE));
    TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX_BF.OWNER_CODE, sizeof(MWIPLOTSTSX_BF.OWNER_CODE));
    TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_nstring(adapt_in, "TRAN_CMF_3", "ORDER_CHANGE");  // 자품목이 모품목으로 LOT이 동일하게 들어가는경우


    cmn_out = TRS.create_node("Cmn_Out");
    if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
    {
        TRS.clone(out_node, cmn_out);
        TRS.free_node(cmn_out);
        return MP_FALSE;
    }
    TRS.free_node(cmn_out);






    //외경만 절단해서 LOT이 분할되지는 않는경우
    if (TRS.get_int(in_node, "SPLITE_COUNT") == 1) {


    }
    //절단 분할 LOT을 분할해야되는경우
    else {




        for (int i = 0; i < TRS.get_int(in_node, "SPLITE_COUNT"); i++)
        {
            memset(s_lot_id, ' ', sizeof(s_lot_id));

            gen_in_node = TRS.add_node(in_node, "gen_in_node");
            TRS.add_char(gen_in_node, "PROCSTEP", '2');
            CopyDefaultMembers(gen_in_node, in_node);


            TRS.add_string(gen_in_node, "RULE_ID", "SPLIT_WIP_LOT_ID_NEW", strlen("SPLIT_WIP_LOT_ID_NEW"));
            TRS.add_nstring(gen_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));


            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
            TRS.free_node(cmn_out);


            //LOT ID 생성 
            //채번된 LOT ID로 작업 공정의 작업지시 정보를 사용하여 LOT을 생성 한다.
            create_in = TRS.add_node(in_node, "create_in");
            TRS.add_char(create_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(create_in, in_node);

            TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
            TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
            TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
            TRS.add_string(create_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
            TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
            TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
            TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
            TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
            TRS.add_double(create_in, "QTY_1", TRS.get_double(in_node, "QTY_1"));
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



            cv_in = TRS.add_node(in_node, "cv_in");
            TRS.add_char(cv_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(cv_in, in_node);

            TRS.add_nstring(cv_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
            TRS.add_string(cv_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
            TRS.add_string(cv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            TRS.add_string(cv_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            //TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            //TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
            TRS.add_double(cv_in, "QTY_1", 0);
            TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);


            DBU_init_mwiplotstsx(&MWIPLOTSTSX_BF);
            TRS.copy(MWIPLOTSTSX_BF.FACTORY, sizeof(MWIPLOTSTSX_BF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPLOTSTSX_BF.LOT_ID, sizeof(MWIPLOTSTSX_BF.LOT_ID), in_node, "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_BF);


            DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
            TRS.copy(MWIPLOTSTSX_AF.FACTORY, sizeof(MWIPLOTSTSX_AF.FACTORY), in_node, IN_FACTORY);
            memcpy(MWIPLOTSTSX_AF.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_AF.LOT_ID));

            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);


            //LOT 추적넣음
            if (memcmp(MWIPLOTSTSX_BF.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID)) != MP_FALSE)
            {
                //LOT 추적 테이블에 저장
                DBU_init_cwiplottrc(&CWIPLOTTRC);
                TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPLOTTRC.AREA_ID));
                memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPLOTTRC.SUB_AREA_ID));
                memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
                memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
                CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ;
                memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX_BF.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
                CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX_BF.LAST_ACTIVE_HIST_SEQ;
                memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX_AF.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX_AF.LAST_TRAN_CODE));
                DBU_insert_cwiplottrc(&CWIPLOTTRC);
                if (DB_error_code != DB_SUCCESS)
                {

                    /*
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
                    TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;

                    */ 
                }
            }


        }
    }


    }


    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Outsourcing_Process_Validation()
- Validation Check sub function of "CUS_WIP_OUTSOURCING_PROCESS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Outsourcing_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "03456789") == MP_FALSE)
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
    if (TRS.get_procstep(in_node) != '7')
    {
        // ORDER ID VALIDATION
        if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_TRANS;

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
