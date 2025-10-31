/*******************************************************************************

System      : MESplus
Module      : CUS_BAS
File Name   : CUS_BAS_View_Global_Area_List.c
Description : 글로별 area list 조회

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/09  WG.LEE         Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAS_common.h"

int CUS_BAS_View_Global_Area_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_VIEW_GLOBAL_AREA_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAS_View_Global_Area_List()
- View Global Area List function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_View_Global_Area_List(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_VIEW_GLOBAL_AREA_LIST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_View_Global_Area_List", out_node);
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
CUS_BAS_VIEW_GLOBAL_AREA_LIST()
- Main sub function of "CUS_BAS_View_Global_Area_List" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_VIEW_GLOBAL_AREA_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MGCMTBLDAT_TAG MGCMTBLDAT;

    TRSNode *list_item;
    int i_step = 0;

    LOG_head("CUS_BAS_View_Global_Area_List");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_BAS_View_Global_Area_List_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
        i_step = 6;
        DBU_init_mgcmtbldat(&MGCMTBLDAT);
        memcpy(MGCMTBLDAT.FACTORY, MP_SYS_FACTORY, strlen(MP_SYS_FACTORY));
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_GLOBAL_AREA, strlen(MP_GCM_GLOBAL_AREA));
        DBU_open_mgcmtbldat(i_step, &MGCMTBLDAT);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "BAS-0004");
            TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
            TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
            TRS.add_dberrmsg(out_node, DB_error_msg);
            return MP_FALSE;
        }

        // FETCH
        while (1)
        {
            DBU_fetch_mgcmtbldat(i_step, &MGCMTBLDAT);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mgcmtbldat(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "BAS-0004");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                TRS.add_dberrmsg(out_node, DB_error_msg);

				// 20.12.21 minjae.go
				DBU_close_mgcmtbldat(i_step);
				//

                return MP_FALSE;
            }

            list_item = TRS.add_node(out_node, "GCM_TBL");
            TRS.add_string(list_item, "KEY_1", MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1));
            TRS.add_string(list_item, "DATA_1", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
        }        
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_BAS_View_Global_Area_List_Validation()
- Validation Check sub function of "CUS_BAS_VIEW_GLOBAL_AREA_LIST" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_View_Global_Area_List_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    return MP_TRUE;
}