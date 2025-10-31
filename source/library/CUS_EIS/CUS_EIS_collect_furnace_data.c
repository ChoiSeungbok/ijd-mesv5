/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_EIS_collect_furnace_data.c
Description : 열처리로 설비 데이터 수집(바인더열처리로 & 디왁싱로 설비)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/07/16  이우길        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"
#include <math.h>

int CUS_EIS_COLLECT_FURNACE_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_FURNACE_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node);

/*******************************************************************************
CUS_EIS_Collect_Furnace_Data()
- 열처리로 설비 데이터 수집(바인더열처리로 & 디왁싱로 설비)
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Furnace_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_FURNACE_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Furnace_Data", out_node);

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
CUS_EIS_COLLECT_FURNACE_DATA()
- Main sub function of "CUS_EIS_Collect_Resource_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_FURNACE_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MRASRESEVN_TAG MRASRESEVN;
    struct MRASEVNDEF_TAG MRASEVNDEF;
    struct MEDCCOLVER_TAG MEDCCOLVER;
    struct MEDCCOLCHR_TAG MEDCCOLCHR;
    //struct MEDCCHRDEF_TAG MEDCCHRDEF;
    struct CRASHITFNC_TAG CRASHITFNC;
    struct CRASHITFNC_TAG CRASHITFNC_START;
    struct work_date_tag work_date;

    TRSNode *event_node;
    TRSNode *Core_Collect_Res_Data_In;
    TRSNode *char_list;
    TRSNode *unit_list;
    TRSNode *value_list;

    char s_factory[10];
    char s_Value_Tmp[25];
    //int iColCharCnt = 0;
    //int i = 0;
    unsigned int u_bit_1;
    unsigned int u_bit_2;
    unsigned int u_bit_value_buho;
    unsigned int u_bit_value;
    unsigned int u_5bit;
    unsigned int u_Exponent;
    unsigned int u_buho;
    unsigned int u_decimal_point;
    double dVaccum = 0;
     
    LOG_head("CUS_EIS_COLLECT_FURNACE_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Validation_CUS_EIS_COLLECT_FURNACE_DATA(s_msg_code, in_node, &MRASRESDEF, out_node) == MP_FALSE)
        return MP_FALSE;

    memset(s_factory, ' ', sizeof(s_factory));
    memset(s_Value_Tmp, ' ', sizeof(s_Value_Tmp));
    memset(&work_date, ' ', sizeof(work_date));
     
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);    
    Get_shift(s_factory, &work_date);
    
    if (TRS.get_procstep(in_node) == '1')
    {
        //이벤트 ID를 받는지 체크
        if (COM_isnullspace(TRS.get_string(in_node, "EVENT_ID")) == MP_TRUE)
        {
            TRS.add_fieldmsg(out_node, "EVENT ID is empty", MP_NVST);
            TRS.add_fieldmsg(out_node, "RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));

            return MP_FALSE;
        }

        //20240625 일단 이거 제거...EQ_STS값 계속 0으로 오는 경우 있는거 같음.(MC 모델확인해보기는 해야됨,일단 제거함.)
        
        //이전 설비 상태가 '0'인경우 데이터를 '0'값을 중복으로 받지 못하게 한다.
        if (TRS.get_char(in_node, "EQ_STS") == '0')
        {
            DBU_init_crashitfnc(&CRASHITFNC);
            memcpy(CRASHITFNC.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASHITFNC.RES_ID));
            DBU_select_crashitfnc(3, &CRASHITFNC);
            if (DB_error_code == DB_SUCCESS)
            {
                if (CRASHITFNC.RES_STATUS == '0')
                {
                    TRS.add_fieldmsg(out_node, "Before Res Status is 0", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

                    return MP_FALSE;
                }
            }
        }
        

        // 바인더인 경우 VACCUM 값이 16비트로 들어오기 때문에 비트를 unsigned int값으로 받아
        // 비트를 잘라 값을 계산한다. 
        if (TRS.get_ushort(in_node, "VACCUM_BIT_1") != 0 && TRS.get_ushort(in_node, "VACCUM_BIT_2") != 0)
        {
            //첫번째 16비트
            //0 : 값의 부호, 1~10 : 값 , 11 : 지수의 부호, 12~15: 지수 값
            u_bit_1 = TRS.get_ushort(in_node, "VACCUM_BIT_1");

            //1~10 값의 비트를 비트마스킹 하여 5자리 SHIFT하여 INT값으로 받는다. 
            //unsigned int 이므로 비트 마스킹 할때 앞에 0x뒤에 0000을 붙여준다.
            u_bit_value = (u_bit_1 & 0x00007FE0) >> 5;   
            //0 자리를 비트마스킹 하여 15자리 SHIFT 하여 값의 부호값을 받는다. 
            u_bit_value_buho = (u_bit_1 & 0x00008000) >> 15;
            //11~15: 부호 + 지수 값을 비트마스킹 한다. 
            u_5bit = u_bit_1 & 0x0000001F;
            //지수의 부호를 받기 위해 4자리 SHIFT
            u_buho = u_5bit >> 4;
            //지수의 값 을 비트마스킹 하여 받는다. 
            u_Exponent = u_bit_1 & 0x0000000F;

            //두번째 16비트
            //12~15: 소수점 자리 값
            u_bit_2 = TRS.get_ushort(in_node, "VACCUM_BIT_2");
            //소수점 자리(마지막4비트)를 비트마스킹 하여 받는다. 
            u_decimal_point = u_bit_2 & 0x0000000F;

            //VACCUM값 계산. 
            // 1. 소수점 계산 
            dVaccum = (double)u_bit_value / pow(10, (double)u_decimal_point);

            // 2. 지수 부호에 따라 E의 N승을 계산 한다. 
            // 부호값 0 인경우 양수, 1인경우 음수
            if (u_buho == 0)    
            {
                dVaccum = dVaccum * pow(10, (double)u_Exponent);
            }
            else if (u_buho == 1)
            {
                dVaccum = dVaccum / pow(10, (double)u_Exponent);
            }

            //값의 부호를 곱해준다. 
            // 부호값 0 인경우 양수, 1인경우 음수
            if (u_bit_value_buho == 1)
                dVaccum = dVaccum * -1;
        }

        //Event가 속해 있는지 확인
        DBC_init_mrasresevn(&MRASRESEVN);
        TRS.copy(MRASRESEVN.FACTORY, sizeof(MRASRESEVN.FACTORY), in_node, IN_FACTORY);
        memcpy(MRASRESEVN.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        TRS.copy(MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID), in_node, "EVENT_ID");
        //memcpy(MRASRESEVN.EVENT_ID, "BINDER_DATA", strlen("BINDER_DATA"));
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

        //DBU_init_medccolchr(&MEDCCOLCHR);
        //memcpy(MEDCCOLCHR.FACTORY, MEDCCOLVER.FACTORY, sizeof(MEDCCOLCHR.FACTORY));
        //memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
        //MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;
        //iColCharCnt = (int)DBU_select_medccolchr_scalar(101, &MEDCCOLCHR);

        //if (iColCharCnt != in_node->SCount)
        //{
        //    //EDC-1001 : Collection Set의 character 갯수와 설비에서 전송한 Character 갯수가 일치하지 않습니다.
        //    strcpy(s_msg_code, "EDC-1001");

        //    TRS.add_fieldmsg(out_node, "Collection Set Cnt", DT_NOVALUESTRING);
        //    TRS.add_fieldmsg(out_node, "RES_CNT", DT_INT, in_node->SCount);
        //    TRS.add_fieldmsg(out_node, "COL_CTN", DT_INT, iColCharCnt);

        //    return MP_FALSE;
        //}

        event_node = TRS.add_node(in_node, "COLLECT_RES_DATA");
        CopyDefaultMembers(event_node, in_node);
        TRS.add_char(event_node, IN_PROCSTEP, '4');
        TRS.add_string(event_node, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
        TRS.add_string(event_node, "EVENT_ID", MRASEVNDEF.EVENT_ID, sizeof(MRASEVNDEF.EVENT_ID));

        Core_Collect_Res_Data_In = TRS.add_node(event_node, "COLLECT_RES_DATA");
        CopyDefaultMembers(Core_Collect_Res_Data_In, event_node);
        TRS.add_char(Core_Collect_Res_Data_In, IN_PROCSTEP, '4');
        //TRS.add_char(Core_Collect_Res_Data_In, IN_PROCSTEP, '1');
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
            
            if (memcmp(MEDCCOLCHR.CHAR_ID, "SV_TEMP", strlen("SV_TEMP")) == MP_FALSE)
            {                
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "TEMP_SV"));
            }

            if (memcmp(MEDCCOLCHR.CHAR_ID, "PV_TEMP", strlen("PV_TEMP")) == MP_FALSE)
            {
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "TEMP_PV"));
            }

            if (memcmp(MEDCCOLCHR.CHAR_ID, "VACCUM_PV1", strlen("VACCUM_PV1")) == MP_FALSE)
            {
                //바인더인 경우 VACCUM_PV1값은 계산된 dVaccum을 넣는다. 
                if (dVaccum != 0)
                {                    
                    COM_dtoa(s_Value_Tmp, dVaccum, sizeof(s_Value_Tmp));
                    TRS.add_string(value_list, "VALUE", s_Value_Tmp, sizeof(s_Value_Tmp));
                }
                else 
                    TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "VACCUM_PV1"));
            }

            if (memcmp(MEDCCOLCHR.CHAR_ID, "VACCUM_PV2", strlen("VACCUM_PV2")) == MP_FALSE)
            {
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "VACCUM_PV2"));
            } 

            if (memcmp(MEDCCOLCHR.CHAR_ID, "THROTTLE_SV", strlen("THROTTLE_SV")) == MP_FALSE)
            {
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "THROTTLE_SV"));
            }

            if (memcmp(MEDCCOLCHR.CHAR_ID, "THROTTLE_PV", strlen("THROTTLE_PV")) == MP_FALSE)
            {
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "THROTTLE_PV"));
            }

            if (memcmp(MEDCCOLCHR.CHAR_ID, "THROTTLE_OUT", strlen("THROTTLE_OUT")) == MP_FALSE)
            {
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "THROTTLE_OUT"));
            }
        }
   
        //if (EDC_COLLECT_RES_DATA(s_msg_code, Core_Collect_Res_Data_In, out_node) == MP_FALSE)
        //    return MP_FALSE;

        //설비 이벤트를 보내 edc가 자동으로 쌓이도록 한다.
        if (RAS_RESOURCE_EVENT(s_msg_code, event_node, out_node) == MP_FALSE)
            return MP_FALSE;

        //설비데이터를 코어에 저장 후 설비 hist seq가 오르므로 설비를 재조회 한다. 
        DBU_init_mrasresdef(&MRASRESDEF);
        TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
        DBU_select_mrasresdef(1, &MRASRESDEF);

        DBU_init_crashitfnc(&CRASHITFNC);
        memcpy(CRASHITFNC.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASHITFNC.RES_ID));
        CRASHITFNC.HIST_SEQ = MRASRESDEF.LAST_ACTIVE_HIST_SEQ;
        memcpy(CRASHITFNC.WORK_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
        memcpy(CRASHITFNC.FACTORY, MRASRESDEF.FACTORY, sizeof(CRASHITFNC.FACTORY));
        memcpy(CRASHITFNC.WORK_DATE, work_date.s_work_date, sizeof(work_date.s_work_date));
        memcpy(CRASHITFNC.DAY_NIGHT, work_date.s_day_night, sizeof(work_date.s_day_night));

        if (COM_isnullspace(TRS.get_string(in_node, "TEMP_SV")) == MP_FALSE)
            CRASHITFNC.SV_TEMP = atof(TRS.get_string(in_node, "TEMP_SV"));

        if (COM_isnullspace(TRS.get_string(in_node, "TEMP_PV")) == MP_FALSE)
            CRASHITFNC.PV_TEMP = atof(TRS.get_string(in_node, "TEMP_PV"));

        if (COM_isnullspace(TRS.get_string(in_node, "TIME_RM")) == MP_FALSE)
            TRS.copy(CRASHITFNC.TIME_RM, sizeof(CRASHITFNC.TIME_RM), in_node, "TIME_RM");

        if (COM_isnullspace(TRS.get_string(in_node, "VACCUM_PV1")) == MP_FALSE)
            CRASHITFNC.VACCUM_PV1 = atof(TRS.get_string(in_node, "VACCUM_PV1"));

        if (COM_isnullspace(TRS.get_string(in_node, "VACCUM_PV2")) == MP_FALSE)
            CRASHITFNC.VACCUM_PV2 = atof(TRS.get_string(in_node, "VACCUM_PV2"));

        if (COM_isnullspace(TRS.get_string(in_node, "THROTTLE_SV")) == MP_FALSE)
            CRASHITFNC.THROTTLE_SV = atof(TRS.get_string(in_node, "THROTTLE_SV"));

        if (COM_isnullspace(TRS.get_string(in_node, "THROTTLE_PV")) == MP_FALSE)
            CRASHITFNC.THROTTLE_PV = atof(TRS.get_string(in_node, "THROTTLE_PV"));

        if (COM_isnullspace(TRS.get_string(in_node, "THROTTLE_OUT")) == MP_FALSE)
            CRASHITFNC.THROTTLE_OUT = atof(TRS.get_string(in_node, "THROTTLE_OUT"));

        if (TRS.get_ushort(in_node, "VACCUM_BIT_1") != 0)
        {
            COM_itoa_left(CRASHITFNC.CMF_1, TRS.get_ushort(in_node, "VACCUM_BIT_1"), sizeof(CRASHITFNC.CMF_1));
            CRASHITFNC.VACCUM_PV1 = dVaccum;
        }
        if (TRS.get_ushort(in_node, "VACCUM_BIT_2") != 0)
            COM_itoa_left(CRASHITFNC.CMF_2, TRS.get_ushort(in_node, "VACCUM_BIT_2"), sizeof(CRASHITFNC.CMF_2));

        CRASHITFNC.RES_STATUS = TRS.get_char(in_node, "EQ_STS");
        
        //EQ_STS : 0 : 종료 , 1: 시작, 2: 작업중
        if (CRASHITFNC.RES_STATUS == '1')
            memcpy(CRASHITFNC.START_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
        else if (CRASHITFNC.RES_STATUS == '2' || CRASHITFNC.RES_STATUS == '0')
        { 
            DBU_init_crashitfnc(&CRASHITFNC_START);
            memcpy(CRASHITFNC_START.RES_ID, MRASRESDEF.RES_ID, sizeof(CRASHITFNC_START.RES_ID));
            DBU_select_crashitfnc(2, &CRASHITFNC_START);

            if (DB_error_code == DB_SUCCESS)
            {
                memcpy(CRASHITFNC.START_TIME, CRASHITFNC_START.START_TIME, sizeof(CRASHITFNC.START_TIME));
            }

            if (CRASHITFNC.RES_STATUS == '0')
                memcpy(CRASHITFNC.END_TIME, work_date.s_sys_time, sizeof(work_date.s_sys_time));
        }

        memcpy(CRASHITFNC.EVENT_ID, MRASRESEVN.EVENT_ID, sizeof(MRASRESEVN.EVENT_ID));

        TRS.copy(CRASHITFNC.CREATE_USER_ID, sizeof(CRASHITFNC.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CRASHITFNC.CREATE_TIME, gs_sys_time, sizeof(CRASHITFNC.CREATE_TIME));

        DBU_insert_crashitfnc(&CRASHITFNC);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CRASHITFNC Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRASHITFNC.RES_ID), CRASHITFNC.RES_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }
    //else if (TRS.get_procstep(in_node) == '2')
    //{
    //   
    //}

    return MP_TRUE;
}

/*******************************************************************************
Validation_CUS_EIS_COLLECT_FURNACE_DATA()
- Main sub function of "CUS_EIS_COLLECT_FURNACE_DATA" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- struct MRASRESDEF_TAG *MRASRESDEF : 설비
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_FURNACE_DATA(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node)
{
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "12") == MP_FALSE)
        return MP_FALSE;

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
