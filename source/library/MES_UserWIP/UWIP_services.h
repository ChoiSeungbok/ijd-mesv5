/*******************************************************************************

    System      : MESplus
    Module      : User Defined Shared Library
    File Name   : sl_common.h
    Description : user function prototype of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/10  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _WIP_SERVICES_H
#define _WIP_SERVICES_H

#include <SLCCore_common.h>

#if defined(_USE_STATIC_LIB)

extern void WIP_UserRoutine_add_service();

#endif

DllExport int UWIP_Summary_Temp_Lot_1(TRSNode *in_node, TRSNode *out_node);
DllExport int UWIP_Generate_Sublot_ID_1(TRSNode *in_node, TRSNode *out_node);

DllExport int UWIP_Future_Action_Custom_Action_1(TRSNode *in_node, TRSNode *out_node);
DllExport int UWIP_Future_Action_Custom_Condition_1(TRSNode *in_node, TRSNode *out_node);

DllExport int WIP_Adapt_Lot_Before_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Adapt_Lot_After_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_End_Lot_Before_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_End_Lot_After_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Start_Lot_Before_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Start_Lot_After_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Update_Factory_Before_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Update_Factory_After_1(TRSNode *in_node, TRSNode *out_node); 
DllExport int WIP_View_Hold_Lot_List_Before_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_View_Hold_Lot_List_After_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Delete_Lot_History_After_1(TRSNode *in_node, TRSNode *out_node);
DllExport int WIP_Delete_Lot_History_Before_1(TRSNode *in_node, TRSNode *out_node);

#endif

