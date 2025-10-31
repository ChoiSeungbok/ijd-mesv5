/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : sl_common.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2008/11/10  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_COMMON_H
#define _CUS_COMMON_H

#include <MESCore_common.h>
#include "WIPCore_common.h"
#include "RASCore_common.h"
#include "TRSCore_defines.h"
#include "BASCore_common.h"

#include "DBU_common.h"
#include "CUS_defines.h"

extern void com_lrtrim(char *d_p, char *s_p, int i, int size_i);
extern int Get_shift(char *sFactory, struct work_date_tag *work_date);
extern int Get_shift_EAP(char *sFactory, struct work_date_tag *work_date, char *eap_sys_time);
extern int CopyDefaultMembers(TRSNode *target_node, TRSNode *source_node);
extern int Update_Eltsts(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern void Save_Log_in_node(TRSNode *in_node);
extern int COM_UPDATE_LOT_CMF(char *sLot, char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


#endif
