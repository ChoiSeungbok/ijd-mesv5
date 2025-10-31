/*******************************************************************************

    System      : MESplus
    Module      : CUS_BAS
    File Name   : CUS_BAS_update_used_data.c
    Description : 프로그램 사용 이력 저장

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2014/04/03  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"

int CUS_BAS_UPDATE_USED_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_BAS_Update_Used_Data()
        - 프로그램 사용 이력 저장
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Used_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_UPDATE_USED_DATA(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_Update_Used_Data", out_node);
    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    if(i_ret == MP_TRUE) 
    {
        if(gb_multi_transaction == MP_FALSE)
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
    CUS_BAS_UPDATE_USED_DATA()
        - Main sub function of "CUS_BAS_Update_Used_Data" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_USED_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CSECUSEDAT_TAG CSECUSEDAT;
	char sSysDate[14];

    LOG_head("CUS_BAS_UPDATE_USED_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(sSysDate, ' ', sizeof(sSysDate));

	DB_get_systime(sSysDate);
	
	DBU_init_csecusedat(&CSECUSEDAT);

	TRS.copy(CSECUSEDAT.FACTORY, sizeof(CSECUSEDAT.FACTORY), in_node, IN_FACTORY);
	memcpy(CSECUSEDAT.USE_DATE, sSysDate, 8);
	TRS.copy(CSECUSEDAT.PROGRAM_ID, sizeof(CSECUSEDAT.PROGRAM_ID), in_node, "PROGRAM_ID");
	TRS.copy(CSECUSEDAT.USER_ID, sizeof(CSECUSEDAT.USER_ID), in_node, IN_USERID);

	DBU_select_csecusedat(1, &CSECUSEDAT);
	if(DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "CSECUSEDAT Select", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSECUSEDAT.FACTORY), CSECUSEDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "USE_DATE", MP_STR, sizeof(CSECUSEDAT.USE_DATE), CSECUSEDAT.USE_DATE);
        TRS.add_fieldmsg(out_node, "PROGRAM_ID", MP_STR, sizeof(CSECUSEDAT.PROGRAM_ID), CSECUSEDAT.PROGRAM_ID);
		TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(CSECUSEDAT.USER_ID), CSECUSEDAT.USER_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
	}
	
	CSECUSEDAT.USE_COUNT++;
    TRS.copy(CSECUSEDAT.FUNC_NAME, sizeof(CSECUSEDAT.FUNC_NAME), in_node, "FUNC_NAME");
	TRS.copy(CSECUSEDAT.PROGRAM_DESC, sizeof(CSECUSEDAT.PROGRAM_DESC), in_node, "PROGRAM_DESC");
	TRS.copy(CSECUSEDAT.PG_KIND, sizeof(CSECUSEDAT.PG_KIND), in_node, "PG_KIND");
	memcpy(CSECUSEDAT.UPDATE_TIME, sSysDate, sizeof(sSysDate));

	if(DB_error_code == DB_SUCCESS)
	{
		DBU_update_csecusedat(1, &CSECUSEDAT);
	}
	else
	{
		DBU_insert_csecusedat(&CSECUSEDAT);
	}

	if(DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "CSECUSEDAT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CSECUSEDAT.FACTORY), CSECUSEDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "USE_DATE", MP_STR, sizeof(CSECUSEDAT.USE_DATE), CSECUSEDAT.USE_DATE);
        TRS.add_fieldmsg(out_node, "PROGRAM_ID", MP_STR, sizeof(CSECUSEDAT.PROGRAM_ID), CSECUSEDAT.PROGRAM_ID);
		TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(CSECUSEDAT.USER_ID), CSECUSEDAT.USER_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
	}

	return MP_TRUE;
}
