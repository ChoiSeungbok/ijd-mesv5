/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_terminate_lot.c
    Description : Terminate Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Terminate_Lot()
            + Terminate Lot
        - CUS_INV_TERMINATE_LOT()
            + Main sub function of "CUS_INV_Terminate_Lot" function
            + Terminate Lot definition
        - CUS_INV_Terminate_Lot_Validation()
            + Validation Check sub function of "CUS_INV_TERMINATE_LOT" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/04  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_TERMINATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Terminate_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Terminate_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Terminate_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_TERMINATE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Terminate_Lot()
        - Terminate Lot
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Terminate_Lot(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_TERMINATE_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_TERMINATE_LOT", out_node);

    if(i_ret == MP_TRUE)
    {
        DB_commit();
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_TERMINATE_LOT()
- Main sub function of "CUS_INV_Terminate_Lot" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_TERMINATE_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	struct MINVLOTSTS_TAG MINVLOTSTS;

	TRSNode *terminate_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;

	LOG_head("CUS_INV_TERMINATE_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Terminate_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	terminate_in_node = TRS.add_node(in_node, "terminate_in_node");
	CopyDefaultMembers(terminate_in_node, in_node);
    TRS.add_char(terminate_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(terminate_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
		TRS.add_nstring(inv_list, "COMMENT", TRS.get_string(inv_lot_list[i], "COMMENT"));

		//LOT 데이터 조회
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_double(inv_list, "ETC_OUT_QTY", TRS.get_double(inv_lot_list[i], "OUT_QTY"));
	}

	// 기타 출고 처리
	if (TRS.get_procstep(in_node) == '2')
	{
		TRS.add_string(terminate_in_node, "TERMINATE_CODE", MP_CINV_TRAN_CODE_ETC_OUT, strlen(MP_CINV_TRAN_CODE_ETC_OUT));
	}
	else
	{
		TRS.add_nstring(terminate_in_node, "TERMINATE_CODE", TRS.get_string(in_node, "TERMINATE_CODE"));
	}
	
	TRS.add_nstring(terminate_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
    TRS.add_nstring(terminate_in_node, "ETC_OUT_TYPE", TRS.get_string(in_node, "ETC_OUT_TYPE")); // 기타 출고 유형
    TRS.add_nstring(terminate_in_node, "OUT_DATE", TRS.get_string(in_node, "OUT_DATE")); //출고 일자
	TRS.add_char(terminate_in_node, "ERP_FLAG", TRS.get_char(in_node, "ERP_FLAG"));

	if (CUS_INV_Terminate_Lot_Before_Transaction(s_msg_code, 0, terminate_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_TERMINATE_LOT(s_msg_code, terminate_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Terminate_Lot_After_Transaction(s_msg_code, 0, terminate_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_TERMINATE_LOT()
        - Main sub function of "CUS_INV_Terminate_Lot" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_TERMINATE_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MRASTOLDEF_TAG MRASTOLDEF;
    struct CWIPGRTBLD_TAG CWIPGRTBLD;
    struct CWIPINVLDM_TAG CWIPINVLDM;

	TRSNode *tool_in;
	TRSNode *cmn_out;
    char s_sys_time[14];

	int i;

	TRSNode **inv_lot_list;
     
    memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for(i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST") ; i++)
	{
		DBU_init_minvlotsts(&MINVLOTSTS_OLD);
		TRS.copy(MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS_OLD);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0044");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_OLD.FACTORY), MINVLOTSTS_OLD.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS_OLD.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS_OLD.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT LOAD 체크
        /* 자재 LOAD된 상태에서도 기타 출고처리 되도록 주석처리_ 20210406_LWG 
           안상현K요청.
		if (MINVLOTSTS_OLD.LOAD_FLAG == 'Y')
		{
			//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
			strcpy(s_msg_code, "INV-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
        */

        //블랜딩 작업지시 투입지시가 되어 있으면 기타 출고를 할 수 없도록 한다.
        DBU_init_cwipgrtbld(&CWIPGRTBLD);
        memcpy(CWIPGRTBLD.FACTORY, MINVLOTSTS_OLD.FACTORY, sizeof(MINVLOTSTS_OLD.FACTORY));
        memcpy(CWIPGRTBLD.LOT_ID, MINVLOTSTS_OLD.INV_LOT_ID, sizeof(MINVLOTSTS_OLD.INV_LOT_ID));

        if (DBU_select_cwipgrtbld_scalar(2, &CWIPGRTBLD) > 0)
        {
            //WIP-0687 : 블랜딩 작업지시에 투입된 lot은 기타 출고를 할 수 없습니다. lot을 확인하세요.
            strcpy(s_msg_code, "WIP-0687");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS_OLD.INV_LOT_ID), MINVLOTSTS_OLD.INV_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_COMMON;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS_OLD.MAT_ID, sizeof(MINVLOTSTS_OLD.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVLOTSTS_OLD.MAT_VER;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

        if (TRS.get_procstep(in_node) == '1')
        {
			// Terminate Code 체크
			if (COM_isnullspace(TRS.get_string(in_node, "TERMINATE_CODE")) == MP_TRUE)
			{
				strcpy(s_msg_code, "WIP-0001");
				TRS.add_fieldmsg(out_node, "TERMINATE_CODE", MP_NVST);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

            // Terminate Code 체크 (GCM 체크)
            if (COM_check_gcm_data(s_msg_code,
                out_node,
                "INV_TERMINATE_CODE",
                TRS.get_factory(in_node),
                TRS.get_string(in_node, "TERMINATE_CODE"),
                (int)strlen(TRS.get_string(in_node, "TERMINATE_CODE"))) == MP_FALSE)
            {
                return MP_FALSE;
            }
        }

		memcpy(&MINVLOTSTS, &MINVLOTSTS_OLD, sizeof(MINVLOTSTS));

		if (TRS.get_char(in_node, IN_PROCSTEP) == '3')
		{
			// TRAN CODE : PROD_IN
			// 수량 0
			// 해당 자재 삭제
			MINVLOTSTS.QTY = 0;
			MINVLOTSTS.QTY_2 = 0;
			MINVLOTSTS.QTY_3 = 0;
		}
		else
		{
			if (TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY") <= 0)
			{
				// INV-0062 : CMN495 INFO - 출고 수량은 0보다 큰 수량이어야 합니다.
				strcpy(s_msg_code, "INV-0062");
				TRS.add_fieldmsg(out_node, "OUT_QTY", MP_DBL, TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

            if (COM_dbl_round(MINVLOTSTS.QTY, 5, 'U') - COM_dbl_round(TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY"), 5, 'U') < 0)
            {
                //INV-0078 : 기타 출고 수량이 LOT의 수량보다 큽니다. 기타 출고 수량을 확인하세요.
                strcpy(s_msg_code, "INV-0078");
                TRS.add_fieldmsg(out_node, "OUT_QTY", MP_DBL, TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY"));
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_VALIDATION;
                gs_log_type.category = MP_LOG_CATE_COMMON;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

			// TRAN CODE : TERMINATE
			// 수량 0
			// 해당 자재 삭제
			MINVLOTSTS.QTY = MINVLOTSTS.QTY - TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY");
			MINVLOTSTS.QTY_2 = 0;
			MINVLOTSTS.QTY_3 = 0;
		}

		if (MINVLOTSTS.QTY <= 0)
		{
			MINVLOTSTS.DELETE_FLAG = 'Y';
			TRS.copy(MINVLOTSTS.DELETE_CODE, sizeof(MINVLOTSTS.DELETE_CODE), in_node, "TERMINATE_CODE");
			memcpy(MINVLOTSTS.DELETE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.DELETE_USER_ID, sizeof(MINVLOTSTS.DELETE_USER_ID), in_node, IN_USERID);

            //전량 기타 출고인 경우 LOAD 테이블에서 지워준다.
            DBU_init_cwipinvldm(&CWIPINVLDM);
            memcpy(CWIPINVLDM.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
            memcpy(CWIPINVLDM.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
            DBU_delete_cwipinvldm(5, &CWIPINVLDM);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code != DB_NOT_FOUND)
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
		}
		
		// PROCSTEP = 1 -> 일단 폐기
		// PROCSTEP = 2 -> 기타 출고
		// PROCSTEP = 3 -> 물류 포장 LOT 출하
		if (TRS.get_procstep(in_node) == '1')
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_TERMINATE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
		}
		else if (TRS.get_procstep(in_node) == '2')
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_ETC_OUT, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
            
            //기타출고시 전체 CV되는 경우만 COMMENT를 넣어주고, 아닐경우 기존 COMMENT값을 가져간다. 
            if(MINVLOTSTS.DELETE_FLAG == 'Y')
			    TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), inv_lot_list[i], "COMMENT");             
		}
		else if (TRS.get_procstep(in_node) == '3')
		{
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_PROD_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
		}
		
		memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
		
		MINVLOTSTS.LAST_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
		MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD.LAST_HIST_SEQ + 1;
        TRS.copy(MINVLOTSTS.INV_CMF_6, sizeof(MINVLOTSTS.INV_CMF_6), in_node, "ETC_OUT_TYPE");//INV_CMF_6(ETC_OUT_TYPE) 기타 출고 유형
        TRS.copy(MINVLOTSTS.INV_CMF_7, sizeof(MINVLOTSTS.INV_CMF_7), in_node, "OUT_DATE");// INV_CMF_7(OUT_DATE) 출고 일자

		TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		//자재 LOT 이력 생성
		DBU_init_minvlothis(&MINVLOTHIS);

		//자재 LOT UPSERT & 자재 이력 INSERT
		if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
													in_node,
													out_node,
													s_sys_time,
													&MINVLOTSTS_OLD,
													&MINVLOTSTS,
													&MINVLOTHIS) == MP_FALSE)
		{
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//금형 자재라면,
		if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
		{
			//TOOL 정보 조회
			DBU_init_mrastoldef(&MRASTOLDEF);
			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASTOLDEF.TOOL_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

			DBU_select_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//TOOL 폐기 처리
			tool_in = TRS.add_node(in_node, "tool_in");
			TRS.add_char(tool_in, IN_PROCSTEP, 'S');
			CopyDefaultMembers(tool_in, in_node);

			TRS.add_string(tool_in, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			TRS.add_string(tool_in, "TOOL_TYPE", MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
			TRS.add_nstring(tool_in, "TOOL_COMMENT", TRS.get_string(in_node, "COMMENT"));

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
    }

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;

}

/*******************************************************************************
    CUS_INV_Terminate_Lot_Validation()
        - Validation Check sub function of "CUS_INV_TERMINATE_LOT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Terminate_Lot_Validation(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node)
{
    /*
	if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Terminate_Lot_Before_Transaction()
- Main sub function of "CUS_INV_TERMINATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Terminate_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Terminate_Lot_After_Transaction()
- Main sub function of "CUS_INV_TERMINATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Terminate_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	//I/F용 필요 테이블
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct CBASTXNDEF_TAG CBASTXNDEF_ETC;
	struct MINVETCLOT_TAG MINVETCLOT;

	TRSNode **inv_lot_list;
	TRSNode *erpif_in;
	TRSNode *cmn_out;
	int i;

	if (TRS.get_procstep(in_node) == '2')
	{
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

		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			//LOT 데이터 조회
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0590 : 이 창고는 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0590");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
			TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0006 : 이 제품은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0006");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//기타 출고 분할로 인해 SEQ 조회
			DBU_init_minvetclot(&MINVETCLOT);
			TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVETCLOT.LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
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
			memcpy(MINVETCLOT.LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

			if (DB_error_code == DB_NOT_FOUND)
			{
				MINVETCLOT.SEQ = 1;
			}
			else
			{
				MINVETCLOT.SEQ += 1;
			}
			
			memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));
			MINVETCLOT.QTY = TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY");
			memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
			memcpy(MINVETCLOT.AREA_ID, MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
			memcpy(MINVETCLOT.SUB_AREA_ID, MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
			memcpy(MINVETCLOT.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
			memcpy(MINVETCLOT.VENDOR_ID, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			MINVETCLOT.VENDOR_SITE_ID = MINVLOTSTS.VENDOR_SITE_ID;
			memcpy(MINVETCLOT.VENDOR_LOT_ID, MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
			memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_OUT, sizeof(MINVETCLOT.ETC_TYPE));
			memcpy(MINVETCLOT.ETC_DATE, MINVLOTSTS.INV_CMF_7, sizeof(MINVLOTSTS.INV_CMF_7));
			MINVETCLOT.TRAN_SRC_ID = 0;
			memset(MINVETCLOT.TRAN_SRC_NAME, ' ', sizeof(MINVETCLOT.TRAN_SRC_NAME));
			//memcpy(MINVETCLOT.ETC_COMMENT, MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT));
            TRS.copy(MINVETCLOT.ETC_COMMENT, sizeof(MINVETCLOT.ETC_COMMENT), inv_lot_list[i], "COMMENT");

			//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
			//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
			if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
			{
				memcpy(MINVETCLOT.CMF_1, "A", strlen("A"));
				memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
				memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));
			}
			else
			{
				memcpy(MINVETCLOT.CMF_1, "B", strlen("B"));
				memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
				memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));
			}

			TRS.copy(MINVETCLOT.CREATE_USER_ID, sizeof(MINVETCLOT.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVETCLOT.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
			TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

			if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
			{
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_1);
				CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2));
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
				CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MINVLOTSTS.INV_CMF_6, sizeof(MINVLOTSTS.INV_CMF_6));
				CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2));
				DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

				if (DB_error_code == DB_NOT_FOUND)
				{
					//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
					//MST(ERP AREA ID : 103)
					//임시로 하드코딩
					DBU_init_cbastxndef(&CBASTXNDEF_ETC);
					TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
					CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MINVLOTSTS.INV_CMF_6, sizeof(MINVLOTSTS.INV_CMF_6));
					CBASTXNDEF_ETC.ERP_AREA_ID = 103;
					DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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
				}

				MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
				memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", -TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY"));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정

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
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정
				TRS.add_double(erpif_in, "QTY", TRS.get_double(inv_lot_list[i], "ETC_OUT_QTY"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

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
		}
	}

	return MP_TRUE;
}