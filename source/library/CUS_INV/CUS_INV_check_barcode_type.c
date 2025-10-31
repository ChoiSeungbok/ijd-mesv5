/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_check_barcode_type.c
Description : Check Barcode Type

MES Version : 4.0.0

Function List
- CUS_INV_Check_Barcode_Type()
+ Check Barcode Type
- CUS_INV_CHECK_BARCODE_TYPE()
+ Main sub function of "CUS_INV_Check_Barcode_Type" function
+ Barcode Type definition
- CUS_INV_Check_Barcode_Type_Validation()
+ Validation Check sub function of "CUS_INV_CHECK_BARCODE_TYPE" function

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/18  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_Check_Barcode_Type_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_CHECK_BARCODE_TYPE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_Check_Barcode_Type()
- Check Barcode Type
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Check_Barcode_Type(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_INV_CHECK_BARCODE_TYPE(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_INV_CHECK_BARCODE_TYPE", out_node);

	if (i_ret == MP_TRUE)
	{
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
		DB_commit();
	}
	else
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_INV_CHECK_BARCODE_TYPE()
- Main sub function of "CUS_INV_Check_Barcode_Type" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_CHECK_BARCODE_TYPE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MINVREQMST_TAG MINVREQMST;
	struct MINVDLVLOT_TAG MINVDLVLOT;
	struct MINVLOTSTS_TAG MINVLOTSTS;
	struct CWIPLOTMVM_TAG CWIPLOTMVM;
	struct MINVMOVSTS_TAG MINVMOVSTS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct CPAKLOTSTS_TAG CPAKLOTSTS;
	struct MRASRESDEF_TAG MRASRESDEF;
	struct CWIPGRPSTS_TAG CWIPGRPSTS;

	double d_pack_lot_qty = 0;
	
    LOG_head("CUS_INV_Check_Barcode_Type");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_Check_Barcode_Type_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	// 불출 요청 번호
	DBU_init_minvreqmst(&MINVREQMST);
	TRS.copy(MINVREQMST.FACTORY, sizeof(MINVREQMST.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVREQMST.REQ_NO, sizeof(MINVREQMST.REQ_NO), in_node, "BARCODE_ID");
	DBU_select_minvreqmst(1, &MINVREQMST);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_ISSUE_REQUEST);
		return MP_TRUE;
	}

	// 입하 LOT ID
	DBU_init_minvdlvlot(&MINVDLVLOT);
	TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "BARCODE_ID");
	DBU_select_minvdlvlot(1, &MINVDLVLOT);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_DLV_LOT);
		return MP_TRUE;
	}

	// 자재 LOT ID
	DBU_init_minvlotsts(&MINVLOTSTS);
	TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "BARCODE_ID");
	DBU_select_minvlotsts(1, &MINVLOTSTS);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_INV_LOT);
		return MP_TRUE;
	}

	// 이동 지시 번호 (WIP)
	DBU_init_cwiplotmvm(&CWIPLOTMVM);
	TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), in_node, "BARCODE_ID");
	DBU_select_cwiplotmvm(1, &CWIPLOTMVM);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_MOVE_REQUEST);
		return MP_TRUE;
	}

	// 이동 지시 번호 (INV)
	DBU_init_minvmovsts(&MINVMOVSTS);
	TRS.copy(MINVMOVSTS.FACTORY, sizeof(MINVMOVSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MINVMOVSTS.MOVE_ID, sizeof(MINVMOVSTS.MOVE_ID), in_node, "BARCODE_ID");
	DBU_select_minvmovsts(1, &MINVMOVSTS);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_MOVE_REQUEST);
		return MP_TRUE;
	}

	// LOT ID
	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "BARCODE_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_LOT);
		return MP_TRUE;
	}

	// BOX ID
	DBU_init_cpaklotsts(&CPAKLOTSTS);
	TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKLOTSTS.BOX_ID_1, sizeof(CPAKLOTSTS.BOX_ID_1), in_node, "BARCODE_ID");
	d_pack_lot_qty = DBU_select_cpaklotsts_scalar(8, &CPAKLOTSTS);

	if (d_pack_lot_qty > 0)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_BOX);
		return MP_TRUE;
	}

	// Final BOX ID
	DBU_init_cpaklotsts(&CPAKLOTSTS);
	TRS.copy(CPAKLOTSTS.FACTORY, sizeof(CPAKLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CPAKLOTSTS.BOX_ID_2, sizeof(CPAKLOTSTS.BOX_ID_2), in_node, "BARCODE_ID");
	d_pack_lot_qty = DBU_select_cpaklotsts_scalar(9, &CPAKLOTSTS);

	if (d_pack_lot_qty > 0)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_FINAL_BOX);
		return MP_TRUE;
	}

	// MACHINE
	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "BARCODE_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);
	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_MACHINE);
		return MP_TRUE;
	}

	// GROUP ID
	DBU_init_cwipgrpsts(&CWIPGRPSTS);
	TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), in_node, "BARCODE_ID");
	DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
	if (DB_error_code == DB_SUCCESS)
	{
		TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_LOT);
		return MP_TRUE;
	}

	//아무것도 없으면 Nothing
	TRS.add_nstring(out_node, "BARCODE_TYPE", MP_BARCODE_TYPE_NOTHING);
    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_Check_Barcode_Type_Validation()
- Validation Check sub function of "CUS_INV_CHECK_BARCODE_TYPE" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_Check_Barcode_Type_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */ 
    /*if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
    {
        return MP_FALSE;
    }*/

    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }

    return MP_TRUE;
}
