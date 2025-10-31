/*******************************************************************************

    System      : MESplus
    Module      : ACTCore
    File Name   : ACTCore_functions.h
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

#ifndef _ACTCORE_FUNCTIONS_H
#define _ACTCORE_FUNCTIONS_H

#include <MESCore_common.h>

/* ALM Module */
void ALM_Msg_Action(struct MALMMSGHIS_TAG *MALMMSGHIS, int i_user_count, struct ALARM_USER_TAG *ALARM_USER);
void ALM_Send_Keeping_Msg(int i_alm_index);
int ALM_Display_Action(char *s_msg_code, struct MALMMSGHIS_TAG *MALMMSGHIS, int i_user_count, struct ALARM_USER_TAG *ALARM_USER);
int ALM_Send_Mail_Action(int i_user_count, struct ALARM_USER_TAG *ALARM_USER, char *s_alarm_id, char *s_content);


/* FMB Module */
int FMB_Publish_Resource_Status(char *s_factory_t, char *s_res_id_t, char s_proc_step);
int FMB_Publish_Port_Status(char *s_factory, char *s_res_id , char *s_port_id, char c_proc_step);
int FMB_Publish_Sub_Resource_Status(char *s_factory, char *s_res_id , char *s_subres_id, char c_proc_step);
int FMB_Publish_Tool_Status(char *s_factory, char *s_res_id , char *s_tool_id, char c_proc_step);
int FMB_Publish_Attribute_Value(TRSNode *in_node);

/* SPC Module */
int SPC_Publish_Data(TRSNode *in_node, int i_unit_seq, char cBackFlag);

/* BBS Message */

int BAS_Publish_BBS_Message(char *s_msg_code, int i_user_count, struct MMSGBBSHIS_TAG *MMSGBBSHIS,  struct ALARM_USER_TAG *MESSAGE_USER);

#endif /* _ACTCORE_FUNCTIONS_H */
