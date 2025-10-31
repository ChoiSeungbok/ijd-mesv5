/*******************************************************************************

    System      : MESplus
    Module      : BOMCore
    File Name   : BOMCore_common.h
    Description : external function prototype definition of BOMCore Library

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


#ifndef _BOMCORE_COMMON_H
#define _BOMCORE_COMMON_H


#include <MESCore_common.h>


extern int BOM_APPROVAL_AND_RELEASE_TO_VERSION(char *s_msg_code,
                                               TRSNode *in_node, 
                                               TRSNode *out_node);
extern int BOM_FIND_BOM_SET_VERSION(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int BOM_ASSEMBLY_LOT(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int BOM_COPY_BOMSET_VERSION(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int BOM_DELETE_BOM_HISTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int BOM_DISASSEMBLE_LOT(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int BOM_REPLACE_LOT(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int BOM_UPDATE_ATTACH_MATERIAL(char *s_msg_code,
                                      TRSNode *in_node, 
                                       TRSNode *out_node);

extern int BOM_UPDATE_BOMSET(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int BOM_UPDATE_BOMSET_VERSION(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);


extern int BOM_VIEW_ATTACH_MATERIAL(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int BOM_VIEW_ATTACH_MATERIAL_LIST(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);

extern int BOM_VIEW_BOMSET(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int BOM_VIEW_BOMSET_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int BOM_VIEW_BOMSET_VERSION(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int BOM_VIEW_BOMSET_VERSION_LIST(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);

extern int BOM_VIEW_LOT_HISTORY_FOR_ASSEMBLY(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int BOM_VIEW_LOT_STATUS_FOR_ASSEMBLY(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

/*Added bs.kwak 2013.01.13 */
extern int BOM_COPY_BOMSET(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);


#endif /* _BOMCORE_COMMON_H */



