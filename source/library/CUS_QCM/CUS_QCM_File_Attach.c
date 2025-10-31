/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_File_Attach.c
Description : Tran Create Inspection Request function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/01  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"
#include "CUS_common.h"

#define MAXBUFLEN  2048000

int CUS_QCM_File_Attach_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);


/*******************************************************************************
CUS_QCM_File_Attach()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_File_Attach(TRSNode* in_node, TRSNode* out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_FILE_ATTACH(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_File_Attach", out_node);
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
CUS_QCM_FILE_ATTACH()
- Main sub function of "CUS_QCM_File_Attach" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_FILE_ATTACH(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{



	//struct CQCMRPTCTM_TAG CQCMRPTCTM;
	//struct CQCMRPTHMM_TAG CQCMRPTHMM;


	struct CBASFILDEF_TAG CBASFILDEF;


	TRSNode* gen_in_node;
	TRSNode* cmn_out;

	char s_sys_time[14];
	char s_file_no[20];



	unsigned char* blob_file;
	long blob_size;
	int iStart = 0;
	int iSize = 0;



	LOG_head("CUS_QCM_File_Attach");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));
	memset(s_file_no, ' ', sizeof(s_file_no));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	/* Validation Check */
	if (CUS_QCM_File_Attach_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	//ProcStep 1 

	if (TRS.get_procstep(in_node) == '1')
	{

		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", "FILE_NO", strlen("FILE_NO"));
		TRS.add_char(gen_in_node, "PROCSTEP", '2');

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(s_file_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);



		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
		TRS.copy(CBASFILDEF.FILE_TYPE, sizeof(CBASFILDEF.FILE_TYPE), in_node, "FILE_TYPE");
		TRS.copy(CBASFILDEF.FILE_NAME, sizeof(CBASFILDEF.FILE_NAME), in_node, "FILE_NAME");
		TRS.copy(CBASFILDEF.FILE_PATH, sizeof(CBASFILDEF.FILE_PATH), in_node, "FILE_PATH");
		TRS.copy(CBASFILDEF.TO_FILE_PATH, sizeof(CBASFILDEF.TO_FILE_PATH), in_node, "TO_FILE_PATH");
		TRS.copy(CBASFILDEF.AREA_ID, sizeof(CBASFILDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(CBASFILDEF.SUB_AREA_ID, sizeof(CBASFILDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		TRS.copy(CBASFILDEF.OPER, sizeof(CBASFILDEF.OPER), in_node, "OPER");
		TRS.copy(CBASFILDEF.RES_ID, sizeof(CBASFILDEF.RES_ID), in_node, "RES_ID");
		TRS.copy(CBASFILDEF.TOOL_ID, sizeof(CBASFILDEF.TOOL_ID), in_node, "TOOL_ID");
		TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
		TRS.copy(CBASFILDEF.INSP_ID, sizeof(CBASFILDEF.INSP_ID), in_node, "INSP_ID");

		CBASFILDEF.IMAGE_SIZE = TRS.get_int(in_node, "IMAGE_SIZE");

		blob_file = 0x00;
		blob_size = 0;

		TRS.get_blob(in_node, MP_BIN_DATA_1, &blob_file, &blob_size);
		iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

		memcpy(CBASFILDEF.IMAGE_DATA, blob_file, iSize);

		TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_insert_cbasfildef(&CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");;
			TRS.add_fieldmsg(out_node, "CBASFILDEF INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_string(out_node, "FILE_NO", CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO));

		iStart = 0;

		for (blob_size -= MAXBUFLEN, iStart += MAXBUFLEN; blob_size > 0; blob_size -= MAXBUFLEN, iStart += MAXBUFLEN)
		{
			iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

			memcpy(CBASFILDEF.IMAGE_DATA, blob_file + iStart, iSize);
			CBASFILDEF.IMAGE_SIZE = iSize;
			DBU_update_cbasfildef(2, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "BAS-0004");

				TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE 2", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASFILDEF.FACTORY), CBASFILDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
				TRS.add_fieldmsg(out_node, "FILE_PATH", MP_STR, sizeof(CBASFILDEF.FILE_PATH), CBASFILDEF.FILE_PATH);
				TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASFILDEF.FILE_NAME), CBASFILDEF.FILE_NAME);
				TRS.add_fieldmsg(out_node, "IMAGE_SIZE", MP_INT, CBASFILDEF.IMAGE_SIZE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{


		if (COM_isnullspace(TRS.get_string(in_node, "IMAGE_CODE")) == MP_TRUE)
		{
			strcpy(s_msg_code, "QCM-0004");;
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//File No 존재시  검사맵핑 정보 삭제
		if (COM_isnullspace(TRS.get_string(in_node, "FILE_NO")) != MP_TRUE)
		{

			DBU_init_cbasfildef(&CBASFILDEF);
			TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO), in_node, "FILE_NO");
			memset(CBASFILDEF.INSP_ID, ' ', sizeof(CBASFILDEF.INSP_ID));
			DBU_update_cbasfildef(3, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");;
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", "FILE_NO", strlen("FILE_NO"));
		TRS.add_char(gen_in_node, "PROCSTEP", '2');

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(s_file_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);


		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
		TRS.copy(CBASFILDEF.INSP_ID, sizeof(CBASFILDEF.INSP_ID), in_node, "INSP_ID");
		//20231013 PDF 파일도 넣어야 되서..File Type 추가.
		TRS.copy(CBASFILDEF.FILE_TYPE, sizeof(CBASFILDEF.FILE_TYPE), in_node, "FILE_TYPE");
		TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "IMAGE_CODE");

		if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) != MP_TRUE) {
			TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
		}


		CBASFILDEF.IMAGE_SIZE = TRS.get_int(in_node, "IMAGE_SIZE");

		blob_file = 0x00;
		blob_size = 0;

		TRS.get_blob(in_node, MP_BIN_DATA_1, &blob_file, &blob_size);
		iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

		memcpy(CBASFILDEF.IMAGE_DATA, blob_file, iSize);

		TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_insert_cbasfildef(&CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");;
			TRS.add_fieldmsg(out_node, "CBASFILDEF INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_string(out_node, "FILE_NO", CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO));

		iStart = 0;

		for (blob_size -= MAXBUFLEN, iStart += MAXBUFLEN; blob_size > 0; blob_size -= MAXBUFLEN, iStart += MAXBUFLEN)
		{
			iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

			memcpy(CBASFILDEF.IMAGE_DATA, blob_file + iStart, iSize);
			CBASFILDEF.IMAGE_SIZE = iSize;
			DBU_update_cbasfildef(2, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "BAS-0004");

				TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE 2", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASFILDEF.FACTORY), CBASFILDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
				TRS.add_fieldmsg(out_node, "FILE_PATH", MP_STR, sizeof(CBASFILDEF.FILE_PATH), CBASFILDEF.FILE_PATH);
				TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASFILDEF.FILE_NAME), CBASFILDEF.FILE_NAME);
				TRS.add_fieldmsg(out_node, "IMAGE_SIZE", MP_INT, CBASFILDEF.IMAGE_SIZE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

	}
	else if (TRS.get_procstep(in_node) == '3') //파일 doc정보 삭제 ( 공백으로 upate)
	{

		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO), in_node, "FILE_NO");
		if ((int)DBU_select_cbasfildef_scalar(1, &CBASFILDEF) > 0)
		{
			memset(CBASFILDEF.INSP_ID, ' ', sizeof(CBASFILDEF.INSP_ID));
			memset(CBASFILDEF.CMF_1, ' ', sizeof(CBASFILDEF.CMF_1));
			DBU_update_cbasfildef(4, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE", MP_NVST);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}







	}
	else if (TRS.get_procstep(in_node) == '4')
	{


		if (COM_isnullspace(TRS.get_string(in_node, "IMAGE_CODE")) == MP_TRUE)
		{
			strcpy(s_msg_code, "QCM-0004");;
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//File No 존재시 삭제.다시 INSERT
		if (COM_isnullspace(TRS.get_string(in_node, "FILE_NO")) != MP_TRUE)
		{
			DBU_init_cbasfildef(&CBASFILDEF);
			TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO), in_node, "FILE_NO");
			DBU_delete_cbasfildef(1, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");;
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			memcpy(s_file_no, TRS.get_string(in_node, "FILE_NO"), strlen(TRS.get_string(in_node, "FILE_NO")));
			/*
			DBU_update_cbasfildef(3, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");;
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			*/
		}
		else {

			gen_in_node = TRS.add_node(in_node, "gen_in_node");

			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.add_string(gen_in_node, "RULE_ID", "FILE_NO", strlen("FILE_NO"));
			TRS.add_char(gen_in_node, "PROCSTEP", '2');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(s_file_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

			TRS.free_node(cmn_out);

		}


		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
		//TRS.copy(CBASFILDEF.INSP_ID, sizeof(CBASFILDEF.INSP_ID), in_node, "INSP_ID");
		//20231013 PDF 파일도 넣어야 되서..File Type 추가.


		TRS.copy(CBASFILDEF.FILE_TYPE, sizeof(CBASFILDEF.FILE_TYPE), in_node, "FILE_TYPE");
		TRS.copy(CBASFILDEF.FILE_NAME, sizeof(CBASFILDEF.FILE_NAME), in_node, "FILE_NAME");
		TRS.copy(CBASFILDEF.AREA_ID, sizeof(CBASFILDEF.AREA_ID), in_node, "AREA_ID");
		//	TRS.copy(CBASFILDEF.OPER, sizeof(CBASFILDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
		TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "CMF_1");
		TRS.copy(CBASFILDEF.CMF_2, sizeof(CBASFILDEF.CMF_2), in_node, "CMF_2");
		TRS.copy(CBASFILDEF.CMF_3, sizeof(CBASFILDEF.CMF_3), in_node, "CMF_3");
		TRS.copy(CBASFILDEF.CMF_4, sizeof(CBASFILDEF.CMF_4), in_node, "CMF_4");
		TRS.copy(CBASFILDEF.CMF_5, sizeof(CBASFILDEF.CMF_5), in_node, "CMF_5");
		TRS.copy(CBASFILDEF.CMF_6, sizeof(CBASFILDEF.CMF_6), in_node, "CMF_6");
		TRS.copy(CBASFILDEF.CMF_7, sizeof(CBASFILDEF.CMF_7), in_node, "CMF_7");
		TRS.copy(CBASFILDEF.CMF_8, sizeof(CBASFILDEF.CMF_8), in_node, "CMF_8");
		//TRS.copy(CBASFILDEF.CMF_9, sizeof(CBASFILDEF.CMF_9), in_node, "CMF_9");
		CBASFILDEF.IMAGE_SIZE = TRS.get_int(in_node, "IMAGE_SIZE");

		/*
		if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) != MP_TRUE) {
			TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
		}
		*/



		blob_file = 0x00;
		blob_size = 0;


		TRS.get_blob(in_node, MP_BIN_DATA_1, &blob_file, &blob_size);
		iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

		memcpy(CBASFILDEF.IMAGE_DATA, blob_file, iSize);

		TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_insert_cbasfildef(&CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");;
			TRS.add_fieldmsg(out_node, "CBASFILDEF INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		TRS.add_string(out_node, "FILE_NO", CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO));

		iStart = 0;

		for (blob_size -= MAXBUFLEN, iStart += MAXBUFLEN; blob_size > 0; blob_size -= MAXBUFLEN, iStart += MAXBUFLEN)
		{
			iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

			memcpy(CBASFILDEF.IMAGE_DATA, blob_file + iStart, iSize);
			CBASFILDEF.IMAGE_SIZE = iSize;
			DBU_update_cbasfildef(2, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "BAS-0004");

				TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE 2", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASFILDEF.FACTORY), CBASFILDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
				TRS.add_fieldmsg(out_node, "FILE_PATH", MP_STR, sizeof(CBASFILDEF.FILE_PATH), CBASFILDEF.FILE_PATH);
				TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASFILDEF.FILE_NAME), CBASFILDEF.FILE_NAME);
				TRS.add_fieldmsg(out_node, "IMAGE_SIZE", MP_INT, CBASFILDEF.IMAGE_SIZE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

	}
	else if (TRS.get_procstep(in_node) == '5')
	{


		//File No 존재시 삭제.다시 INSERT
		if (COM_isnullspace(TRS.get_string(in_node, "FILE_NO")) != MP_TRUE)
		{
			DBU_init_cbasfildef(&CBASFILDEF);
			TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO), in_node, "FILE_NO");
			TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
			TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "CMF_1");
			TRS.copy(CBASFILDEF.CMF_2, sizeof(CBASFILDEF.CMF_2), in_node, "CMF_2");
			TRS.copy(CBASFILDEF.CMF_3, sizeof(CBASFILDEF.CMF_3), in_node, "CMF_3");
			TRS.copy(CBASFILDEF.CMF_4, sizeof(CBASFILDEF.CMF_4), in_node, "CMF_4");
			TRS.copy(CBASFILDEF.CMF_5, sizeof(CBASFILDEF.CMF_5), in_node, "CMF_5");
			TRS.copy(CBASFILDEF.CMF_6, sizeof(CBASFILDEF.CMF_6), in_node, "CMF_6");
			TRS.copy(CBASFILDEF.CMF_7, sizeof(CBASFILDEF.CMF_7), in_node, "CMF_7");
			TRS.copy(CBASFILDEF.CMF_8, sizeof(CBASFILDEF.CMF_8), in_node, "CMF_8");
			DBU_update_cbasfildef(5, &CBASFILDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");;
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


		}
	}
	else if (TRS.get_procstep(in_node) == '6')
	{


	if (COM_isnullspace(TRS.get_string(in_node, "IMAGE_CODE")) == MP_TRUE)
	{
		strcpy(s_msg_code, "QCM-0004");;
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	//File No 존재시 삭제.다시 INSERT
	if (COM_isnullspace(TRS.get_string(in_node, "FILE_NO")) != MP_TRUE)
	{
		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO), in_node, "FILE_NO");
		DBU_delete_cbasfildef(1, &CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");;
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		memcpy(s_file_no, TRS.get_string(in_node, "FILE_NO"), strlen(TRS.get_string(in_node, "FILE_NO")));
		/*
		DBU_update_cbasfildef(3, &CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");;
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		*/
	}
	else {

		gen_in_node = TRS.add_node(in_node, "gen_in_node");

		//LOT ID 발번            
		CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
		TRS.add_string(gen_in_node, "RULE_ID", "FILE_NO", strlen("FILE_NO"));
		TRS.add_char(gen_in_node, "PROCSTEP", '2');

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		memcpy(s_file_no, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

		TRS.free_node(cmn_out);

	}


	DBU_init_cbasfildef(&CBASFILDEF);
	TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
	memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
	//TRS.copy(CBASFILDEF.INSP_ID, sizeof(CBASFILDEF.INSP_ID), in_node, "INSP_ID");
	//20231013 PDF 파일도 넣어야 되서..File Type 추가.


	TRS.copy(CBASFILDEF.FILE_TYPE, sizeof(CBASFILDEF.FILE_TYPE), in_node, "FILE_TYPE");
	TRS.copy(CBASFILDEF.FILE_NAME, sizeof(CBASFILDEF.FILE_NAME), in_node, "FILE_NAME");
	TRS.copy(CBASFILDEF.AREA_ID, sizeof(CBASFILDEF.AREA_ID), in_node, "AREA_ID");
	TRS.copy(CBASFILDEF.LOT_ID, sizeof(CBASFILDEF.LOT_ID), in_node, "LOT_ID");
	TRS.copy(CBASFILDEF.OPER, sizeof(CBASFILDEF.OPER), in_node, "OPER");
	TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "CMF_1");
	CBASFILDEF.IMAGE_SIZE = TRS.get_int(in_node, "IMAGE_SIZE");

	/*
	if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) != MP_TRUE) {
		TRS.copy(CBASFILDEF.MAT_ID, sizeof(CBASFILDEF.MAT_ID), in_node, "MAT_ID");
	}
	*/



	blob_file = 0x00;
	blob_size = 0;


	TRS.get_blob(in_node, MP_BIN_DATA_1, &blob_file, &blob_size);
	iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

	memcpy(CBASFILDEF.IMAGE_DATA, blob_file, iSize);

	TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
	memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));

	DBU_insert_cbasfildef(&CBASFILDEF);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "CMN-0004");;
		TRS.add_fieldmsg(out_node, "CBASFILDEF INSERT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	TRS.add_string(out_node, "FILE_NO", CBASFILDEF.FILE_NO, sizeof(CBASFILDEF.FILE_NO));

	iStart = 0;

	for (blob_size -= MAXBUFLEN, iStart += MAXBUFLEN; blob_size > 0; blob_size -= MAXBUFLEN, iStart += MAXBUFLEN)
	{
		iSize = blob_size > MAXBUFLEN ? MAXBUFLEN : blob_size;

		memcpy(CBASFILDEF.IMAGE_DATA, blob_file + iStart, iSize);
		CBASFILDEF.IMAGE_SIZE = iSize;
		DBU_update_cbasfildef(2, &CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");

			TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE 2", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASFILDEF.FACTORY), CBASFILDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_fieldmsg(out_node, "FILE_PATH", MP_STR, sizeof(CBASFILDEF.FILE_PATH), CBASFILDEF.FILE_PATH);
			TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASFILDEF.FILE_NAME), CBASFILDEF.FILE_NAME);
			TRS.add_fieldmsg(out_node, "IMAGE_SIZE", MP_INT, CBASFILDEF.IMAGE_SIZE);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
	}

	}

	return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_File_Attach_Validation()
- Validation Check sub function of "CUS_QCM_File_Attach" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_File_Attach_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"123456") == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
	{
		strcpy(s_msg_code, "WIP-0001");
		TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		return MP_FALSE;
	}

	return MP_TRUE;
}
