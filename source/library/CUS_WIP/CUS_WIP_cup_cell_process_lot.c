/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_cup_cell_process_lot.c
Description : cup cell 조립 프로세스

MES Version : 5.0

Function List
- step 1 : 작업시작
- step 2 : 작업완료

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/27  wg.lee        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_Cup_Cell_Process_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_CUP_CELL_PROCESS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Cup_Cell_Process_Lot()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cup_Cell_Process_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_CUP_CELL_PROCESS_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Cup_Cell_Process_Lot", out_node);
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
CUS_WIP_CUP_CELL_PROCESS_LOT()
- Main sub function of "CUS_WIP_Cup_Cell_Process_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CUP_CELL_PROCESS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	    //LOT 마스터
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_AF;	//LOT 마스터
    struct MWIPORDSTS_TAG MWIPORDSTS;       //작업지시 마스터
    struct MWIPOPRDEF_TAG MWIPOPRDEF;       //공정 마스터
    //struct MWIPOPRDEF_TAG MWIPOPRDEF_AF;    //공정 마스터
    struct CWIPOPRWRK_TAG CWIPOPRWRK;       //공정 작업자
    struct MWIPMATDEF_TAG MWIPMATDEF;       //제품 마스터
    struct CWIPGRPSTS_TAG CWIPGRPSTS;       //그룹 마스터 테이블    
    struct CWIPGRPLOT_TAG CWIPGRPLOT;       //그룹 LOT 테이블
    
    struct work_date_tag work_date;
    TRSNode *gen_in_node;
    TRSNode *cmn_out;
    TRSNode *start_in;
    TRSNode *end_in;
    TRSNode *loss_in;
    TRSNode *unit_in;
    TRSNode *inv_in;
	TRSNode *create_in;
	TRSNode *list_in;
	TRSNode *mat_in;

    //TRSNode *if_in;
    //TRSNode *if_end_in;
    TRSNode *list_item;

    //TRSNode *argu_list_node;
    TRSNode **Lot_tbl;
    TRSNode **Worker_tbl;

    char s_factory[10];
    int i_mapping_count = 0;
    int i_lot_count = 0;
    int i_worker_count = 0;
    char s_group_id[26];
    char c_CheckErpInput;           //ERP 완료이력 여부
    char c_CheckErpResult;          //ERP에 생산이력 여부

    // LOG
    LOG_head("CUS_WIP_Cup_Cell_Process_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    memset(s_factory, ' ', sizeof(s_factory));
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(s_factory, &work_date);

    // VALIDATION CHECK
    if (CUS_WIP_Cup_Cell_Process_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //멀티 트랜잭션 키 생성. 
    gb_multi_transaction = MP_TRUE;
    memset(gs_multi_tran_key, 0x00, sizeof(gs_multi_tran_key));
    COM_generate_multi_tran_key(gs_multi_tran_key);

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

    //완료 또는 삭제된 작업지시는 진행 할 수 없음
    if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_FINISH
        || MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_DELETE)
    {
        //ORD-0024 : 선택한 Order는 이미 삭제되었습니다.
        strcpy(s_msg_code, "ORD-0024");
        TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    //공정 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0010 : 이 공정은 존재 하지 않습니다.
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //step 1 : 작업시작
    if (TRS.get_procstep(in_node) == '1')
    {
        i_mapping_count = 0;

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int i = 0; i < i_lot_count; i++)
        {
            i_mapping_count++;

            if (i_mapping_count == 1)
            {
                memset(s_group_id, ' ', sizeof(s_group_id));

                DBU_init_cwipgrpsts(&CWIPGRPSTS);
                TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), Lot_tbl[i], "GROUP_ID");
                DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
                if (DB_error_code == DB_SUCCESS)
                {
                    memcpy(s_group_id, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID));
                    s_group_id[25] = 0x00;
                }
                else if (DB_error_code == DB_NOT_FOUND)
                {
                    //그룹ID를 채번한다.   
                    gen_in_node = TRS.add_node(in_node, "gen_in_node");
                    TRS.add_char(gen_in_node, "PROCSTEP", '2');
                    CopyDefaultMembers(gen_in_node, in_node);

                    if (memcmp(MWIPOPRDEF.FACTORY, "IJDK1", strlen("IJDK1")) == 0)
                    {
                        TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_GROUP_ID, strlen(MP_ID_ROLE_WIP_GROUP_ID));
                    }
                    else {
                        TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_CTV_CELL_NO, strlen(MP_ID_ROLE_CTV_CELL_NO));
                        TRS.add_string(gen_in_node, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
                      //  TRS.add_nstring(gen_in_node, "MAT_ID", TRS.get_string(Lot_tbl[i], "MAT_ID"));

                    }

                    TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_GROUP_ID, strlen(MP_ID_ROLE_WIP_GROUP_ID));
                    TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
                    TRS.add_nstring(gen_in_node, "OPER", TRS.get_string(in_node, "GROUP_TYPE"));
                    TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
                    TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
                    TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

                    cmn_out = TRS.create_node("Cmn_Out");
                    if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
                    {
                        TRS.clone(out_node, cmn_out);
                        TRS.free_node(cmn_out);
                        return MP_FALSE;
                    }
                    memcpy(s_group_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
                    TRS.free_node(cmn_out);
                }

                //CWIPGRPSTS 그룹 마스터 테이블 저장.
                memcpy(CWIPGRPSTS.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS.GROUP_ID));
                TRS.copy(CWIPGRPSTS.GROUP_TYPE, sizeof(CWIPGRPSTS.GROUP_TYPE), in_node, "GROUP_TYPE");

                if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
                {
                    TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "PRESS_RES_ID");
                    TRS.copy(CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR), in_node, "CAR");
                    CWIPGRPSTS.CELL_HEIGHT = TRS.get_double(Lot_tbl[i], "CELL_HEIGHT");
                    CWIPGRPSTS.CELL_WEIGHT = TRS.get_double(Lot_tbl[i], "CELL_WEIGHT");
                }
				
				memcpy(CWIPGRPSTS.CMF_1, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                TRS.copy(CWIPGRPSTS.CREATE_USER_ID, sizeof(CWIPGRPSTS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRPSTS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.CREATE_TIME));
                TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
                DBU_insert_cwipgrpsts(&CWIPGRPSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
                    TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                    TRS.add_fieldmsg(out_node, "GROUP_TYPE", MP_STR, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
           
            //lot 정보 조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
            {
                //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
                strcpy(s_msg_code, "WIP-0647");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //MWIPLOTSTSX에 맵핑 순서 저장.
            memcpy(MWIPLOTSTSX.LOT_CMF_1, s_group_id, sizeof(s_group_id));
            COM_itoa_left(MWIPLOTSTSX.LOT_CMF_2, i_mapping_count, sizeof(MWIPLOTSTSX.LOT_CMF_2));



            DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        
            if (memcmp(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID)) != MP_FALSE)
            {
                //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
                strcpy(s_msg_code, "WIP-0647");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //lot 작업시작
            start_in = TRS.add_node(in_node, "start_in");
            TRS.add_char(start_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(start_in, in_node);

            TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_nstring(start_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            //TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			TRS.add_nstring(start_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));


            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);





            if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_D12, strlen(MP_MAPPING_GROUP_D12)) == MP_FALSE)
            {
                //CWIPGRPSTS 그룹 마스터 테이블 저장.
                DBU_init_cwipgrplot(&CWIPGRPLOT);
                memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                memcpy(CWIPGRPLOT.GROUP_ID, s_group_id, sizeof(CWIPGRPLOT.GROUP_ID));
                memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                CWIPGRPLOT.MAPPING_SEQ = TRS.get_int(Lot_tbl[i], "MAPPING_SEQ");
                memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                memcpy(CWIPGRPLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));
                TRS.copy(CWIPGRPLOT.UPDATE_USER_ID, sizeof(CWIPGRPLOT.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRPLOT.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.UPDATE_TIME));
                DBU_insert_cwipgrplot(&CWIPGRPLOT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPGRPLOT INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
                    TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }            
            else if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
            {            
                //CWIPGRPSTS 그룹 마스터 테이블 저장.
                DBU_init_cwipgrplot(&CWIPGRPLOT);
                TRS.copy(CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT.FACTORY), in_node, IN_FACTORY);               
                memcpy(CWIPGRPLOT.GROUP_ID, s_group_id, sizeof(CWIPGRPLOT.GROUP_ID));              
                TRS.copy(CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID), Lot_tbl[i], "D12_ID");
                DBU_select_cwipgrplot(1, &CWIPGRPLOT);
                if (DB_error_code != DB_SUCCESS)
                {
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        //CWIPGRPLOT.MAPPING_SEQ = (int)DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT) + 1;
                        CWIPGRPLOT.MAPPING_SEQ = TRS.get_int(Lot_tbl[i], "MAPPING_SEQ");
                        memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                        memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                        memcpy(CWIPGRPLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                        TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
                        memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));
                        TRS.copy(CWIPGRPLOT.UPDATE_USER_ID, sizeof(CWIPGRPLOT.UPDATE_USER_ID), in_node, IN_USERID);
                        memcpy(CWIPGRPLOT.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.UPDATE_TIME));
                        DBU_insert_cwipgrplot(&CWIPGRPLOT);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                            strcpy(s_msg_code, "ADM-0004");
                            TRS.add_fieldmsg(out_node, "CWIPGRPLOT INSERT", DT_NOVALUESTRING);
                            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
                            TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
                            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            return MP_FALSE;
                        }
                    }
                }
            }

            if (i_mapping_count == TRS.get_int(in_node, "MAPPING_COUNT"))
                i_mapping_count = 0;
        }
    }
    //step 1 : 작업완료
    else if (TRS.get_procstep(in_node) == '2')
    {
        c_CheckErpResult = ' ';
        c_CheckErpInput = ' ';

        //ERP에 생산 이력 및 완료 이력 여부를 리턴 받아오는 함수
        if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (int i = 0; i < i_lot_count; i++)
        {          
            DBU_init_cwipgrpsts(&CWIPGRPSTS);
            TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), Lot_tbl[i], "GROUP_ID");
            DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "CWIPGRPSTS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //lot 정보 조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX);
            TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
            {
                //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
                strcpy(s_msg_code, "WIP-0647");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //group id 의 seq가 1번인 lot일때만 group id를 out_node에 추가해 준다. 
            //1개의 group id 만 저장하기 위해
            if (MWIPLOTSTSX.LOT_CMF_2[0] == '1')
            {
                list_item = TRS.add_node(out_node, "LOT_TBL");
                TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
            }

            if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
            {
                if (MWIPLOTSTSX.LOT_CMF_2[0] == '1')
                {
                    TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "PRESS_RES_ID");
                    TRS.copy(CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR), in_node, "CAR");
                    CWIPGRPSTS.CELL_HEIGHT = TRS.get_double(Lot_tbl[i], "CELL_HEIGHT");
                    CWIPGRPSTS.CELL_WEIGHT = TRS.get_double(Lot_tbl[i], "CELL_WEIGHT");
                    TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
                    memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
                    DBU_update_cwipgrpsts(1, &CWIPGRPSTS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
                        TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }
            }

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //자재 차감 => 공정lot cv처리 완료, 자재lot cv 처리 추가 할 것.
            inv_in = TRS.add_node(in_node, "inv_in");
            CopyDefaultMembers(inv_in, in_node);

            TRS.add_char(inv_in, IN_PROCSTEP, '1');
            TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_nstring(inv_in, "OPER", TRS.get_string(in_node, "OPER"));
            TRS.add_nstring(inv_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
            TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

            if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
                return MP_FALSE;

            //if (INPUT_INV_LOT(s_msg_code, inv_in, out_node) == MP_FALSE)
            //    return MP_FALSE;

               
            if (COM_isnullspace(TRS.get_string(Lot_tbl[i], "LOSS_CODE")) == MP_FALSE)
            {
                loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
                CopyDefaultMembers(loss_in, in_node);
                TRS.add_char(loss_in, IN_PROCSTEP, '1');

                TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

                if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
                    TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                else
                    TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

                TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_double(loss_in, "OUT_QTY_1", 0);

                unit_in = TRS.add_node(loss_in, "UNIT1");
                TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(Lot_tbl[i], "LOSS_CODE"));
                TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX.QTY_1);

                TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
                TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));





                if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
                    return MP_FALSE;
            }
            else
            {
                //LOT 완료
                end_in = TRS.add_node(in_node, "end_in");
                TRS.add_char(end_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(end_in, in_node);

                TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
                TRS.add_nstring(end_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
				TRS.add_nstring(end_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));


                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }

            //LOT정보 재조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
            memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

            //작업자 저장
            Worker_tbl = TRS.get_list(in_node, "WORKER_TBL");
            i_worker_count = TRS.get_item_count(in_node, "WORKER_TBL");

            for (int k = 0; k < i_worker_count; k++)
            {
                DBU_init_cwipoprwrk(&CWIPOPRWRK);
                TRS.copy(CWIPOPRWRK.FACTORY, sizeof(CWIPOPRWRK.FACTORY), in_node, IN_FACTORY);
                TRS.copy(CWIPOPRWRK.OPER, sizeof(CWIPOPRWRK.OPER), in_node, "OPER");
                memcpy(CWIPOPRWRK.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                CWIPOPRWRK.HIST_SEQ = MWIPLOTSTSX_AF.LAST_HIST_SEQ;
                TRS.copy(CWIPOPRWRK.WORKER_ID, sizeof(CWIPOPRWRK.OPER), Worker_tbl[k], "WORKER_ID");

                memcpy(CWIPOPRWRK.START_TIME, MWIPLOTSTSX.START_TIME, sizeof(CWIPOPRWRK.START_TIME));
                memcpy(CWIPOPRWRK.END_TIME, MWIPLOTSTSX_AF.END_TIME, sizeof(CWIPOPRWRK.END_TIME));
                memcpy(CWIPOPRWRK.CREATE_TIME, gs_sys_time, sizeof(CWIPOPRWRK.CREATE_TIME));
                TRS.copy(CWIPOPRWRK.CREATE_USER_ID, sizeof(CWIPOPRWRK.CREATE_USER_ID), in_node, IN_USERID);

                DBU_insert_cwipoprwrk(&CWIPOPRWRK);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPOPRWRK INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPOPRWRK.FACTORY), CWIPOPRWRK.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPOPRWRK.OPER), CWIPOPRWRK.OPER);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPOPRWRK.LOT_ID), CWIPOPRWRK.LOT_ID);
                    TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPOPRWRK.WORKER_ID), CWIPOPRWRK.WORKER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
        }
    }
	//step 3 : 작업시작(CTV 셀조립)
	else if (TRS.get_procstep(in_node) == '3')
	{
		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
		i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

		for (int i = 0; i < i_lot_count; i++)
		{


			memset(s_group_id, ' ', sizeof(s_group_id));

			DBU_init_cwipgrpsts(&CWIPGRPSTS);
			TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), Lot_tbl[i], "GROUP_ID");
			DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				memcpy(s_group_id, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID));
				s_group_id[25] = 0x00;
			}
			else if (DB_error_code == DB_NOT_FOUND)
			{

				memcpy(s_group_id, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID));
				s_group_id[25] = 0x00;


				//CWIPGRPSTS 그룹 마스터 테이블 저장.
				memcpy(CWIPGRPSTS.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS.GROUP_ID));
				TRS.copy(CWIPGRPSTS.GROUP_TYPE, sizeof(CWIPGRPSTS.GROUP_TYPE), in_node, "GROUP_TYPE");

				if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
				{
					TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "PRESS_RES_ID");
					TRS.copy(CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR), in_node, "CAR");
					CWIPGRPSTS.CELL_HEIGHT = TRS.get_double(Lot_tbl[i], "CELL_HEIGHT");
					CWIPGRPSTS.CELL_WEIGHT = TRS.get_double(Lot_tbl[i], "CELL_WEIGHT");
				}

				memcpy(CWIPGRPSTS.CMF_1, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				TRS.copy(CWIPGRPSTS.CREATE_USER_ID, sizeof(CWIPGRPSTS.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPGRPSTS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.CREATE_TIME));
				TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
				DBU_insert_cwipgrpsts(&CWIPGRPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
					TRS.add_fieldmsg(out_node, "GROUP_TYPE", MP_STR, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

			}


			//LOT ID 생성 
			create_in = TRS.add_node(in_node, "create_in");
			TRS.add_char(create_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(create_in, in_node);




			TRS.add_nstring(create_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));
			TRS.add_string(create_in, "MAT_ID", MWIPORDSTS.MAT_ID, sizeof(MWIPORDSTS.MAT_ID));
			TRS.add_int(create_in, "MAT_VER", 1);

			TRS.add_nstring(create_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(create_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			TRS.add_int(create_in, "FLOW_SEQ_NUM", 1);
			TRS.add_string(create_in, "OWNER_CODE", MWIPORDSTS.OWNER_CODE, sizeof(MWIPORDSTS.OWNER_CODE));
			TRS.add_char(create_in, "LOT_PRIORITY", MWIPORDSTS.LOT_PRIORITY);
			TRS.add_char(create_in, "LOT_TYPE", MWIPORDSTS.LOT_TYPE);
			TRS.add_string(create_in, "CREATE_CODE", MWIPORDSTS.CREATE_CODE, sizeof(MWIPORDSTS.CREATE_CODE));
			TRS.add_double(create_in, "QTY_1", TRS.get_double(Lot_tbl[i], "QTY_1"));
			TRS.set_nstring(create_in, "USER_ID", TRS.get_string(in_node, IN_USERID));
			TRS.add_nstring(create_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));


			cmn_out = TRS.create_node("Cmn_Out");

			if (CUS_WIP_CREATE_LOT(s_msg_code, create_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);



			//lot 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
			{
				//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
				strcpy(s_msg_code, "WIP-0647");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}



			//MWIPLOTSTSX에 맵핑 순서 저장.
			memcpy(MWIPLOTSTSX.LOT_CMF_1, s_group_id, sizeof(s_group_id));
			i_mapping_count = TRS.get_int(Lot_tbl[i], "MAPPING_SEQ");

			COM_itoa_left(MWIPLOTSTSX.LOT_CMF_2, i_mapping_count, sizeof(MWIPLOTSTSX.LOT_CMF_2));

			CWIPGRPLOT.MAPPING_SEQ = TRS.get_int(Lot_tbl[i], "MAPPING_SEQ");


			DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			if (memcmp(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID)) != MP_FALSE)
			{
				//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
				strcpy(s_msg_code, "WIP-0647");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			//lot 작업시작
			start_in = TRS.add_node(in_node, "start_in");
			TRS.add_char(start_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(start_in, in_node);

			TRS.add_string(start_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(start_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			TRS.add_nstring(start_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_string(start_in, "FLOW", MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
			//TRS.add_nstring(start_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_string(start_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_START_LOT(s_msg_code, start_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			//CWIPGRPSTS 그룹 마스터 테이블 저장.
			DBU_init_cwipgrplot(&CWIPGRPLOT);
			memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(CWIPGRPLOT.GROUP_ID, s_group_id, sizeof(CWIPGRPLOT.GROUP_ID));
			memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			CWIPGRPLOT.MAPPING_SEQ = TRS.get_int(Lot_tbl[i], "MAPPING_SEQ");
			memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			memcpy(CWIPGRPLOT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));
			TRS.copy(CWIPGRPLOT.UPDATE_USER_ID, sizeof(CWIPGRPLOT.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPGRPLOT.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.UPDATE_TIME));
			DBU_insert_cwipgrplot(&CWIPGRPLOT);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPGRPLOT INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}


            if (TRS.get_char(in_node, "INPUT_BOM") == 'Y') {

                //자동으로 자재 투입 처리를 해준다. 
                //자재 투입 서비스 호출. 
                mat_in = TRS.add_node(in_node, "mat_in");
                TRS.add_char(mat_in, IN_PROCSTEP, '4');
                CopyDefaultMembers(mat_in, in_node);


                TRS.add_nstring(mat_in, "AREA_ID", TRS.get_string(in_node, "AREA_ID"));
                TRS.add_string(mat_in, "SUB_AREA_ID", MWIPORDSTS.ORD_CMF_2, sizeof(MWIPORDSTS.ORD_CMF_2));
                TRS.add_string(mat_in, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                TRS.add_nstring(mat_in, "OPER", TRS.get_string(in_node, "OPER"));
                TRS.add_nstring(mat_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "LOT_ID"));
                TRS.add_char(mat_in, "REL_LEVEL", '1');


                list_in = TRS.add_node(mat_in, "LIST_TBL");
                TRS.add_nstring(list_in, "LOT_ID", TRS.get_string(Lot_tbl[i], "GROUP_ID"));
                TRS.add_nstring(list_in, "MAT_ID", TRS.get_string(Lot_tbl[i], "MAT_ID"));
                TRS.add_nstring(list_in, "LOT_TYPE", TRS.get_string(Lot_tbl[i], "LOT_TYPE"));

                TRS.add_nstring(list_in, "INPUT_TYPE", TRS.get_string(Lot_tbl[i], "INPUT_TYPE"));
                TRS.add_nstring(list_in, "OUT_OPER", TRS.get_string(Lot_tbl[i], "OUT_OPER"));
                TRS.add_double(list_in, "QTY", TRS.get_double(Lot_tbl[i], "QTY_1"));
                TRS.add_double(list_in, "BOM_QTY", TRS.get_double(Lot_tbl[i], "BOM_QTY"));


                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, mat_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }



		}
	}
	//step 4 : 작업완료(CTV 셀조립
	else if (TRS.get_procstep(in_node) == '4')
	{
		c_CheckErpResult = ' ';
		c_CheckErpInput = ' ';

		//ERP에 생산 이력 및 완료 이력 여부를 리턴 받아오는 함수
		if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, in_node, out_node) == MP_FALSE)
			return MP_FALSE;

		Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
		i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

		for (int i = 0; i < i_lot_count; i++)
		{
			DBU_init_cwipgrpsts(&CWIPGRPSTS);
			TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), Lot_tbl[i], "GROUP_ID");
			DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "CWIPGRPSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//lot 정보 조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), Lot_tbl[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
				strcpy(s_msg_code, "WIP-0044");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
			{
				//WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
				strcpy(s_msg_code, "WIP-0647");
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//group id 의 seq가 1번인 lot일때만 group id를 out_node에 추가해 준다. 
			//1개의 group id 만 저장하기 위해
			if (MWIPLOTSTSX.LOT_CMF_2[0] == '1')
			{
				list_item = TRS.add_node(out_node, "LOT_TBL");
				TRS.add_string(list_item, "GROUP_ID", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
			}

			if (memcmp(TRS.get_string(in_node, "GROUP_TYPE"), MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
			{
				if (MWIPLOTSTSX.LOT_CMF_2[0] == '1')
				{
					TRS.copy(CWIPGRPSTS.RES_ID, sizeof(CWIPGRPSTS.RES_ID), in_node, "PRESS_RES_ID");
					TRS.copy(CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR), in_node, "CAR");
					CWIPGRPSTS.CELL_HEIGHT = TRS.get_double(Lot_tbl[i], "CELL_HEIGHT");
					CWIPGRPSTS.CELL_WEIGHT = TRS.get_double(Lot_tbl[i], "CELL_WEIGHT");
					TRS.copy(CWIPGRPSTS.UPDATE_USER_ID, sizeof(CWIPGRPSTS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPGRPSTS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.UPDATE_TIME));
					DBU_update_cwipgrpsts(1, &CWIPGRPSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}

			//자재 정보 조회
			DBU_init_mwipmatdef(&MWIPMATDEF);
			memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
			memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);

			//자재 차감 => 공정lot cv처리 완료, 자재lot cv 처리 추가 할 것.
			inv_in = TRS.add_node(in_node, "inv_in");
			CopyDefaultMembers(inv_in, in_node);

			TRS.add_char(inv_in, IN_PROCSTEP, '1');
			TRS.add_string(inv_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_nstring(inv_in, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_nstring(inv_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
			TRS.add_nstring(inv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			TRS.add_nstring(inv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));

			if (INPUT_INV_LOT_BY_LEVEL(s_msg_code, inv_in, out_node) == MP_FALSE)
				return MP_FALSE;

			//if (INPUT_INV_LOT(s_msg_code, inv_in, out_node) == MP_FALSE)
			//    return MP_FALSE;


			if (COM_isnullspace(TRS.get_string(Lot_tbl[i], "LOSS_CODE")) == MP_FALSE)
			{
				loss_in = TRS.add_node(in_node, "Wip_Lot_Loss");
				CopyDefaultMembers(loss_in, in_node);
				TRS.add_char(loss_in, IN_PROCSTEP, '1');

				TRS.add_string(loss_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(loss_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
				TRS.add_string(loss_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
				TRS.add_string(loss_in, "CAUSE_OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));

				if (COM_isnullspace(TRS.get_string(in_node, "CAUSE_FLOW")) == MP_TRUE)
					TRS.add_string(loss_in, "CAUSE_FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				else
					TRS.add_nstring(loss_in, "CAUSE_FLOW", TRS.get_string(in_node, "CAUSE_FLOW"));

				TRS.add_nstring(loss_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				TRS.add_double(loss_in, "OUT_QTY_1", 0);

				unit_in = TRS.add_node(loss_in, "UNIT1");
				TRS.add_nstring(unit_in, "LOSS_CODE", TRS.get_string(Lot_tbl[i], "LOSS_CODE"));
				TRS.add_double(unit_in, "LOSS_QTY", MWIPLOTSTSX.QTY_1);

				TRS.add_nstring(loss_in, "LOSS_COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
				TRS.add_nstring(loss_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));

				if (CUS_WIP_LOSS_LOT(s_msg_code, loss_in, out_node) == MP_FALSE)
					return MP_FALSE;
			}
			else
			{
				//LOT 완료
				end_in = TRS.add_node(in_node, "end_in");
				TRS.add_char(end_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(end_in, in_node);

				TRS.add_string(end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(end_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
				TRS.add_nstring(end_in, "OPER", TRS.get_string(in_node, "OPER"));
				TRS.add_string(end_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
				TRS.add_nstring(end_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
				TRS.add_nstring(end_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
				TRS.add_nstring(end_in, "COMMENT", TRS.get_string(Lot_tbl[i], "COMMENT"));
				


				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_END_LOT(s_msg_code, end_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

			//LOT정보 재조회
			DBU_init_mwiplotstsx(&MWIPLOTSTSX_AF);
			memcpy(MWIPLOTSTSX_AF.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX_AF.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_AF);

			//작업자 저장
			Worker_tbl = TRS.get_list(in_node, "WORKER_TBL");
			i_worker_count = TRS.get_item_count(in_node, "WORKER_TBL");

			for (int k = 0; k < i_worker_count; k++)
			{
				DBU_init_cwipoprwrk(&CWIPOPRWRK);
				TRS.copy(CWIPOPRWRK.FACTORY, sizeof(CWIPOPRWRK.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPOPRWRK.OPER, sizeof(CWIPOPRWRK.OPER), in_node, "OPER");
				memcpy(CWIPOPRWRK.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				CWIPOPRWRK.HIST_SEQ = MWIPLOTSTSX_AF.LAST_HIST_SEQ;
				TRS.copy(CWIPOPRWRK.WORKER_ID, sizeof(CWIPOPRWRK.OPER), Worker_tbl[k], "WORKER_ID");

				memcpy(CWIPOPRWRK.START_TIME, MWIPLOTSTSX.START_TIME, sizeof(CWIPOPRWRK.START_TIME));
				memcpy(CWIPOPRWRK.END_TIME, MWIPLOTSTSX_AF.END_TIME, sizeof(CWIPOPRWRK.END_TIME));
				memcpy(CWIPOPRWRK.CREATE_TIME, gs_sys_time, sizeof(CWIPOPRWRK.CREATE_TIME));
				TRS.copy(CWIPOPRWRK.CREATE_USER_ID, sizeof(CWIPOPRWRK.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cwipoprwrk(&CWIPOPRWRK);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPOPRWRK INSERT", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPOPRWRK.FACTORY), CWIPOPRWRK.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPOPRWRK.OPER), CWIPOPRWRK.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPOPRWRK.LOT_ID), CWIPOPRWRK.LOT_ID);
					TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPOPRWRK.WORKER_ID), CWIPOPRWRK.WORKER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}
		}
	}
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Cup_Cell_Process_Lot_Validation()
- Validation Check sub function of "CUS_WIP_CUP_CELL_PROCESS_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Cup_Cell_Process_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1234") == MP_FALSE)
    {
        return MP_FALSE;
    }

    // FACTORY VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }
    // ORDER ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }


    return MP_TRUE;
}
