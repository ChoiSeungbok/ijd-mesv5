/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_WIP_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/06/22  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_WIP_SERVICES_H
#define _CUS_WIP_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_WIP_add_service();
#endif

//core  process service
extern int CUS_WIP_Start_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Adapt_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Create_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Split_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Loss_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Skip_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Move_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Terminate_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Cv_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Bonus_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Hold_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Release_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Generate_Id(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Store_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Unstore_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Merge_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Regenerate_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Ship_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Move_Lot_Force(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Etc_In_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Regenerate_P_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Validation_Etc_Out_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Delete_History(TRSNode *in_node, TRSNode *out_node);

//test service
extern int CUS_WIP_Test_Process(TRSNode *in_node, TRSNode *out_node);

//cus process service
extern int CUS_WIP_View_Oper_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Lot_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Lot_Loss(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Input_Material_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Worker_Management(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Process_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Multi_Process_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Worker_Registration(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Move_Lot_Order(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Cup_Cell_Process_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_non_operation(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Input_Lot_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Outsourcing_Process(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Blending_Order(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Material_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Oper_Loss(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Label_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Worker_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Grit_Class_Process(TRSNode *in_node, TRSNode *out_node);

extern int CUS_WIP_Inventory_Survey(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Lot_Press_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Loss_By_Oper(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Etc_Out_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Send_Resource_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Change_Item(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Create_Stock_In_Oper(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Delete_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_View_Lot_History(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Productivity_Goal(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Split_Wip_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Merge_Wip_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Working_Time(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Lot_Comment(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Delete_P_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Create_Erp_If_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Classify_Master_Data_List(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Change_Test_Prod_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_ras_yield_st(TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_Update_Lot_Res_Worktime(TRSNode *in_node, TRSNode *out_node);

#endif
