
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
    "DBC_mwipqtmhis.pc"
};


static unsigned int sqlctx = 9145347;


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
            void  *sqhstv[92];
   unsigned int   sqhstl[92];
            int   sqhsts[92];
            void  *sqindv[92];
            int   sqinds[92];
   unsigned int   sqharm[92];
   unsigned int   *sqharc[92];
   unsigned short  sqadto[92];
   unsigned short  sqtdso[92];
} sqlstm = {13,92};

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

 static const char *sq0010 = 
"NUM asc ,FROM_OPER asc ,FROM_POINT_F\
LAG asc ,CHECK_POINT_FLAG asc ,LOT_ID asc ,TRAN_TIME asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1566,0,4,46,0,0,92,14,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
388,0,0,2,1602,0,4,222,0,0,92,14,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
771,0,0,3,1578,0,4,435,0,0,92,14,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1154,0,0,4,334,0,4,647,0,0,15,14,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
1229,0,0,5,315,0,2,696,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
1300,0,0,6,60,0,2,714,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
1323,0,0,7,41,0,2,720,0,0,1,1,0,1,0,1,97,0,0,
1342,0,0,8,1203,0,3,748,0,0,78,78,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
1669,0,0,9,1276,0,5,929,0,0,78,78,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
1996,0,0,10,1129,0,9,1133,0,0,0,0,0,1,0,
2011,0,0,10,0,0,13,1162,0,0,78,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
2338,0,0,10,0,0,15,1270,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipqtmhis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2013/04/29 20:20:42
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
void DBC_add_null_mwipqtmhis(struct MWIPQTMHIS_N_TAG *MWIPQTMHIS_N, struct MWIPQTMHIS_TAG *MWIPQTMHIS);
void DBC_del_null_mwipqtmhis(struct MWIPQTMHIS_N_TAG *MWIPQTMHIS_N, struct MWIPQTMHIS_TAG *MWIPQTMHIS);


/* SQL SELECT Function */
void DBC_select_mwipqtmhis(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    FROM_FACTORY,
                    FROM_FLOW,
                    FROM_FLOW_SEQ_NUM,
                    FROM_OPER,
                    FROM_POINT_FLAG,
                    CHECK_POINT_FLAG,
                    LOT_ID,
                    TRAN_TIME,
                    HIST_SEQ,
                    PROCESS_LEVEL,
                    CUR_FLOW,
                    CUR_FLOW_SEQ_NUM,
                    CUR_OPER,
                    QUE_TIME,
                    ALARM_ID,
                    MSG,
                    USER_GRP_ID,
                    UPPER_QUE_TIME,
                    LOWER_QUE_TIME,
                    DIFF_QUE_TIME,
                    TRAN_CODE,
                    REASON_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RWK_RET_CLEAR_FLAG,
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
                    LOT_CMF_1,
                    LOT_CMF_2,
                    LOT_CMF_3,
                    LOT_CMF_4,
                    LOT_CMF_5,
                    LOT_CMF_6,
                    LOT_CMF_7,
                    LOT_CMF_8,
                    LOT_CMF_9,
                    LOT_CMF_10,
                    LOT_CMF_11,
                    LOT_CMF_12,
                    LOT_CMF_13,
                    LOT_CMF_14,
                    LOT_CMF_15,
                    LOT_CMF_16,
                    LOT_CMF_17,
                    LOT_CMF_18,
                    LOT_CMF_19,
                    LOT_CMF_20
                INTO 
                    :MWIPQTMHIS_N.FACTORY,
                    :MWIPQTMHIS_N.MAT_ID,
                    :MWIPQTMHIS_N.MAT_VER,
                    :MWIPQTMHIS_N.FLOW,
                    :MWIPQTMHIS_N.FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.OPER,
                    :MWIPQTMHIS_N.FROM_FACTORY,
                    :MWIPQTMHIS_N.FROM_FLOW,
                    :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.FROM_OPER,
                    :MWIPQTMHIS_N.FROM_POINT_FLAG,
                    :MWIPQTMHIS_N.CHECK_POINT_FLAG,
                    :MWIPQTMHIS_N.LOT_ID,
                    :MWIPQTMHIS_N.TRAN_TIME,
                    :MWIPQTMHIS_N.HIST_SEQ,
                    :MWIPQTMHIS_N.PROCESS_LEVEL,
                    :MWIPQTMHIS_N.CUR_FLOW,
                    :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.CUR_OPER,
                    :MWIPQTMHIS_N.QUE_TIME,
                    :MWIPQTMHIS_N.ALARM_ID,
                    :MWIPQTMHIS_N.MSG,
                    :MWIPQTMHIS_N.USER_GRP_ID,
                    :MWIPQTMHIS_N.UPPER_QUE_TIME,
                    :MWIPQTMHIS_N.LOWER_QUE_TIME,
                    :MWIPQTMHIS_N.DIFF_QUE_TIME,
                    :MWIPQTMHIS_N.TRAN_CODE,
                    :MWIPQTMHIS_N.REASON_CODE,
                    :MWIPQTMHIS_N.HOLD_PASSWORD,
                    :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.TRAN_TO_OPER,
                    :MWIPQTMHIS_N.RET_FLOW,
                    :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.RET_OPER,
                    :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                    :MWIPQTMHIS_N.CMF_1,
                    :MWIPQTMHIS_N.CMF_2,
                    :MWIPQTMHIS_N.CMF_3,
                    :MWIPQTMHIS_N.CMF_4,
                    :MWIPQTMHIS_N.CMF_5,
                    :MWIPQTMHIS_N.CMF_6,
                    :MWIPQTMHIS_N.CMF_7,
                    :MWIPQTMHIS_N.CMF_8,
                    :MWIPQTMHIS_N.CMF_9,
                    :MWIPQTMHIS_N.CMF_10,
                    :MWIPQTMHIS_N.CMF_11,
                    :MWIPQTMHIS_N.CMF_12,
                    :MWIPQTMHIS_N.CMF_13,
                    :MWIPQTMHIS_N.CMF_14,
                    :MWIPQTMHIS_N.CMF_15,
                    :MWIPQTMHIS_N.CMF_16,
                    :MWIPQTMHIS_N.CMF_17,
                    :MWIPQTMHIS_N.CMF_18,
                    :MWIPQTMHIS_N.CMF_19,
                    :MWIPQTMHIS_N.CMF_20,
                    :MWIPQTMHIS_N.LOT_COMMENT,
                    :MWIPQTMHIS_N.LOT_CMF_1,
                    :MWIPQTMHIS_N.LOT_CMF_2,
                    :MWIPQTMHIS_N.LOT_CMF_3,
                    :MWIPQTMHIS_N.LOT_CMF_4,
                    :MWIPQTMHIS_N.LOT_CMF_5,
                    :MWIPQTMHIS_N.LOT_CMF_6,
                    :MWIPQTMHIS_N.LOT_CMF_7,
                    :MWIPQTMHIS_N.LOT_CMF_8,
                    :MWIPQTMHIS_N.LOT_CMF_9,
                    :MWIPQTMHIS_N.LOT_CMF_10,
                    :MWIPQTMHIS_N.LOT_CMF_11,
                    :MWIPQTMHIS_N.LOT_CMF_12,
                    :MWIPQTMHIS_N.LOT_CMF_13,
                    :MWIPQTMHIS_N.LOT_CMF_14,
                    :MWIPQTMHIS_N.LOT_CMF_15,
                    :MWIPQTMHIS_N.LOT_CMF_16,
                    :MWIPQTMHIS_N.LOT_CMF_17,
                    :MWIPQTMHIS_N.LOT_CMF_18,
                    :MWIPQTMHIS_N.LOT_CMF_19,
                    :MWIPQTMHIS_N.LOT_CMF_20
                FROM MWIPQTMHIS
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND FROM_FACTORY = :MWIPQTMHIS_N.FROM_FACTORY
                    AND FROM_FLOW = :MWIPQTMHIS_N.FROM_FLOW
                    AND FROM_FLOW_SEQ_NUM = :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM
                    AND FROM_OPER = :MWIPQTMHIS_N.FROM_OPER
                    AND FROM_POINT_FLAG = :MWIPQTMHIS_N.FROM_POINT_FLAG
                    AND CHECK_POINT_FLAG = :MWIPQTMHIS_N.CHECK_POINT_FLAG
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = :MWIPQTMHIS_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,FR\
OM_FACTORY ,FROM_FLOW ,FROM_FLOW_SEQ_NUM ,FROM_OPER ,FROM_POINT_FLAG ,CHECK_\
POINT_FLAG ,LOT_ID ,TRAN_TIME ,HIST_SEQ ,PROCESS_LEVEL ,CUR_FLOW ,CUR_FLOW_S\
EQ_NUM ,CUR_OPER ,QUE_TIME ,ALARM_ID ,MSG ,USER_GRP_ID ,UPPER_QUE_TIME ,LOWE\
R_QUE_TIME ,DIFF_QUE_TIME ,TRAN_CODE ,REASON_CODE ,HOLD_PASSWORD ,HOLD_PRV_G\
RP_ID ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,RET_FLOW ,RET_FLOW_\
SEQ_NUM ,RET_OPER ,RWK_RET_CLEAR_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CM\
F_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CM\
F_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LOT_COMMENT ,LOT_CMF_1 ,LOT_CMF_2 ,LOT\
_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LO\
T_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CM\
F_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 into :b0,:b1,:b2,:b3,:b\
4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20\
,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,");
            sqlstm.stmt = ":b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b4\
0,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,\
:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b\
71,:b72,:b73,:b74,:b75,:b76,:b77  from MWIPQTMHIS where (((((((((((((FACTORY=\
:b0 and MAT_ID=:b1) and MAT_VER=:b2) and FLOW=:b3) and FLOW_SEQ_NUM=:b4) and \
OPER=:b5) and FROM_FACTORY=:b6) and FROM_FLOW=:b7) and FROM_FLOW_SEQ_NUM=:b8)\
 and FROM_OPER=:b9) and FROM_POINT_FLAG=:b10) and CHECK_POINT_FLAG=:b11) and \
LOT_ID=:b12) and TRAN_TIME=:b13)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.MSG);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )13;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
            sqlstm.sqhstl[57] = (unsigned int  )401;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[83] = (unsigned int  )11;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[84] = (unsigned int  )11;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[86] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[87] = (unsigned int  )11;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[89] = (unsigned int  )2;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[91] = (unsigned int  )15;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
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
                         FACTORY,
                         MAT_ID,
                         MAT_VER,
                         FLOW,
                         FLOW_SEQ_NUM,
                         OPER,
                         FROM_FACTORY,
                         FROM_FLOW,
                         FROM_FLOW_SEQ_NUM,
                         FROM_OPER,
                         FROM_POINT_FLAG,
                         CHECK_POINT_FLAG,
                         LOT_ID,
                         TRAN_TIME,
                         HIST_SEQ,
                         PROCESS_LEVEL,
                         CUR_FLOW,
                         CUR_FLOW_SEQ_NUM,
                         CUR_OPER,
                         QUE_TIME,
                         ALARM_ID,
                         MSG,
                         USER_GRP_ID,
                         UPPER_QUE_TIME,
                         LOWER_QUE_TIME,
                         DIFF_QUE_TIME,
                         TRAN_CODE,
                         REASON_CODE,
                         HOLD_PASSWORD,
                         HOLD_PRV_GRP_ID,
                         TRAN_TO_FLOW,
                         TRAN_TO_FLOW_SEQ_NUM,
                         TRAN_TO_OPER,
                         RET_FLOW,
                         RET_FLOW_SEQ_NUM,
                         RET_OPER,
                         RWK_RET_CLEAR_FLAG,
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
                         LOT_CMF_1,
                         LOT_CMF_2,
                         LOT_CMF_3,
                         LOT_CMF_4,
                         LOT_CMF_5,
                         LOT_CMF_6,
                         LOT_CMF_7,
                         LOT_CMF_8,
                         LOT_CMF_9,
                         LOT_CMF_10,
                         LOT_CMF_11,
                         LOT_CMF_12,
                         LOT_CMF_13,
                         LOT_CMF_14,
                         LOT_CMF_15,
                         LOT_CMF_16,
                         LOT_CMF_17,
                         LOT_CMF_18,
                         LOT_CMF_19,
                         LOT_CMF_20
                INTO 
                    :MWIPQTMHIS_N.FACTORY,
                    :MWIPQTMHIS_N.MAT_ID,
                    :MWIPQTMHIS_N.MAT_VER,
                    :MWIPQTMHIS_N.FLOW,
                    :MWIPQTMHIS_N.FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.OPER,
                    :MWIPQTMHIS_N.FROM_FACTORY,
                    :MWIPQTMHIS_N.FROM_FLOW,
                    :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.FROM_OPER,
                    :MWIPQTMHIS_N.FROM_POINT_FLAG,
                    :MWIPQTMHIS_N.CHECK_POINT_FLAG,
                    :MWIPQTMHIS_N.LOT_ID,
                    :MWIPQTMHIS_N.TRAN_TIME,
                    :MWIPQTMHIS_N.HIST_SEQ,
                    :MWIPQTMHIS_N.PROCESS_LEVEL,
                    :MWIPQTMHIS_N.CUR_FLOW,
                    :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.CUR_OPER,
                    :MWIPQTMHIS_N.QUE_TIME,
                    :MWIPQTMHIS_N.ALARM_ID,
                    :MWIPQTMHIS_N.MSG,
                    :MWIPQTMHIS_N.USER_GRP_ID,
                    :MWIPQTMHIS_N.UPPER_QUE_TIME,
                    :MWIPQTMHIS_N.LOWER_QUE_TIME,
                    :MWIPQTMHIS_N.DIFF_QUE_TIME,
                    :MWIPQTMHIS_N.TRAN_CODE,
                    :MWIPQTMHIS_N.REASON_CODE,
                    :MWIPQTMHIS_N.HOLD_PASSWORD,
                    :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.TRAN_TO_OPER,
                    :MWIPQTMHIS_N.RET_FLOW,
                    :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.RET_OPER,
                    :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                    :MWIPQTMHIS_N.CMF_1,
                    :MWIPQTMHIS_N.CMF_2,
                    :MWIPQTMHIS_N.CMF_3,
                    :MWIPQTMHIS_N.CMF_4,
                    :MWIPQTMHIS_N.CMF_5,
                    :MWIPQTMHIS_N.CMF_6,
                    :MWIPQTMHIS_N.CMF_7,
                    :MWIPQTMHIS_N.CMF_8,
                    :MWIPQTMHIS_N.CMF_9,
                    :MWIPQTMHIS_N.CMF_10,
                    :MWIPQTMHIS_N.CMF_11,
                    :MWIPQTMHIS_N.CMF_12,
                    :MWIPQTMHIS_N.CMF_13,
                    :MWIPQTMHIS_N.CMF_14,
                    :MWIPQTMHIS_N.CMF_15,
                    :MWIPQTMHIS_N.CMF_16,
                    :MWIPQTMHIS_N.CMF_17,
                    :MWIPQTMHIS_N.CMF_18,
                    :MWIPQTMHIS_N.CMF_19,
                    :MWIPQTMHIS_N.CMF_20,
                    :MWIPQTMHIS_N.LOT_COMMENT,
                    :MWIPQTMHIS_N.LOT_CMF_1,
                    :MWIPQTMHIS_N.LOT_CMF_2,
                    :MWIPQTMHIS_N.LOT_CMF_3,
                    :MWIPQTMHIS_N.LOT_CMF_4,
                    :MWIPQTMHIS_N.LOT_CMF_5,
                    :MWIPQTMHIS_N.LOT_CMF_6,
                    :MWIPQTMHIS_N.LOT_CMF_7,
                    :MWIPQTMHIS_N.LOT_CMF_8,
                    :MWIPQTMHIS_N.LOT_CMF_9,
                    :MWIPQTMHIS_N.LOT_CMF_10,
                    :MWIPQTMHIS_N.LOT_CMF_11,
                    :MWIPQTMHIS_N.LOT_CMF_12,
                    :MWIPQTMHIS_N.LOT_CMF_13,
                    :MWIPQTMHIS_N.LOT_CMF_14,
                    :MWIPQTMHIS_N.LOT_CMF_15,
                    :MWIPQTMHIS_N.LOT_CMF_16,
                    :MWIPQTMHIS_N.LOT_CMF_17,
                    :MWIPQTMHIS_N.LOT_CMF_18,
                    :MWIPQTMHIS_N.LOT_CMF_19,
                    :MWIPQTMHIS_N.LOT_CMF_20
                FROM MWIPQTMHIS
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = (
                        SELECT NVL(MAX(TRAN_TIME), '00000000000000') 
                        FROM MWIPQTMHIS
                        WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                            AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                            AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                            AND FLOW = :MWIPQTMHIS_N.FLOW
                            AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                            AND OPER = :MWIPQTMHIS_N.OPER
                            AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                        ); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,FR\
OM_FACTORY ,FROM_FLOW ,FROM_FLOW_SEQ_NUM ,FROM_OPER ,FROM_POINT_FLAG ,CHECK_\
POINT_FLAG ,LOT_ID ,TRAN_TIME ,HIST_SEQ ,PROCESS_LEVEL ,CUR_FLOW ,CUR_FLOW_S\
EQ_NUM ,CUR_OPER ,QUE_TIME ,ALARM_ID ,MSG ,USER_GRP_ID ,UPPER_QUE_TIME ,LOWE\
R_QUE_TIME ,DIFF_QUE_TIME ,TRAN_CODE ,REASON_CODE ,HOLD_PASSWORD ,HOLD_PRV_G\
RP_ID ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,RET_FLOW ,RET_FLOW_\
SEQ_NUM ,RET_OPER ,RWK_RET_CLEAR_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CM\
F_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CM\
F_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LOT_COMMENT ,LOT_CMF_1 ,LOT_CMF_2 ,LOT\
_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LO\
T_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CM\
F_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 into :b0,:b1,:b2,:b3,:b\
4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20\
,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,");
            sqlstm.stmt = ":b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b4\
0,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,\
:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b\
71,:b72,:b73,:b74,:b75,:b76,:b77  from MWIPQTMHIS where (((((((FACTORY=:b0 an\
d MAT_ID=:b1) and MAT_VER=:b2) and FLOW=:b3) and FLOW_SEQ_NUM=:b4) and OPER=:\
b5) and LOT_ID=:b12) and TRAN_TIME=(select NVL(max(TRAN_TIME),'00000000000000\
')  from MWIPQTMHIS where ((((((FACTORY=:b0 and MAT_ID=:b1) and MAT_VER=:b2) \
and FLOW=:b3) and FLOW_SEQ_NUM=:b4) and OPER=:b5) and LOT_ID=:b12)))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )388;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.MSG);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )13;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
            sqlstm.sqhstl[57] = (unsigned int  )401;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[83] = (unsigned int  )11;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[84] = (unsigned int  )26;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[85] = (unsigned int  )11;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[87] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[90] = (unsigned int  )11;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[91] = (unsigned int  )26;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
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
        DBC_del_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    }

    DB_stop_query_timer("DBC_select_mwipqtmhis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipqtmhis_for_update(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    FROM_FACTORY,
                    FROM_FLOW,
                    FROM_FLOW_SEQ_NUM,
                    FROM_OPER,
                    FROM_POINT_FLAG,
                    CHECK_POINT_FLAG,
                    LOT_ID,
                    TRAN_TIME,
                    HIST_SEQ,
                    PROCESS_LEVEL,
                    CUR_FLOW,
                    CUR_FLOW_SEQ_NUM,
                    CUR_OPER,
                    QUE_TIME,
                    ALARM_ID,
                    MSG,
                    USER_GRP_ID,
                    UPPER_QUE_TIME,
                    LOWER_QUE_TIME,
                    DIFF_QUE_TIME,
                    TRAN_CODE,
                    REASON_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RWK_RET_CLEAR_FLAG,
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
                    LOT_CMF_1,
                    LOT_CMF_2,
                    LOT_CMF_3,
                    LOT_CMF_4,
                    LOT_CMF_5,
                    LOT_CMF_6,
                    LOT_CMF_7,
                    LOT_CMF_8,
                    LOT_CMF_9,
                    LOT_CMF_10,
                    LOT_CMF_11,
                    LOT_CMF_12,
                    LOT_CMF_13,
                    LOT_CMF_14,
                    LOT_CMF_15,
                    LOT_CMF_16,
                    LOT_CMF_17,
                    LOT_CMF_18,
                    LOT_CMF_19,
                    LOT_CMF_20
                INTO 
                    :MWIPQTMHIS_N.FACTORY,
                    :MWIPQTMHIS_N.MAT_ID,
                    :MWIPQTMHIS_N.MAT_VER,
                    :MWIPQTMHIS_N.FLOW,
                    :MWIPQTMHIS_N.FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.OPER,
                    :MWIPQTMHIS_N.FROM_FACTORY,
                    :MWIPQTMHIS_N.FROM_FLOW,
                    :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.FROM_OPER,
                    :MWIPQTMHIS_N.FROM_POINT_FLAG,
                    :MWIPQTMHIS_N.CHECK_POINT_FLAG,
                    :MWIPQTMHIS_N.LOT_ID,
                    :MWIPQTMHIS_N.TRAN_TIME,
                    :MWIPQTMHIS_N.HIST_SEQ,
                    :MWIPQTMHIS_N.PROCESS_LEVEL,
                    :MWIPQTMHIS_N.CUR_FLOW,
                    :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.CUR_OPER,
                    :MWIPQTMHIS_N.QUE_TIME,
                    :MWIPQTMHIS_N.ALARM_ID,
                    :MWIPQTMHIS_N.MSG,
                    :MWIPQTMHIS_N.USER_GRP_ID,
                    :MWIPQTMHIS_N.UPPER_QUE_TIME,
                    :MWIPQTMHIS_N.LOWER_QUE_TIME,
                    :MWIPQTMHIS_N.DIFF_QUE_TIME,
                    :MWIPQTMHIS_N.TRAN_CODE,
                    :MWIPQTMHIS_N.REASON_CODE,
                    :MWIPQTMHIS_N.HOLD_PASSWORD,
                    :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.TRAN_TO_OPER,
                    :MWIPQTMHIS_N.RET_FLOW,
                    :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.RET_OPER,
                    :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                    :MWIPQTMHIS_N.CMF_1,
                    :MWIPQTMHIS_N.CMF_2,
                    :MWIPQTMHIS_N.CMF_3,
                    :MWIPQTMHIS_N.CMF_4,
                    :MWIPQTMHIS_N.CMF_5,
                    :MWIPQTMHIS_N.CMF_6,
                    :MWIPQTMHIS_N.CMF_7,
                    :MWIPQTMHIS_N.CMF_8,
                    :MWIPQTMHIS_N.CMF_9,
                    :MWIPQTMHIS_N.CMF_10,
                    :MWIPQTMHIS_N.CMF_11,
                    :MWIPQTMHIS_N.CMF_12,
                    :MWIPQTMHIS_N.CMF_13,
                    :MWIPQTMHIS_N.CMF_14,
                    :MWIPQTMHIS_N.CMF_15,
                    :MWIPQTMHIS_N.CMF_16,
                    :MWIPQTMHIS_N.CMF_17,
                    :MWIPQTMHIS_N.CMF_18,
                    :MWIPQTMHIS_N.CMF_19,
                    :MWIPQTMHIS_N.CMF_20,
                    :MWIPQTMHIS_N.LOT_COMMENT,
                    :MWIPQTMHIS_N.LOT_CMF_1,
                    :MWIPQTMHIS_N.LOT_CMF_2,
                    :MWIPQTMHIS_N.LOT_CMF_3,
                    :MWIPQTMHIS_N.LOT_CMF_4,
                    :MWIPQTMHIS_N.LOT_CMF_5,
                    :MWIPQTMHIS_N.LOT_CMF_6,
                    :MWIPQTMHIS_N.LOT_CMF_7,
                    :MWIPQTMHIS_N.LOT_CMF_8,
                    :MWIPQTMHIS_N.LOT_CMF_9,
                    :MWIPQTMHIS_N.LOT_CMF_10,
                    :MWIPQTMHIS_N.LOT_CMF_11,
                    :MWIPQTMHIS_N.LOT_CMF_12,
                    :MWIPQTMHIS_N.LOT_CMF_13,
                    :MWIPQTMHIS_N.LOT_CMF_14,
                    :MWIPQTMHIS_N.LOT_CMF_15,
                    :MWIPQTMHIS_N.LOT_CMF_16,
                    :MWIPQTMHIS_N.LOT_CMF_17,
                    :MWIPQTMHIS_N.LOT_CMF_18,
                    :MWIPQTMHIS_N.LOT_CMF_19,
                    :MWIPQTMHIS_N.LOT_CMF_20
                FROM MWIPQTMHIS
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND FROM_FACTORY = :MWIPQTMHIS_N.FROM_FACTORY
                    AND FROM_FLOW = :MWIPQTMHIS_N.FROM_FLOW
                    AND FROM_FLOW_SEQ_NUM = :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM
                    AND FROM_OPER = :MWIPQTMHIS_N.FROM_OPER
                    AND FROM_POINT_FLAG = :MWIPQTMHIS_N.FROM_POINT_FLAG
                    AND CHECK_POINT_FLAG = :MWIPQTMHIS_N.CHECK_POINT_FLAG
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = :MWIPQTMHIS_N.TRAN_TIME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,FR\
OM_FACTORY ,FROM_FLOW ,FROM_FLOW_SEQ_NUM ,FROM_OPER ,FROM_POINT_FLAG ,CHECK_\
POINT_FLAG ,LOT_ID ,TRAN_TIME ,HIST_SEQ ,PROCESS_LEVEL ,CUR_FLOW ,CUR_FLOW_S\
EQ_NUM ,CUR_OPER ,QUE_TIME ,ALARM_ID ,MSG ,USER_GRP_ID ,UPPER_QUE_TIME ,LOWE\
R_QUE_TIME ,DIFF_QUE_TIME ,TRAN_CODE ,REASON_CODE ,HOLD_PASSWORD ,HOLD_PRV_G\
RP_ID ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,RET_FLOW ,RET_FLOW_\
SEQ_NUM ,RET_OPER ,RWK_RET_CLEAR_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CM\
F_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CM\
F_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LOT_COMMENT ,LOT_CMF_1 ,LOT_CMF_2 ,LOT\
_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LO\
T_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CM\
F_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 into :b0,:b1,:b2,:b3,:b\
4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20\
,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,");
            sqlstm.stmt = ":b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b4\
0,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,\
:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b\
71,:b72,:b73,:b74,:b75,:b76,:b77  from MWIPQTMHIS where (((((((((((((FACTORY=\
:b0 and MAT_ID=:b1) and MAT_VER=:b2) and FLOW=:b3) and FLOW_SEQ_NUM=:b4) and \
OPER=:b5) and FROM_FACTORY=:b6) and FROM_FLOW=:b7) and FROM_FLOW_SEQ_NUM=:b8)\
 and FROM_OPER=:b9) and FROM_POINT_FLAG=:b10) and CHECK_POINT_FLAG=:b11) and \
LOT_ID=:b12) and TRAN_TIME=:b13) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )771;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.MSG);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )13;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
            sqlstm.sqhstl[57] = (unsigned int  )401;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[83] = (unsigned int  )11;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[84] = (unsigned int  )11;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[86] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[87] = (unsigned int  )11;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[89] = (unsigned int  )2;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[91] = (unsigned int  )15;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
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
        DBC_del_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    }

    DB_stop_query_timer("DBC_select_mwipqtmhis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipqtmhis_scalar(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPQTMHIS
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND FROM_FACTORY = :MWIPQTMHIS_N.FROM_FACTORY
                    AND FROM_FLOW = :MWIPQTMHIS_N.FROM_FLOW
                    AND FROM_FLOW_SEQ_NUM = :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM
                    AND FROM_OPER = :MWIPQTMHIS_N.FROM_OPER
                    AND FROM_POINT_FLAG = :MWIPQTMHIS_N.FROM_POINT_FLAG
                    AND CHECK_POINT_FLAG = :MWIPQTMHIS_N.CHECK_POINT_FLAG
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = :MWIPQTMHIS_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPQTMHIS where\
 (((((((((((((FACTORY=:b1 and MAT_ID=:b2) and MAT_VER=:b3) and FLOW=:b4) and \
FLOW_SEQ_NUM=:b5) and OPER=:b6) and FROM_FACTORY=:b7) and FROM_FLOW=:b8) and \
FROM_FLOW_SEQ_NUM=:b9) and FROM_OPER=:b10) and FROM_POINT_FLAG=:b11) and CHEC\
K_POINT_FLAG=:b12) and LOT_ID=:b13) and TRAN_TIME=:b14)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1154;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_select_mwipqtmhis_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipqtmhis(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPQTMHIS
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND FROM_FACTORY = :MWIPQTMHIS_N.FROM_FACTORY
                    AND FROM_FLOW = :MWIPQTMHIS_N.FROM_FLOW
                    AND FROM_FLOW_SEQ_NUM = :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM
                    AND FROM_OPER = :MWIPQTMHIS_N.FROM_OPER
                    AND FROM_POINT_FLAG = :MWIPQTMHIS_N.FROM_POINT_FLAG
                    AND CHECK_POINT_FLAG = :MWIPQTMHIS_N.CHECK_POINT_FLAG
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = :MWIPQTMHIS_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPQTMHIS  where (((((((((((((FACT\
ORY=:b0 and MAT_ID=:b1) and MAT_VER=:b2) and FLOW=:b3) and FLOW_SEQ_NUM=:b4) \
and OPER=:b5) and FROM_FACTORY=:b6) and FROM_FLOW=:b7) and FROM_FLOW_SEQ_NUM=\
:b8) and FROM_OPER=:b9) and FROM_POINT_FLAG=:b10) and CHECK_POINT_FLAG=:b11) \
and LOT_ID=:b12) and TRAN_TIME=:b13)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1229;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
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
            /* EXEC SQL DELETE FROM MWIPQTMHIS
                WHERE LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND HIST_SEQ = :MWIPQTMHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPQTMHIS  where (LOT_ID=:b0 and H\
IST_SEQ=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1300;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
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

        case 3:
            /* EXEC SQL DELETE FROM MWIPQTMHIS
                WHERE LOT_ID = :MWIPQTMHIS_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPQTMHIS  where LOT_ID=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1323;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
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


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_delete_mwipqtmhis", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipqtmhis(struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MWIPQTMHIS( 
                    FACTORY, 
                    MAT_ID, 
                    MAT_VER, 
                    FLOW, 
                    FLOW_SEQ_NUM, 
                    OPER, 
                    FROM_FACTORY, 
                    FROM_FLOW, 
                    FROM_FLOW_SEQ_NUM, 
                    FROM_OPER, 
                    FROM_POINT_FLAG, 
                    CHECK_POINT_FLAG, 
                    LOT_ID, 
                    TRAN_TIME, 
                    HIST_SEQ, 
                    PROCESS_LEVEL, 
                    CUR_FLOW, 
                    CUR_FLOW_SEQ_NUM, 
                    CUR_OPER, 
                    QUE_TIME, 
                    ALARM_ID, 
                    MSG, 
                    USER_GRP_ID, 
                    UPPER_QUE_TIME, 
                    LOWER_QUE_TIME, 
                    DIFF_QUE_TIME, 
                    TRAN_CODE, 
                    REASON_CODE, 
                    HOLD_PASSWORD, 
                    HOLD_PRV_GRP_ID, 
                    TRAN_TO_FLOW, 
                    TRAN_TO_FLOW_SEQ_NUM, 
                    TRAN_TO_OPER, 
                    RET_FLOW, 
                    RET_FLOW_SEQ_NUM, 
                    RET_OPER, 
                    RWK_RET_CLEAR_FLAG, 
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
                    LOT_CMF_1, 
                    LOT_CMF_2, 
                    LOT_CMF_3, 
                    LOT_CMF_4, 
                    LOT_CMF_5, 
                    LOT_CMF_6, 
                    LOT_CMF_7, 
                    LOT_CMF_8, 
                    LOT_CMF_9, 
                    LOT_CMF_10, 
                    LOT_CMF_11, 
                    LOT_CMF_12, 
                    LOT_CMF_13, 
                    LOT_CMF_14, 
                    LOT_CMF_15, 
                    LOT_CMF_16, 
                    LOT_CMF_17, 
                    LOT_CMF_18, 
                    LOT_CMF_19, 
                    LOT_CMF_20
         ) 
        VALUES (
                    :MWIPQTMHIS_N.FACTORY,
                    :MWIPQTMHIS_N.MAT_ID,
                    :MWIPQTMHIS_N.MAT_VER,
                    :MWIPQTMHIS_N.FLOW,
                    :MWIPQTMHIS_N.FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.OPER,
                    :MWIPQTMHIS_N.FROM_FACTORY,
                    :MWIPQTMHIS_N.FROM_FLOW,
                    :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.FROM_OPER,
                    :MWIPQTMHIS_N.FROM_POINT_FLAG,
                    :MWIPQTMHIS_N.CHECK_POINT_FLAG,
                    :MWIPQTMHIS_N.LOT_ID,
                    :MWIPQTMHIS_N.TRAN_TIME,
                    :MWIPQTMHIS_N.HIST_SEQ,
                    :MWIPQTMHIS_N.PROCESS_LEVEL,
                    :MWIPQTMHIS_N.CUR_FLOW,
                    :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.CUR_OPER,
                    :MWIPQTMHIS_N.QUE_TIME,
                    :MWIPQTMHIS_N.ALARM_ID,
                    :MWIPQTMHIS_N.MSG,
                    :MWIPQTMHIS_N.USER_GRP_ID,
                    :MWIPQTMHIS_N.UPPER_QUE_TIME,
                    :MWIPQTMHIS_N.LOWER_QUE_TIME,
                    :MWIPQTMHIS_N.DIFF_QUE_TIME,
                    :MWIPQTMHIS_N.TRAN_CODE,
                    :MWIPQTMHIS_N.REASON_CODE,
                    :MWIPQTMHIS_N.HOLD_PASSWORD,
                    :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW,
                    :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.TRAN_TO_OPER,
                    :MWIPQTMHIS_N.RET_FLOW,
                    :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                    :MWIPQTMHIS_N.RET_OPER,
                    :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                    :MWIPQTMHIS_N.CMF_1,
                    :MWIPQTMHIS_N.CMF_2,
                    :MWIPQTMHIS_N.CMF_3,
                    :MWIPQTMHIS_N.CMF_4,
                    :MWIPQTMHIS_N.CMF_5,
                    :MWIPQTMHIS_N.CMF_6,
                    :MWIPQTMHIS_N.CMF_7,
                    :MWIPQTMHIS_N.CMF_8,
                    :MWIPQTMHIS_N.CMF_9,
                    :MWIPQTMHIS_N.CMF_10,
                    :MWIPQTMHIS_N.CMF_11,
                    :MWIPQTMHIS_N.CMF_12,
                    :MWIPQTMHIS_N.CMF_13,
                    :MWIPQTMHIS_N.CMF_14,
                    :MWIPQTMHIS_N.CMF_15,
                    :MWIPQTMHIS_N.CMF_16,
                    :MWIPQTMHIS_N.CMF_17,
                    :MWIPQTMHIS_N.CMF_18,
                    :MWIPQTMHIS_N.CMF_19,
                    :MWIPQTMHIS_N.CMF_20,
                    :MWIPQTMHIS_N.LOT_COMMENT,
                    :MWIPQTMHIS_N.LOT_CMF_1,
                    :MWIPQTMHIS_N.LOT_CMF_2,
                    :MWIPQTMHIS_N.LOT_CMF_3,
                    :MWIPQTMHIS_N.LOT_CMF_4,
                    :MWIPQTMHIS_N.LOT_CMF_5,
                    :MWIPQTMHIS_N.LOT_CMF_6,
                    :MWIPQTMHIS_N.LOT_CMF_7,
                    :MWIPQTMHIS_N.LOT_CMF_8,
                    :MWIPQTMHIS_N.LOT_CMF_9,
                    :MWIPQTMHIS_N.LOT_CMF_10,
                    :MWIPQTMHIS_N.LOT_CMF_11,
                    :MWIPQTMHIS_N.LOT_CMF_12,
                    :MWIPQTMHIS_N.LOT_CMF_13,
                    :MWIPQTMHIS_N.LOT_CMF_14,
                    :MWIPQTMHIS_N.LOT_CMF_15,
                    :MWIPQTMHIS_N.LOT_CMF_16,
                    :MWIPQTMHIS_N.LOT_CMF_17,
                    :MWIPQTMHIS_N.LOT_CMF_18,
                    :MWIPQTMHIS_N.LOT_CMF_19,
                    :MWIPQTMHIS_N.LOT_CMF_20
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 92;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPQTMHIS (FACTORY,MAT_ID,MAT_VER,FLOW,FLOW_SEQ_NUM,OPER\
,FROM_FACTORY,FROM_FLOW,FROM_FLOW_SEQ_NUM,FROM_OPER,FROM_POINT_FLAG,CHECK_PO\
INT_FLAG,LOT_ID,TRAN_TIME,HIST_SEQ,PROCESS_LEVEL,CUR_FLOW,CUR_FLOW_SEQ_NUM,C\
UR_OPER,QUE_TIME,ALARM_ID,MSG,USER_GRP_ID,UPPER_QUE_TIME,LOWER_QUE_TIME,DIFF\
_QUE_TIME,TRAN_CODE,REASON_CODE,HOLD_PASSWORD,HOLD_PRV_GRP_ID,TRAN_TO_FLOW,T\
RAN_TO_FLOW_SEQ_NUM,TRAN_TO_OPER,RET_FLOW,RET_FLOW_SEQ_NUM,RET_OPER,RWK_RET_\
CLEAR_FLAG,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,CMF_7,CMF_8,CMF_9,CMF_10,CMF_\
11,CMF_12,CMF_13,CMF_14,CMF_15,CMF_16,CMF_17,CMF_18,CMF_19,CMF_20,LOT_COMMEN\
T,LOT_CMF_1,LOT_CMF_2,LOT_CMF_3,LOT_CMF_4,LOT_CMF_5,LOT_CMF_6,LOT_CMF_7,LOT_\
CMF_8,LOT_CMF_9,LOT_CMF_10,LOT_CMF_11,LOT_CMF_12,LOT_CMF_13,LOT_CMF_14,LOT_C\
MF_15,LOT_CMF_16,LOT_CMF_17,LOT_CMF_18,LOT_CMF_19,LOT_CMF_20) values (:b0,:b\
1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b\
18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b3\
3,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:");
    sqlstm.stmt = "b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b\
53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68\
,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1342;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
    sqlstm.sqhstl[5] = (unsigned int  )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
    sqlstm.sqhstl[6] = (unsigned int  )11;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
    sqlstm.sqhstl[9] = (unsigned int  )11;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
    sqlstm.sqhstl[12] = (unsigned int  )26;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
    sqlstm.sqhstl[13] = (unsigned int  )15;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
    sqlstm.sqhstl[15] = (unsigned int  )2;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.MSG);
    sqlstm.sqhstl[21] = (unsigned int  )201;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
    sqlstm.sqhstl[22] = (unsigned int  )21;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
    sqlstm.sqhstl[26] = (unsigned int  )13;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
    sqlstm.sqhstl[27] = (unsigned int  )11;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
    sqlstm.sqhstl[29] = (unsigned int  )21;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
    sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
    sqlstm.sqhstl[32] = (unsigned int  )11;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
    sqlstm.sqhstl[33] = (unsigned int  )21;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
    sqlstm.sqhstl[35] = (unsigned int  )11;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
    sqlstm.sqhstl[36] = (unsigned int  )2;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_1);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_2);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_3);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_4);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_5);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_6);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.CMF_7);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.CMF_8);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.CMF_9);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.CMF_10);
    sqlstm.sqhstl[46] = (unsigned int  )31;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.CMF_11);
    sqlstm.sqhstl[47] = (unsigned int  )31;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.CMF_12);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.CMF_13);
    sqlstm.sqhstl[49] = (unsigned int  )31;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.CMF_14);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.CMF_15);
    sqlstm.sqhstl[51] = (unsigned int  )31;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.CMF_16);
    sqlstm.sqhstl[52] = (unsigned int  )31;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.CMF_17);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.CMF_18);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.CMF_19);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.CMF_20);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
    sqlstm.sqhstl[57] = (unsigned int  )401;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
    sqlstm.sqhstl[59] = (unsigned int  )31;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
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



    DB_stop_query_timer("DBC_insert_mwipqtmhis", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipqtmhis(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPQTMHIS SET
                    HIST_SEQ = :MWIPQTMHIS_N.HIST_SEQ,
                    PROCESS_LEVEL = :MWIPQTMHIS_N.PROCESS_LEVEL,
                    CUR_FLOW = :MWIPQTMHIS_N.CUR_FLOW,
                    CUR_FLOW_SEQ_NUM = :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                    CUR_OPER = :MWIPQTMHIS_N.CUR_OPER,
                    QUE_TIME = :MWIPQTMHIS_N.QUE_TIME,
                    ALARM_ID = :MWIPQTMHIS_N.ALARM_ID,
                    MSG = :MWIPQTMHIS_N.MSG,
                    USER_GRP_ID = :MWIPQTMHIS_N.USER_GRP_ID,
                    UPPER_QUE_TIME = :MWIPQTMHIS_N.UPPER_QUE_TIME,
                    LOWER_QUE_TIME = :MWIPQTMHIS_N.LOWER_QUE_TIME,
                    DIFF_QUE_TIME = :MWIPQTMHIS_N.DIFF_QUE_TIME,
                    TRAN_CODE = :MWIPQTMHIS_N.TRAN_CODE,
                    REASON_CODE = :MWIPQTMHIS_N.REASON_CODE,
                    HOLD_PASSWORD = :MWIPQTMHIS_N.HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID = :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                    TRAN_TO_FLOW = :MWIPQTMHIS_N.TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM = :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER = :MWIPQTMHIS_N.TRAN_TO_OPER,
                    RET_FLOW = :MWIPQTMHIS_N.RET_FLOW,
                    RET_FLOW_SEQ_NUM = :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                    RET_OPER = :MWIPQTMHIS_N.RET_OPER,
                    RWK_RET_CLEAR_FLAG = :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                    CMF_1 = :MWIPQTMHIS_N.CMF_1,
                    CMF_2 = :MWIPQTMHIS_N.CMF_2,
                    CMF_3 = :MWIPQTMHIS_N.CMF_3,
                    CMF_4 = :MWIPQTMHIS_N.CMF_4,
                    CMF_5 = :MWIPQTMHIS_N.CMF_5,
                    CMF_6 = :MWIPQTMHIS_N.CMF_6,
                    CMF_7 = :MWIPQTMHIS_N.CMF_7,
                    CMF_8 = :MWIPQTMHIS_N.CMF_8,
                    CMF_9 = :MWIPQTMHIS_N.CMF_9,
                    CMF_10 = :MWIPQTMHIS_N.CMF_10,
                    CMF_11 = :MWIPQTMHIS_N.CMF_11,
                    CMF_12 = :MWIPQTMHIS_N.CMF_12,
                    CMF_13 = :MWIPQTMHIS_N.CMF_13,
                    CMF_14 = :MWIPQTMHIS_N.CMF_14,
                    CMF_15 = :MWIPQTMHIS_N.CMF_15,
                    CMF_16 = :MWIPQTMHIS_N.CMF_16,
                    CMF_17 = :MWIPQTMHIS_N.CMF_17,
                    CMF_18 = :MWIPQTMHIS_N.CMF_18,
                    CMF_19 = :MWIPQTMHIS_N.CMF_19,
                    CMF_20 = :MWIPQTMHIS_N.CMF_20,
                    LOT_COMMENT = :MWIPQTMHIS_N.LOT_COMMENT,
                    LOT_CMF_1 = :MWIPQTMHIS_N.LOT_CMF_1,
                    LOT_CMF_2 = :MWIPQTMHIS_N.LOT_CMF_2,
                    LOT_CMF_3 = :MWIPQTMHIS_N.LOT_CMF_3,
                    LOT_CMF_4 = :MWIPQTMHIS_N.LOT_CMF_4,
                    LOT_CMF_5 = :MWIPQTMHIS_N.LOT_CMF_5,
                    LOT_CMF_6 = :MWIPQTMHIS_N.LOT_CMF_6,
                    LOT_CMF_7 = :MWIPQTMHIS_N.LOT_CMF_7,
                    LOT_CMF_8 = :MWIPQTMHIS_N.LOT_CMF_8,
                    LOT_CMF_9 = :MWIPQTMHIS_N.LOT_CMF_9,
                    LOT_CMF_10 = :MWIPQTMHIS_N.LOT_CMF_10,
                    LOT_CMF_11 = :MWIPQTMHIS_N.LOT_CMF_11,
                    LOT_CMF_12 = :MWIPQTMHIS_N.LOT_CMF_12,
                    LOT_CMF_13 = :MWIPQTMHIS_N.LOT_CMF_13,
                    LOT_CMF_14 = :MWIPQTMHIS_N.LOT_CMF_14,
                    LOT_CMF_15 = :MWIPQTMHIS_N.LOT_CMF_15,
                    LOT_CMF_16 = :MWIPQTMHIS_N.LOT_CMF_16,
                    LOT_CMF_17 = :MWIPQTMHIS_N.LOT_CMF_17,
                    LOT_CMF_18 = :MWIPQTMHIS_N.LOT_CMF_18,
                    LOT_CMF_19 = :MWIPQTMHIS_N.LOT_CMF_19,
                    LOT_CMF_20 = :MWIPQTMHIS_N.LOT_CMF_20
                WHERE FACTORY = :MWIPQTMHIS_N.FACTORY
                    AND MAT_ID = :MWIPQTMHIS_N.MAT_ID
                    AND MAT_VER = :MWIPQTMHIS_N.MAT_VER
                    AND FLOW = :MWIPQTMHIS_N.FLOW
                    AND FLOW_SEQ_NUM = :MWIPQTMHIS_N.FLOW_SEQ_NUM
                    AND OPER = :MWIPQTMHIS_N.OPER
                    AND FROM_FACTORY = :MWIPQTMHIS_N.FROM_FACTORY
                    AND FROM_FLOW = :MWIPQTMHIS_N.FROM_FLOW
                    AND FROM_FLOW_SEQ_NUM = :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM
                    AND FROM_OPER = :MWIPQTMHIS_N.FROM_OPER
                    AND FROM_POINT_FLAG = :MWIPQTMHIS_N.FROM_POINT_FLAG
                    AND CHECK_POINT_FLAG = :MWIPQTMHIS_N.CHECK_POINT_FLAG
                    AND LOT_ID = :MWIPQTMHIS_N.LOT_ID
                    AND TRAN_TIME = :MWIPQTMHIS_N.TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPQTMHIS  set HIST_SEQ=:b0,PROCESS_LEVEL=:b1,CUR_FLO\
W=:b2,CUR_FLOW_SEQ_NUM=:b3,CUR_OPER=:b4,QUE_TIME=:b5,ALARM_ID=:b6,MSG=:b7,US\
ER_GRP_ID=:b8,UPPER_QUE_TIME=:b9,LOWER_QUE_TIME=:b10,DIFF_QUE_TIME=:b11,TRAN\
_CODE=:b12,REASON_CODE=:b13,HOLD_PASSWORD=:b14,HOLD_PRV_GRP_ID=:b15,TRAN_TO_\
FLOW=:b16,TRAN_TO_FLOW_SEQ_NUM=:b17,TRAN_TO_OPER=:b18,RET_FLOW=:b19,RET_FLOW\
_SEQ_NUM=:b20,RET_OPER=:b21,RWK_RET_CLEAR_FLAG=:b22,CMF_1=:b23,CMF_2=:b24,CM\
F_3=:b25,CMF_4=:b26,CMF_5=:b27,CMF_6=:b28,CMF_7=:b29,CMF_8=:b30,CMF_9=:b31,C\
MF_10=:b32,CMF_11=:b33,CMF_12=:b34,CMF_13=:b35,CMF_14=:b36,CMF_15=:b37,CMF_1\
6=:b38,CMF_17=:b39,CMF_18=:b40,CMF_19=:b41,CMF_20=:b42,LOT_COMMENT=:b43,LOT_\
CMF_1=:b44,LOT_CMF_2=:b45,LOT_CMF_3=:b46,LOT_CMF_4=:b47,LOT_CMF_5=:b48,LOT_C\
MF_6=:b49,LOT_CMF_7=:b50,LOT_CMF_8=:b51,LOT_CMF_9=:b52,LOT_CMF_10=:b53,LOT_C\
MF_11=:b54,LOT_CMF_12=:b55,LOT_CMF_13=:b56,LOT_CMF_14=:b57,LOT_CMF_15=:b58,L\
OT_CMF_16=:b59,LOT_CMF_17=:b60,LOT_CMF_18=:b61,LOT_CMF_19=:b62,LOT_CMF_20=:b\
63 where (((((((((((((FACTORY=:b64 and MAT_ID=:b65)");
            sqlstm.stmt = " and MAT_VER=:b66) and FLOW=:b67) and FLOW_SEQ_N\
UM=:b68) and OPER=:b69) and FROM_FACTORY=:b70) and FROM_FLOW=:b71) and FROM_F\
LOW_SEQ_NUM=:b72) and FROM_OPER=:b73) and FROM_POINT_FLAG=:b74) and CHECK_POI\
NT_FLAG=:b75) and LOT_ID=:b76) and TRAN_TIME=:b77)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1669;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.MSG);
            sqlstm.sqhstl[7] = (unsigned int  )201;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )13;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
            sqlstm.sqhstl[21] = (unsigned int  )11;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPQTMHIS_N.CMF_1);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPQTMHIS_N.CMF_2);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPQTMHIS_N.CMF_3);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.CMF_4);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.CMF_5);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.CMF_6);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.CMF_7);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.CMF_8);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPQTMHIS_N.CMF_9);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.CMF_10);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.CMF_11);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPQTMHIS_N.CMF_12);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.CMF_13);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.CMF_14);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_15);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_16);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_17);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_18);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_19);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_20);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
            sqlstm.sqhstl[43] = (unsigned int  )401;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[69] = (unsigned int  )11;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[72] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[73] = (unsigned int  )11;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )26;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
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

    DB_stop_query_timer("DBC_update_mwipqtmhis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipqtmhis(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPQTMHIS_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    FROM_FACTORY,
                    FROM_FLOW,
                    FROM_FLOW_SEQ_NUM,
                    FROM_OPER,
                    FROM_POINT_FLAG,
                    CHECK_POINT_FLAG,
                    LOT_ID,
                    TRAN_TIME,
                    HIST_SEQ,
                    PROCESS_LEVEL,
                    CUR_FLOW,
                    CUR_FLOW_SEQ_NUM,
                    CUR_OPER,
                    QUE_TIME,
                    ALARM_ID,
                    MSG,
                    USER_GRP_ID,
                    UPPER_QUE_TIME,
                    LOWER_QUE_TIME,
                    DIFF_QUE_TIME,
                    TRAN_CODE,
                    REASON_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    TRAN_TO_FLOW,
                    TRAN_TO_FLOW_SEQ_NUM,
                    TRAN_TO_OPER,
                    RET_FLOW,
                    RET_FLOW_SEQ_NUM,
                    RET_OPER,
                    RWK_RET_CLEAR_FLAG,
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
                    LOT_CMF_1,
                    LOT_CMF_2,
                    LOT_CMF_3,
                    LOT_CMF_4,
                    LOT_CMF_5,
                    LOT_CMF_6,
                    LOT_CMF_7,
                    LOT_CMF_8,
                    LOT_CMF_9,
                    LOT_CMF_10,
                    LOT_CMF_11,
                    LOT_CMF_12,
                    LOT_CMF_13,
                    LOT_CMF_14,
                    LOT_CMF_15,
                    LOT_CMF_16,
                    LOT_CMF_17,
                    LOT_CMF_18,
                    LOT_CMF_19,
                    LOT_CMF_20
                FROM MWIPQTMHIS
                ORDER BY FACTORY ASC,
                    MAT_ID ASC,
                    MAT_VER ASC,
                    FLOW ASC,
                    FLOW_SEQ_NUM ASC,
                    OPER ASC,
                    FROM_FACTORY ASC,
                    FROM_FLOW ASC,
                    FROM_FLOW_SEQ_NUM ASC,
                    FROM_OPER ASC,
                    FROM_POINT_FLAG ASC,
                    CHECK_POINT_FLAG ASC,
                    LOT_ID ASC,
                    TRAN_TIME ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPQTMHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,FR\
OM_FACTORY ,FROM_FLOW ,FROM_FLOW_SEQ_NUM ,FROM_OPER ,FROM_POINT_FLAG ,CHECK_\
POINT_FLAG ,LOT_ID ,TRAN_TIME ,HIST_SEQ ,PROCESS_LEVEL ,CUR_FLOW ,CUR_FLOW_S\
EQ_NUM ,CUR_OPER ,QUE_TIME ,ALARM_ID ,MSG ,USER_GRP_ID ,UPPER_QUE_TIME ,LOWE\
R_QUE_TIME ,DIFF_QUE_TIME ,TRAN_CODE ,REASON_CODE ,HOLD_PASSWORD ,HOLD_PRV_G\
RP_ID ,TRAN_TO_FLOW ,TRAN_TO_FLOW_SEQ_NUM ,TRAN_TO_OPER ,RET_FLOW ,RET_FLOW_\
SEQ_NUM ,RET_OPER ,RWK_RET_CLEAR_FLAG ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CM\
F_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CMF_11 ,CMF_12 ,CMF_13 ,CMF_14 ,CMF_15 ,CM\
F_16 ,CMF_17 ,CMF_18 ,CMF_19 ,CMF_20 ,LOT_COMMENT ,LOT_CMF_1 ,LOT_CMF_2 ,LOT\
_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LO\
T_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CM\
F_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20  from MWIPQTMHIS  order\
 by FACTORY asc ,MAT_ID asc ,MAT_VER asc ,FLOW asc ,FLOW_SEQ_NUM asc ,OPER a\
sc ,FROM_FACTORY asc ,FROM_FLOW asc ,FROM_FLOW_SEQ_");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1996;
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBC_open_mwipqtmhis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipqtmhis(int sel_type, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPQTMHIS_N_TAG MWIPQTMHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPQTMHIS_CUR_1 INTO
                :MWIPQTMHIS_N.FACTORY,
                :MWIPQTMHIS_N.MAT_ID,
                :MWIPQTMHIS_N.MAT_VER,
                :MWIPQTMHIS_N.FLOW,
                :MWIPQTMHIS_N.FLOW_SEQ_NUM,
                :MWIPQTMHIS_N.OPER,
                :MWIPQTMHIS_N.FROM_FACTORY,
                :MWIPQTMHIS_N.FROM_FLOW,
                :MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM,
                :MWIPQTMHIS_N.FROM_OPER,
                :MWIPQTMHIS_N.FROM_POINT_FLAG,
                :MWIPQTMHIS_N.CHECK_POINT_FLAG,
                :MWIPQTMHIS_N.LOT_ID,
                :MWIPQTMHIS_N.TRAN_TIME,
                :MWIPQTMHIS_N.HIST_SEQ,
                :MWIPQTMHIS_N.PROCESS_LEVEL,
                :MWIPQTMHIS_N.CUR_FLOW,
                :MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM,
                :MWIPQTMHIS_N.CUR_OPER,
                :MWIPQTMHIS_N.QUE_TIME,
                :MWIPQTMHIS_N.ALARM_ID,
                :MWIPQTMHIS_N.MSG,
                :MWIPQTMHIS_N.USER_GRP_ID,
                :MWIPQTMHIS_N.UPPER_QUE_TIME,
                :MWIPQTMHIS_N.LOWER_QUE_TIME,
                :MWIPQTMHIS_N.DIFF_QUE_TIME,
                :MWIPQTMHIS_N.TRAN_CODE,
                :MWIPQTMHIS_N.REASON_CODE,
                :MWIPQTMHIS_N.HOLD_PASSWORD,
                :MWIPQTMHIS_N.HOLD_PRV_GRP_ID,
                :MWIPQTMHIS_N.TRAN_TO_FLOW,
                :MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM,
                :MWIPQTMHIS_N.TRAN_TO_OPER,
                :MWIPQTMHIS_N.RET_FLOW,
                :MWIPQTMHIS_N.RET_FLOW_SEQ_NUM,
                :MWIPQTMHIS_N.RET_OPER,
                :MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG,
                :MWIPQTMHIS_N.CMF_1,
                :MWIPQTMHIS_N.CMF_2,
                :MWIPQTMHIS_N.CMF_3,
                :MWIPQTMHIS_N.CMF_4,
                :MWIPQTMHIS_N.CMF_5,
                :MWIPQTMHIS_N.CMF_6,
                :MWIPQTMHIS_N.CMF_7,
                :MWIPQTMHIS_N.CMF_8,
                :MWIPQTMHIS_N.CMF_9,
                :MWIPQTMHIS_N.CMF_10,
                :MWIPQTMHIS_N.CMF_11,
                :MWIPQTMHIS_N.CMF_12,
                :MWIPQTMHIS_N.CMF_13,
                :MWIPQTMHIS_N.CMF_14,
                :MWIPQTMHIS_N.CMF_15,
                :MWIPQTMHIS_N.CMF_16,
                :MWIPQTMHIS_N.CMF_17,
                :MWIPQTMHIS_N.CMF_18,
                :MWIPQTMHIS_N.CMF_19,
                :MWIPQTMHIS_N.CMF_20,
                :MWIPQTMHIS_N.LOT_COMMENT,
                :MWIPQTMHIS_N.LOT_CMF_1,
                :MWIPQTMHIS_N.LOT_CMF_2,
                :MWIPQTMHIS_N.LOT_CMF_3,
                :MWIPQTMHIS_N.LOT_CMF_4,
                :MWIPQTMHIS_N.LOT_CMF_5,
                :MWIPQTMHIS_N.LOT_CMF_6,
                :MWIPQTMHIS_N.LOT_CMF_7,
                :MWIPQTMHIS_N.LOT_CMF_8,
                :MWIPQTMHIS_N.LOT_CMF_9,
                :MWIPQTMHIS_N.LOT_CMF_10,
                :MWIPQTMHIS_N.LOT_CMF_11,
                :MWIPQTMHIS_N.LOT_CMF_12,
                :MWIPQTMHIS_N.LOT_CMF_13,
                :MWIPQTMHIS_N.LOT_CMF_14,
                :MWIPQTMHIS_N.LOT_CMF_15,
                :MWIPQTMHIS_N.LOT_CMF_16,
                :MWIPQTMHIS_N.LOT_CMF_17,
                :MWIPQTMHIS_N.LOT_CMF_18,
                :MWIPQTMHIS_N.LOT_CMF_19,
                :MWIPQTMHIS_N.LOT_CMF_20; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2011;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPQTMHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPQTMHIS_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPQTMHIS_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPQTMHIS_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPQTMHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPQTMHIS_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPQTMHIS_N.FROM_FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPQTMHIS_N.FROM_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPQTMHIS_N.FROM_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPQTMHIS_N.FROM_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPQTMHIS_N.FROM_POINT_FLAG);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPQTMHIS_N.CHECK_POINT_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPQTMHIS_N.LOT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPQTMHIS_N.TRAN_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPQTMHIS_N.HIST_SEQ);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPQTMHIS_N.PROCESS_LEVEL);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPQTMHIS_N.CUR_FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MWIPQTMHIS_N.CUR_FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPQTMHIS_N.CUR_OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MWIPQTMHIS_N.QUE_TIME);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPQTMHIS_N.ALARM_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPQTMHIS_N.MSG);
            sqlstm.sqhstl[21] = (unsigned int  )201;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPQTMHIS_N.USER_GRP_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPQTMHIS_N.UPPER_QUE_TIME);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPQTMHIS_N.LOWER_QUE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPQTMHIS_N.DIFF_QUE_TIME);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPQTMHIS_N.TRAN_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )13;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPQTMHIS_N.REASON_CODE);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPQTMHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPQTMHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_FLOW);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPQTMHIS_N.TRAN_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPQTMHIS_N.TRAN_TO_OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPQTMHIS_N.RET_FLOW);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MWIPQTMHIS_N.RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPQTMHIS_N.RET_OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPQTMHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPQTMHIS_N.CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPQTMHIS_N.CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPQTMHIS_N.CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPQTMHIS_N.CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPQTMHIS_N.CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPQTMHIS_N.CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPQTMHIS_N.CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPQTMHIS_N.CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPQTMHIS_N.CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPQTMHIS_N.CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )31;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPQTMHIS_N.CMF_11);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPQTMHIS_N.CMF_12);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPQTMHIS_N.CMF_13);
            sqlstm.sqhstl[49] = (unsigned int  )31;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPQTMHIS_N.CMF_14);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPQTMHIS_N.CMF_15);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPQTMHIS_N.CMF_16);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPQTMHIS_N.CMF_17);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPQTMHIS_N.CMF_18);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPQTMHIS_N.CMF_19);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPQTMHIS_N.CMF_20);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPQTMHIS_N.LOT_COMMENT);
            sqlstm.sqhstl[57] = (unsigned int  )401;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPQTMHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
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
        DBC_del_null_mwipqtmhis(&MWIPQTMHIS_N, MWIPQTMHIS);
    }

    DB_stop_query_timer("DBC_fetch_mwipqtmhis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipqtmhis(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPQTMHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 92;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2338;
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

    DB_stop_query_timer("DBC_close_mwipqtmhis", sel_type);
}


/* Initialize Function */
void DBC_init_mwipqtmhis(struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* memset by Space */
    memset(MWIPQTMHIS, ' ', sizeof(struct MWIPQTMHIS_TAG));
    
    MWIPQTMHIS->MAT_VER = 0;
    MWIPQTMHIS->FLOW_SEQ_NUM = 0;
    MWIPQTMHIS->FROM_FLOW_SEQ_NUM = 0;
    MWIPQTMHIS->HIST_SEQ = 0;
    MWIPQTMHIS->CUR_FLOW_SEQ_NUM = 0;
    MWIPQTMHIS->QUE_TIME = 0;
    MWIPQTMHIS->UPPER_QUE_TIME = 0;
    MWIPQTMHIS->LOWER_QUE_TIME = 0;
    MWIPQTMHIS->DIFF_QUE_TIME = 0;
    MWIPQTMHIS->TRAN_TO_FLOW_SEQ_NUM = 0;
    MWIPQTMHIS->RET_FLOW_SEQ_NUM = 0;
}


/* Add Null Function */
void DBC_add_null_mwipqtmhis(struct MWIPQTMHIS_N_TAG *MWIPQTMHIS_N, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    /* memset by NULL */
    memset(MWIPQTMHIS_N, '\0', sizeof(struct MWIPQTMHIS_N_TAG));
    
    MEMCPY_AN(MWIPQTMHIS_N->FACTORY, MWIPQTMHIS->FACTORY, sizeof(MWIPQTMHIS->FACTORY));
    MEMCPY_AN(MWIPQTMHIS_N->MAT_ID, MWIPQTMHIS->MAT_ID, sizeof(MWIPQTMHIS->MAT_ID));
    MWIPQTMHIS_N->MAT_VER = MWIPQTMHIS->MAT_VER;
    MEMCPY_AN(MWIPQTMHIS_N->FLOW, MWIPQTMHIS->FLOW, sizeof(MWIPQTMHIS->FLOW));
    MWIPQTMHIS_N->FLOW_SEQ_NUM = MWIPQTMHIS->FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPQTMHIS_N->OPER, MWIPQTMHIS->OPER, sizeof(MWIPQTMHIS->OPER));
    MEMCPY_AN(MWIPQTMHIS_N->FROM_FACTORY, MWIPQTMHIS->FROM_FACTORY, sizeof(MWIPQTMHIS->FROM_FACTORY));
    MEMCPY_AN(MWIPQTMHIS_N->FROM_FLOW, MWIPQTMHIS->FROM_FLOW, sizeof(MWIPQTMHIS->FROM_FLOW));
    MWIPQTMHIS_N->FROM_FLOW_SEQ_NUM = MWIPQTMHIS->FROM_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPQTMHIS_N->FROM_OPER, MWIPQTMHIS->FROM_OPER, sizeof(MWIPQTMHIS->FROM_OPER));
    MWIPQTMHIS_N->FROM_POINT_FLAG[0] = MWIPQTMHIS->FROM_POINT_FLAG;
    MWIPQTMHIS_N->CHECK_POINT_FLAG[0] = MWIPQTMHIS->CHECK_POINT_FLAG;
    MEMCPY_AN(MWIPQTMHIS_N->LOT_ID, MWIPQTMHIS->LOT_ID, sizeof(MWIPQTMHIS->LOT_ID));
    MEMCPY_AN(MWIPQTMHIS_N->TRAN_TIME, MWIPQTMHIS->TRAN_TIME, sizeof(MWIPQTMHIS->TRAN_TIME));
    MWIPQTMHIS_N->HIST_SEQ = MWIPQTMHIS->HIST_SEQ;
    MWIPQTMHIS_N->PROCESS_LEVEL[0] = MWIPQTMHIS->PROCESS_LEVEL;
    MEMCPY_AN(MWIPQTMHIS_N->CUR_FLOW, MWIPQTMHIS->CUR_FLOW, sizeof(MWIPQTMHIS->CUR_FLOW));
    MWIPQTMHIS_N->CUR_FLOW_SEQ_NUM = MWIPQTMHIS->CUR_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPQTMHIS_N->CUR_OPER, MWIPQTMHIS->CUR_OPER, sizeof(MWIPQTMHIS->CUR_OPER));
    MWIPQTMHIS_N->QUE_TIME = MWIPQTMHIS->QUE_TIME;
    MEMCPY_AN(MWIPQTMHIS_N->ALARM_ID, MWIPQTMHIS->ALARM_ID, sizeof(MWIPQTMHIS->ALARM_ID));
    MEMCPY_AN(MWIPQTMHIS_N->MSG, MWIPQTMHIS->MSG, sizeof(MWIPQTMHIS->MSG));
    MEMCPY_AN(MWIPQTMHIS_N->USER_GRP_ID, MWIPQTMHIS->USER_GRP_ID, sizeof(MWIPQTMHIS->USER_GRP_ID));
    MWIPQTMHIS_N->UPPER_QUE_TIME = MWIPQTMHIS->UPPER_QUE_TIME;
    MWIPQTMHIS_N->LOWER_QUE_TIME = MWIPQTMHIS->LOWER_QUE_TIME;
    MWIPQTMHIS_N->DIFF_QUE_TIME = MWIPQTMHIS->DIFF_QUE_TIME;
    MEMCPY_AN(MWIPQTMHIS_N->TRAN_CODE, MWIPQTMHIS->TRAN_CODE, sizeof(MWIPQTMHIS->TRAN_CODE));
    MEMCPY_AN(MWIPQTMHIS_N->REASON_CODE, MWIPQTMHIS->REASON_CODE, sizeof(MWIPQTMHIS->REASON_CODE));
    MEMCPY_AN(MWIPQTMHIS_N->HOLD_PASSWORD, MWIPQTMHIS->HOLD_PASSWORD, sizeof(MWIPQTMHIS->HOLD_PASSWORD));
    MEMCPY_AN(MWIPQTMHIS_N->HOLD_PRV_GRP_ID, MWIPQTMHIS->HOLD_PRV_GRP_ID, sizeof(MWIPQTMHIS->HOLD_PRV_GRP_ID));
    MEMCPY_AN(MWIPQTMHIS_N->TRAN_TO_FLOW, MWIPQTMHIS->TRAN_TO_FLOW, sizeof(MWIPQTMHIS->TRAN_TO_FLOW));
    MWIPQTMHIS_N->TRAN_TO_FLOW_SEQ_NUM = MWIPQTMHIS->TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPQTMHIS_N->TRAN_TO_OPER, MWIPQTMHIS->TRAN_TO_OPER, sizeof(MWIPQTMHIS->TRAN_TO_OPER));
    MEMCPY_AN(MWIPQTMHIS_N->RET_FLOW, MWIPQTMHIS->RET_FLOW, sizeof(MWIPQTMHIS->RET_FLOW));
    MWIPQTMHIS_N->RET_FLOW_SEQ_NUM = MWIPQTMHIS->RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPQTMHIS_N->RET_OPER, MWIPQTMHIS->RET_OPER, sizeof(MWIPQTMHIS->RET_OPER));
    MWIPQTMHIS_N->RWK_RET_CLEAR_FLAG[0] = MWIPQTMHIS->RWK_RET_CLEAR_FLAG;
    MEMCPY_AN(MWIPQTMHIS_N->CMF_1, MWIPQTMHIS->CMF_1, sizeof(MWIPQTMHIS->CMF_1));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_2, MWIPQTMHIS->CMF_2, sizeof(MWIPQTMHIS->CMF_2));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_3, MWIPQTMHIS->CMF_3, sizeof(MWIPQTMHIS->CMF_3));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_4, MWIPQTMHIS->CMF_4, sizeof(MWIPQTMHIS->CMF_4));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_5, MWIPQTMHIS->CMF_5, sizeof(MWIPQTMHIS->CMF_5));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_6, MWIPQTMHIS->CMF_6, sizeof(MWIPQTMHIS->CMF_6));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_7, MWIPQTMHIS->CMF_7, sizeof(MWIPQTMHIS->CMF_7));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_8, MWIPQTMHIS->CMF_8, sizeof(MWIPQTMHIS->CMF_8));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_9, MWIPQTMHIS->CMF_9, sizeof(MWIPQTMHIS->CMF_9));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_10, MWIPQTMHIS->CMF_10, sizeof(MWIPQTMHIS->CMF_10));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_11, MWIPQTMHIS->CMF_11, sizeof(MWIPQTMHIS->CMF_11));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_12, MWIPQTMHIS->CMF_12, sizeof(MWIPQTMHIS->CMF_12));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_13, MWIPQTMHIS->CMF_13, sizeof(MWIPQTMHIS->CMF_13));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_14, MWIPQTMHIS->CMF_14, sizeof(MWIPQTMHIS->CMF_14));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_15, MWIPQTMHIS->CMF_15, sizeof(MWIPQTMHIS->CMF_15));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_16, MWIPQTMHIS->CMF_16, sizeof(MWIPQTMHIS->CMF_16));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_17, MWIPQTMHIS->CMF_17, sizeof(MWIPQTMHIS->CMF_17));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_18, MWIPQTMHIS->CMF_18, sizeof(MWIPQTMHIS->CMF_18));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_19, MWIPQTMHIS->CMF_19, sizeof(MWIPQTMHIS->CMF_19));
    MEMCPY_AN(MWIPQTMHIS_N->CMF_20, MWIPQTMHIS->CMF_20, sizeof(MWIPQTMHIS->CMF_20));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_COMMENT, MWIPQTMHIS->LOT_COMMENT, sizeof(MWIPQTMHIS->LOT_COMMENT));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_1, MWIPQTMHIS->LOT_CMF_1, sizeof(MWIPQTMHIS->LOT_CMF_1));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_2, MWIPQTMHIS->LOT_CMF_2, sizeof(MWIPQTMHIS->LOT_CMF_2));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_3, MWIPQTMHIS->LOT_CMF_3, sizeof(MWIPQTMHIS->LOT_CMF_3));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_4, MWIPQTMHIS->LOT_CMF_4, sizeof(MWIPQTMHIS->LOT_CMF_4));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_5, MWIPQTMHIS->LOT_CMF_5, sizeof(MWIPQTMHIS->LOT_CMF_5));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_6, MWIPQTMHIS->LOT_CMF_6, sizeof(MWIPQTMHIS->LOT_CMF_6));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_7, MWIPQTMHIS->LOT_CMF_7, sizeof(MWIPQTMHIS->LOT_CMF_7));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_8, MWIPQTMHIS->LOT_CMF_8, sizeof(MWIPQTMHIS->LOT_CMF_8));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_9, MWIPQTMHIS->LOT_CMF_9, sizeof(MWIPQTMHIS->LOT_CMF_9));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_10, MWIPQTMHIS->LOT_CMF_10, sizeof(MWIPQTMHIS->LOT_CMF_10));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_11, MWIPQTMHIS->LOT_CMF_11, sizeof(MWIPQTMHIS->LOT_CMF_11));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_12, MWIPQTMHIS->LOT_CMF_12, sizeof(MWIPQTMHIS->LOT_CMF_12));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_13, MWIPQTMHIS->LOT_CMF_13, sizeof(MWIPQTMHIS->LOT_CMF_13));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_14, MWIPQTMHIS->LOT_CMF_14, sizeof(MWIPQTMHIS->LOT_CMF_14));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_15, MWIPQTMHIS->LOT_CMF_15, sizeof(MWIPQTMHIS->LOT_CMF_15));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_16, MWIPQTMHIS->LOT_CMF_16, sizeof(MWIPQTMHIS->LOT_CMF_16));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_17, MWIPQTMHIS->LOT_CMF_17, sizeof(MWIPQTMHIS->LOT_CMF_17));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_18, MWIPQTMHIS->LOT_CMF_18, sizeof(MWIPQTMHIS->LOT_CMF_18));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_19, MWIPQTMHIS->LOT_CMF_19, sizeof(MWIPQTMHIS->LOT_CMF_19));
    MEMCPY_AN(MWIPQTMHIS_N->LOT_CMF_20, MWIPQTMHIS->LOT_CMF_20, sizeof(MWIPQTMHIS->LOT_CMF_20));
}


/* Del Null Function */
void DBC_del_null_mwipqtmhis(struct MWIPQTMHIS_N_TAG *MWIPQTMHIS_N, struct MWIPQTMHIS_TAG *MWIPQTMHIS)
{
    MEMCPY_DN(MWIPQTMHIS->FACTORY, MWIPQTMHIS_N->FACTORY, sizeof(MWIPQTMHIS->FACTORY));
    MEMCPY_DN(MWIPQTMHIS->MAT_ID, MWIPQTMHIS_N->MAT_ID, sizeof(MWIPQTMHIS->MAT_ID));
    MWIPQTMHIS->MAT_VER = MWIPQTMHIS_N->MAT_VER;
    MEMCPY_DN(MWIPQTMHIS->FLOW, MWIPQTMHIS_N->FLOW, sizeof(MWIPQTMHIS->FLOW));
    MWIPQTMHIS->FLOW_SEQ_NUM = MWIPQTMHIS_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPQTMHIS->OPER, MWIPQTMHIS_N->OPER, sizeof(MWIPQTMHIS->OPER));
    MEMCPY_DN(MWIPQTMHIS->FROM_FACTORY, MWIPQTMHIS_N->FROM_FACTORY, sizeof(MWIPQTMHIS->FROM_FACTORY));
    MEMCPY_DN(MWIPQTMHIS->FROM_FLOW, MWIPQTMHIS_N->FROM_FLOW, sizeof(MWIPQTMHIS->FROM_FLOW));
    MWIPQTMHIS->FROM_FLOW_SEQ_NUM = MWIPQTMHIS_N->FROM_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPQTMHIS->FROM_OPER, MWIPQTMHIS_N->FROM_OPER, sizeof(MWIPQTMHIS->FROM_OPER));
    MWIPQTMHIS->FROM_POINT_FLAG = MWIPQTMHIS_N->FROM_POINT_FLAG[0];
    MWIPQTMHIS->CHECK_POINT_FLAG = MWIPQTMHIS_N->CHECK_POINT_FLAG[0];
    MEMCPY_DN(MWIPQTMHIS->LOT_ID, MWIPQTMHIS_N->LOT_ID, sizeof(MWIPQTMHIS->LOT_ID));
    MEMCPY_DN(MWIPQTMHIS->TRAN_TIME, MWIPQTMHIS_N->TRAN_TIME, sizeof(MWIPQTMHIS->TRAN_TIME));
    MWIPQTMHIS->HIST_SEQ = MWIPQTMHIS_N->HIST_SEQ;
    MWIPQTMHIS->PROCESS_LEVEL = MWIPQTMHIS_N->PROCESS_LEVEL[0];
    MEMCPY_DN(MWIPQTMHIS->CUR_FLOW, MWIPQTMHIS_N->CUR_FLOW, sizeof(MWIPQTMHIS->CUR_FLOW));
    MWIPQTMHIS->CUR_FLOW_SEQ_NUM = MWIPQTMHIS_N->CUR_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPQTMHIS->CUR_OPER, MWIPQTMHIS_N->CUR_OPER, sizeof(MWIPQTMHIS->CUR_OPER));
    MWIPQTMHIS->QUE_TIME = MWIPQTMHIS_N->QUE_TIME;
    MEMCPY_DN(MWIPQTMHIS->ALARM_ID, MWIPQTMHIS_N->ALARM_ID, sizeof(MWIPQTMHIS->ALARM_ID));
    MEMCPY_DN(MWIPQTMHIS->MSG, MWIPQTMHIS_N->MSG, sizeof(MWIPQTMHIS->MSG));
    MEMCPY_DN(MWIPQTMHIS->USER_GRP_ID, MWIPQTMHIS_N->USER_GRP_ID, sizeof(MWIPQTMHIS->USER_GRP_ID));
    MWIPQTMHIS->UPPER_QUE_TIME = MWIPQTMHIS_N->UPPER_QUE_TIME;
    MWIPQTMHIS->LOWER_QUE_TIME = MWIPQTMHIS_N->LOWER_QUE_TIME;
    MWIPQTMHIS->DIFF_QUE_TIME = MWIPQTMHIS_N->DIFF_QUE_TIME;
    MEMCPY_DN(MWIPQTMHIS->TRAN_CODE, MWIPQTMHIS_N->TRAN_CODE, sizeof(MWIPQTMHIS->TRAN_CODE));
    MEMCPY_DN(MWIPQTMHIS->REASON_CODE, MWIPQTMHIS_N->REASON_CODE, sizeof(MWIPQTMHIS->REASON_CODE));
    MEMCPY_DN(MWIPQTMHIS->HOLD_PASSWORD, MWIPQTMHIS_N->HOLD_PASSWORD, sizeof(MWIPQTMHIS->HOLD_PASSWORD));
    MEMCPY_DN(MWIPQTMHIS->HOLD_PRV_GRP_ID, MWIPQTMHIS_N->HOLD_PRV_GRP_ID, sizeof(MWIPQTMHIS->HOLD_PRV_GRP_ID));
    MEMCPY_DN(MWIPQTMHIS->TRAN_TO_FLOW, MWIPQTMHIS_N->TRAN_TO_FLOW, sizeof(MWIPQTMHIS->TRAN_TO_FLOW));
    MWIPQTMHIS->TRAN_TO_FLOW_SEQ_NUM = MWIPQTMHIS_N->TRAN_TO_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPQTMHIS->TRAN_TO_OPER, MWIPQTMHIS_N->TRAN_TO_OPER, sizeof(MWIPQTMHIS->TRAN_TO_OPER));
    MEMCPY_DN(MWIPQTMHIS->RET_FLOW, MWIPQTMHIS_N->RET_FLOW, sizeof(MWIPQTMHIS->RET_FLOW));
    MWIPQTMHIS->RET_FLOW_SEQ_NUM = MWIPQTMHIS_N->RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPQTMHIS->RET_OPER, MWIPQTMHIS_N->RET_OPER, sizeof(MWIPQTMHIS->RET_OPER));
    MWIPQTMHIS->RWK_RET_CLEAR_FLAG = MWIPQTMHIS_N->RWK_RET_CLEAR_FLAG[0];
    MEMCPY_DN(MWIPQTMHIS->CMF_1, MWIPQTMHIS_N->CMF_1, sizeof(MWIPQTMHIS->CMF_1));
    MEMCPY_DN(MWIPQTMHIS->CMF_2, MWIPQTMHIS_N->CMF_2, sizeof(MWIPQTMHIS->CMF_2));
    MEMCPY_DN(MWIPQTMHIS->CMF_3, MWIPQTMHIS_N->CMF_3, sizeof(MWIPQTMHIS->CMF_3));
    MEMCPY_DN(MWIPQTMHIS->CMF_4, MWIPQTMHIS_N->CMF_4, sizeof(MWIPQTMHIS->CMF_4));
    MEMCPY_DN(MWIPQTMHIS->CMF_5, MWIPQTMHIS_N->CMF_5, sizeof(MWIPQTMHIS->CMF_5));
    MEMCPY_DN(MWIPQTMHIS->CMF_6, MWIPQTMHIS_N->CMF_6, sizeof(MWIPQTMHIS->CMF_6));
    MEMCPY_DN(MWIPQTMHIS->CMF_7, MWIPQTMHIS_N->CMF_7, sizeof(MWIPQTMHIS->CMF_7));
    MEMCPY_DN(MWIPQTMHIS->CMF_8, MWIPQTMHIS_N->CMF_8, sizeof(MWIPQTMHIS->CMF_8));
    MEMCPY_DN(MWIPQTMHIS->CMF_9, MWIPQTMHIS_N->CMF_9, sizeof(MWIPQTMHIS->CMF_9));
    MEMCPY_DN(MWIPQTMHIS->CMF_10, MWIPQTMHIS_N->CMF_10, sizeof(MWIPQTMHIS->CMF_10));
    MEMCPY_DN(MWIPQTMHIS->CMF_11, MWIPQTMHIS_N->CMF_11, sizeof(MWIPQTMHIS->CMF_11));
    MEMCPY_DN(MWIPQTMHIS->CMF_12, MWIPQTMHIS_N->CMF_12, sizeof(MWIPQTMHIS->CMF_12));
    MEMCPY_DN(MWIPQTMHIS->CMF_13, MWIPQTMHIS_N->CMF_13, sizeof(MWIPQTMHIS->CMF_13));
    MEMCPY_DN(MWIPQTMHIS->CMF_14, MWIPQTMHIS_N->CMF_14, sizeof(MWIPQTMHIS->CMF_14));
    MEMCPY_DN(MWIPQTMHIS->CMF_15, MWIPQTMHIS_N->CMF_15, sizeof(MWIPQTMHIS->CMF_15));
    MEMCPY_DN(MWIPQTMHIS->CMF_16, MWIPQTMHIS_N->CMF_16, sizeof(MWIPQTMHIS->CMF_16));
    MEMCPY_DN(MWIPQTMHIS->CMF_17, MWIPQTMHIS_N->CMF_17, sizeof(MWIPQTMHIS->CMF_17));
    MEMCPY_DN(MWIPQTMHIS->CMF_18, MWIPQTMHIS_N->CMF_18, sizeof(MWIPQTMHIS->CMF_18));
    MEMCPY_DN(MWIPQTMHIS->CMF_19, MWIPQTMHIS_N->CMF_19, sizeof(MWIPQTMHIS->CMF_19));
    MEMCPY_DN(MWIPQTMHIS->CMF_20, MWIPQTMHIS_N->CMF_20, sizeof(MWIPQTMHIS->CMF_20));
    MEMCPY_DN(MWIPQTMHIS->LOT_COMMENT, MWIPQTMHIS_N->LOT_COMMENT, sizeof(MWIPQTMHIS->LOT_COMMENT));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_1, MWIPQTMHIS_N->LOT_CMF_1, sizeof(MWIPQTMHIS->LOT_CMF_1));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_2, MWIPQTMHIS_N->LOT_CMF_2, sizeof(MWIPQTMHIS->LOT_CMF_2));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_3, MWIPQTMHIS_N->LOT_CMF_3, sizeof(MWIPQTMHIS->LOT_CMF_3));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_4, MWIPQTMHIS_N->LOT_CMF_4, sizeof(MWIPQTMHIS->LOT_CMF_4));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_5, MWIPQTMHIS_N->LOT_CMF_5, sizeof(MWIPQTMHIS->LOT_CMF_5));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_6, MWIPQTMHIS_N->LOT_CMF_6, sizeof(MWIPQTMHIS->LOT_CMF_6));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_7, MWIPQTMHIS_N->LOT_CMF_7, sizeof(MWIPQTMHIS->LOT_CMF_7));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_8, MWIPQTMHIS_N->LOT_CMF_8, sizeof(MWIPQTMHIS->LOT_CMF_8));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_9, MWIPQTMHIS_N->LOT_CMF_9, sizeof(MWIPQTMHIS->LOT_CMF_9));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_10, MWIPQTMHIS_N->LOT_CMF_10, sizeof(MWIPQTMHIS->LOT_CMF_10));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_11, MWIPQTMHIS_N->LOT_CMF_11, sizeof(MWIPQTMHIS->LOT_CMF_11));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_12, MWIPQTMHIS_N->LOT_CMF_12, sizeof(MWIPQTMHIS->LOT_CMF_12));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_13, MWIPQTMHIS_N->LOT_CMF_13, sizeof(MWIPQTMHIS->LOT_CMF_13));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_14, MWIPQTMHIS_N->LOT_CMF_14, sizeof(MWIPQTMHIS->LOT_CMF_14));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_15, MWIPQTMHIS_N->LOT_CMF_15, sizeof(MWIPQTMHIS->LOT_CMF_15));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_16, MWIPQTMHIS_N->LOT_CMF_16, sizeof(MWIPQTMHIS->LOT_CMF_16));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_17, MWIPQTMHIS_N->LOT_CMF_17, sizeof(MWIPQTMHIS->LOT_CMF_17));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_18, MWIPQTMHIS_N->LOT_CMF_18, sizeof(MWIPQTMHIS->LOT_CMF_18));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_19, MWIPQTMHIS_N->LOT_CMF_19, sizeof(MWIPQTMHIS->LOT_CMF_19));
    MEMCPY_DN(MWIPQTMHIS->LOT_CMF_20, MWIPQTMHIS_N->LOT_CMF_20, sizeof(MWIPQTMHIS->LOT_CMF_20));
}


