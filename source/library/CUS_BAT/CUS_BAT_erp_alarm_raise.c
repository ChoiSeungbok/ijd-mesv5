/******************************************************************************'

	System      : MESplus
	Module      : CUS_BAT
	File Name   : CUS_BAT_erp_alarm_raise.c.c
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


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")




int CUS_BAT_ERP_ALARM_RAISE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
	CUS_BAT_Setup_Calendar_List()
		- Tran Aging Lot definition
	Return Value
		- int : 0 (MP_TRUE)
	Arguments
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Alarm_Raise(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_ALARM_RAISE(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Alarm_Raise", out_node);

	if (i_ret == MP_TRUE)
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
	CUS_BAT_ERP_ALARM_RAISE()
		- Main sub function of "CUS_BAT_Setup_Calendar_List" function
	Return Value
		- int : 1 (MP_TRUE) or 0 (MP_FALSE)
	Arguments
		- char *s_msg_code : Error Message Code
		- TRSNode *in_node : Input Message structure
		- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_ALARM_RAISE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct IF_MOVE_TRX_TAG IF_MOVE_TRX;

	//TRSNode *calendar_in;
	TRSNode* raise_alarm;


	struct CPAKLOTSTS_TAG CPAKLOTSTS;


	//char s_cal_time[15];

	int i_error_cnt = 0;

	LOG_head("CUS_BAT_ERP_ALARM_RAISE");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);




	/*

	DBU_init_if_move_trx(&IF_MOVE_TRX);

	DBU_open_if_move_trx(2, &IF_MOVE_TRX);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "IF_MOVE_TRX OPEN", MP_NVST);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		return MP_FALSE;
	}
	while (1)
	{
		DBU_fetch_if_move_trx(2, &IF_MOVE_TRX);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_move_trx(2);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_MOVE_TRX FETCH", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			DBU_close_if_move_trx(2);

			return MP_FALSE;
		}

		i_error_cnt = i_error_cnt + 1;

	}



	if (i_error_cnt > 0)
	{
		raise_alarm = TRS.create_node("RAISE_ALARM");

		TRS.set_char(raise_alarm, IN_LANGUAGE, '1');
		TRS.set_nstring(raise_alarm, IN_FACTORY, "IJDK1");
		TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));
		TRS.add_char(raise_alarm, IN_PROCSTEP, '1');

		TRS.add_string(raise_alarm, "ALARM_ID", "ERP_ERROR_RAISE", strlen("ERP_ERROR_RAISE"));
		TRS.add_string(raise_alarm, "ALARM_SUBJECT", "MOVE_TRANSACTION_ERROR", strlen("MOVE_TRANSACTION_ERROR"));
		TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "ERP");


		if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}

		TRS.free_node(raise_alarm);

	}

	*/

	//MC 서버 꺼져있으면 알람발생.


//	const char* cmd = "ping -n 1 -w 5000 " MP_SERVER_IP_MC " > nul";


	/*
	char cmd[128];
	snprintf(cmd, sizeof(cmd),
		"ping -n 1 -w 5000 %s > nul", MP_SERVER_IP_MC);

	int status = system(cmd);

	if (status != 0) {

	}
	else {
		raise_alarm = TRS.create_node("RAISE_ALARM");

		TRS.set_char(raise_alarm, IN_LANGUAGE, '1');
		TRS.set_nstring(raise_alarm, IN_FACTORY, "IJDK1");
		TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));
		TRS.add_char(raise_alarm, IN_PROCSTEP, '1');

		TRS.add_string(raise_alarm, "ALARM_ID", "MC_SERVER_OFF", strlen("MC_SERVER_OFF"));
		TRS.add_string(raise_alarm, "ALARM_SUBJECT", MP_SERVER_IP_MC, strlen(MP_SERVER_IP_MC));
		TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "MC");


		if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}


		TRS.free_node(raise_alarm);
	}

	*/

	//MC 서버 하도 꺼져서 알람 되게...이거 하드 교체해야함...ㅠㅠ (25.05.08)_syw

	HANDLE hIcmp = IcmpCreateFile();
	if (hIcmp == INVALID_HANDLE_VALUE) {
		return MP_FALSE;
	}

	IPAddr ip = inet_addr(MP_SERVER_IP_MC);
	char sendData[] = "ping";


	char replyBuf[1024];
	DWORD dwRet = IcmpSendEcho(
		hIcmp,
		ip,
		sendData, sizeof(sendData),
		NULL,                    /* 옵션(헤더 설정) 없음 */
		replyBuf, sizeof(replyBuf),
		5000
	);
	// ping 안가면
	if (dwRet == 0)
	{
		raise_alarm = TRS.create_node("RAISE_ALARM");

		TRS.set_char(raise_alarm, IN_LANGUAGE, '1');
		TRS.set_nstring(raise_alarm, IN_FACTORY, "IJDK1");
		TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));
		TRS.add_char(raise_alarm, IN_PROCSTEP, '1');

		TRS.add_string(raise_alarm, "ALARM_ID", "MC_SERVER_OFF", strlen("MC_SERVER_OFF"));
		TRS.add_string(raise_alarm, "ALARM_SUBJECT", MP_SERVER_IP_MC, strlen(MP_SERVER_IP_MC));
		TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "MC");


		if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
		{
			TRS.free_node(raise_alarm);
			IcmpCloseHandle(hIcmp);
			return MP_FALSE;
		}

		TRS.free_node(raise_alarm);


	}

	IcmpCloseHandle(hIcmp);




	/*

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
		TRS.set_nstring(raise_alarm, IN_USERID, TRS.get_userid(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSWORD, TRS.get_password(in_node));
		TRS.set_nstring(raise_alarm, IN_PASSPORT, TRS.get_passport(in_node));
		TRS.add_char(raise_alarm, IN_PROCSTEP, '1');

		TRS.add_string(raise_alarm, "ALARM_ID", "HM_SHIP_REPORT", strlen("HM_SHIP_REPORT"));
		TRS.add_string(raise_alarm, "LOT_ID", CPAKLOTSTS.PACK_LOT_ID, strlen(CPAKLOTSTS.PACK_LOT_ID));
		TRS.add_string(raise_alarm, "ALARM_SUBJECT", CPAKLOTSTS.CMF_2, strlen(CPAKLOTSTS.CMF_2));
		TRS.add_nstring(raise_alarm, "SOURCE_DESC_1", "HM SHIP REPORT REQUEST");
		TRS.add_nstring(raise_alarm, "SOURCE_ID_1", "HM SHIP REPORT REQUEST2");


		if (ALM_RAISE_ALARM(s_msg_code, raise_alarm, out_node) == MP_FALSE)
		{
			return MP_FALSE;
		}



		TRS.free_node(raise_alarm);

	}

	DBU_close_cpaklotsts(13);



	*/




	return MP_TRUE;
}
