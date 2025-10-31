/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_create_lot.c
Description : Tran Create Lot function

MES Version : 5.0

Function List
-

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
#include "ACTCore_common.h"

int CUS_WIP_Create_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Create_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Create_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Create_Lot()
- Tran Create Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_CREATE_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Create_Lot", out_node);
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
CUS_WIP_CREATE_LOT()
- Main sub function of "CUS_WIP_Create_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CREATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *create_in_node;
    struct work_date_tag work_date;

    char s_factory[10];
	//char s_group_id[25];

    LOG_head("CUS_WIP_Create_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Create_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    //LOT 생성
    create_in_node = TRS.add_node(in_node, "create_in_node");

    TRS.add_char(create_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(create_in_node, in_node);

    //create 시간은 클라이언트에서 서버 호출 시간으로 한다. 
    //gs_sys_time를 사용하는 이유는 create -> start가 같은 시간에 들어가도록 하기 위해.	
    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(create_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(create_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(create_in_node, "LOT_DESC", TRS.get_string(in_node, "LOT_DESC"));
    TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_int(create_in_node, "MAT_VER", 1);
    TRS.add_char(create_in_node, "LOT_TYPE", TRS.get_char(in_node, "LOT_TYPE"));
    TRS.add_nstring(create_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
    TRS.add_int(create_in_node, "FLOW_SEQ_NUM", TRS.get_int(in_node, "FLOW_SEQ_NUM"));
    TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY_1"));
    TRS.add_double(create_in_node, "QTY_2", TRS.get_double(in_node, "QTY_2"));
    TRS.add_double(create_in_node, "QTY_3", TRS.get_double(in_node, "QTY_3"));
    TRS.add_char(create_in_node, "LOT_PRIORITY", TRS.get_char(in_node, "LOT_PRIORITY"));
    TRS.add_nstring(create_in_node, "CREATE_CODE", TRS.get_string(in_node, "CREATE_CODE"));
    TRS.add_nstring(create_in_node, "OWNER_CODE", TRS.get_string(in_node, "OWNER_CODE"));
    TRS.add_string(create_in_node, "DUE_TIME", gs_sys_time, sizeof(gs_sys_time));

    //추가 정보성 데이터
    TRS.add_nstring(create_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
    TRS.add_nstring(create_in_node, "LOT_CMF_1", TRS.get_string(in_node, "LOT_CMF_1"));
    TRS.add_nstring(create_in_node, "LOT_CMF_2", TRS.get_string(in_node, "LOT_CMF_2"));
    TRS.add_nstring(create_in_node, "LOT_CMF_3", TRS.get_string(in_node, "LOT_CMF_3"));
    TRS.add_nstring(create_in_node, "LOT_CMF_4", TRS.get_string(in_node, "LOT_CMF_4"));
    TRS.add_nstring(create_in_node, "LOT_CMF_5", TRS.get_string(in_node, "LOT_CMF_5"));
    TRS.add_nstring(create_in_node, "LOT_CMF_6", TRS.get_string(in_node, "LOT_CMF_6"));
    TRS.add_nstring(create_in_node, "LOT_CMF_7", TRS.get_string(in_node, "LOT_CMF_7"));
    TRS.add_nstring(create_in_node, "LOT_CMF_8", TRS.get_string(in_node, "LOT_CMF_8"));
    TRS.add_nstring(create_in_node, "LOT_CMF_9", TRS.get_string(in_node, "LOT_CMF_9"));
    TRS.add_nstring(create_in_node, "LOT_CMF_10", TRS.get_string(in_node, "LOT_CMF_10"));
    TRS.add_nstring(create_in_node, "LOT_CMF_11", TRS.get_string(in_node, "LOT_CMF_11"));
    TRS.add_nstring(create_in_node, "LOT_CMF_12", TRS.get_string(in_node, "LOT_CMF_12"));
    TRS.add_nstring(create_in_node, "LOT_CMF_13", TRS.get_string(in_node, "LOT_CMF_13"));
    TRS.add_nstring(create_in_node, "LOT_CMF_14", TRS.get_string(in_node, "LOT_CMF_14"));
    TRS.add_nstring(create_in_node, "LOT_CMF_15", TRS.get_string(in_node, "LOT_CMF_15"));
    TRS.add_nstring(create_in_node, "LOT_CMF_16", TRS.get_string(in_node, "LOT_CMF_16"));
    TRS.add_nstring(create_in_node, "LOT_CMF_17", TRS.get_string(in_node, "LOT_CMF_17"));
    TRS.add_nstring(create_in_node, "LOT_CMF_18", TRS.get_string(in_node, "LOT_CMF_18"));
    TRS.add_nstring(create_in_node, "LOT_CMF_19", TRS.get_string(in_node, "LOT_CMF_19"));
    TRS.add_nstring(create_in_node, "LOT_CMF_20", TRS.get_string(in_node, "LOT_CMF_20"));

    TRS.add_string(create_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(create_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(create_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(create_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(create_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_nstring(create_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
    TRS.add_nstring(create_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
    //TRS.add_nstring(create_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
    //최조 LOT ID를 저장한다. => 
    //SPLIT 하는 경우 최초 LOT ID 대비 채번을 해야 하므로 해당 필드 RESV_FIELD_3 에 최초 생성 LOT ID를 넣어둔다.

	if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_3")) == MP_TRUE)
	{
		TRS.add_nstring(create_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "LOT_ID"));
	}
	else
	{
		TRS.add_nstring(create_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
	}
             
    TRS.add_nstring(create_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
    TRS.add_nstring(create_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));
    TRS.add_char(create_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
    TRS.add_char(create_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
    TRS.add_char(create_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
    TRS.add_char(create_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
    TRS.add_char(create_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
    TRS.add_char(create_in_node, "RWK_FLAG", TRS.get_char(in_node, "RWK_FLAG"));
    TRS.add_nstring(create_in_node, "RWK_CODE", TRS.get_string(in_node, "RWK_CODE"));
    TRS.add_char(create_in_node, "CLASS_OPER_SKIP", TRS.get_char(in_node, "CLASS_OPER_SKIP"));  //분류정보시 작지 실적UPDATE SKIP여부

    if (CUS_WIP_Create_Lot_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Create_Lot_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Create_Lot_Validation()
- Validation Check sub function of "CUS_WIP_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Create_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct CWIPORDOPR_TAG CWIPORDOPR;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;    
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_OPER;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;

    double dOverOrderQty = 0;
    double dOrderQty = 0;
    double dOverPer = 0;
    int iStep = 0;

    /*gcm의 SYSTEM_OPTION 에 셋업된 정보를 가져온다.
        KEY_1  : CUSTOM SYSTEM OPTION 코드
        DATA_1 : CUSTOM SYSTEM OPTION 명칭
        DATA_2 : OPTION 값 
        DATA_3 : OPTION 사용여부
    */

    //CUSTOM SYSTEM 옵션 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT);
    TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_SYSTEM, strlen(MP_GCM_SYSTEM));
    memcpy(MGCMTBLDAT.KEY_1, MP_SYS_ORDER_OVER_QTY, strlen(MP_SYS_ORDER_OVER_QTY));
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

    //작업지시 생성수량의 over생상 범위 (%)
    dOverPer = atof(MGCMTBLDAT.DATA_2);

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

    //CLASS_OPER_SKIP가 Y시(그릿 분류) SKIP 처리 한다. 
    //그릿의 분류는 작업지시가 없지 진행되기 때문에. 
    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
    {
        //공정별 벨리데이션 추가. 
        //system 옵션외에 공정별로 작업지시 대시 생산 수량 벨리데이션 요청으로 인한 추가. 
        //공정별로 벨리데이션에는 작업지시 대시 생산 수량이 over될 수 없다.
        DBU_init_mgcmtbldat(&MGCMTBLDAT_OPER);
        TRS.copy(MGCMTBLDAT_OPER.FACTORY, sizeof(MGCMTBLDAT_OPER.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT_OPER.TABLE_NAME, "C_OPER_VALIDATION", strlen("C_OPER_VALIDATION"));
        memcpy(MGCMTBLDAT_OPER.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_OPER);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                strcpy(s_msg_code, "GCM-0008");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPER SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_OPER.FACTORY), MGCMTBLDAT_OPER.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_OPER.TABLE_NAME), MGCMTBLDAT_OPER.TABLE_NAME);
                TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_OPER.KEY_1), MGCMTBLDAT_OPER.KEY_1);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        //작업지시 조회
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            //작업지시가 대기 상태면 작업지시 시작처리 해준다.
            if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
            {
                MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
            }

            dOverOrderQty = MWIPORDSTS.ORD_QTY * (1 + (dOverPer / 100));
            dOrderQty = MWIPORDSTS.ORD_IN_QTY + TRS.get_double(in_node, "QTY_1");

            //작업지시 수량 체크 확인 여부가 'Y'인경우 생성수량 체크를 한다.
            if (MGCMTBLDAT.DATA_3[0] == 'Y')
            {
                if (dOrderQty > dOverOrderQty)
                {
                    //WIP-0619 : 작업지시에 대한 Lot 생성 수량이 초과 되었습니다. Lot 생성수량과 작업지시 수량을 확인하세요.
                    strcpy(s_msg_code, "WIP-0619");
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            //공정별로 벨리데이션에는 작업지시 대시 생산 수량이 over될 수 없다._20210405_lwg 
            //손병주 주임 요청으로 인한 추가 로직
            //합성공정에서는 작업지시 수량보다 over생산이 있을 수 없다.
            if (MGCMTBLDAT_OPER.DATA_1[0] == 'Y')
            {
                if (COM_dbl_round(MWIPORDSTS.ORD_QTY, 5, 'U') < COM_dbl_round(MWIPORDSTS.ORD_IN_QTY + TRS.get_double(in_node, "QTY_1"), 5, 'U'))
                {
                    //WIP-0619 : 작업지시에 대한 Lot 생성 수량이 초과 되었습니다. Lot 생성수량과 작업지시 수량을 확인하세요.
                    strcpy(s_msg_code, "WIP-0619");
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            //lot 생성시 작업지시에서 create 생성 수량 필드 값을 올려준다.
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

            //CWIPORDOPR에 공정별 ORDER 정보가 없으면 FLOW에 해당하는 공정으로 해서 INSERT해준다. 
            DBU_init_cwipordopr(&CWIPORDOPR);
            memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
            memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            if ((int)DBU_select_cwipordopr_scalar(2, &CWIPORDOPR) == 0)
            {
                iStep = 2;

                DBU_init_mwipflwopr(&MWIPFLWOPR);
                memcpy(MWIPFLWOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
                memcpy(MWIPFLWOPR.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
                DBU_open_mwipflwopr(iStep, &MWIPFLWOPR);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                    strcpy(s_msg_code, "ORD-0008");
                    TRS.add_fieldmsg(out_node, "MWIPFLWOPR OPEN", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
                while (1)
                {
                    DBU_fetch_mwipflwopr(iStep, &MWIPFLWOPR);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        DBU_close_mwipflwopr(iStep);
                        break;
                    }
                    else if (DB_error_code != DB_SUCCESS)
                    {
                        //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                        strcpy(s_msg_code, "ORD-0008");
                        TRS.add_fieldmsg(out_node, "MWIPFLWOPR FETCH", MP_NVST);
                        TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        DBU_close_mwipflwopr(iStep);
                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //공정 조회
                    DBU_init_mwipoprdef(&MWIPOPRDEF);
                    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
                    memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                    DBU_init_cwipordopr(&CWIPORDOPR);
                    memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
                    memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    memcpy(CWIPORDOPR.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                    memcpy(CWIPORDOPR.FLOW, MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
                    CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
                    memcpy(CWIPORDOPR.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    memcpy(CWIPORDOPR.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                    memcpy(CWIPORDOPR.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
                    DBU_insert_cwipordopr(&CWIPORDOPR);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "CWIPORDOPR INSERT ", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
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
CUS_WIP_Create_Lot_After_Transaction()
- Main sub function of "CUS_WIP_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
	struct CWIPLOTTRC_TAG CWIPLOTTRC;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    DBU_init_mwiplothisx(&MWIPLOTHIS);
    memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID));
    MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
    DBU_select_mwiplothisx(1, &MWIPLOTHIS);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTHIS SELECT", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTS.RESV_FIELD_1, sizeof(MWIPLOTSTS.RESV_FIELD_1), in_node, "RESV_FIELD_1");
        TRS.copy(MWIPLOTHIS.RESV_FIELD_1, sizeof(MWIPLOTHIS.RESV_FIELD_1), in_node, "RESV_FIELD_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTS.RESV_FIELD_2, sizeof(MWIPLOTSTS.RESV_FIELD_2), in_node, "RESV_FIELD_2");
        TRS.copy(MWIPLOTHIS.RESV_FIELD_2, sizeof(MWIPLOTHIS.RESV_FIELD_2), in_node, "RESV_FIELD_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTS.RESV_FIELD_3, sizeof(MWIPLOTSTS.RESV_FIELD_3), in_node, "RESV_FIELD_3");
        TRS.copy(MWIPLOTHIS.RESV_FIELD_3, sizeof(MWIPLOTHIS.RESV_FIELD_3), in_node, "RESV_FIELD_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTS.RESV_FIELD_4, sizeof(MWIPLOTSTS.RESV_FIELD_4), in_node, "RESV_FIELD_4");
        TRS.copy(MWIPLOTHIS.RESV_FIELD_4, sizeof(MWIPLOTHIS.RESV_FIELD_4), in_node, "RESV_FIELD_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTS.RESV_FIELD_5, sizeof(MWIPLOTSTS.RESV_FIELD_5), in_node, "RESV_FIELD_5");
        TRS.copy(MWIPLOTHIS.RESV_FIELD_5, sizeof(MWIPLOTHIS.RESV_FIELD_5), in_node, "RESV_FIELD_5");
    }

    DBU_update_mwiplotstsx(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        strcpy(s_msg_code, "ADM-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTS UPDATE", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    DBU_update_mwiplothisx(1, &MWIPLOTHIS);
    if (DB_error_code != DB_SUCCESS)
    {
        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        strcpy(s_msg_code, "ADM-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTHIS UPDATE", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

	// 공정 조회
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


    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
    {
        //LOT 추적 테이블에 저장
        DBU_init_cwiplottrc(&CWIPLOTTRC);
        TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
        memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
        memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
        memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
        memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
        CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
        memcpy(CWIPLOTTRC.FROM_LOT_ID, " ", sizeof(" "));
        CWIPLOTTRC.FROM_LOT_HIST_SEQ = 0;
        memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTS.LAST_TRAN_CODE, sizeof(MWIPLOTSTS.LAST_TRAN_CODE));
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

    return MP_TRUE;
}