/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_RAS_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2022/06/22  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_RAS_SERVICES_H
#define _CUS_RAS_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_RAS_add_service();
#endif

extern int CUS_RAS_View_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Tool_Event(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Update_Tool(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Spare_Management(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Resouce_Repairinfo_Registration(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Mold_Store_Registration(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Scrap_Mold_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Scrap_Mold_Confirm(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Mold_Tool_Event(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Create_Scrap_Mold_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Tacktime_Registration(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Batch_Oee(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Update_Resource_Efficiency_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_Mold_Break_Registration(TRSNode *in_node, TRSNode *out_node);

extern int CUS_RAS_View_Cus_ras_asset_data(TRSNode *in_node, TRSNode *out_node);
#endif
