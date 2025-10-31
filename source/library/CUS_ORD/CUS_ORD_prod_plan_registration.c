/*******************************************************************************

System      : MESplus
Module      : CUS_ORD
File Name   : CUS_ORD_prod_plan_registration.c
Description : Prod Plan Registartion

MES Version : 5.0

Function List


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/08  JS.SOO        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_ORD_common.h"

int CUS_ORD_Prod_Plan_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_ORD_Prod_Plan_Registration_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_ORD_Prod_Plan_Registration_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_ORD_Prod_Plan_Registration()
- tran prod plan
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Prod_Plan_Registration(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_ORD_PROD_PLAN_REGISTRATION(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_ORD_Prod_Plan_Registration", out_node);

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
CUS_ORD_PROD_PLAN_REGISTRATION()
- Main sub function of "CUS_ORD_Prod_Plan_Registration" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_PROD_PLAN_REGISTRATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CORDPRDPLN_TAG CORDPRDPLN;
	
	TRSNode **prod_plan_list;

	char s_sys_time[14];

	int i = 0;

    LOG_head("CUS_ORD_Prod_Plan_Registration");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_ORD_Prod_Plan_Registration_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.set_fieldmsg(out_node, "DB_get_systime", MP_NVST);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_TRANS;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	prod_plan_list = TRS.get_list(in_node, "DATA_LIST");

	// STEP 1 : 생산계획정보 등록/수정
	// STEP 2 : 생산게획정보 삭제

	if (TRS.get_procstep(in_node) == '1')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "DATA_LIST"); i++)
		{
			DBU_init_cordprdpln(&CORDPRDPLN);
			TRS.copy(CORDPRDPLN.FACTORY, sizeof(CORDPRDPLN.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CORDPRDPLN.AREA_ID, sizeof(CORDPRDPLN.AREA_ID), prod_plan_list[i], "AREA_ID");
			TRS.copy(CORDPRDPLN.OPER, sizeof(CORDPRDPLN.OPER), prod_plan_list[i], "OPER");
			TRS.copy(CORDPRDPLN.PLAN_DATE, sizeof(CORDPRDPLN.PLAN_DATE), prod_plan_list[i], "PLAN_DATE");
			TRS.copy(CORDPRDPLN.MAT_ID, sizeof(CORDPRDPLN.MAT_ID), prod_plan_list[i], "MAT_ID");
			CORDPRDPLN.MAT_VER = 1;
			DBU_select_cordprdpln(1, &CORDPRDPLN);
			if (DB_error_code != DB_SUCCESS)
			{
				//조회되지 않으면 INSERT
				if (DB_error_code == DB_NOT_FOUND)
				{
					CORDPRDPLN.QTY = TRS.get_double(prod_plan_list[i], "QTY");
					TRS.copy(CORDPRDPLN.CREATE_USER_ID, sizeof(CORDPRDPLN.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CORDPRDPLN.CREATE_TIME, s_sys_time, sizeof(s_sys_time));
					DBU_insert_cordprdpln(&CORDPRDPLN);
					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "ORD-0004");
						TRS.add_fieldmsg(out_node, "CORDPRDPLN INSERT ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CORDPRDPLN.AREA_ID), CORDPRDPLN.AREA_ID);
						TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CORDPRDPLN.OPER), CORDPRDPLN.OPER);
						TRS.add_fieldmsg(out_node, "PLAN_DATE", DT_STRING, sizeof(CORDPRDPLN.PLAN_DATE), CORDPRDPLN.PLAN_DATE);
						TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CORDPRDPLN.MAT_ID), CORDPRDPLN.MAT_ID);

						TRS.add_dberrmsg(out_node, DB_error_msg);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
				else
				{
					strcpy(s_msg_code, "ORD-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "CORDPRDPLN SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CORDPRDPLN.AREA_ID), CORDPRDPLN.AREA_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CORDPRDPLN.OPER), CORDPRDPLN.OPER);
					TRS.add_fieldmsg(out_node, "PLAN_DATE", DT_STRING, sizeof(CORDPRDPLN.PLAN_DATE), CORDPRDPLN.PLAN_DATE);
					TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CORDPRDPLN.MAT_ID), CORDPRDPLN.MAT_ID);


					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			//조회되면 UPDATE
			else if (DB_error_code == DB_SUCCESS)
			{
				CORDPRDPLN.QTY = TRS.get_double(prod_plan_list[i], "QTY");
				TRS.copy(CORDPRDPLN.UPDATE_USER_ID, sizeof(CORDPRDPLN.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CORDPRDPLN.UPDATE_TIME, s_sys_time, sizeof(s_sys_time));
				DBU_update_cordprdpln(1, &CORDPRDPLN);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "ORD-0004");
					TRS.add_fieldmsg(out_node, "CORDPRDPLN UPDATE(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CORDPRDPLN.AREA_ID), CORDPRDPLN.AREA_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CORDPRDPLN.OPER), CORDPRDPLN.OPER);
					TRS.add_fieldmsg(out_node, "PLAN_DATE", DT_STRING, sizeof(CORDPRDPLN.PLAN_DATE), CORDPRDPLN.PLAN_DATE);
					TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CORDPRDPLN.MAT_ID), CORDPRDPLN.MAT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		for (i = 0; i < TRS.get_item_count(in_node, "DATA_LIST"); i++)
		{
			DBU_init_cordprdpln(&CORDPRDPLN);
			TRS.copy(CORDPRDPLN.FACTORY, sizeof(CORDPRDPLN.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CORDPRDPLN.AREA_ID, sizeof(CORDPRDPLN.AREA_ID), prod_plan_list[i], "AREA_ID");
			TRS.copy(CORDPRDPLN.OPER, sizeof(CORDPRDPLN.OPER), prod_plan_list[i], "OPER");
			TRS.copy(CORDPRDPLN.PLAN_DATE, sizeof(CORDPRDPLN.PLAN_DATE), prod_plan_list[i], "PLAN_DATE");
			TRS.copy(CORDPRDPLN.MAT_ID, sizeof(CORDPRDPLN.MAT_ID), prod_plan_list[i], "MAT_ID");
			DBU_select_cordprdpln(1, &CORDPRDPLN);
			if (DB_error_code != DB_SUCCESS)
			{
				//조회되지 않으면 INSERT
				if (DB_error_code == DB_NOT_FOUND)
				{
					//계속 진행
					continue;
				}
				else
				{
					strcpy(s_msg_code, "ORD-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "CORDPRDPLN SELECT(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CORDPRDPLN.AREA_ID), CORDPRDPLN.AREA_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CORDPRDPLN.OPER), CORDPRDPLN.OPER);
					TRS.add_fieldmsg(out_node, "PLAN_DATE", DT_STRING, sizeof(CORDPRDPLN.PLAN_DATE), CORDPRDPLN.PLAN_DATE);
					TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CORDPRDPLN.MAT_ID), CORDPRDPLN.MAT_ID);


					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_TRANS;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			//조회되면 UPDATE
			else if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cordprdpln(1, &CORDPRDPLN);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "ORD-0004");
					TRS.add_fieldmsg(out_node, "CORDPRDPLN DELETE(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(CORDPRDPLN.AREA_ID), CORDPRDPLN.AREA_ID);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CORDPRDPLN.OPER), CORDPRDPLN.OPER);
					TRS.add_fieldmsg(out_node, "PLAN_DATE", DT_STRING, sizeof(CORDPRDPLN.PLAN_DATE), CORDPRDPLN.PLAN_DATE);
					TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CORDPRDPLN.MAT_ID), CORDPRDPLN.MAT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);
					
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}

	COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}



/*******************************************************************************
CUS_ORD_Prod_Plan_Registration_Validation()
- Validation Check sub function of "CUS_ORD_PROD_PLAN_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Prod_Plan_Registration_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	//struct MWIPMATDEF_TAG MWIPMATDEF;

	TRSNode **prod_plan_list;

	int i = 0;
    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "12") == MP_FALSE)
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

	prod_plan_list = TRS.get_list(in_node, "DATA_LIST");


	for (i = 0; i < TRS.get_item_count(in_node, "DATA_LIST"); i++)
	{
		//추후 더 빡세게 Validation할꺼임(테이블별로 조회)
		if (COM_isnullspace(TRS.get_string(prod_plan_list[i], "AREA_ID")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}

		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
		TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), prod_plan_list[i], "AREA_ID");
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0029 : 존재하지 않는 정보가 포함되어 있습니다.
			strcpy(s_msg_code, "ORD-0029");
			TRS.add_fieldmsg(out_node, "NOT INFORMATION ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "ERROR ROW", MP_INT, i);
			TRS.add_fieldmsg(out_node, "AREA_ID", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

			TRS.add_dberrmsg(out_node, DB_error_msg);

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (COM_isnullspace(TRS.get_string(prod_plan_list[i], "OPER")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "OPER", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}


		
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), prod_plan_list[i], "OPER");
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "ERROR ROW", MP_INT, i);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		


		if (COM_isnullspace(TRS.get_string(prod_plan_list[i], "PLAN_DATE")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "PLAN_DATE", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}

		if (COM_isdate(TRS.get_string(prod_plan_list[i], "PLAN_DATE")) == MP_FALSE)
		{
			//ORD-0029 : 존재하지 않는 정보가 포함되어 있습니다.
			strcpy(s_msg_code, "ORD-0029");
			TRS.add_fieldmsg(out_node, "NOT CALANDER TYPE", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "ERROR ROW", MP_INT, i);
			TRS.add_fieldmsg(out_node, "PLAN_DATE", MP_STR, sizeof(TRS.get_string(prod_plan_list[i], "PLAN_DATE")), TRS.get_string(prod_plan_list[i], "PLAN_DATE"));
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		if (COM_isnullspace(TRS.get_string(prod_plan_list[i], "MAT_ID")) == MP_TRUE)
		{
			strcpy(s_msg_code, "WIP-0001");
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_NVST);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_VALIDATION;
			gs_log_type.category = MP_LOG_CATE_TRANS;
			return MP_FALSE;
		}

		//2021/07/19 품목 등록 의미없음 품목까지해서 계획 관리할수있는게 아님/ 날려버림 '*' 들어가게함 추후 어떻게 될지 몰라 컬럼에.
		/*
		DBU_init_mwipmatdef(&MWIPMATDEF);
		TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), prod_plan_list[i], "MAT_ID");
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0006 : 이 제품은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0006");
			TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "ERROR ROW", MP_INT, i);
			TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		*/

		//등록,수정일때는 수량도 체크
		if (TRS.get_procstep(in_node) == '1')
		{
			if (TRS.get_double(prod_plan_list[i], "QTY") <= 0)
			{
				strcpy(s_msg_code, "WIP-0001");
				TRS.add_fieldmsg(out_node, "QTY", MP_NVST);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				return MP_FALSE;
			}
		}
	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_ORD_Prod_Plan_Registration_Before_Transaction()
- Main sub function of "CUS_ORD_PROD_PLAN_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Prod_Plan_Registration_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}

/*******************************************************************************
CUS_ORD_Prod_Plan_Registration_After_Transaction()
- Main sub function of "CUS_ORD_PROD_PLAN_REGISTRATION" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Prod_Plan_Registration_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    return MP_TRUE;
}