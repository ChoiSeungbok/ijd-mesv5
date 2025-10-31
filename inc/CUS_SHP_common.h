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
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_SHP_COMMON_H
#define _CUS_SHP_COMMON_H

#include <MESCore_common.h>
#include "WIPCore_common.h"
#include "TRSCore_defines.h"

#include "DBU_common.h"
#include "CUS_defines.h"
#include "CUS_WIP_common.h" 
#include "CUS_IFS_common.h" 


extern int CUS_SHP_CREATE_PACK_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_DELETE_PACK_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_CONFIRM_PACK_ORDER_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_CREATE_PACK_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_DELETE_PACK_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_CREATE_PACK_FINAL_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_DELETE_PACK_FINAL_BOX_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_SHIP_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_RETURN_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_VIEW_RETURN_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_VALIDATION_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_CHECK_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_ERP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_SHP_UPDATE_PACK_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif
