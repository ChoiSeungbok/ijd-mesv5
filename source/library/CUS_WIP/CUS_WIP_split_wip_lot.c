/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_split_wip_lot.c
Description : Tran split Wip Lot function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/27  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Split_Wip_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_split_Wip_Lot()
- Tran split Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Wip_Lot(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_SPLIT_WIP_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Split_Wip_Lot", out_node);
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
CUS_WIP_SPLIT_LOT()
- Main sub function of "CUS_WIP_Split_Wip_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_SPLIT_WIP_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;

	struct work_date_tag work_date;
	TRSNode* split_in;
	TRSNode* gen_in_node;
	TRSNode* cmn_out;
	TRSNode** Lot_tbl;
	TRSNode* list_item;
	TRSNode* adapt_in;
	TRSNode* merge_in;

	char s_factory[10];
	int i_lot_count = 0;
	int i = 0;
	double d_lot_qty = 0;
	char s_lot_id[26];
	char s_new_lot_id[26];

	LOG_head("CUS_WIP_Split_Wip_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	if (CUS_WIP_Split_Wip_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	gb_multi_transaction = MP_TRUE;
	memset(gs_multi_tran_key, 0x00, sizeof(gs_multi_tran_key));
	COM_generate_multi_tran_key(gs_multi_tran_key);

	if (TRS.get_procstep(in_node) == '1')
	{
		//모lot 조회
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

		//LOT 삭제여부 체크
		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 잠금 여부 체크
		if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
		{
			// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);

		//20250526 GRT 물류에서 요청함, 생산에서 물류제품창고의 재고를 분할하고 가지고 가는 경우가 있어서. 막음.
		if (memcmp(MWIPOPRDEF.OPER_CMF_2, "N", strlen("N"))==0)
		{
			// WIP-0699 :분할병합을 진행할수 없는 공정입니다.확인바랍니다.
			strcpy(s_msg_code, "WIP-0699");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 2) 자LOT SPLIT
		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
			i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

			for (i = 0; i < i_lot_count; i++)
			{
				if (i != 0)
				{
					//모lot 을 재 조회 한다. 
					DBU_init_mwiplotstsx(&MWIPLOTSTSX);
					TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
				}

				// 소수점이어서 계산 시 5자리 반올림하여 계산 진행
				d_lot_qty = COM_dbl_round(MWIPLOTSTSX.QTY_1, 5, 'U');

				if (d_lot_qty < TRS.get_double(Lot_tbl[i], "QTY_1"))
				{
					// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
					strcpy(s_msg_code, "INV-0021");
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_grt, strlen(gs_area_grt)) == 0)
				{
					//GRIT 사업부는 -001로 분할. ORIGINAL LOT ID를 이용하여 분할 처리
					memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));

					if (TRS.get_char(Lot_tbl[i], "ADD_CHAR_FLAG") == 'Y')
					{
						//split lot id
						sprintf(s_new_lot_id, "%.*s%s", COM_len_space(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)), MWIPLOTSTSX.LOT_ID,
							TRS.get_string(Lot_tbl[i], "ADD_LOT_CHAR"));

						//lot 중복여부 조회
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_new_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
						if (DB_error_code == DB_SUCCESS)
						{
							//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
							strcpy(s_msg_code, "WIP-0045");
							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
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
						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);

						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
						TRS.add_string(gen_in_node, "LOT_ID", MWIPLOTSTSX.RESV_FIELD_3, strlen(MWIPLOTSTSX.RESV_FIELD_3));

						cmn_out = TRS.create_node("cmn_out");
						if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}






						memcpy(s_new_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
					}

					//lot 중복여부 조회
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
					memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_new_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
					if (DB_error_code == DB_SUCCESS)
					{


						//GRT은 기존에 진행되었던 LOT들로도 LOT을 변경해야되는 경우가 있음..일단 삭제된LOT이면 변경가능하도록 수정(25/04/14 syw)
						if (MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG == 'Y')
						{


							MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG = ' ';  //품변으로 다시 투입될것이기에 플래그 Y (20211122)
							DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

							//TRS.free_node(cmn_out);

							//LOT ADAPT 처리(속성변경)
							adapt_in = TRS.add_node(in_node, "adapt_in");
							TRS.add_char(adapt_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(adapt_in, in_node);

							TRS.add_string(adapt_in, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
							TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
							TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
							TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
							TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
							TRS.add_string(adapt_in, "TO_MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
							TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
							TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
							TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
							TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
							TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
							TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
							TRS.add_nstring(adapt_in, "TRAN_CMF_3", "LOT_CHANGE");  // LOT변경 표기용도
							TRS.add_double(adapt_in, "QTY_1", 0);
							TRS.add_string(adapt_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
							TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
							//KGAUO06-002
							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);


							DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
							MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG = ' ';
							DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

							TRS.free_node(cmn_out);



							merge_in = TRS.add_node(in_node, "merge_in");
							TRS.add_char(merge_in, IN_PROCSTEP, '1');
							CopyDefaultMembers(merge_in, in_node);

							TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
							TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTSX.QTY_1);
							TRS.add_nstring(merge_in, "TRAN_CMF_3", "LOT_CHANGE");  // LOT변경 표기용도


							cmn_out = TRS.create_node("Cmn_Out");
							if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
							{
								TRS.clone(out_node, cmn_out);
								TRS.free_node(cmn_out);
								return MP_FALSE;
							}
							TRS.free_node(cmn_out);

						}
						else
						{

							//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
							strcpy(s_msg_code, "WIP-0045");
							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
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

						//자 LOT ID 채번
						split_in = TRS.add_node(in_node, "split_in");
						CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

						TRS.add_char(split_in, "PROCSTEP", '1');
						TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_string(split_in, "CHILD_LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
						TRS.add_string(split_in, "CHILD_LOT_DESC", s_new_lot_id, sizeof(s_new_lot_id));
						TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1")); // QTY_1 유효중량
						TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
						TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량
						TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTSTSX.RESV_FIELD_3));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);


					}





					//포장까지 진행된 경우 CPAKLOTSTS 수정 20230726


	// CPAKLOTSTS - 포장 LOT 정보 조회
					DBU_init_cpaklotsts(&CPAKLOTSTS);
					TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), in_node, "LOT_ID");	// LOT
					DBU_select_cpaklotsts(6, &CPAKLOTSTS);

					if (DB_error_code == DB_SUCCESS)
					{


						//모lot 조회
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


						//모LOT 포장수량 수정
						TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
						CPAKLOTSTS.QTY = MWIPLOTSTSX.QTY_1;

						DBU_update_cpaklotsts(8, &CPAKLOTSTS);

						if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
							TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_INT, CPAKLOTSTS.PACK_LOT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						//자LOT 포장정보 INSERT
						TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
						// memcpy(CPAKLOTSTS.PACK_LOT_ID, s_lot_id, sizeof(CPAKLOTSTS.PACK_LOT_ID));
					  //  memcpy(CPAKLOTSTS.PACK_LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						memcpy(CPAKLOTSTS.PACK_LOT_ID, s_new_lot_id, sizeof(CPAKLOTSTS.PACK_LOT_ID));

						CPAKLOTSTS.QTY = TRS.get_double(Lot_tbl[i], "QTY_1");

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


					list_item = TRS.add_node(out_node, "LOT_TBL");
					TRS.add_string(list_item, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
					TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_double(list_item, "QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
				}
				//W-CUT-H
				else
				{
					if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0 &&
						memcmp(MWIPOPRDEF.OPER_CMF_1, "W-CUT-H", strlen("W-CUT-H")) == MP_FALSE)
					{
						memset(s_lot_id, ' ', sizeof(s_lot_id));

						//공정OPTION의 ID 발번 규칙(DATA_3)에 등록된 ID 발번 규칙으로 해당 공정의 LOT ID를 채번한다.
						gen_in_node = TRS.add_node(in_node, "gen_in_node");
						TRS.add_char(gen_in_node, "PROCSTEP", '2');
						CopyDefaultMembers(gen_in_node, in_node);
						TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
						//TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));
						TRS.add_string(gen_in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
						//사업부별 채번룰의 SEQ가 1번이 되는 경우 FLOW로 사업부를 파라미터로 넘겨 SEQ를 채번한다.
						TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
						TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
						TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
						TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
						TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
						TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
						TRS.free_node(cmn_out);

						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					}
					else
					{
						//쿼리에서 split될 lot id 를 가져온다.
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
						memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						DBU_select_mwiplotstsx(3, &MWIPLOTSTSX_SPLIT);
						if (DB_error_code != DB_SUCCESS)
						{
							memset(s_lot_id, ' ', sizeof(s_lot_id));
							sprintf(s_lot_id, MWIPLOTSTSX.LOT_ID, "-01");
							sprintf(s_lot_id, "%.*s-01", COM_len_space(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)), MWIPLOTSTSX.LOT_ID);
							memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						}
					}

					//자 LOT ID 채번
					split_in = TRS.add_node(in_node, "split_in");
					CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(split_in, "PROCSTEP", '1');
					TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_string(split_in, "CHILD_LOT_DESC", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1")); // QTY_1 유효중량
					TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
					TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량
					TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTSTSX.RESV_FIELD_3));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);


					//포장까지 진행된 경우 CPAKLOTSTS 수정 20230726


					// CPAKLOTSTS - 포장 LOT 정보 조회
					DBU_init_cpaklotsts(&CPAKLOTSTS);
					TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), in_node, "LOT_ID");	// LOT
					DBU_select_cpaklotsts(6, &CPAKLOTSTS);

					if (DB_error_code == DB_SUCCESS)
					{


						//모lot 조회
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


						//모LOT 포장수량 수정
						TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
						CPAKLOTSTS.QTY = MWIPLOTSTSX.QTY_1;

						DBU_update_cpaklotsts(8, &CPAKLOTSTS);

						if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
							TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_INT, CPAKLOTSTS.PACK_LOT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						//자LOT 포장정보 INSERT
						TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
						// memcpy(CPAKLOTSTS.PACK_LOT_ID, s_lot_id, sizeof(CPAKLOTSTS.PACK_LOT_ID));
						memcpy(CPAKLOTSTS.PACK_LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
						CPAKLOTSTS.QTY = TRS.get_double(Lot_tbl[i], "QTY_1");

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







					list_item = TRS.add_node(out_node, "LOT_TBL");
					TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
					TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_double(list_item, "QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
				}
			}
	}


	if (TRS.get_procstep(in_node) == '2')
	{
		//모lot 조회
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

		//LOT 삭제여부 체크
		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 잠금 여부 체크F
		if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
		{
			// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);


		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "CHILD_LOT_ID");

		DBU_select_minvlotsts(1, &MINVLOTSTS);


		//원재료로 존재하는 LOT은 변경불가.
		if (DB_error_code == DB_SUCCESS)
		{
			//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0045");
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.LOT_ID), MINVLOTSTS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		if (COM_isnullspace(TRS.get_string(in_node, "CHILD_LOT_ID")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "CHILDXXX", MP_NVST);
			TRS.add_fieldmsg(out_node, "CHILD_LOT_ID", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			return MP_FALSE;
		}

		//q변경LOT 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
		TRS.copy(MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), in_node, "CHILD_LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
		if (DB_error_code != DB_SUCCESS)
		{
			split_in = TRS.add_node(in_node, "split_in");
			CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(split_in, "PROCSTEP", '1');

			TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_nstring(split_in, "CHILD_LOT_ID", TRS.get_string(in_node, "CHILD_LOT_ID"));
			TRS.add_nstring(split_in, "CHILD_LOT_DESC", TRS.get_string(in_node, "CHILD_LOT_ID"));
			TRS.add_double(split_in, "MOVE_QTY_1", TRS.get_double(in_node, "MOVE_QTY_1")); // QTY_1 유효중량
			TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
			TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량
			TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

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
			//GRT은 기존에 진행되었던 LOT들로도 LOT을 변경해야되는 경우가 있음..일단 삭제된LOT이면 변경가능하도록 수정(25/04/14 syw)
			if (MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG == 'Y')
			{
				MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG = ' ';  //품변으로 다시 투입될것이기에 플래그 Y (20211122)
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

				//TRS.free_node(cmn_out);

				//LOT ADAPT 처리(속성변경)
				adapt_in = TRS.add_node(in_node, "adapt_in");
				TRS.add_char(adapt_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(adapt_in, in_node);

				TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
				TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_string(adapt_in, "TO_MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
				TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
				TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
				TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
				TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
				TRS.add_nstring(adapt_in, "TRAN_CMF_3", "LOT_CHANGE");  // LOT변경 표기용도
				TRS.add_double(adapt_in, "QTY_1", 0);
				TRS.add_string(adapt_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
				TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
				//KGAUO06-002
				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
				MWIPLOTSTSX_SPLIT.QTY_1 = 0;
				MWIPLOTSTSX_SPLIT.LOT_DEL_FLAG = ' ';
				DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);

				//TRS.free_node(cmn_out);

			

				merge_in = TRS.add_node(in_node, "merge_in");
				TRS.add_char(merge_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(merge_in, in_node);

				TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
				TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTSX.QTY_1);
				TRS.add_nstring(merge_in, "TRAN_CMF_3", "LOT_CHANGE");  // LOT변경 표기용도


				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

			}
			else
			{

				//WIP-0045 : 이 LOT은 이미 존재 합니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0045");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

		}



		list_item = TRS.add_node(out_node, "LOT_TBL");
		TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
		TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_double(list_item, "QTY_1", TRS.get_double(in_node, "MOVE_QTY_1"));


	}

	return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Split_Wip_Lot_Validation()
- Validation Check sub function of "CUS_WIP_SPLIT_WIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Wip_Lot_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	// PROCSTEP VALIDATION
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
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
	// LOT ID VALIDATION
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