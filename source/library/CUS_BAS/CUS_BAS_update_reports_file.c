/******************************************************************************'

System      : MESplus
Module      : CUS_BAS
File Name   : CUS_BAS_update_reports_file.c
Description : Update Reports_file function module

MES Version : 5.3.4

Function List
- CUS_BAS_Update_Reports_File()
+ View Caption definition
- CUS_BAS_UPDATE_REPORTS_FILE()
+ Main sub function of CUS_BAS_Update_Reports_File function
+ View Caption definition
Detail Description
- CUS_BAS_UPDATE_REPORTS_FILE()
+ h_proc_step
+ 1 : View Caption definition  by Primary Key
History
Seq   Date        Developer      Description
---------------------------------------------------------------------------
1     2020/10/15                 Create by WGLEE

Copyright(C) 1998-2020 Miracom,Inc.
All rights reserved.

******************************************************************************/

#if defined(_HPUX_SOURCE)

#include <dirent.h>

#elif defined(__digital__) || defined(_AIX)

#include <dirent.h>

#elif defined(WIN32) || defined(WIN64)

#include <direct.h>

#endif

#include "CUS_common.h"
#include "CUS_defines.h"

int CUS_BAS_UPDATE_REPORTS_FILE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
int CUS_BAS_Update_Reports_File_Validation(char *s_msg_code,TRSNode *in_node,TRSNode *out_node);

int CUS_BAS_get_Report_file(char *s_msg_code,
    TRSNode *out_node,
    char *s_file_name_t, char *s_create_time_t, int i_file_size_t,
    char *s_put_member_name,char c_add_fieldmsg);

char gs_cus_rpt_dir[256];

/*******************************************************************************
CUS_BAS_Update_Reports_File()
- View Caption definition
Return Value
- int : 0 (MP_TRUE)
Arguments
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Reports_File(TRSNode *in_node, TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_UPDATE_REPORTS_FILE(s_msg_code, in_node, out_node);

    if (i_ret == MP_TRUE)
        COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    else
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));

    COM_out_msg_log_write(s_msg_code, "CUS_BAS_Update_Reports_File", out_node);

    if (i_ret == MP_TRUE)
    {
        DB_commit();
    }
    else
    {
        DB_rollback();
    }

    return MP_TRUE;
}
/*******************************************************************************
CUS_BAS_UPDATE_REPORTS_FILE()
- Main sub function of "CUS_BAS_Update_Reports_File" function
- View Caption definition
Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_REPORTS_FILE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node)
{
    char s_file_name_t[200];
    char s_create_time_t[14];
    long i_file_size_t = 0;

    // LOG
    LOG_head("CUS_BAS_Update_Reports_File");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_VIEW);

    memset(s_file_name_t, ' ', sizeof(s_file_name_t));
    memset(s_create_time_t, ' ', sizeof(s_create_time_t));

    // VALIDATION CHECK
    if (CUS_BAS_Update_Reports_File_Validation(s_msg_code, in_node, out_node) == MP_FALSE)
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (TRS.get_procstep(in_node) == 'D')
    {
        TRS.copy(s_file_name_t, sizeof(s_file_name_t), in_node, "FILE_NAME");
        TRS.copy(s_create_time_t, sizeof(s_create_time_t), in_node, "CREATION_TIME");
        i_file_size_t = (long)TRS.get_int(in_node, "FILE_SIZE");

        /* Down file */
        if (CUS_BAS_get_Report_file(s_msg_code, out_node, s_file_name_t, s_create_time_t, i_file_size_t, MP_BIN_DATA_3, 'Y') == MP_FALSE)
        {
            COM_set_result(out_node, MP_SUCCESS_C, s_msg_code, MP_MSG_CATE_WARN, TRS.get_language(in_node));
        }
    }

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE;
}



/*******************************************************************************
CUS_BAS_Update_Reports_File_Validation()
- Main sub function of "CUS_BAS_UPDATE_REPORTS_FILE" function
- Check the condition for create/update/delete Caption & vbCrLf    Return Value
- int : 1 (MP_TRUE) or 0 (MP_FALSE)
Arguments
- char *s_msg_code : Error Message Code
- TRSNode *in_node : Input Message structure
- TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Reports_File_Validation(char *s_msg_code, TRSNode *in_node,TRSNode *out_node)
{
    /* ProcStep Validation */
    if (COM_service_validation(s_msg_code,
        in_node,
        out_node,
        TRS.get_procstep(in_node),
        "D") == MP_FALSE)
    {
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "FILE_NAME")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CMN-0001");
        TRS.add_fieldmsg(out_node, "FILE_NAME", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    if (COM_isnullspace(TRS.get_string(in_node, "CREATION_TIME")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CMN-0001");
        TRS.add_fieldmsg(out_node, "CREATION_TIME", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    return MP_TRUE;
}

int CUS_BAS_get_Report_file(char *s_msg_code, TRSNode *out_node, char *s_file_name_t, char *s_create_time_t, int i_file_size_t,
    char *s_put_member_name, char c_add_fieldmsg)
{
    struct stat     status;             // file information structure
    int             i_status;           // file handling variable
    char            s_file_path[1000];
    FILE            *fp;
    unsigned char   *blob_buffer;
    char            s_file_name[200];
    char            s_temp_dir[256];
    char            s_create_time[14];
    char            s_cmp_create_time[14];
    long            i_file_size = 0;

    //s_temp_dir 초기화 후 report파일이 있는 위치를 s_temp_dir에 담아준다.
    memset(s_temp_dir, 0x00, sizeof(s_temp_dir));
    memcpy(s_temp_dir, gs_cus_rpt_dir, strlen(gs_cus_rpt_dir));
    
    //파라미터로 받은 파일명을 s_file_name에 담는다.
    memset(s_file_name, 0x00, sizeof(s_file_name));
    COM_memcpy_add_null(s_file_name, s_file_name_t, sizeof(s_file_name));

    //이전 파일 사이즈
    memset(s_cmp_create_time, 0x00, sizeof(s_cmp_create_time));
    COM_memcpy_add_null(s_cmp_create_time, s_create_time_t, sizeof(s_cmp_create_time));

    i_file_size = i_file_size_t;

    if (strlen(s_file_name) < 1) 
        return MP_TRUE;

    //파일 경로 => 파일의 확장자까지 포함.
    memset(s_file_path, 0x00, sizeof(s_file_path));

#if defined(WIN32) || defined(WIN64)
    sprintf(s_file_path, "%s\\%s", s_temp_dir, s_file_name);
#else
    sprintf(s_file_path, "%s/%s", s_temp_dir, s_file_name);
#endif

    fp = fopen(s_file_path, "rb");
    if (fp == 0x00)
    {
        strcpy(s_msg_code, "ALM-0043");

        if (c_add_fieldmsg == 'Y')
        {
            TRS.add_fieldmsg(out_node, "Attached File Name", MP_NSTR, s_file_name);
        }

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;
        return MP_FALSE;
    }

    //파일 상태값 가져오기
#if defined(WIN32) || defined(WIN64)
    i_status = fstat(_fileno(fp), &status);
#else
    i_status = fstat(fileno(fp), &status);
#endif

    if (i_status == -1)
    {
        strcpy(s_msg_code, "ALM-0043");

        if (c_add_fieldmsg == 'Y')
        {
            TRS.add_fieldmsg(out_node, "Attached File Name", MP_NSTR, s_file_name);
        }

        fclose(fp);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;
        return MP_FALSE;
    }

    COM_date_time_to_char(status.st_ctime, s_create_time);

    //파일의 생성 날짜와 크기가 같은 경우 다운받지 않아도 된다.
    if (memcmp(s_create_time, s_cmp_create_time, sizeof(s_create_time)) == MP_FALSE &&
        i_file_size == status.st_size)
    {
        TRS.add_char(out_node, "UPDATE_YN", 'N');
        fclose(fp);

        return MP_TRUE;
    }

    blob_buffer = (unsigned char*)COM_malloc(status.st_size, "COMCus_get_attached_file", s_file_name);
    fread(blob_buffer, status.st_size, 1, fp);

    TRS.add_string(out_node, "D_CREATION_TIME", s_create_time, sizeof(s_create_time));
    TRS.set_blob(out_node, s_put_member_name, blob_buffer, status.st_size);

    fclose(fp);
    COM_free(blob_buffer);

    TRS.add_char(out_node, "UPDATE_YN", 'Y');

    return MP_TRUE;
}