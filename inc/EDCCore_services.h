/*******************************************************************************

    System      : MESplus
    Module      : EDCCore
    File Name   : EDCCore_common.h
    Description : external function prototype definition of EDCCore Library

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

#ifndef _EDCCORE_SERVICES_H
#define _EDCCORE_SERVICES_H

extern int EDC_Approval_And_Release_to_Version(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Attach_Character(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Change_Char_Sequence(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Change_Lot_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Change_Res_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Collect_Lot_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Collect_Res_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Copy_Col_Set(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Copy_Col_Set_Version(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Delete_LotData_History(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Delete_ResData_History(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Find_Col_Set_Version(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_Attach_Character(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_Character(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_Col_Set(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_Col_Set_Version(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_Default_Unit_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_MFO_ColSet(TRSNode *in_node, TRSNode *out_node);
extern int EDC_Update_MFO_ColSet_List(TRSNode *in_node, TRSNode *out_node);
/*Add By JU.Heo 2012.11.29*/
extern int EDC_Update_Value_Prompt(TRSNode *in_node, TRSNode *out_node);
/* End Add */
extern int EDC_View_Attach_Character(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Attach_Character_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Character(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Character_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Character_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set_List_By_Group(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set_Version(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Col_Set_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Default_Unit_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Lot_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Lot_Data_By_ColSet(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_MFO_ColSet(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_MFO_ColSet_List(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Resource_Data(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Resource_Data_By_ColSet(TRSNode *in_node, TRSNode *out_node);
extern int EDC_View_Derived_Character_List(TRSNode *in_node, TRSNode *out_node);
/*Add By JU.Heo 2012.11.29*/
extern int EDC_View_Value_Prompt(TRSNode *in_node, TRSNode *out_node);
/* End Add */
#endif /* _EDCCORE_SERVICES_H */


