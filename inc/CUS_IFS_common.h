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
    1     2020/09/15  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_IFS_COMMON_H
#define _CUS_IFS_COMMON_H

#include <MESCore_common.h>
#include "TRSCore_defines.h"

#include "DBU_common.h"
#include "CUS_defines.h"


extern int CUS_IFS_PO_RCV_HEADER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_RCV_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_RCV_TXN_LOTS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_CONSIGN_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_INV_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_INV_TXN_LOTS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_MOVE_TRX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_COMPLETION_TRX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_COMP_ISSUE_TRX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_TXN_LOTS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_SHIP_HEADERS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_SHIP_LINES(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_SHIP_LINE_LOTS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_RMA_HEADERS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_RMA_TXNS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_RMA_TXN_LOTS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_OM_PROMISE_DATE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_IFS_PO_REQUESTS_RECEIPTS(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

#endif
