/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_Collect_Inspection_Data.c
Description : Tran Inspection Save function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/14  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Collect_Inspection_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Collect_Inspection_Data()
- Tran
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Inspection_Data(TRSNode *in_node, TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_QCM_COLLECT_INSPECTION_DATA(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_QCM_Collect_Inspection_Data", out_node);
	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

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
CUS_QCM_COLLECT_INSPECTION_DATA()
- Main sub function of "CUS_QCM_Collect_Inspection_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_COLLECT_INSPECTION_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPDAT_TAG CQCMISPDAT;
	struct CQCMISPLOS_TAG CQCMISPLOS;
	struct MWIPLOTSTSX_TAG MWIPLOTSTS;
	struct MINVDLVLOT_TAG MINVDLVLOT;

//	struct CWIPRCPDEF_TAG CWIPRCPDEF;
//	struct MWIPCOLDEF_TAG MWIPCOLDEF;
//	struct MEDCCOLVER_TAG MEDCCOLVER;
//	struct MEDCCOLCHR_TAG MEDCCOLCHR;
//	struct MEDCLOTDAT_TAG MEDCLOTDAT;
//	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MEDCCHRDEF_TAG MEDCCHRDEF;

	char s_sys_time[14];


	TRSNode *insp_in;
	TRSNode *cmn_out;

	//TRSNode *collect_in_node;
	TRSNode **data_list;
	TRSNode **loss_list;

	// For EDC
//	TRSNode *collect_lot_in;
//	TRSNode *char_list;
//	TRSNode  *unit_list;
//	TRSNode  *value_list;
//	TRSNode  *value_seq_list;
//	TRSNode *edc_out;
//	TRSNode **all_thick_list;
//	TRSNode **flatness_list;

	int i_loss_count;
	int i_data_count;

	int i_select_count;

	char c_lot_type;

//	int iCnt = 0;

//	char s_member_name[9];


	LOG_head("CUS_QCM_Collect_Inspection_Data");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "INV-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}


	/* Validation Check */
	if (CUS_QCM_Collect_Inspection_Data_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	// 일반 데이터 저장
	if (TRS.get_procstep(in_node) == '1')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		//공통 탭 정보, Loss정보등은 판정이후 상태에는 수정하지 않음
		if (CQCMISPSTS.INSP_STATUS != MP_CQMS_STATUS_COMPLETE && CQCMISPSTS.INSP_STATUS != MP_CQMS_STATUS_CANCEL)
		{
			//검사마스터 기본정보 저장( 판정코드, 재가공공정, 비고)
			if (COM_isnullspace(TRS.get_string(in_node, "RWK_OPER")) != MP_TRUE)
			{
				TRS.copy(CQCMISPSTS.RWK_FLOW, sizeof(CQCMISPSTS.RWK_FLOW), in_node, "RWK_FLOW");
				TRS.copy(CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER), in_node, "RWK_OPER");
			}
			else
			{
				memset(CQCMISPSTS.RWK_FLOW, ' ', sizeof(CQCMISPSTS.RWK_FLOW));
				memset(CQCMISPSTS.RWK_OPER, ' ', sizeof(CQCMISPSTS.RWK_OPER));
			}
			CQCMISPSTS.INSP_JUDGE_FLAG = TRS.get_char(in_node, "INSP_JUDGE_FLAG");


			TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
			CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VERSION");



			//생산Lot, Dlv Lot  구분
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			//TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
			memcpy(MWIPLOTSTS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				//생산 LOT
				c_lot_type = 'w';

				//현재 Lot의 공정과  검사공정(INSP_OPER)가 다를 경우 에러
				if (memcmp(MWIPLOTSTS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER)) != 0)
				{
					strcpy(s_msg_code, "QCM-0066");
					TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTS.OPER), MWIPLOTSTS.OPER);
					TRS.add_fieldmsg(out_node, "REQUESTED_INSP_OPER", MP_STR, sizeof(CQCMISPSTS.INSP_OPER), CQCMISPSTS.INSP_OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//HOLD인 경우 에러

			}
			else
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_init_minvdlvlot(&MINVDLVLOT);
					TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(MINVDLVLOT.DLV_LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
					//TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
					DBU_select_minvdlvlot(1, &MINVDLVLOT);
					if (DB_error_code == DB_SUCCESS)
					{
						//DLV LOT ID
						c_lot_type = 'i';
					}
					else if (DB_error_code == DB_NOT_FOUND)
					{
						//LOT 존재 X
						return MP_FALSE;
					}
					else
					{
						// DB 오류
						return MP_FALSE;
					}
				}
				else
				{
					//DB 오류
					return MP_FALSE;
				}
			}


			//Loss정보 삭제처리 
			DBU_init_cqcmisplos(&CQCMISPLOS);
			TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
			{
				DBU_delete_cqcmisplos(2, &CQCMISPLOS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}


			loss_list = TRS.get_list(in_node, "LOSS_LIST");
			i_loss_count = TRS.get_item_count(in_node, "LOSS_LIST");
			if (i_loss_count > 0)
			{
				for (int i = 0; i < i_loss_count; i++)
				{
					if (c_lot_type == 'w')
					{
						// QCM Loss 정보성 테이블 저장
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
						memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));         //검사 ID
						CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
						CQCMISPLOS.QTY_FLAG = '1';
						TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
						CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
						memcpy(CQCMISPLOS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPLOS.LOT_ID));
						CQCMISPLOS.HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;
						memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
						memcpy(CQCMISPLOS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
						CQCMISPLOS.MAT_VER = MWIPLOTSTS.MAT_VER;
						memcpy(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						CQCMISPLOS.FLOW_SEQ = MWIPLOTSTS.FLOW_SEQ_NUM;
						memcpy(CQCMISPLOS.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
						CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
						DBU_insert_cqcmisplos(&CQCMISPLOS);
					}
					else if (c_lot_type == 'i')
					{
						// QCM Loss 정보성 테이블 저장
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
						memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));         //검사 ID
						CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
						CQCMISPLOS.QTY_FLAG = '1';
						TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
						CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
						memcpy(CQCMISPLOS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPLOS.LOT_ID));
						CQCMISPLOS.HIST_SEQ = 1; // 자재는 의미X
						memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
						memcpy(CQCMISPLOS.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
						CQCMISPLOS.MAT_VER = MINVDLVLOT.MAT_VER;
						//(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						memset(CQCMISPLOS.FLOW, ' ', sizeof(CQCMISPLOS.FLOW));
						CQCMISPLOS.FLOW_SEQ = 0;
						memcpy(CQCMISPLOS.OPER, MINVDLVLOT.OPER, sizeof(MINVDLVLOT.OPER));
						memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
						CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
						DBU_insert_cqcmisplos(&CQCMISPLOS);
					}
				}
			}
		}


		TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");
		DBU_update_cqcmispsts(1, &CQCMISPSTS); // 판정, 비고 등 저장
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "QCM-0004");
			TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		/*
		//현재 검사요청ID 1개당, COL_SET_ID 1개를 이용하기 때문에,  중간에 품목에 대하여 COL_SET_ID가 바뀌거나,  버전이 증가하게되면 기존 과거 데이터를 삭제해준다.

		//저장시 들어오는 COL_SET_ID과 기존 저장된 COL_SET_ID가 다르면 기존데이터 삭제처리한다.
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
		if ((int)DBU_select_cqcmispdat_scalar(7, &CQCMISPDAT) > 0)
		{
		//기존 입력되어있는 이전버전의 데이터들은 삭제
		DBU_delete_cqcmispdat(4, &CQCMISPDAT);
		if (DB_error_code != DB_SUCCESS)
		{
		strcpy(s_msg_code, "QCM-0004");
		TRS.add_fieldmsg(out_node, "CQCMISPDAT DELETE", MP_NVST);
		TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
		TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
		}
		}


		//저장시 들어오는 COL_SET_ID 기준으로,  in_node의 COL_SET_VERSION 외에 다른 버전이 이미 존재하면 삭제처리한다.
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
		CQCMISPDAT.COL_SET_VER = TRS.get_int(in_node, "COL_SET_VERSION");
		if ((int)DBU_select_cqcmispdat_scalar(6, &CQCMISPDAT) > 0)
		{
		//기존 입력되어있는 이전버전의 데이터들은 삭제
		DBU_delete_cqcmispdat(3, &CQCMISPDAT);
		if (DB_error_code != DB_SUCCESS)
		{
		strcpy(s_msg_code, "QCM-0004");
		TRS.add_fieldmsg(out_node, "CQCMISPDAT DELETE", MP_NVST);
		TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
		TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
		TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
		}
		}

		*/

		//기존 입력된 데이터 전부 삭제 후 재 저장
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		if ((int)DBU_select_cqcmispdat_scalar(5, &CQCMISPDAT) > 0)
		{
			//기존 입력되어있는 이전버전의 데이터들은 삭제
			DBU_delete_cqcmispdat(2, &CQCMISPDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}




		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmispdat(&CQCMISPDAT);
			//공통
			TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
			CQCMISPDAT.COL_SET_VER = TRS.get_int(in_node, "COL_SET_VERSION");
			CQCMISPDAT.INSP_SEQ = TRS.get_int(in_node, "INSP_SEQ");

			//검사 Data List
			TRS.copy(CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID), data_list[i], "CHAR_ID");
			CQCMISPDAT.CHAR_SEQ = TRS.get_int(data_list[i], "CHAR_SEQ");
			CQCMISPDAT.UNIT_SEQ = TRS.get_int(data_list[i], "UNIT_SEQ");
			CQCMISPDAT.VALUE_SEQ = TRS.get_int(data_list[i], "VALUE_SEQ");

			if (COM_isnullspace(TRS.get_string(data_list[i], "UNIT_ID")) == MP_FALSE)
			{
				TRS.copy(CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID), data_list[i], "UNIT_ID");
			}
			else {
				DBC_init_medcchrdef(&MEDCCHRDEF);
				TRS.copy(MEDCCHRDEF.FACTORY, sizeof(MEDCCHRDEF.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MEDCCHRDEF.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID), data_list[i], "CHAR_ID");
				DBC_select_medcchrdef(1, &MEDCCHRDEF);

				if (DB_error_code != DB_SUCCESS)
				{
					//EDC-0005 : This character does not exist.
					strcpy(s_msg_code, "EDC-0005");
					TRS.add_fieldmsg(out_node, "MEDCCHRDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCHRDEF.FACTORY), MEDCCHRDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(MEDCCHRDEF.CHAR_ID), MEDCCHRDEF.CHAR_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				memcpy(CQCMISPDAT.UNIT_ID, MEDCCHRDEF.UNIT, sizeof(CQCMISPDAT.UNIT_ID));
			}


			CQCMISPDAT.VALUE_TYPE = TRS.get_char(data_list[i], "VALUE_TYPE");
			CQCMISPDAT.VALUE_COUNT = TRS.get_int(data_list[i], "VALUE_COUNT");
			TRS.copy(CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1), data_list[i], "VALUE_1");
			TRS.copy(CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2), data_list[i], "VALUE_2");
			TRS.copy(CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3), data_list[i], "VALUE_3");
			TRS.copy(CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4), data_list[i], "VALUE_4");
			TRS.copy(CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5), data_list[i], "VALUE_5");
			TRS.copy(CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6), data_list[i], "VALUE_6");
			TRS.copy(CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7), data_list[i], "VALUE_7");
			TRS.copy(CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8), data_list[i], "VALUE_8");
			TRS.copy(CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9), data_list[i], "VALUE_9");
			TRS.copy(CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10), data_list[i], "VALUE_10");
			TRS.copy(CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11), data_list[i], "VALUE_11");
			TRS.copy(CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12), data_list[i], "VALUE_12");
			TRS.copy(CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13), data_list[i], "VALUE_13");
			TRS.copy(CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14), data_list[i], "VALUE_14");
			TRS.copy(CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15), data_list[i], "VALUE_15");
			TRS.copy(CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16), data_list[i], "VALUE_16");
			TRS.copy(CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17), data_list[i], "VALUE_17");
			TRS.copy(CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18), data_list[i], "VALUE_18");
			TRS.copy(CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19), data_list[i], "VALUE_19");
			TRS.copy(CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20), data_list[i], "VALUE_20");
			TRS.copy(CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21), data_list[i], "VALUE_21");
			TRS.copy(CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22), data_list[i], "VALUE_22");
			TRS.copy(CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23), data_list[i], "VALUE_23");
			TRS.copy(CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24), data_list[i], "VALUE_24");
			TRS.copy(CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25), data_list[i], "VALUE_25");

			CQCMISPDAT.SAMPLE_COUNT = TRS.get_int(data_list[i], "SAMPLE_COUNT");
			TRS.copy(CQCMISPDAT.SPEC_OUT_MASK, sizeof(CQCMISPDAT.SPEC_OUT_MASK), data_list[i], "SPEC_OUT_MASK");


			i_select_count = (int)DBU_select_cqcmispdat_scalar(1, &CQCMISPDAT);

			if (i_select_count > 0)
			{
				//update
				memcpy(CQCMISPDAT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMISPDAT.UPDATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

				DBU_update_cqcmispdat(2, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMISPDAT.INSP_SEQ);
					TRS.add_fieldmsg(out_node, "CHAR_SEQ", MP_INT, CQCMISPDAT.CHAR_SEQ);
					TRS.add_fieldmsg(out_node, "UNIT_SEQ", MP_INT, CQCMISPDAT.UNIT_SEQ);
					TRS.add_fieldmsg(out_node, "VALUE_SEQ", MP_INT, CQCMISPDAT.VALUE_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				//insert
				memcpy(CQCMISPDAT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
				TRS.copy(CQCMISPDAT.CREATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

				DBU_insert_cqcmispdat(&CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
					TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
					TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMISPDAT.INSP_SEQ);
					TRS.add_fieldmsg(out_node, "CHAR_SEQ", MP_INT, CQCMISPDAT.CHAR_SEQ);
					TRS.add_fieldmsg(out_node, "UNIT_SEQ", MP_INT, CQCMISPDAT.UNIT_SEQ);
					TRS.add_fieldmsg(out_node, "VALUE_SEQ", MP_INT, CQCMISPDAT.VALUE_SEQ);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}


		// EDC 데이터 저장 ( SPC )
		insp_in = TRS.add_node(in_node, "insp_in");
		TRS.add_char(insp_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(insp_in, in_node);

		TRS.add_nstring(insp_in, "INSP_ID", TRS.get_string(in_node, "INSP_ID"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_COLLECT_SPC_DATA(s_msg_code, insp_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

	}
	// Main 화면 저장용
	else if (TRS.get_procstep(in_node) == '2')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (CQCMISPSTS.INSP_STATUS != MP_CQMS_STATUS_COMPLETE && CQCMISPSTS.INSP_STATUS != MP_CQMS_STATUS_CANCEL)
		{
			if (COM_isnullspace(TRS.get_string(in_node, "RWK_OPER")) != MP_TRUE)
			{
				TRS.copy(CQCMISPSTS.RWK_FLOW, sizeof(CQCMISPSTS.RWK_FLOW), in_node, "RWK_FLOW");
				TRS.copy(CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER), in_node, "RWK_OPER");
			}
			else
			{
				memset(CQCMISPSTS.RWK_FLOW, ' ', sizeof(CQCMISPSTS.RWK_FLOW));
				memset(CQCMISPSTS.RWK_OPER, ' ', sizeof(CQCMISPSTS.RWK_OPER));
			}

			CQCMISPSTS.INSP_JUDGE_FLAG = TRS.get_char(in_node, "INSP_JUDGE_FLAG");
			TRS.copy(CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT), in_node, "INSP_COMMENT");

			TRS.copy(CQCMISPSTS.COL_SET_ID, sizeof(CQCMISPSTS.COL_SET_ID), in_node, "COL_SET_ID");
			CQCMISPSTS.COL_SET_VERSION = TRS.get_int(in_node, "COL_SET_VERSION");

			DBU_update_cqcmispsts(1, &CQCMISPSTS); // 판정, 비고 등 저장
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			//생산Lot, Dlv Lot  구분
			DBU_init_mwiplotstsx(&MWIPLOTSTS);
			TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
			//TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
			memcpy(MWIPLOTSTS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				//생산 LOT
				c_lot_type = 'w';

				/*
				//현재 Lot의 공정과  검사공정(INSP_OPER)가 다를 경우 에러
				if (memcmp(MWIPLOTSTS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER)) != 0)
				{
				strcpy(s_msg_code, "QCM-0066");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTS.OPER), MWIPLOTSTS.OPER);
				TRS.add_fieldmsg(out_node, "REQUESTED_INSP_OPER", MP_STR, sizeof(CQCMISPSTS.INSP_OPER), CQCMISPSTS.INSP_OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
				}
				*/

				//HOLD인 경우 에러

			}
			else
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_init_minvdlvlot(&MINVDLVLOT);
					TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(MINVDLVLOT.DLV_LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
					//TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
					DBU_select_minvdlvlot(1, &MINVDLVLOT);
					if (DB_error_code == DB_SUCCESS)
					{
						//DLV LOT ID
						c_lot_type = 'i';
					}
					else if (DB_error_code == DB_NOT_FOUND)
					{
						//LOT 존재 X
						return MP_FALSE;
					}
					else
					{
						// DB 오류
						return MP_FALSE;
					}
				}
				else
				{
					//DB 오류
					return MP_FALSE;
				}
			}


			//Loss정보 삭제처리 
			DBU_init_cqcmisplos(&CQCMISPLOS);
			TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
			{
				DBU_delete_cqcmisplos(2, &CQCMISPLOS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

			loss_list = TRS.get_list(in_node, "LOSS_LIST");
			i_loss_count = TRS.get_item_count(in_node, "LOSS_LIST");
			if (i_loss_count > 0)
			{

				//Loss정보 삭제처리 
				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
				{
					DBU_delete_cqcmisplos(2, &CQCMISPLOS);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}

				for (int i = 0; i < i_loss_count; i++)
				{
					if (c_lot_type == 'w')
					{
						// QCM Loss 정보성 테이블 저장
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
						memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));         //검사 ID
						CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
						CQCMISPLOS.QTY_FLAG = '1';
						TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
						CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
						memcpy(CQCMISPLOS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPLOS.LOT_ID));
						CQCMISPLOS.HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ; // Main  Flag가 안넘어오는경우 확인필요
						memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
						memcpy(CQCMISPLOS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
						CQCMISPLOS.MAT_VER = MWIPLOTSTS.MAT_VER;
						memcpy(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						CQCMISPLOS.FLOW_SEQ = MWIPLOTSTS.FLOW_SEQ_NUM;
						memcpy(CQCMISPLOS.OPER, MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
						memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
						CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
						DBU_insert_cqcmisplos(&CQCMISPLOS);
					}
					else if (c_lot_type == 'i')
					{
						// QCM Loss 정보성 테이블 저장
						DBU_init_cqcmisplos(&CQCMISPLOS);
						TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);  //FACTORY
						memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));         //검사 ID
						CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);                         //SEQ
						CQCMISPLOS.QTY_FLAG = '1';
						TRS.copy(CQCMISPLOS.LOSS_CODE, sizeof(CQCMISPLOS.LOSS_CODE), loss_list[i], "LOSS_CODE");
						CQCMISPLOS.LOSS_QTY = TRS.get_double(loss_list[i], "LOSS_QTY");
						memcpy(CQCMISPLOS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPLOS.LOT_ID));
						CQCMISPLOS.HIST_SEQ = 1; // 자재는 의미X
						memcpy(CQCMISPLOS.TRAN_TIME, s_sys_time, sizeof(s_sys_time));
						memcpy(CQCMISPLOS.MAT_ID, MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
						CQCMISPLOS.MAT_VER = MINVDLVLOT.MAT_VER;
						//(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
						memset(CQCMISPLOS.FLOW, ' ', sizeof(CQCMISPLOS.FLOW));
						CQCMISPLOS.FLOW_SEQ = 0;
						memcpy(CQCMISPLOS.OPER, MINVDLVLOT.OPER, sizeof(MINVDLVLOT.OPER));
						memset(CQCMISPLOS.RES_ID, ' ', sizeof(CQCMISPLOS.RES_ID));
						CQCMISPLOS.MAIN_FLAG = TRS.get_char(loss_list[i], "MAIN_FLAG");
						DBU_insert_cqcmisplos(&CQCMISPLOS);
					}

				}
			}

		}

	}
	//PDC 전용 저장로직
	else if (TRS.get_procstep(in_node) == '3')
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID), in_node, "INSP_ID");
		DBU_select_cqcmispsts(1, &CQCMISPSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				strcpy(s_msg_code, "QCM-0050");
			}
			else
			{
				strcpy(s_msg_code, "WIP-0004");
			}
			TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//생산Lot, Dlv Lot  구분
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
		//TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
		memcpy(MWIPLOTSTS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
		if (DB_error_code == DB_SUCCESS)
		{
			//생산 LOT
			c_lot_type = 'w';

			//현재 Lot의 공정과  검사공정(INSP_OPER)가 다를 경우 에러
			if (memcmp(MWIPLOTSTS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER)) != 0)
			{
				strcpy(s_msg_code, "QCM-0066");
				TRS.add_fieldmsg(out_node, "LOT_OPER", MP_STR, sizeof(MWIPLOTSTS.OPER), MWIPLOTSTS.OPER);
				TRS.add_fieldmsg(out_node, "REQUESTED_INSP_OPER", MP_STR, sizeof(CQCMISPSTS.INSP_OPER), CQCMISPSTS.INSP_OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//HOLD인 경우 에러

		}
		else
		{
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_init_minvdlvlot(&MINVDLVLOT);
				TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVDLVLOT.DLV_LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				//TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
				DBU_select_minvdlvlot(1, &MINVDLVLOT);
				if (DB_error_code == DB_SUCCESS)
				{
					//DLV LOT ID
					c_lot_type = 'i';
				}
				else if (DB_error_code == DB_NOT_FOUND)
				{
					//LOT 존재 X
					return MP_FALSE;
				}
				else
				{
					// DB 오류
					return MP_FALSE;
				}
			}
			else
			{
				//DB 오류
				return MP_FALSE;
			}
		}



		//기존 입력된 데이터 전부 삭제 후 재 저장
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		if ((int)DBU_select_cqcmispdat_scalar(5, &CQCMISPDAT) > 0)
		{
			//기존 입력되어있는 이전버전의 데이터들은 삭제
			DBU_delete_cqcmispdat(2, &CQCMISPDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

	


		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cqcmispdat(&CQCMISPDAT);
			//공통
			TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
			TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
			CQCMISPDAT.COL_SET_VER = TRS.get_int(in_node, "COL_SET_VERSION");
			CQCMISPDAT.INSP_SEQ = TRS.get_int(in_node, "INSP_SEQ");

			//검사 Data List
			TRS.copy(CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID), data_list[i], "CHAR_ID");
			CQCMISPDAT.CHAR_SEQ = TRS.get_int(data_list[i], "CHAR_SEQ");
			CQCMISPDAT.UNIT_SEQ = TRS.get_int(data_list[i], "UNIT_SEQ");
			CQCMISPDAT.VALUE_SEQ = TRS.get_int(data_list[i], "VALUE_SEQ");

			if (COM_isnullspace(TRS.get_string(data_list[i], "UNIT_ID")) == MP_FALSE)
			{
				TRS.copy(CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID), data_list[i], "UNIT_ID");
			}
			else {
				DBC_init_medcchrdef(&MEDCCHRDEF);
				TRS.copy(MEDCCHRDEF.FACTORY, sizeof(MEDCCHRDEF.FACTORY), in_node, IN_FACTORY);
				TRS.copy(MEDCCHRDEF.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID), data_list[i], "CHAR_ID");
				DBC_select_medcchrdef(1, &MEDCCHRDEF);

				if (DB_error_code != DB_SUCCESS)
				{
					//EDC-0005 : This character does not exist.
					strcpy(s_msg_code, "EDC-0005");
					TRS.add_fieldmsg(out_node, "MEDCCHRDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCHRDEF.FACTORY), MEDCCHRDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "CHAR_ID", MP_STR, sizeof(MEDCCHRDEF.CHAR_ID), MEDCCHRDEF.CHAR_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				memcpy(CQCMISPDAT.UNIT_ID, MEDCCHRDEF.UNIT, sizeof(CQCMISPDAT.UNIT_ID));
			}

			CQCMISPDAT.VALUE_TYPE = TRS.get_char(data_list[i], "VALUE_TYPE");
			CQCMISPDAT.VALUE_COUNT = TRS.get_int(data_list[i], "VALUE_COUNT");
			TRS.copy(CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1), data_list[i], "VALUE_1");
			TRS.copy(CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2), data_list[i], "VALUE_2");
			TRS.copy(CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3), data_list[i], "VALUE_3");
			TRS.copy(CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4), data_list[i], "VALUE_4");
			TRS.copy(CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5), data_list[i], "VALUE_5");
			TRS.copy(CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6), data_list[i], "VALUE_6");
			TRS.copy(CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7), data_list[i], "VALUE_7");
			TRS.copy(CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8), data_list[i], "VALUE_8");
			TRS.copy(CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9), data_list[i], "VALUE_9");
			TRS.copy(CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10), data_list[i], "VALUE_10");
			TRS.copy(CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11), data_list[i], "VALUE_11");
			TRS.copy(CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12), data_list[i], "VALUE_12");
			TRS.copy(CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13), data_list[i], "VALUE_13");
			TRS.copy(CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14), data_list[i], "VALUE_14");
			TRS.copy(CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15), data_list[i], "VALUE_15");
			TRS.copy(CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16), data_list[i], "VALUE_16");
			TRS.copy(CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17), data_list[i], "VALUE_17");
			TRS.copy(CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18), data_list[i], "VALUE_18");
			TRS.copy(CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19), data_list[i], "VALUE_19");
			TRS.copy(CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20), data_list[i], "VALUE_20");
			TRS.copy(CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21), data_list[i], "VALUE_21");
			TRS.copy(CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22), data_list[i], "VALUE_22");
			TRS.copy(CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23), data_list[i], "VALUE_23");
			TRS.copy(CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24), data_list[i], "VALUE_24");
			TRS.copy(CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25), data_list[i], "VALUE_25");

			CQCMISPDAT.SAMPLE_COUNT = TRS.get_int(data_list[i], "SAMPLE_COUNT");
			TRS.copy(CQCMISPDAT.SPEC_OUT_MASK, sizeof(CQCMISPDAT.SPEC_OUT_MASK), data_list[i], "SPEC_OUT_MASK");


			//insert
			memcpy(CQCMISPDAT.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMISPDAT.CREATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);
			//update
			memcpy(CQCMISPDAT.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
			TRS.copy(CQCMISPDAT.UPDATE_USER_ID, sizeof(CQCMISPDAT.CREATE_USER_ID), in_node, IN_USERID);

			DBU_insert_cqcmispdat(&CQCMISPDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(CQCMISPDAT.COL_SET_ID), CQCMISPDAT.COL_SET_ID);
				TRS.add_fieldmsg(out_node, "COL_SET_VER", MP_INT, CQCMISPDAT.COL_SET_VER);
				TRS.add_fieldmsg(out_node, "INSP_SEQ", MP_INT, CQCMISPDAT.INSP_SEQ);
				TRS.add_fieldmsg(out_node, "CHAR_SEQ", MP_INT, CQCMISPDAT.CHAR_SEQ);
				TRS.add_fieldmsg(out_node, "UNIT_SEQ", MP_INT, CQCMISPDAT.UNIT_SEQ);
				TRS.add_fieldmsg(out_node, "VALUE_SEQ", MP_INT, CQCMISPDAT.VALUE_SEQ);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		//Loss정보 삭제처리 
		DBU_init_cqcmisplos(&CQCMISPLOS);
		TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
		memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
		if ((int)DBU_select_cqcmisplos_scalar(5, &CQCMISPLOS) > 0)
		{
			DBU_delete_cqcmisplos(2, &CQCMISPLOS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPLOS DELETE(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPLOS.FACTORY), CQCMISPLOS.FACTORY);
				TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPLOS.INSP_ID), CQCMISPLOS.INSP_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}


		//Loss 정보 저장
		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
		TRS.copy(CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID), in_node, "COL_SET_ID");
		CQCMISPDAT.INSP_SEQ = 1;
		memcpy(CQCMISPDAT.CHAR_ID, "JUDGE_LOSS", strlen("JUDGE_LOSS"));
		DBU_open_cqcmispdat(3, &CQCMISPDAT);

		while (1)
		{
			DBU_fetch_cqcmispdat(3, &CQCMISPDAT);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cqcmispdat(3);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CQCMISPDAT FETCH", DT_NOVALUESTRING);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cqcmispdat(3);

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//c_lot_type
			if (c_lot_type == 'w')
			{
				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);
				CQCMISPLOS.QTY_FLAG = '1';
				memcpy(CQCMISPLOS.LOSS_CODE, CQCMISPDAT.VALUE_1, sizeof(CQCMISPLOS.LOSS_CODE));
				CQCMISPLOS.LOSS_QTY = CQCMISPDAT.SAMPLE_COUNT;
				memcpy(CQCMISPLOS.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPLOS.LOT_ID));
				CQCMISPLOS.HIST_SEQ = MWIPLOTSTS.LAST_HIST_SEQ;
				memcpy(CQCMISPLOS.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
				memcpy(CQCMISPLOS.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
				CQCMISPLOS.MAT_VER = CQCMISPSTS.MAT_VER;
				memcpy(CQCMISPLOS.FLOW, MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
				CQCMISPLOS.FLOW_SEQ = MWIPLOTSTS.FLOW_SEQ_NUM;
				memcpy(CQCMISPLOS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
				CQCMISPLOS.MAIN_FLAG = 'N';
				DBU_insert_cqcmisplos(&CQCMISPLOS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPLOS INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else if (c_lot_type == 'i')
			{
				DBU_init_cqcmisplos(&CQCMISPLOS);
				TRS.copy(CQCMISPLOS.FACTORY, sizeof(CQCMISPLOS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPLOS.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				CQCMISPLOS.SEQ = (int)DBU_select_cqcmisplos_scalar(2, &CQCMISPLOS);
				CQCMISPLOS.QTY_FLAG = '1';
				memcpy(CQCMISPLOS.LOSS_CODE, CQCMISPDAT.VALUE_1, sizeof(CQCMISPLOS.LOSS_CODE));
				CQCMISPLOS.LOSS_QTY = CQCMISPDAT.SAMPLE_COUNT;
				memcpy(CQCMISPLOS.LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				CQCMISPLOS.HIST_SEQ = 1;
				memcpy(CQCMISPLOS.TRAN_TIME, gs_sys_time, sizeof(gs_sys_time));
				memcpy(CQCMISPLOS.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
				CQCMISPLOS.MAT_VER = CQCMISPSTS.MAT_VER;
				memset(CQCMISPLOS.FLOW, ' ', sizeof(CQCMISPLOS.FLOW));
				CQCMISPLOS.FLOW_SEQ = 0;
				memcpy(CQCMISPLOS.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
				CQCMISPLOS.MAIN_FLAG = 'N';
				DBU_insert_cqcmisplos(&CQCMISPLOS);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPLOS INSERT", MP_NVST);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

		}

		// EDC 데이터 저장 ( SPC )
		insp_in = TRS.add_node(in_node, "insp_in");
		TRS.add_char(insp_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(insp_in, in_node);

		TRS.add_nstring(insp_in, "INSP_ID", TRS.get_string(in_node, "INSP_ID"));

		cmn_out = TRS.create_node("Cmn_Out");
		if (CUS_QCM_COLLECT_SPC_DATA(s_msg_code, insp_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}

	}







	return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Collect_Inspection_Data_Validation()
- Validation Check sub function of "CUS_QCM_COLLECT_INSPECTION_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Inspection_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

	/* ProcStep Validation */
	// 1 - 
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"12345678") == MP_FALSE)
	{
		return MP_FALSE;
	}

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
