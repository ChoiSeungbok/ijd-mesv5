#ifndef _LOGCore_define_H
#define _LOGCore_define_H


#include <COMCore_common.h>
#include <DBC_null_data_type.h>


#define     MP_LOG_LONG_SIZE                  ( 10240 ) /* Byte */
#define     MP_LOG_BUFF_SIZE                  (  1024 ) /* Byte */

/*
**    Size Definition
*/
#define MP_LOG_MAX_LOG_FILE_SIZE              ( 81920 ) /* KBytes */
#define MP_LOG_DEFAULT_LOG_FILE_SIZE          ( 1024 )  /* KBytes */
#define MP_LOG_MAX_LOG_FILE_COUNT             ( 99 )    /* EA */
#define MP_LOG_DEFAULT_LOG_FILE_COUNT         ( 10 )    /* EA */


#define MP_LOG_MESSAGE_FILE_CREATE_ERROR            "MLE-0001"
#define MP_LOG_MESSAGE_INVALID_ENV_NAME_ERROR       "MLE-0002"
#define MP_LOG_MESSAGE_FAIL_TO_GET_LOG_DIRECTORY    "MLE-0003"
#define MP_LOG_MESSAGE_FAIL_TO_GET_COMPUTER_NAME    "MLE-0004"
#define MP_LOG_MESSAGE_DIRECTORY_CREATE_ERROR       "MLE-0005"
#define MP_LOG_MESSAGE_FIND_FIRST_FILE_ERROR        "MLE-0006"
#define MP_LOG_MESSAGE_PATH_NOT_FOUND_ERROR         "MLE-0007"

#define MP_LOG_FILENAME_EXTENSION               ( ".log" )
#define MP_LOG_XML_FILENAME_EXTENSION           ( ".xml" )

#define MP_LOG_HEADER_FILE_NAME                 ( "FILE NAME      :  " )
#define MP_LOG_HEADER_OPEN_TIME                 ( "OPEN TIME      :  " )
#define MP_LOG_HEADER_LOG_LEVEL_ALL_WRITE       ( "LOG LEVEL      :  ALL WRITE " )
#define MP_LOG_HEADER_LOG_LEVEL_WARN_WRITE      ( "LOG LEVEL      :  WARNING WRITE " )
#define MP_LOG_HEADER_LOG_LEVEL_ERROR_WRITE     ( "LOG LEVEL      :  ERROR WRITE " )
#define MP_LOG_HEADER_LOG_LEVEL_TIME_WRITE      ( "LOG LEVEL      :  TIME WRITE " )
#define MP_LOG_HEADER_LOG_FILE_SIZE             ( "LOG FILE SIZE  :  " )
#define MP_LOG_HEADER_LOG_FILE_COUNT            ( "LOG FILE COUNT :  " )

#define MP_LOG_HEAD_LOG_OPEN                    ( "Log file has been successfully opened !" )
#define MP_LOG_HEAD_LOG_CLOSE                   ( "Log file has been successfully closed !" )

#define MP_LOG_PROP_TIME                        ( "T=" )
#define MP_LOG_PROP_LOG_TYPE                    ( " Type=" )
#define MP_LOG_PROP_LOG_CATE                    ( " Category=" )
#define MP_LOG_PROP_LOG_ETYPE                   ( " EType=" )
#define MP_LOG_PROP_SUBJECT                     ( " Subject=" )
#define MP_LOG_PROP_SUB_NO                      ( "SUB=" )
#define MP_LOG_PROP_CLIENT_ID                   ( " CID=" )

/* File Name Offset */
#define MP_LOG_FILE_OFFSET_VERSION          ( 19 )    /* dev101_DEB1.UIS000_~01.log */
#define MP_LOG_FILE_OFFSET_VERSION_BACK     ( 6 )     /* 01.log */
#define MP_LOG_FILE_OFFSET_TIME_BACK        ( 17 )
#define MP_LOG_FILE_OFFSET_FILE_DEV_LEN     ( 18 )


#define MP_LOG_START                        "<<"
#define MP_LOG_WRITE                        "--"
#define MP_LOG_END                          ">>"

/* LOG Level */
#define     MP_LOG_LEVEL_DEBUG_WRITE        ( 0 )   /* 'D' */
#define     MP_LOG_LEVEL_ALL_WRITE          ( 1 )   /* 'A' */
#define     MP_LOG_LEVEL_WARN_WRITE         ( 2 )   /* 'W' */
#define     MP_LOG_LEVEL_ERROR_WRITE        ( 3 )   /* 'E' */ 

/* Log Mode */
#define     MP_LOG_MODE_PUBLIC              ( 1 )   /* 'U' */
#define     MP_LOG_MODE_PRIVATE             ( 2 )   /* 'R' */

/* Log Type */
#define     MP_LOG_FILE_OPEN       ('O')
#define     MP_LOG_FILE_CLOSE      ('C')

#define     MP_LOG_INFORMATION     ('I')
#define     MP_LOG_WARNING         ('W')
#define     MP_LOG_ERROR           ('E')
#define     MP_LOG_DEBUG           ('D')
#define     MP_LOG_SYSTEM          ('S')

/* Log Error Type */
#define     MP_LOG_E_EXISTENCE     ('E')
#define     MP_LOG_E_VALIDATION    ('V')
#define     MP_LOG_E_LOGIC         ('L')
#define     MP_LOG_E_SYSTEM        ('S')

/* Log Category */
#define     MP_LOG_CATE_VIEW       ('V')
#define     MP_LOG_CATE_TRANS      ('T')
#define     MP_LOG_CATE_SETUP      ('S')
#define     MP_LOG_CATE_SYSTEM     ('Y')
#define     MP_LOG_CATE_COMMON     ('C')

/* Log Argument Type */
#define     MP_INT                  (0)
#define     MP_FLT                  (1)
#define     MP_DBL                  (2)
#define     MP_CHR                  (3)
#define     MP_STR                  (4)
#define     MP_NSTR                 (5)
#define     MP_NVST                 (6)
#define     MP_LNG                  (7)

#define     MP_MINT                 (11)
#define     MP_MFLT                 (12)
#define     MP_MDBL                 (13)
#define     MP_MCHR                 (14)
#define     MP_MSTR                 (15)
#define     MP_MLNG                 (16)

#define     MP_MBOOL                (17)
#define     MP_MBIN                 (18)
#define     MP_MSHT                 (19)
#define     MP_MBYT                 (20)
#define     MP_MUBYT                (21)
#define     MP_MUSHT                (22)
#define     MP_MUINT                (23)
#define     MP_MULNG                (24)
#define     MP_MDATE                (25)

/*
**    Log File Name related
*/
#if defined(_HPUX_SOURCE) || defined(__digital__) 

#define MP_LOG_DIRECTORY_TILT                    ( '/' )

#elif defined(_AIX)

#define MP_LOG_DIRECTORY_TILT                    ( '/' )

#elif defined(WIN32) || defined(WIN64)

#define MP_LOG_DIRECTORY_TILT                    ( '\\' )

#endif

#endif //_LOGCore_define_H
