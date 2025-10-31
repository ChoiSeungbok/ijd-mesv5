/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_change_etc_comment.c
    Description : CV Inv Lot

    MES Version : 4.0.0

    Function List
        - CUS_INV_Change_Etc_Comment()
            + Change ETC Comment
        - CUS_INV_CHANGE_ETC_COMMENT()
            + Main sub function of "CUS_INV_Change_Etc_Comment" function
            + Change ETC Comment definition
        - CUS_INV_Change_Etc_Comment_Validation()
            + Validation Check sub function of "CUS_INV_CHANGE_ETC_COMMENT" function

    Detail Description
        -

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/12/16  Miracom       Create     

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_CHANGE_ETC_COMMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Change_Etc_Comment_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Change_Etc_Comment_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Change_Etc_Comment_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CHANGE_ETC_COMMENT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
      

/*******************************************************************************
    CUS_INV_Change_Etc_Comment()
        - Change Etc Comment
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_Change_Etc_Comment(TRSNode *in_node,
                 TRSNode *out_node)
{   
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);
    
    i_ret = CUS_INV_CHANGE_ETC_COMMENT_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CHANGE_ETC_COMMENT", out_node);

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
CUS_INV_CHANGE_ETC_COMMENT()
- Main sub function of "CUS_INV_Change_Etc_Comment" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_CHANGE_ETC_COMMENT_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	TRSNode *change_in_node;
	TRSNode **lot_list;
	TRSNode *comment_list;
	int i;

	LOG_head("CUS_INV_CHANGE_ETC_COMMENT");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Change_Etc_Comment_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	change_in_node = TRS.add_node(in_node, "change_in_node");
	CopyDefaultMembers(change_in_node, in_node);

	lot_list = TRS.get_list(in_node, "LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "LOT_LIST"); i++)
	{
		comment_list = TRS.add_node(change_in_node, "LOT_LIST");
		TRS.add_nstring(comment_list, "LOT_ID", TRS.get_string(lot_list[i], "LOT_ID"));
		TRS.add_int(comment_list, "SEQ", TRS.get_int(lot_list[i], "SEQ"));
		TRS.add_nstring(comment_list, "COMMENT", TRS.get_string(lot_list[i], "COMMENT"));
	}

	if (CUS_INV_Change_Etc_Comment_Before_Transaction(s_msg_code, 0, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CHANGE_ETC_COMMENT(s_msg_code, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Change_Etc_Comment_After_Transaction(s_msg_code, 0, change_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}
 
/*******************************************************************************
    CUS_INV_CHANGE_ETC_COMMENT()
        - Main sub function of "CUS_INV_Change_Etc_Comment" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure    
*******************************************************************************/
int CUS_INV_CHANGE_ETC_COMMENT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node)
{
    struct MINVETCLOT_TAG MINVETCLOT;

	int i;

	TRSNode **lot_list;

	lot_list = TRS.get_list(in_node, "LOT_LIST");

	for(i = 0; i < TRS.get_item_count(in_node, "LOT_LIST") ; i++)
	{
		DBU_init_minvetclot(&MINVETCLOT);
		TRS.copy(MINVETCLOT.FACTORY, sizeof(MINVETCLOT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVETCLOT.LOT_ID, sizeof(MINVETCLOT.LOT_ID), lot_list[i], "LOT_ID");
		MINVETCLOT.SEQ = TRS.get_int(lot_list[i], "SEQ");
		DBU_select_minvetclot(1, &MINVETCLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "MINVETCLOT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVETCLOT.FACTORY), MINVETCLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);
			TRS.add_fieldmsg(out_node, "SEQ", MP_INT, MINVETCLOT.SEQ);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 주석 업데이트
		TRS.copy(MINVETCLOT.ETC_COMMENT, sizeof(MINVETCLOT.ETC_COMMENT), lot_list[i], "COMMENT");
		TRS.copy(MINVETCLOT.UPDATE_USER_ID, sizeof(MINVETCLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVETCLOT.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
		DBU_update_minvetclot(1, &MINVETCLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVETCLOT.FACTORY), MINVETCLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVETCLOT.LOT_ID), MINVETCLOT.LOT_ID);
			TRS.add_fieldmsg(out_node, "SEQ", MP_INT, MINVETCLOT.SEQ);
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
    CUS_INV_Change_Etc_Comment_Validation()
        - Validation Check sub function of "CUS_INV_CHANGE_ETC_COMMENT" function
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Change_Etc_Comment_Validation(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node)
{
    /*
	if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Change_Etc_Comment_Before_Transaction()
- Main sub function of "CUS_INV_CHANGE_ETC_COMMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Change_Etc_Comment_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Change_Etc_Comment_After_Transaction()
- Main sub function of "CUS_INV_CHANGE_ETC_COMMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Change_Etc_Comment_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}