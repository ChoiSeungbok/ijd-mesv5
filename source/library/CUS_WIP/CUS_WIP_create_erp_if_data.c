/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_create_erp_if_data.c
Description : MES에서 생성한 ERP 실적 데이터 취소/재전송 데이터를 생성한다.

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/07  차세영        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_CREATE_ERP_IF_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Create_Erp_If_Data()
- Lagacy System의 재고, 재공을 MES으로 재고, 재공을 생성한다.
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Create_Erp_If_Data(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_CREATE_ERP_IF_DATA(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_Create_Erp_If_Data", out_node);

	if (i_ret == MP_TRUE)
	{
		if (gb_multi_transaction == MP_FALSE)
		{
			DB_commit();
		}
	}
	else
	{
		DB_rollback();
	}

	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_CREATE_ERP_IF_DATA()
- Main sub function of "CUS_WIP_Create_Erp_If_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_CREATE_ERP_IF_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_COMPLETION_TRX_TAG IF_COMPLETION_TRX;
	struct IF_COMPLETION_TRX_TAG IF_COMPLETION_TRX_MASTER;

	struct IF_COMPLETION_TRX_SAVE_TAG IF_COMPLETION_TRX_SAVE;

	
	struct IF_MOVE_TRX_TAG IF_MOVE_TRX;
	struct IF_MOVE_TRX_SAVE_TAG IF_MOVE_TRX_SAVE;
	struct IF_COMP_ISSUE_TRX_TAG IF_COMP_ISSUE_TRX;
	struct IF_COMP_ISSUE_TRX_SAVE_TAG IF_COMP_ISSUE_TRX_SAVE;

	//struct work_date_tag work_date;

	TRSNode *if_tran_in;
	TRSNode *cmn_out;

	double dHeaderSeq = 0;

	char sCmfValue[31];

	memset(sCmfValue, 0x00, sizeof(sCmfValue));
	

	LOG_head("CUS_WIP_CREATE_ERP_IF_DATA");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	
	if (TRS.get_procstep(in_node) == '1')
	{
		// COMPLETION TRX CANCEL

		// 1. 기존 IF_SEQ 조회해서 해당 데이터를 넣고 
		// TRAN_TYPE_ID = 17
		// QTY = - 값으로 변경해서 보내준다.

		DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
		IF_COMPLETION_TRX.IF_SEQ = TRS.get_int(in_node, "IF_SEQ");
		DBU_select_if_completion_trx(1, &IF_COMPLETION_TRX);
		if (DB_error_code == DB_SUCCESS)
		{
			// 정규 완공실적 (작업지시 있는 경우)
			if (memcmp(IF_COMPLETION_TRX.TRAN_TYPE, MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION)) == 0)
			{
				if_tran_in = TRS.add_node(in_node, "if_tran_in");
				TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_tran_in, in_node);

				TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
				TRS.add_string(if_tran_in, "WO_ID", IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID));
				TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMPLETION_TRX.ERP_WO_ID);
				TRS.add_string(if_tran_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
				TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
				TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
				TRS.add_string(if_tran_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
				TRS.add_string(if_tran_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
				TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
				TRS.add_string(if_tran_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
				TRS.add_string(if_tran_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
				TRS.add_double(if_tran_in, "QTY", IF_COMPLETION_TRX.QTY);
				TRS.add_string(if_tran_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
				TRS.add_string(if_tran_in, "LOT_ID", IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX.LOT_ID));

				memset(sCmfValue, 0x00, sizeof(sCmfValue));
				COM_dtoa(sCmfValue, IF_COMPLETION_TRX.IF_SEQ, sizeof(sCmfValue));
				TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);

				DBU_init_if_completion_trx_save(&IF_COMPLETION_TRX_SAVE);
				DBU_insert_if_completion_trx_save((struct IF_COMPLETION_TRX_SAVE_TAG *)&IF_COMPLETION_TRX);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX_SAVE INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

			}
			else {
				if (IF_COMPLETION_TRX.TRAN_TYPE_ID == atoi(MP_ERP_TRAN_TYPE_ID_35))
				{
					DBU_init_if_completion_trx(&IF_COMPLETION_TRX_MASTER);
					IF_COMPLETION_TRX_MASTER.IF_SEQ = IF_COMPLETION_TRX.TRAN_HEADER_ID;
					DBU_select_if_completion_trx(1, &IF_COMPLETION_TRX_MASTER);
					if (DB_error_code == DB_SUCCESS)
					{
						if_tran_in = TRS.add_node(in_node, "if_tran_in");
						TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_tran_in, in_node);

						TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
						TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMPLETION_TRX_MASTER.ERP_WO_ID);
						TRS.add_string(if_tran_in, "AREA_ID", IF_COMPLETION_TRX_MASTER.AREA_ID, sizeof(IF_COMPLETION_TRX_MASTER.AREA_ID));
						TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMPLETION_TRX_MASTER.ERP_AREA_ID);
						TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
						TRS.add_string(if_tran_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN, strlen(MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN));
						TRS.add_string(if_tran_in, "INV_OPER", IF_COMPLETION_TRX_MASTER.INV_OPER, sizeof(IF_COMPLETION_TRX_MASTER.INV_OPER));
						TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMPLETION_TRX_MASTER.ERP_MAT_ID);
						TRS.add_string(if_tran_in, "MAT_ID", IF_COMPLETION_TRX_MASTER.MAT_ID, sizeof(IF_COMPLETION_TRX_MASTER.MAT_ID));
						TRS.add_string(if_tran_in, "UNIT", IF_COMPLETION_TRX_MASTER.UNIT, sizeof(IF_COMPLETION_TRX_MASTER.UNIT));
						TRS.add_double(if_tran_in, "QTY", IF_COMPLETION_TRX_MASTER.QTY);
						TRS.add_string(if_tran_in, "MES_OPER", IF_COMPLETION_TRX_MASTER.MES_OPER, sizeof(IF_COMPLETION_TRX_MASTER.MES_OPER));
						TRS.add_string(if_tran_in, "LOT_ID", IF_COMPLETION_TRX_MASTER.LOT_ID, sizeof(IF_COMPLETION_TRX_MASTER.LOT_ID));
						
						memset(sCmfValue, 0x00, sizeof(sCmfValue));
						COM_dtoa(sCmfValue, IF_COMPLETION_TRX_MASTER.IF_SEQ, sizeof(sCmfValue));
						TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						dHeaderSeq = TRS.get_double(cmn_out, "TRAN_HEADER_ID");

						TRS.free_node(cmn_out);

						if_tran_in = TRS.add_node(in_node, "if_tran_in");
						TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_tran_in, in_node);

						TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
						TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMPLETION_TRX.ERP_WO_ID);
						TRS.add_string(if_tran_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
						TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
						
						TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_43));
						TRS.add_string(if_tran_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN, strlen(MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN));
						TRS.add_string(if_tran_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
						TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
						TRS.add_string(if_tran_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
						TRS.add_string(if_tran_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
						TRS.add_double(if_tran_in, "QTY", IF_COMPLETION_TRX.QTY);
						TRS.add_string(if_tran_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
						TRS.add_string(if_tran_in, "LOT_ID", IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX.LOT_ID));
						TRS.add_double(if_tran_in, "TRAN_HEADER_ID", dHeaderSeq);
						TRS.add_double(if_tran_in, "SRC_TRAN_ID", dHeaderSeq);

						memset(sCmfValue, 0x00, sizeof(sCmfValue));
						COM_dtoa(sCmfValue, IF_COMPLETION_TRX.IF_SEQ, sizeof(sCmfValue));
						TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);

						DBU_init_if_completion_trx_save(&IF_COMPLETION_TRX_SAVE);
						DBU_insert_if_completion_trx_save((struct IF_COMPLETION_TRX_SAVE_TAG *)&IF_COMPLETION_TRX);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX_SAVE INSERT", MP_NVST);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}

						DBU_init_if_completion_trx_save(&IF_COMPLETION_TRX_SAVE);
						DBU_insert_if_completion_trx_save((struct IF_COMPLETION_TRX_SAVE_TAG *)&IF_COMPLETION_TRX_MASTER);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX_SAVE_MASTER INSERT", MP_NVST);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}
					}
				}		
				else if (IF_COMPLETION_TRX.TRAN_TYPE_ID == atoi(MP_ERP_TRAN_TYPE_ID_43))
				{
					DBU_init_if_completion_trx(&IF_COMPLETION_TRX_MASTER);
					IF_COMPLETION_TRX_MASTER.IF_SEQ = IF_COMPLETION_TRX.TRAN_HEADER_ID;
					DBU_select_if_completion_trx(1, &IF_COMPLETION_TRX_MASTER);
					if (DB_error_code == DB_SUCCESS)
					{
						if_tran_in = TRS.add_node(in_node, "if_tran_in");
						TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_tran_in, in_node);

						TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
						TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMPLETION_TRX_MASTER.ERP_WO_ID);
						TRS.add_string(if_tran_in, "AREA_ID", IF_COMPLETION_TRX_MASTER.AREA_ID, sizeof(IF_COMPLETION_TRX_MASTER.AREA_ID));
						TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMPLETION_TRX_MASTER.ERP_AREA_ID);
						TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_44));
						TRS.add_string(if_tran_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
						TRS.add_string(if_tran_in, "INV_OPER", IF_COMPLETION_TRX_MASTER.INV_OPER, sizeof(IF_COMPLETION_TRX_MASTER.INV_OPER));
						TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMPLETION_TRX_MASTER.ERP_MAT_ID);
						TRS.add_string(if_tran_in, "MAT_ID", IF_COMPLETION_TRX_MASTER.MAT_ID, sizeof(IF_COMPLETION_TRX_MASTER.MAT_ID));
						TRS.add_string(if_tran_in, "UNIT", IF_COMPLETION_TRX_MASTER.UNIT, sizeof(IF_COMPLETION_TRX_MASTER.UNIT));
						TRS.add_double(if_tran_in, "QTY", IF_COMPLETION_TRX_MASTER.QTY);
						TRS.add_string(if_tran_in, "MES_OPER", IF_COMPLETION_TRX_MASTER.MES_OPER, sizeof(IF_COMPLETION_TRX_MASTER.MES_OPER));
						TRS.add_string(if_tran_in, "LOT_ID", IF_COMPLETION_TRX_MASTER.LOT_ID, sizeof(IF_COMPLETION_TRX_MASTER.LOT_ID));

						memset(sCmfValue, 0x00, sizeof(sCmfValue));
						COM_dtoa(sCmfValue, IF_COMPLETION_TRX_MASTER.IF_SEQ, sizeof(sCmfValue));
						TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						dHeaderSeq = TRS.get_double(cmn_out, "TRAN_HEADER_ID");

						TRS.free_node(cmn_out);

						if_tran_in = TRS.add_node(in_node, "if_tran_in");
						TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_tran_in, in_node);

						TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
						TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMPLETION_TRX_MASTER.ERP_WO_ID);
						TRS.add_string(if_tran_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
						TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);

						TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
						TRS.add_string(if_tran_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
						TRS.add_string(if_tran_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
						TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
						TRS.add_string(if_tran_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
						TRS.add_string(if_tran_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
						TRS.add_double(if_tran_in, "QTY", IF_COMPLETION_TRX.QTY);
						TRS.add_string(if_tran_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
						TRS.add_string(if_tran_in, "LOT_ID", IF_COMPLETION_TRX.LOT_ID, sizeof(IF_COMPLETION_TRX.LOT_ID));
						TRS.add_double(if_tran_in, "TRAN_HEADER_ID", dHeaderSeq);
						TRS.add_double(if_tran_in, "SRC_TRAN_ID", dHeaderSeq);

						memset(sCmfValue, 0x00, sizeof(sCmfValue));
						COM_dtoa(sCmfValue, IF_COMPLETION_TRX.IF_SEQ, sizeof(sCmfValue));
						TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);

						DBU_init_if_completion_trx_save(&IF_COMPLETION_TRX_SAVE);
						DBU_insert_if_completion_trx_save((struct IF_COMPLETION_TRX_SAVE_TAG *)&IF_COMPLETION_TRX);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX_SAVE INSERT", MP_NVST);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}

						DBU_init_if_completion_trx_save(&IF_COMPLETION_TRX_SAVE);
						DBU_insert_if_completion_trx_save((struct IF_COMPLETION_TRX_SAVE_TAG *)&IF_COMPLETION_TRX_MASTER);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "IF_COMPLETION_TRX_SAVE_MASTER INSERT", MP_NVST);
							TRS.add_dberrmsg(out_node, DB_error_msg);
							return MP_FALSE;
						}
					}
				}
				else if (IF_COMPLETION_TRX.TRAN_TYPE_ID == atoi(MP_ERP_TRAN_TYPE_ID_44))
				{
					DBU_init_if_completion_trx(&IF_COMPLETION_TRX);

					memset(sCmfValue, 0x00, sizeof(sCmfValue));
					COM_dtoa(sCmfValue, IF_COMPLETION_TRX.IF_SEQ, sizeof(sCmfValue));
					memcpy(IF_COMPLETION_TRX.CMF_10, sCmfValue, sizeof(IF_COMPLETION_TRX.CMF_10));

					DBU_select_if_completion_trx(4, &IF_COMPLETION_TRX);
					if (DB_error_code == DB_SUCCESS)
					{
						return MP_TRUE;
					}
				}
				else {

					// IFS-0006 : IF_COMPLETION_TRX 이력 취소 할 수 없는 IF DATA 입니다.
					strcpy(s_msg_code, "IFS-0006");

					TRS.add_fieldmsg(out_node, "IF_SEQ", DT_INT, IF_COMPLETION_TRX.IF_SEQ);
					return MP_FALSE;
				}
			}					
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		// MOVE TRX CANCEL
		DBU_init_if_move_trx(&IF_MOVE_TRX);
		IF_MOVE_TRX.IF_SEQ = TRS.get_int(in_node, "IF_SEQ");
		DBU_select_if_move_trx(1, &IF_MOVE_TRX);
		if (DB_error_code == DB_SUCCESS)
		{
			if (memcmp(IF_MOVE_TRX.TO_STEP, MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S)) == 0)
			{
				if_tran_in = TRS.add_node(in_node, "if_tran_in");
				TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_tran_in, in_node);

				TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
				TRS.add_string(if_tran_in, "WO_ID", IF_MOVE_TRX.WO_ID, sizeof(IF_MOVE_TRX.WO_ID));
				TRS.add_int(if_tran_in, "ERP_WO_ID", IF_MOVE_TRX.ERP_WO_ID);
				TRS.add_string(if_tran_in, "AREA_ID", IF_MOVE_TRX.AREA_ID, sizeof(IF_MOVE_TRX.AREA_ID));
				TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_MOVE_TRX.ERP_AREA_ID);
				TRS.add_string(if_tran_in, "FROM_OPER", IF_MOVE_TRX.TO_OPER, sizeof(IF_MOVE_TRX.TO_OPER));
				TRS.add_string(if_tran_in, "FROM_STEP", MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S));
				TRS.add_int(if_tran_in, "FROM_STEP_TYPE", 5);
				TRS.add_int(if_tran_in, "FROM_OPER_SEQ", IF_MOVE_TRX.TO_OPER_SEQ);
				TRS.add_string(if_tran_in, "TO_OPER", IF_MOVE_TRX.FROM_OPER, sizeof(IF_MOVE_TRX.FROM_OPER));
				TRS.add_string(if_tran_in, "TO_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
				TRS.add_int(if_tran_in, "TO_STEP_TYPE", 1);
				TRS.add_int(if_tran_in, "TO_OPER_SEQ", IF_MOVE_TRX.FROM_OPER_SEQ);
				TRS.add_string(if_tran_in, "UNIT", IF_MOVE_TRX.UNIT, sizeof(IF_MOVE_TRX.UNIT));
				TRS.add_double(if_tran_in, "QTY", IF_MOVE_TRX.QTY);
				TRS.add_string(if_tran_in, "OPER", IF_MOVE_TRX.MES_OPER, sizeof(IF_MOVE_TRX.MES_OPER));
				TRS.add_string(if_tran_in, "LOT_ID", IF_MOVE_TRX.LOT_ID, sizeof(IF_MOVE_TRX.LOT_ID));
				TRS.add_char(if_tran_in, "OVER_FLAG", 'N');

				memset(sCmfValue, 0x00, sizeof(sCmfValue));
				COM_dtoa(sCmfValue, IF_MOVE_TRX.IF_SEQ, sizeof(sCmfValue));
				TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_MOVE_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);
				
				DBU_init_if_move_trx_save(&IF_MOVE_TRX_SAVE);
				DBU_insert_if_move_trx_save((struct IF_MOVE_TRX_SAVE_TAG *)&IF_MOVE_TRX);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "IF_MOVE_TRX_SAVE INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}

			}
			else {
				if_tran_in = TRS.add_node(in_node, "if_tran_in");
				TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_tran_in, in_node);

				TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
				TRS.add_string(if_tran_in, "WO_ID", IF_MOVE_TRX.WO_ID, sizeof(IF_MOVE_TRX.WO_ID));
				TRS.add_int(if_tran_in, "ERP_WO_ID", IF_MOVE_TRX.ERP_WO_ID);
				TRS.add_string(if_tran_in, "AREA_ID", IF_MOVE_TRX.AREA_ID, sizeof(IF_MOVE_TRX.AREA_ID));
				TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_MOVE_TRX.ERP_AREA_ID);
				TRS.add_string(if_tran_in, "FROM_OPER", IF_MOVE_TRX.TO_OPER, sizeof(IF_MOVE_TRX.TO_OPER));
				TRS.add_int(if_tran_in, "FROM_OPER_SEQ", IF_MOVE_TRX.TO_OPER_SEQ);
				TRS.add_string(if_tran_in, "FROM_STEP", IF_MOVE_TRX.TO_STEP, sizeof(IF_MOVE_TRX.TO_STEP));
				TRS.add_int(if_tran_in, "FROM_STEP_TYPE", IF_MOVE_TRX.TO_STEP_TYPE);
				TRS.add_string(if_tran_in, "TO_OPER", IF_MOVE_TRX.FROM_OPER, sizeof(IF_MOVE_TRX.FROM_OPER));
				TRS.add_string(if_tran_in, "TO_STEP", IF_MOVE_TRX.FROM_STEP, sizeof(IF_MOVE_TRX.FROM_STEP));
				TRS.add_int(if_tran_in, "TO_OPER_SEQ", IF_MOVE_TRX.FROM_OPER_SEQ);
				TRS.add_int(if_tran_in, "TO_STEP_TYPE", IF_MOVE_TRX.FROM_STEP_TYPE);
				TRS.add_string(if_tran_in, "UNIT", IF_MOVE_TRX.UNIT, sizeof(IF_MOVE_TRX.UNIT));
				TRS.add_double(if_tran_in, "QTY", IF_MOVE_TRX.QTY);
				TRS.add_string(if_tran_in, "OPER", IF_MOVE_TRX.MES_OPER, sizeof(IF_MOVE_TRX.MES_OPER));
				TRS.add_string(if_tran_in, "LOT_ID", IF_MOVE_TRX.LOT_ID, sizeof(IF_MOVE_TRX.LOT_ID));
				TRS.add_char(if_tran_in, "OVER_FLAG", IF_MOVE_TRX.OVER_FLAG);


				memset(sCmfValue, 0x00, sizeof(sCmfValue));
				COM_dtoa(sCmfValue, IF_MOVE_TRX.IF_SEQ, sizeof(sCmfValue));
				TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_MOVE_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);

				DBU_init_if_move_trx_save(&IF_MOVE_TRX_SAVE);
				DBU_insert_if_move_trx_save((struct IF_MOVE_TRX_SAVE_TAG *)&IF_MOVE_TRX);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "IF_MOVE_TRX_SAVE INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}			
		}
	}
	else if (TRS.get_procstep(in_node) == '3') {
		// COMP ISSUE TRX CANCEL
		DBU_init_if_comp_issue_trx(&IF_COMP_ISSUE_TRX);
		IF_COMP_ISSUE_TRX.IF_SEQ = TRS.get_int(in_node, "IF_SEQ");
		DBU_select_if_comp_issue_trx(1, &IF_COMP_ISSUE_TRX);
		if (DB_error_code == DB_SUCCESS)
		{
			if (IF_COMP_ISSUE_TRX.TRAN_TYPE_ID == atoi(MP_ERP_TRAN_TYPE_ID_35))
			{
				if_tran_in = TRS.add_node(in_node, "if_tran_in");
				TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_tran_in, in_node);

				TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
				TRS.add_string(if_tran_in, "WO_ID", IF_COMP_ISSUE_TRX.WO_ID, sizeof(IF_COMP_ISSUE_TRX.WO_ID));
				TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMP_ISSUE_TRX.ERP_WO_ID);
				TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_43));
				TRS.add_string(if_tran_in, "AREA_ID", IF_COMP_ISSUE_TRX.AREA_ID, sizeof(IF_COMP_ISSUE_TRX.AREA_ID));
				TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMP_ISSUE_TRX.ERP_AREA_ID);
				TRS.add_string(if_tran_in, "SUB_AREA_ID", IF_COMP_ISSUE_TRX.SUB_AREA_ID, sizeof(IF_COMP_ISSUE_TRX.SUB_AREA_ID));
				TRS.add_int(if_tran_in, "ERP_SUB_AREA_ID", IF_COMP_ISSUE_TRX.ERP_SUB_AREA_ID);
				TRS.add_int(if_tran_in, "OPER_SEQ", IF_COMP_ISSUE_TRX.OPER_SEQ);
				TRS.add_string(if_tran_in, "OPER", IF_COMP_ISSUE_TRX.OPER, sizeof(IF_COMP_ISSUE_TRX.OPER));
				TRS.add_string(if_tran_in, "INV_OPER", IF_COMP_ISSUE_TRX.INV_OPER, sizeof(IF_COMP_ISSUE_TRX.INV_OPER));
				TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMP_ISSUE_TRX.ERP_MAT_ID);
				TRS.add_string(if_tran_in, "MAT_ID", IF_COMP_ISSUE_TRX.MAT_ID, sizeof(IF_COMP_ISSUE_TRX.MAT_ID));
				TRS.add_string(if_tran_in, "UNIT", IF_COMP_ISSUE_TRX.UNIT, sizeof(IF_COMP_ISSUE_TRX.UNIT));

                TRS.add_double(if_tran_in, "QTY", -1 * TRS.get_double(in_node, "QTY"));
				//TRS.add_double(if_tran_in, "QTY", -1 * IF_COMP_ISSUE_TRX.QTY);

				memset(sCmfValue, 0x00, sizeof(sCmfValue));
				//COM_dtoa(sCmfValue, IF_COMP_ISSUE_TRX.IF_SEQ, sizeof(sCmfValue));
                sprintf(sCmfValue, "%.0f", IF_COMP_ISSUE_TRX.IF_SEQ);

                TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값
                TRS.add_string(if_tran_in, "CMF_1", IF_COMP_ISSUE_TRX.CMF_1, sizeof(IF_COMP_ISSUE_TRX.CMF_1)); // 취소하기 위해 참조한 lot id

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);

				DBU_init_if_comp_issue_trx_save(&IF_COMP_ISSUE_TRX_SAVE);
				DBU_insert_if_comp_issue_trx_save((struct IF_COMP_ISSUE_TRX_SAVE_TAG *)&IF_COMP_ISSUE_TRX);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "IF_COMP_ISSUE_TRX_SAVE INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
			else {
				if_tran_in = TRS.add_node(in_node, "if_tran_in");
				TRS.add_char(if_tran_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(if_tran_in, in_node);

				TRS.add_char(if_tran_in, "TRAN_FLAG", MP_STEP_DELETE);
				TRS.add_string(if_tran_in, "WO_ID", IF_COMP_ISSUE_TRX.WO_ID, sizeof(IF_COMP_ISSUE_TRX.WO_ID));
				TRS.add_int(if_tran_in, "ERP_WO_ID", IF_COMP_ISSUE_TRX.ERP_WO_ID);
				TRS.add_int(if_tran_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));

				TRS.add_string(if_tran_in, "AREA_ID", IF_COMP_ISSUE_TRX.AREA_ID, sizeof(IF_COMP_ISSUE_TRX.AREA_ID));
				TRS.add_int(if_tran_in, "ERP_AREA_ID", IF_COMP_ISSUE_TRX.ERP_AREA_ID);
				TRS.add_string(if_tran_in, "SUB_AREA_ID", IF_COMP_ISSUE_TRX.SUB_AREA_ID, sizeof(IF_COMP_ISSUE_TRX.SUB_AREA_ID));
				TRS.add_int(if_tran_in, "ERP_SUB_AREA_ID", IF_COMP_ISSUE_TRX.ERP_SUB_AREA_ID);
				TRS.add_int(if_tran_in, "OPER_SEQ", IF_COMP_ISSUE_TRX.OPER_SEQ);

				TRS.add_string(if_tran_in, "OPER", IF_COMP_ISSUE_TRX.INV_OPER, sizeof(IF_COMP_ISSUE_TRX.INV_OPER));
				TRS.add_string(if_tran_in, "INV_OPER", IF_COMP_ISSUE_TRX.OPER, sizeof(IF_COMP_ISSUE_TRX.OPER));
				TRS.add_int(if_tran_in, "ERP_MAT_ID", IF_COMP_ISSUE_TRX.ERP_MAT_ID);
				TRS.add_string(if_tran_in, "MAT_ID", IF_COMP_ISSUE_TRX.MAT_ID, sizeof(IF_COMP_ISSUE_TRX.MAT_ID));
				TRS.add_string(if_tran_in, "UNIT", IF_COMP_ISSUE_TRX.UNIT, sizeof(IF_COMP_ISSUE_TRX.UNIT));
				TRS.add_double(if_tran_in, "QTY", IF_COMP_ISSUE_TRX.QTY);

				memset(sCmfValue, 0x00, sizeof(sCmfValue));
				COM_dtoa(sCmfValue, IF_COMP_ISSUE_TRX.IF_SEQ, sizeof(sCmfValue));
				TRS.add_string(if_tran_in, "CMF_10", sCmfValue, sizeof(sCmfValue)); // 취소하기 위해 참조한 IF_SEQ 값

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, if_tran_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);

				DBU_init_if_comp_issue_trx_save(&IF_COMP_ISSUE_TRX_SAVE);
				DBU_insert_if_comp_issue_trx_save((struct IF_COMP_ISSUE_TRX_SAVE_TAG *)&IF_COMP_ISSUE_TRX);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "IF_COMP_ISSUE_TRX_SAVE INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);
					return MP_FALSE;
				}
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '4') {
	}
	else if (TRS.get_procstep(in_node) == '5') {

	}
	else if (TRS.get_procstep(in_node) == '6') {

	}
	return MP_TRUE;
}
