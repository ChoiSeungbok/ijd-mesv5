/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_mold_tool_event.c
Description : 툴 이벤트

MES Version : 5.0

Function List
-   step 1: 툴 장착,탈착 이벤트 발생. 
    step 2: 금형 현황조회 사용횟수 변경 

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/28  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Mold_Tool_Event_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_MOLD_TOOL_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Mold_Tool_Event()
- Mold Tool Event function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Tool_Event(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_MOLD_TOOL_EVENT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }
    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Mold_Tool_Event", out_node);

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
CUS_RAS_MOLD_TOOL_EVENT()
- Main sub function of "CUS_RAS_Mold_Tool_Eventt" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_MOLD_TOOL_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASTOLDEF_TAG MRASTOLDEF;

    struct work_date_tag work_date;

    TRSNode     *create_in_node;
    TRSNode     *cmn_out;
    TRSNode     **sts_list;
    TRSNode     *tool_sts_list;
    TRSNode     **Tool_tbl;
    TRSNode     *tool_in_node;

    char s_factory[10];
    char tool_event_procstep;
    int sts_count = 0;
    int icount = 0;
    int iUseCount = 0;

    LOG_head("CUS_RAS_Mold_Tool_Event");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_Mold_Tool_Event_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    //툴 이벤트 저장
    if (TRS.get_procstep(in_node) == '1')
    {
        tool_event_procstep = '1';

        create_in_node = TRS.add_node(in_node, "create_in_node");
        TRS.add_char(create_in_node, IN_PROCSTEP, tool_event_procstep);
        CopyDefaultMembers(create_in_node, in_node);

        TRS.add_nstring(create_in_node, "TOOL_ID", TRS.get_string(in_node, "TOOL_ID"));
        TRS.add_nstring(create_in_node, "TOOL_EVENT_ID", TRS.get_string(in_node, "TOOL_EVENT_ID"));
        TRS.add_nstring(create_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
        TRS.add_nstring(create_in_node, "TRAN_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

        sts_list = TRS.get_list(in_node, "STS_LIST");
        sts_count = TRS.get_item_count(in_node, "STS_LIST");
   
        for (int i = 0; i < sts_count; i++)
        {
            tool_sts_list = TRS.add_node(create_in_node, "STS_LIST");
            TRS.add_nstring(tool_sts_list, "TOOL_STS", TRS.get_string(sts_list[i], "TOOL_STS"));
        }

        cmn_out = TRS.create_node("cmn_out");
        if (CUS_RAS_TOOL_EVENT(s_msg_code, create_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);
    }
    else if (TRS.get_procstep(in_node) == '2')
    {

        memset(s_factory, ' ', sizeof(s_factory));
        TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
        memset(&work_date, ' ', sizeof(work_date));

        Get_shift(s_factory, &work_date);

        //LOT을 한번에 여러개 처리 한다. 
        Tool_tbl = TRS.get_list(in_node, "TOOL_TBL");
        icount = TRS.get_item_count(in_node, "TOOL_TBL");

        for (int i = 0; i < icount; i++)
        {
            iUseCount = 0;

            //TOOL 조회
            DBU_init_mrastoldef(&MRASTOLDEF);
            TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), Tool_tbl[i], "TOOL_ID");

            DBU_select_mrastoldef(1, &MRASTOLDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "RAS-0004");
                TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            iUseCount = TRS.get_int(Tool_tbl[i], "USE_COUNT");
            COM_itoa_left(MRASTOLDEF.TOOL_STS_4, iUseCount, sizeof(MRASTOLDEF.TOOL_STS_4));
            memcpy(MRASTOLDEF.TOOL_STS_28, work_date.s_work_date, sizeof(work_date.s_work_date));   //작업일자
            memcpy(MRASTOLDEF.TOOL_STS_29, work_date.s_day_night, sizeof(work_date.s_day_night));   //작업조
            memcpy(MRASTOLDEF.TOOL_STS_30, work_date.s_sys_time, sizeof(work_date.s_sys_time));     //작업시간

            DBU_update_mrastoldef(1, &MRASTOLDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "RAS-0004");
                TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            tool_in_node = TRS.add_node(in_node, "tool_in_node");
            TRS.add_char(tool_in_node, IN_PROCSTEP, 'U');
            CopyDefaultMembers(tool_in_node, in_node);

            TRS.add_string(tool_in_node, "SUB_AREA_ID", MRASTOLDEF.SUB_AREA_ID, sizeof(MRASTOLDEF.SUB_AREA_ID));
            TRS.add_string(tool_in_node, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
            TRS.add_string(tool_in_node, "TOOL_DESC", MRASTOLDEF.TOOL_DESC, sizeof(MRASTOLDEF.TOOL_DESC));
            TRS.add_string(tool_in_node, "TOOL_TYPE", MRASTOLDEF.TOOL_TYPE, sizeof(MRASTOLDEF.TOOL_TYPE));
            TRS.add_string(tool_in_node, "TOOL_GRP", MRASTOLDEF.TOOL_GRP, sizeof(MRASTOLDEF.TOOL_GRP));
            TRS.add_string(tool_in_node, "AREA_ID", MRASTOLDEF.AREA_ID, sizeof(MRASTOLDEF.AREA_ID));
            TRS.add_string(tool_in_node, "VENDOR_ID", MRASTOLDEF.VENDOR_ID, sizeof(MRASTOLDEF.VENDOR_ID));
            TRS.add_string(tool_in_node, "TOOL_COMMENT", MRASTOLDEF.TOOL_COMMENT, sizeof(MRASTOLDEF.TOOL_COMMENT));

            //TOOL 업데이트시 현재 TOOL_STS의 값을 동일하게 넣어준다.
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_1, sizeof(MRASTOLDEF.TOOL_STS_1));        //CAR
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_2, sizeof(MRASTOLDEF.TOOL_STS_2));        //상판,하판
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_3, sizeof(MRASTOLDEF.TOOL_STS_3));        //MAX USE COUNT
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_4, sizeof(MRASTOLDEF.TOOL_STS_4));        //USE COUNT           
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_5, sizeof(MRASTOLDEF.TOOL_STS_5));        //ALAM COUNT
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_6, sizeof(MRASTOLDEF.TOOL_STS_6));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_7, sizeof(MRASTOLDEF.TOOL_STS_7));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_8, sizeof(MRASTOLDEF.TOOL_STS_8));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_9, sizeof(MRASTOLDEF.TOOL_STS_9));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_10, sizeof(MRASTOLDEF.TOOL_STS_10));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_11, sizeof(MRASTOLDEF.TOOL_STS_11));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_12, sizeof(MRASTOLDEF.TOOL_STS_12));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_13, sizeof(MRASTOLDEF.TOOL_STS_13));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_14, sizeof(MRASTOLDEF.TOOL_STS_14));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_15, sizeof(MRASTOLDEF.TOOL_STS_15));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_16, sizeof(MRASTOLDEF.TOOL_STS_16));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_17, sizeof(MRASTOLDEF.TOOL_STS_17));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_18, sizeof(MRASTOLDEF.TOOL_STS_18));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_19, sizeof(MRASTOLDEF.TOOL_STS_19));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_20, sizeof(MRASTOLDEF.TOOL_STS_20));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_21, sizeof(MRASTOLDEF.TOOL_STS_21));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_22, sizeof(MRASTOLDEF.TOOL_STS_22));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_23, sizeof(MRASTOLDEF.TOOL_STS_23));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_24, sizeof(MRASTOLDEF.TOOL_STS_24));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_25, sizeof(MRASTOLDEF.TOOL_STS_25));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_26, sizeof(MRASTOLDEF.TOOL_STS_26));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_27, sizeof(MRASTOLDEF.TOOL_STS_27));
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_28, sizeof(MRASTOLDEF.TOOL_STS_28));        //작업일자
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");     
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_29, sizeof(MRASTOLDEF.TOOL_STS_29));        //작업조
            tool_sts_list = TRS.add_node(tool_in_node, "STS_LIST");
            TRS.add_string(tool_sts_list, "TOOL_STS", MRASTOLDEF.TOOL_STS_30, sizeof(MRASTOLDEF.TOOL_STS_30));         //작업시간

            cmn_out = TRS.create_node("cmn_out");
            if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
    }
	else if (TRS.get_procstep(in_node) == '3')
	 {

			 //TOOL 조회
			 DBU_init_mrastoldef(&MRASTOLDEF);
			 TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
			 TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), in_node, "TOOL_ID");

			 DBU_select_mrastoldef(1, &MRASTOLDEF);
			 if (DB_error_code != DB_SUCCESS)
			 {
				 strcpy(s_msg_code, "RAS-0004");
				 TRS.add_fieldmsg(out_node, "MRASTOLDEF SELECT ", DT_NOVALUESTRING);
				 TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				 TRS.add_dberrmsg(out_node, DB_error_msg);

				 gs_log_type.type = MP_LOG_ERROR;
				 gs_log_type.e_type = MP_LOG_E_SYSTEM;
				 gs_log_type.category = MP_LOG_CATE_TRANS;
				 COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				 return MP_FALSE;
			 }

			 TRS.copy(MRASTOLDEF.TOOL_COMMENT, sizeof(MRASTOLDEF.TOOL_COMMENT), in_node, "TRAN_COMMENT");

			 DBU_update_mrastoldef(1, &MRASTOLDEF);
			 if (DB_error_code != DB_SUCCESS)
			 {
				 strcpy(s_msg_code, "RAS-0004");
				 TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
				 TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
				 TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
				 TRS.add_dberrmsg(out_node, DB_error_msg);

				 gs_log_type.type = MP_LOG_ERROR;
				 gs_log_type.e_type = MP_LOG_E_SYSTEM;
				 gs_log_type.category = MP_LOG_CATE_TRANS;
				 COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				 return MP_FALSE;
			 }

		  


	 }
    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_Mold_Tool_Event_Validation()
- Validation Check sub function of "CUS_RAS_MOLD_TOOL_EVENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Mold_Tool_Event_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        if (COM_isnullspace(TRS.get_string(in_node, "TOOL_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_NVST);

            return MP_FALSE;
        }

        if (COM_isnullspace(TRS.get_string(in_node, "TOOL_EVENT_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "TOOL_EVENT_ID", MP_NVST);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
