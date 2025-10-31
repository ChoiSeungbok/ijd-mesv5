#ifndef _RCPCORE_COMMON_H
#define _RCPCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>


extern int RCP_APPROVAL_RELEASE_RECIPE_VERSION(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int RCP_COPY_RECIPE_VERSION(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);
extern int RCP_UPDATE_LOT_RECIPE(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int RCP_UPDATE_MFO_RECIPE_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int RCP_UPDATE_PARA_VERSION(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int RCP_UPDATE_RECIPE(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int RCP_UPDATE_RECIPE_VERSION(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RCP_UPDATE_SUBLOT_RECIPE(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);


extern int RCP_VIEW_LOT_RECIPE(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int RCP_VIEW_LOT_RECIPE_HISTORY(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int RCP_VIEW_MFO_RECIPE_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int RCP_VIEW_PARA_VERSION_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int RCP_VIEW_RECIPE(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int RCP_VIEW_RECIPE_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int RCP_VIEW_RECIPE_VERSION(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int RCP_VIEW_RECIPE_VERSION_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int RCP_VIEW_SUBLOT_RECIPE(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int RCP_VIEW_SUBLOT_RECIPE_HISTORY(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);


#endif /* _RCPCORE_COMMON_H */



