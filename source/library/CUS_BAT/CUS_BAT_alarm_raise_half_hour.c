/******************************************************************************'

    System      : MESplus
    Module      : CUS_BAT
    File Name   : CUS_BAT_alarm_raise_half_hour.c.c
    Description : alarm raise

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



int CUS_BAT_ALARM_RAISE_HALF_HOUR(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_BAT_Setup_Calendar_List()
        - Tran Aging Lot definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_alarm_raise_half_hour(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAT_ALARM_RAISE_HALF_HOUR(s_msg_code, in_node, out_node);
    
    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    COM_out_msg_log_write(s_msg_code,"CUS_BAT_alarm_raise_half_hour", out_node);

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
    CUS_BAT_ALARM_RAISE_HALF_HOUR()
        - Main sub function of "CUS_BAT_Setup_Calendar_List" function 
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE) 
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure 
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ALARM_RAISE_HALF_HOUR(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
	struct IF_MOVE_TRX_TAG IF_MOVE_TRX;

    //TRSNode *calendar_in;
	TRSNode *raise_alarm;


	struct CPAKLOTSTS_TAG CPAKLOTSTS;


    //char s_cal_time[15];

	int i_error_cnt = 0;

    LOG_head("CUS_BAT_ALARM_RAISE_HALF_HOUR");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);




	DBU_init_cpaklotsts(&CPAKLOTSTS);
	TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);

	DBU_open_cpaklotsts(13, &CPAKLOTSTS);

	if (DB_error_code != DB_SUCCESS)
	{

		DBU_close_cpaklotsts(13);

		return MP_FALSE;
	}


	while (1)
	{

		DBU_fetch_cpaklotsts(13, &CPAKLOTSTS);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_cpaklotsts(13);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			DBU_close_cpaklotsts(13);

			return MP_FALSE;
		}


		raise_alarm = TRS.create_node("RAISE_ALARM");

		TRS.set_char(raise_alarm, IN_LANGUAGE, '1');
		TRS.set_nstring(raise_alarm, IN_FACTORY, "IJDK1");
		//TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
		//TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
		//TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));

        TRS.set_nstring(raise_alarm, IN_USERID, "ADMIN");
        TRS.set_nstring(raise_alarm, IN_PASSWORD, "MANAGER");
        TRS.set_nstring(raise_alarm, IN_PASSPORT, "");





		TRS.add_char(raise_alarm, IN_PROCSTEP, '1');
/*
        TRS.add_string(raise_alarm, "ALARM_ID", "HM_SHIP_REPORT", strlen("HM_SHIP_REPORT"));
        TRS.add_string(raise_alarm, "LOT_ID", CPAKLOTSTS.PACK_LOT_ID, strlen(CPAKLOTSTS.PACK_LOT_ID));
        TRS.add_string(raise_alarm, "ALARM_SUBJECT", CPAKLOTSTS.CMF_2, strlen(CPAKLOTSTS.CMF_2));
        TRS.add_nstring(raise_alarm, "SOURCE_DESC_1", "HM SHIP REPORT REQUEST");
        TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "HM SHIP REPORT REQUEST2");
*/

		TRS.add_string(raise_alarm, "ALARM_ID", "SHIP_REPORT_REQUST", strlen("SHIP_REPORT_REQUST"));
		TRS.add_string(raise_alarm, "LOT_ID", CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID));
		TRS.add_string(raise_alarm, "ALARM_SUBJECT", CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
     //   TRS.add_string(raise_alarm, "ALARM_MSG", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
	//	TRS.add_string(raise_alarm, "SOURCE_DESC_1", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
		TRS.add_string(raise_alarm, "SOURCE_ID_1", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
     //   TRS.add_string(raise_alarm, "SOURCE_DESC_2", CPAKLOTSTS.CMF_3, sizeof(CPAKLOTSTS.CMF_3));
    //   TRS.add_string(raise_alarm, "SOURCE_ID_2", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
     //   TRS.add_string(raise_alarm, "SOURCE_DESC_3", CPAKLOTSTS.CMF_4, sizeof(CPAKLOTSTS.CMF_4));
    //    TRS.add_string(raise_alarm, "SOURCE_ID_3", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
     //  TRS.add_string(raise_alarm, "ALARM_COMMENT_1", CPAKLOTSTS.CMF_1, sizeof(CPAKLOTSTS.CMF_1));
      //  TRS.add_string(raise_alarm, "ALARM_COMMENT_2", CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2));
      // TRS.add_string(raise_alarm, "ALARM_COMMENT_3", CPAKLOTSTS.CMF_3, sizeof(CPAKLOTSTS.CMF_3));
      //  TRS.add_string(raise_alarm, "ALARM_COMMENT_4", CPAKLOTSTS.CMF_4, sizeof(CPAKLOTSTS.CMF_4));

		if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}

		

		TRS.free_node(raise_alarm);

	}

	DBU_close_cpaklotsts(13);
	





	

    return MP_TRUE;
}
