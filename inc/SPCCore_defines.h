#ifndef _SPCCORE_DEFINES_H
#define _SPCCORE_DEFINES_H

#include <float.h>

#define DOUBLE_NULL_DATA                (DBL_MAX)
#define DOUBLE_MIN_VALUE                (DBL_EPSILON * 10)
#define MINIMUM_VALUE                   (0.0000000005)

#define MP_STEP_TRAN                    ( 'T' )
#define MP_STEP_PEND                    ( 'P' )
#define MP_STEP_CONT                    ( 'N' )

#define RULE_1                            ( 'A' )
#define RULE_2                            ( 'B' )
#define RULE_3                            ( 'C' )
#define RULE_4                            ( 'D' )
#define RULE_5                            ( 'E' )
#define RULE_6                            ( 'F' )
#define RULE_7                            ( 'G' )
#define RULE_8                            ( 'H' )
#define RULE_9                            ( 'I' )
#define RULE_10                            ( 'J' )
#define RULE_11                            ( 'K' )
#define RULE_12                            ( 'L' )
#define RULE_13                            ( 'M' )
#define RULE_14                            ( 'N' )
#define RULE_15                            ( 'O' )
#define RULE_16                            ( 'P' )
#define RULE_17                            ( 'Q' )
#define RULE_18                            ( 'R' )
#define RULE_19                            ( 'S' )
#define RULE_20                            ( 'T' )
#define RULE_21                            ( 'U' )
#define RULE_22                            ( 'V' )
#define RULE_23                            ( 'W' )
#define RULE_24                            ( 'X' )
#define RULE_25                            ( 'Y' )
#define RULE_26                            ( 'Z' )

#define GRAPH_XBARR                        ("XBARR     ")
#define GRAPH_XBARS                        ("XBARS     ")
#define GRAPH_XRS                        ("XRS       ")
#define GRAPH_P                            ("P         ")
#define GRAPH_PN                         ("PN        ")
#define GRAPH_C                          ("C         ")
#define GRAPH_U                          ("U         ")
#define GRAPH_ZBARS                      ("ZBARS     ")
#define GRAPH_DELTAS                     ("DELTAS    ")

#define MP_SIZE_DESC                    ( 100 )
#define MP_SIZE_VALUE                    ( 39 )

#define MP_SPC_ALARM                    ("SPC_ALARM           ")

#define SPC_DEFAULT_AREA                ( "DEFAULT_AREA_ID     " )
#define SPC_MAIL_SEND_PROGRAM           ( "MpSendMail.exe" )
#define SPC_FROM_MAIL_ID                ( "SPC@MESplus" )
#define SPC_HEADER_TITLE                ( "SPC Mail" )
#define SPC_FROM_TAG                    ( "<FR>" )
#define SPC_FROM_END_TAG                ( "</FR>" )
#define SPC_TO_TAG                        ( "<TO>" )
#define SPC_TO_END_TAG                    ( "</TO>" )
#define SPC_HEADER_TAG                    ( "<HD>" )
#define SPC_HEADER_END_TAG                ( "</HD>" )
#define SPC_BODY_TAG                    ( "<BD>" )
#define SPC_BODY_END_TAG                ( "</BD>" )

#define SPC_SMS_SEND_PROGRAM            ( "MiracomSMS.exe" )


#endif /* _SPCCORE_DEFINES_H */
