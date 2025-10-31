/*******************************************************************************

    System      : MESplus
    Module      : COMCore
    File Name   : COMCore_defines.h
    Description : Common Macro definition of COMCore Library

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

#ifndef _COMCORE_DEFINES_H
#define _COMCORE_DEFINES_H

#if defined(WIN32) || defined(WIN64)

#elif defined(_HPUX_SOURCE)

#define TRUE                                   (1)
#define FALSE                                  (0)

#elif defined(__digital__) || defined(_AIX)

#endif

/****************************************************/
/* Macro Definition                                 */
/****************************************************/

/* Message Macro Definitions */
#define MP_MESSAGE_INVALID_ARGUMENT                 ( "MPE-0001" )
#define MP_MESSAGE_GETENV_ERROR                     ( "MPE-0002" )
#define MP_MESSAGE_GETCOMNAME_ERROR                 ( "MPE-0003" )
#define MP_MESSAGE_CTIME_ERROR                      ( "MPE-0004" )
#define MP_MESSAGE_INVALID_MONTH                    ( "MPE-0005" )

/* Macro Definition to initialize the status value & message. */
#define MP_STSINIT(sts_val,sts_msg) { *sts_val = MP_TRUE; memset(sts_msg, ' ', MP_SIZE_MSG); }


/****************************************************/
/* Return Value Definition                          */
/****************************************************/

/* True(Success) or False(Fail) or Warn */
#define MP_TRUE                                     ( 1 )
#define MP_FALSE                                    ( 0 )
#define MP_WARN                                     ( 2 )
#define MP_ERROR                                    ( 3 )

/* Success or Fail */
#define MP_SUCCESS_C                                ( '0' )
#define MP_FAIL_C                                   ( '1' )
#define MP_WARN_C                                   ( '2' )
#define MP_TROUBLE_C                                ( '3' )

/* Size Definitions */
#define MP_SIZE_MSG                                 ( 9 )
#define MP_SIZE_SHORT_STRING                        ( 64 )
#define MP_SIZE_MID_STRING                          ( 128 )
#define MP_SIZE_LONG_STRING                         ( 256 )
#define MP_SIZE_BIG_STRING                          ( 4000 )

#define MP_MODE_SECOND                              (0)
#define MP_MODE_MINUTE                              (1)
#define MP_MODE_HOUR                                (2)
#define MP_MODE_DAY                                 (3)

#define MP_SIZE_SERVER_NAME                         ( 30 )
#define MP_SIZE_CHANNEL                             ( 255 )
#define MP_SIZE_SUBNO                               ( 2 )
#define MP_SIZE_CLIENT_ID                           ( 255 )
#define MP_SIZE_SITE_ID                             ( 4 )    

/*  Names */
#define MP_COMPANY_NAME                             ( "Miracom Inc" )
#define MP_PRODUCT_NAME                             ( "MESplus" )
#define MP_REG_ROOT                                 ( "MESPLUS" )
#define MP_REG_DIRECTORIES                          ( "Directories" )
#define MP_REG_ENVIRONMENT                          ( "Environment" )
#define MP_REG_APPLICATION                          ( "Application" )
#define MP_SYSTEM_NAME                              ( "MESPLUS" )

/*  Misc Value Definitions */
#define MP_NULL                                     ( 0x00 )

#define MEMCPY(A,B)                                 memcpy(A, B, sizeof(A));

#endif  /* _COMCORE_DEFINES_H */
