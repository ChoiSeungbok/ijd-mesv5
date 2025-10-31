/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_INV_AddService.c
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
#include "CUS_INV_services.h"


//Use static library
void CUS_INV_add_service()
{
	//Transaction Service
	COM_add_service("CUS_INV", "CUS_INV_Create_Lot", REPLY, CUS_INV_Create_Lot);
	COM_add_service("CUS_INV", "CUS_INV_CV_Lot", REPLY, CUS_INV_CV_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Hold_Lot", REPLY, CUS_INV_Hold_Lot);
	COM_add_service("CUS_INV", "CUS_INV_In_Lot", REPLY, CUS_INV_In_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Issue_Lot", REPLY, CUS_INV_Issue_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Load_Lot", REPLY, CUS_INV_Load_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Merge_Lot", REPLY, CUS_INV_Merge_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Move_Lot", REPLY, CUS_INV_Move_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Release_Lot", REPLY, CUS_INV_Release_Lot);
	COM_add_service("CUS_INV", "CUS_INV_RetOut_Lot", REPLY, CUS_INV_RetOut_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Split_Lot", REPLY, CUS_INV_Split_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Tempin_Lot", REPLY, CUS_INV_Tempin_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Terminate_Lot", REPLY, CUS_INV_Terminate_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Unload_Lot", REPLY, CUS_INV_Unload_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Create_Dlv_Lot", REPLY, CUS_INV_Create_Dlv_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", REPLY, CUS_INV_Confirm_Dlv_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Delete_Dlv_Lot", REPLY, CUS_INV_Delete_Dlv_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Create_Dlv_Label", REPLY, CUS_INV_Create_Dlv_Label);
	COM_add_service("CUS_INV", "CUS_INV_Delete_Dlv_Label", REPLY, CUS_INV_Delete_Dlv_Label);
	COM_add_service("CUS_INV", "CUS_INV_Create_Issue_Request", REPLY, CUS_INV_Create_Issue_Request);
	COM_add_service("CUS_INV", "CUS_INV_Delete_Issue_Request", REPLY, CUS_INV_Delete_Issue_Request);
	COM_add_service("CUS_INV", "CUS_INV_Confirm_Issue_Request", REPLY, CUS_INV_Confirm_Issue_Request);
	COM_add_service("CUS_INV", "CUS_INV_Create_Issue_Request_Lot", REPLY, CUS_INV_Create_Issue_Request_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Delete_Issue_Request_Lot", REPLY, CUS_INV_Delete_Issue_Request_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Receive_Issue_Request_Lot", REPLY, CUS_INV_Receive_Issue_Request_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Kitting_Lot", REPLY, CUS_INV_Kitting_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Regenerate_Lot", REPLY, CUS_INV_Regenerate_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Move_Lot_Order", REPLY, CUS_INV_Move_Lot_Order);
	COM_add_service("CUS_INV", "CUS_INV_Loss_Dlv_Label", REPLY, CUS_INV_Loss_Dlv_Label);
	COM_add_service("CUS_INV", "CUS_INV_Move_Shipment", REPLY, CUS_INV_Move_Shipment);
	COM_add_service("CUS_INV", "CUS_INV_Change_Etc_Comment", REPLY, CUS_INV_Change_Etc_Comment);
    COM_add_service("CUS_INV", "CUS_INV_Tran_Multi_Cv_Lot", REPLY, CUS_INV_Tran_Multi_Cv_Lot);     //자재 CV화면 호출.
	COM_add_service("CUS_INV", "CUS_INV_Delete_Dlv_order", REPLY, CUS_INV_Delete_Dlv_order);
	COM_add_service("CUS_INV", "CUS_INV_Update_inv_data_update", REPLY, CUS_INV_Update_inv_data_update);

	//View Service
    COM_add_service("CUS_INV", "CUS_INV_View_Move_History_List", REPLY, CUS_INV_View_Move_History_List);
	COM_add_service("CUS_INV", "CUS_INV_View_Lot_Issue_List", REPLY, CUS_INV_View_Lot_Issue_List);
    COM_add_service("CUS_INV", "CUS_INV_View_Lot_History_List", REPLY, CUS_INV_View_Lot_History_List);
	COM_add_service("CUS_INV", "CUS_INV_View_PO_List", REPLY, CUS_INV_View_PO_List);
	COM_add_service("CUS_INV", "CUS_INV_View_Lot_List_By_Oper", REPLY, CUS_INV_View_Lot_List_By_Oper);
	COM_add_service("CUS_INV", "CUS_INV_View_Store_Lot_List", REPLY, CUS_INV_View_Store_Lot_List);
    COM_add_service("CUS_INV", "CUS_INV_View_Lot_List_By_Mat", REPLY, CUS_INV_View_Lot_List_By_Mat);

	//PDA View Service
	COM_add_service("CUS_INV", "CUS_INV_View_Issue_Request", REPLY, CUS_INV_View_Issue_Request);
	COM_add_service("CUS_INV", "CUS_INV_View_Issue_Request_Lot", REPLY, CUS_INV_View_Issue_Request_Lot);
	COM_add_service("CUS_INV", "CUS_INV_View_Lot_Info", REPLY, CUS_INV_View_Lot_Info);
	COM_add_service("CUS_INV", "CUS_INV_View_Move_Lot", REPLY, CUS_INV_View_Move_Lot);

	//PDA Validation Service
	COM_add_service("CUS_INV", "CUS_INV_Validation_Issue_Request_Lot", REPLY, CUS_INV_Validation_Issue_Request_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Validation_Dlv_Lot", REPLY, CUS_INV_Validation_Dlv_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Validation_Etc_Out_Lot", REPLY, CUS_INV_Validation_Etc_Out_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Validation_Move_Lot", REPLY, CUS_INV_Validation_Move_Lot);
	COM_add_service("CUS_INV", "CUS_INV_Check_Barcode_Type", REPLY, CUS_INV_Check_Barcode_Type);
	COM_add_service("CUS_INV", "CUS_INV_Delete_Lot", REPLY, CUS_INV_Delete_Lot);

	//VIETNAM Service
	COM_add_service("CUS_INV", "CUS_INV_Arrival_Lot_From_Ship", REPLY, CUS_INV_Arrival_Lot_From_Ship);
	COM_add_service("CUS_INV", "CUS_INV_Production_Lot_Conversion", REPLY, CUS_INV_Production_Lot_Conversion);
}
