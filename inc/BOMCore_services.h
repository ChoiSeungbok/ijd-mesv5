/*******************************************************************************

    System      : MESplus
    Module      : BOMCore
    File Name   : BOM_common.h
    Description : external function prototype definition of BOMCore Library

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/12/16  SK Jin         Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/


#ifndef _BOMCORE_SERVICES_H
#define _BOMCORE_SERVICES_H

extern int BOM_Approval_And_Release_to_Version(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Assembly_Lot(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Copy_BOMSet_Version(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Delete_BOM_History(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Disassemble_Lot(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Find_Bom_Set_Version(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Replace_Lot(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Update_Attach_Material(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Update_BOMSet(TRSNode *in_node, TRSNode *out_node);
extern int BOM_Update_BOMSet_Version(TRSNode *in_node, TRSNode *out_node);

extern int BOM_View_Attach_Material(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_Attach_Material_List(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_BOMSet(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_BOMSet_List(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_BOMSet_Version(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_BOMSet_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_Lot_History_For_Assembly(TRSNode *in_node, TRSNode *out_node);
extern int BOM_View_Lot_Status_For_Assembly(TRSNode *in_node, TRSNode *out_node);
/* Added By Bs.Kwak 2013.01.13*/
extern int BOM_Copy_BOMSet(TRSNode *in_node, TRSNode *out_node);

#endif /* _BOMCORE_SERVICES_H */



