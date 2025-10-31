/*******************************************************************************

	System      : MESplus
	Module      : CUS_SHP
	File Name   : CUS_SHP_create_pack_lot.c
	Description : Create Pack Lot

	MES Version : 5.2.0

	Function List
		- CUS_SHP_Create_Pack_Lot()
			+ Create Pack Lot
		- CUS_SHP_CREATE_PACK_LOT()
			+ Main Sub function of "CUS_SHP_Create_Pack_Lot"

			+ (called by "CUS_SHP_Create_Pack_Lot")
		- CUS_SHP_Create_Pack_Lot_Validation()
			+ Validation Check sub function of "CUS_SHP_CREATE_PACK_LOT" function
			+ (called by "CUS_SHP_CREATE_PACK_LOT")

	Detail Description
		-

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2020/08/26  Miracom         Create

	Copyright(C) 1998-2020 Miracom,Inc.
	All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"
#include "../CUS_COM/CUS_defines.h"

int CUS_SHP_CREATE_PACK_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Create_Pack_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_CREATE_PACK_LOT_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Create_Pack_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_SHP_Create_Pack_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
	CUS_SHP_Create_Pack_Lot()
		- Create Pack Lot
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- CUS_SHP_Create_Pack_Lot_In_Tag *CUS_SHP_Create_Pack_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Lot(TRSNode* in_node,
	TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_SHP_CREATE_PACK_LOT_MAIN(s_msg_code, in_node, out_node);

	
	
	COM_out_msg_log_write(s_msg_code, "CUS_SHP_CREATE_PACK_LOT", out_node);

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
CUS_SHP_CREATE_PACK_LOT_MAIN()
- Main sub function of "CUS_SHP_CREATE_PACK_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_CREATE_PACK_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CREATE_PACK_LOT_MAIN(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct ISHPLOTRCV_TAG ISHPLOTRCV;

	TRSNode* create_in_node;
	TRSNode** pack_lot_list;
	TRSNode* lot_list;
	int i;
	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	char pack_lot_id[26];
	struct work_date_tag work_date;
	char s_factory[10];
	double dCount = 0;

	LOG_head("CUS_SHP_CREATE_PACK_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	/*' Validation Check */
	if (CUS_SHP_Create_Pack_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "PACK_ORDER_ID", TRS.get_string(in_node, "PACK_ORDER_ID"));
	TRS.add_int(create_in_node, "LINE_NO", TRS.get_int(in_node, "LINE_NO"));

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		memset(pack_lot_id, ' ', sizeof(pack_lot_id));

		lot_list = TRS.add_node(create_in_node, "PACK_LOT_LIST");
		TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(pack_lot_list[i], "ORG_LOT_ID"));

		// MWIPLOTSTS - 공정 LOT ID 정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
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

		if (COM_isnullspace(TRS.get_string(pack_lot_list[i], "PACK_LOT_ID")) == MP_FALSE)
		{
			memcpy(pack_lot_id, TRS.get_string(pack_lot_list[i], "PACK_LOT_ID"), strlen(TRS.get_string(pack_lot_list[i], "PACK_LOT_ID")));
		}
		else
		{
			dCount = 0;

			DBU_init_ishplotrcv(&ISHPLOTRCV);
			TRS.copy(ISHPLOTRCV.FACTORY, sizeof(ISHPLOTRCV.FACTORY), in_node, IN_FACTORY);
			TRS.copy(ISHPLOTRCV.PACK_LOT_ID, sizeof(ISHPLOTRCV.PACK_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");

			dCount = DBU_select_ishplotrcv_scalar(2, &ISHPLOTRCV);
			//타법인에서 출하되어 입고한 제품(ISHPLOTRCV)인 경우 중, 포장LOT으로 입고 잡았던 LOT인 경우
			//EX) 베트남 -> 음성으로 출하하여 입고.(역물류인경우)
			//ORG_LOT_ID로 포장LOT을 만든다.
			if (dCount > 0 && ISHPLOTRCV.PACK_LOT_ID[0] == 'V')
			{
				memcpy(pack_lot_id, TRS.get_string(pack_lot_list[i], "ORG_LOT_ID"), strlen(TRS.get_string(pack_lot_list[i], "ORG_LOT_ID")));
			}
			else
			{

				gen_in_node = TRS.add_node(in_node, "gen_in_node");
				//LOT ID 발번            
				CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...

				if (memcmp(TRS.get_string(in_node, "AREA_ID"), MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
				{
					if (COM_isnullspace(MWIPLOTSTS.LOT_CMF_14) == MP_FALSE)
					{
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_SHIPPING_LOT_ID));
						TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
					}
					else
					{
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
						TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTS.RESV_FIELD_3, strlen(MWIPLOTSTS.RESV_FIELD_3));
					}
				}
				else
				{
					if (memcmp(TRS.get_string(in_node, "AREA_ID"), gs_area_ctm, sizeof(gs_area_ctm)) == 0)
					{
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_CTM_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_CTM_SHIPPING_LOT_ID));
						TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
					}
					else
					{
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_SHIPPING_LOT_ID));
						TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
					}

				}

				TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

				cmn_out = TRS.create_node("cmn_out");
				if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				memcpy(pack_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
				TRS.free_node(cmn_out);
			}
		}

		TRS.add_string(lot_list, "PACK_LOT_ID", pack_lot_id, sizeof(pack_lot_id));
		TRS.add_double(lot_list, "QTY", TRS.get_double(pack_lot_list[i], "QTY"));
		TRS.add_nstring(lot_list, "COATING_PERCENT", TRS.get_string(pack_lot_list[i], "COATING_PERCENT"));
	}

	if (CUS_SHP_Create_Pack_Lot_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_CREATE_PACK_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Create_Pack_Lot_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
	CUS_SHP_CREATE_PACK_LOT()
		- Main sub function of "CUS_SHP_Create_Pack_Lot" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_SHP_CREATE_PACK_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CREATE_PACK_LOT(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)

{
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_INSP;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_CUS;
	struct CWIPGRTBLD_TAG CWIPGRTBLD;

	char s_sys_time[14];

	int i;
	double d_qty = 0;
	double d_total_qty = 0;
	double d_lot_qty = 0;
	int i_insp_move_flag = 0;
	int i_Customer_move_flag = 0;

	TRSNode** pack_lot_list;
	TRSNode* lot_list;


	memset(s_sys_time, ' ', sizeof(s_sys_time));

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

	// 포장 지시 상태 체크
	// 생성, 수정, 삭제는 WAIT 상태에서만 가능
	// 확정 -> PACKED로 변경
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

	//AREA 정보 조회
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
	memcpy(MGCMTBLDAT.KEY_1, CPAKORDSTS.AREA_ID, sizeof(CPAKORDSTS.AREA_ID));
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

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		// MWIPLOTSTS - 공정 LOT ID 정보 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
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



		DBU_init_mgcmtbldat(&MGCMTBLDAT_INSP);
		TRS.copy(MGCMTBLDAT_INSP.FACTORY, sizeof(MGCMTBLDAT_INSP.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_INSP.TABLE_NAME, MP_GCM_INSP_JUDGE_LIST, strlen(MP_GCM_INSP_JUDGE_LIST));
		memcpy(MGCMTBLDAT_INSP.KEY_1, MWIPLOTSTS.LOT_CMF_11, sizeof(MWIPLOTSTS.LOT_CMF_11));

		i_insp_move_flag = (int)DBU_select_mgcmtbldat_scalar(4, &MGCMTBLDAT_INSP);
		if (i_insp_move_flag == 0)
		{
			DBU_init_mgcmtbldat(&MGCMTBLDAT_CUS);
			TRS.copy(MGCMTBLDAT_CUS.FACTORY, sizeof(MGCMTBLDAT_CUS.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_CUS.TABLE_NAME, MP_GCM_C_SHP_ALL_SHIP_CUS, strlen(MP_GCM_C_SHP_ALL_SHIP_CUS));
			memcpy(MGCMTBLDAT_CUS.KEY_1, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));

			i_Customer_move_flag = (int)DBU_select_mgcmtbldat_scalar(2, &MGCMTBLDAT_CUS);

			if (i_Customer_move_flag == 0)
			{
				//검사무시하고 출하가는하도록 하는판정 LOT_CMF_19
				if (MWIPLOTSTS.LOT_CMF_19[0] != '\0')
				{
					//WIP-0654 : 해당 Lot의 판정 값은 완제품 창고로 이동이 불가합니다.
					strcpy(s_msg_code, "WIP-0654");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
					TRS.add_fieldmsg(out_node, "JUDGE", MP_STR, sizeof(MWIPLOTSTS.LOT_CMF_11), MWIPLOTSTS.LOT_CMF_11);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

		}


		// 공정 LOT 잠금 여부 체크
		if (MWIPLOTSTS.HOLD_FLAG == 'Y')
		{
			// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
			strcpy(s_msg_code, "WIP-0059");
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

		// 공정 LOT 삭제 여부 체크
		if (MWIPLOTSTS.LOT_DEL_FLAG == 'Y')
		{
			// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
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

		//블랜딩 작업지시 투입지시가 되어 있으면 포장을 할 수 없도록 한다.
		if (memcmp(CPAKORDSTS.AREA_ID, gs_area_grt, sizeof(gs_area_grt)) == MP_FALSE)
		{
			DBU_init_cwipgrtbld(&CWIPGRTBLD);
			memcpy(CWIPGRTBLD.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
			memcpy(CWIPGRTBLD.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

			if (DBU_select_cwipgrtbld_scalar(2, &CWIPGRTBLD) > 0)
			{
				//WIP-0691 : 블랜딩 작업지시에 투입된 LOT은 포장을 할 수 없습니다.
				strcpy(s_msg_code, "WIP-0691");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
		MWIPMATDEF.MAT_VER = MWIPLOTSTS.MAT_VER;
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

		// CPAKLOTSTS - 포장 지시, 라인번호에 해당하는 토탈 수량 체크
		/*DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
		TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS_COUNT.PACK_ORDER_ID, sizeof(CPAKLOTSTS_COUNT.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
		CPAKLOTSTS_COUNT.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
		d_qty = (int)DBU_select_cpaklotsts_scalar(2, &CPAKLOTSTS_COUNT);*/

		if (CPAKORDSTS.QTY < CPAKORDSTS.REG_QTY + TRS.get_double(pack_lot_list[i], "QTY"))
		{
			// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.PACK_ORDER_ID), CPAKLOTSTS_COUNT.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS_COUNT.PACK_LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKLOTSTS - 포장 지시, 라인번호의 공정 LOT ID 수량 체크
		DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
		TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS_COUNT.ORG_LOT_ID, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
		d_qty = (int)DBU_select_cpaklotsts_scalar(3, &CPAKLOTSTS_COUNT);

		if (MGCMTBLDAT.DATA_4[0] == 'Y')
		{
			if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
			{
				if (COM_isspace(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6)) == MP_FALSE)
				{
					d_lot_qty = MWIPLOTSTS.QTY_1 / COM_atof(MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6));
					d_lot_qty = COM_dbl_round(d_lot_qty, 5, 'U');
				}
				else
				{
					d_lot_qty = MWIPLOTSTS.QTY_1;
				}
			}
			else
			{
				d_lot_qty = MWIPLOTSTS.QTY_1;
			}
		}
		else
		{
			d_lot_qty = MWIPLOTSTS.QTY_1;
		}

		if (d_lot_qty < d_qty + TRS.get_double(pack_lot_list[i], "QTY"))
		{
			// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
			strcpy(s_msg_code, "INV-0021");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.PACK_ORDER_ID), CPAKLOTSTS_COUNT.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS_COUNT.PACK_LINE_NO);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), CPAKLOTSTS_COUNT.ORG_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//트랜잭션 포장 수량 합계
		d_total_qty += TRS.get_double(pack_lot_list[i], "QTY");

		//포장 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
		DBU_select_cpaklotsts(1, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//포장 정보가 존재하지 않는다면 생성 & 주문지시 매핑
		if (DB_error_code == DB_NOT_FOUND)
		{
			memcpy(CPAKLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			CPAKLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			CPAKLOTSTS.QTY = TRS.get_double(pack_lot_list[i], "QTY");

			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5)) == MP_FALSE)
					{
						memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5));
					}
					else
					{
						memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					}
				}
				else
				{
					memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				}
			}
			else
			{
				memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			}

			CPAKLOTSTS.PACK_FLAG = 'N';
			memcpy(CPAKLOTSTS.PACK_DATE, s_sys_time, sizeof(s_sys_time));
			memcpy(CPAKLOTSTS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			CPAKLOTSTS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
			CPAKLOTSTS.SHIP_FLAG = 'N';
			memset(CPAKLOTSTS.SHIP_DATE, ' ', sizeof(CPAKLOTSTS.SHIP_DATE));
			memset(CPAKLOTSTS.SHIP_ORDER_ID, ' ', sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			CPAKLOTSTS.SHIP_ORDER_SEQ = 0;
			CPAKLOTSTS.RET_FLAG = 'N';
			CPAKLOTSTS.RETURNED_QTY = 0;
			memset(CPAKLOTSTS.BOX_ID_1, ' ', sizeof(CPAKLOTSTS.BOX_ID_1));
			memset(CPAKLOTSTS.BOX_ID_2, ' ', sizeof(CPAKLOTSTS.BOX_ID_2));
			memset(CPAKLOTSTS.BOX_ID_3, ' ', sizeof(CPAKLOTSTS.BOX_ID_3));
			TRS.copy(CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1), pack_lot_list[i], "COATING_PERCENT");
			memcpy(CPAKLOTSTS.CMF_2, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));	//포장 정보를 최초에 생성시켰던 LOT의 정보를 저장, 출하 성적서 뽑아줘야됨.
			memset(CPAKLOTSTS.CMF_3, ' ', sizeof(CPAKLOTSTS.CMF_3));
			memset(CPAKLOTSTS.CMF_4, ' ', sizeof(CPAKLOTSTS.CMF_4));
			memcpy(CPAKLOTSTS.CMF_5, CPAKORDSTS.CMF_1, sizeof(CPAKORDSTS.CMF_1));	//ERP 포장 지시 번호
			memset(CPAKLOTSTS.CMF_6, ' ', sizeof(CPAKLOTSTS.CMF_6));
			memset(CPAKLOTSTS.CMF_7, ' ', sizeof(CPAKLOTSTS.CMF_7));
			memset(CPAKLOTSTS.CMF_8, ' ', sizeof(CPAKLOTSTS.CMF_8));
			memset(CPAKLOTSTS.CMF_9, ' ', sizeof(CPAKLOTSTS.CMF_9));
			memset(CPAKLOTSTS.CMF_10, ' ', sizeof(CPAKLOTSTS.CMF_10));

			TRS.copy(CPAKLOTSTS.CREATE_USER_ID, sizeof(CPAKLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			// CPAKLOTSTS - 포장 LOT 정보 생성
			DBU_insert_cpaklotsts(&CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
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
			if (COM_isspace(CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID)) == MP_FALSE)
			{
				// WIP-0620 : 해당 Lot은 이미 포장되어 있습니다.
				strcpy(s_msg_code, "WIP-0620");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			CPAKLOTSTS.QTY = TRS.get_double(pack_lot_list[i], "QTY");
			CPAKLOTSTS.PACK_FLAG = 'N';
			memcpy(CPAKLOTSTS.PACK_DATE, s_sys_time, sizeof(CPAKLOTSTS.PACK_DATE));
			memcpy(CPAKLOTSTS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			memcpy(CPAKLOTSTS.MAT_ID, CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
			CPAKLOTSTS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
			CPAKLOTSTS.SHIP_FLAG = 'N';
			memset(CPAKLOTSTS.SHIP_DATE, ' ', sizeof(CPAKLOTSTS.SHIP_DATE));
			memset(CPAKLOTSTS.SHIP_ORDER_ID, ' ', sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			CPAKLOTSTS.SHIP_ORDER_SEQ = 0;
			CPAKLOTSTS.RET_FLAG = 'N';
			CPAKLOTSTS.RETURNED_QTY = 0;
			memset(CPAKLOTSTS.BOX_ID_1, ' ', sizeof(CPAKLOTSTS.BOX_ID_1));
			memset(CPAKLOTSTS.BOX_ID_2, ' ', sizeof(CPAKLOTSTS.BOX_ID_2));
			memset(CPAKLOTSTS.BOX_ID_3, ' ', sizeof(CPAKLOTSTS.BOX_ID_3));
			TRS.copy(CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1), pack_lot_list[i], "COATING_PERCENT");
			memcpy(CPAKLOTSTS.CMF_5, CPAKORDSTS.CMF_1, sizeof(CPAKORDSTS.CMF_1));	//ERP 포장 지시 번호

			TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			// CPAKLOTSTS - 포장 LOT 정보 업데이트
			DBU_update_cpaklotsts(1, &CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//포장 LOT 
		lot_list = TRS.add_node(out_node, "PACK_LOT_LIST");
		TRS.add_string(lot_list, "ORG_LOT_ID", CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
		TRS.add_string(lot_list, "PACK_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
	}

	// 포장 등록 수량 증가
	CPAKORDSTS.REG_QTY = CPAKORDSTS.REG_QTY + d_total_qty;
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

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
	CUS_SHP_Create_Pack_Lot_Validation()
		- Validation Check sub function of "CUS_SHP_CREATE_PACK_LOT" function
	Return Value
		- int : 1 (MP_TRUE) / 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- CUS_SHP_CREATE_PACK_LOT_IN_TAG *In_Lot_In : Input Message structure
		- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
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
CUS_SHP_Create_Pack_Lot_Before_Transaction()
- Main sub function of "CUS_SHP_CREATE_PACK_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Lot_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	// 포장 LOT 정보 삭제
	/*if (CUS_SHP_DELETE_PACK_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}*/
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Create_Pack_Lot_After_Transaction()
- Main sub function of "CUS_SHP_CREATE_PACK_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Lot_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	return MP_TRUE;
}