/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_SHP_update_pack_order.c
Description : 주문지시 정보 갱신

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/12/10                 Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"
#include "CUS_IFS_common.h"

int CUS_SHP_UPDATE_PACK_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_SHP_UPDATE_PACK_ORDER_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
/*******************************************************************************
CUS_SHP_Update_Pack_Order()
- 생산성, 수율 목표 등록
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_Update_Pack_Order(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_SHP_UPDATE_PACK_ORDER(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_SHP_Update_Pack_Order", out_node);

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
CUS_SHP_UPDATE_PACK_ORDER()
- Main sub function of "CUS_SHP_Update_Pack_Order" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_UPDATE_PACK_ORDER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CPAKORDSTS_TAG CPAKORDSTS;
    //struct IF_OM_PROMISE_DATE_TAG IF_OM_PROMISE_DATE;

    TRSNode *inv_if;
    TRSNode *cmn_out;

    int i = 0;

    LOG_head("CUS_SHP_UPDATE_PACK_ORDER");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    //갱신
    if (TRS.get_procstep(in_node) == '1')
    {
        if (CUS_SHP_UPDATE_PACK_ORDER_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
            return MP_FALSE;

        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cpakordsts(&CPAKORDSTS);
            TRS.copy(CPAKORDSTS.FACTORY, sizeof(CPAKORDSTS.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CPAKORDSTS.PACK_ORDER_ID, sizeof(CPAKORDSTS.PACK_ORDER_ID), in_node->SItems[i], "PACK_ORDER_ID");
            CPAKORDSTS.LINE_NO = TRS.get_int(in_node->SItems[i], "LINE_NO");
            DBU_select_cpakordsts(1, &CPAKORDSTS);
            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CPAKORDSTS Select", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "PACK_0RDER_ID", DT_STRING, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
                TRS.add_fieldmsg(out_node, "LINE_NO", DT_STRING, sizeof(CPAKORDSTS.LINE_NO), CPAKORDSTS.LINE_NO);

                return MP_FALSE;
            }

            // 포장 지시 상태 체크
            if (memcmp(CPAKORDSTS.PACK_ORD_STATUS, MP_CSHP_STATUS_WAIT, strlen(MP_CSHP_STATUS_WAIT)) != 0)
            {
                //WIP-0565 : 해당 포장 지시는 이미 포장 완료되었습니다.
                strcpy(s_msg_code, "WIP-0565");
                TRS.add_fieldmsg(out_node, "PACK_ORDER_ID", MP_STR, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
                TRS.add_fieldmsg(out_node, "LINE_NO", MP_INT, CPAKORDSTS.LINE_NO);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                return MP_FALSE;
            }
           
            TRS.copy(CPAKORDSTS.EXPECT_SHIP_DATE, sizeof(CPAKORDSTS.EXPECT_SHIP_DATE), in_node->SItems[i], "EXPECT_SHIP_DATE");
            TRS.copy(CPAKORDSTS.PACK_COMMENT, sizeof(CPAKORDSTS.PACK_COMMENT), in_node->SItems[i], "PACK_COMMENT");
			TRS.copy(CPAKORDSTS.CMF_2, sizeof(CPAKORDSTS.CMF_2), in_node->SItems[i], "CMF_2");

			TRS.copy(CPAKORDSTS.CMF_3, sizeof(CPAKORDSTS.CMF_3), in_node->SItems[i], "CMF_3");
			TRS.copy(CPAKORDSTS.CMF_4, sizeof(CPAKORDSTS.CMF_4), in_node->SItems[i], "CMF_4");
			TRS.copy(CPAKORDSTS.CMF_5, sizeof(CPAKORDSTS.CMF_5), in_node->SItems[i], "CMF_5");
			TRS.copy(CPAKORDSTS.CMF_6, sizeof(CPAKORDSTS.CMF_6), in_node->SItems[i], "CMF_6");


            TRS.copy(CPAKORDSTS.UPDATE_USER_ID, sizeof(CPAKORDSTS.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CPAKORDSTS.UPDATE_TIME, gs_sys_time, sizeof(CPAKORDSTS.UPDATE_TIME));

            DBU_update_cpakordsts(1, &CPAKORDSTS);
            if (DB_error_code != DB_SUCCESS)
            {
                TRS.add_fieldmsg(out_node, "CPAKORDSTS Update 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CPAKORDSTS.FACTORY), CPAKORDSTS.FACTORY);
                TRS.add_fieldmsg(out_node, "PACK_0RDER_ID", DT_STRING, sizeof(CPAKORDSTS.PACK_ORDER_ID), CPAKORDSTS.PACK_ORDER_ID);
                TRS.add_fieldmsg(out_node, "LINE_NO", DT_STRING, sizeof(CPAKORDSTS.LINE_NO), CPAKORDSTS.LINE_NO);

                return MP_FALSE;
            }

            if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "EXPECT_SHIP_DATE")) == MP_FALSE)
            {
                inv_if = TRS.add_node(in_node, "inv_if");
                TRS.add_char(inv_if, IN_PROCSTEP, '1');
                CopyDefaultMembers(inv_if, in_node);

                TRS.add_char(inv_if, "TRAN_FLAG", 'I');
                TRS.add_int(inv_if, "HEADER_ID", atoi(CPAKORDSTS.PACK_ORDER_ID));
                TRS.add_int(inv_if, "LINE_NUMBER", CPAKORDSTS.LINE_NO);                
                TRS.add_nstring(inv_if, "PROMISE_DATE", TRS.get_string(in_node->SItems[i], "EXPECT_SHIP_DATE"));
                TRS.add_nstring(inv_if, "CMF_1", TRS.get_string(in_node->SItems[i], "PACK_COMMENT"));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_IFS_OM_PROMISE_DATE(s_msg_code, inv_if, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }
        }
    }  

    return MP_TRUE;
}

/*******************************************************************************
CUS_SHP_UPDATE_PACK_ORDER_Validation()
- Main sub function of "CUS_SHP_UPDATE_PACK_ORDER" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_SHP_UPDATE_PACK_ORDER_Validation(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    /* ProcStep Validation */
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
