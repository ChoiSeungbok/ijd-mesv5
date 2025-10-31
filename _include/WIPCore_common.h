
#ifndef _WIPCORE_COMMON_H
#define _WIPCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>

/*
** Constant Definitions
*/



/*
** Function Prototype Definitions
*/

/****************************************************************************************************************/
/*    WIP Common Function Prototypes                                                                            */
/****************************************************************************************************************/

extern int WIP_update_insert_lot_status_history(char *s_msg_code,
                                                TRSNode *out_node,
                                                TRSNode *in_node,
                                                char *s_sys_time,
                                                struct MWIPLOTSTS_TAG *MWIPLOTSTS_OLD,
                                                struct MWIPLOTSTS_TAG *MWIPLOTSTS,
                                                struct MWIPLOTHIS_TAG *MWIPLOTHIS);

//2010.12.23 Added by Simon Kim                                                 
extern int WIP_update_insert_step_status_history(char *s_msg_code,
                                                TRSNode *out_node,
                                                TRSNode *in_node,
                                                char *s_sys_time,
                                                struct MWIPSTPSTS_TAG *MWIPSTPSTS_OLD,
                                                struct MWIPSTPSTS_TAG *MWIPSTPSTS,
                                                struct MWIPSTPHIS_TAG *MWIPSTPHIS);


extern int WIP_lot_tran_validation(char *s_msg_code, 
                                   TRSNode *out_node,
                                   TRSNode *in_node,
                                   struct MWIPLOTSTS_TAG *MWIPLOTSTS, 
                                   struct MWIPFACDEF_TAG *MWIPFACDEF,
                                   struct MWIPMATDEF_TAG *MWIPMATDEF,
                                   struct MWIPFLWDEF_TAG *MWIPFLWDEF,
                                   struct MWIPOPRDEF_TAG *MWIPOPRDEF);

extern int WIP_lot_tran_validation_except_flow(char *s_msg_code, 
                                               TRSNode *out_node,
                                               TRSNode *in_node,
                                               struct MWIPLOTSTS_TAG *MWIPLOTSTS, 
                                               struct MWIPFACDEF_TAG *MWIPFACDEF,
                                               struct MWIPMATDEF_TAG *MWIPMATDEF,
                                               struct MWIPOPRDEF_TAG *MWIPOPRDEF);




/* Sublot */
extern int WIP_sublot_tran_validation(char *s_msg_code, 
                                      TRSNode *out_node,
                                      TRSNode *in_node,
                                      struct MWIPSLTSTS_TAG *MWIPSLTSTS, 
                                      struct MWIPOPRDEF_TAG *MWIPOPRDEF);

extern int WIP_sublot_tran_validation_except_flow(char *s_msg_code, 
                                                  TRSNode *out_node,
                                                  TRSNode *in_node,
                                                  struct MWIPSLTSTS_TAG *MWIPSLTSTS, 
                                                  struct MWIPOPRDEF_TAG *MWIPOPRDEF);
                                        
extern int WIP_sublot_tran_validation_except_delete(char *s_msg_code, 
                                             TRSNode *out_node,
                                             TRSNode *in_node,
                                             struct MWIPSLTSTS_TAG *MWIPSLTSTS,
                                             struct MWIPOPRDEF_TAG *MWIPOPRDEF);

extern int WIP_update_insert_sublot_status_history(char *s_msg_code,
                                            TRSNode *out_node,
                                            TRSNode *in_node,
                                            char *s_sys_time,
                                            char *s_tran_time,
                                            int i_lot_hist_seq,
                                            struct MWIPSLTSTS_TAG *MWIPSLTSTS_OLD,
                                            struct MWIPSLTSTS_TAG *MWIPSLTSTS,
                                            struct MWIPSLTHIS_TAG *MWIPSLTHIS);

extern int WIP_update_sublot_status_history(char *s_msg_code,
                                     TRSNode *out_node,
                                     TRSNode *in_node,
                                     char *s_tran_time,
                                     struct MWIPSLTSTS_TAG *MWIPSLTSTS_OLD,
                                     struct MWIPSLTSTS_TAG *MWIPSLTSTS,
                                     struct MWIPSLTHIS_TAG *MWIPSLTHIS);

extern int WIP_process_sublot(char *s_msg_code,
                              TRSNode *out_node,
                              TRSNode *in_node,
                              char *s_factory,
                              char *s_oper,
                              char *s_sublot_id);

extern int WIP_sublot_tracking_option(char *s_msg_code, 
                                      TRSNode *out_node,
                                      char *s_factory, 
                                      char *s_mat_id,
                                      int i_mat_ver,
                                      char *s_flow, 
                                      char *s_oper,
                                      char *c_tracking_flag);

extern int WIP_sublot_tracking_option_by_lot(char *s_msg_code, 
                                             TRSNode *out_node,
                                             char *s_lot_id, 
                                             char *c_tracking_flag);

extern int WIP_check_lot_sublot_unit2_qty(char *s_msg_code, 
                                          TRSNode *out_node, 
                                          char *s_lot_id);

extern int WIP_get_next_fo_by_to_info(char *s_msg_code, TRSNode *out_node,
                                      char *s_factory, 
                                      char *s_mat_id, int i_mat_ver, 
                                      char *s_flow, int i_flow_seq_num, char *s_oper, 
                                      char *s_to_flow, int *i_to_flow_seq_num, char *s_to_oper);

extern int WIP_find_first_last_flow(char *s_msg_code,
                             TRSNode *out_node,
                             char *s_factory, 
                             char *s_material,
                             int i_material_ver);

extern int WIP_find_first_last_oper(char *s_msg_code, 
                             TRSNode *out_node,
                             char *s_factory, 
                             char *s_flow);

extern int WIP_get_lot_ext_info();
extern int WIP_get_ext_loss_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_loss_table);
extern int WIP_get_ext_bonus_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_bonus_table);
extern int WIP_get_ext_lot_defect_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_defect_table);
//extern int WIP_get_ext_rework_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_rework_table);
//extern int WIP_get_ext_hold_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_hold_table);
//extern int WIP_get_ext_release_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_release_table);
//extern int WIP_get_ext_terminate_table(char *s_msg_code, TRSNode *out_node, char *s_lot_id, char *s_terminate_table);

extern int WIP_check_lot_in_batch(char *s_factory,
                                  char *s_lot_id);

extern int WIP_check_sublot_in_batch(char *s_factory,
                                     char *s_sublot_id);

#ifdef _RCP
extern int WIP_delete_lot_recipe(char *s_msg_code,
                          TRSNode *out_node,
                          char c_proc_step,
                          char *s_lot_id);
extern int WIP_dllh_delete_recipe(char *s_msg_code,
                          TRSNode *out_node,
                          char c_proc_step,
                          char *s_lot_id,
                          int dllh_seq);
#endif /* _RCP */

extern int WIP_Delete_Inventory_History_Sub(char *s_msg_code,
                                            TRSNode *out_node, 
                                            char *s_factory, 
                                            char *s_mat_id, 
                                            int i_mat_ver,
                                            char *s_oper,
                                            int i_hist_seq, 
                                            char *s_user_id, 
                                            char *s_comment,
                                            char *s_trans_code, 
                                            char *s_trans_time, 
                                            char *s_sys_time);

extern int WIP_fill_detail_message(TRSNode *out_node,
                             struct MWIPLOTSTS_TAG *MWIPLOTSTS,
                             struct MWIPLOTSTS_TAG *MWIPLOTSTS_OLD);

extern int User_Routine_generate_sublot_ID(char *s_msg_code, TRSNode *out_node, 
                                           char *s_lot_id,
                                              int i_slot_no, 
                                           char *s_sublot_id);

extern int WIP_delete_lot_batch(char *s_msg_code, TRSNode *out_node, char *s_factory, char *s_lot_id);

extern int WIP_delete_sublot_batch(char *s_msg_code, TRSNode *out_node, char *s_factory, char *s_sublot_id);

extern int WIP_process_sublot_tracking(char *s_msg_code,
                                       TRSNode *out_node,
                                       TRSNode *in_node,
                                       char *s_factory,
                                       char *s_lot_id,
                                       char *s_oper,
                                       char *s_crr_id,
                                       char c_empty_carrier_process_flag,
                                       char c_sublot_grade);

extern int WIP_generate_sublot(char *s_msg_code, 
                        TRSNode *out_node, 
                        TRSNode *in_node, 
                        char *s_lot_id, 
                        char *s_crr_id, 
                        char c_grade);

extern int WIP_no_tracking_sublot_by_lot(char *s_msg_code, 
                                         TRSNode *out_node, 
                                         TRSNode *in_node, 
                                         char *s_lot_id);

extern int WIP_carrier_attach_only_crrlot_qty(char *s_msg_code,
                                       TRSNode *out_node,
                                       TRSNode *in_node,
                                       char *s_lot_id,
                                       char *s_crr_id,
                                       double d_qty_1,
                                       double d_qty_2,
                                       double d_qty_3);

extern int WIP_carrier_detach_only_crrlot_qty(char *s_msg_code,
                                       TRSNode *out_node,
                                       TRSNode *in_node,
                                       char *s_lot_id,
                                       char *s_crr_id,
                                       double d_qty_1,
                                       double d_qty_2,
                                       double d_qty_3);

extern int WIP_update_crr_lot_unit1_change_qty(char *s_msg_code,
                                        TRSNode *out_node,
                                        TRSNode *in_node,
                                        char *s_lot_id,
                                        char *s_from_factory,
                                        char *s_from_oper,
                                        double d_qty_1,
                                        double d_qty_2,
                                        double d_qty_3);

extern int WIP_delete_dispatch_list(char *s_msg_code,
                             TRSNode *out_node,
                             char c_proc_step,
                             char *s_lot_id,
							 char *s_factory);

extern int WIP_check_carrier_lot(char *s_msg_code,
                          TRSNode *out_node,
                          char *s_lot_id,
                          char *s_crr_id,
                          double d_move_qty_1);

extern int WIP_check_batch_create_rule(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node,
                                struct MWIPBATRUL_TAG *MWIPBATRUL,
                                char *s_item_id,
                                char c_item_type,
                                char *s_mat_id,
                                int  i_mat_ver,
                                char *s_flow,
                                char *s_oper,
                                char *s_recipe_pp_id,
                                char *s_lot_id,
                                char *s_res_id);

extern int WIP_check_start_batch_rule(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node,
                                      char *s_factory,
                                      char *s_batch_id,
                                      char *s_res_id);

extern int WIP_check_batch_keep(char *s_msg_code,
                         TRSNode *out_node,
                         char *s_factory,
                         char *s_mat_id,
                         int   i_mat_ver,
                         char *s_flow,
                         char *s_oper,
                         char *c_is_batch_keep);

extern int WIP_insert_batch_movement_history(char *s_msg_code,
                                      TRSNode *out_node,
                                      char *s_factory,
                                      char *s_item_id,
                                      char  c_item_type,
                                      char  c_move_point);

extern int WIP_release_batch_by_item(char *s_msg_code,
                              TRSNode *out_node,
                              char *s_factory,
                              char *s_item_id,
                              char  c_item_type,
                              char *s_tran_time,
                              char *s_tran_user,
                              char *s_comment);

extern void WIP_crr_slot_init();

extern void WIP_crr_slot_add(struct MRASCRRSHS_TAG *MRASCRRSHS);

extern int WIP_crr_slot_save(char *s_msg_code,
                      TRSNode *out_node,
                      TRSNode *in_node);

extern int WIP_calculation_lot_queue_time(char proc_step, TRSNode *in_node,
                                    TRSNode *out_node);

extern int WIP_save_queue_time(char *s_lot_id, struct MWIPLOTSTS_TAG *MWIPLOTSTS, struct MWIPQTMDEF_TAG *MWIPQTMDEF, 
                            int i_case, char opt_level, TRSNode *in_node, char c_cal_source);

extern int WIP_update_lot_list_queue_time(TRSNode *in_node,
                                    TRSNode *out_node);

extern int WIP_copy_split_lot_queue_time(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node);

extern int WIP_copy_merge_lot_queue_time(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node);

extern int WIP_get_id_gen_max_argument(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int WIP_check_tran_step_serial_option(char *s_msg_code, TRSNode *out_node, 
                                      char *s_factory_t,
                                      char *s_mat_id_t,
                                      int i_mat_ver,
                                      char *s_flow_t,
                                      char *s_oper_t, 
                                      char c_rel_level, 
                                      int i_seq_num,
                                      char *s_lot_id_t);

extern int WIP_check_step_history(char *s_msg_code, TRSNode *out_node, 
                                      char *s_factory_t,
                                      char *s_mat_id_t,
                                      int i_mat_ver,
                                      char *s_flow_t,
                                      char *s_oper_t, 
                                      char c_rel_level,
                                      char *s_lot_id_t);

extern int WIP_get_carrier_count_of_lot(char *s_lot_id_t);

extern int WIP_check_carrier_lot_relation(char *s_msg_code,
                                          TRSNode *out_node,
                                          TRSNode *in_node,
                                          double d_move_qty_1);

extern int WIP_increase_carrier_lot_qty(char *s_msg_code,
                                        TRSNode *out_node,
                                        TRSNode *in_node,
                                        double d_qty_1,
                                        double d_qty_2,
                                        double d_qty_3);

extern int WIP_decrease_carrier_lot_qty(char *s_msg_code,
                                        TRSNode *out_node,
                                        TRSNode *in_node,
                                        double d_qty_1,
                                        double d_qty_2,
                                        double d_qty_3);

extern int WIP_make_carrier_lot_history(char *s_msg_code,
                                        TRSNode *out_node,
                                        char *s_lot_id_t);
//Add by Kelly Jung for Lot Extension of WIP Transaction
//20121201
extern int WIP_input_lot_ext(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int WIP_check_lot_oper_out(char *s_msg_code, 
                                  TRSNode *in_node, 
                                  TRSNode *out_node, 
                                  char *s_tran_code, 
                                  char *c_oper_out_flag);

extern int WIP_check_lot_queue_time(char *s_msg_code, 
                                    TRSNode *in_node, 
                                    TRSNode *out_node,
                                    char *s_tran_code,
                                    char c_check_point,
                                    char *c_break_flag);

extern int WIP_check_bin_collection(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_check_operation_unit_change(char *s_msg_code, TRSNode *out_node, char *s_factory_t, char *s_oper_t, char *s_to_factory_t, char *s_to_oper_t, char *s_unit_change_flag);
extern int WIP_Check_Low_Yield(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/****************************************************************************************************************/
/*    Service Function Prototypes                                                                               */
/****************************************************************************************************************/


extern int WIP_UPDATE_SUBLOT_GRADE_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int WIP_RELEASE_BATCH(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int WIP_MAKE_BATCH(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int WIP_COLLECT_LOT_DEFECT(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int WIP_CLOSE_RETURNLOT(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);
                                  
extern int WIP_CLEAN_LOT_DEFECT(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);
                                  
extern int WIP_CHECK_QUEUE_TIME(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int WIP_UPDATE_MATERIAL(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_ATTACH_FLOW_TOMATERIAL(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_DETACH_FLOW_FROMMATERIAL(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_OPTIONAL_FLOW(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REPAIR_END_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_LOCAL_REPAIR_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_REWORK_FLOW(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_REPAIR_OPER(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_FACTORY_CMF_ITEM(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_FACTORY(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_CYCLETIME(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_SHIP_FACTORY(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_OPEN_RETURNLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_CLOSE_RETURNLOT_MAIN(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_TROUBLE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Operation Setup */
extern int WIP_UPDATE_OPERATION(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Flow Setup */
extern int WIP_UPDATE_FLOW(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_COPY_FLOW(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_ATTACH_OPER_TOFLOW(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_DETACH_OPER_FROMFLOW(char *s_msg_code,   
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_OPTIONAL_OPER(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_DELETE_LOT_HISTORY(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);


/* Create Lot */
extern int WIP_CREATE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Start Lot */
extern int WIP_START_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Added by Phillip 2011.02.11 for Start Lot Ext*/
extern int WIP_START_LOT_EXT(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

/* End Lot */
extern int WIP_END_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_END_LOT_EXT(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_START_BATCH(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_END_BATCH(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Multi Start Lot */
extern int WIP_MULTI_START_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Multi End Lot */
extern int WIP_MULTI_END_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Move Lot */
extern int WIP_MOVE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Skip Lot */
extern int WIP_SKIP_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Split Lot */
extern int WIP_SPLIT_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Merge & S-Merge Lot */
extern int WIP_MERGE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Combine Lot */
extern int WIP_COMBINE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Loss Lot */
extern int WIP_LOSS_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Bonus Lot */
extern int WIP_BONUS_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Hold Lot */
extern int WIP_HOLD_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Release Lot */
extern int WIP_RELEASE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Release Lot By Force */ // Added By ICBAE 2010-04-14
extern int WIP_RELEASE_LOT_BY_FORCE(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Rework Lot */
extern int WIP_REWORK_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Ship Lot */
extern int WIP_SHIP_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Receive Lot */
extern int WIP_RECEIVE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Adapt Lot */
extern int WIP_ADAPT_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Store Lot*/
extern int WIP_STORE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Unstore Lot */
extern int WIP_UNSTORE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Terminate Lot */
extern int WIP_TERMINATE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_STORE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UNSTORE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* Lot EDC */
extern int WIP_LOT_EDC(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SORT_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REPAIR_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REPAIR_END_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_LOCAL_REPAIR_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_SUBLOT_LIST(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_CREATE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_START_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_END_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REWORK_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_MOVE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SKIP_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_HOLD_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_RELEASE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

// Added By ICBAE 2010.04.14
extern int WIP_RELEASE_SUBLOT_BY_FORCE(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SHIP_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_RECEIVE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_ADAPT_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SPLIT_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_MERGE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_COMBINE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_LOSS_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SORT_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_DELETE_SUBLOT_HISTORY(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SPLIT_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_COMBINE_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_MERGE_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_LOSS_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SORT_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REPAIR_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_LOCAL_REPAIR_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_REPAIR_END_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_RESUME_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_TERMINATE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_GENERATE_LOT_ID(char *s_msg_code,                         
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_CREATE_LOT_RULE(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_QUEUE_TIME(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_GRADE_RULE_LIST(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_BATCH_KEEP_LIST(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_FUTURE_ACTION(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_OPTION_DEFINITION(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_MFO_OPTION_PROMPT(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_YIELD(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_ID_RULE(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);
extern int WIP_UPDATE_RULE_DEF(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);
extern int WIP_UPDATE_RULE_RELATION(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_GENERATE_ID(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_BATCH_RELATION(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UPDATE_BATCH_RULE(char *s_msg_code, 
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_MAKE_RESERVE_BATCH(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_RESERVE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_RESERVE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UNRESERVE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_UNRESERVE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SWAP_OPERATION_SEQ(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_SWAP_FLOW_SEQ(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_CHANGE_CMF(char *s_msg_code,
                                  TRSNode *In_node,
                                  TRSNode *out_node);

//Add by J.S. 2009.02.26
extern int WIP_SCRIBE_LOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SCRIBE_LOT_EXT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_SCRIBE_SUBLOT(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

extern int WIP_CV_LOT(char *s_msg_code,
                      TRSNode *in_node,
                      TRSNode *out_node);

extern int WIP_DELETE_START_BATCH(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_REGENERATE_LOT(char *s_msg_code,
                        TRSNode *in_node ,
                        TRSNode *out_node);

// Add by Simon 2010.12.23

/* Start Lot For Step */
extern int WIP_START_LOT_FOR_STEP(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);

/* End Lot For Step */
extern int WIP_END_LOT_FOR_STEP(char *s_msg_code,
                TRSNode *in_node,
                TRSNode *out_node);






extern int WIP_VIEW_BATCH_HISTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_BATCH_LOT_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int WIP_VIEW_BATCH_RELATION(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_BATCH_RELATION_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int WIP_VIEW_BATCH_RULE(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int WIP_VIEW_BATCH_RULE_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int WIP_VIEW_CMF_CHANGE(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int WIP_VIEW_CYCLETIME_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int WIP_VIEW_DATA_LIST_BY_ATTRIBUTE(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int WIP_VIEW_EXT_CODE_TABLE(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_FACTORY(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node);

extern int WIP_VIEW_FACTORY_CMF_ITEM(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int WIP_VIEW_FACTORY_LIST(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int WIP_VIEW_FLOW(char *s_msg_code,
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int WIP_VIEW_FLOW_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int WIP_VIEW_FLOW_LIST_BY_OPERATION(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int WIP_VIEW_FLOW_SEQUENCE_LIST(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int WIP_VIEW_FUTURE_ACTION(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int WIP_VIEW_FUTURE_ACTION_LIST(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int WIP_VIEW_HOLD_LOT_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_ID_RULE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_ID_RULE_LIST(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int WIP_VIEW_LOT(char *s_msg_code,
                        TRSNode *in_node, 
                        TRSNode *out_node);

extern int WIP_VIEW_LOT_BONUS_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int WIP_VIEW_LOT_DEFECT_LIST_DETAIL(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int WIP_VIEW_LOT_HISTORY(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int WIP_VIEW_LOT_HOLD_CODE_LIST(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST_BY_OPERATION(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST_BY_RESOURCE(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST_DETAIL(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST_DETAIL_BY_SQL_QUERY(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int WIP_VIEW_LOT_LIST_DETAIL(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int WIP_VIEW_LOT_LOSS_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int WIP_VIEW_LOT_TRACE(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int WIP_VIEW_LOT_TRACE_HISTORY(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int WIP_VIEW_LOT_TRACE_TREE(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_MATERIAL(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int WIP_VIEW_MATERIAL_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_MATERIAL_LIST_BY_FLOW(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int WIP_VIEW_MATERIAL_LIST_BY_GROUP(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int WIP_VIEW_MATERIAL_VERSION_LIST(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int WIP_VIEW_MFO_BATCH_KEEP_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int WIP_VIEW_MFO_GRADE_RULE_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int WIP_VIEW_MFO_OPTION_DEFINITION(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int WIP_VIEW_MFO_OPTION_DEFINITION_LIST(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int WIP_VIEW_MFO_OPTION_PROMPT(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int WIP_VIEW_MFO_OPTION_PROMPT_LIST(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int WIP_VIEW_MFO_QUEUE_TIME_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int WIP_VIEW_MFO_SUBLOT(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int WIP_VIEW_MFO_SUBLOT_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int WIP_VIEW_OPERATION(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int WIP_VIEW_OPERATION_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_PROCTIME(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int WIP_VIEW_PROCESS_OPERATION_LIST(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int WIP_VIEW_QUEUE_TIME(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int WIP_VIEW_REPAIR_OPER_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int WIP_VIEW_RESERVE_BATCH(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_RESERVE_BATCH_ID_LIST(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int WIP_VIEW_RESERVE_BATCH_ITEM_LIST(char *s_msg_code,
                                           TRSNode *in_node,
                                           TRSNode *out_node);

extern int WIP_VIEW_RESERVE_LOT_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int WIP_VIEW_RESERVE_SUBLOT_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int WIP_VIEW_RETURNLOT(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int WIP_VIEW_RETURNLOT_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int WIP_VIEW_REWORK_FLOW_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int WIP_VIEW_REWORK_LOT_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int WIP_VIEW_REWORK_OPER_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int WIP_VIEW_RULE_DEF(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int WIP_VIEW_RULE_DEF_LIST(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_RULE_RELATION(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_VIEW_RULE_RELATION_LIST(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int WIP_VIEW_SHIP_FACTORY(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int WIP_VIEW_SHIP_FACTORY_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int WIP_VIEW_SUBLOT(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int WIP_VIEW_SUBLOT_HISTORY(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_SUBLOT_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int WIP_VIEW_SUBLOT_LIST_DETAIL(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int WIP_VIEW_SUBLOT_LOSS_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int WIP_VIEW_TRANSIT_LOT_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int  WIP_VIEW_TROUBLE_LOT(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int WIP_VIEW_TROUBLE_LOT_LIST(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int WIP_VIEW_YIELD_LIST(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int WIP_VIEW_GEN_ID_HISTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_ID_GEN_INIT(char *s_msg_code, 
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_ID_GEN_APPROVAL(char *s_msg_code, 
                               TRSNode *in_node,
                               TRSNode *out_node);

// Added by Simon  2010.12.23
extern int WIP_VIEW_STEP(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int WIP_VIEW_STEP_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_LOT_STEP_STATUS(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int WIP_VIEW_LOT_HISTORY_FOR_STEP(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int WIP_DELETE_LOT_HISTORY_FOR_STEP(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int WIP_ATTACH_STEP_TOOPERATION(char *s_msg_code,
                                        TRSNode *in_node,    
                                        TRSNode *out_node);

extern int WIP_DETACH_STEP_FROMOPERATION(char *s_msg_code,    
                                        TRSNode *in_node,     
                                        TRSNode *out_node);

extern int WIP_UPDATE_STEP(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int WIP_UPDATE_STEP_MFO_RELATION(char *s_msg_code,
                                        TRSNode *in_node,  
                                        TRSNode *out_node);

extern int WIP_SWAP_STEP_SEQ(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

/* Added by phillip 2011.02.10 */
extern int WIP_UPDATE_OPERATION_INPUT_VALUE_LIST(char *s_msg_code,
                                                 TRSNode *in_node, 
                                                 TRSNode *out_node);

extern int WIP_VIEW_OPERATION_INPUT_VALUE_LIST(char *s_msg_code,
                                               TRSNode *in_node, 
                                               TRSNode *out_node);

extern int WIP_VIEW_TOOL_LIST_BY_MFO(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int WIP_VIEW_MFO_OPTION_VALUE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

//Add by J.S. 2011.09.30
extern int WIP_VIEW_FACTORY_CMF_LIST_DETAIL(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

//Add by Aiden. 2012.03.28
extern int WIP_TRANSFER_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_TRANSFER_SUBLOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
//Added by IC.BAE 2012.03.27
extern int WIP_VIEW_MFO_INFO(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int WIP_UPDATE_MULTI_SETUP(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int WIP_GET_FLOW_OPER_BY_COUNT(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

// Added by DM KIM 2012.04.09
extern int WIP_MULTI_SHIP_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_TRANSFER_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_HOLD_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_RELEASE_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_RECEIVE_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_MERGE_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_MULTI_SPLIT_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

// Added by DM KIM 2014.01.14
extern int WIP_MULTI_TERMINATE_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

// Added by DM KIM 2012.04.18
extern int WIP_UPDATE_TEST_PROGRAM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_TEST_PROGRAM_KEY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_TEST_PROGRAM_VERSION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_TEST_PROGRAM_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_APPROVAL_RELEASE_TEST_PROGRAM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//Add by BS.KWAK. 2012.03.29
extern int WIP_QA_GATE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_QA_RULE_BY_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_UPDATE_QA_SAMPLE_RULE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_UPDATE_QA_ACTION_RULE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);


extern int WIP_VIEW_QA_RULE_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_QA_RULE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_MFO_QA_RULE_LIST(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_UPDATE_MFO_QA_RULE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_QA_HISTORY_BY_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_QA_MAINT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_QA_RESULT_ACTION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_QA_RESULT_ACTION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_QA_RESULT_ACTION(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_UPDATE_LOW_YIELD(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int WIP_VIEW_LOW_YIELD(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);


// Add by Kelly Jung 2012.04.19 Lot Extension
extern int WIP_VIEW_LOTEX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, TRSNode *EXTLOTSTS);
extern int WIP_DELETE_LOTEX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_LOTEX(char *s_msg_code, TRSNode *in_node, TRSNode *out_node, TRSNode *EXTLOTSTS);
extern int WIP_VIEW_LOTEX_HIS(char *s_msg_code, char *s_lot_id, int i_hist_seq, TRSNode *out_node, TRSNode *EXTLOTHIS);
extern int WIP_VIEW_LOTEX_LIST(char *s_msg_code, TRSNode *out_node, char *s_factory, TRSNode *LOTEX_LIST);
extern int WIP_UPDATE_LOTEX2(char *s_msg_code, TRSNode *out_node, char *s_lot_id_t, TRSNode *EXTLOTSTS, char c_skip_increase_extseq_flag);
extern int WIP_VIEW_LOTEX2(char *s_msg_code, TRSNode *out_node, char *s_lot_id_t, TRSNode *EXTLOTSTS);

//Add by bs.Kwak 2012 04 25
extern int WIP_VIEW_QA_LOT_DEFECT_BY_LOT(char *s_msg_code, 
							 TRSNode *in_node,
							 TRSNode *out_node);

extern int WIP_VIEW_QA_SUBLOT_DEFECT_BY_LOT(char *s_msg_code, 
							 TRSNode *in_node,
							 TRSNode *out_node);

extern int WIP_VIEW_QA_LOT_HISTORY(char *s_msg_code, 
							 TRSNode *in_node,
							 TRSNode *out_node);

extern int WIP_COPY_MFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int WIP_VIEW_BIN_DEFINITION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_DEFINITION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_VERSION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_BIN_DEFINITION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_BIN_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_COPY_BIN_DEFINITION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_COPY_BIN_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_BIN_UNIT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_BIN_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_UNIT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_BIN_RELATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_RELATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_UPDATE_PRIORITY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_PRIORITY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_PRIORITY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_BY_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_COLLECT_BIN_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_HISTORY_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_HISTORY_SUBLOT_GRADE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_BIN_HISTORY_SUBLOT_UNIT_TOTAL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_END_LOT_BY_BIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_LOW_YIELD_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_TEST_PROGRAM_BY_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_LATEST_BIN_COLLECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_CONFIRM_GENERATED_ID(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_BATCH_CHECK_QUEUE_TIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_BONUS_SUBLOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_BONUS_LOT_EXT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_CV_SUBLOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_CV_LOT_EXT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_VIEW_TEST_PROGRAM_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_COPY_ID_RULE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//Add by MHIM 2015.08.12
extern int WIP_ABORT_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int WIP_ABORT_START_SUBLOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif /* _WIPCORE_COMMON_H */
