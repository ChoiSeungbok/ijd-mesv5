/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM__Recipe_Management.c
Description : Recipe Management function

MES Version : 5.0

Function List
-

Detail Description
- 라운드검사에서 필요한 레시피정보를 등록, 수정, 삭제  서비스
- 레시피 등록 및  설비에 Lot의 정보를 재전달하기 위한 서비스 

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/01/14  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Recipe_Management_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Recipe_Management()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Recipe_Management(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_RECIPE_MANAGEMENT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Recipe_Management", out_node);
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
CUS_QCM_RECIPE_MANAGEMENT()
- Main sub function of "CUS_QCM_Recipe_Management" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_RECIPE_MANAGEMENT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CWIPRCPDEF_TAG CWIPRCPDEF;
	struct MWIPMATDEF_TAG MWIPMATDEF;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;

	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
	//struct MWIPORDSTS_TAG MWIPORDSTS;
	struct MRASRESDEF_TAG MRASRESDEF;

	char s_sys_time[14];

	char c_flag = ' ';
	TRSNode *send_in;
	TRSNode *cmn_out;
	TRSNode **data_list;

	int i_data_count;

	//int i_select_count;

    LOG_head("CUS_QCM_Recipe_Management");
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
    if (CUS_QCM_Recipe_Management_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   



	//레시피정보 생성 및 수정
	if (TRS.get_procstep(in_node) == '1')
	{
		//필수 정보 MAT_ID, OPER 존재 체크 벨리데이션 



		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{

			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), data_list[i], "MAT_ID");
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0006 이제품은 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0006");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), data_list[i], "OPER");
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0010 이 공정은 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}



			DBU_init_cwiprcpdef(&CWIPRCPDEF);
			TRS.copy(CWIPRCPDEF.FACTORY, sizeof(CWIPRCPDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPRCPDEF.AREA_ID, sizeof(CWIPRCPDEF.AREA_ID), data_list[i], "AREA_ID");
			TRS.copy(CWIPRCPDEF.MAT_ID, sizeof(CWIPRCPDEF.MAT_ID), data_list[i], "MAT_ID");
			TRS.copy(CWIPRCPDEF.OPER, sizeof(CWIPRCPDEF.OPER), data_list[i], "OPER");
			DBU_select_cwiprcpdef(1, &CWIPRCPDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					c_flag = 'I';
				}
				else
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "CWIPRCPDEF SELECTE", MP_NVST);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_SETUP;

					return MP_FALSE;
				}
			}
			else
			{
				c_flag = 'U';
			}




			TRS.copy(CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO), data_list[i], "RECIPE_NO");
			TRS.copy(CWIPRCPDEF.CMF_1, sizeof(CWIPRCPDEF.CMF_1), data_list[i], "GRADE");
			TRS.copy(CWIPRCPDEF.CMF_2, sizeof(CWIPRCPDEF.CMF_2), data_list[i], "THICK");
			TRS.copy(CWIPRCPDEF.CMF_3, sizeof(CWIPRCPDEF.CMF_3), data_list[i], "POL_YN");

			if (c_flag == 'I')
			{
				TRS.copy(CWIPRCPDEF.CREATE_USER_ID, sizeof(CWIPRCPDEF.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPRCPDEF.CREATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_insert_cwiprcpdef(&CWIPRCPDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "CWIPRCPDEF INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPRCPDEF.OPER), CWIPRCPDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_SETUP;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else if (c_flag == 'U')
			{
				TRS.copy(CWIPRCPDEF.UPDATE_USER_ID, sizeof(CWIPRCPDEF.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPRCPDEF.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));

				DBU_update_cwiprcpdef(1, &CWIPRCPDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "CWIPRCPDEF UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPRCPDEF.OPER), CWIPRCPDEF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_SETUP;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			DBU_init_cwiprcpdef(&CWIPRCPDEF);
			TRS.copy(CWIPRCPDEF.FACTORY, sizeof(CWIPRCPDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPRCPDEF.AREA_ID, sizeof(CWIPRCPDEF.AREA_ID), data_list[i], "AREA_ID");
			TRS.copy(CWIPRCPDEF.MAT_ID, sizeof(CWIPRCPDEF.MAT_ID), data_list[i], "MAT_ID");
			TRS.copy(CWIPRCPDEF.OPER, sizeof(CWIPRCPDEF.OPER), data_list[i], "OPER");

			DBU_delete_cwiprcpdef(1, &CWIPRCPDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "CMN-0004");
				TRS.add_fieldmsg(out_node, "CWIPRCPDEF DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(CWIPRCPDEF.MAT_ID), CWIPRCPDEF.MAT_ID);
				TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPRCPDEF.OPER), CWIPRCPDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}
	}
	else if (TRS.get_procstep(in_node) == '3')
	{
		data_list = TRS.get_list(in_node, "DATA_LIST");
		i_data_count = TRS.get_item_count(in_node, "DATA_LIST");

		for (int i = 0; i < i_data_count; i++)
		{
			//LOT 체크
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), data_list[i], "LOT_ID");
			DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0044 이 Lot은 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0044");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}

			//Mat ID 체크
			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID), data_list[i], "MAT_ID");
			MWIPMATDEF.MAT_VER = 1;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0006 이제품은 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0006");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}

			//Oper 체크
			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), data_list[i], "OPER");
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0010 이 공정은 존재하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}
			
			DBU_init_mrasresdef(&MRASRESDEF);
			memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(MRASRESDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			MRASRESDEF.RES_CMF_1[0] = 'Y';
			memcpy(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_ROUND, strlen(MP_RESS_GRP_ROUND));
			DBU_select_mrasresdef(2, &MRASRESDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0626 : Round 검사 장비가 존재하지 않습니다. Round 검사 장비를 확인하세요.
				strcpy(s_msg_code, "WIP-0626");
				TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MRASRESDEF.AREA_ID), MRASRESDEF.AREA_ID);
				TRS.add_fieldmsg(out_node, "RES_GRP_1", MP_STR, sizeof(MRASRESDEF.RES_GRP_1), MRASRESDEF.RES_GRP_1);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_cwiprcpdef(&CWIPRCPDEF);
			memcpy(CWIPRCPDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(CWIPRCPDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(CWIPRCPDEF.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CWIPRCPDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
			DBU_select_cwiprcpdef(1, &CWIPRCPDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					//WIP-0625  Round 검사의 Recipe 정보가 존재하지 않습니다.  Recipe 정보를 확인하세요.
					strcpy(s_msg_code, "WIP-0625");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}

				TRS.add_fieldmsg(out_node, "CWIPRCPDEF SELECTE", MP_NVST);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPLOTSTSX.MAT_ID), MWIPLOTSTSX.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_SETUP;

				return MP_FALSE;
			}

			send_in = TRS.add_node(in_node, "send_in");
			TRS.add_char(send_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(send_in, in_node);
			TRS.add_string(send_in, "RES_ID", MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
			TRS.add_string(send_in, "LOT_ID", MWIPLOTSTSX.LOT_ID,sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_string(send_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			TRS.add_string(send_in, "RECIPE_ID", CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_EIS_START_LOT(s_msg_code, send_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			Sleep(300); // 설비신호 서비스 호출시  짧은시간에 수십개를 보내면 QMate쪽에서 모두 받지 못하는 현상이 발생하여 일정텀을 줌.


		}
	}

    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Recipe_Management_Validation()
- Validation Check sub function of "CUS_QCM_RECIPE_MANAGEMENT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Recipe_Management_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "123") == MP_FALSE)
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
