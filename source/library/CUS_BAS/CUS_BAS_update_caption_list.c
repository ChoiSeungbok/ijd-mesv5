/******************************************************************************'

    System      : MESplus
    Module      : CUS_BAS
    File Name   : CUS_BAS_update_caption_list.c
    Description : Caption Setup function module

    MES Version : 5.3.4

    Function List
        - CUS_BAS_Update_Caption_List()
            + Create/Update/Delete Caption definition
        - CUS_BAS_UPDATE_CAPTION_LIST()
            + Main sub function of CUS_BAS_Update_Caption_List function
            + Create/Update/Delete Caption definition
        - CUS_BAS_Update_Caption_List_Validation()
            + Main sub function of CUS_BAS_UPDATE_CAPTION_LIST function
            + Check the condition for create/update/delete Caption
    Detail Description
        - CUS_BAS_UPDATE_CAPTION_LIST()
            + h_proc_step
                + MP_STEP_CREATE : Create Caption definition
                + MP_STEP_UPDATE : Update Caption definition
                + MP_STEP_DELETE : Delete Caption definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2019/03/17  WG,Jung        Create by Generator

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_common.h"

int CUS_BAS_UPDATE_CAPTION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_Update_Caption_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_BAS_Update_Caption_List()
        - Create/Update/Delete Caption definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Caption_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_UPDATE_CAPTION_LIST(s_msg_code, in_node, out_node);

    if(i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 

    COM_out_msg_log_write(s_msg_code,"CUS_BAS_Update_Caption_List", out_node);

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
    CUS_BAS_UPDATE_CAPTION_LIST()
        - Main sub function of "CUS_BAS_Update_Caption_List" function
        - Create/Update/Delete Caption definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE) 
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure 
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_CAPTION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{ 
    struct CBASCPTDEF_TAG CBASCPTDEF;

    int i = 0;
    int i_count = 0;
    char c_flag = ' ';

    TRSNode **list_item;

    LOG_head("CUS_BAS_UPDATE_CAPTION_LIST");
    TRS.log_add_all_members(in_node);

    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    if(CUS_BAS_Update_Caption_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE) 
        return MP_FALSE;
    
    DBU_init_cbascptdef(&CBASCPTDEF); 

    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        list_item = TRS.get_list(in_node, "LIST");
        i_count = TRS.get_item_count(in_node, "LIST");

        for(i = 0; i < i_count; i++) 
        {
            DBU_init_cbascptdef(&CBASCPTDEF); 
            TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), list_item[i], "CAPTION_TYPE");
            TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), list_item[i], "CAPTION_KEY");
            DBU_select_cbascptdef_for_update(1, &CBASCPTDEF);
            if(DB_error_code != DB_SUCCESS)
            {
                if(DB_error_code == DB_NOT_FOUND)
                {
                    c_flag = 'I';
                }
                else
                {
                    strcpy(s_msg_code, "CMN-0004"); 
                    TRS.add_fieldmsg(out_node, "CBASCPTDEF SELECT FOR UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
                    TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;
                    
                    return MP_FALSE; 
                }
            }
            else
            {
                c_flag = 'U';
            }

            TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), list_item[i], "CAPTION_TYPE");
            TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), list_item[i], "CAPTION_KEY");
            TRS.copy(CBASCPTDEF.CAPTION_MSG_1, sizeof(CBASCPTDEF.CAPTION_MSG_1), list_item[i], "CAPTION_MSG_1");
            TRS.copy(CBASCPTDEF.CAPTION_MSG_2, sizeof(CBASCPTDEF.CAPTION_MSG_2), list_item[i], "CAPTION_MSG_2");
            TRS.copy(CBASCPTDEF.CAPTION_MSG_3, sizeof(CBASCPTDEF.CAPTION_MSG_3), list_item[i], "CAPTION_MSG_3");
            TRS.copy(CBASCPTDEF.CAPTION_CMF_10, sizeof(CBASCPTDEF.CAPTION_CMF_10), in_node, "CAPTION_CMF_10");

            if (c_flag == 'I')
            {
                TRS.copy(CBASCPTDEF.CREATE_USER_ID, sizeof(CBASCPTDEF.CREATE_USER_ID), in_node, IN_USERID);
                DB_get_systime(CBASCPTDEF.CREATE_TIME);
            
                DBU_insert_cbascptdef(&CBASCPTDEF); 
                if(DB_error_code != DB_SUCCESS)
                { 
                    strcpy(s_msg_code, "CMN-0004"); 
                    TRS.add_fieldmsg(out_node, "CBASCPTDEF INSERT", MP_NVST); 
                    TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
                    TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    return MP_FALSE; 
                } 
            }
            else if (c_flag == 'U')
            {
                TRS.copy(CBASCPTDEF.UPDATE_USER_ID, sizeof(CBASCPTDEF.UPDATE_USER_ID), in_node, IN_USERID);
                TRS.copy(CBASCPTDEF.UPDATE_TIME, sizeof(CBASCPTDEF.UPDATE_TIME), in_node, "_IN_TIME");
            
                DBU_update_cbascptdef(1, &CBASCPTDEF); 
                if(DB_error_code != DB_SUCCESS)
                { 
                    strcpy(s_msg_code, "CMN-0004"); 
                    TRS.add_fieldmsg(out_node, "CBASCPTDEF UPDATE", MP_NVST); 
                    TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
                    TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    return MP_FALSE; 
                } 
            }
        }
    }
    
    return MP_TRUE; 
} 

/*******************************************************************************
    CUS_BAS_Update_Caption_List_Validation()
        - Main sub function of "CUS_BAS_UPDATE_CAPTION_LIST" function
        - Check the condition for create/update/delete Caption & vbCrLf    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Caption_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    int i = 0;
    int i_count = 0;
    TRSNode **list_item;

    /* ProcStep Validation */
    if(COM_service_validation(s_msg_code,
                            in_node,
                            out_node,
                            TRS.get_procstep(in_node),
                            "IUD") == MP_FALSE)
    {
        return MP_FALSE;
    }

    list_item = TRS.get_list(in_node, "LIST");
    i_count = TRS.get_item_count(in_node, "LIST");

    for(i = 0; i < i_count; i++) 
    {
        /* Caption_type Validation */
        if(COM_isnullspace(TRS.get_string(list_item[i], "CAPTION_TYPE")) == MP_TRUE)
        {
            strcpy(s_msg_code, "CMN-0001");
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }

        /* Caption_key Validation */
        if(COM_isnullspace(TRS.get_string(list_item[i], "CAPTION_KEY")) == MP_TRUE)
        {
            strcpy(s_msg_code, "CMN-0001");
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }
    }

    return MP_TRUE;
}
