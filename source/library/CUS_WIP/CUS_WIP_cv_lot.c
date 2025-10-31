/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_cv_lot.c
Description : Tran cv Lot function

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

int CUS_WIP_Cv_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Cv_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Cv_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Cv_Lot()
- Tran adapt Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cv_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_CV_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Cv_Lot", out_node);
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
CUS_WIP_CV_LOT()
- Main sub function of "CUS_WIP_Cv_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTS_TAG MWIPLOTSTS;
    
    TRSNode *cv_in_node;
    TRSNode *cv_list_1;
    TRSNode *cv_list_2;
    TRSNode *cv_list_3;

    struct work_date_tag work_date;
    char s_factory[10];

    LOG_head("CUS_WIP_Cv_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Cv_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

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

    //실적수량과 이전 실적이 같으면 CV를 하지 않는다.
    if (COM_dbl_round(TRS.get_double(in_node, "QTY_1"), 5, 'U') == COM_dbl_round(MWIPLOTSTS.QTY_1, 5, 'U'))
    {
        return MP_TRUE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    cv_in_node = TRS.add_node(in_node, "cv_in_node");
    TRS.add_char(cv_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(cv_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(cv_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(cv_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    TRS.add_nstring(cv_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(cv_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_nstring(cv_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(cv_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
    TRS.add_nstring(cv_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
   // TRS.add_nstring(cv_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));

	//20211123 수정
    //TRS.add_nstring(cv_in_node, "CV_COMMENT", TRS.get_string(in_node, "CV_COMMENT"));
//	TRS.add_nstring(cv_in_node, "COMMENT", TRS.get_string(in_node, "CV_COMMENT"));
	
	TRS.add_string(cv_in_node, "CRR_ID", MWIPLOTSTS.CRR_ID, sizeof(MWIPLOTSTS.CRR_ID));

    //CV 수량 들어가는 리스트.
    cv_list_1 = TRS.add_node(cv_in_node, "UNIT1");
    
    if (COM_isnullspace(TRS.get_string(in_node, "CODE")) == MP_TRUE)
        TRS.add_nstring(cv_list_1, "CODE", "CV001");
    else
        TRS.add_nstring(cv_list_1, "CODE", TRS.get_string(in_node, "CODE"));

    TRS.set_double(cv_list_1, "QTY", TRS.get_double(in_node, "QTY_1") - MWIPLOTSTS.QTY_1);

    cv_list_2 = TRS.add_node(cv_in_node, "UNIT2");
    TRS.add_nstring(cv_list_2, "CODE", "CV002");
    TRS.set_double(cv_list_2, "QTY", TRS.get_double(in_node, "QTY_2") - MWIPLOTSTS.QTY_2);

    cv_list_3 = TRS.add_node(cv_in_node, "UNIT3");
    TRS.add_nstring(cv_list_3, "CODE", "CV003");
    TRS.set_double(cv_list_3, "QTY", TRS.get_double(in_node, "QTY_3") - MWIPLOTSTS.QTY_3);

    TRS.add_string(cv_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(cv_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(cv_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_char(cv_in_node, "NO_AUTOMATIC_TERMINATE_LOT", ' ');
    TRS.add_char(cv_in_node, "CLASS_OPER_SKIP", TRS.get_char(in_node, "CLASS_OPER_SKIP"));  //분류정보시 작지 실적UPDATE SKIP여부
    TRS.add_char(cv_in_node, "IS_IN_OPER", TRS.get_char(in_node, "IS_IN_OPER"));

    if (CUS_WIP_Cv_Lot_Before_Transaction(s_msg_code, 0, cv_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_CV_LOT(s_msg_code, cv_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Cv_Lot_After_Transaction(s_msg_code, 0, cv_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Cv_Lot_Validation()
- Validation Check sub function of "CUS_WIP_CV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cv_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_WIP_Cv_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_CV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cv_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Cv_Lot_After_Transaction()
- Main sub function of "CUS_WIP_CV_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cv_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
    struct CWIPORDOPR_TAG   CWIPORDOPR;
	struct MWIPORDSTS_TAG   MWIPORDSTS;
    struct CWIPINVLDM_TAG   CWIPINVLDM;
    struct MWIPLOTCVH_TAG   MWIPLOTCVH;

    //load된 LOT인경우 작업지시 cv 정보에 넣어주지 않는다.
    DBU_init_cwipinvldm(&CWIPINVLDM);
    TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), in_node, "LOT_ID");
    if(DBU_select_cwipinvldm_scalar(2, &CWIPINVLDM) > 0)
    {
        return MP_TRUE;
    }

    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    //lot조회
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

    DBC_init_mwiplotcvh(&MWIPLOTCVH);
    TRS.copy(MWIPLOTCVH.FACTORY, sizeof(MWIPLOTCVH.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPLOTCVH.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    MWIPLOTCVH.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
    MWIPLOTCVH.QTY_FLAG = '1';
    DBC_select_mwiplotcvh(1, &MWIPLOTCVH);

    //CLASS_OPER_SKIP가 Y시(그릿 분류) SKIP 처리 한다. 
    //그릿의 분류는 작업지시가 없지 진행되기 때문에. 
    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
    {

		/*
        //공정별 시작 수량 update
        DBU_init_cwipordopr(&CWIPORDOPR);
        TRS.copy(CWIPORDOPR.FACTORY, sizeof(CWIPORDOPR.FACTORY), in_node, IN_FACTORY);
        memcpy(CWIPORDOPR.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
        TRS.copy(CWIPORDOPR.OPER, sizeof(CWIPORDOPR.OPER), in_node, "OPER");
        DBU_select_cwipordopr(1, &CWIPORDOPR);
        if (DB_error_code == DB_SUCCESS)
        {
            CWIPORDOPR.OPER_CV_QTY = CWIPORDOPR.OPER_CV_QTY + MWIPLOTCVH.TOTAL_CV_QTY;

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
		*/





		// 해당로직은 첫공정만 탐.
		//공정별 시작 수량 update 
		DBU_init_cwipordopr(&CWIPORDOPR);
		TRS.copy(CWIPORDOPR.FACTORY, sizeof(CWIPORDOPR.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPORDOPR.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		TRS.copy(CWIPORDOPR.OPER, sizeof(CWIPORDOPR.OPER), in_node, "OPER");
		DBU_select_cwipordopr(1, &CWIPORDOPR);
		if (DB_error_code == DB_SUCCESS)
		{
	
			CWIPORDOPR.OPER_IN_QTY = CWIPORDOPR.OPER_IN_QTY + MWIPLOTCVH.TOTAL_CV_QTY;

				//OPER_CV_QTY 딱히 사용하는 부분이 없고 맞지않을것으로 보임 일단 나둔느걸로
		  	CWIPORDOPR.OPER_CV_QTY = CWIPORDOPR.OPER_CV_QTY + MWIPLOTCVH.TOTAL_CV_QTY;



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


		// 해당로직은 첫공정만 탐.
		//오더 시작 수량 update
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code == DB_SUCCESS)
		{

			MWIPORDSTS.ORD_IN_QTY = MWIPORDSTS.ORD_IN_QTY + MWIPLOTCVH.TOTAL_CV_QTY;


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
		}

    }

    if(TRS.get_char(in_node, "IS_IN_OPER") == 'Y')
    {
        TRS.set_nstring(in_node, "TRAN_CODE", "CV");
        if(Update_Lot_Summary(s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        {
            if (Update_Res_Wip_Summary(s_msg_code, in_node, out_node) == MP_FALSE)
                return MP_FALSE;
        }
    }

    return MP_TRUE;
}