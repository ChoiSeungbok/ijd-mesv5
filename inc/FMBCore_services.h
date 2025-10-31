#ifndef _FMBCORE_SERVICES_H
#define _FMBCORE_SERVICES_H

extern int FMB_Copy_UDR_Group(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Exist_Control(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Moving_by_Force(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Resource_Priority(TRSNode *in_node, TRSNode *out_node);
extern int FMB_UDR_Priority(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_Environment(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_FMB_Group(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_LayOut(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_ResLoc_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_Event_Color(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_Resource_Image(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_Resource_Location(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_UDR_Group(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_UDR_ResLoc(TRSNode *in_node, TRSNode *out_node);
extern int FMB_Update_UDRLoc_List(TRSNode *in_node, TRSNode *out_node);

extern int FMB_Get_HelpURL(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_ResDetail_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Environment(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Environment_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_FMB_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_LayOut(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_LayOut_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Resource(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Event_Color(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Resource_Image_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Group(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Resource(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Event_Color_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Port(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Port_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Port_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Sub_Resource(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Sub_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Sub_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Tool(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Tool_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_Tool_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Port(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Port_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Port_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Sub_Resource(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Sub_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Sub_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Tool(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Tool_List(TRSNode *in_node, TRSNode *out_node);
extern int FMB_View_UDR_Tool_List_Detail(TRSNode *in_node, TRSNode *out_node);

#endif /* _FMBCORE_SERVICES_H */
