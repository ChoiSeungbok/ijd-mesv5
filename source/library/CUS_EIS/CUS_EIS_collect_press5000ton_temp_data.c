/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_EIS_collect_press5000ton_temp_data.c
Description : 5000ton Press 설비 데이터 수집(냉각수 온도(IN/OUT), 유압유 온도)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2022/03/23  정광용        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"
#include <math.h>

int CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_EIS_Collect_Press5000ton_Temp_Data()
- 5000ton Press 설비 데이터 수집(냉각수 온도(IN/OUT), 유압유 온도)
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Press5000ton_Temp_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Press5000ton_Temp_Data", out_node);

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
CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA()
- Main sub function of "CUS_EIS_Collect_Press5000ton_Temp_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    LOG_head("CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Validation_CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(s_msg_code, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

	// 실제 트랜잭션 발생 / 설비의 디바이스가 나눠져있고, 1초 단위라서 MC에서 저장이 불가능하여 MES에서 처리
	// PROCSTEP(1) : 냉각수 온도 IN 값 저장(글로벌 변수)
	// PROCSTEP(2) : 냉각수 온도 OUT 값 저장(글로벌 변수)
	// PROCSTEP(3) : 유압유 온도 값 저장(글로벌 변수)
    if (TRS.get_procstep(in_node) == '1')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "PV_CLW_IN_TEMP")) == MP_FALSE)
			pv_clw_in_temp = atof(TRS.get_string(in_node, "PV_CLW_IN_TEMP"));
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "PV_CLW_OUT_TEMP")) == MP_FALSE)
			pv_clw_out_temp = atof(TRS.get_string(in_node, "PV_CLW_OUT_TEMP"));
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		if (COM_isnullspace(TRS.get_string(in_node, "PV_HDL_TEMP")) == MP_FALSE)
			pv_hdl_temp = atof(TRS.get_string(in_node, "PV_HDL_TEMP"));
	}

    return MP_TRUE;
}

/*******************************************************************************
Validation_CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA()
- Main sub function of "CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- struct MRASRESDEF_TAG *MRASRESDEF : 설비
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_COLLECT_PRESS5000TON_TEMP_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "123") == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
