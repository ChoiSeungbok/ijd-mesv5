/*******************************************************************************

    System      : MESplus
    Module      : ALMCore
    File Name   : ALMCore_services.h
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

#ifndef _ALMCORE_SERVICES_H
#define _ALMCORE_SERVICES_H

extern int ALM_Ack_Alarm(TRSNode *in_node, TRSNode *out_node);
extern int ALM_Check_Confirm_Message(TRSNode *in_node, TRSNode *out_node);
extern int ALM_Clear_Alarm(TRSNode *in_node, TRSNode *out_node);
extern int ALM_Raise_Alarm(TRSNode *in_node, TRSNode *out_node);
extern int ALM_Update_Alarm_Msg(TRSNode *in_node, TRSNode *out_node);
extern int ALM_Update_Alarm_Relation(TRSNode *in_node, TRSNode *out_node);

extern int ALM_View_Alarm_History_List(TRSNode *in_node, TRSNode *out_node);
extern int ALM_View_Alarm_Msg(TRSNode *in_node, TRSNode *out_node);
extern int ALM_View_Alarm_Msg_List(TRSNode *in_node, TRSNode *out_node);
extern int ALM_View_Alarm_Receiver_List(TRSNode *in_node, TRSNode *out_node);
extern int ALM_View_Alarm_Relation_List(TRSNode *in_node, TRSNode *out_node);


#endif /* _ALMCORE_SERVICES_H */


