/*******************************************************************************

    System      : MESplus
    Module      : User Defined Shared Library
    File Name   : CUS_services.h
    Description : user function prototype of user defined shared library

    MES Version : 5.1

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

#ifndef _CUS_SERVICES_H
#define _CUS_SERVICES_H

extern int DNM_Update_Direct_View(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Direct_View(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Direct_View_List(TRSNode *in_node, TRSNode *out_node);

extern int DNM_Update_Direct_View_Header(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Direct_View_Header_List(TRSNode *in_node, TRSNode *out_node);
extern int DNM_Multi_Update_Direct_View_Header(TRSNode *in_node, TRSNode *out_node);
extern int DNM_Update_Header_User(TRSNode *in_node, TRSNode *out_node);
extern int DNM_Multi_Update_Header_User(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Header_User_List(TRSNode *in_node, TRSNode *out_node);

extern int DNM_Update_Direct_View_Condition(TRSNode *in_node, TRSNode *out_node);
extern int DNM_Multi_Update_Direct_View_Condition(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Direct_View_Condition(TRSNode *in_node, TRSNode *out_node);
extern int DNM_View_Direct_View_Condition_List(TRSNode *in_node, TRSNode *out_node);

#endif