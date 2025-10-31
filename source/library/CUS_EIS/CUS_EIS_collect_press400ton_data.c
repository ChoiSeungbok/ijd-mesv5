/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_EIS_collect_press400ton_data.c
Description : 400ton Press 설비 데이터 수집

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

int CUS_EIS_COLLECT_PRESS400TON_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_PRESS400TON_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node);

/*******************************************************************************
CUS_EIS_Collect_Press400ton_Data()
- 400ton Press 설비 데이터 수집
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Press400ton_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_PRESS400TON_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Press400ton_Data", out_node);

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
CUS_EIS_COLLECT_PRESS400TON_DATA()
- Main sub function of "CUS_EIS_Collect_Press400ton_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_PRESS400TON_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MRASRESEVN_TAG MRASRESEVN;
    //struct MRASEVNDEF_TAG MRASEVNDEF;
    //struct MEDCCOLVER_TAG MEDCCOLVER;
    //struct MEDCCOLCHR_TAG MEDCCOLCHR;
	struct CRAS4HRPRS_TAG CRAS4HRPRS;
	struct CRAS4HRPRS_TAG CRAS4HRPRS_START;
    struct work_date_tag work_date;

    //TRSNode *event_node;
    //TRSNode *Core_Collect_Res_Data_In;
    //TRSNode *char_list;
    //TRSNode *unit_list;
    //TRSNode *value_list;

    char s_factory[10];
	char s_sys_time_temp[20];
	char s_sys_msend_time[17];
	//char s_eap_sys_time[14];
     
    LOG_head("CUS_EIS_COLLECT_PRESS400TON_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Validation_CUS_EIS_COLLECT_PRESS400TON_DATA(s_msg_code, in_node, &MRASRESDEF, out_node) == MP_FALSE)
        return MP_FALSE;

	memset(s_sys_time_temp, ' ', sizeof(s_sys_time_temp));
	memset(s_sys_msend_time, ' ', sizeof(s_sys_msend_time));
    memset(s_factory, ' ', sizeof(s_factory));
    memset(&work_date, ' ', sizeof(work_date));

	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);

	//1초에 1개씩의 데이터 수집을 하기때문에, MES가 메세지를 받은 시간이 아닌 MC에서 보낸 시간으로 체크 및 저장
	/*if (COM_isnullspace(TRS.get_string(in_node, "TRAN_TIME")) == MP_FALSE)
	{
		TRS.copy(s_eap_sys_time, sizeof(s_eap_sys_time), in_node, "TRAN_TIME");
		Get_shift_EAP(s_factory, &work_date, s_eap_sys_time);
	}
	else
	{
		Get_shift(s_factory, &work_date);
	}*/

	Get_shift(s_factory, &work_date);

	//MC에서 1초 이내로 쏘는 경우가 존재하여, MES에서 작업시간 단위를 밀리세컨즈까지로 변경
	DB_get_systime_m(s_sys_time_temp);

	if (DB_error_code != DB_SUCCESS)
	{
		TRS.add_fieldmsg(out_node, "s_sys_time_m", MP_NVST);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;

		COM_set_result(out_node, MP_FAIL_C, "CMN-0004", MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memcpy(s_sys_msend_time, s_sys_time_temp, sizeof(s_sys_msend_time));
    
    if (TRS.get_procstep(in_node) == '1')
    {
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
            DBU_init_cras4hrprs(&CRAS4HRPRS);
            memcpy(CRAS4HRPRS.RES_ID, MRASRESDEF.RES_ID, sizeof(CRAS4HRPRS.RES_ID));
            DBU_select_cras4hrprs(3, &CRAS4HRPRS);
            if (DB_error_code == DB_SUCCESS)
            {
                if (CRAS4HRPRS.RES_STATUS == '0')
                {
                    TRS.add_fieldmsg(out_node, "Before Res Status is 0", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

                    return MP_FALSE;
                }
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
        /*DBC_init_mrasevndef(&MRASEVNDEF);
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
        }*/

		// 1초에 1번씩 수집하는 데이터 방식으로, EDC 데이터 생성 불가
		// 처리속도가 1초 이상이 되면서, 메세지 유실 발생

        //Collection Set 최신 Version 구하기
        //DBC_init_medccolver(&MEDCCOLVER);
        //TRS.copy(MEDCCOLVER.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
        //memcpy(MEDCCOLVER.COL_SET_ID, MRASEVNDEF.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID));
        //DBC_select_medccolver(2, &MEDCCOLVER);
        //if (DB_error_code != DB_SUCCESS)
        //{
        //    if (DB_error_code == DB_NOT_FOUND)
        //    {
        //        strcpy(s_msg_code, "EDC-0048");
        //    }
        //    else
        //    {
        //        strcpy(s_msg_code, "EDC-0004");
        //        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        //    }

        //    TRS.add_fieldmsg(out_node, "MEDCCOLVER SELECT 2", DT_NOVALUESTRING);
        //    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
        //    TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

        //    TRS.add_dberrmsg(out_node, DB_error_msg);
        //    return MP_FALSE;
        //}

        //event_node = TRS.add_node(in_node, "COLLECT_RES_DATA");
        //CopyDefaultMembers(event_node, in_node);
        //TRS.add_char(event_node, IN_PROCSTEP, '4');
        //TRS.add_string(event_node, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        //TRS.add_string(event_node, "EVENT_ID", MRASEVNDEF.EVENT_ID, sizeof(MRASEVNDEF.EVENT_ID));

        //Core_Collect_Res_Data_In = TRS.add_node(event_node, "COLLECT_RES_DATA");
        //CopyDefaultMembers(Core_Collect_Res_Data_In, event_node);
        //TRS.add_char(Core_Collect_Res_Data_In, IN_PROCSTEP, '4');
        //TRS.add_string(Core_Collect_Res_Data_In, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        //TRS.add_string(Core_Collect_Res_Data_In, "EVENT_ID", MRASEVNDEF.EVENT_ID, sizeof(MRASEVNDEF.EVENT_ID));
        //TRS.add_int(Core_Collect_Res_Data_In, "HIST_SEQ", MRASRESDEF.LAST_ACTIVE_HIST_SEQ);
        //TRS.add_string(Core_Collect_Res_Data_In, "COL_SET_ID", MRASEVNDEF.COL_SET_ID, sizeof(MRASEVNDEF.COL_SET_ID));
        //TRS.add_int(Core_Collect_Res_Data_In, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);

        ////COL SET의 케릭터별 데이터를 넣는다.
        //DBC_init_medccolchr(&MEDCCOLCHR);
        //TRS.copy(MEDCCOLCHR.FACTORY, sizeof(MEDCCOLVER.FACTORY), in_node, IN_FACTORY);
        //memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
        //MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;
        //DBC_open_medccolchr(3, &MEDCCOLCHR);
        //if (DB_error_code != DB_SUCCESS)
        //{
        //    strcpy(s_msg_code, "WIP-0585");
        //    TRS.add_fieldmsg(out_node, "MEDCCOLCHR OPEN", MP_NVST);
        //    TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
        //    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
        //    TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
        //    TRS.add_dberrmsg(out_node, DB_error_msg);

        //    return MP_FALSE;
        //}
        //while (1)
        //{
        //    DBC_fetch_medccolchr(3, &MEDCCOLCHR);
        //    if (DB_error_code == DB_NOT_FOUND)
        //    {
        //        DBU_close_medccolchr(3);
        //        break;
        //    }
        //    else if (DB_error_code != DB_SUCCESS)
        //    {
        //        strcpy(s_msg_code, "WIP-0585");
        //        TRS.add_fieldmsg(out_node, "MEDCCOLCHR FETCH", MP_NVST);
        //        TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
        //        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
        //        TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
        //        TRS.add_dberrmsg(out_node, DB_error_msg);

        //        DBU_close_medccolchr(3);
        //        return MP_FALSE;
        //    }

        //    char_list = TRS.add_node(Core_Collect_Res_Data_In, "CHAR_LIST");
        //    TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));
        //    unit_list = TRS.add_node(char_list, "UNIT_LIST");
        //    TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);

        //    value_list = TRS.add_node(unit_list, "VALUE_LIST");
        //    
        //    if (memcmp(MEDCCOLCHR.CHAR_ID, "SV_PRESSURE", strlen("SV_PRESSURE")) == MP_FALSE)
        //    {                
        //        TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "SV_PRESSURE"));
        //    }

        //    if (memcmp(MEDCCOLCHR.CHAR_ID, "PV_PRESSURE", strlen("PV_PRESSURE")) == MP_FALSE)
        //    {
        //        TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "PV_PRESSURE"));
        //    }
        //}
   
        ////설비 이벤트를 보내 edc가 자동으로 쌓이도록 한다.
        //if (RAS_RESOURCE_EVENT(s_msg_code, event_node, out_node) == MP_FALSE)
        //    return MP_FALSE;

        //설비데이터를 코어에 저장 후 설비 hist seq가 오르므로 설비를 재조회 한다. 
        DBU_init_mrasresdef(&MRASRESDEF);
        TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
        DBU_select_mrasresdef(1, &MRASRESDEF);

        DBU_init_cras4hrprs(&CRAS4HRPRS);
        memcpy(CRAS4HRPRS.RES_ID, MRASRESDEF.RES_ID, sizeof(CRAS4HRPRS.RES_ID));
		CRAS4HRPRS.HIST_SEQ = MRASRESDEF.LAST_ACTIVE_HIST_SEQ;
        memcpy(CRAS4HRPRS.WORK_TIME, s_sys_msend_time, sizeof(s_sys_msend_time));
        memcpy(CRAS4HRPRS.FACTORY, MRASRESDEF.FACTORY, sizeof(CRAS4HRPRS.FACTORY));
        memcpy(CRAS4HRPRS.WORK_DATE, work_date.s_work_date, sizeof(work_date.s_work_date));
        memcpy(CRAS4HRPRS.DAY_NIGHT, work_date.s_day_night, sizeof(work_date.s_day_night));

        if (COM_isnullspace(TRS.get_string(in_node, "SV_PRESSURE")) == MP_FALSE)
			CRAS4HRPRS.SV_PRESSURE = atof(TRS.get_string(in_node, "SV_PRESSURE"));

        if (COM_isnullspace(TRS.get_string(in_node, "PV_PRESSURE")) == MP_FALSE)
			CRAS4HRPRS.PV_PRESSURE = atof(TRS.get_string(in_node, "PV_PRESSURE"));

		CRAS4HRPRS.RES_STATUS = TRS.get_char(in_node, "EQ_STS");
        
        //EQ_STS : 0 : 종료 , 1: 시작, 2: 작업중
        if (CRAS4HRPRS.RES_STATUS == '1')
            memcpy(CRAS4HRPRS.START_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
        else if (CRAS4HRPRS.RES_STATUS == '2' || CRAS4HRPRS.RES_STATUS == '0')
        { 
            DBU_init_cras4hrprs(&CRAS4HRPRS_START);
            memcpy(CRAS4HRPRS_START.RES_ID, MRASRESDEF.RES_ID, sizeof(CRAS4HRPRS_START.RES_ID));
            DBU_select_cras4hrprs(2, &CRAS4HRPRS_START);

            if (DB_error_code == DB_SUCCESS)
            {
                memcpy(CRAS4HRPRS.START_TIME, CRAS4HRPRS_START.START_TIME, sizeof(CRAS4HRPRS.START_TIME));
            }

            if (CRAS4HRPRS.RES_STATUS == '0')
                memcpy(CRAS4HRPRS.END_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
        }

        memcpy(CRAS4HRPRS.EVENT_ID, MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID));

        TRS.copy(CRAS4HRPRS.CREATE_USER_ID, sizeof(CRAS4HRPRS.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CRAS4HRPRS.CREATE_TIME, gs_sys_time, sizeof(CRAS4HRPRS.CREATE_TIME));

		//MC에서 1초마다지만 같은 초에 2개의 메세지를 쏘는 경우가 있음. 이럴 경우, MES에서 HIST_SEQ를 증가
		DBU_select_cras4hrprs(1, &CRAS4HRPRS);
		if (DB_error_code == DB_SUCCESS)
		{
			CRAS4HRPRS.HIST_SEQ++;
		}

        DBU_insert_cras4hrprs(&CRAS4HRPRS);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CRAS4HRPRS Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRAS4HRPRS.RES_ID), CRAS4HRPRS.RES_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
Validation_CUS_EIS_COLLECT_PRESS400TON_DATA()
- Main sub function of "CUS_EIS_COLLECT_PRESS400TON_DATA" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- struct MRASRESDEF_TAG *MRASRESDEF : 설비
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_PRESS400TON_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node)
{
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "12") == MP_FALSE)
        return MP_FALSE;

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
