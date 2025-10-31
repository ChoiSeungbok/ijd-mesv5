/*******************************************************************************

System      : MESplus
Module      : CUS_IFS
File Name   : CUS_IFS_po_rma_headers.c
Description : I/F Po Rma Headers function(반품정보)

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

int CUS_IFS_Po_Rma_Headers_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_IFS_Po_Rma_Headers()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Po_Rma_Headers(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_IFS_PO_RMA_HEADERS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_IFS_Po_Rma_Headers", out_node);
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
CUS_IFS_PO_RMA_HEADERS()
- Main sub function of "CUS_IFS_Po_Rma_Headers" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_PO_RMA_HEADERS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct IF_PO_RMA_HEADERS_TAG IF_PO_RMA_HEADERS;

    LOG_head("CUS_IFS_Po_Rma_Headers");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_IFS_Po_Rma_Headers_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_if_po_rma_headers(&IF_PO_RMA_HEADERS);

    if (TRS.get_char(in_node, "TRAN_FLAG") == 'I')
    {
        IF_PO_RMA_HEADERS.IF_CODE = 'N';
        memcpy(IF_PO_RMA_HEADERS.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_PO_RMA_HEADERS.FACTORY, sizeof(IF_PO_RMA_HEADERS.FACTORY), in_node, IN_FACTORY);
		IF_PO_RMA_HEADERS.TRAN_FLAG = TRS.get_char(in_node, "TRAN_FLAG");
        IF_PO_RMA_HEADERS.TRAN_TYPE_ID = TRS.get_int(in_node, "TRAN_TYPE_ID");
        TRS.copy(IF_PO_RMA_HEADERS.TRAN_TYPE, sizeof(IF_PO_RMA_HEADERS.TRAN_TYPE), in_node, "TRAN_TYPE");
		TRS.copy(IF_PO_RMA_HEADERS.TRAN_TIME, sizeof(IF_PO_RMA_HEADERS.TRAN_TIME), in_node, "RETURN_DATE");
        IF_PO_RMA_HEADERS.CUSTOMER_ID = TRS.get_int(in_node, "CUSTOMER_ID");
        IF_PO_RMA_HEADERS.CUSTOMER_SITE_ID = TRS.get_int(in_node, "CUSTOMER_SITE_ID");
        IF_PO_RMA_HEADERS.ERP_AREA_ID = TRS.get_int(in_node, "ERP_AREA_ID");       
        TRS.copy(IF_PO_RMA_HEADERS.AREA_ID, sizeof(IF_PO_RMA_HEADERS.AREA_ID), in_node, "AREA_ID");
        TRS.copy(IF_PO_RMA_HEADERS.LOT_ID, sizeof(IF_PO_RMA_HEADERS.LOT_ID), in_node, "LOT_ID");
		TRS.copy(IF_PO_RMA_HEADERS.MES_ID, sizeof(IF_PO_RMA_HEADERS.MES_ID), in_node, "MES_ID");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_1, sizeof(IF_PO_RMA_HEADERS.CMF_1), in_node, "CMF_1");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_2, sizeof(IF_PO_RMA_HEADERS.CMF_2), in_node, "CMF_2");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_3, sizeof(IF_PO_RMA_HEADERS.CMF_3), in_node, "CMF_3");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_4, sizeof(IF_PO_RMA_HEADERS.CMF_4), in_node, "CMF_4");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_5, sizeof(IF_PO_RMA_HEADERS.CMF_5), in_node, "CMF_5");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_6, sizeof(IF_PO_RMA_HEADERS.CMF_6), in_node, "CMF_6");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_7, sizeof(IF_PO_RMA_HEADERS.CMF_7), in_node, "CMF_7");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_8, sizeof(IF_PO_RMA_HEADERS.CMF_8), in_node, "CMF_8");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_9, sizeof(IF_PO_RMA_HEADERS.CMF_9), in_node, "CMF_9");
        TRS.copy(IF_PO_RMA_HEADERS.CMF_10, sizeof(IF_PO_RMA_HEADERS.CMF_10), in_node, "CMF_10");
        TRS.copy(IF_PO_RMA_HEADERS.CREATE_USER_ID, sizeof(IF_PO_RMA_HEADERS.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_PO_RMA_HEADERS.CREATE_TIME, gs_sys_time, sizeof(IF_PO_RMA_HEADERS.CREATE_TIME));
        TRS.copy(IF_PO_RMA_HEADERS.UPDATE_USER_ID, sizeof(IF_PO_RMA_HEADERS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_PO_RMA_HEADERS.UPDATE_TIME, gs_sys_time, sizeof(IF_PO_RMA_HEADERS.UPDATE_TIME));

        DBU_insert_if_po_rma_headers(&IF_PO_RMA_HEADERS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "IF_PO_RMA_HEADERS INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(IF_PO_RMA_HEADERS.FACTORY), IF_PO_RMA_HEADERS.FACTORY);
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
CUS_IFS_Po_Rma_Headers_Validation()
- Validation Check sub function of "CUS_IFS_PO_RMA_HEADERS" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_Po_Rma_Headers_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
