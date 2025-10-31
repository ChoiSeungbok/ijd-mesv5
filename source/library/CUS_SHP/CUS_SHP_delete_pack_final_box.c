/*******************************************************************************

    System      : MESplus
    Module      : CUS_SHP
    File Name   : CUS_SHP_delete_pack_final_box.c
    Description : Delete Pack Final Box

    MES Version : 5.2.0

    Function List
        - CUS_SHP_Delete_Pack_Final_Box()
            + Delete Pack Final Box
        - CUS_SHP_DELETE_PACK_FINAL_BOX()
            + Main Sub function of "CUS_SHP_Delete_Pack_Final_Box"
            + (called by "CUS_SHP_Delete_Pack_Final_Box")
        - CUS_SHP_Delete_Pack_Final_Box_Validation()
            + Validation Check sub function of "CUS_SHP_DELETE_PACK_FINAL_BOX" function
            + (called by "CUS_SHP_DELETE_PACK_FINAL_BOX")
       
    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/08/31  Miracom         Create        

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
#include "CUS_SHP_common.h"
#include "CUS_common.h"

int CUS_SHP_DELETE_PACK_FINAL_BOX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Final_Box_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Final_Box_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_Delete_Pack_Final_Box_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_SHP_Delete_Pack_Final_Box()
        - Delete Pack Final Box
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - CUS_SHP_Delete_Pack_Final_Box_In_Tag *CUS_SHP_Delete_Pack_Final_Box_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Final_Box(TRSNode *in_node, 
                  TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_DELETE_PACK_FINAL_BOX", out_node);

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
CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN()
- Main sub function of "CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN" function
Return Value
- int : 1 (MP_TRUE) / 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN_IN_TAG *In_Lot_In : Input Message structure
- Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)

{
	TRSNode *delete_in_node;

	LOG_head("CUS_SHP_DELETE_PACK_FINAL_BOX");
	COM_log_add_field_msg(in_node);
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

	/*' Validation Check */
	if (CUS_SHP_Delete_Pack_Final_Box_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	delete_in_node = TRS.add_node(in_node, "delete_in_node");
	CopyDefaultMembers(delete_in_node, in_node);

	TRS.add_char(delete_in_node, IN_PROCSTEP, TRS.get_char(in_node, IN_PROCSTEP));

	TRS.add_nstring(delete_in_node, "FINAL_BOX_ID", TRS.get_string(in_node, "FINAL_BOX_ID"));

	if (CUS_SHP_Delete_Pack_Final_Box_Before_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_DELETE_PACK_FINAL_BOX(s_msg_code, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	if (CUS_SHP_Delete_Pack_Final_Box_After_Transaction(s_msg_code, 0, delete_in_node, out_node) == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
    CUS_SHP_DELETE_PACK_FINAL_BOX()
        - Main sub function of "CUS_SHP_Delete_Pack_Final_Box" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_DELETE_PACK_FINAL_BOX_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_DELETE_PACK_FINAL_BOX(char *s_msg_code,
                       TRSNode *in_node, 
                       TRSNode *out_node)

{
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct CPAKLOTSTS_TAG CPAKLOTSTS_COUNT;

    char s_sys_time[14];

	double d_qty = 0;

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

	// CPAKLOTSTS - 출하 LOT 수량 체크(최종 박스에 담겨진)
	DBU_init_cpaklotsts(&CPAKLOTSTS_COUNT);
	TRS.copy(CPAKLOTSTS_COUNT.FACTORY, sizeof(CPAKLOTSTS_COUNT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKLOTSTS_COUNT.BOX_ID_2, sizeof(CPAKLOTSTS_COUNT.BOX_ID_2), in_node, "FINAL_BOX_ID");
	d_qty = (int)DBU_select_cpaklotsts_scalar(19, &CPAKLOTSTS_COUNT);

	if (d_qty > 0)
	{
		strcpy(s_msg_code, "WIP-0572");
		TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS_COUNT.BOX_ID_2), CPAKLOTSTS_COUNT.BOX_ID_2);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_VALIDATION;
		gs_log_type.category = MP_LOG_CATE_COMMON;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// CPAKLOTSTS - 포장 최종 박스 정보 삭제
	DBU_init_cpaklotsts(&CPAKLOTSTS);
	TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), in_node, "FINAL_BOX_ID");
	TRS.copy(CPAKLOTSTS.UPDATE_USER_ID, sizeof(CPAKLOTSTS.UPDATE_USER_ID), in_node, IN_USERID);
	memcpy(CPAKLOTSTS.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
	DBU_update_cpaklotsts(5, &CPAKLOTSTS);

	if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_fieldmsg(out_node, "CPAKLOTSTS UPDATE", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CPAKLOTSTS.FACTORY), CPAKLOTSTS.FACTORY);
		TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKLOTSTS.PACK_ORDER_ID), CPAKLOTSTS.PACK_ORDER_ID);
		TRS.add_fieldmsg(out_node, "PACK_LINE_NO", MP_INT, CPAKLOTSTS.PACK_LINE_NO);
		TRS.add_fieldmsg(out_node, "FINAL_BOX_ID", MP_STR, sizeof(CPAKLOTSTS.BOX_ID_2), CPAKLOTSTS.BOX_ID_2);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}


/*******************************************************************************
    CUS_SHP_Delete_Pack_Final_Box_Validation()
        - Validation Check sub function of "CUS_SHP_DELETE_PACK_FINAL_BOX" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - CUS_SHP_DELETE_PACK_FINAL_BOX_IN_TAG *In_Lot_In : Input Message structure
        - Cmn_Out_Tag *Cmn_Out : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Final_Box_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
CUS_SHP_Delete_Pack_Final_Box_Before_Transaction()
- Main sub function of "CUS_SHP_DELETE_PACK_FINAL_BOX" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Final_Box_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_Delete_Pack_Final_Box_After_Transaction()
- Main sub function of "CUS_SHP_DELETE_PACK_FINAL_BOX" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Delete_Pack_Final_Box_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
	return MP_TRUE;
}