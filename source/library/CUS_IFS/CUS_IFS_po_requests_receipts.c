/*******************************************************************************

System      : MESplus
Module      : CUS_IFS
File Name   : CUS_IFS_po_requests_receipts.c
Description : CUS_IFS_po_requests_receipts

MES Version : 5.3.4 ~

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2023/06/21  YS.SONG        Create

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_IFS_common.h"

int CUS_IFS_po_requests_receipts_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

/*******************************************************************************
CUS_IFS_po_requests_receipts()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_po_requests_receipts(TRSNode* in_node, TRSNode* out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_IFS_PO_REQUESTS_RECEIPTS(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_IFS_po_requests_receipts", out_node);
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
CUS_IFS_po_requests_receipts()
- Main sub function of "CUS_IFS_po_requests_receipts" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_PO_REQUESTS_RECEIPTS(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{



    struct IF_PO_REQUESTS_RECEIPTS_TAG IF_PO_REQUESTS_RECEIPTS;


    LOG_head("CUS_IFS_po_requests_receipts");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_IFS_po_requests_receipts_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_if_po_requests_receipts(&IF_PO_REQUESTS_RECEIPTS);


        memcpy(IF_PO_REQUESTS_RECEIPTS.IF_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.IF_TIME, sizeof(IF_PO_REQUESTS_RECEIPTS.IF_TIME), in_node, "IF_TIME");
        IF_PO_REQUESTS_RECEIPTS.IF_CODE_REQ = 'N';
        IF_PO_REQUESTS_RECEIPTS.IF_CODE_REC = 'N';
        memcpy(IF_PO_REQUESTS_RECEIPTS.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.FROM_ORG_CODE, sizeof(IF_PO_REQUESTS_RECEIPTS.FROM_ORG_CODE), in_node, "FROM_ORG_CODE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.TO_ORG_CODE, sizeof(IF_PO_REQUESTS_RECEIPTS.TO_ORG_CODE), in_node, "TO_ORG_CODE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.FROM_ITEM_CODE, sizeof(IF_PO_REQUESTS_RECEIPTS.FROM_ITEM_CODE), in_node, "FROM_ITEM_CODE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.TO_ITEM_CODE, sizeof(IF_PO_REQUESTS_RECEIPTS.TO_ITEM_CODE), in_node, "TO_ITEM_CODE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.UOM, sizeof(IF_PO_REQUESTS_RECEIPTS.UOM), in_node, "UOM");
        IF_PO_REQUESTS_RECEIPTS.QUANTITY = TRS.get_double(in_node, "QUANTITY");
        IF_PO_REQUESTS_RECEIPTS.UNIT_PRICE = TRS.get_double(in_node, "UNIT_PRICE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.FROM_SUBINVENTORY, sizeof(IF_PO_REQUESTS_RECEIPTS.FROM_SUBINVENTORY), in_node, "FROM_SUBINVENTORY");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.TO_SUBINVENTORY, sizeof(IF_PO_REQUESTS_RECEIPTS.TO_SUBINVENTORY), in_node, "TO_SUBINVENTORY");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.NEED_BY_DATE, sizeof(IF_PO_REQUESTS_RECEIPTS.NEED_BY_DATE), in_node, "NEED_BY_DATE");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_1, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_1), in_node, "CMF_1");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_2, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_2), in_node, "CMF_2");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_3, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_3), in_node, "CMF_3");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_4, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_4), in_node, "CMF_4");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_5, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_5), in_node, "CMF_5");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_6, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_6), in_node, "CMF_6");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_7, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_7), in_node, "CMF_7");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_8, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_8), in_node, "CMF_8");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_9, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_9), in_node, "CMF_9");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CMF_10, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_10), in_node, "CMF_10");
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.CREATE_USER_ID, sizeof(IF_PO_REQUESTS_RECEIPTS.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_PO_REQUESTS_RECEIPTS.CREATE_TIME, gs_sys_time, sizeof(IF_PO_REQUESTS_RECEIPTS.CREATE_TIME));
        TRS.copy(IF_PO_REQUESTS_RECEIPTS.UPDATE_USER_ID, sizeof(IF_PO_REQUESTS_RECEIPTS.UPDATE_USER_ID), in_node, IN_USERID);
        memcpy(IF_PO_REQUESTS_RECEIPTS.UPDATE_TIME, gs_sys_time, sizeof(IF_PO_REQUESTS_RECEIPTS.UPDATE_TIME));



        DBU_insert_if_po_requests_receipts(&IF_PO_REQUESTS_RECEIPTS);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");

            TRS.add_fieldmsg(out_node, "IF_PO_REQUESTS_RECEIPTS INSERT", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(IF_PO_REQUESTS_RECEIPTS.CMF_1), IF_PO_REQUESTS_RECEIPTS.CMF_1);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }




    return MP_TRUE;
}



/*******************************************************************************
CUS_IFS_po_requests_receipts_Validation()
- Validation Check sub function of "CUS_IFS_po_requests_receipts" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_IFS_po_requests_receipts_Validation(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{

    /* ProcStep Validation */
    // 1 - 

    /*
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }
    */

    /*
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }
    */


    return MP_TRUE;
}
