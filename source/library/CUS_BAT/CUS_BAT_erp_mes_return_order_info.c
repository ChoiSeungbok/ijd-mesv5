/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_return_order_info.c
Description : ERP -> MES 반품 정보

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/19  JS.SEO         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAT_common.h"

int CUS_BAT_ERP_MES_RETURN_ORDER_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Return_Order_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Return_Order_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;
	
	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_RETURN_ORDER_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Return_Order_Info", out_node);


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
CUS_BAT_ERP_MES_RETURN_ORDER_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Return_Order_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_RETURN_ORDER_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_RO_INFO_TAG IF_RO_INFO;
	struct IF_RO_INFO_HIS_TAG IF_RO_INFO_HIS;
	struct CRETORDSTS_TAG CRETORDSTS;

	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	int i_step = 0;
	char procStep;
	char Error_Msg[201];

	LOG_head("CUS_BAT_Erp_Mes_Return_Order_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_ro_info(&IF_RO_INFO);
	DBU_open_if_ro_info(i_step, &IF_RO_INFO);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_RO_INFO OPEN(101)", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_ro_info(i_step, &IF_RO_INFO);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_ro_info(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_RO_INFO FETCH(101)", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_RO_INFO.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_RO_INFO.FACTORY), IF_RO_INFO.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_NUMBER", MP_INT, IF_RO_INFO.ORDER_NUMBER);
			TRS.add_fieldmsg(out_node, "LINE_NUMBER", MP_INT, IF_RO_INFO.LINE_NUMBER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			DBU_close_if_ro_info(i_step);

			return MP_FALSE;
		}

		/*FACTORY	1	VARCHAR2	10	공장
		RET_ORDER_ID	2	VARCHAR2	25	반품 지시 번호
		RET_LOT_ID	3	VARCHAR2	25	반품 LOT ID
		LINE_NO		NUMBER	10	라인 번호
		RET_ORD_DATE		VARCHAR2	14	반품 지시 일자
		MAT_ID		VARCHAR2	30	제품
		MAT_VER		NUMBER	10	버전
		CUSTOMER_ID		VARCHAR2	20	고객사
		CUSTOMER_SITE_ID		NUMBER	10	고객 SITE ID
		AREA_ID		VARCHAR2	20	사업부
		SUB_AREA_ID		VARCHAR2	20	작업장
		OPER		VARCHAR2	10	창고
		QTY		NUMBER	10, 3	수량
		RETURNED_QTY		NUMBER	10, 3	반품 완료 수량
		UNIT		VARCHAR2	10	단위
		RET_ORD_STATUS		VARCHAR2	10	상태
		RET_DATE		VARCHAR2	14	반품 일자
		SHIP_ORDER_ID		VARCHAR2	25	출하 지시 번호
		SHIP_ORDER_SEQ		NUMBER	10	출하 지시 순번*/


		// 출하지시 MST존재하는지 확인
		DBU_init_cretordsts(&CRETORDSTS);
		memcpy(CRETORDSTS.FACTORY, IF_RO_INFO.FACTORY, sizeof(CRETORDSTS.FACTORY));
		COM_itoa_left(CRETORDSTS.CMF_1, IF_RO_INFO.ORDER_NUMBER, sizeof(CRETORDSTS.CMF_1));
		CRETORDSTS.LINE_NO = IF_RO_INFO.LINE_NUMBER;
		DBU_select_cretordsts(3, &CRETORDSTS);
		if (DB_error_code == DB_NOT_FOUND) {
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {
			if (IF_RO_INFO.TRAN_FLAG == 'D')
			{
				procStep = MP_STEP_DELETE;
			}
			else {
				procStep = MP_STEP_UPDATE;
			}			
		}
		else
		{
			DB_rollback();

			//WIP-0663 : 이 반품지시는 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0663");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_RO_INFO.IF_CODE = 'E';
			memcpy(IF_RO_INFO.IF_MSG, Error_Msg, sizeof(IF_RO_INFO.IF_MSG));
			DBU_update_if_ro_info(101, &IF_RO_INFO);
			DB_commit();
			continue;
		}

		CRETORDSTS.LINE_NO = IF_RO_INFO.LINE_NUMBER;
		memcpy(CRETORDSTS.MAT_ID, IF_RO_INFO.ITEM_CODE, sizeof(CRETORDSTS.MAT_ID));
		CRETORDSTS.MAT_VER = 1;
		COM_itoa_left(CRETORDSTS.CUSTOMER_ID, IF_RO_INFO.CUSTOMER_ID, sizeof(CRETORDSTS.CUSTOMER_ID));
		memcpy(CRETORDSTS.CUSTOMER_NUMBER, IF_RO_INFO.CUSTOMER_NUMBER, sizeof(CRETORDSTS.CUSTOMER_NUMBER));
		memcpy(CRETORDSTS.CUSTOMER_NAME, IF_RO_INFO.CUSTOMER_NAME, sizeof(CRETORDSTS.CUSTOMER_NAME));
		memcpy(CRETORDSTS.MAT_ID, IF_RO_INFO.ITEM_CODE, sizeof(CRETORDSTS.MAT_ID));
		CRETORDSTS.CUSTOMER_SITE_ID = IF_RO_INFO.CUSTOMER_SITE_ID;
		memcpy(CRETORDSTS.AREA_ID, IF_RO_INFO.ORG_CODE, sizeof(IF_RO_INFO.ORG_CODE));
		
		if (procStep == MP_STEP_UPDATE)
		{
			//반품요청수량이 현재 수량보다 클때
			if (CRETORDSTS.QTY < IF_RO_INFO.ORDERED_QTY)
			{
				memcpy(CRETORDSTS.RET_ORD_STATUS, MP_STATUS_WAIT, strlen(MP_STATUS_WAIT));
			}
			else if (CRETORDSTS.QTY > IF_RO_INFO.ORDERED_QTY)
			{
				if (CRETORDSTS.RETURNED_QTY == IF_RO_INFO.ORDERED_QTY)
				{
					memcpy(CRETORDSTS.RET_ORD_STATUS, MP_STATUS_RETURNED, strlen(MP_STATUS_RETURNED));
				}
				else if (CRETORDSTS.RETURNED_QTY > IF_RO_INFO.ORDERED_QTY)
				{
					//에러
					DB_rollback();

					//INV-0057 : 반품된 수량이 변경수량보다 큽니다.
					strcpy(s_msg_code, "INV-0057");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_RO_INFO.IF_CODE = 'E';
					memcpy(IF_RO_INFO.IF_MSG, Error_Msg, sizeof(IF_RO_INFO.IF_MSG));
					DBU_update_if_ro_info(101, &IF_RO_INFO);
					DB_commit();
					continue;
				}
			}
		}
		else if (procStep == MP_STEP_CREATE)
		{
			CRETORDSTS.RETURNED_QTY = 0;
			memcpy(CRETORDSTS.RET_ORD_STATUS, MP_STATUS_WAIT, strlen(MP_STATUS_WAIT));
		}

		CRETORDSTS.QTY = IF_RO_INFO.ORDERED_QTY;
		memcpy(CRETORDSTS.UNIT, IF_RO_INFO.UNIT, sizeof(IF_RO_INFO.UNIT));
		memcpy(CRETORDSTS.RET_ORD_DATE, IF_RO_INFO.ORDERED_DATE, sizeof(IF_RO_INFO.ORDERED_DATE));

		// 2020.12.23
		// COM_dtoa 로 형변환 하면 double 형이라 숫자값이 잘못된 값으로 변경되어 Query 에서 해결하고 CMF_10 에 임시로 넣어준걸로 가져가도록 수정
		//COM_dtoa(CRETORDSTS.SHIP_ORDER_ID, IF_RO_INFO.SHIPPING_HEADER_ID, sizeof(CRETORDSTS.SHIP_ORDER_ID));
		memcpy(CRETORDSTS.SHIP_ORDER_ID, IF_RO_INFO.CMF_10, sizeof(CRETORDSTS.SHIP_ORDER_ID));
		

		CRETORDSTS.SHIP_ORDER_SEQ = IF_RO_INFO.SHIPPING_LINE_ID;
		CRETORDSTS.SHIP_LINE_IF_ID = IF_RO_INFO.SHIP_LINE_IF_ID;
		CRETORDSTS.SHIP_LINE_LOT_IF_ID = IF_RO_INFO.SHIP_LINE_LOT_IF_ID;
		CRETORDSTS.REFERENCE_LINE_ID = IF_RO_INFO.REFERENCE_LINE_ID;

		CRETORDSTS.OE_ORDER_HEADER_ID = IF_RO_INFO.OE_ORDER_HEADER_ID;
		CRETORDSTS.OE_ORDER_LINE_ID = IF_RO_INFO.OE_ORDER_LINE_ID;

		memcpy(CRETORDSTS.LABEL_NAME, IF_RO_INFO.ITEM_DESC, sizeof(IF_RO_INFO.ITEM_DESC));
		memcpy(CRETORDSTS.UPDATE_TIME, gs_sys_time, sizeof(CRETORDSTS.UPDATE_TIME));
		memcpy(CRETORDSTS.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
		if (procStep == MP_STEP_CREATE)
		{
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.set_string(gen_in_node, "FACTORY", IF_RO_INFO.FACTORY, sizeof(IF_RO_INFO.FACTORY));

			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_RET_ORDER_NO, strlen(MP_ID_ROLE_RET_ORDER_NO));
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

			TRS.copy(CRETORDSTS.RET_ORDER_ID, sizeof(CRETORDSTS.RET_ORDER_ID), cmn_out, "GEN_ID");
			TRS.free_node(cmn_out);

			memcpy(CRETORDSTS.CREATE_TIME, gs_sys_time, sizeof(CRETORDSTS.CREATE_TIME));
			memcpy(CRETORDSTS.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
			DBU_insert_cretordsts(&CRETORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_RO_INFO.IF_CODE = 'E';
				memcpy(IF_RO_INFO.IF_MSG, Error_Msg, sizeof(IF_RO_INFO.IF_MSG));
				DBU_update_if_ro_info(101, &IF_RO_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			DBU_update_cretordsts(1, &CRETORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_RO_INFO.IF_CODE = 'E';
				memcpy(IF_RO_INFO.IF_MSG, Error_Msg, sizeof(IF_RO_INFO.IF_MSG));
				DBU_update_if_ro_info(101, &IF_RO_INFO);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_DELETE) 
		{
			DBU_delete_cretordsts(1, &CRETORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_RO_INFO.IF_CODE = 'E';
				memcpy(IF_RO_INFO.IF_MSG, Error_Msg, sizeof(IF_RO_INFO.IF_MSG));
				DBU_update_if_ro_info(101, &IF_RO_INFO);
				DB_commit();
				continue;
			}
		}


		// BACKUP
		DBU_init_if_ro_info_his(&IF_RO_INFO_HIS);

		IF_RO_INFO_HIS.IF_SEQ = IF_RO_INFO.IF_SEQ;

		DBU_delete_if_ro_info_his(1, &IF_RO_INFO_HIS);
		DBU_insert_if_ro_info_his((struct IF_RO_INFO_HIS_TAG *)&IF_RO_INFO);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_RO_INFO_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_ro_info(1, &IF_RO_INFO);

		DB_commit();
	}

	return MP_TRUE;
}

