/*******************************************************************************

	System      : MESplus
	Module      : CUS_SHP
	File Name   : CUS_SHP_confirm_pack_order.c
	Description : Confirm Pack Order

	MES Version : 5.2.0

	Function List
		- CUS_SHP_Confirm_Pack_Order()
			+ Confirm Pack Order
		- CUS_SHP_CONFIRM_PACK_ORDER()
			+ Main Sub function of "CUS_SHP_Confirm_Pack_Order"
			+ (called by "CUS_SHP_Confirm_Pack_Order")
		- CUS_SHP_Confirm_Pack_Order_Validation()
			+ Validation Check sub function of "CUS_SHP_CONFIRM_PACK_ORDER" function
			+ (called by "CUS_SHP_CONFIRM_PACK_ORDER")

	Detail Description
		-

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2020/08/27  Miracom         Create

	Copyright(C) 1998-2020 Miracom,Inc.
	All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_CONFIRM_PACK_ORDER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Confirm_Pack_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_CONFIRM_PACK_ORDER_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Confirm_Pack_Order_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Confirm_Pack_Order_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
	CUS_SHP_Confirm_Pack_Order()
		- Confirm Pack Order
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- CUS_SHP_Confirm_Pack_Order_In_Tag *CUS_SHP_Confirm_Pack_Order_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Confirm_Pack_Order(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	
	
	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_SHP_CONFIRM_PACK_ORDER_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_SHP_CONFIRM_PACK_ORDER", out_node);

	if (i_ret == MP_TRUE)
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
CUS_SHP_CONFIRM_PACK_ORDER_MAIN()
- Main sub function of "CUS_SHP_CONFIRM_PACK_ORDER_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_CONFIRM_PACK_ORDER_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CONFIRM_PACK_ORDER_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	TRSNode* confirm_in_node;
	TRSNode** pack_lot_list;
	TRSNode* lot_list;
	int i;

	LOG_head("CUS_SHP_CONFIRM_PACK_ORDER");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_SHP_Confirm_Pack_Order_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	confirm_in_node = TRS.add_node(in_node, "confirm_in_node");
	CopyDefaultMembers(confirm_in_node, in_node);

	TRS.add_char(confirm_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(confirm_in_node, "PACK_ORDER_ID", TRS.get_string(in_node, "PACK_ORDER_ID"));
	TRS.add_int(confirm_in_node, "LINE_NO", TRS.get_int(in_node, "LINE_NO"));
	TRS.add_char(confirm_in_node, "OSP_SHIP_FlAG", TRS.get_char(in_node, "OSP_SHIP_FlAG"));
	TRS.add_nstring(confirm_in_node, "TO_OPER_CODE", TRS.get_string(in_node, "TO_OPER_CODE"));

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(confirm_in_node, "PACK_LOT_LIST");
		TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(pack_lot_list[i], "ORG_LOT_ID"));
		TRS.add_nstring(lot_list, "PACK_LOT_ID", TRS.get_string(pack_lot_list[i], "PACK_LOT_ID"));
	}


	if (CUS_SHP_Confirm_Pack_Order_Before_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_CONFIRM_PACK_ORDER(s_msg_code, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Confirm_Pack_Order_After_Transaction(s_msg_code, 0, confirm_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_SHP_CONFIRM_PACK_ORDER()
		- Main sub function of "CUS_SHP_Confirm_Pack_Order" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_SHP_CONFIRM_PACK_ORDER_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CONFIRM_PACK_ORDER(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS_ORG;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS_PAK;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS_NEW;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;
	struct IF_OM_TXNS_TAG IF_OM_TXNS;
	struct IF_OM_TXN_LOTS_TAG IF_OM_TXN_LOTS;
	struct CSHPORDDTL_TAG CSHPORDDTL_COUNT;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct ISHPLOTRCV_TAG ISHPLOTRCV;

	TRSNode* erpif_in;
	TRSNode* split_in;
	TRSNode* cv_in;
	TRSNode* merge_in;
	TRSNode* move_in;
	TRSNode* regenerate_in;
	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	TRSNode** pack_lot_list;
	TRSNode* lot_list;
	TRSNode* raise_alarm;

	char s_sys_time[14];
	char s_new_lot_id[26];
	char s_org_lot_id[26];
	char s_org_inv_lot_id[26];

	int i;
	int db_flag = 0;
	double d_total_qty = 0;
	double d_ship_reg_qty = 0;
	double d_pack_reg_qty = 0;

	double d_if_seq = 0;
	char sCmfValue[30];
	double dCount = 0;

	memset(sCmfValue, 0x00, sizeof(sCmfValue));
	memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_org_inv_lot_id, 0x00, sizeof(s_org_inv_lot_id));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// CPAKORDSTS - 포장 지시 정보 조회
	DBU_init_cpakordsts(&CPAKORDSTS);
	TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
	CPAKORDSTS.LINE_NO = TRS.get_int(in_node, "LINE_NO");
	DBU_select_cpakordsts(1, &CPAKORDSTS);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
		TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	//AREA 정보 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
	memcpy(MGCMTBLDAT.KEY_1, CPAKORDSTS.AREA_ID, sizeof(CPAKORDSTS.AREA_ID));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

	if (DB_error_code != DB_SUCCESS)
	{
		//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
		strcpy(s_msg_code, "GCM-0008");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//SRC 코드 가져오기 - 한글
	DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
	TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
	memcpy(MGCMTBLDAT_SRC.KEY_1, "PACK", strlen("PACK"));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);

	// PROCSTEP : 1 -> 포장 지시 확정
	// PROCSTEP : 2 -> 포장 지시 확정 취소
	if (TRS.get_procstep(in_node) == '1')
	{
		// 포장 지시 상태 체크
		// 상태 : WAIT -> 확정 가능 상태
		if (memcmp(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
		{
			//WIP-0565 : 해당 포장 지시는 이미 포장 완료되었습니다.
			strcpy(s_msg_code, "WIP-0565");
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
		{
			// CPAKLOTSTS - 포장 LOT 정보 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
			CPAKLOTSTS.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
			TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
			TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
			DBU_select_cpaklotsts(2, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 LOT 출하 여부 체크
			if (CPAKLOTSTS.SHIP_FLAG == 'Y')
			{
				strcpy(s_msg_code, "WIP-0569");
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			d_total_qty += CPAKLOTSTS.QTY;

			// MWIPLOTSTS - 공정 LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
			TRS.copy(MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPLOTSTS_ORG.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_ORG.LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_ORG.FACTORY), MWIPLOTSTS_ORG.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_ORG.LOT_ID), MWIPLOTSTS_ORG.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPLOTSTS_ORG.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTS_ORG.MAT_VER;
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

			// MWIPLOTSTS - 포장 LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_PAK);
			TRS.copy(MWIPLOTSTS_PAK.FACTORY, sizeof(MWIPLOTSTS_PAK.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_PAK.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_PAK);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_PAK.FACTORY), MWIPLOTSTS_PAK.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_PAK.LOT_ID), MWIPLOTSTS_PAK.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//MWIPLOTSTS 존재하지 않으면 신규 출하 LOT
			if (DB_error_code == DB_NOT_FOUND)
			{
				// 포장 LOT ID를 이용하여 공정 LOT SPLIT.
				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(split_in, "PROCSTEP", '2');
				TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				TRS.add_string(split_in, "CHILD_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
				TRS.add_string(split_in, "CHILD_LOT_DESC", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));

				if (MGCMTBLDAT.DATA_4[0] == 'Y')
				{
					if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
					{
						if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
						{
							TRS.add_double(split_in, "MOVE_QTY_1", CPAKLOTSTS.QTY * COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6))); // QTY_1 유효중량
						}
						else
						{
							TRS.add_double(split_in, "MOVE_QTY_1", CPAKLOTSTS.QTY); // QTY_1 유효중량
						}
					}
					else
					{
						TRS.add_double(split_in, "MOVE_QTY_1", CPAKLOTSTS.QTY); // QTY_1 유효중량
					}
				}
				else
				{
					TRS.add_double(split_in, "MOVE_QTY_1", CPAKLOTSTS.QTY); // QTY_1 유효중량
				}


				//20250416 커맨트에 "PACKED"로 들어가던거를 원래 가지고 있던 커맨드값 들어가도록 변경 , 
				//왜 "PACKED" 를 넣었었는지를 모르겠어서......혹시 다른데 영향있을지는 없는거 같기는 한데.......
				//TRS.add_string(split_in, "COMMENT", MP_CSHP_STATUS_PACKED, strlen(MP_CSHP_STATUS_PACKED));
				TRS.add_string(split_in, "COMMENT", MWIPLOTSTS_ORG.LAST_COMMENT, strlen(MWIPLOTSTS_ORG.LAST_COMMENT));


				TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_ORG.QTY_1);   //split 전 모랏의 총 수량
				TRS.add_string(split_in, "LOT_CMF_7", MWIPLOTSTS_ORG.LOT_CMF_7, sizeof(MWIPLOTSTS_ORG.LOT_CMF_7));
				TRS.add_string(split_in, "LOT_CMF_8", MWIPLOTSTS_ORG.LOT_CMF_8, sizeof(MWIPLOTSTS_ORG.LOT_CMF_8));
				TRS.add_string(split_in, "LOT_CMF_9", MWIPLOTSTS_ORG.LOT_CMF_9, sizeof(MWIPLOTSTS_ORG.LOT_CMF_9));
				TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTS_ORG.RESV_FIELD_3, sizeof(MWIPLOTSTS_ORG.RESV_FIELD_3));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			//MWIPLOTSTS 존재하면 재포장 출하 LOT
			else
			{
				DBU_init_ishplotrcv(&ISHPLOTRCV);
				TRS.copy(ISHPLOTRCV.FACTORY, sizeof(ISHPLOTRCV.FACTORY), in_node, IN_FACTORY);
				TRS.copy(ISHPLOTRCV.PACK_LOT_ID, sizeof(ISHPLOTRCV.PACK_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
				dCount = DBU_select_ishplotrcv_scalar(2, &ISHPLOTRCV);
				//타법인에서 출하되어 입고한 제품(ISHPLOTRCV)인 경우 중, 포장LOT으로 입고 잡았던 LOT인 경우
				//EX) 베트남 -> 음성으로 출하하여 입고.(역물류인경우)
				if (dCount > 0 && ISHPLOTRCV.PACK_LOT_ID[0] == 'V')
				{
				}
				else
				{
					// 출하 LOT이 WIPLOT을 가지고 있다는 것은 포장 확정 되었다가 취소된 경우
					// 포장 취소되면, 해당 출하LOT(WIPLOT) 정보는 삭제처리 되기때문에 무조건 DELETE(Y)인 상황.
					// REGENERATE로 되살려서 확정 진행할 것.
					regenerate_in = TRS.add_node(in_node, "regenerate_in");
					CopyDefaultMembers(regenerate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(regenerate_in, IN_PROCSTEP, '1');
					TRS.add_string(regenerate_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
					TRS.add_string(regenerate_in, "MAT_ID", MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPLOTSTS_ORG.MAT_ID));
					TRS.add_string(regenerate_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
					TRS.add_string(regenerate_in, "LOT_CMF_7", MWIPLOTSTS_ORG.LOT_CMF_7, sizeof(MWIPLOTSTS_ORG.LOT_CMF_7));
					TRS.add_string(regenerate_in, "LOT_CMF_8", MWIPLOTSTS_ORG.LOT_CMF_8, sizeof(MWIPLOTSTS_ORG.LOT_CMF_8));
					TRS.add_string(regenerate_in, "LOT_CMF_9", MWIPLOTSTS_ORG.LOT_CMF_9, sizeof(MWIPLOTSTS_ORG.LOT_CMF_9));
					TRS.add_string(regenerate_in, "LOT_CMF_10", MWIPLOTSTS_ORG.LOT_CMF_10, sizeof(MWIPLOTSTS_ORG.LOT_CMF_10));
					TRS.add_string(regenerate_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
					TRS.add_string(regenerate_in, "LOT_CMF_12", MWIPLOTSTS_ORG.LOT_CMF_12, sizeof(MWIPLOTSTS_ORG.LOT_CMF_12));
					TRS.add_string(regenerate_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
					TRS.add_string(regenerate_in, "LOT_CMF_14", MWIPLOTSTS_ORG.LOT_CMF_14, sizeof(MWIPLOTSTS_ORG.LOT_CMF_14));
					TRS.add_string(regenerate_in, "RESV_FIELD_3", MWIPLOTSTS_ORG.RESV_FIELD_3, sizeof(MWIPLOTSTS_ORG.RESV_FIELD_3));

					if (MGCMTBLDAT.DATA_4[0] == 'Y')
					{
						if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
						{
							if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
							{
								TRS.add_double(regenerate_in, "QTY_1", CPAKLOTSTS.QTY * COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)));
							}
							else
							{
								TRS.add_double(regenerate_in, "QTY_1", CPAKLOTSTS.QTY);
							}
						}
						else
						{
							TRS.add_double(regenerate_in, "QTY_1", CPAKLOTSTS.QTY);
						}
					}
					else
					{
						TRS.add_double(regenerate_in, "QTY_1", CPAKLOTSTS.QTY);
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

					// 공정 LOT CV 처리
					cv_in = TRS.add_node(in_node, "cv_in");
					CopyDefaultMembers(cv_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
					TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTS_ORG.MAT_ID, sizeof(MWIPLOTSTS_ORG.MAT_ID));
					TRS.add_string(cv_in, "OPER", MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
					TRS.add_string(cv_in, "FLOW", MWIPLOTSTS_ORG.FLOW, sizeof(MWIPLOTSTS_ORG.FLOW));


					if (MGCMTBLDAT.DATA_4[0] == 'Y')
					{
						if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
						{
							if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
							{
								TRS.add_double(cv_in, "QTY_1", MWIPLOTSTS_ORG.QTY_1 - (CPAKLOTSTS.QTY * COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6))));
							}
							else
							{
								TRS.add_double(cv_in, "QTY_1", MWIPLOTSTS_ORG.QTY_1 - CPAKLOTSTS.QTY);
							}
						}
						else
						{
							TRS.add_double(cv_in, "QTY_1", MWIPLOTSTS_ORG.QTY_1 - CPAKLOTSTS.QTY);
						}
					}
					else
					{
						TRS.add_double(cv_in, "QTY_1", MWIPLOTSTS_ORG.QTY_1 - CPAKLOTSTS.QTY);
					}

					TRS.add_string(cv_in, "COMMENT", MP_CSHP_STATUS_PACKED, strlen(MP_CSHP_STATUS_PACKED));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
			}

			// MWIPLOTSTS - 포장 LOT ID 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_PAK);
			TRS.copy(MWIPLOTSTS_PAK.FACTORY, sizeof(MWIPLOTSTS_PAK.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_PAK.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_PAK);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_PAK.FACTORY), MWIPLOTSTS_PAK.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_PAK.LOT_ID), MWIPLOTSTS_PAK.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MWIPOPRDEF - 완제품 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS_ORG.OPER, sizeof(MWIPLOTSTS_ORG.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//SKY경우 CB-STG-S 창고에서 출하됨.EPR창고코드는 같음.
			if (TRS.get_char(in_node, "OSP_SHIP_FlAG") != 'Y') {

				// MWIPOPRDEF - TO 창고 조회(출하 대기 창고)
				DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
				TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_TO.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				memcpy(MWIPOPRDEF_TO.OPER_GRP_1, MP_OPER_GRP_TYPE_SHIP, sizeof(MWIPOPRDEF_TO.OPER_GRP_1));
				MWIPOPRDEF_TO.INV_FLAG = 'Y';
				MWIPOPRDEF_TO.SHIP_FLAG = 'Y';
				DBU_select_mwipoprdef(5, &MWIPOPRDEF_TO);
			}
			else {
				// MWIPOPRDEF - TO 창고 조회(출하 대기 창고)
				DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
				TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER_CODE");
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

			}



			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF_TO.AREA_ID), MWIPOPRDEF_TO.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 LOT ID 출하대기 창고로 MOVE
			move_in = TRS.add_node(in_node, "move_in");
			CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(move_in, "PROCSTEP", '3');
			TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(move_in, "TO_FLOW", MWIPLOTSTS_PAK.FLOW, sizeof(MWIPLOTSTS_PAK.FLOW));
			TRS.add_string(move_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			TRS.add_string(move_in, "PREV_PROD_OPER", MWIPLOTSTS_PAK.OPER, sizeof(MWIPLOTSTS_PAK.OPER));
			TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//ERP 실적 - IF_OM_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_2));
			TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
			TRS.add_string(erpif_in, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_double(erpif_in, "QTY", CPAKLOTSTS.QTY);
			TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
			TRS.add_char(erpif_in, "CANCEL_FLAG", 'N');
			TRS.add_int(erpif_in, "HEADER_ID", COM_atoi(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID)));
			TRS.add_int(erpif_in, "LINE_NUMBER", CPAKORDSTS.LINE_NO);
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_OM_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_om_txns(&IF_OM_TXNS);
			TRS.copy(IF_OM_TXNS.FACTORY, sizeof(IF_OM_TXNS.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_OM_TXNS.MES_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			//ERP 실적 - IF_OM_TXN_LOTS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "OM_TXNS_ID", (double)DBU_select_if_om_txns_scalar(2, &IF_OM_TXNS));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_double(erpif_in, "QTY", CPAKLOTSTS.QTY);
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_OM_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// CPAKLOTSTS - 포장 LOT 정보 확정
			// 상태 변경 PACK_FLAG(N -> Y)
			// 포장 I/F SEQ 저장
			d_if_seq = DBU_select_if_om_txns_scalar(2, &IF_OM_TXNS);
			memset(sCmfValue, ' ', sizeof(sCmfValue));
			sprintf(sCmfValue, "%.0f", d_if_seq);
			memcpy(CPAKLOTSTS.CMF_4, sCmfValue, sizeof(CPAKLOTSTS.CMF_4));

			CPAKLOTSTS.PACK_FLAG = 'Y';
			TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_cpaklotsts(1, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}



			if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
			{

				raise_alarm = TRS.create_node("RAISE_ALARM");

				TRS.set_char(raise_alarm, IN_LANGUAGE, '1');
				TRS.set_nstring(raise_alarm, IN_FACTORY, "IJDK1");
				TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
				TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
				TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));
				TRS.add_char(raise_alarm, IN_PROCSTEP, '1');

				TRS.add_string(raise_alarm, "ALARM_ID", "SHIP_REPORT_REQUST", strlen("SHIP_REPORT_REQUST"));

	
				TRS.add_string(raise_alarm, "LOT_ID", CPAKLOTSTS.PACK_LOT_ID, strlen(CPAKLOTSTS.PACK_LOT_ID));
				TRS.add_string(raise_alarm, "ALARM_SUBJECT", CPAKLOTSTS.CMF_2, strlen(CPAKLOTSTS.CMF_2));
				TRS.add_nstring(raise_alarm, "SOURCE_DESC_1", "HM SHIP REPORT REQUEST");
				TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "HM SHIP REPORT REQUEST2");


				if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
				{
					return MP_FALSE;
				}
			}


		}

		//포장 완료 수량 증가
		CPAKORDSTS.PACKED_QTY = CPAKORDSTS.PACKED_QTY + d_total_qty;

		//지시수량보다 크다면 에러
		if (CPAKORDSTS.QTY < CPAKORDSTS.PACKED_QTY)
		{
			// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKORDSTS - 주문 수량과 포장완료 수량이 같으면 상태 PACKED
		if (CPAKORDSTS.PACKED_QTY == CPAKORDSTS.QTY)
		{
			memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_PACKED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
		}



		memcpy(CPAKORDSTS.PACK_DATE, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CPAKORDSTS.UPDATE_USER_ID, sizeof(CPAKORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CPAKORDSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_cpakordsts(1, &CPAKORDSTS);




		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKORDSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}






	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));
		memset(s_org_lot_id, ' ', sizeof(s_org_lot_id));

		pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
		{
			// CPAKLOTSTS - 포장 LOT 정보 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
			CPAKLOTSTS.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
			TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
			TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
			DBU_select_cpaklotsts(2, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 LOT 출하 여부 체크
			if (CPAKLOTSTS.SHIP_FLAG == 'Y')
			{
				strcpy(s_msg_code, "WIP-0569");
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			d_total_qty += CPAKLOTSTS.QTY;

			// MWIPLOTSTS - 포장 LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_PAK);
			TRS.copy(MWIPLOTSTS_PAK.FACTORY, sizeof(MWIPLOTSTS_PAK.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_PAK.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_PAK);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_PAK.FACTORY), MWIPLOTSTS_PAK.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_PAK.LOT_ID), MWIPLOTSTS_PAK.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// FROM 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS_PAK.OPER, sizeof(MWIPLOTSTS_PAK.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// TO 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
			TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_TO.OPER, MWIPLOTSTS_PAK.LOT_CMF_9, sizeof(MWIPLOTSTS_PAK.LOT_CMF_9));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 LOT ID 기존 완제품 창고로 MOVE
			move_in = TRS.add_node(in_node, "move_in");
			CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(move_in, "PROCSTEP", '3');
			TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(move_in, "TO_FLOW", MWIPLOTSTS_PAK.FLOW, sizeof(MWIPLOTSTS_PAK.FLOW));
			TRS.add_string(move_in, "TO_OPER", MWIPLOTSTS_PAK.LOT_CMF_9, sizeof(MWIPLOTSTS_PAK.LOT_CMF_9));
			TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			// MWIPLOTSTS - 포장 LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_PAK);
			TRS.copy(MWIPLOTSTS_PAK.FACTORY, sizeof(MWIPLOTSTS_PAK.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_PAK.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_PAK);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_PAK.FACTORY), MWIPLOTSTS_PAK.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_PAK.LOT_ID), MWIPLOTSTS_PAK.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// MWIPLOTSTS - 공정 LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS_ORG);
			TRS.copy(MWIPLOTSTS_ORG.FACTORY, sizeof(MWIPLOTSTS_ORG.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS_ORG.LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS_ORG);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_ORG.FACTORY), MWIPLOTSTS_ORG.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_ORG.LOT_ID), MWIPLOTSTS_ORG.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 공정 LOT이 조회되지 않는 경우, 마이그레이션 데이터
			if (DB_error_code == DB_NOT_FOUND)
			{
				if (COM_isnullspace(s_new_lot_id) == MP_TRUE || memcmp(s_org_lot_id, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID)) != 0)
				{
					if (memcmp(MWIPOPRDEF_TO.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
					{
						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);

						//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
						TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTS_PAK.RESV_FIELD_3, strlen(MWIPLOTSTS_PAK.RESV_FIELD_3));

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
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);
						if (DB_error_code != DB_SUCCESS)
						{
							memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));
							sprintf(s_new_lot_id, MWIPLOTSTS_ORG.LOT_ID, "-01");
							sprintf(s_new_lot_id, "%.*s-01", COM_len_space(MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID)), MWIPLOTSTS_ORG.LOT_ID);
						}
						else
						{
							memcpy(s_new_lot_id, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						}
					}

					//포장 취소로 생성된 LOT LIST
					lot_list = TRS.add_node(out_node, "LOT_LIST");
					TRS.add_string(lot_list, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));

					memcpy(s_org_lot_id, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
				}

				// MWIPLOTSTS - NEW LOT 조회
				DBU_init_mwiplotstsx(&MWIPLOTSTS_NEW);
				TRS.copy(MWIPLOTSTS_NEW.FACTORY, sizeof(MWIPLOTSTS_NEW.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPLOTSTS_NEW.LOT_ID, s_new_lot_id, sizeof(s_new_lot_id));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTS_NEW);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_NEW.FACTORY), MWIPLOTSTS_NEW.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_NEW.LOT_ID), MWIPLOTSTS_NEW.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				if (DB_error_code == DB_NOT_FOUND)
				{
					// 포장 LOT ID를 이용하여 NEW LOT ID로 SPLIT
					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(split_in, "PROCSTEP", '2');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
					TRS.add_string(split_in, "CHILD_LOT_DESC", s_new_lot_id, sizeof(s_new_lot_id));
					TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTS_PAK.QTY_1);

					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_PAK.QTY_1);   //split 전 모랏의 총 수량
					TRS.add_string(split_in, "LOT_CMF_7", MWIPLOTSTS_PAK.LOT_CMF_7, sizeof(MWIPLOTSTS_PAK.LOT_CMF_7));
					TRS.add_string(split_in, "LOT_CMF_8", MWIPLOTSTS_PAK.LOT_CMF_8, sizeof(MWIPLOTSTS_PAK.LOT_CMF_8));
					TRS.add_string(split_in, "LOT_CMF_9", MWIPLOTSTS_PAK.LOT_CMF_9, sizeof(MWIPLOTSTS_PAK.LOT_CMF_9));
					TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTS_PAK.RESV_FIELD_3, sizeof(MWIPLOTSTS_PAK.RESV_FIELD_3));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
				else
				{
					// NEW 공정 LOT에 포장 LOT 병합(MERGE)
					merge_in = TRS.add_node(in_node, "merge_in");
					TRS.add_char(merge_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(merge_in, in_node);

					TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
					TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTS_NEW.LOT_ID, sizeof(MWIPLOTSTS_NEW.LOT_ID));
					TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTS_PAK.QTY_1);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}

				//해당 포장 LOT 포장 정보 변경
				//주문지시, 라인번호, 포장여부, 포장일자 초기화
				memcpy(CPAKLOTSTS.ORG_LOT_ID, MWIPLOTSTS_NEW.LOT_ID, sizeof(MWIPLOTSTS_NEW.LOT_ID));
				memset(CPAKLOTSTS.PACK_ORDER_ID, ' ', sizeof(CPAKLOTSTS.PACK_ORDER_ID));
				CPAKLOTSTS.PACK_LINE_NO = 0;
				CPAKLOTSTS.QTY = 0;
				CPAKLOTSTS.PACK_FLAG = 'N';
				memset(CPAKLOTSTS.PACK_DATE, ' ', sizeof(CPAKLOTSTS.PACK_DATE));
				TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

				//20250527 포장LOT 유지하는것땜시 계속걸려서..선택사항으로 바꿈.
				if (TRS.get_char(in_node, "PACK_LOT_DEL") == 'Y') 
				{
					DBU_delete_cpaklotsts(1, &CPAKLOTSTS);
				}
				else {
					DBU_update_cpaklotsts(6, &CPAKLOTSTS);
				}


				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
					TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			// 공정 LOT이 조회되는 경우, MES 데이터
			else
			{
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVLOTSTS.INV_LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
				DBU_select_minvlotsts(1, &MINVLOTSTS);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

				if (DB_error_code == DB_NOT_FOUND)
				{
					db_flag = 0;
				}
				else if (DB_error_code == DB_SUCCESS)
				{
					if (MINVLOTSTS.DELETE_FLAG == 'Y')
					{
						db_flag = 0;
					}
					else
					{
						db_flag = 1;
					}
				}

				// 공정 LOT이 완제품 창고에 존재하는 경우
				if (memcmp(MWIPLOTSTS_ORG.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER)) == 0 && db_flag == 0)
				{
					// LOT이 죽어있는 경우
					if (MWIPLOTSTS_ORG.LOT_DEL_FLAG == 'Y')
					{
						// 공정 LOT이 죽어있는 경우, 해당 공정 LOT REGENERATE
						// 되살려서 MERGE
						regenerate_in = TRS.add_node(in_node, "regenerate_in");
						CopyDefaultMembers(regenerate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(regenerate_in, "PROCSTEP", '1');
						TRS.add_string(regenerate_in, "LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_string(regenerate_in, "ORDER_ID", MWIPLOTSTS_ORG.ORDER_ID, sizeof(MWIPLOTSTS_ORG.ORDER_ID));
						TRS.add_string(regenerate_in, "LOT_CMF_7", MWIPLOTSTS_ORG.LOT_CMF_7, sizeof(MWIPLOTSTS_ORG.LOT_CMF_7));
						TRS.add_string(regenerate_in, "LOT_CMF_8", MWIPLOTSTS_ORG.LOT_CMF_8, sizeof(MWIPLOTSTS_ORG.LOT_CMF_8));
						TRS.add_string(regenerate_in, "LOT_CMF_9", MWIPLOTSTS_ORG.LOT_CMF_9, sizeof(MWIPLOTSTS_ORG.LOT_CMF_9));
						TRS.add_string(regenerate_in, "LOT_CMF_10", MWIPLOTSTS_ORG.LOT_CMF_10, sizeof(MWIPLOTSTS_ORG.LOT_CMF_10));
						TRS.add_string(regenerate_in, "LOT_CMF_11", MWIPLOTSTS_ORG.LOT_CMF_11, sizeof(MWIPLOTSTS_ORG.LOT_CMF_11));
						TRS.add_string(regenerate_in, "LOT_CMF_12", MWIPLOTSTS_ORG.LOT_CMF_12, sizeof(MWIPLOTSTS_ORG.LOT_CMF_12));
						TRS.add_string(regenerate_in, "LOT_CMF_13", MWIPLOTSTS_ORG.LOT_CMF_13, sizeof(MWIPLOTSTS_ORG.LOT_CMF_13));
						TRS.add_string(regenerate_in, "LOT_CMF_14", MWIPLOTSTS_ORG.LOT_CMF_14, sizeof(MWIPLOTSTS_ORG.LOT_CMF_14));
						TRS.add_string(regenerate_in, "RESV_FIELD_3", MWIPLOTSTS_ORG.RESV_FIELD_3, sizeof(MWIPLOTSTS_ORG.RESV_FIELD_3));
						TRS.add_double(regenerate_in, "QTY_1", 0);
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
					}

					DBU_init_ishplotrcv(&ISHPLOTRCV);
					TRS.copy(ISHPLOTRCV.FACTORY, sizeof(ISHPLOTRCV.FACTORY), in_node, IN_FACTORY);
					TRS.copy(ISHPLOTRCV.PACK_LOT_ID, sizeof(ISHPLOTRCV.PACK_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
					dCount = DBU_select_ishplotrcv_scalar(2, &ISHPLOTRCV);
					//타법인에서 출하되어 입고한 제품(ISHPLOTRCV)인 경우 중, 포장LOT으로 입고 잡았던 LOT인 경우
					//EX) 베트남 -> 음성으로 출하하여 입고.(역물류인경우)
					if (dCount > 0 && ISHPLOTRCV.PACK_LOT_ID[0] == 'V')
					{
					}
					else
					{
						// 포장 LOT을 기존 공정 LOT에 MERGE 
						merge_in = TRS.add_node(in_node, "merge_in");
						TRS.add_char(merge_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(merge_in, in_node);

						TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
						TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
						TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTS_PAK.QTY_1);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}

					//해당 포장 LOT 포장 정보 변경
					//주문지시, 라인번호, 포장여부, 포장일자 초기화
					memset(CPAKLOTSTS.PACK_ORDER_ID, ' ', sizeof(CPAKLOTSTS.PACK_ORDER_ID));
					CPAKLOTSTS.PACK_LINE_NO = 0;
					CPAKLOTSTS.PACK_FLAG = 'N';
					memset(CPAKLOTSTS.PACK_DATE, ' ', sizeof(CPAKLOTSTS.PACK_DATE));
					TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_cpaklotsts(1, &CPAKLOTSTS);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
				// 공정 LOT이 완제품 창고에 존재하지 않는 경우
				else
				{
					if (COM_isnullspace(s_new_lot_id) == MP_TRUE || memcmp(s_org_lot_id, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID)) != 0)
					{
						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);

						//GCM 공정 옵션 셋업되어있는 rule id 를 가져온다
						//LOT_CMF_14이 존재한다는 것은 PROD_IN 처리 되었다는 것
						if (COM_isnullspace(MWIPLOTSTS_ORG.LOT_CMF_14) == MP_FALSE)
						{
							DBU_init_minvlotsts(&MINVLOTSTS);
							TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
							memcpy(MINVLOTSTS.INV_LOT_ID, MWIPLOTSTS_ORG.LOT_CMF_14, sizeof(MINVLOTSTS.INV_LOT_ID));
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
							if (memcmp(MWIPOPRDEF_TO.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
							{
								TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
								TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTS_ORG.RESV_FIELD_3, strlen(MWIPLOTSTS_ORG.RESV_FIELD_3));

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
								memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID));
								DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);
								if (DB_error_code != DB_SUCCESS)
								{
									memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));
									sprintf(s_new_lot_id, MWIPLOTSTS_ORG.LOT_ID, "-01");
									sprintf(s_new_lot_id, "%.*s-01", COM_len_space(MWIPLOTSTS_ORG.LOT_ID, sizeof(MWIPLOTSTS_ORG.LOT_ID)), MWIPLOTSTS_ORG.LOT_ID);
								}
								else
								{
									memcpy(s_new_lot_id, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
								}
							}
						}

						//포장 취소로 생성된 LOT LIST
						lot_list = TRS.add_node(out_node, "LOT_LIST");
						TRS.add_string(lot_list, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));

						memcpy(s_org_lot_id, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
					}

					// MWIPLOTSTS - NEW LOT 조회
					DBU_init_mwiplotstsx(&MWIPLOTSTS_NEW);
					TRS.copy(MWIPLOTSTS_NEW.FACTORY, sizeof(MWIPLOTSTS_NEW.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPLOTSTS_NEW.LOT_ID, s_new_lot_id, sizeof(s_new_lot_id));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTS_NEW);

					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS_NEW.FACTORY), MWIPLOTSTS_NEW.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS_NEW.LOT_ID), MWIPLOTSTS_NEW.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						return MP_FALSE;
					}

					if (DB_error_code == DB_NOT_FOUND)
					{
						// 포장 LOT ID를 이용하여 NEW LOT ID로 SPLIT
						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '2');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
						TRS.add_string(split_in, "CHILD_LOT_DESC", s_new_lot_id, sizeof(s_new_lot_id));
						TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTS_PAK.QTY_1);

						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTS_PAK.QTY_1);   //split 전 모랏의 총 수량
						TRS.add_string(split_in, "LOT_CMF_7", MWIPLOTSTS_PAK.LOT_CMF_7, sizeof(MWIPLOTSTS_PAK.LOT_CMF_7));
						TRS.add_string(split_in, "LOT_CMF_8", MWIPLOTSTS_PAK.LOT_CMF_8, sizeof(MWIPLOTSTS_PAK.LOT_CMF_8));
						TRS.add_string(split_in, "LOT_CMF_9", MWIPLOTSTS_PAK.LOT_CMF_9, sizeof(MWIPLOTSTS_PAK.LOT_CMF_9));
						TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTS_PAK.RESV_FIELD_3, sizeof(MWIPLOTSTS_PAK.RESV_FIELD_3));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}
					else
					{
						// NEW 공정 LOT에 포장 LOT 병합(MERGE)
						merge_in = TRS.add_node(in_node, "merge_in");
						TRS.add_char(merge_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(merge_in, in_node);

						TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
						TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTS_NEW.LOT_ID, sizeof(MWIPLOTSTS_NEW.LOT_ID));
						TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTS_PAK.QTY_1);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}

					//해당 포장 LOT 포장 정보 변경
					//주문지시, 라인번호, 포장여부, 포장일자 초기화
					memcpy(CPAKLOTSTS.ORG_LOT_ID, MWIPLOTSTS_NEW.LOT_ID, sizeof(MWIPLOTSTS_NEW.LOT_ID));
					memset(CPAKLOTSTS.PACK_ORDER_ID, ' ', sizeof(CPAKLOTSTS.PACK_ORDER_ID));
					CPAKLOTSTS.PACK_LINE_NO = 0;
					CPAKLOTSTS.QTY = 0;
					CPAKLOTSTS.PACK_FLAG = 'N';
					memset(CPAKLOTSTS.PACK_DATE, ' ', sizeof(CPAKLOTSTS.PACK_DATE));
					TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

					//20250527 포장LOT 유지하는것땜시 계속걸려서..선택사항으로 바꿈.
					if (TRS.get_char(in_node, "PACK_LOT_DEL") == 'Y')
					{
						DBU_delete_cpaklotsts(1, &CPAKLOTSTS);
					}
					else {
						DBU_update_cpaklotsts(6, &CPAKLOTSTS);
					}


					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS_PAK.MAT_ID, sizeof(MWIPLOTSTS_PAK.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTS_PAK.MAT_VER;
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

			// 이전 ERP 실적 KEY 조회
			DBU_init_if_om_txn_lots(&IF_OM_TXN_LOTS);
			TRS.copy(IF_OM_TXN_LOTS.FACTORY, sizeof(IF_OM_TXN_LOTS.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_OM_TXN_LOTS.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));

			//ERP 실적 - IF_OM_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_2));
			TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
			TRS.add_string(erpif_in, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_double(erpif_in, "QTY", -CPAKLOTSTS.QTY);
			TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
			TRS.add_char(erpif_in, "CANCEL_FLAG", 'Y');
			TRS.add_int(erpif_in, "HEADER_ID", COM_atoi(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID)));
			TRS.add_int(erpif_in, "LINE_NUMBER", CPAKORDSTS.LINE_NO);
			TRS.add_double(erpif_in, "SRC_TRAN_ID", COM_atof(CPAKLOTSTS.CMF_4, sizeof(CPAKLOTSTS.CMF_4)));
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_OM_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_om_txns(&IF_OM_TXNS);
			TRS.copy(IF_OM_TXNS.FACTORY, sizeof(IF_OM_TXNS.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_OM_TXNS.MES_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			//ERP 실적 - IF_OM_TXN_LOTS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "OM_TXNS_ID", (double)DBU_select_if_om_txns_scalar(2, &IF_OM_TXNS));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_double(erpif_in, "QTY", -CPAKLOTSTS.QTY);
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS_PAK.LOT_ID, sizeof(MWIPLOTSTS_PAK.LOT_ID));
			TRS.add_string(erpif_in, "MES_ID", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_OM_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}

		//포장 수량 감소
		//등록 수량 감소(포장 확정 취소 -> 주문지시 매핑 해제로 인해 등록 수량도 같이 감소해야함)
		CPAKORDSTS.PACKED_QTY = CPAKORDSTS.PACKED_QTY - d_total_qty;
		CPAKORDSTS.REG_QTY = CPAKORDSTS.REG_QTY - d_total_qty;

		//해당 주문지시로 걸려있는 출하지시의 TOTAL QTY 체크(살아있는 출하 지시 기준)
		DBU_init_cshporddtl(&CSHPORDDTL_COUNT);
		TRS.copy(CSHPORDDTL_COUNT.FACTORY, sizeof(CSHPORDDTL_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CSHPORDDTL_COUNT.PACK_ORDER_ID, sizeof(CSHPORDDTL_COUNT.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
		CSHPORDDTL_COUNT.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
		d_ship_reg_qty = DBU_select_cshporddtl_scalar(4, &CSHPORDDTL_COUNT);

		//해당 주문지시로 걸려있는 출하 가능한 포장 LOT 수량
		DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
		TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS_COUNT.PACK_ORDER_ID, sizeof(CPAKLOTSTS_COUNT.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
		CPAKLOTSTS_COUNT.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
		d_pack_reg_qty = DBU_select_cpaklotsts_scalar(28, &CPAKLOTSTS_COUNT);

		//취소 후 출하지시의 수량보다 수량이 작아지면 안됨.
		if (d_pack_reg_qty < d_ship_reg_qty)
		{
			// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "CSHPORDDTL SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CSHPORDDTL_COUNT.PACK_ORDER_ID), CSHPORDDTL_COUNT.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CSHPORDDTL_COUNT.PACK_LINE_NO);
			TRS.add_fieldmsg(out_node, "CANCEL_QTY", MP_DBL, d_total_qty);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_QTY", MP_DBL, d_ship_reg_qty);
			TRS.add_fieldmsg(out_node, "OK_CANCEL_QTY", MP_DBL, d_total_qty + d_pack_reg_qty - d_ship_reg_qty);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKORDSTS - 주문 수량과 포장완료 수량이 같으면 상태 PACKED
		if (CPAKORDSTS.PACKED_QTY < CPAKORDSTS.QTY)
		{
			memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
		}

		TRS.copy(CPAKORDSTS.UPDATE_USER_ID, sizeof(CPAKORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CPAKORDSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_cpakordsts(1, &CPAKORDSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKORDSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
	CUS_SHP_Confirm_Pack_Order_Validation()
		- Validation Check sub function of "CUS_SHP_CONFIRM_PACK_ORDER" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_SHP_CONFIRM_PACK_ORDER_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Confirm_Pack_Order_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
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
CUS_SHP_Confirm_Pack_Order_Before_Transaction()
- Main sub function of "CUS_SHP_CONFIRM_PACK_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Confirm_Pack_Order_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Confirm_Pack_Order_After_Transaction()
- Main sub function of "CUS_SHP_CONFIRM_PACK_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Confirm_Pack_Order_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}