/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_merge_wip_lot.c
Description : Tran merge Wip Lot function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/12/03                 Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Merge_Wip_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Merge_Wip_Lot()
- Tran split Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Wip_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_MERGE_WIP_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Merge_Wip_Lot", out_node);
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
CUS_WIP_MERGE_LOT()
- Main sub function of "CUS_WIP_Merge_Wip_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_MERGE_WIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_MERGE;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MINVLOTISS_TAG MINVLOTISS;
    struct MINVLOTISS_TAG MINVLOTISS_MERGE;

    struct work_date_tag work_date;

    TRSNode *merge_in;
    TRSNode *cmn_out;
    TRSNode **Lot_tbl;
    TRSNode *gen_in_node;
    TRSNode *split_in;

    char s_lot_id[26];
    int i_lot_count = 0;
    int i = 0;
    char s_factory[10];
    double sSumQty = 0;

    LOG_head("CUS_WIP_Merge_Wip_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (CUS_WIP_Merge_Wip_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    gb_multi_transaction = MP_TRUE;
    memset(gs_multi_tran_key, 0x00, sizeof(gs_multi_tran_key));
    COM_generate_multi_tran_key(gs_multi_tran_key);

    memset(s_factory, ' ', sizeof(s_factory));
    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(s_factory, &work_date);

    if (TRS.get_procstep(in_node) == '1')
    {
        //모lot 조회
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

        if (DB_error_code != DB_SUCCESS)
        {
           
            strcpy(s_msg_code, "WIP-0044");   //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
            TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);
        
            return MP_FALSE;
        }
        
        if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
        {            
            strcpy(s_msg_code, "WIP-0076");
            TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST); //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);
                      
            return MP_FALSE;
        }
       
        if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
        {            
            strcpy(s_msg_code, "WIP-0059"); // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
            TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
        
        DBU_init_mwipoprdef(&MWIPOPRDEF);
        memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
        memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
        DBU_select_mwipoprdef(1, &MWIPOPRDEF);

        if (MWIPOPRDEF.INV_FLAG != 'Y')
        {
            //소비된 자재가 ERP에 올라가지 않았으면 MERGE 할 수 없다. 
            DBU_init_minvlotiss(&MINVLOTISS);
            memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
            memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            
            if (DBU_select_minvlotiss_scalar(4, &MINVLOTISS) > 0)
            {
                //WIP-0685 : 자재가 투입된 LOT은 병합 할 수 없습니다.
                strcpy(s_msg_code, "WIP-0685");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        sSumQty = MWIPLOTSTSX.QTY_1;

        //Merge
        Lot_tbl = TRS.get_list(in_node, "LOT_TBL");
        i_lot_count = TRS.get_item_count(in_node, "LOT_TBL");

        for (i = 0; i < i_lot_count; i++)
        {          
            //자lot 조회
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_MERGE);
            TRS.copy(MWIPLOTSTSX_MERGE.LOT_ID, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), Lot_tbl[i], "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_MERGE);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0044");   //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_MERGE SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
            if (MWIPLOTSTSX_MERGE.LOT_DEL_FLAG == 'Y')
            {
                strcpy(s_msg_code, "WIP-0076");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST); //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);

                return MP_FALSE;
            }

            if (MWIPLOTSTSX_MERGE.HOLD_FLAG == 'Y')
            {
                strcpy(s_msg_code, "WIP-0059"); // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);

                return MP_FALSE;
            }
            if (memcmp(MWIPLOTSTSX.MAT_ID, MWIPLOTSTSX_MERGE.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID)) != 0)
            {
                strcpy(s_msg_code, "WIP-0637");   //WIP-0637 : 품목이 다르면 Lot을 병합 할 수 없습니다.
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_MERGE MAT_ID", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
                TRS.add_fieldmsg(out_node, "MERGE_MAT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.MAT_ID), MWIPLOTSTSX_MERGE.MAT_ID);

                return MP_FALSE;
            }           
           
            if (memcmp(MWIPLOTSTSX.OPER, MWIPLOTSTSX_MERGE.OPER, sizeof(MWIPLOTSTSX.OPER)) != 0)
            {
                strcpy(s_msg_code, "WIP-0638");   //WIP-0638 : 공정이 다르면 Lot을 병합 할 수 없습니다..
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_MERGE LOT OPER", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                TRS.add_fieldmsg(out_node, "MERGE_LOT_OPER", MP_STR, sizeof(MWIPLOTSTSX_MERGE.OPER), MWIPLOTSTSX_MERGE.OPER);
           
                return MP_FALSE;
            }
            if (memcmp(MWIPLOTSTSX.LOT_STATUS, MWIPLOTSTSX_MERGE.LOT_STATUS, sizeof(MWIPLOTSTSX.LOT_STATUS)) != 0)
            {
                strcpy(s_msg_code, "WIP-0639");   //WIP-0639 : LOT 상태가 다르면 Lot을 병합 할 수 없습니다.
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_MERGE LOT_STATUS", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);
                TRS.add_fieldmsg(out_node, "LOT_STATUS", MP_STR, sizeof(MWIPLOTSTSX.LOT_STATUS), MWIPLOTSTSX.LOT_STATUS);
                TRS.add_fieldmsg(out_node, "MERGE_LOT_STATUS", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_STATUS), MWIPLOTSTSX_MERGE.LOT_STATUS);

                return MP_FALSE;
            }

            if (MWIPOPRDEF.INV_FLAG != 'Y')
            {
                //창고가 아닌경우 작업지시가 다르면 안된다.
                if (memcmp(MWIPLOTSTSX.ORDER_ID, MWIPLOTSTSX_MERGE.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
                {
                    //WIP-0684 : 작업지시가 다르면 Lot을 병합 할 수 없습니다.
                    strcpy(s_msg_code, "WIP-0684");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX_MERGE LOT_ORDER", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_MERGE.FACTORY), MWIPLOTSTSX_MERGE.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_MERGE.LOT_ID), MWIPLOTSTSX_MERGE.LOT_ID);
                    TRS.add_fieldmsg(out_node, "ORDER_ID_1", MP_STR, sizeof(MWIPLOTSTSX_MERGE.ORDER_ID), MWIPLOTSTSX_MERGE.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "ORDER_ID_2", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);

                    return MP_FALSE;
                }

                //소비된 자재가 ERP에 올라가지 않았으면 MERGE 할 수 없다. 
                DBU_init_minvlotiss(&MINVLOTISS_MERGE);
                memcpy(MINVLOTISS_MERGE.FACTORY, MWIPLOTSTSX_MERGE.FACTORY, sizeof(MWIPLOTSTSX_MERGE.FACTORY));
                memcpy(MINVLOTISS_MERGE.LOT_ID, MWIPLOTSTSX_MERGE.LOT_ID, sizeof(MWIPLOTSTSX_MERGE.LOT_ID));

                if (DBU_select_minvlotiss_scalar(4, &MINVLOTISS_MERGE) > 0)
                {
                    //WIP-0685 : 자재가 투입된 LOT은 병합 할 수 없습니다.
                    strcpy(s_msg_code, "WIP-0685");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS_MERGE.LOT_ID), MINVLOTISS_MERGE.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            //MERGE
            merge_in = TRS.add_node(in_node, "merge_in");
            TRS.add_char(merge_in, IN_PROCSTEP, '1');
            CopyDefaultMembers(merge_in, in_node);

            TRS.add_string(merge_in, "LOT_ID", MWIPLOTSTSX_MERGE.LOT_ID, sizeof(MWIPLOTSTSX_MERGE.LOT_ID));
            TRS.add_string(merge_in, "INTO_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_double(merge_in, "MOVE_QTY_1", MWIPLOTSTSX_MERGE.QTY_1);
            TRS.add_nstring(merge_in, "COMMENT", TRS.get_string(in_node,"COMMENT"));
            
            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_MERGE_LOT(s_msg_code, merge_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);     

            sSumQty = sSumQty + MWIPLOTSTSX_MERGE.QTY_1;
        }

        if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == 0 &&
            memcmp(MWIPOPRDEF.OPER_CMF_1, "W-CUT-H", strlen("W-CUT-H")) == MP_FALSE)
        {
            memset(s_lot_id, ' ', sizeof(s_lot_id));

            //공정OPTION의 ID 발번 규칙(DATA_3)에 등록된 ID 발번 규칙으로 해당 공정의 LOT ID를 채번한다.
            gen_in_node = TRS.add_node(in_node, "gen_in_node");
            TRS.add_char(gen_in_node, "PROCSTEP", '2');
            CopyDefaultMembers(gen_in_node, in_node);
            TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_COM_OPER, strlen(MP_ID_ROLE_WIP_COM_OPER));
            TRS.add_string(gen_in_node, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_string(gen_in_node, "FLOW", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            TRS.add_string(gen_in_node, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
            TRS.add_nstring(gen_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
            TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
            TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            memcpy(s_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
            TRS.free_node(cmn_out);

            //자 LOT ID 채번
            split_in = TRS.add_node(in_node, "split_in");
            CopyDefaultMembers(split_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

            TRS.add_char(split_in, "PROCSTEP", '1');
            TRS.add_string(split_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(split_in, "CHILD_LOT_ID", s_lot_id, sizeof(s_lot_id));
            TRS.add_string(split_in, "CHILD_LOT_DESC", s_lot_id, sizeof(s_lot_id));
            TRS.add_double(split_in, "MOVE_QTY_1", sSumQty); // QTY_1 유효중량
            TRS.add_nstring(split_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
            TRS.add_double(split_in, "PRE_QTY_1", sSumQty);   //split 전 모랏의 총 수량
            TRS.add_string(split_in, "RESV_FIELD_3", MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTSTSX.RESV_FIELD_3));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_SPLIT_LOT(s_msg_code, split_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);

            //새로 생긴 lot을 담아준다.
            TRS.add_string(out_node, "LOT_ID", s_lot_id, sizeof(s_lot_id));
        }
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Merge_Wip_Lot_Validation()
- Validation Check sub function of "CUS_WIP_MERGE_WIP_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Merge_Wip_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    // PROCSTEP VALIDATION
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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
    // LOT ID VALIDATION
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        return MP_FALSE;
    }

    return MP_TRUE;
}