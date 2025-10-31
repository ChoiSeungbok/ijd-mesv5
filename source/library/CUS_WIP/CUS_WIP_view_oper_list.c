/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_oper_list.c
Description : View Oper List function

MES Version : 5.0

Function List
- step 1: 공정 찾기. 사업부별, 작업장별 공정 찾기 
- step 2: 원인공정 찾기. 사업부의 공정을 조회한다.

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/21  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Oper_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_VIEW_OPER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_View_Oper_List()
- View Oper List
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Oper_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_VIEW_OPER_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_View_Oper_List", out_node);
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
CUS_WIP_VIEW_OPER_LIST()
- Main sub function of "CUS_WIP_View_Oper_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_OPER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPOPRDEF_TAG MWIPOPRDEF;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_WIP_View_Oper_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_View_Oper_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    i_step = 0;

    //공정 찾기 : 사업부별 작업장별 공정 찾기 
    if (TRS.get_procstep(in_node) == '1')
    {
        i_step = 2;

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);                
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
    }
    //원인 공정 찾기 : 사업부별 공정 찾기 
    else if (TRS.get_procstep(in_node) == '2')
    {
        i_step = 3;

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
    }
	//사업부별 생산 창고 + 자재 창고 
	else if (TRS.get_procstep(in_node) == '3')
	{
		i_step = 4;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	//사업부별 생산 창고 조회 
	else if (TRS.get_procstep(in_node) == '4')
	{
		i_step = 5;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	//사업부별 출하 창고 조회 
	else if (TRS.get_procstep(in_node) == '5')
	{
		i_step = 6;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
		MWIPOPRDEF.SHIP_FLAG = TRS.get_char(in_node, "SHIP_FLAG");
	}
	//사업부별 완제품 창고
	else if (TRS.get_procstep(in_node) == '6')
	{
		i_step = 7;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	//사업부 별 모든 창고
	else if (TRS.get_procstep(in_node) == '7')
	{
		i_step = 8;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// PDA 공정 찾기 : 사업부별 작업장별 공정 찾기 
	else if (TRS.get_procstep(in_node) == '8')
	{
		i_step = 9;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// PDA 원인 공정 찾기 : 사업부별 공정 찾기 
	else if (TRS.get_procstep(in_node) == '9')
	{
		i_step = 10;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	else if (TRS.get_procstep(in_node) == 'A')
	{
		i_step = 11;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "FLOW"); //FLOW
	}
	// 사업부별 반품 창고 조회
	else if (TRS.get_procstep(in_node) == 'B')
	{
		i_step = 12;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// 사업부별 자재 창고 조회
	else if (TRS.get_procstep(in_node) == 'C')
	{
		i_step = 13;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	//공정 찾기 : 사업부별 작업장별 공정 찾기 
	else if (TRS.get_procstep(in_node) == 'D')
	{
		i_step = 14;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
	}
    //공정 찾기 : 외주 공정 찾기 
    else if (TRS.get_procstep(in_node) == 'E')
    {
        i_step = 15;

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
    }
	//사업부별 생산 창고 + 자재 창고 + 자재 반납 창고 + 위탁 + 금형 + 완제품
	else if (TRS.get_procstep(in_node) == 'F')
	{
		i_step = 16;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	else if (TRS.get_procstep(in_node) == 'G')
	{
		i_step = 17;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	else if (TRS.get_procstep(in_node) == 'H')
	{
		i_step = 18;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
    //사업부, 작업장별 공정 ALL
    else if (TRS.get_procstep(in_node) == 'I')
    {
        i_step = 19;

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
    }
	// P급 창고
	else if (TRS.get_procstep(in_node) == 'J')
	{
		i_step = 20;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	//공정 찾기 : 사업부별 작업장별 공정 찾기 
	else if (TRS.get_procstep(in_node) == 'K')
	{
		i_step = 21;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
	}
    //공정 찾기 : 컵셀맵핑공정 찾기 (D12, CELL)
    else if (TRS.get_procstep(in_node) == 'L')
    {
        i_step = 22;

        DBU_init_mwipoprdef(&MWIPOPRDEF);
        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
    }
	//사업부, 사업장 별 공정 및 창고 조회
	else if (TRS.get_procstep(in_node) == 'M')
	{
		i_step = 23;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
	}
	// 자재 창고 + 생산 창고 + 완제품 창고 + 반품 창고
	else if (TRS.get_procstep(in_node) == 'O')
	{
		i_step = 24;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// 자재 창고 + 생산 창고 + 완제품 창고 + 반품 창고
	else if (TRS.get_procstep(in_node) == 'O')
	{
		i_step = 24;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// 자재 창고 + 생산 창고 + 완제품 창고
	else if (TRS.get_procstep(in_node) == 'P')
	{
		i_step = 25;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
	// 완제품 창고 + 출하대기 창고 + 반품 창고
	else if (TRS.get_procstep(in_node) == 'Q')
	{
		i_step = 26;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}
    // 공정 창ㅇ고 + 완제품 창고 + 출하대기 창고 + 반품 창고
    else if (TRS.get_procstep(in_node) == 'R')
    {
        i_step = 27;

        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
    }
    // 외주 창고 조회
    else if (TRS.get_procstep(in_node) == 'S')
    {
        i_step = 28;

        TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
        MWIPOPRDEF.INV_FLAG = 'Y';
    }
	// 사업부 작업장별 생산 창고 + 완제품 창고 + 반품 창고 + P급 창고
	// 베트남 요구사항 : 이동(임의의 P급 창고 1개 추가)
	// 기존 P급 -> 신규 P급으로 이동가능하게 
	else if (TRS.get_procstep(in_node) == 'T')
	{
		i_step = 29;

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		TRS.copy(MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "NEXT_OPER");
	}
	// 사업부별 위탁 창고 조회
	else if (TRS.get_procstep(in_node) == 'U')
	{
		i_step = 30;

		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID), in_node, "AREA_ID");
		MWIPOPRDEF.INV_FLAG = TRS.get_char(in_node, "INV_FLAG");
	}

    DBU_open_mwipoprdef(i_step, &MWIPOPRDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        //WIP-0010 : 이 공정은 존재 하지 않습니다.
        strcpy(s_msg_code, "WIP-0010");
        TRS.add_fieldmsg(out_node, "MWIPOPRDEF OPEN", MP_NVST);
        TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
        TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPOPRDEF.SUB_AREA_ID), MWIPOPRDEF.SUB_AREA_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_mwipoprdef(i_step, &MWIPOPRDEF);
        if (DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_mwipoprdef(i_step);
            break;
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0010 : 이 공정은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0010");
            TRS.add_fieldmsg(out_node, "MWIPOPRDEF FETCH", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
            TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MWIPOPRDEF.SUB_AREA_ID), MWIPOPRDEF.SUB_AREA_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            DBU_close_mwipoprdef(i_step);

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        if (COM_check_node_length(out_node) == MP_FALSE)
        {
            TRS.add_string(out_node, "NEXT_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_close_mwipoprdef(i_step);
            break;
        }

        list_item = TRS.add_node(out_node, "OPER_LIST");

        TRS.add_string(list_item, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
        TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
        TRS.add_string(list_item, "OPER_SHORT_DESC", MWIPOPRDEF.OPER_SHORT_DESC, sizeof(MWIPOPRDEF.OPER_SHORT_DESC));
    }


    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Oper_List_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_OPER_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Oper_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123456789ABCDEFGHIJKLMOPQRSTU") == MP_FALSE)
    {
        return MP_FALSE;
    }

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
