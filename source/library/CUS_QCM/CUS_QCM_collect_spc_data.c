/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_collect_spc_data.c
Description : Collect spc data function

MES Version : 5.0

Function List
-

Detail Description
- SPC 를 위해 따로 EDC 서비스를 호출하게하는 서비스
- 판정 이후에도 검사데이터를 수시로 변경할 수 있지만, Lot의 Flow가 변경되면 EDC서비스 코어 내부에서 오류가 발생하므로,  Flow가 변경된 Lot(ex. 검사 후 창고에있는 Lot등 )에 대해서는 서비스를 리턴시킨다.

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2021/02/04  KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_QCM_Collect_Spc_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


/*******************************************************************************
CUS_QCM_Collect_Spc_Data()
- Tran 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Spc_Data(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_COLLECT_SPC_DATA(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_Collect_Spc_Data", out_node);
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
CUS_QCM_COLLECT_SPC_DATA()
- Main sub function of "CUS_QCM_Collect_Spc_Data" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_COLLECT_SPC_DATA(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct CQCMISPDAT_TAG CQCMISPDAT;
	struct MWIPLOTSTSX_TAG MWIPLOTSTSX;

	struct CWIPRCPDEF_TAG CWIPRCPDEF;
	struct MWIPCOLDEF_TAG MWIPCOLDEF;
	struct MEDCCOLVER_TAG MEDCCOLVER;
	//struct MEDCCOLCHR_TAG MEDCCOLCHR;
	struct MEDCLOTDAT_TAG MEDCLOTDAT;
	struct MWIPOPRDEF_TAG MWIPOPRDEF;
	struct MEDCCHRDEF_TAG MEDCCHRDEF;

	
//	char s_member_name[9];
	char s_sys_time[14];

	int iCnt = 0;
//	int i_data_count;

//	TRSNode **data_list;

	// For EDC
	TRSNode *collect_lot_in;
	TRSNode *char_list;
	TRSNode  *unit_list;
	TRSNode  *value_list;
	TRSNode  *value_seq_list;
	TRSNode *edc_out;
//	TRSNode **all_thick_list;
	//TRSNode **flatness_list;

    LOG_head("CUS_QCM_Collect_Spc_Data");
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
    if (CUS_QCM_Collect_Spc_Data_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
   
	//return MP_TRUE;

	//접수
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

		DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		memcpy(MWIPLOTSTSX.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);

		// Lot이 삭제된 상태이면  EDC 저장로직에서 오류발생하므로,  태우지 않고 리턴해준다.
		if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
		{
			return MP_TRUE;
		}


		DBU_init_cqcmispdat(&CQCMISPDAT);
		TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(CQCMISPDAT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
		if ((int)DBU_select_cqcmispdat_scalar(5, &CQCMISPDAT) == 0)
		{
			return MP_TRUE;
		}


		if (memcmp(CQCMISPSTS.INSP_TYPE, MP_INSP_TYPE_IQC, strlen(MP_INSP_TYPE_IQC)) != 0)
		{

			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "WIP-0004");
				TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			if (COM_isspace(MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID)) == MP_TRUE)
			{
				strcpy(s_msg_code, "QCM-0064");
				TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MWIPOPRDEF.AREA_ID), MWIPOPRDEF.AREA_ID);
				return MP_FALSE;
			}


			/*EDC등록이력이 없는상태에서,  새로 EDC 등록시에는 현재 LOT의 공정이 검사공정과 다를경우 ( Ex. 이미 판정 후 검사를 통과한 LOT)
			리턴시킨다.
			(EDC등록하려는 COL_SET_ID의 공정과 현재 LOT의 공정이 다를 경우 코어서비스내에서 오류를 내기 때문
			  => 현재 P급 )
			*/
			
			if (memcmp(CQCMISPSTS.CMF_3, MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW) != 0))
			{
				return MP_TRUE;
			}

			if (memcmp(CQCMISPSTS.INSP_OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER) != 0))
			{
				return MP_TRUE;
			}

			

			//레시피 정보 조회
			DBU_init_cwiprcpdef(&CWIPRCPDEF);
			memcpy(CWIPRCPDEF.FACTORY, CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY));
			memcpy(CWIPRCPDEF.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			memcpy(CWIPRCPDEF.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			memcpy(CWIPRCPDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			DBU_select_cwiprcpdef(1, &CWIPRCPDEF);

			// Collection Set ID 찾기
			DBU_init_mwipcoldef(&MWIPCOLDEF);
			memcpy(MWIPCOLDEF.FACTORY, CQCMISPSTS.FACTORY, sizeof(MWIPCOLDEF.FACTORY));
			memcpy(MWIPCOLDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(MWIPCOLDEF.MAT_ID));
			MWIPCOLDEF.MAT_VER = CQCMISPSTS.MAT_VER;
			memcpy(MWIPCOLDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(MWIPCOLDEF.OPER));
			MWIPCOLDEF.OPT_LEVEL = '4';        // Material - Operation Mode
			MWIPCOLDEF.DISABLE_FLAG = 'N';

			DBU_select_mwipcoldef(4, &MWIPCOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_init_mwipcoldef(&MWIPCOLDEF);
					memcpy(MWIPCOLDEF.FACTORY, CQCMISPSTS.FACTORY, sizeof(MWIPCOLDEF.FACTORY));
					memcpy(MWIPCOLDEF.OPER, CQCMISPSTS.INSP_OPER, sizeof(MWIPCOLDEF.OPER));
					MWIPCOLDEF.OPT_LEVEL = '3';        // Operation Mode
					MWIPCOLDEF.DISABLE_FLAG = 'N';
					DBU_select_mwipcoldef(3, &MWIPCOLDEF);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							// EDC-0008 : COLLECTION SET이 MATERIAL-FLOW-OPERATION에 존재하지 않읍니다.            
							strcpy(s_msg_code, "EDC-0008");
						}
						else
						{
							strcpy(s_msg_code, "EDC-0004");
							TRS.add_dberrmsg(out_node, DB_error_msg);
						}

						TRS.add_fieldmsg(out_node, "Select MWIPCOLDEF 3", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
						TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
						TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPCOLDEF.MAT_VER);
						TRS.add_fieldmsg(out_node, "DISABLE_FLAG", DT_CHAR, MWIPCOLDEF.DISABLE_FLAG);
						TRS.add_fieldmsg(out_node, "OPT_LEVEL", DT_CHAR, MWIPCOLDEF.OPT_LEVEL);

						return MP_FALSE;
					}
				}
				else
				{
					strcpy(s_msg_code, "EDC-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					TRS.add_fieldmsg(out_node, "Select MWIPCOLDEF 3", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MWIPCOLDEF.FACTORY), MWIPCOLDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(MWIPCOLDEF.OPER), MWIPCOLDEF.OPER);
					TRS.add_fieldmsg(out_node, "MAT_ID", DT_STRING, sizeof(MWIPCOLDEF.MAT_ID), MWIPCOLDEF.MAT_ID);
					TRS.add_fieldmsg(out_node, "MAT_VER", DT_INT, MWIPCOLDEF.MAT_VER);
					TRS.add_fieldmsg(out_node, "DISABLE_FLAG", DT_CHAR, MWIPCOLDEF.DISABLE_FLAG);
					TRS.add_fieldmsg(out_node, "OPT_LEVEL", DT_CHAR, MWIPCOLDEF.OPT_LEVEL);

					return MP_FALSE;
				}
			}

			//EDC 데이터 등록
			// Collection Set Version 찾기
			DBC_init_medccolver(&MEDCCOLVER);
			memcpy(MEDCCOLVER.FACTORY, CQCMISPSTS.FACTORY, sizeof(MEDCCOLVER.FACTORY));
			memcpy(MEDCCOLVER.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MEDCCOLVER.COL_SET_ID));
			DBC_select_medccolver(2, &MEDCCOLVER);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					// EDC-0098 : 배포된 COLLECTION VERSION을 찾을 수 없습니다.
					strcpy(s_msg_code, "EDC-0098");
				}
				else
				{
					strcpy(s_msg_code, "EDC-0004");
					TRS.add_dberrmsg(out_node, DB_error_msg);
				}

				TRS.add_fieldmsg(out_node, "MEDCCOLVER SELECT 2", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLVER.FACTORY), MEDCCOLVER.FACTORY);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLVER.COL_SET_ID), MEDCCOLVER.COL_SET_ID);

				return MP_FALSE;
			}




			collect_lot_in = TRS.add_node(in_node, "Collect_Lot_In");
			CopyDefaultMembers(collect_lot_in, in_node);
			TRS.add_char(collect_lot_in, IN_PROCSTEP, '4');
			TRS.add_string(collect_lot_in, "LOT_ID", CQCMISPSTS.LOT_ID, sizeof(CQCMISPSTS.LOT_ID));
			TRS.add_string(collect_lot_in, "MAT_ID", CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			TRS.add_int(collect_lot_in, "MAT_VER", CQCMISPSTS.MAT_VER);
			TRS.add_string(collect_lot_in, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
			TRS.add_int(collect_lot_in, "FLOW_SEQ_NUM", MWIPLOTSTSX.FLOW_SEQ_NUM);
			TRS.add_string(collect_lot_in, "OPER", CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			TRS.add_string(collect_lot_in, "COL_SET_ID", MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			TRS.add_int(collect_lot_in, "COL_SET_VERSION", MEDCCOLVER.COL_SET_VERSION);
			TRS.add_nstring(collect_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
			//TRS.add_char(collect_lot_in, "SELECT_MFO_FLAG", ' ');
			TRS.add_string(collect_lot_in, "RECIPE_ID", CWIPRCPDEF.RECIPE_NO, sizeof(CWIPRCPDEF.RECIPE_NO));





			//이미 edc데이터가 있는지 확인한다. 없으면 insert, 있으면 update
			DBU_init_medclotdat(&MEDCLOTDAT);
			memcpy(MEDCLOTDAT.LOT_ID, CQCMISPSTS.LOT_ID, sizeof(CQCMISPSTS.LOT_ID));
			//MEDCLOTDAT.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
			memcpy(MEDCLOTDAT.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			memcpy(MEDCLOTDAT.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			MEDCLOTDAT.COL_SET_VERSION = MEDCCOLVER.COL_SET_VERSION;
			memcpy(MEDCLOTDAT.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			MEDCLOTDAT.MAT_VER = 1;

			iCnt = (int)DBU_select_medclotdat_scalar(3, &MEDCLOTDAT); // MAX Hist Seq
			if (iCnt == 0)
			{


				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
				DBU_open_cqcmispdat(7, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//QCM-0050 : 이 검사ID은(는) 존재 하지 않습니다.
					strcpy(s_msg_code, "QCM-0050");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 7);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cqcmispdat(7, &CQCMISPDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cqcmispdat(7);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0050");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, 7);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						// 20.12.22 minjae.go
						DBU_close_cqcmispdat(7);
						return MP_FALSE;
						//
					}


					// CHAR_ID를 unit_seq 1일 때만 넘겨야,  Char_seq_num 값이 제대로 들어감. (안그러면, 캐릭터가 같아도 순차적으로 증가되버림)
					if (CQCMISPDAT.UNIT_SEQ == 1)
					{
						char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");
						TRS.add_string(char_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
					}


					unit_list = TRS.add_node(char_list, "UNIT_LIST");

					if (COM_isnullspace(CQCMISPDAT.UNIT_ID) == MP_FALSE)
					{
						TRS.add_string(unit_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
					}
					else {
						DBC_init_medcchrdef(&MEDCCHRDEF);
						TRS.copy(MEDCCHRDEF.FACTORY, sizeof(MEDCCHRDEF.FACTORY), in_node, IN_FACTORY);
						memcpy(MEDCCHRDEF.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID));
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

						TRS.add_string(unit_list, "UNIT_ID", MEDCCHRDEF.UNIT, sizeof(MEDCCHRDEF.UNIT));
					}

					
					TRS.add_char(unit_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", CQCMISPDAT.UNIT_SEQ);


					for (int irow = 1; irow <= CQCMISPDAT.VALUE_COUNT; irow++)
					{
						value_list = TRS.add_node(unit_list, "VALUE_LIST");
						 if (irow == 1)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						}
						else if (irow == 2)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
						}
						else if (irow == 3)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
						}
						else if (irow == 4)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
						}
						else if (irow == 5)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
						}
						else if (irow == 6)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
						}
						else if (irow == 7)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
						}
						else if (irow == 8)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
						}
						else if (irow == 9)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
						}
						else if (irow == 10)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
						}
						else if (irow == 11)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
						}
						else if (irow == 12)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
						}
						else if (irow == 13)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
						}
						else if (irow == 14)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
						}
						else if (irow == 15)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
						}
						else if (irow == 16)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
						}
						else if (irow == 17)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
						}
						else if (irow == 18)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
						}
						else if (irow == 19)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
						}
						else if (irow == 20)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
						}
						else if (irow == 21)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
						}
						else if (irow == 22)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
						}
						else if (irow == 23)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
						}
						else if (irow == 24)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
						}
						else if (irow == 25)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));
						}	
					}
				}

				edc_out = TRS.create_node("Edc_Out");
				if (EDC_COLLECT_LOT_DATA(s_msg_code, collect_lot_in, edc_out) == MP_FALSE)
				{
					TRS.clone(out_node, edc_out);
					TRS.free_node(edc_out);
					return MP_FALSE;
				}

				TRS.free_node(edc_out);

			}
			else
			{
				TRS.set_char(collect_lot_in, IN_PROCSTEP, '1');
				TRS.add_int(collect_lot_in, "HIST_SEQ", iCnt);
				//TRS.add_char(collect_lot_in, "COL_SET_OVR_FLAG", 'Y');
			    TRS.add_string(collect_lot_in, "PROC_FLOW", CQCMISPSTS.CMF_3, sizeof(CQCMISPSTS.CMF_3));
			    TRS.add_string(collect_lot_in, "PROC_OPER", CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));


				DBU_init_cqcmispdat(&CQCMISPDAT);
				TRS.copy(CQCMISPDAT.FACTORY, sizeof(CQCMISPDAT.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CQCMISPDAT.INSP_ID, sizeof(CQCMISPDAT.INSP_ID), in_node, "INSP_ID");
				DBU_open_cqcmispdat(7, &CQCMISPDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//QCM-0050 : 이 검사ID은(는) 존재 하지 않습니다.
					strcpy(s_msg_code, "QCM-0050");
					TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 7);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_cqcmispdat(7, &CQCMISPDAT);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_cqcmispdat(7);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "QCM-0050");
						TRS.add_fieldmsg(out_node, "CQCMISPDAT OPEN", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, 7);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPDAT.FACTORY), CQCMISPDAT.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPDAT.INSP_ID), CQCMISPDAT.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						// 20.12.22 minjae.go
						DBU_close_cqcmispdat(7);
						return MP_FALSE;
						//
					}

					char_list = TRS.add_node(collect_lot_in, "CHAR_LIST");
					TRS.add_string(char_list, "CHAR_ID", CQCMISPDAT.CHAR_ID, sizeof(CQCMISPDAT.CHAR_ID));
					TRS.add_string(char_list, "COL_SET_ID", CQCMISPDAT.COL_SET_ID, sizeof(CQCMISPDAT.COL_SET_ID));
					TRS.add_int(char_list, "CHAR_SEQ_NUM", CQCMISPDAT.CHAR_SEQ);
					TRS.add_int(char_list, "COL_SET_VERSION", CQCMISPDAT.COL_SET_VER);
					TRS.add_int(char_list, "COL_SEQ", 1);

					unit_list = TRS.add_node(char_list, "UNIT_LIST");
					if (COM_isnullspace(CQCMISPDAT.UNIT_ID) == MP_FALSE)
					{
						TRS.add_string(unit_list, "UNIT_ID", CQCMISPDAT.UNIT_ID, sizeof(CQCMISPDAT.UNIT_ID));
					}
					else {
						DBC_init_medcchrdef(&MEDCCHRDEF);
						TRS.copy(MEDCCHRDEF.FACTORY, sizeof(MEDCCHRDEF.FACTORY), in_node, IN_FACTORY);
						memcpy(MEDCCHRDEF.CHAR_ID, CQCMISPDAT.CHAR_ID, sizeof(MEDCCHRDEF.CHAR_ID));
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

						TRS.add_string(unit_list, "UNIT_ID", MEDCCHRDEF.UNIT, sizeof(MEDCCHRDEF.UNIT));
					}


					TRS.add_char(unit_list, "VALUE_TYPE", CQCMISPDAT.VALUE_TYPE);
					TRS.add_int(unit_list, "UNIT_SEQ_NUM", CQCMISPDAT.UNIT_SEQ);

					value_seq_list = TRS.add_node(unit_list, "VALUE_SEQ_LIST");
					TRS.add_int(value_seq_list, "VALUE_SEQ_NUM", 1);

					for (int irow = 1; irow <= CQCMISPDAT.VALUE_COUNT; irow++)
					{
						value_list = TRS.add_node(value_seq_list, "VALUE_LIST");
						if (irow == 1)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_1, sizeof(CQCMISPDAT.VALUE_1));
						}
						else if (irow == 2)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_2, sizeof(CQCMISPDAT.VALUE_2));
						}
						else if (irow == 3)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_3, sizeof(CQCMISPDAT.VALUE_3));
						}
						else if (irow == 4)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_4, sizeof(CQCMISPDAT.VALUE_4));
						}
						else if (irow == 5)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_5, sizeof(CQCMISPDAT.VALUE_5));
						}
						else if (irow == 6)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_6, sizeof(CQCMISPDAT.VALUE_6));
						}
						else if (irow == 7)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_7, sizeof(CQCMISPDAT.VALUE_7));
						}
						else if (irow == 8)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_8, sizeof(CQCMISPDAT.VALUE_8));
						}
						else if (irow == 9)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_9, sizeof(CQCMISPDAT.VALUE_9));
						}
						else if (irow == 10)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_10, sizeof(CQCMISPDAT.VALUE_10));
						}
						else if (irow == 11)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_11, sizeof(CQCMISPDAT.VALUE_11));
						}
						else if (irow == 12)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_12, sizeof(CQCMISPDAT.VALUE_12));
						}
						else if (irow == 13)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_13, sizeof(CQCMISPDAT.VALUE_13));
						}
						else if (irow == 14)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_14, sizeof(CQCMISPDAT.VALUE_14));
						}
						else if (irow == 15)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_15, sizeof(CQCMISPDAT.VALUE_15));
						}
						else if (irow == 16)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_16, sizeof(CQCMISPDAT.VALUE_16));
						}
						else if (irow == 17)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_17, sizeof(CQCMISPDAT.VALUE_17));
						}
						else if (irow == 18)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_18, sizeof(CQCMISPDAT.VALUE_18));
						}
						else if (irow == 19)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_19, sizeof(CQCMISPDAT.VALUE_19));
						}
						else if (irow == 20)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_20, sizeof(CQCMISPDAT.VALUE_20));
						}
						else if (irow == 21)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_21, sizeof(CQCMISPDAT.VALUE_21));
						}
						else if (irow == 22)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_22, sizeof(CQCMISPDAT.VALUE_22));
						}
						else if (irow == 23)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_23, sizeof(CQCMISPDAT.VALUE_23));
						}
						else if (irow == 24)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_24, sizeof(CQCMISPDAT.VALUE_24));
						}
						else if (irow == 25)
						{
							TRS.add_string(value_list, "VALUE", CQCMISPDAT.VALUE_25, sizeof(CQCMISPDAT.VALUE_25));
						}
					}
					
				}

				edc_out = TRS.create_node("Edc_Out");
				if (EDC_CHANGE_LOT_DATA(s_msg_code, collect_lot_in, edc_out) == MP_FALSE)
				{
					TRS.clone(out_node, edc_out);
					TRS.free_node(edc_out);
					return MP_FALSE;
				}

				TRS.free_node(edc_out);
			}
		}

	}

    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_Collect_Spc_Data_Validation()
- Validation Check sub function of "CUS_QCM_COLLECT_SPC_DATA" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_Collect_Spc_Data_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

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

    return MP_TRUE;
}
