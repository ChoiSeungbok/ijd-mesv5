/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_production_lot_conversion.c
    Description : Production Lot Conversion

    MES Version : 4.0.0

    Function List
        - CUS_INV_Production_Lot_Conversion()
            + Production Lot Conversion
        - CUS_INV_PRODUCTION_LOT_CONVERSION()
            + Main sub function of "CUS_INV_Production_Lot_Conversion" function
            + Production Lot Conversion definition
        - CUS_INV_Production_Lot_Conversion_Validation()
            + Validation Check sub function of "CUS_INV_PRODUCTION_LOT_CONVERSION" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2021/01/06  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_PRODUCTION_LOT_CONVERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Production_Lot_Conversion_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Production_Lot_Conversion_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Production_Lot_Conversion_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_PRODUCTION_LOT_CONVERSION_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Production_Lot_Conversion()
        - Production Lot Conversion
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Production_Lot_Conversion(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_PRODUCTION_LOT_CONVERSION_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_PRODUCTION_LOT_CONVERSION", out_node);

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
CUS_INV_PRODUCTION_LOT_CONVERSION()
- Main sub function of "CUS_INV_Production_Lot_Conversion" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_PRODUCTION_LOT_CONVERSION_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *conversion_in_node;
	TRSNode **conversion_lot_list;
	TRSNode *lot_list;
	int i;

	LOG_head("CUS_INV_PRODUCTION_LOT_CONVERSION");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Production_Lot_Conversion_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	conversion_in_node = TRS.add_node(in_node, "conversion_in_node");
	CopyDefaultMembers(conversion_in_node, in_node);

	TRS.add_char(conversion_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	conversion_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(conversion_in_node, "LOT_LIST");
		TRS.add_nstring(lot_list, "LOT_ID", TRS.get_string(conversion_lot_list[i], "LOT_ID"));
		TRS.add_nstring(lot_list, "NEW_LOT_ID", TRS.get_string(conversion_lot_list[i], "NEW_LOT_ID"));
	}

	if (CUS_INV_Production_Lot_Conversion_Before_Transaction(s_msg_code, 0, conversion_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_PRODUCTION_LOT_CONVERSION(s_msg_code, conversion_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Production_Lot_Conversion_After_Transaction(s_msg_code, 0, conversion_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_PRODUCTION_LOT_CONVERSION()
        - Main sub function of "CUS_INV_Production_Lot_Conversion" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_PRODUCTION_LOT_CONVERSION(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{

    struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct MWIPMATFLW_TAG MWIPMATFLW;

	int i = 0;

	TRSNode **conversion_lot_list;
	TRSNode *terminate_in;
	TRSNode *create_in;
	TRSNode *store_in;
    TRSNode *cmn_out;
	TRSNode *inv_list;
	 
	conversion_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), conversion_lot_list[i], "LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 삭제 여부 체크
		if (MINVLOTSTS.DELETE_FLAG == 'Y')
		{
			strcpy(s_msg_code, "INV-0013");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 자재 LOT 잠금 여부 체크
		if (MINVLOTSTS.HOLD_FLAG == 'Y')
		{
			strcpy(s_msg_code, "INV-0014");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//Load 플래그 필요없음 삭제 20230421 송용원
		/*
		// 자재 LOT LOAD 체크
		if (MINVLOTSTS.LOAD_FLAG == 'Y')
		{
			//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
			strcpy(s_msg_code, "INV-0059");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/
		if (COM_isnullspace(MINVLOTSTS.INV_CMF_4) == MP_FALSE)
		{
			//INV-0041 : 해당 자재는 Kitting된 자재입니다.
			strcpy(s_msg_code, "INV-0041");
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MWIPLOTSTS - LOT ID 정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), conversion_lot_list[i], "NEW_LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (DB_error_code != DB_NOT_FOUND)
		{
			//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0045");
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		// 제품에 해당하는 FLOW 조회 (1번째 FLOW)
		DBU_init_mwipmatflw(&MWIPMATFLW);
		TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATFLW.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
		DBU_select_mwipmatflw(2, &MWIPMATFLW);

		if (DB_error_code != DB_SUCCESS)
		{


			// 없으면 전체창고 플로우(첨부터 이거해도 되는데..혹시 포장쪽에 뭐걸리는거 있을지 몰라서일단)
			DBU_init_mwipmatflw(&MWIPMATFLW);
			TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATFLW.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			DBU_select_mwipmatflw(3, &MWIPMATFLW);

			if (DB_error_code != DB_SUCCESS)
			{

				//플로우가 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0655");
				TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

		}

		// 제품에 해당하는 제품 창고 조회(첫 공정)
		DBU_init_mwipflwopr(&MWIPFLWOPR);
		TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
		DBU_select_mwipflwopr(8, &MWIPFLWOPR);

		if (DB_error_code != DB_SUCCESS)
		{
			// 없으면 전체창고 플로우(첨부터 이거해도 되는데..혹시 포장쪽에 뭐걸리는거 있을지 몰라서일단)
			DBU_init_mwipflwopr(&MWIPFLWOPR);
			TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
			memcpy(MWIPFLWOPR.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
			DBU_select_mwipflwopr(9, &MWIPFLWOPR);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}
		}

		//// INV LOT -> WIP LOT
		create_in = TRS.add_node(in_node, "create_in");
		CopyDefaultMembers(create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(create_in, "PROCSTEP", '1');
		TRS.add_nstring(create_in, "LOT_ID", TRS.get_string(conversion_lot_list[i], "NEW_LOT_ID"));
		TRS.add_string(create_in, "LOT_DESC", MP_CINV_TRAN_CODE_PROD_IN, strlen(MP_CINV_TRAN_CODE_PROD_IN));
		TRS.add_string(create_in, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
		TRS.add_int(create_in, "MAT_VER", MINVLOTSTS.MAT_VER);
		TRS.add_char(create_in, "LOT_TYPE", MP_LOT_TYPE_PROD);
		TRS.add_string(create_in, "FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
		TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
		TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
		TRS.add_double(create_in, "QTY_1", MINVLOTSTS.QTY);
		TRS.add_char(create_in, "LOT_PRIORITY", '5');
		TRS.add_string(create_in, "OWNER_CODE", "PROD", strlen("PROD"));
		TRS.add_string(create_in, "CREATE_CODE", "PROD", strlen("PROD"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		// MWIPLOTSTS - LOT ID 정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), conversion_lot_list[i], "NEW_LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//Store안쓸거임
		/*

		// 창고로 STORE
		store_in = TRS.add_node(in_node, "store_in");
		TRS.add_char(store_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(store_in, in_node);

		TRS.add_string(store_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		TRS.add_string(store_in, "TO_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);


		*/

		// 자재 LOT TERMINATE
		terminate_in = TRS.add_node(in_node, "terminate_in");
		CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT
		TRS.add_char(terminate_in, "PROCSTEP", '3');

		inv_list = TRS.add_node(terminate_in, "INV_LOT_LIST");
		TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_TERMINATE_LOT_MAIN(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_Production_Lot_Conversion_Validation()
        - Validation Check sub function of "CUS_INV_PRODUCTION_LOT_CONVERSION" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Production_Lot_Conversion_Validation(char *s_msg_code,
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
CUS_INV_Production_Lot_Conversion_Before_Transaction()
- Main sub function of "CUS_INV_PRODUCTION_LOT_CONVERSION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Production_Lot_Conversion_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Production_Lot_Conversion_After_Transaction()
- Main sub function of "CUS_INV_PRODUCTION_LOT_CONVERSION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Production_Lot_Conversion_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}