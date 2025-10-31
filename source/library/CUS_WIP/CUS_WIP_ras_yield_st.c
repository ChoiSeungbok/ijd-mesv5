/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_ras_yield_st.c
Description : 공정 LOT 기타 입고

MES Version : 5.0

Function List


Detail Description

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/20  KY.JUNG        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_ras_yield_st_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_ras_yield_st_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_ras_yield_st_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_ras_yield_st_MAIN(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_RAS_YIELD_ST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_ras_yield_st()
- Tran Etc In Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_ras_yield_st(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_RAS_YIELD_ST(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_RAS_YIELD_ST", out_node);
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
CUS_WIP_ras_yield_st()
- Main sub function of "CUS_WIP_ras_yield_st" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_RAS_YIELD_ST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CWIPPRYER_TAG CWIPPRYER;

	TRSNode *create_in;
	TRSNode **std_list;




    LOG_head("CUS_WIP_ras_yield_st");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);




	char s_sys_time[14];
	int i = 0;

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



	if (TRS.get_procstep(in_node) == '1')
	{

		std_list = TRS.get_list(in_node, "YEILD_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "YEILD_LIST"); i++)
		{

			create_in = TRS.add_node(in_node, "create_in_node");
			CopyDefaultMembers(create_in, in_node);

			DBU_init_cwippryer(&CWIPPRYER);

			TRS.copy(CWIPPRYER.FACTORY, sizeof(CWIPPRYER.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPPRYER.STD_YEAR, sizeof(CWIPPRYER.STD_YEAR), std_list[i], "STD_YEAR");
			//TRS.copy(CWIPPRYER.STD_TYPE, sizeof(CWIPPRYER.STD_TYPE), in_node, TRS.get_string(lot_list[i], "STD_TYPE"));
			CWIPPRYER.STD_TYPE = TRS.get_int(std_list[i], "STD_TYPE");
		//	TRS.copy(CWIPPRYER.STD_TYPE_DESC, sizeof(CWIPPRYER.STD_TYPE_DESC), std_list[i], "STD_TYPE_DESC");
			TRS.copy(CWIPPRYER.AREA_ID, sizeof(CWIPPRYER.FACTORY), std_list[i], "AREA_ID");

			DBU_select_cwippryer(1, &CWIPPRYER);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{



					TRS.copy(CWIPPRYER.FACTORY, sizeof(CWIPPRYER.FACTORY), in_node, IN_FACTORY);
					TRS.copy(CWIPPRYER.STD_YEAR, sizeof(CWIPPRYER.STD_YEAR), std_list[i], "STD_YEAR");
					//TRS.copy(CWIPPRYER.STD_TYPE, sizeof(CWIPPRYER.STD_TYPE), in_node, TRS.get_string(lot_list[i], "STD_TYPE"));
					CWIPPRYER.STD_TYPE = TRS.get_int(std_list[i], "STD_TYPE");
					//	TRS.copy(CWIPPRYER.STD_TYPE_DESC, sizeof(CWIPPRYER.STD_TYPE_DESC), std_list[i], "STD_TYPE_DESC");
					TRS.copy(CWIPPRYER.AREA_ID, sizeof(CWIPPRYER.FACTORY), std_list[i], "AREA_ID");

					CWIPPRYER.QTR_01 = TRS.get_double(std_list[i], "QTR_01");
					CWIPPRYER.QTR_02 = TRS.get_double(std_list[i], "QTR_02");
					CWIPPRYER.QTR_03 = TRS.get_double(std_list[i], "QTR_03");
					CWIPPRYER.QTR_04 = TRS.get_double(std_list[i], "QTR_04");

					CWIPPRYER.MTH_01 = TRS.get_double(std_list[i], "MTH_01");
					CWIPPRYER.MTH_02 = TRS.get_double(std_list[i], "MTH_02");
					CWIPPRYER.MTH_03 = TRS.get_double(std_list[i], "MTH_03");
					CWIPPRYER.MTH_04 = TRS.get_double(std_list[i], "MTH_04");

					CWIPPRYER.MTH_05 = TRS.get_double(std_list[i], "MTH_05");
					CWIPPRYER.MTH_06 = TRS.get_double(std_list[i], "MTH_06");
					CWIPPRYER.MTH_07 = TRS.get_double(std_list[i], "MTH_07");
					CWIPPRYER.MTH_08 = TRS.get_double(std_list[i], "MTH_08");

					CWIPPRYER.MTH_09 = TRS.get_double(std_list[i], "MTH_09");
					CWIPPRYER.MTH_10 = TRS.get_double(std_list[i], "MTH_10");
					CWIPPRYER.MTH_11 = TRS.get_double(std_list[i], "MTH_11");
					CWIPPRYER.MTH_12 = TRS.get_double(std_list[i], "MTH_12");

					TRS.copy(CWIPPRYER.CMF_2, sizeof(CWIPPRYER.CMF_2), std_list[i], "CMF_2");
					TRS.copy(CWIPPRYER.CMF_3, sizeof(CWIPPRYER.CMF_3), std_list[i], "CMF_3");

					TRS.copy(CWIPPRYER.CREATE_USER_ID, sizeof(CWIPPRYER.CREATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPPRYER.CREATE_TIME, gs_sys_time, sizeof(CWIPPRYER.CREATE_TIME));
					TRS.copy(CWIPPRYER.UPDATE_USER_ID, sizeof(CWIPPRYER.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPPRYER.UPDATE_TIME, gs_sys_time, sizeof(CWIPPRYER.UPDATE_TIME));




					DBU_insert_cwippryer(&CWIPPRYER);
					if (DB_error_code != DB_SUCCESS)
					{

						strcpy(s_msg_code, "QCM-0004");
						TRS.add_fieldmsg(out_node, "CWIPPRYER INSERT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRYER.FACTORY), CWIPPRYER.FACTORY);
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
					strcpy(s_msg_code, "CMN-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRYER SELECTE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRYER.FACTORY), CWIPPRYER.FACTORY);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_SETUP;

					return MP_FALSE;
				}
			}
			else
			{


				TRS.copy(CWIPPRYER.FACTORY, sizeof(CWIPPRYER.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPPRYER.STD_YEAR, sizeof(CWIPPRYER.STD_YEAR), std_list[i], "STD_YEAR");
				//TRS.copy(CWIPPRYER.STD_TYPE, sizeof(CWIPPRYER.STD_TYPE), in_node, TRS.get_string(lot_list[i], "STD_TYPE"));
				CWIPPRYER.STD_TYPE = TRS.get_int(std_list[i], "STD_TYPE");
				//	TRS.copy(CWIPPRYER.STD_TYPE_DESC, sizeof(CWIPPRYER.STD_TYPE_DESC), std_list[i], "STD_TYPE_DESC");
				TRS.copy(CWIPPRYER.AREA_ID, sizeof(CWIPPRYER.FACTORY), std_list[i], "AREA_ID");

				CWIPPRYER.QTR_01 = TRS.get_double(std_list[i], "QTR_01");
				CWIPPRYER.QTR_02 = TRS.get_double(std_list[i], "QTR_02");
				CWIPPRYER.QTR_03 = TRS.get_double(std_list[i], "QTR_03");
				CWIPPRYER.QTR_04 = TRS.get_double(std_list[i], "QTR_04");

				CWIPPRYER.MTH_01 = TRS.get_double(std_list[i], "MTH_01");
				CWIPPRYER.MTH_02 = TRS.get_double(std_list[i], "MTH_02");
				CWIPPRYER.MTH_03 = TRS.get_double(std_list[i], "MTH_03");
				CWIPPRYER.MTH_04 = TRS.get_double(std_list[i], "MTH_04");

				CWIPPRYER.MTH_05 = TRS.get_double(std_list[i], "MTH_05");
				CWIPPRYER.MTH_06 = TRS.get_double(std_list[i], "MTH_06");
				CWIPPRYER.MTH_07 = TRS.get_double(std_list[i], "MTH_07");
				CWIPPRYER.MTH_08 = TRS.get_double(std_list[i], "MTH_08");

				CWIPPRYER.MTH_09 = TRS.get_double(std_list[i], "MTH_09");
				CWIPPRYER.MTH_10 = TRS.get_double(std_list[i], "MTH_10");
				CWIPPRYER.MTH_11 = TRS.get_double(std_list[i], "MTH_11");
				CWIPPRYER.MTH_12 = TRS.get_double(std_list[i], "MTH_12");

				TRS.copy(CWIPPRYER.CMF_2, sizeof(CWIPPRYER.CMF_2), std_list[i], "CMF_2");
				TRS.copy(CWIPPRYER.CMF_3, sizeof(CWIPPRYER.CMF_3), std_list[i], "CMF_3");

				TRS.copy(CWIPPRYER.CREATE_USER_ID, sizeof(CWIPPRYER.CREATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPPRYER.CREATE_TIME, gs_sys_time, sizeof(CWIPPRYER.CREATE_TIME));
				TRS.copy(CWIPPRYER.UPDATE_USER_ID, sizeof(CWIPPRYER.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPPRYER.UPDATE_TIME, gs_sys_time, sizeof(CWIPPRYER.UPDATE_TIME));


				DBU_update_cwippryer(1,&CWIPPRYER);
				if (DB_error_code != DB_SUCCESS)
				{

					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRYER INSERT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRYER.FACTORY), CWIPPRYER.FACTORY);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;

				}
			}

	}

	//	TRS.free_node(cmn_out);
	}
	else if (TRS.get_procstep(in_node) == '2')
	{
		std_list = TRS.get_list(in_node, "YEILD_LIST");

		for (i = 0; i < TRS.get_item_count(in_node, "YEILD_LIST"); i++)
		{

			create_in = TRS.add_node(in_node, "create_in_node");
			CopyDefaultMembers(create_in, in_node);

			DBU_init_cwippryer(&CWIPPRYER);

			TRS.copy(CWIPPRYER.FACTORY, sizeof(CWIPPRYER.FACTORY), in_node, IN_FACTORY);
			TRS.copy(CWIPPRYER.STD_YEAR, sizeof(CWIPPRYER.STD_YEAR), std_list[i], "STD_YEAR");
			//TRS.copy(CWIPPRYER.STD_TYPE, sizeof(CWIPPRYER.STD_TYPE), in_node, TRS.get_string(lot_list[i], "STD_TYPE"));
			CWIPPRYER.STD_TYPE = TRS.get_int(std_list[i], "STD_TYPE");
			TRS.copy(CWIPPRYER.STD_TYPE_DESC, sizeof(CWIPPRYER.STD_TYPE_DESC), std_list[i], "STD_TYPE_DESC");
			TRS.copy(CWIPPRYER.AREA_ID, sizeof(CWIPPRYER.FACTORY), std_list[i], "AREA_ID");

			CWIPPRYER.QTR_01 = TRS.get_double(std_list[i], "QTR_01");
			CWIPPRYER.QTR_02 = TRS.get_double(std_list[i], "QTR_02");
			CWIPPRYER.QTR_03 = TRS.get_double(std_list[i], "QTR_03");
			CWIPPRYER.QTR_04 = TRS.get_double(std_list[i], "QTR_04");

			CWIPPRYER.MTH_01 = TRS.get_double(std_list[i], "MTH_01");
			CWIPPRYER.MTH_02 = TRS.get_double(std_list[i], "MTH_02");
			CWIPPRYER.MTH_03 = TRS.get_double(std_list[i], "MTH_03");
			CWIPPRYER.MTH_04 = TRS.get_double(std_list[i], "MTH_04");

			CWIPPRYER.MTH_05 = TRS.get_double(std_list[i], "MTH_05");
			CWIPPRYER.MTH_06 = TRS.get_double(std_list[i], "MTH_06");
			CWIPPRYER.MTH_07 = TRS.get_double(std_list[i], "MTH_07");
			CWIPPRYER.MTH_08 = TRS.get_double(std_list[i], "MTH_08");

			CWIPPRYER.MTH_09 = TRS.get_double(std_list[i], "MTH_09");
			CWIPPRYER.MTH_10 = TRS.get_double(std_list[i], "MTH_10");
			CWIPPRYER.MTH_11 = TRS.get_double(std_list[i], "MTH_11");
			CWIPPRYER.MTH_12 = TRS.get_double(std_list[i], "MTH_12");

			TRS.copy(CWIPPRYER.CMF_2, sizeof(CWIPPRYER.CMF_2), std_list[i], "CMF_2");
			TRS.copy(CWIPPRYER.CMF_3, sizeof(CWIPPRYER.CMF_3), std_list[i], "CMF_3");

			TRS.copy(CWIPPRYER.CREATE_USER_ID, sizeof(CWIPPRYER.CREATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPPRYER.CREATE_TIME, gs_sys_time, sizeof(CWIPPRYER.CREATE_TIME));
			TRS.copy(CWIPPRYER.UPDATE_USER_ID, sizeof(CWIPPRYER.UPDATE_USER_ID), in_node, IN_USERID);
			memcpy(CWIPPRYER.UPDATE_TIME, gs_sys_time, sizeof(CWIPPRYER.UPDATE_TIME));


			DBU_delete_cwippryer(1, &CWIPPRYER);
			{
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "CWIPPRYER DELETE", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRYER.FACTORY), CWIPPRYER.FACTORY);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;

			}
		}


	}

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_ras_yield_st_Validation()
- Validation Check sub function of "CUS_WIP_ras_yield_st" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_ras_yield_st_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
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

