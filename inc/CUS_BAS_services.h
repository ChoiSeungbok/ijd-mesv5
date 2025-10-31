/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_BAS_service.h
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

#ifndef _CUS_BAS_SERVICES_H
#define _CUS_BAS_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_BAS_add_service();
#endif

extern int CUS_BAS_Update_Caption(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Update_Caption_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_View_Caption(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_View_Caption_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_update_Attach(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Register_Checksheet(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Update_Used_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Update_Reports_File(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Print_Label_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_View_Global_Area_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_BAS_Update_Emi_User(TRSNode *in_node, TRSNode *out_node);
#endif
