/*******************************************************************************

    System      : MESplus
    Module      : ARCCore
    File Name   : ARC_common.h
    Description : external function prototype definition of ARCCore Library

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2005/7/16   J.S.           Create

    Copyright(C) 1998-2005 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _ARCCORE_SERVICES_H
#define _ARCCORE_SERVICES_H

extern int ARC_Dearchive_Table(TRSNode *in_node, TRSNode *out_node);
extern int ARC_Insert_Archive_Running_List(TRSNode *in_node, TRSNode *out_node);
extern int ARC_Update_Archive_Opt(TRSNode *in_node, TRSNode *out_node);
extern int ARC_Update_Archive_Table(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Archive_Opt_Detail(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Archive_Opt_List(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Archive_Table_Detail(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Archive_Table_List(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Column_List(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Factory_List(TRSNode *in_node, TRSNode *out_node);
extern int ARC_View_Table_List(TRSNode *in_node, TRSNode *out_node);

#endif /* _ARCCORE_SERVICES_H */


