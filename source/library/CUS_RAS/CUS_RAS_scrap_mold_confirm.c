/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_scrap_mold_cofirm.c
Description : 금형 폐기 확정

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/08/31  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"

int CUS_RAS_Scrap_Mold_Confirm_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_SCRAP_MOLD_CONFIRM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_Scrap_Mold_Confirm()
- CUS_RAS_Scrap_Mold_Confirm function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Scrap_Mold_Confirm(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_SCRAP_MOLD_CONFIRM(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Scrap_Mold_Confirm", out_node);
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
CUS_RAS_SCRAP_MOLD_CONFIRM()
- Main sub function of "CUS_RAS_Scrap_Mold_Confirm" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_SCRAP_MOLD_CONFIRM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRASDSPREQ_TAG CRASDSPREQ;
    struct CRASDSPTOL_TAG CRASDSPTOL;
    struct CWIPWRKDEF_TAG CWIPWRKDEF;

	struct MINVLOTSTS_TAG MINVLOTSTS;

    TRSNode **tool_list;
	TRSNode *terminate_in;
	TRSNode *inv_list;
    TRSNode *cmn_out;

    int tool_list_count = 0;
    int i = 0;

    char s_sys_time[14];
    //char tool_step;

    LOG_head("CUS_RAS_Scrap_Mold_Confirm");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_Scrap_Mold_Confirm_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memset(s_sys_time, ' ', sizeof(s_sys_time));

    //DB 시간 가져오기
    DB_get_systime(s_sys_time);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "INV-0004");
        TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    // CWIPWRKDEF - 설비작업자 조회 ( 정확한 룰이 정해지면 추가로 조건 필요,  현재는 작업자 아이디 존재하는지만 체크 (조건에 Dept_code 제외함))
    DBU_init_cwipwrkdef(&CWIPWRKDEF);
    TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID), in_node, "CONFIRM_USER_ID");
    //memcpy(CWIPWRKDEF.DEPT_CODE, MP_DEPT_CODE_RES, sizeof(CWIPWRKDEF.DEPT_CODE));

    DBU_select_cwipwrkdef(1, &CWIPWRKDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
        TRS.add_fieldmsg(out_node, "DEPT_CODE", MP_STR, sizeof(CWIPWRKDEF.DEPT_CODE), CWIPWRKDEF.DEPT_CODE);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }
	





    DBU_init_crasdspreq(&CRASDSPREQ);
    TRS.copy(CRASDSPREQ.FACTORY, sizeof(CRASDSPREQ.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CRASDSPREQ.REQ_NO, sizeof(CRASDSPREQ.REQ_NO), in_node, "REQ_NO");

    //요청 정보 조회
    DBU_select_crasdspreq(1, &CRASDSPREQ);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CRASDSPREQ SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    //CONFIRM상태에서만 폐기 가능
    if (memcmp(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_CONFIRM, strlen(MP_CRAS_DSP_REQ_STATUS_CONFIRM)) != 0)
    {
        strcpy(s_msg_code, "RAS-0321");
        TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
        TRS.add_fieldmsg(out_node, "REQ_STATUS", MP_STR, sizeof(CRASDSPREQ.REQ_STATUS), CRASDSPREQ.REQ_STATUS);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_COMMON;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    memcpy(CRASDSPREQ.REQ_STATUS, MP_CRAS_DSP_REQ_STATUS_COMPLETED, sizeof(CRASDSPREQ.REQ_STATUS));
    TRS.copy(CRASDSPREQ.CONFIRM_USER_ID, sizeof(CRASDSPREQ.CONFIRM_USER_ID), in_node, "CONFIRM_USER_ID");
    memcpy(CRASDSPREQ.CONFIRM_TIME, s_sys_time, sizeof(CRASDSPREQ.CONFIRM_TIME));
    TRS.copy(CRASDSPREQ.CONFIRM_COMMENT, sizeof(CRASDSPREQ.CONFIRM_COMMENT), in_node, "CONFIRM_COMMENT");   
    TRS.copy(CRASDSPREQ.UPDATE_USER_ID, sizeof(CRASDSPREQ.UPDATE_USER_ID), in_node, IN_USERID);
    memcpy(CRASDSPREQ.UPDATE_TIME, s_sys_time, sizeof(CRASDSPREQ.UPDATE_TIME));

    DBU_update_crasdspreq(1, &CRASDSPREQ);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "CMN-0004");
        TRS.add_fieldmsg(out_node, "CRASDSPREQ UPDATE", MP_NVST);
        TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPREQ.REQ_NO), CRASDSPREQ.REQ_NO);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

        return MP_FALSE;
    }

    tool_list = TRS.get_list(in_node, "TOOL_LIST");
    tool_list_count = TRS.get_item_count(in_node, "TOOL_LIST");

    //폐기 요청에 대한 해당 폐기 리스트 조회
    //폐기 요청 리스트 update
    for (i = 0; i < tool_list_count; i++)
    {
        DBU_init_crasdsptol(&CRASDSPTOL);
        TRS.copy(CRASDSPTOL.FACTORY, sizeof(CRASDSPTOL.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CRASDSPTOL.REQ_NO, sizeof(CRASDSPTOL.REQ_NO), in_node, "REQ_NO");
        TRS.copy(CRASDSPTOL.TOOL_ID, sizeof(CRASDSPTOL.TOOL_ID), tool_list[i], "TOOL_ID");

        DBU_select_crasdsptol(1, &CRASDSPTOL);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CRASDSPTOL SELECT", MP_NVST);
            TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }
        
        if (CRASDSPTOL.CONFIRM_FLAG == 'Y')
        {
            strcpy(s_msg_code, "RAS-0171");
            TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
            TRS.add_fieldmsg(out_node, "CONFIRM_FLAG", MP_STR, sizeof(CRASDSPTOL.CONFIRM_FLAG), CRASDSPTOL.CONFIRM_FLAG);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_COMMON;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        CRASDSPTOL.CONFIRM_FLAG = 'Y';
        TRS.copy(CRASDSPTOL.UPDATE_USER_ID, sizeof(CRASDSPTOL.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(CRASDSPTOL.UPDATE_TIME, s_sys_time, sizeof(CRASDSPTOL.UPDATE_TIME));

        DBU_update_crasdsptol(1, &CRASDSPTOL);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "CMN-0004");
            TRS.add_fieldmsg(out_node, "CRASDSPTOL UPDATE", MP_NVST);
            TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
            TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_TRANS;
            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

            return MP_FALSE;
        }  

        //TOOL 폐기 처리
		//폐기처리 로직은  기타출고 서비스내에서 구현되고 있으므로 기타출고 서비스를 호출하고, 아래 로직은 주석처리
		/*
        tool_step = 'S';
        tool_in_node = TRS.add_node(in_node, "tool_in_node");
        TRS.add_char(tool_in_node, IN_PROCSTEP, tool_step);
        CopyDefaultMembers(tool_in_node, in_node);

        TRS.add_nstring(tool_in_node, "TOOL_ID", TRS.get_string(tool_list[i], "TOOL_ID"));
        TRS.add_nstring(tool_in_node, "TOOL_TYPE", TRS.get_string(tool_list[i], "TOOL_TYPE"));

        cmn_out = TRS.create_node("cmn_out");
        if (CUS_RAS_UPDATE_TOOL(s_msg_code, tool_in_node, cmn_out) == MP_FALSE)
        {
            TRS.clone(out_node, cmn_out);
            TRS.free_node(cmn_out);
            return MP_FALSE;
        }
        TRS.free_node(cmn_out);
		*/

		//CRASDSPTOL.TOOL_ID
		DBU_init_minvlotsts(&MINVLOTSTS);
		TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(MINVLOTSTS.INV_LOT_ID, CRASDSPTOL.TOOL_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		DBU_select_minvlotsts(1, &MINVLOTSTS);
		if (DB_error_code != DB_SUCCESS )
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "RAS-0168");
			}
			else
			{
				strcpy(s_msg_code, "RAS-0004");
			}
			
			TRS.add_fieldmsg(out_node, "CRASDSPTOL UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "REQ_NO", MP_STR, sizeof(CRASDSPTOL.REQ_NO), CRASDSPTOL.REQ_NO);
			TRS.add_fieldmsg(out_node, "TOOL_ID", MP_STR, sizeof(CRASDSPTOL.TOOL_ID), CRASDSPTOL.TOOL_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

			return MP_FALSE;
		}


		//inv_lot_list

		terminate_in = TRS.add_node(in_node, "terminate_in");
		TRS.add_char(terminate_in, IN_PROCSTEP, '2');
		CopyDefaultMembers(terminate_in, in_node);


		TRS.add_nstring(terminate_in, "TERMINATE_CODE", "ETC_OUT");
		TRS.add_string(terminate_in, "OUT_DATE", gs_sys_time, 8);
		TRS.add_nstring(terminate_in, "ETC_OUT_TYPE", TRS.get_string(in_node, "ETC_OUT_TYPE"));
		TRS.add_char(terminate_in, "ERP_FLAG", 'Y');
		TRS.add_nstring(terminate_in, "COMMENT", TRS.get_string(in_node, "CONFIRM_COMMENT"));

		inv_list = TRS.add_node(terminate_in, "INV_LOT_LIST");
		TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
		TRS.add_nstring(inv_list, "COMMENT", TRS.get_string(in_node, "CONFIRM_COMMENT"));
		TRS.add_double(inv_list, "OUT_QTY", MINVLOTSTS.QTY);

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_INV_TERMINATE_LOT_MAIN(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		//TRS.add_string(tool_in_node, "TOOL_ID", MINVLOTSTS.INV_LOT_ID,sizeof(MINVLOTSTS.INV_LOT_ID));
		//TRS.add_double(tool_in_node, "OUT_QTY,", MINVLOTSTS.QTY);


		//inv_lot_list.AddString("COMMENT", svLotList.Cells[i, (int)LOT.COMMENT].Text.Trim());


		//CONFIRM_COMMENT
		//CONFIRM_USER_ID













    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_RAS_Scrap_Mold_Confirm_Validation()
- Validation Check sub function of "CUS_RAS_SCRAP_MOLD_CONFIRM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Scrap_Mold_Confirm_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "REQ_NO")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "REQ_NO", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}