/*******************************************************************************

    System      : MESplus
    Module      : User Routine for SEC
    File Name   : USEC_Update_User_Ext.c
    Description : User Routine for SEC_Update_User_Ext

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/10  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "USEC_common.h"
#include "DBU_common.h"

extern int CUS_BAS_Update_Emi_User(TRSNode *in_node, TRSNode *out_node);

int SEC_Update_User_Ext_Before_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */







    return MP_TRUE;
}

int SEC_Update_User_Ext_After_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */


    struct CSECUSRDEF_TAG CSECUSRDEF;               
    struct MSECUSRDEF_TAG MSECUSRDEF;

    char sSysDate[14];

    memset(sSysDate, ' ', sizeof(sSysDate));
    DB_get_systime(sSysDate);

    //20240924 ITGC 감사 부서변경에 대한 히스토리 가지고있어야 된다고 해서. 유저정보 바뀌는 히스토리 전부 저장.

    DBC_init_msecusrdef(&MSECUSRDEF);
    TRS.copy(MSECUSRDEF.FACTORY, sizeof(MSECUSRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MSECUSRDEF.USER_ID, sizeof(MSECUSRDEF.USER_ID), in_node, "USER_ID");
    DBC_select_msecusrdef(1, &MSECUSRDEF);
    if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
    {
        return MP_FALSE;
    }

    DBU_init_csecusrdef(&CSECUSRDEF);
    TRS.copy(CSECUSRDEF.FACTORY, sizeof(CSECUSRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CSECUSRDEF.USER_ID, sizeof(CSECUSRDEF.USER_ID), in_node, "USER_ID");
    DBU_select_csecusrdef(1, &CSECUSRDEF);


    TRS.copy(CSECUSRDEF.FACTORY, sizeof(CSECUSRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CSECUSRDEF.USER_ID, sizeof(CSECUSRDEF.USER_ID), in_node, "USER_ID");
    memcpy(CSECUSRDEF.EOH_TIME, sSysDate, sizeof(sSysDate));
    memcpy(CSECUSRDEF.USER_DESC, MSECUSRDEF.USER_DESC, sizeof(CSECUSRDEF.USER_DESC));
    memcpy(CSECUSRDEF.SEC_GRP_ID, MSECUSRDEF.SEC_GRP_ID, sizeof(CSECUSRDEF.SEC_GRP_ID));            //보안 그룹
    memcpy(CSECUSRDEF.PHONE_OFFICE, MSECUSRDEF.PHONE_OFFICE, sizeof(CSECUSRDEF.PHONE_OFFICE));
    memcpy(CSECUSRDEF.PHONE_MOBILE, MSECUSRDEF.PHONE_MOBILE, sizeof(CSECUSRDEF.PHONE_MOBILE));
    memcpy(CSECUSRDEF.PHONE_HOME, MSECUSRDEF.PHONE_HOME, sizeof(CSECUSRDEF.PHONE_HOME));
    memcpy(CSECUSRDEF.PHONE_OTHER, MSECUSRDEF.PHONE_OTHER, sizeof(CSECUSRDEF.PHONE_OTHER));
    memcpy(CSECUSRDEF.EXPIRE_DATE, MSECUSRDEF.EXPIRE_DATE, sizeof(CSECUSRDEF.EXPIRE_DATE));
    memcpy(CSECUSRDEF.PASS_EXPIRE_DATE, MSECUSRDEF.PASS_EXPIRE_DATE, sizeof(CSECUSRDEF.PASS_EXPIRE_DATE));
    memcpy(CSECUSRDEF.ENTER_DATE, MSECUSRDEF.ENTER_DATE, sizeof(CSECUSRDEF.ENTER_DATE));
    memcpy(CSECUSRDEF.EMAIL_ID, MSECUSRDEF.EMAIL_ID, sizeof(CSECUSRDEF.EMAIL_ID));
    memcpy(CSECUSRDEF.BIRTHDAY, MSECUSRDEF.BIRTHDAY, sizeof(CSECUSRDEF.BIRTHDAY));
    CSECUSRDEF.SEX_FLAG = MSECUSRDEF.SEX_FLAG;
    memcpy(CSECUSRDEF.PASSWORD, MSECUSRDEF.PASSWORD, sizeof(CSECUSRDEF.PASSWORD));
    CSECUSRDEF.CHG_PASS_FLAG = MSECUSRDEF.CHG_PASS_FLAG;
    TRS.copy(CSECUSRDEF.CREATE_USER_ID, sizeof(CSECUSRDEF.CREATE_USER_ID), in_node, IN_USERID);
    memcpy(CSECUSRDEF.CREATE_TIME, MSECUSRDEF.CREATE_TIME, sizeof(CSECUSRDEF.CREATE_TIME));
    DBU_insert_csecusrdef(&CSECUSRDEF);
  



    
    //  if (DB_error_code != DB_SUCCESS)
  //  {

  //      return MP_FALSE;
  //  }






    if (CUS_BAS_Update_Emi_User(in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }







    return MP_TRUE;
}

