/*******************************************************************************

    System      : MESplus
    Module      : CUS_SHP
    File Name   : CUS_SHP_delete_pack_lot.c
    Description : Delete Pack Lot

    MES Version : 5.2.0

    Function List
        - CUS_SHP_Delete_Pack_Lot()
            + Delete Pack Lot
        - CUS_SHP_DELETE_PACK_LOT()
            + Main Sub function of "CUS_SHP_Delete_Pack_Lot"
            + (called by "CUS_SHP_Delete_Pack_Lot")
        - CUS_SHP_Delete_Pack_Lot_Validation()
            + Validation Check sub function of "CUS_SHP_DELETE_PACK_LOT" function
            + (called by "CUS_SHP_DELETE_PACK_LOT")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/26  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_DELETE_PACK_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_DELETE_PACK_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_SHP_Delete_Pack_Lot()
        - Delete Pack Lot
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_SHP_Delete_Pack_Lot_In_Tag *CUS_SHP_Delete_Pack_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Lot(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_DELETE_PACK_LOT_MAIN(s_msg_code, in_node, out_node);

	
    COM_out_msg_log_write(s_msg_code, "CUS_SHP_DELETE_PACK_LOT", out_node);

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
CUS_SHP_DELETE_PACK_LOT_MAIN()
- Main sub function of "CUS_SHP_DELETE_PACK_LOT_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_DELETE_PACK_LOT_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_DELETE_PACK_LOT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *delete_in_node;
	TRSNode **pack_lot_list;
	TRSNode *lot_list;
	int i = 0;

	LOG_head("CUS_SHP_DELETE_PACK_LOT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_SHP_Delete_Pack_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	delete_in_node = TRS.add_node(in_node, "delete_in_node");
	CopyDefaultMembers(delete_in_node, in_node);

	TRS.add_char(delete_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(delete_in_node, "PACK_LOT_LIST");
		TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(pack_lot_list[i], "ORG_LOT_ID"));
		TRS.add_nstring(lot_list, "PACK_LOT_ID", TRS.get_string(pack_lot_list[i], "PACK_LOT_ID"));
	}
	
	if (CUS_SHP_Delete_Pack_Lot_Before_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_DELETE_PACK_LOT(s_msg_code, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Delete_Pack_Lot_After_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_SHP_DELETE_PACK_LOT()
        - Main sub function of "CUS_SHP_Delete_Pack_Lot" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_DELETE_PACK_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_DELETE_PACK_LOT(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct CPAKLOTHIS_TAG CPAKLOTHIS;

	TRSNode **pack_lot_list;

    char s_sys_time[14];
	int i = 0;

    memset(s_sys_time, ' ', sizeof(s_sys_time));
	
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

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		//포장 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
		DBU_select_cpaklotsts(1, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 포장 LOT 포장 상태 체크
		// 포장 확정되었다면, 포장 정보 삭제 불가
		if (CPAKLOTSTS.PACK_FLAG == 'Y')
		{
			// WIP-0621 : 해당 Lot은 이미 포장 확정되었습니다.
			strcpy(s_msg_code, "WIP-0621");
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

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

		if (DB_error_code != DB_NOT_FOUND)
		{
			// 포장 지시 상태 체크
			// 생성, 수정, 삭제는 WAIT 상태에서만 가능
			// 확정 -> PACKED로 변경
			if (memcmp(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
			{
				strcpy(s_msg_code, "WIP-0565");
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 포장 등록 수량 감소
			CPAKORDSTS.REG_QTY = CPAKORDSTS.REG_QTY - CPAKLOTSTS.QTY;
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
				return MP_FALSE;
			}
		}

		// 삭제한 포장 정보를 남겨둘 예정
		// 매핑 정보 찾기 위한 정보
		DBU_init_cpaklothis(&CPAKLOTHIS);
		memcpy(CPAKLOTHIS.FACTORY, CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY));
		memcpy(CPAKLOTHIS.ORG_LOT_ID, CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID));
		memcpy(CPAKLOTHIS.PACK_LOT_ID, CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
		memcpy(CPAKLOTHIS.MAT_ID, CPAKLOTSTS.MAT_ID, sizeof(CPAKLOTSTS.MAT_ID));
		CPAKLOTHIS.MAT_VER = CPAKLOTSTS.MAT_VER;
		CPAKLOTHIS.QTY = CPAKLOTSTS.QTY;
		memcpy(CPAKLOTHIS.UNIT, CPAKLOTSTS.UNIT, sizeof(CPAKLOTSTS.UNIT));
		CPAKLOTHIS.PACK_FLAG = CPAKLOTSTS.PACK_FLAG;
		memcpy(CPAKLOTHIS.PACK_DATE, CPAKLOTSTS.PACK_DATE, sizeof(CPAKLOTSTS.PACK_DATE));
		memcpy(CPAKLOTHIS.PACK_ORDER_ID, CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
		CPAKLOTHIS.PACK_LINE_NO = CPAKLOTSTS.PACK_LINE_NO;
		CPAKLOTHIS.SHIP_FLAG = CPAKLOTSTS.SHIP_FLAG;
		memcpy(CPAKLOTHIS.SHIP_DATE, CPAKLOTSTS.SHIP_DATE, sizeof(CPAKLOTSTS.SHIP_DATE));
		memcpy(CPAKLOTHIS.SHIP_ORDER_ID, CPAKLOTSTS.SHIP_ORDER_ID, sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
		CPAKLOTHIS.SHIP_ORDER_SEQ = (int)CPAKLOTSTS.SHIP_ORDER_SEQ;
		CPAKLOTHIS.RET_FLAG = CPAKLOTSTS.RET_FLAG;
		CPAKLOTHIS.RETURNED_QTY = CPAKLOTSTS.RETURNED_QTY;
		memcpy(CPAKLOTHIS.BOX_ID_1, CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1));
		memcpy(CPAKLOTHIS.BOX_ID_2, CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2));
		memcpy(CPAKLOTHIS.BOX_ID_3, CPAKLOTSTS.BOX_ID_3, sizeof(CPAKLOTSTS.BOX_ID_3));
		memcpy(CPAKLOTHIS.CMF_1, CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
		memcpy(CPAKLOTHIS.CMF_2, CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
		memcpy(CPAKLOTHIS.CMF_3, CPAKLOTSTS.CMF_3, sizeof(CPAKLOTSTS.CMF_3));
		memcpy(CPAKLOTHIS.CMF_4, CPAKLOTSTS.CMF_4, sizeof(CPAKLOTSTS.CMF_4));
		memcpy(CPAKLOTHIS.CMF_5, CPAKLOTSTS.CMF_5, sizeof(CPAKLOTSTS.CMF_5));
		memcpy(CPAKLOTHIS.CMF_6, CPAKLOTSTS.CMF_6, sizeof(CPAKLOTSTS.CMF_6));
		memcpy(CPAKLOTHIS.CMF_7, CPAKLOTSTS.CMF_7, sizeof(CPAKLOTSTS.CMF_7));
		memcpy(CPAKLOTHIS.CMF_8, CPAKLOTSTS.CMF_8, sizeof(CPAKLOTSTS.CMF_8));
		memcpy(CPAKLOTHIS.CMF_9, CPAKLOTSTS.CMF_9, sizeof(CPAKLOTSTS.CMF_9));
		memcpy(CPAKLOTHIS.CMF_10, CPAKLOTSTS.CMF_10, sizeof(CPAKLOTSTS.CMF_10));
		TRS.copy(CPAKLOTHIS.CREATE_USER_ID, sizeof(CPAKLOTHIS.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CPAKLOTHIS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CPAKLOTHIS.UPDATE_USER_ID, sizeof(CPAKLOTHIS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CPAKLOTHIS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_insert_cpaklothis(&CPAKLOTHIS);
		if (DB_error_code != DB_SUCCESS)
		{
			/*
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTHIS INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTHIS.ORG_LOT_ID), CPAKLOTHIS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTHIS.PACK_LOT_ID), CPAKLOTHIS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
			*/
		}

		//포장 정보 삭제
		DBU_delete_cpaklotsts(1, &CPAKLOTSTS);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS DELETE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_SHP_Delete_Pack_Lot_Validation()
        - Validation Check sub function of "CUS_SHP_DELETE_PACK_LOT" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_DELETE_PACK_LOT_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_SHP_Delete_Pack_Lot_Before_Transaction()
- Main sub function of "CUS_SHP_DELETE_PACK_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Delete_Pack_Lot_After_Transaction()
- Main sub function of "CUS_SHP_DELETE_PACK_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}