#ifndef _RCPCORE_SERVICES_H
#define _RCPCORE_SERVICES_H

/*
** MESplus include files
*/
extern int  RCP_Approval_Release_Recipe_Version(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Copy_Recipe_Version(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_Lot_Recipe(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_MFO_Recipe_List(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_Para_Version(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_Recipe(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_Recipe_Version(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_Update_Sublot_Recipe(TRSNode *in_node, TRSNode *out_node);

extern int  RCP_View_Lot_Recipe(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Lot_Recipe_History(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_MFO_Recipe_List(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Para_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Recipe(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Recipe_List(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Recipe_Version(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Recipe_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Sublot_Recipe(TRSNode *in_node, TRSNode *out_node);
extern int  RCP_View_Sublot_Recipe_History(TRSNode *in_node, TRSNode *out_node);

#endif /* _RCPCORE_SERVICES_H */



