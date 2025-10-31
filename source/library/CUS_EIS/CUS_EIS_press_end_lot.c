/*******************************************************************************

    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_press_end_lot.c
    Description : Press 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.

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

int CUS_EIS_PRESS_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

/*******************************************************************************
    CUS_EIS_Press_End_Lot()
        - Press 설비에서 작업 완료 정보 받아서 End Lot을 처리한다.
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Press_End_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_EIS_PRESS_END_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_EIS_Press_End_Lot", out_node);

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
    CUS_EIS_PRESS_END_LOT()
        - Main sub function of "CUS_EIS_Press_End_Lot" function
    Return Value
        - int : 0 (IOI_SUCCESS)
    Arguments
        - char *Msg_Code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_PRESS_END_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MRASRESDEF_TAG MRASRESDEF;
    struct MWIPLOTSTSX_TAG MWIPLOTSTS;
    struct CWIPLOTPRS_TAG CWIPLOTPRS;
    struct CWIPGRPLOT_TAG CWIPGRPLOT;

    struct work_date_tag work_date;

    TRSNode *send_node;
    TRSNode *check_node;

    char s_channel[30];

    int i = 0;

    LOG_head("CUS_EIS_PRESS_END_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    if (Check_Equipment(s_msg_code, &MRASRESDEF, in_node, out_node) == MP_FALSE)
        return MP_FALSE;

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        TRS.add_fieldmsg(out_node, "Lot is empty", MP_NVST);
        TRS.add_fieldmsg(out_node, "RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));

        return MP_FALSE;
    }

    memset(&work_date, ' ', sizeof(work_date));

    Get_shift(MWIPLOTSTS.FACTORY, &work_date);

    DBU_init_cwipgrplot(&CWIPGRPLOT);
    TRS.copy(CWIPGRPLOT.FACTORY, sizeof(CWIPGRPLOT.FACTORY), in_node, IN_FACTORY);
    TRS.copy(CWIPGRPLOT.GROUP_ID, sizeof(CWIPGRPLOT.GROUP_ID), in_node, "LOT_ID");

    DBU_open_cwipgrplot(4, &CWIPGRPLOT);
    if(DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "WIP-0004");
        TRS.add_dberrmsg(out_node, DB_error_msg);

        TRS.add_fieldmsg(out_node, "CWIPGRPLOT Open 4", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
        TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);

        return MP_FALSE;
    }

    while (1)
    {
        DBU_fetch_cwipgrplot(4, &CWIPGRPLOT);
        if(DB_error_code == DB_NOT_FOUND)
        {
            DBU_close_cwipgrplot(4);
            break;
        }
        else if(DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);

            TRS.add_fieldmsg(out_node, "CWIPGRPLOT Fetch 4", DT_NOVALUESTRING);
            TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPGRPLOT.FACTORY), CWIPGRPLOT.FACTORY);
            TRS.add_fieldmsg(out_node, "GROUP_ID", DT_STRING, sizeof(CWIPGRPLOT.GROUP_ID), CWIPGRPLOT.GROUP_ID);

			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//

            return MP_FALSE;
        }

        check_node = TRS.create_node("Check_Node");
        CopyDefaultMembers(check_node, in_node);
        TRS.add_string(check_node, "LOT_ID", CWIPGRPLOT.LOT_ID, sizeof(CWIPGRPLOT.LOT_ID));

        if (Check_LotStatus(s_msg_code, &MWIPLOTSTS, check_node, out_node) == MP_FALSE)
        {
            TRS.free_node(check_node);
			// 20.12.22 minjae.go
			DBU_close_cwipgrplot(4);
			//
            return MP_FALSE;
        }

        TRS.free_node(check_node);

        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwiplotprs(&CWIPLOTPRS);
            memcpy(CWIPLOTPRS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(CWIPLOTPRS.LOT_ID));
            CWIPLOTPRS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
            TRS.copy(CWIPLOTPRS.PROFILE, sizeof(CWIPLOTPRS.PROFILE), in_node, "PROFILE");
            TRS.copy(CWIPLOTPRS.STEP, sizeof(CWIPLOTPRS.STEP), in_node->SItems[i], "STEP");
            DBU_select_cwiplotprs(1, &CWIPLOTPRS);

            CWIPLOTPRS.PERIOD_SEC = atoi(TRS.get_string(in_node->SItems[i], "UPLOAD_SEC"));
            memcpy(CWIPLOTPRS.OPER, MWIPLOTSTS.OPER, sizeof(CWIPLOTPRS.OPER));
            memcpy(CWIPLOTPRS.MAT_ID, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTPRS.MAT_ID));
            memcpy(CWIPLOTPRS.FLOW, MWIPLOTSTS.MAT_ID, sizeof(CWIPLOTPRS.FLOW));
            CWIPLOTPRS.FLOW_SEQ_NUM = MWIPLOTSTS.FLOW_SEQ_NUM;

            TRS.copy(CWIPLOTPRS.RES_ID, sizeof(CWIPLOTPRS.RES_ID), in_node, "RES_ID");
            TRS.copy(CWIPLOTPRS.FACTORY, sizeof(CWIPLOTPRS.FACTORY), in_node, IN_FACTORY);
            memcpy(CWIPLOTPRS.WORK_DATE, work_date.s_work_date, sizeof(CWIPLOTPRS.WORK_DATE));
            memcpy(CWIPLOTPRS.WORK_TIME, gs_sys_time, sizeof(CWIPLOTPRS.WORK_TIME));
            memcpy(CWIPLOTPRS.DAY_NIGHT, work_date.s_day_night, sizeof(CWIPLOTPRS.DAY_NIGHT));
            CWIPLOTPRS.PRESSURE_S = atof(TRS.get_string(in_node->SItems[i], "PRESSURE_S"));
            CWIPLOTPRS.PRESSURE_C = atof(TRS.get_string(in_node->SItems[i], "PRESSURE_C"));
            CWIPLOTPRS.POWER_S = atof(TRS.get_string(in_node->SItems[i], "POWER_S"));
            CWIPLOTPRS.POWER_C = atof(TRS.get_string(in_node->SItems[i], "POWER_C"));
            CWIPLOTPRS.CURRENT_S = atof(TRS.get_string(in_node->SItems[i], "CURRENT_S"));
            CWIPLOTPRS.CURRENT_C = atof(TRS.get_string(in_node->SItems[i], "CURRENT_C"));
            CWIPLOTPRS.VOLTAGE_C = atof(TRS.get_string(in_node->SItems[i], "VOLTAGE_C"));
            CWIPLOTPRS.RESITANCE_C = atof(TRS.get_string(in_node->SItems[i], "RESITANCE_C"));
            CWIPLOTPRS.INCH_1 = atof(TRS.get_string(in_node->SItems[i], "INCH_1"));
            CWIPLOTPRS.INCH_2 = atof(TRS.get_string(in_node->SItems[i], "INCH_2"));
            TRS.copy(CWIPLOTPRS.PROCESS_TIME, sizeof(CWIPLOTPRS.PROCESS_TIME), in_node->SItems[i], "PROCESS_TIME");

            if (DB_error_code == DB_NOT_FOUND)
            {
                TRS.copy(CWIPLOTPRS.CREATE_USER_ID, sizeof(CWIPLOTPRS.CREATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTPRS.CREATE_TIME, gs_sys_time, sizeof(CWIPLOTPRS.CREATE_TIME));

                DBU_insert_cwiplotprs(&CWIPLOTPRS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");

                    TRS.add_fieldmsg(out_node, "CWIPLOTPRS INSERT", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
                    TRS.add_fieldmsg(out_node, "PERIOD_SEC", DT_INT, CWIPLOTPRS.PERIOD_SEC);

                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPLOTPRS.OPER), CWIPLOTPRS.OPER);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CWIPLOTPRS.RES_ID), CWIPLOTPRS.RES_ID);
                    TRS.add_fieldmsg(out_node, "PROCESS_TIME", DT_STRING, sizeof(CWIPLOTPRS.PROCESS_TIME), CWIPLOTPRS.PROCESS_TIME);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

					// 20.12.22 minjae.go
					DBU_close_cwipgrplot(4);
					//

                    return MP_FALSE;
                }
            }
            else if (DB_error_code == DB_SUCCESS)
            {
                TRS.copy(CWIPLOTPRS.UPDATE_USER_ID, sizeof(CWIPLOTPRS.UPDATE_USER_ID), in_node, IN_USERID);
                memcpy(CWIPLOTPRS.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTPRS.UPDATE_TIME));

                DBU_update_cwiplotprs(1, &CWIPLOTPRS);
                if (DB_error_code != DB_SUCCESS)
                {
                    strcpy(s_msg_code, "WIP-0004");

                    TRS.add_fieldmsg(out_node, "CWIPLOTPRS UPDATE 1", DT_NOVALUESTRING);
                    TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTPRS.LOT_ID), CWIPLOTPRS.LOT_ID);
                    TRS.add_fieldmsg(out_node, "HIST_SEQ", DT_INT, CWIPLOTPRS.HIST_SEQ);
                    TRS.add_fieldmsg(out_node, "PERIOD_SEC", DT_INT, CWIPLOTPRS.PERIOD_SEC);

                    TRS.add_fieldmsg(out_node, "OPER", DT_STRING, sizeof(CWIPLOTPRS.OPER), CWIPLOTPRS.OPER);
                    TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(CWIPLOTPRS.RES_ID), CWIPLOTPRS.RES_ID);
                    TRS.add_fieldmsg(out_node, "PROCESS_TIME", DT_STRING, sizeof(CWIPLOTPRS.PROCESS_TIME), CWIPLOTPRS.PROCESS_TIME);

                    TRS.add_dberrmsg(out_node, DB_error_msg);

					// 20.12.22 minjae.go
					DBU_close_cwipgrplot(4);
					//

                    return MP_FALSE;
                }
            }
        }
    }

    // Channel 설정
    //sprintf(s_channel, "/%.*s/EAP/%.*s", COM_len_space(gs_site_id, sizeof(gs_site_id)), gs_site_id, COM_len_space(MRASRESDEF.RES_ID, sizeof(MRASRESDEF.RES_ID)), MRASRESDEF.RES_ID);
    
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

    send_node = TRS.add_node(in_node, "Start_Lot");
    TRS.add_char(send_node, IN_PROCSTEP, '1');
    CopyDefaultMembers(send_node, in_node);
    TRS.add_string(send_node, "TRAN_TIME", gs_sys_time, sizeof(gs_sys_time));
    TRS.add_nstring(send_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(send_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

    MOA.call_service("EAP", "EIS_EAP_Press_End_Lot", send_node, NULL, s_channel, 18000000, DM_UNICAST);
   
    LOG_head("Send Press End Lot");
    TRS.add_nstring(send_node, "CHANNEL", s_channel);
    TRS.log_add_all_members(send_node);    
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    return MP_TRUE;
}
