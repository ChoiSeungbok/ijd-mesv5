/*******************************************************************************

System      : MESplus
Module      : CUS_EIS
File Name   : CUS_WIP_delete_p_lot.c
Description : PLot 삭제

MES Version : 5.0

Function List
-

Detail Description
-

History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1    2020/12/7    Create

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

*******************************************************************************/

#include "CUS_common.h"
#include "CUS_EIS_common.h"

int CUS_WIP_DELETE_P_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_WIP_DELETE_P_LOT_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
/*******************************************************************************
CUS_WIP_Delete_P_Lot()
- 
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_Delete_P_Lot(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_WIP_DELETE_P_LOT(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
    {
        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_SETUP;

        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
    }

    COM_out_msg_log_write(s_msg_code, "CUS_WIP_Delete_P_Lot", out_node);

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
CUS_WIP_DELETE_P_LOT()
- Main sub function of "CUS_WIP_Delete_P_Lot" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_DELETE_P_LOT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct CWIPLOTREC_TAG CWIPLOTREC;
    TRSNode *terminate_in;
    TRSNode *cmn_out;
    int i = 0;

    LOG_head("CUS_WIP_DELETE_P_LOT");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);


    if (CUS_WIP_DELETE_P_LOT_VALIDATION(s_msg_code, in_node, out_node) == MP_FALSE)
        return MP_FALSE;
   
  
        for (i = 0; i < in_node->SCount; i++)
        {
            DBU_init_cwiplotrec(&CWIPLOTREC);

            TRS.copy(CWIPLOTREC.FACTORY, sizeof(CWIPLOTREC.FACTORY), in_node, IN_FACTORY);
            TRS.copy(CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID), in_node->SItems[i], "LOT_ID");
            DBU_select_cwiplotrec(2, &CWIPLOTREC);
            
			
			if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CWIPLOTREC Select 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

                return MP_FALSE;
            }




            terminate_in = TRS.add_node(in_node, "terminate_in");
            CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

            TRS.add_char(terminate_in, "PROCSTEP", '1');
            TRS.add_string(terminate_in, "LOT_ID", CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));

            cmn_out = TRS.create_node("Cmn_Out");
            if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
            {
                TRS.clone(out_node, cmn_out);
                TRS.free_node(cmn_out);
                return MP_FALSE;
            }
            TRS.free_node(cmn_out);



            /*

            
            //CTM 사업부 LOT TERMINATE
            if (memcmp(CWIPLOTREC.AREA_ID, "CTM", strlen("CTM")) == 0)
            {              
                terminate_in = TRS.add_node(in_node, "terminate_in");
                CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

                TRS.add_char(terminate_in, "PROCSTEP", '1');
                TRS.add_string(terminate_in, "LOT_ID", CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));

                cmn_out = TRS.create_node("Cmn_Out");
                if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
                {
                    TRS.clone(out_node, cmn_out);
                    TRS.free_node(cmn_out);
                    return MP_FALSE;
                }
                TRS.free_node(cmn_out);
            }


			else if (memcmp(CWIPLOTREC.AREA_ID, "CTV", strlen("CTV")) == 0)
			{
				terminate_in = TRS.add_node(in_node, "terminate_in");
				CopyDefaultMembers(terminate_in, in_node); // LANGUAGE, FACTORY, USERID, PW, PASSPORT

				TRS.add_char(terminate_in, "PROCSTEP", '1');
				TRS.add_string(terminate_in, "LOT_ID", CWIPLOTREC.LOT_ID, sizeof(CWIPLOTREC.LOT_ID));

				cmn_out = TRS.create_node("Cmn_Out");
				if (CUS_WIP_TERMINATE_LOT(s_msg_code, terminate_in, cmn_out) == MP_FALSE)
				{
					TRS.clone(out_node, cmn_out);
					TRS.free_node(cmn_out);
					return MP_FALSE;
				}
				TRS.free_node(cmn_out);
			}

            */


            CWIPLOTREC.DELETE_FLAG = 'Y';
            TRS.copy(CWIPLOTREC.UPDATE_USER_ID, sizeof(CWIPLOTREC.UPDATE_USER_ID), in_node, IN_USERID);
            memcpy(CWIPLOTREC.UPDATE_TIME, gs_sys_time, sizeof(CWIPLOTREC.UPDATE_TIME));

            DBU_update_cwiplotrec(4, &CWIPLOTREC);
            if (DB_error_code != DB_SUCCESS && DB_error_code != DB_NOT_FOUND)
            {
                TRS.add_fieldmsg(out_node, "CWIPLOTREC Delete 1", DT_NOVALUESTRING);
                TRS.add_fieldmsg(out_node, "FACTORY", DT_STRING, sizeof(CWIPLOTREC.FACTORY), CWIPLOTREC.FACTORY);
                TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(CWIPLOTREC.LOT_ID), CWIPLOTREC.LOT_ID);

                return MP_FALSE;
            }
        }    

    return MP_TRUE;
}

/*******************************************************************************
CUS_WIP_DELETE_P_LOT_VALIDATION()
- Main sub function of "CUS_WIP_DELETE_P_LOT" function
Return Value
- int : 0 (IOI_SUCCESS)
Arguments
- char *Msg_Code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_WIP_DELETE_P_LOT_VALIDATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    
    if (COM_isnullspace(TRS.get_string(in_node, "FACTORY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "WIP-0001");
        TRS.add_fieldmsg(out_node, "FACTORY", MP_NVST);
        return MP_FALSE;
    }

    int i = 0;
    for (i = 0; i < in_node->SCount; i++)
    {

        if (COM_isnullspace(TRS.get_string(in_node->SItems[i], "LOT_ID")) == MP_TRUE)
        {
            strcpy(s_msg_code, "WIP-0001");
            TRS.add_fieldmsg(out_node, "LOT_ID", MP_NVST);

            return MP_FALSE;
        }
        
    }

    return MP_TRUE;
}
