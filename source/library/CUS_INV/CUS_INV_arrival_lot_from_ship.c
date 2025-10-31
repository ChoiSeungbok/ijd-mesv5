/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_arrival_lot_from_ship.c
    Description : Arrival Lot From Ship 

    MES Version : 5.2.0

    Function List
        - CUS_INV_Arrival_Lot_From_Ship()
            + Arrival Lot From Ship
        - CUS_INV_ARRIVAL_LOT_FROM_SHIP()
            + Main Sub function of "CUS_INV_Arrival_Lot_From_Ship"
            + (called by "CUS_INV_Arrival_Lot_From_Ship")
        - CUS_INV_Arrival_Lot_From_Ship_Validation()
            + Validation Check sub function of "CUS_INV_ARRIVAL_LOT_FROM_SHIP" function
            + (called by "CUS_INV_ARRIVAL_LOT_FROM_SHIP")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2021/01/05  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_ARRIVAL_LOT_FROM_SHIP(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Arrival_Lot_From_Ship_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Arrival_Lot_From_Ship_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Arrival_Lot_From_Ship_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Arrival_Lot_From_Ship()
        - Arrival Lot From Ship
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Arrival_Lot_From_Ship_In_Tag *CUS_INV_Arrival_Lot_From_Ship_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Arrival_Lot_From_Ship(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_ARRIVAL_LOT_FROM_SHIP", out_node);

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
CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN()
- Main sub function of "CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *create_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;

	LOG_head("CUS_INV_ARRIVAL_LOT_FROM_SHIP");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Arrival_Lot_From_Ship_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));
    TRS.add_nstring(create_in_node, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
    TRS.add_double(create_in_node, "TOTAL_QTY", TRS.get_double(in_node, "TOTAL_QTY"));
    
	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_list, "ORG_LOT_ID", TRS.get_string(inv_lot_list[i], "ORG_LOT_ID"));
		TRS.add_nstring(inv_list, "PACK_LOT_ID", TRS.get_string(inv_lot_list[i], "PACK_LOT_ID"));
		TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
		TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
		TRS.add_nstring(inv_list, "MAT_ID", TRS.get_string(inv_lot_list[i], "MAT_ID"));
		TRS.add_int(inv_list, "MAT_VER", TRS.get_int(inv_lot_list[i], "MAT_VER"));
		TRS.add_nstring(inv_list, "DLV_NO", TRS.get_string(inv_lot_list[i], "DLV_NO"));
		TRS.add_int(inv_list, "DLV_SEQ", TRS.get_int(inv_lot_list[i], "DLV_SEQ"));
		TRS.add_nstring(inv_list, "DLV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
		TRS.add_nstring(inv_list, "DLV_TIME", TRS.get_string(inv_lot_list[i], "DLV_TIME"));
		TRS.add_nstring(inv_list, "VENDOR_LOT_ID", TRS.get_string(inv_lot_list[i], "VENDOR_LOT_ID"));
		TRS.add_nstring(inv_list, "VENDOR_ID", TRS.get_string(inv_lot_list[i], "VENDOR_ID"));
		TRS.add_nstring(inv_list, "VENDOR_SITE_ID", TRS.get_string(inv_lot_list[i], "VENDOR_SITE_ID"));
	}

	if (CUS_INV_Arrival_Lot_From_Ship_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_ARRIVAL_LOT_FROM_SHIP(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Arrival_Lot_From_Ship_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_ARRIVAL_LOT_FROM_SHIP()
        - Main sub function of "CUS_INV_Arrival_Lot_From_Ship" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_ARRIVAL_LOT_FROM_SHIP_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_ARRIVAL_LOT_FROM_SHIP(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct ISHPLOTRCV_TAG ISHPLOTRCV;
	struct MGCMLAGDAT_TAG MGCMLAGDAT;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;
    struct ISHPISPRCV_TAG ISHPISPRCV;

	TRSNode **inv_lot_list;
	TRSNode *lbl_list;
	TRSNode *inv_list;
	TRSNode *dlv_lot_create_in;
	TRSNode *dlv_lbl_create_in;
	TRSNode *dlv_lot_confirm_in;
	TRSNode *inv_lot_create_in;
	TRSNode *cmn_out;
	
    int i;

    //AREA 정보 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT);
    TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA_OPTION, strlen(MP_GCM_AREA_OPTION));
    TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "AREA_ID");

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

        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		//VENDOR 정보 조회
		DBU_init_mgcmlagdat(&MGCMLAGDAT);
		TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
		TRS.copy(MGCMLAGDAT.KEY_1, sizeof(MGCMLAGDAT.KEY_1), inv_lot_list[i], "VENDOR_ID");
		TRS.copy(MGCMLAGDAT.KEY_2, sizeof(MGCMLAGDAT.KEY_2), inv_lot_list[i], "VENDOR_SITE_ID");
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

		// 입하 LOT 생성
		dlv_lot_create_in = TRS.add_node(in_node, "dlv_lot_create_in");
		CopyDefaultMembers(dlv_lot_create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(dlv_lot_create_in, "PROCSTEP", '1');
		TRS.add_nstring(dlv_lot_create_in, "DLV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
		TRS.add_nstring(dlv_lot_create_in, "MAT_ID", TRS.get_string(inv_lot_list[i], "MAT_ID"));
		TRS.add_int(dlv_lot_create_in, "MAT_VER", TRS.get_int(inv_lot_list[i], "MAT_VER"));
		TRS.add_double(dlv_lot_create_in, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		TRS.add_double(dlv_lot_create_in, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
		TRS.add_double(dlv_lot_create_in, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
		TRS.add_nstring(dlv_lot_create_in, "DLV_NO", TRS.get_string(inv_lot_list[i], "DLV_NO"));
		TRS.add_int(dlv_lot_create_in, "DLV_SEQ", TRS.get_int(inv_lot_list[i], "DLV_SEQ"));
		TRS.add_nstring(dlv_lot_create_in, "DLV_TIME", TRS.get_string(inv_lot_list[i], "DLV_TIME"));
		TRS.add_nstring(dlv_lot_create_in, "VENDOR_LOT_ID", TRS.get_string(inv_lot_list[i], "VENDOR_LOT_ID"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_CREATE_DLV_LOT_MAIN(s_msg_code, dlv_lot_create_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		// 입하 LABEL 정보 생성
		dlv_lbl_create_in = TRS.add_node(in_node, "dlv_lbl_create_in");
		CopyDefaultMembers(dlv_lbl_create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(dlv_lbl_create_in, "PROCSTEP", '1');
		TRS.add_nstring(dlv_lbl_create_in, "DLV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
		TRS.add_nstring(dlv_lbl_create_in, "VENDOR_ID", TRS.get_string(inv_lot_list[i], "VENDOR_ID"));
		TRS.add_nstring(dlv_lbl_create_in, "VENDOR_SITE_ID", TRS.get_string(inv_lot_list[i], "VENDOR_SITE_ID"));

		lbl_list = TRS.add_node(dlv_lbl_create_in, "INV_LOT_LIST");

        //area 옵션 중 각 area 별 법인별 입고 lot 유형을 선택한 id로 자재lot 생성.
        //베트남 -> 음성으로 출하 입고된 것은 출하lot id로 입고되며, 음성 -> 베트남은 공정lot id로 입고
        if (memcmp(MGCMTBLDAT.DATA_3, MP_SHIP_INPUT_PACK_LOT_ID, strlen(MP_SHIP_INPUT_PACK_LOT_ID)) == MP_FALSE)
        {
            TRS.add_nstring(lbl_list, "LABEL_ID", TRS.get_string(inv_lot_list[i], "PACK_LOT_ID"));
        }
        else
        {
           // TRS.add_nstring(lbl_list, "LABEL_ID", TRS.get_string(inv_lot_list[i], "ORG_LOT_ID"));
			TRS.add_nstring(lbl_list, "LABEL_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
        }

		TRS.add_double(lbl_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		TRS.add_double(lbl_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
		TRS.add_double(lbl_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_CREATE_DLV_LABEL_MAIN(s_msg_code, dlv_lbl_create_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		// 입하 LOT 확정 -> 수입검사 호출 -> 무검사(자동 PASS 정보 생성)
		dlv_lot_confirm_in = TRS.add_node(in_node, "dlv_lot_confirm_in");
		CopyDefaultMembers(dlv_lot_confirm_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(dlv_lot_confirm_in, "PROCSTEP", '1');
		TRS.add_nstring(dlv_lot_confirm_in, "DLV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_CONFIRM_DLV_LOT_MAIN(s_msg_code, dlv_lot_confirm_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO), inv_lot_list[i], "DLV_NO");
		MINVDLVDTL.DLV_SEQ = TRS.get_int(inv_lot_list[i], "DLV_SEQ");
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

		// MWIPOPRDEF - 자재 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.AREA_ID, MINVDLVDTL.AREA_ID, sizeof(MINVDLVDTL.AREA_ID));

		if (MINVDLVDTL.CONSIGNMENT_FLAG == 'Y')
		{
			memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, sizeof(MWIPOPRDEF.OPER_GRP_1));
		}
		else
		{
			memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, sizeof(MWIPOPRDEF.OPER_GRP_1));
		}

		MWIPOPRDEF.INV_FLAG = 'Y';

		DBU_select_mwipoprdef(3, &MWIPOPRDEF);
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

		// 입고 자재 LOT 정보 생성
		inv_lot_create_in = TRS.add_node(in_node, "inv_lot_create_in");
		CopyDefaultMembers(inv_lot_create_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(inv_lot_create_in, "PROCSTEP", '1');
		TRS.add_nstring(inv_lot_create_in, "DLV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
		TRS.add_string(inv_lot_create_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

        TRS.add_char(inv_lot_create_in, "SKIP_IF", 'Y');

		inv_list = TRS.add_node(inv_lot_create_in, "INV_LOT_LIST");

        //area 옵션 중 각 area 별 법인별 입고 lot 유형을 선택한 id로 자재lot 생성.
        //베트남 -> 음성으로 출하 입고된 것은 출하lot id로 입고되며, 음성 -> 베트남은 공정lot id로 입고
        if (memcmp(MGCMTBLDAT.DATA_3, MP_SHIP_INPUT_PACK_LOT_ID, strlen(MP_SHIP_INPUT_PACK_LOT_ID)) == MP_FALSE)
        {
            TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "PACK_LOT_ID"));
        }
        else
        {
            //TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "ORG_LOT_ID"));
			TRS.add_nstring(inv_list, "INV_LOT_ID", TRS.get_string(inv_lot_list[i], "DLV_LOT_ID"));
        }

		TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
		TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_CREATE_LOT_MAIN(s_msg_code, inv_lot_create_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		// 출하 정보 조회
		DBU_init_ishplotrcv(&ISHPLOTRCV);
		TRS.copy(ISHPLOTRCV.FACTORY, sizeof(ISHPLOTRCV.FACTORY), in_node, IN_FACTORY);
		TRS.copy(ISHPLOTRCV.ORG_LOT_ID, sizeof(ISHPLOTRCV.ORG_LOT_ID), inv_lot_list[i], "ORG_LOT_ID");
		TRS.copy(ISHPLOTRCV.PACK_LOT_ID, sizeof(ISHPLOTRCV.PACK_LOT_ID), inv_lot_list[i], "PACK_LOT_ID");
		DBU_select_ishplotrcv(1, &ISHPLOTRCV);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "ISHPLOTRCV SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ISHPLOTRCV.FACTORY), ISHPLOTRCV.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTRCV.ORG_LOT_ID), ISHPLOTRCV.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTRCV.PACK_LOT_ID), ISHPLOTRCV.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 출하 정보 RECEIVE_FLAG 업데이트
		ISHPLOTRCV.RECEIVE_FLAG = 'Y';
        TRS.copy(ISHPLOTRCV.CMF_1, sizeof(ISHPLOTRCV.CMF_1), inv_lot_list[i], "DLV_LOT_ID");
		TRS.copy(ISHPLOTRCV.UPDATE_USER_ID, sizeof(ISHPLOTRCV.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(ISHPLOTRCV.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		DBU_update_ishplotrcv(1, &ISHPLOTRCV);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "ISHPLOTRCV UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ISHPLOTRCV.FACTORY), ISHPLOTRCV.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTRCV.ORG_LOT_ID), ISHPLOTRCV.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTRCV.PACK_LOT_ID), ISHPLOTRCV.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

        //한국공장의 CTM인경우 
        //(베트남 -> 음성으로 보낸 제품에 대해서만 검사데이터도 RECEIVE_FLAG = 'Y' 처리 해준다. )
        if (memcmp(MINVDLVDTL.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
        {
            DBU_init_ishpisprcv(&ISHPISPRCV);
            TRS.copy(ISHPISPRCV.FACTORY, sizeof(ISHPISPRCV.FACTORY), in_node, IN_FACTORY);
            TRS.copy(ISHPISPRCV.ORG_LOT_ID, sizeof(ISHPISPRCV.ORG_LOT_ID), inv_lot_list[i], "ORG_LOT_ID");
            TRS.copy(ISHPISPRCV.PACK_LOT_ID, sizeof(ISHPISPRCV.PACK_LOT_ID), inv_lot_list[i], "PACK_LOT_ID");
            
            if (DBU_select_ishpisprcv_scalar(2, &ISHPISPRCV) > 0)
            {
                // 출하 정보 RECEIVE_FLAG 업데이트
                ISHPISPRCV.RECEIVE_FLAG = 'Y';
                TRS.copy(ISHPISPRCV.UPDATE_USER_ID, sizeof(ISHPISPRCV.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(ISHPISPRCV.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                DBU_update_ishpisprcv(2, &ISHPISPRCV);

                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "INV-0004");
                    TRS.add_fieldmsg(out_node, "ISHPISPRCV UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ISHPISPRCV.FACTORY), ISHPISPRCV.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPRCV.ORG_LOT_ID), ISHPISPRCV.ORG_LOT_ID);
                    TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPRCV.PACK_LOT_ID), ISHPISPRCV.PACK_LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }
	}
   
	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Arrival_Lot_From_Ship_Validation()
        - Validation Check sub function of "CUS_INV_ARRIVAL_LOT_FROM_SHIP" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_ARRIVAL_LOT_FROM_SHIP_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Arrival_Lot_From_Ship_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Arrival_Lot_From_Ship_Before_Transaction()
- Main sub function of "CUS_INV_ARRIVAL_LOT_FROM_SHIP" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Arrival_Lot_From_Ship_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Arrival_Lot_From_Ship_After_Transaction()
- Main sub function of "CUS_INV_ARRIVAL_LOT_FROM_SHIP" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Arrival_Lot_From_Ship_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MINVDLVMST_TAG MINVDLVMST;
    struct MINVDLVDTL_TAG MINVDLVDTL;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_OPTION;
    //struct MINVDLVLOT_TAG MINVDLVLOT;
    struct IF_PO_RCV_HEADER_TAG IF_PO_RCV_HEADER;
    struct IF_PO_RCV_TXNS_TAG IF_PO_RCV_TXNS;

    TRSNode **inv_lot_list;
    TRSNode *erpif_in;
    TRSNode *cmn_out;
    int i;
    int k;
    double dHeaderSeq = 0;
    double dDtlSeq = 0;
    char sMESID[30];
    double dSumqty = 0;

    memset(sMESID, 0x00, sizeof(sMESID));

    //AREA 정보 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT_OPTION);
    TRS.copy(MGCMTBLDAT_OPTION.FACTORY, sizeof(MGCMTBLDAT_OPTION.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT_OPTION.TABLE_NAME, MP_GCM_AREA_OPTION, strlen(MP_GCM_AREA_OPTION));
    TRS.copy(MGCMTBLDAT_OPTION.KEY_1, sizeof(MGCMTBLDAT_OPTION.KEY_1), in_node, "AREA_ID");

    DBU_select_mgcmtbldat(1, &MGCMTBLDAT_OPTION);
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

        TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPTION SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_OPTION.FACTORY), MGCMTBLDAT_OPTION.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_OPTION.KEY_1), MGCMTBLDAT_OPTION.KEY_1);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

    //입고 수량이을 계산한다.
    if (TRS.get_double(in_node, "TOTAL_QTY") != 0)
    {
        dSumqty = TRS.get_double(in_node, "TOTAL_QTY");
    }
    else
    {
        for (k = 0; k < TRS.get_item_count(in_node, "INV_LOT_LIST"); k++)
        {
            dSumqty = dSumqty + TRS.get_double(inv_lot_list[k], "QTY");
        }
    }

    for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
    {
        if (i == 0)
        {
            DBU_init_minvdlvmst(&MINVDLVMST);
            TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO), inv_lot_list[i], "DLV_NO");
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
            memcpy(MINVDLVDTL.DLV_NO, MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
            //MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
            MINVDLVDTL.DLV_SEQ = TRS.get_int(inv_lot_list[i], "DLV_SEQ");

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

            // MWIPOPRDEF - 자재 창고 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
            memcpy(MWIPOPRDEF.AREA_ID, MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
            memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV));
            MWIPOPRDEF.INV_FLAG = 'Y';
            DBU_select_mwipoprdef(3, &MWIPOPRDEF);

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

            COM_itoa_left(sMESID, MINVDLVDTL.PO_DISTRIBUTION_ID, sizeof(sMESID));

            //ERP 실적 - IF_PO_RCV_HEADER
            erpif_in = TRS.add_node(in_node, "erpif_in");
            TRS.add_char(erpif_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(erpif_in, in_node);

            TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
            TRS.add_int(erpif_in, "VENDOR_ID", COM_atoi(MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID)));
            TRS.add_int(erpif_in, "VENDOR_SITE_ID", MINVDLVMST.VENDOR_SITE_ID);
            TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2)));
            TRS.add_string(erpif_in, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
            //TRS.add_string(erpif_in, "MES_ID", MINVDLVDTL.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));

            TRS.add_string(erpif_in, "MES_ID", sMESID, sizeof(sMESID));

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
            //memcpy(IF_PO_RCV_HEADER.MES_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
            memcpy(IF_PO_RCV_HEADER.MES_ID, sMESID, sizeof(sMESID));

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
            //TRS.add_double(erpif_in, "QTY", MINVDLVLOT.QTY);
            TRS.add_double(erpif_in, "QTY", dSumqty);
            TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            //TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
            TRS.add_string(erpif_in, "MES_ID", sMESID, sizeof(sMESID));
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
            //memcpy(IF_PO_RCV_TXNS.MES_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
            memcpy(IF_PO_RCV_TXNS.MES_ID, sMESID, sizeof(sMESID));

            dDtlSeq = DBU_select_if_po_rcv_txns_scalar(2, &IF_PO_RCV_TXNS);
        }

        DBU_init_minvlotsts(&MINVLOTSTS);
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        //TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");
        if (memcmp(MGCMTBLDAT_OPTION.DATA_3, MP_SHIP_INPUT_PACK_LOT_ID, strlen(MP_SHIP_INPUT_PACK_LOT_ID)) == MP_FALSE)
        {
            TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "PACK_LOT_ID");
        }
        else
        {
            //TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "ORG_LOT_ID");
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "DLV_LOT_ID");
        }

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
        //TRS.add_string(erpif_in, "MES_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
        TRS.add_string(erpif_in, "MES_ID", sMESID, sizeof(sMESID));
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
    

	return MP_TRUE;
}