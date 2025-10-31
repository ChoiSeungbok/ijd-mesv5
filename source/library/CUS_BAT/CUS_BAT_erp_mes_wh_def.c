/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_wh_def.c
Description : ERP -> MES ERP 창고 공정 정보

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/22  MIRACOM        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_BAT_common.h"

int CUS_BAT_ERP_MES_WH_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Wh_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Wh_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_WH_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Wh_Def", out_node);


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
CUS_BAT_ERP_MES_WH_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Wh_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_WH_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_WH_DEF_TAG IF_WH_DEF;
	struct IF_WH_DEF_HIS_TAG IF_WH_DEF_HIS;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MWIPFLWDEF_TAG MWIPFLWDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	TRSNode *tran_in_node;
	TRSNode *tran_out_node;

	TRSNode *tran_in_node2;
	TRSNode *tran_out_node2;

	char Error_Msg[201];

	int i_step = 0;

	LOG_head("CUS_BAT_Erp_Mes_Wh_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));


	//20211124 창고인터페이스 의미없음,어치피 수기로 넣어야됨 "C_ERP_OPER" GCM에 ERP 공정 추가해놔야 처리됨 그냥 배치에서 죽임.
	// 나중에 수정개선되면 그때살릴예정.

	// OPEN
	i_step = 101;

	DBU_init_if_wh_def(&IF_WH_DEF);
	DBU_open_if_wh_def(i_step, &IF_WH_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WH_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WH_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WH_DEF.FACTORY), IF_WH_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WH_DEF.ORG_CODE), IF_WH_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "INV_OPER", MP_STR, sizeof(IF_WH_DEF.INV_OPER), IF_WH_DEF.INV_OPER);
			TRS.add_fieldmsg(out_node, "INV_OPER_DESC", MP_STR, sizeof(IF_WH_DEF.INV_OPER_DESC), IF_WH_DEF.INV_OPER_DESC);


			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_wh_def(i_step, &IF_WH_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_wh_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_WH_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_WH_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_WH_DEF.FACTORY), IF_WH_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ORG_CODE", MP_STR, sizeof(IF_WH_DEF.ORG_CODE), IF_WH_DEF.ORG_CODE);
			TRS.add_fieldmsg(out_node, "INV_OPER", MP_STR, sizeof(IF_WH_DEF.INV_OPER), IF_WH_DEF.INV_OPER);
			TRS.add_fieldmsg(out_node, "INV_OPER_DESC", MP_STR, sizeof(IF_WH_DEF.INV_OPER_DESC), IF_WH_DEF.INV_OPER_DESC);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		// DW 사업부는 안내려주기로 했는데 자꾸 내려와서 별도 처리함.
		if (memcmp(IF_WH_DEF.ORG_CODE, "DW", strlen("DW")) == 0)
		{
			strcpy(s_msg_code, "IFS-0005");

			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_WH_DEF.IF_CODE = 'E';
			memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
			DBU_update_if_wh_def(101, &IF_WH_DEF);
			DB_commit();
			continue;
		}

		if (COM_isnullspace(IF_WH_DEF.DISABLE_DATE) == MP_TRUE)
		{
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			memcpy(MWIPOPRDEF.FACTORY, IF_WH_DEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));

			
			// OPER 의 맨 앞에 사업부 첫글자를 추가하여 창고 코드를 만들어준다.
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			memcpy(MGCMTBLDAT.FACTORY, IF_WH_DEF.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
			memcpy(MGCMTBLDAT.KEY_1, IF_WH_DEF.ORG_CODE, sizeof(IF_WH_DEF.ORG_CODE));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				if (DB_error_code == DB_NOT_FOUND)
				{					
					strcpy(s_msg_code, "GCM-0008");
				}
				else {
					strcpy(s_msg_code, "GCM-0007");
				}
				
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_WH_DEF.IF_CODE = 'E';
				memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
			
				DBU_update_if_wh_def(101, &IF_WH_DEF);
				DB_commit();
				continue;
			}
			

			MWIPOPRDEF.OPER[0] = MGCMTBLDAT.DATA_3[0];
			memcpy(MWIPOPRDEF.OPER+1, IF_WH_DEF.INV_OPER, sizeof(MWIPOPRDEF.OPER));

			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			// 신규 창고만 처리한다.			
			if (DB_error_code == DB_NOT_FOUND)
			{
				tran_in_node = TRS.create_node("UPDATE_OPER_IN");
				tran_out_node = TRS.create_node("CMN_OUT");

				TRS.set_string(tran_in_node, "FACTORY", IF_WH_DEF.FACTORY, sizeof(IF_WH_DEF.FACTORY));
				TRS.set_char(tran_in_node, "PROCSTEP", MP_STEP_CREATE);

				TRS.set_string(tran_in_node, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				TRS.set_string(tran_in_node, "OPER_DESC", IF_WH_DEF.INV_OPER_DESC, sizeof(IF_WH_DEF.INV_OPER_DESC));

				// ERP에서 창고 종류 주는게 없어서 Default는 생산창고로 고정
				TRS.set_nstring(tran_in_node, "OPER_GRP_1", MP_OPER_GRP_TYPE_OPER);
				TRS.set_nstring(tran_in_node, "OPER_GRP_2", "NONE");

				TRS.set_string(tran_in_node, "OPER_CMF_1", IF_WH_DEF.INV_OPER, sizeof(IF_WH_DEF.INV_OPER));

				TRS.set_string(tran_in_node, "AREA_ID", IF_WH_DEF.ORG_CODE, sizeof(IF_WH_DEF.ORG_CODE));

				// ERP에서 창고 단위 주는게 없어서 일단 셋팅
				TRS.set_nstring(tran_in_node, "UNIT_1", "EA");
				TRS.set_char(tran_in_node, "INV_FLAG", 'Y');

				if (WIP_UPDATE_OPERATION(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE)
				{
					DB_rollback();
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WH_DEF.IF_CODE = 'E';
					memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
					DBU_update_if_wh_def(101, &IF_WH_DEF);
					DB_commit();
					continue;
				}

				// 신규 창고인 경우 FLOW 를 XF 붙여서 새로 생성해주고 해당 창고를 매핑
				DBU_init_mwipflwdef(&MWIPFLWDEF);
				memcpy(MWIPFLWDEF.FACTORY, IF_WH_DEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
				MWIPFLWDEF.FLOW[0] = 'X';
				MWIPFLWDEF.FLOW[1] = 'F';
				memcpy(MWIPFLWDEF.FLOW + 2, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

				DBU_select_mwipflwdef(1, &MWIPFLWDEF);

				if (DB_error_code == DB_NOT_FOUND)
				{
					tran_in_node2 = TRS.create_node("UPDATE_FLOW_IN");
					tran_out_node2 = TRS.create_node("CMN_OUT");

					TRS.set_string(tran_in_node2, "FACTORY", MWIPFLWDEF.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
					TRS.set_char(tran_in_node2, "PROCSTEP", MP_STEP_CREATE);

					TRS.set_string(tran_in_node2, "FLOW", MWIPFLWDEF.FLOW, sizeof(MWIPFLWDEF.FLOW));
					TRS.set_string(tran_in_node2, "FLOW_DESC", IF_WH_DEF.INV_OPER_DESC, sizeof(IF_WH_DEF.INV_OPER_DESC));

					if (WIP_UPDATE_FLOW(s_msg_code, tran_in_node2, tran_out_node2) == MP_FALSE)
					{
						DB_rollback();
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						IF_WH_DEF.IF_CODE = 'E';
						memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
						DBU_update_if_wh_def(101, &IF_WH_DEF);
						DB_commit();

						TRS.free_node(tran_in_node2);
						TRS.free_node(tran_out_node2);
						continue;
					}

					// Attach Oper to Flow
					TRS.set_char(tran_in_node2, "PROCSTEP", '1');
					TRS.set_string(tran_in_node2, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));

					if (WIP_ATTACH_OPER_TOFLOW(s_msg_code, tran_in_node2, tran_out_node2) == MP_FALSE)
					{
						DB_rollback();
						COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

						IF_WH_DEF.IF_CODE = 'E';
						memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
						DBU_update_if_wh_def(101, &IF_WH_DEF);
						DB_commit();

						continue;
					}


					TRS.free_node(tran_in_node2);
					TRS.free_node(tran_out_node2);
				}

				TRS.free_node(tran_in_node);
				TRS.free_node(tran_out_node);
			}
			else {
				// 창고명만 업데이트
				memset(MWIPOPRDEF.OPER_DESC, 0x00, sizeof(MWIPOPRDEF.OPER_DESC));
				memset(MWIPOPRDEF.OPER_SHORT_DESC, 0x00, sizeof(MWIPOPRDEF.OPER_SHORT_DESC));
				
				memcpy(MWIPOPRDEF.OPER_DESC, IF_WH_DEF.INV_OPER_DESC, sizeof(IF_WH_DEF.INV_OPER_DESC));
				memcpy(MWIPOPRDEF.OPER_SHORT_DESC, IF_WH_DEF.INV_OPER_DESC, sizeof(MWIPOPRDEF.OPER_SHORT_DESC));

				memcpy(MWIPOPRDEF.UPDATE_TIME, gs_sys_time, sizeof(MWIPOPRDEF.UPDATE_TIME));
				memcpy(MWIPOPRDEF.UPDATE_USER_ID, MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));

				DBU_update_mwipoprdef(2, &MWIPOPRDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					DB_rollback();
					strcpy(s_msg_code, "WIP-0004");
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_WH_DEF.IF_CODE = 'E';
					memcpy(IF_WH_DEF.IF_MSG, Error_Msg, sizeof(IF_WH_DEF.IF_MSG));
					DBU_update_if_wh_def(101, &IF_WH_DEF);
					DB_commit();

					continue;
				}
			}
		}		

		// BACKUP
		DBU_init_if_wh_def_his(&IF_WH_DEF_HIS);

		IF_WH_DEF_HIS.IF_SEQ = IF_WH_DEF.IF_SEQ;

		DBU_delete_if_wh_def_his(1, &IF_WH_DEF_HIS);
		DBU_insert_if_wh_def_his((struct IF_WH_DEF_HIS_TAG *)&IF_WH_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_WH_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_wh_def(1, &IF_WH_DEF);

		DB_commit();
	}

	return MP_TRUE;
}

