/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_common_function.c
    Description : Transaction common INV Function

    MES Version : 5.2.0

    Function List 

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/03  Miracom         Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <CUS_INV_common.h>
 

/*******************************************************************************
    CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY()
        - Update Inv Lot and Insert Inv Lot History
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code                      : Error Message Code 
        - TRSNode *in_node                      : Input TRS Node
        - TRSNode *out_node                     : Output TRS Node
        - char *s_sys_time                      : System Transaction Time
        - struct MINVLOTSTS_TAG *MINVLOTSTS_OLD : Old INV Lot Status Info
        - struct MINVLOTSTS_TAG *MINVLOTSTS        : New INV Lot Status Info
        - struct MINVLOTHIS_TAG *MINVLOTHIS        : Insert INV Lot History Info
*******************************************************************************/
int CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node,
                                         char *s_sys_time_t,
                                         struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
                                         struct MINVLOTSTS_TAG *MINVLOTSTS,
                                         struct MINVLOTHIS_TAG *MINVLOTHIS)
{	
	struct MINVLOTHIS_TAG MINVLOTHIS_MAXSEQ;

    char s_sys_time[14];
	int i_histSeq = 0;

    COM_memcpy(s_sys_time, s_sys_time_t, sizeof(s_sys_time));
	
	memcpy(MINVLOTHIS->INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTHIS->INV_LOT_ID));

	DBU_init_minvlothis(&MINVLOTHIS_MAXSEQ);
	TRS.copy(MINVLOTHIS_MAXSEQ.FACTORY, sizeof(MINVLOTHIS_MAXSEQ.FACTORY), in_node, IN_FACTORY);
	memcpy(MINVLOTHIS_MAXSEQ.INV_LOT_ID, MINVLOTHIS->INV_LOT_ID, sizeof(MINVLOTHIS_MAXSEQ.INV_LOT_ID));
	// MINVLOTHIS - 자재 LOT 이력 마지막 시퀀스 조회
	i_histSeq = (int)DBU_select_minvlothis_scalar(2, &MINVLOTHIS_MAXSEQ);

	//자재 LOT 이력 시퀀스 체크
	if (MINVLOTSTS->LAST_HIST_SEQ != i_histSeq + 1)
	{
		MINVLOTSTS->LAST_HIST_SEQ = i_histSeq + 1;
		MINVLOTSTS->LAST_ACTIVE_HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
	}

	//자재 LOT 이력 데이터 생성(자재 LOT 데이터를 이용하여 이력 생성)
	memcpy(MINVLOTHIS->FACTORY, MINVLOTSTS->FACTORY, sizeof(MINVLOTHIS->FACTORY));
	memcpy(MINVLOTHIS->INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTHIS->INV_LOT_ID));
	MINVLOTHIS->HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
	memcpy(MINVLOTHIS->INV_LOT_DESC, MINVLOTSTS->INV_LOT_DESC, sizeof(MINVLOTHIS->INV_LOT_DESC));
	memcpy(MINVLOTHIS->INV_LOT_TYPE, MINVLOTSTS->INV_LOT_TYPE, sizeof(MINVLOTHIS->INV_LOT_TYPE));
	memcpy(MINVLOTHIS->TRAN_CODE, MINVLOTSTS->LAST_TRAN_CODE, sizeof(MINVLOTHIS->TRAN_CODE));
	TRS.copy(MINVLOTHIS->TRAN_USER_ID, sizeof(MINVLOTHIS->TRAN_USER_ID), in_node, IN_USERID);
	memcpy(MINVLOTHIS->TRAN_TIME, MINVLOTSTS->LAST_TRAN_TIME, sizeof(MINVLOTHIS->TRAN_TIME));
	memcpy(MINVLOTHIS->SYS_TRAN_TIME, s_sys_time, sizeof(MINVLOTHIS->SYS_TRAN_TIME));
	memcpy(MINVLOTHIS->TRAN_COMMENT, MINVLOTSTS->LAST_TRAN_COMMENT, sizeof(MINVLOTHIS->TRAN_COMMENT));
	memcpy(MINVLOTHIS->INV_LOT_STATUS, MINVLOTSTS->INV_LOT_STATUS, sizeof(MINVLOTHIS->INV_LOT_STATUS));
	MINVLOTHIS->INV_LOT_PRIORITY = MINVLOTSTS->INV_LOT_PRIORITY;
	memcpy(MINVLOTHIS->MAT_ID, MINVLOTSTS->MAT_ID, sizeof(MINVLOTHIS->MAT_ID));
	MINVLOTHIS->MAT_VER = MINVLOTSTS->MAT_VER;
	MINVLOTHIS->QTY = MINVLOTSTS->QTY;
	MINVLOTHIS->QTY_2 = MINVLOTSTS->QTY_2;
	MINVLOTHIS->QTY_3 = MINVLOTSTS->QTY_3;
	memcpy(MINVLOTHIS->UNIT, MINVLOTSTS->UNIT, sizeof(MINVLOTHIS->UNIT));
	memcpy(MINVLOTHIS->UNIT_2, MINVLOTSTS->UNIT_2, sizeof(MINVLOTHIS->UNIT_2));
	memcpy(MINVLOTHIS->UNIT_3, MINVLOTSTS->UNIT_3, sizeof(MINVLOTHIS->UNIT_3));
	memcpy(MINVLOTHIS->ORDER_ID, MINVLOTSTS->ORDER_ID, sizeof(MINVLOTHIS->ORDER_ID));
	memcpy(MINVLOTHIS->ADD_ORDER_ID_1, MINVLOTSTS->ADD_ORDER_ID_1, sizeof(MINVLOTHIS->ADD_ORDER_ID_1));
	memcpy(MINVLOTHIS->ADD_ORDER_ID_2, MINVLOTSTS->ADD_ORDER_ID_2, sizeof(MINVLOTHIS->ADD_ORDER_ID_2));
	memcpy(MINVLOTHIS->ADD_ORDER_ID_3, MINVLOTSTS->ADD_ORDER_ID_3, sizeof(MINVLOTHIS->ADD_ORDER_ID_3));
	memcpy(MINVLOTHIS->VENDOR_ID, MINVLOTSTS->VENDOR_ID, sizeof(MINVLOTHIS->VENDOR_ID));
	MINVLOTHIS->VENDOR_SITE_ID = MINVLOTSTS->VENDOR_SITE_ID;
	memcpy(MINVLOTHIS->VENDOR_LOT_ID, MINVLOTSTS->VENDOR_LOT_ID, sizeof(MINVLOTHIS->VENDOR_LOT_ID));
	memcpy(MINVLOTHIS->AREA_ID, MINVLOTSTS->AREA_ID, sizeof(MINVLOTHIS->AREA_ID));
	memcpy(MINVLOTHIS->SUB_AREA_ID, MINVLOTSTS->SUB_AREA_ID, sizeof(MINVLOTHIS->SUB_AREA_ID));
	memcpy(MINVLOTHIS->LOCATION_1, MINVLOTSTS->LOCATION_1, sizeof(MINVLOTHIS->LOCATION_1));
	memcpy(MINVLOTHIS->LOCATION_2, MINVLOTSTS->LOCATION_2, sizeof(MINVLOTHIS->LOCATION_2));
	memcpy(MINVLOTHIS->LOCATION_3, MINVLOTSTS->LOCATION_3, sizeof(MINVLOTHIS->LOCATION_3));
	memcpy(MINVLOTHIS->OPER, MINVLOTSTS->OPER, sizeof(MINVLOTHIS->OPER));
	memcpy(MINVLOTHIS->LOC_NO, MINVLOTSTS->LOC_NO, sizeof(MINVLOTHIS->LOC_NO));
	memcpy(MINVLOTHIS->RES_ID, MINVLOTSTS->RES_ID, sizeof(MINVLOTHIS->RES_ID));
	memcpy(MINVLOTHIS->PORT_ID, MINVLOTSTS->PORT_ID, sizeof(MINVLOTHIS->PORT_ID));
	memcpy(MINVLOTHIS->SLOT_NO, MINVLOTSTS->SLOT_NO, sizeof(MINVLOTHIS->SLOT_NO));
	memcpy(MINVLOTHIS->CRR_ID, MINVLOTSTS->CRR_ID, sizeof(MINVLOTHIS->CRR_ID));
	memcpy(MINVLOTHIS->LOT_ID, MINVLOTSTS->LOT_ID, sizeof(MINVLOTHIS->LOT_ID));
	memcpy(MINVLOTHIS->RECV_DATE, MINVLOTSTS->RECV_DATE, sizeof(MINVLOTHIS->RECV_DATE));
	MINVLOTHIS->RECV_QTY = MINVLOTSTS->RECV_QTY;
	memcpy(MINVLOTHIS->REASON_CODE, MINVLOTSTS->REASON_CODE, sizeof(MINVLOTHIS->REASON_CODE));
	MINVLOTHIS->LOAD_FLAG = MINVLOTSTS->LOAD_FLAG;
	MINVLOTHIS->TRANSIT_FLAG = MINVLOTSTS->TRANSIT_FLAG;
	MINVLOTHIS->DELETE_FLAG = MINVLOTSTS->DELETE_FLAG;
	memcpy(MINVLOTHIS->DELETE_CODE, MINVLOTSTS->DELETE_CODE, sizeof(MINVLOTHIS->DELETE_CODE));
	memcpy(MINVLOTHIS->DELETE_TIME, MINVLOTSTS->DELETE_TIME, sizeof(MINVLOTHIS->DELETE_TIME));
	MINVLOTHIS->HOLD_FLAG = MINVLOTSTS->HOLD_FLAG;
	memcpy(MINVLOTHIS->HOLD_CODE, MINVLOTSTS->HOLD_CODE, sizeof(MINVLOTHIS->HOLD_CODE));
	MINVLOTHIS->INSP_FLAG = MINVLOTSTS->INSP_FLAG;
	memcpy(MINVLOTHIS->INSP_ID, MINVLOTSTS->INSP_ID, sizeof(MINVLOTHIS->INSP_ID));
	MINVLOTHIS->INSP_RESULT_FLAG = MINVLOTSTS->INSP_RESULT_FLAG;
	memcpy(MINVLOTHIS->INV_LOT_GRADE, MINVLOTSTS->INV_LOT_GRADE, sizeof(MINVLOTHIS->INV_LOT_GRADE));
	memcpy(MINVLOTHIS->DLV_NO, MINVLOTSTS->DLV_NO, sizeof(MINVLOTHIS->DLV_NO));
	MINVLOTHIS->DLV_SEQ = MINVLOTSTS->DLV_SEQ;
	memcpy(MINVLOTHIS->PO_NO, MINVLOTSTS->PO_NO, sizeof(MINVLOTHIS->PO_NO));
	MINVLOTHIS->PO_SEQ = MINVLOTSTS->PO_SEQ;
	memcpy(MINVLOTHIS->BL_NO, MINVLOTSTS->BL_NO, sizeof(MINVLOTHIS->BL_NO));
	MINVLOTHIS->BL_SEQ = MINVLOTSTS->BL_SEQ;
	MINVLOTHIS->PO_DISTRIBUTION_ID = MINVLOTSTS->PO_DISTRIBUTION_ID;
	memcpy(MINVLOTHIS->INV_CMF_1, MINVLOTSTS->INV_CMF_1, sizeof(MINVLOTHIS->INV_CMF_1));
	memcpy(MINVLOTHIS->INV_CMF_2, MINVLOTSTS->INV_CMF_2, sizeof(MINVLOTHIS->INV_CMF_2));
	memcpy(MINVLOTHIS->INV_CMF_3, MINVLOTSTS->INV_CMF_3, sizeof(MINVLOTHIS->INV_CMF_3));
	memcpy(MINVLOTHIS->INV_CMF_4, MINVLOTSTS->INV_CMF_4, sizeof(MINVLOTHIS->INV_CMF_4));
	memcpy(MINVLOTHIS->INV_CMF_5, MINVLOTSTS->INV_CMF_5, sizeof(MINVLOTHIS->INV_CMF_5));
	memcpy(MINVLOTHIS->INV_CMF_6, MINVLOTSTS->INV_CMF_6, sizeof(MINVLOTHIS->INV_CMF_6));
	memcpy(MINVLOTHIS->INV_CMF_7, MINVLOTSTS->INV_CMF_7, sizeof(MINVLOTHIS->INV_CMF_7));
	memcpy(MINVLOTHIS->INV_CMF_8, MINVLOTSTS->INV_CMF_8, sizeof(MINVLOTHIS->INV_CMF_8));
	memcpy(MINVLOTHIS->INV_CMF_9, MINVLOTSTS->INV_CMF_9, sizeof(MINVLOTHIS->INV_CMF_9));
	memcpy(MINVLOTHIS->INV_CMF_10, MINVLOTSTS->INV_CMF_10, sizeof(MINVLOTHIS->INV_CMF_10));
	memcpy(MINVLOTHIS->INV_CMF_11, MINVLOTSTS->INV_CMF_11, sizeof(MINVLOTHIS->INV_CMF_11));
	memcpy(MINVLOTHIS->INV_CMF_12, MINVLOTSTS->INV_CMF_12, sizeof(MINVLOTHIS->INV_CMF_12));
	memcpy(MINVLOTHIS->INV_CMF_13, MINVLOTSTS->INV_CMF_13, sizeof(MINVLOTHIS->INV_CMF_13));
	memcpy(MINVLOTHIS->INV_CMF_14, MINVLOTSTS->INV_CMF_14, sizeof(MINVLOTHIS->INV_CMF_14));
	memcpy(MINVLOTHIS->INV_CMF_15, MINVLOTSTS->INV_CMF_15, sizeof(MINVLOTHIS->INV_CMF_15));
	memcpy(MINVLOTHIS->INV_CMF_16, MINVLOTSTS->INV_CMF_16, sizeof(MINVLOTHIS->INV_CMF_16));
	memcpy(MINVLOTHIS->INV_CMF_17, MINVLOTSTS->INV_CMF_17, sizeof(MINVLOTHIS->INV_CMF_17));
	memcpy(MINVLOTHIS->INV_CMF_18, MINVLOTSTS->INV_CMF_18, sizeof(MINVLOTHIS->INV_CMF_18));
	memcpy(MINVLOTHIS->INV_CMF_19, MINVLOTSTS->INV_CMF_19, sizeof(MINVLOTHIS->INV_CMF_19));
	memcpy(MINVLOTHIS->INV_CMF_20, MINVLOTSTS->INV_CMF_20, sizeof(MINVLOTHIS->INV_CMF_20));
	TRS.copy(MINVLOTHIS->TRAN_CMF_1, sizeof(MINVLOTHIS->TRAN_CMF_1), in_node, "TRAN_CMF_1");
	TRS.copy(MINVLOTHIS->TRAN_CMF_2, sizeof(MINVLOTHIS->TRAN_CMF_2), in_node, "TRAN_CMF_2");
	TRS.copy(MINVLOTHIS->TRAN_CMF_3, sizeof(MINVLOTHIS->TRAN_CMF_3), in_node, "TRAN_CMF_3");
	TRS.copy(MINVLOTHIS->TRAN_CMF_4, sizeof(MINVLOTHIS->TRAN_CMF_4), in_node, "TRAN_CMF_4");
	TRS.copy(MINVLOTHIS->TRAN_CMF_5, sizeof(MINVLOTHIS->TRAN_CMF_5), in_node, "TRAN_CMF_5");
	TRS.copy(MINVLOTHIS->TRAN_CMF_6, sizeof(MINVLOTHIS->TRAN_CMF_6), in_node, "TRAN_CMF_6");
	TRS.copy(MINVLOTHIS->TRAN_CMF_7, sizeof(MINVLOTHIS->TRAN_CMF_7), in_node, "TRAN_CMF_7");
	TRS.copy(MINVLOTHIS->TRAN_CMF_8, sizeof(MINVLOTHIS->TRAN_CMF_8), in_node, "TRAN_CMF_8");
	TRS.copy(MINVLOTHIS->TRAN_CMF_9, sizeof(MINVLOTHIS->TRAN_CMF_9), in_node, "TRAN_CMF_9");
	TRS.copy(MINVLOTHIS->TRAN_CMF_10, sizeof(MINVLOTHIS->TRAN_CMF_10), in_node, "TRAN_CMF_10");
	memcpy(MINVLOTHIS->ORG_INV_LOT_ID, MINVLOTSTS->ORG_INV_LOT_ID, sizeof(MINVLOTHIS->ORG_INV_LOT_ID));
	MINVLOTHIS->FROM_TO_DIV = MINVLOTSTS->FROM_TO_DIV;
	memcpy(MINVLOTHIS->FROM_TO_INV_LOT_ID, MINVLOTSTS->FROM_TO_INV_LOT_ID, sizeof(MINVLOTHIS->FROM_TO_INV_LOT_ID));
	MINVLOTHIS->FROM_TO_HIST_SEQ = MINVLOTSTS->FROM_TO_HIST_SEQ;
	MINVLOTHIS->OLD_ACTIVE_HIST_SEQ = MINVLOTSTS_OLD->LAST_ACTIVE_HIST_SEQ;
	memcpy(MINVLOTHIS->OLD_FACTORY, MINVLOTSTS_OLD->FACTORY, sizeof(MINVLOTHIS->OLD_FACTORY));
	memcpy(MINVLOTHIS->OLD_MAT_ID, MINVLOTSTS_OLD->MAT_ID, sizeof(MINVLOTHIS->OLD_MAT_ID));
	memcpy(MINVLOTHIS->OLD_AREA_ID, MINVLOTSTS_OLD->AREA_ID, sizeof(MINVLOTHIS->OLD_AREA_ID));
	memcpy(MINVLOTHIS->OLD_SUB_AREA_ID, MINVLOTSTS_OLD->SUB_AREA_ID, sizeof(MINVLOTHIS->OLD_SUB_AREA_ID));
	memcpy(MINVLOTHIS->OLD_OPER, MINVLOTSTS_OLD->OPER, sizeof(MINVLOTHIS->OLD_OPER));
	MINVLOTHIS->OLD_QTY = MINVLOTSTS_OLD->QTY;
	MINVLOTHIS->OLD_QTY_2 = MINVLOTSTS_OLD->QTY_2;
	MINVLOTHIS->OLD_QTY_3 = MINVLOTSTS_OLD->QTY_3;
	memcpy(MINVLOTHIS->OLD_UNIT, MINVLOTSTS_OLD->UNIT, sizeof(MINVLOTHIS->OLD_UNIT));
	memcpy(MINVLOTHIS->OLD_UNIT_2, MINVLOTSTS_OLD->UNIT_2, sizeof(MINVLOTHIS->OLD_UNIT_2));
	memcpy(MINVLOTHIS->OLD_UNIT_3, MINVLOTSTS_OLD->UNIT_3, sizeof(MINVLOTHIS->OLD_UNIT_3));
	MINVLOTHIS->CHANGE_QTY = fabs(MINVLOTSTS->QTY - MINVLOTSTS_OLD->QTY);
	MINVLOTHIS->CHANGE_QTY_2 = fabs(MINVLOTSTS->QTY_2 - MINVLOTSTS_OLD->QTY_2);
	MINVLOTHIS->CHANGE_QTY_3 = fabs(MINVLOTSTS->QTY_3 - MINVLOTSTS_OLD->QTY_3);
	MINVLOTHIS->CREATE_QTY = MINVLOTSTS->CREATE_QTY;
	MINVLOTHIS->CREATE_QTY_2 = MINVLOTSTS->CREATE_QTY_2;
	MINVLOTHIS->CREATE_QTY_3 = MINVLOTSTS->CREATE_QTY_3;
	memcpy(MINVLOTHIS->CREATE_USER_ID, MINVLOTSTS->CREATE_USER_ID, sizeof(MINVLOTHIS->CREATE_USER_ID));
	memcpy(MINVLOTHIS->CREATE_TIME, MINVLOTSTS->CREATE_TIME, sizeof(MINVLOTHIS->CREATE_TIME));
	memcpy(MINVLOTHIS->UPDATE_USER_ID, MINVLOTSTS->UPDATE_USER_ID, sizeof(MINVLOTHIS->UPDATE_USER_ID));
	memcpy(MINVLOTHIS->UPDATE_TIME, MINVLOTSTS->UPDATE_TIME, sizeof(MINVLOTHIS->UPDATE_TIME));
	MINVLOTHIS->HIST_DEL_FLAG = ' ';
	memset(MINVLOTHIS->HIST_DEL_USER_ID, ' ', sizeof(MINVLOTHIS->HIST_DEL_USER_ID));
	memset(MINVLOTHIS->HIST_DEL_TIME, ' ', sizeof(MINVLOTHIS->HIST_DEL_TIME));
	memset(MINVLOTHIS->HIST_DEL_COMMENT, ' ', sizeof(MINVLOTHIS->HIST_DEL_COMMENT));

	// MINVLOTSTS - 자재 LOT UPSERT
	DBU_update_minvlotsts(1, MINVLOTSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_insert_minvlotsts(MINVLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTSTS INSERT/UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS->FACTORY), MINVLOTSTS->FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTSTS->OPER), MINVLOTSTS->OPER);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS->INV_LOT_ID), MINVLOTSTS->INV_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVLOTSTS INSERT/UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS->FACTORY), MINVLOTSTS->FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTSTS->OPER), MINVLOTSTS->OPER);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS->INV_LOT_ID), MINVLOTSTS->INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	// MINVLOTHIS - 자재 LOT 이력 생성
	DBU_insert_minvlothis(MINVLOTHIS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVLOTHIS INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHIS->INV_LOT_ID), MINVLOTHIS->INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTHIS->HIST_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_INSERT_LOT_SWH_HISTORY()
- Insert Inv Lot Split/Merge History
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code                      : Error Message Code
- TRSNode *in_node                      : Input TRS Node
- TRSNode *out_node                     : Output TRS Node
- char *s_sys_time                      : System Transaction Time
- struct MINVLOTSTS_TAG *MINVLOTSTS_OLD : Old INV Lot Status Info
- struct MINVLOTSTS_TAG *MINVLOTSTS        : New INV Lot Status Info
*******************************************************************************/
int CUS_INV_INSERT_LOT_SWH_HISTORY(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node,
	char *s_sys_time_t,
	struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
	struct MINVLOTSTS_TAG *MINVLOTSTS,
	struct MINVLOTSTS_TAG *MINVLOTSTS_FT)
{
	struct MINVLOTSWH_TAG MINVLOTSWH;

	char s_sys_time[14];

	COM_memcpy(s_sys_time, s_sys_time_t, sizeof(s_sys_time));

	//자재 LOT 분할/병합 이력 데이터 생성
	DBU_init_minvlotswh(&MINVLOTSWH);
	memcpy(MINVLOTSWH.FACTORY, MINVLOTSTS->FACTORY, sizeof(MINVLOTSWH.FACTORY));
	memcpy(MINVLOTSWH.INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTSWH.INV_LOT_ID));
	MINVLOTSWH.HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
	memcpy(MINVLOTSWH.TRAN_CODE, MINVLOTSTS->LAST_TRAN_CODE, sizeof(MINVLOTSWH.TRAN_CODE));
	memcpy(MINVLOTSWH.TRAN_USER_ID, MINVLOTSTS->UPDATE_USER_ID, sizeof(MINVLOTSWH.TRAN_USER_ID));
	memcpy(MINVLOTSWH.TRAN_TIME, MINVLOTSTS->LAST_TRAN_TIME, sizeof(MINVLOTSWH.TRAN_TIME));
	memcpy(MINVLOTSWH.TRAN_COMMENT, MINVLOTSTS->LAST_TRAN_COMMENT, sizeof(MINVLOTSWH.TRAN_COMMENT));
	memcpy(MINVLOTSWH.MAT_ID, MINVLOTSTS->MAT_ID, sizeof(MINVLOTSWH.MAT_ID));
	MINVLOTSWH.MAT_VER = MINVLOTSTS->MAT_VER;
	MINVLOTSWH.QTY = MINVLOTSTS->QTY;
	MINVLOTSWH.QTY_2 = MINVLOTSTS->QTY_2;
	MINVLOTSWH.QTY_3 = MINVLOTSTS->QTY_3;
	memcpy(MINVLOTSWH.UNIT, MINVLOTSTS->UNIT, sizeof(MINVLOTSWH.UNIT));
	memcpy(MINVLOTSWH.UNIT_2, MINVLOTSTS->UNIT_2, sizeof(MINVLOTSWH.UNIT_2));
	memcpy(MINVLOTSWH.UNIT_3, MINVLOTSTS->UNIT_3, sizeof(MINVLOTSWH.UNIT_3));
	MINVLOTSWH.OLD_QTY = MINVLOTSTS_OLD->QTY;
	MINVLOTSWH.OLD_QTY_2 = MINVLOTSTS_OLD->QTY_2;
	MINVLOTSWH.OLD_QTY_3 = MINVLOTSTS_OLD->QTY_3;
	MINVLOTSWH.CHANGE_QTY = fabs(MINVLOTSTS->QTY - MINVLOTSTS_OLD->QTY);
	MINVLOTSWH.CHANGE_QTY_2 = fabs(MINVLOTSTS->QTY_2 - MINVLOTSTS_OLD->QTY_2);
	MINVLOTSWH.CHANGE_QTY_3 = fabs(MINVLOTSTS->QTY_3 - MINVLOTSTS_OLD->QTY_3);
	memcpy(MINVLOTSWH.OPER, MINVLOTSTS->OPER, sizeof(MINVLOTSWH.OPER));
	memcpy(MINVLOTSWH.RES_ID, MINVLOTSTS->RES_ID, sizeof(MINVLOTSWH.RES_ID));
	MINVLOTSWH.FROM_TO_DIV = MINVLOTSTS->FROM_TO_DIV;
	memcpy(MINVLOTSWH.FROM_TO_INV_LOT_ID, MINVLOTSTS->FROM_TO_INV_LOT_ID, sizeof(MINVLOTSWH.FROM_TO_INV_LOT_ID));
	MINVLOTSWH.FROM_TO_QTY = MINVLOTSTS_FT->QTY;
	MINVLOTSWH.FROM_TO_QTY_2 = MINVLOTSTS_FT->QTY_2;
	MINVLOTSWH.FROM_TO_QTY_3 = MINVLOTSTS_FT->QTY_3;
	MINVLOTSWH.HIST_DEL_FLAG = 'N';

	// MINVLOTSWH - 자재 LOT 분할/병합 이력 생성
	DBU_insert_minvlotswh(&MINVLOTSWH);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVLOTSWH INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSWH.INV_LOT_ID), MINVLOTSWH.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTSWH.HIST_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_INSERT_LOT_MVH_HISTORY()
- Insert Inv Lot Move History
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code                      : Error Message Code
- TRSNode *in_node                      : Input TRS Node
- TRSNode *out_node                     : Output TRS Node
- char *s_sys_time                      : System Transaction Time
- struct MINVLOTSTS_TAG *MINVLOTSTS_OLD : Old INV Lot Status Info
- struct MINVLOTSTS_TAG *MINVLOTSTS        : New INV Lot Status Info
*******************************************************************************/
int CUS_INV_INSERT_LOT_MVH_HISTORY(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node,
	char *s_sys_time_t,
	struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
	struct MINVLOTSTS_TAG *MINVLOTSTS)
{
	struct MINVLOTMVH_TAG MINVLOTMVH;

	char s_sys_time[14];

	COM_memcpy(s_sys_time, s_sys_time_t, sizeof(s_sys_time));

	//자재 LOT 이동 이력 데이터 생성
	DBU_init_minvlotmvh(&MINVLOTMVH);
	memcpy(MINVLOTMVH.FACTORY, MINVLOTSTS->FACTORY, sizeof(MINVLOTMVH.FACTORY));
	memcpy(MINVLOTMVH.INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTMVH.INV_LOT_ID));
	MINVLOTMVH.HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
	memcpy(MINVLOTMVH.TRAN_CODE, MINVLOTSTS->LAST_TRAN_CODE, sizeof(MINVLOTMVH.TRAN_CODE));
	memcpy(MINVLOTMVH.TRAN_USER_ID, MINVLOTSTS->UPDATE_USER_ID, sizeof(MINVLOTMVH.TRAN_USER_ID));
	memcpy(MINVLOTMVH.TRAN_TIME, MINVLOTSTS->LAST_TRAN_TIME, sizeof(MINVLOTMVH.TRAN_TIME));
	memcpy(MINVLOTMVH.MAT_ID, MINVLOTSTS->MAT_ID, sizeof(MINVLOTMVH.MAT_ID));
	MINVLOTMVH.MAT_VER = MINVLOTSTS->MAT_VER;
	memcpy(MINVLOTMVH.AREA_ID, MINVLOTSTS_OLD->AREA_ID, sizeof(MINVLOTMVH.AREA_ID));
	memcpy(MINVLOTMVH.SUB_AREA_ID, MINVLOTSTS_OLD->SUB_AREA_ID, sizeof(MINVLOTMVH.SUB_AREA_ID));
	memcpy(MINVLOTMVH.OPER, MINVLOTSTS_OLD->OPER, sizeof(MINVLOTMVH.OPER));
	memcpy(MINVLOTMVH.TO_AREA_ID, MINVLOTSTS->AREA_ID, sizeof(MINVLOTMVH.TO_AREA_ID));
	memcpy(MINVLOTMVH.TO_SUB_AREA_ID, MINVLOTSTS->SUB_AREA_ID, sizeof(MINVLOTMVH.TO_SUB_AREA_ID));
	memcpy(MINVLOTMVH.TO_OPER, MINVLOTSTS->OPER, sizeof(MINVLOTMVH.TO_OPER));
	MINVLOTMVH.TRAN_QTY = MINVLOTSTS->QTY;
	MINVLOTMVH.TRAN_QTY_2 = MINVLOTSTS->QTY_2;
	MINVLOTMVH.TRAN_QTY_3 = MINVLOTSTS->QTY_3;
	MINVLOTMVH.HIST_DEL_FLAG = 'N';

	// MINVLOTMVH - 자재 LOT 이동 이력 생성
	DBU_insert_minvlotmvh(&MINVLOTMVH);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVLOTMVH INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTMVH.INV_LOT_ID), MINVLOTMVH.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTMVH.HIST_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_INSERT_LOT_HLD_HISTORY()
- Insert Inv Lot Hold History
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code                      : Error Message Code
- TRSNode *in_node                      : Input TRS Node
- TRSNode *out_node                     : Output TRS Node
- char *s_sys_time                      : System Transaction Time
- struct MINVLOTSTS_TAG *MINVLOTSTS_OLD : Old INV Lot Status Info
- struct MINVLOTSTS_TAG *MINVLOTSTS        : New INV Lot Status Info
*******************************************************************************/
int CUS_INV_INSERT_LOT_HLD_HISTORY(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node,
	struct MINVLOTSTS_TAG *MINVLOTSTS)
{
	struct MINVLOTHLD_TAG MINVLOTHLD;
	struct MINVLOTHLD_TAG MINVLOTHLD_MAXSEQ;

	int i_histSeq = 0;

	if (TRS.get_procstep(in_node) == '1') //HOLD
	{
		//자재 LOT 이동 이력 데이터 생성
		DBU_init_minvlothld(&MINVLOTHLD);
		memcpy(MINVLOTHLD.FACTORY, MINVLOTSTS->FACTORY, sizeof(MINVLOTHLD.FACTORY));
		memcpy(MINVLOTHLD.INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTHLD.INV_LOT_ID));
		MINVLOTHLD.HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
		MINVLOTHLD.RELEASE_HIST_SEQ = 0;
		memcpy(MINVLOTHLD.MAT_ID, MINVLOTSTS->MAT_ID, sizeof(MINVLOTHLD.MAT_ID));
		MINVLOTHLD.MAT_VER = MINVLOTSTS->MAT_VER;
		MINVLOTHLD.QTY = MINVLOTSTS->QTY;
		MINVLOTHLD.QTY_2 = MINVLOTSTS->QTY_2;
		MINVLOTHLD.QTY_3 = MINVLOTSTS->QTY_3;
		memcpy(MINVLOTHLD.UNIT, MINVLOTSTS->UNIT, sizeof(MINVLOTHLD.UNIT));
		memcpy(MINVLOTHLD.UNIT_2, MINVLOTSTS->UNIT_2, sizeof(MINVLOTHLD.UNIT_2));
		memcpy(MINVLOTHLD.UNIT_3, MINVLOTSTS->UNIT_3, sizeof(MINVLOTHLD.UNIT_3));
		memcpy(MINVLOTHLD.OPER, MINVLOTSTS->OPER, sizeof(MINVLOTHLD.OPER));
		memcpy(MINVLOTHLD.HOLD_CODE, MINVLOTSTS->HOLD_CODE, sizeof(MINVLOTHLD.HOLD_CODE));
		MINVLOTHLD.HOLD_FLAG = MINVLOTSTS->HOLD_FLAG;
		memcpy(MINVLOTHLD.HOLD_USER_ID, MINVLOTSTS->UPDATE_USER_ID, sizeof(MINVLOTHLD.HOLD_USER_ID));
		memcpy(MINVLOTHLD.HOLD_TIME, MINVLOTSTS->LAST_TRAN_TIME, sizeof(MINVLOTHLD.HOLD_TIME));
		memcpy(MINVLOTHLD.HOLD_COMMENT, MINVLOTSTS->LAST_TRAN_COMMENT, sizeof(MINVLOTHLD.HOLD_COMMENT));
		memset(MINVLOTHLD.RELEASE_CODE, ' ', sizeof(MINVLOTHLD.RELEASE_CODE));
		memset(MINVLOTHLD.RELEASE_USER_ID, ' ', sizeof(MINVLOTHLD.RELEASE_USER_ID));
		memset(MINVLOTHLD.RELEASE_TIME, ' ', sizeof(MINVLOTHLD.RELEASE_TIME));
		memset(MINVLOTHLD.RELEASE_COMMENT, ' ', sizeof(MINVLOTHLD.RELEASE_COMMENT));
		MINVLOTHLD.HIST_DEL_FLAG = 'N';

		// MINVLOTHLD - 자재 LOT 잠금 이력 생성
		DBU_insert_minvlothld(&MINVLOTHLD);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVLOTHLD INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHLD.INV_LOT_ID), MINVLOTHLD.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTHLD.HIST_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '2') //RELEASE
	{
		// MINVLOTHLD - 자재 LOT 잠금 이력 마지막 시퀀스 조회
		DBU_init_minvlothld(&MINVLOTHLD_MAXSEQ);
		TRS.copy(MINVLOTHLD_MAXSEQ.FACTORY, sizeof(MINVLOTHLD_MAXSEQ.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVLOTHLD_MAXSEQ.INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTHLD_MAXSEQ.INV_LOT_ID));
		i_histSeq = (int)DBU_select_minvlothld_scalar(2, &MINVLOTHLD_MAXSEQ);

		//MINVLOTHLD - 자재 LOT 잠금 이력 조회
		DBU_init_minvlothld(&MINVLOTHLD);
		TRS.copy(MINVLOTHLD.FACTORY, sizeof(MINVLOTHLD.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVLOTHLD.INV_LOT_ID, MINVLOTSTS->INV_LOT_ID, sizeof(MINVLOTHLD.INV_LOT_ID));
		MINVLOTHLD.HIST_SEQ = i_histSeq;
		DBU_select_minvlothld(1, &MINVLOTHLD);
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
			TRS.add_fieldmsg(out_node, "MINVLOTHLD SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTHLD.FACTORY), MINVLOTHLD.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHLD.INV_LOT_ID), MINVLOTHLD.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTHLD.INV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// RELEASE 데이터 구성
		MINVLOTHLD.RELEASE_HIST_SEQ = MINVLOTSTS->LAST_HIST_SEQ;
		MINVLOTHLD.HOLD_FLAG = MINVLOTSTS->HOLD_FLAG;
		TRS.copy(MINVLOTHLD.RELEASE_CODE, sizeof(MINVLOTHLD.RELEASE_CODE), in_node, "RELEASE_CODE");
		memcpy(MINVLOTHLD.RELEASE_USER_ID, MINVLOTSTS->UPDATE_USER_ID, sizeof(MINVLOTHLD.RELEASE_USER_ID));
		memcpy(MINVLOTHLD.RELEASE_TIME, MINVLOTSTS->LAST_TRAN_TIME, sizeof(MINVLOTHLD.RELEASE_TIME));
		memcpy(MINVLOTHLD.RELEASE_COMMENT, MINVLOTSTS->LAST_TRAN_COMMENT, sizeof(MINVLOTHLD.RELEASE_COMMENT));

		//MINVLOTHLD - RELEASE 데이터 업데이트
		DBU_update_minvlothld(1, &MINVLOTHLD);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVLOTHLD UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTHLD.FACTORY), MINVLOTHLD.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTHLD.INV_LOT_ID), MINVLOTHLD.INV_LOT_ID);
			TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVLOTHLD.HIST_SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_INSERT_LOT_MAT_ISS_HISTORY()
- Insert Inv Lot Mat Issue History
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code                      : Error Message Code
- TRSNode *in_node                      : Input TRS Node
- TRSNode *out_node                     : Output TRS Node
- char *s_sys_time                      : System Transaction Time
- struct MINVLOTSTS_TAG *MINVLOTSTS_OLD : Old INV Lot Status Info
- struct MINVLOTSTS_TAG *MINVLOTSTS        : New INV Lot Status Info
*******************************************************************************/
int CUS_INV_INSERT_LOT_MAT_ISSUE_HISTORY(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node,
	char *s_sys_time_t,
	struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
	struct MINVREQMST_TAG *MINVREQMST,
	struct MINVREQLOT_TAG *MINVREQLOT)
{
	struct MINVMATISS_TAG MINVMATISS;

	char s_sys_time[14];

	COM_memcpy(s_sys_time, s_sys_time_t, sizeof(s_sys_time));

	//자재 불출 내역 생성
	DBU_init_minvmatiss(&MINVMATISS);
	memcpy(MINVMATISS.FACTORY, MINVREQMST->FACTORY, sizeof(MINVREQMST->FACTORY));
	memcpy(MINVMATISS.INV_LOT_ID, MINVREQLOT->INV_LOT_ID, sizeof(MINVREQLOT->INV_LOT_ID));
	MINVMATISS.HIST_SEQ = MINVLOTSTS_OLD->LAST_HIST_SEQ + 1;
	memcpy(MINVMATISS.REQ_NO, MINVREQLOT->REQ_NO, sizeof(MINVREQLOT->REQ_NO));
	memcpy(MINVMATISS.REQ_MAT_ID, MINVREQLOT->REQ_MAT_ID, sizeof(MINVREQLOT->REQ_MAT_ID));
	MINVMATISS.REQ_MAT_VER = MINVREQLOT->REQ_MAT_VER;
	memcpy(MINVMATISS.ISSUE_TIME, s_sys_time, sizeof(MINVMATISS.ISSUE_TIME));
	MINVMATISS.ISSUE_QTY = MINVLOTSTS_OLD->QTY;
	memcpy(MINVMATISS.UNIT, MINVREQLOT->UNIT, sizeof(MINVREQLOT->UNIT));
	memcpy(MINVMATISS.AREA_ID, MINVLOTSTS_OLD->AREA_ID, sizeof(MINVLOTSTS_OLD->AREA_ID));
	memcpy(MINVMATISS.SUB_AREA_ID, MINVLOTSTS_OLD->SUB_AREA_ID, sizeof(MINVLOTSTS_OLD->SUB_AREA_ID));
	memcpy(MINVMATISS.OPER, MINVLOTSTS_OLD->OPER, sizeof(MINVLOTSTS_OLD->OPER));
	memcpy(MINVMATISS.TO_AREA_ID, MINVREQMST->AREA_ID, sizeof(MINVREQMST->AREA_ID));
	memcpy(MINVMATISS.TO_SUB_AREA_ID, MINVREQMST->SUB_AREA_ID, sizeof(MINVREQMST->SUB_AREA_ID));
	memcpy(MINVMATISS.TO_OPER, MINVREQMST->OPER, sizeof(MINVREQMST->OPER));
	memset(MINVMATISS.TRAN_COMMENT, ' ', sizeof(MINVMATISS.TRAN_COMMENT));
	TRS.copy(MINVMATISS.CREATE_USER_ID, sizeof(MINVMATISS.CREATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVMATISS.CREATE_TIME, s_sys_time, sizeof(MINVMATISS.CREATE_TIME));
	memset(MINVMATISS.UPDATE_USER_ID, ' ', sizeof(MINVMATISS.UPDATE_USER_ID));
	memset(MINVMATISS.UPDATE_TIME, ' ', sizeof(MINVMATISS.UPDATE_TIME));

	// MINVMATISS - 자재 불출 내역 생성
	DBU_insert_minvmatiss(&MINVMATISS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVMATISS INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVMATISS.INV_LOT_ID), MINVMATISS.INV_LOT_ID);
		TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MINVMATISS.HIST_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	return MP_TRUE;
}