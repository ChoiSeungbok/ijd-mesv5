/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_resource_event.c
    Description : 설비의 상태 정보 수신

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/28  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_COLLECT_RESOURCE_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_RESOURCE_EVENT(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Collect_Resource_Event()
        - 설비의 상태 정보 수신(U : Connect, D : Disconnect)
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Resource_Event(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_RESOURCE_EVENT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Resource_Event", out_node);

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
    CUS_EIS_COLLECT_RESOURCE_EVENT()
        - Main sub function of "CUS_EIS_Collect_Resource_Event" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_RESOURCE_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;

    LOG_head("CUS_EIS_COLLECT_RESOURCE_EVENT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Validation_CUS_EIS_COLLECT_RESOURCE_EVENT(s_msg_code, in_node, &MRASRESDEF, out_node) == MP_FALSE)
        return MP_FALSE;

	/*
    if(MRASRESDEF.RES_UP_DOWN_FLAG == TRS.get_string(in_node, "RES_STATUS")[0])
    {
        TRS.add_fieldmsg(out_node, "The state of the equipment is the same, so the state is not changed", DT_NOVALUESTRING);

        TRS.add_fieldmsg(out_node, "RES_ID", DT_NSTRING, TRS.get_string(in_node, "RES_ID"));
        TRS.add_fieldmsg(out_node, "RES_STATUS", DT_NSTRING, TRS.get_string(in_node, "RES_STATUS"));

        return MP_FALSE;
    }

	*/

	//자동수신 설비가 아니면, ( 자동수신 대상이 아닌데  이서비스를 태우는 경우가 있어서 강제로 막음)
	if (MRASRESDEF.RES_CMF_2[0] != 'Y')
	{
		TRS.add_fieldmsg(out_node, "The status of this resource cannot be changed by res_cmf_2 setting ", DT_NOVALUESTRING);

		TRS.add_fieldmsg(out_node, "RES_ID", DT_NSTRING, TRS.get_string(in_node, "RES_ID"));
		TRS.add_fieldmsg(out_node, "RES_STATUS", DT_NSTRING, TRS.get_string(in_node, "RES_STATUS"));

		return MP_FALSE;
	}

    // RES_STATUS
    // U : Connect, D : Disconnect
    MRASRESDEF.RES_UP_DOWN_FLAG = TRS.get_string(in_node, "RES_STATUS")[0];

	if (TRS.get_string(in_node, "RES_STATUS")[0] == 'U')
	{
		memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));
		MRASRESDEF.RES_PRI_STS[0] = 'R';  // 가동
	} 
	else if (TRS.get_string(in_node, "RES_STATUS")[0] == 'D')
	{
		memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));
		MRASRESDEF.RES_PRI_STS[0] = 'I';  // 대기
	}
	else if (TRS.get_string(in_node, "RES_STATUS")[0] == 'I')
	{
		memset(MRASRESDEF.RES_PRI_STS, ' ', sizeof(MRASRESDEF.RES_PRI_STS));
		MRASRESDEF.RES_PRI_STS[0] = 'I';  // 대기
	}
        

    //TRS.copy(MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS), in_node, "RES_STATUS");



	/* END_LOT 이벤트가 발생(end서비스 내부코어에서 발생)과 동시에  EIS 설비신호가 올 때, 설비의 현재 SEQ를 가지고 있다가,
	   END_LOT 이벤트가 끝나고  가지고 있던 SEQ를 다시 STS 테이블에 예전 SEQ로 UPDATE 하는 현상을 방지하기 위해,
	   업데이트에 필요한 컬럼만 UPDATE SET절에 넣음. */
    memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time));
    TRS.copy(MRASRESDEF.RES_STS_2, sizeof(MRASRESDEF.RES_STS_1), in_node, "TRAN_TIME");
    DBU_update_mrasresdef(2, &MRASRESDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "RAS-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        TRS.add_fieldmsg(out_node, "RES_PRI_STS", DT_STRING, sizeof(MRASRESDEF.RES_PRI_STS), MRASRESDEF.RES_PRI_STS);

        return MP_FALSE;
    }

    if (MOA.fmb_publish_resource_status(TRS.get_factory(in_node), TRS.get_string(in_node, "RES_ID"), '1') == MP_FALSE)
    {
        LOG_head("RAS_RESOURCE_EVENT() - MOA.fmb_publish_resource_status ERROR");
        LOG_add("FACTORY", MP_NSTR, TRS.get_factory(in_node));
        LOG_add("RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));
        COM_log_write(MP_LOG_ERROR, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);
    }

    return MP_TRUE;
}

/*******************************************************************************
    Validation_CUS_EIS_COLLECT_RESOURCE_EVENT()
        - Main sub function of "CUS_EIS_COLLECT_RESOURCE_EVENT" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - struct MRASRESDEF_TAG *MRASRESDEF : 설비
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_RESOURCE_EVENT(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *out_node)
{
    if (COM_isnullspace(TRS.get_string(in_node, "RES_STATUS")) == MP_TRUE)
    {
        TRS.add_fieldmsg(out_node, "RES STATUS is empty", MP_NVST);
        TRS.add_fieldmsg(out_node, "RES_STATUS", MP_NSTR, TRS.get_string(in_node, "RES_STATUS"));

        return MP_FALSE;
    }

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
