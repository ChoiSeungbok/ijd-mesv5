/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_ORD_service.h
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

#ifndef _CUS_ORD_SERVICES_H
#define _CUS_ORD_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_ORD_add_service();
#endif

extern int CUS_ORD_Update_Order_Bom(TRSNode *in_node, TRSNode *out_node);
extern int CUS_ORD_View_Order_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_ORD_Prod_Plan_Registration(TRSNode *in_node, TRSNode *out_node);
extern int CUS_ORD_Create_Test_Order(TRSNode *in_node, TRSNode *out_node);

#endif
