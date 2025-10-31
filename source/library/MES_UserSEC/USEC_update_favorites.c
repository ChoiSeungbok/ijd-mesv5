/*******************************************************************************

    System      : MESplus
    Module      : User Routine for SEC
    File Name   : USEC_Update_Favorites.c
    Description : User Routine for SEC_Update_Favorites

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/10  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "USEC_common.h"

int SEC_UPDATE_FAVORITES_BEFORE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

int SEC_Update_Favorites_Before_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */

	char s_msg_code[MP_SIZE_MSG];
	int i_ret = MP_TRUE;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = SEC_UPDATE_FAVORITES_BEFORE(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "SEC_UPDATE_FAVORITES_BEFORE", out_node);

	return i_ret;

}

int SEC_Update_Favorites_After_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
    return MP_TRUE;
}


int SEC_UPDATE_FAVORITES_BEFORE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

	struct MSECUSRFUN_TAG MSECUSRFUN;


	if (TRS.get_procstep(in_node) == 'D')
	{
		DBC_init_msecusrfun(&MSECUSRFUN);
		TRS.copy(MSECUSRFUN.FACTORY, sizeof(MSECUSRFUN.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MSECUSRFUN.PROGRAM_ID, sizeof(MSECUSRFUN.PROGRAM_ID), in_node, "PROGRAM_ID");
		TRS.copy(MSECUSRFUN.USER_ID, sizeof(MSECUSRFUN.USER_ID), in_node, IN_USERID);
		TRS.copy(MSECUSRFUN.FUNC_NAME, sizeof(MSECUSRFUN.FUNC_NAME), in_node, "FUNC_NAME");
		DBC_select_msecusrfun(2, &MSECUSRFUN);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "SEC-0004");
			TRS.add_fieldmsg(out_node, "MSECUSRFUN SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MSECUSRFUN.FACTORY), MSECUSRFUN.FACTORY);
			TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MSECUSRFUN.USER_ID), MSECUSRFUN.USER_ID);
			TRS.add_fieldmsg(out_node, "PROGRAM_ID", MP_STR, sizeof(MSECUSRFUN.PROGRAM_ID), MSECUSRFUN.PROGRAM_ID);
			TRS.add_fieldmsg(out_node, "FUNC_NAME", MP_STR, sizeof(MSECUSRFUN.FUNC_NAME), MSECUSRFUN.FUNC_NAME);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		TRS.set_int(in_node, "SEQ_NUM", MSECUSRFUN.SEQ_NUM);
	}

	


	return MP_TRUE;
}

