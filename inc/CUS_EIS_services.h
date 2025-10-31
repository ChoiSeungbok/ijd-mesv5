/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_EIS_service.h
    Description : Customer function prototype of Customer defined shared library

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

#ifndef _CUS_EIS_SERVICES_H
#define _CUS_EIS_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_EIS_add_service();
#endif

extern int CUS_EIS_Start_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Resource_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Resource_Event(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Inspection_Data(TRSNode *in_node, TRSNode *out_node);

extern int CUS_EIS_Press_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Laser_Marking_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Impact_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Round_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Cup_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Basis_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Ball_Mill_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_send_Press_End_Lot(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Furnace_Data(TRSNode *in_node, TRSNode *out_node);

extern int CUS_EIS_Collect_Ballmill_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_PlanetaryMixer_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Press400ton_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Press5000ton_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_VacuumFurnace_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_MdExtruder_Data(TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_Collect_Press5000ton_Temp_Data(TRSNode *in_node, TRSNode *out_node);

#endif
