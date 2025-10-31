/******************************************************************************'

    System      : MESplus
    Module      : CUS_BAT
    File Name   : CUS_BAT_setup_calendar_list.c.c
    Description : Create Calendar by batch Server

    MES Version : 5.3.7

    Function List
        - CUS_BAT_Setup_Calendar_List()
            + Create Calendar by batch Server

    History
    Seq   Date        DevelOPER      Description
    ---------------------------------------------------------------------------
    1     2020/10/06  hn.lee       Create by Generator

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_common.h"
#include "BASCore_common.h"

int CUS_BAT_SETUP_CALENDAR_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node); 

/*******************************************************************************
    CUS_BAT_Setup_Calendar_List()
        - Tran Aging Lot definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Setup_Calendar_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAT_SETUP_CALENDAR_LIST(s_msg_code, in_node, out_node);
    
    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    COM_out_msg_log_write(s_msg_code,"CUS_BAT_Setup_Calendar_List", out_node);

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
    CUS_BAT_SETUP_CALENDAR_LIST()
        - Main sub function of "CUS_BAT_Setup_Calendar_List" function 
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE) 
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure 
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_SETUP_CALENDAR_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
    TRSNode *calendar_in;
    int WORK_HOUR = 24;

    char s_cal_time[15];

    LOG_head("CUS_BAT_SETUP_CALENDAR_LIST");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

    memset(s_cal_time, 0x00, sizeof(s_cal_time));

    COM_calc_time(s_cal_time, gs_sys_time, MP_MODE_DAY, 365);

    calendar_in = TRS.add_node(in_node, "Calendar_In");

    TRS.set_char(calendar_in, IN_LANGUAGE, '1');  // ¿ù¿äÀÏ
    TRS.set_nstring(calendar_in, IN_FACTORY, "IJDK1");
    TRS.set_nstring(calendar_in, IN_USERID, TRS.get_userid(in_node));
    TRS.set_nstring(calendar_in, IN_PASSWORD, TRS.get_password(in_node));
    TRS.set_nstring(calendar_in, IN_PASSPORT, TRS.get_passport(in_node));

    TRS.add_char(calendar_in, IN_PROCSTEP, '1');

    TRS.add_char(calendar_in, "CALENDAR_TYPE", 'F');
    TRS.add_nstring(calendar_in, "CALENDAR_ID", "IJDK1");

    TRS.add_int(calendar_in, "YEAR", COM_atoi(s_cal_time, 4));

    TRS.add_int(calendar_in, "FIRST_DAY_OF_WEEK", 1);
    TRS.add_double(calendar_in, "WORK_HOURS_MONDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_TUESDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_WEDNESDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_THURSDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_FRIDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_SATURDAY", WORK_HOUR);
    TRS.add_double(calendar_in, "WORK_HOURS_SUNDAY", WORK_HOUR);
    TRS.add_char(calendar_in, "IS_HOLIDAY_MONDAY", 'N');
    TRS.add_char(calendar_in, "IS_HOLIDAY_TUESDAY", 'N');
    TRS.add_char(calendar_in, "IS_HOLIDAY_WEDNESDAY", 'N');
    TRS.add_char(calendar_in, "IS_HOLIDAY_THURSDAY", 'N');
    TRS.add_char(calendar_in, "IS_HOLIDAY_FRIDAY", 'N');
    TRS.add_char(calendar_in, "IS_HOLIDAY_SATURDAY", 'Y');
    TRS.add_char(calendar_in, "IS_HOLIDAY_SUNDAY", 'Y');

    if(BAS_UPDATE_CALENDAR_LIST(s_msg_code, calendar_in, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
