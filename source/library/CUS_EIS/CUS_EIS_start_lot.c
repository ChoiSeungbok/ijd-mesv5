/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_start_lot.c
    Description : 설비에 시작 정보를 전송한다.

    MES Version : 5.0

    Function List
        -

    Detail Description
        -

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2020/09/25  이환노        Create

    Copyright(C) 1998-2020 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_EIS_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int Validation_CUS_EIS_START_LOT(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Start_Lot()
        - 설비에 시작 정보를 전송한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Start_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_START_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Start_Lot", out_node);

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
    CUS_EIS_START_LOT()
        - Main sub function of "CUS_EIS_Send_Test" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_START_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct MGCMTBLDAT_TAG MGCMTBLDAT;
    struct MGCMTBLDAT_TAG MGCMTBLDAT_MAP;    
    struct MWIPMATDEF_TAG MWIPMATDEF;

    TRSNode *send_node;
    TRSNode *para_list;

    char s_channel[30];

    int i = 0;
    int i_para_count = 0;

    // /설비 ID/

    memset(s_channel, ' ', sizeof(s_channel));

    LOG_head("CUS_EIS_START_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if(Validation_CUS_EIS_START_LOT(s_msg_code, in_node, &MRASRESDEF, &MWIPLOTSTS, out_node) == MP_FALSE)
        return MP_FALSE;

    DBU_init_mwipmatdef(&MWIPMATDEF);
    memcpy(MWIPMATDEF.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MWIPMATDEF.FACTORY));
    memcpy(MWIPMATDEF.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(MWIPMATDEF.MAT_ID));
    MWIPMATDEF.MAT_VER = 1;
    DBU_select_mwipmatdef(1, &MWIPMATDEF);

    if(memcmp(MRASRESDEF.RES_GRP_1, MP_RESS_GRP_PRESS, strlen(MP_RESS_GRP_PRESS)) == MP_FALSE)
    {
        // Channel 설정
        if (MRASRESDEF.RES_CMF_6[0] == 'Y')
        {
            //자동으로 설비에서 end처리가 올라오지 않는 설비인 경우 PRESS1 그룹으로 eap서버로 보내준다.
            sprintf(s_channel, "/%.*s/EAP/%s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, MP_EAP_RES_GRP_PRESS1);
        }
        else
        {
            //자동으로 설비에서 end처리가 올라오는 설비인 경우 PRESS2 그룹으로 eap서버로 보내준다.
            sprintf(s_channel, "/%.*s/EAP/%s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, MP_EAP_RES_GRP_PRESS2);
        }
    }
    else
    {
        // Channel 설정
        sprintf(s_channel, "/%.*s/EAP/%.*s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, COM_len_space(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID)), MRASRESDEF.RES_ID);
    }

    //sprintf(s_channel, "/%.*s/EAP/%.*s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, COM_len_space(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID)), MRASRESDEF.RES_ID);

    send_node = TRS.add_node(in_node, "Start_Lot");
    TRS.add_char(send_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(send_node, in_node);

    TRS.set_nstring(send_node, "FACTORY", TRS.get_string(in_node, "FACTORY"));
    TRS.add_string(send_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
    TRS.add_nstring(send_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(send_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(send_node, "WORK_DATE", &gs_sys_time[2], 6);    
    TRS.add_nstring(send_node, "RECIPE_ID", TRS.get_string(in_node, "RECIPE_ID"));
    TRS.add_int(send_node, "QTY", (int)MWIPLOTSTS.QTY_1);
    TRS.add_string(send_node, "ORDER_ID", MWIPLOTSTS.ORDER_ID, sizeof(MWIPLOTSTS.ORDER_ID));
    TRS.add_string(send_node, "GRADE", MWIPMATDEF.MAT_CMF_3, sizeof(MWIPMATDEF.MAT_CMF_3));
    TRS.add_string(send_node, "MAT_ID", MWIPLOTSTS.MAT_ID, sizeof(MWIPLOTSTS.MAT_ID));
    TRS.add_string(send_node, "MAT_DESC", MWIPMATDEF.MAT_DESC, sizeof(MWIPMATDEF.MAT_DESC));
    TRS.add_nstring(send_node, "PROFILE", TRS.get_string(in_node, "PROFILE"));
    
    if(TRS.get_item_count(send_node, "PARA_LIST") > 0)
    {
        for (i = 0; i < TRS.get_item_count(send_node, "PARA_LIST"); i++)
        {
            para_list = TRS.add_node(send_node, "PARA_LIST");
            TRS.add_nstring(para_list, "STEP", TRS.get_string(in_node->SItems[i], "STEP"));  // Step
            TRS.add_nstring(para_list, "SECOND", TRS.get_string(in_node->SItems[i], "SECOND"));  // Second
        }
    }
    else
    {
        //C_PROFILE_MAP 로 조회 한 후 C_PROFILE_DATA에서 찾도록 로직 바꿀 것.
        DBU_init_mgcmtbldat(&MGCMTBLDAT_MAP);
        memcpy(MGCMTBLDAT_MAP.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MGCMTBLDAT_MAP.FACTORY));
        memcpy(MGCMTBLDAT_MAP.TABLE_NAME, MP_GCM_PRESS_PROFILE_MAP, strlen(MP_GCM_PRESS_PROFILE_MAP));
        memcpy(MGCMTBLDAT_MAP.KEY_1, MWIPMATDEF.MAT_GRP_1, sizeof(MGCMTBLDAT_MAP.KEY_1));       // 사업부
        TRS.copy(MGCMTBLDAT_MAP.KEY_2, sizeof(MGCMTBLDAT_MAP.KEY_2), in_node, "RES_ID");
        memcpy(MGCMTBLDAT_MAP.KEY_3, MWIPMATDEF.MAT_ID, sizeof(MGCMTBLDAT_MAP.KEY_3));          // mat id
        TRS.copy(MGCMTBLDAT_MAP.KEY_4, sizeof(MGCMTBLDAT_MAP.KEY_4), in_node, "PROFILE");       // Profile
        DBU_select_mgcmtbldat(1, &MGCMTBLDAT_MAP);
        if (DB_error_code == DB_SUCCESS)
        {
            DBU_init_mgcmtbldat(&MGCMTBLDAT);
            memcpy(MGCMTBLDAT.FACTORY, MWIPLOTSTS.FACTORY, sizeof(MGCMTBLDAT.FACTORY));
            memcpy(MGCMTBLDAT.TABLE_NAME, MP_GCM_PROFILE_DATA, strlen(MP_GCM_PROFILE_DATA));
            memcpy(MGCMTBLDAT.KEY_1, MGCMTBLDAT_MAP.KEY_4, sizeof(MGCMTBLDAT.KEY_1));           // Profile
            DBU_open_mgcmtbldat(2, &MGCMTBLDAT);
            if (DB_error_code != DB_SUCCESS)
            {
                // GCM-0007 : DATABASE 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                strcpy(s_msg_code, "GCM-0007");
                TRS.add_fieldmsg(out_node, "MGCMTBLDAT Open 2", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                TRS.add_fieldmsg(out_node, "KEY_1", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }

            while (1)
            {
                DBU_fetch_mgcmtbldat(2, &MGCMTBLDAT);
                if (DB_error_code == DB_NOT_FOUND)
                {
                    DBU_close_mgcmtbldat(2);
                    break;
                }
                else if (DB_error_code != DB_SUCCESS)
                {
                    // GCM-0007 : DATABASE 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
                    strcpy(s_msg_code, "GCM-0007");
                    TRS.add_fieldmsg(out_node, "MGCMTBLDAT Fetch 2", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
                    TRS.add_fieldmsg(out_node, "TABLE_NAME", DT_STRING, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
                    TRS.add_fieldmsg(out_node, "KEY_1", DT_STRING, sizeof(MGCMTBLDAT.KEY_1), MGCMTBLDAT.KEY_1);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

                    DBU_close_mgcmtbldat(2);
                    return MP_FALSE;
                }

                para_list = TRS.add_node(send_node, "PARA_LIST");
                TRS.add_string(para_list, "STEP", MGCMTBLDAT.KEY_2, sizeof(MGCMTBLDAT.KEY_2));     // Step
                TRS.add_string(para_list, "SECOND", MGCMTBLDAT.DATA_1, sizeof(MGCMTBLDAT.DATA_1)); // Second
            }
        }
    }

    // PARA_LIST가 없으면 빈 것으로 생성한다.
    // EAP에서 필요하다고 해서 생성
    i_para_count = TRS.get_item_count(send_node, "PARA_LIST");
    if(i_para_count == 0)
    {
        para_list = TRS.add_node(send_node, "PARA_LIST");  
        //TRS.add_nstring(para_list, "PARA_VALUE", NULL);  // Second
        TRS.add_nstring(para_list, "STEP", NULL);  // Step
        TRS.add_nstring(para_list, "SECOND", NULL);  // Second
    }
    
    LOG_head("Send Equipment To Start Lot");
    TRS.log_add_all_members(send_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    MOA.call_service("EAP", "EIS_EAP_Start_Lot", send_node, NULL, s_channel, 18000000, DM_UNICAST);

    return MP_TRUE;
}

/*******************************************************************************
    Validation_CUS_EIS_START_LOT()
        - Main sub function of "CUS_EIS_START_LOT" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - struct MRASRESDEF_TAG *MRASRESDEF : 설비
        - struct MWIPLOTSTSX_TAG *MWIPLOTSTS : Lot 정보
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Validation_CUS_EIS_START_LOT(char *s_msg_code, TRSNode *in_node, struct MRASRESDEF_TAG *MRASRESDEF, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *out_node)
{
    struct CWIPGRPLOT_TAG  CWIPGRPLOT;

    if (TRS.get_procstep(in_node) == '1')
    {
        if (Check_LotStatus(s_msg_code, MWIPLOTSTS, in_node, out_node) == MP_FALSE)
            return MP_FALSE;
    }
    else
    {
        DBU_init_cwipgrplot(&CWIPGRPLOT);
        TRS.copy(CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT.FACTORY), in_node, IN_FACTORY);
        TRS.copy(CWIPGRPLOT.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID), in_node, "LOT_ID");

        DBU_select_cwipgrplot(3, &CWIPGRPLOT);
        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
                strcpy(s_msg_code, "");
            else
            {
                strcpy(s_msg_code, "WIP-0004");
                TRS.add_dberrmsg(out_node, DB_error_msg);
            }

            TRS.add_fieldmsg(out_node, "CWIPGRPLOT Select 3", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
            TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);            

            return MP_FALSE;
        }

        DBU_init_mwiplotstsx(MWIPLOTSTS);
        memcpy(MWIPLOTSTS->LOT_ID, CWIPGRPLOT.LOT_ID, sizeof(MWIPLOTSTS->LOT_ID));
        DBU_select_mwiplotstsx(1, MWIPLOTSTS);
    }

    if (Check_Equipment(s_msg_code, MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if(MRASRESDEF->RES_CMF_1[0] != 'Y')
    {
        // RAS-0325 : 이 설비는 Lot 시작 정보를 전송하는 설비가 아닙니다.
        strcpy(s_msg_code, "RAS-0325");

        return MP_FALSE;
    }

    return MP_TRUE;
}

