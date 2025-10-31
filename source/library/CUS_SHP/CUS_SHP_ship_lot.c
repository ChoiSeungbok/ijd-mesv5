/*******************************************************************************

    System      : MESplus
    Module      : CUS_SHP
    File Name   : CUS_SHP_ship_lot.c
    Description : Ship Lot

    MES Version : 5.2.0

    Function List
        - CUS_SHP_Ship_Lot()
            + Ship Lot
        - CUS_SHP_SHIP_LOT()
            + Main Sub function of "CUS_SHP_Ship_Lot"
            + (called by "CUS_SHP_Ship_Lot")
        - CUS_SHP_Ship_Lot_Validation()
            + Validation Check sub function of "CUS_SHP_SHIP_LOT" function
            + (called by "CUS_SHP_SHIP_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/31  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_SHIP_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Ship_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Ship_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_SHP_Ship_Lot()
        - Ship Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_SHP_Ship_Lot_In_Tag *CUS_SHP_Ship_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Ship_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_SHIP_LOT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_SHIP_LOT", out_node);

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
CUS_SHP_SHIP_LOT_MAIN()
- Main sub function of "CUS_SHP_SHIP_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_SHIP_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_SHIP_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *ship_in_node;
	TRSNode **pack_list;
	TRSNode *lot_list;
	TRSNode *order_list;
	int i;

	LOG_head("CUS_SHP_SHIP_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_SHP_Ship_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	ship_in_node = TRS.add_node(in_node, "ship_in_node");
	CopyDefaultMembers(ship_in_node, in_node);

	TRS.add_char(ship_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	//PROCSTEP(4) : 출하 지시에 등록된 모든 LOT

	
	if (TRS.get_procstep(in_node) == '1' || TRS.get_procstep(in_node) == '2' || TRS.get_procstep(in_node) == '3')
	{
		TRS.add_nstring(ship_in_node, "SHIP_ORDER_ID", TRS.get_string(in_node, "SHIP_ORDER_ID"));
		TRS.add_double(ship_in_node, "TOTAL_QTY", TRS.get_double(in_node, "TOTAL_QTY"));

		pack_list = TRS.get_list(in_node, "PACK_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
		{
			lot_list = TRS.add_node(ship_in_node, "PACK_LOT_LIST");
			TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(pack_list[i], "ORG_LOT_ID"));
			TRS.add_nstring(lot_list, "PACK_LOT_ID", TRS.get_string(pack_list[i], "PACK_LOT_ID"));
		}
	}
	else
	{
		pack_list = TRS.get_list(in_node, "SHIP_ORDER_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "SHIP_ORDER_LIST"); i++)
		{
			order_list = TRS.add_node(ship_in_node, "SHIP_ORDER_LIST");
			TRS.add_nstring(order_list, "SHIP_ORDER_ID", TRS.get_string(pack_list[i], "SHIP_ORDER_ID"));
		}
	}
	
	
	if (CUS_SHP_Ship_Lot_Before_Transaction(s_msg_code, 0, ship_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_SHIP_LOT(s_msg_code, ship_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Ship_Lot_After_Transaction(s_msg_code, 0, ship_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_SHP_SHIP_LOT()
        - Main sub function of "CUS_SHP_Ship_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_SHIP_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_SHIP_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct CSHPORDMST_TAG CSHPORDMST;
	struct CSHPORDDTL_TAG CSHPORDDTL;
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	struct CSHPORDDTL_TAG CSHPORDDTL_COUNT;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_CUS;
	struct IF_OM_SHIP_HEADERS_TAG IF_OM_SHIP_HEADERS;
	struct IF_OM_SHIP_LINES_TAG IF_OM_SHIP_LINES;
	struct ISHPLOTISS_TAG ISHPLOTISS;   
	struct CWIPPRSRUN_TAG CWIPPRSRUN;
	struct MRASRESDEF_TAG MRASRESDEF;           
    struct CQCMISPSTS_TAG CQCMISPSTS;
    struct CQCMISPDAT_TAG CQCMISPDAT;
    struct ISHPISPISS_TAG ISHPISPISS;

	TRSNode *erpif_in;
	TRSNode *terminate_in;
	TRSNode *cmn_out;

    char s_sys_time[14];
	char s_customer_site_id[10];

	int i;
	//int i_step = 0;
	int i_not_regist_count = 0;
	double d_lot_count = 0;
	double d_ship_dtl_count = 0;
	int send_flag = 0;
	int dtl_send_flag = 0;

	TRSNode **pack_lot_list;
	TRSNode **order_list;
		  
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_customer_site_id, ' ', sizeof(s_customer_site_id));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	if (TRS.get_procstep(in_node) == '1' || TRS.get_procstep(in_node) == '2' || TRS.get_procstep(in_node) == '3')
	{
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

		// 출하 지시 마스터 상태 체크
		// 출하 -> WAIT 상태에서 가능
		if (memcmp(CSHPORDMST.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
		{
			//WIP-0575 : 해당 출하 지시는 이미 출하되었습니다.
			strcpy(s_msg_code, "WIP-0575");
			TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
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
			// MWIPLOTSTS - 포장 LOT 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
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

			// 포장 LOT 잠금 여부 체크
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

			// 포장 LOT 삭제 여부 체크
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
				return MP_FALSE;
			}

			// CPAKLOTSTS - 포장 LOT 정보 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
			TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
			DBU_select_cpaklotsts(1, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 LOT 포장 상태 체크
			// 출하 -> PACK_FLAG(Y) 상태에서 가능
			if (CPAKLOTSTS.PACK_FLAG != 'Y')
			{
				// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0576");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 포장 LOT 출하 상태 체크
			// 출하 -> SHIP_FLAG(N) 상태에서 가능
			if (CPAKLOTSTS.SHIP_FLAG != 'N')
			{
				//WIP-0569 : 해당 포장 Lot은 이미 출하되었습니다.
				strcpy(s_msg_code, "WIP-0569");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
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

				return MP_FALSE;
			}

			// PROCSTEP : 1 -> 출하 등록
			// PROCSTEP : 2 -> 출하 등록 취소
			if (TRS.get_procstep(in_node) == '1')
			{
				if (CSHPORDMST.DELETE_FLAG == 'Y')
				{
					//WIP-0603 : 해당 출하지시는 종료되었습니다.
					strcpy(s_msg_code, "WIP-0603");
					TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_COMMON;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// 출하 지시 상세 정보 조회
				DBU_init_cshporddtl(&CSHPORDDTL);
				TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), in_node, "SHIP_ORDER_ID");
				memcpy(CSHPORDDTL.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
				CSHPORDDTL.PACK_LINE_NO = CPAKORDSTS.LINE_NO;


				//20241107 출하라인번호 가져와서 하는것으로 변경
				if (TRS.get_int(in_node, "SHIP_SEQ") == 0) {
					DBU_open_cshporddtl(4, &CSHPORDDTL);
				}
				else {
					CSHPORDDTL.SEQ = TRS.get_int(in_node, "SHIP_SEQ");
					DBU_open_cshporddtl(5, &CSHPORDDTL);

				}

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
					DBU_fetch_cshporddtl(4, &CSHPORDDTL);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cshporddtl(4);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//INV-0043 : 검색하신 정보는 존재하지 않습니다.
						strcpy(s_msg_code, "INV-0043");
						TRS.add_fieldmsg(out_node, "CSHPORDDTL FETCH", DT_NOVALUESTRING);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cshporddtl(4);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					if (CSHPORDDTL.DELETE_FLAG == 'Y')
					{
						//WIP-0603 : 해당 출하지시는 종료되었습니다.
						strcpy(s_msg_code, "WIP-0603");
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_VALIDATION;
						gs_log_type.category = MP_LOG_CATE_COMMON;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_cshporddtl(4);
						//

						return MP_FALSE;
					}

					// 출하 지시 상세 상태 체크
					// 출하 -> WAIT 상태에서 가능
					if (memcmp(CSHPORDDTL.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
					{
						//WIP-0575 : 해당 출하 지시는 이미 출하되었습니다.
						strcpy(s_msg_code, "WIP-0575");
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
						TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_VALIDATION;
						gs_log_type.category = MP_LOG_CATE_COMMON;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_cshporddtl(4);
						//

						return MP_FALSE;
					}

					if (COM_isspace(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID)) == MP_FALSE)
					{
						// WIP-0592 : 해당 출하 Lot은 이미 출하 지시에 매핑되어 있습니다.
						strcpy(s_msg_code, "WIP-0592");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_cshporddtl(4);
						//

						return MP_FALSE;
					}

					// 등록 수량 Validation
					DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
					TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
					memcpy(CPAKLOTSTS_COUNT.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
					CPAKLOTSTS_COUNT.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
					d_lot_count = DBU_select_cpaklotsts_scalar(24, &CPAKLOTSTS_COUNT);

					if (d_lot_count == CSHPORDDTL.QTY)
					{
						continue;
					}

					if (d_lot_count + CPAKLOTSTS.QTY > CSHPORDDTL.QTY)
					{
						// INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
						strcpy(s_msg_code, "INV-0021");
						TRS.add_fieldmsg(out_node, "CSHPORDDTL SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
						TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_cshporddtl(4);
						//

						return MP_FALSE;
					}

					// CPAKLOTSTS - 출하 등록
					// 포장 LOT & 출하 지시 매핑
					memcpy(CPAKLOTSTS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
					CPAKLOTSTS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
					TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_cpaklotsts(1, &CPAKLOTSTS);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_cshporddtl(4);
						//

						return MP_FALSE;
					}

					break;
				}
			}
			else if (TRS.get_procstep(in_node) == '2')
			{
				if (COM_isspace(CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID)) == MP_TRUE)
				{
					// WIP-0592 : 해당 출하 Lot은 이미 출하 지시에 매핑되어 있습니다.
					strcpy(s_msg_code, "WIP-0592");
					TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
					TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.SHIP_ORDER_ID), CPAKLOTSTS.SHIP_ORDER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// CPAKLOTSTS - 출하 등록
				// 포장 LOT & 출하 지시 매핑 해제
				memset(CPAKLOTSTS.SHIP_ORDER_ID, ' ', sizeof(CSHPORDDTL.SHIP_ORDER_ID));
				CPAKLOTSTS.SHIP_ORDER_SEQ = 0;
				TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_cpaklotsts(1, &CPAKLOTSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
					TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
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
	}
	else
	{
		order_list = TRS.get_list(in_node, "SHIP_ORDER_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "SHIP_ORDER_LIST"); i++)
		{
			send_flag = 0;

			// 출하 지시 마스터 정보 조회
			DBU_init_cshpordmst(&CSHPORDMST);
			TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), order_list[i], "SHIP_ORDER_ID");
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

			// 출하 지시 마스터 상태 체크
			// 출하 -> WAIT 상태에서 가능
			if (memcmp(CSHPORDMST.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
			{
				//WIP-0575 : 해당 출하 지시는 이미 출하되었습니다.
				strcpy(s_msg_code, "WIP-0575");
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (CSHPORDMST.DELETE_FLAG == 'Y')
			{
				//WIP-0603 : 해당 출하지시는 종료되었습니다.
				strcpy(s_msg_code, "WIP-0603");
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
			TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKLOTSTS_COUNT.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
			i_not_regist_count = (int)DBU_select_cpaklotsts_scalar(23, &CPAKLOTSTS_COUNT);


			// CSHPORDDTL - 출하 지시 마스터 정보에 해당하는 출하되지 않은 상세 정보 조회
			// 해당 출하되지 않은 상제 정보가 없다면, 해당 출하 지시 마스터 상태 변경 (WAIT -> SHIPPED)
			DBU_init_cshporddtl(&CSHPORDDTL_COUNT);
			TRS.copy(CSHPORDDTL_COUNT.FACTORY, sizeof(CSHPORDDTL_COUNT.FACTORY), in_node, IN_FACTORY);
			memcpy(CSHPORDDTL_COUNT.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
			memcpy(CSHPORDDTL_COUNT.SHIP_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CSHPORDDTL_COUNT.SHIP_ORD_STATUS));
			d_ship_dtl_count = (int)DBU_select_cshporddtl_scalar(3, &CSHPORDDTL_COUNT);

			if (i_not_regist_count != d_ship_dtl_count)
			{
				// WIP-0618 : 해당 출하지시는 등록이 완료되지 않았습니다.
				strcpy(s_msg_code, "WIP-0618");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS_COUNT.FACTORY), CPAKLOTSTS_COUNT.FACTORY);
				TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.SHIP_ORDER_ID), CPAKLOTSTS_COUNT.SHIP_ORDER_ID);
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

				if (CSHPORDDTL.DELETE_FLAG == 'Y')
				{
					//WIP-0603 : 해당 출하지시는 종료되었습니다.
					strcpy(s_msg_code, "WIP-0603");
					TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_COMMON;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					// 20.12.21 minjae.go
					DBU_close_cshporddtl(2);
					//

					return MP_FALSE;
				}

				// 출하 지시 상세 상태 체크
				// 출하 -> WAIT 상태에서 가능
				if (memcmp(CSHPORDDTL.SHIP_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
				{
					//WIP-0575 : 해당 출하 지시는 이미 출하되었습니다.
					strcpy(s_msg_code, "WIP-0575");
					TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
					TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_VALIDATION;
					gs_log_type.category = MP_LOG_CATE_COMMON;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					// 20.12.21 minjae.go
					DBU_close_cshporddtl(2);
					//

					return MP_FALSE;
				}

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

					// 포장 LOT 포장 상태 체크
					// 출하 -> PACK_FLAG(Y) 상태에서 가능
					if (CPAKLOTSTS.PACK_FLAG != 'Y')
					{
						// WIP-0576 : 해당 포장 LOT은 포장이 확정되지 않았습니다.
						strcpy(s_msg_code, "WIP-0576");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
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

					// 포장 LOT 출하 상태 체크
					// 출하 -> SHIP_FLAG(N) 상태에서 가능
					if (CPAKLOTSTS.SHIP_FLAG != 'N')
					{
						// WIP-0569 : 해당 포장 Lot은 이미 출하되었습니다.
						strcpy(s_msg_code, "WIP-0569");
						TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
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

					// 포장 LOT 잠금 여부 체크
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

						// 20.12.21 minjae.go
						DBU_close_cpaklotsts(12);
						DBU_close_cshporddtl(2);
						//

						return MP_FALSE;
					}

					// 포장 LOT 삭제 여부 체크
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

					CSHPORDDTL.SHIPPED_QTY = CSHPORDDTL.SHIPPED_QTY + CPAKLOTSTS.QTY;

					if (CSHPORDDTL.SHIPPED_QTY > CSHPORDDTL.QTY)
					{
						//WIP-0591 : 선택된 출하 수량은 출하 요청 수량보다 큽니다.
						strcpy(s_msg_code, "WIP-0591");
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
						TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_VALIDATION;
						gs_log_type.category = MP_LOG_CATE_COMMON;
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
						TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						TRS.add_double(erpif_in, "QTY", DBU_select_cpaklotsts_scalar(22, &CPAKLOTSTS_COUNT));
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

					// CPAKLOTSTS - 출하 확정
					// 출하 상태 변경 SHIP_FLAG(N -> Y)
					CPAKLOTSTS.SHIP_FLAG = 'Y';
					memcpy(CPAKLOTSTS.SHIP_DATE, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_cpaklotsts(1, &CPAKLOTSTS);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
						TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
						TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
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


					// MWIPLOTSTS - 폐기 처리
					// 해당 LOT 폐기 처리로 출하 처리하기로 함.
					terminate_in = TRS.add_node(in_node, "terminate_in");
					CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

					TRS.add_char(terminate_in, "PROCSTEP", '1');
					TRS.add_string(terminate_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
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

					// CSHPORDDTL - 출하 지시 상세 정보 출하
					// 상태 변경 (WAIT -> SHIPPED)
					if (CSHPORDDTL.QTY == CSHPORDDTL.SHIPPED_QTY)
					{
						memcpy(CSHPORDDTL.SHIP_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CSHPORDDTL.SHIP_ORD_STATUS));
						CSHPORDDTL.DELETE_FLAG = 'Y';
					}

					memcpy(CSHPORDDTL.SHIP_DATE, s_sys_time, sizeof(s_sys_time));
					TRS.copy(CSHPORDDTL.UPDATE_USER_ID, sizeof(CSHPORDDTL.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CSHPORDDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_update_cshporddtl(1, &CSHPORDDTL);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CSHPORDDTL UPDATE", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSHPORDDTL.FACTORY), CSHPORDDTL.FACTORY);
						TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDDTL.SHIP_ORDER_ID), CSHPORDDTL.SHIP_ORDER_ID);
						TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CSHPORDDTL.SEQ);
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

					// 출하 지시 상세 상태 체크
					// 출하 -> WAIT 상태에서 가능
					if (memcmp(CSHPORDDTL.SHIP_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, strlen(MP_CSHP_STATUS_SHIPPED)) == 0)
					{
						// CSHPORDDTL - 출하 지시 마스터 정보에 해당하는 출하되지 않은 상세 정보 조회
						// 해당 출하되지 않은 상제 정보가 없다면, 해당 출하 지시 마스터 상태 변경 (WAIT -> SHIPPED)
						DBU_init_cshporddtl(&CSHPORDDTL_COUNT);
						TRS.copy(CSHPORDDTL_COUNT.FACTORY, sizeof(CSHPORDDTL_COUNT.FACTORY), in_node, IN_FACTORY);
						memcpy(CSHPORDDTL_COUNT.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
						memcpy(CSHPORDDTL_COUNT.SHIP_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CSHPORDDTL_COUNT.SHIP_ORD_STATUS));
						d_ship_dtl_count = (int)DBU_select_cshporddtl_scalar(2, &CSHPORDDTL_COUNT);

						if (d_ship_dtl_count <= 0)
						{
							// CSHPORDMST - 출하 지시 마스터 정보 출하
							// 상태 변경 (WAIT -> SHIPPED)
							memcpy(CSHPORDMST.SHIP_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CSHPORDMST.SHIP_ORD_STATUS));
							CSHPORDMST.DELETE_FLAG = 'Y';
							TRS.copy(CSHPORDMST.UPDATE_USER_ID, sizeof(CSHPORDMST.UPDATE_USER_ID), in_node, IN_USERID);
							memcpy(CSHPORDMST.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
							DBU_update_cshpordmst(1, &CSHPORDMST);

							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "CSHPORDMST UPDATE", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSHPORDMST.FACTORY), CSHPORDMST.FACTORY);
								TRS.add_fieldmsg(out_node, "SHIP_ORDER_ID", MP_STR, sizeof(CSHPORDMST.SHIP_ORDER_ID), CSHPORDMST.SHIP_ORDER_ID);
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
						}

						if (memcmp(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_PACKED, strlen(MP_CSHP_STATUS_PACKED)) == 0)
						{
							// CPAKLOTSTS - 포장 지시, 라인번호에 해당하는 출하되지 않은 LOT의 수량 체크
							// 해당 포장 지시에 LOT이 모두 출하되었다면, 해당 포장 지시 상태 변경 (PACKED -> SHIPPED)
							// 해당 포장 지시에 해당하는 출하 지시 상태 변경(PACKED -> SHIPPED)
							DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
							TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
							memcpy(CPAKLOTSTS_COUNT.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
							CPAKLOTSTS_COUNT.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
							d_lot_count = (int)DBU_select_cpaklotsts_scalar(6, &CPAKLOTSTS_COUNT);

							if (d_lot_count <= 0)
							{
								// CPAKORDSTS - 포장 지시 정보 출하
								// 상태 변경 (PACKED -> SHIPPED)
								memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
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

									// 20.12.21 minjae.go
									DBU_close_cpaklotsts(12);
									DBU_close_cshporddtl(2);
									//

									return MP_FALSE;
								}
							}
						}
					}

					// CTM 사업부 전용
					if (memcmp(CSHPORDMST.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0)
					{
						// 고객사 정보 조회
						DBU_init_mgcmtbldat(&MGCMTBLDAT_CUS);
						TRS.copy(MGCMTBLDAT_CUS.FACTORY, sizeof(MGCMTBLDAT_CUS.FACTORY), in_node, IN_FACTORY);
						memcpy(MGCMTBLDAT_CUS.TABLE_NAME, MP_GCM_CUSTOMER, strlen(MP_GCM_CUSTOMER));
						memcpy(MGCMTBLDAT_CUS.KEY_1, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
						COM_itoa_left(s_customer_site_id, CPAKORDSTS.CUSTOMER_SITE_ID, sizeof(s_customer_site_id));
						memcpy(MGCMTBLDAT_CUS.KEY_2, s_customer_site_id, sizeof(s_customer_site_id));
						DBU_select_mgcmtbldat(1, &MGCMTBLDAT_CUS);

						if (DB_error_code != DB_SUCCESS)
						{
							/*
							//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
							strcpy(s_msg_code, "GCM-0008");
							TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_CUS.FACTORY), MGCMTBLDAT_CUS.FACTORY);
							TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_CUS.TABLE_NAME), MGCMTBLDAT_CUS.TABLE_NAME);
							TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(MGCMTBLDAT_CUS.KEY_1), MGCMTBLDAT_CUS.KEY_1);
							TRS.add_fieldmsg(out_node, "CUSTOMER_SITE_ID", MP_STR, sizeof(MGCMTBLDAT_CUS.KEY_2), MGCMTBLDAT_CUS.KEY_2);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;

							*/
						}
						else {
							// DATA_4(SEND FLAG)가 Y면 출하 SEND TABLE 데이터 생성
							// 반제품에 대해서만 진행
							//반제품/제품 넘어가는것으로 변경.(20210721)
							if (MGCMTBLDAT_CUS.DATA_4[0] == 'Y')
							{
								//역물류로 인한 로직 변경_ 20210506_lwg
								if (memcmp(CSHPORDMST.AREA_ID, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
								{
									//음성(CTM)인 경우에만 프레스 이력 확인 및 반제품만 ISHPLOTISS에 담는다. 
									//반제품/제품 넘어가는것으로 변경.(20210721)
									
									if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_SEMI_FINISHED, strlen(MP_MAT_TYPE_SEMI_FINISHED)) == 0)
									{
										// 제품,반제품 로직 나중에 달라질수 있어서 분기 시킴.
										// PRESS RUN 정보 조회(LOT ID 이용)
										// 테이블 구조는 LOT ID로 여러개의 ROW가 생성가능하지만, 실제로는 1개라고 함.
										DBU_init_cwipprsrun(&CWIPPRSRUN);
										TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
										memcpy(CWIPPRSRUN.LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));

										DBU_select_cwipprsrun(3, &CWIPPRSRUN);
										//if (DB_error_code != DB_SUCCESS)
										if (DB_error_code == DB_SUCCESS)
										{
											// 프레스 실적 없이 보내는 경우 있음(반품했다가 다시가거나 하는것들) 값없으면 없는데로 그냥 ISHPLOTISS INSERT(20211118)
											/*
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "CWIPPRSRUN SELECT(1) ", DT_NOVALUESTRING);
											TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
											TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPPRSRUN.LOT_ID), CWIPPRSRUN.LOT_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

											return MP_FALSE;
											*/
											// 프레스 설비 정보 조회
											DBU_init_mrasresdef(&MRASRESDEF);
											TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
											memcpy(MRASRESDEF.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));

											DBU_select_mrasresdef(1, &MRASRESDEF);
											if (DB_error_code != DB_SUCCESS)
											{

												//// 프레스 실적 없이 보내는 경우 있음(반품했다가 다시가거나 하는것들) 값없으면 없는데로 그냥 ISHPLOTISS INSERT(20211118)
												/*
												strcpy(s_msg_code, "WIP-0004");
												TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT(1) ", DT_NOVALUESTRING);
												TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
												TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_TRANS;
												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

												return MP_FALSE;
												*/
											}

											// 출하 정보 저장
											DBU_init_ishplotiss(&ISHPLOTISS);
											TRS.copy(ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY), in_node, IN_FACTORY);
											memcpy(ISHPLOTISS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
											memcpy(ISHPLOTISS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
											memcpy(ISHPLOTISS.IF_TIME, s_sys_time, sizeof(s_sys_time));
											ISHPLOTISS.IF_CODE = 'N';
											memset(ISHPLOTISS.IF_MSG, ' ', sizeof(ISHPLOTISS.IF_MSG));
											memcpy(ISHPLOTISS.TO_FACTORY, MGCMTBLDAT_CUS.DATA_5, sizeof(ISHPLOTISS.TO_FACTORY));
											memcpy(ISHPLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
											ISHPLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
											ISHPLOTISS.QTY = CPAKLOTSTS.QTY;
											memcpy(ISHPLOTISS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
											memcpy(ISHPLOTISS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
											ISHPLOTISS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
											memcpy(ISHPLOTISS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
											memcpy(ISHPLOTISS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
											ISHPLOTISS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
											memcpy(ISHPLOTISS.CUSTOMER_ID, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
											ISHPLOTISS.CUSTOMER_SITE_ID = CPAKORDSTS.CUSTOMER_SITE_ID;
											memcpy(ISHPLOTISS.CUSTOMER_NUMBER, CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
											memcpy(ISHPLOTISS.CUSTOMER_NAME, CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
											memcpy(ISHPLOTISS.DELIVERY, CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
											ISHPLOTISS.DELIVERY_ID = CSHPORDMST.DELIVERY_ID;
											memcpy(ISHPLOTISS.DELIVERY_NAME, CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
											memcpy(ISHPLOTISS.DELIVERY_LOCATION, CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
											memcpy(ISHPLOTISS.DELIVERY_PHONE_NO, CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
											memcpy(ISHPLOTISS.DELIVERY_USER_ID, CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
											ISHPLOTISS.SHIPPING_LINE_ID = CSHPORDDTL.SHIPPING_LINE_ID;
											memcpy(ISHPLOTISS.PRS_WORK_DATE, CWIPPRSRUN.WORK_DATE, sizeof(CWIPPRSRUN.WORK_DATE));
											memcpy(ISHPLOTISS.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
											memcpy(ISHPLOTISS.RES_DESC, MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
											ISHPLOTISS.RUN_COUNT = CWIPPRSRUN.RUN_COUNT;
											memcpy(ISHPLOTISS.CELL_ID, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
											ISHPLOTISS.MAPPING_SEQ = CWIPPRSRUN.MAPPING_SEQ;
											memcpy(ISHPLOTISS.CAR, CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR));
											ISHPLOTISS.DAY_NIGHT = CWIPPRSRUN.DAY_NIGHT;
											memcpy(ISHPLOTISS.PRS_TRAN_TIME, CWIPPRSRUN.TRAN_TIME, sizeof(CWIPPRSRUN.TRAN_TIME));
											memset(ISHPLOTISS.CMF_1, ' ', sizeof(ISHPLOTISS.CMF_1));
											memset(ISHPLOTISS.CMF_2, ' ', sizeof(ISHPLOTISS.CMF_2));
											memset(ISHPLOTISS.CMF_3, ' ', sizeof(ISHPLOTISS.CMF_3));
											memset(ISHPLOTISS.CMF_4, ' ', sizeof(ISHPLOTISS.CMF_4));
											memset(ISHPLOTISS.CMF_5, ' ', sizeof(ISHPLOTISS.CMF_5));
											memset(ISHPLOTISS.CMF_6, ' ', sizeof(ISHPLOTISS.CMF_6));
											memset(ISHPLOTISS.CMF_7, ' ', sizeof(ISHPLOTISS.CMF_7));
											memset(ISHPLOTISS.CMF_8, ' ', sizeof(ISHPLOTISS.CMF_8));
											memset(ISHPLOTISS.CMF_9, ' ', sizeof(ISHPLOTISS.CMF_9));
											memset(ISHPLOTISS.CMF_10, ' ', sizeof(ISHPLOTISS.CMF_10));
											TRS.copy(ISHPLOTISS.CREATE_USER_ID, sizeof(ISHPLOTISS.CREATE_USER_ID), in_node, IN_USERID);
											memcpy(ISHPLOTISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
											TRS.copy(ISHPLOTISS.UPDATE_USER_ID, sizeof(ISHPLOTISS.UPDATE_USER_ID), in_node, IN_USERID);
											memcpy(ISHPLOTISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

											DBU_insert_ishplotiss(&ISHPLOTISS);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "WIP-0004");
												TRS.add_fieldmsg(out_node, "ISHPLOTISS INSERT", MP_NVST);
												TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTISS.ORG_LOT_ID), ISHPLOTISS.ORG_LOT_ID);
												TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTISS.PACK_LOT_ID), ISHPLOTISS.PACK_LOT_ID);
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
											// 출하 정보 저장
											DBU_init_ishplotiss(&ISHPLOTISS);
											TRS.copy(ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY), in_node, IN_FACTORY);
											memcpy(ISHPLOTISS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
											memcpy(ISHPLOTISS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
											memcpy(ISHPLOTISS.IF_TIME, s_sys_time, sizeof(s_sys_time));
											ISHPLOTISS.IF_CODE = 'N';
											memset(ISHPLOTISS.IF_MSG, ' ', sizeof(ISHPLOTISS.IF_MSG));
											memcpy(ISHPLOTISS.TO_FACTORY, MGCMTBLDAT_CUS.DATA_5, sizeof(ISHPLOTISS.TO_FACTORY));
											memcpy(ISHPLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
											ISHPLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
											ISHPLOTISS.QTY = CPAKLOTSTS.QTY;
											memcpy(ISHPLOTISS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
											memcpy(ISHPLOTISS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
											ISHPLOTISS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
											memcpy(ISHPLOTISS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
											memcpy(ISHPLOTISS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
											ISHPLOTISS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
											memcpy(ISHPLOTISS.CUSTOMER_ID, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
											ISHPLOTISS.CUSTOMER_SITE_ID = CPAKORDSTS.CUSTOMER_SITE_ID;
											memcpy(ISHPLOTISS.CUSTOMER_NUMBER, CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
											memcpy(ISHPLOTISS.CUSTOMER_NAME, CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
											memcpy(ISHPLOTISS.DELIVERY, CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
											ISHPLOTISS.DELIVERY_ID = CSHPORDMST.DELIVERY_ID;
											memcpy(ISHPLOTISS.DELIVERY_NAME, CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
											memcpy(ISHPLOTISS.DELIVERY_LOCATION, CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
											memcpy(ISHPLOTISS.DELIVERY_PHONE_NO, CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
											memcpy(ISHPLOTISS.DELIVERY_USER_ID, CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
											ISHPLOTISS.SHIPPING_LINE_ID = CSHPORDDTL.SHIPPING_LINE_ID;
											/*
											memcpy(ISHPLOTISS.PRS_WORK_DATE, CWIPPRSRUN.WORK_DATE, sizeof(CWIPPRSRUN.WORK_DATE));
											memcpy(ISHPLOTISS.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
											memcpy(ISHPLOTISS.RES_DESC, MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
											ISHPLOTISS.RUN_COUNT = CWIPPRSRUN.RUN_COUNT;
											memcpy(ISHPLOTISS.CELL_ID, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
											ISHPLOTISS.MAPPING_SEQ = CWIPPRSRUN.MAPPING_SEQ;
											memcpy(ISHPLOTISS.CAR, CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR));
											ISHPLOTISS.DAY_NIGHT = CWIPPRSRUN.DAY_NIGHT;
											memcpy(ISHPLOTISS.PRS_TRAN_TIME, CWIPPRSRUN.TRAN_TIME, sizeof(CWIPPRSRUN.TRAN_TIME));
											*/

											memset(ISHPLOTISS.CMF_1, ' ', sizeof(ISHPLOTISS.CMF_1));
											memset(ISHPLOTISS.CMF_2, ' ', sizeof(ISHPLOTISS.CMF_2));
											memset(ISHPLOTISS.CMF_3, ' ', sizeof(ISHPLOTISS.CMF_3));
											memset(ISHPLOTISS.CMF_4, ' ', sizeof(ISHPLOTISS.CMF_4));
											memset(ISHPLOTISS.CMF_5, ' ', sizeof(ISHPLOTISS.CMF_5));
											memset(ISHPLOTISS.CMF_6, ' ', sizeof(ISHPLOTISS.CMF_6));
											memset(ISHPLOTISS.CMF_7, ' ', sizeof(ISHPLOTISS.CMF_7));
											memset(ISHPLOTISS.CMF_8, ' ', sizeof(ISHPLOTISS.CMF_8));
											memset(ISHPLOTISS.CMF_9, ' ', sizeof(ISHPLOTISS.CMF_9));
											memset(ISHPLOTISS.CMF_10, ' ', sizeof(ISHPLOTISS.CMF_10));
											TRS.copy(ISHPLOTISS.CREATE_USER_ID, sizeof(ISHPLOTISS.CREATE_USER_ID), in_node, IN_USERID);
											memcpy(ISHPLOTISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
											TRS.copy(ISHPLOTISS.UPDATE_USER_ID, sizeof(ISHPLOTISS.UPDATE_USER_ID), in_node, IN_USERID);
											memcpy(ISHPLOTISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

											DBU_insert_ishplotiss(&ISHPLOTISS);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "WIP-0004");
												TRS.add_fieldmsg(out_node, "ISHPLOTISS INSERT", MP_NVST);
												TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTISS.ORG_LOT_ID), ISHPLOTISS.ORG_LOT_ID);
												TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTISS.PACK_LOT_ID), ISHPLOTISS.PACK_LOT_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_TRANS;
												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
												return MP_FALSE;
											}
										}






										//검사 데이터 조회 
										//검사데이터를 음성 ->베트남 으로 넘겨준다.L/P 및 ROUND 검사 (202100721) 있으면 넣고 없으면 안넣는걸로 변경. 
										//ROUND 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											DBU_init_cqcmispdat(&CQCMISPDAT);
											TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
											memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
											DBU_open_cqcmispdat(5, &CQCMISPDAT);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "QCM-0004");
												TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
												TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
												TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_VIEW;

												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
												return MP_FALSE;
											}
											while (1)
											{
												DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code == DB_NOT_FOUND)
												{
													DBU_close_cqcmispdat(5);
													break;
												}
												else if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													DBU_close_cqcmispdat(5);
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}

												//검사 데이터 인터페이스 저장. 
												DBU_init_ishpispiss(&ISHPISPISS);
												memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
												memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
												memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
												ISHPISPISS.IF_CODE = 'N';
												memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
												memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
												memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
												ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
												memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
												ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
												ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
												ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
												memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
												ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
												ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
												memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
												memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
												memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
												memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
												memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
												memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
												memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
												memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
												memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
												memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
												memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
												memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
												memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
												memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
												memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
												memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
												memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
												memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
												memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
												memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
												memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
												memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
												memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
												memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
												memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
												ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
												memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
												ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
												memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
												memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
												memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
												memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
												memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
												memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
												memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
												memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
												memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
												memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
												memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
												memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
												TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
												TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

												DBU_insert_ishpispiss(&ISHPISPISS);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "WIP-0004");
													TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
													TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
													TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_TRANS;
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
											}
										}

										//L/P 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_12, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											//L/P검사 데이터만(마지막 공정검사사 L/P인경우) 
											if (memcmp(CQCMISPSTS.INSP_OPER, "OC04120", strlen("OC04050")) == MP_FALSE)
											{



												DBU_init_cqcmispdat(&CQCMISPDAT);
												TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
												memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
												DBU_open_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
													TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
													TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
												while (1)
												{
													DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
													if (DB_error_code == DB_NOT_FOUND)
													{
														DBU_close_cqcmispdat(5);
														break;
													}
													else if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "QCM-0004");
														TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
														TRS.add_dberrmsg(out_node, DB_error_msg);

														gs_log_type.type = MP_LOG_ERROR;
														gs_log_type.e_type = MP_LOG_E_SYSTEM;
														gs_log_type.category = MP_LOG_CATE_VIEW;

														DBU_close_cqcmispdat(5);
														COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
														return MP_FALSE;
													}

													//검사 데이터 인터페이스 저장. 
													DBU_init_ishpispiss(&ISHPISPISS);
													memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
													memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
													memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
													ISHPISPISS.IF_CODE = 'N';
													memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
													memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
													memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
													ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
													memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
													ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
													ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
													ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
													memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
													ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
													ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
													memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
													memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
													memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
													memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
													memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
													memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
													memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
													memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
													memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
													memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
													memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
													memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
													memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
													memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
													memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
													memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
													memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
													memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
													memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
													memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
													memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
													memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
													memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
													memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
													memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
													ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
													memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
													ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
													memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
													memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
													memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
													memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
													memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
													memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
													memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
													memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
													memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
													memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
													memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
													memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
													TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
													TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

													DBU_insert_ishpispiss(&ISHPISPISS);
													if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "WIP-0004");
														TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
														TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
														TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
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




									}
									else if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS) == 0))
									{
										// 제품,반제품 로직 나중에 달라질수 있어서 분기 시킴.
										// PRESS RUN 정보 조회(LOT ID 이용)
										// 테이블 구조는 LOT ID로 여러개의 ROW가 생성가능하지만, 실제로는 1개라고 함.
										DBU_init_cwipprsrun(&CWIPPRSRUN);
										TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
										memcpy(CWIPPRSRUN.LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));

										DBU_select_cwipprsrun(3, &CWIPPRSRUN);
										if (DB_error_code != DB_SUCCESS)
										{
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "CWIPPRSRUN SELECT(1) ", DT_NOVALUESTRING);
											TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
											TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPPRSRUN.LOT_ID), CWIPPRSRUN.LOT_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

											return MP_FALSE;
										}

										// 프레스 설비 정보 조회
										DBU_init_mrasresdef(&MRASRESDEF);
										TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
										memcpy(MRASRESDEF.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));

										DBU_select_mrasresdef(1, &MRASRESDEF);
										if (DB_error_code != DB_SUCCESS)
										{
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT(1) ", DT_NOVALUESTRING);
											TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
											TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

											return MP_FALSE;
										}

										// 출하 정보 저장
										DBU_init_ishplotiss(&ISHPLOTISS);
										TRS.copy(ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY), in_node, IN_FACTORY);
										memcpy(ISHPLOTISS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
										memcpy(ISHPLOTISS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
										memcpy(ISHPLOTISS.IF_TIME, s_sys_time, sizeof(s_sys_time));
										ISHPLOTISS.IF_CODE = 'N';
										memset(ISHPLOTISS.IF_MSG, ' ', sizeof(ISHPLOTISS.IF_MSG));
										memcpy(ISHPLOTISS.TO_FACTORY, MGCMTBLDAT_CUS.DATA_5, sizeof(ISHPLOTISS.TO_FACTORY));
										memcpy(ISHPLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
										ISHPLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
										ISHPLOTISS.QTY = CPAKLOTSTS.QTY;
										memcpy(ISHPLOTISS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
										memcpy(ISHPLOTISS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
										ISHPLOTISS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
										memcpy(ISHPLOTISS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
										memcpy(ISHPLOTISS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
										ISHPLOTISS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
										memcpy(ISHPLOTISS.CUSTOMER_ID, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
										ISHPLOTISS.CUSTOMER_SITE_ID = CPAKORDSTS.CUSTOMER_SITE_ID;
										memcpy(ISHPLOTISS.CUSTOMER_NUMBER, CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
										memcpy(ISHPLOTISS.CUSTOMER_NAME, CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
										memcpy(ISHPLOTISS.DELIVERY, CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
										ISHPLOTISS.DELIVERY_ID = CSHPORDMST.DELIVERY_ID;
										memcpy(ISHPLOTISS.DELIVERY_NAME, CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
										memcpy(ISHPLOTISS.DELIVERY_LOCATION, CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
										memcpy(ISHPLOTISS.DELIVERY_PHONE_NO, CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
										memcpy(ISHPLOTISS.DELIVERY_USER_ID, CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
										ISHPLOTISS.SHIPPING_LINE_ID = CSHPORDDTL.SHIPPING_LINE_ID;
										memcpy(ISHPLOTISS.PRS_WORK_DATE, CWIPPRSRUN.WORK_DATE, sizeof(CWIPPRSRUN.WORK_DATE));
										memcpy(ISHPLOTISS.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
										memcpy(ISHPLOTISS.RES_DESC, MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
										ISHPLOTISS.RUN_COUNT = CWIPPRSRUN.RUN_COUNT;
										memcpy(ISHPLOTISS.CELL_ID, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
										ISHPLOTISS.MAPPING_SEQ = CWIPPRSRUN.MAPPING_SEQ;
										memcpy(ISHPLOTISS.CAR, CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR));
										ISHPLOTISS.DAY_NIGHT = CWIPPRSRUN.DAY_NIGHT;
										memcpy(ISHPLOTISS.PRS_TRAN_TIME, CWIPPRSRUN.TRAN_TIME, sizeof(CWIPPRSRUN.TRAN_TIME));
										memset(ISHPLOTISS.CMF_1, ' ', sizeof(ISHPLOTISS.CMF_1));
										memset(ISHPLOTISS.CMF_2, ' ', sizeof(ISHPLOTISS.CMF_2));
										memset(ISHPLOTISS.CMF_3, ' ', sizeof(ISHPLOTISS.CMF_3));
										memset(ISHPLOTISS.CMF_4, ' ', sizeof(ISHPLOTISS.CMF_4));
										memset(ISHPLOTISS.CMF_5, ' ', sizeof(ISHPLOTISS.CMF_5));
										memset(ISHPLOTISS.CMF_6, ' ', sizeof(ISHPLOTISS.CMF_6));
										memset(ISHPLOTISS.CMF_7, ' ', sizeof(ISHPLOTISS.CMF_7));
										memset(ISHPLOTISS.CMF_8, ' ', sizeof(ISHPLOTISS.CMF_8));
										memset(ISHPLOTISS.CMF_9, ' ', sizeof(ISHPLOTISS.CMF_9));
										memset(ISHPLOTISS.CMF_10, ' ', sizeof(ISHPLOTISS.CMF_10));
										TRS.copy(ISHPLOTISS.CREATE_USER_ID, sizeof(ISHPLOTISS.CREATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
										TRS.copy(ISHPLOTISS.UPDATE_USER_ID, sizeof(ISHPLOTISS.UPDATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

										DBU_insert_ishplotiss(&ISHPLOTISS);
										if (DB_error_code != DB_SUCCESS)
										{
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "ISHPLOTISS INSERT", MP_NVST);
											TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTISS.ORG_LOT_ID), ISHPLOTISS.ORG_LOT_ID);
											TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTISS.PACK_LOT_ID), ISHPLOTISS.PACK_LOT_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
											return MP_FALSE;
										}

										//검사 데이터 조회 
										//검사데이터를 음성 ->베트남 으로 넘겨준다.L/P 및 ROUND 검사 (202100721) 있으면 넣고 없으면 안넣는걸로 변경. 
										//ROUND 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											DBU_init_cqcmispdat(&CQCMISPDAT);
											TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
											memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
											DBU_open_cqcmispdat(5, &CQCMISPDAT);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "QCM-0004");
												TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
												TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
												TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_VIEW;

												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
												return MP_FALSE;
											}
											while (1)
											{
												DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code == DB_NOT_FOUND)
												{
													DBU_close_cqcmispdat(5);
													break;
												}
												else if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													DBU_close_cqcmispdat(5);
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}

												//검사 데이터 인터페이스 저장. 
												DBU_init_ishpispiss(&ISHPISPISS);
												memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
												memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
												memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
												ISHPISPISS.IF_CODE = 'N';
												memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
												memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
												memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
												ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
												memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
												ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
												ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
												ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
												memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
												ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
												ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
												memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
												memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
												memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
												memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
												memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
												memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
												memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
												memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
												memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
												memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
												memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
												memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
												memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
												memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
												memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
												memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
												memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
												memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
												memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
												memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
												memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
												memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
												memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
												memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
												memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
												ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
												memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
												ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
												memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
												memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
												memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
												memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
												memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
												memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
												memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
												memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
												memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
												memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
												memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
												memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
												TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
												TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

												DBU_insert_ishpispiss(&ISHPISPISS);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "WIP-0004");
													TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
													TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
													TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_TRANS;
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
											}
										}

										//L/P 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_12, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											//L/P검사 데이터만(마지막 공정검사사 L/P인경우) 
											if (memcmp(CQCMISPSTS.INSP_OPER, "OC04120", strlen("OC04050")) == MP_FALSE)
											{


												DBU_init_cqcmispdat(&CQCMISPDAT);
												TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
												memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
												DBU_open_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
													TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
													TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
												while (1)
												{
													DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
													if (DB_error_code == DB_NOT_FOUND)
													{
														DBU_close_cqcmispdat(5);
														break;
													}
													else if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "QCM-0004");
														TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
														TRS.add_dberrmsg(out_node, DB_error_msg);

														gs_log_type.type = MP_LOG_ERROR;
														gs_log_type.e_type = MP_LOG_E_SYSTEM;
														gs_log_type.category = MP_LOG_CATE_VIEW;

														DBU_close_cqcmispdat(5);
														COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
														return MP_FALSE;
													}

													//검사 데이터 인터페이스 저장. 
													DBU_init_ishpispiss(&ISHPISPISS);
													memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
													memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
													memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
													ISHPISPISS.IF_CODE = 'N';
													memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
													memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
													memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
													ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
													memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
													ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
													ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
													ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
													memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
													ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
													ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
													memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
													memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
													memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
													memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
													memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
													memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
													memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
													memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
													memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
													memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
													memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
													memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
													memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
													memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
													memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
													memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
													memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
													memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
													memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
													memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
													memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
													memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
													memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
													memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
													memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
													ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
													memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
													ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
													memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
													memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
													memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
													memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
													memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
													memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
													memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
													memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
													memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
													memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
													memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
													memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
													TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
													TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

													DBU_insert_ishpispiss(&ISHPISPISS);
													if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "WIP-0004");
														TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
														TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
														TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
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
									}



								}
								//베트남(CTV)에서 출하인 경우 프레스 이력을 확인 하지 않는다. 
								else
								{
									//베트남(CTV)경우 제품만 ISHPLOTISS에 담는다. 
									//반제품/제품 넘어가는것으로 변경.(20210721)
									// 제품,반제품 로직 나중에 달라질수 있어서 분기 시킴.
									if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_FINISHED_GOODS, strlen(MP_MAT_TYPE_FINISHED_GOODS)) == 0)
									{
										// 출하 정보 저장
										DBU_init_ishplotiss(&ISHPLOTISS);
										TRS.copy(ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY), in_node, IN_FACTORY);
										memcpy(ISHPLOTISS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
										memcpy(ISHPLOTISS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
										memcpy(ISHPLOTISS.IF_TIME, s_sys_time, sizeof(s_sys_time));
										ISHPLOTISS.IF_CODE = 'N';
										memset(ISHPLOTISS.IF_MSG, ' ', sizeof(ISHPLOTISS.IF_MSG));
										memcpy(ISHPLOTISS.TO_FACTORY, MGCMTBLDAT_CUS.DATA_5, sizeof(ISHPLOTISS.TO_FACTORY));
										memcpy(ISHPLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
										ISHPLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
										ISHPLOTISS.QTY = CPAKLOTSTS.QTY;
										memcpy(ISHPLOTISS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
										memcpy(ISHPLOTISS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
										ISHPLOTISS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
										memcpy(ISHPLOTISS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
										memcpy(ISHPLOTISS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
										ISHPLOTISS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
										memcpy(ISHPLOTISS.CUSTOMER_ID, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
										ISHPLOTISS.CUSTOMER_SITE_ID = CPAKORDSTS.CUSTOMER_SITE_ID;
										memcpy(ISHPLOTISS.CUSTOMER_NUMBER, CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
										memcpy(ISHPLOTISS.CUSTOMER_NAME, CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
										memcpy(ISHPLOTISS.DELIVERY, CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
										ISHPLOTISS.DELIVERY_ID = CSHPORDMST.DELIVERY_ID;
										memcpy(ISHPLOTISS.DELIVERY_NAME, CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
										memcpy(ISHPLOTISS.DELIVERY_LOCATION, CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
										memcpy(ISHPLOTISS.DELIVERY_PHONE_NO, CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
										memcpy(ISHPLOTISS.DELIVERY_USER_ID, CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
										ISHPLOTISS.SHIPPING_LINE_ID = CSHPORDDTL.SHIPPING_LINE_ID;

										/*
										memcpy(ISHPLOTISS.PRS_WORK_DATE, CWIPPRSRUN.WORK_DATE, sizeof(CWIPPRSRUN.WORK_DATE));
										memcpy(ISHPLOTISS.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
										memcpy(ISHPLOTISS.RES_DESC, MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
										ISHPLOTISS.RUN_COUNT = CWIPPRSRUN.RUN_COUNT;
										memcpy(ISHPLOTISS.CELL_ID, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
										ISHPLOTISS.MAPPING_SEQ = CWIPPRSRUN.MAPPING_SEQ;
										memcpy(ISHPLOTISS.CAR, CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR));
										ISHPLOTISS.DAY_NIGHT = CWIPPRSRUN.DAY_NIGHT;
										memcpy(ISHPLOTISS.PRS_TRAN_TIME, CWIPPRSRUN.TRAN_TIME, sizeof(CWIPPRSRUN.TRAN_TIME));
										*/

										memset(ISHPLOTISS.CMF_1, ' ', sizeof(ISHPLOTISS.CMF_1));
										memset(ISHPLOTISS.CMF_2, ' ', sizeof(ISHPLOTISS.CMF_2));
										memset(ISHPLOTISS.CMF_3, ' ', sizeof(ISHPLOTISS.CMF_3));
										memset(ISHPLOTISS.CMF_4, ' ', sizeof(ISHPLOTISS.CMF_4));
										memset(ISHPLOTISS.CMF_5, ' ', sizeof(ISHPLOTISS.CMF_5));
										memset(ISHPLOTISS.CMF_6, ' ', sizeof(ISHPLOTISS.CMF_6));
										memset(ISHPLOTISS.CMF_7, ' ', sizeof(ISHPLOTISS.CMF_7));
										memset(ISHPLOTISS.CMF_8, ' ', sizeof(ISHPLOTISS.CMF_8));
										memset(ISHPLOTISS.CMF_9, ' ', sizeof(ISHPLOTISS.CMF_9));
										memset(ISHPLOTISS.CMF_10, ' ', sizeof(ISHPLOTISS.CMF_10));
										TRS.copy(ISHPLOTISS.CREATE_USER_ID, sizeof(ISHPLOTISS.CREATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
										TRS.copy(ISHPLOTISS.UPDATE_USER_ID, sizeof(ISHPLOTISS.UPDATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

										DBU_insert_ishplotiss(&ISHPLOTISS);
										if (DB_error_code != DB_SUCCESS)
										{
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "ISHPLOTISS INSERT", MP_NVST);
											TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTISS.ORG_LOT_ID), ISHPLOTISS.ORG_LOT_ID);
											TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTISS.PACK_LOT_ID), ISHPLOTISS.PACK_LOT_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
											return MP_FALSE;
										}

										//검사 데이터 조회 
										//검사데이터를 베트남 ->음성 으로 넘겨준다.L/P 및 ROUND 검사 (202100721) 있으면 넣고 없으면 안넣는걸로 변경. 
										//ROUND 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											DBU_init_cqcmispdat(&CQCMISPDAT);
											TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
											memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
											DBU_open_cqcmispdat(5, &CQCMISPDAT);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "QCM-0004");
												TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
												TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
												TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_VIEW;

												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
												return MP_FALSE;
											}
											while (1)
											{
												DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code == DB_NOT_FOUND)
												{
													DBU_close_cqcmispdat(5);
													break;
												}
												else if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													DBU_close_cqcmispdat(5);
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}

												//검사 데이터 인터페이스 저장. 
												DBU_init_ishpispiss(&ISHPISPISS);
												memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
												memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
												memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
												ISHPISPISS.IF_CODE = 'N';
												memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
												memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
												memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
												ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
												memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
												ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
												ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
												ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
												memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
												ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
												ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
												memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
												memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
												memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
												memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
												memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
												memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
												memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
												memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
												memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
												memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
												memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
												memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
												memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
												memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
												memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
												memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
												memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
												memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
												memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
												memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
												memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
												memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
												memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
												memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
												memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
												ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
												memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
												ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
												memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
												memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
												memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
												memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
												memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
												memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
												memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
												memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
												memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
												memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
												memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
												memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
												TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
												TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

												DBU_insert_ishpispiss(&ISHPISPISS);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "WIP-0004");
													TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
													TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
													TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_TRANS;
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
											}
										}

										//L/P 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_12, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											//L/P검사 데이터만(마지막 공정검사사 L/P인경우) 
											if (memcmp(CQCMISPSTS.INSP_OPER, "OC04120", strlen("OC04050")) == MP_FALSE)
											{


												DBU_init_cqcmispdat(&CQCMISPDAT);
												TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
												memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
												DBU_open_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
													TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
													TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
												while (1)
												{
													DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
													if (DB_error_code == DB_NOT_FOUND)
													{
														DBU_close_cqcmispdat(5);
														break;
													}
													else if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "QCM-0004");
														TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
														TRS.add_dberrmsg(out_node, DB_error_msg);

														gs_log_type.type = MP_LOG_ERROR;
														gs_log_type.e_type = MP_LOG_E_SYSTEM;
														gs_log_type.category = MP_LOG_CATE_VIEW;

														DBU_close_cqcmispdat(5);
														COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
														return MP_FALSE;
													}

													//검사 데이터 인터페이스 저장. 
													DBU_init_ishpispiss(&ISHPISPISS);
													memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
													memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
													memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
													ISHPISPISS.IF_CODE = 'N';
													memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
													memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
													memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
													ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
													memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
													ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
													ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
													ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
													memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
													ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
													ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
													memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
													memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
													memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
													memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
													memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
													memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
													memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
													memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
													memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
													memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
													memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
													memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
													memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
													memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
													memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
													memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
													memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
													memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
													memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
													memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
													memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
													memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
													memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
													memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
													memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
													ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
													memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
													ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
													memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
													memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
													memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
													memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
													memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
													memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
													memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
													memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
													memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
													memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
													memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
													memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
													TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
													TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

													DBU_insert_ishpispiss(&ISHPISPISS);
													if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "WIP-0004");
														TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
														TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
														TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
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
									}
									else if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_SEMI_FINISHED, strlen(MP_MAT_TYPE_SEMI_FINISHED)) == 0)
									{
										// 출하 정보 저장
										DBU_init_ishplotiss(&ISHPLOTISS);
										TRS.copy(ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY), in_node, IN_FACTORY);
										memcpy(ISHPLOTISS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
										memcpy(ISHPLOTISS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
										memcpy(ISHPLOTISS.IF_TIME, s_sys_time, sizeof(s_sys_time));
										ISHPLOTISS.IF_CODE = 'N';
										memset(ISHPLOTISS.IF_MSG, ' ', sizeof(ISHPLOTISS.IF_MSG));
										memcpy(ISHPLOTISS.TO_FACTORY, MGCMTBLDAT_CUS.DATA_5, sizeof(ISHPLOTISS.TO_FACTORY));
										memcpy(ISHPLOTISS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
										ISHPLOTISS.MAT_VER = MWIPMATDEF.MAT_VER;
										ISHPLOTISS.QTY = CPAKLOTSTS.QTY;
										memcpy(ISHPLOTISS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
										memcpy(ISHPLOTISS.PACK_ORDER_ID, CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
										ISHPLOTISS.PACK_LINE_NO = CPAKORDSTS.LINE_NO;
										memcpy(ISHPLOTISS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
										memcpy(ISHPLOTISS.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
										ISHPLOTISS.SHIP_ORDER_SEQ = CSHPORDDTL.SEQ;
										memcpy(ISHPLOTISS.CUSTOMER_ID, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
										ISHPLOTISS.CUSTOMER_SITE_ID = CPAKORDSTS.CUSTOMER_SITE_ID;
										memcpy(ISHPLOTISS.CUSTOMER_NUMBER, CSHPORDMST.CUSTOMER_NUMBER, sizeof(CSHPORDMST.CUSTOMER_NUMBER));
										memcpy(ISHPLOTISS.CUSTOMER_NAME, CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
										memcpy(ISHPLOTISS.DELIVERY, CSHPORDMST.DELIVERY, sizeof(CSHPORDMST.DELIVERY));
										ISHPLOTISS.DELIVERY_ID = CSHPORDMST.DELIVERY_ID;
										memcpy(ISHPLOTISS.DELIVERY_NAME, CSHPORDMST.DELIVERY_NAME, sizeof(CSHPORDMST.DELIVERY_NAME));
										memcpy(ISHPLOTISS.DELIVERY_LOCATION, CSHPORDMST.DELIVERY_LOCATION, sizeof(CSHPORDMST.DELIVERY_LOCATION));
										memcpy(ISHPLOTISS.DELIVERY_PHONE_NO, CSHPORDMST.DELIVERY_PHONE_NO, sizeof(CSHPORDMST.DELIVERY_PHONE_NO));
										memcpy(ISHPLOTISS.DELIVERY_USER_ID, CSHPORDMST.DELIVERY_USER_ID, sizeof(CSHPORDMST.DELIVERY_USER_ID));
										ISHPLOTISS.SHIPPING_LINE_ID = CSHPORDDTL.SHIPPING_LINE_ID;

										/*
										memcpy(ISHPLOTISS.PRS_WORK_DATE, CWIPPRSRUN.WORK_DATE, sizeof(CWIPPRSRUN.WORK_DATE));
										memcpy(ISHPLOTISS.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));
										memcpy(ISHPLOTISS.RES_DESC, MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
										ISHPLOTISS.RUN_COUNT = CWIPPRSRUN.RUN_COUNT;
										memcpy(ISHPLOTISS.CELL_ID, CWIPPRSRUN.CELL_ID, sizeof(CWIPPRSRUN.CELL_ID));
										ISHPLOTISS.MAPPING_SEQ = CWIPPRSRUN.MAPPING_SEQ;
										memcpy(ISHPLOTISS.CAR, CWIPPRSRUN.CAR, sizeof(CWIPPRSRUN.CAR));
										ISHPLOTISS.DAY_NIGHT = CWIPPRSRUN.DAY_NIGHT;
										memcpy(ISHPLOTISS.PRS_TRAN_TIME, CWIPPRSRUN.TRAN_TIME, sizeof(CWIPPRSRUN.TRAN_TIME));
										*/

										memset(ISHPLOTISS.CMF_1, ' ', sizeof(ISHPLOTISS.CMF_1));
										memset(ISHPLOTISS.CMF_2, ' ', sizeof(ISHPLOTISS.CMF_2));
										memset(ISHPLOTISS.CMF_3, ' ', sizeof(ISHPLOTISS.CMF_3));
										memset(ISHPLOTISS.CMF_4, ' ', sizeof(ISHPLOTISS.CMF_4));
										memset(ISHPLOTISS.CMF_5, ' ', sizeof(ISHPLOTISS.CMF_5));
										memset(ISHPLOTISS.CMF_6, ' ', sizeof(ISHPLOTISS.CMF_6));
										memset(ISHPLOTISS.CMF_7, ' ', sizeof(ISHPLOTISS.CMF_7));
										memset(ISHPLOTISS.CMF_8, ' ', sizeof(ISHPLOTISS.CMF_8));
										memset(ISHPLOTISS.CMF_9, ' ', sizeof(ISHPLOTISS.CMF_9));
										memset(ISHPLOTISS.CMF_10, ' ', sizeof(ISHPLOTISS.CMF_10));
										TRS.copy(ISHPLOTISS.CREATE_USER_ID, sizeof(ISHPLOTISS.CREATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
										TRS.copy(ISHPLOTISS.UPDATE_USER_ID, sizeof(ISHPLOTISS.UPDATE_USER_ID), in_node, IN_USERID);
										memcpy(ISHPLOTISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

										DBU_insert_ishplotiss(&ISHPLOTISS);
										if (DB_error_code != DB_SUCCESS)
										{
											strcpy(s_msg_code, "WIP-0004");
											TRS.add_fieldmsg(out_node, "ISHPLOTISS INSERT", MP_NVST);
											TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPLOTISS.ORG_LOT_ID), ISHPLOTISS.ORG_LOT_ID);
											TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPLOTISS.PACK_LOT_ID), ISHPLOTISS.PACK_LOT_ID);
											TRS.add_dberrmsg(out_node, DB_error_msg);

											gs_log_type.type = MP_LOG_ERROR;
											gs_log_type.e_type = MP_LOG_E_SYSTEM;
											gs_log_type.category = MP_LOG_CATE_TRANS;
											COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
											return MP_FALSE;
										}

										//검사 데이터 조회 
										//검사데이터를 베트남 ->음성 으로 넘겨준다.L/P 및 ROUND 검사 (202100721) 있으면 넣고 없으면 안넣는걸로 변경. 
										//ROUND 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											DBU_init_cqcmispdat(&CQCMISPDAT);
											TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
											memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
											DBU_open_cqcmispdat(5, &CQCMISPDAT);
											if (DB_error_code != DB_SUCCESS)
											{
												strcpy(s_msg_code, "QCM-0004");
												TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
												TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
												TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
												TRS.add_dberrmsg(out_node, DB_error_msg);

												gs_log_type.type = MP_LOG_ERROR;
												gs_log_type.e_type = MP_LOG_E_SYSTEM;
												gs_log_type.category = MP_LOG_CATE_VIEW;

												COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
												return MP_FALSE;
											}
											while (1)
											{
												DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code == DB_NOT_FOUND)
												{
													DBU_close_cqcmispdat(5);
													break;
												}
												else if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													DBU_close_cqcmispdat(5);
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}

												//검사 데이터 인터페이스 저장. 
												DBU_init_ishpispiss(&ISHPISPISS);
												memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
												memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
												memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
												ISHPISPISS.IF_CODE = 'N';
												memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
												memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
												memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
												ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
												memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
												ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
												ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
												ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
												memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
												ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
												ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
												memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
												memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
												memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
												memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
												memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
												memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
												memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
												memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
												memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
												memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
												memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
												memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
												memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
												memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
												memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
												memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
												memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
												memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
												memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
												memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
												memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
												memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
												memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
												memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
												memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
												ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
												memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
												ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
												memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
												memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
												memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
												memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
												memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
												memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
												memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
												memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
												memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
												memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
												memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
												memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
												TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
												TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
												memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

												DBU_insert_ishpispiss(&ISHPISPISS);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "WIP-0004");
													TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
													TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
													TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_TRANS;
													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
											}
										}

										//L/P 검사 조회
										DBU_init_cqcmispsts(&CQCMISPSTS);
										memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
										memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTS.LOT_CMF_12, sizeof(CQCMISPSTS.INSP_ID));
										DBU_select_cqcmispsts(1, &CQCMISPSTS);
										if (DB_error_code == DB_SUCCESS)
										{

											//L/P검사 데이터만(마지막 공정검사사 L/P인경우) 
											if (memcmp(CQCMISPSTS.INSP_OPER, "OC04120", strlen("OC04050")) == MP_FALSE)
											{


												DBU_init_cqcmispdat(&CQCMISPDAT);
												TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
												memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
												DBU_open_cqcmispdat(5, &CQCMISPDAT);
												if (DB_error_code != DB_SUCCESS)
												{
													strcpy(s_msg_code, "QCM-0004");
													TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", DT_NOVALUESTRING);
													TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
													TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
													TRS.add_dberrmsg(out_node, DB_error_msg);

													gs_log_type.type = MP_LOG_ERROR;
													gs_log_type.e_type = MP_LOG_E_SYSTEM;
													gs_log_type.category = MP_LOG_CATE_VIEW;

													COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
													return MP_FALSE;
												}
												while (1)
												{
													DBU_fetch_cqcmispdat(5, &CQCMISPDAT);
													if (DB_error_code == DB_NOT_FOUND)
													{
														DBU_close_cqcmispdat(5);
														break;
													}
													else if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "QCM-0004");
														TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
														TRS.add_dberrmsg(out_node, DB_error_msg);

														gs_log_type.type = MP_LOG_ERROR;
														gs_log_type.e_type = MP_LOG_E_SYSTEM;
														gs_log_type.category = MP_LOG_CATE_VIEW;

														DBU_close_cqcmispdat(5);
														COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
														return MP_FALSE;
													}

													//검사 데이터 인터페이스 저장. 
													DBU_init_ishpispiss(&ISHPISPISS);
													memcpy(ISHPISPISS.FACTORY, ISHPLOTISS.FACTORY, sizeof(ISHPLOTISS.FACTORY));
													memcpy(ISHPISPISS.PACK_LOT_ID, ISHPLOTISS.PACK_LOT_ID, sizeof(ISHPLOTISS.PACK_LOT_ID));
													memcpy(ISHPISPISS.ORG_LOT_ID, ISHPLOTISS.ORG_LOT_ID, sizeof(ISHPLOTISS.ORG_LOT_ID));
													ISHPISPISS.IF_CODE = 'N';
													memcpy(ISHPISPISS.TO_FACTORY, ISHPLOTISS.TO_FACTORY, sizeof(ISHPLOTISS.TO_FACTORY));
													memcpy(ISHPISPISS.INSP_ID, CQCMISPDAT.INSP_ID, sizeof(ISHPISPISS.INSP_ID));
													memcpy(ISHPISPISS.COL_SET_ID, CQCMISPDAT.COL_SET_ID, sizeof(ISHPISPISS.COL_SET_ID));
													ISHPISPISS.COL_SET_VER = CQCMISPDAT.COL_SET_VER;
													memcpy(ISHPISPISS.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(ISHPISPISS.CHAR_ID));
													ISHPISPISS.CHAR_SEQ = CQCMISPDAT.CHAR_SEQ;
													ISHPISPISS.UNIT_SEQ = CQCMISPDAT.UNIT_SEQ;
													ISHPISPISS.VALUE_SEQ = CQCMISPDAT.VALUE_SEQ;
													memcpy(ISHPISPISS.UNIT_ID, CQCMISPDAT.UNIT_ID, sizeof(ISHPISPISS.UNIT_ID));
													ISHPISPISS.VALUE_TYPE = CQCMISPDAT.VALUE_TYPE;
													ISHPISPISS.VALUE_COUNT = CQCMISPDAT.VALUE_COUNT;
													memcpy(ISHPISPISS.VALUE_1, CQCMISPDAT.VALUE_1, sizeof(ISHPISPISS.VALUE_1));
													memcpy(ISHPISPISS.VALUE_2, CQCMISPDAT.VALUE_2, sizeof(ISHPISPISS.VALUE_2));
													memcpy(ISHPISPISS.VALUE_3, CQCMISPDAT.VALUE_3, sizeof(ISHPISPISS.VALUE_3));
													memcpy(ISHPISPISS.VALUE_4, CQCMISPDAT.VALUE_4, sizeof(ISHPISPISS.VALUE_4));
													memcpy(ISHPISPISS.VALUE_5, CQCMISPDAT.VALUE_5, sizeof(ISHPISPISS.VALUE_5));
													memcpy(ISHPISPISS.VALUE_6, CQCMISPDAT.VALUE_6, sizeof(ISHPISPISS.VALUE_6));
													memcpy(ISHPISPISS.VALUE_7, CQCMISPDAT.VALUE_7, sizeof(ISHPISPISS.VALUE_7));
													memcpy(ISHPISPISS.VALUE_8, CQCMISPDAT.VALUE_8, sizeof(ISHPISPISS.VALUE_8));
													memcpy(ISHPISPISS.VALUE_9, CQCMISPDAT.VALUE_9, sizeof(ISHPISPISS.VALUE_9));
													memcpy(ISHPISPISS.VALUE_10, CQCMISPDAT.VALUE_10, sizeof(ISHPISPISS.VALUE_10));
													memcpy(ISHPISPISS.VALUE_11, CQCMISPDAT.VALUE_11, sizeof(ISHPISPISS.VALUE_11));
													memcpy(ISHPISPISS.VALUE_12, CQCMISPDAT.VALUE_12, sizeof(ISHPISPISS.VALUE_12));
													memcpy(ISHPISPISS.VALUE_13, CQCMISPDAT.VALUE_13, sizeof(ISHPISPISS.VALUE_13));
													memcpy(ISHPISPISS.VALUE_14, CQCMISPDAT.VALUE_14, sizeof(ISHPISPISS.VALUE_14));
													memcpy(ISHPISPISS.VALUE_15, CQCMISPDAT.VALUE_15, sizeof(ISHPISPISS.VALUE_15));
													memcpy(ISHPISPISS.VALUE_16, CQCMISPDAT.VALUE_16, sizeof(ISHPISPISS.VALUE_16));
													memcpy(ISHPISPISS.VALUE_17, CQCMISPDAT.VALUE_17, sizeof(ISHPISPISS.VALUE_17));
													memcpy(ISHPISPISS.VALUE_18, CQCMISPDAT.VALUE_18, sizeof(ISHPISPISS.VALUE_18));
													memcpy(ISHPISPISS.VALUE_19, CQCMISPDAT.VALUE_19, sizeof(ISHPISPISS.VALUE_19));
													memcpy(ISHPISPISS.VALUE_20, CQCMISPDAT.VALUE_20, sizeof(ISHPISPISS.VALUE_20));
													memcpy(ISHPISPISS.VALUE_21, CQCMISPDAT.VALUE_21, sizeof(ISHPISPISS.VALUE_21));
													memcpy(ISHPISPISS.VALUE_22, CQCMISPDAT.VALUE_22, sizeof(ISHPISPISS.VALUE_22));
													memcpy(ISHPISPISS.VALUE_23, CQCMISPDAT.VALUE_23, sizeof(ISHPISPISS.VALUE_23));
													memcpy(ISHPISPISS.VALUE_24, CQCMISPDAT.VALUE_24, sizeof(ISHPISPISS.VALUE_24));
													memcpy(ISHPISPISS.VALUE_25, CQCMISPDAT.VALUE_25, sizeof(ISHPISPISS.VALUE_25));
													ISHPISPISS.SAMPLE_COUNT = CQCMISPDAT.SAMPLE_COUNT;
													memcpy(ISHPISPISS.SPEC_OUT_MASK, CQCMISPDAT.SPEC_OUT_MASK, sizeof(ISHPISPISS.SPEC_OUT_MASK));
													ISHPISPISS.INSP_JUDGE_FLAG = CQCMISPDAT.INSP_JUDGE_FLAG;
													memcpy(ISHPISPISS.INSP_JUDGE_TYPE, CQCMISPDAT.INSP_JUDGE_TYPE, sizeof(ISHPISPISS.INSP_JUDGE_TYPE));
													memcpy(ISHPISPISS.INSP_JUDGE_TIME, CQCMISPDAT.INSP_JUDGE_TIME, sizeof(ISHPISPISS.INSP_JUDGE_TIME));
													memcpy(ISHPISPISS.CMF_1, CQCMISPDAT.CMF_1, sizeof(ISHPISPISS.CMF_1));
													memcpy(ISHPISPISS.CMF_2, CQCMISPDAT.CMF_2, sizeof(ISHPISPISS.CMF_2));
													memcpy(ISHPISPISS.CMF_3, CQCMISPDAT.CMF_3, sizeof(ISHPISPISS.CMF_3));
													memcpy(ISHPISPISS.CMF_4, CQCMISPDAT.CMF_4, sizeof(ISHPISPISS.CMF_4));
													memcpy(ISHPISPISS.CMF_5, CQCMISPDAT.CMF_5, sizeof(ISHPISPISS.CMF_5));
													memcpy(ISHPISPISS.CMF_6, CQCMISPDAT.CMF_6, sizeof(ISHPISPISS.CMF_6));
													memcpy(ISHPISPISS.CMF_7, CQCMISPDAT.CMF_7, sizeof(ISHPISPISS.CMF_7));
													memcpy(ISHPISPISS.CMF_8, CQCMISPDAT.CMF_8, sizeof(ISHPISPISS.CMF_8));
													memcpy(ISHPISPISS.CMF_9, CQCMISPDAT.CMF_9, sizeof(ISHPISPISS.CMF_9));
													memcpy(ISHPISPISS.CMF_10, CQCMISPDAT.CMF_10, sizeof(ISHPISPISS.CMF_10));
													TRS.copy(ISHPISPISS.CREATE_USER_ID, sizeof(ISHPISPISS.CREATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
													TRS.copy(ISHPISPISS.UPDATE_USER_ID, sizeof(ISHPISPISS.UPDATE_USER_ID), in_node, IN_USERID);
													memcpy(ISHPISPISS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

													DBU_insert_ishpispiss(&ISHPISPISS);
													if (DB_error_code != DB_SUCCESS)
													{
														strcpy(s_msg_code, "WIP-0004");
														TRS.add_fieldmsg(out_node, "ISHPISPISS INSERT", MP_NVST);
														TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(ISHPISPISS.ORG_LOT_ID), ISHPISPISS.ORG_LOT_ID);
														TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(ISHPISPISS.PACK_LOT_ID), ISHPISPISS.PACK_LOT_ID);
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
									}
								}
							}
						}

					}
				}
			}
		}
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_SHP_Ship_Lot_Validation()
        - Validation Check sub function of "CUS_SHP_SHIP_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_SHIP_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	TRSNode **pack_box_list;
	TRSNode **pack_final_box_list;
	int i = 0;
	double boxQty = 0;

	//PROCSTEP(4) : 출하지시에 등록된 전체 출하 LOT
	if (TRS.get_procstep(in_node) == '1' || TRS.get_procstep(in_node) == '2' || TRS.get_procstep(in_node) == '3')
	{
		pack_box_list = TRS.get_list(in_node, "PACK_BOX_LIST");
		pack_final_box_list = TRS.get_list(in_node, "PACK_FINAL_BOX_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "PACK_BOX_LIST"); i++)
		{
			// BOX - LOT 수량 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), pack_box_list[i], "BOX_ID");
			boxQty = DBU_select_cpaklotsts_scalar(8, &CPAKLOTSTS);

			//화면에서 선택된 BOX - LOT 수량과 현재 BOX에 매핑되어있는 LOT 수량이 다르다면 에러
			if (boxQty != TRS.get_double(pack_box_list[i], "QTY"))
			{
				// WIP-0581 : 박스에 매핑된 LOT이 전부 선택되지 않았습니다.
				strcpy(s_msg_code, "WIP-0581");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, boxQty);
				TRS.add_fieldmsg(out_node, "CHECK_QTY", MP_DBL, TRS.get_double(pack_box_list[i], "QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		for (i = 0; i < TRS.get_item_count(in_node, "PACK_FINAL_BOX_LIST"); i++)
		{
			// FINAL_BOX - LOT 수량 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), pack_final_box_list[i], "FINAL_BOX_ID");
			boxQty = DBU_select_cpaklotsts_scalar(9, &CPAKLOTSTS);

			//화면에서 선택된 FINALBOX - LOT 수량과 현재 FINAL BOX에 매핑되어있는 LOT 수량이 다르다면 에러
			if (boxQty != TRS.get_double(pack_final_box_list[i], "QTY"))
			{
				// WIP-0581 : 박스에 매핑된 LOT이 전부 선택되지 않았습니다.
				strcpy(s_msg_code, "WIP-0581");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
				TRS.add_fieldmsg(out_node, "QTY", MP_DBL, boxQty);
				TRS.add_fieldmsg(out_node, "CHECK_QTY", MP_DBL, TRS.get_double(pack_final_box_list[i], "QTY"));
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
    
    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Ship_Lot_Before_Transaction()
- Main sub function of "CUS_SHP_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Ship_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Ship_Lot_After_Transaction()
- Main sub function of "CUS_SHP_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Ship_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}