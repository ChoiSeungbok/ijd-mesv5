/*******************************************************************************

    System      : MESplus
    Module      : SLPCore
    File Name   : SLPCore_common.h
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

#ifndef _SLPCORE_COMMON_H
#define _SLPCORE_COMMON_H

#include <MESCore_common.h>

#if defined(WIN32) || defined(WIN64)

    /***********************************/
    /* Windows System                  */
    /***********************************/

    #include <windows.h>
    #include "SLPCore_global_struct.h"

    typedef HINSTANCE   H_LIB;


    typedef void     (*SLC_SET_GLOBAL_VARIABLE_TYPE)(GLOBAL_VAR *);
    typedef void     (*SLC_GET_GLOBAL_VARIABLE_TYPE)(GLOBAL_VAR *);
    typedef void     (*SLC_INITIAL_WINENV_TYPE)(void);
    typedef void     (*SLC_STOP_WINENV_TYPE)(void);

    typedef TRSNode* (*SLC_COPY_NODE_TYPE)(const TRSNode *);
    typedef void     (*SLC_FREE_NODE_TYPE)(TRSNode *node);

    /*** end of windows system ***/

#else

    /***********************************/
    /* Unix, Linux System              */
    /***********************************/

    #include <dlfcn.h>
    #include <dirent.h>

    typedef void *      H_LIB;

    /*** end of unix, linux system ***/

#endif

typedef struct
{
    H_LIB   h_lib;
    char    s_name[30];
    char    s_version[30];
    int     i_usage_count;
    char    s_load_time[18];
    int     i_load_only_lib;
    int     i_proc_count;
} SHARED_POOL;


/* Shared library common function signature */
typedef int     (*SLC_GET_ACTIVE_VERSION_TYPE)(const char *);
typedef int     (*SLC_GET_ACTIVE_VERSION_LIST_TYPE)(void *);
typedef void    (*SLC_BIND_FUNCTION_TYPE)();
typedef void    (*SLC_UNBIND_FUNCTION_TYPE)();
typedef int     (*SLC_GET_LIBRARY_MODE_TYPE)();

typedef int     (*SERVICE_TYPE)(TRSNode *, TRSNode *);
typedef int     (*CUSTOM_XML_FUNCTION_TYPE)(TRSNode *, void *, void **);
typedef int     (*CUSTOM_SET_CHANNEL_TYPE)(char *, char *, char *, int);
typedef int     (*CUSTOM_XML_PROLOGUE_TYPE)(void *);
typedef int     (*CUSTOM_XML_EPILOGUE_TYPE)(void *, char *, int *);


/* Shared Library Pool common function */
extern H_LIB    SLP_load_library(const char *s_lib_name, char *s_lib_ver, char *s_err_msg);
extern H_LIB    SLP_reload_library(const char *s_lib_name, char *s_lib_ver, char *s_err_msg);
extern void*    SLP_get_func_addr(H_LIB p_lib, char *s_func_name, char *s_err_msg);
extern int      SLP_unload_library(H_LIB p_lib, char *s_err_msg);
extern int      SLP_call_service(const char *s_svc_name, const int i_svc_ver, 
                                 const char *s_lib_name, const char *s_lib_ver,
                                 const char *s_key_name,
                                 TRSNode *in_node, TRSNode *out_node);
extern int      SLP_call_service_by_key(const char *s_key_name,
                                        TRSNode *in_node, TRSNode *out_node);
extern void     SLP_init_pool(const int i_max_shared_pool_count);
extern int      SLP_free_pool();
extern int      SLP_clear_pool();

extern int      SLP_custom_parse(TRSNode *node, void *msg_1, void **msg_2, char *s_err_msg);
extern int      SLP_custom_generate(TRSNode *node, void *msg_1, void **msg_2, char *s_err_msg);
extern int      SLP_custom_send_err_msg(TRSNode *node, void *msg_1, void **msg_2, char *s_err_msg);
extern int      SLP_custom_set_channel(char *s_module_name, char *s_service_name, char *channel, int mode, char *s_err_msg);
extern int      SLP_custom_prologue(void *msg, char *s_err_msg);
extern int      SLP_custom_epilogue(void *msg, char *need_sending_message, int *send_type, char *s_err_msg);


#endif

