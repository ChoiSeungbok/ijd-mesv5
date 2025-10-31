/*******************************************************************************

    System      : MESplus
    Module      : MESServer
    File Name   : MessageInline.h
    Description : Handle message for MESplus

    MES Version : 5.1.0

    Detail Description
        - Include middleware inline functions of Highway101 and TibRV

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2010/04/07  R&D            Create

    Copyright(C) 1998-2010 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESSAGE_INLINE_H
#define _MESSAGE_INLINE_H

//Modify by J.S. 2008.02.10 Add AIX Switch
#if defined(_HPUX_SOURCE)
#    include <arpa/inet.h>
#    include <stdio.h>
#    include <stdlib.h>
#    include <netinet/in.h>
#    include <netdb.h>
#elif defined(__sun)
#    include <arpa/inet.h>
#    include <stdio.h>
#    include <stdlib.h>
#    include <netinet/in.h>
#elif defined(_AIX)
#    include <arpa/inet.h>
#    include <stdio.h>
#    include <stdlib.h>
#    include <netinet/in.h>
#    include <netdb.h>
#elif defined(WIN32) || defined(WIN64)
#    include <stdio.h>
#    include <stdlib.h>
#    include <windows.h>
#    include <winsock.h>
#    include <tchar.h>
#endif

#if defined(_H101)

#include <transceiverx.h>

#if defined(_HPUX_SOURCE)
#    define TSTRLEN(s)            strlen(s)
#    define TSTRCPY(s1, s2)       strcpy(s1, s2)
#    define TSTRNCPY(s1, s2, s3)  strncpy(s1, s2, s3)
#    define TSTRSTR(s1, s2)       strstr(s1, s2)
#    define TSTRCHR(s1, c)        strchr(s1, c)
#    define TSTRCMP(s1, s2)       strcmp(s1, s2)
#    define TSTRNCMP(s1, s2, s3)  strncmp(s1, s2, s3)
#    define TOLOWER(c)            tolower(c)
#    define TSTRTOK(s1, s2)       strtok(s1, s2)
#    define TATOI(s)              atoi(s)
#    define TPRINTF               printf
#    define TFPRINTF              fprintf
#    define TSPRINTF              sprintf
#    define TSTRCAT(a, b)         strcat(a, b)
#elif defined(__digital__)
#    define TSTRLEN(s)            strlen(s)
#    define TSTRCPY(s1, s2)       strcpy(s1, s2)
#    define TSTRNCPY(s1,s2,s3)    strncpy(s1,s2,s3)
#    define TSTRSTR(s1, s2)       strstr(s1, s2)
#    define TSTRCHR(s1, c)        strchr(s1, c)
#    define TSTRCMP(s1, s2)       strcmp(s1, s2)
#    define TSTRNCMP(s1,s2,s3)    strncmp(s1, s2, s3)
#    define TOLOWER(c)            tolower(c)
#    define TSTRTOK(s1, s2)       strtok(s1, s2)
#    define TATOI(s)              atoi(s)
#    define TPRINTF               printf
#    define TFPRINTF              fprintf
#    define TSPRINTF              sprintf
#    define TSTRCAT(a, b)         strcat(a, b)
#elif defined(vms)
#    define TSTRLEN(s)            strlen(s)
#    define TSTRCPY(s1, s2)       strcpy(s1, s2)
#    define TSTRNCPY(s1,s2,s3)    strncpy(s1,s2,s3)
#    define TSTRSTR(s1, s2)       strstr(s1, s2)
#    define TSTRCHR(s1, c)        strchr(s1, c)
#    define TSTRCMP(s1, s2)       strcmp(s1, s2)
#    define TSTRNCMP(s1,s2,s3)    strncmp(s1, s2, s3)
#    define TOLOWER(c)            tolower(c)
#    define TSTRTOK(s1, s2)       strtok(s1, s2)
#    define TATOI(s)              atoi(s)
#    define TPRINTF               printf
#    define TFPRINTF              fprintf
#    define TSPRINTF              sprintf
#    define TSTRCAT(a, b)         strcat(a, b)
#elif defined(__sun)
#    define TSTRLEN(s)            strlen(s)
#    define TSTRCPY(s1, s2)       strcpy(s1, s2)
#    define TSTRNCPY(s1,s2,s3)    strncpy(s1,s2,s3)
#    define TSTRSTR(s1, s2)       strstr(s1, s2)
#    define TSTRCHR(s1, c)        strchr(s1, c)
#    define TSTRCMP(s1, s2)       strcmp(s1, s2)
#    define TSTRNCMP(s1,s2,s3)      strncmp(s1, s2, s3)
#    define TOLOWER(c)            tolower(c)
#    define TSTRTOK(s1, s2)       strtok(s1, s2)
#    define TATOI(s)              atoi(s)
#    define TPRINTF               printf
#    define TFPRINTF              fprintf
#    define TSPRINTF              sprintf
#    define TSTRCAT(a, b)         strcat(a, b)
#elif !defined(WIN32) && !defined(_WIN32_WCE)
#    define TSTRLEN(s)            strlen(s)
#    define TSTRCPY(s1, s2)       strcpy(s1, s2)
#    define TSTRNCPY(s1,s2,s3)    strncpy(s1,s2,s3)
#    define TSTRSTR(s1, s2)       strstr(s1, s2)
#    define TSTRCHR(s1, c)        strchr(s1, c)
#    define TSTRCMP(s1, s2)       strcmp(s1, s2)
#    define TSTRNCMP(s1,s2,s3)    strncmp(s1, s2, s3)
#    define TOLOWER(c)            tolower(c)
#    define TSTRTOK(s1, s2)       strtok(s1, s2)
#    define TATOI(s)              atoi(s)
#    define TPRINTF               printf
#    define TFPRINTF              fprintf
#    define TSPRINTF              sprintf
#    define TSTRCAT(a, b)         strcat(a, b)
#else
#    define TSTRLEN(s)            _tcslen(s)
#    define TSTRCPY(s1, s2)       _tcscpy(s1, s2)
#    define TSTRNCPY(s1,s2,s3)    _tcsncpy(s1,s2,s3)
#    define TSTRSTR(s1, s2)       _tcsstr(s1, s2)
#    define TSTRCHR(s1, c)        _tcschr(s1, c)
#    define TSTRCMP(s1, s2)       _tcscmp(s1, s2)
#    define TSTRNCMP(s1,s2,s3)      _tcsncmp(s1, s2, s3)
#    if defined(UNICODE) || defined(_UNICODE)
#        define TOLOWER(c)        towlower(c)
#    else
#        define TOLOWER(c)        tolower(c)
#    endif
#    define TSTRTOK(s1, s2)       _tcstok(s1, s2)
#    define TATOI(s)              _ttoi(s)
#    define TPRINTF               _tprintf
#    define TFPRINTF              _tfprintf
#    define TSPRINTF              _stprintf
#    define TSTRCAT(a, b)         _tcscat(a, b)
#    define strcasecmp(a, b)      (strcmp_icase(a, b))
#    define WCTMB(x,y,z)          WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK,(x),-1,(y),(z),Null_Ptr,Null_Ptr)
#    define MBTWC(x,y,z)          MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,(x), -1, (y), (z) )
typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
#endif /* !defined(WIN32) && !defined(_WIN32_WCE) */


/* Macro - Operation dispatch by module ***************************************/
typedef IOIStatus (*xgen_operation)(IOIHandle session, IOIMessage msg);
typedef struct {
    LPCTSTR name;
    xgen_operation operation;
} XGEN_OPERATION;

typedef struct {
    LPCTSTR name;
    XGEN_OPERATION * operation;
    int operation_count;
} XGEN_MODULE;

//MessageHandler.c 에 정의되어 있음.
extern IOISession mioi_session;

//Modify by J.S. 2009.03.19 get_operation printout 하는 부분 삭제 로그가 너무 많이 생김.
extern XGEN_MODULE xgen_modules[];
extern int xgen_module_index;

#define XGEN_MODULE_INIT(size)\
int xgen_module_index = 0;\
XGEN_MODULE xgen_modules[size];\
xgen_operation get_operation(LPCTSTR module, LPCTSTR operation) {\
    int i, j;\
    for(i = 0; i < xgen_module_index; i++)\
        if(0 == TSTRCMP(xgen_modules[i].name, module))\
            for(j = 0; j < xgen_modules[i].operation_count; j++)\
                if(0 == TSTRCMP(xgen_modules[i].operation[j].name, operation))\
                    return xgen_modules[i].operation[j].operation;\
    return NULL;\
}\
void set_tune(LPCTSTR channel, int mode) {\
    if(DT_REQUEST == mode || DT_UNICAST == mode) IOITuneUnicast(mioi_session, channel);\
    else if(DT_MULTICAST == mode) IOITuneMulticast(mioi_session, channel);\
    else if(DT_GUARANTEED_UNICAST == mode) IOITuneGuaranteedUnicast(mioi_session, channel);\
    else if(DT_GUARANTEED_MULTICAST == mode) IOITuneGuaranteedMulticast(mioi_session, channel);\
}\
void set_untune(LPCTSTR channel, int mode) {\
    if(DT_UNICAST == mode || DT_UNICAST == mode) IOIUntuneUnicast(mioi_session, channel);\
    else if(DT_MULTICAST == mode) IOIUntuneMulticast(mioi_session, channel);\
    else if(DT_GUARANTEED_UNICAST == mode) IOIUntuneGuaranteedUnicast(mioi_session, channel);\
    else if(DT_GUARANTEED_MULTICAST == mode) IOIUntuneGuaranteedMulticast(mioi_session, channel);\
}\
void XGEN_CONFIG_REGIST(int mode) {\
    IOISessionSetConnectHandler(mioi_session, on_connect);\
    IOISessionSetDisconnectHandler(mioi_session, on_disconnect);\
    if(SESSION_MODE_DISPATCH_PULL == (mode & SESSION_MODE_DISPATCH_PULL)) {\
    } else {\
        IOISessionSetUnicastHandler(mioi_session, on_message);\
        IOISessionSetRequestHandler(mioi_session, on_message);\
        IOISessionSetReplyHandler(mioi_session, on_reply);\
    }\
}

#define XGEN_MODULE_BEGIN_CONTEXT(module) XGEN_OPERATION module##_operations[] = {
#define XGEN_OPERATION_REGIST_CONTEXT(operation) {#operation, recv_##operation},
#define XGEN_MODULE_END_CONTEXT(module) };

#define XGEN_MODULE_REGIST(module) regist##module()
#define XGEN_MODULE_REGIST_CONTEXT(module, count)\
void regist##module() {\
    xgen_modules[xgen_module_index].name = #module;\
    xgen_modules[xgen_module_index].operation = module##_operations;\
    xgen_modules[xgen_module_index].operation_count = count;\
    xgen_module_index++;\
}

#elif defined(_TIBRV)

#include <signal.h>
#include <tibrv.h>
#include <cm.h>
#include <ft.h>

/*
** Macro Definition to initialize the status value & message.
*/
#define STSINIT(sts_val,sts_msg) { *sts_val = 0; memset(sts_msg, 0x00 , 10); }

#endif /* _H101, _TIBRV */

#endif /* _MESSAGE_INLINE_H */
