/*******************************************************************************

System      : MESplus
Module      : CUS_WIP
File Name   : CUS_WIP_view_lot_history.c
Description : View Lot History function

MES Version : 5.0

Function List
- 

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/11/20  WG.LEE        Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_WIP_common.h"

int CUS_WIP_View_Lot_History_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_VIEW_LOT_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_WIP_View_Lot_History()
- View Lot Hisotory
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Lot_History(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_VIEW_LOT_HISTORY(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_View_Lot_History", out_node);
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
CUS_WIP_VIEW_LOT_HISTORY()
- Main sub function of "CUS_WIP_View_Lot_History" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_VIEW_LOT_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;       
    struct MWIPLOTHISX_TAG MWIPLOTHISX;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF_OLD;
    struct MWIPFLWDEF_TAG MWIPFLWDEF;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
    struct MRASRESDEF_TAG MRASRESDEF;

    TRSNode *list_item;
    int i_step;

    LOG_head("CUS_WIP_View_Lot_History");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_WIP_View_Lot_History_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == '1')
    {
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

        //if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
        //{
        //    //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
        //    strcpy(s_msg_code, "WIP-0076");
        //    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        //    TRS.add_dberrmsg(out_node, DB_error_msg);

        //    gs_log_type.type = MP_LOG_ERROR;
        //    gs_log_type.e_type = MP_LOG_E_SYSTEM;
        //    gs_log_type.category = MP_LOG_CATE_VIEW;

        //    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        //    return MP_FALSE;
        //}

        //lot이력 정보 조회
        DBU_init_mwiplothisx(&MWIPLOTHISX);
        memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));

        if (TRS.get_char(in_node, "INCLUDE_HIST_DEL") == 'Y')
        {
            i_step = 2;
        }
        else
        {
            i_step = 3;
        }

        DBU_open_mwiplothisx(i_step, &MWIPLOTHISX);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0044");
            TRS.add_fieldmsg(out_node, "MWIPLOTHISX OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

			
            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        while (1)
        {
            DBU_fetch_mwiplothisx(i_step, &MWIPLOTHISX);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mwiplothisx(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "MWIPLOTHISX FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

				// 20.12.21 minjae.go
                //DBU_close_mwiplothisx(2);
				DBU_close_mwiplothisx(i_step);
				//
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_int(out_node, "NEXT_HIST_SEQ", MWIPLOTHISX.HIST_SEQ);
                DBU_close_mwiplothisx(i_step);
                break;
            }

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTHISX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //lot 공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            //lot 공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF_OLD);
            memcpy(MWIPOPRDEF_OLD.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPOPRDEF_OLD.FACTORY));
            memcpy(MWIPOPRDEF_OLD.OPER, MWIPLOTHISX.OLD_OPER, sizeof(MWIPOPRDEF_OLD.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF_OLD);

            //lot flow 정보 조회
            DBU_init_mwipflwdef(&MWIPFLWDEF);
            memcpy(MWIPFLWDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
            memcpy(MWIPFLWDEF.FLOW, MWIPLOTHISX.FLOW, sizeof(MWIPFLWDEF.FLOW));
            DBU_select_mwipflwdef(1, &MWIPFLWDEF);

            list_item = TRS.add_node(out_node, "LOT_TBL");

            TRS.add_string(list_item, "LOT_ID", MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
            TRS.add_string(list_item, "LOT_DESC", MWIPLOTHISX.LOT_DESC, sizeof(MWIPLOTHISX.LOT_DESC));
            TRS.add_int(list_item, "HIST_SEQ", MWIPLOTHISX.HIST_SEQ);
            TRS.add_string(list_item, "TRAN_CODE", MWIPLOTHISX.TRAN_CODE, sizeof(MWIPLOTHISX.TRAN_CODE));
            TRS.add_string(list_item, "TRAN_TIME", MWIPLOTHISX.TRAN_TIME, sizeof(MWIPLOTHISX.TRAN_TIME));

            //제품정보
            TRS.add_string(list_item, "MAT_ID", MWIPLOTHISX.MAT_ID, sizeof(MWIPLOTHISX.MAT_ID));
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
            TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));           
            TRS.add_int(list_item, "MAT_VER", MWIPLOTHISX.MAT_VER);           
            TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            
            //공정 및 플로우 정보
            TRS.add_string(list_item, "OPER", MWIPLOTHISX.OPER, sizeof(MWIPLOTHISX.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_string(list_item, "OPER_TYPE", MWIPOPRDEF.OPER_CMF_12, sizeof(MWIPOPRDEF.OPER_CMF_12));
            TRS.add_string(list_item, "FLOW", MWIPLOTHISX.FLOW, sizeof(MWIPLOTHISX.FLOW));
            TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));
            TRS.add_string(list_item, "QC_TYPE", MWIPOPRDEF.OPER_GRP_2, sizeof(MWIPOPRDEF.OPER_GRP_2));
            TRS.add_string(list_item, "OLD_OPER_QC_TYPE", MWIPOPRDEF_OLD.OPER_GRP_2, sizeof(MWIPOPRDEF_OLD.OPER_GRP_2));

            //area 정보 조회        
            TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));
            
            //sub area 정보 조회
            TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

            TRS.add_double(list_item, "QTY_1", MWIPLOTHISX.QTY_1);
            TRS.add_double(list_item, "QTY_2", MWIPLOTHISX.QTY_2);
            TRS.add_double(list_item, "QTY_3", MWIPLOTHISX.QTY_3);
            TRS.add_char(list_item, "LOT_TYPE", MWIPLOTHISX.LOT_TYPE);
            TRS.add_string(list_item, "OWNER_CODE", MWIPLOTHISX.OWNER_CODE, sizeof(MWIPLOTHISX.OWNER_CODE));
            TRS.add_string(list_item, "CREATE_CODE", MWIPLOTHISX.CREATE_CODE, sizeof(MWIPLOTHISX.CREATE_CODE));
            TRS.add_char(list_item, "LOT_PRIORITY", MWIPLOTHISX.LOT_PRIORITY);
            TRS.add_string(list_item, "LOT_STATUS", MWIPLOTHISX.LOT_STATUS, sizeof(MWIPLOTHISX.LOT_STATUS));
            TRS.add_char(list_item, "HOLD_FLAG", MWIPLOTHISX.HOLD_FLAG);
            TRS.add_string(list_item, "HOLD_CODE", MWIPLOTHISX.HOLD_CODE, sizeof(MWIPLOTHISX.HOLD_CODE));
            TRS.add_double(list_item, "OPER_IN_QTY_1", MWIPLOTHISX.OPER_IN_QTY_1);
            TRS.add_double(list_item, "OPER_IN_QTY_2", MWIPLOTHISX.OPER_IN_QTY_2);
            TRS.add_double(list_item, "OPER_IN_QTY_3", MWIPLOTHISX.OPER_IN_QTY_3);
            TRS.add_double(list_item, "CREATE_QTY_1", MWIPLOTHISX.CREATE_QTY_1);
            TRS.add_double(list_item, "CREATE_QTY_2", MWIPLOTHISX.CREATE_QTY_2);
            TRS.add_double(list_item, "CREATE_QTY_3", MWIPLOTHISX.CREATE_QTY_3);
            TRS.add_double(list_item, "START_QTY_1", MWIPLOTHISX.START_QTY_1);
            TRS.add_double(list_item, "START_QTY_2", MWIPLOTHISX.START_QTY_2);
            TRS.add_double(list_item, "START_QTY_3", MWIPLOTHISX.START_QTY_3);
            TRS.add_char(list_item, "INV_FLAG", MWIPLOTHISX.INV_FLAG);
            TRS.add_char(list_item, "RWK_FLAG", MWIPLOTHISX.RWK_FLAG);
            TRS.add_string(list_item, "RWK_CODE", MWIPLOTHISX.RWK_CODE, sizeof(MWIPLOTHISX.RWK_CODE));
            TRS.add_string(list_item, "RWK_TIME", MWIPLOTHISX.RWK_TIME, sizeof(MWIPLOTHISX.RWK_TIME));
            
            //시작 시간 및 설비 정보
            TRS.add_char(list_item, "START_FLAG", MWIPLOTHISX.START_FLAG);
            TRS.add_string(list_item, "START_TIME", MWIPLOTHISX.START_TIME, sizeof(MWIPLOTHISX.START_TIME));
            TRS.add_string(list_item, "START_RES_ID", MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));            
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "START_RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            //완료 시간 및 설비 정보
            TRS.add_char(list_item, "END_FLAG", MWIPLOTHISX.END_FLAG);
            TRS.add_string(list_item, "END_TIME", MWIPLOTHISX.END_TIME, sizeof(MWIPLOTHISX.END_TIME));
            TRS.add_string(list_item, "END_RES_ID", MWIPLOTHISX.END_RES_ID, sizeof(MWIPLOTHISX.END_RES_ID));
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.END_RES_ID, sizeof(MWIPLOTHISX.END_RES_ID));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "END_RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            //중요설비 정보
            TRS.add_string(list_item, "SAVE_RES_ID_1", MWIPLOTHISX.SAVE_RES_ID_1, sizeof(MWIPLOTHISX.SAVE_RES_ID_1));
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.SAVE_RES_ID_1, sizeof(MWIPLOTHISX.SAVE_RES_ID_1));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "SAVE_RES_DESC_1", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            TRS.add_char(list_item, "FROM_TO_FLAG", MWIPLOTHISX.FROM_TO_FLAG);
            TRS.add_string(list_item, "FROM_TO_LOT_ID", MWIPLOTHISX.FROM_TO_LOT_ID, sizeof(MWIPLOTHISX.FROM_TO_LOT_ID));
            TRS.add_string(list_item, "CREATE_TIME", MWIPLOTHISX.CREATE_TIME, sizeof(MWIPLOTHISX.CREATE_TIME));
            TRS.add_string(list_item, "ORDER_ID", MWIPLOTHISX.ORDER_ID, sizeof(MWIPLOTHISX.ORDER_ID));               
            TRS.add_char(list_item, "LOT_DEL_FLAG", MWIPLOTHISX.LOT_DEL_FLAG);
            TRS.add_string(list_item, "LOT_DEL_CODE", MWIPLOTHISX.LOT_DEL_CODE, sizeof(MWIPLOTHISX.LOT_DEL_CODE));
            TRS.add_string(list_item, "LOT_DEL_TIME", MWIPLOTHISX.LOT_DEL_TIME, sizeof(MWIPLOTHISX.LOT_DEL_TIME));
            TRS.add_string(list_item, "FROM_TO_MAT_ID", MWIPLOTHISX.FROM_TO_MAT_ID, sizeof(MWIPLOTHISX.FROM_TO_MAT_ID));
            TRS.add_string(list_item, "FROM_TO_FLOW", MWIPLOTHISX.FROM_TO_FLOW, sizeof(MWIPLOTHISX.FROM_TO_FLOW));
            TRS.add_string(list_item, "FROM_TO_OPER", MWIPLOTHISX.FROM_TO_OPER, sizeof(MWIPLOTHISX.FROM_TO_OPER));
            TRS.add_double(list_item, "FROM_TO_QTY_1", MWIPLOTHISX.FROM_TO_QTY_1);
            TRS.add_double(list_item, "FROM_TO_QTY_2", MWIPLOTHISX.FROM_TO_QTY_2);
            TRS.add_double(list_item, "FROM_TO_QTY_3", MWIPLOTHISX.FROM_TO_QTY_3);
            TRS.add_string(list_item, "OLD_MAT_ID", MWIPLOTHISX.OLD_MAT_ID, sizeof(MWIPLOTHISX.OLD_MAT_ID));
            TRS.add_string(list_item, "OLD_FLOW", MWIPLOTHISX.OLD_FLOW, sizeof(MWIPLOTHISX.OLD_FLOW));
            TRS.add_string(list_item, "OLD_OPER", MWIPLOTHISX.OLD_OPER, sizeof(MWIPLOTHISX.OLD_OPER));
            TRS.add_double(list_item, "OLD_QTY_1", MWIPLOTHISX.OLD_QTY_1);
            TRS.add_double(list_item, "OLD_QTY_2", MWIPLOTHISX.OLD_QTY_2);
            TRS.add_double(list_item, "OLD_QTY_3", MWIPLOTHISX.OLD_QTY_3);

            TRS.add_string(list_item, "TRAN_USER_ID", MWIPLOTHISX.TRAN_USER_ID, sizeof(MWIPLOTHISX.TRAN_USER_ID));
            TRS.add_string(list_item, "TRAN_COMMENT", MWIPLOTHISX.TRAN_COMMENT, sizeof(MWIPLOTHISX.TRAN_COMMENT));
            TRS.add_char(list_item, "HIST_DEL_FLAG", MWIPLOTHISX.HIST_DEL_FLAG);
            TRS.add_string(list_item, "HIST_DEL_COMMENT", MWIPLOTHISX.HIST_DEL_COMMENT, sizeof(MWIPLOTHISX.HIST_DEL_COMMENT));
            TRS.add_string(list_item, "HIST_DEL_TIME", MWIPLOTHISX.HIST_DEL_TIME, sizeof(MWIPLOTHISX.HIST_DEL_TIME));
            TRS.add_string(list_item, "HIST_DEL_USER_ID", MWIPLOTHISX.HIST_DEL_USER_ID, sizeof(MWIPLOTHISX.HIST_DEL_USER_ID));

            //LOT CMF 정보
            TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTHISX.LOT_CMF_1, sizeof(MWIPLOTHISX.LOT_CMF_1));     //그룹id
            TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTHISX.LOT_CMF_2, sizeof(MWIPLOTHISX.LOT_CMF_2));     //그룹id 순번
            TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTHISX.LOT_CMF_3, sizeof(MWIPLOTHISX.LOT_CMF_3));
            TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTHISX.LOT_CMF_4, sizeof(MWIPLOTHISX.LOT_CMF_4));
            TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTHISX.LOT_CMF_5, sizeof(MWIPLOTHISX.LOT_CMF_5));
            TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTHISX.LOT_CMF_6, sizeof(MWIPLOTHISX.LOT_CMF_6));
            TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTHISX.LOT_CMF_7, sizeof(MWIPLOTHISX.LOT_CMF_7));
            TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTHISX.LOT_CMF_8, sizeof(MWIPLOTHISX.LOT_CMF_8));
            TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTHISX.LOT_CMF_9, sizeof(MWIPLOTHISX.LOT_CMF_9));
            TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTHISX.LOT_CMF_10, sizeof(MWIPLOTHISX.LOT_CMF_10));
            TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTHISX.LOT_CMF_11, sizeof(MWIPLOTHISX.LOT_CMF_11));
            TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTHISX.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_12));
            TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTHISX.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_13));
            TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTHISX.LOT_CMF_14, sizeof(MWIPLOTHISX.LOT_CMF_14));
            TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTHISX.LOT_CMF_15, sizeof(MWIPLOTHISX.LOT_CMF_15));
            TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTHISX.LOT_CMF_16, sizeof(MWIPLOTHISX.LOT_CMF_16));
            TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTHISX.LOT_CMF_17, sizeof(MWIPLOTHISX.LOT_CMF_17));
            TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTHISX.LOT_CMF_18, sizeof(MWIPLOTHISX.LOT_CMF_18));
            TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTHISX.LOT_CMF_19, sizeof(MWIPLOTHISX.LOT_CMF_19));
            TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTHISX.LOT_CMF_20, sizeof(MWIPLOTHISX.LOT_CMF_20));

            //TRAN CMF 정보
            TRS.add_string(list_item, "TRAN_CMF_1", MWIPLOTHISX.TRAN_CMF_1, sizeof(MWIPLOTHISX.TRAN_CMF_1));
            TRS.add_string(list_item, "TRAN_CMF_2", MWIPLOTHISX.TRAN_CMF_2, sizeof(MWIPLOTHISX.TRAN_CMF_2));
            TRS.add_string(list_item, "TRAN_CMF_3", MWIPLOTHISX.TRAN_CMF_3, sizeof(MWIPLOTHISX.TRAN_CMF_3));
            TRS.add_string(list_item, "TRAN_CMF_4", MWIPLOTHISX.TRAN_CMF_4, sizeof(MWIPLOTHISX.TRAN_CMF_4));
            TRS.add_string(list_item, "TRAN_CMF_5", MWIPLOTHISX.TRAN_CMF_5, sizeof(MWIPLOTHISX.TRAN_CMF_5));
            TRS.add_string(list_item, "TRAN_CMF_6", MWIPLOTHISX.TRAN_CMF_6, sizeof(MWIPLOTHISX.TRAN_CMF_6));
            TRS.add_string(list_item, "TRAN_CMF_7", MWIPLOTHISX.TRAN_CMF_7, sizeof(MWIPLOTHISX.TRAN_CMF_7));
            TRS.add_string(list_item, "TRAN_CMF_8", MWIPLOTHISX.TRAN_CMF_8, sizeof(MWIPLOTHISX.TRAN_CMF_8));
            TRS.add_string(list_item, "TRAN_CMF_9", MWIPLOTHISX.TRAN_CMF_9, sizeof(MWIPLOTHISX.TRAN_CMF_9));
            TRS.add_string(list_item, "TRAN_CMF_10", MWIPLOTHISX.TRAN_CMF_10, sizeof(MWIPLOTHISX.TRAN_CMF_10));
            TRS.add_string(list_item, "TRAN_CMF_11", MWIPLOTHISX.TRAN_CMF_11, sizeof(MWIPLOTHISX.TRAN_CMF_11));
            TRS.add_string(list_item, "TRAN_CMF_12", MWIPLOTHISX.TRAN_CMF_12, sizeof(MWIPLOTHISX.TRAN_CMF_12));
            TRS.add_string(list_item, "TRAN_CMF_13", MWIPLOTHISX.TRAN_CMF_13, sizeof(MWIPLOTHISX.TRAN_CMF_13));
            TRS.add_string(list_item, "TRAN_CMF_14", MWIPLOTHISX.TRAN_CMF_14, sizeof(MWIPLOTHISX.TRAN_CMF_14));
            TRS.add_string(list_item, "TRAN_CMF_15", MWIPLOTHISX.TRAN_CMF_15, sizeof(MWIPLOTHISX.TRAN_CMF_15));
            TRS.add_string(list_item, "TRAN_CMF_16", MWIPLOTHISX.TRAN_CMF_16, sizeof(MWIPLOTHISX.TRAN_CMF_16));
            TRS.add_string(list_item, "TRAN_CMF_17", MWIPLOTHISX.TRAN_CMF_17, sizeof(MWIPLOTHISX.TRAN_CMF_17));
            TRS.add_string(list_item, "TRAN_CMF_18", MWIPLOTHISX.TRAN_CMF_18, sizeof(MWIPLOTHISX.TRAN_CMF_18));
            TRS.add_string(list_item, "TRAN_CMF_19", MWIPLOTHISX.TRAN_CMF_19, sizeof(MWIPLOTHISX.TRAN_CMF_19));
            TRS.add_string(list_item, "TRAN_CMF_20", MWIPLOTHISX.TRAN_CMF_20, sizeof(MWIPLOTHISX.TRAN_CMF_20));

            //CTM CMF 정보
            TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTHISX.CTM_CMF_1, sizeof(MWIPLOTHISX.CTM_CMF_1));
            TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTHISX.CTM_CMF_2, sizeof(MWIPLOTHISX.CTM_CMF_2));
            TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTHISX.CTM_CMF_3, sizeof(MWIPLOTHISX.CTM_CMF_3));
            TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTHISX.CTM_CMF_4, sizeof(MWIPLOTHISX.CTM_CMF_4));
            TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTHISX.CTM_CMF_5, sizeof(MWIPLOTHISX.CTM_CMF_5));
            TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTHISX.CTM_CMF_6, sizeof(MWIPLOTHISX.CTM_CMF_6));
            TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTHISX.CTM_CMF_7, sizeof(MWIPLOTHISX.CTM_CMF_7));
            TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTHISX.CTM_CMF_8, sizeof(MWIPLOTHISX.CTM_CMF_8));
            TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTHISX.CTM_CMF_9, sizeof(MWIPLOTHISX.CTM_CMF_9));
            TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTHISX.CTM_CMF_10, sizeof(MWIPLOTHISX.CTM_CMF_10));
            TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTHISX.CTM_CMF_11, sizeof(MWIPLOTHISX.CTM_CMF_11));
            TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTHISX.CTM_CMF_12, sizeof(MWIPLOTHISX.CTM_CMF_12));
            TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTHISX.CTM_CMF_13, sizeof(MWIPLOTHISX.CTM_CMF_13));
            TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTHISX.CTM_CMF_14, sizeof(MWIPLOTHISX.CTM_CMF_14));
            TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTHISX.CTM_CMF_15, sizeof(MWIPLOTHISX.CTM_CMF_15));
            TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTHISX.CTM_CMF_16, sizeof(MWIPLOTHISX.CTM_CMF_16));
            TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTHISX.CTM_CMF_17, sizeof(MWIPLOTHISX.CTM_CMF_17));
            TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTHISX.CTM_CMF_18, sizeof(MWIPLOTHISX.CTM_CMF_18));
            TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTHISX.CTM_CMF_19, sizeof(MWIPLOTHISX.CTM_CMF_19));
            TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTHISX.CTM_CMF_20, sizeof(MWIPLOTHISX.CTM_CMF_20));

            //PDC CMF 정보
            TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTHISX.PDC_CMF_1, sizeof(MWIPLOTHISX.PDC_CMF_1));
            TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTHISX.PDC_CMF_2, sizeof(MWIPLOTHISX.PDC_CMF_2));
            TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTHISX.PDC_CMF_3, sizeof(MWIPLOTHISX.PDC_CMF_3));
            TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTHISX.PDC_CMF_4, sizeof(MWIPLOTHISX.PDC_CMF_4));
            TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTHISX.PDC_CMF_5, sizeof(MWIPLOTHISX.PDC_CMF_5));
            TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTHISX.PDC_CMF_6, sizeof(MWIPLOTHISX.PDC_CMF_6));
            TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTHISX.PDC_CMF_7, sizeof(MWIPLOTHISX.PDC_CMF_7));
            TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTHISX.PDC_CMF_8, sizeof(MWIPLOTHISX.PDC_CMF_8));
            TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTHISX.PDC_CMF_9, sizeof(MWIPLOTHISX.PDC_CMF_9));
            TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTHISX.PDC_CMF_10, sizeof(MWIPLOTHISX.PDC_CMF_10));
            TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTHISX.PDC_CMF_11, sizeof(MWIPLOTHISX.PDC_CMF_11));
            TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTHISX.PDC_CMF_12, sizeof(MWIPLOTHISX.PDC_CMF_12));
            TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTHISX.PDC_CMF_13, sizeof(MWIPLOTHISX.PDC_CMF_13));
            TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTHISX.PDC_CMF_14, sizeof(MWIPLOTHISX.PDC_CMF_14));
            TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTHISX.PDC_CMF_15, sizeof(MWIPLOTHISX.PDC_CMF_15));
            TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTHISX.PDC_CMF_16, sizeof(MWIPLOTHISX.PDC_CMF_16));
            TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTHISX.PDC_CMF_17, sizeof(MWIPLOTHISX.PDC_CMF_17));
            TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTHISX.PDC_CMF_18, sizeof(MWIPLOTHISX.PDC_CMF_18));
            TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTHISX.PDC_CMF_19, sizeof(MWIPLOTHISX.PDC_CMF_19));
            TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTHISX.PDC_CMF_20, sizeof(MWIPLOTHISX.PDC_CMF_20));

            //HM CMF 정보
            TRS.add_string(list_item, "HM_CMF_1", MWIPLOTHISX.HM_CMF_1, sizeof(MWIPLOTHISX.HM_CMF_1));
            TRS.add_string(list_item, "HM_CMF_2", MWIPLOTHISX.HM_CMF_2, sizeof(MWIPLOTHISX.HM_CMF_2));
            TRS.add_string(list_item, "HM_CMF_3", MWIPLOTHISX.HM_CMF_3, sizeof(MWIPLOTHISX.HM_CMF_3));
            TRS.add_string(list_item, "HM_CMF_4", MWIPLOTHISX.HM_CMF_4, sizeof(MWIPLOTHISX.HM_CMF_4));
            TRS.add_string(list_item, "HM_CMF_5", MWIPLOTHISX.HM_CMF_5, sizeof(MWIPLOTHISX.HM_CMF_5));
            TRS.add_string(list_item, "HM_CMF_6", MWIPLOTHISX.HM_CMF_6, sizeof(MWIPLOTHISX.HM_CMF_6));
            TRS.add_string(list_item, "HM_CMF_7", MWIPLOTHISX.HM_CMF_7, sizeof(MWIPLOTHISX.HM_CMF_7));
            TRS.add_string(list_item, "HM_CMF_8", MWIPLOTHISX.HM_CMF_8, sizeof(MWIPLOTHISX.HM_CMF_8));
            TRS.add_string(list_item, "HM_CMF_9", MWIPLOTHISX.HM_CMF_9, sizeof(MWIPLOTHISX.HM_CMF_9));
            TRS.add_string(list_item, "HM_CMF_10", MWIPLOTHISX.HM_CMF_10, sizeof(MWIPLOTHISX.HM_CMF_10));
            TRS.add_string(list_item, "HM_CMF_11", MWIPLOTHISX.HM_CMF_11, sizeof(MWIPLOTHISX.HM_CMF_11));
            TRS.add_string(list_item, "HM_CMF_12", MWIPLOTHISX.HM_CMF_12, sizeof(MWIPLOTHISX.HM_CMF_12));
            TRS.add_string(list_item, "HM_CMF_13", MWIPLOTHISX.HM_CMF_13, sizeof(MWIPLOTHISX.HM_CMF_13));
            TRS.add_string(list_item, "HM_CMF_14", MWIPLOTHISX.HM_CMF_14, sizeof(MWIPLOTHISX.HM_CMF_14));
            TRS.add_string(list_item, "HM_CMF_15", MWIPLOTHISX.HM_CMF_15, sizeof(MWIPLOTHISX.HM_CMF_15));
            TRS.add_string(list_item, "HM_CMF_16", MWIPLOTHISX.HM_CMF_16, sizeof(MWIPLOTHISX.HM_CMF_16));
            TRS.add_string(list_item, "HM_CMF_17", MWIPLOTHISX.HM_CMF_17, sizeof(MWIPLOTHISX.HM_CMF_17));
            TRS.add_string(list_item, "HM_CMF_18", MWIPLOTHISX.HM_CMF_18, sizeof(MWIPLOTHISX.HM_CMF_18));
            TRS.add_string(list_item, "HM_CMF_19", MWIPLOTHISX.HM_CMF_19, sizeof(MWIPLOTHISX.HM_CMF_19));
            TRS.add_string(list_item, "HM_CMF_20", MWIPLOTHISX.HM_CMF_20, sizeof(MWIPLOTHISX.HM_CMF_20));

            //GRIT _string(list_item, "GRT_CMF_1", MWIPLOTHISX.GRT_CMF_1, sizeof(MWIPLOTHISX.GRT_CMF_1));
            TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTHISX.GRT_CMF_2, sizeof(MWIPLOTHISX.GRT_CMF_2));
            TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTHISX.GRT_CMF_3, sizeof(MWIPLOTHISX.GRT_CMF_3));
            TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTHISX.GRT_CMF_4, sizeof(MWIPLOTHISX.GRT_CMF_4));
            TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTHISX.GRT_CMF_5, sizeof(MWIPLOTHISX.GRT_CMF_5));
            TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTHISX.GRT_CMF_6, sizeof(MWIPLOTHISX.GRT_CMF_6));
            TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTHISX.GRT_CMF_7, sizeof(MWIPLOTHISX.GRT_CMF_7));
            TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTHISX.GRT_CMF_8, sizeof(MWIPLOTHISX.GRT_CMF_8));
            TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTHISX.GRT_CMF_9, sizeof(MWIPLOTHISX.GRT_CMF_9));
            TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTHISX.GRT_CMF_10, sizeof(MWIPLOTHISX.GRT_CMF_10));
            TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTHISX.GRT_CMF_11, sizeof(MWIPLOTHISX.GRT_CMF_11));
            TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTHISX.GRT_CMF_12, sizeof(MWIPLOTHISX.GRT_CMF_12));
            TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTHISX.GRT_CMF_13, sizeof(MWIPLOTHISX.GRT_CMF_13));
            TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTHISX.GRT_CMF_14, sizeof(MWIPLOTHISX.GRT_CMF_14));
            TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTHISX.GRT_CMF_15, sizeof(MWIPLOTHISX.GRT_CMF_15));
            TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTHISX.GRT_CMF_16, sizeof(MWIPLOTHISX.GRT_CMF_16));
            TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTHISX.GRT_CMF_17, sizeof(MWIPLOTHISX.GRT_CMF_17));
            TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTHISX.GRT_CMF_18, sizeof(MWIPLOTHISX.GRT_CMF_18));
            TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTHISX.GRT_CMF_19, sizeof(MWIPLOTHISX.GRT_CMF_19));
            TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTHISX.GRT_CMF_20, sizeof(MWIPLOTHISX.GRT_CMF_20));
        }         
    }
    else if (TRS.get_procstep(in_node) == '2')
    {
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

        //if (MWIPLOTSTSX.LOT_DEL_FLAG == 'Y')
        //{
        //    //WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
        //    strcpy(s_msg_code, "WIP-0076");
        //    TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);
        //    TRS.add_dberrmsg(out_node, DB_error_msg);

        //    gs_log_type.type = MP_LOG_ERROR;
        //    gs_log_type.e_type = MP_LOG_E_SYSTEM;
        //    gs_log_type.category = MP_LOG_CATE_VIEW;

        //    COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        //    return MP_FALSE;
        //}

        //lot이력 정보 조회
        DBU_init_mwiplothisx(&MWIPLOTHISX);
        memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTSTSX.LOT_ID));


        i_step = 4;


        DBU_open_mwiplothisx(i_step, &MWIPLOTHISX);
        if (DB_error_code != DB_SUCCESS)
        {
            //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
            strcpy(s_msg_code, "WIP-0044");
            TRS.add_fieldmsg(out_node, "MWIPLOTHISX OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }
        while (1)
        {
            DBU_fetch_mwiplothisx(i_step, &MWIPLOTHISX);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_mwiplothisx(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                strcpy(s_msg_code, "WIP-0044");
                TRS.add_fieldmsg(out_node, "MWIPLOTHISX FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPLOTHISX.FACTORY), MWIPLOTHISX.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                // 20.12.21 minjae.go
                //DBU_close_mwiplothisx(2);
                DBU_close_mwiplothisx(i_step);
                //
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                return MP_FALSE;
            }

            if (COM_check_node_length(out_node) == MP_FALSE)
            {
                TRS.add_int(out_node, "NEXT_HIST_SEQ", MWIPLOTHISX.HIST_SEQ);
                DBU_close_mwiplothisx(i_step);
                break;
            }

            //자재 정보 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPMATDEF.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MWIPLOTHISX.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
            MWIPMATDEF.MAT_VER = 1;
            DBU_select_mwipmatdef(1, &MWIPMATDEF);

            //lot 공정 정보 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MWIPLOTHISX.OPER, sizeof(MWIPOPRDEF.OPER));
            DBU_select_mwipoprdef(1, &MWIPOPRDEF);

            //lot flow 정보 조회
            DBU_init_mwipflwdef(&MWIPFLWDEF);
            memcpy(MWIPFLWDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPFLWDEF.FACTORY));
            memcpy(MWIPFLWDEF.FLOW, MWIPLOTHISX.FLOW, sizeof(MWIPFLWDEF.FLOW));
            DBU_select_mwipflwdef(1, &MWIPFLWDEF);

            list_item = TRS.add_node(out_node, "LOT_TBL");

            TRS.add_string(list_item, "LOT_ID", MWIPLOTHISX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
            TRS.add_string(list_item, "LOT_DESC", MWIPLOTHISX.LOT_DESC, sizeof(MWIPLOTHISX.LOT_DESC));
            TRS.add_int(list_item, "HIST_SEQ", MWIPLOTHISX.HIST_SEQ);
            TRS.add_string(list_item, "TRAN_CODE", MWIPLOTHISX.TRAN_CODE, sizeof(MWIPLOTHISX.TRAN_CODE));
            TRS.add_string(list_item, "TRAN_TIME", MWIPLOTHISX.TRAN_TIME, sizeof(MWIPLOTHISX.TRAN_TIME));

            //제품정보
            TRS.add_string(list_item, "MAT_ID", MWIPLOTHISX.MAT_ID, sizeof(MWIPLOTHISX.MAT_ID));
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "MAT_GRP_1", MWIPMATDEF.MAT_GRP_1, sizeof(MWIPMATDEF.MAT_GRP_1));
            TRS.add_string(list_item, "MAT_GRP_2", MWIPMATDEF.MAT_GRP_2, sizeof(MWIPMATDEF.MAT_GRP_2));
            TRS.add_int(list_item, "MAT_VER", MWIPLOTHISX.MAT_VER);
            TRS.add_string(list_item, "UNIT_1", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));

            //공정 및 플로우 정보
            TRS.add_string(list_item, "OPER", MWIPLOTHISX.OPER, sizeof(MWIPLOTHISX.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_string(list_item, "OPER_TYPE", MWIPOPRDEF.OPER_CMF_12, sizeof(MWIPOPRDEF.OPER_CMF_12));
            TRS.add_string(list_item, "FLOW", MWIPLOTHISX.FLOW, sizeof(MWIPLOTHISX.FLOW));
            TRS.add_string(list_item, "FLOW_DESC", MWIPFLWDEF.FLOW_DESC, sizeof(MWIPFLWDEF.FLOW_DESC));

            //area 정보 조회        
            TRS.add_string(list_item, "AREA_ID", MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_AREA_CODE, strlen(MP_RAS_AREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.AREA_ID, sizeof(MWIPOPRDEF.AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            TRS.add_string(list_item, "AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

            //sub area 정보 조회
            TRS.add_string(list_item, "SUB_AREA_ID", MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_RAS_SUBAREA_CODE, strlen(MP_RAS_SUBAREA_CODE));
            memcpy(MGCMTBLDAT.KEY_1, MWIPOPRDEF.SUB_AREA_ID, sizeof(MWIPOPRDEF.SUB_AREA_ID));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT);
            TRS.add_string(list_item, "SUB_AREA_DESC", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1));

            TRS.add_double(list_item, "QTY_1", MWIPLOTHISX.QTY_1);
            TRS.add_double(list_item, "QTY_2", MWIPLOTHISX.QTY_2);
            TRS.add_double(list_item, "QTY_3", MWIPLOTHISX.QTY_3);
            TRS.add_char(list_item, "LOT_TYPE", MWIPLOTHISX.LOT_TYPE);
            TRS.add_string(list_item, "OWNER_CODE", MWIPLOTHISX.OWNER_CODE, sizeof(MWIPLOTHISX.OWNER_CODE));
            TRS.add_string(list_item, "CREATE_CODE", MWIPLOTHISX.CREATE_CODE, sizeof(MWIPLOTHISX.CREATE_CODE));
            TRS.add_char(list_item, "LOT_PRIORITY", MWIPLOTHISX.LOT_PRIORITY);
            TRS.add_string(list_item, "LOT_STATUS", MWIPLOTHISX.LOT_STATUS, sizeof(MWIPLOTHISX.LOT_STATUS));
            TRS.add_char(list_item, "HOLD_FLAG", MWIPLOTHISX.HOLD_FLAG);
            TRS.add_string(list_item, "HOLD_CODE", MWIPLOTHISX.HOLD_CODE, sizeof(MWIPLOTHISX.HOLD_CODE));
            TRS.add_double(list_item, "OPER_IN_QTY_1", MWIPLOTHISX.OPER_IN_QTY_1);
            TRS.add_double(list_item, "OPER_IN_QTY_2", MWIPLOTHISX.OPER_IN_QTY_2);
            TRS.add_double(list_item, "OPER_IN_QTY_3", MWIPLOTHISX.OPER_IN_QTY_3);
            TRS.add_double(list_item, "CREATE_QTY_1", MWIPLOTHISX.CREATE_QTY_1);
            TRS.add_double(list_item, "CREATE_QTY_2", MWIPLOTHISX.CREATE_QTY_2);
            TRS.add_double(list_item, "CREATE_QTY_3", MWIPLOTHISX.CREATE_QTY_3);
            TRS.add_double(list_item, "START_QTY_1", MWIPLOTHISX.START_QTY_1);
            TRS.add_double(list_item, "START_QTY_2", MWIPLOTHISX.START_QTY_2);
            TRS.add_double(list_item, "START_QTY_3", MWIPLOTHISX.START_QTY_3);
            TRS.add_char(list_item, "INV_FLAG", MWIPLOTHISX.INV_FLAG);
            TRS.add_char(list_item, "RWK_FLAG", MWIPLOTHISX.RWK_FLAG);
            TRS.add_string(list_item, "RWK_CODE", MWIPLOTHISX.RWK_CODE, sizeof(MWIPLOTHISX.RWK_CODE));
            TRS.add_string(list_item, "RWK_TIME", MWIPLOTHISX.RWK_TIME, sizeof(MWIPLOTHISX.RWK_TIME));

            //시작 시간 및 설비 정보
            TRS.add_char(list_item, "START_FLAG", MWIPLOTHISX.START_FLAG);
            TRS.add_string(list_item, "START_TIME", MWIPLOTHISX.START_TIME, sizeof(MWIPLOTHISX.START_TIME));
            TRS.add_string(list_item, "START_RES_ID", MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.START_RES_ID, sizeof(MWIPLOTHISX.START_RES_ID));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "START_RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            //완료 시간 및 설비 정보
            TRS.add_char(list_item, "END_FLAG", MWIPLOTHISX.END_FLAG);
            TRS.add_string(list_item, "END_TIME", MWIPLOTHISX.END_TIME, sizeof(MWIPLOTHISX.END_TIME));
            TRS.add_string(list_item, "END_RES_ID", MWIPLOTHISX.END_RES_ID, sizeof(MWIPLOTHISX.END_RES_ID));
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.END_RES_ID, sizeof(MWIPLOTHISX.END_RES_ID));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "END_RES_DESC", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            //중요설비 정보
            TRS.add_string(list_item, "SAVE_RES_ID_1", MWIPLOTHISX.SAVE_RES_ID_1, sizeof(MWIPLOTHISX.SAVE_RES_ID_1));
            DBU_init_mrasresdef(&MRASRESDEF);
            memcpy(MRASRESDEF.FACTORY, MWIPLOTHISX.FACTORY, sizeof(MWIPLOTHISX.FACTORY));
            memcpy(MRASRESDEF.RES_ID, MWIPLOTHISX.SAVE_RES_ID_1, sizeof(MWIPLOTHISX.SAVE_RES_ID_1));
            DBU_select_mrasresdef(1, &MRASRESDEF);
            TRS.add_string(list_item, "SAVE_RES_DESC_1", MRASRESDEF.RES_DESC, sizeof(MRASRESDEF.RES_DESC));

            TRS.add_char(list_item, "FROM_TO_FLAG", MWIPLOTHISX.FROM_TO_FLAG);
            TRS.add_string(list_item, "FROM_TO_LOT_ID", MWIPLOTHISX.FROM_TO_LOT_ID, sizeof(MWIPLOTHISX.FROM_TO_LOT_ID));
            TRS.add_string(list_item, "CREATE_TIME", MWIPLOTHISX.CREATE_TIME, sizeof(MWIPLOTHISX.CREATE_TIME));
            TRS.add_string(list_item, "ORDER_ID", MWIPLOTHISX.ORDER_ID, sizeof(MWIPLOTHISX.ORDER_ID));
            TRS.add_char(list_item, "LOT_DEL_FLAG", MWIPLOTHISX.LOT_DEL_FLAG);
            TRS.add_string(list_item, "LOT_DEL_CODE", MWIPLOTHISX.LOT_DEL_CODE, sizeof(MWIPLOTHISX.LOT_DEL_CODE));
            TRS.add_string(list_item, "LOT_DEL_TIME", MWIPLOTHISX.LOT_DEL_TIME, sizeof(MWIPLOTHISX.LOT_DEL_TIME));
            TRS.add_string(list_item, "FROM_TO_MAT_ID", MWIPLOTHISX.FROM_TO_MAT_ID, sizeof(MWIPLOTHISX.FROM_TO_MAT_ID));
            TRS.add_string(list_item, "FROM_TO_FLOW", MWIPLOTHISX.FROM_TO_FLOW, sizeof(MWIPLOTHISX.FROM_TO_FLOW));
            TRS.add_string(list_item, "FROM_TO_OPER", MWIPLOTHISX.FROM_TO_OPER, sizeof(MWIPLOTHISX.FROM_TO_OPER));
            TRS.add_double(list_item, "FROM_TO_QTY_1", MWIPLOTHISX.FROM_TO_QTY_1);
            TRS.add_double(list_item, "FROM_TO_QTY_2", MWIPLOTHISX.FROM_TO_QTY_2);
            TRS.add_double(list_item, "FROM_TO_QTY_3", MWIPLOTHISX.FROM_TO_QTY_3);
            TRS.add_string(list_item, "OLD_MAT_ID", MWIPLOTHISX.OLD_MAT_ID, sizeof(MWIPLOTHISX.OLD_MAT_ID));
            TRS.add_string(list_item, "OLD_FLOW", MWIPLOTHISX.OLD_FLOW, sizeof(MWIPLOTHISX.OLD_FLOW));
            TRS.add_string(list_item, "OLD_OPER", MWIPLOTHISX.OLD_OPER, sizeof(MWIPLOTHISX.OLD_OPER));
            TRS.add_double(list_item, "OLD_QTY_1", MWIPLOTHISX.OLD_QTY_1);
            TRS.add_double(list_item, "OLD_QTY_2", MWIPLOTHISX.OLD_QTY_2);
            TRS.add_double(list_item, "OLD_QTY_3", MWIPLOTHISX.OLD_QTY_3);

            TRS.add_string(list_item, "TRAN_USER_ID", MWIPLOTHISX.TRAN_USER_ID, sizeof(MWIPLOTHISX.TRAN_USER_ID));
            TRS.add_string(list_item, "TRAN_COMMENT", MWIPLOTHISX.TRAN_COMMENT, sizeof(MWIPLOTHISX.TRAN_COMMENT));
            TRS.add_char(list_item, "HIST_DEL_FLAG", MWIPLOTHISX.HIST_DEL_FLAG);
            TRS.add_string(list_item, "HIST_DEL_COMMENT", MWIPLOTHISX.HIST_DEL_COMMENT, sizeof(MWIPLOTHISX.HIST_DEL_COMMENT));
            TRS.add_string(list_item, "HIST_DEL_TIME", MWIPLOTHISX.HIST_DEL_TIME, sizeof(MWIPLOTHISX.HIST_DEL_TIME));
            TRS.add_string(list_item, "HIST_DEL_USER_ID", MWIPLOTHISX.HIST_DEL_USER_ID, sizeof(MWIPLOTHISX.HIST_DEL_USER_ID));

            //LOT CMF 정보
            TRS.add_string(list_item, "LOT_CMF_1", MWIPLOTHISX.LOT_CMF_1, sizeof(MWIPLOTHISX.LOT_CMF_1));     //그룹id
            TRS.add_string(list_item, "LOT_CMF_2", MWIPLOTHISX.LOT_CMF_2, sizeof(MWIPLOTHISX.LOT_CMF_2));     //그룹id 순번
            TRS.add_string(list_item, "LOT_CMF_3", MWIPLOTHISX.LOT_CMF_3, sizeof(MWIPLOTHISX.LOT_CMF_3));
            TRS.add_string(list_item, "LOT_CMF_4", MWIPLOTHISX.LOT_CMF_4, sizeof(MWIPLOTHISX.LOT_CMF_4));
            TRS.add_string(list_item, "LOT_CMF_5", MWIPLOTHISX.LOT_CMF_5, sizeof(MWIPLOTHISX.LOT_CMF_5));
            TRS.add_string(list_item, "LOT_CMF_6", MWIPLOTHISX.LOT_CMF_6, sizeof(MWIPLOTHISX.LOT_CMF_6));
            TRS.add_string(list_item, "LOT_CMF_7", MWIPLOTHISX.LOT_CMF_7, sizeof(MWIPLOTHISX.LOT_CMF_7));
            TRS.add_string(list_item, "LOT_CMF_8", MWIPLOTHISX.LOT_CMF_8, sizeof(MWIPLOTHISX.LOT_CMF_8));
            TRS.add_string(list_item, "LOT_CMF_9", MWIPLOTHISX.LOT_CMF_9, sizeof(MWIPLOTHISX.LOT_CMF_9));
            TRS.add_string(list_item, "LOT_CMF_10", MWIPLOTHISX.LOT_CMF_10, sizeof(MWIPLOTHISX.LOT_CMF_10));
            TRS.add_string(list_item, "LOT_CMF_11", MWIPLOTHISX.LOT_CMF_11, sizeof(MWIPLOTHISX.LOT_CMF_11));
            TRS.add_string(list_item, "LOT_CMF_12", MWIPLOTHISX.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_12));
            TRS.add_string(list_item, "LOT_CMF_13", MWIPLOTHISX.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_13));
            TRS.add_string(list_item, "LOT_CMF_14", MWIPLOTHISX.LOT_CMF_14, sizeof(MWIPLOTHISX.LOT_CMF_14));
            TRS.add_string(list_item, "LOT_CMF_15", MWIPLOTHISX.LOT_CMF_15, sizeof(MWIPLOTHISX.LOT_CMF_15));
            TRS.add_string(list_item, "LOT_CMF_16", MWIPLOTHISX.LOT_CMF_16, sizeof(MWIPLOTHISX.LOT_CMF_16));
            TRS.add_string(list_item, "LOT_CMF_17", MWIPLOTHISX.LOT_CMF_17, sizeof(MWIPLOTHISX.LOT_CMF_17));
            TRS.add_string(list_item, "LOT_CMF_18", MWIPLOTHISX.LOT_CMF_18, sizeof(MWIPLOTHISX.LOT_CMF_18));
            TRS.add_string(list_item, "LOT_CMF_19", MWIPLOTHISX.LOT_CMF_19, sizeof(MWIPLOTHISX.LOT_CMF_19));
            TRS.add_string(list_item, "LOT_CMF_20", MWIPLOTHISX.LOT_CMF_20, sizeof(MWIPLOTHISX.LOT_CMF_20));

            //TRAN CMF 정보
            TRS.add_string(list_item, "TRAN_CMF_1", MWIPLOTHISX.TRAN_CMF_1, sizeof(MWIPLOTHISX.TRAN_CMF_1));
            TRS.add_string(list_item, "TRAN_CMF_2", MWIPLOTHISX.TRAN_CMF_2, sizeof(MWIPLOTHISX.TRAN_CMF_2));
            TRS.add_string(list_item, "TRAN_CMF_3", MWIPLOTHISX.TRAN_CMF_3, sizeof(MWIPLOTHISX.TRAN_CMF_3));
            TRS.add_string(list_item, "TRAN_CMF_4", MWIPLOTHISX.TRAN_CMF_4, sizeof(MWIPLOTHISX.TRAN_CMF_4));
            TRS.add_string(list_item, "TRAN_CMF_5", MWIPLOTHISX.TRAN_CMF_5, sizeof(MWIPLOTHISX.TRAN_CMF_5));
            TRS.add_string(list_item, "TRAN_CMF_6", MWIPLOTHISX.TRAN_CMF_6, sizeof(MWIPLOTHISX.TRAN_CMF_6));
            TRS.add_string(list_item, "TRAN_CMF_7", MWIPLOTHISX.TRAN_CMF_7, sizeof(MWIPLOTHISX.TRAN_CMF_7));
            TRS.add_string(list_item, "TRAN_CMF_8", MWIPLOTHISX.TRAN_CMF_8, sizeof(MWIPLOTHISX.TRAN_CMF_8));
            TRS.add_string(list_item, "TRAN_CMF_9", MWIPLOTHISX.TRAN_CMF_9, sizeof(MWIPLOTHISX.TRAN_CMF_9));
            TRS.add_string(list_item, "TRAN_CMF_10", MWIPLOTHISX.TRAN_CMF_10, sizeof(MWIPLOTHISX.TRAN_CMF_10));
            TRS.add_string(list_item, "TRAN_CMF_11", MWIPLOTHISX.TRAN_CMF_11, sizeof(MWIPLOTHISX.TRAN_CMF_11));
            TRS.add_string(list_item, "TRAN_CMF_12", MWIPLOTHISX.TRAN_CMF_12, sizeof(MWIPLOTHISX.TRAN_CMF_12));
            TRS.add_string(list_item, "TRAN_CMF_13", MWIPLOTHISX.TRAN_CMF_13, sizeof(MWIPLOTHISX.TRAN_CMF_13));
            TRS.add_string(list_item, "TRAN_CMF_14", MWIPLOTHISX.TRAN_CMF_14, sizeof(MWIPLOTHISX.TRAN_CMF_14));
            TRS.add_string(list_item, "TRAN_CMF_15", MWIPLOTHISX.TRAN_CMF_15, sizeof(MWIPLOTHISX.TRAN_CMF_15));
            TRS.add_string(list_item, "TRAN_CMF_16", MWIPLOTHISX.TRAN_CMF_16, sizeof(MWIPLOTHISX.TRAN_CMF_16));
            TRS.add_string(list_item, "TRAN_CMF_17", MWIPLOTHISX.TRAN_CMF_17, sizeof(MWIPLOTHISX.TRAN_CMF_17));
            TRS.add_string(list_item, "TRAN_CMF_18", MWIPLOTHISX.TRAN_CMF_18, sizeof(MWIPLOTHISX.TRAN_CMF_18));
            TRS.add_string(list_item, "TRAN_CMF_19", MWIPLOTHISX.TRAN_CMF_19, sizeof(MWIPLOTHISX.TRAN_CMF_19));
            TRS.add_string(list_item, "TRAN_CMF_20", MWIPLOTHISX.TRAN_CMF_20, sizeof(MWIPLOTHISX.TRAN_CMF_20));

            //CTM CMF 정보
            TRS.add_string(list_item, "CTM_CMF_1", MWIPLOTHISX.CTM_CMF_1, sizeof(MWIPLOTHISX.CTM_CMF_1));
            TRS.add_string(list_item, "CTM_CMF_2", MWIPLOTHISX.CTM_CMF_2, sizeof(MWIPLOTHISX.CTM_CMF_2));
            TRS.add_string(list_item, "CTM_CMF_3", MWIPLOTHISX.CTM_CMF_3, sizeof(MWIPLOTHISX.CTM_CMF_3));
            TRS.add_string(list_item, "CTM_CMF_4", MWIPLOTHISX.CTM_CMF_4, sizeof(MWIPLOTHISX.CTM_CMF_4));
            TRS.add_string(list_item, "CTM_CMF_5", MWIPLOTHISX.CTM_CMF_5, sizeof(MWIPLOTHISX.CTM_CMF_5));
            TRS.add_string(list_item, "CTM_CMF_6", MWIPLOTHISX.CTM_CMF_6, sizeof(MWIPLOTHISX.CTM_CMF_6));
            TRS.add_string(list_item, "CTM_CMF_7", MWIPLOTHISX.CTM_CMF_7, sizeof(MWIPLOTHISX.CTM_CMF_7));
            TRS.add_string(list_item, "CTM_CMF_8", MWIPLOTHISX.CTM_CMF_8, sizeof(MWIPLOTHISX.CTM_CMF_8));
            TRS.add_string(list_item, "CTM_CMF_9", MWIPLOTHISX.CTM_CMF_9, sizeof(MWIPLOTHISX.CTM_CMF_9));
            TRS.add_string(list_item, "CTM_CMF_10", MWIPLOTHISX.CTM_CMF_10, sizeof(MWIPLOTHISX.CTM_CMF_10));
            TRS.add_string(list_item, "CTM_CMF_11", MWIPLOTHISX.CTM_CMF_11, sizeof(MWIPLOTHISX.CTM_CMF_11));
            TRS.add_string(list_item, "CTM_CMF_12", MWIPLOTHISX.CTM_CMF_12, sizeof(MWIPLOTHISX.CTM_CMF_12));
            TRS.add_string(list_item, "CTM_CMF_13", MWIPLOTHISX.CTM_CMF_13, sizeof(MWIPLOTHISX.CTM_CMF_13));
            TRS.add_string(list_item, "CTM_CMF_14", MWIPLOTHISX.CTM_CMF_14, sizeof(MWIPLOTHISX.CTM_CMF_14));
            TRS.add_string(list_item, "CTM_CMF_15", MWIPLOTHISX.CTM_CMF_15, sizeof(MWIPLOTHISX.CTM_CMF_15));
            TRS.add_string(list_item, "CTM_CMF_16", MWIPLOTHISX.CTM_CMF_16, sizeof(MWIPLOTHISX.CTM_CMF_16));
            TRS.add_string(list_item, "CTM_CMF_17", MWIPLOTHISX.CTM_CMF_17, sizeof(MWIPLOTHISX.CTM_CMF_17));
            TRS.add_string(list_item, "CTM_CMF_18", MWIPLOTHISX.CTM_CMF_18, sizeof(MWIPLOTHISX.CTM_CMF_18));
            TRS.add_string(list_item, "CTM_CMF_19", MWIPLOTHISX.CTM_CMF_19, sizeof(MWIPLOTHISX.CTM_CMF_19));
            TRS.add_string(list_item, "CTM_CMF_20", MWIPLOTHISX.CTM_CMF_20, sizeof(MWIPLOTHISX.CTM_CMF_20));

            //PDC CMF 정보
            TRS.add_string(list_item, "PDC_CMF_1", MWIPLOTHISX.PDC_CMF_1, sizeof(MWIPLOTHISX.PDC_CMF_1));
            TRS.add_string(list_item, "PDC_CMF_2", MWIPLOTHISX.PDC_CMF_2, sizeof(MWIPLOTHISX.PDC_CMF_2));
            TRS.add_string(list_item, "PDC_CMF_3", MWIPLOTHISX.PDC_CMF_3, sizeof(MWIPLOTHISX.PDC_CMF_3));
            TRS.add_string(list_item, "PDC_CMF_4", MWIPLOTHISX.PDC_CMF_4, sizeof(MWIPLOTHISX.PDC_CMF_4));
            TRS.add_string(list_item, "PDC_CMF_5", MWIPLOTHISX.PDC_CMF_5, sizeof(MWIPLOTHISX.PDC_CMF_5));
            TRS.add_string(list_item, "PDC_CMF_6", MWIPLOTHISX.PDC_CMF_6, sizeof(MWIPLOTHISX.PDC_CMF_6));
            TRS.add_string(list_item, "PDC_CMF_7", MWIPLOTHISX.PDC_CMF_7, sizeof(MWIPLOTHISX.PDC_CMF_7));
            TRS.add_string(list_item, "PDC_CMF_8", MWIPLOTHISX.PDC_CMF_8, sizeof(MWIPLOTHISX.PDC_CMF_8));
            TRS.add_string(list_item, "PDC_CMF_9", MWIPLOTHISX.PDC_CMF_9, sizeof(MWIPLOTHISX.PDC_CMF_9));
            TRS.add_string(list_item, "PDC_CMF_10", MWIPLOTHISX.PDC_CMF_10, sizeof(MWIPLOTHISX.PDC_CMF_10));
            TRS.add_string(list_item, "PDC_CMF_11", MWIPLOTHISX.PDC_CMF_11, sizeof(MWIPLOTHISX.PDC_CMF_11));
            TRS.add_string(list_item, "PDC_CMF_12", MWIPLOTHISX.PDC_CMF_12, sizeof(MWIPLOTHISX.PDC_CMF_12));
            TRS.add_string(list_item, "PDC_CMF_13", MWIPLOTHISX.PDC_CMF_13, sizeof(MWIPLOTHISX.PDC_CMF_13));
            TRS.add_string(list_item, "PDC_CMF_14", MWIPLOTHISX.PDC_CMF_14, sizeof(MWIPLOTHISX.PDC_CMF_14));
            TRS.add_string(list_item, "PDC_CMF_15", MWIPLOTHISX.PDC_CMF_15, sizeof(MWIPLOTHISX.PDC_CMF_15));
            TRS.add_string(list_item, "PDC_CMF_16", MWIPLOTHISX.PDC_CMF_16, sizeof(MWIPLOTHISX.PDC_CMF_16));
            TRS.add_string(list_item, "PDC_CMF_17", MWIPLOTHISX.PDC_CMF_17, sizeof(MWIPLOTHISX.PDC_CMF_17));
            TRS.add_string(list_item, "PDC_CMF_18", MWIPLOTHISX.PDC_CMF_18, sizeof(MWIPLOTHISX.PDC_CMF_18));
            TRS.add_string(list_item, "PDC_CMF_19", MWIPLOTHISX.PDC_CMF_19, sizeof(MWIPLOTHISX.PDC_CMF_19));
            TRS.add_string(list_item, "PDC_CMF_20", MWIPLOTHISX.PDC_CMF_20, sizeof(MWIPLOTHISX.PDC_CMF_20));

            //HM CMF 정보
            TRS.add_string(list_item, "HM_CMF_1", MWIPLOTHISX.HM_CMF_1, sizeof(MWIPLOTHISX.HM_CMF_1));
            TRS.add_string(list_item, "HM_CMF_2", MWIPLOTHISX.HM_CMF_2, sizeof(MWIPLOTHISX.HM_CMF_2));
            TRS.add_string(list_item, "HM_CMF_3", MWIPLOTHISX.HM_CMF_3, sizeof(MWIPLOTHISX.HM_CMF_3));
            TRS.add_string(list_item, "HM_CMF_4", MWIPLOTHISX.HM_CMF_4, sizeof(MWIPLOTHISX.HM_CMF_4));
            TRS.add_string(list_item, "HM_CMF_5", MWIPLOTHISX.HM_CMF_5, sizeof(MWIPLOTHISX.HM_CMF_5));
            TRS.add_string(list_item, "HM_CMF_6", MWIPLOTHISX.HM_CMF_6, sizeof(MWIPLOTHISX.HM_CMF_6));
            TRS.add_string(list_item, "HM_CMF_7", MWIPLOTHISX.HM_CMF_7, sizeof(MWIPLOTHISX.HM_CMF_7));
            TRS.add_string(list_item, "HM_CMF_8", MWIPLOTHISX.HM_CMF_8, sizeof(MWIPLOTHISX.HM_CMF_8));
            TRS.add_string(list_item, "HM_CMF_9", MWIPLOTHISX.HM_CMF_9, sizeof(MWIPLOTHISX.HM_CMF_9));
            TRS.add_string(list_item, "HM_CMF_10", MWIPLOTHISX.HM_CMF_10, sizeof(MWIPLOTHISX.HM_CMF_10));
            TRS.add_string(list_item, "HM_CMF_11", MWIPLOTHISX.HM_CMF_11, sizeof(MWIPLOTHISX.HM_CMF_11));
            TRS.add_string(list_item, "HM_CMF_12", MWIPLOTHISX.HM_CMF_12, sizeof(MWIPLOTHISX.HM_CMF_12));
            TRS.add_string(list_item, "HM_CMF_13", MWIPLOTHISX.HM_CMF_13, sizeof(MWIPLOTHISX.HM_CMF_13));
            TRS.add_string(list_item, "HM_CMF_14", MWIPLOTHISX.HM_CMF_14, sizeof(MWIPLOTHISX.HM_CMF_14));
            TRS.add_string(list_item, "HM_CMF_15", MWIPLOTHISX.HM_CMF_15, sizeof(MWIPLOTHISX.HM_CMF_15));
            TRS.add_string(list_item, "HM_CMF_16", MWIPLOTHISX.HM_CMF_16, sizeof(MWIPLOTHISX.HM_CMF_16));
            TRS.add_string(list_item, "HM_CMF_17", MWIPLOTHISX.HM_CMF_17, sizeof(MWIPLOTHISX.HM_CMF_17));
            TRS.add_string(list_item, "HM_CMF_18", MWIPLOTHISX.HM_CMF_18, sizeof(MWIPLOTHISX.HM_CMF_18));
            TRS.add_string(list_item, "HM_CMF_19", MWIPLOTHISX.HM_CMF_19, sizeof(MWIPLOTHISX.HM_CMF_19));
            TRS.add_string(list_item, "HM_CMF_20", MWIPLOTHISX.HM_CMF_20, sizeof(MWIPLOTHISX.HM_CMF_20));

            //GRIT _string(list_item, "GRT_CMF_1", MWIPLOTHISX.GRT_CMF_1, sizeof(MWIPLOTHISX.GRT_CMF_1));
            TRS.add_string(list_item, "GRT_CMF_2", MWIPLOTHISX.GRT_CMF_2, sizeof(MWIPLOTHISX.GRT_CMF_2));
            TRS.add_string(list_item, "GRT_CMF_3", MWIPLOTHISX.GRT_CMF_3, sizeof(MWIPLOTHISX.GRT_CMF_3));
            TRS.add_string(list_item, "GRT_CMF_4", MWIPLOTHISX.GRT_CMF_4, sizeof(MWIPLOTHISX.GRT_CMF_4));
            TRS.add_string(list_item, "GRT_CMF_5", MWIPLOTHISX.GRT_CMF_5, sizeof(MWIPLOTHISX.GRT_CMF_5));
            TRS.add_string(list_item, "GRT_CMF_6", MWIPLOTHISX.GRT_CMF_6, sizeof(MWIPLOTHISX.GRT_CMF_6));
            TRS.add_string(list_item, "GRT_CMF_7", MWIPLOTHISX.GRT_CMF_7, sizeof(MWIPLOTHISX.GRT_CMF_7));
            TRS.add_string(list_item, "GRT_CMF_8", MWIPLOTHISX.GRT_CMF_8, sizeof(MWIPLOTHISX.GRT_CMF_8));
            TRS.add_string(list_item, "GRT_CMF_9", MWIPLOTHISX.GRT_CMF_9, sizeof(MWIPLOTHISX.GRT_CMF_9));
            TRS.add_string(list_item, "GRT_CMF_10", MWIPLOTHISX.GRT_CMF_10, sizeof(MWIPLOTHISX.GRT_CMF_10));
            TRS.add_string(list_item, "GRT_CMF_11", MWIPLOTHISX.GRT_CMF_11, sizeof(MWIPLOTHISX.GRT_CMF_11));
            TRS.add_string(list_item, "GRT_CMF_12", MWIPLOTHISX.GRT_CMF_12, sizeof(MWIPLOTHISX.GRT_CMF_12));
            TRS.add_string(list_item, "GRT_CMF_13", MWIPLOTHISX.GRT_CMF_13, sizeof(MWIPLOTHISX.GRT_CMF_13));
            TRS.add_string(list_item, "GRT_CMF_14", MWIPLOTHISX.GRT_CMF_14, sizeof(MWIPLOTHISX.GRT_CMF_14));
            TRS.add_string(list_item, "GRT_CMF_15", MWIPLOTHISX.GRT_CMF_15, sizeof(MWIPLOTHISX.GRT_CMF_15));
            TRS.add_string(list_item, "GRT_CMF_16", MWIPLOTHISX.GRT_CMF_16, sizeof(MWIPLOTHISX.GRT_CMF_16));
            TRS.add_string(list_item, "GRT_CMF_17", MWIPLOTHISX.GRT_CMF_17, sizeof(MWIPLOTHISX.GRT_CMF_17));
            TRS.add_string(list_item, "GRT_CMF_18", MWIPLOTHISX.GRT_CMF_18, sizeof(MWIPLOTHISX.GRT_CMF_18));
            TRS.add_string(list_item, "GRT_CMF_19", MWIPLOTHISX.GRT_CMF_19, sizeof(MWIPLOTHISX.GRT_CMF_19));
            TRS.add_string(list_item, "GRT_CMF_20", MWIPLOTHISX.GRT_CMF_20, sizeof(MWIPLOTHISX.GRT_CMF_20));
        }
    }
    return MP_TRUE;
}



/*******************************************************************************
CUS_WIP_View_Lot_History_Validation()
- Validation Check sub function of "CUS_WIP_VIEW_LOT_HISTORY" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_View_Lot_History_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
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
