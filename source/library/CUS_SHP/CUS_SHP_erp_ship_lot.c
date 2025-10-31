/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_SHP_check_ship_lot.c
Description : 공정 LOT - 출하 LOT 관계 체크

MES Version : 4.0.0

Function List
- CUS_SHP_Check_Ship_Lot()
+ Check Ship Lot
- CUS_SHP_CHECK_SHIP_LOT()
+ Main sub function of "CUS_SHP_Check_Ship_Lot" function
+ Ship Lot definition
- CUS_SHP_Check_Ship_Lot_Validation()
+ Validation Check sub function of "CUS_SHP_CHECK_SHIP_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/27  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_ERP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_ERP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_Check_Ship_Lot()
- Check Ship Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_ERP_Ship_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_SHP_ERP_SHIP_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_SHP_ERP_SHIP_LOT", out_node);

	if (i_ret == MP_TRUE)
	{
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
		DB_commit();
	}
	else
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_ERP_SHIP_LOT()
- Main sub function of "CUS_SHP_Check_Ship_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_ERP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CSHPORDMST_TAG CSHPORDMST;
	struct CSHPORDDTL_TAG CSHPORDDTL;
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct IF_OM_SHIP_HEADERS_TAG IF_OM_SHIP_HEADERS;
	struct IF_OM_SHIP_LINES_TAG IF_OM_SHIP_LINES;

	TRSNode *erpif_in;
	TRSNode *cmn_out;

	int send_flag = 0;
	int dtl_send_flag = 0;

	LOG_head("CUS_SHP_ERP_Ship_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_SHP_ERP_Ship_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 출하 지시 마스터 정보 조회
	DBU_init_cshpordmst(&CSHPORDMST);
	TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
	DBU_select_cshpordmst(1, &CSHPORDMST);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CSHPORDMST SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSHPORDMST.FACTORY), CSHPORDMST.FACTORY);
		TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	DBU_init_cshporddtl(&CSHPORDDTL);
	TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
	memcpy(CSHPORDDTL.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
	DBU_open_cshporddtl(2, &CSHPORDDTL);

	if (DB_error_code != DB_SUCCESS)
	{
		//INV-0043 : 검색하신 정보는 존재하지 않습니다.
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "CSHPORDDTL OPEN", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	while (1)
	{
		DBU_fetch_cshporddtl(2, &CSHPORDDTL);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_cshporddtl(2);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CSHPORDDTL OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			DBU_close_cshporddtl(2);
			return MP_FALSE;
		}

		dtl_send_flag = 0;


		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CPAKLOTSTS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
		CPAKLOTSTS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
		DBU_open_cpaklotsts(12, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS OPEN", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			// 20.12.21 minjae.go
			DBU_close_cshporddtl(2);
			//

			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cpaklotsts(12, &CPAKLOTSTS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cpaklotsts(12);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS FETCH", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cpaklotsts(12);

				// 20.12.21 minjae.go
				DBU_close_cshporddtl(2);
				//

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			// MWIPLOTSTS - 포장 LOT 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTS.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
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

				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//

				return MP_FALSE;
			}

			// 출하 창고 정보 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
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

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//

				return MP_FALSE;
			}

			//TO AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//

				return MP_FALSE;
			}

			// CPAKORDSTS - 포장 지시 정보 조회
			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
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

				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//

				return MP_FALSE;
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTS.MAT_VER;
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

				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//

				return MP_FALSE;
			}

			if (send_flag == 0)
			{
				//ERP 실적 - IF_OM_SHIP_HEADERS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "DELIVERY_ID", COM_atoi(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID)));
				TRS.add_string(erpif_in, "MES_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_OM_SHIP_HEADERS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					// 20.12.21 minjae.go
					DBU_close_cpaklotsts(12);
					DBU_close_cshporddtl(2);
					//
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				send_flag = 1;
			}

			if (dtl_send_flag == 0)
			{
				DBU_init_if_om_ship_headers(&IF_OM_SHIP_HEADERS);
				TRS.copy(IF_OM_SHIP_HEADERS.FACTORY, sizeof(IF_OM_SHIP_HEADERS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_OM_SHIP_HEADERS.MES_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
				IF_OM_SHIP_HEADERS.DELIVERY_ID = COM_atoi(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));

				DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
				TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
				memcpy(CPAKLOTSTS_COUNT.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
				CPAKLOTSTS_COUNT.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;

				//ERP 실적 - IF_OM_SHIP_LINES
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "SHIP_HEADER_ID", DBU_select_if_om_ship_headers_scalar(2, &IF_OM_SHIP_HEADERS));
				TRS.add_int(erpif_in, "DELIVERY_ID", COM_atoi(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID)));
				TRS.add_int(erpif_in, "DELIVERY_DTL_ID", CSHPORDDTL.SHIPPING_LINE_ID);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_double(erpif_in, "QTY", DBU_select_cpaklotsts_scalar(26, &CPAKLOTSTS_COUNT));
				TRS.add_string(erpif_in, "UNIT", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
				TRS.add_string(erpif_in, "SHIP_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_string(erpif_in, "MES_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_OM_SHIP_LINES(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					// 20.12.21 minjae.go
					DBU_close_cpaklotsts(12);
					DBU_close_cshporddtl(2);
					//
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				dtl_send_flag = 1;
			}

			DBU_init_if_om_ship_lines(&IF_OM_SHIP_LINES);
			TRS.copy(IF_OM_SHIP_LINES.FACTORY, sizeof(IF_OM_SHIP_LINES.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_OM_SHIP_LINES.MES_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));

			//ERP 실적 - IF_OM_SHIP_LINE_LOTS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "SHIP_HEADER_ID", DBU_select_if_om_ship_headers_scalar(2, &IF_OM_SHIP_HEADERS));
			TRS.add_double(erpif_in, "SHIP_LINE_ID", DBU_select_if_om_ship_lines_scalar(2, &IF_OM_SHIP_LINES));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_double(erpif_in, "QTY", CPAKLOTSTS.QTY);
			TRS.add_string(erpif_in, "MES_ID", CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_OM_SHIP_LINE_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				// 20.12.21 minjae.go
				DBU_close_cpaklotsts(12);
				DBU_close_cshporddtl(2);
				//
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}
	

	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Check_Ship_Lot_Validation()
- Validation Check sub function of "CUS_SHP_CHECK_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_ERP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	/* ProcStep Validation */
	/*if (COM_service_validation(s_msg_code,
	in_node,
	out_node,
	TRS.get_procstep(in_node),
	"1") == MP_FALSE)
	{
	return MP_FALSE;
	}*/

	return MP_TRUE;
}
