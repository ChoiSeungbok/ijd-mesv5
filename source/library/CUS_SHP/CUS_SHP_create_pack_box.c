/*******************************************************************************

    System      : MESplus
    Module      : CUS_SHP
    File Name   : CUS_SHP_create_pack_box.c
    Description : Create Pack Box

    MES Version : 5.2.0

    Function List
        - CUS_SHP_Create_Pack_Box()
            + Create Pack Box
        - CUS_SHP_CREATE_PACK_BOX()
            + Main Sub function of "CUS_SHP_Create_Pack_Box"
            + (called by "CUS_SHP_Create_Pack_Box")
        - CUS_SHP_Create_Pack_Box_Validation()
            + Validation Check sub function of "CUS_SHP_CREATE_PACK_BOX" function
            + (called by "CUS_SHP_CREATE_PACK_BOX")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/28  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_CREATE_PACK_BOX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Create_Pack_Box_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_CREATE_PACK_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Create_Pack_Box_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Create_Pack_Box_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_SHP_Create_Pack_Box()
        - Create Pack Box
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_SHP_Create_Pack_Box_In_Tag *CUS_SHP_Create_Pack_Box_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Box(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_CREATE_PACK_BOX_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_CREATE_PACK_BOX", out_node);

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
CUS_SHP_CREATE_PACK_BOX_MAIN()
- Main sub function of "CUS_SHP_CREATE_PACK_BOX_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_CREATE_PACK_BOX_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CREATE_PACK_BOX_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *create_in_node;
	TRSNode **pack_lot_list;
	TRSNode *lot_list;
	TRSNode *box_list;
	TRSNode	*gen_in_node;
	TRSNode	*cmn_out;
	char pack_box_id[26];
	struct work_date_tag work_date;
	char s_factory[10];
	int i = 0;
	int i_box_count = 0;

	LOG_head("CUS_SHP_CREATE_PACK_BOX");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	memset(s_factory, ' ', sizeof(s_factory));
	TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
	memset(&work_date, ' ', sizeof(work_date));
	Get_shift(s_factory, &work_date);

	/*' Validation Check */
	if (CUS_SHP_Create_Pack_Box_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	create_in_node = TRS.add_node(in_node, "create_in_node");
	CopyDefaultMembers(create_in_node, in_node);

	TRS.add_char(create_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(create_in_node, "PACK_ORDER_ID", TRS.get_string(in_node, "PACK_ORDER_ID"));
	TRS.add_int(create_in_node, "LINE_NO", TRS.get_int(in_node, "LINE_NO"));
	TRS.add_int(create_in_node, "LOT_COUNT", TRS.get_int(in_node, "LOT_COUNT"));
	
	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		lot_list = TRS.add_node(create_in_node, "PACK_LOT_LIST");
		TRS.add_nstring(lot_list, "ORG_LOT_ID", TRS.get_string(pack_lot_list[i], "ORG_LOT_ID"));
		TRS.add_nstring(lot_list, "PACK_LOT_ID", TRS.get_string(pack_lot_list[i], "PACK_LOT_ID"));
	}

	if (COM_isnullspace(TRS.get_string(in_node, "BOX_ID")) == MP_FALSE)
	{
		memset(pack_box_id, ' ', sizeof(pack_box_id));
		memcpy(pack_box_id, TRS.get_string(in_node, "BOX_ID"), strlen(TRS.get_string(in_node, "BOX_ID")));

		box_list = TRS.add_node(create_in_node, "BOX_LIST");
		TRS.add_string(box_list, "BOX_ID", pack_box_id, sizeof(pack_box_id));
	}
	else
	{
		//1박스당 LOT의 개수를 이용하여 BOX 개수 계산
		i_box_count = TRS.get_item_count(in_node, "PACK_LOT_LIST") / TRS.get_int(in_node, "LOT_COUNT");

		if (i_box_count * TRS.get_int(in_node, "LOT_COUNT") < TRS.get_item_count(in_node, "PACK_LOT_LIST"))
		{
			i_box_count++;
		}

		for (i = 0; i < i_box_count; i++)
		{
			memset(pack_box_id, ' ', sizeof(pack_box_id));

			//NAMING RULE 추가 개발 필요
			//사업부에 따른 RULE로 변경해야함
			gen_in_node = TRS.add_node(in_node, "gen_in_node");
			//LOT ID 발번            
			CopyDefaultMembers(gen_in_node, in_node); // 기본 셋업 메세지 ID PW,FACTORY...

														//BOX ID 생성 -> LOT ID와 같은 방식으로 생성
			TRS.add_string(gen_in_node, "RULE_ID", MP_ID_ROLE_SHIPPING_LOT_ID, strlen(MP_ID_ROLE_SHIPPING_LOT_ID));
			TRS.add_nstring(gen_in_node, "FLOW", TRS.get_string(in_node, "AREA_ID"));
			TRS.add_string(gen_in_node, "SEQ_KEY_10", work_date.s_work_date, 8);
			TRS.add_string(gen_in_node, "DATETIME", gs_sys_time, 8);
			TRS.add_string(gen_in_node, "OVR_TIME", gs_sys_time, 8);
			TRS.add_char(gen_in_node, IN_PROCSTEP, '2');

			cmn_out = TRS.create_node("cmn_out");
			if (CUS_WIP_GENERATE_ID(s_msg_code, gen_in_node, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			memcpy(pack_box_id, TRS.get_string(cmn_out, "GEN_ID"), strlen(TRS.get_string(cmn_out, "GEN_ID")));

			TRS.free_node(cmn_out);

			box_list = TRS.add_node(create_in_node, "BOX_LIST");
			TRS.add_string(box_list, "BOX_ID", pack_box_id, sizeof(pack_box_id));
		}
	}
	
	if (CUS_SHP_Create_Pack_Box_Before_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_CREATE_PACK_BOX(s_msg_code, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Create_Pack_Box_After_Transaction(s_msg_code, 0, create_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_SHP_CREATE_PACK_BOX()
        - Main sub function of "CUS_SHP_Create_Pack_Box" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_CREATE_PACK_BOX_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_CREATE_PACK_BOX(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct CPAKORDSTS_TAG CPAKORDSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;

    char s_sys_time[14];

	int i = 0;
	int j = 0;
	char c_print_flag = 'N';
	int i_lot_count = 0;

	TRSNode **pack_lot_list;
	TRSNode **pack_box_list;
	TRSNode *box_list;
		  
    memset(s_sys_time, ' ', sizeof(s_sys_time));
	
	//DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// CPAKORDSTS - 포장 지시 정보 조회
	DBU_init_cpakordsts(&CPAKORDSTS);
	TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
	CPAKORDSTS.LINE_NO = TRS.get_int(in_node, "LINE_NO");
	DBU_select_cpakordsts(1, &CPAKORDSTS);

	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CPAKORDSTS SELECT(1) ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
		TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

		return MP_FALSE;
	}

	pack_box_list = TRS.get_list(in_node, "BOX_LIST");

	pack_lot_list = TRS.get_list(in_node, "PACK_LOT_LIST");

	for (i = 0; i < TRS.get_item_count(in_node, "PACK_LOT_LIST"); i++)
	{
		// CPAKLOTSTS - 포장 LOT 정보 조회
		DBU_init_cpaklotsts(&CPAKLOTSTS);
		TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CPAKLOTSTS.PACK_ORDER_ID, sizeof(CPAKLOTSTS.PACK_ORDER_ID), in_node, "PACK_ORDER_ID");
		CPAKLOTSTS.PACK_LINE_NO = TRS.get_int(in_node, "LINE_NO");
		TRS.copy(CPAKLOTSTS.ORG_LOT_ID, sizeof(CPAKLOTSTS.ORG_LOT_ID), pack_lot_list[i], "ORG_LOT_ID");
		TRS.copy(CPAKLOTSTS.PACK_LOT_ID, sizeof(CPAKLOTSTS.PACK_LOT_ID), pack_lot_list[i], "PACK_LOT_ID");
		DBU_select_cpaklotsts(2, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS SELECT(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}

		// 포장 LOT 출하 여부 체크
		if (CPAKLOTSTS.SHIP_FLAG == 'Y')
		{
			strcpy(s_msg_code, "WIP-0569");
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 중박스 포장 체크
		if (COM_isnullspace(CPAKLOTSTS.BOX_ID_1) == MP_FALSE)
		{
			strcpy(s_msg_code, "WIP-0570");
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// 포장 LOT 대박스 포장 체크
		if (COM_isnullspace(CPAKLOTSTS.BOX_ID_2) == MP_FALSE)
		{
			strcpy(s_msg_code, "WIP-0570");
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_fieldmsg(out_node, "BOX_ID_2", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_COMMON;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		// CPAKLOTSTS - BOX_ID_1 정보 매핑(중박스)
		TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), pack_box_list[j], "BOX_ID");
		TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
		DBU_update_cpaklotsts(1, &CPAKLOTSTS);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
			TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
			TRS.add_fieldmsg(out_node, "ORG_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.ORG_LOT_ID), CPAKLOTSTS.ORG_LOT_ID);
			TRS.add_fieldmsg(out_node, "PACK_LOT_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_LOT_ID), CPAKLOTSTS.PACK_LOT_ID);
			TRS.add_fieldmsg(out_node, "BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_1), CPAKLOTSTS.BOX_ID_1);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		c_print_flag = 'Y';
		i_lot_count++;

		if (i_lot_count == TRS.get_int(in_node, "LOT_COUNT"))
		{
			j++;
			i_lot_count = 0;
		}
	}

	TRS.add_char(out_node, "PRINT_FLAG", c_print_flag);

	for (i = 0; i < TRS.get_item_count(in_node, "BOX_LIST"); i++)
	{
		box_list = TRS.add_node(out_node, "BOX_LIST");
		TRS.add_nstring(box_list, "BOX_ID", TRS.get_string(pack_box_list[i], "BOX_ID"));
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_SHP_Create_Pack_Box_Validation()
        - Validation Check sub function of "CUS_SHP_CREATE_PACK_BOX" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_CREATE_PACK_BOX_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Box_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_SHP_Create_Pack_Box_Before_Transaction()
- Main sub function of "CUS_SHP_CREATE_PACK_BOX" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Box_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	// 포장 BOX 매핑 정보 삭제
	if (CUS_SHP_DELETE_PACK_BOX_MAIN(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Create_Pack_Box_After_Transaction()
- Main sub function of "CUS_SHP_CREATE_PACK_BOX" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Create_Pack_Box_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}