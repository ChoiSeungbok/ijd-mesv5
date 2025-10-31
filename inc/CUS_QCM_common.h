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
    1     2020/07/27  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_QCM_COMMON_H
#define _CUS_QCM_COMMON_H

#include <MESCore_common.h>
#include "EDCCore_common.h"
#include "TRSCore_defines.h"

#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_defines.h"


//extern int CUS_WIP_CV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_INSPECTION_JUDGE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_COLLECT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_CREATE_INSPECTION_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_UPDATE_INSPECTION_STATUS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_COLLECT_INSPECTION_DATA_GRIT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_UPDATE_INSPECTION_WORKER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_VIEW_LOT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_GENERATE_REPORT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_SAVE_REPORT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_FILE_ATTACH(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_BATCH_MIG_DATA_QCM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_BATCH_MIG_DATA_PRT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_COLLECT_CUT_INSPECTION_UPLOAD(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_RECIPE_MANAGEMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_COLLECT_SPC_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_QCM_UPDATE_CUS_QCM_CUSTOMER_CLAIM(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

#endif
