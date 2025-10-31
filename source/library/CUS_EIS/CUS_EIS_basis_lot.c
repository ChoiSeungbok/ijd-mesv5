/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_basis_lot.c
    Description : Cup 조립, Impact 설비이 작업 시작 정보를 전송한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/14  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_BASIS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_BASIS_LOT(char *s_msg_code, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Basis_Lot()
        - Cup 조립, Impact 설비이 작업 시작 정보를 전송한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Basis_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_BASIS_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Basis_Lot", out_node);

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
    CUS_EIS_BASIS_LOT()
        - Main sub function of "CUS_EIS_Basis_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_BASIS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct CWIPLOTBAS_TAG CWIPLOTBAS;

    TRSNode *send_node;

    char s_channel[30];

    LOG_head("CUS_EIS_BASIS_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Validation_CUS_EIS_BASIS_LOT(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    DBU_init_mwipmatdef(&MWIPMATDEF);
    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
    MWIPMATDEF.MAT_VER = 1;
    DBU_select_mwipmatdef(1, &MWIPMATDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        if(DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0006 : 이 제품은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0006");
        }
        else if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_INT, MWIPMATDEF.MAT_VER);

        return MP_FALSE;
    }

    DBU_init_cwiplotbas(&CWIPLOTBAS);
    TRS.copy(CWIPLOTBAS.MASTER_LOT_ID, sizeof(CWIPLOTBAS.MASTER_LOT_ID), in_node, "LOT_ID");
    TRS.copy(CWIPLOTBAS.RES_ID, sizeof(CWIPLOTBAS.RES_ID), in_node, "RES_ID");
    DBU_select_cwiplotbas(1, &CWIPLOTBAS);
    TRS.copy(CWIPLOTBAS.ORDER_ID, sizeof(CWIPLOTBAS.ORDER_ID), in_node, "ORDER_ID");
    TRS.copy(CWIPLOTBAS.MAT_ID, sizeof(CWIPLOTBAS.MAT_ID), in_node, "MAT_ID");
    TRS.copy(CWIPLOTBAS.FACTORY, sizeof(CWIPLOTBAS.FACTORY), in_node, IN_FACTORY);
    CWIPLOTBAS.LOT_QTY = TRS.get_int(in_node, "LOT_QTY");
    TRS.copy(CWIPLOTBAS.RECIPE_ID, sizeof(CWIPLOTBAS.RECIPE_ID), in_node, "RECIPE_ID");
    CWIPLOTBAS.AUTO_FLAG = TRS.get_string(in_node, "AUTO_FLAG")[0];

    if (DB_error_code == DB_SUCCESS)
    {
        TRS.copy(CWIPLOTBAS.UPDATE_USER_ID, sizeof(CWIPLOTBAS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTBAS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTBAS.UPDATE_TIME));
        DBU_update_cwiplotbas(1, &CWIPLOTBAS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_fieldmsg(out_node, "CWIPLOTBAS Update 1", MP_NVST);
            TRS.add_fieldmsg(out_node, "MASTER_LOT_ID", MP_STR, sizeof(CWIPLOTBAS.MASTER_LOT_ID), CWIPLOTBAS.MASTER_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }
    else if(DB_error_code == DB_NOT_FOUND)
    {
        TRS.copy(CWIPLOTBAS.CREATE_USER_ID, sizeof(CWIPLOTBAS.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTBAS.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTBAS.CREATE_TIME));
        DBU_insert_cwiplotbas(&CWIPLOTBAS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_fieldmsg(out_node, "CWIPLOTBAS INSERT", MP_NVST);
            TRS.add_fieldmsg(out_node, "BASIS_LOT_ID", MP_STR, sizeof(CWIPLOTBAS.MASTER_LOT_ID), CWIPLOTBAS.MASTER_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    // MC에 전송할 Channel 생성
    sprintf(s_channel, "/%.*s/EAP/%.*s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, COM_len_space(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID)), MRASRESDEF.RES_ID);

    send_node = TRS.add_node(in_node, "Start_Lot");
    CopyDefaultMembers(send_node, in_node);
    TRS.add_char(send_node, IN_PROCSTEP, '1');

    // MC에 전송하는 순서 중요하므로
    // 순서를 변경하지 말것
    TRS.add_string(send_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
    TRS.add_nstring(send_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(send_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(send_node, "RECIPE_ID", MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1));
    TRS.add_int(send_node, "LOT_QTY", TRS.get_int(in_node, "LOT_QTY"));
    TRS.add_nstring(send_node, "AUTO_FLAG", TRS.get_string(in_node, "AUTO_FLAG"));

    MOA.call_service("EAP", "EIS_EAP_Basis_Lot", send_node, NULL, s_channel, 18000000, DM_UNICAST);

    LOG_head("Send Message To Cup Equipment ");
    TRS.log_add_all_members(send_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    return MP_TRUE;
}

/*******************************************************************************
    Validation_CUS_EIS_BASIS_LOT()
        - Main sub function of "CUS_EIS_Basis_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_BASIS_LOT(char *s_msg_code, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *in_node, TRSNode *out_node)
{
    if(TRS.get_int(in_node, "LOT_QTY") == 0)
    {
        // WIP-0598 : LOT 수량은 0 보다 크야 합니다.
        strcpy(s_msg_code, "WIP-0598");
        TRS.add_fieldmsg(out_node, "Lot Quantity Error", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_NSTRING, TRS.get_string(in_node, "LOT_ID"));
        TRS.add_fieldmsg(out_node, "LOT_QTY", DT_INT, TRS.get_int(in_node, "LOT_QTY"));

        return MP_FALSE;
    }

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
