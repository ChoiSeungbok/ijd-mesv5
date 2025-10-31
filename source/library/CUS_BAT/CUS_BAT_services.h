/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_BAT_service.h
    Description : Customer function prototype of Customer defined shared library

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

#ifndef _CUS_BAT_SERVICES_H
#define _CUS_BAT_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_BAT_add_service();
#endif

extern int CUS_BAT_Erp_Mes_Customer_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Mat_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_P_Wo_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Pack_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Po_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Return_Order_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Ship_Order_Info(TRSNode *in_node, TRSNode *out_node);

extern int CUS_BAT_Erp_Mes_Std_Bom_Def(TRSNode *in_node, TRSNode *out_node);

extern int CUS_BAT_Erp_Mes_Sub_Area_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Transaction_Type_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Uom_Conv_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Vendor_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Wh_Def(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Wo_Bom_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Mes_Wo_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Setup_Calendar_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_Erp_Alarm_Raise(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAT_alarm_raise_half_hour(TRSNode* in_node, TRSNode* out_node);


#endif
