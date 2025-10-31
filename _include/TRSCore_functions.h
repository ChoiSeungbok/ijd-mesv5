#ifndef _TRSCORE_FUNCTIONS_H
#define _TRSCORE_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "TRSCore_common.h"
#include <COMCore_memory.h>

//Add by J.S. 2011.12.27 for MAX_INT, MIN_INT....
#include <limits.h>

/*** Variables ****************************/
char c_validate_xml_value;

#ifndef _INLINE
#if defined(WIN32) || defined(WIN64)
    #define _INLINE static __inline
#else
    #define _INLINE static inline
#endif
#endif

TRSNodeList* TRS_create_list_node(const char* name);
int  TRS_string_length(const char *s_p, const size_t size_i);
void TRS_an_memcpy(char *dst, const char *src, const size_t size);
void TRS_toupper(char *d_p, const char *s_p, const size_t size_i);
int  TRS_strcmp_toupper(const char* value1, const char* value2);
void TRS_print_msg(char* s_function, char* s_msg, char* s_node_name);
void TRS_log_head(const char* s_msg);
void TRS_log_add(const char *title, const int type, ...);
void TRS_log_write();
void TRS_create_extra_info(TRSNode* node);
void UTF8ToAnsi(char *dest, const unsigned char *src, const size_t src_len);
void AnsiToUTF8(unsigned char *dest, const char *src, const size_t src_len);
void TRS_encrypt(char *dest, const unsigned char *src);
void TRS_decrypt(char *dest, const char *src);
void TRS_get_type_string(char* name, TRSDataType valueType);
void TRS_convert_escape(char *dest, const char *src);
TRSDataType TRS_get_data_type(const char* type);
void TRS_to_xml_string_type(char* type, TRSDataType valueType);

void TRS_add_node_length(TRSNode *node, int length);

unsigned char * base64_encode(const unsigned char *src, size_t len, size_t *out_len);
unsigned char * base64_decode(const unsigned char *src, size_t len, size_t *out_len);

int  TRS_atoi(const char *s_p, size_t size_i);
void TRS_itoa_zero(char *d_p, int data_i, size_t size_i);
//Modify by J.S. 2011.11.22
void TRS_get_local_utc_time(char *s_local, char *s_utc, int *i_isdst);
//End Modify
int  TRS_diff_time_sec(int *d_second, char *end_time_p, char *start_time_p);
int  TRS_calc_time(char *s_dest, char *s_src, int value);
int  TRS_convert_datetime(char *s_mdatetime, const char *s_fdatetime);
int  TRS_convert_mdatetime(char *s_mdatetime, const char *s_fdatetime);
int  TRS_get_log_level();


// For XML String Length
extern unsigned int TRS_get_member_xml_length(TRSNode *node);
extern unsigned int TRS_get_list_xml_length(const TRSNode *node);
extern unsigned int TRS_get_array_xml_length(const TRSNode *node);

#endif


