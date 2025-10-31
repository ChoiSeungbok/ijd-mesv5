/*******************************************************************************

    System      : MESplus
    Module      : ACTCore
    File Name   : ACTCore_common.h
    Description : external function prototype definition of ACTCore Library

    MES Version : 5.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2009/02/04  Aiden          Create

    Copyright(C) 1998-2009 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _ACTCORE_COMMON_H
#define _ACTCORE_COMMON_H

#include <MessageDefines.h>
#include <MESCore_common.h>

/*********************************************************************************
    Overriable Function Point Prototype
*********************************************************************************/

/* Call service handler */
typedef int (*CallServiceHandler)(char *s_module_name, 
                                  char *s_service_name, 
                                  TRSNode *in_node, 
                                  TRSNode *out_node, 
                                  char *channel, 
                                  int ttl, 
                                  int mode);


/* ALM Module */
typedef void (*ALM_Msg_Action_Handler)(struct MALMMSGHIS_TAG *MALMMSGHIS, 
                                      int i_user_count, 
                                      struct ALARM_USER_TAG *ALARM_USER);

typedef void (*ALM_Send_Keeping_Msg_Handler)(int i_alm_index);

typedef int (*ALM_Display_Action_Handler)(char *s_msg_code,
                                          struct MALMMSGHIS_TAG *MALMMSGHIS, 
                                          int i_user_count, 
                                          struct ALARM_USER_TAG *ALARM_USER);

typedef int (*ALM_Mail_Action_Handler)(int i_user_count, 
                                       struct ALARM_USER_TAG *ALARM_USER,
                                       char *s_alarm_id,
                                       char *s_content);

/* FMB Module */
typedef int (*FMB_Publish_Resource_Status_Handler)(char *s_factory_t, char *s_res_id_t, char s_proc_step);
typedef int (*FMB_Publish_Port_Status_Handler)(char *s_factory, char *s_res_id , char *s_port_id, char c_proc_step);
typedef int (*FMB_Publish_Sub_Resource_Status_Handler)(char *s_factory, char *s_res_id , char *s_subres_id, char c_proc_step);
typedef int (*FMB_Publish_Tool_Status_Handler)(char *s_factory, char *s_res_id , char *s_tool_id, char c_proc_step);
typedef int (*FMB_Publish_Attribute_Value_Handler)(TRSNode *in_node);

/* SPC Module */
typedef int (*SPC_Publish_Data_Handler)(TRSNode *in_node, int i_unit_seq, char cBackFlag);

/* For Timer */
typedef void (*System_Timer_Handler)();

/* BBS Message */
typedef int (*BAS_Publish_BBS_Message_Handler)(char *s_msg_code,
                                               int i_user_count, 
                                               struct MMSGBBSHIS_TAG *MMSGBBSHIS,
                                               struct ALARM_USER_TAG *MESSAGE_USER);



/*********************************************************************************
    Overriable User Interface Function Prototype
*********************************************************************************/
extern int ACT_call_service(char *s_module_name, 
                            char *s_service_name, 
                            TRSNode *in_node, 
                            TRSNode *out_node, 
                            char *channel, 
                            int ttl, 
                            int mode);

extern void ACT_alm_msg_action(struct MALMMSGHIS_TAG *MALMMSGHIS, 
                               int i_user_count, 
                               struct ALARM_USER_TAG *ALARM_USER);

extern void ACT_alm_send_keeping_msg(int i_alm_index);

extern int ACT_alm_display_action(char *s_msg_code,
                                  struct MALMMSGHIS_TAG *MALMMSGHIS, 
                                  int i_user_count, 
                                  struct ALARM_USER_TAG *ALARM_USER);

extern int ACT_alm_mail_action(int i_user_count, 
                               struct ALARM_USER_TAG *ALARM_USER,
                               char *s_alarm_id,
                               char *s_content);


extern int ACT_fmb_publish_resource_status(char *s_factory_t, char *s_res_id_t, char s_proc_step);
extern int ACT_fmb_publish_port_status(char *s_factory, char *s_res_id , char *s_port_id, char c_proc_step);
extern int ACT_fmb_publish_sub_resource_status(char *s_factory, char *s_res_id , char *s_subres_id, char c_proc_step);
extern int ACT_fmb_publish_tool_status(char *s_factory, char *s_res_id , char *s_tool_id, char c_proc_step);
extern int ACT_fmb_publish_attribute_value(TRSNode *in_node);

extern int ACT_spc_publish_data(TRSNode *in_node, int i_unit_seq, char cBackFlag);

extern void ACT_system_timer_1();
extern void ACT_system_timer_2();
extern void ACT_system_timer_3();
extern void ACT_system_timer_4();
extern void ACT_system_timer_5();
extern void ACT_system_timer_6();
extern void ACT_system_timer_7();
extern void ACT_system_timer_8();
extern void ACT_system_timer_9();


extern int ACT_bas_publish_bbs_message(char *s_msg_code,
                                       int i_user_count, 
                                       struct MMSGBBSHIS_TAG *MMSGBBSHIS,
                                       struct ALARM_USER_TAG *MESSAGE_USER);


typedef struct 
{
    CallServiceHandler                      call_service;

    ALM_Msg_Action_Handler                  alm_msg_action;
    ALM_Send_Keeping_Msg_Handler            alm_send_keeping_msg;
    ALM_Display_Action_Handler              alm_display_action;
    ALM_Mail_Action_Handler                 alm_mail_action;

    FMB_Publish_Resource_Status_Handler     fmb_publish_resource_status;
    FMB_Publish_Port_Status_Handler         fmb_publish_port_status;
    FMB_Publish_Sub_Resource_Status_Handler fmb_publish_sub_resource_status;
    FMB_Publish_Tool_Status_Handler         fmb_publish_tool_status;
    FMB_Publish_Attribute_Value_Handler     fmb_publish_attribute_value;

    SPC_Publish_Data_Handler                spc_publish_data;

    System_Timer_Handler                    timer_callback_1;
    System_Timer_Handler                    timer_callback_2;
    System_Timer_Handler                    timer_callback_3;
    System_Timer_Handler                    timer_callback_4;
    System_Timer_Handler                    timer_callback_5;
    System_Timer_Handler                    timer_callback_6;
    System_Timer_Handler                    timer_callback_7;
    System_Timer_Handler                    timer_callback_8;
    System_Timer_Handler                    timer_callback_9;

    BAS_Publish_BBS_Message_Handler         bas_publish_bbs_message;

} MP_OVERRIDABLE_ACTION;

static const MP_OVERRIDABLE_ACTION MOA = {
    ACT_call_service,
    ACT_alm_msg_action,
    ACT_alm_send_keeping_msg,
    ACT_alm_display_action,
    ACT_alm_mail_action,
    ACT_fmb_publish_resource_status,
    ACT_fmb_publish_port_status,
    ACT_fmb_publish_sub_resource_status,
    ACT_fmb_publish_tool_status,
    ACT_fmb_publish_attribute_value,
    ACT_spc_publish_data,
    ACT_system_timer_1,
    ACT_system_timer_2,
    ACT_system_timer_3,
    ACT_system_timer_4,
    ACT_system_timer_5,
    ACT_system_timer_6,
    ACT_system_timer_7,
    ACT_system_timer_8,
    ACT_system_timer_9,
    ACT_bas_publish_bbs_message
};

#endif /* _ACTCORE_COMMON_H */
