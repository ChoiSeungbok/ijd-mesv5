/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_split_lot.c
Description : Tran split Lot function

MES Version : 5.0

Function List
-

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

int CUS_WIP_Split_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Split_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Split_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Split_Lot()
- Tran split Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_SPLIT_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Split_Lot", out_node);
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
CUS_WIP_SPLIT_LOT()
- Main sub function of "CUS_WIP_Split_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_SPLIT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTS_TAG MWIPLOTSTS;
    TRSNode *split_in_node;
    struct work_date_tag work_date;
    char s_factory[10];
    int i = 0;
    int j = 0;
    char s_member[5][101] = { "LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_" };
    char s_member_name[101];

    LOG_head("CUS_WIP_Split_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (CUS_WIP_Split_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    // 1) LOT MASTER
    DBC_init_mwiplotsts(&MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
    DBC_select_mwiplotsts(1, &MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_fieldmsg(out_node, "[QUERY] MWIPLOTSTS SELECT(1) ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTS.FACTORY), MWIPLOTSTS.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(s_factory, &work_date);

    // 2) LOT SPLIT 
    split_in_node = TRS.add_node(in_node, "split_in_node");

    TRS.add_char(split_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(split_in_node, in_node); 

    TRS.add_string(split_in_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
    TRS.add_string(split_in_node, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_int(split_in_node, "MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(split_in_node, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_string(split_in_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    TRS.add_string(split_in_node, "RES_ID", MWIPLOTSTS.START_RES_ID, sizeof(MWIPLOTSTS.START_RES_ID));
    TRS.add_int(split_in_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);

    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(split_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(split_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));


    TRS.add_char(split_in_node, "NO_AUTOMATIC_TERMINATE_LOT", TRS.get_char(in_node, "NO_AUTOMATIC_TERMINATE_LOT"));

    TRS.add_double(split_in_node, "MOVE_QTY_1", TRS.get_double(in_node, "MOVE_QTY_1"));
    TRS.add_nstring(split_in_node, "CHILD_LOT_ID", TRS.get_string(in_node, "CHILD_LOT_ID"));
    TRS.add_nstring(split_in_node, "CHILD_LOT_DESC", TRS.get_string(in_node, "CHILD_LOT_DESC"));

    if (COM_isnullspace(TRS.get_string(in_node, "CHILD_MAT_ID")) == MP_FALSE)
        TRS.add_nstring(split_in_node, "CHILD_MAT_ID", TRS.get_string(in_node, "CHILD_MAT_ID"));
    else
        TRS.add_string(split_in_node, "CHILD_MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));

    TRS.add_int(split_in_node, "CHILD_MAT_VER", MWIPLOTSTS.MAT_VER);
    TRS.add_string(split_in_node, "CHILD_FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
    TRS.add_int(split_in_node, "CHILD_FLOW_SEQ_NUM", MWIPLOTSTS.FLOW_SEQ_NUM);
    TRS.add_string(split_in_node, "CHILD_OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
    TRS.add_string(split_in_node, "CHILD_CREATE_CODE", MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));
    TRS.add_string(split_in_node, "CHILD_OWNER_CODE", MWIPLOTSTS.OWNER_CODE, sizeof(MWIPLOTSTS.OWNER_CODE));
    TRS.add_string(split_in_node, "CHILD_DUE_TIME", MWIPLOTSTS.ORG_DUE_TIME, sizeof(MWIPLOTSTS.ORG_DUE_TIME));
    TRS.add_char(split_in_node, "CHILD_LOT_TYPE", MWIPLOTSTS.LOT_TYPE);
    TRS.add_char(split_in_node, "CHILD_PRIORITY", MWIPLOTSTS.LOT_PRIORITY);
    TRS.add_char(split_in_node, "RWK_FLAG", TRS.get_char(in_node, "RWK_FLAG"));
    TRS.add_nstring(split_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));    

    TRS.add_string(split_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(split_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(split_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(split_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_char(split_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
    TRS.add_char(split_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
    TRS.add_char(split_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
    TRS.add_char(split_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
    TRS.add_char(split_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
    TRS.add_nstring(split_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
    TRS.add_nstring(split_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
    TRS.add_nstring(split_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
    TRS.add_nstring(split_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
    TRS.add_nstring(split_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));

    TRS.add_double(split_in_node, "PRE_QTY_1", TRS.get_double(in_node, "PRE_QTY_1"));   //split 전 모랏의 총 수량

	TRS.add_char(split_in_node, "SKIP_BY_LOSS", TRS.get_char(in_node, "SKIP_BY_LOSS")); //Loss에 의한 Split은 검사공정에서 벨리데이션 걸지 않음.





    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 20; i++)
        {
            sprintf(s_member_name, "%s%d", s_member[j], i + 1);
            TRS.add_nstring(split_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
        }
    }

    if (CUS_WIP_Split_Lot_Before_Transaction(s_msg_code, 0, split_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_SPLIT_LOT(s_msg_code, split_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Split_Lot_After_Transaction(s_msg_code, 0, split_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Split_Lot_Validation()
- Validation Check sub function of "CUS_WIP_SPLIT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;
	double d_pack_qty = 0;

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code, in_node, out_node, TRS.get_procstep(in_node), "12") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "CHILD_LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "CHILD_LOT_ID", MP_NVST);

        return MP_FALSE;
    }

	// PROCSTEP(1) : SPLIT -> 생산 SPLIT은 해당 Validation 필요. -> ex) LOT 수량(100), 포장 예정 수량(40)일 경우, 100 - 40 = 60개의 수량에 한해서만 분할 가능.									
	// PROCSTEP(2) : 출하 LOT 생성을 위한 SPLIT
	if (TRS.get_procstep(in_node) == '1')
	{
		//모lot 조회
		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
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

		DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
		TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS_COUNT.ORG_LOT_ID, sizeof(CPAKLOTSTS_COUNT.ORG_LOT_ID), in_node, "LOT_ID");
		d_pack_qty = DBU_select_cpaklotsts_scalar(25, &CPAKLOTSTS_COUNT);

		if (MWIPLOTSTSX.QTY_1 - d_pack_qty < TRS.get_double(in_node, "MOVE_QTY_1"))
		{
			//WIP-0622 : 해당 Lot은 포장 진행중입니다. 분할 수량은 포장 후 남는 수량을 초과합니다. 포장 정보를 확인해주세요.
			strcpy(s_msg_code, "WIP-0622");
			TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
			TRS.add_fieldmsg(out_node, "QTY", MP_DBL, MWIPLOTSTSX.QTY_1);
			TRS.add_fieldmsg(out_node, "PACKING_QTY", MP_DBL, d_pack_qty);
			TRS.add_fieldmsg(out_node, "MOVE_QTY", MP_DBL, TRS.get_double(in_node, "MOVE_QTY_1"));
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Split_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_SPLIT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPOPRDEF_TAG   MWIPOPRDEF;

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


	if (TRS.get_char(in_node, "SKIP_BY_LOSS") != 'Y')
	{

		if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
			memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
		{

            //절단품 검사는 분할이 가능하도록 ...문제되는경우 있을거 같기는 한데.. 일단 요청에 의해 변경(20240315)
            if (memcmp(MWIPOPRDEF.OPER, "OC06020", strlen("OC06020")) != MP_FALSE) {

                //WIP-0677 : 검사공정은 SPLIT 처리를 할 수 없습니다.
                strcpy(s_msg_code, "WIP-0677");
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;

            }


		}
	}


    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Split_Lot_After_Transaction()
- Main sub function of "CUS_WIP_SPLIT_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Split_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX_SPLIT;
    struct CWIPLOTTRC_TAG   CWIPLOTTRC;
    struct MWIPOPRDEF_TAG   MWIPOPRDEF;
    struct CQCMISPSTS_TAG   CQCMISPSTS;


    TRSNode* insp_in;
    TRSNode* cmn_out;

    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    //모lot 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
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


    //split 된 자lot 조회
    DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
    TRS.copy(MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), in_node, "CHILD_LOT_ID");
    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
    if (DB_error_code != DB_SUCCESS)
    { 
        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        strcpy(s_msg_code, "WIP-0044");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.FACTORY), MWIPLOTSTSX_SPLIT.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    // 공정 조회
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

    //LOT 추적 테이블에 저장
    DBU_init_cwiplottrc(&CWIPLOTTRC);
    TRS.copy(CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY), in_node, IN_FACTORY);    
    memcpy(CWIPLOTTRC.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
    memcpy(CWIPLOTTRC.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
    memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));
    CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX_SPLIT.LAST_ACTIVE_HIST_SEQ;
    memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
	memcpy(CWIPLOTTRC.TRAN_CODE, MWIPLOTSTSX.LAST_TRAN_CODE, sizeof(MWIPLOTSTSX.LAST_TRAN_CODE));
    DBU_insert_cwiplottrc(&CWIPLOTTRC);
    if (DB_error_code != DB_SUCCESS)
    {
        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        strcpy(s_msg_code, "ADM-0004");
        TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
        TRS.add_fieldmsg(out_node, "FROM_LOT_ID", MP_STR, sizeof(CWIPLOTTRC.FROM_LOT_ID), CWIPLOTTRC.FROM_LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }



    //검사 공정에 대한 분할은 막았으나.. 절단검사에서 분할해야되는 경우 발생(문제가 있을수...있을거 같은데..일단 풀고 가능하게 바꿈_20240315)
    if (TRS.get_char(in_node, "SKIP_BY_LOSS") != 'Y')
    {
        if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_OQC, strlen(MP_INSP_OPER_TYPE_OQC)) == MP_FALSE ||
            memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_PQC, strlen(MP_INSP_OPER_TYPE_PQC)) == MP_FALSE)
        {

            //분할된 LOT에 대해서 검사 요청 
            insp_in = TRS.add_node(in_node, "insp_in");
            TRS.add_char(insp_in, IN_PROCSTEP, '2');
            CopyDefaultMembers(insp_in, in_node);

            TRS.add_string(insp_in, "LOT_ID", MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_QCM_CREATE_INSPECTION_REQUEST(s_msg_code, insp_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }

            TRS.free_node(cmn_out);




            //기존 검사 요청 정보 수량 수정
            DBU_init_cqcmispsts(&CQCMISPSTS);
            TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
            //TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
            memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
            DBU_select_cqcmispsts(1, &CQCMISPSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    strcpy(s_msg_code, "QCM-0050");
                }
                else
                {
                    strcpy(s_msg_code, "WIP-0004");
                }
                TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            CQCMISPSTS.QTY = MWIPLOTSTSX.QTY_1;
            memcpy(CQCMISPSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
            TRS.copy(CQCMISPSTS.UPDATE_USER_ID, sizeof(CQCMISPSTS.UPDATE_USER_ID), in_node, IN_USERID);
            DBU_update_cqcmispsts(1, &CQCMISPSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "QCM-0004");
                TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }





        }
    }


    return MP_TRUE;
}