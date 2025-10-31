/*******************************************************************************

System      : MESplus
Module      : CUS_BAT
File Name   : CUS_BAT_erp_mes_mat_def.c
Description : ERP -> MES 품목마스터 정보

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

int CUS_BAT_ERP_MES_MAT_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_BAT_Erp_Mes_Mat_Def()
-
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_Erp_Mes_Mat_Def(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_BAT_ERP_MES_MAT_DEF(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
	{
		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_SETUP;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
	}

	COM_out_msg_log_write(s_msg_code, "CUS_BAT_Erp_Mes_Mat_Def", out_node);


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
CUS_BAT_ERP_MES_MAT_DEF()
- Main sub function of "CUS_BAT_Erp_Mes_Mat_Def" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAT_ERP_MES_MAT_DEF(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct IF_MAT_DEF_TAG IF_MAT_DEF;
	struct IF_MAT_DEF_HIS_TAG IF_MAT_DEF_HIS;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPMATFLW_TAG MWIPMATFLW;

	int i_step = 0;
	int i_step_2 = 0;

	TRSNode *tran_in_node;
	TRSNode *tran_out_node;

	TRSNode *cmf_in_node;
	TRSNode *cmf_out_node;

	TRSNode *attr_in_node;
	TRSNode *attr_out_node;
	TRSNode *attr_list;

	TRSNode *attach_in_node;
	TRSNode *attach_out_node;

	char procStep;

	char s_erp_mat_id[30];
	//char s_erp_mat_grade[30];
	char s_item_desc[241];
	char Error_Msg[201];

	int i_size = 0;

	LOG_head("CUS_BAT_Erp_Mes_Mat_Def");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(Error_Msg, 0x00, sizeof(Error_Msg));

	// OPEN
	i_step = 101;

	DBU_init_if_mat_def(&IF_MAT_DEF);
	DBU_open_if_mat_def(i_step, &IF_MAT_DEF);
	if (DB_error_code != DB_SUCCESS)
	{
		if (DB_error_code == DB_NOT_FOUND)
		{
			return MP_TRUE;
		}
		else
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_MAT_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_MAT_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_MAT_DEF.FACTORY), IF_MAT_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ITEM_ID", MP_INT, IF_MAT_DEF.ITEM_ID);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_INT, IF_MAT_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "MAT_DESC", MP_INT, IF_MAT_DEF.ITEM_DESC);			
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}
	}

	// FETCH
	while (1)
	{
		DBU_fetch_if_mat_def(i_step, &IF_MAT_DEF);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_if_mat_def(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "WIP-0004");
			TRS.add_fieldmsg(out_node, "IF_MAT_DEF OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "IF_SEQ", MP_INT, IF_MAT_DEF.IF_SEQ);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(IF_MAT_DEF.FACTORY), IF_MAT_DEF.FACTORY);
			TRS.add_fieldmsg(out_node, "ITEM_ID", MP_INT, IF_MAT_DEF.ITEM_ID);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_INT, IF_MAT_DEF.ITEM_CODE);
			TRS.add_fieldmsg(out_node, "MAT_DESC", MP_INT, IF_MAT_DEF.ITEM_DESC);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		//AREA CHECK
		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
		memcpy(MGCMTBLDAT.KEY_1, IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
		DBC_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			DB_rollback();

			strcpy(s_msg_code, "RAS-0011");
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_MAT_DEF.IF_CODE = 'E';
			memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
			DBU_update_if_mat_def(101, &IF_MAT_DEF);

			DB_commit();
			continue;
		}


		DBC_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, IF_MAT_DEF.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, IF_MAT_DEF.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBC_select_mwipmatdef(1, &MWIPMATDEF);

		if (DB_error_code == DB_NOT_FOUND)
		{
			//CREATE
			procStep = MP_STEP_CREATE;
			if (IF_MAT_DEF.ENABLED_FLAG == 'N')
			{
				// BACKUP
				DBU_init_if_mat_def_his(&IF_MAT_DEF_HIS);

				IF_MAT_DEF_HIS.IF_SEQ = IF_MAT_DEF.IF_SEQ;

				DBU_delete_if_mat_def_his(1, &IF_MAT_DEF_HIS);
				DBU_insert_if_mat_def_his((struct IF_MAT_DEF_HIS_TAG *)&IF_MAT_DEF);
				if (DB_error_code != DB_SUCCESS)
				{
					//DO NOTHING
				}

				// DELETE
				DBU_delete_if_mat_def(1, &IF_MAT_DEF);
				if (DB_error_code != DB_SUCCESS)
				{
					//DO NOTHING
				}

				continue;
			}
		}
		else
		{
			if (IF_MAT_DEF.ENABLED_FLAG == 'N')
			{
				//DELETE
				if (MWIPMATDEF.DELETE_FLAG == 'Y')
				{
					//이미 삭제된 케이스
					// BACKUP
					DBU_init_if_mat_def_his(&IF_MAT_DEF_HIS);

					IF_MAT_DEF_HIS.IF_SEQ = IF_MAT_DEF.IF_SEQ;

					DBU_delete_if_mat_def_his(1, &IF_MAT_DEF_HIS);
					DBU_insert_if_mat_def_his((struct IF_MAT_DEF_HIS_TAG *) &IF_MAT_DEF);
					if (DB_error_code != DB_SUCCESS)
					{
						//DO NOTHING
					}

					// DELETE
					DBU_delete_if_mat_def(1, &IF_MAT_DEF);
					if (DB_error_code != DB_SUCCESS)
					{
						//DO NOTHING
					}

					continue;
				}
				procStep = MP_STEP_DELETE;
			}
			else
			{
				if (MWIPMATDEF.DELETE_FLAG == 'Y')
				{
					//UNDELETE (이후 필요하면 UPDATE LOGIC 들어가야함)
					procStep = MP_STEP_UNDELETE;
				}
				else
				{
					//UPDATE
					procStep = MP_STEP_UPDATE;
				}
			}
		}

		tran_in_node = TRS.create_node("UPDATE_MATERIAL_IN");
		tran_out_node = TRS.create_node("CMN_OUT");

		TRS.set_string(tran_in_node, "FACTORY", IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		TRS.set_char(tran_in_node, "PROCSTEP", procStep);

		// IF_MAT_DEF.ITEM_CODE size 40 이어서 문제 생길 수 있음. MES 는 30
		memcpy(MWIPMATDEF.MAT_ID, IF_MAT_DEF.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));

		TRS.set_string(tran_in_node, "MAT_ID", IF_MAT_DEF.ITEM_CODE, sizeof(MWIPMATDEF.MAT_ID));
		TRS.set_int(tran_in_node, "MAT_VER", 1);

		// IF_MAT_DEF.ITEM_DESC size 240 이어서 문제 생길 수 있음. MES 는 200
		TRS.set_string(tran_in_node, "MAT_DESC", IF_MAT_DEF.ITEM_DESC, sizeof(MWIPMATDEF.MAT_DESC));


		//MAT_TYPE (CLASS): 
		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_MATERIAL_TYPE, strlen(MP_GCM_MATERIAL_TYPE));
		memcpy(MGCMTBLDAT.KEY_1, IF_MAT_DEF.ITEM_TYPE, sizeof(MGCMTBLDAT.KEY_1));
		DBC_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			memcpy(MGCMTBLDAT.DATA_1, IF_MAT_DEF.ITEM_TYPE_DESC, sizeof(MGCMTBLDAT.DATA_1));
			DBC_insert_mgcmtbldat(&MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				//DO NOTHING
			}
		}
		TRS.set_string(tran_in_node, "MAT_TYPE", IF_MAT_DEF.ITEM_TYPE, sizeof(IF_MAT_DEF.ITEM_TYPE));


		if (procStep == MP_STEP_CREATE)
		{
			// 신규인경우 일단 ORG_CODE 로 셋팅하고, 이전에 셋팅된 사업부 코드와 다른 경우 ALL 로 변경.		
			TRS.set_string(tran_in_node, "MAT_GRP_1", IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
		}
		else {
			if (memcmp(MWIPMATDEF.MAT_GRP_1, IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE)) != 0
				|| COM_isnullspace(IF_MAT_DEF.ORG_CODE) == MP_TRUE)
			{
				TRS.set_string(tran_in_node, "MAT_GRP_1", "ALL", strlen("ALL"));
			}
			else {
				TRS.set_string(tran_in_node, "MAT_GRP_1", IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
			}
		}

		// MAT_GRP_2, MAT_GRP_3, MAT_GRP_4, MAT_GRP_5, MAT_GRP_6, MAT_GRP_7
		// 각 그룹별 [N/A] 값으로 통일 

		TRS.set_string(tran_in_node, "MAT_GRP_2", "GRP10001", strlen("GRP10001"));
		TRS.set_string(tran_in_node, "MAT_GRP_3", "GRP20001", strlen("GRP20001"));
		TRS.set_string(tran_in_node, "MAT_GRP_4", "GRP30001", strlen("GRP30001"));
		TRS.set_string(tran_in_node, "MAT_GRP_5", "GRP40001", strlen("GRP40001"));
		TRS.set_string(tran_in_node, "MAT_GRP_6", "GRP50001", strlen("GRP50001"));
		TRS.set_string(tran_in_node, "MAT_GRP_7", "GRP60001", strlen("GRP60001"));
		

		//MGCMTBLDAT ( UNIT)
		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_UNIT, strlen(MP_GCM_UNIT));
		memcpy(MGCMTBLDAT.KEY_1, IF_MAT_DEF.UNIT, sizeof(IF_MAT_DEF.UNIT));
		DBC_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			memcpy(MGCMTBLDAT.DATA_1, IF_MAT_DEF.UNIT, sizeof(IF_MAT_DEF.UNIT));
			DBC_insert_mgcmtbldat(&MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				//DO NOTHING
			}
		}

		TRS.set_string(tran_in_node, "UNIT1", IF_MAT_DEF.UNIT, sizeof(IF_MAT_DEF.UNIT));

		memset(s_erp_mat_id, 0x00, sizeof(s_erp_mat_id));

		COM_itoa_left(s_erp_mat_id, IF_MAT_DEF.ITEM_ID, sizeof(s_erp_mat_id));

		//CMF_1 : ERP_MAT_ID
		TRS.set_string(tran_in_node, "MAT_CMF_1", s_erp_mat_id, strlen(s_erp_mat_id));


		//20230413 GRADE 가져오도록 추가
		//memset(s_erp_mat_grade, 0x00, sizeof(s_erp_mat_grade));

		//COM_itoa_left(s_erp_mat_grade, IF_MAT_DEF.CATALOG_VALUE10, sizeof(s_erp_mat_grade));

		//CMF_3 : Grade
		TRS.set_string(tran_in_node, "MAT_CMF_3", IF_MAT_DEF.CATALOG_VALUE10, strlen(IF_MAT_DEF.CATALOG_VALUE10));


		// CMF_7 : Material Class For Summary and Report
		i_step_2 = 2;  //

		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_MAT_CLASS_1_MAP, strlen(MP_GCM_MAT_CLASS_1_MAP));
		memcpy(MGCMTBLDAT.KEY_1, IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
		DBU_open_mgcmtbldat(i_step_2, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		// FETCH
		while (1)
		{
			DBU_fetch_mgcmtbldat(i_step_2, &MGCMTBLDAT);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_mgcmtbldat(i_step_2);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "BAS-0004");
				TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			// 소문자가 섞여 있어서 대문자로 일단 변환한번 하고 비교한다.
			memset(s_item_desc, 0x00, sizeof(s_item_desc));
			COM_toupper(s_item_desc, IF_MAT_DEF.ITEM_DESC, sizeof(IF_MAT_DEF.ITEM_DESC));

			i_size = COM_string_length(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2));

			if (COM_search_string(s_item_desc, sizeof(s_item_desc), MGCMTBLDAT.KEY_2, i_size) > -1)
			{
				TRS.set_string(tran_in_node, "MAT_CMF_7", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
			}
		}
		

		cmf_in_node = TRS.create_node("UPDATE_MATERIAL_IN");
		cmf_out_node = TRS.create_node("CMN_OUT");

		TRS.set_string(cmf_in_node, "FACTORY", IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
		TRS.set_string(cmf_in_node, "AREA_ID", IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
		TRS.set_string(cmf_in_node, "MAT_TYPE", IF_MAT_DEF.ITEM_TYPE, sizeof(IF_MAT_DEF.ITEM_TYPE));

		// CATALOG_NAME 10
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME10, sizeof(IF_MAT_DEF.CATALOG_NAME10));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE10, sizeof(IF_MAT_DEF.CATALOG_VALUE10));		
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 20
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME20, sizeof(IF_MAT_DEF.CATALOG_NAME20));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE20, sizeof(IF_MAT_DEF.CATALOG_VALUE20));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 30
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME30, sizeof(IF_MAT_DEF.CATALOG_NAME30));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE30, sizeof(IF_MAT_DEF.CATALOG_VALUE30));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 40
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME40, sizeof(IF_MAT_DEF.CATALOG_NAME40));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE40, sizeof(IF_MAT_DEF.CATALOG_VALUE40));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 50
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME50, sizeof(IF_MAT_DEF.CATALOG_NAME50));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE50, sizeof(IF_MAT_DEF.CATALOG_VALUE50));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 60
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME60, sizeof(IF_MAT_DEF.CATALOG_NAME60));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE60, sizeof(IF_MAT_DEF.CATALOG_VALUE60));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		// CATALOG_NAME 70
		TRS.set_string(cmf_in_node, "CATALOG_NAME", IF_MAT_DEF.CATALOG_NAME70, sizeof(IF_MAT_DEF.CATALOG_NAME70));
		TRS.set_string(cmf_in_node, "CATALOG_VALUE", IF_MAT_DEF.CATALOG_VALUE70, sizeof(IF_MAT_DEF.CATALOG_VALUE70));
		if (SET_ERP_CATALOG_TO_MATERIAL(s_msg_code, cmf_in_node, cmf_out_node) == MP_TRUE)
		{
			TRS.set_nstring(tran_in_node, TRS.get_string(cmf_out_node, "CMF_NAME"), TRS.get_string(cmf_out_node, "CMF_VALUE"));
		}

		TRS_free_node(cmf_in_node);
		TRS_free_node(cmf_out_node);

		// INSERT GT(General Table)
		if (WIP_UPDATE_MATERIAL(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE)
		{
			DB_rollback();
			COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

			IF_MAT_DEF.IF_CODE = 'E';
			memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
			DBU_update_if_mat_def(101, &IF_MAT_DEF);
			
			DB_commit();
			continue;
		}

		if (procStep == MP_STEP_CREATE)
		{
			attach_in_node = TRS.create_node("ATTACH_FLOW_IN");
			attach_out_node = TRS.create_node("CMN_OUT");

			TRS.set_string(attach_in_node, "FACTORY", IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
			TRS.set_char(attach_in_node, "PROCSTEP", '1');

			TRS.set_string(attach_in_node, "MAT_ID", IF_MAT_DEF.ITEM_CODE, sizeof(IF_MAT_DEF.ITEM_CODE));
			TRS.set_int(attach_in_node, "MAT_VER", 1);

			DBC_init_mgcmtbldat(&MGCMTBLDAT);
			memcpy(MGCMTBLDAT.FACTORY, IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_AREA, strlen(MP_GCM_AREA));
			memcpy(MGCMTBLDAT.KEY_1, IF_MAT_DEF.ORG_CODE, sizeof(IF_MAT_DEF.ORG_CODE));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				DB_rollback();

				strcpy(s_msg_code, "WIP-0008");				
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_MAT_DEF.IF_CODE = 'E';
				memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
				DBU_update_if_mat_def(101, &IF_MAT_DEF);

				DB_commit();

				TRS_free_node(attach_in_node);
				TRS_free_node(attach_out_node);
				continue;
			}

			TRS.set_string(attach_in_node, "FLOW", MGCMTBLDAT.DATA_5, 20);

			// FLOW 존재하는지 체크하고 있으면 추가하지 않는다.
			DBU_init_mwipmatflw(&MWIPMATFLW);
			memcpy(MWIPMATFLW.FACTORY, IF_MAT_DEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
			memcpy(MWIPMATFLW.MAT_ID, IF_MAT_DEF.ITEM_CODE, sizeof(MWIPMATFLW.MAT_ID));
			MWIPMATFLW.MAT_VER = 1;
			memcpy(MWIPMATFLW.FLOW, MGCMTBLDAT.DATA_5, sizeof(MWIPMATFLW.FLOW));
			DBC_select_mwipmatflw(4, &MWIPMATFLW);

			if (DB_error_code == DB_NOT_FOUND)
			{
				if (WIP_ATTACH_FLOW_TOMATERIAL(s_msg_code, attach_in_node, attach_out_node) == MP_FALSE)
				{
					DB_rollback();
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_MAT_DEF.IF_CODE = 'E';
					memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
			
					DBU_update_if_mat_def(101, &IF_MAT_DEF);

					DB_commit();

					TRS_free_node(attach_in_node);
					TRS_free_node(attach_out_node);
					continue;
				}
			}



			//XF-990(전체 창고 플로우 완제품 창고,P급창고 빼고) _20211117 추가 
			// FLOW 존재하는지 체크하고 있으면 추가하지 않는다.
			DBU_init_mwipmatflw(&MWIPMATFLW);
			memcpy(MWIPMATFLW.FACTORY, IF_MAT_DEF.FACTORY, sizeof(MWIPMATFLW.FACTORY));
			memcpy(MWIPMATFLW.MAT_ID, IF_MAT_DEF.ITEM_CODE, sizeof(MWIPMATFLW.MAT_ID));
			MWIPMATFLW.MAT_VER = 1;
			memcpy(MWIPMATFLW.FLOW, "XF-990", strlen("XF-990"));
			DBC_select_mwipmatflw(4, &MWIPMATFLW);

			if (DB_error_code == DB_NOT_FOUND)
			{

				TRS.set_string(attach_in_node, "FLOW", "XF-990", strlen("XF-990"));

				if (WIP_ATTACH_FLOW_TOMATERIAL(s_msg_code, attach_in_node, attach_out_node) == MP_FALSE)
				{
					DB_rollback();
					COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

					IF_MAT_DEF.IF_CODE = 'E';
					memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
			
					DBU_update_if_mat_def(101, &IF_MAT_DEF);

					DB_commit();

					TRS_free_node(attach_in_node);
					TRS_free_node(attach_out_node);
					continue;
				}
			}

	



			TRS_free_node(attach_in_node);
			TRS_free_node(attach_out_node);
		}

		// ATTR Node Setup
		attr_in_node = TRS.create_node("UPDATE_MATERIAL_ATTR_IN");
		attr_out_node = TRS.create_node("ATTR_OUT");

		CopyDefaultMembers(attr_in_node, in_node);

		TRS.set_string(attr_in_node, "FACTORY", IF_MAT_DEF.FACTORY, sizeof(IF_MAT_DEF.FACTORY));

		// Process Step. Option for expansion (1: Update attribute value using current last active history sequence of ATTR_KEY(MAT_ID)
		TRS.set_char(attr_in_node, "PROCSTEP", '1');

		TRS.set_string(attr_in_node, "ATTR_TYPE", MP_ATTR_TYPE_MATERIAL, sizeof(MP_ATTR_TYPE_MATERIAL));
		TRS.set_string(attr_in_node, "ATTR_KEY", IF_MAT_DEF.CMF_1, sizeof(MWIPMATDEF.MAT_ID));


		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME10) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME10");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME10, sizeof(IF_MAT_DEF.CATALOG_NAME10));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE10");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE10, sizeof(IF_MAT_DEF.CATALOG_VALUE10));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME20) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME20");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME20, sizeof(IF_MAT_DEF.CATALOG_NAME20));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE20");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE20, sizeof(IF_MAT_DEF.CATALOG_VALUE20));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME30) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME30");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME30, sizeof(IF_MAT_DEF.CATALOG_NAME30));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE30");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE30, sizeof(IF_MAT_DEF.CATALOG_VALUE30));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME40) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME40");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME40, sizeof(IF_MAT_DEF.CATALOG_NAME40));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE40");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE40, sizeof(IF_MAT_DEF.CATALOG_VALUE40));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME50) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME50");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME50, sizeof(IF_MAT_DEF.CATALOG_NAME50));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE50");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE50, sizeof(IF_MAT_DEF.CATALOG_VALUE50));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME60) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME60");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME60, sizeof(IF_MAT_DEF.CATALOG_NAME60));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE60");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE60, sizeof(IF_MAT_DEF.CATALOG_VALUE60));
		}

		if (COM_isnullspace(IF_MAT_DEF.CATALOG_NAME70) == MP_FALSE)
		{
			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_NAME70");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_NAME70, sizeof(IF_MAT_DEF.CATALOG_NAME70));

			attr_list = TRS.add_node(attr_in_node, "VALUE_LIST");
			TRS.add_nstring(attr_list, "ATTR_NAME", "CATALOG_VALUE70");
			TRS.add_string(attr_list, "ATTR_VALUE", IF_MAT_DEF.CATALOG_VALUE70, sizeof(IF_MAT_DEF.CATALOG_VALUE70));
		}

		if (TRS.get_item_count(attr_in_node, "VALUE_LIST") > 0)
		{
			// Attribute update
			if (BAS_UPDATE_ATTRIBUTE_VALUE(s_msg_code, attr_in_node, attr_out_node) == MP_FALSE)
			{
				COM_get_message(TRS.get_language(in_node), s_msg_code, Error_Msg);

				IF_MAT_DEF.IF_CODE = 'E';
				memcpy(IF_MAT_DEF.IF_MSG, Error_Msg, sizeof(IF_MAT_DEF.IF_MSG));
				DBU_update_if_mat_def(101, &IF_MAT_DEF);
			}
		}
	
		// BACKUP
		DBU_init_if_mat_def_his(&IF_MAT_DEF_HIS);

		IF_MAT_DEF_HIS.IF_SEQ = IF_MAT_DEF.IF_SEQ;

		DBU_delete_if_mat_def_his(1, &IF_MAT_DEF_HIS);
		DBU_insert_if_mat_def_his((struct IF_MAT_DEF_HIS_TAG *)&IF_MAT_DEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			TRS.add_fieldmsg(out_node, "IF_MAT_DEF_HIS INSERT", MP_NVST);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;
			COM_set_field_db_msg(out_node, tran_out_node);

			TRS.free_node(tran_in_node);
			TRS.free_node(tran_out_node);
			return MP_FALSE;
		}

		// DELETE
		DBU_delete_if_mat_def(1, &IF_MAT_DEF);

		TRS.free_node(tran_in_node);
		TRS.free_node(tran_out_node);
		DB_commit();
	}

	return MP_TRUE;
}

