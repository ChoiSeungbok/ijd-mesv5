/*******************************************************************************

    System      : MESplus
    Module      : User Routine for RAS
    File Name   : URAS_Resource_Event.c
    Description : User Routine for RAS_Resource_Event

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

#include "URAS_common.h"
#include "DBU_common.h"

int RAS_RESOURCE_EVENT_BEFORE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int RAS_RESOURCE_EVENT_AFTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

int RAS_Resource_Event_Before_1(TRSNode *in_node, TRSNode *out_node)
{
	/*
	char s_msg_code[MP_SIZE_MSG];
	int i_ret = MP_TRUE;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = RAS_RESOURCE_EVENT_BEFORE(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "RAS_RESOURCE_EVENT_BEFORE", out_node);

	return i_ret;
	*/

	return MP_TRUE;

}

int RAS_Resource_Event_After_1(TRSNode *in_node, TRSNode *out_node)
{
	/*
	char s_msg_code[MP_SIZE_MSG];
	int i_ret = MP_TRUE;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = RAS_RESOURCE_EVENT_AFTER(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "RAS_RESOURCE_EVENT_AFTER", out_node);

	return i_ret;
	*/

	return MP_TRUE;

}

int RAS_RESOURCE_EVENT_BEFORE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	//struct MRASRESDEF_TAG MRASRESDEF;
	//RES_PRI_STS 값을 변경하지 않기 위해 기존값으로 다시 넘겨준다.
	//RES_PRI_STS값은 FMB 설비 상태로 쓰이기 때문에 코어에서 변경해주는 값으로 적용하지 않는다.

	// LOG
	LOG_head("RAS_RESOURCE_EVENT_BEFORE");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/*
	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);

	//RES_UP_DOWN_FLAG
	TRS.add_char(in_node, "RES_UP_DOWN_FLAG_VALUE", MRASRESDEF.RES_UP_DOWN_FLAG);
	TRS.add_string(in_node, "RES_PRI_STS_VALUE", MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS));
	*/
	return MP_TRUE;
}



int RAS_RESOURCE_EVENT_AFTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	//struct MRASRESDEF_TAG MRASRESDEF;

	// LOG
	LOG_head("RAS_RESOURCE_EVENT_AFTER");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	/*
	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);

	MRASRESDEF.RES_UP_DOWN_FLAG = TRS.get_char(in_node, "RES_UP_DOWN_FLAG_VALUE");
	TRS.copy(MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS), in_node, "RES_PRI_STS_VALUE");
	DBU_update_mrasresdef(1, &MRASRESDEF);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "RAS-0004");
		TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
		TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	*/

	return MP_TRUE;
}

