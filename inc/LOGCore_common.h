#ifndef _LOGCORE_COMMON_H
#define _LOGCORE_COMMON_H



extern void LOG_open(char      *my_site_id, 
                     char      *server_name,
                     char      *sub_no,
                     int       log_level,
                     int       log_mode,
                     int       log_file_size,
                     int       log_file_count,
                     char      *log_file_dir,
                     char      log_file_by_time,
                     int       *sts_val,
                     char      *sts_msg);

extern void LOG_close();
extern void LOG_head(const char *head);
extern void LOG_add(const char *title, const int type, ...);
extern void LOG_printf(const char *log, ...);
extern void LOG_key_add(const char *title, const int type, ...);
extern void LOG_write(const char *s_client_id,
                      const char c_log_type, 
                      const char c_log_error_type, 
                      const char c_log_category,
                      const char c_status);
extern void LOG_long_write(const char *s_client_id,
                           const char c_log_type,
                           const char c_log_error_type,
                           const char c_log_category,
                           const char c_status,
                           const char *s_header,
                           const char *s_title, 
                           char *s_log_null_string);
extern void LOG_change_level(int log_level);
extern void LOG_print_backtrace();
extern void LOG_print_backtrace_range(const unsigned int i_skip_size, const unsigned int i_trace_size);
extern void LOG_get_backtrace_symbol(const unsigned int i_skip_size, char *s_symbol_name);

#endif //_LOGCore_common_H


