/*******************************************************************************

    System      : MESplus
    Module      : CUS_INV
    File Name   : CUS_INV_create_dlv_label.c
    Description : Create Inv Dlv Label Data

    MES Version : 5.2.0

    Function List
        - CUS_INV_Create_Dlv_Label()
            + Create Inv Dlv Label Data
        - CUS_INV_CREATE_DLV_LABEL()
            + Main Sub function of "CUS_INV_Create_Dlv_Label"
            + (called by "CUS_INV_Create_Dlv_Label")
        - CUS_INV_Create_Dlv_Label_Validation()
            + Validation Check sub function of "CUS_INV_CREATE_DLV_LABEL" function
            + (called by "CUS_INV_CREATE_DLV_LABEL")
       
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

int CUS_INV_CREATE_DLV_LABEL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Dlv_Label_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CREATE_DLV_LABEL_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Dlv_Label_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_Create_Dlv_Label_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_INV_Create_Dlv_Label()
        - Create Inv Dlv Label Data
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_INV_Create_Dlv_Label_In_Tag *CUS_INV_Create_Dlv_Label_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Label(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_CREATE_DLV_LABEL_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_CREATE_DLV_LABEL", out_node);

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
CUS_INV_CREATE_DLV_LABEL_MAIN()
- Main sub function of "CUS_INV_CREATE_DLV_LABEL_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_INV_CREATE_DLV_LABEL_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_DLV_LABEL_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *create_in_node;
	TRSNode **inv_lot_list;
	TRSNode *inv_list;
	int i;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	char dlv_label_id[26];

	LOG_head("CUS_INV_CREATE_LABEL_LABEL");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_INV_Create_Dlv_Label_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "DLV_LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"));

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		memset(dlv_label_id, ' ', sizeof(dlv_label_id));

		if (COM_isnullspace(TRS.get_string(inv_lot_list[i], "LABEL_ID")) == MP_FALSE)
		{
			memcpy(dlv_label_id, TRS.get_string(inv_lot_list[i], "LABEL_ID"), strlen(TRS.get_string(inv_lot_list[i], "LABEL_ID")));
		}
		else
		{
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW, strlen(MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW));
			TRS.add_string(gen_in_node, "LOT_ID", TRS.get_string(in_node, "DLV_LOT_ID"), strlen(TRS.get_string(in_node, "DLV_LOT_ID")));
			TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(dlv_label_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

			TRS.free_node(cmn_out);
		}

		inv_list = TRS.add_node(create_in_node, "INV_LOT_LIST");
		TRS.add_string(inv_list, "LABEL_ID", dlv_label_id, sizeof(dlv_label_id));

		TRS.add_double(inv_list, "QTY", TRS.get_double(inv_lot_list[i], "QTY"));
		TRS.add_double(inv_list, "QTY_2", TRS.get_double(inv_lot_list[i], "QTY_2"));
		TRS.add_double(inv_list, "QTY_3", TRS.get_double(inv_lot_list[i], "QTY_3"));
	}
	
	if (CUS_INV_Create_Dlv_Label_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_CREATE_DLV_LABEL(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_INV_Create_Dlv_Label_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_INV_CREATE_DLV_LABEL()
        - Main sub function of "CUS_INV_Create_Dlv_Label" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_DLV_LABEL_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_CREATE_DLV_LABEL(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVDLVLBL_TAG MINVDLVLBL;
	struct MINVDLVDTL_TAG MINVDLVDTL;

    char s_sys_time[14];

	int i;

	TRSNode **inv_lot_list;
		  
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

	// MINVDLVLOT - 입하 자재 LOT 정보 조회
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



	//Wait 필요없음
	/*
	// 입하 LOT 상태 체크
	if (memcmp(MINVDLVLOT.DLV_LOT_STATUS, MP_CINV_LOT_STATUS_WAIT, strlen(MP_CINV_LOT_STATUS_WAIT)) != 0)
	{
		strcpy(s_msg_code, "INV-0036");
		TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	*/

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

	inv_lot_list = TRS.get_list(in_node, "INV_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "INV_LOT_LIST"); i++)
	{
		DBU_init_minvdlvlbl(&MINVDLVLBL);
		TRS.copy(MINVDLVLBL.FACTORY, sizeof(MINVDLVLBL.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MINVDLVLBL.DLV_LOT_ID, sizeof(MINVDLVLBL.DLV_LOT_ID), in_node, "DLV_LOT_ID");
		TRS.copy(MINVDLVLBL.LABEL_ID, sizeof(MINVDLVLBL.LABEL_ID), inv_lot_list[i], "LABEL_ID");
		DBU_select_minvdlvlbl(1, &MINVDLVLBL);
		if (DB_error_code != DB_NOT_FOUND)
		{
			strcpy(s_msg_code, "INV-0020");
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		MINVDLVLBL.QTY = TRS.get_double(inv_lot_list[i], "QTY");
		MINVDLVLBL.QTY_2 = TRS.get_double(inv_lot_list[i], "QTY_2");
		MINVDLVLBL.QTY_3 = TRS.get_double(inv_lot_list[i], "QTY_3");

		TRS.copy(MINVDLVLBL.CREATE_USER_ID, sizeof(MINVDLVLBL.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLBL.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
		TRS.copy(MINVDLVLBL.UPDATE_USER_ID, sizeof(MINVDLVLBL.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(MINVDLVLBL.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));

		// MINVDLVLBL - 입고 자재 LABEL 생성
		DBU_insert_minvdlvlbl(&MINVDLVLBL);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "INV-0004");
			TRS.add_fieldmsg(out_node, "MINVDLVLBL INSERT", MP_NVST);
			TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLBL.DLV_LOT_ID), MINVDLVLBL.DLV_LOT_ID);
			TRS.add_fieldmsg(out_node, "LABEL_ID", MP_STR, sizeof(MINVDLVLBL.LABEL_ID), MINVDLVLBL.LABEL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}
	
    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_INV_Create_Dlv_Label_Validation()
        - Validation Check sub function of "CUS_INV_CREATE_DLV_LABEL" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_INV_CREATE_DLV_LABEL_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Label_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_INV_Create_Dlv_Label_Before_Transaction()
- Main sub function of "CUS_INV_CREATE_DLV_LABEL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Label_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	//입하 라벨 삭제
	if (CUS_INV_DELETE_DLV_LABEL_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Create_Dlv_Label_After_Transaction()
- Main sub function of "CUS_INV_CREATE_DLV_LABEL" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Create_Dlv_Label_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}