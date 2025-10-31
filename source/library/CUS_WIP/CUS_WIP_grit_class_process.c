/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_grit_class_process.c
Description : 그릿 분류 프로세스

MES Version : 5.0

Function List
- step 1 : 분류 시작
- step 2 : 분류 완료

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/28  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Grit_Class_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_GRIT_CLASS_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Grit_Class_Process()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Grit_Class_Process(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_GRIT_CLASS_PROCESS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Grit_Class_Process", out_node);
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
CUS_WIP_GRIT_CLASS_PROCESS()
- Main sub function of "CUS_WIP_Grit_Class_Process" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_GRIT_CLASS_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	    //LOT 마스터
    struct MWIPLOTHISX_TAG MWIPLOTHISX;	    //LOT 마스터
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;	//LOT 마스터
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_INTO;	//LOT 마스터
    struct MRASRESDEF_TAG MRASRESDEF;       //
    struct MWIPORDSTS_TAG MWIPORDSTS;	    //작업지시
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보
    struct MGCMTBLDAT_TAG MGCMTBLDAT_CL;    //GCM 정보
    struct MGCMTBLDAT_TAG MGCMTBLDAT_CV;    //GCM 정보
    struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;  //GCM 정보
    struct MWIPMATDEF_TAG MWIPMATDEF;       //제품 마스터
    struct MWIPMATDEF_TAG MWIPMATDEF_ERP;       //제품 마스터
    struct MWIPMATFLW_TAG MWIPMATFLW;       //제품 플로우 마스터
    struct CWIPGRTCLS_TAG CWIPGRTCLS;       //분류기준 표
    struct MINVLOTISS_TAG MINVLOTISS;       //자재투입
    struct MINVLOTISS_TAG MINVLOTISS_OLD;   //자재투입
    struct CWIPLOTCLS_TAG CWIPLOTCLS;       //분류 정보 저장.
    struct MINVLOTSTS_TAG MINVLOTSTS;       //분류 정보 저장.
    struct MWIPOPRDEF_TAG MWIPOPRDEF;       //
    struct MWIPFLWOPR_TAG MWIPFLWOPR;       //
    struct MWIPFLWOPR_TAG MWIPFLWOPR_INIT;       //
    struct MWIPOPRDEF_TAG MWIPOPRDEF_INV;       //
    struct CWIPLOTTRC_TAG CWIPLOTTRC;       //

    struct work_date_tag work_date;

    TRSNode *cmn_out; 
    TRSNode *gen_in_node;
    TRSNode *create_in;    
    TRSNode *start_in;
    TRSNode *end_in;       
    TRSNode *split_in;
    TRSNode *adapt_in;
    TRSNode *loss_in;
    TRSNode *mat_in;
    TRSNode *load_in;
    TRSNode *cv_in;
    TRSNode *merge_in;
    TRSNode *unit_in;
    TRSNode *if_end_in;
    TRSNode **Lot_tbl;
    TRSNode **class_tbl;
    TRSNode *list_in;
    TRSNode *inv_list;
    TRSNode *list_item;
    TRSNode *res_wip;
    TRSNode *res_in;

    int i_lot_count = 0;
    int i_use_lot_count = 0;
    int i_class_count = 0;
    int i_lot_seq = 0;
    char s_Order_id[26];
    char s_lot_id[26];
    char s_mat_id[31];
    double d_Sum_Qty = 0;
    double d_Good_Qty = 0;
    //double d_Remain_Qty = 0;
    double d_Unit = 0;
    double dQty = 0;
    char cSumQty[30];
    char dtoChar[10];
    int iCheckClass = MP_FALSE;
    double dHeaderSeq = 0;
    double dOldQty = 0;
    int iHistSeq = 0;

    int i_start_hist_seq = 0;
    double d_loss_qty = 0;
    double d_split_qty = 0;

    // LOG
    LOG_head("CUS_WIP_Grit_Class_Process");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    // VALIDATION CHECK
    if (CUS_WIP_Grit_Class_Process_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //멀티 트랜잭션 키 생성. 
    gb_multi_transaction = MP_TRUE;
    memset(gs_multi_tran_key, 0x00, sizeof(gs_multi_tran_key));
    COM_generate_multi_tran_key(gs_multi_tran_key);

    memset(s_mat_id, ' ', sizeof(s_mat_id));
    memset(cSumQty, ' ', sizeof(cSumQty));

    //그릿 공정 옵션 조회
    /*gcm의 OPER_OPTION 에 셋업된 정보를 가져온다.
        DATA_1 : 분류 종류 - key(공정)의 분류 정보를 나타낸다. 
                 NONE = 분류가 아닌 공정 (EX : V-Mixer)
                 SIZE = 사이즈 분류
                 MAGN = 자성 분류
                 CUP = 형상 분류
        DATA_2 : 제품군 - 해당 공정의 제품군을 나타낸다. 
                 IMD-T, IMD-KINIK, ISD
        DATA_3 : 혼합여부 - 시작공정 LOT 혼합 여부
        DATA_4 : 가상 작업지시 MAT ID - 임의의 MAT ID에 작업지시를 만든다. 
        DATA_5 : 가상 MAT ID 를 만드는 공정 여부 
        DATA_6 : 형상분류 CLASS 순서 - IMD-T 인 경운 분류를 1~3차 까지 진행한다.
        DATA_7 : 공정에서 생성할 ID룰 셋업
        DATA_8 : 공정에서 시작된 lot에 다른 lot merge 가능 여부 
                 ex) IMD-T 2,3차 형상 분류
    */
    DBU_init_mgcmtbldat(&MGCMTBLDAT);
    TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_GRIT_OPER, strlen(MP_GCM_GRIT_OPER));
    TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "OPER");
    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
    if (DB_error_code != DB_SUCCESS)
    {
        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
        strcpy(s_msg_code, "GCM-0008");
        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MGCMTBLDAT.FACTORY, &work_date);

    //공정 정보 조회
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

    //ERP AREA 정보 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
    TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
    memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
    if (DB_error_code != DB_SUCCESS)
    {
        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
        strcpy(s_msg_code, "GCM-0008");
        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //step 1 :작업시작
    if (TRS.get_procstep(in_node) == '1')
    {
        //최초 시작 품목로 만들어진 작업지시가 있는지 확인한다. 
        //만들어진 작업지시는 가상의 작업지시이므로 MES 내부로만 관리 된다.
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        memcpy(MWIPORDSTS.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPORDSTS.MAT_ID));
        MWIPORDSTS.MAT_VER = 1;
        DBU_select_mwipordsts(2, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
            {
                //첫 공정 가상 만들어지는 MAT ID 를 조회한다.
                //관리에 포함되는 MAT ID 가 아니고 MES 내부에서 관리되는 MAT ID 이다. 
                DBU_init_mwipmatdef(&MWIPMATDEF);
                TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPMATDEF.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPMATDEF.MAT_ID));
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

                //품목 - FLOW 정보 조회
                DBU_init_mwipmatflw(&MWIPMATFLW);
                TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                DBU_select_mwipmatflw(2, &MWIPMATFLW);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0019 : 이 FLOW는 제품에 속해 있지 않습니다.
                    strcpy(s_msg_code, "WIP-0019");
                    TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                memset(s_Order_id, ' ', sizeof(s_Order_id));

                //그릿 작업지시ID를 발번 한다.
                gen_in_node = TRS.add_node(in_node, "gen_in_node");
                TRS.add_char(gen_in_node, "PROCSTEP", '2');
                CopyDefaultMembers(gen_in_node, in_node);
                TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_GRIT_CLASS_ORDER, strlen(MP_ID_ROLE_GRIT_CLASS_ORDER));
                TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                memcpy(s_Order_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                TRS.free_node(cmn_out);

                //flow의 마지막 공정을 조회한다.

				
                DBU_init_mwipflwopr(&MWIPFLWOPR);
                DBU_init_mwipoprdef(&MWIPOPRDEF_INV);
                TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
                DBU_select_mwipflwopr(4, &MWIPFLWOPR);
                if (DB_error_code == DB_SUCCESS)
                {
                    TRS.copy(MWIPOPRDEF_INV.FACTORY, sizeof(MWIPOPRDEF_INV.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPOPRDEF_INV.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF_INV);
                }

                //만들어진 작업지시를 INSERT 한다.
                memcpy(MWIPORDSTS.ORDER_ID, s_Order_id, sizeof(MWIPORDSTS.ORDER_ID));
                memcpy(MWIPORDSTS.WORK_DATE, gs_sys_time, sizeof(MWIPORDSTS.WORK_DATE));
                TRS.copy(MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1), in_node, "AREA_ID");
                TRS.copy(MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2), in_node, "SUB_AREA_ID");
                memcpy(MWIPORDSTS.ORD_CMF_3, MWIPOPRDEF_INV.OPER, sizeof(MWIPOPRDEF_INV.OPER));
                MWIPORDSTS.LOT_TYPE = 'P';
                MWIPORDSTS.LOT_PRIORITY = '1';
                memcpy(MWIPORDSTS.OWNER_CODE, "PROD", strlen("PROD"));
                memcpy(MWIPORDSTS.CREATE_CODE, "PROD", strlen("PROD"));
                memcpy(MWIPORDSTS.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
                MWIPORDSTS.FLOW_SEQ_NUM = MWIPMATFLW.FLOW_SEQ_NUM;
                memcpy(MWIPORDSTS.ORG_DUE_TIME, gs_sys_time, sizeof(MWIPORDSTS.ORG_DUE_TIME));
                MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
                TRS.copy(MWIPORDSTS.CREATE_USER_ID, sizeof(MWIPORDSTS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(MWIPORDSTS.CREATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.CREATE_TIME));                
                //분류 임시 작업지시를 표현해준다. 
                //완료시 벨리데이션 제외 대상에서 체크 한다.
                memcpy(MWIPORDSTS.ORDER_DESC, "CLASS", strlen("CLASS"));

                DBU_insert_mwipordsts(&MWIPORDSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "MWIPORDSTS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPORDSTS.MAT_ID), MWIPORDSTS.MAT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
        }

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        //병합 lot을 생성하는 공정 (분류 첫 공정) 인 경우
        //(혼합여부 - 시작공정 LOT 혼합 여부)
        if (MGCMTBLDAT.DATA_3[0] == 'Y')
        {
            //가상 작업지시 MAT ID을 생성하는 공정 여부
            if (MGCMTBLDAT.DATA_5[0] == 'Y')
            {
                memset(s_lot_id, ' ', sizeof(s_lot_id));

                for (int i = 0; i < i_lot_count; i++)
                {
                    d_Sum_Qty = d_Sum_Qty + TRS.get_double(Lot_tbl[i], "QTY_1");

                    if (i == 0)
                    {
                        TRS.copy(s_mat_id, sizeof(s_mat_id), Lot_tbl[i], "MAT_ID");
                    }

                    //기존 투입 lot인지 확인.
                    DBU_init_mwiplothisx(&MWIPLOTHISX);
                    TRS.copy(MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID), Lot_tbl[i], "LOT_ID");
                    memcpy(MWIPLOTHISX.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                    memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
                    
                    if ((int)DBU_select_mwiplothisx_scalar(2, &MWIPLOTHISX) > 0)
                    {
                        //WIP-0199 : 이 LOT의 공정이 일치 하지 않습니다.
                        strcpy(s_msg_code, "WIP-0199");
                        TRS.add_fieldmsg(out_node, "MWIPLOTHISX SELECT", MP_NVST);
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //각각의 lot을 수량 0 처리 한다.
                    //투입 lot 정보 조회
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
                    if (DB_error_code == DB_SUCCESS)
                    {
                        if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
                        {
                            //WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
                            strcpy(s_msg_code, "WIP-0681");
                            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
                            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            return MP_FALSE;
                        }

                        //flow의 첫 공정을 조회한다.
                        DBU_init_mwipflwopr(&MWIPFLWOPR_INIT);
                        TRS.copy(MWIPFLWOPR_INIT.FACTORY, sizeof(MWIPFLWOPR_INIT.FACTORY), in_node, IN_FACTORY);
                        memcpy(MWIPFLWOPR_INIT.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
                        memcpy(MWIPFLWOPR_INIT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                        DBU_select_mwipflwopr(1, &MWIPFLWOPR_INIT);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            if (MWIPFLWOPR_INIT.SEQ_NUM == 1)
                            {
                                //FLOW의 첫공정인 경우 투입되는 LOT의 공정의 분류 창고에 있는지 확인한다.
                                if (memcmp(MWIPLOTSTSX.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
                                {
                                    //WIP-0669 : 분류 투입은 해당 FLOW의 창고에 있는 LOT만 투입 가능 합니다.
                                    strcpy(s_msg_code, "WIP-0669");
                                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                                    TRS.add_dberrmsg(out_node, DB_error_msg);

                                    return MP_FALSE;
                                }
                            }
                        }

                        //불량코드가 없지만 완료 수량이 다르면 다른 수량 만큼 cv 처리를 한다.
                        cv_in = TRS.add_node(in_node, "cv_in");
                        TRS.add_char(cv_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(cv_in, in_node);

                        TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                        TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                        TRS.add_string(cv_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                        TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                        TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                       // TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
					   // 20211123 수정


                        TRS.add_double(cv_in, "QTY_1", 0);
                        //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                        TRS.add_char(cv_in, "CLASS_OPER_SKIP", 'Y');

                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }

                        TRS.free_node(cmn_out);

                        iHistSeq = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    }
                    else
                    {
                        DBU_init_minvlotsts(&MINVLOTSTS);
                        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                        DBU_select_minvlotsts(1, &MINVLOTSTS);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            iHistSeq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
                        }
                    }
                }

                //공정OPTION의 ID 발번 규칙(DATA_7)이 등록 되어있는지 체크 한다.
                if (MGCMTBLDAT.DATA_7[0] == ' ')
                {
                    //WIP-0597 : ID 발번 규칙이 정의되어있지 않습니다.  ID 발번 규칙을 설정하세요.
                    strcpy(s_msg_code, "WIP-0597");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //공정 옵션에 셋업된 id룰을 사용한다. 
                gen_in_node = TRS.add_node(in_node, "gen_in_node");
                TRS.add_char(gen_in_node, "PROCSTEP", '2');
                CopyDefaultMembers(gen_in_node, in_node);

                //IMD-T 2차, 3차 분류인 경우 새로운 lot으로 채번한다._손영주 주임 요청
                if (MGCMTBLDAT.DATA_6[0] != ' ')
                {
                    TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                    TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_9, sizeof(MGCMTBLDAT.DATA_9));
                }
                else
                {
                    TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
                    TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_7, sizeof(MGCMTBLDAT.DATA_7));
                }

                TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));                
                TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));                
                TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "SEQ_KEY_1"));               
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
                memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                TRS.free_node(cmn_out);

                //lot id 생성
                create_in = TRS.add_node(in_node, "create_in");
                TRS.add_char(create_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(create_in, in_node);

                TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
                //TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));

                if (MGCMTBLDAT.DATA_6[0] != ' ')
                {
                    TRS.add_string(create_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                    TRS.add_int(create_in, "MAT_VER", MWIPLOTSTSX.MAT_VER);
                    TRS.add_string(create_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                }
                else
                {
                    TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
                    TRS.add_int(create_in, "MAT_VER", MWIPORDSTS.MAT_VER);
                    TRS.add_nstring(create_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
                }

                TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
                TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
                TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
                TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
                TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
                TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
                TRS.add_double(create_in, "QTY_1", d_Sum_Qty);
                TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
                
                TRS.add_string(create_in, "RESV_FIELD_1", s_mat_id, sizeof(s_mat_id));
                //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                TRS.add_char(create_in, "CLASS_OPER_SKIP", 'Y');
               
                COM_dtoa(cSumQty, d_Sum_Qty, sizeof(cSumQty));               
                TRS.add_string(create_in, "RESV_FIELD_2", cSumQty, sizeof(cSumQty));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                for (int i = 0; i < i_lot_count; i++)
                {
                    iHistSeq = 0;

                    DBU_init_mwiplotstsx(&MWIPLOTSTSX_INTO);
                    TRS.copy(MWIPLOTSTSX_INTO.LOT_ID, sizeof(MWIPLOTSTSX_INTO.LOT_ID), Lot_tbl[i], "LOT_ID");
                    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_INTO);
                    if (DB_error_code == DB_SUCCESS)
                    {
                        iHistSeq = MWIPLOTSTSX_INTO.LAST_ACTIVE_HIST_SEQ - 1;
                    }
                    else
                    {
                        DBU_init_minvlotsts(&MINVLOTSTS);
                        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
                        DBU_select_minvlotsts(1, &MINVLOTSTS);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            iHistSeq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;
                        }
                    }

                    //LOT 추적 테이블에 저장
                    DBU_init_cwiplottrc(&CWIPLOTTRC);
                    TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
                    memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                    memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                    memcpy(CWIPLOTTRC.LOT_ID, s_lot_id, sizeof(CWIPLOTTRC.LOT_ID));
                    CWIPLOTTRC.LOT_HIST_SEQ = 1;
                    //memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));                    
                    TRS.copy(CWIPLOTTRC.FROM_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID), Lot_tbl[i], "LOT_ID");
                    CWIPLOTTRC.FROM_LOT_HIST_SEQ = iHistSeq;
					memcpy(CWIPLOTTRC.TRAN_CODE, MP_TRAN_CODE_CREATE , sizeof(MP_TRAN_CODE_CREATE));
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
            //새로운 mat id로 lot 을 생성하는 공정이 아닌경우 투입되는 lot을 모두 merge 한다.
            else
            {
                i_use_lot_count = 0;

                if (i_lot_count > 1)
                {
                    for (int i = 1; i < i_lot_count; i++)
                    {
                        merge_in = TRS.add_node(in_node, "merge_in");
                        TRS.add_char(merge_in, IN_PROCSTEP, '1');
                        CopyDefaultMembers(merge_in, in_node);

                        TRS.add_nstring(merge_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));
                        TRS.add_nstring(merge_in, "INTO_LOT_ID", TRS.get_string(Lot_tbl[i_use_lot_count], "LOT_ID"));
                        TRS.add_double(merge_in, "MOVE_QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
                        TRS.add_char(merge_in, "SKIP_OPER_CHECK", 'Y');

                        cmn_out = TRS.create_node("Cmn_Out");
                        if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
                        {
                            TRS.clone(out_node, cmn_out);
                            TRS.free_node(cmn_out);
                            return MP_FALSE;
                        }
                        TRS.free_node(cmn_out);
                    }
                }

                TRS.copy(s_lot_id, sizeof(s_lot_id), Lot_tbl[i_use_lot_count], "LOT_ID");
            }
        }
        else
        {
            i_use_lot_count = 0;
            TRS.copy(s_lot_id, sizeof(s_lot_id), Lot_tbl[i_use_lot_count], "LOT_ID");
        }

        //lot 정보 조회
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
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

        //if (MGCMTBLDAT.DATA_5[0] != 'Y')
        //{
        //    if(memcmp(MWIPLOTSTSX.OPER , MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER)) != MP_FALSE)
        //    {
        //        //WIP-0199 : 이 LOT의 공정이 일치 하지 않습니다.
        //        strcpy(s_msg_code, "WIP-0199");
        //        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
        //        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        //        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
        //        TRS.add_dberrmsg(out_node, DB_error_msg);

        //        return MP_FALSE;
        //    }
        //}

        //LOT 삭제여부 체크
        if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
        {
            //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0076(Grtclssstart)");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //LOT 삭제여부 체크
        if (MWIPLOTSTSX.START_FLAG == 'Y')
        {
            //WIP-0086 : 이 LOT은 START 상태 입니다. 이 상태에서는 현재 TRANSACTION을 사용할 수 없습니다.
            strcpy(s_msg_code, "WIP-0086");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
        {
            //WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
            strcpy(s_msg_code, "WIP-0681");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //최초 투입이 자재인경우 모두 소모처리 해준다. 
        for (int i = 0; i < i_lot_count; i++)
        {
            DBU_init_minvlotsts(&MINVLOTSTS);
            TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "LOT_ID");
            DBU_select_minvlotsts(1, &MINVLOTSTS);
            if (DB_error_code == DB_SUCCESS)
            {
                if (MINVLOTSTS.QTY > 0)
                {
                    load_in = TRS.add_node(in_node, "load_in");
                    TRS.add_char(load_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(load_in, in_node);

                    TRS.add_string(load_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.add_nstring(load_in, "OPER", TRS.get_string(in_node, "OPER"));
                    TRS.add_nstring(load_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    list_in = TRS.add_node(load_in, "INV_LOT_LIST");
                    TRS.add_string(list_in, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_LOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    //load 후 소진 처리를 바로 해준다. 
                    //load 된 자재만 소진 처리를 할 수 있다.
                    mat_in = TRS.add_node(in_node, "mat_in");
                    TRS.add_char(mat_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(mat_in, in_node);

                    inv_list = TRS.add_node(mat_in, "INV_LOT_LIST");
                    TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                    TRS.add_double(inv_list, "ISSUE_QTY", MINVLOTSTS.QTY);

                    TRS.add_string(mat_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.add_string(mat_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_nstring(mat_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_INV_ISSUE_LOT_MAIN(s_msg_code, mat_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                }
            }       
        }

        //lot 작업시작
        start_in = TRS.add_node(in_node, "start_in");
        TRS.add_char(start_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(start_in, in_node);

        TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
        TRS.add_nstring(start_in, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
        TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
        TRS.add_char(start_in, "CLASS_OPER_SKIP", 'Y');

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);

        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        {
            cmn_out = TRS.create_node("Cmn_Out");
            TRS.add_nstring(start_in, "TRAN_CODE", "START");
            if (Update_Res_Wip_Summary(s_msg_code, start_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }

            TRS.free_node(cmn_out);
        }

        //out node에 lot id를 담아준다.
        TRS.add_string(out_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    }
    //step 2 : 작업완료
    else if (TRS.get_procstep(in_node) == '2')
    {     
        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        //end lot은 리스트로 받더라도 무조건 1개의 lot 뿐이 없으므로 Lot_tbl[0]로 한다.
        i_use_lot_count = 0;

        //분리된 lot 정보 조회한다. 
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
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

        if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
        {
            //WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
            strcpy(s_msg_code, "WIP-0681");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        //선택공정과 lot의 공정이 같아야 한다.
        if (TRS.mem_cmp(in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
        {
            //WIP-0656 : 작업 공정과 Lot의 공정이 다릅니다. 공정을 확인하세요.
            strcpy(s_msg_code, "WIP-0656");
            TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        //lot 이력 seq
        i_lot_seq = MWIPLOTSTSX.LAST_HIST_SEQ;

        //lot 삭제여부 체크
        if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
        {
            //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0076(Grtclsssend)");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (MWIPLOTSTSX.START_FLAG != 'Y')
        {
            //WIP-0069 : 이 공정은 START가 필요한 공정 입니다. 먼저 START 후 사용 하세요.
            strcpy(s_msg_code, "WIP-0069");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        
        //분류 수량 확인 벨리데이션
        if (MWIPLOTSTSX.QTY_1 < TRS.get_double(in_node, "SUM_CLASS_QTY"))
        {
            //WIP-0588 : Lot의 수량이 분류 수량의 합보다 작습니다. 분류 수량을 확인하세요.
            strcpy(s_msg_code, "WIP-0588");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        // Start Transaction Sequence
        i_start_hist_seq = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;

        // size 작업한 lot의 수량 
        d_Sum_Qty = TRS.get_double(in_node, "SUM_CLASS_QTY");
        d_Good_Qty = TRS.get_double(in_node, "SUM_GOOD_QTY");

        //사이즈 분류
        if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_SIZE, strlen(MP_CLASS_TYPE_SIZE)) == MP_FALSE)
        {
            class_tbl = TRS.get_list(in_node, "CLASS_TBL");
            i_class_count = TRS.get_item_count(in_node, "CLASS_TBL");

            for (int i = 0; i < i_class_count; i++)
            {                                
                memset(s_lot_id, ' ', sizeof(s_lot_id));
                memset(dtoChar, ' ', sizeof(dtoChar));
                iCheckClass = MP_FALSE;

                //공정OPTION의 ID 발번 규칙(DATA_7)이 등록 되어있는지 체크 한다.
                if (MGCMTBLDAT.DATA_7[0] == ' ')
                {
                    //WIP-0597 : ID 발번 규칙이 정의되어있지 않습니다.  ID 발번 규칙을 설정하세요.
                    strcpy(s_msg_code, "WIP-0597");
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //공정 옵션에 셋업된 id룰을 사용한다. 
                gen_in_node = TRS.add_node(in_node, "gen_in_node");
                TRS.add_char(gen_in_node, "PROCSTEP", '2');
                CopyDefaultMembers(gen_in_node, in_node);
                TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_7, sizeof(MGCMTBLDAT.DATA_7));
                TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "SEQ_KEY_1"));
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
                memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                TRS.free_node(cmn_out);

                //자성 분류될 LOT으로 각각 SPLIT 처리 한다.
                split_in = TRS.add_node(in_node, "split_in");
                CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(split_in, "PROCSTEP", '1');
                TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
                TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
                TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(class_tbl[i], "QTY")); // QTY_1 유효중량
                TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
                TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1 - TRS.get_double(class_tbl[i], "QTY"));   //split 전 모랏의 총 수량                                

                TRS.add_nstring(split_in, "GRT_CMF_1", TRS.get_string(class_tbl[i], "CLASS"));
                dQty = TRS.get_double(class_tbl[i], "QTY");
                COM_dtoa(dtoChar, dQty, sizeof(dtoChar));
                TRS.add_string(split_in, "GRT_CMF_2", dtoChar, sizeof(dtoChar));

                TRS.add_string(split_in, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
                TRS.add_string(split_in, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));
                TRS.add_string(split_in, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
                TRS.add_string(split_in, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                d_split_qty += TRS.get_double(class_tbl[i], "QTY");

                //SPLIT 된 LOT을 조회한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                iCheckClass = MP_FALSE;

                //분류정보 조회
                DBU_init_cwipgrtcls(&CWIPGRTCLS);
                TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");

                //새로운 mat id로 lot 을 생성하는 공정인 경우.
                //가상의 MAT ID 로 만들기 때문에 최초 투입 자재를 알아야 한다.
                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }
                else
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }
                
                TRS.copy(CWIPGRTCLS.CLASS_VALUE, sizeof(CWIPGRTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    //CLASS TYPE으로 조회되지 않는 경우 ALL로 다시 한번 조회한다.
                    //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                    DBU_init_cwipgrtcls(&CWIPGRTCLS);
                    TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                    memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                    TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                    
                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX.MAT_ID)) == MP_FALSE)
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }
                    else
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }

                    memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                    DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                        DBU_init_cwipgrtcls(&CWIPGRTCLS);
                        TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                        memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                        TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            iCheckClass = MP_TRUE;
                        }
                    }
                    else if (DB_error_code == DB_SUCCESS)
                    {
                        iCheckClass = MP_TRUE;
                    }
                }
                else if (DB_error_code == DB_SUCCESS)
                {
                    iCheckClass = MP_TRUE;
                }

                // 특성에 따라 변경되는 mat id가 있는경우
                if (CWIPGRTCLS.OUT_MAT_ID[0] != ' ')
                {
                    //MAT_ID 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPMATDEF.MAT_ID, CWIPGRTCLS.OUT_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

                    //분류표에 맞는 제품으로 adapt 처리 한다.
                    adapt_in = TRS.add_node(in_node, "apt_in");
                    TRS.add_char(adapt_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(adapt_in, in_node);

                    TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_string(adapt_in, "TO_MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_int(adapt_in, "TO_MAT_VER", MWIPMATDEF.MAT_VER);
                    TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX_SPLIT.LOT_TYPE);
                    TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX_SPLIT.LOT_PRIORITY);
                    TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX_SPLIT.CREATE_CODE, sizeof(MWIPLOTSTSX_SPLIT.CREATE_CODE));
                    TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX_SPLIT.OWNER_CODE, sizeof(MWIPLOTSTSX_SPLIT.OWNER_CODE));
                    TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));
                    TRS.add_nstring(adapt_in, "TRAN_CMF_3", "GRIT_SORT");  // GRIT분류  표기용도

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);
                }

                //split된 lot id를 재조회한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

                //LOT ID 를 재조회 한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

                //판정 기준을 조회한다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_CL);
                TRS.copy(MGCMTBLDAT_CL.FACTORY, sizeof(MGCMTBLDAT_CL.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_CL.TABLE_NAME, MP_GCM_GRIT_CLASS_JUDGE, strlen(MP_GCM_GRIT_CLASS_JUDGE));
                TRS.copy(MGCMTBLDAT_CL.KEY_1, sizeof(MGCMTBLDAT_CL.KEY_1), class_tbl[i], "LOSS_CONFIRM");
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CL);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_CL SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CL.FACTORY), MGCMTBLDAT_CL.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CL.TABLE_NAME), MGCMTBLDAT_CL.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //그릿 분류 정보를 조회한다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_CV);
                TRS.copy(MGCMTBLDAT_CV.FACTORY, sizeof(MGCMTBLDAT_CV.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_CV.TABLE_NAME, MP_GCM_GRIT_CLASS, strlen(MP_GCM_GRIT_CLASS));
                TRS.copy(MGCMTBLDAT_CV.KEY_1, sizeof(MGCMTBLDAT_CV.KEY_1), class_tbl[i], "CLASS");
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CV);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_CV SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CV.FACTORY), MGCMTBLDAT_CV.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CV.TABLE_NAME), MGCMTBLDAT_CV.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //분류 기준이 있고 합격인 경우 END 처리를 한다. 
                if (iCheckClass == MP_TRUE && MGCMTBLDAT_CL.DATA_4[0] == 'Y')
                {
                    //LOT 완료
                    end_in = TRS.add_node(in_node, "end_in");
                    TRS.add_char(end_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(end_in, in_node);

                    TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
                    TRS.add_string(end_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
                    //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                    TRS.add_char(end_in, "CLASS_OPER_SKIP", 'Y');

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    d_split_qty += TRS.get_double(class_tbl[i], "QTY");

                    //이전 LOT의 투입 수량
                    DBU_init_minvlotiss(&MINVLOTISS_OLD);
                    memcpy(MINVLOTISS_OLD.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MINVLOTISS_OLD.FACTORY));
                    memcpy(MINVLOTISS_OLD.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS_OLD.LOT_ID));
                    dOldQty = DBU_select_minvlotiss_scalar(2, &MINVLOTISS_OLD);

                    //자재사용 저장
                    DBU_init_minvlotiss(&MINVLOTISS);
                    memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                    memcpy(MINVLOTISS.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    MINVLOTISS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE));
                    TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
                    memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME));
                    memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX_SPLIT.LAST_COMMENT, sizeof(MWIPLOTSTSX_SPLIT.LAST_COMMENT));

                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX.MAT_ID)) == MP_FALSE)
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MINVLOTISS.MAT_ID));
                    else
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MINVLOTISS.MAT_ID));

                    MINVLOTISS.MAT_VER = 1;

                    TRS.copy(MINVLOTISS.AREA_ID, sizeof(MINVLOTISS.AREA_ID), in_node, "AREA_ID");
                    TRS.copy(MINVLOTISS.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
                    TRS.copy(MINVLOTISS.OPER, sizeof(MINVLOTISS.OPER), in_node, "OPER");

                    //양품대비 사용양
                    MINVLOTISS.TRAN_QTY = COM_dbl_round(d_Sum_Qty * (MWIPLOTSTSX_SPLIT.QTY_1 / d_Good_Qty), 1, 'U');
                    d_Unit = COM_dbl_round(MINVLOTISS.TRAN_QTY / MWIPLOTSTSX_SPLIT.QTY_1, 1, 'U');                  
                    COM_dtoa(MINVLOTISS.TRAN_UNIT, d_Unit, sizeof(MINVLOTISS.TRAN_UNIT));
                    MINVLOTISS.TRAN_QTY_2 = d_Sum_Qty;
                    
                    if (dOldQty == 0 || MGCMTBLDAT.DATA_5[0] == 'Y')
                        MINVLOTISS.TRAN_QTY_3 = atof(MWIPLOTSTSX.RESV_FIELD_2) * (MINVLOTISS.TRAN_QTY / d_Sum_Qty);
                    else
                        MINVLOTISS.TRAN_QTY_3 = dOldQty * (MINVLOTISS.TRAN_QTY / d_Sum_Qty);

                    memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX_SPLIT.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.ORDER_ID, MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));
                    memcpy(MINVLOTISS.REASON_CODE, MP_INPUT_TYPE_LOT, strlen(MP_INPUT_TYPE_LOT));

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

                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                }                
                else
                {
                    loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                    CopyDefaultMembers(loss_in, in_node);
                    TRS.add_char(loss_in, IN_PROCSTEP, '1');

                    TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(loss_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));

                    TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_double(loss_in, "OUT_QTY_1", 0);

                    unit_in = TRS.add_node(loss_in, "UNIT1");
                        
                    if (MGCMTBLDAT_CV.DATA_5[0] == 'Y')
                        TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_SIZE, strlen(MP_LOSS_CODE_SIZE));
                    else 
                        TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));

                    TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
                    TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                    //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                    TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');
                    TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                    if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                        return MP_FALSE;

                    d_loss_qty += MWIPLOTSTSX_SPLIT.QTY_1;
                }

                //모든 분류 정보를 저장한다.
                DBU_init_cwiplotcls(&CWIPLOTCLS);
                TRS.copy(CWIPLOTCLS.FACTORY, sizeof(CWIPLOTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPLOTCLS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                CWIPLOTCLS.HIST_SEQ = i_lot_seq;
                memcpy(CWIPLOTCLS.CLASS_TYPE, MGCMTBLDAT.DATA_1, sizeof(CWIPLOTCLS.CLASS_TYPE));
                TRS.copy(CWIPLOTCLS.CLASS_VALUE, sizeof(CWIPLOTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                CWIPLOTCLS.QTY_1 = TRS.get_double(class_tbl[i], "QTY");
                TRS.copy(CWIPLOTCLS.JUDGE_TYPE, sizeof(CWIPLOTCLS.JUDGE_TYPE), class_tbl[i], "LOSS_CONFIRM");
                memcpy(CWIPLOTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPLOTCLS.MAT_GROUP));
                
                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                else
                {
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                //MWIPLOTSTSX_SPLIT
                memcpy(CWIPLOTCLS.OUT_MAT_ID, MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                memcpy(CWIPLOTCLS.OUT_LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

                TRS.copy(CWIPLOTCLS.CREATE_USER_ID, sizeof(CWIPLOTCLS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.CREATE_TIME));
                TRS.copy(CWIPLOTCLS.UPDATE_USER_ID, sizeof(CWIPLOTCLS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.UPDATE_TIME));

                DBU_insert_cwiplotcls(&CWIPLOTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPLOTCLS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCLS.FACTORY), CWIPLOTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCLS.LOT_ID), CWIPLOTCLS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPLOTCLS.CLASS_TYPE), CWIPLOTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPLOTCLS.CLASS_VALUE), CWIPLOTCLS.CLASS_VALUE);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }

            //LOT ID 를 재조회 한다.
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

            if (MWIPLOTSTSX.QTY_1 > 0)
            {
                loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in, in_node);
                TRS.add_char(loss_in, IN_PROCSTEP, '1');

                TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                
                TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_double(loss_in, "OUT_QTY_1", 0);

                unit_in = TRS.add_node(loss_in, "UNIT1");
                TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_SIZE, strlen(MP_LOSS_CODE_SIZE));
                TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX.QTY_1);
                TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');
                TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                    return MP_FALSE;

                d_loss_qty += MWIPLOTSTSX.QTY_1;
            }
        }
        //자성분류
        else if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_MAGN, strlen(MP_CLASS_TYPE_MAGN)) == MP_FALSE)
        {
            class_tbl = TRS.get_list(in_node, "CLASS_TBL");
            i_class_count = TRS.get_item_count(in_node, "CLASS_TBL");

            for (int i = 0; i < i_class_count; i++)
            {
                memset(s_lot_id, ' ', sizeof(s_lot_id));
                memset(dtoChar, ' ', sizeof(dtoChar));
                iCheckClass = MP_FALSE;

                gen_in_node = TRS.add_node(in_node, "gen_in_node");
                TRS.add_char(gen_in_node, "PROCSTEP", '2');
                CopyDefaultMembers(gen_in_node, in_node);
                TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_7, sizeof(MGCMTBLDAT.DATA_7));
                TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "SEQ_KEY_1"));
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
                memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                TRS.free_node(cmn_out);

                // 2) 자LOT SPLIT
                split_in = TRS.add_node(in_node, "split_in");
                CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(split_in, "PROCSTEP", '1');
                TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
                TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
                TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(class_tbl[i], "QTY")); // QTY_1 유효중량
                TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
                TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1 - TRS.get_double(class_tbl[i], "QTY"));   //split 전 모랏의 총 수량
                TRS.add_nstring(split_in, "GRT_CMF_3", TRS.get_string(class_tbl[i], "CLASS"));                
                dQty = TRS.get_double(class_tbl[i], "QTY");
                COM_dtoa(dtoChar, dQty, sizeof(dtoChar));                
                TRS.add_string(split_in, "GRT_CMF_4", dtoChar, sizeof(dtoChar));

                TRS.add_string(split_in, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
                TRS.add_string(split_in, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
                TRS.add_string(split_in, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
                TRS.add_string(split_in, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                d_split_qty += TRS.get_double(class_tbl[i], "QTY");

                //split된 lot을 재 조회 한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                iCheckClass = MP_FALSE;

                //분류정보 조회
                DBU_init_cwipgrtcls(&CWIPGRTCLS);
                TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                
                //새로운 mat id로 lot 을 생성하는 공정 여부
                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }
                else
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }

                TRS.copy(CWIPGRTCLS.CLASS_VALUE, sizeof(CWIPGRTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                    DBU_init_cwipgrtcls(&CWIPGRTCLS);
                    TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                    memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                    TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                    
                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }
                    else
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }

                    memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                    DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                        DBU_init_cwipgrtcls(&CWIPGRTCLS);
                        TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                        memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                        TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            iCheckClass = MP_TRUE;
                        }
                    }
                    else if (DB_error_code == DB_SUCCESS)
                    {
                        iCheckClass = MP_TRUE;
                    }
                }
                else if (DB_error_code == DB_SUCCESS)
                {
                    iCheckClass = MP_TRUE;
                }

                // 변경 mat id가 있는경우
                if (iCheckClass == MP_TRUE && CWIPGRTCLS.OUT_MAT_ID[0] != ' ')
                {
                    //MAT_ID 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPMATDEF.MAT_ID, CWIPGRTCLS.OUT_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

                    //분류표에 맞는 제품으로 adapt 처리 한다.
                    adapt_in = TRS.add_node(in_node, "apt_in");
                    TRS.add_char(adapt_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(adapt_in, in_node);

                    TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_string(adapt_in, "TO_MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_int(adapt_in, "TO_MAT_VER", MWIPMATDEF.MAT_VER);
                    TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX_SPLIT.LOT_TYPE);
                    TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX_SPLIT.LOT_PRIORITY);
                    TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX_SPLIT.CREATE_CODE, sizeof(MWIPLOTSTSX_SPLIT.CREATE_CODE));
                    TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX_SPLIT.OWNER_CODE, sizeof(MWIPLOTSTSX_SPLIT.OWNER_CODE));
                    TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));

                    TRS.add_nstring(adapt_in, "TRAN_CMF_3", "GRIT_SORT");  // GRIT분류  표기용도

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);
                }

                //split된 lot id를 재조회한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

                //LOT ID 를 재조회 한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

                //그릿 분류 정보에서 타겟 여부를 체크한다. 타겟여부가 아닌경우 loss처리 한다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_CV);
                TRS.copy(MGCMTBLDAT_CV.FACTORY, sizeof(MGCMTBLDAT_CV.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_CV.TABLE_NAME, MP_GCM_GRIT_CLASS, strlen(MP_GCM_GRIT_CLASS));
                TRS.copy(MGCMTBLDAT_CV.KEY_1, sizeof(MGCMTBLDAT_CV.KEY_1), class_tbl[i], "CLASS");
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CV);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_CV SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CV.FACTORY), MGCMTBLDAT_CV.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CV.TABLE_NAME), MGCMTBLDAT_CV.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //자성분류에서는 타겟 여부로 lot 진행이 결정되므로 iCheckClass는 무의미 하다.
                //target 여부가 Y인 경우(약자성) 만 end 처리 하고 나머지(강자성)은 loss처리 한다.
                if (MGCMTBLDAT_CV.DATA_4[0] == 'Y')
                {
                    //LOT 완료
                    end_in = TRS.add_node(in_node, "end_in");
                    TRS.add_char(end_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(end_in, in_node);

                    TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
                    TRS.add_string(end_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
                    //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                    TRS.add_char(end_in, "CLASS_OPER_SKIP", 'Y');

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    d_split_qty += TRS.get_double(class_tbl[i], "QTY");

                    //이전 LOT의 투입 수량
                    DBU_init_minvlotiss(&MINVLOTISS_OLD);
                    memcpy(MINVLOTISS_OLD.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MINVLOTISS_OLD.FACTORY));
                    memcpy(MINVLOTISS_OLD.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS_OLD.LOT_ID));
                    dOldQty = DBU_select_minvlotiss_scalar(2, &MINVLOTISS_OLD);

                    //자재사용 저장
                    DBU_init_minvlotiss(&MINVLOTISS);
                    memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                    memcpy(MINVLOTISS.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    MINVLOTISS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE));
                    TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
                    memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME));
                    memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX_SPLIT.LAST_COMMENT, sizeof(MWIPLOTSTSX_SPLIT.LAST_COMMENT));

                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MINVLOTISS.MAT_ID));
                    else
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MINVLOTISS.MAT_ID));

                    MINVLOTISS.MAT_VER = 1;

                    TRS.copy(MINVLOTISS.AREA_ID, sizeof(MINVLOTISS.AREA_ID), in_node, "AREA_ID");
                    TRS.copy(MINVLOTISS.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
                    TRS.copy(MINVLOTISS.OPER, sizeof(MINVLOTISS.OPER), in_node, "OPER");

                    //자성분류인 경우 약자성에서 무조건 전체 수량을 다 먹는다. 
                    //MINVLOTISS.TRAN_QTY = COM_dbl_round(d_Sum_Qty * (MWIPLOTSTSX_SPLIT.QTY_1 / d_Sum_Qty), 1, 'U');
                    MINVLOTISS.TRAN_QTY = d_Sum_Qty;
                    d_Unit = COM_dbl_round(MINVLOTISS.TRAN_QTY / MWIPLOTSTSX_SPLIT.QTY_1, 1, 'U');
                    COM_dtoa(MINVLOTISS.TRAN_UNIT, d_Unit, sizeof(MINVLOTISS.TRAN_UNIT));
                    MINVLOTISS.TRAN_QTY_2 = d_Sum_Qty;

                    if (dOldQty == 0 || MGCMTBLDAT.DATA_5[0] == 'Y')
                        MINVLOTISS.TRAN_QTY_3 = atof(MWIPLOTSTSX.RESV_FIELD_2) * (MINVLOTISS.TRAN_QTY / d_Sum_Qty);
                    else
                        MINVLOTISS.TRAN_QTY_3 = dOldQty * (MINVLOTISS.TRAN_QTY / d_Sum_Qty);

                    memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX_SPLIT.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.ORDER_ID, MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));
                    memcpy(MINVLOTISS.REASON_CODE, MP_INPUT_TYPE_LOT, strlen(MP_INPUT_TYPE_LOT));

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

                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                }
                else
                {                    
                    // if(MGCMTBLDAT_CV.DATA_5[0] == 'Y')
                    loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                    CopyDefaultMembers(loss_in, in_node);
                    TRS.add_char(loss_in, IN_PROCSTEP, '1');

                    TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(loss_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));

                    TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_double(loss_in, "OUT_QTY_1", 0);
                    TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                    unit_in = TRS.add_node(loss_in, "UNIT1");
                  
                    if (MGCMTBLDAT_CV.DATA_5[0] == 'Y')
                        TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_MAGN, strlen(MP_LOSS_CODE_MAGN));
                    else
                        TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));


                    TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
                    
                    TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                    //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                    TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');

                    if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                        return MP_FALSE;

                    d_loss_qty += MWIPLOTSTSX_SPLIT.QTY_1;
                }

                //모든 분류 정보를 저장한다.
                DBU_init_cwiplotcls(&CWIPLOTCLS);
                TRS.copy(CWIPLOTCLS.FACTORY, sizeof(CWIPLOTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPLOTCLS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                CWIPLOTCLS.HIST_SEQ = i_lot_seq;
                memcpy(CWIPLOTCLS.CLASS_TYPE, MGCMTBLDAT.DATA_1, sizeof(CWIPLOTCLS.CLASS_TYPE));
                TRS.copy(CWIPLOTCLS.CLASS_VALUE, sizeof(CWIPLOTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                CWIPLOTCLS.QTY_1 = TRS.get_double(class_tbl[i], "QTY");
                TRS.copy(CWIPLOTCLS.JUDGE_TYPE, sizeof(CWIPLOTCLS.JUDGE_TYPE), class_tbl[i], "LOSS_CONFIRM");
                memcpy(CWIPLOTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPLOTCLS.MAT_GROUP));

                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                else
                {
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                //MWIPLOTSTSX_SPLIT
                memcpy(CWIPLOTCLS.OUT_MAT_ID, MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                memcpy(CWIPLOTCLS.OUT_LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

                TRS.copy(CWIPLOTCLS.CREATE_USER_ID, sizeof(CWIPLOTCLS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.CREATE_TIME));
                TRS.copy(CWIPLOTCLS.UPDATE_USER_ID, sizeof(CWIPLOTCLS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.UPDATE_TIME));

                DBU_insert_cwiplotcls(&CWIPLOTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPLOTCLS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCLS.FACTORY), CWIPLOTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCLS.LOT_ID), CWIPLOTCLS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPLOTCLS.CLASS_TYPE), CWIPLOTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPLOTCLS.CLASS_VALUE), CWIPLOTCLS.CLASS_VALUE);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }

            //LOT ID 를 재조회 한다.
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

            if (MWIPLOTSTSX.QTY_1 > 0)
            {
                loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in, in_node);
                TRS.add_char(loss_in, IN_PROCSTEP, '1');

                TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));

                TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_double(loss_in, "OUT_QTY_1", 0);

                unit_in = TRS.add_node(loss_in, "UNIT1");
                TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_MAGN, strlen(MP_LOSS_CODE_MAGN));
                TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX.QTY_1);
                TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');
                TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                    return MP_FALSE;

                d_loss_qty += MWIPLOTSTSX.QTY_1;
            }
        }
        //형상 분류
        else if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_CUP, strlen(MP_CLASS_TYPE_CUP)) == MP_FALSE)
        {
            class_tbl = TRS.get_list(in_node, "CLASS_TBL");
            i_class_count = TRS.get_item_count(in_node, "CLASS_TBL");

            for (int i = 0; i < i_class_count; i++)
            {
                memset(s_lot_id, ' ', sizeof(s_lot_id));
                memset(dtoChar, ' ', sizeof(dtoChar));
                iCheckClass = MP_FALSE;

                gen_in_node = TRS.add_node(in_node, "gen_in_node");
                TRS.add_char(gen_in_node, "PROCSTEP", '2');
                CopyDefaultMembers(gen_in_node, in_node);
                TRS.add_string(gen_in_node, "RULE_ID", MGCMTBLDAT.DATA_7, sizeof(MGCMTBLDAT.DATA_7));
                TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                //CLASS를 남을 파라미터를 FLOW로 사용. 
                TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(class_tbl[i], "CLASS"));
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
                memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                TRS.free_node(cmn_out);

                // 2) 자LOT SPLIT
                split_in = TRS.add_node(in_node, "split_in");
                CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(split_in, "PROCSTEP", '1');
                TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
                TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
                TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(class_tbl[i], "QTY")); // QTY_1 유효중량
                TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
                TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1 - TRS.get_double(class_tbl[i], "QTY"));   //split 전 모랏의 총 수량
                TRS.add_nstring(split_in, "GRT_CMF_5", TRS.get_string(class_tbl[i], "CLASS"));
                dQty = TRS.get_double(class_tbl[i], "QTY");
                COM_dtoa(dtoChar, dQty, sizeof(dtoChar));
                TRS.add_string(split_in, "GRT_CMF_6", dtoChar, sizeof(dtoChar));

                TRS.add_string(split_in, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
                TRS.add_string(split_in, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
                TRS.add_string(split_in, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
                TRS.add_string(split_in, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);

                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                iCheckClass = MP_FALSE;

                //분류정보 조회
                DBU_init_cwipgrtcls(&CWIPGRTCLS);
                TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                
                //새로운 mat id로 lot 을 생성하는 공정 여부
                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }
                else
                {
                    memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                }

                TRS.copy(CWIPGRTCLS.CLASS_VALUE, sizeof(CWIPGRTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                DBU_select_cwipgrtcls(1, &CWIPGRTCLS);              
                if (DB_error_code == DB_NOT_FOUND)
                {
                    //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                    DBU_init_cwipgrtcls(&CWIPGRTCLS);
                    TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                    memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                    TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                    
                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }
                    else
                    {
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID));
                    }

                    memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                    DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        //IMD-T인 경우 투입제품코드(INPUT_MAT_ID) 및 형식값(CLASS_VALUE)이 all이므로 재 조회를 한다.
                        DBU_init_cwipgrtcls(&CWIPGRTCLS);
                        TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
                        memcpy(CWIPGRTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPGRTCLS.MAT_GROUP));
                        TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), in_node, "CLASS_TYPE");
                        memcpy(CWIPGRTCLS.INPUT_MAT_ID, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        memcpy(CWIPGRTCLS.CLASS_VALUE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
                        DBU_select_cwipgrtcls(1, &CWIPGRTCLS);
                        if (DB_error_code == DB_SUCCESS)
                        {
                            iCheckClass = MP_TRUE;
                        }
                    }
                    else if (DB_error_code == DB_SUCCESS)
                    {
                        iCheckClass = MP_TRUE;
                    }
                }
                else if (DB_error_code == DB_SUCCESS)
                {
                    iCheckClass = MP_TRUE;
                }

                // 변경 mat id가 있는경우
                if (CWIPGRTCLS.OUT_MAT_ID[0] != ' ')
                {
                    //MAT_ID 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPMATDEF.MAT_ID, CWIPGRTCLS.OUT_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

                    //분류표에 맞는 제품으로 adapt 처리 한다.
                    adapt_in = TRS.add_node(in_node, "apt_in");
                    TRS.add_char(adapt_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(adapt_in, in_node);

                    TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_string(adapt_in, "TO_MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_int(adapt_in, "TO_MAT_VER", MWIPMATDEF.MAT_VER);
                    TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                    TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX_SPLIT.LOT_TYPE);
                    TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX_SPLIT.LOT_PRIORITY);
                    TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX_SPLIT.CREATE_CODE, sizeof(MWIPLOTSTSX_SPLIT.CREATE_CODE));
                    TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX_SPLIT.OWNER_CODE, sizeof(MWIPLOTSTSX_SPLIT.OWNER_CODE));
                    TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));
                    TRS.add_nstring(adapt_in, "TRAN_CMF_3", "GRIT_SORT");  // GRIT분류  표기용도

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);
                }

                //split된 lot id를 재조회한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
                memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

                //LOT ID 를 재조회 한다.
                DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

                //판정 기준을 조회한다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_CL);
                TRS.copy(MGCMTBLDAT_CL.FACTORY, sizeof(MGCMTBLDAT_CL.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_CL.TABLE_NAME, MP_GCM_GRIT_CLASS_JUDGE, strlen(MP_GCM_GRIT_CLASS_JUDGE));
                TRS.copy(MGCMTBLDAT_CL.KEY_1, sizeof(MGCMTBLDAT_CL.KEY_1), class_tbl[i], "LOSS_CONFIRM");
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CL);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_CL SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CL.FACTORY), MGCMTBLDAT_CL.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CL.TABLE_NAME), MGCMTBLDAT_CL.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //그릿 분류 정보를 조회한다.
                DBU_init_mgcmtbldat(&MGCMTBLDAT_CV);
                TRS.copy(MGCMTBLDAT_CV.FACTORY, sizeof(MGCMTBLDAT_CV.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT_CV.TABLE_NAME, MP_GCM_GRIT_CLASS, strlen(MP_GCM_GRIT_CLASS));
                TRS.copy(MGCMTBLDAT_CV.KEY_1, sizeof(MGCMTBLDAT_CV.KEY_1), class_tbl[i], "CLASS");
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CV);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_CV SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CV.FACTORY), MGCMTBLDAT_CV.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CV.TABLE_NAME), MGCMTBLDAT_CV.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //분류에서는 iCheckClass 가 의미가 없음. 무조건 LOT 생성함.
                if (MGCMTBLDAT_CL.DATA_4[0] == 'Y')
                {
                    //LOT 완료
                    end_in = TRS.add_node(in_node, "end_in");
                    TRS.add_char(end_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(end_in, in_node);

                    TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                    TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
                    TRS.add_string(end_in, "FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                    TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
                    //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                    TRS.add_char(end_in, "CLASS_OPER_SKIP", 'Y');

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    TRS.free_node(cmn_out);

                    d_split_qty += TRS.get_double(class_tbl[i], "QTY");

                    //이전 LOT의 투입 수량
                    DBU_init_minvlotiss(&MINVLOTISS_OLD);
                    memcpy(MINVLOTISS_OLD.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MINVLOTISS_OLD.FACTORY));
                    memcpy(MINVLOTISS_OLD.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS_OLD.LOT_ID));
                    dOldQty = DBU_select_minvlotiss_scalar(2, &MINVLOTISS_OLD);

                    //자재사용 저장
                    DBU_init_minvlotiss(&MINVLOTISS);
                    memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                    memcpy(MINVLOTISS.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
                    MINVLOTISS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_CODE));
                    TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
                    memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX_SPLIT.LAST_TRAN_TIME));
                    memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX_SPLIT.LAST_COMMENT, sizeof(MWIPLOTSTSX_SPLIT.LAST_COMMENT));

                    //새로운 mat id로 lot 을 생성하는 공정 여부
                    if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX.MAT_ID)) == MP_FALSE)
                    {
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MINVLOTISS.MAT_ID));
                    }
                    else
                    {
                        memcpy(MINVLOTISS.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
                    }
                    MINVLOTISS.MAT_VER = 1;

                    TRS.copy(MINVLOTISS.AREA_ID, sizeof(MINVLOTISS.AREA_ID), in_node, "AREA_ID");
                    TRS.copy(MINVLOTISS.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
                    TRS.copy(MINVLOTISS.OPER, sizeof(MINVLOTISS.OPER), in_node, "OPER");

                    MINVLOTISS.TRAN_QTY = COM_dbl_round(d_Sum_Qty * (MWIPLOTSTSX_SPLIT.QTY_1 / d_Good_Qty), 1, 'U');

                    d_Unit = COM_dbl_round(MINVLOTISS.TRAN_QTY / MWIPLOTSTSX_SPLIT.QTY_1, 1, 'U');
                    COM_dtoa(MINVLOTISS.TRAN_UNIT, d_Unit, sizeof(MINVLOTISS.TRAN_UNIT));
                    MINVLOTISS.TRAN_QTY_2 = d_Sum_Qty;

                    if (MGCMTBLDAT.DATA_6[0] == '1')
                    {
                        if (dOldQty == 0 || MGCMTBLDAT.DATA_5[0] == 'Y')
                            MINVLOTISS.TRAN_QTY_3 = COM_dbl_round(atof(MWIPLOTSTSX.RESV_FIELD_2) * (MINVLOTISS.TRAN_QTY / d_Sum_Qty), 1, 'U');
                        else
                            MINVLOTISS.TRAN_QTY_3 = COM_dbl_round(dOldQty * (MINVLOTISS.TRAN_QTY / d_Sum_Qty), 1, 'U');
                    }
                    else
                    {
                        if (dOldQty == 0)
                        {
                            MINVLOTISS.TRAN_QTY_3 = MINVLOTISS.TRAN_QTY;
                        }
                        else
                        {
                            MINVLOTISS.TRAN_QTY_3 = COM_dbl_round(dOldQty * (MWIPLOTSTSX_SPLIT.QTY_1 / d_Good_Qty), 1, 'U');
                        }
                    }

                    memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX_SPLIT.LAST_ACTIVE_HIST_SEQ;
                    memcpy(MINVLOTISS.ORDER_ID, MWIPLOTSTSX_SPLIT.ORDER_ID, sizeof(MWIPLOTSTSX_SPLIT.ORDER_ID));
                    memcpy(MINVLOTISS.REASON_CODE, MP_INPUT_TYPE_LOT, strlen(MP_INPUT_TYPE_LOT));

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

                    //flow의 마지막 공정을 조회한다.
                    DBU_init_mwipflwopr(&MWIPFLWOPR);
                    DBU_init_mwipoprdef(&MWIPOPRDEF_INV);
                    TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPFLWOPR.FLOW, MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));
                    DBU_select_mwipflwopr(4, &MWIPFLWOPR);
                    if (DB_error_code == DB_SUCCESS)
                    {                        
                        TRS.copy(MWIPOPRDEF_INV.FACTORY, sizeof(MWIPOPRDEF_INV.FACTORY), in_node, IN_FACTORY);
                        memcpy(MWIPOPRDEF_INV.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                        DBU_select_mwipoprdef(1, &MWIPOPRDEF_INV);
                    }

                    //ERP 실적을 올려보낸다.
                    //DATA_6 형상 분류 차수를 나타낸다.
                    
                    //MAT_ID 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

                    if_end_in = TRS.add_node(in_node, "if_end_in");
                    TRS.add_char(if_end_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(if_end_in, in_node);

                    TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
                    TRS.add_int(if_end_in, "ERP_WO_ID", atoi(MP_ERP_ORDER_ID_2));
                    TRS.add_string(if_end_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    TRS.add_int(if_end_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
                    TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_44));
                    TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));                        
                    TRS.add_string(if_end_in, "INV_OPER", MWIPOPRDEF_INV.OPER_CMF_1, sizeof(MWIPOPRDEF_INV.OPER_CMF_1));
                    TRS.add_int(if_end_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                    TRS.add_string(if_end_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    TRS.add_string(if_end_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_double(if_end_in, "QTY", MWIPLOTSTSX_SPLIT.QTY_1);
                    TRS.add_string(if_end_in, "MES_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                    TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    dHeaderSeq = TRS.get_double(cmn_out, "TRAN_HEADER_ID");
                    TRS.free_node(cmn_out);

                    //자재 소요 MAT_ID 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF_ERP);
                    TRS.copy(MWIPMATDEF_ERP.FACTORY, sizeof(MWIPMATDEF_ERP.FACTORY), in_node, IN_FACTORY);

                    if (MGCMTBLDAT.DATA_6[0] == '1')
                        memcpy(MWIPMATDEF_ERP.MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MWIPMATDEF_ERP.MAT_ID));
                    else if (MGCMTBLDAT.DATA_6[0] == '2' || MGCMTBLDAT.DATA_6[0] == '3')
                        memcpy(MWIPMATDEF_ERP.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF_ERP.MAT_ID));
                    else
                    {           
                        memcpy(MWIPMATDEF_ERP.MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MWIPMATDEF_ERP.MAT_ID));
                    }

                    MWIPMATDEF_ERP.MAT_VER = 1;
                    DBU_select_mwipmatdef(1, &MWIPMATDEF_ERP);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0006 : 이 제품은 존재 하지 않습니다.
                        strcpy(s_msg_code, "WIP-0006");
                        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_ERP.FACTORY), MWIPMATDEF_ERP.FACTORY);
                        TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_ERP.MAT_ID), MWIPMATDEF_ERP.MAT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    if_end_in = TRS.add_node(in_node, "if_end_in");
                    TRS.add_char(if_end_in, IN_PROCSTEP, '1');
                    CopyDefaultMembers(if_end_in, in_node);

                    TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
                    TRS.add_int(if_end_in, "ERP_WO_ID", atoi(MP_ERP_ORDER_ID_2));
                    TRS.add_string(if_end_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    TRS.add_int(if_end_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
                    TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
                    TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
                    TRS.add_string(if_end_in, "INV_OPER", MWIPOPRDEF_INV.OPER_CMF_1, sizeof(MWIPOPRDEF_INV.OPER_CMF_1));
                    TRS.add_int(if_end_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_ERP.MAT_CMF_1, sizeof(MWIPMATDEF_ERP.MAT_CMF_1)));
                    TRS.add_string(if_end_in, "MAT_ID", MWIPMATDEF_ERP.MAT_ID, sizeof(MWIPMATDEF_ERP.MAT_ID));
                    TRS.add_string(if_end_in, "UNIT", MWIPMATDEF_ERP.UNIT_1, sizeof(MWIPMATDEF_ERP.UNIT_1));
                    TRS.add_double(if_end_in, "QTY", MINVLOTISS.TRAN_QTY_3);
                    TRS.add_string(if_end_in, "MES_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                    TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    TRS.add_double(if_end_in, "TRAN_HEADER_ID", dHeaderSeq);
                    TRS.add_double(if_end_in, "SRC_TRAN_ID", dHeaderSeq);

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }

                    TRS.free_node(cmn_out);
                    

                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                }                
                else
                {
                    //if (MGCMTBLDAT_CV.DATA_5[0] == 'Y')
                    //{
                        loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                        CopyDefaultMembers(loss_in, in_node);
                        TRS.add_char(loss_in, IN_PROCSTEP, '1');

                        TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                        TRS.add_string(loss_in, "OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                        TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX_SPLIT.OPER, sizeof(MWIPLOTSTSX_SPLIT.OPER));
                        TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX_SPLIT.FLOW, sizeof(MWIPLOTSTSX_SPLIT.FLOW));

                        TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                        TRS.add_double(loss_in, "OUT_QTY_1", 0);

                        unit_in = TRS.add_node(loss_in, "UNIT1");

                        if (MGCMTBLDAT_CV.DATA_5[0] == 'Y')
                            TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_CUP, strlen(MP_LOSS_CODE_CUP));
                        else
                            TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK));

                        TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX_SPLIT.QTY_1);
                        TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                        //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                        TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');
                        TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                        if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                            return MP_FALSE;

                        d_loss_qty += MWIPLOTSTSX_SPLIT.QTY_1;
                    //}
                    //else if (MGCMTBLDAT_CL.DATA_2[0] != ' ')
                    //{
                    //    move_in = TRS.add_node(in_node, "move_in");
                    //    TRS.add_char(move_in, IN_PROCSTEP, '1');
                    //    CopyDefaultMembers(move_in, in_node);

                    //    TRS.add_string(move_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
                    //    TRS.add_nstring(move_in, "OPER", TRS.get_string(in_node, "OPER"));
                    //    TRS.add_string(move_in, "TO_OPER", MGCMTBLDAT_CL.DATA_3, sizeof(MGCMTBLDAT_CL.DATA_3));
                    //    TRS.add_nstring(move_in, "TYPE", "GRIT");
                    //    TRS.add_string(move_in, "LOT_CMF_11", "D", strlen("D"));

                    //    cmn_out = TRS.create_node("Cmn_Out");
                    //    if (CUS_WIP_STORE_LOT(s_msg_code, move_in, cmn_out) == MP_FALSE)
                    //    {
                    //        TRS.clone(out_node, cmn_out);
                    //        TRS.free_node(cmn_out);
                    //        return MP_FALSE;
                    //    }
                    //    TRS.free_node(cmn_out);

                    //    d_loss_qty += MWIPLOTSTSX_SPLIT.QTY_1;
                    //}
                }

                //모든 분류 정보를 저장한다.
                DBU_init_cwiplotcls(&CWIPLOTCLS);
                TRS.copy(CWIPLOTCLS.FACTORY, sizeof(CWIPLOTCLS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPLOTCLS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                CWIPLOTCLS.HIST_SEQ = i_lot_seq;
                memcpy(CWIPLOTCLS.CLASS_TYPE, MGCMTBLDAT.DATA_1, sizeof(CWIPLOTCLS.CLASS_TYPE));
                TRS.copy(CWIPLOTCLS.CLASS_VALUE, sizeof(CWIPLOTCLS.CLASS_VALUE), class_tbl[i], "CLASS");
                CWIPLOTCLS.QTY_1 = TRS.get_double(class_tbl[i], "QTY");
                TRS.copy(CWIPLOTCLS.JUDGE_TYPE, sizeof(CWIPLOTCLS.JUDGE_TYPE), class_tbl[i], "LOSS_CONFIRM");
                memcpy(CWIPLOTCLS.MAT_GROUP, MGCMTBLDAT.DATA_2, sizeof(CWIPLOTCLS.MAT_GROUP));

                if (MGCMTBLDAT.DATA_5[0] == 'Y' || memcmp(MWIPLOTSTSX_SPLIT.MAT_ID, MGCMTBLDAT.DATA_4, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID)) == MP_FALSE)
                {
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.RESV_FIELD_1, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                else
                { 
                    memcpy(CWIPLOTCLS.INPUT_MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(CWIPLOTCLS.INPUT_MAT_ID));
                }
                //MWIPLOTSTSX_SPLIT
                memcpy(CWIPLOTCLS.OUT_MAT_ID, MWIPLOTSTSX_SPLIT.MAT_ID, sizeof(MWIPLOTSTSX_SPLIT.MAT_ID));
                memcpy(CWIPLOTCLS.OUT_LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

                TRS.copy(CWIPLOTCLS.CREATE_USER_ID, sizeof(CWIPLOTCLS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.CREATE_TIME));
                TRS.copy(CWIPLOTCLS.UPDATE_USER_ID, sizeof(CWIPLOTCLS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTCLS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCLS.UPDATE_TIME));

                DBU_insert_cwiplotcls(&CWIPLOTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPLOTCLS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCLS.FACTORY), CWIPLOTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCLS.LOT_ID), CWIPLOTCLS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPLOTCLS.CLASS_TYPE), CWIPLOTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPLOTCLS.CLASS_VALUE), CWIPLOTCLS.CLASS_VALUE);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }

            //LOT ID 를 재조회 한다.
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i_use_lot_count], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

            if (MWIPLOTSTSX.QTY_1 > 0)
            {
                loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in, in_node);
                TRS.add_char(loss_in, IN_PROCSTEP, '1');

                TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));

                TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_double(loss_in, "OUT_QTY_1", 0);

                unit_in = TRS.add_node(loss_in, "UNIT1");
                TRS.add_string(unit_in, "LOSS_CODE", MP_LOSS_CODE_MAGN, strlen(MP_LOSS_CODE_MAGN));
                TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX.QTY_1);
                TRS.add_char(loss_in, "SKIP_IF_YN", 'Y');
                //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
                TRS.add_char(loss_in, "CLASS_OPER_SKIP", 'Y');
                TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                    return MP_FALSE;

                d_loss_qty += MWIPLOTSTSX.QTY_1;
            }
        }
        //혼합공정인 경우
        else if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_NONE, strlen(MP_CLASS_TYPE_NONE)) == MP_FALSE)
        {
            //LOT 완료
            end_in = TRS.add_node(in_node, "end_in");
            TRS.add_char(end_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(end_in, in_node);

            TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
            TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_char(end_in, "SKIP_IF_YN", 'Y');
            //작업지시 실적 업그레이드 스킵을 위함. 분류에서는 작업지시가 가상의 작업지시이기 때문.
            TRS.add_char(end_in, "CLASS_OPER_SKIP", 'Y');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            d_split_qty = MWIPLOTSTSX.QTY_1;

            list_item = TRS.add_node(out_node, "LOT_TBL");
            TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        }

        // 혼합공정은 모 Lot으로 End Lot을 하기 때문에 대상에서 제외함.
        if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_NONE, strlen(MP_CLASS_TYPE_NONE)) != 0)
        //{
        //    // Lot Summary END_DATE, END_TIME, END_DAY_NIGTH 보정
        //    if(Adjust_Lot_Summary(s_msg_code, i_start_hist_seq, d_split_qty, d_loss_qty, &work_date, in_node, out_node) == MP_FALSE)
        //        return MP_FALSE;
        //}

        // 설비 효율 데이터 생성
        // 2020-11-07
        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        {
            res_wip = TRS.add_node(in_node, "RES_WIP");
            CopyDefaultMembers(res_wip, in_node);

            TRS.add_nstring(res_wip, "LOT_ID", TRS.get_string(Lot_tbl[0], "LOT_ID"));
            TRS.add_nstring(res_wip, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_int(res_wip, "START_HIST_SEQ", i_start_hist_seq);

            if (memcmp(MGCMTBLDAT.DATA_1, MP_CLASS_TYPE_NONE, strlen(MP_CLASS_TYPE_NONE)) == MP_FALSE)
            {
                TRS.add_double(res_wip, "IN_QTY", MWIPLOTSTSX.QTY_1);
                TRS.add_double(res_wip, "LOSS_QTY", 0);
                TRS.add_double(res_wip, "OUT_QTY", MWIPLOTSTSX.QTY_1);
            }
            else
            {
                TRS.add_double(res_wip, "IN_QTY", d_split_qty + d_loss_qty);
                TRS.add_double(res_wip, "LOSS_QTY", d_loss_qty);
                TRS.add_double(res_wip, "OUT_QTY", d_split_qty);
            }

            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[0], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

            if(memcpy(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END)) == 0)
                TRS.add_int(res_wip, "END_HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);

            TRS.add_string(res_wip, "END_DATE", work_date.s_work_date, sizeof(work_date.s_work_date));
            TRS.add_string(res_wip, "END_TIME", MWIPLOTSTSX.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX.LAST_TRAN_TIME));
            TRS.add_string(res_wip, "END_DAY_NIGHT", work_date.s_day_night, sizeof(work_date.s_day_night));

            TRS.set_nstring(res_wip, "TRAN_CODE", "END");

            if(Update_Res_Wip_Summary(s_msg_code, res_wip, out_node) == MP_FALSE)
                return MP_FALSE;   
        }
    }
    //step 3 : 시작된 lot에 merge
    //         IMD-T인 경우 2,3차 분류에서 시작된 lot에 다른 lot을 merge 하여 이후에 end 처리 한다. 
    //         시작 처리된 lot에 대기중인 lot을 merge 한다.
    else if (TRS.get_procstep(in_node) == '3')
    {
        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        if (MGCMTBLDAT.DATA_8[0] == 'Y')
        {
            memset(s_lot_id, ' ', sizeof(s_lot_id));

            //MAIN Lot 찾기 
            for (int i = 0; i < i_lot_count; i++)
            {
                if (TRS.get_char(Lot_tbl[i], "MAIN_YN") == 'Y')
                {
                    TRS.copy(s_lot_id, sizeof(s_lot_id), Lot_tbl[i], "LOT_ID");
                }
            }

            //mergr lot을 조회한다.
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            memcpy(MWIPLOTSTSX.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX.LOT_ID));
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

            for (int i = 0; i < i_lot_count; i++)
            {
                if (TRS.mem_cmp(Lot_tbl[i], "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)) == MP_FALSE)
                    continue;

                //투입될 LOT정보 조회
                DBU_init_mwiplotstsx(&MWIPLOTSTSX_INTO);
                TRS.copy(MWIPLOTSTSX_INTO.LOT_ID, sizeof(MWIPLOTSTSX_INTO.LOT_ID), Lot_tbl[i], "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_INTO);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_INTO.FACTORY), MWIPLOTSTSX_INTO.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_INTO.LOT_ID), MWIPLOTSTSX_INTO.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //같은 공정에 있는지 체크
                if (memcmp(MWIPLOTSTSX.OPER, MWIPLOTSTSX_INTO.OPER, sizeof(MWIPLOTSTSX_INTO.OPER)) != MP_FALSE)
                {
                    //WIP-0638 : 공정이 다르면 Lot을 병합 할 수 없습니다.
                    strcpy(s_msg_code, "WIP-0638");
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }

                //같은 MAT ID 인지 체크 
                if (memcmp(MWIPLOTSTSX.MAT_ID, MWIPLOTSTSX_INTO.MAT_ID, sizeof(MWIPLOTSTSX_INTO.MAT_ID)) != MP_FALSE)
                {
                    //WIP-0637 : 품목이 다르면 Lot을 병합 할 수 없습니다.
                    strcpy(s_msg_code, "WIP-0637");
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }

                //이동지시 LOT LIST를 각각 merge lot에 merge 시켜준다.
                merge_in = TRS.add_node(in_node, "merge_in");
                TRS.add_char(merge_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(merge_in, in_node);

                TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTSX_INTO.LOT_ID, sizeof(MWIPLOTSTSX_INTO.LOT_ID));
                TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTSX_INTO.QTY_1);
                TRS.add_char(merge_in, "SKIP_OPER_CHECK", 'Y');

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }

            TRS.add_string(out_node, "LOT_ID", s_lot_id, sizeof(s_lot_id));
        }
        else
        {
            //WIP-0636 : 이공정은 병합 가능 공정이 아닙니다.
            strcpy(s_msg_code, "WIP-0636");
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
            TRS.add_fieldmsg(out_node, "OPER_DESC", MP_STR, sizeof(MWIPOPRDEF.OPER_DESC), MWIPOPRDEF.OPER_DESC);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    if (TRS.get_procstep(in_node) != '3')
    {
        res_in = TRS.add_node(in_node, "res_in_node");
        TRS.add_char(res_in, "PROCSTEP", '1');
        CopyDefaultMembers(res_in, in_node);


        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        {
            DBU_init_mrasresdef(&MRASRESDEF);
            TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");

            // 설비 상태를 자동으로 변경 해준다.
            if (TRS.get_procstep(in_node) == '1')
            {
                //start시 비가동이 완료가 되어있지 않은 경우 start시 비가동을 완료 시켜준다.
                if (Update_Resource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'R', res_in, out_node) == MP_FALSE)
                {
                    return MP_FALSE;
                }
            }
            else if (TRS.get_procstep(in_node) == '2')
            {
                //end시에는 설비에 tool이 작착된 경우 사용횟수를 올려준다. => 로직 추가 예정
                if (Update_Resource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'I', res_in, out_node) == MP_FALSE)
                {
                    return MP_FALSE;
                }
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Grit_Class_Process_Validation()
- Validation Check sub function of "CUS_WIP_GRIT_CLASS_PROCESS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Grit_Class_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
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
