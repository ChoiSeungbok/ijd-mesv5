/*******************************************************************************

    System      : MESplus
    Module      : MESServer
    File Name   : MessageDefines.h
    Description : Handle message for MESplus

    MES Version : 5.0.0

    Detail Description
        - Include middleware definition of Highway101 and TibRV

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/08/25  Aiden          Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESSAGE_DEFINES_H
#define _MESSAGE_DEFINES_H

#define    DM_UNICAST                  0x01
#define    DM_MULTICAST                0x02
#define    DM_RREPLY                   0x03
#define    DM_GUNICAST                 0x05
#define    DM_GMULTICAST               0x06

#if defined(_H101)

/* Constants ******************************************************************/
#define XGEN_SUCCESS                    IOI_SUCCESS
#define XGEN_BLOCK_INIT_COUNT           5
#define XGEN_BLOCK_INC_COUNT            10
#define XGEN_BLOCK_SIZE                 500

#define XGEN_RESULT_CODE                _T("RESULT_CODE")
#define XGEN_RESULT_MSG                 _T("RESULT_MSG")
#define XGEN_VERSION                    _T("4.0")
#define XGEN_TAG_VERSION                _T("VERSION")
#define XGEN_TAG_MODULE                 _T("MODULE")
#define XGEN_TAG_INTERFACE              _T("INTERFACE")
#define XGEN_TAG_OPERATION              _T("OPERATION")

#define XGEN_ERROR_UNEXPECTED_VERSION       -0x15
#define XGEN_ERROR_UNEXPECTED_MODULE        -0x16
#define XGEN_ERROR_UNEXPECTED_OPERATION     -0x17

    #define XGEN_DEFAULT_TTL                    60000
    #define XGEN_DEFAULT_GETMESSAGE_INTERVAL    5000

#elif defined(_TIBRV)

#define CMESSAGE_TRUE                   1
#define CMESSAGE_FALSE                  0

#define CMESSAGE_SUCCESS                0
#define CMESSAGE_WARNING                1
#define CMESSAGE_ERROR                  11
#define CMESSAGE_TIMEOUT                20


#define SIZE_MSG                        10
#define SIZE_SUBNO                      2
#define SIZE_SUBJECT                    255

    #define XGEN_DEFAULT_TTL                    60
    #define XGEN_DEFAULT_GETMESSAGE_INTERVAL    5

#endif

#define XGEN_TAG_HOSTNAME               ("HOSTNAME")
#define XGEN_TAG_HOSTADDR               ("HOSTADDR")

#define MSG_MODULE_NAME                 ("_MODULE_NAME")
#define MSG_SERVICE_NAME                ("_SERVICE_NAME")


#endif /* _MESSAGE_DEFINES_H */
