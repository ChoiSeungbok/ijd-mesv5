/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_loss_dlv_label.c
    Description : Loss Inv Dlv Label Data

    MES Version : 5.2.0

    Function List
        - CUS_INV_Loss_Dlv_Label()
            + Loss Inv Dlv Label Data
        - CUS_INV_LOSS_DLV_LABEL()
            + Main Sub function of "CUS_INV_Loss_Dlv_Label"
            + (called by "CUS_INV_Loss_Dlv_Label")
        - CUS_INV_Loss_Dlv_Label_Validation()
            + Validation Check sub function of "CUS_INV_LOSS_DLV_LABEL" function
            + (called by "CUS_INV_LOSS_DLV_LABEL")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/10  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_LOSS_DLV_LABEL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Loss_Dlv_Label_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_LOSS_DLV_LABEL_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Loss_Dlv_Label_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Loss_Dlv_Label_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Loss_Dlv_Label()
        - Loss Inv Dlv Label Data
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Loss_Dlv_Label_In_Tag *CUS_INV_Loss_Dlv_Label_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Loss_Dlv_Label(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_LOSS_DLV_LABEL_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_LOSS_DLV_LABEL", out_node);

    if(i_ret == MP_TRUE)
    {
        DB_commit();
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_LOSS_DLV_LABEL_MAIN()
- Main sub function of "CUS_INV_LOSS_DLV_LABEL_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_LOSS_DLV_LABEL_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_LOSS_DLV_LABEL_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *loss_in_node;

	LOG_head("CUS_INV_LOSS_LABEL_LABEL");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Loss_Dlv_Label_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	loss_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(loss_in_node, in_node);

	TRS.add_char(loss_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(loss_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));
	TRS.add_double(loss_in_node, "LOSS_QTY", TRS.get_double(in_node, "LOSS_QTY"));

	if (CUS_INV_Loss_Dlv_Label_Before_Transaction(s_msg_code, 0, loss_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_LOSS_DLV_LABEL(s_msg_code, loss_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Loss_Dlv_Label_After_Transaction(s_msg_code, 0, loss_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_LOSS_DLV_LABEL()
        - Main sub function of "CUS_INV_Loss_Dlv_Label" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_LOSS_DLV_LABEL_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_LOSS_DLV_LABEL(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVLBL_TAG MINVDLVLBL;
	struct MINVDLVDTL_TAG MINVDLVDTL;

    char s_sys_time[14];
	double d_loss_qty = 0;
	int i_step = 0;
	
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// MINVDLVLOT - 입하 LOT 정보 조회
	DBU_init_minvdlvlot(&MINVDLVLOT);
	TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "DLV_LOT_ID");
	DBU_select_minvdlvlot(1, &MINVDLVLOT);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVDLVLOT SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	// 입하 LOT 상태 체크
	if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_CONFIRM, strlen(MP_CINV_LOT_STATUS_CONFIRM)) != 0)
	{
		//INV-0070 : 해당 작업은 오직 확정 상태에서만 가능합니다.
		strcpy(s_msg_code, "INV-0070");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// MINVDLVDTL - 구매 입고 상세 정보 조회
	DBU_init_minvdlvdtl(&MINVDLVDTL);
	TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
	memcpy(MINVDLVDTL.DLV_NO, MINVDLVLOT.DLV_NO, sizeof(MINVDLVLOT.DLV_NO));
	MINVDLVDTL.DLV_SEQ = MINVDLVLOT.DLV_SEQ;
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

	if (MINVDLVDTL.ERP_OPEN_YN == 'Y')
	{
		//INV-0066 : 해당 PO 정보는 ERP에서 마감되었습니다.
		strcpy(s_msg_code, "INV-0066");
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

	d_loss_qty = TRS.get_double(in_node, "LOSS_QTY");

	i_step = 3;

	DBU_init_minvdlvlbl(&MINVDLVLBL);
	TRS.copy(MINVDLVLBL.FACTORY, sizeof(MINVDLVLBL.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLBL.DLV_LOT_ID, sizeof(MINVDLVLBL.DLV_LOT_ID), in_node, "DLV_LOT_ID");
	DBU_open_minvdlvlbl(i_step, &MINVDLVLBL);

	if (DB_error_code != DB_SUCCESS)
	{
		//INV-0043 : 검색하신 정보는 존재하지 않습니다.
		strcpy(s_msg_code, "INV-0043");
		TRS.add_fieldmsg(out_node, "MINVDLVLBL OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLBL.FACTORY), MINVDLVLBL.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	while (1)
	{
		DBU_fetch_minvdlvlbl(i_step, &MINVDLVLBL);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_minvdlvlbl(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			//INV-0043 : 검색하신 정보는 존재하지 않습니다.
			strcpy(s_msg_code, "INV-0043");
			TRS.add_fieldmsg(out_node, "MINVDLVLBL OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLBL.FACTORY), MINVDLVLBL.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			
			// 20.12.21 minjae.go
			DBU_close_minvdlvlbl(i_step);
			//

			return MP_FALSE;
		}

		if (d_loss_qty == 0)
		{
			break;
		}

		// LOSS 처리 후 수량이 0이라면, 해당 라벨 데이터 삭제
		if (MINVDLVLBL.QTY <= d_loss_qty)
		{
			DBU_delete_minvdlvlbl(1, &MINVDLVLBL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVLBL DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLBL.FACTORY), MINVDLVLBL.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
				TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				
				// 20.12.21 minjae.go
				DBU_close_minvdlvlbl(i_step);
				//

				return MP_FALSE;
			}

			d_loss_qty -= MINVDLVLBL.QTY;
		}
		// 수량 남아있으면 수량 감소 후 업데이트
		else
		{
			MINVDLVLBL.QTY -= d_loss_qty;
			TRS.copy(MINVDLVLBL.UPDATE_USER_ID, sizeof(MINVDLVLBL.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(MINVDLVLBL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

			// MINVDLVLBL - 입고 라벨 수량 감소
			DBU_update_minvdlvlbl(1, &MINVDLVLBL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVLBL UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
				TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvdlvlbl(i_step);
				//

				return MP_FALSE;
			}

			d_loss_qty = 0;
		}
	}

	// 입하 LOT 수입 검사 LOSS 수량 감소
	MINVDLVLOT.QTY -= TRS.get_double(in_node, "LOSS_QTY");

	if (MINVDLVLOT.QTY < 0)
	{
		//INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
		strcpy(s_msg_code, "INV-0021");
		TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_fieldmsg(out_node, "TOTAL_LOSS_QTY", MP_DBL, TRS.get_double(in_node, "LOSS_QTY"));
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 입하 LOT 수량 0이면 삭제
	if (MINVDLVLOT.QTY == 0)
	{
		DBU_delete_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT DELETE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	else
	{
		TRS.copy(MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLOT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		DBU_update_minvdlvlot(1, &MINVDLVLOT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLOT UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}

	// PO 정보 입하 등록 수량 감소
	MINVDLVDTL.DLV_IN_QTY -= TRS.get_double(in_node, "LOSS_QTY");
	MINVDLVDTL.LOSS_QTY += TRS.get_double(in_node, "LOSS_QTY");

	if (MINVDLVDTL.DLV_IN_QTY < 0)
	{
		//INV-0021 : 입력한 수량은 한계치를 초과하였습니다. 수량을 체크해주세요. 
		strcpy(s_msg_code, "INV-0021");
		TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
		TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
		TRS.add_fieldmsg(out_node, "TOTAL_LOSS_QTY", MP_DBL, TRS.get_double(in_node, "LOSS_QTY"));
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	if(MINVDLVDTL.DLV_QTY <= MINVDLVDTL.CONFIRM_QTY + MINVDLVDTL.LOSS_QTY)
	{
		MINVDLVDTL.DELETE_FLAG = 'Y';
	}

	TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(MINVDLVDTL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

	DBU_update_minvdlvdtl(1, &MINVDLVDTL);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.add_fieldmsg(out_node, "MINVDLVDTL UPDATE", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
		TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
		TRS.add_fieldmsg(out_node, "DLV_SEQ", MP_INT, MINVDLVDTL.DLV_SEQ);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Loss_Dlv_Label_Validation()
        - Validation Check sub function of "CUS_INV_LOSS_DLV_LABEL" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_LOSS_DLV_LABEL_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Loss_Dlv_Label_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{   
	/*
    if(COM_service_validation(s_msg_code,
                              in_node,
                              out_node,
                              TRS.get_procstep(in_node),
                              "1") == MP_FALSE)
    {
        return MP_FALSE;
    }
	*/
    
    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Loss_Dlv_Label_Before_Transaction()
- Main sub function of "CUS_INV_LOSS_DLV_LABEL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Loss_Dlv_Label_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Loss_Dlv_Label_After_Transaction()
- Main sub function of "CUS_INV_LOSS_DLV_LABEL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Loss_Dlv_Label_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}