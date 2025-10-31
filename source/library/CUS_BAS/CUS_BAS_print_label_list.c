/*******************************************************************************

System      : MESplus
Module      : CUS_BAS
File Name   : CUS_BAS_print_label_list.c
Description : 라벨수기입력발행

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/02  SR.SON         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAS_common.h"

int CUS_BAS_Print_Label_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_PRINT_LABEL_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAS_Print_Label_List()
- CUS_BAS_Print_Label_List function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Print_Label_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_PRINT_LABEL_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_Print_Label_List", out_node);
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
CUS_BAS_PRINT_LABEL_LIST()
- Main sub function of "CUS_BAS_Print_Label_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_PRINT_LABEL_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
    struct CBASLBLDAT_TAG CBASLBLDAT;

    TRSNode **label_list;
    TRSNode *list_item;
    int label_list_count = 0;
    char c_flag = ' ';
    int seq = 0;

    LOG_head("CUS_BAS_Print_Label_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_BAS_Print_Label_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    label_list = TRS.get_list(in_node, "LABEL_LIST");
    label_list_count = TRS.get_item_count(in_node, "LABEL_LIST");

    // step 1 : 생성 or update 
    if (TRS.get_procstep(in_node) == '1')
    {
        for (int i = 0; i < label_list_count; i++)
        {
            DBU_init_cbaslbldat(&CBASLBLDAT);
            TRS.copy(CBASLBLDAT.FACTORY, sizeof(CBASLBLDAT.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CBASLBLDAT.AREA_ID, sizeof(CBASLBLDAT.AREA_ID), in_node, "AREA_ID");
            TRS.copy(CBASLBLDAT.FILE_NAME, sizeof(CBASLBLDAT.FILE_NAME), in_node, "FILE_NAME");
            CBASLBLDAT.SEQ = TRS.get_int(label_list[i], "SEQ");

            DBU_select_cbaslbldat(1, &CBASLBLDAT);
            //출력라벨 생성
            if (DB_error_code == DB_NOT_FOUND)
            {
                seq = (int)DBU_select_cbaslbldat_scalar(2, &CBASLBLDAT);
                CBASLBLDAT.SEQ = seq;
                TRS.copy(CBASLBLDAT.LABEL_SIZE, sizeof(CBASLBLDAT.LABEL_SIZE), in_node, "LABEL_SIZE");               
                memcpy(CBASLBLDAT.CREATE_TIME, gs_sys_time,sizeof(CBASLBLDAT.CREATE_TIME));
                memcpy(CBASLBLDAT.PRINT_DATE, CBASLBLDAT.CREATE_TIME, 8);
                TRS.copy(CBASLBLDAT.CREATE_USER_ID, sizeof(CBASLBLDAT.CREATE_USER_ID), in_node, IN_USERID);
                c_flag = 'I';
            }
            //출력 라벨 update
            else if (DB_error_code == DB_SUCCESS)
            {
                memcpy(CBASLBLDAT.UPDATE_TIME, gs_sys_time, sizeof(CBASLBLDAT.UPDATE_TIME));
                TRS.copy(CBASLBLDAT.UPDATE_USER_ID, sizeof(CBASLBLDAT.UPDATE_USER_ID), in_node, IN_USERID);
                c_flag = 'U';
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CBASLBLDAT SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASLBLDAT.FACTORY), CBASLBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASLBLDAT.AREA_ID), CBASLBLDAT.AREA_ID);
                TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASLBLDAT.FILE_NAME), CBASLBLDAT.FILE_NAME);
                TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASLBLDAT.SEQ);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                return MP_FALSE;
            }

            TRS.copy(CBASLBLDAT.LOT_ID, sizeof(CBASLBLDAT.LOT_ID), label_list[i], "LOT_ID");
            TRS.copy(CBASLBLDAT.ITEM_CODE, sizeof(CBASLBLDAT.ITEM_CODE), label_list[i], "ITEM_CODE");
            TRS.copy(CBASLBLDAT.ITEM_NAME, sizeof(CBASLBLDAT.ITEM_NAME), label_list[i], "ITEM_NAME");
            TRS.copy(CBASLBLDAT.INPUT_DATE, sizeof(CBASLBLDAT.INPUT_DATE), label_list[i], "INPUT_DATE");
            CBASLBLDAT.LOT_QTY = TRS.get_double(label_list[i], "LOT_QTY");
            TRS.copy(CBASLBLDAT.UOM, sizeof(CBASLBLDAT.UOM), label_list[i], "UOM");
            TRS.copy(CBASLBLDAT.VENDOR_NAME, sizeof(CBASLBLDAT.VENDOR_NAME), label_list[i], "VENDOR_NAME");
            TRS.copy(CBASLBLDAT.SUPPLIER_LOT_ID, sizeof(CBASLBLDAT.SUPPLIER_LOT_ID), label_list[i], "SUPPLIER_LOT_ID");
            TRS.copy(CBASLBLDAT.CELL_NO, sizeof(CBASLBLDAT.CELL_NO), label_list[i], "CELL_NO");
            TRS.copy(CBASLBLDAT.WO_NO, sizeof(CBASLBLDAT.WO_NO), label_list[i], "WO_NO");
            TRS.copy(CBASLBLDAT.PC0201, sizeof(CBASLBLDAT.PC0201), label_list[i], "PC0201");
            TRS.copy(CBASLBLDAT.PC0202, sizeof(CBASLBLDAT.PC0202), label_list[i], "PC0202");
            TRS.copy(CBASLBLDAT.PC0203, sizeof(CBASLBLDAT.PC0203), label_list[i], "PC0203");
            TRS.copy(CBASLBLDAT.PC0204, sizeof(CBASLBLDAT.PC0204), label_list[i], "PC0204");
            TRS.copy(CBASLBLDAT.MAIN_LOT_ID, sizeof(CBASLBLDAT.MAIN_LOT_ID), label_list[i], "MAIN_LOT_ID");
            TRS.copy(CBASLBLDAT.GRADE, sizeof(CBASLBLDAT.GRADE), label_list[i], "GRADE");
            TRS.copy(CBASLBLDAT.ITEM_UOM, sizeof(CBASLBLDAT.ITEM_UOM), label_list[i], "ITEM_UOM");
            TRS.copy(CBASLBLDAT.REMARKS, sizeof(CBASLBLDAT.REMARKS), label_list[i], "REMARKS");
            TRS.copy(CBASLBLDAT.GROUP_ID, sizeof(CBASLBLDAT.GROUP_ID), label_list[i], "GROUP_ID");
            TRS.copy(CBASLBLDAT.ITEM_NAME1, sizeof(CBASLBLDAT.ITEM_NAME1), label_list[i], "ITEM_NAME1");
            TRS.copy(CBASLBLDAT.ITEM_NAME2, sizeof(CBASLBLDAT.ITEM_NAME2), label_list[i], "ITEM_NAME2");
            TRS.copy(CBASLBLDAT.TYPE, sizeof(CBASLBLDAT.TYPE), label_list[i], "TYPE");
            TRS.copy(CBASLBLDAT.SPEC, sizeof(CBASLBLDAT.SPEC), label_list[i], "SPEC");
            TRS.copy(CBASLBLDAT.ITEM, sizeof(CBASLBLDAT.ITEM), label_list[i], "ITEM");
            TRS.copy(CBASLBLDAT.PO_NUMBER, sizeof(CBASLBLDAT.PO_NUMBER), label_list[i], "PO_NUMBER");
            TRS.copy(CBASLBLDAT.MN_NO, sizeof(CBASLBLDAT.MN_NO), label_list[i], "MN_NO");
            TRS.copy(CBASLBLDAT.DRAWING_FLAG, sizeof(CBASLBLDAT.DRAWING_FLAG), label_list[i], "DRAWING_FLAG");
            TRS.copy(CBASLBLDAT.COAT, sizeof(CBASLBLDAT.COAT), label_list[i], "COAT");

            TRS.add_string(out_node, "FACTORY", CBASLBLDAT.FACTORY, sizeof(CBASLBLDAT.FACTORY));
            TRS.add_string(out_node, "AREA_ID", CBASLBLDAT.AREA_ID, sizeof(CBASLBLDAT.AREA_ID));
            TRS.add_string(out_node, "FILE_NAME", CBASLBLDAT.FILE_NAME, sizeof(CBASLBLDAT.FILE_NAME));

            list_item = TRS.add_node(out_node, "LABEL_LIST");

            if (c_flag == 'I')
            {
                DBU_insert_cbaslbldat(&CBASLBLDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CBASLBLDAT INSERT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASLBLDAT.FACTORY), CBASLBLDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASLBLDAT.AREA_ID), CBASLBLDAT.AREA_ID);
                    TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASLBLDAT.FILE_NAME), CBASLBLDAT.FILE_NAME);
                    TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASLBLDAT.SEQ);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                    return MP_FALSE;
                }
                          
                TRS.add_int(list_item, "SEQ",seq);
            }
            else if (c_flag == 'U')
            {
                DBU_update_cbaslbldat(1, &CBASLBLDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CBASLBLDAT UPDATE ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASLBLDAT.FACTORY), CBASLBLDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASLBLDAT.AREA_ID), CBASLBLDAT.AREA_ID);
                    TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASLBLDAT.FILE_NAME), CBASLBLDAT.FILE_NAME);
                    TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASLBLDAT.SEQ);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_TRANS;
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

                    return MP_FALSE;
                }

                TRS.add_int(list_item, "SEQ", CBASLBLDAT.SEQ);
            }
        }      
    }
    // step 2 : 삭제
    else if (TRS.get_procstep(in_node) == '2')
    {
        for (int i = 0; i < label_list_count; i++)
        {
            DBU_init_cbaslbldat(&CBASLBLDAT);
            TRS.copy(CBASLBLDAT.FACTORY, sizeof(CBASLBLDAT.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CBASLBLDAT.AREA_ID, sizeof(CBASLBLDAT.AREA_ID), in_node, "AREA_ID");
            TRS.copy(CBASLBLDAT.FILE_NAME, sizeof(CBASLBLDAT.FILE_NAME), in_node, "FILE_NAME");
            CBASLBLDAT.SEQ = TRS.get_int(label_list[i], "SEQ");

            DBU_delete_cbaslbldat(1, &CBASLBLDAT);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CBASLBLDAT SELECT ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASLBLDAT.FACTORY), CBASLBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CBASLBLDAT.AREA_ID), CBASLBLDAT.AREA_ID);
                TRS.add_fieldmsg(out_node, "FILE_NAME", MP_STR, sizeof(CBASLBLDAT.FILE_NAME), CBASLBLDAT.FILE_NAME);
                TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CBASLBLDAT.SEQ);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_BAS_Print_Label_Listt_Validation()
- Validation Check sub function of "CUS_BAS_PRINT_LABEL_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Print_Label_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FILE_NAME")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FILE_NAME", MP_NVST);

        return MP_FALSE;
    }

    return MP_TRUE;
}