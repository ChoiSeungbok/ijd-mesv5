/******************************************************************************'

    System      : MESplus
    Module      : CUS_BAS
    File Name   : COMCus_update_caption.c
    Description : Caption Setup function module

    MES Version : 5.3.4

    Function List
        - CUS_BAS_Update_Caption()
            + Create/Update/Delete Caption definition
        - CUS_BAS_UPDATE_CAPTION()
            + Main sub function of CUS_BAS_Update_Caption function
            + Create/Update/Delete Caption definition
        - CUS_BAS_Update_Caption_Validation()
            + Main sub function of CUS_BAS_UPDATE_CAPTION function
            + Check the condition for create/update/delete Caption
    Detail Description
        - CUS_BAS_UPDATE_CAPTION()
            + h_proc_step
                + MP_STEP_CREATE : Create Caption definition
                + MP_STEP_UPDATE : Update Caption definition
                + MP_STEP_DELETE : Delete Caption definition

    History
    Seq   Date        Developer      Description
    ---------------------------------------------------------------------------
    1     2016/01/01                 Create by Generator

    Copyright(C) 1998-2016 Miracom,Inc.
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

int CUS_BAS_UPDATE_CAPTION(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

int CUS_BAS_Update_Caption_Validation(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

int CUS_BAS_get_doc_file(char *s_msg_code,
    TRSNode *out_node,
    char *s_file_name_t,
    char *s_doc_type,
    char *s_put_member_name,
    char c_add_fieldmsg);

char gs_cus_cpt_dir[256];

/*******************************************************************************
    COMCus_Update_Caption()
        - Create/Update/Delete Caption definition
    Return Value
        - int : 0 (MP_TRUE)
    Arguments
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Caption(TRSNode *in_node,
                        TRSNode *out_node)
{
    char s_msg_code[MP_SIZE_MSG];
    int i_ret;

    memset(s_msg_code, 0x00, MP_SIZE_MSG);

    i_ret = CUS_BAS_UPDATE_CAPTION(s_msg_code, in_node, out_node);

    COM_out_msg_log_write(s_msg_code,"CUS_BAS_UPDATE_CAPTION", out_node);

    if(i_ret == MP_TRUE)
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
    CUS_BAS_UPDATE_CAPTION()
        - Main sub function of "CUS_BAS_Update_Caption" function
        - Create/Update/Delete Caption definition
    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE) 
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure 
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_UPDATE_CAPTION(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node)
{ 
    struct CBASCPTDEF_TAG CBASCPTDEF;

	int i;
	unsigned char  *in_data;
    long            blob_size;
    FILE           *blob_file;
    //char            s_cur_time[20];
    char            s_file[200];
    char            s_file_path[1000];
    char            s_temp_dir[256];
	
	//char            s_file_name[20];

    LOG_head("CUS_BAS_Update_Caption");
    TRS.log_add_all_members(in_node);
    COM_log_write(MP_LOG_INFORMATION, MP_LOG_E_LOGIC, MP_LOG_CATE_SETUP);

    if(CUS_BAS_Update_Caption_Validation(s_msg_code, in_node, out_node) == MP_FALSE) 
    {
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cbascptdef(&CBASCPTDEF);

    TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), in_node, "CAPTION_TYPE");
    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "CAPTION_KEY");
    DBU_select_cbascptdef(1, &CBASCPTDEF);
    TRS.copy(CBASCPTDEF.CAPTION_MSG_1, sizeof(CBASCPTDEF.CAPTION_MSG_1), in_node, "CAPTION_MSG_1");
    TRS.copy(CBASCPTDEF.CAPTION_MSG_2, sizeof(CBASCPTDEF.CAPTION_MSG_2), in_node, "CAPTION_MSG_2");
    TRS.copy(CBASCPTDEF.CAPTION_MSG_3, sizeof(CBASCPTDEF.CAPTION_MSG_3), in_node, "CAPTION_MSG_3");
    TRS.copy(CBASCPTDEF.CAPTION_MSG_4, sizeof(CBASCPTDEF.CAPTION_MSG_4), in_node, "CAPTION_MSG_4");
    TRS.copy(CBASCPTDEF.CAPTION_MSG_5, sizeof(CBASCPTDEF.CAPTION_MSG_5), in_node, "CAPTION_MSG_5");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_1, sizeof(CBASCPTDEF.CAPTION_CMF_1), in_node, "CAPTION_CMF_1");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_2, sizeof(CBASCPTDEF.CAPTION_CMF_2), in_node, "CAPTION_CMF_2");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_3, sizeof(CBASCPTDEF.CAPTION_CMF_3), in_node, "CAPTION_CMF_3");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_4, sizeof(CBASCPTDEF.CAPTION_CMF_4), in_node, "CAPTION_CMF_4");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_5, sizeof(CBASCPTDEF.CAPTION_CMF_5), in_node, "CAPTION_CMF_5");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_6, sizeof(CBASCPTDEF.CAPTION_CMF_6), in_node, "CAPTION_CMF_6");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_7, sizeof(CBASCPTDEF.CAPTION_CMF_7), in_node, "CAPTION_CMF_7");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_8, sizeof(CBASCPTDEF.CAPTION_CMF_8), in_node, "CAPTION_CMF_8");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_9, sizeof(CBASCPTDEF.CAPTION_CMF_9), in_node, "CAPTION_CMF_9");
    TRS.copy(CBASCPTDEF.CAPTION_CMF_10, sizeof(CBASCPTDEF.CAPTION_CMF_10), in_node, "CAPTION_CMF_10");
    TRS.copy(CBASCPTDEF.CREATE_USER_ID, sizeof(CBASCPTDEF.CREATE_USER_ID), in_node, "CREATE_USER_ID");
    TRS.copy(CBASCPTDEF.CREATE_TIME, sizeof(CBASCPTDEF.CREATE_TIME), in_node, "CREATE_TIME");
    TRS.copy(CBASCPTDEF.UPDATE_USER_ID, sizeof(CBASCPTDEF.UPDATE_USER_ID), in_node, "UPDATE_USER_ID");
    TRS.copy(CBASCPTDEF.UPDATE_TIME, sizeof(CBASCPTDEF.UPDATE_TIME), in_node, "UPDATE_TIME");

    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        TRS.copy(CBASCPTDEF.CREATE_USER_ID, sizeof(CBASCPTDEF.CREATE_USER_ID), in_node, IN_USERID);
        DB_get_systime(CBASCPTDEF.CREATE_TIME);

        DBU_insert_cbascptdef(&CBASCPTDEF); 
        if(DB_error_code != DB_SUCCESS)
        { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF INSERT", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
            return MP_FALSE; 
        } 
    }
    else if(TRS.get_procstep(in_node) == MP_STEP_UPDATE)
    {
        TRS.copy(CBASCPTDEF.UPDATE_USER_ID, sizeof(CBASCPTDEF.UPDATE_USER_ID), in_node, IN_USERID);
        DB_get_systime(CBASCPTDEF.UPDATE_TIME);

        DBU_update_cbascptdef(1, &CBASCPTDEF);
        if(DB_error_code != DB_SUCCESS)
        { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF UPDATE", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
            return MP_FALSE; 
        } 
    }
    else if(TRS.get_procstep(in_node) == MP_STEP_DELETE)
    {
        DBU_delete_cbascptdef(1, &CBASCPTDEF);
        if(DB_error_code != DB_SUCCESS)
        { 
            strcpy(s_msg_code, "CMN-0004"); 
            TRS.add_fieldmsg(out_node, "CBASCPTDEF DELETE", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
            TRS.add_dberrmsg(out_node, DB_error_msg);

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
            return MP_FALSE; 
        } 
    }
	else if(TRS.get_procstep(in_node) == 'F')
	{	    
        memset(s_temp_dir, 0x00, sizeof(s_temp_dir));
		memcpy(s_temp_dir, gs_cus_cpt_dir, strlen(gs_cus_cpt_dir));        

        //s_cur_time[17] = 0x00;                

        if (COM_isnullspace(TRS.get_string(in_node, "FILE_NAME")) == MP_FALSE)
        {
            memset(s_file, ' ', sizeof(s_file));
            TRS.copy(s_file, sizeof(s_file), in_node, "FILE_NAME");
            COM_add_null(s_file, sizeof(s_file));
         

            /* for doc data */
            in_data = 0x00;
            blob_size = 0;
            TRS.get_blob(in_node, MP_BIN_DATA_1, &in_data, &blob_size);

            if(in_data != 0x00 && blob_size > 0)
            {
                memset(s_file_path, 0x00, sizeof(s_file_path));
				#if defined(WIN32) || defined(WIN64)
                sprintf(s_file_path, "%s\\%s", s_temp_dir, s_file);
				#else
                sprintf(s_file_path, "%s/%s", s_temp_dir, s_file);
				#endif

                i = _chdir(s_temp_dir);
                if (i < 0)
                {
					#if defined(WIN32) || defined(WIN64)
                    i = _mkdir(s_temp_dir);
					#else
                    i = _mkdir(s_temp_dir, 0755);
					#endif
                    if (i < 0)
                    {
                        strcpy(s_msg_code, "ALM-0041");
                        TRS.add_fieldmsg(out_node, "MESplusCusCaptionDir", MP_NSTR, s_temp_dir);

                        gs_log_type.type = MP_LOG_ERROR;
                        gs_log_type.e_type = MP_LOG_E_SYSTEM;
                        gs_log_type.category = MP_LOG_CATE_SETUP;
                        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
                        return MP_FALSE;
                    }
                }

                blob_file = fopen(s_file_path, "wb");
                if(blob_file != 0x00)
                {
                    fwrite(in_data, sizeof(unsigned char), blob_size, blob_file);
                    fclose(blob_file);                    
                }
            }
        }
	}
	else if(TRS.get_procstep(in_node) == 'L')
	{	    			
		/* for MESMessage file */
        if(CUS_BAS_get_doc_file(s_msg_code, out_node, MP_CAPTION_FILE_MESSAGE, "C", MP_BIN_DATA_1, 'Y') == MP_FALSE)
        {
            COM_set_result(out_node, MP_SUCCESS_C, s_msg_code, MP_MSG_CATE_WARN, TRS.get_language(in_node));                
        }

		/* for MESCaption file */
		if(CUS_BAS_get_doc_file(s_msg_code, out_node, MP_CAPTION_FILE_CAPTION, "C", MP_BIN_DATA_2, 'Y') == MP_FALSE)
        {
            COM_set_result(out_node, MP_SUCCESS_C, s_msg_code, MP_MSG_CATE_WARN, TRS.get_language(in_node));                
        }
	}

    COM_set_result(out_node, MP_SUCCESS_C, "CMN-0000", MP_MSG_CATE_SUCCESS, TRS.get_language(in_node));
    return MP_TRUE; 
} 

/*******************************************************************************
    CUS_BAS_Update_Caption_Validation()
        - Main sub function of "CUS_BAS_UPDATE_CAPTION" function
        - Check the condition for create/update/delete Caption & vbCrLf    Return Value
        - int : 1 (MP_TRUE) or 0 (MP_FALSE)
    Arguments
        - char *s_msg_code : Error Message Code 
        - TRSNode *in_node : Input Message structure
        - TRSNode *out_node : Output Message structure
*******************************************************************************/
int CUS_BAS_Update_Caption_Validation(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node)
{
    struct CBASCPTDEF_TAG CBASCPTDEF;


    /* ProcStep Validation */
    if(COM_service_validation(s_msg_code,
                            in_node,
                            out_node,
                            TRS.get_procstep(in_node),
                            "IUDFL") == MP_FALSE)
    {
        return MP_FALSE;
    }

	//파일 업로드 유효성 체크 하지 않음
	if(TRS.get_procstep(in_node) == 'F' ||
		TRS.get_procstep(in_node) == 'L')
	{
		return MP_TRUE;
	}

    /* Caption_type Validation */
    if(COM_isnullspace(TRS.get_string(in_node, "CAPTION_TYPE")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CMN-0001");
        TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    /* Caption_key Validation */
    if(COM_isnullspace(TRS.get_string(in_node, "CAPTION_KEY")) == MP_TRUE)
    {
        strcpy(s_msg_code, "CMN-0001");
        TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_NVST);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_VALIDATION;
        gs_log_type.category = MP_LOG_CATE_SETUP;
        COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node));
        return MP_FALSE;
    }

    DBU_init_cbascptdef(&CBASCPTDEF);
    TRS.copy(CBASCPTDEF.CAPTION_TYPE, sizeof(CBASCPTDEF.CAPTION_TYPE), in_node, "CAPTION_TYPE");
    TRS.copy(CBASCPTDEF.CAPTION_KEY, sizeof(CBASCPTDEF.CAPTION_KEY), in_node, "CAPTION_KEY");
    DBU_select_cbascptdef(1, &CBASCPTDEF); 
    if(TRS.get_procstep(in_node) == MP_STEP_CREATE)
    {
        if(DB_error_code == DB_SUCCESS)
        { 
            strcpy(s_msg_code, "CMN-0006"); //캡션 정보가 이미 존재합니다.
            TRS.add_fieldmsg(out_node, "CBASCPTDEF SELECT", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.e_type = MP_LOG_E_SYSTEM;
            gs_log_type.category = MP_LOG_CATE_SETUP;

            COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
            return MP_FALSE; 
        }
        else
        {
            if (DB_error_code != DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0004"); 
                TRS.add_fieldmsg(out_node, "CBASCPTDEF SELECT", MP_NVST); 
                TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
                TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.type = MP_LOG_ERROR;
                gs_log_type.e_type = MP_LOG_E_SYSTEM;
                gs_log_type.category = MP_LOG_CATE_SETUP;

                COM_set_result(out_node, MP_FAIL_C, s_msg_code, MP_MSG_CATE_ERROR, TRS.get_language(in_node)); 
                return MP_FALSE; 
            }
        }
    }
    else if(TRS.get_procstep(in_node) == MP_STEP_UPDATE ||
            TRS.get_procstep(in_node) == MP_STEP_DELETE) 
    {
        if(DB_error_code != DB_SUCCESS)
        {
            if(DB_error_code == DB_NOT_FOUND)
            {
                strcpy(s_msg_code, "CMN-0005"); //캡션이 존재하지 않습니다.
                gs_log_type.e_type = MP_LOG_E_EXISTENCE;
            }
            else
            {
                strcpy(s_msg_code, "CMN-0004"); 
                TRS.add_dberrmsg(out_node, DB_error_msg);

                gs_log_type.e_type = MP_LOG_E_SYSTEM;
            }

            TRS.add_fieldmsg(out_node, "CBASCPTDEF SELECT", MP_NVST); 
            TRS.add_fieldmsg(out_node, "CAPTION_TYPE", MP_STR, sizeof(CBASCPTDEF.CAPTION_TYPE), CBASCPTDEF.CAPTION_TYPE); 
            TRS.add_fieldmsg(out_node, "CAPTION_KEY", MP_STR, sizeof(CBASCPTDEF.CAPTION_KEY), CBASCPTDEF.CAPTION_KEY); 

            gs_log_type.type = MP_LOG_ERROR;
            gs_log_type.category = MP_LOG_CATE_SETUP;
            return MP_FALSE;
        }
    }
    return MP_TRUE;
}


int CUS_BAS_get_doc_file(char *s_msg_code,
                          TRSNode *out_node,
                          char *s_file_name_t,
                          char *s_doc_type,
                          char *s_put_member_name,
                          char c_add_fieldmsg)
{
    struct stat     status;             // file information structure
    int             i_status;           // file handling variable
    char            s_file_path[1000];
    FILE            *fp;
    unsigned char   *blob_buffer;
    char            s_file_name[200];
    char            s_temp_dir[256];

    memset(s_temp_dir, 0x00, sizeof(s_temp_dir));

	memcpy(s_temp_dir, gs_cus_cpt_dir, strlen(gs_cus_cpt_dir));    

    memset(s_file_name, 0x00, sizeof(s_file_name));
    COM_memcpy_add_null(s_file_name, s_file_name_t, sizeof(s_file_name));

    if(strlen(s_file_name) < 1) return MP_TRUE;

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

        if(c_add_fieldmsg == 'Y')
        {
            TRS.add_fieldmsg(out_node, "Attached File Name", MP_NSTR, s_file_name);
        }

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;
        return MP_FALSE;
    }

#if defined(WIN32) || defined(WIN64)
    i_status = fstat(_fileno(fp), &status);
#else
    i_status = fstat(fileno(fp), &status);
#endif

    if (i_status == -1)
    {
        strcpy(s_msg_code, "ALM-0043");

        if(c_add_fieldmsg == 'Y')
        {
            TRS.add_fieldmsg(out_node, "Attached File Name", MP_NSTR, s_file_name);
        }

        fclose(fp);

        gs_log_type.type = MP_LOG_ERROR;
        gs_log_type.e_type = MP_LOG_E_SYSTEM;
        gs_log_type.category = MP_LOG_CATE_COMMON;
        return MP_FALSE;
    }

    blob_buffer = (unsigned char*)COM_malloc(status.st_size, "COMCus_get_attached_file", s_file_name);
    fread(blob_buffer, status.st_size, 1, fp);

    TRS.set_blob(out_node, s_put_member_name, blob_buffer, status.st_size);

    fclose(fp);
    COM_free(blob_buffer);

    return MP_TRUE;
}