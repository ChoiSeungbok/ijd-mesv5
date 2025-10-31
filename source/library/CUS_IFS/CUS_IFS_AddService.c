/*******************************************************************************

    System      : MESplus
    Module      : Customer Defined Shared Library
    File Name   : CUS_IFS_AddService.c
    Description : Common function of user defined shared library

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

#include <MESCore_service.h>
#include "CUS_IFS_services.h"


//Use static library
void CUS_IFS_add_service()
{
    COM_add_service("CUS_IFS", "CUS_IFS_Po_Rcv_Header", REPLY, CUS_IFS_Po_Rcv_Header);   
}
