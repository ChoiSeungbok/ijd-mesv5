/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_SHP_AddService.c
    Description : Common function of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <MESCore_service.h>
#include "CUS_SHP_services.h"


//Use static library
void CUS_SHP_add_service()
{
	COM_add_service("CUS_SHP", "CUS_SHP_Create_Pack_Lot", REPLY, CUS_SHP_Create_Pack_Lot);
	COM_add_service("CUS_SHP", "CUS_SHP_Delete_Pack_Lot", REPLY, CUS_SHP_Delete_Pack_Lot);
	COM_add_service("CUS_SHP", "CUS_SHP_Confirm_Pack_Order", REPLY, CUS_SHP_Confirm_Pack_Order);
	COM_add_service("CUS_SHP", "CUS_SHP_Create_Pack_Box", REPLY, CUS_SHP_Create_Pack_Box);
	COM_add_service("CUS_SHP", "CUS_SHP_Delete_Pack_Box", REPLY, CUS_SHP_Delete_Pack_Box);
	COM_add_service("CUS_SHP", "CUS_SHP_Create_Pack_Final_Box", REPLY, CUS_SHP_Create_Pack_Final_Box);
	COM_add_service("CUS_SHP", "CUS_SHP_Delete_Pack_Final_Box", REPLY, CUS_SHP_Delete_Pack_Final_Box);
	COM_add_service("CUS_SHP", "CUS_SHP_Ship_Lot", REPLY, CUS_SHP_Ship_Lot);
	COM_add_service("CUS_SHP", "CUS_SHP_Return_Lot", REPLY, CUS_SHP_Return_Lot);
    COM_add_service("CUS_SHP", "CUS_SHP_Update_Pack_Order", REPLY, CUS_SHP_Update_Pack_Order);

    //View Service
    COM_add_service("CUS_SHP", "CUS_SHP_View_Order_List", REPLY, CUS_SHP_View_Order_List);
    COM_add_service("CUS_SHP", "CUS_SHP_View_Ship_Lot_List", REPLY, CUS_SHP_View_Ship_Lot_List);
	COM_add_service("CUS_SHP", "CUS_SHP_View_Return_Lot_List", REPLY, CUS_SHP_View_Return_Lot_List);

	//PDA Service
	COM_add_service("CUS_SHP", "CUS_SHP_Validation_Ship_Lot", REPLY, CUS_SHP_Validation_Ship_Lot);
	COM_add_service("CUS_SHP", "CUS_SHP_Check_Ship_Lot", REPLY, CUS_SHP_Check_Ship_Lot);

	// ERP
	COM_add_service("CUS_SHP", "CUS_SHP_ERP_Ship_Lot", REPLY, CUS_SHP_ERP_Ship_Lot);
}
