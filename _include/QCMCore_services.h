#ifndef _QCMCORE_SERVICES_H
#define _QCMCORE_SERVICES_H

/*
** MESplus include files
*/
extern int QCM_Approval_And_Release_to_Version(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Copy_Inspection_Version(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Create_Batch(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Final_Decision(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Find_Inspection_Version(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Merge_Batch(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Request_Reinspection(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Result_Recording(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Result_Recording_Individual(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Split_Batch(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Update_Attach_Insp_Item(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Update_Inspection_Item(TRSNode *in_node, TRSNode *out_node );
extern int QCM_Update_Inspection_Material(TRSNode *in_node, TRSNode *out_node );
extern int QCM_Update_Inspection_Set(TRSNode *in_node, TRSNode *out_node );
extern int QCM_Update_Inspection_Version(TRSNode *in_node, TRSNode *out_node);
extern int QCM_Update_Sampling_Procedure(TRSNode *in_node, TRSNode *out_node );

extern int QCM_View_Attach_Insp_Item(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Attach_Insp_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Attach_Insp_Item_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Batch_Info(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Batch_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_History(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Item(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Material(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Material_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Set(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Set_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Version(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Inspection_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Item_Inspection_History(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_QC_Batch_History(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_QC_Batch_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Sampling_Procedure(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Sampling_Procedure_List(TRSNode *in_node, TRSNode *out_node);
extern int QCM_View_Defect_List(TRSNode *in_node, TRSNode *out_node);

#endif /* _QCMCORE_SERVICES_H */

