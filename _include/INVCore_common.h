/*******************************************************************************

    System      : MESplus
    Module      : INVCore
    File Name   : INVCore_common.h
    Description : external function prototype definition of INVCore Library

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/12/16  SK Jin         Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _INVCORE_COMMON_H
#define _INVCORE_COMMON_H


#include <MESCore_common.h>


extern int INV_CONSUME(char *s_msg_code,
                      TRSNode *in_node, 
                      TRSNode *out_node);

extern int INV_CONV_TO_INV(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_CONV_TO_LOT(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int INV_DELETE_INVENTORY_HISTORY(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int INV_IN_INVENTORY(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int INV_IN_INVENTORY_SERIAL(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_OUT_INVENTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_OUT_INVENTORY_SERIAL(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int INV_SCRAP(char *s_msg_code,
                      TRSNode *in_node, 
                      TRSNode *out_node);


extern int INV_SCRAP_SERIAL(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_TRANSFER_INVENTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_TRANSFER_INVENTORY_SERIAL(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int INV_UPDATE_SERIAL_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int INV_VIEW_INVENTORY_HISTORY(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int INV_VIEW_INVENTORY_INFO(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int INV_VIEW_INVENTORY_INFO_SERIAL(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);


#endif /* _INVCORE_COMMON_H */

