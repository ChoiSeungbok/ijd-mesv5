/*******************************************************************************

    System      : MESplus
    Module      : User Defined Shared Library
    File Name   : sl_common.h
    Description : Common function prototype of user defined shared library

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

#ifndef _SLCCORE_COMMON_H
#define _SLCCORE_COMMON_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#if defined(WIN32) || defined(WIN64)

    /***********************************/
    /* Windows System                  */
    /***********************************/
    #include <windows.h>
    #include <TRSCore_common.h>
    #include <SLPCore_global_struct.h>
    #include <LOGCore_common.h>
    #include <LOGCore_defines.h>
    #include <DBC_common.h>

#if defined(_USE_STATIC_LIB)
        #define DllExport  extern 
#else
    #if defined(__cplusplus)
        #define DllExport  extern "C" __declspec( dllexport )
    #else
        #define DllExport  extern __declspec( dllexport )
    #endif

#endif

    DllExport void SLC_SET_GLOBAL_VARIABLE(GLOBAL_VAR *global_var);
    DllExport void SLC_GET_GLOBAL_VARIABLE(GLOBAL_VAR *global_var);
    DllExport void SLC_INITIAL_WINENV();
    DllExport void SLC_STOP_WINENV();

    /*** end of windows system ***/

#else

    /***********************************/
    /* Unix, Linux System              */
    /***********************************/

    #define DllExport   extern

    /*** end of unix, linux system ***/

#endif

typedef enum{
    UNLOADABLE = 0,
    LOAD_ONLY = 1
} SLC_LIBRARY_MODE;

typedef struct 
{
    char func_name[100];
    int active_version;
} SLC_FUNC_LIST;

#define SLC_REALLOC_COUNT   10


DllExport int  SLC_GET_ACTIVE_VERSION(const char *s_func_name);
DllExport int  SLC_GET_ACTIVE_VERSION_LIST(void **p_func_list);
DllExport void SLC_BIND_FUNCTION();
DllExport void SLC_UNBIND_FUNCTION();
DllExport int  SLC_GET_LIBRARY_MODE();

extern void SLC_ADD_FUNCTION(const char *s_func_name, int i_active_version);
extern void SLC_SET_LIBRARY_MODE(const SLC_LIBRARY_MODE i_mode);

#define SLC_INITIALIZE() \
SLC_FUNC_LIST   **slc_func_list = 0x00; \
int             slc_func_count = 0; \
int             slc_library_mode = UNLOADABLE; \


#endif

