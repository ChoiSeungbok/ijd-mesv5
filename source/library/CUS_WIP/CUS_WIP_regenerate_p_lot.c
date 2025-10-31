/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_regenerate_p_lot.c
Description : P급 판정 받은 CTM LOT 되살림

MES Version : 5.0

Function List


Detail Description

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/21  KY.JUNG        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Regenerate_P_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Regenerate_P_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Regenerate_P_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_REGENERATE_P_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Regenerate_P_Lot()
- Tran Regenerate P Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Regenerate_P_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_REGENERATE_P_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Regenerate_P_Lot", out_node);
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
CUS_WIP_REGENERATE_P_LOT()
- Main sub function of "CUS_WIP_Regenerate_P_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_REGENERATE_P_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *plot_in_node;
	TRSNode **p_lot_list;
	TRSNode *lot_list;
	
	int i;

    LOG_head("CUS_WIP_Regenerate_P_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Regenerate_P_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	plot_in_node = TRS.add_node(in_node, "plot_in_node");
	CopyDefaultMembers(plot_in_node, in_node);

	TRS.add_char(plot_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));
	TRS.add_nstring(plot_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
	TRS.add_nstring(plot_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
	TRS.add_nstring(plot_in_node, "IN_TYPE", TRS.get_string(in_node, "IN_TYPE"));
	TRS.add_nstring(plot_in_node, "TO_MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
	TRS.add_char(plot_in_node, "MAT_CHANGE", TRS.get_char(in_node, "MAT_CHANGE"));
	TRS.add_char(plot_in_node, "ERP_FLAG", TRS.get_char(in_node, "ERP_FLAG"));

	p_lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(plot_in_node, "LOT_LIST");
		TRS.add_nstring(lot_list, "LOT_ID", TRS.get_string(p_lot_list[i], "LOT_ID"));
	}

	if (CUS_WIP_Regenerate_P_Lot_Before_Transaction(s_msg_code, 0, plot_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_REGENERATE_P_LOT_MAIN(s_msg_code, plot_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_WIP_Regenerate_P_Lot_After_Transaction(s_msg_code, 0, plot_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_REGENERATE_P_LOT()
- Main sub function of "CUS_WIP_Regenerate_P_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_REGENERATE_P_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_AF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct CWIPLOTREC_TAG CWIPLOTREC;
	struct CWIPLOTCHG_TAG CWIPLOTCHG;
	//struct MWIPMATFLW_TAG MWIPMATFLW;
	TRSNode **lot_list;
	TRSNode *etc_lot_list;
	TRSNode *move_in;
	//TRSNode *store_in;
	TRSNode *unstore_in;
	TRSNode *etc_in;
	TRSNode *cmn_out;
	TRSNode *adapt_in;

	char s_sys_time[14];
	int i;
	double d_total_qty = 0;
	char s_mat_change;
	//char s_Mat_id[31];

	memset(s_sys_time, ' ', sizeof(s_sys_time));
//	memset(s_mat_change, ' ', sizeof(s_mat_change));
//	memset(s_Mat_id, ' ', sizeof(s_Mat_id));






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

	//TO 창고 조회
	DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
	TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
	DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0010");
		TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(2) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "TO_OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
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
	memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
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

		TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	lot_list = TRS.get_list(in_node, "LOT_LIST");

	// CTM P급
	if (TRS.get_char(in_node, IN_PROCSTEP) == '1')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// MWIPLOTSTS - LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), lot_list[i], "LOT_ID");
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

			// 공정 LOT 잠금 여부 체크
			if (MWIPLOTSTS.HOLD_FLAG == 'Y')
			{
				// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
				strcpy(s_msg_code, "WIP-0059");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//lot 삭제여부 체크
			if (MWIPLOTSTS.LOT_DEL_FLAG == 'Y')
			{
				//WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0076");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

				return MP_FALSE;
			}

			//P급 정보 조회
			DBU_init_cwiplotrec(&CWIPLOTREC);
			TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), lot_list[i], "LOT_ID");
			DBU_select_cwiplotrec(2, &CWIPLOTREC);


			DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
			TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0010 : 이 공정은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF_AF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			//현재 창고가 P급창고가 아니면 오류
			if (memcmp(MWIPOPRDEF_AF.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != MP_FALSE)
			{
				//WIP-0010 : 이 공정은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0698");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF_AF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;

			}


			if (DB_error_code != DB_SUCCESS)
			{
				//없으면 삭제된거에서 찾아서 처리
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), lot_list[i], "LOT_ID");
				DBU_select_cwiplotrec(4, &CWIPLOTREC);

				d_total_qty += CWIPLOTREC.QTY;

				if (DB_error_code != DB_SUCCESS)
				{

					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}






			/*
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// P급 정보 삭제 여부 
			if (CWIPLOTREC.DELETE_FLAG == 'Y')
			{
				//WIP-0642 : 해당 P급 Lot 정보는 이미 삭제되어 있습니다. 상태를 확인해주세요.
				strcpy(s_msg_code, "WIP-0642");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

				return MP_FALSE;
			}
			*/




			s_mat_change = TRS.get_char(in_node, "MAT_CHANGE");
		//	s_Mat_id = TRS.get_char(in_node, "TO_MAT_ID");


			//memcpy(s_mat_change, sizeof(s_mat_change), in_node, "MAT_CHANGE");



			//TRS.add_nstring(etc_lot_list, "MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
			//TRS.add_int(etc_lot_list, "MAT_VER", 1);

			//if (memcmp(MWIPLOTSTS.MAT_ID, TRS.get_string(in_node, "TO_MAT_ID"), sizeof(MWIPLOTSTS.MAT_ID)) != MP_FALSE)

			if(s_mat_change =='Y')
			{
				//LOT ADAPT 처리(속성변경)
				adapt_in = TRS.add_node(in_node, "adapt_in");
				TRS.add_char(adapt_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(adapt_in, in_node);


				TRS.add_string(adapt_in, "LOT_ID", CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));

				TRS.add_string(adapt_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
				TRS.add_string(adapt_in, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
				TRS.add_string(adapt_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
				TRS.add_string(adapt_in, "TO_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
				TRS.add_nstring(adapt_in, "TO_MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
				TRS.add_int(adapt_in, "TO_MAT_VER", 1);
				TRS.add_string(adapt_in, "TO_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
				TRS.add_char(adapt_in, "LOT_TYPE", MWIPLOTSTS.LOT_TYPE);
				TRS.add_char(adapt_in, "LOT_PRIORITY", MWIPLOTSTS.LOT_PRIORITY);
				TRS.add_string(adapt_in, "CREATE_CODE", MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));
				TRS.add_string(adapt_in, "OWNER_CODE", MWIPLOTSTS.OWNER_CODE, sizeof(MWIPLOTSTS.OWNER_CODE));
				TRS.add_nstring(adapt_in, "TRAN_CMF_3", "P_MAT_CHANGE");  // P급 품목 변경 표기용도

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_ADAPT_LOT(s_msg_code, adapt_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);



				//20210820 품변하는거기는 해서 이력을 넣어야 되나 말아야 되나 하다가 넣음.
				//나중에 봐서 뺄수도 있음.

				//품목변경 이력 저장 (CWIPLOTCHG)
				DBU_init_cwiplotchg(&CWIPLOTCHG);
				TRS.copy(CWIPLOTCHG.FACTORY, sizeof(CWIPLOTCHG.FACTORY), in_node, IN_FACTORY);

				//변경되는 lot을 lot id로 본다.    
				memcpy(CWIPLOTCHG.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CWIPLOTCHG.LOT_ID));
				//CWIPLOTCHG.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ + 1; // 재 조회해서 seq 넣어줄것.
				//20250512 syw  LAST_ACTIVE_HIST_SEQ -->  LAST_HIST_SEQ 변경 리턴한경우 오류나는 케이스있음.
				CWIPLOTCHG.HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ + 1; // 재 조회해서 seq 넣어줄것.


				memcpy(CWIPLOTCHG.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(CWIPLOTCHG.ORDER_ID));
				memcpy(CWIPLOTCHG.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTCHG.FLOW));
				memcpy(CWIPLOTCHG.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTCHG.OPER));
				//memcpy(CWIPLOTCHG.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				memcpy(CWIPLOTCHG.AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(CWIPLOTCHG.AREA_ID));
				memcpy(CWIPLOTCHG.SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(CWIPLOTCHG.SUB_AREA_ID));
				memcpy(CWIPLOTCHG.FROM_MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTCHG.FROM_MAT_ID));
				CWIPLOTCHG.FROM_MAT_VER = MWIPLOTSTS.MAT_VER;
				TRS.copy(CWIPLOTCHG.TO_MAT_ID, sizeof(CWIPLOTCHG.TO_MAT_ID), in_node, "TO_MAT_ID");
				CWIPLOTCHG.TO_MAT_VER = MWIPLOTSTS.MAT_VER;
				CWIPLOTCHG.QRY_1 = MWIPLOTSTS.QTY_1;
				memcpy(CWIPLOTCHG.CMF_1, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID)); //원래 lot을 저장


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


			}





			//이미 store처리 되어있던 lot은 unstore를 해준뒤 앞으로 가야하는 창고로 보낸다. 
			if (MWIPLOTSTS.INV_FLAG == 'Y')
			{
				unstore_in = TRS.add_node(in_node, "unstore_in");
				TRS.add_char(unstore_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(unstore_in, in_node);

				TRS.add_string(unstore_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTS.STR_RET_FLOW, sizeof(MWIPLOTSTS.STR_RET_FLOW));
				TRS.add_string(unstore_in, "TO_OPER", MWIPLOTSTS.STR_RET_OPER, sizeof(MWIPLOTSTS.STR_RET_OPER));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_UNSTORE_LOT(s_msg_code, unstore_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}


			// 생산 창고로 이동
			move_in = TRS.add_node(in_node, "move_in");
			CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

			TRS.add_char(move_in, "PROCSTEP", '4');
			TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(move_in, "TO_FLOW", "XF-990", strlen("XF-990"));  //XF990으로 고정
			TRS.add_nstring(move_in, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
			//TRS.add_string(unstore_in, "TO_FLOW", MWIPLOTSTS.STR_RET_FLOW, sizeof(MWIPLOTSTS.STR_RET_FLOW))
			//TRS.add_string(move_in, "TO_OPER", MWIPLOTSTS.NSTD_RET_OPER, sizeof(MWIPMATFLW.NSTD_RET_OPER));
			TRS.add_char(move_in, "FROM_TO_FLAG", 'F');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//20220429 STROE 안씀
			/*
			// STORE
			store_in = TRS.add_node(in_node, "store_in");
			TRS.add_char(store_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(store_in, in_node);

			TRS.add_string(store_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(store_in, "TO_OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
			TRS.add_nstring(store_in, "COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
			*/





			// P급 처리 후 P급 정보 DELETE_FLAG 변경
			//20210820 CMF_1에 품변해서 들어가는 경우 CMF_1에 바뀐 품목번호 기입(혹몰라)
			CWIPLOTREC.DELETE_FLAG = 'Y';
			TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
			TRS.copy(CWIPLOTREC.CMF_1, sizeof(CWIPLOTREC.CMF_1), in_node, "TO_MAT_ID");
			memcpy(CWIPLOTREC.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			DBU_update_cwiplotrec(6, &CWIPLOTREC);

			if (DB_error_code != DB_SUCCESS)
			{

				//없으면 삭제된거에서 찾아서 처리
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), lot_list[i], "LOT_ID");
				DBU_select_cwiplotrec(4, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE(1)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				CWIPLOTREC.DELETE_FLAG = 'Y';
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				TRS.copy(CWIPLOTREC.CMF_1, sizeof(CWIPLOTREC.CMF_1), in_node, "TO_MAT_ID");
				memcpy(CWIPLOTREC.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_cwiplotrec(6, &CWIPLOTREC);

			}
		}
	}
	// GRT P급
	else if (TRS.get_char(in_node, IN_PROCSTEP) == '2')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// MWIPLOTSTS - LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), lot_list[i], "LOT_ID");
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

			//lot 삭제여부 체크
			if (MWIPLOTSTS.LOT_DEL_FLAG != 'Y')
			{
				// WIP-0630 : 해당 Lot은 삭제되어 있지 않습니다. Lot을 확인하세요.
				strcpy(s_msg_code, "WIP-0630");
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

			//P급 정보 조회
			DBU_init_cwiplotrec(&CWIPLOTREC);
			TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), lot_list[i], "LOT_ID");
			DBU_select_cwiplotrec(2, &CWIPLOTREC);

			if (DB_error_code != DB_SUCCESS)
			{
				//없으면 삭제된거에서 찾아서 처리
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), lot_list[i], "LOT_ID");
				DBU_select_cwiplotrec(4, &CWIPLOTREC);

				d_total_qty += CWIPLOTREC.QTY;

				if (DB_error_code != DB_SUCCESS)
				{

					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
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
				d_total_qty += CWIPLOTREC.QTY;

				// P급 처리 후 P급 정보 DELETE_FLAG 변경
				CWIPLOTREC.DELETE_FLAG = 'Y';
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_cwiplotrec(4, &CWIPLOTREC);


			}

			/*
			// P급 정보 삭제 여부 
			if (CWIPLOTREC.DELETE_FLAG == 'Y')
			{
				//WIP-0642 : 해당 P급 Lot 정보는 이미 삭제되어 있습니다. 상태를 확인해주세요.
				strcpy(s_msg_code, "WIP-0642");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

				return MP_FALSE;
			}
			*/

			if (DB_error_code != DB_SUCCESS)
			{
				DBU_update_cwiplotrec(4, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS) {
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}



		// MWIPLOTSTS - LOT 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), lot_list[0], "LOT_ID");
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


		// MWIPLOTSTS - Total 수량으로 기타 입고 처리
		etc_in = TRS.add_node(in_node, "etc_in");
		CopyDefaultMembers(etc_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(etc_in, "PROCSTEP", '1');
		//TRS.add_nstring(etc_in, "MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
		//TRS.add_int(etc_in, "MAT_VER", 1);
		TRS.add_nstring(etc_in, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
		TRS.add_char(etc_in, "ERP_FLAG", TRS.get_char(in_node, "ERP_FLAG"));

		etc_lot_list = TRS.add_node(etc_in, "LOT_LIST");
		TRS.add_double(etc_lot_list, "QTY_1", d_total_qty);
        //ETC IN에는 MAT_ID 가 LIST에 들어가야 하기 때문에 etc_lot_list에 추가. _20210118_LWG
        TRS.add_nstring(etc_lot_list, "MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
        TRS.add_int(etc_lot_list, "MAT_VER", 1);

		TRS.add_string(etc_lot_list, "SUB_AREA_ID", MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
		TRS.add_string(etc_lot_list, "OPER", MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
		TRS.add_nstring(etc_lot_list, "IN_TYPE", TRS.get_string(in_node, "IN_TYPE"));

		TRS.add_char(etc_lot_list, "LOT_TYPE", MWIPLOTSTS.LOT_TYPE);
		TRS.add_string(etc_lot_list, "CREATE_CODE", MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));
		TRS.add_string(etc_lot_list, "OWNER_CODE", MWIPLOTSTS.OWNER_CODE, sizeof(MWIPLOTSTS.OWNER_CODE));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_ETC_IN_LOT(s_msg_code, etc_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Regenerate_P_Lot_Validation()
- Validation Check sub function of "CUS_WIP_REGENERATE_P_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Regenerate_P_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    /*if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

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
CUS_WIP_Regenerate_P_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_REGENERATE_P_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Regenerate_P_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Regenereate_P_Lot_After_Transaction()
- Main sub function of "CUS_WIP_REGENERATE_PLOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Regenerate_P_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct CWIPORDRWK_TAG CWIPORDRWK;
	TRSNode *erpif_in;
	TRSNode	*cmn_out;
	TRSNode **lot_list;

	int i;

	lot_list = TRS.get_list(in_node, "LOT_LIST");

	//CTM P급 입고 I/F 
	if (TRS.get_char(in_node, IN_PROCSTEP) == '1')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// MWIPLOTSTS - LOT 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), lot_list[i], "LOT_ID");
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
				return MP_FALSE;
			}

			// 공정 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			if (MWIPLOTSTS.LOT_TYPE == MP_LOT_TYPE_P)
			{
				// P급 작지 조회
				DBU_init_cwipordrwk(&CWIPORDRWK);
				TRS.copy(CWIPORDRWK.FACTORY, sizeof(CWIPORDRWK.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPORDRWK.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				memcpy(CWIPORDRWK.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				CWIPORDRWK.MAT_VER = MWIPMATDEF.MAT_VER;
				DBU_select_cwipordrwk(2, &CWIPORDRWK);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPORDRWK SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDRWK.FACTORY), CWIPORDRWK.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPORDRWK.AREA_ID), CWIPORDRWK.AREA_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDRWK.MAT_ID), CWIPORDRWK.MAT_ID);
					TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, CWIPORDRWK.MAT_VER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			//AREA 정보 조회
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
				return MP_FALSE;
			}

			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2));
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
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
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

            //양산품 LOT인 경우에만 COMPLETION을 ERP에 올려준다. 
            //테스트 품인 경우는 ERP에 실적을 올리지 않고, 창고에서 양산품 전환을 해야 한다.
            if (MWIPLOTSTS.LOT_TYPE == MP_LOT_TYPE_P)
            {
                //ERP 실적 I/F
                erpif_in = TRS.add_node(in_node, "erpif_in");
                TRS.add_char(erpif_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(erpif_in, in_node);

                TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
                TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
                TRS.add_string(erpif_in, "WO_ID", CWIPORDRWK.ORDER_ID, sizeof(CWIPORDRWK.ORDER_ID));
                TRS.add_int(erpif_in, "ERP_WO_ID", CWIPORDRWK.ERP_ORDER_ID);
                TRS.add_string(erpif_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
                TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
                TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
                TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
                TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                TRS.add_double(erpif_in, "QTY", MWIPLOTSTS.QTY_1);
                TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_IFS_COMPLETION_TRX(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }
		}
	}
	
    return MP_TRUE;
}