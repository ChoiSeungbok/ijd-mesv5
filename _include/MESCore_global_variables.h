/*******************************************************************************

    System      : MESplus
    Module      : MESCore
    File Name   : MESCore_global_variables.h
    Description : Common header of MESplus Server

    MES Version : 5.1.1

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2010/06/23  R&D            Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESCORE_GLOBAL_VARIABLES_H
#define _MESCORE_GLOBAL_VARIABLES_H

#include <TRSCore_common.h>
#include "MESCore_defines.h"

extern TRSNode* g_node_var;
extern char gs_server_name[MP_SIZE_SERVER_NAME];
extern char gs_client_id[MP_SIZE_CLIENT_ID];

extern char gs_home_dir[256];
extern char gs_command_dir[256];
extern char gs_bin_dir[256];
extern char gs_temp_dir[256];
extern char gs_slib_dir[256];
extern char gs_screen_dir[256];
extern char gs_doctemp_dir[256];
extern char gs_alm_attach_dir[256];
extern char gs_bbs_attach_dir[256];
/*** #989 SPM Development (2012.04.26 by JYPARK) ***/
extern char gs_spec_attach_dir[256];
/*** End of Add (2012.04.26) ***/
extern char gs_work_proc_status_attach_dir[256];

extern char gs_com_file[256];
extern char gs_svr_file[256];
extern unsigned int gi_max_message_length;
extern unsigned int gi_max_shared_pool_count;

extern char gc_language_type;
extern char gs_server_version[100];

extern char gs_site_id[MP_SIZE_SITE_ID];
extern char gs_main_channel[MP_SIZE_CHANNEL];
extern char gs_stop_channel[MP_SIZE_CHANNEL];
extern char gs_admin_channel[MP_SIZE_CHANNEL];
extern char gs_subno[MP_SIZE_SUBNO];
extern char gs_connect_string[100];
extern unsigned int  gi_default_ttl;
extern char gc_h101_inter_station_mode;

extern struct channel_module_tag   ga_channel_mod[30];
extern unsigned int                gi_channel_count;

extern char gs_rv_service[100];
extern char gs_rv_network[100];

extern char gs_upgrade_version[32];
extern char gs_upgrade_method[32];
extern char gs_upgrade_dir[256];
extern char gs_upgrade_address[32];
extern char gs_upgrade_user[32];
extern char gs_upgrade_password[32];

extern char gc_stop_process;

extern char gs_database_user[32];
extern char gs_database_password[32];
extern char gs_tns_name[32];
extern char gc_use_local_db;

extern char gc_label_remote_connected;

extern char gc_alm_language;
extern char gs_alm_factory[10];
extern char gs_alm_res_id[20];
extern char gs_alm_lot_id[25];
extern char gs_alm_source_id[30];
extern char gs_alm_alarm_id[10];
extern char gs_alm_user_id[20];
extern char gs_alm_module[12];
extern char gc_alarm_keeping;

extern struct log_type_tag gs_log_type;
extern int gi_log_mode;
extern int gi_log_level;
extern unsigned int gi_log_file_size;
extern unsigned int gi_log_file_count;
extern char gs_log_file_dir[256];
extern char gc_write_request_xml;
extern char gc_log_file_by_time;

extern char gc_use_spec_out_mask_char;

extern char gc_use_ASC;
extern unsigned int gi_password_min_length;
extern unsigned int gi_password_expire_notice;
extern unsigned int gi_password_char_number;
extern unsigned int gi_password_lock_count;

extern char gc_use_RTD;
extern char gc_process_RTD;
extern char gs_max_process_subno[MP_SIZE_SUBNO];
extern unsigned int gi_delay_time_sec;
extern unsigned int gi_server_polling_sec;

extern char gc_use_pro_epi_shared_library;
extern char gc_use_custom_xml_format;
extern char gc_case_sensitive_member_name;
extern int gi_carrier_lot_relation;

extern char gs_mail_server_name[100];
extern char gs_mail_user_name[50];
extern char gs_mail_user_pass[50];
extern char gs_mail_from_id[50];
extern char gc_mail_file_del_flag;
extern char gc_mail_file_copy_flag;
extern char gs_mail_contents_dir[256];
extern char gs_mail_contents_back_dir[256];

extern char gc_spc_rule_check_type;

extern MES_FUTURE_ACTION_HANDLER gp_future_action;

extern struct MWIPLOTSTS_TAG gs_lot_old_info;

extern int gb_multi_transaction;
extern char gs_multi_tran_key[30];
extern unsigned int gi_multi_tran_seq;

extern int gi_timer_interval_1;
extern int gi_timer_interval_2;
extern int gi_timer_interval_3;
extern int gi_timer_interval_4;
extern int gi_timer_interval_5;
extern int gi_timer_interval_6;
extern int gi_timer_interval_7;
extern int gi_timer_interval_8;
extern int gi_timer_interval_9;

//Add by J.S. 2011.10.20 for Service 실행 통계, 에러 로깅 
extern char gc_collect_performance_info;
extern char gc_collect_error_logging;
extern int  gi_collect_time_limit_sec;
extern char gs_collect_node[20];
extern char gc_collect_table_space_inc_info;
extern int  gi_collect_table_space_check_size;
extern char gc_collect_long_query_ranking_info;
extern char gc_collect_long_query_ranking_type;
//Add by I.C.Bae 2014.09.22 for compress service performance
extern int gi_collect_performance_compress;
//Add by I.C.Bae 2014.09.23 for delete service error log
extern int gi_collected_keeping_limit;

//Add by J.S. 2011.11.21 for DST Time Compress 여부 및 DST 종료시간, DATE넘길때 짧은 XML 형식 사용여부
extern char gc_DST_time_compress;
extern char gs_DST_end_time[20];
extern char gc_short_XML_date_format;
extern char gs_time_zone_offset[6];
//End Add

//Add by IC.BAE 2012.06.13 for Winform log line count
extern int gi_max_line_count;

//Add by JU.Heo 2012.11.21 
extern char gc_guaranteed_msg_confirm_point;

// Added by Chris Jung 2013.01.28
extern char gc_write_interval_time;

// Added by IC.bae
extern int gi_min_waiting_time;
extern int gi_max_waiting_time;

// TibRv Schedule Paramters
extern unsigned short gi_tibrv_scheduler_weight;
extern double gd_tibrv_heartbeat_interval;
extern double gd_tibrv_activate_interval;

#endif /* _MESCORE_GLOBAL_VARIABLES_H */
