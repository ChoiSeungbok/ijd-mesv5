/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_change_test_prod_lot.c
Description : 테스트, 생산품 변경

MES Version : 5.0

Function List
- step 1 :

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/02/09  wg.lee        Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Change_Test_Prod_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_CHANGE_TEST_PROD_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Change_Test_Prod_Lot()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Test_Prod_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_CHANGE_TEST_PROD_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Change_Test_Prod_Lot", out_node);
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
CUS_WIP_CHANGE_TEST_PROD_LOT()
- Main sub function of "CUS_WIP_Change_Test_Prod_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CHANGE_TEST_PROD_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	        //LOT 마스터
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;	        //LOT 마스터
	struct MWIPMATDEF_TAG MWIPMATDEF;	        //
	struct MWIPOPRDEF_TAG MWIPOPRDEF;           //
	struct MINVETCLOT_TAG MINVETCLOT;	        //
	struct CWIPINVLDM_TAG CWIPINVLDM;	        //
	struct CBASTXNDEF_TAG CBASTXNDEF;	        //
	struct CBASTXNDEF_TAG CBASTXNDEF_ETC;	    //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TYPE;      //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;       //
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;        //
	struct IF_INV_TXNS_TAG IF_INV_TXNS;         //

	struct work_date_tag work_date;
	TRSNode* adapt_in;
	TRSNode* split_in;
	TRSNode* erpif_in;
	TRSNode* unstore_in;
	// TRSNode *store_in;
	TRSNode* cmn_out;
	TRSNode** Lot_tbl;

	char s_factory[10];
	char s_oper[11];
	int i_lot_count = 0;
	char c_Store = ' ';

	// LOG
	LOG_head("CUS_WIP_Change_Test_Prod_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_oper, ' ', sizeof(s_oper));

	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	// VALIDATION CHECK
	if (CUS_WIP_Change_Test_Prod_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//step 1 : 작업시작
	if (TRS.get_procstep(in_node) == '1')
	{
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

		Lot_tbl = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (int i = 0; i < i_lot_count; i++)
		{
			c_Store = 'N';

			//lot 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
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

			//기타입고 계정 가져온다.
			//현재 LOT의 CREATE CODE를 가져와야 하기 때문에 LOT조회 바로 뒤에 있어야 함
			DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
			TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
			memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
			//TRS.copy(MGCMTBLDAT_TYPE.KEY_1, sizeof(MGCMTBLDAT_TYPE.KEY_1), Lot_tbl[i], "TO_CREATE_CODE");
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
			if (DB_error_code != DB_SUCCESS)
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

			//LOT의 공정 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

			// 공정 LOT 잠금 여부 체크
			if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
			{
				// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
				strcpy(s_msg_code, "WIP-0059");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 공정 LOT 삭제 여부 체크
			if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
			{
				// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 스토어 다 뺴버림 필요없음.
			/*
			//창고 고정에 있는 LOT만 변경 할 수 있다.
			if (MWIPOPRDEF.INV_FLAG != 'Y')
			{
				//WIP-0657 : 이 LOT은 창고에 있는 공정이 아닙니다. LOT의 공정을 확인하세요.
				strcpy(s_msg_code, "WIP-0657");
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			//LOAD된 LOT이면 변경 불가.
			DBU_init_cwipinvldm(&CWIPINVLDM);
			TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPINVLDM.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			if (DBU_select_cwipinvldm_scalar(4, &CWIPINVLDM) > 0)
			{
				//INV-0059 : 해당 자재 Lot은 투입되어 있습니다.
				strcpy(s_msg_code, "INV-0059");
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (TRS.mem_cmp(Lot_tbl[i], "TO_CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE)) != MP_FALSE)
			{
				if (MWIPLOTSTSX.INV_FLAG == 'Y')
				{
					unstore_in = TRS.add_node(in_node, "unstore_in");
					TRS.add_char(unstore_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(unstore_in, in_node);

					TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					// TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW)); 20220429 Store 안쓸예정
					TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
					// TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));
					TRS.add_string(unstore_in, "TO_OPER", s_oper, sizeof(s_oper));


					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					// c_Store = 'Y';
					memset(s_oper, ' ', sizeof(s_oper));
					memcpy(s_oper, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

					DBU_init_mwiplotstsx(&MWIPLOTSTSX);
					TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
				}

				//LOT ADAPT 처리
				adapt_in = TRS.add_node(in_node, "apt_in");
				TRS.add_char(adapt_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(adapt_in, in_node);

				TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
				TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_string(adapt_in, "TO_MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
				TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);

				if (TRS.mem_cmp(Lot_tbl[i], "TO_CREATE_CODE", MP_CREATE_CODE_PROD, strlen(MP_CREATE_CODE_PROD)) == MP_FALSE)
				{
					TRS.add_char(adapt_in, "LOT_TYPE", MP_LOT_TYPE_P);
					TRS.add_string(adapt_in, "OWNER_CODE", MP_OWNER_CODE_PROD, strlen(MP_OWNER_CODE_PROD));
				}
				else
				{
					TRS.add_char(adapt_in, "LOT_TYPE", MP_LOT_TYPE_T);
					TRS.add_string(adapt_in, "OWNER_CODE", MP_OWNER_CODE_DEVE, strlen(MP_OWNER_CODE_DEVE));
				}
				TRS.add_nstring(adapt_in, "TRAN_CMF_3", "PROD_CHANGE");  // 양산품변경  표기용도
				TRS.add_nstring(adapt_in, "CREATE_CODE", TRS.get_string(Lot_tbl[i], "TO_CREATE_CODE"));
				TRS.add_nstring(adapt_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				//Store 제거
				/*
				if (c_Store == 'Y')
				{
					// TO 창고로 STORE
					store_in = TRS.add_node(in_node, "store_in");
					TRS.add_char(store_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(store_in, in_node);

					TRS.add_string(store_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(store_in, "TO_OPER", s_oper, sizeof(s_oper));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);

					DBU_init_mwiplotstsx(&MWIPLOTSTSX);
					TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
				}
				*/

				//ctm의 가공 (CW-L/P-H, CW-RUD-QC)의 OPER_CMF_10이 공백이 아닌경우 LOT의 첫번째 자리를 
				//C로 변경한다. _문종재 과장 요청
				if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, strlen(gs_area_ctm)) == MP_FALSE)
				{
					//연구소에서 만든 lot이 아닌 경우
					// -> 연구소에먼 만든 lot은 변경 할지 여부를 확인한다. 
					if (MWIPLOTSTSX.LOT_ID[0] != 'R')
					{
						//공정 셋업(OPER_CMF_10)의 양품전환 글자 세팅에 첫글자로 변경한다. 
						if (MWIPOPRDEF.OPER_CMF_10[0] != ' ')
						{

							if (MWIPOPRDEF.OPER_CMF_10[0] != MWIPLOTSTSX.LOT_ID[0]) {
								//쿼리에서 split될 lot id 를 가져온다.
								DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
								memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
								MWIPLOTSTSX_SPLIT.LOT_ID[0] = MWIPOPRDEF.OPER_CMF_10[0];

								split_in = TRS.add_node(in_node, "split_in");
								CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

								TRS.add_char(split_in, "PROCSTEP", '1');
								TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
								TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
								TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
								TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTSX.QTY_1);
								TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "LOSS_COMMENT"));
								TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);

								cmn_out = TRS.create_node("Cmn_Out");
								if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
								{
									TRS.clone(out_node, cmn_out);
									TRS.free_node(cmn_out);
									return MP_FALSE;
								}
								TRS.free_node(cmn_out);

								//split된 lot을 조회한다. 
								DBU_init_mwiplotstsx(&MWIPLOTSTSX);
								memcpy(MWIPLOTSTSX.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
								DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
							}


						}
					}
				}

				if (TRS.mem_cmp(Lot_tbl[i], "TO_CREATE_CODE", MP_CREATE_CODE_PROD, strlen(MP_CREATE_CODE_PROD)) == MP_FALSE)
				{
					DBU_init_mwipmatdef(&MWIPMATDEF);
					TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;
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

					//TO AREA 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
					TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
					memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
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
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					DBU_init_cbastxndef(&CBASTXNDEF);
					TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
					CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
					CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
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
						CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
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
					CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_2, sizeof(MGCMTBLDAT_TYPE.DATA_2));
					CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
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

					//기타입고 정보 저장
					DBU_init_minvetclot(&MINVETCLOT);
					TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(MINVETCLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));


					DBU_select_minvetclot(2, &MINVETCLOT);
					//20221212 SEQ 증가 추가  양산품이 테스트품 작지 들어갔다가 다시 양산품되는 경우 있음.
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
					MINVETCLOT.QTY = MWIPLOTSTSX.QTY_1;
					memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
					memcpy(MINVETCLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					memcpy(MINVETCLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
					memcpy(MINVETCLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					memset(MINVETCLOT.VENDOR_ID, ' ', sizeof(MINVETCLOT.VENDOR_ID));
					MINVETCLOT.VENDOR_SITE_ID = 0;
					memset(MINVETCLOT.VENDOR_LOT_ID, ' ', sizeof(MINVETCLOT.VENDOR_LOT_ID));
					memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_IN, sizeof(MINVETCLOT.ETC_TYPE));
					memcpy(MINVETCLOT.ETC_DATE, work_date.s_work_date, sizeof(work_date.s_work_date));
					MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
					memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
					memcpy(MINVETCLOT.ETC_COMMENT, MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

					//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
					//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS),E(개발품 양산품으로 전환)
					memcpy(MINVETCLOT.CMF_1, "A", strlen("A"));
					memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
					memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));


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
					erpif_in = TRS.add_node(in_node, "erpif_in");
					TRS.add_char(erpif_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(erpif_in, in_node);

					TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
					TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
					TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
					TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
					TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
					TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
					TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
					TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
					TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
					TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //추후 이동지시번호가 들어올예정

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
					memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

					//ERP 실적 - IF_INV_TXN_LOTS
					erpif_in = TRS.add_node(in_node, "erpif_in");
					TRS.add_char(erpif_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(erpif_in, in_node);

					TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
					TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
					TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
					TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //추후 이동지시번호가 들어올예정
					TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
			}
		}
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Change_Test_Prod_Lot_Validation()
- Validation Check sub function of "CUS_WIP_CHANGE_TEST_PROD_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Test_Prod_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP VALIDATION
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"1") == MP_FALSE)
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


	return MP_TRUE;
}
