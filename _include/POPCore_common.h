#ifndef _POPCORE_COMMON_H
#define _POPCORE_COMMON_H


#include <MESCore_common.h>


extern int POP_COPY_LABEL(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);


extern int POP_UPDATE_IMAGE(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);


extern int POP_UPDATE_LABEL(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);


extern int POP_UPDATE_LABEL_DESIGN(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);


extern int POP_UPDATE_LOTLABEL_PRINT_HISTORY(char *s_msg_code,
                                              TRSNode *in_node, 
                                              TRSNode *out_node);


extern int POP_UPDATE_MATERIALLABEL(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int POP_GEN_LABEL(char *s_msg_code,
                  TRSNode *in_node, 
                  TRSNode *out_node);


extern int POP_VIEW_IMAGE(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int POP_VIEW_IMAGE_LIST(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int POP_VIEW_LABEL(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int POP_VIEW_LABEL_DESIGN(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int POP_VIEW_LABEL_LIST(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int POP_VIEW_PRINTINFO(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);


#endif /* _POPCORE_COMMON_H */


