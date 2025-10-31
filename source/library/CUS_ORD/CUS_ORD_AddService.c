/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_ORD_AddService.c
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
#include "CUS_ORD_services.h"


//Use static library
void CUS_ORD_add_service()
{
    COM_add_service("CUS_ORD", "CUS_ORD_Update_Order_Bom", REPLY, CUS_ORD_Update_Order_Bom);
    COM_add_service("CUS_ORD", "CUS_ORD_View_Order_List", REPLY, CUS_ORD_View_Order_List);
	COM_add_service("CUS_ORD", "CUS_ORD_Prod_Plan_Registration", REPLY, CUS_ORD_Prod_Plan_Registration);
    COM_add_service("CUS_ORD", "CUS_ORD_Create_Test_Order", REPLY, CUS_ORD_Create_Test_Order);    
}
