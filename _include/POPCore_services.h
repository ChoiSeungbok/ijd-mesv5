#ifndef _POPCORE_SERVICES_H
#define _POPCORE_SERVICES_H

extern int POP_Copy_Label(TRSNode *in_node, TRSNode *out_node);
extern int POP_Gen_Label(TRSNode *in_node, TRSNode *out_node);
extern int POP_Update_Image(TRSNode *in_node, TRSNode *out_node);
extern int POP_Update_Label(TRSNode *in_node, TRSNode *out_node);
extern int POP_Update_Label_Design(TRSNode *in_node, TRSNode *out_node);
extern int POP_Update_LotLabel_Print_History(TRSNode *in_node, TRSNode *out_node);
extern int POP_Update_MaterialLabel(TRSNode *in_node, TRSNode *out_node);

extern int POP_View_Image(TRSNode *in_node, TRSNode *out_node);
extern int POP_View_Image_List(TRSNode *in_node, TRSNode *out_node);
extern int POP_View_Label(TRSNode *in_node, TRSNode *out_node);
extern int POP_View_Label_Design(TRSNode *in_node, TRSNode *out_node);
extern int POP_View_Label_List(TRSNode *in_node, TRSNode *out_node);
extern int POP_View_PrintInfo(TRSNode *in_node, TRSNode *out_node); 

#endif /* _POPCORE_SERVICES_H */


