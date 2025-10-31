
#ifndef _CUS_COMMON_H
#define _CUS_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>
#include "DBC_common.h"
#include "DNMCore_defines.h"


extern int DNM_UPDATE_DIRECT_VIEW(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_DIRECT_VIEW(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_DIRECT_VIEW_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_UPDATE_HEADER_USER(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_MULTI_UPDATE_HEADER_USER(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_HEADER_USER_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_UPDATE_DIRECT_VIEW_HEADER(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_MULTI_UPDATE_DIRECT_VIEW_HEADER(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_DIRECT_VIEW_HEADER_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int DNM_UPDATE_DIRECT_VIEW_CONDITION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_MULTI_UPDATE_DIRECT_VIEW_CONDITION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_DIRECT_VIEW_CONDITION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);
extern int DNM_VIEW_DIRECT_VIEW_CONDITION_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

#endif /* _CUS_COMMON_H */



