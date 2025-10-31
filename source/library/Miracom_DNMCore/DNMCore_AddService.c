/*******************************************************************************

    System      : MESplus
    Module      : User Defined Shared Library
    File Name   : CUS_AddService.c
    Description : Common function of user defined shared library

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

#include <MESCore_service.h>
#include "DNMCore_services.h"

//Use static library
void DNMCore_add_service()
{
    COM_add_service("DNM", "DNM_Update_Direct_View", REPLY, DNM_Update_Direct_View);
	COM_add_service("DNM", "DNM_View_Direct_View", REPLY, DNM_View_Direct_View);
	COM_add_service("DNM", "DNM_View_Direct_View_List", REPLY, DNM_View_Direct_View_List);
    COM_add_service("DNM", "DNM_Update_Direct_View_Header", REPLY, DNM_Update_Direct_View_Header);
    COM_add_service("DNM", "DNM_Multi_Update_Direct_View_Header", REPLY, DNM_Multi_Update_Direct_View_Header);
	COM_add_service("DNM", "DNM_View_Direct_View_Header_List", REPLY, DNM_View_Direct_View_Header_List);
    COM_add_service("DNM", "DNM_Update_Header_User", REPLY, DNM_Update_Header_User);
    COM_add_service("DNM", "DNM_Multi_Update_Header_User", REPLY, DNM_Multi_Update_Header_User);
	COM_add_service("DNM", "DNM_View_Header_User_List", REPLY, DNM_View_Header_User_List);
    COM_add_service("DNM", "DNM_Update_Direct_View_Condition", REPLY, DNM_Update_Direct_View_Condition);
    COM_add_service("DNM", "DNM_Multi_Update_Direct_View_Condition", REPLY, DNM_Multi_Update_Direct_View_Condition);
	COM_add_service("DNM", "DNM_View_Direct_View_Condition", REPLY, DNM_View_Direct_View_Condition);
    COM_add_service("DNM", "DNM_View_Direct_View_Condition_List", REPLY, DNM_View_Direct_View_Condition_List);
} 



