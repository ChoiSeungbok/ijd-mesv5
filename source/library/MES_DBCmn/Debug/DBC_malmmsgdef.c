
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
    "DBC_malmmsgdef.pc"
};


static unsigned int sqlctx = 9099995;


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
            void  *sqhstv[119];
   unsigned int   sqhstl[119];
            int   sqhsts[119];
            void  *sqindv[119];
            int   sqinds[119];
   unsigned int   sqharm[119];
   unsigned int   *sqharc[119];
   unsigned short  sqadto[119];
   unsigned short  sqtdso[119];
} sqlstm = {13,119};

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

 static const char *sq0007 = 
"ENT_3 ,ALARM_COMMENT_4 ,ALARM_COMMEN\
T_5 ,PDF_FILE_NAME ,IMAGE_FILE_NAME ,ALARM_CMF_1 ,ALARM_CMF_2 ,ALARM_CMF_3 ,A\
LARM_CMF_4 ,ALARM_CMF_5 ,ALARM_CMF_6 ,ALARM_CMF_7 ,ALARM_CMF_8 ,ALARM_CMF_9 ,\
ALARM_CMF_10 ,ALARM_CMF_11 ,ALARM_CMF_12 ,ALARM_CMF_13 ,ALARM_CMF_14 ,ALARM_C\
MF_15 ,ALARM_CMF_16 ,ALARM_CMF_17 ,ALARM_CMF_18 ,ALARM_CMF_19 ,ALARM_CMF_20 ,\
ALARM_GRP_1 ,ALARM_GRP_2 ,ALARM_GRP_3 ,ALARM_GRP_4 ,ALARM_GRP_5 ,ALARM_GRP_6 \
,ALARM_GRP_7 ,ALARM_GRP_8 ,ALARM_GRP_9 ,ALARM_GRP_10  from MALMMSGDEF where (\
(FACTORY=:b0 and ALARM_ID>=:b1) and ALARM_TYPE like :b2) order by ALARM_ID as\
c             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,2148,0,4,46,0,0,119,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
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
496,0,0,2,2160,0,4,321,0,0,119,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
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
987,0,0,3,79,0,4,599,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
1014,0,0,4,61,0,2,636,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1037,0,0,5,2000,0,3,666,0,0,117,117,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
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
1520,0,0,6,2001,0,5,925,0,0,117,117,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
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
2003,0,0,7,1613,0,9,1197,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
2030,0,0,7,0,0,13,1226,0,0,117,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
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
2513,0,0,7,0,0,15,1373,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_malmmsgdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/06/19 19:16:41
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
void DBC_add_null_malmmsgdef(struct MALMMSGDEF_N_TAG *MALMMSGDEF_N, struct MALMMSGDEF_TAG *MALMMSGDEF);
void DBC_del_null_malmmsgdef(struct MALMMSGDEF_N_TAG *MALMMSGDEF_N, struct MALMMSGDEF_TAG *MALMMSGDEF);


/* SQL SELECT Function */
void DBC_select_malmmsgdef(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    ALARM_ID,
                    ALARM_DESC,
                    ALARM_TYPE,
                    ALARM_LEVEL_FLAG,
                    SEND_TO_USER_FLAG,
                    ACTION_DISPLAY_FLAG,
                    ACTION_MAIL_FLAG,
                    ACTION_MSG_FLAG,
                    ALARM_LOT_ACTION,
                    HOLD_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RWK_CODE,
                    RWK_FLOW,
                    RWK_FLOW_SEQ_NUM,
                    RWK_OPER,
                    RWK_STOP_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RET_CLEAR_FLAG,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CMF_16,
                    CMF_17,
                    CMF_18,
                    CMF_19,
                    CMF_20,
                    LOT_COMMENT,
                    ALARM_SUBJECT,
                    ALARM_MSG_1,
                    ALARM_MSG_2,
                    ALARM_MSG_3,
                    EVENT_ID,
                    CHG_STS_1,
                    CHG_STS_2,
                    CHG_STS_3,
                    CHG_STS_4,
                    CHG_STS_5,
                    CHG_STS_6,
                    CHG_STS_7,
                    CHG_STS_8,
                    CHG_STS_9,
                    CHG_STS_10,
                    RES_COMMENT,
                    CLEAR_EVENT_ID,
                    CLEAR_CHG_STS_1,
                    CLEAR_CHG_STS_2,
                    CLEAR_CHG_STS_3,
                    CLEAR_CHG_STS_4,
                    CLEAR_CHG_STS_5,
                    CLEAR_CHG_STS_6,
                    CLEAR_CHG_STS_7,
                    CLEAR_CHG_STS_8,
                    CLEAR_CHG_STS_9,
                    CLEAR_CHG_STS_10,
                    CLEAR_RES_COMMENT,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    ALARM_COMMENT_1,
                    ALARM_COMMENT_2,
                    ALARM_COMMENT_3,
                    ALARM_COMMENT_4,
                    ALARM_COMMENT_5,
                    PDF_FILE_NAME,
                    IMAGE_FILE_NAME,
                    ALARM_CMF_1,
                    ALARM_CMF_2,
                    ALARM_CMF_3,
                    ALARM_CMF_4,
                    ALARM_CMF_5,
                    ALARM_CMF_6,
                    ALARM_CMF_7,
                    ALARM_CMF_8,
                    ALARM_CMF_9,
                    ALARM_CMF_10,
                    ALARM_CMF_11,
                    ALARM_CMF_12,
                    ALARM_CMF_13,
                    ALARM_CMF_14,
                    ALARM_CMF_15,
                    ALARM_CMF_16,
                    ALARM_CMF_17,
                    ALARM_CMF_18,
                    ALARM_CMF_19,
                    ALARM_CMF_20,
                    ALARM_GRP_1,
                    ALARM_GRP_2,
                    ALARM_GRP_3,
                    ALARM_GRP_4,
                    ALARM_GRP_5,
                    ALARM_GRP_6,
                    ALARM_GRP_7,
                    ALARM_GRP_8,
                    ALARM_GRP_9,
                    ALARM_GRP_10
                INTO 
                    :MALMMSGDEF_N.FACTORY,
                    :MALMMSGDEF_N.ALARM_ID,
                    :MALMMSGDEF_N.ALARM_DESC,
                    :MALMMSGDEF_N.ALARM_TYPE,
                    :MALMMSGDEF_N.ALARM_LEVEL_FLAG,
                    :MALMMSGDEF_N.SEND_TO_USER_FLAG,
                    :MALMMSGDEF_N.ACTION_DISPLAY_FLAG,
                    :MALMMSGDEF_N.ACTION_MAIL_FLAG,
                    :MALMMSGDEF_N.ACTION_MSG_FLAG,
                    :MALMMSGDEF_N.ALARM_LOT_ACTION,
                    :MALMMSGDEF_N.HOLD_CODE,
                    :MALMMSGDEF_N.HOLD_PASSWORD,
                    :MALMMSGDEF_N.HOLD_PRV_GRP_ID,
                    :MALMMSGDEF_N.MAT_ID,
                    :MALMMSGDEF_N.MAT_VER,
                    :MALMMSGDEF_N.FLOW,
                    :MALMMSGDEF_N.FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.OPER,
                    :MALMMSGDEF_N.RWK_CODE,
                    :MALMMSGDEF_N.RWK_FLOW,
                    :MALMMSGDEF_N.RWK_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RWK_OPER,
                    :MALMMSGDEF_N.RWK_STOP_OPER,
                    :MALMMSGDEF_N.RET_FLOW,
                    :MALMMSGDEF_N.RET_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RET_OPER,
                    :MALMMSGDEF_N.RET_CLEAR_FLAG,
                    :MALMMSGDEF_N.CMF_1,
                    :MALMMSGDEF_N.CMF_2,
                    :MALMMSGDEF_N.CMF_3,
                    :MALMMSGDEF_N.CMF_4,
                    :MALMMSGDEF_N.CMF_5,
                    :MALMMSGDEF_N.CMF_6,
                    :MALMMSGDEF_N.CMF_7,
                    :MALMMSGDEF_N.CMF_8,
                    :MALMMSGDEF_N.CMF_9,
                    :MALMMSGDEF_N.CMF_10,
                    :MALMMSGDEF_N.CMF_11,
                    :MALMMSGDEF_N.CMF_12,
                    :MALMMSGDEF_N.CMF_13,
                    :MALMMSGDEF_N.CMF_14,
                    :MALMMSGDEF_N.CMF_15,
                    :MALMMSGDEF_N.CMF_16,
                    :MALMMSGDEF_N.CMF_17,
                    :MALMMSGDEF_N.CMF_18,
                    :MALMMSGDEF_N.CMF_19,
                    :MALMMSGDEF_N.CMF_20,
                    :MALMMSGDEF_N.LOT_COMMENT,
                    :MALMMSGDEF_N.ALARM_SUBJECT,
                    :MALMMSGDEF_N.ALARM_MSG_1,
                    :MALMMSGDEF_N.ALARM_MSG_2,
                    :MALMMSGDEF_N.ALARM_MSG_3,
                    :MALMMSGDEF_N.EVENT_ID,
                    :MALMMSGDEF_N.CHG_STS_1,
                    :MALMMSGDEF_N.CHG_STS_2,
                    :MALMMSGDEF_N.CHG_STS_3,
                    :MALMMSGDEF_N.CHG_STS_4,
                    :MALMMSGDEF_N.CHG_STS_5,
                    :MALMMSGDEF_N.CHG_STS_6,
                    :MALMMSGDEF_N.CHG_STS_7,
                    :MALMMSGDEF_N.CHG_STS_8,
                    :MALMMSGDEF_N.CHG_STS_9,
                    :MALMMSGDEF_N.CHG_STS_10,
                    :MALMMSGDEF_N.RES_COMMENT,
                    :MALMMSGDEF_N.CLEAR_EVENT_ID,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_1,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_2,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_3,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_4,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_5,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_6,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_7,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_8,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_9,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_10,
                    :MALMMSGDEF_N.CLEAR_RES_COMMENT,
                    :MALMMSGDEF_N.CREATE_USER_ID,
                    :MALMMSGDEF_N.CREATE_TIME,
                    :MALMMSGDEF_N.UPDATE_USER_ID,
                    :MALMMSGDEF_N.UPDATE_TIME,
                    :MALMMSGDEF_N.ALARM_COMMENT_1,
                    :MALMMSGDEF_N.ALARM_COMMENT_2,
                    :MALMMSGDEF_N.ALARM_COMMENT_3,
                    :MALMMSGDEF_N.ALARM_COMMENT_4,
                    :MALMMSGDEF_N.ALARM_COMMENT_5,
                    :MALMMSGDEF_N.PDF_FILE_NAME,
                    :MALMMSGDEF_N.IMAGE_FILE_NAME,
                    :MALMMSGDEF_N.ALARM_CMF_1,
                    :MALMMSGDEF_N.ALARM_CMF_2,
                    :MALMMSGDEF_N.ALARM_CMF_3,
                    :MALMMSGDEF_N.ALARM_CMF_4,
                    :MALMMSGDEF_N.ALARM_CMF_5,
                    :MALMMSGDEF_N.ALARM_CMF_6,
                    :MALMMSGDEF_N.ALARM_CMF_7,
                    :MALMMSGDEF_N.ALARM_CMF_8,
                    :MALMMSGDEF_N.ALARM_CMF_9,
                    :MALMMSGDEF_N.ALARM_CMF_10,
                    :MALMMSGDEF_N.ALARM_CMF_11,
                    :MALMMSGDEF_N.ALARM_CMF_12,
                    :MALMMSGDEF_N.ALARM_CMF_13,
                    :MALMMSGDEF_N.ALARM_CMF_14,
                    :MALMMSGDEF_N.ALARM_CMF_15,
                    :MALMMSGDEF_N.ALARM_CMF_16,
                    :MALMMSGDEF_N.ALARM_CMF_17,
                    :MALMMSGDEF_N.ALARM_CMF_18,
                    :MALMMSGDEF_N.ALARM_CMF_19,
                    :MALMMSGDEF_N.ALARM_CMF_20,
                    :MALMMSGDEF_N.ALARM_GRP_1,
                    :MALMMSGDEF_N.ALARM_GRP_2,
                    :MALMMSGDEF_N.ALARM_GRP_3,
                    :MALMMSGDEF_N.ALARM_GRP_4,
                    :MALMMSGDEF_N.ALARM_GRP_5,
                    :MALMMSGDEF_N.ALARM_GRP_6,
                    :MALMMSGDEF_N.ALARM_GRP_7,
                    :MALMMSGDEF_N.ALARM_GRP_8,
                    :MALMMSGDEF_N.ALARM_GRP_9,
                    :MALMMSGDEF_N.ALARM_GRP_10
                FROM MALMMSGDEF
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID = :MALMMSGDEF_N.ALARM_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,ALARM_ID ,ALARM_DESC ,ALARM_TYPE ,ALARM_LEVEL\
_FLAG ,SEND_TO_USER_FLAG ,ACTION_DISPLAY_FLAG ,ACTION_MAIL_FLAG ,ACTION_MSG_\
FLAG ,ALARM_LOT_ACTION ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,MAT_ID ,M\
AT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RWK_CODE ,RWK_FLOW ,RWK_FLOW_SEQ_NUM ,RWK_\
OPER ,RWK_STOP_OPER ,RET_FLOW ,RET_FLOW_SEQ_NUM ,RET_OPER ,RET_CLEAR_FLAG ,C\
MF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11\
 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CMF_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LO\
T_COMMENT ,ALARM_SUBJECT ,ALARM_MSG_1 ,ALARM_MSG_2 ,ALARM_MSG_3 ,EVENT_ID ,C\
HG_STS_1 ,CHG_STS_2 ,CHG_STS_3 ,CHG_STS_4 ,CHG_STS_5 ,CHG_STS_6 ,CHG_STS_7 ,\
CHG_STS_8 ,CHG_STS_9 ,CHG_STS_10 ,RES_COMMENT ,CLEAR_EVENT_ID ,CLEAR_CHG_STS\
_1 ,CLEAR_CHG_STS_2 ,CLEAR_CHG_STS_3 ,CLEAR_CHG_STS_4 ,CLEAR_CHG_STS_5 ,CLEA\
R_CHG_STS_6 ,CLEAR_CHG_STS_7 ,CLEAR_CHG_STS_8 ,CLEAR_CHG_STS_9 ,CLEAR_CHG_ST\
S_10 ,CLEAR_RES_COMMENT ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE\
_TIME ,ALARM_COMMENT_1 ,ALARM_COMMENT_2 ,ALARM_COMM");
            sqlbuft((void **)0,
              "ENT_3 ,ALARM_COMMENT_4 ,ALARM_COMMENT_5 ,PDF_FILE_NAME ,IMAGE\
_FILE_NAME ,ALARM_CMF_1 ,ALARM_CMF_2 ,ALARM_CMF_3 ,ALARM_CMF_4 ,ALARM_CMF_5 \
,ALARM_CMF_6 ,ALARM_CMF_7 ,ALARM_CMF_8 ,ALARM_CMF_9 ,ALARM_CMF_10 ,ALARM_CMF\
_11 ,ALARM_CMF_12 ,ALARM_CMF_13 ,ALARM_CMF_14 ,ALARM_CMF_15 ,ALARM_CMF_16 ,A\
LARM_CMF_17 ,ALARM_CMF_18 ,ALARM_CMF_19 ,ALARM_CMF_20 ,ALARM_GRP_1 ,ALARM_GR\
P_2 ,ALARM_GRP_3 ,ALARM_GRP_4 ,ALARM_GRP_5 ,ALARM_GRP_6 ,ALARM_GRP_7 ,ALARM_\
GRP_8 ,ALARM_GRP_9 ,ALARM_GRP_10 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b\
9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24\
,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,\
:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:\
b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b\
70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b8\
5,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b10\
0,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:");
            sqlstm.stmt = "b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116  \
from MALMMSGDEF where (FACTORY=:b0 and ALARM_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MALMMSGDEF_N.ALARM_LEVEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MALMMSGDEF_N.SEND_TO_USER_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MALMMSGDEF_N.ACTION_DISPLAY_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MALMMSGDEF_N.ACTION_MAIL_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MALMMSGDEF_N.ACTION_MSG_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MALMMSGDEF_N.ALARM_LOT_ACTION);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MALMMSGDEF_N.HOLD_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MALMMSGDEF_N.HOLD_PASSWORD);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MALMMSGDEF_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MALMMSGDEF_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MALMMSGDEF_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MALMMSGDEF_N.FLOW);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MALMMSGDEF_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MALMMSGDEF_N.OPER);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MALMMSGDEF_N.RWK_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MALMMSGDEF_N.RWK_FLOW);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MALMMSGDEF_N.RWK_FLOW_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MALMMSGDEF_N.RWK_OPER);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MALMMSGDEF_N.RWK_STOP_OPER);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MALMMSGDEF_N.RET_FLOW);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MALMMSGDEF_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MALMMSGDEF_N.RET_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MALMMSGDEF_N.RET_CLEAR_FLAG);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MALMMSGDEF_N.CMF_1);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MALMMSGDEF_N.CMF_2);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MALMMSGDEF_N.CMF_3);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MALMMSGDEF_N.CMF_4);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MALMMSGDEF_N.CMF_5);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MALMMSGDEF_N.CMF_6);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MALMMSGDEF_N.CMF_7);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MALMMSGDEF_N.CMF_8);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MALMMSGDEF_N.CMF_9);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MALMMSGDEF_N.CMF_10);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MALMMSGDEF_N.CMF_11);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MALMMSGDEF_N.CMF_12);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MALMMSGDEF_N.CMF_13);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MALMMSGDEF_N.CMF_14);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MALMMSGDEF_N.CMF_15);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MALMMSGDEF_N.CMF_16);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MALMMSGDEF_N.CMF_17);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MALMMSGDEF_N.CMF_18);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MALMMSGDEF_N.CMF_19);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MALMMSGDEF_N.CMF_20);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MALMMSGDEF_N.LOT_COMMENT);
            sqlstm.sqhstl[47] = (unsigned int  )401;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MALMMSGDEF_N.ALARM_SUBJECT);
            sqlstm.sqhstl[48] = (unsigned int  )201;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_1);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_2);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_3);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MALMMSGDEF_N.EVENT_ID);
            sqlstm.sqhstl[52] = (unsigned int  )13;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MALMMSGDEF_N.CHG_STS_1);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MALMMSGDEF_N.CHG_STS_2);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MALMMSGDEF_N.CHG_STS_3);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MALMMSGDEF_N.CHG_STS_4);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MALMMSGDEF_N.CHG_STS_5);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MALMMSGDEF_N.CHG_STS_6);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MALMMSGDEF_N.CHG_STS_7);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MALMMSGDEF_N.CHG_STS_8);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MALMMSGDEF_N.CHG_STS_9);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MALMMSGDEF_N.CHG_STS_10);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MALMMSGDEF_N.RES_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MALMMSGDEF_N.CLEAR_EVENT_ID);
            sqlstm.sqhstl[64] = (unsigned int  )13;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MALMMSGDEF_N.CLEAR_RES_COMMENT);
            sqlstm.sqhstl[75] = (unsigned int  )401;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MALMMSGDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MALMMSGDEF_N.CREATE_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MALMMSGDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MALMMSGDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_1);
            sqlstm.sqhstl[80] = (unsigned int  )1001;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_2);
            sqlstm.sqhstl[81] = (unsigned int  )1001;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_3);
            sqlstm.sqhstl[82] = (unsigned int  )1001;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_4);
            sqlstm.sqhstl[83] = (unsigned int  )1001;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_5);
            sqlstm.sqhstl[84] = (unsigned int  )1001;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MALMMSGDEF_N.PDF_FILE_NAME);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MALMMSGDEF_N.IMAGE_FILE_NAME);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_1);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_2);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_3);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_4);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_5);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_6);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_7);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_8);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_9);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_10);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_11);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_12);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_13);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_14);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_15);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_16);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_17);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_18);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_19);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_20);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_1);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_2);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_3);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_4);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_5);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_6);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_7);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_8);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_9);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_10);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[117] = (unsigned int  )11;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
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
        DBC_del_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    }

    DB_stop_query_timer("DBC_select_malmmsgdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_malmmsgdef_for_update(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    ALARM_ID,
                    ALARM_DESC,
                    ALARM_TYPE,
                    ALARM_LEVEL_FLAG,
                    SEND_TO_USER_FLAG,
                    ACTION_DISPLAY_FLAG,
                    ACTION_MAIL_FLAG,
                    ACTION_MSG_FLAG,
                    ALARM_LOT_ACTION,
                    HOLD_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RWK_CODE,
                    RWK_FLOW,
                    RWK_FLOW_SEQ_NUM,
                    RWK_OPER,
                    RWK_STOP_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RET_CLEAR_FLAG,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CMF_16,
                    CMF_17,
                    CMF_18,
                    CMF_19,
                    CMF_20,
                    LOT_COMMENT,
                    ALARM_SUBJECT,
                    ALARM_MSG_1,
                    ALARM_MSG_2,
                    ALARM_MSG_3,
                    EVENT_ID,
                    CHG_STS_1,
                    CHG_STS_2,
                    CHG_STS_3,
                    CHG_STS_4,
                    CHG_STS_5,
                    CHG_STS_6,
                    CHG_STS_7,
                    CHG_STS_8,
                    CHG_STS_9,
                    CHG_STS_10,
                    RES_COMMENT,
                    CLEAR_EVENT_ID,
                    CLEAR_CHG_STS_1,
                    CLEAR_CHG_STS_2,
                    CLEAR_CHG_STS_3,
                    CLEAR_CHG_STS_4,
                    CLEAR_CHG_STS_5,
                    CLEAR_CHG_STS_6,
                    CLEAR_CHG_STS_7,
                    CLEAR_CHG_STS_8,
                    CLEAR_CHG_STS_9,
                    CLEAR_CHG_STS_10,
                    CLEAR_RES_COMMENT,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    ALARM_COMMENT_1,
                    ALARM_COMMENT_2,
                    ALARM_COMMENT_3,
                    ALARM_COMMENT_4,
                    ALARM_COMMENT_5,
                    PDF_FILE_NAME,
                    IMAGE_FILE_NAME,
                    ALARM_CMF_1,
                    ALARM_CMF_2,
                    ALARM_CMF_3,
                    ALARM_CMF_4,
                    ALARM_CMF_5,
                    ALARM_CMF_6,
                    ALARM_CMF_7,
                    ALARM_CMF_8,
                    ALARM_CMF_9,
                    ALARM_CMF_10,
                    ALARM_CMF_11,
                    ALARM_CMF_12,
                    ALARM_CMF_13,
                    ALARM_CMF_14,
                    ALARM_CMF_15,
                    ALARM_CMF_16,
                    ALARM_CMF_17,
                    ALARM_CMF_18,
                    ALARM_CMF_19,
                    ALARM_CMF_20,
                    ALARM_GRP_1,
                    ALARM_GRP_2,
                    ALARM_GRP_3,
                    ALARM_GRP_4,
                    ALARM_GRP_5,
                    ALARM_GRP_6,
                    ALARM_GRP_7,
                    ALARM_GRP_8,
                    ALARM_GRP_9,
                    ALARM_GRP_10
                INTO 
                    :MALMMSGDEF_N.FACTORY,
                    :MALMMSGDEF_N.ALARM_ID,
                    :MALMMSGDEF_N.ALARM_DESC,
                    :MALMMSGDEF_N.ALARM_TYPE,
                    :MALMMSGDEF_N.ALARM_LEVEL_FLAG,
                    :MALMMSGDEF_N.SEND_TO_USER_FLAG,
                    :MALMMSGDEF_N.ACTION_DISPLAY_FLAG,
                    :MALMMSGDEF_N.ACTION_MAIL_FLAG,
                    :MALMMSGDEF_N.ACTION_MSG_FLAG,
                    :MALMMSGDEF_N.ALARM_LOT_ACTION,
                    :MALMMSGDEF_N.HOLD_CODE,
                    :MALMMSGDEF_N.HOLD_PASSWORD,
                    :MALMMSGDEF_N.HOLD_PRV_GRP_ID,
                    :MALMMSGDEF_N.MAT_ID,
                    :MALMMSGDEF_N.MAT_VER,
                    :MALMMSGDEF_N.FLOW,
                    :MALMMSGDEF_N.FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.OPER,
                    :MALMMSGDEF_N.RWK_CODE,
                    :MALMMSGDEF_N.RWK_FLOW,
                    :MALMMSGDEF_N.RWK_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RWK_OPER,
                    :MALMMSGDEF_N.RWK_STOP_OPER,
                    :MALMMSGDEF_N.RET_FLOW,
                    :MALMMSGDEF_N.RET_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RET_OPER,
                    :MALMMSGDEF_N.RET_CLEAR_FLAG,
                    :MALMMSGDEF_N.CMF_1,
                    :MALMMSGDEF_N.CMF_2,
                    :MALMMSGDEF_N.CMF_3,
                    :MALMMSGDEF_N.CMF_4,
                    :MALMMSGDEF_N.CMF_5,
                    :MALMMSGDEF_N.CMF_6,
                    :MALMMSGDEF_N.CMF_7,
                    :MALMMSGDEF_N.CMF_8,
                    :MALMMSGDEF_N.CMF_9,
                    :MALMMSGDEF_N.CMF_10,
                    :MALMMSGDEF_N.CMF_11,
                    :MALMMSGDEF_N.CMF_12,
                    :MALMMSGDEF_N.CMF_13,
                    :MALMMSGDEF_N.CMF_14,
                    :MALMMSGDEF_N.CMF_15,
                    :MALMMSGDEF_N.CMF_16,
                    :MALMMSGDEF_N.CMF_17,
                    :MALMMSGDEF_N.CMF_18,
                    :MALMMSGDEF_N.CMF_19,
                    :MALMMSGDEF_N.CMF_20,
                    :MALMMSGDEF_N.LOT_COMMENT,
                    :MALMMSGDEF_N.ALARM_SUBJECT,
                    :MALMMSGDEF_N.ALARM_MSG_1,
                    :MALMMSGDEF_N.ALARM_MSG_2,
                    :MALMMSGDEF_N.ALARM_MSG_3,
                    :MALMMSGDEF_N.EVENT_ID,
                    :MALMMSGDEF_N.CHG_STS_1,
                    :MALMMSGDEF_N.CHG_STS_2,
                    :MALMMSGDEF_N.CHG_STS_3,
                    :MALMMSGDEF_N.CHG_STS_4,
                    :MALMMSGDEF_N.CHG_STS_5,
                    :MALMMSGDEF_N.CHG_STS_6,
                    :MALMMSGDEF_N.CHG_STS_7,
                    :MALMMSGDEF_N.CHG_STS_8,
                    :MALMMSGDEF_N.CHG_STS_9,
                    :MALMMSGDEF_N.CHG_STS_10,
                    :MALMMSGDEF_N.RES_COMMENT,
                    :MALMMSGDEF_N.CLEAR_EVENT_ID,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_1,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_2,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_3,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_4,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_5,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_6,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_7,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_8,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_9,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_10,
                    :MALMMSGDEF_N.CLEAR_RES_COMMENT,
                    :MALMMSGDEF_N.CREATE_USER_ID,
                    :MALMMSGDEF_N.CREATE_TIME,
                    :MALMMSGDEF_N.UPDATE_USER_ID,
                    :MALMMSGDEF_N.UPDATE_TIME,
                    :MALMMSGDEF_N.ALARM_COMMENT_1,
                    :MALMMSGDEF_N.ALARM_COMMENT_2,
                    :MALMMSGDEF_N.ALARM_COMMENT_3,
                    :MALMMSGDEF_N.ALARM_COMMENT_4,
                    :MALMMSGDEF_N.ALARM_COMMENT_5,
                    :MALMMSGDEF_N.PDF_FILE_NAME,
                    :MALMMSGDEF_N.IMAGE_FILE_NAME,
                    :MALMMSGDEF_N.ALARM_CMF_1,
                    :MALMMSGDEF_N.ALARM_CMF_2,
                    :MALMMSGDEF_N.ALARM_CMF_3,
                    :MALMMSGDEF_N.ALARM_CMF_4,
                    :MALMMSGDEF_N.ALARM_CMF_5,
                    :MALMMSGDEF_N.ALARM_CMF_6,
                    :MALMMSGDEF_N.ALARM_CMF_7,
                    :MALMMSGDEF_N.ALARM_CMF_8,
                    :MALMMSGDEF_N.ALARM_CMF_9,
                    :MALMMSGDEF_N.ALARM_CMF_10,
                    :MALMMSGDEF_N.ALARM_CMF_11,
                    :MALMMSGDEF_N.ALARM_CMF_12,
                    :MALMMSGDEF_N.ALARM_CMF_13,
                    :MALMMSGDEF_N.ALARM_CMF_14,
                    :MALMMSGDEF_N.ALARM_CMF_15,
                    :MALMMSGDEF_N.ALARM_CMF_16,
                    :MALMMSGDEF_N.ALARM_CMF_17,
                    :MALMMSGDEF_N.ALARM_CMF_18,
                    :MALMMSGDEF_N.ALARM_CMF_19,
                    :MALMMSGDEF_N.ALARM_CMF_20,
                    :MALMMSGDEF_N.ALARM_GRP_1,
                    :MALMMSGDEF_N.ALARM_GRP_2,
                    :MALMMSGDEF_N.ALARM_GRP_3,
                    :MALMMSGDEF_N.ALARM_GRP_4,
                    :MALMMSGDEF_N.ALARM_GRP_5,
                    :MALMMSGDEF_N.ALARM_GRP_6,
                    :MALMMSGDEF_N.ALARM_GRP_7,
                    :MALMMSGDEF_N.ALARM_GRP_8,
                    :MALMMSGDEF_N.ALARM_GRP_9,
                    :MALMMSGDEF_N.ALARM_GRP_10
                FROM MALMMSGDEF
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID = :MALMMSGDEF_N.ALARM_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,ALARM_ID ,ALARM_DESC ,ALARM_TYPE ,ALARM_LEVEL\
_FLAG ,SEND_TO_USER_FLAG ,ACTION_DISPLAY_FLAG ,ACTION_MAIL_FLAG ,ACTION_MSG_\
FLAG ,ALARM_LOT_ACTION ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,MAT_ID ,M\
AT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RWK_CODE ,RWK_FLOW ,RWK_FLOW_SEQ_NUM ,RWK_\
OPER ,RWK_STOP_OPER ,RET_FLOW ,RET_FLOW_SEQ_NUM ,RET_OPER ,RET_CLEAR_FLAG ,C\
MF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11\
 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CMF_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LO\
T_COMMENT ,ALARM_SUBJECT ,ALARM_MSG_1 ,ALARM_MSG_2 ,ALARM_MSG_3 ,EVENT_ID ,C\
HG_STS_1 ,CHG_STS_2 ,CHG_STS_3 ,CHG_STS_4 ,CHG_STS_5 ,CHG_STS_6 ,CHG_STS_7 ,\
CHG_STS_8 ,CHG_STS_9 ,CHG_STS_10 ,RES_COMMENT ,CLEAR_EVENT_ID ,CLEAR_CHG_STS\
_1 ,CLEAR_CHG_STS_2 ,CLEAR_CHG_STS_3 ,CLEAR_CHG_STS_4 ,CLEAR_CHG_STS_5 ,CLEA\
R_CHG_STS_6 ,CLEAR_CHG_STS_7 ,CLEAR_CHG_STS_8 ,CLEAR_CHG_STS_9 ,CLEAR_CHG_ST\
S_10 ,CLEAR_RES_COMMENT ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE\
_TIME ,ALARM_COMMENT_1 ,ALARM_COMMENT_2 ,ALARM_COMM");
            sqlbuft((void **)0,
              "ENT_3 ,ALARM_COMMENT_4 ,ALARM_COMMENT_5 ,PDF_FILE_NAME ,IMAGE\
_FILE_NAME ,ALARM_CMF_1 ,ALARM_CMF_2 ,ALARM_CMF_3 ,ALARM_CMF_4 ,ALARM_CMF_5 \
,ALARM_CMF_6 ,ALARM_CMF_7 ,ALARM_CMF_8 ,ALARM_CMF_9 ,ALARM_CMF_10 ,ALARM_CMF\
_11 ,ALARM_CMF_12 ,ALARM_CMF_13 ,ALARM_CMF_14 ,ALARM_CMF_15 ,ALARM_CMF_16 ,A\
LARM_CMF_17 ,ALARM_CMF_18 ,ALARM_CMF_19 ,ALARM_CMF_20 ,ALARM_GRP_1 ,ALARM_GR\
P_2 ,ALARM_GRP_3 ,ALARM_GRP_4 ,ALARM_GRP_5 ,ALARM_GRP_6 ,ALARM_GRP_7 ,ALARM_\
GRP_8 ,ALARM_GRP_9 ,ALARM_GRP_10 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b\
9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24\
,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,\
:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:\
b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b\
70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b8\
5,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b10\
0,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:");
            sqlstm.stmt = "b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116  \
from MALMMSGDEF where (FACTORY=:b0 and ALARM_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )496;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MALMMSGDEF_N.ALARM_LEVEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MALMMSGDEF_N.SEND_TO_USER_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MALMMSGDEF_N.ACTION_DISPLAY_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MALMMSGDEF_N.ACTION_MAIL_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MALMMSGDEF_N.ACTION_MSG_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MALMMSGDEF_N.ALARM_LOT_ACTION);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MALMMSGDEF_N.HOLD_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MALMMSGDEF_N.HOLD_PASSWORD);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MALMMSGDEF_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MALMMSGDEF_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MALMMSGDEF_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MALMMSGDEF_N.FLOW);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MALMMSGDEF_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MALMMSGDEF_N.OPER);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MALMMSGDEF_N.RWK_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MALMMSGDEF_N.RWK_FLOW);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MALMMSGDEF_N.RWK_FLOW_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MALMMSGDEF_N.RWK_OPER);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MALMMSGDEF_N.RWK_STOP_OPER);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MALMMSGDEF_N.RET_FLOW);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MALMMSGDEF_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MALMMSGDEF_N.RET_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MALMMSGDEF_N.RET_CLEAR_FLAG);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MALMMSGDEF_N.CMF_1);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MALMMSGDEF_N.CMF_2);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MALMMSGDEF_N.CMF_3);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MALMMSGDEF_N.CMF_4);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MALMMSGDEF_N.CMF_5);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MALMMSGDEF_N.CMF_6);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MALMMSGDEF_N.CMF_7);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MALMMSGDEF_N.CMF_8);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MALMMSGDEF_N.CMF_9);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MALMMSGDEF_N.CMF_10);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MALMMSGDEF_N.CMF_11);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MALMMSGDEF_N.CMF_12);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MALMMSGDEF_N.CMF_13);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MALMMSGDEF_N.CMF_14);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MALMMSGDEF_N.CMF_15);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MALMMSGDEF_N.CMF_16);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MALMMSGDEF_N.CMF_17);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MALMMSGDEF_N.CMF_18);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MALMMSGDEF_N.CMF_19);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MALMMSGDEF_N.CMF_20);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MALMMSGDEF_N.LOT_COMMENT);
            sqlstm.sqhstl[47] = (unsigned int  )401;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MALMMSGDEF_N.ALARM_SUBJECT);
            sqlstm.sqhstl[48] = (unsigned int  )201;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_1);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_2);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_3);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MALMMSGDEF_N.EVENT_ID);
            sqlstm.sqhstl[52] = (unsigned int  )13;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MALMMSGDEF_N.CHG_STS_1);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MALMMSGDEF_N.CHG_STS_2);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MALMMSGDEF_N.CHG_STS_3);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MALMMSGDEF_N.CHG_STS_4);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MALMMSGDEF_N.CHG_STS_5);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MALMMSGDEF_N.CHG_STS_6);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MALMMSGDEF_N.CHG_STS_7);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MALMMSGDEF_N.CHG_STS_8);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MALMMSGDEF_N.CHG_STS_9);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MALMMSGDEF_N.CHG_STS_10);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MALMMSGDEF_N.RES_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MALMMSGDEF_N.CLEAR_EVENT_ID);
            sqlstm.sqhstl[64] = (unsigned int  )13;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MALMMSGDEF_N.CLEAR_RES_COMMENT);
            sqlstm.sqhstl[75] = (unsigned int  )401;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MALMMSGDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MALMMSGDEF_N.CREATE_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MALMMSGDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MALMMSGDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_1);
            sqlstm.sqhstl[80] = (unsigned int  )1001;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_2);
            sqlstm.sqhstl[81] = (unsigned int  )1001;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_3);
            sqlstm.sqhstl[82] = (unsigned int  )1001;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_4);
            sqlstm.sqhstl[83] = (unsigned int  )1001;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_5);
            sqlstm.sqhstl[84] = (unsigned int  )1001;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MALMMSGDEF_N.PDF_FILE_NAME);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MALMMSGDEF_N.IMAGE_FILE_NAME);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_1);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_2);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_3);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_4);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_5);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_6);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_7);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_8);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_9);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_10);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_11);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_12);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_13);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_14);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_15);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_16);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_17);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_18);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_19);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_20);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_1);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_2);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_3);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_4);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_5);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_6);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_7);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_8);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_9);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_10);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[117] = (unsigned int  )11;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
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
        DBC_del_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    }

    DB_stop_query_timer("DBC_select_malmmsgdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_malmmsgdef_scalar(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MALMMSGDEF
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID = :MALMMSGDEF_N.ALARM_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MALMMSGDEF where\
 (FACTORY=:b1 and ALARM_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )987;
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
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
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

    DB_stop_query_timer("DBC_select_malmmsgdef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_malmmsgdef(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MALMMSGDEF
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID = :MALMMSGDEF_N.ALARM_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MALMMSGDEF  where (FACTORY=:b0 and \
ALARM_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1014;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_delete_malmmsgdef", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_malmmsgdef(struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MALMMSGDEF( 
                    FACTORY, 
                    ALARM_ID, 
                    ALARM_DESC, 
                    ALARM_TYPE, 
                    ALARM_LEVEL_FLAG, 
                    SEND_TO_USER_FLAG, 
                    ACTION_DISPLAY_FLAG, 
                    ACTION_MAIL_FLAG, 
                    ACTION_MSG_FLAG, 
                    ALARM_LOT_ACTION, 
                    HOLD_CODE, 
                    HOLD_PASSWORD, 
                    HOLD_PRV_GRP_ID, 
                    MAT_ID, 
                    MAT_VER, 
                    FLOW, 
                    FLOW_SEQ_NUM, 
                    OPER, 
                    RWK_CODE, 
                    RWK_FLOW, 
                    RWK_FLOW_SEQ_NUM, 
                    RWK_OPER, 
                    RWK_STOP_OPER, 
                    RET_FLOW, 
                    RET_FLOW_SEQ_NUM, 
                    RET_OPER, 
                    RET_CLEAR_FLAG, 
                    CMF_1, 
                    CMF_2, 
                    CMF_3, 
                    CMF_4, 
                    CMF_5, 
                    CMF_6, 
                    CMF_7, 
                    CMF_8, 
                    CMF_9, 
                    CMF_10, 
                    CMF_11, 
                    CMF_12, 
                    CMF_13, 
                    CMF_14, 
                    CMF_15, 
                    CMF_16, 
                    CMF_17, 
                    CMF_18, 
                    CMF_19, 
                    CMF_20, 
                    LOT_COMMENT, 
                    ALARM_SUBJECT, 
                    ALARM_MSG_1, 
                    ALARM_MSG_2, 
                    ALARM_MSG_3, 
                    EVENT_ID, 
                    CHG_STS_1, 
                    CHG_STS_2, 
                    CHG_STS_3, 
                    CHG_STS_4, 
                    CHG_STS_5, 
                    CHG_STS_6, 
                    CHG_STS_7, 
                    CHG_STS_8, 
                    CHG_STS_9, 
                    CHG_STS_10, 
                    RES_COMMENT, 
                    CLEAR_EVENT_ID, 
                    CLEAR_CHG_STS_1, 
                    CLEAR_CHG_STS_2, 
                    CLEAR_CHG_STS_3, 
                    CLEAR_CHG_STS_4, 
                    CLEAR_CHG_STS_5, 
                    CLEAR_CHG_STS_6, 
                    CLEAR_CHG_STS_7, 
                    CLEAR_CHG_STS_8, 
                    CLEAR_CHG_STS_9, 
                    CLEAR_CHG_STS_10, 
                    CLEAR_RES_COMMENT, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    ALARM_COMMENT_1, 
                    ALARM_COMMENT_2, 
                    ALARM_COMMENT_3, 
                    ALARM_COMMENT_4, 
                    ALARM_COMMENT_5, 
                    PDF_FILE_NAME, 
                    IMAGE_FILE_NAME, 
                    ALARM_CMF_1, 
                    ALARM_CMF_2, 
                    ALARM_CMF_3, 
                    ALARM_CMF_4, 
                    ALARM_CMF_5, 
                    ALARM_CMF_6, 
                    ALARM_CMF_7, 
                    ALARM_CMF_8, 
                    ALARM_CMF_9, 
                    ALARM_CMF_10, 
                    ALARM_CMF_11, 
                    ALARM_CMF_12, 
                    ALARM_CMF_13, 
                    ALARM_CMF_14, 
                    ALARM_CMF_15, 
                    ALARM_CMF_16, 
                    ALARM_CMF_17, 
                    ALARM_CMF_18, 
                    ALARM_CMF_19, 
                    ALARM_CMF_20, 
                    ALARM_GRP_1, 
                    ALARM_GRP_2, 
                    ALARM_GRP_3, 
                    ALARM_GRP_4, 
                    ALARM_GRP_5, 
                    ALARM_GRP_6, 
                    ALARM_GRP_7, 
                    ALARM_GRP_8, 
                    ALARM_GRP_9, 
                    ALARM_GRP_10
         ) 
        VALUES (
                    :MALMMSGDEF_N.FACTORY,
                    :MALMMSGDEF_N.ALARM_ID,
                    :MALMMSGDEF_N.ALARM_DESC,
                    :MALMMSGDEF_N.ALARM_TYPE,
                    :MALMMSGDEF_N.ALARM_LEVEL_FLAG,
                    :MALMMSGDEF_N.SEND_TO_USER_FLAG,
                    :MALMMSGDEF_N.ACTION_DISPLAY_FLAG,
                    :MALMMSGDEF_N.ACTION_MAIL_FLAG,
                    :MALMMSGDEF_N.ACTION_MSG_FLAG,
                    :MALMMSGDEF_N.ALARM_LOT_ACTION,
                    :MALMMSGDEF_N.HOLD_CODE,
                    :MALMMSGDEF_N.HOLD_PASSWORD,
                    :MALMMSGDEF_N.HOLD_PRV_GRP_ID,
                    :MALMMSGDEF_N.MAT_ID,
                    :MALMMSGDEF_N.MAT_VER,
                    :MALMMSGDEF_N.FLOW,
                    :MALMMSGDEF_N.FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.OPER,
                    :MALMMSGDEF_N.RWK_CODE,
                    :MALMMSGDEF_N.RWK_FLOW,
                    :MALMMSGDEF_N.RWK_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RWK_OPER,
                    :MALMMSGDEF_N.RWK_STOP_OPER,
                    :MALMMSGDEF_N.RET_FLOW,
                    :MALMMSGDEF_N.RET_FLOW_SEQ_NUM,
                    :MALMMSGDEF_N.RET_OPER,
                    :MALMMSGDEF_N.RET_CLEAR_FLAG,
                    :MALMMSGDEF_N.CMF_1,
                    :MALMMSGDEF_N.CMF_2,
                    :MALMMSGDEF_N.CMF_3,
                    :MALMMSGDEF_N.CMF_4,
                    :MALMMSGDEF_N.CMF_5,
                    :MALMMSGDEF_N.CMF_6,
                    :MALMMSGDEF_N.CMF_7,
                    :MALMMSGDEF_N.CMF_8,
                    :MALMMSGDEF_N.CMF_9,
                    :MALMMSGDEF_N.CMF_10,
                    :MALMMSGDEF_N.CMF_11,
                    :MALMMSGDEF_N.CMF_12,
                    :MALMMSGDEF_N.CMF_13,
                    :MALMMSGDEF_N.CMF_14,
                    :MALMMSGDEF_N.CMF_15,
                    :MALMMSGDEF_N.CMF_16,
                    :MALMMSGDEF_N.CMF_17,
                    :MALMMSGDEF_N.CMF_18,
                    :MALMMSGDEF_N.CMF_19,
                    :MALMMSGDEF_N.CMF_20,
                    :MALMMSGDEF_N.LOT_COMMENT,
                    :MALMMSGDEF_N.ALARM_SUBJECT,
                    :MALMMSGDEF_N.ALARM_MSG_1,
                    :MALMMSGDEF_N.ALARM_MSG_2,
                    :MALMMSGDEF_N.ALARM_MSG_3,
                    :MALMMSGDEF_N.EVENT_ID,
                    :MALMMSGDEF_N.CHG_STS_1,
                    :MALMMSGDEF_N.CHG_STS_2,
                    :MALMMSGDEF_N.CHG_STS_3,
                    :MALMMSGDEF_N.CHG_STS_4,
                    :MALMMSGDEF_N.CHG_STS_5,
                    :MALMMSGDEF_N.CHG_STS_6,
                    :MALMMSGDEF_N.CHG_STS_7,
                    :MALMMSGDEF_N.CHG_STS_8,
                    :MALMMSGDEF_N.CHG_STS_9,
                    :MALMMSGDEF_N.CHG_STS_10,
                    :MALMMSGDEF_N.RES_COMMENT,
                    :MALMMSGDEF_N.CLEAR_EVENT_ID,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_1,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_2,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_3,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_4,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_5,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_6,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_7,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_8,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_9,
                    :MALMMSGDEF_N.CLEAR_CHG_STS_10,
                    :MALMMSGDEF_N.CLEAR_RES_COMMENT,
                    :MALMMSGDEF_N.CREATE_USER_ID,
                    :MALMMSGDEF_N.CREATE_TIME,
                    :MALMMSGDEF_N.UPDATE_USER_ID,
                    :MALMMSGDEF_N.UPDATE_TIME,
                    :MALMMSGDEF_N.ALARM_COMMENT_1,
                    :MALMMSGDEF_N.ALARM_COMMENT_2,
                    :MALMMSGDEF_N.ALARM_COMMENT_3,
                    :MALMMSGDEF_N.ALARM_COMMENT_4,
                    :MALMMSGDEF_N.ALARM_COMMENT_5,
                    :MALMMSGDEF_N.PDF_FILE_NAME,
                    :MALMMSGDEF_N.IMAGE_FILE_NAME,
                    :MALMMSGDEF_N.ALARM_CMF_1,
                    :MALMMSGDEF_N.ALARM_CMF_2,
                    :MALMMSGDEF_N.ALARM_CMF_3,
                    :MALMMSGDEF_N.ALARM_CMF_4,
                    :MALMMSGDEF_N.ALARM_CMF_5,
                    :MALMMSGDEF_N.ALARM_CMF_6,
                    :MALMMSGDEF_N.ALARM_CMF_7,
                    :MALMMSGDEF_N.ALARM_CMF_8,
                    :MALMMSGDEF_N.ALARM_CMF_9,
                    :MALMMSGDEF_N.ALARM_CMF_10,
                    :MALMMSGDEF_N.ALARM_CMF_11,
                    :MALMMSGDEF_N.ALARM_CMF_12,
                    :MALMMSGDEF_N.ALARM_CMF_13,
                    :MALMMSGDEF_N.ALARM_CMF_14,
                    :MALMMSGDEF_N.ALARM_CMF_15,
                    :MALMMSGDEF_N.ALARM_CMF_16,
                    :MALMMSGDEF_N.ALARM_CMF_17,
                    :MALMMSGDEF_N.ALARM_CMF_18,
                    :MALMMSGDEF_N.ALARM_CMF_19,
                    :MALMMSGDEF_N.ALARM_CMF_20,
                    :MALMMSGDEF_N.ALARM_GRP_1,
                    :MALMMSGDEF_N.ALARM_GRP_2,
                    :MALMMSGDEF_N.ALARM_GRP_3,
                    :MALMMSGDEF_N.ALARM_GRP_4,
                    :MALMMSGDEF_N.ALARM_GRP_5,
                    :MALMMSGDEF_N.ALARM_GRP_6,
                    :MALMMSGDEF_N.ALARM_GRP_7,
                    :MALMMSGDEF_N.ALARM_GRP_8,
                    :MALMMSGDEF_N.ALARM_GRP_9,
                    :MALMMSGDEF_N.ALARM_GRP_10
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 119;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MALMMSGDEF (FACTORY,ALARM_ID,ALARM_DESC,ALARM_TYPE,ALARM_\
LEVEL_FLAG,SEND_TO_USER_FLAG,ACTION_DISPLAY_FLAG,ACTION_MAIL_FLAG,ACTION_MSG\
_FLAG,ALARM_LOT_ACTION,HOLD_CODE,HOLD_PASSWORD,HOLD_PRV_GRP_ID,MAT_ID,MAT_VE\
R,FLOW,FLOW_SEQ_NUM,OPER,RWK_CODE,RWK_FLOW,RWK_FLOW_SEQ_NUM,RWK_OPER,RWK_STO\
P_OPER,RET_FLOW,RET_FLOW_SEQ_NUM,RET_OPER,RET_CLEAR_FLAG,CMF_1,CMF_2,CMF_3,C\
MF_4,CMF_5,CMF_6,CMF_7,CMF_8,CMF_9,CMF_10,CMF_11,CMF_12,CMF_13,CMF_14,CMF_15\
,CMF_16,CMF_17,CMF_18,CMF_19,CMF_20,LOT_COMMENT,ALARM_SUBJECT,ALARM_MSG_1,AL\
ARM_MSG_2,ALARM_MSG_3,EVENT_ID,CHG_STS_1,CHG_STS_2,CHG_STS_3,CHG_STS_4,CHG_S\
TS_5,CHG_STS_6,CHG_STS_7,CHG_STS_8,CHG_STS_9,CHG_STS_10,RES_COMMENT,CLEAR_EV\
ENT_ID,CLEAR_CHG_STS_1,CLEAR_CHG_STS_2,CLEAR_CHG_STS_3,CLEAR_CHG_STS_4,CLEAR\
_CHG_STS_5,CLEAR_CHG_STS_6,CLEAR_CHG_STS_7,CLEAR_CHG_STS_8,CLEAR_CHG_STS_9,C\
LEAR_CHG_STS_10,CLEAR_RES_COMMENT,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,\
UPDATE_TIME,ALARM_COMMENT_1,ALARM_COMMENT_2,ALARM_COMMENT_3,ALARM_COMMENT_4,\
ALARM_COMMENT_5,PDF_FILE_NAME,IMAGE_FILE_NA");
    sqlstm.stmt = "ME,ALARM_CMF_1,ALARM_CMF_2,ALARM_CMF_3,ALARM_CMF_4,ALARM\
_CMF_5,ALARM_CMF_6,ALARM_CMF_7,ALARM_CMF_8,ALARM_CMF_9,ALARM_CMF_10,ALARM_CMF\
_11,ALARM_CMF_12,ALARM_CMF_13,ALARM_CMF_14,ALARM_CMF_15,ALARM_CMF_16,ALARM_CM\
F_17,ALARM_CMF_18,ALARM_CMF_19,ALARM_CMF_20,ALARM_GRP_1,ALARM_GRP_2,ALARM_GRP\
_3,ALARM_GRP_4,ALARM_GRP_5,ALARM_GRP_6,ALARM_GRP_7,ALARM_GRP_8,ALARM_GRP_9,AL\
ARM_GRP_10) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b\
13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28\
,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:\
b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b5\
9,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,\
:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b\
90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104\
,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1037;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
    sqlstm.sqhstl[3] = (unsigned int  )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MALMMSGDEF_N.ALARM_LEVEL_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MALMMSGDEF_N.SEND_TO_USER_FLAG);
    sqlstm.sqhstl[5] = (unsigned int  )2;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MALMMSGDEF_N.ACTION_DISPLAY_FLAG);
    sqlstm.sqhstl[6] = (unsigned int  )2;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MALMMSGDEF_N.ACTION_MAIL_FLAG);
    sqlstm.sqhstl[7] = (unsigned int  )2;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MALMMSGDEF_N.ACTION_MSG_FLAG);
    sqlstm.sqhstl[8] = (unsigned int  )2;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MALMMSGDEF_N.ALARM_LOT_ACTION);
    sqlstm.sqhstl[9] = (unsigned int  )11;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MALMMSGDEF_N.HOLD_CODE);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MALMMSGDEF_N.HOLD_PASSWORD);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MALMMSGDEF_N.HOLD_PRV_GRP_ID);
    sqlstm.sqhstl[12] = (unsigned int  )21;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MALMMSGDEF_N.MAT_ID);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(MALMMSGDEF_N.MAT_VER);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MALMMSGDEF_N.FLOW);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MALMMSGDEF_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MALMMSGDEF_N.OPER);
    sqlstm.sqhstl[17] = (unsigned int  )11;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MALMMSGDEF_N.RWK_CODE);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MALMMSGDEF_N.RWK_FLOW);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)&(MALMMSGDEF_N.RWK_FLOW_SEQ_NUM);
    sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MALMMSGDEF_N.RWK_OPER);
    sqlstm.sqhstl[21] = (unsigned int  )11;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MALMMSGDEF_N.RWK_STOP_OPER);
    sqlstm.sqhstl[22] = (unsigned int  )11;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MALMMSGDEF_N.RET_FLOW);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(MALMMSGDEF_N.RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MALMMSGDEF_N.RET_OPER);
    sqlstm.sqhstl[25] = (unsigned int  )11;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MALMMSGDEF_N.RET_CLEAR_FLAG);
    sqlstm.sqhstl[26] = (unsigned int  )2;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MALMMSGDEF_N.CMF_1);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MALMMSGDEF_N.CMF_2);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MALMMSGDEF_N.CMF_3);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MALMMSGDEF_N.CMF_4);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MALMMSGDEF_N.CMF_5);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MALMMSGDEF_N.CMF_6);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MALMMSGDEF_N.CMF_7);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MALMMSGDEF_N.CMF_8);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MALMMSGDEF_N.CMF_9);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MALMMSGDEF_N.CMF_10);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MALMMSGDEF_N.CMF_11);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MALMMSGDEF_N.CMF_12);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MALMMSGDEF_N.CMF_13);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MALMMSGDEF_N.CMF_14);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MALMMSGDEF_N.CMF_15);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MALMMSGDEF_N.CMF_16);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MALMMSGDEF_N.CMF_17);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MALMMSGDEF_N.CMF_18);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MALMMSGDEF_N.CMF_19);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MALMMSGDEF_N.CMF_20);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MALMMSGDEF_N.LOT_COMMENT);
    sqlstm.sqhstl[47] = (unsigned int  )401;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MALMMSGDEF_N.ALARM_SUBJECT);
    sqlstm.sqhstl[48] = (unsigned int  )201;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_1);
    sqlstm.sqhstl[49] = (unsigned int  )1001;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_2);
    sqlstm.sqhstl[50] = (unsigned int  )1001;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_3);
    sqlstm.sqhstl[51] = (unsigned int  )1001;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MALMMSGDEF_N.EVENT_ID);
    sqlstm.sqhstl[52] = (unsigned int  )13;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MALMMSGDEF_N.CHG_STS_1);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MALMMSGDEF_N.CHG_STS_2);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MALMMSGDEF_N.CHG_STS_3);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MALMMSGDEF_N.CHG_STS_4);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MALMMSGDEF_N.CHG_STS_5);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MALMMSGDEF_N.CHG_STS_6);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MALMMSGDEF_N.CHG_STS_7);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MALMMSGDEF_N.CHG_STS_8);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MALMMSGDEF_N.CHG_STS_9);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MALMMSGDEF_N.CHG_STS_10);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MALMMSGDEF_N.RES_COMMENT);
    sqlstm.sqhstl[63] = (unsigned int  )401;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MALMMSGDEF_N.CLEAR_EVENT_ID);
    sqlstm.sqhstl[64] = (unsigned int  )13;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_1);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_2);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_3);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_4);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_5);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_6);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_7);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_8);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_9);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_10);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MALMMSGDEF_N.CLEAR_RES_COMMENT);
    sqlstm.sqhstl[75] = (unsigned int  )401;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MALMMSGDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[76] = (unsigned int  )21;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MALMMSGDEF_N.CREATE_TIME);
    sqlstm.sqhstl[77] = (unsigned int  )15;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MALMMSGDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[78] = (unsigned int  )21;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MALMMSGDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[79] = (unsigned int  )15;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_1);
    sqlstm.sqhstl[80] = (unsigned int  )1001;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_2);
    sqlstm.sqhstl[81] = (unsigned int  )1001;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_3);
    sqlstm.sqhstl[82] = (unsigned int  )1001;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_4);
    sqlstm.sqhstl[83] = (unsigned int  )1001;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_5);
    sqlstm.sqhstl[84] = (unsigned int  )1001;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MALMMSGDEF_N.PDF_FILE_NAME);
    sqlstm.sqhstl[85] = (unsigned int  )51;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MALMMSGDEF_N.IMAGE_FILE_NAME);
    sqlstm.sqhstl[86] = (unsigned int  )51;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_1);
    sqlstm.sqhstl[87] = (unsigned int  )31;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_2);
    sqlstm.sqhstl[88] = (unsigned int  )31;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_3);
    sqlstm.sqhstl[89] = (unsigned int  )31;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_4);
    sqlstm.sqhstl[90] = (unsigned int  )31;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_5);
    sqlstm.sqhstl[91] = (unsigned int  )31;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_6);
    sqlstm.sqhstl[92] = (unsigned int  )31;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_7);
    sqlstm.sqhstl[93] = (unsigned int  )31;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_8);
    sqlstm.sqhstl[94] = (unsigned int  )31;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_9);
    sqlstm.sqhstl[95] = (unsigned int  )31;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_10);
    sqlstm.sqhstl[96] = (unsigned int  )31;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_11);
    sqlstm.sqhstl[97] = (unsigned int  )31;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_12);
    sqlstm.sqhstl[98] = (unsigned int  )31;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_13);
    sqlstm.sqhstl[99] = (unsigned int  )31;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_14);
    sqlstm.sqhstl[100] = (unsigned int  )31;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_15);
    sqlstm.sqhstl[101] = (unsigned int  )31;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_16);
    sqlstm.sqhstl[102] = (unsigned int  )31;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_17);
    sqlstm.sqhstl[103] = (unsigned int  )31;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_18);
    sqlstm.sqhstl[104] = (unsigned int  )31;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_19);
    sqlstm.sqhstl[105] = (unsigned int  )31;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_20);
    sqlstm.sqhstl[106] = (unsigned int  )31;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_1);
    sqlstm.sqhstl[107] = (unsigned int  )31;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_2);
    sqlstm.sqhstl[108] = (unsigned int  )31;
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_3);
    sqlstm.sqhstl[109] = (unsigned int  )31;
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_4);
    sqlstm.sqhstl[110] = (unsigned int  )31;
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_5);
    sqlstm.sqhstl[111] = (unsigned int  )31;
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_6);
    sqlstm.sqhstl[112] = (unsigned int  )31;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_7);
    sqlstm.sqhstl[113] = (unsigned int  )31;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_8);
    sqlstm.sqhstl[114] = (unsigned int  )31;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_9);
    sqlstm.sqhstl[115] = (unsigned int  )31;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_10);
    sqlstm.sqhstl[116] = (unsigned int  )31;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_malmmsgdef", 0);
}


/* SQL UPDATE Function */
void DBC_update_malmmsgdef(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MALMMSGDEF SET
                    ALARM_DESC = :MALMMSGDEF_N.ALARM_DESC,
                    ALARM_TYPE = :MALMMSGDEF_N.ALARM_TYPE,
                    ALARM_LEVEL_FLAG = :MALMMSGDEF_N.ALARM_LEVEL_FLAG,
                    SEND_TO_USER_FLAG = :MALMMSGDEF_N.SEND_TO_USER_FLAG,
                    ACTION_DISPLAY_FLAG = :MALMMSGDEF_N.ACTION_DISPLAY_FLAG,
                    ACTION_MAIL_FLAG = :MALMMSGDEF_N.ACTION_MAIL_FLAG,
                    ACTION_MSG_FLAG = :MALMMSGDEF_N.ACTION_MSG_FLAG,
                    ALARM_LOT_ACTION = :MALMMSGDEF_N.ALARM_LOT_ACTION,
                    HOLD_CODE = :MALMMSGDEF_N.HOLD_CODE,
                    HOLD_PASSWORD = :MALMMSGDEF_N.HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID = :MALMMSGDEF_N.HOLD_PRV_GRP_ID,
                    MAT_ID = :MALMMSGDEF_N.MAT_ID,
                    MAT_VER = :MALMMSGDEF_N.MAT_VER,
                    FLOW = :MALMMSGDEF_N.FLOW,
                    FLOW_SEQ_NUM = :MALMMSGDEF_N.FLOW_SEQ_NUM,
                    OPER = :MALMMSGDEF_N.OPER,
                    RWK_CODE = :MALMMSGDEF_N.RWK_CODE,
                    RWK_FLOW = :MALMMSGDEF_N.RWK_FLOW,
                    RWK_FLOW_SEQ_NUM = :MALMMSGDEF_N.RWK_FLOW_SEQ_NUM,
                    RWK_OPER = :MALMMSGDEF_N.RWK_OPER,
                    RWK_STOP_OPER = :MALMMSGDEF_N.RWK_STOP_OPER,
                    RET_FLOW = :MALMMSGDEF_N.RET_FLOW,
                    RET_FLOW_SEQ_NUM = :MALMMSGDEF_N.RET_FLOW_SEQ_NUM,
                    RET_OPER = :MALMMSGDEF_N.RET_OPER,
                    RET_CLEAR_FLAG = :MALMMSGDEF_N.RET_CLEAR_FLAG,
                    CMF_1 = :MALMMSGDEF_N.CMF_1,
                    CMF_2 = :MALMMSGDEF_N.CMF_2,
                    CMF_3 = :MALMMSGDEF_N.CMF_3,
                    CMF_4 = :MALMMSGDEF_N.CMF_4,
                    CMF_5 = :MALMMSGDEF_N.CMF_5,
                    CMF_6 = :MALMMSGDEF_N.CMF_6,
                    CMF_7 = :MALMMSGDEF_N.CMF_7,
                    CMF_8 = :MALMMSGDEF_N.CMF_8,
                    CMF_9 = :MALMMSGDEF_N.CMF_9,
                    CMF_10 = :MALMMSGDEF_N.CMF_10,
                    CMF_11 = :MALMMSGDEF_N.CMF_11,
                    CMF_12 = :MALMMSGDEF_N.CMF_12,
                    CMF_13 = :MALMMSGDEF_N.CMF_13,
                    CMF_14 = :MALMMSGDEF_N.CMF_14,
                    CMF_15 = :MALMMSGDEF_N.CMF_15,
                    CMF_16 = :MALMMSGDEF_N.CMF_16,
                    CMF_17 = :MALMMSGDEF_N.CMF_17,
                    CMF_18 = :MALMMSGDEF_N.CMF_18,
                    CMF_19 = :MALMMSGDEF_N.CMF_19,
                    CMF_20 = :MALMMSGDEF_N.CMF_20,
                    LOT_COMMENT = :MALMMSGDEF_N.LOT_COMMENT,
                    ALARM_SUBJECT = :MALMMSGDEF_N.ALARM_SUBJECT,
                    ALARM_MSG_1 = :MALMMSGDEF_N.ALARM_MSG_1,
                    ALARM_MSG_2 = :MALMMSGDEF_N.ALARM_MSG_2,
                    ALARM_MSG_3 = :MALMMSGDEF_N.ALARM_MSG_3,
                    EVENT_ID = :MALMMSGDEF_N.EVENT_ID,
                    CHG_STS_1 = :MALMMSGDEF_N.CHG_STS_1,
                    CHG_STS_2 = :MALMMSGDEF_N.CHG_STS_2,
                    CHG_STS_3 = :MALMMSGDEF_N.CHG_STS_3,
                    CHG_STS_4 = :MALMMSGDEF_N.CHG_STS_4,
                    CHG_STS_5 = :MALMMSGDEF_N.CHG_STS_5,
                    CHG_STS_6 = :MALMMSGDEF_N.CHG_STS_6,
                    CHG_STS_7 = :MALMMSGDEF_N.CHG_STS_7,
                    CHG_STS_8 = :MALMMSGDEF_N.CHG_STS_8,
                    CHG_STS_9 = :MALMMSGDEF_N.CHG_STS_9,
                    CHG_STS_10 = :MALMMSGDEF_N.CHG_STS_10,
                    RES_COMMENT = :MALMMSGDEF_N.RES_COMMENT,
                    CLEAR_EVENT_ID = :MALMMSGDEF_N.CLEAR_EVENT_ID,
                    CLEAR_CHG_STS_1 = :MALMMSGDEF_N.CLEAR_CHG_STS_1,
                    CLEAR_CHG_STS_2 = :MALMMSGDEF_N.CLEAR_CHG_STS_2,
                    CLEAR_CHG_STS_3 = :MALMMSGDEF_N.CLEAR_CHG_STS_3,
                    CLEAR_CHG_STS_4 = :MALMMSGDEF_N.CLEAR_CHG_STS_4,
                    CLEAR_CHG_STS_5 = :MALMMSGDEF_N.CLEAR_CHG_STS_5,
                    CLEAR_CHG_STS_6 = :MALMMSGDEF_N.CLEAR_CHG_STS_6,
                    CLEAR_CHG_STS_7 = :MALMMSGDEF_N.CLEAR_CHG_STS_7,
                    CLEAR_CHG_STS_8 = :MALMMSGDEF_N.CLEAR_CHG_STS_8,
                    CLEAR_CHG_STS_9 = :MALMMSGDEF_N.CLEAR_CHG_STS_9,
                    CLEAR_CHG_STS_10 = :MALMMSGDEF_N.CLEAR_CHG_STS_10,
                    CLEAR_RES_COMMENT = :MALMMSGDEF_N.CLEAR_RES_COMMENT,
                    CREATE_USER_ID = :MALMMSGDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MALMMSGDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MALMMSGDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MALMMSGDEF_N.UPDATE_TIME,
                    ALARM_COMMENT_1 = :MALMMSGDEF_N.ALARM_COMMENT_1,
                    ALARM_COMMENT_2 = :MALMMSGDEF_N.ALARM_COMMENT_2,
                    ALARM_COMMENT_3 = :MALMMSGDEF_N.ALARM_COMMENT_3,
                    ALARM_COMMENT_4 = :MALMMSGDEF_N.ALARM_COMMENT_4,
                    ALARM_COMMENT_5 = :MALMMSGDEF_N.ALARM_COMMENT_5,
                    PDF_FILE_NAME = :MALMMSGDEF_N.PDF_FILE_NAME,
                    IMAGE_FILE_NAME = :MALMMSGDEF_N.IMAGE_FILE_NAME,
                    ALARM_CMF_1 = :MALMMSGDEF_N.ALARM_CMF_1,
                    ALARM_CMF_2 = :MALMMSGDEF_N.ALARM_CMF_2,
                    ALARM_CMF_3 = :MALMMSGDEF_N.ALARM_CMF_3,
                    ALARM_CMF_4 = :MALMMSGDEF_N.ALARM_CMF_4,
                    ALARM_CMF_5 = :MALMMSGDEF_N.ALARM_CMF_5,
                    ALARM_CMF_6 = :MALMMSGDEF_N.ALARM_CMF_6,
                    ALARM_CMF_7 = :MALMMSGDEF_N.ALARM_CMF_7,
                    ALARM_CMF_8 = :MALMMSGDEF_N.ALARM_CMF_8,
                    ALARM_CMF_9 = :MALMMSGDEF_N.ALARM_CMF_9,
                    ALARM_CMF_10 = :MALMMSGDEF_N.ALARM_CMF_10,
                    ALARM_CMF_11 = :MALMMSGDEF_N.ALARM_CMF_11,
                    ALARM_CMF_12 = :MALMMSGDEF_N.ALARM_CMF_12,
                    ALARM_CMF_13 = :MALMMSGDEF_N.ALARM_CMF_13,
                    ALARM_CMF_14 = :MALMMSGDEF_N.ALARM_CMF_14,
                    ALARM_CMF_15 = :MALMMSGDEF_N.ALARM_CMF_15,
                    ALARM_CMF_16 = :MALMMSGDEF_N.ALARM_CMF_16,
                    ALARM_CMF_17 = :MALMMSGDEF_N.ALARM_CMF_17,
                    ALARM_CMF_18 = :MALMMSGDEF_N.ALARM_CMF_18,
                    ALARM_CMF_19 = :MALMMSGDEF_N.ALARM_CMF_19,
                    ALARM_CMF_20 = :MALMMSGDEF_N.ALARM_CMF_20,
                    ALARM_GRP_1 = :MALMMSGDEF_N.ALARM_GRP_1,
                    ALARM_GRP_2 = :MALMMSGDEF_N.ALARM_GRP_2,
                    ALARM_GRP_3 = :MALMMSGDEF_N.ALARM_GRP_3,
                    ALARM_GRP_4 = :MALMMSGDEF_N.ALARM_GRP_4,
                    ALARM_GRP_5 = :MALMMSGDEF_N.ALARM_GRP_5,
                    ALARM_GRP_6 = :MALMMSGDEF_N.ALARM_GRP_6,
                    ALARM_GRP_7 = :MALMMSGDEF_N.ALARM_GRP_7,
                    ALARM_GRP_8 = :MALMMSGDEF_N.ALARM_GRP_8,
                    ALARM_GRP_9 = :MALMMSGDEF_N.ALARM_GRP_9,
                    ALARM_GRP_10 = :MALMMSGDEF_N.ALARM_GRP_10
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID = :MALMMSGDEF_N.ALARM_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MALMMSGDEF  set ALARM_DESC=:b0,ALARM_TYPE=:b1,ALARM_LE\
VEL_FLAG=:b2,SEND_TO_USER_FLAG=:b3,ACTION_DISPLAY_FLAG=:b4,ACTION_MAIL_FLAG=\
:b5,ACTION_MSG_FLAG=:b6,ALARM_LOT_ACTION=:b7,HOLD_CODE=:b8,HOLD_PASSWORD=:b9\
,HOLD_PRV_GRP_ID=:b10,MAT_ID=:b11,MAT_VER=:b12,FLOW=:b13,FLOW_SEQ_NUM=:b14,O\
PER=:b15,RWK_CODE=:b16,RWK_FLOW=:b17,RWK_FLOW_SEQ_NUM=:b18,RWK_OPER=:b19,RWK\
_STOP_OPER=:b20,RET_FLOW=:b21,RET_FLOW_SEQ_NUM=:b22,RET_OPER=:b23,RET_CLEAR_\
FLAG=:b24,CMF_1=:b25,CMF_2=:b26,CMF_3=:b27,CMF_4=:b28,CMF_5=:b29,CMF_6=:b30,\
CMF_7=:b31,CMF_8=:b32,CMF_9=:b33,CMF_10=:b34,CMF_11=:b35,CMF_12=:b36,CMF_13=\
:b37,CMF_14=:b38,CMF_15=:b39,CMF_16=:b40,CMF_17=:b41,CMF_18=:b42,CMF_19=:b43\
,CMF_20=:b44,LOT_COMMENT=:b45,ALARM_SUBJECT=:b46,ALARM_MSG_1=:b47,ALARM_MSG_\
2=:b48,ALARM_MSG_3=:b49,EVENT_ID=:b50,CHG_STS_1=:b51,CHG_STS_2=:b52,CHG_STS_\
3=:b53,CHG_STS_4=:b54,CHG_STS_5=:b55,CHG_STS_6=:b56,CHG_STS_7=:b57,CHG_STS_8\
=:b58,CHG_STS_9=:b59,CHG_STS_10=:b60,RES_COMMENT=:b61,CLEAR_EVENT_ID=:b62,CL\
EAR_CHG_STS_1=:b63,CLEAR_CHG_STS_2=:b64,CLEAR_CHG_S");
            sqlstm.stmt = "TS_3=:b65,CLEAR_CHG_STS_4=:b66,CLEAR_CHG_STS_5=:\
b67,CLEAR_CHG_STS_6=:b68,CLEAR_CHG_STS_7=:b69,CLEAR_CHG_STS_8=:b70,CLEAR_CHG_\
STS_9=:b71,CLEAR_CHG_STS_10=:b72,CLEAR_RES_COMMENT=:b73,CREATE_USER_ID=:b74,C\
REATE_TIME=:b75,UPDATE_USER_ID=:b76,UPDATE_TIME=:b77,ALARM_COMMENT_1=:b78,ALA\
RM_COMMENT_2=:b79,ALARM_COMMENT_3=:b80,ALARM_COMMENT_4=:b81,ALARM_COMMENT_5=:\
b82,PDF_FILE_NAME=:b83,IMAGE_FILE_NAME=:b84,ALARM_CMF_1=:b85,ALARM_CMF_2=:b86\
,ALARM_CMF_3=:b87,ALARM_CMF_4=:b88,ALARM_CMF_5=:b89,ALARM_CMF_6=:b90,ALARM_CM\
F_7=:b91,ALARM_CMF_8=:b92,ALARM_CMF_9=:b93,ALARM_CMF_10=:b94,ALARM_CMF_11=:b9\
5,ALARM_CMF_12=:b96,ALARM_CMF_13=:b97,ALARM_CMF_14=:b98,ALARM_CMF_15=:b99,ALA\
RM_CMF_16=:b100,ALARM_CMF_17=:b101,ALARM_CMF_18=:b102,ALARM_CMF_19=:b103,ALAR\
M_CMF_20=:b104,ALARM_GRP_1=:b105,ALARM_GRP_2=:b106,ALARM_GRP_3=:b107,ALARM_GR\
P_4=:b108,ALARM_GRP_5=:b109,ALARM_GRP_6=:b110,ALARM_GRP_7=:b111,ALARM_GRP_8=:\
b112,ALARM_GRP_9=:b113,ALARM_GRP_10=:b114 where (FACTORY=:b115 and ALARM_ID=:\
b116)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1520;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.ALARM_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_LEVEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MALMMSGDEF_N.SEND_TO_USER_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MALMMSGDEF_N.ACTION_DISPLAY_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MALMMSGDEF_N.ACTION_MAIL_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MALMMSGDEF_N.ACTION_MSG_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MALMMSGDEF_N.ALARM_LOT_ACTION);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MALMMSGDEF_N.HOLD_CODE);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MALMMSGDEF_N.HOLD_PASSWORD);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MALMMSGDEF_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MALMMSGDEF_N.MAT_ID);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MALMMSGDEF_N.MAT_VER);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MALMMSGDEF_N.FLOW);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MALMMSGDEF_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MALMMSGDEF_N.OPER);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MALMMSGDEF_N.RWK_CODE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MALMMSGDEF_N.RWK_FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MALMMSGDEF_N.RWK_FLOW_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MALMMSGDEF_N.RWK_OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MALMMSGDEF_N.RWK_STOP_OPER);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MALMMSGDEF_N.RET_FLOW);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MALMMSGDEF_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MALMMSGDEF_N.RET_OPER);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MALMMSGDEF_N.RET_CLEAR_FLAG);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MALMMSGDEF_N.CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MALMMSGDEF_N.CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MALMMSGDEF_N.CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MALMMSGDEF_N.CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MALMMSGDEF_N.CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MALMMSGDEF_N.CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MALMMSGDEF_N.CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MALMMSGDEF_N.CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MALMMSGDEF_N.CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MALMMSGDEF_N.CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MALMMSGDEF_N.CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MALMMSGDEF_N.CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MALMMSGDEF_N.CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MALMMSGDEF_N.CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MALMMSGDEF_N.CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MALMMSGDEF_N.CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MALMMSGDEF_N.CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MALMMSGDEF_N.CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MALMMSGDEF_N.CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MALMMSGDEF_N.CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MALMMSGDEF_N.LOT_COMMENT);
            sqlstm.sqhstl[45] = (unsigned int  )401;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MALMMSGDEF_N.ALARM_SUBJECT);
            sqlstm.sqhstl[46] = (unsigned int  )201;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_1);
            sqlstm.sqhstl[47] = (unsigned int  )1001;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_2);
            sqlstm.sqhstl[48] = (unsigned int  )1001;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_3);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MALMMSGDEF_N.EVENT_ID);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MALMMSGDEF_N.CHG_STS_1);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MALMMSGDEF_N.CHG_STS_2);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MALMMSGDEF_N.CHG_STS_3);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MALMMSGDEF_N.CHG_STS_4);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MALMMSGDEF_N.CHG_STS_5);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MALMMSGDEF_N.CHG_STS_6);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MALMMSGDEF_N.CHG_STS_7);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MALMMSGDEF_N.CHG_STS_8);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MALMMSGDEF_N.CHG_STS_9);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MALMMSGDEF_N.CHG_STS_10);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MALMMSGDEF_N.RES_COMMENT);
            sqlstm.sqhstl[61] = (unsigned int  )401;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MALMMSGDEF_N.CLEAR_EVENT_ID);
            sqlstm.sqhstl[62] = (unsigned int  )13;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_1);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_2);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_3);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_4);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_5);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_6);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_7);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_8);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_9);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_10);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MALMMSGDEF_N.CLEAR_RES_COMMENT);
            sqlstm.sqhstl[73] = (unsigned int  )401;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MALMMSGDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MALMMSGDEF_N.CREATE_TIME);
            sqlstm.sqhstl[75] = (unsigned int  )15;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MALMMSGDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MALMMSGDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_1);
            sqlstm.sqhstl[78] = (unsigned int  )1001;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_2);
            sqlstm.sqhstl[79] = (unsigned int  )1001;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_3);
            sqlstm.sqhstl[80] = (unsigned int  )1001;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_4);
            sqlstm.sqhstl[81] = (unsigned int  )1001;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_5);
            sqlstm.sqhstl[82] = (unsigned int  )1001;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MALMMSGDEF_N.PDF_FILE_NAME);
            sqlstm.sqhstl[83] = (unsigned int  )51;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MALMMSGDEF_N.IMAGE_FILE_NAME);
            sqlstm.sqhstl[84] = (unsigned int  )51;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_1);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_2);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_3);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_4);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_5);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_6);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_7);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_8);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_9);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_10);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_11);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_12);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_13);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_14);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_15);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_16);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_17);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_18);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_19);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_20);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_1);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_2);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_3);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_4);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_5);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_6);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_7);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_8);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_9);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_10);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[115] = (unsigned int  )11;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_malmmsgdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_malmmsgdef(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MALMMSGDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    ALARM_ID,
                    ALARM_DESC,
                    ALARM_TYPE,
                    ALARM_LEVEL_FLAG,
                    SEND_TO_USER_FLAG,
                    ACTION_DISPLAY_FLAG,
                    ACTION_MAIL_FLAG,
                    ACTION_MSG_FLAG,
                    ALARM_LOT_ACTION,
                    HOLD_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    RWK_CODE,
                    RWK_FLOW,
                    RWK_FLOW_SEQ_NUM,
                    RWK_OPER,
                    RWK_STOP_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RET_CLEAR_FLAG,
                    CMF_1,
                    CMF_2,
                    CMF_3,
                    CMF_4,
                    CMF_5,
                    CMF_6,
                    CMF_7,
                    CMF_8,
                    CMF_9,
                    CMF_10,
                    CMF_11,
                    CMF_12,
                    CMF_13,
                    CMF_14,
                    CMF_15,
                    CMF_16,
                    CMF_17,
                    CMF_18,
                    CMF_19,
                    CMF_20,
                    LOT_COMMENT,
                    ALARM_SUBJECT,
                    ALARM_MSG_1,
                    ALARM_MSG_2,
                    ALARM_MSG_3,
                    EVENT_ID,
                    CHG_STS_1,
                    CHG_STS_2,
                    CHG_STS_3,
                    CHG_STS_4,
                    CHG_STS_5,
                    CHG_STS_6,
                    CHG_STS_7,
                    CHG_STS_8,
                    CHG_STS_9,
                    CHG_STS_10,
                    RES_COMMENT,
                    CLEAR_EVENT_ID,
                    CLEAR_CHG_STS_1,
                    CLEAR_CHG_STS_2,
                    CLEAR_CHG_STS_3,
                    CLEAR_CHG_STS_4,
                    CLEAR_CHG_STS_5,
                    CLEAR_CHG_STS_6,
                    CLEAR_CHG_STS_7,
                    CLEAR_CHG_STS_8,
                    CLEAR_CHG_STS_9,
                    CLEAR_CHG_STS_10,
                    CLEAR_RES_COMMENT,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    ALARM_COMMENT_1,
                    ALARM_COMMENT_2,
                    ALARM_COMMENT_3,
                    ALARM_COMMENT_4,
                    ALARM_COMMENT_5,
                    PDF_FILE_NAME,
                    IMAGE_FILE_NAME,
                    ALARM_CMF_1,
                    ALARM_CMF_2,
                    ALARM_CMF_3,
                    ALARM_CMF_4,
                    ALARM_CMF_5,
                    ALARM_CMF_6,
                    ALARM_CMF_7,
                    ALARM_CMF_8,
                    ALARM_CMF_9,
                    ALARM_CMF_10,
                    ALARM_CMF_11,
                    ALARM_CMF_12,
                    ALARM_CMF_13,
                    ALARM_CMF_14,
                    ALARM_CMF_15,
                    ALARM_CMF_16,
                    ALARM_CMF_17,
                    ALARM_CMF_18,
                    ALARM_CMF_19,
                    ALARM_CMF_20,
                    ALARM_GRP_1,
                    ALARM_GRP_2,
                    ALARM_GRP_3,
                    ALARM_GRP_4,
                    ALARM_GRP_5,
                    ALARM_GRP_6,
                    ALARM_GRP_7,
                    ALARM_GRP_8,
                    ALARM_GRP_9,
                    ALARM_GRP_10
                FROM MALMMSGDEF
                WHERE FACTORY = :MALMMSGDEF_N.FACTORY
                    AND ALARM_ID >= :MALMMSGDEF_N.ALARM_ID
                    AND ALARM_TYPE LIKE :MALMMSGDEF_N.ALARM_TYPE
                ORDER BY ALARM_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MALMMSGDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,ALARM_ID ,ALARM_DESC ,ALARM_TYPE ,ALARM_LEVEL\
_FLAG ,SEND_TO_USER_FLAG ,ACTION_DISPLAY_FLAG ,ACTION_MAIL_FLAG ,ACTION_MSG_\
FLAG ,ALARM_LOT_ACTION ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,MAT_ID ,M\
AT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,RWK_CODE ,RWK_FLOW ,RWK_FLOW_SEQ_NUM ,RWK_\
OPER ,RWK_STOP_OPER ,RET_FLOW ,RET_FLOW_SEQ_NUM ,RET_OPER ,RET_CLEAR_FLAG ,C\
MF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11\
 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CMF_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LO\
T_COMMENT ,ALARM_SUBJECT ,ALARM_MSG_1 ,ALARM_MSG_2 ,ALARM_MSG_3 ,EVENT_ID ,C\
HG_STS_1 ,CHG_STS_2 ,CHG_STS_3 ,CHG_STS_4 ,CHG_STS_5 ,CHG_STS_6 ,CHG_STS_7 ,\
CHG_STS_8 ,CHG_STS_9 ,CHG_STS_10 ,RES_COMMENT ,CLEAR_EVENT_ID ,CLEAR_CHG_STS\
_1 ,CLEAR_CHG_STS_2 ,CLEAR_CHG_STS_3 ,CLEAR_CHG_STS_4 ,CLEAR_CHG_STS_5 ,CLEA\
R_CHG_STS_6 ,CLEAR_CHG_STS_7 ,CLEAR_CHG_STS_8 ,CLEAR_CHG_STS_9 ,CLEAR_CHG_ST\
S_10 ,CLEAR_RES_COMMENT ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE\
_TIME ,ALARM_COMMENT_1 ,ALARM_COMMENT_2 ,ALARM_COMM");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2003;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_open_malmmsgdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_malmmsgdef(int sel_type, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MALMMSGDEF_N_TAG MALMMSGDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MALMMSGDEF_CUR_1 INTO
                :MALMMSGDEF_N.FACTORY,
                :MALMMSGDEF_N.ALARM_ID,
                :MALMMSGDEF_N.ALARM_DESC,
                :MALMMSGDEF_N.ALARM_TYPE,
                :MALMMSGDEF_N.ALARM_LEVEL_FLAG,
                :MALMMSGDEF_N.SEND_TO_USER_FLAG,
                :MALMMSGDEF_N.ACTION_DISPLAY_FLAG,
                :MALMMSGDEF_N.ACTION_MAIL_FLAG,
                :MALMMSGDEF_N.ACTION_MSG_FLAG,
                :MALMMSGDEF_N.ALARM_LOT_ACTION,
                :MALMMSGDEF_N.HOLD_CODE,
                :MALMMSGDEF_N.HOLD_PASSWORD,
                :MALMMSGDEF_N.HOLD_PRV_GRP_ID,
                :MALMMSGDEF_N.MAT_ID,
                :MALMMSGDEF_N.MAT_VER,
                :MALMMSGDEF_N.FLOW,
                :MALMMSGDEF_N.FLOW_SEQ_NUM,
                :MALMMSGDEF_N.OPER,
                :MALMMSGDEF_N.RWK_CODE,
                :MALMMSGDEF_N.RWK_FLOW,
                :MALMMSGDEF_N.RWK_FLOW_SEQ_NUM,
                :MALMMSGDEF_N.RWK_OPER,
                :MALMMSGDEF_N.RWK_STOP_OPER,
                :MALMMSGDEF_N.RET_FLOW,
                :MALMMSGDEF_N.RET_FLOW_SEQ_NUM,
                :MALMMSGDEF_N.RET_OPER,
                :MALMMSGDEF_N.RET_CLEAR_FLAG,
                :MALMMSGDEF_N.CMF_1,
                :MALMMSGDEF_N.CMF_2,
                :MALMMSGDEF_N.CMF_3,
                :MALMMSGDEF_N.CMF_4,
                :MALMMSGDEF_N.CMF_5,
                :MALMMSGDEF_N.CMF_6,
                :MALMMSGDEF_N.CMF_7,
                :MALMMSGDEF_N.CMF_8,
                :MALMMSGDEF_N.CMF_9,
                :MALMMSGDEF_N.CMF_10,
                :MALMMSGDEF_N.CMF_11,
                :MALMMSGDEF_N.CMF_12,
                :MALMMSGDEF_N.CMF_13,
                :MALMMSGDEF_N.CMF_14,
                :MALMMSGDEF_N.CMF_15,
                :MALMMSGDEF_N.CMF_16,
                :MALMMSGDEF_N.CMF_17,
                :MALMMSGDEF_N.CMF_18,
                :MALMMSGDEF_N.CMF_19,
                :MALMMSGDEF_N.CMF_20,
                :MALMMSGDEF_N.LOT_COMMENT,
                :MALMMSGDEF_N.ALARM_SUBJECT,
                :MALMMSGDEF_N.ALARM_MSG_1,
                :MALMMSGDEF_N.ALARM_MSG_2,
                :MALMMSGDEF_N.ALARM_MSG_3,
                :MALMMSGDEF_N.EVENT_ID,
                :MALMMSGDEF_N.CHG_STS_1,
                :MALMMSGDEF_N.CHG_STS_2,
                :MALMMSGDEF_N.CHG_STS_3,
                :MALMMSGDEF_N.CHG_STS_4,
                :MALMMSGDEF_N.CHG_STS_5,
                :MALMMSGDEF_N.CHG_STS_6,
                :MALMMSGDEF_N.CHG_STS_7,
                :MALMMSGDEF_N.CHG_STS_8,
                :MALMMSGDEF_N.CHG_STS_9,
                :MALMMSGDEF_N.CHG_STS_10,
                :MALMMSGDEF_N.RES_COMMENT,
                :MALMMSGDEF_N.CLEAR_EVENT_ID,
                :MALMMSGDEF_N.CLEAR_CHG_STS_1,
                :MALMMSGDEF_N.CLEAR_CHG_STS_2,
                :MALMMSGDEF_N.CLEAR_CHG_STS_3,
                :MALMMSGDEF_N.CLEAR_CHG_STS_4,
                :MALMMSGDEF_N.CLEAR_CHG_STS_5,
                :MALMMSGDEF_N.CLEAR_CHG_STS_6,
                :MALMMSGDEF_N.CLEAR_CHG_STS_7,
                :MALMMSGDEF_N.CLEAR_CHG_STS_8,
                :MALMMSGDEF_N.CLEAR_CHG_STS_9,
                :MALMMSGDEF_N.CLEAR_CHG_STS_10,
                :MALMMSGDEF_N.CLEAR_RES_COMMENT,
                :MALMMSGDEF_N.CREATE_USER_ID,
                :MALMMSGDEF_N.CREATE_TIME,
                :MALMMSGDEF_N.UPDATE_USER_ID,
                :MALMMSGDEF_N.UPDATE_TIME,
                :MALMMSGDEF_N.ALARM_COMMENT_1,
                :MALMMSGDEF_N.ALARM_COMMENT_2,
                :MALMMSGDEF_N.ALARM_COMMENT_3,
                :MALMMSGDEF_N.ALARM_COMMENT_4,
                :MALMMSGDEF_N.ALARM_COMMENT_5,
                :MALMMSGDEF_N.PDF_FILE_NAME,
                :MALMMSGDEF_N.IMAGE_FILE_NAME,
                :MALMMSGDEF_N.ALARM_CMF_1,
                :MALMMSGDEF_N.ALARM_CMF_2,
                :MALMMSGDEF_N.ALARM_CMF_3,
                :MALMMSGDEF_N.ALARM_CMF_4,
                :MALMMSGDEF_N.ALARM_CMF_5,
                :MALMMSGDEF_N.ALARM_CMF_6,
                :MALMMSGDEF_N.ALARM_CMF_7,
                :MALMMSGDEF_N.ALARM_CMF_8,
                :MALMMSGDEF_N.ALARM_CMF_9,
                :MALMMSGDEF_N.ALARM_CMF_10,
                :MALMMSGDEF_N.ALARM_CMF_11,
                :MALMMSGDEF_N.ALARM_CMF_12,
                :MALMMSGDEF_N.ALARM_CMF_13,
                :MALMMSGDEF_N.ALARM_CMF_14,
                :MALMMSGDEF_N.ALARM_CMF_15,
                :MALMMSGDEF_N.ALARM_CMF_16,
                :MALMMSGDEF_N.ALARM_CMF_17,
                :MALMMSGDEF_N.ALARM_CMF_18,
                :MALMMSGDEF_N.ALARM_CMF_19,
                :MALMMSGDEF_N.ALARM_CMF_20,
                :MALMMSGDEF_N.ALARM_GRP_1,
                :MALMMSGDEF_N.ALARM_GRP_2,
                :MALMMSGDEF_N.ALARM_GRP_3,
                :MALMMSGDEF_N.ALARM_GRP_4,
                :MALMMSGDEF_N.ALARM_GRP_5,
                :MALMMSGDEF_N.ALARM_GRP_6,
                :MALMMSGDEF_N.ALARM_GRP_7,
                :MALMMSGDEF_N.ALARM_GRP_8,
                :MALMMSGDEF_N.ALARM_GRP_9,
                :MALMMSGDEF_N.ALARM_GRP_10; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2030;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MALMMSGDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MALMMSGDEF_N.ALARM_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MALMMSGDEF_N.ALARM_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MALMMSGDEF_N.ALARM_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MALMMSGDEF_N.ALARM_LEVEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MALMMSGDEF_N.SEND_TO_USER_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MALMMSGDEF_N.ACTION_DISPLAY_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MALMMSGDEF_N.ACTION_MAIL_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MALMMSGDEF_N.ACTION_MSG_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MALMMSGDEF_N.ALARM_LOT_ACTION);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MALMMSGDEF_N.HOLD_CODE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MALMMSGDEF_N.HOLD_PASSWORD);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MALMMSGDEF_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MALMMSGDEF_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MALMMSGDEF_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MALMMSGDEF_N.FLOW);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MALMMSGDEF_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MALMMSGDEF_N.OPER);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MALMMSGDEF_N.RWK_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MALMMSGDEF_N.RWK_FLOW);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MALMMSGDEF_N.RWK_FLOW_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MALMMSGDEF_N.RWK_OPER);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MALMMSGDEF_N.RWK_STOP_OPER);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MALMMSGDEF_N.RET_FLOW);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MALMMSGDEF_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MALMMSGDEF_N.RET_OPER);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MALMMSGDEF_N.RET_CLEAR_FLAG);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MALMMSGDEF_N.CMF_1);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MALMMSGDEF_N.CMF_2);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MALMMSGDEF_N.CMF_3);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MALMMSGDEF_N.CMF_4);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MALMMSGDEF_N.CMF_5);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MALMMSGDEF_N.CMF_6);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MALMMSGDEF_N.CMF_7);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MALMMSGDEF_N.CMF_8);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MALMMSGDEF_N.CMF_9);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MALMMSGDEF_N.CMF_10);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MALMMSGDEF_N.CMF_11);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MALMMSGDEF_N.CMF_12);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MALMMSGDEF_N.CMF_13);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MALMMSGDEF_N.CMF_14);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MALMMSGDEF_N.CMF_15);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MALMMSGDEF_N.CMF_16);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MALMMSGDEF_N.CMF_17);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MALMMSGDEF_N.CMF_18);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MALMMSGDEF_N.CMF_19);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MALMMSGDEF_N.CMF_20);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MALMMSGDEF_N.LOT_COMMENT);
            sqlstm.sqhstl[47] = (unsigned int  )401;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MALMMSGDEF_N.ALARM_SUBJECT);
            sqlstm.sqhstl[48] = (unsigned int  )201;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_1);
            sqlstm.sqhstl[49] = (unsigned int  )1001;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_2);
            sqlstm.sqhstl[50] = (unsigned int  )1001;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MALMMSGDEF_N.ALARM_MSG_3);
            sqlstm.sqhstl[51] = (unsigned int  )1001;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MALMMSGDEF_N.EVENT_ID);
            sqlstm.sqhstl[52] = (unsigned int  )13;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MALMMSGDEF_N.CHG_STS_1);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MALMMSGDEF_N.CHG_STS_2);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MALMMSGDEF_N.CHG_STS_3);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MALMMSGDEF_N.CHG_STS_4);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MALMMSGDEF_N.CHG_STS_5);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MALMMSGDEF_N.CHG_STS_6);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MALMMSGDEF_N.CHG_STS_7);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MALMMSGDEF_N.CHG_STS_8);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MALMMSGDEF_N.CHG_STS_9);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MALMMSGDEF_N.CHG_STS_10);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MALMMSGDEF_N.RES_COMMENT);
            sqlstm.sqhstl[63] = (unsigned int  )401;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MALMMSGDEF_N.CLEAR_EVENT_ID);
            sqlstm.sqhstl[64] = (unsigned int  )13;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MALMMSGDEF_N.CLEAR_CHG_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MALMMSGDEF_N.CLEAR_RES_COMMENT);
            sqlstm.sqhstl[75] = (unsigned int  )401;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MALMMSGDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MALMMSGDEF_N.CREATE_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MALMMSGDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MALMMSGDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_1);
            sqlstm.sqhstl[80] = (unsigned int  )1001;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_2);
            sqlstm.sqhstl[81] = (unsigned int  )1001;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_3);
            sqlstm.sqhstl[82] = (unsigned int  )1001;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_4);
            sqlstm.sqhstl[83] = (unsigned int  )1001;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MALMMSGDEF_N.ALARM_COMMENT_5);
            sqlstm.sqhstl[84] = (unsigned int  )1001;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MALMMSGDEF_N.PDF_FILE_NAME);
            sqlstm.sqhstl[85] = (unsigned int  )51;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MALMMSGDEF_N.IMAGE_FILE_NAME);
            sqlstm.sqhstl[86] = (unsigned int  )51;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_1);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_2);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_3);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_4);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_5);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_6);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_7);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_8);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_9);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_10);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_11);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_12);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_13);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_14);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_15);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_16);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_17);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_18);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_19);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MALMMSGDEF_N.ALARM_CMF_20);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_1);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_2);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_3);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_4);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_5);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_6);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_7);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_8);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_9);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MALMMSGDEF_N.ALARM_GRP_10);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
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
        DBC_del_null_malmmsgdef(&MALMMSGDEF_N, MALMMSGDEF);
    }

    DB_stop_query_timer("DBC_fetch_malmmsgdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_malmmsgdef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MALMMSGDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 119;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2513;
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

    DB_stop_query_timer("DBC_close_malmmsgdef", sel_type);
}


/* Initialize Function */
void DBC_init_malmmsgdef(struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* memset by Space */
    memset(MALMMSGDEF, ' ', sizeof(struct MALMMSGDEF_TAG));
    
    MALMMSGDEF->MAT_VER = 0;
    MALMMSGDEF->FLOW_SEQ_NUM = 0;
    MALMMSGDEF->RWK_FLOW_SEQ_NUM = 0;
    MALMMSGDEF->RET_FLOW_SEQ_NUM = 0;
}


/* Add Null Function */
void DBC_add_null_malmmsgdef(struct MALMMSGDEF_N_TAG *MALMMSGDEF_N, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    /* memset by NULL */
    memset(MALMMSGDEF_N, '\0', sizeof(struct MALMMSGDEF_N_TAG));
    
    MEMCPY_AN(MALMMSGDEF_N->FACTORY, MALMMSGDEF->FACTORY, sizeof(MALMMSGDEF->FACTORY));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_ID, MALMMSGDEF->ALARM_ID, sizeof(MALMMSGDEF->ALARM_ID));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_DESC, MALMMSGDEF->ALARM_DESC, sizeof(MALMMSGDEF->ALARM_DESC));
    MALMMSGDEF_N->ALARM_TYPE[0] = MALMMSGDEF->ALARM_TYPE;
    MALMMSGDEF_N->ALARM_LEVEL_FLAG[0] = MALMMSGDEF->ALARM_LEVEL_FLAG;
    MALMMSGDEF_N->SEND_TO_USER_FLAG[0] = MALMMSGDEF->SEND_TO_USER_FLAG;
    MALMMSGDEF_N->ACTION_DISPLAY_FLAG[0] = MALMMSGDEF->ACTION_DISPLAY_FLAG;
    MALMMSGDEF_N->ACTION_MAIL_FLAG[0] = MALMMSGDEF->ACTION_MAIL_FLAG;
    MALMMSGDEF_N->ACTION_MSG_FLAG[0] = MALMMSGDEF->ACTION_MSG_FLAG;
    MEMCPY_AN(MALMMSGDEF_N->ALARM_LOT_ACTION, MALMMSGDEF->ALARM_LOT_ACTION, sizeof(MALMMSGDEF->ALARM_LOT_ACTION));
    MEMCPY_AN(MALMMSGDEF_N->HOLD_CODE, MALMMSGDEF->HOLD_CODE, sizeof(MALMMSGDEF->HOLD_CODE));
    MEMCPY_AN(MALMMSGDEF_N->HOLD_PASSWORD, MALMMSGDEF->HOLD_PASSWORD, sizeof(MALMMSGDEF->HOLD_PASSWORD));
    MEMCPY_AN(MALMMSGDEF_N->HOLD_PRV_GRP_ID, MALMMSGDEF->HOLD_PRV_GRP_ID, sizeof(MALMMSGDEF->HOLD_PRV_GRP_ID));
    MEMCPY_AN(MALMMSGDEF_N->MAT_ID, MALMMSGDEF->MAT_ID, sizeof(MALMMSGDEF->MAT_ID));
    MALMMSGDEF_N->MAT_VER = MALMMSGDEF->MAT_VER;
    MEMCPY_AN(MALMMSGDEF_N->FLOW, MALMMSGDEF->FLOW, sizeof(MALMMSGDEF->FLOW));
    MALMMSGDEF_N->FLOW_SEQ_NUM = MALMMSGDEF->FLOW_SEQ_NUM;
    MEMCPY_AN(MALMMSGDEF_N->OPER, MALMMSGDEF->OPER, sizeof(MALMMSGDEF->OPER));
    MEMCPY_AN(MALMMSGDEF_N->RWK_CODE, MALMMSGDEF->RWK_CODE, sizeof(MALMMSGDEF->RWK_CODE));
    MEMCPY_AN(MALMMSGDEF_N->RWK_FLOW, MALMMSGDEF->RWK_FLOW, sizeof(MALMMSGDEF->RWK_FLOW));
    MALMMSGDEF_N->RWK_FLOW_SEQ_NUM = MALMMSGDEF->RWK_FLOW_SEQ_NUM;
    MEMCPY_AN(MALMMSGDEF_N->RWK_OPER, MALMMSGDEF->RWK_OPER, sizeof(MALMMSGDEF->RWK_OPER));
    MEMCPY_AN(MALMMSGDEF_N->RWK_STOP_OPER, MALMMSGDEF->RWK_STOP_OPER, sizeof(MALMMSGDEF->RWK_STOP_OPER));
    MEMCPY_AN(MALMMSGDEF_N->RET_FLOW, MALMMSGDEF->RET_FLOW, sizeof(MALMMSGDEF->RET_FLOW));
    MALMMSGDEF_N->RET_FLOW_SEQ_NUM = MALMMSGDEF->RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MALMMSGDEF_N->RET_OPER, MALMMSGDEF->RET_OPER, sizeof(MALMMSGDEF->RET_OPER));
    MALMMSGDEF_N->RET_CLEAR_FLAG[0] = MALMMSGDEF->RET_CLEAR_FLAG;
    MEMCPY_AN(MALMMSGDEF_N->CMF_1, MALMMSGDEF->CMF_1, sizeof(MALMMSGDEF->CMF_1));
    MEMCPY_AN(MALMMSGDEF_N->CMF_2, MALMMSGDEF->CMF_2, sizeof(MALMMSGDEF->CMF_2));
    MEMCPY_AN(MALMMSGDEF_N->CMF_3, MALMMSGDEF->CMF_3, sizeof(MALMMSGDEF->CMF_3));
    MEMCPY_AN(MALMMSGDEF_N->CMF_4, MALMMSGDEF->CMF_4, sizeof(MALMMSGDEF->CMF_4));
    MEMCPY_AN(MALMMSGDEF_N->CMF_5, MALMMSGDEF->CMF_5, sizeof(MALMMSGDEF->CMF_5));
    MEMCPY_AN(MALMMSGDEF_N->CMF_6, MALMMSGDEF->CMF_6, sizeof(MALMMSGDEF->CMF_6));
    MEMCPY_AN(MALMMSGDEF_N->CMF_7, MALMMSGDEF->CMF_7, sizeof(MALMMSGDEF->CMF_7));
    MEMCPY_AN(MALMMSGDEF_N->CMF_8, MALMMSGDEF->CMF_8, sizeof(MALMMSGDEF->CMF_8));
    MEMCPY_AN(MALMMSGDEF_N->CMF_9, MALMMSGDEF->CMF_9, sizeof(MALMMSGDEF->CMF_9));
    MEMCPY_AN(MALMMSGDEF_N->CMF_10, MALMMSGDEF->CMF_10, sizeof(MALMMSGDEF->CMF_10));
    MEMCPY_AN(MALMMSGDEF_N->CMF_11, MALMMSGDEF->CMF_11, sizeof(MALMMSGDEF->CMF_11));
    MEMCPY_AN(MALMMSGDEF_N->CMF_12, MALMMSGDEF->CMF_12, sizeof(MALMMSGDEF->CMF_12));
    MEMCPY_AN(MALMMSGDEF_N->CMF_13, MALMMSGDEF->CMF_13, sizeof(MALMMSGDEF->CMF_13));
    MEMCPY_AN(MALMMSGDEF_N->CMF_14, MALMMSGDEF->CMF_14, sizeof(MALMMSGDEF->CMF_14));
    MEMCPY_AN(MALMMSGDEF_N->CMF_15, MALMMSGDEF->CMF_15, sizeof(MALMMSGDEF->CMF_15));
    MEMCPY_AN(MALMMSGDEF_N->CMF_16, MALMMSGDEF->CMF_16, sizeof(MALMMSGDEF->CMF_16));
    MEMCPY_AN(MALMMSGDEF_N->CMF_17, MALMMSGDEF->CMF_17, sizeof(MALMMSGDEF->CMF_17));
    MEMCPY_AN(MALMMSGDEF_N->CMF_18, MALMMSGDEF->CMF_18, sizeof(MALMMSGDEF->CMF_18));
    MEMCPY_AN(MALMMSGDEF_N->CMF_19, MALMMSGDEF->CMF_19, sizeof(MALMMSGDEF->CMF_19));
    MEMCPY_AN(MALMMSGDEF_N->CMF_20, MALMMSGDEF->CMF_20, sizeof(MALMMSGDEF->CMF_20));
    MEMCPY_AN(MALMMSGDEF_N->LOT_COMMENT, MALMMSGDEF->LOT_COMMENT, sizeof(MALMMSGDEF->LOT_COMMENT));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_SUBJECT, MALMMSGDEF->ALARM_SUBJECT, sizeof(MALMMSGDEF->ALARM_SUBJECT));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_MSG_1, MALMMSGDEF->ALARM_MSG_1, sizeof(MALMMSGDEF->ALARM_MSG_1));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_MSG_2, MALMMSGDEF->ALARM_MSG_2, sizeof(MALMMSGDEF->ALARM_MSG_2));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_MSG_3, MALMMSGDEF->ALARM_MSG_3, sizeof(MALMMSGDEF->ALARM_MSG_3));
    MEMCPY_AN(MALMMSGDEF_N->EVENT_ID, MALMMSGDEF->EVENT_ID, sizeof(MALMMSGDEF->EVENT_ID));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_1, MALMMSGDEF->CHG_STS_1, sizeof(MALMMSGDEF->CHG_STS_1));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_2, MALMMSGDEF->CHG_STS_2, sizeof(MALMMSGDEF->CHG_STS_2));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_3, MALMMSGDEF->CHG_STS_3, sizeof(MALMMSGDEF->CHG_STS_3));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_4, MALMMSGDEF->CHG_STS_4, sizeof(MALMMSGDEF->CHG_STS_4));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_5, MALMMSGDEF->CHG_STS_5, sizeof(MALMMSGDEF->CHG_STS_5));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_6, MALMMSGDEF->CHG_STS_6, sizeof(MALMMSGDEF->CHG_STS_6));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_7, MALMMSGDEF->CHG_STS_7, sizeof(MALMMSGDEF->CHG_STS_7));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_8, MALMMSGDEF->CHG_STS_8, sizeof(MALMMSGDEF->CHG_STS_8));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_9, MALMMSGDEF->CHG_STS_9, sizeof(MALMMSGDEF->CHG_STS_9));
    MEMCPY_AN(MALMMSGDEF_N->CHG_STS_10, MALMMSGDEF->CHG_STS_10, sizeof(MALMMSGDEF->CHG_STS_10));
    MEMCPY_AN(MALMMSGDEF_N->RES_COMMENT, MALMMSGDEF->RES_COMMENT, sizeof(MALMMSGDEF->RES_COMMENT));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_EVENT_ID, MALMMSGDEF->CLEAR_EVENT_ID, sizeof(MALMMSGDEF->CLEAR_EVENT_ID));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_1, MALMMSGDEF->CLEAR_CHG_STS_1, sizeof(MALMMSGDEF->CLEAR_CHG_STS_1));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_2, MALMMSGDEF->CLEAR_CHG_STS_2, sizeof(MALMMSGDEF->CLEAR_CHG_STS_2));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_3, MALMMSGDEF->CLEAR_CHG_STS_3, sizeof(MALMMSGDEF->CLEAR_CHG_STS_3));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_4, MALMMSGDEF->CLEAR_CHG_STS_4, sizeof(MALMMSGDEF->CLEAR_CHG_STS_4));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_5, MALMMSGDEF->CLEAR_CHG_STS_5, sizeof(MALMMSGDEF->CLEAR_CHG_STS_5));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_6, MALMMSGDEF->CLEAR_CHG_STS_6, sizeof(MALMMSGDEF->CLEAR_CHG_STS_6));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_7, MALMMSGDEF->CLEAR_CHG_STS_7, sizeof(MALMMSGDEF->CLEAR_CHG_STS_7));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_8, MALMMSGDEF->CLEAR_CHG_STS_8, sizeof(MALMMSGDEF->CLEAR_CHG_STS_8));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_9, MALMMSGDEF->CLEAR_CHG_STS_9, sizeof(MALMMSGDEF->CLEAR_CHG_STS_9));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_CHG_STS_10, MALMMSGDEF->CLEAR_CHG_STS_10, sizeof(MALMMSGDEF->CLEAR_CHG_STS_10));
    MEMCPY_AN(MALMMSGDEF_N->CLEAR_RES_COMMENT, MALMMSGDEF->CLEAR_RES_COMMENT, sizeof(MALMMSGDEF->CLEAR_RES_COMMENT));
    MEMCPY_AN(MALMMSGDEF_N->CREATE_USER_ID, MALMMSGDEF->CREATE_USER_ID, sizeof(MALMMSGDEF->CREATE_USER_ID));
    MEMCPY_AN(MALMMSGDEF_N->CREATE_TIME, MALMMSGDEF->CREATE_TIME, sizeof(MALMMSGDEF->CREATE_TIME));
    MEMCPY_AN(MALMMSGDEF_N->UPDATE_USER_ID, MALMMSGDEF->UPDATE_USER_ID, sizeof(MALMMSGDEF->UPDATE_USER_ID));
    MEMCPY_AN(MALMMSGDEF_N->UPDATE_TIME, MALMMSGDEF->UPDATE_TIME, sizeof(MALMMSGDEF->UPDATE_TIME));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_COMMENT_1, MALMMSGDEF->ALARM_COMMENT_1, sizeof(MALMMSGDEF->ALARM_COMMENT_1));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_COMMENT_2, MALMMSGDEF->ALARM_COMMENT_2, sizeof(MALMMSGDEF->ALARM_COMMENT_2));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_COMMENT_3, MALMMSGDEF->ALARM_COMMENT_3, sizeof(MALMMSGDEF->ALARM_COMMENT_3));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_COMMENT_4, MALMMSGDEF->ALARM_COMMENT_4, sizeof(MALMMSGDEF->ALARM_COMMENT_4));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_COMMENT_5, MALMMSGDEF->ALARM_COMMENT_5, sizeof(MALMMSGDEF->ALARM_COMMENT_5));
    MEMCPY_AN(MALMMSGDEF_N->PDF_FILE_NAME, MALMMSGDEF->PDF_FILE_NAME, sizeof(MALMMSGDEF->PDF_FILE_NAME));
    MEMCPY_AN(MALMMSGDEF_N->IMAGE_FILE_NAME, MALMMSGDEF->IMAGE_FILE_NAME, sizeof(MALMMSGDEF->IMAGE_FILE_NAME));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_1, MALMMSGDEF->ALARM_CMF_1, sizeof(MALMMSGDEF->ALARM_CMF_1));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_2, MALMMSGDEF->ALARM_CMF_2, sizeof(MALMMSGDEF->ALARM_CMF_2));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_3, MALMMSGDEF->ALARM_CMF_3, sizeof(MALMMSGDEF->ALARM_CMF_3));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_4, MALMMSGDEF->ALARM_CMF_4, sizeof(MALMMSGDEF->ALARM_CMF_4));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_5, MALMMSGDEF->ALARM_CMF_5, sizeof(MALMMSGDEF->ALARM_CMF_5));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_6, MALMMSGDEF->ALARM_CMF_6, sizeof(MALMMSGDEF->ALARM_CMF_6));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_7, MALMMSGDEF->ALARM_CMF_7, sizeof(MALMMSGDEF->ALARM_CMF_7));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_8, MALMMSGDEF->ALARM_CMF_8, sizeof(MALMMSGDEF->ALARM_CMF_8));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_9, MALMMSGDEF->ALARM_CMF_9, sizeof(MALMMSGDEF->ALARM_CMF_9));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_10, MALMMSGDEF->ALARM_CMF_10, sizeof(MALMMSGDEF->ALARM_CMF_10));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_11, MALMMSGDEF->ALARM_CMF_11, sizeof(MALMMSGDEF->ALARM_CMF_11));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_12, MALMMSGDEF->ALARM_CMF_12, sizeof(MALMMSGDEF->ALARM_CMF_12));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_13, MALMMSGDEF->ALARM_CMF_13, sizeof(MALMMSGDEF->ALARM_CMF_13));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_14, MALMMSGDEF->ALARM_CMF_14, sizeof(MALMMSGDEF->ALARM_CMF_14));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_15, MALMMSGDEF->ALARM_CMF_15, sizeof(MALMMSGDEF->ALARM_CMF_15));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_16, MALMMSGDEF->ALARM_CMF_16, sizeof(MALMMSGDEF->ALARM_CMF_16));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_17, MALMMSGDEF->ALARM_CMF_17, sizeof(MALMMSGDEF->ALARM_CMF_17));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_18, MALMMSGDEF->ALARM_CMF_18, sizeof(MALMMSGDEF->ALARM_CMF_18));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_19, MALMMSGDEF->ALARM_CMF_19, sizeof(MALMMSGDEF->ALARM_CMF_19));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_CMF_20, MALMMSGDEF->ALARM_CMF_20, sizeof(MALMMSGDEF->ALARM_CMF_20));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_1, MALMMSGDEF->ALARM_GRP_1, sizeof(MALMMSGDEF->ALARM_GRP_1));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_2, MALMMSGDEF->ALARM_GRP_2, sizeof(MALMMSGDEF->ALARM_GRP_2));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_3, MALMMSGDEF->ALARM_GRP_3, sizeof(MALMMSGDEF->ALARM_GRP_3));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_4, MALMMSGDEF->ALARM_GRP_4, sizeof(MALMMSGDEF->ALARM_GRP_4));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_5, MALMMSGDEF->ALARM_GRP_5, sizeof(MALMMSGDEF->ALARM_GRP_5));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_6, MALMMSGDEF->ALARM_GRP_6, sizeof(MALMMSGDEF->ALARM_GRP_6));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_7, MALMMSGDEF->ALARM_GRP_7, sizeof(MALMMSGDEF->ALARM_GRP_7));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_8, MALMMSGDEF->ALARM_GRP_8, sizeof(MALMMSGDEF->ALARM_GRP_8));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_9, MALMMSGDEF->ALARM_GRP_9, sizeof(MALMMSGDEF->ALARM_GRP_9));
    MEMCPY_AN(MALMMSGDEF_N->ALARM_GRP_10, MALMMSGDEF->ALARM_GRP_10, sizeof(MALMMSGDEF->ALARM_GRP_10));
}


/* Del Null Function */
void DBC_del_null_malmmsgdef(struct MALMMSGDEF_N_TAG *MALMMSGDEF_N, struct MALMMSGDEF_TAG *MALMMSGDEF)
{
    MEMCPY_DN(MALMMSGDEF->FACTORY, MALMMSGDEF_N->FACTORY, sizeof(MALMMSGDEF->FACTORY));
    MEMCPY_DN(MALMMSGDEF->ALARM_ID, MALMMSGDEF_N->ALARM_ID, sizeof(MALMMSGDEF->ALARM_ID));
    MEMCPY_DN(MALMMSGDEF->ALARM_DESC, MALMMSGDEF_N->ALARM_DESC, sizeof(MALMMSGDEF->ALARM_DESC));
    MALMMSGDEF->ALARM_TYPE = MALMMSGDEF_N->ALARM_TYPE[0];
    MALMMSGDEF->ALARM_LEVEL_FLAG = MALMMSGDEF_N->ALARM_LEVEL_FLAG[0];
    MALMMSGDEF->SEND_TO_USER_FLAG = MALMMSGDEF_N->SEND_TO_USER_FLAG[0];
    MALMMSGDEF->ACTION_DISPLAY_FLAG = MALMMSGDEF_N->ACTION_DISPLAY_FLAG[0];
    MALMMSGDEF->ACTION_MAIL_FLAG = MALMMSGDEF_N->ACTION_MAIL_FLAG[0];
    MALMMSGDEF->ACTION_MSG_FLAG = MALMMSGDEF_N->ACTION_MSG_FLAG[0];
    MEMCPY_DN(MALMMSGDEF->ALARM_LOT_ACTION, MALMMSGDEF_N->ALARM_LOT_ACTION, sizeof(MALMMSGDEF->ALARM_LOT_ACTION));
    MEMCPY_DN(MALMMSGDEF->HOLD_CODE, MALMMSGDEF_N->HOLD_CODE, sizeof(MALMMSGDEF->HOLD_CODE));
    MEMCPY_DN(MALMMSGDEF->HOLD_PASSWORD, MALMMSGDEF_N->HOLD_PASSWORD, sizeof(MALMMSGDEF->HOLD_PASSWORD));
    MEMCPY_DN(MALMMSGDEF->HOLD_PRV_GRP_ID, MALMMSGDEF_N->HOLD_PRV_GRP_ID, sizeof(MALMMSGDEF->HOLD_PRV_GRP_ID));
    MEMCPY_DN(MALMMSGDEF->MAT_ID, MALMMSGDEF_N->MAT_ID, sizeof(MALMMSGDEF->MAT_ID));
    MALMMSGDEF->MAT_VER = MALMMSGDEF_N->MAT_VER;
    MEMCPY_DN(MALMMSGDEF->FLOW, MALMMSGDEF_N->FLOW, sizeof(MALMMSGDEF->FLOW));
    MALMMSGDEF->FLOW_SEQ_NUM = MALMMSGDEF_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MALMMSGDEF->OPER, MALMMSGDEF_N->OPER, sizeof(MALMMSGDEF->OPER));
    MEMCPY_DN(MALMMSGDEF->RWK_CODE, MALMMSGDEF_N->RWK_CODE, sizeof(MALMMSGDEF->RWK_CODE));
    MEMCPY_DN(MALMMSGDEF->RWK_FLOW, MALMMSGDEF_N->RWK_FLOW, sizeof(MALMMSGDEF->RWK_FLOW));
    MALMMSGDEF->RWK_FLOW_SEQ_NUM = MALMMSGDEF_N->RWK_FLOW_SEQ_NUM;
    MEMCPY_DN(MALMMSGDEF->RWK_OPER, MALMMSGDEF_N->RWK_OPER, sizeof(MALMMSGDEF->RWK_OPER));
    MEMCPY_DN(MALMMSGDEF->RWK_STOP_OPER, MALMMSGDEF_N->RWK_STOP_OPER, sizeof(MALMMSGDEF->RWK_STOP_OPER));
    MEMCPY_DN(MALMMSGDEF->RET_FLOW, MALMMSGDEF_N->RET_FLOW, sizeof(MALMMSGDEF->RET_FLOW));
    MALMMSGDEF->RET_FLOW_SEQ_NUM = MALMMSGDEF_N->RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MALMMSGDEF->RET_OPER, MALMMSGDEF_N->RET_OPER, sizeof(MALMMSGDEF->RET_OPER));
    MALMMSGDEF->RET_CLEAR_FLAG = MALMMSGDEF_N->RET_CLEAR_FLAG[0];
    MEMCPY_DN(MALMMSGDEF->CMF_1, MALMMSGDEF_N->CMF_1, sizeof(MALMMSGDEF->CMF_1));
    MEMCPY_DN(MALMMSGDEF->CMF_2, MALMMSGDEF_N->CMF_2, sizeof(MALMMSGDEF->CMF_2));
    MEMCPY_DN(MALMMSGDEF->CMF_3, MALMMSGDEF_N->CMF_3, sizeof(MALMMSGDEF->CMF_3));
    MEMCPY_DN(MALMMSGDEF->CMF_4, MALMMSGDEF_N->CMF_4, sizeof(MALMMSGDEF->CMF_4));
    MEMCPY_DN(MALMMSGDEF->CMF_5, MALMMSGDEF_N->CMF_5, sizeof(MALMMSGDEF->CMF_5));
    MEMCPY_DN(MALMMSGDEF->CMF_6, MALMMSGDEF_N->CMF_6, sizeof(MALMMSGDEF->CMF_6));
    MEMCPY_DN(MALMMSGDEF->CMF_7, MALMMSGDEF_N->CMF_7, sizeof(MALMMSGDEF->CMF_7));
    MEMCPY_DN(MALMMSGDEF->CMF_8, MALMMSGDEF_N->CMF_8, sizeof(MALMMSGDEF->CMF_8));
    MEMCPY_DN(MALMMSGDEF->CMF_9, MALMMSGDEF_N->CMF_9, sizeof(MALMMSGDEF->CMF_9));
    MEMCPY_DN(MALMMSGDEF->CMF_10, MALMMSGDEF_N->CMF_10, sizeof(MALMMSGDEF->CMF_10));
    MEMCPY_DN(MALMMSGDEF->CMF_11, MALMMSGDEF_N->CMF_11, sizeof(MALMMSGDEF->CMF_11));
    MEMCPY_DN(MALMMSGDEF->CMF_12, MALMMSGDEF_N->CMF_12, sizeof(MALMMSGDEF->CMF_12));
    MEMCPY_DN(MALMMSGDEF->CMF_13, MALMMSGDEF_N->CMF_13, sizeof(MALMMSGDEF->CMF_13));
    MEMCPY_DN(MALMMSGDEF->CMF_14, MALMMSGDEF_N->CMF_14, sizeof(MALMMSGDEF->CMF_14));
    MEMCPY_DN(MALMMSGDEF->CMF_15, MALMMSGDEF_N->CMF_15, sizeof(MALMMSGDEF->CMF_15));
    MEMCPY_DN(MALMMSGDEF->CMF_16, MALMMSGDEF_N->CMF_16, sizeof(MALMMSGDEF->CMF_16));
    MEMCPY_DN(MALMMSGDEF->CMF_17, MALMMSGDEF_N->CMF_17, sizeof(MALMMSGDEF->CMF_17));
    MEMCPY_DN(MALMMSGDEF->CMF_18, MALMMSGDEF_N->CMF_18, sizeof(MALMMSGDEF->CMF_18));
    MEMCPY_DN(MALMMSGDEF->CMF_19, MALMMSGDEF_N->CMF_19, sizeof(MALMMSGDEF->CMF_19));
    MEMCPY_DN(MALMMSGDEF->CMF_20, MALMMSGDEF_N->CMF_20, sizeof(MALMMSGDEF->CMF_20));
    MEMCPY_DN(MALMMSGDEF->LOT_COMMENT, MALMMSGDEF_N->LOT_COMMENT, sizeof(MALMMSGDEF->LOT_COMMENT));
    MEMCPY_DN(MALMMSGDEF->ALARM_SUBJECT, MALMMSGDEF_N->ALARM_SUBJECT, sizeof(MALMMSGDEF->ALARM_SUBJECT));
    MEMCPY_DN(MALMMSGDEF->ALARM_MSG_1, MALMMSGDEF_N->ALARM_MSG_1, sizeof(MALMMSGDEF->ALARM_MSG_1));
    MEMCPY_DN(MALMMSGDEF->ALARM_MSG_2, MALMMSGDEF_N->ALARM_MSG_2, sizeof(MALMMSGDEF->ALARM_MSG_2));
    MEMCPY_DN(MALMMSGDEF->ALARM_MSG_3, MALMMSGDEF_N->ALARM_MSG_3, sizeof(MALMMSGDEF->ALARM_MSG_3));
    MEMCPY_DN(MALMMSGDEF->EVENT_ID, MALMMSGDEF_N->EVENT_ID, sizeof(MALMMSGDEF->EVENT_ID));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_1, MALMMSGDEF_N->CHG_STS_1, sizeof(MALMMSGDEF->CHG_STS_1));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_2, MALMMSGDEF_N->CHG_STS_2, sizeof(MALMMSGDEF->CHG_STS_2));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_3, MALMMSGDEF_N->CHG_STS_3, sizeof(MALMMSGDEF->CHG_STS_3));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_4, MALMMSGDEF_N->CHG_STS_4, sizeof(MALMMSGDEF->CHG_STS_4));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_5, MALMMSGDEF_N->CHG_STS_5, sizeof(MALMMSGDEF->CHG_STS_5));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_6, MALMMSGDEF_N->CHG_STS_6, sizeof(MALMMSGDEF->CHG_STS_6));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_7, MALMMSGDEF_N->CHG_STS_7, sizeof(MALMMSGDEF->CHG_STS_7));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_8, MALMMSGDEF_N->CHG_STS_8, sizeof(MALMMSGDEF->CHG_STS_8));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_9, MALMMSGDEF_N->CHG_STS_9, sizeof(MALMMSGDEF->CHG_STS_9));
    MEMCPY_DN(MALMMSGDEF->CHG_STS_10, MALMMSGDEF_N->CHG_STS_10, sizeof(MALMMSGDEF->CHG_STS_10));
    MEMCPY_DN(MALMMSGDEF->RES_COMMENT, MALMMSGDEF_N->RES_COMMENT, sizeof(MALMMSGDEF->RES_COMMENT));
    MEMCPY_DN(MALMMSGDEF->CLEAR_EVENT_ID, MALMMSGDEF_N->CLEAR_EVENT_ID, sizeof(MALMMSGDEF->CLEAR_EVENT_ID));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_1, MALMMSGDEF_N->CLEAR_CHG_STS_1, sizeof(MALMMSGDEF->CLEAR_CHG_STS_1));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_2, MALMMSGDEF_N->CLEAR_CHG_STS_2, sizeof(MALMMSGDEF->CLEAR_CHG_STS_2));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_3, MALMMSGDEF_N->CLEAR_CHG_STS_3, sizeof(MALMMSGDEF->CLEAR_CHG_STS_3));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_4, MALMMSGDEF_N->CLEAR_CHG_STS_4, sizeof(MALMMSGDEF->CLEAR_CHG_STS_4));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_5, MALMMSGDEF_N->CLEAR_CHG_STS_5, sizeof(MALMMSGDEF->CLEAR_CHG_STS_5));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_6, MALMMSGDEF_N->CLEAR_CHG_STS_6, sizeof(MALMMSGDEF->CLEAR_CHG_STS_6));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_7, MALMMSGDEF_N->CLEAR_CHG_STS_7, sizeof(MALMMSGDEF->CLEAR_CHG_STS_7));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_8, MALMMSGDEF_N->CLEAR_CHG_STS_8, sizeof(MALMMSGDEF->CLEAR_CHG_STS_8));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_9, MALMMSGDEF_N->CLEAR_CHG_STS_9, sizeof(MALMMSGDEF->CLEAR_CHG_STS_9));
    MEMCPY_DN(MALMMSGDEF->CLEAR_CHG_STS_10, MALMMSGDEF_N->CLEAR_CHG_STS_10, sizeof(MALMMSGDEF->CLEAR_CHG_STS_10));
    MEMCPY_DN(MALMMSGDEF->CLEAR_RES_COMMENT, MALMMSGDEF_N->CLEAR_RES_COMMENT, sizeof(MALMMSGDEF->CLEAR_RES_COMMENT));
    MEMCPY_DN(MALMMSGDEF->CREATE_USER_ID, MALMMSGDEF_N->CREATE_USER_ID, sizeof(MALMMSGDEF->CREATE_USER_ID));
    MEMCPY_DN(MALMMSGDEF->CREATE_TIME, MALMMSGDEF_N->CREATE_TIME, sizeof(MALMMSGDEF->CREATE_TIME));
    MEMCPY_DN(MALMMSGDEF->UPDATE_USER_ID, MALMMSGDEF_N->UPDATE_USER_ID, sizeof(MALMMSGDEF->UPDATE_USER_ID));
    MEMCPY_DN(MALMMSGDEF->UPDATE_TIME, MALMMSGDEF_N->UPDATE_TIME, sizeof(MALMMSGDEF->UPDATE_TIME));
    MEMCPY_DN(MALMMSGDEF->ALARM_COMMENT_1, MALMMSGDEF_N->ALARM_COMMENT_1, sizeof(MALMMSGDEF->ALARM_COMMENT_1));
    MEMCPY_DN(MALMMSGDEF->ALARM_COMMENT_2, MALMMSGDEF_N->ALARM_COMMENT_2, sizeof(MALMMSGDEF->ALARM_COMMENT_2));
    MEMCPY_DN(MALMMSGDEF->ALARM_COMMENT_3, MALMMSGDEF_N->ALARM_COMMENT_3, sizeof(MALMMSGDEF->ALARM_COMMENT_3));
    MEMCPY_DN(MALMMSGDEF->ALARM_COMMENT_4, MALMMSGDEF_N->ALARM_COMMENT_4, sizeof(MALMMSGDEF->ALARM_COMMENT_4));
    MEMCPY_DN(MALMMSGDEF->ALARM_COMMENT_5, MALMMSGDEF_N->ALARM_COMMENT_5, sizeof(MALMMSGDEF->ALARM_COMMENT_5));
    MEMCPY_DN(MALMMSGDEF->PDF_FILE_NAME, MALMMSGDEF_N->PDF_FILE_NAME, sizeof(MALMMSGDEF->PDF_FILE_NAME));
    MEMCPY_DN(MALMMSGDEF->IMAGE_FILE_NAME, MALMMSGDEF_N->IMAGE_FILE_NAME, sizeof(MALMMSGDEF->IMAGE_FILE_NAME));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_1, MALMMSGDEF_N->ALARM_CMF_1, sizeof(MALMMSGDEF->ALARM_CMF_1));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_2, MALMMSGDEF_N->ALARM_CMF_2, sizeof(MALMMSGDEF->ALARM_CMF_2));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_3, MALMMSGDEF_N->ALARM_CMF_3, sizeof(MALMMSGDEF->ALARM_CMF_3));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_4, MALMMSGDEF_N->ALARM_CMF_4, sizeof(MALMMSGDEF->ALARM_CMF_4));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_5, MALMMSGDEF_N->ALARM_CMF_5, sizeof(MALMMSGDEF->ALARM_CMF_5));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_6, MALMMSGDEF_N->ALARM_CMF_6, sizeof(MALMMSGDEF->ALARM_CMF_6));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_7, MALMMSGDEF_N->ALARM_CMF_7, sizeof(MALMMSGDEF->ALARM_CMF_7));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_8, MALMMSGDEF_N->ALARM_CMF_8, sizeof(MALMMSGDEF->ALARM_CMF_8));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_9, MALMMSGDEF_N->ALARM_CMF_9, sizeof(MALMMSGDEF->ALARM_CMF_9));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_10, MALMMSGDEF_N->ALARM_CMF_10, sizeof(MALMMSGDEF->ALARM_CMF_10));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_11, MALMMSGDEF_N->ALARM_CMF_11, sizeof(MALMMSGDEF->ALARM_CMF_11));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_12, MALMMSGDEF_N->ALARM_CMF_12, sizeof(MALMMSGDEF->ALARM_CMF_12));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_13, MALMMSGDEF_N->ALARM_CMF_13, sizeof(MALMMSGDEF->ALARM_CMF_13));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_14, MALMMSGDEF_N->ALARM_CMF_14, sizeof(MALMMSGDEF->ALARM_CMF_14));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_15, MALMMSGDEF_N->ALARM_CMF_15, sizeof(MALMMSGDEF->ALARM_CMF_15));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_16, MALMMSGDEF_N->ALARM_CMF_16, sizeof(MALMMSGDEF->ALARM_CMF_16));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_17, MALMMSGDEF_N->ALARM_CMF_17, sizeof(MALMMSGDEF->ALARM_CMF_17));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_18, MALMMSGDEF_N->ALARM_CMF_18, sizeof(MALMMSGDEF->ALARM_CMF_18));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_19, MALMMSGDEF_N->ALARM_CMF_19, sizeof(MALMMSGDEF->ALARM_CMF_19));
    MEMCPY_DN(MALMMSGDEF->ALARM_CMF_20, MALMMSGDEF_N->ALARM_CMF_20, sizeof(MALMMSGDEF->ALARM_CMF_20));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_1, MALMMSGDEF_N->ALARM_GRP_1, sizeof(MALMMSGDEF->ALARM_GRP_1));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_2, MALMMSGDEF_N->ALARM_GRP_2, sizeof(MALMMSGDEF->ALARM_GRP_2));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_3, MALMMSGDEF_N->ALARM_GRP_3, sizeof(MALMMSGDEF->ALARM_GRP_3));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_4, MALMMSGDEF_N->ALARM_GRP_4, sizeof(MALMMSGDEF->ALARM_GRP_4));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_5, MALMMSGDEF_N->ALARM_GRP_5, sizeof(MALMMSGDEF->ALARM_GRP_5));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_6, MALMMSGDEF_N->ALARM_GRP_6, sizeof(MALMMSGDEF->ALARM_GRP_6));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_7, MALMMSGDEF_N->ALARM_GRP_7, sizeof(MALMMSGDEF->ALARM_GRP_7));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_8, MALMMSGDEF_N->ALARM_GRP_8, sizeof(MALMMSGDEF->ALARM_GRP_8));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_9, MALMMSGDEF_N->ALARM_GRP_9, sizeof(MALMMSGDEF->ALARM_GRP_9));
    MEMCPY_DN(MALMMSGDEF->ALARM_GRP_10, MALMMSGDEF_N->ALARM_GRP_10, sizeof(MALMMSGDEF->ALARM_GRP_10));
}


