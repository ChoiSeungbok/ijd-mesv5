/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_start_lot.c
Description : Tran start Lot function

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/03  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_WIP_common.h"
#include "ACTCore_common.h"

int CUS_WIP_Start_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Start_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_Start_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_Start_Lot()
- Tran start Lot
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Start_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_START_LOT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Start_Lot", out_node);
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
CUS_WIP_START_LOT()
- Main sub function of "CUS_WIP_Start_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *start_in_node;
    struct work_date_tag work_date;
    char s_factory[10];

    int i = 0;
    int j = 0;
    char s_member[5][101] = {"LOT_CMF_","CTM_CMF_", "PDC_CMF_", "HM_CMF_","GRT_CMF_"};
    char s_member_name[101];

    LOG_head("CUS_WIP_Start_Lot");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_Start_Lot_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    TRS.copy(s_factory, sizeof(s_factory), in_node, IN_FACTORY);
    memset(&work_date, ' ' , sizeof(work_date));

    Get_shift(s_factory, &work_date);

    //start 시작
    start_in_node = TRS.add_node(in_node, "start_in_node");

    TRS.add_char(start_in_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(start_in_node, in_node);

    //create 시간은 클라이언트에서 서버 호출 시간으로 한다. 
    //gs_sys_time를 사용하는 이유는 create -> start가 같은 시간에 들어가도록 하기 위해.
    if (COM_isnullspace(TRS.get_string(in_node, "BACK_TIME")) == MP_FALSE)
        TRS.add_nstring(start_in_node, "BACK_TIME", TRS.get_string(in_node, "BACK_TIME"));
    else
        TRS.add_string(start_in_node, "BACK_TIME", gs_sys_time, sizeof(gs_sys_time));

    //필수값
    TRS.add_nstring(start_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_nstring(start_in_node, "MAT_ID", TRS.get_string(in_node, "MAT_ID"));
    TRS.add_int(start_in_node, "MAT_VER", TRS.get_int(in_node, "MAT_VER"));
    TRS.add_nstring(start_in_node, "FLOW", TRS.get_string(in_node, "FLOW"));
    TRS.add_nstring(start_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(start_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_FALSE)
        TRS.add_nstring(start_in_node, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_1")) == MP_FALSE)
        TRS.add_nstring(start_in_node, "ADD_ORDER_ID_1", TRS.get_string(in_node, "ADD_ORDER_ID_1"));

    //추가 정보성 데이터
    TRS.add_string(start_in_node, "TRAN_CMF_1", work_date.s_work_date, sizeof(work_date.s_work_date));
    TRS.add_string(start_in_node, "TRAN_CMF_2", work_date.s_day_night, sizeof(work_date.s_day_night));
    TRS.add_nstring(start_in_node, "TRAN_CMF_3", TRS.get_string(in_node, "TRAN_CMF_3"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_4", TRS.get_string(in_node, "TRAN_CMF_4"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_5", TRS.get_string(in_node, "TRAN_CMF_5"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_6", TRS.get_string(in_node, "TRAN_CMF_6"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_7", TRS.get_string(in_node, "TRAN_CMF_7"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_8", TRS.get_string(in_node, "TRAN_CMF_8"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_9", TRS.get_string(in_node, "TRAN_CMF_9"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_10", TRS.get_string(in_node, "TRAN_CMF_10"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_11", TRS.get_string(in_node, "TRAN_CMF_11"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_12", TRS.get_string(in_node, "TRAN_CMF_12"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_13", TRS.get_string(in_node, "TRAN_CMF_13"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_14", TRS.get_string(in_node, "TRAN_CMF_14"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_15", TRS.get_string(in_node, "TRAN_CMF_15"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_16", TRS.get_string(in_node, "TRAN_CMF_16"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_17", TRS.get_string(in_node, "TRAN_CMF_17"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_18", TRS.get_string(in_node, "TRAN_CMF_18"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_19", TRS.get_string(in_node, "TRAN_CMF_19"));
    TRS.add_nstring(start_in_node, "TRAN_CMF_20", TRS.get_string(in_node, "TRAN_CMF_20"));
    TRS.add_nstring(start_in_node, "COMMENT", TRS.get_string(in_node, "COMMENT"));
    TRS.add_char(start_in_node, "RESV_FLAG_1", TRS.get_char(in_node, "RESV_FLAG_1"));
    TRS.add_char(start_in_node, "RESV_FLAG_2", TRS.get_char(in_node, "RESV_FLAG_2"));
    TRS.add_char(start_in_node, "RESV_FLAG_3", TRS.get_char(in_node, "RESV_FLAG_3"));
    TRS.add_char(start_in_node, "RESV_FLAG_4", TRS.get_char(in_node, "RESV_FLAG_4"));
    TRS.add_char(start_in_node, "RESV_FLAG_5", TRS.get_char(in_node, "RESV_FLAG_5"));
    TRS.add_nstring(start_in_node, "RESV_FIELD_1", TRS.get_string(in_node, "RESV_FIELD_1"));
    TRS.add_nstring(start_in_node, "RESV_FIELD_2", TRS.get_string(in_node, "RESV_FIELD_2"));
    TRS.add_nstring(start_in_node, "RESV_FIELD_3", TRS.get_string(in_node, "RESV_FIELD_3"));
    TRS.add_nstring(start_in_node, "RESV_FIELD_4", TRS.get_string(in_node, "RESV_FIELD_4"));
    TRS.add_nstring(start_in_node, "RESV_FIELD_5", TRS.get_string(in_node, "RESV_FIELD_5"));
    TRS.add_char(start_in_node, "RWK_FLAG", TRS.get_char(in_node, "RWK_FLAG"));
    TRS.add_nstring(start_in_node, "RWK_CODE", TRS.get_string(in_node, "RWK_CODE"));
    TRS.add_char(start_in_node, "CLASS_OPER_SKIP", TRS.get_char(in_node, "CLASS_OPER_SKIP"));  //분류정보시 작지 실적UPDATE SKIP여부

    if (COM_isnullspace(TRS.get_string(in_node, "SAVE_RES_ID_1")) == MP_FALSE)
        TRS.add_nstring(start_in_node, "SAVE_RES_ID_1", TRS.get_string(in_node, "SAVE_RES_ID_1"));

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 20; i++)
        {
            sprintf(s_member_name, "%s%d", s_member[j], i + 1);
            TRS.add_nstring(start_in_node, s_member_name, TRS.get_string(in_node, s_member_name));
        }
    }

    if (CUS_WIP_Start_Lot_Before_Transaction(s_msg_code, 0, start_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (WIP_START_LOT(s_msg_code, start_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (CUS_WIP_Start_Lot_After_Transaction(s_msg_code, 0, start_in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }



    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_Start_Lot_Validation()
- Validation Check sub function of "CUS_WIP_CREATE_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Start_Lot_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Start_Lot_Before_Transaction()
- Main sub function of "CUS_WIP_START_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Start_Lot_Before_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;    
    struct MWIPLOTHISX_TAG MWIPLOTHISX;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
    struct CWIPORDBOM_TAG CWIPORDBOM;
    struct CWIPINVLDM_TAG CWIPINVLDM;       //자재 LOAD 테이블
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF_ERP;
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct CWIPORDOPR_TAG CWIPORDOPR;
    struct MWIPFLWOPR_TAG MWIPFLWOPR;
    struct CWIPERPOPR_TAG CWIPERPOPR;
    struct CWIPLOTREC_TAG CWIPLOTREC;
	struct MRASRESDEF_TAG MRASRESDEF;

    int iCount = 0;
    int i_Step = 0;
    double dOverOrderQty = 0;
    double dOrderQty = 0;
    double dOverPer = 0;

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

    //P급인지 체크
    DBU_init_cwiplotrec(&CWIPLOTREC);
    memcpy(CWIPLOTREC.FACTORY, MWIPLOTSTSX.FACTORY, sizeof(MWIPLOTSTSX.FACTORY));
    memcpy(CWIPLOTREC.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    DBU_select_cwiplotrec(2, &CWIPLOTREC);
    if (DB_error_code == DB_SUCCESS)
    {

        //DBU_delete_cwiplotrec(2, &CWIPLOTREC)

         DBU_update_cwiplotrec(5, &CWIPLOTREC);
         if (DB_error_code != DB_SUCCESS)
         {
             //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
             strcpy(s_msg_code, "ADM-0004");
             TRS.add_fieldmsg(out_node, "CWIPLOTREC UPDATE", DT_NOVALUESTRING);
             TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
             TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

             TRS.add_dberrmsg(out_node, DB_error_msg);

             return MP_FALSE;
         }
            /*
        //WIP-0668 : P급은 작업을 진행 할 수 없습니다. LOT을 확인하세요.
        strcpy(s_msg_code, "WIP-0668");
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
        */
    }

    //공정 조회
    DBU_init_mwipoprdef(&MWIPOPRDEF);
    TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
    TRS.copy(MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER), in_node, "OPER");
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

    /*gcm의 SYSTEM_OPTION 에 셋업된 정보를 가져온다.
        KEY_1  : CUSTOM SYSTEM OPTION 코드
        DATA_1 : CUSTOM SYSTEM OPTION 명칭
        DATA_2 : OPTION 값
        DATA_3 : OPTION 사용여부
    */
    //CUSTOM SYSTEM 옵션 조회
    DBU_init_mgcmtbldat(&MGCMTBLDAT);
    TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
    memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_SYSTEM, strlen(MP_GCM_SYSTEM));
    memcpy(MGCMTBLDAT.KEY_1, MP_SYS_START_BOM_CHECK, strlen(MP_SYS_START_BOM_CHECK));
    DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
    if (DB_error_code != DB_SUCCESS)
    {
        //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
        strcpy(s_msg_code, "GCM-0008");
        TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
        TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_VIEW;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }
    //공정 시작시 자재 투입 BOM리스트가 있는 공정인 경우 자재가 투입되지 않으면 투입처리 되도록 벨리데이션
    if (MGCMTBLDAT.DATA_3[0] == 'Y')
    {
        DBU_init_cwipordbom(&CWIPORDBOM);
        TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPORDBOM.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID), in_node, "ORDER_ID");
        TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), in_node, "OPER");
        
        //공정에 bom단위 투입 리스트가 있는지 조회
        if (DBU_select_cwipordbom_scalar(2, &CWIPORDBOM) > 0)
        {
            i_Step = 2;

            DBU_init_cwipordbom(&CWIPORDBOM);
            TRS.copy(CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPORDBOM.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID), in_node, "ORDER_ID");
            TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), in_node, "OPER");
            DBU_open_cwipordbom(i_Step, &CWIPORDBOM);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                strcpy(s_msg_code, "WIP-0585");
                TRS.add_fieldmsg(out_node, "CWIPORDBOM OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDBOM.OPER), CWIPORDBOM.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            while (1)
            {
                DBU_fetch_cwipordbom(i_Step, &CWIPORDBOM);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_cwipordbom(i_Step);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                    strcpy(s_msg_code, "WIP-0585");
                    TRS.add_fieldmsg(out_node, "CWIPORDBOM FATCH", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDBOM.OPER), CWIPORDBOM.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_cwipordbom(i_Step);
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                DBU_init_cwipinvldm(&CWIPINVLDM);
                memcpy(CWIPINVLDM.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
                memcpy(CWIPINVLDM.ORDER_ID, CWIPORDBOM.ORDER_ID, sizeof(CWIPORDBOM.ORDER_ID));
                memcpy(CWIPINVLDM.OPER, CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER));
                CWIPINVLDM.REL_LEVEL = '2';
                memcpy(CWIPINVLDM.MAT_ID, CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));

                if (DBU_select_cwipinvldm_scalar(3, &CWIPINVLDM) == 0)
                {
                    //WIP-0585 : 투입된 자재가 없습니다. 자재를 투입해 주세요.
                    strcpy(s_msg_code, "WIP-0585");
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPINVLDM.OPER), CWIPINVLDM.OPER);
                    TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPINVLDM.MAT_ID), CWIPINVLDM.MAT_ID);
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

    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y' )
    {
        //lot이 일반 생산 품인 경우(테스트 lot이 아닌경우) 만 erp 공정과 flow의 공정을 체크 한다.
        if (MWIPLOTSTSX.LOT_TYPE == MP_LOT_TYPE_P)
        {
            i_Step = 2;

            //flow의 erp작업 공정 체크한다.
            DBU_init_mwipflwopr(&MWIPFLWOPR);
            TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW), in_node, "FLOW");
            DBU_open_mwipflwopr(i_Step, &MWIPFLWOPR);
            if (DB_error_code != DB_SUCCESS)
            {
                //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                strcpy(s_msg_code, "ORD-0008");
                TRS.add_fieldmsg(out_node, "MWIPFLWOPR OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            while (1)
            {
                DBU_fetch_mwipflwopr(i_Step, &MWIPFLWOPR);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_mwipflwopr(i_Step);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                    strcpy(s_msg_code, "ORD-0008");
                    TRS.add_fieldmsg(out_node, "MWIPFLWOPR FETCH", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_mwipflwopr(i_Step);
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                DBU_init_mwipoprdef(&MWIPOPRDEF_ERP);
                TRS.copy(MWIPOPRDEF_ERP.FACTORY, sizeof(MWIPOPRDEF_ERP.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_ERP.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF_ERP);

                //ERP공정이 없거나, 창고 공정인 경우는 제외
                if (MWIPOPRDEF_ERP.OPER_CMF_1[0] == ' ' || MWIPOPRDEF_ERP.INV_FLAG == 'Y')
                {
                    continue;
                }

                //주말 선방전 pass 임시 코딩
                if (memcmp(MWIPOPRDEF_ERP.OPER, "OC04050", strlen("OC04050")) == MP_FALSE)
                {
                    continue;
                }

                DBU_init_cwiperpopr(&CWIPERPOPR);
                memcpy(CWIPERPOPR.FACTORY, MWIPOPRDEF_ERP.FACTORY, sizeof(MWIPOPRDEF_ERP.FACTORY));
                TRS.copy(CWIPERPOPR.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID), in_node, "ORDER_ID");
                memcpy(CWIPERPOPR.OPER, MWIPOPRDEF_ERP.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
                DBU_select_cwiperpopr(2, &CWIPERPOPR);
                if (DB_error_code != DB_SUCCESS)
                {
                    if (DB_error_code == DB_NOT_FOUND)
                    {
                        //WIP-0650 : MES공정과 ERP의 공정이 같지 않습니다. 작업지시의 FLOW를 조정하세요.
                        strcpy(s_msg_code, "WIP-0650");
                        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        return MP_FALSE;
                    }
                }
            }

            i_Step = 3;

            DBU_init_cwiperpopr(&CWIPERPOPR);
            memcpy(CWIPERPOPR.FACTORY, MWIPOPRDEF_ERP.FACTORY, sizeof(MWIPOPRDEF_ERP.FACTORY));
            TRS.copy(CWIPERPOPR.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID), in_node, "ORDER_ID");
            DBU_open_cwiperpopr(i_Step, &CWIPERPOPR);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0651 : 작업지시에 ERP공정 존재하지 않습니다. 작업지시를 확인하세요.
                strcpy(s_msg_code, "WIP-0651");
                TRS.add_fieldmsg(out_node, "CWIPERPOPR OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            while (1)
            {
                DBU_fetch_cwiperpopr(i_Step, &CWIPERPOPR);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_cwiperpopr(i_Step);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //WIP-0651 : 작업지시에 ERP공정 존재하지 않습니다. 작업지시를 확인하세요.
                    strcpy(s_msg_code, "WIP-0651");
                    TRS.add_fieldmsg(out_node, "CWIPERPOPR FETCH", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_cwiperpopr(i_Step);
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                DBU_init_mwipoprdef(&MWIPOPRDEF_ERP);
                TRS.copy(MWIPOPRDEF_ERP.FACTORY, sizeof(MWIPOPRDEF_ERP.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF_ERP.OPER_CMF_1, CWIPERPOPR.OPER, sizeof(MWIPOPRDEF_ERP.OPER_CMF_1));
                TRS.copy(MWIPOPRDEF_ERP.OPER_CMF_2, sizeof(MWIPOPRDEF_ERP.OPER_CMF_2), in_node, "FLOW");
                if ((int)DBU_select_mwipoprdef_scalar(2, &MWIPOPRDEF_ERP) == 0)
                {
                    //WIP-0650 : MES공정과 ERP의 공정이 같지 않습니다. 작업지시의 FLOW를 조정하세요.
                    strcpy(s_msg_code, "WIP-0650");
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }

            /*gcm의 SYSTEM_OPTION 에 셋업된 정보를 가져온다.
                KEY_1  : CUSTOM SYSTEM OPTION 코드
                DATA_1 : CUSTOM SYSTEM OPTION 명칭
                DATA_2 : OPTION 값
                DATA_3 : OPTION 사용여부
            */

            //CUSTOM SYSTEM 옵션 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_SYSTEM, strlen(MP_GCM_SYSTEM));
            memcpy(MGCMTBLDAT.KEY_1, MP_SYS_CHECK_ERP_OPER, strlen(MP_SYS_CHECK_ERP_OPER));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            if (DB_error_code != DB_SUCCESS)
            {
                //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                strcpy(s_msg_code, "GCM-0008");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            //MES 공정별 작업지시에 ERP 공정이 있는지 확인한다.
            if (MGCMTBLDAT.DATA_3[0] == 'Y')
            {
                //주말 선방전 pass 임시 코딩
                if (memcmp(MWIPOPRDEF.OPER, "OC04050", strlen("OC04050")) != MP_FALSE)
                {
                    //ERP 공정이 셋업되어 있는 공정인 경우 ERP공정과 비교 벨리데이션에
                    if (MWIPOPRDEF.OPER_CMF_1[0] != ' ')
                    {
                        DBU_init_cwiperpopr(&CWIPERPOPR);
                        memcpy(CWIPERPOPR.FACTORY, MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
                        TRS.copy(CWIPERPOPR.ORDER_ID, sizeof(CWIPERPOPR.ORDER_ID), in_node, "ORDER_ID");
                        memcpy(CWIPERPOPR.OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(CWIPERPOPR.OPER));
                        DBU_select_cwiperpopr(2, &CWIPERPOPR);
                        if (DB_error_code != DB_SUCCESS)
                        {
                            if (DB_error_code == DB_NOT_FOUND)
                            {
                                //WIP-0650 : MES공정과 ERP의 공정이 같지 않습니다. 작업지시의 FLOW를 조정하세요.
                                strcpy(s_msg_code, "WIP-0650");
                                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPERPOPR.FACTORY), CWIPERPOPR.FACTORY);
                                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPERPOPR.ORDER_ID), CWIPERPOPR.ORDER_ID);
                                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPERPOPR.OPER), CWIPERPOPR.OPER);
                                TRS.add_dberrmsg(out_node, DB_error_msg);

                                return MP_FALSE;
                            }
                        }
                    }
                }
            }      
        }

        //CWIPORDOPR에 공정별 ORDER 정보가 없으면 FLOW에 해당하는 공정으로 해서 INSERT해준다. 
        DBU_init_cwipordopr(&CWIPORDOPR);
        TRS.copy(CWIPORDOPR.FACTORY, sizeof(CWIPORDOPR.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPORDOPR.ORDER_ID, sizeof(CWIPORDOPR.ORDER_ID), in_node, "ORDER_ID");
        
        iCount = (int)DBU_select_cwipordopr_scalar(2, &CWIPORDOPR);

        if (iCount == 0)
        {
            i_Step = 2;

            DBU_init_mwipflwopr(&MWIPFLWOPR);
            TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
            TRS.copy(MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW), in_node, "FLOW");
            DBU_open_mwipflwopr(i_Step, &MWIPFLWOPR);
            if (DB_error_code != DB_SUCCESS)
            {
                //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                strcpy(s_msg_code, "ORD-0008");
                TRS.add_fieldmsg(out_node, "MWIPFLWOPR OPEN", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }
            while (1)
            {
                DBU_fetch_mwipflwopr(i_Step, &MWIPFLWOPR);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_mwipflwopr(i_Step);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    //ORD-0008 : 이 FLOW는 존재하지 않습니다.
                    strcpy(s_msg_code, "ORD-0008");
                    TRS.add_fieldmsg(out_node, "MWIPFLWOPR FETCH", MP_NVST);
                    TRS.add_fieldmsg(out_node, "step", MP_INT, i_Step);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPFLWOPR.FACTORY), MWIPFLWOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPFLWOPR.FLOW), MWIPFLWOPR.FLOW);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    DBU_close_mwipflwopr(i_Step);
                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //공정 조회
                DBU_init_mwipoprdef(&MWIPOPRDEF);
                TRS.copy(MWIPOPRDEF.FACTORY, sizeof(MWIPOPRDEF.FACTORY), in_node, IN_FACTORY);
                memcpy(MWIPOPRDEF.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                DBU_select_mwipoprdef(1, &MWIPOPRDEF);

                DBU_init_cwipordopr(&CWIPORDOPR);
                TRS.copy(CWIPORDOPR.FACTORY, sizeof(CWIPORDOPR.FACTORY), in_node, IN_FACTORY);
                TRS.copy(CWIPORDOPR.ORDER_ID, sizeof(CWIPORDOPR.ORDER_ID), in_node, "ORDER_ID");
                memcpy(CWIPORDOPR.OPER, MWIPFLWOPR.OPER, sizeof(MWIPFLWOPR.OPER));
                memcpy(CWIPORDOPR.FLOW, MWIPFLWOPR.FLOW, sizeof(MWIPFLWOPR.FLOW));
                CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_WAIT;
                memcpy(CWIPORDOPR.AREA_ID, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
                memcpy(CWIPORDOPR.SUB_AREA_ID, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
                memcpy(CWIPORDOPR.ERP_OPER, MWIPOPRDEF.OPER_CMF_1, sizeof(MWIPOPRDEF.OPER_CMF_1));
                DBU_insert_cwipordopr(&CWIPORDOPR);
                if (DB_error_code != DB_SUCCESS)
                {
                    //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "ADM-0004");
                    TRS.add_fieldmsg(out_node, "CWIPORDOPR INSERT ", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDOPR.FACTORY), CWIPORDOPR.FACTORY);
                    TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDOPR.ORDER_ID), CWIPORDOPR.ORDER_ID);
                    TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDOPR.OPER), CWIPORDOPR.OPER);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    return MP_FALSE;
                }
            }
        }

        //시작공정이 CREATE하는 공정이 아닌경우. => CTM 외경가공 또는 작업지시 공정인 경우 
        if (MWIPOPRDEF.OPER_CMF_2[0] == 'Y')
        {
            DBU_init_mwiplothisx(&MWIPLOTHISX);
            TRS.copy(MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID), in_node, "LOT_ID");
            TRS.copy(MWIPLOTHISX.ORDER_ID, sizeof(MWIPLOTHISX.ORDER_ID), in_node, "ORDER_ID");
            memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_CREATE, strlen(MP_TRAN_CODE_CREATE));
            iCount = (int)DBU_select_mwiplothisx_scalar(3, &MWIPLOTHISX);

            if (iCount == 0)
            {
                /*gcm의 SYSTEM_OPTION 에 셋업된 정보를 가져온다.
                KEY_1  : CUSTOM SYSTEM OPTION 코드
                DATA_1 : CUSTOM SYSTEM OPTION 명칭
                DATA_2 : OPTION 값
                DATA_3 : OPTION 사용여부
                */
                //CUSTOM SYSTEM 옵션 조회
                DBU_init_mgcmtbldat(&MGCMTBLDAT);
                TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
                memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_SYSTEM, strlen(MP_GCM_SYSTEM));
                memcpy(MGCMTBLDAT.KEY_1, MP_SYS_ORDER_OVER_QTY, strlen(MP_SYS_ORDER_OVER_QTY));
                DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
                if (DB_error_code != DB_SUCCESS)
                {
                    //GCM-0008 : TABLE에 존재하지 않는 항목입니다.
                    strcpy(s_msg_code, "GCM-0008");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT SELECT", MP_NVST);
                    TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    gs_log_type.type = MP_LOG_ERROR;
                    gs_log_type.e_type = MP_LOG_E_SYSTEM;
                    gs_log_type.category = MP_LOG_CATE_VIEW;

                    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                    return MP_FALSE;
                }

                //작업지시 생성수량의 over생상 범위 (%)
                dOverPer = atof(MGCMTBLDAT.DATA_2);

                //작업지시 조회
                DBU_init_mwipordsts(&MWIPORDSTS);
                TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
                TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
                DBU_select_mwipordsts(1, &MWIPORDSTS);
                if (DB_error_code == DB_SUCCESS)
                {
                    //작업지시가 대기 상태면 작업지시 시작처리 해준다.
                    if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
                    {
                        MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;
                    }

                    dOverOrderQty = MWIPORDSTS.ORD_QTY * (1 + (dOverPer / 100));
                    dOrderQty = MWIPORDSTS.ORD_IN_QTY + MWIPLOTSTSX.QTY_1;

                    //작업지시 수량 체크 확인 여부가 'Y'인경우 생성수량 체크를 한다.
                    if (MGCMTBLDAT.DATA_3[0] == 'Y')
                    {
                        if (dOrderQty > dOverOrderQty)
                        {
                            //WIP-0619 : 작업지시에 대한 Lot 생성 수량이 초과 되었습니다. Lot 생성수량과 작업지시 수량을 확인하세요.
                            strcpy(s_msg_code, "WIP-0619");
                            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
                            TRS.add_dberrmsg(out_node, DB_error_msg);

                            gs_log_type.type = MP_LOG_ERROR;
                            gs_log_type.e_type = MP_LOG_E_SYSTEM;
                            gs_log_type.category = MP_LOG_CATE_VIEW;

                            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                            return MP_FALSE;
                        }
                    }

                    //lot 생성시 작업지시에서 create 생성 수량 필드 값을 올려준다.
                    MWIPORDSTS.ORD_IN_QTY = dOrderQty;
                    memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
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
            }
        }
    }

    //기존 LOT이 END 했던 공정인 경우 재작업 여부(RESV_FLAG_1)를 업데이트 한다. 
    DBU_init_mwiplothisx(&MWIPLOTHISX);
    memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));
    memcpy(MWIPLOTHISX.OLD_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    memcpy(MWIPLOTHISX.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
    memcpy(MWIPLOTHISX.TRAN_CODE, MP_TRAN_CODE_END, strlen(MP_TRAN_CODE_END));
    iCount = (int)DBU_select_mwiplothisx_scalar(5, &MWIPLOTHISX);
    if (iCount > 0)
    {
        MWIPLOTSTSX.RESV_FLAG_1 = 'Y';
        MWIPLOTSTSX.RWK_COUNT = MWIPLOTSTSX.RWK_COUNT + 1;
    }

    //flow에 첫 공정에 order id 를 바꾼다.
    DBU_init_mwipflwopr(&MWIPFLWOPR);
    TRS.copy(MWIPFLWOPR.FACTORY, sizeof(MWIPFLWOPR.FACTORY), in_node, IN_FACTORY);
    memcpy(MWIPFLWOPR.FLOW, MWIPLOTSTSX.FLOW, sizeof(MWIPFLWOPR.FLOW));
    memcpy(MWIPFLWOPR.OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
    DBU_select_mwipflwopr(1, &MWIPFLWOPR);
    if (DB_error_code == DB_SUCCESS)
    {
        if (MWIPFLWOPR.SEQ_NUM == 1)
        {
            //ORDER_ID는 START시 자동 업데이트가 안되므로 BEFORE 에서 업데이트를 해준다.
            if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_FALSE)
            {
                TRS.copy(MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID), in_node, "ORDER_ID");
            }
        }
    }

    //중요설비인 경우 자동 업데이트가 안되므로 BEFORE 에서 업데이트를 해준다.
    if (COM_isnullspace(TRS.get_string(in_node, "SAVE_RES_ID_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.SAVE_RES_ID_1, sizeof(MWIPLOTSTSX.SAVE_RES_ID_1), in_node, "SAVE_RES_ID_1");
    }

    DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
    if (DB_error_code != DB_SUCCESS)
    {
        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
        strcpy(s_msg_code, "ADM-0004");
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE(1) ", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTSTSX.FACTORY), MWIPLOTSTSX.FACTORY);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
    {
        if (TRS.mem_cmp(in_node, "ORDER_ID", MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID)) != MP_FALSE)
        {
            //WIP-0647 : 작업지시와 LOT의 작업지시가 다릅니다. 작업지시번호를 확인하세요.
            strcpy(s_msg_code, "WIP-0647");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
    }

	if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) != MP_TRUE)
	{
		//설비 이벤트에서 설비 상태값이 변경되기 때문에 조회해서 다시 넘겨준다.
		DBU_init_mrasresdef(&MRASRESDEF);
		TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
		TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
		DBU_select_mrasresdef(1, &MRASRESDEF);
		if (DB_error_code == DB_SUCCESS)
		{
			TRS.add_char(in_node, "RES_UP_DOWN_FLAG_VALUE", MRASRESDEF.RES_UP_DOWN_FLAG);
			TRS.add_string(in_node, "RES_PRI_STS_VALUE", MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS));
		}
	}
	
    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_Start_Lot_After_Transaction()
- Main sub function of "CUS_WIP_START_LOT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Start_Lot_After_Transaction(char *s_msg_code, int msg_id, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG  MWIPLOTSTSX;
    struct CWIPORDOPR_TAG   CWIPORDOPR;
    struct MWIPORDSTS_TAG   MWIPORDSTS;
	struct MRASRESDEF_TAG MRASRESDEF;
    

    if (COM_UPDATE_LOT_CMF(TRS.get_string(in_node, "LOT_ID"), s_msg_code, in_node, out_node) == MP_FALSE)
    {
        return MP_FALSE;
    }

    TRS.add_nstring(in_node, "TRAN_CODE", "START");
    // Lot 별 Summary
    if(Update_Lot_Summary(s_msg_code, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    //lot조회
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

    //CLASS_OPER_SKIP가 Y시(그릿 분류) SKIP 처리 한다. 
    //그릿의 분류는 작업지시가 없지 진행되기 때문에. 
    if (TRS.get_char(in_node, "CLASS_OPER_SKIP") != 'Y')
    {
        //작업지시 조회
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code == DB_SUCCESS)
        {
            //작업지시가 대기 상태면 작업지시 시작처리 해준다.
            if (MWIPORDSTS.ORD_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
            {
                MWIPORDSTS.ORD_STATUS_FLAG = MP_CWIP_ORDER_START;

                memcpy(MWIPORDSTS.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
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
        }

        //공정별 시작 수량 update
        DBU_init_cwipordopr(&CWIPORDOPR);
        TRS.copy(CWIPORDOPR.FACTORY, sizeof(CWIPORDOPR.FACTORY), in_node, IN_FACTORY);
        memcpy(CWIPORDOPR.ORDER_ID, MWIPLOTSTSX.ORDER_ID, sizeof(MWIPLOTSTSX.ORDER_ID));
        TRS.copy(CWIPORDOPR.OPER, sizeof(CWIPORDOPR.OPER), in_node, "OPER");
        DBU_select_cwipordopr(1, &CWIPORDOPR);
        if (DB_error_code == DB_SUCCESS)
        {
            if (CWIPORDOPR.OPER_START_TIME[0] == ' ')
            {
                memcpy(CWIPORDOPR.OPER_START_TIME, gs_sys_time, sizeof(CWIPORDOPR.OPER_START_TIME));
                TRS.copy(CWIPORDOPR.OPER_START_DATE, sizeof(CWIPORDOPR.OPER_START_DATE), in_node, "TRAN_CMF_1");
            }

            //대기 상태면 작업지시 시작처리 해준다.
            if (CWIPORDOPR.OPER_STATUS_FLAG == MP_CWIP_ORDER_WAIT)
            {
                CWIPORDOPR.OPER_STATUS_FLAG = MP_CWIP_ORDER_START;
            }

            if(MWIPLOTSTSX.RESV_FLAG_1 == 'Y')
                CWIPORDOPR.OPER_RWK_IN_QTY = CWIPORDOPR.OPER_RWK_IN_QTY + MWIPLOTSTSX.QTY_1;
            else            
                CWIPORDOPR.OPER_IN_QTY = CWIPORDOPR.OPER_IN_QTY + MWIPLOTSTSX.QTY_1;

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

	DBU_init_mrasresdef(&MRASRESDEF);
	TRS.copy(MRASRESDEF.FACTORY, sizeof(MRASRESDEF.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID), in_node, "RES_ID");
	DBU_select_mrasresdef(1, &MRASRESDEF);
	if (DB_error_code == DB_SUCCESS)
	{
		MRASRESDEF.RES_UP_DOWN_FLAG = TRS.get_char(in_node, "RES_UP_DOWN_FLAG_VALUE");
		TRS.copy(MRASRESDEF.RES_PRI_STS, sizeof(MRASRESDEF.RES_PRI_STS), in_node, "RES_PRI_STS_VALUE");
		DBU_update_mrasresdef(2, &MRASRESDEF);
		if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "RAS-0004");
			TRS.add_fieldmsg(out_node, "MRASRESDEF SELECT", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MRASRESDEF.FACTORY), MRASRESDEF.FACTORY);
			TRS.add_fieldmsg(out_node, "RES_ID", MP_STR, sizeof(MRASRESDEF.RES_ID), MRASRESDEF.RES_ID);
			TRS.add_dberrmsg(out_node, DB_error_msg);

			gs_log_type.type = MP_LOG_ERROR;
			gs_log_type.e_type = MP_LOG_E_SYSTEM;
			gs_log_type.category = MP_LOG_CATE_TRANS;

			COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
			return MP_FALSE;
		}
	}


    return MP_TRUE;
}
