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
    1     2020/06/22  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_WIP_COMMON_H
#define _CUS_WIP_COMMON_H

#include <MESCore_common.h>
#include "WIPCore_common.h"
#include "TRSCore_defines.h"
#include "RASCore_common.h"
#include "EDCCore_common.h"

#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_defines.h" 
#include "CUS_EIS_common.h"
#include "CUS_IFS_common.h" 
#include "CUS_INV_common.h"
#include "CUS_QCM_common.h"
#include "CUS_RAS_common.h"

extern int CUS_WIP_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_ADAPT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_CREATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_SPLIT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_LOSS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_SKIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_MOVE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_TERMINATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_CV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_BONUS_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_HOLD_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_RELEASE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_GENERATE_ID(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_STORE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_UNSTORE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_MERGE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_REGENERATE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_SHIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_MOVE_LOT_FORCE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_ETC_IN_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_REGENERATE_P_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_VALIDATION_ETC_OUT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_DELETE_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//공통 함수
extern int TRANS_ERP_INFO(char *c_CheckErpResult, char *c_CheckErpInput, char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int INPUT_INV_LOT_BY_LEVEL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//호출 함수 추가
extern int CUS_WIP_INPUT_MATERIAL_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_VIEW_MATERIAL_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_VIEW_LABEL_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_VIEW_WORKER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_LOT_PRESS_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_ETC_OUT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int Update_Resource_Status(char *s_msg_code, char *s_factory, char *s_res_id, char c_res_sts, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_CHANGE_ITEM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_CHANGE_ITEM_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int Update_Lot_Summary(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int Update_Res_Wip_Summary(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int Call_Resource_Efficiency(char *s_msg_code, int i_seq,
                                    struct MWIPLOTSTSX_TAG *MWIPLOTSTS, struct MWIPLOTSTSX_TAG *MWIPLOTSTS_AF, struct work_date_tag *work_date,
                                    TRSNode *in_node, TRSNode *out_node);
extern int Adjust_Lot_Summary(char *s_msg_code, int i_start_hist_seq, double d_split_qty, double d_loss_qty, struct work_date_tag *work_date,
                       TRSNode *in_node, TRSNode *out_node);

extern int CUS_WIP_SPLIT_WIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_MERGE_WIP_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_UPDATE_WORKING_TIME(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_DELETE_P_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_WIP_RAS_YIELD_ST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

extern int CUS_WIP_CHANGE_TEST_PROD_LOT(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

#endif
