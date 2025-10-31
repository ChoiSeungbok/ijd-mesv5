/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_end_lot.c
    Description : 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/25  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_End_Lot()
        - 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_End_Lot", out_node);

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
    CUS_EIS_END_LOT()
        - Main sub function of "CUS_EIS_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;

    struct MWIPCOLDEF_TAG MWIPCOLDEF;
    struct MEDCCOLVER_TAG MEDCCOLVER;
    struct MEDCCOLCHR_TAG MEDCCOLCHR;

    TRSNode *end_lot_in;
    TRSNode *collect_lot_in;
    TRSNode  *char_list;
    TRSNode  *unit_list;
    TRSNode  *value_list;

    TRSNode  **para_list;
    TRSNode  **para_char_list;

    int i_para_count;
    int i_para_char_count;

    LOG_head("CUS_EIS_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    DBU_init_mwiplotstsx(&MWIPLOTSTSX);

    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

    if(DB_error_code == DB_NOT_FOUND)
    {
        // WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        return MP_FALSE;
    }
    else if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    if(MWIPLOTSTSX.HOLD_FLAG == 'Y')
    {
        // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
        strcpy(s_msg_code, "WIP-0059");
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        TRS.add_fieldmsg(out_node, "HOLD_CODE", DT_STRING, sizeof(MWIPLOTSTSX.HOLD_CODE), MWIPLOTSTSX.HOLD_CODE);

        DBC_init_mgcmtbldat(&MGCMTBLDAT);
        TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_HOLD_CODE, strlen(MP_WIP_HOLD_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.HOLD_CODE, sizeof(MWIPLOTSTSX.HOLD_CODE));

        DBC_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_fieldmsg(out_node, "HOLD_CODE_DESC", DT_STRING, sizeof(MGCMTBLDAT.DATA_1), MGCMTBLDAT.DATA_1);

        return MP_FALSE;
    }

    DBC_init_mrasresdef(&MRASRESDEF);
    memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));
    TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");

    DBC_select_mrasresdef(1, &MRASRESDEF);
    if(DB_error_code == DB_NOT_FOUND)
    {
        // RAS-0003 : 존재하지 않는 장비입니다.
        strcpy(s_msg_code, "RAS-0003");

        TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);

        return MP_FALSE;
    }

    // Collection Set ID 찾기
    DBC_init_mwipcoldef(&MWIPCOLDEF);
    memcpy(MWIPCOLDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPCOLDEF.FACTORY));
    memcpy(MWIPCOLDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPCOLDEF.MAT_ID));
    MWIPCOLDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;
    memcpy(MWIPCOLDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPCOLDEF.OPER));
    MWIPCOLDEF.COLLECTION_MODE = 'A';  // Auto
    MWIPCOLDEF.OPT_LEVEL = '4';        // Material - Operation Mode

    DBC_select_mwipcoldef(2, &MWIPCOLDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // EDC-0008 : COLLECTION SET이 MATERIAL-FLOW-OPERATION에 존재하지 않읍니다.
            strcpy(s_msg_code, "EDC-0008");
        }
        else
        {
            strcpy(s_msg_code, "EDC-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "Select MWIPCOLDEF 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPCOLDEF.MAT_VER);
        TRS.add_fieldmsg(out_node, "COLLECTION_MODE", DT_CHAR, MWIPCOLDEF.COLLECTION_MODE);
        TRS.add_fieldmsg(out_node, "OPT_LEVEL", DT_CHAR, MWIPCOLDEF.OPT_LEVEL);

        return MP_FALSE;
    }

    // Collection Set Version 찾기
    DBC_init_medccolver(&MEDCCOLVER);
    memcpy(MEDCCOLVER.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MEDCCOLVER.FACTORY));
    memcpy(MEDCCOLVER.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID));
    DBC_select_medccolver(2, &MEDCCOLVER);

    collect_lot_in = TRS.add_node(in_node, "Collect_Lot_In");
    CopyDefaultMembers(collect_lot_in, in_node);
    TRS.add_string(collect_lot_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    TRS.add_string(collect_lot_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
    TRS.add_int(collect_lot_in, "MAT_VER", MWIPLOTSTSX.MAT_VER);
    TRS.add_string(collect_lot_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
    TRS.add_int(collect_lot_in, "FLOW_SEQ_NUM", MWIPLOTSTSX.FLOW_SEQ_NUM);
    TRS.add_nstring(collect_lot_in, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(collect_lot_in, "COL_SET_ID", TRS.get_string(in_node, "COL_SET_ID"));
    TRS.add_int(collect_lot_in, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
    TRS.add_nstring(collect_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    i_para_count = TRS.get_item_count(in_node, "PARA_LIST");
    para_list = TRS.get_list(in_node, "PARA_LIST");

    for (int i = 0; i < i_para_count; i++)
    {
        para_char_list = TRS.get_list(para_list[i], "CHAR_LIST");
        i_para_char_count = TRS.get_item_count(para_list[i], "CHAR_LIST");

        for (int j = 0; j < i_para_char_count; j++)
        {
            char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");

            DBC_init_medccolchr(&MEDCCOLCHR);
            memcpy(MEDCCOLCHR.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MEDCCOLCHR.FACTORY));
            memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
            MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;

            MEDCCOLCHR.SEQ_NUM = j + 1;
            DBC_select_medccolchr(3, &MEDCCOLCHR);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "EDC-0004");

                TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select 3", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLVER.FACTORY);
                TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLVER.COL_SET_ID);
                TRS.add_fieldmsg(out_node, "COL_SET_VERSION", DT_INT, MEDCCOLCHR.COL_SET_VERSION);
                TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, MEDCCOLCHR.SEQ_NUM);

                return MP_FALSE;
            }
            else if (DB_error_code == DB_NOT_FOUND)
            {
                // EDC-0058 : 이 CHARACTER는 COLLECTION SET에 붙어있지 않습니다.
                strcpy(s_msg_code, "EDC-0058");
                TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select 3", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLVER.FACTORY);
                TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLVER.COL_SET_ID);
                TRS.add_fieldmsg(out_node, "COL_SET_VERSION", DT_INT, MEDCCOLCHR.COL_SET_VERSION);
                TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, MEDCCOLCHR.SEQ_NUM);

                return MP_FALSE;
            }

            TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));

            unit_list = TRS.add_node(char_list, "UNIT_LIST");
            TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);
            value_list = TRS.add_node(unit_list, "VALUE_LIST");
            TRS.add_nstring(value_list, "VALUE", TRS.get_string(para_list[i], "PARA_VALUE"));
        }

        if (EDC_COLLECT_LOT_DATA(s_msg_code, collect_lot_in, out_node) == MP_FALSE)
            return MP_FALSE;
    }


    // End Lot 처리
    end_lot_in = TRS.add_node(in_node, "End_Lot_In");

    CopyDefaultMembers(end_lot_in, in_node);
    TRS.add_char(end_lot_in, IN_PROCSTEP, '1');

    TRS.add_nstring(end_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(end_lot_in, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
    TRS.add_int(end_lot_in, "MAT_VER", MWIPLOTSTSX.MAT_VER);
    TRS.add_string(end_lot_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
    TRS.add_string(end_lot_in, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
    TRS.add_nstring(end_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if(CUS_WIP_END_LOT(s_msg_code, end_lot_in, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}
