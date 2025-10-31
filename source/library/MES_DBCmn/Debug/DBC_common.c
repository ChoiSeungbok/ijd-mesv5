
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[14];
};
static const struct sqlcxp sqlfpn =
{
    13,
    "DBC_common.pc"
};


static unsigned int sqlctx = 567899;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {13,5};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,60,0,122,192,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,0,0,0,27,235,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
55,0,0,0,0,0,27,238,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,10,0,0,
86,0,0,4,54,0,1,246,0,0,0,0,0,1,0,
101,0,0,5,37,0,1,249,0,0,0,0,0,1,0,
116,0,0,6,69,0,1,254,0,0,0,0,0,1,0,
131,0,0,7,0,0,32,272,0,0,0,0,0,1,0,
146,0,0,8,74,0,4,300,0,0,1,0,0,1,0,2,97,0,0,
165,0,0,9,76,0,4,337,0,0,1,0,0,1,0,2,97,0,0,
184,0,0,10,48,0,4,367,0,0,1,0,0,1,0,2,97,0,0,
203,0,0,11,0,0,29,383,0,0,0,0,0,1,0,
218,0,0,12,0,0,31,449,0,0,0,0,0,1,0,
233,0,0,13,17,0,1,484,0,0,0,0,0,1,0,
248,0,0,14,31,0,1,497,0,0,0,0,0,1,0,
263,0,0,15,29,0,1,512,0,0,0,0,0,1,0,
278,0,0,16,20,0,43,527,0,0,0,0,0,1,0,
293,0,0,17,34,0,43,543,0,0,0,0,0,1,0,
308,0,0,18,32,0,43,556,0,0,0,0,0,1,0,
323,0,0,19,29,0,4,574,0,0,1,0,0,1,0,2,1,0,0,
342,0,0,20,40,0,1,588,0,0,0,0,0,1,0,
357,0,0,0,0,0,1051,633,0,0,4,4,0,0,128,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,1,9,0,
0,
392,0,0,0,0,0,1051,636,0,0,4,4,0,0,128,1,9,0,0,1,9,0,0,1,9,0,0,1,10,0,0,1,9,0,
0,
427,0,0,23,54,0,1025,644,0,0,0,0,0,0,128,1,9,0,0,
446,0,0,24,37,0,1025,647,0,0,0,0,0,0,128,1,9,0,0,
465,0,0,25,0,0,1056,675,0,0,0,0,0,0,128,1,9,0,0,
484,0,0,26,74,0,1028,710,0,0,1,0,0,0,128,2,97,0,0,1,9,0,0,
507,0,0,27,76,0,1028,753,0,0,1,0,0,0,128,2,97,0,0,1,9,0,0,
530,0,0,28,0,0,1053,795,0,0,0,0,0,0,128,1,9,0,0,
549,0,0,29,0,0,1055,820,0,0,0,0,0,0,128,1,9,0,0,
568,0,0,30,17,0,1025,845,0,0,0,0,0,0,128,1,9,0,0,
587,0,0,31,20,0,1067,869,0,0,0,0,0,0,128,1,9,0,0,
606,0,0,32,29,0,1028,895,0,0,1,0,0,0,128,2,1,0,0,1,9,0,0,
629,0,0,33,40,0,1025,920,0,0,0,0,0,0,128,1,9,0,0,
648,0,0,34,382,0,4,1404,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
};


/*******************************************************************************

    System      : MESplus
    Module      : DBCore
    File Name   : DBC_common.pc
    Description : DB Common Functions related module

    MES Version : 4.0.0 

    Function List
        1. DB_connect() : Connect to DB (Local/Remote)
        2. DB_disconnect() : Disconnect from DB by releasing the ROLLBACK WORK
        3. DB_get_systime() : Get DB System Time ('YYYYMMDDHH24MISS')
        4. DB_usr_error() : Error Handler for DB
        5. DB_commit() : execute COMMIT command
        6. DB_rollback() : execute ROLLBACK command
        7. DB_savepoint() : execute SAVEPOINT command
        8. DB_rollback_to_savepoint() : execute ROLLBACK TO SAVEPOINT command
        9. DB_select_dual() : Check DB Connection
        10. DB_set_rollback_segment_rbg() : Setting big rollback segment, name is rbg
        11. DB_mconnect() : Connect to DB (Local/Remote) in multiple db connection environment
        12. DB_mdisconnect() : Disconnect from DB by releasing the ROLLBACK WORK in multiple db connection environment
        13. DB_mget_systime() : Get DB System Time ('YYYYMMDDHH24MISS') in multiple db connection environment
        14. DB_mcommit() : execute COMMIT command in multiple db connection environment
        15. DB_mrollback() : execute ROLLBACK command in multiple db connection environment
        16. DB_msavepoint() : execute SAVEPOINT command in multiple db connection environment
        17. DB_mrollback_to_savepoint() : execute ROLLBACK TO SAVEPOINT command in multiple db connection environment
        18. DB_mselect_dual() : Check DB Connection in multiple db connection environment
        19. DB_mset_rollback_segment_rbg() : Setting big rollback segment, name is rbg in multiple db connection environment
        20. MEMCPY_AN() : Insert null at end of string
        21. MEMCPY_DN() : copy the memory without NULL by transfering from NULL to SPACE
        22. ISSPACE() : Check the String whether blank or not
        23. make_valid_quote() : Make valid quote string

    Detail Description
        - 
        
    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/11/20  R&D            Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/
/* EXEC SQL BEGIN DECLARE SECTION; */ 

/*     EXEC SQL INCLUDE DBC_Q_COND_N;
 */ 
/*********************************************************************
**
**    File Name   : dbc_q_cond_n.h
**    Description : DB Common Null Structure Definition Header File
**    Create date : 2010/01/19 10:10:57
**
**    Generated by DB Common Generator
**    Copyright (C), MIRACOM,INC.
**
*********************************************************************/

#ifndef __DBC_Q_COND_N_LOADED
#define __DBC_Q_COND_N_LOADED

/* Do not ever change ���� �������� ���ÿ�. */
struct DBC_Q_COND_N_TAG {
    char FROM_DATE[9];
    char TO_DATE[9];
    char FROM_TIME[15];
    char TO_TIME[15];
    char MAT_TYPE[21];
    char MAT_GRP[21];
    char RES_ID[21];
    char OPER[11];
    char SPC_SUMMARY_KEY[13];
    int FROM_SEQ;
    int TO_SEQ;
    int PRIO_LEVEL;
    char PRIO_KEY[21];

    char KEY_1[51];
    char KEY_2[51];
    char KEY_3[51];
    char KEY_4[51];
    char KEY_5[51];
    char KEY_6[51];
    char KEY_7[51];
    char KEY_8[51];
    char KEY_9[51];
    char KEY_10[51];
    char KEY_11[51];
    char KEY_12[51];
    char KEY_13[51];
    char KEY_14[51];
    char KEY_15[51];
    char KEY_16[51];
    char KEY_17[51];
    char KEY_18[51];
    char KEY_19[51];
    char KEY_20[51];

    int NUM_1;
    int NUM_2;
    int NUM_3;
    int NUM_4;
    int NUM_5;
    int NUM_6;
    int NUM_7;
    int NUM_8;
    int NUM_9;
    int NUM_10;
};
/* Added by YJJung - 20161010 */
/* Do not ever change ���� �������� ���ÿ�. */
struct DBC_Q_COND_EXT_N_TAG {
    char FROM_DATE[9];
    char TO_DATE[9];
    char FROM_TIME[15];
    char TO_TIME[15];
    char MAT_TYPE[21];
    char MAT_GRP[21];
    char RES_ID[21];
    char OPER[11];
    char SPC_SUMMARY_KEY[13];
    int FROM_SEQ;
    int TO_SEQ;
    int PRIO_LEVEL;
    char PRIO_KEY[21];

    char KEY_1[101];
    char KEY_2[101];
    char KEY_3[101];
    char KEY_4[101];
    char KEY_5[101];
    char KEY_6[101];
    char KEY_7[101];
    char KEY_8[101];
    char KEY_9[101];
    char KEY_10[101];
    char KEY_11[101];
    char KEY_12[101];
    char KEY_13[101];
    char KEY_14[101];
    char KEY_15[101];
    char KEY_16[101];
    char KEY_17[101];
    char KEY_18[101];
    char KEY_19[101];
    char KEY_20[101];

    int NUM_1;
    int NUM_2;
    int NUM_3;
    int NUM_4;
    int NUM_5;
    int NUM_6;
    int NUM_7;
    int NUM_8;
    int NUM_9;
    int NUM_10;
};

extern struct DBC_Q_COND_N_TAG DBC_Q_COND_N;
extern struct DBC_Q_COND_EXT_N_TAG DBC_Q_COND_EXT_N;

#endif  /* __DBC_Q_COND_N_LOADED */

/* EXEC SQL END DECLARE SECTION; */ 


/* SQL Common Header File */
#include "DBC_common.h"


/* EXEC SQL BEGIN DECLARE SECTION; */ 

    int  DB_error_code;
    char DB_error_msg[200];
    char gc_db_connected;
    char gc_mdb_connected;
    char gc_by_mconn_query;

    /* Indicate whether exist save point by future action or not */
    int  DB_future_action_save_point;
    /* Indicate whether exist save point by step action or not */
    int  DB_step_action_save_point;

    /* Service 에 대한 DB_commit() 시 alarm queue 를 확인하여 alarm 을 처리할 것을 선별하여 설정함. */
    struct ALARM_MSG_TAG    gs_alarm_queue[MP_SIZE_ALM_MAX_QUEUE];
    int                     gi_alarm_keep_count;

    struct RTD_CHANGE_DATA_TAG  gs_rtd_change_data;

    /* Query Condition Variable Definition */
    struct DBC_Q_COND_TAG DBC_Q_COND;
    struct DBC_Q_COND_N_TAG DBC_Q_COND_N;
	struct DBC_Q_COND_EXT_TAG DBC_Q_COND_EXT;
    struct DBC_Q_COND_EXT_N_TAG DBC_Q_COND_EXT_N;

	/* Add by J.S. 2011.11.25 for DST */
	char gc_DB_DST_time_compress;
	char gs_DB_DST_end_time[20];
	char gs_DB_DST_end_time_hour[14]; /* DST End date time of this year - 1 hour */
	char gs_DB_DST_end_time_year[14]; /* DST End date time of this year */
	char gs_DB_time_zone_offset[6]; /* time zone +0000 */
	/* End Add */
/* EXEC SQL END DECLARE SECTION; */ 


char gc_DB_collect_sql_trace;


/* 2006/04/13 J.S : Error handler는 맨 앞에 있어야 함. 뒤로 옴기지 말것 */
/*******************************************************************************
    DB_usr_error()
        - Error Handler for DB
          when an error occured or no data found while quering  
          the DB, copy the sql error message to sql_error_msg 
          which is defined as global variable 
    Return Value
        - None
    Arguments
        - char *s_p : The source string 
        - int size_i : The size of source string
    Globals
        - sql_error_code : used
        - sql_error_msg : modified
*******************************************************************************/
void DB_usr_error()
{
    char err_msg[512];           
    size_t buf_len, msg_len;

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


    DB_error_code = sqlca.sqlcode;
    memset(DB_error_msg, 0x00, sizeof(DB_error_msg));

    if(gc_by_mconn_query != 'Y')
    {
        if(gc_db_connected == 'Y')
        {
            if(DB_error_code == DB_LISTENER_FAILED ||
               DB_error_code == DB_DISCONNECT  ||
               DB_error_code == DB_EOF_CHANNEL ||
               DB_error_code == DB_FAIL_PACKET_WRITE ||
               DB_error_code == DB_NOT_LOGGED_ON ||
               DB_error_code == DB_LOST_CONTACT ||
               DB_error_code == DB_NO_LISTENER)
            {
                gc_db_connected = 'N';
            }
        }
    }
    else if(gc_by_mconn_query == 'Y')
    {
        if(gc_mdb_connected == 'Y')
        {
            if(DB_error_code == DB_LISTENER_FAILED ||
               DB_error_code == DB_DISCONNECT  ||
               DB_error_code == DB_EOF_CHANNEL ||
               DB_error_code == DB_FAIL_PACKET_WRITE ||
               DB_error_code == DB_NOT_LOGGED_ON ||
               DB_error_code == DB_LOST_CONTACT ||
               DB_error_code == DB_NO_LISTENER)
            {
                gc_mdb_connected = 'N';
            }
        }
    }
    
    buf_len = sizeof(err_msg);
    sqlglm(err_msg, &buf_len, &msg_len);
    
    if(msg_len > 199) {
        msg_len = 199;
    }

    memcpy(DB_error_msg, err_msg, msg_len);
    return;     
}

/* EXEC SQL WHENEVER SQLERROR DO DB_usr_error(); */ 

/* EXEC SQL WHENEVER NOT FOUND DO DB_usr_error(); */ 


/*******************************************************************************
    DB_set_session_info()
        - Set DB Session information
    Return Value
        - None
    Arguments
        - char AppName
        - char HostName
        - char SubNo  
    Globals
        - sql_error_code : Modified
*******************************************************************************/
void DB_set_session_info(char *AppName, char *HostName, char *SubNo)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR     ModuleName[64]; */ 
struct { unsigned short len; unsigned char arr[64]; } ModuleName;

    /* EXEC SQL END DECLARE SECTION; */ 


    if(gc_db_connected == 'Y')
    {
        char s_module_name[64];

        DB_error_code = 0;

        sprintf(s_module_name, "%s@%s %s", AppName, HostName, SubNo);
        strcpy((char *)ModuleName.arr, s_module_name);
        ModuleName.len = strlen((char *)ModuleName.arr);

        /* EXEC SQL CALL DBMS_APPLICATION_INFO.SET_MODULE(:ModuleName, 'Set module info'); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "call DBMS_APPLICATION_INFO.SET_MODULE(:b0,'Set modul\
e info')";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)&ModuleName;
        sqlstm.sqhstl[0] = (unsigned int  )66;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}


    }
}

/*******************************************************************************
    DB_connect()
        - Connect to DB (Local/Remote)
    Return Value
        - None
    Arguments
        - int ConnectMode : 1-Local, 2-Remote
        - char Nodename
        - char Username
        - char Password  
    Globals
        - sql_error_code : Modified
*******************************************************************************/
void DB_connect(int ConnectMode, char *TnsName, char *Username, char *Password)
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR     OraUserName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraUserName;

        /* VARCHAR     OraPassword[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraPassword;

        /* VARCHAR     OraTnsName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraTnsName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_db_connected = 'N';

    DB_future_action_save_point = 0;
    DB_step_action_save_point = 0;
    DB_error_code = 0;

    strcpy((char *)OraUserName.arr, Username);
    strcpy((char *)OraPassword.arr, Password);
    strcpy((char *)OraTnsName.arr, TnsName);
    
    OraUserName.len = strlen((char *)OraUserName.arr);
    OraPassword.len = strlen((char *)OraPassword.arr);
    OraTnsName.len = strlen((char *)OraTnsName.arr);

    switch(ConnectMode)
    {
        case 1:
            /* EXEC SQL CONNECT :OraUserName IDENTIFIED BY :OraPassword; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 4;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )10;
            sqlstm.offset = (unsigned int  )24;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&OraUserName;
            sqlstm.sqhstl[0] = (unsigned int  )34;
            sqlstm.sqhsts[0] = (         int  )34;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&OraPassword;
            sqlstm.sqhstl[1] = (unsigned int  )34;
            sqlstm.sqhsts[1] = (         int  )34;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlstm.sqlcmax = (unsigned int )100;
            sqlstm.sqlcmin = (unsigned int )2;
            sqlstm.sqlcincr = (unsigned int )1;
            sqlstm.sqlctimeout = (unsigned int )0;
            sqlstm.sqlcnowait = (unsigned int )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CONNECT :OraUserName IDENTIFIED BY :OraPassword USING :OraTnsName; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 4;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )10;
            sqlstm.offset = (unsigned int  )55;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&OraUserName;
            sqlstm.sqhstl[0] = (unsigned int  )34;
            sqlstm.sqhsts[0] = (         int  )34;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&OraPassword;
            sqlstm.sqhstl[1] = (unsigned int  )34;
            sqlstm.sqhsts[1] = (         int  )34;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&OraTnsName;
            sqlstm.sqhstl[2] = (unsigned int  )34;
            sqlstm.sqhsts[2] = (         int  )34;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlstm.sqlcmax = (unsigned int )100;
            sqlstm.sqlcmin = (unsigned int )2;
            sqlstm.sqlcincr = (unsigned int )1;
            sqlstm.sqlctimeout = (unsigned int )0;
            sqlstm.sqlcnowait = (unsigned int )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        default:
            break;
    }

    if(DB_error_code == 0)
    {
        /* EXEC SQL ALTER SESSION SET NLS_DATE_FORMAT = 'YYYYMMDDHH24MISS'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = 'YYYYMMDDHH24MIS\
S'";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )86;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}


        /* 2007.11.20. Aiden */
        /* Order By시 Sorting에 문제가 발생하여 Session Sorting option을 지정. 독일 윈도우에서 문제 발생 */
        /* EXEC SQL ALTER SESSION SET NLS_SORT = 'BINARY'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "alter SESSION SET NLS_SORT = 'BINARY'";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )101;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}



        if(gc_DB_collect_sql_trace == 'Y')
        {   /* 2012.10.18. Aiden */
            /* CollectOracleSQLTrace 인 경우 Oracle Session 에 대한 Trace Log 를 남기도록 설정 */
            /* EXEC SQL ALTER SESSION SET EVENTS '10046 TRACE NAME CONTEXT FOREVER, LEVEL 12'; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 4;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "alter SESSION SET EVENTS '10046 TRACE NAME CONTE\
XT FOREVER, LEVEL 12'";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )116;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


        }

        gc_db_connected = 'Y';
    }
}


/*******************************************************************************
    DB_disconnect()
        - Disconnect from DB by releasing the ROLLBACK WORK
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_disconnect()
{
    /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )131;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    gc_db_connected = 'N';
}


/*******************************************************************************
    DB_get_systime()
        - Get DB System Time ('YYYYMMDDHH24MISS')
    Return Value
        - int : 1 (blank)/ 0 (not blank)
    Arguments
        - char *s_time : Time String
*******************************************************************************/
void DB_get_systime(char *s_time)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char s_t_time[20];
		char s_c_time[14];
		char s_c_offset[5];
		char i_ret;
		char s_c_msec[6];
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(s_time, ' ', 14);
    memset(s_t_time, ' ', sizeof(s_t_time));
    DB_error_code = 0;

    /*EXEC SQL SELECT TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') INTO :s_t_time FROM DUAL;*/
    /* EXEC SQL SELECT TO_CHAR(SYSTIMESTAMP, 'YYYYMMDDHH24MISSTZHTZM') INTO :s_t_time FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSTIMESTAMP,'YYYYMMDDHH24MISSTZHTZM') in\
to :b0  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )146;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)s_t_time;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    
	memcpy(s_c_time, s_t_time, 14);
	memcpy(s_c_offset, s_t_time + 14, 5);
	memset(s_c_msec, '0', sizeof(s_c_msec));
	i_ret = DB_time_compress(s_c_time, s_c_offset, s_c_msec);
	if(i_ret != DB_TRUE)
	{
		DB_error_code = 9998;
		memset(DB_error_msg, ' ', sizeof(DB_error_msg));
        sprintf(DB_error_msg, "Error : DST Time compress : Error Code = [%d]", i_ret);

	    memcpy(s_time, s_t_time, 14);
		return;
	}
	
	memcpy(s_time, s_c_time, 14);
    /* memcpy(s_time, s_t_time, 14); */
}

void DB_get_systime_m(char *s_time)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char s_t_time[26];
		char s_c_time[14];
		char s_c_offset[5];
		char i_ret;
		char s_c_msec[6];
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(s_time, ' ', 20);
    memset(s_t_time, ' ', sizeof(s_t_time));
    DB_error_code = 0;
	
	/*Modify by J.S. 2011.11.24 timestamp는 dst적용후 datetime부분이 바로 적용되지 않고 session 재접속시 */
	/*sysdate와 일치하는 문제가 있어 sysdate를 이용하는 것으로 통일                                      */
    /*EXEC SQL SELECT TO_CHAR(CURRENT_TIMESTAMP, 'YYYYMMDDHH24MISSFF') INTO :s_t_time FROM DUAL;      */
    /* EXEC SQL SELECT TO_CHAR(SYSTIMESTAMP, 'YYYYMMDDHH24MISSFFTZHTZM') INTO :s_t_time FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSTIMESTAMP,'YYYYMMDDHH24MISSFFTZHTZM') \
into :b0  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )165;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)s_t_time;
    sqlstm.sqhstl[0] = (unsigned int  )26;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    
	memcpy(s_c_time, s_t_time, 14);
	memcpy(s_c_offset, s_t_time + 20, 5);
	memcpy(s_c_msec, s_t_time + 14, 6);
	i_ret = DB_time_compress(s_c_time, s_c_offset, s_c_msec);
	if(i_ret != DB_TRUE)
	{
		DB_error_code = 9998;
		memset(DB_error_msg, ' ', sizeof(DB_error_msg));
        sprintf(DB_error_msg, "Error : DST Time compress : Error Code = [%d]", i_ret);

	    memcpy(s_time, s_t_time, 20);
		return;
	}

	memcpy(s_time, s_c_time, 14);
	memcpy(s_time + 14, s_c_msec, 6);
    /*memcpy(s_time, s_t_time, 20); */
}

void DB_get_day_of_week(char *c_week)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char s_t_week[2];
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(s_t_week, 0x00, 2);
    DB_error_code = 0;

    /* EXEC SQL SELECT TO_CHAR(SYSDATE, 'd') INTO :s_t_week FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSDATE,'d') into :b0  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )184;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)s_t_week;
    sqlstm.sqhstl[0] = (unsigned int  )2;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    *c_week = s_t_week[0];
}

/*******************************************************************************
    DB_commit()
        - execute COMMIT command
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_commit()
{
    int i;

    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )203;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    
    for(i = 0; i < gi_alarm_keep_count; i++)
    {
        if(gs_alarm_queue[i].send_flag != 'N')
        {
            gs_alarm_queue[i].send_flag = 'Y';
        }
    }
    
    for(i = 0; i < gs_rtd_change_data.rtd_lot_data_count; i++)
    {
        if(gs_rtd_change_data.rtd_lot_data[i].commit_flag != 'N')
        {
            gs_rtd_change_data.rtd_lot_data[i].commit_flag = 'Y';
        }
    }
    
    DB_future_action_save_point = 0;
    DB_step_action_save_point = 0;
}


/*******************************************************************************
    DB_rollback()
        - execute ROLLBACK command
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_rollback()
{
    int i;

    if(DB_future_action_save_point == 1 || DB_step_action_save_point == 1)
    {
        if(DB_future_action_save_point == 1)
        {
            DB_rollback_to_savepoint_for_future_action();
        }
        if(DB_step_action_save_point == 1)
        {
            DB_rollback_to_savepoint_for_step_action();
        }

        for(i = 0; i < gi_alarm_keep_count; i++)
        {
            if(gs_alarm_queue[i].send_flag == 'A')
            {
                gs_alarm_queue[i].send_flag = 'N';
            }
        }

        for(i = 0; i < gs_rtd_change_data.rtd_lot_data_count; i++)
        {
            if(gs_rtd_change_data.rtd_lot_data[i].commit_flag == 'A')
            {
                gs_rtd_change_data.rtd_lot_data[i].commit_flag = 'N';
            }
        }

        DB_commit();
    }
    else
    {
        /* EXEC SQL ROLLBACK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )218;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}



        for(i = 0; i < gi_alarm_keep_count; i++)
        {
            if(gs_alarm_queue[i].send_flag != 'N')
            {
                gs_alarm_queue[i].send_flag = 'N';
            }
        }

        for(i = 0; i < gs_rtd_change_data.rtd_lot_data_count; i++)
        {
            if(gs_rtd_change_data.rtd_lot_data[i].commit_flag != 'N')
            {
                gs_rtd_change_data.rtd_lot_data[i].commit_flag = 'N';
            }
        }

    }

    DB_future_action_save_point = 0;
    DB_step_action_save_point = 0;
}


/*******************************************************************************
    DB_savepoint()
        - execute SAVEPOINT command 
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_savepoint()
{
    /* EXEC SQL SAVEPOINT MESPLUS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "savepoint MESPLUS";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )233;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


}

/*******************************************************************************
    DB_savepoint_for_future_action()
        - execute SAVEPOINT command 
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_savepoint_for_future_action()
{
    /* EXEC SQL SAVEPOINT MESPLUS_FUTURE_ACTION; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "savepoint MESPLUS_FUTURE_ACTION";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )248;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}



    DB_future_action_save_point = 1;
}

/*******************************************************************************
    DB_savepoint_for_step_action()
        - execute SAVEPOINT command 
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_savepoint_for_step_action()
{
    /* EXEC SQL SAVEPOINT MESPLUS_STEP_ACTION; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "savepoint MESPLUS_STEP_ACTION";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )263;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}



    DB_step_action_save_point = 1;
}

/*******************************************************************************
    DB_rollback_to_savepoint()
        - execute ROLLBACK TO SAVEPOINT command
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_rollback_to_savepoint()
{
    /* EXEC SQL ROLLBACK TO SAVEPOINT MESPLUS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "rollback  to MESPLUS";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )278;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}

 

    DB_future_action_save_point = 0;
    DB_step_action_save_point = 0;
}

/*******************************************************************************
    DB_rollback_to_savepoint_for_future_action()
        - execute ROLLBACK TO SAVEPOINT command
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_rollback_to_savepoint_for_future_action()
{
    /* EXEC SQL ROLLBACK TO SAVEPOINT MESPLUS_FUTURE_ACTION; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "rollback  to MESPLUS_FUTURE_ACTION";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )293;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}

 
}

/*******************************************************************************
    DB_rollback_to_savepoint_for_step_action()
        - execute ROLLBACK TO SAVEPOINT command
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_rollback_to_savepoint_for_step_action()
{
    /* EXEC SQL ROLLBACK TO SAVEPOINT MESPLUS_STEP_ACTION; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "rollback  to MESPLUS_STEP_ACTION";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )308;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}

 
}

/*******************************************************************************
    DB_select_dual()
        - Check DB Connection
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_select_dual()
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char dummy_flag;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_error_code = 0;
    /* EXEC SQL SELECT *  into :dummy_flag FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select * into :b0  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )323;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&dummy_flag;
    sqlstm.sqhstl[0] = (unsigned int  )1;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}

   
}


/*******************************************************************************
    DB_set_rollback_segment_rbg()
        - Setting big rollback segment, name is rbg
    Return Value
        - None
    Arguments
        - None
*******************************************************************************/
void DB_set_rollback_segment_rbg()
{
    /* EXEC SQL SET TRANSACTION USE ROLLBACK SEGMENT rbg; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "set transaction USE ROLLBACK SEGMENT rbg";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )342;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


}


/*******************************************************************************
    DB_mconnect()
        - Connect to DB (Local/Remote) in multiple DB environement
    Return Value
        - None
    Arguments
        - int ConnectMode : 1-Local, 2-Remote
        - char ConnName
        - char Nodename
        - char Username
        - char Password  
    Globals
        - sql_error_code : Modified
*******************************************************************************/
void DB_mconnect(int ConnectMode, char *ConnName, char *TnsName, char *Username, char *Password)
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR     OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

        /* VARCHAR     OraUserName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraUserName;

        /* VARCHAR     OraPassword[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraPassword;

        /* VARCHAR     OraTnsName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraTnsName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_mdb_connected = 'N';
    gc_by_mconn_query = 'Y';
    DB_error_code = 0;

    strcpy((char *)OraConnName.arr, ConnName); 
    strcpy((char *)OraUserName.arr, Username);
    strcpy((char *)OraPassword.arr, Password);
    strcpy((char *)OraTnsName.arr, TnsName);
    
    OraConnName.len = strlen((char *)OraConnName.arr);
    OraUserName.len = strlen((char *)OraUserName.arr);
    OraPassword.len = strlen((char *)OraPassword.arr);
    OraTnsName.len = strlen((char *)OraTnsName.arr);

    switch(ConnectMode)
    {
        case 1:
            /* EXEC SQL CONNECT :OraUserName IDENTIFIED BY :OraPassword AT:OraConnName; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )10;
            sqlstm.offset = (unsigned int  )357;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&OraUserName;
            sqlstm.sqhstl[0] = (unsigned int  )34;
            sqlstm.sqhsts[0] = (         int  )34;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&OraPassword;
            sqlstm.sqhstl[1] = (unsigned int  )34;
            sqlstm.sqhsts[1] = (         int  )34;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&OraConnName;
            sqlstm.sqhstl[4] = (unsigned int  )34;
            sqlstm.sqhsts[4] = (         int  )34;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlstm.sqlcmax = (unsigned int )100;
            sqlstm.sqlcmin = (unsigned int )2;
            sqlstm.sqlcincr = (unsigned int )1;
            sqlstm.sqlctimeout = (unsigned int )0;
            sqlstm.sqlcnowait = (unsigned int )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CONNECT :OraUserName IDENTIFIED BY :OraPassword AT:OraConnName USING :OraTnsName; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )10;
            sqlstm.offset = (unsigned int  )392;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&OraUserName;
            sqlstm.sqhstl[0] = (unsigned int  )34;
            sqlstm.sqhsts[0] = (         int  )34;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&OraPassword;
            sqlstm.sqhstl[1] = (unsigned int  )34;
            sqlstm.sqhsts[1] = (         int  )34;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&OraTnsName;
            sqlstm.sqhstl[2] = (unsigned int  )34;
            sqlstm.sqhsts[2] = (         int  )34;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&OraConnName;
            sqlstm.sqhstl[4] = (unsigned int  )34;
            sqlstm.sqhsts[4] = (         int  )34;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlstm.sqlcmax = (unsigned int )100;
            sqlstm.sqlcmin = (unsigned int )2;
            sqlstm.sqlcincr = (unsigned int )1;
            sqlstm.sqlctimeout = (unsigned int )0;
            sqlstm.sqlcnowait = (unsigned int )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        default:
            break;
    }

    if(DB_error_code == 0)
    {
        /* EXEC SQL AT:OraConnName ALTER SESSION SET NLS_DATE_FORMAT = 'YYYYMMDDHH24MISS'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = 'YYYYMMDDHH24MIS\
S'";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )427;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)&OraConnName;
        sqlstm.sqhstl[0] = (unsigned int  )34;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}


        /* 2007.11.20. Aiden */
        /* Order By시 Sorting에 문제가 발생하여 Session Sorting option을 지정. 독일 윈도우에서 문제 발생 */
        /* EXEC SQL AT:OraConnName ALTER SESSION SET NLS_SORT = 'BINARY'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "alter SESSION SET NLS_SORT = 'BINARY'";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )446;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)&OraConnName;
        sqlstm.sqhstl[0] = (unsigned int  )34;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}



        gc_mdb_connected = 'Y';
    }

    gc_by_mconn_query = 'N';
}


/*******************************************************************************
    DB_mdisconnect()
        - Disconnect from DB by releasing the ROLLBACK WORK in multiple DB environement
    Return Value
        - None
    Arguments
        - char ConnName
*******************************************************************************/
void DB_mdisconnect(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName ROLLBACK WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )465;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&OraConnName;
    sqlstm.sqhstl[0] = (unsigned int  )34;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    gc_mdb_connected = 'N';
    gc_by_mconn_query = 'N';
}


/*******************************************************************************
    DB_mget_systime()
        - Get DB System Time ('YYYYMMDDHH24MISS') in multiple DB environement
    Return Value
        - int : 1 (blank)/ 0 (not blank)
    Arguments
        - char *s_time : Time String
        - char *ConnName : Time String
*******************************************************************************/
void DB_mget_systime(char *s_time, char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

        char s_t_time[20];
        char s_c_time[14];
        char s_c_offset[5];
        char i_ret;
		char s_c_msec[6];
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(s_time, ' ', 14);
    memset(s_t_time, ' ', sizeof(s_t_time));
    DB_error_code = 0;
    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /*EXEC SQL AT:OraConnName SELECT TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') INTO :s_t_time FROM DUAL; */
    /* EXEC SQL AT:OraConnName SELECT TO_CHAR(SYSTIMESTAMP, 'YYYYMMDDHH24MISSTZHTZM') INTO :s_t_time FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSTIMESTAMP,'YYYYMMDDHH24MISSTZHTZM') in\
to :b1  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )484;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)s_t_time;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&OraConnName;
    sqlstm.sqhstl[1] = (unsigned int  )34;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}



	memcpy(s_c_time, s_t_time, 14);
	memcpy(s_c_offset, s_t_time + 14, 5);
	memset(s_c_msec, '0', sizeof(s_c_msec));
	i_ret = DB_time_compress(s_c_time, s_c_offset, s_c_msec);
	if(i_ret != DB_TRUE)
	{
		DB_error_code = 9998;
		memset(DB_error_msg, ' ', sizeof(DB_error_msg));
        sprintf(DB_error_msg, "Error : DST Time compress : Error Code = [%d]", i_ret);

	    memcpy(s_time, s_t_time, 14);
        gc_by_mconn_query = 'N';
		return;
	}
    
	memcpy(s_time, s_c_time, 14);
    /*memcpy(s_time, s_t_time, 14);*/
    gc_by_mconn_query = 'N';
}

void DB_mget_systime_m(char *s_time, char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

        char s_t_time[26];
        char s_c_time[14];
        char s_c_offset[5];
        char i_ret;
		char s_c_msec[6];
    /* EXEC SQL END DECLARE SECTION; */ 

  

    memset(s_time, ' ', 20);
    memset(s_t_time, ' ', sizeof(s_t_time));
    DB_error_code = 0;
    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /*EXEC SQL AT:OraConnName SELECT TO_CHAR(CURRENT_TIMESTAMP, 'YYYYMMDDHH24MISSFF') INTO :s_t_time FROM DUAL;*/
    /* EXEC SQL AT:OraConnName SELECT TO_CHAR(SYSTIMESTAMP, 'YYYYMMDDHH24MISSFFTZHTZM') INTO :s_t_time FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSTIMESTAMP,'YYYYMMDDHH24MISSFFTZHTZM') \
into :b1  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )507;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)s_t_time;
    sqlstm.sqhstl[0] = (unsigned int  )26;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&OraConnName;
    sqlstm.sqhstl[1] = (unsigned int  )34;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    
	memcpy(s_c_time, s_t_time, 14);
	memcpy(s_c_offset, s_t_time + 20, 5);
	memcpy(s_c_msec, s_t_time + 14, 6);
	i_ret = DB_time_compress(s_c_time, s_c_offset, s_c_msec);
	if(i_ret != DB_TRUE)
	{
		DB_error_code = 9998;
		memset(DB_error_msg, ' ', sizeof(DB_error_msg));
        sprintf(DB_error_msg, "Error : DST Time compress : Error Code = [%d]", i_ret);

	    memcpy(s_time, s_t_time, 20);
        gc_by_mconn_query = 'N';
		return;
	}

	memcpy(s_time, s_c_time, 14);
	memcpy(s_time + 14, s_c_msec, 6);
    /*memcpy(s_time, s_t_time, 20); */
    gc_by_mconn_query = 'N';
}

/*******************************************************************************
    DB_mcommit()
        - execute COMMIT command in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_mcommit(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 

    
    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )530;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&OraConnName;
    sqlstm.sqhstl[0] = (unsigned int  )34;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}


    
    gc_by_mconn_query = 'N';
}


/*******************************************************************************
    DB_mrollback()
        - execute ROLLBACK command in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_mrollback(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 

    
    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

        /* EXEC SQL AT:OraConnName ROLLBACK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )549;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)&OraConnName;
        sqlstm.sqhstl[0] = (unsigned int  )34;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) DB_usr_error();
}



    gc_by_mconn_query = 'N';
}


/*******************************************************************************
    DB_msavepoint()
        - execute SAVEPOINT command  in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_msavepoint(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName SAVEPOINT MESPLUS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "savepoint MESPLUS";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )568;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&OraConnName;
    sqlstm.sqhstl[0] = (unsigned int  )34;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}



    gc_by_mconn_query = 'N';
}

/*******************************************************************************
    DB_mrollback_to_savepoint()
        - execute ROLLBACK TO SAVEPOINT command in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_mrollback_to_savepoint(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName ROLLBACK TO SAVEPOINT MESPLUS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "rollback  to MESPLUS";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )587;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&OraConnName;
    sqlstm.sqhstl[0] = (unsigned int  )34;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}

 

    gc_by_mconn_query = 'N';
}

/*******************************************************************************
    DB_mselect_dual()
        - Check DB Connection in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_mselect_dual(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

        char dummy_flag;
    /* EXEC SQL END DECLARE SECTION; */ 

 
    DB_error_code = 0;
    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName SELECT *  into :dummy_flag FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select * into :b1  from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )606;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&dummy_flag;
    sqlstm.sqhstl[0] = (unsigned int  )1;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&OraConnName;
    sqlstm.sqhstl[1] = (unsigned int  )34;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}

   

    gc_by_mconn_query = 'N';
}


/*******************************************************************************
    DB_mset_rollback_segment_rbg()
        - Setting big rollback segment, name is rbg in multiple DB environement
    Return Value
        - None
    Arguments
        - char *ConnName : Time String
*******************************************************************************/
void DB_mset_rollback_segment_rbg(char *ConnName)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR    OraConnName[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } OraConnName;

    /* EXEC SQL END DECLARE SECTION; */ 


    gc_by_mconn_query = 'Y';

    strcpy((char *)OraConnName.arr, ConnName);
    OraConnName.len = strlen((char *)OraConnName.arr);

    /* EXEC SQL AT:OraConnName SET TRANSACTION USE ROLLBACK SEGMENT rbg; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "set transaction USE ROLLBACK SEGMENT rbg";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )629;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&OraConnName;
    sqlstm.sqhstl[0] = (unsigned int  )34;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) DB_usr_error();
}



    gc_by_mconn_query = 'N';
}

/*******************************************************************************
    MEMCPY_AN()
        - Insert null at end of string
    Return Value
        - None
    Arguments
        - char *d : Destination
        - char *s : Source
        - int size : Size
*******************************************************************************/
void MEMCPY_AN(char *d,char *s,int size)
{
    int i;
    int i_end_of_space; 
   
    i_end_of_space = 0;

    for (i = size - 1; i >= 0; i--)
    {
        if(*(s + i) == ' ' && i_end_of_space == 0)
        {
            *(d + i) = '\0';
        }
        else
        {
            *(d + i) = *(s + i);
            i_end_of_space = 1;
        }
    }

    if(*(d) == '\0') {
        *(d) = ' ';
    }
}


/*******************************************************************************
    MEMCPY_DN()
        - copy the memory without NULL by transfering from NULL to SPACE
    Return Value
        - None
    Arguments
        - char *d : Destination
        - char *s : Source
        - int size : Size
*******************************************************************************/
void MEMCPY_DN(char *d,char *s,int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if(*(s + i) == '\0')
        {  
            *(d + i) = ' ';
        }
        else
        {
            *(d + i) = *(s + i);
        }
    }
}


/*******************************************************************************
    ISSPACE()
        - Check the String whether blank or not
    Return Value
        - int : 1 (blank)/ 0 (not blank)
    Arguments
        - char *s_p : Source
        - int size_i : Size
*******************************************************************************/
int ISSPACE(char *s_p, int size_i)    
{
    int i;                                  

    for (i = 0; i < size_i; i++ )          
    {                                       
        if(*(s_p + i) == ' ')              
            ;                               
        else                                
            return DB_FALSE;                    
    }                                       
                                            
    return DB_TRUE;                            
}                                           

int ISNULLOREMPTY(char *s_p, int size_i)
{
    int i;                                  

    for (i = 0; i < size_i; i++ )          
    {                                       
        if(*(s_p + i) == ' ' || *(s_p +i) == 0x00)              
            ;                               
        else                                
            return DB_FALSE;                    
    }                                       
                                            
    return DB_TRUE;  
}

/*******************************************************************************
    make_valid_quote()
        - Make valid quote string
    Return Value
        - int : 1 (blank)/ 0 (not blank)
    Arguments
        - char *d : Destination
        - char *s : Source
*******************************************************************************/
void make_valid_quote(char *d, char *s)
{
    int i;
    int j;
    int size;

    j = 0;
    size = strlen(s);
    for (i = 0; i < size ; i++)
    {
        if(*(s + i) == 0x27)
        {
            *(d + j) = 0x27;
            j++;
            *(d + j) = 0x27;
            j++;
        }
        else
        {
            *(d + j) = *(s + i);
            j++;
        }
    }
    
    *(d + j) = 0x0;
}

/*******************************************************************************
    DB_init_condition()
        - Initialize Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_TAG *DBC_Q_COND
*******************************************************************************/
void DB_init_condition(struct DBC_Q_COND_TAG *DBC_Q_COND)
{
    /* memset by Space */
    memset(DBC_Q_COND, ' ', sizeof(struct DBC_Q_COND_TAG));
    DBC_Q_COND->FROM_SEQ = 0;
    DBC_Q_COND->TO_SEQ = 0;
    DBC_Q_COND->PRIO_LEVEL = 0;

    DBC_Q_COND->NUM_1 = 0;
    DBC_Q_COND->NUM_2 = 0;
    DBC_Q_COND->NUM_3 = 0;
    DBC_Q_COND->NUM_4 = 0;
    DBC_Q_COND->NUM_5 = 0;
    DBC_Q_COND->NUM_6 = 0;
    DBC_Q_COND->NUM_7 = 0;
    DBC_Q_COND->NUM_8 = 0;
    DBC_Q_COND->NUM_9 = 0;
    DBC_Q_COND->NUM_10 = 0;
}

/*******************************************************************************
    DB_add_null_condition()
        - Add Null Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_N_TAG *DBC_Q_COND_N
*******************************************************************************/
void DB_add_null_condition(struct DBC_Q_COND_TAG *DBC_Q_COND, struct DBC_Q_COND_N_TAG *DBC_Q_COND_N)
{
    /* memset by Space */
    memset(DBC_Q_COND_N, '\0', sizeof(struct DBC_Q_COND_N_TAG));

    MEMCPY_AN(DBC_Q_COND_N->FROM_DATE, DBC_Q_COND->FROM_DATE, sizeof(DBC_Q_COND->FROM_DATE));
    MEMCPY_AN(DBC_Q_COND_N->TO_DATE, DBC_Q_COND->TO_DATE, sizeof(DBC_Q_COND->TO_DATE));
    MEMCPY_AN(DBC_Q_COND_N->FROM_TIME, DBC_Q_COND->FROM_TIME, sizeof(DBC_Q_COND->FROM_TIME));
    MEMCPY_AN(DBC_Q_COND_N->TO_TIME, DBC_Q_COND->TO_TIME, sizeof(DBC_Q_COND->TO_TIME));
    MEMCPY_AN(DBC_Q_COND_N->MAT_TYPE, DBC_Q_COND->MAT_TYPE, sizeof(DBC_Q_COND->MAT_TYPE));
    MEMCPY_AN(DBC_Q_COND_N->MAT_GRP, DBC_Q_COND->MAT_GRP, sizeof(DBC_Q_COND->MAT_GRP));
    MEMCPY_AN(DBC_Q_COND_N->RES_ID, DBC_Q_COND->RES_ID, sizeof(DBC_Q_COND->RES_ID));
    MEMCPY_AN(DBC_Q_COND_N->OPER, DBC_Q_COND->OPER, sizeof(DBC_Q_COND->OPER));
    MEMCPY_AN(DBC_Q_COND_N->SPC_SUMMARY_KEY, DBC_Q_COND->SPC_SUMMARY_KEY, sizeof(DBC_Q_COND->SPC_SUMMARY_KEY));
    DBC_Q_COND_N->FROM_SEQ = DBC_Q_COND->FROM_SEQ;
    DBC_Q_COND_N->TO_SEQ = DBC_Q_COND->TO_SEQ;
    DBC_Q_COND_N->PRIO_LEVEL = DBC_Q_COND->PRIO_LEVEL;
    MEMCPY_AN(DBC_Q_COND_N->PRIO_KEY, DBC_Q_COND->PRIO_KEY, sizeof(DBC_Q_COND->PRIO_KEY));

    MEMCPY_AN(DBC_Q_COND_N->KEY_1, DBC_Q_COND->KEY_1, sizeof(DBC_Q_COND->KEY_1));
    MEMCPY_AN(DBC_Q_COND_N->KEY_2, DBC_Q_COND->KEY_2, sizeof(DBC_Q_COND->KEY_2));
    MEMCPY_AN(DBC_Q_COND_N->KEY_3, DBC_Q_COND->KEY_3, sizeof(DBC_Q_COND->KEY_3));
    MEMCPY_AN(DBC_Q_COND_N->KEY_4, DBC_Q_COND->KEY_4, sizeof(DBC_Q_COND->KEY_4));
    MEMCPY_AN(DBC_Q_COND_N->KEY_5, DBC_Q_COND->KEY_5, sizeof(DBC_Q_COND->KEY_5));
    MEMCPY_AN(DBC_Q_COND_N->KEY_6, DBC_Q_COND->KEY_6, sizeof(DBC_Q_COND->KEY_6));
    MEMCPY_AN(DBC_Q_COND_N->KEY_7, DBC_Q_COND->KEY_7, sizeof(DBC_Q_COND->KEY_7));
    MEMCPY_AN(DBC_Q_COND_N->KEY_8, DBC_Q_COND->KEY_8, sizeof(DBC_Q_COND->KEY_8));
    MEMCPY_AN(DBC_Q_COND_N->KEY_9, DBC_Q_COND->KEY_9, sizeof(DBC_Q_COND->KEY_9));
    MEMCPY_AN(DBC_Q_COND_N->KEY_10, DBC_Q_COND->KEY_10, sizeof(DBC_Q_COND->KEY_10));
    MEMCPY_AN(DBC_Q_COND_N->KEY_11, DBC_Q_COND->KEY_11, sizeof(DBC_Q_COND->KEY_11));
    MEMCPY_AN(DBC_Q_COND_N->KEY_12, DBC_Q_COND->KEY_12, sizeof(DBC_Q_COND->KEY_12));
    MEMCPY_AN(DBC_Q_COND_N->KEY_13, DBC_Q_COND->KEY_13, sizeof(DBC_Q_COND->KEY_13));
    MEMCPY_AN(DBC_Q_COND_N->KEY_14, DBC_Q_COND->KEY_14, sizeof(DBC_Q_COND->KEY_14));
    MEMCPY_AN(DBC_Q_COND_N->KEY_15, DBC_Q_COND->KEY_15, sizeof(DBC_Q_COND->KEY_15));
    MEMCPY_AN(DBC_Q_COND_N->KEY_16, DBC_Q_COND->KEY_16, sizeof(DBC_Q_COND->KEY_16));
    MEMCPY_AN(DBC_Q_COND_N->KEY_17, DBC_Q_COND->KEY_17, sizeof(DBC_Q_COND->KEY_17));
    MEMCPY_AN(DBC_Q_COND_N->KEY_18, DBC_Q_COND->KEY_18, sizeof(DBC_Q_COND->KEY_18));
    MEMCPY_AN(DBC_Q_COND_N->KEY_19, DBC_Q_COND->KEY_19, sizeof(DBC_Q_COND->KEY_19));
    MEMCPY_AN(DBC_Q_COND_N->KEY_20, DBC_Q_COND->KEY_20, sizeof(DBC_Q_COND->KEY_20));

    DBC_Q_COND_N->NUM_1 = DBC_Q_COND->NUM_1;
    DBC_Q_COND_N->NUM_2 = DBC_Q_COND->NUM_2;
    DBC_Q_COND_N->NUM_3 = DBC_Q_COND->NUM_3;
    DBC_Q_COND_N->NUM_4 = DBC_Q_COND->NUM_4;
    DBC_Q_COND_N->NUM_5 = DBC_Q_COND->NUM_5;
    DBC_Q_COND_N->NUM_6 = DBC_Q_COND->NUM_6;
    DBC_Q_COND_N->NUM_7 = DBC_Q_COND->NUM_7;
    DBC_Q_COND_N->NUM_8 = DBC_Q_COND->NUM_8;
    DBC_Q_COND_N->NUM_9 = DBC_Q_COND->NUM_9;
    DBC_Q_COND_N->NUM_10 = DBC_Q_COND->NUM_10;
}

/*******************************************************************************
    DB_del_null_condition()
        - Delete Null Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_N_TAG *DBC_Q_COND_N
*******************************************************************************/
void DB_del_null_condition(struct DBC_Q_COND_TAG *DBC_Q_COND, struct DBC_Q_COND_N_TAG *DBC_Q_COND_N)
{
    MEMCPY_DN(DBC_Q_COND->FROM_DATE, DBC_Q_COND_N->FROM_DATE, sizeof(DBC_Q_COND->FROM_DATE));
    MEMCPY_DN(DBC_Q_COND->TO_DATE, DBC_Q_COND_N->TO_DATE, sizeof(DBC_Q_COND->TO_DATE));
    MEMCPY_DN(DBC_Q_COND->FROM_TIME, DBC_Q_COND_N->FROM_TIME, sizeof(DBC_Q_COND->FROM_TIME));
    MEMCPY_DN(DBC_Q_COND->TO_TIME, DBC_Q_COND_N->TO_TIME, sizeof(DBC_Q_COND->TO_TIME));
    MEMCPY_DN(DBC_Q_COND->MAT_TYPE, DBC_Q_COND_N->MAT_TYPE, sizeof(DBC_Q_COND->MAT_TYPE));
    MEMCPY_DN(DBC_Q_COND->MAT_GRP, DBC_Q_COND_N->MAT_GRP, sizeof(DBC_Q_COND->MAT_GRP));
    MEMCPY_DN(DBC_Q_COND->RES_ID, DBC_Q_COND_N->RES_ID, sizeof(DBC_Q_COND->RES_ID));
    MEMCPY_DN(DBC_Q_COND->OPER, DBC_Q_COND_N->OPER, sizeof(DBC_Q_COND->OPER));
    MEMCPY_DN(DBC_Q_COND->SPC_SUMMARY_KEY, DBC_Q_COND_N->SPC_SUMMARY_KEY, sizeof(DBC_Q_COND->SPC_SUMMARY_KEY));
    DBC_Q_COND->FROM_SEQ = DBC_Q_COND_N->FROM_SEQ;
    DBC_Q_COND->TO_SEQ = DBC_Q_COND_N->TO_SEQ;
    DBC_Q_COND->PRIO_LEVEL = DBC_Q_COND_N->PRIO_LEVEL;
    MEMCPY_DN(DBC_Q_COND->PRIO_KEY, DBC_Q_COND_N->PRIO_KEY, sizeof(DBC_Q_COND->PRIO_KEY));

    MEMCPY_DN(DBC_Q_COND->KEY_1, DBC_Q_COND_N->KEY_1, sizeof(DBC_Q_COND->KEY_1));
    MEMCPY_DN(DBC_Q_COND->KEY_2, DBC_Q_COND_N->KEY_2, sizeof(DBC_Q_COND->KEY_2));
    MEMCPY_DN(DBC_Q_COND->KEY_3, DBC_Q_COND_N->KEY_3, sizeof(DBC_Q_COND->KEY_3));
    MEMCPY_DN(DBC_Q_COND->KEY_4, DBC_Q_COND_N->KEY_4, sizeof(DBC_Q_COND->KEY_4));
    MEMCPY_DN(DBC_Q_COND->KEY_5, DBC_Q_COND_N->KEY_5, sizeof(DBC_Q_COND->KEY_5));
    MEMCPY_DN(DBC_Q_COND->KEY_6, DBC_Q_COND_N->KEY_6, sizeof(DBC_Q_COND->KEY_6));
    MEMCPY_DN(DBC_Q_COND->KEY_7, DBC_Q_COND_N->KEY_7, sizeof(DBC_Q_COND->KEY_7));
    MEMCPY_DN(DBC_Q_COND->KEY_8, DBC_Q_COND_N->KEY_8, sizeof(DBC_Q_COND->KEY_8));
    MEMCPY_DN(DBC_Q_COND->KEY_9, DBC_Q_COND_N->KEY_9, sizeof(DBC_Q_COND->KEY_9));
    MEMCPY_DN(DBC_Q_COND->KEY_10, DBC_Q_COND_N->KEY_10, sizeof(DBC_Q_COND->KEY_10));
    MEMCPY_DN(DBC_Q_COND->KEY_11, DBC_Q_COND_N->KEY_11, sizeof(DBC_Q_COND->KEY_11));
    MEMCPY_DN(DBC_Q_COND->KEY_12, DBC_Q_COND_N->KEY_12, sizeof(DBC_Q_COND->KEY_12));
    MEMCPY_DN(DBC_Q_COND->KEY_13, DBC_Q_COND_N->KEY_13, sizeof(DBC_Q_COND->KEY_13));
    MEMCPY_DN(DBC_Q_COND->KEY_14, DBC_Q_COND_N->KEY_14, sizeof(DBC_Q_COND->KEY_14));
    MEMCPY_DN(DBC_Q_COND->KEY_15, DBC_Q_COND_N->KEY_15, sizeof(DBC_Q_COND->KEY_15));
    MEMCPY_DN(DBC_Q_COND->KEY_16, DBC_Q_COND_N->KEY_16, sizeof(DBC_Q_COND->KEY_16));
    MEMCPY_DN(DBC_Q_COND->KEY_17, DBC_Q_COND_N->KEY_17, sizeof(DBC_Q_COND->KEY_17));
    MEMCPY_DN(DBC_Q_COND->KEY_18, DBC_Q_COND_N->KEY_18, sizeof(DBC_Q_COND->KEY_18));
    MEMCPY_DN(DBC_Q_COND->KEY_19, DBC_Q_COND_N->KEY_19, sizeof(DBC_Q_COND->KEY_19));
    MEMCPY_DN(DBC_Q_COND->KEY_20, DBC_Q_COND_N->KEY_20, sizeof(DBC_Q_COND->KEY_20));

    DBC_Q_COND->NUM_1 = DBC_Q_COND_N->NUM_1;
    DBC_Q_COND->NUM_2 = DBC_Q_COND_N->NUM_2;
    DBC_Q_COND->NUM_3 = DBC_Q_COND_N->NUM_3;
    DBC_Q_COND->NUM_4 = DBC_Q_COND_N->NUM_4;
    DBC_Q_COND->NUM_5 = DBC_Q_COND_N->NUM_5;
    DBC_Q_COND->NUM_6 = DBC_Q_COND_N->NUM_6;
    DBC_Q_COND->NUM_7 = DBC_Q_COND_N->NUM_7;
    DBC_Q_COND->NUM_8 = DBC_Q_COND_N->NUM_8;
    DBC_Q_COND->NUM_9 = DBC_Q_COND_N->NUM_9;
    DBC_Q_COND->NUM_10 = DBC_Q_COND_N->NUM_10;
}
/*******************************************************************************
    DB_init_condition()
        - Initialize Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_EXT_TAG *DBC_Q_COND_EXT
*******************************************************************************/
void DB_init_condition_ext(struct DBC_Q_COND_EXT_TAG *DBC_Q_COND_EXT)
{
    /* memset by Space */
    memset(DBC_Q_COND_EXT, ' ', sizeof(struct DBC_Q_COND_EXT_TAG));
    DBC_Q_COND_EXT->FROM_SEQ = 0;
    DBC_Q_COND_EXT->TO_SEQ = 0;
    DBC_Q_COND_EXT->PRIO_LEVEL = 0;

    DBC_Q_COND_EXT->NUM_1 = 0;
    DBC_Q_COND_EXT->NUM_2 = 0;
    DBC_Q_COND_EXT->NUM_3 = 0;
    DBC_Q_COND_EXT->NUM_4 = 0;
    DBC_Q_COND_EXT->NUM_5 = 0;
    DBC_Q_COND_EXT->NUM_6 = 0;
    DBC_Q_COND_EXT->NUM_7 = 0;
    DBC_Q_COND_EXT->NUM_8 = 0;
    DBC_Q_COND_EXT->NUM_9 = 0;
    DBC_Q_COND_EXT->NUM_10 = 0;
}

/*******************************************************************************
    DB_add_null_condition()
        - Add Null Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_EXT_N_TAG *DBC_Q_COND_EXT_N
*******************************************************************************/
void DB_add_null_condition_ext(struct DBC_Q_COND_EXT_TAG *DBC_Q_COND_EXT, struct DBC_Q_COND_EXT_N_TAG *DBC_Q_COND_EXT_N)
{
    /* memset by Space */
    memset(DBC_Q_COND_EXT_N, '\0', sizeof(struct DBC_Q_COND_EXT_N_TAG));

    MEMCPY_AN(DBC_Q_COND_EXT_N->FROM_DATE, DBC_Q_COND_EXT->FROM_DATE, sizeof(DBC_Q_COND_EXT->FROM_DATE));
    MEMCPY_AN(DBC_Q_COND_EXT_N->TO_DATE, DBC_Q_COND_EXT->TO_DATE, sizeof(DBC_Q_COND_EXT->TO_DATE));
    MEMCPY_AN(DBC_Q_COND_EXT_N->FROM_TIME, DBC_Q_COND_EXT->FROM_TIME, sizeof(DBC_Q_COND_EXT->FROM_TIME));
    MEMCPY_AN(DBC_Q_COND_EXT_N->TO_TIME, DBC_Q_COND_EXT->TO_TIME, sizeof(DBC_Q_COND_EXT->TO_TIME));
    MEMCPY_AN(DBC_Q_COND_EXT_N->MAT_TYPE, DBC_Q_COND_EXT->MAT_TYPE, sizeof(DBC_Q_COND_EXT->MAT_TYPE));
    MEMCPY_AN(DBC_Q_COND_EXT_N->MAT_GRP, DBC_Q_COND_EXT->MAT_GRP, sizeof(DBC_Q_COND_EXT->MAT_GRP));
    MEMCPY_AN(DBC_Q_COND_EXT_N->RES_ID, DBC_Q_COND_EXT->RES_ID, sizeof(DBC_Q_COND_EXT->RES_ID));
    MEMCPY_AN(DBC_Q_COND_EXT_N->OPER, DBC_Q_COND_EXT->OPER, sizeof(DBC_Q_COND_EXT->OPER));
    MEMCPY_AN(DBC_Q_COND_EXT_N->SPC_SUMMARY_KEY, DBC_Q_COND_EXT->SPC_SUMMARY_KEY, sizeof(DBC_Q_COND_EXT->SPC_SUMMARY_KEY));
    DBC_Q_COND_EXT_N->FROM_SEQ = DBC_Q_COND_EXT->FROM_SEQ;
    DBC_Q_COND_EXT_N->TO_SEQ = DBC_Q_COND_EXT->TO_SEQ;
    DBC_Q_COND_EXT_N->PRIO_LEVEL = DBC_Q_COND_EXT->PRIO_LEVEL;
    MEMCPY_AN(DBC_Q_COND_EXT_N->PRIO_KEY, DBC_Q_COND_EXT->PRIO_KEY, sizeof(DBC_Q_COND_EXT->PRIO_KEY));

    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_1, DBC_Q_COND_EXT->KEY_1, sizeof(DBC_Q_COND_EXT->KEY_1));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_2, DBC_Q_COND_EXT->KEY_2, sizeof(DBC_Q_COND_EXT->KEY_2));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_3, DBC_Q_COND_EXT->KEY_3, sizeof(DBC_Q_COND_EXT->KEY_3));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_4, DBC_Q_COND_EXT->KEY_4, sizeof(DBC_Q_COND_EXT->KEY_4));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_5, DBC_Q_COND_EXT->KEY_5, sizeof(DBC_Q_COND_EXT->KEY_5));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_6, DBC_Q_COND_EXT->KEY_6, sizeof(DBC_Q_COND_EXT->KEY_6));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_7, DBC_Q_COND_EXT->KEY_7, sizeof(DBC_Q_COND_EXT->KEY_7));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_8, DBC_Q_COND_EXT->KEY_8, sizeof(DBC_Q_COND_EXT->KEY_8));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_9, DBC_Q_COND_EXT->KEY_9, sizeof(DBC_Q_COND_EXT->KEY_9));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_10, DBC_Q_COND_EXT->KEY_10, sizeof(DBC_Q_COND_EXT->KEY_10));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_11, DBC_Q_COND_EXT->KEY_11, sizeof(DBC_Q_COND_EXT->KEY_11));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_12, DBC_Q_COND_EXT->KEY_12, sizeof(DBC_Q_COND_EXT->KEY_12));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_13, DBC_Q_COND_EXT->KEY_13, sizeof(DBC_Q_COND_EXT->KEY_13));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_14, DBC_Q_COND_EXT->KEY_14, sizeof(DBC_Q_COND_EXT->KEY_14));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_15, DBC_Q_COND_EXT->KEY_15, sizeof(DBC_Q_COND_EXT->KEY_15));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_16, DBC_Q_COND_EXT->KEY_16, sizeof(DBC_Q_COND_EXT->KEY_16));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_17, DBC_Q_COND_EXT->KEY_17, sizeof(DBC_Q_COND_EXT->KEY_17));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_18, DBC_Q_COND_EXT->KEY_18, sizeof(DBC_Q_COND_EXT->KEY_18));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_19, DBC_Q_COND_EXT->KEY_19, sizeof(DBC_Q_COND_EXT->KEY_19));
    MEMCPY_AN(DBC_Q_COND_EXT_N->KEY_20, DBC_Q_COND_EXT->KEY_20, sizeof(DBC_Q_COND_EXT->KEY_20));

    DBC_Q_COND_EXT_N->NUM_1 = DBC_Q_COND_EXT->NUM_1;
    DBC_Q_COND_EXT_N->NUM_2 = DBC_Q_COND_EXT->NUM_2;
    DBC_Q_COND_EXT_N->NUM_3 = DBC_Q_COND_EXT->NUM_3;
    DBC_Q_COND_EXT_N->NUM_4 = DBC_Q_COND_EXT->NUM_4;
    DBC_Q_COND_EXT_N->NUM_5 = DBC_Q_COND_EXT->NUM_5;
    DBC_Q_COND_EXT_N->NUM_6 = DBC_Q_COND_EXT->NUM_6;
    DBC_Q_COND_EXT_N->NUM_7 = DBC_Q_COND_EXT->NUM_7;
    DBC_Q_COND_EXT_N->NUM_8 = DBC_Q_COND_EXT->NUM_8;
    DBC_Q_COND_EXT_N->NUM_9 = DBC_Q_COND_EXT->NUM_9;
    DBC_Q_COND_EXT_N->NUM_10 = DBC_Q_COND_EXT->NUM_10;
}

/*******************************************************************************
    DB_del_null_condition()
        - Delete Null Condition Struct Function
    Return Value
        - void
    Arguments
        - struct DBC_Q_COND_EXT_N_TAG *DBC_Q_COND_EXT_N
*******************************************************************************/
void DB_del_null_condition_ext(struct DBC_Q_COND_EXT_TAG *DBC_Q_COND_EXT, struct DBC_Q_COND_EXT_N_TAG *DBC_Q_COND_EXT_N)
{
    MEMCPY_DN(DBC_Q_COND_EXT->FROM_DATE, DBC_Q_COND_EXT_N->FROM_DATE, sizeof(DBC_Q_COND_EXT->FROM_DATE));
    MEMCPY_DN(DBC_Q_COND_EXT->TO_DATE, DBC_Q_COND_EXT_N->TO_DATE, sizeof(DBC_Q_COND_EXT->TO_DATE));
    MEMCPY_DN(DBC_Q_COND_EXT->FROM_TIME, DBC_Q_COND_EXT_N->FROM_TIME, sizeof(DBC_Q_COND_EXT->FROM_TIME));
    MEMCPY_DN(DBC_Q_COND_EXT->TO_TIME, DBC_Q_COND_EXT_N->TO_TIME, sizeof(DBC_Q_COND_EXT->TO_TIME));
    MEMCPY_DN(DBC_Q_COND_EXT->MAT_TYPE, DBC_Q_COND_EXT_N->MAT_TYPE, sizeof(DBC_Q_COND_EXT->MAT_TYPE));
    MEMCPY_DN(DBC_Q_COND_EXT->MAT_GRP, DBC_Q_COND_EXT_N->MAT_GRP, sizeof(DBC_Q_COND_EXT->MAT_GRP));
    MEMCPY_DN(DBC_Q_COND_EXT->RES_ID, DBC_Q_COND_EXT_N->RES_ID, sizeof(DBC_Q_COND_EXT->RES_ID));
    MEMCPY_DN(DBC_Q_COND_EXT->OPER, DBC_Q_COND_EXT_N->OPER, sizeof(DBC_Q_COND_EXT->OPER));
    MEMCPY_DN(DBC_Q_COND_EXT->SPC_SUMMARY_KEY, DBC_Q_COND_EXT_N->SPC_SUMMARY_KEY, sizeof(DBC_Q_COND_EXT->SPC_SUMMARY_KEY));
    DBC_Q_COND_EXT->FROM_SEQ = DBC_Q_COND_EXT_N->FROM_SEQ;
    DBC_Q_COND_EXT->TO_SEQ = DBC_Q_COND_EXT_N->TO_SEQ;
    DBC_Q_COND_EXT->PRIO_LEVEL = DBC_Q_COND_EXT_N->PRIO_LEVEL;
    MEMCPY_DN(DBC_Q_COND_EXT->PRIO_KEY, DBC_Q_COND_EXT_N->PRIO_KEY, sizeof(DBC_Q_COND_EXT->PRIO_KEY));

    MEMCPY_DN(DBC_Q_COND_EXT->KEY_1, DBC_Q_COND_EXT_N->KEY_1, sizeof(DBC_Q_COND_EXT->KEY_1));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_2, DBC_Q_COND_EXT_N->KEY_2, sizeof(DBC_Q_COND_EXT->KEY_2));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_3, DBC_Q_COND_EXT_N->KEY_3, sizeof(DBC_Q_COND_EXT->KEY_3));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_4, DBC_Q_COND_EXT_N->KEY_4, sizeof(DBC_Q_COND_EXT->KEY_4));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_5, DBC_Q_COND_EXT_N->KEY_5, sizeof(DBC_Q_COND_EXT->KEY_5));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_6, DBC_Q_COND_EXT_N->KEY_6, sizeof(DBC_Q_COND_EXT->KEY_6));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_7, DBC_Q_COND_EXT_N->KEY_7, sizeof(DBC_Q_COND_EXT->KEY_7));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_8, DBC_Q_COND_EXT_N->KEY_8, sizeof(DBC_Q_COND_EXT->KEY_8));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_9, DBC_Q_COND_EXT_N->KEY_9, sizeof(DBC_Q_COND_EXT->KEY_9));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_10, DBC_Q_COND_EXT_N->KEY_10, sizeof(DBC_Q_COND_EXT->KEY_10));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_11, DBC_Q_COND_EXT_N->KEY_11, sizeof(DBC_Q_COND_EXT->KEY_11));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_12, DBC_Q_COND_EXT_N->KEY_12, sizeof(DBC_Q_COND_EXT->KEY_12));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_13, DBC_Q_COND_EXT_N->KEY_13, sizeof(DBC_Q_COND_EXT->KEY_13));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_14, DBC_Q_COND_EXT_N->KEY_14, sizeof(DBC_Q_COND_EXT->KEY_14));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_15, DBC_Q_COND_EXT_N->KEY_15, sizeof(DBC_Q_COND_EXT->KEY_15));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_16, DBC_Q_COND_EXT_N->KEY_16, sizeof(DBC_Q_COND_EXT->KEY_16));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_17, DBC_Q_COND_EXT_N->KEY_17, sizeof(DBC_Q_COND_EXT->KEY_17));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_18, DBC_Q_COND_EXT_N->KEY_18, sizeof(DBC_Q_COND_EXT->KEY_18));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_19, DBC_Q_COND_EXT_N->KEY_19, sizeof(DBC_Q_COND_EXT->KEY_19));
    MEMCPY_DN(DBC_Q_COND_EXT->KEY_20, DBC_Q_COND_EXT_N->KEY_20, sizeof(DBC_Q_COND_EXT->KEY_20));

    DBC_Q_COND_EXT->NUM_1 = DBC_Q_COND_EXT_N->NUM_1;
    DBC_Q_COND_EXT->NUM_2 = DBC_Q_COND_EXT_N->NUM_2;
    DBC_Q_COND_EXT->NUM_3 = DBC_Q_COND_EXT_N->NUM_3;
    DBC_Q_COND_EXT->NUM_4 = DBC_Q_COND_EXT_N->NUM_4;
    DBC_Q_COND_EXT->NUM_5 = DBC_Q_COND_EXT_N->NUM_5;
    DBC_Q_COND_EXT->NUM_6 = DBC_Q_COND_EXT_N->NUM_6;
    DBC_Q_COND_EXT->NUM_7 = DBC_Q_COND_EXT_N->NUM_7;
    DBC_Q_COND_EXT->NUM_8 = DBC_Q_COND_EXT_N->NUM_8;
    DBC_Q_COND_EXT->NUM_9 = DBC_Q_COND_EXT_N->NUM_9;
    DBC_Q_COND_EXT->NUM_10 = DBC_Q_COND_EXT_N->NUM_10;
}

int DB_get_future_action_save_point_flag()
{
    return DB_future_action_save_point;
}

int DB_get_step_action_save_point_flag()
{
    return DB_step_action_save_point;
}


/* Added by Aiden.Koo. 2012.08.01. for writing log of query interval time */
char ms_start_time[21];
char ms_end_time[21];
double  md_service_total_query_time;
char    mc_stop_recording_rank;
int     mi_rank_by_time_count;
int     mi_rank_by_size_count;

/* Logging SQL Query Interval Time */
double gd_from_interval_time_for_logging_query;

#define                     DBC_MAX_QUERY_RANK_COUNT    10000
struct DBC_LONG_QUERY_TAG   gst_long_query_rank_by_time[DBC_MAX_QUERY_RANK_COUNT];
struct DBC_LONG_QUERY_TAG   gst_long_query_rank_by_size[DBC_MAX_QUERY_RANK_COUNT];

extern char gc_write_interval_time;
extern char gc_collect_performance_info;
extern char gc_collect_long_query_ranking_info;
extern char gc_collect_long_query_ranking_type;

extern void COM_log_write( char c_log_type, 
                           char c_log_error_type, 
                           char c_log_category);

extern void LOG_head(const char *head);
extern void LOG_printf(const char *log, ...);
extern void LOG_get_backtrace_symbol(const unsigned int i_skip_size, char *s_symbol_name);

void DB_get_time_interval(char *s_start_time, char *s_end_time, double *d_interval)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char s_t_start_time[21];
        char s_t_end_time[21];
        double d_t_interval;
    /* EXEC SQL END DECLARE SECTION; */ 


    memcpy(s_t_start_time, s_start_time, sizeof(s_t_start_time));
    memcpy(s_t_end_time, s_end_time, sizeof(s_t_end_time));
    d_t_interval = 0;

    /* EXEC SQL SELECT TO_NUMBER(EXTRACT(SECOND FROM DSINTERVAL)) + 
                    TO_NUMBER(EXTRACT(MINUTE FROM DSINTERVAL)) * 60 + 
                    TO_NUMBER(EXTRACT(HOUR FROM DSINTERVAL))   * 60 * 60 + 
                    TO_NUMBER(EXTRACT(DAY FROM DSINTERVAL))  * 60 * 60* 24 AS SEC
        INTO :d_t_interval
        FROM (
            SELECT TO_DSINTERVAL(TO_TIMESTAMP(:s_t_end_time, 'YYYYMMDDHH24MISSFFTZHTZM') - TO_TIMESTAMP(:s_t_start_time, 'YYYYMMDDHH24MISSFFTZHTZM')) AS DSINTERVAL
            FROM DUAL
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select (((TO_NUMBER(extract( second  from DSINTERVAL))+(\
TO_NUMBER(extract( minute  from DSINTERVAL))* 60))+((TO_NUMBER(extract( hour \
 from DSINTERVAL))* 60)* 60))+(((TO_NUMBER(extract( day  from DSINTERVAL))* 6\
0)* 60)* 24)) SEC into :b0  from (select TO_DSINTERVAL((TO_TIMESTAMP(:b1,'YYY\
YMMDDHH24MISSFFTZHTZM')-TO_TIMESTAMP(:b2,'YYYYMMDDHH24MISSFFTZHTZM'))) DSINTE\
RVAL  from DUAL ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )648;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&d_t_interval;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)s_t_end_time;
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)s_t_start_time;
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) DB_usr_error();
    if (sqlca.sqlcode < 0) DB_usr_error();
}



    *d_interval = d_t_interval;
}

void DB_start_query_timer()
{
    if(gc_write_interval_time == 'Y' || gc_collect_performance_info == 'Y' || gc_collect_long_query_ranking_info == 'Y')
    {
        memset(ms_start_time, 0x00, sizeof(ms_start_time));
        memset(ms_end_time, 0x00, sizeof(ms_end_time));

        DB_get_systime_m(ms_start_time);
    }
}

void DB_set_long_query_rank(char *s_func_name, double d_interval, char c_rank_type);
void DB_swap_long_query_rank(int i_from, int i_to, char c_rank_type);

void DB_stop_query_timer(char *s_func_name, int i_case)
{
    if(gc_write_interval_time == 'Y' || gc_collect_performance_info == 'Y' || gc_collect_long_query_ranking_info == 'Y')
    {
        double d_interval;
        int  i_error_code;
        char s_error_msg[200];
        char s_symbol_name[256];

        i_error_code = DB_error_code;
        memcpy(s_error_msg, DB_error_msg, sizeof(s_error_msg));

        DB_get_systime_m(ms_end_time);
        DB_get_time_interval(ms_start_time, ms_end_time, &d_interval);

        if(gc_write_interval_time == 'Y' && d_interval >= gd_from_interval_time_for_logging_query)
        {
            memset(s_symbol_name, 0x00, sizeof(s_symbol_name));
            LOG_get_backtrace_symbol(3, s_symbol_name);

            LOG_head("Query Interval Time");
            LOG_printf("%s, case = [%d], caller = [%s]", s_func_name, i_case, s_symbol_name);
            LOG_printf("  Start = [%s], End = [%s], Interval = [%f]", ms_start_time, ms_end_time, d_interval);
            COM_log_write('S', 'L', 'Y');
        }

        if(gc_collect_performance_info == 'Y')
        {
            md_service_total_query_time += d_interval;
        }

        if(mc_stop_recording_rank != 'Y' && gc_collect_long_query_ranking_info == 'Y')
        {
            sprintf(s_symbol_name, "%s(%d)", s_func_name, i_case);

            if(gc_collect_long_query_ranking_type == 'T')
            {
                DB_set_long_query_rank(s_symbol_name, d_interval, 'T');
            }
            else if(gc_collect_long_query_ranking_type == 'S')
            {
                DB_set_long_query_rank(s_symbol_name, d_interval, 'S');
            }
            else if(gc_collect_long_query_ranking_type == 'B')
            {
                DB_set_long_query_rank(s_symbol_name, d_interval, 'T');
                DB_set_long_query_rank(s_symbol_name, d_interval, 'S');
            }
        }

        DB_error_code = i_error_code;
        memcpy(DB_error_msg, s_error_msg, sizeof(s_error_msg));
    }
}

void DB_init_service_total_query_time()
{
    md_service_total_query_time = 0;
}

double DB_get_service_total_query_time()
{
    return md_service_total_query_time;
}

void DB_init_long_query_rank_by_time()
{
    memset(gst_long_query_rank_by_time, 0x00, sizeof(struct DBC_LONG_QUERY_TAG) * DBC_MAX_QUERY_RANK_COUNT);
    mi_rank_by_time_count = 0;
}

void DB_init_long_query_rank_by_size()
{
    memset(gst_long_query_rank_by_size, 0x00, sizeof(struct DBC_LONG_QUERY_TAG) * DBC_MAX_QUERY_RANK_COUNT);
    mi_rank_by_size_count = 0;
}

void DB_stop_recording_query_rank()
{
    mc_stop_recording_rank = 'Y';
}

void DB_restart_recording_query_rank()
{
    mc_stop_recording_rank = 0;
}

void DB_set_long_query_rank(char *s_func_name, double d_interval, char c_rank_type)
{
    int                         i;
    int                         b_found;
    struct DBC_LONG_QUERY_TAG   *tmp_query;

    b_found = 0;
    for(i = 0; i < DBC_MAX_QUERY_RANK_COUNT; i++)
    {
        if(c_rank_type == 'T')
        {
            tmp_query = &gst_long_query_rank_by_time[i];
        }
        else if(c_rank_type == 'S')
        {
            tmp_query = &gst_long_query_rank_by_size[i];
        }

        if(strcmp(tmp_query->func_name, s_func_name) == 0)
        {
            b_found = 1;
            break;
        }
        if(tmp_query->func_name[0] == 0x00)
        {
            break;
        }
    }

    if(b_found == 0)
    {
        strcpy(tmp_query->func_name, s_func_name);
        tmp_query->calling_count = 1;
        tmp_query->total_query_sec = d_interval;
        tmp_query->avg_query_sec = d_interval;
        tmp_query->min_query_sec = 0;
        tmp_query->max_query_sec = 0;

        if(c_rank_type == 'T')
        {
            mi_rank_by_time_count++;
        }
        else if(c_rank_type == 'S')
        {
            mi_rank_by_size_count++;
        }
    }
    else
    {
        tmp_query->calling_count++;
        tmp_query->total_query_sec += d_interval;
        tmp_query->avg_query_sec = tmp_query->total_query_sec / tmp_query->calling_count;
    }

    if(d_interval < tmp_query->min_query_sec)
    {
        tmp_query->min_query_sec = d_interval;
    }
    else if(d_interval > tmp_query->max_query_sec)
    {
        tmp_query->max_query_sec = d_interval;
    }
}

void DB_sort_query_rank(char c_rank_type)
{
    struct DBC_LONG_QUERY_TAG   st_query_rank[50];
    struct DBC_LONG_QUERY_TAG   *long_query;
    struct DBC_LONG_QUERY_TAG   *tmp_query;
    int                         i;
    int                         i_rank_count;

    memset(st_query_rank, 0x00, sizeof(struct DBC_LONG_QUERY_TAG) * 50);
    i_rank_count = 0;

    while(1)
    {
        long_query = 0x00;
        for(i = 0; i < DBC_MAX_QUERY_RANK_COUNT; i++)
        {
            if(c_rank_type == 'T')
            {
                if(i >= mi_rank_by_time_count)
                {
                    break;
                }
                tmp_query = &gst_long_query_rank_by_time[i];
            }
            else if(c_rank_type == 'S')
            {
                if(i >= mi_rank_by_size_count)
                {
                    break;
                }
                tmp_query = &gst_long_query_rank_by_size[i];
            }

            if(tmp_query->checked == 'Y')
            {
                continue;
            }

            if(long_query == 0x00)
            {
                long_query = tmp_query;
            }
            else
            {
                if(long_query->avg_query_sec < tmp_query->avg_query_sec)
                {
                    long_query = tmp_query;
                }
            }
        } /* end for */

        if(long_query == 0x00)
        {
            break;
        }

        long_query->checked = 'Y';
        st_query_rank[i_rank_count++] = *long_query;

        if(i_rank_count >= 50)
        {
            break;
        }
    } /* end while */

    for(i = 0; i < i_rank_count; i++)
    {
        if(c_rank_type == 'T')
        {
            gst_long_query_rank_by_time[i] = st_query_rank[i];
        }
        else if(c_rank_type == 'S')
        {
            gst_long_query_rank_by_size[i] = st_query_rank[i];
        }
    }

    if(i_rank_count < 50)
    {
        for(i = i_rank_count; i < 50; i++)
        {
            if(c_rank_type == 'T')
            {
                memset(&gst_long_query_rank_by_time[i], 0x00, sizeof(struct DBC_LONG_QUERY_TAG));
            }
            else if(c_rank_type == 'S')
            {
                memset(&gst_long_query_rank_by_size[i], 0x00, sizeof(struct DBC_LONG_QUERY_TAG));
            }
        }
    }
}

/* End add */
