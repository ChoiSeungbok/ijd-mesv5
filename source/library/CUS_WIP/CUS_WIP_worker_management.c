/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_worker_management.c
Description : 작업자 관리

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/30  SR.SON        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_WORKER_MANAGEMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Worker_Management_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Worker_Management()
- 프로그램 테스트
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Worker_Management(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_WORKER_MANAGEMENT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Worker_Management", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

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
CUS_RAS_RESOUCE_REPAIRINFO_REGISTRATION()
- Main sub function of "CUS_WIP_Worker_Management" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_WORKER_MANAGEMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CWIPWRKDEF_TAG CWIPWRKDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_AREA;

    TRSNode     **worker_list;

    char c_flag = ' ';

    int worker_count = 0;

    LOG_head("CUS_WIP_Worker_Management");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Worker_Management_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    //작업자 목록 저장
    if (TRS.get_procstep(in_node) == '1')
    {
        worker_list = TRS.get_list(in_node, "WORKER_LIST");
        worker_count = TRS.get_item_count(in_node, "WORKER_LIST");

        for (int i = 0; i < worker_count; i++)
        {
            DBU_init_cwipwrkdef(&CWIPWRKDEF);
            TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID), worker_list[i], "WORKER_ID");
            
            DBU_select_cwipwrkdef(1, &CWIPWRKDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    c_flag = 'I';
                }
                else
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CWIPWRKDEF SELECTE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);

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

            TRS.copy(CWIPWRKDEF.WORKER_DESC, sizeof(CWIPWRKDEF.WORKER_DESC), worker_list[i], "WORKER_DESC");

			DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
			memcpy(MGCMTBLDAT_AREA.FACTORY, CWIPWRKDEF.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY));
			memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
			TRS.copy(MGCMTBLDAT_AREA.KEY_1, sizeof(MGCMTBLDAT_AREA.KEY_1), worker_list[i], "AREA_ID");
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
			if (DB_error_code != DB_SUCCESS)
			{
				//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
				strcpy(s_msg_code, "GCM-0008");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_AREA.TABLE_NAME), MGCMTBLDAT_AREA.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			memcpy(CWIPWRKDEF.AREA_ID, MGCMTBLDAT_AREA.KEY_1, sizeof(CWIPWRKDEF.AREA_ID));
            TRS.copy(CWIPWRKDEF.DEPT_CODE, sizeof(CWIPWRKDEF.DEPT_CODE), worker_list[i], "DEPT_CODE");

            if (c_flag == 'I')
            {
                TRS.copy(CWIPWRKDEF.CREATE_USER_ID, sizeof(CWIPWRKDEF.CREATE_USER_ID), in_node, IN_USERID);
                DB_get_systime(CWIPWRKDEF.CREATE_TIME);

                DBU_insert_cwipwrkdef(&CWIPWRKDEF);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CWIPWRKDEF INSERT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

            }
            else if (c_flag == 'U')
            {
                TRS.copy(CWIPWRKDEF.CREATE_USER_ID, sizeof(CWIPWRKDEF.UPDATE_USER_ID), in_node, IN_USERID);
                DB_get_systime(CWIPWRKDEF.UPDATE_TIME);

                DBU_update_cwipwrkdef(1, &CWIPWRKDEF);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "CMN-0004");
                    TRS.add_fieldmsg(out_node, "CWIPWRKDEF UPDATE", MP_NVST);
                    TRS.add_fieldmsg(out_node, "WORKER_ID", MP_STR, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_SETUP;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }
        }
    }
    //작업자 목록 삭제
    else if (TRS.get_procstep(in_node) == '2')
    {
        worker_list = TRS.get_list(in_node, "WORKER_LIST");
        worker_count = TRS.get_item_count(in_node, "WORKER_LIST");

        for (int i = 0; i < worker_count; i++)
        {
            DBU_init_cwipwrkdef(&CWIPWRKDEF);
            TRS.copy(CWIPWRKDEF.FACTORY, sizeof(CWIPWRKDEF.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPWRKDEF.WORKER_ID, sizeof(CWIPWRKDEF.WORKER_ID), worker_list[i], "WORKER_ID");

            DBU_delete_cwipwrkdef(1, &CWIPWRKDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "CMN-0004");
                TRS.add_fieldmsg(out_node, "CWIPWRKDEF DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "WORKER_ID", DT_STRING, sizeof(CWIPWRKDEF.WORKER_ID), CWIPWRKDEF.WORKER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
        }
    }
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Worker_Management_Validation()
- Validation Check sub function of "CUS_WIP_WORKER_MANAGEMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Worker_Management_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    return MP_TRUE;
}
