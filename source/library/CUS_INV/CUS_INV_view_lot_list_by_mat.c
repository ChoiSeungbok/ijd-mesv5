/*******************************************************************************

System      : MESplus
Module      : CUS_INV
File Name   : CUS_INV_view_lot_list_by_mat.c
Description : View Inv Lot List By Material

MES Version : 4.0.0

Function List
- 

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/28  Miracom       Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_INV_common.h"
#include "CUS_common.h"

int CUS_INV_View_Lot_List_By_Mat_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_INV_VIEW_LOT_LIST_BY_MAT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
CUS_INV_View_Lot_List_By_Mat()
- View Inv Lot List By Material
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_List_By_Mat(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_INV_VIEW_LOT_LIST_BY_MAT(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code, "CUS_INV_VIEW_LOT_LIST_BY_OPER", out_node);

    if (i_ret == MP_TRUE)
    {
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
        DB_commit();
    }
    else
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        DB_rollback();
    }

    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_VIEW_LOT_LIST_BY_MAT()
- Main sub function of "CUS_INV_View_Lot_List_By_Mat" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_VIEW_LOT_LIST_BY_MAT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{  
    struct MINVLOTSTS_TAG MINVLOTSTS;
    struct MWIPMATDEF_TAG MWIPMATDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF;
    struct MWIPOPRDEF_TAG MWIPOPRDEF_LOAD;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_WORKPLACE;
	struct MGCMLAGDAT_TAG MGCMLAGDAT;

    TRSNode *list_item;
    char s_vendor_site_id[50];
    int i_step = 0;
    
    LOG_head("CUS_INV_View_Lot_List_By_Mat");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    /* Validation Check */
    if (CUS_INV_View_Lot_List_By_Mat_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_minvlotsts(&MINVLOTSTS);
    
    //품목별 자재 현황
    if (TRS.get_procstep(in_node) == '1')
    {
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID), in_node, "MAT_ID");
        TRS.copy(MINVLOTSTS.INV_LOT_TYPE, sizeof(MINVLOTSTS.INV_LOT_TYPE), in_node, "MAT_TYPE");

        i_step = 6;
        DBU_open_minvlotsts(i_step, &MINVLOTSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "MINVLOTSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVLOTSTS.AREA_ID), MINVLOTSTS.AREA_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
            TRS.add_fieldmsg(out_node, "MAT_TYPE", MP_STR, sizeof(MINVLOTSTS.INV_LOT_TYPE), MINVLOTSTS.INV_LOT_TYPE);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_minvlotsts(i_step, &MINVLOTSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_minvlotsts(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //INV-0043 : 검색하신 정보는 존재하지 않습니다.
                strcpy(s_msg_code, "INV-0043");
                TRS.add_fieldmsg(out_node, "MINVLOTSTS FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVLOTSTS.AREA_ID), MINVLOTSTS.AREA_ID);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
                TRS.add_fieldmsg(out_node, "MAT_TYPE", MP_STR, sizeof(MINVLOTSTS.INV_LOT_TYPE), MINVLOTSTS.INV_LOT_TYPE);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvlotsts(i_step);
				//

                return MP_FALSE;
            }

            //제품 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
            MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvlotsts(i_step);
				//

                return MP_FALSE;
            }

            list_item = TRS.add_node(out_node, "MAT_LIST");

            TRS.add_string(list_item, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
            TRS.add_int(list_item, "MAT_VER", MINVLOTSTS.MAT_VER);
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_string(list_item, "MAT_TYPE", MWIPMATDEF.MAT_TYPE, sizeof(MWIPMATDEF.MAT_TYPE));
            TRS.add_double(list_item, "QTY", MINVLOTSTS.QTY);
            TRS.add_string(list_item, "UNIT", MINVLOTSTS.UNIT, sizeof(MINVLOTSTS.UNIT));
            TRS.add_string(list_item, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
        }

    }
    //자재 LOT 상세 현황
    else if (TRS.get_procstep(in_node) == '2')
    {
        TRS.copy(MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY), in_node, IN_FACTORY);
        TRS.copy(MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID), in_node, "AREA_ID");
        TRS.copy(MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID), in_node, "MAT_ID");
        MINVLOTSTS.MAT_VER = TRS.get_int(in_node, "MAT_VER");

        i_step = 7;
        DBU_open_minvlotsts(i_step, &MINVLOTSTS);
        if (DB_error_code != DB_SUCCESS)
        {
            //INV-0043 : 검색하신 정보는 존재하지 않습니다.
            strcpy(s_msg_code, "INV-0043");
            TRS.add_fieldmsg(out_node, "MINVLOTSTS OPEN", MP_NVST);
            TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
            TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
            TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVLOTSTS.AREA_ID), MINVLOTSTS.AREA_ID);
            TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_VIEW;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
            return MP_FALSE;
        }

        while (1)
        {
            DBU_fetch_minvlotsts(i_step, &MINVLOTSTS);
            if (DB_error_code == DB_NOT_FOUND)
            {
                DBU_close_minvlotsts(i_step);
                break;
            }
            else if (DB_error_code != DB_SUCCESS)
            {
                //INV-0043 : 검색하신 정보는 존재하지 않습니다.
                strcpy(s_msg_code, "INV-0043");
                TRS.add_fieldmsg(out_node, "MINVLOTSTS FETCH", MP_NVST);
                TRS.add_fieldmsg(out_node, "step", MP_INT, i_step);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MINVLOTSTS.FACTORY), MINVLOTSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "AREA_ID", MP_STR, sizeof(MINVLOTSTS.AREA_ID), MINVLOTSTS.AREA_ID);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MINVLOTSTS.MAT_ID), MINVLOTSTS.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_VIEW;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvlotsts(i_step);
				//

                return MP_FALSE;
            }

            //제품 조회
            DBU_init_mwipmatdef(&MWIPMATDEF);
            memcpy(MWIPMATDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MINVLOTSTS.FACTORY));
            memcpy(MWIPMATDEF.MAT_ID, MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
            MWIPMATDEF.MAT_VER = MINVLOTSTS.MAT_VER;

            DBU_select_mwipmatdef(1, &MWIPMATDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0006");
                TRS.add_fieldmsg(out_node, "MWIPMATDEF SELECT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPMATDEF.FACTORY), MWIPMATDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "MAT_ID", MP_STR, sizeof(MWIPMATDEF.MAT_ID), MWIPMATDEF.MAT_ID);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvlotsts(i_step);
				//

                return MP_FALSE;
            }

            //공정 조회
            DBU_init_mwipoprdef(&MWIPOPRDEF);
            memcpy(MWIPOPRDEF.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPOPRDEF.FACTORY));
            memcpy(MWIPOPRDEF.OPER, MINVLOTSTS.OPER, sizeof(MWIPOPRDEF.OPER));
            
            DBU_select_mwipoprdef(1,&MWIPOPRDEF);
            if (DB_error_code != DB_SUCCESS)
            {
                strcpy(s_msg_code, "WIP-0010");
                TRS.add_fieldmsg(out_node, "MWIPOPRDEF SELECT", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MWIPOPRDEF.FACTORY), MWIPOPRDEF.FACTORY);
                TRS.add_fieldmsg(out_node, "OPER", MP_STR, sizeof(MWIPOPRDEF.OPER), MWIPOPRDEF.OPER);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_TRANS;
                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

				// 20.12.21 minjae.go
				DBU_close_minvlotsts(i_step);
				//

                return MP_FALSE;
            }

            //협력사 조회
			DBU_init_mgcmlagdat(&MGCMLAGDAT);
			TRS.copy(MGCMLAGDAT.FACTORY, sizeof(MGCMLAGDAT.FACTORY), in_node, IN_FACTORY);
			memcpy(MGCMLAGDAT.TABLE_NAME, MP_GCM_VENDOR, strlen(MP_GCM_VENDOR));
			memcpy(MGCMLAGDAT.KEY_1, MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
			COM_itoa_left(s_vendor_site_id, MINVLOTSTS.VENDOR_SITE_ID, sizeof(s_vendor_site_id));
			memcpy(MGCMLAGDAT.KEY_2, s_vendor_site_id, sizeof(s_vendor_site_id));
			DBU_select_mgcmlagdat(1, &MGCMLAGDAT);

            //Load Workplace 조회
            DBU_init_mgcmtbldat(&MGCMTBLDAT_WORKPLACE);
            memcpy(MGCMTBLDAT_WORKPLACE.FACTORY, MGCMTBLDAT_WORKPLACE.FACTORY, sizeof(MGCMTBLDAT_WORKPLACE.FACTORY));
            memcpy(MGCMTBLDAT_WORKPLACE.TABLE_NAME, MP_GCM_SUB_AREA, strlen(MP_GCM_SUB_AREA));
            memcpy(MGCMTBLDAT_WORKPLACE.KEY_1, MINVLOTSTS.INV_CMF_8, sizeof(MGCMTBLDAT_WORKPLACE.KEY_1));
            DBU_select_mgcmtbldat(1, &MGCMTBLDAT_WORKPLACE);

            //Load Oper조회
            DBU_init_mwipoprdef(&MWIPOPRDEF_LOAD);
            memcpy(MWIPOPRDEF_LOAD.FACTORY, MINVLOTSTS.FACTORY, sizeof(MWIPOPRDEF_LOAD.FACTORY));
            memcpy(MWIPOPRDEF_LOAD.OPER, MINVLOTSTS.INV_CMF_9, sizeof(MWIPOPRDEF_LOAD.OPER));

            DBU_select_mwipoprdef(1, &MWIPOPRDEF_LOAD);
            
            list_item = TRS.add_node(out_node, "INV_LOT_LIST");

            TRS.add_string(list_item, "INV_LOT_ID", MINVLOTSTS.INV_LOT_ID, sizeof(MINVLOTSTS.INV_LOT_ID));
            TRS.add_string(list_item, "INV_LOT_TYPE", MINVLOTSTS.INV_LOT_TYPE, sizeof(MINVLOTSTS.INV_LOT_TYPE));
            TRS.add_string(list_item, "MAT_ID", MINVLOTSTS.MAT_ID, sizeof(MINVLOTSTS.MAT_ID));
            TRS.add_int(list_item, "MAT_VER", MINVLOTSTS.MAT_VER);
            TRS.add_string(list_item, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
            TRS.add_double(list_item, "QTY", MINVLOTSTS.QTY);
            TRS.add_string(list_item, "UNIT", MWIPMATDEF.UNIT_1, sizeof(MWIPMATDEF.UNIT_1));
            TRS.add_string(list_item, "RECV_DATE", MINVLOTSTS.RECV_DATE, sizeof(MINVLOTSTS.RECV_DATE));
            TRS.add_double(list_item, "RECV_DATE", MINVLOTSTS.RECV_QTY);
            TRS.add_string(list_item, "VENDOR_ID", MINVLOTSTS.VENDOR_ID, sizeof(MINVLOTSTS.VENDOR_ID));
            TRS.add_int(list_item, "VENDOR_SITE_ID", MINVLOTSTS.VENDOR_SITE_ID);
            TRS.add_string(list_item, "VENDOR_DESC", MGCMLAGDAT.DATA_1, sizeof(MGCMLAGDAT.DATA_1));
            TRS.add_string(list_item, "VENDOR_LOT_ID", MINVLOTSTS.VENDOR_LOT_ID, sizeof(MINVLOTSTS.VENDOR_LOT_ID));
            TRS.add_string(list_item, "AREA_ID", MINVLOTSTS.AREA_ID, sizeof(MINVLOTSTS.AREA_ID));
            TRS.add_string(list_item, "SUB_AREA_ID", MINVLOTSTS.SUB_AREA_ID, sizeof(MINVLOTSTS.SUB_AREA_ID));
            TRS.add_string(list_item, "OPER", MINVLOTSTS.OPER, sizeof(MINVLOTSTS.OPER));
            TRS.add_string(list_item, "OPER_DESC", MWIPOPRDEF.OPER_DESC, sizeof(MWIPOPRDEF.OPER_DESC));
            TRS.add_char(list_item, "LOAD_FLAG", MINVLOTSTS.LOAD_FLAG);
			TRS.add_string(list_item, "LOT_ID", MINVLOTSTS.LOT_ID, sizeof(MINVLOTSTS.LOT_ID));
			TRS.add_string(list_item, "RES_ID", MINVLOTSTS.RES_ID, sizeof(MINVLOTSTS.RES_ID));
			TRS.add_string(list_item, "ORDER_ID", MINVLOTSTS.ORDER_ID, sizeof(MINVLOTSTS.ORDER_ID));
            TRS.add_string(list_item, "LOAD_WORKPLACE", MINVLOTSTS.INV_CMF_8, sizeof(MINVLOTSTS.INV_CMF_8));
            TRS.add_string(list_item, "LOAD_WORKPLACE_DESC", MGCMTBLDAT_WORKPLACE.DATA_1, sizeof(MGCMTBLDAT_WORKPLACE.DATA_1));
            TRS.add_string(list_item, "LOAD_OPER", MINVLOTSTS.INV_CMF_9, sizeof(MINVLOTSTS.INV_CMF_9));
            TRS.add_string(list_item, "LOAD_OPER_DESC", MWIPOPRDEF_LOAD.OPER_DESC, sizeof(MWIPOPRDEF_LOAD.OPER_DESC));
            TRS.add_char(list_item, "HOLD_FLAG", MINVLOTSTS.HOLD_FLAG);
            TRS.add_string(list_item, "INV_CMF_1", MINVLOTSTS.INV_CMF_1, sizeof(MINVLOTSTS.INV_CMF_1));
            TRS.add_string(list_item, "INV_CMF_2", MINVLOTSTS.INV_CMF_2, sizeof(MINVLOTSTS.INV_CMF_2));
            TRS.add_string(list_item, "INV_CMF_4", MINVLOTSTS.INV_CMF_4, sizeof(MINVLOTSTS.INV_CMF_4));
            TRS.add_string(list_item, "INV_CMF_7", MINVLOTSTS.INV_CMF_7, sizeof(MINVLOTSTS.INV_CMF_7));
        }
    }
   
    return MP_TRUE;
}

/*******************************************************************************
CUS_INV_View_Lot_List_By_Mat_Validation()
- Validation Check sub function of "CUS_INV_VIEW_LOT_LIST_BY_MAT" function
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_INV_View_Lot_List_By_Mat_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
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

    if (COM_isnullspace(TRS.get_string(in_node, "AREA_ID")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "AREA_ID", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        return MP_FALSE;
    }
    return MP_TRUE;
}
