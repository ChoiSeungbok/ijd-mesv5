/*******************************************************************************

System      : MESplus
Module      : CUS_IFS
File Name   : CUS_IFS_inv_txns.c
Description : I/F Inv Txns function(자재불출 정보)

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

int CUS_IFS_Inv_Txns_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_IFS_Inv_Txns()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Inv_Txns(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_IFS_INV_TXNS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_IFS_Inv_Txns", out_node);
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
CUS_IFS_INV_TXNS()
- Main sub function of "CUS_IFS_Inv_Txns" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_INV_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct IF_INV_TXNS_TAG IF_INV_TXNS;

    LOG_head("CUS_IFS_Inv_Txns");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_IFS_Inv_Txns_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_if_inv_txns(&IF_INV_TXNS);

    if (TRS.get_char(in_node, "TRAN_FLAG") == 'I')
    {
		IF_INV_TXNS.IF_CODE = 'N';

        memcpy(IF_INV_TXNS.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
		IF_INV_TXNS.TRAN_FLAG = TRS.get_char(in_node, "TRAN_FLAG");
        IF_INV_TXNS.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
        TRS.copy(IF_INV_TXNS.TRAN_TYPE, sizeof(IF_INV_TXNS.TRAN_TYPE), in_node, "TRAN_TYPE");
        memcpy(IF_INV_TXNS.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));       
        IF_INV_TXNS.ERP_AREA_ID = TRS.get_int(in_node, "ERP_AREA_ID");        
        TRS.copy(IF_INV_TXNS.AREA_ID, sizeof(IF_INV_TXNS.AREA_ID), in_node, "AREA_ID");
        IF_INV_TXNS.ERP_MAT_ID = TRS.get_int(in_node, "ERP_MAT_ID");
        TRS.copy(IF_INV_TXNS.MAT_ID, sizeof(IF_INV_TXNS.MAT_ID), in_node, "MAT_ID");
        TRS.copy(IF_INV_TXNS.FROM_OPER, sizeof(IF_INV_TXNS.FROM_OPER), in_node, "FROM_OPER");
        TRS.copy(IF_INV_TXNS.TO_OPER, sizeof(IF_INV_TXNS.TO_OPER), in_node, "TO_OPER");
        TRS.copy(IF_INV_TXNS.UNIT, sizeof(IF_INV_TXNS.UNIT), in_node, "UNIT");
        IF_INV_TXNS.QTY = TRS.get_double(in_node, "QTY");
        IF_INV_TXNS.TO_ERP_AREA_ID = TRS.get_int(in_node, "TO_ERP_AREA_ID");
        TRS.copy(IF_INV_TXNS.TO_AREA_ID, sizeof(IF_INV_TXNS.TO_AREA_ID), in_node, "TO_AREA_ID");
        TRS.copy(IF_INV_TXNS.SRC_CODE, sizeof(IF_INV_TXNS.SRC_CODE), in_node, "SRC_CODE");
        TRS.copy(IF_INV_TXNS.LOT_ID, sizeof(IF_INV_TXNS.LOT_ID), in_node, "LOT_ID");
		TRS.copy(IF_INV_TXNS.MES_ID, sizeof(IF_INV_TXNS.MES_ID), in_node, "MES_ID");
        IF_INV_TXNS.TRAN_SRC_ID = TRS.get_int(in_node, "TRAN_SRC_ID");
        TRS.copy(IF_INV_TXNS.TRAN_SRC_NAME, sizeof(IF_INV_TXNS.TRAN_SRC_NAME), in_node, "TRAN_SRC_NAME");
        TRS.copy(IF_INV_TXNS.CMF_1, sizeof(IF_INV_TXNS.CMF_1), in_node, "CMF_1");
        TRS.copy(IF_INV_TXNS.CMF_2, sizeof(IF_INV_TXNS.CMF_2), in_node, "CMF_2");
        TRS.copy(IF_INV_TXNS.CMF_3, sizeof(IF_INV_TXNS.CMF_3), in_node, "CMF_3");
        TRS.copy(IF_INV_TXNS.CMF_4, sizeof(IF_INV_TXNS.CMF_4), in_node, "CMF_4");
        TRS.copy(IF_INV_TXNS.CMF_5, sizeof(IF_INV_TXNS.CMF_5), in_node, "CMF_5");
        TRS.copy(IF_INV_TXNS.CMF_6, sizeof(IF_INV_TXNS.CMF_6), in_node, "CMF_6");
        TRS.copy(IF_INV_TXNS.CMF_7, sizeof(IF_INV_TXNS.CMF_7), in_node, "CMF_7");
        TRS.copy(IF_INV_TXNS.CMF_8, sizeof(IF_INV_TXNS.CMF_8), in_node, "CMF_8");
        TRS.copy(IF_INV_TXNS.CMF_9, sizeof(IF_INV_TXNS.CMF_9), in_node, "CMF_9");
        TRS.copy(IF_INV_TXNS.CMF_10, sizeof(IF_INV_TXNS.CMF_10), in_node, "CMF_10");
        TRS.copy(IF_INV_TXNS.CREATE_USER_ID, sizeof(IF_INV_TXNS.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_INV_TXNS.CREATE_TIME, gs_sys_time, sizeof(IF_INV_TXNS.CREATE_TIME));
        TRS.copy(IF_INV_TXNS.UPDATE_USER_ID, sizeof(IF_INV_TXNS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_INV_TXNS.UPDATE_TIME, gs_sys_time, sizeof(IF_INV_TXNS.UPDATE_TIME));

        DBU_insert_if_inv_txns(&IF_INV_TXNS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "IF_INV_TXNS INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_INV_TXNS.FACTORY), IF_INV_TXNS.FACTORY);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }
    else if (TRS.get_char(in_node, "TRAN_FLAG") == 'D')
    {
		 
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_IFS_Inv_Txns_Validation()
- Validation Check sub function of "CUS_IFS_INV_TXNS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Inv_Txns_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
