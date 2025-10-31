/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_QCM_AddService.c
    Description : Common function of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <MESCore_service.h>
#include "CUS_QCM_services.h"


//Use static library
void CUS_QCM_add_service()
{
    //COM_add_service("CUS_BAS", "CUS_BAS_Update_Caption", REPLY, CUS_BAS_Update_Caption);
	COM_add_service("CUS_QCM", "CUS_QCM_View_Lot_Info", REPLY, CUS_QCM_View_Lot_Info);
	COM_add_service("CUS_QCM", "CUS_QCM_Inspection_Judge", REPLY, CUS_QCM_Inspection_Judge);
	COM_add_service("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", REPLY, CUS_QCM_Collect_Inspection_Data);
	COM_add_service("CUS_QCM", "CUS_QCM_Create_Inspection_Request", REPLY, CUS_QCM_Create_Inspection_Request);
	COM_add_service("CUS_QCM", "CUS_QCM_Update_Inspection_Status", REPLY, CUS_QCM_Update_Inspection_Status);
	COM_add_service("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", REPLY, CUS_QCM_Collect_Inspection_Data_Grit);
	COM_add_service("CUS_QCM", "CUS_QCM_Update_Inspection_Worker", REPLY, CUS_QCM_Update_Inspection_Worker);
	COM_add_service("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", REPLY, CUS_QCM_View_Lot_Inspection_Data);
	COM_add_service("CUS_QCM", "CUS_QCM_Generate_Report", REPLY, CUS_QCM_Generate_Report);
	COM_add_service("CUS_QCM", "CUS_QCM_Save_Report", REPLY, CUS_QCM_Save_Report);
	COM_add_service("CUS_QCM", "CUS_QCM_File_Attach", REPLY, CUS_QCM_File_Attach);
    COM_add_service("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Mat", REPLY, CUS_QCM_Ship_Report_Spec_Registration_By_Mat);
    COM_add_service("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Grade", REPLY, CUS_QCM_Ship_Report_Spec_Registration_By_Grade);
	COM_add_service("CUS_QCM", "CUS_QCM_Batch_Mig_Data_Qcm", REPLY, CUS_QCM_Batch_Mig_Data_Qcm);
	COM_add_service("CUS_QCM", "CUS_QCM_Batch_Mig_Data_Prt", REPLY, CUS_QCM_Batch_Mig_Data_Prt);
	COM_add_service("CUS_QCM", "CUS_QCM_Collect_Cut_Inspection_Upload", REPLY, CUS_QCM_Collect_Cut_Inspection_Upload);
	COM_add_service("CUS_QCM", "CUS_QCM_Recipe_Management", REPLY, CUS_QCM_Recipe_Management);
	COM_add_service("CUS_QCM", "CUS_QCM_Collect_Spc_Data", REPLY, CUS_QCM_Collect_Spc_Data);
    COM_add_service("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Claim", REPLY, CUS_QCM_Update_CUS_QCM_Customer_Claim);
    COM_add_service("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Sample_Analysis", REPLY, CUS_QCM_Update_CUS_QCM_Sample_Analysis);
    COM_add_service("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Voc", REPLY, CUS_QCM_Update_CUS_QCM_Customer_Voc);
    COM_add_service("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Other_Company_Spec", REPLY, CUS_QCM_Update_CUS_QCM_Other_Company_Spec);
    
}
