/******************************************************************************'

    System      : MESplus
    Module      : CUS
    File Name   : CUS_common.c
    Description : Customer Common Function 

    MES Version : 5.3.4 ~

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2019/03/17             Create by Generator

    Copyright(C) 1998-2016 Miracom,Inc.
    All rights reserved.

******************************************************************************/

#include "CUS_common.h"
#include <WIPCore_common.h>

/*******************************************************************************
    Get_shift()
        - Validate date string
    Return Value
        - int : MP_TRUE or MP_FALSE
    Arguments
        - char *sFactory : date string
        - struct work_date_tag *work_date
*******************************************************************************/
int Get_shift(char *sFactory, struct work_date_tag *work_date)
{
    char sWorkMonth[6];
    char sWorkDate[8];
    char sWorkTime[14];
    char sDayNight[10];
    int iDate = 0 ;
    int iTime = 0 ;

    memset(sWorkDate, ' ', sizeof(sWorkDate));
    memset(sWorkMonth, ' ', sizeof(sWorkMonth));
    memset(sDayNight, ' ', sizeof(sDayNight));

	if (work_date->c_kind != 'L') // local time을 사용할때
	{
        memset(work_date, ' ', sizeof(struct work_date_tag));

        memcpy(work_date->s_sys_time, gs_sys_time, sizeof(work_date->s_sys_time));
	}

    iDate = COM_atoi(&work_date->s_sys_time[6], 2);
    iTime = COM_atoi(&work_date->s_sys_time[8], 4);

    //Calculate Work Date 
    if(800 <= iTime && iTime <= 2359)
    {
        memcpy(sWorkDate, work_date->s_sys_time, sizeof(sWorkDate));
    }
    else if(0 <= iTime && iTime <= 759)
    {
        COM_sub_time(sWorkTime, work_date->s_sys_time, "001000000");
        memcpy(sWorkDate, sWorkTime, sizeof(sWorkDate));
    }

    //Calculate Work Shift
    // D : 주간, N : 야간
    if(800 <= iTime && iTime <= 1959)
    {
        sDayNight[0] = 'D';
    }
    else if (2000 <= iTime && iTime <= 2359)
    {
        sDayNight[0] = 'N';
    }
    else if (0 <= iTime && iTime <= 759)
    {
        sDayNight[0] = 'N';
    }

	memcpy(sWorkMonth, sWorkDate, sizeof(sWorkMonth));

    memcpy(&work_date->s_work_date, sWorkDate, sizeof(sWorkDate));
    memcpy(&work_date->s_day_night, sDayNight, sizeof(sDayNight));
    memcpy(&work_date->s_work_month, sWorkMonth, sizeof(sWorkMonth));

    return 1;
}

/*******************************************************************************
Get_shift()
- Validate date string
Return Value
- int : MP_TRUE or MP_FALSE
Arguments
- char *sFactory : date string
- struct work_date_tag *work_date
*******************************************************************************/
int Get_shift_EAP(char *sFactory, struct work_date_tag *work_date, char *eap_sys_time)
{
	char sWorkMonth[6];
	char sWorkDate[8];
	char sWorkTime[14];
	char sDayNight[10];
	int iDate = 0;
	int iTime = 0;

	memset(sWorkDate, ' ', sizeof(sWorkDate));
	memset(sWorkMonth, ' ', sizeof(sWorkMonth));
	memset(sDayNight, ' ', sizeof(sDayNight));

	if (work_date->c_kind != 'L') // local time을 사용할때
	{
		memset(work_date, ' ', sizeof(struct work_date_tag));

		memcpy(work_date->s_sys_time, eap_sys_time, sizeof(work_date->s_sys_time));
	}

	iDate = COM_atoi(&work_date->s_sys_time[6], 2);
	iTime = COM_atoi(&work_date->s_sys_time[8], 4);

	//Calculate Work Date 
	if (800 <= iTime && iTime <= 2359)
	{
		memcpy(sWorkDate, work_date->s_sys_time, sizeof(sWorkDate));
	}
	else if (0 <= iTime && iTime <= 759)
	{
		COM_sub_time(sWorkTime, work_date->s_sys_time, "001000000");
		memcpy(sWorkDate, sWorkTime, sizeof(sWorkDate));
	}

	//Calculate Work Shift
	// D : 주간, N : 야간
	if (800 <= iTime && iTime <= 1959)
	{
		sDayNight[0] = 'D';
	}
	else if (2000 <= iTime && iTime <= 2359)
	{
		sDayNight[0] = 'N';
	}
	else if (0 <= iTime && iTime <= 759)
	{
		sDayNight[0] = 'N';
	}

	memcpy(sWorkMonth, sWorkDate, sizeof(sWorkMonth));

	memcpy(&work_date->s_work_date, sWorkDate, sizeof(sWorkDate));
	memcpy(&work_date->s_day_night, sDayNight, sizeof(sDayNight));
	memcpy(&work_date->s_work_month, sWorkMonth, sizeof(sWorkMonth));

	return 1;
}

void com_lrtrim(char *d_p, char *s_p, int i, int size_i)
{
    for(i ; i < size_i; i++)
    {
        if(s_p[i] != ' ')
        {
            break;
        }
    }

    memcpy(d_p, s_p + i, size_i);
}



/*******************************************************************************
    CopyDefaultMembers()
        - Copy Default Members
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - TRSNode *target_node : Target Node
        - TRSNode *source_node : Source Node
*******************************************************************************/
int CopyDefaultMembers(TRSNode *target_node, TRSNode *source_node)
{
    TRS.set_char(target_node, IN_LANGUAGE, TRS.get_language(source_node));
    TRS.set_nstring(target_node, IN_FACTORY, TRS.get_factory(source_node));
    TRS.set_nstring(target_node, IN_USERID, TRS.get_userid(source_node));
    TRS.set_nstring(target_node, IN_PASSWORD, " ");
    TRS.set_nstring(target_node, IN_PASSPORT, TRS.get_passport(source_node));

    return MP_TRUE;
}

/*******************************************************************************
    COM_UPDATE_LOT_CMF()
        - Update status and history of lot By Lot ID
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - string sLot
        - TRSNode *in_node : In Node from each transaction function
        - TRSNode *out_node : Common out node for result message
*******************************************************************************/
int COM_UPDATE_LOT_CMF(char *sLot, char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX;
    struct MWIPLOTSTSX_TAG MWIPLOTSTSX_SPLIT;
    struct MWIPLOTHISX_TAG MWIPLOTHISX;
    //TRSNode *member;

    DBU_init_mwiplotstsx(&MWIPLOTSTSX);
    memcpy(MWIPLOTSTSX.LOT_ID, sLot, sizeof(MWIPLOTSTSX.LOT_ID));    

    DBU_select_mwiplotstsx(1, &MWIPLOTSTSX);
    if(DB_error_code != DB_SUCCESS)
    {
        if(DB_error_code == DB_NOT_FOUND)
        {
            memcpy(s_msg_code, "WIP-0044", MP_SIZE_MSG);
            gs_log_type.e_type = MP_LOG_E_EXISTENCE;
        }
        else
        {
            memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.category = MP_LOG_CATE_TRANS;
        
        return MP_FALSE;
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX.LOT_CMF_1), in_node, "LOT_CMF_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX.LOT_CMF_2), in_node, "LOT_CMF_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX.LOT_CMF_3), in_node, "LOT_CMF_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX.LOT_CMF_4), in_node, "LOT_CMF_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX.LOT_CMF_5), in_node, "LOT_CMF_5");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_6")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX.LOT_CMF_6), in_node, "LOT_CMF_6");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_7")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX.LOT_CMF_7), in_node, "LOT_CMF_7");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_8")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX.LOT_CMF_8), in_node, "LOT_CMF_8");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_9")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX.LOT_CMF_9), in_node, "LOT_CMF_9");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_10")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX.LOT_CMF_10), in_node, "LOT_CMF_10");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_11")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX.LOT_CMF_11), in_node, "LOT_CMF_11");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_12")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX.LOT_CMF_12), in_node, "LOT_CMF_12");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_13")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX.LOT_CMF_13), in_node, "LOT_CMF_13");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_14")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX.LOT_CMF_14), in_node, "LOT_CMF_14");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_15")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX.LOT_CMF_15), in_node, "LOT_CMF_15");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_16")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX.LOT_CMF_16), in_node, "LOT_CMF_16");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_17")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX.LOT_CMF_17), in_node, "LOT_CMF_17");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_18")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX.LOT_CMF_18), in_node, "LOT_CMF_18");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_19")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX.LOT_CMF_19), in_node, "LOT_CMF_19");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "LOT_CMF_20")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX.LOT_CMF_20), in_node, "LOT_CMF_20");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.ADD_ORDER_ID_1, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_1), in_node, "ADD_ORDER_ID_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.ADD_ORDER_ID_2, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_2), in_node, "ADD_ORDER_ID_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "ADD_ORDER_ID_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.ADD_ORDER_ID_3, sizeof(MWIPLOTSTSX.ADD_ORDER_ID_3), in_node, "ADD_ORDER_ID_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.RESV_FIELD_1, sizeof(MWIPLOTSTSX.RESV_FIELD_1), in_node, "RESV_FIELD_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.RESV_FIELD_2, sizeof(MWIPLOTSTSX.RESV_FIELD_2), in_node, "RESV_FIELD_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTSTSX.RESV_FIELD_3), in_node, "RESV_FIELD_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.RESV_FIELD_4, sizeof(MWIPLOTSTSX.RESV_FIELD_4), in_node, "RESV_FIELD_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "RESV_FIELD_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.RESV_FIELD_5, sizeof(MWIPLOTSTSX.RESV_FIELD_5), in_node, "RESV_FIELD_5");
    }

    if (TRS.get_char(in_node, "RESV_FLAG_1") != ' ')
    {
        MWIPLOTSTSX.RESV_FLAG_1 = TRS.get_char(in_node, "RESV_FLAG_1");
    }
    if (TRS.get_char(in_node, "RESV_FLAG_2") != ' ')
    {
        MWIPLOTSTSX.RESV_FLAG_2 = TRS.get_char(in_node, "RESV_FLAG_2");
    }
    if (TRS.get_char(in_node, "RESV_FLAG_3") != ' ')
    {
        MWIPLOTSTSX.RESV_FLAG_3 = TRS.get_char(in_node, "RESV_FLAG_3");
    }
    if (TRS.get_char(in_node, "RESV_FLAG_4") != ' ')
    {
        MWIPLOTSTSX.RESV_FLAG_4 = TRS.get_char(in_node, "RESV_FLAG_4");
    }
    if (TRS.get_char(in_node, "RESV_FLAG_5") != ' ')
    {
        MWIPLOTSTSX.RESV_FLAG_5 = TRS.get_char(in_node, "RESV_FLAG_5");
    }
    //CTM CFM 저장
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX.CTM_CMF_1), in_node, "CTM_CMF_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX.CTM_CMF_2), in_node, "CTM_CMF_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX.CTM_CMF_3), in_node, "CTM_CMF_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX.CTM_CMF_4), in_node, "CTM_CMF_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX.CTM_CMF_5), in_node, "CTM_CMF_5");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_6")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX.CTM_CMF_6), in_node, "CTM_CMF_6");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_7")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX.CTM_CMF_7), in_node, "CTM_CMF_7");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_8")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX.CTM_CMF_8), in_node, "CTM_CMF_8");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_9")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX.CTM_CMF_9), in_node, "CTM_CMF_9");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_10")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX.CTM_CMF_10), in_node, "CTM_CMF_10");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_11")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX.CTM_CMF_11), in_node, "CTM_CMF_11");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_12")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX.CTM_CMF_12), in_node, "CTM_CMF_12");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_13")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX.CTM_CMF_13), in_node, "CTM_CMF_13");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_14")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX.CTM_CMF_14), in_node, "CTM_CMF_14");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_15")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX.CTM_CMF_15), in_node, "CTM_CMF_15");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_16")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX.CTM_CMF_16), in_node, "CTM_CMF_16");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_17")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX.CTM_CMF_17), in_node, "CTM_CMF_17");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_18")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX.CTM_CMF_18), in_node, "CTM_CMF_18");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_19")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX.CTM_CMF_19), in_node, "CTM_CMF_19");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "CTM_CMF_20")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX.CTM_CMF_20), in_node, "CTM_CMF_20");
    }
    //PDC CFM 저장
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX.PDC_CMF_1), in_node, "PDC_CMF_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX.PDC_CMF_2), in_node, "PDC_CMF_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX.PDC_CMF_3), in_node, "PDC_CMF_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX.PDC_CMF_4), in_node, "PDC_CMF_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX.PDC_CMF_5), in_node, "PDC_CMF_5");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_6")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX.PDC_CMF_6), in_node, "PDC_CMF_6");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_7")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX.PDC_CMF_7), in_node, "PDC_CMF_7");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_8")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX.PDC_CMF_8), in_node, "PDC_CMF_8");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_9")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX.PDC_CMF_9), in_node, "PDC_CMF_9");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_10")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX.PDC_CMF_10), in_node, "PDC_CMF_10");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_11")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX.PDC_CMF_11), in_node, "PDC_CMF_11");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_12")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX.PDC_CMF_12), in_node, "PDC_CMF_12");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_13")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX.PDC_CMF_13), in_node, "PDC_CMF_13");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_14")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX.PDC_CMF_14), in_node, "PDC_CMF_14");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_15")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX.PDC_CMF_15), in_node, "PDC_CMF_15");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_16")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX.PDC_CMF_16), in_node, "PDC_CMF_16");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_17")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX.PDC_CMF_17), in_node, "PDC_CMF_17");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_18")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX.PDC_CMF_18), in_node, "PDC_CMF_18");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_19")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX.PDC_CMF_19), in_node, "PDC_CMF_19");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "PDC_CMF_20")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX.PDC_CMF_20), in_node, "PDC_CMF_20");
    }
    //HM CFM 저장
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX.HM_CMF_1), in_node, "HM_CMF_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX.HM_CMF_2), in_node, "HM_CMF_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX.HM_CMF_3), in_node, "HM_CMF_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX.HM_CMF_4), in_node, "HM_CMF_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX.HM_CMF_5), in_node, "HM_CMF_5");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_6")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX.HM_CMF_6), in_node, "HM_CMF_6");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_7")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX.HM_CMF_7), in_node, "HM_CMF_7");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_8")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX.HM_CMF_8), in_node, "HM_CMF_8");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_9")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX.HM_CMF_9), in_node, "HM_CMF_9");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_10")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX.HM_CMF_10), in_node, "HM_CMF_10");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_11")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX.HM_CMF_11), in_node, "HM_CMF_11");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_12")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX.HM_CMF_12), in_node, "HM_CMF_12");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_13")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX.HM_CMF_13), in_node, "HM_CMF_13");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_14")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX.HM_CMF_14), in_node, "HM_CMF_14");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_15")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX.HM_CMF_15), in_node, "HM_CMF_15");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_16")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX.HM_CMF_16), in_node, "HM_CMF_16");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_17")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX.HM_CMF_17), in_node, "HM_CMF_17");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_18")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX.HM_CMF_18), in_node, "HM_CMF_18");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_19")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX.HM_CMF_19), in_node, "HM_CMF_19");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "HM_CMF_20")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX.HM_CMF_20), in_node, "HM_CMF_20");
    }
    //GRIT CFM 저장
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_1")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX.GRT_CMF_1), in_node, "GRT_CMF_1");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_2")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX.GRT_CMF_2), in_node, "GRT_CMF_2");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_3")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX.GRT_CMF_3), in_node, "GRT_CMF_3");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_4")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX.GRT_CMF_4), in_node, "GRT_CMF_4");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_5")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX.GRT_CMF_5), in_node, "GRT_CMF_5");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_6")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX.GRT_CMF_6), in_node, "GRT_CMF_6");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_7")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX.GRT_CMF_7), in_node, "GRT_CMF_7");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_8")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX.GRT_CMF_8), in_node, "GRT_CMF_8");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_9")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX.GRT_CMF_9), in_node, "GRT_CMF_9");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_10")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX.GRT_CMF_10), in_node, "GRT_CMF_10");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_11")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX.GRT_CMF_11), in_node, "GRT_CMF_11");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_12")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX.GRT_CMF_12), in_node, "GRT_CMF_12");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_13")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX.GRT_CMF_13), in_node, "GRT_CMF_13");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_14")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX.GRT_CMF_14), in_node, "GRT_CMF_14");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_15")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX.GRT_CMF_15), in_node, "GRT_CMF_15");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_16")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX.GRT_CMF_16), in_node, "GRT_CMF_16");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_17")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX.GRT_CMF_17), in_node, "GRT_CMF_17");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_18")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX.GRT_CMF_18), in_node, "GRT_CMF_18");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_19")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX.GRT_CMF_19), in_node, "GRT_CMF_19");
    }
    if (COM_isnullspace(TRS.get_string(in_node, "GRT_CMF_20")) == MP_FALSE)
    {
        TRS.copy(MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX.GRT_CMF_20), in_node, "GRT_CMF_20");
    }

    DBU_update_mwiplotstsx(1, &MWIPLOTSTSX);
    if(DB_error_code != DB_SUCCESS)
    {            
        memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
        TRS.add_dberrmsg(out_node, DB_error_msg);
        TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX.LOT_ID), MWIPLOTSTSX.LOT_ID);

        return MP_FALSE;
    }

    DBU_init_mwiplothisx(&MWIPLOTHISX);
    memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));    
    MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX.LAST_ACTIVE_HIST_SEQ;

    DBU_select_mwiplothisx(1, &MWIPLOTHISX);
    if(DB_error_code != DB_SUCCESS)
    {
        if(DB_error_code == DB_NOT_FOUND)
        {
            memcpy(s_msg_code, "WIP-0044", MP_SIZE_MSG);
        }
        else
        {
            memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
            TRS.add_dberrmsg(out_node, DB_error_msg);
        }

        TRS.add_fieldmsg(out_node, "MWIPLOTHISX SELECT", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);        
        TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTHISX.HIST_SEQ);        
        
        return MP_FALSE;
    }

    memcpy(MWIPLOTHISX.LOT_CMF_1, MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_2, MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_3, MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_4, MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_5, MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_6, MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_7, MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_8, MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_9, MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_10, MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_11, MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_12, MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_13, MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_14, MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_15, MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_16, MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_17, MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_18, MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_19, MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.LOT_CMF_20, MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTHISX.LOT_CMF_1));
    memcpy(MWIPLOTHISX.ADD_ORDER_ID_1, MWIPLOTSTSX.ADD_ORDER_ID_1, sizeof(MWIPLOTHISX.ADD_ORDER_ID_1));
    memcpy(MWIPLOTHISX.ADD_ORDER_ID_2, MWIPLOTSTSX.ADD_ORDER_ID_2, sizeof(MWIPLOTHISX.ADD_ORDER_ID_2));
    memcpy(MWIPLOTHISX.ADD_ORDER_ID_3, MWIPLOTSTSX.ADD_ORDER_ID_3, sizeof(MWIPLOTHISX.ADD_ORDER_ID_3));
    memcpy(MWIPLOTHISX.RESV_FIELD_1, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MWIPLOTHISX.RESV_FIELD_1));
    memcpy(MWIPLOTHISX.RESV_FIELD_2, MWIPLOTSTSX.RESV_FIELD_2, sizeof(MWIPLOTHISX.RESV_FIELD_2));
    memcpy(MWIPLOTHISX.RESV_FIELD_3, MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTHISX.RESV_FIELD_3));
    memcpy(MWIPLOTHISX.RESV_FIELD_4, MWIPLOTSTSX.RESV_FIELD_4, sizeof(MWIPLOTHISX.RESV_FIELD_4));
    memcpy(MWIPLOTHISX.RESV_FIELD_5, MWIPLOTSTSX.RESV_FIELD_5, sizeof(MWIPLOTHISX.RESV_FIELD_5));
    MWIPLOTHISX.RESV_FLAG_1 = MWIPLOTSTSX.RESV_FLAG_1;
    MWIPLOTHISX.RESV_FLAG_2 = MWIPLOTSTSX.RESV_FLAG_2;
    MWIPLOTHISX.RESV_FLAG_3 = MWIPLOTSTSX.RESV_FLAG_3;
    MWIPLOTHISX.RESV_FLAG_4 = MWIPLOTSTSX.RESV_FLAG_4;
    MWIPLOTHISX.RESV_FLAG_5 = MWIPLOTSTSX.RESV_FLAG_5;

    //CTM CFM 저장
    memcpy(MWIPLOTHISX.CTM_CMF_1, MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_2, MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_3, MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_4, MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_5, MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_6, MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_7, MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_8, MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_9, MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_10, MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_11, MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_12, MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_13, MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_14, MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_15, MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_16, MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_17, MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_18, MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_19, MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTHISX.CTM_CMF_1));
    memcpy(MWIPLOTHISX.CTM_CMF_20, MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTHISX.CTM_CMF_1));
    //PDC CFM 저장
    memcpy(MWIPLOTHISX.PDC_CMF_1, MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_2, MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_3, MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_4, MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_5, MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_6, MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_7, MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_8, MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_9, MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_10, MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_11, MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_12, MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_13, MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_14, MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_15, MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_16, MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_17, MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_18, MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_19, MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTHISX.PDC_CMF_1));
    memcpy(MWIPLOTHISX.PDC_CMF_20, MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTHISX.PDC_CMF_1));
    //HM CFM 저장
    memcpy(MWIPLOTHISX.HM_CMF_1, MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_2, MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_3, MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_4, MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_5, MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_6, MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_7, MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_8, MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_9, MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_10, MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_11, MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_12, MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_13, MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_14, MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_15, MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_16, MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_17, MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_18, MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_19, MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTHISX.HM_CMF_1));
    memcpy(MWIPLOTHISX.HM_CMF_20, MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTHISX.HM_CMF_1));
    //GRIT CFM 저장
    memcpy(MWIPLOTHISX.GRT_CMF_1, MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_2, MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_3, MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_4, MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_5, MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_6, MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_7, MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_8, MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_9, MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_10, MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_11, MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_12, MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_13, MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_14, MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_15, MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_16, MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_17, MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_18, MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_19, MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTHISX.GRT_CMF_1));
    memcpy(MWIPLOTHISX.GRT_CMF_20, MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTHISX.GRT_CMF_1));

    DBU_update_mwiplothisx(1, &MWIPLOTHISX);
    if(DB_error_code != DB_SUCCESS)
    {            
        memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
        TRS.add_dberrmsg(out_node, DB_error_msg);            

        TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", MP_NVST);
        TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);        
        TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTHISX.HIST_SEQ);        
        
        return MP_FALSE;
    }

    //SPLIT인 경우 자LOT의 CMF까지 같이 업데이트 해준다.
    if (memcmp(MWIPLOTSTSX.LAST_TRAN_CODE, MP_TRAN_CODE_SPLIT, strlen(MP_TRAN_CODE_SPLIT)) == MP_FALSE)
    {
        if (MWIPLOTSTSX.FROM_TO_FLAG == 'F')
        {
            DBU_init_mwiplotstsx(&MWIPLOTSTSX_SPLIT);
            memcpy(MWIPLOTSTSX_SPLIT.LOT_ID, MWIPLOTSTSX.FROM_TO_LOT_ID, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID));

            DBU_select_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    memcpy(s_msg_code, "WIP-0044", MP_SIZE_MSG);
                }
                else
                {
                    memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                }

                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);

                return MP_FALSE;
            }

            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_1, MWIPLOTSTSX.LOT_CMF_1, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_2, MWIPLOTSTSX.LOT_CMF_2, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_3, MWIPLOTSTSX.LOT_CMF_3, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_4, MWIPLOTSTSX.LOT_CMF_4, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_5, MWIPLOTSTSX.LOT_CMF_5, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_6, MWIPLOTSTSX.LOT_CMF_6, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_7, MWIPLOTSTSX.LOT_CMF_7, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_8, MWIPLOTSTSX.LOT_CMF_8, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_9, MWIPLOTSTSX.LOT_CMF_9, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_10, MWIPLOTSTSX.LOT_CMF_10, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_11, MWIPLOTSTSX.LOT_CMF_11, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_12, MWIPLOTSTSX.LOT_CMF_12, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_13, MWIPLOTSTSX.LOT_CMF_13, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_14, MWIPLOTSTSX.LOT_CMF_14, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_15, MWIPLOTSTSX.LOT_CMF_15, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_16, MWIPLOTSTSX.LOT_CMF_16, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_17, MWIPLOTSTSX.LOT_CMF_17, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_18, MWIPLOTSTSX.LOT_CMF_18, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_19, MWIPLOTSTSX.LOT_CMF_19, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.LOT_CMF_20, MWIPLOTSTSX.LOT_CMF_20, sizeof(MWIPLOTSTSX_SPLIT.LOT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_1, MWIPLOTSTSX.ADD_ORDER_ID_1, sizeof(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_1));
            memcpy(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_2, MWIPLOTSTSX.ADD_ORDER_ID_2, sizeof(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_2));
            memcpy(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_3, MWIPLOTSTSX.ADD_ORDER_ID_3, sizeof(MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_3));
            memcpy(MWIPLOTSTSX_SPLIT.RESV_FIELD_1, MWIPLOTSTSX.RESV_FIELD_1, sizeof(MWIPLOTSTSX_SPLIT.RESV_FIELD_1));
            memcpy(MWIPLOTSTSX_SPLIT.RESV_FIELD_2, MWIPLOTSTSX.RESV_FIELD_2, sizeof(MWIPLOTSTSX_SPLIT.RESV_FIELD_2));
            memcpy(MWIPLOTSTSX_SPLIT.RESV_FIELD_3, MWIPLOTSTSX.RESV_FIELD_3, sizeof(MWIPLOTSTSX_SPLIT.RESV_FIELD_3));
            memcpy(MWIPLOTSTSX_SPLIT.RESV_FIELD_4, MWIPLOTSTSX.RESV_FIELD_4, sizeof(MWIPLOTSTSX_SPLIT.RESV_FIELD_4));
            memcpy(MWIPLOTSTSX_SPLIT.RESV_FIELD_5, MWIPLOTSTSX.RESV_FIELD_5, sizeof(MWIPLOTSTSX_SPLIT.RESV_FIELD_5));
            MWIPLOTSTSX_SPLIT.RESV_FLAG_1 = MWIPLOTSTSX.RESV_FLAG_1;
            MWIPLOTSTSX_SPLIT.RESV_FLAG_2 = MWIPLOTSTSX.RESV_FLAG_2;
            MWIPLOTSTSX_SPLIT.RESV_FLAG_3 = MWIPLOTSTSX.RESV_FLAG_3;
            MWIPLOTSTSX_SPLIT.RESV_FLAG_4 = MWIPLOTSTSX.RESV_FLAG_4;
            MWIPLOTSTSX_SPLIT.RESV_FLAG_5 = MWIPLOTSTSX.RESV_FLAG_5;

            //CTM CFM 저장
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_1, MWIPLOTSTSX.CTM_CMF_1, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_2, MWIPLOTSTSX.CTM_CMF_2, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_3, MWIPLOTSTSX.CTM_CMF_3, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_4, MWIPLOTSTSX.CTM_CMF_4, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_5, MWIPLOTSTSX.CTM_CMF_5, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_6, MWIPLOTSTSX.CTM_CMF_6, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_7, MWIPLOTSTSX.CTM_CMF_7, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_8, MWIPLOTSTSX.CTM_CMF_8, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_9, MWIPLOTSTSX.CTM_CMF_9, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_10, MWIPLOTSTSX.CTM_CMF_10, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_11, MWIPLOTSTSX.CTM_CMF_11, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_12, MWIPLOTSTSX.CTM_CMF_12, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_13, MWIPLOTSTSX.CTM_CMF_13, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_14, MWIPLOTSTSX.CTM_CMF_14, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_15, MWIPLOTSTSX.CTM_CMF_15, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_16, MWIPLOTSTSX.CTM_CMF_16, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_17, MWIPLOTSTSX.CTM_CMF_17, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_18, MWIPLOTSTSX.CTM_CMF_18, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_19, MWIPLOTSTSX.CTM_CMF_19, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.CTM_CMF_20, MWIPLOTSTSX.CTM_CMF_20, sizeof(MWIPLOTSTSX_SPLIT.CTM_CMF_1));
            //PDC CFM 저장
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_1, MWIPLOTSTSX.PDC_CMF_1, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_2, MWIPLOTSTSX.PDC_CMF_2, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_3, MWIPLOTSTSX.PDC_CMF_3, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_4, MWIPLOTSTSX.PDC_CMF_4, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_5, MWIPLOTSTSX.PDC_CMF_5, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_6, MWIPLOTSTSX.PDC_CMF_6, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_7, MWIPLOTSTSX.PDC_CMF_7, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_8, MWIPLOTSTSX.PDC_CMF_8, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_9, MWIPLOTSTSX.PDC_CMF_9, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_10, MWIPLOTSTSX.PDC_CMF_10, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_11, MWIPLOTSTSX.PDC_CMF_11, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_12, MWIPLOTSTSX.PDC_CMF_12, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_13, MWIPLOTSTSX.PDC_CMF_13, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_14, MWIPLOTSTSX.PDC_CMF_14, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_15, MWIPLOTSTSX.PDC_CMF_15, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_16, MWIPLOTSTSX.PDC_CMF_16, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_17, MWIPLOTSTSX.PDC_CMF_17, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_18, MWIPLOTSTSX.PDC_CMF_18, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_19, MWIPLOTSTSX.PDC_CMF_19, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.PDC_CMF_20, MWIPLOTSTSX.PDC_CMF_20, sizeof(MWIPLOTSTSX_SPLIT.PDC_CMF_1));
            //HM CFM 저장
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_1, MWIPLOTSTSX.HM_CMF_1, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_2, MWIPLOTSTSX.HM_CMF_2, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_3, MWIPLOTSTSX.HM_CMF_3, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_4, MWIPLOTSTSX.HM_CMF_4, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_5, MWIPLOTSTSX.HM_CMF_5, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_6, MWIPLOTSTSX.HM_CMF_6, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_7, MWIPLOTSTSX.HM_CMF_7, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_8, MWIPLOTSTSX.HM_CMF_8, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_9, MWIPLOTSTSX.HM_CMF_9, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_10, MWIPLOTSTSX.HM_CMF_10, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_11, MWIPLOTSTSX.HM_CMF_11, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_12, MWIPLOTSTSX.HM_CMF_12, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_13, MWIPLOTSTSX.HM_CMF_13, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_14, MWIPLOTSTSX.HM_CMF_14, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_15, MWIPLOTSTSX.HM_CMF_15, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_16, MWIPLOTSTSX.HM_CMF_16, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_17, MWIPLOTSTSX.HM_CMF_17, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_18, MWIPLOTSTSX.HM_CMF_18, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_19, MWIPLOTSTSX.HM_CMF_19, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.HM_CMF_20, MWIPLOTSTSX.HM_CMF_20, sizeof(MWIPLOTSTSX_SPLIT.HM_CMF_1));
            //GRIT CFM 저장
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_1, MWIPLOTSTSX.GRT_CMF_1, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_2, MWIPLOTSTSX.GRT_CMF_2, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_3, MWIPLOTSTSX.GRT_CMF_3, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_4, MWIPLOTSTSX.GRT_CMF_4, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_5, MWIPLOTSTSX.GRT_CMF_5, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_6, MWIPLOTSTSX.GRT_CMF_6, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_7, MWIPLOTSTSX.GRT_CMF_7, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_8, MWIPLOTSTSX.GRT_CMF_8, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_9, MWIPLOTSTSX.GRT_CMF_9, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_10, MWIPLOTSTSX.GRT_CMF_10, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_11, MWIPLOTSTSX.GRT_CMF_11, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_12, MWIPLOTSTSX.GRT_CMF_12, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_13, MWIPLOTSTSX.GRT_CMF_13, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_14, MWIPLOTSTSX.GRT_CMF_14, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_15, MWIPLOTSTSX.GRT_CMF_15, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_16, MWIPLOTSTSX.GRT_CMF_16, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_17, MWIPLOTSTSX.GRT_CMF_17, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_18, MWIPLOTSTSX.GRT_CMF_18, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_19, MWIPLOTSTSX.GRT_CMF_19, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));
            memcpy(MWIPLOTSTSX_SPLIT.GRT_CMF_20, MWIPLOTSTSX.GRT_CMF_20, sizeof(MWIPLOTSTSX_SPLIT.GRT_CMF_1));

            DBU_update_mwiplotstsx(1, &MWIPLOTSTSX_SPLIT);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);
                TRS.add_fieldmsg(out_node, "MWIPLOTSTSX UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTSTSX_SPLIT.LOT_ID), MWIPLOTSTSX_SPLIT.LOT_ID);

                return MP_FALSE;
            }

            DBU_init_mwiplothisx(&MWIPLOTHISX);
            memcpy(MWIPLOTHISX.LOT_ID, MWIPLOTSTSX_SPLIT.LOT_ID, sizeof(MWIPLOTHISX.LOT_ID));
            MWIPLOTHISX.HIST_SEQ = MWIPLOTSTSX_SPLIT.LAST_ACTIVE_HIST_SEQ;

            DBU_select_mwiplothisx(1, &MWIPLOTHISX);
            if (DB_error_code != DB_SUCCESS)
            {
                if (DB_error_code == DB_NOT_FOUND)
                {
                    memcpy(s_msg_code, "WIP-0044", MP_SIZE_MSG);
                }
                else
                {
                    memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                    TRS.add_dberrmsg(out_node, DB_error_msg);
                }

                TRS.add_fieldmsg(out_node, "MWIPLOTHISX SELECT", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTHISX.HIST_SEQ);

                return MP_FALSE;
            }

            memcpy(MWIPLOTHISX.LOT_CMF_1, MWIPLOTSTSX_SPLIT.LOT_CMF_1, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_2, MWIPLOTSTSX_SPLIT.LOT_CMF_2, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_3, MWIPLOTSTSX_SPLIT.LOT_CMF_3, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_4, MWIPLOTSTSX_SPLIT.LOT_CMF_4, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_5, MWIPLOTSTSX_SPLIT.LOT_CMF_5, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_6, MWIPLOTSTSX_SPLIT.LOT_CMF_6, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_7, MWIPLOTSTSX_SPLIT.LOT_CMF_7, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_8, MWIPLOTSTSX_SPLIT.LOT_CMF_8, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_9, MWIPLOTSTSX_SPLIT.LOT_CMF_9, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_10, MWIPLOTSTSX_SPLIT.LOT_CMF_10, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_11, MWIPLOTSTSX_SPLIT.LOT_CMF_11, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_12, MWIPLOTSTSX_SPLIT.LOT_CMF_12, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_13, MWIPLOTSTSX_SPLIT.LOT_CMF_13, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_14, MWIPLOTSTSX_SPLIT.LOT_CMF_14, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_15, MWIPLOTSTSX_SPLIT.LOT_CMF_15, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_16, MWIPLOTSTSX_SPLIT.LOT_CMF_16, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_17, MWIPLOTSTSX_SPLIT.LOT_CMF_17, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_18, MWIPLOTSTSX_SPLIT.LOT_CMF_18, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_19, MWIPLOTSTSX_SPLIT.LOT_CMF_19, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.LOT_CMF_20, MWIPLOTSTSX_SPLIT.LOT_CMF_20, sizeof(MWIPLOTHISX.LOT_CMF_1));
            memcpy(MWIPLOTHISX.ADD_ORDER_ID_1, MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_1, sizeof(MWIPLOTHISX.ADD_ORDER_ID_1));
            memcpy(MWIPLOTHISX.ADD_ORDER_ID_2, MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_2, sizeof(MWIPLOTHISX.ADD_ORDER_ID_2));
            memcpy(MWIPLOTHISX.ADD_ORDER_ID_3, MWIPLOTSTSX_SPLIT.ADD_ORDER_ID_3, sizeof(MWIPLOTHISX.ADD_ORDER_ID_3));
            memcpy(MWIPLOTHISX.RESV_FIELD_1, MWIPLOTSTSX_SPLIT.RESV_FIELD_1, sizeof(MWIPLOTHISX.RESV_FIELD_1));
            memcpy(MWIPLOTHISX.RESV_FIELD_2, MWIPLOTSTSX_SPLIT.RESV_FIELD_2, sizeof(MWIPLOTHISX.RESV_FIELD_2));
            memcpy(MWIPLOTHISX.RESV_FIELD_3, MWIPLOTSTSX_SPLIT.RESV_FIELD_3, sizeof(MWIPLOTHISX.RESV_FIELD_3));
            memcpy(MWIPLOTHISX.RESV_FIELD_4, MWIPLOTSTSX_SPLIT.RESV_FIELD_4, sizeof(MWIPLOTHISX.RESV_FIELD_4));
            memcpy(MWIPLOTHISX.RESV_FIELD_5, MWIPLOTSTSX_SPLIT.RESV_FIELD_5, sizeof(MWIPLOTHISX.RESV_FIELD_5));
            MWIPLOTHISX.RESV_FLAG_1 = MWIPLOTSTSX_SPLIT.RESV_FLAG_1;
            MWIPLOTHISX.RESV_FLAG_2 = MWIPLOTSTSX_SPLIT.RESV_FLAG_2;
            MWIPLOTHISX.RESV_FLAG_3 = MWIPLOTSTSX_SPLIT.RESV_FLAG_3;
            MWIPLOTHISX.RESV_FLAG_4 = MWIPLOTSTSX_SPLIT.RESV_FLAG_4;
            MWIPLOTHISX.RESV_FLAG_5 = MWIPLOTSTSX_SPLIT.RESV_FLAG_5;

            //CTM CFM 저장
            memcpy(MWIPLOTHISX.CTM_CMF_1, MWIPLOTSTSX_SPLIT.CTM_CMF_1, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_2, MWIPLOTSTSX_SPLIT.CTM_CMF_2, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_3, MWIPLOTSTSX_SPLIT.CTM_CMF_3, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_4, MWIPLOTSTSX_SPLIT.CTM_CMF_4, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_5, MWIPLOTSTSX_SPLIT.CTM_CMF_5, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_6, MWIPLOTSTSX_SPLIT.CTM_CMF_6, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_7, MWIPLOTSTSX_SPLIT.CTM_CMF_7, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_8, MWIPLOTSTSX_SPLIT.CTM_CMF_8, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_9, MWIPLOTSTSX_SPLIT.CTM_CMF_9, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_10, MWIPLOTSTSX_SPLIT.CTM_CMF_10, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_11, MWIPLOTSTSX_SPLIT.CTM_CMF_11, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_12, MWIPLOTSTSX_SPLIT.CTM_CMF_12, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_13, MWIPLOTSTSX_SPLIT.CTM_CMF_13, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_14, MWIPLOTSTSX_SPLIT.CTM_CMF_14, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_15, MWIPLOTSTSX_SPLIT.CTM_CMF_15, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_16, MWIPLOTSTSX_SPLIT.CTM_CMF_16, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_17, MWIPLOTSTSX_SPLIT.CTM_CMF_17, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_18, MWIPLOTSTSX_SPLIT.CTM_CMF_18, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_19, MWIPLOTSTSX_SPLIT.CTM_CMF_19, sizeof(MWIPLOTHISX.CTM_CMF_1));
            memcpy(MWIPLOTHISX.CTM_CMF_20, MWIPLOTSTSX_SPLIT.CTM_CMF_20, sizeof(MWIPLOTHISX.CTM_CMF_1));
            //PDC CFM 저장
            memcpy(MWIPLOTHISX.PDC_CMF_1, MWIPLOTSTSX_SPLIT.PDC_CMF_1, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_2, MWIPLOTSTSX_SPLIT.PDC_CMF_2, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_3, MWIPLOTSTSX_SPLIT.PDC_CMF_3, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_4, MWIPLOTSTSX_SPLIT.PDC_CMF_4, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_5, MWIPLOTSTSX_SPLIT.PDC_CMF_5, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_6, MWIPLOTSTSX_SPLIT.PDC_CMF_6, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_7, MWIPLOTSTSX_SPLIT.PDC_CMF_7, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_8, MWIPLOTSTSX_SPLIT.PDC_CMF_8, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_9, MWIPLOTSTSX_SPLIT.PDC_CMF_9, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_10, MWIPLOTSTSX_SPLIT.PDC_CMF_10, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_11, MWIPLOTSTSX_SPLIT.PDC_CMF_11, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_12, MWIPLOTSTSX_SPLIT.PDC_CMF_12, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_13, MWIPLOTSTSX_SPLIT.PDC_CMF_13, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_14, MWIPLOTSTSX_SPLIT.PDC_CMF_14, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_15, MWIPLOTSTSX_SPLIT.PDC_CMF_15, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_16, MWIPLOTSTSX_SPLIT.PDC_CMF_16, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_17, MWIPLOTSTSX_SPLIT.PDC_CMF_17, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_18, MWIPLOTSTSX_SPLIT.PDC_CMF_18, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_19, MWIPLOTSTSX_SPLIT.PDC_CMF_19, sizeof(MWIPLOTHISX.PDC_CMF_1));
            memcpy(MWIPLOTHISX.PDC_CMF_20, MWIPLOTSTSX_SPLIT.PDC_CMF_20, sizeof(MWIPLOTHISX.PDC_CMF_1));
            //HM CFM 저장
            memcpy(MWIPLOTHISX.HM_CMF_1, MWIPLOTSTSX_SPLIT.HM_CMF_1, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_2, MWIPLOTSTSX_SPLIT.HM_CMF_2, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_3, MWIPLOTSTSX_SPLIT.HM_CMF_3, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_4, MWIPLOTSTSX_SPLIT.HM_CMF_4, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_5, MWIPLOTSTSX_SPLIT.HM_CMF_5, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_6, MWIPLOTSTSX_SPLIT.HM_CMF_6, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_7, MWIPLOTSTSX_SPLIT.HM_CMF_7, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_8, MWIPLOTSTSX_SPLIT.HM_CMF_8, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_9, MWIPLOTSTSX_SPLIT.HM_CMF_9, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_10, MWIPLOTSTSX_SPLIT.HM_CMF_10, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_11, MWIPLOTSTSX_SPLIT.HM_CMF_11, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_12, MWIPLOTSTSX_SPLIT.HM_CMF_12, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_13, MWIPLOTSTSX_SPLIT.HM_CMF_13, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_14, MWIPLOTSTSX_SPLIT.HM_CMF_14, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_15, MWIPLOTSTSX_SPLIT.HM_CMF_15, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_16, MWIPLOTSTSX_SPLIT.HM_CMF_16, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_17, MWIPLOTSTSX_SPLIT.HM_CMF_17, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_18, MWIPLOTSTSX_SPLIT.HM_CMF_18, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_19, MWIPLOTSTSX_SPLIT.HM_CMF_19, sizeof(MWIPLOTHISX.HM_CMF_1));
            memcpy(MWIPLOTHISX.HM_CMF_20, MWIPLOTSTSX_SPLIT.HM_CMF_20, sizeof(MWIPLOTHISX.HM_CMF_1));
            //GRIT CFM 저장
            memcpy(MWIPLOTHISX.GRT_CMF_1, MWIPLOTSTSX_SPLIT.GRT_CMF_1, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_2, MWIPLOTSTSX_SPLIT.GRT_CMF_2, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_3, MWIPLOTSTSX_SPLIT.GRT_CMF_3, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_4, MWIPLOTSTSX_SPLIT.GRT_CMF_4, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_5, MWIPLOTSTSX_SPLIT.GRT_CMF_5, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_6, MWIPLOTSTSX_SPLIT.GRT_CMF_6, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_7, MWIPLOTSTSX_SPLIT.GRT_CMF_7, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_8, MWIPLOTSTSX_SPLIT.GRT_CMF_8, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_9, MWIPLOTSTSX_SPLIT.GRT_CMF_9, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_10, MWIPLOTSTSX_SPLIT.GRT_CMF_10, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_11, MWIPLOTSTSX_SPLIT.GRT_CMF_11, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_12, MWIPLOTSTSX_SPLIT.GRT_CMF_12, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_13, MWIPLOTSTSX_SPLIT.GRT_CMF_13, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_14, MWIPLOTSTSX_SPLIT.GRT_CMF_14, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_15, MWIPLOTSTSX_SPLIT.GRT_CMF_15, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_16, MWIPLOTSTSX_SPLIT.GRT_CMF_16, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_17, MWIPLOTSTSX_SPLIT.GRT_CMF_17, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_18, MWIPLOTSTSX_SPLIT.GRT_CMF_18, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_19, MWIPLOTSTSX_SPLIT.GRT_CMF_19, sizeof(MWIPLOTHISX.GRT_CMF_1));
            memcpy(MWIPLOTHISX.GRT_CMF_20, MWIPLOTSTSX_SPLIT.GRT_CMF_20, sizeof(MWIPLOTHISX.GRT_CMF_1));

            DBU_update_mwiplothisx(1, &MWIPLOTHISX);
            if (DB_error_code != DB_SUCCESS)
            {
                memcpy(s_msg_code, "WIP-0004", MP_SIZE_MSG);
                TRS.add_dberrmsg(out_node, DB_error_msg);

                TRS.add_fieldmsg(out_node, "MWIPLOTHISX UPDATE", MP_NVST);
                TRS.add_fieldmsg(out_node, "LOT_ID", MP_STR, sizeof(MWIPLOTHISX.LOT_ID), MWIPLOTHISX.LOT_ID);
                TRS.add_fieldmsg(out_node, "HIST_SEQ", MP_INT, MWIPLOTHISX.HIST_SEQ);

                return MP_FALSE;
            }
        }
    }

    return MP_TRUE;
}

/*******************************************************************************
Update_Eltsts()
- LOT 추가 항목을 MWIPELTSTS에 INSERT, UPDATE 한다.
Return Value
- int : MP_TRUE(1) or MP_FALSE(0)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int Update_Eltsts(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
	struct MWIPLOTSTS_TAG MWIPLOTSTS;
	struct MWIPLOTHIS_TAG MWIPLOTHIS;
	struct MGCMTBLDAT_TAG MGCMTBLDAT;

	TRSNode *EXTLOTSTS;
	int iMemCount;
    char s_sys_time[15];

    LOG_head("Update_Eltsts");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	DBC_init_mwiplotsts(&MWIPLOTSTS);
	TRS.copy(MWIPLOTSTS.FACTORY, sizeof(MWIPLOTSTS.FACTORY), in_node, IN_FACTORY);
	TRS.copy(MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID), in_node, "LOT_ID");
	DBC_select_mwiplotsts(1, &MWIPLOTSTS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_dberrmsg(out_node, DB_error_msg);

		TRS.add_fieldmsg(out_node, "MWIPLOTSTS SELECT ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTSTS.LOT_ID), MWIPLOTSTS.LOT_ID);

		return MP_FALSE;
	}

	DBC_init_mwiplothis(&MWIPLOTHIS);
	memcpy(MWIPLOTHIS.LOT_ID, MWIPLOTSTS.LOT_ID, sizeof(MWIPLOTSTS.LOT_ID));
	MWIPLOTHIS.HIST_SEQ = MWIPLOTSTS.LAST_ACTIVE_HIST_SEQ;
	DBC_select_mwiplothis(1, &MWIPLOTHIS);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "WIP-0004");
		TRS.add_dberrmsg(out_node, DB_error_msg);

		TRS.add_fieldmsg(out_node, "MWIPLOTHIS SELECT ", DT_NOVALUESTRING);
		TRS.add_fieldmsg(out_node, "LOT_ID", DT_STRING, sizeof(MWIPLOTHIS.LOT_ID), MWIPLOTHIS.LOT_ID);

		return MP_FALSE;
	}

	EXTLOTSTS = TRS.add_node(in_node, "elt_in");

	iMemCount = in_node->MemberCount;

    memset(s_sys_time, 0x00, sizeof(s_sys_time));
    memcpy(s_sys_time, gs_sys_time, sizeof(gs_sys_time));

	for (int i = 0; i < iMemCount; i++)
	{
		if (memcmp(in_node->Members[i]->Name, "LOT_ID", strlen("LOT_ID")) == MP_FALSE)
			continue;

		DBC_init_mgcmtbldat(&MGCMTBLDAT);
		memcpy(MGCMTBLDAT.FACTORY, CENTRAL_FACTORY, strlen(CENTRAL_FACTORY));
		memcpy(MGCMTBLDAT.TABLE_NAME, MP_LOT_EXT_GCM_TBL, strlen(MP_LOT_EXT_GCM_TBL));
		memcpy(MGCMTBLDAT.KEY_2, in_node->Members[i]->Name, strlen(in_node->Members[i]->Name));

		DBC_select_mgcmtbldat(3, &MGCMTBLDAT);
		if (DB_error_code == DB_SUCCESS)
		{
			if (MGCMTBLDAT.DATA_2[0] == 'C')
			{
				TRS.set_char(EXTLOTSTS, in_node->Members[i]->Name, in_node->Members[i]->Value.c);
			}
			else if (MGCMTBLDAT.DATA_2[0] == 'V')
			{
				TRS.set_nstring(EXTLOTSTS, in_node->Members[i]->Name, in_node->Members[i]->Value.s);
			}
			else if (MGCMTBLDAT.DATA_2[0] == 'N')
			{
				if (COM_search_string(MGCMTBLDAT.DATA_3, sizeof(MGCMTBLDAT.DATA_3), ",", 1) > 0)
				{
					TRS.set_double(EXTLOTSTS, in_node->Members[i]->Name, in_node->Members[i]->Value.f8);
				}
				else
				{
					TRS.set_int(EXTLOTSTS, in_node->Members[i]->Name, in_node->Members[i]->Value.i4);
				}
			}
		}
	}

	if (WIP_UPDATE_LOTEX2(s_msg_code, out_node, MWIPLOTSTS.LOT_ID, EXTLOTSTS, 'N') == MP_FALSE)
	{
		return MP_FALSE;
	}

    LOG_head("Update_Eltsts_End");
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

	return MP_TRUE;
}


/*******************************************************************************
    Save_Log_in_node()
        - in_node를 xml 형태로 Log에 저장
    Return Value
        - int : MP_TRUE(1) or MP_FALSE(0)
    Arguments
        - TRSNode *in_node : Input Message structure
*******************************************************************************/
void Save_Log_in_node(TRSNode *in_node)
{
    char msg_string[MP_MAX_MSG_LENGTH];
    char s_xml[1001];
    int i_length = 0;
    int i = 0;

    TRS.to_xml_string(msg_string, in_node);

    i_length = (int)strlen(msg_string);

    for (i = 0; i < i_length; i += 1000)
    {
        memset(s_xml, 0x00, sizeof(s_xml));
        if (i + 1000 > i_length)
        {
            memcpy(s_xml, msg_string + i, i_length - i);
        }
        else
        {
            memcpy(s_xml, msg_string + i, 1000);
        }

        LOG_head("In Node XML");
        LOG_add("XML", MP_NSTR, s_xml);
        COM_log_write(MP_LOG_ERROR, MP_LOG_E_LOGIC, MP_LOG_CATE_SYSTEM);
    }
}
