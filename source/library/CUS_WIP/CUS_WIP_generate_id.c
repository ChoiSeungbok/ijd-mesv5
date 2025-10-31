/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_generate_id.c
Description : Generate ID function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/06  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Generate_Id_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Generate_Id_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Generate_Id_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Generate_Id()
- Generate Id
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Generate_Id(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_GENERATE_ID(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Generate_Id", out_node);
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
CUS_WIP_GENERATE_ID()
- Main sub function of "CUS_WIP_Generate_Id" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_GENERATE_ID(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *gen_in_node;
    TRSNode **argu_list;
    TRSNode *argu_list_node;

    struct work_date_tag work_date;
    int iArg_list;
    char s_factory[10];

    LOG_head("CUS_WIP_Generate_Id");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Generate_Id_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    gen_in_node = TRS.add_node(in_node, "gen_in_node");

    //Process Step. Option for expansion ('1': Find rule id of the condition and then generate id, '2' : generate id by the input rule id)
    TRS.add_char(gen_in_node, IN_PROCSTEP, TRS.get_procstep(in_node));

    //rule id를 지정해 주기 위해 자동 step 2로 변경_20200706_lwg
    if (TRS.get_procstep(in_node) == ' ')
    {
        TRS.set_char(gen_in_node, IN_PROCSTEP, '2');
    }

    CopyDefaultMembers(gen_in_node, in_node);

    if (COM_isnullspace(TRS.get_factory(in_node)) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "KEY_FACTORY", TRS.get_factory(in_node));

    if (COM_isnullspace(TRS.get_string(in_node, "RULE_ID")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "RULE_ID", TRS.get_string(in_node, "RULE_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "MAT_ID")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "FLOW")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));

    if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "OPER"));

    if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "RES_TYPE")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "RES_TYPE", TRS.get_string(in_node, "RES_TYPE"));

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "RESG_ID")) == MP_FALSE)
        TRS.add_nstring(gen_in_node, "RESG_ID", TRS.get_string(in_node, "RESG_ID"));

    //추가 정보성 데이터
    TRS.add_nstring(gen_in_node, "REL_KEY_1", TRS.get_string(in_node, "REL_KEY_1"));
    TRS.add_nstring(gen_in_node, "REL_KEY_2", TRS.get_string(in_node, "REL_KEY_2"));
    TRS.add_nstring(gen_in_node, "REL_KEY_3", TRS.get_string(in_node, "REL_KEY_3"));
    TRS.add_nstring(gen_in_node, "REL_KEY_4", TRS.get_string(in_node, "REL_KEY_4"));
    TRS.add_nstring(gen_in_node, "REL_KEY_5", TRS.get_string(in_node, "REL_KEY_5"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "SEQ_KEY_1"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_2", TRS.get_string(in_node, "SEQ_KEY_2"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_3", TRS.get_string(in_node, "SEQ_KEY_3"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_4", TRS.get_string(in_node, "SEQ_KEY_4"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_5", TRS.get_string(in_node, "SEQ_KEY_5"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_6", TRS.get_string(in_node, "SEQ_KEY_6"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_7", TRS.get_string(in_node, "SEQ_KEY_7"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_8", TRS.get_string(in_node, "SEQ_KEY_8"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_9", TRS.get_string(in_node, "SEQ_KEY_9"));
    TRS.add_nstring(gen_in_node, "SEQ_KEY_10", TRS.get_string(in_node, "SEQ_KEY_10"));

    //DATETIME 별 SEQ 생성 GEN RULE 사용.
    if (COM_isnullspace(TRS.get_string(in_node, "DATETIME")) == MP_FALSE || COM_isnullspace(TRS.get_string(in_node, "OVR_TIME")) == MP_FALSE)
    {
        //work date 기분으로 seq를 채번하기 위해 DATETIME에 계산된 work date을 넣어주도록 수정.
        TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
        memset(&work_date, ' ', sizeof(work_date));
        Get_shift(s_factory, &work_date);

		//PO인터페이스에서 24시~ 08시 사이에 PO가내려진 경우(이럴경우 별로 없지만) 기준날짜는 전일,채번은 당일로 되면서
	    //다음 채번부터 에러 발생 01로 계속 채번 되는 오류 수정 ,일단 DLVNO 채번은 innode값 으로 처리하도록, 20211025 syw 
		if (TRS.get_string(in_node, "RULE_ID") == MP_ID_ROLE_DLV_NO) 
		{
			TRS.add_nstring(gen_in_node, "DATETIME", TRS.get_string(in_node, "DATETIME"));
			TRS.add_nstring(gen_in_node, "OVR_TIME", TRS.get_string(in_node, "OVR_TIME"));
		}
		else
		{
			TRS.add_string(gen_in_node, "DATETIME", work_date.s_work_date, sizeof(work_date.s_work_date));
			TRS.add_string(gen_in_node, "OVR_TIME", work_date.s_work_date, sizeof(work_date.s_work_date));
		}

		/*
        //TRS.add_nstring(gen_in_node, "DATETIME", TRS.get_string(in_node, "DATETIME"));
        //TRS.add_nstring(gen_in_node, "OVR_TIME", TRS.get_string(in_node, "OVR_TIME"));
        TRS.add_string(gen_in_node, "DATETIME", work_date.s_work_date, sizeof(work_date.s_work_date));
        TRS.add_string(gen_in_node, "OVR_TIME", work_date.s_work_date, sizeof(work_date.s_work_date));
		*/
    }
    
    iArg_list = TRS.get_item_count(in_node, "ARGU_LIST");
    argu_list = TRS.get_list(in_node, "ARGU_LIST");

    for (int i = 0; i < iArg_list; i++)
    {
        argu_list_node = TRS.add_node(gen_in_node, "ARGU_LIST");
        TRS.add_nstring(argu_list_node, "ARGUMENT", TRS.get_string(argu_list[i], "ARGUMENT"));
    }

    if (CUS_WIP_Generate_Id_Before_Transaction(s_msg_code, 0, gen_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_GENERATE_ID(s_msg_code, gen_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Generate_Id_After_Transaction(s_msg_code, 0, gen_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Generate_Id_Validation()
- Validation Check sub function of "CUS_WIP_GENERATE_ID" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Generate_Id_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
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

/*******************************************************************************
CUS_WIP_Generate_Id_Before_Transaction()
- Main sub function of "CUS_WIP_GENERATE_ID" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Generate_Id_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Generate_Id_After_Transaction()
- Main sub function of "CUS_WIP_GENERATE_ID" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Generate_Id_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{

    return MP_TRUE;
}