
#ifndef _SVMCORE_SERVICES_H
#define _SVMCORE_SERVICES_H

extern int SVM_Update_Member(TRSNode *in_node, TRSNode *out_node);
extern int SVM_Update_Service(TRSNode *in_node, TRSNode *out_node);
extern int SVM_Update_Service_Member_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_Update_Service_User_Routine_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_Update_Active_Function_Version(TRSNode *in_node, TRSNode *out_node);

extern int SVM_View_Member(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Member_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service_Member_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Module_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service_User_Routine_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Active_Function_Version(TRSNode *in_node, TRSNode *out_node);

//Add by J.S. 2011.10.25
extern int SVM_View_Service_Performance_Info_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service_Error_Log_List(TRSNode *in_node, TRSNode *out_node);
extern int SVM_View_Service_Error_Log(TRSNode *in_node, TRSNode *out_node);

//Add by Aiden. 2012.03.27
extern int SVM_View_Service_Consume_Time(TRSNode *in_node, TRSNode *out_node);

#endif /* _SVMCORE_SERVICES_H */


