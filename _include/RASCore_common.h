#ifndef _RASCORE_COMMON_H
#define _RASCORE_COMMON_H


#include <MESCore_common.h>

/*
** Structure Definitions
*/

struct tool_type_tag
{
    char factory[10];
    char tool_type[20];
    char tool_type_desc[200];
    char system_flag;
    char delete_flag;
    char delete_user_id[20];
    struct{
        char prompt[30];
        char format;
        int  size;
        char table_name[20];
        char setup_flag;
        char event_flag;
        char opt;
    }type_list[30];
};

/*
** Function Prototype Definitions
*/

extern int RAS_update_insert_carrier_status_history(char *s_msg_code,
                                             TRSNode *out_node,
                                             TRSNode *in_node,
                                             char *s_sys_time_t,
                                             struct MRASCRRDEF_TAG *MRASCRRDEF,
                                             struct MRASCRRHIS_TAG *MRASCRRHIS);
extern int RAS_recount_proc_lot_resource(char *s_msg_code, 
                                         TRSNode *out_node,
                                         char *s_factory, 
                                         char *s_res_id, 
                                         char *s_event_id);

extern int RAS_recount_proc_lot_resource_main(char *s_msg_code, 
                                              TRSNode *out_node, 
                                              char *s_event_id_t, 
                                              struct MRASRESDEF_TAG *MRASRESDEF);

extern int RAS_change_resource_status(char *s_msg_code, 
                               TRSNode *out_node, 
                               char *s_factory, 
                               int i_chk_seq,
                               char c_chk_flag, 
                               char *s_res_sts, 
                               char *s_chk_sts, 
                               char c_chg_flag, 
                               char *s_chg_sts, 
                               char *s_tbl_name, 
                               char *s_user_chg_sts_t);

extern int RAS_DELETE_RESOURCE_HISTORY(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_RESOURCE_EVENT(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);
extern int RAS_UPDATE_RESOURCE(char *s_msg_code,
                                TRSNode *in_node,  
                               TRSNode *out_node);
extern int RAS_UPDATE_EVENT(char *s_msg_code,
                            TRSNode *in_node,  
                             TRSNode *out_node);

extern int RAS_UPDATE_RESOURCE_EVENT(char *s_msg_code,
                                     TRSNode *in_node,  
                               TRSNode *out_node);

/* Resource Labor Setup */
extern int RAS_UPDATE_RESOURCE_LABOR(char *s_msg_code,
                                      TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_PM_SECURITY(char *s_msg_code,
                                 TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_PM_SECURITY_LIST(char *s_msg_code,
                                 TRSNode *in_node,  
                               TRSNode *out_node);
extern int RAS_UPDATE_PM_SCHEDULE(char *s_msg_code,
                                  TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_PM_SCHEDULE_LIST(char *s_msg_code,
                                  TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_SHEET(char *s_msg_code,
                           TRSNode *in_node,  
                               TRSNode *out_node);


extern int RAS_COPY_RESOURCE_GROUP(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_DELETE_SUB_RESOURCE_HISTORY(char *s_msg_code,
                                    TRSNode *in_node,  
                                    TRSNode *out_node);

extern int RAS_TROUBLE_RESOURCE(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_PORT(char *s_msg_code,
                                TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_UPDATE_RESOURCE_GROUP(char *s_msg_code,
                                TRSNode *in_node,  
                                TRSNode *out_node);

extern int RAS_UPDATE_RESOURCE_GROUP_RELATION(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);
extern int RAS_UPDATE_RESOURCE_MFO_RELATION(char *s_msg_code,
                                TRSNode *in_node,  
                                TRSNode *out_node);

extern int RAS_UPDATE_SUB_RESOURCE(char *s_msg_code,
                             TRSNode *in_node,  
                              TRSNode *out_node);

extern int RAS_UPDATE_SUB_RESOURCE_EVENT(char *s_msg_code,
                                   TRSNode *in_node,  
                               TRSNode *out_node);



#ifdef _CRR
extern int RAS_UPDATE_CARRIER(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_CHANGE_CARRIER(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_CREATE_CARRIER(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_TERMINATE_CARRIER(char *s_msg_code,
                                 TRSNode *in_node,  
                                 TRSNode *out_node);

extern int RAS_START_CARRIER(char *s_msg_code,
                                 TRSNode *in_node,  
                                 TRSNode *out_node);

extern int RAS_END_CARRIER(char *s_msg_code,
                                 TRSNode *in_node,  
                                 TRSNode *out_node);

extern int RAS_ATTACH_LOT_CARRIER(char *s_msg_code,
                                 TRSNode *in_node,  
                                 TRSNode *out_node);

extern int RAS_DETACH_LOT_CARRIER(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);

extern int RAS_ASSIGN_SUBLOT_CARRIER(char *s_msg_code,
                                TRSNode *in_node,  
                                TRSNode *out_node);

extern int RAS_CLEAN_CARRIER(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_RESERVE_CARRIER(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UNRESERVE_CARRIER(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UPDATE_CARRIER_GROUP(char *s_msg_code,
                              TRSNode *in_node,  
                              TRSNode *out_node);

extern int RAS_UPDATE_CARRIER_GROUP_RELATION(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UPDATE_CARRIER_EVENT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CARRIER_EVENT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);


extern int RAS_VIEW_CARRIER(char *s_msg_code, 
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int RAS_VIEW_CARRIER_EVENT(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int RAS_VIEW_CARRIER_EVENT_LIST(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int RAS_VIEW_CARRIER_GROUP(char *s_msg_code, 
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int RAS_VIEW_CARRIER_GROUP_LIST(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int RAS_VIEW_CARRIER_HISTORY_LIST(char *s_msg_code, 
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int RAS_VIEW_CARRIER_HISTORY_LIST_BY_LOT(char *s_msg_code, 
                                                TRSNode *in_node,
                                                TRSNode *out_node);

extern int RAS_VIEW_CARRIER_LIST(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int RAS_VIEW_CARRIER_LIST_BY_LOT_HISTORY(char *s_msg_code, 
                                                TRSNode *in_node,
                                                TRSNode *out_node);

extern int RAS_VIEW_CARRIER_LOT(char *s_msg_code, 
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_CARRIER_LOT_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_CARRIER_LOT_LIST_DETAIL(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int RAS_VIEW_CARRIER_MFO_OPTION(char *s_msg_code, 
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int RAS_VIEW_CARRIER_SUBLOT_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int RAS_VIEW_CARRIER_SUBLOT_LIST_DETAIL(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int RAS_VIEW_CARRIER_SLOT_HISTORY(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

/* Added by MHIM 2015.08.12 */
extern int RAS_ABORT_START_CARRIER(char *s_msg_code,
                               TRSNode *in_node,  
                               TRSNode *out_node);


extern int RAS_check_lot_in_carrier(char *s_msg_code, TRSNode *out_node,
                                    char *s_factory_t, char *s_lot_id_t, char *c_carrier_flag);

extern int RAS_check_carrier_vacancy(char *s_msg_code, TRSNode *out_node,
                                     char *s_crr_id_t, double d_add_qty_1, char *c_avail_flag);

extern int RAS_check_carrier_exist(char *s_msg_code, TRSNode *out_node,
                                   char c_proc_step, char *s_factory_t, char *s_crr_id_t, 
                                   char *c_carrier_flag);

extern int RAS_check_carrier_loop_by_relation(char *s_msg_code, TRSNode *out_node,
                                       char *s_factory_t, char *s_crr_id_t, 
                                       char *s_mat_id_t, int i_mat_ver, char *s_flow_t, 
                                       char *s_oper_t, char *s_res_id_t, char *s_port_id_t);

extern int RAS_check_carrier_loop_by_lot(char *s_msg_code, TRSNode *out_node,
                                  char *s_crr_id_t, char *s_lot_id_t);

extern int RAS_find_available_carrier_loop_relation(char *s_msg_code, TRSNode *out_node,
                                             char *s_factory_t, char *rel_level, char *s_mat_id_t, int *i_mat_ver, 
                                             char *s_flow_t, char *s_oper_t, char *s_res_id_t, char *s_port_id_t);

extern int RAS_check_carrier_usage_limit(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, 
                                         char c_tran_point_t,
                                         char *s_crr_id_t,
                                         int i_chg_usage_count);

extern int RAS_check_carrier_clean_limit(char *s_msg_code, TRSNode *out_node, char *s_crr_id_t);

extern int RAS_insert_carrier_slot_history(char *s_msg_code,
                                    TRSNode *out_node,
                                    TRSNode *in_node,
                                    struct MRASCRRSHS_TAG *MRASCRRSHS,
                                    char c_recount_crr_slot_hist_seq);





#endif /* _CRR */

#ifdef _TOOL
extern int RAS_UPDATE_TOOL_TYPE(char *s_msg_code,
                                TRSNode *in_node,  
                                TRSNode *out_node);

extern int RAS_UPDATE_TOOL_EVENT(char *s_msg_code,
                                TRSNode *in_node,  
                                TRSNode *out_node);

extern int RAS_UPDATE_TOOL_EVENT_RELATION(char *s_msg_code,
                                   TRSNode *in_node,  
                                   TRSNode *out_node);

extern int RAS_UPDATE_TOOL(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UPDATE_TOOL_TYPE_RELATION(char *s_msg_code,
                                         TRSNode *in_node,  
                                         TRSNode *out_node);

extern int RAS_TOOL_EVENT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_COLLECT_TOOL_DEFECT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CLEAN_TOOL_DEFECT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_DELETE_TOOL_HISTORY(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_VIEW_TOOL(char *s_msg_code,
                         TRSNode *in_node,
                         TRSNode *out_node);

extern int RAS_VIEW_TOOL_DEFECT(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_TOOL_DEFECT_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_TOOL_DEFECT_LIST_DETAIL(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int RAS_VIEW_TOOL_EVENT(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int RAS_VIEW_TOOL_EVENT_LIST(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int RAS_VIEW_TOOL_EVENT_RELATION_LIST(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int RAS_VIEW_TOOL_HISTORY(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int RAS_VIEW_TOOL_LIST(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int RAS_VIEW_TOOL_LIST_DETAIL(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_TOOL_TYPE(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int RAS_VIEW_TOOL_TYPE_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int RAS_VIEW_TOOL_TYPE_RELATION(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int RAS_VIEW_TOOL_TYPE_RELATION_LIST(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int RAS_get_tool_status_index(char *status_name);

extern int RAS_tool_event_by_relation(char *s_msg_code,
                                        char *s_res_id,
                                        char *s_event_id,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

#endif /* _TOOL */

/* Sub Resource */
extern int RAS_SUB_RESOURCE_EVENT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CHANGE_PORT_STATE(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CHANGE_TRANSFER_STATE(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CHANGE_ASSOCIATION_STATE(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CHANGE_ACCESS_MODE_STATE(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_CHANGE_RESERVATION_STATE(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UPDATE_SHEET_QUERY(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_MAKE_SHEET_RESULT(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);

extern int RAS_UPDATE_SHEET_TYPE_DEF(char *s_msg_code,
                            TRSNode *in_node,  
                            TRSNode *out_node);





extern int RAS_VIEW_EVENT(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int RAS_VIEW_EVENT_LIST(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int RAS_VIEW_LOTBYRES_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int RAS_VIEW_PM_RESOURCE_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_PM_SCHEDULE(char *s_msg_code, 
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_PM_SCHEDULE_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_PM_SEC_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_PORT(char *s_msg_code,
                         TRSNode *in_node,
                         TRSNode *out_node);

extern int RAS_VIEW_PORT_HISTORY_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int RAS_VIEW_PORT_LIST(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int RAS_VIEW_RESOURCE(char *s_msg_code, 
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_LIST_DETAIL_BYGROUP(char *s_msg_code,
                                                 TRSNode *in_node,
                                                 TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_DOWN_HISTORY(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_DOWN_HISTORY_LIST(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int RAS_VIEW_RESEVENT_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_GROUP(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_GROUP_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_HISTORY(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_LABOR_LIST(char *s_msg_code,    
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int RAS_VIEW_RESOURCE_LIST_DETAIL(char *s_msg_code, 
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int RAS_VIEW_RESLOT_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_SHEET(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int RAS_VIEW_SHEET_LIST(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int RAS_VIEW_SHEET_QUERY(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int RAS_VIEW_SHEET_QUERY_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_SHEET_RESULT(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int RAS_VIEW_SHEET_RESULT_DATA_LIST(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int RAS_VIEW_SHEET_RESULT_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int RAS_VIEW_SHEET_TYPE_DEF(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int RAS_VIEW_SUB_RESOURCE(char *s_msg_code, 
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int RAS_VIEW_SUB_RESEVENT_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int RAS_VIEW_SUB_RESOURCE_HISTORY(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int RAS_VIEW_SUB_RESOURCE_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

/* Added by ICBAE 2012.04.16 */
extern int RAS_VIEW_PORT_LIST_DETAIL(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int RAS_VIEW_SUB_RESOURCE_LIST_DETAIL(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

#endif /* _RASCORE_COMMON_H */



