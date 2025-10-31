/*******************************************************************************

    System      : MESplus
    Module      : FMBCore
    File Name   : FMBCore_common.h
    Description : external function prototype definition of FMBCore Library

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

#ifndef _FMBCORE_COMMON_H
#define _FMBCORE_COMMON_H

#include <MESCore_common.h>


extern int FMB_COPY_UDR_GROUP(char *s_msg_code,
                             TRSNode *in_node,  
                             TRSNode *out_node);

extern int FMB_EXIST_CONTROL(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_MOVING_BY_FORCE(char *s_msg_code,
                             TRSNode *in_node,  
                             TRSNode *out_node);

extern int FMB_RESOURCE_PRIORITY(char *s_msg_code,
                          TRSNode *in_node,  
                          TRSNode *out_node);

extern int FMB_UDR_PRIORITY(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_ENVIRONMENT(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_FMB_GROUP(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_LAYOUT(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_RESLOC_LIST(char *s_msg_code,
                             TRSNode *in_node,  
                             TRSNode *out_node);

extern int FMB_UPDATE_EVENT_COLOR(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_RESOURCE_IMAGE(char *s_msg_code,
                           TRSNode *in_node,  
                           TRSNode *out_node);

extern int FMB_UPDATE_RESOURCE_LOCATION(char *s_msg_code,
                                      TRSNode *in_node,  
                                      TRSNode *out_node);

extern int FMB_UPDATE_UDR_GROUP(char *s_msg_code,
                              TRSNode *in_node,  
                              TRSNode *out_node);

extern int FMB_UPDATE_UDR_RESLOC(char *s_msg_code,
                              TRSNode *in_node,  
                              TRSNode *out_node);

extern int FMB_UPDATE_UDRLOC_LIST(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);


extern int FMB_VIEW_ENVIRONMENT(char *s_msg_code, 
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int FMB_VIEW_ENVIRONMENT_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int FMB_VIEW_FMB_GROUP_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int FMB_VIEW_LAYOUT(char *s_msg_code, 
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int FMB_VIEW_LAYOUT_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int FMB_VIEW_PORT(char *s_msg_code, 
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int FMB_VIEW_PORT_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int FMB_VIEW_PORT_LIST_DETAIL(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int FMB_VIEW_RESDETAIL_LIST(char *s_msg_code, 
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int FMB_VIEW_RESOURCE(char *s_msg_code, 
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int FMB_VIEW_EVENT_COLOR(char *s_msg_code, 
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int FMB_VIEW_EVENT_COLOR_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int FMB_VIEW_RESOURCE_IMAGE_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int FMB_VIEW_RESOURCE_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int FMB_VIEW_RESOURCE_LIST_DETAIL(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int FMB_VIEW_SUB_RESOURCE(char *s_msg_code, 
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int FMB_VIEW_SUB_RESOURCE_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int FMB_VIEW_SUB_RESOURCE_LIST_DETAIL(char *s_msg_code,
                                             TRSNode *in_node, 
                                             TRSNode *out_node);

extern int FMB_VIEW_TOOL(char *s_msg_code, 
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int FMB_VIEW_TOOL_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int FMB_VIEW_TOOL_LIST_DETAIL(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int FMB_VIEW_UDR_GROUP(char *s_msg_code, 
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int FMB_VIEW_UDR_GROUP_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int FMB_VIEW_UDR_PORT(char *s_msg_code, 
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int FMB_VIEW_UDR_PORT_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int FMB_VIEW_UDR_PORT_LIST_DETAIL(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int FMB_VIEW_UDR_RESOURCE(char *s_msg_code, 
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int FMB_VIEW_UDR_RESOURCE_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int FMB_VIEW_UDR_RESOURCE_LIST_DETAIL(char *s_msg_code,
                                             TRSNode *in_node, 
                                             TRSNode *out_node);

extern int FMB_VIEW_UDR_SUB_RESOURCE(char *s_msg_code, 
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int FMB_VIEW_UDR_SUB_RESOURCE_LIST(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int FMB_VIEW_UDR_SUB_RESOURCE_LIST_DETAIL(char *s_msg_code,
                                                 TRSNode *in_node, 
                                                 TRSNode *out_node);

extern int FMB_VIEW_UDR_TOOL(char *s_msg_code, 
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int FMB_VIEW_UDR_TOOL_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int FMB_VIEW_UDR_TOOL_LIST_DETAIL(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);


#endif /* _FMBCORE_COMMON_H */

