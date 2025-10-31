/*******************************************************************************

System      : MESplus
Module      : CUS_RAS
File Name   : CUS_RAS_Update_Resource_Efficiency_Info.c
Description : 설비효율 기준정보 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/01/28                 Create

Copyright(C) 1998-2021 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_RAS_common.h"


int CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_RAS_Update_Resource_Efficiency_Info()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_Update_Resource_Efficiency_Info(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_RAS_Update_Resource_Efficiency_Info", out_node);
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
CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO()
- Main sub function of "CUS_RAS_Update_Resource_Efficiency_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CRASBASDAT_TAG CRASBASDAT;

    int i = 0;

    LOG_head("CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    //신규/갱신
    if (TRS.get_procstep(in_node) == '1')
    {
        if (CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO_VALIDATION(s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_crasbasdat(&CRASBASDAT);
            TRS.copy(CRASBASDAT.FACTORY, sizeof(CRASBASDAT.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CRASBASDAT.RES_ID, sizeof(CRASBASDAT.RES_ID), in_node->SItems[i], "RES_ID");
            DBU_select_crasbasdat(1, &CRASBASDAT);            
            
            CRASBASDAT.PROC_YN = TRS.get_char(in_node->SItems[i], "PROC_YN");
            CRASBASDAT.NOWORK_TYPE = TRS.get_char(in_node->SItems[i], "NOWORK_TYPE");
            CRASBASDAT.RUN_TYPE = TRS.get_char(in_node->SItems[i], "RUN_TYPE");
           
            TRS.copy(CRASBASDAT.CMF_1, sizeof(CRASBASDAT.CMF_1), in_node->SItems[i], "CMF_1");
            TRS.copy(CRASBASDAT.CMF_2, sizeof(CRASBASDAT.CMF_2), in_node->SItems[i], "CMF_2");
            TRS.copy(CRASBASDAT.CMF_3, sizeof(CRASBASDAT.CMF_3), in_node->SItems[i], "CMF_3");
            TRS.copy(CRASBASDAT.CMF_4, sizeof(CRASBASDAT.CMF_4), in_node->SItems[i], "CMF_4");
            TRS.copy(CRASBASDAT.CMF_5, sizeof(CRASBASDAT.CMF_5), in_node->SItems[i], "CMF_5");

            if (DB_error_code == DB_NOT_FOUND)
            {                
                DBU_insert_crasbasdat(&CRASBASDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CRASBASDAT Insert", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CRASBASDAT.FACTORY), CRASBASDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRASBASDAT.RES_ID), CRASBASDAT.RES_ID);

                    return MP_FALSE;
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                DBU_update_crasbasdat(1, &CRASBASDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    TRS.add_fieldmsg(out_node, "CRASBASDAT Update", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CRASBASDAT.FACTORY), CRASBASDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRASBASDAT.RES_ID), CRASBASDAT.RES_ID);

                    return MP_FALSE;
                }
            }
        }
    }
    //삭제
    else if (TRS.get_procstep(in_node) == '2')
    {
        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_crasbasdat(&CRASBASDAT);
            TRS.copy(CRASBASDAT.FACTORY, sizeof(CRASBASDAT.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CRASBASDAT.RES_ID, sizeof(CRASBASDAT.RES_ID), in_node->SItems[i], "RES_ID");
            DBU_delete_crasbasdat(1, &CRASBASDAT);

            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CRASBASDAT Delete", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CRASBASDAT.FACTORY), CRASBASDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CRASBASDAT.RES_ID), CRASBASDAT.RES_ID);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_RAS_Update_Resource_Efficiency_Info_Validation()
- Validation Check sub function of "CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_RAS_UPDATE_RESOURCE_EFFICIENCY_INFO_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        return MP_FALSE;
    }
   
    int i = 0;

    for (i = 0; i < in_node->SCount; i++)
    {
        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "RES_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "RES_ID", MP_NVST);

            return MP_FALSE;
        }
    }


    return MP_TRUE;
}
