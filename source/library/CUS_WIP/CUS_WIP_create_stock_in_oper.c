/*******************************************************************************

    System      : MESplus
    Module      : CUS_WIP
    File Name   : CUS_WIP_create_stock_in_oper.c
    Description : Lagacy System의 재고, 재공을 MES으로 재고, 재공을 생성한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/10/07  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_CREATE_STOCK_IN_OPER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int RAS_UPDATE_TOOL_EVENT_RELATION(char *s_msg_code, TRSNode *tool_event_in, TRSNode *cmn_out);

/*******************************************************************************
    CUS_WIP_Create_Stock_In_Oper()
        - Lagacy System의 재고, 재공을 MES으로 재고, 재공을 생성한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Stock_In_Oper(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_CREATE_STOCK_IN_OPER(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Create_Stock_In_Oper", out_node);

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
    CUS_WIP_CREATE_STOCK_IN_OPER()
        - Main sub function of "CUS_WIP_Create_Stock_In_Oper" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CREATE_STOCK_IN_OPER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MWIPLOTHISX_TAG MWIPLOTHIS;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPMATFLW_TAG MWIPMATFLW;
    struct MWIPMATFLW_TAG MWIPMATFLW_M;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;
    struct MWIPFLWOPR_TAG MWIPFLWOPR_M;
	struct MWIPFLWOPR_TAG MWIPFLWOPR_PROD;
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct CPAKLOTSTS_TAG CPAKLOTSTS;
    struct CWIPUOPLOT_TAG CWIPUOPLOT;
	struct CPAKORDSTS_TAG CPAKORDSTS;
    struct CWIPGRPSTS_TAG CWIPGRPSTS;
    struct CWIPGRPLOT_TAG CWIPGRPLOT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct CWIPGRPLOT_TAG CWIPGRPLOT_LOT;
	struct CWIPGRPSTS_TAG CWIPGRPSTS_D12_1;
	struct CWIPGRPSTS_TAG CWIPGRPSTS_D12_2;
	struct CWIPGRPLOT_TAG CWIPGRPLOT_GRP;
	struct MRASTOLDEF_TAG MRASTOLDEF;
	struct MRASTEVDEF_TAG MRASTEVDEF;
	struct CINVUOPLOT_TAG CINVUOPLOT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;
    struct CWIPLOTREC_TAG CWIPLOTREC;

    // Legacy System Table
    struct CT_PACKING_V_TAG CT_PACKING_V;
    struct CT_MTL510T_TAG CT_MTL510T;
    struct CT_PRD200T_TAG CT_PRD200T;
    struct CT_PRD210T_TAG CT_PRD210T;
	struct CT_MOLD_V_TAG CT_MOLD_V;
    struct work_date_tag work_date;

    TRSNode *create_in_node;
    TRSNode *inv_lot;
	TRSNode *gen_in_node;
    TRSNode *cmn_out;
    //TRSNode *store_in;
    TRSNode *move_in;
	TRSNode *tool_in;
	TRSNode *tool_event_in;

    int iCnt = 0;
    int i_lot_db_error_code = 0;
    int i_sel = 0;
    char s_first_flow[20];
    char s_last_oper[10];
	char s_new_lot_id[26];
	char s_group_id[25];
    char s_vendor_site_id[30];
	int i_group_id_count = 0;
	int i_mapping_seq = 1;
	int i_lot_seq = 0;

    LOG_head("CUS_WIP_CREATE_STOCK_IN_OPER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);
    
    DBU_init_mwipmatdef(&MWIPMATDEF);
    TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), in_node, "MAT_ID");
    MWIPMATDEF.MAT_VER = 1;

    DBU_select_mwipmatdef(1, &MWIPMATDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0006 : 이 제품은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0006");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATDEF.MAT_VER);

        return MP_FALSE;
    }

    if (MWIPMATDEF.DELETE_FLAG == 'Y')
    {
        // WIP-0276 : 이 제품은 이미 삭제되었습니다. 제품을 확인하세요.
        strcpy(s_msg_code, "WIP-0276");
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
        TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATDEF.MAT_VER);

        return MP_FALSE;
    }

    memset(&work_date, ' ', sizeof(work_date));
    Get_shift(MWIPMATDEF.FACTORY, &work_date);

    DBU_init_mwipoprdef(&MWIPOPRDEF);
    memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");

    DBU_select_mwipoprdef(1, &MWIPOPRDEF);
    if(DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
        }
        else
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1' || TRS.get_procstep(in_node) == '6')
    {
        DBU_init_minvlotsts(&MINVLOTSTS);
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
        DBU_select_minvlotsts(1, &MINVLOTSTS);
        
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "INV-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

            return MP_FALSE;
        }

		i_lot_db_error_code = DB_error_code;
    }
    else
    {
        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
        if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "Lot ID", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));
            TRS.add_fieldmsg(out_node, "QTY", DT_DOUBLE, TRS.get_double(in_node, "QTY"));
            TRS.add_fieldmsg(out_node, "OPER", DT_NSTRING, TRS.get_string(in_node, "OPER"));

            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        i_lot_db_error_code = DB_error_code;

        // 제품 타입이 원자재인 경우는 제외(원자재는 Flow가 없음)
        if (memcmp(MWIPMATDEF.MAT_TYPE, MP_MAT_TYPE_RAW_MATERIAL, strlen(MP_MAT_TYPE_RAW_MATERIAL)) != 0)
        {
            // Material의 첫번째 Flow 구하기
            DBU_init_mwipmatflw(&MWIPMATFLW);
            memcpy(MWIPMATFLW.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
            memcpy(MWIPMATFLW.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATFLW.MAT_ID));
            MWIPMATFLW.MAT_VER = 1;
            MWIPMATFLW.FLOW_SEQ_NUM = 1;
            DBU_select_mwipmatflw(3, &MWIPMATFLW);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    // WIP-0593 : 해당 제품은 Flow가 설정되지 않았습니다. 제품 셋업의 플로우 부여에서 설정하세요.
                    strcpy(s_msg_code, "WIP-0593");
                }
                else
                {
                    strcpy(s_msg_code, "WIP-0004");
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                }

                TRS.add_fieldmsg(out_node, "MWIPMATFLW SELECT 2", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_NSTRING, TRS.get_string(in_node, "FACTORY"));
                TRS.add_fieldmsg(out_node, "MAT_ID", DT_NSTRING, TRS.get_string(in_node, "MAT_ID"));

                return MP_FALSE;
            }

            memcpy(s_first_flow, MWIPMATFLW.FLOW, sizeof(s_first_flow));
        }
    }

	// 자재
	if (TRS.get_procstep(in_node) == '1')
	{
		if (i_lot_db_error_code == DB_SUCCESS)
		{
			DBU_init_cinvuoplot(&CINVUOPLOT);
			TRS.copy(CINVUOPLOT.LOT_ID, sizeof(CINVUOPLOT.LOT_ID), in_node, "LOT_ID");
			TRS.copy(CINVUOPLOT.OPER, sizeof(CINVUOPLOT.OPER), in_node, "OPER");
			i_lot_seq = (int)DBU_select_cinvuoplot_scalar(2, &CINVUOPLOT);

			if (i_lot_seq > 0)
			{
				CINVUOPLOT.SEQ = i_lot_seq + 1;
			}
			else if (i_lot_seq == 0)
			{
				CINVUOPLOT.SEQ = 1;
			}
			
			TRS.copy(CINVUOPLOT.MAT_ID, sizeof(CINVUOPLOT.MAT_ID), in_node, "MAT_ID");
			CINVUOPLOT.QTY = TRS.get_double(in_node, "QTY");
			TRS.copy(CINVUOPLOT.VENDOR_ID, sizeof(CINVUOPLOT.VENDOR_ID), in_node, "VENDOR_ID");
			TRS.copy(s_vendor_site_id, sizeof(s_vendor_site_id), in_node, "VENDOR_SITE_ID");
			CINVUOPLOT.VENDOR_SITE_ID = atoi(s_vendor_site_id);
			TRS.copy(CINVUOPLOT.VENDOR_LOT_ID, sizeof(CINVUOPLOT.VENDOR_LOT_ID), in_node, "VENDOR_LOT_ID");
			memset(CINVUOPLOT.MOLD_TYPE, ' ', sizeof(CINVUOPLOT.MOLD_TYPE));
			memset(CINVUOPLOT.MOLD_MODEL, ' ', sizeof(CINVUOPLOT.MOLD_MODEL));

			DBU_insert_cinvuoplot(&CINVUOPLOT);

			DB_commit();
		}
		else
		{
			create_in_node = TRS.add_node(in_node, "Create_Lot_In");

			CopyDefaultMembers(create_in_node, in_node);
			TRS.add_char(create_in_node, IN_PROCSTEP, '3');

			inv_lot = TRS.add_node(create_in_node, "INV_LOT_LIST");
			TRS.add_nstring(inv_lot, "INV_LOT_ID", TRS.get_string(in_node, "LOT_ID"));
			TRS.add_nstring(inv_lot, "INV_LOT_DESC", TRS.get_string(in_node, "REMARKS"));
			TRS.add_nstring(inv_lot, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
			TRS.add_nstring(inv_lot, "OPER", TRS.get_string(in_node, "OPER"));
			TRS.add_double(inv_lot, "QTY", TRS.get_double(in_node, "QTY"));
			TRS.add_nstring(inv_lot, "VENDOR_ID", TRS.get_string(in_node, "VENDOR_ID"));
			TRS.add_nstring(inv_lot, "VENDOR_SITE_ID", TRS.get_string(in_node, "VENDOR_SITE_ID"));
			TRS.add_nstring(inv_lot, "VENDOR_LOT_ID", TRS.get_string(in_node, "VENDOR_LOT_ID"));
			TRS.add_nstring(inv_lot, "IN_TYPE", "MIG");

			if (CUS_INV_CREATE_LOT_MAIN(s_msg_code, create_in_node, out_node) == MP_FALSE)
				return MP_FALSE;
		}
	}
    // 재공
    else if (TRS.get_procstep(in_node) == '2')
    {
        DBU_init_ct_prd210t(&CT_PRD210T);

        DBU_init_ct_prd200t(&CT_PRD200T);
        TRS.copy(CT_PRD200T.LOT_ID, sizeof(CT_PRD200T.LOT_ID), in_node, "LOT_ID");
        DBU_select_ct_prd200t(1, &CT_PRD200T);
        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
                // WIP-0641 : 이 LOT은 Legacy 재공(CT_PRD20OT)에 없습니다.
                strcpy(s_msg_code, "WIP-0641");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "CT_PRD200T Select 1", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PRD200T.LOT_ID), CT_PRD200T.LOT_ID);

            return MP_FALSE;
        }

        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '1');

        TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(create_in_node, "LOT_DESC", TRS.get_string(in_node, "REMARKS"));
        TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_int(create_in_node, "MAT_VER", 1);
        TRS.add_char(create_in_node, "LOT_TYPE", 'P');
        TRS.add_nstring(create_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
        TRS.add_int(create_in_node, "FLOW_SEQ_NUM", TRS.get_int(in_node, "FLOW_SEQ_NUM"));
        TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
        TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
        TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
        TRS.add_nstring(create_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
        TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
        TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");

        if (COM_isspace(CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO)) == MP_FALSE)
        {
            memcpy(CT_PRD210T.LOT_ID, CT_PRD200T.LOT_ID, sizeof(CT_PRD210T.LOT_ID));
            memcpy(CT_PRD210T.OP_CODE, "PC02", strlen("PC02"));
            DBU_select_ct_prd210t(2, &CT_PRD210T);
            if (DB_error_code == DB_SUCCESS)
            {
                TRS.add_string(create_in_node, "LOT_CMF_1", CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO));          // Group ID
                TRS.add_string(create_in_node, "LOT_CMF_3", CT_PRD210T.ATTRIBUTE04, sizeof(CT_PRD210T.ATTRIBUTE04));  // Car 정보
                TRS.add_string(create_in_node, "LOT_CMF_5", CT_PRD210T.ATTRIBUTE02, sizeof(CT_PRD210T.ATTRIBUTE02));  // Cell 중량
                TRS.add_string(create_in_node, "LOT_CMF_6", CT_PRD210T.ATTRIBUTE01, sizeof(CT_PRD210T.ATTRIBUTE01));  // Cell 높이

                DBU_init_cwipgrpsts(&CWIPGRPSTS);
                TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPGRPSTS.GROUP_ID, CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO));
                if (DBU_select_cwipgrpsts_scalar(1, &CWIPGRPSTS) == 0)
                {
                    memcpy(CWIPGRPSTS.GROUP_TYPE, "CELL", 4);
                    memcpy(CWIPGRPSTS.CAR, CT_PRD210T.ATTRIBUTE04, sizeof(CWIPGRPSTS.CAR));
                    CWIPGRPSTS.CELL_HEIGHT = COM_atof(CT_PRD210T.ATTRIBUTE01, sizeof(CT_PRD210T.ATTRIBUTE01));
                    CWIPGRPSTS.CELL_WEIGHT = COM_atof(CT_PRD210T.ATTRIBUTE02, sizeof(CT_PRD210T.ATTRIBUTE02));

                    TRS.copy(CWIPGRPSTS.CREATE_USER_ID, sizeof(CWIPGRPSTS.CREATE_USER_ID), in_node, IN_USERID);
                    memcpy(CWIPGRPSTS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS.CREATE_TIME));

                    DBU_insert_cwipgrpsts(&CWIPGRPSTS);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_fieldmsg(out_node, "CWIPGRPSTS Insert", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
                        TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                        TRS.add_fieldmsg(out_node, "GROUP_TYPE", DT_STRING, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);
                        TRS.add_fieldmsg(out_node, "CAR", DT_STRING, sizeof(CWIPGRPSTS.CAR), CWIPGRPSTS.CAR);
                        TRS.add_fieldmsg(out_node, "CELL_HEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_HEIGHT);
                        TRS.add_fieldmsg(out_node, "CELL_WEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_WEIGHT);

                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }

					// D12 1번
					//그룹ID를 채번한다.   
					memset(s_group_id, ' ', sizeof(s_group_id));
					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);
					TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_GROUP_ID, strlen(MP_ID_ROLE_WIP_GROUP_ID));
					TRS.add_nstring(gen_in_node, "OPER", "D12");
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

					DBU_init_cwipgrpsts(&CWIPGRPSTS_D12_1);
					TRS.copy(CWIPGRPSTS_D12_1.FACTORY, sizeof(CWIPGRPSTS_D12_1.FACTORY), in_node, IN_FACTORY);
					memcpy(CWIPGRPSTS_D12_1.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS_D12_1.GROUP_ID));
					memcpy(CWIPGRPSTS_D12_1.GROUP_TYPE, "D12       ", strlen("D12       "));

					TRS.copy(CWIPGRPSTS_D12_1.CREATE_USER_ID, sizeof(CWIPGRPSTS_D12_1.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPGRPSTS_D12_1.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS_D12_1.CREATE_TIME));

					DBU_insert_cwipgrpsts(&CWIPGRPSTS_D12_1);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPSTS_D12_1 Insert", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
						TRS.add_fieldmsg(out_node, "GROUP_TYPE", DT_STRING, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);
						TRS.add_fieldmsg(out_node, "CAR", DT_STRING, sizeof(CWIPGRPSTS.CAR), CWIPGRPSTS.CAR);
						TRS.add_fieldmsg(out_node, "CELL_HEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_HEIGHT);
						TRS.add_fieldmsg(out_node, "CELL_WEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_WEIGHT);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					DBU_init_cwipgrplot(&CWIPGRPLOT);
					memcpy(CWIPGRPLOT.FACTORY, CWIPGRPSTS.FACTORY, sizeof(CWIPGRPLOT.FACTORY));
					memcpy(CWIPGRPLOT.GROUP_ID, CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO));
					memcpy(CWIPGRPLOT.LOT_ID, s_group_id, strlen(s_group_id));
					DBU_select_cwipgrplot(1, &CWIPGRPLOT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						CWIPGRPLOT.MAPPING_SEQ = 1;
						memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPGRPLOT.AREA_ID));
						memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPGRPLOT.SUB_AREA_ID));
						memcpy(CWIPGRPLOT.OPER, "OC03150   ", strlen("OC03150   "));

						TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));

						DBU_insert_cwipgrplot(&CWIPGRPLOT);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPLOT Insert", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
							TRS.add_fieldmsg(out_node, "MAPPING_SEQ", DT_INT, CWIPGRPLOT.MAPPING_SEQ);
							TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
							TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.AREA_ID), CWIPGRPLOT.AREA_ID);
							TRS.add_fieldmsg(out_node, "SUB_AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.SUB_AREA_ID), CWIPGRPLOT.SUB_AREA_ID);
							TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPGRPLOT.OPER), CWIPGRPLOT.OPER);

							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					// D12 2번
					//그룹ID를 채번한다.   
					memset(s_group_id, ' ', sizeof(s_group_id));
					gen_in_node = TRS.add_node(in_node, "gen_in_node");
					TRS.add_char(gen_in_node, "PROCSTEP", '2');
					CopyDefaultMembers(gen_in_node, in_node);
					TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_GROUP_ID, strlen(MP_ID_ROLE_WIP_GROUP_ID));
					TRS.add_nstring(gen_in_node, "OPER", "D12");
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

					DBU_init_cwipgrpsts(&CWIPGRPSTS_D12_2);
					TRS.copy(CWIPGRPSTS_D12_2.FACTORY, sizeof(CWIPGRPSTS_D12_2.FACTORY), in_node, IN_FACTORY);
					memcpy(CWIPGRPSTS_D12_2.GROUP_ID, s_group_id, sizeof(CWIPGRPSTS_D12_2.GROUP_ID));
					memcpy(CWIPGRPSTS_D12_2.GROUP_TYPE, "D12       ", strlen("D12       "));

					TRS.copy(CWIPGRPSTS_D12_2.CREATE_USER_ID, sizeof(CWIPGRPSTS_D12_2.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPGRPSTS_D12_2.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPSTS_D12_2.CREATE_TIME));

					DBU_insert_cwipgrpsts(&CWIPGRPSTS_D12_2);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPSTS_D12_1 Insert", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
						TRS.add_fieldmsg(out_node, "GROUP_TYPE", DT_STRING, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);
						TRS.add_fieldmsg(out_node, "CAR", DT_STRING, sizeof(CWIPGRPSTS.CAR), CWIPGRPSTS.CAR);
						TRS.add_fieldmsg(out_node, "CELL_HEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_HEIGHT);
						TRS.add_fieldmsg(out_node, "CELL_WEIGHT", DT_DOUBLE, CWIPGRPSTS.CELL_WEIGHT);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					DBU_init_cwipgrplot(&CWIPGRPLOT);
					memcpy(CWIPGRPLOT.FACTORY, CWIPGRPSTS.FACTORY, sizeof(CWIPGRPLOT.FACTORY));
					memcpy(CWIPGRPLOT.GROUP_ID, CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO));
					memcpy(CWIPGRPLOT.LOT_ID, s_group_id, strlen(s_group_id));
					DBU_select_cwipgrplot(1, &CWIPGRPLOT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						CWIPGRPLOT.MAPPING_SEQ = 2;
						memcpy(CWIPGRPLOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPGRPLOT.AREA_ID));
						memcpy(CWIPGRPLOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPGRPLOT.SUB_AREA_ID));
						memcpy(CWIPGRPLOT.OPER, "OC03150   ", strlen("OC03150   "));

						TRS.copy(CWIPGRPLOT.CREATE_USER_ID, sizeof(CWIPGRPLOT.CREATE_USER_ID), in_node, IN_USERID);
						memcpy(CWIPGRPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT.CREATE_TIME));

						DBU_insert_cwipgrplot(&CWIPGRPLOT);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPLOT Insert", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
							TRS.add_fieldmsg(out_node, "MAPPING_SEQ", DT_INT, CWIPGRPLOT.MAPPING_SEQ);
							TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
							TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.AREA_ID), CWIPGRPLOT.AREA_ID);
							TRS.add_fieldmsg(out_node, "SUB_AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.SUB_AREA_ID), CWIPGRPLOT.SUB_AREA_ID);
							TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPGRPLOT.OPER), CWIPGRPLOT.OPER);

							TRS.add_dberrmsg(out_node, DB_error_msg);

							return MP_FALSE;
						}
					}

					DB_commit();
                }	

				// 일단 1번으로 검색해서 count 가 2면 2번으로 검색하자.
				// CELL 번호와 MAPPING SEQ 1에 있는 LOT_ID 를 찾아서
				// 그걸로 다시 CWIPGRPLOT GROUP_ID 로 등록된 건수를 조회해서 2건 이상이면 다음 SEQ LOT_ID 를 찾아서 다시 재조회 한다.

				DBU_init_cwipgrplot(&CWIPGRPLOT);
				memcpy(CWIPGRPLOT.FACTORY, CWIPGRPSTS.FACTORY, sizeof(CWIPGRPLOT.FACTORY));
				memcpy(CWIPGRPLOT.GROUP_ID, CT_PRD200T.CELL_NO, sizeof(CT_PRD200T.CELL_NO));
				CWIPGRPLOT.MAPPING_SEQ = i_mapping_seq;
				DBU_select_cwipgrplot(4, &CWIPGRPLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0643");
					TRS.add_fieldmsg(out_node, "CWIPGRPLOT SELECT 4", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
					TRS.add_fieldmsg(out_node, "MAPPING_SEQ", DT_INT, CWIPGRPLOT.MAPPING_SEQ);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
				
				DBU_init_cwipgrplot(&CWIPGRPLOT_GRP);
				memcpy(CWIPGRPLOT_GRP.FACTORY, CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT_GRP.FACTORY));
				memcpy(CWIPGRPLOT_GRP.GROUP_ID, CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT_GRP.GROUP_ID));

				i_group_id_count = (int)DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT_GRP);
				if (i_group_id_count > 1)
				{
					CWIPGRPLOT.MAPPING_SEQ = ++i_mapping_seq;
					DBU_select_cwipgrplot(4, &CWIPGRPLOT);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0643");
						TRS.add_fieldmsg(out_node, "CWIPGRPLOT SELECT 4", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
						TRS.add_fieldmsg(out_node, "MAPPING_SEQ", DT_INT, CWIPGRPLOT.MAPPING_SEQ);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}

					memcpy(CWIPGRPLOT_GRP.GROUP_ID, CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT_GRP.GROUP_ID));
					i_group_id_count = (int)DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT_GRP);
					if (i_group_id_count > 1)
					{
						// WIP-0643 : CELL 정보에 속한 D12 그룹 ID에 더이상 등록할 수 없습니다.
						strcpy(s_msg_code, "WIP-0643");
						TRS.add_fieldmsg(out_node, "CWIPGRPLOT Select 4", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PRD200T.LOT_ID), CT_PRD200T.LOT_ID);
						TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PRD200T.CELL_NO), CT_PRD200T.CELL_NO);

						return MP_FALSE;
					}										
				}				

				DBU_init_cwipgrplot(&CWIPGRPLOT_LOT);
				memcpy(CWIPGRPLOT_LOT.FACTORY, CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT_LOT.FACTORY));
				memcpy(CWIPGRPLOT_LOT.GROUP_ID, CWIPGRPLOT_GRP.GROUP_ID, sizeof(CWIPGRPLOT_LOT.GROUP_ID));
				memcpy(CWIPGRPLOT_LOT.LOT_ID, CT_PRD200T.LOT_ID, sizeof(CT_PRD200T.LOT_ID));
				CWIPGRPLOT_LOT.MAPPING_SEQ = (int)DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT_LOT) + 1;


				memset(s_vendor_site_id, 0x00, sizeof(s_vendor_site_id));

				i_lot_seq = (int)DBU_select_cwipgrplot_scalar(4, &CWIPGRPLOT) + 1;
				COM_itoa_left(s_vendor_site_id, i_lot_seq, sizeof(s_vendor_site_id));				
				TRS.add_string(create_in_node, "LOT_CMF_2", s_vendor_site_id, sizeof(s_vendor_site_id));              // Group 순번

				memcpy(CWIPGRPLOT_LOT.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(CWIPGRPLOT_LOT.AREA_ID));
				memcpy(CWIPGRPLOT_LOT.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(CWIPGRPLOT_LOT.SUB_AREA_ID));
				memcpy(CWIPGRPLOT_LOT.OPER, "OC03140   ", strlen("OC03140   "));

				TRS.copy(CWIPGRPLOT_LOT.CREATE_USER_ID, sizeof(CWIPGRPLOT_LOT.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPGRPLOT_LOT.CREATE_TIME, gs_sys_time, sizeof(CWIPGRPLOT_LOT.CREATE_TIME));

				DBU_insert_cwipgrplot(&CWIPGRPLOT_LOT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPGRPLOT_LOT Insert", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
					TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
					TRS.add_fieldmsg(out_node, "MAPPING_SEQ", DT_INT, CWIPGRPLOT.MAPPING_SEQ);
					TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
					TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.AREA_ID), CWIPGRPLOT.AREA_ID);
					TRS.add_fieldmsg(out_node, "SUB_AREA_ID", DT_STRING, sizeof(CWIPGRPLOT.SUB_AREA_ID), CWIPGRPLOT.SUB_AREA_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPGRPLOT.OPER), CWIPGRPLOT.OPER);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}
        }

        if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

        memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

        DBU_init_mwiplothisx(&MWIPLOTHIS);
        TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
        MWIPLOTHIS.HIST_SEQ = 1;
        DBU_select_mwiplothisx(1, &MWIPLOTHIS);

        memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplothisx(1, &MWIPLOTHIS);
        /* 검사 요청을 제거
        if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
        {
            insp_in = TRS.add_node(in_node, "insp_in");
            TRS.add_char(insp_in, IN_PROCSTEP, '2');
            CopyDefaultMembers(insp_in, in_node);

            TRS.add_string(insp_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, insp_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }

            TRS.free_node(cmn_out);
        }
        */
    }
    // 반제품 창고의 경우
    else if (TRS.get_procstep(in_node) == '3')
    {
        // 반제품의 경우 동일 Lot이 두개 이상 존재의 가능성 있음.
        // 두번째 Lot 부터는 임시 Table에 저장한다.
        if (i_lot_db_error_code == DB_SUCCESS)
        {
            DBU_init_ct_mtl510t(&CT_MTL510T);
            memcpy(CT_MTL510T.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
            CT_MTL510T.LOT_SEQ = TRS.get_int(in_node, "LOT_SEQ");
            TRS.copy(CT_MTL510T.WH_CODE, sizeof(CT_MTL510T.WH_CODE), in_node, "WH_CODE");
            DBU_select_ct_mtl510t(1, &CT_MTL510T);
            if (DB_error_code == DB_SUCCESS)
            {
                DBU_init_cwipuoplot(&CWIPUOPLOT);
                memcpy(CWIPUOPLOT.LOT_ID, CT_MTL510T.LOT_ID, sizeof(CWIPUOPLOT.LOT_ID));
                CWIPUOPLOT.LOT_SEQ = CT_MTL510T.LOT_SEQ;
                memcpy(CWIPUOPLOT.WH_CODE, CT_MTL510T.WH_CODE, sizeof(CWIPUOPLOT.WH_CODE));
                memcpy(CWIPUOPLOT.MAT_ID, CT_MTL510T.ITEM_CODE, sizeof(CWIPUOPLOT.MAT_ID));
                memcpy(CWIPUOPLOT.ORG_CODE, CT_MTL510T.ORG_CODE, sizeof(CT_MTL510T.ORG_CODE));
                memcpy(CWIPUOPLOT.WC_CODE, CT_MTL510T.WC_CODE, sizeof(CWIPUOPLOT.WC_CODE));
                TRS.copy(CWIPUOPLOT.FACTORY, sizeof(CWIPUOPLOT.FACTORY), in_node, IN_FACTORY);
                CWIPUOPLOT.REMAIN_QTY = CT_MTL510T.REMAIN_QTY;
                CWIPUOPLOT.USE_YN = CT_MTL510T.USE_YN;
                TRS.copy(CWIPUOPLOT.CREATE_USER_ID, sizeof(CWIPUOPLOT.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPUOPLOT.CREATE_TIME, gs_sys_time, sizeof(CWIPUOPLOT.CREATE_TIME));

                DBU_insert_cwipuoplot(&CWIPUOPLOT);

                DB_commit();
            }
        }
        else
        {
            create_in_node = TRS.add_node(in_node, "Create_Lot_In");

            CopyDefaultMembers(create_in_node, in_node);
            TRS.add_char(create_in_node, IN_PROCSTEP, '1');

            TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
            TRS.add_nstring(create_in_node, "LOT_DESC", TRS.get_string(in_node, "REMARKS"));
            TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
            TRS.add_int(create_in_node, "MAT_VER", 1);
            TRS.add_char(create_in_node, "LOT_TYPE", 'P');
            TRS.add_string(create_in_node, "FLOW", MWIPMATFLW.FLOW, sizeof(MWIPMATFLW.FLOW));
            TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
            TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
            TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
            TRS.add_nstring(create_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));
            TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
            TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");

            DBU_init_mwipflwopr(&MWIPFLWOPR);
            memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
            memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPFLWOPR.FLOW));
            TRS.copy(MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER), in_node, "OPER");
            DBU_select_mwipflwopr(1, &MWIPFLWOPR);

            i_lot_db_error_code = DB_error_code;
            // P급 창고 인 경우.
            // 해당 제품의 첫번째 Flow에 공정이 없는 경우
            if(memcmp(MWIPOPRDEF.OPER_GRP_1, "LOSS", strlen("LOSS")) == 0 || i_lot_db_error_code == DB_NOT_FOUND)
            {
                DBU_init_mwipflwopr(&MWIPFLWOPR);
                memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
                memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPFLWOPR.FLOW));

                if(memcmp(MWIPOPRDEF.OPER_GRP_1, "LOSS", strlen("LOSS")) == 0)
                {
                    // P급 창고에 생성하는 Lot은 첫번째 Flow의 검사공정으로 생성한다.
                    i_sel = 6;
                }
                else if(i_lot_db_error_code == DB_NOT_FOUND)
                {
                    i_sel = 4;
                }

                DBU_select_mwipflwopr(i_sel, &MWIPFLWOPR);
                if (DB_error_code != DB_SUCCESS)
                {
                    if (DB_error_code == DB_NOT_FOUND)
                        // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                        strcpy(s_msg_code, "WIP-0599");
                    else
                    {
                        strcpy(s_msg_code, "WIP-00004");
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                    }

                    TRS.add_fieldmsg(out_node, "SELECT MWIPFLWOPR", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "CASE", DT_INT, i_sel);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

                    return MP_FALSE;
                }

                TRS.add_string(create_in_node, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
            }
            else
            {
                TRS.add_nstring(create_in_node, "OPER", TRS.get_string(in_node, "OPER"));
            }

            if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
                return MP_FALSE;

            DBU_init_mwiplotstsx(&MWIPLOTSTS);
            TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
            DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

            memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
            DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

            DBU_init_mwiplothisx(&MWIPLOTHIS);
            TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
            MWIPLOTHIS.HIST_SEQ = 1;
            DBU_select_mwiplothisx(1, &MWIPLOTHIS);

            memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
            DBU_update_mwiplothisx(1, &MWIPLOTHIS);

            // P급 창고 인 경우는 P급 창고 이동 처리한다.
            if(memcmp(MWIPOPRDEF.OPER_GRP_1, "LOSS", strlen("LOSS")) == 0)
            {
                DBU_init_mwipflwopr(&MWIPFLWOPR);
                memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
                TRS.copy(MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER), in_node, "OPER");

                DBU_select_mwipflwopr(7, &MWIPFLWOPR);
                if (DB_error_code != DB_SUCCESS)
                {
                    if (DB_error_code == DB_NOT_FOUND)
                        // WIP-0633 : Flow를 찾을 수 없습니다.
                        strcpy(s_msg_code, "WIP-0633");
                    else
                    {
                        strcpy(s_msg_code, "WIP-0004");
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                    }

                    TRS.add_fieldmsg(out_node, "SELECT MWIPFLWOPR 7", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPFLWOPR.OPER), MWIPFLWOPR.OPER);

                    return MP_FALSE;
                }

                move_in = TRS.add_node(in_node, "move_in");
                CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(move_in, "PROCSTEP", '1');
                TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
                TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
                TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }

                TRS.free_node(cmn_out);

                DBU_init_mwiplotstsx(&MWIPLOTSTS);
                TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
                DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				if (DB_error_code == DB_SUCCESS)
				{
					//WIP-0680 : 해당 Lot은 이미 P급 판정 진행중입니다.
					strcpy(s_msg_code, "WIP-0680");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

                //부외재고 리스트 테이블에 insert해준다. 
                DBU_init_cwiplotrec(&CWIPLOTREC);
                memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
                memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
                CWIPLOTREC.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
                memcpy(CWIPLOTREC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                memcpy(CWIPLOTREC.ORDER_ID, MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));

                //memcpy(CWIPLOTREC.INV_OPER, MWIPORDSTS.ORD_CMF_3, sizeof(CWIPLOTREC.INV_OPER));
                memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
                memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
                memcpy(CWIPLOTREC.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
                memcpy(CWIPLOTREC.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTREC.WORK_DATE));
                memcpy(CWIPLOTREC.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
                CWIPLOTREC.MAT_VER = MWIPLOTSTS.MAT_VER;
                memcpy(CWIPLOTREC.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                CWIPLOTREC.QTY = MWIPLOTSTS.QTY_1;
                memcpy(CWIPLOTREC.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CWIPLOTREC.CREATE_USER_ID, sizeof(CWIPLOTREC.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
                DBU_insert_cwiplotrec(&CWIPLOTREC);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPLOTREC INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPLOTREC.TRAN_OPER), CWIPLOTREC.TRAN_OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
            // 제품의 첫번째 Flow에 공정이 없을 경우 Store 처리한다.
            else if(i_lot_db_error_code == DB_NOT_FOUND)
            {


				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTS INSERT (Stock_Proc3)", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;

				/*
                store_in = TRS.add_node(in_node, "store_in");
                TRS.add_char(store_in, IN_PROCSTEP, '1');
                CopyDefaultMembers(store_in, in_node);

                TRS.add_nstring(store_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
                TRS.add_nstring(store_in, "TO_OPER", TRS.get_string(in_node, "OPER"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_STORE_LOT(s_msg_code, store_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }

                TRS.free_node(cmn_out);

				*/




            }
        }
    }
    //  제품(완제품 창고)
    else if(TRS.get_procstep(in_node) == '4')
    {
        /* 처리 순서
         1. Flow에서 마지막 공정 찾기
         2. 찾은 마지막 공정에 Lot을 생성
         3. 완제품 창고로 이동
        */
        DBU_init_mwipflwopr(&MWIPFLWOPR);

        memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
        memcpy(MWIPFLWOPR.FLOW, MWIPMATFLW.FLOW, sizeof(MWIPFLWOPR.FLOW));

        DBU_select_mwipflwopr(4, &MWIPFLWOPR);
        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if(DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

            return MP_FALSE;
        }

        create_in_node = TRS.add_node(in_node, "Create_Lot_In");

        CopyDefaultMembers(create_in_node, in_node);
        TRS.add_char(create_in_node, IN_PROCSTEP, '1');

        TRS.add_nstring(create_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
        TRS.add_nstring(create_in_node, "LOT_DESC", TRS.get_string(in_node, "REMARKS"));
        TRS.add_nstring(create_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
        TRS.add_int(create_in_node, "MAT_VER", 1);
        TRS.add_char(create_in_node, "LOT_TYPE", 'P');
        TRS.add_string(create_in_node, "FLOW", MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
        TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW.FLOW_SEQ_NUM);
        TRS.add_string(create_in_node, "OPER", MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
        TRS.add_double(create_in_node, "QTY_1", TRS.get_double(in_node, "QTY"));
        TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
        TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
        TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");

        if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        DBU_init_mwiplotstsx(&MWIPLOTSTS);
        TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

        memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

        DBU_init_mwiplothisx(&MWIPLOTHIS);
        TRS.copy(MWIPLOTHIS.LOT_ID, sizeof(MWIPLOTHIS.LOT_ID), in_node, "LOT_ID");
        MWIPLOTHIS.HIST_SEQ = 1;
        DBU_select_mwiplothisx(1, &MWIPLOTHIS);

        memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
        DBU_update_mwiplothisx(1, &MWIPLOTHIS);

		//완제품 창고 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		DBU_init_mwipflwopr(&MWIPFLWOPR_PROD);
		TRS.copy(MWIPFLWOPR_PROD.FACTORY, sizeof(MWIPFLWOPR_PROD.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPFLWOPR_PROD.OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
		DBU_select_mwipflwopr(5, &MWIPFLWOPR_PROD);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPFLWOPR SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR_PROD.FACTORY), MWIPFLWOPR_PROD.FACTORY);
			TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPFLWOPR_PROD.FLOW), MWIPFLWOPR_PROD.FLOW);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 완제품 창고로 MOVE
		move_in = TRS.add_node(in_node, "move_in");
		CopyDefaultMembers(move_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

		TRS.add_char(move_in, "PROCSTEP", '1');
		TRS.add_string(move_in, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		TRS.add_string(move_in, "TO_FLOW", MWIPFLWOPR_PROD.FLOW, sizeof(MWIPFLWOPR_PROD.FLOW));
		TRS.add_string(move_in, "TO_OPER", MWIPFLWOPR_PROD.OPER, sizeof(MWIPFLWOPR_PROD.OPER));
		TRS.add_string(move_in, "PREV_MAT_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
		TRS.add_string(move_in, "PREV_MAT_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
		TRS.add_char(move_in, "FROM_TO_FLAG", 'T');

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_WIP_MOVE_LOT_FORCE(s_msg_code, move_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);
    }
    // 출하대기 인 경우
    else if (TRS.get_procstep(in_node) == '5')
    {
        /* 처리 순서
          1. Mat ID의 사업부로 공정(출하대기 창고)을 찾음
          2. 찾은 공정으로 FLOW-OPER에서 FLOW 찾음.
          3. Mat ID의 첫번째 Flow, flow의 마지막 Oper 찾음
          4. 출하 Lot을 생성한다.(Create)(LOT_CMF_7 : 첫번째 FLOW, LOT_CMF_8 : 첫번재 FLOW의 마지막 공정, LOT_CMF_9 : 완제품 창고)
          5. CPAKORDSTS 데이터를 생성한다.
          6. CPAKLOTSTS 데이터를 생성한다.
        */

		memset(s_new_lot_id, ' ', sizeof(s_new_lot_id));

        // 사업부로 공정(출하대기 창고) 찾기
        memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
        memcpy(MWIPOPRDEF.AREA_ID, MWIPMATDEF.MAT_GRP_1, sizeof(MWIPOPRDEF.AREA_ID));
        MWIPOPRDEF.INV_FLAG = 'Y';
        memcpy(MWIPOPRDEF.OPER_GRP_1, "SHIP", strlen("SHIP"));

        DBU_select_mwipoprdef(7, &MWIPOPRDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0600 : 출하 대기 창고를 찾을 수 없습니다.
                strcpy(s_msg_code, "WIP-0600");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPOPRDEF Select 7", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
            TRS.add_fieldmsg(out_node, "INV_FLAG", DT_CHAR, MWIPOPRDEF.INV_FLAG);
            TRS.add_fieldmsg(out_node, "OPER_GRP_1", DT_STRING, sizeof(MWIPOPRDEF.OPER_GRP_1), MWIPOPRDEF.OPER_GRP_1);

            return MP_FALSE;
        }

		//AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
			return MP_FALSE;
		}

        // 찾은 공정(출하대기 창고)으로 FLOW-OPER에서 FLOW 찾음
        DBU_init_mwipflwopr(&MWIPFLWOPR_M);

        memcpy(MWIPFLWOPR_M.FACTORY, MWIPOPRDEF.FACTORY, sizeof(MWIPFLWOPR_M.FACTORY));
        memcpy(MWIPFLWOPR_M.OPER, MWIPOPRDEF.OPER, sizeof(MWIPFLWOPR_M.OPER));

        DBU_select_mwipflwopr(5, &MWIPFLWOPR_M);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 5", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR_M.FACTORY), MWIPFLWOPR_M.FACTORY);
            TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPFLWOPR_M.OPER), MWIPFLWOPR_M.OPER);

            return MP_FALSE;
        }

        // 첫번째 Flow의 마지막 공정 찾기
        DBU_init_mwipflwopr(&MWIPFLWOPR);

        memcpy(MWIPFLWOPR.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPFLWOPR.FACTORY));
        memcpy(MWIPFLWOPR.FLOW, s_first_flow, sizeof(MWIPFLWOPR.FLOW));
        DBU_select_mwipflwopr(4, &MWIPFLWOPR);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0599 : Flow에 공정이 설정이 안되어 있습니다.
                strcpy(s_msg_code, "WIP-0599");
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPFLWOPR Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);

            return MP_FALSE;
        }

        memcpy(s_last_oper, MWIPFLWOPR.OPER, sizeof(s_last_oper));

        // Flow의 Flow_SEQ_NUM 구하기
        DBU_init_mwipmatflw(&MWIPMATFLW_M);
        memcpy(MWIPMATFLW_M.FACTORY, MWIPMATFLW.FACTORY, sizeof(MWIPMATFLW_M.FACTORY));
        TRS.copy(MWIPMATFLW_M.MAT_ID, sizeof(MWIPMATFLW_M.MAT_ID), in_node, "MAT_ID");
        MWIPMATFLW_M.MAT_VER = 1;
        memcpy(MWIPMATFLW_M.FLOW, MWIPFLWOPR_M.FLOW, sizeof(MWIPMATFLW_M.FLOW));
        DBU_select_mwipmatflw(4, &MWIPMATFLW_M);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code == DB_NOT_FOUND)
                // WIP-0593 : 해당 제품은 Flow가 설정되지 않았습니다. 제품 셋업의 플로우 부여에서 설정하세요.
                strcpy(s_msg_code, "WIP-0593");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "MWIPMATFLW Select 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPMATFLW_M.FACTORY), MWIPMATFLW_M.FACTORY);
            TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPMATFLW_M.MAT_ID), MWIPMATFLW_M.MAT_ID);
            TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPMATFLW_M.MAT_VER);
            TRS.add_fieldmsg(out_node, "FLOW", DT_STRING, sizeof(MWIPMATFLW_M.FLOW), MWIPMATFLW_M.FLOW);

            return MP_FALSE;
        }

        //
        DBU_init_ct_packing_v(&CT_PACKING_V);
        TRS.copy(CT_PACKING_V.LOT_ID, sizeof(CT_PACKING_V.LOT_ID), in_node, "LOT_ID");
		CT_PACKING_V.LOT_SEQ = TRS.get_int(in_node, "LOT_SEQ");
        iCnt = (int)DBU_select_ct_packing_v_scalar(3, &CT_PACKING_V);

        if(iCnt == 0)
        {
            // 해당 출하 Lot은 출하대기 창고 존재하지 않습니다.
            strcpy(s_msg_code, "WIP-0606");
            return MP_FALSE;
        }

        // Legacy System에서 Packing Lot 구하기
        DBU_open_ct_packing_v(2, &CT_PACKING_V);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "CT_PACKING_V Open 2", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PACKING_V.LOT_ID), CT_PACKING_V.LOT_ID);
			TRS.add_fieldmsg(out_node, "LOT_SEQ", DT_INT, CT_PACKING_V.LOT_SEQ);

            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_ct_packing_v(2, &CT_PACKING_V);
            if(DB_error_code == DB_NOT_FOUND)
            {
				// 20.12.21 minjae.go
                //DBU_close_ct_sal110t(2);
				DBU_close_ct_packing_v(2);
				//
                break;
            }
            else if(DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0004");

                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "CT_PACKING_V Fetch 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CT_PACKING_V.LOT_ID), CT_PACKING_V.LOT_ID);
				TRS.add_fieldmsg(out_node, "LOT_SEQ", DT_INT, CT_PACKING_V.LOT_SEQ);

                DBU_close_ct_packing_v(2);

                return MP_FALSE;
            }

			if (CT_PACKING_V.TOTAL_QTY == 1)
			{
				memcpy(s_new_lot_id, CT_PACKING_V.LOT_ID, sizeof(CT_PACKING_V.LOT_ID));
			}
			else
			{
				// 무조건 새로운 ID 발번
				gen_in_node = TRS.add_node(in_node, "gen_in_node");
				TRS.add_char(gen_in_node, "PROCSTEP", '2');
				CopyDefaultMembers(gen_in_node, in_node);

				TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_SHP_LOT, strlen(MP_ID_ROLE_SPLIT_SHP_LOT));
				TRS.add_string(gen_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"), strlen(TRS.get_string(in_node, "LOT_ID")));

				cmn_out = TRS.create_node("cmn_out");
				if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					// 20.12.21 minjae.go
					DBU_close_ct_packing_v(2);
					//
					return MP_FALSE;
				}
				memcpy(s_new_lot_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

				TRS.free_node(cmn_out);
			}

			// 생산 Lot 생성
			create_in_node = TRS.add_node(in_node, "Create_Lot_In");

			CopyDefaultMembers(create_in_node, in_node);
			TRS.add_char(create_in_node, IN_PROCSTEP, '1');

			TRS.add_string(create_in_node, "LOT_ID", s_new_lot_id, sizeof(s_new_lot_id));
			TRS.add_string(create_in_node, "LOT_DESC", CT_PACKING_V.REMARKS, sizeof(CT_PACKING_V.REMARKS));
			TRS.add_string(create_in_node, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			TRS.add_int(create_in_node, "MAT_VER", MWIPMATDEF.MAT_VER);
			TRS.add_char(create_in_node, "LOT_TYPE", 'P');
			TRS.add_string(create_in_node, "FLOW", MWIPFLWOPR_M.FLOW, sizeof(MWIPFLWOPR_M.FLOW));
			TRS.add_int(create_in_node, "FLOW_SEQ_NUM", MWIPMATFLW_M.FLOW_SEQ_NUM);
			TRS.add_string(create_in_node, "OPER", MWIPFLWOPR_M.OPER, sizeof(MWIPFLWOPR_M.OPER));
			TRS.add_double(create_in_node, "QTY_1", CT_PACKING_V.LABEL_QTY);
			TRS.add_char(create_in_node, "LOT_PRIORITY", '1');
			TRS.add_nstring(create_in_node, "CREATE_CODE", "PROD");
			TRS.add_nstring(create_in_node, "OWNER_CODE", "PROD");
			TRS.add_string(create_in_node, "LOT_CMF_7", s_first_flow, sizeof(s_first_flow)); // 제품의 첫번째 Flow
			TRS.add_string(create_in_node, "LOT_CMF_8", s_last_oper, sizeof(s_last_oper)); // 제품의 첫번째 Flow의 마지막 공정
			TRS.add_nstring(create_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "LOT_ID")); // 제품의 첫번째 Flow의 마지막 공정
																						   // 사업부로 공정(완제품 창고) 찾기
			memcpy(MWIPOPRDEF.FACTORY, MWIPMATDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
			memcpy(MWIPOPRDEF.AREA_ID, MWIPMATDEF.MAT_GRP_1, sizeof(MWIPOPRDEF.AREA_ID));
			MWIPOPRDEF.INV_FLAG = 'Y';
			memcpy(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_PROD, strlen(MP_OPER_GRP_TYPE_PROD));

			DBU_select_mwipoprdef(7, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
					// WIP-0604 : 완제품 창고를 찾을 수 없습니다.
					strcpy(s_msg_code, "WIP-0604");
				else
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF Select 7", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
				TRS.add_fieldmsg(out_node, "INV_FLAG", DT_CHAR, MWIPOPRDEF.INV_FLAG);
				TRS.add_fieldmsg(out_node, "OPER_GRP_1", DT_STRING, sizeof(MWIPOPRDEF.OPER_GRP_1), MWIPOPRDEF.OPER_GRP_1);

				DBU_close_ct_packing_v(2);

				return MP_FALSE;
			}

			TRS.add_string(create_in_node, "LOT_CMF_9", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

			if (CUS_WIP_CREATE_LOT(s_msg_code, create_in_node, out_node) == MP_FALSE)
			{
				// 20.12.21 minjae.go
				DBU_close_ct_packing_v(2);
				//
				return MP_FALSE;
			}
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			memcpy(MWIPLOTSTS.LOT_ID, s_new_lot_id, sizeof(s_new_lot_id));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);

			memcpy(MWIPLOTSTS.ADD_ORDER_ID_1, "MIG", 3);
			DBU_update_mwiplotstsx(1, &MWIPLOTSTS);

			DBU_init_mwiplothisx(&MWIPLOTHIS);
			memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			MWIPLOTHIS.HIST_SEQ = 1;
			DBU_select_mwiplothisx(1, &MWIPLOTHIS);

			memcpy(MWIPLOTHIS.ADD_ORDER_ID_1, "MIG", 3);
			DBU_update_mwiplothisx(1, &MWIPLOTHIS);

			DBU_init_cpakordsts(&CPAKORDSTS);
			TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
			COM_itoa_left(CPAKORDSTS.PACK_ORDER_ID, CT_PACKING_V.HEADER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID));
			CPAKORDSTS.LINE_NO = CT_PACKING_V.LINE_NUMBER;
			DBU_select_cpakordsts(1, &CPAKORDSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0635 : 주문지시 정보가 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0635");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", DT_STRING, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", DT_INT, CPAKORDSTS.LINE_NO);

				DBU_close_ct_packing_v(2);

				return MP_FALSE;
			}

			DBU_init_cpaklotsts(&CPAKLOTSTS);
			memcpy(CPAKLOTSTS.FACTORY, MWIPOPRDEF.FACTORY, sizeof(CPAKLOTSTS.FACTORY));

			if (COM_isnullspace(CT_PACKING_V.LOT_ADD) == MP_TRUE)
			{
				TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), in_node, "LOT_ID");
			}
			else
			{
				memcpy(CPAKLOTSTS.ORG_LOT_ID, CT_PACKING_V.LOT_ADD, sizeof(CPAKLOTSTS.ORG_LOT_ID));
			}
			
			memcpy(CPAKLOTSTS.PACK_LOT_ID, MWIPLOTSTS.LOT_ID, strlen(MWIPLOTSTS.LOT_ID));
			memcpy(CPAKLOTSTS.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
			CPAKLOTSTS.MAT_VER = MWIPMATDEF.MAT_VER;
			CPAKLOTSTS.QTY = CT_PACKING_V.LABEL_QTY;

			if (MGCMTBLDAT.DATA_4[0] == 'Y')
			{
				if (memcmp(CPAKORDSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1)) != 0)
				{
					if (COM_isspace(MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5)) == MP_FALSE)
					{
						memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5));
					}
					else
					{
						memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					}
				}
				else
				{
					memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				}
			}
			else
			{
				memcpy(CPAKLOTSTS.UNIT, MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
			}

			CPAKLOTSTS.PACK_FLAG = 'Y';
			memcpy(CPAKLOTSTS.PACK_DATE, CT_PACKING_V.CONFIRM_DATE, sizeof(CT_PACKING_V.CONFIRM_DATE));
			COM_itoa_left(CPAKLOTSTS.PACK_ORDER_ID, CT_PACKING_V.HEADER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID));
			CPAKLOTSTS.PACK_LINE_NO = CT_PACKING_V.LINE_NUMBER;
			CPAKLOTSTS.SHIP_FLAG = 'N';
			memset(CPAKLOTSTS.SHIP_DATE, ' ', sizeof(CPAKLOTSTS.SHIP_DATE));
			memset(CPAKLOTSTS.SHIP_ORDER_ID, ' ', sizeof(CPAKLOTSTS.SHIP_ORDER_ID));
			CPAKLOTSTS.SHIP_ORDER_SEQ = 0;
			CPAKLOTSTS.RET_FLAG = 'N';
			CPAKLOTSTS.RETURNED_QTY = 0;
			memset(CPAKLOTSTS.BOX_ID_1, ' ', sizeof(CPAKLOTSTS.BOX_ID_1));
			memset(CPAKLOTSTS.BOX_ID_2, ' ', sizeof(CPAKLOTSTS.BOX_ID_2));
			memset(CPAKLOTSTS.BOX_ID_3, ' ', sizeof(CPAKLOTSTS.BOX_ID_3));
			COM_dtoa(CPAKLOTSTS.CMF_1, CT_PACKING_V.COATING_RATE, sizeof(CPAKLOTSTS.CMF_1));
			TRS.copy(CPAKLOTSTS.CMF_2, sizeof(CPAKLOTSTS.CMF_2), in_node, "LOT_ID");
			COM_itoa_left(CPAKLOTSTS.CMF_3, CT_PACKING_V.LOT_SEQ, sizeof(CPAKLOTSTS.CMF_3));
			COM_itoa_left(CPAKLOTSTS.CMF_4, CT_PACKING_V.IF_SEQ, sizeof(CPAKLOTSTS.CMF_4));
			memset(CPAKLOTSTS.CMF_5, ' ', sizeof(CPAKLOTSTS.CMF_5));
			memset(CPAKLOTSTS.CMF_6, ' ', sizeof(CPAKLOTSTS.CMF_6));
			memset(CPAKLOTSTS.CMF_7, ' ', sizeof(CPAKLOTSTS.CMF_7));
			memset(CPAKLOTSTS.CMF_8, ' ', sizeof(CPAKLOTSTS.CMF_8));
			memset(CPAKLOTSTS.CMF_9, ' ', sizeof(CPAKLOTSTS.CMF_9));
			memset(CPAKLOTSTS.CMF_10, ' ', sizeof(CPAKLOTSTS.CMF_10));

			TRS.copy(CPAKLOTSTS.CREATE_USER_ID, sizeof(MWIPMATDEF.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.CREATE_TIME, gs_sys_time, sizeof(CPAKLOTSTS.CREATE_TIME));
			TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(MWIPMATDEF.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKLOTSTS.UPDATE_TIME, gs_sys_time, sizeof(CPAKLOTSTS.UPDATE_TIME));

			DBU_insert_cpaklotsts(&CPAKLOTSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "CPAKLOTSTS Insert", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORG_LOT_ID", DT_STRING, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
				TRS.add_fieldmsg(out_node, "PACK_LOT_ID", DT_STRING, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
				TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CPAKLOTSTS.MAT_ID), CPAKLOTSTS.MAT_ID);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", DT_STRING, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);

				DBU_close_ct_packing_v(2);

				return MP_FALSE;
			}

			//포장 등록 및 완료 수량 증가
			CPAKORDSTS.PACKED_QTY += CPAKLOTSTS.QTY;
			CPAKORDSTS.REG_QTY += CPAKLOTSTS.QTY;

			// CPAKORDSTS - 주문 수량과 포장완료 수량이 같으면 상태 PACKED
			if (CPAKORDSTS.PACKED_QTY == CPAKORDSTS.QTY)
			{
				memcpy(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_PACKED, sizeof(CPAKORDSTS.PACK_ORD_STATUS));
			}

			memcpy(CPAKORDSTS.PACK_DATE, CT_PACKING_V.CONFIRM_DATE, sizeof(CT_PACKING_V.CONFIRM_DATE));
			TRS.copy(CPAKORDSTS.UPDATE_USER_ID, sizeof(CPAKORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CPAKORDSTS.UPDATE_TIME, gs_sys_time, sizeof(CPAKORDSTS.UPDATE_TIME));
			DBU_update_cpakordsts(1, &CPAKORDSTS);

			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_dberrmsg(out_node, DB_error_msg);

				TRS.add_fieldmsg(out_node, "CPAKORDSTS UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", DT_STRING, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
				TRS.add_fieldmsg(out_node, "LINE_NO", DT_INT, CPAKORDSTS.LINE_NO);
				
				DBU_close_ct_packing_v(2);

				return MP_FALSE;
			}
        }
    }
	// 금형
	else if (TRS.get_procstep(in_node) == '6')
	{
		DBU_init_ct_mold_v(&CT_MOLD_V);
		TRS.copy(CT_MOLD_V.LOT_ID, sizeof(CT_MOLD_V.LOT_ID), in_node, "LOT_ID");
		iCnt = (int)DBU_select_ct_mold_v_scalar(2, &CT_MOLD_V);

		if (iCnt == 0)
		{
			// WIP-0644 : 해당 금형 자재 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "WIP-0644");
			return MP_FALSE;
		}

		DBU_select_ct_mold_v(1, &CT_MOLD_V);

		// 금형 (자재 + 툴)
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code == DB_SUCCESS)
		{
			// INV-0048 : 이 자재 Lot은 이미 존재합니다.
			strcpy(s_msg_code, "INV-0048");
			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT 1", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			return MP_FALSE;
		}
		else if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_dberrmsg(out_node, DB_error_msg);

			TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT 1", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INV_LOT_ID", DT_STRING, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

			return MP_FALSE;
		}

		// 자재 정보 생성
		create_in_node = TRS.add_node(in_node, "Create_Lot_In");
		CopyDefaultMembers(create_in_node, in_node);
		TRS.add_char(create_in_node, IN_PROCSTEP, '3');

		inv_lot = TRS.add_node(create_in_node, "INV_LOT_LIST");
		TRS.add_nstring(inv_lot, "INV_LOT_ID", TRS.get_string(in_node, "LOT_ID"));
		TRS.add_nstring(inv_lot, "INV_LOT_DESC", TRS.get_string(in_node, "REMARKS"));
		TRS.add_nstring(inv_lot, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
		TRS.add_nstring(inv_lot, "OPER", TRS.get_string(in_node, "OPER"));
		TRS.add_double(inv_lot, "QTY", TRS.get_double(in_node, "QTY"));
		TRS.add_nstring(inv_lot, "VENDOR_ID", TRS.get_string(in_node, "VENDOR_ID"));
		TRS.add_nstring(inv_lot, "VENDOR_SITE_ID", TRS.get_string(in_node, "VENDOR_SITE_ID"));
		TRS.add_nstring(inv_lot, "VENDOR_LOT_ID", TRS.get_string(in_node, "VENDOR_LOT_ID"));
		TRS.add_string(inv_lot, "MOLD_MODEL", CT_MOLD_V.DA_MODELS, sizeof(CT_MOLD_V.DA_MODELS));
		TRS.add_string(inv_lot, "MOLD_TYPE", CT_MOLD_V.DA_TYPE, sizeof(CT_MOLD_V.DA_TYPE));
		TRS.add_nstring(inv_lot, "IN_TYPE", "MIG");

		if (CUS_INV_CREATE_LOT_MAIN(s_msg_code, create_in_node, out_node) == MP_FALSE)
			return MP_FALSE;

		//TOOL 정보 조회
		DBU_init_mrastoldef(&MRASTOLDEF);
		TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), in_node, "LOT_ID");

		DBU_select_mrastoldef(1, &MRASTOLDEF);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

		// TOOL 정보 존재하지 않으면 TOOL 생성
		if (DB_error_code == DB_NOT_FOUND)
		{
			tool_in = TRS.add_node(in_node, "tool_in");
			TRS.add_char(tool_in, IN_PROCSTEP, 'I');
			CopyDefaultMembers(tool_in, in_node);

			TRS.add_string(tool_in, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			TRS.add_nstring(tool_in, "TOOL_DESC", MWIPMATDEF.MAT_DESC);
			TRS.add_string(tool_in, "TOOL_GRP", CT_MOLD_V.DA_MODELS, sizeof(CT_MOLD_V.DA_MODELS));
			TRS.add_string(tool_in, "TOOL_TYPE", CT_MOLD_V.DA_TYPE, sizeof(CT_MOLD_V.DA_TYPE));
			TRS.add_string(tool_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			TRS.add_string(tool_in, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			TRS.add_string(tool_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_nstring(tool_in, "VENDOR_ID", TRS.get_string(in_node, "VENDOR_ID"));
			TRS.add_nstring(tool_in, "TOOL_COMMENT", TRS.get_string(in_node, "TRAN_COMMENT"));

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}

		// 금형 (자재 + 툴)
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
		DBU_select_minvlotsts(1, &MINVLOTSTS);

		//TOOL 정보 조회
		DBU_init_mrastoldef(&MRASTOLDEF);
		TRS.copy(MRASTOLDEF.FACTORY, sizeof(MRASTOLDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID), in_node, "LOT_ID");

		DBU_select_mrastoldef(1, &MRASTOLDEF);
		if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
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

		memcpy(MRASTOLDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MRASTOLDEF.MAT_ID));
		MRASTOLDEF.MAT_VER = MINVLOTSTS.MAT_VER;
		memcpy(MRASTOLDEF.OPER, MINVLOTSTS.OPER, sizeof(MRASTOLDEF.OPER));

		DBU_update_mrastoldef(1, &MRASTOLDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASTOLDEF UPDATE ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(MRASTOLDEF.TOOL_ID), MRASTOLDEF.TOOL_ID);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MRASTOLDEF.MAT_ID), MRASTOLDEF.MAT_ID);
			TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, sizeof(MRASTOLDEF.MAT_VER), MRASTOLDEF.MAT_VER);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MRASTOLDEF.OPER), MRASTOLDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// TOOL EVENT 생성
		DBU_init_mrastevdef(&MRASTEVDEF);
		TRS.copy(MRASTEVDEF.FACTORY, sizeof(MRASTEVDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASTEVDEF.TOOL_TYPE, MRASTOLDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));

		DBU_open_mrastevdef(2, &MRASTEVDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASTEVDEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		while (1)
		{
			DBU_fetch_mrastevdef(2, &MRASTEVDEF);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_mrastevdef(2);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "RAS-0004");
				TRS.add_fieldmsg(out_node, "MRASTEVDEF FETCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASTEVDEF.FACTORY), MRASTEVDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TOOL_TYPE", MP_STR, sizeof(MRASTEVDEF.TOOL_TYPE), MRASTEVDEF.TOOL_TYPE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_mrastevdef(2);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//TOOL EVENT 셋업
			tool_event_in = TRS.add_node(in_node, "tool_event_in");
			TRS.add_char(tool_event_in, IN_PROCSTEP, 'I');
			CopyDefaultMembers(tool_event_in, in_node);

			TRS.add_string(tool_event_in, "TOOL_ID", MRASTOLDEF.TOOL_ID, sizeof(MRASTOLDEF.TOOL_ID));
			TRS.add_string(tool_event_in, "TOOL_TYPE", MRASTEVDEF.TOOL_TYPE, sizeof(MRASTEVDEF.TOOL_TYPE));
			TRS.add_string(tool_event_in, "TOOL_EVENT_ID", MRASTEVDEF.TOOL_EVENT_ID, sizeof(MRASTEVDEF.TOOL_EVENT_ID));

			cmn_out = TRS.create_node("Cmn_Out");
			if (RAS_UPDATE_TOOL_EVENT_RELATION(s_msg_code, tool_event_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				// 20.12.21 minjae.go
				DBU_close_mrastevdef(2);
				//
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}
	}

    return MP_TRUE;
}
