
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
    "DBC_mwipbingrd.pc"
};


static unsigned int sqlctx = 9140155;


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
            void  *sqhstv[93];
   unsigned int   sqhstl[93];
            int   sqhsts[93];
            void  *sqindv[93];
            int   sqinds[93];
   unsigned int   sqharm[93];
   unsigned int   *sqharc[93];
   unsigned short  sqadto[93];
   unsigned short  sqtdso[93];
} sqlstm = {13,93};

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

 static const char *sq0009 = 
"_TRAN_RET_OPTION ,TG_TRAN_COMMENT ,P\
Y_PERIOD ,PY_UPPER_LIMIT ,PY_LOWER_LIMIT ,PY_ALARM_ID ,PY_USE_SPEC_LIMIT_FLAG\
 ,PY_USE_SPEC_CHAR_ID ,BIN_GRADE_CMF_1 ,BIN_GRADE_CMF_2 ,BIN_GRADE_CMF_3 ,BIN\
_GRADE_CMF_4 ,BIN_GRADE_CMF_5 ,BIN_GRADE_CMF_6 ,BIN_GRADE_CMF_7 ,BIN_GRADE_CM\
F_8 ,BIN_GRADE_CMF_9 ,BIN_GRADE_CMF_10 ,BIN_GRADE_CMF_11 ,BIN_GRADE_CMF_12 ,B\
IN_GRADE_CMF_13 ,BIN_GRADE_CMF_14 ,BIN_GRADE_CMF_15 ,BIN_GRADE_CMF_16 ,BIN_GR\
ADE_CMF_17 ,BIN_GRADE_CMF_18 ,BIN_GRADE_CMF_19 ,BIN_GRADE_CMF_20  from MWIPBI\
NGRD where ((FACTORY=:b0 and BIN_ID=:b1) and BIN_VERSION=:b2) order by BIN_UN\
IT asc ,BIN_SEQ asc             ";

 static const char *sq0010 = 
"_TRAN_RET_OPTION ,TG_TRAN_COMMENT ,P\
Y_PERIOD ,PY_UPPER_LIMIT ,PY_LOWER_LIMIT ,PY_ALARM_ID ,PY_USE_SPEC_LIMIT_FLAG\
 ,PY_USE_SPEC_CHAR_ID ,BIN_GRADE_CMF_1 ,BIN_GRADE_CMF_2 ,BIN_GRADE_CMF_3 ,BIN\
_GRADE_CMF_4 ,BIN_GRADE_CMF_5 ,BIN_GRADE_CMF_6 ,BIN_GRADE_CMF_7 ,BIN_GRADE_CM\
F_8 ,BIN_GRADE_CMF_9 ,BIN_GRADE_CMF_10 ,BIN_GRADE_CMF_11 ,BIN_GRADE_CMF_12 ,B\
IN_GRADE_CMF_13 ,BIN_GRADE_CMF_14 ,BIN_GRADE_CMF_15 ,BIN_GRADE_CMF_16 ,BIN_GR\
ADE_CMF_17 ,BIN_GRADE_CMF_18 ,BIN_GRADE_CMF_19 ,BIN_GRADE_CMF_20  from MWIPBI\
NGRD where ((((FACTORY=:b0 and BIN_ID=:b1) and BIN_VERSION=:b2) and BIN_UNIT=\
:b3) and BIN_SEQ>=:b4) order by BIN_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,2055,0,4,45,0,0,93,5,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
392,0,0,2,2067,0,4,264,0,0,93,5,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
779,0,0,3,118,0,4,486,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
814,0,0,4,99,0,4,496,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
845,0,0,5,118,0,2,533,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
880,0,0,6,81,0,2,542,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
907,0,0,7,1879,0,3,572,0,0,88,88,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1274,0,0,8,1898,0,5,772,0,0,88,88,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
1641,0,0,9,1631,0,9,985,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1668,0,0,10,1655,0,9,1086,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,
1703,0,0,9,0,0,13,1114,0,0,88,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2070,0,0,10,0,0,13,1206,0,0,88,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2437,0,0,9,0,0,15,1324,0,0,0,0,0,1,0,
2452,0,0,10,0,0,15,1328,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipbingrd.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/02/19 19:51:10
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2013 MIRACOM,INC.
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
void DBC_add_null_mwipbingrd(struct MWIPBINGRD_N_TAG *MWIPBINGRD_N, struct MWIPBINGRD_TAG *MWIPBINGRD);
void DBC_del_null_mwipbingrd(struct MWIPBINGRD_N_TAG *MWIPBINGRD_N, struct MWIPBINGRD_TAG *MWIPBINGRD);


/* SQL SELECT Function */
void DBC_select_mwipbingrd(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_SEQ,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    KEEP_LOT_FLAG,
                    SPLIT_LOT_ID_RULE,
                    SPLIT_BY_BIN_SEQ,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    REASON_CODE_REF_OPER,
                    CHANGE_MAT_ID,
                    CHANGE_MAT_VER,
                    CHANGE_FLOW,
                    CHANGE_FLOW_SEQ_NUM,
                    CHANGE_OPER,
                    CHANGE_LOT_TYPE,
                    CHANGE_LOT_PRIORITY,
                    CHANGE_CREATE_CODE,
                    CHANGE_OWNER_CODE,
                    CHANGE_CRR_GROUP,
                    TRAN_CODE,
                    TRAN_KEY_REF_OPER,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_TO_MAT_ID,
                    TRAN_TO_MAT_VER,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    TRAN_STOP_OPER,
                    TRAN_RET_FLOW,
                    TRAN_RET_FLOW_SEQ_NUM,
                    TRAN_RET_OPER,
                    TRAN_RET_OPTION,
                    TRAN_COMMENT,
                    TG_TRAN_CODE,
                    TG_TRAN_KEY_REF_OPER,
                    TG_TRAN_KEY_CODE_1,
                    TG_TRAN_KEY_CODE_2,
                    TG_TRAN_KEY_CODE_3,
                    TG_TRAN_TO_MAT_ID,
                    TG_TRAN_TO_MAT_VER,
                    TG_TRAN_TO_FLOW,
                    TG_TRAN_TO_FLOW_SEQ_NUM,
                    TG_TRAN_TO_OPER,
                    TG_TRAN_STOP_OPER,
                    TG_TRAN_RET_FLOW,
                    TG_TRAN_RET_FLOW_SEQ_NUM,
                    TG_TRAN_RET_OPER,
                    TG_TRAN_RET_OPTION,
                    TG_TRAN_COMMENT,
                    PY_PERIOD,
                    PY_UPPER_LIMIT,
                    PY_LOWER_LIMIT,
                    PY_ALARM_ID,
                    PY_USE_SPEC_LIMIT_FLAG,
                    PY_USE_SPEC_CHAR_ID,
                    BIN_GRADE_CMF_1,
                    BIN_GRADE_CMF_2,
                    BIN_GRADE_CMF_3,
                    BIN_GRADE_CMF_4,
                    BIN_GRADE_CMF_5,
                    BIN_GRADE_CMF_6,
                    BIN_GRADE_CMF_7,
                    BIN_GRADE_CMF_8,
                    BIN_GRADE_CMF_9,
                    BIN_GRADE_CMF_10,
                    BIN_GRADE_CMF_11,
                    BIN_GRADE_CMF_12,
                    BIN_GRADE_CMF_13,
                    BIN_GRADE_CMF_14,
                    BIN_GRADE_CMF_15,
                    BIN_GRADE_CMF_16,
                    BIN_GRADE_CMF_17,
                    BIN_GRADE_CMF_18,
                    BIN_GRADE_CMF_19,
                    BIN_GRADE_CMF_20
                INTO 
                    :MWIPBINGRD_N.CREATE_USER_ID,
                    :MWIPBINGRD_N.CREATE_TIME,
                    :MWIPBINGRD_N.UPDATE_USER_ID,
                    :MWIPBINGRD_N.UPDATE_TIME,
                    :MWIPBINGRD_N.FACTORY,
                    :MWIPBINGRD_N.BIN_ID,
                    :MWIPBINGRD_N.BIN_VERSION,
                    :MWIPBINGRD_N.BIN_UNIT,
                    :MWIPBINGRD_N.BIN_SEQ,
                    :MWIPBINGRD_N.BIN_PROMPT,
                    :MWIPBINGRD_N.BIN_PROMPT_DESC,
                    :MWIPBINGRD_N.BIN_TYPE,
                    :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                    :MWIPBINGRD_N.KEEP_LOT_FLAG,
                    :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                    :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                    :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINGRD_N.FAIL_REASON_CODE,
                    :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                    :MWIPBINGRD_N.CHANGE_MAT_ID,
                    :MWIPBINGRD_N.CHANGE_MAT_VER,
                    :MWIPBINGRD_N.CHANGE_FLOW,
                    :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.CHANGE_OPER,
                    :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                    :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                    :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                    :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                    :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                    :MWIPBINGRD_N.TRAN_CODE,
                    :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_TO_OPER,
                    :MWIPBINGRD_N.TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_RET_OPER,
                    :MWIPBINGRD_N.TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TRAN_COMMENT,
                    :MWIPBINGRD_N.TG_TRAN_CODE,
                    :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                    :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TG_TRAN_COMMENT,
                    :MWIPBINGRD_N.PY_PERIOD,
                    :MWIPBINGRD_N.PY_UPPER_LIMIT,
                    :MWIPBINGRD_N.PY_LOWER_LIMIT,
                    :MWIPBINGRD_N.PY_ALARM_ID,
                    :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                    :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_20
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT
                    AND BIN_SEQ = :MWIPBINGRD_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_SEQ ,BIN_PROMPT ,BIN_PROMPT_\
DESC ,BIN_TYPE ,LOGICAL_BIN_FLAG ,KEEP_LOT_FLAG ,SPLIT_LOT_ID_RULE ,SPLIT_BY\
_BIN_SEQ ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LOT_QTY_FAIL ,FAIL_REASON_CODE ,R\
EASON_CODE_REF_OPER ,CHANGE_MAT_ID ,CHANGE_MAT_VER ,CHANGE_FLOW ,CHANGE_FLOW\
_SEQ_NUM ,CHANGE_OPER ,CHANGE_LOT_TYPE ,CHANGE_LOT_PRIORITY ,CHANGE_CREATE_C\
ODE ,CHANGE_OWNER_CODE ,CHANGE_CRR_GROUP ,TRAN_CODE ,TRAN_KEY_REF_OPER ,TRAN\
_KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_TO_MAT_ID ,TRAN_TO_MAT_V\
ER ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,TRAN_STOP_OPER ,TRAN_R\
ET_FLOW ,TRAN_RET_FLOW_SEQ_NUM ,TRAN_RET_OPER ,TRAN_RET_OPTION ,TRAN_COMMENT\
 ,TG_TRAN_CODE ,TG_TRAN_KEY_REF_OPER ,TG_TRAN_KEY_CODE_1 ,TG_TRAN_KEY_CODE_2\
 ,TG_TRAN_KEY_CODE_3 ,TG_TRAN_TO_MAT_ID ,TG_TRAN_TO_MAT_VER ,TG_TRAN_TO_FLOW\
 ,TG_TRAN_TO_FLOW_SEQ_NUM ,TG_TRAN_TO_OPER ,TG_TRAN_STOP_OPER ,TG_TRAN_RET_F\
LOW ,TG_TRAN_RET_FLOW_SEQ_NUM ,TG_TRAN_RET_OPER ,TG");
            sqlbuft((void **)0,
              "_TRAN_RET_OPTION ,TG_TRAN_COMMENT ,PY_PERIOD ,PY_UPPER_LIMIT \
,PY_LOWER_LIMIT ,PY_ALARM_ID ,PY_USE_SPEC_LIMIT_FLAG ,PY_USE_SPEC_CHAR_ID ,B\
IN_GRADE_CMF_1 ,BIN_GRADE_CMF_2 ,BIN_GRADE_CMF_3 ,BIN_GRADE_CMF_4 ,BIN_GRADE\
_CMF_5 ,BIN_GRADE_CMF_6 ,BIN_GRADE_CMF_7 ,BIN_GRADE_CMF_8 ,BIN_GRADE_CMF_9 ,\
BIN_GRADE_CMF_10 ,BIN_GRADE_CMF_11 ,BIN_GRADE_CMF_12 ,BIN_GRADE_CMF_13 ,BIN_\
GRADE_CMF_14 ,BIN_GRADE_CMF_15 ,BIN_GRADE_CMF_16 ,BIN_GRADE_CMF_17 ,BIN_GRAD\
E_CMF_18 ,BIN_GRADE_CMF_19 ,BIN_GRADE_CMF_20 into :b0,:b1,:b2,:b3,:b4,:b5,:b\
6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b\
22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52\
,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,\
:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:\
b83,:b84,:b85,:b86,:b87  from MWIPBINGRD where ((((FACTORY=:b4 and BIN_ID=:b\
5) and BIN_VERSION=:b6) and BIN_UNIT=:b");
            sqlstm.stmt = "7) and BIN_SEQ=:b8)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
            sqlstm.sqhstl[45] = (unsigned int  )401;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[88] = (unsigned int  )11;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[90] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[91] = (unsigned int  )11;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[92] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
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
        DBC_del_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    }

    DB_stop_query_timer("DBC_select_mwipbingrd", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipbingrd_for_update(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_SEQ,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    KEEP_LOT_FLAG,
                    SPLIT_LOT_ID_RULE,
                    SPLIT_BY_BIN_SEQ,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    REASON_CODE_REF_OPER,
                    CHANGE_MAT_ID,
                    CHANGE_MAT_VER,
                    CHANGE_FLOW,
                    CHANGE_FLOW_SEQ_NUM,
                    CHANGE_OPER,
                    CHANGE_LOT_TYPE,
                    CHANGE_LOT_PRIORITY,
                    CHANGE_CREATE_CODE,
                    CHANGE_OWNER_CODE,
                    CHANGE_CRR_GROUP,
                    TRAN_CODE,
                    TRAN_KEY_REF_OPER,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_TO_MAT_ID,
                    TRAN_TO_MAT_VER,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    TRAN_STOP_OPER,
                    TRAN_RET_FLOW,
                    TRAN_RET_FLOW_SEQ_NUM,
                    TRAN_RET_OPER,
                    TRAN_RET_OPTION,
                    TRAN_COMMENT,
                    TG_TRAN_CODE,
                    TG_TRAN_KEY_REF_OPER,
                    TG_TRAN_KEY_CODE_1,
                    TG_TRAN_KEY_CODE_2,
                    TG_TRAN_KEY_CODE_3,
                    TG_TRAN_TO_MAT_ID,
                    TG_TRAN_TO_MAT_VER,
                    TG_TRAN_TO_FLOW,
                    TG_TRAN_TO_FLOW_SEQ_NUM,
                    TG_TRAN_TO_OPER,
                    TG_TRAN_STOP_OPER,
                    TG_TRAN_RET_FLOW,
                    TG_TRAN_RET_FLOW_SEQ_NUM,
                    TG_TRAN_RET_OPER,
                    TG_TRAN_RET_OPTION,
                    TG_TRAN_COMMENT,
                    PY_PERIOD,
                    PY_UPPER_LIMIT,
                    PY_LOWER_LIMIT,
                    PY_ALARM_ID,
                    PY_USE_SPEC_LIMIT_FLAG,
                    PY_USE_SPEC_CHAR_ID,
                    BIN_GRADE_CMF_1,
                    BIN_GRADE_CMF_2,
                    BIN_GRADE_CMF_3,
                    BIN_GRADE_CMF_4,
                    BIN_GRADE_CMF_5,
                    BIN_GRADE_CMF_6,
                    BIN_GRADE_CMF_7,
                    BIN_GRADE_CMF_8,
                    BIN_GRADE_CMF_9,
                    BIN_GRADE_CMF_10,
                    BIN_GRADE_CMF_11,
                    BIN_GRADE_CMF_12,
                    BIN_GRADE_CMF_13,
                    BIN_GRADE_CMF_14,
                    BIN_GRADE_CMF_15,
                    BIN_GRADE_CMF_16,
                    BIN_GRADE_CMF_17,
                    BIN_GRADE_CMF_18,
                    BIN_GRADE_CMF_19,
                    BIN_GRADE_CMF_20
                INTO 
                    :MWIPBINGRD_N.CREATE_USER_ID,
                    :MWIPBINGRD_N.CREATE_TIME,
                    :MWIPBINGRD_N.UPDATE_USER_ID,
                    :MWIPBINGRD_N.UPDATE_TIME,
                    :MWIPBINGRD_N.FACTORY,
                    :MWIPBINGRD_N.BIN_ID,
                    :MWIPBINGRD_N.BIN_VERSION,
                    :MWIPBINGRD_N.BIN_UNIT,
                    :MWIPBINGRD_N.BIN_SEQ,
                    :MWIPBINGRD_N.BIN_PROMPT,
                    :MWIPBINGRD_N.BIN_PROMPT_DESC,
                    :MWIPBINGRD_N.BIN_TYPE,
                    :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                    :MWIPBINGRD_N.KEEP_LOT_FLAG,
                    :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                    :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                    :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINGRD_N.FAIL_REASON_CODE,
                    :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                    :MWIPBINGRD_N.CHANGE_MAT_ID,
                    :MWIPBINGRD_N.CHANGE_MAT_VER,
                    :MWIPBINGRD_N.CHANGE_FLOW,
                    :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.CHANGE_OPER,
                    :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                    :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                    :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                    :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                    :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                    :MWIPBINGRD_N.TRAN_CODE,
                    :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_TO_OPER,
                    :MWIPBINGRD_N.TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_RET_OPER,
                    :MWIPBINGRD_N.TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TRAN_COMMENT,
                    :MWIPBINGRD_N.TG_TRAN_CODE,
                    :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                    :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TG_TRAN_COMMENT,
                    :MWIPBINGRD_N.PY_PERIOD,
                    :MWIPBINGRD_N.PY_UPPER_LIMIT,
                    :MWIPBINGRD_N.PY_LOWER_LIMIT,
                    :MWIPBINGRD_N.PY_ALARM_ID,
                    :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                    :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_20
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT
                    AND BIN_SEQ = :MWIPBINGRD_N.BIN_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_SEQ ,BIN_PROMPT ,BIN_PROMPT_\
DESC ,BIN_TYPE ,LOGICAL_BIN_FLAG ,KEEP_LOT_FLAG ,SPLIT_LOT_ID_RULE ,SPLIT_BY\
_BIN_SEQ ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LOT_QTY_FAIL ,FAIL_REASON_CODE ,R\
EASON_CODE_REF_OPER ,CHANGE_MAT_ID ,CHANGE_MAT_VER ,CHANGE_FLOW ,CHANGE_FLOW\
_SEQ_NUM ,CHANGE_OPER ,CHANGE_LOT_TYPE ,CHANGE_LOT_PRIORITY ,CHANGE_CREATE_C\
ODE ,CHANGE_OWNER_CODE ,CHANGE_CRR_GROUP ,TRAN_CODE ,TRAN_KEY_REF_OPER ,TRAN\
_KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_TO_MAT_ID ,TRAN_TO_MAT_V\
ER ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,TRAN_STOP_OPER ,TRAN_R\
ET_FLOW ,TRAN_RET_FLOW_SEQ_NUM ,TRAN_RET_OPER ,TRAN_RET_OPTION ,TRAN_COMMENT\
 ,TG_TRAN_CODE ,TG_TRAN_KEY_REF_OPER ,TG_TRAN_KEY_CODE_1 ,TG_TRAN_KEY_CODE_2\
 ,TG_TRAN_KEY_CODE_3 ,TG_TRAN_TO_MAT_ID ,TG_TRAN_TO_MAT_VER ,TG_TRAN_TO_FLOW\
 ,TG_TRAN_TO_FLOW_SEQ_NUM ,TG_TRAN_TO_OPER ,TG_TRAN_STOP_OPER ,TG_TRAN_RET_F\
LOW ,TG_TRAN_RET_FLOW_SEQ_NUM ,TG_TRAN_RET_OPER ,TG");
            sqlbuft((void **)0,
              "_TRAN_RET_OPTION ,TG_TRAN_COMMENT ,PY_PERIOD ,PY_UPPER_LIMIT \
,PY_LOWER_LIMIT ,PY_ALARM_ID ,PY_USE_SPEC_LIMIT_FLAG ,PY_USE_SPEC_CHAR_ID ,B\
IN_GRADE_CMF_1 ,BIN_GRADE_CMF_2 ,BIN_GRADE_CMF_3 ,BIN_GRADE_CMF_4 ,BIN_GRADE\
_CMF_5 ,BIN_GRADE_CMF_6 ,BIN_GRADE_CMF_7 ,BIN_GRADE_CMF_8 ,BIN_GRADE_CMF_9 ,\
BIN_GRADE_CMF_10 ,BIN_GRADE_CMF_11 ,BIN_GRADE_CMF_12 ,BIN_GRADE_CMF_13 ,BIN_\
GRADE_CMF_14 ,BIN_GRADE_CMF_15 ,BIN_GRADE_CMF_16 ,BIN_GRADE_CMF_17 ,BIN_GRAD\
E_CMF_18 ,BIN_GRADE_CMF_19 ,BIN_GRADE_CMF_20 into :b0,:b1,:b2,:b3,:b4,:b5,:b\
6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b\
22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52\
,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,\
:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:\
b83,:b84,:b85,:b86,:b87  from MWIPBINGRD where ((((FACTORY=:b4 and BIN_ID=:b\
5) and BIN_VERSION=:b6) and BIN_UNIT=:b7) and BIN_S");
            sqlstm.stmt = "EQ=:b8) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )392;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
            sqlstm.sqhstl[45] = (unsigned int  )401;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[88] = (unsigned int  )11;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[90] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[91] = (unsigned int  )11;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[92] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
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
        DBC_del_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    }

    DB_stop_query_timer("DBC_select_mwipbingrd_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipbingrd_scalar(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPBINGRD where\
 (((FACTORY=:b1 and BIN_ID=:b2) and BIN_VERSION=:b3) and BIN_UNIT=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )779;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
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
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode == 1403) DB_usr_error();
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPBINGRD where\
 ((FACTORY=:b1 and BIN_ID=:b2) and BIN_VERSION=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )814;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_select_mwipbingrd_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipbingrd(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT
                    AND BIN_SEQ = :MWIPBINGRD_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINGRD  where ((((FACTORY=:b0 a\
nd BIN_ID=:b1) and BIN_VERSION=:b2) and BIN_UNIT=:b3) and BIN_SEQ=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )845;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
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
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode == 1403) DB_usr_error();
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL DELETE FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPBINGRD  where ((FACTORY=:b0 and\
 BIN_ID=:b1) and BIN_VERSION=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )880;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
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

    DB_stop_query_timer("DBC_delete_mwipbingrd", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipbingrd(struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPBINGRD( 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    FACTORY, 
                    BIN_ID, 
                    BIN_VERSION, 
                    BIN_UNIT, 
                    BIN_SEQ, 
                    BIN_PROMPT, 
                    BIN_PROMPT_DESC, 
                    BIN_TYPE, 
                    LOGICAL_BIN_FLAG, 
                    KEEP_LOT_FLAG, 
                    SPLIT_LOT_ID_RULE, 
                    SPLIT_BY_BIN_SEQ, 
                    USE_BIN_PROMPT_FAIL_REASON, 
                    KEEP_LOT_QTY_FAIL, 
                    FAIL_REASON_CODE, 
                    REASON_CODE_REF_OPER, 
                    CHANGE_MAT_ID, 
                    CHANGE_MAT_VER, 
                    CHANGE_FLOW, 
                    CHANGE_FLOW_SEQ_NUM, 
                    CHANGE_OPER, 
                    CHANGE_LOT_TYPE, 
                    CHANGE_LOT_PRIORITY, 
                    CHANGE_CREATE_CODE, 
                    CHANGE_OWNER_CODE, 
                    CHANGE_CRR_GROUP, 
                    TRAN_CODE, 
                    TRAN_KEY_REF_OPER, 
                    TRAN_KEY_CODE_1, 
                    TRAN_KEY_CODE_2, 
                    TRAN_KEY_CODE_3, 
                    TRAN_TO_MAT_ID, 
                    TRAN_TO_MAT_VER, 
                    TRAN_TO_FLOW, 
                    TRAN_TO_FLOW_SEQ_NUM, 
                    TRAN_TO_OPER, 
                    TRAN_STOP_OPER, 
                    TRAN_RET_FLOW, 
                    TRAN_RET_FLOW_SEQ_NUM, 
                    TRAN_RET_OPER, 
                    TRAN_RET_OPTION, 
                    TRAN_COMMENT, 
                    TG_TRAN_CODE, 
                    TG_TRAN_KEY_REF_OPER, 
                    TG_TRAN_KEY_CODE_1, 
                    TG_TRAN_KEY_CODE_2, 
                    TG_TRAN_KEY_CODE_3, 
                    TG_TRAN_TO_MAT_ID, 
                    TG_TRAN_TO_MAT_VER, 
                    TG_TRAN_TO_FLOW, 
                    TG_TRAN_TO_FLOW_SEQ_NUM, 
                    TG_TRAN_TO_OPER, 
                    TG_TRAN_STOP_OPER, 
                    TG_TRAN_RET_FLOW, 
                    TG_TRAN_RET_FLOW_SEQ_NUM, 
                    TG_TRAN_RET_OPER, 
                    TG_TRAN_RET_OPTION, 
                    TG_TRAN_COMMENT, 
                    PY_PERIOD, 
                    PY_UPPER_LIMIT, 
                    PY_LOWER_LIMIT, 
                    PY_ALARM_ID, 
                    PY_USE_SPEC_LIMIT_FLAG, 
                    PY_USE_SPEC_CHAR_ID, 
                    BIN_GRADE_CMF_1, 
                    BIN_GRADE_CMF_2, 
                    BIN_GRADE_CMF_3, 
                    BIN_GRADE_CMF_4, 
                    BIN_GRADE_CMF_5, 
                    BIN_GRADE_CMF_6, 
                    BIN_GRADE_CMF_7, 
                    BIN_GRADE_CMF_8, 
                    BIN_GRADE_CMF_9, 
                    BIN_GRADE_CMF_10, 
                    BIN_GRADE_CMF_11, 
                    BIN_GRADE_CMF_12, 
                    BIN_GRADE_CMF_13, 
                    BIN_GRADE_CMF_14, 
                    BIN_GRADE_CMF_15, 
                    BIN_GRADE_CMF_16, 
                    BIN_GRADE_CMF_17, 
                    BIN_GRADE_CMF_18, 
                    BIN_GRADE_CMF_19, 
                    BIN_GRADE_CMF_20
         ) 
        VALUES (
                    :MWIPBINGRD_N.CREATE_USER_ID,
                    :MWIPBINGRD_N.CREATE_TIME,
                    :MWIPBINGRD_N.UPDATE_USER_ID,
                    :MWIPBINGRD_N.UPDATE_TIME,
                    :MWIPBINGRD_N.FACTORY,
                    :MWIPBINGRD_N.BIN_ID,
                    :MWIPBINGRD_N.BIN_VERSION,
                    :MWIPBINGRD_N.BIN_UNIT,
                    :MWIPBINGRD_N.BIN_SEQ,
                    :MWIPBINGRD_N.BIN_PROMPT,
                    :MWIPBINGRD_N.BIN_PROMPT_DESC,
                    :MWIPBINGRD_N.BIN_TYPE,
                    :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                    :MWIPBINGRD_N.KEEP_LOT_FLAG,
                    :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                    :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                    :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                    :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                    :MWIPBINGRD_N.FAIL_REASON_CODE,
                    :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                    :MWIPBINGRD_N.CHANGE_MAT_ID,
                    :MWIPBINGRD_N.CHANGE_MAT_VER,
                    :MWIPBINGRD_N.CHANGE_FLOW,
                    :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.CHANGE_OPER,
                    :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                    :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                    :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                    :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                    :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                    :MWIPBINGRD_N.TRAN_CODE,
                    :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_TO_OPER,
                    :MWIPBINGRD_N.TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TRAN_RET_OPER,
                    :MWIPBINGRD_N.TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TRAN_COMMENT,
                    :MWIPBINGRD_N.TG_TRAN_CODE,
                    :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                    :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                    :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                    :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                    :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                    :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                    :MWIPBINGRD_N.TG_TRAN_COMMENT,
                    :MWIPBINGRD_N.PY_PERIOD,
                    :MWIPBINGRD_N.PY_UPPER_LIMIT,
                    :MWIPBINGRD_N.PY_LOWER_LIMIT,
                    :MWIPBINGRD_N.PY_ALARM_ID,
                    :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                    :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                    :MWIPBINGRD_N.BIN_GRADE_CMF_20
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 93;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPBINGRD (CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPD\
ATE_TIME,FACTORY,BIN_ID,BIN_VERSION,BIN_UNIT,BIN_SEQ,BIN_PROMPT,BIN_PROMPT_D\
ESC,BIN_TYPE,LOGICAL_BIN_FLAG,KEEP_LOT_FLAG,SPLIT_LOT_ID_RULE,SPLIT_BY_BIN_S\
EQ,USE_BIN_PROMPT_FAIL_REASON,KEEP_LOT_QTY_FAIL,FAIL_REASON_CODE,REASON_CODE\
_REF_OPER,CHANGE_MAT_ID,CHANGE_MAT_VER,CHANGE_FLOW,CHANGE_FLOW_SEQ_NUM,CHANG\
E_OPER,CHANGE_LOT_TYPE,CHANGE_LOT_PRIORITY,CHANGE_CREATE_CODE,CHANGE_OWNER_C\
ODE,CHANGE_CRR_GROUP,TRAN_CODE,TRAN_KEY_REF_OPER,TRAN_KEY_CODE_1,TRAN_KEY_CO\
DE_2,TRAN_KEY_CODE_3,TRAN_TO_MAT_ID,TRAN_TO_MAT_VER,TRAN_TO_FLOW,TRAN_TO_FLO\
W_SEQ_NUM,TRAN_TO_OPER,TRAN_STOP_OPER,TRAN_RET_FLOW,TRAN_RET_FLOW_SEQ_NUM,TR\
AN_RET_OPER,TRAN_RET_OPTION,TRAN_COMMENT,TG_TRAN_CODE,TG_TRAN_KEY_REF_OPER,T\
G_TRAN_KEY_CODE_1,TG_TRAN_KEY_CODE_2,TG_TRAN_KEY_CODE_3,TG_TRAN_TO_MAT_ID,TG\
_TRAN_TO_MAT_VER,TG_TRAN_TO_FLOW,TG_TRAN_TO_FLOW_SEQ_NUM,TG_TRAN_TO_OPER,TG_\
TRAN_STOP_OPER,TG_TRAN_RET_FLOW,TG_TRAN_RET_FLOW_SEQ_NUM,TG_TRAN_RET_OPER,TG\
_TRAN_RET_OPTION,TG_TRAN_COMMENT,PY_PERIOD,");
    sqlstm.stmt = "PY_UPPER_LIMIT,PY_LOWER_LIMIT,PY_ALARM_ID,PY_USE_SPEC_LI\
MIT_FLAG,PY_USE_SPEC_CHAR_ID,BIN_GRADE_CMF_1,BIN_GRADE_CMF_2,BIN_GRADE_CMF_3,\
BIN_GRADE_CMF_4,BIN_GRADE_CMF_5,BIN_GRADE_CMF_6,BIN_GRADE_CMF_7,BIN_GRADE_CMF\
_8,BIN_GRADE_CMF_9,BIN_GRADE_CMF_10,BIN_GRADE_CMF_11,BIN_GRADE_CMF_12,BIN_GRA\
DE_CMF_13,BIN_GRADE_CMF_14,BIN_GRADE_CMF_15,BIN_GRADE_CMF_16,BIN_GRADE_CMF_17\
,BIN_GRADE_CMF_18,BIN_GRADE_CMF_19,BIN_GRADE_CMF_20) values (:b0,:b1,:b2,:b3,\
:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b2\
0,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,\
:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b\
51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66\
,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:\
b82,:b83,:b84,:b85,:b86,:b87)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )907;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
    sqlstm.sqhstl[0] = (unsigned int  )21;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
    sqlstm.sqhstl[3] = (unsigned int  )15;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_ID);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
    sqlstm.sqhstl[7] = (unsigned int  )11;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
    sqlstm.sqhstl[10] = (unsigned int  )201;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
    sqlstm.sqhstl[13] = (unsigned int  )2;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
    sqlstm.sqhstl[16] = (unsigned int  )2;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
    sqlstm.sqhstl[17] = (unsigned int  )2;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
    sqlstm.sqhstl[19] = (unsigned int  )11;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
    sqlstm.sqhstl[24] = (unsigned int  )11;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
    sqlstm.sqhstl[25] = (unsigned int  )2;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
    sqlstm.sqhstl[26] = (unsigned int  )2;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
    sqlstm.sqhstl[27] = (unsigned int  )11;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
    sqlstm.sqhstl[28] = (unsigned int  )11;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
    sqlstm.sqhstl[31] = (unsigned int  )11;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
    sqlstm.sqhstl[39] = (unsigned int  )11;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
    sqlstm.sqhstl[40] = (unsigned int  )11;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
    sqlstm.sqhstl[41] = (unsigned int  )21;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
    sqlstm.sqhstl[43] = (unsigned int  )11;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
    sqlstm.sqhstl[44] = (unsigned int  )11;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
    sqlstm.sqhstl[45] = (unsigned int  )401;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
    sqlstm.sqhstl[47] = (unsigned int  )11;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
    sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
    sqlstm.sqhstl[53] = (unsigned int  )21;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
    sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
    sqlstm.sqhstl[55] = (unsigned int  )11;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
    sqlstm.sqhstl[56] = (unsigned int  )11;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
    sqlstm.sqhstl[57] = (unsigned int  )21;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
    sqlstm.sqhstl[59] = (unsigned int  )11;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
    sqlstm.sqhstl[60] = (unsigned int  )11;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
    sqlstm.sqhstl[61] = (unsigned int  )401;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
    sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
    sqlstm.sqhstl[65] = (unsigned int  )21;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
    sqlstm.sqhstl[66] = (unsigned int  )2;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
    sqlstm.sqhstl[67] = (unsigned int  )21;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
    sqlstm.sqhstl[78] = (unsigned int  )31;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
    sqlstm.sqhstl[79] = (unsigned int  )31;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
    sqlstm.sqhstl[81] = (unsigned int  )31;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
    sqlstm.sqhstl[82] = (unsigned int  )31;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
    sqlstm.sqhstl[83] = (unsigned int  )31;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
    sqlstm.sqhstl[84] = (unsigned int  )31;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
    sqlstm.sqhstl[85] = (unsigned int  )31;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
    sqlstm.sqhstl[86] = (unsigned int  )31;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
    sqlstm.sqhstl[87] = (unsigned int  )31;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_mwipbingrd", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipbingrd(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPBINGRD SET
                    CREATE_USER_ID = :MWIPBINGRD_N.CREATE_USER_ID,
                    CREATE_TIME = :MWIPBINGRD_N.CREATE_TIME,
                    UPDATE_USER_ID = :MWIPBINGRD_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPBINGRD_N.UPDATE_TIME,
                    BIN_PROMPT = :MWIPBINGRD_N.BIN_PROMPT,
                    BIN_PROMPT_DESC = :MWIPBINGRD_N.BIN_PROMPT_DESC,
                    BIN_TYPE = :MWIPBINGRD_N.BIN_TYPE,
                    LOGICAL_BIN_FLAG = :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                    KEEP_LOT_FLAG = :MWIPBINGRD_N.KEEP_LOT_FLAG,
                    SPLIT_LOT_ID_RULE = :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                    SPLIT_BY_BIN_SEQ = :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                    USE_BIN_PROMPT_FAIL_REASON = :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL = :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE = :MWIPBINGRD_N.FAIL_REASON_CODE,
                    REASON_CODE_REF_OPER = :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                    CHANGE_MAT_ID = :MWIPBINGRD_N.CHANGE_MAT_ID,
                    CHANGE_MAT_VER = :MWIPBINGRD_N.CHANGE_MAT_VER,
                    CHANGE_FLOW = :MWIPBINGRD_N.CHANGE_FLOW,
                    CHANGE_FLOW_SEQ_NUM = :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                    CHANGE_OPER = :MWIPBINGRD_N.CHANGE_OPER,
                    CHANGE_LOT_TYPE = :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                    CHANGE_LOT_PRIORITY = :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                    CHANGE_CREATE_CODE = :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                    CHANGE_OWNER_CODE = :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                    CHANGE_CRR_GROUP = :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                    TRAN_CODE = :MWIPBINGRD_N.TRAN_CODE,
                    TRAN_KEY_REF_OPER = :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                    TRAN_KEY_CODE_1 = :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2 = :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3 = :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                    TRAN_TO_MAT_ID = :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                    TRAN_TO_MAT_VER = :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                    TRAN_TO_FLOW = :MWIPBINGRD_N.TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM = :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER = :MWIPBINGRD_N.TRAN_TO_OPER,
                    TRAN_STOP_OPER = :MWIPBINGRD_N.TRAN_STOP_OPER,
                    TRAN_RET_FLOW = :MWIPBINGRD_N.TRAN_RET_FLOW,
                    TRAN_RET_FLOW_SEQ_NUM = :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                    TRAN_RET_OPER = :MWIPBINGRD_N.TRAN_RET_OPER,
                    TRAN_RET_OPTION = :MWIPBINGRD_N.TRAN_RET_OPTION,
                    TRAN_COMMENT = :MWIPBINGRD_N.TRAN_COMMENT,
                    TG_TRAN_CODE = :MWIPBINGRD_N.TG_TRAN_CODE,
                    TG_TRAN_KEY_REF_OPER = :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                    TG_TRAN_KEY_CODE_1 = :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                    TG_TRAN_KEY_CODE_2 = :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                    TG_TRAN_KEY_CODE_3 = :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                    TG_TRAN_TO_MAT_ID = :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                    TG_TRAN_TO_MAT_VER = :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                    TG_TRAN_TO_FLOW = :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                    TG_TRAN_TO_FLOW_SEQ_NUM = :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                    TG_TRAN_TO_OPER = :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                    TG_TRAN_STOP_OPER = :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                    TG_TRAN_RET_FLOW = :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                    TG_TRAN_RET_FLOW_SEQ_NUM = :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                    TG_TRAN_RET_OPER = :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                    TG_TRAN_RET_OPTION = :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                    TG_TRAN_COMMENT = :MWIPBINGRD_N.TG_TRAN_COMMENT,
                    PY_PERIOD = :MWIPBINGRD_N.PY_PERIOD,
                    PY_UPPER_LIMIT = :MWIPBINGRD_N.PY_UPPER_LIMIT,
                    PY_LOWER_LIMIT = :MWIPBINGRD_N.PY_LOWER_LIMIT,
                    PY_ALARM_ID = :MWIPBINGRD_N.PY_ALARM_ID,
                    PY_USE_SPEC_LIMIT_FLAG = :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                    PY_USE_SPEC_CHAR_ID = :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                    BIN_GRADE_CMF_1 = :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                    BIN_GRADE_CMF_2 = :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                    BIN_GRADE_CMF_3 = :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                    BIN_GRADE_CMF_4 = :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                    BIN_GRADE_CMF_5 = :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                    BIN_GRADE_CMF_6 = :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                    BIN_GRADE_CMF_7 = :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                    BIN_GRADE_CMF_8 = :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                    BIN_GRADE_CMF_9 = :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                    BIN_GRADE_CMF_10 = :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                    BIN_GRADE_CMF_11 = :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                    BIN_GRADE_CMF_12 = :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                    BIN_GRADE_CMF_13 = :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                    BIN_GRADE_CMF_14 = :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                    BIN_GRADE_CMF_15 = :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                    BIN_GRADE_CMF_16 = :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                    BIN_GRADE_CMF_17 = :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                    BIN_GRADE_CMF_18 = :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                    BIN_GRADE_CMF_19 = :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                    BIN_GRADE_CMF_20 = :MWIPBINGRD_N.BIN_GRADE_CMF_20
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT
                    AND BIN_SEQ = :MWIPBINGRD_N.BIN_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPBINGRD  set CREATE_USER_ID=:b0,CREATE_TIME=:b1,UPD\
ATE_USER_ID=:b2,UPDATE_TIME=:b3,BIN_PROMPT=:b4,BIN_PROMPT_DESC=:b5,BIN_TYPE=\
:b6,LOGICAL_BIN_FLAG=:b7,KEEP_LOT_FLAG=:b8,SPLIT_LOT_ID_RULE=:b9,SPLIT_BY_BI\
N_SEQ=:b10,USE_BIN_PROMPT_FAIL_REASON=:b11,KEEP_LOT_QTY_FAIL=:b12,FAIL_REASO\
N_CODE=:b13,REASON_CODE_REF_OPER=:b14,CHANGE_MAT_ID=:b15,CHANGE_MAT_VER=:b16\
,CHANGE_FLOW=:b17,CHANGE_FLOW_SEQ_NUM=:b18,CHANGE_OPER=:b19,CHANGE_LOT_TYPE=\
:b20,CHANGE_LOT_PRIORITY=:b21,CHANGE_CREATE_CODE=:b22,CHANGE_OWNER_CODE=:b23\
,CHANGE_CRR_GROUP=:b24,TRAN_CODE=:b25,TRAN_KEY_REF_OPER=:b26,TRAN_KEY_CODE_1\
=:b27,TRAN_KEY_CODE_2=:b28,TRAN_KEY_CODE_3=:b29,TRAN_TO_MAT_ID=:b30,TRAN_TO_\
MAT_VER=:b31,TRAN_TO_FLOW=:b32,TRAN_TO_FLOW_SEQ_NUM=:b33,TRAN_TO_OPER=:b34,T\
RAN_STOP_OPER=:b35,TRAN_RET_FLOW=:b36,TRAN_RET_FLOW_SEQ_NUM=:b37,TRAN_RET_OP\
ER=:b38,TRAN_RET_OPTION=:b39,TRAN_COMMENT=:b40,TG_TRAN_CODE=:b41,TG_TRAN_KEY\
_REF_OPER=:b42,TG_TRAN_KEY_CODE_1=:b43,TG_TRAN_KEY_CODE_2=:b44,TG_TRAN_KEY_C\
ODE_3=:b45,TG_TRAN_TO_MAT_ID=:b46,TG_TRAN_TO_MAT_VE");
            sqlstm.stmt = "R=:b47,TG_TRAN_TO_FLOW=:b48,TG_TRAN_TO_FLOW_SEQ_\
NUM=:b49,TG_TRAN_TO_OPER=:b50,TG_TRAN_STOP_OPER=:b51,TG_TRAN_RET_FLOW=:b52,TG\
_TRAN_RET_FLOW_SEQ_NUM=:b53,TG_TRAN_RET_OPER=:b54,TG_TRAN_RET_OPTION=:b55,TG_\
TRAN_COMMENT=:b56,PY_PERIOD=:b57,PY_UPPER_LIMIT=:b58,PY_LOWER_LIMIT=:b59,PY_A\
LARM_ID=:b60,PY_USE_SPEC_LIMIT_FLAG=:b61,PY_USE_SPEC_CHAR_ID=:b62,BIN_GRADE_C\
MF_1=:b63,BIN_GRADE_CMF_2=:b64,BIN_GRADE_CMF_3=:b65,BIN_GRADE_CMF_4=:b66,BIN_\
GRADE_CMF_5=:b67,BIN_GRADE_CMF_6=:b68,BIN_GRADE_CMF_7=:b69,BIN_GRADE_CMF_8=:b\
70,BIN_GRADE_CMF_9=:b71,BIN_GRADE_CMF_10=:b72,BIN_GRADE_CMF_11=:b73,BIN_GRADE\
_CMF_12=:b74,BIN_GRADE_CMF_13=:b75,BIN_GRADE_CMF_14=:b76,BIN_GRADE_CMF_15=:b7\
7,BIN_GRADE_CMF_16=:b78,BIN_GRADE_CMF_17=:b79,BIN_GRADE_CMF_18=:b80,BIN_GRADE\
_CMF_19=:b81,BIN_GRADE_CMF_20=:b82 where ((((FACTORY=:b83 and BIN_ID=:b84) an\
d BIN_VERSION=:b85) and BIN_UNIT=:b86) and BIN_SEQ=:b87)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1274;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
            sqlstm.sqhstl[20] = (unsigned int  )2;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
            sqlstm.sqhstl[34] = (unsigned int  )11;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
            sqlstm.sqhstl[38] = (unsigned int  )11;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
            sqlstm.sqhstl[40] = (unsigned int  )401;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[42] = (unsigned int  )11;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
            sqlstm.sqhstl[56] = (unsigned int  )401;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[83] = (unsigned int  )11;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[86] = (unsigned int  )11;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[87] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_mwipbingrd", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipbingrd(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPBINGRD_CUR_1 CURSOR FOR
                SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_SEQ,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    KEEP_LOT_FLAG,
                    SPLIT_LOT_ID_RULE,
                    SPLIT_BY_BIN_SEQ,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    REASON_CODE_REF_OPER,
                    CHANGE_MAT_ID,
                    CHANGE_MAT_VER,
                    CHANGE_FLOW,
                    CHANGE_FLOW_SEQ_NUM,
                    CHANGE_OPER,
                    CHANGE_LOT_TYPE,
                    CHANGE_LOT_PRIORITY,
                    CHANGE_CREATE_CODE,
                    CHANGE_OWNER_CODE,
                    CHANGE_CRR_GROUP,
                    TRAN_CODE,
                    TRAN_KEY_REF_OPER,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_TO_MAT_ID,
                    TRAN_TO_MAT_VER,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    TRAN_STOP_OPER,
                    TRAN_RET_FLOW,
                    TRAN_RET_FLOW_SEQ_NUM,
                    TRAN_RET_OPER,
                    TRAN_RET_OPTION,
                    TRAN_COMMENT,
                    TG_TRAN_CODE,
                    TG_TRAN_KEY_REF_OPER,
                    TG_TRAN_KEY_CODE_1,
                    TG_TRAN_KEY_CODE_2,
                    TG_TRAN_KEY_CODE_3,
                    TG_TRAN_TO_MAT_ID,
                    TG_TRAN_TO_MAT_VER,
                    TG_TRAN_TO_FLOW,
                    TG_TRAN_TO_FLOW_SEQ_NUM,
                    TG_TRAN_TO_OPER,
                    TG_TRAN_STOP_OPER,
                    TG_TRAN_RET_FLOW,
                    TG_TRAN_RET_FLOW_SEQ_NUM,
                    TG_TRAN_RET_OPER,
                    TG_TRAN_RET_OPTION,
                    TG_TRAN_COMMENT,
                    PY_PERIOD,
                    PY_UPPER_LIMIT,
                    PY_LOWER_LIMIT,
                    PY_ALARM_ID,
                    PY_USE_SPEC_LIMIT_FLAG,
                    PY_USE_SPEC_CHAR_ID,
                    BIN_GRADE_CMF_1,
                    BIN_GRADE_CMF_2,
                    BIN_GRADE_CMF_3,
                    BIN_GRADE_CMF_4,
                    BIN_GRADE_CMF_5,
                    BIN_GRADE_CMF_6,
                    BIN_GRADE_CMF_7,
                    BIN_GRADE_CMF_8,
                    BIN_GRADE_CMF_9,
                    BIN_GRADE_CMF_10,
                    BIN_GRADE_CMF_11,
                    BIN_GRADE_CMF_12,
                    BIN_GRADE_CMF_13,
                    BIN_GRADE_CMF_14,
                    BIN_GRADE_CMF_15,
                    BIN_GRADE_CMF_16,
                    BIN_GRADE_CMF_17,
                    BIN_GRADE_CMF_18,
                    BIN_GRADE_CMF_19,
                    BIN_GRADE_CMF_20
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                ORDER BY BIN_UNIT ASC, BIN_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPBINGRD_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_SEQ ,BIN_PROMPT ,BIN_PROMPT_\
DESC ,BIN_TYPE ,LOGICAL_BIN_FLAG ,KEEP_LOT_FLAG ,SPLIT_LOT_ID_RULE ,SPLIT_BY\
_BIN_SEQ ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LOT_QTY_FAIL ,FAIL_REASON_CODE ,R\
EASON_CODE_REF_OPER ,CHANGE_MAT_ID ,CHANGE_MAT_VER ,CHANGE_FLOW ,CHANGE_FLOW\
_SEQ_NUM ,CHANGE_OPER ,CHANGE_LOT_TYPE ,CHANGE_LOT_PRIORITY ,CHANGE_CREATE_C\
ODE ,CHANGE_OWNER_CODE ,CHANGE_CRR_GROUP ,TRAN_CODE ,TRAN_KEY_REF_OPER ,TRAN\
_KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_TO_MAT_ID ,TRAN_TO_MAT_V\
ER ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,TRAN_STOP_OPER ,TRAN_R\
ET_FLOW ,TRAN_RET_FLOW_SEQ_NUM ,TRAN_RET_OPER ,TRAN_RET_OPTION ,TRAN_COMMENT\
 ,TG_TRAN_CODE ,TG_TRAN_KEY_REF_OPER ,TG_TRAN_KEY_CODE_1 ,TG_TRAN_KEY_CODE_2\
 ,TG_TRAN_KEY_CODE_3 ,TG_TRAN_TO_MAT_ID ,TG_TRAN_TO_MAT_VER ,TG_TRAN_TO_FLOW\
 ,TG_TRAN_TO_FLOW_SEQ_NUM ,TG_TRAN_TO_OPER ,TG_TRAN_STOP_OPER ,TG_TRAN_RET_F\
LOW ,TG_TRAN_RET_FLOW_SEQ_NUM ,TG_TRAN_RET_OPER ,TG");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1641;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL DECLARE DBC_MWIPBINGRD_CUR_2 CURSOR FOR
                SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    BIN_ID,
                    BIN_VERSION,
                    BIN_UNIT,
                    BIN_SEQ,
                    BIN_PROMPT,
                    BIN_PROMPT_DESC,
                    BIN_TYPE,
                    LOGICAL_BIN_FLAG,
                    KEEP_LOT_FLAG,
                    SPLIT_LOT_ID_RULE,
                    SPLIT_BY_BIN_SEQ,
                    USE_BIN_PROMPT_FAIL_REASON,
                    KEEP_LOT_QTY_FAIL,
                    FAIL_REASON_CODE,
                    REASON_CODE_REF_OPER,
                    CHANGE_MAT_ID,
                    CHANGE_MAT_VER,
                    CHANGE_FLOW,
                    CHANGE_FLOW_SEQ_NUM,
                    CHANGE_OPER,
                    CHANGE_LOT_TYPE,
                    CHANGE_LOT_PRIORITY,
                    CHANGE_CREATE_CODE,
                    CHANGE_OWNER_CODE,
                    CHANGE_CRR_GROUP,
                    TRAN_CODE,
                    TRAN_KEY_REF_OPER,
                    TRAN_KEY_CODE_1,
                    TRAN_KEY_CODE_2,
                    TRAN_KEY_CODE_3,
                    TRAN_TO_MAT_ID,
                    TRAN_TO_MAT_VER,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    TRAN_STOP_OPER,
                    TRAN_RET_FLOW,
                    TRAN_RET_FLOW_SEQ_NUM,
                    TRAN_RET_OPER,
                    TRAN_RET_OPTION,
                    TRAN_COMMENT,
                    TG_TRAN_CODE,
                    TG_TRAN_KEY_REF_OPER,
                    TG_TRAN_KEY_CODE_1,
                    TG_TRAN_KEY_CODE_2,
                    TG_TRAN_KEY_CODE_3,
                    TG_TRAN_TO_MAT_ID,
                    TG_TRAN_TO_MAT_VER,
                    TG_TRAN_TO_FLOW,
                    TG_TRAN_TO_FLOW_SEQ_NUM,
                    TG_TRAN_TO_OPER,
                    TG_TRAN_STOP_OPER,
                    TG_TRAN_RET_FLOW,
                    TG_TRAN_RET_FLOW_SEQ_NUM,
                    TG_TRAN_RET_OPER,
                    TG_TRAN_RET_OPTION,
                    TG_TRAN_COMMENT,
                    PY_PERIOD,
                    PY_UPPER_LIMIT,
                    PY_LOWER_LIMIT,
                    PY_ALARM_ID,
                    PY_USE_SPEC_LIMIT_FLAG,
                    PY_USE_SPEC_CHAR_ID,
                    BIN_GRADE_CMF_1,
                    BIN_GRADE_CMF_2,
                    BIN_GRADE_CMF_3,
                    BIN_GRADE_CMF_4,
                    BIN_GRADE_CMF_5,
                    BIN_GRADE_CMF_6,
                    BIN_GRADE_CMF_7,
                    BIN_GRADE_CMF_8,
                    BIN_GRADE_CMF_9,
                    BIN_GRADE_CMF_10,
                    BIN_GRADE_CMF_11,
                    BIN_GRADE_CMF_12,
                    BIN_GRADE_CMF_13,
                    BIN_GRADE_CMF_14,
                    BIN_GRADE_CMF_15,
                    BIN_GRADE_CMF_16,
                    BIN_GRADE_CMF_17,
                    BIN_GRADE_CMF_18,
                    BIN_GRADE_CMF_19,
                    BIN_GRADE_CMF_20
                FROM MWIPBINGRD
                WHERE FACTORY = :MWIPBINGRD_N.FACTORY
                    AND BIN_ID = :MWIPBINGRD_N.BIN_ID
                    AND BIN_VERSION = :MWIPBINGRD_N.BIN_VERSION
                    AND BIN_UNIT = :MWIPBINGRD_N.BIN_UNIT
                    AND BIN_SEQ >= :MWIPBINGRD_N.BIN_SEQ
                ORDER BY BIN_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPBINGRD_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,BIN_ID ,BIN_VERSION ,BIN_UNIT ,BIN_SEQ ,BIN_PROMPT ,BIN_PROMPT_\
DESC ,BIN_TYPE ,LOGICAL_BIN_FLAG ,KEEP_LOT_FLAG ,SPLIT_LOT_ID_RULE ,SPLIT_BY\
_BIN_SEQ ,USE_BIN_PROMPT_FAIL_REASON ,KEEP_LOT_QTY_FAIL ,FAIL_REASON_CODE ,R\
EASON_CODE_REF_OPER ,CHANGE_MAT_ID ,CHANGE_MAT_VER ,CHANGE_FLOW ,CHANGE_FLOW\
_SEQ_NUM ,CHANGE_OPER ,CHANGE_LOT_TYPE ,CHANGE_LOT_PRIORITY ,CHANGE_CREATE_C\
ODE ,CHANGE_OWNER_CODE ,CHANGE_CRR_GROUP ,TRAN_CODE ,TRAN_KEY_REF_OPER ,TRAN\
_KEY_CODE_1 ,TRAN_KEY_CODE_2 ,TRAN_KEY_CODE_3 ,TRAN_TO_MAT_ID ,TRAN_TO_MAT_V\
ER ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,TRAN_STOP_OPER ,TRAN_R\
ET_FLOW ,TRAN_RET_FLOW_SEQ_NUM ,TRAN_RET_OPER ,TRAN_RET_OPTION ,TRAN_COMMENT\
 ,TG_TRAN_CODE ,TG_TRAN_KEY_REF_OPER ,TG_TRAN_KEY_CODE_1 ,TG_TRAN_KEY_CODE_2\
 ,TG_TRAN_KEY_CODE_3 ,TG_TRAN_TO_MAT_ID ,TG_TRAN_TO_MAT_VER ,TG_TRAN_TO_FLOW\
 ,TG_TRAN_TO_FLOW_SEQ_NUM ,TG_TRAN_TO_OPER ,TG_TRAN_STOP_OPER ,TG_TRAN_RET_F\
LOW ,TG_TRAN_RET_FLOW_SEQ_NUM ,TG_TRAN_RET_OPER ,TG");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1668;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
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

    DB_stop_query_timer("DBC_open_mwipbingrd", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipbingrd(int sel_type, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPBINGRD_N_TAG MWIPBINGRD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPBINGRD_CUR_1 INTO
                :MWIPBINGRD_N.CREATE_USER_ID,
                :MWIPBINGRD_N.CREATE_TIME,
                :MWIPBINGRD_N.UPDATE_USER_ID,
                :MWIPBINGRD_N.UPDATE_TIME,
                :MWIPBINGRD_N.FACTORY,
                :MWIPBINGRD_N.BIN_ID,
                :MWIPBINGRD_N.BIN_VERSION,
                :MWIPBINGRD_N.BIN_UNIT,
                :MWIPBINGRD_N.BIN_SEQ,
                :MWIPBINGRD_N.BIN_PROMPT,
                :MWIPBINGRD_N.BIN_PROMPT_DESC,
                :MWIPBINGRD_N.BIN_TYPE,
                :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                :MWIPBINGRD_N.KEEP_LOT_FLAG,
                :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                :MWIPBINGRD_N.FAIL_REASON_CODE,
                :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                :MWIPBINGRD_N.CHANGE_MAT_ID,
                :MWIPBINGRD_N.CHANGE_MAT_VER,
                :MWIPBINGRD_N.CHANGE_FLOW,
                :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.CHANGE_OPER,
                :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                :MWIPBINGRD_N.TRAN_CODE,
                :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                :MWIPBINGRD_N.TRAN_TO_FLOW,
                :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TRAN_TO_OPER,
                :MWIPBINGRD_N.TRAN_STOP_OPER,
                :MWIPBINGRD_N.TRAN_RET_FLOW,
                :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TRAN_RET_OPER,
                :MWIPBINGRD_N.TRAN_RET_OPTION,
                :MWIPBINGRD_N.TRAN_COMMENT,
                :MWIPBINGRD_N.TG_TRAN_CODE,
                :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                :MWIPBINGRD_N.TG_TRAN_COMMENT,
                :MWIPBINGRD_N.PY_PERIOD,
                :MWIPBINGRD_N.PY_UPPER_LIMIT,
                :MWIPBINGRD_N.PY_LOWER_LIMIT,
                :MWIPBINGRD_N.PY_ALARM_ID,
                :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                :MWIPBINGRD_N.BIN_GRADE_CMF_20; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1703;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
            sqlstm.sqhstl[45] = (unsigned int  )401;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_MWIPBINGRD_CUR_2 INTO
                :MWIPBINGRD_N.CREATE_USER_ID,
                :MWIPBINGRD_N.CREATE_TIME,
                :MWIPBINGRD_N.UPDATE_USER_ID,
                :MWIPBINGRD_N.UPDATE_TIME,
                :MWIPBINGRD_N.FACTORY,
                :MWIPBINGRD_N.BIN_ID,
                :MWIPBINGRD_N.BIN_VERSION,
                :MWIPBINGRD_N.BIN_UNIT,
                :MWIPBINGRD_N.BIN_SEQ,
                :MWIPBINGRD_N.BIN_PROMPT,
                :MWIPBINGRD_N.BIN_PROMPT_DESC,
                :MWIPBINGRD_N.BIN_TYPE,
                :MWIPBINGRD_N.LOGICAL_BIN_FLAG,
                :MWIPBINGRD_N.KEEP_LOT_FLAG,
                :MWIPBINGRD_N.SPLIT_LOT_ID_RULE,
                :MWIPBINGRD_N.SPLIT_BY_BIN_SEQ,
                :MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON,
                :MWIPBINGRD_N.KEEP_LOT_QTY_FAIL,
                :MWIPBINGRD_N.FAIL_REASON_CODE,
                :MWIPBINGRD_N.REASON_CODE_REF_OPER,
                :MWIPBINGRD_N.CHANGE_MAT_ID,
                :MWIPBINGRD_N.CHANGE_MAT_VER,
                :MWIPBINGRD_N.CHANGE_FLOW,
                :MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.CHANGE_OPER,
                :MWIPBINGRD_N.CHANGE_LOT_TYPE,
                :MWIPBINGRD_N.CHANGE_LOT_PRIORITY,
                :MWIPBINGRD_N.CHANGE_CREATE_CODE,
                :MWIPBINGRD_N.CHANGE_OWNER_CODE,
                :MWIPBINGRD_N.CHANGE_CRR_GROUP,
                :MWIPBINGRD_N.TRAN_CODE,
                :MWIPBINGRD_N.TRAN_KEY_REF_OPER,
                :MWIPBINGRD_N.TRAN_KEY_CODE_1,
                :MWIPBINGRD_N.TRAN_KEY_CODE_2,
                :MWIPBINGRD_N.TRAN_KEY_CODE_3,
                :MWIPBINGRD_N.TRAN_TO_MAT_ID,
                :MWIPBINGRD_N.TRAN_TO_MAT_VER,
                :MWIPBINGRD_N.TRAN_TO_FLOW,
                :MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TRAN_TO_OPER,
                :MWIPBINGRD_N.TRAN_STOP_OPER,
                :MWIPBINGRD_N.TRAN_RET_FLOW,
                :MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TRAN_RET_OPER,
                :MWIPBINGRD_N.TRAN_RET_OPTION,
                :MWIPBINGRD_N.TRAN_COMMENT,
                :MWIPBINGRD_N.TG_TRAN_CODE,
                :MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_1,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_2,
                :MWIPBINGRD_N.TG_TRAN_KEY_CODE_3,
                :MWIPBINGRD_N.TG_TRAN_TO_MAT_ID,
                :MWIPBINGRD_N.TG_TRAN_TO_MAT_VER,
                :MWIPBINGRD_N.TG_TRAN_TO_FLOW,
                :MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TG_TRAN_TO_OPER,
                :MWIPBINGRD_N.TG_TRAN_STOP_OPER,
                :MWIPBINGRD_N.TG_TRAN_RET_FLOW,
                :MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM,
                :MWIPBINGRD_N.TG_TRAN_RET_OPER,
                :MWIPBINGRD_N.TG_TRAN_RET_OPTION,
                :MWIPBINGRD_N.TG_TRAN_COMMENT,
                :MWIPBINGRD_N.PY_PERIOD,
                :MWIPBINGRD_N.PY_UPPER_LIMIT,
                :MWIPBINGRD_N.PY_LOWER_LIMIT,
                :MWIPBINGRD_N.PY_ALARM_ID,
                :MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG,
                :MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID,
                :MWIPBINGRD_N.BIN_GRADE_CMF_1,
                :MWIPBINGRD_N.BIN_GRADE_CMF_2,
                :MWIPBINGRD_N.BIN_GRADE_CMF_3,
                :MWIPBINGRD_N.BIN_GRADE_CMF_4,
                :MWIPBINGRD_N.BIN_GRADE_CMF_5,
                :MWIPBINGRD_N.BIN_GRADE_CMF_6,
                :MWIPBINGRD_N.BIN_GRADE_CMF_7,
                :MWIPBINGRD_N.BIN_GRADE_CMF_8,
                :MWIPBINGRD_N.BIN_GRADE_CMF_9,
                :MWIPBINGRD_N.BIN_GRADE_CMF_10,
                :MWIPBINGRD_N.BIN_GRADE_CMF_11,
                :MWIPBINGRD_N.BIN_GRADE_CMF_12,
                :MWIPBINGRD_N.BIN_GRADE_CMF_13,
                :MWIPBINGRD_N.BIN_GRADE_CMF_14,
                :MWIPBINGRD_N.BIN_GRADE_CMF_15,
                :MWIPBINGRD_N.BIN_GRADE_CMF_16,
                :MWIPBINGRD_N.BIN_GRADE_CMF_17,
                :MWIPBINGRD_N.BIN_GRADE_CMF_18,
                :MWIPBINGRD_N.BIN_GRADE_CMF_19,
                :MWIPBINGRD_N.BIN_GRADE_CMF_20; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2070;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPBINGRD_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPBINGRD_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPBINGRD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPBINGRD_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPBINGRD_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPBINGRD_N.BIN_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPBINGRD_N.BIN_VERSION);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPBINGRD_N.BIN_UNIT);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPBINGRD_N.BIN_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPBINGRD_N.BIN_PROMPT_DESC);
            sqlstm.sqhstl[10] = (unsigned int  )201;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPBINGRD_N.BIN_TYPE);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPBINGRD_N.LOGICAL_BIN_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_FLAG);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPBINGRD_N.SPLIT_LOT_ID_RULE);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MWIPBINGRD_N.SPLIT_BY_BIN_SEQ);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPBINGRD_N.USE_BIN_PROMPT_FAIL_REASON);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPBINGRD_N.KEEP_LOT_QTY_FAIL);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPBINGRD_N.FAIL_REASON_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPBINGRD_N.REASON_CODE_REF_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPBINGRD_N.CHANGE_MAT_ID);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MWIPBINGRD_N.CHANGE_MAT_VER);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPBINGRD_N.CHANGE_FLOW);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPBINGRD_N.CHANGE_FLOW_SEQ_NUM);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPBINGRD_N.CHANGE_OPER);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_TYPE);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPBINGRD_N.CHANGE_LOT_PRIORITY);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPBINGRD_N.CHANGE_CREATE_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPBINGRD_N.CHANGE_OWNER_CODE);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPBINGRD_N.CHANGE_CRR_GROUP);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPBINGRD_N.TRAN_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[31] = (unsigned int  )11;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_1);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_2);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPBINGRD_N.TRAN_KEY_CODE_3);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPBINGRD_N.TRAN_TO_MAT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_MAT_VER);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPBINGRD_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPBINGRD_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPBINGRD_N.TRAN_TO_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPBINGRD_N.TRAN_STOP_OPER);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPBINGRD_N.TRAN_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPBINGRD_N.TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPBINGRD_N.TRAN_RET_OPTION);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPBINGRD_N.TRAN_COMMENT);
            sqlstm.sqhstl[45] = (unsigned int  )401;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPBINGRD_N.TG_TRAN_CODE);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_REF_OPER);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_1);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_2);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPBINGRD_N.TG_TRAN_KEY_CODE_3);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_MAT_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_MAT_VER);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_FLOW);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPBINGRD_N.TG_TRAN_TO_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPBINGRD_N.TG_TRAN_STOP_OPER);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_FLOW);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MWIPBINGRD_N.TG_TRAN_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPER);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPBINGRD_N.TG_TRAN_RET_OPTION);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPBINGRD_N.TG_TRAN_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MWIPBINGRD_N.PY_PERIOD);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPBINGRD_N.PY_UPPER_LIMIT);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPBINGRD_N.PY_LOWER_LIMIT);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPBINGRD_N.PY_ALARM_ID);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_LIMIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPBINGRD_N.PY_USE_SPEC_CHAR_ID);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_1);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_2);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_3);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_4);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_5);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_6);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_7);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_8);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_9);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_10);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_11);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_12);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_13);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_14);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_15);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_16);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_17);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_18);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_19);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPBINGRD_N.BIN_GRADE_CMF_20);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
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
        DBC_del_null_mwipbingrd(&MWIPBINGRD_N, MWIPBINGRD);
    }

    DB_stop_query_timer("DBC_fetch_mwipbingrd", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipbingrd(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPBINGRD_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2437;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBC_MWIPBINGRD_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2452;
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

    DB_stop_query_timer("DBC_close_mwipbingrd", sel_type);
}


/* Initialize Function */
void DBC_init_mwipbingrd(struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* memset by Space */
    memset(MWIPBINGRD, ' ', sizeof(struct MWIPBINGRD_TAG));
    
    MWIPBINGRD->BIN_VERSION = 0;
    MWIPBINGRD->BIN_SEQ = 0;
    MWIPBINGRD->SPLIT_BY_BIN_SEQ = 0;
    MWIPBINGRD->CHANGE_MAT_VER = 0;
    MWIPBINGRD->CHANGE_FLOW_SEQ_NUM = 0;
    MWIPBINGRD->TRAN_TO_MAT_VER = 0;
    MWIPBINGRD->TRAN_TO_FLOW_SEQ_NUM = 0;
    MWIPBINGRD->TRAN_RET_FLOW_SEQ_NUM = 0;
    MWIPBINGRD->TG_TRAN_TO_MAT_VER = 0;
    MWIPBINGRD->TG_TRAN_TO_FLOW_SEQ_NUM = 0;
    MWIPBINGRD->TG_TRAN_RET_FLOW_SEQ_NUM = 0;
    MWIPBINGRD->PY_PERIOD = 0;
}


/* Add Null Function */
void DBC_add_null_mwipbingrd(struct MWIPBINGRD_N_TAG *MWIPBINGRD_N, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    /* memset by NULL */
    memset(MWIPBINGRD_N, '\0', sizeof(struct MWIPBINGRD_N_TAG));
    
    MEMCPY_AN(MWIPBINGRD_N->CREATE_USER_ID, MWIPBINGRD->CREATE_USER_ID, sizeof(MWIPBINGRD->CREATE_USER_ID));
    MEMCPY_AN(MWIPBINGRD_N->CREATE_TIME, MWIPBINGRD->CREATE_TIME, sizeof(MWIPBINGRD->CREATE_TIME));
    MEMCPY_AN(MWIPBINGRD_N->UPDATE_USER_ID, MWIPBINGRD->UPDATE_USER_ID, sizeof(MWIPBINGRD->UPDATE_USER_ID));
    MEMCPY_AN(MWIPBINGRD_N->UPDATE_TIME, MWIPBINGRD->UPDATE_TIME, sizeof(MWIPBINGRD->UPDATE_TIME));
    MEMCPY_AN(MWIPBINGRD_N->FACTORY, MWIPBINGRD->FACTORY, sizeof(MWIPBINGRD->FACTORY));
    MEMCPY_AN(MWIPBINGRD_N->BIN_ID, MWIPBINGRD->BIN_ID, sizeof(MWIPBINGRD->BIN_ID));
    MWIPBINGRD_N->BIN_VERSION = MWIPBINGRD->BIN_VERSION;
    MEMCPY_AN(MWIPBINGRD_N->BIN_UNIT, MWIPBINGRD->BIN_UNIT, sizeof(MWIPBINGRD->BIN_UNIT));
    MWIPBINGRD_N->BIN_SEQ = MWIPBINGRD->BIN_SEQ;
    MEMCPY_AN(MWIPBINGRD_N->BIN_PROMPT, MWIPBINGRD->BIN_PROMPT, sizeof(MWIPBINGRD->BIN_PROMPT));
    MEMCPY_AN(MWIPBINGRD_N->BIN_PROMPT_DESC, MWIPBINGRD->BIN_PROMPT_DESC, sizeof(MWIPBINGRD->BIN_PROMPT_DESC));
    MWIPBINGRD_N->BIN_TYPE[0] = MWIPBINGRD->BIN_TYPE;
    MWIPBINGRD_N->LOGICAL_BIN_FLAG[0] = MWIPBINGRD->LOGICAL_BIN_FLAG;
    MWIPBINGRD_N->KEEP_LOT_FLAG[0] = MWIPBINGRD->KEEP_LOT_FLAG;
    MEMCPY_AN(MWIPBINGRD_N->SPLIT_LOT_ID_RULE, MWIPBINGRD->SPLIT_LOT_ID_RULE, sizeof(MWIPBINGRD->SPLIT_LOT_ID_RULE));
    MWIPBINGRD_N->SPLIT_BY_BIN_SEQ = MWIPBINGRD->SPLIT_BY_BIN_SEQ;
    MWIPBINGRD_N->USE_BIN_PROMPT_FAIL_REASON[0] = MWIPBINGRD->USE_BIN_PROMPT_FAIL_REASON;
    MWIPBINGRD_N->KEEP_LOT_QTY_FAIL[0] = MWIPBINGRD->KEEP_LOT_QTY_FAIL;
    MEMCPY_AN(MWIPBINGRD_N->FAIL_REASON_CODE, MWIPBINGRD->FAIL_REASON_CODE, sizeof(MWIPBINGRD->FAIL_REASON_CODE));
    MEMCPY_AN(MWIPBINGRD_N->REASON_CODE_REF_OPER, MWIPBINGRD->REASON_CODE_REF_OPER, sizeof(MWIPBINGRD->REASON_CODE_REF_OPER));
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_MAT_ID, MWIPBINGRD->CHANGE_MAT_ID, sizeof(MWIPBINGRD->CHANGE_MAT_ID));
    MWIPBINGRD_N->CHANGE_MAT_VER = MWIPBINGRD->CHANGE_MAT_VER;
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_FLOW, MWIPBINGRD->CHANGE_FLOW, sizeof(MWIPBINGRD->CHANGE_FLOW));
    MWIPBINGRD_N->CHANGE_FLOW_SEQ_NUM = MWIPBINGRD->CHANGE_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_OPER, MWIPBINGRD->CHANGE_OPER, sizeof(MWIPBINGRD->CHANGE_OPER));
    MWIPBINGRD_N->CHANGE_LOT_TYPE[0] = MWIPBINGRD->CHANGE_LOT_TYPE;
    MWIPBINGRD_N->CHANGE_LOT_PRIORITY[0] = MWIPBINGRD->CHANGE_LOT_PRIORITY;
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_CREATE_CODE, MWIPBINGRD->CHANGE_CREATE_CODE, sizeof(MWIPBINGRD->CHANGE_CREATE_CODE));
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_OWNER_CODE, MWIPBINGRD->CHANGE_OWNER_CODE, sizeof(MWIPBINGRD->CHANGE_OWNER_CODE));
    MEMCPY_AN(MWIPBINGRD_N->CHANGE_CRR_GROUP, MWIPBINGRD->CHANGE_CRR_GROUP, sizeof(MWIPBINGRD->CHANGE_CRR_GROUP));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_CODE, MWIPBINGRD->TRAN_CODE, sizeof(MWIPBINGRD->TRAN_CODE));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_KEY_REF_OPER, MWIPBINGRD->TRAN_KEY_REF_OPER, sizeof(MWIPBINGRD->TRAN_KEY_REF_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_KEY_CODE_1, MWIPBINGRD->TRAN_KEY_CODE_1, sizeof(MWIPBINGRD->TRAN_KEY_CODE_1));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_KEY_CODE_2, MWIPBINGRD->TRAN_KEY_CODE_2, sizeof(MWIPBINGRD->TRAN_KEY_CODE_2));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_KEY_CODE_3, MWIPBINGRD->TRAN_KEY_CODE_3, sizeof(MWIPBINGRD->TRAN_KEY_CODE_3));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_TO_MAT_ID, MWIPBINGRD->TRAN_TO_MAT_ID, sizeof(MWIPBINGRD->TRAN_TO_MAT_ID));
    MWIPBINGRD_N->TRAN_TO_MAT_VER = MWIPBINGRD->TRAN_TO_MAT_VER;
    MEMCPY_AN(MWIPBINGRD_N->TRAN_TO_FLOW, MWIPBINGRD->TRAN_TO_FLOW, sizeof(MWIPBINGRD->TRAN_TO_FLOW));
    MWIPBINGRD_N->TRAN_TO_FLOW_SEQ_NUM = MWIPBINGRD->TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINGRD_N->TRAN_TO_OPER, MWIPBINGRD->TRAN_TO_OPER, sizeof(MWIPBINGRD->TRAN_TO_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_STOP_OPER, MWIPBINGRD->TRAN_STOP_OPER, sizeof(MWIPBINGRD->TRAN_STOP_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_RET_FLOW, MWIPBINGRD->TRAN_RET_FLOW, sizeof(MWIPBINGRD->TRAN_RET_FLOW));
    MWIPBINGRD_N->TRAN_RET_FLOW_SEQ_NUM = MWIPBINGRD->TRAN_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINGRD_N->TRAN_RET_OPER, MWIPBINGRD->TRAN_RET_OPER, sizeof(MWIPBINGRD->TRAN_RET_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_RET_OPTION, MWIPBINGRD->TRAN_RET_OPTION, sizeof(MWIPBINGRD->TRAN_RET_OPTION));
    MEMCPY_AN(MWIPBINGRD_N->TRAN_COMMENT, MWIPBINGRD->TRAN_COMMENT, sizeof(MWIPBINGRD->TRAN_COMMENT));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_CODE, MWIPBINGRD->TG_TRAN_CODE, sizeof(MWIPBINGRD->TG_TRAN_CODE));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_KEY_REF_OPER, MWIPBINGRD->TG_TRAN_KEY_REF_OPER, sizeof(MWIPBINGRD->TG_TRAN_KEY_REF_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_KEY_CODE_1, MWIPBINGRD->TG_TRAN_KEY_CODE_1, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_1));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_KEY_CODE_2, MWIPBINGRD->TG_TRAN_KEY_CODE_2, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_2));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_KEY_CODE_3, MWIPBINGRD->TG_TRAN_KEY_CODE_3, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_3));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_TO_MAT_ID, MWIPBINGRD->TG_TRAN_TO_MAT_ID, sizeof(MWIPBINGRD->TG_TRAN_TO_MAT_ID));
    MWIPBINGRD_N->TG_TRAN_TO_MAT_VER = MWIPBINGRD->TG_TRAN_TO_MAT_VER;
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_TO_FLOW, MWIPBINGRD->TG_TRAN_TO_FLOW, sizeof(MWIPBINGRD->TG_TRAN_TO_FLOW));
    MWIPBINGRD_N->TG_TRAN_TO_FLOW_SEQ_NUM = MWIPBINGRD->TG_TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_TO_OPER, MWIPBINGRD->TG_TRAN_TO_OPER, sizeof(MWIPBINGRD->TG_TRAN_TO_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_STOP_OPER, MWIPBINGRD->TG_TRAN_STOP_OPER, sizeof(MWIPBINGRD->TG_TRAN_STOP_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_RET_FLOW, MWIPBINGRD->TG_TRAN_RET_FLOW, sizeof(MWIPBINGRD->TG_TRAN_RET_FLOW));
    MWIPBINGRD_N->TG_TRAN_RET_FLOW_SEQ_NUM = MWIPBINGRD->TG_TRAN_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_RET_OPER, MWIPBINGRD->TG_TRAN_RET_OPER, sizeof(MWIPBINGRD->TG_TRAN_RET_OPER));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_RET_OPTION, MWIPBINGRD->TG_TRAN_RET_OPTION, sizeof(MWIPBINGRD->TG_TRAN_RET_OPTION));
    MEMCPY_AN(MWIPBINGRD_N->TG_TRAN_COMMENT, MWIPBINGRD->TG_TRAN_COMMENT, sizeof(MWIPBINGRD->TG_TRAN_COMMENT));
    MWIPBINGRD_N->PY_PERIOD = MWIPBINGRD->PY_PERIOD;
    MEMCPY_AN(MWIPBINGRD_N->PY_UPPER_LIMIT, MWIPBINGRD->PY_UPPER_LIMIT, sizeof(MWIPBINGRD->PY_UPPER_LIMIT));
    MEMCPY_AN(MWIPBINGRD_N->PY_LOWER_LIMIT, MWIPBINGRD->PY_LOWER_LIMIT, sizeof(MWIPBINGRD->PY_LOWER_LIMIT));
    MEMCPY_AN(MWIPBINGRD_N->PY_ALARM_ID, MWIPBINGRD->PY_ALARM_ID, sizeof(MWIPBINGRD->PY_ALARM_ID));
    MWIPBINGRD_N->PY_USE_SPEC_LIMIT_FLAG[0] = MWIPBINGRD->PY_USE_SPEC_LIMIT_FLAG;
    MEMCPY_AN(MWIPBINGRD_N->PY_USE_SPEC_CHAR_ID, MWIPBINGRD->PY_USE_SPEC_CHAR_ID, sizeof(MWIPBINGRD->PY_USE_SPEC_CHAR_ID));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_1, MWIPBINGRD->BIN_GRADE_CMF_1, sizeof(MWIPBINGRD->BIN_GRADE_CMF_1));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_2, MWIPBINGRD->BIN_GRADE_CMF_2, sizeof(MWIPBINGRD->BIN_GRADE_CMF_2));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_3, MWIPBINGRD->BIN_GRADE_CMF_3, sizeof(MWIPBINGRD->BIN_GRADE_CMF_3));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_4, MWIPBINGRD->BIN_GRADE_CMF_4, sizeof(MWIPBINGRD->BIN_GRADE_CMF_4));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_5, MWIPBINGRD->BIN_GRADE_CMF_5, sizeof(MWIPBINGRD->BIN_GRADE_CMF_5));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_6, MWIPBINGRD->BIN_GRADE_CMF_6, sizeof(MWIPBINGRD->BIN_GRADE_CMF_6));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_7, MWIPBINGRD->BIN_GRADE_CMF_7, sizeof(MWIPBINGRD->BIN_GRADE_CMF_7));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_8, MWIPBINGRD->BIN_GRADE_CMF_8, sizeof(MWIPBINGRD->BIN_GRADE_CMF_8));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_9, MWIPBINGRD->BIN_GRADE_CMF_9, sizeof(MWIPBINGRD->BIN_GRADE_CMF_9));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_10, MWIPBINGRD->BIN_GRADE_CMF_10, sizeof(MWIPBINGRD->BIN_GRADE_CMF_10));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_11, MWIPBINGRD->BIN_GRADE_CMF_11, sizeof(MWIPBINGRD->BIN_GRADE_CMF_11));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_12, MWIPBINGRD->BIN_GRADE_CMF_12, sizeof(MWIPBINGRD->BIN_GRADE_CMF_12));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_13, MWIPBINGRD->BIN_GRADE_CMF_13, sizeof(MWIPBINGRD->BIN_GRADE_CMF_13));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_14, MWIPBINGRD->BIN_GRADE_CMF_14, sizeof(MWIPBINGRD->BIN_GRADE_CMF_14));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_15, MWIPBINGRD->BIN_GRADE_CMF_15, sizeof(MWIPBINGRD->BIN_GRADE_CMF_15));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_16, MWIPBINGRD->BIN_GRADE_CMF_16, sizeof(MWIPBINGRD->BIN_GRADE_CMF_16));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_17, MWIPBINGRD->BIN_GRADE_CMF_17, sizeof(MWIPBINGRD->BIN_GRADE_CMF_17));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_18, MWIPBINGRD->BIN_GRADE_CMF_18, sizeof(MWIPBINGRD->BIN_GRADE_CMF_18));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_19, MWIPBINGRD->BIN_GRADE_CMF_19, sizeof(MWIPBINGRD->BIN_GRADE_CMF_19));
    MEMCPY_AN(MWIPBINGRD_N->BIN_GRADE_CMF_20, MWIPBINGRD->BIN_GRADE_CMF_20, sizeof(MWIPBINGRD->BIN_GRADE_CMF_20));
}


/* Del Null Function */
void DBC_del_null_mwipbingrd(struct MWIPBINGRD_N_TAG *MWIPBINGRD_N, struct MWIPBINGRD_TAG *MWIPBINGRD)
{
    MEMCPY_DN(MWIPBINGRD->CREATE_USER_ID, MWIPBINGRD_N->CREATE_USER_ID, sizeof(MWIPBINGRD->CREATE_USER_ID));
    MEMCPY_DN(MWIPBINGRD->CREATE_TIME, MWIPBINGRD_N->CREATE_TIME, sizeof(MWIPBINGRD->CREATE_TIME));
    MEMCPY_DN(MWIPBINGRD->UPDATE_USER_ID, MWIPBINGRD_N->UPDATE_USER_ID, sizeof(MWIPBINGRD->UPDATE_USER_ID));
    MEMCPY_DN(MWIPBINGRD->UPDATE_TIME, MWIPBINGRD_N->UPDATE_TIME, sizeof(MWIPBINGRD->UPDATE_TIME));
    MEMCPY_DN(MWIPBINGRD->FACTORY, MWIPBINGRD_N->FACTORY, sizeof(MWIPBINGRD->FACTORY));
    MEMCPY_DN(MWIPBINGRD->BIN_ID, MWIPBINGRD_N->BIN_ID, sizeof(MWIPBINGRD->BIN_ID));
    MWIPBINGRD->BIN_VERSION = MWIPBINGRD_N->BIN_VERSION;
    MEMCPY_DN(MWIPBINGRD->BIN_UNIT, MWIPBINGRD_N->BIN_UNIT, sizeof(MWIPBINGRD->BIN_UNIT));
    MWIPBINGRD->BIN_SEQ = MWIPBINGRD_N->BIN_SEQ;
    MEMCPY_DN(MWIPBINGRD->BIN_PROMPT, MWIPBINGRD_N->BIN_PROMPT, sizeof(MWIPBINGRD->BIN_PROMPT));
    MEMCPY_DN(MWIPBINGRD->BIN_PROMPT_DESC, MWIPBINGRD_N->BIN_PROMPT_DESC, sizeof(MWIPBINGRD->BIN_PROMPT_DESC));
    MWIPBINGRD->BIN_TYPE = MWIPBINGRD_N->BIN_TYPE[0];
    MWIPBINGRD->LOGICAL_BIN_FLAG = MWIPBINGRD_N->LOGICAL_BIN_FLAG[0];
    MWIPBINGRD->KEEP_LOT_FLAG = MWIPBINGRD_N->KEEP_LOT_FLAG[0];
    MEMCPY_DN(MWIPBINGRD->SPLIT_LOT_ID_RULE, MWIPBINGRD_N->SPLIT_LOT_ID_RULE, sizeof(MWIPBINGRD->SPLIT_LOT_ID_RULE));
    MWIPBINGRD->SPLIT_BY_BIN_SEQ = MWIPBINGRD_N->SPLIT_BY_BIN_SEQ;
    MWIPBINGRD->USE_BIN_PROMPT_FAIL_REASON = MWIPBINGRD_N->USE_BIN_PROMPT_FAIL_REASON[0];
    MWIPBINGRD->KEEP_LOT_QTY_FAIL = MWIPBINGRD_N->KEEP_LOT_QTY_FAIL[0];
    MEMCPY_DN(MWIPBINGRD->FAIL_REASON_CODE, MWIPBINGRD_N->FAIL_REASON_CODE, sizeof(MWIPBINGRD->FAIL_REASON_CODE));
    MEMCPY_DN(MWIPBINGRD->REASON_CODE_REF_OPER, MWIPBINGRD_N->REASON_CODE_REF_OPER, sizeof(MWIPBINGRD->REASON_CODE_REF_OPER));
    MEMCPY_DN(MWIPBINGRD->CHANGE_MAT_ID, MWIPBINGRD_N->CHANGE_MAT_ID, sizeof(MWIPBINGRD->CHANGE_MAT_ID));
    MWIPBINGRD->CHANGE_MAT_VER = MWIPBINGRD_N->CHANGE_MAT_VER;
    MEMCPY_DN(MWIPBINGRD->CHANGE_FLOW, MWIPBINGRD_N->CHANGE_FLOW, sizeof(MWIPBINGRD->CHANGE_FLOW));
    MWIPBINGRD->CHANGE_FLOW_SEQ_NUM = MWIPBINGRD_N->CHANGE_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINGRD->CHANGE_OPER, MWIPBINGRD_N->CHANGE_OPER, sizeof(MWIPBINGRD->CHANGE_OPER));
    MWIPBINGRD->CHANGE_LOT_TYPE = MWIPBINGRD_N->CHANGE_LOT_TYPE[0];
    MWIPBINGRD->CHANGE_LOT_PRIORITY = MWIPBINGRD_N->CHANGE_LOT_PRIORITY[0];
    MEMCPY_DN(MWIPBINGRD->CHANGE_CREATE_CODE, MWIPBINGRD_N->CHANGE_CREATE_CODE, sizeof(MWIPBINGRD->CHANGE_CREATE_CODE));
    MEMCPY_DN(MWIPBINGRD->CHANGE_OWNER_CODE, MWIPBINGRD_N->CHANGE_OWNER_CODE, sizeof(MWIPBINGRD->CHANGE_OWNER_CODE));
    MEMCPY_DN(MWIPBINGRD->CHANGE_CRR_GROUP, MWIPBINGRD_N->CHANGE_CRR_GROUP, sizeof(MWIPBINGRD->CHANGE_CRR_GROUP));
    MEMCPY_DN(MWIPBINGRD->TRAN_CODE, MWIPBINGRD_N->TRAN_CODE, sizeof(MWIPBINGRD->TRAN_CODE));
    MEMCPY_DN(MWIPBINGRD->TRAN_KEY_REF_OPER, MWIPBINGRD_N->TRAN_KEY_REF_OPER, sizeof(MWIPBINGRD->TRAN_KEY_REF_OPER));
    MEMCPY_DN(MWIPBINGRD->TRAN_KEY_CODE_1, MWIPBINGRD_N->TRAN_KEY_CODE_1, sizeof(MWIPBINGRD->TRAN_KEY_CODE_1));
    MEMCPY_DN(MWIPBINGRD->TRAN_KEY_CODE_2, MWIPBINGRD_N->TRAN_KEY_CODE_2, sizeof(MWIPBINGRD->TRAN_KEY_CODE_2));
    MEMCPY_DN(MWIPBINGRD->TRAN_KEY_CODE_3, MWIPBINGRD_N->TRAN_KEY_CODE_3, sizeof(MWIPBINGRD->TRAN_KEY_CODE_3));
    MEMCPY_DN(MWIPBINGRD->TRAN_TO_MAT_ID, MWIPBINGRD_N->TRAN_TO_MAT_ID, sizeof(MWIPBINGRD->TRAN_TO_MAT_ID));
    MWIPBINGRD->TRAN_TO_MAT_VER = MWIPBINGRD_N->TRAN_TO_MAT_VER;
    MEMCPY_DN(MWIPBINGRD->TRAN_TO_FLOW, MWIPBINGRD_N->TRAN_TO_FLOW, sizeof(MWIPBINGRD->TRAN_TO_FLOW));
    MWIPBINGRD->TRAN_TO_FLOW_SEQ_NUM = MWIPBINGRD_N->TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINGRD->TRAN_TO_OPER, MWIPBINGRD_N->TRAN_TO_OPER, sizeof(MWIPBINGRD->TRAN_TO_OPER));
    MEMCPY_DN(MWIPBINGRD->TRAN_STOP_OPER, MWIPBINGRD_N->TRAN_STOP_OPER, sizeof(MWIPBINGRD->TRAN_STOP_OPER));
    MEMCPY_DN(MWIPBINGRD->TRAN_RET_FLOW, MWIPBINGRD_N->TRAN_RET_FLOW, sizeof(MWIPBINGRD->TRAN_RET_FLOW));
    MWIPBINGRD->TRAN_RET_FLOW_SEQ_NUM = MWIPBINGRD_N->TRAN_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINGRD->TRAN_RET_OPER, MWIPBINGRD_N->TRAN_RET_OPER, sizeof(MWIPBINGRD->TRAN_RET_OPER));
    MEMCPY_DN(MWIPBINGRD->TRAN_RET_OPTION, MWIPBINGRD_N->TRAN_RET_OPTION, sizeof(MWIPBINGRD->TRAN_RET_OPTION));
    MEMCPY_DN(MWIPBINGRD->TRAN_COMMENT, MWIPBINGRD_N->TRAN_COMMENT, sizeof(MWIPBINGRD->TRAN_COMMENT));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_CODE, MWIPBINGRD_N->TG_TRAN_CODE, sizeof(MWIPBINGRD->TG_TRAN_CODE));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_KEY_REF_OPER, MWIPBINGRD_N->TG_TRAN_KEY_REF_OPER, sizeof(MWIPBINGRD->TG_TRAN_KEY_REF_OPER));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_KEY_CODE_1, MWIPBINGRD_N->TG_TRAN_KEY_CODE_1, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_1));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_KEY_CODE_2, MWIPBINGRD_N->TG_TRAN_KEY_CODE_2, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_2));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_KEY_CODE_3, MWIPBINGRD_N->TG_TRAN_KEY_CODE_3, sizeof(MWIPBINGRD->TG_TRAN_KEY_CODE_3));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_TO_MAT_ID, MWIPBINGRD_N->TG_TRAN_TO_MAT_ID, sizeof(MWIPBINGRD->TG_TRAN_TO_MAT_ID));
    MWIPBINGRD->TG_TRAN_TO_MAT_VER = MWIPBINGRD_N->TG_TRAN_TO_MAT_VER;
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_TO_FLOW, MWIPBINGRD_N->TG_TRAN_TO_FLOW, sizeof(MWIPBINGRD->TG_TRAN_TO_FLOW));
    MWIPBINGRD->TG_TRAN_TO_FLOW_SEQ_NUM = MWIPBINGRD_N->TG_TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_TO_OPER, MWIPBINGRD_N->TG_TRAN_TO_OPER, sizeof(MWIPBINGRD->TG_TRAN_TO_OPER));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_STOP_OPER, MWIPBINGRD_N->TG_TRAN_STOP_OPER, sizeof(MWIPBINGRD->TG_TRAN_STOP_OPER));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_RET_FLOW, MWIPBINGRD_N->TG_TRAN_RET_FLOW, sizeof(MWIPBINGRD->TG_TRAN_RET_FLOW));
    MWIPBINGRD->TG_TRAN_RET_FLOW_SEQ_NUM = MWIPBINGRD_N->TG_TRAN_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_RET_OPER, MWIPBINGRD_N->TG_TRAN_RET_OPER, sizeof(MWIPBINGRD->TG_TRAN_RET_OPER));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_RET_OPTION, MWIPBINGRD_N->TG_TRAN_RET_OPTION, sizeof(MWIPBINGRD->TG_TRAN_RET_OPTION));
    MEMCPY_DN(MWIPBINGRD->TG_TRAN_COMMENT, MWIPBINGRD_N->TG_TRAN_COMMENT, sizeof(MWIPBINGRD->TG_TRAN_COMMENT));
    MWIPBINGRD->PY_PERIOD = MWIPBINGRD_N->PY_PERIOD;
    MEMCPY_DN(MWIPBINGRD->PY_UPPER_LIMIT, MWIPBINGRD_N->PY_UPPER_LIMIT, sizeof(MWIPBINGRD->PY_UPPER_LIMIT));
    MEMCPY_DN(MWIPBINGRD->PY_LOWER_LIMIT, MWIPBINGRD_N->PY_LOWER_LIMIT, sizeof(MWIPBINGRD->PY_LOWER_LIMIT));
    MEMCPY_DN(MWIPBINGRD->PY_ALARM_ID, MWIPBINGRD_N->PY_ALARM_ID, sizeof(MWIPBINGRD->PY_ALARM_ID));
    MWIPBINGRD->PY_USE_SPEC_LIMIT_FLAG = MWIPBINGRD_N->PY_USE_SPEC_LIMIT_FLAG[0];
    MEMCPY_DN(MWIPBINGRD->PY_USE_SPEC_CHAR_ID, MWIPBINGRD_N->PY_USE_SPEC_CHAR_ID, sizeof(MWIPBINGRD->PY_USE_SPEC_CHAR_ID));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_1, MWIPBINGRD_N->BIN_GRADE_CMF_1, sizeof(MWIPBINGRD->BIN_GRADE_CMF_1));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_2, MWIPBINGRD_N->BIN_GRADE_CMF_2, sizeof(MWIPBINGRD->BIN_GRADE_CMF_2));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_3, MWIPBINGRD_N->BIN_GRADE_CMF_3, sizeof(MWIPBINGRD->BIN_GRADE_CMF_3));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_4, MWIPBINGRD_N->BIN_GRADE_CMF_4, sizeof(MWIPBINGRD->BIN_GRADE_CMF_4));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_5, MWIPBINGRD_N->BIN_GRADE_CMF_5, sizeof(MWIPBINGRD->BIN_GRADE_CMF_5));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_6, MWIPBINGRD_N->BIN_GRADE_CMF_6, sizeof(MWIPBINGRD->BIN_GRADE_CMF_6));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_7, MWIPBINGRD_N->BIN_GRADE_CMF_7, sizeof(MWIPBINGRD->BIN_GRADE_CMF_7));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_8, MWIPBINGRD_N->BIN_GRADE_CMF_8, sizeof(MWIPBINGRD->BIN_GRADE_CMF_8));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_9, MWIPBINGRD_N->BIN_GRADE_CMF_9, sizeof(MWIPBINGRD->BIN_GRADE_CMF_9));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_10, MWIPBINGRD_N->BIN_GRADE_CMF_10, sizeof(MWIPBINGRD->BIN_GRADE_CMF_10));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_11, MWIPBINGRD_N->BIN_GRADE_CMF_11, sizeof(MWIPBINGRD->BIN_GRADE_CMF_11));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_12, MWIPBINGRD_N->BIN_GRADE_CMF_12, sizeof(MWIPBINGRD->BIN_GRADE_CMF_12));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_13, MWIPBINGRD_N->BIN_GRADE_CMF_13, sizeof(MWIPBINGRD->BIN_GRADE_CMF_13));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_14, MWIPBINGRD_N->BIN_GRADE_CMF_14, sizeof(MWIPBINGRD->BIN_GRADE_CMF_14));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_15, MWIPBINGRD_N->BIN_GRADE_CMF_15, sizeof(MWIPBINGRD->BIN_GRADE_CMF_15));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_16, MWIPBINGRD_N->BIN_GRADE_CMF_16, sizeof(MWIPBINGRD->BIN_GRADE_CMF_16));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_17, MWIPBINGRD_N->BIN_GRADE_CMF_17, sizeof(MWIPBINGRD->BIN_GRADE_CMF_17));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_18, MWIPBINGRD_N->BIN_GRADE_CMF_18, sizeof(MWIPBINGRD->BIN_GRADE_CMF_18));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_19, MWIPBINGRD_N->BIN_GRADE_CMF_19, sizeof(MWIPBINGRD->BIN_GRADE_CMF_19));
    MEMCPY_DN(MWIPBINGRD->BIN_GRADE_CMF_20, MWIPBINGRD_N->BIN_GRADE_CMF_20, sizeof(MWIPBINGRD->BIN_GRADE_CMF_20));
}


