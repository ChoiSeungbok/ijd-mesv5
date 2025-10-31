/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_BAT_AddService.c
    Description : Common function of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/09/21  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <MESCore_service.h>
#include "CUS_BAT_services.h"

//Use static library
void CUS_BAT_add_service()
{	
	COM_add_service("CUS_BAT", "CUS_BAT_Setup_Calendar_List", REPLY, CUS_BAT_Setup_Calendar_List);

	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Customer_Def", REPLY, CUS_BAT_Erp_Mes_Customer_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Mat_Def", REPLY, CUS_BAT_Erp_Mes_Mat_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_P_Wo_Info", REPLY, CUS_BAT_Erp_Mes_P_Wo_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Pack_Info", REPLY, CUS_BAT_Erp_Mes_Pack_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Po_Info", REPLY, CUS_BAT_Erp_Mes_Po_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Return_Order_Info", REPLY, CUS_BAT_Erp_Mes_Return_Order_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Ship_Order_Info", REPLY, CUS_BAT_Erp_Mes_Ship_Order_Info);

	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Std_Bom_Def", REPLY, CUS_BAT_Erp_Mes_Std_Bom_Def);

	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Sub_Area_Def", REPLY, CUS_BAT_Erp_Mes_Sub_Area_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Transaction_Type_Def", REPLY, CUS_BAT_Erp_Mes_Transaction_Type_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Uom_Conv_Def", REPLY, CUS_BAT_Erp_Mes_Uom_Conv_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Vendor_Def", REPLY, CUS_BAT_Erp_Mes_Vendor_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Wh_Def", REPLY, CUS_BAT_Erp_Mes_Wh_Def);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Wo_Bom_Info", REPLY, CUS_BAT_Erp_Mes_Wo_Bom_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Mes_Wo_Info", REPLY, CUS_BAT_Erp_Mes_Wo_Info);
	COM_add_service("CUS_BAT", "CUS_BAT_Erp_Alarm_Raise", REPLY, CUS_BAT_Erp_Alarm_Raise);
	COM_add_service("CUS_BAT", "CUS_BAT_alarm_raise_half_hour", REPLY, CUS_BAT_alarm_raise_half_hour);

}
