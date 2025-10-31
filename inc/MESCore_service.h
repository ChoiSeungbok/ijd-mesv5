/*******************************************************************************

    System      : MESplus
    Module      : MESCore
    File Name   : MESCore_service.h
    Description : Common Macro definition of MESplus Server

    MES Version : 5.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/13  Aiden          Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESCORE_SERVICE_H
#define _MESCORE_SERVICE_H

#include <TRSCore_common.h>

typedef int (*MP_REQUEST_REPLY_TYPE)(TRSNode *, TRSNode *);
typedef int (*MP_REQUEST_NOREPLY_TYPE)(TRSNode *);

typedef enum {
    REPLY,
    NO_REPLY
} MP_SERVICE_MODE;

#define MP_SERVICE_SUCCESS          1
#define MP_SERVICE_FAIL             0
#define MP_SERVICE_NOT_FOUND        -1

extern void COM_INIT_MES_SERVICE_MODULE_LIST();
extern void COM_add_service(char *s_module_name, char *s_service_name, MP_SERVICE_MODE service_mode, ...);
extern void COM_remove_modules();
extern MP_SERVICE_MODE COM_get_service(char *s_module_name, char *s_service_name, void **p_service);
extern int COM_proc_user_routine(char *s_module, char *s_service, int i_point, TRSNode *in_node, TRSNode *out_node);
extern int COM_find_user_service(char *s_lib_name, char *s_lib_ver, char *s_service, int *i_service_ver);

#endif  /* _MESCORE_SERVICE_H */
