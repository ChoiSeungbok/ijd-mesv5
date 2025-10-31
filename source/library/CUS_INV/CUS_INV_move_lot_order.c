/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_move_lot_order.c
Description : 이동 지시 등록/확인

MES Version : 5.0

Function List
- step 1: 이동지시 등록
- step 2: 이동지시 확정

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/12  Miracom        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/


#include "CUS_common.h"
#include "CUS_INV_common.h"

int CUS_INV_Move_Lot_Order_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_MOVE_LOT_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);



/*******************************************************************************
CUS_INV_Move_Lot_Order()
- Log + Definition
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot_Order(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_MOVE_LOT_ORDER(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_Move_Lot_Order", out_node);
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
CUS_INV_MOVE_LOT_ORDER()
- Main sub function of "CUS_INV_Move_Lot_Order" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_MOVE_LOT_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* TABLE */
    struct MINVLOTSTS_TAG MINVLOTSTS;	
    struct MINVMOVSTS_TAG MINVMOVSTS;	// 이동지시 마스터
	struct MINVMOVLOT_TAG MINVMOVLOT;	// 이동지시 LOT
	struct MWIPOPRDEF_TAG MWIPOPRDEF_TO;	// TO 창고 정보
	struct MWIPOPRDEF_TAG MWIPOPRDEF_FROM;	// FROM 창고 정보
    struct MWIPMATDEF_TAG MWIPMATDEF;	
	struct MGCMTBLDAT_TAG MGCMTBLDAT_FROM;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_TO;
	struct CBASTXNDEF_TAG CBASTXNDEF;
	struct MINVDLVDTL_TAG MINVDLVDTL;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_SRC;
	struct IF_INV_TXNS_TAG IF_INV_TXNS;

	TRSNode *erpif_in;
    TRSNode *gen_in_node;
    TRSNode *cmn_out;
    TRSNode **Lot_tbl;

	struct work_date_tag work_date;
    char s_Order_id[21];
	char s_factory[10];
    int i_lot_count = 0;
	int i = 0;

    // LOG
    LOG_head("CUS_INV_Move_Lot_Order");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

    // VALIDATION CHECK
    if (CUS_INV_Move_Lot_Order_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //step 1: 이동지시 등록
    if (TRS.get_procstep(in_node) == '1')
    {        
        if (COM_isnullspace(TRS.get_string(in_node, "MOVE_ID")) == MP_TRUE)
        {
            memset(s_Order_id, ' ', sizeof(s_Order_id));

			// 이동지시 ID 발번 규칙을 셋업하여 찾아오도록 한다.
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			TRS.add_char(gen_in_node, "PROCSTEP", '2');
			CopyDefaultMembers(gen_in_node, in_node);
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_WIP_MOVE_ORDER, strlen(MP_ID_ROLE_WIP_MOVE_ORDER));
			TRS.add_nstring(gen_in_node, "SEQ_KEY_1", TRS.get_string(in_node, "AREA_ID"));
			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            memcpy(s_Order_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));
            TRS.free_node(cmn_out);
        }
        else
        {
            TRS.copy(s_Order_id, sizeof(s_Order_id), in_node, "MOVE_ID");
        }

		//FROM 창고 조회하여 FROM_SUB_AREA_ID, FROM_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER), in_node, "FROM_OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		//TO 창고 조회하여 TO_SUB_AREA_ID, TO_OPER 적용
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER), in_node, "TO_OPER");
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

        //이동지시 마스터 생성 및 업데이트
        DBU_init_minvmovsts(&MINVMOVSTS);
        TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
        memcpy(MINVMOVSTS.MOVE_ID, s_Order_id, sizeof(MINVMOVSTS.MOVE_ID));
        DBU_select_minvmovsts(1, &MINVMOVSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            if (MINVMOVSTS.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
            {
                //WIP-0560 : 완료된 이동지시는 수정할 수 없습니다.
                strcpy(s_msg_code, "WIP-0560");
                TRS.add_fieldmsg(out_node, "MINVMOVSTS", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
                TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(MINVMOVSTS.MOVE_STATUS), MINVMOVSTS.MOVE_STATUS);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

			memcpy(MINVMOVSTS.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			memcpy(MINVMOVSTS.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(MINVMOVSTS.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));
            TRS.copy(MINVMOVSTS.UPDATE_USER_ID, sizeof(MINVMOVSTS.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVMOVSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.UPDATE_TIME));

            DBU_update_minvmovsts(1, &MINVMOVSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MINVMOVSTS UPDATE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
        else if (DB_error_code == DB_NOT_FOUND)
        {
			memcpy(MINVMOVSTS.AREA_ID, MWIPOPRDEF_FROM.AREA_ID, sizeof(MWIPOPRDEF_FROM.AREA_ID));
			memcpy(MINVMOVSTS.SUB_AREA_ID, MWIPOPRDEF_FROM.SUB_AREA_ID, sizeof(MWIPOPRDEF_FROM.SUB_AREA_ID));
			memcpy(MINVMOVSTS.OPER, MWIPOPRDEF_FROM.OPER, sizeof(MWIPOPRDEF_FROM.OPER));
            //TO_AREA_ID는 같은 사업부 내에서만 이동할 수 있도록 함
			memcpy(MINVMOVSTS.TO_AREA_ID, MWIPOPRDEF_TO.AREA_ID, sizeof(MWIPOPRDEF_TO.AREA_ID));
			memcpy(MINVMOVSTS.TO_SUB_AREA_ID, MWIPOPRDEF_TO.SUB_AREA_ID, sizeof(MWIPOPRDEF_TO.SUB_AREA_ID));
			memcpy(MINVMOVSTS.TO_OPER, MWIPOPRDEF_TO.OPER, sizeof(MWIPOPRDEF_TO.OPER));

			MINVMOVSTS.MOVE_STATUS[0] = MP_CWIP_ORDER_START;
            TRS.copy(MINVMOVSTS.CREATE_USER_ID, sizeof(MINVMOVSTS.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVMOVSTS.CREATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.CREATE_TIME));
            TRS.copy(MINVMOVSTS.UPDATE_USER_ID, sizeof(MINVMOVSTS.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVMOVSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.UPDATE_TIME));

            DBU_insert_minvmovsts(&MINVMOVSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MINVMOVSTS INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }   
        }

        /* 이동지시 LOT LIST를 삭제 한다. 
            => 이동지시 리스트의 변동이 있을겨우 전부 삭제 후 다시 저장한다. */
        //MINVMOVLOT에 저장되었던 lot list를 지운다.
        DBU_init_minvmovlot(&MINVMOVLOT);
        memcpy(MINVMOVLOT.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
        memcpy(MINVMOVLOT.MOVE_ID, MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
        DBU_delete_minvmovlot(2, &MINVMOVLOT);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MINVMOVLOT DELETE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
                TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }

        //이동지시 LOT LIST 저장
        Lot_tbl = TRS.get_list(in_node, "INV_LOT_LIST");
        i_lot_count = TRS.get_item_count(in_node, "INV_LOT_LIST");

        for (i = 0; i < i_lot_count; i++)
        {
            DBU_init_minvmovlot(&MINVMOVLOT);
            memcpy(MINVMOVLOT.FACTORY, MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY));
            memcpy(MINVMOVLOT.MOVE_ID, MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
            TRS.copy(MINVMOVLOT.INV_LOT_ID, sizeof(MINVMOVLOT.INV_LOT_ID), Lot_tbl[i], "INV_LOT_ID");
			MINVMOVLOT.QTY = TRS.get_double(Lot_tbl[i], "QTY");
            TRS.copy(MINVMOVLOT.CREATE_USER_ID, sizeof(MINVMOVLOT.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVMOVLOT.CREATE_TIME, gs_sys_time, sizeof(MINVMOVLOT.CREATE_TIME));
            TRS.copy(MINVMOVLOT.UPDATE_USER_ID, sizeof(MINVMOVLOT.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(MINVMOVLOT.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVLOT.UPDATE_TIME));

            DBU_insert_minvmovlot(&MINVMOVLOT);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "MINVMOVLOT INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVLOT.FACTORY), MINVMOVLOT.FACTORY);
                TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVLOT.MOVE_ID), MINVMOVLOT.MOVE_ID);
                TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVMOVLOT.INV_LOT_ID), MINVMOVLOT.INV_LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        //move id를 out node에 넣어준다.
        TRS.add_string(out_node, "MOVE_ID", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));

    }
    //step 2: 이동지시 취소
    // => 이동지시의 상태를 삭제로 변경한다.
    else if (TRS.get_procstep(in_node) == '2')
    {
        DBU_init_minvmovsts(&MINVMOVSTS);
        TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "MOVE_ID");

        DBU_select_minvmovsts(1, &MINVMOVSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0561 : 이동지시번호가 존재하지 않습니다. 이동지시 번호를 확인하세요.
            strcpy(s_msg_code, "WIP-0561");
            TRS.add_fieldmsg(out_node, "MINVMOVSTS SELECT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (MINVMOVSTS.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
        {
            //WIP-0562 : 완료된 이동지시는 취소할 수 없습니다.
            strcpy(s_msg_code, "WIP-0562");
            TRS.add_fieldmsg(out_node, "MINVMOVSTS", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
            TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(MINVMOVSTS.MOVE_STATUS), MINVMOVSTS.MOVE_STATUS);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

		MINVMOVSTS.MOVE_STATUS[0] = MP_CWIP_ORDER_DELETE;
        TRS.copy(MINVMOVSTS.UPDATE_USER_ID, sizeof(MINVMOVSTS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(MINVMOVSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.UPDATE_TIME));

        DBU_update_minvmovsts(1, &MINVMOVSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "MINVMOVSTS UPDATE", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    //step 3: 이동지시 확인
    else if (TRS.get_procstep(in_node) == '3')
    {
        //이동지시 조회
        DBU_init_minvmovsts(&MINVMOVSTS);
        TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "MOVE_ID");

        DBU_select_minvmovsts(1, &MINVMOVSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0561 : 이동지시번호가 존재하지 않습니다. 이동지시 번호를 확인하세요.
            strcpy(s_msg_code, "WIP-0561");
            TRS.add_fieldmsg(out_node, "MINVMOVSTS SELECT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }


		//20230829 금형떔시 개별로 하나씩 하는경우 있어서..이부분 주석걸음..문제 있을거 같으면. 해당부분 다시 풀고 금형입고쪽 수정해야함.
		/*
		if (MINVMOVSTS.MOVE_STATUS[0] != MP_CWIP_ORDER_START)
		{
			//INV-0065 : 해당 이동지시는 진행할 수 없습니다. 상태를 확인해주세요.
			strcpy(s_msg_code, "INV-0065");
			TRS.add_fieldmsg(out_node, "MINVMOVSTS", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
			TRS.add_fieldmsg(out_node, "MOVE_STATUS", MP_STR, sizeof(MINVMOVSTS.MOVE_STATUS), MINVMOVSTS.MOVE_STATUS);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
		*/

        //이동지시를 완료처리 해준다.
		MINVMOVSTS.MOVE_STATUS[0] = MP_CWIP_ORDER_FINISH;
        TRS.copy(MINVMOVSTS.UPDATE_USER_ID, sizeof(MINVMOVSTS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(MINVMOVSTS.UPDATE_TIME, gs_sys_time, sizeof(MINVMOVSTS.UPDATE_TIME));

        DBU_update_minvmovsts(1, &MINVMOVSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            strcpy(s_msg_code, "ADM-0004");
            TRS.add_fieldmsg(out_node, "MINVMOVSTS UPDATE", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVMOVSTS.FACTORY), MINVMOVSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(MINVMOVSTS.MOVE_ID), MINVMOVSTS.MOVE_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

		//FROM AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
		TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_FROM.KEY_1, MINVMOVSTS.AREA_ID, sizeof(MINVMOVSTS.AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);

		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_FROM.TABLE_NAME), MGCMTBLDAT_FROM.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// FROM 창고
		DBU_init_mwipoprdef(&MWIPOPRDEF_FROM);
		TRS.copy(MWIPOPRDEF_FROM.FACTORY, sizeof(MWIPOPRDEF_FROM.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_FROM.OPER, MINVMOVSTS.OPER, sizeof(MINVMOVSTS.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_FROM);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_FROM.FACTORY), MWIPOPRDEF_FROM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_FROM.OPER), MWIPOPRDEF_FROM.OPER);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//TO AREA 정보 조회
		DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
		TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		memcpy(MGCMTBLDAT_TO.KEY_1, MINVMOVSTS.TO_AREA_ID, sizeof(MINVMOVSTS.TO_AREA_ID));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);

		if (DB_error_code != DB_SUCCESS)
		{
			//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
			strcpy(s_msg_code, "GCM-0008");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TO.TABLE_NAME), MGCMTBLDAT_TO.TABLE_NAME);
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//TO 창고
		DBU_init_mwipoprdef(&MWIPOPRDEF_TO);
		TRS.copy(MWIPOPRDEF_TO.FACTORY, sizeof(MWIPOPRDEF_TO.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_TO.OPER, MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_TO);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				//WIP-0590 : 이 창고는 존재하지 않습니다.
				strcpy(s_msg_code, "WIP-0590");
				gs_log_type.e_type = MP_LOG_E_EXISTENCE;
			}
			else
			{
				strcpy(s_msg_code, "INV-0004");
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				TRS.add_dberrmsg(out_node, DB_error_msg);
			}

			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_TO.FACTORY), MWIPOPRDEF_TO.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_TO.OPER), MWIPOPRDEF_TO.OPER);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//위탁 창고에서 이동
		if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_CONSIGNMENT, strlen(MP_OPER_GRP_TYPE_CONSIGNMENT)) == 0)
		{
			TRS.set_char(in_node, IN_PROCSTEP, '5');
			TRS.add_string(in_node, "TO_OPER", MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));
			// 자재 LOT 이동
			if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}

			DBU_init_cbastxndef(&CBASTXNDEF);
			TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
			CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
			CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2));
			DBU_select_cbastxndef(2, &CBASTXNDEF);

			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (DB_error_code == DB_NOT_FOUND)
			{
				//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
				//MST(ERP AREA ID : 103)
				//임시로 하드코딩
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_31);
				CBASTXNDEF.ERP_AREA_ID = 103;
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			Lot_tbl = TRS.get_list(in_node, "INV_LOT_LIST");

			for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
			{
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "INV_LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0044");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
					}
					else
					{
						strcpy(s_msg_code, "WIP-0004");
						gs_log_type.e_type = MP_LOG_E_SYSTEM;

					}
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// MWIPMATDEF - 제품 정보 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
				MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// MINVDLVDTL - 구매 입고 상세 정보 조회
				DBU_init_minvdlvdtl(&MINVDLVDTL);
				TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVDLVDTL.DLV_NO, MINVLOTSTS.DLV_NO, sizeof(MINVLOTSTS.DLV_NO));
				MINVDLVDTL.DLV_SEQ = MINVLOTSTS.DLV_SEQ;
				DBU_select_minvdlvdtl(1, &MINVDLVDTL);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "INV-0004");
					TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(3)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
					TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
					TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//ERP 실적 - IF_PO_CONSIGN_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE_NAME", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "PO_HEADER_ID", MINVDLVDTL.PO_HEADER_ID);
				TRS.add_int(erpif_in, "PO_LINE_ID", MINVDLVDTL.PO_LINE_ID);
				TRS.add_int(erpif_in, "PO_RELEASE_ID", MINVDLVDTL.PO_RELEASE_ID);
				TRS.add_int(erpif_in, "PO_LINE_LOCATION_ID", MINVDLVDTL.LINE_LOCATION_ID);
				TRS.add_int(erpif_in, "PO_DISTRIBUTION_ID", MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_double(erpif_in, "QTY", -MINVLOTSTS.QTY);
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_PO_CONSIGN_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
		//자재 창고에서 이동
		else if (memcmp(MWIPOPRDEF_FROM.OPER_GRP_1, MP_OPER_GRP_TYPE_INV, strlen(MP_OPER_GRP_TYPE_INV)) == 0)
		{
			TRS.set_char(in_node, IN_PROCSTEP, '5');
			TRS.add_string(in_node, "TO_OPER", MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));
			// 자재 LOT 이동
			if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}

			DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
			TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
			memcpy(MGCMTBLDAT_SRC.KEY_1, "ISSUE", strlen("ISSUE"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);

			if (DB_error_code != DB_SUCCESS)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			Lot_tbl = TRS.get_list(in_node, "INV_LOT_LIST");

			for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
			{
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), Lot_tbl[i], "INV_LOT_ID");
				DBU_select_minvlotsts(1, &MINVLOTSTS);

				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0044");
						gs_log_type.e_type = MP_LOG_E_EXISTENCE;
					}
					else
					{
						strcpy(s_msg_code, "WIP-0004");
						gs_log_type.e_type = MP_LOG_E_SYSTEM;

					}
					TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				// MWIPMATDEF - 제품 정보 조회
				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
				MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0006");
					TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", 2);	//2번으로 고정
				TRS.add_string(erpif_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_ID_2, strlen(MP_ERP_TRAN_TYPE_ID_2));	//2번으로 고정
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MINVMOVSTS.AREA_ID, sizeof(MINVMOVSTS.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF_FROM.OPER_CMF_1, sizeof(MWIPOPRDEF_FROM.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_TO.OPER_CMF_1, sizeof(MWIPOPRDEF_TO.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MINVMOVSTS.TO_AREA_ID, sizeof(MINVMOVSTS.TO_AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
				DBU_select_if_inv_txns(2, &IF_INV_TXNS);

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", IF_INV_TXNS.IF_SEQ);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
				TRS.add_string(erpif_in, "MES_ID", MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID));
				TRS.add_double(erpif_in, "QTY", MINVLOTSTS.QTY);

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
		}
		else
		{
			TRS.set_char(in_node, IN_PROCSTEP, '1');
			TRS.add_string(in_node, "TO_OPER", MINVMOVSTS.TO_OPER, sizeof(MINVMOVSTS.TO_OPER));
			// 자재 LOT 이동
			if (CUS_INV_MOVE_LOT_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}
		}
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Move_Lot_Order_Validation()
- Validation Check sub function of "CUS_INV_MOVE_LOT_ORDER" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Move_Lot_Order_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
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

    return MP_TRUE;
}
