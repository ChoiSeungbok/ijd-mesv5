/******************************************************************************'

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_update_classify_master_data_list.c
Description : classify_master_data Setup function module

MES Version : 5.3.4 ~

Function List
- CUS_WIP_Update_classify_master_data_list()
+ Create/Update/Delete classify_master_data_list definition
- CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST()
+ Main sub function of CUS_WIP_Update_classify_master_data_list function
+ Create/Update/Delete classify_master_data_list definition
- CUS_WIP_Update_classify_master_data_list_Validation()
+ Main sub function of CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST function
+ Check the condition for create/update/delete classify_master_data_list
Detail Description
- CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST()
+ h_proc_step
+ MP_STEP_CREATE : Create classify_master_data_list definition
+ MP_STEP_UPDATE : Update classify_master_data_list definition
+ MP_STEP_DELETE : Delete classify_master_data_list definition

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020-12-29  minjae.go    Create by Generator

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

******************************************************************************/

#include "CUS_WIP_common.h"

int CUS_WIP_Update_classify_master_data_list_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Update_Classify_Master_Data_list()
- Create/Update/Delete classify_master_data_list definition
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_Classify_Master_Data_List(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST", out_node);

	if (i_ret == MP_TRUE)
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
CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST()
- Main sub function of "CUS_WIP_Update_classify_master_data_list" function
- Create/Update/Delete classify_master_data_list definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CWIPGRTCLS_TAG CWIPGRTCLS;
    struct MWIPMATDEF_TAG MWIPMATDEF;

	TRSNode **class_tbl;	
    int i = 0;
    int i_class_count = 0;

	LOG_head("CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA_LIST");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	if (CUS_WIP_Update_classify_master_data_list_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

    class_tbl = TRS.get_list(in_node, "CLASS_LIST");
    i_class_count = TRS.get_item_count(in_node, "CLASS_LIST");

	for (i = 0; i < i_class_count; i++)
	{
        /* MAT_GROUP Validation */
        if (COM_isnullspace(TRS.get_string(class_tbl[i], "MAT_GROUP")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "MAT_GROUP", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }
        /* INPUT_MAT_ID Validation */
        if (COM_isnullspace(TRS.get_string(class_tbl[i], "INPUT_MAT_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "INPUT_MAT_ID", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }

        DBU_init_mwipmatdef(&MWIPMATDEF);
        TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), class_tbl[i], "INPUT_MAT_ID");
        MWIPMATDEF.MAT_VER = 1;
        DBU_select_mwipmatdef(1, &MWIPMATDEF);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0006 : 이 제품은 존재 하지 않습니다.
            strcpy(s_msg_code, "WIP-0006");
            TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        /* CLASS_TYPE Validation */
        if (COM_isnullspace(TRS.get_string(class_tbl[i], "CLASS_TYPE")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }
        /* CLASS_VALUE Validation */
        if (COM_isnullspace(TRS.get_string(class_tbl[i], "CLASS_VALUE")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_NVST);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_VALIDATION;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            return MP_FALSE;
        }

        if (COM_isnullspace(TRS.get_string(class_tbl[i], "OUT_MAT_ID")) != MP_TRUE)
        {
            DBU_init_mwipmatdef(&MWIPMATDEF);
            TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), class_tbl[i], "OUT_MAT_ID");
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }

        if (TRS.get_procstep(in_node) == MP_STEP_DELETE)
        {
            DBU_init_cwipgrtcls(&CWIPGRTCLS);
            TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPGRTCLS.MAT_GROUP, sizeof(CWIPGRTCLS.MAT_GROUP), class_tbl[i], "MAT_GROUP");
            TRS.copy(CWIPGRTCLS.INPUT_MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID), class_tbl[i], "INPUT_MAT_ID");
            TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), class_tbl[i], "CLASS_TYPE");
            TRS.copy(CWIPGRTCLS.CLASS_VALUE, sizeof(CWIPGRTCLS.CLASS_VALUE), class_tbl[i], "CLASS_VALUE");
            DBU_select_cwipgrtcls(1, &CWIPGRTCLS);            
            if (DB_error_code == DB_SUCCESS)
            {
                DBU_delete_cwipgrtcls(1, &CWIPGRTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPGRTCLS SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTCLS.FACTORY), CWIPGRTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "MAT_GROUP", MP_STR, sizeof(CWIPGRTCLS.MAT_GROUP), CWIPGRTCLS.MAT_GROUP);
                    TRS.add_fieldmsg(out_node, "INPUT_MAT_ID", MP_STR, sizeof(CWIPGRTCLS.INPUT_MAT_ID), CWIPGRTCLS.INPUT_MAT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPGRTCLS.CLASS_TYPE), CWIPGRTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPGRTCLS.CLASS_VALUE), CWIPGRTCLS.CLASS_VALUE);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }
        else if (TRS.get_procstep(in_node) == MP_STEP_UPDATE)
        {
            DBU_init_cwipgrtcls(&CWIPGRTCLS);
            TRS.copy(CWIPGRTCLS.FACTORY, sizeof(CWIPGRTCLS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPGRTCLS.MAT_GROUP, sizeof(CWIPGRTCLS.MAT_GROUP), class_tbl[i], "MAT_GROUP");
            TRS.copy(CWIPGRTCLS.INPUT_MAT_ID, sizeof(CWIPGRTCLS.INPUT_MAT_ID), class_tbl[i], "INPUT_MAT_ID");
            TRS.copy(CWIPGRTCLS.CLASS_TYPE, sizeof(CWIPGRTCLS.CLASS_TYPE), class_tbl[i], "CLASS_TYPE");
            TRS.copy(CWIPGRTCLS.CLASS_VALUE, sizeof(CWIPGRTCLS.CLASS_VALUE), class_tbl[i], "CLASS_VALUE");
            DBU_select_cwipgrtcls(1, &CWIPGRTCLS);

            TRS.copy(CWIPGRTCLS.OUT_MAT_ID, sizeof(CWIPGRTCLS.OUT_MAT_ID), class_tbl[i], "OUTPUT_MAT_ID");
            TRS.copy(CWIPGRTCLS.CMF_1, sizeof(CWIPGRTCLS.CMF_1), class_tbl[i], "CMF_1");
            TRS.copy(CWIPGRTCLS.CMF_2, sizeof(CWIPGRTCLS.CMF_2), class_tbl[i], "CMF_2");
            TRS.copy(CWIPGRTCLS.CMF_3, sizeof(CWIPGRTCLS.CMF_3), class_tbl[i], "CMF_3");
            TRS.copy(CWIPGRTCLS.CMF_4, sizeof(CWIPGRTCLS.CMF_4), class_tbl[i], "CMF_4");
            TRS.copy(CWIPGRTCLS.CMF_5, sizeof(CWIPGRTCLS.CMF_5), class_tbl[i], "CMF_5");
            TRS.copy(CWIPGRTCLS.CMF_6, sizeof(CWIPGRTCLS.CMF_6), class_tbl[i], "CMF_6");
            TRS.copy(CWIPGRTCLS.CMF_7, sizeof(CWIPGRTCLS.CMF_7), class_tbl[i], "CMF_7");
            TRS.copy(CWIPGRTCLS.CMF_8, sizeof(CWIPGRTCLS.CMF_8), class_tbl[i], "CMF_8");
            TRS.copy(CWIPGRTCLS.CMF_9, sizeof(CWIPGRTCLS.CMF_9), class_tbl[i], "CMF_9");
            TRS.copy(CWIPGRTCLS.CMF_10, sizeof(CWIPGRTCLS.CMF_10), class_tbl[i], "CMF_10");

            if (DB_error_code == DB_SUCCESS)
            {
                TRS.copy(CWIPGRTCLS.UPDATE_USER_ID, sizeof(CWIPGRTCLS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRTCLS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRTCLS.UPDATE_TIME));
                
                DBU_update_cwipgrtcls(1, &CWIPGRTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPGRTCLS UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTCLS.FACTORY), CWIPGRTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "MAT_GROUP", MP_STR, sizeof(CWIPGRTCLS.MAT_GROUP), CWIPGRTCLS.MAT_GROUP);
                    TRS.add_fieldmsg(out_node, "INPUT_MAT_ID", MP_STR, sizeof(CWIPGRTCLS.INPUT_MAT_ID), CWIPGRTCLS.INPUT_MAT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPGRTCLS.CLASS_TYPE), CWIPGRTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPGRTCLS.CLASS_VALUE), CWIPGRTCLS.CLASS_VALUE);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            else if (DB_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CWIPGRTCLS.CREATE_USER_ID, sizeof(CWIPGRTCLS.CREATE_USER_ID),in_node, IN_USERID);
                memcpy(CWIPGRTCLS.CREATE_TIME, gs_sys_time, sizeof(CWIPGRTCLS.CREATE_TIME));
                TRS.copy(CWIPGRTCLS.UPDATE_USER_ID, sizeof(CWIPGRTCLS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPGRTCLS.UPDATE_TIME, gs_sys_time, sizeof(CWIPGRTCLS.UPDATE_TIME));

                DBU_insert_cwipgrtcls(&CWIPGRTCLS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPGRTCLS INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTCLS.FACTORY), CWIPGRTCLS.FACTORY);
                    TRS.add_fieldmsg(out_node, "MAT_GROUP", MP_STR, sizeof(CWIPGRTCLS.MAT_GROUP), CWIPGRTCLS.MAT_GROUP);
                    TRS.add_fieldmsg(out_node, "INPUT_MAT_ID", MP_STR, sizeof(CWIPGRTCLS.INPUT_MAT_ID), CWIPGRTCLS.INPUT_MAT_ID);
                    TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPGRTCLS.CLASS_TYPE), CWIPGRTCLS.CLASS_TYPE);
                    TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPGRTCLS.CLASS_VALUE), CWIPGRTCLS.CLASS_VALUE);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
            else
            {
                strcpy(s_msg_code, "CUS_WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
                gs_log_type.e_type = MP_LOG_E_SYSTEM;

                TRS.add_fieldmsg(out_node, "CWIPGRTCLS SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTCLS.FACTORY), CWIPGRTCLS.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_GROUP", MP_STR, sizeof(CWIPGRTCLS.MAT_GROUP), CWIPGRTCLS.MAT_GROUP);
                TRS.add_fieldmsg(out_node, "INPUT_MAT_ID", MP_STR, sizeof(CWIPGRTCLS.INPUT_MAT_ID), CWIPGRTCLS.INPUT_MAT_ID);
                TRS.add_fieldmsg(out_node, "CLASS_TYPE", MP_STR, sizeof(CWIPGRTCLS.CLASS_TYPE), CWIPGRTCLS.CLASS_TYPE);
                TRS.add_fieldmsg(out_node, "CLASS_VALUE", MP_STR, sizeof(CWIPGRTCLS.CLASS_VALUE), CWIPGRTCLS.CLASS_VALUE);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.category = MP_LOG_CATE_SETUP;
                return MP_FALSE;
            }
        }
	}
	
	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Update_classify_master_data_list_Validation()
- Main sub function of "CUS_WIP_UPDATE_CLASSIFY_MASTER_DATA" function
- Check the condition for create/update/delete classify_master_data
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Update_classify_master_data_list_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"UD") == MP_FALSE)
	{
		return MP_FALSE;
	}

    // FACTORY VALIDATION
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
