/*******************************************************************************

    System      : MESplus
    Module      : User Routine for BAS
    File Name   : UBAS_Update_Calendar_List.c
    Description : User Routine for BAS_Update_Calendar_List

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/04/06  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "UBAS_common.h"
#include "DBU_common.h"

int BAS_Update_Calendar_List_Before_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
    return MP_TRUE;
}

int BAS_Update_Calendar_List_After_1(TRSNode *in_node, TRSNode *out_node)
{
    /* TODO : Insert your code */
    struct MWIPCALDEF_TAG MWIPCALDEF;

    DBU_init_mwipcaldef(&MWIPCALDEF);
    TRS.copy(MWIPCALDEF.CALENDAR_ID, sizeof(MWIPCALDEF.CALENDAR_ID), in_node, "CALENDAR_ID");
    MWIPCALDEF.SYS_YEAR = TRS.get_int(in_node, "YEAR");

    DBU_update_mwipcaldef(2, &MWIPCALDEF);

    return MP_TRUE;
}
