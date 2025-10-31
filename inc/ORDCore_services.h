
#ifndef _ORDCORE_SERVICES_H
#define _ORDCORE_SERVICES_H

extern int ORD_Create_Lot(TRSNode *in_node, TRSNode *out_node);
extern int ORD_Update_Attach_Order_Lot(TRSNode *in_node, TRSNode *out_node);
extern int ORD_Update_Order(TRSNode *in_node, TRSNode *out_node);
extern int ORD_Update_Plan(TRSNode *in_node, TRSNode *out_node);
extern int ORD_Update_PlannedLot(TRSNode *in_node, TRSNode *out_node);
extern int ORD_Update_WorkOrder(TRSNode *in_node, TRSNode *out_node);

extern int ORD_View_Attach_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Order(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Order_List(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Order_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Plan( TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Plan_List( TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_Plan_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_PlannedLot(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_PlannedLot_List(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_PlannedLot_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int ORD_View_WorkOrder_List(TRSNode *in_node, TRSNode *out_node);

#endif /* _ORDCORE_SERVICES_H */



