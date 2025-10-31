/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_lot_press_data.c
Description : Lot Press Data Valid / View / Registration

MES Version : 5.0

Function List


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/13  JS.SEO        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Lot_Press_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Lot_Press_Data_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Lot_Press_Data_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Lot_Press_Data()
- Tran adapt Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Lot_Press_Data(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_LOT_PRESS_DATA(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Lot_Press_Data", out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

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
CUS_WIP_LOT_PRESS_DATA()
- Main sub function of "CUS_WIP_Lot_Press_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_LOT_PRESS_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct CWIPLOTPRS_TAG CWIPLOTPRS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_RESOURCE;
	struct MRASRESDEF_TAG MRASRESDEF;
	struct work_date_tag work_date;

	TRSNode **lot_press_list;
	TRSNode *press_data_list;

	char s_sys_time[14];
	int i = 0;

	LOG_head("CUS_WIP_Lot_Press_Data");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(&work_date, ' ', sizeof(work_date));
	memset(s_sys_time, ' ', sizeof(s_sys_time));

	Get_shift(MWIPLOTSTSX.FACTORY, &work_date);

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		return MP_FALSE;	
	}

	/* Validation Check */
	if (CUS_WIP_Lot_Press_Data_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	lot_press_list = TRS.get_list(in_node, "DATA_LIST");

	// STEP 1 : PRESS LOT 정보 조회
	// STEP 2 : PDC관련 LOT 정보 조회
	// STEP 3 : PRESS 정보 등록/수정 LOT VALID 및 등록/수정

	if (TRS.get_procstep(in_node) == '1')
	{
		//LOT이 존재하는지 확인
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

			return MP_FALSE;
		}

		// 품목 정보 조회
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

			return MP_FALSE;
		}

		DBU_init_cwiplotprs(&CWIPLOTPRS);
		TRS.copy(CWIPLOTPRS.FACTORY, sizeof(CWIPLOTPRS.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPLOTPRS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		TRS.copy(CWIPLOTPRS.CMF_1, sizeof(CWIPLOTPRS.CMF_1), in_node, "AREA");
        TRS.copy(CWIPLOTPRS.RES_ID, sizeof(CWIPLOTPRS.RES_ID), in_node, "RES_ID");
        TRS.copy(CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE), in_node, "PROFILE");
		DBU_open_cwiplotprs(1, &CWIPLOTPRS);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CWIPLOTPRS Open 1", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTPRS.FACTORY), CWIPLOTPRS.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
			TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
			TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_cwiplotprs(1, &CWIPLOTPRS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwiplotprs(1);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTPRS Fetch 1", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTPRS.FACTORY), CWIPLOTPRS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
				TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
				TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				DBU_close_cwiplotprs(1);

				return MP_FALSE;
			}

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_int(out_node, "NEXT_HIST_SEQ", CWIPLOTPRS.HIST_SEQ);
                TRS.add_string(out_node, "NEXT_PROFILE", CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE));
                TRS.add_string(out_node, "NEXT_STEP", CWIPLOTPRS.STEP, sizeof(CWIPLOTPRS.STEP));
                DBU_close_cwiplotprs(1);
                break;
            }

			press_data_list = TRS.add_node(out_node, "PRESS_DATA_LIST");
			TRS.add_string(press_data_list, "LOT_ID", CWIPLOTPRS.LOT_ID, sizeof(CWIPLOTPRS.LOT_ID));
			TRS.add_int(press_data_list, "HIST_SEQ", CWIPLOTPRS.HIST_SEQ);
			TRS.add_string(press_data_list, "PROFILE", CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE));
			TRS.add_string(press_data_list, "STEP", CWIPLOTPRS.STEP, sizeof(CWIPLOTPRS.STEP));
			TRS.add_int(press_data_list, "PERIOD_SEC", CWIPLOTPRS.PERIOD_SEC);
			TRS.add_string(press_data_list, "OPER", CWIPLOTPRS.OPER, sizeof(CWIPLOTPRS.OPER));
			TRS.add_string(press_data_list, "MAT_ID", CWIPLOTPRS.MAT_ID, sizeof(CWIPLOTPRS.MAT_ID));
			TRS.add_string(press_data_list, "FLOW", CWIPLOTPRS.FLOW, sizeof(CWIPLOTPRS.FLOW));
			TRS.add_int(press_data_list, "FLOW_SEQ_NUM", CWIPLOTPRS.FLOW_SEQ_NUM);
			TRS.add_string(press_data_list, "WORK_DATE", CWIPLOTPRS.WORK_DATE, sizeof(CWIPLOTPRS.WORK_DATE));
			TRS.add_string(press_data_list, "WORK_TIME", CWIPLOTPRS.WORK_TIME, sizeof(CWIPLOTPRS.WORK_TIME));
			TRS.add_string(press_data_list, "DAY_NIGHT", CWIPLOTPRS.DAY_NIGHT, sizeof(CWIPLOTPRS.DAY_NIGHT));
			TRS.add_double(press_data_list, "PRESSURE_S", CWIPLOTPRS.PRESSURE_S);
			TRS.add_double(press_data_list, "PRESSURE_C", CWIPLOTPRS.PRESSURE_C);
			TRS.add_double(press_data_list, "POWER_S", CWIPLOTPRS.POWER_S);
			TRS.add_double(press_data_list, "POWER_C", CWIPLOTPRS.POWER_C);
			TRS.add_double(press_data_list, "CURRENT_S", CWIPLOTPRS.CURRENT_S);
			TRS.add_double(press_data_list, "CURRENT_C", CWIPLOTPRS.CURRENT_C);
			TRS.add_double(press_data_list, "VOLTAGE_C", CWIPLOTPRS.VOLTAGE_C);
			TRS.add_double(press_data_list, "RESITANCE_C", CWIPLOTPRS.RESITANCE_C);
			TRS.add_double(press_data_list, "INCH1", CWIPLOTPRS.INCH_1);
			TRS.add_double(press_data_list, "INCH2", CWIPLOTPRS.INCH_2);
			TRS.add_string(press_data_list, "PROCESS_TIME", CWIPLOTPRS.PROCESS_TIME, sizeof(CWIPLOTPRS.PROCESS_TIME));
			TRS.add_double(press_data_list, "MOLD_TEMP", CWIPLOTPRS.MOLD_TEMP);
		}

	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		//LOT이 존재하는지 확인
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

			return MP_FALSE;
		}

		// 품목 정보 조회
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

			return MP_FALSE;
		}

		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_PROFILE_DATA, strlen(MP_GCM_PROFILE_DATA));
		TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "PROFILE");
		DBU_open_mgcmtbldat(2, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			// GCM-0007 : DATABASE 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "GCM-0007");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN(2)", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "KEY_1", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
			TRS.add_fieldmsg(out_node, "KEY_2", DT_STRING, sizeof(MGCMTBLDAT.KEY_2), MGCMTBLDAT.KEY_2);
			TRS.add_fieldmsg(out_node, "KEY_3", DT_STRING, sizeof(MGCMTBLDAT.KEY_3), MGCMTBLDAT.KEY_3);
			TRS.add_fieldmsg(out_node, "KEY_4", DT_STRING, sizeof(MGCMTBLDAT.KEY_4), MGCMTBLDAT.KEY_4);
			TRS.add_fieldmsg(out_node, "KEY_5", DT_STRING, sizeof(MGCMTBLDAT.KEY_5), MGCMTBLDAT.KEY_5);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		while (1)
		{
			// 20.12.21 minjae.go
			//DBU_fetch_mgcmtbldat(5, &MGCMTBLDAT);
			DBU_fetch_mgcmtbldat(2, &MGCMTBLDAT);
			//
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_mgcmtbldat(2);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				// GCM-0007 : DATABASE 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "GCM-0007");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT FETCH(2)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "KEY_1", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "KEY_2", DT_STRING, sizeof(MGCMTBLDAT.KEY_2), MGCMTBLDAT.KEY_2);
				TRS.add_fieldmsg(out_node, "KEY_3", DT_STRING, sizeof(MGCMTBLDAT.KEY_3), MGCMTBLDAT.KEY_3);
				TRS.add_fieldmsg(out_node, "KEY_4", DT_STRING, sizeof(MGCMTBLDAT.KEY_4), MGCMTBLDAT.KEY_4);
				TRS.add_fieldmsg(out_node, "KEY_5", DT_STRING, sizeof(MGCMTBLDAT.KEY_5), MGCMTBLDAT.KEY_5);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				DBU_close_mgcmtbldat(2);

				return MP_FALSE;
			}

			press_data_list = TRS.add_node(out_node, "PRESS_DATA_LIST");
			//기준이 되는 정보
			TRS.add_string(press_data_list, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_int(press_data_list, "HIST_SEQ", MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ);
			TRS.add_string(press_data_list, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
			TRS.add_string(press_data_list, "PROFILE", MGCMTBLDAT.KEY_4, sizeof(MGCMTBLDAT.KEY_4));
			TRS.add_string(press_data_list, "STEP", MGCMTBLDAT.KEY_5, sizeof(MGCMTBLDAT.KEY_5));
			TRS.add_int(press_data_list, "PERIOD_SEC", COM_atoi(MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1)));

			//데이터 입력 정보

			DBU_init_cwiplotprs(&CWIPLOTPRS);
			TRS.copy(CWIPLOTPRS.FACTORY, sizeof(CWIPLOTPRS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPLOTPRS.LOT_ID, sizeof(CWIPLOTPRS.LOT_ID), in_node, "LOT_ID");
			CWIPLOTPRS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			memcpy(CWIPLOTPRS.STEP, MGCMTBLDAT.KEY_5, sizeof(MGCMTBLDAT.KEY_5));
			TRS.copy(CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE), in_node, "PROFILE");
			DBU_select_cwiplotprs(1, &CWIPLOTPRS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					TRS.add_string(press_data_list, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
					TRS.add_string(press_data_list, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					TRS.add_string(press_data_list, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
					TRS.add_int(press_data_list, "FLOW_SEQ_NUM", MWIPLOTSTSX.FLOW_SEQ_NUM);
					continue;
				}
				else
				{
					//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTPRS SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
					TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
					TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
					TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					DBU_close_mgcmtbldat(2);

					return MP_FALSE;
				}
			}
			else if (DB_error_code == DB_SUCCESS)
			{
				TRS.add_string(press_data_list, "OPER", CWIPLOTPRS.OPER, sizeof(CWIPLOTPRS.OPER));
				TRS.add_string(press_data_list, "MAT_ID", CWIPLOTPRS.MAT_ID, sizeof(CWIPLOTPRS.MAT_ID));
				TRS.add_string(press_data_list, "FLOW", CWIPLOTPRS.FLOW, sizeof(CWIPLOTPRS.FLOW));
				TRS.add_int(press_data_list, "FLOW_SEQ_NUM", CWIPLOTPRS.FLOW_SEQ_NUM);
				TRS.add_string(press_data_list, "WORK_DATE", CWIPLOTPRS.WORK_DATE, sizeof(CWIPLOTPRS.WORK_DATE));
				TRS.add_string(press_data_list, "WORK_TIME", CWIPLOTPRS.WORK_TIME, sizeof(CWIPLOTPRS.WORK_TIME));
				TRS.add_string(press_data_list, "WORK_SHIFT", CWIPLOTPRS.DAY_NIGHT, sizeof(CWIPLOTPRS.DAY_NIGHT));
				TRS.add_double(press_data_list, "PRESSURE_S", CWIPLOTPRS.PRESSURE_S);
				TRS.add_double(press_data_list, "PRESSURE_C", CWIPLOTPRS.PRESSURE_C);
				TRS.add_double(press_data_list, "POWER_S", CWIPLOTPRS.POWER_S);
				TRS.add_double(press_data_list, "POWER_C", CWIPLOTPRS.POWER_C);
				TRS.add_double(press_data_list, "CURRENT_S", CWIPLOTPRS.CURRENT_S);
				TRS.add_double(press_data_list, "CURRENT_C", CWIPLOTPRS.CURRENT_C);
				TRS.add_double(press_data_list, "VOLTAGE_C", CWIPLOTPRS.VOLTAGE_C);
				TRS.add_double(press_data_list, "RESITANCE_C", CWIPLOTPRS.RESITANCE_C);
				TRS.add_double(press_data_list, "INCH1", CWIPLOTPRS.INCH_1);
				TRS.add_double(press_data_list, "INCH2", CWIPLOTPRS.INCH_2);
				TRS.add_string(press_data_list, "PROCESS_TIME", CWIPLOTPRS.PROCESS_TIME, sizeof(CWIPLOTPRS.PROCESS_TIME));
				TRS.add_double(press_data_list, "MOLD_TEMP", CWIPLOTPRS.MOLD_TEMP);
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		//LOT이 존재하는지 확인
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0044");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

			return MP_FALSE;
		}

		// 공정 LOT 잠금 여부 체크
		if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
		{
			// WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
			strcpy(s_msg_code, "WIP-0059");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

			return MP_FALSE;
		}

		// 공정 LOT 삭제 여부 체크
		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			// WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
			strcpy(s_msg_code, "WIP-0076");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

			return MP_FALSE;
		}

		if (memcmp(MWIPLOTSTSX.LOT_STATUS, MP_LOT_STATUS_PROC, strlen(MP_LOT_STATUS_PROC)) != 0)
		{
			// WIP-0595 : 해당 Lot은 작업시작이 되지 않았습니다.
			strcpy(s_msg_code, "WIP-0595");

			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTSX.LOT_STATUS), MWIPLOTSTSX.LOT_STATUS);

			return MP_FALSE;
		}

		if (MWIPLOTSTSX.START_FLAG != 'Y')
		{
			// WIP-0595 : 해당 Lot은 작업시작이 되지 않았습니다.
			strcpy(s_msg_code, "WIP-0595");

			TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTSX.LOT_STATUS), MWIPLOTSTSX.LOT_STATUS);

			return MP_FALSE;
		}

		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
		DBU_select_mrasresdef(1, &MRASRESDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//RAS-0003 : 존재하지 않는 장비입니다.
				strcpy(s_msg_code, "RAS-0003");
			}
			else
			{
				//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
			
			return MP_FALSE;
		}

		DBU_init_mgcmtbldat(&MGCMTBLDAT_RESOURCE);
		TRS.copy(MGCMTBLDAT_RESOURCE.FACTORY, sizeof(MGCMTBLDAT_RESOURCE.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_RESOURCE.TABLE_NAME, MP_GCM_RES_GRP_1, strlen(MP_GCM_RES_GRP_1));
		memcpy(MGCMTBLDAT_RESOURCE.KEY_1, MRASRESDEF.RES_GRP_1, sizeof(MRASRESDEF.RES_GRP_1));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_RESOURCE);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//RAS-0323 : 설비그룹이 제대로 지정되지 않은 장비입니다.
				strcpy(s_msg_code, "RAS-0323");
			}
			else
			{
				//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

			return MP_FALSE;
		}
		
		//PRESS여부를 설비에 지정한게 아니라 이렇게 비교하고 있음 추후 변경될 소지 많음
		if (memcmp(MGCMTBLDAT_RESOURCE.DATA_1, MP_PRESS, strlen(MP_PRESS)) != 0)
		{
			//RAS-0324 : PRESS설비가 아닙니다.
			strcpy(s_msg_code, "RAS-0324");

			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 품목 정보 조회
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
		MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0006 : 이 제품은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		// 추후 VALIDATION 추가 예정
		for (i = 0; i < TRS.get_item_count(in_node, "DATA_LIST"); i++)
		{
			//PRESS 데이터 조회 후 데이터 없으면 INSERT 있으면 UPDATE
			DBU_init_cwiplotprs(&CWIPLOTPRS);
			TRS.copy(CWIPLOTPRS.FACTORY, sizeof(CWIPLOTPRS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPLOTPRS.LOT_ID, sizeof(CWIPLOTPRS.LOT_ID), lot_press_list[i], "LOT_ID");
			CWIPLOTPRS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			TRS.copy(CWIPLOTPRS.STEP, sizeof(CWIPLOTPRS.STEP), lot_press_list[i], "STEP");
			TRS.copy(CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE), in_node, "PROFILE");
			DBU_select_cwiplotprs(1, &CWIPLOTPRS);
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTPRS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
				TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_PRESS_PROFILE_MAP, strlen(MP_GCM_PRESS_PROFILE_MAP));
				TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "AREA");
				TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), in_node, "RES_ID");
				memcpy(MGCMTBLDAT.KEY_3, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.copy(MGCMTBLDAT.KEY_4, sizeof(MGCMTBLDAT.KEY_4), in_node, "PROFILE");
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
					}
					else
					{
						//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_dberrmsg(out_node, DB_error_msg);
					}

					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);

					return MP_FALSE;
				}

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_PROFILE_DATA, strlen(MP_GCM_PROFILE_DATA));
				TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "PROFILE");
				TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), lot_press_list[i], "STEP");
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
						strcpy(s_msg_code, "GCM-0008");
					}
					else
					{
						//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_dberrmsg(out_node, DB_error_msg);
					}

					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);

					return MP_FALSE;
				}

				CWIPLOTPRS.PERIOD_SEC = COM_atoi(MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
				memcpy(CWIPLOTPRS.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				memcpy(CWIPLOTPRS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				memcpy(CWIPLOTPRS.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				CWIPLOTPRS.FLOW_SEQ_NUM = MWIPLOTSTSX.FLOW_SEQ_NUM;
				memcpy(CWIPLOTPRS.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
				memcpy(CWIPLOTPRS.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTPRS.WORK_DATE));
				memcpy(CWIPLOTPRS.WORK_TIME, s_sys_time, sizeof(s_sys_time));
				memcpy(CWIPLOTPRS.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTPRS.DAY_NIGHT));

				//데이터 항목
				CWIPLOTPRS.PRESSURE_S = TRS.get_double(lot_press_list[i], "PRESSURE_S");
				CWIPLOTPRS.PRESSURE_C = TRS.get_double(lot_press_list[i], "PRESSURE_C");
				CWIPLOTPRS.POWER_S = TRS.get_double(lot_press_list[i], "POWER_S");
				CWIPLOTPRS.POWER_C = TRS.get_double(lot_press_list[i], "POWER_C");
				CWIPLOTPRS.CURRENT_S = TRS.get_double(lot_press_list[i], "CURRENT_S");
				CWIPLOTPRS.CURRENT_C = TRS.get_double(lot_press_list[i], "CURRENT_C");
				CWIPLOTPRS.VOLTAGE_C = TRS.get_double(lot_press_list[i], "VOLTAGE_C");
				CWIPLOTPRS.RESITANCE_C = TRS.get_double(lot_press_list[i], "RESITANCE_C");
				CWIPLOTPRS.INCH_1 = TRS.get_double(lot_press_list[i], "INCH1");
				CWIPLOTPRS.INCH_2 = TRS.get_double(lot_press_list[i], "INCH2");
				memcpy(CWIPLOTPRS.PROCESS_TIME, s_sys_time, sizeof(s_sys_time));
				CWIPLOTPRS.MOLD_TEMP = TRS.get_double(lot_press_list[i], "MOLD_TEMP");
				TRS.copy(CWIPLOTPRS.CREATE_USER_ID, sizeof(CWIPLOTPRS.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTPRS.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_insert_cwiplotprs(&CWIPLOTPRS);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTPRS INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
					TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
					TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
					TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}
			else if (DB_error_code == DB_SUCCESS)
			{
				//데이터 항목
				CWIPLOTPRS.PRESSURE_S = TRS.get_double(lot_press_list[i], "PRESSURE_S");
				CWIPLOTPRS.PRESSURE_C = TRS.get_double(lot_press_list[i], "PRESSURE_C");
				CWIPLOTPRS.POWER_S = TRS.get_double(lot_press_list[i], "POWER_S");
				CWIPLOTPRS.POWER_C = TRS.get_double(lot_press_list[i], "POWER_C");
				CWIPLOTPRS.CURRENT_S = TRS.get_double(lot_press_list[i], "CURRENT_S");
				CWIPLOTPRS.CURRENT_C = TRS.get_double(lot_press_list[i], "CURRENT_C");
				CWIPLOTPRS.VOLTAGE_C = TRS.get_double(lot_press_list[i], "VOLTAGE_C");
				CWIPLOTPRS.RESITANCE_C = TRS.get_double(lot_press_list[i], "RESITANCE_C");
				CWIPLOTPRS.INCH_1 = TRS.get_double(lot_press_list[i], "INCH1");
				CWIPLOTPRS.INCH_2 = TRS.get_double(lot_press_list[i], "INCH2");
				memcpy(CWIPLOTPRS.PROCESS_TIME, s_sys_time, sizeof(s_sys_time));
				CWIPLOTPRS.MOLD_TEMP = TRS.get_double(lot_press_list[i], "MOLD_TEMP");
				TRS.copy(CWIPLOTPRS.UPDATE_USER_ID, sizeof(CWIPLOTPRS.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTPRS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_cwiplotprs(2, &CWIPLOTPRS);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTPRS UPDATE()", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
					TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
					TRS.add_fieldmsg(out_node, "STEP", DT_STRING, sizeof(CWIPLOTPRS.STEP), CWIPLOTPRS.STEP);
					TRS.add_fieldmsg(out_node, "PROFILE", DT_STRING, sizeof(CWIPLOTPRS.PROFILE), CWIPLOTPRS.PROFILE);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}
		}
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Lot_Press_Data_Validation()
- Validation Check sub function of "CUS_WIP_LOT_PRESS_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Lot_Press_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"123") == MP_FALSE)
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

/*******************************************************************************
CUS_WIP_Lot_Press_Data_Before_Transaction()
- Main sub function of "CUS_WIP_LOT_PRESS_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Lot_Press_Data_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Lot_Press_Data_After_Transaction()
- Main sub function of "CUS_WIP_LOT_PRESS_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Lot_Press_Data_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}