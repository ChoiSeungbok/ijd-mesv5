/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_IFS_service.h
    Description : Customer function prototype of Customer defined shared library

    MES Version : 5.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2020/09/15  Miracom        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _CUS_IFS_SERVICES_H
#define _CUS_IFS_SERVICES_H

#if defined(_USE_STATIC_LIB)
extern void CUS_IFS_add_service();
#endif

extern int CUS_IFS_Po_Rcv_Header(TRSNode *in_node, TRSNode *out_node);

#endif
