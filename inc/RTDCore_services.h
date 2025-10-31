
#ifndef _RTDCORE_SERVICES_H
#define _RTDCORE_SERVICES_H

extern int RTD_Copy_Dispatch_Rule(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Get_Lot_Simulation_Result(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Get_Resource_Simulation_Result(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Dispatch_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Dispatcher(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Dispatcher_Oper(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Dispatcher_Res(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Rule(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Rule_Items(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Reference_Operation(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Update_Dispatcher_Event(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Adjust_Lot_Priority(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Re_Dispatch_Lot(TRSNode *in_node, TRSNode *out_node);
extern int RTD_Interface(TRSNode *in_node);

extern int RTD_View_Dispatch_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatcher(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatcher_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_DspOper_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_DspRes_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Resource_PriSts(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Rule(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Rule_Item(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Rule_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Reference_Operation(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatcher_Event(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatcher_Event_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatcher_Event_History(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Pre_Dispatched_History(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Pre_Dispatched_Status(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatched_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_View_Dispatched_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int RTD_External_Dispatch_Event(TRSNode *in_node, TRSNode *out_node);

#endif /* _RTDCORE_SERVICES_H */


