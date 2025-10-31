/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_round_end_lot.c
    Description : Round 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/09  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_ROUND_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Round_End_Lot()
        - Round 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Round_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_ROUND_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Round_End_Lot", out_node);

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
    CUS_EIS_ROUND_END_LOT()
        - Main sub function of "CUS_EIS_Round_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_ROUND_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTRND_TAG CWIPLOTRND;
    struct CWIPLOTRIM_TAG CWIPLOTRIM;
//    struct MEDCCOLVER_TAG MEDCCOLVER;
   // struct MWIPCOLDEF_TAG MWIPCOLDEF;
//    struct MEDCCOLCHR_TAG MEDCCOLCHR;
//    struct MEDCLOTDAT_TAG MEDCLOTDAT;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    //struct MWIPMATDEF_TAG MWIPMATDEF_TG;
    struct CWIPRCPDEF_TAG CWIPRCPDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    struct work_date_tag work_date;

    int i = 0;
    int iCnt = 0;
    //double dAdjQty = 0;

    TRSNode **all_thick_list;
    TRSNode **flatness_list;
    TRSNode **image_list;

//    TRSNode *collect_lot_in;
//    TRSNode *char_list;
//    TRSNode  *unit_list;
//    TRSNode  *value_list;
//    TRSNode  *value_seq_list;
//    TRSNode *edc_out;

    //TRSNode *start_lot_in;

    LOG_head("CUS_EIS_ROUND_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Check_LotStatus(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if(Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    //공정 정보 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    DBU_select_mwipoprdef(1, &MWIPOPRDEF);

    //LOT ID에 대한 품목 정보를 조회한다.
    DBU_init_mwipmatdef(&MWIPMATDEF);
    memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
    MWIPMATDEF.MAT_VER = 1;
    DBU_select_mwipmatdef(1, &MWIPMATDEF);

    //레시피 정보 조회
    DBU_init_cwiprcpdef(&CWIPRCPDEF);
    memcpy(CWIPRCPDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
    memcpy(CWIPRCPDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
    memcpy(CWIPRCPDEF.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    memcpy(CWIPRCPDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    DBU_select_cwiprcpdef(1, &CWIPRCPDEF);




	/*
    // Collection Set ID 찾기
    DBU_init_mwipcoldef(&MWIPCOLDEF);
    memcpy(MWIPCOLDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPCOLDEF.FACTORY));
    memcpy(MWIPCOLDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPCOLDEF.MAT_ID));
    MWIPCOLDEF.MAT_VER = MWIPLOTSTS.MAT_VER;
    memcpy(MWIPCOLDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPCOLDEF.OPER));
    MWIPCOLDEF.OPT_LEVEL = '4';        // Material - Operation Mode
    MWIPCOLDEF.DISABLE_FLAG = 'N';

    DBU_select_mwipcoldef(3, &MWIPCOLDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_init_mwipcoldef(&MWIPCOLDEF);
            memcpy(MWIPCOLDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPCOLDEF.FACTORY));
            memcpy(MWIPCOLDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPCOLDEF.OPER));
            MWIPCOLDEF.OPT_LEVEL = '3';        // Operation Mode
            MWIPCOLDEF.DISABLE_FLAG = 'N';
            DBU_select_mwipcoldef(3, &MWIPCOLDEF);
            if (DB_error_code != DB_SUCCESS)
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

                TRS.add_fieldmsg(out_node, "Select MWIPCOLDEF 3", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
                TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
                TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPCOLDEF.MAT_VER);
                TRS.add_fieldmsg(out_node, "DISABLE_FLAG", DT_CHAR, MWIPCOLDEF.DISABLE_FLAG);
                TRS.add_fieldmsg(out_node, "OPT_LEVEL", DT_CHAR, MWIPCOLDEF.OPT_LEVEL);

                return MP_FALSE;
            }
        }
        else
        {
            strcpy(s_msg_code, "EDC-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
            TRS.add_fieldmsg(out_node, "Select MWIPCOLDEF 3", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
            TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPCOLDEF.MAT_VER);
            TRS.add_fieldmsg(out_node, "DISABLE_FLAG", DT_CHAR, MWIPCOLDEF.DISABLE_FLAG);
            TRS.add_fieldmsg(out_node, "OPT_LEVEL", DT_CHAR, MWIPCOLDEF.OPT_LEVEL);

            return MP_FALSE;
        }
    }

    //EDC 데이터 등록
    // Collection Set Version 찾기
    DBC_init_medccolver(&MEDCCOLVER);
    memcpy(MEDCCOLVER.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MEDCCOLVER.FACTORY));
    memcpy(MEDCCOLVER.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID));
    DBC_select_medccolver(2, &MEDCCOLVER);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // EDC-0098 : 배포된 COLLECTION VERSION을 찾을 수 없습니다.
            strcpy(s_msg_code, "EDC-0098");
        }
        else
        {
            strcpy(s_msg_code, "EDC-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MEDCCOLVER SELECT 2", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
        TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

        return MP_FALSE;
    }

    collect_lot_in = TRS.add_node(in_node, "Collect_Lot_In");
    CopyDefaultMembers(collect_lot_in, in_node);
    TRS.add_char(collect_lot_in, IN_PROCSTEP, '4');
    TRS.add_string(collect_lot_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    TRS.add_string(collect_lot_in, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(collect_lot_in, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(collect_lot_in, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_int(collect_lot_in, "FLOW_SEQ_NUM", MWIPLOTSTS.FLOW_SEQ_NUM);
    TRS.add_string(collect_lot_in, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    TRS.add_string(collect_lot_in, "COL_SET_ID", MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
    TRS.add_int(collect_lot_in, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
    TRS.add_nstring(collect_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_char(collect_lot_in, "SELECT_MFO_FLAG", 'Y');
    TRS.add_string(collect_lot_in, "RECIPE_ID", CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));    

    //이미 edc데이터가 있는지 확인한다. 없으면 insert, 있으면 update
    DBU_init_medclotdat(&MEDCLOTDAT);
    memcpy(MEDCLOTDAT.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    MEDCLOTDAT.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
    memcpy(MEDCLOTDAT.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    memcpy(MEDCLOTDAT.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
    MEDCLOTDAT.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;

    iCnt = (int)DBU_select_medclotdat_scalar(2, &MEDCLOTDAT);
    if (iCnt == 0)
    {
        DBC_init_medccolchr(&MEDCCOLCHR);
        memcpy(MEDCCOLCHR.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MEDCCOLCHR.FACTORY));
        memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
        MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;

        DBC_open_medccolchr(3, &MEDCCOLCHR);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
            strcpy(s_msg_code, "WIP-0585");
            TRS.add_fieldmsg(out_node, "MEDCCOLCHR OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
            TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
        while (1)
        {
            DBC_fetch_medccolchr(3, &MEDCCOLCHR);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_medccolchr(3);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "MEDCCOLCHR FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
                TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

				// 20.12.22 minjae.go
				DBU_close_medccolchr(3);
				return MP_FALSE;
				//
            }

            char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");
            TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));

            unit_list = TRS.add_node(char_list, "UNIT_LIST");
            TRS.add_string(unit_list, "UNIT_ID", MEDCCOLCHR.UNIT_TBL, sizeof(MEDCCOLCHR.UNIT_TBL));
            TRS.add_char(unit_list, "VALUE_TYPE", MEDCCOLCHR.DATA_TYPE);
            TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);

            if(memcmp(MEDCCOLCHR.CHAR_ID, "ALL-T", strlen("ALL-T")) == MP_FALSE)
            {
                all_thick_list = TRS.get_list(in_node, "ALL_THICKNESS_LIST");
                iCnt = TRS.get_item_count(in_node, "ALL_THICKNESS_LIST");

                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(unit_list, "VALUE_LIST");

                    if(iCnt -1 >= k)                    
                        TRS.add_nstring(value_list, "VALUE", TRS.get_string(all_thick_list[k], "VALUE"));
                    else 
                        TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
            else if (memcmp(MEDCCOLCHR.CHAR_ID, "FLAT", strlen("FLAT")) == MP_FALSE)
            {
                flatness_list = TRS.get_list(in_node, "FLATNESS_LIST");
                iCnt = TRS.get_item_count(in_node, "FLATNESS_LIST");

                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(unit_list, "VALUE_LIST");

                    if (iCnt - 1 >= k)
                        TRS.add_nstring(value_list, "VALUE", TRS.get_string(flatness_list[k], "VALUE"));
                    else 
                        TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
            else if (memcmp(MEDCCOLCHR.CHAR_ID, "MAX-D", strlen("MAX-D")) == MP_FALSE)
            {
                value_list = TRS.add_node(unit_list, "VALUE_LIST");
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "MAX_DIAMETER_1"));
                value_list = TRS.add_node(unit_list, "VALUE_LIST");
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "MAX_DIAMETER_2"));
            }
            else
            {
                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(unit_list, "VALUE_LIST");
                    TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
        }

        edc_out = TRS.create_node("Edc_Out");
        if (EDC_COLLECT_LOT_DATA(s_msg_code, collect_lot_in, edc_out) == MP_FALSE)
        {
            TRS.clone(out_node, edc_out);
            TRS.free_node(edc_out);
            return MP_FALSE;
        }

        TRS.free_node(edc_out);

    }
    else
    {
        TRS.set_char(collect_lot_in, IN_PROCSTEP, '1');
        TRS.add_int(collect_lot_in, "HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);
        TRS.add_char(collect_lot_in, "COL_SET_OVR_FLAG", 'Y');
        TRS.add_string(collect_lot_in, "PROC_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
        TRS.add_string(collect_lot_in, "PROC_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));

        DBC_init_medccolchr(&MEDCCOLCHR);
        memcpy(MEDCCOLCHR.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MEDCCOLCHR.FACTORY));
        memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
        MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;

        DBC_open_medccolchr(3, &MEDCCOLCHR);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
            strcpy(s_msg_code, "WIP-0585");
            TRS.add_fieldmsg(out_node, "MEDCCOLCHR OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
            TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
        while (1)
        {
            DBC_fetch_medccolchr(3, &MEDCCOLCHR);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_medccolchr(3);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "MEDCCOLCHR FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLCHR.FACTORY);
                TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLCHR.COL_SET_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

				// 20.12.22 minjae.go
				DBU_close_medccolchr(3);
				return MP_FALSE;
				//

            }

            char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");
            TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));
            TRS.add_string(char_list, "COL_SET_ID", MEDCCOLCHR.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
            TRS.add_int(char_list, "CHAR_SEQ_NUM", MEDCCOLCHR.SEQ_NUM);
            TRS.add_int(char_list, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
            TRS.add_int(char_list, "COL_SEQ", 1);
           
            unit_list = TRS.add_node(char_list, "UNIT_LIST");
            TRS.add_string(unit_list, "UNIT_ID", MEDCCOLCHR.UNIT_TBL, sizeof(MEDCCOLCHR.UNIT_TBL));
            TRS.add_char(unit_list, "VALUE_TYPE", MEDCCOLCHR.DATA_TYPE);
            TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);

            value_seq_list = TRS.add_node(unit_list, "VALUE_SEQ_LIST");
            TRS.add_int(value_seq_list, "VALUE_SEQ_NUM", 1);

            if (memcmp(MEDCCOLCHR.CHAR_ID, "ALL-T", strlen("ALL-T")) == MP_FALSE)
            {
                all_thick_list = TRS.get_list(in_node, "ALL_THICKNESS_LIST");
                iCnt = TRS.get_item_count(in_node, "ALL_THICKNESS_LIST");

                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(value_seq_list, "VALUE_LIST");

                    if (iCnt - 1 >= k)
                        TRS.add_nstring(value_list, "VALUE", TRS.get_string(all_thick_list[k], "VALUE"));
                    else
                        TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
            else if (memcmp(MEDCCOLCHR.CHAR_ID, "FLAT", strlen("FLAT")) == MP_FALSE)
            {
                flatness_list = TRS.get_list(in_node, "FLATNESS_LIST");
                iCnt = TRS.get_item_count(in_node, "FLATNESS_LIST");

                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(value_seq_list, "VALUE_LIST");

                    if (iCnt - 1 >= k)
                        TRS.add_nstring(value_list, "VALUE", TRS.get_string(flatness_list[k], "VALUE"));
                    else
                        TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
            else if (memcmp(MEDCCOLCHR.CHAR_ID, "MAX-D", strlen("MAX-D")) == MP_FALSE)
            {
                value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "MAX_DIAMETER_1"));
                value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
                TRS.add_nstring(value_list, "VALUE", TRS.get_string(in_node, "MAX_DIAMETER_2"));
            }
            else
            {
                for (int k = 0; k < MEDCCOLCHR.VALUE_COUNT; k++)
                {
                    value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
                    TRS.add_nstring(value_list, "VALUE", " ");
                }
            }
        }

        edc_out = TRS.create_node("Edc_Out");
        if (EDC_CHANGE_LOT_DATA(s_msg_code, collect_lot_in, edc_out) == MP_FALSE)
        {
            TRS.clone(out_node, edc_out);
            TRS.free_node(edc_out);
            return MP_FALSE;
        }

        TRS.free_node(edc_out);
    }

	*/


    //LOT ID를 재조회 한다.
    DBU_init_mwiplotstsx(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

    DBU_init_cwiplotrnd(&CWIPLOTRND);
    TRS.copy(CWIPLOTRND.LOT_ID, sizeof(CWIPLOTRND.LOT_ID), in_node, "LOT_ID");
    CWIPLOTRND.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;

    //등록이 되어있는지 확인한다.
    DBU_select_cwiplotrnd(1, &CWIPLOTRND);

    memcpy(CWIPLOTRND.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTRND.OPER));
    memcpy(CWIPLOTRND.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTRND.MAT_ID));
    memcpy(CWIPLOTRND.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTRND.FLOW));
    CWIPLOTRND.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
    //TRS.copy(CWIPLOTRND.GRADE, sizeof(CWIPLOTRND.GRADE), in_node, "GRADE");
    memcpy(CWIPLOTRND.GRADE, MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
    TRS.copy(CWIPLOTRND.RES_ID, sizeof(CWIPLOTRND.RES_ID), in_node, "RES_ID");
    TRS.copy(CWIPLOTRND.FACTORY, sizeof(CWIPLOTRND.FACTORY), in_node, IN_FACTORY);
    memcpy(CWIPLOTRND.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTRND.WORK_DATE));
    memcpy(CWIPLOTRND.WORK_TIME, gs_sys_time, sizeof(CWIPLOTRND.WORK_TIME));
    memcpy(CWIPLOTRND.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTRND.DAY_NIGHT));

    CWIPLOTRND.EDC_HIST_SEQ = TRS.get_int(in_node, "EDC_HIST_SEQ");

    //TRS.copy(CWIPLOTRND.RECIPE_ID, sizeof(CWIPLOTRND.RECIPE_ID), in_node, "RECIPE_ID");
    memcpy(CWIPLOTRND.RECIPE_ID, CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));
    TRS.copy(CWIPLOTRND.START_TIME, sizeof(CWIPLOTRND.START_TIME), in_node, "START_TIME");
    TRS.copy(CWIPLOTRND.END_TIME, sizeof(CWIPLOTRND.END_TIME), in_node, "END_TIME");
    TRS.copy(CWIPLOTRND.JUDGMENT, sizeof(CWIPLOTRND.JUDGMENT), in_node, "JUDGMENT");

    CWIPLOTRND.S_DEFECT_NUMBER = atof(TRS.get_string(in_node, "S_DEFECT_NUMBER"));
    CWIPLOTRND.S_OUTER_DIAMETER_MIN = atof(TRS.get_string(in_node, "S_OUTER_DIAMETER_MIN"));
    CWIPLOTRND.S_ALL_THICKNESS_MIN = atof(TRS.get_string(in_node, "S_ALL_THICKNESS_MIN"));
    CWIPLOTRND.S_ALL_THICKNESS_MAX = atof(TRS.get_string(in_node, "S_ALL_THICKNESS_MAX"));
    CWIPLOTRND.S_ALL_THICKNESS_TARGET = atof(TRS.get_string(in_node, "S_ALL_THICKNESS_TARGET"));
    CWIPLOTRND.S_FLATNESS_MAX = atof(TRS.get_string(in_node, "S_FLATNESS_MAX"));
    CWIPLOTRND.S_FLATNESS_MIN = atof(TRS.get_string(in_node, "S_FLATNESS_MIN"));

    CWIPLOTRND.SIZE_UM = atof(TRS.get_string(in_node, "SIZE_UM"));
    CWIPLOTRND.SIZE_UM2 = atof(TRS.get_string(in_node, "SIZE_UM2"));
    TRS.copy(CWIPLOTRND.CLASSFICATION, sizeof(CWIPLOTRND.CLASSFICATION), in_node, "CLASSFICATION");
    CWIPLOTRND.OUTER_DIAMETER_1 = atof(TRS.get_string(in_node, "MAX_DIAMETER_1"));
    CWIPLOTRND.OUTER_DIAMETER_2 = atof(TRS.get_string(in_node, "MAX_DIAMETER_2"));
    CWIPLOTRND.OUTER_DIAMETER_MIN = atof(TRS.get_string(in_node, "OUTER_DIAMETER_MIN"));
    all_thick_list = TRS.get_list(in_node, "ALL_THICKNESS_LIST");
    iCnt = TRS.get_item_count(in_node, "ALL_THICKNESS_LIST");

    for (i = 0; i < iCnt; i++)
    {
        if (i == 0)
            CWIPLOTRND.ALL_THICKNESS_1 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 1)
            CWIPLOTRND.ALL_THICKNESS_2 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 2)
            CWIPLOTRND.ALL_THICKNESS_3 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 3)
            CWIPLOTRND.ALL_THICKNESS_4 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 4)
            CWIPLOTRND.ALL_THICKNESS_5 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 5)
            CWIPLOTRND.ALL_THICKNESS_6 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 6)
            CWIPLOTRND.ALL_THICKNESS_7 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 7)
            CWIPLOTRND.ALL_THICKNESS_8 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 8)
            CWIPLOTRND.ALL_THICKNESS_9 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 9)
            CWIPLOTRND.ALL_THICKNESS_10 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 10)
            CWIPLOTRND.ALL_THICKNESS_11 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 11)
            CWIPLOTRND.ALL_THICKNESS_12 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 12)
            CWIPLOTRND.ALL_THICKNESS_13 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 13)
            CWIPLOTRND.ALL_THICKNESS_14 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
        else if (i == 14)
            CWIPLOTRND.ALL_THICKNESS_15 = atof(TRS.get_string(all_thick_list[i], "VALUE"));
    }

    CWIPLOTRND.ALL_THICKNESS_MAX = atof(TRS.get_string(in_node, "ALL_THICKNESS_MAX"));
    CWIPLOTRND.ALL_THICKNESS_MIN = atof(TRS.get_string(in_node, "ALL_THICKNESS_MIN"));

    flatness_list = TRS.get_list(in_node, "FLATNESS_LIST");
    iCnt = TRS.get_item_count(in_node, "FLATNESS_LIST");
    for (i = 0; i < iCnt; i++)
    {
        if (i == 0)
            CWIPLOTRND.FLATNESS_1 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 1)
            CWIPLOTRND.FLATNESS_2 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 2)
            CWIPLOTRND.FLATNESS_3 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 3)
            CWIPLOTRND.FLATNESS_4 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 4)
            CWIPLOTRND.FLATNESS_5 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 5)
            CWIPLOTRND.FLATNESS_6 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 6)
            CWIPLOTRND.FLATNESS_7 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 7)
            CWIPLOTRND.FLATNESS_8 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 8)
            CWIPLOTRND.FLATNESS_9 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 9)
            CWIPLOTRND.FLATNESS_10 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 10)
            CWIPLOTRND.FLATNESS_11 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 11)
            CWIPLOTRND.FLATNESS_12 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 12)
            CWIPLOTRND.FLATNESS_13 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 13)
            CWIPLOTRND.FLATNESS_14 = atof(TRS.get_string(flatness_list[i], "VALUE"));
        else if (i == 14)
            CWIPLOTRND.FLATNESS_15 = atof(TRS.get_string(flatness_list[i], "VALUE"));
    }

    CWIPLOTRND.FLATNESS_MAX = atof(TRS.get_string(in_node, "FLATNESS_MAX"));

    TRS.copy(CWIPLOTRND.DEFECT_IMAGE_1, sizeof(CWIPLOTRND.DEFECT_IMAGE_1), in_node, "DEFECT_IMAGE_1");
    TRS.copy(CWIPLOTRND.DEFECT_IMAGE_2, sizeof(CWIPLOTRND.DEFECT_IMAGE_2), in_node, "DEFECT_IMAGE_2");

    if (DB_error_code == DB_NOT_FOUND)
    {
        TRS.copy(CWIPLOTRND.CREATE_USER_ID, sizeof(CWIPLOTRND.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTRND.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTRND.CREATE_TIME));

        DBU_insert_cwiplotrnd(&CWIPLOTRND);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CWIPLOTRND Insert", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTRND.LOT_ID), CWIPLOTRND.LOT_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }
    else if (DB_error_code == DB_SUCCESS)
    {
        TRS.copy(CWIPLOTRND.UPDATE_USER_ID, sizeof(CWIPLOTRND.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CWIPLOTRND.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTRND.UPDATE_TIME));

        DBU_update_cwiplotrnd(1, &CWIPLOTRND);
        if (DB_error_code != DB_SUCCESS)
        {
            TRS.add_fieldmsg(out_node, "CWIPLOTRND UPDATE", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTRND.LOT_ID), CWIPLOTRND.LOT_ID);

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
    }

    image_list = TRS.get_list(in_node, "IMAGE_LIST");
    iCnt = TRS.get_item_count(in_node, "IMAGE_LIST");

    for (i = 0; i < iCnt; i++)
    {
        DBU_init_cwiplotrim(&CWIPLOTRIM);

        TRS.copy(CWIPLOTRIM.LOT_ID, sizeof(CWIPLOTRIM.LOT_ID), in_node, "LOT_ID");
        CWIPLOTRIM.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
        CWIPLOTRIM.SEQ_NUM = i + 1;

        //등록이 되어있는지 확인한다.
        DBU_select_cwiplotrim(1, &CWIPLOTRIM);

        memcpy(CWIPLOTRIM.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTRIM.OPER));
        memcpy(CWIPLOTRIM.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTRIM.MAT_ID));
        memcpy(CWIPLOTRIM.FLOW, MWIPLOTSTS.FLOW, sizeof(CWIPLOTRIM.FLOW));
        CWIPLOTRIM.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;
        //TRS.copy(CWIPLOTRIM.GRADE, sizeof(CWIPLOTRIM.GRADE), in_node, "GRADE");
        memcpy(CWIPLOTRIM.GRADE, MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
        TRS.copy(CWIPLOTRIM.RES_ID, sizeof(CWIPLOTRIM.RES_ID), in_node, "RES_ID");
        TRS.copy(CWIPLOTRIM.FACTORY, sizeof(CWIPLOTRIM.FACTORY), in_node, IN_FACTORY);
        memcpy(CWIPLOTRIM.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTRIM.WORK_DATE));
        memcpy(CWIPLOTRIM.WORK_TIME, gs_sys_time, sizeof(CWIPLOTRIM.WORK_TIME));
        memcpy(CWIPLOTRIM.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTRIM.DAY_NIGHT));
        memcpy(CWIPLOTRIM.RECIPE_ID, CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));
        CWIPLOTRIM.REAL_COORDINATE_X = atoi(TRS.get_string(image_list[i], "REAL_COORDINATE_X"));
        CWIPLOTRIM.REAL_COORDINATE_Y = atoi(TRS.get_string(image_list[i], "REAL_COORDINATE_Y"));
        TRS.copy(CWIPLOTRIM.SCULPTURE_IMAGE, sizeof(CWIPLOTRIM.SCULPTURE_IMAGE), image_list[i], "SCULPTURE_IMAGE");
        TRS.copy(CWIPLOTRIM.CAMERA_TYPE, sizeof(CWIPLOTRIM.CAMERA_TYPE), image_list[i], "CAMERA_TYPE");
        TRS.copy(CWIPLOTRIM.DETAIL_LOCATION, sizeof(CWIPLOTRIM.DETAIL_LOCATION), image_list[i], "DETAIL_LOCATION");

        if (DB_error_code == DB_NOT_FOUND)
        {
            TRS.copy(CWIPLOTRIM.CREATE_USER_ID, sizeof(CWIPLOTRIM.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTRIM.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTRIM.CREATE_TIME));

            DBU_insert_cwiplotrim(&CWIPLOTRIM);
            if (DB_error_code != DB_SUCCESS)
            {
                TRS.add_fieldmsg(out_node, "CWIPLOTRIM Insert", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTRIM.LOT_ID), CWIPLOTRIM.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTRIM.HIST_SEQ);
                TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, CWIPLOTRIM.SEQ_NUM);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
        else if (DB_error_code == DB_SUCCESS)
        {
            TRS.copy(CWIPLOTRIM.UPDATE_USER_ID, sizeof(CWIPLOTRIM.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTRIM.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTRIM.UPDATE_TIME));

            DBU_update_cwiplotrim(1, &CWIPLOTRIM);
            if (DB_error_code != DB_SUCCESS)
            {
                TRS.add_fieldmsg(out_node, "CWIPLOTRIM UPDATE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTRIM.LOT_ID), CWIPLOTRIM.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTRIM.HIST_SEQ);
                TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, CWIPLOTRIM.SEQ_NUM);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }
    }

    TRS.add_string(in_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));

    //// End Lot 처리
    //if(Equipment_End_Lot(s_msg_code, &MWIPLOTSTS, in_node, out_node) == MP_FALSE)
    //    return MP_FALSE;

    return MP_TRUE;
}
