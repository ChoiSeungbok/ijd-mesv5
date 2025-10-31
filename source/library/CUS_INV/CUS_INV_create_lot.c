/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_create_lot.c
    Description : Create Inv Lot Data

    MES Version : 5.2.0

    Function List
        - CUS_INV_Create_Lot()
            + Create Inv Lot Data
        - CUS_INV_CREATE_LOT()
            + Main Sub function of "CUS_INV_Create_Lot"
            + (called by "CUS_INV_Create_Lot")
        - CUS_INV_Create_Lot_Validation()
            + Validation Check sub function of "CUS_INV_CREATE_LOT" function
            + (called by "CUS_INV_CREATE_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/03  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_CREATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CREATE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Create_Lot()
        - Create Inv Lot Data
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Create_Lot_In_Tag *CUS_INV_Create_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_CREATE_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CREATE_LOT", out_node);

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
CUS_INV_CREATE_LOT_MAIN()
- Main sub function of "CUS_INV_CREATE_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CREATE_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	struct MGCMLAGDAT_TAG MGCMLAGDAT;
	TRSNode *create_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	char inv_lot_id[26];
	char inv_dlv_lot_id[26];

	LOG_head("CUS_INV_CREATE_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Create_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
    TRS.add_nstring(create_in_node, "MOLD_MODEL", TRS.get_string(in_node, "MOLD_MODEL"));
    TRS.add_nstring(create_in_node, "MOLD_TYPE", TRS.get_string(in_node, "MOLD_TYPE"));
    TRS.add_nstring(create_in_node, "MAT_TYPE", TRS.get_string(in_node, "MAT_TYPE"));
	TRS.add_nstring(create_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));
	TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
	TRS.add_int(create_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
	TRS.add_nstring(create_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
	TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
	TRS.add_char(create_in_node, "ERP_FLAG", TRS.get_char(in_node, "ERP_FLAG"));

    TRS.add_char(create_in_node, "SKIP_IF", TRS.get_char(in_node, "SKIP_IF"));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	// 구매 입고
	if (TRS.get_procstep(in_node) == '1')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
			TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
			TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
			TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
			TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
		}
	}
	//기타 입고
	else if (TRS.get_procstep(in_node) == '2')
	{
		DBU_init_mgcmlagdat(&MGCMLAGDAT);
		TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
		TRS.copy(MGCMLAGDAT.KEY_1, sizeof(MGCMLAGDAT.KEY_1), in_node, "VENDOR_ID");
		TRS.copy(MGCMLAGDAT.KEY_2, sizeof(MGCMLAGDAT.KEY_2), in_node, "VENDOR_SITE_ID");
		DBU_select_mgcmlagdat(3, &MGCMLAGDAT);

		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			TRS.add_fieldmsg(out_node, "MGCMLAGDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
			TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		memset(inv_dlv_lot_id, 0x00, sizeof(inv_dlv_lot_id));

		gen_in_node = TRS.add_node(in_node, "gen_in_node");
		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_INV_LOT_ID, strlen(MP_ID_ROLE_INV_LOT_ID));
		TRS.add_string(gen_in_node, "LOT_ID", MGCMLAGDAT.DATA_1, 12);
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(inv_dlv_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			memset(inv_lot_id, ' ', sizeof(inv_lot_id));

			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW, strlen(MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW));
			TRS.add_string(gen_in_node, "LOT_ID", inv_dlv_lot_id, strlen(inv_dlv_lot_id));
			TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(inv_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

			TRS.free_node(cmn_out);

			inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
			TRS.add_string(inv_list, "INV_LOT_ID", inv_lot_id, sizeof(inv_lot_id));
			TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
			TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
			TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
			TRS.add_nstring(inv_list, "SUB_AREA_ID", TRS.get_string(inv_lot_list[i], "SUB_AREA_ID"));
			TRS.add_nstring(inv_list, "OPER", TRS.get_string(inv_lot_list[i], "OPER"));
			TRS.add_nstring(inv_list, "MAT_ID", TRS.get_string(inv_lot_list[i], "MAT_ID"));
			TRS.add_int(inv_list, "MAT_VER", TRS.get_int(inv_lot_list[i], "MAT_VER"));
			TRS.add_nstring(inv_list, "ARRIVAL_DATE", TRS.get_string(inv_lot_list[i], "ARRIVAL_DATE"));
			TRS.add_nstring(inv_list, "IN_TYPE", TRS.get_string(inv_lot_list[i], "IN_TYPE"));
			TRS.add_nstring(inv_list, "VENDOR_ID", TRS.get_string(inv_lot_list[i], "VENDOR_ID"));
			TRS.add_nstring(inv_list, "VENDOR_SITE_ID", TRS.get_string(inv_lot_list[i], "VENDOR_SITE_ID"));
			TRS.add_nstring(inv_list, "VENDOR_LOT_ID", TRS.get_string(inv_lot_list[i], "VENDOR_LOT_ID"));
			TRS.add_nstring(inv_list, "COMMENT", TRS.get_string(inv_lot_list[i], "COMMENT"));
			TRS.add_string(inv_list, "DLV_LOT_ID", inv_dlv_lot_id, sizeof(inv_dlv_lot_id));
		}
	}
	// 마이그레이션 입고
	else if (TRS.get_procstep(in_node) == '3')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
			TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
			TRS.add_nstring(inv_list, "INV_LOT_DESC", TRS.get_string(inv_lot_list[i], "INV_LOT_DESC"));
			TRS.add_nstring(inv_list, "MAT_ID", TRS.get_string(inv_lot_list[i], "MAT_ID"));
			TRS.add_nstring(inv_list, "OPER", TRS.get_string(inv_lot_list[i], "OPER"));
			TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
			TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
			TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
			TRS.add_nstring(inv_list, "VENDOR_ID", TRS.get_string(inv_lot_list[i], "VENDOR_ID"));
			TRS.add_nstring(inv_list, "VENDOR_SITE_ID", TRS.get_string(inv_lot_list[i], "VENDOR_SITE_ID"));
			TRS.add_nstring(inv_list, "VENDOR_LOT_ID", TRS.get_string(inv_lot_list[i], "VENDOR_LOT_ID"));
			TRS.add_nstring(inv_list, "IN_TYPE", TRS.get_string(inv_lot_list[i], "IN_TYPE"));
			TRS.add_nstring(inv_list, "MOLD_MODEL", TRS.get_string(inv_lot_list[i], "MOLD_MODEL"));
			TRS.add_nstring(inv_list, "MOLD_TYPE", TRS.get_string(inv_lot_list[i], "MOLD_TYPE"));
		}
	}

	if (CUS_INV_Create_Lot_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Create_Lot_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_CREATE_LOT()
        - Main sub function of "CUS_INV_Create_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
    struct MWIPMATDEF_TAG MWIPMATDEF; 
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MINVDLVMST_TAG MINVDLVMST;
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVLOTSTS_TAG MINVLOTSTS_OLD;
    struct MINVLOTHIS_TAG MINVLOTHIS;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	//    struct MGCMTBLDAT_TAG MGCMTBLDAT_WH;

	struct MINVLOTSTS_TAG MINVLOTSTS_ORG;
	TRSNode **inv_lot_list;

    char s_sys_time[14];
	char s_vendor_site_id[30];
	int i;
	double d_total_qty = 0;
	  
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// 자재 입하 정보를 이용한 자재 입고
	if (TRS.get_procstep(in_node) == '1')
	{
		// MINVDLVLOT - 입하 자재 LOT 정보 조회
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
		DBU_select_minvdlvlot(1, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 입하 LOT 수입검사 상태 체크
		//if (memcmp(MINVDLVLOT.INSP_STATUS, MP_CQMS_STATUS_COMPLETE, strlen(MP_CQMS_STATUS_COMPLETE)) != 0)
		if(MINVDLVLOT.INSP_STATUS[0] != MP_CQMS_STATUS_COMPLETE)
		{
			//INV-0047 : 이 입하 자재 LOT은 수입 검사가 진행중입니다.
			strcpy(s_msg_code, "INV-0047");
			TRS.add_fieldmsg(out_node, "CUS_INV_CREATE_LOT", MP_NVST);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 입하 LOT 수입검사 결과 체크
		if (MINVDLVLOT.INSP_RESULT_FLAG != MP_CQMS_INSP_JUDGE_PASS &&
			 MINVDLVLOT.INSP_RESULT_FLAG !=MP_CQMS_INSP_JUDGE_SPECIAL)
		{
			//INV-0060 : 수입 검사 결과가 Fail입니다.
			strcpy(s_msg_code, "INV-0060");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 입하 LOT 상태 체크
		if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, strlen(MP_CINV_LOT_STATUS_CONFIRM)) != 0)
		{
			//INV-0071 : 해당 입하 Lot은 이미 입고되었습니다.
			strcpy(s_msg_code, "INV-0071");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
            TRS.add_fieldmsg(out_node, "DLV_LOT_STATUS", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_STATUS), MINVDLVLOT.DLV_LOT_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// MWIPMATDEF - 제품 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVDLVLOT.MAT_VER;
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

		// MINVDLVMST - 구매 입고 마스터 정보 조회
		DBU_init_minvdlvmst(&MINVDLVMST);
		TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVMST.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		DBU_select_minvdlvmst(1, &MINVDLVMST);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// MINVDLVDTL - 구매 입고 상세 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
		DBU_select_minvdlvdtl(1, &MINVDLVDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (MINVDLVDTL.ERP_OPEN_YN == 'Y')
		{
			//INV-0066 : 해당 PO 정보는 ERP에서 마감되었습니다.
			strcpy(s_msg_code, "INV-0066");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS_ORG);
			TRS.copy(MINVLOTSTS_ORG.FACTORY, sizeof(MINVLOTSTS_ORG.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS_ORG.INV_LOT_ID, sizeof(MINVLOTSTS_ORG.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			if ((int)DBU_select_minvlotsts_scalar(1, &MINVLOTSTS_ORG) > 0)
			{
				//INV-0075 : Lot ID가 이미 존재합니다.
				strcpy(s_msg_code, "INV-0075");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT SCALAR(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS_ORG.FACTORY), MINVLOTSTS_ORG.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS_ORG.INV_LOT_ID), MINVLOTSTS_ORG.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//입고 자재 LOT 생성
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			TRS.copy(MINVLOTSTS.INV_LOT_DESC, sizeof(MINVLOTSTS.INV_LOT_DESC), inv_lot_list[i], "INV_LOT_DESC");
			memcpy(MINVLOTSTS.INV_LOT_TYPE, MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
			memcpy(MINVLOTSTS.INV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVLOTSTS.INV_LOT_STATUS));
			MINVLOTSTS.INV_LOT_PRIORITY = '1';
			memcpy(MINVLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MINVLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			MINVLOTSTS.QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			memcpy(MINVLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			memcpy(MINVLOTSTS.UNIT_2, MWIPMATDEF.UNIT_2, sizeof(MWIPMATDEF.UNIT_2));
			memcpy(MINVLOTSTS.UNIT_3, MWIPMATDEF.UNIT_3, sizeof(MWIPMATDEF.UNIT_3));
			memset(MINVLOTSTS.ORDER_ID, ' ', sizeof(MINVLOTSTS.ORDER_ID));
			memset(MINVLOTSTS.ADD_ORDER_ID_1, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_1));
			memset(MINVLOTSTS.ADD_ORDER_ID_2, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_2));
			memset(MINVLOTSTS.ADD_ORDER_ID_3, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_3));
			memcpy(MINVLOTSTS.VENDOR_ID, MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			MINVLOTSTS.VENDOR_SITE_ID = MINVDLVMST.VENDOR_SITE_ID;
			memcpy(MINVLOTSTS.VENDOR_LOT_ID, MINVDLVLOT.VENDOR_LOT_ID, sizeof(MINVDLVLOT.VENDOR_LOT_ID));
			memcpy(MINVLOTSTS.AREA_ID, MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
            memset(MINVLOTSTS.SUB_AREA_ID, ' ', sizeof(MINVLOTSTS.SUB_AREA_ID));
			memset(MINVLOTSTS.LOCATION_1, ' ', sizeof(MINVLOTSTS.LOCATION_1));
			memset(MINVLOTSTS.LOCATION_2, ' ', sizeof(MINVLOTSTS.LOCATION_2));
			memset(MINVLOTSTS.LOCATION_3, ' ', sizeof(MINVLOTSTS.LOCATION_3));
			memset(MINVLOTSTS.OPER, ' ', sizeof(MINVLOTSTS.OPER));
			memset(MINVLOTSTS.LOC_NO, ' ', sizeof(MINVLOTSTS.LOC_NO));
			memset(MINVLOTSTS.RES_ID, ' ', sizeof(MINVLOTSTS.RES_ID));
			memset(MINVLOTSTS.PORT_ID, ' ', sizeof(MINVLOTSTS.PORT_ID));
			memset(MINVLOTSTS.SLOT_NO, ' ', sizeof(MINVLOTSTS.SLOT_NO));
			memset(MINVLOTSTS.CRR_ID, ' ', sizeof(MINVLOTSTS.CRR_ID));
			memset(MINVLOTSTS.LOT_ID, ' ', sizeof(MINVLOTSTS.LOT_ID));
			memcpy(MINVLOTSTS.RECV_DATE, MINVDLVLOT.DLV_TIME, sizeof(MINVLOTSTS.RECV_DATE));
			MINVLOTSTS.RECV_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			memset(MINVLOTSTS.REASON_CODE, ' ', sizeof(MINVLOTSTS.REASON_CODE));
			MINVLOTSTS.LOAD_FLAG = 'N';
			MINVLOTSTS.TRANSIT_FLAG = 'N';
			MINVLOTSTS.DELETE_FLAG = 'N';
			memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
			memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
			memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
			MINVLOTSTS.HOLD_FLAG = 'N';
			memset(MINVLOTSTS.HOLD_CODE, ' ', sizeof(MINVLOTSTS.HOLD_CODE));
			MINVLOTSTS.INSP_FLAG = 'Y';
			memcpy(MINVLOTSTS.INSP_ID, MINVDLVLOT.INSP_ID, sizeof(MINVDLVLOT.INSP_ID));
			MINVLOTSTS.INSP_RESULT_FLAG = MINVDLVLOT.INSP_RESULT_FLAG;
			memset(MINVLOTSTS.INV_LOT_GRADE, ' ', sizeof(MINVLOTSTS.INV_LOT_GRADE));
			memcpy(MINVLOTSTS.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO));
			MINVLOTSTS.DLV_SEQ = MINVDLVDTL.DLV_SEQ;
			memcpy(MINVLOTSTS.PO_NO, MINVDLVDTL.PO_NO, sizeof(MINVDLVDTL.PO_NO));
			MINVLOTSTS.PO_SEQ = MINVDLVDTL.PO_SEQ;
			memcpy(MINVLOTSTS.BL_NO, MINVDLVDTL.BL_NO, sizeof(MINVDLVDTL.BL_NO));
			MINVLOTSTS.BL_SEQ = MINVDLVDTL.BL_SEQ;
			MINVLOTSTS.PO_DISTRIBUTION_ID = MINVDLVDTL.PO_DISTRIBUTION_ID;
            TRS.copy(MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1), in_node, "MOLD_MODEL"); // 금형 모델
            TRS.copy(MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2), in_node, "MOLD_TYPE"); // 금형 구분
			memset(MINVLOTSTS.INV_CMF_3, ' ', sizeof(MINVLOTSTS.INV_CMF_3));	// 이전 공정
			memset(MINVLOTSTS.INV_CMF_4, ' ', sizeof(MINVLOTSTS.INV_CMF_4));
			memset(MINVLOTSTS.INV_CMF_5, ' ', sizeof(MINVLOTSTS.INV_CMF_5));
			memset(MINVLOTSTS.INV_CMF_6, ' ', sizeof(MINVLOTSTS.INV_CMF_6));
			memset(MINVLOTSTS.INV_CMF_7, ' ', sizeof(MINVLOTSTS.INV_CMF_7));
			memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8));
			memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9));
			memset(MINVLOTSTS.INV_CMF_10, ' ', sizeof(MINVLOTSTS.INV_CMF_10));
			memset(MINVLOTSTS.INV_CMF_11, ' ', sizeof(MINVLOTSTS.INV_CMF_11));
			memset(MINVLOTSTS.INV_CMF_12, ' ', sizeof(MINVLOTSTS.INV_CMF_12));
			memset(MINVLOTSTS.INV_CMF_13, ' ', sizeof(MINVLOTSTS.INV_CMF_13));
			memset(MINVLOTSTS.INV_CMF_14, ' ', sizeof(MINVLOTSTS.INV_CMF_14));
			memset(MINVLOTSTS.INV_CMF_15, ' ', sizeof(MINVLOTSTS.INV_CMF_15));
			memset(MINVLOTSTS.INV_CMF_16, ' ', sizeof(MINVLOTSTS.INV_CMF_16));
			memset(MINVLOTSTS.INV_CMF_17, ' ', sizeof(MINVLOTSTS.INV_CMF_17));
			memset(MINVLOTSTS.INV_CMF_18, ' ', sizeof(MINVLOTSTS.INV_CMF_18));
			memset(MINVLOTSTS.INV_CMF_19, ' ', sizeof(MINVLOTSTS.INV_CMF_19));
			memset(MINVLOTSTS.INV_CMF_20, ' ', sizeof(MINVLOTSTS.INV_CMF_20));
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_CREATE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
			MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = 1;
			MINVLOTSTS.LAST_HIST_SEQ = 1;
			memcpy(MINVLOTSTS.ORG_INV_LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
			MINVLOTSTS.FROM_TO_DIV = ' ';
			memset(MINVLOTSTS.FROM_TO_INV_LOT_ID, ' ', sizeof(MINVLOTSTS.FROM_TO_INV_LOT_ID));
			MINVLOTSTS.FROM_TO_HIST_SEQ = 0;
			MINVLOTSTS.CREATE_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.CREATE_QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.CREATE_QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			TRS.copy(MINVLOTSTS.CREATE_USER_ID, sizeof(MINVLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			//자재 LOT 토탈 수량 
			d_total_qty += MINVLOTSTS.QTY;

			//자재 LOT OLD 데이터
			//자재 생성 -> OLD, NEW 데이터 같음
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			memcpy(&MINVLOTSTS_OLD, &MINVLOTSTS, sizeof(MINVLOTSTS));

			//자재 LOT 이력 생성
			DBU_init_minvlothis(&MINVLOTHIS);

			//자재 LOT UPSERT & 자재 이력 INSERT
			if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVLOTSTS,
				&MINVLOTHIS) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//입고 자재 LOT 생성 -> 입고 지시 확정 수량 추가
		MINVDLVDTL.CONFIRM_QTY += d_total_qty;

		//LOT의 수량과 DLV_QTY가 같아지면 DELETE_FLAG = 'Y'
		if (MINVDLVDTL.DLV_QTY <= MINVDLVDTL.CONFIRM_QTY + MINVDLVDTL.LOSS_QTY) 
		{
			MINVDLVDTL.DELETE_FLAG = 'Y';
		}

		TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvdtl(1, &MINVDLVDTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//입하 LOT 상태 변경 (WAIT -> COMPLETED)
		memcpy(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_COMPLETED, sizeof(MINVDLVLOT.DLV_LOT_STATUS));
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 해당하는 지시에 엮인 모든 DTL들 조회
		// 모든 DTL의 DELETE_FLAG = 'Y'인것만 존재할때 부모인 MST도 'Y'를 넣어줌
		if ((int)DBU_select_minvdlvdtl_scalar(2, &MINVDLVDTL) <= 0)
		{
			MINVDLVMST.DELETE_FLAG = 'Y';
		}

		DBU_update_minvdlvmst(1, &MINVDLVMST);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVMST UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	// 기타 입고를 통한 자재 생성
	else if (TRS.get_procstep(in_node) == '2')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			memset(s_vendor_site_id, ' ', sizeof(s_vendor_site_id));

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), inv_lot_list[i], "MAT_ID");
			MWIPMATDEF.MAT_VER = TRS.get_int(inv_lot_list[i], "MAT_VER");
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


			//20220627 해당 제약필요없음
			/*
			// 금형자재일 경우, 기타 입고 제한
			if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
			{
				//INV-0073 : 해당 품목은 금형자재입니다. 진행할 수 없습니다.
				strcpy(s_msg_code, "INV-0073");
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

			*/

			// MWIPOPRDEF - 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), inv_lot_list[i], "OPER");
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_CREATE_LOT_01) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			if (MWIPOPRDEF.INV_FLAG != 'Y')
			{
				//WIP-0582 : 해당 공정은 창고가 아닙니다.
				strcpy(s_msg_code, "WIP-0582");
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//입고 자재 LOT 생성
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
            TRS.copy(MINVLOTSTS.INV_LOT_DESC, sizeof(MINVLOTSTS.INV_LOT_DESC), inv_lot_list[i], "INV_LOT_DESC");
			memcpy(MINVLOTSTS.INV_LOT_TYPE, MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
			memcpy(MINVLOTSTS.INV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVLOTSTS.INV_LOT_STATUS));
			MINVLOTSTS.INV_LOT_PRIORITY = '1';
			memcpy(MINVLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MINVLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			MINVLOTSTS.QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			memcpy(MINVLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			memcpy(MINVLOTSTS.UNIT_2, MWIPMATDEF.UNIT_2, sizeof(MWIPMATDEF.UNIT_2));
			memcpy(MINVLOTSTS.UNIT_3, MWIPMATDEF.UNIT_3, sizeof(MWIPMATDEF.UNIT_3));
			memset(MINVLOTSTS.ORDER_ID, ' ', sizeof(MINVLOTSTS.ORDER_ID));
			memset(MINVLOTSTS.ADD_ORDER_ID_1, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_1));
			memset(MINVLOTSTS.ADD_ORDER_ID_2, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_2));
			memset(MINVLOTSTS.ADD_ORDER_ID_3, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_3));
			TRS.copy(MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID), inv_lot_list[i], "VENDOR_ID");
			TRS.copy(s_vendor_site_id, sizeof(s_vendor_site_id), inv_lot_list[i], "VENDOR_SITE_ID");
			MINVLOTSTS.VENDOR_SITE_ID =  atoi(s_vendor_site_id);
			TRS.copy(MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID), inv_lot_list[i], "VENDOR_LOT_ID");
			memcpy(MINVLOTSTS.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(MINVLOTSTS.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			memset(MINVLOTSTS.LOCATION_1, ' ', sizeof(MINVLOTSTS.LOCATION_1));
			memset(MINVLOTSTS.LOCATION_2, ' ', sizeof(MINVLOTSTS.LOCATION_2));
			memset(MINVLOTSTS.LOCATION_3, ' ', sizeof(MINVLOTSTS.LOCATION_3));
			memcpy(MINVLOTSTS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memset(MINVLOTSTS.LOC_NO, ' ', sizeof(MINVLOTSTS.LOC_NO));
			memset(MINVLOTSTS.RES_ID, ' ', sizeof(MINVLOTSTS.RES_ID));
			memset(MINVLOTSTS.PORT_ID, ' ', sizeof(MINVLOTSTS.PORT_ID));
			memset(MINVLOTSTS.SLOT_NO, ' ', sizeof(MINVLOTSTS.SLOT_NO));
			memset(MINVLOTSTS.CRR_ID, ' ', sizeof(MINVLOTSTS.CRR_ID));
			memset(MINVLOTSTS.LOT_ID, ' ', sizeof(MINVLOTSTS.LOT_ID));
			TRS.copy(MINVLOTSTS.RECV_DATE, sizeof(MINVLOTSTS.RECV_DATE), inv_lot_list[i], "ARRIVAL_DATE");
			MINVLOTSTS.RECV_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			memset(MINVLOTSTS.REASON_CODE, ' ', sizeof(MINVLOTSTS.REASON_CODE));
			MINVLOTSTS.LOAD_FLAG = 'N';
			MINVLOTSTS.TRANSIT_FLAG = 'N';
			MINVLOTSTS.DELETE_FLAG = 'N';
			memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
			memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
			memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
			MINVLOTSTS.HOLD_FLAG = 'N';
			memset(MINVLOTSTS.HOLD_CODE, ' ', sizeof(MINVLOTSTS.HOLD_CODE));
			MINVLOTSTS.INSP_FLAG = 'N';
			memset(MINVLOTSTS.INSP_ID, ' ', sizeof(MINVLOTSTS.INSP_ID));
			MINVLOTSTS.INSP_RESULT_FLAG = ' ';
			memset(MINVLOTSTS.INV_LOT_GRADE, ' ', sizeof(MINVLOTSTS.INV_LOT_GRADE));
			memset(MINVLOTSTS.DLV_NO, ' ', sizeof(MINVLOTSTS.DLV_NO));
			MINVLOTSTS.DLV_SEQ = 0;
			memset(MINVLOTSTS.PO_NO, ' ', sizeof(MINVLOTSTS.PO_NO));
			MINVLOTSTS.PO_SEQ = 0;
			memset(MINVLOTSTS.BL_NO, ' ', sizeof(MINVLOTSTS.BL_NO));
			MINVLOTSTS.BL_SEQ = 0;
			MINVLOTSTS.PO_DISTRIBUTION_ID = 0;
			TRS.copy(MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1), in_node, "MOLD_MODEL"); // 금형 모델
			TRS.copy(MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2), in_node, "MOLD_TYPE"); // 금형 구분
			memset(MINVLOTSTS.INV_CMF_3, ' ', sizeof(MINVLOTSTS.INV_CMF_3));	// 이전 공정
			memset(MINVLOTSTS.INV_CMF_4, ' ', sizeof(MINVLOTSTS.INV_CMF_4));	// Kitting ID
			TRS.copy(MINVLOTSTS.INV_CMF_5, sizeof(MINVLOTSTS.INV_CMF_5), inv_lot_list[i], "IN_TYPE");	// 기타 입고 유형
			memset(MINVLOTSTS.INV_CMF_6, ' ', sizeof(MINVLOTSTS.INV_CMF_6));	// 기타 출고 유형
			memset(MINVLOTSTS.INV_CMF_7, ' ', sizeof(MINVLOTSTS.INV_CMF_7));
			memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8));
			memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9));
			memset(MINVLOTSTS.INV_CMF_10, ' ', sizeof(MINVLOTSTS.INV_CMF_10));
			memset(MINVLOTSTS.INV_CMF_11, ' ', sizeof(MINVLOTSTS.INV_CMF_11));
			memset(MINVLOTSTS.INV_CMF_12, ' ', sizeof(MINVLOTSTS.INV_CMF_12));
			memset(MINVLOTSTS.INV_CMF_13, ' ', sizeof(MINVLOTSTS.INV_CMF_13));
			memset(MINVLOTSTS.INV_CMF_14, ' ', sizeof(MINVLOTSTS.INV_CMF_14));
			memset(MINVLOTSTS.INV_CMF_15, ' ', sizeof(MINVLOTSTS.INV_CMF_15));
			memset(MINVLOTSTS.INV_CMF_16, ' ', sizeof(MINVLOTSTS.INV_CMF_16));
			memset(MINVLOTSTS.INV_CMF_17, ' ', sizeof(MINVLOTSTS.INV_CMF_17));
			memset(MINVLOTSTS.INV_CMF_18, ' ', sizeof(MINVLOTSTS.INV_CMF_18));
			memset(MINVLOTSTS.INV_CMF_19, ' ', sizeof(MINVLOTSTS.INV_CMF_19));
			memset(MINVLOTSTS.INV_CMF_20, ' ', sizeof(MINVLOTSTS.INV_CMF_20));
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_ETC_IN, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), inv_lot_list[i], "COMMENT");
			MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = 1;
			MINVLOTSTS.LAST_HIST_SEQ = 1;
			TRS.copy(MINVLOTSTS.ORG_INV_LOT_ID, sizeof(MINVLOTSTS.ORG_INV_LOT_ID), inv_lot_list[i], "DLV_LOT_ID");
			MINVLOTSTS.FROM_TO_DIV = ' ';
			memset(MINVLOTSTS.FROM_TO_INV_LOT_ID, ' ', sizeof(MINVLOTSTS.FROM_TO_INV_LOT_ID));
			MINVLOTSTS.FROM_TO_HIST_SEQ = 0;
			MINVLOTSTS.CREATE_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.CREATE_QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.CREATE_QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			TRS.copy(MINVLOTSTS.CREATE_USER_ID, sizeof(MINVLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			//자재 LOT OLD 데이터
			//자재 생성 -> OLD, NEW 데이터 같음
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			memcpy(&MINVLOTSTS_OLD, &MINVLOTSTS, sizeof(MINVLOTSTS));

			//자재 LOT 이력 생성
			DBU_init_minvlothis(&MINVLOTHIS);

			//자재 LOT UPSERT & 자재 이력 INSERT
			if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVLOTSTS,
				&MINVLOTHIS) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
	// 마이그레이션 데이터 생성
	else if (TRS.get_procstep(in_node) == '3')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			memset(s_vendor_site_id, ' ', sizeof(s_vendor_site_id));

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), inv_lot_list[i], "MAT_ID");
			MWIPMATDEF.MAT_VER = 1;
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

			// MWIPOPRDEF - 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), inv_lot_list[i], "OPER");
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_CREATE_LOT_02) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//입고 자재 LOT 생성
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			TRS.copy(MINVLOTSTS.INV_LOT_DESC, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_DESC");
			memcpy(MINVLOTSTS.INV_LOT_TYPE, MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
			memcpy(MINVLOTSTS.INV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, sizeof(MINVLOTSTS.INV_LOT_STATUS));
			MINVLOTSTS.INV_LOT_PRIORITY = '1';
			memcpy(MINVLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MINVLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			MINVLOTSTS.QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			memcpy(MINVLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			memcpy(MINVLOTSTS.UNIT_2, MWIPMATDEF.UNIT_2, sizeof(MWIPMATDEF.UNIT_2));
			memcpy(MINVLOTSTS.UNIT_3, MWIPMATDEF.UNIT_3, sizeof(MWIPMATDEF.UNIT_3));
			memset(MINVLOTSTS.ORDER_ID, ' ', sizeof(MINVLOTSTS.ORDER_ID));
			memset(MINVLOTSTS.ADD_ORDER_ID_1, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_1));
			memset(MINVLOTSTS.ADD_ORDER_ID_2, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_2));
			memset(MINVLOTSTS.ADD_ORDER_ID_3, ' ', sizeof(MINVLOTSTS.ADD_ORDER_ID_3));
			TRS.copy(MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID), inv_lot_list[i], "VENDOR_ID");
			TRS.copy(s_vendor_site_id, sizeof(s_vendor_site_id), inv_lot_list[i], "VENDOR_SITE_ID");
			MINVLOTSTS.VENDOR_SITE_ID = atoi(s_vendor_site_id);
			TRS.copy(MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID), inv_lot_list[i], "VENDOR_LOT_ID");
			memcpy(MINVLOTSTS.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(MINVLOTSTS.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			memset(MINVLOTSTS.LOCATION_1, ' ', sizeof(MINVLOTSTS.LOCATION_1));
			memset(MINVLOTSTS.LOCATION_2, ' ', sizeof(MINVLOTSTS.LOCATION_2));
			memset(MINVLOTSTS.LOCATION_3, ' ', sizeof(MINVLOTSTS.LOCATION_3));
			memcpy(MINVLOTSTS.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memset(MINVLOTSTS.LOC_NO, ' ', sizeof(MINVLOTSTS.LOC_NO));
			memset(MINVLOTSTS.RES_ID, ' ', sizeof(MINVLOTSTS.RES_ID));
			memset(MINVLOTSTS.PORT_ID, ' ', sizeof(MINVLOTSTS.PORT_ID));
			memset(MINVLOTSTS.SLOT_NO, ' ', sizeof(MINVLOTSTS.SLOT_NO));
			memset(MINVLOTSTS.CRR_ID, ' ', sizeof(MINVLOTSTS.CRR_ID));
			memset(MINVLOTSTS.LOT_ID, ' ', sizeof(MINVLOTSTS.LOT_ID));
			memcpy(MINVLOTSTS.RECV_DATE, s_sys_time, sizeof(MINVLOTSTS.RECV_DATE));
			MINVLOTSTS.RECV_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			memset(MINVLOTSTS.REASON_CODE, ' ', sizeof(MINVLOTSTS.REASON_CODE));
			MINVLOTSTS.LOAD_FLAG = 'N';
			MINVLOTSTS.TRANSIT_FLAG = 'N';
			MINVLOTSTS.DELETE_FLAG = 'N';
			memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
			memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
			memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
			MINVLOTSTS.HOLD_FLAG = 'N';
			memset(MINVLOTSTS.HOLD_CODE, ' ', sizeof(MINVLOTSTS.HOLD_CODE));
			MINVLOTSTS.INSP_FLAG = 'N';
			memset(MINVLOTSTS.INSP_ID, ' ', sizeof(MINVLOTSTS.INSP_ID));
			MINVLOTSTS.INSP_RESULT_FLAG = ' ';
			memset(MINVLOTSTS.INV_LOT_GRADE, ' ', sizeof(MINVLOTSTS.INV_LOT_GRADE));
			memset(MINVLOTSTS.DLV_NO, ' ', sizeof(MINVLOTSTS.DLV_NO));
			MINVLOTSTS.DLV_SEQ = 0;
			memset(MINVLOTSTS.PO_NO, ' ', sizeof(MINVLOTSTS.PO_NO));
			MINVLOTSTS.PO_SEQ = 0;
			memset(MINVLOTSTS.BL_NO, ' ', sizeof(MINVLOTSTS.BL_NO));
			MINVLOTSTS.BL_SEQ = 0;
			MINVLOTSTS.PO_DISTRIBUTION_ID = 0;
			TRS.copy(MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1), inv_lot_list[i], "MOLD_MODEL"); // 금형 모델
			TRS.copy(MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2), inv_lot_list[i], "MOLD_TYPE"); // 금형 구분
			memset(MINVLOTSTS.INV_CMF_3, ' ', sizeof(MINVLOTSTS.INV_CMF_3));	// 이전 공정
			memset(MINVLOTSTS.INV_CMF_4, ' ', sizeof(MINVLOTSTS.INV_CMF_4));	// Kitting ID
			TRS.copy(MINVLOTSTS.INV_CMF_5, sizeof(MINVLOTSTS.INV_CMF_5), inv_lot_list[i], "IN_TYPE");	// 기타 입고 유형
			memset(MINVLOTSTS.INV_CMF_6, ' ', sizeof(MINVLOTSTS.INV_CMF_6));	// 기타 출고 유형
			memset(MINVLOTSTS.INV_CMF_7, ' ', sizeof(MINVLOTSTS.INV_CMF_7));
			memset(MINVLOTSTS.INV_CMF_8, ' ', sizeof(MINVLOTSTS.INV_CMF_8));
			memset(MINVLOTSTS.INV_CMF_9, ' ', sizeof(MINVLOTSTS.INV_CMF_9));
			memset(MINVLOTSTS.INV_CMF_10, ' ', sizeof(MINVLOTSTS.INV_CMF_10));
			memset(MINVLOTSTS.INV_CMF_11, ' ', sizeof(MINVLOTSTS.INV_CMF_11));
			memset(MINVLOTSTS.INV_CMF_12, ' ', sizeof(MINVLOTSTS.INV_CMF_12));
			memset(MINVLOTSTS.INV_CMF_13, ' ', sizeof(MINVLOTSTS.INV_CMF_13));
			memset(MINVLOTSTS.INV_CMF_14, ' ', sizeof(MINVLOTSTS.INV_CMF_14));
			memset(MINVLOTSTS.INV_CMF_15, ' ', sizeof(MINVLOTSTS.INV_CMF_15));
			memset(MINVLOTSTS.INV_CMF_16, ' ', sizeof(MINVLOTSTS.INV_CMF_16));
			memset(MINVLOTSTS.INV_CMF_17, ' ', sizeof(MINVLOTSTS.INV_CMF_17));
			memset(MINVLOTSTS.INV_CMF_18, ' ', sizeof(MINVLOTSTS.INV_CMF_18));
			memset(MINVLOTSTS.INV_CMF_19, ' ', sizeof(MINVLOTSTS.INV_CMF_19));
			memset(MINVLOTSTS.INV_CMF_20, ' ', sizeof(MINVLOTSTS.INV_CMF_20));
			memcpy(MINVLOTSTS.LAST_TRAN_CODE, MP_CINV_TRAN_CODE_CREATE, sizeof(MINVLOTSTS.LAST_TRAN_CODE));
			memcpy(MINVLOTSTS.LAST_TRAN_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT), in_node, "TRAN_COMMENT");
			MINVLOTSTS.LAST_ACTIVE_HIST_SEQ = 1;
			MINVLOTSTS.LAST_HIST_SEQ = 1;
			memcpy(MINVLOTSTS.ORG_INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			MINVLOTSTS.FROM_TO_DIV = ' ';
			memset(MINVLOTSTS.FROM_TO_INV_LOT_ID, ' ', sizeof(MINVLOTSTS.FROM_TO_INV_LOT_ID));
			MINVLOTSTS.FROM_TO_HIST_SEQ = 0;
			MINVLOTSTS.CREATE_QTY = TRS.get_double(inv_lot_list[i], "QTY");
			MINVLOTSTS.CREATE_QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
			MINVLOTSTS.CREATE_QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");
			TRS.copy(MINVLOTSTS.CREATE_USER_ID, sizeof(MINVLOTSTS.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(MINVLOTSTS.UPDATE_USER_ID, sizeof(MINVLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			//자재 LOT OLD 데이터
			//자재 생성 -> OLD, NEW 데이터 같음
			DBU_init_minvlotsts(&MINVLOTSTS_OLD);
			memcpy(&MINVLOTSTS_OLD, &MINVLOTSTS, sizeof(MINVLOTSTS));

			//자재 LOT 이력 생성
			DBU_init_minvlothis(&MINVLOTHIS);

			//자재 LOT UPSERT & 자재 이력 INSERT
			if (CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(s_msg_code,
				in_node,
				out_node,
				s_sys_time,
				&MINVLOTSTS_OLD,
				&MINVLOTSTS,
				&MINVLOTHIS) == MP_FALSE)
			{
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
   
	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Create_Lot_Validation()
        - Validation Check sub function of "CUS_INV_CREATE_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Create_Lot_Before_Transaction()
- Main sub function of "CUS_INV_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Lot_After_Transaction()
- Main sub function of "CUS_INV_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct CBASTXNDEF_TAG CBASTXNDEF_ETC;
	struct IF_PO_RCV_HEADER_TAG IF_PO_RCV_HEADER;
	struct IF_PO_RCV_TXNS_TAG IF_PO_RCV_TXNS;
	struct MINVETCLOT_TAG MINVETCLOT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_WH;

	//I/F용 필요 테이블
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;

	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	TRSNode *erpif_in;
	TRSNode *cmn_out;
	int i;
    double dHeaderSeq = 0;
    double dDtlSeq = 0;

	// 자재 입하 정보를 이용한 자재 입고
	if (TRS.get_procstep(in_node) == '1')
	{
		//자재 생성 -> 자재 입고
		if (CUS_INV_IN_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}

        if (TRS.get_char(in_node, "SKIP_IF") == 'Y')
        {
            return MP_TRUE;
        }

		// MINVDLVLOT - 입하 자재 LOT 정보 조회
		DBU_init_minvdlvlot(&MINVDLVLOT);
		TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
		DBU_select_minvdlvlot(1, &MINVDLVLOT);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		DBU_init_minvdlvmst(&MINVDLVMST);
		TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVMST.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		DBU_select_minvdlvmst(1, &MINVDLVMST);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// MINVDLVDTL - 구매 입고 상세 정보 조회
		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
		MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
		DBU_select_minvdlvdtl(1, &MINVDLVDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
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
		memcpy(MWIPMATDEF.MAT_ID, MINVDLVDTL.MAT_ID, sizeof(MINVDLVDTL.MAT_ID));
		MWIPMATDEF.MAT_VER = MINVDLVDTL.MAT_VER;
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

		//area 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT.KEY_1, MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
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

		//위탁 재고 입고 I/F
		if (MINVDLVDTL.CONSIGNMENT_FLAG == 'Y')
		{
			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_41);
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
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_41);
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

			inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

			for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
			{
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0044");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
					}
					else
					{
						strcpy(s_msg_code, "WIP-0004");
						gs_log_type.e_type = MP_LOG_E_SYSTEM;

					}
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				// 창고
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_create_lot_03) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//ERP 실적 - IF_PO_CONSIGN_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE_NAME", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
				TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
				TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
				TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
				TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_PO_CONSIGN_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
		//일반 구매 입고 I/F
		else
		{

			//20220303 금형입고 창고 다시 조회 하도록 수정(한국과 베트남 로직다름,한국은 바로 금형창고 베트남은 원자재 창고 가따가 금형창고로)

			//memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_MOLD, strlen(MP_OPER_GRP_TYPE_MOLD));

			// MWIPOPRDEF - 자재 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.AREA_ID, MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));

            // 품목이 금형인 경우 금형창고를 구분하여 조회한다.
            if (MWIPMATDEF.MAT_CMF_9[0] == 'Y')
            {


				DBU_init_mgcmtbldat(&MGCMTBLDAT_WH);
				TRS.copy(MGCMTBLDAT_WH.FACTORY, sizeof(MGCMTBLDAT_WH.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_WH.TABLE_NAME, MP_GCM_MOLD_OPER, strlen(MP_GCM_MOLD_OPER));

				//2022/03/02 한국은 바로 금형창고로 베트남은 원자재 창고에서 금형창고로 분출하는것으로 프로세스 바꿈.




				memcpy(MGCMTBLDAT_WH.KEY_1, MINVDLVMST.AREA_ID, sizeof(MGCMTBLDAT_WH.KEY_1));

				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_WH);
				if (DB_error_code != DB_SUCCESS)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_WH.FACTORY), MGCMTBLDAT_WH.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_WH.TABLE_NAME), MGCMTBLDAT_WH.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_WH.KEY_1), MGCMTBLDAT_WH.KEY_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				memcpy(MWIPOPRDEF.OPER_GRP_1, MGCMTBLDAT_WH.DATA_4, sizeof(MWIPOPRDEF.OPER_GRP_1));
	

            }
            else
            {
                //memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, sizeof(MWIPOPRDEF.OPER_GRP_1));
                memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV));
            }
            
			MWIPOPRDEF.INV_FLAG = 'Y';

			DBU_select_mwipoprdef(3, &MWIPOPRDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_CREATE_LOT_04) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//ERP 실적 - IF_PO_RCV_HEADER
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_int(erpif_in, "VENDOR_ID", COM_atoi(MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID)));
			TRS.add_int(erpif_in, "VENDOR_SITE_ID", MINVDLVMST.VENDOR_SITE_ID);
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
			TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_RCV_HEADER(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_po_rcv_header(&IF_PO_RCV_HEADER);
			TRS.copy(IF_PO_RCV_HEADER.FACTORY, sizeof(IF_PO_RCV_HEADER.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_PO_RCV_HEADER.MES_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
			//DBU_select_if_po_rcv_header(2, &IF_PO_RCV_HEADER);
            //seq값은 max값에서 가져오도록 수정 _ 2020.12.21 _lwg
            dHeaderSeq = DBU_select_if_po_rcv_header_scalar(2, &IF_PO_RCV_HEADER);

			//ERP 실적 - IF_PO_RCV_TXNS
			erpif_in = TRS.add_node(in_node, "erpif_in");
			TRS.add_char(erpif_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(erpif_in, in_node);

			TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
			TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
			TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
			TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
			TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
			TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
			TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
			TRS.add_string(erpif_in, "PO_TYPE", MINVDLVDTL.PO_TYPE, sizeof(MINVDLVDTL.PO_TYPE));
			TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
			TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(erpif_in, "OPER_CODE", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_double(erpif_in, "QTY", MINVDLVLOT.QTY);
			TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
			TRS.add_string(erpif_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
			TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
			TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_PO_RCV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			DBU_init_if_po_rcv_txns(&IF_PO_RCV_TXNS);
			TRS.copy(IF_PO_RCV_TXNS.FACTORY, sizeof(IF_PO_RCV_TXNS.FACTORY), in_node, IN_FACTORY);
			IF_PO_RCV_TXNS.RCV_HEADER_ID = dHeaderSeq;
			memcpy(IF_PO_RCV_TXNS.MES_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
			//DBU_select_if_po_rcv_txns(2, &IF_PO_RCV_TXNS);
            //seq값은 max값에서 가져오도록 수정 _ 2020.12.21 _lwg
            dDtlSeq = DBU_select_if_po_rcv_txns_scalar(2, &IF_PO_RCV_TXNS);

			inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

			for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
			{
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0044");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
					}
					else
					{
						strcpy(s_msg_code, "WIP-0004");
						gs_log_type.e_type = MP_LOG_E_SYSTEM;

					}
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//ERP 실적 - IF_PO_RCV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "RCV_HEADER_ID", dHeaderSeq);
				TRS.add_double(erpif_in, "RCV_TXN_ID", dDtlSeq);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_PO_RCV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
	}
	// 기타 입고를 통한 자재 생성
	else if (TRS.get_procstep(in_node) == '2')
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

		// 기타 입고 생성 후, 클라이언트로 정보 전송
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), inv_lot_list[i], "OPER");
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

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(CUS_INV_CREATE_LOT_05)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

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
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//LOT 데이터 조회
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
			DBU_select_minvlotsts(1, &MINVLOTSTS);
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
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// MWIPMATDEF - 제품 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
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

			//기타입고 정보 저장
			DBU_init_minvetclot(&MINVETCLOT);
			TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVETCLOT.LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			MINVETCLOT.SEQ = 1;
			memcpy(MINVETCLOT.LOT_TYPE, MP_ETC_LOT_TYPE_INV, sizeof(MINVETCLOT.LOT_TYPE));
			MINVETCLOT.QTY = MINVLOTSTS.QTY;
			memcpy(MINVETCLOT.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MINVETCLOT.MAT_VER = MWIPMATDEF.MAT_VER;
			memcpy(MINVETCLOT.AREA_ID, MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
			memcpy(MINVETCLOT.SUB_AREA_ID, MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
			memcpy(MINVETCLOT.OPER, MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
			memcpy(MINVETCLOT.VENDOR_ID, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			MINVETCLOT.VENDOR_SITE_ID = MINVLOTSTS.VENDOR_SITE_ID;
			memcpy(MINVETCLOT.VENDOR_LOT_ID, MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
			memcpy(MINVETCLOT.ETC_TYPE, MP_ETC_TYPE_IN, sizeof(MINVETCLOT.ETC_TYPE));
			memcpy(MINVETCLOT.ETC_DATE, MINVLOTSTS.RECV_DATE, sizeof(MINVLOTSTS.RECV_DATE));
			MINVETCLOT.TRAN_SRC_ID = 0;
			memset(MINVETCLOT.TRAN_SRC_NAME, ' ', sizeof(MINVETCLOT.TRAN_SRC_NAME));
			memcpy(MINVETCLOT.ETC_COMMENT, MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT));

			//211118 테스트품 작지를 자재투입하여 기타출고 하는경우 구분되도록(CMF_1:LOT_TYPE,CMF_2:ORDER_ID정보 ,CMF_3:LOT정보
			//211118 CMF_1 : A(일반),B(MES단독처리),C(테스트품자재투입),D(약식검사 LOSS)
			if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
			{
				memcpy(MINVETCLOT.CMF_1, "A", strlen("A"));
			}
			else
			{
				memcpy(MINVETCLOT.CMF_1, "B", strlen("B"));
			}
			memset(MINVETCLOT.CMF_2, ' ', sizeof(MINVETCLOT.CMF_2));
			memset(MINVETCLOT.CMF_3, ' ', sizeof(MINVETCLOT.CMF_3));


			TRS.copy(MINVETCLOT.CREATE_USER_ID, sizeof(MINVETCLOT.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVETCLOT.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
			TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

			if (TRS.get_char(in_node, "ERP_FLAG") == 'Y')
			{
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
				CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MINVLOTSTS.INV_CMF_5, sizeof(MINVLOTSTS.INV_CMF_5));
				CBASTXNDEF_ETC.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
				DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

				if (DB_error_code == DB_NOT_FOUND)
				{
					//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
					//MST(ERP AREA ID : 103)
					//임시로 하드코딩
					DBU_init_cbastxndef(&CBASTXNDEF_ETC);
					TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
					CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MINVLOTSTS.INV_CMF_5, sizeof(MINVLOTSTS.INV_CMF_5));
					CBASTXNDEF_ETC.ERP_AREA_ID = 103;
					DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);

					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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
				}

				MINVETCLOT.TRAN_SRC_ID = CBASTXNDEF_ETC.TRAN_SRC_ID;
				memcpy(MINVETCLOT.TRAN_SRC_NAME, CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));

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
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정

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
				memcpy(IF_INV_TXNS.MES_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID)); //추후 이동지시번호가 들어올예정
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

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

			//기타입고 화면으로 리스트 전송
			inv_list = TRS.add_node(out_node, "INV_LOT_LIST");
			TRS.add_nstring(inv_list, "LOT_ID", TRS.get_string(inv_lot_list[i], "INV_LOT_ID"));
			TRS.add_int(inv_list, "SEQ", i + 1);
			TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
			TRS.add_string(inv_list, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_string(inv_list, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			TRS.add_string(inv_list, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_string(inv_list, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
			TRS.add_string(inv_list, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(inv_list, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_string(inv_list, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_nstring(inv_list, "ARRIVAL_DATE", TRS.get_string(inv_lot_list[i], "ARRIVAL_DATE"));
			TRS.add_nstring(inv_list, "IN_TYPE", TRS.get_string(inv_lot_list[i], "IN_TYPE"));
			TRS.add_nstring(inv_list, "VENDOR_ID", TRS.get_string(inv_lot_list[i], "VENDOR_ID"));
			TRS.add_nstring(inv_list, "VENDOR_SITE_ID", TRS.get_string(inv_lot_list[i], "VENDOR_SITE_ID"));
			TRS.add_nstring(inv_list, "VENDOR_LOT_ID", TRS.get_string(inv_lot_list[i], "VENDOR_LOT_ID"));
		}
	}

	return MP_TRUE;
}