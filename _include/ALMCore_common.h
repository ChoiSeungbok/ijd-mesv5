/*******************************************************************************

    System      : MESplus
    Module      : ALMCore
    File Name   : ALMCore_common.h
    Description : external function prototype definition of ALMCore Library

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2005/7/16   J.S.           Create

    Copyright(C) 1998-2005 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _ALMCORE_COMMON_H
#define _ALMCORE_COMMON_H


#include <MESCore_common.h>

extern int ALM_get_alarm_user(char *s_msg_code,                                 
                               TRSNode *out_node,
                               char *s_factory, 
                               char *s_user_id, 
                               int *i_user_count, 
                               struct ALARM_USER_TAG *ALARM_USER);

extern int ALM_get_alarm_user_by_prvgrp(char *s_msg_code, 
                                  TRSNode *out_node,
                                  char *s_factory, 
                                  char *s_prv_grp, 
                                  int *i_user_count, 
                                  struct ALARM_USER_TAG *ALARM_USER);

extern int ALM_get_recv_alarm_user(char *s_msg_code, 
                                   TRSNode *out_node,
                                   char *s_factory, 
                                   char *s_alarm_id, 
                                   int *i_user_count, 
                                   struct ALARM_USER_TAG *ALARM_USER);

extern int ALM_process_confirm_message(char *s_msg_code, 
                                       TRSNode *out_node,                                
                                        char c_language,
                                        char *s_user_id,
                                        char *s_factory,
                                        char *s_lot_id,
                                        char c_tran_point,
                                        char *s_res_id,
                                        char *s_event_id,
                                        char *c_raised_flag);

extern int ALM_keep_message(char *s_msg_code,
                            struct MALMMSGHIS_TAG *MALMMSGHIS, 
                            int i_user_count, 
                            struct ALARM_USER_TAG *ALARM_USER);
                                
extern int ALM_get_attached_file(char *s_msg_code,
                                 TRSNode *out_node,
                                 char *s_file_name_t,
                                 char *s_put_member_name,
                                 char c_add_fieldmsg);

extern int ALM_event_alarm(char c_step,
                    char c_language,
                    char *s_user_id,
                    char *s_factory,
                    char *s_res_id,
                    char *s_lot_id,
                    char *s_event_id);

extern int ALM_create_alarm_history(struct MALMMSGHIS_TAG *MALAMSGHIS_t);


extern int ALM_Send_Keeping_Mail(int i_alm_index);



extern int ALM_ACK_ALARM(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_CLEAR_ALARM(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_RAISE_ALARM(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_CHECK_CONFIRM_MESSAGE(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_UPDATE_ALARM_RELATION(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_UPDATE_ALARM_MSG(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);


extern int ALM_VIEW_ALARM_HISTORY_LIST(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int ALM_VIEW_ALARM_MSG(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int ALM_VIEW_ALARM_MSG_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int ALM_VIEW_ALARM_RECEIVER_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int ALM_VIEW_ALARM_RELATION_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);


#endif /* _ALMCORE_COMMON_H */


