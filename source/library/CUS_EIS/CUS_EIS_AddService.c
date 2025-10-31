/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_EIS_AddService.c
    Description : Common function of user defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/09/10  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include <MESCore_service.h>
#include "CUS_EIS_services.h"

//Use static library
void CUS_EIS_add_service()
{
    COM_add_service("CUS_EIS", "CUS_EIS_Start_Lot", REPLY, CUS_EIS_Start_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_End_Lot", REPLY, CUS_EIS_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Collect_Resource_Data", REPLY, CUS_EIS_Collect_Resource_Data);
    COM_add_service("CUS_EIS", "CUS_EIS_Collect_Resource_Event", REPLY, CUS_EIS_Collect_Resource_Event);
    COM_add_service("CUS_EIS", "CUS_EIS_Collect_Inspection_Data", REPLY, CUS_EIS_Collect_Inspection_Data);

    COM_add_service("CUS_EIS", "CUS_EIS_Press_End_Lot", REPLY, CUS_EIS_Press_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Laser_Marking_End_Lot", REPLY, CUS_EIS_Laser_Marking_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Impact_End_Lot", REPLY, CUS_EIS_Impact_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Round_End_Lot", REPLY, CUS_EIS_Round_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Cup_End_Lot", REPLY, CUS_EIS_Cup_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Basis_Lot", REPLY, CUS_EIS_Basis_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_Ball_Mill_End_Lot", REPLY, CUS_EIS_Ball_Mill_End_Lot);
    COM_add_service("CUS_EIS", "CUS_EIS_send_Press_End_Lot", REPLY, CUS_EIS_send_Press_End_Lot);   
    COM_add_service("CUS_EIS", "CUS_EIS_Collect_Furnace_Data", REPLY, CUS_EIS_Collect_Furnace_Data);

	COM_add_service("CUS_EIS", "CUS_EIS_Collect_Ballmill_Data", REPLY, CUS_EIS_Collect_Ballmill_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_PlanetaryMixer_Data", REPLY, CUS_EIS_Collect_PlanetaryMixer_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_Press400ton_Data", REPLY, CUS_EIS_Collect_Press400ton_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_Press5000ton_Data", REPLY, CUS_EIS_Collect_Press5000ton_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_VacuumFurnace_Data", REPLY, CUS_EIS_Collect_VacuumFurnace_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_MdExtruder_Data", REPLY, CUS_EIS_Collect_MdExtruder_Data);
	COM_add_service("CUS_EIS", "CUS_EIS_Collect_Press5000ton_Temp_Data", REPLY, CUS_EIS_Collect_Press5000ton_Temp_Data);
}
