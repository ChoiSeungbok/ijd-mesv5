
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
    "DBC_mwipfaccmf.pc"
};


static unsigned int sqlctx = 9139259;


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
            void  *sqhstv[88];
   unsigned int   sqhstl[88];
            int   sqhsts[88];
            void  *sqindv[88];
            int   sqinds[88];
   unsigned int   sqharm[88];
   unsigned int   *sqharc[88];
   unsigned short  sqadto[88];
   unsigned short  sqtdso[88];
} sqlstm = {13,88};

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
"select FACTORY ,ITEM_NAME ,PRT_1 ,PRT_2 ,PRT_3 ,PRT_4 ,PRT_5 ,PRT_6 ,PRT_7 \
,PRT_8 ,PRT_9 ,PRT_10 ,PRT_11 ,PRT_12 ,PRT_13 ,PRT_14 ,PRT_15 ,PRT_16 ,PRT_17\
 ,PRT_18 ,PRT_19 ,PRT_20 ,FMT_1 ,FMT_2 ,FMT_3 ,FMT_4 ,FMT_5 ,FMT_6 ,FMT_7 ,FM\
T_8 ,FMT_9 ,FMT_10 ,FMT_11 ,FMT_12 ,FMT_13 ,FMT_14 ,FMT_15 ,FMT_16 ,FMT_17 ,F\
MT_18 ,FMT_19 ,FMT_20 ,OPT_1 ,OPT_2 ,OPT_3 ,OPT_4 ,OPT_5 ,OPT_6 ,OPT_7 ,OPT_8\
 ,OPT_9 ,OPT_10 ,OPT_11 ,OPT_12 ,OPT_13 ,OPT_14 ,OPT_15 ,OPT_16 ,OPT_17 ,OPT_\
18 ,OPT_19 ,OPT_20 ,TBL_1 ,TBL_2 ,TBL_3 ,TBL_4 ,TBL_5 ,TBL_6 ,TBL_7 ,TBL_8 ,T\
BL_9 ,TBL_10 ,TBL_11 ,TBL_12 ,TBL_13 ,TBL_14 ,TBL_15 ,TBL_16 ,TBL_17 ,TBL_18 \
,TBL_19 ,TBL_20 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  fr\
om MWIPFACCMF where FACTORY=:b0 order by ITEM_NAME asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1167,0,4,45,0,0,88,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
372,0,0,2,1179,0,4,256,0,0,88,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
739,0,0,3,80,0,4,470,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
766,0,0,4,62,0,2,505,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
789,0,0,5,1049,0,3,533,0,0,86,86,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,
1148,0,0,6,1050,0,5,728,0,0,86,86,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,
1507,0,0,7,1013,0,5,818,0,0,84,84,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,
1858,0,0,8,758,0,9,1022,0,0,1,1,0,1,0,1,97,0,0,
1877,0,0,8,0,0,13,1050,0,0,86,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
2236,0,0,8,0,0,15,1166,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipfaccmf.pc
**    Description : Table Access Function Source File
**    Create date : 2004/11/30 16:20:02
**
**    Generated by DB Common Generator
**    Copyright (C), MIRACOM,INC.
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
void DBC_add_null_mwipfaccmf(struct MWIPFACCMF_N_TAG *MWIPFACCMF_N, struct MWIPFACCMF_TAG *MWIPFACCMF);
void DBC_del_null_mwipfaccmf(struct MWIPFACCMF_N_TAG *MWIPFACCMF_N, struct MWIPFACCMF_TAG *MWIPFACCMF);


/* SQL SELECT Function */
void DBC_select_mwipfaccmf(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         ITEM_NAME,
                         PRT_1,
                         PRT_2,
                         PRT_3,
                         PRT_4,
                         PRT_5,
                         PRT_6,
                         PRT_7,
                         PRT_8,
                         PRT_9,
                         PRT_10,
                         PRT_11,
                         PRT_12,
                         PRT_13,
                         PRT_14,
                         PRT_15,
                         PRT_16,
                         PRT_17,
                         PRT_18,
                         PRT_19,
                         PRT_20,
                         FMT_1,
                         FMT_2,
                         FMT_3,
                         FMT_4,
                         FMT_5,
                         FMT_6,
                         FMT_7,
                         FMT_8,
                         FMT_9,
                         FMT_10,
                         FMT_11,
                         FMT_12,
                         FMT_13,
                         FMT_14,
                         FMT_15,
                         FMT_16,
                         FMT_17,
                         FMT_18,
                         FMT_19,
                         FMT_20,
                         OPT_1,
                         OPT_2,
                         OPT_3,
                         OPT_4,
                         OPT_5,
                         OPT_6,
                         OPT_7,
                         OPT_8,
                         OPT_9,
                         OPT_10,
                         OPT_11,
                         OPT_12,
                         OPT_13,
                         OPT_14,
                         OPT_15,
                         OPT_16,
                         OPT_17,
                         OPT_18,
                         OPT_19,
                         OPT_20,
                         TBL_1,
                         TBL_2,
                         TBL_3,
                         TBL_4,
                         TBL_5,
                         TBL_6,
                         TBL_7,
                         TBL_8,
                         TBL_9,
                         TBL_10,
                         TBL_11,
                         TBL_12,
                         TBL_13,
                         TBL_14,
                         TBL_15,
                         TBL_16,
                         TBL_17,
                         TBL_18,
                         TBL_19,
                         TBL_20,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MWIPFACCMF_N.FACTORY,
                    :MWIPFACCMF_N.ITEM_NAME,
                    :MWIPFACCMF_N.PRT_1,
                    :MWIPFACCMF_N.PRT_2,
                    :MWIPFACCMF_N.PRT_3,
                    :MWIPFACCMF_N.PRT_4,
                    :MWIPFACCMF_N.PRT_5,
                    :MWIPFACCMF_N.PRT_6,
                    :MWIPFACCMF_N.PRT_7,
                    :MWIPFACCMF_N.PRT_8,
                    :MWIPFACCMF_N.PRT_9,
                    :MWIPFACCMF_N.PRT_10,
                    :MWIPFACCMF_N.PRT_11,
                    :MWIPFACCMF_N.PRT_12,
                    :MWIPFACCMF_N.PRT_13,
                    :MWIPFACCMF_N.PRT_14,
                    :MWIPFACCMF_N.PRT_15,
                    :MWIPFACCMF_N.PRT_16,
                    :MWIPFACCMF_N.PRT_17,
                    :MWIPFACCMF_N.PRT_18,
                    :MWIPFACCMF_N.PRT_19,
                    :MWIPFACCMF_N.PRT_20,
                    :MWIPFACCMF_N.FMT_1,
                    :MWIPFACCMF_N.FMT_2,
                    :MWIPFACCMF_N.FMT_3,
                    :MWIPFACCMF_N.FMT_4,
                    :MWIPFACCMF_N.FMT_5,
                    :MWIPFACCMF_N.FMT_6,
                    :MWIPFACCMF_N.FMT_7,
                    :MWIPFACCMF_N.FMT_8,
                    :MWIPFACCMF_N.FMT_9,
                    :MWIPFACCMF_N.FMT_10,
                    :MWIPFACCMF_N.FMT_11,
                    :MWIPFACCMF_N.FMT_12,
                    :MWIPFACCMF_N.FMT_13,
                    :MWIPFACCMF_N.FMT_14,
                    :MWIPFACCMF_N.FMT_15,
                    :MWIPFACCMF_N.FMT_16,
                    :MWIPFACCMF_N.FMT_17,
                    :MWIPFACCMF_N.FMT_18,
                    :MWIPFACCMF_N.FMT_19,
                    :MWIPFACCMF_N.FMT_20,
                    :MWIPFACCMF_N.OPT_1,
                    :MWIPFACCMF_N.OPT_2,
                    :MWIPFACCMF_N.OPT_3,
                    :MWIPFACCMF_N.OPT_4,
                    :MWIPFACCMF_N.OPT_5,
                    :MWIPFACCMF_N.OPT_6,
                    :MWIPFACCMF_N.OPT_7,
                    :MWIPFACCMF_N.OPT_8,
                    :MWIPFACCMF_N.OPT_9,
                    :MWIPFACCMF_N.OPT_10,
                    :MWIPFACCMF_N.OPT_11,
                    :MWIPFACCMF_N.OPT_12,
                    :MWIPFACCMF_N.OPT_13,
                    :MWIPFACCMF_N.OPT_14,
                    :MWIPFACCMF_N.OPT_15,
                    :MWIPFACCMF_N.OPT_16,
                    :MWIPFACCMF_N.OPT_17,
                    :MWIPFACCMF_N.OPT_18,
                    :MWIPFACCMF_N.OPT_19,
                    :MWIPFACCMF_N.OPT_20,
                    :MWIPFACCMF_N.TBL_1,
                    :MWIPFACCMF_N.TBL_2,
                    :MWIPFACCMF_N.TBL_3,
                    :MWIPFACCMF_N.TBL_4,
                    :MWIPFACCMF_N.TBL_5,
                    :MWIPFACCMF_N.TBL_6,
                    :MWIPFACCMF_N.TBL_7,
                    :MWIPFACCMF_N.TBL_8,
                    :MWIPFACCMF_N.TBL_9,
                    :MWIPFACCMF_N.TBL_10,
                    :MWIPFACCMF_N.TBL_11,
                    :MWIPFACCMF_N.TBL_12,
                    :MWIPFACCMF_N.TBL_13,
                    :MWIPFACCMF_N.TBL_14,
                    :MWIPFACCMF_N.TBL_15,
                    :MWIPFACCMF_N.TBL_16,
                    :MWIPFACCMF_N.TBL_17,
                    :MWIPFACCMF_N.TBL_18,
                    :MWIPFACCMF_N.TBL_19,
                    :MWIPFACCMF_N.TBL_20,
                    :MWIPFACCMF_N.CREATE_USER_ID,
                    :MWIPFACCMF_N.CREATE_TIME,
                    :MWIPFACCMF_N.UPDATE_USER_ID,
                    :MWIPFACCMF_N.UPDATE_TIME
                FROM MWIPFACCMF
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,ITEM_NAME ,PRT_1 ,PRT_2 ,PRT_3 ,PRT_4 ,PRT_5 \
,PRT_6 ,PRT_7 ,PRT_8 ,PRT_9 ,PRT_10 ,PRT_11 ,PRT_12 ,PRT_13 ,PRT_14 ,PRT_15 \
,PRT_16 ,PRT_17 ,PRT_18 ,PRT_19 ,PRT_20 ,FMT_1 ,FMT_2 ,FMT_3 ,FMT_4 ,FMT_5 ,\
FMT_6 ,FMT_7 ,FMT_8 ,FMT_9 ,FMT_10 ,FMT_11 ,FMT_12 ,FMT_13 ,FMT_14 ,FMT_15 ,\
FMT_16 ,FMT_17 ,FMT_18 ,FMT_19 ,FMT_20 ,OPT_1 ,OPT_2 ,OPT_3 ,OPT_4 ,OPT_5 ,O\
PT_6 ,OPT_7 ,OPT_8 ,OPT_9 ,OPT_10 ,OPT_11 ,OPT_12 ,OPT_13 ,OPT_14 ,OPT_15 ,O\
PT_16 ,OPT_17 ,OPT_18 ,OPT_19 ,OPT_20 ,TBL_1 ,TBL_2 ,TBL_3 ,TBL_4 ,TBL_5 ,TB\
L_6 ,TBL_7 ,TBL_8 ,TBL_9 ,TBL_10 ,TBL_11 ,TBL_12 ,TBL_13 ,TBL_14 ,TBL_15 ,TB\
L_16 ,TBL_17 ,TBL_18 ,TBL_19 ,TBL_20 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_US\
ER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b2\
7,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42\
,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,\
:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:");
            sqlstm.stmt = "b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77\
,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85  from MWIPFACCMF where (FACTORY=:b0 \
and ITEM_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_1);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_2);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_3);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_4);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_5);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_6);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_7);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_8);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_9);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_10);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_11);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_12);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_13);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_14);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_15);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_16);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_17);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_18);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.PRT_19);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.PRT_20);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_1);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_2);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_3);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_4);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_5);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_6);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_7);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_8);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_9);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_10);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_11);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_12);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_13);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_14);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_15);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_16);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_17);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_18);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.FMT_19);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.FMT_20);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_1);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_2);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_3);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_4);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_5);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_6);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_7);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_8);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_9);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_10);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_11);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_12);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_13);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_14);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_15);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_16);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_17);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_18);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.OPT_19);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.OPT_20);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_1);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_2);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_3);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_4);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_5);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_6);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_7);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_8);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_9);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_10);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_11);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_12);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_13);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_14);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_15);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_16);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_17);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_18);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.TBL_19);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.TBL_20);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.CREATE_USER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.CREATE_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[86] = (unsigned int  )11;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[87] = (unsigned int  )21;
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
        DBC_del_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    }
    DB_stop_query_timer("DBC_select_mwipfaccmf", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipfaccmf_for_update(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         ITEM_NAME,
                         PRT_1,
                         PRT_2,
                         PRT_3,
                         PRT_4,
                         PRT_5,
                         PRT_6,
                         PRT_7,
                         PRT_8,
                         PRT_9,
                         PRT_10,
                         PRT_11,
                         PRT_12,
                         PRT_13,
                         PRT_14,
                         PRT_15,
                         PRT_16,
                         PRT_17,
                         PRT_18,
                         PRT_19,
                         PRT_20,
                         FMT_1,
                         FMT_2,
                         FMT_3,
                         FMT_4,
                         FMT_5,
                         FMT_6,
                         FMT_7,
                         FMT_8,
                         FMT_9,
                         FMT_10,
                         FMT_11,
                         FMT_12,
                         FMT_13,
                         FMT_14,
                         FMT_15,
                         FMT_16,
                         FMT_17,
                         FMT_18,
                         FMT_19,
                         FMT_20,
                         OPT_1,
                         OPT_2,
                         OPT_3,
                         OPT_4,
                         OPT_5,
                         OPT_6,
                         OPT_7,
                         OPT_8,
                         OPT_9,
                         OPT_10,
                         OPT_11,
                         OPT_12,
                         OPT_13,
                         OPT_14,
                         OPT_15,
                         OPT_16,
                         OPT_17,
                         OPT_18,
                         OPT_19,
                         OPT_20,
                         TBL_1,
                         TBL_2,
                         TBL_3,
                         TBL_4,
                         TBL_5,
                         TBL_6,
                         TBL_7,
                         TBL_8,
                         TBL_9,
                         TBL_10,
                         TBL_11,
                         TBL_12,
                         TBL_13,
                         TBL_14,
                         TBL_15,
                         TBL_16,
                         TBL_17,
                         TBL_18,
                         TBL_19,
                         TBL_20,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME
                INTO 
                    :MWIPFACCMF_N.FACTORY,
                    :MWIPFACCMF_N.ITEM_NAME,
                    :MWIPFACCMF_N.PRT_1,
                    :MWIPFACCMF_N.PRT_2,
                    :MWIPFACCMF_N.PRT_3,
                    :MWIPFACCMF_N.PRT_4,
                    :MWIPFACCMF_N.PRT_5,
                    :MWIPFACCMF_N.PRT_6,
                    :MWIPFACCMF_N.PRT_7,
                    :MWIPFACCMF_N.PRT_8,
                    :MWIPFACCMF_N.PRT_9,
                    :MWIPFACCMF_N.PRT_10,
                    :MWIPFACCMF_N.PRT_11,
                    :MWIPFACCMF_N.PRT_12,
                    :MWIPFACCMF_N.PRT_13,
                    :MWIPFACCMF_N.PRT_14,
                    :MWIPFACCMF_N.PRT_15,
                    :MWIPFACCMF_N.PRT_16,
                    :MWIPFACCMF_N.PRT_17,
                    :MWIPFACCMF_N.PRT_18,
                    :MWIPFACCMF_N.PRT_19,
                    :MWIPFACCMF_N.PRT_20,
                    :MWIPFACCMF_N.FMT_1,
                    :MWIPFACCMF_N.FMT_2,
                    :MWIPFACCMF_N.FMT_3,
                    :MWIPFACCMF_N.FMT_4,
                    :MWIPFACCMF_N.FMT_5,
                    :MWIPFACCMF_N.FMT_6,
                    :MWIPFACCMF_N.FMT_7,
                    :MWIPFACCMF_N.FMT_8,
                    :MWIPFACCMF_N.FMT_9,
                    :MWIPFACCMF_N.FMT_10,
                    :MWIPFACCMF_N.FMT_11,
                    :MWIPFACCMF_N.FMT_12,
                    :MWIPFACCMF_N.FMT_13,
                    :MWIPFACCMF_N.FMT_14,
                    :MWIPFACCMF_N.FMT_15,
                    :MWIPFACCMF_N.FMT_16,
                    :MWIPFACCMF_N.FMT_17,
                    :MWIPFACCMF_N.FMT_18,
                    :MWIPFACCMF_N.FMT_19,
                    :MWIPFACCMF_N.FMT_20,
                    :MWIPFACCMF_N.OPT_1,
                    :MWIPFACCMF_N.OPT_2,
                    :MWIPFACCMF_N.OPT_3,
                    :MWIPFACCMF_N.OPT_4,
                    :MWIPFACCMF_N.OPT_5,
                    :MWIPFACCMF_N.OPT_6,
                    :MWIPFACCMF_N.OPT_7,
                    :MWIPFACCMF_N.OPT_8,
                    :MWIPFACCMF_N.OPT_9,
                    :MWIPFACCMF_N.OPT_10,
                    :MWIPFACCMF_N.OPT_11,
                    :MWIPFACCMF_N.OPT_12,
                    :MWIPFACCMF_N.OPT_13,
                    :MWIPFACCMF_N.OPT_14,
                    :MWIPFACCMF_N.OPT_15,
                    :MWIPFACCMF_N.OPT_16,
                    :MWIPFACCMF_N.OPT_17,
                    :MWIPFACCMF_N.OPT_18,
                    :MWIPFACCMF_N.OPT_19,
                    :MWIPFACCMF_N.OPT_20,
                    :MWIPFACCMF_N.TBL_1,
                    :MWIPFACCMF_N.TBL_2,
                    :MWIPFACCMF_N.TBL_3,
                    :MWIPFACCMF_N.TBL_4,
                    :MWIPFACCMF_N.TBL_5,
                    :MWIPFACCMF_N.TBL_6,
                    :MWIPFACCMF_N.TBL_7,
                    :MWIPFACCMF_N.TBL_8,
                    :MWIPFACCMF_N.TBL_9,
                    :MWIPFACCMF_N.TBL_10,
                    :MWIPFACCMF_N.TBL_11,
                    :MWIPFACCMF_N.TBL_12,
                    :MWIPFACCMF_N.TBL_13,
                    :MWIPFACCMF_N.TBL_14,
                    :MWIPFACCMF_N.TBL_15,
                    :MWIPFACCMF_N.TBL_16,
                    :MWIPFACCMF_N.TBL_17,
                    :MWIPFACCMF_N.TBL_18,
                    :MWIPFACCMF_N.TBL_19,
                    :MWIPFACCMF_N.TBL_20,
                    :MWIPFACCMF_N.CREATE_USER_ID,
                    :MWIPFACCMF_N.CREATE_TIME,
                    :MWIPFACCMF_N.UPDATE_USER_ID,
                    :MWIPFACCMF_N.UPDATE_TIME
                FROM MWIPFACCMF
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,ITEM_NAME ,PRT_1 ,PRT_2 ,PRT_3 ,PRT_4 ,PRT_5 \
,PRT_6 ,PRT_7 ,PRT_8 ,PRT_9 ,PRT_10 ,PRT_11 ,PRT_12 ,PRT_13 ,PRT_14 ,PRT_15 \
,PRT_16 ,PRT_17 ,PRT_18 ,PRT_19 ,PRT_20 ,FMT_1 ,FMT_2 ,FMT_3 ,FMT_4 ,FMT_5 ,\
FMT_6 ,FMT_7 ,FMT_8 ,FMT_9 ,FMT_10 ,FMT_11 ,FMT_12 ,FMT_13 ,FMT_14 ,FMT_15 ,\
FMT_16 ,FMT_17 ,FMT_18 ,FMT_19 ,FMT_20 ,OPT_1 ,OPT_2 ,OPT_3 ,OPT_4 ,OPT_5 ,O\
PT_6 ,OPT_7 ,OPT_8 ,OPT_9 ,OPT_10 ,OPT_11 ,OPT_12 ,OPT_13 ,OPT_14 ,OPT_15 ,O\
PT_16 ,OPT_17 ,OPT_18 ,OPT_19 ,OPT_20 ,TBL_1 ,TBL_2 ,TBL_3 ,TBL_4 ,TBL_5 ,TB\
L_6 ,TBL_7 ,TBL_8 ,TBL_9 ,TBL_10 ,TBL_11 ,TBL_12 ,TBL_13 ,TBL_14 ,TBL_15 ,TB\
L_16 ,TBL_17 ,TBL_18 ,TBL_19 ,TBL_20 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_US\
ER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b2\
7,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42\
,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,\
:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:");
            sqlstm.stmt = "b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77\
,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85  from MWIPFACCMF where (FACTORY=:b0 \
and ITEM_NAME=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )372;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_1);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_2);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_3);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_4);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_5);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_6);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_7);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_8);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_9);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_10);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_11);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_12);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_13);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_14);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_15);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_16);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_17);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_18);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.PRT_19);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.PRT_20);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_1);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_2);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_3);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_4);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_5);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_6);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_7);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_8);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_9);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_10);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_11);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_12);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_13);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_14);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_15);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_16);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_17);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_18);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.FMT_19);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.FMT_20);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_1);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_2);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_3);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_4);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_5);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_6);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_7);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_8);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_9);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_10);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_11);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_12);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_13);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_14);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_15);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_16);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_17);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_18);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.OPT_19);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.OPT_20);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_1);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_2);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_3);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_4);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_5);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_6);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_7);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_8);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_9);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_10);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_11);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_12);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_13);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_14);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_15);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_16);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_17);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_18);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.TBL_19);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.TBL_20);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.CREATE_USER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.CREATE_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[86] = (unsigned int  )11;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[87] = (unsigned int  )21;
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
        DBC_del_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    }
    DB_stop_query_timer("DBC_select_mwipfaccmf_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipfaccmf_scalar(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPFACCMF
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPFACCMF where\
 (FACTORY=:b1 and ITEM_NAME=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )739;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
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

    DB_stop_query_timer("DBC_select_mwipfaccmf_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipfaccmf(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPFACCMF
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPFACCMF  where (FACTORY=:b0 and \
ITEM_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )766;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
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
    DB_stop_query_timer("DBC_delete_mwipfaccmf", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipfaccmf(struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPFACCMF (
                    FACTORY,
                    ITEM_NAME,
                    PRT_1,
                    PRT_2,
                    PRT_3,
                    PRT_4,
                    PRT_5,
                    PRT_6,
                    PRT_7,
                    PRT_8,
                    PRT_9,
                    PRT_10,
                    PRT_11,
                    PRT_12,
                    PRT_13,
                    PRT_14,
                    PRT_15,
                    PRT_16,
                    PRT_17,
                    PRT_18,
                    PRT_19,
                    PRT_20,
                    FMT_1,
                    FMT_2,
                    FMT_3,
                    FMT_4,
                    FMT_5,
                    FMT_6,
                    FMT_7,
                    FMT_8,
                    FMT_9,
                    FMT_10,
                    FMT_11,
                    FMT_12,
                    FMT_13,
                    FMT_14,
                    FMT_15,
                    FMT_16,
                    FMT_17,
                    FMT_18,
                    FMT_19,
                    FMT_20,
                    OPT_1,
                    OPT_2,
                    OPT_3,
                    OPT_4,
                    OPT_5,
                    OPT_6,
                    OPT_7,
                    OPT_8,
                    OPT_9,
                    OPT_10,
                    OPT_11,
                    OPT_12,
                    OPT_13,
                    OPT_14,
                    OPT_15,
                    OPT_16,
                    OPT_17,
                    OPT_18,
                    OPT_19,
                    OPT_20,
                    TBL_1,
                    TBL_2,
                    TBL_3,
                    TBL_4,
                    TBL_5,
                    TBL_6,
                    TBL_7,
                    TBL_8,
                    TBL_9,
                    TBL_10,
                    TBL_11,
                    TBL_12,
                    TBL_13,
                    TBL_14,
                    TBL_15,
                    TBL_16,
                    TBL_17,
                    TBL_18,
                    TBL_19,
                    TBL_20,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
        )
        VALUES (
                    :MWIPFACCMF_N.FACTORY,
                    :MWIPFACCMF_N.ITEM_NAME,
                    :MWIPFACCMF_N.PRT_1,
                    :MWIPFACCMF_N.PRT_2,
                    :MWIPFACCMF_N.PRT_3,
                    :MWIPFACCMF_N.PRT_4,
                    :MWIPFACCMF_N.PRT_5,
                    :MWIPFACCMF_N.PRT_6,
                    :MWIPFACCMF_N.PRT_7,
                    :MWIPFACCMF_N.PRT_8,
                    :MWIPFACCMF_N.PRT_9,
                    :MWIPFACCMF_N.PRT_10,
                    :MWIPFACCMF_N.PRT_11,
                    :MWIPFACCMF_N.PRT_12,
                    :MWIPFACCMF_N.PRT_13,
                    :MWIPFACCMF_N.PRT_14,
                    :MWIPFACCMF_N.PRT_15,
                    :MWIPFACCMF_N.PRT_16,
                    :MWIPFACCMF_N.PRT_17,
                    :MWIPFACCMF_N.PRT_18,
                    :MWIPFACCMF_N.PRT_19,
                    :MWIPFACCMF_N.PRT_20,
                    :MWIPFACCMF_N.FMT_1,
                    :MWIPFACCMF_N.FMT_2,
                    :MWIPFACCMF_N.FMT_3,
                    :MWIPFACCMF_N.FMT_4,
                    :MWIPFACCMF_N.FMT_5,
                    :MWIPFACCMF_N.FMT_6,
                    :MWIPFACCMF_N.FMT_7,
                    :MWIPFACCMF_N.FMT_8,
                    :MWIPFACCMF_N.FMT_9,
                    :MWIPFACCMF_N.FMT_10,
                    :MWIPFACCMF_N.FMT_11,
                    :MWIPFACCMF_N.FMT_12,
                    :MWIPFACCMF_N.FMT_13,
                    :MWIPFACCMF_N.FMT_14,
                    :MWIPFACCMF_N.FMT_15,
                    :MWIPFACCMF_N.FMT_16,
                    :MWIPFACCMF_N.FMT_17,
                    :MWIPFACCMF_N.FMT_18,
                    :MWIPFACCMF_N.FMT_19,
                    :MWIPFACCMF_N.FMT_20,
                    :MWIPFACCMF_N.OPT_1,
                    :MWIPFACCMF_N.OPT_2,
                    :MWIPFACCMF_N.OPT_3,
                    :MWIPFACCMF_N.OPT_4,
                    :MWIPFACCMF_N.OPT_5,
                    :MWIPFACCMF_N.OPT_6,
                    :MWIPFACCMF_N.OPT_7,
                    :MWIPFACCMF_N.OPT_8,
                    :MWIPFACCMF_N.OPT_9,
                    :MWIPFACCMF_N.OPT_10,
                    :MWIPFACCMF_N.OPT_11,
                    :MWIPFACCMF_N.OPT_12,
                    :MWIPFACCMF_N.OPT_13,
                    :MWIPFACCMF_N.OPT_14,
                    :MWIPFACCMF_N.OPT_15,
                    :MWIPFACCMF_N.OPT_16,
                    :MWIPFACCMF_N.OPT_17,
                    :MWIPFACCMF_N.OPT_18,
                    :MWIPFACCMF_N.OPT_19,
                    :MWIPFACCMF_N.OPT_20,
                    :MWIPFACCMF_N.TBL_1,
                    :MWIPFACCMF_N.TBL_2,
                    :MWIPFACCMF_N.TBL_3,
                    :MWIPFACCMF_N.TBL_4,
                    :MWIPFACCMF_N.TBL_5,
                    :MWIPFACCMF_N.TBL_6,
                    :MWIPFACCMF_N.TBL_7,
                    :MWIPFACCMF_N.TBL_8,
                    :MWIPFACCMF_N.TBL_9,
                    :MWIPFACCMF_N.TBL_10,
                    :MWIPFACCMF_N.TBL_11,
                    :MWIPFACCMF_N.TBL_12,
                    :MWIPFACCMF_N.TBL_13,
                    :MWIPFACCMF_N.TBL_14,
                    :MWIPFACCMF_N.TBL_15,
                    :MWIPFACCMF_N.TBL_16,
                    :MWIPFACCMF_N.TBL_17,
                    :MWIPFACCMF_N.TBL_18,
                    :MWIPFACCMF_N.TBL_19,
                    :MWIPFACCMF_N.TBL_20,
                    :MWIPFACCMF_N.CREATE_USER_ID,
                    :MWIPFACCMF_N.CREATE_TIME,
                    :MWIPFACCMF_N.UPDATE_USER_ID,
                    :MWIPFACCMF_N.UPDATE_TIME
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 88;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPFACCMF (FACTORY,ITEM_NAME,PRT_1,PRT_2,PRT_3,PRT_4,PRT\
_5,PRT_6,PRT_7,PRT_8,PRT_9,PRT_10,PRT_11,PRT_12,PRT_13,PRT_14,PRT_15,PRT_16,\
PRT_17,PRT_18,PRT_19,PRT_20,FMT_1,FMT_2,FMT_3,FMT_4,FMT_5,FMT_6,FMT_7,FMT_8,\
FMT_9,FMT_10,FMT_11,FMT_12,FMT_13,FMT_14,FMT_15,FMT_16,FMT_17,FMT_18,FMT_19,\
FMT_20,OPT_1,OPT_2,OPT_3,OPT_4,OPT_5,OPT_6,OPT_7,OPT_8,OPT_9,OPT_10,OPT_11,O\
PT_12,OPT_13,OPT_14,OPT_15,OPT_16,OPT_17,OPT_18,OPT_19,OPT_20,TBL_1,TBL_2,TB\
L_3,TBL_4,TBL_5,TBL_6,TBL_7,TBL_8,TBL_9,TBL_10,TBL_11,TBL_12,TBL_13,TBL_14,T\
BL_15,TBL_16,TBL_17,TBL_18,TBL_19,TBL_20,CREATE_USER_ID,CREATE_TIME,UPDATE_U\
SER_ID,UPDATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b1\
1,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26\
,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,\
:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:\
b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b\
72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,");
    sqlstm.stmt = ":b81,:b82,:b83,:b84,:b85)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )789;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_1);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_2);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_3);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_4);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_5);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_6);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_7);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_8);
    sqlstm.sqhstl[9] = (unsigned int  )21;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_9);
    sqlstm.sqhstl[10] = (unsigned int  )21;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_10);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_11);
    sqlstm.sqhstl[12] = (unsigned int  )21;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_12);
    sqlstm.sqhstl[13] = (unsigned int  )21;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_13);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_14);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_15);
    sqlstm.sqhstl[16] = (unsigned int  )21;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_16);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_17);
    sqlstm.sqhstl[18] = (unsigned int  )21;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_18);
    sqlstm.sqhstl[19] = (unsigned int  )21;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.PRT_19);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.PRT_20);
    sqlstm.sqhstl[21] = (unsigned int  )21;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_1);
    sqlstm.sqhstl[22] = (unsigned int  )2;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_2);
    sqlstm.sqhstl[23] = (unsigned int  )2;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_3);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_4);
    sqlstm.sqhstl[25] = (unsigned int  )2;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_5);
    sqlstm.sqhstl[26] = (unsigned int  )2;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_6);
    sqlstm.sqhstl[27] = (unsigned int  )2;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_7);
    sqlstm.sqhstl[28] = (unsigned int  )2;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_8);
    sqlstm.sqhstl[29] = (unsigned int  )2;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_9);
    sqlstm.sqhstl[30] = (unsigned int  )2;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_10);
    sqlstm.sqhstl[31] = (unsigned int  )2;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_11);
    sqlstm.sqhstl[32] = (unsigned int  )2;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_12);
    sqlstm.sqhstl[33] = (unsigned int  )2;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_13);
    sqlstm.sqhstl[34] = (unsigned int  )2;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_14);
    sqlstm.sqhstl[35] = (unsigned int  )2;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_15);
    sqlstm.sqhstl[36] = (unsigned int  )2;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_16);
    sqlstm.sqhstl[37] = (unsigned int  )2;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_17);
    sqlstm.sqhstl[38] = (unsigned int  )2;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_18);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.FMT_19);
    sqlstm.sqhstl[40] = (unsigned int  )2;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.FMT_20);
    sqlstm.sqhstl[41] = (unsigned int  )2;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_1);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_2);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_3);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_4);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_5);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_6);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_7);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_8);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_9);
    sqlstm.sqhstl[50] = (unsigned int  )2;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_10);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_11);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_12);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_13);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_14);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_15);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_16);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_17);
    sqlstm.sqhstl[58] = (unsigned int  )2;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_18);
    sqlstm.sqhstl[59] = (unsigned int  )2;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.OPT_19);
    sqlstm.sqhstl[60] = (unsigned int  )2;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.OPT_20);
    sqlstm.sqhstl[61] = (unsigned int  )2;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_1);
    sqlstm.sqhstl[62] = (unsigned int  )21;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_2);
    sqlstm.sqhstl[63] = (unsigned int  )21;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_3);
    sqlstm.sqhstl[64] = (unsigned int  )21;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_4);
    sqlstm.sqhstl[65] = (unsigned int  )21;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_5);
    sqlstm.sqhstl[66] = (unsigned int  )21;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_6);
    sqlstm.sqhstl[67] = (unsigned int  )21;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_7);
    sqlstm.sqhstl[68] = (unsigned int  )21;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_8);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_9);
    sqlstm.sqhstl[70] = (unsigned int  )21;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_10);
    sqlstm.sqhstl[71] = (unsigned int  )21;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_11);
    sqlstm.sqhstl[72] = (unsigned int  )21;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_12);
    sqlstm.sqhstl[73] = (unsigned int  )21;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_13);
    sqlstm.sqhstl[74] = (unsigned int  )21;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_14);
    sqlstm.sqhstl[75] = (unsigned int  )21;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_15);
    sqlstm.sqhstl[76] = (unsigned int  )21;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_16);
    sqlstm.sqhstl[77] = (unsigned int  )21;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_17);
    sqlstm.sqhstl[78] = (unsigned int  )21;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_18);
    sqlstm.sqhstl[79] = (unsigned int  )21;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.TBL_19);
    sqlstm.sqhstl[80] = (unsigned int  )21;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.TBL_20);
    sqlstm.sqhstl[81] = (unsigned int  )21;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.CREATE_USER_ID);
    sqlstm.sqhstl[82] = (unsigned int  )21;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.CREATE_TIME);
    sqlstm.sqhstl[83] = (unsigned int  )15;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[84] = (unsigned int  )21;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
    sqlstm.sqhstl[85] = (unsigned int  )15;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mwipfaccmf", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipfaccmf(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPFACCMF SET
                    PRT_1 = :MWIPFACCMF_N.PRT_1,
                    PRT_2 = :MWIPFACCMF_N.PRT_2,
                    PRT_3 = :MWIPFACCMF_N.PRT_3,
                    PRT_4 = :MWIPFACCMF_N.PRT_4,
                    PRT_5 = :MWIPFACCMF_N.PRT_5,
                    PRT_6 = :MWIPFACCMF_N.PRT_6,
                    PRT_7 = :MWIPFACCMF_N.PRT_7,
                    PRT_8 = :MWIPFACCMF_N.PRT_8,
                    PRT_9 = :MWIPFACCMF_N.PRT_9,
                    PRT_10 = :MWIPFACCMF_N.PRT_10,
                    PRT_11 = :MWIPFACCMF_N.PRT_11,
                    PRT_12 = :MWIPFACCMF_N.PRT_12,
                    PRT_13 = :MWIPFACCMF_N.PRT_13,
                    PRT_14 = :MWIPFACCMF_N.PRT_14,
                    PRT_15 = :MWIPFACCMF_N.PRT_15,
                    PRT_16 = :MWIPFACCMF_N.PRT_16,
                    PRT_17 = :MWIPFACCMF_N.PRT_17,
                    PRT_18 = :MWIPFACCMF_N.PRT_18,
                    PRT_19 = :MWIPFACCMF_N.PRT_19,
                    PRT_20 = :MWIPFACCMF_N.PRT_20,
                    FMT_1 = :MWIPFACCMF_N.FMT_1,
                    FMT_2 = :MWIPFACCMF_N.FMT_2,
                    FMT_3 = :MWIPFACCMF_N.FMT_3,
                    FMT_4 = :MWIPFACCMF_N.FMT_4,
                    FMT_5 = :MWIPFACCMF_N.FMT_5,
                    FMT_6 = :MWIPFACCMF_N.FMT_6,
                    FMT_7 = :MWIPFACCMF_N.FMT_7,
                    FMT_8 = :MWIPFACCMF_N.FMT_8,
                    FMT_9 = :MWIPFACCMF_N.FMT_9,
                    FMT_10 = :MWIPFACCMF_N.FMT_10,
                    FMT_11 = :MWIPFACCMF_N.FMT_11,
                    FMT_12 = :MWIPFACCMF_N.FMT_12,
                    FMT_13 = :MWIPFACCMF_N.FMT_13,
                    FMT_14 = :MWIPFACCMF_N.FMT_14,
                    FMT_15 = :MWIPFACCMF_N.FMT_15,
                    FMT_16 = :MWIPFACCMF_N.FMT_16,
                    FMT_17 = :MWIPFACCMF_N.FMT_17,
                    FMT_18 = :MWIPFACCMF_N.FMT_18,
                    FMT_19 = :MWIPFACCMF_N.FMT_19,
                    FMT_20 = :MWIPFACCMF_N.FMT_20,
                    OPT_1 = :MWIPFACCMF_N.OPT_1,
                    OPT_2 = :MWIPFACCMF_N.OPT_2,
                    OPT_3 = :MWIPFACCMF_N.OPT_3,
                    OPT_4 = :MWIPFACCMF_N.OPT_4,
                    OPT_5 = :MWIPFACCMF_N.OPT_5,
                    OPT_6 = :MWIPFACCMF_N.OPT_6,
                    OPT_7 = :MWIPFACCMF_N.OPT_7,
                    OPT_8 = :MWIPFACCMF_N.OPT_8,
                    OPT_9 = :MWIPFACCMF_N.OPT_9,
                    OPT_10 = :MWIPFACCMF_N.OPT_10,
                    OPT_11 = :MWIPFACCMF_N.OPT_11,
                    OPT_12 = :MWIPFACCMF_N.OPT_12,
                    OPT_13 = :MWIPFACCMF_N.OPT_13,
                    OPT_14 = :MWIPFACCMF_N.OPT_14,
                    OPT_15 = :MWIPFACCMF_N.OPT_15,
                    OPT_16 = :MWIPFACCMF_N.OPT_16,
                    OPT_17 = :MWIPFACCMF_N.OPT_17,
                    OPT_18 = :MWIPFACCMF_N.OPT_18,
                    OPT_19 = :MWIPFACCMF_N.OPT_19,
                    OPT_20 = :MWIPFACCMF_N.OPT_20,
                    TBL_1 = :MWIPFACCMF_N.TBL_1,
                    TBL_2 = :MWIPFACCMF_N.TBL_2,
                    TBL_3 = :MWIPFACCMF_N.TBL_3,
                    TBL_4 = :MWIPFACCMF_N.TBL_4,
                    TBL_5 = :MWIPFACCMF_N.TBL_5,
                    TBL_6 = :MWIPFACCMF_N.TBL_6,
                    TBL_7 = :MWIPFACCMF_N.TBL_7,
                    TBL_8 = :MWIPFACCMF_N.TBL_8,
                    TBL_9 = :MWIPFACCMF_N.TBL_9,
                    TBL_10 = :MWIPFACCMF_N.TBL_10,
                    TBL_11 = :MWIPFACCMF_N.TBL_11,
                    TBL_12 = :MWIPFACCMF_N.TBL_12,
                    TBL_13 = :MWIPFACCMF_N.TBL_13,
                    TBL_14 = :MWIPFACCMF_N.TBL_14,
                    TBL_15 = :MWIPFACCMF_N.TBL_15,
                    TBL_16 = :MWIPFACCMF_N.TBL_16,
                    TBL_17 = :MWIPFACCMF_N.TBL_17,
                    TBL_18 = :MWIPFACCMF_N.TBL_18,
                    TBL_19 = :MWIPFACCMF_N.TBL_19,
                    TBL_20 = :MWIPFACCMF_N.TBL_20,
                    CREATE_USER_ID = :MWIPFACCMF_N.CREATE_USER_ID,
                    CREATE_TIME = :MWIPFACCMF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MWIPFACCMF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPFACCMF_N.UPDATE_TIME
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPFACCMF  set PRT_1=:b0,PRT_2=:b1,PRT_3=:b2,PRT_4=:b\
3,PRT_5=:b4,PRT_6=:b5,PRT_7=:b6,PRT_8=:b7,PRT_9=:b8,PRT_10=:b9,PRT_11=:b10,P\
RT_12=:b11,PRT_13=:b12,PRT_14=:b13,PRT_15=:b14,PRT_16=:b15,PRT_17=:b16,PRT_1\
8=:b17,PRT_19=:b18,PRT_20=:b19,FMT_1=:b20,FMT_2=:b21,FMT_3=:b22,FMT_4=:b23,F\
MT_5=:b24,FMT_6=:b25,FMT_7=:b26,FMT_8=:b27,FMT_9=:b28,FMT_10=:b29,FMT_11=:b3\
0,FMT_12=:b31,FMT_13=:b32,FMT_14=:b33,FMT_15=:b34,FMT_16=:b35,FMT_17=:b36,FM\
T_18=:b37,FMT_19=:b38,FMT_20=:b39,OPT_1=:b40,OPT_2=:b41,OPT_3=:b42,OPT_4=:b4\
3,OPT_5=:b44,OPT_6=:b45,OPT_7=:b46,OPT_8=:b47,OPT_9=:b48,OPT_10=:b49,OPT_11=\
:b50,OPT_12=:b51,OPT_13=:b52,OPT_14=:b53,OPT_15=:b54,OPT_16=:b55,OPT_17=:b56\
,OPT_18=:b57,OPT_19=:b58,OPT_20=:b59,TBL_1=:b60,TBL_2=:b61,TBL_3=:b62,TBL_4=\
:b63,TBL_5=:b64,TBL_6=:b65,TBL_7=:b66,TBL_8=:b67,TBL_9=:b68,TBL_10=:b69,TBL_\
11=:b70,TBL_12=:b71,TBL_13=:b72,TBL_14=:b73,TBL_15=:b74,TBL_16=:b75,TBL_17=:\
b76,TBL_18=:b77,TBL_19=:b78,TBL_20=:b79,CREATE_USER_ID=:b80,CREATE_TIME=:b81\
,UPDATE_USER_ID=:b82,UPDATE_TIME=:b83 where (FACTOR");
            sqlstm.stmt = "Y=:b84 and ITEM_NAME=:b85)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1148;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.PRT_1);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.PRT_2);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_3);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_4);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_5);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_6);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_7);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_8);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_9);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_10);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_11);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_12);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_13);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_14);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_15);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_16);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_17);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_18);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_19);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_20);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.FMT_1);
            sqlstm.sqhstl[20] = (unsigned int  )2;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.FMT_2);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_3);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_4);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_5);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_6);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_7);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_8);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_9);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_10);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_11);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_12);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_13);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_14);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_15);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_16);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_17);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_18);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_19);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_20);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.OPT_1);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.OPT_2);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_3);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_4);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_5);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_6);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_7);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_8);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_9);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_10);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_11);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_12);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_13);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_14);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_15);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_16);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_17);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_18);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_19);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_20);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.TBL_1);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.TBL_2);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_3);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_4);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_5);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_6);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_7);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_8);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_9);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_10);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_11);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_12);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_13);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_14);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_15);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_16);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_17);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_18);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_19);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_20);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.CREATE_USER_ID);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.CREATE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[84] = (unsigned int  )11;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
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
            /* EXEC SQL UPDATE MWIPFACCMF SET
                    PRT_1 = :MWIPFACCMF_N.PRT_1,
                    PRT_2 = :MWIPFACCMF_N.PRT_2,
                    PRT_3 = :MWIPFACCMF_N.PRT_3,
                    PRT_4 = :MWIPFACCMF_N.PRT_4,
                    PRT_5 = :MWIPFACCMF_N.PRT_5,
                    PRT_6 = :MWIPFACCMF_N.PRT_6,
                    PRT_7 = :MWIPFACCMF_N.PRT_7,
                    PRT_8 = :MWIPFACCMF_N.PRT_8,
                    PRT_9 = :MWIPFACCMF_N.PRT_9,
                    PRT_10 = :MWIPFACCMF_N.PRT_10,
                    PRT_11 = :MWIPFACCMF_N.PRT_11,
                    PRT_12 = :MWIPFACCMF_N.PRT_12,
                    PRT_13 = :MWIPFACCMF_N.PRT_13,
                    PRT_14 = :MWIPFACCMF_N.PRT_14,
                    PRT_15 = :MWIPFACCMF_N.PRT_15,
                    PRT_16 = :MWIPFACCMF_N.PRT_16,
                    PRT_17 = :MWIPFACCMF_N.PRT_17,
                    PRT_18 = :MWIPFACCMF_N.PRT_18,
                    PRT_19 = :MWIPFACCMF_N.PRT_19,
                    PRT_20 = :MWIPFACCMF_N.PRT_20,
                    FMT_1 = :MWIPFACCMF_N.FMT_1,
                    FMT_2 = :MWIPFACCMF_N.FMT_2,
                    FMT_3 = :MWIPFACCMF_N.FMT_3,
                    FMT_4 = :MWIPFACCMF_N.FMT_4,
                    FMT_5 = :MWIPFACCMF_N.FMT_5,
                    FMT_6 = :MWIPFACCMF_N.FMT_6,
                    FMT_7 = :MWIPFACCMF_N.FMT_7,
                    FMT_8 = :MWIPFACCMF_N.FMT_8,
                    FMT_9 = :MWIPFACCMF_N.FMT_9,
                    FMT_10 = :MWIPFACCMF_N.FMT_10,
                    FMT_11 = :MWIPFACCMF_N.FMT_11,
                    FMT_12 = :MWIPFACCMF_N.FMT_12,
                    FMT_13 = :MWIPFACCMF_N.FMT_13,
                    FMT_14 = :MWIPFACCMF_N.FMT_14,
                    FMT_15 = :MWIPFACCMF_N.FMT_15,
                    FMT_16 = :MWIPFACCMF_N.FMT_16,
                    FMT_17 = :MWIPFACCMF_N.FMT_17,
                    FMT_18 = :MWIPFACCMF_N.FMT_18,
                    FMT_19 = :MWIPFACCMF_N.FMT_19,
                    FMT_20 = :MWIPFACCMF_N.FMT_20,
                    OPT_1 = :MWIPFACCMF_N.OPT_1,
                    OPT_2 = :MWIPFACCMF_N.OPT_2,
                    OPT_3 = :MWIPFACCMF_N.OPT_3,
                    OPT_4 = :MWIPFACCMF_N.OPT_4,
                    OPT_5 = :MWIPFACCMF_N.OPT_5,
                    OPT_6 = :MWIPFACCMF_N.OPT_6,
                    OPT_7 = :MWIPFACCMF_N.OPT_7,
                    OPT_8 = :MWIPFACCMF_N.OPT_8,
                    OPT_9 = :MWIPFACCMF_N.OPT_9,
                    OPT_10 = :MWIPFACCMF_N.OPT_10,
                    OPT_11 = :MWIPFACCMF_N.OPT_11,
                    OPT_12 = :MWIPFACCMF_N.OPT_12,
                    OPT_13 = :MWIPFACCMF_N.OPT_13,
                    OPT_14 = :MWIPFACCMF_N.OPT_14,
                    OPT_15 = :MWIPFACCMF_N.OPT_15,
                    OPT_16 = :MWIPFACCMF_N.OPT_16,
                    OPT_17 = :MWIPFACCMF_N.OPT_17,
                    OPT_18 = :MWIPFACCMF_N.OPT_18,
                    OPT_19 = :MWIPFACCMF_N.OPT_19,
                    OPT_20 = :MWIPFACCMF_N.OPT_20,
                    TBL_1 = :MWIPFACCMF_N.TBL_1,
                    TBL_2 = :MWIPFACCMF_N.TBL_2,
                    TBL_3 = :MWIPFACCMF_N.TBL_3,
                    TBL_4 = :MWIPFACCMF_N.TBL_4,
                    TBL_5 = :MWIPFACCMF_N.TBL_5,
                    TBL_6 = :MWIPFACCMF_N.TBL_6,
                    TBL_7 = :MWIPFACCMF_N.TBL_7,
                    TBL_8 = :MWIPFACCMF_N.TBL_8,
                    TBL_9 = :MWIPFACCMF_N.TBL_9,
                    TBL_10 = :MWIPFACCMF_N.TBL_10,
                    TBL_11 = :MWIPFACCMF_N.TBL_11,
                    TBL_12 = :MWIPFACCMF_N.TBL_12,
                    TBL_13 = :MWIPFACCMF_N.TBL_13,
                    TBL_14 = :MWIPFACCMF_N.TBL_14,
                    TBL_15 = :MWIPFACCMF_N.TBL_15,
                    TBL_16 = :MWIPFACCMF_N.TBL_16,
                    TBL_17 = :MWIPFACCMF_N.TBL_17,
                    TBL_18 = :MWIPFACCMF_N.TBL_18,
                    TBL_19 = :MWIPFACCMF_N.TBL_19,
                    TBL_20 = :MWIPFACCMF_N.TBL_20,
                    UPDATE_USER_ID = :MWIPFACCMF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPFACCMF_N.UPDATE_TIME
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                    AND ITEM_NAME = :MWIPFACCMF_N.ITEM_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPFACCMF  set PRT_1=:b0,PRT_2=:b1,PRT_3\
=:b2,PRT_4=:b3,PRT_5=:b4,PRT_6=:b5,PRT_7=:b6,PRT_8=:b7,PRT_9=:b8,PRT_10=:b9,P\
RT_11=:b10,PRT_12=:b11,PRT_13=:b12,PRT_14=:b13,PRT_15=:b14,PRT_16=:b15,PRT_17\
=:b16,PRT_18=:b17,PRT_19=:b18,PRT_20=:b19,FMT_1=:b20,FMT_2=:b21,FMT_3=:b22,FM\
T_4=:b23,FMT_5=:b24,FMT_6=:b25,FMT_7=:b26,FMT_8=:b27,FMT_9=:b28,FMT_10=:b29,F\
MT_11=:b30,FMT_12=:b31,FMT_13=:b32,FMT_14=:b33,FMT_15=:b34,FMT_16=:b35,FMT_17\
=:b36,FMT_18=:b37,FMT_19=:b38,FMT_20=:b39,OPT_1=:b40,OPT_2=:b41,OPT_3=:b42,OP\
T_4=:b43,OPT_5=:b44,OPT_6=:b45,OPT_7=:b46,OPT_8=:b47,OPT_9=:b48,OPT_10=:b49,O\
PT_11=:b50,OPT_12=:b51,OPT_13=:b52,OPT_14=:b53,OPT_15=:b54,OPT_16=:b55,OPT_17\
=:b56,OPT_18=:b57,OPT_19=:b58,OPT_20=:b59,TBL_1=:b60,TBL_2=:b61,TBL_3=:b62,TB\
L_4=:b63,TBL_5=:b64,TBL_6=:b65,TBL_7=:b66,TBL_8=:b67,TBL_9=:b68,TBL_10=:b69,T\
BL_11=:b70,TBL_12=:b71,TBL_13=:b72,TBL_14=:b73,TBL_15=:b74,TBL_16=:b75,TBL_17\
=:b76,TBL_18=:b77,TBL_19=:b78,TBL_20=:b79,UPDATE_USER_ID=:b80,UPDATE_TIME=:b8\
1 where (FACTORY=:b82 and ITEM_NAME=:b83)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1507;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.PRT_1);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.PRT_2);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_3);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_4);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_5);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_6);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_7);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_8);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_9);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_10);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_11);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_12);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_13);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_14);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_15);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_16);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_17);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_18);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_19);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_20);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.FMT_1);
            sqlstm.sqhstl[20] = (unsigned int  )2;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.FMT_2);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_3);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_4);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_5);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_6);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_7);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_8);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_9);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_10);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_11);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_12);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_13);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_14);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_15);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_16);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_17);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_18);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_19);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_20);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.OPT_1);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.OPT_2);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_3);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_4);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_5);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_6);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_7);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_8);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_9);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_10);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_11);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_12);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_13);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_14);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_15);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_16);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_17);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_18);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_19);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_20);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.TBL_1);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.TBL_2);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_3);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_4);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_5);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_6);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_7);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_8);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_9);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_10);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_11);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_12);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_13);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_14);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_15);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_16);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_17);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_18);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_19);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_20);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[82] = (unsigned int  )11;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mwipfaccmf", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipfaccmf(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPFACCMF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    ITEM_NAME,
                    PRT_1,
                    PRT_2,
                    PRT_3,
                    PRT_4,
                    PRT_5,
                    PRT_6,
                    PRT_7,
                    PRT_8,
                    PRT_9,
                    PRT_10,
                    PRT_11,
                    PRT_12,
                    PRT_13,
                    PRT_14,
                    PRT_15,
                    PRT_16,
                    PRT_17,
                    PRT_18,
                    PRT_19,
                    PRT_20,
                    FMT_1,
                    FMT_2,
                    FMT_3,
                    FMT_4,
                    FMT_5,
                    FMT_6,
                    FMT_7,
                    FMT_8,
                    FMT_9,
                    FMT_10,
                    FMT_11,
                    FMT_12,
                    FMT_13,
                    FMT_14,
                    FMT_15,
                    FMT_16,
                    FMT_17,
                    FMT_18,
                    FMT_19,
                    FMT_20,
                    OPT_1,
                    OPT_2,
                    OPT_3,
                    OPT_4,
                    OPT_5,
                    OPT_6,
                    OPT_7,
                    OPT_8,
                    OPT_9,
                    OPT_10,
                    OPT_11,
                    OPT_12,
                    OPT_13,
                    OPT_14,
                    OPT_15,
                    OPT_16,
                    OPT_17,
                    OPT_18,
                    OPT_19,
                    OPT_20,
                    TBL_1,
                    TBL_2,
                    TBL_3,
                    TBL_4,
                    TBL_5,
                    TBL_6,
                    TBL_7,
                    TBL_8,
                    TBL_9,
                    TBL_10,
                    TBL_11,
                    TBL_12,
                    TBL_13,
                    TBL_14,
                    TBL_15,
                    TBL_16,
                    TBL_17,
                    TBL_18,
                    TBL_19,
                    TBL_20,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM MWIPFACCMF
                WHERE FACTORY = :MWIPFACCMF_N.FACTORY
                ORDER BY ITEM_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPFACCMF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1858;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_mwipfaccmf", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipfaccmf(int sel_type, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPFACCMF_N_TAG MWIPFACCMF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPFACCMF_CUR_1 INTO 
                                                    :MWIPFACCMF_N.FACTORY,
                                                    :MWIPFACCMF_N.ITEM_NAME,
                                                    :MWIPFACCMF_N.PRT_1,
                                                    :MWIPFACCMF_N.PRT_2,
                                                    :MWIPFACCMF_N.PRT_3,
                                                    :MWIPFACCMF_N.PRT_4,
                                                    :MWIPFACCMF_N.PRT_5,
                                                    :MWIPFACCMF_N.PRT_6,
                                                    :MWIPFACCMF_N.PRT_7,
                                                    :MWIPFACCMF_N.PRT_8,
                                                    :MWIPFACCMF_N.PRT_9,
                                                    :MWIPFACCMF_N.PRT_10,
                                                    :MWIPFACCMF_N.PRT_11,
                                                    :MWIPFACCMF_N.PRT_12,
                                                    :MWIPFACCMF_N.PRT_13,
                                                    :MWIPFACCMF_N.PRT_14,
                                                    :MWIPFACCMF_N.PRT_15,
                                                    :MWIPFACCMF_N.PRT_16,
                                                    :MWIPFACCMF_N.PRT_17,
                                                    :MWIPFACCMF_N.PRT_18,
                                                    :MWIPFACCMF_N.PRT_19,
                                                    :MWIPFACCMF_N.PRT_20,
                                                    :MWIPFACCMF_N.FMT_1,
                                                    :MWIPFACCMF_N.FMT_2,
                                                    :MWIPFACCMF_N.FMT_3,
                                                    :MWIPFACCMF_N.FMT_4,
                                                    :MWIPFACCMF_N.FMT_5,
                                                    :MWIPFACCMF_N.FMT_6,
                                                    :MWIPFACCMF_N.FMT_7,
                                                    :MWIPFACCMF_N.FMT_8,
                                                    :MWIPFACCMF_N.FMT_9,
                                                    :MWIPFACCMF_N.FMT_10,
                                                    :MWIPFACCMF_N.FMT_11,
                                                    :MWIPFACCMF_N.FMT_12,
                                                    :MWIPFACCMF_N.FMT_13,
                                                    :MWIPFACCMF_N.FMT_14,
                                                    :MWIPFACCMF_N.FMT_15,
                                                    :MWIPFACCMF_N.FMT_16,
                                                    :MWIPFACCMF_N.FMT_17,
                                                    :MWIPFACCMF_N.FMT_18,
                                                    :MWIPFACCMF_N.FMT_19,
                                                    :MWIPFACCMF_N.FMT_20,
                                                    :MWIPFACCMF_N.OPT_1,
                                                    :MWIPFACCMF_N.OPT_2,
                                                    :MWIPFACCMF_N.OPT_3,
                                                    :MWIPFACCMF_N.OPT_4,
                                                    :MWIPFACCMF_N.OPT_5,
                                                    :MWIPFACCMF_N.OPT_6,
                                                    :MWIPFACCMF_N.OPT_7,
                                                    :MWIPFACCMF_N.OPT_8,
                                                    :MWIPFACCMF_N.OPT_9,
                                                    :MWIPFACCMF_N.OPT_10,
                                                    :MWIPFACCMF_N.OPT_11,
                                                    :MWIPFACCMF_N.OPT_12,
                                                    :MWIPFACCMF_N.OPT_13,
                                                    :MWIPFACCMF_N.OPT_14,
                                                    :MWIPFACCMF_N.OPT_15,
                                                    :MWIPFACCMF_N.OPT_16,
                                                    :MWIPFACCMF_N.OPT_17,
                                                    :MWIPFACCMF_N.OPT_18,
                                                    :MWIPFACCMF_N.OPT_19,
                                                    :MWIPFACCMF_N.OPT_20,
                                                    :MWIPFACCMF_N.TBL_1,
                                                    :MWIPFACCMF_N.TBL_2,
                                                    :MWIPFACCMF_N.TBL_3,
                                                    :MWIPFACCMF_N.TBL_4,
                                                    :MWIPFACCMF_N.TBL_5,
                                                    :MWIPFACCMF_N.TBL_6,
                                                    :MWIPFACCMF_N.TBL_7,
                                                    :MWIPFACCMF_N.TBL_8,
                                                    :MWIPFACCMF_N.TBL_9,
                                                    :MWIPFACCMF_N.TBL_10,
                                                    :MWIPFACCMF_N.TBL_11,
                                                    :MWIPFACCMF_N.TBL_12,
                                                    :MWIPFACCMF_N.TBL_13,
                                                    :MWIPFACCMF_N.TBL_14,
                                                    :MWIPFACCMF_N.TBL_15,
                                                    :MWIPFACCMF_N.TBL_16,
                                                    :MWIPFACCMF_N.TBL_17,
                                                    :MWIPFACCMF_N.TBL_18,
                                                    :MWIPFACCMF_N.TBL_19,
                                                    :MWIPFACCMF_N.TBL_20,
                                                    :MWIPFACCMF_N.CREATE_USER_ID,
                                                    :MWIPFACCMF_N.CREATE_TIME,
                                                    :MWIPFACCMF_N.UPDATE_USER_ID,
                                                    :MWIPFACCMF_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1877;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPFACCMF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPFACCMF_N.ITEM_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPFACCMF_N.PRT_1);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPFACCMF_N.PRT_2);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPFACCMF_N.PRT_3);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPFACCMF_N.PRT_4);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPFACCMF_N.PRT_5);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPFACCMF_N.PRT_6);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPFACCMF_N.PRT_7);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPFACCMF_N.PRT_8);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPFACCMF_N.PRT_9);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPFACCMF_N.PRT_10);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPFACCMF_N.PRT_11);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPFACCMF_N.PRT_12);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPFACCMF_N.PRT_13);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPFACCMF_N.PRT_14);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPFACCMF_N.PRT_15);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPFACCMF_N.PRT_16);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPFACCMF_N.PRT_17);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPFACCMF_N.PRT_18);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPFACCMF_N.PRT_19);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPFACCMF_N.PRT_20);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPFACCMF_N.FMT_1);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPFACCMF_N.FMT_2);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPFACCMF_N.FMT_3);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPFACCMF_N.FMT_4);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPFACCMF_N.FMT_5);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPFACCMF_N.FMT_6);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPFACCMF_N.FMT_7);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPFACCMF_N.FMT_8);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPFACCMF_N.FMT_9);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPFACCMF_N.FMT_10);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPFACCMF_N.FMT_11);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPFACCMF_N.FMT_12);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPFACCMF_N.FMT_13);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPFACCMF_N.FMT_14);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPFACCMF_N.FMT_15);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPFACCMF_N.FMT_16);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPFACCMF_N.FMT_17);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPFACCMF_N.FMT_18);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPFACCMF_N.FMT_19);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPFACCMF_N.FMT_20);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPFACCMF_N.OPT_1);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPFACCMF_N.OPT_2);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPFACCMF_N.OPT_3);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPFACCMF_N.OPT_4);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPFACCMF_N.OPT_5);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPFACCMF_N.OPT_6);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPFACCMF_N.OPT_7);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPFACCMF_N.OPT_8);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPFACCMF_N.OPT_9);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPFACCMF_N.OPT_10);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPFACCMF_N.OPT_11);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPFACCMF_N.OPT_12);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPFACCMF_N.OPT_13);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPFACCMF_N.OPT_14);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPFACCMF_N.OPT_15);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPFACCMF_N.OPT_16);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPFACCMF_N.OPT_17);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPFACCMF_N.OPT_18);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPFACCMF_N.OPT_19);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPFACCMF_N.OPT_20);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPFACCMF_N.TBL_1);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPFACCMF_N.TBL_2);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPFACCMF_N.TBL_3);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPFACCMF_N.TBL_4);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPFACCMF_N.TBL_5);
            sqlstm.sqhstl[66] = (unsigned int  )21;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPFACCMF_N.TBL_6);
            sqlstm.sqhstl[67] = (unsigned int  )21;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPFACCMF_N.TBL_7);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPFACCMF_N.TBL_8);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPFACCMF_N.TBL_9);
            sqlstm.sqhstl[70] = (unsigned int  )21;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPFACCMF_N.TBL_10);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPFACCMF_N.TBL_11);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPFACCMF_N.TBL_12);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPFACCMF_N.TBL_13);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPFACCMF_N.TBL_14);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPFACCMF_N.TBL_15);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPFACCMF_N.TBL_16);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPFACCMF_N.TBL_17);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPFACCMF_N.TBL_18);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPFACCMF_N.TBL_19);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPFACCMF_N.TBL_20);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPFACCMF_N.CREATE_USER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPFACCMF_N.CREATE_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPFACCMF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPFACCMF_N.UPDATE_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
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
        DBC_del_null_mwipfaccmf(&MWIPFACCMF_N, MWIPFACCMF);
    }
    DB_stop_query_timer("DBC_fetch_mwipfaccmf", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipfaccmf(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPFACCMF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 88;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2236;
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
    DB_stop_query_timer("DBC_close_mwipfaccmf", sel_type);
}


/* Initialize Function */
void DBC_init_mwipfaccmf(struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* memset by Space */
    memset(MWIPFACCMF, ' ', sizeof(struct MWIPFACCMF_TAG));
    
}


/* Add Null Function */
void DBC_add_null_mwipfaccmf(struct MWIPFACCMF_N_TAG *MWIPFACCMF_N, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    /* memset by NULL */
    memset(MWIPFACCMF_N, '\0', sizeof(struct MWIPFACCMF_N_TAG));
    
    MEMCPY_AN(MWIPFACCMF_N->FACTORY, MWIPFACCMF->FACTORY, sizeof(MWIPFACCMF->FACTORY));
    MEMCPY_AN(MWIPFACCMF_N->ITEM_NAME, MWIPFACCMF->ITEM_NAME, sizeof(MWIPFACCMF->ITEM_NAME));
    MEMCPY_AN(MWIPFACCMF_N->PRT_1, MWIPFACCMF->PRT_1, sizeof(MWIPFACCMF->PRT_1));
    MEMCPY_AN(MWIPFACCMF_N->PRT_2, MWIPFACCMF->PRT_2, sizeof(MWIPFACCMF->PRT_2));
    MEMCPY_AN(MWIPFACCMF_N->PRT_3, MWIPFACCMF->PRT_3, sizeof(MWIPFACCMF->PRT_3));
    MEMCPY_AN(MWIPFACCMF_N->PRT_4, MWIPFACCMF->PRT_4, sizeof(MWIPFACCMF->PRT_4));
    MEMCPY_AN(MWIPFACCMF_N->PRT_5, MWIPFACCMF->PRT_5, sizeof(MWIPFACCMF->PRT_5));
    MEMCPY_AN(MWIPFACCMF_N->PRT_6, MWIPFACCMF->PRT_6, sizeof(MWIPFACCMF->PRT_6));
    MEMCPY_AN(MWIPFACCMF_N->PRT_7, MWIPFACCMF->PRT_7, sizeof(MWIPFACCMF->PRT_7));
    MEMCPY_AN(MWIPFACCMF_N->PRT_8, MWIPFACCMF->PRT_8, sizeof(MWIPFACCMF->PRT_8));
    MEMCPY_AN(MWIPFACCMF_N->PRT_9, MWIPFACCMF->PRT_9, sizeof(MWIPFACCMF->PRT_9));
    MEMCPY_AN(MWIPFACCMF_N->PRT_10, MWIPFACCMF->PRT_10, sizeof(MWIPFACCMF->PRT_10));
    MEMCPY_AN(MWIPFACCMF_N->PRT_11, MWIPFACCMF->PRT_11, sizeof(MWIPFACCMF->PRT_11));
    MEMCPY_AN(MWIPFACCMF_N->PRT_12, MWIPFACCMF->PRT_12, sizeof(MWIPFACCMF->PRT_12));
    MEMCPY_AN(MWIPFACCMF_N->PRT_13, MWIPFACCMF->PRT_13, sizeof(MWIPFACCMF->PRT_13));
    MEMCPY_AN(MWIPFACCMF_N->PRT_14, MWIPFACCMF->PRT_14, sizeof(MWIPFACCMF->PRT_14));
    MEMCPY_AN(MWIPFACCMF_N->PRT_15, MWIPFACCMF->PRT_15, sizeof(MWIPFACCMF->PRT_15));
    MEMCPY_AN(MWIPFACCMF_N->PRT_16, MWIPFACCMF->PRT_16, sizeof(MWIPFACCMF->PRT_16));
    MEMCPY_AN(MWIPFACCMF_N->PRT_17, MWIPFACCMF->PRT_17, sizeof(MWIPFACCMF->PRT_17));
    MEMCPY_AN(MWIPFACCMF_N->PRT_18, MWIPFACCMF->PRT_18, sizeof(MWIPFACCMF->PRT_18));
    MEMCPY_AN(MWIPFACCMF_N->PRT_19, MWIPFACCMF->PRT_19, sizeof(MWIPFACCMF->PRT_19));
    MEMCPY_AN(MWIPFACCMF_N->PRT_20, MWIPFACCMF->PRT_20, sizeof(MWIPFACCMF->PRT_20));
    MWIPFACCMF_N->FMT_1[0] = MWIPFACCMF->FMT_1;
    MWIPFACCMF_N->FMT_2[0] = MWIPFACCMF->FMT_2;
    MWIPFACCMF_N->FMT_3[0] = MWIPFACCMF->FMT_3;
    MWIPFACCMF_N->FMT_4[0] = MWIPFACCMF->FMT_4;
    MWIPFACCMF_N->FMT_5[0] = MWIPFACCMF->FMT_5;
    MWIPFACCMF_N->FMT_6[0] = MWIPFACCMF->FMT_6;
    MWIPFACCMF_N->FMT_7[0] = MWIPFACCMF->FMT_7;
    MWIPFACCMF_N->FMT_8[0] = MWIPFACCMF->FMT_8;
    MWIPFACCMF_N->FMT_9[0] = MWIPFACCMF->FMT_9;
    MWIPFACCMF_N->FMT_10[0] = MWIPFACCMF->FMT_10;
    MWIPFACCMF_N->FMT_11[0] = MWIPFACCMF->FMT_11;
    MWIPFACCMF_N->FMT_12[0] = MWIPFACCMF->FMT_12;
    MWIPFACCMF_N->FMT_13[0] = MWIPFACCMF->FMT_13;
    MWIPFACCMF_N->FMT_14[0] = MWIPFACCMF->FMT_14;
    MWIPFACCMF_N->FMT_15[0] = MWIPFACCMF->FMT_15;
    MWIPFACCMF_N->FMT_16[0] = MWIPFACCMF->FMT_16;
    MWIPFACCMF_N->FMT_17[0] = MWIPFACCMF->FMT_17;
    MWIPFACCMF_N->FMT_18[0] = MWIPFACCMF->FMT_18;
    MWIPFACCMF_N->FMT_19[0] = MWIPFACCMF->FMT_19;
    MWIPFACCMF_N->FMT_20[0] = MWIPFACCMF->FMT_20;
    MWIPFACCMF_N->OPT_1[0] = MWIPFACCMF->OPT_1;
    MWIPFACCMF_N->OPT_2[0] = MWIPFACCMF->OPT_2;
    MWIPFACCMF_N->OPT_3[0] = MWIPFACCMF->OPT_3;
    MWIPFACCMF_N->OPT_4[0] = MWIPFACCMF->OPT_4;
    MWIPFACCMF_N->OPT_5[0] = MWIPFACCMF->OPT_5;
    MWIPFACCMF_N->OPT_6[0] = MWIPFACCMF->OPT_6;
    MWIPFACCMF_N->OPT_7[0] = MWIPFACCMF->OPT_7;
    MWIPFACCMF_N->OPT_8[0] = MWIPFACCMF->OPT_8;
    MWIPFACCMF_N->OPT_9[0] = MWIPFACCMF->OPT_9;
    MWIPFACCMF_N->OPT_10[0] = MWIPFACCMF->OPT_10;
    MWIPFACCMF_N->OPT_11[0] = MWIPFACCMF->OPT_11;
    MWIPFACCMF_N->OPT_12[0] = MWIPFACCMF->OPT_12;
    MWIPFACCMF_N->OPT_13[0] = MWIPFACCMF->OPT_13;
    MWIPFACCMF_N->OPT_14[0] = MWIPFACCMF->OPT_14;
    MWIPFACCMF_N->OPT_15[0] = MWIPFACCMF->OPT_15;
    MWIPFACCMF_N->OPT_16[0] = MWIPFACCMF->OPT_16;
    MWIPFACCMF_N->OPT_17[0] = MWIPFACCMF->OPT_17;
    MWIPFACCMF_N->OPT_18[0] = MWIPFACCMF->OPT_18;
    MWIPFACCMF_N->OPT_19[0] = MWIPFACCMF->OPT_19;
    MWIPFACCMF_N->OPT_20[0] = MWIPFACCMF->OPT_20;
    MEMCPY_AN(MWIPFACCMF_N->TBL_1, MWIPFACCMF->TBL_1, sizeof(MWIPFACCMF->TBL_1));
    MEMCPY_AN(MWIPFACCMF_N->TBL_2, MWIPFACCMF->TBL_2, sizeof(MWIPFACCMF->TBL_2));
    MEMCPY_AN(MWIPFACCMF_N->TBL_3, MWIPFACCMF->TBL_3, sizeof(MWIPFACCMF->TBL_3));
    MEMCPY_AN(MWIPFACCMF_N->TBL_4, MWIPFACCMF->TBL_4, sizeof(MWIPFACCMF->TBL_4));
    MEMCPY_AN(MWIPFACCMF_N->TBL_5, MWIPFACCMF->TBL_5, sizeof(MWIPFACCMF->TBL_5));
    MEMCPY_AN(MWIPFACCMF_N->TBL_6, MWIPFACCMF->TBL_6, sizeof(MWIPFACCMF->TBL_6));
    MEMCPY_AN(MWIPFACCMF_N->TBL_7, MWIPFACCMF->TBL_7, sizeof(MWIPFACCMF->TBL_7));
    MEMCPY_AN(MWIPFACCMF_N->TBL_8, MWIPFACCMF->TBL_8, sizeof(MWIPFACCMF->TBL_8));
    MEMCPY_AN(MWIPFACCMF_N->TBL_9, MWIPFACCMF->TBL_9, sizeof(MWIPFACCMF->TBL_9));
    MEMCPY_AN(MWIPFACCMF_N->TBL_10, MWIPFACCMF->TBL_10, sizeof(MWIPFACCMF->TBL_10));
    MEMCPY_AN(MWIPFACCMF_N->TBL_11, MWIPFACCMF->TBL_11, sizeof(MWIPFACCMF->TBL_11));
    MEMCPY_AN(MWIPFACCMF_N->TBL_12, MWIPFACCMF->TBL_12, sizeof(MWIPFACCMF->TBL_12));
    MEMCPY_AN(MWIPFACCMF_N->TBL_13, MWIPFACCMF->TBL_13, sizeof(MWIPFACCMF->TBL_13));
    MEMCPY_AN(MWIPFACCMF_N->TBL_14, MWIPFACCMF->TBL_14, sizeof(MWIPFACCMF->TBL_14));
    MEMCPY_AN(MWIPFACCMF_N->TBL_15, MWIPFACCMF->TBL_15, sizeof(MWIPFACCMF->TBL_15));
    MEMCPY_AN(MWIPFACCMF_N->TBL_16, MWIPFACCMF->TBL_16, sizeof(MWIPFACCMF->TBL_16));
    MEMCPY_AN(MWIPFACCMF_N->TBL_17, MWIPFACCMF->TBL_17, sizeof(MWIPFACCMF->TBL_17));
    MEMCPY_AN(MWIPFACCMF_N->TBL_18, MWIPFACCMF->TBL_18, sizeof(MWIPFACCMF->TBL_18));
    MEMCPY_AN(MWIPFACCMF_N->TBL_19, MWIPFACCMF->TBL_19, sizeof(MWIPFACCMF->TBL_19));
    MEMCPY_AN(MWIPFACCMF_N->TBL_20, MWIPFACCMF->TBL_20, sizeof(MWIPFACCMF->TBL_20));
    MEMCPY_AN(MWIPFACCMF_N->CREATE_USER_ID, MWIPFACCMF->CREATE_USER_ID, sizeof(MWIPFACCMF->CREATE_USER_ID));
    MEMCPY_AN(MWIPFACCMF_N->CREATE_TIME, MWIPFACCMF->CREATE_TIME, sizeof(MWIPFACCMF->CREATE_TIME));
    MEMCPY_AN(MWIPFACCMF_N->UPDATE_USER_ID, MWIPFACCMF->UPDATE_USER_ID, sizeof(MWIPFACCMF->UPDATE_USER_ID));
    MEMCPY_AN(MWIPFACCMF_N->UPDATE_TIME, MWIPFACCMF->UPDATE_TIME, sizeof(MWIPFACCMF->UPDATE_TIME));
}


/* Del Null Function */
void DBC_del_null_mwipfaccmf(struct MWIPFACCMF_N_TAG *MWIPFACCMF_N, struct MWIPFACCMF_TAG *MWIPFACCMF)
{
    MEMCPY_DN(MWIPFACCMF->FACTORY, MWIPFACCMF_N->FACTORY, sizeof(MWIPFACCMF->FACTORY));
    MEMCPY_DN(MWIPFACCMF->ITEM_NAME, MWIPFACCMF_N->ITEM_NAME, sizeof(MWIPFACCMF->ITEM_NAME));
    MEMCPY_DN(MWIPFACCMF->PRT_1, MWIPFACCMF_N->PRT_1, sizeof(MWIPFACCMF->PRT_1));
    MEMCPY_DN(MWIPFACCMF->PRT_2, MWIPFACCMF_N->PRT_2, sizeof(MWIPFACCMF->PRT_2));
    MEMCPY_DN(MWIPFACCMF->PRT_3, MWIPFACCMF_N->PRT_3, sizeof(MWIPFACCMF->PRT_3));
    MEMCPY_DN(MWIPFACCMF->PRT_4, MWIPFACCMF_N->PRT_4, sizeof(MWIPFACCMF->PRT_4));
    MEMCPY_DN(MWIPFACCMF->PRT_5, MWIPFACCMF_N->PRT_5, sizeof(MWIPFACCMF->PRT_5));
    MEMCPY_DN(MWIPFACCMF->PRT_6, MWIPFACCMF_N->PRT_6, sizeof(MWIPFACCMF->PRT_6));
    MEMCPY_DN(MWIPFACCMF->PRT_7, MWIPFACCMF_N->PRT_7, sizeof(MWIPFACCMF->PRT_7));
    MEMCPY_DN(MWIPFACCMF->PRT_8, MWIPFACCMF_N->PRT_8, sizeof(MWIPFACCMF->PRT_8));
    MEMCPY_DN(MWIPFACCMF->PRT_9, MWIPFACCMF_N->PRT_9, sizeof(MWIPFACCMF->PRT_9));
    MEMCPY_DN(MWIPFACCMF->PRT_10, MWIPFACCMF_N->PRT_10, sizeof(MWIPFACCMF->PRT_10));
    MEMCPY_DN(MWIPFACCMF->PRT_11, MWIPFACCMF_N->PRT_11, sizeof(MWIPFACCMF->PRT_11));
    MEMCPY_DN(MWIPFACCMF->PRT_12, MWIPFACCMF_N->PRT_12, sizeof(MWIPFACCMF->PRT_12));
    MEMCPY_DN(MWIPFACCMF->PRT_13, MWIPFACCMF_N->PRT_13, sizeof(MWIPFACCMF->PRT_13));
    MEMCPY_DN(MWIPFACCMF->PRT_14, MWIPFACCMF_N->PRT_14, sizeof(MWIPFACCMF->PRT_14));
    MEMCPY_DN(MWIPFACCMF->PRT_15, MWIPFACCMF_N->PRT_15, sizeof(MWIPFACCMF->PRT_15));
    MEMCPY_DN(MWIPFACCMF->PRT_16, MWIPFACCMF_N->PRT_16, sizeof(MWIPFACCMF->PRT_16));
    MEMCPY_DN(MWIPFACCMF->PRT_17, MWIPFACCMF_N->PRT_17, sizeof(MWIPFACCMF->PRT_17));
    MEMCPY_DN(MWIPFACCMF->PRT_18, MWIPFACCMF_N->PRT_18, sizeof(MWIPFACCMF->PRT_18));
    MEMCPY_DN(MWIPFACCMF->PRT_19, MWIPFACCMF_N->PRT_19, sizeof(MWIPFACCMF->PRT_19));
    MEMCPY_DN(MWIPFACCMF->PRT_20, MWIPFACCMF_N->PRT_20, sizeof(MWIPFACCMF->PRT_20));
    MWIPFACCMF->FMT_1 = MWIPFACCMF_N->FMT_1[0];
    MWIPFACCMF->FMT_2 = MWIPFACCMF_N->FMT_2[0];
    MWIPFACCMF->FMT_3 = MWIPFACCMF_N->FMT_3[0];
    MWIPFACCMF->FMT_4 = MWIPFACCMF_N->FMT_4[0];
    MWIPFACCMF->FMT_5 = MWIPFACCMF_N->FMT_5[0];
    MWIPFACCMF->FMT_6 = MWIPFACCMF_N->FMT_6[0];
    MWIPFACCMF->FMT_7 = MWIPFACCMF_N->FMT_7[0];
    MWIPFACCMF->FMT_8 = MWIPFACCMF_N->FMT_8[0];
    MWIPFACCMF->FMT_9 = MWIPFACCMF_N->FMT_9[0];
    MWIPFACCMF->FMT_10 = MWIPFACCMF_N->FMT_10[0];
    MWIPFACCMF->FMT_11 = MWIPFACCMF_N->FMT_11[0];
    MWIPFACCMF->FMT_12 = MWIPFACCMF_N->FMT_12[0];
    MWIPFACCMF->FMT_13 = MWIPFACCMF_N->FMT_13[0];
    MWIPFACCMF->FMT_14 = MWIPFACCMF_N->FMT_14[0];
    MWIPFACCMF->FMT_15 = MWIPFACCMF_N->FMT_15[0];
    MWIPFACCMF->FMT_16 = MWIPFACCMF_N->FMT_16[0];
    MWIPFACCMF->FMT_17 = MWIPFACCMF_N->FMT_17[0];
    MWIPFACCMF->FMT_18 = MWIPFACCMF_N->FMT_18[0];
    MWIPFACCMF->FMT_19 = MWIPFACCMF_N->FMT_19[0];
    MWIPFACCMF->FMT_20 = MWIPFACCMF_N->FMT_20[0];
    MWIPFACCMF->OPT_1 = MWIPFACCMF_N->OPT_1[0];
    MWIPFACCMF->OPT_2 = MWIPFACCMF_N->OPT_2[0];
    MWIPFACCMF->OPT_3 = MWIPFACCMF_N->OPT_3[0];
    MWIPFACCMF->OPT_4 = MWIPFACCMF_N->OPT_4[0];
    MWIPFACCMF->OPT_5 = MWIPFACCMF_N->OPT_5[0];
    MWIPFACCMF->OPT_6 = MWIPFACCMF_N->OPT_6[0];
    MWIPFACCMF->OPT_7 = MWIPFACCMF_N->OPT_7[0];
    MWIPFACCMF->OPT_8 = MWIPFACCMF_N->OPT_8[0];
    MWIPFACCMF->OPT_9 = MWIPFACCMF_N->OPT_9[0];
    MWIPFACCMF->OPT_10 = MWIPFACCMF_N->OPT_10[0];
    MWIPFACCMF->OPT_11 = MWIPFACCMF_N->OPT_11[0];
    MWIPFACCMF->OPT_12 = MWIPFACCMF_N->OPT_12[0];
    MWIPFACCMF->OPT_13 = MWIPFACCMF_N->OPT_13[0];
    MWIPFACCMF->OPT_14 = MWIPFACCMF_N->OPT_14[0];
    MWIPFACCMF->OPT_15 = MWIPFACCMF_N->OPT_15[0];
    MWIPFACCMF->OPT_16 = MWIPFACCMF_N->OPT_16[0];
    MWIPFACCMF->OPT_17 = MWIPFACCMF_N->OPT_17[0];
    MWIPFACCMF->OPT_18 = MWIPFACCMF_N->OPT_18[0];
    MWIPFACCMF->OPT_19 = MWIPFACCMF_N->OPT_19[0];
    MWIPFACCMF->OPT_20 = MWIPFACCMF_N->OPT_20[0];
    MEMCPY_DN(MWIPFACCMF->TBL_1, MWIPFACCMF_N->TBL_1, sizeof(MWIPFACCMF->TBL_1));
    MEMCPY_DN(MWIPFACCMF->TBL_2, MWIPFACCMF_N->TBL_2, sizeof(MWIPFACCMF->TBL_2));
    MEMCPY_DN(MWIPFACCMF->TBL_3, MWIPFACCMF_N->TBL_3, sizeof(MWIPFACCMF->TBL_3));
    MEMCPY_DN(MWIPFACCMF->TBL_4, MWIPFACCMF_N->TBL_4, sizeof(MWIPFACCMF->TBL_4));
    MEMCPY_DN(MWIPFACCMF->TBL_5, MWIPFACCMF_N->TBL_5, sizeof(MWIPFACCMF->TBL_5));
    MEMCPY_DN(MWIPFACCMF->TBL_6, MWIPFACCMF_N->TBL_6, sizeof(MWIPFACCMF->TBL_6));
    MEMCPY_DN(MWIPFACCMF->TBL_7, MWIPFACCMF_N->TBL_7, sizeof(MWIPFACCMF->TBL_7));
    MEMCPY_DN(MWIPFACCMF->TBL_8, MWIPFACCMF_N->TBL_8, sizeof(MWIPFACCMF->TBL_8));
    MEMCPY_DN(MWIPFACCMF->TBL_9, MWIPFACCMF_N->TBL_9, sizeof(MWIPFACCMF->TBL_9));
    MEMCPY_DN(MWIPFACCMF->TBL_10, MWIPFACCMF_N->TBL_10, sizeof(MWIPFACCMF->TBL_10));
    MEMCPY_DN(MWIPFACCMF->TBL_11, MWIPFACCMF_N->TBL_11, sizeof(MWIPFACCMF->TBL_11));
    MEMCPY_DN(MWIPFACCMF->TBL_12, MWIPFACCMF_N->TBL_12, sizeof(MWIPFACCMF->TBL_12));
    MEMCPY_DN(MWIPFACCMF->TBL_13, MWIPFACCMF_N->TBL_13, sizeof(MWIPFACCMF->TBL_13));
    MEMCPY_DN(MWIPFACCMF->TBL_14, MWIPFACCMF_N->TBL_14, sizeof(MWIPFACCMF->TBL_14));
    MEMCPY_DN(MWIPFACCMF->TBL_15, MWIPFACCMF_N->TBL_15, sizeof(MWIPFACCMF->TBL_15));
    MEMCPY_DN(MWIPFACCMF->TBL_16, MWIPFACCMF_N->TBL_16, sizeof(MWIPFACCMF->TBL_16));
    MEMCPY_DN(MWIPFACCMF->TBL_17, MWIPFACCMF_N->TBL_17, sizeof(MWIPFACCMF->TBL_17));
    MEMCPY_DN(MWIPFACCMF->TBL_18, MWIPFACCMF_N->TBL_18, sizeof(MWIPFACCMF->TBL_18));
    MEMCPY_DN(MWIPFACCMF->TBL_19, MWIPFACCMF_N->TBL_19, sizeof(MWIPFACCMF->TBL_19));
    MEMCPY_DN(MWIPFACCMF->TBL_20, MWIPFACCMF_N->TBL_20, sizeof(MWIPFACCMF->TBL_20));
    MEMCPY_DN(MWIPFACCMF->CREATE_USER_ID, MWIPFACCMF_N->CREATE_USER_ID, sizeof(MWIPFACCMF->CREATE_USER_ID));
    MEMCPY_DN(MWIPFACCMF->CREATE_TIME, MWIPFACCMF_N->CREATE_TIME, sizeof(MWIPFACCMF->CREATE_TIME));
    MEMCPY_DN(MWIPFACCMF->UPDATE_USER_ID, MWIPFACCMF_N->UPDATE_USER_ID, sizeof(MWIPFACCMF->UPDATE_USER_ID));
    MEMCPY_DN(MWIPFACCMF->UPDATE_TIME, MWIPFACCMF_N->UPDATE_TIME, sizeof(MWIPFACCMF->UPDATE_TIME));
}



