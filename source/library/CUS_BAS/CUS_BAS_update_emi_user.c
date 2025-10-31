/*******************************************************************************

System      : CUS_BAS_update_emi_user
Module      : CUS_BAS
File Name   : CUS_BAS_update_emi_user.c
Description : EMI 사용자 등록

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/26  Miracom        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"

extern int CUS_BAS_UPDATE_EMI_USER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_UPDATE_EMI_FAC_USER(char *s_msg_code, struct ESECUSRDEF_TAG *ESECUSRDEF, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_DELETE_EMI_FAC_USER(char *s_msg_code, struct ESECUSRDEF_TAG *ESECUSRDEF, TRSNode *in_node, TRSNode *out_node);
/*******************************************************************************
CUS_BAS_Update_Emi_User()
- EMI 사용자 등록
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Emi_User(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_UPDATE_EMI_USER(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_Update_Emi_User", out_node);
    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

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
CUS_BAS_UPDATE_EMI_USER()
- Main sub function of "CUS_BAS_Update_Emi_User" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_EMI_USER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MSECUSRDEF_TAG MSECUSRDEF;
    struct ESECUSRDEF_TAG ESECUSRDEF;
    char sSysDate[14];

    LOG_head("CUS_BAS_UPDATE_EMI_USER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    memset(sSysDate, ' ', sizeof(sSysDate));
    DB_get_systime(sSysDate);

    DBC_init_msecusrdef(&MSECUSRDEF);
    TRS.copy(MSECUSRDEF.FACTORY, sizeof(MSECUSRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MSECUSRDEF.USER_ID, sizeof(MSECUSRDEF.USER_ID), in_node, "USER_ID");
    DBC_select_msecusrdef(1, &MSECUSRDEF);
    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "MSECUSRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MSECUSRDEF.FACTORY), MSECUSRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(MSECUSRDEF.USER_ID), MSECUSRDEF.USER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }
    
    //삭제됐을 경우
    if (DB_error_code == DB_NOT_FOUND)
    {
        //EMI 사용자가 있으면 삭제
        DBU_init_esecusrdef(&ESECUSRDEF);      
        TRS.copy(ESECUSRDEF.FACTORY, sizeof(ESECUSRDEF.FACTORY), in_node, IN_FACTORY);
        TRS.copy(ESECUSRDEF.USER_ID, sizeof(ESECUSRDEF.USER_ID), in_node, "USER_ID");
        DBU_select_esecusrdef(1, &ESECUSRDEF);
        if (DB_error_code == DB_SUCCESS)
        {
            DBU_delete_esecusrdef(1, &ESECUSRDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "SEC-0004");
                TRS.add_fieldmsg(out_node, "EMI ESECUSRDEF DELETE", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECUSRDEF.FACTORY), ESECUSRDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECUSRDEF.USER_ID), ESECUSRDEF.USER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
            //factory별  user 삭제
            if (CUS_BAS_DELETE_EMI_FAC_USER(s_msg_code, &ESECUSRDEF, in_node, out_node) == MP_FALSE)
            {
                return MP_FALSE;
            }

        }

        return MP_TRUE;
    }
    

    //EMI 사용자 등록/수정
    DBU_init_esecusrdef(&ESECUSRDEF);
    TRS.copy(ESECUSRDEF.FACTORY, sizeof(ESECUSRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(ESECUSRDEF.USER_ID, sizeof(ESECUSRDEF.USER_ID), in_node, "USER_ID");
    DBU_select_esecusrdef(1, &ESECUSRDEF);

    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "EMI MSECUSRDEF SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECUSRDEF.FACTORY), ESECUSRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECUSRDEF.USER_ID), ESECUSRDEF.USER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    memcpy(ESECUSRDEF.USER_DESC, MSECUSRDEF.USER_DESC, sizeof(ESECUSRDEF.USER_DESC));
    memcpy(ESECUSRDEF.SEC_GRP_ID, MSECUSRDEF.SEC_GRP_ID, sizeof(ESECUSRDEF.SEC_GRP_ID));            //보안 그룹
    memcpy(ESECUSRDEF.PHONE_OFFICE, MSECUSRDEF.PHONE_OFFICE, sizeof(ESECUSRDEF.PHONE_OFFICE));
    memcpy(ESECUSRDEF.PHONE_MOBILE, MSECUSRDEF.PHONE_MOBILE, sizeof(ESECUSRDEF.PHONE_MOBILE));
    memcpy(ESECUSRDEF.PHONE_HOME, MSECUSRDEF.PHONE_HOME, sizeof(ESECUSRDEF.PHONE_HOME));
    memcpy(ESECUSRDEF.PHONE_OTHER, MSECUSRDEF.PHONE_OTHER, sizeof(ESECUSRDEF.PHONE_OTHER));
    memcpy(ESECUSRDEF.EXPIRE_DATE, MSECUSRDEF.EXPIRE_DATE, sizeof(ESECUSRDEF.EXPIRE_DATE));
    memcpy(ESECUSRDEF.PASS_EXPIRE_DATE, MSECUSRDEF.PASS_EXPIRE_DATE, sizeof(ESECUSRDEF.PASS_EXPIRE_DATE));
    memcpy(ESECUSRDEF.ENTER_DATE, MSECUSRDEF.ENTER_DATE, sizeof(ESECUSRDEF.ENTER_DATE));
    memcpy(ESECUSRDEF.EMAIL_ID, MSECUSRDEF.EMAIL_ID, sizeof(ESECUSRDEF.EMAIL_ID));
    memcpy(ESECUSRDEF.BIRTHDAY, MSECUSRDEF.BIRTHDAY, sizeof(ESECUSRDEF.BIRTHDAY));
    ESECUSRDEF.SEX_FLAG = MSECUSRDEF.SEX_FLAG;

    //등록
    if (DB_error_code == DB_NOT_FOUND)
    {        
        memcpy(ESECUSRDEF.PASSWORD, "1                   ", sizeof(ESECUSRDEF.PASSWORD));// 기본값
        ESECUSRDEF.CHG_PASS_FLAG = 'Y';                  
        TRS.copy(ESECUSRDEF.CREATE_USER_ID, sizeof(ESECUSRDEF.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(ESECUSRDEF.CREATE_TIME, sSysDate, sizeof(sSysDate));    
        DBU_insert_esecusrdef(1, &ESECUSRDEF);       
    }
    else
    {
         TRS.copy(ESECUSRDEF.UPDATE_USER_ID, sizeof(ESECUSRDEF.CREATE_USER_ID), in_node, IN_USERID);
         memcpy(ESECUSRDEF.UPDATE_TIME, sSysDate, sizeof(sSysDate));
         DBU_update_esecusrdef(1, &ESECUSRDEF);
    }   

    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "EMI MSECUSRDEF INSERT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECUSRDEF.FACTORY), ESECUSRDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECUSRDEF.USER_ID), ESECUSRDEF.USER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    //factory별  user 등록
    if (CUS_BAS_UPDATE_EMI_FAC_USER(s_msg_code, &ESECUSRDEF, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }
    
    return MP_TRUE;
}
/*******************************************************************************
CUS_BAS_UPDATE_EMI_FAC_USER()
- Main sub function of "CUS_BAS_UPDATE_EMI_FAC_USER" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_EMI_FAC_USER(char *s_msg_code, struct ESECUSRDEF_TAG *ESECUSRDEF, TRSNode *in_node, TRSNode *out_node)
{
    
    struct ESECUSRDEF_TAG ESECFACUSR;

    char sSysDate[14];

    LOG_head("CUS_BAS_UPDATE_EMI_FAC_USER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    memset(sSysDate, ' ', sizeof(sSysDate));
    DB_get_systime(sSysDate);

    DBU_init_esecusrdef(&ESECFACUSR);
    memcpy(ESECFACUSR.FACTORY, ESECUSRDEF->FACTORY, sizeof(ESECFACUSR.FACTORY));
    memcpy(ESECFACUSR.USER_ID, ESECUSRDEF->USER_ID, sizeof(ESECFACUSR.USER_ID));
    DBU_select_esecusrdef(2, &ESECFACUSR);
    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "EMI ESECFACUSR SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECFACUSR.FACTORY), ESECFACUSR.FACTORY);
        TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECFACUSR.USER_ID), ESECFACUSR.USER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);
        return MP_FALSE;
    }

    memcpy(ESECFACUSR.SEC_GRP_ID, ESECUSRDEF->SEC_GRP_ID, sizeof(ESECFACUSR.SEC_GRP_ID));

    if (DB_error_code == DB_NOT_FOUND)
    {
        TRS.copy(ESECFACUSR.CREATE_USER_ID, sizeof(ESECFACUSR.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(ESECFACUSR.CREATE_TIME, sSysDate, sizeof(sSysDate));
        DBU_insert_esecusrdef(2,&ESECFACUSR);
    }
    else
    {
        TRS.copy(ESECFACUSR.UPDATE_USER_ID, sizeof(ESECFACUSR.CREATE_USER_ID), in_node, IN_USERID);
        memcpy(ESECFACUSR.UPDATE_TIME, sSysDate, sizeof(sSysDate));
        DBU_update_esecusrdef(2, &ESECFACUSR);
    }

    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "SEC-0004");
        TRS.add_fieldmsg(out_node, "EMI ESECFACUSR INSERT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECFACUSR.FACTORY), ESECFACUSR.FACTORY);
        TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECFACUSR.USER_ID), ESECFACUSR.USER_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }
    
    return MP_TRUE;

}

/*******************************************************************************
CUS_BAS_DELETE_EMI_FAC_USER()
- Main sub function of "CUS_BAS_DELETE_EMI_FAC_USER" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_DELETE_EMI_FAC_USER(char *s_msg_code, struct ESECUSRDEF_TAG *ESECUSRDEF, TRSNode *in_node, TRSNode *out_node)
{
    
    struct ESECUSRDEF_TAG ESECFACUSR;
    
    LOG_head("CUS_BAS_DELETE_EMI_FAC_USER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    DBU_init_esecusrdef(&ESECFACUSR);
    memcpy(ESECFACUSR.FACTORY, ESECUSRDEF->FACTORY, sizeof(ESECFACUSR.FACTORY));
    memcpy(ESECFACUSR.USER_ID, ESECUSRDEF->USER_ID, sizeof(ESECFACUSR.USER_ID));
    DBU_select_esecusrdef(2, &ESECFACUSR);
    if (DB_error_code == DB_SUCCESS)
    {
        DBU_delete_esecusrdef(2, &ESECFACUSR);
        if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "SEC-0004");
            TRS.add_fieldmsg(out_node, "EMI MSECFACUSR DELETE", MP_NVST);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(ESECFACUSR.FACTORY), ESECFACUSR.FACTORY);
            TRS.add_fieldmsg(out_node, "USER_ID", MP_STR, sizeof(ESECFACUSR.USER_ID), ESECFACUSR.USER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);
            return MP_FALSE;
        }
    }  
   
    return MP_TRUE;
}