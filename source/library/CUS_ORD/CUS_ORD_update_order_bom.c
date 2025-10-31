/*******************************************************************************

System      : MESplus
Module      : CUS_ORD
File Name   : CUS_ORD_update_order_bom.c
Description : Update Order Bom function

MES Version : 5.0

Function List
- step 1: 작업지시 BOM 정보 변경


Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/07/24  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_ORD_Update_Order_Bom_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_ORD_UPDATE_ORDER_BOM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_ORD_Update_Order_Bom()
- Update Order Bom
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Update_Order_Bom(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_ORD_UPDATE_ORDER_BOM(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_ORD_Update_Order_Bom", out_node);
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
CUS_ORD_UPDATE_ORDER_BOM()
- Main sub function of "CUS_ORD_Update_Order_Bom" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_UPDATE_ORDER_BOM(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPORDSTS_TAG MWIPORDSTS;
    struct CWIPORDBOM_TAG CWIPORDBOM;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct CWIPGRTBLD_TAG CWIPGRTBLD;
    struct CWIPORDOPR_TAG CWIPORDOPR;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MWIPLOTHISX_TAG MWIPLOTHISX;
    struct CWIPINVLDM_TAG CWIPINVLDM;

    TRSNode **list_item;
    int iItemCount = 0;
    int i = 0;

    LOG_head("CUS_ORD_Update_Order_Bom");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_ORD_Update_Order_Bom_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //작업지시 BOM 정보 변경
    if (TRS.get_procstep(in_node) == '1')
    {
        DBU_init_mwipordsts(&MWIPORDSTS);
        TRS.copy(MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID), in_node, "ORDER_ID");
        DBU_select_mwipordsts(1, &MWIPORDSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //ORD-0002 : 이 ORDER는 존재하지 않습니다.
            strcpy(s_msg_code, "ORD-0002");
            TRS.add_fieldmsg(out_node, "MWIPORDSTS SELECT(1) ", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPORDSTS.FACTORY), MWIPORDSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }

		/*
        if (MWIPORDSTS.ORD_STATUS_FLAG != MP_CWIP_ORDER_WAIT)
        {
            //ORD-0027 : 대기 상태인 작업지시만 수정이 가능합니다.
            strcpy(s_msg_code, "ORD-0027");
            TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            return MP_FALSE;
        }
		*/

		if (MWIPORDSTS.ORD_STATUS_FLAG != MP_CWIP_ORDER_WAIT)
		{

			//LOT 생성아직 안되었으면 변경가능하도록 수종20211025
			DBU_init_mwiplotstsx(&MWIPLOTSTSX);
			memcpy(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
			if (DBU_select_mwiplotstsx_scalar(4, &MWIPLOTSTSX) > 0)
			{
				//WIP - 0230 : 이 제품에는 LOT이 존재 합니다.먼저 LOT을 지운 후 지우세요.
				strcpy(s_msg_code, "WIP-0230");
				TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPORDSTS.ORDER_ID), MWIPORDSTS.ORDER_ID);
				TRS.add_dberrmsg(out_node, DB_error_msg);

				return MP_FALSE;

			}

		}


        if (memcmp(MWIPORDSTS.FLOW, TRS.get_string(in_node, "FLOW"), strlen(TRS.get_string(in_node, "FLOW"))) != MP_FALSE)
        {
            TRS.copy(MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW), in_node, "FLOW");

            //그릿의 블랜딩 작업지시인 경우 블랜딩 작업지시 화면에서 lot 생성을 먼저 한다. 
            //생성된 lot의 flow를 변경해줘야 한다. 
            if (memcmp(MWIPORDSTS.ORD_CMF_1, gs_area_grt, sizeof(gs_area_grt)) == MP_FALSE)
            {
                //블랜딩 작업지시인지 여부를 확인한다.
                DBU_init_cwipgrtbld(&CWIPGRTBLD);
                TRS.copy(CWIPGRTBLD.FACTORY, sizeof(CWIPGRTBLD.FACTORY), in_node, IN_FACTORY);
                memcpy(CWIPGRTBLD.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(CWIPGRTBLD.ORDER_ID));
                if(DBU_select_cwipgrtbld_scalar(3, &CWIPGRTBLD) > 0)
                {
                    //공정별 작업지시 테이블에 이전 플로우에 대한 공정을 지운다. 
                    //다시 생성 하지 않는 이유는 start시 자동으로 생성처리 된다.
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

                    //작업지시에 만들어진 LOT을 찾아 FLOW를 업데이트 해준다.
                    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
                    memcpy(MWIPLOTSTSX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.copy(MWIPLOTSTSX.FLOW, sizeof(MWIPLOTSTSX.FLOW), in_node, "FLOW");
                    DBU_update_mwiplotstsx(3, &MWIPLOTSTSX);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTSTSX.ORDER_ID), MWIPLOTSTSX.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPLOTSTSX.FLOW), MWIPLOTSTSX.FLOW);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    DBU_init_mwiplothisx(&MWIPLOTHISX);
                    memcpy(MWIPLOTHISX.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.copy(MWIPLOTHISX.FLOW, sizeof(MWIPLOTHISX.FLOW), in_node, "FLOW");
                    DBU_update_mwiplothisx(2, &MWIPLOTHISX);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(MWIPLOTHISX.ORDER_ID), MWIPLOTHISX.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(MWIPLOTHISX.FLOW), MWIPLOTHISX.FLOW);
                        TRS.add_dberrmsg(out_node, DB_error_msg);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_VIEW;

                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }

                    DBU_init_cwipinvldm(&CWIPINVLDM);
                    memcpy(CWIPINVLDM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
                    memcpy(CWIPINVLDM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
                    TRS.copy(CWIPINVLDM.FLOW, sizeof(CWIPINVLDM.FLOW), in_node, "FLOW");
                    memcpy(CWIPINVLDM.UPDATE_TIME, gs_sys_time, sizeof(gs_sys_time));
                    TRS.copy(CWIPINVLDM.UPDATE_USER_ID, sizeof(CWIPINVLDM.UPDATE_USER_ID), in_node, IN_USERID);

                    DBU_update_cwipinvldm(2, &CWIPINVLDM);
                    if (DB_error_code != DB_SUCCESS)
                    {
                        //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                        strcpy(s_msg_code, "ADM-0004");
                        TRS.add_fieldmsg(out_node, "CWIPINVLDM UPDATE", DT_NOVALUESTRING);
                        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPINVLDM.ORDER_ID), CWIPINVLDM.ORDER_ID);
                        TRS.add_fieldmsg(out_node, "FLOW", MP_STR, sizeof(CWIPINVLDM.FLOW), CWIPINVLDM.FLOW);
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

        TRS.copy(MWIPORDSTS.ORDER_DESC, sizeof(MWIPORDSTS.ORDER_DESC), in_node, "COMMENT");

        //작업지시 설명 업데이트
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

        //BOM정보를 삭제하고 모든 리스트를 INSERT 한다.
        DBU_init_cwipordbom(&CWIPORDBOM);
        memcpy(CWIPORDBOM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
        memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
        DBU_delete_cwipordbom(2, &CWIPORDBOM);
        if (DB_error_code != DB_SUCCESS)
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPORDBOM DELETE", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
        }

        list_item = TRS.get_list(in_node, "BOM_LIST");
        iItemCount = TRS.get_item_count(in_node, "BOM_LIST");

        for (i = 0; i < iItemCount; i++)
        {
            DBU_init_cwipordbom(&CWIPORDBOM);
            memcpy(CWIPORDBOM.FACTORY, MWIPORDSTS.FACTORY, sizeof(MWIPORDSTS.FACTORY));
            memcpy(CWIPORDBOM.ORDER_ID, MWIPORDSTS.ORDER_ID, sizeof(MWIPORDSTS.ORDER_ID));
            memcpy(CWIPORDBOM.FLOW, MWIPORDSTS.FLOW, sizeof(MWIPORDSTS.FLOW));
            TRS.copy(CWIPORDBOM.OPER, sizeof(CWIPORDBOM.OPER), list_item[i], "OPER");
            TRS.copy(CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID), list_item[i], "MAT_ID");
            CWIPORDBOM.MAT_VER = 1;
            CWIPORDBOM.UNIT_QTY = TRS.get_double(list_item[i], "UNIT_QTY");
            CWIPORDBOM.QTY = TRS.get_double(list_item[i], "QTY");

            //MAT_ID 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, CWIPORDBOM.MAT_ID, sizeof(CWIPORDBOM.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0006 : 이 제품은 존재 하지 않습니다.
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT(1) ", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            memcpy(CWIPORDBOM.UNIT, MWIPMATDEF.UNIT_1, sizeof(CWIPORDBOM.UNIT));

            //OUT_OPER 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, CWIPORDBOM.FACTORY, sizeof(CWIPORDBOM.FACTORY));
            memcpy(MWIPOPRDEF.OPER_CMF_1, CWIPORDBOM.FLOW, sizeof(CWIPORDBOM.FLOW));
            DBU_select_mwipoprdef(2, &MWIPOPRDEF);
            if (DB_error_code == DB_SUCCESS)
            {
                memcpy(CWIPORDBOM.OUT_OPER, MWIPOPRDEF.OPER, sizeof(MWIPOPRDEF.OPER));
            }

            TRS.copy(CWIPORDBOM.CREATE_USER_ID,sizeof(CWIPORDBOM.CREATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPORDBOM.CREATE_TIME, gs_sys_time, sizeof(CWIPORDBOM.CREATE_TIME));

            DBU_insert_cwipordbom(&CWIPORDBOM);
            if (DB_error_code != DB_SUCCESS)
            {
                //ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "ADM-0004");
                TRS.add_fieldmsg(out_node, "CWIPORDBOM INSERT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(CWIPORDBOM.FACTORY), CWIPORDBOM.FACTORY);
                TRS.add_fieldmsg(out_node, "ORDER_ID", MP_STR, sizeof(CWIPORDBOM.ORDER_ID), CWIPORDBOM.ORDER_ID);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(CWIPORDBOM.OPER), CWIPORDBOM.OPER);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(CWIPORDBOM.MAT_ID), CWIPORDBOM.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }            
        }

    }

    return MP_TRUE;
}



/*******************************************************************************
CUS_ORD_Update_Order_Bom_Validation()
- Validation Check sub function of "CUS_ORD_UPDATE_ORDER_BOM" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_ORD_Update_Order_Bom_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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

    if (COM_isnullspace(TRS.get_string(in_node, "ORDER_ID")) == MP_TRUE)
    {
        //ORD-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.
        strcpy(s_msg_code, "ORD-0001");
        TRS.add_fieldmsg(out_node, "ORDER_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }


    return MP_TRUE;
}
