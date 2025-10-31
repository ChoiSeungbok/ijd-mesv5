/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_view_resource_list.c
Description : View Resource List by Oper function

MES Version : 5.0

Function List
- step 1: 설비 조회

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/03  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_ORD_common.h"

int CUS_RAS_View_Resource_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_VIEW_RESOURCE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_RAS_View_Resource_List()
- View Resource List by Oper
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_View_Resource_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_VIEW_RESOURCE_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_View_Resource_List", out_node);
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
CUS_RAS_VIEW_RESOURCE_LIST()
- Main sub function of "CUS_RAS_View_Resource_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_VIEW_RESOURCE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESMFO_TAG MRASRESMFO;  
    struct MRASRESDEF_TAG MRASRESDEF;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_RAS_View_Resource_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_RAS_View_Resource_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    i_step = 0;

    //step 2 : 공정에 대한 설비 찾기
    if (TRS.get_procstep(in_node) == '1')
    {
        i_step = 2;

        DBU_init_mrasresmfo(&MRASRESMFO);
        TRS.copy(MRASRESMFO.FACTORY, sizeof(MRASRESMFO.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASRESMFO.OPER, sizeof(MRASRESMFO.OPER), in_node, "OPER");
        TRS.copy(MRASRESMFO.RES_ID, sizeof(MRASRESMFO.RES_ID), in_node, "NEXT_RES_ID");

        DBU_open_mrasresmfo(i_step, &MRASRESMFO);
        if (DB_error_code != DB_SUCCESS)
        {
            //RAS-0320 : 공정에 설비가 존재하지 않습니다.
            strcpy(s_msg_code, "RAS-0320");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESMFO.FACTORY), MRASRESMFO.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MRASRESMFO.OPER), MRASRESMFO.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mrasresmfo(i_step, &MRASRESMFO);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mrasresmfo(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //RAS-0320 : 공정에 설비가 존재하지 않습니다.
                strcpy(s_msg_code, "RAS-0320");
                TRS.add_fieldmsg(out_node, "MWIPORDSTS OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESMFO.FACTORY), MRASRESMFO.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MRASRESMFO.OPER), MRASRESMFO.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mrasresmfo(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_RES_ID", MRASRESMFO.RES_ID, sizeof(MRASRESMFO.RES_ID));
                DBU_close_mrasresmfo(i_step);
                break;
            }

            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MRASRESMFO.FACTORY, sizeof(MRASRESMFO.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MRASRESMFO.RES_ID, sizeof(MRASRESMFO.RES_ID));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code == DB_SUCCESS)
            {
                list_item = TRS.add_node(out_node, "RES_LIST");
                TRS.add_string(list_item, "RES_ID", MRASRESMFO.RES_ID, sizeof(MRASRESMFO.RES_ID));
                TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
            }
        }
    }
    //step 1 : 설비 그룹에 대한 설비 찾기
    else if (TRS.get_procstep(in_node) == '2')
    {
        i_step = 2;

        DBU_init_mrasresdef(&MRASRESDEF);
        TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASRESDEF.AREA_ID, sizeof(MRASRESDEF.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MRASRESDEF.RES_GRP_1, sizeof(MRASRESDEF.RES_GRP_1), in_node, "RES_GRP_1");
        TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "NEXT_RES_ID");

        DBU_open_mrasresdef(i_step, &MRASRESDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //RAS-0320 : 공정에 설비가 존재하지 않습니다.
            strcpy(s_msg_code, "RAS-0320");
            TRS.add_fieldmsg(out_node, "MRASRESDEF OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "RES_GRP", MP_STR, sizeof(MRASRESDEF.RES_GRP_1), MRASRESDEF.RES_GRP_1);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mrasresdef(i_step, &MRASRESDEF);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mrasresdef(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //RAS-0320 : 공정에 설비가 존재하지 않습니다.
                strcpy(s_msg_code, "RAS-0320");
                TRS.add_fieldmsg(out_node, "MRASRESDEF OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_GRP", MP_STR, sizeof(MRASRESDEF.RES_GRP_1), MRASRESDEF.RES_GRP_1);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mrasresdef(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
                DBU_close_mrasresdef(i_step);
                break;
            }

            list_item = TRS.add_node(out_node, "RES_LIST");
            TRS.add_string(list_item, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
            TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));            
        }
    }
    //step 3 : 작업장에 대한 설비 찾기
    else if (TRS.get_procstep(in_node) == '3')
    {
        DBU_init_mrasresdef(&MRASRESDEF);
        TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MRASRESDEF.SUB_AREA_ID, sizeof(MRASRESDEF.SUB_AREA_ID), in_node, "SUB_AREA_ID");
        
        i_step = 3;
        DBU_open_mrasresdef(i_step, &MRASRESDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //RAS-0320 : 공정에 설비가 존재하지 않습니다.
            strcpy(s_msg_code, "RAS-0320");
            TRS.add_fieldmsg(out_node, "MRASRESDEF OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MRASRESDEF.SUB_AREA_ID), MRASRESDEF.SUB_AREA_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mrasresdef(i_step, &MRASRESDEF);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mrasresdef(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //RAS-0320 : 공정에 설비가 존재하지 않습니다.
                strcpy(s_msg_code, "RAS-0320");
                TRS.add_fieldmsg(out_node, "MRASRESDEF OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "SUB_AREA_ID", MP_STR, sizeof(MRASRESDEF.SUB_AREA_ID), MRASRESDEF.SUB_AREA_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mrasresdef(i_step);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
                DBU_close_mrasresdef(i_step);
                break;
            }

            list_item = TRS.add_node(out_node, "RES_LIST");
            TRS.add_string(list_item, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
            TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
        }
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_View_Resource_List_Validation()
- Validation Check sub function of "CUS_RAS_VIEW_RESOURCE_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_View_Resource_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
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
