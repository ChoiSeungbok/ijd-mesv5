/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_INV_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/06/22  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_INV_SERVICES_H
#define _CUS_INV_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_INV_add_service();
#endif

extern int CUS_INV_Create_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CV_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Hold_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_In_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Issue_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Load_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Merge_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Move_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Release_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_RetOut_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Split_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Tempin_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Terminate_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Unload_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Create_Dlv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Confirm_Dlv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Dlv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Create_Dlv_Label(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Dlv_Label(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Create_Issue_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Issue_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Confirm_Issue_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Create_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Receive_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Kitting_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Move_History_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Lot_Issue_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Lot_History_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_PO_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Lot_List_By_Oper(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Store_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Issue_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Validation_Issue_Request_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Validation_Dlv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Validation_Etc_Out_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Lot_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Validation_Move_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Check_Barcode_Type(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Regenerate_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Lot_List_By_Mat(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Move_Lot_Order(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_View_Move_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Loss_Dlv_Label(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Move_Shipment(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Change_Etc_Comment(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Tran_Multi_Cv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Arrival_Lot_From_Ship(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Production_Lot_Conversion(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Delete_Dlv_order(TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_Update_inv_data_update(TRSNode* in_node, TRSNode* out_node);
#endif
