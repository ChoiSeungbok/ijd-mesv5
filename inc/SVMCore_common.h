
#ifndef _SVMCORE_COMMON_H
#define _SVMCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>

/*
** Function Prototype Definitions
*/

extern int SVM_UPDATE_MEMBER(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int SVM_UPDATE_SERVICE(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int SVM_UPDATE_SERVICE_MEMBER_LIST(char *s_msg_code,
                                          TRSNode *in_node,                                     
                                          TRSNode *out_node);

extern int SVM_UPDATE_SERVICE_USER_ROUTINE_LIST(char *s_msg_code,
                                                TRSNode *in_node, 
                                                TRSNode *out_node);

extern int SVM_UPDATE_ACTIVE_FUNCTION_VERSION(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int SVM_VIEW_ACTIVE_FUNCTION_VERSION(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int SVM_VIEW_MEMBER(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int SVM_VIEW_MEMBER_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int SVM_VIEW_MODULE_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int SVM_VIEW_SERVICE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);


extern int SVM_VIEW_SERVICE_LIST(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int SVM_VIEW_SERVICE_MEMBER_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int SVM_VIEW_SERVICE_USER_ROUTINE_LIST(char *s_msg_code,
                                              TRSNode *in_node, 
                                              TRSNode *out_node);

extern int SVM_VIEW_SERVICE_PERFORMANCE_INFO_LIST(char *s_msg_code,
                                                  TRSNode *in_node,
                                                  TRSNode *out_node);

extern int SVM_VIEW_SERVICE_ERROR_LOG_LIST(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int SVM_VIEW_SERVICE_ERROR_LOG(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int SVM_VIEW_SERVICE_CONSUME_TIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif

