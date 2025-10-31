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
    1     2020/08/03  Miracom        Create

    Copyright(C) 1998-2008 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_INV_COMMON_H
#define _CUS_INV_COMMON_H

#include <MESCore_common.h>
#include "INVCore_common.h"
#include "TRSCore_defines.h"

#include "DBU_common.h"
#include "CUS_defines.h"
#include "CUS_WIP_common.h" 
#include "CUS_IFS_common.h" 

extern int CUS_INV_UPDATE_INSERT_LOT_STATUS_HISTORY(char *s_msg_code,
													TRSNode *in_node,
													TRSNode *out_node,
													char *s_sys_time_t,
													struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
													struct MINVLOTSTS_TAG *MINVLOTSTS,
													struct MINVLOTHIS_TAG *MINVLOTHIS);

extern int CUS_INV_INSERT_LOT_SWH_HISTORY(char *s_msg_code,
											TRSNode *in_node,
											TRSNode *out_node,
											char *s_sys_time_t,
											struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
											struct MINVLOTSTS_TAG *MINVLOTSTS,
											struct MINVLOTSTS_TAG *MINVLOTSTS_FT);

int CUS_INV_INSERT_LOT_MVH_HISTORY(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node,
									char *s_sys_time_t,
									struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
									struct MINVLOTSTS_TAG *MINVLOTSTS);

int CUS_INV_INSERT_LOT_HLD_HISTORY(char *s_msg_code,
									TRSNode *in_node,
									TRSNode *out_node,
									struct MINVLOTSTS_TAG *MINVLOTSTS);

int CUS_INV_INSERT_LOT_MAT_ISSUE_HISTORY(char *s_msg_code,
											TRSNode *in_node,
											TRSNode *out_node,
											char *s_sys_time_t,
											struct MINVLOTSTS_TAG *MINVLOTSTS_OLD,
											struct MINVREQMST_TAG *MINVREQMST,
											struct MINVREQLOT_TAG *MINVREQLOT);

extern int CUS_INV_CREATE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CV_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_HOLD_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_IN_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_ISSUE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_LOAD_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_MERGE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_MOVE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_RELEASE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_RETOUT_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_SPLIT_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_TEMPIN_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_TERMINATE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_UNLOAD_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CREATE_DLV_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CONFIRM_DLV_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_DLV_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CREATE_DLV_LABEL_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_DLV_LABEL_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CREATE_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CONFIRM_ISSUE_REQUEST_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CREATE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_RECEIVE_ISSUE_REQUEST_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_KITTING_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_LOT_ISSUE_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_PO_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_LOT_LIST_BY_OPER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_STORE_LOT_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_ISSUE_REQUEST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VALIDATION_ISSUE_REQUEST_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VALIDATION_DLV_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VALIDATION_ETC_OUT_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VALIDATION_MOVE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CHECK_BARCODE_TYPE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_REGENERATE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_LOT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_MOVE_LOT_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_VIEW_MOVE_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_LOSS_DLV_LABEL_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_MOVE_SHIPMENT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_CHANGE_ETC_COMMENT_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_ARRIVAL_LOT_FROM_SHIP_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_PRODUCTION_LOT_CONVERSION_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_DELETE_DLV_ORDER_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int CUS_INV_UPDATE_INV_DATA_UPDATE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
#endif
