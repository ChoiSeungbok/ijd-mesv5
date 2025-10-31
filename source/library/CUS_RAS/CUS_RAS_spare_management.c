/******************************************************************************'

System      : MESplus
Module      : CUS_BAS
File Name   : COMCus_update_caption.c
Description : Caption Setup function module

MES Version : 5.3.4

Function List
- CUS_RAS_Spare_Management()
+ Create/Update/Delete Caption definition
- CUS_RAS_SPARE_MANAGEMENT()
+ Main sub function of CUS_RAS_Spare_Management function
+ Create/Update/Delete Caption definition
- CUS_RAS_Spare_Management_Validation()
+ Main sub function of CUS_RAS_SPARE_MANAGEMENT function
+ Check the condition for create/update/delete Caption
Detail Description
- CUS_RAS_SPARE_MANAGEMENT()
+ h_proc_step
+ MP_STEP_CREATE : Create Caption definition
+ MP_STEP_UPDATE : Update Caption definition
+ MP_STEP_DELETE : Delete Caption definition

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2016/01/01                 Create by Generator

Copyright(C) 1998-2016 Miracom,Inc.
All rights reserved.

******************************************************************************/

#if defined(_HPUX_SOURCE)

#include <dirent.h>

#elif defined(__digital__) || defined(_AIX)

#include <dirent.h>

#elif defined(WIN32) || defined(WIN64)

#include <direct.h>

#endif

#include "CUS_common.h"
#include "CUS_defines.h"
#include "CUS_RAS_common.h"

int CUS_RAS_SPARE_MANAGEMENT(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

int CUS_RAS_Spare_Management_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

/*******************************************************************************
COMCus_Update_Caption()
- Create/Update/Delete Caption definition
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Spare_Management(TRSNode *in_node,
	TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;


	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_RAS_SPARE_MANAGEMENT(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_RAS_SPARE_MANAGEMENT", out_node);

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
CUS_RAS_SPARE_MANAGEMENT()
- Main sub function of "CUS_RAS_Spare_Management" function
- Create/Update/Delete Caption definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_SPARE_MANAGEMENT(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	//struct CRASSPRSTS_TAG CRASSPRSTS;

	struct CRASSPRSTS_TAG CRASSPRSTS;



	TRSNode			*gen_in_node;
	TRSNode			*create_in;
	TRSNode			*cmn_out;



	//int i;
	//unsigned char  *in_data;
	//long            blob_size;
	//FILE           *blob_file;
	//char            s_cur_time[20];
	//char            s_file[200];
	//char            s_file_path[1000];
	//char            s_temp_dir[256];
	char			s_spare_id[20];

	//char            s_file_name[20];

	LOG_head("CUS_RAS_Spare_Management");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	/*  일단 체크안함
	if (CUS_RAS_Spare_Management_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
	COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	return MP_FALSE;
	}
	*/


	memset(s_spare_id, ' ', sizeof(s_spare_id));

	gen_in_node = TRS.add_node(in_node, "gen_in_node");



	TRS.copy(CRASSPRSTS.FACTORY, sizeof(CRASSPRSTS.FACTORY), in_node, "FACTORY");

	if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{

		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", "SPARE_ID", strlen("SPARE_ID"));
		TRS.add_char(gen_in_node, "PROCSTEP", '2');


		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(s_spare_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);
		create_in = TRS.add_node(in_node, "create_in");
		TRS.add_char(create_in, IN_PROCSTEP, '1');
		TRS.add_string(create_in, "SPARE_ID", s_spare_id, sizeof(s_spare_id));
		CopyDefaultMembers(create_in, in_node);
		TRS.copy(CRASSPRSTS.SPARE_ID, sizeof(CRASSPRSTS.SPARE_ID), create_in, "SPARE_ID");
	}
	else
	{
		TRS.copy(CRASSPRSTS.SPARE_ID, sizeof(CRASSPRSTS.SPARE_ID), in_node, "SPARE_ID");
	}
	DBU_select_crassprsts(1, &CRASSPRSTS);

	TRS.copy(CRASSPRSTS.LOCATION_1, sizeof(CRASSPRSTS.LOCATION_1), in_node, "LOCATION_1");
	TRS.copy(CRASSPRSTS.LOCATION_2, sizeof(CRASSPRSTS.LOCATION_2), in_node, "LOCATION_2");
	TRS.copy(CRASSPRSTS.LOCATION_3, sizeof(CRASSPRSTS.LOCATION_3), in_node, "LOCATION_3");
	TRS.copy(CRASSPRSTS.SPARE_TYPE, sizeof(CRASSPRSTS.SPARE_TYPE), in_node, "SPARE_TYPE");
	TRS.copy(CRASSPRSTS.SPARE_MAT_ID, sizeof(CRASSPRSTS.SPARE_MAT_ID), in_node, "SPARE_MAT_ID");
	TRS.copy(CRASSPRSTS.SPARE_SPEC_ID, sizeof(CRASSPRSTS.SPARE_SPEC_ID), in_node, "SPARE_SPEC_ID");
	TRS.copy(CRASSPRSTS.MANUFACTURER_ID, sizeof(CRASSPRSTS.MANUFACTURER_ID), in_node, "MANUFACTURER_ID");
	TRS.copy(CRASSPRSTS.RES_ID, sizeof(CRASSPRSTS.RES_ID), in_node, "RES_ID");
	//TRS.copy(CRASSPRSTS.STOCK_QTY, sizeof(CRASSPRSTS.STOCK_QTY), in_node, "STOCK_QTY");
	CRASSPRSTS.STOCK_QTY = TRS.get_int(in_node, "STOCK_QTY");
	TRS.copy(CRASSPRSTS.CMF_1, sizeof(CRASSPRSTS.CMF_1), in_node, "CMF_1");
	TRS.copy(CRASSPRSTS.CMF_2, sizeof(CRASSPRSTS.CMF_2), in_node, "CMF_2");
	TRS.copy(CRASSPRSTS.CMF_3, sizeof(CRASSPRSTS.CMF_3), in_node, "CMF_3");
	TRS.copy(CRASSPRSTS.CMF_4, sizeof(CRASSPRSTS.CMF_4), in_node, "CMF_4");
	TRS.copy(CRASSPRSTS.CMF_5, sizeof(CRASSPRSTS.CMF_5), in_node, "CMF_5");
	TRS.copy(CRASSPRSTS.CMF_6, sizeof(CRASSPRSTS.CMF_6), in_node, "CMF_6");
	TRS.copy(CRASSPRSTS.CMF_7, sizeof(CRASSPRSTS.CMF_7), in_node, "CMF_7");
	TRS.copy(CRASSPRSTS.CMF_8, sizeof(CRASSPRSTS.CMF_8), in_node, "CMF_8");
	TRS.copy(CRASSPRSTS.CMF_9, sizeof(CRASSPRSTS.CMF_9), in_node, "CMF_9");
	TRS.copy(CRASSPRSTS.CMF_10, sizeof(CRASSPRSTS.CMF_10), in_node, "CMF_10");
	TRS.copy(CRASSPRSTS.CREATE_USER_ID, sizeof(CRASSPRSTS.CREATE_USER_ID), in_node, "CREATE_USER_ID");
	TRS.copy(CRASSPRSTS.CREATE_TIME, sizeof(CRASSPRSTS.CREATE_TIME), in_node, "CREATE_TIME");
	TRS.copy(CRASSPRSTS.UPDATE_USER_ID, sizeof(CRASSPRSTS.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
	TRS.copy(CRASSPRSTS.UPDATE_TIME, sizeof(CRASSPRSTS.UPDATE_TIME), in_node, "UPDATE_TIME");

	if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{
		TRS.copy(CRASSPRSTS.CREATE_USER_ID, sizeof(CRASSPRSTS.CREATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(CRASSPRSTS.CREATE_TIME);

		DBU_insert_crassprsts(&CRASSPRSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CRASSPRSTS INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASSPRSTS.FACTORY), CRASSPRSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
			TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
			TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
			TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);
			TRS.add_fieldmsg(out_node, "SPARE_TYPE", MP_STR, sizeof(CRASSPRSTS.SPARE_TYPE), CRASSPRSTS.SPARE_TYPE);
			TRS.add_fieldmsg(out_node, "SPARE_MAT_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_MAT_ID), CRASSPRSTS.SPARE_MAT_ID);
			TRS.add_fieldmsg(out_node, "SPARE_SPEC_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_SPEC_ID), CRASSPRSTS.SPARE_SPEC_ID);
			TRS.add_fieldmsg(out_node, "MANUFACTURER_ID", MP_STR, sizeof(CRASSPRSTS.MANUFACTURER_ID), CRASSPRSTS.MANUFACTURER_ID);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.RES_ID);
			TRS.add_fieldmsg(out_node, "STOCK_QTY", MP_DBL, sizeof(CRASSPRSTS.STOCK_QTY), CRASSPRSTS.STOCK_QTY);
			TRS.add_fieldmsg(out_node, "CMF_1", MP_STR, sizeof(CRASSPRSTS.CMF_1), CRASSPRSTS.CMF_1);
			TRS.add_fieldmsg(out_node, "CMF_2", MP_STR, sizeof(CRASSPRSTS.CMF_2), CRASSPRSTS.CMF_2);
			TRS.add_fieldmsg(out_node, "CMF_3", MP_STR, sizeof(CRASSPRSTS.CMF_3), CRASSPRSTS.CMF_3);
			TRS.add_fieldmsg(out_node, "CMF_4", MP_STR, sizeof(CRASSPRSTS.CMF_4), CRASSPRSTS.CMF_4);
			TRS.add_fieldmsg(out_node, "CMF_5", MP_STR, sizeof(CRASSPRSTS.CMF_5), CRASSPRSTS.CMF_5);
			TRS.add_fieldmsg(out_node, "CMF_6", MP_STR, sizeof(CRASSPRSTS.CMF_6), CRASSPRSTS.CMF_6);
			TRS.add_fieldmsg(out_node, "CMF_7", MP_STR, sizeof(CRASSPRSTS.CMF_7), CRASSPRSTS.CMF_7);
			TRS.add_fieldmsg(out_node, "CMF_8", MP_STR, sizeof(CRASSPRSTS.CMF_8), CRASSPRSTS.CMF_8);
			TRS.add_fieldmsg(out_node, "CMF_9", MP_STR, sizeof(CRASSPRSTS.CMF_9), CRASSPRSTS.CMF_9);
			TRS.add_fieldmsg(out_node, "CMF_10", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.CMF_10);
			TRS.add_fieldmsg(out_node, "CREATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.CREATE_USER_ID), CRASSPRSTS.CREATE_USER_ID);
			TRS.add_fieldmsg(out_node, "CREATE_TIME", MP_STR, sizeof(CRASSPRSTS.CREATE_TIME), CRASSPRSTS.CREATE_TIME);
			TRS.add_fieldmsg(out_node, "UPDATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.UPDATE_USER_ID), CRASSPRSTS.UPDATE_USER_ID);
			TRS.add_fieldmsg(out_node, "UPDATE_TIME", MP_STR, sizeof(CRASSPRSTS.UPDATE_TIME), CRASSPRSTS.UPDATE_TIME);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		TRS.add_nstring(out_node, "SPARE_ID", CRASSPRSTS.SPARE_ID);
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_UPDATE)
	{
		TRS.copy(CRASSPRSTS.UPDATE_USER_ID, sizeof(CRASSPRSTS.UPDATE_USER_ID), in_node, IN_USERID);
		DB_get_systime(CRASSPRSTS.UPDATE_TIME);

		DBU_update_crassprsts(1, &CRASSPRSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CRASSPRSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASSPRSTS.FACTORY), CRASSPRSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
			TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
			TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
			TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);
			TRS.add_fieldmsg(out_node, "SPARE_TYPE", MP_STR, sizeof(CRASSPRSTS.SPARE_TYPE), CRASSPRSTS.SPARE_TYPE);
			TRS.add_fieldmsg(out_node, "SPARE_MAT_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_MAT_ID), CRASSPRSTS.SPARE_MAT_ID);
			TRS.add_fieldmsg(out_node, "SPARE_SPEC_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_SPEC_ID), CRASSPRSTS.SPARE_SPEC_ID);
			TRS.add_fieldmsg(out_node, "MANUFACTURER_ID", MP_STR, sizeof(CRASSPRSTS.MANUFACTURER_ID), CRASSPRSTS.MANUFACTURER_ID);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.RES_ID);
			TRS.add_fieldmsg(out_node, "STOCK_QTY", MP_DBL, sizeof(CRASSPRSTS.STOCK_QTY), CRASSPRSTS.STOCK_QTY);
			TRS.add_fieldmsg(out_node, "CMF_1", MP_STR, sizeof(CRASSPRSTS.CMF_1), CRASSPRSTS.CMF_1);
			TRS.add_fieldmsg(out_node, "CMF_2", MP_STR, sizeof(CRASSPRSTS.CMF_2), CRASSPRSTS.CMF_2);
			TRS.add_fieldmsg(out_node, "CMF_3", MP_STR, sizeof(CRASSPRSTS.CMF_3), CRASSPRSTS.CMF_3);
			TRS.add_fieldmsg(out_node, "CMF_4", MP_STR, sizeof(CRASSPRSTS.CMF_4), CRASSPRSTS.CMF_4);
			TRS.add_fieldmsg(out_node, "CMF_5", MP_STR, sizeof(CRASSPRSTS.CMF_5), CRASSPRSTS.CMF_5);
			TRS.add_fieldmsg(out_node, "CMF_6", MP_STR, sizeof(CRASSPRSTS.CMF_6), CRASSPRSTS.CMF_6);
			TRS.add_fieldmsg(out_node, "CMF_7", MP_STR, sizeof(CRASSPRSTS.CMF_7), CRASSPRSTS.CMF_7);
			TRS.add_fieldmsg(out_node, "CMF_8", MP_STR, sizeof(CRASSPRSTS.CMF_8), CRASSPRSTS.CMF_8);
			TRS.add_fieldmsg(out_node, "CMF_9", MP_STR, sizeof(CRASSPRSTS.CMF_9), CRASSPRSTS.CMF_9);
			TRS.add_fieldmsg(out_node, "CMF_10", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.CMF_10);
			TRS.add_fieldmsg(out_node, "CREATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.CREATE_USER_ID), CRASSPRSTS.CREATE_USER_ID);
			TRS.add_fieldmsg(out_node, "CREATE_TIME", MP_STR, sizeof(CRASSPRSTS.CREATE_TIME), CRASSPRSTS.CREATE_TIME);
			TRS.add_fieldmsg(out_node, "UPDATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.UPDATE_USER_ID), CRASSPRSTS.UPDATE_USER_ID);
			TRS.add_fieldmsg(out_node, "UPDATE_TIME", MP_STR, sizeof(CRASSPRSTS.UPDATE_TIME), CRASSPRSTS.UPDATE_TIME);
			TRS.add_dberrmsg(out_node, DB_error_msg);



			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		TRS.add_nstring(out_node, "SPARE_ID", CRASSPRSTS.SPARE_ID);
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_DELETE)
	{
		DBU_delete_crassprsts(1, &CRASSPRSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CRASSPRSTS DELETE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CRASSPRSTS.FACTORY), CRASSPRSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
			TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
			TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
			TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);
			TRS.add_fieldmsg(out_node, "SPARE_TYPE", MP_STR, sizeof(CRASSPRSTS.SPARE_TYPE), CRASSPRSTS.SPARE_TYPE);
			TRS.add_fieldmsg(out_node, "SPARE_MAT_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_MAT_ID), CRASSPRSTS.SPARE_MAT_ID);
			TRS.add_fieldmsg(out_node, "SPARE_SPEC_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_SPEC_ID), CRASSPRSTS.SPARE_SPEC_ID);
			TRS.add_fieldmsg(out_node, "MANUFACTURER_ID", MP_STR, sizeof(CRASSPRSTS.MANUFACTURER_ID), CRASSPRSTS.MANUFACTURER_ID);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.RES_ID);
			TRS.add_fieldmsg(out_node, "STOCK_QTY", MP_DBL, sizeof(CRASSPRSTS.STOCK_QTY), CRASSPRSTS.STOCK_QTY);
			TRS.add_fieldmsg(out_node, "CMF_1", MP_STR, sizeof(CRASSPRSTS.CMF_1), CRASSPRSTS.CMF_1);
			TRS.add_fieldmsg(out_node, "CMF_2", MP_STR, sizeof(CRASSPRSTS.CMF_2), CRASSPRSTS.CMF_2);
			TRS.add_fieldmsg(out_node, "CMF_3", MP_STR, sizeof(CRASSPRSTS.CMF_3), CRASSPRSTS.CMF_3);
			TRS.add_fieldmsg(out_node, "CMF_4", MP_STR, sizeof(CRASSPRSTS.CMF_4), CRASSPRSTS.CMF_4);
			TRS.add_fieldmsg(out_node, "CMF_5", MP_STR, sizeof(CRASSPRSTS.CMF_5), CRASSPRSTS.CMF_5);
			TRS.add_fieldmsg(out_node, "CMF_6", MP_STR, sizeof(CRASSPRSTS.CMF_6), CRASSPRSTS.CMF_6);
			TRS.add_fieldmsg(out_node, "CMF_7", MP_STR, sizeof(CRASSPRSTS.CMF_7), CRASSPRSTS.CMF_7);
			TRS.add_fieldmsg(out_node, "CMF_8", MP_STR, sizeof(CRASSPRSTS.CMF_8), CRASSPRSTS.CMF_8);
			TRS.add_fieldmsg(out_node, "CMF_9", MP_STR, sizeof(CRASSPRSTS.CMF_9), CRASSPRSTS.CMF_9);
			TRS.add_fieldmsg(out_node, "CMF_10", MP_STR, sizeof(CRASSPRSTS.RES_ID), CRASSPRSTS.CMF_10);
			TRS.add_fieldmsg(out_node, "CREATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.CREATE_USER_ID), CRASSPRSTS.CREATE_USER_ID);
			TRS.add_fieldmsg(out_node, "CREATE_TIME", MP_STR, sizeof(CRASSPRSTS.CREATE_TIME), CRASSPRSTS.CREATE_TIME);
			TRS.add_fieldmsg(out_node, "UPDATE_USER_ID", MP_STR, sizeof(CRASSPRSTS.UPDATE_USER_ID), CRASSPRSTS.UPDATE_USER_ID);
			TRS.add_fieldmsg(out_node, "UPDATE_TIME", MP_STR, sizeof(CRASSPRSTS.UPDATE_TIME), CRASSPRSTS.UPDATE_TIME);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}


	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Spare_Management_Validation()
- Main sub function of "CUS_RAS_SPARE_MANAGEMENT" function
- Check the condition for create/update/delete Caption & vbCrLf    Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Spare_Management_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	struct CRASSPRSTS_TAG CRASSPRSTS;


	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"IUDFL") == MP_FALSE)
	{
		return MP_FALSE;
	}


	/* Caption_type Validation */
	if (COM_isnullspace(TRS.get_string(in_node, "SPARE_ID")) == MP_TRUE)
	{
		strcpy(s_msg_code, "CMN-0001");
		TRS.add_fieldmsg(out_node, "SPARE_ID", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_SETUP;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	DBU_init_crassprsts(&CRASSPRSTS);
	TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
	TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
	TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
	TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);
	DBU_select_crassprsts(1, &CRASSPRSTS);
	if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{
		if (DB_error_code == DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0006"); //SPARE 정보가 이미 존재합니다.
			TRS.add_fieldmsg(out_node, "CRASSPRSTS SELECT", MP_NVST);
			//TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
			//TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
			//TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
			//TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_SETUP;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		else
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CRASSPRSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
				TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
				TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
				TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_UPDATE ||
		TRS.get_procstep(in_node) == MP_STEP_DELETE)
	{
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "CMN-0005"); //캡션이 존재하지 않습니다.
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
			}

			TRS.add_fieldmsg(out_node, "CRASSPRSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "SPARE_ID", MP_STR, sizeof(CRASSPRSTS.SPARE_ID), CRASSPRSTS.SPARE_ID);
			TRS.add_fieldmsg(out_node, "LOCATION_1", MP_STR, sizeof(CRASSPRSTS.LOCATION_1), CRASSPRSTS.LOCATION_1);
			TRS.add_fieldmsg(out_node, "LOCATION_2", MP_STR, sizeof(CRASSPRSTS.LOCATION_2), CRASSPRSTS.LOCATION_2);
			TRS.add_fieldmsg(out_node, "LOCATION_3", MP_STR, sizeof(CRASSPRSTS.LOCATION_3), CRASSPRSTS.LOCATION_3);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_SETUP;
			return MP_FALSE;
		}
	}
	return MP_TRUE;
}


