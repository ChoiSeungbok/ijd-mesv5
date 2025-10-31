/*******************************************************************************

	System      : MESplus
	Module      : User Routine for Common
	File Name   : UCMN_server_start.c
	Description : User Routine for UCMN_server_start

	MES Version : 5.0

	Function List
		-

	Detail Description
		-

	History
	Seq   Date        Developer      Description
	---------------------------------------------------------------------------
	1     2009/02/16  Miracom        Create

	Copyright(C) 1998-2008 Miracom,Inc.
	All rights reserved.

*******************************************************************************/

#include "UCMN_common.h"
#include "CUS_defines.h"
#include "DBU_common.h"
#include <stdio.h>
#include <windows.h>
#include <psapi.h>



#include "UWIP_common.h"
#include <WIPCore_common.h>
#include "DBU_common.h"
#include "CUS_common.h"
#include "CUS_WIP_common.h"



char gs_area_ctm[3];
char gs_area_pdc[3];
char gs_area_hm[3];
char gs_area_grt[3];
double pv_clw_in_temp;
double pv_clw_out_temp;
double pv_hdl_temp;

int UCMN_server_start_1(TRSNode* in_node, TRSNode* out_node)
{
	/* TODO : Insert your code */
	int i_len;
	int i_len_2;
	int i_ret;
	int i_step;
	char s_value[256];
	char s_key[256];
	char s_msg_code[MP_SIZE_MSG];

	struct MGCMTBLDAT_TAG MGCMTBLDAT;
	struct MGCMTBLDAT_TAG MGCMTBLDAT_VER;

	TRSNode* list_item;
	TRSNode* tran_in_node;
	TRSNode* tran_out_node;

	memset(s_msg_code, ' ', MP_SIZE_MSG);

	// SYSTEM FACTORY 에서 사업부 별 AREA Code 들고 와서 Global 변수에 담아준다.
	// ERP 에서 AREA Code 를 동시에 쓸수 없다고 해서 ...-_-
	memset(gs_area_ctm, 0x00, sizeof(gs_area_ctm));
	memset(gs_area_pdc, 0x00, sizeof(gs_area_pdc));
	memset(gs_area_hm, 0x00, sizeof(gs_area_hm));
	memset(gs_area_grt, 0x00, sizeof(gs_area_grt));

	pv_clw_in_temp = 0.0;
	pv_clw_out_temp = 0.0;
	pv_hdl_temp = 0.0;

	i_step = 6;
	DBU_init_mgcmtbldat(&MGCMTBLDAT);
	memcpy(MGCMTBLDAT.FACTORY, "SYSTEM", strlen("SYSTEM"));
	memcpy(MGCMTBLDAT.TABLE_NAME, "GLOBAL_AREA", strlen("GLOBAL_AREA"));
	DBU_open_mgcmtbldat(i_step, &MGCMTBLDAT);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "BAS-0004");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}

	// FETCH
	while (1)
	{
		DBU_fetch_mgcmtbldat(i_step, &MGCMTBLDAT);
		if (DB_error_code == DB_NOT_FOUND)
		{
			DBU_close_mgcmtbldat(i_step);
			break;
		}
		else if (DB_error_code != DB_SUCCESS)
		{
			strcpy(s_msg_code, "BAS-0004");
			TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
			TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT.FACTORY), MGCMTBLDAT.FACTORY);
			TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT.TABLE_NAME), MGCMTBLDAT.TABLE_NAME);
			TRS.add_dberrmsg(out_node, DB_error_msg);
			return MP_FALSE;
		}

		if (memcmp(MGCMTBLDAT.KEY_1, MP_AREA_CTM, strlen(MP_AREA_CTM)) == 0)
		{
			memcpy(gs_area_ctm, MGCMTBLDAT.DATA_1, sizeof(gs_area_ctm));
		}

		if (memcmp(MGCMTBLDAT.KEY_1, MP_AREA_PDC, strlen(MP_AREA_PDC)) == 0)
		{
			memcpy(gs_area_pdc, MGCMTBLDAT.DATA_1, sizeof(gs_area_pdc));
		}

		if (memcmp(MGCMTBLDAT.KEY_1, MP_AREA_HM, strlen(MP_AREA_HM)) == 0)
		{
			memcpy(gs_area_hm, MGCMTBLDAT.DATA_1, sizeof(gs_area_hm));
		}

		if (memcmp(MGCMTBLDAT.KEY_1, MP_AREA_GRIT, strlen(MP_AREA_GRIT)) == 0)
		{
			memcpy(gs_area_grt, MGCMTBLDAT.DATA_1, sizeof(gs_area_grt));
		}
	}



	//ITGC관련 감사에서 운영시스템 변경History를 관리해야된다고 지적사항나와서.
	//Clinet는 버전변경된 히스토리보여주면 되는데.. 서버는 없어서..넣음.
	//바뀐파일과 이전파일이 다른 파일이면  GCM히스토리에 기록하고 현황으로 보여주고 그걸로 증빙자료 제출..System으로 접속시 현황 하나 만들어놓음. 20241006 syw

	DBU_init_mgcmtbldat(&MGCMTBLDAT_VER);
	memcpy(MGCMTBLDAT_VER.FACTORY, "SYSTEM", strlen("SYSTEM"));
	memcpy(MGCMTBLDAT_VER.TABLE_NAME, "UPGRADE_OPTION", strlen("UPGRADE_OPTION"));
	memcpy(MGCMTBLDAT_VER.KEY_1, "MESServer", strlen("MESServer"));
	DBU_select_mgcmtbldat(1, &MGCMTBLDAT_VER);
	if (DB_error_code != DB_SUCCESS)
	{
		strcpy(s_msg_code, "BAS-0004");
		TRS.add_fieldmsg(out_node, "MGCMTBLDAT OPEN", MP_NVST);
		TRS.add_fieldmsg(out_node, "FACTORY", MP_STR, sizeof(MGCMTBLDAT_VER.FACTORY), MGCMTBLDAT_VER.FACTORY);
		TRS.add_fieldmsg(out_node, "TABLE_NAME", MP_STR, sizeof(MGCMTBLDAT_VER.TABLE_NAME), MGCMTBLDAT_VER.TABLE_NAME);
		TRS.add_fieldmsg(out_node, "KEY_1", MP_STR, sizeof(MGCMTBLDAT_VER.KEY_1), MGCMTBLDAT_VER.KEY_1);
		TRS.add_dberrmsg(out_node, DB_error_msg);
		return MP_FALSE;
	}




	char s_sys_time[14];
	memset(s_sys_time, ' ', sizeof(s_sys_time));

	//DB 시간 가져오기
	DB_get_systime(s_sys_time);

	s_sys_time[sizeof(s_sys_time) - 1] = '\0';


	char current_file_path[1024];    // 현재 실행 중인 서버 파일 경로
	char backup_file_path[1024];    // 백업된 파일 경로
	char backupHistory_file_path[1024];    // 백업된 파일 History 경로
	const char* additional_path = "\\backup\\MESServer.exe";
	char additional_path2[1024];


	// 백업 경로와 히스토리 파일 경로 설정
	strcpy(additional_path2, "\\backup\\MESServer_");
	strcat(additional_path2, s_sys_time);
	strcat(additional_path2, ".exe");

	GetModuleFileName(NULL, current_file_path, sizeof(current_file_path));
	strncpy(backup_file_path, current_file_path, sizeof(backup_file_path) - 1);
	backup_file_path[sizeof(backup_file_path) - 1] = '\0';
	strncpy(backupHistory_file_path, current_file_path, sizeof(backupHistory_file_path) - 1);
	backupHistory_file_path[sizeof(backupHistory_file_path) - 1] = '\0';

	// 마지막 슬래시 위치 찾아 경로 추가
	char* last_slash = strrchr(backup_file_path, '\\');
	if (last_slash != NULL) {
		*(last_slash + 1) = '\0';
		strncat(backup_file_path, additional_path, sizeof(backup_file_path) - strlen(backup_file_path) - 1);
	}

	char* last_slash2 = strrchr(backupHistory_file_path, '\\');
	if (last_slash2 != NULL) {
		*(last_slash2 + 1) = '\0';
		strncat(backupHistory_file_path, additional_path2, sizeof(backupHistory_file_path) - strlen(backupHistory_file_path) - 1);
	}

	// 파일 비교
	FILE* fp1 = fopen(current_file_path, "rb");
	FILE* fp2 = fopen(backup_file_path, "rb");

	if (fp1 == NULL || fp2 == NULL) {
		if (fp1) fclose(fp1);
		if (fp2) fclose(fp2);
	}
	else {


		fseek(fp1, 0, SEEK_END);
		fseek(fp2, 0, SEEK_END);
		long size1 = ftell(fp1);
		long size2 = ftell(fp2);
		rewind(fp1);
		rewind(fp2);

		int isame = (size1 == size2);
		if (isame) {
			int ch1, ch2;
			while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) {
				if (ch1 != ch2) {
					isame = 0;
					break;
				}
			}
		}

		fclose(fp1);
		fclose(fp2);


		// 파일이 다르면 복사 진행
		if (!isame) {


			/*
			if (copy_file(current_file_path, backup_file_path) == 0 &&
				copy_file(backup_file_path, backupHistory_file_path) == 0)
			*/

			if (!CopyFile(current_file_path, backup_file_path, FALSE) == 0 &&
				!CopyFile(backup_file_path, backupHistory_file_path, FALSE) == 0)
			{


				//백업해놓은 파일명 기준으로 GCM테이블에 기록(서버배포현황 화면에서 사용)
			 	char* p_insert_name;
	

				p_insert_name = strrchr(backupHistory_file_path, '\\');  // Windows 경로는 '\' 사용
				if (p_insert_name != NULL) {
					p_insert_name++;  // 슬래시 다음 문자부터 파일 이름
				}
				else {
					p_insert_name = backupHistory_file_path;  // 슬래시가 없으면 전체가 파일 이름
				}



				// 데이터베이스 업데이트 코드 추가
				//char sData2[50];
				//sprintf(sData2, "%ld", size1);

				tran_in_node = TRS.create_node("IN_VALUE");
				tran_out_node = TRS.create_node("OUT_VALUE");

				TRS.set_string(tran_in_node, "FACTORY", "SYSTEM", strlen("SYSTEM"));
				TRS.set_string(tran_in_node, "TABLE_NAME", "UPGRADE_OPTION", strlen("UPGRADE_OPTION"));
				TRS.set_string(tran_in_node, "USERID", MP_DEFAULT_USER_ID, strlen(MP_DEFAULT_USER_ID));
				TRS.set_char(tran_in_node, "PROCSTEP", 'U');

				list_item = TRS.add_node(tran_in_node, "DATA_LIST");
				TRS.add_string(list_item, "KEY_1", MGCMTBLDAT_VER.KEY_1, sizeof(MGCMTBLDAT_VER.KEY_1));

				TRS.add_string(list_item, "DATA_2", p_insert_name, strlen(p_insert_name));
				//TRS.add_nstring(list_item, "DATA_2", "asdasd");
				//TRS.add_nstring(list_item, "DATA_2", p_insert_name);
				//TRS.add_string(list_item, "DATA_2", p_insert_name, strlen(p_insert_name));

				if (BAS_UPDATE_DATA_LIST(s_msg_code, tran_in_node, tran_out_node) == MP_FALSE) {
					TRS.clone(out_node, tran_out_node);
					TRS.free_node(tran_out_node);
				}
			}

		}



		//캡션 파일 위치
		memset(gs_cus_cpt_dir, 0x00, sizeof(gs_cus_cpt_dir));
		memset(s_value, 0x00, sizeof(s_value));

		i_ret = COM_get_init_value(gs_com_file, "Directories", "MESplusCusCaptionDir", s_value, &i_len);
		if (i_ret == MP_FALSE)
		{
			LOG_head("UCMN_server_start_1 : COM_get_init_value");
			LOG_add("gs_com_file", MP_NSTR, gs_svr_file);
			LOG_add("s_key", MP_NSTR, s_key);
			COM_log_write(MP_LOG_DEBUG, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

			return MP_TRUE;
		}

		memcpy(gs_cus_cpt_dir, s_value, i_len);

		//report 파일 위치
		memset(gs_cus_rpt_dir, 0x00, sizeof(gs_cus_rpt_dir));
		memset(s_value, 0x00, sizeof(s_value));

		i_ret = COM_get_init_value(gs_com_file, "Directories", "MESplusCusReportDir", s_value, &i_len_2);
		if (i_ret == MP_FALSE)
		{
			LOG_head("UCMN_server_start_1 : COM_get_init_value");
			LOG_add("gs_com_file", MP_NSTR, gs_svr_file);
			LOG_add("s_key", MP_NSTR, s_key);
			COM_log_write(MP_LOG_DEBUG, MP_LOG_E_LOGIC, MP_LOG_CATE_TRANS);

			return MP_TRUE;
		}

		memcpy(gs_cus_rpt_dir, s_value, i_len_2);






		return MP_TRUE;
	}
}

// 파일 복사 함수 정의
int copy_file(const char* src_path, const char* dest_path) {

	if (!CopyFile(src_path, dest_path, FALSE)) {
		DWORD error = GetLastError();
		return 1;
	}



	/*
	FILE* src = NULL;
	FILE* dest = NULL;

	// 소스 파일 열기
	if (fopen_s(&src, src_path, "rb") != 0) {
		return 1;
	}

	// 대상 파일 열기
	if (fopen_s(&dest, dest_path, "wb") != 0) {
		fclose(src);
		return 1;
	}

	char buffer[4096];
	size_t bytes;
	while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
		if (fwrite(buffer, 1, bytes, dest) != bytes) {
			fclose(src);
			fclose(dest);
			return 1;
		}
	}

	fclose(src);
	fclose(dest);

	*/
	return 0;
}