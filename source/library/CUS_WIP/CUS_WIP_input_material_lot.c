/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_input_material_lot.c
Description : 자재 투입

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/29  Miracom        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Input_Material_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_INPUT_MATERIAL_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Input_Material_Lot()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Input_Material_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Input_Material_Lot", out_node);
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
CUS_WIP_INPUT_MATERIAL_LOT()
- Main sub function of "CUS_WIP_Input_Material_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_INPUT_MATERIAL_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	/* TABLE */
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	// 공정 LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_M;	// 공정 LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_ISS;	// 공정 LOT 마스터
	struct MINVLOTSTS_TAG MINVLOTSTS;	// 자재 LOT 마스터
	struct MWIPOPRDEF_TAG MWIPOPRDEF;	// 공정 마스터 테이블
	struct MWIPOPRDEF_TAG MWIPOPRDEF_ISS;	// 공정 마스터 테이블
	struct MWIPORDSTS_TAG MWIPORDSTS;	// 작업지시 마스터 테이블
	struct CWIPORDBOM_TAG CWIPORDBOM;	// 작업지시 BOM 테이블
	struct CWIPINVLDM_TAG CWIPINVLDM;	// 변경 자재 LOAD 테이블
	struct MINVLOTISS_TAG MINVLOTISS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CWIPLOTTRC_TAG CWIPLOTTRC;
	struct CWIPERPOPR_TAG CWIPERPOPR;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SUB_AREA;
	struct MWIPMATDEF_TAG MWIPMATDEF_BOM;

	struct CBASTXNDEF_TAG CBASTXNDEF_ETC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TYPE;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MINVETCLOT_TAG MINVETCLOT;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;

	TRSNode** list_tbl;
	TRSNode* load_in;
	TRSNode* inv_list;
	TRSNode* cmn_out;
	TRSNode* cv_in;
	TRSNode* inv_if;

	char s_lot_id[26];
	int iStep = 0;
	int iItemCount = 0;
	int i = 0;
	int i_seq = 0;
	int icheck = MP_FALSE;
	int iBomcheck = MP_FALSE;
	double d_ifseq = 0;
	
	int iWipInvcheck = MP_FALSE;

	char s_factory[10];
	struct work_date_tag work_date;
	char s_yyyymm[6];



	char c_Iss_cmf4[30];
	char c_etc_tranSrc[30];
	char c_if_seq[30];
	int i_LotType = 0;

	// LOG
	LOG_head("CUS_WIP_Input_Material_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	// VALIDATION CHECK
	if (CUS_WIP_Input_Material_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(s_lot_id, ' ', sizeof(s_lot_id));
	memset(&work_date, ' ', sizeof(work_date));
	memset(s_yyyymm, ' ', sizeof(s_yyyymm));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	Get_shift(s_factory, &work_date);

	// STEP 1 
	// 자재 Unload 처리
	if (TRS.get_procstep(in_node) == '1')
	{

		DBU_init_mwiplotstsx(&MWIPLOTSTSX);

		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

		//20220418 이거 문제안될것으로 보임 삭제
		/*

		if(TRS.get_char(in_node, "REL_LEVEL") == '1')  // LOT 인경우
		{
			if(TRS.mem_cmp(in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) == 0)
			{
				if(memcmp(MWIPLOTSTSX.LOT_STATUS, MP_LOT_STATUS_PROC, sizeof(MWIPLOTSTSX.LOT_STATUS)) == 0)
				{
					// WIP-0631 : 해당 자재는 착공 중입니다. 자재는 투입 해제 할 수 없습니다.
					strcpy(s_msg_code, "WIP-0631");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT 1", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
					TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTSX.LOT_STATUS), MWIPLOTSTSX.LOT_STATUS);

					return MP_FALSE;
				}
			}
		}
		else if(TRS.get_char(in_node, "REL_LEVEL") == '2') // Work Orderidmesr

		{
			if (TRS.mem_cmp(in_node, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) == 0)
			{
				if (TRS.mem_cmp(in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) == 0)
				{
					if (memcmp(MWIPLOTSTSX.LOT_STATUS, MP_LOT_STATUS_PROC, sizeof(MWIPLOTSTSX.LOT_STATUS)) == 0)
					{
						// WIP-0631 : 해당 자재는 착공 중입니다. 자재는 투입 해제 할 수 없습니다.
						strcpy(s_msg_code, "WIP-0631");
						TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT 1", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
						TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
						TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTSX.LOT_STATUS), MWIPLOTSTSX.LOT_STATUS);

						return MP_FALSE;
					}
				}
			}
		}
		*/

		if (TRS.str_cmp(in_node, "LOT_TYPE", MP_LOT_TYPE_INV) == 0)
		{
			load_in = TRS.add_node(in_node, "load_in");
			TRS.add_char(load_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(load_in, in_node);

			inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
			TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(in_node, "INV_LOT_ID"));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_INV_UNLOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.free_node(cmn_out);
		}

		DBU_init_cwipinvldm(&CWIPINVLDM);
		TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
		CWIPINVLDM.REL_LEVEL = TRS.get_char(in_node, "REL_LEVEL");
		TRS.copy(CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), in_node, "INV_LOT_ID");
		TRS.copy(CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER), in_node, "OPER");
		TRS.copy(CWIPINVLDM.ORDER_ID, sizeof(CWIPINVLDM.ORDER_ID), in_node, "ORDER_ID");
		TRS.copy(CWIPINVLDM.RES_ID, sizeof(CWIPINVLDM.RES_ID), in_node, "RES_ID");
		TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.LOT_ID), in_node, "LOT_ID");

		DBU_delete_cwipinvldm(1, &CWIPINVLDM);
		if (DB_error_code != DB_NOT_FOUND && DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CWIPINVLDM Delete 1", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
			TRS.add_fieldmsg(out_node, "REL_LEVEL", DT_CHAR, CWIPINVLDM.REL_LEVEL);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
			TRS.add_fieldmsg(out_node, "ORDER_ID", DT_STRING, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
			TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
	}
	// 자재 투입처리 '2' : 작업지시별, '3' : 공정별, '4' : lot별, 
	else if (TRS.get_procstep(in_node) == '2' || TRS.get_procstep(in_node) == '3' || TRS.get_procstep(in_node) == '4')
	{
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

		//창고 고정은 자재를 투입처리 할 수 없다. 
		if (MWIPOPRDEF.INV_FLAG == 'Y')
		{
			//WIP-0629 : 해당 공정은 자재 투입 공정이 아닙니다.
			strcpy(s_msg_code, "WIP-0629");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//경우에 따라선느 검사 공정 투입된되는 경우 있을수 있음(20220613 송용원)
		/*
		if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
			memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
		{
			//WIP-0629 : 해당 공정은 자재 투입 공정이 아닙니다.
			strcpy(s_msg_code, "WIP-0629");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/

		if (MWIPOPRDEF.OPER_CMF_1[0] == ' ')
		{
			//WIP-0652 : ERP 공정과 맵핑되어 있지 않은 공정은 자재를 투입할 수 없습니다.
			strcpy(s_msg_code, "WIP-0652");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//자재 투입처리(작업지시별)
		if (TRS.get_procstep(in_node) == '2')
		{
			//REL_LEVEL = 2
			iStep = 3;

			//작업지시 체크
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
		//자재 투입처리(공정별)
		else if (TRS.get_procstep(in_node) == '3')
		{
			//REL_LEVEL = 3
			iStep = 2;
		}
		//lot별 자재 투입처리
		else if (TRS.get_procstep(in_node) == '4')
		{
			//REL_LEVEL = 1
			iStep = 4;

			//생성된 LOT ID 또는 Client에서 받은 LOT ID에 대한 정보를 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_M);
			TRS.copy(MWIPLOTSTSX_M.LOT_ID, sizeof(MWIPLOTSTSX_M.LOT_ID), in_node, "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_M);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_M.FACTORY), MWIPLOTSTSX_M.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_M.LOT_ID), MWIPLOTSTSX_M.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		list_tbl = TRS.get_list(in_node, "LIST_TBL");
		iItemCount = TRS.get_item_count(in_node, "LIST_TBL");

		//기존 load된 리스트 중에 load List lot이 없으면 자재 unload처리를 해준다.
		DBU_init_cwipinvldm(&CWIPINVLDM);
		TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
		CWIPINVLDM.REL_LEVEL = TRS.get_char(in_node, "REL_LEVEL");
		TRS.copy(CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER), in_node, "OPER");
		TRS.copy(CWIPINVLDM.ORDER_ID, sizeof(CWIPINVLDM.ORDER_ID), in_node, "ORDER_ID");
		TRS.copy(CWIPINVLDM.RES_ID, sizeof(CWIPINVLDM.RES_ID), in_node, "RES_ID");
		TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.LOT_ID), in_node, "LOT_ID");

		DBU_open_cwipinvldm(iStep, &CWIPINVLDM);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
			strcpy(s_msg_code, "WIP-0585");
			TRS.add_fieldmsg(out_node, "CWIPINVLDM OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		while (1)
		{
			DBU_fetch_cwipinvldm(iStep, &CWIPINVLDM);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwipinvldm(iStep);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "CWIPINVLDM FATCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cwipinvldm(iStep);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (iItemCount > 0)
			{
				if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == 0)
				{
					for (i = 0; i < iItemCount; i++)
					{
						if (memcmp(CWIPINVLDM.INV_LOT_ID, TRS.get_string(list_tbl[i], "LOT_ID"), strlen(TRS.get_string(list_tbl[i], "LOT_ID"))) == MP_FALSE)
						{
							icheck = MP_TRUE;
							break;
						}
					}
				}
			}
			else
			{
				icheck = MP_FALSE;
			}

			if (icheck == MP_FALSE)
			{
				if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == 0)
				{
					//unload 트랜젝션 부분 수정 할 것
					load_in = TRS.add_node(in_node, "load_in");
					TRS.add_char(load_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(load_in, in_node);


					TRS.add_nstring(load_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_char(load_in, "REL_LEVEL", TRS.get_char(in_node, "REL_LEVEL"));

					inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
					TRS.add_string(inv_list, "INV_LOT_ID", CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_UNLOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}
			}

			icheck = MP_FALSE;
		}

		//작업지시, 공정에 LOAD된 자재 리스트를 지운다.
		DBU_init_cwipinvldm(&CWIPINVLDM);
		TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
		CWIPINVLDM.REL_LEVEL = TRS.get_char(in_node, "REL_LEVEL");
		TRS.copy(CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER), in_node, "OPER");
		TRS.copy(CWIPINVLDM.ORDER_ID, sizeof(CWIPINVLDM.ORDER_ID), in_node, "ORDER_ID");
		TRS.copy(CWIPINVLDM.RES_ID, sizeof(CWIPINVLDM.RES_ID), in_node, "RES_ID");
		TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.LOT_ID), in_node, "LOT_ID");

		DBU_delete_cwipinvldm(iStep, &CWIPINVLDM);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		for (i = 0; i < iItemCount; i++)
		{

			if (CWIPINVLDM.REL_LEVEL == '2')
			{
				//BOM상에 없는 자재도 투입 가능.
				//작업지시 BOM정보에 존재하는 MAT ID 인지 확인한다.

				DBU_init_cwipordbom(&CWIPORDBOM);
				TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
				TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), in_node, "OPER");
				TRS.copy(CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID), list_tbl[i], "MAT_ID");
				CWIPORDBOM.MAT_VER = 1;
				DBU_select_cwipordbom(1, &CWIPORDBOM);
				if (DB_error_code != DB_SUCCESS)
				{



					DBU_init_cwipordbom(&CWIPORDBOM);
					memcpy(CWIPORDBOM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
					memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
					TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), in_node, "OPER");
					TRS.copy(CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID), list_tbl[i], "MAT_ID");
					CWIPORDBOM.MAT_VER = 1;
					CWIPORDBOM.UNIT_QTY = TRS.get_double(list_tbl[i], "BOM_QTY");
					CWIPORDBOM.QTY = TRS.get_double(list_tbl[i], "QTY");
					TRS.copy(CWIPORDBOM.OUT_OPER, sizeof(CWIPORDBOM.OUT_OPER), list_tbl[i], "OUT_OPER");

					//MAT_ID 조회
					DBU_init_mwipmatdef(&MWIPMATDEF_BOM);
					memcpy(MWIPMATDEF_BOM.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
					memcpy(MWIPMATDEF_BOM.MAT_ID, CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));
					MWIPMATDEF_BOM.MAT_VER = 1;
					DBU_select_mwipmatdef(1, &MWIPMATDEF_BOM);
					if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0006 : 이 제품은 존재 하지 않습니다.
						strcpy(s_msg_code, "WIP-0006");
						TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BOM.FACTORY), MWIPMATDEF_BOM.FACTORY);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BOM.MAT_ID), MWIPMATDEF_BOM.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					memcpy(CWIPORDBOM.UNIT, MWIPMATDEF_BOM.UNIT_1, sizeof(CWIPORDBOM.UNIT));



					TRS.copy(CWIPORDBOM.CREATE_USER_ID, sizeof(CWIPORDBOM.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPORDBOM.CREATE_TIME, gs_sys_time, sizeof(CWIPORDBOM.CREATE_TIME));

					DBU_insert_cwipordbom(&CWIPORDBOM);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPORDBOM INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDBOM.OPER), CWIPORDBOM.OPER);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}




					/*

					//ORD-0028 : 이 자재는 작업지시 BOM에 속해 있지 않습니다. 작업지시를 확인하세요.
					strcpy(s_msg_code, "ORD-0028");
					TRS.add_fieldmsg(out_node, "CWIPORDBOM SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
					*/


				}
			}

			//자재lot 또는 공정lot인지 판단하여 조회한다
			if (memcmp(TRS.get_string(list_tbl[i], "LOT_TYPE"), MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == 0)
			{
				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), list_tbl[i], "LOT_ID");
				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER)) != MP_FALSE)
				{
					//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0648");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (TRS.get_procstep(in_node) == '2')
				{
					if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_PROD)
					{
						if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
						{
							//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
							strcpy(s_msg_code, "WIP-0681");
							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
							TRS.add_fieldmsg(out_node, "LOT_TYPE", MP_CHR, MWIPLOTSTSX.LOT_TYPE);


							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}
				}
				else if (TRS.get_procstep(in_node) == '4')
				{
					if (MWIPLOTSTSX_M.LOT_TYPE == MP_LOT_TYPE_PROD)
					{
						if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
						{
							//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
							strcpy(s_msg_code, "WIP-0681");
							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
							TRS.add_fieldmsg(out_node, "LOT_TYPE", MP_CHR, MWIPLOTSTSX.LOT_TYPE);

							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}
				}
			}
			else
			{
				//자재 LOT 확인
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), list_tbl[i], "LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
				{
					////WIP-0649 : 자재 공정이 일치하지 않습니다. 자재의 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0649");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			// 자재LOT이 load 되어있는지 확인 후 투입되어 있지 않으면 투입처리.
			DBU_init_cwipinvldm(&CWIPINVLDM);
			TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
			CWIPINVLDM.REL_LEVEL = TRS.get_char(in_node, "REL_LEVEL");
			TRS.copy(CWIPINVLDM.OPER, sizeof(CWIPINVLDM.OPER), in_node, "OPER");
			TRS.copy(CWIPINVLDM.ORDER_ID, sizeof(CWIPINVLDM.ORDER_ID), in_node, "ORDER_ID");
			TRS.copy(CWIPINVLDM.RES_ID, sizeof(CWIPINVLDM.RES_ID), in_node, "RES_ID");
			TRS.copy(CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), list_tbl[i], "LOT_ID");
			TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), in_node, "LOT_ID");
			DBU_select_cwipinvldm(iStep, &CWIPINVLDM);
			if (DB_error_code == DB_SUCCESS)
			{
				//INV-0028 : 해당 자재에 투입 이력이 존재합니다. 자재LOT 투입 이력을 확인하세요.
				strcpy(s_msg_code, "INV-0028");
				TRS.add_fieldmsg(out_node, "CWIPINVLDM SELECT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
			else if (DB_error_code == DB_NOT_FOUND)
			{
				memcpy(CWIPINVLDM.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				memcpy(CWIPINVLDM.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

				if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_FALSE)
				{
					//작업지시 체크
					DBU_init_mwipordsts(&MWIPORDSTS);
					TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
					DBU_select_mwipordsts(1, &MWIPORDSTS);

					memcpy(CWIPINVLDM.FLOW, MWIPORDSTS.FLOW, sizeof(CWIPINVLDM.FLOW));
					memcpy(CWIPINVLDM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				}

				memcpy(CWIPINVLDM.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

				TRS.copy(CWIPINVLDM.LOT_ID, sizeof(CWIPINVLDM.LOT_ID), in_node, "LOT_ID");
				TRS.copy(CWIPINVLDM.RES_ID, sizeof(CWIPINVLDM.RES_ID), in_node, "RES_ID");
				memcpy(CWIPINVLDM.TRAN_TIME, gs_sys_time, sizeof(CWIPINVLDM.TRAN_TIME));
				TRS.copy(CWIPINVLDM.MAT_ID, sizeof(CWIPINVLDM.MAT_ID), list_tbl[i], "MAT_ID");
				CWIPINVLDM.MAT_VER = 1;

				//리스트의 out oper가 있는경우 innode의 out oper 보가 우선으로 값을 넣어준다. 
				// =>in_node인 경우 : 자재투입,  list_tbl[i]인 경우 : 외주자재 투입인 경우
				if (COM_isnullspace(TRS.get_string(list_tbl[i], "OUT_OPER")) == MP_TRUE)
				{
					//TRS.copy(CWIPINVLDM.OUT_OPER, sizeof(CWIPINVLDM.OUT_OPER), in_node, "OUT_OPER");
					//WIP-0649 : 자재 공정이 일치하지 않습니다. 자재의 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0649");
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
				else
				{
					TRS.copy(CWIPINVLDM.OUT_OPER, sizeof(CWIPINVLDM.OUT_OPER), list_tbl[i], "OUT_OPER");
				}

				TRS.copy(CWIPINVLDM.CREATE_USER_ID, sizeof(CWIPINVLDM.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPINVLDM.CREATE_TIME, gs_sys_time, sizeof(CWIPINVLDM.CREATE_TIME));
				TRS.copy(CWIPINVLDM.UPDATE_USER_ID, sizeof(CWIPINVLDM.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPINVLDM.UPDATE_TIME, gs_sys_time, sizeof(CWIPINVLDM.UPDATE_TIME));
				TRS.copy(CWIPINVLDM.LOT_TYPE, sizeof(CWIPINVLDM.LOT_TYPE), list_tbl[i], "LOT_TYPE");

				//INPUT_TYPE이 존재하지 않는 자재인 경우 무조건 input type을 all로 한다. unit 단위를 알 수 없기 때문
				if (COM_isnullspace(TRS.get_string(list_tbl[i], "INPUT_TYPE")) == MP_FALSE)
				{
					TRS.copy(CWIPINVLDM.INPUT_TYPE, sizeof(CWIPINVLDM.INPUT_TYPE), list_tbl[i], "INPUT_TYPE");
				}
				else
				{
					memcpy(CWIPINVLDM.INPUT_TYPE, MP_INPUT_TYPE_ALL, strlen(MP_INPUT_TYPE_ALL));
				}

				CWIPINVLDM.QTY = TRS.get_double(list_tbl[i], "QTY");
				CWIPINVLDM.BOM_QTY = TRS.get_double(list_tbl[i], "BOM_QTY");

				DBU_insert_cwipinvldm(&CWIPINVLDM);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPINVLDM INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				if (memcmp(TRS.get_string(list_tbl[i], "LOT_TYPE"), MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == 0)
				{
					//// 자재LOT이 load 되어있는지 확인 후 투입되어 있지 않으면 투입처리.
					//자재 LOT 확인
					DBU_init_minvlotsts(&MINVLOTSTS);
					TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), list_tbl[i], "LOT_ID");
					DBU_select_minvlotsts(1, &MINVLOTSTS);

					if (CWIPINVLDM.REL_LEVEL == '1')
					{
						if (MINVLOTSTS.LOT_ID[0] == ' ' || memcmp(MINVLOTSTS.LOT_ID, MWIPLOTSTSX_M.LOT_ID, sizeof(MWIPLOTSTSX_M.LOT_ID)) != MP_FALSE)
							iBomcheck = MP_TRUE;
						else
							iBomcheck = MP_FALSE;
					}
					else if (CWIPINVLDM.REL_LEVEL == '2')
					{
						if (MINVLOTSTS.ORDER_ID[0] == ' ' || memcmp(MINVLOTSTS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID)) != MP_FALSE)
							iBomcheck = MP_TRUE;
						else
							iBomcheck = MP_FALSE;
					}
					else if (CWIPINVLDM.REL_LEVEL == '3')
					{
						if (MINVLOTSTS.INV_CMF_9[0] == ' ' || memcmp(MINVLOTSTS.INV_CMF_9, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER)) != MP_FALSE)
							iBomcheck = MP_TRUE;
						else
							iBomcheck = MP_FALSE;
					}

					if (iBomcheck == MP_TRUE)
					{
						load_in = TRS.add_node(in_node, "load_in");
						TRS.add_char(load_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(load_in, in_node);

						if (CWIPINVLDM.REL_LEVEL == '1')
						{
							TRS.add_nstring(load_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
						}
						else if (CWIPINVLDM.REL_LEVEL == '2')
						{
							TRS.add_string(load_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						}
						else if (CWIPINVLDM.REL_LEVEL == '3')
						{
							TRS.add_nstring(load_in, "OPER", TRS.get_string(in_node, "OPER"));
						}

						TRS.add_nstring(load_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
						TRS.add_nstring(load_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));
						TRS.add_char(load_in, "REL_LEVEL", TRS.get_char(in_node, "REL_LEVEL"));

						inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
						TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_INV_LOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);
					}
				}
			}



			//투입 lOt의 비고정보 생산LOT에 입력(20220610)
			if (TRS.get_char(in_node, "COMMENT_WIP") == 'Y') {
				TRS.copy(MWIPLOTSTSX_M.LAST_COMMENT, sizeof(MWIPLOTSTSX_M.LAST_COMMENT), list_tbl[i], "COMMENT");

				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_M);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_M UPDATE(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_fieldmsg(out_node, "LAST_COMMENT", MP_STR, sizeof(MWIPLOTSTSX.LAST_COMMENT), MWIPLOTSTSX.LAST_COMMENT);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

					return MP_FALSE;
				}

			}


		}
	}
	//자재 미투입 처리 => 자재를 바로 iss에 투입처리 하고 erp에 투입 실적을 전송한다.
	else if (TRS.get_procstep(in_node) == '5')
	{
		//작업지시 체크
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		//테스트품도 투입가능하게 변경(2023-05-17)
	  /*  if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_TEST)
		{
			//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
			strcpy(s_msg_code, "WIP-0681");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
		*/

		//투입처리 하는 공정을 체크한다.
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

		//창고 고정은 자재를 투입처리 할 수 없다. 
		if (MWIPOPRDEF.INV_FLAG == 'Y')
		{
			//WIP-0629 : 해당 공정은 자재 투입 공정이 아닙니다.
			strcpy(s_msg_code, "WIP-0629");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//20220613 검사공정도 투입하는 경우의수있을수 있음.
		/*
		//검사 공정은 자재 투입을 할 수 없다
		if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
			memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
		{
			//WIP-0629 : 해당 공정은 자재 투입 공정이 아닙니다.
			strcpy(s_msg_code, "WIP-0629");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		*/

		//ERP공정과 맵핑되지 않은 공정은 자재 투입을 할 수 없다.
		if (MWIPOPRDEF.OPER_CMF_1[0] == ' ')
		{
			//WIP-0652 : ERP 공정과 맵핑되어 있지 않은 공정은 자재를 투입할 수 없습니다.
			strcpy(s_msg_code, "WIP-0652");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_TEST) {

		}
		else {
			//작업지시 공정 조회
			DBU_init_cwiperpopr(&CWIPERPOPR);
			memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
			memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
			memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
			DBU_select_cwiperpopr(2, &CWIPERPOPR);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0010 : 이 공정은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "CWIPERPOPR SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}



		//ERP AREA ID 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
		TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ERP SUB AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_SUB_AREA);
		TRS.copy(MGCMTBLDAT_SUB_AREA.FACTORY, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_SUB_AREA.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
		memcpy(MGCMTBLDAT_SUB_AREA.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SUB_AREA);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), MGCMTBLDAT_SUB_AREA.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.KEY_1), MGCMTBLDAT_SUB_AREA.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//Client에서 받은 LOT ID에 대한 정보를 조회한다.
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
		//테스트품도 투입가능하게 변경(2023-05-17)
		/*
		if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
		{
			//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
			strcpy(s_msg_code, "WIP-0681");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_TYPE", MP_CHR, MWIPLOTSTSX.LOT_TYPE);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
		*/

		list_tbl = TRS.get_list(in_node, "LIST_TBL");
		iItemCount = TRS.get_item_count(in_node, "LIST_TBL");

		for (i = 0; i < iItemCount; i++)
		{
			memset(s_lot_id, ' ', sizeof(s_lot_id));

			//자재 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), list_tbl[i], "MAT_ID");
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

				return MP_FALSE;
			}

			//2020-12-31 요청에 의해 주석처리
			/*
			//작업지시 BOM정보에 존재하는 MAT ID 인지 확인한다.
			DBU_init_cwipordbom(&CWIPORDBOM);
			TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			memcpy(CWIPORDBOM.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CWIPORDBOM.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));

			CWIPORDBOM.MAT_VER = 1;
			DBU_select_cwipordbom(1, &CWIPORDBOM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0028 : 이 자재는 작업지시 BOM에 속해 있지 않습니다. 작업지시를 확인하세요.
				strcpy(s_msg_code, "ORD-0028");
				TRS.add_fieldmsg(out_node, "CWIPORDBOM SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			} */

			//20230220 생산테이블먼저조회하고 없으면 자재테이블 조회해서 투입하는것으로 변경

			DBU_init_mwiplotstsx(&MWIPLOTSTSX_ISS);
			TRS.copy(MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID), list_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_ISS);
			if (DB_error_code != DB_SUCCESS)
			{


				/*
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.LOT_ID), MWIPLOTSTSX_ISS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;

				*/


				//자재 LOT 확인
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), list_tbl[i], "LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(s_lot_id, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				i_seq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;

				if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
				{
					////WIP-0649 : 자재 공정이 일치하지 않습니다. 자재의 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0649");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (COM_dbl_round(MINVLOTSTS.QTY, 5, 'U') < COM_dbl_round(TRS.get_double(list_tbl[i], "QTY"), 5, 'U'))
				{
					//WIP-0672 :투입 수량이 lot의 수량보다 클 수가 없습니다. 투입 수량을 확인 하세요.
					strcpy(s_msg_code, "WIP-0672");
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
				memcpy(MWIPOPRDEF_ISS.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
				memcpy(MWIPOPRDEF_ISS.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

				if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
				{
					//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0646");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

				if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD)) == MP_FALSE)
				{
					 //20250526 출하전 제품창고에서 투입처리되는거 막음
					//INV - 0079 : 제품창고에서는  투입처리 할 수 없습니다.창고 이동 후 투입처리를 진행해 주세요.
					strcpy(s_msg_code, "INV-0079");
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

			}
			else
			{
				memcpy(s_lot_id, MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
				i_seq = MWIPLOTSTSX_ISS.LAST_ACTIVE_HIST_SEQ;


				if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER)) != MP_FALSE)
				{
					//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0648");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_ISS.OPER), MWIPLOTSTSX_ISS.OPER);
					TRS.add_fieldmsg(out_node, "OUT_OPER", MP_STR, sizeof(TRS.get_string(list_tbl[i], "OUT_OPER")), TRS.get_string(list_tbl[i], "OUT_OPER"));
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (COM_dbl_round(MWIPLOTSTSX_ISS.QTY_1, 5, 'U') < COM_dbl_round(TRS.get_double(list_tbl[i], "QTY"), 5, 'U'))
				{
					//WIP-0672 :투입 수량이 lot의 수량보다 클 수가 없습니다. 투입 수량을 확인 하세요.
					strcpy(s_msg_code, "WIP-0672");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.LOT_ID), MWIPLOTSTSX_ISS.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				//테스트품도 투입가능하게 변경(2023-05-17)
				/*
				if (MWIPLOTSTSX_ISS.LOT_TYPE == MP_LOT_TYPE_TEST)
				{
					//WIP-0681 : 테스트품은 자재를 투입처리 할 수 없습니다. LOT의 타입을 확인하세요.
					strcpy(s_msg_code, "WIP-0681");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_ISS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_ISS.FACTORY), MWIPLOTSTSX_ISS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.ORDER_ID), MWIPLOTSTSX_ISS.ORDER_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.LOT_ID), MWIPLOTSTSX_ISS.LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_TYPE", MP_CHR, MWIPLOTSTSX_ISS.LOT_TYPE);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
				*/

				DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
				memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
				memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

				if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
				{
					//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0646");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}

			//자재사용 저장
			DBU_init_minvlotiss(&MINVLOTISS);
			TRS.copy(MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
			MINVLOTISS.HIST_SEQ = i_seq;
			DBU_select_minvlotiss(1, &MINVLOTISS);
			if (DB_error_code == DB_SUCCESS)
			{

				DBU_init_minvlotiss(&MINVLOTISS);
				TRS.copy(MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
				//20230516 INV에서 WIP으로 변경된 원자재경우 HIST_SEQ 중복떔?..오류 그냥 플로스 10000 시켜서 HIST_SEQ 만듬
				MINVLOTISS.HIST_SEQ = i_seq + 10000;
				DBU_select_minvlotiss(1, &MINVLOTISS);
				if (DB_error_code == DB_SUCCESS)
				{
					//INV-0028 : 해당 자재에 투입 이력이 존재합니다. 자재LOT 투입 이력을 확인하세요.
					strcpy(s_msg_code, "INV-0028");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "MINVLOTISS SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);

					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					return MP_FALSE;
				}


				/*

				//INV-0028 : 해당 자재에 투입 이력이 존재합니다. 자재LOT 투입 이력을 확인하세요.
				strcpy(s_msg_code, "INV-0028");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "MINVLOTISS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				return MP_FALSE;
				*/
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				memcpy(MINVLOTISS.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
				TRS.copy(MINVLOTISS.TRAN_USER_ID, sizeof(MINVLOTISS.TRAN_USER_ID), in_node, IN_USERID);
				memcpy(MINVLOTISS.TRAN_TIME, gs_sys_time, sizeof(MINVLOTISS.TRAN_TIME));
				//memcpy(MINVLOTISS.TRAN_TIME, MWIPLOTSTSX.LAST_TRAN_TIME, sizeof(MWIPLOTSTSX.LAST_TRAN_TIME));
				memcpy(MINVLOTISS.TRAN_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				memcpy(MINVLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MINVLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
				memcpy(MINVLOTISS.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				memcpy(MINVLOTISS.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
				memcpy(MINVLOTISS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				memcpy(MINVLOTISS.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MINVLOTISS.ERP_OPER));
				TRS.copy(MINVLOTISS.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER), list_tbl[i], "OUT_OPER");
				memcpy(MINVLOTISS.REASON_CODE, MP_INPUT_TYPE_LOT, strlen(MP_INPUT_TYPE_LOT));
				MINVLOTISS.TRAN_QTY = TRS.get_double(list_tbl[i], "QTY");
				memcpy(MINVLOTISS.TRAN_UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				MINVLOTISS.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
				memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(MINVLOTISS.CMF_2, "ETC", strlen("ETC"));

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
			}


			//in_OUT LOT이 같의면 패스(20230220 )
			if (memcmp(MINVLOTISS.INV_LOT_ID, MINVLOTISS.LOT_ID, strlen(MINVLOTISS.LOT_ID)) != 0)
			{
				//사용한 자재는 사용량 만큼 CV처리를 해준다.
				if (memcmp(TRS.get_string(list_tbl[i], "LOT_TYPE"), MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == 0)
				{
					cv_in = TRS.add_node(in_node, "cv_in");
					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(cv_in, in_node);

					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
					TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_ISS.MAT_ID, sizeof(MWIPLOTSTSX_ISS.MAT_ID));
					TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
					TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_ISS.FLOW, sizeof(MWIPLOTSTSX_ISS.FLOW));
					TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
					//TRS.add_string(cv_in, "COMMENT", MWIPLOTSTSX_ISS.LAST_COMMENT, sizeof(MWIPLOTSTSX_ISS.LAST_COMMENT));  20220602 자재투입후 비고 사라진다는 문의로해당부분 주석처리함
					//TRS.add_nstring(cv_in, "COMMENT",TRS.get_string(in_node, "COMMENT"));//20210901  커맨트 삭제되는거 방지.클라이언트에서 딱히 COMMENT 안가져옴..혹시 있었으면 수정해야됨.
					TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_ISS.QTY_1 - TRS.get_double(list_tbl[i], "QTY"));
					TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					if (memcmp(MWIPLOTSTSX_ISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)) != MP_FALSE)
					{
						//LOT 추적 테이블에 저장
						DBU_init_cwiplottrc(&CWIPLOTTRC);
						TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);
						memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPLOTTRC.AREA_ID));
						memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPLOTTRC.SUB_AREA_ID));
						memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
						memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
						memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX_ISS.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
						CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX_ISS.LAST_ACTIVE_HIST_SEQ;
						memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
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
				else
				{
					//자재 load를 해준다
					load_in = TRS.add_node(in_node, "load_in");
					TRS.add_char(load_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(load_in, in_node);

					TRS.add_string(load_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_nstring(load_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
					TRS.add_nstring(load_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_char(load_in, "REL_LEVEL", '1');

					inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
					TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_LOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);

					//자재를 iss 시켜준다.
					cv_in = TRS.add_node(in_node, "cv_in");
					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(cv_in, in_node);

					inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
					TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
					TRS.add_double(inv_list, "ISSUE_QTY", MINVLOTISS.TRAN_QTY);
					TRS.add_string(cv_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					//TRS.add_nstring(cv_in, "TRAN_COMMENT", TRS.get_string(in_node, "COMMENT"));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_ISSUE_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}



			}




			//투입 lOt의 비고정보 생산LOT에 입력(20220610)
			if (TRS.get_char(in_node, "COMMENT_WIP") == 'Y') {
				TRS.copy(MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT), list_tbl[i], "COMMENT");

				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
					TRS.add_fieldmsg(out_node, "LAST_COMMENT", MP_STR, sizeof(MWIPLOTSTSX.LAST_COMMENT), MWIPLOTSTSX.LAST_COMMENT);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

					return MP_FALSE;
				}

			}


			if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_STORED_GOODS, strlen(MP_MAT_TYPE_STORED_GOODS)) == 0) {


				//기타출고 계정 가져온다.
				DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
				TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE", strlen("TEST_ITEM_ISSUE"));
				memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
				memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
				if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0) {

					DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
					TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE2", strlen("TEST_ITEM_ISSUE2"));
					memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
					memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);



					if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
					{

						//기타출고 계정 가져온다.
						DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
						TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
						memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
						memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
						memcpy(MGCMTBLDAT_TYPE.KEY_2, " ", sizeof(" "));
						DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
						if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
							TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
							TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

					}

				}


				//기타 출고 코드 확인
				DBU_init_cbastxndef(&CBASTXNDEF_ETC);
				TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_3, sizeof(MGCMTBLDAT_TYPE.DATA_3));
				CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));
				DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT_1", MP_NVST);
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


				//기타 입출고 이력 테이블 저장
				DBU_init_minvetclot(&MINVETCLOT);
				TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
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
				memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

				if (DB_error_code == DB_NOT_FOUND)
				{
					MINVETCLOT.SEQ = 1;
				}
				else
				{
					MINVETCLOT.SEQ += 1;
				}

				if (i_LotType == 1)
					memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
				else if (i_LotType == 2)
					memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));

				MINVETCLOT.QTY = MINVLOTISS.TRAN_QTY;
				memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
				memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
				memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF_ISS.SUB_AREA_ID, sizeof(MWIPOPRDEF_ISS.SUB_AREA_ID));
				memcpy(MINVETCLOT.OPER, MWIPOPRDEF_ISS.OPER, sizeof(MWIPOPRDEF_ISS.OPER));
				memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
				MINVETCLOT.VENDOR_SITE_ID = 0;
				memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
				memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_OUT, sizeof(MINVETCLOT.ETC_TYPE));
				memcpy(MINVETCLOT.ETC_DATE, MINVLOTISS.TRAN_TIME, 8);
				MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
				memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
				memcpy(MINVETCLOT.ETC_COMMENT, MINVLOTISS.TRAN_COMMENT, sizeof(MINVLOTISS.TRAN_COMMENT));

				//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
				//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
				memcpy(MINVETCLOT.CMF_1, "C", strlen("C"));
				memcpy(MINVETCLOT.CMF_2, MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));
				memcpy(MINVETCLOT.CMF_3, MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
				//20240215 자재리턴시 필요해서 HIST_SEQ추가
				memset(c_Iss_cmf4, ' ', sizeof(c_Iss_cmf4));
				sprintf(c_Iss_cmf4, "%d", MINVLOTISS.HIST_SEQ);
				memcpy(MINVETCLOT.CMF_4, c_Iss_cmf4, sizeof(MINVETCLOT.CMF_4));


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
				inv_if = TRS.add_node(in_node, "inv_if");
				TRS.add_char(inv_if, IN_PROCSTEP, '1');
				CopyDefaultMembers(inv_if, in_node);

				TRS.add_char(inv_if, "TRAN_FLAG", 'I');
				//TRS.add_int(inv_if, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				//TRS.add_string(inv_if, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_1));
				TRS.add_string(inv_if, "TRAN_TYPE", "Account issue", sizeof("Account issue"));
				TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
				TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
				TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
				TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
				TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(inv_if, "FROM_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
				TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(inv_if, "QTY", -1 * MINVLOTISS.TRAN_QTY);
				TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

				d_ifseq = (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

				//ERP 실적 - IF_INV_TXN_LOTS
				inv_if = TRS.add_node(in_node, "inv_if");
				TRS.add_char(inv_if, IN_PROCSTEP, '1');
				CopyDefaultMembers(inv_if, in_node);

				TRS.add_char(inv_if, "TRAN_FLAG", 'I');
				TRS.add_double(inv_if, "INV_TXNS_ID", d_ifseq);
				TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(inv_if, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
				TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)); //추후 맞는 데이터가 들어옴
				TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				memset(c_if_seq, ' ', sizeof(c_if_seq));
				sprintf(c_if_seq, "%.0f", d_ifseq);

				//인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
				MINVLOTISS.CMF_1[0] = 'Y';
				memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
				DBU_update_minvlotiss(1, &MINVLOTISS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

					return MP_FALSE;
				}





			}

			else if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_TEST) {
				if (MWIPLOTSTSX_ISS.LOT_TYPE != MP_LOT_TYPE_TEST) {


					//기타출고 계정 가져온다.
					DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
					TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE", strlen("TEST_ITEM_ISSUE"));
					memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
					memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
					if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0) {

						DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
						TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
						memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "TEST_ITEM_ISSUE2", strlen("TEST_ITEM_ISSUE2"));
						memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
						memcpy(MGCMTBLDAT_TYPE.KEY_2, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);



						if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
						{

							//기타출고 계정 가져온다.
							DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
							TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
							memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
							memcpy(MGCMTBLDAT_TYPE.KEY_2, " ", sizeof(" "));
							DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
							if (DB_error_code != DB_SUCCESS || memcmp(MGCMTBLDAT_TYPE.DATA_6, "N", strlen("N")) == 0)
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
								TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
								TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

						}

					}


					//기타 출고 코드 확인
					DBU_init_cbastxndef(&CBASTXNDEF_ETC);
					TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
					CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_3, sizeof(MGCMTBLDAT_TYPE.DATA_3));
					CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));
					DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT_2", MP_NVST);
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


					//기타 입출고 이력 테이블 저장
					DBU_init_minvetclot(&MINVETCLOT);
					TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
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
					memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

					if (DB_error_code == DB_NOT_FOUND)
					{
						MINVETCLOT.SEQ = 1;
					}
					else
					{
						MINVETCLOT.SEQ += 1;
					}

					if (i_LotType == 1)
						memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_WIP, sizeof(MINVETCLOT.LOT_TYPE));
					else if (i_LotType == 2)
						memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));

					MINVETCLOT.QTY = MINVLOTISS.TRAN_QTY;
					memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
					memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
					memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF_ISS.SUB_AREA_ID, sizeof(MWIPOPRDEF_ISS.SUB_AREA_ID));
					memcpy(MINVETCLOT.OPER, MWIPOPRDEF_ISS.OPER, sizeof(MWIPOPRDEF_ISS.OPER));
					memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
					MINVETCLOT.VENDOR_SITE_ID = 0;
					memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
					memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_OUT, sizeof(MINVETCLOT.ETC_TYPE));
					memcpy(MINVETCLOT.ETC_DATE, MINVLOTISS.TRAN_TIME, 8);
					MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
					memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
					memcpy(MINVETCLOT.ETC_COMMENT, MINVLOTISS.TRAN_COMMENT, sizeof(MINVLOTISS.TRAN_COMMENT));

					//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
					//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
					memcpy(MINVETCLOT.CMF_1, "C", strlen("C"));
					memcpy(MINVETCLOT.CMF_2, MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));
					memcpy(MINVETCLOT.CMF_3, MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
					//20240215 자재리턴시 필요해서 HIST_SEQ추가
					memset(c_Iss_cmf4, ' ', sizeof(c_Iss_cmf4));
					sprintf(c_Iss_cmf4, "%d", MINVLOTISS.HIST_SEQ);
					memcpy(MINVETCLOT.CMF_4, c_Iss_cmf4, sizeof(MINVETCLOT.CMF_4));



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
					inv_if = TRS.add_node(in_node, "inv_if");
					TRS.add_char(inv_if, IN_PROCSTEP, '1');
					CopyDefaultMembers(inv_if, in_node);

					TRS.add_char(inv_if, "TRAN_FLAG", 'I');
					//TRS.add_int(inv_if, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
					//TRS.add_string(inv_if, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
					TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_1));
					TRS.add_string(inv_if, "TRAN_TYPE", "Account issue", sizeof("Account issue"));
					TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
					TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
					TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
					TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
					TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
					TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(inv_if, "FROM_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
					TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(inv_if, "QTY", -1 * MINVLOTISS.TRAN_QTY);
					TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
					TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					DBU_init_if_inv_txns(&IF_INV_TXNS);
					TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
					memcpy(IF_INV_TXNS.MES_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

					d_ifseq = (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

					//ERP 실적 - IF_INV_TXN_LOTS
					inv_if = TRS.add_node(in_node, "inv_if");
					TRS.add_char(inv_if, IN_PROCSTEP, '1');
					CopyDefaultMembers(inv_if, in_node);

					TRS.add_char(inv_if, "TRAN_FLAG", 'I');
					TRS.add_double(inv_if, "INV_TXNS_ID", d_ifseq);
					TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
					TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(inv_if, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
					TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)); //추후 맞는 데이터가 들어옴
					TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_INV_TXN_LOTS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					memset(c_if_seq, ' ', sizeof(c_if_seq));
					sprintf(c_if_seq, "%.0f", d_ifseq);

					//인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
					MINVLOTISS.CMF_1[0] = 'Y';
					memcpy(MINVLOTISS.CMF_3, c_if_seq, sizeof(MINVLOTISS.CMF_3));
					DBU_update_minvlotiss(1, &MINVLOTISS);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "CMN-0004");
						TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
						TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

						return MP_FALSE;
					}

				}






			}


			else {
				inv_if = TRS.add_node(in_node, "inv_if");
				TRS.add_char(inv_if, IN_PROCSTEP, '1');
				CopyDefaultMembers(inv_if, in_node);

				TRS.add_char(inv_if, "TRAN_FLAG", 'I');
				TRS.add_string(inv_if, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				TRS.add_int(inv_if, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
				TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
				TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
				TRS.add_string(inv_if, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
				TRS.add_int(inv_if, "ERP_SUB_AREA_ID", COM_atoi(MGCMTBLDAT_SUB_AREA.DATA_8, sizeof(MGCMTBLDAT_SUB_AREA.DATA_8)));
				TRS.add_int(inv_if, "OPER_SEQ", CWIPERPOPR.OPER_SEQ);
				TRS.add_string(inv_if, "OPER", CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));
				TRS.add_string(inv_if, "INV_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
				TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);
				TRS.add_string(inv_if, "CMF_1", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, inv_if, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				d_ifseq = TRS.get_double(cmn_out, "IF_SEQ");
				TRS.free_node(cmn_out);

			}



			//인터페이스에 올린 iss는 cmf1에 'Y'로 넣는다.
			MINVLOTISS.CMF_1[0] = 'Y';

			//double에서 자리수가 E가 들어가는 소수점으로 들어가서 long으로 처리. -> 베트남 시퀀스에서도 생각해봐야함
			COM_ltoa_left(MINVLOTISS.CMF_3, (long)d_ifseq, sizeof(MINVLOTISS.CMF_3));
			DBU_update_minvlotiss(1, &MINVLOTISS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

				return MP_FALSE;
			}
		}
	}
	//6 자재투입취소
	else if (TRS.get_procstep(in_node) == '6')
	{
		//작업지시 체크
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}



		//투입처리 하는 공정을 체크한다.
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

		//창고 고정은 자재를 투입처리 할 수 없다. 
		if (MWIPOPRDEF.INV_FLAG == 'Y')
		{
			//WIP-0629 : 해당 공정은 자재 투입 공정이 아닙니다.
			strcpy(s_msg_code, "WIP-0629");
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//테스트 작지인경우
		if (MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_TEST) {

		}
		//양산작지인경우
		else {

			//ERP공정과 맵핑되지 않은 공정은 자재 투입을 할 수 없다.(작업지시공정은 제외)
			if (MWIPOPRDEF.OPER_CMF_1[0] == ' ' && memcmp(MWIPOPRDEF.OPER, "OC05001", strlen("OC05001")) != MP_FALSE)
			{
				//WIP-0652 : ERP 공정과 맵핑되어 있지 않은 공정은 자재를 투입할 수 없습니다.
				strcpy(s_msg_code, "WIP-0652");
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPOPRDEF.OPER, "OC05001", strlen("OC05001")) == MP_FALSE)
			{
				//작업지시 공정 조회
				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				DBU_select_cwiperpopr(3, &CWIPERPOPR);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0010 : 이 공정은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "CWIPERPOPR(FIRST OP) SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				//작업지시 공정 조회
				DBU_init_cwiperpopr(&CWIPERPOPR);
				memcpy(CWIPERPOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(CWIPERPOPR.FACTORY));
				memcpy(CWIPERPOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID));
				memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
				DBU_select_cwiperpopr(2, &CWIPERPOPR);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0010 : 이 공정은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "CWIPERPOPR SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

		}



		//ERP AREA ID 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
		TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ERP SUB AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_SUB_AREA);
		TRS.copy(MGCMTBLDAT_SUB_AREA.FACTORY, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_SUB_AREA.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
		memcpy(MGCMTBLDAT_SUB_AREA.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SUB_AREA);
		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.FACTORY), MGCMTBLDAT_SUB_AREA.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_SUB_AREA.KEY_1), MGCMTBLDAT_SUB_AREA.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}




		list_tbl = TRS.get_list(in_node, "LIST_TBL");
		iItemCount = TRS.get_item_count(in_node, "LIST_TBL");

		for (i = 0; i < iItemCount; i++)
		{
			memset(s_lot_id, ' ', sizeof(s_lot_id));




			//Client에서 받은 LOT ID에 대한 정보를 조회한다.
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), list_tbl[i], "OPER_LOT_ID");
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


			//자재 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), list_tbl[i], "MAT_ID");
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

				return MP_FALSE;
			}



			//20230220 생산테이블먼저조회하고 없으면 자재테이블 조회해서 투입취소하는것으로 변경

			DBU_init_mwiplotstsx(&MWIPLOTSTSX_ISS);
			TRS.copy(MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID), list_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_ISS);
			if (DB_error_code != DB_SUCCESS)
			{


				//자재 LOT 확인
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), list_tbl[i], "LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
					strcpy(s_msg_code, "WIP-0044");
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(s_lot_id, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				i_seq = MINVLOTSTS.LAST_ACTIVE_HIST_SEQ;

				////WIP-0649 : 자재 공정이 일치하지 않습니다. 자재의 공정을 확인하세요.
				if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER)) != MP_FALSE)
				{
					////WIP-0649 : 자재 공정이 일치하지 않습니다. 자재의 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0649");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				//WIP - 0696 : 투입당시 품목과 현재혹은 마지막 품목코드가 다릅니다..
				if (TRS.mem_cmp(list_tbl[i], "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID)) != MP_FALSE)
				{
					//WIP - 0696 : 투입당시 품목과 현재혹은 마지막 품목코드가 다릅니다.
					strcpy(s_msg_code, "WIP-0696");
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}



				DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
				memcpy(MWIPOPRDEF_ISS.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
				memcpy(MWIPOPRDEF_ISS.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

				//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
				if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
				{
					//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
					strcpy(s_msg_code, "WIP-0646");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

				//INV이면 True
				iWipInvcheck = MP_TRUE;

			}
			else
			{
				memcpy(s_lot_id, MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
				i_seq = MWIPLOTSTSX_ISS.LAST_ACTIVE_HIST_SEQ;


				if (memcmp(MWIPOPRDEF.OPER_CMF_2, "Y", strlen("Y")) != MP_FALSE) {
					if (TRS.mem_cmp(list_tbl[i], "OUT_OPER", MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER)) != MP_FALSE)
					{
						//WIP-0648 : 출고 공정과 LOT의 공정이 다릅니다. 공정을 확인하세요.
						strcpy(s_msg_code, "WIP-0648");
						TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_ISS.OPER), MWIPLOTSTSX_ISS.OPER);
						TRS.add_fieldmsg(out_node, "OUT_OPER", MP_STR, sizeof(TRS.get_string(list_tbl[i], "OUT_OPER")), TRS.get_string(list_tbl[i], "OUT_OPER"));
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//WIP - 0696 : 투입당시 품목과 현재혹은 마지막 품목코드가 다릅니다..
					if (TRS.mem_cmp(list_tbl[i], "MAT_ID", MWIPLOTSTSX_ISS.MAT_ID, sizeof(MWIPLOTSTSX_ISS.MAT_ID)) != MP_FALSE)
					{
						//WIP - 0696 : 투입당시 품목과 현재혹은 마지막 품목코드가 다릅니다.
						strcpy(s_msg_code, "WIP-0696");
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.LOT_ID), MWIPLOTSTSX_ISS.LOT_ID);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.MAT_ID), MWIPLOTSTSX_ISS.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}



					DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
					memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
					memcpy(MWIPOPRDEF_ISS.OPER, MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
					DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

					if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
					{
						//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
						strcpy(s_msg_code, "WIP-0646");
						TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}

				}
				else {

					//CTM 작업지시공정에서 투입된거는 강제로 W-L/P-H 창고로 가도록 함...임시 하드코딩.^^;
					DBU_init_mwipoprdef(&MWIPOPRDEF_ISS);
					memcpy(MWIPOPRDEF_ISS.FACTORY, MWIPLOTSTSX_ISS.FACTORY, sizeof(MWIPLOTSTSX_ISS.FACTORY));
					memcpy(MWIPOPRDEF_ISS.OPER, "CW-L/P-H", strlen("CW-L/P-H"));
					DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISS);

					if (MWIPOPRDEF_ISS.INV_FLAG != 'Y')
					{
						//WIP-0646 : 자재의 공정이 창고가 아닙니다. 공정을 확인하세요.
						strcpy(s_msg_code, "WIP-0646");
						TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_ISS.FACTORY), MWIPOPRDEF_ISS.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISS.OPER), MWIPOPRDEF_ISS.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);
						return MP_FALSE;
					}
				}


				//WIP이면 FALSE
				iWipInvcheck = MP_FALSE;
			}

			//자재사용 조회
			DBU_init_minvlotiss(&MINVLOTISS);
			TRS.copy(MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTISS.INV_LOT_ID, s_lot_id, sizeof(MINVLOTISS.INV_LOT_ID));
			MINVLOTISS.HIST_SEQ = TRS.get_int(list_tbl[i], "HIST_SEQ");

			DBU_select_minvlotiss(1, &MINVLOTISS);
			if (DB_error_code == DB_SUCCESS)
			{

				memcpy(s_yyyymm, MINVLOTISS.TRAN_TIME, sizeof(s_yyyymm));

				//해당 월에 실적 처리가 되었는지 체크한다.
				if (memcmp(s_yyyymm, work_date.s_work_month, sizeof(s_yyyymm)) != MP_FALSE)
				{
					//WIP-0124 : 이 달은 유효하지 않습니다. 달을 확인 하세요.
					strcpy(s_msg_code, "WIP-0124");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
					TRS.add_fieldmsg(out_node, "TRAN_TIME", DT_STRING, sizeof(MINVLOTISS.TRAN_TIME), MINVLOTISS.TRAN_TIME);
					return MP_FALSE;
				}



				//in_OUT LOT이 같의면 패스(20230220 )
				if (memcmp(MINVLOTISS.INV_LOT_ID, MINVLOTISS.LOT_ID, strlen(MINVLOTISS.LOT_ID)) != 0)
				{
					//사용한 자재는 사용량 만큼 CV처리를 해준다.
					//if (memcmp(TRS.get_string(list_tbl[i], "LOT_TYPE"), MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP)) == 0)

					if (iWipInvcheck == MP_FALSE)
					{

						if (MWIPLOTSTSX_ISS.LOT_DEL_FLAG == 'Y')
						{
							MWIPLOTSTSX_ISS.LOT_DEL_FLAG = ' ';
							memset(MWIPLOTSTSX_ISS.LOT_DEL_CODE, ' ', sizeof(MWIPLOTSTSX_ISS.LOT_DEL_CODE));
							memset(MWIPLOTSTSX_ISS.LOT_DEL_TIME, ' ', sizeof(MWIPLOTSTSX_ISS.LOT_DEL_TIME));
							DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_ISS);
							if (DB_error_code != DB_SUCCESS)
							{
								memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ISS.LOT_ID), MWIPLOTSTSX_ISS.LOT_ID);

								return MP_FALSE;
							}


						}


						cv_in = TRS.add_node(in_node, "cv_in");
						TRS.add_char(cv_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(cv_in, in_node);


						TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_ISS.LOT_ID, sizeof(MWIPLOTSTSX_ISS.LOT_ID));
						TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_ISS.MAT_ID, sizeof(MWIPLOTSTSX_ISS.MAT_ID));
						TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_ISS.OPER, sizeof(MWIPLOTSTSX_ISS.OPER));
						TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_ISS.FLOW, sizeof(MWIPLOTSTSX_ISS.FLOW));
						TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
						//TRS.add_string(cv_in, "COMMENT", MWIPLOTSTSX_ISS.LAST_COMMENT, sizeof(MWIPLOTSTSX_ISS.LAST_COMMENT));  20220602 자재투입후 비고 사라진다는 문의로해당부분 주석처리함
						//TRS.add_nstring(cv_in, "COMMENT",TRS.get_string(in_node, "COMMENT"));//20210901  커맨트 삭제되는거 방지.클라이언트에서 딱히 COMMENT 안가져옴..혹시 있었으면 수정해야됨.
						TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_ISS.QTY_1 + MINVLOTISS.TRAN_QTY);
						TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);


						//LOT 추적 테이블에 삭제
						if (memcmp(MWIPLOTSTSX_ISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)) != MP_FALSE)
						{
							//LOT 추적 테이블에 삭제
							DBU_init_cwiplottrc(&CWIPLOTTRC);
							memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
							memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
							memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
							memcpy(CWIPLOTTRC.FROM_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
							DBU_select_cwiplottrc(4, &CWIPLOTTRC);
							if (DB_error_code == DB_SUCCESS)
							{
								DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
								if (DB_error_code != DB_SUCCESS)
								{
									if (DB_error_code != DB_NOT_FOUND)
									{
										//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
										strcpy(s_msg_code, "ADM-0004");
										TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
										TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
										TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
										TRS.add_dberrmsg(out_node, DB_error_msg);

										gs_log_type.type = MP_LOG_ERROR;
										gs_log_type.e_type = MP_LOG_E_SYSTEM;
										gs_log_type.category = MP_LOG_CATE_VIEW;

										COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
										return MP_FALSE;
									}
								}
							}

						}
					}
					else
					{


						if (MINVLOTSTS.DELETE_FLAG == 'Y')
						{
							MINVLOTSTS.DELETE_FLAG = ' ';
							memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
							memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
							memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
							DBU_update_minvlotsts(1, &MINVLOTSTS);
							if (DB_error_code != DB_SUCCESS)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
								TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

								TRS.add_dberrmsg(out_node, DB_error_msg);
								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}


						cv_in = TRS.add_node(in_node, "cv_in");
						TRS.add_char(cv_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(cv_in, in_node);

						inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
						TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
						TRS.add_double(inv_list, "CHANGE_QTY", MINVLOTSTS.QTY + MINVLOTISS.TRAN_QTY);
						TRS.add_string(inv_list, "TRAN_COMMENT", MP_DEL_TRAN_COMMENT, strlen(MP_DEL_TRAN_COMMENT));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);



					}



				}


				if (MINVLOTISS.CMF_1[0] == 'Y') {
					if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_STORED_GOODS, strlen(MP_MAT_TYPE_STORED_GOODS)) == 0 || MWIPORDSTS.LOT_TYPE == MP_LOT_TYPE_TEST) {

						if (MWIPLOTSTSX_ISS.LOT_TYPE != MP_LOT_TYPE_TEST) {






							//기타 입출고 이력 조회
							DBU_init_minvetclot(&MINVETCLOT);
							TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
							memcpy(MINVETCLOT.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
							memcpy(MINVETCLOT.CMF_2, MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));
							memcpy(MINVETCLOT.CMF_3, MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
							//memcpy(MINVETCLOT.CMF_4, MINVLOTISS.HIST_SEQ, sizeof(MINVLOTISS.HIST_SEQ));
							memset(c_Iss_cmf4, ' ', sizeof(c_Iss_cmf4));
							sprintf(c_Iss_cmf4, "%d", MINVLOTISS.HIST_SEQ);
							memcpy(MINVETCLOT.CMF_4, c_Iss_cmf4, sizeof(MINVETCLOT.CMF_4));

							DBU_select_minvetclot(3, &MINVETCLOT);





							//기타출고 계정으로 다시 입고할 계정 확인
							DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
							TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, "ETC_CANCLE_ACCOUNT", strlen("ETC_CANCLE_ACCOUNT"));
							//memcpy(MGCMTBLDAT_TYPE.KEY_1, MINVETCLOT.TRAN_SRC_ID, sizeof(MINVETCLOT.TRAN_SRC_ID));
							memset(c_etc_tranSrc, ' ', sizeof(c_etc_tranSrc));
							sprintf(c_etc_tranSrc, "%d", MINVETCLOT.TRAN_SRC_ID);
							memcpy(MGCMTBLDAT_TYPE.KEY_1, c_etc_tranSrc, sizeof(MGCMTBLDAT_TYPE.KEY_1));

							DBU_select_mgcmtbldat(4, &MGCMTBLDAT_TYPE);
							if (DB_error_code != DB_SUCCESS) {


								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
								TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
								TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;


							}


							//기타 입고 코드 확인
							DBU_init_cbastxndef(&CBASTXNDEF_ETC);
							TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
							CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_5, sizeof(MGCMTBLDAT_TYPE.DATA_5));
							CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2));

							DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT_3", MP_NVST);
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

							//ETC IN 한글명 가져옴
							DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
							TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
							memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
							memcpy(MGCMTBLDAT_SRC.KEY_1, "ETC_IN", strlen("ETC_IN"));
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




							//ERP 실적 - IF_INV_TXNS
							inv_if = TRS.add_node(in_node, "inv_if");
							TRS.add_char(inv_if, IN_PROCSTEP, '1');
							CopyDefaultMembers(inv_if, in_node);

							TRS.add_char(inv_if, "TRAN_FLAG", 'I');
							//TRS.add_int(inv_if, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
							//TRS.add_string(inv_if, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
							TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_40));
							TRS.add_string(inv_if, "TRAN_TYPE", "Account receipt", sizeof("Account receipt"));
							TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
							TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
							TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
							TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF_ISS.AREA_ID, sizeof(MWIPOPRDEF_ISS.AREA_ID));
							TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
							TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
							TRS.add_string(inv_if, "FROM_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
							TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
							TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);
							TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
							TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);

							DBU_init_if_inv_txns(&IF_INV_TXNS);
							TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
							memcpy(IF_INV_TXNS.MES_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

							d_ifseq = (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

							//ERP 실적 - IF_INV_TXN_LOTS
							inv_if = TRS.add_node(in_node, "inv_if");
							TRS.add_char(inv_if, IN_PROCSTEP, '1');
							CopyDefaultMembers(inv_if, in_node);

							TRS.add_char(inv_if, "TRAN_FLAG", 'I');
							TRS.add_double(inv_if, "INV_TXNS_ID", d_ifseq);
							TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
							TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
							TRS.add_string(inv_if, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
							TRS.add_string(inv_if, "MES_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)); //추후 맞는 데이터가 들어옴
							TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);

							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_IFS_INV_TXN_LOTS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);


							/*
							// 자제투입이력 삭제.
							DBU_delete_minvlotiss(1, &MINVLOTISS);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "CMN-0004");
								TRS.add_fieldmsg(out_node, "MINVLOTISS DELETE", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
								TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
								TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

								return MP_FALSE;
							}

							*/

							// 기타입고 이력 삭제.
							DBU_delete_minvetclot(1, &MINVETCLOT);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "CMN-0004");
								TRS.add_fieldmsg(out_node, "MINVETCLOT DELETE", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);

								return MP_FALSE;
							}

						}

					}




					else {
						inv_if = TRS.add_node(in_node, "inv_if");
						TRS.add_char(inv_if, IN_PROCSTEP, '1');
						CopyDefaultMembers(inv_if, in_node);

						TRS.add_char(inv_if, "TRAN_FLAG", 'I');
						TRS.add_string(inv_if, "WO_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_int(inv_if, "ERP_WO_ID", COM_atoi(MWIPORDSTS.ORD_CMF_5, sizeof(MWIPORDSTS.ORD_CMF_5)));
						TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_43));
						TRS.add_string(inv_if, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						TRS.add_int(inv_if, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
						TRS.add_string(inv_if, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
						TRS.add_int(inv_if, "ERP_SUB_AREA_ID", COM_atoi(MGCMTBLDAT_SUB_AREA.DATA_8, sizeof(MGCMTBLDAT_SUB_AREA.DATA_8)));
						TRS.add_int(inv_if, "OPER_SEQ", CWIPERPOPR.OPER_SEQ);
						TRS.add_string(inv_if, "OPER", CWIPERPOPR.OPER, sizeof(CWIPERPOPR.OPER));

						TRS.add_string(inv_if, "INV_OPER", MWIPOPRDEF_ISS.OPER_CMF_1, sizeof(MWIPOPRDEF_ISS.OPER_CMF_1));
						TRS.add_int(inv_if, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
						TRS.add_string(inv_if, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
						TRS.add_string(inv_if, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						TRS.add_double(inv_if, "QTY", MINVLOTISS.TRAN_QTY);
						TRS.add_string(inv_if, "CMF_1", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, inv_if, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						d_ifseq = TRS.get_double(cmn_out, "IF_SEQ");
						TRS.free_node(cmn_out);




					}
				}

				DBU_delete_minvlotiss(1, &MINVLOTISS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "MINVLOTISS DELETE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

					return MP_FALSE;
				}




			}
		}
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Input_Material_Lot_Validation()
- Validation Check sub function of "CUS_WIP_INPUT_MATERIAL_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Input_Material_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP VALIDATION
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"123456") == MP_FALSE)
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

	if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		return MP_FALSE;
	}

	/*
	if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		return MP_FALSE;
	}
	*/

	return MP_TRUE;
}

