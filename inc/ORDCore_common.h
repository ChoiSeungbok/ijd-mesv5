
#ifndef _ORDCORE_COMMON_H
#define _ORDCORE_COMMON_H


#include <MESCore_common.h>


extern int ORD_CREATE_LOT(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int ORD_UPDATE_ATTACH_ORDER_LOT(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int ORD_UPDATE_ORDER(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int ORD_UPDATE_PLAN(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int ORD_UPDATE_PLANNEDLOT(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int ORD_UPDATE_WORKORDER(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);


extern int ORD_VIEW_ATTACH_LOT_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int ORD_VIEW_ORDER(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int ORD_VIEW_ORDER_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int ORD_VIEW_ORDER_LIST_DETAIL(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int ORD_VIEW_PLAN(char *s_msg_code,
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int ORD_VIEW_PLAN_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int ORD_VIEW_PLAN_LIST_DETAIL(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int ORD_VIEW_PLANNEDLOT(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int ORD_VIEW_PLANNEDLOT_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int ORD_VIEW_PLANNEDLOT_LIST_DETAIL(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int ORD_VIEW_WORKORDER_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);


#endif /* _ORDCORE_COMMON_H */

