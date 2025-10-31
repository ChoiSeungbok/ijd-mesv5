/******************************************************************************'

System      : MESplus
Module      : CUS
File Name   : CUS_common.c
Description : Customer Common Function

MES Version : 5.3.4 ~

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2019/03/17             Create by Generator

Copyright(C) 1998-2016 Miracom,Inc.
All rights reserved.

******************************************************************************/

#include "CUS_common.h"


/*******************************************************************************
COM_UPDATE_LOT_CMF()
- Update status and history of lot By Lot ID
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- string sLot
- TRSNode *in_node : In Node from each transaction function
- TRSNode *out_node : Common out node for result message
*******************************************************************************/
int SET_ERP_CATALOG_TO_MATERIAL(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	char catalogValue[30];
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	DBC_init_mgcmtbldat(&MGCMTBLDAT);
	TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);

	memcpy(MGCMTBLDAT.TABLE_NAME, "C_MAT_CMF_MAPPING", strlen("C_MAT_CMF_MAPPING"));
	TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "AREA_ID"); // AREA_ID
	TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), in_node, "MAT_TYPE"); // MAT_TYPE
	TRS.copy(MGCMTBLDAT.KEY_3, sizeof(MGCMTBLDAT.KEY_3), in_node, "CATALOG_NAME"); // CATALOG_NAME
	DBC_select_mgcmtbldat(1, &MGCMTBLDAT);
	if (DB_error_code != DB_SUCCESS)
	{
		TRS.add_dberrmsg(out_node, DB_error_msg);
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	TRS.set_string(out_node, "CMF_NAME", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
	memset(catalogValue, 0x00, sizeof(catalogValue));
	TRS.copy(catalogValue, sizeof(catalogValue), in_node, "CATALOG_VALUE"); // CATALOG_VALUE
	TRS.set_string(out_node, "CMF_VALUE", catalogValue, sizeof(catalogValue));	

	return MP_TRUE;
}