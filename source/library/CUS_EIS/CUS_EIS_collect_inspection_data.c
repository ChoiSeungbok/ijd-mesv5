/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_collect_inspection_data.c
    Description : 검사 설비의 검사 정보 전송(EAP -> MES)

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/28  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_COLLECT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Collect_Inspection_Data()
        - 설비의 상태 정보 수신(U : Connect, D : Disconnect)
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Collect_Inspection_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_COLLECT_INSPECTION_DATA(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Collect_Inspection_Data", out_node);

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
    CUS_EIS_COLLECT_INSPECTION_DATA()
        - Main sub function of "CUS_EIS_Collect_Inspection_Data" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_COLLECT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MRASRESDEF_TAG MRASRESDEF;

    struct MWIPCOLDEF_TAG MWIPCOLDEF;
    struct MEDCCOLCHR_TAG MEDCCOLCHR;
    struct MEDCCOLVER_TAG MEDCCOLVER;

    struct CWIPGRPLOT_TAG CWIPGRPLOT;

    TRSNode *collect_lot_in;
    TRSNode *char_list;
    TRSNode *unit_list;
    TRSNode *value_list;
    TRSNode *check_lot;
    TRSNode *edc_out;

    TRSNode **para_list;

    int i_para_count;

    LOG_head("CUS_EIS_COLLECT_INSPECTION_DATA");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    // Press 설비의 경우 LOT_ID에 GROUP_ID EAP에서 받음
    DBU_init_cwipgrplot(&CWIPGRPLOT);
    memcpy(CWIPGRPLOT.FACTORY, MRASRESDEF.FACTORY, sizeof(CWIPGRPLOT.FACTORY));
    TRS.copy(CWIPGRPLOT.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID), in_node, "LOT_ID");
    DBU_open_cwipgrplot(4, &CWIPGRPLOT);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "CWIPGRPLOT Open 4", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
        TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);

        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_cwipgrplot(4, &CWIPGRPLOT);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_cwipgrplot(4);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "CWIPGRPLOT Fetch 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
            TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);

			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//

            return MP_FALSE;
        }

        check_lot = TRS.create_node("Check_Node");
        CopyDefaultMembers(check_lot, in_node);
        TRS.add_string(check_lot, "LOT_ID", CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID));

        if (Check_LotStatus(s_msg_code, &MWIPLOTSTS, check_lot, out_node) == MP_FALSE)
        {
            TRS.free_node(check_lot);
			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//
            return MP_FALSE;
        }

        TRS.free_node(check_lot);

        if (memcmp(MWIPLOTSTS.LOT_STATUS, MP_LOT_STATUS_PROC, strlen(MP_LOT_STATUS_PROC)) != 0)
        {
            // WIP-0595 : 해당 Lot은 작업시작이 되지 않았습니다.
            strcpy(s_msg_code, "WIP-0595");

            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
            TRS.add_fieldmsg(out_node, "LOT_STATUS", DT_STRING, sizeof(MWIPLOTSTS.LOT_STATUS), MWIPLOTSTS.LOT_STATUS);

			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//

            return MP_FALSE;
        }

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

					// 20.12.22 minjae.go
					DBU_close_cwipgrplot(4);
					//

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

				// 20.12.22 minjae.go
				DBU_close_cwipgrplot(4);
				//

                return MP_FALSE;
            }
        }

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

			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//

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
        TRS.add_nstring(collect_lot_in, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_string(collect_lot_in, "COL_SET_ID", MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
        TRS.add_int(collect_lot_in, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
        TRS.add_nstring(collect_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));

        i_para_count = TRS.get_item_count(in_node, "PARA_LIST");
        para_list = TRS.get_list(in_node, "PARA_LIST");

        for (int i = 0; i < i_para_count; i++)
        {
            char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");

            DBC_init_medccolchr(&MEDCCOLCHR);
            memcpy(MEDCCOLCHR.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MEDCCOLCHR.FACTORY));
            memcpy(MEDCCOLCHR.COL_SET_ID, MEDCCOLVER.COL_SET_ID, sizeof(MEDCCOLCHR.COL_SET_ID));
            MEDCCOLCHR.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;

            MEDCCOLCHR.SEQ_NUM = i + 1;
            DBC_select_medccolchr(3, &MEDCCOLCHR);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "EDC-0004");

                TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select 3", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLCHR.FACTORY), MEDCCOLVER.FACTORY);
                TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLCHR.COL_SET_ID), MEDCCOLVER.COL_SET_ID);
                TRS.add_fieldmsg(out_node, "COL_SET_VERSION", DT_INT, MEDCCOLCHR.COL_SET_VERSION);
                TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, MEDCCOLCHR.SEQ_NUM);

				// 20.12.22 minjae.go
				DBU_close_cwipgrplot(4);
				//

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

				// 20.12.22 minjae.go
				DBU_close_cwipgrplot(4);
				//

                return MP_FALSE;
            }

            TRS.add_string(char_list, "CHAR_ID", MEDCCOLCHR.CHAR_ID, sizeof(MEDCCOLCHR.CHAR_ID));

            unit_list = TRS.add_node(char_list, "UNIT_LIST");
            TRS.add_int(unit_list, "UNIT_SEQ_NUM", 1);
            value_list = TRS.add_node(unit_list, "VALUE_LIST");
            TRS.add_nstring(value_list, "VALUE", TRS.get_string(para_list[i], "PARA_VALUE"));
        }

        edc_out = TRS.create_node("Edc_Out");

        if (EDC_COLLECT_LOT_DATA(s_msg_code, collect_lot_in, edc_out) == MP_FALSE)
        {
            TRS.clone(out_node, edc_out);
            TRS.free_node(edc_out);
			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//
            return MP_FALSE;
        }

        TRS.free_node(edc_out);
    }

    return MP_TRUE;
}
