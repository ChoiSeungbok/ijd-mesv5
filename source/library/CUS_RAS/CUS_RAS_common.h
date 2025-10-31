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
    1     2020/06/22  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_RAS_COMMON_H
#define _CUS_RAS_COMMON_H

#include <MESCore_common.h>
#include "RASCore_common.h"
#include "TRSCore_defines.h"

#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_defines.h" 
#include "CUS_WIP_common.h" 


extern int CUS_RAS_TOOL_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_UPDATE_TOOL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_SPARE_MANAGEMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_RAS_CREATE_SCRAP_MOLD_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int CUS_RAS_VIEW_CUS_RAS_ASSET_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
#endif
