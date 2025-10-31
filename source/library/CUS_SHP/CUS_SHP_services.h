/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_SHP_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_SHP_SERVICES_H
#define _CUS_SHP_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_SHP_add_service();
#endif

extern int CUS_SHP_Create_Pack_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Delete_Pack_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Confirm_Pack_Order(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Create_Pack_Box(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Delete_Pack_Box(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Create_Pack_Final_Box(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Delete_Pack_Final_Box(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Return_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_View_Order_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_View_Ship_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_View_Return_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Validation_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Check_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_ERP_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_Update_Pack_Order(TRSNode *in_node, TRSNode *out_node);


#endif
