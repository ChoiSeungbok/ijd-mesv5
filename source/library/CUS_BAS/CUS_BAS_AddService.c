/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_BAS_AddService.c
    Description : Common function of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/06/22  Miracom        Create

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <MESCore_service.h>
#include "CUS_BAS_services.h"


//Use static library
void CUS_BAS_add_service()
{
    COM_add_service("CUS_BAS", "CUS_BAS_Update_Caption", REPLY, CUS_BAS_Update_Caption);
	COM_add_service("CUS_BAS", "CUS_BAS_Update_Caption_List", REPLY, CUS_BAS_Update_Caption_List);
    COM_add_service("CUS_BAS", "CUS_BAS_View_Caption", REPLY, CUS_BAS_View_Caption);
    COM_add_service("CUS_BAS", "CUS_BAS_View_Caption_List", REPLY, CUS_BAS_View_Caption_List);
	COM_add_service("CUS_BAS", "CUS_BAS_update_Attach", REPLY, CUS_BAS_update_Attach);
    COM_add_service("CUS_BAS", "CUS_BAS_Register_Checksheet", REPLY, CUS_BAS_Register_Checksheet);
    COM_add_service("CUS_BAS", "CUS_BAS_Update_Used_Data", REPLY, CUS_BAS_Update_Used_Data);
    COM_add_service("CUS_BAS", "CUS_BAS_Update_Reports_File", REPLY, CUS_BAS_Update_Reports_File);
    COM_add_service("CUS_BAS", "CUS_BAS_Print_Label_List", REPLY, CUS_BAS_Print_Label_List);
    COM_add_service("CUS_BAS", "CUS_BAS_View_Global_Area_List", REPLY, CUS_BAS_View_Global_Area_List);
    COM_add_service("CUS_BAS", "CUS_BAS_Update_Emi_User", REPLY, CUS_BAS_Update_Emi_User);
}
