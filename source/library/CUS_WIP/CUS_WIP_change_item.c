/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_change_item.c
Description : Chagne Item

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/26  JS.SEO        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Change_Item_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Change_Item_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_Change_Item_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_Change_Item()
- Tran Terminate Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Item(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_CHANGE_ITEM_MAIN(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Change_Item", out_node);

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
CUS_WIP_CHANGE_ITEM()
- Main sub function of "CUS_WIP_Change_Item" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CHANGE_ITEM_MAIN(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	TRSNode* change_in_node;
	TRSNode** change_lot_list;
	TRSNode* change_list;

	int i = 0;

	LOG_head("CUS_WIP_Change_Item");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_Change_Item_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	change_lot_list = TRS.get_list(in_node, "CHANGE_LIST");

	change_in_node = TRS.add_node(in_node, "change_in_node");
	CopyDefaultMembers(change_in_node, in_node);
	TRS.add_char(change_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	for (i = 0; i < TRS.get_item_count(in_node, "CHANGE_LIST"); i++)
	{
		change_list = TRS.add_node(change_in_node, "CHANGE_LOT_LIST");
		TRS.add_nstring(change_list, "BEFORE_MAT_ID", TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));
		TRS.add_nstring(change_list, "BEFORE_LOT_ID", TRS.get_string(change_lot_list[i], "BEFORE_LOT_ID"));
		TRS.add_nstring(change_list, "BEFORE_OPER", TRS.get_string(change_lot_list[i], "BEFORE_OPER"));
		TRS.add_nstring(change_list, "AFTER_OPER", TRS.get_string(change_lot_list[i], "AFTER_OPER"));
		TRS.add_nstring(change_list, "AFTER_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));
		TRS.add_nstring(change_list, "AFTER_LOT_ID", TRS.get_string(change_lot_list[i], "AFTER_LOT_ID"));
		TRS.add_nstring(change_list, "AFTER_OPER", TRS.get_string(change_lot_list[i], "AFTER_OPER"));
		TRS.add_char(change_list, "CHANGE_FLAG", TRS.get_char(change_lot_list[i], "CHANGE_FLAG"));
		TRS.add_double(change_list, "UNIT_PRICE", TRS.get_double(change_lot_list[i], "UNIT_PRICE"));

	}

	if (CUS_WIP_Change_Item_Before_Transaction(s_msg_code, 0, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_CHANGE_ITEM(s_msg_code, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	change_in_node = TRS.add_node(in_node, "change_in_node");
	CopyDefaultMembers(change_in_node, in_node);
	TRS.add_char(change_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	change_lot_list = TRS.get_list(out_node, "CHANGE_LIST");

	for (i = 0; i < TRS.get_item_count(out_node, "CHANGE_LIST"); i++)
	{
		change_list = TRS.add_node(change_in_node, "CHANGE_LOT_LIST");
		TRS.add_nstring(change_list, "BEFORE_MAT_ID", TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));
		TRS.add_nstring(change_list, "BEFORE_LOT_ID", TRS.get_string(change_lot_list[i], "BEFORE_LOT_ID"));
		TRS.add_nstring(change_list, "BEFORE_OPER", TRS.get_string(change_lot_list[i], "BEFORE_OPER"));
		TRS.add_nstring(change_list, "AFTER_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));
		TRS.add_nstring(change_list, "AFTER_LOT_ID", TRS.get_string(change_lot_list[i], "AFTER_LOT_ID"));
		TRS.add_nstring(change_list, "AFTER_OPER", TRS.get_string(change_lot_list[i], "AFTER_OPER"));
		TRS.add_double(change_list, "UNIT_PRICE", TRS.get_double(change_lot_list[i], "UNIT_PRICE"));
	}

	if (CUS_WIP_Change_Item_After_Transaction(s_msg_code, 0, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_CHANGE_ITEM()
- Main sub function of "CUS_WIP_Change_Item" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CHANGE_ITEM(char* s_msg_code,
	TRSNode* in_node,
	TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_AF;
	struct CWIPLOTCHG_TAG CWIPLOTCHG;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

	TRSNode** change_lot_list;
	TRSNode* split_in;
	TRSNode* adapt_in;
	TRSNode* unstore_in;
	// TRSNode *store_in;
	TRSNode* cmn_out;
	TRSNode* list_item;

	char s_lot_id[26];
	char s_oper[11];
	char c_Store = ' ';

	int i;

	memset(s_oper, ' ', sizeof(s_oper));

	change_lot_list = TRS.get_list(in_node, "CHANGE_LOT_LIST");

	//일반 품목변경
	if (TRS.get_procstep(in_node) == '1')
	{

		for (i = 0; i < TRS.get_item_count(in_node, "CHANGE_LOT_LIST"); i++)
		{
			c_Store = 'N';

			//LOT이 존재하는지 확인
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "BEFORE_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
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
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);


				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//공정 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

			// 현재 LOT의 MAT_ID가 Client에서 던진 BEFORE_MAT_ID와 같은지 확인
			if (memcmp(MWIPLOTSTSX.MAT_ID, TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"), strlen(TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"))) != 0)
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
				TRS.add_fieldmsg(out_node, "CLIENT BEFORE_MAT_ID", MP_STR, strlen(TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID")), TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 또는 이미 변경되었을수도 있기 때문에 Client에서 던진 AFTER_MAT_ID와 같은지도 확인
			if (memcmp(MWIPLOTSTSX.MAT_ID, TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"), strlen(TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"))) == 0)
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
				TRS.add_fieldmsg(out_node, "CLIENT AFTER_MAT_ID", MP_STR, strlen(TRS.get_string(change_lot_list[i], "AFTER_MAT_ID")), TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//CASE 1 : LOT을 새로 생성(수기입력 마찬가지) -> SPLIT후 해당 LOT 생성 -> ADAPT로 속성변경
			//CASE 2 : 기존 LOT사용 -> ADAPT로 속성변경
			//CHANE_FLAG
			//N : 새로 LOT채번, I : 수기입력, E : 기존 LOT번호 사용
			memset(s_lot_id, ' ', sizeof(s_lot_id));

			if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'N')
			{
				//생성 로직은 아직 미확정
			}
			else if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'I')
			{
				//수기입력인데 변경할 LOT_ID가 없는경우 에러
				if (COM_isnullspace(TRS.get_string(change_lot_list[i], "AFTER_LOT_ID")) == MP_TRUE)
				{
					//WIP-0614 : 수기입력의 경우 변경할 LOT_ID가 존재해야합니다.
					strcpy(s_msg_code, "WIP-0614");
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				TRS.copy(s_lot_id, sizeof(s_lot_id), change_lot_list[i], "AFTER_LOT_ID");
			}
			else if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'E')
			{
			}
			else
			{
				//WIP-0615 : LOT생성방식이 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0615");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//LOT_ID새로생기는 경우만 스플릿
			if (COM_isnullspace(s_lot_id) != MP_TRUE)
			{
				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node);

				TRS.add_char(split_in, "PROCSTEP", '1');
				TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
				TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
				TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTSX.QTY_1);

				TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량
				TRS.add_string(split_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

			if (MWIPLOTSTSX.INV_FLAG == 'Y')
			{
				unstore_in = TRS.add_node(in_node, "unstore_in");
				TRS.add_char(unstore_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(unstore_in, in_node);

				TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				//   TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
				TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				c_Store = 'Y';
				memset(s_oper, ' ', sizeof(s_oper));
				memcpy(s_oper, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "BEFORE_LOT_ID");
				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			}






			//LOT ADAPT 처리(속성변경)
			adapt_in = TRS.add_node(in_node, "adapt_in");
			TRS.add_char(adapt_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(adapt_in, in_node);

			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				TRS.add_string(adapt_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
			else
				TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

			TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
			TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_nstring(adapt_in, "TO_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));
			TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
			TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
			TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
			TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
			TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
			TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
			TRS.add_nstring(adapt_in, "TRAN_CMF_3", "MAT_CHANGE");  // 품목 변경 표기용도
			TRS.add_string(adapt_in, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
			TRS.add_string(adapt_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//lot 테이블 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				memcpy(MWIPLOTSTSX_AF.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			else
				memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);


			// 20220429 Store 제거 
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
			}

			*/

			//품목변경 이력 저장 (CWIPLOTCHG)
			DBU_init_cwiplotchg(&CWIPLOTCHG);
			TRS.copy(CWIPLOTCHG.FACTORY, sizeof(CWIPLOTCHG.FACTORY), in_node, IN_FACTORY);

			//변경되는 lot을 lot id로 본다.    
			memcpy(CWIPLOTCHG.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(CWIPLOTCHG.LOT_ID));
			CWIPLOTCHG.HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ; // 재 조회해서 seq 넣어줄것.

			memcpy(CWIPLOTCHG.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(CWIPLOTCHG.ORDER_ID));
			memcpy(CWIPLOTCHG.FLOW, MWIPLOTSTSX.FLOW, sizeof(CWIPLOTCHG.FLOW));
			memcpy(CWIPLOTCHG.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CWIPLOTCHG.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			memcpy(CWIPLOTCHG.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(CWIPLOTCHG.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			TRS.copy(CWIPLOTCHG.FROM_MAT_ID, sizeof(CWIPLOTCHG.FROM_MAT_ID), change_lot_list[i], "BEFORE_MAT_ID");
			CWIPLOTCHG.FROM_MAT_VER = MWIPLOTSTSX.MAT_VER;
			TRS.copy(CWIPLOTCHG.TO_MAT_ID, sizeof(CWIPLOTCHG.TO_MAT_ID), change_lot_list[i], "AFTER_MAT_ID");
			CWIPLOTCHG.TO_MAT_VER = MWIPLOTSTSX_AF.MAT_VER;
			CWIPLOTCHG.QRY_1 = MWIPLOTSTSX.QTY_1;
			memcpy(CWIPLOTCHG.CMF_1, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //원래 lot을 저장

			TRS.copy(CWIPLOTCHG.CREATE_USER_ID, sizeof(CWIPLOTCHG.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTCHG.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCHG.CREATE_TIME));
			TRS.copy(CWIPLOTCHG.UPDATE_USER_ID, sizeof(CWIPLOTCHG.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTCHG.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCHG.UPDATE_TIME));

			DBU_insert_cwiplotchg(&CWIPLOTCHG);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTCHG INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCHG.FACTORY), CWIPLOTCHG.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCHG.LOT_ID), CWIPLOTCHG.LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPLOTCHG.ORDER_ID), CWIPLOTCHG.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTCHG.OPER), CWIPLOTCHG.OPER);
				TRS.add_fieldmsg(out_node, "FROM_MAT_ID", MP_STR, sizeof(CWIPLOTCHG.FROM_MAT_ID), CWIPLOTCHG.FROM_MAT_ID);
				TRS.add_fieldmsg(out_node, "TO_MAT_ID", MP_STR, sizeof(CWIPLOTCHG.TO_MAT_ID), CWIPLOTCHG.TO_MAT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			//품목 속성변경 후 LOT의 리스트를 보낸다.
			list_item = TRS.add_node(out_node, "CHANGE_LIST");
			TRS.add_nstring(list_item, "BEFORE_LOT_ID", TRS.get_string(change_lot_list[i], "BEFORE_LOT_ID"));
			TRS.add_nstring(list_item, "BEFORE_MAT_ID", TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));
			TRS.add_nstring(list_item, "AFTER_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));

			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				TRS.add_string(list_item, "AFTER_LOT_ID", s_lot_id, sizeof(s_lot_id));
			else
				TRS.add_string(list_item, "AFTER_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		}
	}
	//타사업부 품목으로 품목변경(자동내부거래) 20230620 추가
	else if (TRS.get_procstep(in_node) == '2') {
		for (i = 0; i < TRS.get_item_count(in_node, "CHANGE_LOT_LIST"); i++)
		{
			c_Store = 'N';

			//LOT이 존재하는지 확인
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "BEFORE_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
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
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);


				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//공정 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

			// 현재 LOT의 MAT_ID가 Client에서 던진 BEFORE_MAT_ID와 같은지 확인
			if (memcmp(MWIPLOTSTSX.MAT_ID, TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"), strlen(TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"))) != 0)
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
				TRS.add_fieldmsg(out_node, "CLIENT BEFORE_MAT_ID", MP_STR, strlen(TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID")), TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 또는 이미 변경되었을수도 있기 때문에 Client에서 던진 AFTER_MAT_ID와 같은지도 확인
			if (memcmp(MWIPLOTSTSX.MAT_ID, TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"), strlen(TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"))) == 0)
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
				TRS.add_fieldmsg(out_node, "CLIENT AFTER_MAT_ID", MP_STR, strlen(TRS.get_string(change_lot_list[i], "AFTER_MAT_ID")), TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//CASE 1 : LOT을 새로 생성(수기입력 마찬가지) -> SPLIT후 해당 LOT 생성 -> ADAPT로 속성변경
			//CASE 2 : 기존 LOT사용 -> ADAPT로 속성변경
			//CHANE_FLAG
			//N : 새로 LOT채번, I : 수기입력, E : 기존 LOT번호 사용
			memset(s_lot_id, ' ', sizeof(s_lot_id));

			if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'N')
			{
				//생성 로직은 아직 미확정
			}
			else if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'I')
			{
				//수기입력인데 변경할 LOT_ID가 없는경우 에러
				if (COM_isnullspace(TRS.get_string(change_lot_list[i], "AFTER_LOT_ID")) == MP_TRUE)
				{
					//WIP-0614 : 수기입력의 경우 변경할 LOT_ID가 존재해야합니다.
					strcpy(s_msg_code, "WIP-0614");
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				TRS.copy(s_lot_id, sizeof(s_lot_id), change_lot_list[i], "AFTER_LOT_ID");
			}
			else if (TRS_get_char(change_lot_list[i], "CHANGE_FLAG") == 'E')
			{
			}
			else
			{
				//WIP-0615 : LOT생성방식이 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0615");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//LOT_ID새로생기는 경우만 스플릿
			if (COM_isnullspace(s_lot_id) != MP_TRUE)
			{
				split_in = TRS.add_node(in_node, "split_in");
				CopyDefaultMembers(split_in, in_node);

				TRS.add_char(split_in, "PROCSTEP", '1');
				TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
				TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
				TRS.add_double(split_in, "MOVE_QTY_1", MWIPLOTSTSX.QTY_1);

				TRS.add_double(split_in, "PRE_QTY_1", MWIPLOTSTSX.QTY_1);   //split 전 모랏의 총 수량

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

			if (MWIPLOTSTSX.INV_FLAG == 'Y')
			{
				unstore_in = TRS.add_node(in_node, "unstore_in");
				TRS.add_char(unstore_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(unstore_in, in_node);

				TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				//   TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTSX.STR_RET_FLOW, sizeof(MWIPLOTSTSX.STR_RET_FLOW));
				TRS.add_string(unstore_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
				TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPLOTSTSX.STR_RET_OPER));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				c_Store = 'Y';
				memset(s_oper, ' ', sizeof(s_oper));
				memcpy(s_oper, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

				DBU_init_mwiplotstsx(&MWIPLOTSTSX);
				TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "BEFORE_LOT_ID");
				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			}






			//LOT ADAPT 처리(속성변경)
			adapt_in = TRS.add_node(in_node, "adapt_in");
			TRS.add_char(adapt_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(adapt_in, in_node);

			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				TRS.add_string(adapt_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
			else
				TRS.add_string(adapt_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

			TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_string(adapt_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
			TRS.add_string(adapt_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			//TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_string(adapt_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
			TRS.add_nstring(adapt_in, "TO_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));
			TRS.add_int(adapt_in, "TO_MAT_VER", MWIPLOTSTSX.MAT_VER);
			//TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
			TRS.add_nstring(adapt_in, "TO_OPER", TRS.get_string(change_lot_list[i], "AFTER_OPER"));

			TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTSX.LOT_TYPE);
			TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTSX.LOT_PRIORITY);
			TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
			TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTSX.OWNER_CODE, sizeof(MWIPLOTSTSX.OWNER_CODE));
			TRS.add_nstring(adapt_in, "TRAN_CMF_3", "MAT_CHANGE");  // 품목 변경 표기용도

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//lot 테이블 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				memcpy(MWIPLOTSTSX_AF.LOT_ID, s_lot_id, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			else
				memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);


			// 20220429 Store 제거 
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
			}

			*/

			//품목변경 이력 저장 (CWIPLOTCHG)
			DBU_init_cwiplotchg(&CWIPLOTCHG);
			TRS.copy(CWIPLOTCHG.FACTORY, sizeof(CWIPLOTCHG.FACTORY), in_node, IN_FACTORY);

			//변경되는 lot을 lot id로 본다.    
			memcpy(CWIPLOTCHG.LOT_ID, MWIPLOTSTSX_AF.LOT_ID, sizeof(CWIPLOTCHG.LOT_ID));
			CWIPLOTCHG.HIST_SEQ = MWIPLOTSTSX_AF.LAST_ACTIVE_HIST_SEQ; // 재 조회해서 seq 넣어줄것.

			memcpy(CWIPLOTCHG.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(CWIPLOTCHG.ORDER_ID));
			memcpy(CWIPLOTCHG.FLOW, MWIPLOTSTSX.FLOW, sizeof(CWIPLOTCHG.FLOW));
			memcpy(CWIPLOTCHG.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CWIPLOTCHG.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			memcpy(CWIPLOTCHG.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(CWIPLOTCHG.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			TRS.copy(CWIPLOTCHG.FROM_MAT_ID, sizeof(CWIPLOTCHG.FROM_MAT_ID), change_lot_list[i], "BEFORE_MAT_ID");
			CWIPLOTCHG.FROM_MAT_VER = MWIPLOTSTSX.MAT_VER;
			TRS.copy(CWIPLOTCHG.TO_MAT_ID, sizeof(CWIPLOTCHG.TO_MAT_ID), change_lot_list[i], "AFTER_MAT_ID");
			CWIPLOTCHG.TO_MAT_VER = MWIPLOTSTSX_AF.MAT_VER;
			CWIPLOTCHG.QRY_1 = MWIPLOTSTSX.QTY_1;
			memcpy(CWIPLOTCHG.CMF_1, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID)); //원래 lot을 저장
			TRS.copy(CWIPLOTCHG.CMF_2, sizeof(CWIPLOTCHG.CMF_2), change_lot_list[i], "AFTER_AREA");
			TRS.copy(CWIPLOTCHG.CMF_3, sizeof(CWIPLOTCHG.CMF_3), change_lot_list[i], "AFTER_OPER");
			TRS.copy(CWIPLOTCHG.CMF_4, sizeof(CWIPLOTCHG.CMF_4), change_lot_list[i], "REQUESTS_IF_YN");
			TRS.copy(CWIPLOTCHG.CMF_5, sizeof(CWIPLOTCHG.CMF_5), change_lot_list[i], "RECEIPTS_IF_YN");

			TRS.copy(CWIPLOTCHG.CREATE_USER_ID, sizeof(CWIPLOTCHG.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTCHG.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTCHG.CREATE_TIME));
			TRS.copy(CWIPLOTCHG.UPDATE_USER_ID, sizeof(CWIPLOTCHG.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPLOTCHG.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTCHG.UPDATE_TIME));

			DBU_insert_cwiplotchg(&CWIPLOTCHG);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTCHG INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCHG.FACTORY), CWIPLOTCHG.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCHG.LOT_ID), CWIPLOTCHG.LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPLOTCHG.ORDER_ID), CWIPLOTCHG.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTCHG.OPER), CWIPLOTCHG.OPER);
				TRS.add_fieldmsg(out_node, "FROM_MAT_ID", MP_STR, sizeof(CWIPLOTCHG.FROM_MAT_ID), CWIPLOTCHG.FROM_MAT_ID);
				TRS.add_fieldmsg(out_node, "TO_MAT_ID", MP_STR, sizeof(CWIPLOTCHG.TO_MAT_ID), CWIPLOTCHG.TO_MAT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			//품목 속성변경 후 LOT의 리스트를 보낸다.
			list_item = TRS.add_node(out_node, "CHANGE_LIST");
			TRS.add_nstring(list_item, "BEFORE_LOT_ID", TRS.get_string(change_lot_list[i], "BEFORE_LOT_ID"));
			TRS.add_nstring(list_item, "BEFORE_MAT_ID", TRS.get_string(change_lot_list[i], "BEFORE_MAT_ID"));
			TRS.add_nstring(list_item, "BEFORE_OPER", TRS.get_string(change_lot_list[i], "BEFORE_OPER"));
			TRS.add_nstring(list_item, "AFTER_MAT_ID", TRS.get_string(change_lot_list[i], "AFTER_MAT_ID"));
			TRS.add_nstring(list_item, "AFTER_OPER", TRS.get_string(change_lot_list[i], "AFTER_OPER"));


			if (COM_isnullspace(s_lot_id) != MP_TRUE)
				TRS.add_string(list_item, "AFTER_LOT_ID", s_lot_id, sizeof(s_lot_id));
			else
				TRS.add_string(list_item, "AFTER_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		}
	}
	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Change_Item_Validation()
- Validation Check sub function of "CUS_WIP_CHANGE_ITEM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Item_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
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
CUS_WIP_Change_Item_Before_Transaction()
- Main sub function of "CUS_WIP_CHANGE_ITEM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Item_Before_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Change_Item_After_Transaction()
- Main sub function of "CUS_WIP_CHANGE_ITEM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Change_Item_After_Transaction(char* s_msg_code, int msg_id, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_BEFORE;;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;
	struct MWIPMATDEF_TAG MWIPMATDEF_AFTER;
	struct MWIPMATDEF_TAG MWIPMATDEF_BEFORE;
	struct IF_COMPLETION_TRX_TAG IF_COMPLETION_TRX;
	struct IF_PO_REQUESTS_RECEIPTS_TAG IF_PO_REQUESTS_RECEIPTS;

	TRSNode** change_lot_list;
	TRSNode* if_change_in;
	TRSNode* cmn_out;

	int i;

	change_lot_list = TRS.get_list(in_node, "CHANGE_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "CHANGE_LOT_LIST"); i++)
	{
		if (TRS.get_procstep(in_node) == '1') {

			// LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "AFTER_LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
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
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);


				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//해당 lot이 테스트 품인 경우 ERP I/F를 타지 못하게 한다.
			if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
				continue;

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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

			//AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPMATDEF_AFTER - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF_AFTER);
			TRS.copy(MWIPMATDEF_AFTER.FACTORY, sizeof(MWIPMATDEF_AFTER.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF_AFTER.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			MWIPMATDEF_AFTER.MAT_VER = MWIPLOTSTSX.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF_AFTER);
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

				TRS.add_fieldmsg(out_node, "MWIPMATDEF_AFTER SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_AFTER.FACTORY), MWIPMATDEF_AFTER.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_AFTER.MAT_ID), MWIPMATDEF_AFTER.MAT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//ERP 품목변경 후 I/F
			if_change_in = TRS.add_node(in_node, "if_change_in");
			TRS.add_char(if_change_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(if_change_in, in_node);

			TRS.add_char(if_change_in, "TRAN_FLAG", 'I');
			TRS.add_int(if_change_in, "ERP_WO_ID", 1);
			TRS.add_string(if_change_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_int(if_change_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
			TRS.add_int(if_change_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_44));
			TRS.add_string(if_change_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
			TRS.add_string(if_change_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_int(if_change_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_AFTER.MAT_CMF_1, sizeof(MWIPMATDEF_AFTER.MAT_CMF_1)));
			TRS.add_string(if_change_in, "MAT_ID", MWIPMATDEF_AFTER.MAT_ID, sizeof(MWIPMATDEF_AFTER.MAT_ID));
			TRS.add_string(if_change_in, "UNIT", MWIPMATDEF_AFTER.UNIT_1, sizeof(MWIPMATDEF_AFTER.UNIT_1));
			TRS.add_double(if_change_in, "QTY", MWIPLOTSTSX.QTY_1);
			TRS.add_string(if_change_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_char(if_change_in, "CHANGE_ITEM", 'Y');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_change_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.free_node(cmn_out);

			// MWIPMATDEF_BEFORE - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF_BEFORE);
			TRS.copy(MWIPMATDEF_BEFORE.FACTORY, sizeof(MWIPMATDEF_BEFORE.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF_BEFORE.MAT_ID, sizeof(MWIPMATDEF_BEFORE.MAT_ID), change_lot_list[i], "BEFORE_MAT_ID");
			MWIPMATDEF_BEFORE.MAT_VER = MWIPLOTSTSX.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF_BEFORE);
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

				TRS.add_fieldmsg(out_node, "MWIPMATDEF_BEFORE SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BEFORE.FACTORY), MWIPMATDEF_BEFORE.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BEFORE.MAT_ID), MWIPMATDEF_BEFORE.MAT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
			TRS.copy(IF_COMPLETION_TRX.FACTORY, sizeof(IF_COMPLETION_TRX.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);

			//ERP 품목변경 전 I/F
			TRS.set_int(if_change_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
			TRS.set_string(if_change_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
			TRS.set_double(if_change_in, "TRAN_HEADER_ID", (double)DBU_select_if_completion_trx_scalar(2, &IF_COMPLETION_TRX));
			TRS.set_string(if_change_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.set_int(if_change_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_BEFORE.MAT_CMF_1, sizeof(MWIPMATDEF_BEFORE.MAT_CMF_1)));
			TRS.set_string(if_change_in, "MAT_ID", MWIPMATDEF_BEFORE.MAT_ID, sizeof(MWIPMATDEF_BEFORE.MAT_ID));
			TRS.set_string(if_change_in, "UNIT", MWIPMATDEF_BEFORE.UNIT_1, sizeof(MWIPMATDEF_BEFORE.UNIT_1));
			TRS.set_double(if_change_in, "QTY", MWIPLOTSTSX.QTY_1);
			TRS.set_nstring(if_change_in, "LOT_ID", TRS.get_string(change_lot_list[i], "BEFORE_LOT_ID"));
			TRS.set_char(if_change_in, "CHANGE_ITEM", 'N');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_change_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.free_node(cmn_out);
		}

		else if (TRS.get_procstep(in_node) == '2') {
			// LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), change_lot_list[i], "AFTER_LOT_ID");

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
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
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT(1)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);


				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//해당 lot이 테스트 품인 경우 ERP I/F를 타지 못하게 한다.
			if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
				continue;

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
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


			DBU_init_mwipoprdef(&MWIPOPRDEF_BEFORE);
			TRS.copy(MWIPOPRDEF_BEFORE.FACTORY, sizeof(MWIPOPRDEF_BEFORE.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF_BEFORE.OPER, sizeof(MWIPOPRDEF_BEFORE.OPER), change_lot_list[i], "BEFORE_OPER");

			DBU_select_mwipoprdef(1, &MWIPOPRDEF_BEFORE);
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

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF_BEFORE SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_BEFORE.FACTORY), MWIPOPRDEF_BEFORE.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_BEFORE.OPER), MWIPOPRDEF_BEFORE.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}





			//AREA 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPMATDEF_AFTER - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF_AFTER);
			TRS.copy(MWIPMATDEF_AFTER.FACTORY, sizeof(MWIPMATDEF_AFTER.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF_AFTER.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			MWIPMATDEF_AFTER.MAT_VER = MWIPLOTSTSX.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF_AFTER);
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

				TRS.add_fieldmsg(out_node, "MWIPMATDEF_AFTER SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_AFTER.FACTORY), MWIPMATDEF_AFTER.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_AFTER.MAT_ID), MWIPMATDEF_AFTER.MAT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}



			// MWIPMATDEF_BEFORE - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF_BEFORE);
			TRS.copy(MWIPMATDEF_BEFORE.FACTORY, sizeof(MWIPMATDEF_BEFORE.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF_BEFORE.MAT_ID, sizeof(MWIPMATDEF_BEFORE.MAT_ID), change_lot_list[i], "BEFORE_MAT_ID");
			MWIPMATDEF_BEFORE.MAT_VER = MWIPLOTSTSX.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF_BEFORE);
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

				TRS.add_fieldmsg(out_node, "MWIPMATDEF_BEFORE SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BEFORE.FACTORY), MWIPMATDEF_BEFORE.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BEFORE.MAT_ID), MWIPMATDEF_BEFORE.MAT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			//Erp I/F Request and Receipt
			if_change_in = TRS.add_node(in_node, "if_change_in");
			TRS.add_char(if_change_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(if_change_in, in_node);

			TRS.add_string(if_change_in, "FROM_ORG_CODE", MWIPOPRDEF_BEFORE.AREA_ID, sizeof(MWIPOPRDEF_BEFORE.AREA_ID));
			TRS.add_string(if_change_in, "TO_ORG_CODE", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(if_change_in, "FROM_ITEM_CODE", MWIPMATDEF_BEFORE.MAT_ID, sizeof(MWIPMATDEF_BEFORE.MAT_ID));
			TRS.add_string(if_change_in, "TO_ITEM_CODE", MWIPMATDEF_AFTER.MAT_ID, sizeof(MWIPMATDEF_AFTER.MAT_ID));
			TRS.add_string(if_change_in, "UOM", MWIPMATDEF_BEFORE.UNIT_1, sizeof(MWIPMATDEF_BEFORE.UNIT_1));
			TRS.add_double(if_change_in, "QUANTITY", MWIPLOTSTSX.QTY_1);
			TRS.add_double(if_change_in, "UNIT_PRICE", TRS.get_double(change_lot_list[i], "UNIT_PRICE"));



			TRS.add_string(if_change_in, "FROM_SUBINVENTORY", MWIPOPRDEF_BEFORE.OPER_CMF_1, sizeof(MWIPOPRDEF_BEFORE.OPER_CMF_1));
			TRS.add_string(if_change_in, "TO_SUBINVENTORY", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_string(if_change_in, "NEED_BY_DATE", gs_sys_time, 8);
			TRS.add_string(if_change_in, "CMF_1", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

			//CUS_IFS_po_requests_receipts
			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_REQUESTS_RECEIPTS(s_msg_code, if_change_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.free_node(cmn_out);


		}

	}

	return MP_TRUE;
}