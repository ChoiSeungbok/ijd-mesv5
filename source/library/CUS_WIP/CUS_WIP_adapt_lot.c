/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_adapt_lot.c
Description : Tran adapt Lot function

MES Version : 5.0

Function List


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/03  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Adapt_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Adapt_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Adapt_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Adapt_Lot()
- Tran adapt Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Adapt_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_ADAPT_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Adapt_Lot", out_node);
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
CUS_WIP_ADAPT_LOT()
- Main sub function of "CUS_WIP_Adapt_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_ADAPT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;	    //LOT 마스터

    TRSNode *adapt_in_node;
    struct work_date_tag work_date;
    char s_factory[10];
    int i = 0;
    int j = 0;
    char s_member[4][101] = {"CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
    char s_member_name[101];

    LOG_head("CUS_WIP_Adapt_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Adapt_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);
                                        //lot 정보 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    //adapt 시작
    adapt_in_node = TRS.add_node(in_node, "adapt_in_node");

    TRS.add_char(adapt_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(adapt_in_node, in_node);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(adapt_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(adapt_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_nstring(adapt_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(adapt_in_node, "LOT_DESC", TRS.get_string(in_node, "LOT_DESC"));
    TRS.add_nstring(adapt_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_nstring(adapt_in_node, "TO_MAT_ID", TRS.get_string(in_node, "TO_MAT_ID"));
    TRS.add_int(adapt_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
    TRS.add_int(adapt_in_node, "TO_MAT_VER", TRS.get_int(in_node, "TO_MAT_VER"));
    TRS.add_nstring(adapt_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
    TRS.add_nstring(adapt_in_node, "OPER", TRS.get_string(in_node, "OPER"));   
    TRS.add_nstring(adapt_in_node, "TO_FLOW", TRS.get_string(in_node, "TO_FLOW"));
    TRS.add_nstring(adapt_in_node, "TO_OPER", TRS.get_string(in_node, "TO_OPER"));
    TRS.add_nstring(adapt_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(adapt_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
    TRS.add_char(adapt_in_node, "LOT_PRIORITY", TRS.get_char(in_node, "LOT_PRIORITY"));
    TRS.add_nstring(adapt_in_node, "CREATE_CODE", TRS.get_string(in_node, "CREATE_CODE"));
    TRS.add_nstring(adapt_in_node, "OWNER_CODE", TRS.get_string(in_node, "OWNER_CODE"));

    //추가 정보성 데이터



    if (TRS.get_double(in_node, "QTY_1") != 0)
    {
        TRS.set_double(adapt_in_node, "QTY_1", TRS.get_double(in_node, "QTY_1"));
    }


    
    TRS.add_char(adapt_in_node, "LOT_TYPE", TRS.get_char(in_node, "LOT_TYPE"));    
    TRS.add_char(adapt_in_node, "INV_FLAG", TRS.get_char(in_node, "INV_FLAG"));
    TRS.add_nstring(adapt_in_node, "STR_RET_FLOW", TRS.get_string(in_node, "STR_RET_FLOW"));
    TRS.add_int(adapt_in_node, "STR_RET_FLOW_SEQ_NUM", TRS.get_int(in_node, "STR_RET_FLOW_SEQ_NUM"));
    TRS.add_nstring(adapt_in_node, "STR_RET_OPER", TRS.get_string(in_node, "STR_RET_OPER"));
    TRS.add_string(adapt_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(adapt_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(adapt_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(adapt_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_char(adapt_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
    TRS.add_char(adapt_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
    TRS.add_char(adapt_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
    TRS.add_char(adapt_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
    TRS.add_char(adapt_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
    TRS.add_nstring(adapt_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
    TRS.add_nstring(adapt_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
    TRS.add_nstring(adapt_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
    TRS.add_nstring(adapt_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
    TRS.add_nstring(adapt_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_1")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_1", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_1", TRS.get_string(in_node, "LOT_CMF_1"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_2")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_2", MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_2", TRS.get_string(in_node, "LOT_CMF_2"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_3")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_3", MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_3", TRS.get_string(in_node, "LOT_CMF_3"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_4")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_4", MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_4", TRS.get_string(in_node, "LOT_CMF_4"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_5")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_5", MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_5", TRS.get_string(in_node, "LOT_CMF_5"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_6")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_6", MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_6", TRS.get_string(in_node, "LOT_CMF_6"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_7")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_7", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_7", TRS.get_string(in_node, "LOT_CMF_7"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_8")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_8", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_8", TRS.get_string(in_node, "LOT_CMF_8"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_9")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_9", MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_9", TRS.get_string(in_node, "LOT_CMF_9"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_10")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_10", MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_10", TRS.get_string(in_node, "LOT_CMF_10"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_11")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_11", MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_11", TRS.get_string(in_node, "LOT_CMF_11"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_12")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_12", MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_12", TRS.get_string(in_node, "LOT_CMF_12"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_13")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_13", MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_13", TRS.get_string(in_node, "LOT_CMF_13"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_14")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_14", MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_14", TRS.get_string(in_node, "LOT_CMF_14"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_15")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_15", MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_15", TRS.get_string(in_node, "LOT_CMF_15"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_16")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_16", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_16", TRS.get_string(in_node, "LOT_CMF_16"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_17")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_17", MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_17", TRS.get_string(in_node, "LOT_CMF_17"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_18")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_18", MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_18", TRS.get_string(in_node, "LOT_CMF_18"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_19")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_19", MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_19", TRS.get_string(in_node, "LOT_CMF_19"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_20")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "LOT_CMF_20", MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "LOT_CMF_20", TRS.get_string(in_node, "LOT_CMF_20"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_1")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "ADD_ORDER_ID_1", MWIPLOTSTSX.ADD_ORDER_ID_1, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_1));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "ADD_ORDER_ID_1", TRS.get_string(in_node, "ADD_ORDER_ID_1"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_2")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "ADD_ORDER_ID_2", MWIPLOTSTSX.ADD_ORDER_ID_2, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_2));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "ADD_ORDER_ID_2", TRS.get_string(in_node, "ADD_ORDER_ID_2"));
    }

    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_3")) == MP_TRUE)
    {
        TRS.add_string(adapt_in_node, "ADD_ORDER_ID_3", MWIPLOTSTSX.ADD_ORDER_ID_3, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_3));
    }
    else
    {
        TRS.add_nstring(adapt_in_node, "ADD_ORDER_ID_3", TRS.get_string(in_node, "ADD_ORDER_ID_3"));
    }

    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 20; i++)
        {
            sprintf(s_member_name, "%s%d", s_member[j], i + 1);
            TRS.add_nstring(adapt_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
        }
    }

    if (COM_isnullspace(TRS.get_string(in_node, "RWK_END_FLOW")) == MP_FALSE)
        TRS.add_nstring(adapt_in_node, "RWK_END_FLOW", TRS.get_string(in_node, "RWK_END_FLOW"));

    if (COM_isnullspace(TRS.get_string(in_node, "RWK_END_OPER")) == MP_FALSE)
        TRS.add_nstring(adapt_in_node, "RWK_END_OPER", TRS.get_string(in_node, "RWK_END_OPER"));

    if (CUS_WIP_Adapt_Lot_Before_Transaction(s_msg_code, 0, adapt_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_ADAPT_LOT(s_msg_code, adapt_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Adapt_Lot_After_Transaction(s_msg_code, 0, adapt_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }



    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Adapt_Lot_Validation()
- Validation Check sub function of "CUS_WIP_ADAPT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Adapt_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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
CUS_WIP_Adapt_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_ADAPT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Adapt_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;	    //LOT 마스터

    //lot 정보 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (MWIPLOTSTS.INV_FLAG == 'Y')
    {
        MWIPLOTSTS.INV_FLAG = ' ';
        memset(MWIPLOTSTS.STR_RET_FLOW, ' ', sizeof(MWIPLOTSTS.STR_RET_FLOW));
        memset(MWIPLOTSTS.STR_RET_OPER, ' ', sizeof(MWIPLOTSTS.STR_RET_OPER));
        TRS.copy(MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW), in_node, "TO_FLOW");

        DBU_update_mwiplotstsx(1, &MWIPLOTSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "MWIPLOTSTS UPDATE(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Adapt_Lot_After_Transaction()
- Main sub function of "CUS_WIP_ADAPT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Adapt_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}