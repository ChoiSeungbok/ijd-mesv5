/*******************************************************************************

    System      : MESplus
    Module      : EDCCore
    File Name   : EDCCore_common.h
    Description : external function prototype definition of EDCCore Library

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/12/16  SK Jin         Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _EDCCORE_COMMON_H
#define _EDCCORE_COMMON_H


#include <MESCore_common.h>


#ifdef _SPC
#include <SPCCore_common.h>
#endif
#include <RASCore_common.h>


extern int EDC_collect_data_validation(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int EDC_collect_data_insert_data(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node,
                                 char c_lot_or_res_flag,
                                 void *p_data_table);

extern int EDC_collect_data_raise_alarm(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node,
                                 char c_lot_or_res_flag);

extern int EDC_collect_data_insert_to_spc(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node,
                                   char c_lot_or_res_flag,
                                   int i_edc_hist_seq,
                                   int i_edc_col_seq);

extern int EDC_collect_data_check_col_set(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node,
                                   char c_lot_or_res_flag);

extern int EDC_APPROVAL_AND_RELEASE_TO_VERSION(char *s_msg_code,
                                               TRSNode *in_node,
                                               TRSNode *out_node);

extern int EDC_ATTACH_CHARACTER(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int EDC_CHANGE_CHAR_SEQUENCE(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int EDC_CHANGE_LOT_DATA(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int EDC_CHANGE_RES_DATA(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);

extern int EDC_COLLECT_LOT_DATA(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int EDC_COLLECT_RES_DATA(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int EDC_COPY_COL_SET(char *s_msg_code,
                            TRSNode *in_node,
                            TRSNode *out_node);

extern int EDC_COPY_COL_SET_VERSION(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int EDC_DELETE_LOTDATA_HISTORY(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int EDC_DELETE_RESDATA_HISTORY(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int EDC_FIND_COL_SET_VERSION(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int EDC_UPDATE_ATTACH_CHARACTER(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int EDC_UPDATE_CHARACTER(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int EDC_UPDATE_COL_SET(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int EDC_UPDATE_COL_SET_VERSION(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);
extern int EDC_UPDATE_DEFAULT_UNIT_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);
extern int EDC_UPDATE_MFO_COLSET(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int EDC_UPDATE_MFO_COLSET_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

/*Add By JU.Heo 2012.11.29*/
extern int EDC_UPDATE_VALUE_PROMPT(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);
/* End Add */

extern int EDC_VIEW_ATTACH_CHARACTER(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int EDC_VIEW_ATTACH_CHARACTER_LIST(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int EDC_VIEW_CHARACTER(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int EDC_VIEW_CHARACTER_LIST(char *s_msg_code,
                                   TRSNode *in_node,
                                   TRSNode *out_node);

extern int EDC_VIEW_CHARACTER_LIST_DETAIL(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int EDC_VIEW_COL_SET(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int EDC_VIEW_COL_SET_LIST(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int EDC_VIEW_COL_SET_LIST_BY_GROUP(char *s_msg_code,
                                          TRSNode *in_node,
                                          TRSNode *out_node);

extern int EDC_VIEW_COL_SET_LIST_DETAIL(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int EDC_VIEW_COL_SET_VERSION(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int EDC_VIEW_COL_SET_VERSION_LIST(char *s_msg_code, 
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int EDC_VIEW_DEFAULT_UNIT_LIST(char *s_msg_code,
                                      TRSNode *in_node,
                                      TRSNode *out_node);

extern int EDC_VIEW_LOT_DATA(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int EDC_VIEW_LOT_DATA_BY_COLSET(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int EDC_VIEW_MFO_COLSET(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int EDC_VIEW_MFO_COLSET_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int EDC_VIEW_RESOURCE_DATA(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int EDC_VIEW_RESOURCE_DATA_BY_COLSET(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int EDC_VIEW_DERIVED_CHARACTER_LIST(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

/*Add By JU.Heo 2012.11.30*/
extern int EDC_VIEW_VALUE_PROMPT(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);
/* End Add */

#endif /* _EDCCORE_COMMON_H */


