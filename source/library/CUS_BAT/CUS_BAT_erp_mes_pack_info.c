/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_pack_info.c
Description : ERP -> MES 포장지시 정보

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

int CUS_BAT_ERP_MES_PACK_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Pack_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Pack_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_PACK_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Pack_Info", out_node);


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
CUS_BAT_ERP_MES_PACK_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Pack_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_PACK_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_PACK_INFO_TAG IF_PACK_INFO;
	struct IF_PACK_INFO_HIS_TAG IF_PACK_INFO_HIS;
	
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	
	int i_step = 0;
	char procStep;
	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_Pack_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_pack_info(&IF_PACK_INFO);
	DBU_open_if_pack_info(i_step, &IF_PACK_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_PACK_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_PACK_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_PACK_INFO.FACTORY), IF_PACK_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_PACK_INFO.ORG_CODE), IF_PACK_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "ORDER_HEADER_ID", MP_INT, IF_PACK_INFO.ORDER_HEADER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NUMBER", MP_INT, IF_PACK_INFO.LINE_NUMBER);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_pack_info(i_step, &IF_PACK_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_pack_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_PACK_INFO OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_PACK_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_PACK_INFO.FACTORY), IF_PACK_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_PACK_INFO.ORG_CODE), IF_PACK_INFO.ORG_CODE);
			TRS.add_fieldmsg(out_node, "ORDER_HEADER_ID", MP_INT, IF_PACK_INFO.ORDER_HEADER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NUMBER", MP_INT, IF_PACK_INFO.LINE_NUMBER);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		/*FACTORY	1	VARCHAR2	10	공장
			PACK_ORDER_ID	2	VARCHAR2	25	포장 지시 번호
			LINE_NO	3	NUMBER	10	라인 번호
			PACK_ORD_DATE		VARCHAR2	14	포장 지시 일자
			MAT_ID		VARCHAR2	30	제품
			MAT_VER		NUMBER	10	버전
			CUSTOMER_ID		VARCHAR2	20	고객사
			DELIVERY_ID		VARCHAR2	20	납품처
			AREA_ID		VARCHAR2	20	사업부
			SUB_AREA_ID		VARCHAR2	20	작업장
			OPER		VARCHAR2	10	창고
			QTY		NUMBER	10, 3	주문 수량
			PACKED_QTY		NUMBER	10, 3	포장 완료 수량
			UNIT		VARCHAR2	10	단위
			PACK_ORD_STATUS		VARCHAR2	10	상태
			PACK_DATE		VARCHAR2	14	포장 일자
			LABEL_NAME		VARCHAR2	200	라벨 품목명
			LABEL_TYPE		VARCHAR2	10	라벨 유형
			LABEL_MESH		VARCHAR2	30	라벨 사이즈
*/

		DBU_init_cpakordsts(&CPAKORDSTS);

		memcpy(CPAKORDSTS.FACTORY, IF_PACK_INFO.FACTORY, sizeof(CPAKORDSTS.FACTORY));

		COM_itoa_left(CPAKORDSTS.PACK_ORDER_ID, IF_PACK_INFO.ORDER_HEADER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
		CPAKORDSTS.LINE_NO = IF_PACK_INFO.LINE_NUMBER;

		DBU_select_cpakordsts(1, &CPAKORDSTS);
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

			IF_PACK_INFO.IF_CODE = 'E';
			memcpy(IF_PACK_INFO.IF_MSG, Error_Msg, sizeof(IF_PACK_INFO.IF_MSG));
			DBU_update_if_pack_info(101, &IF_PACK_INFO);
			DB_commit();
			continue;
		}

		
		memcpy(CPAKORDSTS.PACK_ORD_DATE, IF_PACK_INFO.ORDERED_DATE, sizeof(CPAKORDSTS.PACK_ORD_DATE));

		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, IF_PACK_INFO.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, IF_PACK_INFO.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;

		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "WIP-0006");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_PACK_INFO.IF_CODE = 'R';
			memcpy(IF_PACK_INFO.IF_MSG, Error_Msg, sizeof(IF_PACK_INFO.IF_MSG));
			DBU_update_if_pack_info(101, &IF_PACK_INFO);
			DB_commit();
			continue;
		}


		memcpy(CPAKORDSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(CPAKORDSTS.MAT_ID));
		CPAKORDSTS.MAT_VER = MWIPMATDEF.MAT_VER;

		COM_itoa_left(CPAKORDSTS.CUSTOMER_ID, IF_PACK_INFO.CUSTOMER_ID, sizeof(CPAKORDSTS.CUSTOMER_ID));

		CPAKORDSTS.CUSTOMER_SITE_ID = IF_PACK_INFO.SHIP_TO_SITE_USE_ID;

		COM_itoa_left(CPAKORDSTS.DELIVERY_ID, IF_PACK_INFO.END_SHIP_TO_ID, sizeof(CPAKORDSTS.DELIVERY_ID));	//납품처 ID
		memcpy(CPAKORDSTS.DELIVERY_NAME, IF_PACK_INFO.END_SHIP_TO_NAME, sizeof(CPAKORDSTS.DELIVERY_NAME));	//최종 납품처명

		memcpy(CPAKORDSTS.AREA_ID, IF_PACK_INFO.ORG_CODE, sizeof(IF_PACK_INFO.ORG_CODE));
		
		memcpy(CPAKORDSTS.UNIT, IF_PACK_INFO.ORDER_UNIT, sizeof(IF_PACK_INFO.ORDER_UNIT));

		memcpy(CPAKORDSTS.LABEL_NAME, IF_PACK_INFO.LABEL_NAME, sizeof(CPAKORDSTS.LABEL_NAME));
		memcpy(CPAKORDSTS.LABEL_TYPE, IF_PACK_INFO.LABEL_TYPE, sizeof(CPAKORDSTS.LABEL_TYPE));
		memcpy(CPAKORDSTS.LABEL_MESH, IF_PACK_INFO.LABEL_MESH, sizeof(CPAKORDSTS.LABEL_MESH));		
		memcpy(CPAKORDSTS.DRAWING_FLAG, IF_PACK_INFO.DRAWING_FLAG, sizeof(IF_PACK_INFO.DRAWING_FLAG));
		memcpy(CPAKORDSTS.PACKING_INSTRUCTIONS, IF_PACK_INFO.PACKING_INSTRUCTIONS, sizeof(IF_PACK_INFO.PACKING_INSTRUCTIONS));
		memcpy(CPAKORDSTS.ORDER_TYPE, IF_PACK_INFO.ORDER_TYPE, sizeof(IF_PACK_INFO.ORDER_TYPE));
		memcpy(CPAKORDSTS.REQUEST_DATE, IF_PACK_INFO.REQUEST_DATE, sizeof(IF_PACK_INFO.REQUEST_DATE));
		memcpy(CPAKORDSTS.SCHEDULE_SHIP_DATE, IF_PACK_INFO.SCHEDULE_SHIP_DATE, sizeof(IF_PACK_INFO.SCHEDULE_SHIP_DATE));
		memcpy(CPAKORDSTS.PO_GUBUN, IF_PACK_INFO.PO_GUBUN, sizeof(IF_PACK_INFO.PO_GUBUN));
		memcpy(CPAKORDSTS.LINE_DESC, IF_PACK_INFO.LINE_DESC, sizeof(IF_PACK_INFO.LINE_DESC));
		memcpy(CPAKORDSTS.INCLUDE_INSPECTION, IF_PACK_INFO.INCLUDE_INSPECTION, sizeof(IF_PACK_INFO.INCLUDE_INSPECTION));
		COM_itoa_left(CPAKORDSTS.CMF_1, IF_PACK_INFO.ORDER_NUMBER, sizeof(CPAKORDSTS.CMF_1));

		memcpy(CPAKORDSTS.UPDATE_TIME, gs_sys_time, sizeof(CPAKORDSTS.UPDATE_TIME));
		memcpy(CPAKORDSTS.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		if (procStep == MP_STEP_CREATE)
		{
			memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_STATUS_WAIT, sizeof(CPAKORDSTS.PACK_ORD_STATUS));

			// 지시 수량 = ERP 지시수량 - 출하수량
			CPAKORDSTS.QTY = IF_PACK_INFO.ORDERED_QTY;
			CPAKORDSTS.REG_QTY = IF_PACK_INFO.SHIPED_QTY;
			CPAKORDSTS.PACKED_QTY = IF_PACK_INFO.SHIPED_QTY;

			//지시수량과 출하 수량이 같은 값이면, 완료되었다는 의미 -> 출하된 것
			if (IF_PACK_INFO.ORDERED_QTY == IF_PACK_INFO.SHIPED_QTY)
			{
				if (IF_PACK_INFO.SHIPED_QTY != 0)
				{
					memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
				}
			}

			memcpy(CPAKORDSTS.CREATE_TIME, gs_sys_time, sizeof(CPAKORDSTS.CREATE_TIME));
			memcpy(CPAKORDSTS.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

			DBU_insert_cpakordsts(&CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PACK_INFO.IF_CODE = 'E';
				memcpy(IF_PACK_INFO.IF_MSG, Error_Msg, sizeof(IF_PACK_INFO.IF_MSG));
				DBU_update_if_pack_info(101, &IF_PACK_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			// 지시 수량 = ERP 지시수량
			CPAKORDSTS.QTY = IF_PACK_INFO.ORDERED_QTY;

			//만약 포장이 완료된 상태에서 ERP에서 지시수량을 더 적은 수량으로 변경된 경우에는 영업과 해결해야할 문제.
			//취소 수량은 신경쓰지 않아도 됨.
			//기존 지시수량과 I/F 지시 수량이 다르다면, I/F 지시수량으로 변경

			// I/F 지시수량과 포장된 수량이 같다면 상태 변경
			if (CPAKORDSTS.QTY <= CPAKORDSTS.PACKED_QTY)
			{
				if (CPAKORDSTS.PACKED_QTY == 0)
				{
					memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
				}
				else
				{
					memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_PACKED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
				}
			}
			else
			{
				memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
			}

			if (IF_PACK_INFO.SHIPED_QTY != 0)
			{
				if (CPAKORDSTS.QTY == IF_PACK_INFO.SHIPED_QTY)
				{
					memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_SHIPPED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
				}
			}

			DBU_update_cpakordsts(1, &CPAKORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_PACK_INFO.IF_CODE = 'E';
				memcpy(IF_PACK_INFO.IF_MSG, Error_Msg, sizeof(IF_PACK_INFO.IF_MSG));
				DBU_update_if_pack_info(101, &IF_PACK_INFO);
				DB_commit();
				continue;
			}
		}

		// BACKUP
		DBU_init_if_pack_info_his(&IF_PACK_INFO_HIS);

		IF_PACK_INFO_HIS.IF_SEQ = IF_PACK_INFO.IF_SEQ;

		DBU_delete_if_pack_info_his(1, &IF_PACK_INFO_HIS);
		DBU_insert_if_pack_info_his((struct IF_PACK_INFO_HIS_TAG *)&IF_PACK_INFO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_PACK_INFO_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_pack_info(1, &IF_PACK_INFO);

		DB_commit();
	}

	return MP_TRUE;
}

