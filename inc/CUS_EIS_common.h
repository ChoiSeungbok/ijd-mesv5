/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : sl_common.h
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

#ifndef _CUS_EIS_COMMON_H
#define _CUS_EIS_COMMON_H

#include <MESCore_common.h>
#include "RASCore_common.h"
#include "WIPCore_common.h"
#include "TRSCore_defines.h"
#include "ACTCore_common.h"

#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_defines.h" 
#include "CUS_WIP_common.h" 

extern int CUS_EIS_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int Check_LotStatus(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *in_node, TRSNode *out_node);
extern int Check_Equipment(char *s_msg_code, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *in_node, TRSNode *out_node);
extern int Equipment_End_Lot(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_BASIS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_BALL_MILL_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_EIS_SEND_PRESS_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif
