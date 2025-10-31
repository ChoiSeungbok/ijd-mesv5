/*******************************************************************************

System      : MESplus
Module      : CUS_IFS
File Name   : CUS_IFS_completion_trx.c
Description : I/F Completion Trx function(생산완공등록)

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/17  SR.SON        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_IFS_common.h"

int CUS_IFS_Completion_Trx_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_IFS_Completion_Trx()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Completion_Trx(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_IFS_COMPLETION_TRX(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_IFS_Completion_Trx", out_node);
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
CUS_IFS_COMPLETION_TRX()
- Main sub function of "CUS_IFS_Completion_Trx" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_COMPLETION_TRX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct IF_COMPLETION_TRX_TAG IF_COMPLETION_TRX;
	struct IF_COMPLETION_TRX_TAG IF_COMPLETION_TRX_AF;

	double d_if_seq = 0;

    LOG_head("CUS_IFS_Completion_Trx");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_IFS_Completion_Trx_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_if_completion_trx(&IF_COMPLETION_TRX);

    if (TRS.get_char(in_node, "TRAN_FLAG") == 'I')
    {
        IF_COMPLETION_TRX.IF_CODE = 'N';		
        //IF_COMPLETION_TRX.IF_CODE = 'T';            //임시 배치에서 S로 변경

        IF_COMPLETION_TRX.TRAN_FLAG = TRS.get_char(in_node, "TRAN_FLAG");
        memcpy(IF_COMPLETION_TRX.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_COMPLETION_TRX.FACTORY, sizeof(IF_COMPLETION_TRX.FACTORY), in_node, IN_FACTORY);
        IF_COMPLETION_TRX.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
        TRS.copy(IF_COMPLETION_TRX.TRAN_TYPE, sizeof(IF_COMPLETION_TRX.TRAN_TYPE), in_node, "TRAN_TYPE");
        memcpy(IF_COMPLETION_TRX.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
        IF_COMPLETION_TRX.ERP_ORDER_NUM = TRS.get_int(in_node, "ERP_ORDER_NUM");
        IF_COMPLETION_TRX.ERP_AREA_ID = TRS.get_int(in_node, "ERP_AREA_ID");
        TRS.copy(IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID), in_node, "AREA_ID");
        IF_COMPLETION_TRX.ERP_WO_ID = TRS.get_int(in_node, "ERP_WO_ID");
        TRS.copy(IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID), in_node, "WO_ID");
        TRS.copy(IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER), in_node, "INV_OPER");
        TRS.copy(IF_COMPLETION_TRX.FROM_STEP, sizeof(IF_COMPLETION_TRX.FROM_STEP), in_node, "FROM_STEP");
        IF_COMPLETION_TRX.ERP_MAT_ID = TRS.get_int(in_node, "ERP_MAT_ID");
        TRS.copy(IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID), in_node, "MAT_ID");
        TRS.copy(IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT), in_node, "UNIT");

		//WIP Assembly Completion = 44 + 수량
		//Wip Assembly Return = 17 - 수량
		if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 44)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 17)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY")) * -1;
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 43)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 35)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY")) * -1;
		}
		else
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}

        
        IF_COMPLETION_TRX.TRAN_HEADER_ID = TRS.get_double(in_node, "TRAN_HEADER_ID");
        IF_COMPLETION_TRX.SRC_TRAN_ID = TRS.get_int(in_node, "SRC_TRAN_ID");
        IF_COMPLETION_TRX.MMT_TRAN_ID = TRS.get_int(in_node, "MMT_TRAN_ID");
        IF_COMPLETION_TRX.MMT_TRAN_HEADER_ID = TRS.get_int(in_node, "MMT_TRAN_HEADER_ID");
        TRS.copy(IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER), in_node, "MES_OPER");
        TRS.copy(IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX.LOT_ID), in_node, "LOT_ID");
        TRS.copy(IF_COMPLETION_TRX.CMF_1, sizeof(IF_COMPLETION_TRX.CMF_1), in_node, "CMF_1");
        TRS.copy(IF_COMPLETION_TRX.CMF_2, sizeof(IF_COMPLETION_TRX.CMF_2), in_node, "CMF_2");
        TRS.copy(IF_COMPLETION_TRX.CMF_3, sizeof(IF_COMPLETION_TRX.CMF_3), in_node, "CMF_3");
        TRS.copy(IF_COMPLETION_TRX.CMF_4, sizeof(IF_COMPLETION_TRX.CMF_4), in_node, "CMF_4");
        TRS.copy(IF_COMPLETION_TRX.CMF_5, sizeof(IF_COMPLETION_TRX.CMF_5), in_node, "CMF_5");
        TRS.copy(IF_COMPLETION_TRX.CMF_6, sizeof(IF_COMPLETION_TRX.CMF_6), in_node, "CMF_6");
        TRS.copy(IF_COMPLETION_TRX.CMF_7, sizeof(IF_COMPLETION_TRX.CMF_7), in_node, "CMF_7");
        TRS.copy(IF_COMPLETION_TRX.CMF_8, sizeof(IF_COMPLETION_TRX.CMF_8), in_node, "CMF_8");
        TRS.copy(IF_COMPLETION_TRX.CMF_9, sizeof(IF_COMPLETION_TRX.CMF_9), in_node, "CMF_9");
        TRS.copy(IF_COMPLETION_TRX.CMF_10, sizeof(IF_COMPLETION_TRX.CMF_10), in_node, "CMF_10");
        TRS.copy(IF_COMPLETION_TRX.CREATE_USER_ID, sizeof(IF_COMPLETION_TRX.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_COMPLETION_TRX.CREATE_TIME, gs_sys_time, sizeof(IF_COMPLETION_TRX.CREATE_TIME));
        TRS.copy(IF_COMPLETION_TRX.UPDATE_USER_ID, sizeof(IF_COMPLETION_TRX.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_COMPLETION_TRX.UPDATE_TIME, gs_sys_time, sizeof(IF_COMPLETION_TRX.UPDATE_TIME));

		/*if (TRS.get_char(in_node, "CHANGE_ITEM") == 'Y')
			DBU_insert_if_completion_trx_item_change(&IF_COMPLETION_TRX);
		else*/
			DBU_insert_if_completion_trx(&IF_COMPLETION_TRX);
        
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_COMPLETION_TRX.FACTORY), IF_COMPLETION_TRX.FACTORY);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

		if (TRS.get_double(in_node, "TRAN_HEADER_ID") == 0)
		{
			//IF SEQ 조회
			DBU_init_if_completion_trx(&IF_COMPLETION_TRX_AF);
			TRS.copy(IF_COMPLETION_TRX_AF.FACTORY, sizeof(IF_COMPLETION_TRX_AF.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_COMPLETION_TRX_AF.LOT_ID, IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX_AF.LOT_ID));
			IF_COMPLETION_TRX_AF.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
			d_if_seq = (double)DBU_select_if_completion_trx_scalar(2, &IF_COMPLETION_TRX_AF);

			IF_COMPLETION_TRX.IF_SEQ = d_if_seq;
			IF_COMPLETION_TRX.TRAN_HEADER_ID = d_if_seq;
			IF_COMPLETION_TRX.SRC_TRAN_ID = d_if_seq;
			DBU_update_if_completion_trx(1, &IF_COMPLETION_TRX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");

				TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_COMPLETION_TRX.FACTORY), IF_COMPLETION_TRX.FACTORY);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

            TRS.add_double(out_node, "TRAN_HEADER_ID", d_if_seq);
		}

		
    }
    else if (TRS.get_char(in_node, "TRAN_FLAG") == 'D')
    {
		IF_COMPLETION_TRX.IF_CODE = 'W';
		//IF_COMPLETION_TRX.TRAN_FLAG = TRS.get_char(in_node, "TRAN_FLAG");
		IF_COMPLETION_TRX.TRAN_FLAG = MP_STEP_CREATE;
		memcpy(IF_COMPLETION_TRX.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
		TRS.copy(IF_COMPLETION_TRX.FACTORY, sizeof(IF_COMPLETION_TRX.FACTORY), in_node, IN_FACTORY);
		IF_COMPLETION_TRX.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
		TRS.copy(IF_COMPLETION_TRX.TRAN_TYPE, sizeof(IF_COMPLETION_TRX.TRAN_TYPE), in_node, "TRAN_TYPE");
		memcpy(IF_COMPLETION_TRX.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
		IF_COMPLETION_TRX.ERP_ORDER_NUM = TRS.get_int(in_node, "ERP_ORDER_NUM");
		IF_COMPLETION_TRX.ERP_AREA_ID = TRS.get_int(in_node, "ERP_AREA_ID");
		TRS.copy(IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID), in_node, "AREA_ID");
		IF_COMPLETION_TRX.ERP_WO_ID = TRS.get_int(in_node, "ERP_WO_ID");
		TRS.copy(IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID), in_node, "WO_ID");
		TRS.copy(IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER), in_node, "INV_OPER");
		TRS.copy(IF_COMPLETION_TRX.FROM_STEP, sizeof(IF_COMPLETION_TRX.FROM_STEP), in_node, "FROM_STEP");
		IF_COMPLETION_TRX.ERP_MAT_ID = TRS.get_int(in_node, "ERP_MAT_ID");
		TRS.copy(IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID), in_node, "MAT_ID");
		TRS.copy(IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT), in_node, "UNIT");

		//WIP Assembly Completion = 44 + 수량
		//Wip Assembly Return = 17 - 수량
		if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 44)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 17)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY")) * -1;
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 43)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}
		else if (TRS.get_int(in_node, "TRAN_TYPE_ID") == 35)
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY")) * -1;
		}
		else
		{
			IF_COMPLETION_TRX.QTY = fabs(TRS.get_double(in_node, "QTY"));
		}


		IF_COMPLETION_TRX.TRAN_HEADER_ID = TRS.get_double(in_node, "TRAN_HEADER_ID");
		IF_COMPLETION_TRX.SRC_TRAN_ID = TRS.get_double(in_node, "SRC_TRAN_ID");
		IF_COMPLETION_TRX.MMT_TRAN_ID = TRS.get_double(in_node, "MMT_TRAN_ID");
		IF_COMPLETION_TRX.MMT_TRAN_HEADER_ID = TRS.get_double(in_node, "MMT_TRAN_HEADER_ID");
		TRS.copy(IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER), in_node, "MES_OPER");
		TRS.copy(IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX.LOT_ID), in_node, "LOT_ID");
		TRS.copy(IF_COMPLETION_TRX.CMF_1, sizeof(IF_COMPLETION_TRX.CMF_1), in_node, "CMF_1");
		TRS.copy(IF_COMPLETION_TRX.CMF_2, sizeof(IF_COMPLETION_TRX.CMF_2), in_node, "CMF_2");
		TRS.copy(IF_COMPLETION_TRX.CMF_3, sizeof(IF_COMPLETION_TRX.CMF_3), in_node, "CMF_3");
		TRS.copy(IF_COMPLETION_TRX.CMF_4, sizeof(IF_COMPLETION_TRX.CMF_4), in_node, "CMF_4");
		TRS.copy(IF_COMPLETION_TRX.CMF_5, sizeof(IF_COMPLETION_TRX.CMF_5), in_node, "CMF_5");
		TRS.copy(IF_COMPLETION_TRX.CMF_6, sizeof(IF_COMPLETION_TRX.CMF_6), in_node, "CMF_6");
		TRS.copy(IF_COMPLETION_TRX.CMF_7, sizeof(IF_COMPLETION_TRX.CMF_7), in_node, "CMF_7");
		TRS.copy(IF_COMPLETION_TRX.CMF_8, sizeof(IF_COMPLETION_TRX.CMF_8), in_node, "CMF_8");
		TRS.copy(IF_COMPLETION_TRX.CMF_9, sizeof(IF_COMPLETION_TRX.CMF_9), in_node, "CMF_9");
		TRS.copy(IF_COMPLETION_TRX.CMF_10, sizeof(IF_COMPLETION_TRX.CMF_10), in_node, "CMF_10");
		TRS.copy(IF_COMPLETION_TRX.CREATE_USER_ID, sizeof(IF_COMPLETION_TRX.CREATE_USER_ID), in_node, IN_USERID);
		memcpy(IF_COMPLETION_TRX.CREATE_TIME, gs_sys_time, sizeof(IF_COMPLETION_TRX.CREATE_TIME));
		TRS.copy(IF_COMPLETION_TRX.UPDATE_USER_ID, sizeof(IF_COMPLETION_TRX.UPDATE_USER_ID), in_node, IN_USERID);
		memcpy(IF_COMPLETION_TRX.UPDATE_TIME, gs_sys_time, sizeof(IF_COMPLETION_TRX.UPDATE_TIME));

		/*if (TRS.get_char(in_node, "CHANGE_ITEM") == 'Y')
		DBU_insert_if_completion_trx_item_change(&IF_COMPLETION_TRX);
		else*/
		DBU_insert_if_completion_trx(&IF_COMPLETION_TRX);

		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");

			TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX INSERT", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_COMPLETION_TRX.FACTORY), IF_COMPLETION_TRX.FACTORY);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (TRS.get_double(in_node, "TRAN_HEADER_ID") == 0)
		{
			//IF SEQ 조회
			DBU_init_if_completion_trx(&IF_COMPLETION_TRX_AF);
			TRS.copy(IF_COMPLETION_TRX_AF.FACTORY, sizeof(IF_COMPLETION_TRX_AF.FACTORY), in_node, IN_FACTORY);
			memcpy(IF_COMPLETION_TRX_AF.LOT_ID, IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX_AF.LOT_ID));
			IF_COMPLETION_TRX_AF.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
			d_if_seq = (double)DBU_select_if_completion_trx_scalar(2, &IF_COMPLETION_TRX_AF);

			IF_COMPLETION_TRX.IF_SEQ = d_if_seq;
			IF_COMPLETION_TRX.TRAN_HEADER_ID = d_if_seq;
			IF_COMPLETION_TRX.SRC_TRAN_ID = d_if_seq;
			DBU_update_if_completion_trx(1, &IF_COMPLETION_TRX);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");

				TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_COMPLETION_TRX.FACTORY), IF_COMPLETION_TRX.FACTORY);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.add_double(out_node, "TRAN_HEADER_ID", d_if_seq);
		}
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_IFS_Completion_Trx_Validation()
- Validation Check sub function of "CUS_IFS_COMPLETION_TRX" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Completion_Trx_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
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

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}
