
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
    "DBC_mbaschklst.pc"
};


static unsigned int sqlctx = 9090731;


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
            void  *sqhstv[81];
   unsigned int   sqhstl[81];
            int   sqhsts[81];
            void  *sqindv[81];
            int   sqinds[81];
   unsigned int   sqharm[81];
   unsigned int   *sqharc[81];
   unsigned short  sqadto[81];
   unsigned short  sqtdso[81];
} sqlstm = {13,81};

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
"FACTORY asc ,CHKLIST_ID asc         \
    ";

 static const char *sq0008 = 
"1 and FACTORY=:b0) and CHKLIST_ID>=:\
b1) order by CHKLIST_ID asc             ";

 static const char *sq0009 = 
"=1 and FACTORY=:b0) and CHKLIST_TYPE\
=:b1) and CHKLIST_ID>=:b2) order by CHKLIST_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1442,0,4,47,0,0,81,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
344,0,0,2,1454,0,4,245,0,0,81,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
683,0,0,3,81,0,4,446,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
710,0,0,4,63,0,2,482,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
733,0,0,5,1330,0,3,511,0,0,79,79,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1064,0,0,6,1331,0,5,693,0,0,79,79,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1395,0,0,7,1064,0,9,886,0,0,0,0,0,1,0,
1410,0,0,8,1100,0,9,976,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1433,0,0,9,1123,0,9,1067,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1460,0,0,7,0,0,13,1094,0,0,79,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1791,0,0,8,0,0,13,1177,0,0,79,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2122,0,0,9,0,0,13,1260,0,0,79,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2453,0,0,7,0,0,15,1368,0,0,0,0,0,1,0,
2468,0,0,8,0,0,15,1372,0,0,0,0,0,1,0,
2483,0,0,9,0,0,15,1376,0,0,0,0,0,1,0,
2498,0,0,10,7513,0,4,1638,0,0,5,4,0,1,0,1,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,
2533,0,0,11,3429,0,4,1843,0,0,4,3,0,1,0,1,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
2564,0,0,12,122,0,4,1946,0,0,4,3,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2595,0,0,13,122,0,4,1957,0,0,4,3,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
};


/*********************************************************************
**
**    File Name   : DBC_mbaschklst.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/02/12 16:23:05
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
void DBC_add_null_mbaschklst(struct MBASCHKLST_N_TAG *MBASCHKLST_N, struct MBASCHKLST_TAG *MBASCHKLST);
void DBC_del_null_mbaschklst(struct MBASCHKLST_N_TAG *MBASCHKLST_N, struct MBASCHKLST_TAG *MBASCHKLST);

void DBC_add_null_mbaschklst_join(struct MBASCHKLST_JOIN_N_TAG *MBASCHKLST_JOIN_N, struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN);
void DBC_del_null_mbaschklst_join(struct MBASCHKLST_JOIN_N_TAG *MBASCHKLST_JOIN_N, struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN);

/* SQL SELECT Function */
void DBC_select_mbaschklst(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
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
                    CHKLIST_ID,
                    CHKLIST_DESC,
                    CHKLIST_TYPE,
                    LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1,
                    CHKLIST_GRP_2,
                    CHKLIST_GRP_3,
                    CHKLIST_GRP_4,
                    CHKLIST_GRP_5,
                    CHKLIST_GRP_6,
                    CHKLIST_GRP_7,
                    CHKLIST_GRP_8,
                    CHKLIST_GRP_9,
                    CHKLIST_GRP_10,
                    CHKLIST_CMF_1,
                    CHKLIST_CMF_2,
                    CHKLIST_CMF_3,
                    CHKLIST_CMF_4,
                    CHKLIST_CMF_5,
                    CHKLIST_CMF_6,
                    CHKLIST_CMF_7,
                    CHKLIST_CMF_8,
                    CHKLIST_CMF_9,
                    CHKLIST_CMF_10,
                    KEY_1_PMT,
                    KEY_2_PMT,
                    KEY_3_PMT,
                    KEY_4_PMT,
                    KEY_5_PMT,
                    KEY_6_PMT,
                    KEY_7_PMT,
                    KEY_8_PMT,
                    KEY_9_PMT,
                    KEY_10_PMT,
                    KEY_1_REQ,
                    KEY_2_REQ,
                    KEY_3_REQ,
                    KEY_4_REQ,
                    KEY_5_REQ,
                    KEY_6_REQ,
                    KEY_7_REQ,
                    KEY_8_REQ,
                    KEY_9_REQ,
                    KEY_10_REQ,
                    KEY_1_FMT,
                    KEY_2_FMT,
                    KEY_3_FMT,
                    KEY_4_FMT,
                    KEY_5_FMT,
                    KEY_6_FMT,
                    KEY_7_FMT,
                    KEY_8_FMT,
                    KEY_9_FMT,
                    KEY_10_FMT,
                    KEY_1_TBL,
                    KEY_2_TBL,
                    KEY_3_TBL,
                    KEY_4_TBL,
                    KEY_5_TBL,
                    KEY_6_TBL,
                    KEY_7_TBL,
                    KEY_8_TBL,
                    KEY_9_TBL,
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
                INTO 
                    :MBASCHKLST_N.CREATE_USER_ID,
                    :MBASCHKLST_N.CREATE_TIME,
                    :MBASCHKLST_N.UPDATE_USER_ID,
                    :MBASCHKLST_N.UPDATE_TIME,
                    :MBASCHKLST_N.FACTORY,
                    :MBASCHKLST_N.CHKLIST_ID,
                    :MBASCHKLST_N.CHKLIST_DESC,
                    :MBASCHKLST_N.CHKLIST_TYPE,
                    :MBASCHKLST_N.LOT_OR_RES_FLAG,
                    :MBASCHKLST_N.CHKLIST_GRP_1,
                    :MBASCHKLST_N.CHKLIST_GRP_2,
                    :MBASCHKLST_N.CHKLIST_GRP_3,
                    :MBASCHKLST_N.CHKLIST_GRP_4,
                    :MBASCHKLST_N.CHKLIST_GRP_5,
                    :MBASCHKLST_N.CHKLIST_GRP_6,
                    :MBASCHKLST_N.CHKLIST_GRP_7,
                    :MBASCHKLST_N.CHKLIST_GRP_8,
                    :MBASCHKLST_N.CHKLIST_GRP_9,
                    :MBASCHKLST_N.CHKLIST_GRP_10,
                    :MBASCHKLST_N.CHKLIST_CMF_1,
                    :MBASCHKLST_N.CHKLIST_CMF_2,
                    :MBASCHKLST_N.CHKLIST_CMF_3,
                    :MBASCHKLST_N.CHKLIST_CMF_4,
                    :MBASCHKLST_N.CHKLIST_CMF_5,
                    :MBASCHKLST_N.CHKLIST_CMF_6,
                    :MBASCHKLST_N.CHKLIST_CMF_7,
                    :MBASCHKLST_N.CHKLIST_CMF_8,
                    :MBASCHKLST_N.CHKLIST_CMF_9,
                    :MBASCHKLST_N.CHKLIST_CMF_10,
                    :MBASCHKLST_N.KEY_1_PMT,
                    :MBASCHKLST_N.KEY_2_PMT,
                    :MBASCHKLST_N.KEY_3_PMT,
                    :MBASCHKLST_N.KEY_4_PMT,
                    :MBASCHKLST_N.KEY_5_PMT,
                    :MBASCHKLST_N.KEY_6_PMT,
                    :MBASCHKLST_N.KEY_7_PMT,
                    :MBASCHKLST_N.KEY_8_PMT,
                    :MBASCHKLST_N.KEY_9_PMT,
                    :MBASCHKLST_N.KEY_10_PMT,
                    :MBASCHKLST_N.KEY_1_REQ,
                    :MBASCHKLST_N.KEY_2_REQ,
                    :MBASCHKLST_N.KEY_3_REQ,
                    :MBASCHKLST_N.KEY_4_REQ,
                    :MBASCHKLST_N.KEY_5_REQ,
                    :MBASCHKLST_N.KEY_6_REQ,
                    :MBASCHKLST_N.KEY_7_REQ,
                    :MBASCHKLST_N.KEY_8_REQ,
                    :MBASCHKLST_N.KEY_9_REQ,
                    :MBASCHKLST_N.KEY_10_REQ,
                    :MBASCHKLST_N.KEY_1_FMT,
                    :MBASCHKLST_N.KEY_2_FMT,
                    :MBASCHKLST_N.KEY_3_FMT,
                    :MBASCHKLST_N.KEY_4_FMT,
                    :MBASCHKLST_N.KEY_5_FMT,
                    :MBASCHKLST_N.KEY_6_FMT,
                    :MBASCHKLST_N.KEY_7_FMT,
                    :MBASCHKLST_N.KEY_8_FMT,
                    :MBASCHKLST_N.KEY_9_FMT,
                    :MBASCHKLST_N.KEY_10_FMT,
                    :MBASCHKLST_N.KEY_1_TBL,
                    :MBASCHKLST_N.KEY_2_TBL,
                    :MBASCHKLST_N.KEY_3_TBL,
                    :MBASCHKLST_N.KEY_4_TBL,
                    :MBASCHKLST_N.KEY_5_TBL,
                    :MBASCHKLST_N.KEY_6_TBL,
                    :MBASCHKLST_N.KEY_7_TBL,
                    :MBASCHKLST_N.KEY_8_TBL,
                    :MBASCHKLST_N.KEY_9_TBL,
                    :MBASCHKLST_N.KEY_10_TBL,
                    :MBASCHKLST_N.KEY_1_ITEM,
                    :MBASCHKLST_N.KEY_2_ITEM,
                    :MBASCHKLST_N.KEY_3_ITEM,
                    :MBASCHKLST_N.KEY_4_ITEM,
                    :MBASCHKLST_N.KEY_5_ITEM,
                    :MBASCHKLST_N.KEY_6_ITEM,
                    :MBASCHKLST_N.KEY_7_ITEM,
                    :MBASCHKLST_N.KEY_8_ITEM,
                    :MBASCHKLST_N.KEY_9_ITEM,
                    :MBASCHKLST_N.KEY_10_ITEM
                FROM MBASCHKLST
                WHERE FACTORY = :MBASCHKLST_N.FACTORY
                    AND CHKLIST_ID = :MBASCHKLST_N.CHKLIST_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,CHKLIST_ID ,CHKLIST_DESC ,CHKLIST_TYPE ,LOT_OR_RES_FLAG ,CHKLIS\
T_GRP_1 ,CHKLIST_GRP_2 ,CHKLIST_GRP_3 ,CHKLIST_GRP_4 ,CHKLIST_GRP_5 ,CHKLIST\
_GRP_6 ,CHKLIST_GRP_7 ,CHKLIST_GRP_8 ,CHKLIST_GRP_9 ,CHKLIST_GRP_10 ,CHKLIST\
_CMF_1 ,CHKLIST_CMF_2 ,CHKLIST_CMF_3 ,CHKLIST_CMF_4 ,CHKLIST_CMF_5 ,CHKLIST_\
CMF_6 ,CHKLIST_CMF_7 ,CHKLIST_CMF_8 ,CHKLIST_CMF_9 ,CHKLIST_CMF_10 ,KEY_1_PM\
T ,KEY_2_PMT ,KEY_3_PMT ,KEY_4_PMT ,KEY_5_PMT ,KEY_6_PMT ,KEY_7_PMT ,KEY_8_P\
MT ,KEY_9_PMT ,KEY_10_PMT ,KEY_1_REQ ,KEY_2_REQ ,KEY_3_REQ ,KEY_4_REQ ,KEY_5\
_REQ ,KEY_6_REQ ,KEY_7_REQ ,KEY_8_REQ ,KEY_9_REQ ,KEY_10_REQ ,KEY_1_FMT ,KEY\
_2_FMT ,KEY_3_FMT ,KEY_4_FMT ,KEY_5_FMT ,KEY_6_FMT ,KEY_7_FMT ,KEY_8_FMT ,KE\
Y_9_FMT ,KEY_10_FMT ,KEY_1_TBL ,KEY_2_TBL ,KEY_3_TBL ,KEY_4_TBL ,KEY_5_TBL ,\
KEY_6_TBL ,KEY_7_TBL ,KEY_8_TBL ,KEY_9_TBL ,KEY_10_TBL ,KEY_1_ITEM ,KEY_2_IT\
EM ,KEY_3_ITEM ,KEY_4_ITEM ,KEY_5_ITEM ,KEY_6_ITEM ,KEY_7_ITEM ,KEY_8_ITEM ,\
KEY_9_ITEM ,KEY_10_ITEM into :b0,:b1,:b2,:b3,:b4,:b");
            sqlstm.stmt = "5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,\
:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b\
31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:\
b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b7\
7,:b78  from MBASCHKLST where (FACTORY=:b4 and CHKLIST_ID=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[77] = (unsigned int  )101;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[78] = (unsigned int  )101;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
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
        DBC_del_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    }

    DB_stop_query_timer("DBC_select_mbaschklst", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mbaschklst_for_update(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
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
                    CHKLIST_ID,
                    CHKLIST_DESC,
                    CHKLIST_TYPE,
                    LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1,
                    CHKLIST_GRP_2,
                    CHKLIST_GRP_3,
                    CHKLIST_GRP_4,
                    CHKLIST_GRP_5,
                    CHKLIST_GRP_6,
                    CHKLIST_GRP_7,
                    CHKLIST_GRP_8,
                    CHKLIST_GRP_9,
                    CHKLIST_GRP_10,
                    CHKLIST_CMF_1,
                    CHKLIST_CMF_2,
                    CHKLIST_CMF_3,
                    CHKLIST_CMF_4,
                    CHKLIST_CMF_5,
                    CHKLIST_CMF_6,
                    CHKLIST_CMF_7,
                    CHKLIST_CMF_8,
                    CHKLIST_CMF_9,
                    CHKLIST_CMF_10,
                    KEY_1_PMT,
                    KEY_2_PMT,
                    KEY_3_PMT,
                    KEY_4_PMT,
                    KEY_5_PMT,
                    KEY_6_PMT,
                    KEY_7_PMT,
                    KEY_8_PMT,
                    KEY_9_PMT,
                    KEY_10_PMT,
                    KEY_1_REQ,
                    KEY_2_REQ,
                    KEY_3_REQ,
                    KEY_4_REQ,
                    KEY_5_REQ,
                    KEY_6_REQ,
                    KEY_7_REQ,
                    KEY_8_REQ,
                    KEY_9_REQ,
                    KEY_10_REQ,
                    KEY_1_FMT,
                    KEY_2_FMT,
                    KEY_3_FMT,
                    KEY_4_FMT,
                    KEY_5_FMT,
                    KEY_6_FMT,
                    KEY_7_FMT,
                    KEY_8_FMT,
                    KEY_9_FMT,
                    KEY_10_FMT,
                    KEY_1_TBL,
                    KEY_2_TBL,
                    KEY_3_TBL,
                    KEY_4_TBL,
                    KEY_5_TBL,
                    KEY_6_TBL,
                    KEY_7_TBL,
                    KEY_8_TBL,
                    KEY_9_TBL,
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
                INTO 
                    :MBASCHKLST_N.CREATE_USER_ID,
                    :MBASCHKLST_N.CREATE_TIME,
                    :MBASCHKLST_N.UPDATE_USER_ID,
                    :MBASCHKLST_N.UPDATE_TIME,
                    :MBASCHKLST_N.FACTORY,
                    :MBASCHKLST_N.CHKLIST_ID,
                    :MBASCHKLST_N.CHKLIST_DESC,
                    :MBASCHKLST_N.CHKLIST_TYPE,
                    :MBASCHKLST_N.LOT_OR_RES_FLAG,
                    :MBASCHKLST_N.CHKLIST_GRP_1,
                    :MBASCHKLST_N.CHKLIST_GRP_2,
                    :MBASCHKLST_N.CHKLIST_GRP_3,
                    :MBASCHKLST_N.CHKLIST_GRP_4,
                    :MBASCHKLST_N.CHKLIST_GRP_5,
                    :MBASCHKLST_N.CHKLIST_GRP_6,
                    :MBASCHKLST_N.CHKLIST_GRP_7,
                    :MBASCHKLST_N.CHKLIST_GRP_8,
                    :MBASCHKLST_N.CHKLIST_GRP_9,
                    :MBASCHKLST_N.CHKLIST_GRP_10,
                    :MBASCHKLST_N.CHKLIST_CMF_1,
                    :MBASCHKLST_N.CHKLIST_CMF_2,
                    :MBASCHKLST_N.CHKLIST_CMF_3,
                    :MBASCHKLST_N.CHKLIST_CMF_4,
                    :MBASCHKLST_N.CHKLIST_CMF_5,
                    :MBASCHKLST_N.CHKLIST_CMF_6,
                    :MBASCHKLST_N.CHKLIST_CMF_7,
                    :MBASCHKLST_N.CHKLIST_CMF_8,
                    :MBASCHKLST_N.CHKLIST_CMF_9,
                    :MBASCHKLST_N.CHKLIST_CMF_10,
                    :MBASCHKLST_N.KEY_1_PMT,
                    :MBASCHKLST_N.KEY_2_PMT,
                    :MBASCHKLST_N.KEY_3_PMT,
                    :MBASCHKLST_N.KEY_4_PMT,
                    :MBASCHKLST_N.KEY_5_PMT,
                    :MBASCHKLST_N.KEY_6_PMT,
                    :MBASCHKLST_N.KEY_7_PMT,
                    :MBASCHKLST_N.KEY_8_PMT,
                    :MBASCHKLST_N.KEY_9_PMT,
                    :MBASCHKLST_N.KEY_10_PMT,
                    :MBASCHKLST_N.KEY_1_REQ,
                    :MBASCHKLST_N.KEY_2_REQ,
                    :MBASCHKLST_N.KEY_3_REQ,
                    :MBASCHKLST_N.KEY_4_REQ,
                    :MBASCHKLST_N.KEY_5_REQ,
                    :MBASCHKLST_N.KEY_6_REQ,
                    :MBASCHKLST_N.KEY_7_REQ,
                    :MBASCHKLST_N.KEY_8_REQ,
                    :MBASCHKLST_N.KEY_9_REQ,
                    :MBASCHKLST_N.KEY_10_REQ,
                    :MBASCHKLST_N.KEY_1_FMT,
                    :MBASCHKLST_N.KEY_2_FMT,
                    :MBASCHKLST_N.KEY_3_FMT,
                    :MBASCHKLST_N.KEY_4_FMT,
                    :MBASCHKLST_N.KEY_5_FMT,
                    :MBASCHKLST_N.KEY_6_FMT,
                    :MBASCHKLST_N.KEY_7_FMT,
                    :MBASCHKLST_N.KEY_8_FMT,
                    :MBASCHKLST_N.KEY_9_FMT,
                    :MBASCHKLST_N.KEY_10_FMT,
                    :MBASCHKLST_N.KEY_1_TBL,
                    :MBASCHKLST_N.KEY_2_TBL,
                    :MBASCHKLST_N.KEY_3_TBL,
                    :MBASCHKLST_N.KEY_4_TBL,
                    :MBASCHKLST_N.KEY_5_TBL,
                    :MBASCHKLST_N.KEY_6_TBL,
                    :MBASCHKLST_N.KEY_7_TBL,
                    :MBASCHKLST_N.KEY_8_TBL,
                    :MBASCHKLST_N.KEY_9_TBL,
                    :MBASCHKLST_N.KEY_10_TBL,
                    :MBASCHKLST_N.KEY_1_ITEM,
                    :MBASCHKLST_N.KEY_2_ITEM,
                    :MBASCHKLST_N.KEY_3_ITEM,
                    :MBASCHKLST_N.KEY_4_ITEM,
                    :MBASCHKLST_N.KEY_5_ITEM,
                    :MBASCHKLST_N.KEY_6_ITEM,
                    :MBASCHKLST_N.KEY_7_ITEM,
                    :MBASCHKLST_N.KEY_8_ITEM,
                    :MBASCHKLST_N.KEY_9_ITEM,
                    :MBASCHKLST_N.KEY_10_ITEM
                FROM MBASCHKLST
                WHERE FACTORY = :MBASCHKLST_N.FACTORY
                    AND CHKLIST_ID = :MBASCHKLST_N.CHKLIST_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,CHKLIST_ID ,CHKLIST_DESC ,CHKLIST_TYPE ,LOT_OR_RES_FLAG ,CHKLIS\
T_GRP_1 ,CHKLIST_GRP_2 ,CHKLIST_GRP_3 ,CHKLIST_GRP_4 ,CHKLIST_GRP_5 ,CHKLIST\
_GRP_6 ,CHKLIST_GRP_7 ,CHKLIST_GRP_8 ,CHKLIST_GRP_9 ,CHKLIST_GRP_10 ,CHKLIST\
_CMF_1 ,CHKLIST_CMF_2 ,CHKLIST_CMF_3 ,CHKLIST_CMF_4 ,CHKLIST_CMF_5 ,CHKLIST_\
CMF_6 ,CHKLIST_CMF_7 ,CHKLIST_CMF_8 ,CHKLIST_CMF_9 ,CHKLIST_CMF_10 ,KEY_1_PM\
T ,KEY_2_PMT ,KEY_3_PMT ,KEY_4_PMT ,KEY_5_PMT ,KEY_6_PMT ,KEY_7_PMT ,KEY_8_P\
MT ,KEY_9_PMT ,KEY_10_PMT ,KEY_1_REQ ,KEY_2_REQ ,KEY_3_REQ ,KEY_4_REQ ,KEY_5\
_REQ ,KEY_6_REQ ,KEY_7_REQ ,KEY_8_REQ ,KEY_9_REQ ,KEY_10_REQ ,KEY_1_FMT ,KEY\
_2_FMT ,KEY_3_FMT ,KEY_4_FMT ,KEY_5_FMT ,KEY_6_FMT ,KEY_7_FMT ,KEY_8_FMT ,KE\
Y_9_FMT ,KEY_10_FMT ,KEY_1_TBL ,KEY_2_TBL ,KEY_3_TBL ,KEY_4_TBL ,KEY_5_TBL ,\
KEY_6_TBL ,KEY_7_TBL ,KEY_8_TBL ,KEY_9_TBL ,KEY_10_TBL ,KEY_1_ITEM ,KEY_2_IT\
EM ,KEY_3_ITEM ,KEY_4_ITEM ,KEY_5_ITEM ,KEY_6_ITEM ,KEY_7_ITEM ,KEY_8_ITEM ,\
KEY_9_ITEM ,KEY_10_ITEM into :b0,:b1,:b2,:b3,:b4,:b");
            sqlstm.stmt = "5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,\
:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b\
31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:\
b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b7\
7,:b78  from MBASCHKLST where (FACTORY=:b4 and CHKLIST_ID=:b5) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )344;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[77] = (unsigned int  )101;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[78] = (unsigned int  )101;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
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
        DBC_del_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    }

    DB_stop_query_timer("DBC_select_mbaschklst_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mbaschklst_scalar(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MBASCHKLST
                WHERE FACTORY = :MBASCHKLST_N.FACTORY
                    AND CHKLIST_ID = :MBASCHKLST_N.CHKLIST_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MBASCHKLST where\
 (FACTORY=:b1 and CHKLIST_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )683;
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
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
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

    DB_stop_query_timer("DBC_select_mbaschklst_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mbaschklst(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MBASCHKLST
                WHERE FACTORY = :MBASCHKLST_N.FACTORY
                    AND CHKLIST_ID = :MBASCHKLST_N.CHKLIST_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MBASCHKLST  where (FACTORY=:b0 and \
CHKLIST_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )710;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
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

    DB_stop_query_timer("DBC_delete_mbaschklst", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mbaschklst(struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MBASCHKLST( 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    FACTORY, 
                    CHKLIST_ID, 
                    CHKLIST_DESC, 
                    CHKLIST_TYPE, 
                    LOT_OR_RES_FLAG, 
                    CHKLIST_GRP_1, 
                    CHKLIST_GRP_2, 
                    CHKLIST_GRP_3, 
                    CHKLIST_GRP_4, 
                    CHKLIST_GRP_5, 
                    CHKLIST_GRP_6, 
                    CHKLIST_GRP_7, 
                    CHKLIST_GRP_8, 
                    CHKLIST_GRP_9, 
                    CHKLIST_GRP_10, 
                    CHKLIST_CMF_1, 
                    CHKLIST_CMF_2, 
                    CHKLIST_CMF_3, 
                    CHKLIST_CMF_4, 
                    CHKLIST_CMF_5, 
                    CHKLIST_CMF_6, 
                    CHKLIST_CMF_7, 
                    CHKLIST_CMF_8, 
                    CHKLIST_CMF_9, 
                    CHKLIST_CMF_10, 
                    KEY_1_PMT, 
                    KEY_2_PMT, 
                    KEY_3_PMT, 
                    KEY_4_PMT, 
                    KEY_5_PMT, 
                    KEY_6_PMT, 
                    KEY_7_PMT, 
                    KEY_8_PMT, 
                    KEY_9_PMT, 
                    KEY_10_PMT, 
                    KEY_1_REQ, 
                    KEY_2_REQ, 
                    KEY_3_REQ, 
                    KEY_4_REQ, 
                    KEY_5_REQ, 
                    KEY_6_REQ, 
                    KEY_7_REQ, 
                    KEY_8_REQ, 
                    KEY_9_REQ, 
                    KEY_10_REQ, 
                    KEY_1_FMT, 
                    KEY_2_FMT, 
                    KEY_3_FMT, 
                    KEY_4_FMT, 
                    KEY_5_FMT, 
                    KEY_6_FMT, 
                    KEY_7_FMT, 
                    KEY_8_FMT, 
                    KEY_9_FMT, 
                    KEY_10_FMT, 
                    KEY_1_TBL, 
                    KEY_2_TBL, 
                    KEY_3_TBL, 
                    KEY_4_TBL, 
                    KEY_5_TBL, 
                    KEY_6_TBL, 
                    KEY_7_TBL, 
                    KEY_8_TBL, 
                    KEY_9_TBL, 
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
         ) 
        VALUES (
                    :MBASCHKLST_N.CREATE_USER_ID,
                    :MBASCHKLST_N.CREATE_TIME,
                    :MBASCHKLST_N.UPDATE_USER_ID,
                    :MBASCHKLST_N.UPDATE_TIME,
                    :MBASCHKLST_N.FACTORY,
                    :MBASCHKLST_N.CHKLIST_ID,
                    :MBASCHKLST_N.CHKLIST_DESC,
                    :MBASCHKLST_N.CHKLIST_TYPE,
                    :MBASCHKLST_N.LOT_OR_RES_FLAG,
                    :MBASCHKLST_N.CHKLIST_GRP_1,
                    :MBASCHKLST_N.CHKLIST_GRP_2,
                    :MBASCHKLST_N.CHKLIST_GRP_3,
                    :MBASCHKLST_N.CHKLIST_GRP_4,
                    :MBASCHKLST_N.CHKLIST_GRP_5,
                    :MBASCHKLST_N.CHKLIST_GRP_6,
                    :MBASCHKLST_N.CHKLIST_GRP_7,
                    :MBASCHKLST_N.CHKLIST_GRP_8,
                    :MBASCHKLST_N.CHKLIST_GRP_9,
                    :MBASCHKLST_N.CHKLIST_GRP_10,
                    :MBASCHKLST_N.CHKLIST_CMF_1,
                    :MBASCHKLST_N.CHKLIST_CMF_2,
                    :MBASCHKLST_N.CHKLIST_CMF_3,
                    :MBASCHKLST_N.CHKLIST_CMF_4,
                    :MBASCHKLST_N.CHKLIST_CMF_5,
                    :MBASCHKLST_N.CHKLIST_CMF_6,
                    :MBASCHKLST_N.CHKLIST_CMF_7,
                    :MBASCHKLST_N.CHKLIST_CMF_8,
                    :MBASCHKLST_N.CHKLIST_CMF_9,
                    :MBASCHKLST_N.CHKLIST_CMF_10,
                    :MBASCHKLST_N.KEY_1_PMT,
                    :MBASCHKLST_N.KEY_2_PMT,
                    :MBASCHKLST_N.KEY_3_PMT,
                    :MBASCHKLST_N.KEY_4_PMT,
                    :MBASCHKLST_N.KEY_5_PMT,
                    :MBASCHKLST_N.KEY_6_PMT,
                    :MBASCHKLST_N.KEY_7_PMT,
                    :MBASCHKLST_N.KEY_8_PMT,
                    :MBASCHKLST_N.KEY_9_PMT,
                    :MBASCHKLST_N.KEY_10_PMT,
                    :MBASCHKLST_N.KEY_1_REQ,
                    :MBASCHKLST_N.KEY_2_REQ,
                    :MBASCHKLST_N.KEY_3_REQ,
                    :MBASCHKLST_N.KEY_4_REQ,
                    :MBASCHKLST_N.KEY_5_REQ,
                    :MBASCHKLST_N.KEY_6_REQ,
                    :MBASCHKLST_N.KEY_7_REQ,
                    :MBASCHKLST_N.KEY_8_REQ,
                    :MBASCHKLST_N.KEY_9_REQ,
                    :MBASCHKLST_N.KEY_10_REQ,
                    :MBASCHKLST_N.KEY_1_FMT,
                    :MBASCHKLST_N.KEY_2_FMT,
                    :MBASCHKLST_N.KEY_3_FMT,
                    :MBASCHKLST_N.KEY_4_FMT,
                    :MBASCHKLST_N.KEY_5_FMT,
                    :MBASCHKLST_N.KEY_6_FMT,
                    :MBASCHKLST_N.KEY_7_FMT,
                    :MBASCHKLST_N.KEY_8_FMT,
                    :MBASCHKLST_N.KEY_9_FMT,
                    :MBASCHKLST_N.KEY_10_FMT,
                    :MBASCHKLST_N.KEY_1_TBL,
                    :MBASCHKLST_N.KEY_2_TBL,
                    :MBASCHKLST_N.KEY_3_TBL,
                    :MBASCHKLST_N.KEY_4_TBL,
                    :MBASCHKLST_N.KEY_5_TBL,
                    :MBASCHKLST_N.KEY_6_TBL,
                    :MBASCHKLST_N.KEY_7_TBL,
                    :MBASCHKLST_N.KEY_8_TBL,
                    :MBASCHKLST_N.KEY_9_TBL,
                    :MBASCHKLST_N.KEY_10_TBL,
                    :MBASCHKLST_N.KEY_1_ITEM,
                    :MBASCHKLST_N.KEY_2_ITEM,
                    :MBASCHKLST_N.KEY_3_ITEM,
                    :MBASCHKLST_N.KEY_4_ITEM,
                    :MBASCHKLST_N.KEY_5_ITEM,
                    :MBASCHKLST_N.KEY_6_ITEM,
                    :MBASCHKLST_N.KEY_7_ITEM,
                    :MBASCHKLST_N.KEY_8_ITEM,
                    :MBASCHKLST_N.KEY_9_ITEM,
                    :MBASCHKLST_N.KEY_10_ITEM
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 81;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MBASCHKLST (CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPD\
ATE_TIME,FACTORY,CHKLIST_ID,CHKLIST_DESC,CHKLIST_TYPE,LOT_OR_RES_FLAG,CHKLIS\
T_GRP_1,CHKLIST_GRP_2,CHKLIST_GRP_3,CHKLIST_GRP_4,CHKLIST_GRP_5,CHKLIST_GRP_\
6,CHKLIST_GRP_7,CHKLIST_GRP_8,CHKLIST_GRP_9,CHKLIST_GRP_10,CHKLIST_CMF_1,CHK\
LIST_CMF_2,CHKLIST_CMF_3,CHKLIST_CMF_4,CHKLIST_CMF_5,CHKLIST_CMF_6,CHKLIST_C\
MF_7,CHKLIST_CMF_8,CHKLIST_CMF_9,CHKLIST_CMF_10,KEY_1_PMT,KEY_2_PMT,KEY_3_PM\
T,KEY_4_PMT,KEY_5_PMT,KEY_6_PMT,KEY_7_PMT,KEY_8_PMT,KEY_9_PMT,KEY_10_PMT,KEY\
_1_REQ,KEY_2_REQ,KEY_3_REQ,KEY_4_REQ,KEY_5_REQ,KEY_6_REQ,KEY_7_REQ,KEY_8_REQ\
,KEY_9_REQ,KEY_10_REQ,KEY_1_FMT,KEY_2_FMT,KEY_3_FMT,KEY_4_FMT,KEY_5_FMT,KEY_\
6_FMT,KEY_7_FMT,KEY_8_FMT,KEY_9_FMT,KEY_10_FMT,KEY_1_TBL,KEY_2_TBL,KEY_3_TBL\
,KEY_4_TBL,KEY_5_TBL,KEY_6_TBL,KEY_7_TBL,KEY_8_TBL,KEY_9_TBL,KEY_10_TBL,KEY_\
1_ITEM,KEY_2_ITEM,KEY_3_ITEM,KEY_4_ITEM,KEY_5_ITEM,KEY_6_ITEM,KEY_7_ITEM,KEY\
_8_ITEM,KEY_9_ITEM,KEY_10_ITEM) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,\
:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17");
    sqlstm.stmt = ",:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,\
:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b\
44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59\
,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:\
b75,:b76,:b77,:b78)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )733;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
    sqlstm.sqhstl[0] = (unsigned int  )21;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
    sqlstm.sqhstl[3] = (unsigned int  )15;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
    sqlstm.sqhstl[4] = (unsigned int  )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
    sqlstm.sqhstl[6] = (unsigned int  )201;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
    sqlstm.sqhstl[8] = (unsigned int  )2;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
    sqlstm.sqhstl[29] = (unsigned int  )51;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
    sqlstm.sqhstl[30] = (unsigned int  )51;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
    sqlstm.sqhstl[31] = (unsigned int  )51;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
    sqlstm.sqhstl[32] = (unsigned int  )51;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
    sqlstm.sqhstl[33] = (unsigned int  )51;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
    sqlstm.sqhstl[34] = (unsigned int  )51;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
    sqlstm.sqhstl[35] = (unsigned int  )51;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
    sqlstm.sqhstl[36] = (unsigned int  )51;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
    sqlstm.sqhstl[37] = (unsigned int  )51;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
    sqlstm.sqhstl[38] = (unsigned int  )51;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
    sqlstm.sqhstl[40] = (unsigned int  )2;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
    sqlstm.sqhstl[41] = (unsigned int  )2;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
    sqlstm.sqhstl[50] = (unsigned int  )2;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
    sqlstm.sqhstl[58] = (unsigned int  )2;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
    sqlstm.sqhstl[69] = (unsigned int  )101;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
    sqlstm.sqhstl[70] = (unsigned int  )101;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
    sqlstm.sqhstl[71] = (unsigned int  )101;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
    sqlstm.sqhstl[72] = (unsigned int  )101;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
    sqlstm.sqhstl[73] = (unsigned int  )101;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
    sqlstm.sqhstl[74] = (unsigned int  )101;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
    sqlstm.sqhstl[75] = (unsigned int  )101;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
    sqlstm.sqhstl[76] = (unsigned int  )101;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
    sqlstm.sqhstl[77] = (unsigned int  )101;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
    sqlstm.sqhstl[78] = (unsigned int  )101;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_mbaschklst", 0);
}


/* SQL UPDATE Function */
void DBC_update_mbaschklst(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MBASCHKLST SET
                    CREATE_USER_ID = :MBASCHKLST_N.CREATE_USER_ID,
                    CREATE_TIME = :MBASCHKLST_N.CREATE_TIME,
                    UPDATE_USER_ID = :MBASCHKLST_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MBASCHKLST_N.UPDATE_TIME,
                    CHKLIST_DESC = :MBASCHKLST_N.CHKLIST_DESC,
                    CHKLIST_TYPE = :MBASCHKLST_N.CHKLIST_TYPE,
                    LOT_OR_RES_FLAG = :MBASCHKLST_N.LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1 = :MBASCHKLST_N.CHKLIST_GRP_1,
                    CHKLIST_GRP_2 = :MBASCHKLST_N.CHKLIST_GRP_2,
                    CHKLIST_GRP_3 = :MBASCHKLST_N.CHKLIST_GRP_3,
                    CHKLIST_GRP_4 = :MBASCHKLST_N.CHKLIST_GRP_4,
                    CHKLIST_GRP_5 = :MBASCHKLST_N.CHKLIST_GRP_5,
                    CHKLIST_GRP_6 = :MBASCHKLST_N.CHKLIST_GRP_6,
                    CHKLIST_GRP_7 = :MBASCHKLST_N.CHKLIST_GRP_7,
                    CHKLIST_GRP_8 = :MBASCHKLST_N.CHKLIST_GRP_8,
                    CHKLIST_GRP_9 = :MBASCHKLST_N.CHKLIST_GRP_9,
                    CHKLIST_GRP_10 = :MBASCHKLST_N.CHKLIST_GRP_10,
                    CHKLIST_CMF_1 = :MBASCHKLST_N.CHKLIST_CMF_1,
                    CHKLIST_CMF_2 = :MBASCHKLST_N.CHKLIST_CMF_2,
                    CHKLIST_CMF_3 = :MBASCHKLST_N.CHKLIST_CMF_3,
                    CHKLIST_CMF_4 = :MBASCHKLST_N.CHKLIST_CMF_4,
                    CHKLIST_CMF_5 = :MBASCHKLST_N.CHKLIST_CMF_5,
                    CHKLIST_CMF_6 = :MBASCHKLST_N.CHKLIST_CMF_6,
                    CHKLIST_CMF_7 = :MBASCHKLST_N.CHKLIST_CMF_7,
                    CHKLIST_CMF_8 = :MBASCHKLST_N.CHKLIST_CMF_8,
                    CHKLIST_CMF_9 = :MBASCHKLST_N.CHKLIST_CMF_9,
                    CHKLIST_CMF_10 = :MBASCHKLST_N.CHKLIST_CMF_10,
                    KEY_1_PMT = :MBASCHKLST_N.KEY_1_PMT,
                    KEY_2_PMT = :MBASCHKLST_N.KEY_2_PMT,
                    KEY_3_PMT = :MBASCHKLST_N.KEY_3_PMT,
                    KEY_4_PMT = :MBASCHKLST_N.KEY_4_PMT,
                    KEY_5_PMT = :MBASCHKLST_N.KEY_5_PMT,
                    KEY_6_PMT = :MBASCHKLST_N.KEY_6_PMT,
                    KEY_7_PMT = :MBASCHKLST_N.KEY_7_PMT,
                    KEY_8_PMT = :MBASCHKLST_N.KEY_8_PMT,
                    KEY_9_PMT = :MBASCHKLST_N.KEY_9_PMT,
                    KEY_10_PMT = :MBASCHKLST_N.KEY_10_PMT,
                    KEY_1_REQ = :MBASCHKLST_N.KEY_1_REQ,
                    KEY_2_REQ = :MBASCHKLST_N.KEY_2_REQ,
                    KEY_3_REQ = :MBASCHKLST_N.KEY_3_REQ,
                    KEY_4_REQ = :MBASCHKLST_N.KEY_4_REQ,
                    KEY_5_REQ = :MBASCHKLST_N.KEY_5_REQ,
                    KEY_6_REQ = :MBASCHKLST_N.KEY_6_REQ,
                    KEY_7_REQ = :MBASCHKLST_N.KEY_7_REQ,
                    KEY_8_REQ = :MBASCHKLST_N.KEY_8_REQ,
                    KEY_9_REQ = :MBASCHKLST_N.KEY_9_REQ,
                    KEY_10_REQ = :MBASCHKLST_N.KEY_10_REQ,
                    KEY_1_FMT = :MBASCHKLST_N.KEY_1_FMT,
                    KEY_2_FMT = :MBASCHKLST_N.KEY_2_FMT,
                    KEY_3_FMT = :MBASCHKLST_N.KEY_3_FMT,
                    KEY_4_FMT = :MBASCHKLST_N.KEY_4_FMT,
                    KEY_5_FMT = :MBASCHKLST_N.KEY_5_FMT,
                    KEY_6_FMT = :MBASCHKLST_N.KEY_6_FMT,
                    KEY_7_FMT = :MBASCHKLST_N.KEY_7_FMT,
                    KEY_8_FMT = :MBASCHKLST_N.KEY_8_FMT,
                    KEY_9_FMT = :MBASCHKLST_N.KEY_9_FMT,
                    KEY_10_FMT = :MBASCHKLST_N.KEY_10_FMT,
                    KEY_1_TBL = :MBASCHKLST_N.KEY_1_TBL,
                    KEY_2_TBL = :MBASCHKLST_N.KEY_2_TBL,
                    KEY_3_TBL = :MBASCHKLST_N.KEY_3_TBL,
                    KEY_4_TBL = :MBASCHKLST_N.KEY_4_TBL,
                    KEY_5_TBL = :MBASCHKLST_N.KEY_5_TBL,
                    KEY_6_TBL = :MBASCHKLST_N.KEY_6_TBL,
                    KEY_7_TBL = :MBASCHKLST_N.KEY_7_TBL,
                    KEY_8_TBL = :MBASCHKLST_N.KEY_8_TBL,
                    KEY_9_TBL = :MBASCHKLST_N.KEY_9_TBL,
                    KEY_10_TBL = :MBASCHKLST_N.KEY_10_TBL,
                    KEY_1_ITEM = :MBASCHKLST_N.KEY_1_ITEM,
                    KEY_2_ITEM = :MBASCHKLST_N.KEY_2_ITEM,
                    KEY_3_ITEM = :MBASCHKLST_N.KEY_3_ITEM,
                    KEY_4_ITEM = :MBASCHKLST_N.KEY_4_ITEM,
                    KEY_5_ITEM = :MBASCHKLST_N.KEY_5_ITEM,
                    KEY_6_ITEM = :MBASCHKLST_N.KEY_6_ITEM,
                    KEY_7_ITEM = :MBASCHKLST_N.KEY_7_ITEM,
                    KEY_8_ITEM = :MBASCHKLST_N.KEY_8_ITEM,
                    KEY_9_ITEM = :MBASCHKLST_N.KEY_9_ITEM,
                    KEY_10_ITEM = :MBASCHKLST_N.KEY_10_ITEM
                WHERE FACTORY = :MBASCHKLST_N.FACTORY
                    AND CHKLIST_ID = :MBASCHKLST_N.CHKLIST_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MBASCHKLST  set CREATE_USER_ID=:b0,CREATE_TIME=:b1,UPD\
ATE_USER_ID=:b2,UPDATE_TIME=:b3,CHKLIST_DESC=:b4,CHKLIST_TYPE=:b5,LOT_OR_RES\
_FLAG=:b6,CHKLIST_GRP_1=:b7,CHKLIST_GRP_2=:b8,CHKLIST_GRP_3=:b9,CHKLIST_GRP_\
4=:b10,CHKLIST_GRP_5=:b11,CHKLIST_GRP_6=:b12,CHKLIST_GRP_7=:b13,CHKLIST_GRP_\
8=:b14,CHKLIST_GRP_9=:b15,CHKLIST_GRP_10=:b16,CHKLIST_CMF_1=:b17,CHKLIST_CMF\
_2=:b18,CHKLIST_CMF_3=:b19,CHKLIST_CMF_4=:b20,CHKLIST_CMF_5=:b21,CHKLIST_CMF\
_6=:b22,CHKLIST_CMF_7=:b23,CHKLIST_CMF_8=:b24,CHKLIST_CMF_9=:b25,CHKLIST_CMF\
_10=:b26,KEY_1_PMT=:b27,KEY_2_PMT=:b28,KEY_3_PMT=:b29,KEY_4_PMT=:b30,KEY_5_P\
MT=:b31,KEY_6_PMT=:b32,KEY_7_PMT=:b33,KEY_8_PMT=:b34,KEY_9_PMT=:b35,KEY_10_P\
MT=:b36,KEY_1_REQ=:b37,KEY_2_REQ=:b38,KEY_3_REQ=:b39,KEY_4_REQ=:b40,KEY_5_RE\
Q=:b41,KEY_6_REQ=:b42,KEY_7_REQ=:b43,KEY_8_REQ=:b44,KEY_9_REQ=:b45,KEY_10_RE\
Q=:b46,KEY_1_FMT=:b47,KEY_2_FMT=:b48,KEY_3_FMT=:b49,KEY_4_FMT=:b50,KEY_5_FMT\
=:b51,KEY_6_FMT=:b52,KEY_7_FMT=:b53,KEY_8_FMT=:b54,KEY_9_FMT=:b55,KEY_10_FMT\
=:b56,KEY_1_TBL=:b57,KEY_2_TBL=:b58,KEY_3_TBL=:b59,");
            sqlstm.stmt = "KEY_4_TBL=:b60,KEY_5_TBL=:b61,KEY_6_TBL=:b62,KEY\
_7_TBL=:b63,KEY_8_TBL=:b64,KEY_9_TBL=:b65,KEY_10_TBL=:b66,KEY_1_ITEM=:b67,KEY\
_2_ITEM=:b68,KEY_3_ITEM=:b69,KEY_4_ITEM=:b70,KEY_5_ITEM=:b71,KEY_6_ITEM=:b72,\
KEY_7_ITEM=:b73,KEY_8_ITEM=:b74,KEY_9_ITEM=:b75,KEY_10_ITEM=:b76 where (FACTO\
RY=:b77 and CHKLIST_ID=:b78)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1064;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[27] = (unsigned int  )51;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[28] = (unsigned int  )51;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[67] = (unsigned int  )101;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[68] = (unsigned int  )101;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[77] = (unsigned int  )11;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_mbaschklst", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mbaschklst(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MBASCHKLST_CUR_1 CURSOR FOR
                SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    CHKLIST_ID,
                    CHKLIST_DESC,
                    CHKLIST_TYPE,
                    LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1,
                    CHKLIST_GRP_2,
                    CHKLIST_GRP_3,
                    CHKLIST_GRP_4,
                    CHKLIST_GRP_5,
                    CHKLIST_GRP_6,
                    CHKLIST_GRP_7,
                    CHKLIST_GRP_8,
                    CHKLIST_GRP_9,
                    CHKLIST_GRP_10,
                    CHKLIST_CMF_1,
                    CHKLIST_CMF_2,
                    CHKLIST_CMF_3,
                    CHKLIST_CMF_4,
                    CHKLIST_CMF_5,
                    CHKLIST_CMF_6,
                    CHKLIST_CMF_7,
                    CHKLIST_CMF_8,
                    CHKLIST_CMF_9,
                    CHKLIST_CMF_10,
                    KEY_1_PMT,
                    KEY_2_PMT,
                    KEY_3_PMT,
                    KEY_4_PMT,
                    KEY_5_PMT,
                    KEY_6_PMT,
                    KEY_7_PMT,
                    KEY_8_PMT,
                    KEY_9_PMT,
                    KEY_10_PMT,
                    KEY_1_REQ,
                    KEY_2_REQ,
                    KEY_3_REQ,
                    KEY_4_REQ,
                    KEY_5_REQ,
                    KEY_6_REQ,
                    KEY_7_REQ,
                    KEY_8_REQ,
                    KEY_9_REQ,
                    KEY_10_REQ,
                    KEY_1_FMT,
                    KEY_2_FMT,
                    KEY_3_FMT,
                    KEY_4_FMT,
                    KEY_5_FMT,
                    KEY_6_FMT,
                    KEY_7_FMT,
                    KEY_8_FMT,
                    KEY_9_FMT,
                    KEY_10_FMT,
                    KEY_1_TBL,
                    KEY_2_TBL,
                    KEY_3_TBL,
                    KEY_4_TBL,
                    KEY_5_TBL,
                    KEY_6_TBL,
                    KEY_7_TBL,
                    KEY_8_TBL,
                    KEY_9_TBL,
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
                FROM MBASCHKLST
                ORDER BY FACTORY ASC,
                    CHKLIST_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MBASCHKLST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,CHKLIST_ID ,CHKLIST_DESC ,CHKLIST_TYPE ,LOT_OR_RES_FLAG ,CHKLIS\
T_GRP_1 ,CHKLIST_GRP_2 ,CHKLIST_GRP_3 ,CHKLIST_GRP_4 ,CHKLIST_GRP_5 ,CHKLIST\
_GRP_6 ,CHKLIST_GRP_7 ,CHKLIST_GRP_8 ,CHKLIST_GRP_9 ,CHKLIST_GRP_10 ,CHKLIST\
_CMF_1 ,CHKLIST_CMF_2 ,CHKLIST_CMF_3 ,CHKLIST_CMF_4 ,CHKLIST_CMF_5 ,CHKLIST_\
CMF_6 ,CHKLIST_CMF_7 ,CHKLIST_CMF_8 ,CHKLIST_CMF_9 ,CHKLIST_CMF_10 ,KEY_1_PM\
T ,KEY_2_PMT ,KEY_3_PMT ,KEY_4_PMT ,KEY_5_PMT ,KEY_6_PMT ,KEY_7_PMT ,KEY_8_P\
MT ,KEY_9_PMT ,KEY_10_PMT ,KEY_1_REQ ,KEY_2_REQ ,KEY_3_REQ ,KEY_4_REQ ,KEY_5\
_REQ ,KEY_6_REQ ,KEY_7_REQ ,KEY_8_REQ ,KEY_9_REQ ,KEY_10_REQ ,KEY_1_FMT ,KEY\
_2_FMT ,KEY_3_FMT ,KEY_4_FMT ,KEY_5_FMT ,KEY_6_FMT ,KEY_7_FMT ,KEY_8_FMT ,KE\
Y_9_FMT ,KEY_10_FMT ,KEY_1_TBL ,KEY_2_TBL ,KEY_3_TBL ,KEY_4_TBL ,KEY_5_TBL ,\
KEY_6_TBL ,KEY_7_TBL ,KEY_8_TBL ,KEY_9_TBL ,KEY_10_TBL ,KEY_1_ITEM ,KEY_2_IT\
EM ,KEY_3_ITEM ,KEY_4_ITEM ,KEY_5_ITEM ,KEY_6_ITEM ,KEY_7_ITEM ,KEY_8_ITEM ,\
KEY_9_ITEM ,KEY_10_ITEM  from MBASCHKLST  order by ");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1395;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 101:
            /* EXEC SQL DECLARE DBC_MBASCHKLST_CUR_101 CURSOR FOR
                SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    CHKLIST_ID,
                    CHKLIST_DESC,
                    CHKLIST_TYPE,
                    LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1,
                    CHKLIST_GRP_2,
                    CHKLIST_GRP_3,
                    CHKLIST_GRP_4,
                    CHKLIST_GRP_5,
                    CHKLIST_GRP_6,
                    CHKLIST_GRP_7,
                    CHKLIST_GRP_8,
                    CHKLIST_GRP_9,
                    CHKLIST_GRP_10,
                    CHKLIST_CMF_1,
                    CHKLIST_CMF_2,
                    CHKLIST_CMF_3,
                    CHKLIST_CMF_4,
                    CHKLIST_CMF_5,
                    CHKLIST_CMF_6,
                    CHKLIST_CMF_7,
                    CHKLIST_CMF_8,
                    CHKLIST_CMF_9,
                    CHKLIST_CMF_10,
                    KEY_1_PMT,
                    KEY_2_PMT,
                    KEY_3_PMT,
                    KEY_4_PMT,
                    KEY_5_PMT,
                    KEY_6_PMT,
                    KEY_7_PMT,
                    KEY_8_PMT,
                    KEY_9_PMT,
                    KEY_10_PMT,
                    KEY_1_REQ,
                    KEY_2_REQ,
                    KEY_3_REQ,
                    KEY_4_REQ,
                    KEY_5_REQ,
                    KEY_6_REQ,
                    KEY_7_REQ,
                    KEY_8_REQ,
                    KEY_9_REQ,
                    KEY_10_REQ,
                    KEY_1_FMT,
                    KEY_2_FMT,
                    KEY_3_FMT,
                    KEY_4_FMT,
                    KEY_5_FMT,
                    KEY_6_FMT,
                    KEY_7_FMT,
                    KEY_8_FMT,
                    KEY_9_FMT,
                    KEY_10_FMT,
                    KEY_1_TBL,
                    KEY_2_TBL,
                    KEY_3_TBL,
                    KEY_4_TBL,
                    KEY_5_TBL,
                    KEY_6_TBL,
                    KEY_7_TBL,
                    KEY_8_TBL,
                    KEY_9_TBL,
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
                FROM MBASCHKLST
				WHERE 1=1
					AND FACTORY = :MBASCHKLST_N.FACTORY
					AND CHKLIST_ID >= :MBASCHKLST_N.CHKLIST_ID
                ORDER BY CHKLIST_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MBASCHKLST_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,CHKLIST_ID ,CHKLIST_DESC ,CHKLIST_TYPE ,LOT_OR_RES_FLAG ,CHKLIS\
T_GRP_1 ,CHKLIST_GRP_2 ,CHKLIST_GRP_3 ,CHKLIST_GRP_4 ,CHKLIST_GRP_5 ,CHKLIST\
_GRP_6 ,CHKLIST_GRP_7 ,CHKLIST_GRP_8 ,CHKLIST_GRP_9 ,CHKLIST_GRP_10 ,CHKLIST\
_CMF_1 ,CHKLIST_CMF_2 ,CHKLIST_CMF_3 ,CHKLIST_CMF_4 ,CHKLIST_CMF_5 ,CHKLIST_\
CMF_6 ,CHKLIST_CMF_7 ,CHKLIST_CMF_8 ,CHKLIST_CMF_9 ,CHKLIST_CMF_10 ,KEY_1_PM\
T ,KEY_2_PMT ,KEY_3_PMT ,KEY_4_PMT ,KEY_5_PMT ,KEY_6_PMT ,KEY_7_PMT ,KEY_8_P\
MT ,KEY_9_PMT ,KEY_10_PMT ,KEY_1_REQ ,KEY_2_REQ ,KEY_3_REQ ,KEY_4_REQ ,KEY_5\
_REQ ,KEY_6_REQ ,KEY_7_REQ ,KEY_8_REQ ,KEY_9_REQ ,KEY_10_REQ ,KEY_1_FMT ,KEY\
_2_FMT ,KEY_3_FMT ,KEY_4_FMT ,KEY_5_FMT ,KEY_6_FMT ,KEY_7_FMT ,KEY_8_FMT ,KE\
Y_9_FMT ,KEY_10_FMT ,KEY_1_TBL ,KEY_2_TBL ,KEY_3_TBL ,KEY_4_TBL ,KEY_5_TBL ,\
KEY_6_TBL ,KEY_7_TBL ,KEY_8_TBL ,KEY_9_TBL ,KEY_10_TBL ,KEY_1_ITEM ,KEY_2_IT\
EM ,KEY_3_ITEM ,KEY_4_ITEM ,KEY_5_ITEM ,KEY_6_ITEM ,KEY_7_ITEM ,KEY_8_ITEM ,\
KEY_9_ITEM ,KEY_10_ITEM  from MBASCHKLST where ((1=");
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1410;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
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
			
		case 102:
            /* EXEC SQL DECLARE DBC_MBASCHKLST_CUR_102 CURSOR FOR
                SELECT 
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    FACTORY,
                    CHKLIST_ID,
                    CHKLIST_DESC,
                    CHKLIST_TYPE,
                    LOT_OR_RES_FLAG,
                    CHKLIST_GRP_1,
                    CHKLIST_GRP_2,
                    CHKLIST_GRP_3,
                    CHKLIST_GRP_4,
                    CHKLIST_GRP_5,
                    CHKLIST_GRP_6,
                    CHKLIST_GRP_7,
                    CHKLIST_GRP_8,
                    CHKLIST_GRP_9,
                    CHKLIST_GRP_10,
                    CHKLIST_CMF_1,
                    CHKLIST_CMF_2,
                    CHKLIST_CMF_3,
                    CHKLIST_CMF_4,
                    CHKLIST_CMF_5,
                    CHKLIST_CMF_6,
                    CHKLIST_CMF_7,
                    CHKLIST_CMF_8,
                    CHKLIST_CMF_9,
                    CHKLIST_CMF_10,
                    KEY_1_PMT,
                    KEY_2_PMT,
                    KEY_3_PMT,
                    KEY_4_PMT,
                    KEY_5_PMT,
                    KEY_6_PMT,
                    KEY_7_PMT,
                    KEY_8_PMT,
                    KEY_9_PMT,
                    KEY_10_PMT,
                    KEY_1_REQ,
                    KEY_2_REQ,
                    KEY_3_REQ,
                    KEY_4_REQ,
                    KEY_5_REQ,
                    KEY_6_REQ,
                    KEY_7_REQ,
                    KEY_8_REQ,
                    KEY_9_REQ,
                    KEY_10_REQ,
                    KEY_1_FMT,
                    KEY_2_FMT,
                    KEY_3_FMT,
                    KEY_4_FMT,
                    KEY_5_FMT,
                    KEY_6_FMT,
                    KEY_7_FMT,
                    KEY_8_FMT,
                    KEY_9_FMT,
                    KEY_10_FMT,
                    KEY_1_TBL,
                    KEY_2_TBL,
                    KEY_3_TBL,
                    KEY_4_TBL,
                    KEY_5_TBL,
                    KEY_6_TBL,
                    KEY_7_TBL,
                    KEY_8_TBL,
                    KEY_9_TBL,
                    KEY_10_TBL,
                    KEY_1_ITEM,
                    KEY_2_ITEM,
                    KEY_3_ITEM,
                    KEY_4_ITEM,
                    KEY_5_ITEM,
                    KEY_6_ITEM,
                    KEY_7_ITEM,
                    KEY_8_ITEM,
                    KEY_9_ITEM,
                    KEY_10_ITEM
                FROM MBASCHKLST
				WHERE 1=1
					AND FACTORY = :MBASCHKLST_N.FACTORY
					AND CHKLIST_TYPE = :MBASCHKLST_N.CHKLIST_TYPE
					AND CHKLIST_ID >= :MBASCHKLST_N.CHKLIST_ID
                ORDER BY CHKLIST_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MBASCHKLST_CUR_102; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TI\
ME ,FACTORY ,CHKLIST_ID ,CHKLIST_DESC ,CHKLIST_TYPE ,LOT_OR_RES_FLAG ,CHKLIS\
T_GRP_1 ,CHKLIST_GRP_2 ,CHKLIST_GRP_3 ,CHKLIST_GRP_4 ,CHKLIST_GRP_5 ,CHKLIST\
_GRP_6 ,CHKLIST_GRP_7 ,CHKLIST_GRP_8 ,CHKLIST_GRP_9 ,CHKLIST_GRP_10 ,CHKLIST\
_CMF_1 ,CHKLIST_CMF_2 ,CHKLIST_CMF_3 ,CHKLIST_CMF_4 ,CHKLIST_CMF_5 ,CHKLIST_\
CMF_6 ,CHKLIST_CMF_7 ,CHKLIST_CMF_8 ,CHKLIST_CMF_9 ,CHKLIST_CMF_10 ,KEY_1_PM\
T ,KEY_2_PMT ,KEY_3_PMT ,KEY_4_PMT ,KEY_5_PMT ,KEY_6_PMT ,KEY_7_PMT ,KEY_8_P\
MT ,KEY_9_PMT ,KEY_10_PMT ,KEY_1_REQ ,KEY_2_REQ ,KEY_3_REQ ,KEY_4_REQ ,KEY_5\
_REQ ,KEY_6_REQ ,KEY_7_REQ ,KEY_8_REQ ,KEY_9_REQ ,KEY_10_REQ ,KEY_1_FMT ,KEY\
_2_FMT ,KEY_3_FMT ,KEY_4_FMT ,KEY_5_FMT ,KEY_6_FMT ,KEY_7_FMT ,KEY_8_FMT ,KE\
Y_9_FMT ,KEY_10_FMT ,KEY_1_TBL ,KEY_2_TBL ,KEY_3_TBL ,KEY_4_TBL ,KEY_5_TBL ,\
KEY_6_TBL ,KEY_7_TBL ,KEY_8_TBL ,KEY_9_TBL ,KEY_10_TBL ,KEY_1_ITEM ,KEY_2_IT\
EM ,KEY_3_ITEM ,KEY_4_ITEM ,KEY_5_ITEM ,KEY_6_ITEM ,KEY_7_ITEM ,KEY_8_ITEM ,\
KEY_9_ITEM ,KEY_10_ITEM  from MBASCHKLST where (((1");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1433;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
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

    DB_stop_query_timer("DBC_open_mbaschklst", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mbaschklst(int sel_type, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_N_TAG MBASCHKLST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MBASCHKLST_CUR_1 INTO
                :MBASCHKLST_N.CREATE_USER_ID,
                :MBASCHKLST_N.CREATE_TIME,
                :MBASCHKLST_N.UPDATE_USER_ID,
                :MBASCHKLST_N.UPDATE_TIME,
                :MBASCHKLST_N.FACTORY,
                :MBASCHKLST_N.CHKLIST_ID,
                :MBASCHKLST_N.CHKLIST_DESC,
                :MBASCHKLST_N.CHKLIST_TYPE,
                :MBASCHKLST_N.LOT_OR_RES_FLAG,
                :MBASCHKLST_N.CHKLIST_GRP_1,
                :MBASCHKLST_N.CHKLIST_GRP_2,
                :MBASCHKLST_N.CHKLIST_GRP_3,
                :MBASCHKLST_N.CHKLIST_GRP_4,
                :MBASCHKLST_N.CHKLIST_GRP_5,
                :MBASCHKLST_N.CHKLIST_GRP_6,
                :MBASCHKLST_N.CHKLIST_GRP_7,
                :MBASCHKLST_N.CHKLIST_GRP_8,
                :MBASCHKLST_N.CHKLIST_GRP_9,
                :MBASCHKLST_N.CHKLIST_GRP_10,
                :MBASCHKLST_N.CHKLIST_CMF_1,
                :MBASCHKLST_N.CHKLIST_CMF_2,
                :MBASCHKLST_N.CHKLIST_CMF_3,
                :MBASCHKLST_N.CHKLIST_CMF_4,
                :MBASCHKLST_N.CHKLIST_CMF_5,
                :MBASCHKLST_N.CHKLIST_CMF_6,
                :MBASCHKLST_N.CHKLIST_CMF_7,
                :MBASCHKLST_N.CHKLIST_CMF_8,
                :MBASCHKLST_N.CHKLIST_CMF_9,
                :MBASCHKLST_N.CHKLIST_CMF_10,
                :MBASCHKLST_N.KEY_1_PMT,
                :MBASCHKLST_N.KEY_2_PMT,
                :MBASCHKLST_N.KEY_3_PMT,
                :MBASCHKLST_N.KEY_4_PMT,
                :MBASCHKLST_N.KEY_5_PMT,
                :MBASCHKLST_N.KEY_6_PMT,
                :MBASCHKLST_N.KEY_7_PMT,
                :MBASCHKLST_N.KEY_8_PMT,
                :MBASCHKLST_N.KEY_9_PMT,
                :MBASCHKLST_N.KEY_10_PMT,
                :MBASCHKLST_N.KEY_1_REQ,
                :MBASCHKLST_N.KEY_2_REQ,
                :MBASCHKLST_N.KEY_3_REQ,
                :MBASCHKLST_N.KEY_4_REQ,
                :MBASCHKLST_N.KEY_5_REQ,
                :MBASCHKLST_N.KEY_6_REQ,
                :MBASCHKLST_N.KEY_7_REQ,
                :MBASCHKLST_N.KEY_8_REQ,
                :MBASCHKLST_N.KEY_9_REQ,
                :MBASCHKLST_N.KEY_10_REQ,
                :MBASCHKLST_N.KEY_1_FMT,
                :MBASCHKLST_N.KEY_2_FMT,
                :MBASCHKLST_N.KEY_3_FMT,
                :MBASCHKLST_N.KEY_4_FMT,
                :MBASCHKLST_N.KEY_5_FMT,
                :MBASCHKLST_N.KEY_6_FMT,
                :MBASCHKLST_N.KEY_7_FMT,
                :MBASCHKLST_N.KEY_8_FMT,
                :MBASCHKLST_N.KEY_9_FMT,
                :MBASCHKLST_N.KEY_10_FMT,
                :MBASCHKLST_N.KEY_1_TBL,
                :MBASCHKLST_N.KEY_2_TBL,
                :MBASCHKLST_N.KEY_3_TBL,
                :MBASCHKLST_N.KEY_4_TBL,
                :MBASCHKLST_N.KEY_5_TBL,
                :MBASCHKLST_N.KEY_6_TBL,
                :MBASCHKLST_N.KEY_7_TBL,
                :MBASCHKLST_N.KEY_8_TBL,
                :MBASCHKLST_N.KEY_9_TBL,
                :MBASCHKLST_N.KEY_10_TBL,
                :MBASCHKLST_N.KEY_1_ITEM,
                :MBASCHKLST_N.KEY_2_ITEM,
                :MBASCHKLST_N.KEY_3_ITEM,
                :MBASCHKLST_N.KEY_4_ITEM,
                :MBASCHKLST_N.KEY_5_ITEM,
                :MBASCHKLST_N.KEY_6_ITEM,
                :MBASCHKLST_N.KEY_7_ITEM,
                :MBASCHKLST_N.KEY_8_ITEM,
                :MBASCHKLST_N.KEY_9_ITEM,
                :MBASCHKLST_N.KEY_10_ITEM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1460;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[77] = (unsigned int  )101;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[78] = (unsigned int  )101;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
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

        case 101:
            /* EXEC SQL FETCH DBC_MBASCHKLST_CUR_101 INTO
                :MBASCHKLST_N.CREATE_USER_ID,
                :MBASCHKLST_N.CREATE_TIME,
                :MBASCHKLST_N.UPDATE_USER_ID,
                :MBASCHKLST_N.UPDATE_TIME,
                :MBASCHKLST_N.FACTORY,
                :MBASCHKLST_N.CHKLIST_ID,
                :MBASCHKLST_N.CHKLIST_DESC,
                :MBASCHKLST_N.CHKLIST_TYPE,
                :MBASCHKLST_N.LOT_OR_RES_FLAG,
                :MBASCHKLST_N.CHKLIST_GRP_1,
                :MBASCHKLST_N.CHKLIST_GRP_2,
                :MBASCHKLST_N.CHKLIST_GRP_3,
                :MBASCHKLST_N.CHKLIST_GRP_4,
                :MBASCHKLST_N.CHKLIST_GRP_5,
                :MBASCHKLST_N.CHKLIST_GRP_6,
                :MBASCHKLST_N.CHKLIST_GRP_7,
                :MBASCHKLST_N.CHKLIST_GRP_8,
                :MBASCHKLST_N.CHKLIST_GRP_9,
                :MBASCHKLST_N.CHKLIST_GRP_10,
                :MBASCHKLST_N.CHKLIST_CMF_1,
                :MBASCHKLST_N.CHKLIST_CMF_2,
                :MBASCHKLST_N.CHKLIST_CMF_3,
                :MBASCHKLST_N.CHKLIST_CMF_4,
                :MBASCHKLST_N.CHKLIST_CMF_5,
                :MBASCHKLST_N.CHKLIST_CMF_6,
                :MBASCHKLST_N.CHKLIST_CMF_7,
                :MBASCHKLST_N.CHKLIST_CMF_8,
                :MBASCHKLST_N.CHKLIST_CMF_9,
                :MBASCHKLST_N.CHKLIST_CMF_10,
                :MBASCHKLST_N.KEY_1_PMT,
                :MBASCHKLST_N.KEY_2_PMT,
                :MBASCHKLST_N.KEY_3_PMT,
                :MBASCHKLST_N.KEY_4_PMT,
                :MBASCHKLST_N.KEY_5_PMT,
                :MBASCHKLST_N.KEY_6_PMT,
                :MBASCHKLST_N.KEY_7_PMT,
                :MBASCHKLST_N.KEY_8_PMT,
                :MBASCHKLST_N.KEY_9_PMT,
                :MBASCHKLST_N.KEY_10_PMT,
                :MBASCHKLST_N.KEY_1_REQ,
                :MBASCHKLST_N.KEY_2_REQ,
                :MBASCHKLST_N.KEY_3_REQ,
                :MBASCHKLST_N.KEY_4_REQ,
                :MBASCHKLST_N.KEY_5_REQ,
                :MBASCHKLST_N.KEY_6_REQ,
                :MBASCHKLST_N.KEY_7_REQ,
                :MBASCHKLST_N.KEY_8_REQ,
                :MBASCHKLST_N.KEY_9_REQ,
                :MBASCHKLST_N.KEY_10_REQ,
                :MBASCHKLST_N.KEY_1_FMT,
                :MBASCHKLST_N.KEY_2_FMT,
                :MBASCHKLST_N.KEY_3_FMT,
                :MBASCHKLST_N.KEY_4_FMT,
                :MBASCHKLST_N.KEY_5_FMT,
                :MBASCHKLST_N.KEY_6_FMT,
                :MBASCHKLST_N.KEY_7_FMT,
                :MBASCHKLST_N.KEY_8_FMT,
                :MBASCHKLST_N.KEY_9_FMT,
                :MBASCHKLST_N.KEY_10_FMT,
                :MBASCHKLST_N.KEY_1_TBL,
                :MBASCHKLST_N.KEY_2_TBL,
                :MBASCHKLST_N.KEY_3_TBL,
                :MBASCHKLST_N.KEY_4_TBL,
                :MBASCHKLST_N.KEY_5_TBL,
                :MBASCHKLST_N.KEY_6_TBL,
                :MBASCHKLST_N.KEY_7_TBL,
                :MBASCHKLST_N.KEY_8_TBL,
                :MBASCHKLST_N.KEY_9_TBL,
                :MBASCHKLST_N.KEY_10_TBL,
                :MBASCHKLST_N.KEY_1_ITEM,
                :MBASCHKLST_N.KEY_2_ITEM,
                :MBASCHKLST_N.KEY_3_ITEM,
                :MBASCHKLST_N.KEY_4_ITEM,
                :MBASCHKLST_N.KEY_5_ITEM,
                :MBASCHKLST_N.KEY_6_ITEM,
                :MBASCHKLST_N.KEY_7_ITEM,
                :MBASCHKLST_N.KEY_8_ITEM,
                :MBASCHKLST_N.KEY_9_ITEM,
                :MBASCHKLST_N.KEY_10_ITEM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1791;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[77] = (unsigned int  )101;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[78] = (unsigned int  )101;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
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

        case 102:
            /* EXEC SQL FETCH DBC_MBASCHKLST_CUR_102 INTO
                :MBASCHKLST_N.CREATE_USER_ID,
                :MBASCHKLST_N.CREATE_TIME,
                :MBASCHKLST_N.UPDATE_USER_ID,
                :MBASCHKLST_N.UPDATE_TIME,
                :MBASCHKLST_N.FACTORY,
                :MBASCHKLST_N.CHKLIST_ID,
                :MBASCHKLST_N.CHKLIST_DESC,
                :MBASCHKLST_N.CHKLIST_TYPE,
                :MBASCHKLST_N.LOT_OR_RES_FLAG,
                :MBASCHKLST_N.CHKLIST_GRP_1,
                :MBASCHKLST_N.CHKLIST_GRP_2,
                :MBASCHKLST_N.CHKLIST_GRP_3,
                :MBASCHKLST_N.CHKLIST_GRP_4,
                :MBASCHKLST_N.CHKLIST_GRP_5,
                :MBASCHKLST_N.CHKLIST_GRP_6,
                :MBASCHKLST_N.CHKLIST_GRP_7,
                :MBASCHKLST_N.CHKLIST_GRP_8,
                :MBASCHKLST_N.CHKLIST_GRP_9,
                :MBASCHKLST_N.CHKLIST_GRP_10,
                :MBASCHKLST_N.CHKLIST_CMF_1,
                :MBASCHKLST_N.CHKLIST_CMF_2,
                :MBASCHKLST_N.CHKLIST_CMF_3,
                :MBASCHKLST_N.CHKLIST_CMF_4,
                :MBASCHKLST_N.CHKLIST_CMF_5,
                :MBASCHKLST_N.CHKLIST_CMF_6,
                :MBASCHKLST_N.CHKLIST_CMF_7,
                :MBASCHKLST_N.CHKLIST_CMF_8,
                :MBASCHKLST_N.CHKLIST_CMF_9,
                :MBASCHKLST_N.CHKLIST_CMF_10,
                :MBASCHKLST_N.KEY_1_PMT,
                :MBASCHKLST_N.KEY_2_PMT,
                :MBASCHKLST_N.KEY_3_PMT,
                :MBASCHKLST_N.KEY_4_PMT,
                :MBASCHKLST_N.KEY_5_PMT,
                :MBASCHKLST_N.KEY_6_PMT,
                :MBASCHKLST_N.KEY_7_PMT,
                :MBASCHKLST_N.KEY_8_PMT,
                :MBASCHKLST_N.KEY_9_PMT,
                :MBASCHKLST_N.KEY_10_PMT,
                :MBASCHKLST_N.KEY_1_REQ,
                :MBASCHKLST_N.KEY_2_REQ,
                :MBASCHKLST_N.KEY_3_REQ,
                :MBASCHKLST_N.KEY_4_REQ,
                :MBASCHKLST_N.KEY_5_REQ,
                :MBASCHKLST_N.KEY_6_REQ,
                :MBASCHKLST_N.KEY_7_REQ,
                :MBASCHKLST_N.KEY_8_REQ,
                :MBASCHKLST_N.KEY_9_REQ,
                :MBASCHKLST_N.KEY_10_REQ,
                :MBASCHKLST_N.KEY_1_FMT,
                :MBASCHKLST_N.KEY_2_FMT,
                :MBASCHKLST_N.KEY_3_FMT,
                :MBASCHKLST_N.KEY_4_FMT,
                :MBASCHKLST_N.KEY_5_FMT,
                :MBASCHKLST_N.KEY_6_FMT,
                :MBASCHKLST_N.KEY_7_FMT,
                :MBASCHKLST_N.KEY_8_FMT,
                :MBASCHKLST_N.KEY_9_FMT,
                :MBASCHKLST_N.KEY_10_FMT,
                :MBASCHKLST_N.KEY_1_TBL,
                :MBASCHKLST_N.KEY_2_TBL,
                :MBASCHKLST_N.KEY_3_TBL,
                :MBASCHKLST_N.KEY_4_TBL,
                :MBASCHKLST_N.KEY_5_TBL,
                :MBASCHKLST_N.KEY_6_TBL,
                :MBASCHKLST_N.KEY_7_TBL,
                :MBASCHKLST_N.KEY_8_TBL,
                :MBASCHKLST_N.KEY_9_TBL,
                :MBASCHKLST_N.KEY_10_TBL,
                :MBASCHKLST_N.KEY_1_ITEM,
                :MBASCHKLST_N.KEY_2_ITEM,
                :MBASCHKLST_N.KEY_3_ITEM,
                :MBASCHKLST_N.KEY_4_ITEM,
                :MBASCHKLST_N.KEY_5_ITEM,
                :MBASCHKLST_N.KEY_6_ITEM,
                :MBASCHKLST_N.KEY_7_ITEM,
                :MBASCHKLST_N.KEY_8_ITEM,
                :MBASCHKLST_N.KEY_9_ITEM,
                :MBASCHKLST_N.KEY_10_ITEM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2122;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_N.CREATE_USER_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_N.CREATE_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MBASCHKLST_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MBASCHKLST_N.CHKLIST_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MBASCHKLST_N.CHKLIST_DESC);
            sqlstm.sqhstl[6] = (unsigned int  )201;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MBASCHKLST_N.CHKLIST_TYPE);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MBASCHKLST_N.LOT_OR_RES_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_1);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_2);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_3);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_4);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_5);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_6);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_7);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_8);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_9);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MBASCHKLST_N.CHKLIST_GRP_10);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_1);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_2);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_3);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_4);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_5);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_6);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_7);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_8);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_9);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MBASCHKLST_N.CHKLIST_CMF_10);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MBASCHKLST_N.KEY_1_PMT);
            sqlstm.sqhstl[29] = (unsigned int  )51;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MBASCHKLST_N.KEY_2_PMT);
            sqlstm.sqhstl[30] = (unsigned int  )51;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MBASCHKLST_N.KEY_3_PMT);
            sqlstm.sqhstl[31] = (unsigned int  )51;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MBASCHKLST_N.KEY_4_PMT);
            sqlstm.sqhstl[32] = (unsigned int  )51;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MBASCHKLST_N.KEY_5_PMT);
            sqlstm.sqhstl[33] = (unsigned int  )51;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MBASCHKLST_N.KEY_6_PMT);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MBASCHKLST_N.KEY_7_PMT);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MBASCHKLST_N.KEY_8_PMT);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MBASCHKLST_N.KEY_9_PMT);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MBASCHKLST_N.KEY_10_PMT);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MBASCHKLST_N.KEY_1_REQ);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MBASCHKLST_N.KEY_2_REQ);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MBASCHKLST_N.KEY_3_REQ);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MBASCHKLST_N.KEY_4_REQ);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MBASCHKLST_N.KEY_5_REQ);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MBASCHKLST_N.KEY_6_REQ);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MBASCHKLST_N.KEY_7_REQ);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MBASCHKLST_N.KEY_8_REQ);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MBASCHKLST_N.KEY_9_REQ);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MBASCHKLST_N.KEY_10_REQ);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MBASCHKLST_N.KEY_1_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MBASCHKLST_N.KEY_2_FMT);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MBASCHKLST_N.KEY_3_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MBASCHKLST_N.KEY_4_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MBASCHKLST_N.KEY_5_FMT);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MBASCHKLST_N.KEY_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MBASCHKLST_N.KEY_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MBASCHKLST_N.KEY_8_FMT);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MBASCHKLST_N.KEY_9_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MBASCHKLST_N.KEY_10_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MBASCHKLST_N.KEY_1_TBL);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MBASCHKLST_N.KEY_2_TBL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MBASCHKLST_N.KEY_3_TBL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MBASCHKLST_N.KEY_4_TBL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MBASCHKLST_N.KEY_5_TBL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MBASCHKLST_N.KEY_6_TBL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MBASCHKLST_N.KEY_7_TBL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MBASCHKLST_N.KEY_8_TBL);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MBASCHKLST_N.KEY_9_TBL);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MBASCHKLST_N.KEY_10_TBL);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MBASCHKLST_N.KEY_1_ITEM);
            sqlstm.sqhstl[69] = (unsigned int  )101;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MBASCHKLST_N.KEY_2_ITEM);
            sqlstm.sqhstl[70] = (unsigned int  )101;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MBASCHKLST_N.KEY_3_ITEM);
            sqlstm.sqhstl[71] = (unsigned int  )101;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MBASCHKLST_N.KEY_4_ITEM);
            sqlstm.sqhstl[72] = (unsigned int  )101;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MBASCHKLST_N.KEY_5_ITEM);
            sqlstm.sqhstl[73] = (unsigned int  )101;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MBASCHKLST_N.KEY_6_ITEM);
            sqlstm.sqhstl[74] = (unsigned int  )101;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MBASCHKLST_N.KEY_7_ITEM);
            sqlstm.sqhstl[75] = (unsigned int  )101;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MBASCHKLST_N.KEY_8_ITEM);
            sqlstm.sqhstl[76] = (unsigned int  )101;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MBASCHKLST_N.KEY_9_ITEM);
            sqlstm.sqhstl[77] = (unsigned int  )101;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MBASCHKLST_N.KEY_10_ITEM);
            sqlstm.sqhstl[78] = (unsigned int  )101;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
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
        DBC_del_null_mbaschklst(&MBASCHKLST_N, MBASCHKLST);
    }

    DB_stop_query_timer("DBC_fetch_mbaschklst", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mbaschklst(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MBASCHKLST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2453;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 101:
            /* EXEC SQL CLOSE DBC_MBASCHKLST_CUR_101; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2468;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
			
        case 102:
            /* EXEC SQL CLOSE DBC_MBASCHKLST_CUR_102; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2483;
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

    DB_stop_query_timer("DBC_close_mbaschklst", sel_type);
}


/* Initialize Function */
void DBC_init_mbaschklst(struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* memset by Space */
    memset(MBASCHKLST, ' ', sizeof(struct MBASCHKLST_TAG));
    
}


/* Add Null Function */
void DBC_add_null_mbaschklst(struct MBASCHKLST_N_TAG *MBASCHKLST_N, struct MBASCHKLST_TAG *MBASCHKLST)
{
    /* memset by NULL */
    memset(MBASCHKLST_N, '\0', sizeof(struct MBASCHKLST_N_TAG));
    
    MEMCPY_AN(MBASCHKLST_N->CREATE_USER_ID, MBASCHKLST->CREATE_USER_ID, sizeof(MBASCHKLST->CREATE_USER_ID));
    MEMCPY_AN(MBASCHKLST_N->CREATE_TIME, MBASCHKLST->CREATE_TIME, sizeof(MBASCHKLST->CREATE_TIME));
    MEMCPY_AN(MBASCHKLST_N->UPDATE_USER_ID, MBASCHKLST->UPDATE_USER_ID, sizeof(MBASCHKLST->UPDATE_USER_ID));
    MEMCPY_AN(MBASCHKLST_N->UPDATE_TIME, MBASCHKLST->UPDATE_TIME, sizeof(MBASCHKLST->UPDATE_TIME));
    MEMCPY_AN(MBASCHKLST_N->FACTORY, MBASCHKLST->FACTORY, sizeof(MBASCHKLST->FACTORY));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_ID, MBASCHKLST->CHKLIST_ID, sizeof(MBASCHKLST->CHKLIST_ID));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_DESC, MBASCHKLST->CHKLIST_DESC, sizeof(MBASCHKLST->CHKLIST_DESC));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_TYPE, MBASCHKLST->CHKLIST_TYPE, sizeof(MBASCHKLST->CHKLIST_TYPE));
    MBASCHKLST_N->LOT_OR_RES_FLAG[0] = MBASCHKLST->LOT_OR_RES_FLAG;
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_1, MBASCHKLST->CHKLIST_GRP_1, sizeof(MBASCHKLST->CHKLIST_GRP_1));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_2, MBASCHKLST->CHKLIST_GRP_2, sizeof(MBASCHKLST->CHKLIST_GRP_2));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_3, MBASCHKLST->CHKLIST_GRP_3, sizeof(MBASCHKLST->CHKLIST_GRP_3));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_4, MBASCHKLST->CHKLIST_GRP_4, sizeof(MBASCHKLST->CHKLIST_GRP_4));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_5, MBASCHKLST->CHKLIST_GRP_5, sizeof(MBASCHKLST->CHKLIST_GRP_5));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_6, MBASCHKLST->CHKLIST_GRP_6, sizeof(MBASCHKLST->CHKLIST_GRP_6));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_7, MBASCHKLST->CHKLIST_GRP_7, sizeof(MBASCHKLST->CHKLIST_GRP_7));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_8, MBASCHKLST->CHKLIST_GRP_8, sizeof(MBASCHKLST->CHKLIST_GRP_8));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_9, MBASCHKLST->CHKLIST_GRP_9, sizeof(MBASCHKLST->CHKLIST_GRP_9));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_GRP_10, MBASCHKLST->CHKLIST_GRP_10, sizeof(MBASCHKLST->CHKLIST_GRP_10));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_1, MBASCHKLST->CHKLIST_CMF_1, sizeof(MBASCHKLST->CHKLIST_CMF_1));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_2, MBASCHKLST->CHKLIST_CMF_2, sizeof(MBASCHKLST->CHKLIST_CMF_2));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_3, MBASCHKLST->CHKLIST_CMF_3, sizeof(MBASCHKLST->CHKLIST_CMF_3));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_4, MBASCHKLST->CHKLIST_CMF_4, sizeof(MBASCHKLST->CHKLIST_CMF_4));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_5, MBASCHKLST->CHKLIST_CMF_5, sizeof(MBASCHKLST->CHKLIST_CMF_5));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_6, MBASCHKLST->CHKLIST_CMF_6, sizeof(MBASCHKLST->CHKLIST_CMF_6));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_7, MBASCHKLST->CHKLIST_CMF_7, sizeof(MBASCHKLST->CHKLIST_CMF_7));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_8, MBASCHKLST->CHKLIST_CMF_8, sizeof(MBASCHKLST->CHKLIST_CMF_8));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_9, MBASCHKLST->CHKLIST_CMF_9, sizeof(MBASCHKLST->CHKLIST_CMF_9));
    MEMCPY_AN(MBASCHKLST_N->CHKLIST_CMF_10, MBASCHKLST->CHKLIST_CMF_10, sizeof(MBASCHKLST->CHKLIST_CMF_10));
    MEMCPY_AN(MBASCHKLST_N->KEY_1_PMT, MBASCHKLST->KEY_1_PMT, sizeof(MBASCHKLST->KEY_1_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_2_PMT, MBASCHKLST->KEY_2_PMT, sizeof(MBASCHKLST->KEY_2_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_3_PMT, MBASCHKLST->KEY_3_PMT, sizeof(MBASCHKLST->KEY_3_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_4_PMT, MBASCHKLST->KEY_4_PMT, sizeof(MBASCHKLST->KEY_4_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_5_PMT, MBASCHKLST->KEY_5_PMT, sizeof(MBASCHKLST->KEY_5_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_6_PMT, MBASCHKLST->KEY_6_PMT, sizeof(MBASCHKLST->KEY_6_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_7_PMT, MBASCHKLST->KEY_7_PMT, sizeof(MBASCHKLST->KEY_7_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_8_PMT, MBASCHKLST->KEY_8_PMT, sizeof(MBASCHKLST->KEY_8_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_9_PMT, MBASCHKLST->KEY_9_PMT, sizeof(MBASCHKLST->KEY_9_PMT));
    MEMCPY_AN(MBASCHKLST_N->KEY_10_PMT, MBASCHKLST->KEY_10_PMT, sizeof(MBASCHKLST->KEY_10_PMT));
    MBASCHKLST_N->KEY_1_REQ[0] = MBASCHKLST->KEY_1_REQ;
    MBASCHKLST_N->KEY_2_REQ[0] = MBASCHKLST->KEY_2_REQ;
    MBASCHKLST_N->KEY_3_REQ[0] = MBASCHKLST->KEY_3_REQ;
    MBASCHKLST_N->KEY_4_REQ[0] = MBASCHKLST->KEY_4_REQ;
    MBASCHKLST_N->KEY_5_REQ[0] = MBASCHKLST->KEY_5_REQ;
    MBASCHKLST_N->KEY_6_REQ[0] = MBASCHKLST->KEY_6_REQ;
    MBASCHKLST_N->KEY_7_REQ[0] = MBASCHKLST->KEY_7_REQ;
    MBASCHKLST_N->KEY_8_REQ[0] = MBASCHKLST->KEY_8_REQ;
    MBASCHKLST_N->KEY_9_REQ[0] = MBASCHKLST->KEY_9_REQ;
    MBASCHKLST_N->KEY_10_REQ[0] = MBASCHKLST->KEY_10_REQ;
    MBASCHKLST_N->KEY_1_FMT[0] = MBASCHKLST->KEY_1_FMT;
    MBASCHKLST_N->KEY_2_FMT[0] = MBASCHKLST->KEY_2_FMT;
    MBASCHKLST_N->KEY_3_FMT[0] = MBASCHKLST->KEY_3_FMT;
    MBASCHKLST_N->KEY_4_FMT[0] = MBASCHKLST->KEY_4_FMT;
    MBASCHKLST_N->KEY_5_FMT[0] = MBASCHKLST->KEY_5_FMT;
    MBASCHKLST_N->KEY_6_FMT[0] = MBASCHKLST->KEY_6_FMT;
    MBASCHKLST_N->KEY_7_FMT[0] = MBASCHKLST->KEY_7_FMT;
    MBASCHKLST_N->KEY_8_FMT[0] = MBASCHKLST->KEY_8_FMT;
    MBASCHKLST_N->KEY_9_FMT[0] = MBASCHKLST->KEY_9_FMT;
    MBASCHKLST_N->KEY_10_FMT[0] = MBASCHKLST->KEY_10_FMT;
    MEMCPY_AN(MBASCHKLST_N->KEY_1_TBL, MBASCHKLST->KEY_1_TBL, sizeof(MBASCHKLST->KEY_1_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_2_TBL, MBASCHKLST->KEY_2_TBL, sizeof(MBASCHKLST->KEY_2_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_3_TBL, MBASCHKLST->KEY_3_TBL, sizeof(MBASCHKLST->KEY_3_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_4_TBL, MBASCHKLST->KEY_4_TBL, sizeof(MBASCHKLST->KEY_4_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_5_TBL, MBASCHKLST->KEY_5_TBL, sizeof(MBASCHKLST->KEY_5_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_6_TBL, MBASCHKLST->KEY_6_TBL, sizeof(MBASCHKLST->KEY_6_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_7_TBL, MBASCHKLST->KEY_7_TBL, sizeof(MBASCHKLST->KEY_7_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_8_TBL, MBASCHKLST->KEY_8_TBL, sizeof(MBASCHKLST->KEY_8_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_9_TBL, MBASCHKLST->KEY_9_TBL, sizeof(MBASCHKLST->KEY_9_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_10_TBL, MBASCHKLST->KEY_10_TBL, sizeof(MBASCHKLST->KEY_10_TBL));
    MEMCPY_AN(MBASCHKLST_N->KEY_1_ITEM, MBASCHKLST->KEY_1_ITEM, sizeof(MBASCHKLST->KEY_1_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_2_ITEM, MBASCHKLST->KEY_2_ITEM, sizeof(MBASCHKLST->KEY_2_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_3_ITEM, MBASCHKLST->KEY_3_ITEM, sizeof(MBASCHKLST->KEY_3_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_4_ITEM, MBASCHKLST->KEY_4_ITEM, sizeof(MBASCHKLST->KEY_4_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_5_ITEM, MBASCHKLST->KEY_5_ITEM, sizeof(MBASCHKLST->KEY_5_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_6_ITEM, MBASCHKLST->KEY_6_ITEM, sizeof(MBASCHKLST->KEY_6_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_7_ITEM, MBASCHKLST->KEY_7_ITEM, sizeof(MBASCHKLST->KEY_7_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_8_ITEM, MBASCHKLST->KEY_8_ITEM, sizeof(MBASCHKLST->KEY_8_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_9_ITEM, MBASCHKLST->KEY_9_ITEM, sizeof(MBASCHKLST->KEY_9_ITEM));
    MEMCPY_AN(MBASCHKLST_N->KEY_10_ITEM, MBASCHKLST->KEY_10_ITEM, sizeof(MBASCHKLST->KEY_10_ITEM));
}


/* Del Null Function */
void DBC_del_null_mbaschklst(struct MBASCHKLST_N_TAG *MBASCHKLST_N, struct MBASCHKLST_TAG *MBASCHKLST)
{
    MEMCPY_DN(MBASCHKLST->CREATE_USER_ID, MBASCHKLST_N->CREATE_USER_ID, sizeof(MBASCHKLST->CREATE_USER_ID));
    MEMCPY_DN(MBASCHKLST->CREATE_TIME, MBASCHKLST_N->CREATE_TIME, sizeof(MBASCHKLST->CREATE_TIME));
    MEMCPY_DN(MBASCHKLST->UPDATE_USER_ID, MBASCHKLST_N->UPDATE_USER_ID, sizeof(MBASCHKLST->UPDATE_USER_ID));
    MEMCPY_DN(MBASCHKLST->UPDATE_TIME, MBASCHKLST_N->UPDATE_TIME, sizeof(MBASCHKLST->UPDATE_TIME));
    MEMCPY_DN(MBASCHKLST->FACTORY, MBASCHKLST_N->FACTORY, sizeof(MBASCHKLST->FACTORY));
    MEMCPY_DN(MBASCHKLST->CHKLIST_ID, MBASCHKLST_N->CHKLIST_ID, sizeof(MBASCHKLST->CHKLIST_ID));
    MEMCPY_DN(MBASCHKLST->CHKLIST_DESC, MBASCHKLST_N->CHKLIST_DESC, sizeof(MBASCHKLST->CHKLIST_DESC));
    MEMCPY_DN(MBASCHKLST->CHKLIST_TYPE, MBASCHKLST_N->CHKLIST_TYPE, sizeof(MBASCHKLST->CHKLIST_TYPE));
    MBASCHKLST->LOT_OR_RES_FLAG = MBASCHKLST_N->LOT_OR_RES_FLAG[0];
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_1, MBASCHKLST_N->CHKLIST_GRP_1, sizeof(MBASCHKLST->CHKLIST_GRP_1));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_2, MBASCHKLST_N->CHKLIST_GRP_2, sizeof(MBASCHKLST->CHKLIST_GRP_2));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_3, MBASCHKLST_N->CHKLIST_GRP_3, sizeof(MBASCHKLST->CHKLIST_GRP_3));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_4, MBASCHKLST_N->CHKLIST_GRP_4, sizeof(MBASCHKLST->CHKLIST_GRP_4));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_5, MBASCHKLST_N->CHKLIST_GRP_5, sizeof(MBASCHKLST->CHKLIST_GRP_5));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_6, MBASCHKLST_N->CHKLIST_GRP_6, sizeof(MBASCHKLST->CHKLIST_GRP_6));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_7, MBASCHKLST_N->CHKLIST_GRP_7, sizeof(MBASCHKLST->CHKLIST_GRP_7));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_8, MBASCHKLST_N->CHKLIST_GRP_8, sizeof(MBASCHKLST->CHKLIST_GRP_8));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_9, MBASCHKLST_N->CHKLIST_GRP_9, sizeof(MBASCHKLST->CHKLIST_GRP_9));
    MEMCPY_DN(MBASCHKLST->CHKLIST_GRP_10, MBASCHKLST_N->CHKLIST_GRP_10, sizeof(MBASCHKLST->CHKLIST_GRP_10));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_1, MBASCHKLST_N->CHKLIST_CMF_1, sizeof(MBASCHKLST->CHKLIST_CMF_1));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_2, MBASCHKLST_N->CHKLIST_CMF_2, sizeof(MBASCHKLST->CHKLIST_CMF_2));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_3, MBASCHKLST_N->CHKLIST_CMF_3, sizeof(MBASCHKLST->CHKLIST_CMF_3));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_4, MBASCHKLST_N->CHKLIST_CMF_4, sizeof(MBASCHKLST->CHKLIST_CMF_4));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_5, MBASCHKLST_N->CHKLIST_CMF_5, sizeof(MBASCHKLST->CHKLIST_CMF_5));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_6, MBASCHKLST_N->CHKLIST_CMF_6, sizeof(MBASCHKLST->CHKLIST_CMF_6));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_7, MBASCHKLST_N->CHKLIST_CMF_7, sizeof(MBASCHKLST->CHKLIST_CMF_7));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_8, MBASCHKLST_N->CHKLIST_CMF_8, sizeof(MBASCHKLST->CHKLIST_CMF_8));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_9, MBASCHKLST_N->CHKLIST_CMF_9, sizeof(MBASCHKLST->CHKLIST_CMF_9));
    MEMCPY_DN(MBASCHKLST->CHKLIST_CMF_10, MBASCHKLST_N->CHKLIST_CMF_10, sizeof(MBASCHKLST->CHKLIST_CMF_10));
    MEMCPY_DN(MBASCHKLST->KEY_1_PMT, MBASCHKLST_N->KEY_1_PMT, sizeof(MBASCHKLST->KEY_1_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_2_PMT, MBASCHKLST_N->KEY_2_PMT, sizeof(MBASCHKLST->KEY_2_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_3_PMT, MBASCHKLST_N->KEY_3_PMT, sizeof(MBASCHKLST->KEY_3_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_4_PMT, MBASCHKLST_N->KEY_4_PMT, sizeof(MBASCHKLST->KEY_4_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_5_PMT, MBASCHKLST_N->KEY_5_PMT, sizeof(MBASCHKLST->KEY_5_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_6_PMT, MBASCHKLST_N->KEY_6_PMT, sizeof(MBASCHKLST->KEY_6_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_7_PMT, MBASCHKLST_N->KEY_7_PMT, sizeof(MBASCHKLST->KEY_7_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_8_PMT, MBASCHKLST_N->KEY_8_PMT, sizeof(MBASCHKLST->KEY_8_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_9_PMT, MBASCHKLST_N->KEY_9_PMT, sizeof(MBASCHKLST->KEY_9_PMT));
    MEMCPY_DN(MBASCHKLST->KEY_10_PMT, MBASCHKLST_N->KEY_10_PMT, sizeof(MBASCHKLST->KEY_10_PMT));
    MBASCHKLST->KEY_1_REQ = MBASCHKLST_N->KEY_1_REQ[0];
    MBASCHKLST->KEY_2_REQ = MBASCHKLST_N->KEY_2_REQ[0];
    MBASCHKLST->KEY_3_REQ = MBASCHKLST_N->KEY_3_REQ[0];
    MBASCHKLST->KEY_4_REQ = MBASCHKLST_N->KEY_4_REQ[0];
    MBASCHKLST->KEY_5_REQ = MBASCHKLST_N->KEY_5_REQ[0];
    MBASCHKLST->KEY_6_REQ = MBASCHKLST_N->KEY_6_REQ[0];
    MBASCHKLST->KEY_7_REQ = MBASCHKLST_N->KEY_7_REQ[0];
    MBASCHKLST->KEY_8_REQ = MBASCHKLST_N->KEY_8_REQ[0];
    MBASCHKLST->KEY_9_REQ = MBASCHKLST_N->KEY_9_REQ[0];
    MBASCHKLST->KEY_10_REQ = MBASCHKLST_N->KEY_10_REQ[0];
    MBASCHKLST->KEY_1_FMT = MBASCHKLST_N->KEY_1_FMT[0];
    MBASCHKLST->KEY_2_FMT = MBASCHKLST_N->KEY_2_FMT[0];
    MBASCHKLST->KEY_3_FMT = MBASCHKLST_N->KEY_3_FMT[0];
    MBASCHKLST->KEY_4_FMT = MBASCHKLST_N->KEY_4_FMT[0];
    MBASCHKLST->KEY_5_FMT = MBASCHKLST_N->KEY_5_FMT[0];
    MBASCHKLST->KEY_6_FMT = MBASCHKLST_N->KEY_6_FMT[0];
    MBASCHKLST->KEY_7_FMT = MBASCHKLST_N->KEY_7_FMT[0];
    MBASCHKLST->KEY_8_FMT = MBASCHKLST_N->KEY_8_FMT[0];
    MBASCHKLST->KEY_9_FMT = MBASCHKLST_N->KEY_9_FMT[0];
    MBASCHKLST->KEY_10_FMT = MBASCHKLST_N->KEY_10_FMT[0];
    MEMCPY_DN(MBASCHKLST->KEY_1_TBL, MBASCHKLST_N->KEY_1_TBL, sizeof(MBASCHKLST->KEY_1_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_2_TBL, MBASCHKLST_N->KEY_2_TBL, sizeof(MBASCHKLST->KEY_2_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_3_TBL, MBASCHKLST_N->KEY_3_TBL, sizeof(MBASCHKLST->KEY_3_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_4_TBL, MBASCHKLST_N->KEY_4_TBL, sizeof(MBASCHKLST->KEY_4_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_5_TBL, MBASCHKLST_N->KEY_5_TBL, sizeof(MBASCHKLST->KEY_5_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_6_TBL, MBASCHKLST_N->KEY_6_TBL, sizeof(MBASCHKLST->KEY_6_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_7_TBL, MBASCHKLST_N->KEY_7_TBL, sizeof(MBASCHKLST->KEY_7_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_8_TBL, MBASCHKLST_N->KEY_8_TBL, sizeof(MBASCHKLST->KEY_8_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_9_TBL, MBASCHKLST_N->KEY_9_TBL, sizeof(MBASCHKLST->KEY_9_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_10_TBL, MBASCHKLST_N->KEY_10_TBL, sizeof(MBASCHKLST->KEY_10_TBL));
    MEMCPY_DN(MBASCHKLST->KEY_1_ITEM, MBASCHKLST_N->KEY_1_ITEM, sizeof(MBASCHKLST->KEY_1_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_2_ITEM, MBASCHKLST_N->KEY_2_ITEM, sizeof(MBASCHKLST->KEY_2_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_3_ITEM, MBASCHKLST_N->KEY_3_ITEM, sizeof(MBASCHKLST->KEY_3_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_4_ITEM, MBASCHKLST_N->KEY_4_ITEM, sizeof(MBASCHKLST->KEY_4_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_5_ITEM, MBASCHKLST_N->KEY_5_ITEM, sizeof(MBASCHKLST->KEY_5_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_6_ITEM, MBASCHKLST_N->KEY_6_ITEM, sizeof(MBASCHKLST->KEY_6_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_7_ITEM, MBASCHKLST_N->KEY_7_ITEM, sizeof(MBASCHKLST->KEY_7_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_8_ITEM, MBASCHKLST_N->KEY_8_ITEM, sizeof(MBASCHKLST->KEY_8_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_9_ITEM, MBASCHKLST_N->KEY_9_ITEM, sizeof(MBASCHKLST->KEY_9_ITEM));
    MEMCPY_DN(MBASCHKLST->KEY_10_ITEM, MBASCHKLST_N->KEY_10_ITEM, sizeof(MBASCHKLST->KEY_10_ITEM));
}


/* Initialize Function */
void DBC_init_mbaschklst_join(struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN)
{
    /* memset by Space */
    memset(MBASCHKLST_JOIN, ' ', sizeof(struct MBASCHKLST_JOIN_TAG));
    
    MBASCHKLST_JOIN->KEY_SEQ = 0;
    MBASCHKLST_JOIN->LOT_HIST_SEQ = 0;
    MBASCHKLST_JOIN->RES_HIST_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_mbaschklst_join(struct MBASCHKLST_JOIN_N_TAG *MBASCHKLST_JOIN_N, struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN)
{
    /* memset by NULL */
    memset(MBASCHKLST_JOIN_N, '\0', sizeof(struct MBASCHKLST_JOIN_N_TAG));
    
    MEMCPY_AN(MBASCHKLST_JOIN_N->FACTORY, MBASCHKLST_JOIN->FACTORY, sizeof(MBASCHKLST_JOIN->FACTORY));
    MEMCPY_AN(MBASCHKLST_JOIN_N->CHKLIST_ID, MBASCHKLST_JOIN->CHKLIST_ID, sizeof(MBASCHKLST_JOIN->CHKLIST_ID));
    MEMCPY_AN(MBASCHKLST_JOIN_N->LOT_ID, MBASCHKLST_JOIN->LOT_ID, sizeof(MBASCHKLST_JOIN->LOT_ID));
    MBASCHKLST_JOIN_N->LOT_HIST_SEQ = MBASCHKLST_JOIN->LOT_HIST_SEQ;
    MEMCPY_AN(MBASCHKLST_JOIN_N->RES_ID, MBASCHKLST_JOIN->RES_ID, sizeof(MBASCHKLST_JOIN->RES_ID));
    MBASCHKLST_JOIN_N->RES_HIST_SEQ = MBASCHKLST_JOIN->RES_HIST_SEQ;
    MBASCHKLST_JOIN_N->KEY_SEQ = MBASCHKLST_JOIN->KEY_SEQ;
    MBASCHKLST_JOIN_N->KEY_REQ[0] = MBASCHKLST_JOIN->KEY_REQ;
    MBASCHKLST_JOIN_N->KEY_FMT[0] = MBASCHKLST_JOIN->KEY_FMT;
    MEMCPY_AN(MBASCHKLST_JOIN_N->KEY_PMT, MBASCHKLST_JOIN->KEY_PMT, sizeof(MBASCHKLST_JOIN->KEY_PMT));
    MEMCPY_AN(MBASCHKLST_JOIN_N->KEY_TBL, MBASCHKLST_JOIN->KEY_TBL, sizeof(MBASCHKLST_JOIN->KEY_TBL));
    MEMCPY_AN(MBASCHKLST_JOIN_N->KEY_ITEM, MBASCHKLST_JOIN->KEY_ITEM, sizeof(MBASCHKLST_JOIN->KEY_ITEM));
    MEMCPY_AN(MBASCHKLST_JOIN_N->KEY_VALUE, MBASCHKLST_JOIN->KEY_VALUE, sizeof(MBASCHKLST_JOIN->KEY_VALUE));
}


/* Del Null Function */
void DBC_del_null_mbaschklst_join(struct MBASCHKLST_JOIN_N_TAG *MBASCHKLST_JOIN_N, struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN)
{
    MEMCPY_DN(MBASCHKLST_JOIN->FACTORY, MBASCHKLST_JOIN_N->FACTORY, sizeof(MBASCHKLST_JOIN->FACTORY));
    MEMCPY_DN(MBASCHKLST_JOIN->CHKLIST_ID, MBASCHKLST_JOIN_N->CHKLIST_ID, sizeof(MBASCHKLST_JOIN->CHKLIST_ID));
    MEMCPY_DN(MBASCHKLST_JOIN->LOT_ID, MBASCHKLST_JOIN_N->LOT_ID, sizeof(MBASCHKLST_JOIN->LOT_ID));
    MBASCHKLST_JOIN->LOT_HIST_SEQ = MBASCHKLST_JOIN_N->LOT_HIST_SEQ;
    MEMCPY_DN(MBASCHKLST_JOIN->RES_ID, MBASCHKLST_JOIN_N->RES_ID, sizeof(MBASCHKLST_JOIN->RES_ID));
    MBASCHKLST_JOIN->RES_HIST_SEQ = MBASCHKLST_JOIN_N->RES_HIST_SEQ;
    MBASCHKLST_JOIN->KEY_SEQ = MBASCHKLST_JOIN_N->KEY_SEQ;
    MBASCHKLST_JOIN->KEY_REQ = MBASCHKLST_JOIN_N->KEY_REQ[0];
    MBASCHKLST_JOIN->KEY_FMT = MBASCHKLST_JOIN_N->KEY_FMT[0];
    MEMCPY_DN(MBASCHKLST_JOIN->KEY_VALUE, MBASCHKLST_JOIN_N->KEY_VALUE, sizeof(MBASCHKLST_JOIN->KEY_VALUE));
    MEMCPY_DN(MBASCHKLST_JOIN->KEY_TBL, MBASCHKLST_JOIN_N->KEY_TBL, sizeof(MBASCHKLST_JOIN->KEY_TBL));
    MEMCPY_DN(MBASCHKLST_JOIN->KEY_ITEM, MBASCHKLST_JOIN_N->KEY_ITEM, sizeof(MBASCHKLST_JOIN->KEY_ITEM));
    MEMCPY_DN(MBASCHKLST_JOIN->KEY_VALUE, MBASCHKLST_JOIN_N->KEY_VALUE, sizeof(MBASCHKLST_JOIN->KEY_VALUE));
}

void DBC_select_checklist_key(int sel_type, struct MBASCHKLST_JOIN_TAG *MBASCHKLST_JOIN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MBASCHKLST_JOIN_N_TAG MBASCHKLST_JOIN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mbaschklst_join(&MBASCHKLST_JOIN_N, MBASCHKLST_JOIN);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    CASE :MBASCHKLST_JOIN_N.KEY_ITEM
                    WHEN 'LOT_ID' THEN LOT_ID
                    WHEN 'HIST_SEQ' THEN TO_CHAR(HIST_SEQ)
                    WHEN 'TRAN_TIME' THEN TRAN_TIME
                    WHEN 'SYS_TRAN_TIME' THEN SYS_TRAN_TIME
                    WHEN 'TRAN_CODE' THEN TRAN_CODE
                    WHEN 'LOT_DESC' THEN LOT_DESC
                    WHEN 'FACTORY' THEN FACTORY
                    WHEN 'MAT_ID' THEN MAT_ID
                    WHEN 'MAT_VER' THEN TO_CHAR(MAT_VER)
                    WHEN 'FLOW' THEN FLOW
                    WHEN 'FLOW_SEQ_NUM' THEN TO_CHAR(FLOW_SEQ_NUM)
                    WHEN 'OPER' THEN OPER
                    WHEN 'QTY_1' THEN TO_CHAR(QTY_1)
                    WHEN 'QTY_2' THEN TO_CHAR(QTY_2)
                    WHEN 'QTY_3' THEN TO_CHAR(QTY_3)
                    WHEN 'CRR_ID' THEN CRR_ID
                    WHEN 'LOT_TYPE' THEN LOT_TYPE
                    WHEN 'OWNER_CODE' THEN OWNER_CODE
                    WHEN 'CREATE_CODE' THEN CREATE_CODE
                    WHEN 'LOT_PRIORITY' THEN LOT_PRIORITY
                    WHEN 'LOT_STATUS' THEN LOT_STATUS
                    WHEN 'HOLD_FLAG' THEN HOLD_FLAG
                    WHEN 'HOLD_CODE' THEN HOLD_CODE
                    WHEN 'HOLD_PASSWORD' THEN HOLD_PASSWORD
                    WHEN 'HOLD_PRV_GRP_ID' THEN HOLD_PRV_GRP_ID
                    WHEN 'OPER_IN_QTY_1' THEN TO_CHAR(OPER_IN_QTY_1)
                    WHEN 'OPER_IN_QTY_2' THEN TO_CHAR(OPER_IN_QTY_2)
                    WHEN 'OPER_IN_QTY_3' THEN TO_CHAR(OPER_IN_QTY_3)
                    WHEN 'CREATE_QTY_1' THEN TO_CHAR(CREATE_QTY_1)
                    WHEN 'CREATE_QTY_2' THEN TO_CHAR(CREATE_QTY_2)
                    WHEN 'CREATE_QTY_3' THEN TO_CHAR(CREATE_QTY_3)
                    WHEN 'START_QTY_1' THEN TO_CHAR(START_QTY_1)
                    WHEN 'START_QTY_2' THEN TO_CHAR(START_QTY_2)
                    WHEN 'START_QTY_3' THEN TO_CHAR(START_QTY_3)
                    WHEN 'INV_FLAG' THEN INV_FLAG
                    WHEN 'TRANSIT_FLAG' THEN TRANSIT_FLAG
                    WHEN 'UNIT_EXIST_FLAG' THEN UNIT_EXIST_FLAG
                    WHEN 'INV_UNIT' THEN INV_UNIT
                    WHEN 'RWK_FLAG' THEN RWK_FLAG
                    WHEN 'RWK_CODE' THEN RWK_CODE
                    WHEN 'RWK_COUNT' THEN TO_CHAR(RWK_COUNT)
                    WHEN 'RWK_RET_FLOW' THEN RWK_RET_FLOW
                    WHEN 'RWK_RET_FLOW_SEQ_NUM' THEN TO_CHAR(RWK_RET_FLOW_SEQ_NUM)
                    WHEN 'RWK_RET_OPER' THEN RWK_RET_OPER
                    WHEN 'RWK_END_FLOW' THEN RWK_END_FLOW
                    WHEN 'RWK_END_FLOW_SEQ_NUM' THEN TO_CHAR(RWK_END_FLOW_SEQ_NUM)
                    WHEN 'RWK_END_OPER' THEN RWK_END_OPER
                    WHEN 'RWK_RET_CLEAR_FLAG' THEN RWK_RET_CLEAR_FLAG
                    WHEN 'RWK_TIME' THEN RWK_TIME
                    WHEN 'NSTD_FLAG' THEN NSTD_FLAG
                    WHEN 'NSTD_RET_FLOW' THEN NSTD_RET_FLOW
                    WHEN 'NSTD_RET_FLOW_SEQ_NUM' THEN TO_CHAR(NSTD_RET_FLOW_SEQ_NUM)
                    WHEN 'NSTD_RET_OPER' THEN NSTD_RET_OPER
                    WHEN 'NSTD_TIME' THEN NSTD_TIME
                    WHEN 'REP_FLAG' THEN REP_FLAG
                    WHEN 'REP_RET_OPER' THEN REP_RET_OPER
                    WHEN 'STR_RET_FLOW' THEN STR_RET_FLOW
                    WHEN 'STR_RET_FLOW_SEQ_NUM' THEN TO_CHAR(STR_RET_FLOW_SEQ_NUM)
                    WHEN 'STR_RET_OPER' THEN STR_RET_OPER
                    WHEN 'START_FLAG' THEN START_FLAG
                    WHEN 'START_TIME' THEN START_TIME
                    WHEN 'START_RES_ID' THEN START_RES_ID
                    WHEN 'END_FLAG' THEN END_FLAG
                    WHEN 'END_TIME' THEN END_TIME
                    WHEN 'END_RES_ID' THEN END_RES_ID
                    WHEN 'SAMPLE_FLAG' THEN SAMPLE_FLAG
                    WHEN 'SAMPLE_WAIT_FLAG' THEN SAMPLE_WAIT_FLAG
                    WHEN 'SAMPLE_RESULT' THEN SAMPLE_RESULT
                    WHEN 'FROM_TO_FLAG' THEN FROM_TO_FLAG
                    WHEN 'FROM_TO_LOT_ID' THEN FROM_TO_LOT_ID
                    WHEN 'SHIP_CODE' THEN SHIP_CODE
                    WHEN 'SHIP_TIME' THEN SHIP_TIME
                    WHEN 'ORG_DUE_TIME' THEN ORG_DUE_TIME
                    WHEN 'SCH_DUE_TIME' THEN SCH_DUE_TIME
                    WHEN 'CREATE_TIME' THEN CREATE_TIME
                    WHEN 'FAC_IN_TIME' THEN FAC_IN_TIME
                    WHEN 'FLOW_IN_TIME' THEN FLOW_IN_TIME
                    WHEN 'OPER_IN_TIME' THEN OPER_IN_TIME
                    WHEN 'RESERVE_RES_ID' THEN RESERVE_RES_ID
                    WHEN 'PORT_ID' THEN PORT_ID
                    WHEN 'BATCH_ID' THEN BATCH_ID
                    WHEN 'BATCH_SEQ' THEN TO_CHAR(BATCH_SEQ)
                    WHEN 'ORDER_ID' THEN ORDER_ID
                    WHEN 'ADD_ORDER_ID_1' THEN ADD_ORDER_ID_1
                    WHEN 'ADD_ORDER_ID_2' THEN ADD_ORDER_ID_2
                    WHEN 'ADD_ORDER_ID_3' THEN ADD_ORDER_ID_3
                    WHEN 'LOT_LOCATION_1' THEN LOT_LOCATION_1
                    WHEN 'LOT_LOCATION_2' THEN LOT_LOCATION_2
                    WHEN 'LOT_LOCATION_3' THEN LOT_LOCATION_3
                    WHEN 'LOT_CMF_1' THEN LOT_CMF_1
                    WHEN 'LOT_CMF_2' THEN LOT_CMF_2
                    WHEN 'LOT_CMF_3' THEN LOT_CMF_3
                    WHEN 'LOT_CMF_4' THEN LOT_CMF_4
                    WHEN 'LOT_CMF_5' THEN LOT_CMF_5
                    WHEN 'LOT_CMF_6' THEN LOT_CMF_6
                    WHEN 'LOT_CMF_7' THEN LOT_CMF_7
                    WHEN 'LOT_CMF_8' THEN LOT_CMF_8
                    WHEN 'LOT_CMF_9' THEN LOT_CMF_9
                    WHEN 'LOT_CMF_10' THEN LOT_CMF_10
                    WHEN 'LOT_CMF_11' THEN LOT_CMF_11
                    WHEN 'LOT_CMF_12' THEN LOT_CMF_12
                    WHEN 'LOT_CMF_13' THEN LOT_CMF_13
                    WHEN 'LOT_CMF_14' THEN LOT_CMF_14
                    WHEN 'LOT_CMF_15' THEN LOT_CMF_15
                    WHEN 'LOT_CMF_16' THEN LOT_CMF_16
                    WHEN 'LOT_CMF_17' THEN LOT_CMF_17
                    WHEN 'LOT_CMF_18' THEN LOT_CMF_18
                    WHEN 'LOT_CMF_19' THEN LOT_CMF_19
                    WHEN 'LOT_CMF_20' THEN LOT_CMF_20
                    WHEN 'LOT_DEL_FLAG' THEN LOT_DEL_FLAG
                    WHEN 'LOT_DEL_CODE' THEN LOT_DEL_CODE
                    WHEN 'LOT_DEL_TIME' THEN LOT_DEL_TIME
                    WHEN 'BOM_SET_ID' THEN BOM_SET_ID
                    WHEN 'BOM_SET_VERSION' THEN TO_CHAR(BOM_SET_VERSION)
                    WHEN 'BOM_ACTIVE_HIST_SEQ' THEN TO_CHAR(BOM_ACTIVE_HIST_SEQ)
                    WHEN 'BOM_HIST_SEQ' THEN TO_CHAR(BOM_HIST_SEQ)
                    WHEN 'CRITICAL_RES_ID' THEN CRITICAL_RES_ID
                    WHEN 'CRITICAL_RES_GROUP_ID' THEN CRITICAL_RES_GROUP_ID
                    WHEN 'SAVE_RES_ID_1' THEN SAVE_RES_ID_1
                    WHEN 'SAVE_RES_ID_2' THEN SAVE_RES_ID_2
                    WHEN 'SUBRES_ID' THEN SUBRES_ID
                    WHEN 'LOT_GROUP_ID_1' THEN LOT_GROUP_ID_1
                    WHEN 'LOT_GROUP_ID_2' THEN LOT_GROUP_ID_2
                    WHEN 'LOT_GROUP_ID_3' THEN LOT_GROUP_ID_3
                    WHEN 'YIELD_1' THEN TO_CHAR(YIELD_1)
                    WHEN 'YIELD_2' THEN TO_CHAR(YIELD_2)
                    WHEN 'YIELD_3' THEN TO_CHAR(YIELD_3)
                    WHEN 'GOOD_QTY' THEN TO_CHAR(GOOD_QTY)
                    WHEN 'RESV_FIELD_1' THEN RESV_FIELD_1
                    WHEN 'RESV_FIELD_2' THEN RESV_FIELD_2
                    WHEN 'RESV_FIELD_3' THEN RESV_FIELD_3
                    WHEN 'RESV_FIELD_4' THEN RESV_FIELD_4
                    WHEN 'RESV_FIELD_5' THEN RESV_FIELD_5
                    WHEN 'RESV_FLAG_1' THEN RESV_FLAG_1
                    WHEN 'RESV_FLAG_2' THEN RESV_FLAG_2
                    WHEN 'RESV_FLAG_3' THEN RESV_FLAG_3
                    WHEN 'RESV_FLAG_4' THEN RESV_FLAG_4
                    WHEN 'RESV_FLAG_5' THEN RESV_FLAG_5
                    WHEN 'FROM_TO_MAT_ID' THEN FROM_TO_MAT_ID
                    WHEN 'FROM_TO_MAT_VER' THEN TO_CHAR(FROM_TO_MAT_VER)
                    WHEN 'FROM_TO_FLOW' THEN FROM_TO_FLOW
                    WHEN 'FROM_TO_FLOW_SEQ_NUM' THEN TO_CHAR(FROM_TO_FLOW_SEQ_NUM)
                    WHEN 'FROM_TO_OPER' THEN FROM_TO_OPER
                    WHEN 'FROM_TO_QTY_1' THEN TO_CHAR(FROM_TO_QTY_1)
                    WHEN 'FROM_TO_QTY_2' THEN TO_CHAR(FROM_TO_QTY_2)
                    WHEN 'FROM_TO_QTY_3' THEN TO_CHAR(FROM_TO_QTY_3)
                    WHEN 'FROM_TO_HIST_SEQ' THEN TO_CHAR(FROM_TO_HIST_SEQ)
                    WHEN 'OLD_FACTORY' THEN OLD_FACTORY
                    WHEN 'OLD_MAT_ID' THEN OLD_MAT_ID
                    WHEN 'OLD_MAT_VER' THEN TO_CHAR(OLD_MAT_VER)
                    WHEN 'OLD_FLOW' THEN OLD_FLOW
                    WHEN 'OLD_FLOW_SEQ_NUM' THEN TO_CHAR(OLD_FLOW_SEQ_NUM)
                    WHEN 'OLD_OPER' THEN OLD_OPER
                    WHEN 'OLD_QTY_1' THEN TO_CHAR(OLD_QTY_1)
                    WHEN 'OLD_QTY_2' THEN TO_CHAR(OLD_QTY_2)
                    WHEN 'OLD_QTY_3' THEN TO_CHAR(OLD_QTY_3)
                    WHEN 'OLD_LOT_TYPE' THEN OLD_LOT_TYPE
                    WHEN 'OLD_OWNER_CODE' THEN OLD_OWNER_CODE
                    WHEN 'OLD_CREATE_CODE' THEN OLD_CREATE_CODE
                    WHEN 'OLD_FAC_IN_TIME' THEN OLD_FAC_IN_TIME
                    WHEN 'OLD_FLOW_IN_TIME' THEN OLD_FLOW_IN_TIME
                    WHEN 'OLD_OPER_IN_TIME' THEN OLD_OPER_IN_TIME
                    WHEN 'TRAN_CMF_1' THEN TRAN_CMF_1
                    WHEN 'TRAN_CMF_2' THEN TRAN_CMF_2
                    WHEN 'TRAN_CMF_3' THEN TRAN_CMF_3
                    WHEN 'TRAN_CMF_4' THEN TRAN_CMF_4
                    WHEN 'TRAN_CMF_5' THEN TRAN_CMF_5
                    WHEN 'TRAN_CMF_6' THEN TRAN_CMF_6
                    WHEN 'TRAN_CMF_7' THEN TRAN_CMF_7
                    WHEN 'TRAN_CMF_8' THEN TRAN_CMF_8
                    WHEN 'TRAN_CMF_9' THEN TRAN_CMF_9
                    WHEN 'TRAN_CMF_10' THEN TRAN_CMF_10
                    WHEN 'TRAN_CMF_11' THEN TRAN_CMF_11
                    WHEN 'TRAN_CMF_12' THEN TRAN_CMF_12
                    WHEN 'TRAN_CMF_13' THEN TRAN_CMF_13
                    WHEN 'TRAN_CMF_14' THEN TRAN_CMF_14
                    WHEN 'TRAN_CMF_15' THEN TRAN_CMF_15
                    WHEN 'TRAN_CMF_16' THEN TRAN_CMF_16
                    WHEN 'TRAN_CMF_17' THEN TRAN_CMF_17
                    WHEN 'TRAN_CMF_18' THEN TRAN_CMF_18
                    WHEN 'TRAN_CMF_19' THEN TRAN_CMF_19
                    WHEN 'TRAN_CMF_20' THEN TRAN_CMF_20
                    WHEN 'TRAN_USER_ID' THEN TRAN_USER_ID
                    WHEN 'TRAN_COMMENT' THEN TRAN_COMMENT
                    WHEN 'PREV_ACTIVE_HIST_SEQ' THEN TO_CHAR(PREV_ACTIVE_HIST_SEQ)
                    WHEN 'MULTI_TR_KEY' THEN MULTI_TR_KEY
                    WHEN 'MULTI_TR_SEQ' THEN TO_CHAR(MULTI_TR_SEQ)
                    WHEN 'EXT_HIST_SEQ' THEN TO_CHAR(EXT_HIST_SEQ)
                    WHEN 'HIST_DEL_FLAG' THEN HIST_DEL_FLAG
                    WHEN 'HIST_DEL_TIME' THEN HIST_DEL_TIME
                    WHEN 'HIST_DEL_USER_ID' THEN HIST_DEL_USER_ID
                    WHEN 'HIST_DEL_COMMENT' THEN HIST_DEL_COMMENT
                    ELSE ' '
                    END 
                INTO 
                    :MBASCHKLST_JOIN_N.KEY_VALUE
                FROM MWIPLOTHIS
                WHERE FACTORY = :MBASCHKLST_JOIN_N.FACTORY
                    AND LOT_ID = :MBASCHKLST_JOIN_N.LOT_ID
                    AND HIST_SEQ = :MBASCHKLST_JOIN_N.LOT_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select  case :b0 when 'LOT_ID' then LOT_ID when 'HIST_SEQ' th\
en TO_CHAR(HIST_SEQ) when 'TRAN_TIME' then TRAN_TIME when 'SYS_TRAN_TIME' th\
en SYS_TRAN_TIME when 'TRAN_CODE' then TRAN_CODE when 'LOT_DESC' then LOT_DE\
SC when 'FACTORY' then FACTORY when 'MAT_ID' then MAT_ID when 'MAT_VER' then\
 TO_CHAR(MAT_VER) when 'FLOW' then FLOW when 'FLOW_SEQ_NUM' then TO_CHAR(FLO\
W_SEQ_NUM) when 'OPER' then OPER when 'QTY_1' then TO_CHAR(QTY_1) when 'QTY_\
2' then TO_CHAR(QTY_2) when 'QTY_3' then TO_CHAR(QTY_3) when 'CRR_ID' then C\
RR_ID when 'LOT_TYPE' then LOT_TYPE when 'OWNER_CODE' then OWNER_CODE when '\
CREATE_CODE' then CREATE_CODE when 'LOT_PRIORITY' then LOT_PRIORITY when 'LO\
T_STATUS' then LOT_STATUS when 'HOLD_FLAG' then HOLD_FLAG when 'HOLD_CODE' t\
hen HOLD_CODE when 'HOLD_PASSWORD' then HOLD_PASSWORD when 'HOLD_PRV_GRP_ID'\
 then HOLD_PRV_GRP_ID when 'OPER_IN_QTY_1' then TO_CHAR(OPER_IN_QTY_1) when \
'OPER_IN_QTY_2' then TO_CHAR(OPER_IN_QTY_2) when 'OPER_IN_QTY_3' then TO_CHA\
R(OPER_IN_QTY_3) when 'CREATE_QTY_1' then TO_CHAR(C");
            sqlbuft((void **)0,
              "REATE_QTY_1) when 'CREATE_QTY_2' then TO_CHAR(CREATE_QTY_2) w\
hen 'CREATE_QTY_3' then TO_CHAR(CREATE_QTY_3) when 'START_QTY_1' then TO_CHA\
R(START_QTY_1) when 'START_QTY_2' then TO_CHAR(START_QTY_2) when 'START_QTY_\
3' then TO_CHAR(START_QTY_3) when 'INV_FLAG' then INV_FLAG when 'TRANSIT_FLA\
G' then TRANSIT_FLAG when 'UNIT_EXIST_FLAG' then UNIT_EXIST_FLAG when 'INV_U\
NIT' then INV_UNIT when 'RWK_FLAG' then RWK_FLAG when 'RWK_CODE' then RWK_CO\
DE when 'RWK_COUNT' then TO_CHAR(RWK_COUNT) when 'RWK_RET_FLOW' then RWK_RET\
_FLOW when 'RWK_RET_FLOW_SEQ_NUM' then TO_CHAR(RWK_RET_FLOW_SEQ_NUM) when 'R\
WK_RET_OPER' then RWK_RET_OPER when 'RWK_END_FLOW' then RWK_END_FLOW when 'R\
WK_END_FLOW_SEQ_NUM' then TO_CHAR(RWK_END_FLOW_SEQ_NUM) when 'RWK_END_OPER' \
then RWK_END_OPER when 'RWK_RET_CLEAR_FLAG' then RWK_RET_CLEAR_FLAG when 'RW\
K_TIME' then RWK_TIME when 'NSTD_FLAG' then NSTD_FLAG when 'NSTD_RET_FLOW' t\
hen NSTD_RET_FLOW when 'NSTD_RET_FLOW_SEQ_NUM' then TO_CHAR(NSTD_RET_FLOW_SE\
Q_NUM) when 'NSTD_RET_OPER' then NSTD_RET_OPER when");
            sqlbuft((void **)0,
              " 'NSTD_TIME' then NSTD_TIME when 'REP_FLAG' then REP_FLAG whe\
n 'REP_RET_OPER' then REP_RET_OPER when 'STR_RET_FLOW' then STR_RET_FLOW whe\
n 'STR_RET_FLOW_SEQ_NUM' then TO_CHAR(STR_RET_FLOW_SEQ_NUM) when 'STR_RET_OP\
ER' then STR_RET_OPER when 'START_FLAG' then START_FLAG when 'START_TIME' th\
en START_TIME when 'START_RES_ID' then START_RES_ID when 'END_FLAG' then END\
_FLAG when 'END_TIME' then END_TIME when 'END_RES_ID' then END_RES_ID when '\
SAMPLE_FLAG' then SAMPLE_FLAG when 'SAMPLE_WAIT_FLAG' then SAMPLE_WAIT_FLAG \
when 'SAMPLE_RESULT' then SAMPLE_RESULT when 'FROM_TO_FLAG' then FROM_TO_FLA\
G when 'FROM_TO_LOT_ID' then FROM_TO_LOT_ID when 'SHIP_CODE' then SHIP_CODE \
when 'SHIP_TIME' then SHIP_TIME when 'ORG_DUE_TIME' then ORG_DUE_TIME when '\
SCH_DUE_TIME' then SCH_DUE_TIME when 'CREATE_TIME' then CREATE_TIME when 'FA\
C_IN_TIME' then FAC_IN_TIME when 'FLOW_IN_TIME' then FLOW_IN_TIME when 'OPER\
_IN_TIME' then OPER_IN_TIME when 'RESERVE_RES_ID' then RESERVE_RES_ID when '\
PORT_ID' then PORT_ID when 'BATCH_ID' then BATCH_ID");
            sqlbuft((void **)0,
              " when 'BATCH_SEQ' then TO_CHAR(BATCH_SEQ) when 'ORDER_ID' the\
n ORDER_ID when 'ADD_ORDER_ID_1' then ADD_ORDER_ID_1 when 'ADD_ORDER_ID_2' t\
hen ADD_ORDER_ID_2 when 'ADD_ORDER_ID_3' then ADD_ORDER_ID_3 when 'LOT_LOCAT\
ION_1' then LOT_LOCATION_1 when 'LOT_LOCATION_2' then LOT_LOCATION_2 when 'L\
OT_LOCATION_3' then LOT_LOCATION_3 when 'LOT_CMF_1' then LOT_CMF_1 when 'LOT\
_CMF_2' then LOT_CMF_2 when 'LOT_CMF_3' then LOT_CMF_3 when 'LOT_CMF_4' then\
 LOT_CMF_4 when 'LOT_CMF_5' then LOT_CMF_5 when 'LOT_CMF_6' then LOT_CMF_6 w\
hen 'LOT_CMF_7' then LOT_CMF_7 when 'LOT_CMF_8' then LOT_CMF_8 when 'LOT_CMF\
_9' then LOT_CMF_9 when 'LOT_CMF_10' then LOT_CMF_10 when 'LOT_CMF_11' then \
LOT_CMF_11 when 'LOT_CMF_12' then LOT_CMF_12 when 'LOT_CMF_13' then LOT_CMF_\
13 when 'LOT_CMF_14' then LOT_CMF_14 when 'LOT_CMF_15' then LOT_CMF_15 when \
'LOT_CMF_16' then LOT_CMF_16 when 'LOT_CMF_17' then LOT_CMF_17 when 'LOT_CMF\
_18' then LOT_CMF_18 when 'LOT_CMF_19' then LOT_CMF_19 when 'LOT_CMF_20' the\
n LOT_CMF_20 when 'LOT_DEL_FLAG' then LOT_DEL_FLAG ");
            sqlbuft((void **)0,
              "when 'LOT_DEL_CODE' then LOT_DEL_CODE when 'LOT_DEL_TIME' the\
n LOT_DEL_TIME when 'BOM_SET_ID' then BOM_SET_ID when 'BOM_SET_VERSION' then\
 TO_CHAR(BOM_SET_VERSION) when 'BOM_ACTIVE_HIST_SEQ' then TO_CHAR(BOM_ACTIVE\
_HIST_SEQ) when 'BOM_HIST_SEQ' then TO_CHAR(BOM_HIST_SEQ) when 'CRITICAL_RES\
_ID' then CRITICAL_RES_ID when 'CRITICAL_RES_GROUP_ID' then CRITICAL_RES_GRO\
UP_ID when 'SAVE_RES_ID_1' then SAVE_RES_ID_1 when 'SAVE_RES_ID_2' then SAVE\
_RES_ID_2 when 'SUBRES_ID' then SUBRES_ID when 'LOT_GROUP_ID_1' then LOT_GRO\
UP_ID_1 when 'LOT_GROUP_ID_2' then LOT_GROUP_ID_2 when 'LOT_GROUP_ID_3' then\
 LOT_GROUP_ID_3 when 'YIELD_1' then TO_CHAR(YIELD_1) when 'YIELD_2' then TO_\
CHAR(YIELD_2) when 'YIELD_3' then TO_CHAR(YIELD_3) when 'GOOD_QTY' then TO_C\
HAR(GOOD_QTY) when 'RESV_FIELD_1' then RESV_FIELD_1 when 'RESV_FIELD_2' then\
 RESV_FIELD_2 when 'RESV_FIELD_3' then RESV_FIELD_3 when 'RESV_FIELD_4' then\
 RESV_FIELD_4 when 'RESV_FIELD_5' then RESV_FIELD_5 when 'RESV_FLAG_1' then \
RESV_FLAG_1 when 'RESV_FLAG_2' then RESV_FLAG_2 whe");
            sqlbuft((void **)0,
              "n 'RESV_FLAG_3' then RESV_FLAG_3 when 'RESV_FLAG_4' then RESV\
_FLAG_4 when 'RESV_FLAG_5' then RESV_FLAG_5 when 'FROM_TO_MAT_ID' then FROM_\
TO_MAT_ID when 'FROM_TO_MAT_VER' then TO_CHAR(FROM_TO_MAT_VER) when 'FROM_TO\
_FLOW' then FROM_TO_FLOW when 'FROM_TO_FLOW_SEQ_NUM' then TO_CHAR(FROM_TO_FL\
OW_SEQ_NUM) when 'FROM_TO_OPER' then FROM_TO_OPER when 'FROM_TO_QTY_1' then \
TO_CHAR(FROM_TO_QTY_1) when 'FROM_TO_QTY_2' then TO_CHAR(FROM_TO_QTY_2) when\
 'FROM_TO_QTY_3' then TO_CHAR(FROM_TO_QTY_3) when 'FROM_TO_HIST_SEQ' then TO\
_CHAR(FROM_TO_HIST_SEQ) when 'OLD_FACTORY' then OLD_FACTORY when 'OLD_MAT_ID\
' then OLD_MAT_ID when 'OLD_MAT_VER' then TO_CHAR(OLD_MAT_VER) when 'OLD_FLO\
W' then OLD_FLOW when 'OLD_FLOW_SEQ_NUM' then TO_CHAR(OLD_FLOW_SEQ_NUM) when\
 'OLD_OPER' then OLD_OPER when 'OLD_QTY_1' then TO_CHAR(OLD_QTY_1) when 'OLD\
_QTY_2' then TO_CHAR(OLD_QTY_2) when 'OLD_QTY_3' then TO_CHAR(OLD_QTY_3) whe\
n 'OLD_LOT_TYPE' then OLD_LOT_TYPE when 'OLD_OWNER_CODE' then OLD_OWNER_CODE\
 when 'OLD_CREATE_CODE' then OLD_CREATE_CODE when '");
            sqlbuft((void **)0,
              "OLD_FAC_IN_TIME' then OLD_FAC_IN_TIME when 'OLD_FLOW_IN_TIME'\
 then OLD_FLOW_IN_TIME when 'OLD_OPER_IN_TIME' then OLD_OPER_IN_TIME when 'T\
RAN_CMF_1' then TRAN_CMF_1 when 'TRAN_CMF_2' then TRAN_CMF_2 when 'TRAN_CMF_\
3' then TRAN_CMF_3 when 'TRAN_CMF_4' then TRAN_CMF_4 when 'TRAN_CMF_5' then \
TRAN_CMF_5 when 'TRAN_CMF_6' then TRAN_CMF_6 when 'TRAN_CMF_7' then TRAN_CMF\
_7 when 'TRAN_CMF_8' then TRAN_CMF_8 when 'TRAN_CMF_9' then TRAN_CMF_9 when \
'TRAN_CMF_10' then TRAN_CMF_10 when 'TRAN_CMF_11' then TRAN_CMF_11 when 'TRA\
N_CMF_12' then TRAN_CMF_12 when 'TRAN_CMF_13' then TRAN_CMF_13 when 'TRAN_CM\
F_14' then TRAN_CMF_14 when 'TRAN_CMF_15' then TRAN_CMF_15 when 'TRAN_CMF_16\
' then TRAN_CMF_16 when 'TRAN_CMF_17' then TRAN_CMF_17 when 'TRAN_CMF_18' th\
en TRAN_CMF_18 when 'TRAN_CMF_19' then TRAN_CMF_19 when 'TRAN_CMF_20' then T\
RAN_CMF_20 when 'TRAN_USER_ID' then TRAN_USER_ID when 'TRAN_COMMENT' then TR\
AN_COMMENT when 'PREV_ACTIVE_HIST_SEQ' then TO_CHAR(PREV_ACTIVE_HIST_SEQ) wh\
en 'MULTI_TR_KEY' then MULTI_TR_KEY when 'MULTI_TR_");
            sqlstm.stmt = "SEQ' then TO_CHAR(MULTI_TR_SEQ) when 'EXT_HIST_S\
EQ' then TO_CHAR(EXT_HIST_SEQ) when 'HIST_DEL_FLAG' then HIST_DEL_FLAG when '\
HIST_DEL_TIME' then HIST_DEL_TIME when 'HIST_DEL_USER_ID' then HIST_DEL_USER_\
ID when 'HIST_DEL_COMMENT' then HIST_DEL_COMMENT else ' '  end  into :b1  fro\
m MWIPLOTHIS where ((FACTORY=:b2 and LOT_ID=:b3) and HIST_SEQ=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2498;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_JOIN_N.KEY_ITEM);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_JOIN_N.KEY_VALUE);
            sqlstm.sqhstl[1] = (unsigned int  )101;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_JOIN_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_JOIN_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MBASCHKLST_JOIN_N.LOT_HIST_SEQ);
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
            /* EXEC SQL SELECT 
                    CASE :MBASCHKLST_JOIN_N.KEY_ITEM
                    WHEN 'FACTORY' THEN FACTORY
                    WHEN 'RES_ID' THEN RES_ID
                    WHEN 'RES_DESC' THEN RES_DESC
                    WHEN 'RES_TYPE' THEN RES_TYPE
                    WHEN 'RES_GRP_1' THEN RES_GRP_1
                    WHEN 'RES_GRP_2' THEN RES_GRP_2
                    WHEN 'RES_GRP_3' THEN RES_GRP_3
                    WHEN 'RES_GRP_4' THEN RES_GRP_4
                    WHEN 'RES_GRP_5' THEN RES_GRP_5
                    WHEN 'RES_GRP_6' THEN RES_GRP_6
                    WHEN 'RES_GRP_7' THEN RES_GRP_7
                    WHEN 'RES_GRP_8' THEN RES_GRP_8
                    WHEN 'RES_GRP_9' THEN RES_GRP_9
                    WHEN 'RES_GRP_10' THEN RES_GRP_10
                    WHEN 'USE_FAC_PRT_FLAG' THEN USE_FAC_PRT_FLAG
                    WHEN 'RES_STS_PRT_1' THEN RES_STS_PRT_1
                    WHEN 'RES_STS_PRT_2' THEN RES_STS_PRT_2
                    WHEN 'RES_STS_PRT_3' THEN RES_STS_PRT_3
                    WHEN 'RES_STS_PRT_4' THEN RES_STS_PRT_4
                    WHEN 'RES_STS_PRT_5' THEN RES_STS_PRT_5
                    WHEN 'RES_STS_PRT_6' THEN RES_STS_PRT_6
                    WHEN 'RES_STS_PRT_7' THEN RES_STS_PRT_7
                    WHEN 'RES_STS_PRT_8' THEN RES_STS_PRT_8
                    WHEN 'RES_STS_PRT_9' THEN RES_STS_PRT_9
                    WHEN 'RES_STS_PRT_10' THEN RES_STS_PRT_10
                    WHEN 'RES_CMF_1' THEN RES_CMF_1
                    WHEN 'RES_CMF_2' THEN RES_CMF_2
                    WHEN 'RES_CMF_3' THEN RES_CMF_3
                    WHEN 'RES_CMF_4' THEN RES_CMF_4
                    WHEN 'RES_CMF_5' THEN RES_CMF_5
                    WHEN 'RES_CMF_6' THEN RES_CMF_6
                    WHEN 'RES_CMF_7' THEN RES_CMF_7
                    WHEN 'RES_CMF_8' THEN RES_CMF_8
                    WHEN 'RES_CMF_9' THEN RES_CMF_9
                    WHEN 'RES_CMF_10' THEN RES_CMF_10
                    WHEN 'RES_CMF_11' THEN RES_CMF_11
                    WHEN 'RES_CMF_12' THEN RES_CMF_12
                    WHEN 'RES_CMF_13' THEN RES_CMF_13
                    WHEN 'RES_CMF_14' THEN RES_CMF_14
                    WHEN 'RES_CMF_15' THEN RES_CMF_15
                    WHEN 'RES_CMF_16' THEN RES_CMF_16
                    WHEN 'RES_CMF_17' THEN RES_CMF_17
                    WHEN 'RES_CMF_18' THEN RES_CMF_18
                    WHEN 'RES_CMF_19' THEN RES_CMF_19
                    WHEN 'RES_CMF_20' THEN RES_CMF_20
                    WHEN 'AREA_ID' THEN AREA_ID
                    WHEN 'SUB_AREA_ID' THEN SUB_AREA_ID
                    WHEN 'RES_LOCATION' THEN RES_LOCATION
                    WHEN 'PROC_RULE' THEN PROC_RULE
                    WHEN 'MAX_PROC_COUNT' THEN TO_CHAR(MAX_PROC_COUNT)
                    WHEN 'BATCH_COND_1' THEN BATCH_COND_1
                    WHEN 'BATCH_COND_2' THEN BATCH_COND_2
                    WHEN 'PM_SCH_ENABLE_FLAG' THEN PM_SCH_ENABLE_FLAG
                    WHEN 'UNIT_BASE_ST_FLAG' THEN UNIT_BASE_ST_FLAG
                    WHEN 'SEC_CHK_FLAG' THEN SEC_CHK_FLAG
                    WHEN 'GATHER_ALARM_FLAG' THEN GATHER_ALARM_FLAG
                    WHEN 'DELETE_FLAG' THEN DELETE_FLAG
                    WHEN 'DELETE_USER_ID' THEN DELETE_USER_ID
                    WHEN 'DELETE_TIME' THEN DELETE_TIME
                    WHEN 'CREATE_USER_ID' THEN CREATE_USER_ID
                    WHEN 'CREATE_TIME' THEN CREATE_TIME
                    WHEN 'UPDATE_USER_ID' THEN UPDATE_USER_ID
                    WHEN 'UPDATE_TIME' THEN UPDATE_TIME
                    WHEN 'RES_UP_DOWN_FLAG' THEN RES_UP_DOWN_FLAG
                    WHEN 'RES_PRI_STS' THEN RES_PRI_STS
                    WHEN 'RES_STS_1' THEN RES_STS_1
                    WHEN 'RES_STS_2' THEN RES_STS_2
                    WHEN 'RES_STS_3' THEN RES_STS_3
                    WHEN 'RES_STS_4' THEN RES_STS_4
                    WHEN 'RES_STS_5' THEN RES_STS_5
                    WHEN 'RES_STS_6' THEN RES_STS_6
                    WHEN 'RES_STS_7' THEN RES_STS_7
                    WHEN 'RES_STS_8' THEN RES_STS_8
                    WHEN 'RES_STS_9' THEN RES_STS_9
                    WHEN 'RES_STS_10' THEN RES_STS_10
                    WHEN 'LOT_ID' THEN LOT_ID
                    WHEN 'SUBLOT_ID' THEN SUBLOT_ID
                    WHEN 'CRR_ID' THEN CRR_ID
                    WHEN 'RES_CTRL_MODE' THEN RES_CTRL_MODE
                    WHEN 'RES_PROC_MODE' THEN RES_PROC_MODE
                    WHEN 'LAST_RECIPE_ID' THEN LAST_RECIPE_ID
                    WHEN 'PROC_COUNT' THEN TO_CHAR(PROC_COUNT)
                    WHEN 'LAST_START_TIME' THEN LAST_START_TIME
                    WHEN 'LAST_END_TIME' THEN LAST_END_TIME
                    WHEN 'LAST_DOWN_TIME' THEN LAST_DOWN_TIME
                    WHEN 'LAST_DOWN_HIST_SEQ' THEN TO_CHAR(LAST_DOWN_HIST_SEQ)
                    WHEN 'LAST_EVENT_ID' THEN LAST_EVENT_ID
                    WHEN 'LAST_EVENT_TIME' THEN LAST_EVENT_TIME
                    WHEN 'LAST_ACTIVE_HIST_SEQ' THEN TO_CHAR(LAST_ACTIVE_HIST_SEQ)
                    WHEN 'LAST_HIST_SEQ' THEN TO_CHAR(LAST_HIST_SEQ)
                    WHEN 'RES_SHORT_DESC' THEN RES_SHORT_DESC
                    ELSE ' '
                    END 
                INTO 
                    :MBASCHKLST_JOIN_N.KEY_VALUE
                FROM MRASRESDEF
                WHERE FACTORY = :MBASCHKLST_JOIN_N.FACTORY
                    AND RES_ID = :MBASCHKLST_JOIN_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select  case :b0 when 'FACTORY' then FACTORY when 'RES_ID' th\
en RES_ID when 'RES_DESC' then RES_DESC when 'RES_TYPE' then RES_TYPE when '\
RES_GRP_1' then RES_GRP_1 when 'RES_GRP_2' then RES_GRP_2 when 'RES_GRP_3' t\
hen RES_GRP_3 when 'RES_GRP_4' then RES_GRP_4 when 'RES_GRP_5' then RES_GRP_\
5 when 'RES_GRP_6' then RES_GRP_6 when 'RES_GRP_7' then RES_GRP_7 when 'RES_\
GRP_8' then RES_GRP_8 when 'RES_GRP_9' then RES_GRP_9 when 'RES_GRP_10' then\
 RES_GRP_10 when 'USE_FAC_PRT_FLAG' then USE_FAC_PRT_FLAG when 'RES_STS_PRT_\
1' then RES_STS_PRT_1 when 'RES_STS_PRT_2' then RES_STS_PRT_2 when 'RES_STS_\
PRT_3' then RES_STS_PRT_3 when 'RES_STS_PRT_4' then RES_STS_PRT_4 when 'RES_\
STS_PRT_5' then RES_STS_PRT_5 when 'RES_STS_PRT_6' then RES_STS_PRT_6 when '\
RES_STS_PRT_7' then RES_STS_PRT_7 when 'RES_STS_PRT_8' then RES_STS_PRT_8 wh\
en 'RES_STS_PRT_9' then RES_STS_PRT_9 when 'RES_STS_PRT_10' then RES_STS_PRT\
_10 when 'RES_CMF_1' then RES_CMF_1 when 'RES_CMF_2' then RES_CMF_2 when 'RE\
S_CMF_3' then RES_CMF_3 when 'RES_CMF_4' then RES_C");
            sqlbuft((void **)0,
              "MF_4 when 'RES_CMF_5' then RES_CMF_5 when 'RES_CMF_6' then RE\
S_CMF_6 when 'RES_CMF_7' then RES_CMF_7 when 'RES_CMF_8' then RES_CMF_8 when\
 'RES_CMF_9' then RES_CMF_9 when 'RES_CMF_10' then RES_CMF_10 when 'RES_CMF_\
11' then RES_CMF_11 when 'RES_CMF_12' then RES_CMF_12 when 'RES_CMF_13' then\
 RES_CMF_13 when 'RES_CMF_14' then RES_CMF_14 when 'RES_CMF_15' then RES_CMF\
_15 when 'RES_CMF_16' then RES_CMF_16 when 'RES_CMF_17' then RES_CMF_17 when\
 'RES_CMF_18' then RES_CMF_18 when 'RES_CMF_19' then RES_CMF_19 when 'RES_CM\
F_20' then RES_CMF_20 when 'AREA_ID' then AREA_ID when 'SUB_AREA_ID' then SU\
B_AREA_ID when 'RES_LOCATION' then RES_LOCATION when 'PROC_RULE' then PROC_R\
ULE when 'MAX_PROC_COUNT' then TO_CHAR(MAX_PROC_COUNT) when 'BATCH_COND_1' t\
hen BATCH_COND_1 when 'BATCH_COND_2' then BATCH_COND_2 when 'PM_SCH_ENABLE_F\
LAG' then PM_SCH_ENABLE_FLAG when 'UNIT_BASE_ST_FLAG' then UNIT_BASE_ST_FLAG\
 when 'SEC_CHK_FLAG' then SEC_CHK_FLAG when 'GATHER_ALARM_FLAG' then GATHER_\
ALARM_FLAG when 'DELETE_FLAG' then DELETE_FLAG when");
            sqlbuft((void **)0,
              " 'DELETE_USER_ID' then DELETE_USER_ID when 'DELETE_TIME' then\
 DELETE_TIME when 'CREATE_USER_ID' then CREATE_USER_ID when 'CREATE_TIME' th\
en CREATE_TIME when 'UPDATE_USER_ID' then UPDATE_USER_ID when 'UPDATE_TIME' \
then UPDATE_TIME when 'RES_UP_DOWN_FLAG' then RES_UP_DOWN_FLAG when 'RES_PRI\
_STS' then RES_PRI_STS when 'RES_STS_1' then RES_STS_1 when 'RES_STS_2' then\
 RES_STS_2 when 'RES_STS_3' then RES_STS_3 when 'RES_STS_4' then RES_STS_4 w\
hen 'RES_STS_5' then RES_STS_5 when 'RES_STS_6' then RES_STS_6 when 'RES_STS\
_7' then RES_STS_7 when 'RES_STS_8' then RES_STS_8 when 'RES_STS_9' then RES\
_STS_9 when 'RES_STS_10' then RES_STS_10 when 'LOT_ID' then LOT_ID when 'SUB\
LOT_ID' then SUBLOT_ID when 'CRR_ID' then CRR_ID when 'RES_CTRL_MODE' then R\
ES_CTRL_MODE when 'RES_PROC_MODE' then RES_PROC_MODE when 'LAST_RECIPE_ID' t\
hen LAST_RECIPE_ID when 'PROC_COUNT' then TO_CHAR(PROC_COUNT) when 'LAST_STA\
RT_TIME' then LAST_START_TIME when 'LAST_END_TIME' then LAST_END_TIME when '\
LAST_DOWN_TIME' then LAST_DOWN_TIME when 'LAST_DOWN");
            sqlstm.stmt = "_HIST_SEQ' then TO_CHAR(LAST_DOWN_HIST_SEQ) when\
 'LAST_EVENT_ID' then LAST_EVENT_ID when 'LAST_EVENT_TIME' then LAST_EVENT_TI\
ME when 'LAST_ACTIVE_HIST_SEQ' then TO_CHAR(LAST_ACTIVE_HIST_SEQ) when 'LAST_\
HIST_SEQ' then TO_CHAR(LAST_HIST_SEQ) when 'RES_SHORT_DESC' then RES_SHORT_DE\
SC else ' '  end  into :b1  from MRASRESDEF where (FACTORY=:b2 and RES_ID=:b3\
)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2533;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_JOIN_N.KEY_ITEM);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_JOIN_N.KEY_VALUE);
            sqlstm.sqhstl[1] = (unsigned int  )101;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_JOIN_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_JOIN_N.RES_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
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

        case 3:
            /* EXEC SQL SELECT ATTR_VALUE
                INTO 
                    :MBASCHKLST_JOIN_N.KEY_VALUE
                FROM MATRNAMSTS
                WHERE FACTORY = :MBASCHKLST_JOIN_N.FACTORY
                    AND ATTR_TYPE = 'LOT'
                    AND ATTR_NAME = :MBASCHKLST_JOIN_N.KEY_ITEM
                    AND ATTR_KEY = :MBASCHKLST_JOIN_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ATTR_VALUE into :b0  from MATRNAMSTS wher\
e (((FACTORY=:b1 and ATTR_TYPE='LOT') and ATTR_NAME=:b2) and ATTR_KEY=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2564;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_JOIN_N.KEY_VALUE);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_JOIN_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_JOIN_N.KEY_ITEM);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_JOIN_N.LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
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

        case 4:
            /* EXEC SQL SELECT ATTR_VALUE
                INTO 
                    :MBASCHKLST_JOIN_N.KEY_VALUE
                FROM MATRNAMSTS
                WHERE FACTORY = :MBASCHKLST_JOIN_N.FACTORY
                    AND ATTR_TYPE = 'RES'
                    AND ATTR_NAME = :MBASCHKLST_JOIN_N.KEY_ITEM
                    AND ATTR_KEY = :MBASCHKLST_JOIN_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 81;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ATTR_VALUE into :b0  from MATRNAMSTS wher\
e (((FACTORY=:b1 and ATTR_TYPE='RES') and ATTR_NAME=:b2) and ATTR_KEY=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2595;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MBASCHKLST_JOIN_N.KEY_VALUE);
            sqlstm.sqhstl[0] = (unsigned int  )101;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MBASCHKLST_JOIN_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MBASCHKLST_JOIN_N.KEY_ITEM);
            sqlstm.sqhstl[2] = (unsigned int  )101;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MBASCHKLST_JOIN_N.RES_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
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


    if(DB_error_code == 0)
    {
        DBC_del_null_mbaschklst_join(&MBASCHKLST_JOIN_N, MBASCHKLST_JOIN);
    }

    DB_stop_query_timer("DBC_select_checklist_key", sel_type);
}
