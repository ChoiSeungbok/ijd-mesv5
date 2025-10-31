#ifndef _TRS_COMMON_H
#define _TRS_COMMON_H

#include "TRSCore_defines.h"
#include <DBC_null_data_type.h>

/******************************************************/
/* ProtoType of TRS Common Function                   */
/******************************************************/
extern void TRS_initialize();
extern void TRS_add_flex_header(TRSNode *node, const char *name, const size_t length);
extern void TRS_set_char_locale(const char* s_locale);
extern void TRS_set_xml_value_validation(const char c_validate_xml_value_flag);
extern void TRS_set_time_zone_offset(const char* s_offset);
//Add by J.S. 2011.11.22
extern void TRS_set_time_zone_offset_ignore(const char c_ignore);
extern void TRS_set_short_XML_date_format(const char c_short_XML_date_format_flag);
//End Add
extern void TRS_set_log_level(const int i_log_level);
extern void TRS_set_case_sensitive_name(const char c_case_sensitive_name_flag);
/* OSS 검증으로 주석처리함 */
//***/extern void TRS_set_not_use_iconv_method(const char c_not_use_iconv_method_flag);

/******************************************************/
/* ProtoType of TRS Log Function Pointer              */
/******************************************************/
typedef void (*TRS_log_add_head_type)(const char *head);
typedef void (*TRS_log_add_field_type)(const char *title, const int type, ...);
typedef void (*TRS_log_write_type)(char c_log_type, char c_log_error_type, char c_log_category);

extern void TRS_set_log_head_handler(const TRS_log_add_head_type fp);
extern void TRS_set_log_add_handler(const TRS_log_add_field_type fp);
extern void TRS_set_log_write_handler(const TRS_log_write_type fp);

/******************************************************/
/* ProtoType of Function Pointer                      */
/******************************************************/
extern TRSNode*     TRS_add_string(TRSNode *node, const char* name, const char* value, const size_t length);
extern TRSNode*     TRS_add_nstring(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_add_enc_string(TRSNode *node, const char* name, const char* value, const size_t length);
extern TRSNode*     TRS_add_enc_nstring(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_add_char(TRSNode *node, const char* name, const char value);
extern TRSNode*     TRS_add_binary(TRSNode *node, const char* name, const unsigned char value);
extern TRSNode*     TRS_add_boolean(TRSNode *node, const char* name, const int value);
extern TRSNode*     TRS_add_ubyte(TRSNode *node, const char* name, const unsigned char value);
extern TRSNode*     TRS_add_ushort(TRSNode *node, const char* name, const unsigned short value);
extern TRSNode*     TRS_add_uint(TRSNode *node, const char* name, const unsigned int value);
extern TRSNode*     TRS_add_ulong(TRSNode *node, const char* name, const unsigned long value);
extern TRSNode*     TRS_add_float(TRSNode *node, const char* name, const float value);
extern TRSNode*     TRS_add_double(TRSNode *node, const char* name, const double value);
extern TRSNode*     TRS_add_byte(TRSNode *node, const char* name, const char value);
extern TRSNode*     TRS_add_short(TRSNode *node, const char* name, const short value);
extern TRSNode*     TRS_add_int(TRSNode *node, const char* name, const int value);
extern TRSNode*     TRS_add_long(TRSNode *node, const char* name, const long value);
extern TRSNode*     TRS_add_datetime(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_add_datetime_f(TRSNode *node, const char* name, const char* value, const char* format);
extern TRSNode*     TRS_add_blob(TRSNode *node, const char* name, const unsigned char* value, const size_t length);
extern TRSNode*     TRS_add_object(TRSNode *node, const char* name, const void* value);

extern TRSNode*     TRS_add_member(TRSNode *node, const char* name, const TRSDataType type, ...);
extern TRSNode*     TRS_add_node(TRSNode *node, const char* name);
extern void         TRS_add_made_node(TRSNode *to_node, TRSNode *node);
extern TRSNode*     TRS_add_array(TRSNode *node, const char *name, const TRSDataType array_type);
extern int          TRS_add_item(TRSNode *node, ...);
extern int          TRS_add_array_item(TRSNode *node, char *name, ...);

extern int          TRS_add_item_for_null(TRSNode *node, ...);
extern int          TRS_add_array_item_for_null(TRSNode *node, char *name, ...);

extern void*        TRS_copy(char* dst, const size_t length, const TRSNode *node, const char* name);
extern unsigned int TRS_calculate_msg_length(const TRSNode *node);
extern void         TRS_to_xml_string(char* xmlString, const TRSNode *node);
extern int          TRS_parse(TRSNode *node, const char* xmlString, const size_t len, char* s_err_msg);

extern void*        TRS_copy_for_null(MSTRING* dest, const TRSNode *node, const char* name);

extern int          TRS_memcmp(const TRSNode *node, const char* name, const char* value, const size_t length);
extern int          TRS_strcmp(const TRSNode *node, const char* name, const char* value);
extern int          TRS_strtcmp(const TRSNode *node1, const char* name1, const TRSNode *node2, const char* name2);

extern int          TRS_memcmp_for_null(const TRSNode *node, const char* name, MSTRING value);

extern TRSNode*     TRS_create_node(const char* name);
extern void         TRS_free_node(TRSNode *node);
extern void         TRS_init_node(TRSNode *node);

extern TRSNode*     TRS_get_member(const TRSNode *node, const char* member_name);
extern TRSNode**    TRS_get_list(const TRSNode *node, const char* list_name);
extern int          TRS_get_item_count(const TRSNode *node, const char* list_name);
extern TRSNode*     TRS_get_array(const TRSNode *node, const char* array_name);

extern char*            TRS_get_string(const TRSNode *node, const char* name);
extern char             TRS_get_char(const TRSNode *node, const char* name);
extern unsigned char    TRS_get_binary(const TRSNode *node, const char* name);
extern int              TRS_get_boolean(const TRSNode *node, const char* name);
extern unsigned char    TRS_get_ubyte(const TRSNode *node, const char* name);
extern unsigned short   TRS_get_ushort(const TRSNode *node, const char* name);
extern unsigned int     TRS_get_uint(const TRSNode *node, const char* name);
extern unsigned long    TRS_get_ulong(const TRSNode *node, const char* name);
extern float            TRS_get_float(const TRSNode *node, const char* name);
extern double           TRS_get_double(const TRSNode *node, const char* name);
extern char             TRS_get_byte(const TRSNode *node, const char* name);
extern short            TRS_get_short(const TRSNode *node, const char* name);
extern int              TRS_get_int(const TRSNode *node, const char* name);
extern long             TRS_get_long(const TRSNode *node, const char* name);
extern char*            TRS_get_datetime(const TRSNode *node, const char* name);
extern void             TRS_get_blob(const TRSNode *node, const char* name, unsigned char** dest, long* length);
extern void*            TRS_get_object(const TRSNode *node, const char* name);

extern void         TRS_get_string_param(const TRSNode *node, const char* name, char* dest);
extern void         TRS_get_string_param_fs(const TRSNode *node, const char* name, char* dest, const size_t length);
extern void         TRS_get_char_param(const TRSNode *node, const char* name, char* dest);
extern void         TRS_get_binary_param(const TRSNode *node, const char* name, unsigned char* dest);
extern void         TRS_get_boolean_param(const TRSNode *node, const char* name, int* dest);
extern void         TRS_get_ubyte_param(const TRSNode *node, const char* name, unsigned char* dest);
extern void         TRS_get_ushort_param(const TRSNode *node, const char* name, unsigned short* dest);
extern void         TRS_get_uint_param(const TRSNode *node, const char* name, unsigned int* dest);
extern void         TRS_get_ulong_param(const TRSNode *node, const char* name, unsigned long* dest);
extern void         TRS_get_float_param(const TRSNode *node, const char* name, float* dest);
extern void         TRS_get_double_param(const TRSNode *node, const char* name, double* dest);
extern void         TRS_get_byte_param(const TRSNode *node, const char* name, char* dest);
extern void         TRS_get_short_param(const TRSNode *node, const char* name, short* dest);
extern void         TRS_get_int_param(const TRSNode *node, const char* name, int* dest);
extern void         TRS_get_long_param(const TRSNode *node, const char* name, long* dest);
extern void         TRS_get_datetime_param(const TRSNode *node, const char* name, char* dest);
extern void         TRS_get_object_param(const TRSNode *node, const char* name, void* dest);

extern void         TRS_add_out_msg_status_value(TRSNode *node, const char status);
extern void         TRS_add_out_msg_msgcode(TRSNode *node, const char* msgCode);
extern void         TRS_add_out_msg_message(TRSNode *node, const char* msg);
extern void         TRS_add_out_msg_msgcate(TRSNode *node, const char category);
extern void         TRS_add_out_msg_fieldmsg(TRSNode *node, const char* name, TRSDataType type, ...);
extern void         TRS_add_out_msg_dberrmsg(TRSNode *node, const char* dberrmsg);

extern char*        TRS_get_in_msg_passport(const TRSNode *node);
extern char         TRS_get_in_msg_language(const TRSNode *node);
extern char*        TRS_get_in_msg_factory(const TRSNode *node);
extern char*        TRS_get_in_msg_userid(const TRSNode *node);
extern char*        TRS_get_in_msg_password(const TRSNode *node);
extern char         TRS_get_in_msg_procstep(const TRSNode *node);

extern void         TRS_set_out_msg_status_value(TRSNode *node, const char status);
extern void         TRS_set_out_msg_msgcode(TRSNode *node, const char* msgCode);
extern void         TRS_set_out_msg_message(TRSNode *node, const char* msg);
extern void         TRS_set_out_msg_msgcate(TRSNode *node, const char category);
extern void         TRS_set_out_msg_fieldmsg(TRSNode *node, const char* name, TRSDataType type, ...);
extern void         TRS_set_out_msg_dberrmsg(TRSNode *node, const char* dberrmsg);

extern TRSNode*     TRS_set_string(TRSNode *node, const char* name, const char* value, const size_t length);
extern TRSNode*     TRS_set_nstring(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_set_enc_string(TRSNode *node, const char* name, const char* value, const size_t length);
extern TRSNode*     TRS_set_enc_nstring(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_set_char(TRSNode *node, const char* name, const char value);
extern TRSNode*     TRS_set_binary(TRSNode *node, const char* name, const unsigned char value);
extern TRSNode*     TRS_set_boolean(TRSNode *node, const char* name, const int value);
extern TRSNode*     TRS_set_ubyte(TRSNode *node, const char* name, const unsigned char value);
extern TRSNode*     TRS_set_ushort(TRSNode *node, const char* name, const unsigned short value);
extern TRSNode*     TRS_set_uint(TRSNode *node, const char* name, const unsigned int value);
extern TRSNode*     TRS_set_ulong(TRSNode *node, const char* name, const unsigned long value);
extern TRSNode*     TRS_set_float(TRSNode *node, const char* name, const float value);
extern TRSNode*     TRS_set_double(TRSNode *node, const char* name, const double value);
extern TRSNode*     TRS_set_byte(TRSNode *node, const char* name, const char value);
extern TRSNode*     TRS_set_short(TRSNode *node, const char* name, const short value);
extern TRSNode*     TRS_set_int(TRSNode *node, const char* name, const int value);
extern TRSNode*     TRS_set_long(TRSNode *node, const char* name, const long value);
extern TRSNode*     TRS_set_datetime(TRSNode *node, const char* name, const char* value);
extern TRSNode*     TRS_set_datetime_f(TRSNode *node, const char* name, const char* value, const char* format);
extern TRSNode*     TRS_set_blob(TRSNode *node, const char* name, const unsigned char* value, const size_t length);
extern TRSNode*     TRS_set_object(TRSNode *node, const char* name, const void* value);

extern void         TRS_clone(TRSNode *dest, const TRSNode *src);
extern void         TRS_sync(TRSNode *dest, const TRSNode *src);
extern void         TRS_copy_members(TRSNode *dest, const TRSNode *src);

extern void         TRS_add_member_to_log(const TRSNode *node, const char* name);
extern void         TRS_add_all_member_to_log(const TRSNode *node);

extern TRSNode*     TRS_add_string_for_null(TRSNode *node, const char* name, const MSTRING value);
extern TRSNode*     TRS_add_enc_string_for_null(TRSNode *node, const char* name, const MSTRING value);
extern TRSNode*     TRS_add_char_for_null(TRSNode *node, const char* name, const MCHAR value);
extern TRSNode*     TRS_add_binary_for_null(TRSNode *node, const char* name, const MBINARY value);
extern TRSNode*     TRS_add_boolean_for_null(TRSNode *node, const char* name, const MBOOLEAN value);
extern TRSNode*     TRS_add_ubyte_for_null(TRSNode *node, const char* name, const MUBYTE value);
extern TRSNode*     TRS_add_ushort_for_null(TRSNode *node, const char* name, const MUSHORT value);
extern TRSNode*     TRS_add_uint_for_null(TRSNode *node, const char* name, const MUINT value);
extern TRSNode*     TRS_add_ulong_for_null(TRSNode *node, const char* name, const MULONG value);
extern TRSNode*     TRS_add_float_for_null(TRSNode *node, const char* name, const MFLOAT value);
extern TRSNode*     TRS_add_double_for_null(TRSNode *node, const char* name, const MDOUBLE value);
extern TRSNode*     TRS_add_byte_for_null(TRSNode *node, const char* name, const MBYTE value);
extern TRSNode*     TRS_add_short_for_null(TRSNode *node, const char* name, const MSHORT value);
extern TRSNode*     TRS_add_int_for_null(TRSNode *node, const char* name, const MINT value);
extern TRSNode*     TRS_add_long_for_null(TRSNode *node, const char* name, const MLONG value);
extern TRSNode*     TRS_add_datetime_for_null(TRSNode *node, const char* name, const MDATETIME value);
extern TRSNode*     TRS_add_blob_for_null(TRSNode *node, const char* name, const MBLOB value);

extern MSTRING      TRS_get_string_for_null(const TRSNode *node, const char* name);
extern MCHAR        TRS_get_char_for_null(const TRSNode *node, const char* name);
extern MBINARY      TRS_get_binary_for_null(const TRSNode *node, const char* name);
extern MBOOLEAN     TRS_get_boolean_for_null(const TRSNode *node, const char* name);
extern MUBYTE       TRS_get_ubyte_for_null(const TRSNode *node, const char* name);
extern MUSHORT      TRS_get_ushort_for_null(const TRSNode *node, const char* name);
extern MUINT        TRS_get_uint_for_null(const TRSNode *node, const char* name);
extern MULONG       TRS_get_ulong_for_null(const TRSNode *node, const char* name);
extern MFLOAT       TRS_get_float_for_null(const TRSNode *node, const char* name);
extern MDOUBLE      TRS_get_double_for_null(const TRSNode *node, const char* name);
extern MBYTE        TRS_get_byte_for_null(const TRSNode *node, const char* name);
extern MSHORT       TRS_get_short_for_null(const TRSNode *node, const char* name);
extern MINT         TRS_get_int_for_null(const TRSNode *node, const char* name);
extern MLONG        TRS_get_long_for_null(const TRSNode *node, const char* name);
extern MDATETIME    TRS_get_datetime_for_null(const TRSNode *node, const char* name);
extern MBLOB        TRS_get_blob_for_null(const TRSNode *node, const char* name);

extern void         TRS_get_string_param_for_null(const TRSNode *node, const char* name, MSTRING* dest);
extern void         TRS_get_char_param_for_null(const TRSNode *node, const char* name, MCHAR* dest);
extern void         TRS_get_binary_param_for_null(const TRSNode *node, const char* name, MBINARY* dest);
extern void         TRS_get_boolean_param_for_null(const TRSNode *node, const char* name, MBOOLEAN* dest);
extern void         TRS_get_ubyte_param_for_null(const TRSNode *node, const char* name, MUBYTE* dest);
extern void         TRS_get_ushort_param_for_null(const TRSNode *node, const char* name, MUSHORT* dest);
extern void         TRS_get_uint_param_for_null(const TRSNode *node, const char* name, MUINT* dest);
extern void         TRS_get_ulong_param_for_null(const TRSNode *node, const char* name, MULONG* dest);
extern void         TRS_get_float_param_for_null(const TRSNode *node, const char* name, MFLOAT* dest);
extern void         TRS_get_double_param_for_null(const TRSNode *node, const char* name, MDOUBLE* dest);
extern void         TRS_get_byte_param_for_null(const TRSNode *node, const char* name, MBYTE* dest);
extern void         TRS_get_short_param_for_null(const TRSNode *node, const char* name, MSHORT* dest);
extern void         TRS_get_int_param_for_null(const TRSNode *node, const char* name, MINT* dest);
extern void         TRS_get_long_param_for_null(const TRSNode *node, const char* name, MLONG* dest);
extern void         TRS_get_datetime_param_for_null(const TRSNode *node, const char* name, MDATETIME* dest);
extern void         TRS_get_blob_param_for_null(const TRSNode *node, const char* name, MBLOB* dest);

extern TRSNode*     TRS_set_string_for_null(TRSNode *node, const char* name, const MSTRING value);
extern TRSNode*     TRS_set_enc_string_for_null(TRSNode *node, const char* name, const MSTRING value);
extern TRSNode*     TRS_set_char_for_null(TRSNode *node, const char* name, const MCHAR value);
extern TRSNode*     TRS_set_binary_for_null(TRSNode *node, const char* name, const MBINARY value);
extern TRSNode*     TRS_set_boolean_for_null(TRSNode *node, const char* name, const MBOOLEAN value);
extern TRSNode*     TRS_set_ubyte_for_null(TRSNode *node, const char* name, const MUBYTE value);
extern TRSNode*     TRS_set_ushort_for_null(TRSNode *node, const char* name, const MUSHORT value);
extern TRSNode*     TRS_set_uint_for_null(TRSNode *node, const char* name, const MUINT value);
extern TRSNode*     TRS_set_ulong_for_null(TRSNode *node, const char* name, const MULONG value);
extern TRSNode*     TRS_set_float_for_null(TRSNode *node, const char* name, const MFLOAT value);
extern TRSNode*     TRS_set_double_for_null(TRSNode *node, const char* name, const MDOUBLE value);
extern TRSNode*     TRS_set_byte_for_null(TRSNode *node, const char* name, const MBYTE value);
extern TRSNode*     TRS_set_short_for_null(TRSNode *node, const char* name, const MSHORT value);
extern TRSNode*     TRS_set_int_for_null(TRSNode *node, const char* name, const MINT value);
extern TRSNode*     TRS_set_long_for_null(TRSNode *node, const char* name, const MLONG value);
extern TRSNode*     TRS_set_datetime_for_null(TRSNode *node, const char* name, const MDATETIME value);
extern TRSNode*     TRS_set_blob_for_null(TRSNode *node, const char* name, const MBLOB value);

extern TRSNode*     TRS_insert_member(TRSNode *node, const char *name, const char override_flag, const int index, const TRSDataType type, ...);
extern TRSNode*     TRS_insert_member_for_null(TRSNode *node, const char *name, const char override_flag, const int index, const TRSDataType type, ...);

extern int          TRS_get_parent_path(const TRSNode *node, const char *s_name, char *s_path);
extern int          TRS_get_member_path(const TRSNode *node, const char *s_name, char *s_path);
extern int          TRS_get_node_path(const TRSNode *node, char *s_path);



typedef struct
{    
    TRSNode*     (*add_string)(TRSNode *node, const char* name, const char* value, const size_t length);
    TRSNode*     (*add_nstring)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*add_enc_string)(TRSNode *node, const char* name, const char* value, const size_t length);
    TRSNode*     (*add_enc_nstring)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*add_char)(TRSNode *node, const char* name, const char value);
    TRSNode*     (*add_binary)(TRSNode *node, const char* name, const unsigned char value);
    TRSNode*     (*add_boolean)(TRSNode *node, const char* name, const int value);
    TRSNode*     (*add_ubyte)(TRSNode *node, const char* name, const unsigned char value);
    TRSNode*     (*add_ushort)(TRSNode *node, const char* name, const unsigned short value);
    TRSNode*     (*add_uint)(TRSNode *node, const char* name, const unsigned int value);
    TRSNode*     (*add_ulong)(TRSNode *node, const char* name, const unsigned long value);
    TRSNode*     (*add_float)(TRSNode *node, const char* name, const float value);
    TRSNode*     (*add_double)(TRSNode *node, const char* name, const double value);
    TRSNode*     (*add_byte)(TRSNode *node, const char* name, const char value);
    TRSNode*     (*add_short)(TRSNode *node, const char* name, const short value);
    TRSNode*     (*add_int)(TRSNode *node, const char* name, const int value);
    TRSNode*     (*add_long)(TRSNode *node, const char* name, const long value);
    TRSNode*     (*add_datetime)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*add_datetime_f)(TRSNode *node, const char* name, const char* value, const char* format);
    TRSNode*     (*add_blob)(TRSNode *node, const char* name, const unsigned char* value, const size_t length);
    TRSNode*     (*add_object)(TRSNode *node, const char* name, const void* value);

    
    TRSNode*     (*add_member)(TRSNode *node, const char* name, const TRSDataType type, ...);
    TRSNode*     (*add_node)(TRSNode *node, const char* name);
    void         (*add_made_node)(TRSNode *to_node, TRSNode *node);
    TRSNode*     (*add_array)(TRSNode *node, const char *name, const TRSDataType array_type);
    int          (*add_item)(TRSNode *node, ...);
    int          (*add_array_item)(TRSNode *node, char *name, ...);

    void*        (*copy)(char* dest, const size_t length, const TRSNode *node, const char* name);
    unsigned int (*calculate_msg_length)(const TRSNode *node);
    void         (*to_xml_string)(char* xmlString, const TRSNode *node);
    int          (*parse)(TRSNode *node, const char* xmlString, const size_t len, char* s_err_msg);
    
    int          (*mem_cmp)(const TRSNode *node, const char* name, const char* value, const size_t length);
    int          (*str_cmp)(const TRSNode *node, const char* name, const char* value);
    int          (*str_tcmp)(const TRSNode *node1, const char* name1, const TRSNode *node2, const char* name2);

    TRSNode*     (*create_node)(const char* node_name);
    void         (*free_node)(TRSNode *node);
    void         (*init_node)(TRSNode *node);
    
    TRSNode*     (*get_member)(const TRSNode *node, const char* member_name);
    TRSNode**    (*get_list)(const TRSNode *node, const char* list_name);
    int          (*get_item_count)(const TRSNode *node, const char* list_name);
    TRSNode*     (*get_array)(const TRSNode *node, const char* array_name);

    char*           (*get_string)(const TRSNode *node, const char* name);
    char            (*get_char)(const TRSNode *node, const char* name);
    unsigned char   (*get_binary)(const TRSNode *node, const char* name);
    int             (*get_boolean)(const TRSNode *node, const char* name);
    unsigned char   (*get_ubyte)(const TRSNode *node, const char* name);
    unsigned short  (*get_ushort)(const TRSNode *node, const char* name);
    unsigned int    (*get_uint)(const TRSNode *node, const char* name);
    unsigned long   (*get_ulong)(const TRSNode *node, const char* name);
    float           (*get_float)(const TRSNode *node, const char* name);
    double          (*get_double)(const TRSNode *node, const char* name);
    char            (*get_byte)(const TRSNode *node, const char* name);
    short           (*get_short)(const TRSNode *node, const char* name);
    int             (*get_int)(const TRSNode *node, const char* name);
    long            (*get_long)(const TRSNode *node, const char* name);
    char*           (*get_datetime)(const TRSNode *node, const char* name);
    void            (*get_blob)(const TRSNode *node, const char* name, unsigned char** dest, long* length);
    void*           (*get_object)(const TRSNode *node, const char* name);
        
    void         (*get_string_param)(const TRSNode *node, const char* name, char* dest);
    void         (*get_string_param_fs)(const TRSNode *node, const char* name, char *dest, const size_t length);    
    void         (*get_char_param)(const TRSNode *node, const char* name, char* dest);
    void         (*get_binary_param)(const TRSNode *node, const char* name, unsigned char* dest);
    void         (*get_boolean_param)(const TRSNode *node, const char* name, int* dest);
    void         (*get_ubyte_param)(const TRSNode *node, const char* name, unsigned char* dest);
    void         (*get_ushort_param)(const TRSNode *node, const char* name, unsigned short* dest);
    void         (*get_uint_param)(const TRSNode *node, const char* name, unsigned int* dest);
    void         (*get_ulong_param)(const TRSNode *node, const char* name, unsigned long* dest);
    void         (*get_float_param)(const TRSNode *node, const char* name, float* dest);
    void         (*get_double_param)(const TRSNode *node, const char* name, double* dest);
    void         (*get_byte_param)(const TRSNode *node, const char* name, char* dest);
    void         (*get_short_param)(const TRSNode *node, const char* name, short* dest);
    void         (*get_int_param)(const TRSNode *node, const char* name, int* dest);
    void         (*get_long_param)(const TRSNode *node, const char* name, long* dest);
    void         (*get_datetime_param)(const TRSNode *node, const char* name, char* dest);
    void         (*get_object_param)(const TRSNode *node, const char* name, void* dest);

    void         (*add_status_value)(TRSNode *node, const char status);
    void         (*add_msgcode)(TRSNode *node, const char* msgCode);
    void         (*add_message)(TRSNode *node, const char* msg);
    void         (*add_msgcate)(TRSNode *node, const char category);
    void         (*add_fieldmsg)(TRSNode *node, const char* name, TRSDataType type, ...);
    void         (*add_dberrmsg)(TRSNode *node, const char* dberrmsg);
    
    char*        (*get_passport)(const TRSNode *node);
    char         (*get_language)(const TRSNode *node);
    char*        (*get_factory)(const TRSNode *node);
    char*        (*get_userid)(const TRSNode *node);
    char*        (*get_password)(const TRSNode *node);
    char         (*get_procstep)(const TRSNode *node);
    
    void         (*set_status_value)(TRSNode *node, const char status);
    void         (*set_msgcode)(TRSNode *node, const char* msgCode);
    void         (*set_message)(TRSNode *node, const char* msg);
    void         (*set_msgcate)(TRSNode *node, const char category);
    void         (*set_fieldmsg)(TRSNode *node, const char* name, TRSDataType type, ...);
    void         (*set_dberrmsg)(TRSNode *node, const char* dberrmsg);
    
    TRSNode*     (*set_string)(TRSNode *node, const char* name, const char* value, const size_t length);
    TRSNode*     (*set_nstring)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*set_enc_string)(TRSNode *node, const char* name, const char* value, const size_t length);
    TRSNode*     (*set_enc_nstring)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*set_char)(TRSNode *node, const char* name, const char value);
    TRSNode*     (*set_binary)(TRSNode *node, const char* name, const unsigned char value);
    TRSNode*     (*set_boolean)(TRSNode *node, const char* name, const int value);
    TRSNode*     (*set_ubyte)(TRSNode *node, const char* name, const unsigned char value);
    TRSNode*     (*set_ushort)(TRSNode *node, const char* name, const unsigned short value);
    TRSNode*     (*set_uint)(TRSNode *node, const char* name, const unsigned int value);
    TRSNode*     (*set_ulong)(TRSNode *node, const char* name, const unsigned long value);
    TRSNode*     (*set_float)(TRSNode *node, const char* name, const float value);
    TRSNode*     (*set_double)(TRSNode *node, const char* name, const double value);
    TRSNode*     (*set_byte)(TRSNode *node, const char* name, const char value);
    TRSNode*     (*set_short)(TRSNode *node, const char* name, const short value);
    TRSNode*     (*set_int)(TRSNode *node, const char* name, const int value);
    TRSNode*     (*set_long)(TRSNode *node, const char* name, const long value);
    TRSNode*     (*set_datetime)(TRSNode *node, const char* name, const char* value);
    TRSNode*     (*set_datetime_f)(TRSNode *node, const char* name, const char* value, const char* format);
    TRSNode*     (*set_blob)(TRSNode *node, const char* name, const unsigned char* value, const size_t length);
    TRSNode*     (*set_object)(TRSNode *node, const char* name, const void* value);

    void         (*clone)(TRSNode *dest, const TRSNode *src);
    void         (*sync)(TRSNode *dest, const TRSNode *src);
    void         (*copy_members)(TRSNode *dest, const TRSNode *src);
    void         (*log_add)(const TRSNode *node, const char* name);
    void         (*log_add_all_members)(const TRSNode *node);

    TRSNode*     (*insert_member)(TRSNode *node, const char *name, const char override_flag, const int index, const TRSDataType type, ...);

    int          (*get_parent_path)(const TRSNode *node, const char *s_name, char *s_path);
    int          (*get_member_path)(const TRSNode *node, const char *s_name, char *s_path);
    int          (*get_node_path)(const TRSNode *node, char *s_path);

}TRSFunctions;

static const TRSFunctions TRS = {

    TRS_add_string,
    TRS_add_nstring,
    TRS_add_enc_string,
    TRS_add_enc_nstring,
    TRS_add_char,
    TRS_add_binary,
    TRS_add_boolean,
    TRS_add_ubyte,
    TRS_add_ushort,
    TRS_add_uint,
    TRS_add_ulong,
    TRS_add_float,
    TRS_add_double,
    TRS_add_byte,
    TRS_add_short,
    TRS_add_int,
    TRS_add_long,
    TRS_add_datetime,
    TRS_add_datetime_f,
    TRS_add_blob,
    TRS_add_object,

    TRS_add_member,
    TRS_add_node,
    TRS_add_made_node,
    TRS_add_array,
    TRS_add_item,
    TRS_add_array_item,
    
    TRS_copy,
    TRS_calculate_msg_length,

    TRS_to_xml_string,
    TRS_parse,

    TRS_memcmp,
    TRS_strcmp,
    TRS_strtcmp,

    TRS_create_node,
    TRS_free_node,
    TRS_init_node,
    
    TRS_get_member,
    TRS_get_list,
    TRS_get_item_count,
    TRS_get_array,
    
    TRS_get_string,
    TRS_get_char,
    TRS_get_binary,
    TRS_get_boolean,
    TRS_get_ubyte,
    TRS_get_ushort,
    TRS_get_uint,
    TRS_get_ulong,
    TRS_get_float,
    TRS_get_double,
    TRS_get_byte,
    TRS_get_short,
    TRS_get_int,
    TRS_get_long,
    TRS_get_datetime,
    TRS_get_blob,
    TRS_get_object,
    
    TRS_get_string_param,
    TRS_get_string_param_fs,
    TRS_get_char_param,
    TRS_get_binary_param,
    TRS_get_boolean_param,
    TRS_get_ubyte_param,
    TRS_get_ushort_param,
    TRS_get_uint_param,
    TRS_get_ulong_param,
    TRS_get_float_param,
    TRS_get_double_param,
    TRS_get_byte_param,
    TRS_get_short_param,
    TRS_get_int_param,
    TRS_get_long_param,
    TRS_get_datetime_param,
    TRS_get_object_param,

    TRS_add_out_msg_status_value,
    TRS_add_out_msg_msgcode,
    TRS_add_out_msg_message,
    TRS_add_out_msg_msgcate,
    TRS_add_out_msg_fieldmsg,
    TRS_add_out_msg_dberrmsg,
    
    TRS_get_in_msg_passport,
    TRS_get_in_msg_language,
    TRS_get_in_msg_factory,
    TRS_get_in_msg_userid,
    TRS_get_in_msg_password,
    TRS_get_in_msg_procstep,
    
    TRS_set_out_msg_status_value,
    TRS_set_out_msg_msgcode,
    TRS_set_out_msg_message,
    TRS_set_out_msg_msgcate,
    TRS_set_out_msg_fieldmsg,
    TRS_set_out_msg_dberrmsg,
    
    TRS_set_string,
    TRS_set_nstring,
    TRS_set_enc_string,
    TRS_set_enc_nstring,
    TRS_set_char,
    TRS_set_binary,
    TRS_set_boolean,
    TRS_set_ubyte,
    TRS_set_ushort,
    TRS_set_uint,
    TRS_set_ulong,
    TRS_set_float,
    TRS_set_double,
    TRS_set_byte,
    TRS_set_short,
    TRS_set_int,
    TRS_set_long,
    TRS_set_datetime,
    TRS_set_datetime_f,
    TRS_set_blob,
    TRS_set_object,

    TRS_clone,
    TRS_sync,
    TRS_copy_members,
    TRS_add_member_to_log,
    TRS_add_all_member_to_log,

    TRS_insert_member,

    TRS_get_parent_path,
    TRS_get_member_path,
    TRS_get_node_path
};


typedef struct
{    
    TRSNode*     (*add_string)(TRSNode *node, const char* name, const MSTRING value);
    TRSNode*     (*add_enc_string)(TRSNode *node, const char* name, const MSTRING value);
    TRSNode*     (*add_char)(TRSNode *node, const char* name, const MCHAR value);
    TRSNode*     (*add_binary)(TRSNode *node, const char* name, const MBINARY value);
    TRSNode*     (*add_boolean)(TRSNode *node, const char* name, const MBOOLEAN value);
    TRSNode*     (*add_ubyte)(TRSNode *node, const char* name, const MUBYTE value);
    TRSNode*     (*add_ushort)(TRSNode *node, const char* name, const MUSHORT value);
    TRSNode*     (*add_uint)(TRSNode *node, const char* name, const MUINT value);
    TRSNode*     (*add_ulong)(TRSNode *node, const char* name, const MULONG value);
    TRSNode*     (*add_float)(TRSNode *node, const char* name, const MFLOAT value);
    TRSNode*     (*add_double)(TRSNode *node, const char* name, const MDOUBLE value);
    TRSNode*     (*add_byte)(TRSNode *node, const char* name, const MBYTE value);
    TRSNode*     (*add_short)(TRSNode *node, const char* name, const MSHORT value);
    TRSNode*     (*add_int)(TRSNode *node, const char* name, const MINT value);
    TRSNode*     (*add_long)(TRSNode *node, const char* name, const MLONG value);
    TRSNode*     (*add_datetime)(TRSNode *node, const char* name, const MDATETIME value);
    TRSNode*     (*add_blob)(TRSNode *node, const char* name, const MBLOB value);
    TRSNode*     (*add_object)(TRSNode *node, const char* name, const void* value);
    
    TRSNode*     (*add_node)(TRSNode *node, const char* name);
    void         (*add_made_node)(TRSNode *to_node, TRSNode *node);
    TRSNode*     (*add_array)(TRSNode *node, const char *name, const TRSDataType array_type);
    int          (*add_item)(TRSNode *node, ...);
    int          (*add_array_item)(TRSNode *node, char *name, ...);

    void*        (*copy)(MSTRING* dest, const TRSNode *node, const char* name);
    unsigned int (*calculate_msg_length)(const TRSNode *node);
    void         (*to_xml_string)(char* xmlString, const TRSNode *node);
    int          (*parse)(TRSNode *node, const char* xmlString, const size_t len, char* s_err_msg);
    
    int          (*str_cmp)(const TRSNode *node, const char* name, MSTRING value);
    int          (*str_tcmp)(const TRSNode *node1, const char* name1, const TRSNode *node2, const char* name2);

    TRSNode*     (*create_node)(const char* node_name);
    void         (*free_node)(TRSNode *node);
    void         (*init_node)(TRSNode *node);
    
    TRSNode*     (*get_member)(const TRSNode *node, const char* member_name);
    TRSNode**    (*get_list)(const TRSNode *node, const char* list_name);
    int          (*get_item_count)(const TRSNode *node, const char* list_name);
    TRSNode*     (*get_array)(const TRSNode *node, const char* array_name);

    MSTRING      (*get_string)(const TRSNode *node, const char* name);
    MCHAR        (*get_char)(const TRSNode *node, const char* name);
    MBINARY      (*get_binary)(const TRSNode *node, const char* name);
    MBOOLEAN     (*get_boolean)(const TRSNode *node, const char* name);
    MUBYTE       (*get_ubyte)(const TRSNode *node, const char* name);
    MUSHORT      (*get_ushort)(const TRSNode *node, const char* name);
    MUINT        (*get_uint)(const TRSNode *node, const char* name);
    MULONG       (*get_ulong)(const TRSNode *node, const char* name);
    MFLOAT       (*get_float)(const TRSNode *node, const char* name);
    MDOUBLE      (*get_double)(const TRSNode *node, const char* name);
    MBYTE        (*get_byte)(const TRSNode *node, const char* name);
    MSHORT       (*get_short)(const TRSNode *node, const char* name);
    MINT         (*get_int)(const TRSNode *node, const char* name);
    MLONG        (*get_long)(const TRSNode *node, const char* name);
    MDATETIME    (*get_datetime)(const TRSNode *node, const char* name);
    MBLOB        (*get_blob)(const TRSNode *node, const char* name);
    void*        (*get_object)(const TRSNode *node, const char* name);
        
    void         (*get_string_param)(const TRSNode *node, const char* name, MSTRING* dest);
    void         (*get_char_param)(const TRSNode *node, const char* name, MCHAR* dest);
    void         (*get_binary_param)(const TRSNode *node, const char* name, MBINARY* dest);
    void         (*get_boolean_param)(const TRSNode *node, const char* name, MBOOLEAN* dest);
    void         (*get_ubyte_param)(const TRSNode *node, const char* name, MUBYTE* dest);
    void         (*get_ushort_param)(const TRSNode *node, const char* name, MUSHORT* dest);
    void         (*get_uint_param)(const TRSNode *node, const char* name, MUINT* dest);
    void         (*get_ulong_param)(const TRSNode *node, const char* name, MULONG* dest);
    void         (*get_float_param)(const TRSNode *node, const char* name, MFLOAT* dest);
    void         (*get_double_param)(const TRSNode *node, const char* name, MDOUBLE* dest);
    void         (*get_byte_param)(const TRSNode *node, const char* name, MBYTE* dest);
    void         (*get_short_param)(const TRSNode *node, const char* name, MSHORT* dest);
    void         (*get_int_param)(const TRSNode *node, const char* name, MINT* dest);
    void         (*get_long_param)(const TRSNode *node, const char* name, MLONG* dest);
    void         (*get_datetime_param)(const TRSNode *node, const char* name, MDATETIME* dest);
    void         (*get_blob_param)(const TRSNode *node, const char* name, MBLOB* dest);
    void         (*get_object_param)(const TRSNode *node, const char* name, void* dest);

    void         (*add_status_value)(TRSNode *node, const char status);
    void         (*add_msgcode)(TRSNode *node, const char* msgCode);
    void         (*add_message)(TRSNode *node, const char* msg);
    void         (*add_msgcate)(TRSNode *node, const char category);
    void         (*add_fieldmsg)(TRSNode *node, const char* name, TRSDataType type, ...);
    void         (*add_dberrmsg)(TRSNode *node, const char* dberrmsg);
    
    char*        (*get_passport)(const TRSNode *node);
    char         (*get_language)(const TRSNode *node);
    char*        (*get_factory)(const TRSNode *node);
    char*        (*get_userid)(const TRSNode *node);
    char*        (*get_password)(const TRSNode *node);
    char         (*get_procstep)(const TRSNode *node);
    
    void         (*set_status_value)(TRSNode *node, const char status);
    void         (*set_msgcode)(TRSNode *node, const char* msgCode);
    void         (*set_message)(TRSNode *node, const char* msg);
    void         (*set_msgcate)(TRSNode *node, const char category);
    void         (*set_fieldmsg)(TRSNode *node, const char* name, TRSDataType type, ...);
    void         (*set_dberrmsg)(TRSNode *node, const char* dberrmsg);
    
    TRSNode*     (*set_string)(TRSNode *node, const char* name, const MSTRING value);
    TRSNode*     (*set_enc_string)(TRSNode *node, const char* name, const MSTRING value);
    TRSNode*     (*set_char)(TRSNode *node, const char* name, const MCHAR value);
    TRSNode*     (*set_binary)(TRSNode *node, const char* name, const MBINARY value);
    TRSNode*     (*set_boolean)(TRSNode *node, const char* name, const MBOOLEAN value);
    TRSNode*     (*set_ubyte)(TRSNode *node, const char* name, const MUBYTE value);
    TRSNode*     (*set_ushort)(TRSNode *node, const char* name, const MUSHORT value);
    TRSNode*     (*set_uint)(TRSNode *node, const char* name, const MUINT value);
    TRSNode*     (*set_ulong)(TRSNode *node, const char* name, const MULONG value);
    TRSNode*     (*set_float)(TRSNode *node, const char* name, const MFLOAT value);
    TRSNode*     (*set_double)(TRSNode *node, const char* name, const MDOUBLE value);
    TRSNode*     (*set_byte)(TRSNode *node, const char* name, const MBYTE value);
    TRSNode*     (*set_short)(TRSNode *node, const char* name, const MSHORT value);
    TRSNode*     (*set_int)(TRSNode *node, const char* name, const MINT value);
    TRSNode*     (*set_long)(TRSNode *node, const char* name, const MLONG value);
    TRSNode*     (*set_datetime)(TRSNode *node, const char* name, const MDATETIME value);
    TRSNode*     (*set_blob)(TRSNode *node, const char* name, const MBLOB value);
    TRSNode*     (*set_object)(TRSNode *node, const char* name, const void* value);

    void         (*clone)(TRSNode *dest, const TRSNode *src);
    void         (*sync)(TRSNode *dest, const TRSNode *src);
    void         (*copy_members)(TRSNode *dest, const TRSNode *src);
    void         (*log_add)(const TRSNode *node, const char* name);
    void         (*log_add_all_members)(const TRSNode *node);

    TRSNode*     (*insert_member)(TRSNode *node, const char *name, const char override_flag, const int index, const TRSDataType type, ...);

    int          (*get_parent_path)(const TRSNode *node, const char *s_name, char *s_path);
    int          (*get_member_path)(const TRSNode *node, const char *s_name, char *s_path);
    int          (*get_node_path)(const TRSNode *node, char *s_path);

}TRSFunctionsForNull;

static const TRSFunctionsForNull TRSN = {

    TRS_add_string_for_null,
    TRS_add_enc_string_for_null,
    TRS_add_char_for_null,
    TRS_add_binary_for_null,
    TRS_add_boolean_for_null,
    TRS_add_ubyte_for_null,
    TRS_add_ushort_for_null,
    TRS_add_uint_for_null,
    TRS_add_ulong_for_null,
    TRS_add_float_for_null,
    TRS_add_double_for_null,
    TRS_add_byte_for_null,
    TRS_add_short_for_null,
    TRS_add_int_for_null,
    TRS_add_long_for_null,
    TRS_add_datetime_for_null,
    TRS_add_blob_for_null,
    TRS_add_object,

    TRS_add_node,
    TRS_add_made_node,
    TRS_add_array,
    TRS_add_item_for_null,
    TRS_add_array_item_for_null,
    
    TRS_copy_for_null,
    TRS_calculate_msg_length,

    TRS_to_xml_string,
    TRS_parse,

    TRS_memcmp_for_null,
    TRS_strtcmp,

    TRS_create_node,
    TRS_free_node,
    TRS_init_node,
    
    TRS_get_member,
    TRS_get_list,
    TRS_get_item_count,
    TRS_get_array,
    
    TRS_get_string_for_null,
    TRS_get_char_for_null,
    TRS_get_binary_for_null,
    TRS_get_boolean_for_null,
    TRS_get_ubyte_for_null,
    TRS_get_ushort_for_null,
    TRS_get_uint_for_null,
    TRS_get_ulong_for_null,
    TRS_get_float_for_null,
    TRS_get_double_for_null,
    TRS_get_byte_for_null,
    TRS_get_short_for_null,
    TRS_get_int_for_null,
    TRS_get_long_for_null,
    TRS_get_datetime_for_null,
    TRS_get_blob_for_null,
    TRS_get_object,
    
    TRS_get_string_param_for_null,
    TRS_get_char_param_for_null,
    TRS_get_binary_param_for_null,
    TRS_get_boolean_param_for_null,
    TRS_get_ubyte_param_for_null,
    TRS_get_ushort_param_for_null,
    TRS_get_uint_param_for_null,
    TRS_get_ulong_param_for_null,
    TRS_get_float_param_for_null,
    TRS_get_double_param_for_null,
    TRS_get_byte_param_for_null,
    TRS_get_short_param_for_null,
    TRS_get_int_param_for_null,
    TRS_get_long_param_for_null,
    TRS_get_datetime_param_for_null,
    TRS_get_blob_param_for_null,
    TRS_get_object_param,

    TRS_add_out_msg_status_value,
    TRS_add_out_msg_msgcode,
    TRS_add_out_msg_message,
    TRS_add_out_msg_msgcate,
    TRS_add_out_msg_fieldmsg,
    TRS_add_out_msg_dberrmsg,
    
    TRS_get_in_msg_passport,
    TRS_get_in_msg_language,
    TRS_get_in_msg_factory,
    TRS_get_in_msg_userid,
    TRS_get_in_msg_password,
    TRS_get_in_msg_procstep,
    
    TRS_set_out_msg_status_value,
    TRS_set_out_msg_msgcode,
    TRS_set_out_msg_message,
    TRS_set_out_msg_msgcate,
    TRS_set_out_msg_fieldmsg,
    TRS_set_out_msg_dberrmsg,
    
    TRS_set_string_for_null,
    TRS_set_enc_string_for_null,
    TRS_set_char_for_null,
    TRS_set_binary_for_null,
    TRS_set_boolean_for_null,
    TRS_set_ubyte_for_null,
    TRS_set_ushort_for_null,
    TRS_set_uint_for_null,
    TRS_set_ulong_for_null,
    TRS_set_float_for_null,
    TRS_set_double_for_null,
    TRS_set_byte_for_null,
    TRS_set_short_for_null,
    TRS_set_int_for_null,
    TRS_set_long_for_null,
    TRS_set_datetime_for_null,
    TRS_set_blob_for_null,
    TRS_set_object,

    TRS_clone,
    TRS_sync,
    TRS_copy_members,
    TRS_add_member_to_log,
    TRS_add_all_member_to_log,

    TRS_insert_member_for_null,
    
    TRS_get_parent_path,
    TRS_get_member_path,
    TRS_get_node_path

};

#endif

