/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_EIS_collect_ballmill_data.c
Description : Ball Mill 설비 데이터 수집

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2022/03/23  정광용        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"
#include <math.h>

int CUS_EIS_COLLECT_BALLMILL_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_BALLMILL_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node);

/*******************************************************************************
CUS_EIS_Collect_Ballmill_Data()
- Ball Mill 설비 데이터 수집
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Ballmill_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_BALLMILL_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_BallMill_Data", out_node);

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
CUS_EIS_COLLECT_BALLMILL_DATA()
- Main sub function of "CUS_EIS_Collect_Ballmill_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_BALLMILL_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MRASRESEVN_TAG MRASRESEVN;
    struct MRASEVNDEF_TAG MRASEVNDEF;
    struct MEDCCOLVER_TAG MEDCCOLVER;
    struct MEDCCOLCHR_TAG MEDCCOLCHR;
	struct CRASBALMIL_TAG CRASBALMIL;
	struct CRASBALMIL_TAG CRASBALMIL_START;
    struct work_date_tag work_date;

    TRSNode *event_node;
    TRSNode *Core_Collect_Res_Data_In;
    TRSNode *char_list;
    TRSNode *unit_list;
    TRSNode *value_list;

    char s_factory[10];
     
    LOG_head("CUS_EIS_COLLECT_BALLMILL_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Validation_CUS_EIS_COLLECT_BALLMILL_DATA(s_msg_code, in_node, &MRASRESDEF, out_node) == MP_FALSE)
        return MP_FALSE;

    memset(s_factory, ' ', sizeof(s_factory));
    memset(&work_date, ' ', sizeof(work_date));
     
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);    
    Get_shift(s_factory, &work_date);
    
	//이벤트 ID를 받는지 체크
	if (COM_isnullspace(TRS.get_string(in_node, "EVENT_ID")) == MP_TRUE)
	{
		TRS.add_fieldmsg(out_node, "EVENT ID is empty", MP_NVST);
		TRS.add_fieldmsg(out_node, "RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));

		return MP_FALSE;
	}

	//이전 설비 상태가 '0'인경우 데이터를 '0'값을 중복으로 받지 못하게 한다.
	if (TRS.get_char(in_node, "EQ_STS") == '0')
	{
		DBU_init_crasbalmil(&CRASBALMIL);
		memcpy(CRASBALMIL.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASBALMIL.RES_ID));

		//Procstep : CONTROLLER
		if (TRS.get_procstep(in_node) == '1')
		{
			memcpy(CRASBALMIL.CMF_1, "1", strlen("1"));
		}
		else if (TRS.get_procstep(in_node) == '2')
		{
			memcpy(CRASBALMIL.CMF_1, "2", strlen("2"));
		}
		else if (TRS.get_procstep(in_node) == '3')
		{
			memcpy(CRASBALMIL.CMF_1, "3", strlen("3"));
		}
		else if (TRS.get_procstep(in_node) == '4')
		{
			memcpy(CRASBALMIL.CMF_1, "4", strlen("4"));
		}

		DBU_select_crasbalmil(3, &CRASBALMIL);
		if (DB_error_code == DB_SUCCESS)
		{
			if (CRASBALMIL.RES_STATUS == '0')
			{
				TRS.add_fieldmsg(out_node, "Before Res Status is 0", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

				return MP_FALSE;
			}
		}
	}
	// 설비 상태 2인데, 설정시간과 측정시간이 동일하다면, 대기 상태이므로 데이터 저장을 하지 않는다.
	else if (TRS.get_char(in_node, "EQ_STS") == '2')
	{
		DBU_init_crasbalmil(&CRASBALMIL);
		memcpy(CRASBALMIL.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASBALMIL.RES_ID));

		//Procstep : CONTROLLER
		if (TRS.get_procstep(in_node) == '1')
		{
			memcpy(CRASBALMIL.CMF_1, "1", strlen("1"));
		}
		else if (TRS.get_procstep(in_node) == '2')
		{
			memcpy(CRASBALMIL.CMF_1, "2", strlen("2"));
		}
		else if (TRS.get_procstep(in_node) == '3')
		{
			memcpy(CRASBALMIL.CMF_1, "3", strlen("3"));
		}
		else if (TRS.get_procstep(in_node) == '4')
		{
			memcpy(CRASBALMIL.CMF_1, "4", strlen("4"));
		}

		TRS.copy(CRASBALMIL.SV_TIME, sizeof(CRASBALMIL.SV_TIME), in_node, "SV_TIME");
		TRS.copy(CRASBALMIL.PV_TIME, sizeof(CRASBALMIL.PV_TIME), in_node, "PV_TIME");

		DBU_select_crasbalmil(4, &CRASBALMIL);
		if (DB_error_code == DB_SUCCESS)
		{
			TRS.add_fieldmsg(out_node, "Before Res Status is wait", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

			return MP_FALSE; 
		}
	}

	//Event가 속해 있는지 확인
	DBC_init_mrasresevn(&MRASRESEVN);
	TRS.copy(MRASRESEVN.FACTORY, sizeof(MRASRESEVN.FACTORY), in_node, IN_FACTORY);
	memcpy(MRASRESEVN.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
	TRS.copy(MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID), in_node, "EVENT_ID");
	DBC_select_mrasresevn(1, &MRASRESEVN);
	if (DB_error_code != DB_SUCCESS)
	{
		TRS.add_fieldmsg(out_node, "Select &MRASRESEVN 1", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESEVN.FACTORY), MRASRESEVN.FACTORY);
		TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESEVN.RES_ID), MRASRESEVN.RES_ID);
		TRS.add_fieldmsg(out_node, "EVENT_ID", DT_STRING, sizeof(MRASRESEVN.EVENT_ID), MRASRESEVN.EVENT_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	//설비 이벤트 확인 - COL SET 정보 조회용.
	DBC_init_mrasevndef(&MRASEVNDEF);
	TRS.copy(MRASEVNDEF.FACTORY, sizeof(MRASEVNDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(MRASEVNDEF.EVENT_ID, MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID));
	DBC_select_mrasevndef(1, &MRASEVNDEF);
	if (DB_error_code != DB_SUCCESS)
	{
		TRS.add_fieldmsg(out_node, "Select &MRASEVNDEF 1", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASEVNDEF.FACTORY), MRASEVNDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "EVENT_ID", DT_STRING, sizeof(MRASEVNDEF.EVENT_ID), MRASEVNDEF.EVENT_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	if (MRASEVNDEF.COL_SET_ID[0] == ' ')
	{
		TRS.add_fieldmsg(out_node, "No ColSet ID", DT_NOVALUESTRING);
		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	//Collection Set 최신 Version 구하기
	DBC_init_medccolver(&MEDCCOLVER);
	TRS.copy(MEDCCOLVER.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
	memcpy(MEDCCOLVER.COL_SET_ID, MRASEVNDEF.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID));
	DBC_select_medccolver(2, &MEDCCOLVER);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "EDC-0048");
		}
		else
		{
			strcpy(s_msg_code, "EDC-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
		}

		TRS.add_fieldmsg(out_node, "MEDCCOLVER SELECT 2", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
		TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	event_node = TRS.add_node(in_node, "COLLECT_RES_DATA");
	CopyDefaultMembers(event_node, in_node);
	TRS.add_char(event_node, IN_PROCSTEP, '4');
	TRS.add_string(event_node, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
	TRS.add_string(event_node, "EVENT_ID", MRASEVNDEF.EVENT_ID, sizeof(MRASEVNDEF.EVENT_ID));

	Core_Collect_Res_Data_In = TRS.add_node(event_node, "COLLECT_RES_DATA");
	CopyDefaultMembers(Core_Collect_Res_Data_In, event_node);
	TRS.add_char(Core_Collect_Res_Data_In, IN_PROCSTEP, '4');
	TRS.add_string(Core_Collect_Res_Data_In, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
	TRS.add_string(Core_Collect_Res_Data_In, "EVENT_ID", MRASEVNDEF.EVENT_ID, sizeof(MRASEVNDEF.EVENT_ID));
	TRS.add_int(Core_Collect_Res_Data_In, "HIST_SEQ", MRASRESDEF.LAST_ACTIVE_HIST_SEQ);
	TRS.add_string(Core_Collect_Res_Data_In, "COL_SET_ID", MRASEVNDEF.COL_SET_ID, sizeof(MRASEVNDEF.COL_SET_ID));
	TRS.add_int(Core_Collect_Res_Data_In, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);

	//COL SET의 케릭터별 데이터를 넣는다.
	DBC_init_medccolchr(&MEDCCOLCHR);
	TRS.copy(MEDCCOLCHR.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
	memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
	MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;
	DBC_open_medccolchr(3, &MEDCCOLCHR);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0585");
		TRS.add_fieldmsg(out_node, "MEDCCOLCHR OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
		TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}
	while (1)
	{
		DBC_fetch_medccolchr(3, &MEDCCOLCHR);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_medccolchr(3);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0585");
			TRS.add_fieldmsg(out_node, "MEDCCOLCHR FETCH", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
			TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			DBU_close_medccolchr(3);
			return MP_FALSE;
		}

		char_list = TRS.add_node(Core_Collect_Res_Data_In, "CHAR_LIST");
		TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));
		unit_list = TRS.add_node(char_list, "UNIT_LIST");
		TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);

		value_list = TRS.add_node(unit_list, "VALUE_LIST");

		if (memcmp(MEDCCOLCHR.CHAR_ID, "SV_TIME", strlen("SV_TIME")) == MP_FALSE)
		{
			TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "SV_TIME"));
		}

		if (memcmp(MEDCCOLCHR.CHAR_ID, "PV_TIME", strlen("PV_TIME")) == MP_FALSE)
		{
			TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "PV_TIME"));
		}

		if (memcmp(MEDCCOLCHR.CHAR_ID, "SV_RPM", strlen("SV_RPM")) == MP_FALSE)
		{
			TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "SV_RPM"));
		}

		if (memcmp(MEDCCOLCHR.CHAR_ID, "PV_RPM", strlen("PV_RPM")) == MP_FALSE)
		{
			TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "PV_RPM"));
		}
	}

	//설비 이벤트를 보내 edc가 자동으로 쌓이도록 한다.
	if (RAS_RESOURCE_EVENT(s_msg_code, event_node, out_node) == MP_FALSE)
		return MP_FALSE;

	//설비데이터를 코어에 저장 후 설비 hist seq가 오르므로 설비를 재조회 한다. 
	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);

	DBU_init_crasbalmil(&CRASBALMIL);
	memcpy(CRASBALMIL.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASBALMIL.RES_ID));
	CRASBALMIL.HIST_SEQ = MRASRESDEF.LAST_ACTIVE_HIST_SEQ;
	memcpy(CRASBALMIL.WORK_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
	memcpy(CRASBALMIL.FACTORY, MRASRESDEF.FACTORY, sizeof(CRASBALMIL.FACTORY));
	memcpy(CRASBALMIL.WORK_DATE, work_date.s_work_date, sizeof(work_date.s_work_date));
	memcpy(CRASBALMIL.DAY_NIGHT, work_date.s_day_night, sizeof(work_date.s_day_night));

	if (COM_isnullspace(TRS.get_string(in_node, "SV_TIME")) == MP_FALSE)
		TRS.copy(CRASBALMIL.SV_TIME, sizeof(CRASBALMIL.SV_TIME), in_node, "SV_TIME");

	if (COM_isnullspace(TRS.get_string(in_node, "PV_TIME")) == MP_FALSE)
		TRS.copy(CRASBALMIL.PV_TIME, sizeof(CRASBALMIL.PV_TIME), in_node, "PV_TIME");

	if (COM_isnullspace(TRS.get_string(in_node, "SV_RPM")) == MP_FALSE)
		CRASBALMIL.SV_RPM = atof(TRS.get_string(in_node, "SV_RPM"));

	if (COM_isnullspace(TRS.get_string(in_node, "PV_RPM")) == MP_FALSE)
		CRASBALMIL.PV_RPM = atof(TRS.get_string(in_node, "PV_RPM"));

	CRASBALMIL.RES_STATUS = TRS.get_char(in_node, "EQ_STS");

	//Procstep : CONTROLLER
	if (TRS.get_procstep(in_node) == '1')
	{
		memcpy(CRASBALMIL.CMF_1, "1", strlen("1"));
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		memcpy(CRASBALMIL.CMF_1, "2", strlen("2"));
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		memcpy(CRASBALMIL.CMF_1, "3", strlen("3"));
	}
	else if (TRS.get_procstep(in_node) == '4')
	{
		memcpy(CRASBALMIL.CMF_1, "4", strlen("4"));
	}

	//EQ_STS : 0 : 종료 , 1: 시작, 2: 작업중
	if (CRASBALMIL.RES_STATUS == '1')
		memcpy(CRASBALMIL.START_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
	else if (CRASBALMIL.RES_STATUS == '2' || CRASBALMIL.RES_STATUS == '0')
	{
		DBU_init_crasbalmil(&CRASBALMIL_START);
		memcpy(CRASBALMIL_START.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASBALMIL_START.RES_ID));
		memcpy(CRASBALMIL_START.CMF_1, CRASBALMIL.CMF_1, sizeof(CRASBALMIL_START.CMF_1));
		DBU_select_crasbalmil(2, &CRASBALMIL_START);

		if (DB_error_code == DB_SUCCESS)
		{
			memcpy(CRASBALMIL.START_TIME, CRASBALMIL_START.START_TIME, sizeof(CRASBALMIL.START_TIME));
		}

		if (CRASBALMIL.RES_STATUS == '0')
			memcpy(CRASBALMIL.END_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
	}

	memcpy(CRASBALMIL.EVENT_ID, MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID));

	TRS.copy(CRASBALMIL.CREATE_USER_ID, sizeof(CRASBALMIL.CREATE_USER_ID), in_node, IN_USERID);
	memcpy(CRASBALMIL.CREATE_TIME, gs_sys_time, sizeof(CRASBALMIL.CREATE_TIME));

	DBU_insert_crasbalmil(&CRASBALMIL);
	if (DB_error_code != DB_SUCCESS)
	{
		TRS.add_fieldmsg(out_node, "CRASBALMIL Insert", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRASBALMIL.RES_ID), CRASBALMIL.RES_ID);

		TRS.add_dberrmsg(out_node, DB_error_msg);

		return MP_FALSE;
	}
    
    return MP_TRUE;
}

/*******************************************************************************
Validation_CUS_EIS_COLLECT_BALLMILL_DATA()
- Main sub function of "CUS_EIS_COLLECT_BALLMILL_DATA" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- struct MRASRESDEF_TAG *MRASRESDEF : 설비
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_BALLMILL_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node)
{
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "1234") == MP_FALSE)
        return MP_FALSE;

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
