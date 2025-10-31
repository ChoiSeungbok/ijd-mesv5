#ifndef _RASCORE_SERVICES_H
#define _RASCORE_SERVICES_H

/*
** Function Prototype Definitions
*/

extern int RAS_Change_Port_State(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Change_Transfer_State(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Change_Association_State(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Change_Access_Mode_State(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Change_Reservation_State(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Copy_Resource_Group(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Delete_Resource_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Delete_Sub_Resource_History(TRSNode *in_node, TRSNode *out_node) ;
extern int RAS_Make_Sheet_Result(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Resource_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Sub_Resource_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Trouble_Resource(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_PM_Schedule(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_PM_Schedule_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_PM_Security(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_PM_Security_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Port(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource_Group(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource_Group_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource_Labor(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Resource_MFO_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Sheet(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Sheet_Query(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Sheet_Type_Def(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Sub_Resource(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Sub_Resource_Event(TRSNode *in_node, TRSNode *out_node);

extern int RAS_View_Resource(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_ResEvent_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Labor_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_LotByRes_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Event_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_List_DETAIL_BYGROUP(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_ResLot_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_History( TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Down_History_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Down_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_PM_Sec_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_PM_Schedule(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_PM_Schedule_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_PM_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Query_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Query(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Result(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Make_Sheet_Result(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Type_Def(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_PM_Security_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Port(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Port_History_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Port_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Group(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_List_Detail_ByGroup(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Result_Data_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sheet_Result_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sub_ResEvent_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sub_Resource(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sub_Resource_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sub_Resource_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Resource_Type_List(TRSNode *in_node, TRSNode *out_node);

#if _CRR

extern int RAS_Create_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Assign_Sublot_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Attach_Lot_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Change_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Clean_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Detach_Lot_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_End_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Start_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Carrier_Group(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Carrier_Group_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Reserve_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Unreserve_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Carrier_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Carrier_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Terminate_Carrier(TRSNode *in_node, TRSNode *out_node);


extern int RAS_View_Carrier(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_List( TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Lot(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Lot_List( TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_SubLot_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_History_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_History_List_BY_Lot(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_List_BY_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Slot_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_List_By_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Event_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Group(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_History_List_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Lot_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_MFO_Option(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Sublot_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Carrier_Sublot_List_Detail(TRSNode *in_node, TRSNode *out_node);

#endif /* _CRR */

#if _TOOL

extern int RAS_Clean_Tool_Defect(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Collect_Tool_Defect(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Delete_Tool_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Tool_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Tool(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Tool_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Tool_Event_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Tool_Type(TRSNode *in_node, TRSNode *out_node);
extern int RAS_Update_Tool_Type_Relation(TRSNode *in_node, TRSNode *out_node);

extern int RAS_View_Tool_Type(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Type_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Event(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Event_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Event_Relation_List( TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Type_Relation(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Type_Relation_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Defect(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Defect_List(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Defect_List_DETAIL(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_History(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_Defect_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Tool_List_Detail(TRSNode *in_node, TRSNode *out_node);

#endif /* _TOOL */

/* Added by ICBAE 2012.04.16 */
extern int RAS_View_Port_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int RAS_View_Sub_Resource_List_Detail(TRSNode *in_node, TRSNode *out_node);

extern int RAS_Abort_Start_Carrier(TRSNode *in_node, TRSNode *out_node);

#endif /* _RASCORE_SERVICES_H */



