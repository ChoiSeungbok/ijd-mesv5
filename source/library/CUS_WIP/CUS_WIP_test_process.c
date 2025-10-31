/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_test_process.c
Description : TEST 프로세스

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/06  Miracom        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_TEST_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Test_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Test_Process()
- 프로그램 테스트
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Test_Process(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_TEST_PROCESS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Test_Process", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

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
CUS_WIP_TEST_PROCESS()
- Main sub function of "CUS_WIP_Test_Process" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_TEST_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    //struct MWIPLOTSTS_TAG MWIPLOTSTS;
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct CWIPLOTREC_TAG CWIPLOTREC;

    TRSNode     *gen_in_node;
    TRSNode     *create_in;
    TRSNode     *start_in;
    TRSNode     *end_in;  
    TRSNode     *terminate_in;
    TRSNode     *cmn_out;

    TRSNode     **lot_list;
    int i_lot_count = 0;
    char s_lot_id[26];

    LOG_head("CUS_WIP_Test_Process");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    //멀티 트랜잭션 키 생성. 
    //gb_multi_transaction = MP_TRUE;
    //memset(gs_multi_tran_key, 0x00, sizeof(gs_multi_tran_key));
    //COM_generate_multi_tran_key(gs_multi_tran_key);

    /* Validation Check */
    if (CUS_WIP_Test_Process_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) != '4')
    {
        //작업지시 조회
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0002 : 이 ORDER는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0002");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        i_lot_count = TRS.get_int(in_node, "CREATE_COUNT");

        for (int i = 0; i < i_lot_count; i++)
        {
            memset(s_lot_id, ' ', sizeof(s_lot_id));

            gen_in_node = TRS.add_node(in_node, "gen_in_node");

            //LOT ID 발번            
            CopyDefaultMembers(gen_in_node, in_node);
            TRS.add_string(gen_in_node, "RULE_ID", "TEST_LOT_ID", strlen("TEST_LOT_ID"));            
            TRS.add_char(gen_in_node, "PROCSTEP", '2');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
            TRS.free_node(cmn_out);

            //create
            create_in = TRS.add_node(in_node, "create_in");
            TRS.add_char(create_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(create_in, in_node);

            TRS.add_string(create_in, "LOT_ID", s_lot_id, sizeof(s_lot_id));
            TRS.add_string(create_in, "LOT_DESC", s_lot_id, sizeof(s_lot_id));           
            TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));   //TDIA001
            TRS.add_int(create_in, "MAT_VER", 1);
            TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
            TRS.add_string(create_in, "OWNER_CODE", "PROD", strlen("PROD"));
            TRS.add_char(create_in, "LOT_PRIORITY", '5');
            TRS.add_char(create_in, "LOT_TYPE", MP_LOT_TYPE_TEST);
            TRS.add_string(create_in, "CREATE_CODE", "TEST", strlen("TEST"));
            TRS.add_double(create_in, "QTY_1", TRS.get_double(in_node, "CREATE_QTY"));
            TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
            TRS.add_string(create_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            TRS.add_char(create_in, "CLASS_OPER_SKIP", 'Y');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
    }
    //작업시작
    else if (TRS.get_procstep(in_node) == '2')
    {    
        lot_list = TRS.get_list(in_node, "LOT_LIST");
        i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

        for (int i = 0; i < i_lot_count; i++)
        {
            //LOT 시작
            start_in = TRS.add_node(in_node, "start_in");
            TRS.add_char(start_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(start_in, in_node);

            TRS.add_nstring(start_in, "LOT_ID", TRS.get_string(lot_list[i],"LOT_ID"));
            TRS.add_nstring(start_in, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
            TRS.add_nstring(start_in, "OPER", TRS.get_string(in_node, "OPER"));           
            TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            //TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_char(start_in, "CLASS_OPER_SKIP", 'Y');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
    }
    //작업 완료
    else if (TRS.get_procstep(in_node) == '3')
    {
        lot_list = TRS.get_list(in_node, "LOT_LIST");
        i_lot_count = TRS.get_item_count(in_node, "LOT_LIST");

        for (int i = 0; i < i_lot_count; i++)
        {
            //LOT 완료
            end_in = TRS.add_node(in_node, "end_in");
            TRS.add_char(end_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(end_in, in_node);

            TRS.add_nstring(end_in, "LOT_ID", TRS.get_string(lot_list[i], "LOT_ID"));
            TRS.add_nstring(end_in, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
            TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_string(end_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.add_char(end_in, "CLASS_OPER_SKIP", 'Y');

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);
        }
    }

    //terminate
    else if (TRS.get_procstep(in_node) == '4')    
    {
        terminate_in = TRS.add_node(in_node, "teminate_in");
        TRS.add_char(terminate_in, IN_PROCSTEP, '1');
        CopyDefaultMembers(terminate_in, in_node);

        TRS.add_nstring(terminate_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

        if (COM_isnullspace(TRS.get_string(in_node, "COMMENT")) == MP_FALSE)
        {
            TRS.add_nstring(terminate_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
        }
        else
        {
            TRS.add_string(terminate_in, "COMMENT", MP_CINV_TRAN_CODE_TERMINATE, strlen(MP_CINV_TRAN_CODE_TERMINATE));
        }

        cmn_out = TRS.create_node("Cmn_Out");
        if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);

        DBU_init_cwiplotrec(&CWIPLOTREC);
        TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), in_node, "LOT_ID");

        if (DBU_select_cwiplotrec_scalar(2, &CWIPLOTREC) > 0)
        {
            TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));

            DBU_update_cwiplotrec(5, &CWIPLOTREC);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Test_Process_Validation()
- Validation Check sub function of "CUS_WIP_TEST_PROCESS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Test_Process_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1234") == MP_FALSE)
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
