/*******************************************************************************

    System      : MESplus
    Module      : CUS_SHP
    File Name   : CUS_SHP_return_lot.c
    Description : Return Lot

    MES Version : 5.2.0

    Function List
        - CUS_SHP_Return_Lot()
            + Return Lot
        - CUS_SHP_RETURN_LOT()
            + Main Sub function of "CUS_SHP_Return_Lot"
            + (called by "CUS_SHP_Return_Lot")
        - CUS_SHP_Return_Lot_Validation()
            + Validation Check sub function of "CUS_SHP_RETURN_LOT" function
            + (called by "CUS_SHP_RETURN_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/09/01  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_RETURN_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Return_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_RETURN_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Return_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Return_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_SHP_Return_Lot()
        - Return Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_SHP_Return_Lot_In_Tag *CUS_SHP_Return_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Return_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_RETURN_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_RETURN_LOT", out_node);

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
CUS_SHP_RETURN_LOT_MAIN()
- Main sub function of "CUS_SHP_RETURN_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_RETURN_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_RETURN_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *return_in_node;
	TRSNode **return_lot_list;
	TRSNode *lot_list;
	int i;

	LOG_head("CUS_SHP_RETURN_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_SHP_Return_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	return_in_node = TRS.add_node(in_node, "return_in_node");
	CopyDefaultMembers(return_in_node, in_node);

	TRS.add_char(return_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(return_in_node, "RET_ORDER_ID", TRS.get_string(in_node, "RET_ORDER_ID"));
	TRS.add_int(return_in_node, "LINE_NO", TRS.get_int(in_node, "LINE_NO"));
	TRS.add_nstring(return_in_node, "RETURN_DATE", TRS.get_string(in_node, "RETURN_DATE"));
	TRS.add_double(return_in_node, "TOTAL_QTY", TRS.get_double(in_node, "TOTAL_QTY"));
	
	return_lot_list = TRS.get_list(in_node, "RET_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "RET_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(return_in_node, "RET_LOT_LIST");
		TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(return_lot_list[i], "ORG_LOT_ID"));
		TRS.add_nstring(lot_list, "PACK_LOT_ID", TRS.get_string(return_lot_list[i], "PACK_LOT_ID"));
		TRS.add_double(lot_list, "QTY", TRS.get_double(return_lot_list[i], "QTY"));
	}
	
	if (CUS_SHP_Return_Lot_Before_Transaction(s_msg_code, 0, return_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_RETURN_LOT(s_msg_code, return_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Return_Lot_After_Transaction(s_msg_code, 0, return_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_SHP_RETURN_LOT()
        - Main sub function of "CUS_SHP_Return_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_RETURN_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_RETURN_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct CRETORDSTS_TAG CRETORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct CRETLOTSTS_TAG CRETLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct MWIPFLWOPR_TAG MWIPFLWOPR_TEMP;
	struct MWIPMATFLW_TAG MWIPMATFLW;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;
	struct IF_PO_RMA_HEADERS_TAG IF_PO_RMA_HEADERS;
	struct IF_PO_RMA_TXNS_TAG IF_PO_RMA_TXNS;
	struct MINVLOTSTS_TAG MINVLOTSTS;

	TRSNode *create_in;
	TRSNode *regenerate_in;
	TRSNode *gen_in_node;
	TRSNode *split_in;
	TRSNode *move_in;
	TRSNode *cmn_out;
	TRSNode *erpif_in;

    char s_sys_time[14];
	char s_new_lot_id[26];
	char s_org_inv_lot_id[26];

	int i;
	int i_split_return_flag = 0;
	int send_flag = 0;

	TRSNode *lot_list;
	TRSNode **return_lot_list;
		  
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_org_inv_lot_id, 0x00, sizeof(s_org_inv_lot_id));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// 반품 지시 정보 조회
	DBU_init_cretordsts(&CRETORDSTS);
	TRS.copy(CRETORDSTS.FACTORY, sizeof(CRETORDSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CRETORDSTS.CMF_1, sizeof(CRETORDSTS.RET_ORDER_ID), in_node, "RET_ORDER_ID");
	CRETORDSTS.LINE_NO = TRS.get_int(in_node, "LINE_NO");
	DBU_select_cretordsts(2, &CRETORDSTS);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CRETORDSTS SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETORDSTS.FACTORY), CRETORDSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.RET_ORDER_ID), CRETORDSTS.RET_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// 반품 지시 상태 체크
	// 반품 -> WAIT 상태에서 가능
	if (memcmp(CRETORDSTS.RET_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
	{
		//WIP-0578 : 해당 반품 지시는 이미 마감되었습니다.
		strcpy(s_msg_code, "WIP-0578");
		TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.RET_ORDER_ID), CRETORDSTS.RET_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//반품지시 수량과 반품 Lot의 토탈 수량이 일치해야됨.
	if (CRETORDSTS.QTY != TRS.get_double(in_node, "TOTAL_QTY"))
	{
		//WIP-0670 : 반품 Lot의 수량이 반품 지시 수량과 일치하지 않습니다.
		strcpy(s_msg_code, "WIP-0670");
		TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.RET_ORDER_ID), CRETORDSTS.RET_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//AREA 정보 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
	memcpy(MGCMTBLDAT.KEY_1, CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		TRS.add_dberrmsg(out_node, DB_error_msg);
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// MWIPMATDEF - 제품 정보 조회
	DBU_init_mwipmatdef(&MWIPMATDEF);
	TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPMATDEF.MAT_ID, CRETORDSTS.MAT_ID, sizeof(CRETORDSTS.MAT_ID));
	MWIPMATDEF.MAT_VER = CRETORDSTS.MAT_VER;
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

	// MWIPOPRDEF - 반품 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF);
	TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MWIPOPRDEF.AREA_ID, CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID));
	memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_RET, sizeof(MWIPOPRDEF.OPER_GRP_1));
	MWIPOPRDEF.INV_FLAG = 'Y';
	DBU_select_mwipoprdef(7, &MWIPOPRDEF);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	return_lot_list = TRS.get_list(in_node, "RET_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "RET_LOT_LIST"); i++)
	{
		memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));

		// CPAKLOTSTS - 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), return_lot_list[i], "ORG_LOT_ID");
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), return_lot_list[i], "PACK_LOT_ID");
		DBU_select_cpaklotsts(1, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 포장 정보 조회 시, 존재하면 MES 데이터
		if (DB_error_code != DB_NOT_FOUND)
		{
			// 포장 LOT 출하 상태 체크
			// 반품 -> SHIP_FLAG(Y) 상태에서 가능
			if (CPAKLOTSTS.SHIP_FLAG != 'Y')
			{
				// WIP-0579 : 해당 Lot은 출하되지 않았습니다. 상태를 확인해주세요.
				strcpy(s_msg_code, "WIP-0579");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 포장 LOT 반품 상태 체크
			// 반품 -> RET_FLAG(N) 상태에서 가능
			if (CPAKLOTSTS.RET_FLAG != 'N')
			{
				// WIP-0580 : 해당 Lot은 이미 반품되었습니다.
				strcpy(s_msg_code, "WIP-0580");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//최종 반품이라면, i_split_return_flag = 0;
			//분할 반품이라면, i_split_return_flag = 1;
			if (CPAKLOTSTS.QTY - CPAKLOTSTS.RETURNED_QTY == TRS.get_double(return_lot_list[i], "QTY"))
			{
				i_split_return_flag = 0;
			}
			else
			{
				i_split_return_flag = 1;
			}

			// MWIPLOTSTS - 포장 LOT 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), return_lot_list[i], "PACK_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//// TERMINATE된 출하 LOT -> REGENERATE
			regenerate_in = TRS.add_node(in_node, "regenerate_in");
			CopyDefaultMembers(regenerate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(regenerate_in, "PROCSTEP", '1');
			TRS.add_string(regenerate_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(regenerate_in, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
			TRS.add_string(regenerate_in, "LOT_CMF_7", MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7));
			TRS.add_string(regenerate_in, "LOT_CMF_8", MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8));
			TRS.add_string(regenerate_in, "LOT_CMF_9", MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9));
			TRS.add_string(regenerate_in, "LOT_CMF_10", MWIPLOTSTS.LOT_CMF_10, sizeof(MWIPLOTSTS.LOT_CMF_10));
			TRS.add_string(regenerate_in, "LOT_CMF_11", MWIPLOTSTS.LOT_CMF_11, sizeof(MWIPLOTSTS.LOT_CMF_11));
			TRS.add_string(regenerate_in, "LOT_CMF_12", MWIPLOTSTS.LOT_CMF_12, sizeof(MWIPLOTSTS.LOT_CMF_12));
			TRS.add_string(regenerate_in, "LOT_CMF_13", MWIPLOTSTS.LOT_CMF_13, sizeof(MWIPLOTSTS.LOT_CMF_13));
			TRS.add_string(regenerate_in, "LOT_CMF_14", MWIPLOTSTS.LOT_CMF_14, sizeof(MWIPLOTSTS.LOT_CMF_14));
			TRS.add_string(regenerate_in, "RESV_FIELD_3", MWIPLOTSTS.RESV_FIELD_3, sizeof(MWIPLOTSTS.RESV_FIELD_3));
			TRS.add_nstring(regenerate_in, "COMMENT", TRS.get_string(return_lot_list[i], "COMMENT"));

			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CRETORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
					{
						TRS.add_double(regenerate_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY") * COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)));
					}
					else
					{
						TRS.add_double(regenerate_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
					}
				}
				else
				{
					TRS.add_double(regenerate_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
				}
			}
			else
			{
				TRS.add_double(regenerate_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
			}
			
			TRS.add_double(regenerate_in, "QTY_2", 0);
			TRS.add_double(regenerate_in, "QTY_3", 0);

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_REGENERATE_LOT(s_msg_code, regenerate_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// MWIPLOTSTS - REGENERATE LOT 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), return_lot_list[i], "PACK_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (i_split_return_flag == 1
				|| (i_split_return_flag == 0 && COM_isnullspace(MWIPLOTSTS.LOT_CMF_14) == MP_FALSE))
			{
				//REGENERATE LOT의 정보를 통해 SPLIT 처리 -> 되살아난 LOT 자동 TERMINATE
				//해당 LOT을 REGENERATE하고 SPLIT으로 TERMINATE하는 이유 : 출하 나갔던 시점의 데이터로 SPLIT하기 위함.
				//이렇게 하지 않을 경우, 출하 나갔던 시점의 데이터를 보관할 수 없음.
				//최종반품일때만 기존 출하 LOT으로 부활
				//분할 처리된 데이터는 라벨 출력이 필요하므로 LOT_LIST 구성
				gen_in_node = TRS.add_node(in_node, "gen_in_node");
				TRS.add_char(gen_in_node, "PROCSTEP", '2');
				CopyDefaultMembers(gen_in_node, in_node);

				//LOT_CMF_14이 존재한다는 것은 PROD_IN 처리 되었다는 것
				if (COM_isnullspace(MWIPLOTSTS.LOT_CMF_14) == MP_FALSE)
				{
					DBU_init_minvlotsts(&MINVLOTSTS);
					TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
					memcpy(MINVLOTSTS.INV_LOT_ID, MWIPLOTSTS.LOT_CMF_14, sizeof(MINVLOTSTS.INV_LOT_ID));
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

					memcpy(s_org_inv_lot_id, MINVLOTSTS.ORG_INV_LOT_ID, sizeof(MINVLOTSTS.ORG_INV_LOT_ID));

					TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW, strlen(MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW));
					TRS.add_string(gen_in_node, "LOT_ID", s_org_inv_lot_id, strlen(s_org_inv_lot_id)); // Original Lot으로 발번

					cmn_out = TRS.create_node("cmn_out");
					if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					memcpy(s_new_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

					TRS.free_node(cmn_out);
				}
				else
				{
					if (memcmp(MWIPOPRDEF.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
					{
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
						TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTS.RESV_FIELD_3, strlen(MWIPLOTSTS.RESV_FIELD_3));

						cmn_out = TRS.create_node("cmn_out");
						if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						memcpy(s_new_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

						TRS.free_node(cmn_out);
					}
					else
					{
						//쿼리에서 split될 lot id 를 가져온다.
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);
						if (DB_error_code != DB_SUCCESS)
						{
							memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));
							sprintf(s_new_lot_id, MWIPLOTSTS.LOT_ID, "-01");
							sprintf(s_new_lot_id, "%.*s-01", COM_len_space(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID)), MWIPLOTSTS.LOT_ID);
						}
						else
						{
							memcpy(s_new_lot_id, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						}
					}
				}

				// 출하 LOT ID를 이용하여 NEW LOT ID로 SPLIT
				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(split_in, "PROCSTEP", '1');
				TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_string(split_in, "CHILD_LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
				TRS.add_string(split_in, "CHILD_LOT_DESC", MP_CREATE_DESC_RETURN_LOT, strlen(MP_CREATE_DESC_RETURN_LOT));
				TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTS.QTY_1);

				TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS.QTY_1);   //split 전 모랏의 총 수량
				TRS.add_string(split_in, "LOT_CMF_7", MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7));
				TRS.add_string(split_in, "LOT_CMF_8", MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8));
				TRS.add_string(split_in, "LOT_CMF_9", MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9));
				TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTS.RESV_FIELD_3, sizeof(MWIPLOTSTS.RESV_FIELD_3));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				//포장 취소로 생성된 LOT LIST
				lot_list = TRS.add_node(out_node, "LOT_LIST");
				TRS.add_string(lot_list, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
			}

			// 반품 창고로 MOVE
			move_in = TRS.add_node(in_node, "move_in");
			CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(move_in, "PROCSTEP", '4');
			if (i_split_return_flag == 0 && COM_isnullspace(MWIPLOTSTS.LOT_CMF_14) == MP_TRUE)
			{
				TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			}
			else
			{
				TRS.add_string(move_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
			}
			TRS.add_string(move_in, "TO_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
			TRS.add_string(move_in, "TO_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_nstring(move_in, "COMMENT", TRS.get_string(return_lot_list[i], "COMMENT"));
			TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// CPAKLOTSTS - 반품 처리
			CPAKLOTSTS.RETURNED_QTY = CPAKLOTSTS.RETURNED_QTY + TRS.get_double(return_lot_list[i], "QTY");

			if (CPAKLOTSTS.RETURNED_QTY > CPAKLOTSTS.QTY)
			{
				// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
				strcpy(s_msg_code, "INV-0021");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, CPAKLOTSTS.QTY);
				TRS.add_fieldmsg(out_node, "RETURN_QTY", MP_DBL, TRS.get_double(return_lot_list[i], "QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//반품완료 수량과 LOT 수량이 같으면 반품 종료
			if (CPAKLOTSTS.RETURNED_QTY == CPAKLOTSTS.QTY)
			{
				CPAKLOTSTS.RET_FLAG = 'Y';
			}

			TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_cpaklotsts(1, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 반품 지시 - 반품 수량 증가
			CRETORDSTS.RETURNED_QTY += TRS.get_double(return_lot_list[i], "QTY");

			if (CRETORDSTS.QTY < CRETORDSTS.RETURNED_QTY)
			{
				// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
				strcpy(s_msg_code, "INV-0021");
				TRS.add_fieldmsg(out_node, "CRETORDSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, CRETORDSTS.QTY);
				TRS.add_fieldmsg(out_node, "RETURN_QTY", MP_DBL, TRS.get_double(return_lot_list[i], "QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (CRETORDSTS.QTY == CRETORDSTS.RETURNED_QTY)
			{
				// CRETORDSTS - 반품 지시 정보
				// 상태 변경 (WAIT -> RETURNED)
				memcpy(CRETORDSTS.RET_ORD_STATUS, MP_CSHP_STATUS_RETURNED, sizeof(CRETORDSTS.RET_ORD_STATUS));
			}

			TRS.copy(CRETORDSTS.RET_DATE, sizeof(CRETLOTSTS.RET_DATE), in_node, "RETURN_DATE");
			TRS.copy(CRETORDSTS.UPDATE_USER_ID, sizeof(CRETORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETORDSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_cretordsts(1, &CRETORDSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CRETORDSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETORDSTS.FACTORY), CRETORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.RET_ORDER_ID), CRETORDSTS.RET_ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cretlotsts(&CRETLOTSTS);
			TRS.copy(CRETLOTSTS.FACTORY, sizeof(CRETLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CRETLOTSTS.RET_ORDER_ID, CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));

			//최종 반품일(0) 경우, PACK_LOT_ID
			//분할 반품(1)일 경우, SPLIT LOT ID
			if (i_split_return_flag == 0 && COM_isnullspace(MWIPLOTSTS.LOT_CMF_14) == MP_TRUE)
			{
				memcpy(CRETLOTSTS.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			}
			else
			{
				memcpy(CRETLOTSTS.LOT_ID, s_new_lot_id, sizeof(s_new_lot_id));
			}

			memcpy(CRETLOTSTS.RET_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			memcpy(CRETLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			CRETLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			CRETLOTSTS.QTY = TRS.get_double(return_lot_list[i], "QTY");
			
			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CRETORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5)) == MP_FALSE)
					{
						memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.MAT_CMF_5, sizeof(CRETLOTSTS.UNIT));
					}
					else
					{
						memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					}
				}
				else
				{
					memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				}
			}
			else
			{
				memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			}

			TRS.copy(CRETLOTSTS.RET_DATE, sizeof(CRETLOTSTS.RET_DATE), in_node, "RETURN_DATE");
			CRETLOTSTS.RET_LINE_NO = CRETORDSTS.LINE_NO;
			memcpy(CRETLOTSTS.PACK_DATE, CPAKLOTSTS.PACK_DATE, sizeof(CPAKLOTSTS.PACK_DATE));
			memcpy(CRETLOTSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
			CRETLOTSTS.PACK_LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
			memcpy(CRETLOTSTS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
			memcpy(CRETLOTSTS.SHIP_ORDER_ID, CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			CRETLOTSTS.SHIP_ORDER_SEQ = CPAKLOTSTS.SHIP_ORDER_SEQ;
			memcpy(CRETLOTSTS.CMF_1, CRETORDSTS.CMF_1, sizeof(CRETORDSTS.CMF_1));
			memset(CRETLOTSTS.CMF_2, ' ', sizeof(CRETLOTSTS.CMF_2));
			memset(CRETLOTSTS.CMF_3, ' ', sizeof(CRETLOTSTS.CMF_3));
			memset(CRETLOTSTS.CMF_4, ' ', sizeof(CRETLOTSTS.CMF_4));
			memset(CRETLOTSTS.CMF_5, ' ', sizeof(CRETLOTSTS.CMF_5));
			memset(CRETLOTSTS.CMF_6, ' ', sizeof(CRETLOTSTS.CMF_6));
			memset(CRETLOTSTS.CMF_7, ' ', sizeof(CRETLOTSTS.CMF_7));
			memset(CRETLOTSTS.CMF_8, ' ', sizeof(CRETLOTSTS.CMF_8));
			memset(CRETLOTSTS.CMF_9, ' ', sizeof(CRETLOTSTS.CMF_9));
			memset(CRETLOTSTS.CMF_10, ' ', sizeof(CRETLOTSTS.CMF_10));
			TRS.copy(CRETLOTSTS.CREATE_USER_ID, sizeof(CRETLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CRETLOTSTS.UPDATE_USER_ID, sizeof(CRETLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			// CRETLOTSTS - 반품 LOT 정보 생성
			DBU_insert_cretlotsts(&CRETLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CRETLOTSTS INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETLOTSTS.RET_ORDER_ID), CRETLOTSTS.RET_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CRETLOTSTS.LOT_ID), CRETLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		// 포장 정보 조회 시, 존재하지 않으면 과거 데이터
		// 반품 창고에 Lot 생성
		else
		{
			// MWIPLOTSTS - LOT 정보 조회(이전에 반품 처리된 LOT인지 체크)
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), return_lot_list[i], "PACK_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 과거 데이터 첫 반품은 입력된 LOT ID로 생성
			// 이후 같은 LOT ID로 반품된 경우, LOT ID 새로 발번하여 생성
			if (DB_error_code == DB_NOT_FOUND)
			{
				i_split_return_flag = 0;
			}
			else
			{
				i_split_return_flag = 1;
			}

			// 과거 제품이므로 어떤 제품창고에서 온 데이터인지 알수 없음.
			// 임의로 제품에 해당하는 FLOW와 OPER를 찾아서 임의의 데이터로 저장.
			// 제품에 해당하는 FLOW 조회
			DBU_init_mwipmatflw(&MWIPMATFLW);
			TRS.copy(MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATFLW.MAT_VER = MWIPMATDEF.MAT_VER;
			MWIPMATFLW.FLOW_SEQ_NUM = 1;
			DBU_select_mwipmatflw(3, &MWIPMATFLW);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATFLW.FACTORY), MWIPMATFLW.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATFLW.MAT_ID), MWIPMATFLW.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//반품창고의 FLOW, OPER를 조회
				DBU_init_mwipflwopr(&MWIPFLWOPR_TEMP);
				TRS.copy(MWIPFLWOPR_TEMP.FACTORY, sizeof(MWIPFLWOPR_TEMP.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR_TEMP.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipflwopr(5, &MWIPFLWOPR_TEMP);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR_TEMP.FACTORY), MWIPFLWOPR_TEMP.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR_TEMP.FLOW), MWIPFLWOPR_TEMP.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}
			else
			{
				// 제품에 해당하는 제품 창고 조회(마지막 공정)
				DBU_init_mwipflwopr(&MWIPFLWOPR_TEMP);
				TRS.copy(MWIPFLWOPR_TEMP.FACTORY, sizeof(MWIPFLWOPR_TEMP.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPFLWOPR_TEMP.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
				DBU_select_mwipflwopr(3, &MWIPFLWOPR_TEMP);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR_TEMP.FACTORY), MWIPFLWOPR_TEMP.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR_TEMP.FLOW), MWIPFLWOPR_TEMP.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}

			//반품 창고의 FLOW, OPER를 조회
			DBU_init_mwipflwopr(&MWIPFLWOPR);
			TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			DBU_select_mwipflwopr(5, &MWIPFLWOPR);

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

			//// CREATE LOT - 반품 창고로 생성
			create_in = TRS.add_node(in_node, "create_in");
			CopyDefaultMembers(create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(create_in, "PROCSTEP", '1');

			if (i_split_return_flag == 0)
			{
				TRS.add_nstring(create_in, "LOT_ID", TRS.get_string(return_lot_list[i], "PACK_LOT_ID"));
			}
			else
			{
				if (memcmp(MWIPOPRDEF.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
				{
					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);

					TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
					TRS.add_string(gen_in_node, "LOT_ID", TRS.get_string(return_lot_list[i], "PACK_LOT_ID"), strlen(TRS.get_string(return_lot_list[i], "PACK_LOT_ID")));

					cmn_out = TRS.create_node("cmn_out");
					if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					memcpy(s_new_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

					TRS.free_node(cmn_out);

					TRS.add_string(create_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
				}
				else
				{
					//쿼리에서 split될 lot id 를 가져온다.
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
					TRS_copy(MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), return_lot_list[i], "PACK_LOT_ID");
					DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);
					if (DB_error_code != DB_SUCCESS)
					{
						memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));
						sprintf(s_new_lot_id, MWIPLOTSTSX_SPLIT.LOT_ID, "-01");
						sprintf(s_new_lot_id, "%.*s-01", COM_len_space(MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID)), MWIPLOTSTSX_SPLIT.LOT_ID);
						TRS.add_string(create_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
					}
					else
					{
						memcpy(s_new_lot_id, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						TRS.add_string(create_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
					}
				}
			}
			
			TRS.add_string(create_in, "LOT_DESC", MP_CREATE_DESC_RETURN_LOT, strlen(MP_CREATE_DESC_RETURN_LOT));
			TRS.add_string(create_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(create_in, "MAT_VER", 1);
			TRS.add_char(create_in, "LOT_TYPE", MP_LOT_TYPE_PROD);
			TRS.add_string(create_in, "FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
			TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
			TRS.add_string(create_in, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));

			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CRETORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
					{
						TRS.add_double(create_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY") * COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)));
					}
					else
					{
						TRS.add_double(create_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
					}
				}
				else
				{
					TRS.add_double(create_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
				}
			}
			else
			{
				TRS.add_double(create_in, "QTY_1", TRS.get_double(return_lot_list[i], "QTY"));
			}
			
			TRS.add_char(create_in, "LOT_PRIORITY", '5');
			TRS.add_string(create_in, "OWNER_CODE", "PROD", strlen("PROD"));
			TRS.add_string(create_in, "CREATE_CODE", "PROD", strlen("PROD"));
			TRS.add_string(create_in, "LOT_CMF_7", MWIPFLWOPR_TEMP.FLOW, sizeof(MWIPFLWOPR_TEMP.FLOW));	// 제품에 해당하는 제품 FLOW
			TRS.add_string(create_in, "LOT_CMF_8", MWIPFLWOPR_TEMP.OPER, sizeof(MWIPFLWOPR_TEMP.OPER)); // 제품에 해당하는 제품 FLOW의 마지막 공정 값
			TRS.add_nstring(create_in, "RESV_FIELD_3", TRS.get_string(return_lot_list[i], "PACK_LOT_ID")); // 제품에 해당하는 제품 FLOW의 마지막 공정 값

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// 과거 데이터는 포장 정보가 존재하지 않기때문에, 포장 정보 업데이트는 제외.
			// 반품 지시 - 반품 수량 증가
			CRETORDSTS.RETURNED_QTY += TRS.get_double(return_lot_list[i], "QTY");

			if (CRETORDSTS.QTY < CRETORDSTS.RETURNED_QTY)
			{
				// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
				strcpy(s_msg_code, "INV-0021");
				TRS.add_fieldmsg(out_node, "CRETORDSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, CRETORDSTS.QTY);
				TRS.add_fieldmsg(out_node, "RETURN_QTY", MP_DBL, TRS.get_double(return_lot_list[i], "QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (CRETORDSTS.QTY == CRETORDSTS.RETURNED_QTY)
			{
				// CRETORDSTS - 반품 지시 정보
				// 상태 변경 (WAIT -> RETURNED)
				memcpy(CRETORDSTS.RET_ORD_STATUS, MP_CSHP_STATUS_RETURNED, sizeof(CRETORDSTS.RET_ORD_STATUS));
			}

			TRS.copy(CRETORDSTS.RET_DATE, sizeof(CRETLOTSTS.RET_DATE), in_node, "RETURN_DATE");
			TRS.copy(CRETORDSTS.UPDATE_USER_ID, sizeof(CRETORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETORDSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_cretordsts(1, &CRETORDSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CRETORDSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETORDSTS.FACTORY), CRETORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETORDSTS.RET_ORDER_ID), CRETORDSTS.RET_ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cretlotsts(&CRETLOTSTS);
			TRS.copy(CRETLOTSTS.FACTORY, sizeof(CRETLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CRETLOTSTS.RET_ORDER_ID, CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));

			//과거데이터
			//첫 반품일 경우(0), PACK_LOT_ID
			//추가 반품일 경우(1), SPLIT LOT ID
			if (i_split_return_flag == 0)
			{
				memcpy(CRETLOTSTS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			}
			else
			{
				memcpy(CRETLOTSTS.LOT_ID, s_new_lot_id, sizeof(s_new_lot_id));
			}

			memcpy(CRETLOTSTS.RET_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			memcpy(CRETLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			CRETLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			CRETLOTSTS.QTY = TRS.get_double(return_lot_list[i], "QTY");

			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CRETORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5)) == MP_FALSE)
					{
						memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.MAT_CMF_5, sizeof(CRETLOTSTS.UNIT));
					}
					else
					{
						memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					}
				}
				else
				{
					memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				}
			}
			else
			{
				memcpy(CRETLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			}

			TRS.copy(CRETLOTSTS.RET_DATE, sizeof(CRETLOTSTS.RET_DATE), in_node, "RETURN_DATE");
			CRETLOTSTS.RET_LINE_NO = CRETORDSTS.LINE_NO;
			memcpy(CRETLOTSTS.PACK_DATE, CPAKLOTSTS.PACK_DATE, sizeof(CPAKLOTSTS.PACK_DATE));
			memcpy(CRETLOTSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
			CRETLOTSTS.PACK_LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
			memcpy(CRETLOTSTS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
			memcpy(CRETLOTSTS.SHIP_ORDER_ID, CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			CRETLOTSTS.SHIP_ORDER_SEQ = CPAKLOTSTS.SHIP_ORDER_SEQ;
			memcpy(CRETLOTSTS.CMF_1, CRETORDSTS.CMF_1, sizeof(CRETORDSTS.CMF_1));
			memset(CRETLOTSTS.CMF_2, ' ', sizeof(CRETLOTSTS.CMF_2));
			memset(CRETLOTSTS.CMF_3, ' ', sizeof(CRETLOTSTS.CMF_3));
			memset(CRETLOTSTS.CMF_4, ' ', sizeof(CRETLOTSTS.CMF_4));
			memset(CRETLOTSTS.CMF_5, ' ', sizeof(CRETLOTSTS.CMF_5));
			memset(CRETLOTSTS.CMF_6, ' ', sizeof(CRETLOTSTS.CMF_6));
			memset(CRETLOTSTS.CMF_7, ' ', sizeof(CRETLOTSTS.CMF_7));
			memset(CRETLOTSTS.CMF_8, ' ', sizeof(CRETLOTSTS.CMF_8));
			memset(CRETLOTSTS.CMF_9, ' ', sizeof(CRETLOTSTS.CMF_9));
			memset(CRETLOTSTS.CMF_10, ' ', sizeof(CRETLOTSTS.CMF_10));
			TRS.copy(CRETLOTSTS.CREATE_USER_ID, sizeof(CRETLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CRETLOTSTS.UPDATE_USER_ID, sizeof(CRETLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRETLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			// CRETLOTSTS - 반품 LOT 정보 생성
			DBU_insert_cretlotsts(&CRETLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CRETLOTSTS INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "RET_ORDER_ID", MP_STR, sizeof(CRETLOTSTS.RET_ORDER_ID), CRETLOTSTS.RET_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CRETLOTSTS.LOT_ID), CRETLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//ERP 반품 실적
		if (send_flag == 0)
		{
			//ERP 실적 - IF_PO_RMA_HEADERS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "CUSTOMER_ID", COM_atoi(CRETORDSTS.CUSTOMER_ID, sizeof(CRETORDSTS.CUSTOMER_ID)));
			TRS.add_int(erpif_in, "CUSTOMER_SITE_ID", CRETORDSTS.CUSTOMER_SITE_ID);
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID));
			TRS.add_string(erpif_in, "MES_ID", CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));
			TRS.add_string(erpif_in, "CMF_1", CRETORDSTS.CUSTOMER_NUMBER, sizeof(CRETORDSTS.CUSTOMER_NUMBER));	//ATTRIBUTE1
			TRS.add_nstring(erpif_in, "RETURN_DATE", TRS.get_string(in_node, "RETURN_DATE"));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_RMA_HEADERS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_po_rma_headers(&IF_PO_RMA_HEADERS);
			TRS.copy(IF_PO_RMA_HEADERS.FACTORY, sizeof(IF_PO_RMA_HEADERS.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_PO_RMA_HEADERS.MES_ID, CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));

			//ERP 실적 - IF_PO_RMA_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "RMA_HEADER_ID", (double)DBU_select_if_po_rma_headers_scalar(2, &IF_PO_RMA_HEADERS));
			TRS.add_double(erpif_in, "OE_ORDER_HEADER_ID", CRETORDSTS.OE_ORDER_HEADER_ID);
			TRS.add_double(erpif_in, "OE_ORDER_LINE_ID", CRETORDSTS.OE_ORDER_LINE_ID);
			TRS.add_int(erpif_in, "CUSTOMER_ID", COM_atoi(CRETORDSTS.CUSTOMER_ID, sizeof(CRETORDSTS.CUSTOMER_ID)));
			TRS.add_int(erpif_in, "CUSTOMER_SITE_ID", CRETORDSTS.CUSTOMER_SITE_ID);
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_double(erpif_in, "QTY", TRS.get_double(in_node, "TOTAL_QTY"));
			TRS.add_string(erpif_in, "UNIT", CRETORDSTS.UNIT, sizeof(CRETORDSTS.UNIT));
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", CRETORDSTS.AREA_ID, sizeof(CRETORDSTS.AREA_ID));
			TRS.add_string(erpif_in, "MES_ID", CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));
			TRS.add_string(erpif_in, "CMF_1", CRETORDSTS.CUSTOMER_NUMBER, sizeof(CRETORDSTS.CUSTOMER_NUMBER));	//ATTRIBUTE1
			TRS.add_nstring(erpif_in, "RETURN_DATE", TRS.get_string(in_node, "RETURN_DATE"));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_RMA_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			send_flag = 1;
		}

		DBU_init_if_po_rma_txns(&IF_PO_RMA_TXNS);
		TRS.copy(IF_PO_RMA_TXNS.FACTORY, sizeof(IF_PO_RMA_TXNS.FACTORY), in_node, IN_FACTORY);
		memcpy(IF_PO_RMA_TXNS.MES_ID, CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));

		//ERP 실적 - IF_PO_RMA_TNX_LOTS
		erpif_in = TRS.add_node(in_node, "erpif_in");
		TRS.add_char(erpif_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(erpif_in, in_node);

		TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
		TRS.add_double(erpif_in, "RMA_HEADER_ID", (double)DBU_select_if_po_rma_headers_scalar(2, &IF_PO_RMA_HEADERS));
		TRS.add_double(erpif_in, "RMA_TXNS_ID", (double)DBU_select_if_po_rma_txns_scalar(2, &IF_PO_RMA_TXNS));
		TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
		TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));

		if (i_split_return_flag == 0)
		{
			TRS.add_nstring(erpif_in, "LOT_ID", TRS.get_string(return_lot_list[i], "PACK_LOT_ID"));
		}
		else
		{
			TRS.add_string(erpif_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
		}

		TRS.add_double(erpif_in, "QTY", TRS.get_double(return_lot_list[i], "QTY"));
		TRS.add_string(erpif_in, "MES_ID", CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID));
		TRS.add_nstring(erpif_in, "RETURN_DATE", TRS.get_string(in_node, "RETURN_DATE"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_IFS_PO_RMA_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
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
    CUS_SHP_Return_Lot_Validation()
        - Validation Check sub function of "CUS_SHP_RETURN_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_RETURN_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Return_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{   
	/*
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }
	*/
    
    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Return_Lot_Before_Transaction()
- Main sub function of "CUS_SHP_RETURN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Return_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Return_Lot_After_Transaction()
- Main sub function of "CUS_SHP_RETURN_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Return_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}