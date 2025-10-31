
#ifndef _SPCCORE_SERVICES_H
#define _SPCCORE_SERVICES_H

/*
** MESplus include files
*/

extern int SPC_Ack_Alarm(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Attach_Chart_Set(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Chart_User(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Auto_Calculation_Control_Limit(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Clear_Alarm(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Collect_EDC_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Collect_ChartSet_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Exclude_EDC_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Find_Spec_Version(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Chart(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Chart_Set(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Default_Unit_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_MFO_Chart(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_MFO_Chart_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_OOC_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Prompt(TRSNode *in_node, TRSNode *out_node);
extern int SPC_Update_Spec(TRSNode *in_node, TRSNode *out_node);

extern int SPC_View_Chart(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Chart_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Spec(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Spec_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_OOC_History_Detail(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_OOC_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_ControlChart(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_EDC_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Spec_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Raw_Data(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Chart_User_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Process_Capability(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Exclude_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Exclude_History_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Alarm_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Chart_Set(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Chart_Set_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Exclude_History(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Exclude_History_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Prompt(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Default_Unit_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Chart_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_EDC_Data_ChartSet(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_Attach_Chart_Set_List(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_MFO_Chart(TRSNode *in_node, TRSNode *out_node);
extern int SPC_View_MFO_Chart_List(TRSNode *in_node, TRSNode *out_node);


#endif /* _SPCCORE_SERVICES_H */

