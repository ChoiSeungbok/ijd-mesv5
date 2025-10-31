/******************************************************************************'

System      : MESplus
Module      : CUS_BAS
File Name   : COMCus_update_caption.c
Description : Caption Setup function module

MES Version : 5.3.4

Function List
- CUS_BAS_update_Attach()
+ Create/Update/Delete Caption definition
- CUS_BAS_UPDATE_ATTACH()
+ Main sub function of CUS_BAS_update_Attach function
+ Create/Update/Delete Caption definition
- CUS_BAS_update_Attach_Validation()
+ Main sub function of CUS_BAS_UPDATE_ATTACH function
+ Check the condition for create/update/delete Caption
Detail Description
- CUS_BAS_UPDATE_ATTACH()
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

#include "CUS_common.h"
#include "CUS_defines.h"
#include "CUS_WIP_common.h"

#define MAXBUFLEN  2048000

int CUS_BAS_UPDATE_ATTACH(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

int CUS_BAS_update_Attach_Validation(char *s_msg_code,
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
int CUS_BAS_update_Attach(TRSNode *in_node,
	TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAS_UPDATE_ATTACH(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_BAS_UPDATE_ATTACH", out_node);

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
CUS_BAS_UPDATE_ATTACH()
- Main sub function of "CUS_BAS_update_Attach" function
- Create/Update/Delete Caption definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_ATTACH(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CBASFILDEF_TAG CBASFILDEF;

	TRSNode	 *gen_in_node;
	TRSNode	 *cmn_out;
	char s_sys_time[14];
	char s_file_no[10];

    unsigned char *blob_file;
    long blob_size;
    int iStart = 0;
    int iSize = 0;

	LOG_head("CUS_BAS_UPDATE_ATTACH");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	if (CUS_BAS_update_Attach_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memset(s_sys_time, ' ', sizeof(s_sys_time));

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

	memset(s_file_no, ' ', sizeof(s_file_no));

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
	}
	else
	{
		memcpy(s_file_no, TRS.get_string(in_node, "FILE_NO"), strlen(TRS.get_string(in_node, "FILE_NO")));
	}

	if (TRS.get_procstep(in_node) == '1')
	{
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

		TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "CMF_1");
		TRS.copy(CBASFILDEF.CMF_2, sizeof(CBASFILDEF.CMF_2), in_node, "CMF_2");
		TRS.copy(CBASFILDEF.CMF_3, sizeof(CBASFILDEF.CMF_3), in_node, "CMF_3");
		TRS.copy(CBASFILDEF.CMF_4, sizeof(CBASFILDEF.CMF_4), in_node, "CMF_4");
		TRS.copy(CBASFILDEF.CMF_5, sizeof(CBASFILDEF.CMF_5), in_node, "CMF_5");
		TRS.copy(CBASFILDEF.CMF_6, sizeof(CBASFILDEF.CMF_6), in_node, "CMF_6");
		TRS.copy(CBASFILDEF.CMF_7, sizeof(CBASFILDEF.CMF_7), in_node, "CMF_7");
		TRS.copy(CBASFILDEF.CMF_8, sizeof(CBASFILDEF.CMF_8), in_node, "CMF_8");
		TRS.copy(CBASFILDEF.CMF_9, sizeof(CBASFILDEF.CMF_9), in_node, "CMF_9");
		TRS.copy(CBASFILDEF.CMF_10, sizeof(CBASFILDEF.CMF_10), in_node, "CMF_10");
		TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CBASFILDEF.UPDATE_USER_ID, sizeof(CBASFILDEF.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

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
            if(DB_error_code != DB_SUCCESS)
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
		DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
		DBU_select_cbasfildef(1, &CBASFILDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CBASFILDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

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
		TRS.copy(CBASFILDEF.CMF_1, sizeof(CBASFILDEF.CMF_1), in_node, "CMF_1");
		TRS.copy(CBASFILDEF.CMF_2, sizeof(CBASFILDEF.CMF_2), in_node, "CMF_2");
		TRS.copy(CBASFILDEF.CMF_3, sizeof(CBASFILDEF.CMF_3), in_node, "CMF_3");
		TRS.copy(CBASFILDEF.CMF_4, sizeof(CBASFILDEF.CMF_4), in_node, "CMF_4");
		TRS.copy(CBASFILDEF.CMF_5, sizeof(CBASFILDEF.CMF_5), in_node, "CMF_5");
		TRS.copy(CBASFILDEF.CMF_6, sizeof(CBASFILDEF.CMF_6), in_node, "CMF_6");
		TRS.copy(CBASFILDEF.CMF_7, sizeof(CBASFILDEF.CMF_7), in_node, "CMF_7");
		TRS.copy(CBASFILDEF.CMF_8, sizeof(CBASFILDEF.CMF_8), in_node, "CMF_8");
		TRS.copy(CBASFILDEF.CMF_9, sizeof(CBASFILDEF.CMF_9), in_node, "CMF_9");
		TRS.copy(CBASFILDEF.CMF_10, sizeof(CBASFILDEF.CMF_10), in_node, "CMF_10");
		TRS.copy(CBASFILDEF.CREATE_USER_ID, sizeof(CBASFILDEF.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(CBASFILDEF.UPDATE_USER_ID, sizeof(CBASFILDEF.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CBASFILDEF.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_update_cbasfildef(1, &CBASFILDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");;
			TRS.add_fieldmsg(out_node, "CBASFILDEF UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		/*DBU_init_cbasfildef(&CBASFILDEF);
		TRS.copy(CBASFILDEF.FACTORY, sizeof(CBASFILDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(CBASFILDEF.FILE_NO, s_file_no, sizeof(s_file_no));
		DBU_select_cbasfildef(1, &CBASFILDEF);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "CMN-0004");
			TRS.add_fieldmsg(out_node, "CBASFILDEF DELETE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FILE_NO", MP_STR, sizeof(CBASFILDEF.FILE_NO), CBASFILDEF.FILE_NO);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}*/

		DBU_delete_cbasfildef(1, &CBASFILDEF);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_BAS_update_Attach_Validation()
- Main sub function of "CUS_BAS_UPDATE_ATTACH" function
- Check the condition for create/update/delete Caption & vbCrLf    Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_update_Attach_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	///* ProcStep Validation */
	//if (COM_service_validation(s_msg_code,
	//	in_node,
	//	out_node,
	//	TRS.get_procstep(in_node),
	//	"IUDFL") == MP_FALSE)
	//{
	//	return MP_FALSE;
	//}

	return MP_TRUE;
}


