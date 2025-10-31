/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_mold_break_registration.c
Description : 금형 파손 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/04/29  LWG         Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Mold_Break_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_MOLD_BREAK_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Mold_Break_Registration()
- Mold Store Break function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Break_Registration(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_RAS_MOLD_BREAK_REGISTRATION(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_RAS_Mold_Break_Registration", out_node);
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
CUS_RAS_MOLD_BREAK_REGISTRATION()
- Main sub function of "CUS_RAS_Mold_Break_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_MOLD_BREAK_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MRASTOLDEF_TAG MRASTOLDEF;
	struct MRASTOLHIS_TAG MRASTOLHIS;
	struct CRASTOLBRK_TAG CRASTOLBRK;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct CRASDSPREQ_TAG CRASDSPREQ;
	struct CRASDSPTOL_TAG CRASDSPTOL;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	TRSNode **Tool_tbl;

	int i_tool_count = 0;
	char req_no[21];

	LOG_head("CUS_RAS_Mold_Break_Registration");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	//초기화
	memset(req_no, ' ', sizeof(req_no));

	/* Validation Check */
	if (CUS_RAS_Mold_Break_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 저장
	if (TRS.get_procstep(in_node) == '1')
	{
		Tool_tbl = TRS.get_list(in_node, "TOOL_TBL");
		i_tool_count = TRS.get_item_count(in_node, "TOOL_TBL");

		for (int i = 0; i < i_tool_count; i++)
		{
			//개별 tool별로 조회한다.
			DBU_init_mrastoldef(&MRASTOLDEF);
			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), Tool_tbl[i], "TOOL_ID");
			DBU_select_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//RAS-0168 : TOOL 이 존재하지 않습니다.
				strcpy(s_msg_code, "RAS-0168");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTOLDEF.FACTORY), MRASTOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (MRASTOLDEF.DELETE_FLAG != ' ')
			{
				//RAS-0171 : 삭제/폐기/반품된 TOOL입니다.
				strcpy(s_msg_code, "RAS-0171");
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (MRASTOLDEF.RES_ID[0] != ' ')
			{
				//RAS-0177 : TOOL이 현재 장비/서브장비에서 작업중입니다. 장비/서브장비로부터 TOOL을 먼저 분리하세요.
				strcpy(s_msg_code, "RAS-0177");
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASTOLDEF.RES_ID), MRASTOLDEF.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_crastolbrk(&CRASTOLBRK);
			memcpy(CRASTOLBRK.FACTORY, MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY));
			memcpy(CRASTOLBRK.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			DBU_select_crastolbrk(1, &CRASTOLBRK);

			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					TRS.copy(CRASTOLBRK.CREATE_USER_ID, sizeof(CRASTOLBRK.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CRASTOLBRK.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));

					DBU_insert_crastolbrk(&CRASTOLBRK);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CRASTOLBRK INSERT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
						TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}
				else
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CRASTOLBRK SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
					TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}

			CRASTOLBRK.HIST_SEQ = MRASTOLDEF.LAST_ACTIVE_HIST_SEQ;
			memcpy(CRASTOLBRK.AREA_ID, MRASTOLDEF.AREA_ID, sizeof(MRASTOLDEF.AREA_ID));
			memcpy(CRASTOLBRK.OPER, MRASTOLDEF.OPER, sizeof(MRASTOLDEF.OPER));
			memcpy(CRASTOLBRK.MAT_ID, MRASTOLDEF.MAT_ID, sizeof(MRASTOLDEF.MAT_ID));

			DBU_init_mrastolhis(&MRASTOLHIS);
			memcpy(MRASTOLHIS.FACTORY, MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY));
			memcpy(MRASTOLHIS.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			DBU_select_mrastolhis(2, &MRASTOLHIS);
			if (DB_error_code == DB_SUCCESS)
			{
				memcpy(CRASTOLBRK.RES_ID, MRASTOLHIS.RES_ID, sizeof(MRASTOLHIS.RES_ID));
				memcpy(CRASTOLBRK.CAR, MRASTOLDEF.TOOL_STS_1, sizeof(CRASTOLBRK.CAR));
				memcpy(CRASTOLBRK.TOP_BASE, MRASTOLDEF.TOOL_STS_2, sizeof(CRASTOLBRK.TOP_BASE));
			}

			TRS.copy(CRASTOLBRK.BREAK_DATE, sizeof(CRASTOLBRK.BREAK_DATE), in_node, "BREAK_DATE");
			TRS.copy(CRASTOLBRK.OCCUR_TIME, sizeof(CRASTOLBRK.OCCUR_TIME), in_node, "OCCUR_TIME");
			TRS.copy(CRASTOLBRK.TOOL_KIND, sizeof(CRASTOLBRK.TOOL_KIND), in_node, "TOOL_KIND");
			TRS.copy(CRASTOLBRK.WORKER_ID, sizeof(CRASTOLBRK.WORKER_ID), in_node, "WORKER_ID");
			TRS.copy(CRASTOLBRK.ISSUE_TYPE, sizeof(CRASTOLBRK.ISSUE_TYPE), in_node, "ISSUE_TYPE");
			TRS.copy(CRASTOLBRK.ISSUE_COMMENT, sizeof(CRASTOLBRK.ISSUE_COMMENT), in_node, "ISSUE_COMMENT");
			TRS.copy(CRASTOLBRK.BREAK_CAUSE, sizeof(CRASTOLBRK.BREAK_CAUSE), in_node, "BREAK_CAUSE");
			TRS.copy(CRASTOLBRK.ACTION_COMMENT, sizeof(CRASTOLBRK.ACTION_COMMENT), in_node, "ACTION_COMMENT");
			TRS.copy(CRASTOLBRK.BO_TIME, sizeof(CRASTOLBRK.BO_TIME), in_node, "BO_TIME");
			TRS.copy(CRASTOLBRK.BREAK_PATTERN, sizeof(CRASTOLBRK.BREAK_PATTERN), in_node, "BREAK_PATTERN");
			TRS.copy(CRASTOLBRK.CROWN_NO, sizeof(CRASTOLBRK.CROWN_NO), in_node, "CROWN_NO");
			TRS.copy(CRASTOLBRK.CARBIDE_LOT, sizeof(CRASTOLBRK.CARBIDE_LOT), in_node, "CARBIDE_LOT");
			TRS.copy(CRASTOLBRK.C_SCAN, sizeof(CRASTOLBRK.C_SCAN), in_node, "C_SCAN");
			TRS.copy(CRASTOLBRK.BREAK_TYPE, sizeof(CRASTOLBRK.BREAK_TYPE), in_node, "BREAK_TYPE");
			TRS.copy(CRASTOLBRK.MAT_TYPE, sizeof(CRASTOLBRK.MAT_TYPE), in_node, "MAT_TYPE");
			TRS.copy(CRASTOLBRK.GRADE, sizeof(CRASTOLBRK.GRADE), in_node, "GRADE");
			TRS.copy(CRASTOLBRK.BO_DIE_NO, sizeof(CRASTOLBRK.BO_DIE_NO), in_node, "BO_DIE_NO");
			TRS.copy(CRASTOLBRK.D10_TYPE, sizeof(CRASTOLBRK.D10_TYPE), in_node, "D10_TYPE");
			TRS.copy(CRASTOLBRK.D10_CREATE_TIME, sizeof(CRASTOLBRK.D10_CREATE_TIME), in_node, "D10_CREATE_TIME");
			TRS.copy(CRASTOLBRK.M15_LOT_ID, sizeof(CRASTOLBRK.M15_LOT_ID), in_node, "M15_LOT_ID");
			TRS.copy(CRASTOLBRK.M13_LOT_ID, sizeof(CRASTOLBRK.M13_LOT_ID), in_node, "M13_LOT_ID");
			CRASTOLBRK.D10_WEIGHT = TRS.get_double(in_node, "D10_WEIGHT");
			CRASTOLBRK.D10_HEIGHT = TRS.get_double(in_node, "D10_HEIGHT");
			CRASTOLBRK.CONFIRM_FLAG = 'N';
			TRS.copy(CRASTOLBRK.REMARK, sizeof(CRASTOLBRK.REMARK), in_node, "REMARK");
			TRS.copy(CRASTOLBRK.CMF_1, sizeof(CRASTOLBRK.CMF_1), in_node, "CMF_1");

			CRASTOLBRK.SIZE_1 = TRS.get_double(in_node, "SIZE_1");
			CRASTOLBRK.SIZE_2 = TRS.get_double(in_node, "SIZE_2");
			CRASTOLBRK.SIZE_3 = TRS.get_double(in_node, "SIZE_3");


			//20220818 추가
			TRS.copy(CRASTOLBRK.BO_PRESSURE, sizeof(CRASTOLBRK.BO_PRESSURE), in_node, "BO_PRESSURE");
			TRS.copy(CRASTOLBRK.BO_ELECTRICITY, sizeof(CRASTOLBRK.BO_ELECTRICITY), in_node, "BO_ELECTRICITY");
			TRS.copy(CRASTOLBRK.BO_RESISTANCE, sizeof(CRASTOLBRK.BO_RESISTANCE), in_node, "BO_RESISTANCE");
			TRS.copy(CRASTOLBRK.BO_CURRENT, sizeof(CRASTOLBRK.BO_CURRENT), in_node, "BO_CURRENT");
			TRS.copy(CRASTOLBRK.HOLD_LOT_ID, sizeof(CRASTOLBRK.HOLD_LOT_ID), in_node, "HOLD_LOT_ID");
			TRS.copy(CRASTOLBRK.ASSY_MOLD, sizeof(CRASTOLBRK.ASSY_MOLD), in_node, "ASSY_MOLD");
			TRS.copy(CRASTOLBRK.ASSY_MOLD_PRESSURE, sizeof(CRASTOLBRK.ASSY_MOLD_PRESSURE), in_node, "ASSY_MOLD_PRESSURE");
			TRS.copy(CRASTOLBRK.PROFILE_NO, sizeof(CRASTOLBRK.PROFILE_NO), in_node, "PROFILE_NO");
			TRS.copy(CRASTOLBRK.PROFILE_PRESSURE, sizeof(CRASTOLBRK.PROFILE_PRESSURE), in_node, "PROFILE_PRESSURE");
			TRS.copy(CRASTOLBRK.PROFILE_ELECTRICITY, sizeof(CRASTOLBRK.PROFILE_ELECTRICITY), in_node, "PROFILE_ELECTRICITY");
			TRS.copy(CRASTOLBRK.MOLD_LOCATION, sizeof(CRASTOLBRK.MOLD_LOCATION), in_node, "MOLD_LOCATION");
			TRS.copy(CRASTOLBRK.MOD_IN_FORN_LOT, sizeof(CRASTOLBRK.MOD_IN_FORN_LOT), in_node, "MOD_IN_FORN_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_REAR_LOT, sizeof(CRASTOLBRK.MOD_IN_REAR_LOT), in_node, "MOD_IN_REAR_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_LEFT_LOT, sizeof(CRASTOLBRK.MOD_IN_LEFT_LOT), in_node, "MOD_IN_LEFT_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_RIGHT_LOT, sizeof(CRASTOLBRK.MOD_IN_RIGHT_LOT), in_node, "MOD_IN_RIGHT_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_TOP_LOT, sizeof(CRASTOLBRK.MOD_IN_TOP_LOT), in_node, "MOD_IN_TOP_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_BOTTON_LOT, sizeof(CRASTOLBRK.MOD_IN_BOTTON_LOT), in_node, "MOD_IN_BOTTON_LOT");








			DBU_init_minvlotsts(&MINVLOTSTS);
			TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVLOTSTS.INV_LOT_ID, MRASTOLDEF.TOOL_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
			DBU_select_minvlotsts(1, &MINVLOTSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				memcpy(CRASTOLBRK.VENDOR_LOT_ID, MINVLOTSTS.VENDOR_LOT_ID, sizeof(CRASTOLBRK.VENDOR_LOT_ID));
			}

			if (MRASTOLDEF.TOOL_STS_3[0] != ' ')
				CRASTOLBRK.LIMIT_COUNT = COM_atoi(MRASTOLDEF.TOOL_STS_3, sizeof(MRASTOLDEF.TOOL_STS_3));
			else
				CRASTOLBRK.LIMIT_COUNT = 0;

			if (MRASTOLDEF.TOOL_STS_4[0] != ' ')
				CRASTOLBRK.USE_COUNT = COM_atoi(MRASTOLDEF.TOOL_STS_4, sizeof(MRASTOLDEF.TOOL_STS_4));
			else
				CRASTOLBRK.USE_COUNT = 0;

			if (MRASTOLDEF.TOOL_STS_5[0] != ' ')
				CRASTOLBRK.ALAM_COUNT = COM_atoi(MRASTOLDEF.TOOL_STS_5, sizeof(MRASTOLDEF.TOOL_STS_5));
			else
				CRASTOLBRK.ALAM_COUNT = 0;

			TRS.copy(CRASTOLBRK.UPDATE_USER_ID, sizeof(CRASTOLBRK.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRASTOLBRK.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

			DBU_update_crastolbrk(1, &CRASTOLBRK);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CRASTOLBRK UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}
	//확정하여 폐기 요청.
	else if (TRS.get_procstep(in_node) == '2')
	{
		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		CopyDefaultMembers(gen_in_node, in_node);
		TRS.add_string(gen_in_node, "RULE_ID", "MOLD_REQ_NO", strlen("MOLD_REQ_NO"));
		TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

		cmn_out = TRS.create_node("cmn_out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

		memcpy(req_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);

		Tool_tbl = TRS.get_list(in_node, "TOOL_TBL");
		i_tool_count = TRS.get_item_count(in_node, "TOOL_TBL");

		for (int i = 0; i < i_tool_count; i++)
		{
			//개별 tool별로 조회한다.
			DBU_init_mrastoldef(&MRASTOLDEF);
			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), Tool_tbl[i], "TOOL_ID");
			DBU_select_mrastoldef(1, &MRASTOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//RAS-0168 : TOOL 이 존재하지 않습니다.
				strcpy(s_msg_code, "RAS-0168");
				TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTOLDEF.FACTORY), MRASTOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (MRASTOLDEF.DELETE_FLAG != ' ')
			{
				//RAS-0171 : 삭제/폐기/반품된 TOOL입니다.
				strcpy(s_msg_code, "RAS-0171");
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (MRASTOLDEF.RES_ID[0] != ' ')
			{
				//RAS-0177 : TOOL이 현재 장비/서브장비에서 작업중입니다. 장비/서브장비로부터 TOOL을 먼저 분리하세요.
				strcpy(s_msg_code, "RAS-0177");
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASTOLDEF.RES_ID), MRASTOLDEF.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_crastolbrk(&CRASTOLBRK);
			memcpy(CRASTOLBRK.FACTORY, MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY));
			memcpy(CRASTOLBRK.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			DBU_select_crastolbrk(1, &CRASTOLBRK);

			if (DB_error_code != DB_SUCCESS)
			{
				//RAS-0326 : 금형 파손 정보가 존재하지 않습니다. 금형 파손 정보를 먼저 등록해 주세요.
				strcpy(s_msg_code, "RAS-0326");
				TRS.add_fieldmsg(out_node, "CRASTOLBRK SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MRASTOLDEF.OPER, sizeof(MRASTOLDEF.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0010 : 이 공정은 존재 하지 않습니다.
				strcpy(s_msg_code, "WIP-0010");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (i == 0)
			{
				DBU_init_crasdspreq(&CRASDSPREQ);
				TRS.copy(CRASDSPREQ.FACTORY, sizeof(CRASDSPREQ.FACTORY), in_node, IN_FACTORY);
				memcpy(CRASDSPREQ.REQ_NO, req_no, sizeof(CRASDSPREQ.REQ_NO));
				TRS.copy(CRASDSPREQ.AREA_ID, sizeof(CRASDSPREQ.AREA_ID), in_node, "AREA_ID");
				memcpy(CRASDSPREQ.SUB_AREA_ID, MRASTOLDEF.SUB_AREA_ID, sizeof(MRASTOLDEF.SUB_AREA_ID));
				memcpy(CRASDSPREQ.OPER, MRASTOLDEF.OPER, sizeof(MRASTOLDEF.OPER));
				memcpy(CRASDSPREQ.REQ_USER_ID, CRASTOLBRK.WORKER_ID, sizeof(CRASTOLBRK.WORKER_ID));
				//TRS.copy(CRASDSPREQ.REQ_COMMENT, sizeof(CRASDSPREQ.REQ_COMMENT), in_node, "REQ_COMMENT");

				memcpy(CRASDSPREQ.REQ_TIME, gs_sys_time, sizeof(CRASDSPREQ.REQ_TIME));
				memcpy(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_CONFIRM, strlen(MP_CRAS_DSP_REQ_STATUS_CONFIRM));
				memcpy(CRASDSPREQ.CREATE_TIME, gs_sys_time, sizeof(CRASDSPREQ.CREATE_TIME));
				TRS.copy(CRASDSPREQ.CREATE_USER_ID, sizeof(CRASDSPREQ.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CRASDSPREQ.UPDATE_TIME, gs_sys_time, sizeof(CRASDSPREQ.UPDATE_TIME));
				TRS.copy(CRASDSPREQ.UPDATE_USER_ID, sizeof(CRASDSPREQ.UPDATE_USER_ID), in_node, IN_USERID);
				DBU_insert_crasdspreq(&CRASDSPREQ);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "CRASDSPREQ INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}
			}

			//금형 폐기 리스트 조회
			DBU_init_crasdsptol(&CRASDSPTOL);
			TRS.copy(CRASDSPTOL.FACTORY, sizeof(CRASDSPTOL.FACTORY), in_node, IN_FACTORY);
			memcpy(CRASDSPTOL.REQ_NO, req_no, sizeof(CRASDSPTOL.REQ_NO));
			memcpy(CRASDSPTOL.TOOL_ID, MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			TRS.copy(CRASDSPTOL.CREATE_USER_ID, sizeof(CRASDSPTOL.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CRASDSPTOL.CREATE_TIME, gs_sys_time, sizeof(CRASDSPTOL.CREATE_TIME));

			DBU_insert_crasdsptol(&CRASDSPTOL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CRASDSPTOL INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//폐기 요청 확정에 대한 정보 업데이트
			memcpy(CRASTOLBRK.REQ_NO, req_no, sizeof(CRASTOLBRK.REQ_NO));
			CRASTOLBRK.CONFIRM_FLAG = 'Y';
			memcpy(CRASTOLBRK.CONFIRM_TIME, gs_sys_time, sizeof(gs_sys_time));
			TRS.copy(CRASTOLBRK.UPDATE_USER_ID, sizeof(CRASTOLBRK.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRASTOLBRK.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

			DBU_update_crastolbrk(1, &CRASTOLBRK);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CRASTOLBRK UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}
	//폐기이력만 수정 추가
	else if (TRS.get_procstep(in_node) == '3')
	{
		Tool_tbl = TRS.get_list(in_node, "TOOL_TBL");
		i_tool_count = TRS.get_item_count(in_node, "TOOL_TBL");

		for (int i = 0; i < i_tool_count; i++)
		{

			DBU_init_crastolbrk(&CRASTOLBRK);

			TRS.copy(CRASTOLBRK.FACTORY, sizeof(CRASTOLBRK.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CRASTOLBRK.TOOL_ID, sizeof(CRASTOLBRK.TOOL_ID), Tool_tbl[i], "TOOL_ID");
			DBU_select_crastolbrk(1, &CRASTOLBRK);

			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					TRS.copy(CRASTOLBRK.CREATE_USER_ID, sizeof(CRASTOLBRK.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CRASTOLBRK.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));

					DBU_insert_crastolbrk(&CRASTOLBRK);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CRASTOLBRK INSERT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
						TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}
				else
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CRASTOLBRK SELECT ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
					TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}



			TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), Tool_tbl[i], "TOOL_ID");

			TRS.copy(CRASTOLBRK.AREA_ID, sizeof(CRASTOLBRK.AREA_ID), in_node, "AREA_ID");
			TRS.copy(CRASTOLBRK.OPER, sizeof(CRASTOLBRK.OPER), in_node, "OPER");
			TRS.copy(CRASTOLBRK.MAT_ID, sizeof(CRASTOLBRK.MAT_ID), in_node, "MAT_ID");

			CRASTOLBRK.HIST_SEQ = 0;

			TRS.copy(CRASTOLBRK.BREAK_DATE, sizeof(CRASTOLBRK.BREAK_DATE), in_node, "BREAK_DATE");
			TRS.copy(CRASTOLBRK.OCCUR_TIME, sizeof(CRASTOLBRK.OCCUR_TIME), in_node, "OCCUR_TIME");
			TRS.copy(CRASTOLBRK.TOOL_KIND, sizeof(CRASTOLBRK.TOOL_KIND), in_node, "TOOL_KIND");
			TRS.copy(CRASTOLBRK.WORKER_ID, sizeof(CRASTOLBRK.WORKER_ID), in_node, "WORKER_ID");
			TRS.copy(CRASTOLBRK.ISSUE_TYPE, sizeof(CRASTOLBRK.ISSUE_TYPE), in_node, "ISSUE_TYPE");
			TRS.copy(CRASTOLBRK.ISSUE_COMMENT, sizeof(CRASTOLBRK.ISSUE_COMMENT), in_node, "ISSUE_COMMENT");
			TRS.copy(CRASTOLBRK.BREAK_CAUSE, sizeof(CRASTOLBRK.BREAK_CAUSE), in_node, "BREAK_CAUSE");
			TRS.copy(CRASTOLBRK.ACTION_COMMENT, sizeof(CRASTOLBRK.ACTION_COMMENT), in_node, "ACTION_COMMENT");
			TRS.copy(CRASTOLBRK.BO_TIME, sizeof(CRASTOLBRK.BO_TIME), in_node, "BO_TIME");
			TRS.copy(CRASTOLBRK.BREAK_PATTERN, sizeof(CRASTOLBRK.BREAK_PATTERN), in_node, "BREAK_PATTERN");
			TRS.copy(CRASTOLBRK.CROWN_NO, sizeof(CRASTOLBRK.CROWN_NO), in_node, "CROWN_NO");
			TRS.copy(CRASTOLBRK.CARBIDE_LOT, sizeof(CRASTOLBRK.CARBIDE_LOT), in_node, "CARBIDE_LOT");
			TRS.copy(CRASTOLBRK.C_SCAN, sizeof(CRASTOLBRK.C_SCAN), in_node, "C_SCAN");
			TRS.copy(CRASTOLBRK.BREAK_TYPE, sizeof(CRASTOLBRK.BREAK_TYPE), in_node, "BREAK_TYPE");
			TRS.copy(CRASTOLBRK.MAT_TYPE, sizeof(CRASTOLBRK.MAT_TYPE), in_node, "MAT_TYPE");
			TRS.copy(CRASTOLBRK.GRADE, sizeof(CRASTOLBRK.GRADE), in_node, "GRADE");
			TRS.copy(CRASTOLBRK.BO_DIE_NO, sizeof(CRASTOLBRK.BO_DIE_NO), in_node, "BO_DIE_NO");
			TRS.copy(CRASTOLBRK.D10_TYPE, sizeof(CRASTOLBRK.D10_TYPE), in_node, "D10_TYPE");
			TRS.copy(CRASTOLBRK.D10_CREATE_TIME, sizeof(CRASTOLBRK.D10_CREATE_TIME), in_node, "D10_CREATE_TIME");
			TRS.copy(CRASTOLBRK.M15_LOT_ID, sizeof(CRASTOLBRK.M15_LOT_ID), in_node, "M15_LOT_ID");
			TRS.copy(CRASTOLBRK.M13_LOT_ID, sizeof(CRASTOLBRK.M13_LOT_ID), in_node, "M13_LOT_ID");
			CRASTOLBRK.D10_WEIGHT = TRS.get_double(in_node, "D10_WEIGHT");
			CRASTOLBRK.D10_HEIGHT = TRS.get_double(in_node, "D10_HEIGHT");
			CRASTOLBRK.CONFIRM_FLAG = 'Y';
			TRS.copy(CRASTOLBRK.REMARK, sizeof(CRASTOLBRK.REMARK), in_node, "REMARK");
			TRS.copy(CRASTOLBRK.CMF_1, sizeof(CRASTOLBRK.CMF_1), in_node, "CMF_1");

			CRASTOLBRK.SIZE_1 = TRS.get_double(in_node, "SIZE_1");
			CRASTOLBRK.SIZE_2 = TRS.get_double(in_node, "SIZE_2");
			CRASTOLBRK.SIZE_3 = TRS.get_double(in_node, "SIZE_3");


			//20220818 추가
			TRS.copy(CRASTOLBRK.BO_PRESSURE, sizeof(CRASTOLBRK.BO_PRESSURE), in_node, "BO_PRESSURE");
			TRS.copy(CRASTOLBRK.BO_ELECTRICITY, sizeof(CRASTOLBRK.BO_ELECTRICITY), in_node, "BO_ELECTRICITY");
			TRS.copy(CRASTOLBRK.BO_RESISTANCE, sizeof(CRASTOLBRK.BO_RESISTANCE), in_node, "BO_RESISTANCE");
			TRS.copy(CRASTOLBRK.BO_CURRENT, sizeof(CRASTOLBRK.BO_CURRENT), in_node, "BO_CURRENT");
			TRS.copy(CRASTOLBRK.HOLD_LOT_ID, sizeof(CRASTOLBRK.HOLD_LOT_ID), in_node, "HOLD_LOT_ID");
			TRS.copy(CRASTOLBRK.ASSY_MOLD, sizeof(CRASTOLBRK.ASSY_MOLD), in_node, "ASSY_MOLD");
			TRS.copy(CRASTOLBRK.ASSY_MOLD_PRESSURE, sizeof(CRASTOLBRK.ASSY_MOLD_PRESSURE), in_node, "ASSY_MOLD_PRESSURE");
			TRS.copy(CRASTOLBRK.PROFILE_NO, sizeof(CRASTOLBRK.PROFILE_NO), in_node, "PROFILE_NO");
			TRS.copy(CRASTOLBRK.PROFILE_PRESSURE, sizeof(CRASTOLBRK.PROFILE_PRESSURE), in_node, "PROFILE_PRESSURE");
			TRS.copy(CRASTOLBRK.PROFILE_ELECTRICITY, sizeof(CRASTOLBRK.PROFILE_ELECTRICITY), in_node, "PROFILE_ELECTRICITY");
			TRS.copy(CRASTOLBRK.MOLD_LOCATION, sizeof(CRASTOLBRK.MOLD_LOCATION), in_node, "MOLD_LOCATION");
			TRS.copy(CRASTOLBRK.MOD_IN_FORN_LOT, sizeof(CRASTOLBRK.MOD_IN_FORN_LOT), in_node, "MOD_IN_FORN_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_REAR_LOT, sizeof(CRASTOLBRK.MOD_IN_REAR_LOT), in_node, "MOD_IN_REAR_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_LEFT_LOT, sizeof(CRASTOLBRK.MOD_IN_LEFT_LOT), in_node, "MOD_IN_LEFT_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_RIGHT_LOT, sizeof(CRASTOLBRK.MOD_IN_RIGHT_LOT), in_node, "MOD_IN_RIGHT_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_TOP_LOT, sizeof(CRASTOLBRK.MOD_IN_TOP_LOT), in_node, "MOD_IN_TOP_LOT");
			TRS.copy(CRASTOLBRK.MOD_IN_BOTTON_LOT, sizeof(CRASTOLBRK.MOD_IN_BOTTON_LOT), in_node, "MOD_IN_BOTTON_LOT");



			TRS.copy(CRASTOLBRK.VENDOR_LOT_ID, sizeof(CRASTOLBRK.VENDOR_LOT_ID), in_node, "VENDOR_LOT_ID");
			CRASTOLBRK.LIMIT_COUNT = TRS.get_int(in_node, "LIMIT_COUNT");
			CRASTOLBRK.USE_COUNT = TRS.get_int(in_node, "USE_COUNT");
			CRASTOLBRK.ALAM_COUNT = TRS.get_int(in_node, "ALAM_COUNT");

			TRS.copy(CRASTOLBRK.UPDATE_USER_ID, sizeof(CRASTOLBRK.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CRASTOLBRK.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));




			DBU_update_crastolbrk(1, &CRASTOLBRK);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CRASTOLBRK UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}
	//폐기이력 삭제.
	else if (TRS.get_procstep(in_node) == '4')
	{

		Tool_tbl = TRS.get_list(in_node, "TOOL_TBL");
		i_tool_count = TRS.get_item_count(in_node, "TOOL_TBL");

		for (int i = 0; i < i_tool_count; i++)
		{
			DBU_init_crastolbrk(&CRASTOLBRK);
			TRS.copy(CRASTOLBRK.FACTORY, sizeof(CRASTOLBRK.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CRASTOLBRK.TOOL_ID, sizeof(CRASTOLBRK.TOOL_ID), Tool_tbl[i], "TOOL_ID");
			DBU_select_crastolbrk(1, &CRASTOLBRK);

			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					TRS.copy(CRASTOLBRK.FACTORY, sizeof(CRASTOLBRK.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CRASTOLBRK.TOOL_ID, sizeof(CRASTOLBRK.TOOL_ID), Tool_tbl[i], "TOOL_ID");

					DBU_delete_crastolbrk(1, &CRASTOLBRK);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CRASTOLBRK INSERT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASTOLBRK.FACTORY), CRASTOLBRK.FACTORY);
						TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASTOLBRK.TOOL_ID), CRASTOLBRK.TOOL_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}
			}
		}
	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Mold_Break_Registration_Validation()
- Validation Check sub function of "CUS_RAS_MOLD_BREAK_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Break_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12") == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		return MP_FALSE;
	}

	return MP_TRUE;
}
