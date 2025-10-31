/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_po_list.c
Description : View PO List

MES Version : 4.0.0

Function List
- CUS_INV_View_PO_List()
+ View PO List
- CUS_INV_VIEW_PO_LIST()
+ Main sub function of "CUS_INV_View_PO_List" function
+ Unload Lot definition
- CUS_INV_View_PO_List_Validation()
+ Validation Check sub function of "CUS_INV_VIEW_PO_LIST" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/14  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_View_PO_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_PO_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_PO_List()
- View PO List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_PO_List(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_VIEW_PO_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_VIEW_PO_LIST", out_node);

	if (i_ret == MP_TRUE)
	{
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
		DB_commit();
	}
	else
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_VIEW_PO_LIST()
- Main sub function of "CUS_INV_View_PO_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_PO_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMLAGDAT_TAG MGCMLAGDAT;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_INV_View_PO_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_PO_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	DB_init_condition(&DBC_Q_COND);
	TRS.copy(DBC_Q_COND.FROM_TIME, sizeof(DBC_Q_COND.FROM_TIME), in_node, "FROM_DATE");
	TRS.copy(DBC_Q_COND.TO_TIME, sizeof(DBC_Q_COND.TO_TIME), in_node, "TO_DATE");

	DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N);

	// PROCSTEP = 1 -> 구매 입고 마스터 정보 조회
	// PROCSTEP = 2 -> 구매 입고 상세 정보 조회
	if (TRS.get_procstep(in_node) == '1')
	{
		i_step = 2;

		DBU_init_minvdlvmst(&MINVDLVMST);
		TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID), in_node, "VENDOR_ID");
		DBU_open_minvdlvmst(i_step, &MINVDLVMST);

		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVDLVMST OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVDLVMST.AREA_ID), MINVDLVMST.AREA_ID);
			TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MINVDLVMST.VENDOR_ID), MINVDLVMST.VENDOR_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_minvdlvmst(i_step, &MINVDLVMST);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_minvdlvmst(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVDLVMST OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVDLVMST.AREA_ID), MINVDLVMST.AREA_ID);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MINVDLVMST.VENDOR_ID), MINVDLVMST.VENDOR_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvdlvmst(i_step);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "DLV_MST_LIST");

			TRS.add_string(list_item, "DLV_NO", MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
			TRS.add_string(list_item, "PO_NO", MINVDLVMST.PO_NO, sizeof(MINVDLVMST.PO_NO));
			TRS.add_string(list_item, "BL_NO", MINVDLVMST.BL_NO, sizeof(MINVDLVMST.BL_NO));
			TRS.add_string(list_item, "DLV_EXP_DATE", MINVDLVMST.DLV_EXP_DATE, sizeof(MINVDLVMST.DLV_EXP_DATE));
			TRS.add_string(list_item, "VENDOR_ID", MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			TRS.add_int(list_item, "VENDOR_SITE_ID", MINVDLVMST.VENDOR_SITE_ID);

			// 협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVDLVMST.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));
			COM_itoa_left(MGCMTBLDAT.KEY_2, MINVDLVMST.VENDOR_SITE_ID, sizeof(MGCMTBLDAT.KEY_2));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMLAGDAT.FACTORY), MGCMLAGDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMLAGDAT.TABLE_NAME), MGCMLAGDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "VENDOR_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_1), MGCMLAGDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "VENDOR_SITE_ID", MP_STR, sizeof(MGCMLAGDAT.KEY_2), MGCMLAGDAT.KEY_2);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvdlvmst(i_step);
				//

				return MP_FALSE;
			}			

			if (DB_error_code == DB_NOT_FOUND)
			{
				TRS.add_string(list_item, "VENDOR_DESC", " ", strlen(" "));
			}
			else
			{
				TRS.add_string(list_item, "VENDOR_DESC", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
			}
			TRS.add_string(list_item, "AREA_ID", MINVDLVMST.AREA_ID, sizeof(MINVDLVMST.AREA_ID));
			TRS.add_string(list_item, "CMF_1", MINVDLVMST.CMF_1, sizeof(MINVDLVMST.CMF_1));
		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		i_step = 2;

		DBU_init_minvdlvdtl(&MINVDLVDTL);
		TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO), in_node, "DLV_NO");
		DBU_open_minvdlvdtl(i_step, &MINVDLVDTL);

		if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVDLVMST OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_minvdlvdtl(i_step, &MINVDLVDTL);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_minvdlvdtl(i_step);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//INV-0043 : 검색하신 정보는 존재하지 않습니다.
				strcpy(s_msg_code, "INV-0043");
				TRS.add_fieldmsg(out_node, "MINVDLVMST OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvdlvdtl(i_step);
				//

				return MP_FALSE;
			}

			list_item = TRS.add_node(out_node, "DLV_DTL_LIST");

			TRS.add_string(list_item, "DLV_NO", MINVDLVDTL.DLV_NO, sizeof(MINVDLVDTL.DLV_NO));
			TRS.add_int(list_item, "DLV_SEQ", MINVDLVDTL.DLV_SEQ);
			TRS.add_string(list_item, "PO_NO", MINVDLVDTL.PO_NO, sizeof(MINVDLVDTL.PO_NO));
			TRS.add_int(list_item, "PO_SEQ", MINVDLVDTL.PO_SEQ);
			TRS.add_string(list_item, "BL_NO", MINVDLVDTL.BL_NO, sizeof(MINVDLVDTL.BL_NO));
			TRS.add_int(list_item, "BL_SEQ", MINVDLVDTL.BL_SEQ);
			TRS.add_double(list_item, "DLV_QTY", MINVDLVDTL.DLV_QTY);
			TRS.add_double(list_item, "DLV_IN_QTY", MINVDLVDTL.DLV_IN_QTY);
			TRS.add_double(list_item, "CONFIRM_QTY", MINVDLVDTL.CONFIRM_QTY);
			TRS.add_double(list_item, "LOSS_QTY", MINVDLVDTL.LOSS_QTY);

			//제품 조회
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

				// 20.12.21 minjae.go
				DBU_close_minvdlvdtl(i_step);
				//
				

				return MP_FALSE;
			}

			TRS.add_string(list_item, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			TRS.add_string(list_item, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(list_item, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_char(list_item, "ERP_OPEN_YN", MINVDLVDTL.ERP_OPEN_YN);
		}
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_View_PO_List_Validation()
- Validation Check sub function of "CUS_INV_VIEW_PO_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_PO_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */ 
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
