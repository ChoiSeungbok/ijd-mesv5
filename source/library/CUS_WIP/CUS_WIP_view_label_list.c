/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_label_list.c
Description : View Label List function

MES Version : 5.0

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/21  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Label_List_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int CUS_WIP_VIEW_LABEL_LIST(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_WIP_View_Label_List()
- View Label List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Label_List(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_VIEW_LABEL_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_VIEW_LABEL_LIST", out_node);
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
CUS_WIP_VIEW_LABEL_LIST()
- Main sub function of "CUS_WIP_View_Label_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_LABEL_LIST(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MINVDLVLBL_TAG MINVDLVLBL;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct MWIPLOTHISX_TAG MWIPLOTHIS_ORGLOT;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MWIPLOTLOS_TAG MWIPLOTLOS;
	struct MWIPFLWOPR_TAG MWIPFLWOPR;
	struct CWIPGRPSTS_TAG CWIPGRPSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MRASRESDEF_TAG MRASRESDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_WH;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_OUT;
	struct CWIPORDBOM_TAG CWIPORDBOM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;
	struct MWIPMATDEF_TAG MWIPMATDEF_BOM;
	struct MWIPMATDEF_TAG MWIPMATDEF_LOT;
	struct CWIPLOTMVM_TAG CWIPLOTMVM;
	struct CWIPLOTMVC_TAG CWIPLOTMVC;
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVREQDTL_TAG MINVREQDTL;
	struct MINVREQLOT_TAG MINVREQLOT;
	struct CBASLBLDAT_TAG CBASLBLDAT;
	struct MINVMOVSTS_TAG MINVMOVSTS;
	struct MINVMOVLOT_TAG MINVMOVLOT;
	struct CWIPPRSRUN_TAG CWIPPRSRUN;
	struct MGCMLAGDAT_TAG MGCMLAGDAT;
	struct CRETLOTSTS_TAG CRETLOTSTS;
	struct CWIPGRTBLD_TAG CWIPGRTBLD;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX_ITEM;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct CSHPORDMST_TAG CSHPORDMST;
	struct CSHPORDDTL_TAG CSHPORDDTL;
	struct MGCMLAGDAT_TAG MGCMLAGDAT_DRAWING;
	struct MGCMLAGDAT_TAG MGCMLAGDAT_DRAWING2;
	struct MGCMLAGDAT_TAG MGCMLAGDAT_CUSTITEM;

	TRSNode** box_list;
	TRSNode* list_item;
	TRSNode** kitting_list;
	TRSNode** inv_lot_list;
	TRSNode** lot_list;
	TRSNode** group_list;
	TRSNode** cell_list;
	TRSNode** data_list;
	TRSNode** ship_order_list;

	int i = 0;
	int i_step = 0;
	int l_step = 0;
	int i_lot_count = 0;
	int i_data_count = 0;
	int row_num = 0;
	int mat_ver = 0;
	int i_page_no = 0;
	char qr_data[200];
	char s_label_type[240];
	char s_label_mesh[240];
	char s_customer_item[200];
	char s_drawing_flag[200];
	char s_reg_date[14];
	char s_vendor_name[50];
	char s_vendor_site_id[30];
	char s_customer_site_id[10];
	char s_cell_weight[13];
	char s_cell_height[13];
	char s_lot_id[25];
	char s_mat_id[30];
	char remark = ' ';
	double unpacked_qty = 0;
	double d_y_count = 0;
	double d_n_count = 0;
	double count = 0;
	double d_stock_qty = 0;


	LOG_head("CUS_WIP_View_Label_List");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_WIP_View_Label_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	//자재불출요청 
	if (TRS.get_procstep(in_node) == '0')
	{
		// MINVREQMST - 불출 요청 마스터 정보 조회
		DBU_init_minvreqmst(&MINVREQMST);
		TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "REQ_NO");

		DBU_select_minvreqmst(1, &MINVREQMST);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "MINVREQMST SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQMST.REQ_NO), MINVREQMST.REQ_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//출고 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MINVREQMST.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MINVREQMST.OPER, sizeof(MWIPOPRDEF.OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 입고 창고
		DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
		memcpy(MWIPOPRDEF_WH.FACTORY, MINVREQMST.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
		memcpy(MWIPOPRDEF_WH.OPER, MINVREQMST.TO_OPER, sizeof(MWIPOPRDEF_WH.OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		list_item = TRS.add_node(out_node, "LABEL_LIST");
		TRS.add_string(list_item, "TRANS_SEQ", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		TRS.add_string(list_item, "TRANS_SEQ2", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
		TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));

		//자재불출요청 확정시
		if (memcmp(MINVREQMST.REQ_STATUS, MP_CINV_ISSUE_REQUEST, strlen(MP_CINV_ISSUE_REQUEST)) == 0)
		{
			DBU_init_minvreqdtl(&MINVREQDTL);
			memcpy(MINVREQDTL.FACTORY, MINVREQMST.FACTORY, sizeof(MINVREQDTL.FACTORY));
			memcpy(MINVREQDTL.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQDTL.REQ_NO));

			i_step = 3;
			DBU_open_minvreqdtl(i_step, &MINVREQDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVREQDTL OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_minvreqdtl(i_step, &MINVREQDTL);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_minvreqdtl(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "INV-0004");
					TRS.add_fieldmsg(out_node, "MINVREQDTL FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVREQDTL.FACTORY), MINVREQDTL.FACTORY);
					TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQDTL.REQ_NO), MINVREQDTL.REQ_NO);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_minvreqdtl(i_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//품목 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MINVREQDTL.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MINVREQDTL.REQ_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = MINVREQDTL.REQ_MAT_VER;

				DBU_select_mwipmatdef(1, &MWIPMATDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					// 20.12.21 minjae.go
					DBU_close_minvreqdtl(i_step);
					//

					return MP_FALSE;
				}

				row_num = i_lot_count % 6;

				if (i_lot_count == 0)
				{
					memset(s_reg_date, ' ', sizeof(s_reg_date));
					memcpy(s_reg_date, MINVREQDTL.UPDATE_TIME, sizeof(MINVREQDTL.UPDATE_TIME));
					TRS.add_string(list_item, "REG_DATE", s_reg_date, sizeof(s_reg_date));
				}
				else if (row_num == 0)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "TRANS_SEQ", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
					TRS.add_string(list_item, "TRANS_SEQ2", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
					TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
					TRS.add_string(list_item, "REG_DATE", s_reg_date, sizeof(s_reg_date));
				}

				i_lot_count++;

				switch (row_num)
				{
				case 0:
					TRS.add_string(list_item, "ITEM_CODE1", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME1", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY1", MINVREQDTL.REQ_QTY);
					break;

				case 1:
					TRS.add_string(list_item, "ITEM_CODE2", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM2", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY2", MINVREQDTL.REQ_QTY);
					break;

				case 2:
					TRS.add_string(list_item, "ITEM_CODE3", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME3", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM3", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY3", MINVREQDTL.REQ_QTY);
					break;

				case 3:
					TRS.add_string(list_item, "ITEM_CODE4", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME4", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM4", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY4", MINVREQDTL.REQ_QTY);
					break;

				case 4:
					TRS.add_string(list_item, "ITEM_CODE5", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME5", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM5", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY5", MINVREQDTL.REQ_QTY);
					break;

				case 5:
					TRS.add_string(list_item, "ITEM_CODE6", MINVREQDTL.REQ_MAT_ID, sizeof(MINVREQDTL.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME6", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM6", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY6", MINVREQDTL.REQ_QTY);
					break;
				}
			}

		}
		//자재불출요청 등록 확정시
		else
		{
			lot_list = TRS.get_list(in_node, "REQ_LOT_LIST");

			for (i = 0; i < TRS.get_item_count(in_node, "REQ_LOT_LIST"); i++)
			{
				// MINVREQLOT - 불출 요청 LOT 정보 조회
				DBU_init_minvreqlot(&MINVREQLOT);
				memcpy(MINVREQLOT.FACTORY, MINVREQMST.FACTORY, sizeof(MINVREQLOT.FACTORY));
				memcpy(MINVREQLOT.REQ_NO, MINVREQMST.REQ_NO, sizeof(MINVREQLOT.REQ_NO));
				TRS.copy(MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID), lot_list[i], "REQ_LOT_ID");

				DBU_select_minvreqlot(2, &MINVREQLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "MINVREQLOT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(MINVREQLOT.REQ_NO), MINVREQLOT.REQ_NO);
					TRS.add_fieldmsg(out_node, "REQ_MAT_ID", MP_STR, sizeof(MINVREQLOT.REQ_MAT_ID), MINVREQLOT.REQ_MAT_ID);
					TRS.add_fieldmsg(out_node, "REQ_MAT_VER", MP_INT, MINVREQLOT.REQ_MAT_VER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//품목 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MINVREQLOT.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MINVREQLOT.REQ_MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = MINVREQLOT.REQ_MAT_VER;

				DBU_select_mwipmatdef(1, &MWIPMATDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				row_num = i % 6;

				if (i == 0)
				{
					memset(s_reg_date, ' ', sizeof(s_reg_date));
					memcpy(s_reg_date, MINVREQLOT.UPDATE_TIME, sizeof(MINVREQLOT.UPDATE_TIME));
					TRS.add_string(list_item, "REG_DATE", s_reg_date, sizeof(s_reg_date));
				}
				else if (row_num == 0)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "TRANS_SEQ", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
					TRS.add_string(list_item, "TRANS_SEQ2", MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO));
					TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
					TRS.add_string(list_item, "REG_DATE", s_reg_date, sizeof(s_reg_date));
				}

				switch (row_num)
				{
				case 0:
					TRS.add_string(list_item, "ITEM_CODE1", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME1", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO1", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM1", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY1", MINVREQLOT.REQ_QTY);
					break;

				case 1:
					TRS.add_string(list_item, "ITEM_CODE2", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO2", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM2", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY2", MINVREQLOT.REQ_QTY);
					break;

				case 2:
					TRS.add_string(list_item, "ITEM_CODE3", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME3", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO3", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM3", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY3", MINVREQLOT.REQ_QTY);
					break;

				case 3:
					TRS.add_string(list_item, "ITEM_CODE4", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME4", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO4", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM4", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY4", MINVREQLOT.REQ_QTY);
					break;

				case 4:
					TRS.add_string(list_item, "ITEM_CODE5", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME5", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO5", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM5", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY5", MINVREQLOT.REQ_QTY);
					break;

				case 5:
					TRS.add_string(list_item, "ITEM_CODE6", MINVREQLOT.REQ_MAT_ID, sizeof(MINVREQLOT.REQ_MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME6", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO6", MINVREQLOT.INV_LOT_ID, sizeof(MINVREQLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM6", MINVREQLOT.UNIT, sizeof(MINVREQLOT.UNIT));
					TRS.add_double(list_item, "LOT_QTY6", MINVREQLOT.REQ_QTY);
					break;
				}
			}
		}
	}
	//원자재 라벨 데이터
	else if (TRS.get_procstep(in_node) == '1')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_minvdlvlot(&MINVDLVLOT);
			TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), inv_lot_list[i], "DLV_LOT_ID");
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

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVDLVLOT.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			//협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVDLVMST.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvdlvlbl(&MINVDLVLBL);
			TRS.copy(MINVDLVLBL.FACTORY, sizeof(MINVDLVLBL.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVDLVLBL.DLV_LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
			TRS.copy(MINVDLVLBL.LABEL_ID, sizeof(MINVDLVLBL.LABEL_ID), inv_lot_list[i], "INV_LOT_ID");
			DBU_select_minvdlvlbl(1, &MINVDLVLBL);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVDLVLBL SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
				TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "ITEM_CODE", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "INPUT_DATE", MINVDLVLOT.DLV_TIME, sizeof(MINVDLVLOT.DLV_TIME));
			TRS.add_double(list_item, "LOT_QTY", MINVDLVLBL.QTY);
			TRS.add_string(list_item, "UOM", MINVDLVLOT.UNIT, sizeof(MINVDLVLOT.UNIT));
			TRS.add_string(list_item, "VENDOR_NAME", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			TRS.add_string(list_item, "SUPPLIER_LOT_ID", MINVDLVLOT.VENDOR_LOT_ID, sizeof(MINVDLVLOT.VENDOR_LOT_ID));
			TRS.add_string(list_item, "LOT_ID", MINVDLVLBL.LABEL_ID, sizeof(MINVDLVLBL.LABEL_ID));
		}
	}
	// 입고 후 원자재 라벨
	else if (TRS.get_procstep(in_node) == '2')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "INV_LOT_ID");

			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
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

			//협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVLOTSTS.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "ITEM_CODE", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "INPUT_DATE", MINVLOTSTS.RECV_DATE, sizeof(MINVLOTSTS.RECV_DATE));
			TRS.add_double(list_item, "LOT_QTY", MINVLOTSTS.QTY);
			TRS.add_string(list_item, "UOM", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));


			if (DB_error_code == DB_NOT_FOUND)
			{
				memset(s_vendor_name, ' ', sizeof(s_vendor_name));
				TRS.add_string(list_item, "VENDOR_NAME", s_vendor_name, sizeof(s_vendor_name));
			}
			else
			{
				TRS.add_string(list_item, "VENDOR_NAME", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			}

			TRS.add_string(list_item, "SUPPLIER_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
			TRS.add_string(list_item, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		}
	}
	// 공정 라벨 데이터
	else if (TRS.get_procstep(in_node) == '3')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), lot_list[i], "LOT_ID");

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
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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

			//CWIPGRPSTS 조회
			DBU_init_cwipgrpsts(&CWIPGRPSTS);

			if (MWIPLOTSTSX.LOT_CMF_1[0] != ' ')
			{
				TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPGRPSTS.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPSTS.GROUP_ID));

				DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPGRPSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}

			// 마지막 비고정보조회
			DBU_init_mwiplothisx(&MWIPLOTHIS_ORGLOT);
			memcpy(MWIPLOTHIS_ORGLOT.LOT_ID, MWIPLOTSTSX.FROM_TO_LOT_ID, sizeof(MWIPLOTHIS_ORGLOT.LOT_ID));
			memcpy(MWIPLOTHIS_ORGLOT.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTHIS_ORGLOT.OPER));
			memcpy(MWIPLOTHIS_ORGLOT.TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END));

			DBU_select_mwiplothisx(6, &MWIPLOTHIS_ORGLOT);


			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "MAIN_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(list_item, "ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
			TRS.add_string(list_item, "WO_NO", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));


			if (MWIPLOTHIS_ORGLOT.TRAN_COMMENT[0] != ' ')
			{
				TRS.add_string(list_item, "REMARKS", MWIPLOTHIS_ORGLOT.TRAN_COMMENT, sizeof(MWIPLOTHIS_ORGLOT.TRAN_COMMENT));
			}
			else
			{
				TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
			}


			//TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
			TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
		}
	}
	// 공정 라벨 데이터- CEll 라벨
	else if (TRS.get_procstep(in_node) == '4')
	{
		cell_list = TRS.get_list(in_node, "CELL_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "CELL_LIST"); i++)
		{
			//CWIPGRPSTS 조회
			DBU_init_cwipgrpsts(&CWIPGRPSTS);
			TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), cell_list[i], "GROUP_ID");

			DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPGRPSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			COM_dtoa(s_cell_height, CWIPGRPSTS.CELL_HEIGHT, sizeof(s_cell_height));
			COM_dtoa(s_cell_weight, CWIPGRPSTS.CELL_WEIGHT, sizeof(s_cell_weight));

			//작업지시 조회
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, CWIPGRPSTS.CMF_1, sizeof(MWIPORDSTS.ORDER_ID));

			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPORDSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPORDSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPORDSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "CELL_NO", CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "WO_NO", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			TRS.add_string(list_item, "PC0201", s_cell_height, sizeof(s_cell_height));
			TRS.add_string(list_item, "PC0202", s_cell_weight, sizeof(s_cell_weight));
			TRS.add_string(list_item, "PC0203", CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID));
			TRS.add_string(list_item, "PC0204", CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR));
		}
	}
	// 출하 라벨 데이터
	else if (TRS.get_procstep(in_node) == '5')
	{
		lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "PACK_LOT_LIST");

		for (i = 0; i < i_lot_count; i++)
		{
			memset(s_label_type, 0x00, sizeof(s_label_type));
			memset(s_label_mesh, 0x00, sizeof(s_label_mesh));
			memset(qr_data, 0x00, sizeof(qr_data));
			memset(s_drawing_flag, 0x00, sizeof(s_drawing_flag));
			memset(s_customer_item, 0x00, sizeof(s_customer_item));


			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), lot_list[i], "PACK_LOT_ID");
			TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), lot_list[i], "ORG_LOT_ID");

			DBU_select_cpaklotsts(1, &CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, CPAKLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;
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

			// 포장 지시 정보 조회
			DBU_init_cpakordsts(&CPAKORDSTS);
			memcpy(CPAKORDSTS.FACTORY, CPAKLOTSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY));
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;

			DBU_select_cpakordsts(1, &CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT ", DT_NOVALUESTRING);
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





			// GRT FEFA SIZE 조회1
			DBU_init_mgcmlagdat(&MGCMLAGDAT_DRAWING);
			TRS.copy(MGCMLAGDAT_DRAWING.FACTORY, sizeof(MGCMLAGDAT_DRAWING.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT_DRAWING.TABLE_NAME, "C_FEFA_SIZE2", strlen("C_FEFA_SIZE2"));
			memcpy(MGCMLAGDAT_DRAWING.KEY_1, CPAKORDSTS.DELIVERY_ID, sizeof(CPAKORDSTS.DELIVERY_ID));
			memcpy(MGCMLAGDAT_DRAWING.KEY_2, CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT_DRAWING);


			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT(1) SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{


				DBU_init_mgcmlagdat(&MGCMLAGDAT_DRAWING2);
				TRS.copy(MGCMLAGDAT_DRAWING2.FACTORY, sizeof(MGCMLAGDAT_DRAWING2.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMLAGDAT_DRAWING2.TABLE_NAME, "C_FEFA_SIZE", strlen("C_FEFA_SIZE"));
				memcpy(MGCMLAGDAT_DRAWING2.KEY_1, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
				//memcpy(MGCMLAGDAT_DRAWING.KEY_2, CPAKORDSTS.CUSTOMER_SITE_ID, sizeof(CPAKORDSTS.CUSTOMER_SITE_ID));
				COM_itoa_left(s_customer_site_id, CPAKORDSTS.CUSTOMER_SITE_ID, sizeof(s_customer_site_id));
				memcpy(MGCMLAGDAT_DRAWING2.KEY_2, s_customer_site_id, sizeof(s_customer_site_id));
				memcpy(MGCMLAGDAT_DRAWING2.KEY_3, CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
				DBU_select_mgcmlagdat(1, &MGCMLAGDAT_DRAWING2);


				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMTBLDAT(2) SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT_DRAWING2.FACTORY), MGCMLAGDAT_DRAWING2.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT_DRAWING2.TABLE_NAME), MGCMLAGDAT_DRAWING2.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(MGCMLAGDAT_DRAWING2.KEY_1), MGCMLAGDAT_DRAWING2.KEY_1);
					TRS.add_fieldmsg(out_node, "SITE_USE_ID", MP_STR, sizeof(MGCMLAGDAT_DRAWING2.KEY_2), MGCMLAGDAT_DRAWING2.KEY_2);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MGCMLAGDAT_DRAWING2.KEY_3), MGCMLAGDAT_DRAWING2.KEY_3);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				if (DB_error_code == DB_NOT_FOUND)
				{



					memcpy(s_drawing_flag, CPAKORDSTS.DRAWING_FLAG, sizeof(s_drawing_flag));



				}
				else
				{

					memcpy(s_drawing_flag, MGCMLAGDAT_DRAWING2.DATA_2, sizeof(s_drawing_flag));



				}

			}
			else
			{

				//COM_memcpy(s_drawing_flag, CPAKORDSTS.DRAWING_FLAG, sizeof(CPAKORDSTS.DRAWING_FLAG));
				memcpy(s_drawing_flag, MGCMLAGDAT_DRAWING.DATA_2, sizeof(s_drawing_flag));

			}






			// GRT CUSTOMER ITEM 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT_CUSTITEM);
			TRS.copy(MGCMLAGDAT_CUSTITEM.FACTORY, sizeof(MGCMLAGDAT_CUSTITEM.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT_CUSTITEM.TABLE_NAME, "C_DELIVERY_ITEM", strlen("C_DELIVERY_ITEM"));
			memcpy(MGCMLAGDAT_CUSTITEM.KEY_1, CPAKORDSTS.DELIVERY_ID, sizeof(CPAKORDSTS.DELIVERY_ID));
			memcpy(MGCMLAGDAT_CUSTITEM.KEY_2, CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT_CUSTITEM);


			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMLAGDAT_CUSTITEM SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.FACTORY), MGCMLAGDAT_CUSTITEM.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.TABLE_NAME), MGCMLAGDAT_CUSTITEM.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "DELIVERY_ID", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.KEY_1), MGCMLAGDAT_CUSTITEM.KEY_1);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.KEY_2), MGCMLAGDAT_CUSTITEM.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_init_mgcmlagdat(&MGCMLAGDAT_CUSTITEM);
				TRS.copy(MGCMLAGDAT_CUSTITEM.FACTORY, sizeof(MGCMLAGDAT_CUSTITEM.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMLAGDAT_CUSTITEM.TABLE_NAME, "C_CUSTOMER_ITEM", strlen("C_CUSTOMER_ITEM"));
				memcpy(MGCMLAGDAT_CUSTITEM.KEY_1, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));

				COM_itoa_left(s_customer_site_id, CPAKORDSTS.CUSTOMER_SITE_ID, sizeof(s_customer_site_id));
				memcpy(MGCMLAGDAT_CUSTITEM.KEY_2, s_customer_site_id, sizeof(s_customer_site_id));
				memcpy(MGCMLAGDAT_CUSTITEM.KEY_3, CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
				DBU_select_mgcmlagdat(1, &MGCMLAGDAT_CUSTITEM);


				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					TRS.add_fieldmsg(out_node, "MGCMLAGDAT_CUSTITEM SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.FACTORY), MGCMLAGDAT_CUSTITEM.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.TABLE_NAME), MGCMLAGDAT_CUSTITEM.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "CUSTOMER_ID", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.KEY_1), MGCMLAGDAT_CUSTITEM.KEY_1);
					TRS.add_fieldmsg(out_node, "SITE_USE_ID", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.KEY_2), MGCMLAGDAT_CUSTITEM.KEY_2);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MGCMLAGDAT_CUSTITEM.KEY_3), MGCMLAGDAT_CUSTITEM.KEY_3);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


				if (DB_error_code == DB_NOT_FOUND)
				{

					memcpy(s_customer_item, CPAKORDSTS.LINE_DESC, sizeof(s_customer_item));

				}
				else
				{

					memcpy(s_customer_item, MGCMLAGDAT_CUSTITEM.DATA_2, sizeof(s_customer_item));
				}

			}
			else
			{


				//COM_memcpy(s_customer_item, CPAKORDSTS.LINE_DESC, sizeof(CPAKORDSTS.LINE_DESC));
				memcpy(s_customer_item, MGCMLAGDAT_CUSTITEM.DATA_2, sizeof(s_customer_item));


			}






			list_item = TRS.add_node(out_node, "LABEL_LIST");


			//LABEL TYPE이 비어있는 경우, GRADE
			if (CPAKORDSTS.LABEL_TYPE[0] == ' ')
			{
				memcpy(s_label_type, MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			}
			else
			{
				memcpy(s_label_type, CPAKORDSTS.LABEL_TYPE, sizeof(CPAKORDSTS.LABEL_TYPE));
			}

			//LABEL MESH가 비어 있는 경우, SIZE
			if (CPAKORDSTS.LABEL_MESH[0] == ' ')
			{
				memcpy(s_label_mesh, MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
			}
			else
			{
				memcpy(s_label_mesh, CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
			}

			//CTM
			if (memcmp(CPAKORDSTS.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "TYPE", s_label_mesh, sizeof(s_label_mesh));
				TRS.add_string(list_item, "ITEM_NAME", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", s_label_mesh, sizeof(s_label_mesh));
			}
			// GRIT 
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
			{
				/*
				coating_rate = COM_atof(CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
				gross = (CPAKLOTSTS.QTY * 100) / (100 - coating_rate);
				COM_dtoa(s_gross, gross, sizeof(s_gross));
				*/

				if (CPAKLOTSTS.CMF_1[0] == ' ')
				{
					COM_memcpy(qr_data, "", sizeof(qr_data));
				}
				else
				{
					COM_memcpy(qr_data, CPAKLOTSTS.CMF_1, sizeof(qr_data));
				}

				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "COAT", CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
				TRS.add_string(list_item, "QR_DATA", qr_data, sizeof(qr_data));
				// TRS.add_string(list_item, "DRAWING_FLAG", CPAKORDSTS.DRAWING_FLAG, sizeof(CPAKORDSTS.DRAWING_FLAG));
			 //	TRS.add_string(list_item, "DRAWING_FLAG", s_drawing_flag, sizeof(s_drawing_flag));
				TRS.add_string(list_item, "DRAWING_FLAG", s_drawing_flag, sizeof(s_drawing_flag));
				//   TRS.add_string(list_item, "DRAWING_FLAG2", s_drawing_flag, sizeof(s_drawing_flag));







				   //20210623 FEFA SIZE(drawing_flag ERP에서 받던거 MES에 기준정보 등록이 되어있으면 MES거 가져오는걸로 변경.

				TRS.add_string(list_item, "TYPE", s_label_mesh, sizeof(s_label_mesh));

				//CUSTOMER PART NO
				// 
				// //20221108 CUSTOMER ITME(LINE_DESC ERP에서 받던거 MES에 기준정보 등록이 되어있으면 MES거 가져오는걸로 변경.
			  //  TRS.add_string(list_item, "LINE_DESC", CPAKORDSTS.LINE_DESC, sizeof(CPAKORDSTS.LINE_DESC));
				TRS.add_string(list_item, "LINE_DESC", s_customer_item, sizeof(s_customer_item));

			}
			//HM
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "SPEC", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
				TRS.add_int(list_item, "BOX_COUNT", i_lot_count);
				TRS.add_string(list_item, "ITEM_NAME1", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
			}
			//PDC
			//else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_PDC, strlen(MP_AREA_PDC)) == 0)
			else if (memcmp(CPAKORDSTS.AREA_ID, gs_area_pdc, strlen(gs_area_pdc)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "TYPE", s_label_mesh, sizeof(s_label_mesh));
				TRS.add_string(list_item, "ITEM_NAME", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", s_label_mesh, sizeof(s_label_mesh));

				TRS.add_string(list_item, "CMF_3", CPAKORDSTS.CMF_3, sizeof(CPAKORDSTS.CMF_3));
				TRS.add_string(list_item, "CMF_4", CPAKORDSTS.CMF_4, sizeof(CPAKORDSTS.CMF_4));
				TRS.add_string(list_item, "CMF_5", CPAKORDSTS.CMF_5, sizeof(CPAKORDSTS.CMF_5));
				TRS.add_string(list_item, "CMF_6", CPAKORDSTS.CMF_6, sizeof(CPAKORDSTS.CMF_6));
			}

			TRS.add_string(list_item, "LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			TRS.add_double(list_item, "LOT_QTY", CPAKLOTSTS.QTY);
			TRS.add_string(list_item, "ITEM", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "ITEM_UOM", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_string(list_item, "PO_NUMBER", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			TRS.add_string(list_item, "MN_NO", CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));


		}
	}
	// T-CARD
	else if (TRS.get_procstep(in_node) == '6')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			// LOT 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// ORDER ID가 없는 경우 T-CARD 발행 불가
			if (COM_isnullspace(MWIPLOTSTSX.ORDER_ID) == MP_TRUE)
			{
				strcpy(s_msg_code, "WIP-0001");
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0012 : 이 FLOW는 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0012");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//작업지시 조회
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0018");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//사업부 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			memcpy(MGCMTBLDAT_AREA.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

			//작업장 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			memcpy(MGCMTBLDAT.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			//완료 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
			memcpy(MWIPOPRDEF_WH.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
			memcpy(MWIPOPRDEF_WH.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_WH.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//설비 조회
			DBU_init_mrasresdef(&MRASRESDEF);
			memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));

			if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
			{
				memcpy(MRASRESDEF.RES_ID, MWIPLOTSTSX.END_RES_ID, sizeof(MRASRESDEF.RES_ID));
			}
			else
			{
				memcpy(MRASRESDEF.RES_ID, MWIPLOTSTSX.START_RES_ID, sizeof(MRASRESDEF.RES_ID));
			}

			DBU_select_mrasresdef(1, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//RAS-0003 : 존재하지 않는 장비입니다.
				strcpy(s_msg_code, "RAS-0003");
				TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//FLOW조회
			l_step = 2;
			DBU_init_mwipflwopr(&MWIPFLWOPR);
			memcpy(MWIPFLWOPR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
			memcpy(MWIPFLWOPR.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));

			DBU_open_mwipflwopr(l_step, &MWIPFLWOPR);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0012 : 이 FLOW는 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0012");
				TRS.add_fieldmsg(out_node, "MWIPFLWOPR OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_mwipflwopr(l_step, &MWIPFLWOPR);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_mwipflwopr(l_step);

					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_mwipflwopr(l_step);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//공정 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				memcpy(MWIPOPRDEF.FACTORY, MWIPFLWOPR.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
				memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);

				if (MWIPOPRDEF.INV_FLAG == ' ')
				{
					//SEQ_NUM=1인 경우, CWIPORDBOM조회
					if (MWIPFLWOPR.SEQ_NUM == 1)
					{
						i_step = 4;

						DBU_init_cwipordbom(&CWIPORDBOM);
						memcpy(CWIPORDBOM.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPORDBOM.FACTORY));
						memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID));
						memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(CWIPORDBOM.FLOW));
						memcpy(CWIPORDBOM.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
						DBU_open_cwipordbom(i_step, &CWIPORDBOM);
						if (DB_error_code != DB_SUCCESS)
						{
							//ORD-0028 : 이 자재는 작업지시 BOM에 속해 있지 않습니다. 작업지시를 확인하세요.
							strcpy(s_msg_code, "ORD-0028");
							TRS.add_fieldmsg(out_node, "CWIPORDBOM OPEN", MP_NVST);
							TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
							TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(CWIPORDBOM.FLOW), CWIPORDBOM.FLOW);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

							// 20.12.21 minjae.go
							DBU_close_mwipflwopr(l_step);
							//

							return MP_FALSE;
						}


						while (1)
						{
							DBU_fetch_cwipordbom(i_step, &CWIPORDBOM);
							if (DB_error_code == DB_NOT_FOUND)
							{


								list_item = TRS.add_node(out_node, "LABEL_LIST");

								TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
								TRS.add_int(list_item, "SEQ_NUM", MWIPFLWOPR.SEQ_NUM);
								TRS.add_string(list_item, "OP_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
								TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
								TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
								TRS.add_string(list_item, "WIP_ENTITY_NAME", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
								TRS.add_string(list_item, "JOB_DATE", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
								TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
								TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
								TRS.add_double(list_item, "PLAN_QTY", MWIPORDSTS.ORD_QTY);
								TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
								TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
								// TRS.add_string(list_item, "REMARKS", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
								TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
								TRS.add_string(list_item, "MC_NAME", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));




								DBU_close_cwipordbom(i_step);
								break;

							}
							else if (DB_error_code != DB_SUCCESS)
							{
								//ORD-0028 : 이 자재는 작업지시 BOM에 속해 있지 않습니다. 작업지시를 확인하세요.
								strcpy(s_msg_code, "ORD-0028");
								TRS.add_fieldmsg(out_node, "CWIPORDBOM FETCH", MP_NVST);
								TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
								TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
								TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(CWIPORDBOM.FLOW), CWIPORDBOM.FLOW);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								DBU_close_cwipordbom(i_step);
								// 20.12.21 minjae.go
								DBU_close_mwipflwopr(l_step);
								//
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}

							//제품 조회
							DBU_init_mwipmatdef(&MWIPMATDEF_BOM);
							memcpy(MWIPMATDEF_BOM.FACTORY, CWIPORDBOM.FACTORY, sizeof(MWIPMATDEF_BOM.FACTORY));
							memcpy(MWIPMATDEF_BOM.MAT_ID, CWIPORDBOM.MAT_ID, sizeof(MWIPMATDEF_BOM.MAT_ID));
							MWIPMATDEF_BOM.MAT_VER = CWIPORDBOM.MAT_VER;

							DBU_select_mwipmatdef(1, &MWIPMATDEF_BOM);
							if (DB_error_code != DB_SUCCESS)
							{
								strcpy(s_msg_code, "WIP-0006");
								TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(2) ", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BOM.FACTORY), MWIPMATDEF_BOM.FACTORY);
								TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BOM.MAT_ID), MWIPMATDEF_BOM.MAT_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_TRANS;
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

								// 20.12.21 minjae.go
								DBU_close_cwipordbom(i_step);
								DBU_close_mwipflwopr(l_step);
								//

								return MP_FALSE;
							}

							//출고 창고 조회
							DBU_init_mwipoprdef(&MWIPOPRDEF_OUT);
							memcpy(MWIPOPRDEF_OUT.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPOPRDEF_OUT.FACTORY));
							memcpy(MWIPOPRDEF_OUT.OPER, CWIPORDBOM.OUT_OPER, sizeof(MWIPOPRDEF_OUT.OPER));

							DBU_select_mwipoprdef(1, &MWIPOPRDEF_OUT);
							/* 데이터가 없으면 그냥 빈값으로만 보이도록 주석처리 함.
							if (DB_error_code != DB_SUCCESS)
							{
								//WIP-0590 : 이 창고는 존재하지 않습니다.
								strcpy(s_msg_code, "WIP-0590");
								TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_OUT.FACTORY), MWIPOPRDEF_OUT.FACTORY);
								TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_OUT.OPER), MWIPOPRDEF_OUT.OPER);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_TRANS;
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

								// 20.12.21 minjae.go
								DBU_close_cwipordbom(i_step);
								DBU_close_mwipflwopr(l_step);
								//

								return MP_FALSE;
							}
							*/

							// 불량수량 조회
							DBU_init_mwiplotlos(&MWIPLOTLOS);
							memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTLOS.LOT_ID));
							memcpy(MWIPLOTLOS.OPER, CWIPORDBOM.OPER, sizeof(MWIPLOTLOS.OPER));

							DBU_select_mwiplotlos(2, &MWIPLOTLOS);
							if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "MWIPLOTLOS SELECT ", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTLOS.LOT_ID), MWIPLOTLOS.LOT_ID);
								TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTLOS.OPER), MWIPLOTLOS.OPER);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_TRANS;
								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

								// 20.12.21 minjae.go
								DBU_close_cwipordbom(i_step);
								DBU_close_mwipflwopr(l_step);
								//

								return MP_FALSE;
							}

							list_item = TRS.add_node(out_node, "LABEL_LIST");

							TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
							TRS.add_int(list_item, "SEQ_NUM", MWIPFLWOPR.SEQ_NUM);
							TRS.add_string(list_item, "OP_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
							TRS.add_double(list_item, "LOT_QTY", MWIPORDSTS.ORD_QTY);
							TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
							TRS.add_string(list_item, "WIP_ENTITY_NAME", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
							TRS.add_string(list_item, "JOB_DATE", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
							TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
							TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
							TRS.add_double(list_item, "PLAN_QTY", MWIPORDSTS.ORD_QTY);
							TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
							TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));
							TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));

							//TRS.add_string(list_item, "REMARKS", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
							TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

							TRS.add_string(list_item, "MC_NAME", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
							TRS.add_string(list_item, "ITEM_NAME110", MWIPMATDEF_BOM.MAT_DESC, sizeof(MWIPMATDEF_BOM.MAT_DESC));
							TRS.add_double(list_item, "TOTAL_QUANTITY", CWIPORDBOM.UNIT_QTY);
							TRS.add_string(list_item, "ITEM_UOM", CWIPORDBOM.UNIT, sizeof(CWIPORDBOM.UNIT));
							TRS.add_double(list_item, "ITEM_QTY", CWIPORDBOM.QTY);
							TRS.add_string(list_item, "NAME110", MWIPOPRDEF_OUT.OPER_DESC, sizeof(MWIPOPRDEF_OUT.OPER_DESC));
							TRS.add_double(list_item, "GOOD_QTY", MWIPLOTSTSX.QTY_1);
							TRS.add_double(list_item, "LOSS_QTY", MWIPLOTLOS.LOSS_QTY_1);
						}


					}
					else
					{
						list_item = TRS.add_node(out_node, "LABEL_LIST");

						TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_int(list_item, "SEQ_NUM", MWIPFLWOPR.SEQ_NUM);
						TRS.add_string(list_item, "OP_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
						TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
						TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
						TRS.add_string(list_item, "WIP_ENTITY_NAME", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_string(list_item, "JOB_DATE", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
						TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
						TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
						TRS.add_double(list_item, "PLAN_QTY", MWIPORDSTS.ORD_QTY);
						TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
						TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						// TRS.add_string(list_item, "REMARKS", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
						TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
						TRS.add_string(list_item, "MC_NAME", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
					}
				}
			}
		}
	}
	// T-CARD(Mutil)
	else if (TRS.get_procstep(in_node) == '7')
	{
		group_list = TRS.get_list(in_node, "GROUP_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "GROUP_LIST"); i++)
		{
			i_step = 4;
			i_lot_count = 0;

			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1), group_list[i], "GROUP_ID");

			DBU_open_mwiplotstsx(i_step, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_1), MWIPLOTSTSX.LOT_CMF_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_mwiplotstsx(i_step, &MWIPLOTSTSX);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_mwiplotstsx(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_1), MWIPLOTSTSX.LOT_CMF_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_mwiplotstsx(i_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (i_lot_count == 0)
				{
					//MWIPORDSTS -작업지시 조회
					DBU_init_mwipordsts(&MWIPORDSTS);
					memcpy(MWIPORDSTS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPORDSTS.FACTORY));
					memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

					DBU_select_mwipordsts(1, &MWIPORDSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
						strcpy(s_msg_code, "ORD-0018");
						TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_mwiplotstsx(i_step);
						//

						return MP_FALSE;
					}

					//사업부 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
					memcpy(MGCMTBLDAT_AREA.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
					memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
					memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

					//작업장 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT);
					memcpy(MGCMTBLDAT.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
					memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
					memcpy(MGCMTBLDAT.KEY_1, MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

					//완료 창고 조회
					DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
					memcpy(MWIPOPRDEF_WH.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
					memcpy(MWIPOPRDEF_WH.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_WH.OPER));

					DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
					if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0590 : 이 창고는 존재하지 않습니다.
						strcpy(s_msg_code, "WIP-0590");
						TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_mwiplotstsx(i_step);
						//

						return MP_FALSE;
					}

					//품목 조회
					DBU_init_mwipmatdef(&MWIPMATDEF);
					memcpy(MWIPMATDEF.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
					memcpy(MWIPMATDEF.MAT_ID, MWIPORDSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					MWIPMATDEF.MAT_VER = MWIPORDSTS.MAT_VER;
					DBU_select_mwipmatdef(1, &MWIPMATDEF);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0006");
						TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_LOT.FACTORY), MWIPMATDEF_LOT.FACTORY);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_LOT.MAT_ID), MWIPMATDEF_LOT.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_mwiplotstsx(i_step);
						//

						return MP_FALSE;
					}
				}

				//품목 조회
				DBU_init_mwipmatdef(&MWIPMATDEF_LOT);
				memcpy(MWIPMATDEF_LOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF_LOT.FACTORY));
				memcpy(MWIPMATDEF_LOT.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF_LOT.MAT_ID));
				MWIPMATDEF_LOT.MAT_VER = MWIPLOTSTSX.MAT_VER;
				DBU_select_mwipmatdef(1, &MWIPMATDEF_LOT);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_LOT.FACTORY), MWIPMATDEF_LOT.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_LOT.MAT_ID), MWIPMATDEF_LOT.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					// 20.12.21 minjae.go
					DBU_close_mwiplotstsx(i_step);
					//

					return MP_FALSE;
				}

				i_lot_count++;
				list_item = TRS.add_node(out_node, "LABEL_LIST");
				TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
				TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
				TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				TRS.add_string(list_item, "WO_NO", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				TRS.add_double(list_item, "LOT_QTY", MWIPORDSTS.ORD_QTY);
				TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
				TRS.add_int(list_item, "NO", atoi(MWIPLOTSTSX.LOT_CMF_2));
				TRS.add_string(list_item, "ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_string(list_item, "ITEM_NAME110", MWIPMATDEF_LOT.MAT_DESC, sizeof(MWIPMATDEF_LOT.MAT_DESC));
				TRS.add_string(list_item, "LOT_NO", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF_LOT.UNIT_1, sizeof(MWIPMATDEF_LOT.UNIT_1));
				TRS.add_double(list_item, "ITEM_QTY", MWIPLOTSTSX.QTY_1);
			}
		}
	}
	// 창고이동 출고증
	else if (TRS.get_procstep(in_node) == '8')
	{
		//MWIPLOTMVM -이동지시 마스터 조회
		DBU_init_cwiplotmvm(&CWIPLOTMVM);
		TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), in_node, "MOVE_ID");

		DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0018");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVM SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//출고 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
		memcpy(MWIPOPRDEF.OPER, CWIPLOTMVM.FROM_OPER, sizeof(MWIPOPRDEF.OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 입고 창고
		DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
		memcpy(MWIPOPRDEF_WH.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
		memcpy(MWIPOPRDEF_WH.OPER, CWIPLOTMVM.TO_OPER, sizeof(MWIPOPRDEF_WH.OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//사업부 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
		memcpy(MGCMTBLDAT_AREA.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
		memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_AREA.KEY_1, CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

		list_item = TRS.add_node(out_node, "LABEL_LIST");
		TRS.add_string(list_item, "TRANS_SEQ", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		TRS.add_string(list_item, "TRANS_SEQ2", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
		TRS.add_string(list_item, "REG_DATE", CWIPLOTMVM.CREATE_TIME, sizeof(CWIPLOTMVM.CREATE_TIME));
		TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
		TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));

		i_step = 2;
		DBU_init_cwiplotmvc(&CWIPLOTMVC);
		memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVC.FACTORY));
		memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVC.MOVE_ID));

		DBU_open_cwiplotmvc(i_step, &CWIPLOTMVC);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTMVC OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cwiplotmvc(i_step, &CWIPLOTMVC);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwiplotmvc(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVC FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cwiplotmvc(i_step);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MWIPLOTSTSX 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cwiplotmvc(i_step);
				//

				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_cwiplotmvc(i_step);
				//

				return MP_FALSE;
			}

			i_lot_count++;

			if (TRS.get_char(in_node, "LABEL_TYPE") == 'D')
			{
				if (i_lot_count != 1)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
				}

				TRS.add_string(list_item, "TRANS_SEQ", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
				TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
				TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				TRS.add_int(list_item, "NO", i_lot_count);
				TRS.add_string(list_item, "ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(list_item, "LOT_NO", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
				TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(list_item, "LOT_QTY", CWIPLOTMVC.QTY);
			}
			else
			{
				row_num = i_lot_count % 6;

				if (row_num == 1 && i_lot_count != 1)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "TRANS_SEQ", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
					TRS.add_string(list_item, "TRANS_SEQ2", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
					TRS.add_string(list_item, "REG_DATE", CWIPLOTMVM.CREATE_TIME, sizeof(CWIPLOTMVM.CREATE_TIME));
					TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				}

				switch (row_num)
				{
				case 1:
					TRS.add_string(list_item, "ITEM_CODE1", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME1", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO1", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY1", CWIPLOTMVC.QTY);
					break;

				case 2:
					TRS.add_string(list_item, "ITEM_CODE2", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO2", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM2", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY2", CWIPLOTMVC.QTY);
					break;

				case 3:
					TRS.add_string(list_item, "ITEM_CODE3", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME3", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO3", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM3", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY3", CWIPLOTMVC.QTY);
					break;

				case 4:
					TRS.add_string(list_item, "ITEM_CODE4", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME4", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO4", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM4", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY4", CWIPLOTMVC.QTY);
					break;

				case 5:
					TRS.add_string(list_item, "ITEM_CODE5", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME5", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO5", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM5", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY5", CWIPLOTMVC.QTY);
					break;

				case 0:
					TRS.add_string(list_item, "ITEM_CODE6", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME6", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO6", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
					TRS.add_string(list_item, "UOM6", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY6", CWIPLOTMVC.QTY);
					break;
				}
			}
		}
	}
	// 입하 라벨
	else if (TRS.get_procstep(in_node) == '9')
	{
		inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
		{
			//입하 LOT 조회
			DBU_init_minvdlvlot(&MINVDLVLOT);
			TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), inv_lot_list[i], "DLV_LOT_ID");

			DBU_select_minvdlvlot(1, &MINVDLVLOT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MINVDLVLOT.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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
			memcpy(MINVDLVMST.FACTORY, MINVDLVLOT.FACTORY, sizeof(MINVDLVMST.FACTORY));
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

			//협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVDLVMST.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "ITEM_CODE", MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "INPUT_DATE", MINVDLVLOT.DLV_TIME, sizeof(MINVDLVLOT.DLV_TIME));
			TRS.add_double(list_item, "LOT_QTY", MINVDLVLOT.QTY);
			TRS.add_string(list_item, "UOM", MINVDLVLOT.UNIT, sizeof(MINVDLVLOT.UNIT));
			TRS.add_string(list_item, "VENDOR_NAME", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			TRS.add_string(list_item, "SUPPLIER_LOT_ID", MINVDLVLOT.VENDOR_LOT_ID, sizeof(MINVDLVLOT.VENDOR_LOT_ID));
			TRS.add_string(list_item, "LOT_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
		}
	}
	//step R 반품 후 공정 라벨
	else if (TRS.get_procstep(in_node) == 'R')
	{
		lot_list = TRS.get_list(in_node, "MOVE_LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "MOVE_LOT_LIST"); i++)
		{
			// CPAKLOTSTS - 포장 정보 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), lot_list[i], "ORG_LOT_ID");
			TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_cpaklotsts(1, &CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MWIPLOTSTSX 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.FACTORY, CPAKLOTSTS.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(MWIPLOTSTSX.LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "MAIN_LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
			TRS.add_string(list_item, "ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
		}
	}
	//step B BOX 포장 출하 라벨
	else if (TRS.get_procstep(in_node) == 'B')
	{
		box_list = TRS.get_list(in_node, "BOX_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "BOX_LIST"); i++)
		{
			// CPAKLOTSTS - 포장 정보 조회
			DBU_init_cpaklotsts(&CPAKLOTSTS);
			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), box_list[i], "BOX_ID");
			i_step = 4;

			DBU_select_cpaklotsts(i_step, &CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, CPAKLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			memset(s_label_type, 0x00, sizeof(s_label_type));
			memset(qr_data, 0x00, sizeof(qr_data));

			// 포장 지시 정보 조회
			DBU_init_cpakordsts(&CPAKORDSTS);
			memcpy(CPAKORDSTS.FACTORY, CPAKLOTSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY));
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;

			DBU_select_cpakordsts(1, &CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT ", DT_NOVALUESTRING);
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

			//LABEL TYPE이 비어있는 경우, GRADE
			if (CPAKORDSTS.LABEL_TYPE[0] == ' ')
			{
				memcpy(s_label_type, MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			}
			else
			{
				memcpy(s_label_type, CPAKORDSTS.LABEL_TYPE, sizeof(s_label_type));
			}

			//CTM
			if (memcmp(CPAKORDSTS.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				TRS.add_string(list_item, "ITEM_NAME", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
			}
			// GRIT 
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
			{
				if (CPAKLOTSTS.CMF_1[0] == ' ')
				{
					COM_memcpy(qr_data, "", sizeof(qr_data));
				}
				else
				{
					COM_memcpy(qr_data, CPAKLOTSTS.CMF_1, sizeof(qr_data));
				}

				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "COAT", CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
				TRS.add_string(list_item, "QR_DATA", qr_data, sizeof(qr_data));
				TRS.add_string(list_item, "DRAWING_FLAG", CPAKORDSTS.DRAWING_FLAG, sizeof(CPAKORDSTS.DRAWING_FLAG));

				//LABEL MESH가 비어있는 경우, SIZE
				if (CPAKORDSTS.LABEL_MESH[0] == ' ')
				{
					TRS.add_string(list_item, "TYPE", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				}
				else
				{
					TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				}

				//CUSTOMER PART NO
				TRS.add_string(list_item, "LINE_DESC", CPAKORDSTS.LINE_DESC, sizeof(CPAKORDSTS.LINE_DESC));
			}
			//HM
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "SPEC", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
				TRS.add_int(list_item, "BOX_COUNT", 1);
				TRS.add_string(list_item, "ITEM_NAME1", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
			}
			//PDC
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_PDC, strlen(MP_AREA_PDC)) == 0)
			{
				//LABEL MESH가 비어있는 경우, SIZE
				if (CPAKORDSTS.LABEL_MESH[0] == ' ')
				{
					TRS.add_string(list_item, "TYPE", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				}
				else
				{
					TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				}
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
			}

			TRS.add_string(list_item, "PO_NUMBER", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			TRS.add_string(list_item, "LOT_ID", CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
			TRS.add_string(list_item, "ITEM_CODE", CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_double(list_item, "LOT_QTY", CPAKLOTSTS.QTY);
		}
	}
	//step C 대 BOX 포장 출하 라벨 
	else if (TRS.get_procstep(in_node) == 'C')
	{
		// CPAKLOTSTS - 포장 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), in_node, "FINAL_BOX_ID");
		i_step = 5;

		DBU_select_cpaklotsts(i_step, &CPAKLOTSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//품목 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, CPAKLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;

		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		list_item = TRS.add_node(out_node, "LABEL_LIST");

		TRS.add_string(list_item, "LOT_ID", CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
		TRS.add_string(list_item, "ITEM_CODE", CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
		TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
		TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
		TRS.add_double(list_item, "LOT_QTY", CPAKLOTSTS.QTY);
	}
	//step D 반품 후 출하 라벨
	else if (TRS.get_procstep(in_node) == 'D')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (i = 0; i < i_lot_count; i++)
		{
			memset(s_label_type, 0x00, sizeof(s_label_type));
			memset(qr_data, 0x00, sizeof(qr_data));

			DBU_init_cretlotsts(&CRETLOTSTS);
			TRS.copy(CRETLOTSTS.FACTORY, sizeof(CRETLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CRETLOTSTS.LOT_ID, sizeof(CRETLOTSTS.LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_cretlotsts(2, &CRETLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CRETLOTSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRETLOTSTS.FACTORY), CRETLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CRETLOTSTS.LOT_ID), CRETLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			memcpy(CPAKLOTSTS.FACTORY, CRETLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY));
			memcpy(CPAKLOTSTS.PACK_LOT_ID, CRETLOTSTS.RET_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));

			DBU_select_cpaklotsts(3, &CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, CPAKLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKLOTSTS.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 포장 지시 정보 조회
			DBU_init_cpakordsts(&CPAKORDSTS);
			memcpy(CPAKORDSTS.FACTORY, CPAKLOTSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY));
			memcpy(CPAKORDSTS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CPAKLOTSTS.PACK_LINE_NO;

			DBU_select_cpakordsts(1, &CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT ", DT_NOVALUESTRING);
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

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			//LABEL TYPE이 비어있는 경우, GRADE
			if (CPAKORDSTS.LABEL_TYPE[0] == ' ')
			{
				memcpy(s_label_type, MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			}
			else
			{
				memcpy(s_label_type, CPAKORDSTS.LABEL_TYPE, sizeof(s_label_type));
			}

			//CTM
			if (memcmp(CPAKORDSTS.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				TRS.add_string(list_item, "ITEM_NAME", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
			}
			// GRIT 
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
			{
				if (CPAKLOTSTS.CMF_1[0] == ' ')
				{
					COM_memcpy(qr_data, "", sizeof(qr_data));
				}
				else
				{
					COM_memcpy(qr_data, CPAKLOTSTS.CMF_1, sizeof(qr_data));
				}

				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "COAT", CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
				TRS.add_string(list_item, "QR_DATA", qr_data, sizeof(qr_data));
				TRS.add_string(list_item, "DRAWING_FLAG", CPAKORDSTS.DRAWING_FLAG, sizeof(CPAKORDSTS.DRAWING_FLAG));

				//LABEL MESH가 비어있는 경우, SIZE
				if (CPAKORDSTS.LABEL_MESH[0] == ' ')
				{
					TRS.add_string(list_item, "TYPE", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				}
				else
				{
					TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				}

				//CUSTOMER PART NO
				TRS.add_string(list_item, "LINE_DESC", CPAKORDSTS.LINE_DESC, sizeof(CPAKORDSTS.LINE_DESC));
			}
			//HM
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
			{
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "SPEC", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
				TRS.add_int(list_item, "BOX_COUNT", i_lot_count);
				TRS.add_string(list_item, "ITEM_NAME1", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
			}
			//PDC
			else if (memcmp(CPAKORDSTS.AREA_ID, MP_AREA_PDC, strlen(MP_AREA_PDC)) == 0)
			{
				//LABEL MESH가 비어있는 경우, SIZE
				if (CPAKORDSTS.LABEL_MESH[0] == ' ')
				{
					TRS.add_string(list_item, "TYPE", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				}
				else
				{
					TRS.add_string(list_item, "TYPE", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
					TRS.add_string(list_item, "ITEM_NAME2", CPAKORDSTS.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));
				}
				TRS.add_string(list_item, "GRADE", s_label_type, sizeof(s_label_type));
				TRS.add_string(list_item, "ITEM_NAME", s_label_type, sizeof(s_label_type));
			}

			TRS.add_string(list_item, "LOT_ID", CRETLOTSTS.LOT_ID, sizeof(CRETLOTSTS.LOT_ID));
			TRS.add_double(list_item, "LOT_QTY", CRETLOTSTS.QTY);
			TRS.add_string(list_item, "ITEM", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "ITEM_UOM", CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
			TRS.add_string(list_item, "PO_NUMBER", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			TRS.add_string(list_item, "MN_NO", CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
		}
	}
	//step E 포장 취소 출하라벨 발행
	else if (TRS.get_procstep(in_node) == 'E')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (i = 0; i < i_lot_count; i++)
		{
			//LOT정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_LOT.FACTORY), MWIPMATDEF_LOT.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_LOT.MAT_ID), MWIPMATDEF_LOT.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_int(list_item, "BOX_COUNT", i_lot_count);
			TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
			TRS.add_string(list_item, "ITEM", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_string(list_item, "GRADE", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "TYPE", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
		}
	}
	//step F BLENDING T-CARD
	else if (TRS.get_procstep(in_node) == 'F')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

		for (i = 0; i < i_lot_count; i++)
		{
			// LOT 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), lot_list[i], "LOT_ID");

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// ORDER ID가 없는 경우 T-CARD 발행 불가
			if (COM_isnullspace(MWIPLOTSTSX.ORDER_ID) == MP_TRUE)
			{
				strcpy(s_msg_code, "WIP-0001");
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				return MP_FALSE;
			}

			//작업지시 조회
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//사업부 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			memcpy(MGCMTBLDAT_AREA.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPORDSTS.ORD_CMF_1, sizeof(MWIPORDSTS.ORD_CMF_1));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

			//작업장 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			memcpy(MGCMTBLDAT.FACTORY, MWIPORDSTS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			//완료 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
			memcpy(MWIPOPRDEF_WH.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
			memcpy(MWIPOPRDEF_WH.OPER, MWIPORDSTS.ORD_CMF_3, sizeof(MWIPOPRDEF_WH.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//설비 조회
			DBU_init_mrasresdef(&MRASRESDEF);
			memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));

			if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
			{
				memcpy(MRASRESDEF.RES_ID, MWIPLOTSTSX.END_RES_ID, sizeof(MRASRESDEF.RES_ID));
			}
			else
			{
				memcpy(MRASRESDEF.RES_ID, MWIPLOTSTSX.START_RES_ID, sizeof(MRASRESDEF.RES_ID));
			}

			DBU_select_mrasresdef(1, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//RAS-0003 : 존재하지 않는 장비입니다.
				strcpy(s_msg_code, "RAS-0003");
				TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//FLOW조회
			l_step = 2;
			DBU_init_mwipflwopr(&MWIPFLWOPR);
			memcpy(MWIPFLWOPR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
			memcpy(MWIPFLWOPR.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));

			DBU_open_mwipflwopr(l_step, &MWIPFLWOPR);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0012 : 이 FLOW는 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0012");
				TRS.add_fieldmsg(out_node, "MWIPFLWOPR OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_mwipflwopr(l_step, &MWIPFLWOPR);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_mwipflwopr(l_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "MWIPFLWOPR FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_mwipflwopr(l_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//공정 조회
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				memcpy(MWIPOPRDEF.FACTORY, MWIPFLWOPR.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
				memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);

				//SEQ_NUM=1인 경우, CWIPGRTBLD조회
				if (MWIPFLWOPR.SEQ_NUM == 1)
				{
					i_step = 2;

					DBU_init_cwipgrtbld(&CWIPGRTBLD);
					memcpy(CWIPGRTBLD.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPGRTBLD.FACTORY));
					memcpy(CWIPGRTBLD.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPGRTBLD.ORDER_ID));

					DBU_open_cwipgrtbld(i_step, &CWIPGRTBLD);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRTBLD OPEN", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTBLD.FACTORY), CWIPGRTBLD.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPGRTBLD.ORDER_ID), CWIPGRTBLD.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPGRTBLD.OPER), CWIPGRTBLD.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

						// 20.12.21 minjae.go
						DBU_close_mwipflwopr(l_step);
						//
						return MP_FALSE;
					}

					while (1)
					{
						DBU_fetch_cwipgrtbld(i_step, &CWIPGRTBLD);
						if (DB_error_code == DB_NOT_FOUND)
						{
							DBU_close_cwipgrtbld(i_step);
							break;
						}
						else if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRTBLD FETCH", MP_NVST);
							TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTBLD.FACTORY), CWIPGRTBLD.FACTORY);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPGRTBLD.ORDER_ID), CWIPGRTBLD.ORDER_ID);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPGRTBLD.OPER), CWIPGRTBLD.OPER);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

							// 20.12.21 minjae.go
							DBU_close_cwipgrtbld(i_step);
							DBU_close_mwipflwopr(l_step);
							//

							return MP_FALSE;
						}

						//초기화
						memset(s_lot_id, 0x00, sizeof(s_lot_id));
						memset(s_mat_id, 0x00, sizeof(s_mat_id));
						mat_ver = 0;

						//LOT 조회
						DBU_init_mwiplotstsx(&MWIPLOTSTSX_ITEM);
						TRS.copy(MWIPLOTSTSX_ITEM.FACTORY, sizeof(MWIPLOTSTSX_ITEM.FACTORY), in_node, IN_FACTORY);
						memcpy(MWIPLOTSTSX_ITEM.LOT_ID, CWIPGRTBLD.LOT_ID, sizeof(MWIPLOTSTSX_ITEM.LOT_ID));

						DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_ITEM);
						if (DB_error_code != DB_SUCCESS)
						{
							//WMIPLOTSTS 없는 경우, MINVLOTSTS 조회
							if (DB_error_code == DB_NOT_FOUND)
							{
								DBU_init_minvlotsts(&MINVLOTSTS);
								TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
								memcpy(MINVLOTSTS.INV_LOT_ID, CWIPGRTBLD.LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));

								DBU_select_minvlotsts(1, &MINVLOTSTS);
								if (DB_error_code != DB_SUCCESS)
								{
									strcpy(s_msg_code, "INV-0004");
									TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
									TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
									TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_TRANS;
									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

									// 20.12.21 minjae.go
									DBU_close_cwipgrtbld(i_step);
									DBU_close_mwipflwopr(l_step);
									//

									return MP_FALSE;
								}

								memcpy(s_lot_id, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
								memcpy(s_mat_id, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
								mat_ver = MINVLOTSTS.MAT_VER;
							}
							else
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_ITEM.LOT_ID), MWIPLOTSTSX_ITEM.LOT_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

								// 20.12.21 minjae.go
								DBU_close_cwipgrtbld(i_step);
								DBU_close_mwipflwopr(l_step);
								//

								return MP_FALSE;
							}
						}

						if (s_lot_id[0] == 0)
						{
							memcpy(s_lot_id, MWIPLOTSTSX_ITEM.LOT_ID, sizeof(MWIPLOTSTSX_ITEM.LOT_ID));
							memcpy(s_mat_id, MWIPLOTSTSX_ITEM.MAT_ID, sizeof(MWIPLOTSTSX_ITEM.MAT_ID));
							mat_ver = MWIPLOTSTSX_ITEM.MAT_VER;
						}

						//제품 조회
						DBU_init_mwipmatdef(&MWIPMATDEF_BOM);
						memcpy(MWIPMATDEF_BOM.FACTORY, CWIPGRTBLD.FACTORY, sizeof(MWIPMATDEF_BOM.FACTORY));
						memcpy(MWIPMATDEF_BOM.MAT_ID, s_mat_id, sizeof(MWIPMATDEF_BOM.MAT_ID));
						MWIPMATDEF_BOM.MAT_VER = mat_ver;

						DBU_select_mwipmatdef(1, &MWIPMATDEF_BOM);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0006");
							TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(2) ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_BOM.FACTORY), MWIPMATDEF_BOM.FACTORY);
							TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_BOM.MAT_ID), MWIPMATDEF_BOM.MAT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

							// 20.12.21 minjae.go
							DBU_close_cwipgrtbld(i_step);
							DBU_close_mwipflwopr(l_step);
							//

							return MP_FALSE;
						}


						//출고 창고 조회
						DBU_init_mwipoprdef(&MWIPOPRDEF_OUT);
						memcpy(MWIPOPRDEF_OUT.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPOPRDEF_OUT.FACTORY));
						memcpy(MWIPOPRDEF_OUT.OPER, CWIPGRTBLD.OPER, sizeof(MWIPOPRDEF_OUT.OPER));

						DBU_select_mwipoprdef(1, &MWIPOPRDEF_OUT);
						if (DB_error_code != DB_SUCCESS)
						{
							//WIP-0590 : 이 창고는 존재하지 않습니다.
							strcpy(s_msg_code, "WIP-0590");
							TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_OUT.FACTORY), MWIPOPRDEF_OUT.FACTORY);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_OUT.OPER), MWIPOPRDEF_OUT.OPER);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

							// 20.12.21 minjae.go
							DBU_close_cwipgrtbld(i_step);
							DBU_close_mwipflwopr(l_step);
							//

							return MP_FALSE;
						}

						// 불량수량 조회
						DBU_init_mwiplotlos(&MWIPLOTLOS);
						memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTLOS.LOT_ID));
						memcpy(MWIPLOTLOS.OPER, CWIPGRTBLD.OPER, sizeof(MWIPLOTLOS.OPER));

						DBU_select_mwiplotlos(2, &MWIPLOTLOS);
						if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "MWIPLOTLOS SELECT ", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTLOS.LOT_ID), MWIPLOTLOS.LOT_ID);
							TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTLOS.OPER), MWIPLOTLOS.OPER);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_TRANS;
							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

							// 20.12.21 minjae.go
							DBU_close_cwipgrtbld(i_step);
							DBU_close_mwipflwopr(l_step);
							//

							return MP_FALSE;
						}

						list_item = TRS.add_node(out_node, "LABEL_LIST");

						TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_int(list_item, "SEQ_NUM", MWIPFLWOPR.SEQ_NUM);
						TRS.add_string(list_item, "OP_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
						TRS.add_double(list_item, "LOT_QTY", MWIPORDSTS.ORD_QTY);
						TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
						TRS.add_string(list_item, "WIP_ENTITY_NAME", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
						TRS.add_string(list_item, "JOB_DATE", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
						TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
						TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
						TRS.add_double(list_item, "PLAN_QTY", MWIPORDSTS.ORD_QTY);
						TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
						TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
						TRS.add_string(list_item, "REMARKS", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
						TRS.add_string(list_item, "MC_NAME", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
						TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));
						TRS.add_string(list_item, "LOT_ID", CWIPGRTBLD.LOT_ID, sizeof(CWIPGRTBLD.LOT_ID));
						TRS.add_string(list_item, "ITEM_NAME110", MWIPMATDEF_BOM.MAT_DESC, sizeof(MWIPMATDEF_BOM.MAT_DESC));
						TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF_BOM.UNIT_1, sizeof(MWIPMATDEF_BOM.UNIT_1));
						TRS.add_double(list_item, "ITEM_QTY", CWIPGRTBLD.QTY_1);
						TRS.add_string(list_item, "NAME110", MWIPOPRDEF_OUT.OPER_DESC, sizeof(MWIPOPRDEF_OUT.OPER_DESC));
						TRS.add_double(list_item, "GOOD_QTY", MWIPLOTSTSX.QTY_1);
						TRS.add_double(list_item, "LOSS_QTY", MWIPLOTLOS.LOSS_QTY_1);
					}
				}
				else
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");

					TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_int(list_item, "SEQ_NUM", MWIPFLWOPR.SEQ_NUM);
					TRS.add_string(list_item, "OP_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_double(list_item, "LOT_QTY", MWIPORDSTS.ORD_QTY);
					TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
					TRS.add_string(list_item, "WIP_ENTITY_NAME", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					TRS.add_string(list_item, "JOB_DATE", MWIPORDSTS.PLAN_START_TIME, sizeof(MWIPORDSTS.PLAN_START_TIME));
					TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "NAME", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
					TRS.add_double(list_item, "PLAN_QTY", MWIPORDSTS.ORD_QTY);
					TRS.add_string(list_item, "WC_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
					TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_string(list_item, "REMARKS", MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC));
					TRS.add_string(list_item, "MC_NAME", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
				}
			}
		}

	}
	//수기 라벨
	else if (TRS.get_procstep(in_node) == 'L')
	{
		lot_list = TRS.get_list(in_node, "LABEL_LIST");
		i_lot_count = TRS.get_item_count(in_node, "LABEL_LIST");

		for (i = 0; i < i_lot_count; i++)
		{
			DBU_init_cbaslbldat(&CBASLBLDAT);
			TRS.copy(CBASLBLDAT.FACTORY, sizeof(CBASLBLDAT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CBASLBLDAT.AREA_ID, sizeof(CBASLBLDAT.AREA_ID), in_node, "AREA_ID");
			TRS.copy(CBASLBLDAT.FILE_NAME, sizeof(CBASLBLDAT.FILE_NAME), in_node, "FILE_NAME");
			CBASLBLDAT.SEQ = TRS.get_int(lot_list[i], "SEQ");

			DBU_select_cbaslbldat(1, &CBASLBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CBASLBLDAT SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASLBLDAT.FACTORY), CBASLBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASLBLDAT.AREA_ID), CBASLBLDAT.AREA_ID);
				TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASLBLDAT.FILE_NAME), CBASLBLDAT.FILE_NAME);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASLBLDAT.SEQ);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");
			TRS.add_string(list_item, "LOT_ID", CBASLBLDAT.LOT_ID, sizeof(CBASLBLDAT.LOT_ID));
			TRS.add_string(list_item, "ITEM_CODE", CBASLBLDAT.ITEM_CODE, sizeof(CBASLBLDAT.ITEM_CODE));
			TRS.add_string(list_item, "ITEM_NAME", CBASLBLDAT.ITEM_NAME, sizeof(CBASLBLDAT.ITEM_NAME));
			TRS.add_string(list_item, "INPUT_DATE", CBASLBLDAT.INPUT_DATE, sizeof(CBASLBLDAT.INPUT_DATE));
			TRS.add_double(list_item, "LOT_QTY", CBASLBLDAT.LOT_QTY);
			TRS.add_string(list_item, "UOM", CBASLBLDAT.UOM, sizeof(CBASLBLDAT.UOM));
			TRS.add_string(list_item, "VENDOR_NAME", CBASLBLDAT.VENDOR_NAME, sizeof(CBASLBLDAT.VENDOR_NAME));
			TRS.add_string(list_item, "SUPPLIER_LOT_ID", CBASLBLDAT.SUPPLIER_LOT_ID, sizeof(CBASLBLDAT.SUPPLIER_LOT_ID));
			TRS.add_string(list_item, "CELL_NO", CBASLBLDAT.CELL_NO, sizeof(CBASLBLDAT.CELL_NO));
			TRS.add_string(list_item, "WO_NO", CBASLBLDAT.WO_NO, sizeof(CBASLBLDAT.WO_NO));
			TRS.add_string(list_item, "PC0201", CBASLBLDAT.PC0201, sizeof(CBASLBLDAT.PC0201));
			TRS.add_string(list_item, "PC0202", CBASLBLDAT.PC0202, sizeof(CBASLBLDAT.PC0202));
			TRS.add_string(list_item, "PC0203", CBASLBLDAT.PC0203, sizeof(CBASLBLDAT.PC0203));
			TRS.add_string(list_item, "PC0204", CBASLBLDAT.PC0204, sizeof(CBASLBLDAT.PC0204));
			TRS.add_string(list_item, "MAIN_LOT_ID", CBASLBLDAT.MAIN_LOT_ID, sizeof(CBASLBLDAT.MAIN_LOT_ID));
			TRS.add_string(list_item, "GRADE", CBASLBLDAT.GRADE, sizeof(CBASLBLDAT.GRADE));
			TRS.add_string(list_item, "ITEM_UOM", CBASLBLDAT.ITEM_UOM, sizeof(CBASLBLDAT.ITEM_UOM));
			TRS.add_string(list_item, "REMARKS", CBASLBLDAT.REMARKS, sizeof(CBASLBLDAT.REMARKS));
			TRS.add_string(list_item, "GROUP_ID", CBASLBLDAT.GROUP_ID, sizeof(CBASLBLDAT.GROUP_ID));
			TRS.add_string(list_item, "ITEM_NAME1", CBASLBLDAT.ITEM_NAME1, sizeof(CBASLBLDAT.ITEM_NAME1));
			TRS.add_string(list_item, "ITEM_NAME2", CBASLBLDAT.ITEM_NAME2, sizeof(CBASLBLDAT.ITEM_NAME2));
			TRS.add_string(list_item, "TYPE", CBASLBLDAT.TYPE, sizeof(CBASLBLDAT.TYPE));
			TRS.add_string(list_item, "SPEC", CBASLBLDAT.SPEC, sizeof(CBASLBLDAT.SPEC));
			TRS.add_string(list_item, "ITEM", CBASLBLDAT.ITEM, sizeof(CBASLBLDAT.ITEM));
			TRS.add_string(list_item, "PO_NUMBER", CBASLBLDAT.PO_NUMBER, sizeof(CBASLBLDAT.PO_NUMBER));
			TRS.add_string(list_item, "MN_NO", CBASLBLDAT.MN_NO, sizeof(CBASLBLDAT.MN_NO));
			TRS.add_string(list_item, "DRAWING_FLAG", CBASLBLDAT.DRAWING_FLAG, sizeof(CBASLBLDAT.DRAWING_FLAG));
			TRS.add_string(list_item, "COAT", CBASLBLDAT.COAT, sizeof(CBASLBLDAT.COAT));
			TRS.add_int(list_item, "BOX_COUNT", i_lot_count);



			if (CBASLBLDAT.COAT[0] == ' ')
			{
				COM_memcpy(qr_data, "", sizeof(qr_data));
			}
			else
			{
				COM_memcpy(qr_data, CBASLBLDAT.COAT, sizeof(qr_data));
			}
			TRS.add_string(list_item, "QR_DATA", qr_data, sizeof(qr_data));
		}
	}
	//자재 이동
	else if (TRS.get_procstep(in_node) == 'I')
	{
		//MINVMOVSTS -이동지시 마스터 조회
		DBU_init_minvmovsts(&MINVMOVSTS);
		TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "MOVE_ID");

		DBU_select_minvmovsts(1, &MINVMOVSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0018");
			TRS.add_fieldmsg(out_node, "MINVMOVSTS SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//출고 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		memcpy(MWIPOPRDEF.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
		memcpy(MWIPOPRDEF.OPER, MINVMOVSTS.OPER, sizeof(MINVMOVSTS.OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 입고 창고
		DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
		memcpy(MWIPOPRDEF_WH.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
		memcpy(MWIPOPRDEF_WH.OPER, MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));

		DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0590 : 이 창고는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0590");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//사업부 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
		memcpy(MGCMTBLDAT_AREA.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
		memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_AREA.KEY_1, MINVMOVSTS.AREA_ID, sizeof(MINVMOVSTS.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

		list_item = TRS.add_node(out_node, "LABEL_LIST");
		TRS.add_string(list_item, "TRANS_SEQ", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
		TRS.add_string(list_item, "TRANS_SEQ2", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
		TRS.add_string(list_item, "REG_DATE", MINVMOVSTS.CREATE_TIME, sizeof(MINVMOVSTS.CREATE_TIME));
		TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
		TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
		TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));

		i_step = 2;
		DBU_init_minvmovlot(&MINVMOVLOT);
		memcpy(MINVMOVLOT.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
		memcpy(MINVMOVLOT.MOVE_ID, MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));

		DBU_open_minvmovlot(i_step, &MINVMOVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "MINVMOVLOT OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_minvmovlot(i_step, &MINVMOVLOT);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_minvmovlot(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MINVMOVLOT FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_minvmovlot(i_step);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//MWIPLOTSTSX 조회
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTSTS.INV_LOT_ID, MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvmovlot(i_step);
				//

				return MP_FALSE;
			}

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvmovlot(i_step);
				//

				return MP_FALSE;
			}

			i_lot_count++;

			if (TRS.get_char(in_node, "LABEL_TYPE") == 'D')
			{
				if (i_lot_count != 1)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
				}

				TRS.add_string(list_item, "TRANS_SEQ", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
				TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
				TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
				TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				TRS.add_int(list_item, "NO", i_lot_count);
				TRS.add_string(list_item, "ITEM_CODE", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
				TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(list_item, "LOT_NO", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
				TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(list_item, "LOT_QTY", MINVMOVLOT.QTY);
			}
			else
			{
				row_num = i_lot_count % 6;

				if (row_num == 1 && i_lot_count != 1)
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "TRANS_SEQ", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
					TRS.add_string(list_item, "TRANS_SEQ2", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
					TRS.add_string(list_item, "REG_DATE", MINVMOVSTS.CREATE_TIME, sizeof(MINVMOVSTS.CREATE_TIME));
					TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				}

				switch (row_num)
				{
				case 1:
					TRS.add_string(list_item, "ITEM_CODE1", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME1", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO1", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY1", MINVMOVLOT.QTY);
					break;

				case 2:
					TRS.add_string(list_item, "ITEM_CODE2", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO2", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM2", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY2", MINVMOVLOT.QTY);
					break;

				case 3:
					TRS.add_string(list_item, "ITEM_CODE3", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME3", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO3", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM3", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY3", MINVMOVLOT.QTY);
					break;

				case 4:
					TRS.add_string(list_item, "ITEM_CODE4", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME4", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO4", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM4", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY4", MINVMOVLOT.QTY);
					break;

				case 5:
					TRS.add_string(list_item, "ITEM_CODE5", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME5", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO5", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM5", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY5", MINVMOVLOT.QTY);
					break;

				case 0:
					TRS.add_string(list_item, "ITEM_CODE6", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME6", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO6", MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID));
					TRS.add_string(list_item, "UOM6", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY6", MINVMOVLOT.QTY);
					break;
				}
			}
		}
	}
	// KITTING ID
	else if (TRS.get_procstep(in_node) == 'A')
	{
		kitting_list = TRS.get_list(in_node, "KITTING_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "KITTING_LIST"); i++)
		{
			i_lot_count = 0;

			i_step = 8;

			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4), kitting_list[i], "KITTING_ID");
			DBU_open_minvlotsts(i_step, &MINVLOTSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "KITTING_ID", MP_STR, sizeof(MINVLOTSTS.INV_CMF_4), MINVLOTSTS.INV_CMF_4);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_minvlotsts(i_step, &MINVLOTSTS);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_minvlotsts(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					//INV-0043 : 검색하신 정보는 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0043");
					TRS.add_fieldmsg(out_node, "MINVLOTSTS OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "KITTING_ID", MP_STR, sizeof(MINVLOTSTS.INV_CMF_4), MINVLOTSTS.INV_CMF_4);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					// 20.12.21 minjae.go
					DBU_close_minvlotsts(i_step);
					//

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//품목 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
				MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					// 20.12.21 minjae.go
					DBU_close_minvlotsts(i_step);
					//

					return MP_FALSE;
				}

				i_lot_count++;

				if (TRS.get_char(in_node, "LABEL_TYPE") == 'D')
				{
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					if (i_lot_count == 1)
					{
						TRS.add_string(list_item, "TRANS_SEQ2", MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4));
					}

					TRS.add_string(list_item, "TRANS_SEQ", MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4));
					TRS.add_string(list_item, "ORG_CODE", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
					TRS.add_int(list_item, "NO", i_lot_count);
					TRS.add_string(list_item, "ITEM_CODE", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
					TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY", MINVLOTSTS.QTY);
				}
			}
		}
	}
	//이동지시서 
	else if (TRS.get_procstep(in_node) == 'M')
	{
		data_list = TRS.get_list(in_node, "MOVE_LIST");
		i_data_count = TRS.get_item_count(in_node, "MOVE_LIST");

		for (i = 0; i < i_data_count; i++)
		{
			d_y_count = 0;
			d_n_count = 0;

			//MWIPLOTMVM -이동지시 마스터 조회
			DBU_init_cwiplotmvm(&CWIPLOTMVM);
			TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), data_list[i], "MOVE_ID");

			DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0018 : 이 WORK ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0018");
				TRS.add_fieldmsg(out_node, "CWIPLOTMVM SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVM.FACTORY), CWIPLOTMVM.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVM.MOVE_ID), CWIPLOTMVM.MOVE_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//출고 창고 조회
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			memcpy(MWIPOPRDEF.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
			memcpy(MWIPOPRDEF.OPER, CWIPLOTMVM.FROM_OPER, sizeof(MWIPOPRDEF.OPER));

			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF_WH.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF_WH.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 입고 창고
			DBU_init_mwipoprdef(&MWIPOPRDEF_WH);
			memcpy(MWIPOPRDEF_WH.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPOPRDEF_WH.FACTORY));
			memcpy(MWIPOPRDEF_WH.OPER, CWIPLOTMVM.TO_OPER, sizeof(MWIPOPRDEF_WH.OPER));

			DBU_select_mwipoprdef(1, &MWIPOPRDEF_WH);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_WH.FACTORY), MWIPOPRDEF_WH.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_WH.OPER), MWIPOPRDEF_WH.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//사업부 정보 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			memcpy(MGCMTBLDAT_AREA.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT_AREA.KEY_1, CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, CWIPLOTMVM.CMF_2, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			DBU_init_cwipprsrun(&CWIPPRSRUN);

			if (TRS.get_char(in_node, "SPLIT_DAY_WORK") == 'Y')
			{
				l_step = 4;
				memcpy(CWIPPRSRUN.CMF_10, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
			}
			else
			{
				l_step = 3;
			}

			memcpy(CWIPPRSRUN.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPPRSRUN.FACTORY));
			memcpy(CWIPPRSRUN.RES_ID, CWIPLOTMVM.CMF_1, sizeof(CWIPPRSRUN.RES_ID));
			memcpy(CWIPPRSRUN.MAT_ID, CWIPLOTMVM.CMF_2, sizeof(CWIPPRSRUN.MAT_ID));
			memcpy(CWIPPRSRUN.WORK_DATE, CWIPLOTMVM.CMF_3, sizeof(CWIPPRSRUN.WORK_DATE));

			DBU_open_cwipprsrun(l_step, &CWIPPRSRUN);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPPRSRUN OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
				TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			while (1)
			{

				DBU_fetch_cwipprsrun(l_step, &CWIPPRSRUN);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_cwipprsrun(l_step);
					break;
				}

				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRSRUN FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
					TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cwipprsrun(l_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (CWIPPRSRUN.LOSS_YN == 'Y')
				{
					remark = 'X';
					d_y_count++;
					count = 0;
				}
				else
				{
					remark = 'O';
					d_n_count++;
					count = 1;
				}


				// PRESS 비고정보 조회
				DBU_init_mwiplothisx(&MWIPLOTHIS_ORGLOT);
				memcpy(MWIPLOTHIS_ORGLOT.LOT_ID, CWIPPRSRUN.ORG_LOT_ID, sizeof(MWIPLOTHIS_ORGLOT.LOT_ID));
				MWIPLOTHIS_ORGLOT.HIST_SEQ = CWIPPRSRUN.ORG_LOT_HIST_SEQ;
				DBU_select_mwiplothisx(1, &MWIPLOTHIS_ORGLOT);



				DBU_init_mrasresdef(&MRASRESDEF);
				memcpy(MRASRESDEF.FACTORY, CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY));
				memcpy(MRASRESDEF.RES_ID, CWIPPRSRUN.RES_ID, sizeof(CWIPPRSRUN.RES_ID));

				DBU_select_mrasresdef(1, &MRASRESDEF);
				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					/*
					//RAS-0003 : 존재하지 않는 장비입니다.
					strcpy(s_msg_code, "RAS-0003");
					TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT ", DT_NOVALUESTRING);
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


				MWIPLOTHIS_ORGLOT.TRAN_COMMENT;

				list_item = TRS.add_node(out_node, "LABEL_LIST");
				TRS.add_string(list_item, "TRANS_SEQ", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
				TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
				TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
				TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
				TRS.add_int(list_item, "NO", CWIPPRSRUN.MAPPING_SEQ);
				TRS.add_string(list_item, "ITEM_CODE", CWIPPRSRUN.MAT_ID, sizeof(CWIPPRSRUN.MAT_ID));
				TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(list_item, "LOT_NO", CWIPPRSRUN.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
				TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
				TRS.add_double(list_item, "LOT_QTY", count);
				TRS.add_char(list_item, "REMARKS", remark);



				if (COM_isnullspace(TRS.get_string(in_node, "REMARKS2")) == MP_TRUE)
				{
					TRS.add_string(list_item, "REMARKS2", MWIPLOTHIS_ORGLOT.TRAN_COMMENT, sizeof(MWIPLOTHIS_ORGLOT.TRAN_COMMENT));
				}
				else
				{
					TRS.add_nstring(list_item, "REMARKS2", TRS.get_string(in_node, "REMARKS2"));
				}




				//TRS.add_string(list_item, "REMARKS2", MWIPLOTHIS_ORGLOT.TRAN_COMMENT,sizeof(MWIPLOTHIS_ORGLOT.TRAN_COMMENT));
				//TRS.add_nstring(list_item, "REMARKS2", TRS.get_string(in_node, "REMARKS2"));
				TRS.add_double(list_item, "TOTAL_QTY", d_n_count);

				TRS.add_string(list_item, "SUMMARY_ITEM_CODE", CWIPPRSRUN.MAT_ID, sizeof(CWIPPRSRUN.MAT_ID));
				TRS.add_string(list_item, "SUMMARY_ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_double(list_item, "SUMMARY_ITEM_QTY", d_n_count);
				TRS.add_char(list_item, "SUMMARY_REMARKS", 'O');
				TRS.add_string(list_item, "SUMMARY_ITEM_CODE2", CWIPPRSRUN.MAT_ID, sizeof(CWIPPRSRUN.MAT_ID));
				TRS.add_string(list_item, "SUMMARY_ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_double(list_item, "SUMMARY_ITEM_QTY2", d_y_count);
				TRS.add_char(list_item, "SUMMARY_REMARKS2", 'X');


			}



			/*
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.FACTORY, CWIPLOTMVM.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(MWIPLOTSTSX.LOT_CMF_1, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVC.MOVE_ID));

			i_step = 6;
			DBU_open_mwiplotstsx(i_step, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
				TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_1), MWIPLOTSTSX.LOT_CMF_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			while (1)
			{
				DBU_fetch_mwiplotstsx(i_step, &MWIPLOTSTSX);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_mwiplotstsx(i_step);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "MWIPLOTSTSX FETCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
					TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_CMF_1), MWIPLOTSTSX.LOT_CMF_1);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_mwiplotstsx(i_step);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//품목 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
				memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;

				DBU_select_mwipmatdef(1, &MWIPMATDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				DBU_init_cwipprsrun(&CWIPPRSRUN);
				memcpy(CWIPPRSRUN.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPPRSRUN.FACTORY));
				memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));

				l_step = 2;
				DBU_open_cwipprsrun(l_step, &CWIPPRSRUN);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRSRUN OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
					TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				while (1)
				{
					DBU_fetch_cwipprsrun(l_step, &CWIPPRSRUN);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cwipprsrun(l_step);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPPRSRUN FETCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, l_step);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
						TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_cwipprsrun(l_step);
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					if (CWIPPRSRUN.LOSS_YN == 'Y')
					{
						remark = 'X';
						d_y_count++;
						count = 0;
					}
					else
					{
						remark = 'O';
						d_n_count++;
						count = 1;
					}

					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "TRANS_SEQ", CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID));
					TRS.add_string(list_item, "FR_WH_CODE", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
					TRS.add_string(list_item, "TO_WH_CODE", MWIPOPRDEF_WH.OPER_DESC, sizeof(MWIPOPRDEF_WH.OPER_DESC));
					TRS.add_string(list_item, "ORG_CODE", MGCMTBLDAT_AREA.DATA_1, sizeof(MGCMTBLDAT_AREA.DATA_1));
					TRS.add_int(list_item, "NO", CWIPPRSRUN.MAPPING_SEQ);
					TRS.add_string(list_item, "ITEM_CODE", CWIPPRSRUN.MAT_ID, sizeof(CWIPPRSRUN.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "LOT_NO", CWIPPRSRUN.LOT_ID, sizeof(CWIPPRSRUN.LOT_ID));
					TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.add_double(list_item, "LOT_QTY", count);
					TRS.add_char(list_item, "REMARKS", remark);
					TRS.add_double(list_item, "TOTAL_QTY", d_n_count);

					TRS.add_string(list_item, "SUMMARY_ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "SUMMARY_ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_double(list_item, "SUMMARY_ITEM_QTY", d_n_count);
					TRS.add_char(list_item, "SUMMARY_REMARKS", 'O');
					TRS.add_string(list_item, "SUMMARY_ITEM_CODE2", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(list_item, "SUMMARY_ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_double(list_item, "SUMMARY_ITEM_QTY2", d_y_count);
					TRS.add_char(list_item, "SUMMARY_REMARKS2", 'X');
				}
			}
			*/
		}
	}
	//미출고 내역
	else if (TRS.get_procstep(in_node) == 'S')
	{
		data_list = TRS.get_list(in_node, "ORDER_LIST");
		i_data_count = TRS.get_item_count(in_node, "ORDER_LIST");

		for (i = 0; i < i_data_count; i++)
		{
			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID), data_list[i], "PACK_ORDER_ID");
			CPAKORDSTS.LINE_NO = TRS.get_int(data_list[i], "LINE_NO");

			DBU_select_cpakordsts(1, &CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKORDSTS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//거래처
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_CUSTOMER, strlen(MP_GCM_CUSTOMER));
			memcpy(MGCMTBLDAT.KEY_1, CPAKORDSTS.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));
			COM_itoa_left(s_customer_site_id, CPAKORDSTS.CUSTOMER_SITE_ID, sizeof(s_customer_site_id));
			memcpy(MGCMTBLDAT.KEY_2, s_customer_site_id, sizeof(s_customer_site_id));

			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			//품목 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, CPAKORDSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, CPAKORDSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = CPAKORDSTS.MAT_VER;

			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0006");
				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTSX.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPLOTSTSX.MAT_VER = MWIPMATDEF.MAT_VER;
			d_stock_qty = DBU_select_mwiplotstsx_scalar(2, &MWIPLOTSTSX);

			//미출고량
			unpacked_qty = CPAKORDSTS.QTY - CPAKORDSTS.REG_QTY;

			list_item = TRS.add_node(out_node, "LABEL_LIST");
			TRS.add_string(list_item, "ORDER_NUMBER", CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			TRS.add_string(list_item, "BOOKED_DATE", CPAKORDSTS.PACK_ORD_DATE, 8);
			TRS.add_int(list_item, "LINE_NUMBER", CPAKORDSTS.LINE_NO);
			TRS.add_string(list_item, "LABEL_NAME", CPAKORDSTS.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
			TRS.add_string(list_item, "CUSTOMER_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
			TRS.add_string(list_item, "DRAWING_FLAG", CPAKORDSTS.DRAWING_FLAG, sizeof(CPAKORDSTS.DRAWING_FLAG));
			TRS.add_string(list_item, "ORDER_TYPE", CPAKORDSTS.ORDER_TYPE, sizeof(CPAKORDSTS.ORDER_TYPE));
			TRS.add_string(list_item, "REQUEST_DATE", CPAKORDSTS.REQUEST_DATE, 8);
			TRS.add_string(list_item, "SCHEDULE_SHIP_DATE", CPAKORDSTS.EXPECT_SHIP_DATE, 8);
			TRS.add_double(list_item, "UNPACKED_QUANTITY", unpacked_qty);
			TRS.add_string(list_item, "ORDER_DATE", CPAKORDSTS.PACK_ORD_DATE, 8);
			TRS.add_string(list_item, "ITEM_CODE", CPAKORDSTS.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "PACKING_INSTRUCTIONS", CPAKORDSTS.PACKING_INSTRUCTIONS, sizeof(CPAKORDSTS.PACKING_INSTRUCTIONS));
			TRS.add_string(list_item, "END_SHIP_TO_NAME", CPAKORDSTS.DELIVERY_NAME, sizeof(CPAKORDSTS.DELIVERY_NAME));
			TRS.add_nstring(list_item, "USER_NAME", TRS.get_string(in_node, IN_USERID));

			//맵핑 값 없음
			TRS.add_string(list_item, "SECTION_GBN", "", sizeof(""));
			TRS.add_string(list_item, "SECTION_NAME", "", sizeof(""));
			TRS.add_string(list_item, "FIXED_YN", "", sizeof(""));
			TRS.add_double(list_item, "UNPACKED_ONHAND_QUANTITY", d_stock_qty);
			TRS.add_double(list_item, "REMAIN_QTY", 0);
		}
	}
	//외주입고 라벨 => WIP LOT으로 자재 라벨 사용
	else if (TRS.get_procstep(in_node) == 'T')
	{
		inv_lot_list = TRS.get_list(in_node, "LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), inv_lot_list[i], "LOT_ID");

			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
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

			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 구매 입고 디테일 정보 조회
			DBU_init_minvdlvdtl(&MINVDLVDTL);
			TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
			MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
			DBU_select_minvdlvdtl(102, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 구매 입고 마스터 정보 조회
			DBU_init_minvdlvmst(&MINVDLVMST);
			TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
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

			//협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVDLVMST.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "ITEM_CODE", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "INPUT_DATE", MWIPLOTSTSX.OPER_IN_TIME, sizeof(MWIPLOTSTSX.OPER_IN_TIME));
			TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
			TRS.add_string(list_item, "UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));


			if (DB_error_code == DB_NOT_FOUND)
			{
				memset(s_vendor_name, ' ', sizeof(s_vendor_name));
				TRS.add_string(list_item, "VENDOR_NAME", s_vendor_name, sizeof(s_vendor_name));
			}
			else
			{
				TRS.add_string(list_item, "VENDOR_NAME", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			}

			TRS.add_string(list_item, "SUPPLIER_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		}
	}
	// 출하 출고증
	else if (TRS.get_procstep(in_node) == 'J')
	{
		i_page_no = 0;

		ship_order_list = TRS.get_list(in_node, "SHIP_ORDER_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "SHIP_ORDER_LIST"); i++)
		{
			i_lot_count = 0;

			// 출하 지시 마스터 정보 조회
			DBU_init_cshpordmst(&CSHPORDMST);
			TRS.copy(CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID), ship_order_list[i], "SHIP_ORDER_ID");
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

			// 출하 지시 상세 정보 조회
			DBU_init_cshporddtl(&CSHPORDDTL);
			TRS.copy(CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID), ship_order_list[i], "SHIP_ORDER_ID");
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
					TRS.add_fieldmsg(out_node, "CSHPORDDTL FETCH", DT_NOVALUESTRING);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cshporddtl(2);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//제품 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CSHPORDDTL.MAT_ID, sizeof(CSHPORDDTL.MAT_ID));
				MWIPMATDEF.MAT_VER = CSHPORDDTL.MAT_VER;
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

				i_lot_count++;

				row_num = i_lot_count % 6;

				switch (row_num)
				{
				case 1:
					i_page_no++;
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "SHIP_ID", CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
					TRS.add_string(list_item, "SHIP_ID2", CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
					TRS.add_int(list_item, "TAB_NO", 1);
					TRS.add_int(list_item, "PAGE_NO", i_page_no);
					TRS.add_string(list_item, "CUSTOMER_NAME", CSHPORDMST.CUSTOMER_NAME, sizeof(CSHPORDMST.CUSTOMER_NAME));
					TRS.add_string(list_item, "ITEM_CODE1", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME1", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM1", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY1", CSHPORDDTL.QTY);
					break;

				case 2:
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "ITEM_CODE2", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME2", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM2", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY2", CSHPORDDTL.QTY);
					break;

				case 3:
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "ITEM_CODE3", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME3", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM3", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY3", CSHPORDDTL.QTY);
					break;

				case 4:
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "ITEM_CODE4", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME4", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM4", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY4", CSHPORDDTL.QTY);
					break;

				case 5:
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "ITEM_CODE5", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME5", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM5", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY5", CSHPORDDTL.QTY);
					break;

				case 0:
					list_item = TRS.add_node(out_node, "LABEL_LIST");
					TRS.add_string(list_item, "ITEM_CODE6", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.add_string(list_item, "ITEM_NAME6", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
					TRS.add_string(list_item, "UOM6", CSHPORDDTL.UNIT, sizeof(CSHPORDDTL.UNIT));
					TRS.add_double(list_item, "QTY6", CSHPORDDTL.QTY);
					break;
				}
			}
		}
	}
	//원자재 라벨 - grit 공정 라벨로 자재 라벨 출력
	else if (TRS.get_procstep(in_node) == 'G')
	{
		inv_lot_list = TRS.get_list(in_node, "LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), inv_lot_list[i], "LOT_ID");

			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
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

			//협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVLOTSTS.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "ITEM_CODE", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "INPUT_DATE", MINVLOTSTS.RECV_DATE, sizeof(MINVLOTSTS.RECV_DATE));
			TRS.add_double(list_item, "LOT_QTY", MINVLOTSTS.QTY);
			TRS.add_string(list_item, "UOM", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));

			if (DB_error_code == DB_NOT_FOUND)
			{
				memset(s_vendor_name, ' ', sizeof(s_vendor_name));
				TRS.add_string(list_item, "VENDOR_NAME", s_vendor_name, sizeof(s_vendor_name));
			}
			else
			{
				TRS.add_string(list_item, "VENDOR_NAME", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			}

			TRS.add_string(list_item, "SUPPLIER_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
			TRS.add_string(list_item, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		}
	}
	// 창고에 있는 재고 조회 211220 추가
	else if (TRS.get_procstep(in_node) == 'H')
	{
		lot_list = TRS.get_list(in_node, "LOT_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
		{
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), lot_list[i], "LOT_ID");

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
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}


			//제품 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
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


			list_item = TRS.add_node(out_node, "LABEL_LIST");

			TRS.add_string(list_item, "MAIN_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(list_item, "ITEM_CODE", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_string(list_item, "ITEM_NAME", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(list_item, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			TRS.add_string(list_item, "ITEM_UOM", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_double(list_item, "LOT_QTY", MWIPLOTSTSX.QTY_1);
			TRS.add_string(list_item, "WO_NO", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));


			//TRS.add_string(list_item, "REMARKS", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
			TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));


		}
	}

	return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Label_List_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_LABEL_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Label_List_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"0123456789ABCDEFGHIJLMRST") == MP_FALSE)
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
