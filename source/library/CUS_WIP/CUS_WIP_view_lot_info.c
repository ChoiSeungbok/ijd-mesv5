/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_lot_info.c
Description : View Lot Infomation function

MES Version : 5.0

Function List
- step 1: 묶음번호 또는 Lot id를 조회하여 lot 리스트 정보를 리턴한다. 


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/27  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_View_Lot_Info()
- View Lot Info
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Lot_Info(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_VIEW_LOT_INFO(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_View_Lot_Info", out_node);
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
CUS_WIP_VIEW_LOT_INFO()
- Main sub function of "CUS_WIP_View_Lot_Info" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_LOT_INFO(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;       //공정 LOT 
    struct MINVLOTSTS_TAG MINVLOTSTS;       //자재 LOT
    struct MWIPMATDEF_TAG MWIPMATDEF;       //품목 마스터
    struct MWIPOPRDEF_TAG MWIPOPRDEF;       //공정 마스터
    struct MWIPFLWDEF_TAG MWIPFLWDEF;       //FLOW 마스터
    struct CWIPLOTLST_TAG CWIPLOTLST;       //불량 정보
    struct MRASRESDEF_TAG MRASRESDEF;       //설비 마스터 정보
    struct MGCMTBLDAT_TAG MGCMTBLDAT;       //GCM 정보
    struct MGCMTBLDAT_TAG MGCMTBLDAT_OPER;  //GCM 정보 공정 데이터
    struct CWIPINVLDM_TAG CWIPINVLDM;       //자재 load 테이블
    struct CWIPLOTMVM_TAG CWIPLOTMVM;       //이동지시 마스터 테이블
    struct CWIPLOTMVC_TAG CWIPLOTMVC;       //이동지시 확정 lot 리스트 테이블
    struct CWIPGRPSTS_TAG CWIPGRPSTS;       //그룹 마스터 테이블    
    struct CWIPGRPLOT_TAG CWIPGRPLOT;       //그룹 LOT 테이블
    //struct MINVDLVMST_TAG MINVDLVMST;       //
    struct MINVDLVDTL_TAG MINVDLVDTL;       //
	struct CWIPLOTMVR_TAG CWIPLOTMVR;
    struct MGCMLAGDAT_TAG MGCMLAGDAT;
	struct MRASRESDEF_TAG MRASRESDEF_PRS;


    TRSNode *list_item;
    //int i_step = 0;
    char c_flag = ' ';
    double dSumLoss = 0;
    int iStep = 0;
    int i_skip = 0;
    char s_member_name[101];
    char s_member_code[101];
    char s_vendor_site_id[50];

    LOG_head("CUS_WIP_View_Lot_Info");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_View_Lot_Info_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //작업장별 공정 찾기 => LOT 또는 묶음LOT으로 조회하여 리턴한다.
    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
        if (DB_error_code == DB_SUCCESS)
            c_flag = 'L';               

        //LOT 인경우
        if (c_flag == 'L')
        {
            if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
            {
                //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0076");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }


            

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //lot 공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
            

            // P급 창고이동은 가능하도록 
            if (TRS.get_char(in_node, "MOVE_OPEN_STATUS_EXISTS_CHECK") != 'Y')
            {
                //P급창고꺼는 조회안되도록수정 (20221206)
                           //DBU_select_mwipoprdef(1, &MWIPOPRDEF);
                DBU_select_mwipoprdef(11, &MWIPOPRDEF);
                if (DB_error_code != DB_SUCCESS)
                {
           
                    //WIP - 0668 : P급은 작업을 진행 할 수 없습니다.LOT을 확인하세요.
                    strcpy(s_msg_code, "WIP-0668");
                    TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                    TRS.add_fieldmsg(out_node, "LOT ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
            }

            //lot flow 정보 조회
            DBU_init_mwipflwdef(&MWIPFLWDEF);
            memcpy(MWIPFLWDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
            memcpy(MWIPFLWDEF.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWDEF.FLOW));
            DBU_select_mwipflwdef(1, &MWIPFLWDEF);

            //불량 저장 정보 조회
            DBU_init_cwiplotlst(&CWIPLOTLST);
            memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
            //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
            memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
            dSumLoss = DBU_select_cwiplotlst_scalar(3, &CWIPLOTLST);

            list_item = TRS.add_node(out_node, "LOT_TBL");

            TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(list_item, "LOT_DESC", MWIPLOTSTSX.LOT_DESC, sizeof(MWIPLOTSTSX.LOT_DESC));
            TRS.add_string(list_item, "LOT_STATUS", MWIPLOTSTSX.LOT_STATUS, sizeof(MWIPLOTSTSX.LOT_STATUS));
            TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
            TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
            TRS.add_int(list_item, "MAT_VER", MWIPLOTSTSX.MAT_VER);
            TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_string(list_item, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_string(list_item, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
            TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));
            TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
            TRS.add_double(list_item, "LOSS_QTY", dSumLoss);
            TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            //area 정보 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

            //sub area 정보 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_string(list_item, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
            TRS.add_string(list_item, "CREATE_TIME", MWIPLOTSTSX.CREATE_TIME, sizeof(MWIPLOTSTSX.CREATE_TIME));
            TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));
            TRS.add_string(list_item, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));
            TRS.add_string(list_item, "LOT_TYPE", MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP));
			TRS.add_string(list_item, "PRESS_RES_ID", MWIPLOTSTSX.SAVE_RES_ID_1, sizeof(MWIPLOTSTSX.SAVE_RES_ID_1));

            TRS.add_string(list_item, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "CREATE_CODE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

            //LOT CMF 정보
            TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));     //그룹id
            TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2));     //그룹id 순번
            TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3));     
            TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4));     
            TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5));     
            TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6));     
            TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));     
            TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));     
            TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9));
            TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
            TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));
            TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12));
            TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13));
            TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14));
            TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15));
            TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
            TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17));
            TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18));
            TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19));
            TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20));

            //CTM CMF 정보
            TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1));     
            TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_2));     
            TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_3));
            TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_4));
            TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_5));
            TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_6));
            TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_7));
            TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_8));
            TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_9));
            TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_10));
            TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_11));
            TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_12));
            TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_13));
            TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_14));
            TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_15));
            TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_16));
            TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_17));
            TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_18));
            TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_19));
            TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_20));

            //PDC CMF 정보
            TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1));
            TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_2));
            TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_3));
            TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_4));
            TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_5));
            TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_6));
            TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_7));
            TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_8));
            TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_9));
            TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_10));
            TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_11));
            TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_12));
            TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_13));
            TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_14));
            TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_15));
            TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_16));
            TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_17));
            TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_18));
            TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_19));
            TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_20));

            //HM CMF 정보
            TRS.add_string(list_item, "HM_CMF_1", MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1));
            TRS.add_string(list_item, "HM_CMF_2", MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_2));
            TRS.add_string(list_item, "HM_CMF_3", MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_3));
            TRS.add_string(list_item, "HM_CMF_4", MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_4));
            TRS.add_string(list_item, "HM_CMF_5", MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_5));
            TRS.add_string(list_item, "HM_CMF_6", MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_6));
            TRS.add_string(list_item, "HM_CMF_7", MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_7));
            TRS.add_string(list_item, "HM_CMF_8", MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_8));
            TRS.add_string(list_item, "HM_CMF_9", MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_9));
            TRS.add_string(list_item, "HM_CMF_10", MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_10));
            TRS.add_string(list_item, "HM_CMF_11", MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_11));
            TRS.add_string(list_item, "HM_CMF_12", MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_12));
            TRS.add_string(list_item, "HM_CMF_13", MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_13));
            TRS.add_string(list_item, "HM_CMF_14", MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_14));
            TRS.add_string(list_item, "HM_CMF_15", MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_15));
            TRS.add_string(list_item, "HM_CMF_16", MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_16));
            TRS.add_string(list_item, "HM_CMF_17", MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_17));
            TRS.add_string(list_item, "HM_CMF_18", MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_18));
            TRS.add_string(list_item, "HM_CMF_19", MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_19));
            TRS.add_string(list_item, "HM_CMF_20", MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_20));

            //GRIT 
            TRS.add_string(list_item, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
            TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
            TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
            TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));
            TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
            TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));
            TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_7));
            TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_8));
            TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_9));
            TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_10));
            TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_11));
            TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_12));
            TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_13));
            TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_14));
            TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_15));
            TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_16));
            TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_17));
            TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_18));
            TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_19));
            TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_20));

            //설비 정보
            if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
            {
                TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.END_RES_ID, sizeof(MWIPLOTSTSX.END_RES_ID));
            }
            else
            {
                TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.START_RES_ID, sizeof(MWIPLOTSTSX.START_RES_ID));
            }

            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), list_item, "RES_ID");
            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code == DB_SUCCESS)
            {
                TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
            }

			DBU_init_mrasresdef(&MRASRESDEF_PRS);
			memcpy(MRASRESDEF_PRS.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF_PRS.FACTORY));
			memcpy(MRASRESDEF_PRS.RES_ID, MWIPLOTSTSX.SAVE_RES_ID_1, sizeof(MWIPLOTSTSX.SAVE_RES_ID_1));
			DBU_select_mrasresdef(1, &MRASRESDEF_PRS);
			if (DB_error_code == DB_SUCCESS)
			{
				TRS.add_string(list_item, "PRESS_RES_DESC", MRASRESDEF_PRS.RES_DESC, sizeof(MRASRESDEF_PRS.RES_DESC));
			}


            //작업공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");        
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            if (DB_error_code == DB_SUCCESS)
            {
                //작업 공정 옵션
                TRS.add_string(out_node, "OPER_OPTION_1", MWIPOPRDEF.OPER_CMF_2, sizeof(MWIPOPRDEF.OPER_CMF_2));
                TRS.add_string(out_node, "OPER_OPTION_2", MWIPOPRDEF.OPER_CMF_13, sizeof(MWIPOPRDEF.OPER_CMF_13));
            }

			if (TRS.get_char(in_node, "MOVE_OPEN_STATUS_EXISTS_CHECK") == 'Y')
			{
				DBU_init_cwiplotmvr(&CWIPLOTMVR);
				TRS.copy(CWIPLOTMVR.FACTORY, sizeof(CWIPLOTMVR.FACTORY), in_node, IN_FACTORY);
				TRS.copy(CWIPLOTMVR.LOT_ID, sizeof(CWIPLOTMVR.LOT_ID), in_node, "LOT_ID");
				
				if ((int)DBU_select_cwiplotmvr_scalar(3, &CWIPLOTMVR) > 0)
				{
					//WIP-0673 :이 LOT은 이미 "OPEN" 상태의 다른 이동지시번호가 존재합니다.
					strcpy(s_msg_code, "WIP-0673");
					TRS.add_dberrmsg(out_node, DB_error_msg);
					gs_log_type.type = MP_LOG_ERROR;
					gs_log_type.e_type = MP_LOG_E_SYSTEM;
					gs_log_type.category = MP_LOG_CATE_VIEW;

					COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
					return MP_FALSE;
				}
			}

            //공정의 CMF 필드에 있는 공정 데이터 값이 버튼으로 셋업 되어있으면 Desc 데이터를 GCM에서 가져와야 하한다. 
            DBU_init_mgcmtbldat(&MGCMTBLDAT_OPER);
            memcpy(MGCMTBLDAT_OPER.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
            memcpy(MGCMTBLDAT_OPER.TABLE_NAME, MP_GCM_OPER_DATA, strlen(MP_GCM_OPER_DATA));
            memcpy(MGCMTBLDAT_OPER.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_open_mgcmtbldat(2, &MGCMTBLDAT_OPER);
            if (DB_error_code != DB_SUCCESS)
            {
                //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                strcpy(s_msg_code, "GCM-0008");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPER OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_OPER.KEY_1), MGCMTBLDAT_OPER.KEY_1);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            while (1)
            {
                DBU_fetch_mgcmtbldat(2, &MGCMTBLDAT_OPER);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_mgcmtbldat(2);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPER OPEN", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_OPER.KEY_1), MGCMTBLDAT_OPER.KEY_1);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_mgcmtbldat(2);

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //oper data 옵션에 버튼유무가 'Y' 인 경우 해당 컬럼의 desc값도 찾아온다.
                if (MGCMTBLDAT_OPER.DATA_3[0] == 'Y')
                {
                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MGCMTBLDAT_OPER.DATA_4, sizeof(MGCMTBLDAT_OPER.DATA_4));

                    //MGCMTBLDAT_OPER.DATA_2 에는 컬럼 값이 있으므로 컬럼값을 변수에 담는다. 
                    // => 미리 outnode에 넣은 컬럼에 해당하는 값을 가져오기 위함.
                    sprintf(s_member_code, "%.*s", COM_len_space(MGCMTBLDAT_OPER.DATA_2, sizeof(MGCMTBLDAT_OPER.DATA_2)), MGCMTBLDAT_OPER.DATA_2);

                    //프로파일 옵션인 경우
                    if (memcmp(MGCMTBLDAT_OPER.DATA_4, MP_GCM_PROFILE_DEF, strlen(MP_GCM_PROFILE_DEF)) == MP_FALSE)
                    {
                        memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                        TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), list_item, s_member_code);
                    }
                    else
                    {
                        TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), list_item, s_member_code);
                    }

                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    if (DB_error_code == DB_SUCCESS)
                    {
                        sprintf(s_member_name, "%.*s_DESC", COM_len_space(MGCMTBLDAT_OPER.DATA_2, sizeof(MGCMTBLDAT_OPER.DATA_2)), MGCMTBLDAT_OPER.DATA_2);
                        TRS.add_string(list_item, s_member_name, MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                    }
                }
            }
        }
        else
        {
            //이동지시 조회
            DBU_init_cwiplotmvm(&CWIPLOTMVM);
            TRS.copy(CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVM.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVM.MOVE_ID), in_node, "LOT_ID");
            DBU_select_cwiplotmvm(1, &CWIPLOTMVM);
            if (DB_error_code == DB_SUCCESS)
                c_flag = 'C';
            else
                c_flag = 'M';
            
            //이동지시인 경우
            if (c_flag == 'C')
            {
                if (TRS.get_char(in_node, "SKIP_YN") == 'Y')
                    i_skip = MP_TRUE;
                else 
                    i_skip = MP_FALSE;

                //pda에서 이동지시 리스트를 조회하기 위해 사용. 
                if (i_skip == MP_FALSE)
                {
                    if (CWIPLOTMVM.MOVE_STATUS[0] != MP_CWIP_ORDER_FINISH)
                    {
                        //WIP-0563 : 완료되지 않은 이동지시 번호 입니다.
                        strcpy(s_msg_code, "WIP-0563");
                        TRS.add_dberrmsg(out_node, DB_error_msg);
                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }

                //이동지시 상태
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_ORDER_STATUS, strlen(MP_WIP_ORDER_STATUS));
                memcpy(MGCMTBLDAT.KEY_1, CWIPLOTMVM.MOVE_STATUS, sizeof(CWIPLOTMVM.MOVE_STATUS));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                TRS.add_string(out_node, "MOVE_STATUS", CWIPLOTMVM.MOVE_STATUS, sizeof(CWIPLOTMVM.MOVE_STATUS));
                TRS.add_string(out_node, "MOVE_STATUSDESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                //from area 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                memcpy(MGCMTBLDAT.KEY_1, CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                TRS.add_string(out_node, "FROM_AREA_ID", CWIPLOTMVM.FROM_AREA_ID, sizeof(CWIPLOTMVM.FROM_AREA_ID));
                TRS.add_string(out_node, "FROM_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                //from sub area 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
                memcpy(MGCMTBLDAT.KEY_1, CWIPLOTMVM.FROM_SUB_AREA_ID, sizeof(CWIPLOTMVM.FROM_SUB_AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                TRS.add_string(out_node, "FROM_SUB_AREA_ID", CWIPLOTMVM.FROM_SUB_AREA_ID, sizeof(CWIPLOTMVM.FROM_SUB_AREA_ID));
                TRS.add_string(out_node, "FROM_SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                //from oper 정보 조회
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF.OPER, CWIPLOTMVM.FROM_OPER, sizeof(CWIPLOTMVM.FROM_OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                TRS.add_string(out_node, "FROM_OPER", CWIPLOTMVM.FROM_OPER, sizeof(CWIPLOTMVM.FROM_OPER));
                TRS.add_string(out_node, "FROM_OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));

                //to area 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                memcpy(MGCMTBLDAT.KEY_1, CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
               
                TRS.add_string(out_node, "TO_AREA_ID", CWIPLOTMVM.TO_AREA_ID, sizeof(CWIPLOTMVM.TO_AREA_ID));
                TRS.add_string(out_node, "TO_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                //to sub area 정보 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
                memcpy(MGCMTBLDAT.KEY_1, CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                TRS.add_string(out_node, "TO_SUB_AREA_ID", CWIPLOTMVM.TO_SUB_AREA_ID, sizeof(CWIPLOTMVM.TO_SUB_AREA_ID));
                TRS.add_string(out_node, "TO_SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                //to oper 정보 조회
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF.OPER, CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                TRS.add_string(out_node, "TO_OPER", CWIPLOTMVM.TO_OPER, sizeof(CWIPLOTMVM.TO_OPER));
                TRS.add_string(out_node, "TO_OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));

                //이동지시 대상 lot 정보 조회
                DBU_init_cwiplotmvc(&CWIPLOTMVC);
                memcpy(CWIPLOTMVC.FACTORY, CWIPLOTMVM.FACTORY, sizeof(CWIPLOTMVC.FACTORY));
                memcpy(CWIPLOTMVC.MOVE_ID, CWIPLOTMVM.MOVE_ID, sizeof(CWIPLOTMVC.MOVE_ID));

                DBU_open_cwiplotmvc(2, &CWIPLOTMVC);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "CWIPLOTMVC OPEN", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
                    TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                while (1)
                {
                    DBU_fetch_cwiplotmvc(2, &CWIPLOTMVC);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        DBU_close_cwiplotmvc(2);
                        break;
                    }
                    else if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                        strcpy(s_msg_code, "WIP-0044");
                        TRS.add_fieldmsg(out_node, "CWIPLOTMVC OPEN", MP_NVST);
                        TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTMVC.FACTORY), CWIPLOTMVC.FACTORY);
                        TRS.add_fieldmsg(out_node, "MOVE_ID", MP_STR, sizeof(CWIPLOTMVC.MOVE_ID), CWIPLOTMVC.MOVE_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        DBU_close_cwiplotmvc(2);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    if (COM_check_node_length(out_node) == MP_FALSE)
                    {
                        TRS.add_string(out_node, "NEXT_LOT", CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
                        DBU_close_cwiplotmvc(2);
                        break;
                    }

                    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                    memcpy(MWIPLOTSTSX.LOT_ID, CWIPLOTMVC.LOT_ID, sizeof(CWIPLOTMVC.LOT_ID));
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

                    if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
                    {
                        //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                        strcpy(s_msg_code, "WIP-0076");
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //자재 정보 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
                    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    MWIPMATDEF.MAT_VER = 1;
                    DBU_select_mwipmatdef(1, &MWIPMATDEF);

                    //lot 공정 정보 조회
                    DBU_init_mwipoprdef(&MWIPOPRDEF);
                    memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                    memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                    //lot flow 정보 조회
                    DBU_init_mwipflwdef(&MWIPFLWDEF);
                    memcpy(MWIPFLWDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
                    memcpy(MWIPFLWDEF.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWDEF.FLOW));
                    DBU_select_mwipflwdef(1, &MWIPFLWDEF);

                    //불량 저장 정보 조회
                    DBU_init_cwiplotlst(&CWIPLOTLST);
                    memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
                    //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
                    memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
                    dSumLoss = DBU_select_cwiplotlst_scalar(3, &CWIPLOTLST);

                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(list_item, "LOT_DESC", MWIPLOTSTSX.LOT_DESC, sizeof(MWIPLOTSTSX.LOT_DESC));
                    TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                    TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
                    TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
                    TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
                    TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_string(list_item, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                    TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
                    TRS.add_string(list_item, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                    TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));

                    TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
                    TRS.add_double(list_item, "LOSS_QTY", dSumLoss);

                    TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    //area 정보 조회
                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                    TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

                    //sub area 정보 조회
                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                    TRS.add_string(list_item, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                    TRS.add_string(list_item, "CREATE_TIME", MWIPLOTSTSX.CREATE_TIME, sizeof(MWIPLOTSTSX.CREATE_TIME));
                    TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));

                    //설비 정보
                    if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
                    {
                        TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.END_RES_ID, sizeof(MWIPLOTSTSX.END_RES_ID));
                    }
                    else
                    {
                        TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.START_RES_ID, sizeof(MWIPLOTSTSX.START_RES_ID));
                    }

                    DBU_init_mrasresdef(&MRASRESDEF);
                    memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));
                    TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), list_item, "RES_ID");
                    DBU_select_mrasresdef(1, &MRASRESDEF);
                    if (DB_error_code == DB_SUCCESS)
                    {
                        TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
                    }

                    TRS.add_string(list_item, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "CREATE_CODE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                    //LOT CMF 정보
                    TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));     //그룹id
                    TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2));     //그룹id 순번
                    TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3));
                    TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4));
                    TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5));
                    TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6));
                    TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));
                    TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));
                    TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9));
                    TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
                    TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));
                    TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12));
                    TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13));
                    TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14));
                    TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15));
                    TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
                    TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17));
                    TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18));
                    TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19));
                    TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20));

                    //CTM CMF 정보
                    TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1));
                    TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_2));
                    TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_3));
                    TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_4));
                    TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_5));
                    TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_6));
                    TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_7));
                    TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_8));
                    TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_9));
                    TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_10));
                    TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_11));
                    TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_12));
                    TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_13));
                    TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_14));
                    TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_15));
                    TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_16));
                    TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_17));
                    TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_18));
                    TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_19));
                    TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_20));

                    //PDC CMF 정보
                    TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1));
                    TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_2));
                    TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_3));
                    TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_4));
                    TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_5));
                    TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_6));
                    TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_7));
                    TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_8));
                    TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_9));
                    TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_10));
                    TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_11));
                    TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_12));
                    TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_13));
                    TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_14));
                    TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_15));
                    TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_16));
                    TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_17));
                    TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_18));
                    TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_19));
                    TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_20));

                    //HM CMF 정보
                    TRS.add_string(list_item, "HM_CMF_1", MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1));
                    TRS.add_string(list_item, "HM_CMF_2", MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_2));
                    TRS.add_string(list_item, "HM_CMF_3", MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_3));
                    TRS.add_string(list_item, "HM_CMF_4", MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_4));
                    TRS.add_string(list_item, "HM_CMF_5", MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_5));
                    TRS.add_string(list_item, "HM_CMF_6", MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_6));
                    TRS.add_string(list_item, "HM_CMF_7", MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_7));
                    TRS.add_string(list_item, "HM_CMF_8", MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_8));
                    TRS.add_string(list_item, "HM_CMF_9", MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_9));
                    TRS.add_string(list_item, "HM_CMF_10", MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_10));
                    TRS.add_string(list_item, "HM_CMF_11", MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_11));
                    TRS.add_string(list_item, "HM_CMF_12", MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_12));
                    TRS.add_string(list_item, "HM_CMF_13", MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_13));
                    TRS.add_string(list_item, "HM_CMF_14", MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_14));
                    TRS.add_string(list_item, "HM_CMF_15", MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_15));
                    TRS.add_string(list_item, "HM_CMF_16", MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_16));
                    TRS.add_string(list_item, "HM_CMF_17", MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_17));
                    TRS.add_string(list_item, "HM_CMF_18", MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_18));
                    TRS.add_string(list_item, "HM_CMF_19", MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_19));
                    TRS.add_string(list_item, "HM_CMF_20", MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_20));

                    //GRIT CMF 정보
                    TRS.add_string(list_item, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
                    TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
                    TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
                    TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));
                    TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
                    TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));
                    TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_7));
                    TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_8));
                    TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_9));
                    TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_10));
                    TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_11));
                    TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_12));
                    TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_13));
                    TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_14));
                    TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_15));
                    TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_16));
                    TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_17));
                    TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_18));
                    TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_19));
                    TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_20));

                }
            }
            //MAPPING ID 인경우 -> 소결
            else if (c_flag == 'M')
            {
                DBU_init_cwipgrpsts(&CWIPGRPSTS);
                TRS.copy(CWIPGRPSTS.FACTORY, sizeof(CWIPGRPSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPSTS.GROUP_ID), in_node, "LOT_ID");
                DBU_select_cwipgrpsts(1,&CWIPGRPSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
                    TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //D12허용20230331
                /* 
                //D12 그룹 ID는 공정에서 진행 할 수 없음. 
                if (memcmp(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_D12, strlen(MP_MAPPING_GROUP_D12)) == MP_FALSE)
                {
                    //WIP-0577 : Group ID가 아닙니다. ID를 확인하세요.
                    strcpy(s_msg_code, "WIP-0577");
                    TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "GROUP_TYPE", MP_STR, sizeof(CWIPGRPSTS.GROUP_TYPE), CWIPGRPSTS.GROUP_TYPE);
                    TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPSTS.GROUP_ID), CWIPGRPSTS.GROUP_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }
                */
                //iStep 구분
                else if (memcmp(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_CELL, strlen(MP_MAPPING_GROUP_CELL)) == MP_FALSE)
                    iStep = 2;
                else if (memcmp(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_ISP, strlen(MP_MAPPING_GROUP_ISP)) == MP_FALSE 
                    || memcmp(CWIPGRPSTS.GROUP_TYPE, MP_MAPPING_GROUP_CUP, strlen(MP_MAPPING_GROUP_CUP)) == MP_FALSE)
                    iStep = 3;

                DBU_init_cwipgrplot(&CWIPGRPLOT);
                memcpy(CWIPGRPLOT.FACTORY, CWIPGRPSTS.FACTORY, sizeof(CWIPGRPLOT.FACTORY));
                memcpy(CWIPGRPLOT.GROUP_ID, CWIPGRPSTS.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID));

                DBU_open_cwipgrplot(iStep, &CWIPGRPLOT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    strcpy(s_msg_code, "WIP-0044");
                    TRS.add_fieldmsg(out_node, "CWIPGRPLOT OPEN", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
                    TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                while (1)
                {
                    DBU_fetch_cwipgrplot(iStep, &CWIPGRPLOT);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        DBU_close_cwipgrplot(iStep);
                        break;
                    }
                    else if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                        strcpy(s_msg_code, "WIP-0044");
                        TRS.add_fieldmsg(out_node, "CWIPGRPLOT FETCH", MP_NVST);
                        TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
                        TRS.add_fieldmsg(out_node, "GROUP_ID", MP_STR, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        DBU_close_cwipgrplot(iStep);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    if (COM_check_node_length(out_node) == MP_FALSE)
                    {
                        TRS.add_string(out_node, "NEXT_LOT", CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID));
                        DBU_close_cwipgrplot(iStep);
                        break;
                    }

                    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                    memcpy(MWIPLOTSTSX.LOT_ID, CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID));
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

                    if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
                    {
                        //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                        strcpy(s_msg_code, "WIP-0076");
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    //자재 정보 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
                    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    MWIPMATDEF.MAT_VER = 1;
                    DBU_select_mwipmatdef(1, &MWIPMATDEF);

                    //lot 공정 정보 조회
                    DBU_init_mwipoprdef(&MWIPOPRDEF);
                    memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                    memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                    //lot flow 정보 조회
                    DBU_init_mwipflwdef(&MWIPFLWDEF);
                    memcpy(MWIPFLWDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
                    memcpy(MWIPFLWDEF.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWDEF.FLOW));
                    DBU_select_mwipflwdef(1, &MWIPFLWDEF);

                    //불량 저장 정보 조회
                    DBU_init_cwiplotlst(&CWIPLOTLST);
                    memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
                    //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
                    memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
                    dSumLoss = DBU_select_cwiplotlst_scalar(3, &CWIPLOTLST);

                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                    TRS.add_string(list_item, "LOT_DESC", MWIPLOTSTSX.LOT_DESC, sizeof(MWIPLOTSTSX.LOT_DESC));
                    TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
                    TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
                    TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
                    TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
                    TRS.add_string(list_item, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
                    TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
                    TRS.add_string(list_item, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
                    TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));

                    TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
                    TRS.add_double(list_item, "LOSS_QTY", dSumLoss);

                    TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    //area 정보 조회
                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                    TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

                    //sub area 정보 조회
                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                    TRS.add_string(list_item, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
                    TRS.add_string(list_item, "CREATE_TIME", MWIPLOTSTSX.CREATE_TIME, sizeof(MWIPLOTSTSX.CREATE_TIME));
                    TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));

                    //설비 정보
                    if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
                    {
                        TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.END_RES_ID, sizeof(MWIPLOTSTSX.END_RES_ID));
                    }
                    else
                    {
                        TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.START_RES_ID, sizeof(MWIPLOTSTSX.START_RES_ID));
                    }

                    DBU_init_mrasresdef(&MRASRESDEF);
                    memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));
                    TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), list_item, "RES_ID");
                    DBU_select_mrasresdef(1, &MRASRESDEF);
                    if (DB_error_code == DB_SUCCESS)
                    {
                        TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
                    }

                    TRS.add_string(list_item, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

                    DBU_init_mgcmtbldat(&MGCMTBLDAT);
                    memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                    memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
                    memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
                    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                    TRS.add_string(list_item, "CREATE_CODE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

                    //LOT CMF 정보
                    TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));     //그룹id
                    TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2));     //그룹id 순번
                    TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3));
                    TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4));
                    TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5));
                    TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6));
                    TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));
                    TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));
                    TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9));
                    TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
                    TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));
                    TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12));
                    TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13));
                    TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14));
                    TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15));
                    TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
                    TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17));
                    TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18));
                    TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19));
                    TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20));

                    //CTM CMF 정보
                    TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1));
                    TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_2));
                    TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_3));
                    TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_4));
                    TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_5));
                    TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_6));
                    TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_7));
                    TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_8));
                    TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_9));
                    TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_10));
                    TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_11));
                    TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_12));
                    TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_13));
                    TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_14));
                    TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_15));
                    TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_16));
                    TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_17));
                    TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_18));
                    TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_19));
                    TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_20));

                    //PDC CMF 정보
                    TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1));
                    TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_2));
                    TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_3));
                    TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_4));
                    TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_5));
                    TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_6));
                    TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_7));
                    TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_8));
                    TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_9));
                    TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_10));
                    TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_11));
                    TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_12));
                    TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_13));
                    TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_14));
                    TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_15));
                    TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_16));
                    TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_17));
                    TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_18));
                    TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_19));
                    TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_20));

                    //HM CMF 정보
                    TRS.add_string(list_item, "HM_CMF_1", MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1));
                    TRS.add_string(list_item, "HM_CMF_2", MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_2));
                    TRS.add_string(list_item, "HM_CMF_3", MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_3));
                    TRS.add_string(list_item, "HM_CMF_4", MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_4));
                    TRS.add_string(list_item, "HM_CMF_5", MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_5));
                    TRS.add_string(list_item, "HM_CMF_6", MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_6));
                    TRS.add_string(list_item, "HM_CMF_7", MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_7));
                    TRS.add_string(list_item, "HM_CMF_8", MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_8));
                    TRS.add_string(list_item, "HM_CMF_9", MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_9));
                    TRS.add_string(list_item, "HM_CMF_10", MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_10));
                    TRS.add_string(list_item, "HM_CMF_11", MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_11));
                    TRS.add_string(list_item, "HM_CMF_12", MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_12));
                    TRS.add_string(list_item, "HM_CMF_13", MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_13));
                    TRS.add_string(list_item, "HM_CMF_14", MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_14));
                    TRS.add_string(list_item, "HM_CMF_15", MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_15));
                    TRS.add_string(list_item, "HM_CMF_16", MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_16));
                    TRS.add_string(list_item, "HM_CMF_17", MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_17));
                    TRS.add_string(list_item, "HM_CMF_18", MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_18));
                    TRS.add_string(list_item, "HM_CMF_19", MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_19));
                    TRS.add_string(list_item, "HM_CMF_20", MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_20));

                    //GRIT CMF 정보
                    TRS.add_string(list_item, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
                    TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
                    TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
                    TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));
                    TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
                    TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));
                    TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_7));
                    TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_8));
                    TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_9));
                    TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_10));
                    TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_11));
                    TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_12));
                    TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_13));
                    TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_14));
                    TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_15));
                    TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_16));
                    TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_17));
                    TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_18));
                    TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_19));
                    TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_20));

                    //공정의 CMF 필드에 있는 공정 데이터 값이 버튼으로 셋업 되어있으면 Desc 데이터를 GCM에서 가져와야 하한다. 
                    DBU_init_mgcmtbldat(&MGCMTBLDAT_OPER);
                    memcpy(MGCMTBLDAT_OPER.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
                    memcpy(MGCMTBLDAT_OPER.TABLE_NAME, MP_GCM_OPER_DATA, strlen(MP_GCM_OPER_DATA));
                    memcpy(MGCMTBLDAT_OPER.KEY_1, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
                    DBU_open_mgcmtbldat(2, &MGCMTBLDAT_OPER);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                        strcpy(s_msg_code, "GCM-0008");
                        TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPER OPEN", MP_NVST);
                        TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_OPER.KEY_1), MGCMTBLDAT_OPER.KEY_1);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    while (1)
                    {
                        DBU_fetch_mgcmtbldat(2, &MGCMTBLDAT_OPER);
                        if (DB_error_code == DB_NOT_FOUND)
                        {
                            DBU_close_mgcmtbldat(2);
                            break;
                        }
                        else if (DB_error_code != DB_SUCCESS)
                        {
                            //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                            strcpy(s_msg_code, "GCM-0008");
                            TRS.add_fieldmsg(out_node, "MGCMTBLDAT_OPER OPEN", MP_NVST);
                            TRS.add_fieldmsg(out_node, "step", MP_INT, 2);
                            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MGCMTBLDAT_OPER.KEY_1), MGCMTBLDAT_OPER.KEY_1);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            gs_log_type.type = MP_LOG_ERROR;
                            gs_log_type.e_type = MP_LOG_E_SYSTEM;
                            gs_log_type.category = MP_LOG_CATE_VIEW;

                            DBU_close_mgcmtbldat(2);

                            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                            return MP_FALSE;
                        }

                        //oper data 옵션에 버튼유무가 'Y' 인 경우 해당 컬럼의 desc값도 찾아온다.
                        if (MGCMTBLDAT_OPER.DATA_3[0] == 'Y')
                        {
                            DBU_init_mgcmtbldat(&MGCMTBLDAT);
                            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
                            memcpy(MGCMTBLDAT.TABLE_NAME, MGCMTBLDAT_OPER.DATA_4, sizeof(MGCMTBLDAT_OPER.DATA_4));
                            
                            //MGCMTBLDAT_OPER.DATA_2 에는 컬럼 값이 있으므로 컬럼값을 변수에 담는다. 
                            // => 미리 outnode에 넣은 컬럼에 해당하는 값을 가져오기 위함.
                            sprintf(s_member_code, "%.*s", COM_len_space(MGCMTBLDAT_OPER.DATA_2, sizeof(MGCMTBLDAT_OPER.DATA_2)), MGCMTBLDAT_OPER.DATA_2);

                            //프로파일 옵션인 경우
                            if (memcmp(MGCMTBLDAT_OPER.DATA_4, MP_GCM_PROFILE_DEF, strlen(MP_GCM_PROFILE_DEF)) == MP_FALSE)
                            {
                                memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                                TRS.copy(MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2), list_item, s_member_code);
                            }
                            else
                            {   
                                TRS.copy(MGCMTBLDAT.KEY_1, sizeof(MGCMTBLDAT.KEY_1), list_item, s_member_code);                        
                            }

                            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

                            if (DB_error_code == DB_SUCCESS)
                            {
                                sprintf(s_member_name, "%.*s_DESC", COM_len_space(MGCMTBLDAT_OPER.DATA_2, sizeof(MGCMTBLDAT_OPER.DATA_2)), MGCMTBLDAT_OPER.DATA_2);
                                TRS.add_string(list_item, s_member_name, MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
                            }
                        }
                    }
                }
            }

            //작업공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            //작업 공정 옵션
            TRS.add_string(out_node, "OPER_OPTION_1", MWIPOPRDEF.OPER_CMF_2, sizeof(MWIPOPRDEF.OPER_CMF_2));
            TRS.add_string(out_node, "OPER_OPTION_2", MWIPOPRDEF.OPER_CMF_13, sizeof(MWIPOPRDEF.OPER_CMF_13));

            //area 정보 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_CAR, strlen(MP_GCM_CAR));
            memcpy(MGCMTBLDAT.KEY_1, CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            //셀조립 정보
            TRS.add_string(out_node, "LOT_CMF_3", CWIPGRPSTS.CAR, sizeof(CWIPGRPSTS.CAR));
            TRS.add_string(out_node, "LOT_CMF_3_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_double(out_node, "LOT_CMF_5", CWIPGRPSTS.CELL_WEIGHT);
            TRS.add_double(out_node, "LOT_CMF_6", CWIPGRPSTS.CELL_HEIGHT);
        }       
    }
    //투입 자재lot 또는 kitting lot 또는 공정lot을 조회하여 리턴한다. 
    else if (TRS.get_procstep(in_node) == '2')
    {
        //자재LOT이 load 되어있는지 확인.
        DBU_init_cwipinvldm(&CWIPINVLDM);
        TRS.copy(CWIPINVLDM.FACTORY, sizeof(CWIPINVLDM.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPINVLDM.INV_LOT_ID, sizeof(CWIPINVLDM.INV_LOT_ID), in_node, "LOT_ID");
        if(DBU_select_cwipinvldm_scalar(1, &CWIPINVLDM) > 0)
        {
            //INV-0018 : 이 자재 LOT은 다른 작업지시에 투입되어 있습니다. 작업지시를 확인해주세요.
            strcpy(s_msg_code, "INV-0018");
            TRS.add_fieldmsg(out_node, "CWIPINVLDM SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPINVLDM.FACTORY), CWIPINVLDM.FACTORY);
            TRS.add_fieldmsg(out_node, "INV_LOT_ID", MP_STR, sizeof(CWIPINVLDM.INV_LOT_ID), CWIPINVLDM.INV_LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "LOT_ID");
        DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
        if (DB_error_code == DB_SUCCESS)
            c_flag = 'L';
        else
            c_flag = 'I';

        //공정 lot인 경우
        if (c_flag == 'L')
        {

            //20231127 HOLD기능 추가
            if (MWIPLOTSTSX.HOLD_FLAG == 'Y')
            {

                //WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
                strcpy(s_msg_code, "WIP-0059");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;


            }


            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);




            if (memcmp(MWIPOPRDEF.OPER_GRP_1, MP_OPER_GRP_TYPE_LOSS, strlen(MP_OPER_GRP_TYPE_LOSS)) == 0) {

                //WIP - 0668 : P급은 작업을 진행 할 수 없습니다.LOT을 확인하세요.
                strcpy(s_msg_code, "WIP-0668");
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;

            }

            //lot flow 정보 조회
            DBU_init_mwipflwdef(&MWIPFLWDEF);
            memcpy(MWIPFLWDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
            memcpy(MWIPFLWDEF.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWDEF.FLOW));
            DBU_select_mwipflwdef(1, &MWIPFLWDEF);

            list_item = TRS.add_node(out_node, "LOT_TBL");

            TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(list_item, "LOT_DESC", MWIPLOTSTSX.LOT_DESC, sizeof(MWIPLOTSTSX.LOT_DESC));
            TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
            TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));            
            TRS.add_string(list_item, "LOT_TYPE", MP_LOT_TYPE_WIP, strlen(MP_LOT_TYPE_WIP));
            TRS.add_string(list_item, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_string(list_item, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
            TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));
            TRS.add_string(list_item, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
            TRS.add_string(list_item, "OSP_ORDER_ID", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
            TRS.add_string(list_item, "LAST_COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

            TRS.add_string(list_item, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

            TRS.add_string(list_item, "VENDOR_LOT_ID", " ", sizeof(""));
            TRS.add_string(list_item, "VENDOR_DESC", " ", sizeof(""));

            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "CREATE_CODE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));








            // 구매 입고 마스터 정보 조회
            DBU_init_minvdlvdtl(&MINVDLVDTL);
            TRS.copy(MINVDLVDTL.FACTORY, sizeof(MINVDLVDTL.FACTORY), in_node, IN_FACTORY);
            memcpy(MINVDLVDTL.CMF_1, MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
            DBU_select_minvdlvdtl(103, &MINVDLVDTL);
            if (DB_error_code == DB_SUCCESS)
            {
                TRS.add_string(list_item, "PO_NO", MINVDLVDTL.PO_NO, sizeof(MINVDLVDTL.PO_NO));
            }
        }
        // 자재lot 또는 kitting ID 인 경우
        else
        {
            DBU_init_minvlotsts(&MINVLOTSTS);
            TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID), in_node, "LOT_ID");
            DBU_select_minvlotsts(1, &MINVLOTSTS);
            if (DB_error_code == DB_SUCCESS)
                c_flag = 'I';
            else 
                c_flag = 'K';

            //자재 lot 인 경우
            if (c_flag == 'I')
            {
                if (TRS.get_char(in_node, "SKIP_DELL_FLAG") != 'Y')
                {
                    if (MINVLOTSTS.DELETE_FLAG == 'Y')
                    {
                        //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
                        strcpy(s_msg_code, "WIP-0076");
                        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }

                //20231127 HOLD기능 추가
                if (MINVLOTSTS.HOLD_FLAG == 'Y')
                {

                    //INV-0014
                                            //INV-0014 : 이 자재 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
                    strcpy(s_msg_code, "INV-0014");
                    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MINVLOTSTS.INV_LOT_ID), MINVLOTSTS.INV_LOT_ID);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;


                }


                //자재 정보 조회
                DBU_init_mwipmatdef(&MWIPMATDEF);
                memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
                memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                MWIPMATDEF.MAT_VER = 1;
                DBU_select_mwipmatdef(1, &MWIPMATDEF);

                //공정 정보 조회
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                memcpy(MWIPOPRDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF);



                //협력사 조회
                DBU_init_mgcmlagdat(&MGCMLAGDAT);
                TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
                memcpy(MGCMLAGDAT.KEY_1, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
                COM_itoa_left(s_vendor_site_id, MINVLOTSTS.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
                memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
                DBU_select_mgcmlagdat(1, &MGCMLAGDAT);


                list_item = TRS.add_node(out_node, "LOT_TBL");

                TRS.add_string(list_item, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                TRS.add_string(list_item, "LOT_DESC", MINVLOTSTS.INV_LOT_DESC, sizeof(MINVLOTSTS.INV_LOT_DESC));
                TRS.add_string(list_item, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
                TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
                TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
                TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
                TRS.add_double(list_item, "QTY_1", MINVLOTSTS.QTY);
                TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                TRS.add_string(list_item, "LOT_TYPE", MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV));
                TRS.add_string(list_item, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
                TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
                TRS.add_string(list_item, "ORDER_ID", MINVLOTSTS.ORDER_ID, sizeof(MINVLOTSTS.ORDER_ID));
                TRS.add_string(list_item, "OSP_ORDER_ID", MINVLOTSTS.INV_CMF_10, sizeof(MINVLOTSTS.INV_CMF_10));
                TRS.add_string(list_item, "PO_NO", MINVLOTSTS.PO_NO, sizeof(MINVLOTSTS.PO_NO));
                TRS.add_string(list_item, "LAST_COMMENT", MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT));
                TRS.add_string(list_item, "VENDOR_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
                TRS.add_string(list_item, "VENDOR_DESC", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
            }
            //kitting ID 인 경우
            else
            {
                //open-fetch에서 자재LOT이 load 되어있는지 확인한다. 
                    iStep = 4;

                DBU_init_minvlotsts(&MINVLOTSTS);
                TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER), in_node, "OPER");
                TRS.copy(MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4), in_node, "LOT_ID");
                TRS.copy(MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.LOT_ID), in_node, "NEXT_LOT_ID");
                DBU_open_minvlotsts(iStep, &MINVLOTSTS);
                if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
                    strcpy(s_msg_code, "WIP-0583");
                    TRS.add_fieldmsg(out_node, "MINVLOTSTS OPEN", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                while (1)
                {
                    DBU_fetch_minvlotsts(iStep, &MINVLOTSTS);
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        DBU_close_minvlotsts(iStep);
                        break;
                    }
                    else if (DB_error_code != DB_SUCCESS)
                    {
                        //WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
                        strcpy(s_msg_code, "WIP-0583");
                        TRS.add_fieldmsg(out_node, "MINVLOTSTS FETCH", MP_NVST);
                        TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MINVLOTSTS.OPER), MINVLOTSTS.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        DBU_close_minvlotsts(iStep);

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    if (COM_check_node_length(out_node) == MP_FALSE)
                    {
                        TRS.add_string(out_node, "NEXT_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                        DBU_close_minvlotsts(iStep);
                        break;
                    }

                    //자재 정보 조회
                    DBU_init_mwipmatdef(&MWIPMATDEF);
                    memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
                    memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
                    MWIPMATDEF.MAT_VER = 1;
                    DBU_select_mwipmatdef(1, &MWIPMATDEF);

                    //공정 정보 조회
                    DBU_init_mwipoprdef(&MWIPOPRDEF);
                    memcpy(MWIPOPRDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                    memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));
                    DBU_select_mwipoprdef(1, &MWIPOPRDEF);


                    //협력사 조회
                    DBU_init_mgcmlagdat(&MGCMLAGDAT);
                    TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
                    memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
                    memcpy(MGCMLAGDAT.KEY_1, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
                    COM_itoa_left(s_vendor_site_id, MINVLOTSTS.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
                    memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
                    DBU_select_mgcmlagdat(1, &MGCMLAGDAT);



                    list_item = TRS.add_node(out_node, "LOT_TBL");
                    TRS.add_string(list_item, "LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
                    TRS.add_string(list_item, "LOT_DESC", MINVLOTSTS.INV_LOT_DESC, sizeof(MINVLOTSTS.INV_LOT_DESC));
                    TRS.add_string(list_item, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
                    TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
                    TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
                    TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
                    TRS.add_double(list_item, "QTY_1", MINVLOTSTS.QTY);
                    TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
                    TRS.add_string(list_item, "LOT_TYPE", MP_LOT_TYPE_INV, strlen(MP_LOT_TYPE_INV));  
                    TRS.add_string(list_item, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
                    TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
                    TRS.add_string(list_item, "ORDER_ID", MINVLOTSTS.ORDER_ID, sizeof(MINVLOTSTS.ORDER_ID));
                    TRS.add_string(list_item, "OSP_ORDER_ID", MINVLOTSTS.INV_CMF_10, sizeof(MINVLOTSTS.INV_CMF_10));
                    TRS.add_string(list_item, "PO_NO", MINVLOTSTS.PO_NO, sizeof(MINVLOTSTS.PO_NO));
                    TRS.add_string(list_item, "LAST_COMMENT", MINVLOTSTS.LAST_TRAN_COMMENT, sizeof(MINVLOTSTS.LAST_TRAN_COMMENT));
                    TRS.add_string(list_item, "VENDOR_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
                    TRS.add_string(list_item, "VENDOR_DESC", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
                }
            }        
        }

    }
    //STEP 3: 공정의 lot list 찾아오기, 
    //STEP 4: 공정의 설비에 시작된 LOT LIST 찾아오기
    else if (TRS.get_procstep(in_node) == '3' || TRS.get_procstep(in_node) == '4')
    {
        DBU_init_mwiplotstsx(&MWIPLOTSTSX);
		TRS.copy(MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER), in_node, "OPER");
        if (TRS.get_procstep(in_node) == '3')
        {
			
            iStep = 2;
        }
        else
        {
			if (COM_isnullspace(TRS.get_string(in_node, "OPER")) == MP_TRUE)
			{
				iStep = 7;
			}
			else
			{
				iStep = 3;
			}
           
            TRS.copy(MWIPLOTSTSX.START_RES_ID, sizeof(MWIPLOTSTSX.START_RES_ID), in_node, "RES_ID");
        }

        TRS.copy(MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID), in_node, "NEXT_LOT_ID");
        DBU_open_mwiplotstsx(iStep, &MWIPLOTSTSX);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
            strcpy(s_msg_code, "WIP-0583");
            TRS.add_fieldmsg(out_node, "MWIPLOTSTSX OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
            TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_mwiplotstsx(iStep, &MWIPLOTSTSX);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mwiplotstsx(iStep);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0583 : 해당 공정은 LOT이 존재하지 않습니다.
                strcpy(s_msg_code, "WIP-0583");
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, iStep);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPLOTSTSX.OPER), MWIPLOTSTSX.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                DBU_close_mwiplotstsx(iStep);

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_string(out_node, "NEXT_LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
                DBU_close_mwiplotstsx(iStep);
                break;
            }

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTSX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //lot 공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTSTSX.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            //lot flow 정보 조회
            DBU_init_mwipflwdef(&MWIPFLWDEF);
            memcpy(MWIPFLWDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
            memcpy(MWIPFLWDEF.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWDEF.FLOW));
            DBU_select_mwipflwdef(1, &MWIPFLWDEF);

            //불량 저장 정보 조회
            DBU_init_cwiplotlst(&CWIPLOTLST);
            memcpy(CWIPLOTLST.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(CWIPLOTLST.LOT_ID));
            //CWIPLOTLST.HIST_SEQ = MWIPLOTSTSX.LAST_HIST_SEQ;
            memcpy(CWIPLOTLST.OPER, MWIPLOTSTSX.OPER, sizeof(CWIPLOTLST.OPER));
            dSumLoss = DBU_select_cwiplotlst_scalar(3, &CWIPLOTLST);

            list_item = TRS.add_node(out_node, "LOT_TBL");
            TRS.add_string(list_item, "LOT_ID", MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
            TRS.add_string(list_item, "LOT_DESC", MWIPLOTSTSX.LOT_DESC, sizeof(MWIPLOTSTSX.LOT_DESC));
            TRS.add_string(list_item, "MAT_ID", MWIPLOTSTSX.MAT_ID, sizeof(MWIPLOTSTSX.MAT_ID));
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
            TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
            TRS.add_string(list_item, "OPER", MWIPLOTSTSX.OPER, sizeof(MWIPLOTSTSX.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_string(list_item, "FLOW", MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW));
            TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));

            TRS.add_double(list_item, "QTY_1", MWIPLOTSTSX.QTY_1);
            TRS.add_double(list_item, "LOSS_QTY", dSumLoss);

            TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            //area 정보 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));

            //sub area 정보 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            TRS.add_string(list_item, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
            TRS.add_string(list_item, "CREATE_TIME", MWIPLOTSTSX.CREATE_TIME, sizeof(MWIPLOTSTSX.CREATE_TIME));
            TRS.add_string(list_item, "START_TIME", MWIPLOTSTSX.START_TIME, sizeof(MWIPLOTSTSX.START_TIME));
            TRS.add_string(list_item, "COMMENT", MWIPLOTSTSX.LAST_COMMENT, sizeof(MWIPLOTSTSX.LAST_COMMENT));

            TRS.add_string(list_item, "CREATE_CODE", MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));

            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_CREATE_CODE, strlen(MP_WIP_CREATE_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTSX.CREATE_CODE, sizeof(MWIPLOTSTSX.CREATE_CODE));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);

            TRS.add_string(list_item, "CREATE_CODE_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));


            //LOT CMF 정보
            TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1));     //그룹id
            TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2));     //그룹id 순번
            TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3));
            TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4));
            TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5));
            TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6));
            TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7));
            TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8));
            TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9));
            TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10));
            TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11));
            TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12));
            TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13));
            TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14));
            TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15));
            TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16));
            TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17));
            TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18));
            TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19));
            TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20));

            //CTM CMF 정보
            TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1));
            TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_2));
            TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_3));
            TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_4));
            TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_5));
            TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_6));
            TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_7));
            TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_8));
            TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_9));
            TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_10));
            TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_11));
            TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_12));
            TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_13));
            TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_14));
            TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_15));
            TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_16));
            TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_17));
            TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_18));
            TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_19));
            TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_20));

            //PDC CMF 정보
            TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1));
            TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_2));
            TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_3));
            TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_4));
            TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_5));
            TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_6));
            TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_7));
            TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_8));
            TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_9));
            TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_10));
            TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_11));
            TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_12));
            TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_13));
            TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_14));
            TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_15));
            TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_16));
            TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_17));
            TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_18));
            TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_19));
            TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_20));

            //HM CMF 정보
            TRS.add_string(list_item, "HM_CMF_1", MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1));
            TRS.add_string(list_item, "HM_CMF_2", MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_2));
            TRS.add_string(list_item, "HM_CMF_3", MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_3));
            TRS.add_string(list_item, "HM_CMF_4", MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_4));
            TRS.add_string(list_item, "HM_CMF_5", MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_5));
            TRS.add_string(list_item, "HM_CMF_6", MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_6));
            TRS.add_string(list_item, "HM_CMF_7", MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_7));
            TRS.add_string(list_item, "HM_CMF_8", MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_8));
            TRS.add_string(list_item, "HM_CMF_9", MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_9));
            TRS.add_string(list_item, "HM_CMF_10", MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_10));
            TRS.add_string(list_item, "HM_CMF_11", MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_11));
            TRS.add_string(list_item, "HM_CMF_12", MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_12));
            TRS.add_string(list_item, "HM_CMF_13", MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_13));
            TRS.add_string(list_item, "HM_CMF_14", MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_14));
            TRS.add_string(list_item, "HM_CMF_15", MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_15));
            TRS.add_string(list_item, "HM_CMF_16", MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_16));
            TRS.add_string(list_item, "HM_CMF_17", MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_17));
            TRS.add_string(list_item, "HM_CMF_18", MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_18));
            TRS.add_string(list_item, "HM_CMF_19", MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_19));
            TRS.add_string(list_item, "HM_CMF_20", MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_20));

            //GRIT CMF 정보
            TRS.add_string(list_item, "GRT_CMF_1", MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1));
            TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2));
            TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3));
            TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4));
            TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5));
            TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6));
            TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_7));
            TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_8));
            TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_9));
            TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_10));
            TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_11));
            TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_12));
            TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_13));
            TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_14));
            TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_15));
            TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_16));
            TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_17));
            TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_18));
            TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_19));
            TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_20));

            //설비 정보
            if (MWIPLOTSTSX.END_RES_ID[0] != ' ')
            {
                TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.END_RES_ID, sizeof(MWIPLOTSTSX.END_RES_ID));
            }
            else
            {
                TRS.add_string(list_item, "RES_ID", MWIPLOTSTSX.START_RES_ID, sizeof(MWIPLOTSTSX.START_RES_ID));
            }

            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MRASRESDEF.FACTORY));
            TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), list_item, "RES_ID");
            DBU_select_mrasresdef(1, &MRASRESDEF);
            if (DB_error_code == DB_SUCCESS)
            {
                TRS.add_string(list_item, "RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));
            }

        }
    }
   
    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Lot_Info_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_LOT_INFO" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Lot_Info_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{

    /* ProcStep Validation */
    // 1 - 
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "1234") == MP_FALSE)
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
