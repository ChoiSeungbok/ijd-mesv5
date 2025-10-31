#ifndef _QCMCORE_COMMON_H
#define _QCMCORE_COMMON_H

/*
** MESplus include files
*/
#include <MESCore_common.h>


/*
** Function Prototype Definitions
*/
 

extern int QCM_APPROVAL_AND_RELEASE_TO_VERSION(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int QCM_COPY_INSPECTION_VERSION(char *s_msg_code, 
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int QCM_UPDATE_INSPECTION_ITEM(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_UPDATE_INSPECTION_SET(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_UPDATE_INSPECTION_VERSION(char *s_msg_code, 
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int QCM_UPDATE_SAMPLING_PROCEDURE(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node); 

extern int QCM_UPDATE_INSPECTION_MATERIAL(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node); 

extern int QCM_FIND_INSPECTION_VERSION(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int QCM_CREATE_BATCH(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node); 

extern int QCM_RESULT_RECORDING(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_RESULT_RECORDING_INDIVIDUAL(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_FINAL_DECISION(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_UPDATE_ATTACH_INSP_ITEM(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int QCM_MERGE_BATCH(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int QCM_REQUEST_REINSPECTION(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);



extern int QCM_VIEW_ATTACH_INSP_ITEM(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int QCM_VIEW_ATTACH_INSP_ITEM_LIST (char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int QCM_VIEW_ATTACH_INSP_ITEM_LIST_DETAIL(char *s_msg_code,
                                                 TRSNode *in_node, 
                                                 TRSNode *out_node);

extern int QCM_VIEW_BATCH_INFO(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int QCM_VIEW_BATCH_ITEM_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_HISTORY(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_ITEM(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_ITEM_LIST(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_MATERIAL(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_MATERIAL_LIST(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_SET(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_SET_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_VERSION(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int QCM_VIEW_INSPECTION_VERSION_LIST(char *s_msg_code,
                                            TRSNode *in_node, 
                                            TRSNode *out_node);

extern int QCM_VIEW_ITEM_INSPECTION_HISTORY(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int QCM_VIEW_QC_BATCH_HISTORY(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int QCM_VIEW_QC_BATCH_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int QCM_VIEW_SAMPLING_PROCEDURE(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int QCM_VIEW_SAMPLING_PROCEDURE_LIST(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int QCM_VIEW_DEFECT_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);


#endif /* _QCMCORE_COMMON_H */

