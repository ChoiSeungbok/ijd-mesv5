/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_SHP_check_ship_lot.c
Description : 공정 LOT - 출하 LOT 관계 체크

MES Version : 4.0.0

Function List
- CUS_SHP_Check_Ship_Lot()
+ Check Ship Lot
- CUS_SHP_CHECK_SHIP_LOT()
+ Main sub function of "CUS_SHP_Check_Ship_Lot" function
+ Ship Lot definition
- CUS_SHP_Check_Ship_Lot_Validation()
+ Validation Check sub function of "CUS_SHP_CHECK_SHIP_LOT" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/27  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_Check_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_CHECK_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_SHP_Check_Ship_Lot()
- Check Ship Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Check_Ship_Lot(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);



	i_ret = CUS_SHP_CHECK_SHIP_LOT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_SHP_CHECK_SHIP_LOT", out_node);

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
CUS_SHP_CHECK_SHIP_LOT()
- Main sub function of "CUS_SHP_Check_Ship_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_CHECK_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	LOG_head("CUS_SHP_Check_Ship_Lot");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/* Validation Check */
	if (CUS_SHP_Check_Ship_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// CPAKLOTSTS - 포장 LOT 정보 조회
	DBU_init_cpaklotsts(&CPAKLOTSTS);
	TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), in_node, "LOT_ID_1");	// 1번째 INPUT
	TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), in_node, "LOT_ID_2");	// 2번째 INPUT
	DBU_select_cpaklotsts(1, &CPAKLOTSTS);

	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID_1", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
		TRS.add_fieldmsg(out_node, "LOT_ID_2", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	//해당 데이터가 존재하지 않는다면 바꿔서 조회
	if (DB_error_code == DB_NOT_FOUND)
	{
		// CPAKLOTSTS - 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), in_node, "LOT_ID_2");	// 2번째 INPUT
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), in_node, "LOT_ID_1");	// 1번째 INPUT
		DBU_select_cpaklotsts(1, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID_2", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_ID_1", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		if (DB_error_code == DB_NOT_FOUND)
		{
			//일치 데이터 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_MATCH_STATUS, strlen(MP_GCM_MATCH_STATUS));
			memcpy(MGCMTBLDAT.KEY_1, "N", strlen("N"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.add_string(out_node, "MATCH", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
		}
		else
		{


			TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CPAKLOTSTS.CMF_6, "Y", strlen("Y"));

			DBU_update_cpaklotsts(7, &CPAKLOTSTS);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_INT, CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}



			//일치 데이터 조회
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_MATCH_STATUS, strlen(MP_GCM_MATCH_STATUS));
			memcpy(MGCMTBLDAT.KEY_1, "Y", strlen("Y"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.add_string(out_node, "MATCH", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
		}
	}
	else
	{

		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(CPAKLOTSTS.CMF_6, "Y", strlen("Y"));

		DBU_update_cpaklotsts(7, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_INT, CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//일치 데이터 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_MATCH_STATUS, strlen(MP_GCM_MATCH_STATUS));
		memcpy(MGCMTBLDAT.KEY_1, "Y", strlen("Y"));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_dberrmsg(out_node, DB_error_msg);
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_string(out_node, "MATCH", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Check_Ship_Lot_Validation()
- Validation Check sub function of "CUS_SHP_CHECK_SHIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Check_Ship_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

	if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID_1")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "LOT_ID_1", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID_2")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "LOT_ID_2", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		return MP_FALSE;
	}

	return MP_TRUE;
}
