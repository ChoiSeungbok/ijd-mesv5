/*******************************************************************************

    System      : MESplus
    Module      : MESServer
    File Name   : MessageHandler.h
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

#ifndef _MESSAGE_HANDLER_H
#define _MESSAGE_HANDLER_H


extern char* COM_get_comein_channel();
extern char* COM_get_hostname();
extern char* COM_get_hostaddr();
extern char* COM_get_hostname_peer();
extern char* COM_get_hostaddr_peer();

#if defined(_H101)

#include <transceiverx.h>


/* Stub method ****************************************************************/
extern IOIStatus init(LPTSTR session_id, int session_mode, LPTSTR connect_string, unsigned short monitoring_port);
extern void term();
extern void tune(LPTSTR channel, int mode);
extern void untune(LPTSTR channel, int mode);

extern void on_connect(IOIHandle issuer);
extern void on_disconnect(IOIHandle issuer);
extern void on_message(IOIHandle issuer, IOIMessage msg);
extern void on_reply(IOIHandle issuer, IOIMessage req, IOIMessage rep, void *hint);

extern IOIStatus send_message(IOIMessage msg, IOIMessage *rep, LPTSTR channel, int ttl, int mode, Bool32 sync);
extern IOIStatus send_reply(IOIHandle issuer, IOIMessage req, IOIMessage rep, int err_code, char* err_msg);

extern void dispatch_message();

extern int get_last_space_pos(LPCTSTR str, int size);

extern void COM_get_binary_data(TRSNode *node, HTransformer *former);
extern void COM_set_binary_data(HTransformer *former, TRSNode *node);


#elif defined(_TIBRV)

#include <tibrv.h>

typedef void (*CMessage_callback_type)(tibrvEvent, tibrvMsg, void*);

extern tibrvTransport CMessage_get_transport();

extern void CMessage_initialize(char            *s_server_name,
                                char            *s_sub_no,
                                int             load_balance,
                                char            *s_service,
                                char            *s_network,
                                char            *s_daemon,
                                unsigned short  *sts_val,
                                char            *sts_msg);

extern void CMessage_startup_server(CMessage_callback_type  callback_address,
                                    unsigned short          *sts_val,
                                    char                    *sts_msg);

extern void CMessage_create_server(char             *subject,
                                   char             *s_sub_no,
                                   unsigned short   *sts_val,
                                   char             *sts_msg,
                                   unsigned short   i_scheduler_wieght,
                                   double           d_heartbeat_interval,
                                   double           d_activate_interval);

extern void CMessage_destroy_server(char            *subject,
                                    unsigned short  *sts_val,
                                    char            *sts_msg);

extern void CMessage_request_reply(char             *dest_subject,
                                   tibrvMsg         req, 
                                   tibrvMsg         *rep, 
                                   unsigned short  timeout,
                                   unsigned short   *sts_val,
                                   char             *sts_msg);

extern void CMessage_request_reply_str(char             *dest_subject,
                                       char             *message,
                                       int              msg_length,
                                       char             *reply_buffer,
                                       int              reply_buffer_size,
                                       int              *reply_msg_length,
                                       unsigned short   timeout,
                                       unsigned short   *sts_val,
                                       char             *sts_msg);

extern void CMessage_request_noreply(char              *subject,
                                     tibrvMsg          message,
                                     unsigned short    *sts_val,
                                     char              *sts_msg);

extern void CMessage_request_noreply_str(char            *subject,
                                         char            *message,
                                         int             msg_length,
                                         unsigned short  *sts_val,
                                         char            *sts_msg);

extern void CMessage_enable_certify(char            *certify_name,
                                    char            *my_subject,
                                    unsigned short  *sts_val,
                                    char            *sts_msg );
            
extern void CMessage_request_certify(char           *dest_subject,
                                     char           *message,
                                     int            msg_length,
                                     unsigned short *sts_val,
                                     char           *sts_msg);

extern void CMessage_add_certify_server(char            *subject,
                                        unsigned short  *sts_val,
                                        char            *sts_msg);

extern void CMessage_reply(tibrvMsg         message, 
                           unsigned short   *sts_val, 
                           char             *sts_msg);

extern void CMessage_add_timer(unsigned long            interval,
                               char                     repeat_flag,
                               int                      *timer_id,
                               CMessage_callback_type   callback_address,
                               unsigned short           *sts_val,
                               char                     *sts_msg);

extern void CMessage_cancel_timer(int               timer_id,
                                  unsigned short    *sts_val,
                                  char              *sts_msg);

extern void CMessage_publish(char           *dest_subject,
                             tibrvMsg       message,
                             unsigned short *sts_val,
                             char           *sts_msg);

extern void CMessage_start_subscribe(char           *subject,
                                     unsigned short *sts_val,
                                     char           *sts_msg);

extern void CMessage_stop_subscribe(char            *subject,
                                    unsigned short  *sts_val,
                                    char            *sts_msg);

extern void CMessage_terminate(unsigned short   *sts_val,
                               char             *sts_msg);

extern void CMessage_discard_message(unsigned short *sts_val, 
                                     char *sts_msg);

extern void CMessage_get_message(char           *buffer,
                                 int            buf_length,
                                 unsigned short *sts_val,
                                 char           *sts_msg);

extern void CMessage_peek_message(char              *sender_subject,
                                  int               *msg_length,
                                  unsigned short    *sts_val,
                                  char              *sts_msg);

extern void CMessage_startup_client(char *my_subject, unsigned short *sts_val, 
                                    char *sts_msg);
extern void CMessage_dispatch();
extern void CMessage_get_description(char *sts_msg, char *s_desc);

extern void ReadMsgString(tibrvMsg message, const char *s_field_name, char *s_value);
extern void ReadMsgChar(tibrvMsg message, const char *s_field_name, char *c_value);
extern void ReadMsgInt32(tibrvMsg message, const char *s_field_name, int *i_value);
extern void ReadMsgInt(tibrvMsg message, const char *s_field_name, int *i_value);
extern void ReadMsgInt64(tibrvMsg message, const char *s_field_name, long *l_value);
extern void ReadMsgFloat(tibrvMsg message, const char *s_field_name, float *f_value);
extern void ReadMsgDouble(tibrvMsg message, const char *s_field_name, double *d_value);
extern void WriteMsgString(tibrvMsg message, const char *s_field_name, const char *s_value);
extern void WriteMsgStringFS(tibrvMsg message, const char *s_field_name, const char *s_value, const int i_size);
extern void WriteMsgChar(tibrvMsg message, const char *s_field_name, const char c_value);
extern void WriteMsgInt32(tibrvMsg message, const char *s_field_name, const int i_value);
extern void WriteMsgInt(tibrvMsg message, const char *s_field_name, const int i_value);
extern void WriteMsgInt64(tibrvMsg message, const char *s_field_name, const long l_value);
extern void WriteMsgFloat(tibrvMsg message, const char *s_field_name, const float f_value);
extern void WriteMsgDouble(tibrvMsg message, const char *s_field_name, const double d_value);

extern void message_callback(tibrvEvent event, tibrvMsg message, void* closure);

extern void COM_get_binary_data(TRSNode *node, tibrvMsg *msg);
extern void COM_set_binary_data(tibrvMsg *msg, TRSNode *node);

#endif /* _H101, _TIBRV */

#endif /* _MESSAGE_HANDLER_H */

