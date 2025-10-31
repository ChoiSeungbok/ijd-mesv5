
#ifndef _INVCORE_SERVICES_H
#define _INVCORE_SERVICES_H

extern int INV_Consume(TRSNode *in_node, TRSNode *out_node);
extern int INV_Conv_To_Inv(TRSNode *in_node, TRSNode *out_node);
extern int INV_Conv_To_Lot(TRSNode *in_node, TRSNode *out_node);
extern int INV_Delete_Inventory_History(TRSNode *in_node, TRSNode *out_node);
extern int INV_In_Inventory(TRSNode *in_node, TRSNode *out_node);
extern int INV_In_Inventory_Serial(TRSNode *in_node, TRSNode *out_node);
extern int INV_Out_Inventory(TRSNode *in_node, TRSNode *out_node);
extern int INV_Out_Inventory_Serial(TRSNode *in_node, TRSNode *out_node);
extern int INV_Scrap(TRSNode *in_node, TRSNode *out_node);
extern int INV_Scrap_Serial(TRSNode *in_node, TRSNode *out_node);
extern int INV_Transfer_Inventory(TRSNode *in_node, TRSNode *out_node);
extern int INV_Transfer_Inventory_Serial(TRSNode *in_node, TRSNode *out_node);
extern int INV_Update_Serial_List(TRSNode *in_node, TRSNode *out_node);

extern int INV_View_Inventory_History(TRSNode *in_node, TRSNode *out_node);
extern int INV_View_Inventory_Info(TRSNode *in_node, TRSNode *out_node);
extern int INV_View_Inventory_Info_Serial(TRSNode *in_node, TRSNode *out_node);

#endif /* _INVCORE_SERVICES_H */

