/*******************************************************************************

System      : MESplus
Module      : CUS_QCM
File Name   : CUS_QCM_view_lot_info.c
Description : View Lot Infomation function

MES Version : 5.0

Function List
- step 1: Lot id를 조회하여 lot 리스트 정보를 리턴한다. 


Detail Description
- 검사등록 화면에서  Lot을 스캔시  Lot에 대한 정보를 가져오는 서비스

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/09/02   KMS              Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_QCM_common.h"

int CUS_QCM_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_QCM_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_QCM_View_Lot_Info()
- View Lot Info
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_View_Lot_Info(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_QCM_VIEW_LOT_INFO(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_QCM_View_Lot_Info", out_node);
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
CUS_QCM_VIEW_LOT_INFO()
- Main sub function of "CUS_QCM_View_Lot_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;      //공정 LOT 
	struct MINVDLVLOT_TAG MINVDLVLOT;       //DLV LOT
    //struct MINVLOTSTS_TAG MINVLOTSTS;       //자재 LOT

	struct MWIPMATDEF_TAG MWIPMATDEF; //품목
	struct MWIPMATDEF_TAG MWIPMATDEF_D; //실제직경 참조 값
	struct MWIPOPRDEF_TAG MWIPOPRDEF; //공정
	struct MWIPOPRDEF_TAG MWIPOPRDEF_ISP; // 검사 공정
	struct MRASRESDEF_TAG MRASRESDEF; //설비
	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	

	struct CQCMISPSTS_TAG CQCMISPSTS;
	struct MWIPCOLDEF_TAG MWIPCOLDEF;
	struct MEDCCOLDEF_TAG MEDCCOLDEF ;

	struct CQCMGRTSIV_TAG CQCMGRTSIV;
	struct CQCMGRTHLT_TAG CQCMGRTHLT;

	struct MWIPOPRDEF_TAG MWIPOPRDEF_RWK;
    

    //TRSNode *list_item;
	char s_insp_type[30];

	int i_psd_cnt;
	int i_bi_cnt;
	int i_bti_cnt;
	int i_hlt_cnt;

	double d_real_d_ref;


    LOG_head("CUS_QCM_View_Lot_Info");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_QCM_View_Lot_Info_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

	memset(s_insp_type, ' ', sizeof(s_insp_type));

    //Lot 조회
	if (TRS.get_procstep(in_node) == '1')
	{
		DBU_init_mwiplotstsx(&MWIPLOTSTS);
		TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
		DBU_select_mwiplotstsx(1, &MWIPLOTSTS);
		if (DB_error_code == DB_SUCCESS)
		{

			


			DBU_init_mwipoprdef(&MWIPOPRDEF);
			TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF.OPER, MWIPLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF);

			DBU_init_mrasresdef(&MRASRESDEF);
			TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MRASRESDEF.RES_ID, MWIPLOTSTS.END_RES_ID, sizeof(MRASRESDEF.RES_ID));
			DBU_select_mrasresdef(1, &MRASRESDEF);

			DBU_init_cqcmispsts(&CQCMISPSTS);
			TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMISPSTS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.copy(CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER), in_node, "OPER");
			//TRS.copy(CQCMISPSTS.INSP_TYPE, sizeof(CQCMISPSTS.INSP_TYPE), in_node, "INSP_TYPE");
			DBU_select_cqcmispsts(3, &CQCMISPSTS);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "QCM-0067"); //이 Lot의 검사요청이 존재하지 않습니다.
				}
				else
				{
					strcpy(s_msg_code, "QCM-0004");
				}
				TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
				TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}


			DBU_init_mwipmatdef(&MWIPMATDEF);
			TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			MWIPMATDEF.MAT_VER = CQCMISPSTS.MAT_VER;
			DBU_select_mwipmatdef(1, &MWIPMATDEF);


			DBU_init_mwipmatdef(&MWIPMATDEF_D);
			TRS.copy(MWIPMATDEF_D.FACTORY, sizeof(MWIPMATDEF_D.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPMATDEF_D.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			MWIPMATDEF_D.MAT_VER = CQCMISPSTS.MAT_VER;
			d_real_d_ref = DBU_select_mwipmatdef_scalar(2, &MWIPMATDEF_D);


			//memcmp(MWIPORDSTS.FLOW, TRS.get_string(in_node, "FLOW"), strlen(TRS.get_string(in_node, "FLOW"))) != MP_FALSE
			/*
			if (memcmp(CQCMISPSTS.INSP_TYPE, TRS.get_string(in_node, "INSP_TYPE"), strlen(TRS.get_string(in_node, "INSP_TYPE"))) != 0)
			{
				strcpy(s_msg_code, "QCM-0051");
				TRS.add_fieldmsg(out_node, "INSP_TYPE", MP_STR, sizeof(CQCMISPSTS.INSP_TYPE),CQCMISPSTS.INSP_TYPE);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}*/

			DBU_init_mwipoprdef(&MWIPOPRDEF_ISP);
			TRS.copy(MWIPOPRDEF_ISP.FACTORY, sizeof(MWIPOPRDEF_ISP.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPOPRDEF_ISP.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
			DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISP);
			/*
			if(COM_isnullspace(MWIPOPRDEF_ISP.OPER_CMF_5) == MP_TRUE)
			{
				strcpy(s_msg_code, "QCM-0068");
				TRS.add_fieldmsg(out_node, "INSP_OPER", MP_STR, sizeof(MWIPOPRDEF_ISP.OPER), MWIPOPRDEF_ISP.OPER);
				TRS.add_fieldmsg(out_node, "OPER_DESC", MP_STR, sizeof(MWIPOPRDEF_ISP.OPER_DESC), MWIPOPRDEF_ISP.OPER_DESC);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			*/

			
			


			/*
			if (memcmp(MWIPOPRDEF_ISP.AREA_ID, TRS.get_string(in_node, "AREA_ID"), strlen(TRS.get_string(in_node, "AREA_ID"))) != 0)
			{
				strcpy(s_msg_code, "QCM-0052");
				TRS.add_fieldmsg(out_node, "Department", MP_STR, sizeof(MWIPOPRDEF_ISP.AREA_ID), MWIPOPRDEF_ISP.AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			if (memcmp(MWIPOPRDEF_ISP.SUB_AREA_ID, TRS.get_string(in_node, "SUB_AREA_ID"), strlen(TRS.get_string(in_node, "SUB_AREA_ID"))) != 0)
			{
				strcpy(s_msg_code, "QCM-0053");
				TRS.add_fieldmsg(out_node, "WorkPlace", MP_STR, sizeof(MWIPOPRDEF_ISP.SUB_AREA_ID), MWIPOPRDEF_ISP.SUB_AREA_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_VALIDATION;
				gs_log_type.category = MP_LOG_CATE_COMMON;
				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}*/

			DBU_init_mwipcoldef(&MWIPCOLDEF);
			TRS.copy(MWIPCOLDEF.FACTORY, sizeof(MWIPCOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MWIPCOLDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			MWIPCOLDEF.MAT_VER = 1;
			memcpy(MWIPCOLDEF.OPER, MWIPOPRDEF_ISP.OPER, sizeof(MWIPOPRDEF_ISP.OPER));
			MWIPCOLDEF.OPT_LEVEL = '4'; // mat_id , oper  level
			MWIPCOLDEF.DISABLE_FLAG = 'N';
			DBU_select_mwipcoldef(2, &MWIPCOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "QCM-0063");
				}
				else
				{
					strcpy(s_msg_code, "QCM-0004");
				}
				TRS.add_fieldmsg(out_node, "MWIPCOLDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CQCMISPSTS.MAT_ID), CQCMISPSTS.MAT_ID);
				TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISP.OPER), MWIPOPRDEF_ISP.OPER);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			DBU_init_medccoldef(&MEDCCOLDEF);
			TRS.copy(MEDCCOLDEF.FACTORY, sizeof(MEDCCOLDEF.FACTORY), in_node, IN_FACTORY);
			memcpy(MEDCCOLDEF.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			DBU_select_medccoldef(1, &MEDCCOLDEF);
			if (DB_error_code != DB_SUCCESS)
			{
				/*
				if (DB_error_code == DB_NOT_FOUND)
				{
				}
				else
				{
				}*/
				strcpy(s_msg_code, "QCM-0004");
				TRS.add_fieldmsg(out_node, "MEDCCOLDEF SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLDEF.FACTORY), MEDCCOLDEF.FACTORY);
				TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLDEF.COL_SET_ID), MEDCCOLDEF.COL_SET_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}

			//(1) Grit PSD, BI, BTI 검사차수 가져오기
			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "PSD", strlen("PSD"));
			i_psd_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
			if (i_psd_cnt == 0)
			{
				i_psd_cnt = 1;
			}

			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "BI", strlen("BI"));
			i_bi_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
			if(i_bi_cnt == 0)
			{
				i_bi_cnt = 1;
			}

			DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
			TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "BTI", strlen("BTI"));
			i_bti_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
			if (i_bti_cnt == 0)
			{
				i_bti_cnt = 1;
			}

			DBU_init_cqcmgrthlt(&CQCMGRTHLT);
			TRS.copy(CQCMGRTHLT.FACTORY, sizeof(CQCMGRTHLT.FACTORY), in_node, IN_FACTORY);
			memcpy(CQCMGRTHLT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			memcpy(CQCMGRTHLT.INSP_DTL_TYPE, "HLT", strlen("HLT"));
			i_hlt_cnt = (int)DBU_select_cqcmgrthlt_scalar(2, &CQCMGRTHLT);
			if (i_hlt_cnt == 0)
			{
				i_hlt_cnt = 1;
			}

			
			

			// 품목, 공정별 COL_SET_ID
			TRS.add_string(out_node, "COL_SET_ID", MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
			TRS.add_string(out_node, "COL_SET_DESC", MEDCCOLDEF.COL_SET_DESC, sizeof(MEDCCOLDEF.COL_SET_DESC));

			TRS.add_string(out_node, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
			TRS.add_string(out_node, "SIZES", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
			TRS.add_string(out_node, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));

			TRS.add_string(out_node, "MAT_CMF_4", MWIPMATDEF.MAT_CMF_4, sizeof(MWIPMATDEF.MAT_CMF_4));
			TRS.add_string(out_node, "MAT_CMF_5", MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5));
			TRS.add_string(out_node, "MAT_CMF_6", MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6));
			TRS.add_string(out_node, "MAT_CMF_7", MWIPMATDEF.MAT_CMF_7, sizeof(MWIPMATDEF.MAT_CMF_7));
			TRS.add_string(out_node, "MAT_CMF_8", MWIPMATDEF.MAT_CMF_8, sizeof(MWIPMATDEF.MAT_CMF_8));
			TRS.add_string(out_node, "MAT_CMF_9", MWIPMATDEF.MAT_CMF_9, sizeof(MWIPMATDEF.MAT_CMF_9));
			TRS.add_string(out_node, "MAT_CMF_10", MWIPMATDEF.MAT_CMF_10, sizeof(MWIPMATDEF.MAT_CMF_10));
			TRS.add_string(out_node, "MAT_CMF_11", MWIPMATDEF.MAT_CMF_11, sizeof(MWIPMATDEF.MAT_CMF_11));
			TRS.add_string(out_node, "MAT_CMF_12", MWIPMATDEF.MAT_CMF_12, sizeof(MWIPMATDEF.MAT_CMF_12));
			TRS.add_string(out_node, "MAT_CMF_13", MWIPMATDEF.MAT_CMF_13, sizeof(MWIPMATDEF.MAT_CMF_13));
			TRS.add_string(out_node, "MAT_CMF_14", MWIPMATDEF.MAT_CMF_14, sizeof(MWIPMATDEF.MAT_CMF_14));
			TRS.add_string(out_node, "MAT_CMF_15", MWIPMATDEF.MAT_CMF_15, sizeof(MWIPMATDEF.MAT_CMF_15));

			TRS.add_string(out_node, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));

			TRS.add_double(out_node, "REAL_D_REF", d_real_d_ref);

			TRS.add_string(out_node, "LOT_KIND", "W", strlen("W"));
			TRS.add_string(out_node, "LOT_ID", MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
			TRS.add_string(out_node, "LOT_DESC", MWIPLOTSTS.LOT_DESC, sizeof(MWIPLOTSTS.LOT_DESC));
			TRS.add_string(out_node, "FACTORY", MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY));
			TRS.add_string(out_node, "MAT_ID", CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
			TRS.add_int(out_node, "MAT_VER", MWIPLOTSTS.MAT_VER);
			TRS.add_string(out_node, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
			TRS.add_string(out_node, "MAT_TYPE", MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
			TRS.add_string(out_node, "FLOW", MWIPLOTSTS.FLOW, sizeof(MWIPLOTSTS.FLOW));
			TRS.add_int(out_node, "FLOW_SEQ_NUM", MWIPLOTSTS.FLOW_SEQ_NUM);
			TRS.add_string(out_node, "OPER", MWIPLOTSTS.OPER, sizeof(MWIPLOTSTS.OPER));
			TRS.add_string(out_node, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
			TRS.add_double(out_node, "QTY_1", MWIPLOTSTS.QTY_1);
			TRS.add_double(out_node, "QTY_2", MWIPLOTSTS.QTY_2);
			TRS.add_double(out_node, "QTY_3", MWIPLOTSTS.QTY_3);
			TRS.add_char(out_node, "LOT_TYPE", MWIPLOTSTS.LOT_TYPE);
			TRS.add_string(out_node, "OWNER_CODE", MWIPLOTSTS.OWNER_CODE, sizeof(MWIPLOTSTS.OWNER_CODE));
			TRS.add_string(out_node, "CREATE_CODE", MWIPLOTSTS.CREATE_CODE, sizeof(MWIPLOTSTS.CREATE_CODE));
			TRS.add_char(out_node, "LOT_PRIORITY", MWIPLOTSTS.LOT_PRIORITY);
			TRS.add_string(out_node, "LOT_STATUS", MWIPLOTSTS.LOT_STATUS, sizeof(MWIPLOTSTS.LOT_STATUS));
			TRS.add_char(out_node, "HOLD_FLAG", MWIPLOTSTS.HOLD_FLAG);
			TRS.add_string(out_node, "HOLD_CODE", MWIPLOTSTS.HOLD_CODE, sizeof(MWIPLOTSTS.HOLD_CODE));
			TRS.add_string(out_node, "HOLD_PRV_GRP_ID", MWIPLOTSTS.HOLD_PRV_GRP_ID, sizeof(MWIPLOTSTS.HOLD_PRV_GRP_ID));
			TRS.add_enc_string(out_node, "HOLD_PASSWORD", MWIPLOTSTS.HOLD_PASSWORD, sizeof(MWIPLOTSTS.HOLD_PASSWORD));
			TRS.add_double(out_node, "OPER_IN_QTY_1", MWIPLOTSTS.OPER_IN_QTY_1);
			TRS.add_double(out_node, "OPER_IN_QTY_2", MWIPLOTSTS.OPER_IN_QTY_2);
			TRS.add_double(out_node, "OPER_IN_QTY_3", MWIPLOTSTS.OPER_IN_QTY_3);
			TRS.add_double(out_node, "CREATE_QTY_1", MWIPLOTSTS.CREATE_QTY_1);
			TRS.add_double(out_node, "CREATE_QTY_2", MWIPLOTSTS.CREATE_QTY_2);
			TRS.add_double(out_node, "CREATE_QTY_3", MWIPLOTSTS.CREATE_QTY_3);
			TRS.add_double(out_node, "START_QTY_1", MWIPLOTSTS.START_QTY_1);
			TRS.add_double(out_node, "START_QTY_2", MWIPLOTSTS.START_QTY_2);
			TRS.add_double(out_node, "START_QTY_3", MWIPLOTSTS.START_QTY_3);
			TRS.add_char(out_node, "INV_FLAG", MWIPLOTSTS.INV_FLAG);
			TRS.add_char(out_node, "TRANSIT_FLAG", MWIPLOTSTS.TRANSIT_FLAG);
			TRS.add_char(out_node, "UNIT_EXIST_FLAG", MWIPLOTSTS.UNIT_EXIST_FLAG);
			TRS.add_string(out_node, "INV_UNIT", MWIPLOTSTS.INV_UNIT, sizeof(MWIPLOTSTS.INV_UNIT));
			TRS.add_char(out_node, "RWK_FLAG", MWIPLOTSTS.RWK_FLAG);
			TRS.add_string(out_node, "RWK_CODE", MWIPLOTSTS.RWK_CODE, sizeof(MWIPLOTSTS.RWK_CODE));
			TRS.add_int(out_node, "RWK_COUNT", MWIPLOTSTS.RWK_COUNT);
			TRS.add_string(out_node, "RWK_RET_FLOW", MWIPLOTSTS.RWK_RET_FLOW, sizeof(MWIPLOTSTS.RWK_RET_FLOW));
			TRS.add_int(out_node, "RWK_RET_FLOW_SEQ_NUM", MWIPLOTSTS.RWK_RET_FLOW_SEQ_NUM);
			TRS.add_string(out_node, "RWK_RET_OPER", MWIPLOTSTS.RWK_RET_OPER, sizeof(MWIPLOTSTS.RWK_RET_OPER));
			TRS.add_string(out_node, "RWK_END_FLOW", MWIPLOTSTS.RWK_END_FLOW, sizeof(MWIPLOTSTS.RWK_END_FLOW));
			TRS.add_int(out_node, "RWK_END_FLOW_SEQ_NUM", MWIPLOTSTS.RWK_END_FLOW_SEQ_NUM);
			TRS.add_string(out_node, "RWK_END_OPER", MWIPLOTSTS.RWK_END_OPER, sizeof(MWIPLOTSTS.RWK_END_OPER));
			TRS.add_char(out_node, "RWK_RET_CLEAR_FLAG", MWIPLOTSTS.RWK_RET_CLEAR_FLAG);
			TRS.add_string(out_node, "RWK_TIME", MWIPLOTSTS.RWK_TIME, sizeof(MWIPLOTSTS.RWK_TIME));
			TRS.add_char(out_node, "NSTD_FLAG", MWIPLOTSTS.NSTD_FLAG);
			TRS.add_string(out_node, "NSTD_RET_FLOW", MWIPLOTSTS.NSTD_RET_FLOW, sizeof(MWIPLOTSTS.NSTD_RET_FLOW));
			TRS.add_int(out_node, "NSTD_RET_FLOW_SEQ_NUM", MWIPLOTSTS.NSTD_RET_FLOW_SEQ_NUM);
			TRS.add_string(out_node, "NSTD_RET_OPER", MWIPLOTSTS.NSTD_RET_OPER, sizeof(MWIPLOTSTS.NSTD_RET_OPER));
			TRS.add_string(out_node, "NSTD_TIME", MWIPLOTSTS.NSTD_TIME, sizeof(MWIPLOTSTS.NSTD_TIME));
			TRS.add_char(out_node, "REP_FLAG", MWIPLOTSTS.REP_FLAG);
			TRS.add_string(out_node, "REP_RET_OPER", MWIPLOTSTS.REP_RET_OPER, sizeof(MWIPLOTSTS.REP_RET_OPER));
			TRS.add_string(out_node, "STR_RET_FLOW", MWIPLOTSTS.STR_RET_FLOW, sizeof(MWIPLOTSTS.STR_RET_FLOW));
			TRS.add_int(out_node, "STR_RET_FLOW_SEQ_NUM", MWIPLOTSTS.STR_RET_FLOW_SEQ_NUM);
			TRS.add_string(out_node, "STR_RET_OPER", MWIPLOTSTS.STR_RET_OPER, sizeof(MWIPLOTSTS.STR_RET_OPER));
			TRS.add_char(out_node, "START_FLAG", MWIPLOTSTS.START_FLAG);
			TRS.add_string(out_node, "START_TIME", MWIPLOTSTS.START_TIME, sizeof(MWIPLOTSTS.START_TIME));
			TRS.add_string(out_node, "START_RES_ID", MWIPLOTSTS.START_RES_ID, sizeof(MWIPLOTSTS.START_RES_ID));
			TRS.add_char(out_node, "END_FLAG", MWIPLOTSTS.END_FLAG);
			TRS.add_string(out_node, "END_TIME", MWIPLOTSTS.END_TIME, sizeof(MWIPLOTSTS.END_TIME));
			TRS.add_string(out_node, "END_RES_ID", MWIPLOTSTS.END_RES_ID, sizeof(MWIPLOTSTS.END_RES_ID));
			TRS.add_string(out_node, "RES_ID", MWIPLOTSTS.END_RES_ID, sizeof(MWIPLOTSTS.END_RES_ID));
			TRS.add_string(out_node, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
			TRS.add_char(out_node, "SAMPLE_FLAG", MWIPLOTSTS.SAMPLE_FLAG);
			TRS.add_char(out_node, "SAMPLE_WAIT_FLAG", MWIPLOTSTS.SAMPLE_WAIT_FLAG);
			TRS.add_char(out_node, "SAMPLE_RESULT", MWIPLOTSTS.SAMPLE_RESULT);
			TRS.add_char(out_node, "FROM_TO_FLAG", MWIPLOTSTS.FROM_TO_FLAG);
			TRS.add_string(out_node, "FROM_TO_LOT_ID", MWIPLOTSTS.FROM_TO_LOT_ID, sizeof(MWIPLOTSTS.FROM_TO_LOT_ID));
			TRS.add_string(out_node, "SHIP_CODE", MWIPLOTSTS.SHIP_CODE, sizeof(MWIPLOTSTS.SHIP_CODE));
			TRS.add_string(out_node, "SHIP_TIME", MWIPLOTSTS.SHIP_TIME, sizeof(MWIPLOTSTS.SHIP_TIME));
			TRS.add_string(out_node, "ORG_DUE_TIME", MWIPLOTSTS.ORG_DUE_TIME, sizeof(MWIPLOTSTS.ORG_DUE_TIME));
			TRS.add_string(out_node, "SCH_DUE_TIME", MWIPLOTSTS.SCH_DUE_TIME, sizeof(MWIPLOTSTS.SCH_DUE_TIME));
			TRS.add_string(out_node, "CREATE_TIME", MWIPLOTSTS.CREATE_TIME, sizeof(MWIPLOTSTS.CREATE_TIME));
			TRS.add_string(out_node, "FAC_IN_TIME", MWIPLOTSTS.FAC_IN_TIME, sizeof(MWIPLOTSTS.FAC_IN_TIME));
			TRS.add_string(out_node, "FLOW_IN_TIME", MWIPLOTSTS.FLOW_IN_TIME, sizeof(MWIPLOTSTS.FLOW_IN_TIME));
			TRS.add_string(out_node, "OPER_IN_TIME", MWIPLOTSTS.OPER_IN_TIME, sizeof(MWIPLOTSTS.OPER_IN_TIME));
			TRS.add_string(out_node, "RESERVE_RES_ID", MWIPLOTSTS.RESERVE_RES_ID, sizeof(MWIPLOTSTS.RESERVE_RES_ID));
			TRS.add_string(out_node, "PORT_ID", MWIPLOTSTS.PORT_ID, sizeof(MWIPLOTSTS.PORT_ID));
			TRS.add_string(out_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
			TRS.add_string(out_node, "ADD_ORDER_ID_1", MWIPLOTSTS.ADD_ORDER_ID_1, sizeof(MWIPLOTSTS.ADD_ORDER_ID_1));
			TRS.add_string(out_node, "ADD_ORDER_ID_2", MWIPLOTSTS.ADD_ORDER_ID_2, sizeof(MWIPLOTSTS.ADD_ORDER_ID_2));
			TRS.add_string(out_node, "ADD_ORDER_ID_3", MWIPLOTSTS.ADD_ORDER_ID_3, sizeof(MWIPLOTSTS.ADD_ORDER_ID_3));
			TRS.add_string(out_node, "LOT_LOCATION_1", MWIPLOTSTS.LOT_LOCATION_1, sizeof(MWIPLOTSTS.LOT_LOCATION_1));
			TRS.add_string(out_node, "LOT_LOCATION_2", MWIPLOTSTS.LOT_LOCATION_2, sizeof(MWIPLOTSTS.LOT_LOCATION_2));
			TRS.add_string(out_node, "LOT_LOCATION_3", MWIPLOTSTS.LOT_LOCATION_3, sizeof(MWIPLOTSTS.LOT_LOCATION_3));
			TRS.add_string(out_node, "LOT_CMF_1", MWIPLOTSTS.LOT_CMF_1, sizeof(MWIPLOTSTS.LOT_CMF_1));
			TRS.add_string(out_node, "LOT_CMF_2", MWIPLOTSTS.LOT_CMF_2, sizeof(MWIPLOTSTS.LOT_CMF_2));
			TRS.add_string(out_node, "LOT_CMF_3", MWIPLOTSTS.LOT_CMF_3, sizeof(MWIPLOTSTS.LOT_CMF_3));
			TRS.add_string(out_node, "LOT_CMF_4", MWIPLOTSTS.LOT_CMF_4, sizeof(MWIPLOTSTS.LOT_CMF_4));
			TRS.add_string(out_node, "LOT_CMF_5", MWIPLOTSTS.LOT_CMF_5, sizeof(MWIPLOTSTS.LOT_CMF_5));
			TRS.add_string(out_node, "LOT_CMF_6", MWIPLOTSTS.LOT_CMF_6, sizeof(MWIPLOTSTS.LOT_CMF_6));
			TRS.add_string(out_node, "LOT_CMF_7", MWIPLOTSTS.LOT_CMF_7, sizeof(MWIPLOTSTS.LOT_CMF_7));
			TRS.add_string(out_node, "LOT_CMF_8", MWIPLOTSTS.LOT_CMF_8, sizeof(MWIPLOTSTS.LOT_CMF_8));
			TRS.add_string(out_node, "LOT_CMF_9", MWIPLOTSTS.LOT_CMF_9, sizeof(MWIPLOTSTS.LOT_CMF_9));
			TRS.add_string(out_node, "LOT_CMF_10", MWIPLOTSTS.LOT_CMF_10, sizeof(MWIPLOTSTS.LOT_CMF_10));
			TRS.add_string(out_node, "LOT_CMF_11", MWIPLOTSTS.LOT_CMF_11, sizeof(MWIPLOTSTS.LOT_CMF_11));
			TRS.add_string(out_node, "LOT_CMF_12", MWIPLOTSTS.LOT_CMF_12, sizeof(MWIPLOTSTS.LOT_CMF_12));
			TRS.add_string(out_node, "LOT_CMF_13", MWIPLOTSTS.LOT_CMF_13, sizeof(MWIPLOTSTS.LOT_CMF_13));
			TRS.add_string(out_node, "LOT_CMF_14", MWIPLOTSTS.LOT_CMF_14, sizeof(MWIPLOTSTS.LOT_CMF_14));
			TRS.add_string(out_node, "LOT_CMF_15", MWIPLOTSTS.LOT_CMF_15, sizeof(MWIPLOTSTS.LOT_CMF_15));
			TRS.add_string(out_node, "LOT_CMF_16", MWIPLOTSTS.LOT_CMF_16, sizeof(MWIPLOTSTS.LOT_CMF_16));
			TRS.add_string(out_node, "LOT_CMF_17", MWIPLOTSTS.LOT_CMF_17, sizeof(MWIPLOTSTS.LOT_CMF_17));
			TRS.add_string(out_node, "LOT_CMF_18", MWIPLOTSTS.LOT_CMF_18, sizeof(MWIPLOTSTS.LOT_CMF_18));
			TRS.add_string(out_node, "LOT_CMF_19", MWIPLOTSTS.LOT_CMF_19, sizeof(MWIPLOTSTS.LOT_CMF_19));
			TRS.add_string(out_node, "LOT_CMF_20", MWIPLOTSTS.LOT_CMF_20, sizeof(MWIPLOTSTS.LOT_CMF_20));
			TRS.add_char(out_node, "LOT_DEL_FLAG", MWIPLOTSTS.LOT_DEL_FLAG);
			TRS.add_string(out_node, "LOT_DEL_CODE", MWIPLOTSTS.LOT_DEL_CODE, sizeof(MWIPLOTSTS.LOT_DEL_CODE));
			TRS.add_string(out_node, "LOT_DEL_TIME", MWIPLOTSTS.LOT_DEL_TIME, sizeof(MWIPLOTSTS.LOT_DEL_TIME));
			TRS.add_string(out_node, "LAST_TRAN_CODE", MWIPLOTSTS.LAST_TRAN_CODE, sizeof(MWIPLOTSTS.LAST_TRAN_CODE));
			TRS.add_string(out_node, "LAST_TRAN_TIME", MWIPLOTSTS.LAST_TRAN_TIME, sizeof(MWIPLOTSTS.LAST_TRAN_TIME));
			TRS.add_string(out_node, "LAST_COMMENT", MWIPLOTSTS.LAST_COMMENT, sizeof(MWIPLOTSTS.LAST_COMMENT));
			TRS.add_int(out_node, "LAST_ACTIVE_HIST_SEQ", MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ);
			TRS.add_int(out_node, "LAST_HIST_SEQ", MWIPLOTSTS.LAST_HIST_SEQ);
			TRS.add_string(out_node, "BOM_SET_ID", MWIPLOTSTS.BOM_SET_ID, sizeof(MWIPLOTSTS.BOM_SET_ID));
			TRS.add_int(out_node, "BOM_SET_VERSION", MWIPLOTSTS.BOM_SET_VERSION);
			TRS.add_int(out_node, "BOM_HIST_SEQ", MWIPLOTSTS.BOM_HIST_SEQ);
			TRS.add_int(out_node, "BOM_ACTIVE_HIST_SEQ", MWIPLOTSTS.BOM_ACTIVE_HIST_SEQ);
			TRS.add_string(out_node, "CRITICAL_RES_ID", MWIPLOTSTS.CRITICAL_RES_ID, sizeof(MWIPLOTSTS.CRITICAL_RES_ID));
			TRS.add_string(out_node, "CRITICAL_RES_GROUP_ID", MWIPLOTSTS.CRITICAL_RES_GROUP_ID, sizeof(MWIPLOTSTS.CRITICAL_RES_GROUP_ID));
			TRS.add_string(out_node, "SAVE_RES_ID_1", MWIPLOTSTS.SAVE_RES_ID_1, sizeof(MWIPLOTSTS.SAVE_RES_ID_1));
			TRS.add_string(out_node, "SAVE_RES_ID_2", MWIPLOTSTS.SAVE_RES_ID_2, sizeof(MWIPLOTSTS.SAVE_RES_ID_2));
			TRS.add_string(out_node, "SUBRES_ID", MWIPLOTSTS.SUBRES_ID, sizeof(MWIPLOTSTS.SUBRES_ID));
			TRS.add_string(out_node, "LOT_GROUP_ID_1", MWIPLOTSTS.LOT_GROUP_ID_1, sizeof(MWIPLOTSTS.LOT_GROUP_ID_1));
			TRS.add_string(out_node, "LOT_GROUP_ID_2", MWIPLOTSTS.LOT_GROUP_ID_2, sizeof(MWIPLOTSTS.LOT_GROUP_ID_2));
			TRS.add_string(out_node, "LOT_GROUP_ID_3", MWIPLOTSTS.LOT_GROUP_ID_3, sizeof(MWIPLOTSTS.LOT_GROUP_ID_3));
			TRS.add_double(out_node, "YIELD_1", MWIPLOTSTS.YIELD_1);
			TRS.add_double(out_node, "YIELD_2", MWIPLOTSTS.YIELD_2);
			TRS.add_double(out_node, "YIELD_3", MWIPLOTSTS.YIELD_3);
			TRS.add_double(out_node, "GOOD_QTY", MWIPLOTSTS.GOOD_QTY);
			TRS.add_string(out_node, "RESV_FIELD_1", MWIPLOTSTS.RESV_FIELD_1, sizeof(MWIPLOTSTS.RESV_FIELD_1));
			TRS.add_string(out_node, "RESV_FIELD_2", MWIPLOTSTS.RESV_FIELD_2, sizeof(MWIPLOTSTS.RESV_FIELD_2));
			TRS.add_string(out_node, "RESV_FIELD_3", MWIPLOTSTS.RESV_FIELD_3, sizeof(MWIPLOTSTS.RESV_FIELD_3));
			TRS.add_string(out_node, "RESV_FIELD_4", MWIPLOTSTS.RESV_FIELD_4, sizeof(MWIPLOTSTS.RESV_FIELD_4));
			TRS.add_string(out_node, "RESV_FIELD_5", MWIPLOTSTS.RESV_FIELD_5, sizeof(MWIPLOTSTS.RESV_FIELD_5));
			TRS.add_char(out_node, "RESV_FLAG_1", MWIPLOTSTS.RESV_FLAG_1);
			TRS.add_char(out_node, "RESV_FLAG_2", MWIPLOTSTS.RESV_FLAG_2);
			TRS.add_char(out_node, "RESV_FLAG_3", MWIPLOTSTS.RESV_FLAG_3);
			TRS.add_char(out_node, "RESV_FLAG_4", MWIPLOTSTS.RESV_FLAG_4);
			TRS.add_char(out_node, "RESV_FLAG_5", MWIPLOTSTS.RESV_FLAG_5);

			TRS.add_string(out_node, "INSP_ID", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
			TRS.add_char(out_node, "INSP_STATUS", CQCMISPSTS.INSP_STATUS);
			TRS.add_double(out_node, "INSP_QTY", CQCMISPSTS.QTY);
			TRS.add_string(out_node, "INSP_OPER", CQCMISPSTS.INSP_OPER,sizeof(CQCMISPSTS.INSP_OPER));
			TRS.add_string(out_node, "INSP_OPER_DESC", MWIPOPRDEF_ISP.OPER_DESC, sizeof(MWIPOPRDEF_ISP.OPER_DESC));
			TRS.add_string(out_node, "INSP_SAMPLE_GRADE", CQCMISPSTS.CMF_7, sizeof(CQCMISPSTS.CMF_7));
			TRS.add_string(out_node, "INSP_SAMPLE_SIZE", CQCMISPSTS.CMF_8, sizeof(CQCMISPSTS.CMF_8));

			TRS.add_char(out_node, "INSP_JUDGE_FLAG", CQCMISPSTS.INSP_JUDGE_FLAG);
			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, "C_INSP_JUDGE", strlen("C_INSP_JUDGE"));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF_ISP.OPER, sizeof(MWIPOPRDEF_ISP.OPER));
			MGCMTBLDAT.KEY_2[0] = CQCMISPSTS.INSP_JUDGE_FLAG;
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			TRS.add_string(out_node, "INSP_JUDGE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));



			TRS.add_string(out_node, "RWK_OPER", CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER));
			if (COM_isnullspace(CQCMISPSTS.RWK_OPER) != MP_TRUE)
			{
				DBU_init_mwipoprdef(&MWIPOPRDEF_RWK);
				TRS.copy(MWIPOPRDEF_RWK.FACTORY, sizeof(MWIPOPRDEF_RWK.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_RWK.OPER, CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_RWK);

				TRS.add_string(out_node, "RWK_OPER_DESC", MWIPOPRDEF_RWK.OPER_DESC, sizeof(MWIPOPRDEF_RWK.OPER_DESC));

			}
			







			TRS.add_string(out_node, "INSP_COMMENT", CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT));

			TRS.add_string(out_node, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));

			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_INSP_STATUS, strlen(MP_GCM_INSP_STATUS));
			MGCMTBLDAT.KEY_1[0] = CQCMISPSTS.INSP_STATUS;
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			TRS.add_string(out_node, "INSP_STATUS_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));


			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			TRS.add_string(out_node, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
			TRS.add_string(out_node, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

			TRS.add_string(out_node, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

			DBU_init_mgcmtbldat(&MGCMTBLDAT);
			TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_INSP_GRIT_SIZE, strlen(MP_GCM_INSP_GRIT_SIZE));
			memcpy(MGCMTBLDAT.KEY_1, MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
			DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
			if (MGCMTBLDAT.DATA_1[0] == 'Y')
			{
				TRS.add_char(out_node, "DOUBLE_SIZE", MGCMTBLDAT.DATA_1[0]);
				TRS.add_string(out_node, "SIZE_1", MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2));
				TRS.add_string(out_node, "SIZE_2", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));
			}
			else
			{
				TRS.add_char(out_node, "DOUBLE_SIZE", 'N');
				TRS.add_string(out_node, "SIZE_1", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				//TRS.add_string(out_node, "SIZE_2", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));
			}

		


			TRS.add_int(out_node, "INSP_COUNT_PSD", i_psd_cnt);
			TRS.add_int(out_node, "INSP_COUNT_BI", i_bi_cnt);
			TRS.add_int(out_node, "INSP_COUNT_BTI", i_bti_cnt);
			TRS.add_int(out_node, "INSP_COUNT_HLT", i_hlt_cnt);

			
			

		}
		else
		{
			// DLV LOT 조회
			DBU_init_minvdlvlot(&MINVDLVLOT);
			TRS.copy(MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY), in_node, IN_FACTORY);
			TRS.copy(MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID), in_node, "LOT_ID");
			DBU_select_minvdlvlot(1, &MINVDLVLOT);
			if (DB_error_code != DB_SUCCESS)
			{
				if (DB_error_code == DB_NOT_FOUND)
				{
					strcpy(s_msg_code, "WIP-0044");
				}
				else
				{
					strcpy(s_msg_code, "WIP-0004");
				}
				TRS.add_fieldmsg(out_node, "MINVLOTSTS SELECT", MP_NVST);
				TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVDLVLOT.FACTORY), MINVDLVLOT.FACTORY);
				TRS.add_fieldmsg(out_node, "DLV_LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);

				TRS.add_dberrmsg(out_node, DB_error_msg);

				gs_log_type.type = MP_LOG_ERROR;
				gs_log_type.e_type = MP_LOG_E_SYSTEM;
				gs_log_type.category = MP_LOG_CATE_VIEW;

				COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
				return MP_FALSE;
			}
			else
			{

			


				DBU_init_mwipoprdef(&MWIPOPRDEF);
				TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF.OPER, MINVDLVLOT.OPER, sizeof(MWIPOPRDEF.OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF);

				DBU_init_cqcmispsts(&CQCMISPSTS);
				TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPSTS.LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				DBU_select_cqcmispsts(2, &CQCMISPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "WIP-0044");
					}
					else
					{
						strcpy(s_msg_code, "WIP-0004");
					}
					TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVDLVLOT.DLV_LOT_ID), MINVDLVLOT.DLV_LOT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}



				DBU_init_cqcmispsts(&CQCMISPSTS);
				TRS.copy(CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMISPSTS.LOT_ID, MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				TRS.copy(CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER), in_node, "OPER");
				DBU_select_cqcmispsts(3, &CQCMISPSTS);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "QCM-0067"); //이 Lot의 검사요청이 존재하지 않습니다.
					}
					else
					{
						strcpy(s_msg_code, "QCM-0004");
					}
					TRS.add_fieldmsg(out_node, "CQCMISPSTS SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CQCMISPSTS.FACTORY), CQCMISPSTS.FACTORY);
					TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				DBU_init_mwipmatdef(&MWIPMATDEF);
				TRS.copy(MWIPMATDEF.FACTORY, sizeof(MWIPMATDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPMATDEF.MAT_ID, CQCMISPSTS.MAT_ID, sizeof(CQCMISPSTS.MAT_ID));
				MWIPMATDEF.MAT_VER = CQCMISPSTS.MAT_VER;
				DBU_select_mwipmatdef(1, &MWIPMATDEF);


				DBU_init_mwipoprdef(&MWIPOPRDEF_ISP);
				TRS.copy(MWIPOPRDEF_ISP.FACTORY, sizeof(MWIPOPRDEF_ISP.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPOPRDEF_ISP.OPER, CQCMISPSTS.INSP_OPER, sizeof(CQCMISPSTS.INSP_OPER));
				DBU_select_mwipoprdef(1, &MWIPOPRDEF_ISP);


				DBU_init_mwipcoldef(&MWIPCOLDEF);
				TRS.copy(MWIPCOLDEF.FACTORY, sizeof(MWIPCOLDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MWIPCOLDEF.MAT_ID, MWIPMATDEF.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
				MWIPCOLDEF.MAT_VER = 1;
				memcpy(MWIPCOLDEF.OPER, MWIPOPRDEF_ISP.OPER, sizeof(MWIPOPRDEF_ISP.OPER));
				MWIPCOLDEF.OPT_LEVEL = '4'; // mat_id , oper  level
				MWIPCOLDEF.DISABLE_FLAG = 'N';
				DBU_select_mwipcoldef(2, &MWIPCOLDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					if (DB_error_code == DB_NOT_FOUND)
					{
						strcpy(s_msg_code, "QCM-0063");
					}
					else
					{
						strcpy(s_msg_code, "QCM-0004");
					}
					TRS.add_fieldmsg(out_node, "MWIPCOLDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
					TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF_ISP.OPER), MWIPOPRDEF_ISP.OPER);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				DBU_init_medccoldef(&MEDCCOLDEF);
				TRS.copy(MEDCCOLDEF.FACTORY, sizeof(MEDCCOLDEF.FACTORY), in_node, IN_FACTORY);
				memcpy(MEDCCOLDEF.COL_SET_ID, MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
				DBU_select_medccoldef(1, &MEDCCOLDEF);
				if (DB_error_code != DB_SUCCESS)
				{
					/*
					if (DB_error_code == DB_NOT_FOUND)
					{
					}
					else
					{
					}*/
					strcpy(s_msg_code, "QCM-0004");
					TRS.add_fieldmsg(out_node, "MEDCCOLDEF SELECT", MP_NVST);
					TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MEDCCOLDEF.FACTORY), MEDCCOLDEF.FACTORY);
					TRS.add_fieldmsg(out_node, "COL_SET_ID", MP_STR, sizeof(MEDCCOLDEF.COL_SET_ID), MEDCCOLDEF.COL_SET_ID);

					TRS.add_dberrmsg(out_node, DB_error_msg);

					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}

				//(1) Grit PSD, BI, BTI 검사차수 가져오기
				DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
				TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "PSD", strlen("PSD"));
				i_psd_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
				if (i_psd_cnt == 0)
				{
					i_psd_cnt = 1;
				}

				DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
				TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "BI", strlen("BI"));
				i_bi_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
				if (i_bi_cnt == 0)
				{
					i_bi_cnt = 1;
				}

				DBU_init_cqcmgrtsiv(&CQCMGRTSIV);
				TRS.copy(CQCMGRTSIV.FACTORY, sizeof(CQCMGRTSIV.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTSIV.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				memcpy(CQCMGRTSIV.INSP_DTL_TYPE, "BTI", strlen("BTI"));
				i_bti_cnt = (int)DBU_select_cqcmgrtsiv_scalar(2, &CQCMGRTSIV);
				if (i_bti_cnt == 0)
				{
					i_bti_cnt = 1;
				}

				DBU_init_cqcmgrthlt(&CQCMGRTHLT);
				TRS.copy(CQCMGRTHLT.FACTORY, sizeof(CQCMGRTHLT.FACTORY), in_node, IN_FACTORY);
				memcpy(CQCMGRTHLT.INSP_ID, CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				memcpy(CQCMGRTHLT.INSP_DTL_TYPE, "HLT", strlen("HLT"));
				i_hlt_cnt = (int)DBU_select_cqcmgrthlt_scalar(2, &CQCMGRTHLT);
				if (i_hlt_cnt == 0)
				{
					i_hlt_cnt = 1;
				}



				// 품목, 공정별 COL_SET_ID
				TRS.add_string(out_node, "COL_SET_ID", MWIPCOLDEF.COL_SET_ID, sizeof(MWIPCOLDEF.COL_SET_ID));
				TRS.add_string(out_node, "COL_SET_DESC", MEDCCOLDEF.COL_SET_DESC, sizeof(MEDCCOLDEF.COL_SET_DESC));
				TRS.add_string(out_node, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
				TRS.add_string(out_node, "SIZES", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				TRS.add_string(out_node, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));

				TRS.add_string(out_node, "MAT_CMF_4", MWIPMATDEF.MAT_CMF_4, sizeof(MWIPMATDEF.MAT_CMF_4));
				TRS.add_string(out_node, "MAT_CMF_5", MWIPMATDEF.MAT_CMF_5, sizeof(MWIPMATDEF.MAT_CMF_5));
				TRS.add_string(out_node, "MAT_CMF_6", MWIPMATDEF.MAT_CMF_6, sizeof(MWIPMATDEF.MAT_CMF_6));
				TRS.add_string(out_node, "MAT_CMF_7", MWIPMATDEF.MAT_CMF_7, sizeof(MWIPMATDEF.MAT_CMF_7));
				TRS.add_string(out_node, "MAT_CMF_8", MWIPMATDEF.MAT_CMF_8, sizeof(MWIPMATDEF.MAT_CMF_8));
				TRS.add_string(out_node, "MAT_CMF_9", MWIPMATDEF.MAT_CMF_9, sizeof(MWIPMATDEF.MAT_CMF_9));
				TRS.add_string(out_node, "MAT_CMF_10", MWIPMATDEF.MAT_CMF_10, sizeof(MWIPMATDEF.MAT_CMF_10));
				TRS.add_string(out_node, "MAT_CMF_11", MWIPMATDEF.MAT_CMF_11, sizeof(MWIPMATDEF.MAT_CMF_11));
				TRS.add_string(out_node, "MAT_CMF_12", MWIPMATDEF.MAT_CMF_12, sizeof(MWIPMATDEF.MAT_CMF_12));
				TRS.add_string(out_node, "MAT_CMF_13", MWIPMATDEF.MAT_CMF_13, sizeof(MWIPMATDEF.MAT_CMF_13));
				TRS.add_string(out_node, "MAT_CMF_14", MWIPMATDEF.MAT_CMF_14, sizeof(MWIPMATDEF.MAT_CMF_14));
				TRS.add_string(out_node, "MAT_CMF_15", MWIPMATDEF.MAT_CMF_15, sizeof(MWIPMATDEF.MAT_CMF_15));

				TRS.add_string(out_node, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));

				TRS.add_string(out_node, "VENDOR_LOT_ID", MINVDLVLOT.VENDOR_LOT_ID, sizeof(MINVDLVLOT.VENDOR_LOT_ID));
				TRS.add_string(out_node, "FACTORY", MINVDLVLOT.FACTORY, sizeof(MINVDLVLOT.FACTORY));
				TRS.add_string(out_node, "LOT_ID", MINVDLVLOT.DLV_LOT_ID, sizeof(MINVDLVLOT.DLV_LOT_ID));
				TRS.add_string(out_node, "LOT_KIND", "I", strlen("I"));
				TRS.add_string(out_node, "LOT_STATUS", MINVDLVLOT.DLV_LOT_STATUS, sizeof(MINVDLVLOT.DLV_LOT_STATUS));
				TRS.add_string(out_node, "MAT_ID", MINVDLVLOT.MAT_ID, sizeof(MINVDLVLOT.MAT_ID));
				TRS.add_int(out_node, "MAT_VER", MINVDLVLOT.MAT_VER);
				TRS.add_string(out_node, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
				TRS.add_string(out_node, "MAT_TYPE", MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
				TRS.add_double(out_node, "QTY_1", MINVDLVLOT.QTY);
				TRS.add_double(out_node, "QTY_2", MINVDLVLOT.QTY_2);
				TRS.add_double(out_node, "QTY_3", MINVDLVLOT.QTY_3);
				TRS.add_string(out_node, "UNIT", MINVDLVLOT.UNIT, sizeof(MINVDLVLOT.UNIT));
				TRS.add_string(out_node, "UNIT_2", MINVDLVLOT.UNIT_2, sizeof(MINVDLVLOT.UNIT_2));
				TRS.add_string(out_node, "UNIT_3", MINVDLVLOT.UNIT_3, sizeof(MINVDLVLOT.UNIT_3));
				TRS.add_string(out_node, "OPER", MINVDLVLOT.OPER, sizeof(MINVDLVLOT.OPER));
				TRS.add_string(out_node, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
				TRS.add_string(out_node, "CREATE_USER_ID", MINVDLVLOT.CREATE_USER_ID, sizeof(MINVDLVLOT.CREATE_USER_ID));
				TRS.add_string(out_node, "CREATE_TIME", MINVDLVLOT.CREATE_TIME, sizeof(MINVDLVLOT.CREATE_TIME));
				TRS.add_string(out_node, "UPDATE_USER_ID", MINVDLVLOT.UPDATE_USER_ID, sizeof(MINVDLVLOT.UPDATE_USER_ID));
				TRS.add_string(out_node, "UPDATE_TIME", MINVDLVLOT.UPDATE_TIME, sizeof(MINVDLVLOT.UPDATE_TIME));
				TRS.add_string(out_node, "RES_ID", " ", strlen(" "));
				TRS.add_string(out_node, "RES_DESC", " ", strlen(" "));

				TRS.add_string(out_node, "INSP_ID", CQCMISPSTS.INSP_ID, sizeof(CQCMISPSTS.INSP_ID));
				TRS.add_double(out_node, "INSP_QTY", CQCMISPSTS.QTY);
				TRS.add_char(out_node, "INSP_STATUS", CQCMISPSTS.INSP_STATUS);
				TRS.add_string(out_node, "INSP_OPER", CQCMISPSTS.INSP_OPER,sizeof(CQCMISPSTS.INSP_OPER));
				TRS.add_string(out_node, "INSP_OPER_DESC", MWIPOPRDEF_ISP.OPER_DESC, sizeof(MWIPOPRDEF_ISP.OPER_DESC));
				TRS.add_char(out_node, "INSP_JUDGE_FLAG", CQCMISPSTS.INSP_JUDGE_FLAG);

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, "C_INSP_JUDGE", strlen("C_INSP_JUDGE"));
				memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF_ISP.OPER, sizeof(MWIPOPRDEF_ISP.OPER));
                MGCMTBLDAT.KEY_2[0] = CQCMISPSTS.INSP_JUDGE_FLAG;
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

				TRS.add_string(out_node, "INSP_JUDGE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

				TRS.add_string(out_node, "RWK_OPER", CQCMISPSTS.RWK_OPER, sizeof(CQCMISPSTS.RWK_OPER));
				TRS.add_string(out_node, "INSP_COMMENT", CQCMISPSTS.INSP_COMMENT, sizeof(CQCMISPSTS.INSP_COMMENT));
				TRS.add_string(out_node, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_INSP_STATUS, strlen(MP_GCM_INSP_STATUS));
				MGCMTBLDAT.KEY_1[0] = CQCMISPSTS.INSP_STATUS;
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

				TRS.add_string(out_node, "INSP_STATUS_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
				memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

				TRS.add_string(out_node, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
				TRS.add_string(out_node, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
				memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

				TRS.add_string(out_node, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

				DBU_init_mgcmtbldat(&MGCMTBLDAT);
				TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
				memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_INSP_GRIT_SIZE, strlen(MP_GCM_INSP_GRIT_SIZE));
				memcpy(MGCMTBLDAT.KEY_1, MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
				DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
				if (MGCMTBLDAT.DATA_1[0] == 'Y')
				{
					TRS.add_char(out_node, "DOUBLE_SIZE", MGCMTBLDAT.DATA_1[0]);
					TRS.add_string(out_node, "SIZE_1", MGCMTBLDAT.DATA_2, sizeof(MGCMTBLDAT.DATA_2));
					TRS.add_string(out_node, "SIZE_2", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));
				}
				else
				{
					TRS.add_char(out_node, "DOUBLE_SIZE", 'N');
					TRS.add_string(out_node, "SIZE_1", MWIPMATDEF.MAT_CMF_2, sizeof(MWIPMATDEF.MAT_CMF_2));
					//TRS.add_string(out_node, "SIZE_2", MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3));
				}


				TRS.add_int(out_node, "INSP_COUNT_PSD", i_psd_cnt);
				TRS.add_int(out_node, "INSP_COUNT_BI", i_bi_cnt);
				TRS.add_int(out_node, "INSP_COUNT_BTI", i_bti_cnt);
				TRS.add_int(out_node, "INSP_COUNT_HLT", i_hlt_cnt);

			}
				
		}

	}

    return MP_TRUE;
}



/*******************************************************************************
CUS_QCM_View_Lot_Info_Validation()
- Validation Check sub function of "CUS_QCM_VIEW_LOT_INFO" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_QCM_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1") == MP_FALSE)
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
