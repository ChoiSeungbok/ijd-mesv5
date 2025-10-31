/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_ship_order_info.c
Description : ERP -> MES 출하 정보

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

int CUS_BAT_ERP_MES_SHIP_ORDER_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Ship_Order_Info()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Ship_Order_Info(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_SHIP_ORDER_INFO(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Ship_Order_Info", out_node);


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
CUS_BAT_ERP_MES_SHIP_ORDER_INFO()
- Main sub function of "CUS_BAT_Erp_Mes_Ship_Order_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_SHIP_ORDER_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_SO_MST_TAG IF_SO_MST;
	struct IF_SO_MST_HIS_TAG IF_SO_MST_HIS;
	struct IF_SO_DTL_TAG IF_SO_DTL;
	struct IF_SO_DTL_HIS_TAG IF_SO_DTL_HIS;
	struct CSHPORDMST_TAG CSHPORDMST;
	struct CSHPORDDTL_TAG CSHPORDDTL;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

	int i_step = 0;
	char procStep;
	char Error_Msg[201];
	int i_dtl_count = 0;

	LOG_head("CUS_BAT_Erp_Mes_Ship_Order_Info");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_so_mst(&IF_SO_MST);
	DBU_open_if_so_mst(i_step, &IF_SO_MST);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_SO_MST OPEN(101)", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_so_mst(i_step, &IF_SO_MST);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_so_mst(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_SO_MST FETCH(101)", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_SO_MST.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_SO_MST.FACTORY), IF_SO_MST.FACTORY);
			TRS.add_fieldmsg(out_node, "SHIPPING_HEADER_ID", MP_INT, IF_SO_MST.SHIPPING_HEADER_ID);
			TRS.add_fieldmsg(out_node, "SHIPPING_HEADER_NUM", MP_STR, IF_SO_MST.SHIPPING_HEADER_NUM);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			DBU_close_if_so_mst(i_step);

			return MP_FALSE;
		}

		// INSERT SHIP ORDER MASTER TABLE
		// FACTORY	1	VARCHAR2	10	공장
		// SHIP_ORDER_ID	2	VARCHAR2	25	출하 지시 번호
		// SHIP_ORD_DATE		VARCHAR2	14	출하 지시 일자
		// CUSTOMER_ID		VARCHAR2	20	고객사 
		// AREA_ID		VARCHAR2	20	사업부
		// SUB_AREA_ID		VARCHAR2	20	작업장 X
		// OPER		VARCHAR2	10	창고 X
		// DELIVERY_ID		VARCHAR2	20	납품처
		// DELIVERY_LOCATION		VARCHAR2	50	납품장소
		// DELIVERY_PHONE_NO		VARCHAR2	20	납품연락처
		// DELIVERY_USER_ID		VARCHAR2	20	납품처 담당자
		// SHIP_ORD_STATUS		VARCHAR2	10	상태

		// 출하지시 MST존재하는지 확인
		DBU_init_cshpordmst(&CSHPORDMST);
		memcpy(CSHPORDMST.FACTORY, IF_SO_MST.FACTORY, sizeof(CSHPORDMST.FACTORY));
		COM_itoa_left(CSHPORDMST.SHIP_ORDER_ID, IF_SO_MST.SHIPPING_HEADER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
		DBU_select_cshpordmst(1, &CSHPORDMST);
		if (DB_error_code == DB_NOT_FOUND) {
			procStep = MP_STEP_CREATE;
		}
		else if (DB_error_code == DB_SUCCESS) {
			procStep = MP_STEP_UPDATE;
		}
		else
		{
			DB_rollback();
			//WIP-0664 : 이 출하지시는 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0664");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_SO_MST.IF_CODE = 'E';
			memcpy(IF_SO_MST.IF_MSG, Error_Msg, sizeof(IF_SO_MST.IF_MSG));
			DBU_update_if_so_mst(101, &IF_SO_MST);
			DB_commit();
			continue;
		}

		memcpy(CSHPORDMST.SHIP_ORD_DATE, IF_SO_MST.SHIPPING_DATE, sizeof(IF_SO_MST.SHIPPING_DATE));
		COM_itoa_left(CSHPORDMST.CUSTOMER_ID, IF_SO_MST.CUSTOMER_ID, sizeof(CSHPORDMST.CUSTOMER_ID));

		memcpy(CSHPORDMST.CUSTOMER_NUMBER, IF_SO_MST.CUSTOMER_NUMBER, sizeof(IF_SO_MST.CUSTOMER_NUMBER));
		memcpy(CSHPORDMST.CUSTOMER_NAME, IF_SO_MST.CUSTOMER_NAME, sizeof(IF_SO_MST.CUSTOMER_NAME));
		memcpy(CSHPORDMST.AREA_ID, IF_SO_MST.SHIP_FROM_ORG_NAME, sizeof(IF_SO_MST.SHIP_FROM_ORG_NAME));
		memcpy(CSHPORDMST.DELIVERY, IF_SO_MST.SHIP_TO_ORG_NAME, sizeof(IF_SO_MST.SHIP_TO_ORG_NAME));
		CSHPORDMST.DELIVERY_ID = IF_SO_MST.INVOICE_TO_ORG_ID;


		memcpy(CSHPORDMST.DELIVERY_NAME, IF_SO_MST.INVOICE_TO_ORG_NAME, sizeof(IF_SO_MST.INVOICE_TO_ORG_NAME));

		memcpy(CSHPORDMST.DELIVERY_LOCATION, IF_SO_MST.SHIP_TO_ADDRESS, sizeof(IF_SO_MST.SHIP_TO_ADDRESS));

		memcpy(CSHPORDMST.DELIVERY_PHONE_NO, IF_SO_MST.CUST_PHONE_NUMBER, sizeof(IF_SO_MST.CUST_PHONE_NUMBER));

		memcpy(CSHPORDMST.DELIVERY_USER_ID, IF_SO_MST.CUST_CONTACT_NAME, sizeof(IF_SO_MST.CUST_CONTACT_NAME));
		
		// 업데이트 하기전에 IF 상태값 확인
		// OPEN : DELETE_FLAG = ' '로 변경
		// CLOSE : DELETE_FALG = 'Y'로 변경
		if (IF_SO_MST.SHIPPING_STATUS == 'O')
		{
			CSHPORDMST.DELETE_FLAG = ' ';

			//DTL이 먼저 INSERT되고, MST가 후에 INSERT되는 경우
			//MST정보를 이용하여 DTL 기록이 있는지 체크
			//있다면, 해당 OPER를 조회하여 MST 생성 시 OPER 값 UPDATE
			DBU_init_if_so_dtl_his(&IF_SO_DTL_HIS);
			memcpy(IF_SO_DTL_HIS.FACTORY, IF_SO_MST.FACTORY, sizeof(IF_SO_DTL_HIS.FACTORY));
			IF_SO_DTL_HIS.SHIPPING_HEADER_ID = IF_SO_MST.SHIPPING_HEADER_ID;
			i_dtl_count = (int)DBU_select_if_so_dtl_his_scalar(2, &IF_SO_DTL_HIS);

			if (i_dtl_count > 0)
			{
				DBU_init_if_so_dtl_his(&IF_SO_DTL_HIS);
				memcpy(IF_SO_DTL_HIS.FACTORY, IF_SO_MST.FACTORY, sizeof(IF_SO_DTL_HIS.FACTORY));
				IF_SO_DTL_HIS.SHIPPING_HEADER_ID = IF_SO_MST.SHIPPING_HEADER_ID;
				DBU_select_if_so_dtl_his(2, &IF_SO_DTL_HIS);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND) {
					DB_rollback();

					//INV-0055 : 하위 출하 DETAIL 데이터가 존재하지 않습니다.
					strcpy(s_msg_code, "INV-0055");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_DTL.IF_CODE = 'E';
					memcpy(IF_SO_DTL.IF_MSG, Error_Msg, strlen(IF_SO_DTL.IF_MSG));
					DBU_update_if_so_dtl(101, &IF_SO_DTL);
					DB_commit();
					continue;
				}

				if (DB_error_code == DB_SUCCESS)
				{
					// MST에 OPER를 업데이트해준다.
					// MWIPOPRDEF에서 ERP OPER를 가지고 찾아온다.
					DBU_init_mwipoprdef(&MWIPOPRDEF);
					memcpy(MWIPOPRDEF.FACTORY, CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY));
					memcpy(MWIPOPRDEF.AREA_ID, CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
					memcpy(MWIPOPRDEF.OPER_CMF_1, IF_SO_DTL_HIS.SHIP_FROM_INV_OPER, sizeof(IF_SO_DTL_HIS.SHIP_FROM_INV_OPER));
					DBU_select_mwipoprdef(10, &MWIPOPRDEF);
					if (DB_error_code != DB_SUCCESS)
					{
						DB_rollback();

						//WIP-0600 : 출하 대기 창고를 찾을 수 없습니다.
						strcpy(s_msg_code, "WIP-0600");
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						IF_SO_DTL.IF_CODE = 'E';
						memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
						DBU_update_if_so_dtl(101, &IF_SO_DTL);
						DB_commit();
						continue;
					}

					memcpy(CSHPORDMST.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				}
			}
		}
		else if (IF_SO_MST.SHIPPING_STATUS == 'C')
		{
			CSHPORDMST.DELETE_FLAG = 'Y';

			//Data가 없는데 CLOSE가 오면 에러
			// ERP에서 생성 후, MES에 I/F가 내려오지 않은 상태에서 CLOSE가 날라오면, 에러지만 HISTORY로 데이터 이동 처리.
			if (procStep == MP_STEP_CREATE)
			{
				DB_rollback();

				//WIP-0664 : 이 출하지시는 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0664");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_MST.IF_CODE = 'E';
				memcpy(IF_SO_MST.IF_MSG, Error_Msg, sizeof(IF_SO_MST.IF_MSG));

				// BACKUP
				DBU_init_if_so_mst_his(&IF_SO_MST_HIS);

				IF_SO_MST_HIS.IF_SEQ = IF_SO_MST.IF_SEQ;

				DBU_delete_if_so_mst_his(1, &IF_SO_MST_HIS);
				DBU_insert_if_so_mst_his((struct IF_SO_MST_HIS_TAG *)&IF_SO_MST);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "BAS-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_fieldmsg(out_node, "IF_SO_MST_HIS INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;
					COM_set_field_db_msg(out_node, out_node);
					return MP_FALSE;
				}

				// DELETE
				DBU_delete_if_so_mst(1, &IF_SO_MST);
				DB_commit();

				continue;
			}
		}

		if (procStep == MP_STEP_CREATE)
		{
			memcpy(CSHPORDMST.SHIP_ORD_STATUS, MP_STATUS_WAIT, strlen(MP_STATUS_WAIT));
			memcpy(CSHPORDMST.CREATE_TIME, gs_sys_time, sizeof(CSHPORDMST.CREATE_TIME));
			memcpy(CSHPORDMST.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
			DBU_insert_cshpordmst(&CSHPORDMST);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_MST.IF_CODE = 'E';
				memcpy(IF_SO_MST.IF_MSG, Error_Msg, sizeof(IF_SO_MST.IF_MSG));
				DBU_update_if_so_mst(101, &IF_SO_MST);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			memcpy(CSHPORDMST.UPDATE_TIME, gs_sys_time, sizeof(CSHPORDMST.UPDATE_TIME));
			memcpy(CSHPORDMST.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
			DBU_update_cshpordmst(1, &CSHPORDMST);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_MST.IF_CODE = 'E';
				memcpy(IF_SO_MST.IF_MSG, Error_Msg, sizeof(IF_SO_MST.IF_MSG));
				DBU_update_if_so_mst(101, &IF_SO_MST);
				DB_commit();
				continue;
			}

			// MST가 삭제라면, DTL도 모두 삭제 처리
			if (CSHPORDMST.DELETE_FLAG == 'Y')
			{
				DBU_init_cshporddtl(&CSHPORDDTL);
				memcpy(CSHPORDDTL.FACTORY, CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY));
				memcpy(CSHPORDDTL.SHIP_ORDER_ID, CSHPORDMST.SHIP_ORDER_ID, sizeof(CSHPORDMST.SHIP_ORDER_ID));
				CSHPORDDTL.DELETE_FLAG = 'Y';
				memcpy(CSHPORDDTL.UPDATE_TIME, gs_sys_time, sizeof(CSHPORDDTL.UPDATE_TIME));
				memcpy(CSHPORDDTL.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
				DBU_update_cshporddtl(2, &CSHPORDDTL);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					DB_rollback();

					strcpy(s_msg_code, "INV-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_MST.IF_CODE = 'E';
					memcpy(IF_SO_MST.IF_MSG, Error_Msg, sizeof(IF_SO_MST.IF_MSG));
					DBU_update_if_so_mst(101, &IF_SO_MST);
					DB_commit();
					continue;
				}
			}
		}

		// BACKUP
		DBU_init_if_so_mst_his(&IF_SO_MST_HIS);

		IF_SO_MST_HIS.IF_SEQ = IF_SO_MST.IF_SEQ;

		DBU_delete_if_so_mst_his(1, &IF_SO_MST_HIS);
		DBU_insert_if_so_mst_his((struct IF_SO_MST_HIS_TAG *)&IF_SO_MST);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_SO_MST_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_so_mst(1, &IF_SO_MST);

		DB_commit();
	}

	//해당하는 출하 DTL 조회
	DBU_init_if_so_dtl(&IF_SO_DTL);
	DBU_open_if_so_dtl(i_step, &IF_SO_DTL);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_SO_DTL OPEN(101)", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_so_dtl(i_step, &IF_SO_DTL);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_so_dtl(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "IF_SO_DTL FETCH(101)", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_SO_DTL.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_SO_DTL.FACTORY), IF_SO_DTL.FACTORY);
			TRS.add_fieldmsg(out_node, "SHIPPING_HEADER_ID", MP_INT, IF_SO_DTL.SHIPPING_HEADER_ID);
			TRS.add_fieldmsg(out_node, "SHIPPING_LINE_ID", MP_INT, IF_SO_DTL.SHIPPING_LINE_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			DBU_close_if_so_dtl(i_step);

			return MP_FALSE;
		}

		// INSERT DELIVERY DETAIL TABLE
		/*FACTORY	1	VARCHAR2	10	공장
		SHIP_ORDER_ID	2	VARCHAR2	25	출하 지시 번호
		SEQ	3	NUMBER	10	순번
		MAT_ID		VARCHAR2	30	제품
		MAT_VER		NUMBER	10	버전
		QTY		NUMBER	10,3	출하요청수량
		SHIPPED_QTY		NUMBER	10,3	출하완료수량
		UNIT		VARCHAR2	10	단위
		SHIP_ORD_STATUS		VARCHAR2	10	상태
		SHIP_DATE		VARCHAR2	14	출하 일시
		PACK_ORDER_ID		VARCHAR2	25	포장 지시 번호
		PACK_LINE_NO		NUMBER	10	포장 지시 라인 번호*/

		DBU_init_cshporddtl(&CSHPORDDTL);
		memcpy(CSHPORDDTL.FACTORY, IF_SO_DTL.FACTORY, sizeof(IF_SO_DTL.FACTORY));
		COM_itoa_left(CSHPORDDTL.SHIP_ORDER_ID, IF_SO_DTL.SHIPPING_HEADER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
		CSHPORDDTL.SEQ = IF_SO_DTL.SHIPPING_LINE_NUM;
		DBU_select_cshporddtl(1, &CSHPORDDTL);
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

			IF_SO_DTL.IF_CODE = 'E';
			memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
			DBU_update_if_so_dtl(101, &IF_SO_DTL);
			DB_commit();
			continue;
		}

		/*FACTORY	1	VARCHAR2	10	공장
		SHIP_ORDER_ID	2	VARCHAR2	25	출하 지시 번호
		SEQ	3	NUMBER	10	순번
		MAT_ID		VARCHAR2	30	제품
		MAT_VER		NUMBER	10	버전
		QTY		NUMBER	10,3	출하요청수량
		SHIPPED_QTY		NUMBER	10,3	출하완료수량
		UNIT		VARCHAR2	10	단위
		SHIP_ORD_STATUS		VARCHAR2	10	상태
		SHIP_DATE		VARCHAR2	14	출하 일시
		PACK_ORDER_ID		VARCHAR2	25	포장 지시 번호
		PACK_LINE_NO		NUMBER	10	포장 지시 라인 번호*/

		COM_itoa_left(CSHPORDDTL.SHIP_ORDER_ID, IF_SO_DTL.SHIPPING_HEADER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
		CSHPORDDTL.SEQ = IF_SO_DTL.SHIPPING_LINE_NUM;
		memcpy(CSHPORDDTL.MAT_ID, IF_SO_DTL.ITEM_CODE, sizeof(IF_SO_DTL.ITEM_CODE));
		CSHPORDDTL.MAT_VER = 1;

		//수정인 경우
		if (procStep == MP_STEP_UPDATE)
		{
			//출하수량이 현재 수량보다 클때
			if (CSHPORDDTL.QTY < IF_SO_DTL.SHIPPING_QTY)
			{
				if (CSHPORDDTL.DELETE_FLAG == 'Y')
				{
					DB_rollback();
					//WIP-0603 : 해당 출하지시는 종료되었습니다.
					strcpy(s_msg_code, "WIP-0603");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_DTL.IF_CODE = 'E';
					memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
					DBU_update_if_so_dtl(101, &IF_SO_DTL);
					DB_commit();
					continue;
				}
			}
			else if (CSHPORDDTL.QTY > IF_SO_DTL.SHIPPING_QTY)
			{
				if (CSHPORDDTL.DELETE_FLAG == 'Y')
				{
					DB_rollback();
					//WIP-0603 : 해당 출하지시는 종료되었습니다.
					strcpy(s_msg_code, "WIP-0603");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_DTL.IF_CODE = 'E';
					memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
					DBU_update_if_so_dtl(101, &IF_SO_DTL);
					DB_commit();
					continue;
				}
			}
		}
		else if (procStep == MP_STEP_CREATE)
		{
			CSHPORDDTL.SHIPPED_QTY = 0;
			memcpy(CSHPORDDTL.SHIP_ORD_STATUS, MP_STATUS_WAIT, strlen(MP_STATUS_WAIT));
		}

		CSHPORDDTL.QTY = IF_SO_DTL.SHIPPING_QTY;
		memcpy(CSHPORDDTL.UNIT, IF_SO_DTL.SHIPPING_UOM, sizeof(IF_SO_DTL.SHIPPING_UOM));
		memcpy(CSHPORDDTL.SHIP_DATE, IF_SO_DTL.SHIPPING_DATE, sizeof(IF_SO_DTL.SHIPPING_DATE));

		COM_itoa_left(CSHPORDDTL.PACK_ORDER_ID, IF_SO_DTL.OE_HEADER_ID, sizeof(CSHPORDDTL.PACK_ORDER_ID));
		CSHPORDDTL.PACK_LINE_NO = IF_SO_DTL.LINE_NUMBER;
		CSHPORDDTL.SHIPPING_LINE_ID = IF_SO_DTL.SHIPPING_LINE_ID;
		memcpy(CSHPORDDTL.UPDATE_TIME, gs_sys_time, sizeof(CSHPORDDTL.UPDATE_TIME));
		memcpy(CSHPORDDTL.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

		if (procStep == MP_STEP_CREATE)
		{
			//출하헤더ID, 라인NUM이 0이면, 취소되는 데이터.
			//ERP에서 MST정보를 먼저 삭제하면서 DTL의 헤더 정보를 찾을 수 없다고 함.
			//따라서 그냥 무시하는 데이터로 변경.
			//RELEASED_STATUS가 C면 무시
			if (IF_SO_DTL.SHIPPING_HEADER_ID == 0 || IF_SO_DTL.SHIPPING_LINE_NUM == 0 || IF_SO_DTL.RELEASED_STATUS == 'C')
			{
				// BACKUP
				DBU_init_if_so_dtl_his(&IF_SO_DTL_HIS);

				IF_SO_DTL_HIS.IF_SEQ = IF_SO_DTL.IF_SEQ;

				DBU_delete_if_so_dtl_his(1, &IF_SO_DTL_HIS);
				DBU_insert_if_so_dtl_his((struct IF_SO_DTL_HIS_TAG *)&IF_SO_DTL);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "BAS-0004");
					TRS.add_fieldmsg(out_node, "IF_SO_DTL_HIS INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;
					COM_set_field_db_msg(out_node, out_node);
					return MP_FALSE;
				}

				// DELETE
				DBU_delete_if_so_dtl(1, &IF_SO_DTL);

				DB_commit();

				continue;
			}

			memcpy(CSHPORDDTL.CREATE_TIME, gs_sys_time, sizeof(CSHPORDDTL.CREATE_TIME));
			memcpy(CSHPORDDTL.CREATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
			DBU_insert_cshporddtl(&CSHPORDDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_DTL.IF_CODE = 'E';
				memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
				DBU_update_if_so_dtl(101, &IF_SO_DTL);
				DB_commit();
				continue;
			}
		}
		else if (procStep == MP_STEP_UPDATE)
		{
			//만약 DETAIL 정보의 상태가 CLOSE로 오면 해당 DETAIL 삭제처리 
			if (IF_SO_DTL.RELEASED_STATUS == 'C')
			{
				CSHPORDDTL.DELETE_FLAG = 'Y';
			}

			DBU_update_cshporddtl(1, &CSHPORDDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_DTL.IF_CODE = 'E';
				memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
				DBU_update_if_so_dtl(101, &IF_SO_DTL);
				DB_commit();
				continue;
			}
		}

		// Detail 에 창고가 있으면 Master 에 창고 업데이트 한다.
		if (COM_isnullspace(IF_SO_DTL.SHIP_FROM_INV_OPER) == MP_FALSE)
		{
			// 출하지시 마스터 조회
			// 출하지시 MST존재하는지 확인
			DBU_init_cshpordmst(&CSHPORDMST);
			memcpy(CSHPORDMST.FACTORY, CSHPORDDTL.FACTORY, sizeof(CSHPORDDTL.FACTORY));
			memcpy(CSHPORDMST.SHIP_ORDER_ID, CSHPORDDTL.SHIP_ORDER_ID, sizeof(CSHPORDDTL.SHIP_ORDER_ID));
			DBU_select_cshpordmst(1, &CSHPORDMST);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND) {
				DB_rollback();

				strcpy(s_msg_code, "INV-0004");
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_SO_DTL.IF_CODE = 'E';
				memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
				DBU_update_if_so_dtl(101, &IF_SO_DTL);
				DB_commit();
				continue;
			}

			if (DB_error_code == DB_SUCCESS)
			{
				// MST에 OPER를 업데이트해준다.
				// MWIPOPRDEF에서 ERP OPER를 가지고 찾아온다.
				DBU_init_mwipoprdef(&MWIPOPRDEF);
				memcpy(MWIPOPRDEF.FACTORY, CSHPORDMST.FACTORY, sizeof(CSHPORDMST.FACTORY));
				memcpy(MWIPOPRDEF.AREA_ID, CSHPORDMST.AREA_ID, sizeof(CSHPORDMST.AREA_ID));
				memcpy(MWIPOPRDEF.OPER_CMF_1, IF_SO_DTL.SHIP_FROM_INV_OPER, sizeof(IF_SO_DTL.SHIP_FROM_INV_OPER));
				DBU_select_mwipoprdef(10, &MWIPOPRDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "INV-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_DTL.IF_CODE = 'E';
					memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
					DBU_update_if_so_dtl(101, &IF_SO_DTL);
					DB_commit();
					continue;
				}

				memcpy(CSHPORDMST.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_update_cshpordmst(3, &CSHPORDMST);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();

					strcpy(s_msg_code, "INV-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_SO_DTL.IF_CODE = 'E';
					memcpy(IF_SO_DTL.IF_MSG, Error_Msg, sizeof(IF_SO_DTL.IF_MSG));
					DBU_update_if_so_dtl(101, &IF_SO_DTL);
					DB_commit();
					continue;
				}
			}
		}

		// BACKUP
		DBU_init_if_so_dtl_his(&IF_SO_DTL_HIS);

		IF_SO_DTL_HIS.IF_SEQ = IF_SO_DTL.IF_SEQ;

		DBU_delete_if_so_dtl_his(1, &IF_SO_DTL_HIS);
		DBU_insert_if_so_dtl_his((struct IF_SO_DTL_HIS_TAG *)&IF_SO_DTL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			TRS.add_fieldmsg(out_node, "IF_SO_DTL_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_so_dtl(1, &IF_SO_DTL);

		DB_commit();
	}

	return MP_TRUE;
}

