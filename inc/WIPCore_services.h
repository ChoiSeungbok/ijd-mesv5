
#ifndef _WIPCORE_SERVICES_H
#define _WIPCORE_SERVICES_H

/*
** Function Prototype Definitions
*/

extern int WIP_Adapt_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Adapt_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Attach_Flow_ToMaterial(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Attach_Oper_ToFlow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Bonus_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Check_Queue_Time(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Clean_Lot_Defect(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Close_ReturnLot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Collect_Lot_Defect(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Combine_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Combine_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Combine_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Copy_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Create_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Create_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Delete_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Delete_Sublot_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Detach_Flow_FromMaterial(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Detach_Oper_FromFlow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Generate_ID(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Hold_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Hold_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Local_Repair_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Local_Repair_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Loss_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Loss_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Loss_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Lot_Edc(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Make_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Make_Reserve_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Merge_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Merge_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Merge_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Move_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Move_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Start_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Open_ReturnLot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Receive_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Receive_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Release_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Release_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Release_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Repair_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Repair_End_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Repair_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Repair_Sublot(TRSNode *in_node, TRSNode *out_node);
//extern int WIP_Resume_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Rework_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Rework_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Ship_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Skip_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Skip_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Sort_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Sort_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Sort_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Split_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Split_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Split_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Start_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Start_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Start_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Start_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Store_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Store_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Swap_Flow_Seq(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Swap_Operation_Seq(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Terminate_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Terminate_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Trouble_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Unstore_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Unstore_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Reserve_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Reserve_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Unreserve_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Unreserve_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Change_CMF(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Scribe_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Scribe_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Scribe_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_CV_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Delete_Start_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Regenerate_Lot(TRSNode *in_node, TRSNode *out_node);
/* 2010.12.23 Added by Simon Kim */
extern int WIP_Start_Lot_For_Step(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Lot_For_Step(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Swap_Step_Seq(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Attach_Step_ToOperation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Detach_Step_FromOperation(TRSNode *in_node, TRSNode *out_node);


extern int WIP_Update_Batch_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Batch_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_CycleTime(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Factory(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_Update_Factory_Cmf_Item(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_Update_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Future_Action(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_ID_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Material(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_MFO_Batch_Keep_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_MFO_Grade_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_MFO_Option_Definition(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_Update_MFO_Option_Prompt(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_Update_MFO_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_MFO_Sublot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Operation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Optional_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Optional_Oper(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_Update_Queue_Time(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Repair_Oper(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Rework_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Rule_Def(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Rule_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Ship_Factory(TRSNode *in_node, TRSNode *out_node);
/* extern int WIP_Update_Sublot_Grade_List(TRSNode *in_node, TRSNode *out_node); */
extern int WIP_Update_Yield(TRSNode *in_node, TRSNode *out_node);
/* 2010.12.23 Added  by Simon Kim */
extern int WIP_Update_Step(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Step_MFO_Relation(TRSNode *in_node, TRSNode *out_node);

extern int WIP_View_Batch_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Batch_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Batch_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Batch_Relation_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Batch_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Batch_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_CycleTime_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Data_List_By_Attribute(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Ext_Code_Table(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Factory(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_View_Factory_Cmf_Item(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_View_Factory_List(TRSNode *in_node, TRSNode *out_node); 
extern int WIP_View_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Flow_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Flow_List_By_Operation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Flow_Sequence_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Future_Action(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Future_Action_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Grade_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Hold_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_ID_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_ID_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Bonus_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Defect_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Hold_Code_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_List_By_Operation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_List_By_Resource(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_List_Detail_By_SQL_Query(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Loss_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Trace(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Trace_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Trace_Tree(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Material(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Material_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Material_List_By_Flow(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Material_List_By_Group(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Material_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Batch_Keep_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Option_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Option_Definition_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Option_Prompt(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Option_Prompt_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Queue_Time_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_Sublot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Operation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Operation_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_ProcTime(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Process_Operation_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Queue_Time(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Repair_Oper_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Reserve_Batch(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Reserve_Batch_Id_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Reserve_Batch_Item_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_ReturnLot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_ReturnLot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rework_Flow_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rework_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rework_Oper_List(TRSNode *in_node,TRSNode *out_node);
extern int WIP_View_Rule_Def(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rule_Def_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rule_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Rule_Relation_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Ship_Factory(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Ship_Factory_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Sublot_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Sublot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Sublot_List_Detail(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Sublot_Loss_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Transit_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Trouble_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Trouble_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Yield_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Reserve_Lot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Reserve_Sublot_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_CMF_Change(TRSNode *in_node, TRSNode *out_node);

// Added By ICBAE 2010.04.14
extern int WIP_Release_Lot_By_Force(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Release_Sublot_By_Force(TRSNode *in_node, TRSNode *out_node);

// Added by LAVERWON - 2010/11/30
// Generate ID
extern int WIP_View_Gen_ID_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_ID_Gen_Init(TRSNode *in_node, TRSNode *out_node);
extern int WIP_ID_Gen_Approval(TRSNode *in_node, TRSNode *out_node);


/* 2010.12.23 Added by Simon Kim */
extern int WIP_View_Step(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Step_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_Step_Status(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Lot_History_For_Step(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Delete_Lot_History_For_Step(TRSNode *in_node, TRSNode *out_node);

/* Added by phillip 2011.02.10 */
extern int WIP_Update_Operation_Input_Value_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Operation_Input_Value_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Tool_List_By_MFO(TRSNode *in_node, TRSNode *out_node);

extern int WIP_View_MFO_Option_Value(TRSNode *in_node, TRSNode *out_node);

//Add by J.S. 2011.09.30
extern int WIP_View_Factory_Cmf_List_Detail(TRSNode *in_node, TRSNode *out_node);

//Add by Aiden. 2012.03.28
extern int WIP_Transfer_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Transfer_Sublot(TRSNode *in_node, TRSNode *out_node);

//Add by IC.BAE 2012.03.28
extern int WIP_View_MFO_Info(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Multi_Setup(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Get_Flow_Oper_By_Count(TRSNode *in_node, TRSNode *out_node);

// Added by DM KIM 2012.04.09
extern int WIP_Multi_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Transfer_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Hold_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Release_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Receive_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Merge_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Multi_Split_Lot(TRSNode *in_node, TRSNode *out_node);

// Added by DM KIM 2012.04.18
extern int WIP_Update_Test_Program(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Test_Program_Key_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Test_Program_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Test_Program_Version(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Approval_Release_Test_Program(TRSNode *in_node, TRSNode *out_node);


//Add by bs.Kwak 2012 03 29 
extern int WIP_QA_Gate(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_QA_Rule_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_QA_Sample_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_QA_Action_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_QA_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_QA_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_MFO_QA_Rule_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_MFO_QA_Rule(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_QA_History_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_QA_Maint(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Qa_Result_Action(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Qa_Result_Action(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Low_Yield(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Low_Yield(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Low_Yield_List(TRSNode *in_node, TRSNode *out_node);

//Add by bs.Kwak 2012 04 25
extern int WIP_View_Qa_Lot_Defect_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Qa_SubLot_Defect_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Qa_Lot_History(TRSNode *in_node, TRSNode *out_node);

extern int WIP_Copy_MFO(TRSNode *in_node, TRSNode *out_node);

// Added by DM KIM 2014.01.14
extern int WIP_Multi_Terminate_Lot(TRSNode *in_node, TRSNode *out_node);

extern int WIP_View_Bin_Definition_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Version(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Version_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Bin_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Bin_Version(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Copy_Bin_Definition(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Copy_Bin_Version(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Bin_Unit(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Bin_Grade(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Unit(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Grade(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Bin_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_Relation(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Update_Priority(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Priority(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Priority_List(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Collect_Bin_Data(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_History(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_History_Grade(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_History_Sublot_Grade(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Bin_History_Sublot_Unit_Total(TRSNode *in_node, TRSNode *out_node);
extern int WIP_End_Lot_By_Bin(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Test_Program_By_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_View_Latest_Bin_Collection_Data(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Confirm_Generated_ID(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Batch_Check_Queue_Time(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Bonus_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Bonus_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_CV_Sublot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_CV_Lot_Ext(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Copy_ID_Rule(TRSNode *in_node, TRSNode *out_node);

// Added by MHIM 2015.08.12
extern int WIP_Abort_Start_Lot(TRSNode *in_node, TRSNode *out_node);
extern int WIP_Abort_Start_Sublot(TRSNode *in_node, TRSNode *out_node);

#endif /* _WIPCORE_SERVICES_H */
