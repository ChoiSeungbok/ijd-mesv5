/*******************************************************************************

System      : MESplus
Module      : User Routine for WIP
File Name   : UWIP_Adapt_Lot.c
Description : User Routine for WIP_Delete_Lot_History

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2008/11/10  Miracom        Create

Copyright(C) 1998-2008 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "UWIP_common.h"
#include <WIPCore_common.h>
#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_WIP_common.h"

int WIP_DELETE_LOT_HISTORY_BEFORE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);
int WIP_DELETE_LOT_HISTORY_AFTER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node);

int WIP_Delete_Lot_History_Before_1(TRSNode* in_node, TRSNode* out_node)
{
	/* TODO : Insert your code */
	char s_msg_code[MP_SIZE_MSG];
	int i_ret = MP_TRUE;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = WIP_DELETE_LOT_HISTORY_BEFORE(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "WIP_DELETE_LOT_HISTORY_BEFORE", out_node);

	return i_ret;
}

int WIP_Delete_Lot_History_After_1(TRSNode* in_node, TRSNode* out_node)
{
	/* TODO : Insert your code */
	char s_msg_code[MP_SIZE_MSG];
	int i_ret = MP_TRUE;

	memset(s_msg_code, 0x00, MP_SIZE_MSG);

	i_ret = WIP_DELETE_LOT_HISTORY_AFTER(s_msg_code, in_node, out_node);

	if (i_ret == MP_TRUE)
		COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
	else
		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

	COM_out_msg_log_write(s_msg_code, "WIP_DELETE_LOT_HISTORY_AFTER", out_node);

	return i_ret;
}

int WIP_DELETE_LOT_HISTORY_BEFORE(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;	        //LOT 마스터
	struct MWIPLOTHISX_TAG  MWIPLOTHISX;	        //LOT 마스터
	struct MWIPLOTHISX_TAG  MWIPLOTHISX_T;	        //LOT 마스터
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX_LAD;	    //
	struct MWIPLOTHISX_TAG  MWIPLOTHISX_LAD;	    //
	struct MINVLOTSTS_TAG   MINVLOTSTS;	            //
	struct MINVLOTHIS_TAG   MINVLOTHIS;	            //
	struct CWIPOPRWRK_TAG   CWIPOPRWRK;	            //
	struct MGCMTBLDAT_TAG   MGCMTBLDAT;	            // 
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_GRT;	        //
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_TYPE;	    //
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_SRC;	        //   
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_FROM;	        //
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_TO;	        //
	struct MGCMTBLDAT_TAG   MGCMTBLDAT_AREA;	        //
	struct MWIPOPRDEF_TAG   MWIPOPRDEF;	            //
	struct MWIPOPRDEF_TAG   MWIPOPRDEF_AF;	        //
	struct MRASRESDEF_TAG   MRASRESDEF;	            //
	struct MWIPORDSTS_TAG   MWIPORDSTS;             //작업지시 마스터
	//struct CWIPERPOPR_TAG   CWIPERPOPR;             //
	struct CWIPORDOPR_TAG   CWIPORDOPR;             //
	struct MINVLOTISS_TAG   MINVLOTISS;             //
	struct MINVLOTISS_TAG   MINVLOTISS_EA;          //
	struct CWIPGRPSTS_TAG   CWIPGRPSTS;	            //
	struct CWIPGRPLOT_TAG   CWIPGRPLOT;	            //
	struct CWIPPRSRUN_TAG   CWIPPRSRUN;	            //
	struct MWIPLOTLOS_TAG   MWIPLOTLOS;	            //    
	struct CWIPLOTREC_TAG   CWIPLOTREC;	            //
	struct CWIPLOTTRC_TAG   CWIPLOTTRC;	            //    
	struct CWIPLOTPRS_TAG   CWIPLOTPRS;	            //
	struct CQCMISPSTS_TAG   CQCMISPSTS;	            //
	struct CWIPINVLDM_TAG   CWIPINVLDM;	            //
	struct MWIPMATDEF_TAG   MWIPMATDEF;	            //
	struct MWIPMATDEF_TAG   MWIPMATDEF_AF;	            //
	struct MINVDLVMST_TAG   MINVDLVMST;	            //
	struct MINVDLVDTL_TAG   MINVDLVDTL;	            //
	struct CWIPLOTCLS_TAG   CWIPLOTCLS;	            //
	struct CWIPGRTBLD_TAG   CWIPGRTBLD;	            //
	struct CWIPBLDAVG_TAG   CWIPBLDAVG;	            //  
	struct CWIPLOTLST_TAG   CWIPLOTLST;	            //
	struct CBASTXNDEF_TAG   CBASTXNDEF;	            //
	struct CBASTXNDEF_TAG   CBASTXNDEF_ETC;	        //
	struct CSUMRESWIP_TAG   CSUMRESWIP;	            //
	struct CSUMLOTDAT_TAG   CSUMLOTDAT;
	struct CWIPORDRWK_TAG   CWIPORDRWK;
	struct CWIPLOTCHG_TAG   CWIPLOTCHG;

	struct IF_MOVE_TRX_TAG         IF_MOVE_TRX;	        //
	struct IF_COMPLETION_TRX_TAG   IF_COMPLETION_TRX;	//
	struct IF_COMP_ISSUE_TRX_TAG   IF_COMP_ISSUE_TRX;	//
	struct IF_INV_TXNS_TAG         IF_INV_TXNS;	        //
	struct IF_INV_TXNS_TAG         IF_INV_TXNS_S;	    //

	TRSNode* if_in;
	TRSNode* check_in;
	TRSNode* if_end_in;
	TRSNode* inv_if;
	//TRSNode *move_in;    
	TRSNode* cv_in;
	TRSNode* erpif_in;
	TRSNode* load_in;
	//TRSNode *unstore_in;
	//TRSNode *store_in;
	//TRSNode *poif_in;    
	TRSNode* if_change_in;
	TRSNode* cmn_out;
	TRSNode* inv_list;

	TRSNode* iss_in;
	TRSNode* iss_list;

	char c_CheckErpInput;                   //ERP 완료이력 여부
	char c_CheckErpResult;                  //ERP에 생산이력 여부
	char c_CheckClassOper;                  //분류 공정 여부
	char c_CheckEndScrapOper = 'N';		    //CTM P급 판정과 같이 End 에서 Scrap 발생 여부
	double dHeaderSeq = 0;
	//int i_step = 0;
	int iStep = 0;
	int iMoveStep = 0;

	//LOT ID 조회
	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
	if (DB_error_code != DB_SUCCESS)
	{
		//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
		strcpy(s_msg_code, "WIP-0044");
		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	DBU_init_mwiplothisx(&MWIPLOTHISX);
	memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
	MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
	DBU_select_mwiplothisx(1, &MWIPLOTHISX);
	if (DB_error_code != DB_SUCCESS)
	{
		//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
		strcpy(s_msg_code, "WIP-0044");
		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}



	//TRAN CODE : CREATE 경우
	if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) == MP_FALSE)
	{
		c_CheckClassOper = 'N';

		//공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//분류 공정 여부 => 분류 공정인 경우 create 시 로직이 다르기 때문
		DBU_init_mgcmtbldat(&MGCMTBLDAT_GRT);
		TRS.copy(MGCMTBLDAT_GRT.FACTORY, sizeof(MGCMTBLDAT_GRT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_GRT.TABLE_NAME, MP_GCM_GRIT_OPER, strlen(MP_GCM_GRIT_OPER));
		memcpy(MGCMTBLDAT_GRT.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_GRT);
		if (DB_error_code == DB_SUCCESS)
		{
			c_CheckClassOper = 'Y';
		}

		//작업지시 실적 BACK
		//테스트품도 작업지시가 내려오기 때문에 작업지시 수량 변경 처리를 한다.
		//if (MWIPLOTSTSX.LOT_TYPE != MP_LOT_TYPE_TEST && c_CheckClassOper != 'Y')
		if (c_CheckClassOper != 'Y')
		{
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (MWIPOPRDEF.OPER_CMF_2[0] != 'Y')
			{
				//시작된 작업지시는 다시 살려준다.     
				//작업지시는 CREATE 삭제시 자동으로 상태값이 변경된다(코어내부) 
				//  -> 자동으로 'O' 로 변경되기 때문에 IN_NODE에 작업지시 번호를 넘겨주어 AFTER에서 'W'로 업데이트 해준다.
				if (COM_dbl_round(MWIPORDSTS.ORD_IN_QTY, 5, 'U') >= COM_dbl_round(MWIPLOTSTSX.QTY_1, 5, 'U'))
				{
					MWIPORDSTS.ORD_IN_QTY = MWIPORDSTS.ORD_IN_QTY - MWIPLOTSTSX.QTY_1;
				}
				else
				{
					MWIPORDSTS.ORD_IN_QTY = 0;
				}

				if (MWIPORDSTS.ORD_IN_QTY == 0)
				{
					TRS.set_string(in_node, "ORDER_ID", MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				}
			}

			//작업지시가 대기 상태로 되면 공정별 작업지시 테이블을 지워준다.            
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
			{
				DBU_init_cwipordopr(&CWIPORDOPR);
				memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
				memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				if (DBU_select_cwipordopr_scalar(2, &CWIPORDOPR) > 0)
				{
					DBU_delete_cwipordopr(2, &CWIPORDOPR);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPORDOPR DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
		else if (c_CheckClassOper == 'Y')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
			if (DBU_select_cwiplottrc_scalar(2, &CWIPLOTTRC) > 0)
			{
				DBU_delete_cwiplottrc(2, &CWIPLOTTRC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		DBU_init_cwiplottrc(&CWIPLOTTRC);
		memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
		memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTTRC.OPER));
		memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
		CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_cwiplottrc(2, &CWIPLOTTRC);
		if (DB_error_code == DB_SUCCESS)
		{
			DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code != DB_NOT_FOUND)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		//그릿 blending 작지인 경우 작지에 맵핑된 lot리스트를 지운다.
		//작업지시에 등록된 lot을 지운다.
		DBU_init_cwipgrtbld(&CWIPGRTBLD);
		TRS.copy(CWIPGRTBLD.FACTORY, sizeof(CWIPGRTBLD.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPGRTBLD.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPGRTBLD.ORDER_ID));
		DBU_delete_cwipgrtbld(2, &CWIPGRTBLD);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPGRTBLD DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRTBLD.FACTORY), CWIPGRTBLD.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPGRTBLD.ORDER_ID), CWIPGRTBLD.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//그릿 blending 작지인 경우 작지에 맵핑된 lot리스트를 지운다.
		DBU_init_cwipbldavg(&CWIPBLDAVG);
		TRS.copy(CWIPBLDAVG.FACTORY, sizeof(CWIPBLDAVG.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPBLDAVG.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPBLDAVG.ORDER_ID));
		DBU_delete_cwipbldavg(2, &CWIPBLDAVG);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPBLDAVG DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPBLDAVG.FACTORY), CWIPBLDAVG.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPBLDAVG.ORDER_ID), CWIPBLDAVG.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//불량 등록이 되어있으면 삭제 처리 한다. 
		DBU_init_cwiplotlst(&CWIPLOTLST);
		memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
		DBU_delete_cwiplotlst(3, &CWIPLOTLST);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTLST DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTLST.LOT_ID), CWIPLOTLST.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//기존 load된 리스트 중에 load List lot이 없으면 자재 unload처리를 해준다.        
		iStep = 4;
		DBU_init_cwipinvldm(&CWIPINVLDM);
		TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
		CWIPINVLDM.REL_LEVEL = '1';
		memcpy(CWIPINVLDM.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(CWIPINVLDM.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		memcpy(CWIPINVLDM.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

		DBU_open_cwipinvldm(iStep, &CWIPINVLDM);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
			strcpy(s_msg_code, "WIP-0585");
			TRS.add_fieldmsg(out_node, "CWIPINVLDM OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		while (1)
		{
			DBU_fetch_cwipinvldm(iStep, &CWIPINVLDM);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_cwipinvldm(iStep);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "CWIPINVLDM FATCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_cwipinvldm(iStep);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(CWIPINVLDM.LOT_TYPE, MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV)) == 0)
			{
				//unload 트랜젝션 부분 수정 할 것
				load_in = TRS.add_node(in_node, "load_in");
				TRS.add_char(load_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(load_in, in_node);

				TRS.add_char(load_in, "REL_LEVEL", '1');

				inv_list = TRS.add_node(load_in, "INV_LOT_LIST");
				TRS.add_string(inv_list, "INV_LOT_ID", CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_INV_UNLOAD_LOT_MAIN(s_msg_code, load_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}

				TRS.free_node(cmn_out);
			}
		}

		//작업지시, 공정에 LOAD된 자재 리스트를 지운다.
		DBU_init_cwipinvldm(&CWIPINVLDM);
		TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
		CWIPINVLDM.REL_LEVEL = '1';
		memcpy(CWIPINVLDM.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(CWIPINVLDM.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		memcpy(CWIPINVLDM.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

		DBU_delete_cwipinvldm(iStep, &CWIPINVLDM);
		if (DB_error_code != DB_SUCCESS)
		{
			if (DB_error_code != DB_NOT_FOUND)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPINVLDM DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CWIPINVLDM.RES_ID), CWIPINVLDM.RES_ID);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPINVLDM.LOT_ID), CWIPINVLDM.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}

	//TRAN CODE : START 경우
	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START)) == MP_FALSE)
	{
		c_CheckClassOper = 'N';

		//SATART 처리 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//설비 조회
		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));
		DBU_select_mrasresdef(1, &MRASRESDEF);

		//분류 공정 여부 
		DBU_init_mgcmtbldat(&MGCMTBLDAT_GRT);
		TRS.copy(MGCMTBLDAT_GRT.FACTORY, sizeof(MGCMTBLDAT_GRT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_GRT.TABLE_NAME, MP_GCM_GRIT_OPER, strlen(MP_GCM_GRIT_OPER));
		memcpy(MGCMTBLDAT_GRT.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_GRT);
		if (DB_error_code == DB_SUCCESS)
		{
			c_CheckClassOper = 'Y';
		}

		/*gcm의 OPER_OPTION 에 셋업된 정보를 가져온다.
			DATA_1 : 시작 트랜젝션옵션 - 시작공정의 START 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
			DATA_2 : 완료 트랜젝션옵션 - 시작공정의 END 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
			DATA_3 : 공정별 id 발번 규칙 - 공정별 ID 발번 규칙을 셋업한다.
			DATA_4 : 그룹ID 생성룰 - 그룹 ID를 발번 하고, 그룹 테이블에 INSERT 한다.
			DATA_5 : ONLY END 공정 - START 없이 END 처리만 하는 공정
			DATA_6 : 공정별 id 발번 규칙2 - 공정별 ID 발번 규칙을 셋업한다. ID rule이 두개인 경우.
			DATA_7 : split공정시 split될 자lot이 qty값.
			DATA_8 : 특정 설비 저장 공정 여부. press인 경우 lot의 save res id에 저장되도록 한다.
		*/
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_OPER_OPTION, strlen(MP_GCM_OPER_OPTION));
		memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		memcpy(MGCMTBLDAT.KEY_2, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		memcpy(MGCMTBLDAT.KEY_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

		//작업지시 실적 BACK
		//테스트품도 작업지시가 내려오기 때문에 작업지시 수량 변경 처리를 한다.
		//if (MWIPLOTSTSX.LOT_TYPE != MP_LOT_TYPE_TEST && c_CheckClassOper != 'Y')
		if (c_CheckClassOper != 'Y')
		{
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//공정별 작업지시에 START 수량을 업데이트 한다. 
			DBU_init_cwipordopr(&CWIPORDOPR);
			memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
			memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(CWIPORDOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			DBU_select_cwipordopr(1, &CWIPORDOPR);
			if (DB_error_code == DB_SUCCESS)
			{
				if (MWIPLOTSTSX.RESV_FLAG_1 == 'Y')
					CWIPORDOPR.OPER_RWK_IN_QTY = CWIPORDOPR.OPER_RWK_IN_QTY - MWIPLOTSTSX.QTY_1;
				else
					CWIPORDOPR.OPER_IN_QTY = CWIPORDOPR.OPER_IN_QTY - MWIPLOTSTSX.QTY_1;

				//공정 작업지시 시작 취소
				if (CWIPORDOPR.OPER_IN_QTY == 0)
				{
					CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
					memset(CWIPORDOPR.OPER_START_TIME, ' ', sizeof(CWIPORDOPR.OPER_START_TIME));
					memset(CWIPORDOPR.OPER_START_DATE, ' ', sizeof(CWIPORDOPR.OPER_START_DATE));
				}

				memcpy(CWIPORDOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDOPR.UPDATE_TIME));
				TRS.copy(CWIPORDOPR.UPDATE_USER_ID, sizeof(CWIPORDOPR.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_cwipordopr(1, &CWIPORDOPR);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPORDOPR UPDATE(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}
			}

			//OPER_CMF_2 = 'Y'인 경우는 start시 작지 생성 수량을 올려주기 때문.
			if (MWIPOPRDEF.OPER_CMF_2[0] == 'Y')
			{
				//시작된 작업지시는 다시 살려준다. 
				MWIPORDSTS.ORD_IN_QTY = MWIPORDSTS.ORD_IN_QTY - MWIPLOTSTSX.QTY_1;
				if (MWIPORDSTS.ORD_IN_QTY == 0)
				{
					if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_START)
					{
						//외주 공정은 START 취소가 되더라고 작업지시 상태는 OPEN상태여야 한다.
						if (memcmp(MWIPOPRDEF.OPER_GRP_1, "OSP", strlen("OSP")) != MP_FALSE)
						{
							MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
						}
					}
				}

				memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
				TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_mwipordsts(1, &MWIPORDSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				//작업지시가 대기 상태로 되면 공정별 작업지시 테이블을 지워준다.            
				if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
				{
					DBU_init_cwipordopr(&CWIPORDOPR);
					memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
					memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
					if (DBU_select_cwipordopr_scalar(2, &CWIPORDOPR) > 0)
					{
						DBU_delete_cwipordopr(2, &CWIPORDOPR);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPORDOPR DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}
		}

		// 설비 효율용 집계
		DBU_init_csumreswip(&CSUMRESWIP);
		memcpy(CSUMRESWIP.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CSUMRESWIP.LOT_ID));
		CSUMRESWIP.START_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_csumreswip(1, &CSUMRESWIP);
		if (DB_error_code == DB_SUCCESS)
		{
			DBU_delete_csumreswip(1, &CSUMRESWIP);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CSUMRESWIP DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMRESWIP.RES_ID), CSUMRESWIP.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//분류 공정인 경우
		if (c_CheckClassOper == 'Y')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
			//CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
			DBU_open_cwiplottrc(2, &CWIPLOTTRC);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "CWIPLOTTRC OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTTRC.OPER), CWIPLOTTRC.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			while (1)
			{
				DBU_fetch_cwiplottrc(2, &CWIPLOTTRC);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_cwiplottrc(2);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
					strcpy(s_msg_code, "WIP-0585");
					TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPLOTTRC.OPER), CWIPLOTTRC.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_cwiplottrc(2);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//자재lot인 경우 다시 수량을 살려준다.
				DBU_init_minvlotsts(&MINVLOTSTS);
				TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(MINVLOTSTS.INV_LOT_ID, CWIPLOTTRC.FROM_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
				DBU_select_minvlotsts(1, &MINVLOTSTS);
				if (DB_error_code == DB_SUCCESS)
				{
					if (MINVLOTSTS.DELETE_FLAG == 'Y')
					{
						MINVLOTSTS.DELETE_FLAG = ' ';
						memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
						memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
						memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
						DBU_update_minvlotsts(1, &MINVLOTSTS);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

							TRS.add_dberrmsg(out_node, DB_error_msg);
							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}

					DBU_init_minvlothis(&MINVLOTHIS);
					memcpy(MINVLOTHIS.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
					memcpy(MINVLOTHIS.INV_LOT_ID, MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
					MINVLOTHIS.HIST_SEQ = CWIPLOTTRC.FROM_LOT_HIST_SEQ;
					DBU_select_minvlothis(1, &MINVLOTHIS);

					cv_in = TRS.add_node(in_node, "cv_in");
					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(cv_in, in_node);

					inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
					TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
					TRS.add_double(inv_list, "CHANGE_QTY", MINVLOTHIS.QTY);
					TRS.add_string(inv_list, "TRAN_COMMENT", MP_DEL_TRAN_COMMENT, strlen(MP_DEL_TRAN_COMMENT));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}
			}
		}

		// Lot Summary의 END_DATE, END_TIME, END_DAY_NIGTH 보정
		DBU_init_csumlotdat(&CSUMLOTDAT);
		memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(CSUMLOTDAT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		CSUMLOTDAT.START_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_csumlotdat(1, &CSUMLOTDAT);
		if (DB_error_code == DB_SUCCESS)
		{
			DBU_delete_csumlotdat(1, &CSUMLOTDAT);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CSUMLOTDAT DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMLOTDAT.RES_ID), CSUMLOTDAT.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		//CUP - CELL 맵핑 공정인 경우 GROUP ID를 지워준다.
		if (MWIPOPRDEF.OPER_CMF_7[0] == 'Y')
		{
			//그룹 ID조회
			//첫번째 lot이 삭제될 때 그룹id를 지운다.
			DBU_init_cwipgrpsts(&CWIPGRPSTS);
			TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPGRPSTS.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPSTS.GROUP_ID));
			DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwipgrpsts(1, &CWIPGRPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPSTS DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}

				DBU_init_cwipgrplot(&CWIPGRPLOT);
				memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
				memcpy(CWIPGRPLOT.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPLOT.GROUP_ID));

				if (DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT) > 0)
				{
					DBU_delete_cwipgrplot(2, &CWIPGRPLOT);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPLOT DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}

			//MWIPLOTSTSX에 맵핑 순서 초기화.
			memset(MWIPLOTSTSX.LOT_CMF_1, ' ', sizeof(MWIPLOTSTSX.LOT_CMF_1));
			memset(MWIPLOTSTSX.LOT_CMF_2, ' ', sizeof(MWIPLOTSTSX.LOT_CMF_2));
			DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//lot history 테이블에도 맵핑 순서 초기화.
			memset(MWIPLOTHISX.LOT_CMF_1, ' ', sizeof(MWIPLOTHISX.LOT_CMF_1));
			memset(MWIPLOTHISX.LOT_CMF_2, ' ', sizeof(MWIPLOTHISX.LOT_CMF_2));
			DBU_update_mwiplothisx(1, &MWIPLOTHISX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END)) == MP_FALSE)
	{
		//END 처리 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OLD_OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ERP에 생산 이력 및 완료 이력 여부를 리턴 받아오는 함수
		check_in = TRS.add_node(in_node, "check_in");
		TRS.add_char(check_in, IN_PROCSTEP, '1');
		CopyDefaultMembers(check_in, in_node);

		TRS.add_string(check_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		TRS.add_string(check_in, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));

		cmn_out = TRS.create_node("Cmn_Out");
		if (TRANS_ERP_INFO(&c_CheckErpResult, &c_CheckErpInput, s_msg_code, check_in, cmn_out) == MP_FALSE)
		{
			TRS.clone(out_node, cmn_out);
			TRS.free_node(cmn_out);
			return MP_FALSE;
		}
		TRS.free_node(cmn_out);

		//END 처리 설비 조회
		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.END_RES_ID, sizeof(MWIPLOTHISX.END_RES_ID));
		DBU_select_mrasresdef(1, &MRASRESDEF);

		/*gcm의 OPER_OPTION 에 셋업된 정보를 가져온다.
			DATA_1 : 시작 트랜젝션옵션 - 시작공정의 START 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
			DATA_2 : 완료 트랜젝션옵션 - 시작공정의 END 트랜젝션 외에 추가 트랜젝션을 컨트롤 한다.
			DATA_3 : 공정별 id 발번 규칙 - 공정별 ID 발번 규칙을 셋업한다.
			DATA_4 : 그룹ID 생성룰 - 그룹 ID를 발번 하고, 그룹 테이블에 INSERT 한다.
			DATA_5 : ONLY END 공정 - START 없이 END 처리만 하는 공정
			DATA_6 : 공정별 id 발번 규칙2 - 공정별 ID 발번 규칙을 셋업한다. ID rule이 두개인 경우.
			DATA_7 : split공정시 split될 자lot이 qty값.
			DATA_8 : 특정 설비 저장 공정 여부. press인 경우 lot의 save res id에 저장되도록 한다.
		*/
		DBU_init_mgcmtbldat(&MGCMTBLDAT);
		TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_OPER_OPTION, strlen(MP_GCM_OPER_OPTION));
		memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
		memcpy(MGCMTBLDAT.KEY_2, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
		memcpy(MGCMTBLDAT.KEY_3, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

		//공정 옵션이 맵핑그룹 설정 이 Y인 경우 그룹번호에서 빼준다. 그룹에 0개의 lot이 되면 그룹id 삭제
		if (MGCMTBLDAT.DATA_4[0] != ' ')
		{
			DBU_init_cwipgrplot(&CWIPGRPLOT);
			memcpy(CWIPGRPLOT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
			memcpy(CWIPGRPLOT.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPLOT.GROUP_ID));
			memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			DBU_select_cwipgrplot(1, &CWIPGRPLOT);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwipgrplot(1, &CWIPGRPLOT);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPLOT DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}

			if (DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT) == 0)
			{
				DBU_init_cwipgrpsts(&CWIPGRPSTS);
				TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPGRPSTS.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPSTS.GROUP_ID));
				DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
				if (DB_error_code == DB_SUCCESS)
				{
					DBU_delete_cwipgrpsts(1, &CWIPGRPSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPGRPSTS DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}

			//MWIPLOTSTSX에 맵핑 순서 초기화.
			memset(MWIPLOTSTSX.LOT_CMF_1, ' ', sizeof(MWIPLOTSTSX.LOT_CMF_1));
			memset(MWIPLOTSTSX.LOT_CMF_2, ' ', sizeof(MWIPLOTSTSX.LOT_CMF_2));
			DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}

			//lot history 테이블에도 맵핑 순서 초기화.
			memset(MWIPLOTHISX.LOT_CMF_1, ' ', sizeof(MWIPLOTHISX.LOT_CMF_1));
			memset(MWIPLOTHISX.LOT_CMF_2, ' ', sizeof(MWIPLOTHISX.LOT_CMF_2));
			DBU_update_mwiplothisx(1, &MWIPLOTHISX);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//검사 완료를 이력삭제 하는 경우 검사 요청 ID의 상태값을 바꿔준다.
		if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
		{
			DBU_init_cqcmispsts(&CQCMISPSTS);
			memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CQCMISPSTS.FACTORY));
			memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTSX.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
			DBU_select_cqcmispsts(1, &CQCMISPSTS);
			if (DB_error_code == DB_SUCCESS)
			{

				// 절단가능품 판정으로 CWIPLOTREC 로 보낸 LOT 정보는 삭제 처리한다.
				if (CQCMISPSTS.INSP_JUDGE_FLAG == 'A')
				{
					// ERP 분기 처리 위해서 추가함.
					c_CheckEndScrapOper = 'Y';

					DBU_init_cwiplotrec(&CWIPLOTREC);
					memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTREC.FACTORY));
					memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));
					CWIPLOTREC.HIST_SEQ = MWIPLOTHISX.HIST_SEQ;
					DBU_select_cwiplotrec(3, &CWIPLOTREC);
					if (DB_error_code == DB_SUCCESS)
					{
						CWIPLOTREC.DELETE_FLAG = 'Y';
						memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));
						TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
						DBU_update_cwiplotrec(2, &CWIPLOTREC);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
							TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPLOTREC.HIST_SEQ);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}





				CQCMISPSTS.INSP_STATUS = 'R';
				//20221013 집계시 판정이 계속 걸려서..판정도 제거
				CQCMISPSTS.INSP_JUDGE_FLAG = ' ';
				memset(CQCMISPSTS.INSP_JUDGE_TIME, ' ', sizeof(CQCMISPSTS.INSP_JUDGE_TIME));

				DBU_update_cqcmispsts(1, &CQCMISPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}


			}
		}

		//cup - cell 맵핑 공정인 경우 
		if (MWIPOPRDEF.OPER_CMF_7[0] == 'Y')
		{
			DBU_init_cwipgrpsts(&CWIPGRPSTS);
			TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPGRPSTS.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPSTS.GROUP_ID));
			DBU_select_cwipgrpsts(1, &CWIPGRPSTS);
			if (DB_error_code == DB_SUCCESS)
			{
				if (memcmp(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
				{
					memset(CWIPGRPSTS.CAR, ' ', sizeof(CWIPGRPSTS.CAR));
					memset(CWIPGRPSTS.RES_ID, ' ', sizeof(CWIPGRPSTS.RES_ID));
					CWIPGRPSTS.CELL_WEIGHT = 0;
					CWIPGRPSTS.CELL_HEIGHT = 0;

					DBU_update_cwipgrpsts(1, &CWIPGRPSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPGRPSTS INSERT", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		//PRESS 설비인 경우 일별 RUN수 체크 테이블을 삭제한다.
		if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
		{
			//프레스 날짜별 COUNT 이력 삭제
			DBU_init_cwipprsrun(&CWIPPRSRUN);
			TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
			memcpy(CWIPPRSRUN.WORK_DATE, MWIPLOTHISX.TRAN_CMF_1, sizeof(CWIPPRSRUN.WORK_DATE));
			memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTHISX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
			if (DBU_select_cwipprsrun_scalar(3, &CWIPPRSRUN) > 0)
			{
				DBU_delete_cwipprsrun(2, &CWIPPRSRUN);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPPRSRUN DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
						TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		//작업지시 실적 BACK
		DBU_init_mwipordsts(&MWIPORDSTS);
		TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		DBU_select_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ORD-0002 : 이 ORDER는 존재하지 않습니다.
			strcpy(s_msg_code, "ORD-0002");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//완료 이후 공정 정보 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
		TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);

		//다음공정이 창고로 가는 경우를 마지막공정이라고 판단하여 작업지시의 out 수량 실적을 올려준다.
		if (MWIPOPRDEF_AF.INV_FLAG == 'Y')
		{
			if (MWIPLOTHISX.RESV_FLAG_1 == 'Y')
			{
				MWIPORDSTS.ORD_RWK_QTY = MWIPORDSTS.ORD_RWK_QTY - MWIPLOTSTSX.QTY_1;
			}
			else
			{
				MWIPORDSTS.ORD_OUT_QTY = MWIPORDSTS.ORD_OUT_QTY - MWIPLOTSTSX.QTY_1;
			}

			//완료된 작업지시는 다시 살려준다. 
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_CLOSE)
			{
				MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
			}

			memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
			TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//공정별 작업지시에 end 수량을 업데이트 한다. 
		DBU_init_cwipordopr(&CWIPORDOPR);
		memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		memcpy(CWIPORDOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_cwipordopr(1, &CWIPORDOPR);
		if (DB_error_code == DB_SUCCESS)
		{
			if (MWIPLOTHISX.RESV_FLAG_1 == 'Y')
			{
				CWIPORDOPR.OPER_RWK_OUT_QTY = CWIPORDOPR.OPER_RWK_OUT_QTY - MWIPLOTSTSX.QTY_1;
			}
			else
			{
				CWIPORDOPR.OPER_OUT_QTY = CWIPORDOPR.OPER_OUT_QTY - MWIPLOTSTSX.QTY_1;
			}

			//공정 작업지시 마감처리 취소
			if (CWIPORDOPR.OPER_STATUS_FLAG == MP_CWIP_ORDER_CLOSE)
			{
				CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_START;
				memset(CWIPORDOPR.OPER_END_TIME, ' ', sizeof(CWIPORDOPR.OPER_END_TIME));
				memset(CWIPORDOPR.OPER_END_DATE, ' ', sizeof(CWIPORDOPR.OPER_END_DATE));
			}

			memcpy(CWIPORDOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDOPR.UPDATE_TIME));
			TRS.copy(CWIPORDOPR.UPDATE_USER_ID, sizeof(CWIPORDOPR.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_cwipordopr(1, &CWIPORDOPR);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPORDOPR UPDATE(1) ", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//생산품인 경우만 인터페이스를 BACK처리 한다.
		if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
		{
			//실적 I/F back
			//그릿 분류 실적인 경우에는 ERP I/F가 다르다.
			DBU_init_mgcmtbldat(&MGCMTBLDAT_GRT);
			TRS.copy(MGCMTBLDAT_GRT.FACTORY, sizeof(MGCMTBLDAT_GRT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_GRT.TABLE_NAME, MP_GCM_GRIT_OPER, strlen(MP_GCM_GRIT_OPER));
			memcpy(MGCMTBLDAT_GRT.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_GRT);
			if (DB_error_code == DB_SUCCESS && memcmp(MWIPORDSTS.ORDER_DESC, "CLASS", strlen("CLASS")) == MP_FALSE)
			{
				//그릿 IF 전송 취소
				DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
				memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				memcpy(IF_COMPLETION_TRX.MES_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				IF_COMPLETION_TRX.ERP_WO_ID = atoi(MP_ERP_ORDER_ID_2);
				IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
				DBU_select_if_completion_trx(3, &IF_COMPLETION_TRX);
				if (DB_error_code == DB_SUCCESS)
				{
					if_end_in = TRS.add_node(in_node, "if_end_in");
					TRS.add_char(if_end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(if_end_in, in_node);

					TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
					TRS.add_int(if_end_in, "ERP_WO_ID", atoi(MP_ERP_ORDER_ID_2));
					TRS.add_string(if_end_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
					TRS.add_int(if_end_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
					TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
					TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN, strlen(MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN));
					TRS.add_string(if_end_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
					TRS.add_int(if_end_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
					TRS.add_string(if_end_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
					TRS.add_string(if_end_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
					TRS.add_double(if_end_in, "QTY", IF_COMPLETION_TRX.QTY);
					TRS.add_string(if_end_in, "MES_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					dHeaderSeq = TRS.get_double(cmn_out, "TRAN_HEADER_ID");

					TRS.free_node(cmn_out);
				}

				//자재 소모 IF 취소 

				DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
				memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				memcpy(IF_COMPLETION_TRX.MES_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				IF_COMPLETION_TRX.ERP_WO_ID = atoi(MP_ERP_ORDER_ID_2);
				IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_35);
				DBU_select_if_completion_trx(3, &IF_COMPLETION_TRX);
				if (DB_error_code == DB_SUCCESS)
				{
					if_end_in = TRS.add_node(in_node, "if_end_in");
					TRS.add_char(if_end_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(if_end_in, in_node);

					TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
					TRS.add_int(if_end_in, "ERP_WO_ID", atoi(MP_ERP_ORDER_ID_2));
					TRS.add_string(if_end_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
					TRS.add_int(if_end_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
					TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_43));
					TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN, strlen(MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN));
					TRS.add_string(if_end_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
					TRS.add_int(if_end_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
					TRS.add_string(if_end_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
					TRS.add_string(if_end_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
					TRS.add_double(if_end_in, "QTY", IF_COMPLETION_TRX.QTY);
					TRS.add_string(if_end_in, "MES_OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_double(if_end_in, "TRAN_HEADER_ID", dHeaderSeq);
					TRS.add_double(if_end_in, "SRC_TRAN_ID", dHeaderSeq);

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}
			}
			else
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					////MOVE IF 삭제 전송
					DBU_init_if_move_trx(&IF_MOVE_TRX);
					memcpy(IF_MOVE_TRX.MES_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					memcpy(IF_MOVE_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					memcpy(IF_MOVE_TRX.FROM_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(IF_MOVE_TRX.FROM_OPER));

					if (c_CheckEndScrapOper == 'N')
					{
						// Without Scrap
						iMoveStep = 2;
					}
					else {
						// Only Scrap
						iMoveStep = 4;
					}

					DBU_select_if_move_trx(iMoveStep, &IF_MOVE_TRX);
					if (DB_error_code == DB_SUCCESS)
					{
						if_in = TRS.add_node(in_node, "if_in");
						TRS.add_char(if_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_in, in_node);

						TRS.add_char(if_in, "TRAN_FLAG", 'I');
						TRS.add_string(if_in, "WO_ID", IF_MOVE_TRX.WO_ID, sizeof(IF_MOVE_TRX.WO_ID));
						TRS.add_int(if_in, "ERP_WO_ID", IF_MOVE_TRX.ERP_WO_ID);
						TRS.add_string(if_in, "AREA_ID", IF_MOVE_TRX.AREA_ID, sizeof(IF_MOVE_TRX.AREA_ID));
						TRS.add_int(if_in, "ERP_AREA_ID", IF_MOVE_TRX.ERP_AREA_ID);
						TRS.add_string(if_in, "FROM_OPER", IF_MOVE_TRX.TO_OPER, sizeof(IF_MOVE_TRX.TO_OPER));
						TRS.add_int(if_in, "FROM_OPER_SEQ", IF_MOVE_TRX.TO_OPER_SEQ);
						TRS.add_string(if_in, "FROM_STEP", IF_MOVE_TRX.TO_STEP, sizeof(IF_MOVE_TRX.TO_STEP));
						TRS.add_int(if_in, "FROM_STEP_TYPE", IF_MOVE_TRX.TO_STEP_TYPE);
						TRS.add_string(if_in, "TO_OPER", IF_MOVE_TRX.FROM_OPER, sizeof(IF_MOVE_TRX.FROM_OPER));
						TRS.add_string(if_in, "TO_STEP", IF_MOVE_TRX.FROM_STEP, sizeof(IF_MOVE_TRX.FROM_STEP));
						TRS.add_int(if_in, "TO_OPER_SEQ", IF_MOVE_TRX.FROM_OPER_SEQ);
						TRS.add_int(if_in, "TO_STEP_TYPE", IF_MOVE_TRX.FROM_STEP_TYPE);
						TRS.add_string(if_in, "UNIT", IF_MOVE_TRX.UNIT, sizeof(IF_MOVE_TRX.UNIT));
						TRS.add_double(if_in, "QTY", IF_MOVE_TRX.QTY);
						TRS.add_string(if_in, "OPER", IF_MOVE_TRX.MES_OPER, sizeof(IF_MOVE_TRX.MES_OPER));
						TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
						TRS.add_char(if_in, "OVER_FLAG", IF_MOVE_TRX.OVER_FLAG);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_MOVE_TRX(s_msg_code, if_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);

						if (c_CheckErpResult == 'N')
							c_CheckErpResult = 'Y';
					}
					//}
					//COMPLETION IF 삭제 전송
					DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
					memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					memcpy(IF_COMPLETION_TRX.MES_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
					memcpy(IF_COMPLETION_TRX.INV_OPER, MWIPOPRDEF_AF.OPER_CMF_1, sizeof(IF_COMPLETION_TRX.INV_OPER));
					memcpy(IF_COMPLETION_TRX.WO_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
					IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
					DBU_select_if_completion_trx(2, &IF_COMPLETION_TRX);
					if (DB_error_code == DB_SUCCESS)
					{
						if_end_in = TRS.add_node(in_node, "if_end_in");
						TRS.add_char(if_end_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_end_in, in_node);

						TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
						TRS.add_string(if_end_in, "WO_ID", IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID));
						TRS.add_int(if_end_in, "ERP_WO_ID", IF_COMPLETION_TRX.ERP_WO_ID);
						TRS.add_string(if_end_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
						TRS.add_int(if_end_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
						TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
						TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
						TRS.add_string(if_end_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
						TRS.add_int(if_end_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
						TRS.add_string(if_end_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
						TRS.add_string(if_end_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
						TRS.add_double(if_end_in, "QTY", IF_COMPLETION_TRX.QTY);
						TRS.add_string(if_end_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
						TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);
					}
				}
			}
		}

		//작업자 실적 삭제 
		DBU_init_cwipoprwrk(&CWIPOPRWRK);
		memcpy(CWIPOPRWRK.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPOPRWRK.FACTORY));
		memcpy(CWIPOPRWRK.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPOPRWRK.LOT_ID));
		memcpy(CWIPOPRWRK.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		CWIPOPRWRK.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		if (DBU_select_cwipoprwrk_scalar(2, &CWIPOPRWRK) > 0)
		{
			DBU_delete_cwipoprwrk(2, &CWIPOPRWRK);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code != DB_NOT_FOUND)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPOPRWRK DELETE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPOPRWRK.FACTORY), CWIPOPRWRK.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPOPRWRK.LOT_ID), CWIPOPRWRK.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPOPRWRK.OPER), CWIPOPRWRK.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		//외주인경우
		if (memcmp(MWIPOPRDEF.OPER_GRP_1, "OSP", strlen("OSP")) == MP_FALSE)
		{
			DBU_init_minvdlvdtl(&MINVDLVDTL);
			TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
			MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
			DBU_select_minvdlvdtl(102, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 구매 입고 마스터 정보 조회
			DBU_init_minvdlvmst(&MINVDLVMST);
			TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
			DBU_select_minvdlvmst(1, &MINVDLVMST);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//입고된 수량만큼 PO 정보에 입고 수량을 업데이트 해준다.
			MINVDLVDTL.DLV_IN_QTY = MINVDLVDTL.DLV_IN_QTY - MWIPLOTSTSX.QTY_1;
			MINVDLVDTL.CONFIRM_QTY = MINVDLVDTL.CONFIRM_QTY - MWIPLOTSTSX.QTY_1;

			MINVDLVDTL.DELETE_FLAG = ' ';
			memcpy(MINVDLVDTL.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.UPDATE_TIME));
			TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);

			DBU_update_minvdlvdtl(1, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
				TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}



		DBU_init_minvlotiss(&MINVLOTISS);
		memcpy(MINVLOTISS.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
		memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
		memcpy(MINVLOTISS.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MINVLOTISS.ERP_OPER));
		memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		DBU_open_minvlotiss(4, &MINVLOTISS);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
			strcpy(s_msg_code, "WIP-0585");
			TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
			TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
			TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
		while (1)
		{

			DBU_fetch_minvlotiss(4, &MINVLOTISS);
			if (DB_error_code == DB_NOT_FOUND)
			{
				DBU_close_minvlotiss(4);
				break;
			}
			else if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, 4);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
				TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				DBU_close_minvlotiss(4);
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//자재투입 취소처리를 해준다.<서비스 호출로 변경함>(20240311) 
			//자재 투입 취소 서비스 호출로
			iss_in = TRS.add_node(in_node, "mat_in");
			TRS.add_char(iss_in, IN_PROCSTEP, '6');
			CopyDefaultMembers(iss_in, in_node);


			TRS.add_string(iss_in, "AREA_ID", MINVLOTISS.AREA_ID, sizeof(MINVLOTISS.AREA_ID));
			TRS.add_string(iss_in, "SUB_AREA_ID", MINVLOTISS.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID));
			TRS.add_string(iss_in, "OPER", MINVLOTISS.OPER, sizeof(MINVLOTISS.OPER));
			TRS.add_string(iss_in, "ORDER_ID", MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));



			iss_list = TRS.add_node(iss_in, "LIST_TBL");
			TRS.add_string(iss_list, "OPER_LOT_ID", MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
			TRS.add_string(iss_list, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
			TRS.add_string(iss_list, "MAT_ID", MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
			TRS.add_double(iss_list, "QTY", MINVLOTISS.TRAN_QTY);
			TRS.add_int(iss_list, "HIST_SEQ", MINVLOTISS.HIST_SEQ);
			TRS.add_string(iss_list, "OUT_OPER", MINVLOTISS.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER));



			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, iss_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);
		}





		//자재투입 로직
		/*
		//LOT이 생산품일 경우
		if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
		{
			//컵계량 공정인 경우 첫공정이어도 무조건 자재 사용을 올려준다.
			//컵계량 공정에서 end 이후 바로 split되어 다음 lot으로 자재 소모를 올려줄 수 없기 때문
			// => 컵계량 공정인 경우 c_CheckErpResult = 'Y'; 넣는 로직 확인 할 것.
			if (memcmp(MGCMTBLDAT.DATA_1, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE)) == MP_FALSE)
			{
				if (memcmp(MGCMTBLDAT.DATA_2, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
				{
					if (memcmp(MGCMTBLDAT.DATA_4, MP_ID_ROLE_WIP_CUP_GROUP_ID, strlen(MP_ID_ROLE_WIP_CUP_GROUP_ID)) == MP_FALSE)
					{
						if (c_CheckErpResult == 'N')
							c_CheckErpResult = 'Y';
					}
				}
			}



			//자재 차감 BACK로직 => 보완 필요.
			DBU_init_minvlotiss(&MINVLOTISS);
			memcpy(MINVLOTISS.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
			memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(MINVLOTISS.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MINVLOTISS.ERP_OPER));
			memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			DBU_open_minvlotiss(4, &MINVLOTISS);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
				TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			while (1)
			{
				DBU_fetch_minvlotiss(4, &MINVLOTISS);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_minvlotiss(4);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
					strcpy(s_msg_code, "WIP-0585");
					TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 4);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
					TRS.add_fieldmsg(out_node, "ERP_OPER", MP_STR, sizeof(MINVLOTISS.ERP_OPER), MINVLOTISS.ERP_OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_minvlotiss(4);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}




				//외경가공, 작업지시공정인 경우 자기 자신이 투입처리만 올라가는 것이기 때문에 CV처리를 하지 않는다.
				if (memcmp(MINVLOTISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)) == MP_FALSE
					&& MWIPOPRDEF.OPER_CMF_2[0] == 'Y') {
					if (c_CheckErpResult == 'N')
						c_CheckErpResult = 'Y';

				}

				////자재 소비 IF 삭제 전송
				if (c_CheckErpResult == 'Y')
				{
					DBU_init_if_comp_issue_trx(&IF_COMP_ISSUE_TRX);
					IF_COMP_ISSUE_TRX.IF_SEQ = (double)atol(MINVLOTISS.CMF_3);
					DBU_select_if_comp_issue_trx(1, &IF_COMP_ISSUE_TRX);

					if (DB_error_code == DB_SUCCESS)
					{
						inv_if = TRS.add_node(in_node, "inv_if");
						TRS.add_char(inv_if, IN_PROCSTEP, '1');
						CopyDefaultMembers(inv_if, in_node);

						TRS.add_char(inv_if, "TRAN_FLAG", 'I');
						TRS.add_string(inv_if, "WO_ID", IF_COMP_ISSUE_TRX.WO_ID, sizeof(IF_COMP_ISSUE_TRX.WO_ID));
						TRS.add_int(inv_if, "ERP_WO_ID", IF_COMP_ISSUE_TRX.ERP_WO_ID);
						TRS.add_int(inv_if, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_43));
						TRS.add_string(inv_if, "AREA_ID", IF_COMP_ISSUE_TRX.AREA_ID, sizeof(IF_COMP_ISSUE_TRX.AREA_ID));
						TRS.add_int(inv_if, "ERP_AREA_ID", IF_COMP_ISSUE_TRX.ERP_AREA_ID);
						TRS.add_string(inv_if, "SUB_AREA_ID", IF_COMP_ISSUE_TRX.SUB_AREA_ID, sizeof(IF_COMP_ISSUE_TRX.SUB_AREA_ID));
						TRS.add_int(inv_if, "ERP_SUB_AREA_ID", IF_COMP_ISSUE_TRX.ERP_SUB_AREA_ID);
						TRS.add_int(inv_if, "OPER_SEQ", IF_COMP_ISSUE_TRX.OPER_SEQ);
						TRS.add_string(inv_if, "OPER", IF_COMP_ISSUE_TRX.OPER, sizeof(IF_COMP_ISSUE_TRX.OPER));
						TRS.add_string(inv_if, "INV_OPER", IF_COMP_ISSUE_TRX.INV_OPER, sizeof(IF_COMP_ISSUE_TRX.INV_OPER));
						TRS.add_int(inv_if, "ERP_MAT_ID", IF_COMP_ISSUE_TRX.ERP_MAT_ID);
						TRS.add_string(inv_if, "MAT_ID", IF_COMP_ISSUE_TRX.MAT_ID, sizeof(IF_COMP_ISSUE_TRX.MAT_ID));
						TRS.add_string(inv_if, "UNIT", IF_COMP_ISSUE_TRX.UNIT, sizeof(IF_COMP_ISSUE_TRX.UNIT));
						TRS.add_double(inv_if, "QTY", -1 * IF_COMP_ISSUE_TRX.QTY);
						TRS.add_string(inv_if, "CMF_1", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMP_ISSUE_TRX(s_msg_code, inv_if, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}


						TRS.free_node(cmn_out);
					}
				}

				DBU_init_minvlotiss(&MINVLOTISS_EA);
				memcpy(MINVLOTISS_EA.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
				memcpy(MINVLOTISS_EA.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(MINVLOTISS_EA.OPER, MWIPOPRDEF.OPER, sizeof(MINVLOTISS_EA.OPER));
				memcpy(MINVLOTISS_EA.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				memcpy(MINVLOTISS_EA.MAT_ID, MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
				DBU_open_minvlotiss(3, &MINVLOTISS_EA);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
					strcpy(s_msg_code, "WIP-0585");
					TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS_EA.FACTORY), MINVLOTISS_EA.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS_EA.ORDER_ID), MINVLOTISS_EA.ORDER_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS_EA.OPER), MINVLOTISS_EA.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS_EA.LOT_ID), MINVLOTISS_EA.LOT_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS_EA.MAT_ID), MINVLOTISS_EA.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
				while (1)
				{
					DBU_fetch_minvlotiss(3, &MINVLOTISS_EA);
					if (DB_error_code == DB_NOT_FOUND)
					{
						DBU_close_minvlotiss(3);
						break;
					}
					else if (DB_error_code != DB_SUCCESS)
					{
						//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
						strcpy(s_msg_code, "WIP-0585");
						TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
						TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS_EA.FACTORY), MINVLOTISS_EA.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS_EA.ORDER_ID), MINVLOTISS_EA.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS_EA.OPER), MINVLOTISS_EA.OPER);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS_EA.LOT_ID), MINVLOTISS_EA.LOT_ID);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS_EA.MAT_ID), MINVLOTISS_EA.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						DBU_close_minvlotiss(3);
						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//실제 자재 lot을 찾아서 수량을 보정해주는 로직 추가.
					DBU_init_mwiplotstsx(&MWIPLOTSTSX_LAD);
					memcpy(MWIPLOTSTSX_LAD.LOT_ID, MINVLOTISS_EA.INV_LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
					DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LAD);
					//자재가 wip lot인 경우
					if (DB_error_code == DB_SUCCESS)
					{
						DBU_init_cwiplottrc(&CWIPLOTTRC);
						memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
						memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
						memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
						memcpy(CWIPLOTTRC.FROM_LOT_ID, MINVLOTISS_EA.INV_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
						DBU_select_cwiplottrc(4, &CWIPLOTTRC);
						if (DB_error_code == DB_SUCCESS)
						{
							DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
							if (DB_error_code != DB_SUCCESS)
							{
								if (DB_error_code != DB_NOT_FOUND)
								{
									//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
									strcpy(s_msg_code, "ADM-0004");
									TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
									TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
									TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}
							}
						}

						if (MWIPLOTSTSX_LAD.LOT_DEL_FLAG == 'Y')
						{
							MWIPLOTSTSX_LAD.LOT_DEL_FLAG = ' ';
							memset(MWIPLOTSTSX_LAD.LOT_DEL_CODE, ' ', sizeof(MWIPLOTSTSX_LAD.LOT_DEL_CODE));
							memset(MWIPLOTSTSX_LAD.LOT_DEL_TIME, ' ', sizeof(MWIPLOTSTSX_LAD.LOT_DEL_TIME));
							DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_LAD);
							if (DB_error_code != DB_SUCCESS)
							{
								memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_LAD.LOT_ID), MWIPLOTSTSX_LAD.LOT_ID);

								return MP_FALSE;
							}

							DBU_init_mwiplothisx(&MWIPLOTHISX_LAD);
							memcpy(MWIPLOTHISX_LAD.LOT_ID, MWIPLOTSTSX_LAD.LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
							MWIPLOTHISX_LAD.HIST_SEQ = MWIPLOTSTSX_LAD.LAST_ACTIVE_HIST_SEQ;
							DBU_select_mwiplothisx(1, &MWIPLOTHISX_LAD);

							MWIPLOTHISX_LAD.LOT_DEL_FLAG = ' ';
							memset(MWIPLOTHISX_LAD.LOT_DEL_CODE, ' ', sizeof(MWIPLOTHISX_LAD.LOT_DEL_CODE));
							memset(MWIPLOTHISX_LAD.LOT_DEL_TIME, ' ', sizeof(MWIPLOTHISX_LAD.LOT_DEL_TIME));
							DBU_update_mwiplothisx(1, &MWIPLOTHISX_LAD);
							if (DB_error_code != DB_SUCCESS)
							{
								memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX_LAD.LOT_ID), MWIPLOTHISX_LAD.LOT_ID);

								return MP_FALSE;
							}
						}



						//외경가공, 작업지시공정인 경우 자기 자신이 투입처리만 올라가는 것이기 때문에 CV처리를 하지 않는다. 20220914 추가
						if (memcmp(MINVLOTISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)) == MP_FALSE
							&& MWIPOPRDEF.OPER_CMF_2[0] == 'Y')
						{
						}
						else
						{

						cv_in = TRS.add_node(in_node, "cv_in");
						TRS.add_char(cv_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(cv_in, in_node);

						TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_LAD.LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
						TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_LAD.MAT_ID, sizeof(MWIPLOTSTSX_LAD.MAT_ID));
						TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_LAD.OPER, sizeof(MWIPLOTSTSX_LAD.OPER));
						TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_LAD.FLOW, sizeof(MWIPLOTSTSX_LAD.FLOW));
						TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
						//TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
						TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_LAD.QTY_1 + MINVLOTISS_EA.TRAN_QTY);
						TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						}
					}

					//자재가 inv lot인 경우
					DBU_init_minvlotsts(&MINVLOTSTS);
					memcpy(MINVLOTSTS.FACTORY, MINVLOTISS_EA.FACTORY, sizeof(MINVLOTISS_EA.FACTORY));
					memcpy(MINVLOTSTS.INV_LOT_ID, MINVLOTISS_EA.INV_LOT_ID, sizeof(MINVLOTISS_EA.INV_LOT_ID));
					DBU_select_minvlotsts(1, &MINVLOTSTS);
					if (DB_error_code == DB_SUCCESS)
					{
						if (MINVLOTSTS.DELETE_FLAG == 'Y')
						{
							MINVLOTSTS.DELETE_FLAG = ' ';
							memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
							memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
							memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
							DBU_update_minvlotsts(1, &MINVLOTSTS);
							if (DB_error_code != DB_SUCCESS)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
								TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

								TRS.add_dberrmsg(out_node, DB_error_msg);
								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}

						cv_in = TRS.add_node(in_node, "cv_in");
						TRS.add_char(cv_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(cv_in, in_node);

						inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
						TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
						TRS.add_double(inv_list, "CHANGE_QTY", MINVLOTSTS.QTY + MINVLOTISS_EA.TRAN_QTY);
						TRS.add_string(inv_list, "TRAN_COMMENT", MP_DEL_TRAN_COMMENT, strlen(MP_DEL_TRAN_COMMENT));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}

					//MINVLOTISS_EA.HIST_DEL_FLAG = 'Y';
					DBU_delete_minvlotiss(1, &MINVLOTISS_EA);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "MINVLOTISS_EA UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS_EA.FACTORY), MINVLOTISS_EA.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS_EA.ORDER_ID), MINVLOTISS_EA.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS_EA.OPER), MINVLOTISS_EA.OPER);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS_EA.LOT_ID), MINVLOTISS_EA.LOT_ID);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS_EA.MAT_ID), MINVLOTISS_EA.MAT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
		//LOT이 테스트 품인 경우 기타 입고처리를 한다.
		else if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_TEST)
		{
			//ETC IN 한글명 가져옴
			DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
			TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
			memcpy(MGCMTBLDAT_SRC.KEY_1, "ETC_IN", strlen("ETC_IN"));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
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
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
				TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
				TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvlotiss(&MINVLOTISS);
			memcpy(MINVLOTISS.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
			memcpy(MINVLOTISS.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			memcpy(MINVLOTISS.OPER, MWIPOPRDEF.OPER, sizeof(MINVLOTISS.OPER));
			memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			DBU_open_minvlotiss(5, &MINVLOTISS);
			if (DB_error_code != DB_SUCCESS)
			{
				//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
				strcpy(s_msg_code, "WIP-0585");
				TRS.add_fieldmsg(out_node, "MINVLOTISS OPEN", MP_NVST);
				TRS.add_fieldmsg(out_node, "step", MP_INT, 3);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS.MAT_ID), MINVLOTISS.MAT_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			while (1)
			{
				DBU_fetch_minvlotiss(5, &MINVLOTISS);
				if (DB_error_code == DB_NOT_FOUND)
				{
					DBU_close_minvlotiss(5);
					break;
				}
				else if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
					strcpy(s_msg_code, "WIP-0585");
					TRS.add_fieldmsg(out_node, "MINVLOTISS FATCH", MP_NVST);
					TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS.MAT_ID), MINVLOTISS.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					DBU_close_minvlotiss(5);
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (MINVLOTISS.CMF_3[0] != ' ')
				{
					DBU_init_if_inv_txns(&IF_INV_TXNS);
					IF_INV_TXNS.IF_SEQ = (double)atol(MINVLOTISS.CMF_3);
					DBU_select_if_inv_txns(1, &IF_INV_TXNS);
					if (DB_error_code == DB_SUCCESS)
					{
						DBU_init_cbastxndef(&CBASTXNDEF);
						TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
						CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
						CBASTXNDEF.ERP_AREA_ID = IF_INV_TXNS.ERP_AREA_ID;
						DBU_select_cbastxndef(2, &CBASTXNDEF);

						if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
							TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
							TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						if (DB_error_code == DB_NOT_FOUND)
						{
							//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
							//MST(ERP AREA ID : 103)
							//임시로 하드코딩
							DBU_init_cbastxndef(&CBASTXNDEF);
							TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
							CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_40);
							CBASTXNDEF.ERP_AREA_ID = 103;
							DBU_select_cbastxndef(2, &CBASTXNDEF);

							if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
							{
								strcpy(s_msg_code, "WIP-0004");
								TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
								TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
								TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}

						//기타입고 계정 가져온다.
						//현재 LOT의 CREATE CODE를 가져와야 하기 때문에 LOT조회 바로 뒤에 있어야 함
						DBU_init_mgcmtbldat(&MGCMTBLDAT_TYPE);
						TRS.copy(MGCMTBLDAT_TYPE.FACTORY, sizeof(MGCMTBLDAT_TYPE.FACTORY), in_node, IN_FACTORY);
						memcpy(MGCMTBLDAT_TYPE.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
						memcpy(MGCMTBLDAT_TYPE.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
						DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TYPE);
						if (DB_error_code != DB_SUCCESS)
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TYPE.FACTORY), MGCMTBLDAT_TYPE.FACTORY);
							TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_TYPE.TABLE_NAME), MGCMTBLDAT_TYPE.TABLE_NAME);
							TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_TYPE.KEY_1), MGCMTBLDAT_TYPE.KEY_1);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						//기타입고 계정코드
						DBU_init_cbastxndef(&CBASTXNDEF_ETC);
						TRS.copy(CBASTXNDEF_ETC.FACTORY, sizeof(CBASTXNDEF_ETC.FACTORY), in_node, IN_FACTORY);
						CBASTXNDEF_ETC.ERP_AREA_ID = IF_INV_TXNS.ERP_AREA_ID;
						CBASTXNDEF_ETC.TRAN_TYPE_ID = COM_atoi(MGCMTBLDAT_TYPE.DATA_5, sizeof(MGCMTBLDAT_TYPE.DATA_5));

						DBU_select_cbastxndef(2, &CBASTXNDEF_ETC);
						if (DB_error_code != DB_SUCCESS || MGCMTBLDAT_TYPE.DATA_5[0] == ' ')
						{
							strcpy(s_msg_code, "WIP-0004");
							TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF_ETC.FACTORY), CBASTXNDEF_ETC.FACTORY);
							TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF_ETC.TRAN_TYPE_ID);
							TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF_ETC.ERP_AREA_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}

						inv_if = TRS.add_node(in_node, "inv_if");
						TRS.add_char(inv_if, IN_PROCSTEP, '1');
						CopyDefaultMembers(inv_if, in_node);

						TRS.add_char(inv_if, "TRAN_FLAG", 'I');
						TRS.add_int(inv_if, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
						TRS.add_string(inv_if, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
						TRS.add_int(inv_if, "TRAN_SRC_ID", CBASTXNDEF_ETC.TRAN_SRC_ID);
						TRS.add_string(inv_if, "TRAN_SRC_NAME", CBASTXNDEF_ETC.TRAN_TYPE_NAME, sizeof(CBASTXNDEF_ETC.TRAN_TYPE_NAME));
						TRS.add_int(inv_if, "ERP_AREA_ID", IF_INV_TXNS.ERP_AREA_ID);
						TRS.add_string(inv_if, "AREA_ID", IF_INV_TXNS.AREA_ID, sizeof(IF_INV_TXNS.AREA_ID));
						TRS.add_int(inv_if, "ERP_MAT_ID", IF_INV_TXNS.ERP_MAT_ID);
						TRS.add_string(inv_if, "MAT_ID", IF_INV_TXNS.MAT_ID, sizeof(IF_INV_TXNS.MAT_ID));
						TRS.add_string(inv_if, "FROM_OPER", IF_INV_TXNS.FROM_OPER, sizeof(IF_INV_TXNS.FROM_OPER));
						TRS.add_string(inv_if, "UNIT", IF_INV_TXNS.UNIT, sizeof(IF_INV_TXNS.UNIT));
						TRS.add_double(inv_if, "QTY", -1 * IF_INV_TXNS.QTY);
						TRS.add_string(inv_if, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
						TRS.add_string(inv_if, "MES_ID", IF_INV_TXNS.MES_ID, sizeof(IF_INV_TXNS.MES_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_INV_TXNS(s_msg_code, inv_if, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);

						DBU_init_if_inv_txns(&IF_INV_TXNS_S);
						TRS.copy(IF_INV_TXNS_S.FACTORY, sizeof(IF_INV_TXNS_S.FACTORY), in_node, IN_FACTORY);
						memcpy(IF_INV_TXNS_S.MES_ID, IF_INV_TXNS.MES_ID, sizeof(IF_INV_TXNS.MES_ID));

						//ERP 실적 - IF_INV_TXN_LOTS
						erpif_in = TRS.add_node(in_node, "erpif_in");
						TRS.add_char(erpif_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(erpif_in, in_node);

						TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
						TRS.add_double(erpif_in, "INV_TXNS_ID", (double)DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS_S));
						TRS.add_int(erpif_in, "ERP_MAT_ID", IF_INV_TXNS.ERP_MAT_ID);
						TRS.add_string(erpif_in, "MAT_ID", IF_INV_TXNS.MAT_ID, sizeof(IF_INV_TXNS.MAT_ID));
						TRS.add_string(erpif_in, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
						TRS.add_string(erpif_in, "MES_ID", IF_INV_TXNS.MES_ID, sizeof(IF_INV_TXNS.MES_ID)); //추후 이동지시번호가 들어올예정
						TRS.add_double(erpif_in, "QTY", -1 * IF_INV_TXNS.QTY);

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
						TRS.free_node(cmn_out);
					}
				}

				//실제 자재 lot을 찾아서 수량을 보정해주는 로직 추가.
				DBU_init_mwiplotstsx(&MWIPLOTSTSX_LAD);
				memcpy(MWIPLOTSTSX_LAD.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
				DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_LAD);
				//자재가 wip lot인 경우
				if (DB_error_code == DB_SUCCESS)
				{
					DBU_init_cwiplottrc(&CWIPLOTTRC);
					memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
					memcpy(CWIPLOTTRC.OPER, MWIPOPRDEF.OPER, sizeof(CWIPLOTTRC.OPER));
					memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
					memcpy(CWIPLOTTRC.FROM_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
					DBU_select_cwiplottrc(4, &CWIPLOTTRC);
					if (DB_error_code == DB_SUCCESS)
					{
						DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
						if (DB_error_code != DB_SUCCESS)
						{
							if (DB_error_code != DB_NOT_FOUND)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}
					}

					if (MWIPLOTSTSX_LAD.LOT_DEL_FLAG == 'Y')
					{
						MWIPLOTSTSX_LAD.LOT_DEL_FLAG = ' ';
						memset(MWIPLOTSTSX_LAD.LOT_DEL_CODE, ' ', sizeof(MWIPLOTSTSX_LAD.LOT_DEL_CODE));
						memset(MWIPLOTSTSX_LAD.LOT_DEL_TIME, ' ', sizeof(MWIPLOTSTSX_LAD.LOT_DEL_TIME));
						DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_LAD);
						if (DB_error_code != DB_SUCCESS)
						{
							memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_LAD.LOT_ID), MWIPLOTSTSX_LAD.LOT_ID);

							return MP_FALSE;
						}

						DBU_init_mwiplothisx(&MWIPLOTHISX_LAD);
						memcpy(MWIPLOTHISX_LAD.LOT_ID, MWIPLOTSTSX_LAD.LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
						MWIPLOTHISX_LAD.HIST_SEQ = MWIPLOTSTSX_LAD.LAST_ACTIVE_HIST_SEQ;
						DBU_select_mwiplothisx(1, &MWIPLOTHISX_LAD);

						MWIPLOTHISX_LAD.LOT_DEL_FLAG = ' ';
						memset(MWIPLOTHISX_LAD.LOT_DEL_CODE, ' ', sizeof(MWIPLOTHISX_LAD.LOT_DEL_CODE));
						memset(MWIPLOTHISX_LAD.LOT_DEL_TIME, ' ', sizeof(MWIPLOTHISX_LAD.LOT_DEL_TIME));
						DBU_update_mwiplothisx(1, &MWIPLOTHISX_LAD);
						if (DB_error_code != DB_SUCCESS)
						{
							memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
							TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX_LAD.LOT_ID), MWIPLOTHISX_LAD.LOT_ID);

							return MP_FALSE;
						}
					}

					//외경가공, 작업지시공정인 경우 자기 자신이 투입처리만 올라가는 것이기 때문에 CV처리를 하지 않는다.
					if (memcmp(MINVLOTISS.LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID)) == MP_FALSE
						&& MWIPOPRDEF.OPER_CMF_2[0] == 'Y')
					{
					}
					else
					{
						cv_in = TRS.add_node(in_node, "cv_in");
						TRS.add_char(cv_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(cv_in, in_node);

						TRS.add_string(cv_in, "LOT_ID", MWIPLOTSTSX_LAD.LOT_ID, sizeof(MWIPLOTSTSX_LAD.LOT_ID));
						TRS.add_string(cv_in, "MAT_ID", MWIPLOTSTSX_LAD.MAT_ID, sizeof(MWIPLOTSTSX_LAD.MAT_ID));
						TRS.add_string(cv_in, "OPER", MWIPLOTSTSX_LAD.OPER, sizeof(MWIPLOTSTSX_LAD.OPER));
						TRS.add_string(cv_in, "FLOW", MWIPLOTSTSX_LAD.FLOW, sizeof(MWIPLOTSTSX_LAD.FLOW));
						TRS.add_nstring(cv_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
						//TRS.add_nstring(cv_in, "COMMENT", TRS.get_string(in_node, "COMMENT"));
						TRS.add_double(cv_in, "QTY_1", MWIPLOTSTSX_LAD.QTY_1 + MINVLOTISS.TRAN_QTY);
						TRS.add_string(cv_in, "CODE", MP_CV_CODE_INPUT_INV, strlen(MP_CV_CODE_INPUT_INV));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_WIP_CV_LOT(s_msg_code, cv_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}
					}
				}

				//자재가 inv lot인 경우
				DBU_init_minvlotsts(&MINVLOTSTS);
				memcpy(MINVLOTSTS.FACTORY, MINVLOTISS.FACTORY, sizeof(MINVLOTISS.FACTORY));
				memcpy(MINVLOTSTS.INV_LOT_ID, MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
				DBU_select_minvlotsts(1, &MINVLOTSTS);
				if (DB_error_code == DB_SUCCESS)
				{
					if (MINVLOTSTS.DELETE_FLAG == 'Y')
					{
						MINVLOTSTS.DELETE_FLAG = ' ';
						memset(MINVLOTSTS.DELETE_CODE, ' ', sizeof(MINVLOTSTS.DELETE_CODE));
						memset(MINVLOTSTS.DELETE_TIME, ' ', sizeof(MINVLOTSTS.DELETE_TIME));
						memset(MINVLOTSTS.DELETE_USER_ID, ' ', sizeof(MINVLOTSTS.DELETE_USER_ID));
						DBU_update_minvlotsts(1, &MINVLOTSTS);
						if (DB_error_code != DB_SUCCESS)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "MINVLOTSTS UPDATE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
							TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);

							TRS.add_dberrmsg(out_node, DB_error_msg);
							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}

					cv_in = TRS.add_node(in_node, "cv_in");
					TRS.add_char(cv_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(cv_in, in_node);

					inv_list = TRS.add_node(cv_in, "INV_LOT_LIST");
					TRS.add_string(inv_list, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
					TRS.add_double(inv_list, "CHANGE_QTY", MINVLOTSTS.QTY + MINVLOTISS.TRAN_QTY);
					TRS.add_string(inv_list, "TRAN_COMMENT", MP_DEL_TRAN_COMMENT, strlen(MP_DEL_TRAN_COMMENT));

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_INV_CV_LOT_MAIN(s_msg_code, cv_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}
					TRS.free_node(cmn_out);
				}

				//MINVLOTISS.HIST_DEL_FLAG = 'Y';
				DBU_delete_minvlotiss(1, &MINVLOTISS);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MINVLOTISS UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTISS.MAT_ID), MINVLOTISS.MAT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}











			}
		}
		*/


		// 설비 효율용 집계
		DBU_init_csumreswip(&CSUMRESWIP);
		memcpy(CSUMRESWIP.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CSUMRESWIP.LOT_ID));
		memcpy(CSUMRESWIP.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(CSUMRESWIP.RES_ID, MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID));
		CSUMRESWIP.END_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_csumreswip(2, &CSUMRESWIP);
		if (DB_error_code == DB_SUCCESS)
		{
			memset(CSUMRESWIP.END_DATE, ' ', sizeof(CSUMRESWIP.END_DATE));
			memset(CSUMRESWIP.END_TIME, ' ', sizeof(CSUMRESWIP.END_TIME));
			memset(CSUMRESWIP.END_DAY_NIGHT, ' ', sizeof(CSUMRESWIP.END_DAY_NIGHT));
			CSUMRESWIP.END_HIST_SEQ = 0;
			//CSUMRESWIP.IN_QTY = 0;
			CSUMRESWIP.OUT_QTY = 0;
			memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));
			TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_csumreswip(1, &CSUMRESWIP);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CSUMRESWIP UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMRESWIP.RES_ID), CSUMRESWIP.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		// Lot Summary의 END_DATE, END_TIME, END_DAY_NIGTH 보정
		DBU_init_csumlotdat(&CSUMLOTDAT);
		memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(CSUMLOTDAT.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		CSUMLOTDAT.END_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		DBU_select_csumlotdat(2, &CSUMLOTDAT);
		if (DB_error_code == DB_SUCCESS)
		{
			//검사 완료를 이력삭제 하는 경우 검사 요청 ID의 상태값을 바꿔준다.
			if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
			{
				DBU_delete_csumlotdat(1, &CSUMLOTDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CSUMLOTDAT DELETE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMLOTDAT.RES_ID), CSUMLOTDAT.RES_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				memset(CSUMLOTDAT.END_DATE, ' ', sizeof(CSUMLOTDAT.END_DATE));
				memset(CSUMLOTDAT.END_TIME, ' ', sizeof(CSUMLOTDAT.END_TIME));
				memset(CSUMLOTDAT.END_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.END_DAY_NIGHT));
				CSUMLOTDAT.END_HIST_SEQ = 0;
				CSUMLOTDAT.OUT_QTY = 0;
				memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));
				TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_csumlotdat(1, &CSUMLOTDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CSUMLOTDAT UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMLOTDAT.RES_ID), CSUMLOTDAT.RES_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_LOSS, strlen(MP_TRAN_CODE_LOSS)) == MP_FALSE)
	{
		//불량 정보 조회
		DBC_init_mwiplotlos(&MWIPLOTLOS);
		memcpy(MWIPLOTLOS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		MWIPLOTLOS.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		MWIPLOTLOS.QTY_FLAG = '1';
		DBC_select_mwiplotlos(1, &MWIPLOTLOS);

		//공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);

		//외주인경우
		if (memcmp(MWIPOPRDEF.OPER_GRP_1, "OSP", strlen("OSP")) == MP_FALSE)
		{
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_minvdlvdtl(&MINVDLVDTL);
			TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
			MINVDLVDTL.PO_DISTRIBUTION_ID = atoi(MWIPORDSTS.ORD_CMF_4);
			DBU_select_minvdlvdtl(102, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVDTL SELECT(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVDTL.FACTORY), MINVDLVDTL.FACTORY);
				TRS.add_fieldmsg(out_node, "PO_DISTRIBUTION_ID", MP_INT, MINVDLVDTL.PO_DISTRIBUTION_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			// 구매 입고 마스터 정보 조회
			DBU_init_minvdlvmst(&MINVDLVMST);
			TRS.copy(MINVDLVMST.FACTORY, sizeof(MINVDLVMST.FACTORY), in_node, IN_FACTORY);
			memcpy(MINVDLVMST.DLV_NO, MINVDLVDTL.DLV_NO, sizeof(MINVDLVMST.DLV_NO));
			DBU_select_minvdlvmst(1, &MINVDLVMST);
			if (DB_error_code != DB_SUCCESS)
			{
				strcpy(s_msg_code, "INV-0004");
				TRS.add_fieldmsg(out_node, "MINVDLVMST SELECT(2)", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVMST.FACTORY), MINVDLVMST.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_NO", MP_STR, sizeof(MINVDLVMST.DLV_NO), MINVDLVMST.DLV_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_TRANS;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				return MP_FALSE;
			}

			//입고된 수량만큼 PO 정보에 입고 수량을 업데이트 해준다.
			MINVDLVDTL.DLV_IN_QTY = MINVDLVDTL.DLV_IN_QTY - MWIPLOTLOS.TOTAL_LOSS_QTY;
			MINVDLVDTL.LOSS_QTY = MINVDLVDTL.LOSS_QTY - MWIPLOTLOS.TOTAL_LOSS_QTY;

			MINVDLVDTL.DELETE_FLAG = ' ';
			memcpy(MINVDLVDTL.UPDATE_TIME, gs_sys_time, sizeof(MINVDLVDTL.UPDATE_TIME));
			TRS.copy(MINVDLVDTL.UPDATE_USER_ID, sizeof(MINVDLVDTL.UPDATE_USER_ID), in_node, IN_USERID);

			DBU_update_minvdlvdtl(1, &MINVDLVDTL);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CWIPLOTTRC INSERT", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVDLVDTL.DLV_NO), MINVDLVDTL.DLV_NO);
				TRS.add_fieldmsg(out_node, "PO_NO", MP_STR, sizeof(MINVDLVDTL.PO_NO), MINVDLVDTL.PO_NO);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;
			}
		}

		//부외재고 삭제
		if (memcmp(MWIPLOTLOS.LOSS_CODE_1, MP_LOSS_CODE_NON_STOCK, strlen(MP_LOSS_CODE_NON_STOCK)) == MP_FALSE)
		{
			DBU_init_cwiplotrec(&CWIPLOTREC);
			memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTREC.FACTORY));
			memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));
			DBU_select_cwiplotrec(1, &CWIPLOTREC);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplotrec(1, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTREC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		//경우 검사 요청 ID의 상태값을 바꿔준다.
		if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, strlen(gs_area_ctm)) == MP_FALSE)
		{
			if (memcmp(MWIPOPRDEF.OPER_GRP_2, MP_INSP_OPER_TYPE_NON, strlen(MP_INSP_OPER_TYPE_NON)) != MP_FALSE)
			{
				DBU_init_cqcmispsts(&CQCMISPSTS);
				memcpy(CQCMISPSTS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CQCMISPSTS.FACTORY));
				memcpy(CQCMISPSTS.INSP_ID, MWIPLOTSTSX.LOT_CMF_10, sizeof(CQCMISPSTS.INSP_ID));
				DBU_select_cqcmispsts(1, &CQCMISPSTS);
				if (DB_error_code == DB_SUCCESS)
				{
					CQCMISPSTS.INSP_STATUS = 'R';
					DBU_update_cqcmispsts(1, &CQCMISPSTS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CQCMISPSTS UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
						TRS.add_fieldmsg(out_node, "INSP_ID", MP_STR, sizeof(CQCMISPSTS.INSP_ID), CQCMISPSTS.INSP_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}

		//END 처리 설비 조회
		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));
		DBU_select_mrasresdef(1, &MRASRESDEF);
		if (DB_error_code == DB_SUCCESS)
		{
			if (memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
			{
				//프레스 날짜별 COUNT 이력 삭제
				DBU_init_cwipprsrun(&CWIPPRSRUN);
				TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPPRSRUN.WORK_DATE, MWIPLOTHISX.TRAN_CMF_1, sizeof(CWIPPRSRUN.WORK_DATE));
				memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTHISX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
				if (DBU_select_cwipprsrun_scalar(3, &CWIPPRSRUN) > 0)
				{
					DBU_delete_cwipprsrun(2, &CWIPPRSRUN);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code != DB_NOT_FOUND)
						{
							//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
							strcpy(s_msg_code, "ADM-0004");
							TRS.add_fieldmsg(out_node, "CWIPPRSRUN DELETE", DT_NOVALUESTRING);
							TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
							TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
							TRS.add_dberrmsg(out_node, DB_error_msg);

							gs_log_type.type = MP_LOG_ERROR;
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							gs_log_type.category = MP_LOG_CATE_VIEW;

							COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
							return MP_FALSE;
						}
					}
				}
			}
		}

		//작업지시 실적 BACK
		if (MWIPLOTSTSX.LOT_TYPE != MP_LOT_TYPE_TEST)
		{
			DBU_init_mwipordsts(&MWIPORDSTS);
			TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPORDSTS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
			DBU_select_mwipordsts(1, &MWIPORDSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ORD-0002 : 이 ORDER는 존재하지 않습니다.
				strcpy(s_msg_code, "ORD-0002");
				TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//분류의 작업지시는 mes 내부에서만 사용 하는 임의의 작업지시이기 때문에 작업지시 수량을 보정하지 않아도 된다.
			if (memcmp(MWIPORDSTS.ORDER_DESC, "CLASS", strlen("CLASS")) != MP_FALSE)
			{
				MWIPORDSTS.ORD_LOSS_QTY = MWIPORDSTS.ORD_LOSS_QTY - MWIPLOTLOS.TOTAL_LOSS_QTY;

				memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
				TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_mwipordsts(1, &MWIPORDSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					return MP_FALSE;
				}

				//공정별 작업지시에 end 수량을 업데이트 한다. 
				DBU_init_cwipordopr(&CWIPORDOPR);
				memcpy(CWIPORDOPR.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
				memcpy(CWIPORDOPR.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
				memcpy(CWIPORDOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_cwipordopr(1, &CWIPORDOPR);
				if (DB_error_code == DB_SUCCESS)
				{
					CWIPORDOPR.OPER_LOSS_QTY = CWIPORDOPR.OPER_LOSS_QTY - MWIPLOTLOS.TOTAL_LOSS_QTY;

					memcpy(CWIPORDOPR.UPDATE_TIME, gs_sys_time, sizeof(CWIPORDOPR.UPDATE_TIME));
					TRS.copy(CWIPORDOPR.UPDATE_USER_ID, sizeof(CWIPORDOPR.UPDATE_USER_ID), in_node, IN_USERID);

					DBU_update_cwipordopr(1, &CWIPORDOPR);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPORDOPR UPDATE(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
						TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}
			}
		}

		// LOSS IF 실적 취소
		DBU_init_if_move_trx(&IF_MOVE_TRX);
		memcpy(IF_MOVE_TRX.MES_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		memcpy(IF_MOVE_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(IF_MOVE_TRX.FROM_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(IF_MOVE_TRX.FROM_OPER));
		memcpy(IF_MOVE_TRX.TO_STEP, MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S));
		DBU_select_if_move_trx(3, &IF_MOVE_TRX);
		if (DB_error_code == DB_SUCCESS)
		{
			if_in = TRS.add_node(in_node, "if_in");
			TRS.add_char(if_in, IN_PROCSTEP, '1');
			CopyDefaultMembers(if_in, in_node);

			TRS.add_char(if_in, "TRAN_FLAG", 'I');
			TRS.add_string(if_in, "WO_ID", IF_MOVE_TRX.WO_ID, sizeof(IF_MOVE_TRX.WO_ID));
			TRS.add_int(if_in, "ERP_WO_ID", IF_MOVE_TRX.ERP_WO_ID);
			TRS.add_string(if_in, "AREA_ID", IF_MOVE_TRX.AREA_ID, sizeof(IF_MOVE_TRX.AREA_ID));
			TRS.add_int(if_in, "ERP_AREA_ID", IF_MOVE_TRX.ERP_AREA_ID);
			TRS.add_string(if_in, "FROM_OPER", IF_MOVE_TRX.TO_OPER, sizeof(IF_MOVE_TRX.TO_OPER));
			TRS.add_string(if_in, "FROM_STEP", MP_ERP_TRAN_STEP_S, strlen(MP_ERP_TRAN_STEP_S));
			TRS.add_int(if_in, "FROM_STEP_TYPE", 5);
			TRS.add_int(if_in, "FROM_OPER_SEQ", IF_MOVE_TRX.TO_OPER_SEQ);
			TRS.add_string(if_in, "TO_OPER", IF_MOVE_TRX.FROM_OPER, sizeof(IF_MOVE_TRX.FROM_OPER));
			TRS.add_string(if_in, "TO_STEP", MP_ERP_TRAN_STEP_Q, strlen(MP_ERP_TRAN_STEP_Q));
			TRS.add_int(if_in, "TO_STEP_TYPE", 1);
			TRS.add_int(if_in, "TO_OPER_SEQ", IF_MOVE_TRX.FROM_OPER_SEQ);
			TRS.add_string(if_in, "UNIT", IF_MOVE_TRX.UNIT, sizeof(IF_MOVE_TRX.UNIT));
			TRS.add_double(if_in, "QTY", IF_MOVE_TRX.QTY);
			TRS.add_string(if_in, "OPER", MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
			TRS.add_string(if_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
			TRS.add_char(if_in, "OVER_FLAG", 'N');

			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_IFS_MOVE_TRX(s_msg_code, if_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}

			TRS.free_node(cmn_out);
		}

		DBU_init_mwiplothisx(&MWIPLOTHISX_T);
		memcpy(MWIPLOTHISX_T.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		MWIPLOTHISX_T.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
		memcpy(MWIPLOTHISX_T.OLD_OPER, MWIPLOTLOS.CAUSE_OPER, sizeof(MWIPLOTHISX_T.OLD_OPER));
		memcpy(MWIPLOTHISX_T.TRAN_CODE, MP_TRAN_CODE_START, strlen(MP_TRAN_CODE_START));
		MWIPLOTHISX_T.RESV_FLAG_1 = MWIPLOTSTSX.RESV_FLAG_1;  // 재작업 여부
		DBU_select_mwiplothisx(3, &MWIPLOTHISX_T);
		if (DB_error_code == DB_NOT_FOUND)
		{
			MWIPLOTHISX_T.HIST_SEQ = 0;
		}

		// 설비 효율용 집계
		DBU_init_csumreswip(&CSUMRESWIP);
		memcpy(CSUMRESWIP.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CSUMRESWIP.LOT_ID));
		CSUMRESWIP.START_HIST_SEQ = MWIPLOTHISX_T.HIST_SEQ;
		DBU_select_csumreswip(1, &CSUMRESWIP);
		if (DB_error_code == DB_SUCCESS)
		{
			memset(CSUMRESWIP.END_DATE, ' ', sizeof(CSUMRESWIP.END_DATE));
			memset(CSUMRESWIP.END_TIME, ' ', sizeof(CSUMRESWIP.END_TIME));
			memset(CSUMRESWIP.END_DAY_NIGHT, ' ', sizeof(CSUMRESWIP.END_DAY_NIGHT));
			CSUMRESWIP.END_HIST_SEQ = 0;

			CSUMRESWIP.OUT_QTY = 0;
			CSUMRESWIP.LOSS_QTY = CSUMRESWIP.LOSS_QTY - (MWIPLOTHISX.OLD_QTY_1 - MWIPLOTHISX.QTY_1);

			memcpy(CSUMRESWIP.UPDATE_TIME, gs_sys_time, sizeof(CSUMRESWIP.UPDATE_TIME));
			TRS.copy(CSUMRESWIP.UPDATE_USER_ID, sizeof(CSUMRESWIP.UPDATE_USER_ID), in_node, IN_USERID);
			DBU_update_csumreswip(1, &CSUMRESWIP);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "CSUMRESWIP UPDATE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMRESWIP.LOT_ID), CSUMRESWIP.LOT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMRESWIP.OPER), CSUMRESWIP.OPER);
				TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMRESWIP.RES_ID), CSUMRESWIP.RES_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
		}

		// Lot Summary의 END_DATE, END_TIME, END_DAY_NIGTH 보정
		DBU_init_csumlotdat(&CSUMLOTDAT);
		memcpy(CSUMLOTDAT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(CSUMLOTDAT.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		CSUMLOTDAT.START_HIST_SEQ = MWIPLOTHISX_T.HIST_SEQ;
		DBU_select_csumlotdat(1, &CSUMLOTDAT);
		if (DB_error_code == DB_SUCCESS)
		{
			if (CSUMLOTDAT.START_HIST_SEQ != 0)
			{
				memset(CSUMLOTDAT.END_DATE, ' ', sizeof(CSUMLOTDAT.END_DATE));
				memset(CSUMLOTDAT.END_TIME, ' ', sizeof(CSUMLOTDAT.END_TIME));
				memset(CSUMLOTDAT.END_DAY_NIGHT, ' ', sizeof(CSUMLOTDAT.END_DAY_NIGHT));
				CSUMLOTDAT.END_HIST_SEQ = 0;

				CSUMLOTDAT.LOSS_QTY = 0;
				CSUMLOTDAT.OUT_QTY = 0;

				memcpy(CSUMLOTDAT.UPDATE_TIME, gs_sys_time, sizeof(CSUMLOTDAT.UPDATE_TIME));
				TRS.copy(CSUMLOTDAT.UPDATE_USER_ID, sizeof(CSUMLOTDAT.UPDATE_USER_ID), in_node, IN_USERID);

				DBU_update_csumlotdat(1, &CSUMLOTDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CSUMLOTDAT UPDATE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMLOTDAT.RES_ID), CSUMLOTDAT.RES_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
			else
			{
				DBU_delete_csumlotdat(1, &CSUMLOTDAT);
				if (DB_error_code != DB_SUCCESS)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CSUMLOTDAT DELETE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CSUMLOTDAT.LOT_ID), CSUMLOTDAT.LOT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CSUMLOTDAT.OPER), CSUMLOTDAT.OPER);
					TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(CSUMLOTDAT.RES_ID), CSUMLOTDAT.RES_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_ADAPT, strlen(MP_TRAN_CODE_ADAPT)) == MP_FALSE)
	{
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//ADAPT시에는 자기 자신lot이 투입lot이 된다. 
		DBU_init_minvlotiss(&MINVLOTISS);
		memcpy(MINVLOTISS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
		memcpy(MINVLOTISS.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
		memcpy(MINVLOTISS.OPER, MWIPOPRDEF.OPER, sizeof(MINVLOTISS.OPER));
		memcpy(MINVLOTISS.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
		memcpy(MINVLOTISS.INV_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
		DBU_select_minvlotiss(2, &MINVLOTISS);
		if (DB_error_code == DB_SUCCESS)
		{


			//자재투입 취소처리를 해준다.<서비스 호출로 변경함>(20240311) 
			//자재 투입 취소 서비스 호출로
			iss_in = TRS.add_node(in_node, "mat_in");
			TRS.add_char(iss_in, IN_PROCSTEP, '6');
			CopyDefaultMembers(iss_in, in_node);


			TRS.add_string(iss_in, "AREA_ID", MINVLOTISS.AREA_ID, sizeof(MINVLOTISS.AREA_ID));
			TRS.add_string(iss_in, "SUB_AREA_ID", MINVLOTISS.SUB_AREA_ID, sizeof(MINVLOTISS.SUB_AREA_ID));
			TRS.add_string(iss_in, "OPER", MINVLOTISS.OPER, sizeof(MINVLOTISS.OPER));
			TRS.add_string(iss_in, "ORDER_ID", MINVLOTISS.ORDER_ID, sizeof(MINVLOTISS.ORDER_ID));



			iss_list = TRS.add_node(iss_in, "LIST_TBL");
			TRS.add_string(iss_list, "OPER_LOT_ID", MINVLOTISS.LOT_ID, sizeof(MINVLOTISS.LOT_ID));
			TRS.add_string(iss_list, "LOT_ID", MINVLOTISS.INV_LOT_ID, sizeof(MINVLOTISS.INV_LOT_ID));
			TRS.add_string(iss_list, "MAT_ID", MINVLOTISS.MAT_ID, sizeof(MINVLOTISS.MAT_ID));
			TRS.add_double(iss_list, "QTY", MINVLOTISS.TRAN_QTY);
			TRS.add_int(iss_list, "HIST_SEQ", MINVLOTISS.HIST_SEQ);
			TRS.add_string(iss_list, "OUT_OPER", MINVLOTISS.OUT_OPER, sizeof(MINVLOTISS.OUT_OPER));



			cmn_out = TRS.create_node("Cmn_Out");
			if (CUS_WIP_INPUT_MATERIAL_LOT(s_msg_code, iss_in, cmn_out) == MP_FALSE)
			{
				TRS.clone(out_node, cmn_out);
				TRS.free_node(cmn_out);
				return MP_FALSE;
			}
			TRS.free_node(cmn_out);

			/*

			DBU_delete_minvlotiss(1, &MINVLOTISS);
			if (DB_error_code != DB_SUCCESS)
			{
				//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
				strcpy(s_msg_code, "ADM-0004");
				TRS.add_fieldmsg(out_node, "MINVLOTISS DELETE", DT_NOVALUESTRING);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTISS.FACTORY), MINVLOTISS.FACTORY);
				TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(MINVLOTISS.INV_LOT_ID), MINVLOTISS.INV_LOT_ID);
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MINVLOTISS.ORDER_ID), MINVLOTISS.ORDER_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTISS.OPER), MINVLOTISS.OPER);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTISS.LOT_ID), MINVLOTISS.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);
				return MP_FALSE;
			}

			*/
		}

		//품목 변경인 경우 이전 품목으로 다시 품목변경을 ERP에 올린다.
		if (memcmp(MWIPLOTHISX.TRAN_CMF_3, "MAT_CHANGE", strlen("MAT_CHANGE")) == MP_FALSE)
		{

			//P급창고에서의 변경은 ERP에 올리지 않는다.
			if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != MP_FALSE)
			{

				//양산품인 경우만 인터페이스를 올린다.
				if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_PROD)
				{
					DBU_init_mwipoprdef(&MWIPOPRDEF);
					TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
					DBU_select_mwipoprdef(1, &MWIPOPRDEF);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							//WIP-0590 : 이 창고는 존재하지 않습니다.
							strcpy(s_msg_code, "WIP-0590");
							gs_log_type.e_type = MP_LOG_E_EXISTENCE;
						}
						else
						{
							strcpy(s_msg_code, "INV-0004");
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							TRS.add_dberrmsg(out_node, DB_error_msg);
						}

						TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
						TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_TRANS;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//품목변경인 경우 창고에서만 변경 가능하기 때문에 일반 공정에서 변경 될 수 없다.
					if (memcmp(MWIPOPRDEF.OPER_GRP_1, "NO_STORE", strlen("NO_STORE")) == MP_FALSE)
					{
						DBU_init_mwiplothisx(&MWIPLOTHISX_T);
						memcpy(MWIPLOTHISX_T.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
						memcpy(MWIPLOTHISX_T.LOT_ID, MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
						MWIPLOTHISX_T.HIST_SEQ = MWIPLOTHISX.HIST_SEQ;
						DBU_select_mwiplothisx(7, &MWIPLOTHISX_T);
						if (DB_error_code == DB_SUCCESS)
						{
							DBU_init_mwipoprdef(&MWIPOPRDEF);
							TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
							memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX_T.OPER, sizeof(MWIPOPRDEF.OPER));
							DBU_select_mwipoprdef(1, &MWIPOPRDEF);
							if (DB_error_code != DB_SUCCESS)
							{
								//WIP-0010 : 이 공정은 존재 하지 않습니다.
								strcpy(s_msg_code, "WIP-0010");
								TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
								TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}
					}

					//AREA 정보 조회
					DBU_init_mgcmtbldat(&MGCMTBLDAT_AREA);
					TRS.copy(MGCMTBLDAT_AREA.FACTORY, sizeof(MGCMTBLDAT_AREA.FACTORY), in_node, IN_FACTORY);
					memcpy(MGCMTBLDAT_AREA.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
					memcpy(MGCMTBLDAT_AREA.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					DBU_select_mgcmtbldat(1, &MGCMTBLDAT_AREA);
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
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_AREA.FACTORY), MGCMTBLDAT_AREA.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_AREA.KEY_1), MGCMTBLDAT_AREA.KEY_1);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					// MWIPMATDEF_AF - 제품 정보 조회
					DBU_init_mwipmatdef(&MWIPMATDEF_AF);
					TRS.copy(MWIPMATDEF_AF.FACTORY, sizeof(MWIPMATDEF_AF.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPMATDEF_AF.MAT_ID, MWIPLOTHISX.OLD_MAT_ID, sizeof(MWIPLOTHISX.OLD_MAT_ID));
					MWIPMATDEF_AF.MAT_VER = MWIPLOTHISX.OLD_MAT_VER;
					DBU_select_mwipmatdef(1, &MWIPMATDEF_AF);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							//WIP-0006 : 이 제품은 존재 하지 않습니다.
							strcpy(s_msg_code, "WIP-0006");
							gs_log_type.e_type = MP_LOG_E_EXISTENCE;
						}
						else
						{
							strcpy(s_msg_code, "INV-0004");
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							TRS.add_dberrmsg(out_node, DB_error_msg);
						}

						TRS.add_fieldmsg(out_node, "MWIPMATDEF_AF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF_AF.FACTORY), MWIPMATDEF_AF.FACTORY);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF_AF.MAT_ID), MWIPMATDEF_AF.MAT_ID);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_TRANS;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					//ERP 품목변경 후 I/F
					if_change_in = TRS.add_node(in_node, "if_change_in");
					TRS.add_char(if_change_in, IN_PROCSTEP, '1');
					CopyDefaultMembers(if_change_in, in_node);

					TRS.add_char(if_change_in, "TRAN_FLAG", 'I');
					TRS.add_int(if_change_in, "ERP_WO_ID", 1);
					TRS.add_string(if_change_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					TRS.add_int(if_change_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_AREA.DATA_2, sizeof(MGCMTBLDAT_AREA.DATA_2)));
					TRS.add_int(if_change_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_44));
					TRS.add_string(if_change_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
					TRS.add_string(if_change_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
					TRS.add_int(if_change_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF_AF.MAT_CMF_1, sizeof(MWIPMATDEF_AF.MAT_CMF_1)));
					TRS.add_string(if_change_in, "MAT_ID", MWIPMATDEF_AF.MAT_ID, sizeof(MWIPMATDEF_AF.MAT_ID));
					TRS.add_string(if_change_in, "UNIT", MWIPMATDEF_AF.UNIT_1, sizeof(MWIPMATDEF_AF.UNIT_1));
					TRS.add_double(if_change_in, "QTY", MWIPLOTSTSX.QTY_1);
					TRS.add_string(if_change_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.add_char(if_change_in, "CHANGE_ITEM", 'Y');

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_change_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);

					// MWIPMATDEF - 제품 정보 조회
					DBU_init_mwipmatdef(&MWIPMATDEF);
					TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
					memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
					MWIPMATDEF.MAT_VER = MWIPLOTSTSX.MAT_VER;
					DBU_select_mwipmatdef(1, &MWIPMATDEF);
					if (DB_error_code != DB_SUCCESS)
					{
						if (DB_error_code == DB_NOT_FOUND)
						{
							//WIP-0006 : 이 제품은 존재 하지 않습니다.
							strcpy(s_msg_code, "WIP-0006");
							gs_log_type.e_type = MP_LOG_E_EXISTENCE;
						}
						else
						{
							strcpy(s_msg_code, "INV-0004");
							gs_log_type.e_type = MP_LOG_E_SYSTEM;
							TRS.add_dberrmsg(out_node, DB_error_msg);
						}

						TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.category = MP_LOG_CATE_TRANS;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
					TRS.copy(IF_COMPLETION_TRX.FACTORY, sizeof(IF_COMPLETION_TRX.FACTORY), in_node, IN_FACTORY);
					memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);

					//ERP 품목변경 전 I/F
					TRS.set_int(if_change_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_35));
					TRS.set_string(if_change_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION));
					TRS.set_double(if_change_in, "TRAN_HEADER_ID", (double)DBU_select_if_completion_trx_scalar(2, &IF_COMPLETION_TRX));
					TRS.set_string(if_change_in, "INV_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
					TRS.set_int(if_change_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
					TRS.set_string(if_change_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					TRS.set_string(if_change_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
					TRS.set_double(if_change_in, "QTY", MWIPLOTSTSX.QTY_1);
					TRS.set_string(if_change_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					TRS.set_char(if_change_in, "CHANGE_ITEM", 'N');

					cmn_out = TRS.create_node("Cmn_Out");
					if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_change_in, cmn_out) == MP_FALSE)
					{
						TRS.clone(out_node, cmn_out);
						TRS.free_node(cmn_out);
						return MP_FALSE;
					}

					TRS.free_node(cmn_out);
				}
			}
			//품목변경 이력 테이블 삭제.  (CWIPLOTCHG)
			DBU_init_cwiplotchg(&CWIPLOTCHG);
			memcpy(CWIPLOTCHG.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
			memcpy(CWIPLOTCHG.LOT_ID, MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
			CWIPLOTCHG.HIST_SEQ = MWIPLOTHISX.HIST_SEQ;

			DBU_select_cwiplotchg(1, &CWIPLOTCHG);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplotchg(1, &CWIPLOTCHG);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTCHG DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCHG.FACTORY), CWIPLOTCHG.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCHG.LOT_ID), CWIPLOTCHG.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}


		if (memcmp(MWIPLOTHISX.TRAN_CMF_3, "PROD_CHANGE", strlen("PROD_CHANGE")) == MP_FALSE) {

		}

	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
	{
		c_CheckClassOper = 'N';

		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//PRESS 설비인 경우 일별 RUN수 체크 테이블을 삭제한다.        
		//프레스 날짜별 COUNT 이력 삭제
		DBU_init_cwipprsrun(&CWIPPRSRUN);
		TRS.copy(CWIPPRSRUN.FACTORY, sizeof(CWIPPRSRUN.FACTORY), in_node, IN_FACTORY);
		memcpy(CWIPPRSRUN.WORK_DATE, MWIPLOTHISX.TRAN_CMF_1, sizeof(CWIPPRSRUN.WORK_DATE));
		memcpy(CWIPPRSRUN.CELL_ID, MWIPLOTHISX.LOT_CMF_1, sizeof(CWIPPRSRUN.CELL_ID));
		if (DBU_select_cwipprsrun_scalar(3, &CWIPPRSRUN) > 0)
		{
			DBU_delete_cwipprsrun(2, &CWIPPRSRUN);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code != DB_NOT_FOUND)
				{
					//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
					strcpy(s_msg_code, "ADM-0004");
					TRS.add_fieldmsg(out_node, "CWIPPRSRUN DELETE", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPPRSRUN.FACTORY), CWIPPRSRUN.FACTORY);
					TRS.add_fieldmsg(out_node, "CELL_ID", MP_STR, sizeof(CWIPPRSRUN.CELL_ID), CWIPPRSRUN.CELL_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		//분류 공정 여부 
		DBU_init_mgcmtbldat(&MGCMTBLDAT_GRT);
		TRS.copy(MGCMTBLDAT_GRT.FACTORY, sizeof(MGCMTBLDAT_GRT.FACTORY), in_node, IN_FACTORY);
		memcpy(MGCMTBLDAT_GRT.TABLE_NAME, MP_GCM_GRIT_OPER, strlen(MP_GCM_GRIT_OPER));
		memcpy(MGCMTBLDAT_GRT.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mgcmtbldat(1, &MGCMTBLDAT_GRT);
		if (DB_error_code == DB_SUCCESS)
		{
			c_CheckClassOper = 'Y';
		}

		//lot 추적 테이블 삭제
		if (MWIPLOTSTSX.FROM_TO_FLAG == 'T')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
			CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_cwiplottrc(2, &CWIPLOTTRC);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}

			//그릿분류 공정인 경우 CWIPLOTCLS테이블 삭제.
			if (c_CheckClassOper == 'Y')
			{
				DBU_init_cwiplotcls(&CWIPLOTCLS);
				memcpy(CWIPLOTCLS.FACTORY, CWIPLOTTRC.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
				memcpy(CWIPLOTCLS.OUT_LOT_ID, CWIPLOTTRC.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
				memcpy(CWIPLOTCLS.LOT_ID, CWIPLOTTRC.FROM_LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
				DBU_delete_cwiplotcls(2, &CWIPLOTCLS);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTCLS DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTCLS.FACTORY), CWIPLOTCLS.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTCLS.LOT_ID), CWIPLOTCLS.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
		else if (MWIPLOTSTSX.FROM_TO_FLAG == 'F')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
			CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_cwiplottrc(3, &CWIPLOTTRC);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}

			//그릿분류 공정인 경우 CWIPLOTCLS테이블 삭제.
			if (c_CheckClassOper == 'Y')
			{


			}

		}

		//SPLIT공정이면서 맵핑그룹 설정되어 있는 공정인 경우 LOT을 SPLIT 하면서 SPLIT된 LOT들을 그룹ID에 묶어준다.
		//수동 컵계량 공정인 경우 해당 옵션을 사용한다.
		//PRESS 공정인 경우 제외
		if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, sizeof(gs_area_ctm)) == MP_FALSE)
		{
			if (MWIPLOTSTSX.FROM_TO_FLAG == 'T')
			{
				//save res id 를 저장하는 공정은 press 공정뿐이 없다.
				//press 공정에서는 group id를 지우지 않는다.
				if (MWIPLOTSTSX.SAVE_RES_ID_1[0] == ' ')
				{
					DBU_init_cwipgrplot(&CWIPGRPLOT);
					TRS.copy(CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(CWIPGRPLOT.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPLOT.GROUP_ID));
					memcpy(CWIPGRPLOT.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID));
					DBU_select_cwipgrplot(1, &CWIPGRPLOT);
					if (DB_error_code == DB_SUCCESS)
					{
						DBU_delete_cwipgrplot(1, &CWIPGRPLOT);
						if (DB_error_code != DB_SUCCESS)
						{
							if (DB_error_code != DB_NOT_FOUND)
							{
								//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
								strcpy(s_msg_code, "ADM-0004");
								TRS.add_fieldmsg(out_node, "CWIPGRPLOT DELETE", DT_NOVALUESTRING);
								TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
								TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
								TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPGRPLOT.LOT_ID), CWIPGRPLOT.LOT_ID);
								TRS.add_dberrmsg(out_node, DB_error_msg);

								gs_log_type.type = MP_LOG_ERROR;
								gs_log_type.e_type = MP_LOG_E_SYSTEM;
								gs_log_type.category = MP_LOG_CATE_VIEW;

								COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
								return MP_FALSE;
							}
						}
					}

					DBU_init_cwipgrplot(&CWIPGRPLOT);
					TRS.copy(CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT.FACTORY), in_node, IN_FACTORY);
					memcpy(CWIPGRPLOT.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPLOT.GROUP_ID));
					if (DBU_select_cwipgrplot_scalar(2, &CWIPGRPLOT) == 0)
					{
						DBU_init_cwipgrpsts(&CWIPGRPSTS);
						TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
						memcpy(CWIPGRPSTS.GROUP_ID, MWIPLOTSTSX.LOT_CMF_1, sizeof(CWIPGRPSTS.GROUP_ID));
						if (DB_error_code == DB_SUCCESS)
						{
							DBU_delete_cwipgrpsts(1, &CWIPGRPSTS);
							if (DB_error_code != DB_SUCCESS)
							{
								if (DB_error_code != DB_NOT_FOUND)
								{
									//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
									strcpy(s_msg_code, "ADM-0004");
									TRS.add_fieldmsg(out_node, "CWIPGRPSTS DELETE", DT_NOVALUESTRING);
									TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPSTS.FACTORY), CWIPGRPSTS.FACTORY);
									TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
									TRS.add_dberrmsg(out_node, DB_error_msg);

									gs_log_type.type = MP_LOG_ERROR;
									gs_log_type.e_type = MP_LOG_E_SYSTEM;
									gs_log_type.category = MP_LOG_CATE_VIEW;

									COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
									return MP_FALSE;
								}
							}
						}
					}
				}

				////PRESS 설비에서 받은 정보는 시작 LOT으로 설비 인터페이스 데이터를 받아 LOT이 완료시 PRESS로 채번된 LOT ID을 초기화
				DBU_init_cwiplotprs(&CWIPLOTPRS);
				memcpy(CWIPLOTPRS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTPRS.FACTORY));
				memcpy(CWIPLOTPRS.CMF_1, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				if (DBU_select_cwiplotprs_scalar(3, &CWIPLOTPRS) > 0)
				{
					memset(CWIPLOTPRS.CMF_1, ' ', sizeof(CWIPLOTPRS.CMF_1));
					TRS.copy(CWIPLOTPRS.UPDATE_USER_ID, sizeof(CWIPLOTPRS.UPDATE_USER_ID), in_node, IN_USERID);
					memcpy(CWIPLOTPRS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTPRS.UPDATE_TIME));
					DBU_update_cwiplotprs(3, &CWIPLOTPRS);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTPRS UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTPRS.FACTORY), CWIPLOTPRS.FACTORY);
						TRS.add_fieldmsg(out_node, "CMF_1", MP_STR, sizeof(CWIPLOTPRS.CMF_1), CWIPLOTPRS.CMF_1);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						return MP_FALSE;
					}
				}
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_MERGE, strlen(MP_TRAN_CODE_MERGE)) == MP_FALSE)
	{
		//MERGE되어 0이된 것
		if (MWIPLOTSTSX.FROM_TO_FLAG == 'F')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.FROM_LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.FROM_LOT_ID));
			CWIPLOTTRC.FROM_LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_cwiplottrc(3, &CWIPLOTTRC);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
		//MERGE되어 수량이 증가된 것
		else if (MWIPLOTSTSX.FROM_TO_FLAG == 'T')
		{
			DBU_init_cwiplottrc(&CWIPLOTTRC);
			memcpy(CWIPLOTTRC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTTRC.FACTORY));
			memcpy(CWIPLOTTRC.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTTRC.OPER));
			memcpy(CWIPLOTTRC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTTRC.LOT_ID));
			CWIPLOTTRC.LOT_HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
			DBU_select_cwiplottrc(2, &CWIPLOTTRC);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_delete_cwiplottrc(1, &CWIPLOTTRC);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code != DB_NOT_FOUND)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTTRC DELETE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTTRC.FACTORY), CWIPLOTTRC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTTRC.LOT_ID), CWIPLOTTRC.LOT_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_STORE, strlen(MP_TRAN_CODE_STORE)) == MP_FALSE) //현재는 STORE 안씀
	{
		//LOT ID에 대한 품목 정보를 조회한다.
		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		//현재 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//TO 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
		TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTSX.STR_RET_OPER, sizeof(MWIPOPRDEF_AF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF_AF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}

		//STORE의 이력삭제인 경우 STR_RET_OPER가 일반 공정인 경우는 건너뛴다. 
		if (memcmp(MWIPOPRDEF_AF.OPER_GRP_1, "NO_STORE", strlen("NO_STORE")) == MP_FALSE)
		{
			DBU_init_mwiplothisx(&MWIPLOTHISX_T);
			memcpy(MWIPLOTHISX_T.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
			memcpy(MWIPLOTHISX_T.LOT_ID, MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
			MWIPLOTHISX_T.HIST_SEQ = MWIPLOTHISX.HIST_SEQ;
			DBU_select_mwiplothisx(7, &MWIPLOTHISX_T);
			if (DB_error_code == DB_SUCCESS)
			{
				DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
				TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTHISX_T.OPER, sizeof(MWIPOPRDEF_AF.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
				if (DB_error_code != DB_SUCCESS)
				{
					//WIP-0010 : 이 공정은 존재 하지 않습니다.
					strcpy(s_msg_code, "WIP-0010");
					TRS.add_fieldmsg(out_node, "MWIPOPRDEF_AF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}

		//품목변경으로 인한 store인 경우(이전 창고와 공정이 같을 때)는 erp 인터페이스를 보내지 않는다.
		if (memcmp(MWIPOPRDEF.OPER, MWIPOPRDEF_AF.OPER, sizeof(MWIPOPRDEF_AF.OPER)) != MP_FALSE)
		{
			//이전 창고가 P급 창고인 경우 ERP인터페이스는 
			// CTM : COMPLETION 취소, GRT : 기타 출고
			if (memcmp(MWIPOPRDEF_AF.OPER_GRP_1, "LOSS", strlen("LOSS")) != MP_FALSE)
			{
				//FROM AREA 정보 조회
				DBU_init_mgcmtbldat(&MGCMTBLDAT_FROM);
				TRS.copy(MGCMTBLDAT_FROM.FACTORY, sizeof(MGCMTBLDAT_FROM.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_FROM.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
				memcpy(MGCMTBLDAT_FROM.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_FROM);
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

					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_FROM.FACTORY), MGCMTBLDAT_FROM.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_FROM.KEY_1), MGCMTBLDAT_FROM.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//TO AREA 정보 조회
				DBU_init_mgcmtbldat(&MGCMTBLDAT_TO);
				TRS.copy(MGCMTBLDAT_TO.FACTORY, sizeof(MGCMTBLDAT_TO.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_TO.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
				memcpy(MGCMTBLDAT_TO.KEY_1, MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_TO);
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

					TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_TO.FACTORY), MGCMTBLDAT_TO.FACTORY);
					TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MGCMTBLDAT_TO.KEY_1), MGCMTBLDAT_TO.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				DBU_init_mgcmtbldat(&MGCMTBLDAT_SRC);
				TRS.copy(MGCMTBLDAT_SRC.FACTORY, sizeof(MGCMTBLDAT_SRC.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT_SRC.TABLE_NAME, MP_GCM_SRC_CODE, strlen(MP_GCM_SRC_CODE));
				memcpy(MGCMTBLDAT_SRC.KEY_1, "MOVE", strlen("MOVE"));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT_SRC);
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
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_SRC.FACTORY), MGCMTBLDAT_SRC.FACTORY);
					TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_SRC.TABLE_NAME), MGCMTBLDAT_SRC.TABLE_NAME);
					TRS.add_fieldmsg(out_node, "SRC_CODE", MP_STR, sizeof(MGCMTBLDAT_SRC.KEY_1), MGCMTBLDAT_SRC.KEY_1);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//창고 이동 인터페이스 
				DBU_init_cbastxndef(&CBASTXNDEF);
				TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
				CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
				CBASTXNDEF.ERP_AREA_ID = COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2));
				DBU_select_cbastxndef(2, &CBASTXNDEF);

				if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
					TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				if (DB_error_code == DB_NOT_FOUND)
				{
					//해당 사업부로 조회 후 데이터 없을 경우, MST로 다시 조회
					//MST(ERP AREA ID : 103)
					//임시로 하드코딩
					DBU_init_cbastxndef(&CBASTXNDEF);
					TRS.copy(CBASTXNDEF.FACTORY, sizeof(CBASTXNDEF.FACTORY), in_node, IN_FACTORY);
					CBASTXNDEF.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_2);
					CBASTXNDEF.ERP_AREA_ID = 103;
					DBU_select_cbastxndef(2, &CBASTXNDEF);

					if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CBASTXNDEF SELECT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CBASTXNDEF.FACTORY), CBASTXNDEF.FACTORY);
						TRS.add_fieldmsg(out_node, "TRAN_TYPE_ID", MP_INT, CBASTXNDEF.TRAN_TYPE_ID);
						TRS.add_fieldmsg(out_node, "ERP_AREA_ID", MP_INT, CBASTXNDEF.ERP_AREA_ID);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}

				//ERP 실적 - IF_INV_TXNS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_int(erpif_in, "TRAN_TYPE_ID", CBASTXNDEF.TRAN_TYPE_ID);
				TRS.add_string(erpif_in, "TRAN_TYPE", CBASTXNDEF.TRAN_TYPE_NAME, sizeof(CBASTXNDEF.TRAN_TYPE_NAME));
				TRS.add_int(erpif_in, "TRAN_SRC_ID", CBASTXNDEF.TRAN_SRC_ID);
				TRS.add_string(erpif_in, "TRAN_SRC_NAME", CBASTXNDEF.TRAN_SRC_DESC, sizeof(CBASTXNDEF.TRAN_SRC_DESC));
				TRS.add_int(erpif_in, "ERP_AREA_ID", COM_atoi(MGCMTBLDAT_FROM.DATA_2, sizeof(MGCMTBLDAT_FROM.DATA_2)));
				TRS.add_string(erpif_in, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "FROM_OPER", MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
				TRS.add_string(erpif_in, "TO_OPER", MWIPOPRDEF_AF.OPER_CMF_1, sizeof(MWIPOPRDEF_AF.OPER_CMF_1));
				TRS.add_string(erpif_in, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
				TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
				TRS.add_int(erpif_in, "TO_ERP_AREA_ID", COM_atoi(MGCMTBLDAT_TO.DATA_2, sizeof(MGCMTBLDAT_TO.DATA_2)));
				TRS.add_string(erpif_in, "TO_AREA_ID", MWIPOPRDEF_AF.AREA_ID, sizeof(MWIPOPRDEF_AF.AREA_ID));
				TRS.add_string(erpif_in, "SRC_CODE", MGCMTBLDAT_SRC.DATA_1, sizeof(MGCMTBLDAT_SRC.DATA_1));
				TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXNS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);

				DBU_init_if_inv_txns(&IF_INV_TXNS);
				TRS.copy(IF_INV_TXNS.FACTORY, sizeof(IF_INV_TXNS.FACTORY), in_node, IN_FACTORY);
				memcpy(IF_INV_TXNS.MES_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				dHeaderSeq = DBU_select_if_inv_txns_scalar(2, &IF_INV_TXNS);

				//ERP 실적 - IF_INV_TXN_LOTS
				erpif_in = TRS.add_node(in_node, "erpif_in");
				TRS.add_char(erpif_in, IN_PROCSTEP, '1');
				CopyDefaultMembers(erpif_in, in_node);

				TRS.add_char(erpif_in, "TRAN_FLAG", 'I');
				TRS.add_double(erpif_in, "INV_TXNS_ID", dHeaderSeq);
				TRS.add_int(erpif_in, "ERP_MAT_ID", COM_atoi(MWIPMATDEF.MAT_CMF_1, sizeof(MWIPMATDEF.MAT_CMF_1)));
				TRS.add_string(erpif_in, "MAT_ID", MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				TRS.add_string(erpif_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				TRS.add_double(erpif_in, "QTY", MWIPLOTSTSX.QTY_1);
				TRS.add_string(erpif_in, "MES_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));     //이동지시 번호

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_IFS_INV_TXN_LOTS(s_msg_code, erpif_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}
			else
			{
				if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, strlen(gs_area_ctm)) == MP_FALSE)
				{
					//P급 작지를 조회한다.
					DBU_init_cwipordrwk(&CWIPORDRWK);
					memcpy(CWIPORDRWK.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
					memcpy(CWIPORDRWK.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					memcpy(CWIPORDRWK.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					CWIPORDRWK.MAT_VER = MWIPMATDEF.MAT_VER;
					DBU_select_cwipordrwk(2, &CWIPORDRWK);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPORDRWK SELECT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDRWK.FACTORY), CWIPORDRWK.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPORDRWK.AREA_ID), CWIPORDRWK.AREA_ID);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDRWK.MAT_ID), CWIPORDRWK.MAT_ID);
						TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, CWIPORDRWK.MAT_VER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
					memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					memcpy(IF_COMPLETION_TRX.WO_ID, CWIPORDRWK.ORDER_ID, sizeof(CWIPORDRWK.ORDER_ID));
					memcpy(IF_COMPLETION_TRX.INV_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(IF_COMPLETION_TRX.INV_OPER));
					IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
					DBU_select_if_completion_trx(5, &IF_COMPLETION_TRX);
					if (DB_error_code == DB_SUCCESS)
					{
						if_end_in = TRS.add_node(in_node, "if_end_in");
						TRS.add_char(if_end_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_end_in, in_node);

						TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
						TRS.add_int(if_end_in, "ERP_WO_ID", IF_COMPLETION_TRX.ERP_WO_ID);
						TRS.add_string(if_end_in, "WO_ID", IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID));
						TRS.add_string(if_end_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
						TRS.add_int(if_end_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
						TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
						TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
						TRS.add_string(if_end_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
						TRS.add_int(if_end_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
						TRS.add_string(if_end_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
						TRS.add_string(if_end_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
						TRS.add_double(if_end_in, "QTY", IF_COMPLETION_TRX.QTY);
						TRS.add_string(if_end_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
						TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);
					}
				}
				//그릿은 LOT을 새로 생성하기 때문에 BACK처리 할 필요없음. 
				//기타 출고처리 해야함. 
				else if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_grt, strlen(gs_area_grt)) == MP_FALSE)
				{



				}

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				DBU_select_cwiplotrec(4, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(4) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// P급 처리 후 P급 정보 DELETE_FLAG 변경
				CWIPLOTREC.DELETE_FLAG = ' ';
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				DBU_update_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}
		}
	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_CV, strlen(MP_TRAN_CODE_CV)) == MP_FALSE)
	{

	}

	else if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_MOVE, strlen(MP_TRAN_CODE_MOVE)) == MP_FALSE)
	{

		DBU_init_mwipoprdef(&MWIPOPRDEF_AF);
		TRS.copy(MWIPOPRDEF_AF.FACTORY, sizeof(MWIPOPRDEF_AF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF_AF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF_AF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF_AF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF_AF.FACTORY), MWIPOPRDEF_AF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_AF.OPER), MWIPOPRDEF_AF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}


		//END 처리 공정 조회
		DBU_init_mwipoprdef(&MWIPOPRDEF);
		TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
		memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OLD_OPER, sizeof(MWIPOPRDEF.OPER));
		DBU_select_mwipoprdef(1, &MWIPOPRDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			//WIP-0010 : 이 공정은 존재 하지 않습니다.
			strcpy(s_msg_code, "WIP-0010");
			TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_VIEW;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}



		//LOT ID에 대한 품목 정보를 조회한다.
		DBU_init_mwipmatdef(&MWIPMATDEF);
		memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
		memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
		MWIPMATDEF.MAT_VER = 1;
		DBU_select_mwipmatdef(1, &MWIPMATDEF);

		//20240716 P급 리턴추가
		// 이전 공정이 P급 창고 인 경우
		if (memcmp(MWIPOPRDEF.OPER_GRP_1, MWIPOPRDEF_AF.OPER_GRP_1, strlen(MWIPOPRDEF_AF.OPER_GRP_1)) != MP_FALSE) {



			if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == MP_FALSE && memcmp(MWIPOPRDEF_AF.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) != MP_FALSE)
			{
			
				
				if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_ctm, strlen(gs_area_ctm)) == MP_FALSE)
				{
					//P급 작지를 조회한다.
					DBU_init_cwipordrwk(&CWIPORDRWK);
					memcpy(CWIPORDRWK.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
					memcpy(CWIPORDRWK.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
					memcpy(CWIPORDRWK.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
					CWIPORDRWK.MAT_VER = MWIPMATDEF.MAT_VER;
					DBU_select_cwipordrwk(2, &CWIPORDRWK);

					if (DB_error_code != DB_SUCCESS)
					{
						strcpy(s_msg_code, "WIP-0004");
						TRS.add_fieldmsg(out_node, "CWIPORDRWK SELECT", MP_NVST);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDRWK.FACTORY), CWIPORDRWK.FACTORY);
						TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(CWIPORDRWK.AREA_ID), CWIPORDRWK.AREA_ID);
						TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDRWK.MAT_ID), CWIPORDRWK.MAT_ID);
						TRS.add_fieldmsg(out_node, "MAT_VER", MP_INT, CWIPORDRWK.MAT_VER);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						gs_log_type.type = MP_LOG_ERROR;
						gs_log_type.e_type = MP_LOG_E_SYSTEM;
						gs_log_type.category = MP_LOG_CATE_VIEW;

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}

					DBU_init_if_completion_trx(&IF_COMPLETION_TRX);
					memcpy(IF_COMPLETION_TRX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
					memcpy(IF_COMPLETION_TRX.WO_ID, CWIPORDRWK.ORDER_ID, sizeof(CWIPORDRWK.ORDER_ID));
					memcpy(IF_COMPLETION_TRX.INV_OPER, MWIPOPRDEF_AF.OPER_CMF_1, sizeof(IF_COMPLETION_TRX.INV_OPER));
					IF_COMPLETION_TRX.TRAN_TYPE_ID = atoi(MP_ERP_TRAN_TYPE_ID_44);
					DBU_select_if_completion_trx(5, &IF_COMPLETION_TRX);
					if (DB_error_code == DB_SUCCESS)
					{
						if_end_in = TRS.add_node(in_node, "if_end_in");
						TRS.add_char(if_end_in, IN_PROCSTEP, '1');
						CopyDefaultMembers(if_end_in, in_node);

						TRS.add_char(if_end_in, "TRAN_FLAG", 'I');
						TRS.add_int(if_end_in, "ERP_WO_ID", IF_COMPLETION_TRX.ERP_WO_ID);
						TRS.add_string(if_end_in, "WO_ID", IF_COMPLETION_TRX.WO_ID, sizeof(IF_COMPLETION_TRX.WO_ID));
						TRS.add_string(if_end_in, "AREA_ID", IF_COMPLETION_TRX.AREA_ID, sizeof(IF_COMPLETION_TRX.AREA_ID));
						TRS.add_int(if_end_in, "ERP_AREA_ID", IF_COMPLETION_TRX.ERP_AREA_ID);
						TRS.add_int(if_end_in, "TRAN_TYPE_ID", atoi(MP_ERP_TRAN_TYPE_ID_17));
						TRS.add_string(if_end_in, "TRAN_TYPE", MP_ERP_TRAN_TYPE_44_WIP_COMPLETION, strlen(MP_ERP_TRAN_TYPE_44_WIP_COMPLETION));
						TRS.add_string(if_end_in, "INV_OPER", IF_COMPLETION_TRX.INV_OPER, sizeof(IF_COMPLETION_TRX.INV_OPER));
						TRS.add_int(if_end_in, "ERP_MAT_ID", IF_COMPLETION_TRX.ERP_MAT_ID);
						TRS.add_string(if_end_in, "MAT_ID", IF_COMPLETION_TRX.MAT_ID, sizeof(IF_COMPLETION_TRX.MAT_ID));
						TRS.add_string(if_end_in, "UNIT", IF_COMPLETION_TRX.UNIT, sizeof(IF_COMPLETION_TRX.UNIT));
						TRS.add_double(if_end_in, "QTY", IF_COMPLETION_TRX.QTY);
						TRS.add_string(if_end_in, "MES_OPER", IF_COMPLETION_TRX.MES_OPER, sizeof(IF_COMPLETION_TRX.MES_OPER));
						TRS.add_string(if_end_in, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

						cmn_out = TRS.create_node("Cmn_Out");
						if (CUS_IFS_COMPLETION_TRX(s_msg_code, if_end_in, cmn_out) == MP_FALSE)
						{
							TRS.clone(out_node, cmn_out);
							TRS.free_node(cmn_out);
							return MP_FALSE;
						}

						TRS.free_node(cmn_out);
					}
				}
				//그릿은 LOT을 새로 생성하기 때문에 BACK처리 할 필요없음. 
				//기타 출고처리 해야함. 
				else if (memcmp(MWIPOPRDEF.AREA_ID, gs_area_grt, strlen(gs_area_grt)) == MP_FALSE)
				{



				}

				//P급 정보 조회
				DBU_init_cwiplotrec(&CWIPLOTREC);
				TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
				DBU_select_cwiplotrec(4, &CWIPLOTREC);
				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC SELECT(4) ", DT_NOVALUESTRING);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

					return MP_FALSE;
				}

				// P급 처리 후 P급 정보 DELETE_FLAG 변경
				CWIPLOTREC.DELETE_FLAG = ' ';
				TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
				memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
				DBU_update_cwiplotrec(2, &CWIPLOTREC);

				if (DB_error_code != DB_SUCCESS)
				{
					strcpy(s_msg_code, "WIP-0004");
					TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_TRANS;
					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}




				// CTM P급 창고 끼리 이동할때 MOVE TRAN 발생하고 
				// 해당 이력 삭제 해야 하는 경우 CWIPLOTREC Table에 OLD_FLOW, OLD_OPER 로 UPDATE 해줘야 함.
				/* store 쪽 로직에 넣음.
				DBU_init_cwiplotrec(&CWIPLOTREC);
				memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(CWIPLOTREC.FACTORY));
				memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));
				DBU_select_cwiplotrec(2, &CWIPLOTREC);
				if (DB_error_code == DB_SUCCESS)
				{
					memcpy(CWIPLOTREC.TRAN_FLOW, MWIPLOTHISX.OLD_FLOW, sizeof(CWIPLOTREC.TRAN_FLOW));
					memcpy(CWIPLOTREC.TRAN_OPER, MWIPLOTHISX.OLD_OPER, sizeof(CWIPLOTREC.TRAN_OPER));
					memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));
					TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
					DBU_update_cwiplotrec(3, &CWIPLOTREC);
					if (DB_error_code != DB_SUCCESS)
					{
						//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
						strcpy(s_msg_code, "ADM-0004");
						TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", DT_NOVALUESTRING);
						TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
						TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);
						TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, CWIPLOTREC.HIST_SEQ);
						TRS.add_dberrmsg(out_node, DB_error_msg);

						COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
						return MP_FALSE;
					}
				}
				*/


			}
		}
	}

	else
	{

	}

	return MP_TRUE;
}

int WIP_DELETE_LOT_HISTORY_AFTER(char* s_msg_code, TRSNode* in_node, TRSNode* out_node)
{
	struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;	        //LOT 마스터
	struct MWIPLOTHISX_TAG  MWIPLOTHISX;	        //
	struct MWIPORDSTS_TAG  MWIPORDSTS;	        //
	struct CQCMISPSTS_TAG CQCMISPSTS;

	DBU_init_mwipordsts(&MWIPORDSTS);
	TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
	DBU_select_mwipordsts(1, &MWIPORDSTS);
	if (DB_error_code == DB_SUCCESS)
	{
		if (MWIPORDSTS.ORD_IN_QTY <= 0)
		{
			if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_START)
			{
				MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
			}

			MWIPORDSTS.ORD_IN_QTY = 0;
		}

		memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(MWIPORDSTS.UPDATE_TIME));
		TRS.copy(MWIPORDSTS.UPDATE_USER_ID, sizeof(MWIPORDSTS.UPDATE_USER_ID), in_node, IN_USERID);

		DBU_update_mwipordsts(1, &MWIPORDSTS);
		if (DB_error_code != DB_SUCCESS)
		{
			//ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
			strcpy(s_msg_code, "ADM-0004");
			TRS.add_fieldmsg(out_node, "MWIPORDSTS UPDATE(1) ", DT_NOVALUESTRING);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
			TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			return MP_FALSE;
		}
	}

	DBU_init_mwiplotstsx(&MWIPLOTSTSX);
	TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
	DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
	if (DB_error_code != DB_SUCCESS)
	{

		DBU_init_cqcmispsts(&CQCMISPSTS);
		TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
		TRS.copy(CQCMISPSTS.LOT_ID, sizeof(CQCMISPSTS.LOT_ID), in_node, "LOT_ID");
		DBU_select_cqcmispsts(2, &CQCMISPSTS);
		if (DB_error_code == DB_SUCCESS)
		{

			DBU_delete_cqcmispsts(1, &CQCMISPSTS);

		}

		return MP_TRUE;
	}

	DBU_init_mwiplothisx(&MWIPLOTHISX);
	memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
	MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;
	DBU_select_mwiplothisx(1, &MWIPLOTHISX);
	if (DB_error_code != DB_SUCCESS)
	{
		//WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
		strcpy(s_msg_code, "WIP-0044");
		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		gs_log_type.type = MP_LOG_ERROR;
		gs_log_type.e_type = MP_LOG_E_SYSTEM;
		gs_log_type.category = MP_LOG_CATE_VIEW;

		COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
		return MP_FALSE;
	}

	memcpy(MWIPLOTSTSX.LOT_CMF_1, MWIPLOTHISX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_2, MWIPLOTHISX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_3, MWIPLOTHISX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_4, MWIPLOTHISX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_5, MWIPLOTHISX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_6, MWIPLOTHISX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_7, MWIPLOTHISX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_8, MWIPLOTHISX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_9, MWIPLOTHISX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_10, MWIPLOTHISX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_11, MWIPLOTHISX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_12, MWIPLOTHISX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_13, MWIPLOTHISX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_14, MWIPLOTHISX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_15, MWIPLOTHISX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_16, MWIPLOTHISX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_17, MWIPLOTHISX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_18, MWIPLOTHISX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_19, MWIPLOTHISX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.LOT_CMF_20, MWIPLOTHISX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_1));
	memcpy(MWIPLOTSTSX.ADD_ORDER_ID_1, MWIPLOTHISX.ADD_ORDER_ID_1, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_1));
	memcpy(MWIPLOTSTSX.ADD_ORDER_ID_2, MWIPLOTHISX.ADD_ORDER_ID_2, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_2));
	memcpy(MWIPLOTSTSX.ADD_ORDER_ID_3, MWIPLOTHISX.ADD_ORDER_ID_3, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_3));
	memcpy(MWIPLOTSTSX.RESV_FIELD_1, MWIPLOTHISX.RESV_FIELD_1, sizeof(MWIPLOTSTSX.RESV_FIELD_1));
	memcpy(MWIPLOTSTSX.RESV_FIELD_2, MWIPLOTHISX.RESV_FIELD_2, sizeof(MWIPLOTSTSX.RESV_FIELD_2));
	memcpy(MWIPLOTSTSX.RESV_FIELD_3, MWIPLOTHISX.RESV_FIELD_3, sizeof(MWIPLOTSTSX.RESV_FIELD_3));
	memcpy(MWIPLOTSTSX.RESV_FIELD_4, MWIPLOTHISX.RESV_FIELD_4, sizeof(MWIPLOTSTSX.RESV_FIELD_4));
	memcpy(MWIPLOTSTSX.RESV_FIELD_5, MWIPLOTHISX.RESV_FIELD_5, sizeof(MWIPLOTSTSX.RESV_FIELD_5));
	MWIPLOTSTSX.RESV_FLAG_1 = MWIPLOTHISX.RESV_FLAG_1;
	MWIPLOTSTSX.RESV_FLAG_2 = MWIPLOTHISX.RESV_FLAG_2;
	MWIPLOTSTSX.RESV_FLAG_3 = MWIPLOTHISX.RESV_FLAG_3;
	MWIPLOTSTSX.RESV_FLAG_4 = MWIPLOTHISX.RESV_FLAG_4;
	MWIPLOTSTSX.RESV_FLAG_5 = MWIPLOTHISX.RESV_FLAG_5;

	//CTM CFM 저장
	memcpy(MWIPLOTSTSX.CTM_CMF_1, MWIPLOTHISX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_2, MWIPLOTHISX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_3, MWIPLOTHISX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_4, MWIPLOTHISX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_5, MWIPLOTHISX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_6, MWIPLOTHISX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_7, MWIPLOTHISX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_8, MWIPLOTHISX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_9, MWIPLOTHISX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_10, MWIPLOTHISX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_11, MWIPLOTHISX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_12, MWIPLOTHISX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_13, MWIPLOTHISX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_14, MWIPLOTHISX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_15, MWIPLOTHISX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_16, MWIPLOTHISX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_17, MWIPLOTHISX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_18, MWIPLOTHISX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_19, MWIPLOTHISX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	memcpy(MWIPLOTSTSX.CTM_CMF_20, MWIPLOTHISX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_1));
	//PDC CFM 저장
	memcpy(MWIPLOTSTSX.PDC_CMF_1, MWIPLOTHISX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_2, MWIPLOTHISX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_3, MWIPLOTHISX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_4, MWIPLOTHISX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_5, MWIPLOTHISX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_6, MWIPLOTHISX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_7, MWIPLOTHISX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_8, MWIPLOTHISX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_9, MWIPLOTHISX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_10, MWIPLOTHISX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_11, MWIPLOTHISX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_12, MWIPLOTHISX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_13, MWIPLOTHISX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_14, MWIPLOTHISX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_15, MWIPLOTHISX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_16, MWIPLOTHISX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_17, MWIPLOTHISX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_18, MWIPLOTHISX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_19, MWIPLOTHISX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	memcpy(MWIPLOTSTSX.PDC_CMF_20, MWIPLOTHISX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_1));
	//HM CFM 저장
	memcpy(MWIPLOTSTSX.HM_CMF_1, MWIPLOTHISX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_2, MWIPLOTHISX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_3, MWIPLOTHISX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_4, MWIPLOTHISX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_5, MWIPLOTHISX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_6, MWIPLOTHISX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_7, MWIPLOTHISX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_8, MWIPLOTHISX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_9, MWIPLOTHISX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_10, MWIPLOTHISX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_11, MWIPLOTHISX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_12, MWIPLOTHISX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_13, MWIPLOTHISX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_14, MWIPLOTHISX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_15, MWIPLOTHISX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_16, MWIPLOTHISX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_17, MWIPLOTHISX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_18, MWIPLOTHISX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_19, MWIPLOTHISX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_1));
	memcpy(MWIPLOTSTSX.HM_CMF_20, MWIPLOTHISX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_1));
	//GRIT CFM 저장
	memcpy(MWIPLOTSTSX.GRT_CMF_1, MWIPLOTHISX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_2, MWIPLOTHISX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_3, MWIPLOTHISX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_4, MWIPLOTHISX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_5, MWIPLOTHISX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_6, MWIPLOTHISX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_7, MWIPLOTHISX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_8, MWIPLOTHISX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_9, MWIPLOTHISX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_10, MWIPLOTHISX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_11, MWIPLOTHISX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_12, MWIPLOTHISX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_13, MWIPLOTHISX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_14, MWIPLOTHISX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_15, MWIPLOTHISX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_16, MWIPLOTHISX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_17, MWIPLOTHISX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_18, MWIPLOTHISX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_19, MWIPLOTHISX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_1));
	memcpy(MWIPLOTSTSX.GRT_CMF_20, MWIPLOTHISX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_1));

	DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
	if (DB_error_code != DB_SUCCESS)
	{
		memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
		TRS.add_dberrmsg(out_node, DB_error_msg);

		TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
		TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

		return MP_FALSE;
	}

	return MP_TRUE;
}