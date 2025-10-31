/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_RAS_AddService.c
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
#include "CUS_RAS_services.h"


//Use static library
void CUS_RAS_add_service()
{   
    COM_add_service("CUS_RAS", "CUS_RAS_View_Resource_List", REPLY, CUS_RAS_View_Resource_List);
    COM_add_service("CUS_RAS", "CUS_RAS_Tool_Event", REPLY, CUS_RAS_Tool_Event);
    COM_add_service("CUS_RAS", "CUS_RAS_Update_Tool", REPLY, CUS_RAS_Update_Tool);
	COM_add_service("CUS_RAS", "CUS_RAS_Spare_Management", REPLY, CUS_RAS_Spare_Management);
    COM_add_service("CUS_RAS", "CUS_RAS_Resouce_Repairinfo_Registration", REPLY, CUS_RAS_Resouce_Repairinfo_Registration);
    COM_add_service("CUS_RAS", "CUS_RAS_Mold_Store_Registration", REPLY, CUS_RAS_Mold_Store_Registration);
    COM_add_service("CUS_RAS", "CUS_RAS_Scrap_Mold_Request", REPLY, CUS_RAS_Scrap_Mold_Request);
    COM_add_service("CUS_RAS", "CUS_RAS_Scrap_Mold_Confirm", REPLY, CUS_RAS_Scrap_Mold_Confirm);
    COM_add_service("CUS_RAS", "CUS_RAS_Mold_Tool_Event", REPLY, CUS_RAS_Mold_Tool_Event);
    COM_add_service("CUS_RAS", "CUS_RAS_Create_Scrap_Mold_Request", REPLY, CUS_RAS_Create_Scrap_Mold_Request);
    COM_add_service("CUS_RAS", "CUS_RAS_Tacktime_Registration", REPLY, CUS_RAS_Tacktime_Registration);
    COM_add_service("CUS_RAS", "CUS_RAS_Batch_Oee", REPLY, CUS_RAS_Batch_Oee);
    COM_add_service("CUS_RAS", "CUS_RAS_Update_Resource_Efficiency_Info", REPLY, CUS_RAS_Update_Resource_Efficiency_Info);
    COM_add_service("CUS_RAS", "CUS_RAS_Mold_Break_Registration", REPLY, CUS_RAS_Mold_Break_Registration);
    COM_add_service("CUS_RAS", "CUS_RAS_View_Cus_ras_asset_data", REPLY, CUS_RAS_View_Cus_ras_asset_data);
}
