/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_po_info.c
Description : ERP -> MES PO 정보

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/22  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAT_common.h"

int CUS_BAT_ERP_MES_PO_INFO(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Po_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Po_Info(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_PO_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Po_Info", out_node);


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
CUS_BAT_ERP_MES_PO_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Po_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_PO_INFO(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct IF_PO_INFO_TAG IF_PO_INFO;
	struct IF_PO_INFO_HIS_TAG IF_PO_INFO_HIS;
	struct MINVDLVMST_TAG MINVDLVMST;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;


	TRSNode* gen_in_node;
	TRSNode* cmn_out;

	int i_step = 0;
	int i_step_2 = 0;

	char procStep;
	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_Po_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_po_info(&IF_PO_INFO);
	DBU_open_if_po_info(i_step, &IF_PO_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_PO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_PO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_PO_INFO.FACTORY), IF_PO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_PO_INFO.ORG_CODE), IF_PO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "PO_HEADER_ID", MP_INT, IF_PO_INFO.PO_HEADER_ID);
			TRS.add_fieldmsg(out_node, "PO_LINE_ID", MP_INT, IF_PO_INFO.PO_LINE_ID);
			TRS.add_fieldmsg(out_node, "PO_NUM", MP_INT, IF_PO_INFO.PO_NUM);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_po_info(i_step, &IF_PO_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_po_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_PO_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_PO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_PO_INFO.FACTORY), IF_PO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_PO_INFO.ORG_CODE), IF_PO_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "PO_HEADER_ID", MP_INT, IF_PO_INFO.PO_HEADER_ID);
			TRS.add_fieldmsg(out_node, "PO_LINE_ID", MP_INT, IF_PO_INFO.PO_LINE_ID);
			TRS.add_fieldmsg(out_node, "PO_NUM", MP_INT, IF_PO_INFO.PO_NUM);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		// INSERT DELIVERY MASTER TABLE
		//FACTORY	1	VARCHAR2	10	FACTORY
		//	DLV_NO	2	NUMBER	10	입고 번호
		//	PO_NO		VARCHAR2	30	구매 발주 번호
		//	PO_SEQ		NUMBER	10	구매 발주 순번
		//	BL_NO		VARCHAR2	30	통관번호
		//	BL_SEQ		NUMBER	10	통관 순번
		//	DLV_EXP_DATE		VARCHAR2	8	납품 예정 일자
		//	VENDOR_CODE		VARCHAR2	20	공급사 코드
		//	VENDOR_SITE_ID		NUMBER	공급사 코드
		//	AREA_ID		VARCHAR2	20	사업부

		DBU_init_minvdlvmst(&MINVDLVMST);

		memcpy(MINVDLVMST.FACTORY, IF_PO_INFO.FACTORY, sizeof(MINVDLVMST.FACTORY));
		memcpy(MINVDLVMST.PO_NO, IF_PO_INFO.PO_NUM, sizeof(IF_PO_INFO.PO_NUM));
		memcpy(MINVDLVMST.AREA_ID, IF_PO_INFO.ORG_CODE, sizeof(IF_PO_INFO.ORG_CODE));
		//MINVDLVMST.PO_SEQ = IF_PO_INFO.LINE_NUM;

		DBU_select_minvdlvmst(102, &MINVDLVMST);

		if (DB_error_code == DB_NOT_FOUND) {
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {
			procStep = MP_STEP_UPDATE;
		}
		else
		{
			DB_rollback();

			strcpy(s_msg_code, "INV-0052");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_PO_INFO.IF_CODE = 'E';
			memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
			DBU_update_if_po_info(101, &IF_PO_INFO);
			DB_commit();
			continue;
		}

		memcpy(MINVDLVMST.DLV_EXP_DATE, IF_PO_INFO.NEED_BY_DATE, sizeof(MINVDLVMST.DLV_EXP_DATE));

		COM_itoa_left(MINVDLVMST.VENDOR_ID, IF_PO_INFO.VENDOR_ID, sizeof(MINVDLVMST.VENDOR_ID));

		MINVDLVMST.VENDOR_SITE_ID = IF_PO_INFO.VENDOR_SITE_ID;
		memcpy(MINVDLVMST.AREA_ID, IF_PO_INFO.ORG_CODE, sizeof(IF_PO_INFO.ORG_CODE));
		memcpy(MINVDLVMST.CMF_1, IF_PO_INFO.WIP_ENTITY_NAME, sizeof(MINVDLVMST.CMF_1));

		memcpy(MINVDLVMST.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVMST.UPDATE_TIME));
		memcpy(MINVDLVMST.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		if (procStep == MP_STEP_CREATE)
		{
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.set_string(gen_in_node, "FACTORY", IF_PO_INFO.FACTORY, sizeof(IF_PO_INFO.FACTORY));

			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_DLV_NO, strlen(MP_ID_ROLE_DLV_NO));
			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
			TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.copy(MINVDLVMST.DLV_NO, sizeof(MINVDLVMST.DLV_NO), cmn_out, "GEN_ID");
			TRS.free_node(cmn_out);

			memcpy(MINVDLVMST.CREATE_TIME, gs_sys_time, sizeof(MINVDLVMST.CREATE_TIME));
			memcpy(MINVDLVMST.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_minvdlvmst(&MINVDLVMST);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PO_INFO.IF_CODE = 'E';
				//어디서 확인하려구  추가 20211026
				memcpy(IF_PO_INFO.CMF_9, MINVDLVMST.DLV_NO, sizeof(IF_PO_INFO.CMF_9));
				memcpy(IF_PO_INFO.CMF_10, "DBU_insert_minvdlvmst", sizeof(IF_PO_INFO.CMF_10));
				memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
				DBU_update_if_po_info(101, &IF_PO_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			DBU_update_minvdlvmst(1, &MINVDLVMST);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PO_INFO.IF_CODE = 'E';
				//어디서 확인하려구  추가 20211026
				memcpy(IF_PO_INFO.CMF_10, " DBU_update_minvdlvmst", sizeof(IF_PO_INFO.CMF_10));
				memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
				DBU_update_if_po_info(101, &IF_PO_INFO);
				DB_commit();
				continue;
			}
		}


		// INSERT DELIVERY DETAIL TABLE
		/*FACTORY	1	VARCHAR2	10	FACTORY
			DLV_NO	2	VARCHAR2	30	입고 번호
			DLV_SEQ	3	NUMBER	10	입고 순번
			MAT_ID		VARCHAR2	30	제품
			MAT_VER		NUMBER	10	제품버전
			PO_NO		VARCHAR2	30	구매 발주 번호
			PO_SEQ		NUMBER	10	구매 발주 순번
			BL_NO		VARCHAR2	30	통관번호
			BL_SEQ		NUMBER	10	통관 순번
			DLV_QTY		NUMBER	10, 3	입고 수량
			AREA_ID		VARCHAR2	20	사업부

			PO_HEADER_ID
			PO_LINE_ID
			PO_RELEASE_ID
			LINE_LOCATION_ID
			PO_DISTRIBUTION_ID
			PO_TYPE
			INSPECTION_FLAG
			CONSIGNMENT_FLAG

			*/

		DBU_init_minvdlvdtl(&MINVDLVDTL);

		memcpy(MINVDLVDTL.FACTORY, IF_PO_INFO.FACTORY, sizeof(MINVDLVDTL.FACTORY));
		memcpy(MINVDLVDTL.DLV_NO, MINVDLVMST.DLV_NO, sizeof(MINVDLVDTL.DLV_NO));
		memcpy(MINVDLVDTL.PO_NO, IF_PO_INFO.PO_NUM, sizeof(IF_PO_INFO.PO_NUM));
		MINVDLVDTL.PO_SEQ = IF_PO_INFO.LINE_NUM;
		MINVDLVDTL.PO_DISTRIBUTION_ID = IF_PO_INFO.PO_DISTRIBUTION_ID;

		DBU_select_minvdlvdtl(101, &MINVDLVDTL);

		if (DB_error_code == DB_NOT_FOUND) {
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {
			procStep = MP_STEP_UPDATE;
		}
		else
		{
			DB_rollback();

			strcpy(s_msg_code, "INV-0004");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_PO_INFO.IF_CODE = 'E';
			//어디서 확인하려구  추가 20211026
			memcpy(IF_PO_INFO.CMF_10, "DBU_select_minvdlvdtl", sizeof(IF_PO_INFO.CMF_10));
			memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
			DBU_update_if_po_info(101, &IF_PO_INFO);
			DB_commit();
			continue;
		}


		memcpy(MINVDLVDTL.AREA_ID, IF_PO_INFO.ORG_CODE, sizeof(IF_PO_INFO.ORG_CODE));

		memcpy(MINVDLVDTL.MAT_ID, IF_PO_INFO.ITEM_CODE, sizeof(MINVDLVDTL.MAT_ID));
		MINVDLVDTL.MAT_VER = 1;

		MINVDLVDTL.DLV_QTY = IF_PO_INFO.ORDER_QTY;

		MINVDLVDTL.PO_HEADER_ID = IF_PO_INFO.PO_HEADER_ID;
		MINVDLVDTL.PO_LINE_ID = IF_PO_INFO.PO_LINE_ID;
		MINVDLVDTL.PO_RELEASE_ID = IF_PO_INFO.PO_RELEASE_ID;
		MINVDLVDTL.LINE_LOCATION_ID = IF_PO_INFO.LINE_LOCATION_ID;
		MINVDLVDTL.PO_DISTRIBUTION_ID = IF_PO_INFO.PO_DISTRIBUTION_ID;
		memcpy(MINVDLVDTL.PO_TYPE, IF_PO_INFO.PO_TYPE, sizeof(MINVDLVDTL.PO_TYPE));
		memcpy(MINVDLVDTL.CMF_1, IF_PO_INFO.WIP_ENTITY_NAME, sizeof(MINVDLVDTL.CMF_1));

		//MINVDLVDTL.INSPECTION_FLAG = IF_PO_INFO.INSPECT_FLAG;



		//20220707 추가( ERP무시하고 MES에서 수입검사 유무 판별)

		i_step_2 = 2;

		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_PO_INFO.FACTORY, sizeof(IF_PO_INFO.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_C_INSP_IQC_MES_FLAG, strlen(MP_GCM_C_INSP_IQC_MES_FLAG));
		memcpy(MGCMTBLDAT.KEY_1, IF_PO_INFO.ITEM_CODE, sizeof(MGCMTBLDAT.KEY_1));
		DBU_open_mgcmtbldat(i_step_2, &MGCMTBLDAT);
		/*
		if (DB_error_code == DB_SUCCESS)
		{
			MINVDLVDTL.INSPECTION_FLAG = MGCMTBLDAT.DATA_1[0];
		}
		else
		{
			MINVDLVDTL.INSPECTION_FLAG = IF_PO_INFO.INSPECT_FLAG;
		}
		*/

		// FETCH
		while (1)
		{
			DBU_fetch_mgcmtbldat(i_step_2, &MGCMTBLDAT);
			if (DB_error_code == DB_SUCCESS)
			{
				MINVDLVDTL.INSPECTION_FLAG = MGCMTBLDAT.DATA_1[0];
				break;
			}
			else
			{
				MINVDLVDTL.INSPECTION_FLAG = IF_PO_INFO.INSPECT_FLAG;
				DBU_close_mgcmtbldat(i_step_2);
				break;
			}


		}


		MINVDLVDTL.CONSIGNMENT_FLAG = IF_PO_INFO.CONSIGNMENT_FLAG[0];

		memcpy(MINVDLVDTL.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.UPDATE_TIME));
		memcpy(MINVDLVDTL.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
		/*
				if (IF_PO_INFO.APPROVED_FLAG_HEADER == 'Y' && IF_PO_INFO.APPROVED_FLAG_LOCATION == 'Y'
					&& memcmp(IF_PO_INFO.CLOSED_CODE_HEADER, "FINALLY CLOSED", strlen("FINALLY CLOSED")) == 1
					&& (memcmp(IF_PO_INFO.CLOSED_CODE_LOCATION, "OPEN", strlen("OPEN")) == 0 || memcmp(IF_PO_INFO.CLOSED_CODE_LOCATION, "CLOSED FOR INVOICE", strlen("CLOSED FOR INVOICE")) == 0)
					&& IF_PO_INFO.USER_HOLD_FLAG == 'N'
					&& IF_PO_INFO.FROZEN_FLAG == 'N'
					&& IF_PO_INFO.PHA_CANCEL_FLAG == 'N'
					&& IF_PO_INFO.PLA_CANCEL_FLAG == 'N'
					&& IF_PO_INFO.PLLA_CANCEL_FLAG == 'N'
					)
					*/
		//2024-07-23  CLOSED_CODE_LOCATION 조건 수정.
		if (IF_PO_INFO.APPROVED_FLAG_HEADER == 'Y' && IF_PO_INFO.APPROVED_FLAG_LOCATION == 'Y'
			&& memcmp(IF_PO_INFO.CLOSED_CODE_HEADER, "FINALLY CLOSED", strlen("FINALLY CLOSED")) == 1
			&& (memcmp(IF_PO_INFO.CLOSED_CODE_LOCATION, "OPEN", strlen("OPEN")) == 0 || memcmp(IF_PO_INFO.CLOSED_CODE_LOCATION, "CLOSED FOR INVOICE", strlen("CLOSED FOR INVOICE")) == 0)
			&& IF_PO_INFO.USER_HOLD_FLAG == 'N'
			&& IF_PO_INFO.FROZEN_FLAG == 'N'
			&& IF_PO_INFO.PHA_CANCEL_FLAG == 'N'
			&& IF_PO_INFO.PLA_CANCEL_FLAG == 'N'
			&& IF_PO_INFO.PLLA_CANCEL_FLAG == 'N'
			)


		{
			// Open PO
			MINVDLVDTL.ERP_OPEN_YN = ' ';
			// 외주 PO 의 경우 WO 에 PO NUM 값을 업데이트 해준다.
			// PO NUM 에서 PO DISTRIBUTION ID 로 변경한다. 1개PO에 여러개 WO가 물릴수 있기 때문
			if (COM_isnullspace(IF_PO_INFO.WIP_ENTITY_NAME) == MP_FALSE)
			{
				DBU_init_mwipordsts(&MWIPORDSTS);
				memcpy(MWIPORDSTS.FACTORY, IF_PO_INFO.FACTORY, sizeof(MWIPORDSTS.FACTORY));
				memcpy(MWIPORDSTS.ORDER_ID, IF_PO_INFO.WIP_ENTITY_NAME, sizeof(MWIPORDSTS.ORDER_ID));
				DBU_select_mwipordsts(1, &MWIPORDSTS);

				if (DB_error_code == DB_SUCCESS)
				{
					//memcpy 에서 itoa로 변경 _ 20201215 wg.lee
					COM_itoa_left(MWIPORDSTS.ORD_CMF_4, IF_PO_INFO.PO_DISTRIBUTION_ID, sizeof(MWIPORDSTS.ORD_CMF_4));
					//memcpy(MWIPORDSTS.ORD_CMF_4, IF_PO_INFO.PO_DISTRIBUTION_ID, sizeof(IF_PO_INFO.PO_NUM));
					DBU_update_mwipordsts(2, &MWIPORDSTS);
				}
			}
		}
		else {
			// Closed PO
			MINVDLVDTL.ERP_OPEN_YN = 'Y';
		}

		if (procStep == MP_STEP_CREATE)
		{
			MINVDLVDTL.DLV_SEQ = (int)DBU_select_minvdlvdtl_scalar(101, &MINVDLVDTL);
			memcpy(MINVDLVDTL.CREATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.CREATE_TIME));
			memcpy(MINVDLVDTL.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_minvdlvdtl(&MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PO_INFO.IF_CODE = 'E';
				//어디서 확인하려구  추가 20211026
				memcpy(IF_PO_INFO.CMF_10, "DBU_insert_minvdlvdtl", sizeof(IF_PO_INFO.CMF_10));
				memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
				DBU_update_if_po_info(101, &IF_PO_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{

			/*WHERE 1 = 1
				AND t.approved_flag_header = 'Y' --R
				AND t.approved_flag_location = 'Y' --R
				AND t.closed_code_header     NOT IN('FINALLY CLOSED') --OPEN, CLOSED
				AND t.closed_code_location   IN('OPEN', 'CLOSED FOR INVOICE') --OPEN, CLOSED, CLOSED FOR RECEIVING, CLOSED FOR INVOICE, FINALLY CLOSED, CANCELLED
				AND t.user_hold_flag = 'N' --Y
				AND t.frozen_flag = 'N'
				AND t.cancel_flag_header = 'N'
				AND t.cancel_flag_line = 'N'
				AND t.cancel_flag_location = 'N'*/

			DBU_update_minvdlvdtl(1, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PO_INFO.IF_CODE = 'E';
				//어디서 확인하려구  추가 20211026
				memcpy(IF_PO_INFO.CMF_10, "DBU_update_minvdlvdtl", sizeof(IF_PO_INFO.CMF_10));

				memcpy(IF_PO_INFO.IF_MSG, Error_Msg, sizeof(IF_PO_INFO.IF_MSG));
				DBU_update_if_po_info(101, &IF_PO_INFO);
				DB_commit();
				continue;
			}
		}


		// BACKUP
		DBU_init_if_po_info_his(&IF_PO_INFO_HIS);

		IF_PO_INFO_HIS.IF_SEQ = IF_PO_INFO.IF_SEQ;

		DBU_delete_if_po_info_his(1, &IF_PO_INFO_HIS);
		DBU_insert_if_po_info_his((struct IF_PO_INFO_HIS_TAG*)&IF_PO_INFO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_PO_INFO_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_po_info(1, &IF_PO_INFO);

		DB_commit();
	}

	return MP_TRUE;
}

