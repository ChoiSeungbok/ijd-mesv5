/******************************************************************************'
    System      : MESplus
    Module      : CUS_EIS
    File Name   : CUS_EIS_common.c
    Description : Customer Common Function 

    MES Version : 5.3.4 ~

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2019/06/19             Create by Generator

    Copyright(C) 1998-2019 Miracom,Inc.
    All rights reserved.
******************************************************************************/
#include "CUS_EIS_common.h"
/*******************************************************************************
    CUS_EIS_Get_Collect_Char()
    - Collection Set의 Character 조회
    Return Value
    - int : 0 (IOI_SUCCESS)
    Arguments
    - TRSNode *in_node : Input Message structure
    - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_EIS_Get_Collect_Char(char *s_msg_code, int i_seq, struct MEDCCOLCHR_TAG *MEDCCOLCHR, struct MEDCCOLVER_TAG *MEDCCOLVER, TRSNode *out_node)
{
    DBC_init_medccolchr(MEDCCOLCHR);
    memcpy(MEDCCOLCHR->FACTORY, MEDCCOLVER->FACTORY, sizeof(MEDCCOLVER->FACTORY));
    memcpy(MEDCCOLCHR->COL_SET_ID, MEDCCOLVER->COL_SET_ID, sizeof(MEDCCOLCHR->COL_SET_ID));
    MEDCCOLCHR->COL_SET_VERSION = MEDCCOLVER->COL_SET_VERSION;
    MEDCCOLCHR->SEQ_NUM = i_seq;
    DBC_select_medccolchr(3, MEDCCOLCHR);
    if (DB_error_code != DB_SUCCESS)
    {
        strcpy(s_msg_code, "EDC-0004");

        TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select 3", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLCHR->FACTORY), MEDCCOLVER->FACTORY);
        TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLCHR->COL_SET_ID), MEDCCOLVER->COL_SET_ID);
        TRS.add_fieldmsg(out_node, "COL_SET_VERSION", DT_INT, MEDCCOLCHR->COL_SET_VERSION);
        TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, MEDCCOLCHR->SEQ_NUM);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }
    else if (DB_error_code == DB_NOT_FOUND)
    {
        // EDC-0016 : CHARACTER SET에 이 CHARACTER가 존재하지 않습니다.
        strcpy(s_msg_code, "EDC-0016");
        TRS.add_fieldmsg(out_node, "MEDCCOLCHR Select 3", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MEDCCOLCHR->FACTORY), MEDCCOLVER->FACTORY);
        TRS.add_fieldmsg(out_node, "COL_SET_ID", DT_STRING, sizeof(MEDCCOLCHR->COL_SET_ID), MEDCCOLVER->COL_SET_ID);
        TRS.add_fieldmsg(out_node, "COL_SET_VERSION", DT_INT, MEDCCOLCHR->COL_SET_VERSION);
        TRS.add_fieldmsg(out_node, "SEQ_NUM", DT_INT, MEDCCOLCHR->SEQ_NUM);

        TRS.add_dberrmsg(out_node, DB_error_msg);

        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
    Check_Equipment()
        - 설비 정보 확인
    Return Value
        - int : MP_TRUE(1) or MP_FALSE(0)
    Arguments
        - char *s_msg_code : Error Message Code
        - struct MRASRESDEF_TAG *MRASRESDEF
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Check_Equipment(char *s_msg_code, struct MRASRESDEF_TAG *MRASRESDEF, TRSNode *in_node, TRSNode *out_node)
{
    if (COM_isnullspace(TRS.get_string(in_node, "RES_ID")) == MP_TRUE)
    {
        TRS.add_fieldmsg(out_node, "RES ID is empty", MP_NVST);
        TRS.add_fieldmsg(out_node, "RES_ID", MP_NSTR, TRS.get_string(in_node, "RES_ID"));

        return MP_FALSE;
    }

    DBU_init_mrasresdef(MRASRESDEF);
    TRS.copy(MRASRESDEF->FACTORY, sizeof(MRASRESDEF->FACTORY), in_node, IN_FACTORY);
    TRS.copy(MRASRESDEF->RES_ID, sizeof(MRASRESDEF->RES_ID), in_node, "RES_ID");
    DBU_select_mrasresdef(1, MRASRESDEF);
    if (DB_error_code != DB_error_code)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            // RAS-0003 : 존재하지 않는 장비입니다.
            strcpy(s_msg_code, "RAS-0003");
        }
        else
        {
            strcpy(s_msg_code, "RAS-0004");
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MRASRESDEF Select 1", DT_NOVALUESTRING);
        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF->FACTORY), MRASRESDEF->FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF->RES_ID), MRASRESDEF->RES_ID);
        return MP_FALSE;
    }

    if (MRASRESDEF->DELETE_FLAG == 'Y')
    {
        //RAS-0119 : 이 장비는 삭제되었습니다.
        strcpy(s_msg_code, "RAS-0119");

        TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(MRASRESDEF->FACTORY), MRASRESDEF->FACTORY);
        TRS.add_fieldmsg(out_node, "RES_ID", DT_STRING, sizeof(MRASRESDEF->RES_ID), MRASRESDEF->RES_ID);
        TRS.add_fieldmsg(out_node, "DELETE_FLAG", DT_CHAR, MRASRESDEF->DELETE_FLAG);
        TRS.add_fieldmsg(out_node, "DELETE_USER_ID", DT_STRING, sizeof(MRASRESDEF->DELETE_USER_ID), MRASRESDEF->DELETE_USER_ID);
        TRS.add_fieldmsg(out_node, "DELETE_TIME", DT_STRING, sizeof(MRASRESDEF->DELETE_TIME), MRASRESDEF->DELETE_TIME);

        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
    Check_LotStatus()
        - Lot 정보 확인
    Return Value
        - int : MP_TRUE(1) or MP_FALSE(0)
    Arguments
        - char *s_msg_code : Error Message Code
        - struct MWIPLOTSTS_TAG *MWIPLOTSTS
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Check_LotStatus(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *in_node, TRSNode *out_node)
{
    struct MGCMTBLDAT_TAG MGCMTBLDAT;

    if (COM_isnullspace(TRS.get_string(in_node, "LOT_ID")) == MP_TRUE)
    {
        TRS.add_fieldmsg(out_node, "Lot is empty", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_NSTR, TRS.get_string(in_node, "LOT_ID"));

        return MP_FALSE;
    }

    DBU_init_mwiplotstsx(MWIPLOTSTS);
    TRS.copy(MWIPLOTSTS->LOT_ID, sizeof(MWIPLOTSTS->LOT_ID), in_node, "LOT_ID");
    DBU_select_mwiplotstsx(1, MWIPLOTSTS);
    if (DB_error_code != DB_SUCCESS)
    {
        if (DB_error_code == DB_NOT_FOUND)
        {
            strcpy(s_msg_code, "WIP-0044");		// WIP-0044 : 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
        }
        else if (DB_error_code != DB_SUCCESS)
        {
            strcpy(s_msg_code, "WIP-0004");		// WIP-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPLOTSTS Select (1)", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTS->LOT_ID), MWIPLOTSTS->LOT_ID);

        return MP_FALSE;
    }

    if (MWIPLOTSTS->HOLD_FLAG == 'Y')
    {
        // WIP-0059 : 이 LOT은 HOLD 중입니다. RELEASE 후 사용 하세요.
        strcpy(s_msg_code, "WIP-0059");
        TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS->LOT_ID), MWIPLOTSTS->LOT_ID);
        TRS.add_fieldmsg(out_node, "HOLD_CODE", DT_STRING, sizeof(MWIPLOTSTS->HOLD_CODE), MWIPLOTSTS->HOLD_CODE);

        DBC_init_mgcmtbldat(&MGCMTBLDAT);
        TRS.copy(MGCMTBLDAT.FACTORY, sizeof(MGCMTBLDAT.FACTORY), in_node, IN_FACTORY);
        memcpy(MGCMTBLDAT.TABLE_NAME, MP_WIP_HOLD_CODE, strlen(MP_WIP_HOLD_CODE));
        memcpy(MGCMTBLDAT.KEY_1, MWIPLOTSTS->HOLD_CODE, sizeof(MWIPLOTSTS->HOLD_CODE));

        DBC_select_mgcmtbldat(1, &MGCMTBLDAT);

        TRS.add_fieldmsg(out_node, "HOLD_CODE_DESC", DT_STRING, sizeof(MGCMTBLDAT.DATA_1), MGCMTBLDAT.DATA_1);

        return MP_FALSE;
    }

    if (MWIPLOTSTS->LOT_DEL_FLAG == 'Y')
    {
        strcpy(s_msg_code, "WIP-0076");     // WIP-0076 : 이 LOT은 이미 삭제된 LOT 입니다. LOT을  확인 하세요.
        return MP_FALSE;
    }

    return MP_TRUE;
}

/*******************************************************************************
    Equipment_End_Lot()
        - Lot End
    Return Value
        - int : MP_TRUE(1) or MP_FALSE(0)
    Arguments
        - char *s_msg_code : Error Message Code
        - struct MWIPLOTSTS_TAG *MWIPLOTSTS
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int Equipment_End_Lot(char *s_msg_code, struct MWIPLOTSTSX_TAG *MWIPLOTSTS, TRSNode *in_node, TRSNode *out_node)
{
    TRSNode *end_lot_in;

    end_lot_in = TRS.add_node(in_node, "End_Lot_In");

    CopyDefaultMembers(end_lot_in, in_node);
    TRS.add_char(end_lot_in, IN_PROCSTEP, '1');

    TRS.add_nstring(end_lot_in, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));
    TRS.add_string(end_lot_in, "MAT_ID", MWIPLOTSTS->MAT_ID, sizeof(MWIPLOTSTS->MAT_ID));
    TRS.add_int(end_lot_in, "MAT_VER", MWIPLOTSTS->MAT_VER);
    TRS.add_string(end_lot_in, "FLOW", MWIPLOTSTS->FLOW, sizeof(MWIPLOTSTS->FLOW));
    TRS.add_string(end_lot_in, "OPER", MWIPLOTSTS->OPER, sizeof(MWIPLOTSTS->OPER));
    TRS.add_nstring(end_lot_in, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    if (COM_istime(TRS.get_string(in_node, "END_TIME")) == MP_TRUE)
    {
        if (TRS.mem_cmp(in_node, "END_TIME", MWIPLOTSTS->LAST_TRAN_TIME, sizeof(MWIPLOTSTS->LAST_TRAN_TIME)) > 0 &&
            TRS.mem_cmp(in_node, "END_TIME", gs_sys_time, sizeof(gs_sys_time)) < 0)
        {
            TRS.add_nstring(end_lot_in, "BACK_TIME", TRS.get_string(in_node, "END_TIME"));
        }
    }

    TRS.add_nstring(end_lot_in, "ORDER_ID", TRS.get_string(in_node, "ORDER_ID"));

    if (CUS_WIP_END_LOT(s_msg_code, end_lot_in, out_node) == MP_FALSE)
        return MP_FALSE;

    return MP_TRUE;
}

/*******************************************************************************
    BCOM_SAVE_LOG()
        - Main sub function of "SVM_SAVE_ERROR" function
    Return Value
        - int : 1 (MP_TRUE) / 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int BCOM_SAVE_LOG(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MSVMERRLOG_TAG MSVMERRLOG;
    TRSNode **node;
    char s_temp[2000];
    int i;
    double d_tran_time = 0;

    char s_sys_time[14];

    //Server process 종료일때는 아무것도 하지 않느다.

    d_tran_time = 0;// TRS.get_double(in_node, "TRAN_TIME");

    if (in_node == 0x00 || out_node == 0x00)
    {
        return MP_FALSE;
    }
    memset(s_sys_time, ' ', sizeof(s_sys_time));

    DB_get_systime(s_sys_time);
    if (DB_error_code != DB_SUCCESS)
    {
        TRS.add_fieldmsg(out_node, "DB_get_systime", MP_NVST);
        TRS.add_dberrmsg(out_node, DB_error_msg);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;

        COM_set_result(out_node, MP_FAIL_C, "CMN-0004", MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    //설비에서 MES
    if (TRS.get_char(in_node, "USE_EQIF_LOG_FLAG") == 'Y')
    {
        memset(s_temp, 0x0, sizeof(s_temp));

        DBC_init_msvmerrlog(&MSVMERRLOG);
        memcpy(MSVMERRLOG.TRAN_TIME, s_sys_time, sizeof(MSVMERRLOG.TRAN_TIME));
        TRS.copy(MSVMERRLOG.SYSTEM_NODE, sizeof(MSVMERRLOG.SYSTEM_NODE), in_node, "SYSTEM_NODE");
        TRS.copy(MSVMERRLOG.SERVER_NAME, sizeof(MSVMERRLOG.SERVER_NAME), in_node, "SERVER_NAME");
        TRS.copy(MSVMERRLOG.SUBNO, sizeof(MSVMERRLOG.SUBNO), in_node, "SUBNO");
        TRS.copy(MSVMERRLOG.SERVICE_NAME, sizeof(MSVMERRLOG.SERVICE_NAME), in_node, "SERVICE_NAME");
        TRS.copy(MSVMERRLOG.FACTORY, sizeof(MSVMERRLOG.FACTORY), in_node, "FACTORY");
        TRS.copy(MSVMERRLOG.RES_ID, sizeof(MSVMERRLOG.RES_ID), in_node, "RES_ID");
        TRS.copy(MSVMERRLOG.LOT_ID, sizeof(MSVMERRLOG.LOT_ID), in_node, "LOT_ID");

        MSVMERRLOG.STATUS_VALUE = TRS.get_char(in_node, "STATUSVALUE");
        TRS.copy(MSVMERRLOG.MSG_ID, sizeof(MSVMERRLOG.MSG_ID), in_node, "MSGCODE");
        TRS.copy(MSVMERRLOG.ERROR_MSG, sizeof(MSVMERRLOG.ERROR_MSG), in_node, "ERROR_MSG");
        TRS.copy(MSVMERRLOG.DB_ERROR_MSG, sizeof(MSVMERRLOG.DB_ERROR_MSG), in_node, "DBERRMSG");

        MSVMERRLOG.CONSUME_SEC = d_tran_time;
        memset(s_temp, 0x0, sizeof(s_temp));
        node = TRS.get_list(out_node, OUT_FIELDMSG);
        TRS.copy(MSVMERRLOG.ERROR_MSG_DETAIL, sizeof(MSVMERRLOG.ERROR_MSG_DETAIL), in_node, "ERROR_MSG_DETAIL");

        memset(s_temp, 0x0, sizeof(s_temp));
        if (in_node != 0x0)
        {
            //Modify by J.S. 2011.02.06 detail부분 가독성 향상을 위하여 공백 추가, 대괄호 추가
            for (i = 0; i < in_node->MemberCount; i++)
            {
                if (in_node->Members[i]->ValueType == DT_STRING ||
                    in_node->Members[i]->ValueType == DT_NSTRING)
                {
                    if (in_node->Members[i]->Value.s != 0x0)
                    {
                        if ((strlen(s_temp) + strlen(in_node->Members[i]->Value.s)) > 900)
                        {
                            break;
                        }

                        if (strcmp(in_node->Members[i]->Name, "_SERVICE_NAME") == 0 ||
                            strcmp(in_node->Members[i]->Name, "_MODULE_NAME") == 0 ||
                            strcmp(in_node->Members[i]->Name, "PASSWORD") == 0)
                        {
                            //Do Nothing
                        }
                        else
                        {
                            sprintf(s_temp + strlen(s_temp), "%s=[%s] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.s);
                        }
                    }
                }
                else if (in_node->Members[i]->ValueType == DT_CHAR)
                {
                    if (in_node->Members[i]->Value.c != 0x0)
                    {
                        sprintf(s_temp + strlen(s_temp), "%s=[%c] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.c);
                    }
                }
                else if (in_node->Members[i]->ValueType == DT_INT)
                {
                    sprintf(s_temp + strlen(s_temp), "%s=[%d] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.i4);
                }
                else if (in_node->Members[i]->ValueType == DT_LONG)
                {
                    sprintf(s_temp + strlen(s_temp), "%s=[%ld] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.i8);
                }
                else if (in_node->Members[i]->ValueType == DT_FLOAT)
                {
                    sprintf(s_temp + strlen(s_temp), "%s=[%f] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.f4);
                }
                else if (in_node->Members[i]->ValueType == DT_DOUBLE)
                {
                    sprintf(s_temp + strlen(s_temp), "%s=[%f] \n", in_node->Members[i]->Name, in_node->Members[i]->Value.f8);
                }

                //1000 byte이내만 보내기 위해서
                if (strlen(s_temp) > 900)
                {
                    break;
                }
            }
        }
        memcpy(MSVMERRLOG.IN_MSG, s_temp, strlen(s_temp));

        TRS.copy(MSVMERRLOG.ERR_CMF_1, sizeof(MSVMERRLOG.ERR_CMF_1), in_node, "LINE_ID");
        TRS.copy(MSVMERRLOG.ERR_CMF_2, sizeof(MSVMERRLOG.ERR_CMF_2), in_node, "OPER");
        TRS.copy(MSVMERRLOG.CREATE_USER_ID, sizeof(MSVMERRLOG.CREATE_USER_ID), in_node, "USERID");
        memcpy(MSVMERRLOG.CREATE_TIME, s_sys_time, sizeof(MSVMERRLOG.CREATE_TIME));



        DBC_insert_msvmerrlog(&MSVMERRLOG);
        if (DB_error_code != DB_SUCCESS)
        {
            LOG_head("SVM_SAVE_ERROR");
            LOG_add("table", MP_NSTR, "MSVMERRLOG INSERT ERROR");
            LOG_add("db_error_msg", MP_STR, sizeof(DB_error_msg), DB_error_msg);
            COM_log_write(MP_LOG_ERROR, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

            DB_rollback();
            return MP_FALSE;
        }

        DB_commit();

    }

    return MP_TRUE;
}

/*******************************************************************************
    COM_SEND_LOG()
        - 에러를 처리한다.
    Return Value
        - int : MP_TRUE(1) or MP_FALSE(0)
    Arguments
        - char *s_msg_code : Error Message Code
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int BCOM_SEND_LOG(TRSNode *in_node, TRSNode *out_node)
{
    int i;
    char s_tran_time[20];
    char s_temp[1000];
    char s_msg_code[MP_SIZE_MSG];


    TRSNode *tran_in_node;
    TRSNode **node;


    if (in_node == 0x00)
        return MP_FALSE;

    if (out_node == 0x00)
        return MP_FALSE;

    memset(s_temp, 0x0, sizeof(s_temp));
    memset(s_msg_code, ' ', MP_SIZE_MSG);

    tran_in_node = TRS.add_node(in_node, "Send_Error_Log_In");

    TRS.add_char(tran_in_node, "STATUSVALUE", TRS.get_char(out_node, "STATUSVALUE"));
    TRS.add_char(tran_in_node, "PROCSTEP", '1');
    TRS.add_string(tran_in_node, "SITE_ID", gs_site_id, sizeof(gs_site_id));
    TRS.add_string(tran_in_node, "SERVER_NAME", gs_server_name, sizeof(gs_server_name));
    TRS.add_string(tran_in_node, "SYSTEM_NODE", gs_collect_node, sizeof(gs_collect_node));
    TRS.add_nstring(tran_in_node, "USERID", TRS.get_string(in_node, "USERID"));

    TRS.add_string(tran_in_node, "SUBNO", gs_subno, sizeof(gs_subno));

    TRS.add_nstring(tran_in_node, "FACTORY", TRS.get_string(in_node, IN_FACTORY));
    TRS.add_nstring(tran_in_node, "RES_ID", TRS.get_string(in_node, "RES_ID"));
    TRS.add_nstring(tran_in_node, "OPER", TRS.get_string(in_node, "OPER"));
    TRS.add_nstring(tran_in_node, "LOT_ID", TRS.get_string(in_node, "LOT_ID"));

    //데이터 확인이 필요한 정보 추가

    //데이터 확인이 필요한 정보 추가

    TRS.add_nstring(tran_in_node, "SERVICE_NAME", TRS.get_string(in_node, "_SERVICE_NAME"));

    DB_get_systime_m(s_tran_time);

    TRS.add_string(tran_in_node, "TRAN_TIME", s_tran_time, sizeof(s_tran_time));
    TRS.add_nstring(tran_in_node, "MSGCODE", TRS.get_string(out_node, "MSGCODE"));
    TRS.add_nstring(tran_in_node, "ERROR_MSG", TRS.get_string(out_node, "MSG"));
    TRS.add_nstring(tran_in_node, "DBERRMSG", TRS.get_string(out_node, "DBERRMSG"));

    node = TRS.get_list(out_node, OUT_FIELDMSG);

    if (node != 0x0)
    {
        //Modify by J.S. 2011.02.06 detail부분 가독성 향상을 위하여 공백 추가, 대괄호 추가
        for (i = 0; i < node[0]->MemberCount; i++)
        {
            if (node[0]->Members[i]->ValueType == DT_STRING ||
                node[0]->Members[i]->ValueType == DT_NSTRING)
            {
                if (node[0]->Members[i]->Value.s != 0x0)
                {
                    if ((strlen(s_temp) + strlen(node[0]->Members[i]->Value.s)) > 900)
                    {
                        break;
                    }

                    sprintf(s_temp + strlen(s_temp), "%s=[%s] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.s);
                }
            }
            else if (node[0]->Members[i]->ValueType == DT_CHAR)
            {
                if (node[0]->Members[i]->Value.c != 0x0)
                {
                    sprintf(s_temp + strlen(s_temp), "%s=[%c] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.c);
                }
            }
            else if (node[0]->Members[i]->ValueType == DT_INT)
            {
                sprintf(s_temp + strlen(s_temp), "%s=[%d] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.i4);
            }
            else if (node[0]->Members[i]->ValueType == DT_LONG)
            {
                sprintf(s_temp + strlen(s_temp), "%s=[%ld] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.i8);
            }
            else if (node[0]->Members[i]->ValueType == DT_FLOAT)
            {
                sprintf(s_temp + strlen(s_temp), "%s=[%f] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.f4);
            }
            else if (node[0]->Members[i]->ValueType == DT_DOUBLE)
            {
                sprintf(s_temp + strlen(s_temp), "%s=[%f] \n", node[0]->Members[i]->Name, node[0]->Members[i]->Value.f8);
            }

            //1000 byte이내만 보내기 위해서
            if (strlen(s_temp) > 900)
            {
                break;
            }
        }
    }

    TRS.add_nstring(tran_in_node, "ERROR_MSG_DETAIL", s_temp);

    //memset(s_channel, 0x0, sizeof(s_channel));
    //sprintf(s_channel, "/ADMIN01");

    if (TRS.get_char(in_node, "USE_EQIF_LOG_FLAG") == 'Y')
    {
        TRS.set_char(tran_in_node, "USE_EQIF_LOG_FLAG", 'Y');
    }

    BCOM_SAVE_LOG(s_msg_code, tran_in_node, out_node);

    return MP_TRUE;
}
