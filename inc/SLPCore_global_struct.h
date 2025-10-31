/*******************************************************************************

    System      : MESplus
    Module      : SLPCore
    File Name   : SLPCore_global_struct.h
    Description : Common header of MESplus Server

    MES Version : 4.2.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/06/03  Aiden          Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _SLPCORE_GLOBAL_STRUCT_H
#define _SLPCORE_GLOBAL_STRUCT_H

#if defined(WIN32) || defined(WIN64)

typedef struct
{
    char s_site_id[MP_SIZE_SITE_ID];
    char s_main_channel[MP_SIZE_CHANNEL];
    char s_subno[MP_SIZE_SUBNO];
    char s_server_name[MP_SIZE_SERVER_NAME];
    char s_client_id[MP_SIZE_CLIENT_ID];
    char s_home_dir[256];
    char s_command_dir[256];
    char s_bin_dir[256];
    char s_temp_dir[256];
    char s_slib_dir[256];
    char s_com_file[256];
    char s_svr_file[256];
    unsigned int i_max_message_length;
    int i_max_shared_pool_count;

    char s_connect_string[100];

    /* Label Print */
    char c_label_remote_connected;

    /* For Alarm */
    char c_alm_language;
    char s_alm_factory[10];
    char s_alm_res_id[20];
    char s_alm_lot_id[25];
    char s_alm_source_id[30];
    char s_alm_alarm_id[10];
    char s_alm_user_id[20];
    char s_alm_module[12];
    char c_alarm_keeping;

    /* Log Related */
    int i_log_mode;
    int i_log_level;
    unsigned int i_log_file_size;
    unsigned int i_log_file_count;
    char s_log_file_dir[256];
    char c_write_request_xml;
    char c_log_file_by_time;

    /* EDC Option */
    char c_use_spec_out_mask_char;

    /* Channel Information */
    struct
    {
        char s_channel[255];
        char c_tune_mode;
        char s_allow_mod_list[50][30];
        int  i_allow_mod_count;
    }   a_channel_mod[30];
    int i_channel_count;

    unsigned int i_default_ttl;

    int  b_multi_transaction;
    char s_multi_tran_key[30];
    unsigned int i_multi_tran_seq;

    char c_language_type;
    char s_server_version[100];
    char c_db_connected;

    void *node_var;

} GLOBAL_VAR;

#endif

#endif
