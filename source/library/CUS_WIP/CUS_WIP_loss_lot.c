/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_loss_lot.c
Description : Tran Loss Lot function

MES Version : 5.0

Function List


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/03  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include <stdio.h>

int CUS_WIP_Loss_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Loss_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Loss_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Loss_Lot()
- Tran Loss Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Loss_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_LOSS_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Loss_Lot", out_node);
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
CUS_WIP_LOSS_LOT()
- Main sub function of "CUS_WIP_Loss_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_LOSS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTS_TAG MWIPLOTSTS;
    struct work_date_tag work_date;

    TRSNode *loss_in_node;
    TRSNode **loss_list;
    TRSNode *unit1_list;

    int i_loss_count;
    char s_factory[10];

	char s_member[5][101] = { "LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
	char s_member_name[101];

    LOG_head("CUS_WIP_Loss_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Loss_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //LOT정보 조회
    DBC_init_mwiplotsts(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBC_select_mwiplotsts(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    //loss 시작
    loss_in_node = TRS.add_node(in_node, "loss_in_node");

    TRS.add_char(loss_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(loss_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(loss_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(loss_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_string(loss_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    TRS.add_int(loss_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);
    TRS.add_string(loss_in_node, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(loss_in_node, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(loss_in_node, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_nstring(loss_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(loss_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    TRS.set_double(loss_in_node, "OUT_QTY_1", TRS.get_double(in_node, "OUT_QTY_1"));
    TRS.set_double(loss_in_node, "OUT_QTY_2", TRS.get_double(in_node, "OUT_QTY_2"));
    TRS.set_double(loss_in_node, "OUT_QTY_3", TRS.get_double(in_node, "OUT_QTY_3"));

    TRS.add_nstring(loss_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
    TRS.add_nstring(loss_in_node, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));
    TRS.add_nstring(loss_in_node, "CAUSE_OPER", TRS.get_string(in_node, "CAUSE_OPER"));
    TRS.add_nstring(loss_in_node, "CAUSE_RES_ID", TRS.get_string(in_node, "RES_ID"));

    loss_list = TRS.get_list(in_node, "UNIT1");
    i_loss_count = TRS.get_item_count(in_node, "UNIT1");

    for (int i = 0; i < i_loss_count; i++)
    {
        unit1_list = TRS.add_node(loss_in_node, "UNIT1");
        TRS.add_nstring(unit1_list, "CODE", TRS.get_string(loss_list[i], "LOSS_CODE"));
        TRS.add_double(unit1_list, "QTY", TRS.get_double(loss_list[i], "LOSS_QTY"));
        TRS.set_char(unit1_list, "NO_SCRAP_FLAG", ' ');      
    }

    TRS.add_nstring(loss_in_node, "LOSS_COMMENT", TRS.get_string(in_node, "LOSS_COMMENT"));

    //추가 정보성 데이터
    TRS.add_string(loss_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(loss_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(loss_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(loss_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_char(loss_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
    TRS.add_char(loss_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
    TRS.add_char(loss_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
    TRS.add_char(loss_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
    TRS.add_char(loss_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
    TRS.add_nstring(loss_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
    TRS.add_nstring(loss_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
    TRS.add_nstring(loss_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
    TRS.add_nstring(loss_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
    TRS.add_nstring(loss_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));
    TRS.add_char(loss_in_node, "SKIP_IF_YN", TRS.get_char(in_node, "SKIP_IF_YN"));    
    TRS.add_char(loss_in_node, "CLASS_OPER_SKIP", TRS.get_char(in_node, "CLASS_OPER_SKIP"));  //분류정보시 작지 실적UPDATE SKIP여부
    TRS.add_char(loss_in_node, "NO_AUTOMATIC_TERMINATE_LOT", ' ');
    TRS.add_char(loss_in_node, "ETC_OUT_YN", TRS.get_char(in_node, "ETC_OUT_YN"));

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			sprintf(s_member_name, "%s%d", s_member[j], i + 1);
			TRS.add_nstring(loss_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
		}
	}

    if (CUS_WIP_Loss_Lot_Before_Transaction(s_msg_code, 0, loss_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_LOSS_LOT(s_msg_code, loss_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Loss_Lot_After_Transaction(s_msg_code, 0, loss_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }



    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Loss_Lot_Validation()
- Validation Check sub function of "CUS_WIP_LOSS_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Loss_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Loss_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_LOSS_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Loss_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Loss_Lot_After_Transaction()
- Main sub function of "CUS_WIP_LOSS_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Loss_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{  
    struct MWIPORDSTS_TAG   MWIPORDSTS;         //작업지시 마스터
    struct CWIPORDOPR_TAG   CWIPORDOPR;
    struct CWIPERPOPR_TAG   CWIPERPOPR;         //
    struct MWIPOPRDEF_TAG   MWIPOPRDEF;
    struct MWIPOPRDEF_TAG   MWIPOPRDEF_FROM;
    struct MWIPFLWOPR_TAG   MWIPFLWOPR;
    struct MGCMTBLDAT_TAG   MGCMTBLDAT_AREA;
    struct MGCMTBLDAT_TAG   MGCMTBLDAT_SRC;
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
    struct MWIPLOTLOS_TAG   MWIPLOTLOS;
    struct MWIPMATDEF_TAG   MWIPMATDEF;
    struct CWIPLOTREC_TAG   CWIPLOTREC;                   //부외재고 테이블
    struct MINVETCLOT_TAG   MINVETCLOT;
    struct CBASTXNDEF_TAG   CBASTXNDEF;
    struct CBASTXNDEF_TAG   CBASTXNDEF_ETC;
    struct IF_INV_TXNS_TAG   IF_INV_TXNS;

    struct work_date_tag work_date;
    TRSNode *if_in;
    TRSNode *cmn_out;

    char s_factory[10];

	//CMF UPDATE
	if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

    TRS.add_nstring(in_node, "TRAN_CODE", "LOSS");
    //// Lot 별 Summary
    if (Update_Lot_Summary(s_msg_code, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    memset(s_factory, ' ', sizeof(s_factory));
    memset(&work_date, ' ', sizeof(work_date));
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);    
    Get_shift(s_factory, &work_date);

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

    //불량 정보 조회
    DBC_init_mwiplotlos(&MWIPLOTLOS);
    memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    MWIPLOTLOS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
    MWIPLOTLOS.QTY_FLAG = '1';
    DBC_select_mwiplotlos(1, &MWIPLOTLOS);

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

    //LOT ID에 대한 품목 정보를 조회한다.
    DBU_init_mwipmatdef(&MWIPMATDEF);
    memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
    MWIPMATDEF.MAT_VER = 1;
    DBU_select_mwipmatdef(1, &MWIPMATDEF);

    //CLASS_OPER_SKIP가 Y시(그릿 분류) SKIP 처리 한다. 
    //그릿의 분류는 작업지시가 없지 진행되기 때문에. 
    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
    {
        //작업지시에 LOSS 수량을 업데이트 한다.
        MWIPORDSTS.ORD_LOSS_QTY = MWIPORDSTS.ORD_LOSS_QTY + MWIPLOTLOS.TOTAL_LOSS_QTY;
        memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
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

        //공정별 작업지시에 loss수량을 업데이트 한다. 
        DBU_init_cwipordopr(&CWIPORDOPR);
        memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        memcpy(CWIPORDOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_cwipordopr(1, &CWIPORDOPR);
        if (DB_error_code == DB_SUCCESS)
        {
            CWIPORDOPR.OPER_LOSS_QTY = CWIPORDOPR.OPER_LOSS_QTY + MWIPLOTLOS.TOTAL_LOSS_QTY;
            memcpy(CWIPORDOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDOPR.UPDATE_TIME));
            TRS.copy(CWIPORDOPR.UPDATE_USER_ID, sizeof(CWIPORDOPR.UPDATE_USER_ID), in_node, IN_USERID);
            DBU_update_cwipordopr(1, &CWIPORDOPR);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPORDOPR UPDATE(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }

    //인터페이스 스킵 여부가 Y인 경우 ERP에 인터페이스를 보내지 않는다. 
    // ex) 외주입고에서 end 인 경우
    if (TRS.get_char(in_node, "SKIP_IF_YN") != 'Y')
    {
        //해당 lot이 테스트 품인 경우 ERP I/F를 타지 못하게 한다.
        if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
            return MP_TRUE;

        //작업지시 ERP 공정 조회
        DBU_init_cwiperpopr(&CWIPERPOPR);
        memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
        memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
        memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
        DBU_select_cwiperpopr(2, &CWIPERPOPR);

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

        //기타 출고 여부 
        //그릿의 약식검사인 경우 불량을 기타 출고로 처리 한다. 
        if (TRS.get_char(in_node, "ETC_OUT_YN") != 'Y')
        {
            if_in = TRS.add_node(in_node, "if_in");
            TRS.add_char(if_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(if_in, in_node);

            TRS.add_char(if_in, "TRAN_FLAG", 'I');
            TRS.add_string(if_in, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_int(if_in, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
            TRS.add_string(if_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            TRS.add_int(if_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
            TRS.add_string(if_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
            TRS.add_int(if_in, "FROM_OPER_SEQ", CWIPERPOPR.OPER_SEQ);
            TRS.add_string(if_in, "FROM_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
            TRS.add_int(if_in, "FROM_STEP_TYPE", 1);
            TRS.add_string(if_in, "TO_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
            TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S));
            TRS.add_int(if_in, "TO_STEP_TYPE", 5);
            TRS.add_int(if_in, "TO_OPER_SEQ", CWIPERPOPR.OPER_SEQ);
            TRS.add_string(if_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_double(if_in, "QTY", MWIPLOTLOS.TOTAL_LOSS_QTY);
            TRS.add_nstring(if_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_char(if_in, "OVER_FLAG", 'N');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_MOVE_TRX(s_msg_code, if_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }

            TRS.free_node(cmn_out);
        }
        else
        {
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

            DBU_init_cbastxndef(&CBASTXNDEF_ETC);
            TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
            CBASTXNDEF_ETC.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_180);
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

            //형상 분류에서 이미 erp에 재고가 생겼기 때문에 약식검사에서 erp에 기타 출고 올라갈때 flow의 마지막공정 = 창고
            //으로 erp 인터페이스를 올린다.
            DBU_init_mwipflwopr(&MWIPFLWOPR);
            memcpy(MWIPFLWOPR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
            memcpy(MWIPFLWOPR.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWOPR.FLOW));
            DBU_select_mwipflwopr(4, &MWIPFLWOPR);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0655");
                TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(4) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
            memcpy(MWIPOPRDEF_FROM.FACTORY, MWIPFLWOPR.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY));
            memcpy(MWIPOPRDEF_FROM.OPER, MWIPFLWOPR.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
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

            //기타 입출고 이력 테이블 저장
            DBU_init_minvetclot(&MINVETCLOT);
            TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
            memcpy(MINVETCLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
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
            memcpy(MINVETCLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

            if (DB_error_code == DB_NOT_FOUND)
            {
                MINVETCLOT.SEQ = 1;
            }
            else
            {
                MINVETCLOT.SEQ += 1;
            }

            memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
            MINVETCLOT.QTY = MWIPLOTLOS.TOTAL_LOSS_QTY;
            memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
            memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
            memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
            memcpy(MINVETCLOT.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
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
			memcpy(MINVETCLOT.CMF_1, "D", strlen("D"));
			memcpy(MINVETCLOT.CMF_2, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			memcpy(MINVETCLOT.CMF_3, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));


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
            if_in = TRS.add_node(in_node, "if_in");
            TRS.add_char(if_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(if_in, in_node);

            TRS.add_char(if_in, "TRAN_FLAG", 'I');
            TRS.add_int(if_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
            TRS.add_string(if_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
            TRS.add_int(if_in, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
            TRS.add_string(if_in, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
            TRS.add_int(if_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
            TRS.add_string(if_in, "AREA_ID", MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
            TRS.add_int(if_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
            TRS.add_string(if_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_string(if_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
            TRS.add_string(if_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_double(if_in, "QTY", -1 * MWIPLOTLOS.TOTAL_LOSS_QTY);
            TRS.add_string(if_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
            TRS.add_string(if_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //추후 맞는 데이터가 들어옴

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_INV_TXNS(s_msg_code, if_in, cmn_out) == MP_FALSE)
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
            if_in = TRS.add_node(in_node, "if_in");
            TRS.add_char(if_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(if_in, in_node);

            TRS.add_char(if_in, "TRAN_FLAG", 'I');
            TRS.add_double(if_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
            TRS.add_int(if_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
            TRS.add_string(if_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(if_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //추후 맞는 데이터가 들어옴
            TRS.add_double(if_in, "QTY", MWIPLOTLOS.TOTAL_LOSS_QTY);

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_IFS_INV_TXN_LOTS(s_msg_code, if_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
    }

    if (memcmp(MWIPLOTLOS.LOSS_CODE_1, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)) == MP_FALSE)
    {
		//P급 정보 조회
		DBU_init_cwiplotrec(&CWIPLOTREC);
		TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		DBU_select_cwiplotrec(2, &CWIPLOTREC);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (DB_error_code == DB_SUCCESS)
		{
			//WIP-0680 : 해당 Lot은 이미 P급 판정 진행중입니다.
			strcpy(s_msg_code, "WIP-0680");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

        //부외재고 리스트 테이블에 insert해준다. 
        DBU_init_cwiplotrec(&CWIPLOTREC);
        memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
        memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
        CWIPLOTREC.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
        memcpy(CWIPLOTREC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
        memcpy(CWIPLOTREC.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        memcpy(CWIPLOTREC.INV_OPER, MWIPORDSTS.ORD_CMF_3, sizeof(CWIPLOTREC.INV_OPER));
        memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
        memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
        memcpy(CWIPLOTREC.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
        memcpy(CWIPLOTREC.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTREC.WORK_DATE));
        memcpy(CWIPLOTREC.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
        CWIPLOTREC.MAT_VER = MWIPLOTSTSX.MAT_VER;
        memcpy(CWIPLOTREC.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
        CWIPLOTREC.QTY = MWIPLOTLOS.TOTAL_LOSS_QTY;
        memcpy(CWIPLOTREC.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(CWIPLOTREC.CREATE_USER_ID, sizeof(CWIPLOTREC.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
        DBU_insert_cwiplotrec(&CWIPLOTREC);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "CWIPLOTREC INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTREC.TRAN_OPER), CWIPLOTREC.TRAN_OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
	//CTM P급창고로 이동
	if (memcmp(MWIPLOTLOS.LOSS_CODE_1, MP_LOSS_CODE_P_STOCK, strlen(MP_LOSS_CODE_P_STOCK)) == MP_FALSE)
	{
		//P급 정보 조회
		DBU_init_cwiplotrec(&CWIPLOTREC);
		TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		DBU_select_cwiplotrec(2, &CWIPLOTREC);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (DB_error_code == DB_SUCCESS)
		{
			//WIP-0680 : 해당 Lot은 이미 P급 판정 진행중입니다.
			strcpy(s_msg_code, "WIP-0680");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//부외재고 리스트 테이블에 insert해준다. 
		DBU_init_cwiplotrec(&CWIPLOTREC);
		memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
		memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		CWIPLOTREC.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		memcpy(CWIPLOTREC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		memcpy(CWIPLOTREC.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		memcpy(CWIPLOTREC.INV_OPER, MWIPORDSTS.ORD_CMF_3, sizeof(CWIPLOTREC.INV_OPER));
		memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
		memcpy(CWIPLOTREC.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
		memcpy(CWIPLOTREC.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTREC.WORK_DATE));
		memcpy(CWIPLOTREC.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		CWIPLOTREC.MAT_VER = MWIPLOTSTSX.MAT_VER;
		memcpy(CWIPLOTREC.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
		CWIPLOTREC.QTY = MWIPLOTLOS.TOTAL_LOSS_QTY;
		memcpy(CWIPLOTREC.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CWIPLOTREC.CREATE_USER_ID, sizeof(CWIPLOTREC.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
		DBU_insert_cwiplotrec(&CWIPLOTREC);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTREC INSERT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTREC.TRAN_OPER), CWIPLOTREC.TRAN_OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}


    return MP_TRUE;
}