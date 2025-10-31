/******************************************************************************'

System      : MESplus
Module      : CUS_WIP
File Name   : COMCus_update_caption.c
Description : Caption Setup function module

MES Version : 5.3.4

Function List
- CUS_WIP_non_operation()
+ Create/Update/Delete Caption definition
- CUS_WIP_NON_OPERATION()
+ Main sub function of CUS_WIP_non_operation function
+ Create/Update/Delete Caption definition
- CUS_WIP_non_operation_Validation()
+ Main sub function of CUS_WIP_NON_OPERATION function
+ Check the condition for create/update/delete Caption
Detail Description
- CUS_WIP_NON_OPERATION()
+ h_proc_step
+ MP_STEP_CREATE : Create Caption definition
+ MP_STEP_UPDATE : Update Caption definition
+ MP_STEP_DELETE : Delete Caption definition

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2016/01/01                 Create by Generator

Copyright(C) 1998-2016 Miracom,Inc.
All rights reserved.

******************************************************************************/

#if defined(_HPUX_SOURCE)

#include <dirent.h>

#elif defined(__digital__) || defined(_AIX)

#include <dirent.h>

#elif defined(WIN32) || defined(WIN64)

#include <direct.h>

#endif

#include "CUS_common.h"
#include "CUS_defines.h"
#include "CUS_WIP_common.h"

int CUS_WIP_NON_OPERATION(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

int CUS_WIP_non_operation_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node);

int Update_NonResource_Status(char *s_msg_code, char *s_factory, char *s_res_id, char c_res_sts, TRSNode *out_node);

/*******************************************************************************
COMCus_Update_Caption()
- Create/Update/Delete Caption definition
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_non_operation(TRSNode *in_node,
	TRSNode *out_node)
{
	char s_msg_code[MP_SIZE_MSG];
	int i_ret;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = CUS_WIP_NON_OPERATION(s_msg_code, in_node, out_node);

	COM_out_msg_log_write(s_msg_code, "CUS_WIP_NON_OPERATION", out_node);

	if (i_ret == MP_TRUE)
	{
		DB_commit();
	}
	else
	{
		DB_rollback();
	}

	return MP_TRUE;
}
/*******************************************************************************
CUS_WIP_NON_OPERATION()
- Main sub function of "CUS_WIP_non_operation" function
- Create/Update/Delete Caption definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_NON_OPERATION(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{

	struct CWIPDWNSTS_TAG CWIPDWNSTS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	struct MRASRESDEF_TAG MRASRESDEF;

    struct work_date_tag work_date;


	LOG_head("CUS_WIP_non_operation");
	TRS.log_add_all_members(in_node);
	COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

	TRSNode **ras_list;
	int i = 0;
	int i_hist_seq = 0;
	int i_seq = 0;
	
	if (CUS_WIP_non_operation_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
	{
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}
	
	if (TRS.get_procstep(in_node) == MP_STEP_CREATE)
	{
		ras_list = TRS.get_list(in_node, "RES_TBL");

		for (i = 0; i < TRS.get_item_count(in_node, "RES_TBL"); i++) 
		{
			DBU_init_cwipdwnsts(&CWIPDWNSTS);
			TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
			TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), ras_list[i], "RES_ID");
			TRS.copy(CWIPDWNSTS.OPER, sizeof(CWIPDWNSTS.OPER), in_node, "OPER");
			CWIPDWNSTS.DOWN_STATUS = 'S'; //START상태

			//SEQ 넘버 가져오기
			i_hist_seq = (int)DBU_select_cwipdwnsts_scalar(2, &CWIPDWNSTS);
			CWIPDWNSTS.HIST_SEQ = i_hist_seq;
			i_seq = (int)DBU_select_cwipdwnsts_scalar(3, &CWIPDWNSTS);
			CWIPDWNSTS.SEQ = i_seq;
			
			//1. 해당 설비-공정에 해당하는 데이터 중 비가동 시작 데이터 존재할 경우
			if ((int)DBU_select_cwipdwnsts_scalar(5, &CWIPDWNSTS) > 0)
			{
				//WIP-0608 : 비가동이 시작된 이력이 있습니다.
				strcpy(s_msg_code, "WIP-0608");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.copy(CWIPDWNSTS.DOWN_START_TIME, sizeof(CWIPDWNSTS.DOWN_START_TIME), in_node, "DOWN_START_TIME");

            memset(&work_date, ' ', sizeof(work_date));
            work_date.c_kind = 'L';
            memcpy(work_date.s_sys_time, CWIPDWNSTS.DOWN_START_TIME, sizeof(work_date.s_sys_time));
            Get_shift(CWIPDWNSTS.FACTORY, &work_date);
            memcpy(CWIPDWNSTS.DOWN_START_DATE, work_date.s_work_date, sizeof(CWIPDWNSTS.DOWN_START_DATE));
            memcpy(CWIPDWNSTS.DOWN_START_DAY_NIGHT, work_date.s_day_night, sizeof(CWIPDWNSTS.DOWN_START_DAY_NIGHT));

			//2. 이전 종료시간이 시작시간보다 늦는경우 에러
			if (DBU_select_cwipdwnsts_scalar(6, &CWIPDWNSTS) > 0)
			{
				//WIP-0610 : 이전 비가동 이력의 종료시간보다 시작시간이 앞섭니다.
				strcpy(s_msg_code, "WIP-0610");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);
				TRS.add_fieldmsg(out_node, "PREV_END_TIME", MP_DBL, DBU_select_cwipdwnsts_scalar(6, &CWIPDWNSTS));

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.copy(CWIPDWNSTS.AREA_ID, sizeof(CWIPDWNSTS.AREA_ID), in_node, "AREA_ID");
			TRS.copy(CWIPDWNSTS.SUB_AREA_ID, sizeof(CWIPDWNSTS.SUB_AREA_ID), in_node, "SUB_AREA_ID");
			TRS.copy(CWIPDWNSTS.ORDER_ID, sizeof(CWIPDWNSTS.ORDER_ID), in_node, "ORDER_ID");
			TRS.copy(CWIPDWNSTS.DOWN_CODE, sizeof(CWIPDWNSTS.DOWN_CODE), in_node, "DOWN_CODE");
			TRS.copy(CWIPDWNSTS.DOWN_TYPE_1, sizeof(CWIPDWNSTS.DOWN_TYPE_1), in_node, "DOWN_TYPE_1");
			TRS.copy(CWIPDWNSTS.DOWN_TYPE_2, sizeof(CWIPDWNSTS.DOWN_TYPE_2), in_node, "DOWN_TYPE_2");
			TRS.copy(CWIPDWNSTS.DOWN_TYPE_3, sizeof(CWIPDWNSTS.DOWN_TYPE_3), in_node, "DOWN_TYPE_3");
			TRS.copy(CWIPDWNSTS.CREATE_USER_ID, sizeof(CWIPDWNSTS.CREATE_USER_ID), in_node, IN_USERID);
			DB_get_systime(CWIPDWNSTS.CREATE_TIME);
			DBU_insert_cwipdwnsts(&CWIPDWNSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPDWNSTS INSERT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			// 설비 기준정보 변경
			// 비가동코드의 상태코드를 조회해서 입력해준다.
			// D : 정지, I : 대기

			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_NOP_GRP_3, strlen(MP_GCM_NOP_GRP_3));
			TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), in_node, "DOWN_TYPE_1");
			TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), in_node, "DOWN_TYPE_2");
			TRS.copy(MGCMTBLDAT.KEY_3, sizeof(MGCMTBLDAT.KEY_3), in_node, "DOWN_TYPE_3");
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//GCM-0008 : TABLE에 존재하지 않는 항목입니다.
					strcpy(s_msg_code, "GCM-0008");
					gs_log_type.e_type = MP_LOG_E_EXISTENCE;
				}
				else
				{
					strcpy(s_msg_code, "INV-0004");
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "NOP_GRP_1", MP_STR, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);
				TRS.add_fieldmsg(out_node, "NOP_GRP_2", MP_STR, sizeof(MGCMTBLDAT.KEY_2), MGCMTBLDAT.KEY_2);
				TRS.add_fieldmsg(out_node, "NOP_GRP_3", MP_STR, sizeof(MGCMTBLDAT.KEY_3), MGCMTBLDAT.KEY_3);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (Update_NonResource_Status(s_msg_code, CWIPDWNSTS.FACTORY, CWIPDWNSTS.RES_ID, MGCMTBLDAT.DATA_3[0], out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}
		}
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_UPDATE)
	{
		ras_list = TRS.get_list(in_node, "RES_TBL");

		for (i = 0; i < TRS.get_item_count(in_node, "RES_TBL"); i++)
		{
			DBU_init_cwipdwnsts(&CWIPDWNSTS);
			TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
			TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), ras_list[i], "RES_ID");
			TRS.copy(CWIPDWNSTS.OPER, sizeof(CWIPDWNSTS.OPER), in_node, "OPER");

			i_hist_seq = (int)DBU_select_cwipdwnsts_scalar(2, &CWIPDWNSTS);
			CWIPDWNSTS.HIST_SEQ = i_hist_seq;
			i_seq = (int)DBU_select_cwipdwnsts_scalar(4, &CWIPDWNSTS);
			CWIPDWNSTS.SEQ = i_seq;

			//1. Client와 Server의 비가동 시퀀스 비교
			if (i_seq != TRS.get_int(ras_list[i], "SEQ"))
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_select_cwipdwnsts(1, &CWIPDWNSTS);

			//2. 비가동 시작이 아닌경우 에러
			if (CWIPDWNSTS.DOWN_STATUS != 'S')
			{
				//WIP-0611 : 현재 비가동 시작 샹태가 아닙니다.
				strcpy(s_msg_code, "WIP-0611");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//3. 현재 시작된 비가동의 시작시간이 종료시간보다 늦는 경우 에러
			if (COM_atof(CWIPDWNSTS.DOWN_START_TIME, sizeof(CWIPDWNSTS.DOWN_START_TIME)) > COM_atof(TRS.get_string(in_node, "DOWN_END_TIME"), sizeof(CWIPDWNSTS.DOWN_START_TIME)))
			{
				//WIP-0612 : 이전 비가동 이력의 시작시간보다 종료시간이 앞섭니다.
				strcpy(s_msg_code, "WIP-0612");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			TRS.copy(CWIPDWNSTS.DOWN_END_TIME, sizeof(CWIPDWNSTS.DOWN_END_TIME), in_node, "DOWN_END_TIME");
            memset(&work_date, ' ', sizeof(work_date));
            work_date.c_kind = 'L';
            memcpy(work_date.s_sys_time, CWIPDWNSTS.DOWN_END_TIME, sizeof(work_date.s_sys_time));
            Get_shift(CWIPDWNSTS.FACTORY, &work_date);
            memcpy(CWIPDWNSTS.DOWN_END_DATE, work_date.s_work_date, sizeof(CWIPDWNSTS.DOWN_END_DATE));
            memcpy(CWIPDWNSTS.DOWN_END_DAY_NIGHT, work_date.s_day_night, sizeof(CWIPDWNSTS.DOWN_END_DAY_NIGHT));

			CWIPDWNSTS.DOWN_STATUS = 'E'; //END상태
			TRS.copy(CWIPDWNSTS.UPDATE_USER_ID, sizeof(CWIPDWNSTS.UPDATE_USER_ID), in_node, IN_USERID);
			DB_get_systime(CWIPDWNSTS.UPDATE_TIME);
			DBU_update_cwipdwnsts(1, &CWIPDWNSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPDWNSTS UPDATE(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mrasresdef(&MRASRESDEF);
			TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASRESDEF.RES_ID, CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID));
			DBU_select_mrasresdef(1, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					// RAS-0003 : 존재하지 않는 장비입니다.
					strcpy(s_msg_code, "RAS-0003");
				}
				else
				{
					strcpy(s_msg_code, "RAS-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MRASRESDEF Select 1", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
				return MP_FALSE;
			}



			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTSX.START_RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
			
			//시작설비로 맵핑된 LOT 존재시, 혹은  항시 가동설비시
			if (DBU_select_mwiplotstsx_scalar(3, &MWIPLOTSTSX) > 0 || MRASRESDEF.RES_CMF_9[0] == 'Y')
			{
				// 가동으로  변경
				if (Update_NonResource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'R', out_node) == MP_FALSE)
				{
					return MP_FALSE;
				}
			}
			else
			{
				// IDLE 으로  변경
				if (Update_NonResource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'I', out_node) == MP_FALSE)
				{
					return MP_FALSE;
				}
			}


		}
	}
	else if (TRS.get_procstep(in_node) == MP_STEP_DELETE)
	{
		ras_list = TRS.get_list(in_node, "RES_TBL");

		for (i = 0; i < TRS.get_item_count(in_node, "RES_TBL"); i++)
		{
			DBU_init_cwipdwnsts(&CWIPDWNSTS);
			TRS.copy(CWIPDWNSTS.FACTORY, sizeof(CWIPDWNSTS.FACTORY), in_node, "FACTORY");
			TRS.copy(CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID), ras_list[i], "RES_ID");

			i_hist_seq = (int)DBU_select_cwipdwnsts_scalar(2, &CWIPDWNSTS);
			CWIPDWNSTS.HIST_SEQ = i_hist_seq;
			i_seq = (int)DBU_select_cwipdwnsts_scalar(4, &CWIPDWNSTS);
			CWIPDWNSTS.SEQ = i_seq;

			//1. Client와 Server의 비가동 시퀀스 비교
			if (i_seq != TRS.get_int(ras_list[i], "SEQ"))
			{
				//WIP-0609 : 데이터가 변경되었습니다. 화면을 재조회해주세요.
				strcpy(s_msg_code, "WIP-0609");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_select_cwipdwnsts(1, &CWIPDWNSTS);

			//시작이 아닐경우 에러
			//현재는 각각의 SEQ는 지울수 없다.
			if (CWIPDWNSTS.DOWN_STATUS != 'S')
			{
				//WIP-0611 : 현재 비가동 시작 샹태가 아닙니다.
				strcpy(s_msg_code, "WIP-0611");
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPDWNSTS.OPER), CWIPDWNSTS.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_delete_cwipdwnsts(1, &CWIPDWNSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPDWNSTS DELETE(1)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPDWNSTS.FACTORY), CWIPDWNSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPDWNSTS.RES_ID), CWIPDWNSTS.RES_ID);
				TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPDWNSTS.HIST_SEQ);
				TRS.add_fieldmsg(out_node, "SEQ", MP_INT, CWIPDWNSTS.SEQ);

				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_TRANS;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_mrasresdef(&MRASRESDEF);
			TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASRESDEF.RES_ID, CWIPDWNSTS.RES_ID, sizeof(CWIPDWNSTS.RES_ID));
			DBU_select_mrasresdef(1, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					// RAS-0003 : 존재하지 않는 장비입니다.
					strcpy(s_msg_code, "RAS-0003");
				}
				else
				{
					strcpy(s_msg_code, "RAS-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MRASRESDEF Select 1", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
				return MP_FALSE;
			}



			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPLOTSTSX.START_RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));

			//시작설비로 맵핑된 LOT 존재시, 혹은  항시 가동설비시
			if (DBU_select_mwiplotstsx_scalar(3, &MWIPLOTSTSX) > 0 || MRASRESDEF.RES_CMF_9[0] == 'Y')
			{
				// 가동으로  변경
				if (Update_NonResource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'R', out_node) == MP_FALSE)
				{
					return MP_FALSE;
				}
			}
			else
			{
				// IDLE 으로  변경
				if (Update_NonResource_Status(s_msg_code, MRASRESDEF.FACTORY, MRASRESDEF.RES_ID, 'I', out_node) == MP_FALSE)
				{
					return MP_FALSE;
				}
			}


			// 가동으로 우선 변경
			/*
			if (Update_NonResource_Status(s_msg_code, CWIPDWNSTS.FACTORY, CWIPDWNSTS.RES_ID, 'R', out_node) == MP_FALSE)
			{
				return MP_FALSE;
			}*/
		}
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_non_operation_Validation()
- Main sub function of "CUS_WIP_NON_OPERATION" function
- Check the condition for create/update/delete Caption & vbCrLf    Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_non_operation_Validation(char *s_msg_code,
	TRSNode *in_node,
	TRSNode *out_node)
{
	/* ProcStep Validation */
	if (COM_service_validation(s_msg_code,
		in_node,
		out_node,
		TRS.get_procstep(in_node),
		"IUD") == MP_FALSE)
	{
		return MP_FALSE;
	}

	return MP_TRUE;
}

/*******************************************************************************
Update_Resource_Status()
- 비가동 설비 상태를 변경한다.
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- string sLot
- TRSNode *in_node : In Node from each transaction function
- TRSNode *out_node : Common out node for result message
*******************************************************************************/
int Update_NonResource_Status(char *s_msg_code, char *s_factory, char *s_res_id, char c_res_sts, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;

    DBU_init_mrasresdef(&MRASRESDEF);

    memcpy(MRASRESDEF.FACTORY, s_factory, sizeof(MRASRESDEF.FACTORY));
    memcpy(MRASRESDEF.RES_ID, s_res_id, sizeof(MRASRESDEF.RES_ID));
    DBU_select_mrasresdef(1, &MRASRESDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // RAS-0003 : 존재하지 않는 장비입니다.
            strcpy(s_msg_code, "RAS-0003");
        }
        else
        {
            strcpy(s_msg_code, "RAS-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MRASRESDEF Select 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        return MP_FALSE;
    }

    // 설비 상태 변경 여부 확인
    //   - 현재는 래핑기를 제외하고 설비 상태 변경
    //   - 래핑기는 EIS(Equipment Interface Server)를 통해서 설비 상태를 변경하고 있음
    if (MRASRESDEF.RES_CMF_2[0] == 'Y')
        return MP_TRUE;

    if (MRASRESDEF.DELETE_FLAG == 'Y')
    {
        //RAS-0119 : 이 장비는 삭제되었습니다.
        strcpy(s_msg_code, "RAS-0119");

        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        TRS.add_fieldmsg(out_node, "DELETE_FLAG", DT_CHAR, MRASRESDEF.DELETE_FLAG);
        TRS.add_fieldmsg(out_node, "DELETE_USER_ID", DT_STRING, sizeof(MRASRESDEF.DELETE_USER_ID), MRASRESDEF.DELETE_USER_ID);
        TRS.add_fieldmsg(out_node, "DELETE_TIME", DT_STRING, sizeof(MRASRESDEF.DELETE_TIME), MRASRESDEF.DELETE_TIME);

        return MP_FALSE;
    }
       
  
    if (c_res_sts == 'R')
    {
        MRASRESDEF.RES_UP_DOWN_FLAG = 'U';
    }
    else
    {
        MRASRESDEF.RES_UP_DOWN_FLAG = 'D';
    }        

    memset(MRASRESDEF.RES_STS_1,' ', sizeof(MRASRESDEF.RES_STS_1));
    MRASRESDEF.RES_PRI_STS[0] = c_res_sts;  // 설비 상태
    memcpy(MRASRESDEF.RES_STS_1, gs_sys_time, sizeof(gs_sys_time)); // 설비 상태 변경 일시

    DBU_update_mrasresdef(2, &MRASRESDEF);
    if (DB_error_code != DB_SUCCESS)
    {
        TRS.add_fieldmsg(out_node, "MRASRESDEF Update 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
        TRS.add_fieldmsg(out_node, "RES_STS_3", DT_STRING, sizeof(MRASRESDEF.RES_STS_3), MRASRESDEF.RES_STS_3);

        return MP_FALSE;
    }   

    return MP_TRUE;
}


