/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_QCM_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_QCM_SERVICES_H
#define _CUS_QCM_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_QCM_add_service();
#endif

//extern int CUS_BAS_Update_Caption(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_View_Lot_Info(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Inspection_Judge(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Collect_Inspection_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Create_Inspection_Request(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Update_Inspection_Status(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Collect_Inspection_Data_Grit(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Update_Inspection_Worker(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_View_Lot_Inspection_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Generate_Report(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Save_Report(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_File_Attach(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Ship_Report_Spec_Registration_By_Mat(TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_Ship_Report_Spec_Registration_By_Grade(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Batch_Mig_Data_Qcm(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Batch_Mig_Data_Prt(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Collect_Cut_Inspection_Upload(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Recipe_Management(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Collect_Spc_Data(TRSNode *in_node, TRSNode * out_node);
extern int CUS_QCM_Update_CUS_QCM_Customer_Claim(TRSNode* in_node, TRSNode* out_node);
extern int CUS_QCM_Update_CUS_QCM_Sample_Analysis(TRSNode* in_node, TRSNode* out_node);
extern int CUS_QCM_Update_CUS_QCM_Customer_Voc(TRSNode* in_node, TRSNode* out_node);
extern int CUS_QCM_Update_CUS_QCM_Other_Company_Spec(TRSNode* in_node, TRSNode* out_node);
#endif
