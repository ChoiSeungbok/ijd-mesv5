
#ifndef _SPMCORE_SERVICES_H
#define _SPMCORE_SERVICES_H

/*
** Function Prototype Definitions
*/

extern int SPM_Update_Spec(TRSNode *in_node, TRSNode *out_node);
extern int SPM_Update_Spec_Character(TRSNode *in_node, TRSNode *out_node);
extern int SPM_Copy_Spec_Version(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_List(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Version(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Character(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Character_List(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Limit(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Attach_File(TRSNode *in_node, TRSNode *out_node);
extern int SPM_View_Spec_Value(TRSNode *in_node, TRSNode *out_node);
extern int SPM_Compare_Spec_Value(TRSNode *in_node, TRSNode *out_node);


#endif /* _SPMCORE_SERVICES_H */
