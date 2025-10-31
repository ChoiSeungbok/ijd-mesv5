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
    1     2020/09/21  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_BAT_COMMON_H
#define _CUS_BAT_COMMON_H

#include <MESCore_common.h>
#include "RASCore_common.h"
#include "WIPCore_common.h"
#include "TRSCore_defines.h"
#include "ACTCore_common.h"
#include "ORDCore_common.h"

#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_defines.h" 
#include "CUS_WIP_common.h" 

//extern int CUS_BAT_SEND_TEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int SET_ERP_CATALOG_TO_MATERIAL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


#endif
