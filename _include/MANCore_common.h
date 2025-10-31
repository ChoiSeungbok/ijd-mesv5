/****************************************************************
*
*   Program ID  : MESplus Main Application Library
*
*   File Name   : MANCore_common.h
*
*   Description : MESplus Main common header file
*
*   Functions   :
*
*   Special Logic Notes  :
*
*   Modification History :
*
*   DATE             AUTHOR         DESCRIPTION
*  --------------   -------------- ------------------------------
*   2009/11/09       Aiden          Create
*
***************************************************************/

#ifndef _MANCORE_COMMON_H
#define _MANCORE_COMMON_H

#define MP_MESServer            "MESServer"
#define MP_RTDServer            "RTDServer"
#define MP_ADMServer            "ADMServer"

#define MP_PRV_SERVICE          "SERVICE             "

/* Function Prototypes */
extern void MESServer_add_service();

extern int MAIN_initialize_server(char *s_exe_app_name);
extern void MAIN_exit_program(void);
extern void MAIN_dispatch_message();

#endif /* _MANCORE_COMMON_H */

