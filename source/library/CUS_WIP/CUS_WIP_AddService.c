/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_WIP_AddService.c
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
#include "CUS_WIP_services.h"


//Use static library
void CUS_WIP_add_service()
{
    //core  process service
    COM_add_service("CUS_WIP", "CUS_WIP_Start_Lot", REPLY, CUS_WIP_Start_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_End_Lot", REPLY, CUS_WIP_End_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Adapt_Lot", REPLY, CUS_WIP_Adapt_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Create_Lot", REPLY, CUS_WIP_Create_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Split_Lot", REPLY, CUS_WIP_Split_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Loss_Lot", REPLY, CUS_WIP_Loss_Lot);    
    COM_add_service("CUS_WIP", "CUS_WIP_Skip_Lot", REPLY, CUS_WIP_Skip_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Move_Lot", REPLY, CUS_WIP_Move_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Terminate_Lot", REPLY, CUS_WIP_Terminate_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Cv_Lot", REPLY, CUS_WIP_Cv_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Bonus_Lot", REPLY, CUS_WIP_Bonus_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Hold_Lot", REPLY, CUS_WIP_Hold_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Release_Lot", REPLY, CUS_WIP_Release_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Generate_Id", REPLY, CUS_WIP_Generate_Id);
    COM_add_service("CUS_WIP", "CUS_WIP_Store_Lot", REPLY, CUS_WIP_Store_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Unstore_Lot", REPLY, CUS_WIP_Unstore_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Merge_Lot", REPLY, CUS_WIP_Merge_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Regenerate_Lot", REPLY, CUS_WIP_Regenerate_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_Ship_Lot", REPLY, CUS_WIP_Ship_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_Move_Lot_Force", REPLY, CUS_WIP_Move_Lot_Force);
	COM_add_service("CUS_WIP", "CUS_WIP_Etc_In_Lot", REPLY, CUS_WIP_Etc_In_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_Regenerate_P_Lot", REPLY, CUS_WIP_Regenerate_P_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_Validation_Etc_Out_Lot", REPLY, CUS_WIP_Validation_Etc_Out_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Delete_History", REPLY, CUS_WIP_Delete_History);

    //test service
    COM_add_service("CUS_WIP", "CUS_WIP_Test_Process", REPLY, CUS_WIP_Test_Process);

    //cus process service
    COM_add_service("CUS_WIP", "CUS_WIP_View_Oper_List", REPLY, CUS_WIP_View_Oper_List);
    COM_add_service("CUS_WIP", "CUS_WIP_View_Lot_Info", REPLY, CUS_WIP_View_Lot_Info);   
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Lot_Loss", REPLY, CUS_WIP_Update_Lot_Loss);
    COM_add_service("CUS_WIP", "CUS_WIP_Input_Material_Lot", REPLY, CUS_WIP_Input_Material_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Worker_Management", REPLY, CUS_WIP_Worker_Management);
    COM_add_service("CUS_WIP", "CUS_WIP_Process_Lot", REPLY, CUS_WIP_Process_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Multi_Process_Lot", REPLY, CUS_WIP_Multi_Process_Lot);    
    COM_add_service("CUS_WIP", "CUS_WIP_Worker_Registration", REPLY, CUS_WIP_Worker_Registration);
    COM_add_service("CUS_WIP", "CUS_WIP_Move_Lot_Order", REPLY, CUS_WIP_Move_Lot_Order);
    COM_add_service("CUS_WIP", "CUS_WIP_Cup_Cell_Process_Lot", REPLY, CUS_WIP_Cup_Cell_Process_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_non_operation", REPLY, CUS_WIP_non_operation);
    COM_add_service("CUS_WIP", "CUS_WIP_Input_Lot_Data", REPLY, CUS_WIP_Input_Lot_Data);    
    COM_add_service("CUS_WIP", "CUS_WIP_Outsourcing_Process", REPLY, CUS_WIP_Outsourcing_Process);    
    COM_add_service("CUS_WIP", "CUS_WIP_Blending_Order", REPLY, CUS_WIP_Blending_Order);
	COM_add_service("CUS_WIP", "CUS_WIP_View_Material_List", REPLY, CUS_WIP_View_Material_List);    
    COM_add_service("CUS_WIP", "CUS_WIP_View_Oper_Loss", REPLY, CUS_WIP_View_Oper_Loss);    
	COM_add_service("CUS_WIP", "CUS_WIP_View_Label_List", REPLY, CUS_WIP_View_Label_List);
	COM_add_service("CUS_WIP", "CUS_WIP_View_Worker_List", REPLY, CUS_WIP_View_Worker_List);
    COM_add_service("CUS_WIP", "CUS_WIP_Grit_Class_Process", REPLY, CUS_WIP_Grit_Class_Process);
    COM_add_service("CUS_WIP", "CUS_WIP_Inventory_Survey", REPLY, CUS_WIP_Inventory_Survey);
	COM_add_service("CUS_WIP", "CUS_WIP_Lot_Press_Data", REPLY, CUS_WIP_Lot_Press_Data);
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Loss_By_Oper", REPLY, CUS_WIP_Update_Loss_By_Oper);
	COM_add_service("CUS_WIP", "CUS_WIP_Etc_Out_Lot", REPLY, CUS_WIP_Etc_Out_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Send_Resource_Info", REPLY, CUS_WIP_Send_Resource_Info);
	COM_add_service("CUS_WIP", "CUS_WIP_Change_Item", REPLY, CUS_WIP_Change_Item);
    COM_add_service("CUS_WIP", "CUS_WIP_Create_Stock_In_Oper", REPLY, CUS_WIP_Create_Stock_In_Oper);
    COM_add_service("CUS_WIP", "CUS_WIP_Delete_Lot_History", REPLY, CUS_WIP_Delete_Lot_History);
    COM_add_service("CUS_WIP", "CUS_WIP_View_Lot_History", REPLY, CUS_WIP_View_Lot_History);
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Productivity_Goal", REPLY, CUS_WIP_Update_Productivity_Goal);
    COM_add_service("CUS_WIP", "CUS_WIP_Split_Wip_Lot", REPLY, CUS_WIP_Split_Wip_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Merge_Wip_Lot", REPLY, CUS_WIP_Merge_Wip_Lot);
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Working_Time", REPLY, CUS_WIP_Update_Working_Time);
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Lot_Comment", REPLY, CUS_WIP_Update_Lot_Comment);
    COM_add_service("CUS_WIP", "CUS_WIP_Delete_P_Lot", REPLY, CUS_WIP_Delete_P_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_Create_Erp_If_Data", REPLY, CUS_WIP_Create_Erp_If_Data);
	COM_add_service("CUS_WIP", "CUS_WIP_Update_Classify_Master_Data_List", REPLY, CUS_WIP_Update_Classify_Master_Data_List);
    COM_add_service("CUS_WIP", "CUS_WIP_Change_Test_Prod_Lot", REPLY, CUS_WIP_Change_Test_Prod_Lot);
	COM_add_service("CUS_WIP", "CUS_WIP_ras_yield_st", REPLY, CUS_WIP_ras_yield_st);
    COM_add_service("CUS_WIP", "CUS_WIP_Update_Lot_Res_Worktime", REPLY, CUS_WIP_Update_Lot_Res_Worktime);
}
