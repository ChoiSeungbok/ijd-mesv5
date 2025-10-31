
#ifndef _SECCORE_SERVICES_H
#define _SECCORE_SERVICES_H

/*
** MESplus include files
*/
extern int SEC_Login(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Login_Ext(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Change_Password(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Change_Password_Ext(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Copy_Privilege_Group(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Copy_SecGrp(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_Favorites(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_Function(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_GrpFunc_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_Privilege(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_Privilege_Group(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_Privilege_Group_User(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Update_SecGrp(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Update_User(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Update_User_Ext(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_Update_Flexible_Header(TRSNode *in_node, TRSNode *out_node);

extern int SEC_Get_HelpURL(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Favorites_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Function(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Function_Detail(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Function_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_GrpFunc_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Privilege(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Privilege_Group(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Privilege_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Privilege_Group_User_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Privilege_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_SecGrp(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_SecGrp_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_User(TRSNode *in_node,  TRSNode *out_node); 
extern int SEC_View_User_Ext(TRSNode *in_node, TRSNode *out_node); 
extern int SEC_View_User_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Flexible_Header_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_View_Group_By_Type_Privilege_List(TRSNode *in_node, TRSNode *out_node);
extern int SEC_Check_Session(TRSNode *in_node);
extern int SEC_View_Concurrent_User_Info(TRSNode *in_node, TRSNode *out_node);

#endif /* _SECCORE_SERVICES_H */

