
#ifndef _RTDCORE_COMMON_H
#define _RTDCORE_COMMON_H


#include <MESCore_common.h>
#include "RTDCore_defines.h"

#include <limits.h>


extern int RTD_GET_LOT_SIMULATION_RESULT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int RTD_GET_RESOURCE_SIMULATION_RESULT(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_COPY_DISPATCH_RULE(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_UPDATE_DISPATCHER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int RTD_UPDATE_DISPATCHER_OPER(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_UPDATE_DISPATCHER_RES(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_UPDATE_RULE_ITEMS(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_get_up_resource_count(char *s_msg_code, TRSNode *out_node, struct MWIPLOTSTS_TAG *MWIPLOTSTS, 
                              int *i_res_up_count);

extern int RTD_get_cycle_time(char *s_msg_code, TRSNode *out_node,char *s_factory, 
                              char *s_mat_id, int i_mat_ver, char *s_flow, 
                              int i_flow_seq_num, char *s_oper, int *i_cycle_time);

extern int RTD_get_less_wip_score(char *s_msg_code, TRSNode *out_node, struct MWIPLOTSTS_TAG *MWIPLOTSTS,
                           char *s_oper_count, int *i_score);

extern int RTD_get_lot_recipe(char *s_msg_code, TRSNode *out_node, struct MWIPLOTSTS_TAG *MWIPLOTSTS,
                         char *s_res_id, char *s_recipe);

/* Added by LAVERWON - 20080617 */
extern int RTD_CALCULATE_LOT_PRIORITY(char *s_msg_code,
                                      char *s_lot_id,
                                      char c_unselect_capable_only_flag);

extern int RTD_UPDATE_RULE(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_UPDATE_DISPATCH_RELATION(char *s_msg_code,TRSNode *in_node, TRSNode *out_node);

extern int RTD_GET_LOT_PRIORITY(char *s_msg_code,
                         TRSNode *out_node,
                         char *s_lot_id, 
                         char *s_res_id,
                         char *s_oper,
                         char *s_dsp_id,
                         char *s_ref_oper,
                         char c_unselect_capable_only_flag,
                         char *s_priority_score, 
                         char *c_unselect_flag,
                         char *s_rule_id,
                         char *s_dsp_reason,
                         char *s_priority_support,
                         char *c_capable_flag,
                         char *s_unselect_reason,
                         char *s_uncapable_reason,
                         struct  PDS_CMF_TBL_TAG *pds_cmf_tbl);

extern int RTD_GET_RESOURCE_PRIORITY(char *s_msg_code,
                                     TRSNode *out_node,
                                     char *s_factory,
                                     char *s_res_id,
                                     char *s_lot_id,
                                     char *s_dsp_id,
                                     char *s_priority_score, 
                                     char *c_unselect_flag,
                                     char *s_rule_id,
                                     char *s_dsp_reason,
                                     char *c_capable_flag,
                                     char *s_unselect_reason,
                                     char *s_uncapable_reason,
                                     struct  PDS_CMF_TBL_TAG *pds_cmf_tbl);


extern int RTD_INTERFACE();


extern int RTD_UPDATE_DISPATCH_RELATION(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int RTD_UPDATE_DISPATCHER_EVENT(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int RTD_UPDATE_REFERENCE_OPERATION(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int RTD_ADJUST_LOT_PRIORITY(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int RTD_RE_DISPATCH_LOT(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);
/* End Add */

extern void RTD_sort_lot_priority(int i_count);
extern void RTD_sort_lot_batch_priority(int i_count);

extern int RTD_insert_event(char *s_msg_code, TRSNode *out_node, struct MRTDEVNIFS_TAG *MRTDEVNIFS);


extern void Init_LOTPDS_LIST(struct LOTPDS_LIST_TAG *LOTPDS_LIST);

//Add by J.S. 2008.08.20
extern int RTD_Check_Config(TRSNode *in_node, TRSNode *out_node);


extern int RTD_VIEW_DISPATCH_RELATION(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int RTD_VIEW_DISPATCHED_LOT_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int RTD_VIEW_DISPATCHED_RESOURCE_LIST(char *s_msg_code,
                                             TRSNode *in_node, 
                                             TRSNode *out_node);

extern int RTD_VIEW_DISPATCHER(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int RTD_VIEW_DISPATCHER_EVENT(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int RTD_VIEW_DISPATCHER_EVENT_HISTORY(char *s_msg_code,
                                             TRSNode *in_node, 
                                             TRSNode *out_node);

extern int RTD_VIEW_DISPATCHER_EVENT_LIST(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int RTD_VIEW_DISPATCHER_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int RTD_VIEW_DSPOPER_LIST(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int RTD_VIEW_DSPRES_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int RTD_VIEW_PRE_DISPATCHED_HISTORY(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int RTD_VIEW_PRE_DISPATCHED_STATUS(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int RTD_VIEW_REFERENCE_OPERATION(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int RTD_VIEW_RESOURCE_PRISTS(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int RTD_VIEW_RULE(char *s_msg_code,
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int RTD_VIEW_RULE_ITEM(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int RTD_VIEW_RULE_ITEM_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int RTD_VIEW_RULE_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);


#endif /* _RTDCORE_COMMON_H */


