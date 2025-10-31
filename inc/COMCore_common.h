/*******************************************************************************

    System      : MESplus
    Module      : COMCore
    File Name   : COMCore_common.h
    Description : external function prototype definition of COMCore Library

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

#ifndef _COMCORE_COMMON_H
#define _COMCORE_COMMON_H

/* 
** C Standard include files   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>

#if defined(_HPUX_SOURCE) || defined(__digital__) || defined(_AIX)

#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#elif defined(WIN32) || defined(WIN64)

#include <sys\types.h>
#include <sys\stat.h>
#include <windows.h>
#include <winreg.h>
#include <winsock.h>
#include <winbase.h>
#include <process.h>

#endif

#include <locale.h>
#include <fcntl.h>
#include <stdarg.h>

#include <math.h>

/* Common Library include files */
#include "COMCore_defines.h"

/* Function Prototype Definitions */
/*******************************************************************************
    1. String Manipulation
*******************************************************************************/
extern int COM_len_space(char *s_p, int size_i);
extern int COM_isspace(char *s_p, int size_i);
extern int COM_isnum(char *str, int size_i, char type, int negative_flag);
extern int COM_isdigit(char *s_p, int size_i);
extern int COM_isdigitminus(char *s_p, int size_i);
extern int COM_isdigitdot(char *s_p, int size_i);
extern int COM_isdigitdotminus(char *s_p, int size_i);
extern int COM_isnum_ns(char *str, char type, int negative_flag);
extern int COM_isdigit_ns(char *s_p);
extern int COM_isdigitminus_ns(char *s_p);
extern int COM_isdigitdot_ns(char *s_p);
extern int COM_isdigitdotminus_ns(char *s_p);
extern int COM_change_char(char *source, int source_length, char from_char, char to_char);
extern int COM_add_null(char *s_p, int size_i);
extern int COM_del_null(char *s_p, int size_i);
extern void COM_append(char *target_str, const char *source_str, int i_size);
extern void COM_2byte_memcpy(char *d_p, char *s_p, int size_i);
extern int COM_right(char *d_p, char *s_p, int s_size_i, int size_i);
extern int COM_strlike(char *source, char *str);
extern int COM_memlike(char *source, int source_length, char *str, int str_length);
extern void COM_toupper(char *d_p, char *s_p, int size_i);
extern void COM_tolower(char *d_p, char *s_p, int size_i);
extern void COM_ltrim(char *d_p, char *s_p, int size_i);
extern void COM_rtrim(char *d_p, char *s_p, int size_i);
extern int COM_search_string(char *s_p, int size_s, char *t_p, int size_t);
extern void COM_replace_string(char *d_p, int size_d, char *s_p, int size_s, int s_pos, int e_pos, char *r_p, int size_r);
extern int COM_len_space_back(char *s_p, int size_i);
extern int COM_string_length(char *s_p, int size_i);
extern int COM_isnullspace(char *s_p);
extern void COM_memcpy(char *d, char *s, int i_size);
extern void COM_memcpy_add_null(char *d,char *s,int size);
extern void COM_memcpy_del_null(char *d,char *s,int size);

/*******************************************************************************
    2. Type Conversion
*******************************************************************************/
extern int COM_atoi(char *s_p, int size_i);
extern long COM_atol(char *s_p, int size_i);
extern unsigned long COM_strtoul(char *s_p, int size_i);
extern double COM_atof(char *s_p, int size_i);
extern void COM_itoa(char *d_p, int data_i, int size_i);
extern void COM_itoa_left(char *d_p, int data_i, int size_i);
extern void COM_itoa_zero(char *d_p, int data_i, int size_i);
extern void COM_ltoa(char *d_p, long data_i32, int size_i);
extern void COM_ltoa_left(char *d_p, long data_i32, int size_i);
extern void COM_ltoa_zero(char *d_p, long data_i32, int size_i);
extern void COM_ultoa(char *d_p, unsigned long data_i32, int size_i);
extern void COM_ultoa_left(char *d_p, unsigned long data_i32, int size_i);
extern void COM_ultoa_zero(char *d_p, unsigned long data_i32, int size_i);
extern void COM_ftoa(char *d_p, float data_f, int size_i);
extern void COM_ftoa_second(char *d_p, float data_f, int size_i);    
extern void COM_dtoa(char *d_p, double data_d, int size_i);
extern char COM_int_to_one_char(int i_value, char c_sort_flag);
extern void COM_int_to_three_char(int i_value, char c_sort_flag, char *s_result);
extern void COM_time_to_five_char(char *s_time, char c_sort_flag, char *s_result);
extern double COM_dbl_round(double d_source, unsigned int i_scale, char up_down_flag);
/*******************************************************************************
    3. Date/Time Manipulation
*******************************************************************************/
extern void COM_get_date_time(char *d_p);
extern void COM_get_date_time_utc(char *d_p);
extern void COM_get_date_time_i(int *d_p, int *t_p);
extern void COM_get_date_time_i_utc(int *d_p, int *t_p);
extern int COM_get_date_time_tm(struct tm *cur_tm, char *datetime);
extern int COM_add_time_sec(char *d_time_p, char *s_time_p, int second);
extern int COM_add_time(char *d_time_p, char *s_time_p, char *add_time_p);
extern int COM_sub_time_sec(char *d_time_p, char *s_time_p, int second);
extern int COM_sub_time(char *d_time_p, char *s_time_p, char *sub_time_p);
extern int COM_diff_time_sec(int *i_second, char *end_time_p, char *start_time_p);
extern int COM_diff_time_millisec(double *d_second, char *end_time_p, char *start_time_p);
extern int COM_diff_time_tm(time_t *d_tm, char *end_time_p, char *start_time_p);
extern int COM_calc_time(char *d_time_p, char *from, int mode, int value);
extern int COM_isdatetime(char *s_date_time);
extern int COM_isdate(char *s_date);
extern int COM_istime(char *s_time);
extern void COM_get_date_time_msec(char *d_p);
extern void COM_get_date_time_msec_utc(char *d_p);
extern void COM_date_time_to_char(time_t s_p, char *d_p);
//Add by J.S. 2011.12.07 for DST
extern void COM_get_local_utc_time_dst(char *s_local, char *s_utc, int *i_isdst);
extern double COM_interval_millisec(char *s_from_time);
extern int COM_interval_sec(char *s_from_time);

/*******************************************************************************
    4. Environment
*******************************************************************************/
extern int COM_getenv(char *d_value, char *d_name);
extern int COM_putenv(char *s_name, char *s_value);
extern int COM_get_computer_name(char *str_name, int *l_len);

/*******************************************************************************
    5. INI File
*******************************************************************************/
extern int COM_get_init_file(char *str_server, char *str_com_inifile, char *str_svr_inifile);
extern int COM_get_init_value(char *str_filename, char *str_section, char *str_key, char *str_value, int *l_len);
extern int COM_get_init_file_ext(char *str_server, char *str_com_inifile, char *str_svr_inifile, char *str_section, char *str_key);

/*******************************************************************************
    6. ¾ÏÈ£È­
*******************************************************************************/
extern int COM_encrypt_one_way(char *d, char *s, int s_size, char *p, int p_size);
extern int COM_decrypt(char *d, char *s, int s_size, char *p, int p_size);

#endif  /* _COMCORE_COMMON_H */
