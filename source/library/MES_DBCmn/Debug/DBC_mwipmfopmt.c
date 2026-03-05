
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
           char  filnam[18];
};
static const struct sqlcxp sqlfpn =
{
    17,
    "DBC_mwipmfopmt.pc"
};


static unsigned int sqlctx = 9142987;


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
            void  *sqhstv[110];
   unsigned int   sqhstl[110];
            int   sqhsts[110];
            void  *sqindv[110];
            int   sqinds[110];
   unsigned int   sqharm[110];
   unsigned int   *sqharc[110];
   unsigned short  sqadto[110];
   unsigned short  sqtdso[110];
} sqlstm = {13,110};

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

 static const char *sq0008 = 
"_20 ,DATA_TBL_1 ,DATA_TBL_2 ,DATA_TB\
L_3 ,DATA_TBL_4 ,DATA_TBL_5 ,DATA_TBL_6 ,DATA_TBL_7 ,DATA_TBL_8 ,DATA_TBL_9 ,\
DATA_TBL_10 ,DATA_TBL_11 ,DATA_TBL_12 ,DATA_TBL_13 ,DATA_TBL_14 ,DATA_TBL_15 \
,DATA_TBL_16 ,DATA_TBL_17 ,DATA_TBL_18 ,DATA_TBL_19 ,DATA_TBL_20 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from MWIPMFOPMT where FACTORY=\
:b0 order by OPTION_NAME asc             ";

 static const char *sq0009 = 
"_20 ,DATA_TBL_1 ,DATA_TBL_2 ,DATA_TB\
L_3 ,DATA_TBL_4 ,DATA_TBL_5 ,DATA_TBL_6 ,DATA_TBL_7 ,DATA_TBL_8 ,DATA_TBL_9 ,\
DATA_TBL_10 ,DATA_TBL_11 ,DATA_TBL_12 ,DATA_TBL_13 ,DATA_TBL_14 ,DATA_TBL_15 \
,DATA_TBL_16 ,DATA_TBL_17 ,DATA_TBL_18 ,DATA_TBL_19 ,DATA_TBL_20 ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from MWIPMFOPMT where (FACTORY\
=:b0 and SYS_PMT_FLAG=:b1) order by OPTION_NAME asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1936,0,4,44,0,0,110,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,
0,
460,0,0,2,1948,0,4,299,0,0,110,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,
915,0,0,3,82,0,4,558,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
942,0,0,4,64,0,2,593,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
965,0,0,5,65,0,2,599,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
988,0,0,6,1794,0,3,628,0,0,108,108,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1435,0,0,7,1795,0,5,867,0,0,108,108,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1882,0,0,8,1409,0,9,1117,0,0,1,1,0,1,0,1,97,0,0,
1901,0,0,9,1432,0,9,1235,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1924,0,0,8,0,0,13,1264,0,0,108,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2371,0,0,9,0,0,13,1376,0,0,108,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2818,0,0,8,0,0,15,1515,0,0,0,0,0,1,0,
2833,0,0,9,0,0,15,1519,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipmfopmt.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2008/01/15 16:22:18
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2007 MIRACOM,INC.
**
*********************************************************************/
/* EXEC SQL BEGIN DECLARE SECTION; */ 

/*     EXEC SQL INCLUDE DBC_COMMON_N;
 */ 
/*********************************************************************
**
**    File Name   : dbc_common_n.h
**    Description : DB Common Null Structure Definition Header File
**    Create date : 2010/01/19 10:10:57
**
**    Generated by DB Common Generator
**    Copyright (C), MIRACOM,INC.
**
*********************************************************************/

#ifndef __SQL_COMMON_N_LOADED
#define __SQL_COMMON_N_LOADED

#include "dbc_q_cond_n.h"
#include "dbc_null_data_type_n.h"

#include "DBC_mmsgmsgdef_n.h"
#include "DBC_mgcmtbldef_n.h"
#include "DBC_mgcmtbldat_n.h"
#include "DBC_msecfundef_n.h"
#include "DBC_msecgrpdef_n.h"
#include "DBC_msecgrpfun_n.h"
#include "DBC_msecusrdef_n.h"
#include "DBC_msecusrfun_n.h"
#include "DBC_msecprvgrp_n.h"
#include "DBC_msecprvusr_n.h"
#include "DBC_msecprvdef_n.h"
#include "DBC_msecusrext_n.h"
#include "DBC_mseclickey_n.h"
#include "DBC_msecflxhdr_n.h"
#include "DBC_matrnamdef_n.h"
#include "DBC_matrnamsts_n.h"
#include "DBC_matrnamhis_n.h"
#include "DBC_mwipfacdef_n.h"
#include "DBC_mwipcaldef_n.h"
#include "DBC_mwipfaccmf_n.h"
#include "DBC_mwipmatdef_n.h"
#include "DBC_mwiplotsts_n.h"
#include "DBC_mwiprwkdef_n.h"
#include "DBC_mwipfacshp_n.h"
#include "DBC_mwipmatflw_n.h"
#include "DBC_mwipflwdef_n.h"
#include "DBC_mwipflwopr_n.h"
#include "DBC_mwipoprdef_n.h"
#include "DBC_mwipcytdef_n.h"
#include "DBC_mwipordsts_n.h"
#include "DBC_mwipplndef_n.h"
#include "DBC_mwipplnlot_n.h"
#include "DBC_mwipwrkord_n.h"
#include "DBC_mwipcoldef_n.h"
#include "DBC_mwiplothis_n.h"
#include "DBC_mwiplotbns_n.h"
#include "DBC_mwiplotlos_n.h"
#include "DBC_mwiplotspl_n.h"
#include "DBC_mwiplotmrg_n.h"
#include "DBC_mwiplotcmb_n.h"
#include "DBC_mwiplothld_n.h"
#include "DBC_mwiplotlsm_n.h"
#include "DBC_mwiplotbnm_n.h"
#include "DBC_mwiprmasts_n.h"
#include "DBC_mwiplotshp_n.h"
#include "DBC_mwiplotrwk_n.h"
#include "DBC_mwipmhdsts_n.h"
#include "DBC_mwipqtmdef_n.h"
#include "DBC_mwipqtmhis_n.h"
#include "DBC_mwipbakdef_n.h"
#include "DBC_mwiplotbat_n.h"
#include "DBC_mwiplotdft_n.h"
#include "DBC_mwiprepdef_n.h"
#include "DBC_mwiplotrep_n.h"
#include "DBC_mwipsltdef_n.h"
#include "DBC_mwipsltsts_n.h"
#include "DBC_mwipslthis_n.h"
#include "DBC_mwipsltlos_n.h"
/* 2013.06.14. Aiden. Sublot based Loss/Bonus History */
#include "DBC_mwipsltbos_n.h"
#include "DBC_mwipsltcvh_n.h"
#include "DBC_mrascrrdef_n.h"
#include "DBC_mrascrrhis_n.h"
#include "DBC_mrascrrgrp_n.h"
#include "DBC_mrascrrmfo_n.h"
#include "DBC_mrascgrrel_n.h"
#include "DBC_mwipcrrlot_n.h"
#include "DBC_mrascevdef_n.h"
#include "DBC_mwiplotdel_n.h"
#include "DBC_mwipgrddef_n.h"
#include "DBC_mwipylddef_n.h"
#include "DBC_mwipmfodef_n.h"
#include "DBC_mwipmfopmt_n.h"
#include "DBC_mwipidgdef_n.h"
#include "DBC_mwipidgrul_n.h"
#include "DBC_mwipidgrel_n.h"
#include "DBC_mwipidgskv_n.h"
#include "DBC_mwipidghis_n.h"
#include "DBC_mwipbatrul_n.h"
#include "DBC_mwipbatrel_n.h"
#include "DBC_mwipbatrsv_n.h"
#include "DBC_mwipbatrit_n.h"
#include "DBC_mwipbatdef_n.h"
#include "DBC_mwipbathis_n.h"
#include "DBC_mwiprshlot_n.h"
#include "DBC_mwiplotcvh_n.h"
#include "DBC_mwiplotcvm_n.h"
#include "DBC_mwipfatdef_n.h"
#include "DBC_mwipfatact_n.h"
#include "DBC_mwipfatsvc_n.h"
#include "DBC_mwipfatcnd_n.h"
#include "DBC_mwiplotmvh_n.h"
#include "DBC_mwipsltmvh_n.h"
#include "DBC_mwiplotqtm_n.h"
#include "DBC_mwipstpdef_n.h"
#include "DBC_mwipstpsts_n.h"
#include "DBC_mwipstpmfo_n.h"
#include "DBC_mwipstphis_n.h"
#include "DBC_mrasevndef_n.h"
#include "DBC_mrasresdef_n.h"
#include "DBC_mrasresevn_n.h"
#include "DBC_mrasreslab_n.h"
#include "DBC_mrasreshis_n.h"
#include "DBC_mrasreslth_n.h"
#include "DBC_mrasresdwh_n.h"
#include "DBC_mrassrsdef_n.h"
#include "DBC_mrassrslth_n.h"
#include "DBC_mrassrslot_n.h"
#include "DBC_mrassrshis_n.h"
#include "DBC_mrassrsevn_n.h"
#include "DBC_mraspmssec_n.h"
#include "DBC_mraspmssts_n.h"
#include "DBC_mrasqrydef_n.h"
#include "DBC_mrasshtcat_n.h"
#include "DBC_mrasshtdef_n.h"
#include "DBC_mrasshtdat_n.h"
#include "DBC_mrasshtrst_n.h"
#include "DBC_mrastoltye_n.h"
#include "DBC_mrastevdef_n.h"
#include "DBC_mrastoldef_n.h"
#include "DBC_mrastolevn_n.h"
#include "DBC_mrastolhis_n.h"
#include "DBC_mrastoldft_n.h"
#include "DBC_mraspotdef_n.h"
#include "DBC_mraspothis_n.h"
#include "DBC_mbomsetdef_n.h"
#include "DBC_mbomsetver_n.h"
#include "DBC_mbomsetmat_n.h"
#include "DBC_mbomlotass_n.h"
#include "DBC_mbomlotash_n.h"
#include "DBC_minvmathis_n.h"
#include "DBC_minvmatsts_n.h"
#include "DBC_minvsrlsts_n.h"
#include "DBC_medcchrdef_n.h"
#include "DBC_medccolchr_n.h"
#include "DBC_medccoldef_n.h"
#include "DBC_medclotdat_n.h"
#include "DBC_medcresdat_n.h"
#include "DBC_medccolver_n.h"
#include "DBC_medccolunt_n.h"
#include "DBC_mfmbudrloc_n.h"
#include "DBC_mfmbudrdef_n.h"
#include "DBC_mfmbresloc_n.h"
#include "DBC_mfmbfaclyt_n.h"
#include "DBC_mfmbresimg_n.h"
#include "DBC_mfmbevtclr_n.h"
#include "DBC_mfmbenvdef_n.h"
#include "DBC_mfmbgrpusr_n.h"
#include "DBC_mspcchtdef_n.h"
#include "DBC_mspcspehis_n.h"
#include "DBC_mspcedcdat_n.h"
#include "DBC_mspccaldat_n.h"
#include "DBC_mspcoochis_n.h"
#include "DBC_mspcchtusr_n.h"
#include "DBC_mspcsumdat_n.h"
#include "DBC_mspcalmhis_n.h"
#include "DBC_mspcsetdef_n.h"
#include "DBC_mspcchtset_n.h"
#include "DBC_mspcdelhis_n.h"
#include "DBC_mspcchtmfo_n.h"
#include "DBC_mspcprtdef_n.h"
#include "DBC_mspcchtunt_n.h"
#include "DBC_spccore_join_n.h"
#include "DBC_mrcprcpdef_n.h"
#include "DBC_mrcprcpver_n.h"
#include "DBC_mrcppraver_n.h"
#include "DBC_mrcpmfodef_n.h"
#include "DBC_mrcplotrcp_n.h"
#include "DBC_mrcplotpra_n.h"
#include "DBC_mrcplothis_n.h"
#include "DBC_mrcpprahis_n.h"
#include "DBC_mrcpsltrcp_n.h"
#include "DBC_mrcpsltpra_n.h"
#include "DBC_mrcpslthis_n.h"
#include "DBC_mrcpslphis_n.h"
#include "DBC_mpoplbldef_n.h"
#include "DBC_mpoplblimg_n.h"
#include "DBC_mpoplbldgn_n.h"
#include "DBC_mpopmatlbl_n.h"
#include "DBC_mpoplotprh_n.h"
#include "DBC_mrtddspdef_n.h"
#include "DBC_mrtddspopr_n.h"
#include "DBC_mrtddspres_n.h"
#include "DBC_mrtdruldef_n.h"
#include "DBC_mrtdrulitm_n.h"
#include "DBC_mrtdevncon_n.h"
#include "DBC_mrtdevnifh_n.h"
#include "DBC_mrtdevnifs_n.h"
#include "DBC_mrtdlotpdh_n.h"
#include "DBC_mrtdlotpds_n.h"
#include "DBC_mrtdrefopr_n.h"
#include "DBC_mrtdresopr_n.h"
#include "DBC_malmmsgdef_n.h"
#include "DBC_malmmsghis_n.h"
#include "DBC_malmrcvdef_n.h"
#include "DBC_malmmfores_n.h"
#include "DBC_mqcmsmpdef_n.h"
#include "DBC_mqcmsetver_n.h"
#include "DBC_mqcmsetitm_n.h"
#include "DBC_mqcmsetdef_n.h"
#include "DBC_mqcmitmdef_n.h"
#include "DBC_mqcmmatdef_n.h"
#include "DBC_qcmcore_join_n.h"
#include "DBC_mqcmbatsts_n.h"
#include "DBC_mqcmitmsts_n.h"
#include "DBC_mqcmbathis_n.h"
#include "DBC_mqcmbatisp_n.h"
#include "DBC_mqcmitmisp_n.h"
#include "DBC_mqcmbatdft_n.h"
#include "DBC_mqcmitmdft_n.h"
#include "DBC_wipcore_join_n.h"
#include "DBC_seccore_join_n.h"
#include "DBC_edccore_join_n.h"
#include "DBC_rascore_join_n.h"
#include "DBC_fmbcore_join_n.h"
#include "DBC_rcpcore_join_n.h"
#include "DBC_rtdcore_join_n.h"
#include "DBC_mtmplothis_n.h"
#include "DBC_mwiplotyld_n.h"
#include "DBC_mtmpreshis_n.h"
#include "DBC_mtmpatrhis_n.h"
#include "DBC_mtmpcrrhis_n.h"
#include "DBC_mrasrsgdef_n.h"
#include "DBC_mrasrsgres_n.h"
#include "DBC_mrasresmfo_n.h"
#include "DBC_msvmdftver_n.h"
#include "DBC_msvmkeyver_n.h"
#include "DBC_msvmmbrdef_n.h"
#include "DBC_msvmsvcdef_n.h"
#include "DBC_msvmsvcmbr_n.h"
#include "DBC_msvmsvcurt_n.h"
#include "DBC_mmsgbbshis_n.h"
#include "DBC_mmsgbbsseq_n.h"
#include "DBC_mmsgbbstxt_n.h"
#include "DBC_mrascrrshs_n.h"
#include "DBC_mbasglbdef_n.h"
#include "DBC_mbasglbpmt_n.h"
#include "DBC_mwiplotrds_n.h"
#include "DBC_mwipsltrds_n.h"
#include "DBC_medcchrfml_n.h"
#include "DBC_mbasscrdef_n.h"
#include "DBC_mwipoprinv_n.h"
#include "DBC_mwiptollth_n.h"
#include "DBC_mrastolrsh_n.h"
#include "DBC_mbasscrrel_n.h"
#include "DBC_mbasscrcnd_n.h"
#include "DBC_mwipcrrlth_n.h"

#include "DBC_mbasinqdef_n.h"
#include "DBC_mbassqldef_n.h"

#include "DBC_mwiplotlnr_n.h"
#include "DBC_mgcmlagdat_n.h"
#include "DBC_medccolche_n.h"

/* Add by J.S. 2011.10.20 for log performance, error */
#include "DBC_msvmpfmlog_n.h"
#include "DBC_msvmerrlog_n.h"

/* Add by Kelly, 2012.04.04 */
#include "DBC_mwipbindef_n.h"
#include "DBC_mwipbinver_n.h"
#include "DBC_mwipbinunt_n.h"
#include "DBC_mwipbingrd_n.h"
#include "DBC_mwipbinrel_n.h"
#include "DBC_mwipbinhis_n.h"
#include "DBC_mwipbinshs_n.h"
#include "DBC_mwipbinhss_n.h"
#include "DBC_mwipbinssh_n.h"
#include "DBC_mwippridef_n.h"
#include "DBC_mwipbinfml_n.h"
#include "DBC_mwipbinsph_n.h"

/* add by patrick, 2012,04,10 */
#include "DBC_mbasdofdef_n.h"
#include "DBC_mbasdoddef_n.h"
#include "DBC_mbasdotdef_n.h"

/* Add by J.S. 2012.04.17 */
#include "DBC_mmsgbbsfil_n.h"

/* Add by DM KIM 2012.04.18 */
#include "DBC_mwiptstpgm_n.h"

/* Add by bs.Kwak, 2012.03.29 */
#include "DBC_mqcgactdef_n.h"
#include "DBC_mqcglotdef_n.h"
#include "DBC_mqcglothis_n.h"
#include "DBC_mqcgmforel_n.h"
#include "DBC_mqcgsltdef_n.h"
#include "DBC_mqcgslthis_n.h"
#include "DBC_mqcgsmpdef_n.h"
#include "DBC_mwiplyddef_n.h"
#include "DBC_mwiplydcod_n.h"

/* Add by JYPARK, 2012.04.16 (SPM Module Table) */
#include "DBC_medcspmver_n.h"
#include "DBC_mspmchrdsv_n.h"
#include "DBC_mspmrelchr_n.h"
#include "DBC_mspmreldef_n.h"
#include "DBC_mspmrelver_n.h"
#include "DBC_mspmatrsts_n.h"
#include "DBC_mspmatrhis_n.h"
#include "DBC_mspmdocimg_n.h"
#include "DBC_spmcore_join_n.h"

#include "DBC_mwemstpact_n.h"
#include "DBC_mwemstpdef_n.h"
#include "DBC_mwemstpsts_n.h"
#include "DBC_mwemstsdef_n.h"
#include "DBC_mwemtyedef_n.h"
#include "DBC_mwemactact_n.h"
#include "DBC_mwemactcnd_n.h"
#include "DBC_mwemactdef_n.h"
#include "DBC_mwemprcdef_n.h"
#include "DBC_mwemprcstp_n.h"
#include "DBC_mwemprcusr_n.h"
#include "DBC_mwemevnsts_n.h"
#include "DBC_mwemevnhis_n.h"
#include "DBC_mwemevnsvl_n.h"
#include "DBC_mwemevnsvh_n.h"


/* Add by YGSON, 2012.11.16 (BAS Module Table) */
#include "DBC_mbaschklsa_n.h"
#include "DBC_mbaschklsh_n.h"
#include "DBC_mbaschklsq_n.h"
#include "DBC_mbaschklsr_n.h"
#include "DBC_mbaschklst_n.h"
#include "DBC_mbaschkqry_n.h"

/* Add by JU.Heo 2012.12.03 */
#include "DBC_medcprtdef_n.h"

/* Add for Batch Process */
#include "DBC_mbatprcdef_n.h"
#include "DBC_mbatprcsts_n.h"
#include "DBC_mbatprchis_n.h"

/* Add by Mihwa 2013.01.21 */
#include "DBC_mrastolrel_n.h"

/* Add by Aiden 2013.08.28 */
#include "DBC_mwipidgscf_n.h"
/* Add by Aiden 2014.03.05 */
#include "DBC_mwiplotfqt_n.h"
/* Added by YJJung 2015.08.11 */
#include "DBC_mrtdrulext_n.h"

/* Added By YJJung 2016.02.17 */
#include "DBC_mspcrulext_n.h"
#include "DBC_mspcoocext_n.h"

#include "DBC_mpoplbldex_n.h"
#include "DBC_mgcmtblhis_n.h"
#include "DBC_mgcmdathis_n.h"

/* Direct View ฐüทร */
#include "DBC_mdnmdvuhdr_n.h"
#include "DBC_mdnmdvwcnd_n.h"
#include "DBC_mdnmdvwhdr_n.h"
#include "DBC_mdnmsqldef_n.h"
#include "DBC_mdnmsqlhis_n.h"

#include "DBC_mtmppothis_n.h"
#endif /* __SQL_COMMON_N_LOADED */

/* EXEC SQL END DECLARE SECTION; */ 


/* SQL Common Header File */
#include "DBC_common.h"


/* SQL Error Handling */
/* EXEC SQL WHENEVER SQLERROR DO DB_usr_error(); */ 

/* EXEC SQL WHENEVER NOT FOUND DO DB_usr_error(); */ 


/* Function Declaration */
void DBC_add_null_mwipmfopmt(struct MWIPMFOPMT_N_TAG *MWIPMFOPMT_N, struct MWIPMFOPMT_TAG *MWIPMFOPMT);
void DBC_del_null_mwipmfopmt(struct MWIPMFOPMT_N_TAG *MWIPMFOPMT_N, struct MWIPMFOPMT_TAG *MWIPMFOPMT);


/* SQL SELECT Function */
void DBC_select_mwipmfopmt(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         OPTION_NAME,
                         OPTION_DESC,
                         SYS_PMT_FLAG,
                         KEY_PMT_1,
                         KEY_PMT_2,
                         KEY_PMT_3,
                         KEY_PMT_4,
                         KEY_PMT_5,
                         KEY_OPT_1,
                         KEY_OPT_2,
                         KEY_OPT_3,
                         KEY_OPT_4,
                         KEY_OPT_5,
                         KEY_FMT_1,
                         KEY_FMT_2,
                         KEY_FMT_3,
                         KEY_FMT_4,
                         KEY_FMT_5,
                         KEY_TBL_1,
                         KEY_TBL_2,
                         KEY_TBL_3,
                         KEY_TBL_4,
                         KEY_TBL_5,
                         DATA_PMT_1,
                         DATA_PMT_2,
                         DATA_PMT_3,
                         DATA_PMT_4,
                         DATA_PMT_5,
                         DATA_PMT_6,
                         DATA_PMT_7,
                         DATA_PMT_8,
                         DATA_PMT_9,
                         DATA_PMT_10,
                         DATA_PMT_11,
                         DATA_PMT_12,
                         DATA_PMT_13,
                         DATA_PMT_14,
                         DATA_PMT_15,
                         DATA_PMT_16,
                         DATA_PMT_17,
                         DATA_PMT_18,
                         DATA_PMT_19,
                         DATA_PMT_20,
                         DATA_OPT_1,
                         DATA_OPT_2,
                         DATA_OPT_3,
                         DATA_OPT_4,
                         DATA_OPT_5,
                         DATA_OPT_6,
                         DATA_OPT_7,
                         DATA_OPT_8,
                         DATA_OPT_9,
                         DATA_OPT_10,
                         DATA_OPT_11,
                         DATA_OPT_12,
                         DATA_OPT_13,
                         DATA_OPT_14,
                         DATA_OPT_15,
                         DATA_OPT_16,
                         DATA_OPT_17,
                         DATA_OPT_18,
                         DATA_OPT_19,
                         DATA_OPT_20,
                         DATA_FMT_1,
                         DATA_FMT_2,
                         DATA_FMT_3,
                         DATA_FMT_4,
                         DATA_FMT_5,
                         DATA_FMT_6,
                         DATA_FMT_7,
                         DATA_FMT_8,
                         DATA_FMT_9,
                         DATA_FMT_10,
                         DATA_FMT_11,
                         DATA_FMT_12,
                         DATA_FMT_13,
                         DATA_FMT_14,
                         DATA_FMT_15,
                         DATA_FMT_16,
                         DATA_FMT_17,
                         DATA_FMT_18,
                         DATA_FMT_19,
                         DATA_FMT_20,
                         DATA_TBL_1,
                         DATA_TBL_2,
                         DATA_TBL_3,
                         DATA_TBL_4,
                         DATA_TBL_5,
                         DATA_TBL_6,
                         DATA_TBL_7,
                         DATA_TBL_8,
                         DATA_TBL_9,
                         DATA_TBL_10,
                         DATA_TBL_11,
                         DATA_TBL_12,
                         DATA_TBL_13,
                         DATA_TBL_14,
                         DATA_TBL_15,
                         DATA_TBL_16,
                         DATA_TBL_17,
                         DATA_TBL_18,
                         DATA_TBL_19,
                         DATA_TBL_20,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MWIPMFOPMT_N.FACTORY,
                    :MWIPMFOPMT_N.OPTION_NAME,
                    :MWIPMFOPMT_N.OPTION_DESC,
                    :MWIPMFOPMT_N.SYS_PMT_FLAG,
                    :MWIPMFOPMT_N.KEY_PMT_1,
                    :MWIPMFOPMT_N.KEY_PMT_2,
                    :MWIPMFOPMT_N.KEY_PMT_3,
                    :MWIPMFOPMT_N.KEY_PMT_4,
                    :MWIPMFOPMT_N.KEY_PMT_5,
                    :MWIPMFOPMT_N.KEY_OPT_1,
                    :MWIPMFOPMT_N.KEY_OPT_2,
                    :MWIPMFOPMT_N.KEY_OPT_3,
                    :MWIPMFOPMT_N.KEY_OPT_4,
                    :MWIPMFOPMT_N.KEY_OPT_5,
                    :MWIPMFOPMT_N.KEY_FMT_1,
                    :MWIPMFOPMT_N.KEY_FMT_2,
                    :MWIPMFOPMT_N.KEY_FMT_3,
                    :MWIPMFOPMT_N.KEY_FMT_4,
                    :MWIPMFOPMT_N.KEY_FMT_5,
                    :MWIPMFOPMT_N.KEY_TBL_1,
                    :MWIPMFOPMT_N.KEY_TBL_2,
                    :MWIPMFOPMT_N.KEY_TBL_3,
                    :MWIPMFOPMT_N.KEY_TBL_4,
                    :MWIPMFOPMT_N.KEY_TBL_5,
                    :MWIPMFOPMT_N.DATA_PMT_1,
                    :MWIPMFOPMT_N.DATA_PMT_2,
                    :MWIPMFOPMT_N.DATA_PMT_3,
                    :MWIPMFOPMT_N.DATA_PMT_4,
                    :MWIPMFOPMT_N.DATA_PMT_5,
                    :MWIPMFOPMT_N.DATA_PMT_6,
                    :MWIPMFOPMT_N.DATA_PMT_7,
                    :MWIPMFOPMT_N.DATA_PMT_8,
                    :MWIPMFOPMT_N.DATA_PMT_9,
                    :MWIPMFOPMT_N.DATA_PMT_10,
                    :MWIPMFOPMT_N.DATA_PMT_11,
                    :MWIPMFOPMT_N.DATA_PMT_12,
                    :MWIPMFOPMT_N.DATA_PMT_13,
                    :MWIPMFOPMT_N.DATA_PMT_14,
                    :MWIPMFOPMT_N.DATA_PMT_15,
                    :MWIPMFOPMT_N.DATA_PMT_16,
                    :MWIPMFOPMT_N.DATA_PMT_17,
                    :MWIPMFOPMT_N.DATA_PMT_18,
                    :MWIPMFOPMT_N.DATA_PMT_19,
                    :MWIPMFOPMT_N.DATA_PMT_20,
                    :MWIPMFOPMT_N.DATA_OPT_1,
                    :MWIPMFOPMT_N.DATA_OPT_2,
                    :MWIPMFOPMT_N.DATA_OPT_3,
                    :MWIPMFOPMT_N.DATA_OPT_4,
                    :MWIPMFOPMT_N.DATA_OPT_5,
                    :MWIPMFOPMT_N.DATA_OPT_6,
                    :MWIPMFOPMT_N.DATA_OPT_7,
                    :MWIPMFOPMT_N.DATA_OPT_8,
                    :MWIPMFOPMT_N.DATA_OPT_9,
                    :MWIPMFOPMT_N.DATA_OPT_10,
                    :MWIPMFOPMT_N.DATA_OPT_11,
                    :MWIPMFOPMT_N.DATA_OPT_12,
                    :MWIPMFOPMT_N.DATA_OPT_13,
                    :MWIPMFOPMT_N.DATA_OPT_14,
                    :MWIPMFOPMT_N.DATA_OPT_15,
                    :MWIPMFOPMT_N.DATA_OPT_16,
                    :MWIPMFOPMT_N.DATA_OPT_17,
                    :MWIPMFOPMT_N.DATA_OPT_18,
                    :MWIPMFOPMT_N.DATA_OPT_19,
                    :MWIPMFOPMT_N.DATA_OPT_20,
                    :MWIPMFOPMT_N.DATA_FMT_1,
                    :MWIPMFOPMT_N.DATA_FMT_2,
                    :MWIPMFOPMT_N.DATA_FMT_3,
                    :MWIPMFOPMT_N.DATA_FMT_4,
                    :MWIPMFOPMT_N.DATA_FMT_5,
                    :MWIPMFOPMT_N.DATA_FMT_6,
                    :MWIPMFOPMT_N.DATA_FMT_7,
                    :MWIPMFOPMT_N.DATA_FMT_8,
                    :MWIPMFOPMT_N.DATA_FMT_9,
                    :MWIPMFOPMT_N.DATA_FMT_10,
                    :MWIPMFOPMT_N.DATA_FMT_11,
                    :MWIPMFOPMT_N.DATA_FMT_12,
                    :MWIPMFOPMT_N.DATA_FMT_13,
                    :MWIPMFOPMT_N.DATA_FMT_14,
                    :MWIPMFOPMT_N.DATA_FMT_15,
                    :MWIPMFOPMT_N.DATA_FMT_16,
                    :MWIPMFOPMT_N.DATA_FMT_17,
                    :MWIPMFOPMT_N.DATA_FMT_18,
                    :MWIPMFOPMT_N.DATA_FMT_19,
                    :MWIPMFOPMT_N.DATA_FMT_20,
                    :MWIPMFOPMT_N.DATA_TBL_1,
                    :MWIPMFOPMT_N.DATA_TBL_2,
                    :MWIPMFOPMT_N.DATA_TBL_3,
                    :MWIPMFOPMT_N.DATA_TBL_4,
                    :MWIPMFOPMT_N.DATA_TBL_5,
                    :MWIPMFOPMT_N.DATA_TBL_6,
                    :MWIPMFOPMT_N.DATA_TBL_7,
                    :MWIPMFOPMT_N.DATA_TBL_8,
                    :MWIPMFOPMT_N.DATA_TBL_9,
                    :MWIPMFOPMT_N.DATA_TBL_10,
                    :MWIPMFOPMT_N.DATA_TBL_11,
                    :MWIPMFOPMT_N.DATA_TBL_12,
                    :MWIPMFOPMT_N.DATA_TBL_13,
                    :MWIPMFOPMT_N.DATA_TBL_14,
                    :MWIPMFOPMT_N.DATA_TBL_15,
                    :MWIPMFOPMT_N.DATA_TBL_16,
                    :MWIPMFOPMT_N.DATA_TBL_17,
                    :MWIPMFOPMT_N.DATA_TBL_18,
                    :MWIPMFOPMT_N.DATA_TBL_19,
                    :MWIPMFOPMT_N.DATA_TBL_20,
                    :MWIPMFOPMT_N.CREATE_USER_ID,
                    :MWIPMFOPMT_N.CREATE_TIME,
                    :MWIPMFOPMT_N.UPDATE_USER_ID,
                    :MWIPMFOPMT_N.UPDATE_TIME
                FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND OPTION_NAME = :MWIPMFOPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,OPTION_NAME ,OPTION_DESC ,SYS_PMT_FLAG ,KEY_P\
MT_1 ,KEY_PMT_2 ,KEY_PMT_3 ,KEY_PMT_4 ,KEY_PMT_5 ,KEY_OPT_1 ,KEY_OPT_2 ,KEY_\
OPT_3 ,KEY_OPT_4 ,KEY_OPT_5 ,KEY_FMT_1 ,KEY_FMT_2 ,KEY_FMT_3 ,KEY_FMT_4 ,KEY\
_FMT_5 ,KEY_TBL_1 ,KEY_TBL_2 ,KEY_TBL_3 ,KEY_TBL_4 ,KEY_TBL_5 ,DATA_PMT_1 ,D\
ATA_PMT_2 ,DATA_PMT_3 ,DATA_PMT_4 ,DATA_PMT_5 ,DATA_PMT_6 ,DATA_PMT_7 ,DATA_\
PMT_8 ,DATA_PMT_9 ,DATA_PMT_10 ,DATA_PMT_11 ,DATA_PMT_12 ,DATA_PMT_13 ,DATA_\
PMT_14 ,DATA_PMT_15 ,DATA_PMT_16 ,DATA_PMT_17 ,DATA_PMT_18 ,DATA_PMT_19 ,DAT\
A_PMT_20 ,DATA_OPT_1 ,DATA_OPT_2 ,DATA_OPT_3 ,DATA_OPT_4 ,DATA_OPT_5 ,DATA_O\
PT_6 ,DATA_OPT_7 ,DATA_OPT_8 ,DATA_OPT_9 ,DATA_OPT_10 ,DATA_OPT_11 ,DATA_OPT\
_12 ,DATA_OPT_13 ,DATA_OPT_14 ,DATA_OPT_15 ,DATA_OPT_16 ,DATA_OPT_17 ,DATA_O\
PT_18 ,DATA_OPT_19 ,DATA_OPT_20 ,DATA_FMT_1 ,DATA_FMT_2 ,DATA_FMT_3 ,DATA_FM\
T_4 ,DATA_FMT_5 ,DATA_FMT_6 ,DATA_FMT_7 ,DATA_FMT_8 ,DATA_FMT_9 ,DATA_FMT_10\
 ,DATA_FMT_11 ,DATA_FMT_12 ,DATA_FMT_13 ,DATA_FMT_14 ,DATA_FMT_15 ,DATA_FMT_\
16 ,DATA_FMT_17 ,DATA_FMT_18 ,DATA_FMT_19 ,DATA_FMT");
            sqlstm.stmt = "_20 ,DATA_TBL_1 ,DATA_TBL_2 ,DATA_TBL_3 ,DATA_TB\
L_4 ,DATA_TBL_5 ,DATA_TBL_6 ,DATA_TBL_7 ,DATA_TBL_8 ,DATA_TBL_9 ,DATA_TBL_10 \
,DATA_TBL_11 ,DATA_TBL_12 ,DATA_TBL_13 ,DATA_TBL_14 ,DATA_TBL_15 ,DATA_TBL_16\
 ,DATA_TBL_17 ,DATA_TBL_18 ,DATA_TBL_19 ,DATA_TBL_20 ,CREATE_USER_ID ,CREATE_\
TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b\
9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,\
:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b\
40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55\
,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:\
b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b8\
6,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b10\
1,:b102,:b103,:b104,:b105,:b106,:b107  from MWIPMFOPMT where (FACTORY=:b0 and\
 OPTION_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
            sqlstm.sqhstl[78] = (unsigned int  )2;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
            sqlstm.sqhstl[79] = (unsigned int  )2;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
            sqlstm.sqhstl[80] = (unsigned int  )2;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
            sqlstm.sqhstl[81] = (unsigned int  )2;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
            sqlstm.sqhstl[82] = (unsigned int  )2;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
            sqlstm.sqhstl[83] = (unsigned int  )2;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
            sqlstm.sqhstl[100] = (unsigned int  )21;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
            sqlstm.sqhstl[102] = (unsigned int  )21;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[104] = (unsigned int  )21;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
            sqlstm.sqhstl[105] = (unsigned int  )15;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[106] = (unsigned int  )21;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[108] = (unsigned int  )11;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
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


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    }
    DB_stop_query_timer("DBC_select_mwipmfopmt", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipmfopmt_for_update(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         OPTION_NAME,
                         OPTION_DESC,
                         SYS_PMT_FLAG,
                         KEY_PMT_1,
                         KEY_PMT_2,
                         KEY_PMT_3,
                         KEY_PMT_4,
                         KEY_PMT_5,
                         KEY_OPT_1,
                         KEY_OPT_2,
                         KEY_OPT_3,
                         KEY_OPT_4,
                         KEY_OPT_5,
                         KEY_FMT_1,
                         KEY_FMT_2,
                         KEY_FMT_3,
                         KEY_FMT_4,
                         KEY_FMT_5,
                         KEY_TBL_1,
                         KEY_TBL_2,
                         KEY_TBL_3,
                         KEY_TBL_4,
                         KEY_TBL_5,
                         DATA_PMT_1,
                         DATA_PMT_2,
                         DATA_PMT_3,
                         DATA_PMT_4,
                         DATA_PMT_5,
                         DATA_PMT_6,
                         DATA_PMT_7,
                         DATA_PMT_8,
                         DATA_PMT_9,
                         DATA_PMT_10,
                         DATA_PMT_11,
                         DATA_PMT_12,
                         DATA_PMT_13,
                         DATA_PMT_14,
                         DATA_PMT_15,
                         DATA_PMT_16,
                         DATA_PMT_17,
                         DATA_PMT_18,
                         DATA_PMT_19,
                         DATA_PMT_20,
                         DATA_OPT_1,
                         DATA_OPT_2,
                         DATA_OPT_3,
                         DATA_OPT_4,
                         DATA_OPT_5,
                         DATA_OPT_6,
                         DATA_OPT_7,
                         DATA_OPT_8,
                         DATA_OPT_9,
                         DATA_OPT_10,
                         DATA_OPT_11,
                         DATA_OPT_12,
                         DATA_OPT_13,
                         DATA_OPT_14,
                         DATA_OPT_15,
                         DATA_OPT_16,
                         DATA_OPT_17,
                         DATA_OPT_18,
                         DATA_OPT_19,
                         DATA_OPT_20,
                         DATA_FMT_1,
                         DATA_FMT_2,
                         DATA_FMT_3,
                         DATA_FMT_4,
                         DATA_FMT_5,
                         DATA_FMT_6,
                         DATA_FMT_7,
                         DATA_FMT_8,
                         DATA_FMT_9,
                         DATA_FMT_10,
                         DATA_FMT_11,
                         DATA_FMT_12,
                         DATA_FMT_13,
                         DATA_FMT_14,
                         DATA_FMT_15,
                         DATA_FMT_16,
                         DATA_FMT_17,
                         DATA_FMT_18,
                         DATA_FMT_19,
                         DATA_FMT_20,
                         DATA_TBL_1,
                         DATA_TBL_2,
                         DATA_TBL_3,
                         DATA_TBL_4,
                         DATA_TBL_5,
                         DATA_TBL_6,
                         DATA_TBL_7,
                         DATA_TBL_8,
                         DATA_TBL_9,
                         DATA_TBL_10,
                         DATA_TBL_11,
                         DATA_TBL_12,
                         DATA_TBL_13,
                         DATA_TBL_14,
                         DATA_TBL_15,
                         DATA_TBL_16,
                         DATA_TBL_17,
                         DATA_TBL_18,
                         DATA_TBL_19,
                         DATA_TBL_20,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MWIPMFOPMT_N.FACTORY,
                    :MWIPMFOPMT_N.OPTION_NAME,
                    :MWIPMFOPMT_N.OPTION_DESC,
                    :MWIPMFOPMT_N.SYS_PMT_FLAG,
                    :MWIPMFOPMT_N.KEY_PMT_1,
                    :MWIPMFOPMT_N.KEY_PMT_2,
                    :MWIPMFOPMT_N.KEY_PMT_3,
                    :MWIPMFOPMT_N.KEY_PMT_4,
                    :MWIPMFOPMT_N.KEY_PMT_5,
                    :MWIPMFOPMT_N.KEY_OPT_1,
                    :MWIPMFOPMT_N.KEY_OPT_2,
                    :MWIPMFOPMT_N.KEY_OPT_3,
                    :MWIPMFOPMT_N.KEY_OPT_4,
                    :MWIPMFOPMT_N.KEY_OPT_5,
                    :MWIPMFOPMT_N.KEY_FMT_1,
                    :MWIPMFOPMT_N.KEY_FMT_2,
                    :MWIPMFOPMT_N.KEY_FMT_3,
                    :MWIPMFOPMT_N.KEY_FMT_4,
                    :MWIPMFOPMT_N.KEY_FMT_5,
                    :MWIPMFOPMT_N.KEY_TBL_1,
                    :MWIPMFOPMT_N.KEY_TBL_2,
                    :MWIPMFOPMT_N.KEY_TBL_3,
                    :MWIPMFOPMT_N.KEY_TBL_4,
                    :MWIPMFOPMT_N.KEY_TBL_5,
                    :MWIPMFOPMT_N.DATA_PMT_1,
                    :MWIPMFOPMT_N.DATA_PMT_2,
                    :MWIPMFOPMT_N.DATA_PMT_3,
                    :MWIPMFOPMT_N.DATA_PMT_4,
                    :MWIPMFOPMT_N.DATA_PMT_5,
                    :MWIPMFOPMT_N.DATA_PMT_6,
                    :MWIPMFOPMT_N.DATA_PMT_7,
                    :MWIPMFOPMT_N.DATA_PMT_8,
                    :MWIPMFOPMT_N.DATA_PMT_9,
                    :MWIPMFOPMT_N.DATA_PMT_10,
                    :MWIPMFOPMT_N.DATA_PMT_11,
                    :MWIPMFOPMT_N.DATA_PMT_12,
                    :MWIPMFOPMT_N.DATA_PMT_13,
                    :MWIPMFOPMT_N.DATA_PMT_14,
                    :MWIPMFOPMT_N.DATA_PMT_15,
                    :MWIPMFOPMT_N.DATA_PMT_16,
                    :MWIPMFOPMT_N.DATA_PMT_17,
                    :MWIPMFOPMT_N.DATA_PMT_18,
                    :MWIPMFOPMT_N.DATA_PMT_19,
                    :MWIPMFOPMT_N.DATA_PMT_20,
                    :MWIPMFOPMT_N.DATA_OPT_1,
                    :MWIPMFOPMT_N.DATA_OPT_2,
                    :MWIPMFOPMT_N.DATA_OPT_3,
                    :MWIPMFOPMT_N.DATA_OPT_4,
                    :MWIPMFOPMT_N.DATA_OPT_5,
                    :MWIPMFOPMT_N.DATA_OPT_6,
                    :MWIPMFOPMT_N.DATA_OPT_7,
                    :MWIPMFOPMT_N.DATA_OPT_8,
                    :MWIPMFOPMT_N.DATA_OPT_9,
                    :MWIPMFOPMT_N.DATA_OPT_10,
                    :MWIPMFOPMT_N.DATA_OPT_11,
                    :MWIPMFOPMT_N.DATA_OPT_12,
                    :MWIPMFOPMT_N.DATA_OPT_13,
                    :MWIPMFOPMT_N.DATA_OPT_14,
                    :MWIPMFOPMT_N.DATA_OPT_15,
                    :MWIPMFOPMT_N.DATA_OPT_16,
                    :MWIPMFOPMT_N.DATA_OPT_17,
                    :MWIPMFOPMT_N.DATA_OPT_18,
                    :MWIPMFOPMT_N.DATA_OPT_19,
                    :MWIPMFOPMT_N.DATA_OPT_20,
                    :MWIPMFOPMT_N.DATA_FMT_1,
                    :MWIPMFOPMT_N.DATA_FMT_2,
                    :MWIPMFOPMT_N.DATA_FMT_3,
                    :MWIPMFOPMT_N.DATA_FMT_4,
                    :MWIPMFOPMT_N.DATA_FMT_5,
                    :MWIPMFOPMT_N.DATA_FMT_6,
                    :MWIPMFOPMT_N.DATA_FMT_7,
                    :MWIPMFOPMT_N.DATA_FMT_8,
                    :MWIPMFOPMT_N.DATA_FMT_9,
                    :MWIPMFOPMT_N.DATA_FMT_10,
                    :MWIPMFOPMT_N.DATA_FMT_11,
                    :MWIPMFOPMT_N.DATA_FMT_12,
                    :MWIPMFOPMT_N.DATA_FMT_13,
                    :MWIPMFOPMT_N.DATA_FMT_14,
                    :MWIPMFOPMT_N.DATA_FMT_15,
                    :MWIPMFOPMT_N.DATA_FMT_16,
                    :MWIPMFOPMT_N.DATA_FMT_17,
                    :MWIPMFOPMT_N.DATA_FMT_18,
                    :MWIPMFOPMT_N.DATA_FMT_19,
                    :MWIPMFOPMT_N.DATA_FMT_20,
                    :MWIPMFOPMT_N.DATA_TBL_1,
                    :MWIPMFOPMT_N.DATA_TBL_2,
                    :MWIPMFOPMT_N.DATA_TBL_3,
                    :MWIPMFOPMT_N.DATA_TBL_4,
                    :MWIPMFOPMT_N.DATA_TBL_5,
                    :MWIPMFOPMT_N.DATA_TBL_6,
                    :MWIPMFOPMT_N.DATA_TBL_7,
                    :MWIPMFOPMT_N.DATA_TBL_8,
                    :MWIPMFOPMT_N.DATA_TBL_9,
                    :MWIPMFOPMT_N.DATA_TBL_10,
                    :MWIPMFOPMT_N.DATA_TBL_11,
                    :MWIPMFOPMT_N.DATA_TBL_12,
                    :MWIPMFOPMT_N.DATA_TBL_13,
                    :MWIPMFOPMT_N.DATA_TBL_14,
                    :MWIPMFOPMT_N.DATA_TBL_15,
                    :MWIPMFOPMT_N.DATA_TBL_16,
                    :MWIPMFOPMT_N.DATA_TBL_17,
                    :MWIPMFOPMT_N.DATA_TBL_18,
                    :MWIPMFOPMT_N.DATA_TBL_19,
                    :MWIPMFOPMT_N.DATA_TBL_20,
                    :MWIPMFOPMT_N.CREATE_USER_ID,
                    :MWIPMFOPMT_N.CREATE_TIME,
                    :MWIPMFOPMT_N.UPDATE_USER_ID,
                    :MWIPMFOPMT_N.UPDATE_TIME
                FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND OPTION_NAME = :MWIPMFOPMT_N.OPTION_NAME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,OPTION_NAME ,OPTION_DESC ,SYS_PMT_FLAG ,KEY_P\
MT_1 ,KEY_PMT_2 ,KEY_PMT_3 ,KEY_PMT_4 ,KEY_PMT_5 ,KEY_OPT_1 ,KEY_OPT_2 ,KEY_\
OPT_3 ,KEY_OPT_4 ,KEY_OPT_5 ,KEY_FMT_1 ,KEY_FMT_2 ,KEY_FMT_3 ,KEY_FMT_4 ,KEY\
_FMT_5 ,KEY_TBL_1 ,KEY_TBL_2 ,KEY_TBL_3 ,KEY_TBL_4 ,KEY_TBL_5 ,DATA_PMT_1 ,D\
ATA_PMT_2 ,DATA_PMT_3 ,DATA_PMT_4 ,DATA_PMT_5 ,DATA_PMT_6 ,DATA_PMT_7 ,DATA_\
PMT_8 ,DATA_PMT_9 ,DATA_PMT_10 ,DATA_PMT_11 ,DATA_PMT_12 ,DATA_PMT_13 ,DATA_\
PMT_14 ,DATA_PMT_15 ,DATA_PMT_16 ,DATA_PMT_17 ,DATA_PMT_18 ,DATA_PMT_19 ,DAT\
A_PMT_20 ,DATA_OPT_1 ,DATA_OPT_2 ,DATA_OPT_3 ,DATA_OPT_4 ,DATA_OPT_5 ,DATA_O\
PT_6 ,DATA_OPT_7 ,DATA_OPT_8 ,DATA_OPT_9 ,DATA_OPT_10 ,DATA_OPT_11 ,DATA_OPT\
_12 ,DATA_OPT_13 ,DATA_OPT_14 ,DATA_OPT_15 ,DATA_OPT_16 ,DATA_OPT_17 ,DATA_O\
PT_18 ,DATA_OPT_19 ,DATA_OPT_20 ,DATA_FMT_1 ,DATA_FMT_2 ,DATA_FMT_3 ,DATA_FM\
T_4 ,DATA_FMT_5 ,DATA_FMT_6 ,DATA_FMT_7 ,DATA_FMT_8 ,DATA_FMT_9 ,DATA_FMT_10\
 ,DATA_FMT_11 ,DATA_FMT_12 ,DATA_FMT_13 ,DATA_FMT_14 ,DATA_FMT_15 ,DATA_FMT_\
16 ,DATA_FMT_17 ,DATA_FMT_18 ,DATA_FMT_19 ,DATA_FMT");
            sqlstm.stmt = "_20 ,DATA_TBL_1 ,DATA_TBL_2 ,DATA_TBL_3 ,DATA_TB\
L_4 ,DATA_TBL_5 ,DATA_TBL_6 ,DATA_TBL_7 ,DATA_TBL_8 ,DATA_TBL_9 ,DATA_TBL_10 \
,DATA_TBL_11 ,DATA_TBL_12 ,DATA_TBL_13 ,DATA_TBL_14 ,DATA_TBL_15 ,DATA_TBL_16\
 ,DATA_TBL_17 ,DATA_TBL_18 ,DATA_TBL_19 ,DATA_TBL_20 ,CREATE_USER_ID ,CREATE_\
TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b\
9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,\
:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b\
40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55\
,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:\
b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b8\
6,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b10\
1,:b102,:b103,:b104,:b105,:b106,:b107  from MWIPMFOPMT where (FACTORY=:b0 and\
 OPTION_NAME=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )460;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
            sqlstm.sqhstl[78] = (unsigned int  )2;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
            sqlstm.sqhstl[79] = (unsigned int  )2;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
            sqlstm.sqhstl[80] = (unsigned int  )2;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
            sqlstm.sqhstl[81] = (unsigned int  )2;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
            sqlstm.sqhstl[82] = (unsigned int  )2;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
            sqlstm.sqhstl[83] = (unsigned int  )2;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
            sqlstm.sqhstl[100] = (unsigned int  )21;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
            sqlstm.sqhstl[102] = (unsigned int  )21;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[104] = (unsigned int  )21;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
            sqlstm.sqhstl[105] = (unsigned int  )15;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[106] = (unsigned int  )21;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[108] = (unsigned int  )11;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
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


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    }
    DB_stop_query_timer("DBC_select_mwipmfopmt_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipmfopmt_scalar(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND OPTION_NAME = :MWIPMFOPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPMFOPMT where\
 (FACTORY=:b1 and OPTION_NAME=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )915;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&d_value;
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
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


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_select_mwipmfopmt_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipmfopmt(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND OPTION_NAME = :MWIPMFOPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPMFOPMT  where (FACTORY=:b0 and \
OPTION_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )942;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
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


            break;

        case 2:
            /* EXEC SQL DELETE FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND SYS_PMT_FLAG = :MWIPMFOPMT_N.SYS_PMT_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPMFOPMT  where (FACTORY=:b0 and \
SYS_PMT_FLAG=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )965;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
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


            break;



        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_delete_mwipmfopmt", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipmfopmt(struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPMFOPMT (
                    FACTORY,
                    OPTION_NAME,
                    OPTION_DESC,
                    SYS_PMT_FLAG,
                    KEY_PMT_1,
                    KEY_PMT_2,
                    KEY_PMT_3,
                    KEY_PMT_4,
                    KEY_PMT_5,
                    KEY_OPT_1,
                    KEY_OPT_2,
                    KEY_OPT_3,
                    KEY_OPT_4,
                    KEY_OPT_5,
                    KEY_FMT_1,
                    KEY_FMT_2,
                    KEY_FMT_3,
                    KEY_FMT_4,
                    KEY_FMT_5,
                    KEY_TBL_1,
                    KEY_TBL_2,
                    KEY_TBL_3,
                    KEY_TBL_4,
                    KEY_TBL_5,
                    DATA_PMT_1,
                    DATA_PMT_2,
                    DATA_PMT_3,
                    DATA_PMT_4,
                    DATA_PMT_5,
                    DATA_PMT_6,
                    DATA_PMT_7,
                    DATA_PMT_8,
                    DATA_PMT_9,
                    DATA_PMT_10,
                    DATA_PMT_11,
                    DATA_PMT_12,
                    DATA_PMT_13,
                    DATA_PMT_14,
                    DATA_PMT_15,
                    DATA_PMT_16,
                    DATA_PMT_17,
                    DATA_PMT_18,
                    DATA_PMT_19,
                    DATA_PMT_20,
                    DATA_OPT_1,
                    DATA_OPT_2,
                    DATA_OPT_3,
                    DATA_OPT_4,
                    DATA_OPT_5,
                    DATA_OPT_6,
                    DATA_OPT_7,
                    DATA_OPT_8,
                    DATA_OPT_9,
                    DATA_OPT_10,
                    DATA_OPT_11,
                    DATA_OPT_12,
                    DATA_OPT_13,
                    DATA_OPT_14,
                    DATA_OPT_15,
                    DATA_OPT_16,
                    DATA_OPT_17,
                    DATA_OPT_18,
                    DATA_OPT_19,
                    DATA_OPT_20,
                    DATA_FMT_1,
                    DATA_FMT_2,
                    DATA_FMT_3,
                    DATA_FMT_4,
                    DATA_FMT_5,
                    DATA_FMT_6,
                    DATA_FMT_7,
                    DATA_FMT_8,
                    DATA_FMT_9,
                    DATA_FMT_10,
                    DATA_FMT_11,
                    DATA_FMT_12,
                    DATA_FMT_13,
                    DATA_FMT_14,
                    DATA_FMT_15,
                    DATA_FMT_16,
                    DATA_FMT_17,
                    DATA_FMT_18,
                    DATA_FMT_19,
                    DATA_FMT_20,
                    DATA_TBL_1,
                    DATA_TBL_2,
                    DATA_TBL_3,
                    DATA_TBL_4,
                    DATA_TBL_5,
                    DATA_TBL_6,
                    DATA_TBL_7,
                    DATA_TBL_8,
                    DATA_TBL_9,
                    DATA_TBL_10,
                    DATA_TBL_11,
                    DATA_TBL_12,
                    DATA_TBL_13,
                    DATA_TBL_14,
                    DATA_TBL_15,
                    DATA_TBL_16,
                    DATA_TBL_17,
                    DATA_TBL_18,
                    DATA_TBL_19,
                    DATA_TBL_20,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
        )
        VALUES (
                    :MWIPMFOPMT_N.FACTORY,
                    :MWIPMFOPMT_N.OPTION_NAME,
                    :MWIPMFOPMT_N.OPTION_DESC,
                    :MWIPMFOPMT_N.SYS_PMT_FLAG,
                    :MWIPMFOPMT_N.KEY_PMT_1,
                    :MWIPMFOPMT_N.KEY_PMT_2,
                    :MWIPMFOPMT_N.KEY_PMT_3,
                    :MWIPMFOPMT_N.KEY_PMT_4,
                    :MWIPMFOPMT_N.KEY_PMT_5,
                    :MWIPMFOPMT_N.KEY_OPT_1,
                    :MWIPMFOPMT_N.KEY_OPT_2,
                    :MWIPMFOPMT_N.KEY_OPT_3,
                    :MWIPMFOPMT_N.KEY_OPT_4,
                    :MWIPMFOPMT_N.KEY_OPT_5,
                    :MWIPMFOPMT_N.KEY_FMT_1,
                    :MWIPMFOPMT_N.KEY_FMT_2,
                    :MWIPMFOPMT_N.KEY_FMT_3,
                    :MWIPMFOPMT_N.KEY_FMT_4,
                    :MWIPMFOPMT_N.KEY_FMT_5,
                    :MWIPMFOPMT_N.KEY_TBL_1,
                    :MWIPMFOPMT_N.KEY_TBL_2,
                    :MWIPMFOPMT_N.KEY_TBL_3,
                    :MWIPMFOPMT_N.KEY_TBL_4,
                    :MWIPMFOPMT_N.KEY_TBL_5,
                    :MWIPMFOPMT_N.DATA_PMT_1,
                    :MWIPMFOPMT_N.DATA_PMT_2,
                    :MWIPMFOPMT_N.DATA_PMT_3,
                    :MWIPMFOPMT_N.DATA_PMT_4,
                    :MWIPMFOPMT_N.DATA_PMT_5,
                    :MWIPMFOPMT_N.DATA_PMT_6,
                    :MWIPMFOPMT_N.DATA_PMT_7,
                    :MWIPMFOPMT_N.DATA_PMT_8,
                    :MWIPMFOPMT_N.DATA_PMT_9,
                    :MWIPMFOPMT_N.DATA_PMT_10,
                    :MWIPMFOPMT_N.DATA_PMT_11,
                    :MWIPMFOPMT_N.DATA_PMT_12,
                    :MWIPMFOPMT_N.DATA_PMT_13,
                    :MWIPMFOPMT_N.DATA_PMT_14,
                    :MWIPMFOPMT_N.DATA_PMT_15,
                    :MWIPMFOPMT_N.DATA_PMT_16,
                    :MWIPMFOPMT_N.DATA_PMT_17,
                    :MWIPMFOPMT_N.DATA_PMT_18,
                    :MWIPMFOPMT_N.DATA_PMT_19,
                    :MWIPMFOPMT_N.DATA_PMT_20,
                    :MWIPMFOPMT_N.DATA_OPT_1,
                    :MWIPMFOPMT_N.DATA_OPT_2,
                    :MWIPMFOPMT_N.DATA_OPT_3,
                    :MWIPMFOPMT_N.DATA_OPT_4,
                    :MWIPMFOPMT_N.DATA_OPT_5,
                    :MWIPMFOPMT_N.DATA_OPT_6,
                    :MWIPMFOPMT_N.DATA_OPT_7,
                    :MWIPMFOPMT_N.DATA_OPT_8,
                    :MWIPMFOPMT_N.DATA_OPT_9,
                    :MWIPMFOPMT_N.DATA_OPT_10,
                    :MWIPMFOPMT_N.DATA_OPT_11,
                    :MWIPMFOPMT_N.DATA_OPT_12,
                    :MWIPMFOPMT_N.DATA_OPT_13,
                    :MWIPMFOPMT_N.DATA_OPT_14,
                    :MWIPMFOPMT_N.DATA_OPT_15,
                    :MWIPMFOPMT_N.DATA_OPT_16,
                    :MWIPMFOPMT_N.DATA_OPT_17,
                    :MWIPMFOPMT_N.DATA_OPT_18,
                    :MWIPMFOPMT_N.DATA_OPT_19,
                    :MWIPMFOPMT_N.DATA_OPT_20,
                    :MWIPMFOPMT_N.DATA_FMT_1,
                    :MWIPMFOPMT_N.DATA_FMT_2,
                    :MWIPMFOPMT_N.DATA_FMT_3,
                    :MWIPMFOPMT_N.DATA_FMT_4,
                    :MWIPMFOPMT_N.DATA_FMT_5,
                    :MWIPMFOPMT_N.DATA_FMT_6,
                    :MWIPMFOPMT_N.DATA_FMT_7,
                    :MWIPMFOPMT_N.DATA_FMT_8,
                    :MWIPMFOPMT_N.DATA_FMT_9,
                    :MWIPMFOPMT_N.DATA_FMT_10,
                    :MWIPMFOPMT_N.DATA_FMT_11,
                    :MWIPMFOPMT_N.DATA_FMT_12,
                    :MWIPMFOPMT_N.DATA_FMT_13,
                    :MWIPMFOPMT_N.DATA_FMT_14,
                    :MWIPMFOPMT_N.DATA_FMT_15,
                    :MWIPMFOPMT_N.DATA_FMT_16,
                    :MWIPMFOPMT_N.DATA_FMT_17,
                    :MWIPMFOPMT_N.DATA_FMT_18,
                    :MWIPMFOPMT_N.DATA_FMT_19,
                    :MWIPMFOPMT_N.DATA_FMT_20,
                    :MWIPMFOPMT_N.DATA_TBL_1,
                    :MWIPMFOPMT_N.DATA_TBL_2,
                    :MWIPMFOPMT_N.DATA_TBL_3,
                    :MWIPMFOPMT_N.DATA_TBL_4,
                    :MWIPMFOPMT_N.DATA_TBL_5,
                    :MWIPMFOPMT_N.DATA_TBL_6,
                    :MWIPMFOPMT_N.DATA_TBL_7,
                    :MWIPMFOPMT_N.DATA_TBL_8,
                    :MWIPMFOPMT_N.DATA_TBL_9,
                    :MWIPMFOPMT_N.DATA_TBL_10,
                    :MWIPMFOPMT_N.DATA_TBL_11,
                    :MWIPMFOPMT_N.DATA_TBL_12,
                    :MWIPMFOPMT_N.DATA_TBL_13,
                    :MWIPMFOPMT_N.DATA_TBL_14,
                    :MWIPMFOPMT_N.DATA_TBL_15,
                    :MWIPMFOPMT_N.DATA_TBL_16,
                    :MWIPMFOPMT_N.DATA_TBL_17,
                    :MWIPMFOPMT_N.DATA_TBL_18,
                    :MWIPMFOPMT_N.DATA_TBL_19,
                    :MWIPMFOPMT_N.DATA_TBL_20,
                    :MWIPMFOPMT_N.CREATE_USER_ID,
                    :MWIPMFOPMT_N.CREATE_TIME,
                    :MWIPMFOPMT_N.UPDATE_USER_ID,
                    :MWIPMFOPMT_N.UPDATE_TIME
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 110;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPMFOPMT (FACTORY,OPTION_NAME,OPTION_DESC,SYS_PMT_FLAG,\
KEY_PMT_1,KEY_PMT_2,KEY_PMT_3,KEY_PMT_4,KEY_PMT_5,KEY_OPT_1,KEY_OPT_2,KEY_OP\
T_3,KEY_OPT_4,KEY_OPT_5,KEY_FMT_1,KEY_FMT_2,KEY_FMT_3,KEY_FMT_4,KEY_FMT_5,KE\
Y_TBL_1,KEY_TBL_2,KEY_TBL_3,KEY_TBL_4,KEY_TBL_5,DATA_PMT_1,DATA_PMT_2,DATA_P\
MT_3,DATA_PMT_4,DATA_PMT_5,DATA_PMT_6,DATA_PMT_7,DATA_PMT_8,DATA_PMT_9,DATA_\
PMT_10,DATA_PMT_11,DATA_PMT_12,DATA_PMT_13,DATA_PMT_14,DATA_PMT_15,DATA_PMT_\
16,DATA_PMT_17,DATA_PMT_18,DATA_PMT_19,DATA_PMT_20,DATA_OPT_1,DATA_OPT_2,DAT\
A_OPT_3,DATA_OPT_4,DATA_OPT_5,DATA_OPT_6,DATA_OPT_7,DATA_OPT_8,DATA_OPT_9,DA\
TA_OPT_10,DATA_OPT_11,DATA_OPT_12,DATA_OPT_13,DATA_OPT_14,DATA_OPT_15,DATA_O\
PT_16,DATA_OPT_17,DATA_OPT_18,DATA_OPT_19,DATA_OPT_20,DATA_FMT_1,DATA_FMT_2,\
DATA_FMT_3,DATA_FMT_4,DATA_FMT_5,DATA_FMT_6,DATA_FMT_7,DATA_FMT_8,DATA_FMT_9\
,DATA_FMT_10,DATA_FMT_11,DATA_FMT_12,DATA_FMT_13,DATA_FMT_14,DATA_FMT_15,DAT\
A_FMT_16,DATA_FMT_17,DATA_FMT_18,DATA_FMT_19,DATA_FMT_20,DATA_TBL_1,DATA_TBL\
_2,DATA_TBL_3,DATA_TBL_4,DATA_TBL_5,DATA_TB");
    sqlstm.stmt = "L_6,DATA_TBL_7,DATA_TBL_8,DATA_TBL_9,DATA_TBL_10,DATA_TB\
L_11,DATA_TBL_12,DATA_TBL_13,DATA_TBL_14,DATA_TBL_15,DATA_TBL_16,DATA_TBL_17,\
DATA_TBL_18,DATA_TBL_19,DATA_TBL_20,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID\
,UPDATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,\
:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43\
,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:\
b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b7\
4,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,\
:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b1\
04,:b105,:b106,:b107)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )988;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
    sqlstm.sqhstl[3] = (unsigned int  )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
    sqlstm.sqhstl[9] = (unsigned int  )2;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
    sqlstm.sqhstl[14] = (unsigned int  )2;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
    sqlstm.sqhstl[15] = (unsigned int  )2;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
    sqlstm.sqhstl[16] = (unsigned int  )2;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
    sqlstm.sqhstl[17] = (unsigned int  )2;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
    sqlstm.sqhstl[18] = (unsigned int  )2;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
    sqlstm.sqhstl[24] = (unsigned int  )21;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
    sqlstm.sqhstl[25] = (unsigned int  )21;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
    sqlstm.sqhstl[26] = (unsigned int  )21;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
    sqlstm.sqhstl[27] = (unsigned int  )21;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
    sqlstm.sqhstl[29] = (unsigned int  )21;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
    sqlstm.sqhstl[31] = (unsigned int  )21;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
    sqlstm.sqhstl[32] = (unsigned int  )21;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
    sqlstm.sqhstl[33] = (unsigned int  )21;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
    sqlstm.sqhstl[34] = (unsigned int  )21;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
    sqlstm.sqhstl[36] = (unsigned int  )21;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
    sqlstm.sqhstl[38] = (unsigned int  )21;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
    sqlstm.sqhstl[39] = (unsigned int  )21;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
    sqlstm.sqhstl[40] = (unsigned int  )21;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
    sqlstm.sqhstl[41] = (unsigned int  )21;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
    sqlstm.sqhstl[43] = (unsigned int  )21;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
    sqlstm.sqhstl[50] = (unsigned int  )2;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
    sqlstm.sqhstl[58] = (unsigned int  )2;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
    sqlstm.sqhstl[59] = (unsigned int  )2;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
    sqlstm.sqhstl[60] = (unsigned int  )2;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
    sqlstm.sqhstl[61] = (unsigned int  )2;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
    sqlstm.sqhstl[62] = (unsigned int  )2;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
    sqlstm.sqhstl[64] = (unsigned int  )2;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
    sqlstm.sqhstl[65] = (unsigned int  )2;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
    sqlstm.sqhstl[66] = (unsigned int  )2;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
    sqlstm.sqhstl[67] = (unsigned int  )2;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
    sqlstm.sqhstl[68] = (unsigned int  )2;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
    sqlstm.sqhstl[69] = (unsigned int  )2;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
    sqlstm.sqhstl[70] = (unsigned int  )2;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
    sqlstm.sqhstl[71] = (unsigned int  )2;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
    sqlstm.sqhstl[72] = (unsigned int  )2;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
    sqlstm.sqhstl[73] = (unsigned int  )2;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
    sqlstm.sqhstl[74] = (unsigned int  )2;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
    sqlstm.sqhstl[75] = (unsigned int  )2;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
    sqlstm.sqhstl[76] = (unsigned int  )2;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
    sqlstm.sqhstl[77] = (unsigned int  )2;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
    sqlstm.sqhstl[78] = (unsigned int  )2;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
    sqlstm.sqhstl[79] = (unsigned int  )2;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
    sqlstm.sqhstl[80] = (unsigned int  )2;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
    sqlstm.sqhstl[81] = (unsigned int  )2;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
    sqlstm.sqhstl[82] = (unsigned int  )2;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
    sqlstm.sqhstl[83] = (unsigned int  )2;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
    sqlstm.sqhstl[84] = (unsigned int  )21;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
    sqlstm.sqhstl[85] = (unsigned int  )21;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
    sqlstm.sqhstl[86] = (unsigned int  )21;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
    sqlstm.sqhstl[87] = (unsigned int  )21;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
    sqlstm.sqhstl[88] = (unsigned int  )21;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
    sqlstm.sqhstl[89] = (unsigned int  )21;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
    sqlstm.sqhstl[90] = (unsigned int  )21;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
    sqlstm.sqhstl[91] = (unsigned int  )21;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
    sqlstm.sqhstl[92] = (unsigned int  )21;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
    sqlstm.sqhstl[93] = (unsigned int  )21;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
    sqlstm.sqhstl[94] = (unsigned int  )21;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
    sqlstm.sqhstl[95] = (unsigned int  )21;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
    sqlstm.sqhstl[96] = (unsigned int  )21;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
    sqlstm.sqhstl[97] = (unsigned int  )21;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
    sqlstm.sqhstl[98] = (unsigned int  )21;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
    sqlstm.sqhstl[99] = (unsigned int  )21;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
    sqlstm.sqhstl[100] = (unsigned int  )21;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
    sqlstm.sqhstl[101] = (unsigned int  )21;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
    sqlstm.sqhstl[102] = (unsigned int  )21;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
    sqlstm.sqhstl[103] = (unsigned int  )21;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
    sqlstm.sqhstl[104] = (unsigned int  )21;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
    sqlstm.sqhstl[105] = (unsigned int  )15;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
    sqlstm.sqhstl[106] = (unsigned int  )21;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
    sqlstm.sqhstl[107] = (unsigned int  )15;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mwipmfopmt", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipmfopmt(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPMFOPMT SET
                    OPTION_DESC = :MWIPMFOPMT_N.OPTION_DESC,
                    SYS_PMT_FLAG = :MWIPMFOPMT_N.SYS_PMT_FLAG,
                    KEY_PMT_1 = :MWIPMFOPMT_N.KEY_PMT_1,
                    KEY_PMT_2 = :MWIPMFOPMT_N.KEY_PMT_2,
                    KEY_PMT_3 = :MWIPMFOPMT_N.KEY_PMT_3,
                    KEY_PMT_4 = :MWIPMFOPMT_N.KEY_PMT_4,
                    KEY_PMT_5 = :MWIPMFOPMT_N.KEY_PMT_5,
                    KEY_OPT_1 = :MWIPMFOPMT_N.KEY_OPT_1,
                    KEY_OPT_2 = :MWIPMFOPMT_N.KEY_OPT_2,
                    KEY_OPT_3 = :MWIPMFOPMT_N.KEY_OPT_3,
                    KEY_OPT_4 = :MWIPMFOPMT_N.KEY_OPT_4,
                    KEY_OPT_5 = :MWIPMFOPMT_N.KEY_OPT_5,
                    KEY_FMT_1 = :MWIPMFOPMT_N.KEY_FMT_1,
                    KEY_FMT_2 = :MWIPMFOPMT_N.KEY_FMT_2,
                    KEY_FMT_3 = :MWIPMFOPMT_N.KEY_FMT_3,
                    KEY_FMT_4 = :MWIPMFOPMT_N.KEY_FMT_4,
                    KEY_FMT_5 = :MWIPMFOPMT_N.KEY_FMT_5,
                    KEY_TBL_1 = :MWIPMFOPMT_N.KEY_TBL_1,
                    KEY_TBL_2 = :MWIPMFOPMT_N.KEY_TBL_2,
                    KEY_TBL_3 = :MWIPMFOPMT_N.KEY_TBL_3,
                    KEY_TBL_4 = :MWIPMFOPMT_N.KEY_TBL_4,
                    KEY_TBL_5 = :MWIPMFOPMT_N.KEY_TBL_5,
                    DATA_PMT_1 = :MWIPMFOPMT_N.DATA_PMT_1,
                    DATA_PMT_2 = :MWIPMFOPMT_N.DATA_PMT_2,
                    DATA_PMT_3 = :MWIPMFOPMT_N.DATA_PMT_3,
                    DATA_PMT_4 = :MWIPMFOPMT_N.DATA_PMT_4,
                    DATA_PMT_5 = :MWIPMFOPMT_N.DATA_PMT_5,
                    DATA_PMT_6 = :MWIPMFOPMT_N.DATA_PMT_6,
                    DATA_PMT_7 = :MWIPMFOPMT_N.DATA_PMT_7,
                    DATA_PMT_8 = :MWIPMFOPMT_N.DATA_PMT_8,
                    DATA_PMT_9 = :MWIPMFOPMT_N.DATA_PMT_9,
                    DATA_PMT_10 = :MWIPMFOPMT_N.DATA_PMT_10,
                    DATA_PMT_11 = :MWIPMFOPMT_N.DATA_PMT_11,
                    DATA_PMT_12 = :MWIPMFOPMT_N.DATA_PMT_12,
                    DATA_PMT_13 = :MWIPMFOPMT_N.DATA_PMT_13,
                    DATA_PMT_14 = :MWIPMFOPMT_N.DATA_PMT_14,
                    DATA_PMT_15 = :MWIPMFOPMT_N.DATA_PMT_15,
                    DATA_PMT_16 = :MWIPMFOPMT_N.DATA_PMT_16,
                    DATA_PMT_17 = :MWIPMFOPMT_N.DATA_PMT_17,
                    DATA_PMT_18 = :MWIPMFOPMT_N.DATA_PMT_18,
                    DATA_PMT_19 = :MWIPMFOPMT_N.DATA_PMT_19,
                    DATA_PMT_20 = :MWIPMFOPMT_N.DATA_PMT_20,
                    DATA_OPT_1 = :MWIPMFOPMT_N.DATA_OPT_1,
                    DATA_OPT_2 = :MWIPMFOPMT_N.DATA_OPT_2,
                    DATA_OPT_3 = :MWIPMFOPMT_N.DATA_OPT_3,
                    DATA_OPT_4 = :MWIPMFOPMT_N.DATA_OPT_4,
                    DATA_OPT_5 = :MWIPMFOPMT_N.DATA_OPT_5,
                    DATA_OPT_6 = :MWIPMFOPMT_N.DATA_OPT_6,
                    DATA_OPT_7 = :MWIPMFOPMT_N.DATA_OPT_7,
                    DATA_OPT_8 = :MWIPMFOPMT_N.DATA_OPT_8,
                    DATA_OPT_9 = :MWIPMFOPMT_N.DATA_OPT_9,
                    DATA_OPT_10 = :MWIPMFOPMT_N.DATA_OPT_10,
                    DATA_OPT_11 = :MWIPMFOPMT_N.DATA_OPT_11,
                    DATA_OPT_12 = :MWIPMFOPMT_N.DATA_OPT_12,
                    DATA_OPT_13 = :MWIPMFOPMT_N.DATA_OPT_13,
                    DATA_OPT_14 = :MWIPMFOPMT_N.DATA_OPT_14,
                    DATA_OPT_15 = :MWIPMFOPMT_N.DATA_OPT_15,
                    DATA_OPT_16 = :MWIPMFOPMT_N.DATA_OPT_16,
                    DATA_OPT_17 = :MWIPMFOPMT_N.DATA_OPT_17,
                    DATA_OPT_18 = :MWIPMFOPMT_N.DATA_OPT_18,
                    DATA_OPT_19 = :MWIPMFOPMT_N.DATA_OPT_19,
                    DATA_OPT_20 = :MWIPMFOPMT_N.DATA_OPT_20,
                    DATA_FMT_1 = :MWIPMFOPMT_N.DATA_FMT_1,
                    DATA_FMT_2 = :MWIPMFOPMT_N.DATA_FMT_2,
                    DATA_FMT_3 = :MWIPMFOPMT_N.DATA_FMT_3,
                    DATA_FMT_4 = :MWIPMFOPMT_N.DATA_FMT_4,
                    DATA_FMT_5 = :MWIPMFOPMT_N.DATA_FMT_5,
                    DATA_FMT_6 = :MWIPMFOPMT_N.DATA_FMT_6,
                    DATA_FMT_7 = :MWIPMFOPMT_N.DATA_FMT_7,
                    DATA_FMT_8 = :MWIPMFOPMT_N.DATA_FMT_8,
                    DATA_FMT_9 = :MWIPMFOPMT_N.DATA_FMT_9,
                    DATA_FMT_10 = :MWIPMFOPMT_N.DATA_FMT_10,
                    DATA_FMT_11 = :MWIPMFOPMT_N.DATA_FMT_11,
                    DATA_FMT_12 = :MWIPMFOPMT_N.DATA_FMT_12,
                    DATA_FMT_13 = :MWIPMFOPMT_N.DATA_FMT_13,
                    DATA_FMT_14 = :MWIPMFOPMT_N.DATA_FMT_14,
                    DATA_FMT_15 = :MWIPMFOPMT_N.DATA_FMT_15,
                    DATA_FMT_16 = :MWIPMFOPMT_N.DATA_FMT_16,
                    DATA_FMT_17 = :MWIPMFOPMT_N.DATA_FMT_17,
                    DATA_FMT_18 = :MWIPMFOPMT_N.DATA_FMT_18,
                    DATA_FMT_19 = :MWIPMFOPMT_N.DATA_FMT_19,
                    DATA_FMT_20 = :MWIPMFOPMT_N.DATA_FMT_20,
                    DATA_TBL_1 = :MWIPMFOPMT_N.DATA_TBL_1,
                    DATA_TBL_2 = :MWIPMFOPMT_N.DATA_TBL_2,
                    DATA_TBL_3 = :MWIPMFOPMT_N.DATA_TBL_3,
                    DATA_TBL_4 = :MWIPMFOPMT_N.DATA_TBL_4,
                    DATA_TBL_5 = :MWIPMFOPMT_N.DATA_TBL_5,
                    DATA_TBL_6 = :MWIPMFOPMT_N.DATA_TBL_6,
                    DATA_TBL_7 = :MWIPMFOPMT_N.DATA_TBL_7,
                    DATA_TBL_8 = :MWIPMFOPMT_N.DATA_TBL_8,
                    DATA_TBL_9 = :MWIPMFOPMT_N.DATA_TBL_9,
                    DATA_TBL_10 = :MWIPMFOPMT_N.DATA_TBL_10,
                    DATA_TBL_11 = :MWIPMFOPMT_N.DATA_TBL_11,
                    DATA_TBL_12 = :MWIPMFOPMT_N.DATA_TBL_12,
                    DATA_TBL_13 = :MWIPMFOPMT_N.DATA_TBL_13,
                    DATA_TBL_14 = :MWIPMFOPMT_N.DATA_TBL_14,
                    DATA_TBL_15 = :MWIPMFOPMT_N.DATA_TBL_15,
                    DATA_TBL_16 = :MWIPMFOPMT_N.DATA_TBL_16,
                    DATA_TBL_17 = :MWIPMFOPMT_N.DATA_TBL_17,
                    DATA_TBL_18 = :MWIPMFOPMT_N.DATA_TBL_18,
                    DATA_TBL_19 = :MWIPMFOPMT_N.DATA_TBL_19,
                    DATA_TBL_20 = :MWIPMFOPMT_N.DATA_TBL_20,
                    CREATE_USER_ID = :MWIPMFOPMT_N.CREATE_USER_ID,
                    CREATE_TIME = :MWIPMFOPMT_N.CREATE_TIME,
                    UPDATE_USER_ID = :MWIPMFOPMT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPMFOPMT_N.UPDATE_TIME
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND OPTION_NAME = :MWIPMFOPMT_N.OPTION_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPMFOPMT  set OPTION_DESC=:b0,SYS_PMT_FLAG=:b1,KEY_P\
MT_1=:b2,KEY_PMT_2=:b3,KEY_PMT_3=:b4,KEY_PMT_4=:b5,KEY_PMT_5=:b6,KEY_OPT_1=:\
b7,KEY_OPT_2=:b8,KEY_OPT_3=:b9,KEY_OPT_4=:b10,KEY_OPT_5=:b11,KEY_FMT_1=:b12,\
KEY_FMT_2=:b13,KEY_FMT_3=:b14,KEY_FMT_4=:b15,KEY_FMT_5=:b16,KEY_TBL_1=:b17,K\
EY_TBL_2=:b18,KEY_TBL_3=:b19,KEY_TBL_4=:b20,KEY_TBL_5=:b21,DATA_PMT_1=:b22,D\
ATA_PMT_2=:b23,DATA_PMT_3=:b24,DATA_PMT_4=:b25,DATA_PMT_5=:b26,DATA_PMT_6=:b\
27,DATA_PMT_7=:b28,DATA_PMT_8=:b29,DATA_PMT_9=:b30,DATA_PMT_10=:b31,DATA_PMT\
_11=:b32,DATA_PMT_12=:b33,DATA_PMT_13=:b34,DATA_PMT_14=:b35,DATA_PMT_15=:b36\
,DATA_PMT_16=:b37,DATA_PMT_17=:b38,DATA_PMT_18=:b39,DATA_PMT_19=:b40,DATA_PM\
T_20=:b41,DATA_OPT_1=:b42,DATA_OPT_2=:b43,DATA_OPT_3=:b44,DATA_OPT_4=:b45,DA\
TA_OPT_5=:b46,DATA_OPT_6=:b47,DATA_OPT_7=:b48,DATA_OPT_8=:b49,DATA_OPT_9=:b5\
0,DATA_OPT_10=:b51,DATA_OPT_11=:b52,DATA_OPT_12=:b53,DATA_OPT_13=:b54,DATA_O\
PT_14=:b55,DATA_OPT_15=:b56,DATA_OPT_16=:b57,DATA_OPT_17=:b58,DATA_OPT_18=:b\
59,DATA_OPT_19=:b60,DATA_OPT_20=:b61,DATA_FMT_1=:b6");
            sqlstm.stmt = "2,DATA_FMT_2=:b63,DATA_FMT_3=:b64,DATA_FMT_4=:b6\
5,DATA_FMT_5=:b66,DATA_FMT_6=:b67,DATA_FMT_7=:b68,DATA_FMT_8=:b69,DATA_FMT_9=\
:b70,DATA_FMT_10=:b71,DATA_FMT_11=:b72,DATA_FMT_12=:b73,DATA_FMT_13=:b74,DATA\
_FMT_14=:b75,DATA_FMT_15=:b76,DATA_FMT_16=:b77,DATA_FMT_17=:b78,DATA_FMT_18=:\
b79,DATA_FMT_19=:b80,DATA_FMT_20=:b81,DATA_TBL_1=:b82,DATA_TBL_2=:b83,DATA_TB\
L_3=:b84,DATA_TBL_4=:b85,DATA_TBL_5=:b86,DATA_TBL_6=:b87,DATA_TBL_7=:b88,DATA\
_TBL_8=:b89,DATA_TBL_9=:b90,DATA_TBL_10=:b91,DATA_TBL_11=:b92,DATA_TBL_12=:b9\
3,DATA_TBL_13=:b94,DATA_TBL_14=:b95,DATA_TBL_15=:b96,DATA_TBL_16=:b97,DATA_TB\
L_17=:b98,DATA_TBL_18=:b99,DATA_TBL_19=:b100,DATA_TBL_20=:b101,CREATE_USER_ID\
=:b102,CREATE_TIME=:b103,UPDATE_USER_ID=:b104,UPDATE_TIME=:b105 where (FACTOR\
Y=:b106 and OPTION_NAME=:b107)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1435;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
            sqlstm.sqhstl[78] = (unsigned int  )2;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
            sqlstm.sqhstl[79] = (unsigned int  )2;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
            sqlstm.sqhstl[80] = (unsigned int  )2;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
            sqlstm.sqhstl[81] = (unsigned int  )2;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
            sqlstm.sqhstl[100] = (unsigned int  )21;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[102] = (unsigned int  )21;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
            sqlstm.sqhstl[103] = (unsigned int  )15;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[104] = (unsigned int  )21;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[105] = (unsigned int  )15;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[106] = (unsigned int  )11;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[107] = (unsigned int  )21;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
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


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_update_mwipmfopmt", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipmfopmt(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPMFOPMT_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    OPTION_NAME,
                    OPTION_DESC,
                    SYS_PMT_FLAG,
                    KEY_PMT_1,
                    KEY_PMT_2,
                    KEY_PMT_3,
                    KEY_PMT_4,
                    KEY_PMT_5,
                    KEY_OPT_1,
                    KEY_OPT_2,
                    KEY_OPT_3,
                    KEY_OPT_4,
                    KEY_OPT_5,
                    KEY_FMT_1,
                    KEY_FMT_2,
                    KEY_FMT_3,
                    KEY_FMT_4,
                    KEY_FMT_5,
                    KEY_TBL_1,
                    KEY_TBL_2,
                    KEY_TBL_3,
                    KEY_TBL_4,
                    KEY_TBL_5,
                    DATA_PMT_1,
                    DATA_PMT_2,
                    DATA_PMT_3,
                    DATA_PMT_4,
                    DATA_PMT_5,
                    DATA_PMT_6,
                    DATA_PMT_7,
                    DATA_PMT_8,
                    DATA_PMT_9,
                    DATA_PMT_10,
                    DATA_PMT_11,
                    DATA_PMT_12,
                    DATA_PMT_13,
                    DATA_PMT_14,
                    DATA_PMT_15,
                    DATA_PMT_16,
                    DATA_PMT_17,
                    DATA_PMT_18,
                    DATA_PMT_19,
                    DATA_PMT_20,
                    DATA_OPT_1,
                    DATA_OPT_2,
                    DATA_OPT_3,
                    DATA_OPT_4,
                    DATA_OPT_5,
                    DATA_OPT_6,
                    DATA_OPT_7,
                    DATA_OPT_8,
                    DATA_OPT_9,
                    DATA_OPT_10,
                    DATA_OPT_11,
                    DATA_OPT_12,
                    DATA_OPT_13,
                    DATA_OPT_14,
                    DATA_OPT_15,
                    DATA_OPT_16,
                    DATA_OPT_17,
                    DATA_OPT_18,
                    DATA_OPT_19,
                    DATA_OPT_20,
                    DATA_FMT_1,
                    DATA_FMT_2,
                    DATA_FMT_3,
                    DATA_FMT_4,
                    DATA_FMT_5,
                    DATA_FMT_6,
                    DATA_FMT_7,
                    DATA_FMT_8,
                    DATA_FMT_9,
                    DATA_FMT_10,
                    DATA_FMT_11,
                    DATA_FMT_12,
                    DATA_FMT_13,
                    DATA_FMT_14,
                    DATA_FMT_15,
                    DATA_FMT_16,
                    DATA_FMT_17,
                    DATA_FMT_18,
                    DATA_FMT_19,
                    DATA_FMT_20,
                    DATA_TBL_1,
                    DATA_TBL_2,
                    DATA_TBL_3,
                    DATA_TBL_4,
                    DATA_TBL_5,
                    DATA_TBL_6,
                    DATA_TBL_7,
                    DATA_TBL_8,
                    DATA_TBL_9,
                    DATA_TBL_10,
                    DATA_TBL_11,
                    DATA_TBL_12,
                    DATA_TBL_13,
                    DATA_TBL_14,
                    DATA_TBL_15,
                    DATA_TBL_16,
                    DATA_TBL_17,
                    DATA_TBL_18,
                    DATA_TBL_19,
                    DATA_TBL_20,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                ORDER BY OPTION_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPMFOPMT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,OPTION_NAME ,OPTION_DESC ,SYS_PMT_FLAG ,KEY_P\
MT_1 ,KEY_PMT_2 ,KEY_PMT_3 ,KEY_PMT_4 ,KEY_PMT_5 ,KEY_OPT_1 ,KEY_OPT_2 ,KEY_\
OPT_3 ,KEY_OPT_4 ,KEY_OPT_5 ,KEY_FMT_1 ,KEY_FMT_2 ,KEY_FMT_3 ,KEY_FMT_4 ,KEY\
_FMT_5 ,KEY_TBL_1 ,KEY_TBL_2 ,KEY_TBL_3 ,KEY_TBL_4 ,KEY_TBL_5 ,DATA_PMT_1 ,D\
ATA_PMT_2 ,DATA_PMT_3 ,DATA_PMT_4 ,DATA_PMT_5 ,DATA_PMT_6 ,DATA_PMT_7 ,DATA_\
PMT_8 ,DATA_PMT_9 ,DATA_PMT_10 ,DATA_PMT_11 ,DATA_PMT_12 ,DATA_PMT_13 ,DATA_\
PMT_14 ,DATA_PMT_15 ,DATA_PMT_16 ,DATA_PMT_17 ,DATA_PMT_18 ,DATA_PMT_19 ,DAT\
A_PMT_20 ,DATA_OPT_1 ,DATA_OPT_2 ,DATA_OPT_3 ,DATA_OPT_4 ,DATA_OPT_5 ,DATA_O\
PT_6 ,DATA_OPT_7 ,DATA_OPT_8 ,DATA_OPT_9 ,DATA_OPT_10 ,DATA_OPT_11 ,DATA_OPT\
_12 ,DATA_OPT_13 ,DATA_OPT_14 ,DATA_OPT_15 ,DATA_OPT_16 ,DATA_OPT_17 ,DATA_O\
PT_18 ,DATA_OPT_19 ,DATA_OPT_20 ,DATA_FMT_1 ,DATA_FMT_2 ,DATA_FMT_3 ,DATA_FM\
T_4 ,DATA_FMT_5 ,DATA_FMT_6 ,DATA_FMT_7 ,DATA_FMT_8 ,DATA_FMT_9 ,DATA_FMT_10\
 ,DATA_FMT_11 ,DATA_FMT_12 ,DATA_FMT_13 ,DATA_FMT_14 ,DATA_FMT_15 ,DATA_FMT_\
16 ,DATA_FMT_17 ,DATA_FMT_18 ,DATA_FMT_19 ,DATA_FMT");
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1882;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
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


            break;

        case 2:
            /* EXEC SQL DECLARE DBC_MWIPMFOPMT_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    OPTION_NAME,
                    OPTION_DESC,
                    SYS_PMT_FLAG,
                    KEY_PMT_1,
                    KEY_PMT_2,
                    KEY_PMT_3,
                    KEY_PMT_4,
                    KEY_PMT_5,
                    KEY_OPT_1,
                    KEY_OPT_2,
                    KEY_OPT_3,
                    KEY_OPT_4,
                    KEY_OPT_5,
                    KEY_FMT_1,
                    KEY_FMT_2,
                    KEY_FMT_3,
                    KEY_FMT_4,
                    KEY_FMT_5,
                    KEY_TBL_1,
                    KEY_TBL_2,
                    KEY_TBL_3,
                    KEY_TBL_4,
                    KEY_TBL_5,
                    DATA_PMT_1,
                    DATA_PMT_2,
                    DATA_PMT_3,
                    DATA_PMT_4,
                    DATA_PMT_5,
                    DATA_PMT_6,
                    DATA_PMT_7,
                    DATA_PMT_8,
                    DATA_PMT_9,
                    DATA_PMT_10,
                    DATA_PMT_11,
                    DATA_PMT_12,
                    DATA_PMT_13,
                    DATA_PMT_14,
                    DATA_PMT_15,
                    DATA_PMT_16,
                    DATA_PMT_17,
                    DATA_PMT_18,
                    DATA_PMT_19,
                    DATA_PMT_20,
                    DATA_OPT_1,
                    DATA_OPT_2,
                    DATA_OPT_3,
                    DATA_OPT_4,
                    DATA_OPT_5,
                    DATA_OPT_6,
                    DATA_OPT_7,
                    DATA_OPT_8,
                    DATA_OPT_9,
                    DATA_OPT_10,
                    DATA_OPT_11,
                    DATA_OPT_12,
                    DATA_OPT_13,
                    DATA_OPT_14,
                    DATA_OPT_15,
                    DATA_OPT_16,
                    DATA_OPT_17,
                    DATA_OPT_18,
                    DATA_OPT_19,
                    DATA_OPT_20,
                    DATA_FMT_1,
                    DATA_FMT_2,
                    DATA_FMT_3,
                    DATA_FMT_4,
                    DATA_FMT_5,
                    DATA_FMT_6,
                    DATA_FMT_7,
                    DATA_FMT_8,
                    DATA_FMT_9,
                    DATA_FMT_10,
                    DATA_FMT_11,
                    DATA_FMT_12,
                    DATA_FMT_13,
                    DATA_FMT_14,
                    DATA_FMT_15,
                    DATA_FMT_16,
                    DATA_FMT_17,
                    DATA_FMT_18,
                    DATA_FMT_19,
                    DATA_FMT_20,
                    DATA_TBL_1,
                    DATA_TBL_2,
                    DATA_TBL_3,
                    DATA_TBL_4,
                    DATA_TBL_5,
                    DATA_TBL_6,
                    DATA_TBL_7,
                    DATA_TBL_8,
                    DATA_TBL_9,
                    DATA_TBL_10,
                    DATA_TBL_11,
                    DATA_TBL_12,
                    DATA_TBL_13,
                    DATA_TBL_14,
                    DATA_TBL_15,
                    DATA_TBL_16,
                    DATA_TBL_17,
                    DATA_TBL_18,
                    DATA_TBL_19,
                    DATA_TBL_20,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM MWIPMFOPMT
                WHERE FACTORY = :MWIPMFOPMT_N.FACTORY
                    AND SYS_PMT_FLAG = :MWIPMFOPMT_N.SYS_PMT_FLAG
                ORDER BY OPTION_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPMFOPMT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,OPTION_NAME ,OPTION_DESC ,SYS_PMT_FLAG ,KEY_P\
MT_1 ,KEY_PMT_2 ,KEY_PMT_3 ,KEY_PMT_4 ,KEY_PMT_5 ,KEY_OPT_1 ,KEY_OPT_2 ,KEY_\
OPT_3 ,KEY_OPT_4 ,KEY_OPT_5 ,KEY_FMT_1 ,KEY_FMT_2 ,KEY_FMT_3 ,KEY_FMT_4 ,KEY\
_FMT_5 ,KEY_TBL_1 ,KEY_TBL_2 ,KEY_TBL_3 ,KEY_TBL_4 ,KEY_TBL_5 ,DATA_PMT_1 ,D\
ATA_PMT_2 ,DATA_PMT_3 ,DATA_PMT_4 ,DATA_PMT_5 ,DATA_PMT_6 ,DATA_PMT_7 ,DATA_\
PMT_8 ,DATA_PMT_9 ,DATA_PMT_10 ,DATA_PMT_11 ,DATA_PMT_12 ,DATA_PMT_13 ,DATA_\
PMT_14 ,DATA_PMT_15 ,DATA_PMT_16 ,DATA_PMT_17 ,DATA_PMT_18 ,DATA_PMT_19 ,DAT\
A_PMT_20 ,DATA_OPT_1 ,DATA_OPT_2 ,DATA_OPT_3 ,DATA_OPT_4 ,DATA_OPT_5 ,DATA_O\
PT_6 ,DATA_OPT_7 ,DATA_OPT_8 ,DATA_OPT_9 ,DATA_OPT_10 ,DATA_OPT_11 ,DATA_OPT\
_12 ,DATA_OPT_13 ,DATA_OPT_14 ,DATA_OPT_15 ,DATA_OPT_16 ,DATA_OPT_17 ,DATA_O\
PT_18 ,DATA_OPT_19 ,DATA_OPT_20 ,DATA_FMT_1 ,DATA_FMT_2 ,DATA_FMT_3 ,DATA_FM\
T_4 ,DATA_FMT_5 ,DATA_FMT_6 ,DATA_FMT_7 ,DATA_FMT_8 ,DATA_FMT_9 ,DATA_FMT_10\
 ,DATA_FMT_11 ,DATA_FMT_12 ,DATA_FMT_13 ,DATA_FMT_14 ,DATA_FMT_15 ,DATA_FMT_\
16 ,DATA_FMT_17 ,DATA_FMT_18 ,DATA_FMT_19 ,DATA_FMT");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1901;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;



        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_mwipmfopmt", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipmfopmt(int sel_type, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMFOPMT_N_TAG MWIPMFOPMT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPMFOPMT_CUR_1 INTO 
                                                    :MWIPMFOPMT_N.FACTORY,
                                                    :MWIPMFOPMT_N.OPTION_NAME,
                                                    :MWIPMFOPMT_N.OPTION_DESC,
                                                    :MWIPMFOPMT_N.SYS_PMT_FLAG,
                                                    :MWIPMFOPMT_N.KEY_PMT_1,
                                                    :MWIPMFOPMT_N.KEY_PMT_2,
                                                    :MWIPMFOPMT_N.KEY_PMT_3,
                                                    :MWIPMFOPMT_N.KEY_PMT_4,
                                                    :MWIPMFOPMT_N.KEY_PMT_5,
                                                    :MWIPMFOPMT_N.KEY_OPT_1,
                                                    :MWIPMFOPMT_N.KEY_OPT_2,
                                                    :MWIPMFOPMT_N.KEY_OPT_3,
                                                    :MWIPMFOPMT_N.KEY_OPT_4,
                                                    :MWIPMFOPMT_N.KEY_OPT_5,
                                                    :MWIPMFOPMT_N.KEY_FMT_1,
                                                    :MWIPMFOPMT_N.KEY_FMT_2,
                                                    :MWIPMFOPMT_N.KEY_FMT_3,
                                                    :MWIPMFOPMT_N.KEY_FMT_4,
                                                    :MWIPMFOPMT_N.KEY_FMT_5,
                                                    :MWIPMFOPMT_N.KEY_TBL_1,
                                                    :MWIPMFOPMT_N.KEY_TBL_2,
                                                    :MWIPMFOPMT_N.KEY_TBL_3,
                                                    :MWIPMFOPMT_N.KEY_TBL_4,
                                                    :MWIPMFOPMT_N.KEY_TBL_5,
                                                    :MWIPMFOPMT_N.DATA_PMT_1,
                                                    :MWIPMFOPMT_N.DATA_PMT_2,
                                                    :MWIPMFOPMT_N.DATA_PMT_3,
                                                    :MWIPMFOPMT_N.DATA_PMT_4,
                                                    :MWIPMFOPMT_N.DATA_PMT_5,
                                                    :MWIPMFOPMT_N.DATA_PMT_6,
                                                    :MWIPMFOPMT_N.DATA_PMT_7,
                                                    :MWIPMFOPMT_N.DATA_PMT_8,
                                                    :MWIPMFOPMT_N.DATA_PMT_9,
                                                    :MWIPMFOPMT_N.DATA_PMT_10,
                                                    :MWIPMFOPMT_N.DATA_PMT_11,
                                                    :MWIPMFOPMT_N.DATA_PMT_12,
                                                    :MWIPMFOPMT_N.DATA_PMT_13,
                                                    :MWIPMFOPMT_N.DATA_PMT_14,
                                                    :MWIPMFOPMT_N.DATA_PMT_15,
                                                    :MWIPMFOPMT_N.DATA_PMT_16,
                                                    :MWIPMFOPMT_N.DATA_PMT_17,
                                                    :MWIPMFOPMT_N.DATA_PMT_18,
                                                    :MWIPMFOPMT_N.DATA_PMT_19,
                                                    :MWIPMFOPMT_N.DATA_PMT_20,
                                                    :MWIPMFOPMT_N.DATA_OPT_1,
                                                    :MWIPMFOPMT_N.DATA_OPT_2,
                                                    :MWIPMFOPMT_N.DATA_OPT_3,
                                                    :MWIPMFOPMT_N.DATA_OPT_4,
                                                    :MWIPMFOPMT_N.DATA_OPT_5,
                                                    :MWIPMFOPMT_N.DATA_OPT_6,
                                                    :MWIPMFOPMT_N.DATA_OPT_7,
                                                    :MWIPMFOPMT_N.DATA_OPT_8,
                                                    :MWIPMFOPMT_N.DATA_OPT_9,
                                                    :MWIPMFOPMT_N.DATA_OPT_10,
                                                    :MWIPMFOPMT_N.DATA_OPT_11,
                                                    :MWIPMFOPMT_N.DATA_OPT_12,
                                                    :MWIPMFOPMT_N.DATA_OPT_13,
                                                    :MWIPMFOPMT_N.DATA_OPT_14,
                                                    :MWIPMFOPMT_N.DATA_OPT_15,
                                                    :MWIPMFOPMT_N.DATA_OPT_16,
                                                    :MWIPMFOPMT_N.DATA_OPT_17,
                                                    :MWIPMFOPMT_N.DATA_OPT_18,
                                                    :MWIPMFOPMT_N.DATA_OPT_19,
                                                    :MWIPMFOPMT_N.DATA_OPT_20,
                                                    :MWIPMFOPMT_N.DATA_FMT_1,
                                                    :MWIPMFOPMT_N.DATA_FMT_2,
                                                    :MWIPMFOPMT_N.DATA_FMT_3,
                                                    :MWIPMFOPMT_N.DATA_FMT_4,
                                                    :MWIPMFOPMT_N.DATA_FMT_5,
                                                    :MWIPMFOPMT_N.DATA_FMT_6,
                                                    :MWIPMFOPMT_N.DATA_FMT_7,
                                                    :MWIPMFOPMT_N.DATA_FMT_8,
                                                    :MWIPMFOPMT_N.DATA_FMT_9,
                                                    :MWIPMFOPMT_N.DATA_FMT_10,
                                                    :MWIPMFOPMT_N.DATA_FMT_11,
                                                    :MWIPMFOPMT_N.DATA_FMT_12,
                                                    :MWIPMFOPMT_N.DATA_FMT_13,
                                                    :MWIPMFOPMT_N.DATA_FMT_14,
                                                    :MWIPMFOPMT_N.DATA_FMT_15,
                                                    :MWIPMFOPMT_N.DATA_FMT_16,
                                                    :MWIPMFOPMT_N.DATA_FMT_17,
                                                    :MWIPMFOPMT_N.DATA_FMT_18,
                                                    :MWIPMFOPMT_N.DATA_FMT_19,
                                                    :MWIPMFOPMT_N.DATA_FMT_20,
                                                    :MWIPMFOPMT_N.DATA_TBL_1,
                                                    :MWIPMFOPMT_N.DATA_TBL_2,
                                                    :MWIPMFOPMT_N.DATA_TBL_3,
                                                    :MWIPMFOPMT_N.DATA_TBL_4,
                                                    :MWIPMFOPMT_N.DATA_TBL_5,
                                                    :MWIPMFOPMT_N.DATA_TBL_6,
                                                    :MWIPMFOPMT_N.DATA_TBL_7,
                                                    :MWIPMFOPMT_N.DATA_TBL_8,
                                                    :MWIPMFOPMT_N.DATA_TBL_9,
                                                    :MWIPMFOPMT_N.DATA_TBL_10,
                                                    :MWIPMFOPMT_N.DATA_TBL_11,
                                                    :MWIPMFOPMT_N.DATA_TBL_12,
                                                    :MWIPMFOPMT_N.DATA_TBL_13,
                                                    :MWIPMFOPMT_N.DATA_TBL_14,
                                                    :MWIPMFOPMT_N.DATA_TBL_15,
                                                    :MWIPMFOPMT_N.DATA_TBL_16,
                                                    :MWIPMFOPMT_N.DATA_TBL_17,
                                                    :MWIPMFOPMT_N.DATA_TBL_18,
                                                    :MWIPMFOPMT_N.DATA_TBL_19,
                                                    :MWIPMFOPMT_N.DATA_TBL_20,
                                                    :MWIPMFOPMT_N.CREATE_USER_ID,
                                                    :MWIPMFOPMT_N.CREATE_TIME,
                                                    :MWIPMFOPMT_N.UPDATE_USER_ID,
                                                    :MWIPMFOPMT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1924;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
            sqlstm.sqhstl[78] = (unsigned int  )2;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
            sqlstm.sqhstl[79] = (unsigned int  )2;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
            sqlstm.sqhstl[80] = (unsigned int  )2;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
            sqlstm.sqhstl[81] = (unsigned int  )2;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
            sqlstm.sqhstl[82] = (unsigned int  )2;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
            sqlstm.sqhstl[83] = (unsigned int  )2;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
            sqlstm.sqhstl[100] = (unsigned int  )21;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
            sqlstm.sqhstl[102] = (unsigned int  )21;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[104] = (unsigned int  )21;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
            sqlstm.sqhstl[105] = (unsigned int  )15;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[106] = (unsigned int  )21;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
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


            break;

        case 2:
            /* EXEC SQL FETCH DBC_MWIPMFOPMT_CUR_2 INTO 
                                                    :MWIPMFOPMT_N.FACTORY,
                                                    :MWIPMFOPMT_N.OPTION_NAME,
                                                    :MWIPMFOPMT_N.OPTION_DESC,
                                                    :MWIPMFOPMT_N.SYS_PMT_FLAG,
                                                    :MWIPMFOPMT_N.KEY_PMT_1,
                                                    :MWIPMFOPMT_N.KEY_PMT_2,
                                                    :MWIPMFOPMT_N.KEY_PMT_3,
                                                    :MWIPMFOPMT_N.KEY_PMT_4,
                                                    :MWIPMFOPMT_N.KEY_PMT_5,
                                                    :MWIPMFOPMT_N.KEY_OPT_1,
                                                    :MWIPMFOPMT_N.KEY_OPT_2,
                                                    :MWIPMFOPMT_N.KEY_OPT_3,
                                                    :MWIPMFOPMT_N.KEY_OPT_4,
                                                    :MWIPMFOPMT_N.KEY_OPT_5,
                                                    :MWIPMFOPMT_N.KEY_FMT_1,
                                                    :MWIPMFOPMT_N.KEY_FMT_2,
                                                    :MWIPMFOPMT_N.KEY_FMT_3,
                                                    :MWIPMFOPMT_N.KEY_FMT_4,
                                                    :MWIPMFOPMT_N.KEY_FMT_5,
                                                    :MWIPMFOPMT_N.KEY_TBL_1,
                                                    :MWIPMFOPMT_N.KEY_TBL_2,
                                                    :MWIPMFOPMT_N.KEY_TBL_3,
                                                    :MWIPMFOPMT_N.KEY_TBL_4,
                                                    :MWIPMFOPMT_N.KEY_TBL_5,
                                                    :MWIPMFOPMT_N.DATA_PMT_1,
                                                    :MWIPMFOPMT_N.DATA_PMT_2,
                                                    :MWIPMFOPMT_N.DATA_PMT_3,
                                                    :MWIPMFOPMT_N.DATA_PMT_4,
                                                    :MWIPMFOPMT_N.DATA_PMT_5,
                                                    :MWIPMFOPMT_N.DATA_PMT_6,
                                                    :MWIPMFOPMT_N.DATA_PMT_7,
                                                    :MWIPMFOPMT_N.DATA_PMT_8,
                                                    :MWIPMFOPMT_N.DATA_PMT_9,
                                                    :MWIPMFOPMT_N.DATA_PMT_10,
                                                    :MWIPMFOPMT_N.DATA_PMT_11,
                                                    :MWIPMFOPMT_N.DATA_PMT_12,
                                                    :MWIPMFOPMT_N.DATA_PMT_13,
                                                    :MWIPMFOPMT_N.DATA_PMT_14,
                                                    :MWIPMFOPMT_N.DATA_PMT_15,
                                                    :MWIPMFOPMT_N.DATA_PMT_16,
                                                    :MWIPMFOPMT_N.DATA_PMT_17,
                                                    :MWIPMFOPMT_N.DATA_PMT_18,
                                                    :MWIPMFOPMT_N.DATA_PMT_19,
                                                    :MWIPMFOPMT_N.DATA_PMT_20,
                                                    :MWIPMFOPMT_N.DATA_OPT_1,
                                                    :MWIPMFOPMT_N.DATA_OPT_2,
                                                    :MWIPMFOPMT_N.DATA_OPT_3,
                                                    :MWIPMFOPMT_N.DATA_OPT_4,
                                                    :MWIPMFOPMT_N.DATA_OPT_5,
                                                    :MWIPMFOPMT_N.DATA_OPT_6,
                                                    :MWIPMFOPMT_N.DATA_OPT_7,
                                                    :MWIPMFOPMT_N.DATA_OPT_8,
                                                    :MWIPMFOPMT_N.DATA_OPT_9,
                                                    :MWIPMFOPMT_N.DATA_OPT_10,
                                                    :MWIPMFOPMT_N.DATA_OPT_11,
                                                    :MWIPMFOPMT_N.DATA_OPT_12,
                                                    :MWIPMFOPMT_N.DATA_OPT_13,
                                                    :MWIPMFOPMT_N.DATA_OPT_14,
                                                    :MWIPMFOPMT_N.DATA_OPT_15,
                                                    :MWIPMFOPMT_N.DATA_OPT_16,
                                                    :MWIPMFOPMT_N.DATA_OPT_17,
                                                    :MWIPMFOPMT_N.DATA_OPT_18,
                                                    :MWIPMFOPMT_N.DATA_OPT_19,
                                                    :MWIPMFOPMT_N.DATA_OPT_20,
                                                    :MWIPMFOPMT_N.DATA_FMT_1,
                                                    :MWIPMFOPMT_N.DATA_FMT_2,
                                                    :MWIPMFOPMT_N.DATA_FMT_3,
                                                    :MWIPMFOPMT_N.DATA_FMT_4,
                                                    :MWIPMFOPMT_N.DATA_FMT_5,
                                                    :MWIPMFOPMT_N.DATA_FMT_6,
                                                    :MWIPMFOPMT_N.DATA_FMT_7,
                                                    :MWIPMFOPMT_N.DATA_FMT_8,
                                                    :MWIPMFOPMT_N.DATA_FMT_9,
                                                    :MWIPMFOPMT_N.DATA_FMT_10,
                                                    :MWIPMFOPMT_N.DATA_FMT_11,
                                                    :MWIPMFOPMT_N.DATA_FMT_12,
                                                    :MWIPMFOPMT_N.DATA_FMT_13,
                                                    :MWIPMFOPMT_N.DATA_FMT_14,
                                                    :MWIPMFOPMT_N.DATA_FMT_15,
                                                    :MWIPMFOPMT_N.DATA_FMT_16,
                                                    :MWIPMFOPMT_N.DATA_FMT_17,
                                                    :MWIPMFOPMT_N.DATA_FMT_18,
                                                    :MWIPMFOPMT_N.DATA_FMT_19,
                                                    :MWIPMFOPMT_N.DATA_FMT_20,
                                                    :MWIPMFOPMT_N.DATA_TBL_1,
                                                    :MWIPMFOPMT_N.DATA_TBL_2,
                                                    :MWIPMFOPMT_N.DATA_TBL_3,
                                                    :MWIPMFOPMT_N.DATA_TBL_4,
                                                    :MWIPMFOPMT_N.DATA_TBL_5,
                                                    :MWIPMFOPMT_N.DATA_TBL_6,
                                                    :MWIPMFOPMT_N.DATA_TBL_7,
                                                    :MWIPMFOPMT_N.DATA_TBL_8,
                                                    :MWIPMFOPMT_N.DATA_TBL_9,
                                                    :MWIPMFOPMT_N.DATA_TBL_10,
                                                    :MWIPMFOPMT_N.DATA_TBL_11,
                                                    :MWIPMFOPMT_N.DATA_TBL_12,
                                                    :MWIPMFOPMT_N.DATA_TBL_13,
                                                    :MWIPMFOPMT_N.DATA_TBL_14,
                                                    :MWIPMFOPMT_N.DATA_TBL_15,
                                                    :MWIPMFOPMT_N.DATA_TBL_16,
                                                    :MWIPMFOPMT_N.DATA_TBL_17,
                                                    :MWIPMFOPMT_N.DATA_TBL_18,
                                                    :MWIPMFOPMT_N.DATA_TBL_19,
                                                    :MWIPMFOPMT_N.DATA_TBL_20,
                                                    :MWIPMFOPMT_N.CREATE_USER_ID,
                                                    :MWIPMFOPMT_N.CREATE_TIME,
                                                    :MWIPMFOPMT_N.UPDATE_USER_ID,
                                                    :MWIPMFOPMT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2371;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMFOPMT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMFOPMT_N.OPTION_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMFOPMT_N.OPTION_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMFOPMT_N.SYS_PMT_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_1);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_2);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_3);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_4);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMFOPMT_N.KEY_PMT_5);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_1);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_2);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_3);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_4);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMFOPMT_N.KEY_OPT_5);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_1);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_2);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_3);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_4);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMFOPMT_N.KEY_FMT_5);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_1);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_2);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_3);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_4);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMFOPMT_N.KEY_TBL_5);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_1);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_2);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_3);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_4);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_5);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_6);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_7);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_8);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_9);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_10);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_11);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_12);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_13);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_14);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_15);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_16);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_17);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_18);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_19);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMFOPMT_N.DATA_PMT_20);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_1);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_2);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_3);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_4);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_5);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_6);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_7);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_8);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_9);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_10);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_11);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_12);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_13);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_14);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_15);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_16);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_17);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_18);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_19);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMFOPMT_N.DATA_OPT_20);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_1);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_2);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_3);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_4);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_5);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_6);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_7);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_8);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_9);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_10);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_11);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_12);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_13);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_14);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_15);
            sqlstm.sqhstl[78] = (unsigned int  )2;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_16);
            sqlstm.sqhstl[79] = (unsigned int  )2;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_17);
            sqlstm.sqhstl[80] = (unsigned int  )2;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_18);
            sqlstm.sqhstl[81] = (unsigned int  )2;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_19);
            sqlstm.sqhstl[82] = (unsigned int  )2;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMFOPMT_N.DATA_FMT_20);
            sqlstm.sqhstl[83] = (unsigned int  )2;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_1);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_2);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_3);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_4);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_5);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_6);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_7);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_8);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_9);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_10);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_11);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_12);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_13);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_14);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_15);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_16);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_17);
            sqlstm.sqhstl[100] = (unsigned int  )21;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_18);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_19);
            sqlstm.sqhstl[102] = (unsigned int  )21;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMFOPMT_N.DATA_TBL_20);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMFOPMT_N.CREATE_USER_ID);
            sqlstm.sqhstl[104] = (unsigned int  )21;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMFOPMT_N.CREATE_TIME);
            sqlstm.sqhstl[105] = (unsigned int  )15;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPMFOPMT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[106] = (unsigned int  )21;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPMFOPMT_N.UPDATE_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
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


            break;



        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwipmfopmt(&MWIPMFOPMT_N, MWIPMFOPMT);
    }
    DB_stop_query_timer("DBC_fetch_mwipmfopmt", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipmfopmt(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPMFOPMT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2818;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBC_MWIPMFOPMT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 110;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2833;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;



        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 32);
            break;
    }
    DB_stop_query_timer("DBC_close_mwipmfopmt", sel_type);
}


/* Initialize Function */
void DBC_init_mwipmfopmt(struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* memset by Space */
    memset(MWIPMFOPMT, ' ', sizeof(struct MWIPMFOPMT_TAG));
    
}


/* Add Null Function */
void DBC_add_null_mwipmfopmt(struct MWIPMFOPMT_N_TAG *MWIPMFOPMT_N, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    /* memset by NULL */
    memset(MWIPMFOPMT_N, '\0', sizeof(struct MWIPMFOPMT_N_TAG));
    
    MEMCPY_AN(MWIPMFOPMT_N->FACTORY, MWIPMFOPMT->FACTORY, sizeof(MWIPMFOPMT->FACTORY));
    MEMCPY_AN(MWIPMFOPMT_N->OPTION_NAME, MWIPMFOPMT->OPTION_NAME, sizeof(MWIPMFOPMT->OPTION_NAME));
    MEMCPY_AN(MWIPMFOPMT_N->OPTION_DESC, MWIPMFOPMT->OPTION_DESC, sizeof(MWIPMFOPMT->OPTION_DESC));
    MWIPMFOPMT_N->SYS_PMT_FLAG[0] = MWIPMFOPMT->SYS_PMT_FLAG;
    MEMCPY_AN(MWIPMFOPMT_N->KEY_PMT_1, MWIPMFOPMT->KEY_PMT_1, sizeof(MWIPMFOPMT->KEY_PMT_1));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_PMT_2, MWIPMFOPMT->KEY_PMT_2, sizeof(MWIPMFOPMT->KEY_PMT_2));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_PMT_3, MWIPMFOPMT->KEY_PMT_3, sizeof(MWIPMFOPMT->KEY_PMT_3));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_PMT_4, MWIPMFOPMT->KEY_PMT_4, sizeof(MWIPMFOPMT->KEY_PMT_4));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_PMT_5, MWIPMFOPMT->KEY_PMT_5, sizeof(MWIPMFOPMT->KEY_PMT_5));
    MWIPMFOPMT_N->KEY_OPT_1[0] = MWIPMFOPMT->KEY_OPT_1;
    MWIPMFOPMT_N->KEY_OPT_2[0] = MWIPMFOPMT->KEY_OPT_2;
    MWIPMFOPMT_N->KEY_OPT_3[0] = MWIPMFOPMT->KEY_OPT_3;
    MWIPMFOPMT_N->KEY_OPT_4[0] = MWIPMFOPMT->KEY_OPT_4;
    MWIPMFOPMT_N->KEY_OPT_5[0] = MWIPMFOPMT->KEY_OPT_5;
    MWIPMFOPMT_N->KEY_FMT_1[0] = MWIPMFOPMT->KEY_FMT_1;
    MWIPMFOPMT_N->KEY_FMT_2[0] = MWIPMFOPMT->KEY_FMT_2;
    MWIPMFOPMT_N->KEY_FMT_3[0] = MWIPMFOPMT->KEY_FMT_3;
    MWIPMFOPMT_N->KEY_FMT_4[0] = MWIPMFOPMT->KEY_FMT_4;
    MWIPMFOPMT_N->KEY_FMT_5[0] = MWIPMFOPMT->KEY_FMT_5;
    MEMCPY_AN(MWIPMFOPMT_N->KEY_TBL_1, MWIPMFOPMT->KEY_TBL_1, sizeof(MWIPMFOPMT->KEY_TBL_1));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_TBL_2, MWIPMFOPMT->KEY_TBL_2, sizeof(MWIPMFOPMT->KEY_TBL_2));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_TBL_3, MWIPMFOPMT->KEY_TBL_3, sizeof(MWIPMFOPMT->KEY_TBL_3));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_TBL_4, MWIPMFOPMT->KEY_TBL_4, sizeof(MWIPMFOPMT->KEY_TBL_4));
    MEMCPY_AN(MWIPMFOPMT_N->KEY_TBL_5, MWIPMFOPMT->KEY_TBL_5, sizeof(MWIPMFOPMT->KEY_TBL_5));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_1, MWIPMFOPMT->DATA_PMT_1, sizeof(MWIPMFOPMT->DATA_PMT_1));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_2, MWIPMFOPMT->DATA_PMT_2, sizeof(MWIPMFOPMT->DATA_PMT_2));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_3, MWIPMFOPMT->DATA_PMT_3, sizeof(MWIPMFOPMT->DATA_PMT_3));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_4, MWIPMFOPMT->DATA_PMT_4, sizeof(MWIPMFOPMT->DATA_PMT_4));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_5, MWIPMFOPMT->DATA_PMT_5, sizeof(MWIPMFOPMT->DATA_PMT_5));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_6, MWIPMFOPMT->DATA_PMT_6, sizeof(MWIPMFOPMT->DATA_PMT_6));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_7, MWIPMFOPMT->DATA_PMT_7, sizeof(MWIPMFOPMT->DATA_PMT_7));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_8, MWIPMFOPMT->DATA_PMT_8, sizeof(MWIPMFOPMT->DATA_PMT_8));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_9, MWIPMFOPMT->DATA_PMT_9, sizeof(MWIPMFOPMT->DATA_PMT_9));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_10, MWIPMFOPMT->DATA_PMT_10, sizeof(MWIPMFOPMT->DATA_PMT_10));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_11, MWIPMFOPMT->DATA_PMT_11, sizeof(MWIPMFOPMT->DATA_PMT_11));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_12, MWIPMFOPMT->DATA_PMT_12, sizeof(MWIPMFOPMT->DATA_PMT_12));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_13, MWIPMFOPMT->DATA_PMT_13, sizeof(MWIPMFOPMT->DATA_PMT_13));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_14, MWIPMFOPMT->DATA_PMT_14, sizeof(MWIPMFOPMT->DATA_PMT_14));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_15, MWIPMFOPMT->DATA_PMT_15, sizeof(MWIPMFOPMT->DATA_PMT_15));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_16, MWIPMFOPMT->DATA_PMT_16, sizeof(MWIPMFOPMT->DATA_PMT_16));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_17, MWIPMFOPMT->DATA_PMT_17, sizeof(MWIPMFOPMT->DATA_PMT_17));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_18, MWIPMFOPMT->DATA_PMT_18, sizeof(MWIPMFOPMT->DATA_PMT_18));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_19, MWIPMFOPMT->DATA_PMT_19, sizeof(MWIPMFOPMT->DATA_PMT_19));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_PMT_20, MWIPMFOPMT->DATA_PMT_20, sizeof(MWIPMFOPMT->DATA_PMT_20));
    MWIPMFOPMT_N->DATA_OPT_1[0] = MWIPMFOPMT->DATA_OPT_1;
    MWIPMFOPMT_N->DATA_OPT_2[0] = MWIPMFOPMT->DATA_OPT_2;
    MWIPMFOPMT_N->DATA_OPT_3[0] = MWIPMFOPMT->DATA_OPT_3;
    MWIPMFOPMT_N->DATA_OPT_4[0] = MWIPMFOPMT->DATA_OPT_4;
    MWIPMFOPMT_N->DATA_OPT_5[0] = MWIPMFOPMT->DATA_OPT_5;
    MWIPMFOPMT_N->DATA_OPT_6[0] = MWIPMFOPMT->DATA_OPT_6;
    MWIPMFOPMT_N->DATA_OPT_7[0] = MWIPMFOPMT->DATA_OPT_7;
    MWIPMFOPMT_N->DATA_OPT_8[0] = MWIPMFOPMT->DATA_OPT_8;
    MWIPMFOPMT_N->DATA_OPT_9[0] = MWIPMFOPMT->DATA_OPT_9;
    MWIPMFOPMT_N->DATA_OPT_10[0] = MWIPMFOPMT->DATA_OPT_10;
    MWIPMFOPMT_N->DATA_OPT_11[0] = MWIPMFOPMT->DATA_OPT_11;
    MWIPMFOPMT_N->DATA_OPT_12[0] = MWIPMFOPMT->DATA_OPT_12;
    MWIPMFOPMT_N->DATA_OPT_13[0] = MWIPMFOPMT->DATA_OPT_13;
    MWIPMFOPMT_N->DATA_OPT_14[0] = MWIPMFOPMT->DATA_OPT_14;
    MWIPMFOPMT_N->DATA_OPT_15[0] = MWIPMFOPMT->DATA_OPT_15;
    MWIPMFOPMT_N->DATA_OPT_16[0] = MWIPMFOPMT->DATA_OPT_16;
    MWIPMFOPMT_N->DATA_OPT_17[0] = MWIPMFOPMT->DATA_OPT_17;
    MWIPMFOPMT_N->DATA_OPT_18[0] = MWIPMFOPMT->DATA_OPT_18;
    MWIPMFOPMT_N->DATA_OPT_19[0] = MWIPMFOPMT->DATA_OPT_19;
    MWIPMFOPMT_N->DATA_OPT_20[0] = MWIPMFOPMT->DATA_OPT_20;
    MWIPMFOPMT_N->DATA_FMT_1[0] = MWIPMFOPMT->DATA_FMT_1;
    MWIPMFOPMT_N->DATA_FMT_2[0] = MWIPMFOPMT->DATA_FMT_2;
    MWIPMFOPMT_N->DATA_FMT_3[0] = MWIPMFOPMT->DATA_FMT_3;
    MWIPMFOPMT_N->DATA_FMT_4[0] = MWIPMFOPMT->DATA_FMT_4;
    MWIPMFOPMT_N->DATA_FMT_5[0] = MWIPMFOPMT->DATA_FMT_5;
    MWIPMFOPMT_N->DATA_FMT_6[0] = MWIPMFOPMT->DATA_FMT_6;
    MWIPMFOPMT_N->DATA_FMT_7[0] = MWIPMFOPMT->DATA_FMT_7;
    MWIPMFOPMT_N->DATA_FMT_8[0] = MWIPMFOPMT->DATA_FMT_8;
    MWIPMFOPMT_N->DATA_FMT_9[0] = MWIPMFOPMT->DATA_FMT_9;
    MWIPMFOPMT_N->DATA_FMT_10[0] = MWIPMFOPMT->DATA_FMT_10;
    MWIPMFOPMT_N->DATA_FMT_11[0] = MWIPMFOPMT->DATA_FMT_11;
    MWIPMFOPMT_N->DATA_FMT_12[0] = MWIPMFOPMT->DATA_FMT_12;
    MWIPMFOPMT_N->DATA_FMT_13[0] = MWIPMFOPMT->DATA_FMT_13;
    MWIPMFOPMT_N->DATA_FMT_14[0] = MWIPMFOPMT->DATA_FMT_14;
    MWIPMFOPMT_N->DATA_FMT_15[0] = MWIPMFOPMT->DATA_FMT_15;
    MWIPMFOPMT_N->DATA_FMT_16[0] = MWIPMFOPMT->DATA_FMT_16;
    MWIPMFOPMT_N->DATA_FMT_17[0] = MWIPMFOPMT->DATA_FMT_17;
    MWIPMFOPMT_N->DATA_FMT_18[0] = MWIPMFOPMT->DATA_FMT_18;
    MWIPMFOPMT_N->DATA_FMT_19[0] = MWIPMFOPMT->DATA_FMT_19;
    MWIPMFOPMT_N->DATA_FMT_20[0] = MWIPMFOPMT->DATA_FMT_20;
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_1, MWIPMFOPMT->DATA_TBL_1, sizeof(MWIPMFOPMT->DATA_TBL_1));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_2, MWIPMFOPMT->DATA_TBL_2, sizeof(MWIPMFOPMT->DATA_TBL_2));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_3, MWIPMFOPMT->DATA_TBL_3, sizeof(MWIPMFOPMT->DATA_TBL_3));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_4, MWIPMFOPMT->DATA_TBL_4, sizeof(MWIPMFOPMT->DATA_TBL_4));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_5, MWIPMFOPMT->DATA_TBL_5, sizeof(MWIPMFOPMT->DATA_TBL_5));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_6, MWIPMFOPMT->DATA_TBL_6, sizeof(MWIPMFOPMT->DATA_TBL_6));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_7, MWIPMFOPMT->DATA_TBL_7, sizeof(MWIPMFOPMT->DATA_TBL_7));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_8, MWIPMFOPMT->DATA_TBL_8, sizeof(MWIPMFOPMT->DATA_TBL_8));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_9, MWIPMFOPMT->DATA_TBL_9, sizeof(MWIPMFOPMT->DATA_TBL_9));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_10, MWIPMFOPMT->DATA_TBL_10, sizeof(MWIPMFOPMT->DATA_TBL_10));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_11, MWIPMFOPMT->DATA_TBL_11, sizeof(MWIPMFOPMT->DATA_TBL_11));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_12, MWIPMFOPMT->DATA_TBL_12, sizeof(MWIPMFOPMT->DATA_TBL_12));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_13, MWIPMFOPMT->DATA_TBL_13, sizeof(MWIPMFOPMT->DATA_TBL_13));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_14, MWIPMFOPMT->DATA_TBL_14, sizeof(MWIPMFOPMT->DATA_TBL_14));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_15, MWIPMFOPMT->DATA_TBL_15, sizeof(MWIPMFOPMT->DATA_TBL_15));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_16, MWIPMFOPMT->DATA_TBL_16, sizeof(MWIPMFOPMT->DATA_TBL_16));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_17, MWIPMFOPMT->DATA_TBL_17, sizeof(MWIPMFOPMT->DATA_TBL_17));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_18, MWIPMFOPMT->DATA_TBL_18, sizeof(MWIPMFOPMT->DATA_TBL_18));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_19, MWIPMFOPMT->DATA_TBL_19, sizeof(MWIPMFOPMT->DATA_TBL_19));
    MEMCPY_AN(MWIPMFOPMT_N->DATA_TBL_20, MWIPMFOPMT->DATA_TBL_20, sizeof(MWIPMFOPMT->DATA_TBL_20));
    MEMCPY_AN(MWIPMFOPMT_N->CREATE_USER_ID, MWIPMFOPMT->CREATE_USER_ID, sizeof(MWIPMFOPMT->CREATE_USER_ID));
    MEMCPY_AN(MWIPMFOPMT_N->CREATE_TIME, MWIPMFOPMT->CREATE_TIME, sizeof(MWIPMFOPMT->CREATE_TIME));
    MEMCPY_AN(MWIPMFOPMT_N->UPDATE_USER_ID, MWIPMFOPMT->UPDATE_USER_ID, sizeof(MWIPMFOPMT->UPDATE_USER_ID));
    MEMCPY_AN(MWIPMFOPMT_N->UPDATE_TIME, MWIPMFOPMT->UPDATE_TIME, sizeof(MWIPMFOPMT->UPDATE_TIME));
}


/* Del Null Function */
void DBC_del_null_mwipmfopmt(struct MWIPMFOPMT_N_TAG *MWIPMFOPMT_N, struct MWIPMFOPMT_TAG *MWIPMFOPMT)
{
    MEMCPY_DN(MWIPMFOPMT->FACTORY, MWIPMFOPMT_N->FACTORY, sizeof(MWIPMFOPMT->FACTORY));
    MEMCPY_DN(MWIPMFOPMT->OPTION_NAME, MWIPMFOPMT_N->OPTION_NAME, sizeof(MWIPMFOPMT->OPTION_NAME));
    MEMCPY_DN(MWIPMFOPMT->OPTION_DESC, MWIPMFOPMT_N->OPTION_DESC, sizeof(MWIPMFOPMT->OPTION_DESC));
    MWIPMFOPMT->SYS_PMT_FLAG = MWIPMFOPMT_N->SYS_PMT_FLAG[0];
    MEMCPY_DN(MWIPMFOPMT->KEY_PMT_1, MWIPMFOPMT_N->KEY_PMT_1, sizeof(MWIPMFOPMT->KEY_PMT_1));
    MEMCPY_DN(MWIPMFOPMT->KEY_PMT_2, MWIPMFOPMT_N->KEY_PMT_2, sizeof(MWIPMFOPMT->KEY_PMT_2));
    MEMCPY_DN(MWIPMFOPMT->KEY_PMT_3, MWIPMFOPMT_N->KEY_PMT_3, sizeof(MWIPMFOPMT->KEY_PMT_3));
    MEMCPY_DN(MWIPMFOPMT->KEY_PMT_4, MWIPMFOPMT_N->KEY_PMT_4, sizeof(MWIPMFOPMT->KEY_PMT_4));
    MEMCPY_DN(MWIPMFOPMT->KEY_PMT_5, MWIPMFOPMT_N->KEY_PMT_5, sizeof(MWIPMFOPMT->KEY_PMT_5));
    MWIPMFOPMT->KEY_OPT_1 = MWIPMFOPMT_N->KEY_OPT_1[0];
    MWIPMFOPMT->KEY_OPT_2 = MWIPMFOPMT_N->KEY_OPT_2[0];
    MWIPMFOPMT->KEY_OPT_3 = MWIPMFOPMT_N->KEY_OPT_3[0];
    MWIPMFOPMT->KEY_OPT_4 = MWIPMFOPMT_N->KEY_OPT_4[0];
    MWIPMFOPMT->KEY_OPT_5 = MWIPMFOPMT_N->KEY_OPT_5[0];
    MWIPMFOPMT->KEY_FMT_1 = MWIPMFOPMT_N->KEY_FMT_1[0];
    MWIPMFOPMT->KEY_FMT_2 = MWIPMFOPMT_N->KEY_FMT_2[0];
    MWIPMFOPMT->KEY_FMT_3 = MWIPMFOPMT_N->KEY_FMT_3[0];
    MWIPMFOPMT->KEY_FMT_4 = MWIPMFOPMT_N->KEY_FMT_4[0];
    MWIPMFOPMT->KEY_FMT_5 = MWIPMFOPMT_N->KEY_FMT_5[0];
    MEMCPY_DN(MWIPMFOPMT->KEY_TBL_1, MWIPMFOPMT_N->KEY_TBL_1, sizeof(MWIPMFOPMT->KEY_TBL_1));
    MEMCPY_DN(MWIPMFOPMT->KEY_TBL_2, MWIPMFOPMT_N->KEY_TBL_2, sizeof(MWIPMFOPMT->KEY_TBL_2));
    MEMCPY_DN(MWIPMFOPMT->KEY_TBL_3, MWIPMFOPMT_N->KEY_TBL_3, sizeof(MWIPMFOPMT->KEY_TBL_3));
    MEMCPY_DN(MWIPMFOPMT->KEY_TBL_4, MWIPMFOPMT_N->KEY_TBL_4, sizeof(MWIPMFOPMT->KEY_TBL_4));
    MEMCPY_DN(MWIPMFOPMT->KEY_TBL_5, MWIPMFOPMT_N->KEY_TBL_5, sizeof(MWIPMFOPMT->KEY_TBL_5));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_1, MWIPMFOPMT_N->DATA_PMT_1, sizeof(MWIPMFOPMT->DATA_PMT_1));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_2, MWIPMFOPMT_N->DATA_PMT_2, sizeof(MWIPMFOPMT->DATA_PMT_2));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_3, MWIPMFOPMT_N->DATA_PMT_3, sizeof(MWIPMFOPMT->DATA_PMT_3));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_4, MWIPMFOPMT_N->DATA_PMT_4, sizeof(MWIPMFOPMT->DATA_PMT_4));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_5, MWIPMFOPMT_N->DATA_PMT_5, sizeof(MWIPMFOPMT->DATA_PMT_5));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_6, MWIPMFOPMT_N->DATA_PMT_6, sizeof(MWIPMFOPMT->DATA_PMT_6));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_7, MWIPMFOPMT_N->DATA_PMT_7, sizeof(MWIPMFOPMT->DATA_PMT_7));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_8, MWIPMFOPMT_N->DATA_PMT_8, sizeof(MWIPMFOPMT->DATA_PMT_8));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_9, MWIPMFOPMT_N->DATA_PMT_9, sizeof(MWIPMFOPMT->DATA_PMT_9));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_10, MWIPMFOPMT_N->DATA_PMT_10, sizeof(MWIPMFOPMT->DATA_PMT_10));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_11, MWIPMFOPMT_N->DATA_PMT_11, sizeof(MWIPMFOPMT->DATA_PMT_11));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_12, MWIPMFOPMT_N->DATA_PMT_12, sizeof(MWIPMFOPMT->DATA_PMT_12));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_13, MWIPMFOPMT_N->DATA_PMT_13, sizeof(MWIPMFOPMT->DATA_PMT_13));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_14, MWIPMFOPMT_N->DATA_PMT_14, sizeof(MWIPMFOPMT->DATA_PMT_14));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_15, MWIPMFOPMT_N->DATA_PMT_15, sizeof(MWIPMFOPMT->DATA_PMT_15));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_16, MWIPMFOPMT_N->DATA_PMT_16, sizeof(MWIPMFOPMT->DATA_PMT_16));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_17, MWIPMFOPMT_N->DATA_PMT_17, sizeof(MWIPMFOPMT->DATA_PMT_17));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_18, MWIPMFOPMT_N->DATA_PMT_18, sizeof(MWIPMFOPMT->DATA_PMT_18));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_19, MWIPMFOPMT_N->DATA_PMT_19, sizeof(MWIPMFOPMT->DATA_PMT_19));
    MEMCPY_DN(MWIPMFOPMT->DATA_PMT_20, MWIPMFOPMT_N->DATA_PMT_20, sizeof(MWIPMFOPMT->DATA_PMT_20));
    MWIPMFOPMT->DATA_OPT_1 = MWIPMFOPMT_N->DATA_OPT_1[0];
    MWIPMFOPMT->DATA_OPT_2 = MWIPMFOPMT_N->DATA_OPT_2[0];
    MWIPMFOPMT->DATA_OPT_3 = MWIPMFOPMT_N->DATA_OPT_3[0];
    MWIPMFOPMT->DATA_OPT_4 = MWIPMFOPMT_N->DATA_OPT_4[0];
    MWIPMFOPMT->DATA_OPT_5 = MWIPMFOPMT_N->DATA_OPT_5[0];
    MWIPMFOPMT->DATA_OPT_6 = MWIPMFOPMT_N->DATA_OPT_6[0];
    MWIPMFOPMT->DATA_OPT_7 = MWIPMFOPMT_N->DATA_OPT_7[0];
    MWIPMFOPMT->DATA_OPT_8 = MWIPMFOPMT_N->DATA_OPT_8[0];
    MWIPMFOPMT->DATA_OPT_9 = MWIPMFOPMT_N->DATA_OPT_9[0];
    MWIPMFOPMT->DATA_OPT_10 = MWIPMFOPMT_N->DATA_OPT_10[0];
    MWIPMFOPMT->DATA_OPT_11 = MWIPMFOPMT_N->DATA_OPT_11[0];
    MWIPMFOPMT->DATA_OPT_12 = MWIPMFOPMT_N->DATA_OPT_12[0];
    MWIPMFOPMT->DATA_OPT_13 = MWIPMFOPMT_N->DATA_OPT_13[0];
    MWIPMFOPMT->DATA_OPT_14 = MWIPMFOPMT_N->DATA_OPT_14[0];
    MWIPMFOPMT->DATA_OPT_15 = MWIPMFOPMT_N->DATA_OPT_15[0];
    MWIPMFOPMT->DATA_OPT_16 = MWIPMFOPMT_N->DATA_OPT_16[0];
    MWIPMFOPMT->DATA_OPT_17 = MWIPMFOPMT_N->DATA_OPT_17[0];
    MWIPMFOPMT->DATA_OPT_18 = MWIPMFOPMT_N->DATA_OPT_18[0];
    MWIPMFOPMT->DATA_OPT_19 = MWIPMFOPMT_N->DATA_OPT_19[0];
    MWIPMFOPMT->DATA_OPT_20 = MWIPMFOPMT_N->DATA_OPT_20[0];
    MWIPMFOPMT->DATA_FMT_1 = MWIPMFOPMT_N->DATA_FMT_1[0];
    MWIPMFOPMT->DATA_FMT_2 = MWIPMFOPMT_N->DATA_FMT_2[0];
    MWIPMFOPMT->DATA_FMT_3 = MWIPMFOPMT_N->DATA_FMT_3[0];
    MWIPMFOPMT->DATA_FMT_4 = MWIPMFOPMT_N->DATA_FMT_4[0];
    MWIPMFOPMT->DATA_FMT_5 = MWIPMFOPMT_N->DATA_FMT_5[0];
    MWIPMFOPMT->DATA_FMT_6 = MWIPMFOPMT_N->DATA_FMT_6[0];
    MWIPMFOPMT->DATA_FMT_7 = MWIPMFOPMT_N->DATA_FMT_7[0];
    MWIPMFOPMT->DATA_FMT_8 = MWIPMFOPMT_N->DATA_FMT_8[0];
    MWIPMFOPMT->DATA_FMT_9 = MWIPMFOPMT_N->DATA_FMT_9[0];
    MWIPMFOPMT->DATA_FMT_10 = MWIPMFOPMT_N->DATA_FMT_10[0];
    MWIPMFOPMT->DATA_FMT_11 = MWIPMFOPMT_N->DATA_FMT_11[0];
    MWIPMFOPMT->DATA_FMT_12 = MWIPMFOPMT_N->DATA_FMT_12[0];
    MWIPMFOPMT->DATA_FMT_13 = MWIPMFOPMT_N->DATA_FMT_13[0];
    MWIPMFOPMT->DATA_FMT_14 = MWIPMFOPMT_N->DATA_FMT_14[0];
    MWIPMFOPMT->DATA_FMT_15 = MWIPMFOPMT_N->DATA_FMT_15[0];
    MWIPMFOPMT->DATA_FMT_16 = MWIPMFOPMT_N->DATA_FMT_16[0];
    MWIPMFOPMT->DATA_FMT_17 = MWIPMFOPMT_N->DATA_FMT_17[0];
    MWIPMFOPMT->DATA_FMT_18 = MWIPMFOPMT_N->DATA_FMT_18[0];
    MWIPMFOPMT->DATA_FMT_19 = MWIPMFOPMT_N->DATA_FMT_19[0];
    MWIPMFOPMT->DATA_FMT_20 = MWIPMFOPMT_N->DATA_FMT_20[0];
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_1, MWIPMFOPMT_N->DATA_TBL_1, sizeof(MWIPMFOPMT->DATA_TBL_1));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_2, MWIPMFOPMT_N->DATA_TBL_2, sizeof(MWIPMFOPMT->DATA_TBL_2));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_3, MWIPMFOPMT_N->DATA_TBL_3, sizeof(MWIPMFOPMT->DATA_TBL_3));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_4, MWIPMFOPMT_N->DATA_TBL_4, sizeof(MWIPMFOPMT->DATA_TBL_4));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_5, MWIPMFOPMT_N->DATA_TBL_5, sizeof(MWIPMFOPMT->DATA_TBL_5));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_6, MWIPMFOPMT_N->DATA_TBL_6, sizeof(MWIPMFOPMT->DATA_TBL_6));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_7, MWIPMFOPMT_N->DATA_TBL_7, sizeof(MWIPMFOPMT->DATA_TBL_7));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_8, MWIPMFOPMT_N->DATA_TBL_8, sizeof(MWIPMFOPMT->DATA_TBL_8));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_9, MWIPMFOPMT_N->DATA_TBL_9, sizeof(MWIPMFOPMT->DATA_TBL_9));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_10, MWIPMFOPMT_N->DATA_TBL_10, sizeof(MWIPMFOPMT->DATA_TBL_10));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_11, MWIPMFOPMT_N->DATA_TBL_11, sizeof(MWIPMFOPMT->DATA_TBL_11));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_12, MWIPMFOPMT_N->DATA_TBL_12, sizeof(MWIPMFOPMT->DATA_TBL_12));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_13, MWIPMFOPMT_N->DATA_TBL_13, sizeof(MWIPMFOPMT->DATA_TBL_13));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_14, MWIPMFOPMT_N->DATA_TBL_14, sizeof(MWIPMFOPMT->DATA_TBL_14));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_15, MWIPMFOPMT_N->DATA_TBL_15, sizeof(MWIPMFOPMT->DATA_TBL_15));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_16, MWIPMFOPMT_N->DATA_TBL_16, sizeof(MWIPMFOPMT->DATA_TBL_16));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_17, MWIPMFOPMT_N->DATA_TBL_17, sizeof(MWIPMFOPMT->DATA_TBL_17));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_18, MWIPMFOPMT_N->DATA_TBL_18, sizeof(MWIPMFOPMT->DATA_TBL_18));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_19, MWIPMFOPMT_N->DATA_TBL_19, sizeof(MWIPMFOPMT->DATA_TBL_19));
    MEMCPY_DN(MWIPMFOPMT->DATA_TBL_20, MWIPMFOPMT_N->DATA_TBL_20, sizeof(MWIPMFOPMT->DATA_TBL_20));
    MEMCPY_DN(MWIPMFOPMT->CREATE_USER_ID, MWIPMFOPMT_N->CREATE_USER_ID, sizeof(MWIPMFOPMT->CREATE_USER_ID));
    MEMCPY_DN(MWIPMFOPMT->CREATE_TIME, MWIPMFOPMT_N->CREATE_TIME, sizeof(MWIPMFOPMT->CREATE_TIME));
    MEMCPY_DN(MWIPMFOPMT->UPDATE_USER_ID, MWIPMFOPMT_N->UPDATE_USER_ID, sizeof(MWIPMFOPMT->UPDATE_USER_ID));
    MEMCPY_DN(MWIPMFOPMT->UPDATE_TIME, MWIPMFOPMT_N->UPDATE_TIME, sizeof(MWIPMFOPMT->UPDATE_TIME));
}


