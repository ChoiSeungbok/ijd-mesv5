/*******************************************************************************

    System      : MESplus
    Module      : MESCore
    File Name   : MESCore_common.h
    Description : Common header of MESplus Server

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/12/16  SK Jin         Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESCORE_COMMON_H
#define _MESCORE_COMMON_H

#include <LOGCore_common.h>
#include <LOGCore_defines.h>

#include <DBC_common.h>

#include "MESCore_defines.h"
#include "MESCore_service.h"
#include "MESCore_global_variables.h"
#include <TRSCore_common.h>
#include <SLPCore_common.h>
#include <COMCore_memory.h>

//Add by J.S. 2011.12.27 for MAX_INT, MIN_INT....
#include <limits.h>

/*
**  Defines
*/
#if defined(WIN32) || defined(WIN64)

#elif defined(_HPUX_SOURCE)

#define TRUE                                   (1)
#define FALSE                                  (0)

#elif defined(__digital__) || defined(_AIX)

#endif

/*
**  Function Prototypes
*/

extern void COM_log_write( char c_log_type, 
                           char c_log_error_type, 
                           char c_log_category);

extern void COM_long_log_write( char c_log_type, 
                                char c_log_error_type, 
                                char c_log_category,
                                char *s_header,
                                char *s_title,
                                char *s_log_null_string);

extern void COM_log_add_field_msg(TRSNode *node);

extern void COM_out_msg_log_write(char *s_msg_code, 
                                  char *s_func_name, 
                                  TRSNode *node);

extern int COM_get_message(char c_lang, 
                           char *s_msg_code, 
                           char *s_msg);

extern int COM_set_message(TRSNode *node, 
                           char *s_msg_code, 
                           char c_msg_category, 
                           char c_lang );

extern int COM_set_result(TRSNode *node, 
                          char c_status, 
                          char *s_msg_code, 
                          char c_msg_category, 
                          char c_lang );

extern int COM_set_field_db_msg(TRSNode *dest, 
                                TRSNode *src);

extern int COM_check_gcm_table(char *s_msg_code , 
                               TRSNode *out_node, 
                               char *s_table_name, 
                               char *s_factory);

extern int COM_check_gcm_data(char *s_msg_code, 
                              TRSNode *out_node, 
                              char *s_table_name, 
                              char *s_factory, 
                              char *s_code_value, 
                              int i_size);

//Add by J.S. 2008.12.22
extern int COM_check_gcm_data_area(char *s_msg_code, 
                              TRSNode *out_node, 
                              char *s_table_name, 
                              char *s_factory, 
                              char *s_code_value, 
                              int i_size, 
                              char *s_area, 
                              int i_area_size);


extern int COM_check_gcm_key(char *s_msg_code, 
                             TRSNode *out_node, 
                             char *s_table_name, 
                             char *s_factory, 
                             struct key_list *s_key_list);

//Add by J.S. 2008.12.22
extern int COM_check_gcm_key_area(char *s_msg_code, 
                             TRSNode *out_node, 
                             char *s_table_name, 
                             char *s_factory, 
                             struct key_list *s_key_list,
                             char *s_area);

extern int COM_check_gcm_sql_data(char *s_msg_code, 
                                  TRSNode *out_node, 
                                  char *s_table_name, 
                                  char *s_factory,
                                  char *s_code_value, 
                                  struct argu_list *s_argu_list);

extern int COM_check_grp(char *s_msg_code, 
                         TRSNode *out_node, 
                         char *s_item_name, 
                         char *s_factory, 
                         struct check_list *s_check_list);

extern int COM_check_cmf(char *s_msg_code, 
                         TRSNode *out_node,
                         char *s_item_name, 
                         char *s_factory, 
                         struct check_list *s_check_list);

extern int COM_check_mfo(char *s_msg_code, 
                         TRSNode *out_node,
                         char c_proc_step, 
                         char c_opt_level, 
                         char *s_factory,
                         char *s_mat_id,
                         int i_mat_ver,
                         char *s_flow, 
                         char *s_oper);

extern int COM_check_mfo_return_first_flow(char *s_msg_code, 
                                           TRSNode *out_node,
                                           char c_proc_step, 
                                           char c_opt_level, 
                                           char *s_factory,
                                           char *s_mat_id, 
                                           int i_mat_ver, 
                                           char *s_flow, 
                                           char *s_oper, 
                                           char *s_first_flow);

extern int COM_check_mf(char *s_msg_code, 
                        TRSNode *out_node,
                        char c_proc_step, 
                        char c_opt_level, 
                        char *s_factory,
                        char *s_mat_id, 
                        int i_mat_ver,
                        char *s_flow);

extern int COM_check_resource_mfo_relation(char *s_msg_code, 
                                           TRSNode *out_node,
                                           char c_proc_step, 
                                           char *s_factory,
                                           char *s_mat_id,
                                           int i_mat_ver,
                                           char *s_flow,
                                           char *s_oper, 
                                           char *s_res_id);

extern int COM_next_fo(char *s_msg_code, 
                       TRSNode *out_node,
                       char *s_factory,
                       char *s_mat_id,
                       int i_mat_ver,
                       char *s_flow, 
                       int *i_flow_seq_num,
                       char *s_oper);

extern int COM_next_fo_by_lot(char *s_msg_code, 
                              TRSNode *out_node,
                              struct MWIPLOTSTS_TAG *MWIPLOTSTS, int b_is_view_only);

extern int COM_next_fo_by_sublot(char *s_msg_code, 
                              TRSNode *out_node,
                              struct MWIPSLTSTS_TAG *MWIPSLTSTS, int b_is_view_only);

extern int COM_get_cycle_time(char *s_msg_code, 
                              TRSNode *out_node, 
                              char *s_factory, 
                              char *s_mat_id,
                              int i_mat_ver,
                              char *s_flow,
                              int i_flow_seq,
                              char *s_oper, 
                              double *d_queue_time, 
                              double *d_proc_time, 
                              double *d_hpu_proc_time);


extern int COM_get_proc_time(char *s_msg_code, 
                             TRSNode *out_node, 
                             char *s_factory, 
                             char *s_mat_id, 
                             int i_mat_ver, 
                             char *s_flow, 
                             int i_flow_seq_num, 
                             char *s_oper, 
                             double d_qty, 
                             double *d_sum_queue_time, 
                             double *d_sum_proc_time, 
                             double *d_sum_proc_queue_time);

extern int COM_get_global_option_value(char *s_factory, 
                                       char *s_option, 
                                       char *s_value_1, 
                                       char *s_value_2, 
                                       char *s_value_3, 
                                       char *s_value_4, 
                                       char *s_value_5);

extern char COM_get_global_option_value2(char *s_factory, char *s_option);

extern int COM_get_global_option_value3(char *s_factory, char *s_option, char *s_value);

extern int COM_compare_global_option(char *s_factory, 
                                     char *s_option, 
                                     char c_value);

extern int COM_is_nstd_flow(char *s_msg_code, 
                            TRSNode *out_node,
                            char *s_factory, 
                            char *s_mat_id,
                            int i_mat_ver,
                            char *s_flow);

extern int COM_check_rework_mfo(char *s_msg_code, 
                                TRSNode *out_node,
                                char *s_factory, 
                                char *s_mat_id, 
                                int i_mat_ver,
                                char *s_flow, 
                                char *s_oper,
                                char *s_rework_code, 
                                char *s_to_flow,
                                int i_to_flow_seq,
                                char *s_to_oper);

extern int COM_check_repair_oper(char *s_msg_code, 
                                 TRSNode *out_node,
                                 char *s_factory, 
                                 char *s_oper, 
                                 char *s_to_oper);

extern int COM_check_privilege(char *s_msg_code, 
                               TRSNode *out_node,
                               char c_proc_step, 
                               char *s_factory, 
                               char *s_prv_type, 
                               char *s_prv_item1, 
                               int i_size_prv_item1,
                               char *s_prv_item2, 
                               int i_size_prv_item2,
                               char *s_prv_item3, 
                               int i_size_prv_item3, 
                               char *s_user_id);

extern void COM_get_user_desc(char *s_factory, 
                              char *s_user, 
                              char *s_desc);

extern int COM_check_unit_next_oper(char *s_msg_code, 
                                 TRSNode *out_node,
                                 char *s_factory, 
                                 char *s_flow, 
                                 char *s_oper, 
                                 char *c_change_flag);

extern int COM_check_unit_diff_oper(char *s_msg_code, 
                                      TRSNode *out_node,
                                      char *s_factory, 
                                      char *s_oper, 
                                      char *s_to_factory,
                                      char *s_to_oper, 
                                      char *c_change_flag);

extern void COM_fill_check_list(struct check_list *chkl, 
                                TRSNode *node, 
                                int i_value_count, 
                                char *s_name_prefix);

extern int COM_check_tran_resource_mfo_relation(char *s_msg_code, 
                                                TRSNode *out_node,
                                                char *s_factory,
                                                char *s_mat_id,
                                                int i_mat_ver,
                                                char *s_flow,
                                                char *s_oper, 
                                                char *s_res_id);
/* Added by Simon Kim 2010.12.30 */
extern char COM_check_tran_step_mfo_relation(char *s_msg_code, 
                                                TRSNode *out_node,
                                                char *s_factory,
                                                char *s_mat_id,
                                                int i_mat_ver,
                                                char *s_flow,
                                                char *s_oper, 
                                                char *s_step);

extern int COM_check_backtime(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, char *s_last_tran_time);

extern int COM_check_resource_port_relation(char *s_msg_code, TRSNode *out_node,
                                     char *s_factory, char *s_res_id, char *s_subres_id, char *s_port_id);

extern int COM_generate_multi_tran_key(char *s_multi_tr_key);

extern void COM_init_mfo_option_tag(struct mfo_option_in_tag *opt_in,
                             struct mfo_option_out_tag *opt_out);

extern int COM_get_mfo_option(char *s_msg_code, TRSNode *out_node,
                       struct mfo_option_in_tag *opt_in,
                       struct mfo_option_out_tag *opt_out);

extern int COM_check_node_length(TRSNode *node);

extern int COM_check_value(char *s_msg_code, TRSNode *in_node, TRSNode *out_node,
                           char *s_member_name, char c_mandatory, char c_check_from_table, 
                           char *s_table_name, char *s_column_name, char *s_where_sql);

extern int COM_service_validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, char c_proc_step, char *s_available_proc_step);

extern void COM_add_alarm_to_queue(struct ALARM_MSG_TAG *ALARM);

extern void COM_add_rtd_data_to_queue(struct RTD_LOT_DATA_TAG *LOT_DATA);

extern void COM_print_unfreed_mem_status(char *s_service_name);

extern int COM_check_use_mfo_id(char *s_msg_code, TRSNode *out_node, char c_case, 
                                char *s_factory_t, char *s_id_t, int i_size_id, int i_ver);

extern int COM_check_rework_stop_oper(char *s_msg_code, TRSNode *out_node,
                               char *s_factory_t, char *s_rwk_flow_t, char *s_rwk_oper_t, char *s_rwk_stop_oper_t);

extern int COM_get_current_shift(char *s_msg_code, TRSNode *out_node, char *s_factory_t, char *c_shift);
extern int COM_get_attached_file(char *s_msg_code, TRSNode *out_node, char *s_file_dir_t, char *s_file_name_t, char *s_put_member_name, char c_add_fieldmsg);
extern int COM_remove_file_path(char *s_msg_code, TRSNode *out_node, char *s_file_path_t);
extern int COM_remove_file(char *s_file_path_t, char *s_file_name_t);
extern int COM_save_attached_file(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, char *s_file_dir_t, char *s_file_name_t, char *s_get_member_name);

//Add by J.S. 2011.10.20 for Collect service infomation
extern int COM_collect_service_performance(TRSNode *in_node, TRSNode *out_node, char c_finish_flag, double  d_tran_time);

extern int COM_get_due_time(char *s_msg_code, TRSNode *out_node, char *s_factory_t, char *s_source_time_t, double d_sum_proc_queue_time, char c_cycle_time_unit, char *s_due_time);
extern int COM_is_allow_duplicate_flow(char *s_factory_t);
extern void COM_clear_allow_duplicate_flow_flag();

#endif /* _MESCORE_COMMON_H */

