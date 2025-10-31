
#ifndef _SECCORE_COMMON_H
#define _SECCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>


#define  NOT_CHANGE_PASSWORD "_NOTCHANGE_PASSWORD_"


/* MESPlus SECURITY Module */

/* Login */
extern int SEC_LOGIN(char *s_msg_code,
                     TRSNode *in_node,
                     TRSNode *out_node);

extern int SEC_UPDATE_FUNCTION(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);
                
extern int SEC_UPDATE_USER(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int SEC_COPY_SECGRP(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int SEC_UPDATE_GRPFUNC_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int SEC_UPDATE_SECGRP(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int SEC_UPDATE_FAVORITES(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int SEC_UPDATE_PRIVILEGE_GROUP(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int SEC_COPY_PRIVILEGE_GROUP(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int SEC_UPDATE_PRIVILEGE_GROUP_USER(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int SEC_CHANGE_PASSWORD(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int SEC_CHANGE_PASSWORD_EXT(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int SEC_UPDATE_PRIVILEGE(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int SEC_UPDATE_USER_EXT(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int SEC_UPDATE_FLEXIBLE_HEADER(char *s_msg_code,
                                                 TRSNode *in_node,
                                               TRSNode *out_node);


extern int SEC_GET_HELPURL(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int SEC_VIEW_FAVORITES_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int SEC_VIEW_FLEXIBLE_HEADER_LIST(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_Node);

extern int SEC_VIEW_FUNCTION(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int SEC_VIEW_FUNCTION_DETAIL(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int SEC_VIEW_FUNCTION_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int SEC_VIEW_GROUP_BY_TYPE_PRIVILEGE_LIST(char *s_msg_code,
                                                 TRSNode *in_node,
                                                 TRSNode *out_node);

extern int SEC_VIEW_GRPFUNC_LIST(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int SEC_VIEW_PRIVILEGE(char *s_msg_code, 
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int SEC_VIEW_PRIVILEGE_GROUP(char *s_msg_code, 
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SEC_VIEW_PRIVILEGE_GROUP_LIST(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int SEC_VIEW_PRIVILEGE_GROUP_USER_LIST(char *s_msg_code,
                                              TRSNode *in_node,
                                              TRSNode *out_node);

extern int SEC_VIEW_PRIVILEGE_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int SEC_VIEW_SECGRP(char *s_msg_code, 
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int SEC_VIEW_SECGRP_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_Node);

extern int SEC_VIEW_USER(char *s_msg_code,
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int SEC_VIEW_USER_EXT(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int SEC_VIEW_USER_LIST(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int SEC_VIEW_CONCURRENT_USER_INFO(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);
#endif /* _SECCORE_COMMON_H */



