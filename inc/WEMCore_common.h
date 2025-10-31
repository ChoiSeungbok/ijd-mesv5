
#ifndef _WEMCORE_COMMON_H
#define _WEMCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>

/*
** Common Function Prototype Definitions
*/
extern int WEM_exist_user_in_user_type(char *s_msg_code, 
                                       TRSNode *out_node,
                                       char *s_factory_t, 
                                       char c_user_type, 
                                       char *s_user_type_id_t, 
                                       char *s_user_id_t);

extern int WEM_check_authority(char *s_msg_code, 
                               TRSNode *out_node,
                               char *s_factory_t, 
                               char *s_proc_type_t, 
                               char *s_proc_id_t, 
                               char *s_step_id_t, 
                               char *s_user_id_t,
                               char *s_option);

extern int WEM_get_next_step(char *s_msg_code, 
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int WEM_check_value_change(char *s_msg_code, 
                                  TRSNode *in_node,
                                  TRSNode *out_node,
                                  char *c_value_change_flag);

extern void WEM_get_event_status_value(char *s_factory_t, 
                                       char *s_proc_event_id_t, 
                                       char *s_status_name_t, 
                                       char *s_status_value, 
                                       int i_status_size);

extern void WEM_bind_sql_variable(char *s_factory, 
                                  char *s_proc_event_id, 
                                  char *s_lot_id, 
                                  char *s_res_id, 
                                  char *s_mat_id, 
                                  char *s_mat_ver, 
                                  char *s_sql);
extern int WEM_get_proc_event_status_values(char *s_msg_code, 
                                            TRSNode *out_node,
                                            char *s_user_id_t,
                                            char *s_factory_t, 
                                            char *s_proc_event_id_t, 
                                            char c_include_file);

/*
** Function Prototype Definitions
*/
extern int WEM_UPDATE_WORK_PROCESS_TYPE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS_TYPE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS_TYPE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_STATUS_DEFINITION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_UPDATE_WORK_STATUS_DEFINITION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_UPDATE_PROCESS_STEP(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_PROCESS_STEP(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_PROCESS_STEP_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_STEP_ACTION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_STEP_ACTION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_UPDATE_STEP_ACTION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS_STEP_USER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_UPDATE_WORK_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_UPDATE_WORK_PROCESS_STEP_USER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_WORK_PROCESS_STEP(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_PROCESS_EVENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_EVENT_STEP_STATUS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_EVENT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_EVENT_STATUS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_EVENT_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_DELETE_EVENT_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_COPY_WORK_PROCESS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_COPY_PROCESS_STEP(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WEM_VIEW_EVENT_STATUS_DETAIL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif

