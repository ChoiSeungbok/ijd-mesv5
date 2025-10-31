
#ifndef _WEMCORE_SERVICES_H
#define _WEMCORE_SERVICES_H

extern int WEM_Update_Work_Process_Type(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process_Type(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process_Type_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Status_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Update_Work_Status_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Update_Process_Step(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Process_Step(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Process_Step_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Step_Action_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Step_Action(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Update_Step_Action(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process_Step_User_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Update_Work_Process(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Update_Work_Process_Step_User(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Work_Process_Step(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Process_Event(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Event_Step_Status(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Event_List(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Event_Status(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Event_History(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Delete_Event_History(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Copy_Work_Process(TRSNode *in_node, TRSNode *out_node);
extern int WEM_Copy_Process_Step(TRSNode *in_node, TRSNode *out_node);
extern int WEM_View_Event_Status_Detail(TRSNode *in_node, TRSNode *out_node);

#endif /* _WEMCORE_SERVICES_H */


